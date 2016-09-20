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
*   VERSION     : $Revision: 1.22 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSMAPI_REST_H
#define TSMAPI_REST_H
#include "tsmdefines.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * @brief Implementation of CMD_ENC_ECB as per SHE spec. chapter 7.1
 *
 * eTSM_CmdEncECB() shall use the supplied key to encrypt 128-bits wide
 * plain text to 128-bits wide encrypted text. The plain text to be encrypted
 * shall be 128-bits(4 * 32-bits) wide and shall be placed in the memory
 * before calling this function. The pointer where the encrypted text shall
 * be written shall be large enough to hold 128-bits(4 * 32-bits) wide item.
 * The encrypted text shall be available in memory as soon as the operation
 * error code availability is signaled by the TSM via an irq. Alternatively
 * polling may be used to check for error code availability.
 *
 *
 * @param[in] eKeyId key to be used for encryption
 * @param[in] au32PlainText Pointer to the memory where the 128-Bit wide
 *                          plain text is placed
 * @param[in,out] au32CipherText Pointer to the memory where the 128-Bit wide
 *                               cipher text should be written to
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText or au32CipherText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_CmdEncECB(const tsm_key_id_e eKeyId,
                         const uint32_t au32PlainText[4],
                         uint32_t au32CipherText[4]);

/**
 * @brief Implementation of CMD_ENC_ECB as per SHE spec. chapter 7.1 (non-blocking)
 *
 * eTSM_CmdEncECBNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdEncECB().
 * It triggers the command and provides input data without
 * actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdEncECBCheckResult()
 *
 * @param[in] eKeyId key to be used for encryption
 * @param[in] au32PlainText Pointer to the memory where the 128-Bit wide
 *                            plain text is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncECB()
 * @see eTSM_CmdEncECBCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdEncECBNoWait(const tsm_key_id_e eKeyId, const uint32_t au32PlainText[4]);

/**
 * @brief Implementation of CMD_ENC_ECB as per SHE spec. chapter 7.1 (non-blocking)
 *
 * eTSM_CmdEncECBCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdEncECB().
 * It checks if the command previously triggered by eTSM_CmdEncECBNoWait()
 * has been completed and retrieves the execution result and processing data.
 *
 * @param[in,out] au32CipherText Pointer to the memory where the 128-Bit wide
 *                               cipher text should be written
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32CipherText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncECB()
 * @see eTSM_CmdEncECBNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdEncECBCheckResult(uint32_t au32CipherText[4]);


/**
 * @brief Implementation of CMD_ENC_CBC(Step 1) as per SHE spec. chapter 7.2
 *
 * eTSM_CmdEncCBCInit() shall initialize the encryption engine of TSM
 * to work in CBC mode and provides the key and initialization vector
 * that shall be used for the rest of the CBC process.
 * Please note that the CBC process shall be complete only after a further N
 * successive calls to eTSM_CmdEncCBCUpdate() and eTSM_CmdEncCBCFinalize().
 *
 * @param[in] eKeyId key to be used for encryption
 * @param[in] au32IV Pointer to the memory where the 128-Bit wide
 *                            Initialization Vector(IV) is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32IV
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncCBCUpdate
 * @see eTSM_CmdEncCBCFinalize

 */

tsm_func_ret_e eTSM_CmdEncCBCInit(const tsm_key_id_e eKeyId,
                             const uint32_t au32IV[4]);

/**
 * @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 (non-blocking)
 *
 * eTSM_CmdEncCBCInitNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdEncCBCInit().
 * It triggers the command and provides input data without
 * actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdEncCBCInitCheckResult()
 *
 * @param[in] eKeyId key to be used for encryption
 * @param[in] au32IV Pointer to the memory where the 128-Bit wide
 *                            Initialization Vector(IV) is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32IV
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncCBCInit()
 * @see eTSM_CmdEncCBCInitCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdEncCBCInitNoWait(const tsm_key_id_e eKeyId,
                             const uint32_t au32IV[4]);

/**
* @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 (non-blocking)
*
* eTSM_CmdEncCBCInitCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdEncCBCInit().
* It checks if the command previously triggered by eTSM_CmdEncCBCInitNoWait()
* has been completed and retrieves the execution result.
*
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
* @see eTSM_CmdEncCBCInit()
* @see eTSM_CmdEncCBCInitNoWait()
*
*/
tsm_func_ret_e eTSM_CmdEncCBCInitCheckResult(void);

/**
 * @brief Implementation of CMD_ENC_CBC(Step 2) as per SHE spec. chapter 7.2
 *
 * eTSM_CmdEncCBCUpdate() shall provide N*128-bits(4 * 32-bits) wide
 * plain text to the encryption engine for encryption. The plain text to be
 * encrypted shall be N*128-bits(4 * 32-bits) wide and shall be placed in
 * the memory before calling this function. The pointer where the encrypted
 * text shall be written shall be large enough to hold N*128-bits(4 * 32-bits)
 * wide item.
 * The encrypted text shall be available in memory as soon as the operation
 * error code availability is signaled by the TSM via an irq. Alternatively
 * polling may be used to check for error code availability.
 * Please note that eTSM_CmdEncCBCInit() should be called before making
 * use of eTSM_CmdEncCBCUpdate(). The CBC process shall be complete only
 * after N successive calls to eTSM_CmdEncCBCUpdate() and
 * eTSM_CmdEncCBCFinalize().
 *
 * @param[in] au32PlainText Pointer to the memory where the N*128-Bit wide
 *                            plain text is placed
 * @param[in,out] au32CipherText Pointer to the memory where the N*128-Bit wide
 *                               cipher text should be written
 *
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText, au32CipherText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncCBCInit
 * @see eTSM_CmdEncCBCFinalize
 *
 */

