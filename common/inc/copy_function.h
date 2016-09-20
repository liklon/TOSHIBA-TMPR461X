/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION :
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : config
*   LIBRARIES   :
******************************************************************************
*   VERSION     : $Revision: 1.6 $
*   DATE        : $Date: 2015/05/04 09:07:19 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef COPY_FUNCTION_H
#define COPY_FUNCTION_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "core.h"

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

/*********************************************/

/**********************************************
*                 Enumerations                *
**********************************************/

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      asm_copy_word
 *
 * Purpose:       Copy array of words
 *
 * Inputs:        arg1    start adresse source
 *                arg2    end adresse source
 *                arg3    start adresse destination
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void asm_copy_word(uint32_t arg1, uint32_t arg2, uint32_t arg3);

/****************************************************************************
 *
 * Function:      asm_copy_hword
 *
 * Purpose:       Copy array of half words
 *
 * Inputs:        arg1    start adresse source
 *                arg2    end adresse source
 *                arg3    start adresse destination
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void asm_copy_hword(uint32_t arg1, uint32_t arg2, uint32_t arg3);

/****************************************************************************
 *
 * Function:      asm_copy_byte
 *
 * Purpose:       Copy array of bytes
 *
 * Inputs:        arg1    start adresse source
 *                arg2    end adresse source
 *                arg3    start adresse destination
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void asm_copy_byte(uint32_t arg1, uint32_t arg2, uint32_t arg3);

#endif /* COPY_FUNCTION_H */

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
  conditions set forth in the �Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (�Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer�s own risk.

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

