/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : NOR LLDD
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : IPL
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.5 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/

#include "captypes.h"                   /* Cap-Bt Data types header */
#include "pl353memctrl.h"               /* Board specific defines */
#include "pl353nor.h"                   /* Driver's API header file */

/* Public-scope objects ---------------------------------------------------*/

/* Package-scope objects ---------------------------------------------------*/

/* Local-scope objects -----------------------------------------------------*/

/* *** NOR Flash device related RANGES for MemCtrl settings *** */
#define NORFLASH_RD_CYCLE_MIN   (2U)
#define NORFLASH_RD_CYCLE_MAX   (15U)

#define NORFLASH_WR_CYCLE_MIN   (2U)
#define NORFLASH_WR_CYCLE_MAX   (15U)

#define NORFLASH_ASSERT_OEN_MIN    (1U)
#define NORFLASH_ASSERT_OEN_MAX    (7U)

#define NORFLASH_ASSERT_WEN_MIN  (1U)
#define NORFLASH_ASSERT_WEN_MAX  (7U)

#define NORFLASH_PAGE_CYCLE_MIN     (1U)
#define NORFLASH_PAGE_CYCLE_MAX     (7U)

#define NORFLASH_TURNAROUND_MIN     (1U)
#define NORFLASH_TURNAROUND_MAX     (7U)

/* **************** NOR Flash Local Functions Declarations **************** */

/*****************************************************************************
* Checks, if values in the configuration structure are valid and can be written
* to the Memory Controller and/or NOR device.
*****************************************************************************/
static NorFlashStatus_e eNorF_ConfigVerify (const NorFlashCfg_st *
                                            const pstNorCfg);

/*****************************************************************************
* Function copies configuration parameters from the configuration structure
* to the Memory Controller and/or NOR device registers.
*****************************************************************************/
static void vNorF_CopyConfigToRegs (NorFlashCfg_st * const pstNorCfg);

/*..........................................................................*/

/* ***************** NOR Flash Local Functions Definitions **************** */

