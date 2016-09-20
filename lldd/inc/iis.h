/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : IIS Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : IIS
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/08 08:56:32 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef IIS_H
#define IIS_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_IIS_H_REVISION     "$Revision: 1.8 $"
#define LLDD_IIS_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/*
 *  Register bit masks 
 */

/* Rx FIFO underflow interrupt */
#define IIS_INT_RX_ERR                      (0x01 << 5) 
/* More than 16 words in the RX FIFO */
#define IIS_INT_RX_HF_INT                   (0x01 << 4) 
/* more than 24 words in Rx FIFO */
#define IIS_INT_RX_AF_INT                   (0x01 << 3) 
/* less than 24 words in Tx FIFO */
#define IIS_INT_TX_NF_INT                   (0x01 << 2) 
/* Tx FIFO overflow */
#define IIS_INT_TX_ERR                      (0x01 << 1) 
/* less than 8 words in Tx FIFO */
#define IIS_INT_TX_AE_INT                   (0x01 << 0) 
/* Mask all interrupt sources */
#define IIS_INT_GLOBAL_MASK                 (0x01 << 6) 

/* TX FIFO size */
#define IIS_FIFO_TX_SIZE                    32 
/* RX FIFO size */
#define IIS_FIFO_RX_SIZE                    32 
/* TX FIFO all status bits */                                           
#define IIS_FIFO_TX_MASKS                   (0x1F << 16) 
/* TX FIFO empty */                                           
#define IIS_FIFO_TX_EMPTY                   (0x01 << 20) 
/* TX FIFO almost empty (8 or less data) */
#define IIS_FIFO_TX_AE                      (0x01 << 19) 
/* TX FIFO half full */
#define IIS_FIFO_TX_HF                      (0x01 << 18) 
/* TX FIFO almost full */
#define IIS_FIFO_TX_AF                      (0x01 << 17) 
/* TX FIFO full */
#define IIS_FIFO_TX_FULL                    (0x01 << 16) 
/* RX FIFO all status bits */                                           
#define IIS_FIFO_RX_MASKS                   (0x1F << 0) 
/* RX FIFO empty */                                           
#define IIS_FIFO_RX_EMPTY                   (0x01 << 4) 
/* RX FIFO almost empty (8 or less data) */
#define IIS_FIFO_RX_AE                      (0x01 << 3) 
/* RX FIFO half full */
#define IIS_FIFO_RX_HF                      (0x01 << 2) 
/* RX FIFO almost full */
#define IIS_FIFO_RX_AF                      (0x01 << 1) 
/* RX FIFO full */
#define IIS_FIFO_RX_FULL                    (0x01 << 0) 

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/* IIS Controller initialization error codes */
typedef enum tag_iis_ErrCode_e
{
    IIS_OK   = 0,                           /* Operation completed correctly */
    IIS_FAIL = 1                            /* Operation not completed */
} iis_ErrCode_e;

/* IIS channel */
typedef enum tag_iis_Ch_e
{
    IIS_CH0 = 0x0,                          /* Interface channel 0 */
    IIS_CH1 = 0x1                           /* Interface channel 1 */  
} iis_Ch_e;

/* IIS Word select polarities */
typedef enum tag_iis_WrdSelPol_e
{
    IIS_WRDSEL_START_LOW  = 0x0,            /* Start as low */
    IIS_WRDSEL_START_HIGH = 0x1             /* Start as high */  
} iis_WrdSelPol_e;

/* IIS transmit polarities */
typedef enum tag_iis_TxPol_e
{
    IIS_TXPOL_FALL_EDGE = 0x0,              /* Falling edge */
    IIS_TXPOL_RISE_EDGE = 0x1               /* Rising edge */  
} iis_TxPol_e;

/* IIS overflow error reaction */
typedef enum tag_iis_ErrOvrRes_e
{
    IIS_ERR_OVR_DISCARD = 0x0,              /* Discard data */
    IIS_ERR_OVR_STOP_WS = 0x1               /* Stop word select generation */  
} iis_ErrOvrRes_e;

