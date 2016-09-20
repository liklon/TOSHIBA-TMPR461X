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
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/08 08:54:27 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef NANDFLASH_H
#define NANDFLASH_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                       /* Cap-Bt Data types header */

/* *** Initial value and CRC-16 generator polynomial defines *** */
#define CRCGEN_INIT_VALUE  (0x4F4EU)
#define CRCGEN_POLYNOMIAL  (0x8005U)

/* *** Functions' parameters definitions *** */
#define NF_PAR_IGNORE   (0U)                /* parameter not meaningful */
#define NF_PAR_NO_END_CMD  (0U)             /* u32EndCmdValid param:
                                               u32EndCommand not used */
#define NF_PAR_END_VALID   (1U)             /* u32EndCmdValid param: use
                                               u32EndCommand */
#define NF_PAR_CS_ACTIV   (0U)              /* u32ClearCs param: keep CS LOW
                                               (ACTIVE) */
#define NF_PAR_CS_CLEAR   (1U)              /* u32ClearCs param: change CS to
                                               HIGH */
#define NF_PAR_ECC_CALC   (0U)              /* u32EccLast param: ECC calculate
                                               (ACTIVE) */
#define NF_PAR_ECC_LAST   (1U)              /* u32EccLast param: last value for
                                               ECC */
#define NF_PAR_CMD_PHASE   (0U)             /* indicates Command Phase address */
#define NF_PAR_DATA_PHASE  (1U)             /* indicates Data Phase address */

/*
 Assume 160Mz clock: 1 CPU cycle == 6.25[ns].
 1[us] == 160 CPU cycles
 Since typical SW loop takes 3x CPU cycles - each value for a typical
 loop should be divded by 3. For other loops (busy check) - CPU executes ~12
 instructions - so each value should be divided by 12, 10x will be used for safety
*/
#define NANDFLASH_TIME_1us   (10U)
#define NANDFLASH_TIME_1ms   (1000U * (NANDFLASH_TIME_1us))
#define NANDFLASH_TIME_1s    (1000U * (NANDFLASH_TIME_1ms))

/* Device's Initial Busy Timeout (100us) */
#define NANDFLASH_INIT_TIME_MAX_us_CFG   ((100U * NANDFLASH_TIME_1us))

/*
 Device Busy Timeout: 1s. Wait Busy loop takes 25 CPU instructions:
 Use 24 as divider for SW-loop 1s timeout. */
#define NANDFLASH_BUSY_TIMEOUT_MAX_CFG   (NANDFLASH_TIME_1s /24U)

/* ECC Busy Timeout: 1s (loop takes 10 CPU cycles) */
#define NANDFLASH_ECC_TIMEOUT_MAX_CFG    (NANDFLASH_TIME_1s /10U)
/*
 For ONFI compliant devices there is a parameter page with 2 or more redundant
 pages. Single Parameter Page read needs 256 bytes SW buffer. */
#define NANDFLASH_ONFI_MAX_PARAM   (256U)

/* *** NAND Flash device common COMMANDS *** */
#define NANDFLASH_CMD_RESET           (0xFFU)
#define NANDFLASH_CMD_READ_ID         (0x90U)
#define NANDFLASH_CMD_READ_STATUS     (0x70U)
#define NANDFLASH_CMD_READ_MODE       (0x00U) /* use after Status check */
#define NANDFLASH_CMD_PAGE_RD_START   (0x00U)
#define NANDFLASH_CMD_PAGE_RD_END     (0x30U)
#define NANDFLASH_CMD_ERASE_START     (0x60U)
#define NANDFLASH_CMD_ERASE_END       (0xD0U)
#define NANDFLASH_CMD_PROGRAM_START   (0x80U)
#define NANDFLASH_CMD_PROGRAM_END     (0x10U)

/* *** NAND Flash special access ONFI v1.0 commands *** */
#define NANDFLASH_CMD_WR_COL_CHNG     (0x85U)
#define NANDFLASH_CMD_RD_COL_CHNG     (0x05U)
#define NANDFLASH_CMD_RD_COL_CH_END   (0xE0U)
#define NANDFLASH_CMD_RD_COL_CH_E_V   (0x1U)

/* *** ONFI only COMMANDS *** */
#define NANDFLASH_CMD_ONFI_READ_PARAM   (0xECU)
#define NANDFLASH_CMD_ONFI_SET_FEATURE  (0xEFU)
#define NANDFLASH_CMD_ONFI_GET_FEATURE  (0xEEU)

/* NAND READY interrupt clear macro */
#define NANDFLASH_CLEAR_READY_IRQ()   MEMCTRL_MEM_CFG_CLR=MEMCTRL_INT_CLR_1_BIT

