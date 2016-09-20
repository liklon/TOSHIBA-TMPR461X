/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: config.h,v $
*   Description :
******************************************************************************
*   PROJECT     : Capricorn
*   MODULE      : config
*               : $Name:  $
*   LIBRARIES   :
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.1 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/05/09 14:05:53 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Basic_Graphics_Keil/inc/config.h,v $
*   LOG:        : please have a look at the end of the file
*****************************************************************************/
#ifndef CONFIG_H
#define CONFIG_H

/*****************************************************************************************
*                Include files
*****************************************************************************************/
#include "mw_definitions.h"
#include "qspi.h"

/*****************************************************************************************
* select Drehbuch
* 0: 600-450, 1: 440, 2: 325, 3: 225
*****************************************************************************************/
#define DREHBUCH    (2)
/* select output device
* 0: monitor
* 1: displays
*****************************************************************************************/
#define OUTPUT_DEVICE    0

/*****************************************************************************************
* QSPI
* 1: S25FL032P
* 2: S25FL064P
*****************************************************************************************/
#define QSPI_DEVICE      (DEV_S25FL127P)

/*****************************************************************************************
* Parallel NOR
* 1: xxx
* 2: yyy
*****************************************************************************************/
#define NOR_DEVICE      1

/*****************************************************************************************
* NAND
* 1: xxx
* 2: yyy
*****************************************************************************************/
#define NAND_DEVICE      1

/*****************************************************************************************
* RAM
*  1: MT46H8M32LFB5-6
*  2: MT46H16M32LFB5-6
*  3: IS42S32800D-6
*****************************************************************************************/
#define RAM_DEVICE    2

/*****************************************************************************************
*                 D I S P L A Y   -   C O N F I G U R A T I O N
*****************************************************************************************/
/* enable GDC0 and / or GDC1 */
#define GDCx0		ON
#define GDCx1		OFF

/* TO DO: Set Resolution (QVGA_RES / HNTSC_RES / HVGA_RES / VGA_RES / WVGA_RES / WVGA_1_RES /
                          SVGA_RES / DVGA_RES / DVGA_1_RES / DVGA_1_RES_60) */
#define DISPLAY_RESOLUTION_0 CLAA088WA//WVGA_RES_50 //DAL 20151221
#define DISPLAY_RESOLUTION_1 QVGA_RES_60

/****************************************************************************************
*                        G D C 0  -   C O N F I G U R A T I O N
*****************************************************************************************/
/* TO DO: Enable Layers that you plan to use with GDC0 */
/* possible values: ON / OFF */
#define GDC0_LAYER_A 	ON
#define GDC0_LAYER_B 	OFF
#define GDC0_LAYER_C 	OFF
#define GDC0_LAYER_D 	OFF
#define GDC0_LAYER_E 	OFF

/* TO DO: Set color format for each layer */
/* possible values: FMT_OFF (only possible for layer A) / FMT_RGB16 / FMT_RGBA32 */
#define GDC0_LAYER_A_COLOR_FORMAT		FMT_RGBA32
#define GDC0_LAYER_B_COLOR_FORMAT		FMT_RGBA32
#define GDC0_LAYER_C_COLOR_FORMAT		FMT_RGBA32
#define GDC0_LAYER_D_COLOR_FORMAT		FMT_RGBA32
#define GDC0_LAYER_E_COLOR_FORMAT		FMT_RGBA32

/* TO DO: select doublebuffering for each layer */
/* possible values: ON / OFF */
#define GDC0_LAYER_A_DOUBLEFUFFERING		ON
#define GDC0_LAYER_B_DOUBLEFUFFERING		ON
#define GDC0_LAYER_C_DOUBLEFUFFERING		ON
#define GDC0_LAYER_D_DOUBLEFUFFERING		OFF
#define GDC0_LAYER_E_DOUBLEFUFFERING		OFF


