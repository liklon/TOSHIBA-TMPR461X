/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   DESCRIPTION : NAND erase/programming header file.
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : System
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.5 $
*   DATE        : $Date: 2015/05/04 09:07:17 $
*   TAG         : $Name: HLDD_1_1 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef PL353_NANDFLASH_H
#define PL353_NANDFLASH_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                       /* Cap-Bt Data types header */
#include "pl353nand.h"

/**********************************************
*                 Constants                   *
**********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/
/*..........................................................................*/
/* NAND programming Utility ERASE selector */
typedef enum tag_NandErase_e
{
    NAND_ERASE_AUTO = 0U,
    NAND_ERASE_SKIP = 1U
} NandErase_e;

/* NAND programming Utility State Machine selector  */
typedef enum tag_NandPrgState_e
{
   NAND_PRG_STATE_INIT      = 0,  /* Initialize state machine and variables */
   NAND_PRG_STATE_LOAD_SREC = 1,  /* */
   NAND_PRG_STATE_COPY_SREC = 2,  /* */
   NAND_PRG_STATE_FILL_GAP  = 3,  /* */
   NAND_PRG_STATE_PROGRAM   = 4,  /* */
   NAND_PRG_STATE_READY     = 5   /* */
} NandPrgState_e;

/* NAND programming Utility OPERATION results */
typedef enum tag_NandPrgRslt_e
{
   NAND_RSLT_OK          = 0,     /* OK */
   NAND_RSLT_LOAD_ERR    = 1,     /* NO ANY S-Record loaded */
   NAND_RSLT_LOAD_END    = 2,     /* ALL S-Records loaded */
   NAND_RSLT_ERASE_ERR   = 3,     /* ERASE error */
   NAND_RSLT_PROGRAM_ERR = 4,     /* PROGRAM error */
   NAND_RSLT_STATUS_ERR  = 5,     /* READ PAGE Status error */
   NAND_RSLT_VERIFY_ERR  = 6      /* VERIFY error */

} NandPrgRslt_e;

/**********************************************
*                 Structures                  *
**********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/*..........................................................................*/
/*   NAND FLASH ERASE required blocks  */
NandFlashStatus_e eIplPrgNand_SelectErase (NandFlashCfg_st * pstNandCfg,
                                           uint32_t u32HdrStart,
                                           uint32_t u32HdrSize,
                                           uint32_t u32BlStart,
                                           uint32_t u32BlSize,
                                           uint32_t u32EpStart,
                                           uint32_t u32EpSize);

/*..........................................................................*/
/*   NAND FLASH ERASE blocks specified by address range */
NandFlashStatus_e eNandUtil_AutoErase (NandFlashCfg_st * pstNandCfg,
                                       uint32_t u32StartAddress,
                                       uint32_t u32EndAddress,
                                       uint32_t* pu32ErasedBlocks);

/*****************************************************************************
* This function erases the specified block inside the NAND flash device.
*
*****************************************************************************/
NandFlashStatus_e eNandFlash_EraseBlock (NandFlashCfg_st * pstNandCfg,
                                         uint32_t u32BlockNumber);

/*****************************************************************************
* This function programs a data page within the 8-bit NAND Flash devices.
* It should be used for memory devices with 8-bit interface, which are organized
* as arrays of bytes. The destination location is addressed by a block number
* and by a page number within a block.
*****************************************************************************/
NandFlashStatus_e eNandFlash_ProgramPageBytes (NandFlashCfg_st * pstNandCfg,
                                               uint32_t u32BlockNumber,
                                               uint32_t u32PageNumber,
                                               uint8_t pu8SrcBuf[],
                                               uint8_t pu8ExtrBuf[]);

/*****************************************************************************
* This function writes a data page within 16-bit NAND Flash devices.
* It should be used for memory devices with 16-bit interface, which are
* organized as arrays of 16-bit words. The destination location is addressed by
* a block number and by a page number within a block.
*****************************************************************************/
NandFlashStatus_e eNandFlash_ProgramPage16bitWords (NandFlashCfg_st *
                                                    pstNandCfg,
                                                    uint32_t u32BlockNumber,
                                                    uint32_t u32PageNumber,
                                                    uint16_t pu16SrcBuf[],
                                                    uint16_t pu16ExtrBuf[]);

/*****************************************************************************
* This function writes the data from the source buffer NAND pages within
* 8 or 16-bit NAND Flash devices.
*****************************************************************************/
NandFlashStatus_e eNandFlash_ProgramPages (NandFlashCfg_st * pstNandCfg,
                                           uint32_t u32BlockNumber,
                                           uint32_t u32StartPage,
                                           uint32_t u32NoOfPages,
                                           uint32_t pu32SrcBuf[],
                                           uint32_t pu32ExtrBuf[]);

/*****************************************************************************
* This function programs the NAND Flash memory device. This function reads the
* specified number of consecutive bytes starting at the source address from the
* source (typically RAM) memory buffer and stores the data into the destination
* NAND Flash memory at address specified by pu32DstAddr pointer.
* The destination address (pu32DstAddr) must be always NAND Page-size alligned.
*****************************************************************************/
NandFlashStatus_e eNandFlash_ProgramData (NandFlashCfg_st * pstCfg,
                                          uint32_t pu32SrcBuf[],
                                          uint32_t u32SrcBufLen,
                                          uint32_t pu32DstAddr,
                                          uint32_t pu32ExtrBuf[]);


#endif /* PL353_NANDFLASH_H */

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

