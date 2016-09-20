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
*   VERSION     : $Revision: 1.23 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSMAPI_COMMON_H
#define TSMAPI_COMMON_H
#include "tsmdefines.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * @mainpage TSM API
 * This section describes the API for the Toshiba CR4 TSM software driver.
 *
 * @section sec_intro Introduction
 * This documentation covers extended information to the TMPR46x-300 Data Book.
 * It provides details about how to make use of the Toshiba Security Hardware Module (TSM)
 * from within a customer's secondary boot loader, or from software application point of view.
 *
 * As described in the Data Book the communication between Cortex R4 CPU and the TSM is
 * realized by a dedicated hardware interface, called Access Port (AP).
 *
 * Toshiba has developed a TSM API Software Driver, which incorporates the required
 * communication flow between Cortex R4 CPU and the TSM making use of the AP.
 * The driver has an easy to use, well defined API.
 *
 * All API functions can be executed as blocking (synchronous) and
 * none blocking (asynchronous) operation. For a blocking operation the API function does not
 * return until the TSM has finished the task. In the opposite, the none blocking operation
 * sets only the command and data and returns immediately.
 *
 * @section sec_disclaim Disclaimer
 * RESTRICTIONS ON PRODUCT USE
 * Toshiba Corporation, and its subsidiaries and affiliates (collectively "TOSHIBA"),
 * reserve the right to make changes to the information in this document, and related hardware,
 * software and systems (collectively "Product") without notice.
 *
 * This document and any information herein may not be reproduced without prior written
 * permission from TOSHIBA. Even with TOSHIBA's written permission, reproduction is permissible
 * only if reproduction is without alteration/omission.
 *
 * Though TOSHIBA works continually to improve Product's quality and reliability,
 * Product can malfunction or fail. Customers are responsible for complying with safety standards
 * and for providing adequate designs and safeguards for their hardware, software and systems
 * which minimize risk and avoid situations in which a malfunction or failure of Product could
 * cause loss of human life, bodily injury or damage to property, including data loss or corruption.
 * Before customers use the Product, create designs including the Product, or incorporate the
 * Product into their own applications, customers must also refer to and comply with (a) the latest
 * versions of all relevant TOSHIBA information, including without limitation, this document,
 * the specifications, the data sheets and application notes for Product and the precautions and
 * conditions set forth in the "TOSHIBA Semiconductor Reliability Handbook" and (b) the instructions
 * for the application with which the Product will be used with or for.
 * Customers are solely responsible for all aspects of their own product design or applications,
 * including but not limited to (a) determining the appropriateness of the use of this Product
 * in such design or applications; (b) evaluating and determining the applicability of any information
 * contained in this document, or in charts, diagrams, programs, algorithms, sample application circuits,
 * or any other referenced documents; and (c) validating all operating parameters for such designs
 * and applications. TOSHIBA ASSUMES NO LIABILITY FOR CUSTOMERS' PRODUCT DESIGN OR APPLICATIONS.
 *
 * PRODUCT IS NEITHER INTENDED NOR WARRANTED FOR USE IN EQUIPMENTS OR SYSTEMS THAT REQUIRE
 * EXTRAORDINARILY HIGH LEVELS OF QUALITY AND/OR RELIABILITY, AND/OR A MALFUNCTION OR FAILURE
 * OF WHICH MAY CAUSE LOSS OF HUMAN LIFE, BODILY INJURY, SERIOUS PROPERTY DAMAGE AND/OR SERIOUS PUBLIC
 * IMPACT ("UNINTENDED USE"). Except for specific applications as expressly stated in this document,
 * Unintended Use includes, without limitation, equipment used in nuclear facilities, equipment used
 * in the aerospace industry, medical equipment, equipment used for automobiles, trains, ships and other
 * transportation, traffic signaling equipment, equipment used to control combustions or explosions,
 * safety devices, elevators and escalators, devices related to electric power, and equipment used in
 * finance-related fields. IF YOU USE PRODUCT FOR UNINTENDED USE, TOSHIBA ASSUMES NO LIABILITY FOR PRODUCT.
 * For details, please contact your TOSHIBA sales representative.
 *
 * Do not disassemble, analyze, reverse-engineer, alter, modify, translate or copy Product,
 * whether in whole or in part.
 *
 * Product shall not be used for or incorporated into any products or systems whose manufacture, use,
 * or sale is prohibited under any applicable laws or regulations.
 *
 * The information contained herein is presented only as guidance for Product use. No responsibility is
 * assumed by TOSHIBA for any infringement of patents or any other intellectual property rights of third
 * parties that may result from the use of Product. No license to any intellectual property right is
 * granted by this document, whether express or implied, by estoppel or otherwise.
 *
 * ABSENT A WRITTEN SIGNED AGREEMENT, EXCEPT AS PROVIDED IN THE RELEVANT TERMS AND CONDITIONS OF SALE
 * FOR PRODUCT, AND TO THE MAXIMUM EXTENT ALLOWABLE BY LAW, TOSHIBA (1) ASSUMES NO LIABILITY WHATSOEVER,
 * INCLUDING WITHOUT LIMITATION, INDIRECT, CONSEQUENTIAL, SPECIAL, OR INCIDENTAL DAMAGES OR LOSS,
 * INCLUDING WITHOUT LIMITATION, LOSS OF PROFITS, LOSS OF OPPORTUNITIES, BUSINESS INTERRUPTION AND LOSS
 * OF DATA, AND (2) DISCLAIMS ANY AND ALL EXPRESS OR IMPLIED WARRANTIES AND CONDITIONS RELATED TO SALE,
 * USE OF PRODUCT, OR INFORMATION, INCLUDING WARRANTIES OR CONDITIONS OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, ACCURACY OF INFORMATION, OR NONINFRINGEMENT.
 *
 * Do not use or otherwise make available Product or related software or technology for any military purposes,
 * including without limitation, for the design, development, use, stockpiling or manufacturing of nuclear,
 * chemical, or biological weapons or missile technology products (mass destruction weapons).
 * Product and related software and technology may be controlled under the applicable export laws
 * and regulations including, without limitation, the Japanese Foreign Exchange and Foreign Trade Law and
 * the U.S. Export Administration Regulations. Export and re-export of Product or related software or
 * technology are strictly prohibited except in compliance with all applicable export laws and regulations.
 *
 * Please contact your TOSHIBA sales representative for details as to environmental matters such as the
 * RoHS compatibility of Product. Please use Product in compliance with all applicable laws and regulations
 * that regulate the inclusion or use of controlled substances, including without limitation,
 * the EU RoHS Directive. TOSHIBA ASSUMES NO LIABILITY FOR DAMAGES OR LOSSES OCCURRING AS A RESULT OF
 * NONCOMPLIANCE WITH APPLICABLE LAWS AND REGULATIONS.
 *
