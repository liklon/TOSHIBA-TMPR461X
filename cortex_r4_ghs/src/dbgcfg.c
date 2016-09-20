/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: dbgcfg.c,v $
*   Description : Debug configuration & initialization routines
******************************************************************************
*   PROJECT     : Capricorn
*   MODULE      : System
*               : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.1 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2013-09-24 06:50:46 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/cortex_r4_ghs/src/dbgcfg.c,v $
*   LOG:        : please have a look at the end of the file
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                    /* Core specific primitive type definitions */
#include "dbgcfg.h"                       /* Own definitions and prototypes */

/*********************************************/


/**********************************************
*             Constants & Macros              *
**********************************************/

/* 
 *  IO symbols must be declared as weak, to prevent the 
 *  linker warnings, if the GHS libraries are not used
 */
#pragma weak __gh_iob_init
extern void __gh_iob_init(void);
static void (*const iob_init_funcp)(void) = __gh_iob_init;


/**********************************************
*             Function definition             *
**********************************************/

/***************************************************************************/
/* Intialize the MULTI debugger I/O system */
static void vGhsDbgIOInit(bool_t tEnable)
{
    /* Only one initialization will be allowed */
    static bool_t tInitialzed = C_FALSE;

    /* "Singleton" initialization */
    if( C_FALSE == tInitialzed )
    {
        tInitialzed = C_TRUE;
        /* C_TRUE - enable, C_FALSE - disable */
        if( C_TRUE == tEnable )
        {                       
            /* 
             *  if ind_iob.c is loaded, initialize _iob for stdin, stdout, stderr 
             *  Note: Without this intialization fragment the printf() to the 
             *  debugger won't work
             */
            if( iob_init_funcp )
            {
                __gh_iob_init();
            }
        }
    }
}



/***************************************************************************/


/* Main debug configuration entry point */
void vDebugCfg(void)
{
    /* Enable the debug output */
    vGhsDbgIOInit(C_TRUE);
}


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

/********************************* BEGIN OF LOG ******************************
*
* $Log: dbgcfg.c,v $
* Revision 1.1  2013-09-24 06:50:46  mto
* initial version (moved from projects to general location)
*
*
*********************************** END OF LOG ******************************/
