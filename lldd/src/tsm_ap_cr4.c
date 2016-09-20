/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION :
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TSM-Application Port-CR4
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.38 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "cr4_burst_access.h" 
#include "tsm_ap_cr4_io.h"
#include "tsm_ap.h"
#include "tsm_ap_cr4.h"

#ifdef HW_EMULATION_AP
  #include "stdio.h"
  #include "ap_hw_emulation.h"
#endif

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error */
  #pragma ghs nowarning 1877  /* Rule 11.3 [A] : disable casting error */
#endif

#ifdef M3_R4_EMULATION
  #include "ARMCM3.h"       /* Cortex-M3 specific defintions */
  #include "tsm_irq_handlers.h"

  extern  tsm_ap_err_e eTSM_AP_GetDeviceMode(tsm_ap_TsmType_e* const peTsmType);

  #define ERC_BUSY_BIT  0x0400;
#endif


/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/
/* Mask for AP-Command reister: */
#define MASK_AP_CMD     0x000FFFFFU
#define MASK_AP_SUBCMD  0x0000000FU

/* Mask for AP-ERC reister: */
#define MASK_AP_ERC_FLAG_STATUS  0x0000FFFFU
#define MASK_AP_ERC_FLAG_CANCEL  0x40000000U
#define MASK_AP_ERC_FLAG_VALID   0x80000000U

/* Rx/Tx FiFo Address */
#define RX_FIFO_IN_REG__      0xC010B180U
#define TX_FIFO_OUT_REG__     0xC010B1A0U

/*********************************************/


/**********************************************
*                    Macros                   *
**********************************************/


/*********************************************/


/**********************************************
*             Function definition             *
*********************************************/
/****************************************************************************/
/* -->Register Description #0 */
tsm_ap_err_e eTSM_AP_SetCommand(const tsm_cmd_st * const pstSheCommand)
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;
    uint32_t     u32CmdValue;

    if ((C_NULL != pstSheCommand) &&
        ((CMD_ID_NORM == pstSheCommand->eCmdID) ||
         (CMD_ID_CANCEL == pstSheCommand->eCmdID)) )
        {
        u32CmdValue  =  ((uint32_t)(pstSheCommand->eCmdID))<< 24;
        u32CmdValue  += ((uint32_t)(pstSheCommand->eCmd)& MASK_AP_CMD)<< 4;
        u32CmdValue  += ((uint32_t)(pstSheCommand->eSubCmd) & MASK_AP_SUBCMD);

        vSetCommand (u32CmdValue);
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }
#ifdef M3_R4_EMULATION
    if ( TSM_AP_NO_ERROR == eRet)
    {
        uint32_t u32Status;
        uint32_t u32Erc;
        bool_t   boBusy;
        tsm_ap_TsmType_e eCurDevMode = TSM_L_MODE;

        boBusy = biGetSTATUS_BUSY();
        if (C_FALSE == boBusy)
        {
            /* set Busy-Bit (Bit [0]) in status register to "1"  */
            u32Status = u32GetSTATUS();
            u32Status &= ~(uint32_t)0x01U;
            u32Status |= (uint32_t)0x01U;
            vSetSTATUS(u32Status);

            if (CMD_ID_NORM == pstSheCommand->eCmdID)
            {
                /* trigger CMD interrupt */
                NVIC_SetPendingIRQ(CMD_IRQn);  /* CMD Interrupt */
            }
            else
            {
                /* trigger CANCEL interrupt */
                NVIC_SetPendingIRQ(Cancel_IRQn);  /* CANCEL Interrupt */
            }
            (void) eTSM_AP_GetDeviceMode(&eCurDevMode);
            
            vTSM_IRQ_BottomHalfScheduler(eCurDevMode); /* call command dispatcher */
            
        }
        else
        {
            /* Set ERC-Busy Bit in ERC register: */
            u32Erc = u32GetERC_FLAG();
            u32Erc |= ERC_BUSY_BIT;

            vSetERC_FLAG (u32Erc);
        }
    }
