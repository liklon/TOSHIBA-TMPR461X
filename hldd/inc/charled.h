/******************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*******************************************************************************
*   DESCRIPTION : use caracter display led
*******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Capricorn Software
*   LIBRARIES   :
*******************************************************************************
*   VERSION     : $Revision: 1.6 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: HLDD_1_1 $
*******************************************************************************/
#ifndef CHARLED_H
#define CHARLED_H

/**********************************************
*                Include files                *
**********************************************/


/**********************************************
*                 Constants                   *
**********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/


/**********************************************
*                 Structures                  *
**********************************************/


/**********************************************
*            Forward declarations             *
**********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      initCLED
 *
 * Purpose:       initialisation of character LCD
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
void initCLED(void);

/****************************************************************************
 *
 * Function:      setCLED
 *
 * Purpose:       output text on character LED
 *                (Usage: setCLED("Xyz..");
 *
 * Inputs:        text - pointer to text
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void setCLED(char *text);

/****************************************************************************
 *
 * Function:      hexCLED
 *
 * Purpose:       output hexadecimal value on character LED
 *                (converts the decimal to hex and displays on LED)
 *
 * Inputs:        number - hex value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void hexCLED(unsigned long number);

/****************************************************************************
 *
 * Function:      DecCLED
 *
 * Purpose:       output decimal time value on character LED
 *                Units in Pico-Sec. Usage : Pass the number in pico resolution
 *
 * Inputs:        text - number in picoseconds
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void DecCLED(unsigned long long text);

/****************************************************************************
 *
 * Function:      disp_rtc_time_on_CLED
 *
 * Purpose:       Function to print out the RTC time on CLED's. Displays time in HH-MM-SS format
 *                void disp_rtc_time_on_CLED (unsigned short hh, unsigned short mm, unsigned short ss)
 *
 * Inputs:        text - number in picoseconds
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void disp_rtc_time_on_CLED(void);

/****************************************************************************
 *
 * Function:      setNORflash_interface_gdc1
 *
 * Purpose:       On the Ref-Board, Using the EBIF interface under the FG group for
 *                driving LED's. So configure PIMUX CMC* group to EBIF(NOR-Flash)
 *
 * Inputs:        text - number in picoseconds
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void setNORflash_interface_gdc1(void);

/****************************************************************************/

#endif	/* CHARLED_H */

/****************************************************************************/

/*************************  BEGIN of DISCLAIMER   ***************************

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
  conditions set forth in the “Handling Guide for Semiconductor Devices,” or
  “TOSHIBA Semiconductor Reliability Handbook” etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (“Unintended Usage”).
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

***************************  END of DISCALIMER  ****************************/

