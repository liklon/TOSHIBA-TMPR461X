/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Middleware listmanagement
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.7 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef LISTMNGR_H
#define LISTMNGR_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "ga_common.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define MW_LISTMNGR_H_REVISION     "$Revision: 1.7 $"
#define MW_LISTMNGR_H_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/


/**********************************************
*            External variables               *
**********************************************/

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/**
* @brief List status
*/
typedef enum tag_lst_status_e
{
    LIST_INUSE    = 0x0U,               /*!< List used by the GA */
    LIST_FINISH   = 0x1U                /*!< List not used by GA */
} lst_status_e;

/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/


/*********************************************/


/**********************************************
*            Function prototypes              *
**********************************************/

/**
* @brief Implementation of function vGf_Listmngr_GetVersion
*
* Retrieve pointers to module and header revision and tag string
*
* @note none
*
* @param[in,out] pau8ModuleRevision - pointer to module revision string
* @param[in,out] pau8ModuleTag      - pointer to module tag string
* @param[in,out] pau8HeaderRevision - pointer to header revision string
* @param[in,out] pau8HeaderTag      - pointer to header tag string
*
* @return void
*/
void vGf_Listmngr_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                             uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);


/**
* @brief Implementation of function vGfInitList
*
* Initializes the GA lists
*
* @note This function needs to be called before any other from this file.
*
* @return void
*/
void vGfListInit(void);


/**
* @brief Implementation of function vGfStartListExecution
*
* Sends the current list to the GA and performs the switching
* between the active and inactive lists. The list will be closed
* automatically by this function.
*
* @note none
*
* @return void
*/
void vGfStartListExecution(void);


/**
* @brief Implementation of function vGfListExecute
*
* Wait till the previous list is executed and the GA is ready.
* Sends the current list to the GA and performs the switching
* between the active and inactive lists. The list will be closed
* automatically by this function.
*
* @note none
*
* @return void
*/
void vGfListExecute(void);


/**
* @brief Implementation of function vGfListResetAll
*
* Resets both GA lists.
*
* @note none
*
* @return void
*/
void vGfListResetAll(void);


/**
* @brief Implementation of function pstGfListGetExec
*
* Returns the pointer to the list currently currently being
* executed by the GA.
*
* @note none
*
* @return Pointer to the list currently being executed by GA.
*/
ga_list_st* pstGfListGetExec(void);


/**
* @brief Implementation of function pstGfListGetWrite
*
* Returns the pointer to the list currently currently being
* written by the software.
*
* @note none
*
* @return Pointer to the list currently being written by SW.
*/
ga_list_st* pstGfListGetWrite(void);


/**
* @brief Implementation of function vGfListWaitToComplete
*
* This function waits on GA to execute the current list.
*
* @note none
*
* @return void
*/
void vGfListWaitToComplete(void);


/***************************************************************************/


#endif /* LISTMNGR_H */

/***************************************************************************/


/************************* BEGIN of DISCLAIMER   *****************************

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

****************************  END of DISCLAIMER *****************************/
