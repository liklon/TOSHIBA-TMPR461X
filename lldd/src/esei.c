/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference ESEI Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Extended Serial Expansion Interface (ESEI)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "esei_io.h"                      /* ESEI registers, bits and access macros defintion */
#include "esei.h"                         /* ESEI LLDD definitions */

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1858  /* Rule 17.4 [R] : subscript operator may only be applied to objects declared as an array type */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1879  /* Rule 10.3 [R] : Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1880  /* Rule 10.3 [R] :  Restrict explicit casts for integer type expressions */

  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */  
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error (used for result of i/o header amcros) */
#endif


/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_ESEI_C_REVISION     "$Revision: 1.8 $"
#define LLDD_ESEI_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_ESEI_C_REVISION[]    = LLDD_ESEI_C_REVISION;
static uint8_t au8LLDD_ESEI_C_TAG[]         = LLDD_ESEI_C_TAG;
static uint8_t au8LLDD_ESEI_H_REVISION[]    = LLDD_ESEI_H_REVISION;
static uint8_t au8LLDD_ESEI_H_TAG[]         = LLDD_ESEI_H_TAG;
static uint8_t au8LLDD_ESEI_IO_H_REVISION[] = LLDD_ESEI_IO_H_REVISION;
static uint8_t au8LLDD_ESEI_IO_H_TAG[]      = LLDD_ESEI_IO_H_TAG;

/*********************************************/

/**********************************************
*        Exported function definition         *
**********************************************/

void vESEI_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_ESEI_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_ESEI_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_ESEI_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_ESEI_H_TAG[0];
   *pau8IORevision     = &au8LLDD_ESEI_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_ESEI_IO_H_TAG[0];
}


/****************************************************************************/
void vESEI_Config(esei_ch_e eCh, esei_ctrlcfg_st stCfg)
{
    esei_opmode_e eOpMode;

    /* Get current OPMODE */
    eOpMode = (esei_opmode_e) biGetSEMCR_OPMODE((uint16_t)eCh);

    /* Switch to configuration mode (if neccessary) */
    if( ESEI_OPM_ACT == eOpMode )
    {
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_CFG);
    }

    /* Master/Slave mode */
    vSetSECR0_MSTR(eCh, (uint16_t)stCfg.eMode);

    /* LSB/MSB Bit Order */
    vSetSECR0_SBOS(eCh, (uint16_t)stCfg.eBitOrder);

    /* SSI valid in Master Mode */
    vSetSECR0_SSIVAL(eCh, (uint16_t)stCfg.eSsiValid);

    /* SEI Phase selection */
    vSetSECR0_SPHA(eCh, (uint16_t)stCfg.ePhase);

    /* SEI Polarity (TX format) */
    vSetSECR0_SPOL(eCh, (uint16_t)stCfg.ePolarity);

    /* Restore OPMODE (if changed) */
    if( ESEI_OPM_ACT == eOpMode )
    {
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_ACT);
    }

}


/****************************************************************************/
void vESEI_IrqConfig(esei_ch_e eCh, esei_irqcfg_st stCfg)
{
    esei_opmode_e eOpMode;

    /* Save current OPMODE */
    eOpMode = (esei_opmode_e)(biGetSEMCR_OPMODE(eCh));

    /* Switch to configuration mode (if neccessary) */
    if( ESEI_OPM_ACT == eOpMode )
    {
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_CFG);
    }

    /* IDLE IRQ enable/disable */
    vSetSECR0_SILIE(eCh, (uint16_t)stCfg.eIdleIrqEn);
    /* Overflow IRQ enable/disable */
    vSetSECR0_SOEIE(eCh, (uint16_t)stCfg.eOvflowIrqEn);
    /* Underflow IRQ enable/disable */
    vSetSECR0_SUEIE(eCh, (uint16_t)stCfg.eUndflowIrqEn);
    /* TX format error IRQ enable/disable */
    vSetSECR0_STFIE(eCh, (uint16_t)stCfg.eTransFmtIrqEn);
    /* Parity IRQ enable/disbale */
    vSetSEPR_SPIE(eCh, (uint8_t)stCfg.eParityIrqEn);

    /* Restore OPMODE (if changed) */
    if(ESEI_OPM_ACT == eOpMode )
    {
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_ACT);
    }
}


