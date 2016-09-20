/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Serial Bus Interface (I2C) Timer Functionality Extension
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Serial Bus Interface (SBI) / I2C
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.7 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/*
 *  This is a primitive implementation of timers needed by the I2C driver
 *  Those should be ported appropriately to the target platform/system !!! 
 */

/**********************************************
*                Include files                *
**********************************************/
#include "iic_timer.h"                    /* SBI (I2C) timer functionality extension */

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_IIC_TIMER_C_REVISION     "$Revision: 1.7 $"
#define LLDD_IIC_TIMER_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_IIC_TIMER_C_REVISION[] = LLDD_IIC_TIMER_C_REVISION;
static uint8_t au8LLDD_IIC_TIMER_C_TAG[]      = LLDD_IIC_TIMER_C_TAG;
static uint8_t au8LLDD_IIC_TIMER_H_REVISION[] = LLDD_IIC_TIMER_H_REVISION;
static uint8_t au8LLDD_IIC_TIMER_H_TAG[]      = LLDD_IIC_TIMER_H_TAG;

/*********************************************/

/**********************************************
*               Global variables              *
**********************************************/
/* Software timer counters */
uint32_t u32TimeBusy = 0U;
uint32_t u32TimeAck = 0U;

/*********************************************/

/**********************************************
*        Exported function definition         *
**********************************************/

/****************************************************************************/
void vIIC_TimerGetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                          uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
   *pau8ModuleRevision = &au8LLDD_IIC_TIMER_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_IIC_TIMER_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_IIC_TIMER_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_IIC_TIMER_H_TAG[0];
}


/****************************************************************************/
void vIIC_TimerStart (iic_TimerSelect_e eTimer)
{
    /*  
     *  Preset the counter
     */
    switch( eTimer )
    {
        case IIC_TIMER_IRQ_ACK_SEL:                
            u32TimeAck = IIC_TIMER_IRQ_ACK;
            break;

        case IIC_TIMER_BUSY_SEL:                
            u32TimeBusy = IIC_TIMER_BUSY;
            break;

        default:
            break;
    }
}


/****************************************************************************/
void vIIC_TimerStop (iic_TimerSelect_e eTimer)
{
  /* 
   *  Timer can be stopped even if it is not running,
   *  because it could expire in the meantime. Stop 
   *  the appropriate timer by cleareing it
   */
    switch (eTimer)
    {
        case IIC_TIMER_IRQ_ACK_SEL:    
            u32TimeAck = 0;    
            break;

        case IIC_TIMER_BUSY_SEL:         
            u32TimeBusy = 0;    
            break;

        default:
            break;    
    }
}


/****************************************************************************/
iic_TimerStatus_e eIIC_TimerQuery (iic_TimerSelect_e eTimer)
{
    iic_TimerStatus_e eTimerStatus = IIC_TIMER_STOPPED;

    /* 
     *  Check timer counter or RTOS event flag.
     *  If the timer is still running change the 
     *  value of the return status
     */
    switch (eTimer)
    {
        case IIC_TIMER_IRQ_ACK_SEL:                   
            if (u32TimeAck > 0)
            {
                /* Timer running */
                u32TimeAck--;
                eTimerStatus = IIC_TIMER_RUNNING;
            }
            else
            {
                /* Timer expiried */
                u32TimeAck = 0;
                eTimerStatus = IIC_TIMER_EXPIRED;
            }    
            break;

        case IIC_TIMER_BUSY_SEL:    
            if (u32TimeBusy > 0)
            {
                /* Timer running */
                u32TimeBusy--;
                eTimerStatus = IIC_TIMER_RUNNING;
            }
            else
            {
                /* Timer expiried */
                u32TimeBusy = 0;
                eTimerStatus = IIC_TIMER_EXPIRED;
            }    
            break;

        default:  
            break;  
    }
    /* Status report */
    return eTimerStatus;
}


/****************************************************************************/
void iic_Timer_Delay_us (uint32_t u32Time)
{
    /* Wait loop */
    while( u32Time > 0 )
    {
        u32Time--;
    }
}

/****************************************************************************/

/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: iic_timer.c
**  $Revision: 1.7 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :  5 (0286) String literal contains character which is not a
** |                    member of the basic source character set.
** |           5 (0288) Source file '<TEXT>' has comments containing characters
** |                    which are not members of the basic source character set.
** |          22 (3218) File scope static, '<TEXT>', only accessed in one
** |                    function.
** |          45 (0303) Cast between a pointer to volatile object and an
** |                    integral type.
** |          52 (1503) The function '%1s' is defined but is not used within
** |                    this project.
** |
** | REASON : This is neccessary because of driver version control.
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/

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

