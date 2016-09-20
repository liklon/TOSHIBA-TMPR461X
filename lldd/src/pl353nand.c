/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : NAND LLDD
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : IPL
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/05/08 08:55:03 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                       /* Cap-Bt Data types header */
#include "core.h"                           /* Generic Cortex utilities */ 
#include "pl353memctrl.h"                   /* Board specific defines */
#include "pl353nand.h"                      /* Driver's API header file */

/* Supporting defines */
#define CRCGEN_TOP_BIT   (0x8000U)

/* *** NAND Flash device related RANGES for MemCtrl settings *** */
#define NANDFLASH_RD_CYCLE_MIN   (2U)
#define NANDFLASH_RD_CYCLE_MAX   (15U)
#define NANDFLASH_WR_CYCLE_MIN   (2U)
#define NANDFLASH_WR_CYCLE_MAX   (15U)

#define NANDFLASH_ASSERT_REN_MIN    (1U)
#define NANDFLASH_ASSERT_REN_MAX    (7U)
#define NANDFLASH_DEASSERT_WEN_MIN  (1U)
#define NANDFLASH_DEASSERT_WEN_MAX  (7U)

#define NANDFLASH_STATUS_RD_MAX     (7U)
#define NANDFLASH_ID_RD_MAX         (7U)

#define NANDFLASH_BUSY_TO_REN_MAX   (15U)

/* Supporting bit masks */
#define NF_MASK_4X_ECC_BLOCKS   (0x0FU)
#define NF_MASK_5X_ECC_BLOCKS   (0x1FU)
#define NF_INTERN_ECC_FAILED      (0x01U)

/* *** Typical Large Page Devices Addressing ***

  Mapping Columns/Pages/Blocks to Address-Cycles for a NAND device

   Cycle:  I/O7  I/O6  I/O5 I/O4 I/O3  I/O2   I/O1  I/O0

   First   CA7   CA6   CA5  CA4   CA3   CA2   CA1   CA0
   Second  LOW   LOW   LOW  LOW  CA11  CA10   CA9   CA8
   Third   BA7   BA6   PA5  PA4   PA3   PA2   PA1   PA0
   Fourth  BA15  BA14  BA13 BA12  BA11  BA10  BA9   BA8
   Fifth   LOW   LOW   LOW  LOW   LOW   BA18  BA17  BA16
*/

/* *** Comment on BLOCK SELECTION for ERASE commands ***
  Mapping Pages/Blocks to Address-Cycles for a NAND device.
  Page address is ignored for ERASE command.

   Cycle  I/O7  I/O6 I/O5 I/O4 I/O3  I/O2 I/O1 I/O0
   First   BA7  BA6  PA5  PA4   PA3   PA2  PA1  PA0
   Second  BA15 BA14 BA13 BA12  BA11  BA10 BA9  BA8
   Third   LOW  LOW  LOW  LOW   LOW   BA18 BA17 BA16
*/

/**********************************************
*  Global variables and forward declarations  *
**********************************************/
/* Extra Block buffer for Reading. With the current NAND driver implementation
 this buffer is overwritten with the Extra Block data just after the 2kB Page
 content is read. So there is no chance to have access  to extra block content
 when driver function for multi-page-read is used. */
uint32_t pu32GlExtraBlockBuf[8] = { 0x0U, 0x0U, 0x0U, 0x0U,
   0x0U, 0x0U, 0x0U, 0x0U
};

/* **************** NAND Flash Local Functions Declarations **************** */

/*****************************************************************************
* Function performs the calculation of the CRC-16 checksum. It operates on
* bytes from the input buffer. The number of bytes from the buffer precessed
* by this function is determined by the 2nd. parameter (u32BufferLength).
* After the calculation the function returns the calculated CRC-16 value.
*
*****************************************************************************/
uint16_t u16CRCGEN_CalculateCrc16 (const uint8_t pu8DataBuf[], uint32_t u32BufferLength);

/*****************************************************************************
* Checks, if values in the configuration structure are valid and can be written
* to the Memory Controller and/or NAND device.
*****************************************************************************/
static NandFlashStatus_e eNF_ConfigVerify (const NandFlashCfg_st *
                                           const pstNandCfg);

/*****************************************************************************
* Function copies configuration parameters from the configuration structure
* to the Memory Controller and/or NAND device registers.
*****************************************************************************/
static void vNF_CopyConfigToRegs (const NandFlashCfg_st * const pstNandCfg);

/*****************************************************************************
* Function sends a NAND Command over the AXI bus, without any parameter.
*****************************************************************************/
static void vNF_CmdPhaseAxi (const NandFlashCfg_st * const pstNandCfg,
                             uint32_t u32StartCommand);

/*****************************************************************************
* Function sends a NAND Command over the AXI bus, with a single byte register
* address parameter.
*****************************************************************************/
static void vNF_CmdPhaseAxiRegAddr (const NandFlashCfg_st * const pstNandCfg,
                                    uint32_t u32RegAdr,
                                    uint32_t u32StartCommand);

/*****************************************************************************
* Function reads a single data byte over the AXI bus, using AXI Data Phase.
*****************************************************************************/
static uint32_t u32NF_DataPhaseAxiRead (const NandFlashCfg_st *
                                        const pstNandCfg, uint32_t u32ClearCs,
                                        uint32_t u32EccLast);

/*****************************************************************************
* Function reads multiple data over the AXI bus, using AXI Data Phase.
*****************************************************************************/
static void vNF_DataPhaseAxiRdMulti (const NandFlashCfg_st * const pstNandCfg,
                                     uint32_t u32BufferLen,
                                     uint32_t pu32DstBuf[], uint32_t u32EccLast,
                                     uint32_t pu32ExtrBuf[]);

/*****************************************************************************
* Function waits with timeout until ECC HW module finishes reading of the ECC
* data from NAND memory.
*****************************************************************************/
static NandFlashStatus_e eNF_EccReadReady (const NandFlashCfg_st *
                                           const pstNandCfg);

/*****************************************************************************
* Function fixes a single error detected by ECC HW module.
*****************************************************************************/
static NandFlashStatus_e eNF_EccBitFix (uint32_t u32EccValue, uint8_t pu8Buf[]);

/*****************************************************************************
* Function scans all ECC status information and deploys a required action e.g.
* ECC correction or error return.
*****************************************************************************/
static NandFlashStatus_e eNF_EccCorrectLarge (const NandFlashCfg_st * const pstNandCfg,
                                              uint8_t pu8DstBuf[],
                                              uint8_t pu8ExtrBuf[]);

/*****************************************************************************
* Function scans an ONFI compliant device for the Parameter Page information.
*****************************************************************************/
static NandFlashStatus_e eNF_ReadOnfiParamsPage (NandFlashCfg_st * pstNandCfg);

/*****************************************************************************
* Function sends a SET FEATURE command with the parameters to an ONFI compliant
* device.
*****************************************************************************/
static NandFlashStatus_e eNF_SetFeature (const NandFlashCfg_st * const pstNandCfg,
                                         uint32_t u32SubAddress,
                                         uint8_t const pu8SubParBuf[]);

/* ***************** NAND Flash Local Functions Definitions **************** */

/*..........................................................................*/
uint16_t u16CRCGEN_CalculateCrc16 (const uint8_t pu8DataBuf[],
                                   uint32_t u32BufferLength)
{
   const uint16_t u16GenPolynom = CRCGEN_POLYNOMIAL;

   const uint16_t u16TopBit = CRCGEN_TOP_BIT;

   uint16_t u16CRC = CRCGEN_INIT_VALUE;

   uint32_t u32BufIdx;

   uint32_t u32BitIdx;

   /* Loop for each byte in the buffer */
   for (u32BufIdx = 0; u32BufIdx < u32BufferLength; u32BufIdx++)
   {
      uint16_t u16BufValue;

      u16BufValue = pu8DataBuf[u32BufIdx];
      u16BufValue = (u16BufValue << 8);
      u16CRC = (u16CRC ^ u16BufValue);

      /* Loop for each bit in the byte */
      for (u32BitIdx = 0; u32BitIdx < 8; u32BitIdx++)
      {
         if ((u16CRC & u16TopBit) != 0x0000U)
         {
            u16CRC = ((u16CRC << 1) ^ u16GenPolynom);
         }
         else
         {
            u16CRC = (u16CRC << 1);
         }
      }
   }

   return u16CRC;
}