tsm_func_ret_e eTSM_CmdEncCBCUpdate(const uint32_t au32PlainText[],
                         uint32_t au32CipherText[],
                         const uint32_t u32BlockSizeOf128Bits);

/**
 * @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 (non-blocking)
 *
 * eTSM_CmdEncCBCUpdateNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdEncCBCUpdate().
 * It triggers the command and provides input data without
 * actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdEncCBCUpdateCheckResult()
 *
 * @param[in] au32PlainText Pointer to the memory where the N*128-Bit wide
 *                            plain text is placed
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)*
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32PlainText
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncCBCUpdate()
 * @see eTSM_CmdEncCBCUpdateCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdEncCBCUpdateNoWait(const uint32_t au32PlainText[], const uint32_t u32BlockSizeOf128Bits);

/**
 * @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 (non-blocking)
 *
 * eTSM_CmdEncCBCUpdateCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdEncCBCUpdate().
 * It checks if the command previously triggered by eTSM_CmdEncCBCUpdateNoWait()
 * has been completed and retrieves the execution result and processing data.
 *
 * @param[in,out] au32CipherText Pointer to the memory where the N*128-Bit wide
 *                               cipher text should be written
 *
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32CipherText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR

 *
 * @see eTSM_CmdEncCBCUpdate()
 * @see eTSM_CmdEncCBCUpdateNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdEncCBCUpdateCheckResult(uint32_t au32CipherText[], const uint32_t u32BlockSizeOf128Bits);

/**
 * @brief Implementation of CMD_ENC_CBC(Step 3) as per SHE spec. chapter 7.2
 *
 * eTSM_CmdEncCBCFinalize() shall de-initialize the encryption engine of TSM
 * Please note that eTSM_CmdEncCBCUpdate() should be called appropriate number
 * of times before making use of eTSM_CmdEncCBCFinalize().
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncCBCInit
 * @see eTSM_CmdEncCBCUpdate
 *
 */

tsm_func_ret_e eTSM_CmdEncCBCFinalize(void);

/**
 * @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 (non-blocking)
 *
 * eTSM_CmdEncCBCFinalizeNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdEncCBCFinalize().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdEncCBCFinalizeCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdEncCBCFinalize()
 * @see eTSM_CmdEncCBCFinalizeCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdEncCBCFinalizeNoWait(void);

/**
* @brief Implementation of CMD_ENC_CBC as per SHE spec. chapter 7.2 (non-blocking)
*
* eTSM_CmdEncCBCFinalizeCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdEncCBCFinalize().
* It checks if the command previously triggered by eTSM_CmdEncCBCFinalizeNoWait()
* has been completed and retrieves the execution result.
*
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdEncCBCFinalize()
* @see eTSM_CmdEncCBCFinalizeNoWait()
*
*/
tsm_func_ret_e eTSM_CmdEncCBCFinalizeCheckResult(void);

/**
 * @brief Implementation of CMD_DEC_ECB as per SHE spec. chapter 7.3
 *
 * eTSM_CmdDecECB() shall use the supplied key to decrypt 128-bits wide
 * encrypted text to 128-bits wide plain text. The encrypted text
 * shall be 128-bits(4 * 32-bits) wide and shall be placed in the memory
 * before calling this function. The pointer where the plain text shall
 * be written shall be large enough to hold 128-bits(4 * 32-bits) wide item.
 * The decrypted text shall be available in memory as soon as the operation
 * error code availability is signaled by the TSM via an irq. Alternatively
 * polling may be used to check for error code availability.
 *
 *
 * @param[in] eKeyId key to be used for encryption
 * @param[in] au32CipherText Pointer to the memory where the 128-Bit wide
 *                            encrypted text is placed
 * @param[in,out] au32PlainText Pointer to the memory where the 128-Bit wide
 *                               decrypted text should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32CipherText, au32PlainText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdDecECB(const tsm_key_id_e eKeyId,
                         const uint32_t au32CipherText[4],
                         uint32_t au32PlainText[4]);

/**
 * @brief Implementation of CMD_DEC_ECB as per SHE spec. chapter 7.3 (non-blocking)
 *
 * eTSM_CmdDecECBNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdDecECB().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdDecECBCheckResult()
 *
 * @param[in] eKeyId key to be used for encryption
 * @param[in] au32CipherText Pointer to the memory where the 128-Bit wide
 *                            encrypted text is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32CipherText
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDecECB()
 * @see eTSM_CmdDecECBCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdDecECBNoWait(const tsm_key_id_e eKeyId, const uint32_t au32CipherText[4]);

/**
 * @brief Implementation of CMD_DEC_ECB as per SHE spec. chapter 7.3 (non-blocking)
 *
 * eTSM_CmdDecECBCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdDecECB().
 * It checks if the command previously triggered by eTSM_CmdDecECBNoWait()
 * has been completed and retrieves the execution result and processing data.
 *
 * @param[in,out] au32PlainText Pointer to the memory where the 128-Bit wide
 *                               decrypted text should be written
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDecECB()
 * @see eTSM_CmdDecECBNoWait()
 *
*/
tsm_func_ret_e eTSM_CmdDecECBCheckResult(uint32_t au32PlainText[4]);


