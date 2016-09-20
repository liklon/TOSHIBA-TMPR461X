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
*   VERSION     : $Revision: 1.13 $
*   DATE        : $Date: 2015/05/04 09:07:17 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSMAPI_REST_STREAM_H
#define TSMAPI_REST_STREAM_H
#include "tsmdefines.h"
#include "tsmapi_irq_dma_stream.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 using DMA
 *
 * eTSM_CmdEncCBCStream() shall use the supplied key to encrypt N*128-bits wide
 * plain text to N*128-bits wide encrypted text. The plain text to be encrypted
 * shall be N*128-bits(4 * 32-bits) wide and shall be placed in the memory
 * before calling this function. The 128-bits(4 * 32-bits) wide initialization
 * vector(IV) shall be also placed in the memory before calling this function.
 * The pointer where the encrypted text shall be written shall be large enough
 * to hold N*128-bits(4 * 32-bits) wide item. This function is implemented as
 * blocking call which means it returns not before the operation is finished.
 * This function uses DMA facilities.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx and above
 *
 * @param[in] eKeyId key to be used for encryption
 * @param[in] au32PlainText Pointer to the memory where the N*128-Bits wide
 *                            plain text is placed
 * @param[in] au32CipherText Pointer to the memory where the N*128-Bits wide
 *                               cipher text should be written
 * @param[in] au32IV Pointer to the memory where the 128-Bit wide
 *                            Initialization Vector(IV) is placed
 * @param[in] u32N count of the 128-Bits wide items (max. 3FFFh:16383d)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32IV
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32CipherText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID key is locked due to failed boot measurement or an active debugger
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 */
tsm_func_ret_e eTSM_CmdEncCBCStream(const tsm_key_id_e eKeyId,
                         const uint32_t au32PlainText[],
                         const uint32_t au32CipherText[],
                         const uint32_t au32IV[4],
                         const uint32_t u32N);


/**
 * @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 using DMA
 *
 * eTSM_CmdEncCBCInitStreamNoWait() provides the (non-blocking) variant of the
 * blocking eTSM_CmdEncCBCStream().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdEncCBCInitCheckResult()
 * This function uses DMA facilities.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx and above
 *
 * @param[in] eKeyId key to be used for encryption
 * @param[in] au32PlainText Pointer to the memory where the N*128-Bits wide
 *                            plain text is placed
 * @param[in] au32CipherText Pointer to the memory where the N*128-Bits wide
 *                               cipher text should be written
 * @param[in] au32IV Pointer to the memory where the 128-Bit wide
 *                            Initialization Vector(IV) is placed
 * @param[in] u32N count of the 128-Bits wide items (max. 3FFFh:16383d)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32IV
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32CipherText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID key is locked due to failed boot measurement or an active debugger
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 */
tsm_func_ret_e eTSM_CmdEncCBCStreamNoWait(const tsm_key_id_e eKeyId,
                         const uint32_t au32PlainText[],
                         const uint32_t au32CipherText[],
                         const uint32_t au32IV[4],
                         const uint32_t u32N);