*/


/**
 * @brief check for available ERC code after making a non blocking call to any TSM API and retrieve
 * the expected amount of processing data in case ERC code is available
 *
 * This API can be used by application in order to check for the resulting ERC after making a non-bocking
 * asynchrouns call to TSM APIs and to translate the ERC into TSM API return codes
 *
 * The amount of expected processing data, which depends on the asynchronous command previously triggered
 * has to be passed to the function.
 *
 * The pointer to the memory where the the processing data should be written to must be passed to
 * the function in case the expected amount of processing data is not equal to 0.
 *
 * @param[in]     u32N           data chunk size in number of 128-bit blocks
 *                               per update for FiFo usage (min: 0, max: 128)
 * @param[in,out] au32OutData    pointer to the memory where the u32N number of 128-bit blocks of
 *                               processing data should be written to
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR on success
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_NOT_AVAILABLE
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_NO_SECURE_BOOT
 * @return TSM_FUNC_KEY_WRITE_PROTECTED
 * @return TSM_FUNC_KEY_UPDATE_ERROR
 * @return TSM_FUNC_RNG_SEED
 * @return TSM_FUNC_NO_DEBUGGING
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_GENERAL_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_INTERNAL
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid parameters
 *
 */
 tsm_func_ret_e eTSM_CheckForErcGetData(uint32_t au32OutData[], const uint32_t u32N);

 /**
  * @brief check for available ERC code after making a non blocking call to any TSM API and retrieve
  * the expected 128-bit amount of processing data in case ERC code is available
  *
  * This API can be used by application in order to check for the resulting ERC after making a non-bocking
  * asynchrouns call to TSM APIs and to translate the ERC into TSM API return codes
  *
  * The pointer to the memory where the the processing data should be written to must be passed to
  * the function.
  *
  * @param[in,out] au32OutData    pointer to the memory where the 128-bit block of
  *                               processing data should be written to
  *
  * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
  * @return TSM_FUNC_NO_ERROR on success
  * @return TSM_FUNC_SEQUENCE_ERROR
  * @return TSM_FUNC_KEY_NOT_AVAILABLE
  * @return TSM_FUNC_KEY_INVALID
  * @return TSM_FUNC_KEY_EMPTY
  * @return TSM_FUNC_NO_SECURE_BOOT
  * @return TSM_FUNC_KEY_WRITE_PROTECTED
  * @return TSM_FUNC_KEY_UPDATE_ERROR
  * @return TSM_FUNC_RNG_SEED
  * @return TSM_FUNC_NO_DEBUGGING
  * @return TSM_FUNC_BUSY
  * @return TSM_FUNC_MEMORY_FAILURE
  * @return TSM_FUNC_GENERAL_ERROR
  * @return TSM_FUNC_GENERAL_ERROR_INTERNAL
  * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid parameter
  *
  */
  tsm_func_ret_e eTSM_CheckForErcGetData_4Words(uint32_t au32OutData[]);

 /**
 * @brief poll for ERC code after making a non blocking call to any TSM API and retrieve
 * the expected amount of processing data
 *
 * This API can be used by application in order to wait for the resulting ERC after making a non-bocking
 * asynchrouns call to TSM APIs and to translate the ERC into TSM API return codes
 *
 * The amount of expected processing data which depends on the asynchronous command previously triggered
 * has to be passed to the function.
 *
 * The pointer to the memory where the the processing data should be written to must be passed to
 * the function in case the expected amount of processing data is not equal to 0.
 *
 * @param[in]     u32N           data chunk size in number of 128-bit blocks
 *                               per update for FiFo usage (min: 0, max: 128)
 * @param[in,out] au32OutData    pointer to the memory where the u32N number of 128-bit blocks of
 *                               processing data should be written to
 *
 * @return TSM_FUNC_NO_ERROR on success
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_NOT_AVAILABLE
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_NO_SECURE_BOOT
 * @return TSM_FUNC_KEY_WRITE_PROTECTED
 * @return TSM_FUNC_KEY_UPDATE_ERROR
 * @return TSM_FUNC_RNG_SEED
 * @return TSM_FUNC_NO_DEBUGGING
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_GENERAL_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_INTERNAL
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid parameters
 *
 */
 tsm_func_ret_e eTSM_PollForErcGetData(uint32_t au32OutData[], const uint32_t u32N);

