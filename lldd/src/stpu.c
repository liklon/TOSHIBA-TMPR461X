/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Stpu
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : 
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.6 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "stpu_io.h"                   /* stepper_motor registers, bits and access macros defintion */
#include "stpu.h"                      /* Own definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_STPU_C_REVISION     "$Revision: 1.6 $"
#define LLDD_STPU_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8LLDD_STPU_C_REVISION[]    = LLDD_STPU_C_REVISION;
static uint8_t au8LLDD_STPU_C_TAG[]         = LLDD_STPU_C_TAG;
static uint8_t au8LLDD_STPU_H_REVISION[]    = LLDD_STPU_H_REVISION;
static uint8_t au8LLDD_STPU_H_TAG[]         = LLDD_STPU_H_TAG;
static uint8_t au8LLDD_STPU_IO_H_REVISION[] = LLDD_STPU_IO_H_REVISION;
static uint8_t au8LLDD_STPU_IO_H_TAG[]      = LLDD_STPU_IO_H_TAG;

/*********************************************/

/**********************************************
*             Function definition             *
**********************************************/

void vSTPU_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_STPU_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_STPU_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_STPU_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_STPU_H_TAG[0];
   *pau8IORevision     = &au8LLDD_STPU_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_STPU_IO_H_TAG[0];
}


/****************************************************************************/
uint32_t u32STPU_GetVersion(void)
{
    return u32GetSTPU_TMRVER();
}


/****************************************************************************/
void vSTPU_ConfigureCommonPrescaler(stpu_common_prescaler_config_st stConfig)
{
    vSetSTPU_CFG_CMPRSCLR(stConfig.u8CommonPrescalerValue);
    vSetSTPU_CFG_CMPRSCLREN(stConfig.eCommonPrescalerEnable);
}


/****************************************************************************/
void vSTPU_EnableInterrupt(stpu_enable_e eEn)
{
    vSetSTPU_CFG_INTREN(eEn);
}


/****************************************************************************/
void vSTPU_EnableDiagnosisMode(stpu_enable_e eEn)
{
    vSetSTPU_CFG_DIGNMDEN(eEn);
}


/****************************************************************************/
uint32_t u32STPU_GetTimerStatusBits(void)
{
    return biGetSTPU_TMRST_IST();
}


/****************************************************************************/
void vSTPU_DisableInterrupts(uint32_t u32Value)
{
    vSetSTPU_TMRINTDS_INTD(u32Value);
}


/****************************************************************************/
uint32_t u32STPU_GetInterruptStatusBits(void)
{
    return biGetSTPU_TMRINTRST_INTST();
}


/****************************************************************************/
void vSTPU_EnableInterrupts(uint32_t u32Value)
{
    vSetSTPU_TMRINTREN_IEN(u32Value);
}


/****************************************************************************/
void vSTPU_ClearInterrupts(uint32_t u32Value)
{
    vSetSTPU_TMRINTRCL_ICL(u32Value);
}


/****************************************************************************/
int32_t i32STPU_Continue(stpu_dev_e eDevice)
{
    int32_t i32Res = C_SUCCESS;

    if (eDevice <= STPU7)
    {
        vSetSTPU_TMRCTRL_CON(eDevice, 1);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32STPU_Stop(stpu_dev_e eDevice)
{
    int32_t i32Res = C_SUCCESS;

    if (eDevice <= STPU7)
    {
        vSetSTPU_TMRCTRL_STP(eDevice, 1);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32STPU_Start(stpu_dev_e eDevice)
{
    int32_t i32Res = C_SUCCESS;

    if (eDevice <= STPU7)
    {
        vSetSTPU_TMRCTRL_STR(eDevice, 1);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
void vSTPU_Configure(stpu_dev_e eDevice, stpu_timer_config_st stConfig)
{
    vSetSTPU_TMRMDCTRL_TMRMD(eDevice, stConfig.eTimerMode);
    vSetSTPU_TMRMDCTRL_TMRPRLD(eDevice, stConfig.ePreloadEnable);
    vSetSTPU_TMRBTPL_BTPL(eDevice, stConfig.u32TimerBudgetValue);
}


/****************************************************************************/
uint32_t u32STPU_GetTimerValue(stpu_dev_e eDevice)
{
    return biGetSTPU_TMRCCV_TMRCCV(eDevice);
}

/****************************************************************************/

/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: stpu.c
**  $Revision: 1.6 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :  5 (0286) String literal contains character which is not a
** |                    member of the basic source character set.
** |           5 (0288) Source file '<TEXT>' has comments containing characters
** |                    which are not members of the basic source character set.
** |          22 (3218) File scope static, '<TEXT>', only accessed in one
** |                    function.
** |          45 (0303) Cast between a pointer to volatile object and an
** |                    integral type.
** |          52 (1503) The function '%1s' is defined but is not used within
** |                    this project.
** |
** | REASON : This is neccessary because of driver version control.
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/

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

