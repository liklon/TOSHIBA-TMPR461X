/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TIMER_PWM low level driver header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_PWM
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TIMER_PWM_H
#define TIMER_PWM_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_TIMER_PWM_H_REVISION     "$Revision: 1.10 $"
#define LLDD_TIMER_PWM_H_TAG          "$Name: LLDD_1_6 $"

/****************************************************************************
*                          CONTROLER SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
typedef enum tag_timer_pwm_cntrl_e
{
  TIMER_PWM_CNTRL_0  =0,
  TIMER_PWM_CNTRL_1  =0x1000,
  TIMER_PWM_CNTRL_2  =0x2000,
  TIMER_PWM_CNTRL_3  =0x3000,
  TIMER_PWM_CNTRL_4  =0x4000,
  TIMER_PWM_CNTRL_5  =0x5000,
  TIMER_PWM_CNTRL_6  =0x6000,
  TIMER_PWM_CNTRL_7  =0x7000,
  TIMER_PWM_CNTRL_8  =0x8000,
  TIMER_PWM_CNTRL_9  =0x9000,
  TIMER_PWM_CNTRL_10 =0xA000,
  TIMER_PWM_CNTRL_11 =0xB000,
  TIMER_PWM_CNTRL_12 =0xC000,
  TIMER_PWM_CNTRL_13 =0xD000,
  TIMER_PWM_CNTRL_14 =0xE000,
  TIMER_PWM_CNTRL_15 =0xF000,
  TIMER_PWM_CNTRL_16 =0x10000,
  TIMER_PWM_CNTRL_17 =0x11000,
  TIMER_PWM_CNTRL_18 =0x12000,
  TIMER_PWM_CNTRL_19 =0x13000,
  TIMER_PWM_CNTRL_20 =0x14000,
  TIMER_PWM_CNTRL_21 =0x15000,
  TIMER_PWM_CNTRL_22 =0x16000,
  TIMER_PWM_CNTRL_23 =0x17000
} timer_pwm_cntrl_e;

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/* TBRUN.DBE / TBRUN.SYNC / TBRUN.OFI - double buffer/synchronous reset/overflow interrupt selection */
typedef enum tag_timer_pwm_en_e
{
    TIMER_PWM_DISABLE = 0x0,                    /* Double buffer disabled */
    TIMER_PWM_ENABLE  = 0x1                     /* Double buffering enabled */
} timer_pwm_en_e;

/* PWMCR.SCLK / HSPWMCR.SCLK / GPWMCR.SCLK - prescaler selection */
typedef enum tag_timer_pwm_sclk_e
{
    TIMER_PWM_SCLK_DIV1   = 0x0,            /* IM-Bus frequency [40 MHz] / G-Bus frequency [140 MHz] / Dot Clock */
    TIMER_PWM_SCLK_DIV2   = 0x1,            /* IM-Bus/G-Bus/Dot-Clock frequency / 2 */
    TIMER_PWM_SCLK_DIV4   = 0x2,            /* IM-Bus/G-Bus/Dot-Clock frequency / 4 */
    TIMER_PWM_SCLK_DIV8   = 0x3,            /* IM-Bus/G-Bus/Dot-Clock frequency / 8 */
    TIMER_PWM_SCLK_DIV16  = 0x4,            /* IM-Bus/G-Bus/Dot-Clock frequency / 16 */
    TIMER_PWM_SCLK_DIV32  = 0x5,            /* IM-Bus/G-Bus/Dot-Clock frequency / 32 */
    TIMER_PWM_SCLK_DIV64  = 0x6,            /* IM-Bus/G-Bus/Dot-Clock frequency / 64 */
    TIMER_PWM_SCLK_DIV128 = 0x7             /* IM-Bus/G-Bus/Dot-Clock frequency / 128 */
} timer_pwm_sclk_e;

/* PWMCR.RC / GPWMCR.RC - reset of the counter */
typedef enum tag_timer_pwm_rc_e
{
    TIMER_PWM_PDR_ONLY   = 0x0,              /* Reset on PWMPDR match only */
    TIMER_PWM_PDR_HSYNC  = 0x1,              /* Reset on HSync edge and on PWMPDR match */
    TIMER_PWM_PDR_VSYNC  = 0x2,              /* Reset on VSync edge and on PWMPDR match */
    TIMER_PWM_PDR_HVSYNC = 0x3               /* Reset on HSync, Vsync and on PWMPDR match */
} timer_pwm_rc_e;

