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
*   VERSION     : $Revision: 1.5 $
*   DATE        : $Date: 2015/05/04 09:07:17 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "listmngr.h"
#include "gf.h"
#include "ga.h"
#include "gfunctions.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define MW_LISTMNGR_C_REVISION     "$Revision: 1.5 $"
#define MW_LISTMNGR_C_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8MW_LISTMNGR_C_REVISION[] = MW_LISTMNGR_C_REVISION;
static uint8_t au8MW_LISTMNGR_C_TAG[]      = MW_LISTMNGR_C_TAG;
static uint8_t au8MW_LISTMNGR_H_REVISION[] = MW_LISTMNGR_H_REVISION;
static uint8_t au8MW_LISTMNGR_H_TAG[]      = MW_LISTMNGR_H_TAG;

/*********************************************/

/**********************************************
*         External variables                  *
**********************************************/ 
/* Command-Lists */
extern ga_list_st stList1;
extern ga_list_st stList2;

/*********************************************/

/**********************************************
*              Global variables               *
**********************************************/ 
/* Pointer to the list that is being executed by the GA */
ga_list_st* pstExecList = 0;

/* Pointer to the list that is being written by the software  */
ga_list_st* pstWriteList = 0;

/*********************************************/

/**********************************************
*             Function definition             *
**********************************************/

/****************************************************************************/

void vGf_Listmngr_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                             uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
    *pau8ModuleRevision = &au8MW_LISTMNGR_C_REVISION[0];
    *pau8ModuleTag      = &au8MW_LISTMNGR_C_TAG[0];
    *pau8HeaderRevision = &au8MW_LISTMNGR_H_REVISION[0];
    *pau8HeaderTag      = &au8MW_LISTMNGR_H_TAG[0];
}


/****************************************************************************/

void vGfListInit(void)
{
    /* Assign the actual lists to the pointers */
    pstExecList  = &stList1;
    pstWriteList = &stList2;

    /* Reset Both lists */
    vGA_ResetList(pstExecList);
    vGA_ResetList(pstWriteList);
}


/****************************************************************************/

void vGfStartListExecution(void)
{
    ga_list_st* pstTempList=0;

    /* Closing the Write list (safety measure) */
    vGA_CloseList(pstWriteList);

    /* Switch Write and Exec lists */
    pstTempList  = pstExecList;
    pstExecList  = pstWriteList;
    pstWriteList = pstTempList;

    /* Start the execution of new Exec list */
    vGA_SetCmdListAddr((uint32_t) (pstExecList->ullCommands));

    /* Reset the new Write list */
    vGA_ResetList(pstWriteList);
}


/****************************************************************************/

void vGfListExecute(void)
{
    ga_list_st* pstTempList=0;

    /* Wait on GA to complete the current list */
    vGfWaitForGA();
    
    /* Closing the Write list (safety measure) */
    vGA_CloseList(pstWriteList);

    /* Switch Write and Exec lists */
    pstTempList  = pstExecList;
    pstExecList  = pstWriteList;
    pstWriteList = pstTempList;

    /* Start the execution of new Exec list */
    vGA_SetCmdListAddr((uint32_t) (pstExecList->ullCommands));

    /* Reset the new Write list */
    vGA_ResetList(pstWriteList);
}


/****************************************************************************/

void vGfListResetAll(void)
{
    /* Reset Both lists */
    vGA_ResetList(pstExecList);
    vGA_ResetList(pstWriteList);
}


/****************************************************************************/

ga_list_st* pstGfListGetExec(void)
{
    return pstExecList;
}


/****************************************************************************/

ga_list_st* pstGfListGetWrite(void)
{
    return pstWriteList;
}


/****************************************************************************/

void vGfListWaitToComplete(void)
{
    /* Wait on GA to complete the current list */
    vGfWaitForGA();
}

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
