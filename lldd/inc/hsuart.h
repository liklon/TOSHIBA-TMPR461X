/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : High-Speed UART Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Asynchronous Serial Interface (HSUART)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef HSUART_H
#define HSUART_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_UART_H_REVISION     "$Revision: 1.12 $"
#define LLDD_UART_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/****************************************************************************
*                          CHANNEL SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/

/*!< UART channel */
typedef enum tag_UartCh_e
{
    UART_CH0 = 0,                       /*!< Channel 0 */
    UART_CH1                            /*!< Channel 1 */
} uart_Ch_e;


/*
 *  SILCR parameter values
 */

/*!< SILCR.RWUB - Receive wake-up bit */
typedef enum tag_UartRwub_e
{
    UART_NOT_WAIT_WUB = 0,              /*!< Do not wait for a wake-up-bit */
    UART_WAIT_WUB                       /*!< Wait for a wake-up-bit */
} uart_Rwub_e;

/*!< SILCR.TWUB - Transmit wake-up bit */
typedef enum tag_uart_Twub_e
{
    UART_NFRAME_DATA = 0,               /*!< Next frame contains data */
    UART_NFRAME_ADDR                    /*!< Next frame contains address */
} uart_Twub_e;

/*!< SILCR.LSBF - LSBit/MSBit first */
typedef enum tag_uart_Lsbf_e
{
    UART_MSB = 0,                       /*!< Reads/sends the MSBit first */
    UART_LSB                            /*!< Reads/sends the LSBit first */
} uart_Lsbf_e;

/*!< SILCR.UEPS - odd/even parity  */
typedef enum tag_uart_Ueps_e
{
    UART_ODD = 0,                       /*!< Odd parity */
    UART_EVEN                           /*!< Even parity */
} uart_Ueps_e;

/*!< SILCR.UPEN - parity enable */
typedef enum tag_uart_Upen_e
{
    UART_PARITY_DIS = 0,                /*!< Disable parity check */
    UART_PARITY_EN                      /*!< Enable parity check */
} uart_Upen_e;

/*!< SILCR.USBL - stop bit length */
typedef enum tag_uart_Usbl_e
{
    UART_ONE_BIT = 0,                   /*!< One bit */
    UART_TWO_BITS                       /*!< Two bits */
} uart_Usbl_e;

/*!< SILCR.UMODE - mode of operation */
typedef enum tag_uart_Umode_e
{
    UART_8BIT = 0,                      /*!< 8-bit data length */
    UART_7BIT,                          /*!< 7-bit data length */
    UART_8BIT_MULTI,                    /*!< Multi-controller 8-bit data length */
    UART_7BIT_MULTI                     /*!< Multi-controller 7-bit data length */
} uart_Umode_e;


/*
 *  SIDICR parameter values
 */

/*!< SIDICR.xxx - enable/disable values  */
typedef enum tag_uart_IrqEn_e
{
    UART_IRQ_DIS = 0,                   /*!< Disable interrupt  */
    UART_IRQ_EN                         /*!< Enable interrupt */
} uart_IrqEn_e;

/*!< SIDICR.CTSAC - CTS status active condition */
typedef enum tag_uart_Ctsac_e
{
    UART_CTS_DIS = 0,                   /*!< Disable CTS */
    UART_CTS_RISE,                      /*!< CTS terminal rising edge */
    UART_CTS_FALL,                      /*!< CTS terminal falling edge */
    UART_CTS_BOTH                       /*!< CTS both edges */
} uart_Ctsac_e;

/*!< SIDICR.SIUB - status interrupt on break of transfer */
typedef enum tag_uart_Siub_e
{
    UART_BRK_DET_DIS = 0,               /*!< Break detection disabled */
    UART_BRK_DET_EN                     /*!< Break detection enabled */
} uart_Siub_e;


/*
 *  SIFCR parameter values
 */

