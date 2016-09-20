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
 * Input Filename: C:\Users\liklon\Desktop\CM000\12\AA24.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.47 KB
 * Compression Ratio : 56.96%
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
ALIGNED const uint32_t u32_AA24_RLE[AA24_SIZE] = {
0x0000009C, 0x00000005, 0xDFFFFFD5, 0xFFDFFFFF, 0xFFFFC5FF, 0x00000084, 0x0000000A, 0xDFFFFFC3, 
0xFFDFFFFF, 0xFFFFD7FF, 0xD3000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x84FFFFE3, 0x0B000000, 0xDB000000, 
0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFDB, 0x00000000, 0xFFFFF300, 0xFDFFFFFF, 0xFFC5FFFF, 0x000082FF, 
0x00000C00, 0xFFFFC100, 0xFFFFFFF9, 0xFFF9FFFF, 0xFFFFC1FF, 0x00000000, 0xFFD30000, 0xFFFFFFFF, 
0xE3FFFFFF, 0x0082FFFF, 0x00050000, 0xFFDB0000, 0xFFFFFFFF, 0xDBFFFFFF, 0x0083FFFF, 0x000B0000, 
0xFFF30000, 0xFFFFFFFF, 0xC5FFFFFD, 0x0000FFFF, 0xFFFFC100, 0xFFFFFFF9, 0xFFF9FFFF, 0xFFFFC1FF, 
0x00000083, 0x0000000A, 0xFFFFFFD3, 0xFFFFFFFF, 0xFFFFE3FF, 0xDB000000, 0xFFFFFFFF, 0xFFFFFFFF, 
0x85FFFFDB, 0x09000000, 0xF3000000, 0xFFFFFFFF, 0xFFFFFDFF, 0xF9FFFFC7, 0xFFFFFFFF, 0xFFFFF9FF, 
0x85FFFFC1, 0x08000000, 0xD3000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFEF, 0xFFFFFFFF, 0xFFFFDBFF, 
0x00000087, 0x00000002, 0x82FFFFF3, 0x03FFFFFF, 0xFDFFFFFF, 0xFFC1FFFF, 0x000087FF, 0x00000200, 
0xFFFFD300, 0xFFFFFF82, 0xFFFFFF02, 0x89FFFFE3, 0x05000000, 0xF9000000, 0xFFFFFFFF, 0xFFFFFFFF, 
0x89FFFFC5, 0x04000000, 0xF7000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000008A, 0x00000004, 0xFFFFFFF7, 
0xFFFFFFFF, 0x00008AFF, 0x00000400, 0xFFFFF700, 0xFFFFFFFF, 0x008AFFFF, 0x00040000, 0xFFF70000, 
0xFFFFFFFF, 0x8AFFFFFF, 0x04000000, 0xF7000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000008A, 0x00000004, 
0xFFFFFFF7, 0xFFFFFFFF, 0x00008AFF, 0x00000400, 0xFFFFF700, 0xFFFFFFFF, 0x0084FFFF, 0x00010000, 
0x00000000
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
