/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference High-Speed UART Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Asynchronous Serial Interface (HSUART)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.18 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "core.h"                           /* Generic Cortex utilities */ 
#include "hsuart_io.h"                      /* HSUART registers, bits and access macros defintion */
#include "hsuart.h"                         /* HSUART LLDD definitions */

/*********************************************/


/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_UART_C_REVISION     "$Revision: 1.18 $"
#define LLDD_UART_C_TAG          "$Name: LLDD_1_6 $"

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : Functions must always have prototype declarations */

  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : disable casting error */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1849  /* Rule 10.5 [R] : Bitwise `~' and `<<' expressions on unsigned char or unsigned short .. */
  #pragma ghs nowarning 1752  /* Rule 17.4 [R] : allow access to data under pointer by array (used forc copy) */
 #endif
/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_UART_C_REVISION[]    = LLDD_UART_C_REVISION;
static uint8_t au8LLDD_UART_C_TAG[]         = LLDD_UART_C_TAG;
static uint8_t au8LLDD_UART_H_REVISION[]    = LLDD_UART_H_REVISION;
static uint8_t au8LLDD_UART_H_TAG[]         = LLDD_UART_H_TAG;
static uint8_t au8LLDD_UART_IO_H_REVISION[] = LLDD_UART_IO_H_REVISION;
static uint8_t au8LLDD_UART_IO_H_TAG[]      = LLDD_UART_IO_H_TAG;

/* Waits for 15-cycles */
static void vUART_Wait(void);

/*********************************************/

/**********************************************
*        Exported function definition         *
**********************************************/

void vUART_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_UART_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_UART_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_UART_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_UART_H_TAG[0];
   *pau8IORevision     = &au8LLDD_UART_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_UART_IO_H_TAG[0];
}

/****************************************************************************/

void vUART_Init(uart_Ch_e eCh, uart_BdRate_e eBaudRate, uart_DataFmt_st * stDataCfg,uart_DmaIrq_st * stDmaIrqCfg)
{
    /* Reset the UART */
    vUART_Reset(eCh);

    /* Put both FIFOs in reset */
    vUART_FifoResetTx(eCh, UART_RST_ACTIVE);
    vUART_FifoResetRx(eCh, UART_RST_ACTIVE);

    /* Set baud-rate */
    vUART_SetBaudRate(eCh, eBaudRate);

    /* Configure line/data parameters */
    vUART_DataFmtConfig(eCh, stDataCfg);

    /* Configure DMA/IRQ parameters */
    vUART_DmaIrqConfig(eCh, stDmaIrqCfg);

    /* Release FIFO reset */
    vUART_FifoResetTx(eCh, UART_RST_RELEASE);
    vUART_FifoResetRx(eCh, UART_RST_RELEASE);

    /* Switch off the open-drain */
    vSetSILCR_RSRVD12(eCh, (uint16_t)0U);    
}

/****************************************************************************/

void vUART_DataFmtConfig(uart_Ch_e eCh, uart_DataFmt_st * pstDataFmt)
{
    if (0x0U != pstDataFmt)
    {
        /* Configure the line control register fields */
        vSetSILCR_UMODE(eCh,(uint16_t) pstDataFmt->eUmode);
        vSetSILCR_USBL(eCh, (uint16_t) pstDataFmt->eUsbl);
        vSetSILCR_UPEN(eCh, (uint16_t) pstDataFmt->eUpen);
        vSetSILCR_UEPS(eCh, (uint16_t) pstDataFmt->eUeps);
        vSetSILCR_LSBF(eCh, (uint16_t) pstDataFmt->eLsbf);
        vSetSILCR_TWUB(eCh, (uint16_t) pstDataFmt->eTwub);
        vSetSILCR_RWUB(eCh, (uint16_t) pstDataFmt->eRwub);
    }
}

/****************************************************************************/

