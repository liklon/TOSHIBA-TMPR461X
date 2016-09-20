/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TSM error code which will be used fro TSM-FW and Accessport
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TSM
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.11 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSM_ERC_H
#define TSM_ERC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

/**********************************************
*                    Macros                   *
**********************************************/


/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/

/*! TSM command result codes as per section 8 in
  2009-04-01_SHE_Functional_Specification_v1.1(rev439).pdf */
typedef enum tag_tsm_erc_e
{
    TSM_ERC_UNKNOWN                       = 0x00000000U,
    /*!< Value 0x00 defined as unknown */

    TSM_ERC_NO_ERROR                      = 0x00000001U,
    /*!< Successful operation */

    TSM_ERC_SEQUENCE_ERROR                = 0x00000002U,
    /*!< Sequence error in case the current (sub)command is
      unexpected */

    TSM_ERC_KEY_NOT_AVAILABLE             = 0x00000004U,
    /*!< key is locked due to failed boot measurement or an
      active debugger */

    TSM_ERC_KEY_INVALID                   = 0x00000008U,
    /*!< Key is not allowed for the given operation */

    TSM_ERC_KEY_EMPTY                     = 0x00000010U,
    /*!< key is not initialized yet */

    TSM_ERC_NO_SECURE_BOOT                = 0x00000020U,
    /*!< returned if
      (i) the conditions for a secure boot process are not met
      and the secure boot process has to be canceled.
      (ii) a function changing the boot status is called without
      secure booting
      (iii) after finishing the secure boot process */

    TSM_ERC_KEY_WRITE_PROTECTED           = 0x00000040U,
    /*!< key update is attempted on a memory slot that has been
      write protected or when an attempt to active the debugger
      is started when a key is write-protected. */

    TSM_ERC_KEY_UPDATE_ERROR              = 0x00000080U,
    /*!< key update did not succeed due to errors in verification of
      the messages */

    TSM_ERC_RNG_SEED                      = 0x00000100U,
    /*!< seed not initialized */

    TSM_ERC_NO_DEBUGGING                  = 0x00000200U,
    /*!< internal debugging is not possible because the authentication
      with the challenge response protocol did not succeed. */

    TSM_ERC_BUSY                          = 0x00000400U,
    /*!< TSM currently executing a command */

    TSM_ERC_MEMORY_FAILURE                = 0x00000800U,
    /*!< memory read/write errors */

    TSM_ERC_GENERAL_ERROR                 = 0x00001000U
    /*!< any other errors */

} tsm_erc_e;


/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TSM_ERC_H */

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
  conditions set forth in the ?Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (?Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer?s own risk.

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


