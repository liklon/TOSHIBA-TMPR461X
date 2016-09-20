/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Serial Bus Interface (I2C) Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Serial Bus Interface (SBI) / I2C
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef IIC_H
#define IIC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                /* Core specific primitive type definitions */

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_IIC_H_REVISION     "$Revision: 1.10 $"
#define LLDD_IIC_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/* Reset bit-masks */
#define IIC_1ST_RESET_VAL         0x2
#define IIC_2ND_RESET_VAL         0x1

/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/

/**
* @brief IIC initialization error codes
*/
typedef enum tag_iic_InitErrorCodes_e
{
    IIC_INIT_OK       = 0,               /*!< Correct initialization */
    IIC_INIT_BC_ERR   = 1,               /*!< Unsupported number of bits */
    IIC_INIT_ACK_ERR  = 2,               /*!< Invalid acknowledge cycle  */
    IIC_INIT_SCK_ERR  = 3,               /*!< Unsuppported clock setting */
    IIC_INIT_SA_ERR   = 4,               /*!< Invalid slave address [slave mode] */
    IIC_INIT_ALS_ERR  = 5                /*!< Incorrect address recognition mode [slave mode] */
} iic_InitErrors_e;

/**
* @brief IIC transfer status/error codes
*/
typedef enum tag_iic_ErrorCodes_e
{
    IIC_READY            = 0,            /*!< TX/RX complete */
    IIC_BUSY_TIMEOUT     = 1,            /*!< Bus busy time-out */
    IIC_IRQ_ACK_TIMEOUT  = 2,            /*!< Acknowledge time-out */
    IIC_CLK_LINE_TIMEOUT = 3,            /*!< Clock line LOW state time-out */
    IIC_NOT_READY        = 4             /*!< Bus not ready */
} iic_ErrorCodes_e;

/**
* @brief IIC R/W direction bit values on the IIC bus
*/
typedef enum tag_iic_SendDirBit_e
{
    IIC_WR_TO_SLAVE   = 0x0,
    IIC_RD_FROM_SLAVE = 0x1
} iic_SendDirBit_e;

/**
* @brief IIC  output clock frequency
*/
typedef enum tag_iic_OutClkFreq_e
{
    IIC_OUTCLK_340_KHZ = 0x0,            /*!< n = 4, 340.9 kHz */
    IIC_OUTCLK_197_KHZ = 0x1,            /*!< n = 5, 197.3 kHz */
    IIC_OUTCLK_103_KHZ = 0x2,            /*!< n = 6, 107.1 kHz */
    IIC_OUTCLK_56_KHZ  = 0x3,            /*!< n = 7, 55.9 kHz */
    IIC_OUTCLK_28_KHZ  = 0x4,            /*!< n = 8, 28.6 kHz */
    IIC_OUTCLK_14_KHZ  = 0x5,            /*!< n = 9, 14.5 kHz */
    IIC_OUTCLK_7_KHZ   = 0x6             /*!< n = 10 7.2 kHz */  
} iic_OutClkFreq_e;

/**
* @brief IIC number of data bits
*/
typedef enum tag_iic_NoOfBits_e
{
    IIC_DATA_BITS_8 = 0x0,               /*!< 8 bits */
    IIC_DATA_BITS_1 = 0x1,               /*!< 1 bits */
    IIC_DATA_BITS_2 = 0x2,               /*!< 2 bits */
    IIC_DATA_BITS_3 = 0x3,               /*!< 3 bits */
    IIC_DATA_BITS_4 = 0x4,               /*!< 4 bits */
    IIC_DATA_BITS_5 = 0x5,               /*!< 5 bits */
    IIC_DATA_BITS_6 = 0x6,               /*!< 6 bits */
    IIC_DATA_BITS_7 = 0x7                /*!< 7 bits */  
} iic_NoOfBits_e;

/**
* @brief IIC acknowledge generation
*/
typedef enum tag_iic_AckCycle_e
{
    IIC_ACK_DISABLE = 0,                 /*!< Do not generate acknowledge cycle */
    IIC_ACK_ENABLE  = 1                  /*!< Generate acknowledge cycle */  
} iic_AckCycle_e;

