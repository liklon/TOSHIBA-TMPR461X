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
 * Image Dimensions : Width=41, Height=62
 * Input Filename: C:\Users\liklon\Desktop\CM000\7\speedfont0.png
 * Data is RLE compressed
 * Uncompressed Data Size : 9.93 KB
 * Compressed Data Size : 2.39 KB
 * Compression Ratio : 75.94%
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
ALIGNED const uint32_t u32_speedfont0_RLE[SPEEDFONT0_SIZE] = {
0xFFFFC08E, 0xFFFFC004, 0xDDFFFFCC, 0xFFE2FFFF, 0xFFFF85FF, 0xFFFF04FF, 0xFFFFEEFF, 0xD9FFFFDD, 
0xC09AFFFF, 0xC003FFFF, 0xFFDDFFFF, 0xFFFFFBFF, 0xFFFFFF8C, 0xFFFFFF03, 0xC8FFFFE6, 0xC095FFFF, 
0xC002FFFF, 0xFFDDFFFF, 0xFFFF91FF, 0xFFFF02FF, 0xFFFFE6FF, 0xFFFFC092, 0xFFFFC003, 0xF3FFFFC8, 
0xFF93FFFF, 0xFF03FFFF, 0xFFF7FFFF, 0xFFFFCCFF, 0xFFFFC08F, 0xFFFFC003, 0xF7FFFFCC, 0xFF95FFFF, 
0xFF03FFFF, 0xFFFBFFFF, 0xFFFFCCFF, 0xFFFFC08D, 0xFFFFC003, 0xFBFFFFCC, 0xFF97FFFF, 0xFF03FFFF, 
0xFFFBFFFF, 0xFFFFC8FF, 0xFFFFC08B, 0xFFFFC003, 0xF7FFFFC4, 0xFF88FFFF, 0xFF03FFFF, 0xFFDDFFFF, 
0xFFFFD1FF, 0xFFFFC083, 0xFFFFC003, 0xEEFFFFDD, 0xFF88FFFF, 0xFF02FFFF, 0xFFF3FFFF, 0xFFC08BFF, 
0xFFC002FF, 0xFFFFEAFF, 0xFFFFFF87, 0xFFFFFF02, 0x88FFFFE2, 0x03FFFFC0, 0xD1FFFFC0, 0xFFF7FFFF, 
0xFFFF87FF, 0xFFFF02FF, 0xFFFFDDFF, 0xFFFFC089, 0xFFFFC002, 0x87FFFFD9, 0x02FFFFFF, 0xD1FFFFFF, 
0xC08AFFFF, 0xC003FFFF, 0xFFC8FFFF, 0xFFFFF3FF, 0xFFFFFF87, 0xFFFFFF02, 0x87FFFFC8, 0x03FFFFC0, 
0xC4FFFFC0, 0xFFFBFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC08C, 0xFFFFC003, 0xFBFFFFC8, 
0xFF86FFFF, 0xFF02FFFF, 0xFFE6FFFF, 0xFFC087FF, 0xFFC002FF, 0xFFFFDDFF, 0xFFFFFF86, 0xFFFFFF02, 
0x8EFFFFE2, 0x02FFFFC0, 0xD5FFFFC0, 0xFF87FFFF, 0xFF02FFFF, 0xFFC8FFFF, 0xFFC085FF, 0xFFC003FF, 
0xFFFFC4FF, 0x85FFFFFB, 0x03FFFFFF, 0xFBFFFFFF, 0xFFC4FFFF, 0xFFC08FFF, 0xFFC002FF, 0xFFFFEEFF, 
0xFFFFFF86, 0xFFFFFF02, 0x85FFFFE2, 0x02FFFFC0, 0xD9FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFDDFFFF, 
0xFFC090FF, 0xFFC002FF, 0xFFFFD1FF, 0xFFFFFF86, 0xFFFFFF02, 0x85FFFFFB, 0x02FFFFC0, 0xEEFFFFC0, 
0xFF85FFFF, 0xFF03FFFF, 0xFFFBFFFF, 0xFFFFC4FF, 0xFFFFC091, 0xFFFFC002, 0x86FFFFF3, 0x02FFFFFF, 
0xD1FFFFFF, 0xC083FFFF, 0xC002FFFF, 0xFFC8FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFE6FF, 0xFFFFC092, 
0xFFFFC002, 0x86FFFFDD, 0x02FFFFFF, 0xE2FFFFFF, 0xC083FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC092, 0xFFFFC002, 0x86FFFFCC, 0x02FFFFFF, 0xF3FFFFFF, 0xC083FFFF, 
0xC002FFFF, 0xFFEAFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFC4FF, 0xFFFFC093, 0xFFFFC002, 0x86FFFFF3, 
0x02FFFFFF, 0xC4FFFFFF, 0xC082FFFF, 0xC002FFFF, 0xFFFBFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFF3FF, 
0xFFFFC094, 0xFFFFC002, 0x86FFFFE6, 0x05FFFFFF, 0xD5FFFFFF, 0xFFC0FFFF, 0xFFFFC0FF, 0x86FFFFCC, 
0x02FFFFFF, 0xE2FFFFFF, 0xC094FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 0xFFFF05FF, 0xFFFFDDFF, 
0xC0FFFFC0, 0xFFD9FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC094, 0xFFFFC002, 0x86FFFFCC, 
0x05FFFFFF, 0xEAFFFFFF, 0xFFC0FFFF, 0xFFFFC0FF, 0x86FFFFE2, 0x02FFFFFF, 0xCCFFFFFF, 0xC094FFFF, 
0xC002FFFF, 0xFFC4FFFF, 0xFFFF86FF, 0xFFFF05FF, 0xFFFFF3FF, 0xC0FFFFC0, 0xFFEEFFFF, 0xFFFF86FF, 
0xFFFF01FF, 0xFFC096FF, 0xFFC002FF, 0xFFFFFBFF, 0xFFFFFF85, 0xFFFFFF05, 0xC0FFFFFB, 0xFFC0FFFF, 
0xFFFFF7FF, 0xFFFFFF85, 0xFFFFFF02, 0x96FFFFF7, 0x02FFFFC0, 0xF3FFFFC0, 0xFF86FFFF, 0xFF03FFFF, 
0xFFC4FFFF, 0xFFFFC0FF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFEE, 0x02FFFFC0, 0xEAFFFFC0, 0xFF86FFFF, 
0xFF03FFFF, 0xFFC8FFFF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFEA, 0x02FFFFC0, 0xE6FFFFC0, 
0xFF86FFFF, 0xFF03FFFF, 0xFFD1FFFF, 0xFFFFCCFF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFE6, 0x02FFFFC0, 
0xDDFFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFD5FFFF, 0xFFFFD1FF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFDD, 
0x02FFFFC0, 0xDDFFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFD9FFFF, 0xFFFFD9FF, 0xFFFFFF86, 0xFFFFFF02, 
0x96FFFFDD, 0x02FFFFC0, 0xDDFFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFD9FFFF, 0xFFFFD9FF, 0xFFFFFF86, 
0xFFFFFF02, 0x96FFFFDD, 0x02FFFFC0, 0xD9FFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFD9FFFF, 0xFFFFD9FF, 
0xFFFFFF86, 0xFFFFFF02, 0x96FFFFD9, 0x02FFFFC0, 0xD9FFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFDDFFFF, 
0xFFFFDDFF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFD9, 0x02FFFFC0, 0xD9FFFFC0, 0xFF86FFFF, 0xFF03FFFF, 
0xFFDDFFFF, 0xFFFFDDFF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFD9, 0x02FFFFC0, 0xD9FFFFC0, 0xFF86FFFF, 
0xFF03FFFF, 0xFFDDFFFF, 0xFFFFDDFF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFD9, 0x02FFFFC0, 0xD9FFFFC0, 
0xFF86FFFF, 0xFF03FFFF, 0xFFDDFFFF, 0xFFFFDDFF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFD9, 0x02FFFFC0, 
0xD9FFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFD9FFFF, 0xFFFFD9FF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFD9, 
0x02FFFFC0, 0xD9FFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFD9FFFF, 0xFFFFD9FF, 0xFFFFFF86, 0xFFFFFF02, 
0x96FFFFDD, 0x02FFFFC0, 0xDDFFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFD5FFFF, 0xFFFFD9FF, 0xFFFFFF86, 
0xFFFFFF02, 0x96FFFFDD, 0x02FFFFC0, 0xDDFFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFD1FFFF, 0xFFFFD1FF, 
0xFFFFFF86, 0xFFFFFF02, 0x96FFFFE2, 0x02FFFFC0, 0xE2FFFFC0, 0xFF86FFFF, 0xFF03FFFF, 0xFFC8FFFF, 
0xFFFFCCFF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFE6, 0x02FFFFC0, 0xE6FFFFC0, 0xFF86FFFF, 0xFF03FFFF, 
0xFFC4FFFF, 0xFFFFC4FF, 0xFFFFFF86, 0xFFFFFF02, 0x96FFFFEE, 0x02FFFFC0, 0xEEFFFFC0, 0xFF85FFFF, 
0xFF04FFFF, 0xFFFBFFFF, 0xFFFFC0FF, 0x86FFFFC0, 0x02FFFFFF, 0xF7FFFFFF, 0xC096FFFF, 0xC002FFFF, 
0xFFF7FFFF, 0xFFFF85FF, 0xFFFF05FF, 0xFFFFF3FF, 0xC0FFFFC0, 0xFFF3FFFF, 0xFFFF86FF, 0xFFFF01FF, 
0xFFC096FF, 0xFFC001FF, 0xFFFF86FF, 0xFFFF05FF, 0xFFFFE6FF, 0xC0FFFFC0, 0xFFEAFFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFCCFF, 0xFFFFC094, 0xFFFFC002, 0x86FFFFCC, 0x05FFFFFF, 0xDDFFFFFF, 0xFFC0FFFF, 
0xFFFFC0FF, 0x86FFFFDD, 0x02FFFFFF, 0xD5FFFFFF, 0xC094FFFF, 0xC002FFFF, 0xFFD5FFFF, 0xFFFF86FF, 
0xFFFF05FF, 0xFFFFD1FF, 0xC0FFFFC0, 0xFFD5FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFE2FF, 0xFFFFC094, 
0xFFFFC002, 0x86FFFFE2, 0x05FFFFFF, 0xC4FFFFFF, 0xFFC0FFFF, 0xFFFFC0FF, 0x86FFFFC4, 0x02FFFFFF, 
0xF3FFFFFF, 0xC094FFFF, 0xC002FFFF, 0xFFF3FFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFF3FF, 0xFFFFC083, 
0xFFFFC002, 0x86FFFFF3, 0x02FFFFFF, 0xC4FFFFFF, 0xC092FFFF, 0xC002FFFF, 0xFFC4FFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFDDFF, 0xFFFFC083, 0xFFFFC002, 0x86FFFFE2, 0x02FFFFFF, 0xDDFFFFFF, 0xC092FFFF, 
0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFCCFF, 0xFFFFC083, 0xFFFFC002, 0x86FFFFCC, 
0x02FFFFFF, 0xEEFFFFFF, 0xC092FFFF, 0xC002FFFF, 0xFFEEFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFF3FF, 
0xFFFFC085, 0xFFFFC002, 0x86FFFFF7, 0x02FFFFFF, 0xD1FFFFFF, 0xC090FFFF, 0xC002FFFF, 0xFFD1FFFF, 
0xFFFF86FF, 0xFFFF02FF, 0xFFFFD9FF, 0xFFFFC085, 0xFFFFC002, 0x86FFFFDD, 0x02FFFFFF, 0xEEFFFFFF, 
0xC090FFFF, 0xC002FFFF, 0xFFEEFFFF, 0xFFFF85FF, 0xFFFF03FF, 0xFFFFFBFF, 0x85FFFFC4, 0x03FFFFC0, 
0xC4FFFFC0, 0xFFFBFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC08E, 0xFFFFC002, 0x86FFFFD5, 
0x02FFFFFF, 0xDDFFFFFF, 0xC087FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 0xFFFF03FF, 0xFFFFFBFF, 
0x8CFFFFC8, 0x03FFFFC0, 0xC8FFFFC0, 0xFFFBFFFF, 0xFFFF85FF, 0xFFFF03FF, 0xFFFFF7FF, 0x87FFFFC4, 
0x03FFFFC0, 0xC4FFFFC0, 0xFFF7FFFF, 0xFFFF86FF, 0xFFFF03FF, 0xFFFFF7FF, 0x8AFFFFC8, 0x03FFFFC0, 
0xC8FFFFC0, 0xFFF7FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC089, 0xFFFFC002, 0x87FFFFD5, 
0x03FFFFFF, 0xFBFFFFFF, 0xFFD5FFFF, 0xFFC088FF, 0xFFC003FF, 0xFFFFD5FF, 0x86FFFFFB, 0x02FFFFFF, 
0xEAFFFFFF, 0xC08BFFFF, 0xC002FFFF, 0xFFE2FFFF, 0xFFFF88FF, 0xFFFF04FF, 0xFFFFF3FF, 0xC8FFFFDD, 
0xC082FFFF, 0xC004FFFF, 0xFFC4FFFF, 0xFFFFDDFF, 0x87FFFFEE, 0x03FFFFFF, 0xF7FFFFFF, 0xFFC4FFFF, 
0xFFC08CFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF97, 0xFFFFFF03, 0xC8FFFFFB, 0xC08DFFFF, 0xC003FFFF, 
0xFFC4FFFF, 0xFFFFEEFF, 0xFFFFFF95, 0xFFFFFF03, 0xCCFFFFF7, 0xC090FFFF, 0xC002FFFF, 0xFFEAFFFF, 
0xFFFF93FF, 0xFFFF03FF, 0xFFFFEEFF, 0x92FFFFC8, 0x03FFFFC0, 0xD5FFFFC0, 0xFFFBFFFF, 0xFFFF90FF, 
0xFFFF02FF, 0xFFFFDDFF, 0xFFFFC096, 0xFFFFC003, 0xFBFFFFDD, 0xFF8BFFFF, 0xFF03FFFF, 0xFFFBFFFF, 
0xFFFFDDFF, 0xFFFFC09A, 0xFFFFC004, 0xDDFFFFD1, 0xFFE6FFFF, 0xFFFF85FF, 0xFFFF04FF, 0xFFFFE6FF, 
0xD1FFFFDD, 0xC08EFFFF, 0xC001FFFF, 0x0000FFFF
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
