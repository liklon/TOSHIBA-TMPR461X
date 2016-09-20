/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Standard core access utilities definitions
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Core
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.11 $
*   DATE        : $Date: 2015/05/04 09:07:19 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef CORE_H
#define CORE_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                     /* Core specific primitive type definitions */
#include "cr4_pmu.h"

/*********************************************/


/**********************************************
*             Constants & Macros              *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1862  /* Rule 19.7 : disable function-like macro not allowed */
#endif
/**********************************************/

/* Physical translation in un-cached area */
#define PHYSICAL_ADDR_MASK                  0xFFFFFFFFU
#define PHYSICAL(addr)                      (((uint32_t)(addr) & PHYSICAL_ADDR_MASK))

/* copy function */
#define asm_copyfunction                    (asm_copy_word)
#define asm_copyfunction_hword              (asm_copy_hword)
#define asm_copyfunction_byte               (asm_copy_byte)

/* PMU enable */
#define PMU_ENABLE()                        (vCR4_EnablePMU())

/* Timer Enable */
#define TIMER_ENABLE()                      (vCR4_EnableCCNT())

/* Timer Reset */
#define TIMER_RESET()                       (vCR4_ResetCCNT())

/* Timer Get */
#define TIMER_GET()                         (u32CR4_ReadCCNT())

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
 * Function:      __DSB
 *
 * Purpose:       Data barrier
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void __DSB(void);


/****************************************************************************
 *
 * Function:      __ISB
 *
 * Purpose:       Instruction barrier
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void __ISB(void);


/****************************************************************************
 *
 * Function:      asm_enable_core_int
 *
 * Purpose:       Enable core interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void asm_enable_core_int(void);


/****************************************************************************
 *
 * Function:      asm_disable_core_int
 *
 * Purpose:       Disable core interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void asm_disable_core_int(void);


/****************************************************************************
 *
 * Function:      asm_enable_core_fast_int
 *
 * Purpose:       Enable core fast interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void asm_enable_core_fast_int(void);


/****************************************************************************
 *
 * Function:      asm_disable_core_fast_int
 *
 * Purpose:       Disable core fast interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void asm_disable_core_fast_int(void);


/****************************************************************************
 *
 * Function:      asm_enable_core_vic_port
 *
 * Purpose:       Enable VIC port
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void asm_enable_core_vic_port(void);


/****************************************************************************
 *
 * Function:      asm_disable_core_vic_port
 *
 * Purpose:       Disable VIC port
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void asm_disable_core_vic_port(void);


#endif /* CORE_H */

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

