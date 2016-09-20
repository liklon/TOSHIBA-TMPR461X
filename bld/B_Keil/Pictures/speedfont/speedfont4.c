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
 * Converted on: 22.04.2016 @ 16:09
 * Output format: FMT_RLERGBA24
 * Image Dimensions : Width=46, Height=60
 * Input Filename: C:\Users\liklon\Desktop\CM000\7\speedfont4.png
 * Data is RLE compressed
 * Uncompressed Data Size : 10.78 KB
 * Compressed Data Size : 1.88 KB
 * Compression Ratio : 82.55%
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
ALIGNED const uint32_t u32_speedfont4_RLE[SPEEDFONT4_SIZE] = {
0xFFFFC09B, 0xFFFFC002, 0x86FFFFF7, 0x02FFFFFF, 0xD9FFFFFF, 0xC0A3FFFF, 0xC002FFFF, 0xFFD9FFFF, 
0xFFFF87FF, 0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC0A3, 0xFFFFC002, 0x87FFFFF7, 0x02FFFFFF, 0xD9FFFFFF, 
0xC0A2FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF88FF, 0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC0A1, 0xFFFFC003, 
0xFBFFFFC4, 0xFF88FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC0A1FF, 0xFFC002FF, 0xFFFFE2FF, 0xFFFFFF89, 
0xFFFFFF02, 0xA0FFFFD9, 0x02FFFFC0, 0xC8FFFFC0, 0xFF8AFFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC0A0FF, 
0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF8A, 0xFFFFFF02, 0x9FFFFFD9, 0x02FFFFC0, 0xD5FFFFC0, 0xFF8BFFFF, 
0xFF02FFFF, 0xFFD9FFFF, 0xFFC09FFF, 0xFFC002FF, 0xFFFFF7FF, 0xFFFFFF8B, 0xFFFFFF02, 0x9EFFFFD9, 
0x02FFFFC0, 0xDDFFFFC0, 0xFF8CFFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC09DFF, 0xFFC002FF, 0xFFFFC8FF, 
0xFFFFFF85, 0xFFFFFF02, 0x86FFFFF3, 0x02FFFFFF, 0xD9FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFEEFFFF, 
0xFFFF85FF, 0xFFFF02FF, 0xFFFFD1FF, 0xFFFFFF86, 0xFFFFFF02, 0x9CFFFFD9, 0x02FFFFC0, 0xD9FFFFC0, 
0xFF85FFFF, 0xFF03FFFF, 0xFFE2FFFF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0x9BFFFFD9, 0x03FFFFC0, 
0xC4FFFFC0, 0xFFFBFFFF, 0xFFFF84FF, 0xFFFF04FF, 0xFFFFFBFF, 0xC8FFFFC4, 0xFF86FFFF, 0xFF02FFFF, 
0xFFD9FFFF, 0xFFC09BFF, 0xFFC002FF, 0xFFFFE6FF, 0xFFFFFF85, 0xFFFFFF04, 0xC0FFFFD9, 0xFFC8FFFF, 
0xFFFF86FF, 0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC09A, 0xFFFFC002, 0x85FFFFD5, 0x05FFFFFF, 0xF3FFFFFF, 
0xFFC0FFFF, 0xFFFFC0FF, 0x86FFFFC8, 0x02FFFFFF, 0xD9FFFFFF, 0xC099FFFF, 0xC003FFFF, 0xFFC4FFFF, 
0xFFFFF7FF, 0xFFFFFF85, 0xFFFFFF05, 0xC0FFFFCC, 0xFFC0FFFF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 
0x99FFFFD9, 0x02FFFFC0, 0xE6FFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFE2FFFF, 0xFFC082FF, 0xFFC002FF, 
0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0x98FFFFD9, 0x02FFFFC0, 0xD5FFFFC0, 0xFF85FFFF, 0xFF03FFFF, 
0xFFF7FFFF, 0xFFFFC4FF, 0xFFFFC082, 0xFFFFC002, 0x86FFFFC8, 0x02FFFFFF, 0xD9FFFFFF, 0xC097FFFF, 
0xC003FFFF, 0xFFC4FFFF, 0xFFFFF7FF, 0xFFFFFF85, 0xFFFFFF02, 0x83FFFFD5, 0x02FFFFC0, 0xC8FFFFC0, 
0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC097FF, 0xFFC002FF, 0xFFFFEAFF, 0xFFFFFF85, 0xFFFFFF02, 
0x84FFFFEA, 0x02FFFFC0, 0xC8FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC096FF, 0xFFC002FF, 
0xFFFFD9FF, 0xFFFFFF85, 0xFFFFFF03, 0xC8FFFFFB, 0xC084FFFF, 0xC002FFFF, 0xFFC8FFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC095, 0xFFFFC003, 0xFBFFFFC8, 0xFF85FFFF, 0xFF02FFFF, 0xFFDDFFFF, 
0xFFC085FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0x95FFFFD9, 0x02FFFFC0, 0xF3FFFFC0, 
0xFF85FFFF, 0xFF02FFFF, 0xFFEEFFFF, 0xFFC086FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 
0x94FFFFD9, 0x02FFFFC0, 0xDDFFFFC0, 0xFF85FFFF, 0xFF03FFFF, 0xFFFBFFFF, 0xFFFFC8FF, 0xFFFFC086, 
0xFFFFC002, 0x86FFFFC8, 0x02FFFFFF, 0xD9FFFFFF, 0xC093FFFF, 0xC002FFFF, 0xFFCCFFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC087, 0xFFFFC002, 0x86FFFFC8, 0x02FFFFFF, 0xD9FFFFFF, 0xC092FFFF, 
0xC003FFFF, 0xFFC4FFFF, 0xFFFFF7FF, 0xFFFFFF85, 0xFFFFFF02, 0x88FFFFEA, 0x02FFFFC0, 0xC8FFFFC0, 
0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC092FF, 0xFFC002FF, 0xFFFFEAFF, 0xFFFFFF85, 0xFFFFFF03, 
0xC4FFFFF7, 0xC088FFFF, 0xC002FFFF, 0xFFC8FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC091, 
0xFFFFC002, 0x86FFFFDD, 0x02FFFFFF, 0xD5FFFFFF, 0xC089FFFF, 0xC002FFFF, 0xFFC8FFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC090, 0xFFFFC002, 0x86FFFFCC, 0x02FFFFFF, 0xE2FFFFFF, 0xC08AFFFF, 
0xC002FFFF, 0xFFC8FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC08F, 0xFFFFC003, 0xF7FFFFC8, 
0xFF85FFFF, 0xFF02FFFF, 0xFFF3FFFF, 0xFFC08BFF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 
0x8FFFFFD9, 0x02FFFFC0, 0xF3FFFFC0, 0xFF85FFFF, 0xFF03FFFF, 0xFFFBFFFF, 0xFFFFC8FF, 0xFFFFC08B, 
0xFFFFC002, 0x86FFFFC8, 0x02FFFFFF, 0xD9FFFFFF, 0xC08EFFFF, 0xC002FFFF, 0xFFE2FFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC08C, 0xFFFFC002, 0x86FFFFC8, 0x02FFFFFF, 0xD9FFFFFF, 0xC08DFFFF, 
0xC002FFFF, 0xFFD9FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFE2FF, 0xFFFFC08D, 0xFFFFC002, 0x86FFFFC8, 
0x02FFFFFF, 0xD9FFFFFF, 0xC08CFFFF, 0xC002FFFF, 0xFFCCFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFF3FF, 
0xFFFFC08E, 0xFFFFC002, 0x86FFFFC8, 0x02FFFFFF, 0xD9FFFFFF, 0xC08BFFFF, 0xC003FFFF, 0xFFC8FFFF, 
0xFFFFF7FF, 0xFFFFFF85, 0xFFFFFF03, 0xC8FFFFFB, 0xC08EFFFF, 0xC002FFFF, 0xFFC8FFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC08A, 0xFFFFC003, 0xF3FFFFC4, 0xFF86FFFF, 0xFF02FFFF, 0xFFD1FFFF, 
0xFFC08FFF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0x8AFFFFD9, 0x02FFFFC0, 0xEAFFFFC0, 
0xFF86FFFF, 0xFF02FFFF, 0xFFDDFFFF, 0xFFC090FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 
0x89FFFFD9, 0x02FFFFC0, 0xE2FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFEAFFFF, 0xFFC091FF, 0xFFC002FF, 
0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0x88FFFFD9, 0x02FFFFC0, 0xD5FFFFC0, 0xFFABFFFF, 0xFF03FFFF, 
0xFFD9FFFF, 0xFFFFD9FF, 0xFFFFFFAB, 0xFFFFFF03, 0xD9FFFFD9, 0xFFABFFFF, 0xFF03FFFF, 0xFFD9FFFF, 
0xFFFFD9FF, 0xFFFFFFAB, 0xFFFFFF03, 0xD9FFFFD9, 0xFFABFFFF, 0xFF03FFFF, 0xFFD9FFFF, 0xFFFFD9FF, 
0xFFFFFFAB, 0xFFFFFF02, 0x9BFFFFD9, 0x02FFFFC0, 0xC8FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 
0xFFC0A4FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0xA4FFFFD9, 0x02FFFFC0, 0xC8FFFFC0, 
0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC0A4FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 
0xA4FFFFD9, 0x02FFFFC0, 0xC8FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC0A4FF, 0xFFC002FF, 
0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0xA4FFFFD9, 0x02FFFFC0, 0xC8FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 
0xFFD9FFFF, 0xFFC0A4FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0xA4FFFFD9, 0x02FFFFC0, 
0xC8FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC0A4FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 
0xFFFFFF02, 0xA4FFFFD9, 0x02FFFFC0, 0xC8FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC0A4FF, 
0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0xA4FFFFD9, 0x02FFFFC0, 0xC8FFFFC0, 0xFF86FFFF, 
0xFF02FFFF, 0xFFD9FFFF, 0xFFC0A4FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0x88FFFFD9, 
0x01FFFFC0, 0x00FFFFC0
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
