/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : include file
*                 Access-Port Driver (common parts valid for R4 core)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      :
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.29 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSM_AP_CR4_H
#define TSM_AP_CR4_H

/**
 * @mainpage TSM Access Port-LLDD drivers for R4 Core
 *
 * @section
 *
 */
/* For Understanding of RX- and TX-Fifo:
 *         +---------+
 *   Write |   RX    | Read
 * CR4---->|   FIFO  |----->CM3
 *         |         |
 *         +---------+
 *
 *         +---------+
 *    Read |   TX    | Write
 * CR4<----|   FIFO  |<-----CM3
 *         |         |
 *         +---------+
 */

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "tsm_ap.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_TSM_AP_CR4_REVISION     "$Revision: 1.29 $"
#define LLDD_TSM_AP_CR4_TAG          "$Name: LLDD_1_6 $"

/**********************************************
*                    Macros                   *
**********************************************/


/**********************************************
*                global variabes              *
**********************************************/



/**********************************************
*               Enumerations                  *
**********************************************/

/*! Forx RX: DMA or IRC as destination of a Fifo IRQ */
typedef enum tag_tsm_ap_RxFifoIrqDest_e
{
    RX_IRQ_TO_IRC = 0,
    /*!< Irq to IRC (default) */

    RX_IRQ_TO_DMA = 1
    /*!< Irq to DMA for Burstreq signal for streaming support. */

} tsm_ap_RxFifoIrqDest_e;

/*! For TX: DMA or IRC as destination of a Fifo IRQ */
typedef enum tag_tsm_ap_TxFifoIrqDest_e
{
    TX_IRQ_TO_IRC = 0,
    /*!< Irq to IRC (default) */

    TX_IRQ_TO_DMA = 1
    /*!< Irq to DMA for Burstreq signal for streaming support. */

} tsm_ap_TxFifoIrqDest_e;

/**********************************************
*                 Structures                  *
**********************************************/
/*! Structure for CR4-RX-FIFO-Status */
typedef struct tag_tsm_ap_RxFifoStatus_CR4_st
{
    bool_t   eRxFull;
    /*!< RX_IN FULL */

    bool_t   eRx_4WordsAv;
    /*!< RX_IN 4 (or more) 32 bit data packets available */

    bool_t   eRx_16WordsAv;
    /*!< RX_IN 16 (or more) 32 bit data packets available (3,125%) */

    bool_t   eRx_128WordsAv;
    /*!< RX_IN 128 (or more) 32 bit data packets available (25%) */

    bool_t   eRx_256WordsAv;
    /*!< RX_IN 256 (or more) 32 bit data packets available(50%) */

    bool_t   eRx_384WordsAv;
    /*!< RX_IN 384 (or more) 32 bit data packets available(50%) */

    bool_t   eRxEmpty;
    /*!< RX_IN Empty */

    uint32_t u32RxCounter;
    /*!< 16 bit RX-Input-Available Data counter (No. of 32bit available entries) */

} tsm_ap_RxFifoStatus_CR4_st;


/*! Structure for CR4-RX-FIFO-IRQ Configuration  */
typedef struct tag_tsm_ap_RxFifoIrqConfig_st
{
    bool_t   eIrqRxEmpty;
    /*!< Interupt if RX-FiFo Empty */

    bool_t   eIrqRx_4WordsAv;
    /*!< Interupt if in RX FiFo 4 (or more) 32 bit data packets available */

    bool_t   eIrqRx_16WordsAv;
    /*!< Interupt if in RX FiFo 16 (or more) 32 bit data packets available */

    bool_t   eIrqRx_128WordsAv;
    /*!< Interupt if in RX FiFo 128 (or more) 32 bit data packets available (25%) */

    bool_t   eIrqRx_256WordsAv;
    /*!< Interupt if in RX FiFo 256 (or more) 32 bit data packets available(50%) */

    bool_t   eIrqRx_384WordsAv;
    /*!< Interupt if in RX FiFo 384 (or more) 32 bit data packets available(75%) */

    bool_t   eIrqRxFull;
    /*!< Interupt if RX FiFo  FULL */

} tsm_ap_RxFifoIrqConfig_st;


