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
 * Input Filename: C:\Users\liklon\Desktop\CM000\12\AA22.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.72 KB
 * Compression Ratio : 34.38%
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
ALIGNED const uint32_t u32_AA22_RLE[AA22_SIZE] = {
0x0000009C, 0x00000014, 0xDFFFFFDF, 0xFFD9FFFF, 0x000000FF, 0xDB000000, 0xFFDFFFFF, 0xFFFFDDFF, 
0x00000000, 0xFFDB0000, 0xFFFFDFFF, 0x00FFFFDF, 0xFFF70000, 0xFFFFFFFF, 0x00FFFFF9, 0x00000000, 
0xFFFF8200, 0xFFFF0CFF, 0xFFFFC3FF, 0xF9000000, 0xFFFFFFFF, 0xFFFFF9FF, 0xEF000000, 0xFFFFFFFF, 
0xFFFFFFFF, 0xC7000000, 0xFF82FFFF, 0xFF0CFFFF, 0xFFCBFFFF, 0x000000FF, 0xFFFFFFFF, 0xFFF1FFFF, 
0x000000FF, 0xFFFFFFE7, 0xFFFFFFFF, 0xFFFFC7FF, 0x82FFFFD1, 0x0CFFFFFF, 0xD3FFFFFF, 0xFFC7FFFF, 
0xFFFFFFFF, 0xE9FFFFFF, 0x0000FFFF, 0xFFFFDF00, 0xFFFFFFFF, 0xFFCDFFFF, 0xFFFFD9FF, 0xFFFFFF82, 
0xFFFFFF4B, 0xCDFFFFDD, 0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFE1, 0xFFD70000, 0xFFFFFFFF, 0xD3FFFFFF, 
0xFFE1FFFF, 0xFFFFFFFF, 0xFFFFFFFB, 0xFFE5FFFF, 0xFFFFD3FF, 0xFFFFFFFF, 0xFFD9FFFF, 0x000000FF, 
0xFFFFFFCF, 0xFFFFFFFF, 0xFFFFD9FF, 0xFFFFFFEB, 0xFFF9FFFF, 0xFFFFFFFF, 0xD9FFFFED, 0xFFFFFFFF, 
0xFFFFFFFF, 0x00FFFFD1, 0xFFC70000, 0xFFFFFFFF, 0xDFFFFFFF, 0xFFF3FFFF, 0xFFFFFFFF, 0xFFFFFFF3, 
0xFFF7FFFF, 0xFFFFDFFF, 0xFFFFFFFF, 0xFFC9FFFF, 0x000000FF, 0xFF000000, 0xFFFFFFFF, 0xFFFFE7FF, 
0xFFFFFFFB, 0xFFE1FFFF, 0xFFFFFFFF, 0xE7FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFC1, 0x00000000, 
0xFFFFF700, 0xF1FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFCF, 0xFFFFFFFF, 0xFFFFF7FF, 0xF9FFFFFF, 
0x0082FFFF, 0x000C0000, 0xFFEF0000, 0xFFFFFFFF, 0xFFFFFFF9, 0xFFFFFFFF, 0xFFFFC1FF, 0xFFFFFFFB, 
0xFFF9FFFF, 0xFFFFFFFF, 0x82FFFFF1, 0x0C000000, 0xE5000000, 0xFFFFFFFF, 0xFFFFF5FF, 0xF7FFFFFF, 
0x0000FFFF, 0xFFFFF300, 0xF3FFFFFF, 0xFFFFFFFF, 0xFFFFE9FF, 0x00000082, 0x00000002, 0x82FFFFDD, 
0x04FFFFFF, 0xEDFFFFFF, 0x0000FFFF, 0xFFFFEB00, 0xFFFFFF82, 0xFFFFFF02, 0x82FFFFE1, 0x02000000, 
0xD5000000, 0xFF82FFFF, 0xFF04FFFF, 0xFFE5FFFF, 0x000000FF, 0x82FFFFE1, 0x02FFFFFF, 0xD9FFFFFF, 
0x0082FFFF, 0x00020000, 0xFFCD0000, 0xFFFF82FF, 0xFFFF04FF, 0xFFFFDDFF, 0xD9000000, 0xFF82FFFF, 
0xFF02FFFF, 0xFFD1FFFF, 0x000082FF, 0x00000200, 0xFFFFC500, 0xFFFFFF82, 0xFFFFFF04, 0x00FFFFD3, 
0xFFCF0000, 0xFFFF82FF, 0xFFFF02FF, 0xFFFFC9FF, 0x00000083, 0x00000007, 0xFFFFFFFD, 0xFFFFFFFF, 
0xFFFFCBFF, 0xC7000000, 0xFF82FFFF, 0xFF02FFFF, 0xFFC1FFFF, 0x000083FF, 0x00000B00, 0xFFFFF500, 
0xFFFFFFFF, 0xFFC1FFFF, 0x000000FF, 0xFD000000, 0xFFFFFFFF, 0xFFFFF9FF, 0x01000000, 0x00000000
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
