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
 * Image Dimensions : Width=39, Height=61
 * Input Filename: C:\Users\liklon\Desktop\CM000\7\speedfont2.png
 * Data is RLE compressed
 * Uncompressed Data Size : 9.29 KB
 * Compressed Data Size : 1.53 KB
 * Compression Ratio : 83.50%
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
ALIGNED const uint32_t u32_speedfont2_RLE[SPEEDFONT2_SIZE] = {
0xFFFFC08B, 0xFFFFC004, 0xDDFFFFD9, 0xFFE2FFFF, 0xFFFF86FF, 0xFFFF04FF, 0xFFFFEAFF, 0xDDFFFFDD, 
0xC096FFFF, 0xC003FFFF, 0xFFD5FFFF, 0xFFFFEAFF, 0xFFFFFF8E, 0xFFFFFF03, 0xD9FFFFEE, 0xC091FFFF, 
0xC003FFFF, 0xFFD5FFFF, 0xFFFFF7FF, 0xFFFFFF92, 0xFFFFFF03, 0xD9FFFFFB, 0xC08DFFFF, 0xC003FFFF, 
0xFFC8FFFF, 0xFFFFEEFF, 0xFFFFFF96, 0xFFFFFF03, 0xC4FFFFEE, 0xC08AFFFF, 0xC003FFFF, 0xFFD1FFFF, 
0xFFFFFBFF, 0xFFFFFF98, 0xFFFFFF03, 0xCCFFFFF7, 0xC088FFFF, 0xC002FFFF, 0xFFD9FFFF, 0xFFFF9BFF, 
0xFFFF03FF, 0xFFFFFBFF, 0x87FFFFCC, 0x02FFFFC0, 0xF7FFFFC0, 0xFF88FFFF, 0xFF04FFFF, 0xFFE2FFFF, 
0xFFFFDDFF, 0x83FFFFC4, 0x04FFFFC0, 0xC8FFFFC0, 0xFFDDFFFF, 0xFFFFEAFF, 0xFFFFFF89, 0xFFFFFF03, 
0xC4FFFFF7, 0xC086FFFF, 0xC002FFFF, 0xFFF7FFFF, 0xFFFF85FF, 0xFFFF03FF, 0xFFFFF3FF, 0x8AFFFFD9, 
0x03FFFFC0, 0xC4FFFFC0, 0xFFE6FFFF, 0xFFFF88FF, 0xFFFF02FF, 0xFFFFE6FF, 0xFFFFC086, 0xFFFFC002, 
0x83FFFFF7, 0x03FFFFFF, 0xF7FFFFFF, 0xFFD5FFFF, 0xFFC08EFF, 0xFFC003FF, 0xFFFFD1FF, 0x87FFFFFB, 
0x02FFFFFF, 0xCCFFFFFF, 0xC085FFFF, 0xC002FFFF, 0xFFF7FFFF, 0xFFFF82FF, 0xFFFF02FF, 0xFFFFE2FF, 
0xFFFFC091, 0xFFFFC002, 0x87FFFFCC, 0x02FFFFFF, 0xE6FFFFFF, 0xC085FFFF, 0xC005FFFF, 0xFFF7FFFF, 
0xFFFFFFFF, 0xD1FFFFFB, 0xC093FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF87FF, 0xFFFF02FF, 0xFFFFC4FF, 
0xFFFFC084, 0xFFFFC004, 0xF7FFFFF7, 0xFFC8FFFF, 0xFFC095FF, 0xFFC002FF, 0xFFFFF7FF, 0xFFFFFF86, 
0xFFFFFF02, 0x84FFFFD5, 0x03FFFFC0, 0xEEFFFFC0, 0xFFC8FFFF, 0xFFC096FF, 0xFFC002FF, 0xFFFFDDFF, 
0xFFFFFF86, 0xFFFFFF02, 0x84FFFFE2, 0x02FFFFC0, 0xC4FFFFC0, 0xC097FFFF, 0xC002FFFF, 0xFFC4FFFF, 
0xFFFF86FF, 0xFFFF02FF, 0xFFFFEEFF, 0xFFFFC09E, 0xFFFFC002, 0x85FFFFF7, 0x02FFFFFF, 0xF7FFFFFF, 
0xC09EFFFF, 0xC002FFFF, 0xFFEEFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFF7FF, 0xFFFFC09E, 0xFFFFC002, 
0x85FFFFEE, 0x02FFFFFF, 0xF7FFFFFF, 0xC09EFFFF, 0xC002FFFF, 0xFFEEFFFF, 0xFFFF85FF, 0xFFFF02FF, 
0xFFFFF7FF, 0xFFFFC09E, 0xFFFFC002, 0x85FFFFF3, 0x02FFFFFF, 0xF3FFFFFF, 0xC09EFFFF, 0xC002FFFF, 
0xFFFBFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFEAFF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFCC, 0x02FFFFFF, 
0xE2FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC09D, 
0xFFFFC002, 0x86FFFFF3, 0x02FFFFFF, 0xC8FFFFFF, 0xC09CFFFF, 0xC002FFFF, 0xFFD1FFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFF3FF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFF3, 0x02FFFFFF, 0xDDFFFFFF, 0xC09CFFFF, 
0xC002FFFF, 0xFFE2FFFF, 0xFFFF87FF, 0xFFFF02FF, 0xFFFFC8FF, 0xFFFFC09B, 0xFFFFC002, 0x87FFFFD5, 
0x02FFFFFF, 0xE6FFFFFF, 0xC09BFFFF, 0xC002FFFF, 0xFFCCFFFF, 0xFFFF87FF, 0xFFFF03FF, 0xFFFFFBFF, 
0x9AFFFFC8, 0x03FFFFC0, 0xD1FFFFC0, 0xFFFBFFFF, 0xFFFF87FF, 0xFFFF02FF, 0xFFFFDDFF, 0xFFFFC09A, 
0xFFFFC002, 0x88FFFFD5, 0x02FFFFFF, 0xEAFFFFFF, 0xC09AFFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF88FF, 
0xFFFF03FF, 0xFFFFF3FF, 0x99FFFFC4, 0x02FFFFC0, 0xEAFFFFC0, 0xFF88FFFF, 0xFF03FFFF, 0xFFF7FFFF, 
0xFFFFC8FF, 0xFFFFC098, 0xFFFFC003, 0xF7FFFFCC, 0xFF88FFFF, 0xFF03FFFF, 0xFFF7FFFF, 0xFFFFC8FF, 
0xFFFFC098, 0xFFFFC002, 0x89FFFFD9, 0x03FFFFFF, 0xF7FFFFFF, 0xFFC8FFFF, 0xFFC097FF, 0xFFC003FF, 
0xFFFFC4FF, 0x89FFFFEE, 0x03FFFFFF, 0xF3FFFFFF, 0xFFC4FFFF, 0xFFC097FF, 0xFFC003FF, 0xFFFFD5FF, 
0x89FFFFFB, 0x02FFFFFF, 0xEAFFFFFF, 0xC098FFFF, 0xC002FFFF, 0xFFE2FFFF, 0xFFFF8AFF, 0xFFFF02FF, 
0xFFFFD9FF, 0xFFFFC097, 0xFFFFC003, 0xF3FFFFC8, 0xFF89FFFF, 0xFF03FFFF, 0xFFF3FFFF, 0xFFFFCCFF, 
0xFFFFC097, 0xFFFFC003, 0xFBFFFFD1, 0xFF89FFFF, 0xFF02FFFF, 0xFFE2FFFF, 0xFFC098FF, 0xFFC002FF, 
0xFFFFD9FF, 0xFFFFFF89, 0xFFFFFF03, 0xD1FFFFF7, 0xC098FFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF89FF, 
0xFFFF03FF, 0xFFFFEAFF, 0x98FFFFC4, 0x02FFFFC0, 0xE2FFFFC0, 0xFF89FFFF, 0xFF02FFFF, 0xFFD9FFFF, 
0xFFC099FF, 0xFFC002FF, 0xFFFFDDFF, 0xFFFFFF88, 0xFFFFFF03, 0xCCFFFFF7, 0xC099FFFF, 0xC002FFFF, 
0xFFDDFFFF, 0xFFFF88FF, 0xFFFF02FF, 0xFFFFEAFF, 0xFFFFC09A, 0xFFFFC002, 0x88FFFFCC, 0x02FFFFFF, 
0xDDFFFFFF, 0xC09AFFFF, 0xC003FFFF, 0xFFC4FFFF, 0xFFFFF7FF, 0xFFFFFF87, 0xFFFFFF02, 0x9BFFFFD1, 
0x02FFFFC0, 0xE2FFFFC0, 0xFF87FFFF, 0xFF02FFFF, 0xFFCCFFFF, 0xFFC09BFF, 0xFFC002FF, 0xFFFFC8FF, 
0xFFFFFF87, 0xFFFFFF02, 0x9CFFFFD1, 0x02FFFFC0, 0xE6FFFFC0, 0xFF86FFFF, 0xFF02FFFF, 0xFFDDFFFF, 
0xFFC09CFF, 0xFFC002FF, 0xFFFFC4FF, 0xFFFFFF86, 0xFFFFFF02, 0x9DFFFFF7, 0x02FFFFC0, 0xD9FFFFC0, 
0xFF86FFFF, 0xFF02FFFF, 0xFFD9FFFF, 0xFFC09DFF, 0xFFC002FF, 0xFFFFEAFF, 0xFFFFFF86, 0xFFFFFF02, 
0x9DFFFFC4, 0x02FFFFC0, 0xF3FFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFF3FFFF, 0xFFC09DFF, 0xFFC002FF, 
0xFFFFC4FF, 0xFFFFFF86, 0xFFFFFF02, 0x9DFFFFEA, 0x02FFFFC0, 0xCCFFFFC0, 0xFF86FFFF, 0xFF02FFFF, 
0xFFE6FFFF, 0xFFC09DFF, 0xFFC002FF, 0xFFFFD1FF, 0xFFFFFFA4, 0xFFFFFF03, 0xD5FFFFEE, 0xFFA4FFFF, 
0xFF03FFFF, 0xFFEEFFFF, 0xFFFFD9FF, 0xFFFFFFA4, 0xFFFFFF03, 0xD9FFFFEE, 0xFFA4FFFF, 0xFF03FFFF, 
0xFFEEFFFF, 0xFFFFD9FF, 0xFFFFFFA4, 0xFFFFFF03, 0xD9FFFFEE, 0xFFA4FFFF, 0xFF01FFFF, 0xEE01FFFF, 
0x0000FFFF
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