void vUART_DmaIrqConfig(uart_Ch_e eCh, uart_DmaIrq_st * pstDmaIrq)
{
    if (0x0U != pstDmaIrq)
    {
        /* Configure all DMA/Interrupt register fields */
        vSetSIDICR_TIR(eCh, (uint16_t) pstDmaIrq->eTir);
        vSetSIDICR_RIR(eCh, (uint16_t) pstDmaIrq->eRir);
        vSetSIDICR_SPIR(eCh, (uint16_t) pstDmaIrq->eSpir);
        vSetSIDICR_CTSAC(eCh, (uint16_t) pstDmaIrq->eCtsac);
        vSetSIDICR_RXTOUT_EN(eCh, (uint16_t) pstDmaIrq->eRxTout);
        vSetSIDICR_SIOE(eCh,  (uint16_t) pstDmaIrq->eSioe);
        vSetSIDICR_SICTS(eCh, (uint16_t) pstDmaIrq->eSicts);
        vSetSIDICR_SIBRK(eCh, (uint16_t) pstDmaIrq->eSibrk);
        vSetSIDICR_SITR(eCh,  (uint16_t) pstDmaIrq->eSitr);
        vSetSIDICR_SIAS(eCh,  (uint16_t) pstDmaIrq->eSias);
        vSetSIDICR_SIUB(eCh,  (uint16_t) pstDmaIrq->eSiub);
    }
}

/****************************************************************************/

void vUART_FifoConfig(uart_Ch_e eCh, uart_Fifo_st * pstFifo)
{
    if (0x0U != pstFifo)
    {
        /* Configure all fifo control register fields */
        vSetSIFCR_RDIL(eCh, pstFifo->u8Rdil);
        vSetSIFCR_TDIL(eCh, pstFifo->u8Tdil);
        vSetSIFCR_FRSTEW(eCh, (uint16_t)pstFifo->eFrStew);
    }
}

/****************************************************************************/

void vUART_FlowCtrlConfig(uart_Ch_e eCh, uart_Flow_st * pstFlow)
{
    if (0x0U != pstFlow)
    {
        /* Configure all flow control register fields */
        vSetSIFLCR_RSDR(eCh,(uint16_t)pstFlow->eRsdr);
        vSetSIFLCR_TSDR(eCh,(uint16_t)pstFlow->eTsdr);
        vSetSIFLCR_TBRK(eCh,(uint16_t)pstFlow->eTbrk);
        vSetSIFLCR_TRS(eCh, (uint16_t)pstFlow->eTrs);
        vSetSIFLCR_RCS(eCh, (uint16_t)pstFlow->eRcs);
    }
}

/****************************************************************************/

void vUART_SetRTSTerminalLevel(uart_Ch_e eCh, uart_Rtssc_e eLevel)
{
    vSetSIFLCR_RTSSC(eCh, (uint16_t)eLevel);
}

/****************************************************************************/

uart_Ctss_e eUART_GetCTSTerminalStatus(uart_Ch_e eCh)
{
    return (uart_Ctss_e)biGetSISCISR_CTSS(eCh);
}

/****************************************************************************/

void vUART_SetRTSTriggerLevel(uart_Ch_e eCh, uart_Rtstl_e eLevel)
{
    vSetSIFLCR_RTSTL(eCh, (uint16_t)eLevel);
}

/****************************************************************************/

void vUART_GetTransferStat(uart_Ch_e eCh, uint8_t *pu8Status)
{
    if (0x0U != pu8Status)
    {
        *pu8Status = u8GetSISCISR(eCh);
    }
}

/****************************************************************************/

void vUART_SetBaudRate(uart_Ch_e eCh, uart_BdRate_e eBaudRate)
{
    vSetSIBGR(eCh, (uint16_t) eBaudRate);
}

/****************************************************************************/

int32_t i32UART_GetBaudRate(uart_Ch_e eCh, uint32_t *pu32BaudRate)
{
    uint8_t u8Bclk;
    uint8_t u8Preskal = 1U;
    uint16_t u16Div;
    int32_t i32Res = C_SUCCESS;

    if (0x0U != pu32BaudRate)
    {
        u8Bclk = (uint8_t) biGetSIBGR_BCLK(eCh);
        u16Div = (uint16_t) biGetSIBGR_BRD(eCh);

        switch( u8Bclk )
        {
            case UART_NO_DIV: 
                u8Preskal = 1U;
                break;

            case UART_DIV_2: 
                u8Preskal = 2U;
                break;

            case UART_DIV_8: 
                u8Preskal = 8U;
                break;

            case UART_DIV_32: 
                u8Preskal = 32U;
                break;

            case UART_DIV_128: 
                u8Preskal = 128U;
                break;

            default:        
                /* Incorrect prescaler value */
                i32Res =  C_FAILED;
            break;
        }
        if( C_SUCCESS == i32Res )
        {
            /* 75MHz */
            *pu32BaudRate = ( (75000000U/ u8Preskal) / (u16Div + 1U) )/ 16U;
        }
    }
    else
    {
        i32Res = C_FAILED;
        
    }

    return i32Res;
}

