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
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef NORFLASH_H
#define NORFLASH_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                   /* Cap-Bt Data types header */

/* Configurable device Busy Timeout in CPU cycles  */
#define NORFLASH_BUSY_TIMEOUT_MAX_CFG   (2000U)

/* Configurable Erase All Chip Timeout in CPU cycles  */
#define NORFLASH_ERASE_CHIP_TIMEOUT_CFG   (0xFFFFFFFFU)

/* Configurable Erase Single Block Timeout in CPU cycles  */
#define NORFLASH_ERASE_BLK_TIMEOUT_CFG   (0xFFFFFFFFU)

/* Configurable Block Program Timeout in CPU cycles  */
#define NORFLASH_PROGRAM_TIMEOUT_CFG   (0xFFFFFFFFU)

/* Macros for accessing NOR device in byte or 16 bit word */

/*
#define NORFLASH_BYTE_ACCESS(base,address)   *(TYPES_REG8((uint32_t)((base)+(address))))
*/
#define NORFLASH_BYTE_ACCESS(base,address)    *(TYPES_REG8((uint32_t)((base)+(address))))
#define NORFLASH_WORD_ACCESS(base,address)   *(TYPES_REG16((uint32_t)((base)+(address))))

/* *** NAND Flash device common COMMANDS *** */
#define NORFLASH_CMD_RESET     (0xF0U)
#define NORFLASH_CMD_ERASE_SETUP    (0x80U)
#define NORFLASH_CMD_ERASE_CHIP     (0x10U)
#define NORFLASH_CMD_ERASE_BLOCK    (0x30U)
#define NORFLASH_CMD_PROGRAM        (0xA0U)

/* Drivers functions' results / status / error codes */
typedef enum tag_NorFlashStatus_e
{
   NORFLASH_STATUS_OK = 0,                  /* operation was successful */
   NORFLASH_STATUS_UNKNOWN,                 /* initial result value */
   NORFLASH_STATUS_PTR_ERR,                 /* pointer was invalid */
   NORFLASH_STATUS_CFG_ERR,                 /* provided configuration invalid */
   NORFLASH_STATUS_OPERATION_ERR,           /* PROGRAM / ERASE BLOCK / ERASE */
   NORFLASH_STATUS_BUSY_ERR,                /* busy-timeout occurred */
   NORFLASH_STATUS_RD_ID_ERR                /* reading of the device failed */
} NorFlashStatus_e;

/* NOR device's data bus width definitions */
typedef enum tag_NorFlashBusWidth_e
{
   NORFLASH_BUS_WIDTH_16 = 0x01             /* 16-bits bus only supported */
} NorFlashBusWidth_e;

/* NOR device's burst length definitions */
typedef enum tag_NorFlashBurstLength_e
{
   NORFLASH_BURST_LEN_1 = 0x00,             /* 1 beat burst */
   NORFLASH_BURST_LEN_4,                    /* 4 beats burst */
   NORFLASH_BURST_LEN_8,                    /* 8 beats burst */
   NORFLASH_BURST_LEN_16,                   /* 16 beats burst */
   NORFLASH_BURST_LEN_32,                   /* 32 beats burst */
   NORFLASH_BURST_LEN_CNTS                  /* Continuous operation */
} NorFlashBurstLength_e;

/* NOR device's Read / Write mode definitions */
typedef enum tag_NorFlashRdWrMode_e
{
   NORFLASH_NOSYNC_MODE = 0x00,             /* Memory Asynchronous mode */
   NORFLASH_SYNC_MODE                       /* Memory Synchronous mode */
} NorFlashRdWrMode_e;