/* PWMCR.VED / PWMCR.HED / GPWMCR.VED / GPWMCR.HED  - sync edge detection */
typedef enum tag_timer_pwm_ved_e
{
    TIMER_PWM_SYNC_POS = 0x0,                   /* Positive V/HSync edge detected */
    TIMER_PWM_SYNC_NEG = 0x1                    /* Negative V/HSync edge detected */
} timer_pwm_ved_e;

/* PWMCR.OL / HSPWMCR.OL / GPWMCR.OL - output level */
typedef enum tag_timer_pwm_ol_e
{
    TIMER_PWM_LEVEL_LO = 0x0,                   /* PWM starts active low (low duty cycle) */
    TIMER_PWM_LEVEL_HI = 0x1                    /* PWM starts active high (high duty cycle) */
} timer_pwm_ol_e;

/* PWMCR.GDC / GPWMCR.GDC - display synchronization signals */
typedef enum tag_timer_pwm_gdc_e
{
    TIMER_PWM_HSYNC   = 0x0,                    /* HSync selected */
    TIMER_PWM_DOTCLK  = 0x1,                    /* DotClock selected */
    TIMER_PWM_PRESCAL = 0x2                     /* Prescaler selected */
} timer_pwm_gdc_e;

/* GPWMCR.TCORE_EN - timer_pwm core control */
typedef enum tag_timer_pwm_tcore_e
{
    TIMER_PWM_CORE_DISABLE = 0x0,               /* Timer is disabled */
    TIMER_PWM_CORE_ENABLE  = 0x1,               /* Timer is enabled */
} timer_pwm_tcore_e;


/**********************************************
*                 Structures                  *
**********************************************/

/* PWM timer configuration  */
typedef struct tag_timer_pwm_Cfg_st
{
    timer_pwm_sclk_e  ePrescalClk;              /* Peripheral clock prescaler */
    timer_pwm_rc_e    eRst;                     /* Reset counter condition */
    timer_pwm_ved_e   eVSyncEd;                 /* VSync edge detection */
    timer_pwm_ved_e   eHsyncEd;                 /* HSync edge detection */
    timer_pwm_en_e    eIrqEn;                   /* Period end interrupt enable/disable */
    timer_pwm_en_e    eDblBuffEn;               /* Double-buffer on/off */
    timer_pwm_ol_e    eOutLevel;                /* Output level */
    timer_pwm_gdc_e   eClkSrc;                  /* Display synchronization signals */
} timer_pwm_Cfg_st;

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vTIMER_PWM_GetVersion
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
void vTIMER_PWM_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                           uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                           uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      boTIMER_PWM_Config
 *
 * Purpose:       Configure a PWM timer
 *
 * Inputs:        eCntrl   PWM timer controller
 *                eCfg     Target configuration
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE  on success
 *                C_FALSE on inalid PWM controller type
 *
 * Limitations:   Only Standard PWM timer controllers may be provided
 *
 ***************************************************************************/
bool_t boTIMER_PWM_Config(timer_pwm_cntrl_e eCntrl, timer_pwm_Cfg_st stCfg);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_SetPeriod
 *
 * Purpose:       Preset the PWM timer period
 *
 * Inputs:        eCntrl    PWM timer controller
 *                usPeriod  PWM timer period
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_SetPeriod(timer_pwm_cntrl_e eCntrl, uint16_t u16Period);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_SetDuty
 *
 * Purpose:       Preset the PWM timer duty
 *
 * Inputs:        eCntrl  PWM timer controller
 *                usDuty  PWM Timer duty cycle
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_SetDuty(timer_pwm_cntrl_e eCntrl, uint16_t u16Duty);


