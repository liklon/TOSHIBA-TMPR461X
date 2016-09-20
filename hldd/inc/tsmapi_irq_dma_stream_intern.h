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
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/05/04 09:07:17 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSMAPI_IRQ_DMA_STREAM_INTERN_H
#define TSMAPI_IRQ_DMA_STREAM_INTERN_H
#include "tsmdefines.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**
 * @brief Implementation for streaming API functions to prove the configuration of DMA-channels
 *
 * The configuration of DMA channels for TX and RX directions is required before any API function can make use of
 * streaming/DMA support. For configuration of the channels the API has to call the function eTSM_ConfigDma_IrqCtrl4Stream.
 * The function returns the current status of the configuration.
 *
 * @return C_TRUE the DMA channels are already configured and can be used
 * @return C_FALSE DMA channels not configured streaming mode is not possible
 *
 */
bool_t bTSM_IsDMAConfigurationDone (void);

/**
 * @brief stops DMA channels used for streaming mode by application
 *
 * This functions stops the DMA transfer on both DMA channels for TX and RX direction. All data will be lost immediately.
 *
 * @return void
 *
 */
void vTSM_StopDmaTransfers (void);

/**
 * @brief start dma channel transfer for TX and RX direction
 *
 * @param[in] u32SrcAddr Pointer to the memory where the data for RX direction is placed
 * @param[in] u16SrcTransferSizeInWords RX transfer size in words
 * @param[in] u32DstAddr Pointer to the memory where the data for TX direction should be copied
 * @param[in] u16DstTransferSizeInWords TX transfer size in words
 *
 * @return void
 *
 */
void vTSM_StartDmaTransfers (const uint32_t u32SrcAddr[], const uint16_t u16SrcTransferSizeInWords,
                                  const uint32_t u32DstAddr[], const uint16_t u16DstTransferSizeInWords);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TSMAPI_IRQ_DMA_STREAM_INTERN_H */

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


