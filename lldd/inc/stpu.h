/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Stpu
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : STPU
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.7 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef STPU_H
#define STPU_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_STPU_H_REVISION     "$Revision: 1.7 $"
#define LLDD_STPU_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/* stpu device no. */
typedef enum tag_stpu_dev_e
{
   STPU0 = 0,                              /* stpu device #0 */
   STPU1 = 1,                              /* stpu device #1 */
   STPU2 = 2,                              /* stpu device #2 */
   STPU3 = 3,                              /* stpu device #3 */
   STPU4 = 4,                              /* stpu device #4 */
   STPU5 = 5,                              /* stpu device #5 */
   STPU6 = 6,                              /* stpu device #6 */
   STPU7 = 7                               /* stpu device #7 */
} stpu_dev_e;

/* enable */
typedef enum tag_stpu_enable_e
{
   STPU_DIS = 0,                           /* disable */
   STPU_EN  = 1                            /* enable  */
} stpu_enable_e;

/* Timer mode operation */
typedef enum tag_stpu_timer_mode_e
{
   STPU_MODE_0 = 0,                        /* timer mode 0 */
   STPU_MODE_1 = 1,                        /* timer mode 1  */
   STPU_MODE_2 = 2,                        /* timer mode 2  */
   STPU_MODE_3 = 3                         /* timer mode 3  */
} stpu_timer_mode_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/
/* Timer config */
typedef struct tag_stpu_timer_config_st
{
   stpu_timer_mode_e eTimerMode;           /* timer mode */
   stpu_enable_e     ePreloadEnable;       /* preload enable  */
   uint32_t          u32TimerBudgetValue;  /* timer budget value */
} stpu_timer_config_st;

/* Common prescaler config */
typedef struct tag_stpu_common_prescaler_config_st
{
   uint8_t           u8CommonPrescalerValue;  /* common prescaler value */
   stpu_enable_e     eCommonPrescalerEnable;  /* common prescaler enable  */
} stpu_common_prescaler_config_st;

/*********************************************/

/**********************************************
*            Forward declarations             *
**********************************************/

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vSTPU_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8IORevision     - pointer to IO header revision string
 *                pau8IOTag          - pointer to IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSTPU_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      u32STPU_GetVersion
 *
 * Purpose:       Return STPU module version number
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: STPU module version number
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32STPU_GetVersion(void);

/****************************************************************************
 *
 * Function:      vSTPU_ConfigureCommonPrescaler
 *
 * Purpose:       Configure common prescaler
 *
 * Inputs:        stConfig    Configuration of common prescaler
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSTPU_ConfigureCommonPrescaler(stpu_common_prescaler_config_st stConfig);

/****************************************************************************
 *
 * Function:      vSTPU_EnableInterrupt
 *
 * Purpose:       Enable/disable interrupt
 *
 * Inputs:        eEn    Enable/disable interrupt
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSTPU_EnableInterrupt(stpu_enable_e eEn);

/****************************************************************************
 *
 * Function:      vSTPU_EnableDiagnosisMode
 *
 * Purpose:       Enable/disable diagnosis mode
 *
 * Inputs:        eEn    Enable/disable diagnosis mode
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSTPU_EnableDiagnosisMode(stpu_enable_e eEn);

/****************************************************************************
 *
 * Function:      u32STPU_GetTimerStatusBits
 *
 * Purpose:       Read timer status
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Timer status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32STPU_GetTimerStatusBits(void);

/****************************************************************************
 *
 * Function:      vSTPU_DisableInterrupts
 *
 * Purpose:       Disable interrupt
 *
 * Inputs:        u32Value    Disable interrupt mask
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSTPU_DisableInterrupts(uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32STPU_GetInterruptStatusBits
 *
 * Purpose:       Read interrupt status
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Interrupt status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32STPU_GetInterruptStatusBits(void);

/****************************************************************************
 *
 * Function:      vSTPU_EnableInterrupts
 *
 * Purpose:       Enable interrupts
 *
 * Inputs:        u32Value    Enable interrupts mask
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSTPU_EnableInterrupts(uint32_t u32Value);

/****************************************************************************
 *
 * Function:      vSTPU_ClearInterrupts
 *
 * Purpose:       Clear interrupts
 *
 * Inputs:        u32Value    Clear interrupts mask
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSTPU_ClearInterrupts(uint32_t u32Value);

/****************************************************************************
 *
 * Function:      i32STPU_Continue
 *
 * Purpose:       Continue timer
 *
 * Inputs:        eDevice     Timer number
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32STPU_Continue(stpu_dev_e eDevice);

/****************************************************************************
 *
 * Function:      i32STPU_Stop
 *
 * Purpose:       Stop timer
 *
 * Inputs:        eDevice     Timer number
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32STPU_Stop(stpu_dev_e eDevice);

/****************************************************************************
 *
 * Function:      i32STPU_Start
 *
 * Purpose:       Start timer
 *
 * Inputs:        eDevice     Timer number
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32STPU_Start(stpu_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSTPU_Configure
 *
 * Purpose:       Configure timer
 *
 * Inputs:        eDevice     Timer number
 *                stConfig    Timer configuration
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSTPU_Configure(stpu_dev_e eDevice, stpu_timer_config_st stConfig);

/****************************************************************************
 *
 * Function:      u32STPU_GetTimerValue
 *
 * Purpose:       read timer value
 *
 * Inputs:        eDevice     Timer number
 *
 * Outputs:       none
 *
 * Return Values: timer value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32STPU_GetTimerValue(stpu_dev_e eDevice);

/****************************************************************************/


#endif /* STPU_H */

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