/**
* @brief SBI operation mode
*/
typedef enum tag_iic_OperMode_e
{
    IIC_BUS_START_CONDITION   = 0xF8,    /*!< START */
    IIC_BUS_STOP_CONDITION    = 0xD8,    /*!< STOP */
    IIC_BUS_RELEASE_CONDITION = 0x18     /*!< Slave, RX, IRQ Cancel, SBI = IIC */
} iic_OperMode_e;

/**
* @brief IIC transfer direction
*/
typedef enum tag_iic_TransfDir_e
{
    IIC_RX_DIR = 0,                      /*!< Transmit */
    IIC_TX_DIR = 1                       /*!< Receive */
} iic_TransfDir_e;

/**
* @brief Master/slave controller mode/status
*/
typedef enum tag_iic_CtrlMode_e
{
    IIC_SLAVE_MODE  = 0,                 /*!< Slave mode */
    IIC_MASTER_MODE = 1                  /*!< Master mode */
} iic_CtrlMode_e;

/**
* @brief IIC bus status
*/
typedef enum tag_iic_BusyStat_e
{
    IIC_BUS_FREE = 0,                    /*!< Bus free */
    IIC_BUS_BUSY = 1                     /*!< Bus busy */
} iic_BusyStat_e;

/**
* @brief IIC controller interrupt status
*/
typedef enum tag_iic_IrqStat_e
{
    IIC_IRQ_PENDING = 0,                 /*!< Interrupt generated */
    IIC_IRQ_CANCEL  = 1                  /*!< Interrupt canceled */
} iic_IrqStat_e;

/**
* @brief IIC controller bus arbitration status
*/
typedef enum tag_iic_ArbitrStat_e
{
    IIC_ARBITR_NO_LOST = 0,              /*!< No arbitration lost */
    IIC_ARBITR_IS_LOST = 1               /*!< Arbitration lost detected */
} iic_ArbitrStat_e;

/**
* @brief IIC controller slave address match status
*/
typedef enum tag_iic_AdrMatchStat_e
{
    IIC_ADR_NO_MATCH = 0,                /*!< No "match" */
    IIC_ADR_IS_MATCH = 1                 /*!< Address "match" or general call detected */
} iic_AdrMatchStat_e;

/**
* @brief IIC controller General Call detection status
*/
typedef enum tag_iic_GenCallStat_e
{
    IIC_GEN_CALL_NO_DET = 0,             /*!< General Call is not deteced */
    IIC_GEN_CALL_IS_DET = 1              /*!< General Call is detected */
} iic_GenCallStat_e;

/**
* @brief IIC controller last received bit status
*/
typedef enum tag_iic_LastRxBitStat_e
{
    IIC_LST_BIT_ACK   = 0,               /*!< Last recieved bit is "0" */
    IIC_LST_BIT_NOACK = 1                /*!< Last recieved bit is "1" */
} iic_LastRxBitStat_e;

/**
* @brief IIC slave address recognition mode
*/
typedef enum tag_iic_AdrRecMode_e
{
    IIC_ADR_REC_ENABLE  = 0x0,           /*!< Address recognition enabled */
    IIC_ADR_REC_DISABLE = 0x1            /*!< Address recognition disabled */    
} iic_AdrRecMode_e;

/**
* @brief IIC slave mode and transfer direction
*/
typedef enum tag_iic_SlaveDirMode_e
{
    IIC_SLAVE_RX_MODE = 0x18,            /*!< Slave RX mode */
    IIC_SLAVE_TX_MODE = 0x58,            /*!< Slave TX mode */
} iic_SlaveDirMode_e;

/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/