/****************************************************************************/
void vESEI_SetOpMode(esei_ch_e eCh, esei_opmode_e eMode)
{
    vSetSEMCR_OPMODE(eCh, (uint8_t)eMode);
}


/****************************************************************************/
void vESEI_SetTransferSize(esei_ch_e eCh, esei_ssz_e eTxSize)
{
    esei_opmode_e eOpMode;

    /* Get current OPMODE */
    eOpMode = (esei_opmode_e) (biGetSEMCR_OPMODE((uint16_t)eCh));

    if( ESEI_OPM_ACT == eOpMode )
    {
        /* Switch to configuration mode */
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_CFG);

        /* Set Transfer Size */
        vSetSECR1_SSZ(eCh, (uint16_t)eTxSize);

        /* Restore Original OPMODE */
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_ACT);
    }
    else
    {
        /* Set Transfer Size */
        vSetSECR1_SSZ(eCh, (uint16_t)eTxSize);
    }

}

/****************************************************************************/
int32_t i32ESEI_SetBitRate(esei_ch_e eCh, uint32_t u32BitRate)
{
    uint8_t       u8Ser;
    esei_opmode_e eOpMode;
    int32_t       i32Res = C_SUCCESS;

    /* Get current OPMODE */
    eOpMode = (esei_opmode_e) (biGetSEMCR_OPMODE((uint16_t)eCh));

    if( (u32BitRate > (uint32_t) ESEI_MIN_BITRATE) && (u32BitRate <  (uint32_t) ESEI_MAX_BITRATE) )
    {
        /* Calculate SER parameter SER = (Fsys / 2Fsclk) - 1 */
        u8Ser = (uint8_t)(((((140U * 1000000U) / u32BitRate)/ 2U) - 1U) / 1000U);

        if( ESEI_OPM_ACT == eOpMode )
        {
            /* Switch to configuration mode */
            vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_CFG);

            /* Set SER */
            vSetSECR1_SER(eCh, u8Ser);

            /* Restore Original OPMODE */
            vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_ACT);
        }
        else
        {
            /* Set SER */
            vSetSECR1_SER(eCh, u8Ser);
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
void vESEI_ParityConfig(esei_ch_e eCh, esei_spp01_e eBitType,
                       esei_speo_e eMode, esei_en_e eStopEn)
{
    esei_opmode_e eOpMode;

    eOpMode = (esei_opmode_e)(biGetSEMCR_OPMODE(eCh));

    /* Switch to configuration mode (if neccessary) */
    if( ESEI_OPM_ACT == eOpMode )
    {
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_CFG);
    }

    /* Parity bit type */
    vSetSEPR_SPP01(eCh, (uint8_t)eBitType);

    /* Even/Odd type */
    vSetSEPR_SPEO(eCh, (uint8_t)eOpMode);

    /* Parity Stop enable */
    vSetSEPR_SPISE(eCh, (uint8_t)eStopEn);

    /* Restore OPMODE */
    if( ESEI_OPM_ACT == eOpMode )
    {
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_ACT);
    }
}


/****************************************************************************/
void vESEI_ParityEnable(esei_ch_e eCh, esei_en_e eEnable)
{
    esei_opmode_e eOpMode;

    eOpMode = (esei_opmode_e)(biGetSEMCR_OPMODE(eCh));

    if( ESEI_OPM_ACT == eOpMode )
    {
        /* Switch to configuration mode */
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_CFG);

        /* Parity enable */
        vSetSEPR_SPEN(eCh, (uint8_t)eEnable);

        /* Restore Original OPMODE */
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_ACT);
    }
    else
    {
        /* Parity enable */
        vSetSEPR_SPEN(eCh, (uint8_t)eEnable);
    }
}


