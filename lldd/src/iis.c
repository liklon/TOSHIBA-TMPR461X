/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference IIS Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : IIS Controller
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.7 $
*   DATE        : $Date: 2015/05/08 08:57:22 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "iis_io.h"                         /* IIS registers, bits and access macros defintion */
#include "iis.h"                            /* IIS LLDD definitions */

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_IIS_C_REVISION     "$Revision: 1.7 $"
#define LLDD_IIS_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_IIS_C_REVISION[]    = LLDD_IIS_C_REVISION;
static uint8_t au8LLDD_IIS_C_TAG[]         = LLDD_IIS_C_TAG;
static uint8_t au8LLDD_IIS_H_REVISION[]    = LLDD_IIS_H_REVISION;
static uint8_t au8LLDD_IIS_H_TAG[]         = LLDD_IIS_H_TAG;
static uint8_t au8LLDD_IIS_IO_H_REVISION[] = LLDD_IIS_IO_H_REVISION;
static uint8_t au8LLDD_IIS_IO_H_TAG[]      = LLDD_IIS_IO_H_TAG;

/*********************************************/

/**********************************************
*        Exported function definition         *
**********************************************/

/****************************************************************************/
void vIIS_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_IIS_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_IIS_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_IIS_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_IIS_H_TAG[0];
   *pau8IORevision     = &au8LLDD_IIS_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_IIS_IO_H_TAG[0];
}


/****************************************************************************/
iis_ErrCode_e eIIS_InitAsDAC(iis_Ch_e eCh)
{
    iis_ErrCode_e eErrCode = IIS_OK;
    
    /* CTRL register configuration */
    eErrCode |= eIIS_SetModeDir(eCh, IIS_MODE_MASTER, IIS_DIR_TX);

    /* FIFO-Errors handling configuration */
    eErrCode |= eIIS_SetErrResolve(eCh, IIS_ERR_OVR_DISCARD, IIS_ERR_UDR_SND_ZEROS);

    /* Signals polarities confgiguration */
    eErrCode |= eIIS_SetWrdSelTxPol(eCh, IIS_WRDSEL_START_LOW, IIS_TXPOL_FALL_EDGE);

    /* Data with configuration */
    eErrCode |= eIIS_SetWidthLength(eCh, IIS_DATAWID_16, IIS_WSLEN_16);

    /* Clear any pending interrupts */
    vIIS_ClearIrq(eCh, IIS_INT_RX_ERR | IIS_INT_TX_ERR);

    /* Interrupt mask register configuration (if interrupts used) */
    vIIS_EnableInt(eCh, IIS_INT_TX_AE_INT);

    /* Initialize clocks */
    eErrCode |= eIIS_SetClkAttr(eCh,IIS_MCLKOUT_DISABLE, IIS_LTIME_31, IIS_BCLKDIV_8);
    /* Activate MCLK for IIS */
    eErrCode |= eIIS_SetMClkOper(eCh, IIS_MCLKOPER_ENABLE);

    /* Starting first recording/playback: IIS enabled for RX/TX */
    eErrCode |= eIIS_SetTxRxOper (eCh, IIS_TRSF_OPER_ENABLE);

    return eErrCode;
}


/****************************************************************************/
iis_ErrCode_e eIIS_InitAsADC(iis_Ch_e eCh)
{
    iis_ErrCode_e eErrCode = IIS_OK;
    
    /* Configure as master RX */
    eErrCode |= eIIS_SetModeDir(eCh, IIS_MODE_MASTER, IIS_DIR_RX);

    /* FIFO-Errors handling configuration */
    eErrCode |= eIIS_SetErrResolve(eCh, IIS_ERR_OVR_DISCARD, IIS_ERR_UDR_SND_ZEROS);

    /* Signals polarities configuration */
    eErrCode |= eIIS_SetWrdSelTxPol(eCh, IIS_WRDSEL_START_LOW, IIS_TXPOL_FALL_EDGE);

    /* Data with configuration */
    eErrCode |= eIIS_SetWidthLength(eCh, IIS_DATAWID_16, IIS_WSLEN_16);

    /* Clear any pending interrupts */
    vIIS_ClearIrq(eCh, IIS_INT_RX_ERR | IIS_INT_TX_ERR);

    /* Interrupt mask register configuration (if interrupts used) */
    vIIS_EnableInt(eCh, IIS_INT_RX_AF_INT);

    /* Initialize clocks */
    eErrCode |= eIIS_SetClkAttr(eCh,IIS_MCLKOUT_ENABLE, IIS_LTIME_31, IIS_BCLKDIV_8);
    /* Activate MCLK for IIS */
    eErrCode |= eIIS_SetMClkOper(eCh, IIS_MCLKOPER_ENABLE);

    /* Starting first recording/playback: I2S0 enable for RX */
    eErrCode |= eIIS_SetTxRxOper(eCh, IIS_TRSF_OPER_ENABLE);

    return eErrCode;
}


