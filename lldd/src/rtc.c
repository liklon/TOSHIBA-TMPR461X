/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : RTC Low-level source file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      :
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "rtc.h"
#include "rtc_io.h"
/*********************************************/

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error (used for result of i/o header amcros) */
  #pragma ghs nowarning 1877  /* Rule 11-3 [A] : cast of 0 from type "type" to type "type" not allowed */
#endif

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_RTC_C_REVISION     "$Revision: 1.10 $"
#define LLDD_RTC_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_RTC_C_REVISION[]        = LLDD_RTC_C_REVISION;
static uint8_t au8LLDD_RTC_C_TAG[]             = LLDD_RTC_C_TAG;
static uint8_t au8LLDD_RTC_H_REVISION[]        = LLDD_RTC_H_REVISION;
static uint8_t au8LLDD_RTC_H_TAG[]             = LLDD_RTC_H_TAG;
static uint8_t au8LLDD_RTC_IO_H_REVISION[]     = LLDD_RTC_IO_H_REVISION;
static uint8_t au8LLDD_RTC_IO_H_TAG[]          = LLDD_RTC_IO_H_TAG;

/*********************************************/

/**********************************************
*             Function definition             *
*********************************************/

/****************************************************************************/
void vRTC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
    *pau8ModuleRevision = &au8LLDD_RTC_C_REVISION[0];
    *pau8ModuleTag      = &au8LLDD_RTC_C_TAG[0];
    *pau8HeaderRevision = &au8LLDD_RTC_H_REVISION[0];
    *pau8HeaderTag      = &au8LLDD_RTC_H_TAG[0];
    *pau8IORevision     = &au8LLDD_RTC_IO_H_REVISION[0];
    *pau8IOTag          = &au8LLDD_RTC_IO_H_TAG[0];    
}

/****************************************************************************/
void vRTC_SelectPage(rtc_page_e eSelectPage)
{
    vSetRTCPAGER_PAGE((uint8_t)eSelectPage);
}

/****************************************************************************/
void vRTC_EnableAlarm(rtc_enable_e eEn)
{
    vSetRTCPAGER_ENAALM((uint8_t)eEn);
}

/****************************************************************************/
void vRTC_EnableClock(rtc_enable_e eEn)
{
    vSetRTCPAGER_ENATMR((uint8_t)eEn);
}

/****************************************************************************/
void vRTC_SetAdjust(rtc_adjust_set_e eAdj)
{
    vSetRTCPAGER_ADJUST((uint8_t)eAdj);
}

/****************************************************************************/
void vRTC_EnableInterrupt(rtc_enable_e eEn)
{
    vSetRTCPAGER_INTENA((uint8_t)eEn);
}

/****************************************************************************/
rtc_adjust_status_e eRTC_GetAdjust(void)
{
    rtc_adjust_status_e eResult;
    
    eResult = (rtc_adjust_status_e) biGetRTCPAGER_ADJUST();
    return eResult;
}

/****************************************************************************/
bool_t boRTC_SetTimeAndDate(const rtc_time_date_st *pstTimeAndDate)
{
    bool_t boResult = C_TRUE;
    
    if ( 0x00 != pstTimeAndDate)
    {
        /* Set time: */
        vSetRTCSECR_SEC_DATA(pstTimeAndDate->u8Sec);
        vSetRTCMINR_MIN_DATA(pstTimeAndDate->u8Min);
        vSetRTCHOURR_HOUR_DATA(pstTimeAndDate->u8Hour);

        /* Set date: */
        vSetRTCDAYR_DAY_DATA(pstTimeAndDate->u8DayOfWeek);
        vSetRTCDATER_DATE_DATA(pstTimeAndDate->u8DateOfMonth);
        vSetRTCMONTHR_MON_DATA(pstTimeAndDate->u8Month);
        vSetRTCYEARR_YEAR_DATA(pstTimeAndDate->u8Year);
    }
    else
    {
        boResult = C_FALSE;
    }

    return boResult;
}
/****************************************************************************/
bool_t boRTC_GetTimeAndDate(rtc_time_date_st *pstTimeAndDate)
{
    bool_t boResult = C_TRUE;
    
    if ( 0x00 != pstTimeAndDate)
    {
        /* read time: */
        pstTimeAndDate->u8Sec  = biGetRTCSECR_SEC_DATA();
        pstTimeAndDate->u8Min  = biGetRTCMINR_MIN_DATA();
        pstTimeAndDate->u8Hour = biGetRTCHOURR_HOUR_DATA();

        /* read date: */
        pstTimeAndDate->u8DayOfWeek   = biGetRTCDAYR_DAY_DATA();
        pstTimeAndDate->u8DateOfMonth = biGetRTCDATER_DATE_DATA();
        pstTimeAndDate->u8Month       = biGetRTCMONTHR_MON_DATA();
        pstTimeAndDate->u8Year        = biGetRTCYEARR_YEAR_DATA();
    }
    else
    {
        boResult = C_FALSE;
    }

    return boResult;
}