/* *** NAND device's type selection *** */
typedef enum tag_NandFlashDeviceType_e
{
   NANDFLASH_DEVICE_ONFI_HOST_ECC = 0,      /* Device configured according to
                                               ONFI */
   NANDFLASH_DEVICE_ONFI_VENDOR1_ECC,       /* Device configured according to
                                               ONFI w. internal ECC: MICRON */
   NANDFLASH_DEVICE_MAX                     /* For max-range use only */
} NandFlashDeviceType_e;

/* *** Drivers functions' results / status / error codes *** */
typedef enum tag_NandFlashStatus_e
{
   NANDFLASH_STATUS_OK = 0,                 /* operation was successful */
   NANDFLASH_STATUS_UNKNOWN,                /* initial result value */
   NANDFLASH_STATUS_NO_COMPLY_ERR,          /* Access try to parameters for
                                               non-compliant device */
   NANDFLASH_STATUS_OPERATION_ERR,          /* PROGRAM / ERASE BLOCK / ERASE
                                               ALL operation failed */
   NANDFLASH_STATUS_PTR_ERR,                /* pointer was invalid */
   NANDFLASH_STATUS_CFG_ERR,                /* provided configuration was
                                               invalid */
   NANDFLASH_STATUS_SIZE_ERR,               /* number of read-bytes greater
                                               than memory area */
   NANDFLASH_STATUS_BUSY_ERR,               /* busy-timeout occurred */
   NANDFLASH_STATUS_USAGE_ERR,              /* function not intended for this
                                               type of device or device can not
                                               accept such request: e.g. Page
                                               does not exists */
   NANDFLASH_STATUS_PARAM_ERR,              /* function parameter invalid */
   NANDFLASH_STATUS_CRC_ERR,                /* CRC-16 error(s) detected */
   NANDFLASH_STATUS_ECC_RD_ERR,             /* ECC/Block-Read Error */
   NANDFLASH_STATUS_ECC_ERR                 /* ECC error(s) detected, but not
                                               possible to correct */
} NandFlashStatus_e;

/* *** NAND device's data bus width definitions *** */
typedef enum tag_NandFlashBusWidth_e
{
   NANDFLASH_BUS_WIDTH_8 = 0x00,            /* 8-bits bus */
   NANDFLASH_BUS_WIDTH_16 = 0x01            /* 16-bits bus */
} NandFlashBusWidth_e;

/* *** NAND device's Extra Block configuration / size [B] definitions *** */
typedef enum tag_NandFlashExtraBlock_e
{
   NANDFLASH_EXTRA_BLOCK_DISABLED = 0,      /* NO extra block */   
   NANDFLASH_EXTRA_BLOCK_8_BYTES,           /* Extra block uses 8 bytes */
   NANDFLASH_EXTRA_BLOCK_16_BYTES,          /* Extra block uses 16 bytes */
   NANDFLASH_EXTRA_BLOCK_32_BYTES           /* Extra block uses 32 bytes */
} NandFlashExtraBlock_e;

/* *** NAND Flash main configuration structure data-type *** */
typedef struct tag_NandFlashCfg_st
{
   uint32_t u32NandChipAddress;             /* refer to FPGA or Cap-Bt spec. */
   NandFlashDeviceType_e eDeviceType;       /* ONFI w/o or with ECC support */
   NandFlashBusWidth_e eBusWidth;           /* number of data bit for device's
                                               bus */
   NandFlashExtraBlock_e eExtraBlockCfg;    /* disable or select Extra Block */
   uint32_t u32PageAdrCycNo;                /* address cycles to access Page */
   uint32_t u32BlkSize;                     /* number of Pages within Block */
   uint32_t u32PageSize;                    /* number of Bytes within Page */
   uint16_t u16SpareSize;                   /* number of Bytes within Spare
                                               Area */
   uint32_t u32IdRdTime;
   uint32_t u32StatusRdTime;
   uint32_t u32WriteCycleTime;
   uint32_t u32ReadCycleTime;
   uint32_t u32BusyCycleToReN;
   uint32_t u32DeAssertDelayWeN;
   uint32_t u32AssertDelayReN;
   uint32_t u32BusyTimeOut;                 /* used for waiting with busy
                                               finite-loops */
   uint32_t u32EccTimeOut;                  /* used for waiting with ECC busy
                                               finite-loops */
   uint8_t u8EccBitsCorr;                   /* number of bits ECC
                                               correctability */
   uint8_t u8ManufacturerId;
   uint8_t u8DeviceId;
   uint8_t pu8Param[NANDFLASH_ONFI_MAX_PARAM]; /* Parameters storage area */
} NandFlashCfg_st;                          /* definition of struct type */


