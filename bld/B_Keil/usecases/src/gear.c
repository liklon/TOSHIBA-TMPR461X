/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: gear.c,v $
*   Description : Gear
******************************************************************************
*   PROJECT     : Capricorn_Bt
*   MODULE      : Application
*               : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.1 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/05/09 14:05:53 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Basic_Graphics_Keil/usecases/src/gear.c,v $
*   LOG:        : please have a look at the end of the file
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"        /* Core specific primitive type definitions */
#include "listmngr.h"
#include "gfunctions.h"
#include "images_defs.h"
#include "images_externs.h"
#include "statevariables.h"
#include "gear.h"

/**********************************************
*             Constants & Macros              *
**********************************************/
#define GEAR_NORMAL_POSX (10)
#define GEAR_NORMAL_POSY (15)
#define GEAR_SHADOW_POSX (GEAR_NORMAL_POSX)
#define GEAR_SHADOW_POSY (GEAR_NORMAL_POSY + 31)

/**********************************************
*                Variables                    *
**********************************************/


/**********************************************
*             Function definition             *
**********************************************/
void vInitGear(void)
{
    /* set gear on main */
    vGfLayerBlendBitmapRLE32(&stImage_gear[0][0], &stGDC1LayerA, GEAR_NORMAL_POSX, GEAR_NORMAL_POSY);
    vGfListExecute();

    /* set gear shadow on main */
    vGfLayerBlendBitmapRLE32(&stImage_gear[0][1], &stGDC1LayerA, GEAR_SHADOW_POSX, GEAR_SHADOW_POSY);
    vGfListExecute();
}


/****************************************************************************/

void vSetGear(void)
{
    static uint16_t u16GearInc = 0;
    static uint8_t u8Direction = 0;

    gf_cliprect_st stPart;
    static uint8_t u8GearPointer = 0;

    if (stStatevariables.u8Animate == 1)
    {
	u16GearInc = u16GearInc + 1;
	if (u16GearInc == 50)
	{
	    u16GearInc = 0;
	    
	    if (u8Direction == 0)
	    {
		stStatevariables.u16GearType = stStatevariables.u16GearType + 1;
		if (stStatevariables.u16GearType >= 4)
		{
		    u8Direction = 1;
		    stStatevariables.u16GearType = 4;
		}
	    }
	    else
	    {
		if (stStatevariables.u16GearType >= 1)
		{
		    stStatevariables.u16GearType = stStatevariables.u16GearType - 1;
		}
		else
		{
		    stStatevariables.u16GearType = 0;
		    u8Direction = 0;
		}
	    }
	}
    }

    if (stStatevariables.u16GearType != stStatevariables.u16GearTypeold)
    {
        /* erase old gear */
        stPart.u16SrcOffsX = GEAR_NORMAL_POSX;
        stPart.u16SrcOffsY = GEAR_NORMAL_POSY;
        stPart.u16Width    = stImage_gear[0][0].u16Width;
        stPart.u16Height   = stImage_gear[0][0].u16Height;
        vGfLayerFillArea(&stGDC1LayerA, &stPart, BACKGROUND_COLOR_1);
        vGfListExecute();

        /* erase old reflection */
        stPart.u16SrcOffsX = GEAR_SHADOW_POSX;
        stPart.u16SrcOffsY = GEAR_SHADOW_POSY;
        stPart.u16Width    = stImage_gear[0][1].u16Width;
        stPart.u16Height   = stImage_gear[0][1].u16Height;
        vGfLayerFillArea(&stGDC1LayerA, &stPart, BACKGROUND_COLOR_1);
        vGfListExecute();

        if (stStatevariables.u8GearToggle == 0)
        {
            if (stStatevariables.u16GearType > stStatevariables.u16GearTypeold)
            {
                u8GearPointer = GEAR_INTER_STEPS * (stStatevariables.u16GearType-1);
            }
            else
            {
                u8GearPointer = GEAR_INTER_STEPS * (stStatevariables.u16GearType+1);
            }
        }
        if (stStatevariables.u8GearToggle < GEAR_INTER_STEPS)
        {
            if (stStatevariables.u16GearType > stStatevariables.u16GearTypeold)
            {
                u8GearPointer = u8GearPointer + 1;
            }
            else
            {
	        u8GearPointer = u8GearPointer - 1;
	    }
        }

        /* draw gear main */
        vGfLayerBlendBitmapRLE32(&stImage_gear[u8GearPointer][0], &stGDC1LayerA, GEAR_NORMAL_POSX, GEAR_NORMAL_POSY);
        vGfListExecute();

        /* draw reflection main */
        vGfLayerBlendBitmapRLE32(&stImage_gear[u8GearPointer][1], &stGDC1LayerA, GEAR_SHADOW_POSX, GEAR_SHADOW_POSY);
        vGfListExecute();

	/* control */
	if (stStatevariables.u8GearToggle < GEAR_INTER_STEPS)
	{
	    stStatevariables.u8GearToggle = stStatevariables.u8GearToggle + 1;
	}
	else
	{
	    stStatevariables.u8GearToggle = 0;
	    stStatevariables.u16GearTypeold = stStatevariables.u16GearType;
	}
    }
}

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
* $Log: gear.c,v $
* Revision 1.1  2014/05/09 14:05:53  mto
* initial version
*
*
*********************************** END OF LOG ******************************/