/**
 * @brief Implementation of CMD_GENERATE_MAC(Step 1) as per SHE spec. chapter 7.5
 *
 * eTSM_CmdGenerateMACInit() shall initialize the MAC engine of TSM
 * and provides the key and message length in bits that shall be used
 * for the rest of the steps. Please note that the process shall be
 * complete only after a further N successive calls to eTSM_CmdGenerateMACUpdate()
 * and eTSM_CmdGenerateMACFinalize().
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in] u64MsgLen 64-Bit wide message length in bits is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdGenerateMACInit(const tsm_key_id_e eKeyId, const uint64_t u64MsgLen);

/**
 * @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 (non-blocking)
 *
 * eTSM_CmdGenerateMACInitNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdGenerateMACInit().
 * It triggers the command and provides input data without
 * actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdGenerateMACInitCheckResult()
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in] u64MsgLen 64-Bit wide message length in bits is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter u64MsgLen
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdGenerateMACInit()
 * @see eTSM_CmdGenerateMACInitCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdGenerateMACInitNoWait(const tsm_key_id_e eKeyId, const uint64_t u64MsgLen);

/**
 * @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 (non-blocking)
 *
 * eTSM_CmdGenerateMACInitCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdGenerateMACInit().
 * It checks if the command previously triggered by eTSM_CmdGenerateMACInitNoWait()
 * has been completed and retrieves the execution result.
 *
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
 * @see eTSM_CmdGenerateMACInit()
 * @see eTSM_CmdGenerateMACInitNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdGenerateMACInitCheckResult(void);

/**
 * @brief Implementation of CMD_GENERATE_MAC(Step 2) as per SHE spec. chapter 7.5
 *
 * eTSM_CmdGenerateMACUpdate() shall provide 128-bits(4 * 32-bits) wide
 * message fragments to the MAC generation.
 * Please note that eTSM_CmdGenerateMACInit() should be called before making
 * use of eTSM_CmdGenerateMACUpdate(). The CBC process shall be complete only
 * after N successive calls to eTSM_CmdGenerateMACUpdate() and
 * eTSM_CmdGenerateMACFinalize().
 *
 * @param[in] au32Msg Pointer to the memory where the 128-Bits wide message
 *                    is placed
 *
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Msg
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdGenerateMACUpdate(const uint32_t au32Msg[], const uint32_t u32BlockSizeOf128Bits);

/**
 * @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 (non-blocking)
 *
 * eTSM_CmdGenerateMACUpdateNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdGenerateMACUpdate().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdGenerateMACUpdateCheckResult()
 *
 * @param[in] au32Msg Pointer to the memory where the 128-Bits wide message
 *                    is placed
 *
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32Msg
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdGenerateMACUpdate()
 * @see eTSM_CmdGenerateMACUpdateCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdGenerateMACUpdateNoWait(const uint32_t au32Msg[], const uint32_t u32BlockSizeOf128Bits);

/**
* @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 (non-blocking)
*
* eTSM_CmdGenerateMACUpdateCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdGenerateMACUpdate().
* It checks if the command previously triggered by eTSM_CmdGenerateMACUpdateNoWait()
* has been completed and retrieves the execution result.
*
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdGenerateMACUpdate()
* @see eTSM_CmdGenerateMACUpdateNoWait()
*
*/
tsm_func_ret_e eTSM_CmdGenerateMACUpdateCheckResult(void);

/**
 * @brief Implementation of CMD_GENERATE_MAC(Step 3) as per SHE spec. chapter 7.5
 *
 * eTSM_CmdGenerateMACFinalize() shall de-initialize the decryption engine of TSM
 * Please note that eTSM_CmdGenerateMACUpdate() should be called appropraite
 * number of times before making use of eTSM_CmdGenerateMACFinalize().
 * The MAC shall be available in memory as soon as the operation error code
 * availability is signaled by the TSM via an irq. Alternatively
 * polling may be used to check for error code availability.
 *
 * @param[in,out] au32MAC Pointer to the memory where the MAC should be stored
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32MAC
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdGenerateMACFinalize(uint32_t au32MAC[4]);

/**
 * @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 (non-blocking)
 *
 * eTSM_CmdGenerateMACFinalizeNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdGenerateMACFinalize().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdGenerateMACFinalizeCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdGenerateMACFinalize()
 * @see eTSM_CmdGenerateMACFinalizeCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdGenerateMACFinalizeNoWait(void);

/**
* @brief Implementation of CMD_GENERATE_MAC as per SHE spec. chapter 7.5 (non-blocking)
 *
 * eTSM_CmdGenerateMACFinalizeCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdGenerateMACFinalize().
 * It checks if the command previously triggered by eTSM_CmdGenerateMACFinalizeNoWait()
 * has been completed and retrieves the execution result and processing data.
 *
 * @param[in,out] au32MAC Pointer to the memory where the MAC should be stored
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32MAC
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdGenerateMACFinalize()
* @see eTSM_CmdGenerateMACFinalizeNoWait()
*
*/
tsm_func_ret_e eTSM_CmdGenerateMACFinalizeCheckResult(uint32_t au32MAC[4]);


/**
 * @brief Implementation of CMD_VERIFY_MAC(Step 1) as per SHE spec. chapter 7.6
 *
 * eTSM_CmdVerifyMACInit() implements the first step of CMD_VERIFY_MAC.
 * This involves providing the Key id and the message length specified
 * as the number of bits.
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in] u64MsgLen 64-Bit wide message length in bits is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdVerifyMAC() for details
 * @see eTSM_CmdVerifyMACUpdate()
 * @see eTSM_CmdVerifyMACFinalize()
 *
 */

