/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TIMER_CMPLX low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_CMPLX
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.7 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "timer_cmplx.h"                    /* Timer cmplx LLDD definitions */
#include "timer_cmplx_io.h"                 /* 16-bit Complex timer registers, bits and access macros defintion */

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_TIMER_CMPLX_C_REVISION     "$Revision: 1.7 $"
#define LLDD_TIMER_CMPLX_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_TIMER_CMPLX_C_REVISION[]    = LLDD_TIMER_CMPLX_C_REVISION;
static uint8_t au8LLDD_TIMER_CMPLX_C_TAG[]         = LLDD_TIMER_CMPLX_C_TAG;
static uint8_t au8LLDD_TIMER_CMPLX_H_REVISION[]    = LLDD_TIMER_CMPLX_H_REVISION;
static uint8_t au8LLDD_TIMER_CMPLX_H_TAG[]         = LLDD_TIMER_CMPLX_H_TAG;
static uint8_t au8LLDD_TIMER_CMPLX_IO_H_REVISION[] = LLDD_TIMER_CMPLX_IO_H_REVISION;
static uint8_t au8LLDD_TIMER_CMPLX_IO_H_TAG[]      = LLDD_TIMER_CMPLX_IO_H_TAG;

/*********************************************/

/**********************************************
*        Exported function definition         *
**********************************************/

void vTIMER_CMPLX_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                             uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                             uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_TIMER_CMPLX_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_TIMER_CMPLX_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_TIMER_CMPLX_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_TIMER_CMPLX_H_TAG[0];
   *pau8IORevision     = &au8LLDD_TIMER_CMPLX_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_TIMER_CMPLX_IO_H_TAG[0];
}

/****************************************************************************/


void vTIMER_CMPLX_Config(timer_cmplx_ch_e eCh, timer_cmplx_genCfg_st stCfg)
{
    vSetTBMOD_CLK(eCh, stCfg.eClkSource);
    vSetTBMOD_CLE(eCh, stCfg.eCountCtrl);
    vSetTBRUN_DBE(eCh, stCfg.eDblBuffEn);
    vSetTBRUN_SYNC(eCh, stCfg.eSyncRstEn);
    vSetTBRUN_IDL(eCh, stCfg.eIdle);
    vSetTBRUN_PRUN(eCh, stCfg.ePresclStart);
    vSetTBRUN_OFI(eCh, stCfg.eOvrflwIrqEn);
    vSetTBRUN_TRUN(eCh, stCfg.eTimerStart);
}

/****************************************************************************/


void vTIMER_CMPLX_SetCountCtrl(timer_cmplx_ch_e eCh, timer_cmplx_cle_e eCountCtrl)
{
    vSetTBMOD_CLE(eCh, eCountCtrl);
}

/****************************************************************************/


void vTIMER_CMPLX_SetCaptureTiming(timer_cmplx_ch_e eCh, timer_cmplx_cpm_e eCapTiming)
{
    vSetTBMOD_CPM(eCh, eCapTiming);
}

/****************************************************************************/


void vTIMER_CMPLX_FlipFlopConfig(timer_cmplx_ch_e eCh, timer_cmplx_ffCfg_st stFfCfg)
{
    vSetTBFF_INVL1(eCh, stFfCfg.eInvl1);
    vSetTBFF_INVL0(eCh, stFfCfg.eInvl0);
    vSetTBFF_INVC1(eCh, stFfCfg.eInvc1);
    vSetTBFF_INVC0(eCh, stFfCfg.eInvc0);
    vSetTBFF_MOD(eCh, stFfCfg.eFfMode);
}

/****************************************************************************/


void vTIMER_CMPLX_SetStateIdle(timer_cmplx_ch_e eCh)
{
    vSetTBRUN_IDL(eCh, TIMER_CMPLX_IDLE);
}

/****************************************************************************/


void vTIMER_CMPLX_SetStateNormal(timer_cmplx_ch_e eCh)
{
    vSetTBRUN_IDL(eCh, TIMER_CMPLX_NORMAL);
}

/****************************************************************************/


void vTIMER_CMPLX_Start(timer_cmplx_ch_e eCh)
{
    vSetTBRUN_TRUN(eCh, TIMER_CMPLX_START);
}