/**
* @brief check for ERC code after making a non blocking call to any TSM API
*
* This API can be used by application in order to check if a resulting ERC after making a non-blocking
* asynchrouns call to TSM APIs is available. The API also translates the ERC into TSM API return codes.
*
* @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL the resulting ERC is not available yet
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_KEY_NOT_AVAILABLE
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_EMPTY
* @return TSM_FUNC_NO_SECURE_BOOT
* @return TSM_FUNC_KEY_WRITE_PROTECTED
* @return TSM_FUNC_KEY_UPDATE_ERROR
* @return TSM_FUNC_RNG_SEED
* @return TSM_FUNC_NO_DEBUGGING
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_GENERAL_ERROR
* @return TSM_FUNC_GENERAL_ERROR_INTERNAL
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid parameters
*
*/
tsm_func_ret_e eTSM_CheckForErc(void);

/**
* @brief poll for ERC code after making a non blocking call to any TSM API
*
* This API can be used by application in order to wait for the resulting ERC after making a non-blocking
* asynchrouns call to TSM APIs. The API also translates the ERC into TSM API return codes
*
*
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_KEY_NOT_AVAILABLE
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_EMPTY
* @return TSM_FUNC_NO_SECURE_BOOT
* @return TSM_FUNC_KEY_WRITE_PROTECTED
* @return TSM_FUNC_KEY_UPDATE_ERROR
* @return TSM_FUNC_RNG_SEED
* @return TSM_FUNC_NO_DEBUGGING
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_GENERAL_ERROR
* @return TSM_FUNC_GENERAL_ERROR_INTERNAL
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid parameters
*
*/

tsm_func_ret_e eTSM_PollForErc (void);

/**
* @brief Implementation of CMD_DEC_CBC(Step 1) as per SHE spec. chapter 7.4
*
* eTSM_CmdDecCBCInit() shall initialize the decryption engine of TSM
* to work in CBC mode and provides the key-ID and initialization vector
* that shall be used for the rest of the CBC process.
* Please note that the CBC process shall be complete only after a further N
* successive calls to eTSM_CmdDecCBCUpdate() and eTSM_CmdDecCBCFinalize().
*
* @param[in] eKeyId key-ID to be used for decryption
* @param[in] au32IV Pointer to the memory where the 128-Bit wide
*                            Initialization Vector(IV) is placed
*
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32IV
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_INVALID
* @return TSM_FUNC_KEY_EMPTY
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
*/

