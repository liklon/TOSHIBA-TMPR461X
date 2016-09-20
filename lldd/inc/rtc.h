/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : RTC Low-level header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : RTC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.11 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef RTC_LLDD_H
#define RTC_LLDD_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"


/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_RTC_H_REVISION     "$Revision: 1.11 $"
#define LLDD_RTC_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*                    Macros                   *
**********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
typedef enum tag_rtc_page_e
{
  RTC_PAGE_0 = 0,  /* page 0 */
  RTC_PAGE_1 = 1   /* page 1 */
} rtc_page_e;

typedef enum tag_rtc_enable_e
{
  RTC_DISABLE = 0,  /* disable */
  RTC_ENABLE  = 1   /* enable  */
} rtc_enable_e;

typedef enum tag_rtc_adjust_set_e
{
  RTC_ADJUST_DONTCARE = 0,   /* Don’t care */
  RTC_ADJUST_REQUEST  = 1    /* Sets ADJUST request */
} rtc_adjust_set_e;

typedef enum tag_rtc_adjust_status_e
{
  RTC_ADJSTAT_NO_REQUESTED = 0,  /* No ADJUST request */
  RTC_ADJSTAT_REQUESTED   = 1     /* ADJUST requested */
} rtc_adjust_status_e;

typedef enum tag_rtc_alarm_reset_e
{
  RTC_ALARM_RESET_DONTCARE = 0,  /* Don’t care */
  RTC_ALARM_RESET_INIT   = 1     /* Initializes alarm registers (Minute Column, Hour Column,
                                    Day Column and Day of the week Column) as follows.
                                    Minute: 00, Hour: 00, Day: 01, Day of the week: Sunday */
} rtc_alarm_reset_e;

typedef enum tag_rtc_timer_reset_e
{
  RTC_TIMER_RESET_DONTCARE = 0,  /* Don’t care */
  RTC_TIMER_RESET_ACTIVE   = 1   /* Resets sec counter */
} rtc_timer_reset_e;

typedef enum tag_rtc_config_set_e
{
  RTC_CFG_DONTCARE      = 0,  /* Don’t care   */
  RTC_CFG_DATA_UPDATE   = 1   /* Data Update  */
} rtc_config_set_e;

typedef enum tag_rtc_config_status_e
{
  RTC_CFGSTAT_READY      = 0,  /* HW is ready */
  RTC_CFGSTAT_BUSY       = 1   /* HW is busy  */
} rtc_config_status_e;


typedef enum tag_rtc_init_staus_e
{
  RTC_INITSTAT_NOT_INITIAL     = 0,  /* Not initial status (Never Power down) */
  RTC_INITSTAT_INITIAL         = 1   /* Initial status (Power On Status)      */
} rtc_init_staus_e;

typedef enum tag_rtc_clock_source_e
{
  RTC_CLK_32KHZ      = 0x0,    /* selects 32Khz as clock source, */
  RTC_CLK_10MHZ      = 0x1,    /* selects 10Mhz as clock source, */
  RTC_CLK_100KHZ     = 0x2     /* selects 100Khz as clock source */
} rtc_clock_source_e;

/**********************************************
*                 Structures                  *
**********************************************/
/* RTC time & date structure */
typedef struct tag_rtc_reset_cfg_st
{
    rtc_enable_e   eEn_1HzOpEn;
    rtc_enable_e   eEn_2HzOpEn;
    rtc_enable_e   eEn_4HzOpEn;
    rtc_enable_e   eEn_8HzOpEn;
    rtc_enable_e   eEn_16HzOpEn;
} rtc_reset_cfg_st;

/* RTC time & date structure */
typedef struct tag_rtc_time_date_st
{
    uint8_t  u8Sec;          /* 6 bits */
    uint8_t  u8Min;          /* 7 bits */
    uint8_t  u8Hour;         /* 6 bits */
    
    uint8_t  u8DayOfWeek;    /* 3 bits */
    uint8_t  u8DateOfMonth;  /* 6 bits */
    uint8_t  u8Month;        /* 8 bits */
    uint8_t  u8Year;         /* 8 bits */
} rtc_time_date_st;


/*********************************************/

/**********************************************
*            Forward declarations             *
**********************************************/

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/


