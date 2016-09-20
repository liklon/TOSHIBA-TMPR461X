/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: buttons.c,v $
*   Description : Button handling
*****************************************************************************
*   PROJECT     : FPK-demo
*   MODULE      : Buttons
*   TAG         : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.5 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/12/17 15:17:49 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Demo_7inch/usecases/src/buttons.c,v $
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "buttons.h"
#include "gpio.h"
#include "ccr.h"
#include "intc.h"
#include "statevariables.h"
#include "pinconfig.h"
#include "timer_cmplx.h"
#include "mydef.h"
/**********************************************
*               Defs                          *
**********************************************/
/* SMC position update ration */
#define ENCODER_TICK_RATIO   (7 * 75 * (1000 / 64))

#define PB_DELAY		3

#define AOB_ENCODER_POLL_RATE   175000

/**********************************************
*               Structs                       *
**********************************************/


/**********************************************
*              Variables                      *
**********************************************/
/* button 1 */
uint32_t u32Pushbutton1_wait;
uint32_t u32Pushbutton1_new;
uint32_t u32Pushbutton1_old;

/* button 2 */
uint32_t u32Pushbutton2_wait;
uint32_t u32Pushbutton2_new;
uint32_t u32Pushbutton2_old;

/* button 3 */
uint32_t u32Pushbutton3_wait;
uint32_t u32Pushbutton3_new;
uint32_t u32Pushbutton3_old;

/* button 4 */
uint32_t u32Pushbutton4_wait;
uint32_t u32Pushbutton4_new;
uint32_t u32Pushbutton4_old;

/* button encoder */
uint32_t u32Pushbutton5_wait;
uint32_t u32Pushbutton5_new;
uint32_t u32Pushbutton5_old;

int8_t i8Graytab[] = { 0,1,-1,0, -1,0,0,1, 1,0,0,-1, 0,-1,1,0 };
int8_t i8Enc_delta;              // Encoder inc between two calls in main

/* static variables */
int8_t i8Encoder_Rest;
uint8_t u8Graycode;

/**********************************************
*               Functions                     *
**********************************************/

int8_t i8GetEncoder(void)
{
    int8_t i8Value = 0;

    if (i8Enc_delta != 0)
    {
        if (i8Enc_delta > 0)
        {
            i8Value = 1;
        }
        else
        {
            i8Value = -1;
        }
        i8Enc_delta = 0;
    }
    
    return i8Value;
}

/****************************************************************************/
uint16_t u16TimerCount = 0;
extern uint8_t u8SpeedChangeTimeFlag;
uint16_t u16Timer1SFlag = 0;
uint16_t u16TimerAlpha = 0;
uint8_t u8QdIndex = 0;
uint16_t u16TimerQd = 0;
extern uint8_t u8PowerDir;

#if defined(__GHS__) || defined(__ghs__)
__interrupt void vISREncoder(void)
#else
__irq void vISREncoder(void)
#endif /* defined(__GHS__) || defined(__ghs__) */
{
    u16TimerCount++;
	u8SpeedChangeTimeFlag++;
	u16Timer1SFlag++;
	u16TimerAlpha++;
	u16TimerQd++;

	if(u16TimerQd > 10)
	{
		if(u8PowerDir == 0) u8QdIndex++;
		else if(u8PowerDir == 1)
		{
			if(u8QdIndex > 0) u8QdIndex--;
            else u8QdIndex = 2;
		}
			
		if(u8QdIndex > 2) u8QdIndex = 0;
		
		u16TimerQd = 0;
	}
	
	if(u8SpeedChangeTimeFlag > 200) u8SpeedChangeTimeFlag = 0;
	if(u16TimerCount > 10000) u16TimerCount = 0;
	if(u16Timer1SFlag > 10000) u16Timer1SFlag = 0;
	if(u16TimerAlpha > 10000) u16TimerAlpha = 0;
    vINTC_ModifyIrqLevel(INTC_RESTORE_OLD, INTC_LEVEL_7);
}

/****************************************************************************/


void vAOBInstallEncPollTimer(uint8_t n)
{
    timer_cmplx_genCfg_st timer_cmplx;
    uint16_t u16CompVal;

    /* configure complex timer 1 for encoder update */
    timer_cmplx.eDblBuffEn   = TIMER_CMPLX_DISABLE;    /* do not use double buffer */
    timer_cmplx.eSyncRstEn   = TIMER_CMPLX_DISABLE;    /* disable synchronous reset acceptance */
    timer_cmplx.eIdle        = TIMER_CMPLX_NORMAL;     /* Normal operation */
    timer_cmplx.ePresclStart = TIMER_CMPLX_STOP;       /* Prescaler stop */
    timer_cmplx.eOvrflwIrqEn = TIMER_CMPLX_DISABLE;    /* Overflow interrupt on/off */
    timer_cmplx.eClkSource   = TIMER_CMPLX_CLK_DIV64;  /* Peripheral clock frequency [75MHz]/64 */
    timer_cmplx.eCountCtrl   = TIMER_CMPLX_ONE_SHOT;   /* On match of compare value 1 reset the counter  */
    timer_cmplx.eTimerStart  = TIMER_CMPLX_STOP;       /* Timer start/stop */
    vTIMER_CMPLX_Config(TIMER_CMPLX_PM_1, timer_cmplx);

    // calculate counter value
    u16CompVal = TIMERCOMPLX_NUMBER(n);//ENCODER_TICK_RATIO;
    vTIMER_CMPLX_SetCompareVal1(TIMER_CMPLX_PM_1, u16CompVal);

    /* configure interrupt modes */
    i32INTC_SourceConfig(INTC_TIM1_MAVAL1, INTC_TO_CPU, INTC_EDGE_FALL, INTC_LEVEL_3, INTC_AUTO_CLEAR_ENABLE);
    
    /* set callback function for tick timer IRQ */
    vINTC_SetISRStartAddress(INTC_TIM1_MAVAL1, (uint32_t)&vISREncoder);

    vTIMER_CMPLX_StartPrescaler(TIMER_CMPLX_PM_1);     /* start timer prescaler */
    vTIMER_CMPLX_Start(TIMER_CMPLX_PM_1);              /* start tick timer */
}


