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
 * Converted on: 25.04.2016 @ 09:27
 * Output format: FMT_RLERGBA24
 * Image Dimensions : Width=14, Height=20
 * Input Filename: C:\Users\liklon\Desktop\CM000\12\AA12.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.71 KB
 * Compression Ratio : 35.00%
 ************************************************************************/

#include "captypes.h"
#include "images_defs.h"

#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section rodata = ".ROMgraphics"
#define ALIGNED
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(_DIAB_TOOL)
#pragma section .rodata ".ROMgraphics"
/* fixme: specify alignment */
#define ALIGNED
#endif /* defined(_DIAB_TOOL) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#pragma arm section rodata = ".ROMgraphics"
#define ALIGNED __align(8)
#endif /* defined(__arm__) && defined(__ARMCC_VERSION) */

#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED const uint32_t u32_AA12_RLE[AA12_SIZE] = {
0x0000009C, 0x00000002, 0x82FFFFC7, 0x02FFFFDF, 0xD1FFFFDF, 0x0082FFFF, 0x00020000, 0xFFCB0000, 
0xFFDF82FF, 0xFFDF04FF, 0xFFFFCBFF, 0xCF000000, 0xFF82FFFF, 0xFF02FFFF, 0xFFEDFFFF, 0x000082FF, 
0x00000200, 0xFFFFDD00, 0xFFFFFF82, 0xFFFFFF04, 0x00FFFFD7, 0xFFCF0000, 0xFFFF82FF, 0xFFFF02FF, 
0xFFFFFBFF, 0x00000082, 0x00000002, 0x82FFFFEB, 0x04FFFFFF, 0xD7FFFFFF, 0x0000FFFF, 0xFFFFCF00, 
0xFFFFFF83, 0xFFFFFF05, 0x00FFFFC7, 0x00000000, 0xFFFFF700, 0xFFFFFF82, 0xFFFFFF04, 0x00FFFFD7, 
0xFFCF0000, 0xFFFF83FF, 0xFFFF04FF, 0xFFFFD3FF, 0xC3000000, 0xFF83FFFF, 0xFF04FFFF, 0xFFD7FFFF, 
0x000000FF, 0x83FFFFCF, 0x04FFFFFF, 0xE1FFFFFF, 0x0000FFFF, 0xFFFFD100, 0xFFFFFF83, 0xFFFFFF5C, 
0x00FFFFD7, 0xFFCF0000, 0xFFFFFFFF, 0xEBFFFFFF, 0xFFFFFFFF, 0xFFFFEDFF, 0xDD000000, 0xFFFFFFFF, 
0xFFFFEFFF, 0xFFFFFFFB, 0xFFD7FFFF, 0x000000FF, 0xFFFFFFCF, 0xFFFFFFFF, 0xFFFFF9FF, 0xFBFFFFFF, 
0x0000FFFF, 0xFFFFEB00, 0xF9FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFD7, 0xFFCF0000, 0xFFFFFFFF, 
0xF9FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF5FFFFC5, 0xFFFFFFFF, 0xFFFFF9FF, 0xFFFFFFFF, 0xFFD7FFFF, 
0x000000FF, 0xFFFFFFCF, 0xFFFFFFFF, 0xFFFFEBFF, 0xFFFFFFFF, 0xFFD7FFFF, 0xFFFFFFFF, 0xEBFFFFFF, 
0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFD7, 0xFFCF0000, 0xFFFFFFFF, 0xE1FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 
0xFFFFFFEF, 0xFFFFFFFF, 0xFFFFE1FF, 0xFFFFFFFF, 0xFFD7FFFF, 0x000000FF, 0xFFFFFFCF, 0xFFFFFFFF, 
0xFFFFDFFF, 0xFFFFFFF3, 0xFFF7FFFF, 0xFFFFFFFF, 0xD3FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFD7, 
0xFFCF0000, 0xFFFFFFFF, 0xDFFFFFFF, 0xFFE7FFFF, 0xFFFF82FF, 0xFFFF0CFF, 0xFFFFF7FF, 0xFFFFFFCF, 
0xFFFFFFFF, 0xFFFFD7FF, 0xCF000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xDBFFFFDF, 0xFF82FFFF, 0xFF0CFFFF, 
0xFFEBFFFF, 0xFFFFCFFF, 0xFFFFFFFF, 0xFFD7FFFF, 0x000000FF, 0xFFFFFFCF, 0xFFFFFFFF, 0xFFFFDFFF, 
0x82FFFFCD, 0x0CFFFFFF, 0xDDFFFFFF, 0xFFCFFFFF, 0xFFFFFFFF, 0xD7FFFFFF, 0x0000FFFF, 0xFFFFCF00, 
0xFFFFFFFF, 0xFFDFFFFF, 0xFFFFC1FF, 0xFFFFFF82, 0xFFFFFF21, 0xCFFFFFD1, 0xFFFFFFFF, 0xFFFFFFFF, 
0x00FFFFD7, 0xFFCF0000, 0xFFFFFFFF, 0xDFFFFFFF, 0x0000FFFF, 0xFFFFF300, 0xFFFFFFFF, 0xFFC3FFFF, 
0xFFFFCFFF, 0xFFFFFFFF, 0xFFD7FFFF, 0x000000FF, 0xFFFFFFCF, 0xFFFFFFFF, 0xFFFFDFFF, 0xE7000000, 
0xFFFFFFFF, 0xFFFFF7FF, 0xCF000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFD701
};

#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section rodata = default
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(_DIAB_TOOL)
#pragma section .rodata "default"
/* fixme: specify alignment */
#endif /* defined(_DIAB_TOOL) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#pragma arm section rodata
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
  �Handling Guide for Semiconductor Devices,� or 
  �TOSHIBA Semiconductor Reliability Handbook� etc..

- The Toshiba products listed in this document are intended for usage in 
  general electronics applications (computer, personal equipment, office 
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.). 
  These Toshiba products are neither intended nor warranted for usage in 
  equipment that requires extraordinarily high quality and/or reliability or
  a malfunction or failure of which may cause loss of human life or bodily 
  injury (�Unintended Usage�). Unintended Usage include atomic energy control
  instruments, airplane or spaceship instruments, transportation instruments, 
  traffic signal instruments, combustion control instruments, medical 
  instruments, all types of safety devices, etc.. 
  Unintended Usage of Toshiba products listed in this document shall be 
  made at the customer�s own risk.

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
