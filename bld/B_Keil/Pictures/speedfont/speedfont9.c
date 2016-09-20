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
 * Image Dimensions : Width=40, Height=62
 * Input Filename: C:\Users\liklon\Desktop\CM000\7\speedfont9.png
 * Data is RLE compressed
 * Uncompressed Data Size : 9.69 KB
 * Compressed Data Size : 2.18 KB
 * Compression Ratio : 77.47%
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
ALIGNED const uint32_t u32_speedfont9_RLE[SPEEDFONT9_SIZE] = {
0xFFFFC08D, 0xFFFFC004, 0xDDFFFFCC, 0xFFDDFFFF, 0xFFFF85FF, 0xFFFF04FF, 0xFFFFF7FF, 0xDDFFFFDD, 
0xC098FFFF, 0xC003FFFF, 0xFFC8FFFF, 0xFFFFDDFF, 0xFFFFFF8D, 0xFFFFFF03, 0xD1FFFFEE, 0xC093FFFF, 
0xC003FFFF, 0xFFC4FFFF, 0xFFFFE6FF, 0xFFFFFF91, 0xFFFFFF03, 0xC8FFFFEE, 0xC090FFFF, 0xC003FFFF, 
0xFFD5FFFF, 0xFFFFFBFF, 0xFFFFFF94, 0xFFFFFF02, 0x8EFFFFD5, 0x02FFFFC0, 0xDDFFFFC0, 0xFF97FFFF, 
0xFF02FFFF, 0xFFDDFFFF, 0xFFC08CFF, 0xFFC002FF, 0xFFFFE6FF, 0xFFFFFF99, 0xFFFFFF02, 0x8AFFFFDD, 
0x02FFFFC0, 0xDDFFFFC0, 0xFF88FFFF, 0xFF04FFFF, 0xFFFBFFFF, 0xFFFFDDFF, 0x83FFFFD1, 0x03FFFFC0, 
0xD5FFFFC0, 0xFFDDFFFF, 0xFFFF89FF, 0xFFFF02FF, 0xFFFFCCFF, 0xFFFFC088, 0xFFFFC002, 0x88FFFFD5, 
0x02FFFFFF, 0xDDFFFFFF, 0xC089FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF87FF, 0xFFFF03FF, 0xFFFFFBFF, 
0x86FFFFC4, 0x03FFFFC0, 0xC8FFFFC0, 0xFFFBFFFF, 0xFFFF86FF, 0xFFFF03FF, 0xFFFFF7FF, 0x8BFFFFCC, 
0x03FFFFC0, 0xD1FFFFC0, 0xFFFBFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFE6FF, 0xFFFFC086, 0xFFFFC002, 
0x86FFFFE6, 0x03FFFFFF, 0xFBFFFFFF, 0xFFC8FFFF, 0xFFC08DFF, 0xFFC002FF, 0xFFFFCCFF, 0xFFFFFF87, 
0xFFFFFF02, 0x84FFFFC8, 0x02FFFFC0, 0xC8FFFFC0, 0xFF87FFFF, 0xFF02FFFF, 0xFFCCFFFF, 0xFFC08FFF, 
0xFFC002FF, 0xFFFFD5FF, 0xFFFFFF86, 0xFFFFFF02, 0x84FFFFE6, 0x02FFFFC0, 0xE6FFFFC0, 0xFF86FFFF, 
0xFF02FFFF, 0xFFE2FFFF, 0xFFC091FF, 0xFFC002FF, 0xFFFFEAFF, 0xFFFFFF86, 0xFFFFFF02, 0x82FFFFC8, 
0x03FFFFC0, 0xC4FFFFC0, 0xFFFBFFFF, 0xFFFF85FF, 0xFFFF03FF, 0xFFFFFBFF, 0x91FFFFC4, 0x02FFFFC0, 
0xC8FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFDDFFFF, 0xFFC082FF, 0xFFC002FF, 0xFFFFD5FF, 0xFFFFFF86, 
0xFFFFFF02, 0x93FFFFE6, 0x02FFFFC0, 0xEAFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF3FFFF, 0xFFC082FF, 
0xFFC002FF, 0xFFFFE2FF, 0xFFFFFF86, 0xFFFFFF02, 0x93FFFFD5, 0x02FFFFC0, 0xD5FFFFC0, 0xFF86FFFF, 
0xFF05FFFF, 0xFFCCFFFF, 0xFFFFC0FF, 0xEEFFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFC4FFFF, 0xFFC093FF, 
0xFFC002FF, 0xFFFFC4FF, 0xFFFFFF86, 0xFFFFFF05, 0xC0FFFFDD, 0xFFC0FFFF, 0xFFFFFBFF, 0xFFFFFF85, 
0xFFFFFF02, 0x95FFFFF7, 0x02FFFFC0, 0xF3FFFFC0, 0xFF85FFFF, 0xFF04FFFF, 0xFFEAFFFF, 0xFFFFC0FF, 
0x86FFFFC0, 0x02FFFFFF, 0xEEFFFFFF, 0xC095FFFF, 0xC002FFFF, 0xFFE6FFFF, 0xFFFF85FF, 0xFFFF04FF, 
0xFFFFF3FF, 0xC8FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFEEFFFF, 0xFFC095FF, 0xFFC002FF, 0xFFFFDDFF, 
0xFFFFFF86, 0xFFFFFF03, 0xC8FFFFC4, 0xFF86FFFF, 0xFF02FFFF, 0xFFEEFFFF, 0xFFC095FF, 0xFFC002FF, 
0xFFFFD9FF, 0xFFFFFF86, 0xFFFFFF03, 0xC8FFFFCC, 0xFF86FFFF, 0xFF02FFFF, 0xFFEEFFFF, 0xFFC095FF, 
0xFFC002FF, 0xFFFFD9FF, 0xFFFFFF86, 0xFFFFFF03, 0xC4FFFFD5, 0xFF86FFFF, 0xFF02FFFF, 0xFFF7FFFF, 
0xFFC095FF, 0xFFC002FF, 0xFFFFD9FF, 0xFFFFFF86, 0xFFFFFF03, 0xC0FFFFDD, 0xFF87FFFF, 0xFF02FFFF, 
0xFFC4FFFF, 0xFFC094FF, 0xFFC002FF, 0xFFFFDDFF, 0xFFFFFF86, 0xFFFFFF04, 0xC0FFFFDD, 0xFFF3FFFF, 
0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC094, 0xFFFFC002, 0x86FFFFEA, 0x04FFFFFF, 0xE6FFFFFF, 
0xFFC0FFFF, 0xFFFFEAFF, 0xFFFFFF86, 0xFFFFFF02, 0x94FFFFE2, 0x02FFFFC0, 0xFBFFFFC0, 0xFF86FFFF, 
0xFF04FFFF, 0xFFE6FFFF, 0xFFFFC0FF, 0x86FFFFDD, 0x02FFFFFF, 0xFBFFFFFF, 0xC093FFFF, 0xC002FFFF, 
0xFFD5FFFF, 0xFFFF87FF, 0xFFFF04FF, 0xFFFFEAFF, 0xC4FFFFC0, 0xFF87FFFF, 0xFF02FFFF, 0xFFDDFFFF, 
0xFFC092FF, 0xFFC002FF, 0xFFFFF3FF, 0xFFFFFF87, 0xFFFFFF05, 0xC0FFFFEE, 0xFFC0FFFF, 0xFFFFEEFF, 
0xFFFFFF86, 0xFFFFFF03, 0xC8FFFFFB, 0xC090FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF88FF, 0xFFFF05FF, 
0xFFFFEEFF, 0xC0FFFFC0, 0xFFD1FFFF, 0xFFFF87FF, 0xFFFF03FF, 0xFFFFF3FF, 0x8EFFFFC4, 0x02FFFFC0, 
0xD9FFFFC0, 0xFF89FFFF, 0xFF02FFFF, 0xFFEEFFFF, 0xFFC082FF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF87, 
0xFFFFFF03, 0xC4FFFFF3, 0xC08CFFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF8AFF, 0xFFFF02FF, 0xFFFFEEFF, 
0xFFFFC082, 0xFFFFC002, 0x88FFFFC8, 0x03FFFFFF, 0xFBFFFFFF, 0xFFD9FFFF, 0xFFC089FF, 0xFFC003FF, 
0xFFFFC8FF, 0x8BFFFFEA, 0x02FFFFFF, 0xE6FFFFFF, 0xC083FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF89FF, 
0xFFFF04FF, 0xFFFFFBFF, 0xD5FFFFDD, 0xC084FFFF, 0xC003FFFF, 0xFFDDFFFF, 0xFFFFEAFF, 0xFFFFFF85, 
0xFFFFFF02, 0x86FFFFE2, 0x02FFFFFF, 0xE6FFFFFF, 0xC084FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF97FF, 
0xFFFF03FF, 0xFFFFF7FF, 0x86FFFFC4, 0x02FFFFFF, 0xE2FFFFFF, 0xC085FFFF, 0xC002FFFF, 0xFFDDFFFF, 
0xFFFF95FF, 0xFFFF04FF, 0xFFFFFBFF, 0xC0FFFFC8, 0xFF86FFFF, 0xFF02FFFF, 0xFFDDFFFF, 0xFFC086FF, 
0xFFC002FF, 0xFFFFD5FF, 0xFFFFFF93, 0xFFFFFF05, 0xCCFFFFF7, 0xFFC0FFFF, 0xFFFFC0FF, 0xFFFFFF86, 
0xFFFFFF02, 0x87FFFFD9, 0x03FFFFC0, 0xC8FFFFC0, 0xFFEEFFFF, 0xFFFF90FF, 0xFFFF06FF, 0xFFFFEAFF, 
0xC0FFFFC4, 0xFFC0FFFF, 0xFFFFC8FF, 0xFFFFFF86, 0xFFFFFF02, 0x89FFFFD5, 0x03FFFFC0, 0xD1FFFFC0, 
0xFFEAFFFF, 0xFFFF8CFF, 0xFFFF03FF, 0xFFFFEEFF, 0x83FFFFD5, 0x02FFFFC0, 0xCCFFFFC0, 0xFF86FFFF, 
0xFF02FFFF, 0xFFCCFFFF, 0xFFC08CFF, 0xFFC004FF, 0xFFFFDDFF, 0xF7FFFFDD, 0xFF84FFFF, 0xFF05FFFF, 
0xFFFBFFFF, 0xFFFFDDFF, 0xC4FFFFDD, 0xC085FFFF, 0xC002FFFF, 0xFFD5FFFF, 0xFFFF86FF, 0xFFFF01FF, 
0xFFC09FFF, 0xFFC002FF, 0xFFFFDDFF, 0xFFFFFF85, 0xFFFFFF02, 0x9FFFFFF7, 0x02FFFFC0, 0xE6FFFFC0, 
0xFF85FFFF, 0xFF02FFFF, 0xFFEAFFFF, 0xFFC09FFF, 0xFFC002FF, 0xFFFFF3FF, 0xFFFFFF85, 0xFFFFFF02, 
0x9EFFFFDD, 0x02FFFFC0, 0xC4FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFD1FFFF, 0xFFC09EFF, 0xFFC002FF, 
0xFFFFD5FF, 0xFFFFFF85, 0xFFFFFF02, 0x9FFFFFFB, 0x02FFFFC0, 0xE2FFFFC0, 0xFF85FFFF, 0xFF02FFFF, 
0xFFEAFFFF, 0xFFC09FFF, 0xFFC002FF, 0xFFFFFBFF, 0xFFFFFF85, 0xFFFFFF02, 0x9EFFFFDD, 0x02FFFFC0, 
0xD5FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFC4FFFF, 0xFFC09EFF, 0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 
0xFFFFFF02, 0x9EFFFFEA, 0x02FFFFC0, 0xD1FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFD1FFFF, 0xFFC09EFF, 
0xFFC002FF, 0xFFFFEEFF, 0xFFFFFF85, 0xFFFFFF02, 0x9EFFFFF7, 0x02FFFFC0, 0xDDFFFFC0, 0xFF86FFFF, 
0xFF02FFFF, 0xFFD9FFFF, 0xFFC09DFF, 0xFFC002FF, 0xFFFFCCFF, 0xFFFFFF86, 0xFFFFFF02, 0x9DFFFFF3, 
0x03FFFFC0, 0xC8FFFFC0, 0xFFF7FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFCCFF, 0xFFFFC088, 0xFFFFC002, 
0x92FFFFC4, 0x03FFFFC0, 0xCCFFFFC0, 0xFFF7FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFE2FF, 0xFFFFC089, 
0xFFFFC003, 0xDDFFFFF7, 0xC090FFFF, 0xC002FFFF, 0xFFD9FFFF, 0xFFFF87FF, 0xFFFF02FF, 0xFFFFF3FF, 
0xFFFFC08A, 0xFFFFC006, 0xFFFFFFF7, 0xFFFBFFFF, 0xFFFFDDFF, 0x8BFFFFC4, 0x03FFFFC0, 0xD5FFFFC0, 
0xFFEEFFFF, 0xFFFF87FF, 0xFFFF03FF, 0xFFFFF7FF, 0x8AFFFFC8, 0x02FFFFC0, 0xF7FFFFC0, 0xFF83FFFF, 
0xFF04FFFF, 0xFFF3FFFF, 0xFFFFDDFF, 0x85FFFFDD, 0x04FFFFC0, 0xDDFFFFC0, 0xFFDDFFFF, 0xFFFFFBFF, 
0xFFFFFF88, 0xFFFFFF03, 0xCCFFFFFB, 0xC08BFFFF, 0xC002FFFF, 0xFFF7FFFF, 0xFFFF97FF, 0xFFFF03FF, 
0xFFFFFBFF, 0x8CFFFFCC, 0x02FFFFC0, 0xF7FFFFC0, 0xFF96FFFF, 0xFF03FFFF, 0xFFF3FFFF, 0xFFFFC8FF, 
0xFFFFC08D, 0xFFFFC002, 0x95FFFFF7, 0x02FFFFFF, 0xDDFFFFFF, 0xC08FFFFF, 0xC003FFFF, 0xFFC4FFFF, 
0xFFFFE6FF, 0xFFFFFF92, 0xFFFFFF03, 0xC8FFFFEA, 0xC092FFFF, 0xC003FFFF, 0xFFCCFFFF, 0xFFFFE2FF, 
0xFFFFFF8E, 0xFFFFFF03, 0xC8FFFFDD, 0xC097FFFF, 0xC004FFFF, 0xFFD9FFFF, 0xFFFFDDFF, 0x85FFFFEA, 
0x05FFFFFF, 0xF7FFFFFF, 0xFFDDFFFF, 0xFFFFDDFF, 0x91FFFFCC, 0x01FFFFC0, 0x00FFFFC0
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