/* NOR device's Burst alignment definitions */
typedef enum tag_NorFlashBurstAlign_e
{
   NORFLASH_BURST_ALGN_CROSS_ANY = 0x00,    /* Burst can cross any address
                                               boundary. */
   NORFLASH_BURST_ALGN_CROSS_32,            /* splits on boundary that is 32
                                               beats for continuous. */
   NORFLASH_BURST_ALGN_CROSS_64,            /* ... 64 beats */
   NORFLASH_BURST_ALGN_CROSS_128,           /* ... 128 beats */
   NORFLASH_BURST_ALGN_CROSS_256            /* ... 256 beats */
} NorFlashBurstAlign_e;

/* NOR device's WE Time configuration definitions */
typedef enum tag_NorFlashWeTimeCfg_e
{
   NORFLASH_WE_TIME_CFG_WEN_AFTER = 0x00,   /* we_n asserts 2 cyc. after CS_n */
   NORFLASH_WE_TIME_CFG_WEN_TOGETHER        /* we_n asserts together with CS_n */
} NorFlashWeTimeCfg_e;

/* NOR device's Byte Lane configuration definitions */
typedef enum tag_NorFlashByteLane_e
{
   NORFLASH_BYTE_LANE_AS_CS = 0x00,         /* BLS timing == Chip Sel tim. */
   NORFLASH_BYTE_LANE_AS_WEN                /* 8-bit memories only: REMOVE? */
} NorFlashByteLane_e;

/* NOR device's Advance Signal configuration definitions */
typedef enum tag_NorFlashAdvanceSignal_e
{
   NORFLASH_NO_ADV_SIG = 0x00,              /* NO use of advance signal(s) */
   NORFLASH_USE_ADV_SIG                     /* Use advance signal(s) */
} NorFlashAdvanceSignal_e;

/* NAND Flash main configuration structure data-type */
typedef struct tag_NorFlashCfg_st
{
   uint32_t u32NorChipAdr;                  /* refer to FPGA or Cap-Bt spec. */
   NorFlashBurstLength_e eWrBursLen;
   NorFlashBurstLength_e eRdBursLen;
   NorFlashBusWidth_e eBusWidth;            /* number of bit for device's bus */
   uint32_t u32TurnaroundTime;
   uint32_t u32PageCycleTime;
   uint32_t u32WriteCycleTime;
   uint32_t u32ReadCycleTime;
   NorFlashRdWrMode_e eWrMode;
   NorFlashRdWrMode_e eRdMode;
   NorFlashBurstAlign_e eBurstAlign;
   NorFlashWeTimeCfg_e eWeTime;
   uint32_t u32AssertDelayWeN;
   uint32_t u32AssertDelayOeN;
   NorFlashByteLane_e eByteLane;
   NorFlashAdvanceSignal_e eAdrAdvSig;
   NorFlashAdvanceSignal_e eBurstAdrAdvSig;
   uint32_t u32set_cycles;                  /* store value of set_cycles reg */
   uint32_t u32set_opmode;                  /* store value of set_opmode reg */
} NorFlashCfg_st;                           /* definition of struct type */

/*****************************************************************************
* These function loads configuration parameters (which have been set during the
* HW reset or with the use of the “Set” functions) from the Memory Controller
* registers to the respective member variables within the NorFlashCfg_st data
* structure. It is recommended to call this function, before any other NOR
* driver function is called.
*****************************************************************************/
NorFlashStatus_e eNorFlash_GetHwConfig (NorFlashCfg_st * pstNorCfg);

/*****************************************************************************
* This function executes the sequence of events required to initialise the SMC
* Memory Controller and a Flash memory device to ensure the configuration of
* both is synchronized. The content of the NorFlashCfg_st data structure will
* be used to perform the required operations.
*****************************************************************************/
NorFlashStatus_e eNorFlash_Initialize (NorFlashCfg_st * pstNorCfg);

/*****************************************************************************
* This function sets the memory blocks size, read and write bursts lengths
* inside the NorFlashCfg_st structure.
*****************************************************************************/
NorFlashStatus_e eNorFlash_SetBurstLength (NorFlashCfg_st * pstNorCfg,
                                           NorFlashBurstLength_e eWrBrstLen,
                                           NorFlashBurstLength_e eRdBrstLen);

