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
*   VERSION     : $Revision: 1.6 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef IIC_TIMER_H
#define IIC_TIMER_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/

/**********************************************
*                  Exports                    *
**********************************************/
/* Software timer counters */
extern uint32_t u32TimeBusy;
extern uint32_t u32TimeAck;

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_IIC_TIMER_H_REVISION     "$Revision: 1.6 $"
#define LLDD_IIC_TIMER_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/* Acknowledge time-out value in [ms] */
#define IIC_TIMER_IRQ_ACK                   16000 
/* Busy time-out value in [ms] */
#define IIC_TIMER_BUSY                      15000

/* Guard time for restart procedure [ms] */
#define IIC_TIMER_RESTART_GUARD             1000
 
/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/* IIC Timer types */
typedef enum tag_iic_TimerSelect_e
{  
  IIC_TIMER_IRQ_ACK_SEL = 1,                /* Acknowledge time-out timer */
  IIC_TIMER_BUSY_SEL = 2                    /* Busy time-out timer */
} iic_TimerSelect_e;

/* IIC Timer status / error codes */
typedef enum tag_iic_TimerStatus_e
{
  IIC_TIMER_STOPPED = 0,                    /* Timer is stopped / not running */
  IIC_TIMER_RUNNING,                        /* Timer is running */
  IIC_TIMER_EXPIRED                         /* Timer expired */
} iic_TimerStatus_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vIIC_TimerGetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vIIC_TimerGetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                          uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);


/****************************************************************************
 *
 * Function:      IIC_TimerStart
 *
 * Purpose:       Start the selected time-out detection & recovery software
 *                timer
 *
 * Inputs:        eTimer  Time-out to be measured
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   This function is provided as a sample solution, to overcome 
 *                the lack of hardware support for time-out detection in the 
 *                SBI. It may be rewritten or ported to use any available in
 *                the system resources, like complex/system timers, operating
 *                system mechanisms, etc. 
 *
 ***************************************************************************/
void vIIC_TimerStart(iic_TimerSelect_e eTimer);


/****************************************************************************
 *
 * Function:      vIIC_TimerStop
 *
 * Purpose:       Stops and clears the selected time-out detection software
 *                timer
 *
 * Inputs:        eTimer  Software timer to be stopped
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   This function is provided as a sample solution, to overcome 
 *                the lack of hardware support for time-out detection in the 
 *                SBI. It may be rewritten or ported to use any available in
 *                the system resources, like complex/system timers, operating
 *                system mechanisms, etc. 
 *
 ***************************************************************************/
void vIIC_TimerStop(iic_TimerSelect_e eTimer);


/****************************************************************************
 *
 * Function:      eIIC_TimerQuery
 *
 * Purpose:       Retrieve the current status of a software timer
 *
 * Inputs:        eTimer  Software timer to be checked
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   This function is provided as a sample solution, to overcome 
 *                the lack of hardware support for time-out detection in the 
 *                SBI. It may be rewritten or ported to use any available in
 *                the system resources, like complex/system timers, operating
 *                system mechanisms, etc. 
 *
 ***************************************************************************/
iic_TimerStatus_e eIIC_TimerQuery (iic_TimerSelect_e eTimer);


/****************************************************************************
 *
 * Function:      iic_Timer_Delay_us
 *
 * Purpose:       Inserts very short and platform specific delays
 *
 * Inputs:        u32Time  Selected time to wait [in core cycles]
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   This function is provided as a sample solution, to overcome 
 *                the lack of hardware support for time-out detection in the 
 *                SBI. It may be rewritten or ported to use any available in
 *                the system resources, like complex/system timers, operating
 *                system mechanisms, etc. 
 *
 ***************************************************************************/
void iic_Timer_Delay_us (uint32_t u32Time);

/****************************************************************************/	


#endif /* IIC_TIMER_H */

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