/****************************************************************************/
iis_ErrCode_e eIIS_SetWrdSelTxPol(iis_Ch_e eCh, iis_WrdSelPol_e eWrdSelPol,
                                  iis_TxPol_e eTxPol)
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    
    /* Check if the parameters are in range and write them */
    if( ((IIS_WRDSEL_START_LOW == eWrdSelPol) || (IIS_WRDSEL_START_HIGH == eWrdSelPol))
        && ((IIS_TXPOL_FALL_EDGE == eTxPol) || (IIS_TXPOL_RISE_EDGE == eTxPol)) )
    {
        vSetI2SCTRL_POL(eCh, eTxPol);
        vSetI2SCTRL_WSPol(eCh, eWrdSelPol);
        eErrCode = IIS_OK;
    }
    return eErrCode;
}


/****************************************************************************/
iis_ErrCode_e eIIS_SetErrResolve(iis_Ch_e eCh, iis_ErrOvrRes_e eErrOvrRes,
                                 iis_ErrUdrRes_e eErrUdrRes)
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    
    /* Check if the parameters are in range and write them  */
    if( ((IIS_ERR_OVR_DISCARD == eErrOvrRes) || (IIS_ERR_OVR_STOP_WS == eErrOvrRes))
        && ((IIS_ERR_UDR_SND_ZEROS == eErrUdrRes) || (IIS_ERR_UDR_STOP_WS == eErrUdrRes))
      )
    {
        vSetI2SCTRL_FullRes(eCh, eErrOvrRes);
        vSetI2SCTRL_EmptyRes(eCh, eErrUdrRes);
        eErrCode = IIS_OK;
    }
    return eErrCode;
}


/****************************************************************************/
iis_ErrCode_e eIIS_SetModeDir (iis_Ch_e eCh, iis_Mode_e eMode, iis_Dir_e eDir)
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    
    /* Check if the parameters are in range and write them */
    if( ((IIS_MODE_SLAVE == eMode) || (IIS_MODE_MASTER == eMode))
        && ((IIS_DIR_RX == eDir) || (IIS_DIR_TX == eDir)) )
    {
        vSetI2SCTRL_MSSLV(eCh, eMode);
        vSetI2SCTRL_TXRXSEL(eCh, eDir);
        eErrCode = IIS_OK;
    }
    
    return eErrCode;
}


/****************************************************************************/
iis_ErrCode_e eIIS_SetTxRxOper(iis_Ch_e eCh, iis_TrsfOper_e eTrsfOper)
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    
    /* Check if the parameters are in range and write them */
    if( (IIS_TRSF_OPER_DISABLE == eTrsfOper) || (IIS_TRSF_OPER_ENABLE == eTrsfOper) )
    {
        vSetI2SCTRL_TXRXEN(eCh, eTrsfOper);
        eErrCode = IIS_OK;
    }
    return eErrCode;
}


/****************************************************************************/
iis_ErrCode_e eIIS_SetWidthLength(iis_Ch_e eCh, iis_DataWid_e eDataWidth, iis_WsLen_e eWsLen)
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    uint32_t u32LenWid = 0;
    uint32_t u32DataWidth_1;
    uint32_t u32DataWidth_32;

    u32DataWidth_1  = IIS_DATAWID_1;
    u32DataWidth_32 = IIS_DATAWID_32;
    /* 
     *  Check if the parameters are in range and write them
     *  Combine both params to create one Word to be written
     */
    if ((eDataWidth >= u32DataWidth_1) && (eDataWidth <= u32DataWidth_32))
    {
        u32LenWid = (uint32_t)(eDataWidth | eWsLen);
        
        vSetI2SLENGTH(eCh,u32LenWid);
        
        eErrCode = IIS_OK;
    }

    return eErrCode;
}


/****************************************************************************/
iis_ErrCode_e eIIS_SetMClkOper(iis_Ch_e eCh, iis_MClkOper_e eMClkOper)
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    uint32_t u32ClkConfReg = 0;
    uint32_t u32MClkOper = 0;
    uint32_t u32ClrMask = 0;
    
    /* Check if the parameters are in range and write them  */
    if( (IIS_MCLKOPER_DISABLE == eMClkOper) || (IIS_MCLKOPER_ENABLE == eMClkOper) )
    {
        u32MClkOper = (uint32_t)eMClkOper;
        u32ClrMask = ~((uint32_t)IIS_MCLKOPER_ENABLE);

        /* 
         *  get the old register value
         *  Clear the enable bit and apply ne bit value to 
         *  enable or disable MCLK
         */
        u32ClkConfReg = u32GetI2SCLKCONF(eCh);            
        u32ClkConfReg = u32ClkConfReg & u32ClrMask;
        u32ClkConfReg = u32ClkConfReg | u32MClkOper;            
        vSetI2SCLKCONF(eCh, u32ClkConfReg);            
        eErrCode = IIS_OK;
    }
    return eErrCode;
}