/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/**
* @brief Implementation of function vIIC_GetVersion
*
* Retrieve pointers to module and header revision and tag string
*
* @note none
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
void vIIC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/**
* @brief Implementation of function eIIC_Init
*
* Reset, initilize and switch the SBI to IIC mode
*
* @note The slave address recognition mode must be explicitly set
*       via extra call of the IIC_SetAdrRecMode driver function
*
* @param[in] eNoOfBits   - Number of bits to transfer
* @param[in] eAckCycle   - Acknowledge cycle enable/disable
* @param[in] eOutClkFreq - Output clock frequency
* @param[in] u8SlaveAdr  - Slave address
*
* @return IIC_INIT_OK if Correct initialization
* @return IIC_INIT_BC_ERR if Unsupported number of bits
* @return IIC_INIT_ACK_ERR if Invalid acknowledge cycle
* @return IIC_INIT_SCK_ERR if Unsuppported clock setting
* @return IIC_INIT_SA_ERR if Invalid slave address [slave mode]
* @return IIC_INIT_ALS_ERR if Incorrect address recognition mode [slave mode]
*/
iic_InitErrors_e eIIC_Init(iic_NoOfBits_e eNoOfBits, iic_AckCycle_e eAckCycle,
                           iic_OutClkFreq_e eOutClkFreq, uint8_t u8SlaveAdr);


/**
*
* @brief Implementation of function vIIC_Reset
*
* Software reset of the IIC controller
*
* @note none
*
* @return void
*/
void vIIC_Reset(void);


/**
*
* @brief Implementation of function eIIC_SetNoOfBits
*
* Configure the number of bits to be transferred over the IIC bus
*
* @note none
*
* @param[in] eNoOfBits - Number of bits in a word
*
* @return IIC_INIT_OK if Correct initialization
* @return IIC_INIT_BC_ERR if Unsupported number of bits
* @return IIC_INIT_ACK_ERR if Invalid acknowledge cycle
* @return IIC_INIT_SCK_ERR if Unsuppported clock setting
* @return IIC_INIT_SA_ERR if Invalid slave address [slave mode]
* @return IIC_INIT_ALS_ERR if Incorrect address recognition mode [slave mode]
*/
iic_InitErrors_e eIIC_SetNoOfBits(iic_NoOfBits_e eNoOfBits);


/**
*
* @brief Implementation of function eIIC_GetNoOfBits
*
* Retrieve the currently set number of bits configuration
*
* @note This function relies on the shadow register content (SBI0CR1)
*
* @return IIC_DATA_BITS_8 if 8 bits
* @return IIC_DATA_BITS_1 if 1 bit
* @return IIC_DATA_BITS_2 if 2 bits
* @return IIC_DATA_BITS_3 if 3 bits
* @return IIC_DATA_BITS_4 if 4 bits
* @return IIC_DATA_BITS_5 if 5 bits
* @return IIC_DATA_BITS_6 if 6 bits
* @return IIC_DATA_BITS_7 if 7 bits
*/
iic_NoOfBits_e eIIC_GetNoOfBits(void);


/**
*
* @brief Implementation of function eIIC_SetOutClkFreq
*                
* The function configures an IIC controller output clock frequency
* (IICCLK) by specifying the appropriate predefined value used as an
* input for the formula, which calculates the output frequency.
*
* @note none
*                
* @param[in] eOutClkFreq - Output clock frequency
*
* @return IIC_INIT_OK if Correct initialization
* @return IIC_INIT_BC_ERR if Unsupported number of bits
* @return IIC_INIT_ACK_ERR if Invalid acknowledge cycle
* @return IIC_INIT_SCK_ERR if Unsuppported clock setting
* @return IIC_INIT_SA_ERR if Invalid slave address [slave mode]
* @return IIC_INIT_ALS_ERR if Incorrect address recognition mode [slave mode]
*/
iic_InitErrors_e eIIC_SetOutClkFreq(iic_OutClkFreq_e eOutClkFreq);