/*! Structure for CR4-TX-FIFO-Status */
typedef struct tag_tsm_ap_TxFifoStatus_CR4_st
{
    bool_t   eTxEmpty;
    /*!< TX Empty */

    bool_t   eTx_4WordsAv;
    /*!< TX 4 (or more) free 32 bit slots available */

    bool_t   eTx_128WordsAv;
    /*!< TX 128 (or more) free 32 bit slots available (25%) */

    bool_t   eTx_256WordsAv;
    /*!< TX 256 (or more) free 32 bit slots available(50%) */

    bool_t   eTxFull;
    /*!< shows if TX is Full */

    uint32_t u32TxCounter;
    /*!< 16 bit TX-Input-Entry counter (No. of 32bit free slots)  */

} tsm_ap_TxFifoStatus_CR4_st;


/*! Structure for CR4-TX-FIFO-IRQ Configuration  */
typedef struct tag_tsm_ap_TxFifoIrqConfig_CR4_st
{
    bool_t   eIrqTxEmpty;
    /*!< Interupt if RX-FiFo Empty */

    bool_t   eIrqTx_4WordsAv;
    /*!< Interupt if in RX FiFo 4 (or more) 32 bit data packets available */

    bool_t   eIrqTx_128WordsAv;
    /*!< Interupt if in RX FiFo 128 (or more) 32 bit data packets available (25%) */

    bool_t   eIrqTx_256WordsAv;
    /*!< Interupt if in RX FiFo 256 (or more) 32 bit data packets available(50%) */

    bool_t   eIrqTxFull;
    /*!< Interupt if RX FiFo  FULL */

} tsm_ap_TxFifoIrqConfig_CR4_st;


/**********************************************
*        Exported function prototypes         *
**********************************************/


/**
 * @brief Implementation of writng SHE-Command
 *
 * @param[in] pstSheCommand pointer to structure of SHE command
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on invalid parameters
 *
 */
/* -->Register Description #0 */
tsm_ap_err_e eTSM_AP_SetCommand(const tsm_cmd_st * const pstSheCommand);

/**
 * @brief Implementation of Reading TSM-SHE-Status
 *
 * @param[in, out] pstErc pointer to structure of status
 * (validity, CancelBit, Erc-Flag)
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
  /* -->Register Description #1 */
 tsm_ap_err_e eTSM_AP_GetStatus_CR4(tsm_ap_status_st * const pstStatus);


 /**
  * @brief returns size of integrated flash (for Cap-C)
  *
  * @param[in,out] none
  *
  * @return True: return flash size 0, 1, 2 or 3
  *
  */
  /* -->Register Description #1 */
 tsm_ap_FlashSizeX_e eTSM_AP_GetFlashSize_CR4(void);

/**
 * @brief To check if TSM-Firmware is ready
 *
 * @param[in, out] none
 *
 * @return C_TRUE/C_FALSE
 *
 */
 bool_t boTSM_AP_IsTsmReady(void);
 

/**
 * @brief To check if device mode is FULL-SHE
 *
 * @param[in, out] none
 *
 * @return C_TRUE/C_FALSE
 *
 */
 bool_t boTSM_AP_IsFullShe(void);
 

/**
 * @brief Implementation of Reading ERC-status
 *
 * @param[in, out] pstErc pointer to structure of Erc status
 * (validity, CancelBit, Erc-Flag)
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
/* -->Register Description #2 */
 tsm_ap_err_e eTSM_AP_GetErcStatus_CR4(tsm_ap_Erc_st * const pstErc);


/**
 * @brief Get CM3-RX-Fifo Status
 *
 * @param[in] pstRxFifoStatus pointer to structure of RX-Fifo-status
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 *         +---------+
 *   Write |   RX    | Read
 * CR4---->|   FIFO  |----->CM3
 *         |         |
 *         +---------+
 *
 */
/* -->Register Description #6 */
 tsm_ap_err_e eTSM_AP_GetRxFifoStatus_CR4(tsm_ap_RxFifoStatus_CR4_st * const pstRxFifoStatus);
 
/**
 * @brief Cecheks whether 4 words free places are available in RX-Fifo
 *
 * @param[in] none
 *
 * @return C_TRUE/C_FALSE
 */
 bool_t boTSM_AP_RxFifo_4WordsFree(void);

 
/**
 * @brief deilvers how many words are free in RX-Fifo
 *
 * @param[in] none
 *
 * @return no. of free places in words
 */
 uint32_t u32TSM_AP_RxFifo_CntWordsFree(void);
 

