/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION :
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     : TSM-Driver
*   MODULE      : TSM
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.15 $
*   DATE        : $Date: 2015/05/04 09:07:17 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSMDEFINES_H
#define TSMDEFINES_H

/**********************************************
*                Include files                *
**********************************************/

#include "captypes.h"
#include "tsm_erc.h"


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

/*! Key-ID's defined  as per section 4.5 in
	  2009-04-01_SHE_Functional_Specification_v1.1(rev439).pdf */
typedef enum tag_tsm_key_id_e
{
    TSM_SECRET_KEY = 0x0,
    /*!< Secret Key (ROM) */

    TSM_MASTER_ECU_KEY = 0x1,
    /*!< Master ECU Key, NOTE: for TMPR460/61XBG-300 TSM_KEY_1 and TSM_MASTER_ECU_KEY physically refer to one and the same key */

    TSM_BOOT_MAC_KEY = 0x2,
    /*!< Boot Mac Key */

    TSM_BOOT_MAC = 0x3,
    /*!< TSM_BOOT_MAC, not available for TMPR460/61XBG-300 */

    TSM_KEY_1 = 0x4,
    /*!< Key 1 */

    TSM_KEY_2 = 0x5,
    /*!< Key 2 */

    TSM_KEY_3 = 0x6,
    /*!< Key 3 */

    TSM_KEY_4 = 0x7,
    /*!< Key 4 */

    TSM_KEY_5 = 0x8,
    /*!< Key 5, not available for TMPR460/61XBG-300 */

    TSM_KEY_6 = 0x9,
    /*!< Key 6, not available for TMPR460/61XBG-300 */

    TSM_KEY_7 = 0xA,
    /*!< Key 7, not available for TMPR460/61XBG-300 */

    TSM_KEY_8 = 0xB,
    /*!< Key 8, not available for TMPR460/61XBG-300 */

    TSM_KEY_9 = 0xC,
    /*!< Key 9, not available for TMPR460/61XBG-300 */

    TSM_KEY_10 = 0xD,
    /*!< Key 10, not available for TMPR460/61XBG-300 */

    TSM_RAM_KEY = 0xE
    /*!< RAM Key */

} tsm_key_id_e;

/*! TSM function return code.*/
typedef enum tag_tsm_func_ret_e
{
    TSM_FUNC_ERC_UNKNOWN         = TSM_ERC_UNKNOWN,
    /*!< Value 0x00 defined as unknown */

    TSM_FUNC_NO_ERROR            = TSM_ERC_NO_ERROR,
    /*!< Successful operation */

    TSM_FUNC_SEQUENCE_ERROR      = TSM_ERC_SEQUENCE_ERROR,
    /*!< Sequence error in case the current (sub)command is
      unexpected */

    TSM_FUNC_KEY_NOT_AVAILABLE   = TSM_ERC_KEY_NOT_AVAILABLE,
    /*!< key is locked due to failed boot measurement or an
      active debugger */

    TSM_FUNC_KEY_INVALID         = TSM_ERC_KEY_INVALID,
    /*!< Key is not allowed for the given operation */

    TSM_FUNC_KEY_EMPTY           = TSM_ERC_KEY_EMPTY,
    /*!< key is not initialized yet */

    TSM_FUNC_NO_SECURE_BOOT      = TSM_ERC_NO_SECURE_BOOT,
    /*!< returned if
      (i) the conditions for a secure boot process are not met
      and the secure boot process has to be canceled.
      (ii) a function changing the boot status is called without
      secure booting
      (iii) after finishing the secure boot process */

    TSM_FUNC_KEY_WRITE_PROTECTED = TSM_ERC_KEY_WRITE_PROTECTED,
    /*!< key update is attempted on a memory slot that has been
      write protected or when an attempt to active the debugger
      is started when a key is write-protected. */

    TSM_FUNC_KEY_UPDATE_ERROR    = TSM_ERC_KEY_UPDATE_ERROR,
    /*!< key update did not succeed due to errors in verification of
      the messages */

    TSM_FUNC_RNG_SEED            = TSM_ERC_RNG_SEED,
    /*!< seed not initialized */

    TSM_FUNC_NO_DEBUGGING        = TSM_ERC_NO_DEBUGGING,
    /*!< internal debugging is not possible because the authentication
      with the challenge response protocol did not succeed. */

    TSM_FUNC_BUSY                = TSM_ERC_BUSY,
    /*!< TSM currently executing a command */

    TSM_FUNC_MEMORY_FAILURE      = TSM_ERC_MEMORY_FAILURE,
    /*!< memory read/write errors */

    TSM_FUNC_GENERAL_ERROR       = TSM_ERC_GENERAL_ERROR,
    /*!< any other errors */

    TSM_FUNC_GENERAL_ERROR_WRONG_PARAM     = 0x01000000 + (TSM_ERC_GENERAL_ERROR),
    /*!< One of the parameters supplied is wrong or invalid */

    TSM_FUNC_GENERAL_ERROR_NOT_IMPLEMENTED = 0x02000000 + (TSM_ERC_GENERAL_ERROR),
    /*!< Function not implemented */

    TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL   = 0x03000000 + (TSM_ERC_GENERAL_ERROR),
    /*!< returned by eTSM_GetErrorResultCode() when a valid ERC
      is not yet available */

    TSM_FUNC_GENERAL_ERROR_ERC_WRONG       = 0x04000000 + (TSM_ERC_GENERAL_ERROR),
    /*!< returned by eTSM_GetErrorResultCode() when a valid ERC
      is available but the value is not unique. Most likely due to a
      race condition caused by CMD_CANCEL */

    TSM_FUNC_GENERAL_ERROR_INTERNAL        = 0x05000000 + (TSM_ERC_GENERAL_ERROR),
    /*!< returned by eTSM_GetErrorResultCode() when any internal error detected  */

    TSM_FUNC_GENERAL_ERROR_TIMEOUT         = 0x06000000 + (TSM_ERC_GENERAL_ERROR)
    /*!< returned by eTSM_GetErrorResultCode() timeout occurred */

} tsm_func_ret_e;