/****************************************************************************
 *
 * Function:      vRTC_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8IORevision     - pointer to IO header revision string
 *                pau8IOTag          - pointer to IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vRTC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);


/****************************************************************************
 *
 * Function:      vRTC_SelectPage
 *
 * Purpose:       Select RTC page
 *
 * Inputs:        eSelectPage: To be selected page
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_SelectPage(rtc_page_e eSelectPage);


/****************************************************************************
 *
 * Function:      vRTC_EnableAlarm
 *
 * Purpose:       Alarm enable setting
 *
 * Inputs:        eEn: enable/disable Alarm
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_EnableAlarm(rtc_enable_e eEn);


/****************************************************************************
 *
 * Function:      vRTC_EnableClock
 *
 * Purpose:       Clock enable settings
 *
 * Inputs:        eEn: enable/disable clock
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_EnableClock(rtc_enable_e eEn);


/****************************************************************************
 *
 * Function:      vRTC_SetAdjust
 *
 * Purpose:       Adjust setting
 *
 * Inputs:        eAdj: setting
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_SetAdjust(rtc_adjust_set_e eAdj);


/****************************************************************************
 *
 * Function:      vRTC_EnableInterrupt
 *
 * Purpose:       Interrupt enable setting
 *
 * Inputs:        eEn: enable interrupt
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_EnableInterrupt(rtc_enable_e eEn);


/****************************************************************************
 *
 * Function:      eRTC_GetAdjust
 *
 * Purpose:       Read Adjust setting
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: adjust setting
 *
 * Limitations:
 *
 ***************************************************************************/
rtc_adjust_status_e eRTC_GetAdjust(void);


/****************************************************************************
 *
 * Function:      boRTC_SetTimeAndDate
 *
 * Purpose:       Sets time and Date
 *
 * Inputs:        pstTimeAndDate: Pointer to Time and Date struct
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE:  Ok
 *                C_FALSE: NULL pointer
 *
 * Limitations:
 *
 ***************************************************************************/
bool_t boRTC_SetTimeAndDate(const rtc_time_date_st *pstTimeAndDate);


/****************************************************************************
 *
 * Function:      boRTC_GetTimeAndDate
 *
 * Purpose:       Gets time and Date
 *
 * Inputs:        pstTimeAndDate: Pointer to Time and Date struct
 *
 * Outputs:       pstTimeAndDate: Pointer to Time and Date struct
 *
 * Return Values: C_TRUE:  Ok
 *                C_FALSE: NULL pointer
 *
 * Limitations:
 *
 ***************************************************************************/
bool_t boRTC_GetTimeAndDate(rtc_time_date_st *pstTimeAndDate);


/****************************************************************************
 *
 * Function:      boRTC_SetConfigReset
 *
 * Purpose:       Set configuration of rtc reset registers
 *
 * Inputs:        pResetCfg:   pointer to config structure
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE/C_FALSE if pointer NULL
 *
 * Limitations:
 *
 ***************************************************************************/
bool_t boRTC_SetConfigReset(const rtc_reset_cfg_st* const pResetCfg);


/****************************************************************************
 *
 * Function:      boRTC_GetConfigReset
 *
 * Purpose:       Get configuration of rtc reset registers
 *
 * Inputs:        pResetCfg:   pointer to config structure
 *
 * Outputs:       pResetCfg:   pointer to config structure
 *
 * Return Values: C_TRUE/C_FALSE if pointer NULL
 *
 * Limitations:
 *
 ***************************************************************************/
bool_t boRTC_GetConfigReset(rtc_reset_cfg_st* const pResetCfg);


/****************************************************************************
 *
 * Function:      vRTC_ResetTimer
 *
 * Purpose:       resets Timer
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_ResetTimer(void);


/****************************************************************************
 *
 * Function:      vRTC_ResetAlarm
 *
 * Purpose:       resets Alarm:
 *                  Initializes alarm registers (Minute Column, Hour Column,
 *                  Day Column and Day of the week Column) as follows.
 *                  Minute: 00, Hour: 00, Day: 01, Day of the week: Sunday 
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_ResetAlarm(void);


/****************************************************************************
 *
 * Function:      vRTC_SetCalibIntvPeriod
 *
 * Purpose:       Set Calibration Interval Period .
 *
 * Inputs:        u8CalibIntvPeriod:  Calibration Interval Period
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_SetCalibIntvPeriod(uint8_t u8CalibIntvPeriod);


/****************************************************************************
 *
 * Function:      vRTC_SetCalibIntvValue
 *
 * Purpose:       Set Calibration Interval Value 
 *
 * Inputs:        u8CalibIntvValue:  Calibration Interval Value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_SetCalibIntvValue(uint8_t u8CalibIntvValue);


/****************************************************************************
 *
 * Function:      vRTC_SetClockSource
 *
 * Purpose:       RTC clock source selection.  (32 KHZ, 10MHZ, 100MHZ)
 *
 * Inputs:        eClkSrc:  clock source
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_SetClockSource(rtc_clock_source_e eClkSrc);


/****************************************************************************
 *
 * Function:      vRTC_EnableCalibration
 *
 * Purpose:       Enable Calibration
 *
 * Inputs:        eEn: enable/disable
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vRTC_EnableCalibration(rtc_enable_e eEn);


#endif /* RTC_LLDD_H */

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