/*!< SIFCR.SWRST - software reset */
typedef enum tag_uart_SwRst_e
{
    UART_RST_RELEASE = 0,               /*!< Normal operation */
    UART_RST_ACTIVE                     /*!< Reset activated */
} uart_SwRst_e;

/*!< SIFCR.FRSTEW - FIFO reset allowance  */
typedef enum tag_uart_FrStew_e
{
    UART_FIFO_RST_DIS = 0,              /*!< Resets of Tx/Rx FIFO are inhibited */
    UART_FIFO_RST_EN                    /*!< Resets of Tx/Rx FIFO are possible */
} uart_FrStew_e;


/*
 *  SIFLCR parameter values
 */

/*!< SIFLCR.RTSSC - RTS terminal level */
typedef enum tag_uart_Rtssc_e
{
    UART_RTS_LOW = 0,                   /*!< RTS terminal will be set to low  */
    UART_RTS_HIGH                       /*!< RTS terminal will be set to high */
} uart_Rtssc_e;

/*!< SIFLCR.RSDR - Receive serial data request */
typedef enum tag_uart_Rsdr_e
{
    UART_DATA_STORE = 0,                /*!< Received data will be stored */
    UART_DATA_IGNORE                    /*!< Received data will not be stored */
} uart_Rsdr_e;

/*!< SIFLCR.TSDR - Transmit serial data request */
typedef enum tag_uart_Tsdr_e
{
    UART_TRANS_RUN = 0,                 /*!< Transmission in progress */
    UART_TRANS_HALT                     /*!< Transmission halted */
} uart_Tsdr_e;

/*!< SIFLCR.RTSTL - RTS trigger level */
typedef enum tag_uart_Rtstl_e
{
    UART_RTS_TRIGGER_LEVEL_1  = 0x0,    /*!< trigger level at  1 byte  */
    UART_RTS_TRIGGER_LEVEL_2  = 0x1,    /*!< trigger level at  2 bytes */
    UART_RTS_TRIGGER_LEVEL_3  = 0x2,    /*!< trigger level at  3 bytes */
    UART_RTS_TRIGGER_LEVEL_4  = 0x3,    /*!< trigger level at  4 bytes */
    UART_RTS_TRIGGER_LEVEL_5  = 0x4,    /*!< trigger level at  5 bytes */
    UART_RTS_TRIGGER_LEVEL_6  = 0x5,    /*!< trigger level at  6 bytes */
    UART_RTS_TRIGGER_LEVEL_7  = 0x6,    /*!< trigger level at  7 bytes */
    UART_RTS_TRIGGER_LEVEL_8  = 0x7,    /*!< trigger level at  8 bytes */
    UART_RTS_TRIGGER_LEVEL_9  = 0x8,    /*!< trigger level at  9 bytes */
    UART_RTS_TRIGGER_LEVEL_10 = 0x9,    /*!< trigger level at 10 bytes */
    UART_RTS_TRIGGER_LEVEL_11 = 0xA,    /*!< trigger level at 11 bytes */
    UART_RTS_TRIGGER_LEVEL_12 = 0xB,    /*!< trigger level at 12 bytes */
    UART_RTS_TRIGGER_LEVEL_13 = 0xC,    /*!< trigger level at 13 bytes */
    UART_RTS_TRIGGER_LEVEL_14 = 0xD,    /*!< trigger level at 14 bytes */
    UART_RTS_TRIGGER_LEVEL_15 = 0xE,    /*!< trigger level at 15 bytes */
    UART_RTS_TRIGGER_LEVEL_16 = 0xF     /*!< trigger level at 16 bytes */
} uart_Rtstl_e;

/*!< SIFLCR.TBRK - Transmitter break */
typedef enum tag_uart_Tbrk_e
{
    UART_TRANS_NORM = 0,                /*!< Normal operation */
    UART_TRANS_BREAK                    /*!< Transmit a break */
} uart_Tbrk_e;