/****************************************************************************/

int32_t i32UART_WriteByte(uart_Ch_e eCh, uint8_t u8Data)
{
    int32_t i32Res = C_SUCCESS;

    if(1U == u32UART_IsTxFifoReady(eCh))
    {
        /* Write one byte */
        vSetSITFIFO(eCh, u8Data);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}

/****************************************************************************/

uint32_t u32UART_WriteData(uart_Ch_e eCh, const uint8_t pu8Data[], uint32_t u32Len)
{
    uint32_t u32FifoRdy = 1U;
    uint32_t u32Cnt     = 0U;

    if (0x0U != pu8Data)
    {
        /* Send byte by byte */
        while((u32Cnt < u32Len) && (u32FifoRdy>0U))
        {
            if((1U == u32UART_IsTxFifoReady(eCh)))
            {
                /* Write one byte */
                vSetSITFIFO(eCh, pu8Data[u32Cnt]);
                u32Cnt++;
            }
            else
            {
                /* No more space in TX-FIFO */
                u32FifoRdy = 0U; 
            }
        }
    }
    return u32Cnt;
}

/****************************************************************************/

int32_t i32UART_ReadByte(uart_Ch_e eCh, uint8_t *pu8Data)
{
    int32_t i32Res = C_FAILED;  /* No data in Rx FIFO */
    
    if (0x0U != pu8Data)
    {
        if( biGetSIDISR_RFDN(eCh) > 0U )
        {
            if( 0U == biGetSIDISR_ERI(eCh) )
            {
                *pu8Data = u8GetSIRFIFO(eCh);
                i32Res = C_SUCCESS;  /* data in Rx FIFO */
            }
        }
    }
    return i32Res;
}

/****************************************************************************/

int32_t i32UART_ReadData(uart_Ch_e eCh, uint8_t pu8Data[], uint32_t *pu32Len)
{

    uint16_t u16DataFrames;
    uint16_t u16Error = 0U;
    int32_t i32Res = C_SUCCESS;

    if ( (0x0U != pu8Data) && (0x0U != pu32Len) )
    {
        *pu32Len = 0U;

        /* Check if any data stored */
        u16DataFrames = biGetSIDISR_RFDN(eCh);

        while( (*pu32Len < 32U) && (u16DataFrames > 0U) )
        {
            /* Check if error */
            u16Error = biGetSIDISR_ERI(eCh);

            if( 0U == u16Error )
            {
                pu8Data[*pu32Len] = u8GetSIRFIFO(eCh);
                u16DataFrames = biGetSIDISR_RFDN(eCh);
                (*pu32Len)++;
            }
            else
            {
                i32Res = C_FAILED;  /* Error */
                break;
            }
        }
    }
    else
    {
        i32Res = C_FAILED;
    }
    return i32Res;
}

/****************************************************************************/

int32_t i32UART_IsTimeOut(uart_Ch_e eCh)
{
    int32_t i32TimeOut;

    /* Read time-out status */
    i32TimeOut = (int32_t) biGetSIDISR_TOUT(eCh);

    /* Clear the time-out flag */
    if(1 == i32TimeOut)
    {
        vClrSIDISR_TOUT(eCh);
    }

    return i32TimeOut;
}

/****************************************************************************/

uint8_t u8UART_GetRxDataCnt(uart_Ch_e eCh)
{
    return (uint8_t) biGetSIDISR_RFDN(eCh);
}

/****************************************************************************/

uint32_t u32UART_IsTxFifoReady(uart_Ch_e eCh)
{
    return (uint32_t) biGetSISCISR_TRDY(eCh);
}

/****************************************************************************/

uint16_t u16UART_GetDmaIrqStat(uart_Ch_e eCh)
{
  uint16_t u16IrqStat;

  /* Get register value */
  u16IrqStat = u16GetSIDISR(eCh);

  return u16IrqStat;
}

/****************************************************************************/

void vUART_ClearDmaIrqFlag(uart_Ch_e eCh, uart_Flag_e eFlag)
{
    uint16_t u16Mask;

    /* Mask for clearing */
    u16Mask = (uint16_t)(eFlag);

    /* Select the register */
    if(eFlag > UART_FLG_OERS)
    {
        /* DIDISR register */
        vSetSIDISR(eCh, ~u16Mask);
    }
    else
    {
       /* SISCISR register */
       vSetSISCISR(eCh, (uint8_t)(~u16Mask));
    }
}

/****************************************************************************/

uint32_t u32UART_IsTxFifoFree(uart_Ch_e eCh)
{
    return (uint32_t) biGetSISCISR_TXALS(eCh);
}

/****************************************************************************/
static  void  vUART_Wait(void)
{
    volatile uint32_t  u32Cnt;
    /* Wait ~15 core cycles */
    for(u32Cnt = 0; u32Cnt < 15; u32Cnt++)
    {    
        /* violation of MISRA rule 1.1 due to necessary inline assembler */
/*        __asm("nop");*/                       /* PRQA S 1006 */
        ;
    }    
}


/****************************************************************************/

void vUART_Reset(uart_Ch_e eCh)
{
    /* Apply reset */
    vSetSIFCR_SWRST(eCh, 1);

    /* 
     *  Make sure that the previous instrcution is completed
     *  ARM data barrier replaces the MIPS "sync"
     */
    /* violation of MISRA rule 1.1 due to necessary inline assembler */

    __DSB(); 

    /* Wait for reset to complete (TX49 frequency / EBUS frequency = 1 / 2) */
    vUART_Wait();
}

/****************************************************************************/

void vUART_FifoResetTx(uart_Ch_e eCh, uart_SwRst_e eRstEn)
{
    uint16_t u16RegVal;

    u16RegVal = u16GetSIFCR(eCh);

    if(UART_RST_ACTIVE == eRstEn)
    {
        u16RegVal |= 0x05U;
    }
    else
    {
        u16RegVal &= 0xfffaU;
    }

    vSetSIFCR(eCh, u16RegVal);
}

/****************************************************************************/

void vUART_FifoResetRx(uart_Ch_e eCh, uart_SwRst_e eRstEn)
{
    uint16_t u16RegVal;

    u16RegVal = u16GetSIFCR(eCh);

    if(UART_RST_ACTIVE == eRstEn)
    {
        u16RegVal |= 0x03U;
    }
    else
    {
        u16RegVal &= 0xfffcU;
    }

    vSetSIFCR(eCh, u16RegVal);
}

/****************************************************************************/

void vUART_TxRunCtrl(uart_Ch_e eCh, uart_Tsdr_e eRunCtrl)
{
    vSetSIFLCR_TSDR(eCh, (uint16_t)eRunCtrl);
}

/****************************************************************************/

void vUART_TxBreak(uart_Ch_e eCh, uart_Tbrk_e eBreak)
{
    vSetSIFLCR_TBRK(eCh, (uint16_t)eBreak);
}

/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */   

/****************************************************************************/

/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 1847 / 10.3 - cast of complex integer expression with underlying type
** |                        "type" to non-integer type "type" not allowed 
** | CONS.  : disable
** | REASON : to use macros from i/o header files, unavoidable when addressing 
** |          memory mapped registers 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   :   Deactivated:
** |     Not requested Rules: 
** |         Rule 11.3 [A] : Functions must always have prototype declarations
** |
** |     Requested Rules:
** |         Rule 10.1 [R] : Restrict implicit conversions for integer type expressions:
** |                         Used to have access to register bits of I/O header files
** |         Rule 10.5 [R] : Bitwise `~' and `<<' expressions on unsigned char or unsigned short:
** |                         Used for bit manuplations of I/O header files
** |         Rule 17.4 [R] : No pointer arithmetic other than array indexing:
** |                         This is necessary to have access to macros generated by converter tool
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/

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