/* Extra Block buffer */
extern uint32_t pu32GlExtraBlockBuf[8];


/* ****************** NAND Flash API Functions Definitions ****************** */

/*****************************************************************************
* DESC   : This Assembler function is needed to write a 2x32-bit burst the data
*          into the NAND device. Such operations are not supported in C.
*****************************************************************************/
extern void vNF_AddrBrstWr(uint32_t u32CmdPhAddr, uint32_t u32BlkWrd0, uint32_t u32BlkWrd1);

/*****************************************************************************
* This function is used by most of NAND driver functions for [us] wait
* intervals geration.
* Assumed CPU clock= 160 MHz: 160 CPU instructions ~= 1[us].
* The function's parameter (multiplied by 160) is finally limited to 32-bit.
* This implies the max. duration of the interval...
* Since each loop in this function requires 3x CPU instructions (SUB, CMP, BNE)
* or (MOVS, SUB, BNE) the duration value should be divided by 3. This is done,
* while creating values for NANDFLASH_TIME_1us, NANDFLASH_TIME_1ms and
* NANDFLASH_TIME_1s defines.
*****************************************************************************/
void NF_uSecWait (uint32_t u32usTime);

/*****************************************************************************
* Function loads configuration parameters, which have been set during the HW
* reset or with the use of the “Set” functions) from the Memory Controller
* registers to the respective member variables within the NandFlashCfg_st data
* structure.
*****************************************************************************/
NandFlashStatus_e eNandFlash_GetHwConfig (NandFlashCfg_st * pstNandCfg);

/*****************************************************************************
* This function executes the sequence of events required to initialise the SMC
* Memory Controller and a NAND Flash memory device to ensure the configuration
* of both is synchronized. The content of the NandFlashCfg_st data structure
* will be used to perform the required operations. It should be noted, however,
* that the PL353 memory controller allows to specify the required timing for
* each transfer separately. For this reason most of the timing parameters stored
* in NandFlashCfg_st data structure will be provided during a command write,
* data read (or similar operation).
* Limitation: Cap bt/C doen't support 4byte Extra buffer size. 
*****************************************************************************/
NandFlashStatus_e eNandFlash_Initialize (NandFlashCfg_st * pstNandCfg,
                                         NandFlashDeviceType_e eDeviceType);

/*****************************************************************************
* This function sets the Extra block related configuration within the
* NandFlashCfg_st structure. The Extra Block can be Disabled or enabled. If the
* size is set to non-zero value the Extra block will be Enabled, refer to
* NandFlashExtraBlock_e data type.
*****************************************************************************/
NandFlashStatus_e eNandFlash_SetExtraBlock (NandFlashCfg_st * pstNandCfg,
                                            NandFlashExtraBlock_e eExtraBlkCfg);

/*****************************************************************************
* This function sets the u8IdRdTime, u8StatusRdTime, u8WriteCycleTime and
* u8ReadCycleTime for NAND chip configuration inside the NandFlashCfg_st
* configuration structure.
*****************************************************************************/
NandFlashStatus_e eNandFlash_SetBusTiming (NandFlashCfg_st * pstNandCfg,
                                           uint32_t u32IdRdTime,
                                           uint32_t u32StatusRdTime,
                                           uint32_t u32WriteCycleTime,
                                           uint32_t u32ReadCycleTime);

/*****************************************************************************
* This function sets u8BusyCycleToReN cycles, u8DeAssertDelayWeN de-assertion
* delay and u8AssertDelayReN assertion delay, configuration inside the
* NandFlashCfg_st configuration structure.
*****************************************************************************/
NandFlashStatus_e eNandFlash_SetCycleAssertDelays (NandFlashCfg_st * pstNandCfg,
                                                   uint32_t u32BusyCycleToReN,
                                                   uint32_t u32DeAssertDelayWeN,
                                                   uint32_t u32AssertDelayReN);

/*****************************************************************************
* This function reads the NAND Flash device status: busy / ready. If the device
* is busy - it waits a predefined time in the finite loop. A number of the loop
* cycles is provided as a function parameter.
*****************************************************************************/
NandFlashStatus_e eNandFlash_WaitDeviceReady (const NandFlashCfg_st *
                                              const pstNandCfg);

/*****************************************************************************
* Function waits with timeout until ECC HW module finishes its work.
*****************************************************************************/
NandFlashStatus_e eNF_EccWaitIdle (const NandFlashCfg_st * const pstNandCfg);

