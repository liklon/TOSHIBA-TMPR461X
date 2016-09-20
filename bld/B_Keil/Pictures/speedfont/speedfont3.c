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
 * Image Dimensions : Width=36, Height=62
 * Input Filename: C:\Users\liklon\Desktop\CM000\7\speedfont3.png
 * Data is RLE compressed
 * Uncompressed Data Size : 8.72 KB
 * Compressed Data Size : 1.65 KB
 * Compression Ratio : 81.10%
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
ALIGNED const uint32_t u32_speedfont3_RLE[SPEEDFONT3_SIZE] = {
0xFFFFC089, 0xFFFFC004, 0xDDFFFFD1, 0xFFDDFFFF, 0xFFFF86FF, 0xFFFF04FF, 0xFFFFEAFF, 0xDDFFFFDD, 
0xC093FFFF, 0xC003FFFF, 0xFFD1FFFF, 0xFFFFE6FF, 0xFFFFFF8E, 0xFFFFFF03, 0xD5FFFFEE, 0xC08EFFFF, 
0xC003FFFF, 0xFFD5FFFF, 0xFFFFF3FF, 0xFFFFFF92, 0xFFFFFF03, 0xD1FFFFF3, 0xC08AFFFF, 0xC003FFFF, 
0xFFCCFFFF, 0xFFFFEEFF, 0xFFFFFF96, 0xFFFFFF02, 0x88FFFFE2, 0x02FFFFC0, 0xC8FFFFC0, 0xFF99FFFF, 
0xFF02FFFF, 0xFFEEFFFF, 0xFFC087FF, 0xFFC002FF, 0xFFFFC8FF, 0xFFFFFF9A, 0xFFFFFF02, 0x86FFFFEA, 
0x02FFFFC0, 0xC8FFFFC0, 0xFF85FFFF, 0xFF04FFFF, 0xFFF7FFFF, 0xFFFFDDFF, 0x85FFFFDD, 0x04FFFFC0, 
0xDDFFFFC0, 0xFFDDFFFF, 0xFFFFFBFF, 0xFFFFFF89, 0xFFFFFF02, 0x85FFFFDD, 0x02FFFFC0, 0xC8FFFFC0, 
0xFF83FFFF, 0xFF03FFFF, 0xFFE2FFFF, 0xFFFFC8FF, 0xFFFFC08B, 0xFFFFC003, 0xF7FFFFD5, 0xFF88FFFF, 
0xFF02FFFF, 0xFFC8FFFF, 0xFFC084FF, 0xFFC005FF, 0xFFFFC8FF, 0xFFFFFFFF, 0xFFE2FFFF, 0xFFC090FF, 
0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF87, 0xFFFFFF02, 0x84FFFFE6, 0x04FFFFC0, 0xC8FFFFC0, 0xFFF3FFFF, 
0xFFFFCCFF, 0xFFFFC092, 0xFFFFC002, 0x87FFFFF3, 0x02FFFFFF, 0xC4FFFFFF, 0xC083FFFF, 0xC002FFFF, 
0xFFC4FFFF, 0xFFC094FF, 0xFFC002FF, 0xFFFFCCFF, 0xFFFFFF87, 0xFFFFFF02, 0x9AFFFFD5, 0x02FFFFC0, 
0xEAFFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFE2FFFF, 0xFFC09AFF, 0xFFC002FF, 0xFFFFDDFF, 0xFFFFFF86, 
0xFFFFFF02, 0x9AFFFFEE, 0x02FFFFC0, 0xCCFFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC09BFF, 
0xFFC001FF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFF7FF, 0xFFFFC09B, 0xFFFFC001, 0xFFFFFF86, 0xFFFFFF02, 
0x9BFFFFF7, 0x01FFFFC0, 0x86FFFFC0, 0x02FFFFFF, 0xEEFFFFFF, 0xC09BFFFF, 0xC001FFFF, 0xFF86FFFF, 
0xFF02FFFF, 0xFFE6FFFF, 0xFFC09AFF, 0xFFC002FF, 0xFFFFCCFF, 0xFFFFFF86, 0xFFFFFF02, 0x9AFFFFDD, 
0x02FFFFC0, 0xDDFFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFCCFFFF, 0xFFC09AFF, 0xFFC002FF, 0xFFFFEEFF, 
0xFFFFFF85, 0xFFFFFF02, 0x9AFFFFF7, 0x02FFFFC0, 0xCCFFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFDDFFFF, 
0xFFC09AFF, 0xFFC002FF, 0xFFFFF3FF, 0xFFFFFF85, 0xFFFFFF03, 0xC4FFFFF7, 0xC099FFFF, 0xC002FFFF, 
0xFFEEFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC098, 0xFFFFC003, 0xEEFFFFC8, 0xFF86FFFF, 
0xFF02FFFF, 0xFFDDFFFF, 0xFFC097FF, 0xFFC003FF, 0xFFFFC8FF, 0x87FFFFE2, 0x02FFFFFF, 0xDDFFFFFF, 
0xC094FFFF, 0xC005FFFF, 0xFFCCFFFF, 0xFFFFDDFF, 0xFBFFFFDD, 0xFF88FFFF, 0xFF02FFFF, 0xFFD5FFFF, 
0xFFC08CFF, 0xFFC002FF, 0xFFFFD9FF, 0xFFFFFF92, 0xFFFFFF03, 0xC8FFFFEA, 0xC08DFFFF, 0xC002FFFF, 
0xFFD9FFFF, 0xFFFF90FF, 0xFFFF03FF, 0xFFFFE6FF, 0x8FFFFFCC, 0x02FFFFC0, 0xD9FFFFC0, 0xFF8EFFFF, 
0xFF02FFFF, 0xFFDDFFFF, 0xFFC092FF, 0xFFC002FF, 0xFFFFD9FF, 0xFFFFFF90, 0xFFFFFF04, 0xDDFFFFFB, 
0xFFD1FFFF, 0xFFC08EFF, 0xFFC002FF, 0xFFFFD9FF, 0xFFFFFF93, 0xFFFFFF03, 0xD9FFFFF7, 0xC08CFFFF, 
0xC002FFFF, 0xFFD9FFFF, 0xFFFF95FF, 0xFFFF03FF, 0xFFFFF3FF, 0x94FFFFCC, 0x01FFFFC0, 0x82FFFFC0, 
0x01FFFFDD, 0x8BFFFFDD, 0x02FFFFFF, 0xD5FFFFFF, 0xC097FFFF, 0xC003FFFF, 0xFFC8FFFF, 0xFFFFDDFF, 
0xFFFFFF89, 0xFFFFFF02, 0x99FFFFD9, 0x02FFFFC0, 0xE2FFFFC0, 0xFF88FFFF, 0xFF02FFFF, 0xFFCCFFFF, 
0xFFC099FF, 0xFFC003FF, 0xFFFFD1FF, 0x86FFFFFB, 0x03FFFFFF, 0xF7FFFFFF, 0xFFC4FFFF, 0xFFC099FF, 
0xFFC002FF, 0xFFFFCCFF, 0xFFFFFF87, 0xFFFFFF02, 0x9AFFFFDD, 0x02FFFFC0, 0xDDFFFFC0, 0xFF86FFFF, 
0xFF02FFFF, 0xFFFBFFFF, 0xFFC09BFF, 0xFFC002FF, 0xFFFFF7FF, 0xFFFFFF86, 0xFFFFFF02, 0x9AFFFFD5, 
0x02FFFFC0, 0xDDFFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFE2FFFF, 0xFFC09AFF, 0xFFC002FF, 0xFFFFCCFF, 
0xFFFFFF86, 0xFFFFFF02, 0x9BFFFFF3, 0x01FFFFC0, 0x86FFFFC0, 0x02FFFFFF, 0xFBFFFFFF, 0xC09BFFFF, 
0xC002FFFF, 0xFFF7FFFF, 0xFFFF86FF, 0xFFFF01FF, 0xFFC09BFF, 0xFFC002FF, 0xFFFFF7FF, 0xFFFFFF86, 
0xFFFFFF01, 0xFFFFC09B, 0xFFFFC002, 0x85FFFFF7, 0x02FFFFFF, 0xFBFFFFFF, 0xC09BFFFF, 0xC002FFFF, 
0xFFFBFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFF3FF, 0xFFFFC09A, 0xFFFFC002, 0x86FFFFCC, 0x02FFFFFF, 
0xEAFFFFFF, 0xC09AFFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFDDFF, 0xFFFFC09A, 
0xFFFFC002, 0x86FFFFF7, 0x03FFFFFF, 0xCCFFFFFF, 0xFFC4FFFF, 0xFFC098FF, 0xFFC002FF, 0xFFFFD9FF, 
0xFFFFFF86, 0xFFFFFF05, 0xC0FFFFF7, 0xFFDDFFFF, 0xFFFFDDFF, 0xFFFFC096, 0xFFFFC003, 0xFBFFFFC8, 
0xFF86FFFF, 0xFF07FFFF, 0xFFD9FFFF, 0xFFFFC0FF, 0xFFFFFFDD, 0xFFEEFFFF, 0xFFFFC8FF, 0xFFFFC093, 
0xFFFFC003, 0xF7FFFFC8, 0xFF86FFFF, 0xFF05FFFF, 0xFFF7FFFF, 0xFFFFC0FF, 0xDDFFFFC0, 0xFF82FFFF, 
0xFF02FFFF, 0xFFE2FFFF, 0xFFC091FF, 0xFFC003FF, 0xFFFFD5FF, 0x87FFFFFB, 0x05FFFFFF, 0xD5FFFFFF, 
0xFFC0FFFF, 0xFFFFC0FF, 0x84FFFFDD, 0x03FFFFFF, 0xE2FFFFFF, 0xFFCCFFFF, 0xFFC08CFF, 0xFFC003FF, 
0xFFFFD1FF, 0x88FFFFEE, 0x02FFFFFF, 0xE2FFFFFF, 0xC082FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 
0xFFFF05FF, 0xFFFFFBFF, 0xDDFFFFDD, 0xFFC8FFFF, 0xFFC085FF, 0xFFC004FF, 0xFFFFDDFF, 0xFBFFFFDD, 
0xFF89FFFF, 0xFF02FFFF, 0xFFEEFFFF, 0xFFC083FF, 0xFFC002FF, 0xFFFFDDFF, 0xFFFFFF9C, 0xFFFFFF02, 
0x85FFFFEE, 0x02FFFFC0, 0xE6FFFFC0, 0xFF9AFFFF, 0xFF02FFFF, 0xFFE2FFFF, 0xFFC087FF, 0xFFC002FF, 
0xFFFFD9FF, 0xFFFFFF97, 0xFFFFFF03, 0xD1FFFFF7, 0xC089FFFF, 0xC003FFFF, 0xFFC8FFFF, 0xFFFFEAFF, 
0xFFFFFF93, 0xFFFFFF03, 0xDDFFFFFB, 0xC08DFFFF, 0xC003FFFF, 0xFFCCFFFF, 0xFFFFE2FF, 0xFFFFFF8F, 
0xFFFFFF03, 0xD9FFFFE6, 0xC092FFFF, 0xC004FFFF, 0xFFD5FFFF, 0xFFFFDDFF, 0x86FFFFE2, 0x05FFFFFF, 
0xF3FFFFFF, 0xFFDDFFFF, 0xFFFFDDFF, 0x8DFFFFD1, 0x01FFFFC0, 0x00FFFFC0
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
