/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : WDT low level driver header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : WDT
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.6 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef _WDT_H
#define _WDT_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_WDT_H_REVISION     "$Revision: 1.6 $"
#define LLDD_WDT_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/* watchdog commands */
typedef enum tag_wdt_command_e
{
    WDT_STOP_AND_CLEAR = 0x5354,    /* stop and clear command */
    WDT_CLEAR          = 0x4352     /* clear command */
} wdt_command_e;

/* watchdog commands */
typedef enum tag_wdt_enable_e
{
    WDT_ENABLE = 0,    /* start WDT */
    WDT_DISABLE        /* stop WDT */
} wdt_enable_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/
/* watchdog configuration structure */
typedef struct tag_wdt_config_st
{
    uint32_t u32CountValue;    /* Reference counter value */
    uint32_t u32LowerLimit;    /* Lower window limit (MIN value) */
    uint32_t u32UpperLimit;    /* Upper window limit (MAX value) */
} wdt_config_st;

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
 * Function:      vWDT_GetVersion
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
void vWDT_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      vWDT_SetCounterValue
 *
 * Purpose:       Set Counter value
 *
 * Inputs:        u32Value     Counter value to be set
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vWDT_SetCounterValue(uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32WDT_GetCounterValue
 *
 * Purpose:       Get Counter value
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Counter value
 *
 * Limitations:
 *
 ***************************************************************************/
uint32_t u32WDT_GetCounterValue(void);

/****************************************************************************
 *
 * Function:      vWDT_SetLowerLimit
 *
 * Purpose:       Set lower limit compare value
 *
 * Inputs:        u32Value     Lower limit compare value to be set
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vWDT_SetLowerLimit(uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32WDT_GetLowerLimit
 *
 * Purpose:       Get lower limit compare value
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Lower limit compare value
 *
 * Limitations:
 *
 ***************************************************************************/
uint32_t u32WDT_GetLowerLimit(void);

/****************************************************************************
 *
 * Function:      vWDT_SetUpperLimit
 *
 * Purpose:       Set upper limit compare value
 *
 * Inputs:        u32Value     Upper limit compare value to be set
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vWDT_SetUpperLimit(uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32WDT_GetUppererLimit
 *
 * Purpose:       Get upper limit compare value
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Upper limit compare value
 *
 * Limitations:
 *
 ***************************************************************************/
uint32_t u32WDT_GetUppererLimit(void);

/****************************************************************************
 *
 * Function:      vWDT_Enable
 *
 * Purpose:       Enable / disable WDT
 *
 * Inputs:        eEn     WDT_ENABLE / WDT_DISABLE
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vWDT_Enable(wdt_enable_e eEn);

/****************************************************************************
 *
 * Function:      eWDT_CheckIfEnabled
 *
 * Purpose:       Check if WDT is enabled
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: WDT_ENABLE / WDT_DISABLE
 *
 * Limitations:
 *
 ***************************************************************************/
wdt_enable_e eWDT_CheckIfEnabled(void);

/****************************************************************************
 *
 * Function:      vWDT_SetCommand
 *
 * Purpose:       Set command
 *
 * Inputs:        eCommand     Command
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vWDT_SetCommand(wdt_command_e eCommand);


/****************************************************************************
 *
 * Function:      vWDT_Config
 *
 * Purpose:       Set configuration of WDT
 *
 * Inputs:        stConfig     Cofiguration values
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vWDT_Config(wdt_config_st stConfig);

/****************************************************************************/


#endif /* _WDT_H */

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

