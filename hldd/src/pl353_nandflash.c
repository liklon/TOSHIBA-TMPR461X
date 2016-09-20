/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   DESCRIPTION : IPL NAND Flash Program module's source/definition file.
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : System
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/11 13:11:59 $
*   TAG         : $Name: HLDD_1_1 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/

#include "captypes.h"                       /* Cap-Bt Data types header */
#include "pl353memctrl.h"                   /* Board specific defines */
#include "pl353nand.h"                      /* Driver's API header file */
#include "pl353_nandflash.h"
#include "core.h"

#define IPLPRG_MAX_BLOCKS   (1024)

uint32_t au32BlocksToErase[IPLPRG_MAX_BLOCKS];

/*..........................................................................*/

/* **************** Local Functions Declarations **************** */

/*****************************************************************************
* Function sends a NAND Command over the AXI bus, with an address parameter
* calculated based on the block number.
*****************************************************************************/
static void vNF_CmdPhaseAxiBlockSelect (const NandFlashCfg_st *
                                        const pstNandCfg, uint32_t u32BlockNo,
                                        uint32_t u32StartCommand,
                                        uint32_t u32EndCmdValid,
                                        uint32_t u32EndCommand);

/*****************************************************************************
* Function writes multiple data over the AXI bus, using AXI Data Phase.
*****************************************************************************/
static void vNF_DataPhaseAxiWrMultiBytes (const NandFlashCfg_st *
                                          const pstNandCfg,
                                          uint32_t u32BufferLen,
                                          const uint8_t pu8SrcBuf[],
                                          uint32_t u32EccLast,
                                          const uint8_t pu8ExtrBuf[]);

/*****************************************************************************
* Function writes multiple 16-bit data over the AXI bus, using AXI Data Phase.
*****************************************************************************/
static void vNF_DataPhaseAxiWrMulti16Bits (const NandFlashCfg_st *
                                           const pstNandCfg,
                                           uint32_t u32BufferLen,
                                           const uint16_t pu16SrcBuf[],
                                           uint32_t u32EccLast,
                                           const uint16_t pu16ExtrBuf[]);

/****************************************************************************/

/*..........................................................................*/

/* ***************** Functions Definitions **************** */

