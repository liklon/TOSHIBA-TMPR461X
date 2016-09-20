/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION :
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     : TSM-Driver
*   MODULE      : TSM stream helper functions for isr and dma access
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.15 $
*   DATE        : $Date: 2015/05/04 09:07:18 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "tsmapi_irq_dma_stream.h"          /* Module API helper definitions for ISR and DMA for user */
#include "tsmapi_irq_dma_stream_intern.h"   /* Module helper definitions for ISR and DMA only for intern */
#include "tsmapi_rest.h"
#include "tsm_ap.h"
#include "tsm_ap_cr4.h"
#include "dmac.h"
#include "ccr.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/
#define TSM_TX_FIFO_ADDR      (0xC010B1B0U)
#define TSM_RX_FIFO_ADDR      (0xC010B180U)
#define TSM_HASH_3_VERSION    (0x03U)
#define TSM_VER_INVALID_VALUE_ALL_BITS   (0xFFFFFFFFU)
#define TSM_INVALID_VER_VALUE_NO_BITS    (0x00000000U)

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/


/**********************************************
*                    Macros                   *
**********************************************/

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

/* variable to store the dma channel for src data */
static dmac_channel_e eSrcChannel;
/* variable to store the dma channel for destination data */
static dmac_channel_e eDstChannel;
/* variable to track the configuration of dma and irq*/
static bool_t bInitDone=C_FALSE;
/* variable that contains the actual status of a stream procedure */
static bool_t bStreamProcessPending= C_FALSE;

/*********************************************/

/**********************************************
*             Function definition             *
*********************************************/
static bool_t bTSM_StreamModeSupportedByFw ( void );


void vTSM_StopDmaTransfers (void)
{
   if (C_TRUE == bStreamProcessPending )
   {
       /* stops immediately the data transfer in both channels */
       /* all outstanding data is lost */
       vTSM_AP_DisableRxFifoIrqs_CR4();
       vTSM_AP_DisableTxFifoIrqs_CR4();
       vDMAC_StopTransfer (eSrcChannel);
       vDMAC_StopTransfer (eDstChannel);
       /* clear TX and RX FIFO */
       vTSM_AP_ClearRxFifo_CR4();
       vTSM_AP_ClearTxFifo_CR4();
   }
   bStreamProcessPending = C_FALSE;
}

void vTSM_StartDmaTransfers (const uint32_t u32SrcAddr[], const uint16_t u16SrcTransferSizeInWords,
                             const uint32_t u32DstAddr[], const uint16_t u16DstTransferSizeInWords)
{
   dmac_control_st  stControl;

   /* stop dma transfer on both used channels */
   vDMAC_StopTransfer (eSrcChannel);
   vDMAC_StopTransfer (eDstChannel);

   /* clear TX and RX FIFO */
   vTSM_AP_ClearRxFifo_CR4();
   vTSM_AP_ClearTxFifo_CR4();

   /* clear all pending interrupts */
   vDMAC_ClearInterruptTCStatus(eSrcChannel);
   vDMAC_ClearInterruptTCStatus(eDstChannel);

   vDMAC_ClearInterruptError(eSrcChannel);
   vDMAC_ClearInterruptError(eDstChannel);

   vDMAC_SetSourceAddress(eSrcChannel, (uint32_t)u32SrcAddr);
   vDMAC_SetDestinationAddress(eSrcChannel, TSM_RX_FIFO_ADDR);

   /* set transfer size for source channel */
   (void) boDMAC_GetControl(eSrcChannel, &stControl);
   stControl.u16TransferSize = u16SrcTransferSizeInWords;
   vDMAC_SetControl(eSrcChannel, &stControl);

   vDMAC_SetSourceAddress(eDstChannel, TSM_TX_FIFO_ADDR);
   vDMAC_SetDestinationAddress(eDstChannel, (uint32_t)u32DstAddr);

   /* set transfer size for destination channel */
   (void) boDMAC_GetControl(eDstChannel, &stControl);
   stControl.u16TransferSize = u16DstTransferSizeInWords;
   vDMAC_SetControl(eDstChannel, &stControl);

   /* start transfer for both channels */
   vDMAC_StartTransfer (eSrcChannel);
   vDMAC_StartTransfer (eDstChannel);

   vTSM_AP_EnableTxFifoIrqs_CR4();
   vTSM_AP_EnableRxFifoIrqs_CR4();

   bStreamProcessPending = C_TRUE;
}

bool_t bTSM_IsDMAConfigurationDone (void)
{
    return bInitDone;
}