/*..........................................................................*/
/* TESTED */
static NorFlashStatus_e eNorF_ConfigVerify (const NorFlashCfg_st *
                                            const pstNorCfg)
{
   NorFlashStatus_e eResult;

   /* check cycles settings */
   if ((pstNorCfg->u32ReadCycleTime < (NORFLASH_RD_CYCLE_MIN)) ||
       (pstNorCfg->u32ReadCycleTime > (NORFLASH_RD_CYCLE_MAX)) ||
       (pstNorCfg->u32WriteCycleTime < (NORFLASH_WR_CYCLE_MIN)) ||
       (pstNorCfg->u32WriteCycleTime > (NORFLASH_WR_CYCLE_MAX)) ||
       (pstNorCfg->u32AssertDelayOeN < (NORFLASH_ASSERT_OEN_MIN)) ||
       (pstNorCfg->u32AssertDelayOeN > (NORFLASH_ASSERT_OEN_MAX)) ||
       (pstNorCfg->u32AssertDelayWeN < (NORFLASH_ASSERT_WEN_MIN)) ||
       (pstNorCfg->u32AssertDelayWeN > (NORFLASH_ASSERT_WEN_MAX)) ||
       (pstNorCfg->u32PageCycleTime < (NORFLASH_PAGE_CYCLE_MIN)) ||
       (pstNorCfg->u32PageCycleTime > (NORFLASH_PAGE_CYCLE_MAX)) ||
       (pstNorCfg->u32TurnaroundTime < (NORFLASH_TURNAROUND_MIN)) ||
       (pstNorCfg->u32TurnaroundTime > (NORFLASH_TURNAROUND_MAX)))
   {
/***
* MESSAGE: MISRA-C:2004 Rule 14.1 This statement is unreachable.

* DESC   : Not applicable: In case of wrong run-time value (see comment above)
*          it could happen that some of values above are out-of-range.
****/
      eResult = NORFLASH_STATUS_CFG_ERR;    /* Invalid Parameter(s)! */
   }
   else
   {
      /*
         Verify also (to be done after PL353 HW config is fixed): For read
         transfers, the maximum memory burst length on the memory interface is
         the depth of the read data FIFO. For writes, the maximum burst length
         is dependent on: - the beat size of the AXI transfer, asize - the
         memory data bus width, mw - the depth of the write data FIFO depth,
         wfifo_depth. The formula to determine the maximum memory write burst
         length is: Memory write burst length = ((1<<asize) x wfifo_depth) /
         (1<<mw) */
      /* check opmode settings */
/***
* MESSAGE: MISRA-C:2004 Rule 13.7 The result of this logical operation is always
*          'false'.
*
* DESC   : The check below is required for enum types since structure members
*          might contain values (after C cast operation) specified at the
*          "run-time", whicjh could be by out-of-range of the respective
*          enumeration type.
****/
      if ((pstNorCfg->eBusWidth != (NORFLASH_BUS_WIDTH_16)) ||           /* PRQA S 3356 */
          (pstNorCfg->eRdBursLen >= (NORFLASH_BURST_LEN_CNTS)) ||        /* PRQA S 3356 */
          (pstNorCfg->eWrBursLen >= (NORFLASH_BURST_LEN_CNTS)) ||        /* PRQA S 3356 */ /* PRQA S 3359 */
          (pstNorCfg->eBurstAlign > (NORFLASH_BURST_ALGN_CROSS_256)))    /* PRQA S 3356 */
      {    /* PRQA S 3201 */
         eResult = NORFLASH_STATUS_CFG_ERR; /* Invalid Parameter(s)! */
      }
      else
      {
         eResult = NORFLASH_STATUS_OK;      /* All Parameters OK */
      }
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
static void vNorF_CopyConfigToRegs (NorFlashCfg_st * const pstNorCfg)
{
   uint32_t u32Cfg;

   /* copy cycles/opmode data from the configuration structure to registers */
   u32Cfg = 0U;
   u32Cfg = u32Cfg | ((pstNorCfg->u32ReadCycleTime) << (MEMCTRL_SET_T0_SFT));
   u32Cfg = u32Cfg | ((pstNorCfg->u32WriteCycleTime) << (MEMCTRL_SET_T1_SFT));
   u32Cfg = u32Cfg | ((pstNorCfg->u32AssertDelayOeN) << (MEMCTRL_SET_T2_SFT));
   u32Cfg = u32Cfg | ((pstNorCfg->u32AssertDelayWeN) << (MEMCTRL_SET_T3_SFT));
   u32Cfg = u32Cfg | ((pstNorCfg->u32PageCycleTime) << (MEMCTRL_SET_T4_SFT));
   u32Cfg = u32Cfg | ((pstNorCfg->u32TurnaroundTime) << (MEMCTRL_SET_T5_SFT));
   /*
      we_time */
   if (pstNorCfg->eWeTime == NORFLASH_WE_TIME_CFG_WEN_TOGETHER)
   {
      u32Cfg = u32Cfg | (MEMCTRL_SET_SRAM_T6_MSK);
   }
   /*
      Update register */
   MEMCTRL_SET_CYCLES = u32Cfg;
   pstNorCfg->u32set_cycles = u32Cfg;       /* store content of set_cycles */

   u32Cfg = 0U;
   /* u32Cfg value must be "0", otherwise settings below will be incorrect */
   /*
      Bus Width is always the same */
   u32Cfg = (u32Cfg | (MEMCTRL_SET_MW_16_BITS));

   /*
      Read Mode */
   if (pstNorCfg->eRdMode == NORFLASH_SYNC_MODE)
   {
      u32Cfg = (u32Cfg | (MEMCTRL_SET_RD_SYNC_MSK));
   }
   /*
      Read Burst Length */
   switch (pstNorCfg->eRdBursLen)
   {
      case NORFLASH_BURST_LEN_1:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_RD_BL_1_BITS));
      }
         break;
      case NORFLASH_BURST_LEN_4:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_RD_BL_4_BITS));
      }
         break;
      case NORFLASH_BURST_LEN_8:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_RD_BL_8_BITS));
      }
         break;
      case NORFLASH_BURST_LEN_16:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_RD_BL_16_BITS));
      }
         break;
      case NORFLASH_BURST_LEN_32:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_RD_BL_32_BITS));
      }
         break;
      default:                             /* NORFLASH_BURST_LEN_CNTS */
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_RD_BL_CNTS_BITS));
      }
         break;
   }
   /*
      Write Mode */
   if (pstNorCfg->eWrMode == NORFLASH_SYNC_MODE)
   {
      u32Cfg = (u32Cfg | (MEMCTRL_SET_WR_SYNC_MSK));
   }
   /*
      Write Burst Length */
   switch (pstNorCfg->eWrBursLen)
   {
      case NORFLASH_BURST_LEN_1:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_WR_BL_1_BITS));
      }
         break;
      case NORFLASH_BURST_LEN_4:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_WR_BL_4_BITS));
      }
         break;
      case NORFLASH_BURST_LEN_8:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_WR_BL_8_BITS));
      }
         break;
      case NORFLASH_BURST_LEN_16:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_WR_BL_16_BITS));
      }
         break;
      case NORFLASH_BURST_LEN_32:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_WR_BL_32_BITS));
      }
         break;
      default:                             /* NORFLASH_BURST_LEN_CNTS */
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_WR_BL_CNTS_BITS));
      }
         break;
   }
   /*
      Burst Address Advance Signal */
   if (pstNorCfg->eBurstAdrAdvSig == NORFLASH_USE_ADV_SIG)
   {
      u32Cfg = (u32Cfg | (MEMCTRL_SET_BAA_MSK));
   }
   /*
      Address Advance Signal */
   if (pstNorCfg->eAdrAdvSig == NORFLASH_USE_ADV_SIG)
   {
      u32Cfg = (u32Cfg | (MEMCTRL_SET_ADV_MSK));
   }
   /*
      Byte Lane Strobe */
   if (pstNorCfg->eByteLane == NORFLASH_BYTE_LANE_AS_WEN)
   {
      u32Cfg = (u32Cfg | (MEMCTRL_SET_BLS_MSK));
   }
   /*
      Burst Align */
   switch (pstNorCfg->eBurstAlign)
   {
      case NORFLASH_BURST_ALGN_CROSS_ANY:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_BRST_CR_ANY_BITS));
      }
         break;
      case NORFLASH_BURST_ALGN_CROSS_32:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_BRST_CR_32_BITS));
      }
         break;
      case NORFLASH_BURST_ALGN_CROSS_64:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_BRST_CR_64_BITS));
      }
         break;
      case NORFLASH_BURST_ALGN_CROSS_128:
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_BRST_CR_128_BITS));
      }
         break;
      default:                             /* NORFLASH_BURST_ALGN_CROSS_256 */
      {
         u32Cfg = (u32Cfg | (MEMCTRL_SET_BRST_CR_256_BITS));
      }
         break;
   }
   /*
      Update register */
   MEMCTRL_SET_OPMODE = u32Cfg;
   pstNorCfg->u32set_opmode = u32Cfg;       /* store content of set_opmode */
}

