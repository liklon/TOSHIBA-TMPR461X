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
 * Image Dimensions : Width=22, Height=61
 * Input Filename: C:\Users\liklon\Desktop\CM000\7\speedfont1.png
 * Data is RLE compressed
 * Uncompressed Data Size : 5.24 KB
 * Compressed Data Size : 1.43 KB
 * Compression Ratio : 72.80%
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
ALIGNED const uint32_t u32_speedfont1_RLE[SPEEDFONT1_SIZE] = {
0xFFFFC091, 0xFFFFC005, 0xFFFFFFE2, 0xFFFFFFFF, 0xFFFFF7FF, 0xFFFFC08F, 0xFFFFC003, 0xEEFFFFC8, 
0xFF82FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08EFF, 0xFFC003FF, 0xFFFFD5FF, 0x83FFFFFB, 0x02FFFFFF, 
0xF7FFFFFF, 0xC08CFFFF, 0xC003FFFF, 0xFFC4FFFF, 0xFFFFEAFF, 0xFFFFFF85, 0xFFFFFF02, 0x8BFFFFF7, 
0x02FFFFC0, 0xDDFFFFC0, 0xFF87FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC089FF, 0xFFC003FF, 0xFFFFD5FF, 
0x88FFFFF7, 0x02FFFFFF, 0xF7FFFFFF, 0xC087FFFF, 0xC003FFFF, 0xFFD1FFFF, 0xFFFFEEFF, 0xFFFFFF8A, 
0xFFFFFF02, 0x85FFFFF7, 0x03FFFFC0, 0xD5FFFFC0, 0xFFEEFFFF, 0xFFFF8CFF, 0xFFFF02FF, 0xFFFFF7FF, 
0xFFFFC083, 0xFFFFC003, 0xF7FFFFDD, 0xFF8EFFFF, 0xFF05FFFF, 0xFFF7FFFF, 0xFFFFC0FF, 0xEAFFFFDD, 
0xFF89FFFF, 0xFF03FFFF, 0xFFDDFFFF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF03, 0xEEFFFFF7, 0xFF89FFFF, 
0xFF05FFFF, 0xFFF7FFFF, 0xFFFFD1FF, 0xEEFFFFC0, 0xFF85FFFF, 0xFF03FFFF, 0xFFF7FFFF, 0xFFFFEEFF, 
0xFFFFFF88, 0xFFFFFF02, 0x82FFFFE6, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF03FFFF, 0xFFF7FFFF, 
0xFFFFEEFF, 0xFFFFFF86, 0xFFFFFF03, 0xCCFFFFEA, 0xC083FFFF, 0xC002FFFF, 0xFFEEFFFF, 0xFFFF85FF, 
0xFFFF03FF, 0xFFFFF7FF, 0x84FFFFEE, 0x03FFFFFF, 0xEAFFFFFF, 0xFFCCFFFF, 0xFFC085FF, 0xFFC002FF, 
0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF03, 0xEEFFFFF7, 0xFF82FFFF, 0xFF03FFFF, 0xFFE2FFFF, 0xFFFFC8FF, 
0xFFFFC087, 0xFFFFC002, 0x85FFFFEE, 0x05FFFFFF, 0xF7FFFFFF, 0xFFEEFFFF, 0xFFFFE6FF, 0x8AFFFFD9, 
0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 
0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 
0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 
0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 
0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 
0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 
0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 
0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 
0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 
0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 
0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 
0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 
0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 
0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 
0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 
0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 
0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 
0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 
0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 
0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 
0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 
0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 
0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 
0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 
0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 
0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 
0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 
0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 
0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 
0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 
0xFFFFFF02, 0x8DFFFFF7, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC08DFF, 
0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF01, 0xFFFFF701
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