/*!< SIFLCR.TRS - TX request select */
typedef enum tag_uart_Trs_e
{
    UART_BY_TSDR = 0,                   /*!< control by TRSD */
    UART_BY_CTS_TERMINAL                /*!< control by CTS terminal */
} uart_Trs_e;

/*!< SIFLCR.RCS - RTS control select */
typedef enum tag_uart_Rcs_e
{
    UART_BY_SOFTWARE = 0,               /*!< control by software */
    UART_BY_SOFTWARE_OR_HARDWARE        /*!< control by software or hardware */
} uart_Rcs_e;


/*
 *  SIBGR parameter values
 */

/*!< SIBGR.BCLK - Baud rate generator clock */
typedef enum tag_uart_Bclk_e
{
    UART_DIV_2   = 0x0,                 /*!< 1/2 system frequency */
    UART_DIV_8   = 0x1,                 /*!< 1/8 system frequency */
    UART_DIV_32  = 0x2,                 /*!< 1/32 system frequency */
    UART_DIV_128 = 0x3,                 /*!< 1/128 system frequency */
    UART_NO_DIV  = 0x4                  /*!< System frequency (no division) */
} uart_Bclk_e;


/*
 *  SIDISR field masks
 */

/*!< DMA/Interrupt atatus bit-field masks */
typedef enum tag_uart_DmaIrqMask_e
{
    UART_MSK_UBRK   = 0x8000,           /*!< Break */
    UART_MSK_UVALID = 0x4000,           /*!< No data available */
    UART_MSK_ERI    = 0x0400,           /*!< Error interrupt */
    UART_MSK_TOUT   = 0x0200,           /*!< Receive time-out */
    UART_MSK_TDIS   = 0x0100,           /*!< Transmit DMA/Interrupt status */
    UART_MSK_RDIS   = 0x0080,           /*!< Receive DMA/Interrupt status */
    UART_MSK_STIS   = 0x0040            /*!< Status interrupt status */
} uart_DmaIrqMask_e;

/*!< Status clear masks */
typedef enum tag_uart_Flag_e
{
    UART_FLG_ERI  = 0x0400,             /*!< Error interrupt */
    UART_FLG_TOUT = 0x0200,             /*!< Receive time-out */
    UART_FLG_TDIS = 0x0100,             /*!< Transmit DMA/Interrupt status */
    UART_FLG_RDIS = 0x0080,             /*!< Receive DMA/Interrupt status */
    UART_FLG_STIS = 0x0040,             /*!< Status interrupt status */
    UART_FLG_OERS = 0x0020,             /*!< Overrun error status */
    UART_FLG_UBRK = 0x0001              /*!< Break */
}uart_Flag_e;


/*
 *  SISCISR field masks
 */

/*!< Status change register bit-field masks */
typedef enum tag_uart_SisMask_e
{
    UART_MSK_OERS  = 0x0020,            /*!< Overrun error status */    
    UART_MSK_CTSS  = 0x0010,            /*!< CTS timer status */    
    UART_MSK_RBRKD = 0x0008,            /*!< Receive break */
    UART_MSK_TRDY  = 0x0004,            /*!< TX ready */
    UART_MSK_TXALS = 0x0002,            /*!< TX all */
    UART_MSK_UBRKD = 0x0001             /*!< UART break detect */
} uart_SisMask_e;

/*!< CTS terminal status */
typedef enum tag_uart_Ctss_e
{
    UART_CTS_DEASSERTED = 0x0,          /*!< CTS terminal is deasserted */    
    UART_CTS_ASSERTED   = 0x1           /*!< CTS terminal is asserted */
} uart_Ctss_e;


/*
 *  Baud rate values
 */