/* IIS underflow error reaction */
typedef enum tag_iis_ErrUdrRes_e
{
    IIS_ERR_UDR_SND_ZEROS = 0x0,            /* Send zeros */
    IIS_ERR_UDR_STOP_WS   = 0x1             /* Send stop word select generation */  
} iis_ErrUdrRes_e;

/* IIS mode of operation */
typedef enum tag_iis_Mode_e
{
    IIS_MODE_SLAVE  = 0x0,                  /* Operate in Slave mode */
    IIS_MODE_MASTER = 0x1                   /* Operate in Master mode */  
} iis_Mode_e;

/* IIS direction */
typedef enum tag_iis_Dir_e
{
    IIS_DIR_RX = 0x0,                       /* Receive */
    IIS_DIR_TX = 0x1                        /* Transmit */  
} iis_Dir_e;

/* IIS TX/RX activity  */
typedef enum tag_iis_TrsfOper_e
{
    IIS_TRSF_OPER_DISABLE = 0x0,            /* Disable TX/RX operation */
    IIS_TRSF_OPER_ENABLE  = 0x1             /* Enable TX/RX operation */  
} iis_TrsfOper_e;

/* IIS valid data width selection (number of bits) */
typedef enum tag_iis_DataWid_e
{
    IIS_DATAWID_1  = (0 << 8),              /* 1 valid data bit */
    IIS_DATAWID_2  = (1 << 8),              /* 2 valid data bits */
    IIS_DATAWID_3  = (2 << 8),              /* 3 valid data bits */
    IIS_DATAWID_4  = (3 << 8),              /* 4 valid data bits */
    IIS_DATAWID_5  = (4 << 8),              /* 5 valid data bits */
    IIS_DATAWID_6  = (5 << 8),              /* 6 valid data bits */
    IIS_DATAWID_7  = (6 << 8),              /* 7 valid data bits */
    IIS_DATAWID_8  = (7 << 8),              /* 8 valid data bits */
    IIS_DATAWID_9  = (8 << 8),              /* 9 valid data bits */
    IIS_DATAWID_10 = (9 << 8),              /* 10 valid data bits */
    IIS_DATAWID_11 = (10 << 8),             /* 11 valid data bits */
    IIS_DATAWID_12 = (11 << 8),             /* 12 valid data bits */
    IIS_DATAWID_13 = (12 << 8),             /* 13 valid data bits */
    IIS_DATAWID_14 = (13 << 8),             /* 14 valid data bits */
    IIS_DATAWID_15 = (14 << 8),             /* 15 valid data bits */
    IIS_DATAWID_16 = (15 << 8),             /* 16 valid data bits */
    IIS_DATAWID_17 = (16 << 8),             /* 17 valid data bits */
    IIS_DATAWID_18 = (17 << 8),             /* 18 valid data bits */
    IIS_DATAWID_19 = (18 << 8),             /* 19 valid data bits */
    IIS_DATAWID_20 = (19 << 8),             /* 20 valid data bits */
    IIS_DATAWID_21 = (20 << 8),             /* 21 valid data bits */
    IIS_DATAWID_22 = (21 << 8),             /* 22 valid data bits */
    IIS_DATAWID_23 = (22 << 8),             /* 23 valid data bits */
    IIS_DATAWID_24 = (23 << 8),             /* 24 valid data bits */
    IIS_DATAWID_25 = (24 << 8),             /* 25 valid data bits */
    IIS_DATAWID_26 = (25 << 8),             /* 26 valid data bits */
    IIS_DATAWID_27 = (26 << 8),             /* 27 valid data bits */
    IIS_DATAWID_28 = (27 << 8),             /* 28 valid data bits */
    IIS_DATAWID_29 = (28 << 8),             /* 29 valid data bits */
    IIS_DATAWID_30 = (29 << 8),             /* 30 valid data bits */
    IIS_DATAWID_31 = (30 << 8),             /* 31 valid data bits */
    IIS_DATAWID_32 = (31 << 8)              /* 32 valid data bits */  
} iis_DataWid_e;

