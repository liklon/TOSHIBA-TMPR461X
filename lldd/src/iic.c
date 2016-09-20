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
*   DATE        : $Date: 2015/05/08 08:58:24 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "iic_io.h"                       /* SBI (I2C) registers, bits and access macros defintion */
#include "iic.h"                          /* SBI (I2C) LLDD definitions */
#include "iic_timer.h"                    /* SBI (I2C) timer functionality extension */

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_IIC_C_REVISION     "$Revision: 1.10 $"
#define LLDD_IIC_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_IIC_C_REVISION[]    = LLDD_IIC_C_REVISION;
static uint8_t au8LLDD_IIC_C_TAG[]         = LLDD_IIC_C_TAG;
static uint8_t au8LLDD_IIC_H_REVISION[]    = LLDD_IIC_H_REVISION;
static uint8_t au8LLDD_IIC_H_TAG[]         = LLDD_IIC_H_TAG;
static uint8_t au8LLDD_IIC_IO_H_REVISION[] = LLDD_IIC_IO_H_REVISION;
static uint8_t au8LLDD_IIC_IO_H_TAG[]      = LLDD_IIC_IO_H_TAG;

/*********************************************/

/**********************************************
*        Exported function definition         *
**********************************************/

/****************************************************************************/
void vIIC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_IIC_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_IIC_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_IIC_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_IIC_H_TAG[0];
   *pau8IORevision     = &au8LLDD_IIC_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_IIC_IO_H_TAG[0];
}

/****************************************************************************/
iic_InitErrors_e eIIC_Init(iic_NoOfBits_e eNoOfBits, iic_AckCycle_e eAckCycle,
                           iic_OutClkFreq_e eOutClkFreq, uint8_t u8SlaveAdr)
{
    iic_InitErrors_e eInitErrorCode = IIC_INIT_OK;
    
    /* Reset the SBI module */
    vIIC_Reset();

    /* Perform initialization according to input parameters */
    eInitErrorCode = eIIC_SetNoOfBits(eNoOfBits);
    if (eInitErrorCode == IIC_INIT_OK)
    {
        eInitErrorCode = eIIC_SetAckCycMode(eAckCycle);
        if (eInitErrorCode == IIC_INIT_OK)
        {
            eInitErrorCode = eIIC_SetOutClkFreq(eOutClkFreq);
            if(IIC_INIT_OK == eInitErrorCode)
            {
                eInitErrorCode = eIIC_SetSlaveAdr(u8SlaveAdr);
            }
        }
    }
    return eInitErrorCode;
}


/****************************************************************************/
void vIIC_Reset(void)
{
    /* Trigger reset */
    vSetSBI0CR2(IIC_1ST_RESET_VAL);
    vSetSBI0CR2(IIC_2ND_RESET_VAL);
    
    /* Set the appropriate mode */
    vSetSBI0CR2(IIC_BUS_RELEASE_CONDITION);
    
    /* Update the shadow variables with the default values */
    vSetSBI0AR_DEFAULT();
    vSetSBI0CR1_DEFAULT();
}


/****************************************************************************/
iic_NoOfBits_e eIIC_GetNoOfBits(void)
{
    iic_NoOfBits_e eReturn = IIC_DATA_BITS_8;
    
    /* Get bits count */
    eReturn = (iic_NoOfBits_e)biGetSBI0CR1_BC();
    return eReturn;
}


/****************************************************************************/
iic_InitErrors_e eIIC_SetNoOfBits(iic_NoOfBits_e eNoOfBits)
{
    iic_InitErrors_e eInitErrorCode = IIC_INIT_OK;
    uint8_t u8DataBits_7;
    uint8_t u8DataBits_8;

    u8DataBits_7 = IIC_DATA_BITS_7;
    u8DataBits_8 = IIC_DATA_BITS_8;

    /* The check may look strange, but it is based on the enumeration values */
    if( (eNoOfBits < u8DataBits_8) || (eNoOfBits > u8DataBits_7) )
    {
        /* Invalid request */
        eInitErrorCode = IIC_INIT_BC_ERR;
    }
    else
    {
        vSetSBI0CR1_BC((uint8_t)eNoOfBits);
    }
    
    return eInitErrorCode;
}