/*!< Baud Rate value assuming system clock @ 160MHz - TODO */
typedef enum tag_uart_BdRate_e
{    
    UART_BR_4800   = 0x17A,             /*!< Prescaler 1/8, Divisor 122 */
    UART_BR_9600   = 0x13D,             /*!< Prescaler 1/8, Divisor  61 */
    UART_BR_14400  = 0x0A3,             /*!< Prescaler 1/2, Divisor 163 */
    UART_BR_19200  = 0x07A,             /*!< Prescaler 1/2, Divisor 122 */
    UART_BR_38400  = 0x03D,             /*!< Prescaler 1/2, Divisor  61 */ 
    UART_BR_57600  = 0x029,             /*!< Prescaler 1/2, Divisor  41 */ 
    UART_BR_115200 = 0x014              /*!< Prescaler 1/2, Divisor  20 */  
} uart_BdRate_e;    

/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/

/*!< Line/Data Format configuration structure */
typedef struct tag_uart_DataFmt_st
{
    uart_Rwub_e eRwub;                  /*!< Receive wake-up bit */
    uart_Twub_e eTwub;                  /*!< Transmit wake-up bit */
    uart_Lsbf_e eLsbf;                  /*!< LSB/MSB first */
    uart_Ueps_e eUeps;                  /*!< Parity */
    uart_Upen_e eUpen;                  /*!< Parity check */
    uart_Usbl_e eUsbl;                  /*!< Stop bit length */
    uart_Umode_e eUmode;                /*!< UART mode */
} uart_DataFmt_st;

/*!< DMA/IRQ configuration structure */
typedef struct tag_uart_DmaIrq_st
{
    uart_IrqEn_e eTir;                 /*!< Transmit interrupt request on/off */
    uart_IrqEn_e eRir;                 /*!< Receive interrupt request on/off */
    uart_IrqEn_e eSpir;                /*!< Status interrupt request on/off */
    uart_Ctsac_e eCtsac;               /*!< Status active condition */
    uart_IrqEn_e eRxTout;              /*!< Interrupt on time-out on/off */
    uart_IrqEn_e eSioe;                /*!< Interrupt on overrun error on/off */
    uart_IrqEn_e eSicts;               /*!< Interrupt on receive of CTS on/off */
    uart_IrqEn_e eSibrk;               /*!< Interrupt on break of UART Transfer on/off */
    uart_IrqEn_e eSitr;                /*!< Interrupt on free space in TX-FIFO on/off */
    uart_IrqEn_e eSias;                /*!< Interrupt when all data sent on/off */
    uart_Siub_e  eSiub;                /*!< Interrupt on break of transfer on/off */
} uart_DmaIrq_st;

/*!< FIFO configuration structure */
typedef struct tag_uart_Fifo_st
{
    uint8_t u8Rdil;                     /*!< Receive DMA/IRQ trigger level (0-15) */
    uint8_t u8Tdil;                     /*!< Transmit DMA/IRQ trigger level (0-15) */
    uart_FrStew_e eFrStew;              /*!< FIFO reset enable/disable */
} uart_Fifo_st;

/*!< Flow control configuration structure */
typedef struct tag_uart_Flow_st
{
    uart_Rsdr_e eRsdr;                  /*!< Receive serial data request */
    uart_Tsdr_e eTsdr;                  /*!< Transmit serial data request */
    uart_Tbrk_e eTbrk;                  /*!< Transmitter break */
    uart_Trs_e eTrs;                    /*!< TX request select */
    uart_Rcs_e eRcs;                    /*!< RTS control select */
} uart_Flow_st;

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/**
* @brief Implementation of function vUART_GetVersion
*
* Retrieve pointers to module and header revision and tag string
*
* @note No Limitations
*
* @param[in] None
*
* @param[in,out] pau8ModuleRevision - pointer to module revision string
* @param[in,out] pau8ModuleTag      - pointer to module tag string
* @param[in,out] pau8HeaderRevision - pointer to header revision string
* @param[in,out] pau8HeaderTag      - pointer to header tag string
* @param[in,out] pau8IORevision     - pointer to IO header revision string
* @param[in,out] pau8IOTag          - pointer to IO header tag string
*
* @return void
*/
void vUART_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/**
* @brief Implementation of function vUART_Init
*
* HSUART initialization
*
* @note No Limitations
*
* @param[in] eCh         - Channel 
* @param[in] eBaudRate   - Baudrate 
* @param[in] stDataCfg   - Pointer to Line/Data format
* @param[in] stDmaIrqCfg - Pointer to DMA/IRQ configuration
*
* @param[in,out] None
*
* @return void
*/
void vUART_Init(uart_Ch_e eCh, uart_BdRate_e eBaudRate,
                uart_DataFmt_st * stDataCfg, uart_DmaIrq_st * stDmaIrqCfg);


