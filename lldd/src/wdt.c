/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : WDT low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : WDT
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "wdt_io.h"                   /* WDT registers, bits and access macros defintion */
#include "wdt.h"                      /* Own definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_WDT_C_REVISION     "$Revision: 1.8 $"
#define LLDD_WDT_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8LLDD_WDT_C_REVISION[]    = LLDD_WDT_C_REVISION;
static uint8_t au8LLDD_WDT_C_TAG[]         = LLDD_WDT_C_TAG;
static uint8_t au8LLDD_WDT_H_REVISION[]    = LLDD_WDT_H_REVISION;
static uint8_t au8LLDD_WDT_H_TAG[]         = LLDD_WDT_H_TAG;
static uint8_t au8LLDD_WDT_IO_H_REVISION[] = LLDD_WDT_IO_H_REVISION;
static uint8_t au8LLDD_WDT_IO_H_TAG[]      = LLDD_WDT_IO_H_TAG;

/*********************************************/

/**********************************************
*             Function definition             *
**********************************************/

void vWDT_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_WDT_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_WDT_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_WDT_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_WDT_H_TAG[0];
   *pau8IORevision     = &au8LLDD_WDT_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_WDT_IO_H_TAG[0];
}


/****************************************************************************/
uint32_t u32WDT_GetCounterValue(void)
{
    return u32GetCNT();
}


/****************************************************************************/
void vWDT_SetLowerLimit(uint32_t u32Value)
{
    vSetMIN(u32Value);
}


/****************************************************************************/
uint32_t u32WDT_GetLowerLimit(void)
{
    return u32GetMIN();
}


/****************************************************************************/
void vWDT_SetUpperLimit(uint32_t u32Value)
{
    vSetMAX(u32Value);
}


/****************************************************************************/
uint32_t u32WDT_GetUppererLimit(void)
{
    return u32GetMAX();
}


/****************************************************************************/
void vWDT_Enable(wdt_enable_e eEn)
{
    vSetCTL_WDTDIS(eEn);
}


/****************************************************************************/
wdt_enable_e eWDT_CheckIfEnabled(void)
{
    return (wdt_enable_e)biGetCTL_WDTDIS();
}


/****************************************************************************/
void vWDT_SetCommand(wdt_command_e eCommand)
{
    vSetCMD_CMD(eCommand);
}


/****************************************************************************/
void vWDT_Config(wdt_config_st stConfig)
{
    vSetMIN(stConfig.u32LowerLimit);
    vSetMAX(stConfig.u32UpperLimit);
}

/****************************************************************************/


/****************************************************************************/

/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: wdt.c
**  $Revision: 1.8 $
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

