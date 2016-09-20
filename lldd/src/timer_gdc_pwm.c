/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TIMER_GDC_PWM low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_GDC_PWM
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.9 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "timer_gdc_pwm_io.h"              /* GDC_PWM timer registers, bits and access macros defintion */
#include "timer_gdc_pwm.h"                     /* Timer LLDD definitions */

/*********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to narrower underlying type, "type", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : implicit conversion of complex expression from underlying type, "type", to underlying type, "type", not allowed */

  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */  
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error (used for result of i/o header amcros) */
#endif 
/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_TIMER_GDC_PWM_C_REVISION     "$Revision: 1.9 $"
#define LLDD_TIMER_GDC_PWM_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_TIMER_GDC_PWM_C_REVISION[]    = LLDD_TIMER_GDC_PWM_C_REVISION;
static uint8_t au8LLDD_TIMER_GDC_PWM_C_TAG[]         = LLDD_TIMER_GDC_PWM_C_TAG;
static uint8_t au8LLDD_TIMER_GDC_PWM_H_REVISION[]    = LLDD_TIMER_GDC_PWM_H_REVISION;
static uint8_t au8LLDD_TIMER_GDC_PWM_H_TAG[]         = LLDD_TIMER_GDC_PWM_H_TAG;
static uint8_t au8LLDD_TIMER_GDC_PWM_IO_H_REVISION[] = LLDD_TIMER_GDC_PWM_IO_H_REVISION;
static uint8_t au8LLDD_TIMER_GDC_PWM_IO_H_TAG[]      = LLDD_TIMER_GDC_PWM_IO_H_TAG;

/*********************************************/

/* indicator if PWM is running */
static uint8_t au8GDCPWMRunning[2] =
{
    0U,
    0U
};

/*********************************************/


/**********************************************
*        Exported function definition         *
**********************************************/

void vTIMER_GDC_PWM_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                               uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                               uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_TIMER_GDC_PWM_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_TIMER_GDC_PWM_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_TIMER_GDC_PWM_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_TIMER_GDC_PWM_H_TAG[0];
   *pau8IORevision     = &au8LLDD_TIMER_GDC_PWM_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_TIMER_GDC_PWM_IO_H_TAG[0];
}

/****************************************************************************/


bool_t boTIMER_GDC_PWM_Config(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_Cfg_st stCfg)
{
    bool_t boResult = C_FALSE;

    /* GDC PWM timers */
    vSetGPWMCR_RC(eCntrl, stCfg.eRst);
    vSetGPWMCR_VED(eCntrl, stCfg.eVSyncEd);
    vSetGPWMCR_HED(eCntrl, stCfg.eHsyncEd);

    /* HSync or Prescaler only */
    if( TIMER_GDC_PWM_DOTCLK != stCfg.eClkSrc )
    {       
        vSetGPWMCR_GDC(eCntrl, stCfg.eClkSrc);
        vSetGPWMCR_TCORE_EN(eCntrl, stCfg.eCoreEn);
        vSetGPWMCR_SCLK(eCntrl, stCfg.ePrescalClk);    
        vSetGPWMCR_IE(eCntrl, stCfg.eIrqEn);
        vSetGPWMCR_DB(eCntrl, stCfg.eDblBuffEn);
        vSetGPWMCR_OL(eCntrl, stCfg.eOutLevel);
        boResult = C_TRUE;        
    }

    /* Configuration result */
    return boResult;
}

/****************************************************************************/


void vTIMER_GDC_PWM_SetPeriod(timer_gdc_pwm_cntrl_e eCntrl, uint16_t u16Period)
{
    vSetGPWMPDR_GPWMPDR(eCntrl, u16Period);
}

/****************************************************************************/


void vTIMER_GDC_PWM_SetDuty(timer_gdc_pwm_cntrl_e eCntrl, uint16_t u16Duty)
{
    vSetGPWMDDR_GPWMDDR(eCntrl, u16Duty);
}

/****************************************************************************/


uint16_t u16TIMER_GDC_PWM_GetDuty(timer_gdc_pwm_cntrl_e eCntrl)
{
    uint16_t u16Res;

    u16Res = u16GetGPWMDDR(eCntrl);            

    return u16Res;
}

/****************************************************************************/