/**
 * @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 (non-blocking)
 *
 * eTSM_CmdEncCBCStreamCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdEncCBCStream().
 * It checks if the command previously triggered by eTSM_CmdEncCBCStreamNoWait()
 * has been completed and retrieves the execution result.
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncCBCStream()
 * @see eTSM_CmdEncCBCStreamNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdEncCBCStreamCheckResult(void);


/**
 * @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 using DMA
 *
 * eTSM_CmdDecCBCStream() shall use the supplied key to decrypt N*128-bits wide
 * plain text to N*128-bits wide encrypted text. The encrypted text
 * shall be N*128-bits(4 * 32-bits) wide and shall be placed in the memory
 * before calling this function. The 128-bits(4 * 32-bits) wide initialization
 * vector(IV) shall be placed in the memory before calling this function. The
 * pointer where the decrypted text shall be written shall be large enough
 * to hold N*128-bits(4 * 32-bits) wide item. This function is implemented as
 * blocking call which means it returns not before the operation is finished.
 * After returning from this function the result data is already copied to the
 * destination buffer.
 * This function uses DMA facilities.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx and above
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in,out] au32CipherText Pointer to the memory where the N*128-Bits wide
 *                               cipher text is placed
 * @param[in] au32PlainText Pointer to the memory where the N*128-Bits wide
 *                            plain text should be written
 * @param[in] au32IV Pointer to the memory where the 128-Bit wide
 *                            Initialization Vector(IV) is placed
 * @param[in] u32N count of the 128-Bits wide items (max. 3FFFh:16383d)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32IV
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32CipherText
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_CmdDecCBCStream(const tsm_key_id_e eKeyId,
                             const uint32_t au32CipherText[],
                             const uint32_t au32PlainText[],
                             const uint32_t au32IV[4],
                             const uint32_t u32N);


/**
 * @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 using DMA
 *
 * eTSM_CmdDecCBCStream() shall use the supplied key to decrypt N*128-bits wide
 * plain text to N*128-bits wide encrypted text. The encrypted text
 * shall be N*128-bits(4 * 32-bits) wide and shall be placed in the memory
 * before calling this function. The 128-bits(4 * 32-bits) wide initialization
 * vector(IV) shall be placed in the memory before calling this function. The
 * pointer where the decrypted text shall be written shall be large enough
 * to hold N*128-bits(4 * 32-bits) wide item. The decrypted text shall be
 * available in memory as soon as the operation error code availability is
 * signaled by the TSM via an irq. Alternatively polling may be used to
 * check for error code availability. This function uses DMA facilities.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in,out] au32CipherText Pointer to the memory where the N*128-Bits wide
 *                               cipher text is placed
 * @param[in] au32PlainText Pointer to the memory where the N*128-Bits wide
 *                            plain text should be written
 * @param[in] au32IV Pointer to the memory where the 128-Bit wide
 *                            Initialization Vector(IV) is placed
 * @param[in] u32N count of the 128-Bits wide items (max. 3FFFh:16383d)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32IV
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32CipherText
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_CmdDecCBCStreamNoWait(const tsm_key_id_e eKeyId,
                             const uint32_t au32CipherText[],
                             const uint32_t au32PlainText[],
                             const uint32_t au32IV[4],
                             const uint32_t u32N);


/**
* @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 (non-blocking)
*
* eTSM_CmdDecCBCStreamCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdDecECBStream().
* It checks if the command previously triggered by eTSM_CmdDecCBCStreamNoWait()
* has been completed and retrieves the execution result.
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_EMPTY
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdDecCBCStream()
* @see eTSM_CmdDecCBCStreamNoWait()
*
*/
tsm_func_ret_e eTSM_CmdDecCBCStreamCheckResult(void);


/**
 * @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 using DMA
 *
 * eTSM_CmdGenerateMACStream()generates MAC using the specified key for the
 * message of a specified length. The message shall be N*128bits wide and
 * shall be placed in memory before calling this function.
 * This function is implemented as blocking call which means it returns not
 * before the operation is finished. After returning from this function the
 * result data (Mac) is already copied to the destination buffer.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in] au32Msg Pointer to the memory where the N*128-Bits wide message
 *                    is placed
 * @param[in] au32Mac Pointer to the memory where the128-Bits wide generated Mac should
 *            be stored
 * @param[in] u64MsgLen 64-Bit wide message length in bits is placed (max 1FFFE0h:2097120d)
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Msg
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32MAC
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_CmdGenerateMACStream(const tsm_key_id_e eKeyId,
                              const uint32_t au32Msg[],
                              const uint32_t au32Mac[4],
                              const uint64_t u64MsgLen);


/**
 * @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 using DMA
 *
 * eTSM_CmdGenerateMACStream()generates MAC using the specified key for the
 * message of a specified length. The message shall be N*128bits wide and
 * shall be placed in memory before calling this function.
 * The MAC shall be available in memory as soon as the operation error code
 * availability is signaled by the TSM via an irq. Alternatively
 * polling may be used to check for error code availability.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx and above
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in] au32Msg Pointer to the memory where the N*128-Bits wide message
 *                    is placed
 * @param[in] au32Mac Pointer to the memory where the128-Bits wide generated Mac should
 *            be stored
 * @param[in] u64MsgLen 64-Bit wide message length in bits is placed (max 1FFFE0h:2097120d)
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Msg
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32MAC
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_CmdGenerateMACStreamNoWait(const tsm_key_id_e eKeyId,
                              const uint32_t au32Msg[],
                              const uint32_t au32Mac[4],
                              const uint64_t u64MsgLen);


/**
* @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 (non-blocking)
*
* eTSM_CmdGenerateMACStreamCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdGenerateMACStream().
* It checks if the command previously triggered by eTSM_CmdGenerateMACStreamNoWait()
* has been completed and retrieves the execution result.
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_EMPTY
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdGenerateMACStream()
* @see eTSM_CmdGenerateMACStreamNoWait()
*
*/
tsm_func_ret_e eTSM_CmdGenerateMACStreamCheckResult(void);