/* IIS WS length selection (number of clock cycles) */
typedef enum tag_iis_WsLen_e
{
    IIS_WSLEN_RESERVED = 0, /* reserved value */
    IIS_WSLEN_2  = 1,                       /* 2 clock cycles */
    IIS_WSLEN_3  = 2,                       /* 3 clock cycles */
    IIS_WSLEN_4  = 3,                       /* 4 clock cycles */
    IIS_WSLEN_5  = 4,                       /* 5 clock cycles */
    IIS_WSLEN_6  = 5,                       /* 6 clock cycles */
    IIS_WSLEN_7  = 6,                       /* 7 clock cycles */
    IIS_WSLEN_8  = 7,                       /* 8 clock cycles */
    IIS_WSLEN_9  = 8,                       /* 9 clock cycles */
    IIS_WSLEN_10 = 9,                       /* 10 clock cycles */
    IIS_WSLEN_11 = 10,                      /* 11 clock cycles */
    IIS_WSLEN_12 = 11,                      /* 12 clock cycles */
    IIS_WSLEN_13 = 12,                      /* 13 clock cycles */
    IIS_WSLEN_14 = 13,                      /* 14 clock cycles */
    IIS_WSLEN_15 = 14,                      /* 15 clock cycles */
    IIS_WSLEN_16 = 15,                      /* 16 clock cycles */
    IIS_WSLEN_17 = 16,                      /* 17 clock cycles */
    IIS_WSLEN_18 = 17,                      /* 18 clock cycles */
    IIS_WSLEN_19 = 18,                      /* 19 clock cycles */
    IIS_WSLEN_20 = 19,                      /* 20 clock cycles */
    IIS_WSLEN_21 = 20,                      /* 21 clock cycles */
    IIS_WSLEN_22 = 21,                      /* 22 clock cycles */
    IIS_WSLEN_23 = 22,                      /* 23 clock cycles */
    IIS_WSLEN_24 = 23,                      /* 24 clock cycles */
    IIS_WSLEN_25 = 24,                      /* 25 clock cycles */
    IIS_WSLEN_26 = 25,                      /* 26 clock cycles */
    IIS_WSLEN_27 = 26,                      /* 27 clock cycles */
    IIS_WSLEN_28 = 27,                      /* 28 clock cycles */
    IIS_WSLEN_29 = 28,                      /* 29 clock cycles */
    IIS_WSLEN_30 = 29,                      /* 30 clock cycles */
    IIS_WSLEN_31 = 30,                      /* 31 clock cycles */
    IIS_WSLEN_32 = 31                       /* 32 clock cycles */  
} iis_WsLen_e;

/* IIS MCLK activity */
typedef enum tag_iis_MClkOper_e
{
    IIS_MCLKOPER_DISABLE = (0x0 << 21),     /* MCLK disabled */
    IIS_MCLKOPER_ENABLE = (0x1 << 21)       /* MCLK enabled */  
} iis_MClkOper_e;

/* IIS MCLK source */
typedef enum tag_iis_MClkSrc_e
{
    IIS_MCLKSRC_INTERNAL = (0x0 << 20),     /* Internal MCLK 480MHz */
    IIS_MCLKSRC_EXTERNAL = (0x1 << 20)      /* External MCLK source */    
} iis_MClkSrc_e;

/* IIS divider value */
typedef enum tag_iis_MClkDiv_e
{
    IIS_MCLKDIV_RESERVED = (0 << 8),        /* Reserved value */
    IIS_MCLKDIV_1        = (1 << 8),        /* No division */
    IIS_MCLKDIV_2        = (2 << 8),        /* Division by 2 */
    IIS_MCLKDIV_3        = (3 << 8),        /* Division by 3 */
    IIS_MCLKDIV_4        = (4 << 8),        /* Division by 4 */
    IIS_MCLKDIV_11       = (11 << 8),       /* Division by 11 (default) */    
    IIS_MCLKDIV_39       = (39 << 8),       /* Division by 39 */
    /*
     *  Values from 5 up to 1022, should be defined if necessary
     */
    IIS_MCLKDIV_1023     = (1023 << 8)      /* Division by 2 */    
} iis_MClkDiv_e;