/**
* @brief Implementation of function vUART_DataFmtConfig
*
* Line/Data format configuration
*
* @note No Limitations
*
* @param[in] eCh        - Uart channel 
* @param[in] pstDataFmt - Pointer to Line/data format configuration request
*
* @param[in,out] None
*
* @return void
*/
void vUART_DataFmtConfig(uart_Ch_e eCh, uart_DataFmt_st * pstDataFmt);


/**
* @brief Implementation of function vUART_DmaIrqConfig
*
* DMA / IRQ request configuration
*
* @note No Limitations
*
* @param[in] eCh       - Uart channel 
* @param[in] pstDmaIrq - Pointer to DMA/IRQ configuration request
*
* @param[in,out] None
*
* @return void
*/
void vUART_DmaIrqConfig(uart_Ch_e eCh, uart_DmaIrq_st * pstDmaIrq);


/**
* @brief Implementation of function vUART_FifoConfig
*
* Transmit and receive FIFOs configuration
*
* @note No Limitations
*
* @param[in] eCh     - Uart channel 
* @param[in] pstFifo - Pointer to Fifo configuration
*
* @param[in,out] None
*
* @return void
*/
void vUART_FifoConfig(uart_Ch_e eCh, uart_Fifo_st * pstFifo);


/**
* @brief Implementation of function vUART_FlowCtrlConfig
*
* Flow control configuration
*
* @note No Limitations
*
* @param[in] eCh     - Uart channel 
* @param[in] pstFlow - Pointer to Flow control request
*
* @param[in,out] None
*
* @return void
*/
void vUART_FlowCtrlConfig(uart_Ch_e eCh, uart_Flow_st * pstFlow);


/**
* @brief Implementation of function vUART_SetRTSTerminalLevel
*
* Set level of RTS terminal
*
* @note No Limitations
*
* @param[in] eCh    - Uart channel 
* @param[in] eLevel - Level on terminal
*
* @param[in,out] None
*
* @return void
*/
void vUART_SetRTSTerminalLevel(uart_Ch_e eCh, uart_Rtssc_e eLevel);


/**
* @brief Implementation of function eUART_GetCTSTerminalStatus
*
* Read CTS terminal status
*
* @note No Limitations
*
* @param[in] eCh - Uart channel 
*
* @param[in,out] None
*
* @return UART_CTS_DEASSERTED if CTS terminal is deasserted    
* @return UART_CTS_ASSERTED if CTS terminal is asserted
*/
uart_Ctss_e eUART_GetCTSTerminalStatus(uart_Ch_e eCh);


/**
* @brief Implementation of function vUART_SetRTSTriggerLevel
*
* Set level of RTS trigger level
*
* @note No Limitations
*
* @param[in] eCh    - Uart channel 
* @param[in] eLevel - Trigger level
*
* @param[in,out] None
*
* @return void
*/
void vUART_SetRTSTriggerLevel(uart_Ch_e eCh, uart_Rtstl_e eLevel);


