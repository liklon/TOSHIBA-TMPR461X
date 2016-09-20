/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : sin/cos integer lookuptable implementation (65536 times integeger values)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : sin/cos integer lookuptable implementation (65536 times integeger values)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.7 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef SINUSCOSINUS_H
#define SINUSCOSINUS_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_SINUSCOSINUS_H_REVISION     "$Revision: 1.7 $"
#define LLDD_SINUSCOSINUS_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vSINUSCOSINUS_GetVersion
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
void vSINUSCOSINUS_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                              uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);

/****************************************************************************
 *
 * Function:      vCopySinCosTableROM2RAM
 *
 * Purpose:       copy sin-table from ROM to RAM
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCopySinCosTableROM2RAM(void);

/****************************************************************************
 *
 * Function:      i32SinLookUp
 *
 * Purpose:       sin() look up table (65536 times integer)
 *
 * Inputs:        int16_t angle_x_10 (10 times integer angle, 0 <= 3600 degrees)
 *
 * Outputs:       none
 *
 * Return Values: int32_t 65536 times integer sinus value
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32SinLookup(int16_t angle_x_10);

/****************************************************************************
 *
 * Function:      i32CosLookUp
 *
 * Purpose:       cos() look up table (65536 times integer)
 *
 * Inputs:        int16_t angle_x_10 (10 times integer angle, 0 <= 3600 degrees)
 *
 * Outputs:       none
 *
 * Return Values: int32_t 65536 times integer cos value
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32CosLookup(int16_t angle_x_10);

/****************************************************************************
 *
 * Function:      vSinCosLookUp
 *
 * Purpose:       sin(), cos() look up table (65536 times integer)
 *
 * Inputs:        int16_t angle_x_10 (10 times integer angle, 0 <= 3600 degrees)
 * 
 *
 * Outputs:       int32_t *sin_      pointer to 65536 times integer sinus value
 *                int32_t *cos_      pointer to 65536 times integer cosinus value
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSinCosLookUp(int16_t angle_x_10, int32_t *sin_, int32_t *cos_);

/****************************************************************************/


#endif /* SINUSCOSINUS_H */

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