/* TO DO: Set parameters for all layers that you enabled above. */
/* Layer A */
#define GDC0_LAYERA_WIDTH     1280
#define GDC0_LAYERA_HEIGHT    480
#define GDC0_LAYERA_STARTX      0
#define GDC0_LAYERA_STARTY      0

/* Layer B */
#define GDC0_LAYERB_WIDTH     400
#define GDC0_LAYERB_HEIGHT    400
#define GDC0_LAYERB_STARTX    550
#define GDC0_LAYERB_STARTY    20

/* Layer C */
#define GDC0_LAYERC_WIDTH     800
#define GDC0_LAYERC_HEIGHT    480
#define GDC0_LAYERC_STARTX      0
#define GDC0_LAYERC_STARTY      0

/* Layer D */
#define GDC0_LAYERD_WIDTH     800
#define GDC0_LAYERD_HEIGHT    480
#define GDC0_LAYERD_STARTX      0
#define GDC0_LAYERD_STARTY      0

/* Layer E */
#define GDC0_LAYERE_WIDTH     800
#define GDC0_LAYERE_HEIGHT    480
#define GDC0_LAYERE_STARTX      0
#define GDC0_LAYERE_STARTY      0


/****************************************************************************************
*                        G D C 1  -   C O N F I G U R A T I O N
*****************************************************************************************/
/* TO DO: Enable Layers that you plan to use with GDC1 */
/* possible values: ON / OFF */
#define GDC1_LAYER_A 	OFF
#define GDC1_LAYER_B 	OFF
#define GDC1_LAYER_C 	OFF
#define GDC1_LAYER_D 	OFF
#define GDC1_LAYER_E 	OFF

/* TO DO: Set color format for each layer */
/* possible values: FMT_OFF / FMT_RGB16 / FMT_RGBA32 */
#define GDC1_LAYER_A_COLOR_FORMAT		FMT_RGBA32
#define GDC1_LAYER_B_COLOR_FORMAT		FMT_RGBA32
#define GDC1_LAYER_C_COLOR_FORMAT		FMT_RGBA32
#define GDC1_LAYER_D_COLOR_FORMAT		FMT_RGBA32
#define GDC1_LAYER_E_COLOR_FORMAT		FMT_RGBA32

/* TO DO: select doublebuffering for each layer */
/* possible values: ON / OFF */
#define GDC1_LAYER_A_DOUBLEFUFFERING		ON
#define GDC1_LAYER_B_DOUBLEFUFFERING		ON
#define GDC1_LAYER_C_DOUBLEFUFFERING		ON
#define GDC1_LAYER_D_DOUBLEFUFFERING		ON
#define GDC1_LAYER_E_DOUBLEFUFFERING		ON



/* TO DO: Set parameters for all layers that you enabled above. */
/* Layer A */
#define GDC1_LAYERA_WIDTH     320
#define GDC1_LAYERA_HEIGHT    240
#define GDC1_LAYERA_STARTX      0
#define GDC1_LAYERA_STARTY      0

/* Layer B */
#define GDC1_LAYERB_WIDTH     640
#define GDC1_LAYERB_HEIGHT    480
#define GDC1_LAYERB_STARTX      0
#define GDC1_LAYERB_STARTY      0

/* Layer C */
#define GDC1_LAYERC_WIDTH	    640
#define GDC1_LAYERC_HEIGHT    480
#define GDC1_LAYERC_STARTX      0
#define GDC1_LAYERC_STARTY      0

/* Layer D */
#define GDC1_LAYERD_WIDTH     640
#define GDC1_LAYERD_HEIGHT    480
#define GDC1_LAYERD_STARTX      0
#define GDC1_LAYERD_STARTY      0

/* Layer E */
#define GDC1_LAYERE_WIDTH     640
#define GDC1_LAYERE_HEIGHT    480
#define GDC1_LAYERE_STARTX      0
#define GDC1_LAYERE_STARTY      0

#endif /* CONFIG_H */

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
* $Log: config.h,v $
* Revision 1.1  2014/05/09 14:05:53  mto
* initial version
*
*
*********************************** END OF LOG ******************************/