tsm_func_ret_e eTSM_CmdVerifyMACInit(const tsm_key_id_e eKeyId, const uint64_t u64MsgLen);

/**
 * @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 (non-blocking)
 *
 * eTSM_CmdVerifyMACInitNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdVerifyMACInit().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdVerifyMACInitCheckResult()
 *
 * @param[in] eKeyId key to be used for decryption
 * @param[in] u64MsgLen 64-Bit wide message length in bits is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdVerifyMACInit()
 * @see eTSM_CmdVerifyMACInitCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdVerifyMACInitNoWait(const tsm_key_id_e eKeyId, const uint64_t u64MsgLen);

/**
 * @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 (non-blocking)
 *
 * eTSM_CmdVerifyMACInitCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdVerifyMACInit().
 * It checks if the command previously triggered by eTSM_CmdVerifyMACInitNoWait()
 * has been completed and retrieves the execution result.
 *
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
* @see eTSM_CmdVerifyMACInit()
* @see eTSM_CmdVerifyMACInitNoWait()
*
*/
tsm_func_ret_e eTSM_CmdVerifyMACInitCheckResult(void);

/**
 * @brief Implementation of CMD_VERIFY_MAC(Step 2) as per SHE spec. chapter 7.6
 *
 * eTSM_CmdVerifyMACUpdate() implements the second step of CMD_VERIFY_MAC.
 * With this API one shall provide 128-bits wide message data in
 * a loop "n" times where n shall be calculated as follows: n =
 * (u64MsgLen/128) + ((u64MsgLen%128) == 0) ? 0 : 1
 *
 * @param[in] au32Msg Pointer to the memory where the 128-Bits wide message
 *                    is placed
 *
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Msg
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdVerifyMAC() for details
 * @see eTSM_CmdVerifyMACInit()
 * @see eTSM_CmdVerifyMACFinalize()
 *
 *
 */

tsm_func_ret_e eTSM_CmdVerifyMACUpdate(const uint32_t au32Msg[], const uint32_t u32BlockSizeOf128Bits);

/**
 * @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 (non-blocking)
 *
 * eTSM_CmdVerifyMACUpdateNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdVerifyMACUpdate().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdVerifyMACUpdateCheckResult()
 *
 * @param[in] au32Msg Pointer to the memory where the 128-Bits wide message
 *                    is placed
 *
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32Msg
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdVerifyMACUpdate()
 * @see eTSM_CmdVerifyMACUpdateCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdVerifyMACUpdateNoWait(const uint32_t au32Msg[], const uint32_t u32BlockSizeOf128Bits);

/**
* @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 (non-blocking)
*
* eTSM_CmdVerifyMACUpdateCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdVerifyMACUpdate().
* It checks if the command previously triggered by eTSM_CmdVerifyMACUpdateNoWait()
* has been completed and retrieves the execution result.
*
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdVerifyMACUpdate()
* @see eTSM_CmdVerifyMACUpdateNoWait()
*
*/
tsm_func_ret_e eTSM_CmdVerifyMACUpdateCheckResult(void);

/**
 * @brief Implementation of CMD_VERIFY_MAC(Step 3) as per SHE spec. chapter 7.6
 *
 * eTSM_CmdVerifyMACFinalize() implements the last(third) step of
 * CMD_VERIFY_MAC.
 *
 * @param[in] au32MAC Pointer to the memory where the MAC to be compared
 *                    is placed
 * @param[in] u32MACLen length of the MAC in bits is placed
 * @param[in,out] peVerificationStatus Pointer to the memory where the
 *                                       verification status should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32MAC, peVerificationStatus
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdVerifyMAC() for details
 * @see eTSM_CmdVerifyMACInit()
 * @see eTSM_CmdVerifyMACUpdate()
 *
 */

tsm_func_ret_e eTSM_CmdVerifyMACFinalize(const uint32_t au32MAC[4],
                                         const uint32_t u32MACLen,
                                         tsm_mac_verification_status_e* const peVerificationStatus);

/**
 * @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 (non-blocking)
 *
 * eTSM_CmdVerifyMACFinalizeNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdVerifyMACFinalize().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdVerifyMACFinalizeCheckResult()
 *
 * @param[in] au32MAC Pointer to the memory where the MAC to be compared
 *                    is placed
 * @param[in] u32MACLen length of the MAC in bits is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32MAC
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdVerifyMACFinalize()
 * @see eTSM_CmdVerifyMACFinalizeCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdVerifyMACFinalizeNoWait(const uint32_t au32MAC[4], const uint32_t u32MACLen);

/**
* @brief Implementation of CMD_VERIFY_MAC as per SHE spec. chapter 7.6 (non-blocking)
*
* eTSM_CmdVerifyMACFinalizeCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdVerifyMACFinalize().
* It checks if the command previously triggered by eTSM_CmdVerifyMACFinalizeNoWait()
* has been completed and retrieves the execution result and processing data.
*
* @param[in,out] peVerificationStatus Pointer to the memory where the
*                                       verification status should be written
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer peVerificationStatus
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdVerifyMACFinalize()
* @see eTSM_CmdVerifyMACFinalizeNoWait()
*
*/
tsm_func_ret_e eTSM_CmdVerifyMACFinalizeCheckResult(tsm_mac_verification_status_e* const peVerificationStatus);

