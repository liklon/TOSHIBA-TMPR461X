/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TIMER_CMPLX low level driver header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_CMPLX
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TIMER_CMPLX_H
#define TIMER_CMPLX_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_TIMER_CMPLX_H_REVISION     "$Revision: 1.8 $"
#define LLDD_TIMER_CMPLX_H_TAG          "$Name: LLDD_1_6 $"

/****************************************************************************
*                          CONTROLER SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
 
typedef enum tag_timer_cmplx_ch_e
{
  TIMER_CMPLX_PM_0 =0,
  TIMER_CMPLX_PM_1 =0x1000,  
  TIMER_CMPLX_PM_2 =0x2000,  
  TIMER_CMPLX_PM_3 =0x3000,  
  TIMER_CMPLX_PM_4 =0x4000,  
  TIMER_CMPLX_PM_5 =0x5000 
} timer_cmplx_ch_e;

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/* *** */

/*
 *  TBRUN parameter values
 */

/* TBRUN.DBE / TBRUN.SYNC / TBRUN.OFI - double buffer/synchronous reset/overflow interrupt selection */
typedef enum tag_timer_cmplx_en_e
{
    TIMER_CMPLX_DISABLE = 0x0,                    /* Double buffer disabled */
    TIMER_CMPLX_ENABLE  = 0x1                     /* Double buffering enabled */
} timer_cmplx_en_e;

/* TBRUN.IDL - idle state */
typedef enum tag_timer_cmplx_idl_e
{
    TIMER_CMPLX_IDLE   = 0x0,                     /* Timer stops and goes to idle state */
    TIMER_CMPLX_NORMAL = 0x1                      /* Normal operation */
} timer_cmplx_idl_e;

/* TBRUN.PRUN / TBRUN.TRUN / PWMCR.TRUN / HSPWMCR.TRUN / GPWMCR.TRUN - prescaler/timer start/stop */
typedef enum tag_timer_cmplx_run_e
{
    TIMER_CMPLX_STOP  = 0x0,                      /* Timer stop */
    TIMER_CMPLX_START = 0x1                       /* Timer start */
} timer_cmplx_run_e;

/* *** */

/*
 *  TBMOD parameter values
 */

/* TBMOD.CP0 - software capture control */
typedef enum tag_timer_cmplx_cp0_e
{
    TIMER_CMPLX_LATCH    = 0x0,                   /* Latch the counter value into TB0CP0 */
    TIMER_CMPLX_NO_LATCH = 0x1                    /* Do not care */
} timer_cmplx_cp0_e;

/* TBMOD.CLE - up-counter control */
typedef enum tag_timer_cmplx_cle_e
{
    TIMER_CMPLX_FREE_RUN = 0x0,                   /* On match of compare value 1 do count */
    TIMER_CMPLX_ONE_SHOT = 0x1                    /* On match of compare value 1 reset the counter */
} timer_cmplx_cle_e;

/* TBMOD.CPM - capture timing */
typedef enum tag_timer_cmplx_cpm_e
{
    TIMER_CMPLX_CPM_DIS    = 0x0,                 /* Latch disabled */
    TIMER_CMPLX_TBIN01_RR  = 0x1,                 /* Latch at rise of TBIN0 [TBxCAP0] and rise of TBIN1 [TBxCAP1] */
    TIMER_CMPLX_TBIN00_RF  = 0x2,                 /* Latch at rise of TBIN0 [TBxCAP0] and fall of TBIN0 [TBxCAP1] */
    TIMER_CMPLX_TBOUTIN_RF = 0x3                  /* Latch at rise of TB0UTIN [TBxCAP0] and rise of TB0UTIN [TBxCAP1] */
} timer_cmplx_cpm_e;

/* Source Clock Selection (TBMOD.CLK) */
typedef enum tag_timer_cmplx_clk_e
{
    TIMER_CMPLX_CLK_EXT   = 0x0,                  /* External input (TBIN0) */
    TIMER_CMPLX_CLK_DIV1  = 0x1,                  /* Peripheral clock frequency [35MHz] */
    TIMER_CMPLX_CLK_DIV2  = 0x2,                  /* Peripheral clock frequency / 2 */
    TIMER_CMPLX_CLK_DIV4  = 0x3,                  /* Peripheral clock frequency / 4 */
    TIMER_CMPLX_CLK_DIV8  = 0x4,                  /* Peripheral clock frequency / 8 */
    TIMER_CMPLX_CLK_DIV16 = 0x5,                  /* Peripheral clock frequency / 16 */
    TIMER_CMPLX_CLK_DIV32 = 0x6,                  /* Peripheral clock frequency / 32 */
    TIMER_CMPLX_CLK_DIV64 = 0x7                   /* Peripheral clock frequency / 64 */
} timer_cmplx_clk_e;

