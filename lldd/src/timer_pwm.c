/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TIMER_PWM low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_PWM
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
#include "timer_pwm_io.h"                  /* PWM timer registers, bits and access macros defintion */
#include "timer_pwm.h"                     /* Timer LLDD definitions */

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_TIMER_PWM_C_REVISION     "$Revision: 1.8 $"
#define LLDD_TIMER_PWM_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_TIMER_PWM_C_REVISION[]    = LLDD_TIMER_PWM_C_REVISION;
static uint8_t au8LLDD_TIMER_PWM_C_TAG[]         = LLDD_TIMER_PWM_C_TAG;
static uint8_t au8LLDD_TIMER_PWM_H_REVISION[]    = LLDD_TIMER_PWM_H_REVISION;
static uint8_t au8LLDD_TIMER_PWM_H_TAG[]         = LLDD_TIMER_PWM_H_TAG;
static uint8_t au8LLDD_TIMER_PWM_IO_H_REVISION[] = LLDD_TIMER_PWM_IO_H_REVISION;
static uint8_t au8LLDD_TIMER_PWM_IO_H_TAG[]      = LLDD_TIMER_PWM_IO_H_TAG;

/*********************************************/

/* indicator if PWM is running */
static uint8_t au8PWMRunning[24] =
{
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

/*********************************************/


/**********************************************
*        Exported function definition         *
**********************************************/

void vTIMER_PWM_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                           uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                           uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_TIMER_PWM_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_TIMER_PWM_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_TIMER_PWM_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_TIMER_PWM_H_TAG[0];
   *pau8IORevision     = &au8LLDD_TIMER_PWM_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_TIMER_PWM_IO_H_TAG[0];
}

/****************************************************************************/


bool_t boTIMER_PWM_Config(timer_pwm_cntrl_e eCntrl, timer_pwm_Cfg_st stCfg)
{
    bool_t boResult = C_FALSE;    

    /* Standard PWM timers */
    vSetPWMCR_RC(eCntrl, stCfg.eRst);       
    vSetPWMCR_VED(eCntrl, stCfg.eVSyncEd);
    vSetPWMCR_HED(eCntrl, stCfg.eHsyncEd);
    vSetPWMCR_GDC(eCntrl, stCfg.eClkSrc);
    vSetPWMCR_SCLK(eCntrl, stCfg.ePrescalClk);
    vSetPWMCR_IE(eCntrl, stCfg.eIrqEn);
    vSetPWMCR_DB(eCntrl, stCfg.eDblBuffEn);
    vSetPWMCR_OL(eCntrl, stCfg.eOutLevel);
    boResult = C_TRUE;

    /* Configuration result */
    return boResult;
}

/****************************************************************************/


void vTIMER_PWM_SetPeriod(timer_pwm_cntrl_e eCntrl, uint16_t u16Period)
{
   vSetPWMPDR_PWMPDR(eCntrl, u16Period);
}

/****************************************************************************/


void vTIMER_PWM_SetDuty(timer_pwm_cntrl_e eCntrl, uint16_t u16Duty)
{
   vSetPWMDDR_PWMDDR(eCntrl, u16Duty);
}

/****************************************************************************/


uint16_t u16TIMER_PWM_GetDuty(timer_pwm_cntrl_e eCntrl)
{
    uint16_t u16Res;

    u16Res = u16GetPWMDDR(eCntrl);

    return u16Res;
}

/****************************************************************************/