/**
 * @brief Implementation of CMD_LOAD_KEY as per SHE spec. chapter 7.7
 *
 * eTSM_CmdLoadKey() updates an internal key of SHE. For details regarding
 * calculation of parameters M1, M2 and M3 please refer to
 * chapter 9.1 of the SHE specification.
 *
 * @note Do not use eTSM_CmdLoadKey() to update a key with trivial key value
 * set to "0..0"128 (all 128 bits set to zero). This special trivial key value
 * might lead to malfunction when making use of this key for certain cryptographic
 * operations as the operational output might become invalid/corrupt in this case.
 *
 * @param[in] au32M1 Pointer to the memory where 128-Bits wide message M1 is placed
 * @param[in] au32M2 Pointer to the memory where 256-Bits wide message M2 is placed
 * @param[in] au32M3 Pointer to the memory where 128-Bits wide message M3 is placed
 * @param[in,out] au32M4 Pointer to the memory where 256-Bits wide message M4 should be written
 * @param[in,out] au32M5 Pointer to the memory where 128-Bits wide message M5 should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32M1, au32M2, au32M3, au32M4, au32M5
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_WRITE_PROTECTED
 * @return TSM_FUNC_KEY_UPDATE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see chapter 9.1 Description of the memory update protocol of SHE specification
 *
 */

tsm_func_ret_e eTSM_CmdLoadKey(const uint32_t au32M1[4],
                          const uint32_t au32M2[8],
                          const uint32_t au32M3[4],
                          uint32_t au32M4[8],
                          uint32_t au32M5[4]);

/**
 * @brief Implementation of CMD_LOAD_KEY as per SHE spec. chapter 7.7 (non-blocking)
 *
 * eTSM_CmdLoadKeyNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdLoadKey().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdLoadKeyCheckResult()
 *
 * @param[in] au32M1 Pointer to the memory where 128-Bits wide message M1 is placed
 * @param[in] au32M2 Pointer to the memory where 256-Bits wide message M2 is placed
 * @param[in] au32M3 Pointer to the memory where 128-Bits wide message M3 is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32M1, au32M2, au32M3
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdLoadKey()
 * @see eTSM_CmdLoadKeyCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdLoadKeyNoWait(const uint32_t au32M1[4],
                          const uint32_t au32M2[8],
                          const uint32_t au32M3[4]);

/**
* @brief Implementation of CMD_LOAD_KEY as per SHE spec. chapter 7.7 (non-blocking)
*
* eTSM_CmdLoadKeyCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdLoadKey().
* It checks if the command previously triggered by eTSM_CmdLoadKeyNoWait()
* has been completed and retrieves the execution result and processing data.
*
* @param[in,out] au32M4 Pointer to the memory where 256-Bits wide message M4 should be written
* @param[in,out] au32M5 Pointer to the memory where 128-Bits wide message M5 should be written
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32M4, au32M5
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_WRITE_PROTECTED
* @return TSM_FUNC_KEY_UPDATE_ERROR
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_KEY_EMPTY
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdLoadKey()
* @see eTSM_CmdLoadKeyNoWait()
*
*/
tsm_func_ret_e eTSM_CmdLoadKeyCheckResult(uint32_t au32M4[8], uint32_t au32M5[4]);

/**
 * @brief Implementation of CMD_LOAD_PLAIN_KEY as per SHE spec. chapter 7.8
 *
 * A 128-bits wide key placed at au32Key is loaded without encryption and
 * verification of the key, i.e. the key is handed over in plaintext to
 * be loaded into the RAM_KEY slot.
 *
 * @param[in] au32Key Pointer to the memory where 128-Bits wide key is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Key
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdLoadPlainKey(const uint32_t au32Key[4]);

/**
 * @brief Implementation of CMD_LOAD_PLAIN_KEY as per SHE spec. chapter 7.8 (non-blocking)
 *
 * eTSM_CmdLoadPlainKeyNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdLoadPlainKey().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdLoadPlainKeyCheckResult()
 *
 * @param[in] au32Key Pointer to the memory where 128-Bits wide key is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32Key
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdLoadPlainKey()
 * @see eTSM_CmdLoadPlainKeyCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdLoadPlainKeyNoWait(const uint32_t au32Key[4]);

/**
* @brief Implementation of CMD_LOAD_PLAIN_KEY as per SHE spec. chapter 7.8 (non-blocking)
*
* eTSM_CmdLoadPlainKeyCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdLoadPlainKey().
* It checks if the command previously triggered by eTSM_CmdLoadPlainKeyNoWait()
* has been completed and retrieves the execution result.
*
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdLoadPlainKey()
* @see eTSM_CmdLoadPlainKeyNoWait()
*
*/

tsm_func_ret_e eTSM_CmdLoadPlainKeyCheckResult(void);

