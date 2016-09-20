/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   File Name   : $RCSfile: buttons.h,v $
*   Description : Button handling
*****************************************************************************
*   PROJECT     : Capricorn
*   MODULE      : Buttons
*   TAG         : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
*****************************************************************************
*   VERSION     : $Revision: 1.2 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/12/17 15:17:49 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Demo_7inch/usecases/inc/buttons.h,v $
****************************************************************************/
#ifndef _BUTTONS_H
#define _BUTTONS_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "config.h"

/**********************************************
*               Defs                          *
**********************************************/


/**********************************************
*               Structs                       *
**********************************************/


/**********************************************
*         External variables                  *
**********************************************/


/**********************************************
*               Functions                     *
**********************************************/

/****************************************************************************
 *
 * Function:      vInitPushbuttons
 *
 * Purpose:       Initialisation of bushbuttons
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 * Precondition:  none
 *
 ***************************************************************************/
void vInitPushbuttons(void);

/****************************************************************************
 *
 * Function:      vUpdatePushbuttons
 *
 * Purpose:       periodic update of button variables
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 * Precondition:  vInitPushbuttons has to be called before
 *
 ***************************************************************************/
void vUpdatePushbuttons(void);

/****************************************************************************
 *
 * Function:      vEvalPushbuttons
 *
 * Purpose:       periodic evaluation of button variables
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 * Precondition:  vInitPushbuttons has to be called before
 *
 ***************************************************************************/
void vEvalPushbuttons(void);

void vAOBInstallEncPollTimer(uint8_t n);
#endif /* _BUTTONS_H */

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

