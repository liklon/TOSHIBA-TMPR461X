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
#ifndef TSMAPI_IRQ_DMA_STREAM_H
#define TSMAPI_IRQ_DMA_STREAM_H
#include "tsmdefines.h"
#include "dmac.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*! list of DMA channels supported by contoller */
typedef enum tag_tsm_dmac_channel_e
{
    TSM_DMAC_CHANNEL_0 = DMAC_CHANNEL_0,
    /*!< DMA CHANNEL 0 Highest priority */
    TSM_DMAC_CHANNEL_1 = DMAC_CHANNEL_1,
    /*!< DMA CHANNEL 1 */
    TSM_DMAC_CHANNEL_2 = DMAC_CHANNEL_2,
    /*!<  DMA CHANNEL 2 */
    TSM_DMAC_CHANNEL_3 = DMAC_CHANNEL_3,
    /*!<  DMA CHANNEL 3 */
    TSM_DMAC_CHANNEL_4 = DMAC_CHANNEL_4,
    /*!<  DMA CHANNEL 4 */
    TSM_DMAC_CHANNEL_5 = DMAC_CHANNEL_5,
    /*!<  DMA CHANNEL 5 */
    TSM_DMAC_CHANNEL_6 = DMAC_CHANNEL_6,
    /*!<  DMA CHANNEL 6 */
    TSM_DMAC_CHANNEL_7 = DMAC_CHANNEL_7
    /*!<  DMA CHANNEL 7 Lowest priority */
} tsm_dmac_channel_e;


/**
 * @brief function to configure interrupts and DMA channels used by streaming API
 *
 * eTSM_ConfigDma_IrqCtrl4Stream() shall be used to configure the interrupts and the DMA channels used
 * for TSM API stream mode operation. It has to be called at least one time before stream mode
 * operation can be used. But multiples calls are also allowed to reconfigure the DMA channels.
 * In that way the API provides independent configurations during runtime: In case that this function
 * is not called before using an API function with make use of stream mode, the streaming API function return with
 * an error.
 *
 * @note This functionality is only supported by tsm-driver versions 3.xx and above
 *       Both channels used for DMA transfer can't be used during the runtime of the stream mode operation
 *
 * @param[in] eTsmSrcChannel DMA channel used for source data
 * @param[in] eTsmDstChannel DMA channel used for destination data
 *
 * @return TSM_FUNC_NO_ERROR
 * @return TSM_FUNC_GENERAL_ERROR
 * @return TSM_FUNC_GENERAL_ERROR_WRONG_PARAM eTsmSrcChannel or eTsmDstChannel in use already
 *
 */
tsm_func_ret_e eTSM_ConfigDma_IrqCtrl4Stream (tsm_dmac_channel_e eTsmSrcChannel, tsm_dmac_channel_e eTsmDstChannel);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TSMAPI_IRQ_DMA_STREAM_H */

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