/**
 * @brief Implementation of CMD_EXPORT_RAM_KEY as per SHE spec. chapter 7.9
 *
 * eTSM_CmdExportRAMKey() exports the RAM_KEY into a format protected
 * by SECRET_KEY. A RAM_KEY can only be exported if it was written into
 * SHE in plaintext.
 *
 * @param[in,out] au32M1 Pointer to the memory where 128-Bits wide message M1 should be written
 * @param[in,out] au32M2 Pointer to the memory where 256-Bits wide message M2 should be written
 * @param[in,out] au32M3 Pointer to the memory where 128-Bits wide message M3 should be written
 * @param[in,out] au32M4 Pointer to the memory where 256-Bits wide message M4 should be written
 * @param[in,out] au32M5 Pointer to the memory where 128-Bits wide message M5 should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32M1, au32M2, au32M3, au32M4, au32M5
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdExportRAMKey(uint32_t au32M1[4],
                               uint32_t au32M2[8],
                               uint32_t au32M3[4],
                               uint32_t au32M4[8],
                               uint32_t au32M5[4]);

/**
 * @brief Implementation of CMD_EXPORT_RAM_KEY as per SHE spec. chapter 7.9 (non-blocking)
 *
 * eTSM_CmdExportRAMKeyNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdExportRAMKey().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdExportRAMKeyCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdExportRAMKey()
 * @see eTSM_CmdExportRAMKeyCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdExportRAMKeyNoWait(void);

/**
* @brief Implementation of CMD_EXPORT_RAM_KEY as per SHE spec. chapter 7.9 (non-blocking)
*
* eTSM_CmdExportRAMKeyCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdExportRAMKey().
* It checks if the command previously triggered by eTSM_CmdExportRAMKeyNoWait()
* has been completed and retrieves the execution result and processing data.
*
* @param[in,out] au32M1 Pointer to the memory where 128-Bits wide message M1 should be written
* @param[in,out] au32M2 Pointer to the memory where 256-Bits wide message M2 should be written
* @param[in,out] au32M3 Pointer to the memory where 128-Bits wide message M3 should be written
* @param[in,out] au32M4 Pointer to the memory where 256-Bits wide message M4 should be written
* @param[in,out] au32M5 Pointer to the memory where 128-Bits wide message M5 should be written
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32M1, au32M2, au32M3, au32M4, au32M5
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_KEY_EMPTY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdExportRAMKey()
* @see eTSM_CmdExportRAMKeyNoWait()
*
*/
tsm_func_ret_e eTSM_CmdExportRAMKeyCheckResult(uint32_t au32M1[4],
                               uint32_t au32M2[8],
                               uint32_t au32M3[4],
                               uint32_t au32M4[8],
                               uint32_t au32M5[4]);

/**
 * @brief Implementation of CMD_INIT_RNG as per SHE spec. chapter 7.10
 *
 * eTSM_CmdInitRNG() initializes the seed and derives a key for the PRNG.
 * This function must be called before eTSM_CmdRnd() after every power
 * cycle/reset.
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see Chapter 5.1.1 or Chapter 5.1.2 of SHE specification
 *
 */

tsm_func_ret_e eTSM_CmdInitRNG(void);

/**
 * @brief Implementation of CMD_INIT_RNG as per SHE spec. chapter 7.10 (non-blocking)
 *
 * eTSM_CmdInitRNGNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdInitRNG().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdInitRNGCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdInitRNG()
 * @see eTSM_CmdInitRNGCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdInitRNGNoWait(void);

/**
 * @brief Implementation of CMD_INIT_RNG as per SHE spec. chapter 7.10 (non-blocking)
 *
 * eTSM_CmdInitRNGCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdInitRNG().
 * It checks if the command previously triggered by eTSM_CmdInitRNGNoWait()
 * has been completed and retrieves the execution result.
 *
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdInitRNG()
 * @see eTSM_CmdInitRNGNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdInitRNGCheckResult(void);

/**
 * @brief Implementation of CMD_EXTEND_SEED as per SHE spec. chapter 7.11
 *
 * eTSM_CmdExtendSeed() extends the seed of the PRNG by compressing
 * the former seed value and the supplied 128-bits wide entropy into a new seed
 * which will be used to generate the following random numbers via call
 * to eTSM_CmdRnd().
 *
 * @param[in] au32Entropy Pointer to the memory where 128-Bits wide entropy value
 *                        is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_RNG_SEED
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Entropy
 *
 */

tsm_func_ret_e eTSM_CmdExtendSeed(const uint32_t au32Entropy[4]);

/**
 * @brief Implementation of CMD_EXTEND_SEED as per SHE spec. chapter 7.11 (non-blocking)
 *
 * eTSM_CmdExtendSeedNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdExtendSeed().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdExtendSeedCheckResult()
 *
 * @param[in] au32Entropy Pointer to the memory where 128-Bits wide entropy value
 *                        is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32Entropy
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdExtendSeed()
 * @see eTSM_CmdExtendSeedCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdExtendSeedNoWait(const uint32_t au32Entropy[4]);

/**
* @brief Implementation of CMD_EXTEND_SEED as per SHE spec. chapter 7.11 (non-blocking)
*
* eTSM_CmdExtendSeedCheckResult() provides the 2'nd stage (non-blocking) variant
* of the blocking eTSM_CmdExtendSeed().
* It checks if the command previously triggered by eTSM_CmdExtendSeedNoWait()
* has been completed and retrieves the execution result.
*
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR
* @return TSM_FUNC_RNG_SEED
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see eTSM_CmdExtendSeed()
* @see eTSM_CmdExtendSeedNoWait()
*
*/
tsm_func_ret_e eTSM_CmdExtendSeedCheckResult(void);