/*..........................................................................*/

/* ***************** NOR Flash API Functions Definitions ***************** */

/*..........................................................................*/

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_GetHwConfig (NorFlashCfg_st * pstNorCfg)
{
   NorFlashStatus_e eResult;

   /* Initialize the NOR memory region Base Address */
   pstNorCfg->u32NorChipAdr = NORFLASH_BASE_ADDRESS;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      uint32_t u32RdCfg;

      /* copy cycles data from SRAM register to the configuration structure */
      u32RdCfg = MEMCTRL_SRAM_CYCLES;
      pstNorCfg->u32ReadCycleTime =
         ((u32RdCfg & (MEMCTRL_SET_T0_MSK)) >> (MEMCTRL_SET_T0_SFT));
      pstNorCfg->u32WriteCycleTime =
         ((u32RdCfg & (MEMCTRL_SET_T1_MSK)) >> (MEMCTRL_SET_T1_SFT));
      pstNorCfg->u32AssertDelayOeN =
         ((u32RdCfg & (MEMCTRL_SET_T2_MSK)) >> (MEMCTRL_SET_T2_SFT));
      pstNorCfg->u32AssertDelayWeN =
         ((u32RdCfg & (MEMCTRL_SET_T3_MSK)) >> (MEMCTRL_SET_T3_SFT));
      pstNorCfg->u32PageCycleTime =
         ((u32RdCfg & (MEMCTRL_SET_T4_MSK)) >> (MEMCTRL_SET_T4_SFT));
      pstNorCfg->u32TurnaroundTime =
         ((u32RdCfg & (MEMCTRL_SET_T5_MSK)) >> (MEMCTRL_SET_T5_SFT));

      if (((u32RdCfg & (MEMCTRL_SET_SRAM_T6_MSK)) == (MEMCTRL_SET_SRAM_T6_MSK)))
      {
         /* bit is 1: we_n and cs_n assert together */
         pstNorCfg->eWeTime = NORFLASH_WE_TIME_CFG_WEN_TOGETHER;
      }
      else
      {
         /* bit is 0: we_n 2 mclk cycles after cs_n */
         pstNorCfg->eWeTime = NORFLASH_WE_TIME_CFG_WEN_AFTER;
      }

      /* copy operation mode data from register to the configuration structure */
      u32RdCfg = (0x0000FFFFU & MEMCTRL_SRAM_OPMODE);
      /*
         mw bits: BUS WIDTH is fixed to 16-bits always! */
      pstNorCfg->eBusWidth = NORFLASH_BUS_WIDTH_16;
      /*
         rd_sync bit */
      if ((u32RdCfg & (MEMCTRL_SET_RD_SYNC_MSK)) == (MEMCTRL_SET_RD_SYNC_MSK))
      {
         pstNorCfg->eRdMode = NORFLASH_SYNC_MODE;
      }
      else
      {
         pstNorCfg->eRdMode = NORFLASH_NOSYNC_MODE;
      }
      /*
         rd_bl bit */
      switch ((u32RdCfg & (MEMCTRL_SET_RD_BL_MSK)))
      {
         case MEMCTRL_SET_RD_BL_1_BITS:
         {
            pstNorCfg->eRdBursLen = NORFLASH_BURST_LEN_1;
         }
            break;
         case MEMCTRL_SET_RD_BL_4_BITS:
         {
            pstNorCfg->eRdBursLen = NORFLASH_BURST_LEN_4;
         }
            break;
         case MEMCTRL_SET_RD_BL_8_BITS:
         {
            pstNorCfg->eRdBursLen = NORFLASH_BURST_LEN_8;
         }
            break;
         case MEMCTRL_SET_RD_BL_16_BITS:
         {
            pstNorCfg->eRdBursLen = NORFLASH_BURST_LEN_16;
         }
            break;
         case MEMCTRL_SET_RD_BL_32_BITS:
         {
            pstNorCfg->eRdBursLen = NORFLASH_BURST_LEN_32;
         }
            break;
         default:
         {
            /* for all other values use "continuous" */
            pstNorCfg->eRdBursLen = NORFLASH_BURST_LEN_CNTS;
         }
            break;
      }
      /*
         wr_sync bit */
      if ((u32RdCfg & (MEMCTRL_SET_WR_SYNC_MSK)) == (MEMCTRL_SET_WR_SYNC_MSK))
      {
         pstNorCfg->eWrMode = NORFLASH_SYNC_MODE;
      }
      else
      {
         pstNorCfg->eWrMode = NORFLASH_NOSYNC_MODE;
      }
      /*
         wr_bl bit */
      switch ((u32RdCfg & (MEMCTRL_SET_WR_BL_MSK)))
      {
         case MEMCTRL_SET_WR_BL_1_BITS:
         {
            pstNorCfg->eWrBursLen = NORFLASH_BURST_LEN_1;
         }
            break;
         case MEMCTRL_SET_WR_BL_4_BITS:
         {
            pstNorCfg->eWrBursLen = NORFLASH_BURST_LEN_4;
         }
            break;
         case MEMCTRL_SET_WR_BL_8_BITS:
         {
            pstNorCfg->eWrBursLen = NORFLASH_BURST_LEN_8;
         }
            break;
         case MEMCTRL_SET_WR_BL_16_BITS:
         {
            pstNorCfg->eWrBursLen = NORFLASH_BURST_LEN_16;
         }
            break;
         case MEMCTRL_SET_WR_BL_32_BITS:
         {
            pstNorCfg->eWrBursLen = NORFLASH_BURST_LEN_32;
         }
            break;
         default:
         {
            /* for all other values use "continuous" */
            pstNorCfg->eWrBursLen = NORFLASH_BURST_LEN_CNTS;
         }
            break;
      }
      /*
         adv bit */
      if ((u32RdCfg & (MEMCTRL_SET_ADV_MSK)) == (MEMCTRL_SET_ADV_MSK))
      {
         pstNorCfg->eAdrAdvSig = NORFLASH_USE_ADV_SIG;
      }
      else
      {
         pstNorCfg->eAdrAdvSig = NORFLASH_NO_ADV_SIG;
      }
      /*
         bls bit */
      if ((u32RdCfg & (MEMCTRL_SET_BLS_MSK)) == (MEMCTRL_SET_BLS_MSK))
      {
         pstNorCfg->eByteLane = NORFLASH_BYTE_LANE_AS_WEN;
      }
      else
      {
         pstNorCfg->eByteLane = NORFLASH_BYTE_LANE_AS_CS;
      }
      /*
         burst_allign bits */
      switch ((u32RdCfg & (MEMCTRL_SET_BRST_ALIGN_MSK)))
      {
         case MEMCTRL_SET_BRST_CR_ANY_BITS:
         {
            pstNorCfg->eBurstAlign = NORFLASH_BURST_ALGN_CROSS_ANY;
         }
            break;
         case MEMCTRL_SET_BRST_CR_32_BITS:
         {
            pstNorCfg->eBurstAlign = NORFLASH_BURST_ALGN_CROSS_32;
         }
            break;
         case MEMCTRL_SET_BRST_CR_64_BITS:
         {
            pstNorCfg->eBurstAlign = NORFLASH_BURST_ALGN_CROSS_64;
         }
            break;
         case MEMCTRL_SET_BRST_CR_128_BITS:
         {
            pstNorCfg->eBurstAlign = NORFLASH_BURST_ALGN_CROSS_128;
         }
            break;
         default:
         {
            /* other including reserved set to MEMCTRL_SET_BRST_CR_256_BITS */
            pstNorCfg->eBurstAlign = NORFLASH_BURST_ALGN_CROSS_256;
         }
            break;
      }
      /* Check all settings */
      eResult = eNorF_ConfigVerify (pstNorCfg);
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_Initialize (NorFlashCfg_st * pstNorCfg)
{
/***
* MESSAGE: Msg(3:3197) The initialiser for 'eResult' is always modified before
*          being used.
*
* DESC   : To detect that eResult is updated every time within this complex
*          function the initial value NANDFLASH_STATUS_UNKNOWN is used.
****/
   NorFlashStatus_e eResult = NORFLASH_STATUS_UNKNOWN;    /* PRQA S 3197 */

   uint32_t u32TryCnt = 0;                  /* Register-update retry counter */

   /*
      Initialize the NOR memory region Base Address. This init is done already
      in eNorFlash_GetHwConfig() function, but is repeated here in case, if the
      mentioned function would never be called. */
   pstNorCfg->u32NorChipAdr = NORFLASH_BASE_ADDRESS;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      eResult = eNorF_ConfigVerify (pstNorCfg); /* Settings correct? */

      if (eResult == NORFLASH_STATUS_OK)
      {
         uint32_t u32DirCmdVal = 0U;        /* to construct a direct_cmd
                                               register value */
         uint32_t u32MatchData = 0U;        /* Match data Value ? */

         /*
            Bus Width should be fixed to 16-bit for NOR flash always. */
         pstNorCfg->eBusWidth = NORFLASH_BUS_WIDTH_16;

         vNorF_CopyConfigToRegs (pstNorCfg);
         /*
            The configuration is now within set_cycles and set_opmode
            registers. To update the timing within the SMC for a NOR device it
            is required to specify: an UpdateRegs and AXI cmd_type within the
            direct_cmd register. */
         /* Set Match Data Value for UpdateRegs and AXI command */
         /*
            Perform the required sequence of memory accesses, the Last Access
            Containing the Match Data Value. This is memory device specific
            area. Currently nothing to be written -so use:
            MEMCTRL_CMD_TYPE_UPD_REGS_MSK instead of
            MEMCTRL_CMD_TYPE_UPD_REGS_AXI_MSK. */
         u32DirCmdVal = u32DirCmdVal | MEMCTRL_NOR_CHIP_SEL_MSK;
         u32DirCmdVal = u32DirCmdVal | MEMCTRL_CMD_TYPE_UPD_REGS_MSK;
         u32DirCmdVal = u32DirCmdVal | u32MatchData;
         MEMCTRL_DIRECT_CMD = u32DirCmdVal; /* Update registers */
         /*
            Verify the new timings and operation mode: - check for correct
            sram_cycles register - check for correct opmode register. Try to
            Update Cyclec and Opmode registers upto 4 times */
         eResult = NORFLASH_STATUS_UNKNOWN; /* reuse eResult for this loop */
         do
         {
            uint32_t u32Cyc = MEMCTRL_SRAM_CYCLES;

            uint32_t u32Mod = (0x0000FFFFU & MEMCTRL_SRAM_OPMODE);

            if ((u32Cyc == pstNorCfg->u32set_cycles) &&
                (u32Mod == pstNorCfg->u32set_opmode))
            {
               eResult = NORFLASH_STATUS_OK;
            }
            else
            {
               if (u32TryCnt < 4U)
               {
                  MEMCTRL_DIRECT_CMD = u32DirCmdVal;
                  u32TryCnt++;
               }
               else
               {
                  eResult = NORFLASH_STATUS_OPERATION_ERR; /* update failed */
               }
            }
         }
         while (!
                ((eResult == (NORFLASH_STATUS_OK)) ||
                 (eResult == (NORFLASH_STATUS_OPERATION_ERR))));
      }
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_SetBurstLength (NorFlashCfg_st * pstNorCfg,
                                           NorFlashBurstLength_e eWrBrstLen,
                                           NorFlashBurstLength_e eRdBrstLen)
{
   NorFlashStatus_e eResult;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      pstNorCfg->eWrBursLen = eWrBrstLen;
      pstNorCfg->eRdBursLen = eRdBrstLen;
      eResult = NORFLASH_STATUS_OK;
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_SetBusTiming (NorFlashCfg_st * pstNorCfg,
                                         uint32_t u32TurnaroundTime,
                                         uint32_t u32PageCycleTime,
                                         uint32_t u32WriteCycleTime,
                                         uint32_t u32ReadCycleTime)
{
   NorFlashStatus_e eResult;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      if ((pstNorCfg->u32ReadCycleTime < (NORFLASH_RD_CYCLE_MIN)) ||
          (pstNorCfg->u32ReadCycleTime > (NORFLASH_RD_CYCLE_MAX)) ||
          (pstNorCfg->u32WriteCycleTime < (NORFLASH_WR_CYCLE_MIN)) ||
          (pstNorCfg->u32WriteCycleTime > (NORFLASH_WR_CYCLE_MAX)) ||
          (pstNorCfg->u32PageCycleTime < (NORFLASH_PAGE_CYCLE_MIN)) ||
          (pstNorCfg->u32PageCycleTime > (NORFLASH_PAGE_CYCLE_MAX)) ||
          (pstNorCfg->u32TurnaroundTime < (NORFLASH_TURNAROUND_MIN)) ||
          (pstNorCfg->u32TurnaroundTime > (NORFLASH_TURNAROUND_MAX)))
      {
         eResult = NORFLASH_STATUS_CFG_ERR;
      }
      else
      {
         pstNorCfg->u32TurnaroundTime = u32TurnaroundTime;
         pstNorCfg->u32PageCycleTime = u32PageCycleTime;
         pstNorCfg->u32WriteCycleTime = u32WriteCycleTime;
         pstNorCfg->u32ReadCycleTime = u32ReadCycleTime;
         eResult = NORFLASH_STATUS_OK;
      }

   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_SetReadWriteSyncMode (NorFlashCfg_st * pstNorCfg,
                                                 NorFlashRdWrMode_e eWrMode,
                                                 NorFlashRdWrMode_e eRdMode,
                                                 NorFlashBurstAlign_e
                                                 eBurstAlign)
{
   NorFlashStatus_e eResult;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      pstNorCfg->eWrMode = eWrMode;
      pstNorCfg->eRdMode = eRdMode;
      pstNorCfg->eBurstAlign = eBurstAlign;
      eResult = NORFLASH_STATUS_OK;
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_SetSignalsAssertDelays (NorFlashCfg_st * pstNorCfg,
                                                   NorFlashWeTimeCfg_e eWeTime,
                                                   uint32_t u32AssertDelayWeN,
                                                   uint32_t u32AssertDelayOeN)
{
   NorFlashStatus_e eResult;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      if ((pstNorCfg->u32AssertDelayOeN < (NORFLASH_ASSERT_OEN_MIN)) ||
          (pstNorCfg->u32AssertDelayOeN > (NORFLASH_ASSERT_OEN_MAX)) ||
          (pstNorCfg->u32AssertDelayWeN < (NORFLASH_ASSERT_WEN_MIN)) ||
          (pstNorCfg->u32AssertDelayWeN > (NORFLASH_ASSERT_WEN_MAX)))
      {
         eResult = NORFLASH_STATUS_CFG_ERR;
      }
      else
      {
         pstNorCfg->eWeTime = eWeTime;
         pstNorCfg->u32AssertDelayWeN = u32AssertDelayWeN;
         pstNorCfg->u32AssertDelayOeN = u32AssertDelayOeN;
         eResult = NORFLASH_STATUS_OK;
      }
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_SetSignalsConfig (NorFlashCfg_st * pstNorCfg,
                                             NorFlashByteLane_e eByteLane,
                                             NorFlashAdvanceSignal_e eAdrAdvSig,
                                             NorFlashAdvanceSignal_e
                                             eBurstAdrAdvSig)
{
   NorFlashStatus_e eResult;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      pstNorCfg->eByteLane = eByteLane;
      pstNorCfg->eAdrAdvSig = eAdrAdvSig;
      pstNorCfg->eBurstAdrAdvSig = eBurstAdrAdvSig;
      eResult = NORFLASH_STATUS_OK;
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_Reset (const NorFlashCfg_st * const pstNorCfg)
{
   NorFlashStatus_e eResult;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      uint32_t u32NorBase = pstNorCfg->u32NorChipAdr;

      /* NORFLASH_BUS_WIDTH_16 */
      NORFLASH_WORD_ACCESS (u32NorBase, 0x00UL) = (uint16_t)NORFLASH_CMD_RESET;
      eResult = NORFLASH_STATUS_OK;
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_Read16bitWords (const NorFlashCfg_st *
                                           const pstNorCfg, uint32_t u32SrcAdr,
                                           uint16_t pu16DstBuf[],
                                           uint32_t u32BufferLen)
{
   NorFlashStatus_e eResult;

   if (pstNorCfg != TYPES_NULL_PTR)
   {
      uint32_t u32Idx;

      uint16_t *pu16Address;

/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : Thes message is undestood, but the pointer cast is required
*          to maintian properly the position within the 16-bit buffer.
****/
      /* Modify a source pointer */
      pu16Address = (uint16_t *)u32SrcAdr;    /* PRQA S 0306 */
      for (u32Idx = 0U; u32Idx < u32BufferLen; u32Idx++)
      {
         pu16DstBuf[u32Idx] = pu16Address[u32Idx]; /* Destination <- Source */
      }
      eResult = NORFLASH_STATUS_OK;
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
}

/*..........................................................................*/
/* TESTED */
NorFlashStatus_e eNorFlash_Read32bitWords (const NorFlashCfg_st *
                                           const pstNorCfg, uint32_t u32SrcAdr,
                                           uint32_t pu32DstBuf[],
                                           uint32_t u32BufferLen)
{
   NorFlashStatus_e eResult;

   /*
      Assume the MemCtrl is converting a 32-bit access to the appropriate
      number of bus accesses for 8-bit and 16-bit devices? The reading is very
      simple operation: copy a content from the location indicated by the
      source pointer and store it at the destination. */
   if (pstNorCfg != TYPES_NULL_PTR)
   {
      uint32_t u32Idx;

      uint32_t *pu32Address;

/***
* MESSAGE: MISRA-C:2004 Rule 11.3 [I] Cast between a pointer to object and an
*          integral type.
*
* DESC   : Thes message is undestood, but the pointer cast is required
*          to maintian properly the position within the buffer.
****/
      /* Modify a source pointer */
      pu32Address = (uint32_t *)u32SrcAdr;    /* PRQA S 0306 */
      for (u32Idx = 0U; u32Idx < u32BufferLen; u32Idx++)
      {
         pu32DstBuf[u32Idx] = pu32Address[u32Idx]; /* Destination <- Source */
      }
      eResult = NORFLASH_STATUS_OK;
   }
   else
   {
      eResult = NORFLASH_STATUS_PTR_ERR;
   }
   return eResult;
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

