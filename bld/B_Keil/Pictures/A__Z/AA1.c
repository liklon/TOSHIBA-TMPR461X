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
 * Input Filename: C:\Users\liklon\Desktop\CM000\12\AA1.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.55 KB
 * Compression Ratio : 49.64%
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
ALIGNED const uint32_t u32_AA1_RLE[AA1_SIZE] = {
0x0000009D, 0x00000001, 0xFFFFDF84, 0xFFFFDF04, 0xCFFFFFD9, 0xFFC7FFFF, 0x000085FF, 0x00000100, 
0xFFFF8700, 0xFFFF03FF, 0xFFFFEFFF, 0x83FFFFC9, 0x01000000, 0x88000000, 0x03FFFFFF, 0xF9FFFFFF, 
0xFFC5FFFF, 0x000082FF, 0x00000100, 0xFFFF8200, 0xFFFF01FF, 0x000082FF, 0x00000600, 0xFFFFD300, 
0xFFFFFFF1, 0xFFFFFFFF, 0xFFFFE7FF, 0x00000082, 0x00000001, 0xFFFFFF82, 0xFFFFFF01, 0x00000083, 
0x00000005, 0xFFFFFFCF, 0xFFFFFFFF, 0xFFFFF5FF, 0x00000082, 0x00000001, 0xFFFFFF82, 0xFFFFFF01, 
0x00000084, 0x00000004, 0xFFFFFFFF, 0xFFFDFFFF, 0x000082FF, 0x00000100, 0xFFFF8200, 0xFFFF01FF, 
0x000083FF, 0x00000500, 0xFFFFCD00, 0xFFFFFFFF, 0xFFF3FFFF, 0x000082FF, 0x00000100, 0xFFFF8200, 
0xFFFF09FF, 0x000000FF, 0xC3000000, 0xFFD7FFFF, 0xFFFFF5FF, 0xFFFFFFFF, 0xFFDBFFFF, 0x000082FF, 
0x00000100, 0xFFFF8800, 0xFFFF03FF, 0xFFFFE7FF, 0x82FFFFC1, 0x01000000, 0x87000000, 0x03FFFFFF, 
0xF7FFFFFF, 0xFFD7FFFF, 0x000083FF, 0x00000100, 0xFFFF8200, 0xFFFF09FF, 0xFFFFCFFF, 0xDBFFFFCF, 
0xFFEBFFFF, 0xFFFFFBFF, 0xFFFFFFFF, 0xFFE5FFFF, 0x000082FF, 0x00000100, 0xFFFF8200, 0xFFFF01FF, 
0x000083FF, 0x00000800, 0xFFFFC700, 0xFFFFFFFB, 0xFFFFFFFF, 0xFFFFC9FF, 0x00000000, 0xFF820000, 
0xFF01FFFF, 0x0084FFFF, 0x00070000, 0xFFEB0000, 0xFFFFFFFF, 0xD9FFFFFF, 0x0000FFFF, 0x00000000, 
0xFFFFFF82, 0xFFFFFF01, 0x00000084, 0x00000007, 0xFFFFFFE7, 0xFFFFFFFF, 0xFFFFD9FF, 0x00000000, 
0xFF820000, 0xFF01FFFF, 0x0084FFFF, 0x00070000, 0xFFF50000, 0xFFFFFFFF, 0xCDFFFFFF, 0x0000FFFF, 
0x00000000, 0xFFFFFF82, 0xFFFFFF01, 0x00000082, 0x00000009, 0xE7FFFFC7, 0xFFFFFFFF, 0xFFFFFFFF, 
0xC3FFFFFD, 0x0000FFFF, 0x00000000, 0xFFFFFF89, 0xFFFFFF02, 0x82FFFFDB, 0x01000000, 0x87000000, 
0x04FFFFFF, 0xF7FFFFFF, 0xFFDBFFFF, 0x000000FF, 0x00000001
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