/* *** */

/*
 *  TBFF parameter values
 */

/* TBFF.INVL0 / TBFF.INVL1 / TBFF.INVC0 / TBFF.INVC1 - TBOUT inversion */
typedef enum tag_timer_cmplx_ffinv_e
{
    TIMER_CMPLX_FF_NOINV = 0x0,                   /* Do not invert */
    TIMER_CMPLX_FF_INV   = 0x1                    /* Inversion enabled */
} timer_cmplx_ffinv_e;

/* TBFF.MOD - output flip-flop mode */
typedef enum tag_timer_cmplx_mod_e
{
    TIMER_CMPLX_TBFF_INV      = 0x0,              /* Invert TBFF value */
    TIMER_CMPLX_TBFF_SET      = 0x1,              /* Set TBFF value */
    TIMER_CMPLX_TBFF_CLR      = 0x2,              /* Clear TBFF value */
    TIMER_CMPLX_TBFF_DONTCARE = 0x3               /* Do not care */
} timer_cmplx_mod_e;


/**********************************************
*                 Structures                  *
**********************************************/

/* 16-bit timer_cmplx configuration */
typedef struct tag_timer_cmplx_genCfg_st
{
    timer_cmplx_en_e  eDblBuffEn;                 /* Double-buffer on/off */
    timer_cmplx_en_e  eSyncRstEn;                 /* Synchronous reset acceptance */
    timer_cmplx_idl_e eIdle;                      /* Idle state */
    timer_cmplx_run_e ePresclStart;               /* Prescaler start/stop */
    timer_cmplx_en_e  eOvrflwIrqEn;               /* Overflow interrupt on/off */
    timer_cmplx_clk_e eClkSource;                 /* Clock source selection */
    timer_cmplx_cle_e eCountCtrl;                 /* Mode selection [free-run or one-shot] */
    timer_cmplx_run_e eTimerStart;                /* Timer start/stop */
} timer_cmplx_genCfg_st;

