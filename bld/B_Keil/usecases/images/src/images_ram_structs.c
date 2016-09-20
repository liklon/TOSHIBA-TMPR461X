/*****************************************************************************
*   This software is copyright protected. All rights reserved 
*   Toshiba Electronics Europe GmbH 
*   European LSI Design and Engineering Center (ELDEC)
****************************************************************************** 
*   File Name   : $RCSfile: $ 
*   Description : Image file
****************************************************************************** 
*   PROJECT     : Capricorn 
*   MODULE      : Graphics 
*               : $Name: $ 
*   LIBRARIES   : None 
*   AUTHOR      : $Author: $
****************************************************************************** 
*   VERSION     : $Revision: $ 
*   RELEASE     : Preliminary & Confidential 
*   DATE        : $Date: $ 
*   SOURCE MOD. : $Source: $ 
*   LOG:        : please have a look at the end of the file
*****************************************************************************/
/************************************************************************
 * Generated using TEE Capricorn: Image to C Code Generator
 * Version 2.00
 * Toshiba Electronics Europe GmbH
 * This software is copyright protected. All rights reserved
 ************************************************************************
 * Converted on: 21.01.2016 @ 10:59
 ************************************************************************/
#include "images_defs.h"
#include "gf.h"
#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section bss = ".RAMSTgraphics"
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(_DIAB_TOOL)
#pragma section .bss ".RAMSTgraphics"
#endif /* defined(_DIAB_TOOL) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#pragma arm section zidata = ".RAMSTgraphics"
#endif /* defined(__arm__) && defined(__ARMCC_VERSION) */

/**
	A__Z
*/	
	gf_image_st stImage_AA[26];
/***********************************************************END A__Z*******/	

/**
	a_z
*/	
	gf_image_st stImage_a[26];
/***********************************************************END a_z*******/

/**
	car_door
*/	
	gf_image_st stImage_door_d[16];
/***********************************************************END car_door*******/

/**
	disfont_14x
*/	
	gf_image_st stImage_disfont[11];	
/***********************************************************END disfont_14x*******/


/**
	err_word
*/	
	gf_image_st stImage_ERR[20];
/***********************************************************END err_word*******/


/**
	lamp
*/	
		
	gf_image_st stImage_sspic0;
	gf_image_st stImage_sspic1;
	gf_image_st stImage_sspic10;
	gf_image_st stImage_sspic11;
	gf_image_st stImage_sspic12;
	gf_image_st stImage_sspic13;
	gf_image_st stImage_sspic14;
	gf_image_st stImage_sspic15;
	gf_image_st stImage_sspic16;
	gf_image_st stImage_sspic17;
	gf_image_st stImage_sspic18;
	gf_image_st stImage_sspic19;
	gf_image_st stImage_sspic2;
	gf_image_st stImage_sspic20;
	gf_image_st stImage_sspic21;
	gf_image_st stImage_sspic22;
	gf_image_st stImage_sspic23;
	gf_image_st stImage_sspic24;
	gf_image_st stImage_sspic25;
	gf_image_st stImage_sspic26;
	gf_image_st stImage_sspic3;
	gf_image_st stImage_sspic4;
	gf_image_st stImage_sspic5;
	gf_image_st stImage_sspic6;
	gf_image_st stImage_sspic7;
	gf_image_st stImage_sspic8;
	gf_image_st stImage_sspic9;

/***********************************************************END lamp*******/


/**
	prnds
*/	
	gf_image_st stImage_LEV[5];
/***********************************************************END prnds*******/


/**
	speedfont
*/	
	gf_image_st stImage_speedfont[10];	
/***********************************************************END speedfont*******/
	
/**
	instrument
*/
	gf_image_st stImage_dial_amp;
	gf_image_st stImage_dial_soc;
	gf_image_st stImage_dial_speed;
/***************************************************************************************END instrument**********/

/**
	needle
*/
gf_image_st stImage_needle_amp;
gf_image_st stImage_needle_speed;
/***************************************************************************************END needle**************/



#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section bss = default
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(_DIAB_TOOL)
#pragma section .bss "default"
#endif /* defined(_DIAB_TOOL) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#pragma arm section zidata
#endif /* defined(__arm__) && defined(__ARMCC_VERSION) */

/****************************************************************************/

/************************** BEGIN of DISCLAIMER   **************************

- TOSHIBA is continually working to improve the quality and reliability of   
  its products. Nevertheless, semiconductor devices in general can
  malfunction or fail due to their inherent electrical sensitivity and 
  vulnerability to physical stress. It is the responsibility of the buyer, 
  when utilizing TOSHIBA products, to comply with the standards of safety 
  in making a safe design for the entire system, and to avoid situations in 
  which a malfunction or failure of such TOSHIBA products could cause loss of
  human life, bodily injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used 
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications.
  Also, please keep in mind the precautions and conditions set forth in the 
  ï¿½Handling Guide for Semiconductor Devices,ï¿?or 
  ï¿½TOSHIBA Semiconductor Reliability Handbookï¿?etc..

- The Toshiba products listed in this document are intended for usage in 
  general electronics applications (computer, personal equipment, office 
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.). 
  These Toshiba products are neither intended nor warranted for usage in 
  equipment that requires extraordinarily high quality and/or reliability or
  a malfunction or failure of which may cause loss of human life or bodily 
  injury (ï¿½Unintended Usageï¿?. Unintended Usage include atomic energy control
  instruments, airplane or spaceship instruments, transportation instruments, 
  traffic signal instruments, combustion control instruments, medical 
  instruments, all types of safety devices, etc.. 
  Unintended Usage of Toshiba products listed in this document shall be 
  made at the customerï¿½s own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit,business interruption, loss of business
  information,and other pecuniary losses) occurring 
  from the use of, or inability to use, this product.

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
* $Log: $
*
*********************************** END OF LOG ******************************/