/****************************************************************************/
iic_InitErrors_e eIIC_SetOutClkFreq(iic_OutClkFreq_e eOutClkFreq)
{
    iic_InitErrors_e eInitErrorCode = IIC_INIT_OK;
    uint8_t u8Clock_low;
    uint8_t u8Clock_high;

    u8Clock_low = IIC_OUTCLK_7_KHZ;
    u8Clock_high = IIC_OUTCLK_340_KHZ;

    if( (eOutClkFreq < u8Clock_high) || (eOutClkFreq > u8Clock_low) )
    {
        /* Invalid clock request */
        eInitErrorCode = IIC_INIT_SCK_ERR; 
    }
    else
    {
        vSetSBI0CR1_SCK((uint8_t)eOutClkFreq);        
    }
    return eInitErrorCode;
}


/****************************************************************************/
iic_InitErrors_e eIIC_SetAckCycMode(iic_AckCycle_e eAckCycle)
{
    iic_InitErrors_e eInitErrorCode = IIC_INIT_OK;
    
    if( (IIC_ACK_DISABLE == eAckCycle) || (IIC_ACK_ENABLE == eAckCycle) )
    {
        vSetSBI0CR1_ACK((uint8_t)eAckCycle);
    }
    else
    {
        /* Wrong acknowledge bit selection */
        eInitErrorCode = IIC_INIT_ACK_ERR; 
    }
    return eInitErrorCode;
}


/****************************************************************************/
iic_AckCycle_e eIIC_GetAckCycMode(void)
{
    iic_AckCycle_e eReturn = IIC_ACK_DISABLE;
    
    eReturn = (iic_AckCycle_e)biGetSBI0CR1_ACK ();
    return eReturn;
}


/****************************************************************************/
iic_InitErrors_e eIIC_SetSlaveAdr(uint8_t u8SlaveAdr)
{
    iic_InitErrors_e eInitErrorCode = IIC_INIT_OK;
    
    if ((u8SlaveAdr > 0x00) && (u8SlaveAdr <= 0x7F))
    {      
        vSetSBI0AR_SA(u8SlaveAdr);
    }
    else
    {
        /* Wrong slave address */
        eInitErrorCode = IIC_INIT_SA_ERR; 
    }
    return eInitErrorCode;
}


/****************************************************************************/
iic_InitErrors_e eIIC_SetAdrRecMode(iic_AdrRecMode_e eAdrRecMode)
{
    iic_InitErrors_e eInitErrorCode = IIC_INIT_OK;
    
    if( (IIC_ADR_REC_ENABLE == eAdrRecMode) || (IIC_ADR_REC_DISABLE == eAdrRecMode) )
    {      
        vSetSBI0AR_ALS((uint8_t)(eAdrRecMode));
    }
    else
    {
        /* Wrong address recognition bit selection */
        eInitErrorCode = IIC_INIT_ALS_ERR; 
    }
    
    return eInitErrorCode;
}


/****************************************************************************/
void vIIC_SendStart(void)
{
    vSetSBI0CR2(IIC_BUS_START_CONDITION);
}


