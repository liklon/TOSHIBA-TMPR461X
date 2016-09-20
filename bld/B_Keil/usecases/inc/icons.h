/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: icons.h,v $
*   Description : Icons
******************************************************************************
*   PROJECT     : Capricorn_Bt
*   MODULE      : Application
*               : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.1 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/05/09 14:05:52 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Basic_Graphics_Keil/usecases/inc/icons.h,v $
*   LOG:        : please have a look at the end of the file
*****************************************************************************/
#ifndef ICONS_H
#define ICONS_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */
#include "config.h"
#include "mydef.h"
#include "GPIO.H" 
/**********************************************
*                 Constants                   *
**********************************************/
#define FADE_INDICATOR   40
#define FADE_ICONS       31

/**********************************************
*               Enumerations                  *
**********************************************/


/**********************************************
*                 Structures                  *
**********************************************/


/**********************************************
*                Variables                    *
**********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vInitIcons
 *
 * Purpose:       Initialisation of icons
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vInitIcons(void);

/****************************************************************************
 *
 * Function:      vSetIcons
 *
 * Purpose:       Set of icons
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSetIcons(void);
void vSetSpeedNeedle(void);
void vShowSpeedNumber(void);


void vShowRotateSpeed(void);

void vShowMotorPower(void);

void vShowTotalVoltage(void);

void vShowTotalCurrent(void);
void vShowSOCNumber(void); 
void vShowBatteryVoltage(void);

void vShowBatteryLife(void);
void vShowTotalDistance(void);
void vShowTripDistance(void);

void vShowTorque(void);

void vShowMotorT(void);
void vShowControlT(void);


void vShowBatteryMaxV(void);

void vShowBatteryMinV(void);


void vShowBatteryDropV(void);

void vShowBatteryDropT(void);

void vShowChargeTime(void);

void vShowErrWord(void);

void vShowBatteryMaxT(void);
	
void vShowBatteryMinT(void);
void vShowPRNDS(void);


void vShowPowerOnLogo(void);
void vShowChargeTimeInit(void);
void vShowDistanceInit(void);
void vShowBatteryInit(void);
void vRunIconFunction(void);
void vShowkpa(void);
void vShowkpb(void);
void vBLControl(gpio_portpin_e ePin, uint8_t u8stat, uint8_t u8flagon);

void vInitPanelPin(void);
void vShowAlphaChange(void);

void vShowBatteryT(void);

void vShowDCACT(void);
void vShowUPST(void);
void vShowCurrentTime(void);
void vSetBackPic(void);
void vSetBackPicCarInfo(void);
void vClearScreen(void);

void vCreatBatSmall(DiyBar_st* pstTmpBar);


#endif  /* ICONS_H */

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
  conditions set forth in the ?andling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (?nintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer? own risk.

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
* $Log: icons.h,v $
* Revision 1.1  2014/05/09 14:05:52  mto
* initial version
*
*
*********************************** END OF LOG ******************************/