/****************************************************************************/
bool_t boRTC_SetConfigReset(const rtc_reset_cfg_st* const pResetCfg)
{
    bool_t boResult = C_FALSE;

    if (C_NULL != pResetCfg)
    {
        vSetRTCRESTR_DIS1HZ ( (uint8_t)(pResetCfg->eEn_1HzOpEn) );
        vSetRTCRESTR_DIS2HZ ( (uint8_t)(pResetCfg->eEn_2HzOpEn) );
        vSetRTCRESTR_DIS4HZ ( (uint8_t)(pResetCfg->eEn_4HzOpEn) );
        vSetRTCRESTR_DIS8HZ ( (uint8_t)(pResetCfg->eEn_8HzOpEn) );
        vSetRTCRESTR_DIS16HZ( (uint8_t)(pResetCfg->eEn_16HzOpEn));
        boResult = C_TRUE;
    }
    return boResult;
}

/****************************************************************************/
bool_t boRTC_GetConfigReset(rtc_reset_cfg_st* const pResetCfg)
{
    bool_t boResult = C_FALSE;

    if (C_NULL != pResetCfg)
    {
        pResetCfg->eEn_1HzOpEn  = (rtc_enable_e) biGetRTCRESTR_DIS1HZ();
        pResetCfg->eEn_2HzOpEn  = (rtc_enable_e) biGetRTCRESTR_DIS2HZ();
        pResetCfg->eEn_4HzOpEn  = (rtc_enable_e) biGetRTCRESTR_DIS4HZ();
        pResetCfg->eEn_8HzOpEn  = (rtc_enable_e) biGetRTCRESTR_DIS8HZ();
        pResetCfg->eEn_16HzOpEn = (rtc_enable_e) biGetRTCRESTR_DIS16HZ();
        boResult = C_TRUE;
    }
    return boResult;
}


/****************************************************************************/
void vRTC_ResetTimer(void)
{
    vSetRTCRESTR_RSTTMR((uint8_t)RTC_ENABLE);
}

/****************************************************************************/
void vRTC_ResetAlarm(void)
{
    vSetRTCRESTR_RSTALM((uint8_t)RTC_ENABLE);
}

/****************************************************************************/
void vRTC_SetCalibIntvPeriod(uint8_t u8CalibIntvPeriod)
{
    vSetRTCCALIBCTRL0(u8CalibIntvPeriod);
}

/****************************************************************************/
void vRTC_SetCalibIntvValue(uint8_t u8CalibIntvValue)
{
    vSetRTCCALIBCTRL1_CAL_INTRVL(u8CalibIntvValue);
}

/****************************************************************************/
void vRTC_SetClockSource(rtc_clock_source_e eClkSrc)
{
    vSetRTCCALIBCTRL1_CLK_RTC_SEL((uint8_t)eClkSrc);
}

/****************************************************************************/
void vRTC_EnableCalibration(rtc_enable_e eEn)
{
    vSetRTCCALIBCTRL1_CAL_ENB((uint8_t)eEn);
}
/****************************************************************************/


/****************************************************************************/

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