tsm_func_ret_e eTSM_CmdDecCBCInit(const tsm_key_id_e eKeyId,
                                  const uint32_t au32IV[4]);

/**
 * @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 (non-blocking)
 *
 * eTSM_CmdDecCBCInitNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdDecCBCInit().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdDecCBCInitCheckResult()
 *
 * @param[in] eKeyId key-ID to be used for decryption
 * @param[in] au32IV Pointer to the memory where the 128-Bit wide
 *                            Initialization Vector(IV) is placed
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32IV
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDecCBCInit()
 * @see eTSM_CmdDecCBCInitCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdDecCBCInitNoWait(const tsm_key_id_e eKeyId,
                                 const uint32_t au32IV[4]);

/**
 * @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 (non-blocking)
 *
 * eTSM_CmdDecCBCInitCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdDecCBCInit().
 * It checks if the command previously triggered by eTSM_CmdDecCBCInitNoWait()
 * has been completed and retrieves the execution result.
 *
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR on success
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_INVALID
 * @return TSM_FUNC_KEY_EMPTY
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDecCBCInit()
 * @see eTSM_CmdDecCBCInitNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdDecCBCInitCheckResult(void);

/**
* @brief Implementation of CMD_DEC_CBC(Step 2) as per SHE spec. chapter 7.4
*
* eTSM_CmdDecCBCUpdate() shall provide N*128-bits(4 * 32-bits) wide
* encrypted text to the decryption engine for decryption. The encrypted text
* shall be N*128-bits(4 * 32-bits) wide and shall be placed in
* the memory before calling this function. The pointer where the decrypted
* text shall be written shall be large enough to hold N*128-bits(4 * 32-bits)
* wide item.
* The decrypted text shall be available in memory as soon as the operation
* error code availability is signaled by the TSM via an irq. Alternatively
* polling may be used to check for error code availability.
* Please note that eTSM_CmdDecCBCInit() should be called before making
* use of eTSM_CmdDecCBCUpdate(). The CBC process shall be complete only
* after N successive calls to eTSM_CmdDecCBCUpdate() and
* eTSM_CmdDecCBCFinalize().
*
* @param[in] au32CipherText Pointer to the memory where the N*128-Bit wide
*                            encrypted text is placed
* @param[in,out] au32PlainText Pointer to the memory where the N*128-Bit wide
*                               decrypted text should be written
*
* @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
*                                  per update for FiFo usage (min: 1, max: 128)
*
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32CipherText
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
*/
tsm_func_ret_e eTSM_CmdDecCBCUpdate(const uint32_t au32CipherText[],
                          uint32_t au32PlainText[],
                          const uint32_t u32BlockSizeOf128Bits);

/**
 * @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 (non-blocking)
 *
 * eTSM_CmdDecCBCUpdateNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdDecCBCUpdate().
 * It triggers the command and provides input data without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdDecCBCUpdateCheckResult()
 *
 * @param[in] au32CipherText Pointer to the memory where the N*128-Bit wide
 *                            encrypted text is placed
 *
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer parameter au32CipherText
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDecCBCUpdate()
 * @see eTSM_CmdDecCBCUpdateCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdDecCBCUpdateNoWait(const uint32_t au32CipherText[], const uint32_t u32BlockSizeOf128Bits);

/**
 * @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 (non-blocking)
 *
 * eTSM_CmdDecCBCUpdateCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdDecCBCUpdate().
 * It checks if the command previously triggered by eTSM_CmdDecCBCUpdateNoWait()
 * has been completed and retrieves the execution result and processing data.
 *
 * @param[in,out] au32PlainText Pointer to the memory where the N*128-Bit wide
 *                               decrypted text should be written
 *
 * @param[in] u32BlockSizeOf128Bits data chunk size in number of 128-bit blocks
 *                                  per update for FiFo usage (min: 1, max: 128)
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR on success
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer au32PlainText
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_MEMORY_FAILURE
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDecCBCUpdate()
 * @see eTSM_CmdDecCBCUpdateNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdDecCBCUpdateCheckResult(uint32_t au32PlainText[], const uint32_t u32BlockSizeOf128Bits);

/**
* @brief Implementation of CMD_DEC_CBC(Step 3) as per SHE spec. chapter 7.4
*
* eTSM_CmdDecCBCFinalize() shall de-initialize the decryption engine of TSM
* Please note that eTSM_CmdDecCBCUpdate() should be called appropriate number
* of times before making use of eTSM_CmdDecCBCFinalize().
*
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
*/
tsm_func_ret_e eTSM_CmdDecCBCFinalize(void);