/**
*
* @brief Implementation of function eIIC_SetAckCycMode
*                
* Configures the controller to send or avoid sending of an 
* additional cycle for the acknowledge pulse on the IIC bus
*
* @note none
*                
* @param[in] eAckCycle - Acknowledge cycle enable/disable request
*
* @return IIC_INIT_OK if Correct initialization
* @return IIC_INIT_BC_ERR if Unsupported number of bits
* @return IIC_INIT_ACK_ERR if Invalid acknowledge cycle
* @return IIC_INIT_SCK_ERR if Unsuppported clock setting
* @return IIC_INIT_SA_ERR if Invalid slave address [slave mode]
* @return IIC_INIT_ALS_ERR if Incorrect address recognition mode [slave mode]
*/
iic_InitErrors_e eIIC_SetAckCycMode(iic_AckCycle_e eAckCycle);


/**
*
* @brief Implementation of function eIIC_GetAckCycMode
*                
* Retrieve the currently set acknowledge cycle mode of the 
* IIC bus
*
* @note This function relies on the shadow register content (SBI0CR1)
*
* @return IIC_ACK_DISABLE if no acknowledge cycle is generated
* @return IIC_ACK_ENABLE if acknowledge cycle is generated
*/
iic_AckCycle_e eIIC_GetAckCycMode(void);


/**
*
* @brief Implementation of function eIIC_SetSlaveAdr
*                
* Set the slave address for the IIC controller operating in 
* slave mode
*
* @note The address recognition mode has to be set by the explicit
*       call of the IIC_SetAdrRecMode driver function
*                
* @param[in] u8SlaveAdr - Slave address
*
* @return IIC_INIT_OK if Correct initialization
* @return IIC_INIT_BC_ERR if Unsupported number of bits
* @return IIC_INIT_ACK_ERR if Invalid acknowledge cycle
* @return IIC_INIT_SCK_ERR if Unsuppported clock setting
* @return IIC_INIT_SA_ERR if Invalid slave address [slave mode]
* @return IIC_INIT_ALS_ERR if Incorrect address recognition mode [slave mode]
*/
iic_InitErrors_e eIIC_SetSlaveAdr(uint8_t u8SlaveAdr);


/**
*
* @brief Implementation of function eIIC_SetAdrRecMode
*                
* Set the recognition mode of the slave address. 
*
* @note The slave address must be set separately 
*
* @param[in] eAdrRecMode - Slave address recognition
*
* @return IIC_INIT_OK if Correct initialization
* @return IIC_INIT_BC_ERR if Unsupported number of bits
* @return IIC_INIT_ACK_ERR if Invalid acknowledge cycle
* @return IIC_INIT_SCK_ERR if Unsuppported clock setting
* @return IIC_INIT_SA_ERR if Invalid slave address [slave mode]
* @return IIC_INIT_ALS_ERR if Incorrect address recognition mode [slave mode]
*/
iic_InitErrors_e eIIC_SetAdrRecMode(iic_AdrRecMode_e eAdrRecMode);


/**
*
* @brief Implementation of function vIIC_SendStart
*                
* Introduce start condition on the IIC bus
*
* @note IIC controller must operate in Master mode
*
* @return void
*/
void vIIC_SendStart(void);


/**
*
* @brief Implementation of function vIIC_SendStop
*                
* Causestop condition on the IIC bus
*
* @note IIC controller must operate in Master mode
*
* @return void
*/
void vIIC_SendStop(void);


/**
*
* @brief Implementation of function eIIC_PrepareRestart
*                
* Verify that the preconditions for direction change are met
*
* @note none
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if clock line LOW state time-out
* @return IIC_NOT_READY if bus not ready
*/
iic_ErrorCodes_e eIIC_PrepareRestart(void);


/**
*
* @brief Implementation of function eIIC_WaitBusyTimeout
*                
* Wait until either the bus is ready or predefine time-out
* elapsed
*
* @note none
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if clock line LOW state time-out
* @return IIC_NOT_READY if bus not ready
*/
iic_ErrorCodes_e eIIC_WaitBusyTimeout(void);


/**
*
* @brief Implementation of function eIIC_WaitAckTimeout
*                
* Wait for ACK until the predefine time-out elapses
*
* @note none
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if clock line LOW state time-out
* @return IIC_NOT_READY if bus not ready
*/
iic_ErrorCodes_e eIIC_WaitAckTimeout(void);