/* 16-bit timer_cmplx Flip-Flop configuration */
typedef struct tag_timer_cmplx_ffCfg_st
{
    timer_cmplx_ffinv_e eInvl1;                   /* Invert when counter value is latched in TB0CP1 */
    timer_cmplx_ffinv_e eInvl0;                   /* Invert when counter value is latched in TB0CP0 */
    timer_cmplx_ffinv_e eInvc1;                   /* Invert when up-counter value is equal to TB1REG */
    timer_cmplx_ffinv_e eInvc0;                   /* Invert when up-counter value is equal to TB0REG */
    timer_cmplx_mod_e   eFfMode;                  /* Flip-Flop mode */
} timer_cmplx_ffCfg_st;


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_GetVersion
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
void vTIMER_CMPLX_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                       uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                       uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_Config
 *
 * Purpose:       Configure the 16-bit complex timer
 *
 * Inputs:        eCh    Timer channel
 *                stCfg  Target configuration
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_Config(timer_cmplx_ch_e eCh, timer_cmplx_genCfg_st stCfg);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetCountCtrl
 *
 * Purpose:       Set up-counter behavior on match with TB1REG value
 *
 * Inputs:        eCh         Timer channel
 *                eCountCtrl  Control request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetCountCtrl(timer_cmplx_ch_e eCh, timer_cmplx_cle_e eCountCtrl);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetCaptureTiming
 *
 * Purpose:       Set capture event selection
 *
 * Inputs:        eCh         Timer channel
 *                eCapTiming  Capture timing 
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetCaptureTiming(timer_cmplx_ch_e eCh, timer_cmplx_cpm_e eCapTiming);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_FlipFlopConfig
 *
 * Purpose:       Timer 16-bit Flip-Flop configuration
 *
 * Inputs:        eCh      Timer channel
 *                stFfCfg  Flip-flop configuration
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_FlipFlopConfig(timer_cmplx_ch_e eCh, timer_cmplx_ffCfg_st stFfCfg);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetStateIdle
 *
 * Purpose:       Change to IDLE state mode
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetStateIdle(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetStateNormal
 *
 * Purpose:       Change to NORMAL state mode.
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetStateNormal(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_Start
 *
 * Purpose:       Start the 16-bit timer/up-counter
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_Start(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_Stop
 *
 * Purpose:       Stop the 16-bit timer/up-counter
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_Stop(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetOvflowIrqEnable
 *
 * Purpose:       Enable/disable the overflow interrupt
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetOvflowIrqEnable(timer_cmplx_ch_e eCh, timer_cmplx_en_e eIrqEn);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetSyncRstEnable
 *
 * Purpose:       Enable/disable the synchronous reset
 *
 * Inputs:        eCh          Timer channel
 *                eSyncRstEn   Sync Reset Enable parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetSyncRstEnable(timer_cmplx_ch_e eCh, timer_cmplx_en_e eSyncRstEn);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_StartPrescaler
 *
 * Purpose:       Start the prescaler
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_StartPrescaler(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_StopPrescaler
 *
 * Purpose:       Stops the prescaler
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_StopPrescaler(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetDblBuffEnable
 *
 * Purpose:       Enable/disable double buffering
 *
 * Inputs:        eCh      Timer channel
 *                eBuffEn  Double buffer enable parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetDblBuffEnable(timer_cmplx_ch_e eCh, timer_cmplx_en_e eBuffEn);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_LatchCounter
 *
 * Purpose:       Latch the current counter value into TB0CP0 register
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_LatchCounter(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetFfInvl1
 *
 * Purpose:       Set the inversion mode for TBOUT flip-flop upon up-counter 
 *                latch into TB0CP1
 *
 * Inputs:        eCh      Timer channel
 *                eInvert  Inversion parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetFfInvl1(timer_cmplx_ch_e eCh, timer_cmplx_ffinv_e eInvert);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetFfInvl0
 *
 * Purpose:       Set the inversion mode for TBOUT flip-flop upon up-counter 
 *                latch into TB0CP0
 *
 * Inputs:        eCh      Timer channel
 *                eInvert  Inversion parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetFfInvl0(timer_cmplx_ch_e eCh, timer_cmplx_ffinv_e eInvert);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetFfInvc1
 *
 * Purpose:       Set the inversion mode for TBOUT flip-flop upon up-counter 
 *                match with TB1REG
 *
 * Inputs:        eCh  Timer channel
 *                eInvert - Inversion parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetFfInvc1(timer_cmplx_ch_e eCh, timer_cmplx_ffinv_e eInvert);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetFfInvc0
 *
 * Purpose:       Set the inversion mode for TBOUT flip-flop upon up-counter 
 *                match with TB0REG
 *
 * Inputs:        eCh      Timer channel
 *                eInvert  Inversion parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetFfInvc0(timer_cmplx_ch_e eCh, timer_cmplx_ffinv_e eInvert);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetCompareVal0
 *
 * Purpose:       Set first compare value
 *
 * Inputs:        eCh        Timer channel
 *                usCompVal  First compare value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetCompareVal0(timer_cmplx_ch_e eCh, uint16_t u16CompVal);


/****************************************************************************
 *
 * Function:      u16TIMER_CMPLX_GetCompareVal0
 *
 * Purpose:       Retrieve the value of TB0REG register
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: first compare value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TIMER_CMPLX_GetCompareVal0(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      vTIMER_CMPLX_SetCompareVal1
 *
 * Purpose:       Set second compare value 
 *
 * Inputs:        eCh        Timer channel
 *                usCompVal  Second compare calue
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTIMER_CMPLX_SetCompareVal1(timer_cmplx_ch_e eCh, uint16_t u16CompVal);


/****************************************************************************
 *
 * Function:      u16TIMER_CMPLX_GetCompareVal1
 *
 * Purpose:       Retrieve the value of TB1REG register
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: second compare value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TIMER_CMPLX_GetCompareVal1(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      u16TIMER_CMPLX_GetCapturedVal0
 *
 * Purpose:       Retrieve the value captured in TB0CP0 register
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: value captured in TB0CP0 register 
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TIMER_CMPLX_GetCapturedVal0(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      u16TIMER_CMPLX_GetCapturedVal1
 *
 * Purpose:       Retrieve the value captured in TB0CP1 register
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: value captured in TB0CP1 register 
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TIMER_CMPLX_GetCapturedVal1(timer_cmplx_ch_e eCh);


/****************************************************************************
 *
 * Function:      u16TIMER_CMPLX_GetCounterVal
 *
 * Purpose:       Retrieve the current up-counter value
 *
 * Inputs:        eCh  Timer channel
 *
 * Outputs:       none
 *
 * Return Values: current counter value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TIMER_CMPLX_GetCounterVal(timer_cmplx_ch_e eCh);

/****************************************************************************/


#endif /* TIMER_CMPLX_H */

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