/****************************************************************************/
void vIIC_SendStop(void)
{
    vSetSBI0CR2(IIC_BUS_STOP_CONDITION);
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_PrepareRestart(void)
{
    iic_ErrorCodes_e eErrorCode = IIC_NOT_READY;
    
    /* Release the bus witout sending STOP condition - bus is still in BUSY state */
    vSetSBI0CR2(IIC_BUS_RELEASE_CONDITION);
    /* Check if bus is free */
    eErrorCode = eIIC_WaitBusyTimeout();
    if( IIC_READY == eErrorCode )
    {
        /* Check if the clock line is not pulled LOW by some device */
        eErrorCode = eIIC_WaitHighClkTimeout();
        if( IIC_READY == eErrorCode )
        {
            /* Wait additonal 4.7 us */
            iic_Timer_Delay_us(IIC_TIMER_RESTART_GUARD);
        }
    }
    return eErrorCode;
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_WaitBusyTimeout(void)
{
    iic_ErrorCodes_e eErrorCode = IIC_NOT_READY;
    iic_BusyStat_e eBusyStat = IIC_BUS_BUSY;
    iic_TimerStatus_e eTimerStatus = IIC_TIMER_STOPPED;
    
    vIIC_TimerStart(IIC_TIMER_BUSY_SEL);
    do
    {
        eBusyStat = eIIC_GetBusyStatus();        
        eTimerStatus = eIIC_TimerQuery(IIC_TIMER_BUSY_SEL);
    
    }
    while( (IIC_BUS_BUSY == eBusyStat) && (IIC_TIMER_RUNNING == eTimerStatus) );
    
    if( (IIC_TIMER_EXPIRED == eTimerStatus) || (IIC_BUS_BUSY == eBusyStat) )
    {
        eErrorCode = IIC_BUSY_TIMEOUT;
    }
    else
    {
        vIIC_TimerStop(IIC_TIMER_BUSY_SEL);
        eErrorCode = IIC_READY;
    }
    return eErrorCode;
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_WaitAckTimeout(void)
{
    iic_ErrorCodes_e eErrorCode = IIC_NOT_READY;
    iic_LastRxBitStat_e eLastRxBitStat = IIC_LST_BIT_NOACK;
    iic_IrqStat_e eIrqStat = IIC_IRQ_CANCEL;
    iic_TimerStatus_e eTimerStatus = IIC_TIMER_STOPPED;
    
    vIIC_TimerStart(IIC_TIMER_IRQ_ACK_SEL);
    do
    {
        eIrqStat = eIIC_GetIrqStatus();    
        eTimerStatus = eIIC_TimerQuery(IIC_TIMER_IRQ_ACK_SEL);
    }
    while( (IIC_IRQ_CANCEL == eIrqStat) && (IIC_TIMER_RUNNING == eTimerStatus) );
    
    /* Reconfirm if ACK bit from Slave device was "0" */
    eLastRxBitStat = eIIC_GetLastRxBit ();
    
    if( (IIC_TIMER_EXPIRED == eTimerStatus) || (IIC_LST_BIT_NOACK == eLastRxBitStat) )
    {
        eErrorCode = IIC_IRQ_ACK_TIMEOUT;
    }
    else 
    {
        /* IRQ and ACK OK */
        vIIC_TimerStop(IIC_TIMER_IRQ_ACK_SEL);
        eErrorCode = IIC_READY;
    }
    return eErrorCode;
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_WaitIrqTimeout(void)
{
    iic_ErrorCodes_e eErrorCode = IIC_NOT_READY;
    iic_IrqStat_e eIrqStat = IIC_IRQ_CANCEL;
    iic_TimerStatus_e eTimerStatus = IIC_TIMER_STOPPED;
    
    vIIC_TimerStart(IIC_TIMER_IRQ_ACK_SEL);
    do
    {
        eIrqStat = eIIC_GetIrqStatus();    
        eTimerStatus = eIIC_TimerQuery(IIC_TIMER_IRQ_ACK_SEL);
    }
    while( (IIC_IRQ_CANCEL == eIrqStat) && (IIC_TIMER_RUNNING == eTimerStatus) );
    
    if( (IIC_TIMER_EXPIRED == eTimerStatus) || (IIC_IRQ_CANCEL == eIrqStat) )
    {
        eErrorCode = IIC_IRQ_ACK_TIMEOUT;
    }
    else 
    {
        /* IRQ OK */
        vIIC_TimerStop(IIC_TIMER_IRQ_ACK_SEL);
        eErrorCode = IIC_READY;
    }
    return eErrorCode;
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_WaitHighClkTimeout(void)
{
    iic_ErrorCodes_e eErrorCode = IIC_NOT_READY;
    iic_LastRxBitStat_e eLastRxBitStat = IIC_LST_BIT_NOACK;
    iic_TimerStatus_e eTimerStatus = IIC_TIMER_STOPPED;
    
    vIIC_TimerStart(IIC_TIMER_IRQ_ACK_SEL);
    do
    {
        eLastRxBitStat = eIIC_GetLastRxBit();    
        eTimerStatus = eIIC_TimerQuery(IIC_TIMER_IRQ_ACK_SEL);
    }
    while( (IIC_LST_BIT_ACK == eLastRxBitStat) && (IIC_TIMER_RUNNING == eTimerStatus) );
    
    /* Reconfirm the reason for loop break */
    if( (IIC_TIMER_EXPIRED == eTimerStatus) || (IIC_LST_BIT_ACK == eLastRxBitStat) )
    {
        eErrorCode = IIC_CLK_LINE_TIMEOUT;
    }
    else 
    {
        /* ACK */
        vIIC_TimerStop(IIC_TIMER_IRQ_ACK_SEL);
        eErrorCode = IIC_READY;
    }
    return eErrorCode;
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_SendSlaveAdr(uint8_t u8SlaveAddress, iic_SendDirBit_e eSendDirBit)
{
    iic_ErrorCodes_e eErrorCode = IIC_NOT_READY;
    uint8_t u8ByteToSend = 0;
    
    /* If bus is free send the device alave address and direction bit */
    eErrorCode = eIIC_WaitBusyTimeout();
    
    if( IIC_READY == eErrorCode )
    {
        /* Send slave address and the direction bit WRITE */
        u8ByteToSend = (uint8_t)((u8SlaveAddress << 1) | eSendDirBit);
        vIIC_WriteByte(u8ByteToSend);        
        /* Send Start condition to begin transfer */
        vIIC_SendStart();        
        /* Wait until complete word is send or Ack-Timeout expires */
        eErrorCode = eIIC_WaitAckTimeout();
    }
    return eErrorCode;
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_SendSubAdr(uint8_t u8SubAdrLen, uint32_t u32SubAdr)
{
    iic_ErrorCodes_e eErrorCode = IIC_READY;
    uint8_t u8SubAdrIdx = 0;
    uint8_t u8SubAdrByte = 0;
    
    /* Sub-address write loop with acknowledge check */
    u8SubAdrIdx = 0;
    while( (IIC_READY == eErrorCode) && (u8SubAdrIdx < (u8SubAdrLen * 8)) )
    {
        u8SubAdrByte = (uint8_t)((u32SubAdr >> u8SubAdrIdx));
        
        vIIC_WriteByte(u8SubAdrByte);
        eErrorCode = eIIC_WaitAckTimeout();
        
        u8SubAdrIdx = (u8SubAdrIdx + 8);
    }
    return eErrorCode;
}


/****************************************************************************/
iic_TransfDir_e eIIC_GetTransfDir(void)
{
    iic_TransfDir_e eTransfDir = (iic_TransfDir_e)biGetSBI0SR_TRX();    
    return eTransfDir;
}


/****************************************************************************/
iic_CtrlMode_e eIIC_GetCtrlMode(void)
{
    iic_CtrlMode_e eCtrlMode = (iic_CtrlMode_e)biGetSBI0SR_MST();
    return eCtrlMode;
}


/****************************************************************************/
iic_BusyStat_e eIIC_GetBusyStatus(void)
{
    iic_BusyStat_e eBusyStat = (iic_BusyStat_e)biGetSBI0SR_BB();
    return eBusyStat;
}


/****************************************************************************/
iic_IrqStat_e eIIC_GetIrqStatus(void)
{
    iic_IrqStat_e eIrqStat = (iic_IrqStat_e)biGetSBI0SR_PIN();
    return eIrqStat;
}


/****************************************************************************/
iic_ArbitrStat_e eIIC_IsArbitrLost(void)
{
    iic_ArbitrStat_e eArbitrStat = (iic_ArbitrStat_e)biGetSBI0SR_AL();
    return eArbitrStat;
}


/****************************************************************************/
iic_AdrMatchStat_e eIIC_IsAdrMatch(void)
{
    iic_AdrMatchStat_e eAdrMatchStat = (iic_AdrMatchStat_e)biGetSBI0SR_AAS();
    return eAdrMatchStat;
}


/****************************************************************************/
iic_GenCallStat_e eIIC_IsGenCall(void)
{
    iic_GenCallStat_e eGenCallStat = (iic_GenCallStat_e)biGetSBI0SR_AD0();
    return eGenCallStat;
}


/****************************************************************************/
iic_LastRxBitStat_e eIIC_GetLastRxBit(void)
{
    iic_LastRxBitStat_e eLastRxBitStat = (iic_LastRxBitStat_e)biGetSBI0SR_LRB();
    return eLastRxBitStat;
}


/****************************************************************************/
void vIIC_WriteByte(uint8_t u8Data)
{
    vSetSBI0DBR(u8Data);
}


/****************************************************************************/
uint8_t u8IIC_ReadByte(void)
{
    uint8_t u8Data = u8GetSBI0DBR();
    return u8Data;
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_WriteData(uint8_t u8SlaveAddress, uint8_t u8SubAdrLen, 
                                uint32_t u32SubAdr, uint8_t u8DataLen, 
                                const uint8_t pau8Data[])
{
    /* error code */
    iic_ErrorCodes_e eErrorCode = IIC_NOT_READY;
    /* Send-data counter */
    uint8_t u8DataIdx = 0; 
    
    /* Start condition and slave address */
    eErrorCode = eIIC_SendSlaveAdr(u8SlaveAddress, IIC_WR_TO_SLAVE);
    if( IIC_READY == eErrorCode )
    {
        /* Sub-address */
        eErrorCode = eIIC_SendSubAdr(u8SubAdrLen, u32SubAdr);
        if( IIC_READY == eErrorCode )
        {                    
            /* Data write loop with acknowledge check */          
            while( (IIC_READY == eErrorCode) && (u8DataIdx < u8DataLen) )
            {
                vIIC_WriteByte(pau8Data[u8DataIdx]);
                eErrorCode = eIIC_WaitAckTimeout();
                u8DataIdx++;
            }
        }
    }
    /* STOP condition */
    vIIC_SendStop ();
    
    return eErrorCode;
}


/****************************************************************************/
iic_ErrorCodes_e eIIC_ReadData(uint8_t u8SlaveAddress, uint8_t u8SubAdrLen, 
                               uint32_t u32SubAdr, uint8_t u8DataLen, 
                               uint8_t pau8Data[])
{
    iic_ErrorCodes_e eErrorCode = IIC_NOT_READY;
    iic_NoOfBits_e eOldNoOfBits = IIC_DATA_BITS_8;
    iic_AckCycle_e eOldAckCycle = IIC_ACK_DISABLE;
    /* send-data counter */
    uint8_t u8DataIdx = 0; 
    
    /* Remember no of bits and acknowledge mode */     
    eOldAckCycle = eIIC_GetAckCycMode();    
    eOldNoOfBits = eIIC_GetNoOfBits();
    /* Start condition, slave address */
    eErrorCode = eIIC_SendSlaveAdr(u8SlaveAddress, IIC_WR_TO_SLAVE);
    if( IIC_READY == eErrorCode )
    {
        /* Sub-address */
        eErrorCode = eIIC_SendSubAdr(u8SubAdrLen, u32SubAdr);
        if( IIC_READY == eErrorCode )
        {
            /* 
             *  Change the direction without stopping the 
             *  current transfer: Restart condition
             */
            eErrorCode = eIIC_PrepareRestart();
            if( IIC_READY == eErrorCode )
            {
                /* Slave address with READ direction */
                eErrorCode = eIIC_SendSlaveAdr(u8SlaveAddress, IIC_RD_FROM_SLAVE);
                if( IIC_READY == eErrorCode )
                {            
                    /* Perform dummy read */
                    u8IIC_ReadByte();
                    /* Wait for Rx IRQ */
                    eErrorCode = eIIC_WaitIrqTimeout();
                    if( IIC_READY == eErrorCode )
                    {
                        uint8_t u8DataLenTmp = (u8DataLen - 1);
                        
                        /* READ all data, besides the last byte */
                        u8DataIdx = 0;
                        while( (IIC_READY == eErrorCode) && (u8DataIdx < u8DataLenTmp) )
                        {
                            pau8Data[u8DataIdx] = u8IIC_ReadByte();
                            eErrorCode = eIIC_WaitIrqTimeout();
                            u8DataIdx++;
                        }
                    }
                    /* Check the last error code to decide what to do  */
                    if( IIC_READY == eErrorCode )
                    {
                        /* Disable generation of ack clock cycle */                                                  
                        eIIC_SetAckCycMode(IIC_ACK_DISABLE);
                        /* Receive the last data and wait until completion */
                        pau8Data[u8DataIdx] = u8IIC_ReadByte();
                        /* Wait for Rx IRQ */
                        eErrorCode = eIIC_WaitIrqTimeout();
                        if( IIC_READY == eErrorCode )
                        {
                            /* 
                             *  All read, the master must finish the transfer, so
                             *  change the number of bits in controller to one, 
                             *  read out dummy data - this will generate 1 clock 
                             *  pulse
                             */
                            eIIC_SetNoOfBits(IIC_DATA_BITS_1);
                            u8IIC_ReadByte();
                            /* Wait for completion */
                            eErrorCode = eIIC_WaitIrqTimeout();
                        }
                    }
                }
            }
        }
    }

    /* STOP condition */
    vIIC_SendStop();

    /* Restore the previous no of bits and ack mode */
    eIIC_SetNoOfBits(eOldNoOfBits);
    eIIC_SetAckCycMode(eOldAckCycle);
    
    return eErrorCode;
}

/****************************************************************************/


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: iic.c
**  $Revision: 1.10 $
**  $Date: 2015/05/08 08:58:24 $
**
** **************************************************************************
**
**  ------------------------------------------------------------------------
** |
** | RULE   : Msg(3:3197) - The initialiser for 'variable' is always modified
** |          before being used.
** |
** | CONS.  : The initialisation performed when this object is defined appears
** |          to be redundant because the value of the object is not used
** |          before being modified by assignment.
** |
** | REASON : Variables get the initalization values at declaration, which are
** |          typically overwritten by the content of the function.
** |          This is not any error and seems to be better solution than
** |          leaving the variables non-initialized.
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 16.10 - Functions xxx return a value which is not being used.
** |
** |
** | CONS.  : If a function returns error information, then that error
** |          information shall be tested.
** |
** | REASON : Some functions have double functionality. e.g. "Shadow-functions"
** |          These functions might be used as "Set-type" or "Get-type".
** |          In the 1st. case the return value can be ignored.
** |          In the 2nd. case the return value is a usefull information.
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : Msg(6:0303) - Cast between a pointer to volatile object and an
** |          integral type.
** |
** | CONS.  : The size of integer required to hold the result of a pointer
** |          cast is implementation-defined. This message will identify such
** |          operations where the pointer addresses a volatile memory address.
** |
** | REASON : This type of operation is not uncommon in embedded software
** |          applications where memory mapped I/O ports must be addressed.
** |
**  ------------------------------------------------------------------------
*****************************************************************************
****************************************************************************/

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

