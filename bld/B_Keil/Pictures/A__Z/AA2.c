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
 * Input Filename: C:\Users\liklon\Desktop\CM000\12\AA2.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.57 KB
 * Compression Ratio : 47.50%
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
ALIGNED const uint32_t u32_AA2_RLE[AA2_SIZE] = {
0x000000A1, 0x00000006, 0xDBFFFFCD, 0xFFDFFFFF, 0xFFFFCFFF, 0x86FFFFC3, 0x03000000, 0xC7000000, 
0xFFF7FFFF, 0xFFFF83FF, 0xFFFF03FF, 0xFFFFF9FF, 0x84FFFFCD, 0x03000000, 0xCB000000, 0xFFF9FFFF, 
0xFFFF86FF, 0xFFFF02FF, 0xFFFFCBFF, 0x00000083, 0x0000000B, 0xFFFFFFED, 0xFFFFFFFF, 0xFFFFE7FF, 
0x00FFFFC3, 0xFFD70000, 0xFFFFFFFF, 0xF1FFFFFF, 0x0082FFFF, 0x00060000, 0xFFCB0000, 0xFFFFFFFF, 
0xF3FFFFFF, 0xFFC1FFFF, 0x000082FF, 0x00000B00, 0xFFFFF100, 0xFFFFFFFF, 0xFFCDFFFF, 0x000000FF, 
0xE3000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x83FFFFDD, 0x0B000000, 0xDF000000, 0xFFFFFFFF, 0xFFFFFFFF, 
0x00FFFFD3, 0x00000000, 0xFFFFF300, 0xFFFFFFFF, 0xFFC9FFFF, 0x000083FF, 0x00000B00, 0xFFFFD700, 
0xFFFFFFFF, 0xFFD9FFFF, 0x000000FF, 0xF9000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x83FFFFC3, 0x07000000, 
0xC5000000, 0xFFCFFFFF, 0xFFFFCFFF, 0x00FFFFC7, 0xFFC10000, 0xFFFF82FF, 0xFFFF01FF, 0x000089FF, 
0x00000500, 0xFFFFC700, 0xFFFFFFFF, 0xFFF7FFFF, 0x000089FF, 0x00000500, 0xFFFFC700, 0xFFFFFFFF, 
0xFFF9FFFF, 0x000089FF, 0x00000200, 0xFFFFC100, 0xFFFFFF82, 0xFFFFFF01, 0x00000084, 0x0000000B, 
0xFFFFFFD7, 0xFFFFFFFF, 0xFFFFE3FF, 0x00000000, 0xFFF90000, 0xFFFFFFFF, 0xC5FFFFFF, 0x0083FFFF, 
0x000B0000, 0xFFDB0000, 0xFFFFFFFF, 0xDBFFFFFF, 0x0000FFFF, 0x00000000, 0xFFFFFFF3, 0xFFFFFFFF, 
0xFFFFD5FF, 0x00000083, 0x0000000B, 0xFFFFFFE1, 0xFFFFFFFF, 0xFFFFD1FF, 0x00000000, 0xFFDB0000, 
0xFFFFFFFF, 0xE9FFFFFF, 0x0083FFFF, 0x00120000, 0xFFF70000, 0xFFFFFFFF, 0xC7FFFFFF, 0x0000FFFF, 
0x00000000, 0xF9FFFFC1, 0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFD7, 0x00000000, 0xFFFFDF00, 0xFFFFFFFF, 
0xFFEBFFFF, 0x000083FF, 0x00000200, 0xFFFFD700, 0xFFFFFF82, 0xFFFFFF03, 0xF7FFFFF7, 0xFF82FFFF, 
0xFF02FFFF, 0xFFCBFFFF, 0x000084FF, 0x00000300, 0xFFFFD300, 0x83FFFFFB, 0x04FFFFFF, 0xF9FFFFFF, 
0xFFD1FFFF, 0x000000FF, 0x00000001
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