/*! TSM verification modes only available for TMPR462/63XBG-300 */
typedef enum tag_tsm_secure_mode_e
{
    TSM_BACKGROUND_VERIFICATION = 0x1,
    /*!< background verification: verification in background while executing secondary boot loader */

    TSM_FOREGROUND_VERIFICATION = 0x2
    /*!< foreground verification: verification to be performed prior to executing secondary boot loader */
}tsm_secure_mode_e;

/*! TSM status register bits as per section 6 in
  2009-04-01_SHE_Functional_Specification_v1.1(rev439).pdf */
typedef enum tag_tsm_status_bit_e
{
    TSM_STATUS_BUSY           = (uint8_t)(1U << 0U),
    /*!< The bit is set whenever TSM is processing a command */

    TSM_STATUS_SECURE_BOOT    = (uint8_t)(1U << 1U),
    /*!< The bit is set if the secure booting is activated */

    TSM_STATUS_BOOT_INIT      = (uint8_t)(1U << 2U),
    /*!< The bit is set if the secure booting has been personalized during
      the boot sequence */

    TSM_STATUS_BOOT_FINISHED  = (uint8_t)(1U << 3U),
    /*!< The bit is set when the secure booting has been finished by calling
      either CMD_BOOT_FAILURE or CMD_BOOT_OK or if CMD_SECURE_BOOT failed in
      verifying BOOT_MAC. */

    TSM_STATUS_BOOT_OK        = (uint8_t)(1U << 4U),
    /*!< The bit is set if the secure booting (CMD_SECURE_BOOT) succeeded
      If CMD_BOOT_FAILURE is called the bit is erased */

    TSM_STATUS_RND_INIT       = (uint8_t)(1U << 5U),
    /*!< The bit is set if the random number generator has been initialized */

    TSM_STATUS_EXT_DEBUGGER   = (uint8_t)(1U << 6U),
    /*!< The bit is set if an external debugger is connected to the chip,
      i.e. it reflects the input for debugger activation */

    TSM_STATUS_INT_DEBUGGER   = (uint8_t)(1U << 7U)
    /*!< The bit is set if the internal debugging mechanisms of TSM are
      activated */
} tsm_status_bit_e;

/*! MAC verification status */
typedef enum tag_tsm_mac_verification_status_e
{
	/* to distinguish the value from empty data, we define none zerro values:*/
    TSM_MAC_VERIFICATION_STATUS_OK     = 0,
    /*!< MAC verification successful */

    TSM_MAC_VERIFICATION_STATUS_NOT_OK = 1
    /*!< MAC verification failed */
} tsm_mac_verification_status_e;

/*********************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TSMDEFINES_H */

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
  conditions set forth in the Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customers own risk.

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