/*..........................................................................*/
static NandFlashStatus_e eNF_ConfigVerify (const NandFlashCfg_st *
                                           const pstNandCfg)
{
   NandFlashStatus_e eResult;

/***
* MESSAGE: MISRA-C:2004 Rule 13.7 The result of this logical operation is always
*          'false'.
*
* DESC   : The check below is required for enum types since NANDFLASH_BUS_WIDTH_16
*          and NANDFLASH_EXTRA_BLOCK_32_BYTES values might contain values
*          specified at the "run-time" and by out-of-range of the respective
*          enumerations.
****/
   if ((pstNandCfg->u32ReadCycleTime < (NANDFLASH_RD_CYCLE_MIN)) ||
       (pstNandCfg->u32ReadCycleTime > (NANDFLASH_RD_CYCLE_MAX)) ||
       (pstNandCfg->u32WriteCycleTime < (NANDFLASH_WR_CYCLE_MIN)) ||
       (pstNandCfg->u32WriteCycleTime > (NANDFLASH_WR_CYCLE_MAX)) ||
       (pstNandCfg->u32AssertDelayReN < (NANDFLASH_ASSERT_REN_MIN)) ||
       (pstNandCfg->u32AssertDelayReN > (NANDFLASH_ASSERT_REN_MAX)) ||
       (pstNandCfg->u32DeAssertDelayWeN < (NANDFLASH_DEASSERT_WEN_MIN)) ||
       (pstNandCfg->u32DeAssertDelayWeN > (NANDFLASH_DEASSERT_WEN_MAX)) ||
       (pstNandCfg->u32StatusRdTime > (NANDFLASH_STATUS_RD_MAX)) ||
       (pstNandCfg->u32IdRdTime > (NANDFLASH_ID_RD_MAX)) ||
       (pstNandCfg->u32BusyCycleToReN > (NANDFLASH_BUSY_TO_REN_MAX)) ||
       (pstNandCfg->eBusWidth > (NANDFLASH_BUS_WIDTH_16)) ||               /* PRQA S 3356 */
       (pstNandCfg->eExtraBlockCfg > (NANDFLASH_EXTRA_BLOCK_32_BYTES)))    /* PRQA S 3356 */
   {
      eResult = NANDFLASH_STATUS_CFG_ERR;   /* Invalid Parameter(s)! */
   }
   else
   {
      eResult = NANDFLASH_STATUS_OK;        /* All Parameters OK */
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
static void vNF_CopyConfigToRegs (const NandFlashCfg_st * const pstNandCfg)
{
   uint32_t u32RegCfg;

   uint32_t u32DirCmdVal;


   /* copy cycles/opmode data from the configuration structure to registers */
   u32RegCfg = 0x00000000U;
   u32RegCfg =
      u32RegCfg | ((pstNandCfg->u32ReadCycleTime) << (MEMCTRL_SET_T0_SFT));
   u32RegCfg =
      u32RegCfg | ((pstNandCfg->u32WriteCycleTime) << (MEMCTRL_SET_T1_SFT));
   u32RegCfg =
      u32RegCfg | ((pstNandCfg->u32AssertDelayReN) << (MEMCTRL_SET_T2_SFT));
   u32RegCfg =
      u32RegCfg | ((pstNandCfg->u32DeAssertDelayWeN) << (MEMCTRL_SET_T3_SFT));
   u32RegCfg =
      u32RegCfg | ((pstNandCfg->u32StatusRdTime) << (MEMCTRL_SET_T4_SFT));
   u32RegCfg = u32RegCfg | ((pstNandCfg->u32IdRdTime) << (MEMCTRL_SET_T5_SFT));
   u32RegCfg =
      u32RegCfg | ((pstNandCfg->u32BusyCycleToReN) << (MEMCTRL_SET_T6_SFT));
   MEMCTRL_SET_CYCLES = u32RegCfg;
   /* Force to 8-bit interface at the begining */
   MEMCTRL_SET_OPMODE = MEMCTRL_SET_MW_8_BITS;
   /*
      Update cycles and opmode registers for NAND UpdateRegs (see PL353 spec.,
      page 3-12) */
   u32DirCmdVal = MEMCTRL_NAND_CHIP_SEL_MSK | MEMCTRL_CMD_TYPE_UPD_REGS_MSK;
   MEMCTRL_DIRECT_CMD = u32DirCmdVal;
   /*
      Load Ecc Memory Config Register. Change the Extra block configuration
      bits Write it back to the register */
   u32RegCfg = MEMCTRL_ECC_MEMCFG;
   u32RegCfg = u32RegCfg & (~MEMCTRL_ECC_EXTRA_BLOCK_MSK);
   u32RegCfg = u32RegCfg & (~MEMCTRL_ECC_EXTRA_BLOCK_SIZE_MSK);

   switch (pstNandCfg->eExtraBlockCfg)
   {
      
      case NANDFLASH_EXTRA_BLOCK_8_BYTES:
      {
         u32RegCfg = (u32RegCfg | (MEMCTRL_ECC_EXTRA_BLOCK_MSK));
         u32RegCfg = (u32RegCfg | (MEMCTRL_ECC_EXTRA_BLOCK_SIZE_8B_BITS));
      }
         break;
      case NANDFLASH_EXTRA_BLOCK_16_BYTES:
      {
         u32RegCfg = (u32RegCfg | (MEMCTRL_ECC_EXTRA_BLOCK_MSK));
         u32RegCfg = (u32RegCfg | (MEMCTRL_ECC_EXTRA_BLOCK_SIZE_16B_BITS));
      }
         break;
      case NANDFLASH_EXTRA_BLOCK_32_BYTES:
      {
         u32RegCfg = (u32RegCfg | (MEMCTRL_ECC_EXTRA_BLOCK_MSK));
         u32RegCfg = (u32RegCfg | (MEMCTRL_ECC_EXTRA_BLOCK_SIZE_32B_BITS));
      }
         break;
      default:
      {
         /* DISABLED for NANDFLASH_EXTRA_BLOCK_DISABLED and invalid values */
         u32RegCfg = (u32RegCfg & (~MEMCTRL_ECC_EXTRA_BLOCK_MSK));
      }
         break;
   }
   MEMCTRL_ECC_MEMCFG = u32RegCfg;
}

/*..........................................................................*/
/* TESTED */
static void vNF_CmdPhaseAxi (const NandFlashCfg_st * const pstNandCfg,
                             uint32_t u32StartCommand)
{
   uint32_t u32CmdPh;                       /* Word to be send within a command
                                               phase */
   uint32_t *pu32CmdPhDest;


   if(pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_HOST_ECC)
   {
      NANDFLASH_CLEAR_READY_IRQ ();
   }

   /*
      WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already. */
   u32CmdPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32CmdPh = (u32CmdPh | (u32StartCommand << (MEMCTRL_AXI_START_COMMAND_SFT)));
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This warning cannot be avoided, since the PL353 MemCtrl requires a
*          specific pointer/access based on the integer value built upon the
*          combination of integer parameters.
****/
   pu32CmdPhDest = (uint32_t *)u32CmdPh;    /* PRQA S 0306 */

   /*
      No any address cycles are send (only command). According to SMC spec.
      When issuing a command phase access with address cycles==0 : at least one
      byte lane must be enabled. */
   *pu32CmdPhDest = 0U;                     /* wdata don't care according to
                                               SMC spec. page 2-23 */
   __DSB();

   if(pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_HOST_ECC)
   {
      NF_uSecWait ((3U * NANDFLASH_TIME_1us));
   }
}

/*..........................................................................*/
/* Command with the register access is scheduled. */
/* TESTED */
static void vNF_CmdPhaseAxiRegAddr (const NandFlashCfg_st * const pstNandCfg,
                                    uint32_t u32RegAdr,
                                    uint32_t u32StartCommand)
{
   uint32_t u32CmdPh;                       /* Word to be send within a command
                                               phase */
   uint32_t *pu32CmdPhDest;


   if(pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_HOST_ECC)
   {
      NANDFLASH_CLEAR_READY_IRQ ();
   }
   /*
      WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already... */
   u32CmdPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32CmdPh = (u32CmdPh | (0x1U << (MEMCTRL_AXI_ADDRES_CYCLES_SFT)));
   u32CmdPh =
      (u32CmdPh | (NF_PAR_CMD_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32CmdPh = (u32CmdPh | (u32StartCommand << (MEMCTRL_AXI_START_COMMAND_SFT)));
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This warning cannot be avoided, since the PL353 MemCtrl requires a
*          specific pointer/access based on the integer value built upon the
*          combination of integer parameters.
****/
   pu32CmdPhDest = (uint32_t *)u32CmdPh;    /* PRQA S 0306 */
   /* Send a command with parameter(address) to the device */
   *pu32CmdPhDest = u32RegAdr;
    __DSB();

   if(pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_HOST_ECC)
   {
      NF_uSecWait ((3U * NANDFLASH_TIME_1us));
   }
}

/*..........................................................................*/
/* TESTED */
void vNF_CmdPhaseAxiCplx (const NandFlashCfg_st * const pstNandCfg,
                          uint32_t u32ColAdr, uint32_t u32PageNo,
                          uint32_t u32BlockNo, uint32_t u32StartCommand,
                          uint32_t u32EndCmdValid, uint32_t u32EndCommand)
{
   uint32_t u32CmdPh;                       /* Word to be send within a command
                                               phase */
   uint32_t u32Data;

   uint32_t u32_BA7_6;

   uint32_t u32_BA15_8;

   uint32_t u32_PA5_0;

   uint32_t u32DataNext;

   uint32_t *pu32CmdPhDest;


   if(pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_HOST_ECC)
   {
      NANDFLASH_CLEAR_READY_IRQ ();
   }
   /* u32NandChipAddress should be stored in cfg structure shifted already */
   u32CmdPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32CmdPh =
      (u32CmdPh |
       (pstNandCfg->u32PageAdrCycNo << (MEMCTRL_AXI_ADDRES_CYCLES_SFT)));
   u32CmdPh = (u32CmdPh | (u32EndCmdValid << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
   u32CmdPh =
      (u32CmdPh | (NF_PAR_CMD_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32CmdPh = (u32CmdPh | (u32EndCommand << (MEMCTRL_AXI_END_COMMAND_SFT)));
   u32CmdPh = (u32CmdPh | (u32StartCommand << (MEMCTRL_AXI_START_COMMAND_SFT)));

   /*
      5 or more (max. upto 7) address cycles require 2 32-bit words to be send,
      since each word can carry upto 4 bytes (1 cycle == 1 byte). CHECK ORDER:
      Data1 or Data2 first? Spec. says that we should 1st. send the data
      containg the most significant part of the address (u32Data1) and after
      that lower significant part of the address (u32Data2). This MUST be
      verified!!! */
   /* Construct Command-Phase Data Re-formatted address: WARNING: This code
      should be valid for devices with 2kB pages only. consider suppport of
      4kB or bigger (or smaller than 2kB pages). See page 13 of MICRON
      MT29FG08xxx For 5 or more address cycles the device expects: 1st.
      cycle: CA7..CA0 bits 2nd. cycle: CA11..CA0 bits (right aligned) 3rd.
      cycle: BA7, BA6, PA5..PA0 bits 4th. cycle: BA15..BA8 bits 5th. cycle:
      BA17..BA6 bits (right aligned) */

    /* Construct 1st. and 2nd. cycle byte; CA11-0: offset within page */
    u32Data = u32ColAdr;
    /* Construct 3rd. cycle byte */
    u32_PA5_0 = (u32PageNo & 0x3FU);
    u32_BA7_6 = (((u32BlockNo << 6) & 0xC0U));
    u32Data = (u32Data | ((u32_BA7_6 | u32_PA5_0) << 16));
    /* Construct 4th. cycle byte */
    u32_BA15_8 = (((u32BlockNo >> 2) & 0xFFU));
    u32Data = (u32Data | (u32_BA15_8 << 24));

   if (pstNandCfg->u32PageAdrCycNo >= 5U)   /* check if command has 5 or more
                                               adress cycles */
   {
      /* Construct cycle 5th. byte */
      u32DataNext = (u32BlockNo >> 10); /* BA ?? ..BA16 bits */
      /* Send all address bytes/cycles from u32Dat1 using burst of 2 */
      vNF_AddrBrstWr(u32CmdPh, u32Data, u32DataNext);
      __DSB();
   }
   else /* 4 address bytes only */
   {
      /* Pointer init */
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This warning cannot be avoided, since the PL353 MemCtrl requires a
*          specific pointer/access based on the integer value built upon the
*          combination of integer parameters.
****/
      pu32CmdPhDest = (uint32_t *)u32CmdPh;    /* PRQA S 0306 */
      /* Send 4 address bytes/cycles from u32Dat1 */
      *pu32CmdPhDest = u32Data;
      __DSB();
   }
   if(pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_HOST_ECC)
   {
      NF_uSecWait ((3U * NANDFLASH_TIME_1us));
   }
}


/*..........................................................................*/
/* TESTED */
static uint32_t u32NF_DataPhaseAxiRead (const NandFlashCfg_st *
                                        const pstNandCfg, uint32_t u32ClearCs,
                                        uint32_t u32EccLast)
{
   uint32_t u32DatPh;                       /* to be send within a data phase */

   uint32_t *pu32CmdPhDest;

   uint32_t u32DataRead;

   /*
      WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already... No any END Command send! */
   u32DatPh = (((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK))
               | (u32ClearCs << (MEMCTRL_AXI_CLEAR_CS_SFT))
               | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT))
               | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This warning cannot be avoided, since the PL353 MemCtrl requires a
*          specific pointer/access based on the integer value built upon the
*          combination of integer parameters.
****/
   pu32CmdPhDest = (uint32_t *)u32DatPh;    /* PRQA S 0306 */
   /* Construct Command-Phase Data Re-formatted address */
   u32DataRead = *pu32CmdPhDest;            /* read from device */

   return u32DataRead;
}

/*..........................................................................*/
/* TESTED */
static void vNF_DataPhaseAxiRdMulti (const NandFlashCfg_st * const pstNandCfg,
                                     uint32_t u32BufferLen,
                                     uint32_t pu32DstBuf[], uint32_t u32EccLast,
                                     uint32_t pu32ExtrBuf[])
{
   uint32_t u32DatPh;                       /* Word to be send within a command
                                               phase */
   uint32_t *pu32CmdPhDest;

   uint32_t u32Idx;

   uint32_t u32ExtrBufLen;               /* Extra Length in 32-bit Words */


   /* WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already. */
   u32DatPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32DatPh = (u32DatPh | (NF_PAR_CS_ACTIV << (MEMCTRL_AXI_CLEAR_CS_SFT)));
   u32DatPh =
      (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32DatPh = (u32DatPh | (NF_PAR_ECC_CALC << (MEMCTRL_AXI_ECC_LAST_SFT)));
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This warning cannot be avoided, since the PL353 MemCtrl requires a
*          specific pointer/access based on the integer value built upon the
*          combination of integer parameters.
****/
   pu32CmdPhDest = (uint32_t *)u32DatPh;    /* PRQA S 0306 */

   /* Read only 2kB page (without extra block), if Disabled or the destination
      buffer is NULL (when function is called for Spare Area read) */
   if ((pstNandCfg->eExtraBlockCfg == NANDFLASH_EXTRA_BLOCK_DISABLED) ||
       (pu32ExtrBuf == (uint32_t *)0x00U))
   {
      for (u32Idx = 0U; u32Idx < (u32BufferLen - 1U); u32Idx++)
      {
         /* destination is always 32-bit (min. 4 bytes are read from NAND) */
         pu32DstBuf[u32Idx] = (*pu32CmdPhDest);
      }
      /*
         Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This warning cannot be avoided, since the PL353 MemCtrl requires a
*          specific pointer/access based on the integer value built upon the
*          combination of integer parameters.
****/
      pu32CmdPhDest = (uint32_t *)u32DatPh;    /* PRQA S 0306 */
      /* LAST 32-bit word from device */
      pu32DstBuf[u32Idx] = (*pu32CmdPhDest);
   }
   else
   {
      /* Extra block enabled and read was for Main Page Area */
      for (u32Idx = 0U; u32Idx < u32BufferLen; u32Idx++)
      {
         /* destination is always 32-bit (min. 4 bytes are read from NAND) */
         pu32DstBuf[u32Idx] = (*pu32CmdPhDest);
      }
      /* Default Extra Buffer Length: 32 bytes == 8 x 32-bit words */
      switch (pstNandCfg->eExtraBlockCfg)
      {
         case NANDFLASH_EXTRA_BLOCK_32_BYTES:
         {
            u32ExtrBufLen = (32U >> 2);
         }
            break;

         case NANDFLASH_EXTRA_BLOCK_16_BYTES:
         {
            u32ExtrBufLen = (16U >> 2);
         }
            break;

         case NANDFLASH_EXTRA_BLOCK_8_BYTES:
         {
            u32ExtrBufLen = (8U >> 2);
         }
            break;

         default:                          /* 4-bytes */
         {
            u32ExtrBufLen = (4U >> 2);
         }
      }

      for (u32Idx = 0U; u32Idx < (u32ExtrBufLen - 1); u32Idx++)
      {
         /* destination is always 32-bit (min. 4 bytes are read from NAND) */
         pu32ExtrBuf[u32Idx] = (*pu32CmdPhDest);
      }
      /*
         Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This warning cannot be avoided, since the PL353 MemCtrl requires a
*          specific pointer/access based on the integer value built upon the
*          combination of integer parameters.
****/
      pu32CmdPhDest = (uint32_t *)u32DatPh;    /* PRQA S 0306 */
      /* LAST 32-bit word from device */
      pu32ExtrBuf[u32Idx] = (*pu32CmdPhDest);
   }
}

/*..........................................................................*/
/*
 Indicates that ECC block is IDLE, last operation is successful and ECC
 values have been read from memory already. Used for NAND READ operations */
/* TESTED */
static NandFlashStatus_e eNF_EccReadReady (const NandFlashCfg_st *
                                           const pstNandCfg)
{
   NandFlashStatus_e eResult;

   uint32_t u32TimeCycles;

   uint32_t u32Status;

   uint32_t u32EccReadMsk;                  /* depending on Extra Block use the
                                               mask can varry */

   /* Check Last ECC Status */
   u32Status = MEMCTRL_ECC_STATUS;
   u32Status = (u32Status & MEMCTRL_ECC_LAST_STATUS_MSK);
   if (u32Status == MEMCTRL_ECC_LAST_STATUS_SUCCESS_BITS)
   {
      if (pstNandCfg->eExtraBlockCfg == NANDFLASH_EXTRA_BLOCK_DISABLED)
      {
         /* Extra Block NOT used */
         u32EccReadMsk = NF_MASK_4X_ECC_BLOCKS;
      }
      else
      {
         /* Check Extra Block also */
         u32EccReadMsk = NF_MASK_5X_ECC_BLOCKS;
      }
      u32EccReadMsk = (u32EccReadMsk << (MEMCTRL_ECC_READ_SFT));

      /* Wait with timer until the ECC READ is ready. */
      u32TimeCycles = pstNandCfg->u32EccTimeOut;
      do
      {
         /* count down loop with device status check... */
         if (u32TimeCycles > 0x0U)
         {
            u32TimeCycles--;
         }
         u32Status = MEMCTRL_ECC_STATUS;
         u32Status = (u32Status & u32EccReadMsk);
      }
      while (!((u32Status == u32EccReadMsk) || (u32TimeCycles == 0U)));
      /*
         Waiting should be finished, when the ECC read bits are 1 (read
         complete) or the loop counter reaches 0. */
      if (u32Status == u32EccReadMsk)
      {
         eResult = NANDFLASH_STATUS_OK;
      }
      else
      {
         eResult = NANDFLASH_STATUS_ECC_RD_ERR; /* READ timeout expired */
      }
   }
   else
   {
      eResult = NANDFLASH_STATUS_ECC_ERR;   /* LAst Status NOT successful */
   }

   return eResult;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNF_EccConfigure (const NandFlashCfg_st * const pstNandCfg)
{
   NandFlashStatus_e eResult;

   uint32_t u32MemCfgReg;


   eResult = eNF_EccWaitIdle (pstNandCfg);

   if (eResult == NANDFLASH_STATUS_OK)
   {
      /* clear ALL interrupts flags */
      MEMCTRL_ECC_STATUS = MEMCTRL_ECC_RAW_ALL_INTS_MSK;
      /* clear ecc_int interrupt flags */
      MEMCTRL_ECC_VALUE0 = 0x0U;
      MEMCTRL_ECC_VALUE1 = 0x0U;
      MEMCTRL_ECC_VALUE2 = 0x0U;
      MEMCTRL_ECC_VALUE3 = 0x0U;
      MEMCTRL_ECC_VALUE4 = 0x0U;
      /*
         Prepare ECC memory config (valid for LARGE PAGE devices only! Select:
         MEMCTRL_ECC_JUMP_NO_BITS (reads and writes only occur on the end of
         page). MEMCTRL_ECC_READ_END_MSK: ECC read at the end of the page.
         MEMCTRL_ECC_MODE_CALC_RD_WR_BITS: ECC calculated and written/read.
         to/from memory . MEMCTRL_ECC_PAGE_SIZE_4X512_BITS: Page contains 4 x
         512 bytes (2048). */
      u32MemCfgReg = MEMCTRL_ECC_MEMCFG;
      /* Clear ECC related and keep other settings */
      u32MemCfgReg = (u32MemCfgReg & (0xFFFFFF00UL));
      /* Configure new ECC settings */
      u32MemCfgReg = u32MemCfgReg | ((MEMCTRL_ECC_A8_OUTPUT_MSK) | (MEMCTRL_ECC_JUMP_NO_BITS)
                                     | (MEMCTRL_ECC_READ_END_MSK)
                                     | (MEMCTRL_ECC_MODE_CALC_RD_WR_BITS) |
                                     (MEMCTRL_ECC_PAGE_SIZE_4X512_BITS));
      /* Write back new ECC settings */
      MEMCTRL_ECC_MEMCFG = u32MemCfgReg;
      /*
         Specify device-specific commands the ECC block uses to DETECT reading:
         READ START, READ END, if supported (END VALID) and writing (PROGRAM). */
      MEMCTRL_ECC_MEMCMD1 =
         ((MEMCTRL_ECC_RD_CMD_END_VALID_MSK) |
          ((NANDFLASH_CMD_PAGE_RD_END) << (MEMCTRL_ECC_RD_CMD_END_SFT)) |
          ((NANDFLASH_CMD_PAGE_RD_START) << (MEMCTRL_ECC_RD_CMD_SFT)) |
          ((NANDFLASH_CMD_PROGRAM_START) << (MEMCTRL_ECC_WR_CMD_SFT)));
      /*
         Specify device-specific commands to be used, while accessing different
         parts in NAND page. The usage of this configuration is dependent on the
         ecc_jump bit in the ecc_memcfg register. MEMCTRL_ECC_JUMP_NO_BITS: NO
         support for jumps-> below config is meaningless
         MEMCTRL_ECC_JUMP_COL_CHNG_BITS: Jump using random column change
         commands, see MEMCTRL_ECC_MEMCMD2 MEMCTRL_ECC_JUMP_FUL_CMD_BITS: Jump
         using Full command, see MEMCTRL_ECC_MEMCMD1 above Consider ONFi random
         access commands: Change Read Column Command: 0x05 Change Write Column
         Command: 0x85 Currently configured for "Jump using Full command" since
         this insures the proper operation for most devices, however this counts
         against the maximum number of program operations before a NAND page must
         be erased. */
      MEMCTRL_ECC_MEMCMD2 =
         (((NANDFLASH_CMD_RD_COL_CH_E_V) << 24) |
          ((NANDFLASH_CMD_RD_COL_CH_END) << 16) | ((NANDFLASH_CMD_RD_COL_CHNG)
                                                   << 8) |
          ((NANDFLASH_CMD_WR_COL_CHNG) << 0));
      eResult = NANDFLASH_STATUS_OK;
   }
   else
   {
      /* could be optimized / removed since eResult is updated already */
      eResult = NANDFLASH_STATUS_BUSY_ERR;  /* busy timout expired */
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
static NandFlashStatus_e eNF_EccBitFix (uint32_t u32EccValue, uint8_t pu8Buf[])
{
   uint32_t u32ByteNo;

   uint32_t u32BitNo;

   uint8_t u8BitMask;


   /* Correct the right bit in the right byte: 5 upper bits -> byte number; 3
      lower bits -> bit number within a byte */
   u32ByteNo = (u32EccValue & (MEMCTRL_ECC_VAL_VALUE_MSK));
   u32BitNo = u32ByteNo;
   u32ByteNo = (u32ByteNo >> 3U);           /* get rid of the bit number */
   u32BitNo = (u32BitNo & 0x7U);            /* get rid of the byte number */
   u8BitMask = (uint8_t)(0x1U << u32BitNo);

   if ((pu8Buf[u32ByteNo] & (u8BitMask)) == 0x00U)
   {
      /* defective bit is 0 -> SET this bit */
      pu8Buf[u32ByteNo] = pu8Buf[u32ByteNo] | u8BitMask;
   }
   else
   {
      /* defective bit is 1 -> CLEAR this bit */
      u8BitMask = (~u8BitMask);
      pu8Buf[u32ByteNo] = pu8Buf[u32ByteNo] & u8BitMask;
   }
   return NANDFLASH_STATUS_OK;
}

/*..........................................................................*/
/***
* MESSAGE: MISRA-C:2004 Rule 16.7 The object addressed by the pointer parameter
*          'pu8DstBuf' (same for 'pu8ExtrBuf') is not modified and so the
*          pointer could be of type 'pointer to const'.
*
* DESC   : The two warnings are not applicable. the MISRA tool did not recognize
*          that this function calls suroutines, which might modify the content
*          of both buffers.
****/
static NandFlashStatus_e eNF_EccCorrectLarge (const NandFlashCfg_st * const pstNandCfg,
                                              uint8_t pu8DstBuf[],     /* PRQA S 3673 */
                                              uint8_t pu8ExtrBuf[])    /* PRQA S 3673 */
{
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;    /* PRQA S 3197 */

   uint32_t u32EccStatus;

   uint32_t u32EccValue;

   uint32_t u32EccMsk;

   uint32_t u32BlockNo;

   uint32_t u32ValRegAdr;

   volatile uint32_t *pu32ValueRegister;

   uint32_t u32BufAddr;   /* track SW buffer address */

   uint32_t u32MaxBlockNo = 3U; /* by default Extra B. disabled */


   /* Wait until ECC module is ready */
   eResult = eNF_EccWaitIdle (pstNandCfg);

   if (eResult == NANDFLASH_STATUS_OK)
   {
      u32EccStatus = MEMCTRL_ECC_STATUS;
      /*
         Other bits are meaningful only, if ecc_last_status == b00: Completed
         successfully. */
      if ((u32EccStatus & (MEMCTRL_ECC_LAST_STATUS_MSK)) ==
          (MEMCTRL_ECC_LAST_STATUS_SUCCESS_BITS))
      {
         /* if Extra Block used - take a different bit mask */
         if (pstNandCfg->eExtraBlockCfg == NANDFLASH_EXTRA_BLOCK_DISABLED)
         {
            u32EccMsk = 0x0FU;              /* Extra Block NOT used */
         }
         else
         {
            u32EccMsk = 0x1FU;              /* Check also Extra Block */
         }
         /* Check if ALL ECC VALID (if ALL block of data read correctly?) */
         if ((u32EccStatus & (u32EccMsk << (MEMCTRL_ECC_VALUE_VALID_SFT))) ==
             (u32EccMsk << (MEMCTRL_ECC_VALUE_VALID_SFT)))
         {
            /*
               Check with TIMEOUT, if the ECC codes for ALL blocks of data have
               been read correctly. VERIFY, if wait with TIMEOUT is really
               needed... */
            eResult = eNF_EccReadReady (pstNandCfg);
            if (eResult == NANDFLASH_STATUS_OK)
            {
               /* Check if ALL ECC PASSED (if all ecc_fail flags are zero?) */
               u32EccStatus = MEMCTRL_ECC_STATUS;
/***
* MESSAGE: Msg(3:3371) Unsigned left shift operation << definitely truncates
*          bits from result.
*
* DESC   : This message is TRUE, however it was the intension to get rid of
*          unused bits.
****/
               if ((u32EccStatus & (u32EccMsk << (MEMCTRL_ECC_ECC_FAIL_SFT))) ==
                   0x00U)
               {
                  /*
                     ALL ecc_fail bits == 0 -> ECC PASS - correction not
                     needed. ** Here the reading is over with ALL ECC correct
                     *** */
                  eResult = NANDFLASH_STATUS_OK;
               }
               else                         /* ecc_fail == 1: FAIL */
               {
                  /*
                     With extra block: 0 to 4 registers need to be analyzed and
                     without extra block: 0 to 3 registers need to be analyzed */
                  if (pstNandCfg->eExtraBlockCfg !=
                      NANDFLASH_EXTRA_BLOCK_DISABLED)
                  {
                     u32MaxBlockNo = 4U;
                  }
                  u32BlockNo = 0U;          /* start at MEMCTRL_ECC_VALUE0 */
                  do
                  {
                     /*
                        Calculate address to be accessed and read from that
                        address: */
/***
* MESSAGE: MISRA-C:2004 Rule 10.1 Integral expression implicitly converted to
*          wider type.
*
* DESC   : This message is TRUE, however, in that particular casede there is no
*          risk for crossing of the 32-bit type range.
****/
                     u32ValRegAdr = (uint32_t)(MEMCTRL_ECC_VALUE_ADR (u32BlockNo));     /* PRQA S 3212 */
                     pu32ValueRegister = (volatile uint32_t *)u32ValRegAdr;
                     u32EccValue = (uint32_t)(*pu32ValueRegister);    /* PRQA S 3212 */

                     /* check ecc_fail flags, if set to 1: try to correct */
                     if ((u32EccValue & (MEMCTRL_ECC_VAL_FAIL_MSK)) != 0x0U)
                     {
/***
* MESSAGE: MISRA-C:2004 Rule 1.1 [L] Nesting of control structures (statements)
*          exceeds 15 - program is non-conforming.
*          MISRA-C:2004 Rule 1.1; REFERENCE - ISO-5.2.4.1 Translation Limits
*
* DESC   : This message is TRUE, however, to keep the code readable the source
*          code is preserved in its orginal form.
****/
                        /* check ecc_correct flag, if set: Correct bad-bit */
                        if ((u32EccValue & (MEMCTRL_ECC_VAL_CORRECT_MSK)) !=
                            0x0U)
                        {    /* PRQA S 0715 */
                           /* Calculate offest within the SW buffer depending
                              on the ECC block number. Block size is by default
                              512 bytes for a 2kB Page NAND device. */
                           if (u32BlockNo < u32MaxBlockNo)
                           {
                              /* for 4x 512 Blocks from 2kB Page */
                              u32BufAddr = (u32BlockNo * 512U);
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*          MISRA-C:2004 Rule 1.2; [U] Integral type is not large enough to hold a pointer value.
*
* DESC   : These messages are undestood, but is is required to manipulate pointers
*          using integer calculations. Since within thise system only 32-bit
*          pointers are used - there should be no danger to cast as below.
****/
                              u32BufAddr = (u32BufAddr + (uint32_t)pu8DstBuf);    /* PRQA S 0306 */
                           }
                           else
                           {
                              /* Extra Block: bit fix in Extra buffer */
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*          MISRA-C:2004 Rule 1.2; [U] Integral type is not large enough to hold a pointer value.
*
* DESC   : These messages are undestood, but is is required to manipulate pointers
*          using integer calculations. Since within thise system only 32-bit
*          pointers are used - there should be no danger to cast as below.
****/
                              u32BufAddr = (uint32_t)pu8ExtrBuf;    /* PRQA S 0306 */
                           }
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This message is undestood, but is was required to manipulate (see
*          earlier description) pointers using integer calculations.
****/
                           eResult =
                              eNF_EccBitFix (u32EccValue,
                                             (uint8_t *)u32BufAddr);    /* PRQA S 0306 */
                        }
                        else
                        {    /* PRQA S 0715 */
                           /* Correction NOT possible */
/***
* MESSAGE: MISRA-C:2004 Rule 1.1 [L] Nesting of control structures (statements)
*          exceeds 15 - program is non-conforming.
*          MISRA-C:2004 Rule 1.1; REFERENCE - ISO-5.2.4.1 Translation Limits
*
* DESC   : This message is TRUE, however, to keep the code readable the source
*          code is preserved in its orginal form.
****/
                           eResult = NANDFLASH_STATUS_ECC_ERR;
                        }
                     }
                     /* dO it for next ECC block / Value register */
                     u32BlockNo++;
                     /* Run this loop only, if both below conditions are TRUE */
                  }
                  while (((u32BlockNo <= u32MaxBlockNo) &&
                          (eResult == NANDFLASH_STATUS_OK)));

                  /* *** FINAL eResult available *** */
               }
            }
            else
            {
               /* could be optimized / removed since eResult is updated already
                */
               eResult = NANDFLASH_STATUS_BUSY_ERR; /* busy timout expired */
            }
         }
         else
         {
            eResult = NANDFLASH_STATUS_ECC_RD_ERR; /* SW debugging needed */
         }
      }
      else
      {
         /* Last Status PROBLEM: Error reason should be analyzed */
         eResult = NANDFLASH_STATUS_ECC_ERR;
      }
   }
   else
   {
      /* could be optimized / removed since eResult is updated already */
      eResult = NANDFLASH_STATUS_BUSY_ERR;  /* busy timout expired */
   }
   return eResult;
}

/*..........................................................................*/
static NandFlashStatus_e eNF_ReadOnfiParamsPage (NandFlashCfg_st * pstNandCfg)
{
/***
* MESSAGE: Msg(3:3197) The initialiser for 'eResult' is always modified before
*          being used.
*
* DESC   : To detect that eResult is updated every time within this complex
*          function the initial value NANDFLASH_STATUS_UNKNOWN is used.
****/
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;    /* PRQA S 3197 */

   uint32_t u32Idx;

   uint32_t u32ReadNand;

   uint32_t u32tmp;                   /* temporary */

   uint32_t u32DevCrc;                /* CRC read from NAND device */

   uint32_t u32CalCrc;                /* CRC based on read parameters */

   uint32_t u32tmpOffset;

   uint32_t u32Tmp;

   uint8_t u8RowCyc;

   uint8_t u8ColCyc;

   uint32_t u32ParOffset = 0x00U;                /* Parameter Page offset */


      do
      {
         /* Read ONFI Parameter Page */
         vNF_CmdPhaseAxiRegAddr (pstNandCfg, u32ParOffset,
                                 NANDFLASH_CMD_ONFI_READ_PARAM);
         /* check with timeout for NAND readyness */
         eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
         if(eResult == NANDFLASH_STATUS_OK)
         {
          /* Return to Read Mode after the Status check (Internal ECC only) */
          if(pstNandCfg->eDeviceType != NANDFLASH_DEVICE_ONFI_HOST_ECC)
          {
            vNF_CmdPhaseAxi (pstNandCfg, NANDFLASH_CMD_READ_MODE);
          }
         /*
            Read 0-253 parameters with integrity check */
         for (u32Idx = 0U; u32Idx < (NANDFLASH_ONFI_MAX_PARAM - 4U);
              u32Idx = u32Idx + 4)
         {

            u32ReadNand =
               u32NF_DataPhaseAxiRead (pstNandCfg, NF_PAR_CS_ACTIV,
                                       NF_PAR_IGNORE);
            pstNandCfg->pu8Param[u32Idx] = (uint8_t)(u32ReadNand & 0x000000FFU);
            pstNandCfg->pu8Param[u32Idx + 1] =
               (uint8_t)((u32ReadNand >> 8) & 0x000000FFU);
            pstNandCfg->pu8Param[u32Idx + 2] =
               (uint8_t)((u32ReadNand >> 16) & 0x000000FFU);
            pstNandCfg->pu8Param[u32Idx + 3] =
               (uint8_t)((u32ReadNand >> 24) & 0x000000FFU);
         }
         /* Last read with CS to be disabled */

         u32ReadNand =
            u32NF_DataPhaseAxiRead (pstNandCfg, NF_PAR_CS_CLEAR, NF_PAR_IGNORE);

         pstNandCfg->pu8Param[u32Idx] = (uint8_t)(u32ReadNand & 0x000000FFU);
         pstNandCfg->pu8Param[u32Idx + 1] = (uint8_t)((u32ReadNand >> 8) & 0x000000FFU);
         pstNandCfg->pu8Param[u32Idx + 2] = (uint8_t)((u32ReadNand >> 16) & 0x000000FFU);
         pstNandCfg->pu8Param[u32Idx + 3] = (uint8_t)((u32ReadNand >> 24) & 0x000000FFU);

         /* Build CRC-16 word from last 2 bytes */
         u32tmp = pstNandCfg->pu8Param[(NANDFLASH_ONFI_MAX_PARAM - 1U)];
         u32DevCrc = (u32tmp << 8);         /* upper CRC-16 byte */
         u32tmp = pstNandCfg->pu8Param[(NANDFLASH_ONFI_MAX_PARAM - 2U)];
         u32DevCrc = u32DevCrc | u32tmp;    /* lower CRC-16 byte */
         /*
            CRC-16 calculation for all, but last 2 values */
         u32CalCrc =
            u16CRCGEN_CalculateCrc16 (&(pstNandCfg->pu8Param[0]),
                                      (NANDFLASH_ONFI_MAX_PARAM - 2U));
         if (u32CalCrc == u32DevCrc)
         {
            eResult = NANDFLASH_STATUS_OK;
         }
         else                               /* CRC-16 error - try 1st/2nd
                                               Redundant Parameter Page */
         {
            u32tmpOffset = (2 * NANDFLASH_ONFI_MAX_PARAM);

            if (u32ParOffset < u32tmpOffset)
            {
               u32ParOffset = (u32ParOffset + NANDFLASH_ONFI_MAX_PARAM);
            }
            else
            {
               eResult = NANDFLASH_STATUS_CRC_ERR; /* Exit loop with error */
            }
          }
         }
      }
      while (eResult == NANDFLASH_STATUS_UNKNOWN);

      if (eResult == NANDFLASH_STATUS_OK)   /* CRC was OK */
      {

         /* Compare readout to ONFI signature: ASCI codes */
         if ((pstNandCfg->pu8Param[0] == 0x4FU) &&
             (pstNandCfg->pu8Param[1] == 0x4EU) &&
             (pstNandCfg->pu8Param[2] == 0x46U) &&
             (pstNandCfg->pu8Param[3] == 0x49U))
         {
            /* Extract Bus Width */
            if ((pstNandCfg->pu8Param[6] & 0x01U) == 0x01U)
            {
               pstNandCfg->eBusWidth = NANDFLASH_BUS_WIDTH_16;
            }
            else
            {
               pstNandCfg->eBusWidth = NANDFLASH_BUS_WIDTH_8;
            }
            /* Extract Page Size */
            pstNandCfg->u32PageSize = pstNandCfg->pu8Param[80];
            u32Tmp = pstNandCfg->pu8Param[81];
            pstNandCfg->u32PageSize = pstNandCfg->u32PageSize | (u32Tmp << 8);
            u32Tmp = pstNandCfg->pu8Param[82];
            pstNandCfg->u32PageSize = pstNandCfg->u32PageSize | (u32Tmp << 16);
            u32Tmp = pstNandCfg->pu8Param[83];
            pstNandCfg->u32PageSize = pstNandCfg->u32PageSize | (u32Tmp << 24);
            /*
               Extract Spare Area Size */
            pstNandCfg->u16SpareSize = pstNandCfg->pu8Param[84];
            u32Tmp = pstNandCfg->pu8Param[85];
            pstNandCfg->u16SpareSize =
               pstNandCfg->u16SpareSize | (uint16_t)(u32Tmp << 8);
            /*
               Extract Block Size (number of Pages) */
            pstNandCfg->u32BlkSize = pstNandCfg->pu8Param[92];
            u32Tmp = pstNandCfg->pu8Param[93];
            pstNandCfg->u32BlkSize = pstNandCfg->u32BlkSize | (u32Tmp << 8);
            u32Tmp = pstNandCfg->pu8Param[94];
            pstNandCfg->u32BlkSize = pstNandCfg->u32BlkSize | (u32Tmp << 16);
            u32Tmp = pstNandCfg->pu8Param[95];
            pstNandCfg->u32BlkSize = pstNandCfg->u32BlkSize | (u32Tmp << 24);
            /*
               Page access Address Cycles number */
            u8RowCyc = (pstNandCfg->pu8Param[101] & 0x0FU);
            u8ColCyc = ((pstNandCfg->pu8Param[101] & 0xF0U) >> 4);
            pstNandCfg->u32PageAdrCycNo =
               ((uint32_t)u8RowCyc + (uint32_t)u8ColCyc)+1;
            /*
               Bits of ECC correctability */
            pstNandCfg->u8EccBitsCorr = pstNandCfg->pu8Param[112];
         }
         else
         {
            /* device is not compliant with ONFI standard */
            eResult = NANDFLASH_STATUS_NO_COMPLY_ERR;
         }
      }
      else
      {
         /* CRC ERROR: Error code updated already: can be optimized */
      }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
static NandFlashStatus_e eNF_SetFeature (const NandFlashCfg_st * const pstNandCfg,
                                         uint32_t u32SubAddress,
                                         uint8_t const pu8SubParBuf[])
{
   NandFlashStatus_e eResult;

   uint32_t u32DatPh;                       /* Word to be send within a command
                                               phase */
   uint32_t *pu32CmdPhDest;

   uint32_t u32WrData;

   uint32_t u32Tmp;


   /* ONFI SET FEATURE command with address == 0x90 == ECC ctrl */
   vNF_CmdPhaseAxiRegAddr (pstNandCfg, u32SubAddress,
                           NANDFLASH_CMD_ONFI_SET_FEATURE);
   /*
      WAIT ALE to data start tADL == 70ns Timing for tADL begins in the address
      cycle, on the final rising edge of WE#, and ends with the first rising
      edge of WE# for data input. On FPGA target it takes ~2u to send 8-bytes
      using 4 x !WE cycles - so total min. time is: 2.1 [us] + 70 [ns] */
   /*
      4 bytes are written per single access, so create a word to be written */
   u32WrData = pu8SubParBuf[0];
   u32Tmp = pu8SubParBuf[1];
   u32WrData = u32WrData | (u32Tmp << 8);
   u32Tmp = pu8SubParBuf[2];
   u32WrData = u32WrData | (u32Tmp << 16);
   u32Tmp = pu8SubParBuf[3];
   u32WrData = u32WrData | (u32Tmp << 24);
   /*
      Chip select must be finished in the last transfer. ECC calculation End
      depends on the u32EccLast parameter value. */
   u32DatPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
   u32DatPh = (u32DatPh | (NF_PAR_IGNORE << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
   u32DatPh =
      (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32DatPh =
      (u32DatPh | (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
   u32DatPh = (u32DatPh | (NF_PAR_IGNORE << (MEMCTRL_AXI_ECC_LAST_SFT)));
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : This warning cannot be avoided, since the PL353 MemCtrl requires a
*          specific pointer/access based on the integer value built upon the
*          combination of integer parameters.
****/
   pu32CmdPhDest = (uint32_t *)u32DatPh;    /* PRQA S 0306 */
   *pu32CmdPhDest = u32WrData;              /* 4 x 8-bit Write to device */

   __DSB();

   /* Wait until the ECC Feature is really setup */
   eResult = eNandFlash_WaitDeviceReady (pstNandCfg);

   return eResult;
}

/*..........................................................................*/
/* NOT_TESTED */
NandFlashStatus_e eNF_GetDeviceStatus (const NandFlashCfg_st * const pstNandCfg)
{
   NandFlashStatus_e eResult;

   uint8_t u8DevStat;

/*
 ONFI:
 In the case of non-interleaved operations, the Read Status function retrieves
 a status value for the last operation issued. If multiple interleaved operations
 are in progress on a single LUN, then Read Status returns the composite status
 value for status register bits that are independent per interleaved address.
 Specifically, Read Status shall return the combined status value of the
 independent status register bits according to Table 18. See section 5.10 for
 status register bit definitions. */
   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      vNF_CmdPhaseAxi (pstNandCfg, NANDFLASH_CMD_READ_STATUS);
      /* read ... */
      u8DevStat =
         (uint8_t)u32NF_DataPhaseAxiRead (pstNandCfg, NF_PAR_CS_CLEAR,
                                          NF_PAR_IGNORE);
      /* check only bit0: for non-interleaved operations */
      if ((u8DevStat & NF_INTERN_ECC_FAILED) == NF_INTERN_ECC_FAILED)
      {
         eResult = NANDFLASH_STATUS_OPERATION_ERR;
      }
      else
      {
         eResult = NANDFLASH_STATUS_OK;
      }
   }
   return eResult;
}

/*..........................................................................*/
NandFlashStatus_e eNF_ReadDeviceStatus (const NandFlashCfg_st * const pstNandCfg,
                                        uint32_t* pu32NandStatus )
{
   NandFlashStatus_e eResult;
   eResult = NANDFLASH_STATUS_OK;

   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      vNF_CmdPhaseAxi (pstNandCfg, NANDFLASH_CMD_READ_STATUS);
      /* read ... */
      *pu32NandStatus =
         (uint8_t)u32NF_DataPhaseAxiRead (pstNandCfg, NF_PAR_CS_CLEAR,
                                          NF_PAR_IGNORE);
   }
   return eResult;
}

/*..........................................................................*/

/* ***************** NAND Flash API Functions Definitions ***************** */

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_GetHwConfig (NandFlashCfg_st * pstNandCfg)
{
   NandFlashStatus_e eResult;

   uint32_t u32RdCfg;

   uint32_t u32Tmp;


   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      /* copy cycles data from register to the configuration structure */
      u32RdCfg = MEMCTRL_NAND_CYCLES;

      pstNandCfg->u32ReadCycleTime =
         ((u32RdCfg & (MEMCTRL_SET_T0_MSK)) >> (MEMCTRL_SET_T0_SFT));
      pstNandCfg->u32WriteCycleTime =
         ((u32RdCfg & (MEMCTRL_SET_T1_MSK)) >> (MEMCTRL_SET_T1_SFT));
      pstNandCfg->u32AssertDelayReN =
         ((u32RdCfg & (MEMCTRL_SET_T2_MSK)) >> (MEMCTRL_SET_T2_SFT));
      pstNandCfg->u32DeAssertDelayWeN =
         ((u32RdCfg & (MEMCTRL_SET_T3_MSK)) >> (MEMCTRL_SET_T3_SFT));
      pstNandCfg->u32StatusRdTime =
         ((u32RdCfg & (MEMCTRL_SET_T4_MSK)) >> (MEMCTRL_SET_T4_SFT));
      pstNandCfg->u32IdRdTime =
         ((u32RdCfg & (MEMCTRL_SET_T5_MSK)) >> (MEMCTRL_SET_T5_SFT));
      pstNandCfg->u32BusyCycleToReN =
         ((u32RdCfg & (MEMCTRL_SET_NAND_T6_MSK)) >> (MEMCTRL_SET_T6_SFT));
      /* copy operation mode data from register to the configuration structure */
      u32RdCfg = MEMCTRL_NAND_OPMODE;
      /*
         Load u32BusWidth */
      u32Tmp = ((u32RdCfg & (MEMCTRL_SET_MW_MSK)));
      if (u32Tmp == (MEMCTRL_SET_MW_16_BITS))
      {
         pstNandCfg->eBusWidth = NANDFLASH_BUS_WIDTH_16;
      }
      else
      {
         /* 0x00 and all other values should result as 8-bit mode */
         pstNandCfg->eBusWidth = NANDFLASH_BUS_WIDTH_8;
      }
      u32RdCfg = MEMCTRL_ECC_MEMCFG;
      u32Tmp = ((u32RdCfg & (MEMCTRL_ECC_EXTRA_BLOCK_MSK)));
      if (u32Tmp == (MEMCTRL_ECC_EXTRA_BLOCK_MSK))
      {
         u32Tmp = ((u32RdCfg & (MEMCTRL_ECC_EXTRA_BLOCK_SIZE_MSK)));
         switch (u32Tmp)
         {
            case MEMCTRL_ECC_EXTRA_BLOCK_SIZE_32B_BITS:
            {
               pstNandCfg->eExtraBlockCfg = NANDFLASH_EXTRA_BLOCK_32_BYTES;
            }
               break;
            case MEMCTRL_ECC_EXTRA_BLOCK_SIZE_16B_BITS:
            {
               pstNandCfg->eExtraBlockCfg = NANDFLASH_EXTRA_BLOCK_16_BYTES;
            }
               break;
            default:
            {
               pstNandCfg->eExtraBlockCfg = NANDFLASH_EXTRA_BLOCK_8_BYTES;
            }
            break;            
         }
      }
      else
      {
         pstNandCfg->eExtraBlockCfg = NANDFLASH_EXTRA_BLOCK_DISABLED;
      }

      /* Check all settings */
      eResult = eNF_ConfigVerify (pstNandCfg);
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_Initialize (NandFlashCfg_st * pstNandCfg,
                                         NandFlashDeviceType_e eDeviceType)
{
/***
* MESSAGE: Msg(3:3197) The initialiser for 'eResult' is always modified before
*          being used.
*
* DESC   : To detect that eResult is updated every time within this complex
*          function the initial value NANDFLASH_STATUS_UNKNOWN is used.
****/
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;    /* PRQA S 3197 */

   uint32_t u32DirCmdVal;    /* for direct_cmd register value */

   uint32_t u32Opmode;

   uint32_t u32Cycles;

   uint32_t u32Cyc;

   uint32_t u32Mod;

   uint32_t u32TryCnt = 0;   /* Register-update counter */


   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      /* First of all Device Initialization requires Power Supply settling
         time, which affects the Ready/#Busy line at Power Up. The NAND device
         spec. requires to wait min. 100us from PowerUp (if Busy line is not
         monitored). Since in PL353 the Ready state is asserting the
         edge-sensitive interrupt - the R/#B line cannot be monitored since the
         configuration of the signal requires MEMCTRL_BUSY_CFG_SET macro call
         (if configuration is done to late the #Busy/Ready edge IRQ will not be
         "latched" be PL353). */
      NF_uSecWait (NANDFLASH_INIT_TIME_MAX_us_CFG);
/***
* MESSAGE: MISRA-C:2004 Rule 12.11 Unsigned multiplication in constant
*          expression wraps around past maximum value.
*
* DESC   : Several warnings generated about the risk to cross the boundary of
*          the 32-bit integer type should be taken into account, while changing
*          the values/parameters of: NANDFLASH_BUSY_TIMEOUT_MAX_CFG and
*          NANDFLASH_ECC_TIMEOUT_MAX_CFG. With current selections the result
*          of the macros/calculations is within the range.
****/
      pstNandCfg->u32BusyTimeOut = NANDFLASH_BUSY_TIMEOUT_MAX_CFG;
      pstNandCfg->u32EccTimeOut = NANDFLASH_ECC_TIMEOUT_MAX_CFG;
      /* Enable Interrupts: INT_ENABLE0 and INT_ENABLE1 bits */
      /* MEMCTRL_MEM_CFG_SET = 0x00000003U; */

      if(pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_HOST_ECC)
      {
         /* ENABLE Busy signal for NAND with HOST ECC */
         MEMCTRL_BUSY_CFG_SET = MEMCTRL_BUSY_ENABLE;
         NANDFLASH_CLEAR_READY_IRQ ();         /* Clear after BUSY line cfg */
      }

      /* Warning: specify u32NandChipAddress according to LSI/FPGA spec. */
      pstNandCfg->u32NandChipAddress = MEMCTRL_NAND_CHIP_ADDRESS;

      eResult = eNF_ConfigVerify (pstNandCfg);

      if (eResult == NANDFLASH_STATUS_OK)
      {
         /* Initial copy should be done here to be able to access the device... */
         vNF_CopyConfigToRegs (pstNandCfg);

         /* !!! NEW: RESET the NAND device !!! */
         eResult = eNandFlash_ResetDevice (pstNandCfg);
         if (eResult == NANDFLASH_STATUS_OK)
         {
            /*
               This function should configure some parameters according to
               settings taken from the NAND devices configuration registers.
               Those settings are differently stored for ONFI compliant devices
               than for Samsung devices. */
            if (eDeviceType == (NANDFLASH_DEVICE_ONFI_HOST_ECC)) /* ONFI device */
            {
               pstNandCfg->eDeviceType = eDeviceType;
               eResult = eNF_ReadOnfiParamsPage (pstNandCfg);
            }
            else if (eDeviceType == (NANDFLASH_DEVICE_ONFI_VENDOR1_ECC))
            {
               pstNandCfg->eDeviceType = eDeviceType;
               /* MICRON/ONFI device with internal ECC */
               eResult = eNF_ReadOnfiParamsPage (pstNandCfg);

               if (eResult == NANDFLASH_STATUS_OK)
               {
                  /* Enable Internal device's ECC sequence */
                  uint8_t u8SubParBuf[] = { 0x08U, 0x00U, 0x00U, 0x00U };
                  /* SET INTERNAL ECC feature */
                  eResult = eNF_SetFeature (pstNandCfg, 0x90U, u8SubParBuf);
               }
            }
            else
            {
               eResult = NANDFLASH_STATUS_NO_COMPLY_ERR;
            }

            if (eResult == NANDFLASH_STATUS_OK)
            {
               /*
                  Check, if settings are correct */
               eResult = eNF_ConfigVerify (pstNandCfg);
               if (eResult == NANDFLASH_STATUS_OK)
               {
                  if (pstNandCfg->eBusWidth == NANDFLASH_BUS_WIDTH_16)
                  {
                     u32Opmode = MEMCTRL_SET_MW_16_BITS;
                  }
                  else                      /* 8-bit */
                  {
                     u32Opmode = MEMCTRL_SET_MW_8_BITS;
                  }
                  /* Update NAND OPMODE Register */
                  MEMCTRL_SET_OPMODE = u32Opmode;

                  u32Cycles = MEMCTRL_NAND_CYCLES;
                  MEMCTRL_SET_CYCLES = u32Cycles;
                  /*
                     Configuration is now within set_cycles and set_opmode
                     registers. To update the timing within the SMC for a NAND
                     device it is required to specify an UpdateRegs cmd_type
                     within the direct_cmd register. */
                  u32DirCmdVal =
                     ((MEMCTRL_NAND_CHIP_SEL_MSK) |
                      (MEMCTRL_CMD_TYPE_UPD_REGS_MSK));
                  MEMCTRL_DIRECT_CMD = u32DirCmdVal; /* Update registers for
                                                        NAND */

                  /* reuse eResult for this loop, assume unknown result */
                  eResult = NANDFLASH_STATUS_UNKNOWN;
                  do
                  {
                     u32Cyc = MEMCTRL_NAND_CYCLES;

                     u32Mod = (MEMCTRL_NAND_OPMODE & (MEMCTRL_SET_MW_MSK));

                     if ((u32Cyc == u32Cycles) && (u32Mod == u32Opmode))
                     {
                        eResult = NANDFLASH_STATUS_OK;
                     }
                     else
                     {
/***
* MESSAGE: MISRA-C:2004 Rule 1.1 [L] Nesting of control structures (statements)
*          exceeds 15 - program is non-conforming.
*          MISRA-C:2004 Rule 1.1; REFERENCE - ISO-5.2.4.1 Translation Limits
*
* DESC   : Two messages for below conditions are TRUE, however, to keep the
*          code readable the source code is preserved in its orginal form.
****/
                        if (u32TryCnt < 4U)
                        {    /* PRQA S 0715 */
                           MEMCTRL_DIRECT_CMD = u32DirCmdVal;
                           u32TryCnt++;
                        }
                        else
                        {    /* PRQA S 0715 */
                           eResult = NANDFLASH_STATUS_OPERATION_ERR; /* update
                                                                        failed */
                        }
                     }
                  }
                  while (!((eResult == (NANDFLASH_STATUS_OK)) ||
                          (eResult == (NANDFLASH_STATUS_OPERATION_ERR))));

                  eResult = NANDFLASH_STATUS_OK;
               }
            }
            else
            {
               /* eResult updated already - optimize it */
            }
         }
      }
   }
   return eResult;
}

/*..........................................................................*/
void NF_uSecWait (uint32_t u32usTime)
{
/***
* MESSAGE: MISRA-C:2004 Rule 13.2 Value of control expression is not derived
*          from an explicit logical operation.
*
* DESC   : The message for below condition is TRUE, however, to keep the
*          execution time unchanged (SW wait-loop) the source code will remain
*          unchanged.
****/
/***
* MESSAGE: MISRA-C:2004 Rule 21.1 Unsigned arithmetic definitely results in
*          wraparound past zero.
*
* DESC   : The wraparound even, if would happen should not be dangerous, since
*          the value of '0' should end the counting process, and the u32usTime
*          variable is not used later within the function.
****/

/***
* MESSAGE: MISRA-C:2004 Rule 12.13 Result of ++ or -- operator used in expression.
*
* DESC   : This very simple count-own loop has been verfied to generate time
*          intervals based on instruction execution. Thus the implementation
*          will remain.
****/

    while( u32usTime-- )    /* PRQA S 3372 */  /* PRQA S 3344 */
    {
       ;
    }
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_SetExtraBlock (NandFlashCfg_st * pstNandCfg,
                                            NandFlashExtraBlock_e eExtraBlkCfg)
{
   NandFlashStatus_e eResult;

   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      pstNandCfg->eExtraBlockCfg = eExtraBlkCfg;
      eResult = NANDFLASH_STATUS_OK;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_SetBusTiming (NandFlashCfg_st * pstNandCfg,
                                           uint32_t u32IdRdTime,
                                           uint32_t u32StatusRdTime,
                                           uint32_t u32WriteCycleTime,
                                           uint32_t u32ReadCycleTime)
{
   NandFlashStatus_e eResult;

   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      if ((u32IdRdTime > (NANDFLASH_ID_RD_MAX)) ||
          (u32StatusRdTime > (NANDFLASH_STATUS_RD_MAX)) ||
          (u32WriteCycleTime < (NANDFLASH_WR_CYCLE_MIN)) ||
          (u32WriteCycleTime > (NANDFLASH_WR_CYCLE_MAX)) ||
          (u32ReadCycleTime < (NANDFLASH_RD_CYCLE_MIN)) ||
          (u32ReadCycleTime > (NANDFLASH_RD_CYCLE_MAX)))
      {
         eResult = NANDFLASH_STATUS_CFG_ERR;
      }
      else
      {
         pstNandCfg->u32IdRdTime = u32IdRdTime;
         pstNandCfg->u32StatusRdTime = u32StatusRdTime;
         pstNandCfg->u32WriteCycleTime = u32WriteCycleTime;
         pstNandCfg->u32ReadCycleTime = u32ReadCycleTime;
         eResult = NANDFLASH_STATUS_OK;
      }
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_SetCycleAssertDelays (NandFlashCfg_st * pstNandCfg,
                                                   uint32_t u32BusyCycleToReN,
                                                   uint32_t u32DeAssertDelayWeN,
                                                   uint32_t u32AssertDelayReN)
{
   NandFlashStatus_e eResult;

   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      if ((u32AssertDelayReN < (NANDFLASH_ASSERT_REN_MIN)) ||
          (u32AssertDelayReN > (NANDFLASH_ASSERT_REN_MAX)) ||
          (u32DeAssertDelayWeN < (NANDFLASH_DEASSERT_WEN_MIN)) ||
          (u32DeAssertDelayWeN > (NANDFLASH_DEASSERT_WEN_MAX)) ||
          (u32BusyCycleToReN > (NANDFLASH_BUSY_TO_REN_MAX)))
      {
         eResult = NANDFLASH_STATUS_CFG_ERR;
      }
      else
      {
         pstNandCfg->u32AssertDelayReN = u32AssertDelayReN;
         pstNandCfg->u32DeAssertDelayWeN = u32DeAssertDelayWeN;
         pstNandCfg->u32BusyCycleToReN = u32BusyCycleToReN;
         eResult = NANDFLASH_STATUS_OK;
      }

   }
   return eResult;
}

/*..........................................................................*/
/*  Note from device's Data Sheet:
  While monitoring the status register to determine when a data transfer from
 the Flash array to the data register (tR) is complete, the host must issue the
 READ MODE (00h) command to disable the status register and enable data output
 (see Read Operations). */
/* TESTED */
NandFlashStatus_e eNandFlash_WaitDeviceReady (const NandFlashCfg_st *
                                              const pstNandCfg)
{
   NandFlashStatus_e eResult;


   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      uint32_t u32BusyReady;

      uint32_t u32TimeCycles = pstNandCfg->u32BusyTimeOut;

     /* Devices with HOST ECC will be handled with BUSY signal
     Edge-sensitive interrupts, while devices with Internal ECC
     will be handled with Status Register Busy check */
     if(pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_HOST_ECC)
     {
        /* 100ns wait for settling of the BUSY line state... */
        NF_uSecWait (NANDFLASH_TIME_1us);

        /* Single Loop below executes 12 instructions - each dealy could be 12x
         shorter (set to 10x to be ion the safe side) than initially assumed
         the required values are set directly within the defines in NandFlash.h */
        do
        {
         u32BusyReady = (MEMCTRL_MEMC_STATUS);
         u32BusyReady = u32BusyReady & (MEMCTRL_RAW_INT_STATUS1_BIT);
         if (u32BusyReady == 0)
         {
            /* count down loop with device status check... */
            if (u32TimeCycles > 0x0U)
            {
               u32TimeCycles--;
            }
         }
        }
        while (!((u32BusyReady == (MEMCTRL_RAW_INT_STATUS1_BIT)) ||
                (u32TimeCycles == 0U)));
      /*
         Waiting should be finished, when the raw_int_status1 bit is HIGH or
         the loop counter reaches 0. */
      if (u32BusyReady == (MEMCTRL_RAW_INT_STATUS1_BIT))
      {
         /* Clear generated IRQ and return OK */
         NANDFLASH_CLEAR_READY_IRQ ();
         eResult = NANDFLASH_STATUS_OK;
      }
      else
      {
         eResult = NANDFLASH_STATUS_BUSY_ERR; /* busy timout expired */
      }
     }
     else
     {
      /* Single Loop below executes 12 instructions So each delay could be 12x
         shorter (set to 10x to be ion the safe side) than initially assumed
         the required values are set directly within the defines in NandFlash.h
      */
      vNF_CmdPhaseAxi (pstNandCfg, NANDFLASH_CMD_READ_STATUS);
      do
      {
         u32BusyReady = u32NF_DataPhaseAxiRead (pstNandCfg, NF_PAR_CS_ACTIV,
                                                NF_PAR_IGNORE);
         /* extract #Busy/Ready bit */
         u32BusyReady = (u32BusyReady & 0x40U);
         if (u32BusyReady == 0x00U)
         {
            /* NAND device BUSY: count down loop with another status check */
            if (u32TimeCycles > 0x0U)
            {
               u32TimeCycles--;
            }
         }
      }
      while (!((u32BusyReady == (0x40U)) || (u32TimeCycles == 0U)));
      /* Read it one more time and disable CS */
      u32BusyReady = u32NF_DataPhaseAxiRead (pstNandCfg, NF_PAR_CS_CLEAR,
                                             NF_PAR_IGNORE);
      /* extract #Busy/Ready bit */
      u32BusyReady = (u32BusyReady & 0x40U);

      /* Waiting should be finished, when the #Busy/Ready bit is HIGH or
         the loop counter reaches 0. */
      if (u32BusyReady == 0x40U)
      {
         /* consider return to Read mode... */
         eResult = NANDFLASH_STATUS_OK;
      }
      else
      {
         eResult = NANDFLASH_STATUS_BUSY_ERR; /* busy timout expired */
      }
     }
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNF_EccWaitIdle (const NandFlashCfg_st * const pstNandCfg)
{
   NandFlashStatus_e eResult;

   uint32_t u32TimeCycles = pstNandCfg->u32EccTimeOut;

   uint32_t u32EccStatus;


   /* Wait with timer until the ECC block is IDLE */
   do
   {
      /* count down loop with device status check... */
      if (u32TimeCycles > 0x0U)
      {
         u32TimeCycles--;
      }
      u32EccStatus = (MEMCTRL_ECC_STATUS);
      u32EccStatus = u32EccStatus & (MEMCTRL_ECC_BUSY_MSK);
   }
   while (!((u32EccStatus != (MEMCTRL_ECC_BUSY_MSK)) || (u32TimeCycles == 0U)));
   /*
      Waiting should be finished, when the ECC status bit is 0 (IDLE) or the
      loop counter reaches 0. */
   if (u32EccStatus != (MEMCTRL_ECC_BUSY_MSK))
   {
      eResult = NANDFLASH_STATUS_OK;
   }
   else
   {
      eResult = NANDFLASH_STATUS_BUSY_ERR;  /* busy timout expired */
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_ResetDevice (const NandFlashCfg_st * const pstNandCfg)
{
   NandFlashStatus_e eResult;


   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      vNF_CmdPhaseAxi (pstNandCfg, NANDFLASH_CMD_RESET);
      eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_ReadSinglePage (NandFlashCfg_st * pstNandCfg,    /* PRQA S 3673 */
                                             uint32_t u32BlockNumber,
                                             uint32_t u32PageNumber,
                                             uint32_t pu32DstBuf[],
                                             uint32_t pu32ExtrBuf[])
{
/***
* MESSAGE: Msg(3:3197) The initialiser for 'eResult' is always modified before
*          being used.
*
* DESC   : To detect that eResult is updated every time within this complex
*          function the initial value NANDFLASH_STATUS_UNKNOWN is used.
****/
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;    /* PRQA S 3197 */


   if ((pstNandCfg == TYPES_NULL_PTR))
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      if (u32PageNumber < (pstNandCfg->u32BlkSize))
      {
         uint32_t u32BufferLen = ((pstNandCfg->u32PageSize) >> 2);

         /* ECC handled differently for devices with internal ECC */
         if (pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_VENDOR1_ECC)
         {
            vNF_CmdPhaseAxiCplx (pstNandCfg, 0x0U, u32PageNumber,
                                 u32BlockNumber, NANDFLASH_CMD_PAGE_RD_START,
                                 NF_PAR_END_VALID, NANDFLASH_CMD_PAGE_RD_END);
            /* Wait until ready: Take into account: tWB tR tRR tR_ECC */
            eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
            /* Return to Read Mode after the Status check (Internal ECC only) */
            if(pstNandCfg->eDeviceType != NANDFLASH_DEVICE_ONFI_HOST_ECC)
            {
              vNF_CmdPhaseAxi (pstNandCfg, NANDFLASH_CMD_READ_MODE);
            }

            if (eResult == NANDFLASH_STATUS_OK)
            {
               vNF_DataPhaseAxiRdMulti (pstNandCfg, u32BufferLen, pu32DstBuf,
                                        NF_PAR_IGNORE, pu32ExtrBuf);

               /* Check devices status: SR bit0 = 0: READ successful SR bit 1 =
                  0 READ error */
               eResult = eNF_GetDeviceStatus (pstNandCfg);
               /* ****** FINAL eResult should be available here ****** */
            }
         }
         else                               /* 1-bit ECC: ONFI devices */
         {
            /* Prepare ECC HW before reading data */
            eResult = eNF_EccConfigure (pstNandCfg);

            if (eResult == NANDFLASH_STATUS_OK)
            {
               vNF_CmdPhaseAxiCplx (pstNandCfg, 0U, u32PageNumber,
                                    u32BlockNumber, NANDFLASH_CMD_PAGE_RD_START,
                                    NF_PAR_END_VALID,
                                    NANDFLASH_CMD_PAGE_RD_END);
               eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
            /* Return to Read Mode after the Status check (Internal ECC only) */
               if(pstNandCfg->eDeviceType != NANDFLASH_DEVICE_ONFI_HOST_ECC)
               {
                 vNF_CmdPhaseAxi (pstNandCfg, NANDFLASH_CMD_READ_MODE);
               }

               if (eResult == NANDFLASH_STATUS_OK)
               {
                  vNF_DataPhaseAxiRdMulti (pstNandCfg, u32BufferLen, pu32DstBuf,
                                           NF_PAR_ECC_LAST, pu32ExtrBuf);
                  /* Wait until ECC is IDLE */
                  eResult = eNF_EccWaitIdle (pstNandCfg);
                  if (eResult == NANDFLASH_STATUS_OK)
                  {
                     /*
                      *** Now apply ECC Correction, based on ECC values ***
                      */
/***
* MESSAGE: MISRA-C:2004 Rule 11.4; Casting to different object pointer type.
*
* DESC   : Due to a different nature of the reading (32-bit accesses) and error
*          correction (based on byte-addressing) it is required to cast
*          pointers. It should be safe since 32-bit buffer is used as being an
*          8-bit buffer.
*
****/
                     eResult =
                        eNF_EccCorrectLarge (pstNandCfg, (uint8_t *)pu32DstBuf,     /* PRQA S 0310 */
                                             (uint8_t *)pu32ExtrBuf);               /* PRQA S 0310 */
                  }
               }
               /* ****** FINAL eResult should be available here ****** */
            }
            else
            {
               eResult = eResult;           /* to be optimized / removed ... */
            }
         }
      }
      else
      {
         eResult = NANDFLASH_STATUS_USAGE_ERR;
      }
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED
 u32SpareOffset: offset within spare Area is always counted in 32-bit words */
NandFlashStatus_e eNandFlash_ReadSpareArea (NandFlashCfg_st * pstNandCfg,    /* PRQA S 3673 */
                                            uint32_t u32BlockNumber,
                                            uint32_t u32PageNumber,
                                            uint32_t u32SpareOffset,
                                            uint32_t u32BufferLen,
                                            uint32_t pu32DstBuf[])
{
/***
* MESSAGE: Msg(3:3197) The initialiser for 'eResult' is always modified before
*          being used.
*
* DESC   : To detect that eResult is updated every time within this complex
*          function the initial value NANDFLASH_STATUS_UNKNOWN is used.
****/
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;    /* PRQA S 3197 */

   uint32_t u32EccSetOld;

   uint32_t u32EccSetNew;

   uint32_t u32SpareAdr;


   if ((pstNandCfg == TYPES_NULL_PTR))
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      /*
         Spare area read requires to temporary disable Host's ECC engine. */
      u32EccSetOld = MEMCTRL_ECC_MEMCFG;    /* remember orig. settings */
      u32EccSetNew = u32EccSetOld & ~(MEMCTRL_ECC_MODE_MSK); /* Disable ECC */
      MEMCTRL_ECC_MEMCFG = u32EccSetNew;    /* Write it back to MemCtrl */

      if ((u32SpareOffset + u32BufferLen) <= ((pstNandCfg->u16SpareSize) >> 2))
      {
         if (u32PageNumber < (pstNandCfg->u32BlkSize))
         {
            /*
               Spare Area: address just after the Page. The address differs for
               8-bit and 16-bit devices. */
            if (pstNandCfg->eBusWidth == NANDFLASH_BUS_WIDTH_8)
            {
               /* 2kB Page + 64 bytes Spare */
               u32SpareAdr = (pstNandCfg->u32PageSize + u32SpareOffset);
            }
            else
            {
               /* 1k 16-bit Words Page + 32x 16-bit Words Spare */
               u32SpareAdr =
                  (((pstNandCfg->u32PageSize) >> 1) + u32SpareOffset);
            }

            vNF_CmdPhaseAxiCplx (pstNandCfg, u32SpareAdr, u32PageNumber,
                                 u32BlockNumber, NANDFLASH_CMD_PAGE_RD_START,
                                 NF_PAR_END_VALID, NANDFLASH_CMD_PAGE_RD_END);

            eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
            /* Return to Read Mode after the Status check (Internal ECC only) */
            if(pstNandCfg->eDeviceType != NANDFLASH_DEVICE_ONFI_HOST_ECC)
            {
              vNF_CmdPhaseAxi (pstNandCfg, NANDFLASH_CMD_READ_MODE);
            }

            if (eResult == NANDFLASH_STATUS_OK)
            {
               /*
                  Read of the spare area (typically ECC related) does not
                  invlove the ECC calculation itself - that's why use:
                  NF_PAR_IGNORE. */
               vNF_DataPhaseAxiRdMulti (pstNandCfg, u32BufferLen, pu32DstBuf,
                                        NF_PAR_IGNORE, (uint32_t *)0x00U);
               eResult = eNF_GetDeviceStatus (pstNandCfg);
               /* ****** FINAL eResult should be available here ****** */
            }
            else
            {
               eResult = eResult;           /* to be optimized / removed ... */
            }
         }
         else
         {
            eResult = NANDFLASH_STATUS_USAGE_ERR;
         }
      }
      else
      {
         eResult = NANDFLASH_STATUS_SIZE_ERR; /* too many data to be read! */
      }
      MEMCTRL_ECC_MEMCFG = u32EccSetOld;    /* Write old settings to MemCtrl */
   }
   return eResult;
}

/*..........................................................................*/
/*..........................................................................*/
/***
* MESSAGE: MISRA-C:2004 Rule 16.7 The object addressed by the pointer parameter
*          'pu32DstBuf' (same for 'pu8ExtrBuf') is not modified and so the
*          pointer could be of type 'pointer to const'.
*
* DESC   : The two warnings are not applicable. the MISRA tool did not recognize
*          that this function calls suroutines, which might modify the content
*          of both buffers.
****/
NandFlashStatus_e eNandFlash_ReadPages (NandFlashCfg_st * pstNandCfg,
                                        uint32_t u32BlockNumber,
                                        uint32_t u32StartPage,
                                        uint32_t u32NoOfPages,
                                        uint32_t pu32DstBuf[],    /* PRQA S 3673 */
                                        uint32_t pu32ExtrBuf[])
{
/***
* MESSAGE: Msg(3:3197) The initialiser for 'eResult' is always modified before
*          being used.
*
* DESC   : To detect that eResult is updated every time within this complex
*          function the initial value NANDFLASH_STATUS_UNKNOWN is used.
****/
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;     /* PRQA S 3197 */

   uint32_t u32Idx;

   uint32_t u32DstAddr ;


   if ((pstNandCfg == TYPES_NULL_PTR))
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      /*
         Check, if all Pages belong to the current block. */
      if (u32NoOfPages > 0U)                /* is anything to read */
      {
         u32Idx = u32StartPage;
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
*          MISRA-C:2004 Rule 1.2; [U] Integral type is not large enough to hold
*          a pointer value.
*
* DESC   : These messages are undestood, but the pointer manipulation was
*          required to maintian the position within the buffer. As unsigned int
*          type is 32-bit on ARM, which is same as pointer - there should be no
*          danger with such cast.
****/
         /* Source location to read from */
         u32DstAddr = (uint32_t)pu32DstBuf;     /* PRQA S 0306 */
         do
         {
            if (u32Idx >= pstNandCfg->u32BlkSize) /* check range/condition! */
            {
               /* This function might cross the total size / number of blocks
                  of the NAND device. DO NOT reset StartPage since it is used
                  in the loop exit condition. */
               u32BlockNumber++;
               u32NoOfPages = (u32NoOfPages - (u32Idx - u32StartPage));
               /* Read should continue at the beginning of the next block */
               u32Idx = 0U;
               u32StartPage = 0U;
            }
/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : These message is undestood, but the pointer manipulation was
*          required to maintian the position within the buffer. Here the reverse
*          cast is required (see upper listed MISRA warnings).
****/
            eResult =
               eNandFlash_ReadSinglePage (pstNandCfg, u32BlockNumber, u32Idx,      /* PRQA S 0306 */
                                          (uint32_t *)u32DstAddr, pu32ExtrBuf);    /* PRQA S 0306 */
            u32Idx++;
            u32DstAddr = (u32DstAddr + pstNandCfg->u32PageSize);
         }
         while (((u32Idx < (u32NoOfPages + u32StartPage)) &&
                 (eResult == NANDFLASH_STATUS_OK)));

         /* ****** FINAL eResult should be available here ****** */
      }
      else
      {
         eResult = NANDFLASH_STATUS_PARAM_ERR; /* */
      }
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED: */
NandFlashStatus_e eNandFlash_ReadNand (NandFlashCfg_st * pstNandCfg,
                                       uint32_t u32StartAddr,
                                       uint32_t pu32Data[],
                                       uint32_t u32BufferLen)
{
   NandFlashStatus_e eNandStatus;

   uint32_t u32BlockBytes;

   uint32_t u32BlockNumber;

   uint32_t u32ByteBlkOffset;

   uint32_t u32StartPage;

   uint32_t u32NoOfPages;


   /* Calculate Block and Page number */
   u32BlockBytes = (pstNandCfg->u32BlkSize) * (pstNandCfg->u32PageSize);
   /* Block number where the addr is pointing to */
   u32BlockNumber = (u32StartAddr / u32BlockBytes);
   /* Address offset from the beginning of the block */
   u32ByteBlkOffset = (u32StartAddr % u32BlockBytes);
   /* Page number, in which the addr is pointing to */
   u32StartPage = (u32ByteBlkOffset / (pstNandCfg->u32PageSize));
   /* Convert no of 32-bit Words to no of Bytes */
   u32BufferLen = (u32BufferLen << 2);

   /* Calculate how many pages should be read */
   u32NoOfPages = ((u32BufferLen) / pstNandCfg->u32PageSize);
   /*
      Check, if one additional page needs to be read */
   if (((u32BufferLen) % (pstNandCfg->u32PageSize)) != 0)
   {
      u32NoOfPages++;                       /* Another page must be read */
   }
   /* Perform NAND data-read */
   eNandStatus =
      eNandFlash_ReadPages (pstNandCfg, u32BlockNumber, u32StartPage,
                            u32NoOfPages, pu32Data, pu32GlExtraBlockBuf);
   return eNandStatus;
}


/****************************************************************************/


/***********************  BEGIN of DISCLAIMER   *****************************

- TOSHIBA is continually working to improve the quality and reliability of
  its products.
  Nevertheless, semiconductor devices in general can malfunction or fail
  due to their inherent electrical sensitivity and vulnerability to physical
  stress. It is the responsibility of the buyer, when utilizing TOSHIBA
  products, to comply with the standards of safety in making a safe design
  for the entire system, and to avoid situations in which a malfunction or
  failure of such TOSHIBA products could cause loss of human life,
  bodily injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications. Also, please keep in mind the precautions and
  conditions set forth in the “Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (“Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer’s own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit,business interruption, loss of business
  information,and other pecuniary losses) occurring from the use of,
  or inability to use, this product.

- The products described in this document are subject to the foreign exchange
  and foreign trade laws.

- The products described in this document contain components made in the
  United States and subject to export control of the U.S. authorities.
  Diversion contrary to the U.S. law is prohibited.

- The information contained herein is presented only as a guide for the
  applications of our products.
  No responsibility is assumed by TOSHIBA CORPORATION for any infringements
  of intellectual property or other rights of the third parties which may
  result from its use.
  No license is granted by implication or otherwise under any intellectual
  property or other rights of TOSHIBA CORPORATION or others.

- The information contained herein is subject to change without notice.

****************************  END of DISCLAIMER ****************************/