/**
 * @brief Implementation of CMD_RND as per SHE spec. chapter 7.12
 *
 * eTSM_CmdRnd() returns a 128-bits wide random number. eTSM_CmdInitRNG()
 * has to be called before any call to eTSM_CmdRnd().
 *
 * @param[in,out] au32Rnd Pointer to the memory where 128-Bits wide random
 *                        value should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Rnd
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_RNG_SEED
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdRnd(uint32_t au32Rnd[4]);

/**
 * @brief Implementation of CMD_RND as per SHE spec. chapter 7.12 (non-blocking)
 *
 * eTSM_CmdRndNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdRnd().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdRndCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdRnd()
 * @see eTSM_CmdRndCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdRndNoWait(void);

/**
 * @brief Implementation of CMD_RND as per SHE spec. chapter 7.12 (non-blocking)
 *
 * eTSM_CmdRndCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdRnd().
 * It checks if the command previously triggered by eTSM_CmdRndNoWait()
 * has been completed and retrieves the execution result and processing data.
 *
 * @param[in,out] au32Rnd Pointer to the memory where 128-Bits wide random
 *                        value should be written
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Rnd
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_RNG_SEED
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdRnd()
 * @see eTSM_CmdRndNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdRndCheckResult(uint32_t au32Rnd[4]);


/**
 * @brief Implementation of CMD_BOOT_OK as per SHE spec. chapter 7.15
 *
 * The command is used to mark successful boot verification for later stages
 * than CMD_SECURE_BOOT. In particular it is meant to lock the command
 * CMD_BOOT_FAILURE.
 *
 * @note If the secure booting is segmented into several stages and SHE does
 * only provide the first, autonomous stage, this function can be used during
 * the following stages, to provide the boot status to SHE.
 *
 * @note shall be called only once after power cycle/reset by the initial
 * program loader. It may only be called if CMD_SECURE_BOOT did not detect
 * any errors before and if CMD_BOOT_FAILURE was not called.
 * In case called a second time shall signal appropriate error return code.
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_NO_SECURE_BOOT
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_CmdBootOK(void);

/**
 * @brief Implementation of CMD_BOOT_OK as per SHE spec. chapter 7.15 (non-blocking)
 *
 * eTSM_CmdBootOKNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdBootOK().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdBootOKCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdBootOK()
 * @see eTSM_CmdBootOKCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdBootOKNoWait(void);

/**
 * @brief Implementation of CMD_BOOT_OK as per SHE spec. chapter 7.15 (non-blocking)
 *
 * eTSM_CmdBootOKCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdBootOK().
 * It checks if the command previously triggered by eTSM_CmdBootOKNoWait()
 * has been completed and retrieves the execution result.
 *
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_NO_SECURE_BOOT
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdBootOK()
 * @see eTSM_CmdBootOKNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdBootOKCheckResult(void);

/**
 * @brief Implementation of CMD_GET_ID as per SHE spec. chapter 7.17
 *
 * eTSM_CmdGetID() returns the identity (UID) and the value of the
 * status register protected by a MAC over a challenge and the data.
 * If MASTER_ECU_KEY is empty, the returned MAC has to be set to 0.
 *
 * @param[in]     au32Challenge Pointer to the memory where challenge is stored
 * @param[in,out] au32ID Pointer to the memory where 120-bits wide ID has
 *                       to be stored
 * @param[in,out] pu8SREG Pointer to the memory where status has to be stored
 * @param[in,out] au32MAC Pointer to the memory where the MAC should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Challenge, au32ID, pu8SREG, au32MAC
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdGetID(const uint32_t au32Challenge[4],
                        uint32_t au32ID[4],
                        uint8_t*  const pu8SREG,
                        uint32_t au32MAC[4]);

/**
 * @brief Implementation of CMD_GET_ID as per SHE spec. chapter 7.17 (non-blocking)
 *
 * eTSM_CmdGetIDNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdGetID().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdGetIDCheckResult()
 *
 * @param[in]     au32Challenge Pointer to the memory where challenge is stored
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32Challenge
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdGetID()
 * @see eTSM_CmdGetIDCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdGetIDNoWait(const uint32_t au32Challenge[4]);

/**
 * @brief Implementation of CMD_GET_ID as per SHE spec. chapter 7.17 (non-blocking)
 *
 * eTSM_CmdGetIDCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdGetID().
 * It checks if the command previously triggered by eTSM_CmdGetIDNoWait()
 * has been completed and retrieves the execution result and processing data.
 *
 * @param[in,out] au32ID Pointer to the memory where 120-bits wide ID has
 *                       to be stored
 * @param[in,out] pu8SREG Pointer to the memory where status has to be stored
 * @param[in,out] au32MAC Pointer to the memory where the MAC should be written
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32ID, pu8SREG, au32MAC
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdGetID()
 * @see eTSM_CmdGetIDNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdGetIDCheckResult(uint32_t au32ID[4], uint8_t* const pu8SREG, uint32_t au32MAC[4]);

/**
 * @brief Implementation of CMD_CANCEL as per SHE spec. chapter 7.18
 *
 * eTSM_CmdCancel() is used to cancel an operation that was started
 * before.
 *
 * @note Cancelling an operation started before could lead to race
 * conditions due to the fact that checking the status for being busy
 * and delivering a cancel is not atomic and the possibility that the
 * operation to be cancelled is already finished at the time of issuing
 * the cancel.
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */

tsm_func_ret_e eTSM_CmdCancel(void);