int32_t i32TIMER_PWM_SetWaveform(timer_pwm_cntrl_e eCntrl, uint16_t u16Period, uint16_t u16Duty, timer_pwm_ol_e eOutLevel)
{
    int32_t i32Res;
    uint16_t u16DutyVal;
    timer_pwm_en_e eCurStat = TIMER_PWM_DISABLE;
    timer_pwm_en_e eBuffType = TIMER_PWM_DISABLE;

    eCurStat = (timer_pwm_en_e)biGetPWMCR_TRUN(eCntrl);
    eBuffType = (timer_pwm_en_e)biGetPWMCR_DB(eCntrl);

    /* check if change is allowed */
    if( ( TIMER_PWM_ENABLE != eCurStat ) || ( TIMER_PWM_DISABLE != eBuffType ) )
    {
        if(u16Duty <= 100)
        {
            if ((u16Duty != 0) && (u16Duty != 100))
            {
                /* Duty-counter value */
                u16DutyVal = (uint16_t)((u16Period * u16Duty)/100);

                vSetPWMPDR_PWMPDR(eCntrl, u16Period);
                vSetPWMDDR_PWMDDR(eCntrl, u16DutyVal);

                /* enable timer if coming from 0% and 100% */
                if (au8PWMRunning[eCntrl] == 1)
                {
                    vSetPWMCR_TRUN(eCntrl, TIMER_PWM_ENABLE);
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
                    vSetPWMCR_TRUN(eCntrl, TIMER_PWM_DISABLE);
                    vSetPWMCR_OL(eCntrl, eOutLevel);

		    /* Achieved Duty-cycle */
                    i32Res = 0;
                }
                else
                {
                    /* 100% */
                    vSetPWMCR_TRUN(eCntrl, TIMER_PWM_DISABLE);
                    vSetPWMCR_OL(eCntrl, ~eOutLevel);

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


void vTIMER_PWM_SetPrescaler(timer_pwm_cntrl_e eCntrl, timer_pwm_sclk_e ePrescal)
{
    vSetPWMCR_SCLK(eCntrl, ePrescal);
}

/****************************************************************************/


void vTIMER_PWM_SetRstCondition(timer_pwm_cntrl_e eCntrl, timer_pwm_rc_e eRst)
{
    vSetPWMCR_RC(eCntrl, eRst);
}

/****************************************************************************/


void vTIMER_PWM_SetDetEdgeVsync(timer_pwm_cntrl_e eCntrl, timer_pwm_ved_e eEdge)
{
    vSetPWMCR_VED(eCntrl, eEdge);
}

/****************************************************************************/


void vTIMER_PWM_SetDetEdgeHSync(timer_pwm_cntrl_e eCntrl, timer_pwm_ved_e eEdge)
{
    vSetPWMCR_HED(eCntrl, eEdge);
}

/****************************************************************************/


void vTIMER_PWM_IrqEnable(timer_pwm_cntrl_e eCntrl, timer_pwm_en_e eEnable)
{
    vSetPWMCR_IE(eCntrl, eEnable);
}

/****************************************************************************/


void vTIMER_PWM_DBuffEnable(timer_pwm_cntrl_e eCntrl, timer_pwm_en_e eEnable)
{
    vSetPWMCR_DB(eCntrl, eEnable);
}

/****************************************************************************/


int32_t i32TIMER_PWM_SetOutLevel(timer_pwm_cntrl_e eCntrl, timer_pwm_ol_e eLevel)
{
    int32_t i32Res = C_SUCCESS;
    timer_pwm_en_e eCurStat = TIMER_PWM_DISABLE;

    eCurStat = (timer_pwm_en_e)biGetPWMCR_TRUN(eCntrl);

    /* Change allowed only when Timer is not Running */
    if( TIMER_PWM_ENABLE != eCurStat )
    {
        /* Change Output Level */
        vSetPWMCR_OL(eCntrl, eLevel);
    }
    else
    {
        /* No change allowed (PWM Timer running) */
        i32Res = C_FAILED;
    }

    return i32Res;
}

/****************************************************************************/


void vTIMER_PWM_SetClkSource(timer_pwm_cntrl_e eCntrl, timer_pwm_gdc_e eSource)
{
    vSetPWMCR_GDC(eCntrl, eSource);
}

/****************************************************************************/



void vTIMER_PWM_Enable(timer_pwm_cntrl_e eCntrl, timer_pwm_en_e eEnable)
{
    vSetPWMCR_TRUN(eCntrl, eEnable);
    au8PWMRunning[eCntrl] = (uint8_t)eEnable;
}

/****************************************************************************/


uint16_t u16TIMER_PWM_GetCountVal(timer_pwm_cntrl_e eCntrl)
{
    return (uint16_t) biGetPWMCNT_PWMCNT(eCntrl);
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