/**
* @brief Implementation of function vUART_GetTransferStat
*
* Retrieve the status of the current transfer
*
* @note No Limitations
*
* @param[in] eCh - Uart channel 
*
*
* @param[in,out]  pu8Status - The value of the Status change (SISCISR) register
*                             Please use the masks defined in EUartSisMask to
*                             evaluate / parse the register value
*
* @return void
*/
void vUART_GetTransferStat(uart_Ch_e eCh, uint8_t *pu8Status);


/**
* @brief Implementation of function vUART_SetBaudRate
*
* HSUART Baud-rate setting
*
* @note No Limitations
*
* @param[in] eCh       - Uart channel
* @param[in] eBaudRate - Baud-rate 
*
* @param[in,out] None
*
* @return void
*/
void vUART_SetBaudRate(uart_Ch_e eCh, uart_BdRate_e eBaudRate);


/**
* @brief Implementation of function i32UART_GetBaudRate
*
* Retrieve current baud-rate value
*
* @note No Limitations
*
* @param[in] eCh - Uart channel 
*
* @param[in,out] pu32BaudRate - Current baud-rate value in [bps]
*
* @return C_SUCCESS if baudrate could be set
* @return C_FAILED in case of wrong baudrate
*/
int32_t i32UART_GetBaudRate(uart_Ch_e eCh, uint32_t *pu32BaudRate);


/**
* @brief Implementation of function i32UART_WriteByte
*
* Write one data byte to the TX-FIFO
*
* @note No Limitations
*
* @param[in] eCh    - Uart channel 
* @param[in] u8Data - Data byte to be sent
*
* @param[in,out] None
*
* @return C_SUCCESS on success
* @return C_FAILED  on fifo not ready
*/
int32_t i32UART_WriteByte(uart_Ch_e eCh, uint8_t u8Data);


/**
* @brief Implementation of function u32UART_WriteData
*
* Write data buffer to the TX-FIFO (polling)
*
* @note No Limitations
*
* @param[in] eCh     - Uart channel
* @param[in] pu8Data - Data buffer to be transmitted
* @param[in] u32Len  - Number of bytes to be sent
*
* @param[in,out] None
*
* @return Number of written bytes
*/
uint32_t u32UART_WriteData(uart_Ch_e eCh, const uint8_t *pu8Data, uint32_t u32Len);


/**
* @brief Implementation of function i32UART_ReadByte
*
* Retrieve one byte from the RX-FIFO
*
* @note A check for error occurance must be always made before
*       this function is invoked
*
* @param[in] eCh - Uart channel 
*
* @param[in,out] pu8Data - Data retrieved from FIFO
*
* @return C_SUCCESS if data are read from Rx FIFO
* @return C_FAILED if no data are in Rx FIFO
*/
int32_t i32UART_ReadByte(uart_Ch_e eCh, uint8_t *pu8Data);


/**
* @brief Implementation of function i32UART_ReadData
*
* Retrieve all available data from the RX-FIFO
*
* @note Please note that function will stop reading data on 
*       occurence of any of the following events:
*          1. Parity error
*          2. Overrun error
*          3. Frame error
*
* @param[in] eCh - Uart channel
*
* @param[in,out] pu8Data - Data retrieved from FIFO
* @param[in,out] pu32Len - Number of retrieved data-bytes
*
* @return C_SUCCESS on success
* @return C_FAILED  on error detection
*/
int32_t i32UART_ReadData(uart_Ch_e eCh, uint8_t *pu8Data, uint32_t *pu32Len);


/**
* @brief Implementation of function i32UART_IsTimeOut
*
* Check if receive time-out occured and clear the flag
*
* @note No Limitations
*
* @param[in] eCh - Uart channel selection
*
* @param[in,out] None
*
* @return Receive time-out status
*/
int32_t i32UART_IsTimeOut(uart_Ch_e eCh);