/****************************************************************************
 *
 * Function:      u16TIMER_PWM_GetDuty
 *
 * Purpose:       Retrieve the PWM timer duty
 *
 * Inputs:        eCntrl  PWM timer controller
 *
 * Outputs:       Current duty cycle value
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TIMER_PWM_GetDuty(timer_pwm_cntrl_e eCntrl);


/****************************************************************************
 *
 * Function:      i32TIMER_PWM_SetWaveform
 *
 * Purpose:       Set the PWM timer square waveform
 *
 * Inputs:        eCntrl     PWM timer controller
 *                usPeriod   PWM timer period
 *                usDuty     PWM timer duty cycle [range 0-100]
 *                eOutLevel  PWM output level 
 *
 * Outputs:       none
 *
 * Return Values: 0-100  achieved duty-cycle value on success 
 *                0xFF   on error
 *
 * Limitations:   The timer must be stopped if doublebuffering is switched
 *                off in order to be successfully configured. If this is
 *                however not the case, the function will immediately return
 *                with 0xFF, without setting any parameters
 *
 ***************************************************************************/
int32_t i32TIMER_PWM_SetWaveform(timer_pwm_cntrl_e eCntrl, uint16_t u16Period, uint16_t u16Duty, timer_pwm_ol_e eOutLevel);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_SetPrescaler
 *
 * Purpose:       Set the PWM timer prescaler divider
 *
 * Inputs:        eCntrl    PWM timer controller
 *                ePrescal  Division factor
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_SetPrescaler(timer_pwm_cntrl_e eCntrl, timer_pwm_sclk_e ePrescal);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_SetRstCondition
 *
 * Purpose:       Set the PWM counter reset condition
 *
 * Inputs:        eCntrl   PWM timer controller
 *                eRst     Reset condition
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_SetRstCondition(timer_pwm_cntrl_e eCntrl, timer_pwm_rc_e eRst);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_SetDetEdgeVsync
 *
 * Purpose:       Set the VSync detection edge
 *
 * Inputs:        eCntrl   PWM timer controller
 *                eEdge    Positive/negative edge
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_SetDetEdgeVsync(timer_pwm_cntrl_e eCntrl, timer_pwm_ved_e eEdge);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_SetDetEdgeHSync
 *
 * Purpose:       Set the HSync detection edge
 *
 * Inputs:        eCntrl   PWM timer controller
 *                eEdge    Positive/negative edge
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_SetDetEdgeHSync(timer_pwm_cntrl_e eCntrl, timer_pwm_ved_e eEdge);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_IrqEnable
 *
 * Purpose:       Enable/disable the interrupt request
 *
 * Inputs:        eCntrl    PWM timer controller
 *                eEnable   On/off request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_IrqEnable(timer_pwm_cntrl_e eCntrl, timer_pwm_en_e eEnable);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_DBuffEnable
 *
 * Purpose:       Enable/disable the double buffeing
 *
 * Inputs:        eCntrl   PWM timer controller
 *                eEnable  On/off request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_DBuffEnable(timer_pwm_cntrl_e eCntrl, timer_pwm_en_e eEnable);


/****************************************************************************
 *
 * Function:      i32TIMER_PWM_SetOutLevel
 *
 * Purpose:       Set the PWM initial output level
 *
 * Inputs:        eCntrl    PWM timer controller
 *                eLevel    Desired output level
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS  on sucess
 *                C_FAILED   if timer runs
 *
 * Limitations:   This function cannot change the setting of output level
 *                when the PWM Timer is running. In this case, the function
 *                will immediately return with error
 *
 ***************************************************************************/
int32_t i32TIMER_PWM_SetOutLevel(timer_pwm_cntrl_e eCntrl, timer_pwm_ol_e eLevel);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_SetClkSource
 *
 * Purpose:       Select PWM timer clock source
 *
 * Inputs:        eCntrl   PWM timer controller
 *                eSource  Clock source
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_SetClkSource(timer_pwm_cntrl_e eCntrl, timer_pwm_gdc_e eSource);


/****************************************************************************
 *
 * Function:      vTIMER_PWM_Enable
 *
 * Purpose:       Enable/disables the PWM timer
 *
 * Inputs:        eCntrl   PWM timer controller
 *                eEnable  Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_PWM_Enable(timer_pwm_cntrl_e eCntrl, timer_pwm_en_e eEnable);


/****************************************************************************
 *
 * Function:      u16TIMER_PWM_GetCountVal
 *
 * Purpose:       Retrieve the current value of the PWM counter
 *
 * Inputs:        eCntrl  PWM timer controller
 *
 * Outputs:       none
 *
 * Return Values: current PWM counter value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TIMER_PWM_GetCountVal(timer_pwm_cntrl_e eCntrl);

/****************************************************************************/


#endif /* TIMER_PWM_H */

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