/*****************************************************************************
* Function sends a NAND Command over the AXI bus, with most possible parameters
* configurable (column number, page number, block number, start / end commands).
*****************************************************************************/
void vNF_CmdPhaseAxiCplx (const NandFlashCfg_st * const pstNandCfg,
                          uint32_t u32ColAdr, uint32_t u32PageNo,
                          uint32_t u32BlockNo, uint32_t u32StartCommand,
                          uint32_t u32EndCmdValid, uint32_t u32EndCommand);

/*****************************************************************************
* Function configures ECC HW module for auto-ECC generation for NAND devices
* with 2kB Pages.
*****************************************************************************/
NandFlashStatus_e eNF_EccConfigure (const NandFlashCfg_st * const pstNandCfg);

/*****************************************************************************
* Function reads the current status from the NAND device.
* configuration.
*****************************************************************************/
NandFlashStatus_e eNF_GetDeviceStatus (const NandFlashCfg_st *
                                       const pstNandCfg);

/*****************************************************************************
* Function gives the Status Register value from the NAND device.
*
*****************************************************************************/
NandFlashStatus_e eNF_ReadDeviceStatus (const NandFlashCfg_st * const pstNandCfg,
                                        uint32_t* pu32NandStatus );

/*****************************************************************************
* This function sends the reset command (reinitialises the device) to the
* NAND Flash device.
*****************************************************************************/
NandFlashStatus_e eNandFlash_ResetDevice (const NandFlashCfg_st * const pstNandCfg);

/*****************************************************************************
* This function reads a data page from the 8-bit NAND Flash devices. It should
* be used for memory devices with 8-bit interface, which are organized as arrays
* of bytes. The expected data is addressed by a block number and by a page
* number within a block.
*****************************************************************************/
NandFlashStatus_e eNandFlash_ReadSinglePage (NandFlashCfg_st * pstNandCfg,
                                             uint32_t u32BlockNumber,
                                             uint32_t u32PageNumber,
                                             uint32_t pu32DstBuf[],
                                             uint32_t pu32ExtrBuf[]);

/*****************************************************************************
* This function reads a spare data area for a particular page from the 8-bit
* NAND Flash devices. It should be used for memory devices with 8-bit interface,
* which are organized as arrays of bytes. The expected data is addressed by a
* block number, page number and an offset within a spare area.
*****************************************************************************/
NandFlashStatus_e eNandFlash_ReadSpareArea (NandFlashCfg_st * pstNandCfg,
                                            uint32_t u32BlockNumber,
                                            uint32_t u32PageNumber,
                                            uint32_t u32SpareOffset,
                                            uint32_t u32BufferLen,
                                            uint32_t pu32DstBuf[]);

/*****************************************************************************
* This function reads data from the NAND Flash devices. The readout data is put
* starting at the memory pointed by the pointer provided by the application.
* The readout starts at the provided block and page number. If the Page number
* is outside of the size of the block - the readout will move the source pointer
* to the next block, and so on. It is the responsibility of the application to
* insure the reading of blocks/pages within the range of the total size of the
* NAND device. If any of the blocks will fail its ECC during the readout this
* function will return a NANDFLASH_STATUS_ECC_ERR error.
*****************************************************************************/
NandFlashStatus_e eNandFlash_ReadPages (NandFlashCfg_st * pstNandCfg,
                                        uint32_t u32BlockNumber,
                                        uint32_t u32StartPage,
                                        uint32_t u32NoOfPages,
                                        uint32_t pu32DstBuf[],
                                        uint32_t pu32ExtrBuf[]);

/*****************************************************************************
* This function reads data from the NAND Flash devices. The readout data is put
* starting at the memory pointed by the pointer provided by the application.
* The readout starts at the provided offset, which should be always NAND Page
* alligned (start at a page-beginning address). It is assumed that Page 0 starts
* at u32StartAddr equal to 0. Next Page address is dependent on the size of the
* page, as can be read from NandFlashCfg_st structure.
*
* It is the responsibility of the application to insure the reading of data,
* as specified by u32BufferLen, within the range of the total size of the NAND
* device.
* u32BufferLen must greater or equal to the sum of the pages (total) involved in
* the data read.
* Example:
* u32StartAddr= (4096/4) = 1024, PageSize= (2048/4)= 512 words,
* if want to read u32BufferLen= 2052 bytes = 513 words - it is needed to provide
* a buffer of the size of 2xPagesize == 1024 words.
*
*****************************************************************************/
NandFlashStatus_e eNandFlash_ReadNand (NandFlashCfg_st * pstNandCfg,
                                       uint32_t u32StartAddr,
                                       uint32_t pu32Data[],
                                       uint32_t u32BufferLen);


#endif /* NANDFLASH_H */


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