/**
 * @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 using DMA
 *
 * eTSM_CmdVerifyMACStream() verifies for the specified message the provided
 * MAC against the computed MAC. The key that is supplied is used to compute
 * the MAC. The length of the message is specified as the number of bits.
 * This function is implemented as blocking call which means it returns not
 * before the operation is finished. After returning from this function the
 * result data (verification status) is already copied to the destination buffer.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx and above
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in] au32Msg Pointer to the memory where the N*128-Bits wide message
 *                    is placed
 * @param[in] u64MsgLen 64-Bit wide message length in bits (max 1FFFE0h:2097120d)
 * @param[in] au32MAC Pointer to the memory where the MAC 128-Bit
 *                    is placed
 * @param[in] u32MACLen length of the MAC in bits is placed
 * @param[in] peVerificationStatus Pointer to the memory where the
 *                        verification status should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Msg
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32MAC
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer peVerificationStatus
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_CmdVerifyMACStream(const tsm_key_id_e eKeyId,
                            const uint32_t au32Msg[],
                            const uint64_t u64MsgLen,
                            const uint32_t au32MAC[4],
                            const uint32_t u32MACLen,
                            tsm_mac_verification_status_e* const peVerificationStatus);


/**
 * @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 using DMA
 *
 * eTSM_CmdVerifyMACStream() verifies for the specified message the provided
 * MAC against the computed MAC. The key that is supplied is used to compute
 * the MAC. The length of the message is specified as the number of bits.
 * The verification status shall be available in memory as soon as the
 * operation error code availability is signaled by the TSM via an irq.
 * Alternatively polling may be used to check for error code availability.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx and above
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in] au32Msg Pointer to the memory where the N*128-Bits wide message
 *                    is placed
 * @param[in] u64MsgLen 64-Bit wide message length in bits (max 1FFFE0h:2097120d)
 * @param[in] au32MAC Pointer to the memory where the MAC 128-Bit
 *                    is placed
 * @param[in] u32MACLen length of the MAC in bits is placed
 * @param[in] peVerificationStatus Pointer to the memory where the
 *                        verification status should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Msg
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32MAC
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer peVerificationStatus
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_CmdVerifyMACStreamNoWait(const tsm_key_id_e eKeyId,
                            const uint32_t au32Msg[],
                            const uint64_t u64MsgLen,
                            const uint32_t au32MAC[4],
                            const uint32_t u32MACLen,
                            tsm_mac_verification_status_e* const peVerificationStatus);


/**
* @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 (non-blocking)
*
* eTSM_CmdVerifyMACStreamCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdVerifyMACStream().
* It checks if the command previously triggered by eTSM_CmdVerifyMACStreamNoWait()
* has been completed and retrieves the execution result.
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_EMPTY
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdVerifyMACStream()
* @see eTSM_CmdVerifyMACStreamNoWait()
*
*/
tsm_func_ret_e eTSM_CmdVerifyMACStreamCheckResult(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TSMAPI_REST_H */

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