/*****************************************************************************
* This function sets the u8TurnaroundTime, u8PageCycleTime, u8WriteCycleTime
* and u8ReadCycleTime for SRAM chip configuration (refer to t_tr, t_pc, t_wc
* and t_rc bits in SMC Memory controller.
*****************************************************************************/
NorFlashStatus_e eNorFlash_SetBusTiming (NorFlashCfg_st * pstNorCfg,
                                         uint32_t u32TurnaroundTime,
                                         uint32_t u32PageCycleTime,
                                         uint32_t u32WriteCycleTime,
                                         uint32_t u32ReadCycleTime);

/*****************************************************************************
* This function sets the configuration of the memory. It affects the memory
* burst splitting method across different burst boundaries, write and read
* synchronous mode settings inside the NorFlashCfg_st structure. This memory
* burst splitting is valid, when the SMC is configured to perform synchronous
* transfers.
*****************************************************************************/
NorFlashStatus_e eNorFlash_SetReadWriteSyncMode (NorFlashCfg_st * pstNorCfg,
                                                 NorFlashRdWrMode_e eWrMode,
                                                 NorFlashRdWrMode_e eRdMode,
                                                 NorFlashBurstAlign_e
                                                 eBurstAlign);

/*****************************************************************************
* This function sets eWeTime cycles (this parameter is valid only for
* asynchronous multiplexed transfers), u8AssertDelayWeN assertion delay and
* u8AssertDelayOeN assertion delay, configuration inside the NorFlashCfg_st
* configuration structure.
*****************************************************************************/
NorFlashStatus_e eNorFlash_SetSignalsAssertDelays (NorFlashCfg_st * pstNorCfg,
                                                   NorFlashWeTimeCfg_e eWeTime,
                                                   uint32_t u32AssertDelayWeN,
                                                   uint32_t u32AssertDelayOeN);

/*****************************************************************************
* This function sets the configuration of the byte-lane strobe outputs (bls_n),
* address advance (adv_n) and burst address advance (baa_n) signals inside the
* NorFlashCfg_st structure.
*****************************************************************************/
NorFlashStatus_e eNorFlash_SetSignalsConfig (NorFlashCfg_st * pstNorCfg,
                                             NorFlashByteLane_e eByteLane,
                                             NorFlashAdvanceSignal_e eAdrAdvSig,
                                             NorFlashAdvanceSignal_e
                                             eBurstAdrAdvSig);

/*****************************************************************************
* This function resets NOR Flash memory device. After this command the NOR
* Flash memory device should return to the read mode.
*****************************************************************************/
NorFlashStatus_e eNorFlash_Reset (const NorFlashCfg_st * const pstNorCfg);

/*****************************************************************************
* This function reads the specified number of consecutive 16-bit words starting
* at the source address from the NOR flash memory device and stores the data
* into the destination buffer (e.g. to the RAM memory)..
* u32BufferLen contains a number of 16-bit words.
*****************************************************************************/
NorFlashStatus_e eNorFlash_Read16bitWords (const NorFlashCfg_st *
                                           const pstNorCfg, uint32_t u32SrcAdr,
                                           uint16_t pu16DstBuf[],
                                           uint32_t u32BufferLen);

/*****************************************************************************
* This function reads the specified number of consecutive 32-bit words starting
* at the source address from the NOR flash memory device and stores the data
* into the destination buffer (e.g. to the RAM memory).
* u32BufferLen contains a number of 32-bit words
*****************************************************************************/
NorFlashStatus_e eNorFlash_Read32bitWords (const NorFlashCfg_st *
                                           const pstNorCfg, uint32_t u32SrcAdr,
                                           uint32_t pu32DstBuf[],
                                           uint32_t u32BufferLen);


#endif /* NORFLASH_H */


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