/**
 * @brief Get CM3-RX-FIFO-IRQ-Configuration
 *
 * @param[in] pstRxFifoIrqConfig pointer to structure of RX-Fifo-IRQ-Configuration
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
/* -->Register Description #7 */
 tsm_ap_err_e eTSM_AP_GetRxFifoIrqConfig_CR4(tsm_ap_RxFifoIrqConfig_st * const pstRxFifoIrqConfig);

 /**
 * @brief Set CM3- RX-FIFO-IRQ-Configuration
 *
 * @param[in] pstRxFifoIrqConfig pointer to structure of RX-Fifo-IRQ-Configuration
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on invalid parameters
 *
 */
 /* -->Register Description #7 */
 tsm_ap_err_e eTSM_AP_SetRxFifoIrqConfig_CR4(const tsm_ap_RxFifoIrqConfig_st * const pstRxFifoIrqConfig);


/**
 * @brief Set clear RX FIFO
 *
 * @param[in] none
 *
 * @return none
 *
 */
 void vTSM_AP_ClearRxFifo_CR4(void);


/**
 * @brief Get IRQ FIFO interrupt for CR4 module
 *
 * @param[in] none 
 *
 * @return IRQ
 *
 */
 tsm_ap_RxFifoIrqDest_e eTSM_AP_GetRxFifoIrqDestination_CR4(void);
 
 
/**
* @brief Get the information if the IRQ will be sent to IRC or DMA.
*
* @return RX_IRQ_TO_IRC or RX_IRQ_TO_DMA
*
*/
tsm_ap_RxFifoIrqDest_e eTSM_AP_GetRxFifoIrqDestination(void);


 /**
 * @brief Get destination of RX-Irw
 *
 * @return Destination of Irq
 *
 */
 void vTSM_AP_SetRxFifoIrqDestination(const tsm_ap_RxFifoIrqDest_e  eRxIrqDest);


 /**
 * @brief Enable RX-Fifo Interrupts which are configured
 * @see eTSM_AP_SetRxFifoIrqConfig_CR4
 *
 */
/* -->Register Description #7 */
 void vTSM_AP_EnableRxFifoIrqs_CR4(void);


/**
 * @brief disable RX-Fifo Interrupts which are configured
 * @see eTSM_AP_SetRxFifoIrqConfig_CR4
 *
 */
/* -->Register Description #7 */
 void vTSM_AP_DisableRxFifoIrqs_CR4(void);


 /**
 * @brief Get CM3-TX-Fifo Status
 *
 * @param[in] pstRxFifoStatus pointer to structure of TX-Fifo-status
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 *         +---------+
 *    Read |   TX    | Write
 * CR4<----|   FIFO  |<-----CM3
 *         |         |
 *         +---------+
  */
/* -->Register Description #8 */
 tsm_ap_err_e eTSM_AP_GetTxFifoStatus_CR4(tsm_ap_TxFifoStatus_CR4_st * const pstTxFifoStatus);


/**
 * @brief Checks if at least 4 words data are available in TX-FIFO for Read
 *
 *
 * @return C_TRUE:  Yes at least 4 words are available in TX-Fifo
 * @return C_FALSE: At least 4 words data are not available in TX-Fifo
 *
 */
 bool_t boTSM_AP_TxFifo_4WordsAv(void);


/**
 * @brief Checks how many words are available in TX fifo for read
 *
 *
 * @return No. of available words in Fifo
 *
 */
 uint32_t u32TSM_AP_TxFifo_CntWordsAv(void);


  /**
 * @brief Get CR4-TX-FIFO-IRQ-Configuration
 *
 * @param[in] pstTxFifoIrqConfig pointer to structure of TX-Fifo-IRQ-Configuration
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
 tsm_ap_err_e eTSM_AP_GetTxFifoIrqConfig_CR4(tsm_ap_TxFifoIrqConfig_CR4_st * const pstTxFifoIrqConfig);


/**
 * @brief Set CM3- TX-FIFO-IRQ-Configuration
 *
 * @param[in] pstTxFifoIrqConfig pointer to structure of TX-Fifo-IRQ-Configuration
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on invalid parameters
 *
 */
/* -->Register Description #9 */
 tsm_ap_err_e eTSM_AP_SetTxFifoIrqConfig_CR4(const tsm_ap_TxFifoIrqConfig_CR4_st * const pstTxFifoIrqConfig);


 /**
  * @brief CR4 TX FiFo Clear.
  *
  *
  */
  void vTSM_AP_ClearTxFifo_CR4(void);


 /**
  * @brief Get the information if the IRQ will be sent to IRC or DMA.
  *
  * @return TX_IRQ_TO_IRC or TX_IRQ_TO_DMA
  *
  */