/****************************************************************************/

void vInitPushbuttons(void)
{
    i8Encoder_Rest = 0;
    u8Graycode = 0;

    /* Encoder increment */
    i8Enc_delta = 0;

   // vPinconfig_Buttons();
    //vAOBInstallEncPollTimer();

    /* button 1 */
    u32Pushbutton1_wait = 0;
    u32Pushbutton1_new  = 0;
    u32Pushbutton1_old  = 0;    

    /* button 2 */
    u32Pushbutton2_wait = 0;
    u32Pushbutton2_new  = 0;
    u32Pushbutton2_old  = 0;

    /* button 3 */
    u32Pushbutton3_wait = 0;
    u32Pushbutton3_new  = 0;
    u32Pushbutton3_old  = 0;

    /* button 4 */
    u32Pushbutton4_wait = 0;
    u32Pushbutton4_new  = 0;
    u32Pushbutton4_old  = 0;    

    /* button encoder */
    u32Pushbutton5_wait = 0;
    u32Pushbutton5_new  = 0;
    u32Pushbutton5_old  = 0;    
}

/****************************************************************************/


void vUpdatePushbuttons(void)
{
    gpio_state_e ePBState = GPIO_LOW;

    /* AOB: encoder increment */
    stStatevariables.i8EncoderInc = i8GetEncoder();

    /* button 1 */
    i32GPIO_GetPinState(PORT_I2SMCLK, &ePBState);
    if( ePBState == 0 )
    {
        u32Pushbutton1_wait = u32Pushbutton1_wait + 1;
        if( u32Pushbutton1_wait > PB_DELAY )
        {
            u32Pushbutton1_new = 1;
            if( u32Pushbutton1_new != u32Pushbutton1_old )
            {
                u32Pushbutton1_old = u32Pushbutton1_new;
        
                stStatevariables.u16Button_1 = 1;
            }
        }
    }
    else
    {
        u32Pushbutton1_wait = 0;
        u32Pushbutton1_new = 0;
        u32Pushbutton1_old = 0;
    }

    /* button 2 */
    i32GPIO_GetPinState(PORT_I2S0CLK, &ePBState);
    if( ePBState == 0)
    {
        u32Pushbutton2_wait = u32Pushbutton2_wait + 1;
        if( u32Pushbutton2_wait > PB_DELAY )
        {
            u32Pushbutton2_new = 1;
            if( u32Pushbutton2_new != u32Pushbutton2_old )
            {
                u32Pushbutton2_old = u32Pushbutton2_new;

                stStatevariables.u16Button_2 = 1;
            }
        }
    }
    else
    {
        u32Pushbutton2_wait = 0;
        u32Pushbutton2_new = 0;
        u32Pushbutton2_old = 0;
    }

    /* button 3 */
    i32GPIO_GetPinState(PORT_I2S0WS, &ePBState);
    if( ePBState == 0)
    {
        u32Pushbutton3_wait = u32Pushbutton3_wait + 1;
        if( u32Pushbutton3_wait > PB_DELAY )
        {
            u32Pushbutton3_new = 1;
            if( u32Pushbutton3_new != u32Pushbutton3_old )
            {
                u32Pushbutton3_old = u32Pushbutton3_new;

                stStatevariables.u16Button_3 = 1;
            }
        }
    }
    else
    {
        u32Pushbutton3_wait = 0;
        u32Pushbutton3_new = 0;
        u32Pushbutton3_old = 0;
    }

    /* button 4 */
    i32GPIO_GetPinState(PORT_I2S0SD, &ePBState);
    if( ePBState == 0)
    {
        u32Pushbutton4_wait = u32Pushbutton4_wait + 1;
        if( u32Pushbutton4_wait > PB_DELAY )
        {
            u32Pushbutton4_new = 1;
            if( u32Pushbutton4_new != u32Pushbutton4_old )
            {
                u32Pushbutton4_old = u32Pushbutton4_new;

                stStatevariables.u16Button_4 = 1;
            }
        }
    }
    else
    {
        u32Pushbutton4_wait = 0;
        u32Pushbutton4_new = 0;
        u32Pushbutton4_old = 0;
    }	

    /* button encoder */
    i32GPIO_GetPinState(PORT_PNLGPP6, &ePBState);
    if( ePBState == 0)
    {
        u32Pushbutton5_wait = u32Pushbutton5_wait + 1;
        if( u32Pushbutton5_wait > PB_DELAY )
        {
            u32Pushbutton5_new = 1;
            if( u32Pushbutton5_new != u32Pushbutton5_old )
            {
                u32Pushbutton5_old = u32Pushbutton5_new;

                stStatevariables.u16Button_enc = 1;
            }
        }
    }
    else
    {
        u32Pushbutton5_wait = 0;
        u32Pushbutton5_new = 0;
        u32Pushbutton5_old = 0;
    }	
    stStatevariables.i8EncoderInc  = 0;
    stStatevariables.u16Button_1   = 0;
    stStatevariables.u16Button_2   = 0;
    stStatevariables.u16Button_3   = 0;
    stStatevariables.u16Button_4   = 0;
    stStatevariables.u16Button_enc = 0;

}

/****************************************************************************/


/****************************************************************************/


/************************* BEGIN of DISCLAIMER   *****************************

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

****************************  END of DISCLAIMER *****************************/
