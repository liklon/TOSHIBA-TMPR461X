/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: statevariables.c,v $
*   Description : Statevariables
******************************************************************************
*   PROJECT     : Capricorn_Bt
*   MODULE      : Application
*               : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.1 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/05/09 14:05:53 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Basic_Graphics_Keil/usecases/src/statevariables.c,v $
*   LOG:        : please have a look at the end of the file
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"         /* Core specific primitive type definitions */
#include "statevariables.h"

/**********************************************
*             Constants & Macros              *
**********************************************/


/**********************************************
*                Variables                    *
**********************************************/
statevariables_st stStatevariables;

/**********************************************
*             Function definition             *
**********************************************/
void vInitStatevariables(void)
{
    stStatevariables.u8Animate = 1;

    stStatevariables.u8GearToggle = 0;                          // update of front and back buffer
    stStatevariables.u16GearType = 0;                           // type of gear
    stStatevariables.u16GearTypeold = 0;                        // old type of gear

    stStatevariables.u16IndicatorleftAlpha = 0xFFFF;            // alpha of indicator left
    stStatevariables.u8IndicatorleftType = 0x0;                 // type of indicator left
    stStatevariables.u16IndicatorrightAlpha = 0xFFFF;           // alpha of indicator right
    stStatevariables.u8IndicatorrightType = 0x0;                // type of indicator right

    stStatevariables.u16BatteryAlpha = 0xFFFF;                  // alpha for battery
    stStatevariables.u8BatteryOn = 0x0;                         // battery on or off
    stStatevariables.u16LightAlpha = 0xFFFF;                    // alpha for light
    stStatevariables.u8LightOn = 0x0;                           // light on or off
    stStatevariables.u8LightType = 0x1;                         // light type
    stStatevariables.u16OilAlpha = 0xFFFF;                      // alpha for oil
    stStatevariables.u8OilOn = 0x0;                             // oil on or off
    
    stStatevariables.i8EncoderInc  = 0;
    stStatevariables.u16Button_1   = 0;
    stStatevariables.u16Button_2   = 0;
    stStatevariables.u16Button_3   = 0;
    stStatevariables.u16Button_4   = 0;
    stStatevariables.u16Button_enc = 0;
    
}

/***************************************************************************/


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

/********************************* BEGIN OF LOG ******************************
*
* $Log: statevariables.c,v $
* Revision 1.1  2014/05/09 14:05:53  mto
* initial version
*
*
*********************************** END OF LOG ******************************/