/*..........................................................................*/
/* TESTED */
static void vNF_CmdPhaseAxiBlockSelect (const NandFlashCfg_st *
                                        const pstNandCfg, uint32_t u32BlockNo,
                                        uint32_t u32StartCommand,
                                        uint32_t u32EndCmdValid,
                                        uint32_t u32EndCommand)
{
   uint32_t u32CmdPh;                       /* to be send within a cmd phase */

   uint32_t *pu32CmdPhDest;

   uint32_t u32Data;

   NANDFLASH_CLEAR_READY_IRQ ();
   /*
      WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already.

      u32NoOfAddrCycles is most probably NOT the same as MEMCTRL_BASE! This
      needs to be clarified!

      u32NoOfAddrCycles is DEVICE-dependent and can be calculated based on the
      total size of the device (page size, number of pages in a block and
      number of blocks). Use 3 address cycles for ERASE. */
   u32CmdPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32CmdPh = (u32CmdPh | (3U << (MEMCTRL_AXI_ADDRES_CYCLES_SFT)));
   u32CmdPh = (u32CmdPh | (u32EndCmdValid << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
   u32CmdPh =
      (u32CmdPh | (NF_PAR_CMD_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32CmdPh = (u32CmdPh | (u32EndCommand << (MEMCTRL_AXI_END_COMMAND_SFT)));
   u32CmdPh = (u32CmdPh | (u32StartCommand << (MEMCTRL_AXI_START_COMMAND_SFT)));
   pu32CmdPhDest = (uint32_t *)u32CmdPh;

   /* Construct Command-Phase Data Re-formatted address */
   u32Data = (0x00U);                       /* Page is ignored / not shifted */
   u32Data = u32Data | ((u32BlockNo) << 6); /* Block is shifted by 6 bits */
   *pu32CmdPhDest = u32Data;                /* write it */
   NF_uSecWait (3);
}

/*..........................................................................*/
/* TESTED on silicon */
static void vNF_DataPhaseAxiWrMultiBytes (const NandFlashCfg_st *
                                          const pstNandCfg,
                                          uint32_t u32BufferLen,
                                          const uint8_t pu8SrcBuf[],
                                          uint32_t u32EccLast,
                                          const uint8_t pu8ExtrBuf[])
{
   uint32_t u32DatPh;                       /* Word to be send within a command
                                               phase */
   uint32_t u32Idx;

   uint32_t u32TmpLen;

   uint32_t *pu32WrData;   

   /*
      WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already... */
   u32DatPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32DatPh = (u32DatPh | (NF_PAR_CS_ACTIV << (MEMCTRL_AXI_CLEAR_CS_SFT)));
   u32DatPh =
      (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32DatPh = (u32DatPh | (NF_PAR_ECC_CALC << (MEMCTRL_AXI_ECC_LAST_SFT)));

   u32TmpLen = (u32BufferLen >> 2);         /* 4 bytes per access */

   pu32WrData = (uint32_t *)pu8SrcBuf;      /* Write to device */

   if (pstNandCfg->eExtraBlockCfg == NANDFLASH_EXTRA_BLOCK_DISABLED)
   {
      /* Without Extra Block simply write Page data */
      for (u32Idx = 0U; u32Idx < (u32TmpLen - 2U); u32Idx+=2)
      {
         /* Write to device */
         vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
         __DSB();
      }
      /* Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      /* check if END command is required for programming? */
      u32DatPh =
         (u32DatPh | (NF_PAR_END_VALID << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh =
         (u32DatPh |
          (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));

      vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
      __DSB();
   }
   else
   {
      uint32_t u32ExtrBufLen;

      /* With Extra Block write Page data ... */
      for (u32Idx = 0U; u32Idx < u32TmpLen; u32Idx+=2)
      {
        vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
        __DSB();
      }
      /* ... and continue with Extra data */
      switch (pstNandCfg->eExtraBlockCfg)
      {
            /* find out the extra buffer size */
         case NANDFLASH_EXTRA_BLOCK_32_BYTES:
         {
            u32ExtrBufLen = (32U >> 2);     /* 4 bytes per access */
         }
            break;
         case NANDFLASH_EXTRA_BLOCK_16_BYTES:
         {
            u32ExtrBufLen = (16U >> 2);     /* 4 bytes per access */
         }
         break;
         default:                          /* NANDFLASH_EXTRA_BLOCK_8_BYTES */
         {
             u32ExtrBufLen = (8U >> 2);      /* 4 bytes per access */
         }
            break;
      }
      pu32WrData = (uint32_t *)pu8ExtrBuf;  /* Write to device */

      for (u32Idx = 0U; u32Idx < (u32ExtrBufLen - 2); u32Idx+=2)
      {
         vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
         __DSB();
      }
      /* Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      /* check if END command is required for programming? */
      u32DatPh =
         (u32DatPh | (NF_PAR_END_VALID << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh =
         (u32DatPh |
          (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));
      vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx],pu32WrData[u32Idx+1]);
      
      __DSB();
   }
}


/*..........................................................................*/
/* TESTED on FPGA */
#if 0
static void vNF_DataPhaseAxiWrMultiBytes_FPGA (const NandFlashCfg_st *
                                          const pstNandCfg,
                                          uint32_t u32BufferLen,
                                          const uint8_t pu8SrcBuf[],
                                          uint32_t u32EccLast,
                                          const uint8_t pu8ExtrBuf[])
{
   uint32_t u32DatPh;                       /* Word to be send within a command
                                               phase */
   uint32_t *pu32CmdPhDest;

   uint32_t u32Idx;

   uint32_t u32TmpLen;

   uint32_t *pu32WrData;

   /*
      WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already... */
   u32DatPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32DatPh = (u32DatPh | (NF_PAR_CS_ACTIV << (MEMCTRL_AXI_CLEAR_CS_SFT)));
   u32DatPh =
      (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32DatPh = (u32DatPh | (NF_PAR_ECC_CALC << (MEMCTRL_AXI_ECC_LAST_SFT)));
   pu32CmdPhDest = (uint32_t *)u32DatPh;

   u32TmpLen = (u32BufferLen >> 2);         /* 4 bytes per access */

   pu32WrData = (uint32_t *)pu8SrcBuf;      /* Write to device */

   if (pstNandCfg->eExtraBlockCfg == NANDFLASH_EXTRA_BLOCK_DISABLED)
   {
      /* Without Extra Block simply write Page data */
      for (u32Idx = 0U; u32Idx < (u32TmpLen - 1U); u32Idx++)
      {
         *pu32CmdPhDest = pu32WrData[u32Idx]; /* Write to device */
      }
      /* Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      /* check if END command is required for programming? */
      u32DatPh =
         (u32DatPh | (NF_PAR_END_VALID << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh =
         (u32DatPh |
          (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));

      pu32CmdPhDest = (uint32_t *)u32DatPh;
      *pu32CmdPhDest = pu32WrData[u32Idx];  /* Last Write to device */
   }
   else
   {
      uint32_t u32ExtrBufLen;

      /* With Extra Block write Page data ... */
      for (u32Idx = 0U; u32Idx < u32TmpLen; u32Idx++)
      {
         *pu32CmdPhDest = pu32WrData[u32Idx]; /* Write to device */
      }
      /* ... and continue with Extra data */
      switch (pstNandCfg->eExtraBlockCfg)
      {
            /* find out the extra buffer size */
         case NANDFLASH_EXTRA_BLOCK_32_BYTES:
         {
            u32ExtrBufLen = (32U >> 2);     /* 4 bytes per access */
         }
            break;
         case NANDFLASH_EXTRA_BLOCK_16_BYTES:
         {
            u32ExtrBufLen = (16U >> 2);     /* 4 bytes per access */
         }
            break;
         default:
         {
            u32ExtrBufLen = (8U >> 2);      /* 4 bytes per access */
         }
         break;
         
      }
      pu32WrData = (uint32_t *)pu8ExtrBuf;  /* Write to device */
      for (u32Idx = 0U; u32Idx < (u32ExtrBufLen - 1); u32Idx++)
      {
         *pu32CmdPhDest = pu32WrData[u32Idx]; /* Write to device */
      }
      /* Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      /* check if END command is required for programming? */
      u32DatPh =
         (u32DatPh | (NF_PAR_END_VALID << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh =
         (u32DatPh |
          (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));

      pu32CmdPhDest = (uint32_t *)u32DatPh;
      *pu32CmdPhDest = pu32WrData[u32Idx];  /* Last Write to device */
   }
}
#endif

/*..........................................................................*/
/* TESTED on silicon */
static void vNF_DataPhaseAxiWrMulti16Bits (const NandFlashCfg_st *
                                           const pstNandCfg,
                                           uint32_t u32BufferLen,
                                           const uint16_t pu16SrcBuf[],
                                           uint32_t u32EccLast,
                                           const uint16_t pu16ExtrBuf[])
{
   uint32_t u32DatPh;                       /* Word to be send within a command
                                               phase */
   uint32_t u32Idx;

   uint32_t u32TmpLen;

   uint32_t *pu32WrData;


   /*
      WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already... */
   u32DatPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32DatPh = (u32DatPh | (NF_PAR_CS_ACTIV << (MEMCTRL_AXI_CLEAR_CS_SFT)));

   u32DatPh =
      (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32DatPh = (u32DatPh | (NF_PAR_ECC_CALC << (MEMCTRL_AXI_ECC_LAST_SFT)));

   u32TmpLen = (u32BufferLen >> 1);         /* 2 words per access */

   pu32WrData = (uint32_t *)pu16SrcBuf;     /* Write to device */

   if (pstNandCfg->eExtraBlockCfg == NANDFLASH_EXTRA_BLOCK_DISABLED)
   {
      /* Without Extra Block simply write Page data */
      for (u32Idx = 0U; u32Idx < (u32TmpLen - 2U); u32Idx+=2)
      {
         vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
         __DSB();
      }
      /*
         Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      /* check if END command is required for programming */
      u32DatPh =
         (u32DatPh | (NF_PAR_END_VALID << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh =
         (u32DatPh |
          (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));

      vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
      __DSB();
   }
   else
   {
      uint32_t u32ExtrBufLen;

      /* With Extra Block write Page data ... */
      for (u32Idx = 0U; u32Idx < u32TmpLen; u32Idx+=2)
      {
         vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
      }
      /* ... and continue with Extra data */
      switch (pstNandCfg->eExtraBlockCfg)
      {
            /* find out the extra buffer size */
         case NANDFLASH_EXTRA_BLOCK_32_BYTES:
         {
            u32ExtrBufLen = (32U >> 2);     /* 4 bytes per access */
         }
            break;
         case NANDFLASH_EXTRA_BLOCK_16_BYTES:
         {
            u32ExtrBufLen = (16U >> 2);     /* 4 bytes per access */
         }
            break;
        default: 
         {
            u32ExtrBufLen = (8U >> 2);      /* 4 bytes per access */
         }
         break;         
      }
      pu32WrData = (uint32_t *)pu16ExtrBuf; /* Write to device */
      for (u32Idx = 0U; u32Idx < (u32ExtrBufLen - 2); u32Idx+=2)
      {
        vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
        __DSB();
      }
      /* Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      /* check if END command is required for programming? */
      u32DatPh =
         (u32DatPh | (NF_PAR_END_VALID << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh =
         (u32DatPh |
          (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));

      /* Last Write to device */
      vNF_AddrBrstWr(u32DatPh, pu32WrData[u32Idx], pu32WrData[u32Idx+1]);
      __DSB();
   }
}

/*..........................................................................*/
/* TESTED on FPGA */
#if 0
static void vNF_DataPhaseAxiWrMulti16Bits_FPGA (const NandFlashCfg_st *
                                           const pstNandCfg,
                                           uint32_t u32BufferLen,
                                           const uint16_t pu16SrcBuf[],
                                           uint32_t u32EccLast,
                                           const uint16_t pu16ExtrBuf[])
{
   uint32_t u32DatPh;                       /* Word to be send within a command
                                               phase */
   uint32_t *pu32CmdPhDest;

   uint32_t u32Idx;

   uint32_t u32TmpLen;

   uint32_t *pu32WrData;

   /*
      WARNINGS: u32NandChipAddress should be stored in cfg structure shifted
      already... */
   u32DatPh = ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
   u32DatPh = (u32DatPh | (NF_PAR_CS_ACTIV << (MEMCTRL_AXI_CLEAR_CS_SFT)));
   u32DatPh =
      (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
   u32DatPh = (u32DatPh | (NF_PAR_ECC_CALC << (MEMCTRL_AXI_ECC_LAST_SFT)));
   pu32CmdPhDest = (uint32_t *)u32DatPh;

   u32TmpLen = (u32BufferLen >> 1);         /* 2 x 16bit words per access */

   pu32WrData = (uint32_t *)pu16SrcBuf;     /* Write to device */

   if (pstNandCfg->eExtraBlockCfg == NANDFLASH_EXTRA_BLOCK_DISABLED)
   {
      /* Without Extra Block simply write Page data */
      for (u32Idx = 0U; u32Idx < (u32TmpLen - 1U); u32Idx++)
      {
         *pu32CmdPhDest = pu32WrData[u32Idx]; /* Write to device */
      }
      /*
         Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      /* check if END command is required for programming */
      u32DatPh =
         (u32DatPh | (NF_PAR_END_VALID << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh =
         (u32DatPh |
          (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));

      pu32CmdPhDest = (uint32_t *)u32DatPh;
      *pu32CmdPhDest = pu32WrData[u32Idx];  /* Last Write to device */
   }
   else
   {
      uint32_t u32ExtrBufLen;

      /* With Extra Block write Page data ... */
      for (u32Idx = 0U; u32Idx < u32TmpLen; u32Idx++)
      {
         *pu32CmdPhDest = pu32WrData[u32Idx]; /* Write to device */
      }
      /* ... and continue with Extra data */
      switch (pstNandCfg->eExtraBlockCfg)
      {
            /* find out the extra buffer size */
         case NANDFLASH_EXTRA_BLOCK_32_BYTES:
         {
            u32ExtrBufLen = (32U >> 2);     /* 4 bytes per access */
         }
            break;
         case NANDFLASH_EXTRA_BLOCK_16_BYTES:
         {
            u32ExtrBufLen = (16U >> 2);     /* 4 bytes per access */
         }
         break;
         default:              
         {
            u32ExtrBufLen = (8U >> 2);      /* 4 bytes per access */
         }
         break;         
      }
      pu32WrData = (uint32_t *)pu16ExtrBuf; /* Write to device */
      for (u32Idx = 0U; u32Idx < (u32ExtrBufLen - 1); u32Idx++)
      {
         *pu32CmdPhDest = pu32WrData[u32Idx]; /* Write to device */
      }
      /* Chip select must be finished in the last transfer. ECC calculation End
         depends on the u32EccLast parameter value. */
      u32DatPh =
         ((pstNandCfg->u32NandChipAddress) & (MEMCTRL_AXI_BASE_ADDR_MASK));
      u32DatPh = (u32DatPh | (NF_PAR_CS_CLEAR << (MEMCTRL_AXI_CLEAR_CS_SFT)));
      /* check if END command is required for programming? */
      u32DatPh =
         (u32DatPh | (NF_PAR_END_VALID << (MEMCTRL_AXI_END_CMD_VALID_SFT)));
      u32DatPh =
         (u32DatPh | (NF_PAR_DATA_PHASE << (MEMCTRL_AXI_CMD_DATA_SELECT_SFT)));
      u32DatPh =
         (u32DatPh |
          (NANDFLASH_CMD_PROGRAM_END << (MEMCTRL_AXI_END_COMMAND_SFT)));
      u32DatPh = (u32DatPh | (u32EccLast << (MEMCTRL_AXI_ECC_LAST_SFT)));

      pu32CmdPhDest = (uint32_t *)u32DatPh;
      *pu32CmdPhDest = pu32WrData[u32Idx];  /* Last Write to device */
   }
}
#endif

/*..........................................................................*/

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eIplPrgNand_Configure (NandFlashCfg_st * pstCfg,
                                         NandFlashDeviceType_e eDevice,
                                         NandFlashExtraBlock_e eExtraBlkCfg)
{
   NandFlashStatus_e eNfFinalRslt = NANDFLASH_STATUS_UNKNOWN;

   NandFlashStatus_e eNfRslt0 = NANDFLASH_STATUS_UNKNOWN;

   NandFlashStatus_e eNfRslt1 = NANDFLASH_STATUS_UNKNOWN;

   NandFlashStatus_e eNfRslt2 = NANDFLASH_STATUS_UNKNOWN;

   NandFlashStatus_e eNfRslt3 = NANDFLASH_STATUS_UNKNOWN;

   NandFlashStatus_e eNfRslt4 = NANDFLASH_STATUS_UNKNOWN;


   /* Load HW settings from registers to config structure. */
   eNfRslt0 = eNandFlash_GetHwConfig (pstCfg);

   /* eExtraBlkCfg selection comes from boot options / XLS file */
   eNfRslt1 = eNandFlash_SetExtraBlock (pstCfg, eExtraBlkCfg);
   /* Modify to max. values: u32IdRdTime u32StatusRdTime u32WriteCycleTime
      u32ReadCycleTime */
   /* Modify to max. values: u32BusyCycleToReN u32DeAssertDelayWeN
      u32AssertDelayReN */

 /* Set timing parameters */
    eNfRslt2 = eNandFlash_SetBusTiming(pstCfg,
                                         0x2U,  /* NAND_ID_RD_TIME */
                                         0x2U,   /* NAND_STATUS_RD_TIME */
                                         0x7U,   /* write CycTime. was 0x7U */
                                         0x7U);  /* read CycTime. was 0x7U */
    /* Set cycle assert delays */
    eNfRslt3 = eNandFlash_SetCycleAssertDelays (pstCfg,
                                                 0x2U,  /* NAND_BUSY_CYCLE_TO_R_EN */
                                                 0x5U,   /* NAND_DEASSERT_DELAY_W_EN */
                                                 0x3U);   /* NAND_ASSERT_DELAY_R_EN */

   eNfRslt4 = eNandFlash_Initialize (pstCfg, eDevice);

   if ((eNfRslt0 == NANDFLASH_STATUS_OK) && (eNfRslt1 == NANDFLASH_STATUS_OK) &&
       (eNfRslt2 == NANDFLASH_STATUS_OK) && (eNfRslt3 == NANDFLASH_STATUS_OK) &&
       (eNfRslt4 == NANDFLASH_STATUS_OK))
   {
      eNfFinalRslt = NANDFLASH_STATUS_OK;
   }
   else
   {
      eNfFinalRslt = NANDFLASH_STATUS_CFG_ERR;
   }

   return eNfFinalRslt;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eIplPrgNand_SelectErase (NandFlashCfg_st * pstNandCfg,
                                           uint32_t u32HdrStart,
                                           uint32_t u32HdrSize,
                                           uint32_t u32BlStart,
                                           uint32_t u32BlSize,
                                           uint32_t u32EpStart,
                                           uint32_t u32EpSize)
{
   NandFlashStatus_e eErRes = NANDFLASH_STATUS_UNKNOWN;

   uint32_t u32BlockBytes = 64;

   uint32_t u32ErBlock_Hdr;

   uint32_t u32ErBlockNo_BlStart;

   uint32_t u32ErBlockNo_BlEnd;

   uint32_t u32ErBlockNo_EpStart;

   uint32_t u32ErBlockNo_EpEnd;

   uint32_t u32TabIdx = 0;

   uint32_t u32BIdx = 0;

   uint32_t u32BlSizeBytes = (u32BlSize << 2);

   uint32_t u32EpSizeBytes = (u32EpSize << 2);

   /*
      To Erase blocks before programming them - it is required to identify
      their numbers. Since all adresses are absolute - it is required to
      calculate only an offset from the NAND Base Address i.e. subtract from
      each address the value of the Base Addesss. */
   u32BlockBytes = (pstNandCfg->u32BlkSize) * (pstNandCfg->u32PageSize);
   u32BlStart = (u32BlStart - u32HdrStart); /* offset only */
   u32EpStart = (u32EpStart - u32HdrStart); /* offset only */
   u32HdrStart = 0;                         /* offset == 0 */
   u32ErBlock_Hdr = 0;                      /* Header is always at block 0 */

   /* Block number, where BL code starts */
   u32ErBlockNo_BlStart = (u32BlStart / u32BlockBytes);
   /* Block number, where BL code ends */
   u32ErBlockNo_BlEnd = ((u32BlStart + u32BlSizeBytes - 1) / u32BlockBytes);

   /* Block number, where EP code starts */
   u32ErBlockNo_EpStart = (u32EpStart / u32BlockBytes);
   /* Block number, where EP code ends */
   u32ErBlockNo_EpEnd = ((u32EpStart + u32EpSizeBytes - 1) / u32BlockBytes);

   /* Always erase block 0 */
   au32BlocksToErase[u32TabIdx++] = u32ErBlock_Hdr;

   /* Check, if all fits within Block 0 */
   if ((u32ErBlock_Hdr != u32ErBlockNo_BlStart) ||
       (u32ErBlock_Hdr != u32ErBlockNo_BlEnd) ||
       (u32ErBlock_Hdr != u32ErBlockNo_EpStart) ||
       (u32ErBlock_Hdr != u32ErBlockNo_EpEnd))
   {
      /* Identify Boot Loader Blocks to ERASE */
      for (u32BIdx = u32ErBlockNo_BlStart; u32BIdx <= u32ErBlockNo_BlEnd;
           u32BIdx++)
      {
         /* Check, if not on the list already */
         if (u32BIdx != u32ErBlock_Hdr)
         {
            au32BlocksToErase[u32TabIdx++] = u32BIdx;
         }
      }
      /* Identify Emergency Program Blocks to ERASE */
      for (u32BIdx = u32ErBlockNo_EpStart; u32BIdx <= u32ErBlockNo_EpEnd;
           u32BIdx++)
      {
         /* To avoid double-erasing of common blocks: check, if such are not
            already on the list */
         if ((u32BIdx != u32ErBlock_Hdr) &&
             ((u32BIdx < u32ErBlockNo_BlStart) ||
              (u32BIdx > u32ErBlockNo_BlEnd)))
         {
            au32BlocksToErase[u32TabIdx++] = u32BIdx;
         }
      }
   }
   else
   {
      /* Everything fits within block 0 */
   }
   /* Now Erase all blocks from the list */
   for (u32BIdx = u32ErBlock_Hdr; u32BIdx < u32TabIdx; u32BIdx++)
   {

      eErRes = eNandFlash_EraseBlock (pstNandCfg, au32BlocksToErase[u32BIdx]);
      if (eErRes != NANDFLASH_STATUS_OK)
      {
         /* Exit loop immediately, in case of erase problem */
         break;
      }
   }
   return eErRes;
}

/***************************************************************************/
void eNandUtil_FindBlockPageOffset (NandFlashCfg_st * pstCfg,
                                    uint32_t pu32NandAddr,
                                    uint32_t* pu32Block,
                                    uint32_t* pu32Page,
                                    uint32_t* pu32PageOffset)
{
   uint32_t u32BlockBytes;
   uint32_t u32ByteBlkOffset;
   uint32_t u32Block;
   uint32_t u32Page;
   uint32_t u32PageOffset;


   /* Calculate number of bytes within 1 block */
   u32BlockBytes = (pstCfg->u32BlkSize) * (pstCfg->u32PageSize);

   /* Block number where the addr is pointing to */
   u32Block = (pu32NandAddr / u32BlockBytes);

   /* Address offset from the beginning of the block */
   u32ByteBlkOffset = (pu32NandAddr % u32BlockBytes);

   /* Page number, in which the addr is pointing to */
   u32Page = (u32ByteBlkOffset / (pstCfg->u32PageSize));

   /* Address offset from the beginning of the page */
   u32PageOffset = (u32ByteBlkOffset % (pstCfg->u32PageSize));
    /*
    printf("Blk %d, StrPg %d, PgOff %d\n", u32Block, u32Page, u32PageOffset);
    */
   *pu32Block = u32Block;
   *pu32Page = u32Page;
   *pu32PageOffset = u32PageOffset;
}


/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandUtil_AutoErase (NandFlashCfg_st * pstNandCfg,
                                       uint32_t u32StartAddress,
                                       uint32_t u32EndAddress,
                                       uint32_t* pu32ErasedBlocks)
{
   NandFlashStatus_e eErRes = NANDFLASH_STATUS_UNKNOWN;

   uint32_t u32BlockBytes = 64;

   uint32_t u32StartBlock;

   uint32_t u32EndBlock;

   uint32_t u32BIdx = 0;

   /* This function assumes that all NAND device is located at offset 0 */
   u32BlockBytes = (pstNandCfg->u32BlkSize) * (pstNandCfg->u32PageSize);

   /* Block number, where image starts */
   u32StartBlock = (u32StartAddress / u32BlockBytes);
   /* Block number, where image ends */
   u32EndBlock = (u32EndAddress / u32BlockBytes);

   /* ERASE blocks */
   *pu32ErasedBlocks = 0;
   for (u32BIdx = u32StartBlock; u32BIdx <= u32EndBlock;  u32BIdx++)
   {
      eErRes = eNandFlash_EraseBlock (pstNandCfg, u32BIdx);
      if (eErRes != NANDFLASH_STATUS_OK)
      {
         /* Exit loop immediately, in case of erase problem */
         /*
         printf("ERROR %d during ERASE of block %d\n", eErRes, u32BIdx);
         */
         break;
      }
      else
      {
        (*pu32ErasedBlocks)++; /* increment number of erased blocks */
      }
   }
   return eErRes;
}

/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_EraseBlock (NandFlashCfg_st * pstNandCfg,
                                         uint32_t u32BlockNumber)
{
   NandFlashStatus_e eResult;

   if (pstNandCfg == TYPES_NULL_PTR)
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      vNF_CmdPhaseAxiBlockSelect (pstNandCfg, u32BlockNumber,
                                  NANDFLASH_CMD_ERASE_START, NF_PAR_END_VALID,
                                  NANDFLASH_CMD_ERASE_END);

      eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
   }
   return eResult;
}


/*..........................................................................*/
/* TESTED */
NandFlashStatus_e eNandFlash_ProgramPageBytes (NandFlashCfg_st * pstNandCfg,
                                               uint32_t u32BlockNumber,
                                               uint32_t u32PageNumber,
                                               uint8_t pu8SrcBuf[],
                                               uint8_t pu8ExtrBuf[])
{
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;

   if ((pstNandCfg == TYPES_NULL_PTR))
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      if ((pstNandCfg->eBusWidth == NANDFLASH_BUS_WIDTH_8) &&
          (u32PageNumber < pstNandCfg->u32BlkSize))
      {
         uint32_t u32BufferLen = (uint32_t)(pstNandCfg->u32PageSize);

         /* ECC handled differently for devices with internal ECC */
         if (pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_VENDOR1_ECC)
         {
            vNF_CmdPhaseAxiCplx (pstNandCfg, 0x0U, u32PageNumber,
                                 u32BlockNumber, NANDFLASH_CMD_PROGRAM_START,
                                 NF_PAR_NO_END_CMD, NF_PAR_IGNORE);
            /*
               NF_PAR_ECC_LAST parameter means that the last read-transfer will
               close the HW ECC calculation process. */
            vNF_DataPhaseAxiWrMultiBytes (pstNandCfg, u32BufferLen, pu8SrcBuf,
                                          NF_PAR_IGNORE, pu8ExtrBuf);

            /* Spec. defines the wait tWB time: WE# HIGH to busy tWB= 100ns
               before the BUSY status is read. Normally it should be handled by
               the Memory Controller; confirm it! With Internal ECC wait
               tPROG_ECC ==600 us */
            eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
            if (eResult == NANDFLASH_STATUS_OK)
            {
               /* Check device's status (0 == ECC OK) */
               eResult = eNF_GetDeviceStatus (pstNandCfg);
               /* ****** FINAL eResult should be available here ****** */
            }
            /* ****** FINAL eResult should be available here ****** */
         }
         else                               /* 1-bit ECC: ONFI devices */
         {
            /* Prepare ECC HW before writing data */
            eResult = eNF_EccConfigure (pstNandCfg);

            if (eResult == NANDFLASH_STATUS_OK)
            {
               /* AXI write Command Phase followed by the Page Data Phase */
               vNF_CmdPhaseAxiCplx (pstNandCfg, 0U, u32PageNumber,
                                    u32BlockNumber, NANDFLASH_CMD_PROGRAM_START,
                                    NF_PAR_NO_END_CMD, NF_PAR_IGNORE);
               /* DATA Phase (Extra Block is forbidden in this case) */
               vNF_DataPhaseAxiWrMultiBytes (pstNandCfg, u32BufferLen,
                                             pu8SrcBuf, NF_PAR_ECC_LAST,
                                             pu8ExtrBuf);
               /* Wait until ECC is IDLE */
               eResult = eNF_EccWaitIdle (pstNandCfg);
               if (eResult == NANDFLASH_STATUS_OK)
               {
                  uint32_t u32Status;

                  /* Check Last ECC Status */
                  u32Status = MEMCTRL_ECC_STATUS;
                  u32Status = (u32Status & MEMCTRL_ECC_LAST_STATUS_MSK);
                  if (u32Status == MEMCTRL_ECC_LAST_STATUS_SUCCESS_BITS)
                  {
                     /* Spec. defines the wait tWB time: WE# HIGH to busy tWB=
                        100ns before the BUSY status is read. Normally it
                        should be handled by the Memory Controller; confirm it!
                        With Internal ECC wait tPROG_ECC ==600 us */
                     eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
                     if (eResult == NANDFLASH_STATUS_OK)
                     {
                        /*
                           Read the device's status word */
                        eResult = eNF_GetDeviceStatus (pstNandCfg);
                        /* ****** FINAL eResult should be available here ******
                         */
                     }
                  }
                  else
                  {
                     /* For details ecc_last_status should be analyzed */
                     eResult = NANDFLASH_STATUS_ECC_ERR;
                  }
               }
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
/* TESTED */
NandFlashStatus_e eNandFlash_ProgramPage16bitWords (NandFlashCfg_st *
                                                    pstNandCfg,
                                                    uint32_t u32BlockNumber,
                                                    uint32_t u32PageNumber,
                                                    uint16_t pu16SrcBuf[],
                                                    uint16_t pu16ExtrBuf[])
{
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;

   if ((pstNandCfg == TYPES_NULL_PTR))
   {
      eResult = NANDFLASH_STATUS_PTR_ERR;
   }
   else
   {
      if ((pstNandCfg->eBusWidth == NANDFLASH_BUS_WIDTH_16) &&
          (u32PageNumber < pstNandCfg->u32BlkSize))
      {
         /* number of 16-bit words in a buffer */
         uint32_t u32BufferLen = ((pstNandCfg->u32PageSize) >> 1);

         /*
            ECC handled differently for devices with internal ECC */
         if (pstNandCfg->eDeviceType == NANDFLASH_DEVICE_ONFI_VENDOR1_ECC)
         {
            vNF_CmdPhaseAxiCplx (pstNandCfg, 0x0U, u32PageNumber,
                                 u32BlockNumber, NANDFLASH_CMD_PROGRAM_START,
                                 NF_PAR_NO_END_CMD, NF_PAR_IGNORE);
            /*
               NF_PAR_ECC_LAST parameter means that the last read-transfer will
               close the HW ECC calculation process. */
            vNF_DataPhaseAxiWrMulti16Bits (pstNandCfg, u32BufferLen, pu16SrcBuf,
                                           NF_PAR_IGNORE, pu16ExtrBuf);
            /* Spec. defines the wait tWB time: WE# HIGH to busy tWB= 100ns
               before the BUSY status is read. Normally it should be handled by
               the Memory Controller; confirm it! With Internal ECC wait
               tPROG_ECC ==600 us */
            eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
            if (eResult == NANDFLASH_STATUS_OK)
            {
               /*
                  Read the device's status word */
               eResult = eNF_GetDeviceStatus (pstNandCfg);
               /* ****** FINAL eResult should be available here ****** */
            }
            /* ****** FINAL eResult should be available here ****** */
         }
         else                               /* 1-bit ECC: ONFI devices */
         {
            /* Prepare ECC HW before writing data */
            eResult = eNF_EccConfigure (pstNandCfg);

            if (eResult == NANDFLASH_STATUS_OK)
            {
               /* AXI write Command Phase followed by the Page Data Phase */
               vNF_CmdPhaseAxiCplx (pstNandCfg, 0U, u32PageNumber,
                                    u32BlockNumber, NANDFLASH_CMD_PROGRAM_START,
                                    NF_PAR_NO_END_CMD, NF_PAR_IGNORE);
               /* DATA Phase (Extra Block is forbidden in this case) */
               vNF_DataPhaseAxiWrMulti16Bits (pstNandCfg, u32BufferLen,
                                              pu16SrcBuf, NF_PAR_ECC_LAST,
                                              pu16ExtrBuf);
               /* Wait until ECC is IDLE */
               eResult = eNF_EccWaitIdle (pstNandCfg);
               if (eResult == NANDFLASH_STATUS_OK)
               {
                  uint32_t u32Status;

                  /* Check Last ECC Status */
                  u32Status = MEMCTRL_ECC_STATUS;
                  u32Status = (u32Status & MEMCTRL_ECC_LAST_STATUS_MSK);
                  if (u32Status == MEMCTRL_ECC_LAST_STATUS_SUCCESS_BITS)
                  {
                     /* Spec. defines the wait tWB time: WE# HIGH to busy tWB=
                        100ns before the BUSY status is read. Normally it
                        should be handled by the Memory Controller; confirm it!
                        With Internal ECC wait tPROG_ECC ==600 us */
                     eResult = eNandFlash_WaitDeviceReady (pstNandCfg);
                     if (eResult == NANDFLASH_STATUS_OK)
                     {
                        /*
                           Read the device's status word */
                        eResult = eNF_GetDeviceStatus (pstNandCfg);
                        /* ****** FINAL eResult should be available here ******
                         */
                     }
                  }
                  else
                  {
                     /* For details ecc_last_status should be analyzed */
                     eResult = NANDFLASH_STATUS_ECC_ERR;
                  }
               }
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
/* TESTED: */
NandFlashStatus_e eNandFlash_ProgramPages (NandFlashCfg_st * pstNandCfg,
                                           uint32_t u32BlockNumber,
                                           uint32_t u32StartPage,
                                           uint32_t u32NoOfPages,
                                           uint32_t pu32SrcBuf[],
                                           uint32_t pu32ExtrBuf[])
{
   NandFlashStatus_e eResult = NANDFLASH_STATUS_UNKNOWN;

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
         uint32_t u32Idx = u32StartPage;

         uint32_t u32SrcAddr = (uint32_t)pu32SrcBuf; /* Source location to read
                                                        from */

         do
         {
            if (u32Idx >= pstNandCfg->u32BlkSize) /* check range/condition! */
            {
               /* This function might cross the total size / number of blocks
                  of the NAND device. DO NOT reset StartPage since it is used
                  in the loop exit condition. */
               u32BlockNumber++;
               u32NoOfPages = (u32NoOfPages - (u32Idx - u32StartPage));
               /* Read should continue at beginning of the next block */
               u32Idx = 0U;
               u32StartPage = 0U;
            }
            if (pstNandCfg->eBusWidth == NANDFLASH_BUS_WIDTH_16)
            {
               eResult =
                  eNandFlash_ProgramPage16bitWords (pstNandCfg, u32BlockNumber,
                                                    u32Idx,
                                                    (uint16_t *)u32SrcAddr,
                                                    (uint16_t *)pu32ExtrBuf);
            }
            else
            {
               eResult =
                  eNandFlash_ProgramPageBytes (pstNandCfg, u32BlockNumber,
                                               u32Idx, (uint8_t *)u32SrcAddr,
                                               (uint8_t *)pu32ExtrBuf);
            }
            u32Idx++;
            u32SrcAddr = (u32SrcAddr + pstNandCfg->u32PageSize);
         }
         while (((u32Idx < (u32StartPage + u32NoOfPages)) &&
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
NandFlashStatus_e eNandFlash_ProgramData (NandFlashCfg_st * pstCfg,
                                          uint32_t pu32SrcBuf[],
                                          uint32_t u32SrcBufLen,
                                          uint32_t pu32DstAddr,
                                          uint32_t pu32ExtrBuf[])
{
   NandFlashStatus_e eNandStatus;

   uint32_t u32BlockBytes;

   uint32_t u32BlockNumber;

   uint32_t u32ByteBlkOffset;

   uint32_t u32StartPage;

   uint32_t u32NoOfPages;

   /* Calculate Block and Page number */
   u32BlockBytes = (pstCfg->u32BlkSize) * (pstCfg->u32PageSize);
   /* Block number where the addr is pointing to */
   u32BlockNumber = (pu32DstAddr / u32BlockBytes);
   /* Address offset from the beginning of the block */
   u32ByteBlkOffset = (pu32DstAddr % u32BlockBytes);
   /* Page number, in which the addr is pointing to */
   u32StartPage = (u32ByteBlkOffset / (pstCfg->u32PageSize));
   /* Convert no of words to no of bytes */
   u32SrcBufLen = (u32SrcBufLen << 2);

   /* Calculate how many pages should be read */
   u32NoOfPages = ((u32SrcBufLen) / pstCfg->u32PageSize);
   /*
      Check, if one additional page needs to be programmed */
   if (((u32SrcBufLen) % (pstCfg->u32PageSize)) != 0)
   {
      u32NoOfPages = u32NoOfPages + 1;      /* Another page must be prog. */
   }
   /* Perform NAND data-program */
   eNandStatus =
      eNandFlash_ProgramPages (pstCfg, u32BlockNumber, u32StartPage,
                               u32NoOfPages, pu32SrcBuf, pu32ExtrBuf);
   return eNandStatus;
}

/*..........................................................................*/

/* violation of MISRA rule xx.x but this is just a demo */

/**********************************************************************
*
* NOTE00:
* ...
*
*/


/***************************************************************************/


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
  conditions set forth in the Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (Unintended Usage).
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