/* IIS output activity selection */
typedef enum tag_iis_MClkOut_e
{
    IIS_MCLKOUT_DISABLE = (0x0 << 21),      /* MCLK outpu disabled */
    IIS_MCLKOUT_ENABLE  = (0x1 << 21)       /* MCLK outpu enabled */    
} iis_MClkOut_e;

/* IIS latch time selection (MCLK's positive edged number)*/
typedef enum tag_iis_LatchTime_e
{
    IIS_LTIME_RESERVED = (0 << 2),          /* Reserved value */
    IIS_LTIME_2        = (0x01 << 2),       /* 2 positive positive edge */
    IIS_LTIME_3        = (0x02 << 2),       /* 3 positive edge */
    IIS_LTIME_4        = (0x03 << 2),       /* 4 positive edge */
    IIS_LTIME_5        = (0x04 << 2),       /* 5 positive edge */
    IIS_LTIME_6        = (0x05 << 2),       /* 6 positive edge */
    IIS_LTIME_7        = (0x06 << 2),       /* 7 positive edge */
    IIS_LTIME_8        = (0x07 << 2),       /* 8 positive edge */
    IIS_LTIME_9        = (0x08 << 2),       /* 9 positive edge */
    IIS_LTIME_10       = (0x09 << 2),       /* 10 positive edge */
    IIS_LTIME_11       = (0x0A << 2),       /* 11 positive edge */
    IIS_LTIME_12       = (0x0B << 2),       /* 12 positive edge */
    IIS_LTIME_13       = (0x0C << 2),       /* 13 positive edge */
    IIS_LTIME_14       = (0x0D << 2),       /* 14 positive edge */
    IIS_LTIME_15       = (0x0E << 2),       /* 15 positive edge */
    IIS_LTIME_16       = (0x0F << 2),       /* 16 positive edge */
    IIS_LTIME_17       = (0x10 << 2),       /* 17 positive edge */
    IIS_LTIME_18       = (0x11 << 2),       /* 18 positive edge */
    IIS_LTIME_19       = (0x12 << 2),       /* 19 positive edge */
    IIS_LTIME_20       = (0x13 << 2),       /* 20 positive edge */
    IIS_LTIME_21       = (0x14 << 2),       /* 21 positive edge */
    IIS_LTIME_22       = (0x15 << 2),       /* 22 positive edge */
    IIS_LTIME_23       = (0x16 << 2),       /* 23 positive edge */
    IIS_LTIME_24       = (0x17 << 2),       /* 24 positive edge */
    IIS_LTIME_25       = (0x18 << 2),       /* 25 positive edge */
    IIS_LTIME_26       = (0x19 << 2),       /* 26 positive edge */
    IIS_LTIME_27       = (0x1A << 2),       /* 27 positive edge */
    IIS_LTIME_28       = (0x1B << 2),       /* 28 positive edge */
    IIS_LTIME_29       = (0x1C << 2),       /* 29 positive edge */
    IIS_LTIME_30       = (0x1D << 2),       /* 30 positive edge */
    IIS_LTIME_31       = (0x1E << 2),       /* 31 positive edge */
    IIS_LTIME_32       = (0x1F << 2)        /* 32 positive edge */   
} iis_LatchTime_e;

