/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Performance monitor unit routines based on ARM's V7 sample code
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TSM-SHE Firmware System Longrun Test (Cortex-R4)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.5 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef _CR4_PMU_H
#define _CR4_PMU_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                       /* Core specific primitive type definitions */

/*********************************************/


/**********************************************
*             Constants & Macros              *
**********************************************/

/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/

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
 * Function:      u32CR4_GetPMN
 *
 * Purpose:       Returns the number of progammable counters
 *
 * Inputs:        none
 *
 * Outputs:       Programmable counters count
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32CR4_GetPMN(void);


/****************************************************************************
 *
 * Function:      vCR4_PMNConfig
 *
 * Purpose:       Sets the event for a programmable counter to record
 *
 * Inputs:        u32Counter: Which counter to program  (e.g. 0 for PMN0, 1 for PMN1)
 *                u32Even:    The event code (ARM Architecture Reference Manual)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCR4_PMNConfig(uint32_t u32Counter, uint32_t u32Event);


/****************************************************************************
 *
 * Function:      vCR4_SetCntDivider
 *
 * Purpose:       Enables/disables the divider (1/64) on CCNT
 *
 * Inputs:        u32Divider: 0 - disable, all others enable
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCR4_SetCntDivider(uint32_t u32Divider);


/****************************************************************************
 *
 * Function:      vCR4_EnablePMU
 *
 * Purpose:       Global PMU enable
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
void vCR4_EnablePMU(void);


/****************************************************************************
 *
 * Function:      vCR4_DisablePMU
 *
 * Purpose:       Global PMU disable
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
void vCR4_DisablePMU(void);


 /****************************************************************************
 *
 * Function:      vCR4_EnableCCNT
 *
 * Purpose:       Enable the cycle counter (CCNT)
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
void vCR4_EnableCCNT(void);


/****************************************************************************
 *
 * Function:      vCR4_DisableCCNT
 *
 * Purpose:       Disable the cycle counter (CCNT)
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
void vCR4_DisableCCNT(void);


/****************************************************************************
 *
 * Function:      vCR4_EnablePMN
 *
 * Purpose:       Enable PMN{n}
 *
 * Inputs:        u32Counter: The counter to enable (e.g. 0 for PMN0, 1 for PMN1)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCR4_EnablePMN(uint32_t u32Counter);


/****************************************************************************
 *
 * Function:      vCR4_DisablePMN
 *
 * Purpose:       Disable PMN{n}
 *
 * Inputs:        u32Counter: The counter to disable (e.g. 0 for PMN0, 1 for PMN1)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCR4_DisablePMN(uint32_t u32Counter);


/****************************************************************************
 *
 * Function:      uCR4_32ReadCCNT
 *
 * Purpose:       Returns the value of CCNT
 *
 * Inputs:        none
 *
 * Outputs:       Cycle counter value
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32CR4_ReadCCNT(void);


/****************************************************************************
 *
 * Function:      u32CR4_ReadPMN
 *
 * Purpose:       Returns the value of PMN{n}
 *
 * Inputs:        u32Counter: The counter to read (e.g. 0 for PMN0, 1 for PMN1)
 *
 * Outputs:       PMNn counter
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32CR4_ReadPMN(uint32_t u32Counter);


/****************************************************************************
 *
 * Function:      u32CR4_ReadFlags
 *
 * Purpose:       Returns the value of the overflow flags
 *
 * Inputs:        none
 *
 * Outputs:       Overflow flags
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32CR4_ReadFlags(void);


/****************************************************************************
 *
 * Function:      vCR4_WriteFlags
 *
 * Purpose:       Writes the overflow flags
 *
 * Inputs:        u32Flags: flags to write
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCR4_WriteFlags(uint32_t u32Flags);


/****************************************************************************
 *
 * Function:      vCR4_EnableCCNTIrq
 *
 * Purpose:       Enables interrupt generation on overflow of the CCNT
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
void vCR4_EnableCCNTIrq(void);


/****************************************************************************
 *
 * Function:      vCR4_DisableCCNTIrq
 *
 * Purpose:       Disables interrupt generation on overflow of the CCNT
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
void vCR4_DisableCCNTIrq(void);


/****************************************************************************
 *
 * Function:      vCR4_EnablePmnIrq
 *
 * Purpose:       Enables interrupt generation on overflow of PMN{x}
 *
 * Inputs:        u32Counter: The counter to enable the interrupt for (e.g. 0 for PMN0, 1 for PMN1)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCR4_EnablePmnIrq(uint32_t u32Counter);


/****************************************************************************
 *
 * Function:      vCR4_DisablePMNIrq
 *
 * Purpose:       Disables interrupt generation on overflow of PMN{x}
 *
 * Inputs:        u32Counter: The counter to disable the interrupt for (e.g. 0 for PMN0, 1 for PMN1)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCR4_DisablePMNIrq(uint32_t u32Counter);


/****************************************************************************
 *
 * Function:      vCR4_ResetPMN
 *
 * Purpose:       Resets the programmable counters
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
void vCR4_ResetPMN(void);


/****************************************************************************
 *
 * Function:      vCR4_ResetPMN
 *
 * Purpose:       Resets the CCNT
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
void vCR4_ResetCCNT(void);


/****************************************************************************
 *
 * Function:      vCR4_ResetPMN
 *
 * Purpose:       Writes to software increment register
 *
 * Inputs:        u32Counter: The counter to increment (e.g. 0 for PMN0, 1 for PMN1)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCR4_PMUSoftwareIncrement(uint32_t u32Counter);


/****************************************************************************
 *
 * Function:      vCR4_EnablePMUUserAccess
 *
 * Purpose:       Enables User mode access to the PMU (must be called in a priviledged mode)
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
void vCR4_EnablePMUUserAccess(void);


/****************************************************************************
 *
 * Function:      vCR4_DisablePMUUserAccess
 *
 * Purpose:       Disables User mode access to the PMU (must be called in a priviledged mode)
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
void vCR4_DisablePMUUserAccess(void);


#endif /* _CR4_PMU_H */

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
  conditions set forth in the Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (Unintended Usage).
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