/**
 * @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 (non-blocking)
 *
 * eTSM_CmdDecCBCFinalizeNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdDecCBCFinalize().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdDecCBCFinalizeCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
  * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDecCBCFinalize()
 * @see eTSM_CmdDecCBCFinalizeCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdDecCBCFinalizeNoWait(void);

/**
 * @brief Implementation of CMD_DEC_CBC as per SHE spec. chapter 7.4 (non-blocking)
 *
 * eTSM_CmdDecCBCFinalizeCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdDecCBCFinalize().
 * It checks if the command previously triggered by eTSM_CmdDecCBCFinalizeNoWait()
 * has been completed and retrieves the execution result.
 *
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_MEMORY_FAILURE
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdDecCBCFinalize()
 * @see eTSM_CmdDecCBCFinalizeNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdDecCBCFinalizeCheckResult(void);

/**
* @brief Implementation of CMD_BOOT_FAILURE as per SHE spec. chapter 7.14
*
* eTSM_CmdBootFailure() will impose the same sanctions as if CMD_SECURE_BOOT
* would detect a failure but can be used during later stages of the boot process.
*
* @note If the secure booting is segmented into several stages and TSM does
* only provide the first, autonomous stage, this function can be used during
* the following stages, to provide the boot status to TSM.
*
* @note This API shall be called only once after power cycle/reset is handled by
* the initial program loader (IPL). In case the API is called a second time it signals
* the appropriate error return code.
*
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_SEQUENCE_ERROR
* @return TSM_FUNC_NO_SECURE_BOOT
* @return TSM_FUNC_BUSY
* @return TSM_FUNC_GENERAL_ERROR
*
* @see more details in chapter 10.4 in SHE specification.
*
*/
tsm_func_ret_e eTSM_CmdBootFailure(void);

/**
 * @brief Implementation of CMD_BOOT_FAILURE as per SHE spec. chapter 7.14 (non-blocking)
 *
 * eTSM_CmdBootFailureNoWait() provides the 1'st stage (non-blocking) variant
 * of the blocking eTSM_CmdBootFailure().
 * It triggers the command without actually waiting for its completion.
 * Once the command has been triggered, it is mandatory to check for its completion
 * and to retrieve the execution result by calling eTSM_CmdBootFailureCheckResult()
 *
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdBootFailure()
 * @see eTSM_CmdBootFailureCheckResult()
 *
 */
tsm_func_ret_e eTSM_CmdBootFailureNoWait(void);

/**
 * @brief Implementation of CMD_BOOT_FAILURE as per SHE spec. chapter 7.14 (non-blocking)
 *
 * eTSM_CmdBootFailureCheckResult() provides the 2'nd stage (non-blocking) variant
 * of the blocking eTSM_CmdBootFailure().
 * It checks if the command previously triggered by eTSM_CmdBootFailureNoWait()
 * has been completed and retrieves the execution result.
 *
 *
 * @return TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL command not yet completed, ERC not yet available
 * @return TSM_FUNC_NO_ERROR on success
 * @return TSM_FUNC_SEQUENCE_ERROR
 * @return TSM_FUNC_NO_SECURE_BOOT
 * @return TSM_FUNC_BUSY
 * @return TSM_FUNC_GENERAL_ERROR
 *
 * @see eTSM_CmdBootFailure()
 * @see eTSM_CmdBootFailureNoWait()
 *
 */
tsm_func_ret_e eTSM_CmdBootFailureCheckResult(void);

/**
* @brief Implementation of CMD_GET_STATUS as per SHE spec. chapter 7.16
*
* To be used to retrieve the current status of the TSM module.
*
* @param[in,out] pu8Status content of the status register. The value of
*                register can be masked with enumeration defined in
*                tsm_status_bit_e. Example:
*                if (*pu8Status & TSM_STATUS_BOOT_OK) ...
*
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer pu8Status
* @return TSM_FUNC_GENERAL_ERROR_INTERNAL
*
*/
tsm_func_ret_e eTSM_CmdGetStatus(uint8_t* const pu8Status);

/**
* @brief Get the result code of a previous command
*
* @param[in,out] peErc Pointer to the memory where the error code should be
*                      written
*
* @return TSM_FUNC_NO_ERROR on success
* @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM on invalid pointer peErc
* @return TSM_ERC_GENERAL_ERROR_ERC_NOT_AVAIL on invalid ERC
*
*/
tsm_func_ret_e eTSM_GetErrorResultCode(tsm_erc_e* const peErc);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TSMAPI__COMMON_H */

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