static bool_t bTSM_StreamModeSupportedByFw ( void )
{
    uint16_t u16TsmMajorVersion;
    uint16_t u16TsmMinorVersion;
    uint16_t u16TsmDrvMajorVersion;
    uint16_t u16TsmDrvMinorVersion;
    bool_t bSupported;
    tsm_func_ret_e eFuncRetCode;

    bSupported = C_FALSE;

    eFuncRetCode = eTSM_GetTsmVersion( &u16TsmMajorVersion, &u16TsmMinorVersion,
                                       &u16TsmDrvMajorVersion, &u16TsmDrvMinorVersion);

    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        if ( (C_FALSE == ((TSM_VER_INVALID_VALUE_ALL_BITS == u16TsmMajorVersion) && (TSM_VER_INVALID_VALUE_ALL_BITS == u16TsmMinorVersion)))
                                                                 &&
           ( C_FALSE == ((  TSM_INVALID_VER_VALUE_NO_BITS == u16TsmMajorVersion) && (TSM_INVALID_VER_VALUE_NO_BITS == u16TsmMinorVersion))))
        {
            if (TSM_HASH_3_VERSION <= u16TsmMajorVersion)
            {
                bSupported = C_TRUE;
            }
        }
    }
    return bSupported;
}


tsm_func_ret_e eTSM_ConfigDma_IrqCtrl4Stream (tsm_dmac_channel_e eTsmSrcChannel, tsm_dmac_channel_e eTsmDstChannel)
{
   dmac_control_st     stControl;
   dmac_config_st      stConfig;
   dmac_linklistitem_st  stLinkListItem;
   tsm_ap_RxFifoIrqConfig_st      stRxFifoIrqConfig;
   tsm_ap_TxFifoIrqConfig_CR4_st  stTxFifoIrqConfig;
   tsm_func_ret_e  eFuncRet;
   ccr_enable_e eEn;

   eFuncRet = TSM_FUNC_NO_ERROR;

   (void)i32CCR_GetEnabledModuleClock( CCR_DMA, &eEn);

   /* check that dma controller and irqs are already enabled by application */
   if ( ( DMAC_ENABLE != eDMAC_GetEnabled() ) || (eEn != CCR_DISABLE) )
   {
       eFuncRet = TSM_FUNC_GENERAL_ERROR;
   }

   /* check that tsm version supports stream mode */
   if (TSM_FUNC_NO_ERROR == eFuncRet)
   {
       if (C_FALSE == bTSM_StreamModeSupportedByFw() )
       {
           eFuncRet = TSM_FUNC_GENERAL_ERROR;
       }
   }

   if (TSM_FUNC_NO_ERROR == eFuncRet)
   {
       /* store settings for later use */
       eSrcChannel = (dmac_channel_e)eTsmSrcChannel;
       eDstChannel = (dmac_channel_e)eTsmDstChannel;

       /* validate that dma channels are currently not busy */
       if (eDMAC_GetEnabledChannel(eSrcChannel) == DMAC_ENABLE)
       {
           eFuncRet = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
       }

       /* complicated handling to satisfy Miscra */
       if ( TSM_FUNC_NO_ERROR == eFuncRet )
       {
           if (eDMAC_GetEnabledChannel(eDstChannel) == DMAC_ENABLE)
           {
               eFuncRet = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
           }
       }

       if ( TSM_FUNC_NO_ERROR == eFuncRet )
       {

           /* configure irq for RX fifo */
           stRxFifoIrqConfig.eIrqRxEmpty = C_FALSE;
           stRxFifoIrqConfig.eIrqRx_4WordsAv = C_TRUE;
           stRxFifoIrqConfig.eIrqRx_16WordsAv = C_FALSE;
           stRxFifoIrqConfig.eIrqRx_128WordsAv = C_FALSE;
           stRxFifoIrqConfig.eIrqRx_256WordsAv = C_FALSE;
           stRxFifoIrqConfig.eIrqRx_384WordsAv = C_FALSE;
           stRxFifoIrqConfig.eIrqRxFull = C_FALSE;
           (void) eTSM_AP_SetRxFifoIrqConfig_CR4(&stRxFifoIrqConfig);

           vTSM_AP_SetRxFifoIrqDestination(RX_IRQ_TO_DMA);

           /* configure irq for TX fifo */
           stTxFifoIrqConfig.eIrqTxEmpty = C_FALSE;
           stTxFifoIrqConfig.eIrqTx_4WordsAv = C_TRUE;
           stTxFifoIrqConfig.eIrqTx_128WordsAv = C_FALSE;
           stTxFifoIrqConfig.eIrqTx_256WordsAv = C_FALSE;
           stTxFifoIrqConfig.eIrqTxFull = C_FALSE;
           (void) eTSM_AP_SetTxFifoIrqConfig_CR4 (&stTxFifoIrqConfig);

           vTSM_AP_SetTxFifoIrqDestination_CR4 (TX_IRQ_TO_DMA);

           /* clear all pending interrupts */
           vDMAC_ClearInterruptError(eSrcChannel);
           vDMAC_ClearInterruptError(eDstChannel);

           vDMAC_ClearInterruptTCStatus(eSrcChannel);
           vDMAC_ClearInterruptTCStatus(eDstChannel);

           /* configure ctrl register for source dma channel */
           /* transfer size will be set in she api function */
           stControl.eTCInterruptEnable     = DMAC_DISABLE;
           stControl.u8Protection           = 0U;
           stControl.eDstInc                = DMAC_NO_ADDRESS_INCREMENT;
           stControl.eSourceInc             = DMAC_ADDRESS_INCREMENT;
           stControl.eDstAHBMasterSelect    = DMAC_SELECT_AHB_MASTER_1;
           stControl.eSourceAHBMasterSelect = DMAC_SELECT_AHB_MASTER_2;
           stControl.eDstTransferWidth      = DMAC_TRANSFER_WORD;
           stControl.eSourceTransferWidth   = DMAC_TRANSFER_WORD;
           stControl.eDstBurstLength        = DMAC_BURST_LENGTH_4;
           stControl.eSourceBurstLength     = DMAC_BURST_LENGTH_4;
           vDMAC_SetControl(eSrcChannel, &stControl);

           /* configure ctrl register for destination dma channel */
           /* transfer size will be set in she api function */
           stControl.eTCInterruptEnable     = DMAC_DISABLE;
           stControl.u8Protection           = 0U;
           stControl.eDstInc                = DMAC_ADDRESS_INCREMENT;
           stControl.eSourceInc             = DMAC_NO_ADDRESS_INCREMENT;
           stControl.eDstAHBMasterSelect    = DMAC_SELECT_AHB_MASTER_1;
           stControl.eSourceAHBMasterSelect = DMAC_SELECT_AHB_MASTER_2;
           stControl.eDstTransferWidth      = DMAC_TRANSFER_WORD;
           stControl.eSourceTransferWidth   = DMAC_TRANSFER_WORD;
           stControl.eDstBurstLength        = DMAC_BURST_LENGTH_4;
           stControl.eSourceBurstLength     = DMAC_BURST_LENGTH_4;
           vDMAC_SetControl(eDstChannel, &stControl);

           /* set config register for src channel */
           stConfig.eHalt               = DMAC_DISABLE;
           stConfig.eActive             = DMAC_DISABLE;
           stConfig.eLockedTransfer     = DMAC_DISABLE;
           stConfig.eMaskTCInterrupt    = DMAC_DISABLE;
           stConfig.eMaskErrorInterrupt = DMAC_DISABLE;
           stConfig.eFlowControl        = DMAC_MEMORY_TO_PERIPHERAL_BY_DMA;
           stConfig.u8DstPeripheral     = 0x8U;
           stConfig.u8SourcePeripheral  = 0U;
           vDMAC_SetConfiguration(eSrcChannel, &stConfig);

           /* set config register for destination channel */
           stConfig.eHalt               = DMAC_DISABLE;
           stConfig.eActive             = DMAC_DISABLE;
           stConfig.eLockedTransfer     = DMAC_DISABLE;
           stConfig.eMaskTCInterrupt    = DMAC_ENABLE;
           stConfig.eMaskErrorInterrupt = DMAC_DISABLE;
           stConfig.eFlowControl        = DMAC_PERIPHERAL_TO_MEMORY_BY_DMA;
           stConfig.u8DstPeripheral     = 0U;
           stConfig.u8SourcePeripheral  = 0x9U;
           vDMAC_SetConfiguration(eDstChannel, &stConfig);

           /* delete all entries in linked list for tsm channels */
           stLinkListItem.eAHBMasterSelect = DMAC_SELECT_AHB_MASTER_1;
           stLinkListItem.u32LLIAddress =0U;
           vDMAC_SetLinkListItem(eDstChannel,&stLinkListItem);
           vDMAC_SetLinkListItem(eSrcChannel,&stLinkListItem);

           /* store that init was done */
           bInitDone = C_TRUE;
       }
   }
   return eFuncRet;
}


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