int32_t i32TIMER_GDC_PWM_SetWaveform(timer_gdc_pwm_cntrl_e eCntrl, uint16_t u16Period, uint16_t u16Duty, timer_gdc_pwm_ol_e eOutLevel)
{
    int32_t i32Res;
    uint16_t u16DutyVal;
    timer_gdc_pwm_en_e eCurStat = TIMER_GDC_PWM_DISABLE;
    timer_gdc_pwm_en_e eBuffType = TIMER_GDC_PWM_DISABLE;

    eCurStat = (timer_gdc_pwm_en_e)biGetGPWMCR_TRUN(eCntrl);
    eBuffType = (timer_gdc_pwm_en_e)biGetGPWMCR_DB(eCntrl);

    /* check if change is allowed */
    if( ( TIMER_GDC_PWM_ENABLE != eCurStat ) || ( TIMER_GDC_PWM_DISABLE != eBuffType ) )
    {
        if(u16Duty <= 100)
        {
            if ((u16Duty != 0) && (u16Duty != 100))
            {
                /* Duty-counter value */
                u16DutyVal = (u16Period * u16Duty)/100;

                vSetGPWMPDR_GPWMPDR(eCntrl, u16Period);
                vSetGPWMDDR_GPWMDDR(eCntrl, u16DutyVal);

                /* enable timer if coming from 0% and 100% */
                if (au8GDCPWMRunning[eCntrl] == 1U)
                {
                    vSetGPWMCR_TRUN(eCntrl, TIMER_GDC_PWM_ENABLE);
                }

                /* Achieved Duty-cycle */
                i32Res = (u16DutyVal* 100) / u16Period;
            }
            else
            {
                /* special treatment for 0% and 100% */
                if (u16Duty == 0)
                {
                    /* 0% */
                    vSetGPWMCR_TRUN(eCntrl, TIMER_GDC_PWM_DISABLE);
                    vSetGPWMCR_OL(eCntrl, eOutLevel);

            /* Achieved Duty-cycle */
                    i32Res = 0;
                }
                else
                {
                    /* 100% */
                    vSetGPWMCR_TRUN(eCntrl, TIMER_GDC_PWM_DISABLE);
                    if (TIMER_GDC_PWM_LEVEL_HI == eOutLevel)
                    {
                        vSetGPWMCR_OL(eCntrl, TIMER_GDC_PWM_LEVEL_LO);
                    }
                    else
                    {
                        vSetGPWMCR_OL(eCntrl, TIMER_GDC_PWM_LEVEL_HI);
                    }

            /* Achieved Duty-cycle */
                    i32Res = 100;
                }
            }
        }
        else
        {
            /* Duty Cycle parameter out of range */
            i32Res = 0xff;
        }
    }
    else
    {
        /* PWM Timer running, no change allowed */
        i32Res = 0xff;
    }

    return i32Res;
}

/****************************************************************************/


void vTIMER_GDC_PWM_SetPrescaler(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_sclk_e ePrescal)
{
    vSetGPWMCR_SCLK(eCntrl, ePrescal);
}

/****************************************************************************/


void vTIMER_GDC_PWM_SetRstCondition(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_rc_e eRst)
{
    vSetGPWMCR_RC(eCntrl, eRst);
}

/****************************************************************************/


void vTIMER_GDC_PWM_SetDetEdgeVsync(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_ved_e eEdge)
{
    vSetGPWMCR_VED(eCntrl, eEdge);
}

/****************************************************************************/


void vTIMER_GDC_PWM_SetDetEdgeHSync(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_ved_e eEdge)
{
    vSetGPWMCR_HED(eCntrl, eEdge);
}

/****************************************************************************/


void vTIMER_GDC_PWM_IrqEnable(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_en_e eEnable)
{
    vSetGPWMCR_IE(eCntrl, eEnable);
}

/****************************************************************************/


void vTIMER_GDC_PWM_DBuffEnable(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_en_e eEnable)
{
    vSetGPWMCR_DB(eCntrl, eEnable);
}

/****************************************************************************/


int32_t i32TIMER_GDC_PWM_SetOutLevel(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_ol_e eLevel)
{
    int32_t i32Res = C_SUCCESS;
    timer_gdc_pwm_en_e eCurStat = TIMER_GDC_PWM_DISABLE;

    eCurStat = (timer_gdc_pwm_en_e)biGetGPWMCR_TRUN(eCntrl);

    /* Change allowed only when Timer is not Running */
    if( TIMER_GDC_PWM_ENABLE != eCurStat )
    {
        /* Change Output Level */
        vSetGPWMCR_OL(eCntrl, eLevel);
    }
    else
    {
        /* No change allowed (PWM Timer running) */
        i32Res = C_FAILED;
    }

    return i32Res;
}

/****************************************************************************/


void vTIMER_GDC_PWM_SetClkSource(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_gdc_e eSource)
{
    vSetGPWMCR_GDC(eCntrl, eSource);
}

/****************************************************************************/


void vTIMER_GDC_PWM_GDCCoreEnable(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_tcore_e eEnable)
{
    vSetGPWMCR_TCORE_EN(eCntrl, eEnable);
}

/****************************************************************************/


void vTIMER_GDC_PWM_Enable(timer_gdc_pwm_cntrl_e eCntrl, timer_gdc_pwm_en_e eEnable)
{
    vSetGPWMCR_TRUN(eCntrl, eEnable);
    au8GDCPWMRunning[eCntrl] = (uint8_t)eEnable;
}

/****************************************************************************/


uint16_t u16TIMER_GDC_PWM_GetCountVal(timer_gdc_pwm_cntrl_e eCntrl)
{
    return (uint16_t) biGetGPWMCNT_GPWMCNT(eCntrl);
}

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
** | RULE   : 1864 /10.1  - implicit conversion from underlying type, "type", 
** |                        to narrower underlying type, "type", not allowed
** | CONS.  : allow
** | REASON : to use macros from i/o header files 
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