/**
 * @brief Implementation of CMD_CANCEL as per SHE spec. chapter 7.18 (non-blocking)
 *
 * eTSM_CmdCancelNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdCancel().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdCancelCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdCancel()
 * @see eTSM_CmdCancelCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdCancelNoWait(void);

/**
 * @brief Implementation of CMD_CANCEL as per SHE spec. chapter 7.18 (non-blocking)
 *
 * eTSM_CmdCancelCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdCancel().
 * It checks if the command previously triggered by eTSM_CmdCancelNoWait()
 * has been completed and retrieves the execution result.
 *
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdCancel()
 * @see eTSM_CmdCancelNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdCancelCheckResult(void);

/**
 * @brief Implementation of CMD_DEBUG (STEP1) as per SHE spec. chapter 7.19
 *
 * eTSM_CmdDebugInit() implements the first step of CMD_DEBUG and provides
 * a 128 bit challenge value to the application. The cmd CMD_DEBUG is used
 * to activate any internal debugging facilities of TSM. Activating the
 * internal debugger implies the deletion of all keys except SECRET_KEY,
 * UID and PRNG_SEED. For TMPR460/61XBG-300 these keys are not deleted in the
 * OTP memory and can be used again after a POR. For TMPR462/63XBG-300 the cmd will
 * only work, if no key is write-protected. Active debugger protection and
 * secure boot protection flags as well as empty keys are ignored.
 * After successful authentication and deletion of all keys, the bit RND_INIT
 * in status register is reset to 0.
 *
 * @note For TMPR462/63XBG-300 the command can also be used to reset TSM to the factory
 * defaults if no key is write protected.
 *
 * @param[in,out] au32Challenge Pointer to the memory where 128-Bits wide
 *                              challenge should be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Challenge
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_WRITE_PROTECTED
 * @return TSM_FUNC_RNG_SEED
 * @return TSM_FUNC_NO_DEBUGGING
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see chapter 11 of the SHE specification
 *
 */
tsm_func_ret_e eTSM_CmdDebugInit(uint32_t au32Challenge[4]);

/**
 * @brief Implementation of CMD_DEBUG as per SHE spec. chapter 7.19 (non-blocking)
 *
 * eTSM_CmdDebugInitNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdDebugInit().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdDebugInitCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDebugInit()
 * @see eTSM_CmdDebugInitCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdDebugInitNoWait(void);

/**
 * @brief Implementation of CMD_DEBUG as per SHE spec. chapter 7.19 (non-blocking)
 *
 * eTSM_CmdDebugInitCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdDebugInit().
 * It checks if the command previously triggered by eTSM_CmdDebugInitNoWait()
 * has been completed and retrieves the execution result and processing data.
 *
 * @param[in,out] au32Challenge Pointer to the memory where 128-Bits wide
 *                              challenge should be written
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Challenge
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_WRITE_PROTECTED
 * @return TSM_FUNC_RNG_SEED
 * @return TSM_FUNC_NO_DEBUGGING
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDebugInit()
 * @see eTSM_CmdDebugInitNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdDebugInitCheckResult(uint32_t au32Challenge[4]);


/**
 * @brief Implementation of CMD_DEBUG (STEP2) as per SHE spec. chapter 7.19
 *
 * eTSM_CmdDebugFinalize() implements the finalize step of CMD_DEBUG and
 * provides a 128-Bits value for authorization. The CMD_DEBUG is used to activate
 * any internal debugging facilities of TSM. Activating the internal debugger
 * implies the deletion of all keys except SECRET_KEY, UID and PRNG_SEED.
 * For TMPR460/61XBG-300 these keys are not deleted in the OTP memory and can
 * be used again after a POR. For TMPR462/63XBG-300 the cmd will only work, if no key
 * is write-protected. Active debugger protection and secure boot protection
 * flags as well as empty keys are ignored. After successful authentication
 * and deletion of all keys, the bit RND_INIT in status register is reset to 0.
 *
 * @note For TMPR462/63XBG-300 the command can also be used to reset TSM to the factory
 * defaults if no key is writeprotected.
 *
 * @param[in] au32Authorization Pointer to the memory where 128-Bits wide
 *                              authorization will be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32Authorization
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see chapter 11 of the SHE specification
 *
 */
tsm_func_ret_e eTSM_CmdDebugFinalize(const uint32_t au32Authorization[4]);

/**
 * @brief Implementation of CMD_DEBUG as per SHE spec. chapter 7.19 (non-blocking)
 *
 * eTSM_CmdDebugFinalizeNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdDebugFinalize().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdDebugFinalizeCheckResult()
 *
 * @param[in] au32Authorization Pointer to the memory where 128-Bits wide
 *                              authorization will be written
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32Authorization
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDebugFinalize()
 * @see eTSM_CmdDebugFinalizeCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdDebugFinalizeNoWait(const uint32_t au32Authorization[4]);

/**
 * @brief Implementation of CMD_DEBUG as per SHE spec. chapter 7.19 (non-blocking)
 *
 * eTSM_CmdDebugFinalizeCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdDebugFinalize().
 * It checks if the command previously triggered by eTSM_CmdDebugFinalizeNoWait()
 * has been completed and retrieves the execution result.
 *
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDebugFinalize()
 * @see eTSM_CmdDebugFinalizeNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdDebugFinalizeCheckResult(void);

/**
 * @brief provides the TSM Version number
 *
 * eTSM_GetTsmVersion() provides the version numbers of TSM module and TSM driver.
 * The major TSM number matches the TSM module version (#1,#2,#3..) number
 * and the minor TSM number matches subversion of TSM module.
 * The major driver number matches the driver release major number
 * and the driver minor number matches subversion.
 * This feature is only available for TSM module version #3 and above.
 *
 * @param[in] pu16TsmMajorVersion    pointer to store the Tsm Major number
 * @param[in] pu16TsmMinorVersion    pointer to store the Tsm Minor number
 * @param[in] pu16TsmDrvMajorVersion pointer to store the Tsm Driver Major number
 * @param[in] pu16TsmDrvMinorVersion pointer to store the Tsm Driver Minor number
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM
 * @return TSM_FUNC_GENERAL_ERROR
 *
 */
tsm_func_ret_e eTSM_GetTsmVersion(uint16_t * const pu16TsmMajorVersion, uint16_t * const pu16TsmMinorVersion,
                                  uint16_t * const pu16TsmDrvMajorVersion, uint16_t * const pu16TsmDrvMinorVersion);

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