/**
*
* @brief Implementation of function eIIC_WaitIrqTimeout
*                
* Wait until interrupt condition is asserted in the IIC 
* controller
*
* @note none
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if clock line LOW state time-out
* @return IIC_NOT_READY if bus not ready
*/
iic_ErrorCodes_e eIIC_WaitIrqTimeout(void);


/**
*
* @brief Implementation of function eIIC_WaitHighClkTimeout
*                
* Ensure the IIC clock line is "high" i.e. no other devices
* are pulling it "low" 
*
* @note Used in the restart condition generation
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if clock line LOW state time-out
* @return IIC_NOT_READY if bus not ready
*/
iic_ErrorCodes_e eIIC_WaitHighClkTimeout(void);


/**
*
* @brief Implementation of function eIIC_SendSlaveAdr
*                 
* Send slave addres and direction bit over the IIC bus
*
* @note none
*                 
* @param[in] u8SlaveAddress - The value of the slave address
* @param[in] eSendDirBit    - The direction of the data following the address
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if clock line LOW state time-out
* @return IIC_NOT_READY if bus not ready
*/
iic_ErrorCodes_e eIIC_SendSlaveAdr(uint8_t u8SlaveAddress, 
                                   iic_SendDirBit_e eSendDirBit);


/**
*
* @brief Implementation of function eIIC_SendSubAdr
*                
* Sends subaddress to the slave device
*
* @note The subaddress might be up to 4 bytes long
*
* @param[in] u8SubAdrLen - Subaddress length
* @param[in] u32SubAdr   - Subaddress value
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if clock line LOW state time-out
* @return IIC_NOT_READY if bus not ready
*/
iic_ErrorCodes_e eIIC_SendSubAdr(uint8_t u8SubAdrLen, uint32_t u32SubAdr);


/**
*
* @brief Implementation of function eIIC_GetTransfDir
*                
* Retrieve the current transfer direction of the controller
*
* @note The direction may change automatically, i.e. detection of
*       an arbitration lost
*
* @return IIC_RX_DIR if Transmit
* @return IIC_TX_DIR if Receive
*/
iic_TransfDir_e eIIC_GetTransfDir(void);


/**
*
* @brief Implementation of function eIIC_GetCtrlMode
*                
* Retrieve the current control mode of the IIC controller
*
* @note It may change automatically, i.e. detection of an 
*       arbitration lost
*
* @return IIC_SLAVE_MODE if slave mode
* @return IIC_MASTER_MODE if master mode
*/
iic_CtrlMode_e eIIC_GetCtrlMode(void);


/**
*
* @brief Implementation of function eIIC_GetBusyStatus
*                
* Retrieves the present IIC bus status
*
* @note none
*
* @return IIC_BUS_FREE if bus is free
* @return IIC_BUS_BUSY if bus is busy
*/
iic_BusyStat_e eIIC_GetBusyStatus(void);


/**
*
* @brief Implementation of function eIIC_GetIrqStatus
*                
* Retrieves the current IIC controller interrupt status
*
* @note none
*
* @return IIC_IRQ_PENDING if interrupt is generated
* @return IIC_IRQ_CANCEL if interrupt is canceled
*/
iic_IrqStat_e eIIC_GetIrqStatus(void);


/**
*
* @brief Implementation of function eIIC_IsArbitrLost
*                
* Check wether arbitration lost was detected
*
* @note none
*
* @return IIC_ARBITR_NO_LOST if no arbitration is lost
* @return IIC_ARBITR_IS_LOST if arbitration lost is detected
*/
iic_ArbitrStat_e eIIC_IsArbitrLost(void);


/**
*
* @brief Implementation of function eIIC_IsAdrMatch
*                
* Retrieve slave address match status 
*
* @note Valid for slave mode only
*
* @return IIC_ADR_NO_MATCH if no "match"
* @return IIC_ADR_IS_MATCH if address "match" or general call detected
*/
iic_AdrMatchStat_e eIIC_IsAdrMatch(void);