/**
* @brief Implementation of function u16UART_GetDmaIrqStat
*
* Retrieves the status of Transmit/Receive DMA interrupt
* register. Please use the masks defined in uart_DmaIrqMask_e 
* enumeration for result parsing/evaluation
*
* @note No Limitations
*
* @param[in] eCh - Uart channel
*
* @param[in,out] None
*
* @return Current interrupt status
*/
uint16_t u16UART_GetDmaIrqStat(uart_Ch_e eCh);


/**
* @brief Implementation of function vUART_ClearDmaIrqFlag
*
* Clear the status of selected transmit/receive DMA/Interrupt
*
* @note No Limitations
*
* @param[in] eCh   - Uart channel 
* @param[in] eFlag - Flag(s) to be cleared
*
* @param[in,out] None
*
* @return void
*/
void vUART_ClearDmaIrqFlag(uart_Ch_e eCh, uart_Flag_e eFlag);


/**
* @brief Implementation of function u8UART_GetRxDataCnt
*
* Retrieve the total number of received data frames currently 
* stored in the RX-FIFO
*
* @note No Limitations
*
* @param[in] eCh - Uart channel 
*
* @param[in,out] None
*
* @return Number of data-bytes in the RX-FIFO
*/
uint8_t u8UART_GetRxDataCnt(uart_Ch_e eCh);


/**
* @brief Implementation of function u32UART_IsTxFifoReady
*
* Check for free space in the TX-FIFO
*
* @note No Limitations
*
* @param[in] eCh - Uart channel
*
* @param[in,out] None
*
* @return 1 on TX-FIFO ready
* @return 0 on TX-FIFO not ready
*/
uint32_t u32UART_IsTxFifoReady(uart_Ch_e eCh);


/**
* @brief Implementation of function u32UART_IsTxFifoFree
*
* Check if both the TX-FIFO and the shift register are empty
*
* @note No Limitations
*
* @param[in] eCh - Uart channel
*
* @param[in,out] None
*
* @return 1 on empty
* @return 0 when at least one is not empty
*/
uint32_t u32UART_IsTxFifoFree(uart_Ch_e eCh);


/**
* @brief Implementation of function vUART_Reset
*
* Performs reset of a HSUART module
*
* @note The 5-cycle wait has to be applied when I-cache is used
*
* @param[in] eCh - Uart channel
*
* @param[in,out] None
*
* @return void
*/
void vUART_Reset(uart_Ch_e eCh);


/**
* @brief Implementation of function vUART_FifoResetTx
*
* Reset the TX-FIFO
*
* @note No Limitations
*
* @param[in] eCh    - Uart channel selection
* @param[in] eRstEn - Reset activation
*
* @param[in,out] None
*
* @return void
*/
void vUART_FifoResetTx(uart_Ch_e eCh, uart_SwRst_e eRstEn);


/**
* @brief Implementation of function vUART_FifoResetRx
*
* Reset the RX-FIFO
*
* @note No Limitations
*
* @param[in] eCh    - Uart channel
* @param[in] eRstEn - Reset activation
*
* @param[in,out] None
*
* @return void
*/
void vUART_FifoResetRx(uart_Ch_e eCh, uart_SwRst_e eRstEn);


/**
* @brief Implementation of function vUART_TxRunCtrl
*
* Start/stop the current transmission
*
* @note No Limitations
*
* @param[in] eCh      - Uart channel
* @param[in] eRunCtrl - Start/stop requets
*
* @param[in,out] None
*
* @return void
*/
void vUART_TxRunCtrl(uart_Ch_e eCh, uart_Tsdr_e eRunCtrl);


/**
* @brief Implementation of function vUART_TxBreak
*
* Forced break transmission configuration
*
* @note No Limitations
*
* @param[in] eCh    - Uart channel
* @param[in] eBreak - Breka/no break
*
* @param[in,out] None
*
* @return void
*/
void vUART_TxBreak(uart_Ch_e eCh, uart_Tbrk_e eBreak);


/****************************************************************************/


#endif /* _HSUART_H */

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