/****************************************************************************/
void vESEI_SetTiming(esei_ch_e eCh, esei_en_e ePrescal, uint16_t u16IfCount, 
                     uint8_t u8SSCount)
{
    esei_mstr_e eMsMode;
    esei_spha_e eCphase;

    /* Get Master/slave mode: */
    eMsMode = (esei_mstr_e) biGetSECR0_MSTR(eCh);

    /* Get clock phase: */
    eCphase = (esei_spha_e) biGetSECR0_SPHA(eCh);

    /* Prescaler */
    vSetSECR0_IFSPSE(eCh, (uint16_t)ePrescal);

    /* Inter-Frame Counter set */
    vSetSEFSR_IFS(eCh, u16IfCount);

    /* If ESEI in slave mode and SPHA == LO, then SSS must be 4 */
    if( (ESEI_MODE_SLAVE == eMsMode) && (ESEI_ACT_LO == eCphase) )
    {
        /* Slave Select Space */
        vSetSSSR_SSS(eCh, 4U);
    }
    else
    {
        vSetSSSR_SSS(eCh, u8SSCount);
    }
}


/****************************************************************************/
int32_t i32ESEI_SetRunCtrl(esei_ch_e eCh, esei_sestp_e eStart)
{
    esei_mstr_e   eMsMode;
    esei_opmode_e eOpMode;
    int32_t       i32Res = C_SUCCESS;

    /* Get Master/slave mode: */
    eMsMode = (esei_mstr_e) biGetSECR0_MSTR(eCh);
    /* Get current OPMODE */
    eOpMode = (esei_opmode_e) (biGetSEMCR_OPMODE((uint16_t)eCh));

    if( (ESEI_MODE_MASTER == eMsMode) && (ESEI_OPM_ACT == eOpMode) )
    {
        vSetSEMCR_SESTP(eCh, (uint8_t) eStart);
    }
    else
    {
        /* Not possible to change the setting */
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
esei_sestp_e eESEI_GetRunCtrl(esei_ch_e eCh)
{
    return (esei_sestp_e) biGetSEMCR_SESTP(eCh);
}


/****************************************************************************/
int32_t i32ESEI_ClearBuffer(esei_ch_e eCh)
{
    esei_mstr_e  eMsMode;
    esei_sestp_e eSeiStop;
    esei_sidle_e eIdle;
    int32_t i32Res = C_SUCCESS;

    /* Get Master/slave mode: */
    eMsMode = (esei_mstr_e) biGetSECR0_MSTR(eCh);    

    /* Get SEI stop: */
    eSeiStop = (esei_sestp_e) biGetSEMCR_SESTP(eCh);    

    /* Get Idle indicator: */
    eIdle = (esei_sidle_e) biGetSESR_SIDLE(eCh);    

    /* Check if ESEI master mode, stopped and in IDLE */
    if( (ESEI_MODE_MASTER == eMsMode) && (ESEI_STOP == eSeiStop) && (ESEI_IDLE == eIdle) )
    {
        /* Buffer clear */
        vSetSEMCR_BCLR(eCh, 1U);
    }
    else
    {
        /* Safe buffer clear impossible */
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_DiagLoopEnable(esei_ch_e eCh, esei_en_e eEnable)
{
    esei_opmode_e eOpMode;
    esei_mstr_e eMsMode;
    int32_t     i32Res = C_SUCCESS;

    /* Get current OPMODE */
    eOpMode = (esei_opmode_e) (biGetSEMCR_OPMODE((uint16_t)eCh));
    /* Get Master/slave mode: */
    eMsMode = (esei_mstr_e) biGetSECR0_MSTR(eCh);

    /* Check if ESEI master mode and active */
    if( (ESEI_MODE_MASTER == eMsMode) && (ESEI_OPM_ACT == eOpMode) )
    {
        /* Diagnostic loop */
        vSetSEMCR_DLOOP(eCh, (uint8_t) eEnable);
    }
    else
    {
        /* Setting not possible */
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
void vESEI_SetMode(esei_ch_e eCh, esei_mstr_e eMode)
{
    esei_opmode_e eOpMode;

    /* Get current OPMODE */
    eOpMode = (esei_opmode_e) (biGetSEMCR_OPMODE((uint16_t)eCh));

    /* Swhich to configuration mode (if neccessary) */
    if( ESEI_OPM_ACT == eOpMode )
    {
        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_CFG);

        /* Master/slave mode */
        vSetSECR0_MSTR(eCh, (uint16_t)eMode);

        vSetSEMCR_OPMODE(eCh, (uint8_t)ESEI_OPM_ACT);
    }
    else
    {
        /* Master/slave mode */
        vSetSECR0_MSTR(eCh, (uint16_t)eMode);
    }
}


/****************************************************************************/
int32_t i32ESEI_IsTxBuffEmpty(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( 0U == biGetSESR_TBF(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_IsRxBuffFull(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( 0U == biGetSESR_RBF(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_IsParityErr(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t) ESEI_NOERR == biGetSESR_PAR(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
void vESEI_ClearParityErr(esei_ch_e eCh)
{
    if( (uint32_t)ESEI_ERROR == biGetSESR_PAR(eCh) )
    {
        vClrSESR_PAR(eCh);
    }
}


/****************************************************************************/
void vESEI_ClearStatusAll(esei_ch_e eCh)
{
    vSetSESR(eCh, 0xFFFFFFFFU);
}


/****************************************************************************/
int32_t i32ESEI_IsLoopElapsed(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_LOOP_NOELPSD == biGetSESR_SEILC(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_IsIRQActTx(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_IRQ_NONE == biGetSESR_TBSI(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_IsIRQActRx(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_IRQ_NONE == biGetSESR_RBSI(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_IsTxFormatErr(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_NOERR == biGetSESR_SETF(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
void vESEI_ClearTxFormatErr(esei_ch_e eCh)
{
    if( (uint32_t)ESEI_ERROR == biGetSESR_SETF(eCh) )
    {
        vClrSESR_SETF(eCh);
    }
}


/****************************************************************************/
int32_t i32ESEI_IsIdle(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_ACTIVE == biGetSESR_SIDLE(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_IsUnderflowErr(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_NOERR == biGetSESR_SEUE(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
void vESEI_ClearUnderFlowErr(esei_ch_e eCh)
{
    if( (uint32_t)ESEI_ERROR == biGetSESR_SEUE(eCh) )
    {
        vClrSESR_SEUE(eCh);
    }
}


/****************************************************************************/
int32_t i32ESEI_IsOverflowErr(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_NOERR == biGetSESR_SEOE(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
void vESEI_ClearOverFlowErr(esei_ch_e eCh)
{
    if( (uint32_t)ESEI_ERROR == biGetSESR_SEOE(eCh) )
    {
        vClrSESR_SEOE(eCh);
    }
}


/****************************************************************************/
int32_t i32ESEI_IsIFCntrRunning(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_CNT_STOPPED == biGetSESR_IFSD(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_IsReadyBuffTx(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_NOT_READY == biGetSESR_STRDY(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_IsReadyBuffRx(esei_ch_e eCh)
{
    int32_t i32Res = C_TRUE;

    if( (uint32_t)ESEI_NOT_READY == biGetSESR_SRRDY(eCh) )
    {
        i32Res = C_FALSE;
    }

    return i32Res;
}


/****************************************************************************/
void vESEI_LoopEnable(esei_ch_e eCh, esei_en_e eEnable)
{
    vSetSELCR_SLTB(eCh, (uint8_t)eEnable);
}


/****************************************************************************/
void vESEI_BlockLoop(esei_ch_e eCh, esei_slb_e eBlock)
{
    vSetSELCR_SLB(eCh, (uint8_t)eBlock);
}


/****************************************************************************/
int32_t i32ESEI_SetIrqLevelTx(esei_ch_e eCh, uint8_t u8Level)
{
    int32_t i32Res = C_SUCCESS;

    if( u8Level < (uint8_t)ESEI_TXFIFO_DEPTH)
    {
        vSetSEILR_TXIFL(eCh, u8Level);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_SetIrqLevelRx(esei_ch_e eCh, uint8_t u8Level)
{
    int32_t i32Res = C_SUCCESS;

    if( u8Level < (uint8_t)ESEI_RXFIFO_DEPTH )
    {
        vSetSEILR_RXIFL(eCh, u8Level);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
uint8_t u8ESEI_GetLevelTx(esei_ch_e eCh)
{
    return (uint8_t)biGetSEFLR_STBFL(eCh);
}


/****************************************************************************/
uint8_t u8ESEI_GetLevelRx(esei_ch_e eCh)
{
    return (uint8_t)biGetSEFLR_SRBFL(eCh);
}


/****************************************************************************/
int32_t i32ESEI_WriteFrameSingle(esei_ch_e eCh, uint16_t u16Data)
{
    int32_t i32Res = C_SUCCESS;

    if( (uint32_t) ESEI_READY == biGetSESR_STRDY(eCh) )
    {
        vSetSEDR_DR(eCh, u16Data);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_ReadFrameSingle(esei_ch_e eCh, uint16_t* pu16Data)
{
    int32_t i32Res = C_SUCCESS;

    if( (uint32_t) ESEI_READY == biGetSESR_SRRDY(eCh) )
    {
        *pu16Data = biGetSEDR_DR(eCh);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_ReadFrameUni(esei_ch_e eCh, uint16_t* pu16Data)
{
    int32_t i32Res = C_SUCCESS;

    if( (uint32_t) ESEI_READY == biGetSESR_SRRDY(eCh) )
    {
        *pu16Data = biGetSERSR_RS(eCh);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_WriteFrame(esei_ch_e eCh, esei_scid_e eCs, esei_en_e eToggleEn,
                           esei_ssz_e eFrameSize, uint16_t u16Data)
{
    int32_t i32Res = C_SUCCESS;
    uint32_t u32Buff;

    if( ((uint32_t) ESEI_READY == biGetSESR_STRDY(eCh)) )
    {
        /* Word-access only allowed */
        u32Buff = ((0x1U & (uint32_t)eToggleEn)) << 24;
        u32Buff |= ((0x7U & (uint32_t)eCs)) << 21;
        u32Buff |= ((0x1fU & (uint32_t)eFrameSize)) << 16;
        u32Buff |= ((0xffffU & u16Data));

        /* Write to Data Extended Register */
        vSetSEDER_W(eCh, u32Buff);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_ReadFrame(esei_ch_e eCh, esei_scid_e* peSlaveId,
                          esei_pr_e* peParityRep, uint8_t* pu8FrameSize,
                          uint16_t* pu16Data)
{
    int32_t i32Res = C_SUCCESS;
    uint32_t u32Buff;

    if( (uint32_t) ESEI_READY == biGetSESR_SRRDY(eCh) )
    {
        /* Read Data Extended Register in one word access */
        u32Buff = u32GetSEDER_R(eCh);
        *pu16Data = (uint16_t)(u32Buff & 0xFFFFU);
        *pu8FrameSize = (uint8_t)((u32Buff >> 16) & 0x1FU);
        *peSlaveId = (esei_scid_e)((u32Buff >> 21U) & 0x7U);
        *peParityRep = (esei_pr_e)((u32Buff >> 31) & 0x1U);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_ReadWriteFrame(esei_ch_e eCh, esei_dSEntry_st stSend,
                               esei_dREntry_st* pstRecv, esei_en_e eToggleEn)
{
    int32_t i32Res = C_SUCCESS;
    uint32_t u32Buff;
    uint32_t u32TimCnt =0;
    esei_rdy_e eReady;
    esei_ssz_e eTsize;

    eReady = (esei_rdy_e) biGetSESR_STRDY(eCh);
    eTsize = (esei_ssz_e) biGetSECR1_SSZ(eCh);
    
    /* Check whether TX FIFO is ready */
    if( (ESEI_READY == eReady) && (ESEI_TXSIZE_SFL == eTsize) )
    {
        /* Write to Data Extended Register */
        u32Buff =  ((uint32_t)(0x1U & (uint32_t)(eToggleEn))) << 24;
        u32Buff |= ((uint32_t)(0x7U & (uint32_t)(stSend.eSlaveId))) << 21;
        u32Buff |=  ((uint32_t)(0x1FU & (uint32_t)(stSend.eFrameSize))) << 16;
        u32Buff |=  ((uint32_t)(0xFFFFU & (uint32_t)stSend.u16Data));
        vSetSEDER_W(eCh, u32Buff);

        /* Wait for RX buffer ready */
        while( (biGetSESR_SRRDY(eCh) != (uint32_t)ESEI_READY) && (u32TimCnt < (uint32_t)ESEI_RX_RDY_TIMEOUT) )
        {
            u32TimCnt++;
        }

        /* Check for timeout */
        if( u32TimCnt < (uint32_t)ESEI_RX_RDY_TIMEOUT )
        {
            /* Read from Data Extended Register */
            u32Buff = u32GetSEDER_R(eCh);
            pstRecv->u16Data = (uint16_t)(u32Buff & 0xFFFFU);
            pstRecv->eFrameSize = (esei_ssz_e)((u32Buff >> 16) & 0x1FU);
            pstRecv->eSlaveId = (esei_scid_e)((u32Buff >> 21) & 0x7U);
            pstRecv->eParityErr = (esei_pr_e)((u32Buff >> 31) & 0x1U);
        }
        else
        {
            i32Res = C_FAILED;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32ESEI_ReadWriteData(esei_ch_e eCh, const esei_dSEntry_st* pstSendData,
                              esei_dREntry_st* pstRecvData, uint32_t u32Cnt,
                              esei_en_e eToggleEn)
{
    int32_t i32FrmCnt = 0;
    uint32_t u32TimOutCnt = 0;
    int32_t i32Res;


    while((((uint32_t)i32FrmCnt) < u32Cnt) && (u32TimOutCnt < (uint32_t)ESEI_TX_RDY_TIMEOUT))
    {
        /* Transfer (read/write) one frame */
        i32Res =  i32ESEI_ReadWriteFrame(eCh, pstSendData[i32FrmCnt],
                                         (esei_dREntry_st*)&pstRecvData[i32FrmCnt], eToggleEn);
        if( C_SUCCESS == i32Res )
        {
            /* Increment frame counter */
            i32FrmCnt++;         
            /* Reset timeout counter */
            u32TimOutCnt = 0;    
        }
        else
        {
            /* Check whether TX buffer is full */
            if( C_FALSE == i32ESEI_IsReadyBuffTx(eCh) )
            {
                /* No error - increment timeout counter */
                u32TimOutCnt++;
            }
            else
            {
                /* Error occured */
                break;
            }
        }
    }

    return i32FrmCnt;
}

/****************************************************************************/
/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */
/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**
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
** | RULE   : 1858 /17.4  - subscript operator may only be applied to objects 
** |                        declared as an array type
** | CONS.  : allow
** | REASON : to handle array of data by usage of pointer 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1866 /10.1  -  implicit conversion from underlying type, "type",
** |                         to underlying type, "type", changes signedness
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1867 /10.1  -  implicit conversion from underlying type, "type",
** |                         to underlying type, "type", changes signedness
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1879 /10.3  -    cast of complex integer expression with underlying
** |                           type "type" to same width type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as macros in io header file
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1880 /10.3  -    cast of complex integer expression with underlying
** |                           type "type" to same width type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as macros in io header file
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/



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