/**
*
* @brief Implementation of function eIIC_IsGenCall
*                
* Detect general call over the IIC bus
*
* @note none
*
* @return IIC_GEN_CALL_NO_DET if general call is not deteced
* @return IIC_GEN_CALL_IS_DET if general call is detected
*/
iic_GenCallStat_e eIIC_IsGenCall(void);


/**
*
* @brief Implementation of function eIIC_GetLastRxBit
*                
* Retrieve the level of the last bit that was received
*
* @note none
*
* @return IIC_LST_BIT_ACK if last recieved bit is "0"
* @return IIC_LST_BIT_NOACK if last recieved bit is "1"
*/
iic_LastRxBitStat_e eIIC_GetLastRxBit(void);


/**
*
* @brief Implementation of function vIIC_WriteByte
*                
* Send single word over the IIC bus
*
* @note Ensure the previous data transfer was acknowledged
*                
* @param[in] u8Data - Data word to be send over IIC bus
*
* @return void
*/
void vIIC_WriteByte(uint8_t u8Data);


/**
*
* @brief Implementation of function u8IIC_ReadByte
*                
* Retrieve single word recieved over the IIC bus
*
* @note The first data read after restart procedure should be
*       ignored. The previous data transfer must be acknowledged
*       as a precondition for this function call
*
* @return Data-byte retrieved from the RX buffer
*/
uint8_t u8IIC_ReadByte(void);


/**
*
* @brief Implementation of function eIIC_WriteData
*                
* Write data to a slave device
*
* @note This function assumes that all transmitted sub-address and
*       data will be 8-bit long (unused bits should be ignored by
*       the Slave device). The function is showing an example of
*       data write procedure using basic driver functions. It should
*       be noted that for the target application parts of that
*       function should be implemented as an IIC interrupt handler
*
* @param[in] u8SlaveAddress - The address of the slave device. The LSB of
*                             the address will be replaced by direction bits.
* @param[in] u8SubAdrLen    - Number of subaddress bytes
* @param[in] u32SubAdr      - Subaddress
* @param[in] u8DataLen      - Number of valid data bytes to be sent
* @param[in] pau8Data[]     - Data buffer
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if Bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if Acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if Clock line LOW state time-out
* @return IIC_NOT_READY if Bus not ready
*/
iic_ErrorCodes_e eIIC_WriteData(uint8_t u8SlaveAddress, uint8_t u8SubAdrLen, 
                                uint32_t u32SubAdr, uint8_t u8DataLen, 
                                const uint8_t pau8Data[]);


/**
*
* @brief Implementation of function eIIC_ReadData
*
* Read data from a slave device
*
* @note This function assumes that all transmitted sub-address and
*       received data will be 8-bit long (unused bits should be
*       ignored). The function is showing an example of data write
*       procedure using basic driver functions. It should
*       be noted that for the target application parts of that
*       function should be implemented as an IIC interrupt handler
*
* @param[in] u8SlaveAddress - The address of the slave device. The LSB of
*                             the address will be replaced by direction bits.
* @param[in] u8SubAdrLen    - Number of subaddress bytes
* @param[in] u32SubAdr      - Subaddress
* @param[in] u8DataLen      - Number of valid data bytes to be recieved
*
* @param[in,out] pau8Data[]  Data read
*
* @return IIC_READY if TX/RX complete
* @return IIC_BUSY_TIMEOUT if Bus busy time-out
* @return IIC_IRQ_ACK_TIMEOUT if Acknowledge time-out
* @return IIC_CLK_LINE_TIMEOUT if Clock line LOW state time-out
* @return IIC_NOT_READY if Bus not ready
*/
iic_ErrorCodes_e eIIC_ReadData(uint8_t u8SlaveAddress, uint8_t u8SubAdrLen, 
                               uint32_t u32SubAdr, uint8_t u8DataLen, 
                               uint8_t  pau8Data[]);


/****************************************************************************/


#endif /* IIC_H*/

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