/****************************************************************************/
iis_MClkOper_e eIIS_GetMClkOper(iis_Ch_e eCh)
{
    iis_MClkOper_e eMClkOper = IIS_MCLKOPER_DISABLE;
    
    /* Read the current value of the MCLK enable bit */
    eMClkOper = (iis_MClkOper_e)(u32GetI2SCLKCONF(eCh) & IIS_MCLKOPER_ENABLE);

    /* Return the respective enumeration value according the MCLKEN bit value */
    return eMClkOper;
}


/****************************************************************************/
iis_ErrCode_e eIIS_SetClkAttr(iis_Ch_e eCh,iis_MClkOut_e eMClkOut,
                              iis_LatchTime_e eLatchTime, iis_BClkDiv_e eBClkDiv)
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    iis_MClkOper_e eMClkOperOld;            
    
    /*     
     *  MCLK should be disabled during set-up. Preserve the old value
     *  and restore it after applying new settings
     */
    if (((eLatchTime >= IIS_LTIME_2) && (eLatchTime <= IIS_LTIME_32))
        && ((IIS_MCLKOUT_DISABLE == eMClkOut) ||
            (IIS_MCLKOUT_ENABLE == eMClkOut))
        && ((IIS_BCLKDIV_8 == eBClkDiv) || (IIS_BCLKDIV_16 == eBClkDiv) ||
            (IIS_BCLKDIV_32 == eBClkDiv)))
    {
        /* 
         *  Prepare the value to be written
         *  Choose IIS channel
         *  Store the current setting of MCLKEN bit
         *  Change clock attributes
         *  Restore the original MCLKEN bit setting
         */
        uint32_t u32Attr = (uint32_t)(eMClkOut | eLatchTime | eBClkDiv);
        
        eMClkOperOld = eIIS_GetMClkOper(eCh);            
        vSetI2SCLKCONF(eCh, u32Attr);            
        eErrCode = eIIS_SetMClkOper (eCh, eMClkOperOld);
    }
    return eErrCode;
}


/****************************************************************************/
void vIIS_DisableInt(iis_Ch_e eCh, uint8_t u8Mask)
{
    uint8_t u8TmpMask = 0x00;
    
    /* 
     *  Get the current mask
     *  Set bits to mask out
     *  Set the new mask
     */
    u8TmpMask = u8GetI2SIRMASK(eCh);        
    u8TmpMask = u8TmpMask | u8Mask;        
    vSetI2SIRMASK(eCh, u8TmpMask);        
}


/****************************************************************************/
void vIIS_EnableInt(iis_Ch_e eCh, uint8_t u8Mask)
{
    uint32_t u8TmpMask = 0x00;
    
    /* 
     *  Get the current mask
     *  Clear bits to unmask and set the new mask
     */
    u8TmpMask = u8GetI2SIRMASK(eCh);        
    u8TmpMask = u8TmpMask & ~u8Mask;        
    vSetI2SIRMASK(eCh, u8TmpMask);        
}


/****************************************************************************/
void vIIS_ClearIrq(iis_Ch_e eCh, uint32_t u32Mask)
{
    /*  Write the IRQ clear mask bits */          
    vSetI2SIRCLR(eCh, u32Mask);        
}


/****************************************************************************/
uint8_t u8IIS_GetIrqStatus(iis_Ch_e eCh)
{
    uint8_t u8IrqStat = 0;
    
    /* Get the current IRQ status */       
    u8IrqStat = u8GetI2SIRSTAT(eCh);        

    return u8IrqStat;
}


/****************************************************************************/
uint32_t u32IIS_GetFifoStatus(iis_Ch_e eCh)
{
    uint32_t u32FifoStat = 0;
    
    /* Get the current FIFO status */    
    u32FifoStat = u32GetI2SFIFOSTAT(eCh);        

    return u32FifoStat;
}


/****************************************************************************/
uint16_t u16IIS_GetCtrlReg(iis_Ch_e eCh)
{
    uint16_t u16CtrlReg = 0;
    
    /* Get the control register value */
    u16CtrlReg = u16GetI2SCTRL(eCh);        

    return u16CtrlReg;
}


/****************************************************************************/
uint16_t u16IIS_GetLengthReg(iis_Ch_e eCh)
{
    uint16_t u16LengthReg = 0;
    
    /* Get the length */
    u16LengthReg = u16GetI2SLENGTH(eCh);     

    return u16LengthReg;
}


