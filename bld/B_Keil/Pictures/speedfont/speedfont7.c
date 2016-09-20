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
 * Image Dimensions : Width=39, Height=60
 * Input Filename: C:\Users\liklon\Desktop\CM000\7\speedfont7.png
 * Data is RLE compressed
 * Uncompressed Data Size : 9.14 KB
 * Compressed Data Size : 1.27 KB
 * Compression Ratio : 86.09%
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
ALIGNED const uint32_t u32_speedfont7_RLE[SPEEDFONT7_SIZE] = {
0xFFFFE601, 0xFFFFFFA4, 0xFFFFFF03, 0xE6FFFFEE, 0xFFA4FFFF, 0xFF03FFFF, 0xFFEEFFFF, 0xFFFFE6FF, 
0xFFFFFFA4, 0xFFFFFF03, 0xE6FFFFEE, 0xFFA4FFFF, 0xFF03FFFF, 0xFFEEFFFF, 0xFFFFE6FF, 0xFFFFFFA4, 
0xFFFFFF03, 0xE6FFFFDD, 0xFFA3FFFF, 0xFF02FFFF, 0xFFF7FFFF, 0xFFC09EFF, 0xFFC002FF, 0xFFFFF7FF, 
0xFFFFFF85, 0xFFFFFF02, 0x9DFFFFD9, 0x02FFFFC0, 0xDDFFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFEEFFFF, 
0xFFC09DFF, 0xFFC003FF, 0xFFFFC4FF, 0x85FFFFFB, 0x02FFFFFF, 0xD1FFFFFF, 0xC09DFFFF, 0xC002FFFF, 
0xFFE6FFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFEAFF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFC8, 0x02FFFFFF, 
0xC8FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFEAFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFE6FF, 0xFFFFC09D, 
0xFFFFC002, 0x86FFFFD1, 0x02FFFFFF, 0xC8FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFEEFFFF, 0xFFFF85FF, 
0xFFFF02FF, 0xFFFFDDFF, 0xFFFFC09D, 0xFFFFC002, 0x85FFFFD1, 0x03FFFFFF, 0xFBFFFFFF, 0xFFC4FFFF, 
0xFFC09DFF, 0xFFC002FF, 0xFFFFF7FF, 0xFFFFFF85, 0xFFFFFF02, 0x9DFFFFDD, 0x02FFFFC0, 0xD9FFFFC0, 
0xFF85FFFF, 0xFF03FFFF, 0xFFFBFFFF, 0xFFFFC4FF, 0xFFFFC09D, 0xFFFFC002, 0x85FFFFF7, 0x02FFFFFF, 
0xDDFFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFD9FFFF, 0xFFFF85FF, 0xFFFF03FF, 0xFFFFFBFF, 0x9DFFFFC4, 
0x02FFFFC0, 0xF7FFFFC0, 0xFF85FFFF, 0xFF02FFFF, 0xFFDDFFFF, 0xFFC09DFF, 0xFFC002FF, 0xFFFFD9FF, 
0xFFFFFF85, 0xFFFFFF03, 0xC4FFFFFB, 0xC09DFFFF, 0xC002FFFF, 0xFFF7FFFF, 0xFFFF85FF, 0xFFFF02FF, 
0xFFFFE2FF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFD9, 0x02FFFFFF, 0xC8FFFFFF, 0xC09DFFFF, 0xC002FFFF, 
0xFFF7FFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFE6FF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFD1, 0x02FFFFFF, 
0xC8FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFEEFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFEEFF, 0xFFFFC09D, 
0xFFFFC002, 0x86FFFFD1, 0x02FFFFFF, 0xD1FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFEAFFFF, 0xFFFF85FF, 
0xFFFF02FF, 0xFFFFF3FF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFC8, 0x02FFFFFF, 0xD9FFFFFF, 0xC09DFFFF, 
0xC002FFFF, 0xFFE2FFFF, 0xFFFF85FF, 0xFFFF03FF, 0xFFFFFBFF, 0x9CFFFFC4, 0x03FFFFC0, 0xC4FFFFC0, 
0xFFFBFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFDDFF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFDD, 0x02FFFFFF, 
0xC8FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFF7FFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFEEFF, 0xFFFFC09D, 
0xFFFFC002, 0x86FFFFD1, 0x02FFFFFF, 0xD5FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFEAFFFF, 0xFFFF85FF, 
0xFFFF02FF, 0xFFFFFBFF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFC4, 0x02FFFFFF, 0xE2FFFFFF, 0xC09DFFFF, 
0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFCCFF, 0xFFFFC09D, 0xFFFFC002, 0x85FFFFF3, 
0x02FFFFFF, 0xF3FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFCCFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFDDFF, 
0xFFFFC09D, 0xFFFFC002, 0x86FFFFE2, 0x02FFFFFF, 0xC4FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFFBFFFF, 
0xFFFF85FF, 0xFFFF02FF, 0xFFFFEEFF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFD5, 0x02FFFFFF, 0xDDFFFFFF, 
0xC09DFFFF, 0xC002FFFF, 0xFFE6FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFC4FF, 0xFFFFC09D, 0xFFFFC002, 
0x85FFFFFB, 0x02FFFFFF, 0xEEFFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFD5FFFF, 0xFFFF86FF, 0xFFFF02FF, 
0xFFFFDDFF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFE6, 0x02FFFFFF, 0xCCFFFFFF, 0xC09DFFFF, 0xC002FFFF, 
0xFFFBFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFF3FF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFCC, 0x02FFFFFF, 
0xE2FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFDDFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC09D, 
0xFFFFC002, 0x86FFFFF3, 0x02FFFFFF, 0xC4FFFFFF, 0xC09CFFFF, 0xC002FFFF, 0xFFC4FFFF, 0xFFFF86FF, 
0xFFFF02FF, 0xFFFFF3FF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFD5, 0x02FFFFFF, 0xE2FFFFFF, 0xC09DFFFF, 
0xC002FFFF, 0xFFE2FFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFD5FF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFF3, 
0x02FFFFFF, 0xC4FFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFFBFFFF, 0xFFFF85FF, 0xFFFF02FF, 0xFFFFFBFF, 
0xFFFFC09D, 0xFFFFC002, 0x86FFFFCC, 0x02FFFFFF, 0xEAFFFFFF, 0xC09DFFFF, 0xC002FFFF, 0xFFD9FFFF, 
0xFFFF86FF, 0xFFFF02FF, 0xFFFFE2FF, 0xFFFFC09D, 0xFFFFC002, 0x86FFFFE2, 0x02FFFFFF, 0xD9FFFFFF, 
0xC09DFFFF, 0xC002FFFF, 0xFFEAFFFF, 0xFFFF86FF, 0xFFFF02FF, 0xFFFFCCFF, 0xFFFFC09D, 0xFFFFC002, 
0x86FFFFF7, 0x02FFFFFF, 0xC4FFFFFF, 0xC094FFFF, 0xC001FFFF, 0x0000FFFF
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