#endif
    return eRet;
}
/****************************************************************************/
/* -->Register Description #1 */
tsm_ap_err_e eTSM_AP_GetStatus_CR4(tsm_ap_status_st * const pstStatus)
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;

    if (C_NULL != pstStatus)
    {
        pstStatus->eBusy          = (bool_t)biGetSTATUS_BUSY();
        pstStatus->eSecure_Boot   = (bool_t)biGetSTATUS_SECURE_BOOT();
        pstStatus->eBoot_Init     = (bool_t)biGetSTATUS_BOOT_INIT();
        pstStatus->eBoot_finished = (bool_t)biGetSTATUS_BOOT_FINISHED();
        pstStatus->eBoot_Ok       = (bool_t)biGetSTATUS_BOOT_OK();
        pstStatus->eRnd_Init      = (bool_t)biGetSTATUS_RND_INIT();
        pstStatus->eExt_DebuggEr  = (bool_t)biGetSTATUS_EXT_DEBUGGER();
        pstStatus->eInt_DebuggEr  = (bool_t)biGetSTATUS_INT_DEBUGGER();
        pstStatus->eTsm_Ready     = (bool_t)biGetSTATUS_TSM_ready();
        pstStatus->eShe           = (tsm_ap_TsmType_e) biGetSTATUS_SHE();        
        pstStatus->eFlashSize     = eTSM_AP_GetFlashSize_CR4();
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/
tsm_ap_FlashSizeX_e eTSM_AP_GetFlashSize_CR4(void)
{
    /* Note integrated flash size should be interpreted with information of Cap-Type
     * (Cap-Bt or Cap-C) This should be done in higher appliction. */
    tsm_ap_FlashSizeX_e  eSize;
    uint32_t u32B0, u32B1, u32Bx;
    
    u32B0 = biGetSTATUS_FLASH_SIZE0();
    u32B1 = biGetSTATUS_FLASH_SIZE1();

    u32Bx = (2U * u32B1) + u32B0;
    
    switch (u32Bx)
    {
        case 0:
            eSize = eApFlashSize_0;
            break;
            
        case 1:
            eSize = eApFlashSize_1;
            break;
            
        case 2:
            eSize = eApFlashSize_2;
            break;
            
        default:
            eSize = eApFlashSize_3;
            break;
    }
    return eSize;
}
/****************************************************************************/
bool_t boTSM_AP_IsTsmReady(void)
{
    bool_t boRes;

    if ( 0U == biGetSTATUS_TSM_ready() )
    {    
        boRes = C_FALSE;
    }
    else
    {
        boRes = C_TRUE;
    }
    return boRes;
}
/****************************************************************************/
bool_t boTSM_AP_IsFullShe(void)
{
    bool_t boRes;

    if ( 0U == biGetSTATUS_SHE() )
    {    
        boRes = C_FALSE;
    }
    else
    {
        boRes = C_TRUE;
    }    
    return boRes;
}


/****************************************************************************/
/* -->Register Description #2 */
tsm_ap_err_e eTSM_AP_GetErcStatus_CR4(tsm_ap_Erc_st * const pstErc)
{
    /* Please Note:
     * ERC Status register is a special register. With every read from this
     * register the HW clears "Valid-Flag" and Busy flag in status register (if Valid flag=1)
     * It meand the bits "Valid", "Cancel" and "Flag status " should not be read
     * seperatedly by Macros of tsm_ap_cr4.io". Thw whole 32 bits register should be read
     * once and be validated by masks: */

    tsm_ap_err_e  eRet=TSM_AP_NO_ERROR;
    uint32_t      u32ErcRegData;

    if (C_NULL != pstErc)
    {
        /* get the register as 32 bits value: */
        u32ErcRegData = u32GetERC_FLAG();

        /* Mask cancel bit: */
        if (0x00U == (u32ErcRegData & MASK_AP_ERC_FLAG_CANCEL))
        {
            pstErc->eCancel = C_FALSE;
        }
        else
        {
            pstErc->eCancel = C_TRUE;
        }
        /* mask valid bit: */
        if (0x00U == (u32ErcRegData & MASK_AP_ERC_FLAG_VALID))
        {
            pstErc->eValid = C_FALSE;
        }
        else
        {
            pstErc->eValid = C_TRUE;
        }
        
        /* mask ERC flag value: */
        u32ErcRegData &= MASK_AP_ERC_FLAG_STATUS;
        
        /* cast value to destination, required single step for Misra checker */
        pstErc->eErc_Flags = (tsm_erc_e)(u32ErcRegData);

        
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }
#ifdef M3_R4_EMULATION
        /* 1- reset Valid flag & Busy Flag, on if Valid Flag was set ("1")
         * 2- reset ERC regisetr to 0 : */
        if (C_TRUE == pstErc->eValid)
        {
            /* step 1: */
            uint32_t u32Status;
            /* reset Busy-Bit (Bit [0]) in status register to "0"  */
            u32Status = u32GetSTATUS();
            u32Status &= ~(uint32_t)0x01U;
            vSetSTATUS(u32Status);

            /* step 2: */
            vSetERC_FLAG(0x00U);

        }
#endif
    return eRet;
}
/****************************************************************************/
/* -->Register Description #3 */
tsm_ap_err_e eTSM_AP_GetRxFifoStatus_CR4(tsm_ap_RxFifoStatus_CR4_st * const pstRxFifoStatus)
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;

    if (C_NULL != pstRxFifoStatus)
    {
        pstRxFifoStatus->eRxFull        = (bool_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_F();
        pstRxFifoStatus->eRx_4WordsAv   = (bool_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_4A();
        pstRxFifoStatus->eRx_16WordsAv  = (bool_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_16A();
        pstRxFifoStatus->eRx_128WordsAv = (bool_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_128A();
        pstRxFifoStatus->eRx_256WordsAv = (bool_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_256A();
        pstRxFifoStatus->eRx_384WordsAv = (bool_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_384A();
        pstRxFifoStatus->eRxEmpty       = (bool_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_E();
        pstRxFifoStatus->u32RxCounter   = (uint32_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_C();
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/
/* -->Register Description #3 */
bool_t boTSM_AP_RxFifo_4WordsFree(void)
{
    bool_t boRet;

    if (0U == biGetCR4_RX_FIFO_STATUS_CR4_RX_4A())
    {
        boRet = C_FALSE;
    }
    else
    {
        boRet = C_TRUE;
    }
    return boRet;
}
/****************************************************************************/
/* -->Register Description #3 */
uint32_t u32TSM_AP_RxFifo_CntWordsFree(void)
{
    uint32_t u3Cnt;

    u3Cnt = (uint32_t) biGetCR4_RX_FIFO_STATUS_CR4_RX_C();
    return u3Cnt;
}
/****************************************************************************/
/* -->Register Description #4 */
tsm_ap_err_e eTSM_AP_GetRxFifoIrqConfig_CR4(tsm_ap_RxFifoIrqConfig_st * const pstRxFifoIrqConfig)
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;

    if (C_NULL != pstRxFifoIrqConfig)
    {
        pstRxFifoIrqConfig->eIrqRxEmpty       = (bool_t) biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_F_EN();
        pstRxFifoIrqConfig->eIrqRx_4WordsAv   = (bool_t) biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_4A_EN();
        pstRxFifoIrqConfig->eIrqRx_16WordsAv  = (bool_t) biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_16A_EN();
        pstRxFifoIrqConfig->eIrqRx_128WordsAv = (bool_t) biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_128A_EN();
        pstRxFifoIrqConfig->eIrqRx_256WordsAv = (bool_t) biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_256A_EN();
        pstRxFifoIrqConfig->eIrqRx_384WordsAv = (bool_t) biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_384A_EN();
        pstRxFifoIrqConfig->eIrqRxFull        = (bool_t) biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_E_EN();
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/
/* -->Register Description #4 */
tsm_ap_err_e eTSM_AP_SetRxFifoIrqConfig_CR4(const tsm_ap_RxFifoIrqConfig_st * const pstRxFifoIrqConfig)
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;

    if (C_NULL != pstRxFifoIrqConfig)
    {
        vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_F_EN    ((uint32_t) pstRxFifoIrqConfig->eIrqRxEmpty);
        vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_4A_EN   ((uint32_t) pstRxFifoIrqConfig->eIrqRx_4WordsAv);
        vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_16A_EN  ((uint32_t) pstRxFifoIrqConfig->eIrqRx_16WordsAv);
        vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_128A_EN ((uint32_t) pstRxFifoIrqConfig->eIrqRx_128WordsAv);
        vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_256A_EN ((uint32_t) pstRxFifoIrqConfig->eIrqRx_256WordsAv);
        vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_384A_EN ((uint32_t) pstRxFifoIrqConfig->eIrqRx_384WordsAv);
        vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_E_EN    ((uint32_t) pstRxFifoIrqConfig->eIrqRxFull);
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/
/* -->Register Description #4 */
void vTSM_AP_ClearRxFifo_CR4(void)
{
    vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_CLEAR((uint32_t) C_TRUE);
    /*  NOTE: Should be set to zerro by SW??????????? */
    vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_CLEAR((uint32_t) C_FALSE);

#ifdef HW_EMULATION_AP
    vTSM_AP_ClearRxFifo_EMUL();
#endif
}
/****************************************************************************/
/* -->Register Description #4 */
tsm_ap_RxFifoIrqDest_e eTSM_AP_GetRxFifoIrqDestination_CR4(void)
{
    tsm_ap_RxFifoIrqDest_e eDest;
    eDest = (tsm_ap_RxFifoIrqDest_e) biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_D_I();
    return eDest;
}
/****************************************************************************/
/* -->Register Description #4 */
void vTSM_AP_SetRxFifoIrqDestination(const tsm_ap_RxFifoIrqDest_e  eRxIrqDest)
{
    vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_D_I((uint32_t) eRxIrqDest);
}
/****************************************************************************/
/* -->Register Description #4 */
void vTSM_AP_EnableRxFifoIrqs_CR4(void)
{
    vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_IRQ_EN((uint32_t) C_TRUE);
}
/****************************************************************************/
/* -->Register Description #4 */
void vTSM_AP_DisableRxFifoIrqs_CR4(void)
{
    vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_IRQ_EN((uint32_t) C_FALSE);
}
/****************************************************************************/
/* -->Register Description #5 */
tsm_ap_err_e eTSM_AP_GetTxFifoStatus_CR4(tsm_ap_TxFifoStatus_CR4_st * const pstTxFifoStatus)
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;

    if (C_NULL != pstTxFifoStatus)
    {
        pstTxFifoStatus->eTxEmpty       = (bool_t) biGetCR4_TX_FIFO_STATUS_CR4_TX_E();
        pstTxFifoStatus->eTx_4WordsAv   = (bool_t) biGetCR4_TX_FIFO_STATUS_CR4_TX_4A();
        pstTxFifoStatus->eTx_128WordsAv = (bool_t) biGetCR4_TX_FIFO_STATUS_CR4_TX_128A();
        pstTxFifoStatus->eTx_256WordsAv = (bool_t) biGetCR4_TX_FIFO_STATUS_CR4_TX_256A();
        pstTxFifoStatus->eTxFull        = (bool_t) biGetCR4_TX_FIFO_STATUS_CR4_TX_F();
        pstTxFifoStatus->u32TxCounter   = (uint32_t) biGetCR4_TX_FIFO_STATUS_CR4_TX_C();
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/
/* -->Register Description #5 */
bool_t boTSM_AP_TxFifo_4WordsAv(void)
{
    bool_t boRet;

    if (0U == biGetCR4_TX_FIFO_STATUS_CR4_TX_4A())
    {
        boRet = C_FALSE;
    }
    else
    {
        boRet = C_TRUE;
    }
    return boRet;
}
/****************************************************************************/
/* -->Register Description #5 */
uint32_t u32TSM_AP_TxFifo_CntWordsAv(void)
{
    uint32_t u32Cnt;

    u32Cnt   = (uint32_t) biGetCR4_TX_FIFO_STATUS_CR4_TX_C();
    
    return u32Cnt;
}
/****************************************************************************/
/* -->Register Description #6 */
tsm_ap_err_e eTSM_AP_GetTxFifoIrqConfig_CR4(tsm_ap_TxFifoIrqConfig_CR4_st * const pstTxFifoIrqConfig)
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;

    if (C_NULL != pstTxFifoIrqConfig)
    {
        pstTxFifoIrqConfig->eIrqTxEmpty       = (bool_t) biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_E_EN();
        pstTxFifoIrqConfig->eIrqTx_4WordsAv   = (bool_t) biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_4A_EN();
        pstTxFifoIrqConfig->eIrqTx_128WordsAv = (bool_t) biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_128A_EN();
        pstTxFifoIrqConfig->eIrqTx_256WordsAv = (bool_t) biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_256A_EN();
        pstTxFifoIrqConfig->eIrqTxFull        = (bool_t) biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_F_EN();
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/
/* -->Register Description #6 */
tsm_ap_err_e eTSM_AP_SetTxFifoIrqConfig_CR4(const tsm_ap_TxFifoIrqConfig_CR4_st * const pstTxFifoIrqConfig)
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;

    if (C_NULL != pstTxFifoIrqConfig)
    {
        vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_E_EN((uint32_t) pstTxFifoIrqConfig->eIrqTxEmpty);
        vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_4A_EN((uint32_t) pstTxFifoIrqConfig->eIrqTx_4WordsAv);
        vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_128A_EN((uint32_t) pstTxFifoIrqConfig->eIrqTx_128WordsAv);
        vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_256A_EN((uint32_t) pstTxFifoIrqConfig->eIrqTx_256WordsAv);
        vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_F_EN((uint32_t) pstTxFifoIrqConfig->eIrqTxFull);
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/
/* -->Register Description #6 */
void vTSM_AP_ClearTxFifo_CR4(void)
{
    vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_CLEAR((uint32_t) C_TRUE);
    /*  NOTE: Should be set to zerro by SW??????????? */
    vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_CLEAR((uint32_t) C_FALSE);

#ifdef HW_EMULATION_AP
    vTSM_AP_ClearTxFifo_EMUL();
#endif
}
/****************************************************************************/
/* -->Register Description #6 */
tsm_ap_TxFifoIrqDest_e eTSM_AP_GetTxFifoIrqDestination_CR4(void)
{
    tsm_ap_TxFifoIrqDest_e eDest;
    eDest = (tsm_ap_TxFifoIrqDest_e) biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_D_I();
    return eDest;
}
/****************************************************************************/
/* -->Register Description #6 */
void vTSM_AP_SetTxFifoIrqDestination_CR4(const tsm_ap_TxFifoIrqDest_e  eTxIrqDest)
{
    vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_D_I((uint32_t) eTxIrqDest);
}
/****************************************************************************/
/* -->Register Description #6 */
void vTSM_AP_EnableTxFifoIrqs_CR4(void)
{
    vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_IRQ_EN((uint32_t) C_TRUE);
}
/****************************************************************************/
/* -->Register Description #6 */
void vTSM_AP_DisableTxFifoIrqs_CR4(void)
{
    vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_IRQ_EN((uint32_t) C_FALSE);
}
/****************************************************************************/
/* -->Register Description #7..10 */
tsm_ap_err_e eTSM_AP_GetUid_CR4(uint32_t  au32UidData[4])
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;
    uint32_t     u32LsbByte_1,u32LsbByte_2, u32LsbByte_3;

    if (C_NULL != au32UidData)
    {
        au32UidData[0]   = u32GetUID_IN0();
        au32UidData[1]   = u32GetUID_IN1();
        au32UidData[2]   = u32GetUID_IN2();
        au32UidData[3]   = u32GetUID_IN3();

        u32LsbByte_1 = au32UidData[1] & 0xFFU;
        u32LsbByte_2 = au32UidData[2] & 0xFFU;
        u32LsbByte_3 = au32UidData[3] & 0xFFU;

        au32UidData[0] = (au32UidData[0]>>8) + (u32LsbByte_1<<24);
        au32UidData[1] = (au32UidData[1]>>8) + (u32LsbByte_2<<24);
        au32UidData[2] = (au32UidData[2]>>8) + (u32LsbByte_3<<24);
        au32UidData[3] =  au32UidData[3]>>8;
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/
/* -->Register Description #11 */
tsm_ap_err_e u32TSM_AP_WriteDP_Param(const uint32_t au32Params[], const uint32_t u32Size)
{
    uint32_t u32i;
    uint32_t u32SizeLocal = u32Size;
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;

    if (C_NULL != au32Params)
    {
        if (u32Size > DP_PARAM_SIZE_MAX)
        {
            u32SizeLocal = DP_PARAM_SIZE_MAX;
        }
        for (u32i=0U; u32i < u32SizeLocal; u32i++)
        {
#if defined(__GHS__) || defined(__ghs__)
/* Misra Checker has a problem with this Macro which contains an addition
   between the variable (ui32Loop) and a fix value. If the Macro is used with
   two fix values there is no error shown by the Misra checker. There is no way to
   fix the problem, so simple ignore the error.
   disable warning for violation Misra Rule 10.1 */
#pragma ghs nowarning 1867
/* disable warning for violation Misra Rule 10.3 */
#pragma ghs nowarning 1847
#endif /* defined(__GHS__) || defined(__ghs__) */                    
            vSetCR4_DP_PARAM_PARAM_DATA(u32i, au32Params[u32i]);
#if defined(__GHS__) || defined(__ghs__)
#pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */
        }
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }
    return eRet;
}

/****************************************************************************/
/* -->Register Description #11 */
tsm_ap_err_e u32TSM_AP_ReadDP_ParamStat_CR4(uint32_t au32Params[2])
{
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;
    
    if (C_NULL != au32Params)
    {
        /* retrieve the statistical data from DP param */        
       au32Params[0] = biGetCR4_DP_PARAM_PARAM_DATA(30);
       au32Params[1] = biGetCR4_DP_PARAM_PARAM_DATA(31);
       
       /* and invalidate the data in the DP param right after retrieval */
       vSetCR4_DP_PARAM_PARAM_DATA(30U, 0x00000000U);
       vSetCR4_DP_PARAM_PARAM_DATA(31U, 0x00000000U);
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }
    
    return eRet;
}
/****************************************************************************/
/* -->Register Description #12 */

tsm_ap_err_e eTSM_AP_WriteRxFIFO(const uint32_t au32Data[], const uint32_t u32Size)
{
    uint32_t      u32i;
    uint32_t      u32FreeCnt;
    tsm_ap_err_e  eRet=TSM_AP_NO_ERROR;
#ifndef HW_EMULATION_AP
    uint32_t u32Offset;
#endif

    if (C_NULL != au32Data)
    {
        /* check how many free words are available in FIFO: */
        u32FreeCnt = u32TSM_AP_RxFifo_CntWordsFree();

        if (u32Size > u32FreeCnt)
        {
            eRet = TSM_AP_FIFO_NOT_ENOUGH_SPACE_FREE;
        }
        else
        {
#ifdef HW_EMULATION_AP
            for (u32i=0U; u32i<u32Size; u32i++)
            {
                /* there are 8 registers available for write. In case of no burst8
                 * we write in first register: */
                /* vSetRX_FIFO_IN(pu32Data[u32i%8], u32i);*/

                vSetRX_FIFO_IN_EMUL(0, au32Data[u32i]);
            }
#else
            if (0U < (u32Size / 8U))
            {
                /* burst8 */
                vASM_Copy8WordsInBurstMem2FiFo((uint32_t)au32Data, (uint32_t)RX_FIFO_IN_REG__, (u32Size / 8U));
            }
            
            /* copy remaining data in 32bit words, if any */
            u32Offset =  (u32Size / 8U) * 8U;
            
            for (u32i=0U; (u32i < (u32Size % 8U)); u32i++)
            {
                /* there are 8 registers available for write. In case of no burst
                 * we write in first register: */
                vSetRX_FIFO_IN(0, au32Data[u32i + u32Offset]);
            }
#endif
        }
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }
    return eRet;
}
/****************************************************************************/
/* -->Register Description #12 */

tsm_ap_err_e eTSM_AP_WriteRxFIFO_4Words(const uint32_t au32Data[])
{
#ifdef HW_EMULATION_AP
    uint32_t      u32i;
#endif
    uint32_t      u32FreeCnt;
    tsm_ap_err_e  eRet=TSM_AP_NO_ERROR;
    uint32_t      u32Size = 0x04U;

    if (C_NULL != au32Data)
    {
        /* check how many free words are available in FIFO: */
        u32FreeCnt = u32TSM_AP_RxFifo_CntWordsFree();

        if (u32Size > u32FreeCnt)
        {
            eRet = TSM_AP_FIFO_NOT_ENOUGH_SPACE_FREE;
        }
        else
        {
#ifdef HW_EMULATION_AP
            for (u32i=0U; u32i<u32Size; u32i++)
            {
                /* there are 8 registers available for write. In case of no burst8
                 * we write in first register: */
                /* vSetRX_FIFO_IN(pu32Data[u32i%8], u32i);*/

                vSetRX_FIFO_IN_EMUL(0, au32Data[u32i]);
            }
#else
            /* burst4 */
            vASM_Copy4WordsInBurstMem2FiFo((uint32_t)au32Data, (uint32_t)RX_FIFO_IN_REG__, 1U);
#endif
        }
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }
    return eRet;
}
/****************************************************************************/
/* -->Register Description #13 */

tsm_ap_err_e eTSM_AP_ReadTxFIFO(uint32_t au32Data[], const uint32_t u32Size)
{
    uint32_t   u32i;
    uint32_t   u32AvailCnt;
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;
#ifndef HW_EMULATION_AP
    uint32_t u32Offset;
#endif    

    if (C_NULL != au32Data)
    {
        /* check how many words are available in FIFO: */
        u32AvailCnt = u32TSM_AP_TxFifo_CntWordsAv();

        if (u32Size > u32AvailCnt)
        {
            eRet = TSM_AP_FIFO_NOT_ENOUGH_DATA_AVAIL;
        }
        else
        {
#ifdef HW_EMULATION_AP            
            for (u32i=0U; u32i<u32Size; u32i++)
            {
                au32Data[u32i] = u32GetTX_FIFO_OUT_EMUL(0);
            }
#else
            if (0U < (u32Size / 8U))
            {
                /* burst8 */
                vASM_Copy8WordsInBurstFiFo2Mem((uint32_t)TX_FIFO_OUT_REG__, (uint32_t)au32Data, (u32Size / 8U));
            }
            /* copy remaining data in 32bit words, if any */
            u32Offset =  (u32Size / 8U) * 8U;
            
            for (u32i=0U; (u32i < (u32Size % 8U)); u32i++)
            {
                au32Data[u32i + u32Offset] = u32GetTX_FIFO_OUT(0);
            }
#endif
        }
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}

/****************************************************************************/
/* -->Register Description #13 */

tsm_ap_err_e eTSM_AP_ReadTxFIFO_4Words(uint32_t au32Data[])
{
#ifdef HW_EMULATION_AP
    uint32_t   u32i;
#endif    
    uint32_t   u32AvailCnt;
    tsm_ap_err_e eRet=TSM_AP_NO_ERROR;
    uint32_t    u32Size = 0x04U;

    if (C_NULL != au32Data)
    {
        /* check how many words are available in FIFO: */
        u32AvailCnt = u32TSM_AP_TxFifo_CntWordsAv();

        if (u32Size > u32AvailCnt)
        {
            eRet = TSM_AP_FIFO_NOT_ENOUGH_DATA_AVAIL;
        }
        else
        {
#ifdef HW_EMULATION_AP            
            for (u32i=0U; u32i<u32Size; u32i++)
            {
                au32Data[u32i] = u32GetTX_FIFO_OUT_EMUL(0);
            }
#else
            /* burst4 */
            vASM_Copy4WordsInBurstFiFo2Mem((uint32_t)TX_FIFO_OUT_REG__, (uint32_t)au32Data, 1U);
#endif
        }
    }
    else
    {
        eRet=TSM_AP_WRONG_PARAMS;
    }

    return eRet;
}
/****************************************************************************/

#ifdef HW_EMULATION_AP
#ifdef M3_R4_EMULATION

void vPrintFifoStatus__CR4(void)
{
    uint32_t u32Data;
    uint8_t  c_F, c_256, c_128, c_4, c_E;
    uint32_t u32Cnt;

    c_F   = (biGetCR4_RX_FIFO_STATUS_CR4_RX_F())   ? 1:0;
    c_256 = (biGetCR4_RX_FIFO_STATUS_CR4_RX_256A())? 1:0;
    c_128 = (biGetCR4_RX_FIFO_STATUS_CR4_RX_128A())? 1:0;
    c_4   = (biGetCR4_RX_FIFO_STATUS_CR4_RX_4A())  ? 1:0;
    c_E   = (biGetCR4_RX_FIFO_STATUS_CR4_RX_E())   ? 1:0;
    u32Cnt = biGetCR4_RX_FIFO_STATUS_CR4_RX_C();

    u32Data = u32GetCR4_RX_FIFO_STATUS();
    printf("+ %08x -----+---+-E-+---+256+128+---+-4-+-F-+--Cnt--|\n", u32Data);
    printf("|  CR4-RX(FREE) |   | %d |   | %d | %d |   | %d | %d |  %3d  |\n", c_E, c_256, c_128, c_4, c_F, u32Cnt);
    c_F   = (biGetCR4_TX_FIFO_STATUS_CR4_TX_F())   ? 1:0;
    c_256 = (biGetCR4_TX_FIFO_STATUS_CR4_TX_256A())? 1:0;
    c_128 = (biGetCR4_TX_FIFO_STATUS_CR4_TX_128A())? 1:0;
    c_4   = (biGetCR4_TX_FIFO_STATUS_CR4_TX_4A())  ? 1:0;
    c_E   = (biGetCR4_TX_FIFO_STATUS_CR4_TX_E())   ? 1:0;
    u32Cnt = biGetCR4_TX_FIFO_STATUS_CR4_TX_C();
    //printf("\n");
    u32Data = u32GetCR4_TX_FIFO_STATUS();
    printf("+ %08x -----+---+-F-+---+256+128+---+-4-+-E-+--Cnt--|\n", u32Data);
    printf("|  CR4-TX(AVAIL)|   | %d |   | %d | %d |   | %d | %d |  %3d  |\n", c_F, c_256, c_128, c_4, c_E, u32Cnt);
    printf("+---------------+---+---+---+---+---+---+---+---+-------|\n");
    printf("\n");
    printf("\n");
    return ;
}
/*-------------------------------------------------------*/
void vSetCR4_TX_FIFO_STATUS__(uint32_t u32Data)
{
    vSetCR4_TX_FIFO_STATUS(u32Data);
    return ;
}
/*-------------------------------------------------------*/
void vSetCR4_RX_FIFO_STATUS__(uint32_t u32Data)
{
    vSetCR4_RX_FIFO_STATUS(u32Data);
    return ;
}
#endif /* HW_EMULATION_AP */
#endif /* M3_R4_EMULATION */

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
  conditions set forth in the ?Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (?Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer?s own risk.

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