/****************************************************************************/
uint32_t u32IIS_GetClkCfgReg(iis_Ch_e eCh)
{
    uint32_t u32ClkCfgReg = 0;
    
    /* Get the current clock configuration */
    u32ClkCfgReg = u32GetI2SCLKCONF(eCh);    
    
    return u32ClkCfgReg;
}


/****************************************************************************/
uint8_t u8IIS_GetIntMaskReg(iis_Ch_e eCh)
{
    uint8_t u8IntMaskReg = 0;
    
    /* Get the current IRQ mask */
    u8IntMaskReg = u8GetI2SIRMASK(eCh);      

    return u8IntMaskReg;
}


/****************************************************************************/
void vIIS_WriteWord(iis_Ch_e eCh, uint32_t u32Data)
{
    /* Write the word to the TX FIFO */
    vSetI2STXDATA(eCh, u32Data);      
}


/****************************************************************************/
uint32_t u32IIS_ReadWord(iis_Ch_e eCh)
{
    uint32_t u32RdWord = 0;
    
    /* Get the word from the RX FIFO */
    u32RdWord = u32GetI2SRXDATA(eCh);

    return u32RdWord;
}


/****************************************************************************/
iis_ErrCode_e eIIS_WriteData(iis_Ch_e eCh, uint32_t u32DataLen, const uint32_t u32Data[])
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    uint32_t u32FifoStat = 0;
    uint32_t u32DataIdx = 0;
    uint32_t u32DataToSnd = u32DataLen;
    uint32_t u32CurFifoEmpty = 0;
    
    /* If FIFO has space write appropriate number of words */
    if( u32DataIdx < u32DataLen )
    {
        eErrCode = eIIS_SetTxRxOper(eCh, IIS_TRSF_OPER_ENABLE);
    }
    if( IIS_OK == eErrCode )
    {
        while( u32DataIdx < u32DataLen )
        {
            u32FifoStat = u32IIS_GetFifoStatus(eCh);
            u32FifoStat = (u32FifoStat & IIS_FIFO_TX_MASKS);
            
            if( IIS_FIFO_TX_AE == (u32FifoStat & IIS_FIFO_TX_AE) )
            {
                u32CurFifoEmpty = 24;
            }
            else
            {
                if( IIS_FIFO_TX_EMPTY == (u32FifoStat & IIS_FIFO_TX_EMPTY) )
                {
                    u32CurFifoEmpty = IIS_FIFO_TX_SIZE;
                }
                else
                {
                    u32CurFifoEmpty = 0;
                }
            }
            while( (u32DataToSnd > 0) && (u32CurFifoEmpty > 0) )
            {
                vIIS_WriteWord(eCh, u32Data[u32DataIdx]);
                u32DataIdx++;
                u32DataToSnd--;
                u32CurFifoEmpty--;
            }
        }
        /* Check if all data has been written */
        if( u32DataIdx == u32DataLen )
        {
          eErrCode = IIS_OK;
        }
    }
    return eErrCode;
}


/****************************************************************************/
iis_ErrCode_e eIIS_ReadData(iis_Ch_e eCh, uint32_t *pu32DataLen, uint32_t u32Data[])
{
    iis_ErrCode_e eErrCode = IIS_FAIL;
    uint32_t u32FifoStat = 0;
    uint32_t u32DataIdx = 0;
    uint32_t u32CurFifoFull = 0;    
    *pu32DataLen = 0;

    /* Enable */
    eErrCode = eIIS_SetTxRxOper(eCh, IIS_TRSF_OPER_ENABLE);
    
    if( IIS_OK == eErrCode )
    {
        u32FifoStat = u32IIS_GetFifoStatus(eCh);
        u32FifoStat = (u32FifoStat & IIS_FIFO_RX_MASKS);
        
        if( IIS_FIFO_RX_AF == (u32FifoStat & IIS_FIFO_RX_AF) )
        {
            u32CurFifoFull = 24;
        }
        else
        {
            if( IIS_FIFO_RX_FULL == (u32FifoStat & IIS_FIFO_RX_FULL) )
            {
                u32CurFifoFull = IIS_FIFO_RX_SIZE;
            }
            else
            {
                u32CurFifoFull = 0; /* ??? */
            }
        }
        while( (u32CurFifoFull > 0) && ((*pu32DataLen) < IIS_FIFO_RX_SIZE) )
        {
            u32Data[u32DataIdx] = u32IIS_ReadWord(eCh);
            u32DataIdx++;
            u32CurFifoFull--;
            (*pu32DataLen)++;
        }
        /* Check if all  has been read */
        if( ((*pu32DataLen) > 0) && ((*pu32DataLen) < IIS_FIFO_RX_SIZE) )
        {
            eErrCode = IIS_OK;
        }
    }
    return eErrCode;
}

/****************************************************************************/


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: iis.c
**  $Revision: 1.7 $
**  $Date: 2015/05/08 08:57:22 $
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