tsm_ap_TxFifoIrqDest_e eTSM_AP_GetTxFifoIrqDestination_CR4(void);


/**
 * @brief Based on this API, it will be decided, if the choosen IRQ will be send to
 * the IRC or as Burstreq signal to the DMA for streaming support.
 *
 * @param[in] eTxIrqDest DMA or IRC
 *
 */
 void vTSM_AP_SetTxFifoIrqDestination_CR4(const tsm_ap_TxFifoIrqDest_e  eTxIrqDest);


  /**
 * @brief Enable TX-Fifo Interrupts which are configured
 * @see eTSM_AP_SetTxFifoIrqConfig_CR4
 *
 */
/* -->Register Description #9 */
 void vTSM_AP_EnableTxFifoIrqs_CR4(void);


/**
 * @brief disable TX-Fifo Interrupts which are configured
 * @see eTSM_AP_SetTxFifoIrqConfig_CR4
 *
 */
/* -->Register Description #9 */
 void vTSM_AP_DisableTxFifoIrqs_CR4(void);


 /**
 * @brief Reads 120 bits data output for TSM-Access-Port UID
 *
 * @param[in, out] au32UidData pointer to structure of UID data
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
/* -->Register Description #10..13 */
 tsm_ap_err_e eTSM_AP_GetUid_CR4(uint32_t au32UidData[4]);


 /**
 * @brief Writes Data from an array in dual port RAM (parameters) (max 32xWords)
 * @param[in, out] pu32Params pointer to structure of parameters
 *                 u32Size  size of structure
 * @note: size of structure should be multiple of 32 bits!
 *
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
/* -->Register Description #14 */
tsm_ap_err_e u32TSM_AP_WriteDP_Param(const uint32_t au32Params[], const  uint32_t u32Size);

/**
 * @brief Reads Statistical Data from dual port RAM at index 30, 31 (parameters)
 * @param[in, out] au32Params pointer to structure of parameters
  *
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
/* -->Register Description #14 */
tsm_ap_err_e u32TSM_AP_ReadDP_ParamStat_CR4(uint32_t au32Params[2]);

/**
 * @brief RX_FIFO-Data Input of TSM-Access-Port
 * Note:  this function dose not check, whether enough free places
 *        are available in RX-FIFO or not. It should be done outside
 *        of API.
 *  Used for :
 *   - Single access by CR4 CPU
 *   - CPU Burst4 or Burst8. Use this address as start address of
 *     Burst4 or Burst8 (with address increment)
 *
 * @param[in] u32Data Data to be written in FIFO
 * @param[in] u32Size: Sie of data to be read
 *
 *         +---------+
 *   Write |   RX    | Read
 * CR4---->|   FIFO  |----->CM3
 *         |         |
 *         +---------+
 *
 */
 tsm_ap_err_e eTSM_AP_WriteRxFIFO(const uint32_t au32Data[], const uint32_t u32Size);

 /**
  * @brief RX_FIFO-Data Input of TSM-Access-Port
  * Note:  this function dose not check, whether enough free places
  *        are available in RX-FIFO or not. It should be done outside
  *        of API.
  *  Used for :
  *   - Single access by CR4 CPU
  *   - DMA access (non incrementing or decrementing address)
  *   - CPU Burst4
  *
  * @param[in] u32Data Data to be written in FIFO
  *
  *         +---------+
  *   Write |   RX    | Read
  * CR4---->|   FIFO  |----->CM3
  *         |         |
  *         +---------+
  *
  */
 tsm_ap_err_e eTSM_AP_WriteRxFIFO_4Words(const uint32_t au32Data[]);

 /**
 * @brief Read TX_FIFO-Data output
 * Notes: this function dose not check, whether data are available in
 *        TX-FIFO or not. It should be done outside of API.
 *  Used for :
 *
 * @param[in] au32Data: Data to be written from FIFO
 * @param[in] u32Size: Sie of data to be read
 *
 *         +---------+
 *    Read |   TX    | Write
 * CR4<----|   FIFO  |<-----CM3
 *         |         |
 *         +---------+
 *
 */
 tsm_ap_err_e eTSM_AP_ReadTxFIFO(uint32_t au32Data[], const uint32_t u32Size);
 
 /**
 * @brief Read TX_FIFO-Data output
 * Notes: this function dose not check, whether data are available in
 *        TX-FIFO or not. It should be done outside of API.
 *  Used for :
 *
 * @param[in] au32Data: Data to be written from FIFO
 *
 *         +---------+
 *    Read |   TX    | Write
 * CR4<----|   FIFO  |<-----CM3
 *         |         |
 *         +---------+
 *
 */
 tsm_ap_err_e eTSM_AP_ReadTxFIFO_4Words(uint32_t au32Data[]);