/****************************************************************************/


void vTIMER_CMPLX_Stop(timer_cmplx_ch_e eCh)
{
    vSetTBRUN_TRUN(eCh, TIMER_CMPLX_STOP);
}

/****************************************************************************/


void vTIMER_CMPLX_SetOvflowIrqEnable(timer_cmplx_ch_e eCh, timer_cmplx_en_e eIrqEn)
{
    vSetTBRUN_OFI(eCh, eIrqEn);
}

/****************************************************************************/


void vTIMER_CMPLX_SetSyncRstEnable(timer_cmplx_ch_e eCh, timer_cmplx_en_e eSyncRstEn)
{
    vSetTBRUN_SYNC(eCh, eSyncRstEn);
}

/****************************************************************************/


void vTIMER_CMPLX_StartPrescaler(timer_cmplx_ch_e eCh)
{
    vSetTBRUN_PRUN(eCh, TIMER_CMPLX_START);
}

/****************************************************************************/


void vTIMER_CMPLX_StopPrescaler(timer_cmplx_ch_e eCh)
{
    vSetTBRUN_PRUN(eCh, TIMER_CMPLX_STOP);
}

/****************************************************************************/


void vTIMER_CMPLX_SetDblBuffEnable(timer_cmplx_ch_e eCh, timer_cmplx_en_e eBuffEn)
{
    vSetTBRUN_DBE(eCh, eBuffEn);
}

/****************************************************************************/


void vTIMER_CMPLX_LatchCounter(timer_cmplx_ch_e eCh)
{
    vSetTBMOD_CP0(eCh, TIMER_CMPLX_LATCH);
    vSetTBMOD_CP0(eCh, TIMER_CMPLX_NO_LATCH);
}

/****************************************************************************/


void vTIMER_CMPLX_SetFfInvl1(timer_cmplx_ch_e eCh, timer_cmplx_ffinv_e eInvert)
{
    vSetTBFF_INVL1(eCh, eInvert);
}

/****************************************************************************/


void vTIMER_CMPLX_SetFfInvl0(timer_cmplx_ch_e eCh, timer_cmplx_ffinv_e eInvert)
{
    vSetTBFF_INVL0(eCh, eInvert);
}

/****************************************************************************/


void vTIMER_CMPLX_SetFfInvc1(timer_cmplx_ch_e eCh, timer_cmplx_ffinv_e eInvert)
{
    vSetTBFF_INVC1(eCh, eInvert);
}

/****************************************************************************/


void vTIMER_CMPLX_SetFfInvc0(timer_cmplx_ch_e eCh, timer_cmplx_ffinv_e eInvert)
{
    vSetTBFF_INVC0(eCh, eInvert);
}

/****************************************************************************/


void vTIMER_CMPLX_SetCompareVal0(timer_cmplx_ch_e eCh, uint16_t u16CompVal)
{
    vSetTB0REG_CMP0(eCh, u16CompVal);
}

/****************************************************************************/


uint16_t u16TIMER_CMPLX_GetCompareVal0(timer_cmplx_ch_e eCh)
{
    return (uint16_t) biGetTB0REG_CMP0(eCh);
}

/****************************************************************************/


void vTIMER_CMPLX_SetCompareVal1(timer_cmplx_ch_e eCh, uint16_t u16CompVal)
{
    vSetTB1REG_CMP1(eCh, u16CompVal);
}

/****************************************************************************/


uint16_t u16TIMER_CMPLX_GetCompareVal1(timer_cmplx_ch_e eCh)
{
    return (uint16_t) biGetTB1REG_CMP1(eCh);
}

/****************************************************************************/


uint16_t u16TIMER_CMPLX_GetCapturedVal0(timer_cmplx_ch_e eCh)
{
    return (uint16_t) biGetTB0CP0_CP0(eCh);
}

/****************************************************************************/


uint16_t u16TIMER_CMPLX_GetCapturedVal1(timer_cmplx_ch_e eCh)
{
    return (uint16_t) biGetTB0CP1_CP1(eCh);
}

/****************************************************************************/


uint16_t u16TIMER_CMPLX_GetCounterVal(timer_cmplx_ch_e eCh)
{
    return (uint16_t) biGetTB0CNT_CNT(eCh);
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