/*
** IIS Bit Clock divider selection
*/
typedef enum tag_iis_BClkDiv_e
{
  IIS_BCLKDIV_8        = 0x0,               /* Dividy by 8 */
  IIS_BCLKDIV_16       = 0x1,               /* Dividy by 16 */
  IIS_BCLKDIV_32       = 0x2,               /* Dividy by 32 */
  IIS_BCLKDIV_RESERVED = 0x3                /* Reserved */  
} iis_BClkDiv_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vIIS_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8IORevision     - pointer to IO header revision string
 *                pau8IOTag          - pointer to IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vIIS_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      eIIS_InitAsADC
 *                
 * Purpose:       Initialize the IIS controllers as ADC (input)
 *
 * Inputs:        eCh  IIS channel (interface) selection
 *                
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   This function is an example set of configurations necessary
 *                to be performed for IIS controller. It should be noted
 *                that several other settings are required (board setup)
 *                to be able to utilize the IIS interface correctly as an input.
 *                Be aware the the sub-functions return-errors checking - any
 *                sub-function error will cause this function to fail, however
 *                some settings might be already written to the IIS controller.
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_InitAsADC(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      eIIS_InitAsDAC
 *                
 * Purpose:       Initialize the IIS controllers as DAC (input)
 *                
 * Inputs:        eCh  IIS channel (interface)
 *                
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   This function is an example set of configurations necessary
 *                to be performed for the IIS controller. It should be noted
 *                that several other settings are required (board setup) to 
 *                be able to utilize the IIS interface correctly as an output.
 *                Be aware the the sub-functions return-errors checking - any
 *                sub-function error will cause this function to fail, however
 *                some settings might be already written to the IIS controller
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_InitAsDAC(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      eIIS_SetWrdSelTxPol
 *
 * Purpose:       Configure the WS signal start and the transmit mode
 *                polarities on the IIS bus
 *
 * Inputs:        eCh         IIS channel (interface)
 *                eWrdSelPol  Start level 
 *                eTxPol      Transmit polarity
 *
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   none
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_SetWrdSelTxPol(iis_Ch_e eCh, iis_WrdSelPol_e eWrdSelPol,
                                  iis_TxPol_e eTxPol);


/****************************************************************************
 *
 * Function:      eIIS_SetErrResolve
 *
 * Purpose:       Configure (available in master mode) the IIS bus controller
 *                behavior in case of data reception under the FIFO full (overflow)
 *                and in case of data transmission under the FIFO empty (underflow)
 *                conditions.
 *
 * Inputs:        eCh         IIS channel (interface)
 *                eErrOvrRes  Overflow error handling 
 *                eErrUdrRes  Underflow error handling 
 *
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   none
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_SetErrResolve (iis_Ch_e eCh, iis_ErrOvrRes_e eErrOvrRes,
                                  iis_ErrUdrRes_e eErrUdrRes);


/****************************************************************************
 *
 * Function:      eIIS_SetModeDir
 *
 * Purpose:       Configure the IIS bus controller Master/Slave mode as well as
 *                the transmission direction. The transmission or reception will 
 *                be disabled after the mode change and should be separately 
 *                enabled by another driver API function
 *
 * Inputs:        eCh    IIS channel (interface)
 *                eMode  Master / Slave operating mode 
 *                eDir   TX / RX direction 
 *
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   none
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_SetModeDir(iis_Ch_e eCh, iis_Mode_e eMode, iis_Dir_e eDir);


/****************************************************************************
 *
 * Function:      eIIS_SetTxRxOper
 *
 * Purpose:       Enable/disable the IIS bus controller transmission or reception
 *                (depending on the current direction)
 *
 * Inputs:        eCh        IIS channel (interface)
 *                eTrsfOper  Enable / Disable transfer (RX/TX) operation
 *
 * Outputs: none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   none
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_SetTxRxOper (iis_Ch_e eCh, iis_TrsfOper_e eTrsfOper);


/****************************************************************************
 *
 * Function:      eIIS_SetWidthLength
 *
 * Purpose:       Set the number of valid bits to be transmitted during one
 *                word-select period and the length of the WS signal by 
 *                defining the number of clock cycles
 *
 * Inputs:        eCh         IIS channel (interface)
 *                eDataWidth  Number of valid bits to be transmitted (during one
 *                            word select period)
 *                eWsLen      Number of clock cycles per word-select interval
 *
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   none
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_SetWidthLength(iis_Ch_e eCh, iis_DataWid_e eDataWidth,
                                  iis_WsLen_e eWsLen);


/****************************************************************************
 *
 * Function:      eIIS_SetMClkOper
 *
 * Purpose:       Enable/disable the IIS controller module clock. It should
 *                be disabled while configuring the MCLK settings
 *                
 * Inputs:        eCh        IIS channel (interface)
 *                eMClkOper  MCLK Enable / disable 
 *                
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   none
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_SetMClkOper(iis_Ch_e eCh, iis_MClkOper_e eMClkOper);


/****************************************************************************
 *
 * Function:      eIIS_GetMClkOper
 *
 * Purpose:       Retrieve the current MCLK enable/disable bit state
 *                                
 * Inputs:        eCh  IIS channel (interface)
 *                                
 * Outputs:       none
 *
 * Return Values: MCLKEN bit status (iis_MClkOper_e enumeration type)
 *
 * Limitations:   none
 *
 ***************************************************************************/
iis_MClkOper_e eIIS_GetMClkOper(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      eIIS_SetClkAttr
 *
 * Purpose:       Configures clock/bit-clock attributes (source, dividers, 
 *                output and latch-time) of a IIS controller channel
 *
 * Inputs:        eCh         IIS channel (interface)
 *                eMClkOut    Module clock (MCLK) output enable / disable
 *                eLatchTime  Latch time
 *                eBClkDiv    Bit clock (BCLK) divider
 *                
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   none
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_SetClkAttr(iis_Ch_e eCh,iis_MClkOut_e eMClkOut,
                              iis_LatchTime_e eLatchTime, iis_BClkDiv_e eBClkDiv);


/****************************************************************************
 *
 * Function:      vIIS_DisableInt
 *
 * Purpose:       Mask (disable) selected interrupts. Only interrupt sources
 *                explicitly given as an "OR-ed" combination will be affected
 *
 * Inputs:        eCh     IIS channel (interface)
 *                u8Mask  Combination of interrupt sources to be masked
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vIIS_DisableInt(iis_Ch_e eCh, uint8_t u8Mask);


/****************************************************************************
 *
 * Function:      vIIS_EnableInt
 *
 * Purpose:       Unmask (enable) selected interrupts. Only interrupt sources
 *                explicitly given as an "OR-ed" combination will be affected
 *
 * Inputs:        eCh     IIS channel (interface)
 *                u8Mask  Combination of interrupt sources to be unmasked
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vIIS_EnableInt(iis_Ch_e eCh, uint8_t u8Mask);


/****************************************************************************
 *
 * Function:      vIIS_ClearIrq
 *
 * Purpose:       Clear selected interrupts. Only interrupt sources explicitly
 *                given as an "OR-ed" combination will be affected by this 
 *                function (affects only RX and TX error interrupts). Other 
 *                interrupt sources cannot be cleared by this function i.e. 
 *                the real reason for the interrupt must be eliminated instead
 *
 * Inputs:        eCh      IIS channel (interface)
 *                u32Mask  Combination of interrupt sources to be cleared
 *
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vIIS_ClearIrq(iis_Ch_e eCh, uint32_t u32Mask);


/****************************************************************************
 *
 * Function:      u8IIS_GetIrqStatus
 *
 * Purpose:       Retrieve the current interrupt status of the IIS controller
 *
 * Inputs:        eCh  IIS channel (interface) selection
 *
 *
 * Outputs:       none
 *
 * Return Values: Bit combination reflecting the active interrupt sources
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8IIS_GetIrqStatus(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      u32IIS_GetFifoStatus
 *
 * Purpose:       Retrieve the current status of the RX and TX FIFOs
 *
 * Inputs:        eCh  IIS channel (interface) selection
 *
 *
 * Outputs:       none
 *
 * Return Values: Bit combination reflecting the FIFOs status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32IIS_GetFifoStatus(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      u16IIS_GetCtrlReg
 *
 * Purpose:       Retriev the current control register value
 *
 * Inputs:        eCh  IIS channel (interface)
 *
 * Outputs:       none
 *
 * Return Values: Bit combination reflecting the settings in the control
 *                register
 *
 * Limitations:   To be used for debug and driver validation purposes only
 *
 ***************************************************************************/
uint16_t u16IIS_GetCtrlReg(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      u16IIS_GetLengthReg
 *                
 * Purpose:       Retrieve the current data length configuration
 *                
 * Inputs:        eCh  IIS channel (interface)
 *
 * Outputs:       none
 *
 * Return Values: Bit combination reflecting the settings in the control
 *                register
 *
 * Limitations:   To be used for debug and driver validation purposes only
 *
 ***************************************************************************/
uint16_t u16IIS_GetLengthReg(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      u32IIS_GetClkCfgReg
 *                
 * Purpose:       Retrieve the current clock settings of a IIS controller 
 *                channel
 *             
 * Inputs:        eCh  IIS channel (interface)
 *
 * Outputs:       none
 *
 * Return Values: Bit combination reflecting the settings in the clock
 *                configuration register
 *
 * Limitations:   To be used for debug and driver validation purposes only
 *
 ***************************************************************************/
uint32_t u32IIS_GetClkCfgReg(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      u8IIS_GetIntMaskReg
 *
 * Purpose:       Retrieve the current settings of the IIS controller interrupt
 *                mask register 
 *
 * Inputs:        eCh  IIS channel (interface)
 *
 * Outputs:       none
 *
 * Return Values: Bit combination reflecting the settings in the interrupt
 *                mask register
 *
 * Limitations:   To be used for debug and driver validation purposes only
 *
 ***************************************************************************/
uint8_t u8IIS_GetIntMaskReg(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      vIIS_WriteWord
 *
 * Purpose:       Write a single data word (up to 32-bits) to the IIS controller
 *                Transmit Data Register (TX FIFO), thus transmit it over the IIS
 *                bus
 *
 * Inputs:        eCh      IIS channel (interface)
 *                u32Data  Data word to be send over the IIS bus
 *
 *
 * Outputs:       none
 *
 * Return Values: Initialization error / status code
 *
 * Limitations:   The TX FIFO must have at least one entry available for the
 *                data before this function is called
 *
 ***************************************************************************/
void vIIS_WriteWord(iis_Ch_e eCh, uint32_t u32Data);


/****************************************************************************
 *
 * Function:      u32IIS_ReadWord
 *
 * Purpose:       Reads one byte from the IIS controller RX FIFO
 *
 * Inputs:        eCh  IIS channel (interface)
 *
 * Outputs:       none
 *
 * Return Values: The data word retrieved from the IIS RX buffer
 *
 * Limitations:   The RX FIFO must have at least one entry available for the
 *                data before this function is called
 *
 ***************************************************************************/
uint32_t u32IIS_ReadWord(iis_Ch_e eCh);


/****************************************************************************
 *
 * Function:      eIIS_WriteData
 *
 * Purpose:       Trasmit data sample
 *
 * Inputs:        eCh         IIS channel (interface)
 *                u32DataLen  Number of valid data bytes to be transmitted
 *                u32Data     Transmit data buffer
 *
 * Outputs:       none
 *
 * Return Values: Status/error code depending on the context
 *
 * Limitations:   This function is only an example of the IIS interface,
 *                implemeting FIFO status polling mechanism. It should be 
 *                used only as a reference. IIS interrupts together with 
 *                DMA utilisation shall lbe used for real applications
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_WriteData(iis_Ch_e eCh, uint32_t u32DataLen, 
                             const uint32_t u32Data[]);


/****************************************************************************
 *
 * Function:      eIIS_ReadData
 *
 * Purpose:       Read data sample
 *
 * Inputs:        eCh      IIS channel (interface)
 *                u32Data  Reception data buffer
 *
 * Outputs:       Filled reception data buffer
 *
 * Return Values: Status/error code depending on the context
 *
 * Limitations:   This function is only an example of the IIS interface,
 *                implemeting FIFO status polling mechanism. It should be 
 *                used only as a reference. IIS interrupts together with 
 *                DMA utilisation shall lbe used for real applications
 *
 ***************************************************************************/
iis_ErrCode_e eIIS_ReadData(iis_Ch_e eCh, uint32_t *pu32DataLen, uint32_t u32Data[]);

/****************************************************************************/


#endif /* IIS_H */

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