/**
 * @brief Get CR4-RX-Fifo Status
 *
 * @param[in] pstRxFifoStatus pointer to structure of RX-Fifo-status
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
 tsm_ap_err_e eTSM_AP_GetRxFifoStatus(tsm_ap_RxFifoStatus_CR4_st * const pstRxFifoStatus);


/**
 * @brief Get CR4-RX-FIFO-IRQ-Configuration
 *
 * @param[in] pstRxFifoIrqConfig pointer to structure of RX-Fifo-IRQ-Configuration
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 */
 tsm_ap_err_e eTSM_AP_GetRxFifoIrqConfig_CR4(tsm_ap_RxFifoIrqConfig_st * const pstRxFifoIrqConfig);


 /**
 * @brief Set CR4- RX-FIFO-IRQ-Configuration
 *
 * @param[in] pstRxFifoIrqConfig pointer to structure of RX-Fifo-IRQ-Configuration
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on invalid parameters
 *
 */
 tsm_ap_err_e eTSM_AP_SetRxFifoIrqConfig_CR4(const tsm_ap_RxFifoIrqConfig_st * const pstRxFifoIrqConfig);


/**
 * @brief Based on this API, it will be decided, if the choosen IRQ will be send to
 * the IRC or as Burstreq signal to the DMA for streaming support.
 *
 * @param[in] eRxIrqDest DMA or IRC
 *
 */
 void vTSM_AP_SetRxFifoIrqDestination(const tsm_ap_RxFifoIrqDest_e  eRxIrqDest);


/**
 * @brief CR4 RX FiFo Clear.
 *
 *
 */
 void vTSM_AP_ClearRxFifo_CR4(void);


/**
 * @brief Enables RX-Fifo Interrupts which are configured
 * @see eTSM_AP_SetRxFifoIrqConfig_CR4
 *
 */
 void vTSM_AP_EnableRxFifoIrqs_CR4(void);


/**
 * @brief Disables RX-Fifo Interrupts which are configured
 * @see eTSM_AP_SetRxFifoIrqConfig_CR4
 *
 */
 void vTSM_AP_DisableRxFifoIrqs(void);

 /**
 * @brief Get CR4-TX-Fifo Status
 *
 * @param[in] pstRxFifoStatus pointer to structure of TX-Fifo-status
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on null pointer
 *
 *         +---------+
 *    Read |   TX    | Write
 * CR4<----|   FIFO  |<-----CM3
 *         |         |
 *         +---------+
 */
 tsm_ap_err_e eTSM_AP_GetTxFifoStatus_CR4(tsm_ap_TxFifoStatus_CR4_st * const pstTxFifoStatus);




 /**
 * @brief Set CR4- TX-FIFO-IRQ-Configuration
 *
 * @param[in] pstTxFifoIrqConfig pointer to structure of TX-Fifo-IRQ-Configuration
 *
 * @return TSM_AP_NO_ERROR on success
 * @return TSM_AP_WRONG_PARAMS on invalid parameters
 *
 */
 tsm_ap_err_e eTSM_AP_SetTxFifoIrqConfig_CR4(const tsm_ap_TxFifoIrqConfig_CR4_st * const pstTxFifoIrqConfig);


/**
 * @brief Enables TX-Fifo Interrupts which are configured
 * @see eTSM_AP_SetTxFifoIrqConfig_CR4
 *
 */
 void vTSM_AP_EnableTxFifoIrqs_CR4(void);


/**
 * @brief Disables TX-Fifo Interrupts which are configured
 * @see eTSM_AP_SetTxFifoIrqConfig_CR4
 *
 */
 void vTSM_AP_DisableTxFifoIrqs_CR4(void);


 #endif /* _TSM_AP_CR4_H */

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


