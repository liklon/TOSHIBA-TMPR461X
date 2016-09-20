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
 * Input Filename: C:\Users\liklon\Desktop\CM000\13\a10.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.54 KB
 * Compression Ratio : 50.27%
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
ALIGNED const uint32_t u32_a10_RLE[A10_SIZE] = {
0x00000005, 0xE7000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000008A, 0x00000004, 0xFFFFFFE7, 0xFFFFFFFF, 
0x00008AFF, 0x00000400, 0xFFFFE700, 0xFFFFFFFF, 0x008AFFFF, 0x00040000, 0xFFE70000, 0xFFFFFFFF, 
0x8AFFFFFF, 0x04000000, 0xE7000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000008A, 0x00000004, 0xFFFFFFE7, 
0xFFFFFFFF, 0x000083FF, 0x00000500, 0xFFFFCD00, 0xDFFFFFDF, 0xFFD1FFFF, 0x000082FF, 0x00000400, 
0xFFFFE700, 0xFFFFFFFF, 0x0082FFFF, 0x00060000, 0xFFCB0000, 0xFFFFFBFF, 0xF3FFFFFF, 0xFFC3FFFF, 
0x000082FF, 0x00000B00, 0xFFFFE700, 0xFFFFFFFF, 0x0000FFFF, 0x00000000, 0xFBFFFFC7, 0xFFFFFFFF, 
0xFFFFF3FF, 0x83FFFFC3, 0x0A000000, 0xE7000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xC7000000, 0xFFF7FFFF, 
0xFFFFFFFF, 0xC3FFFFF7, 0x0084FFFF, 0x00090000, 0xFFE70000, 0xFFFFFFFF, 0xC3FFFFFF, 0xFFF7FFFF, 
0xFFFFFFFF, 0xC7FFFFFB, 0x0085FFFF, 0x00050000, 0xFFE70000, 0xFFFFFFFF, 0xF3FFFFFF, 0xFF82FFFF, 
0xFF02FFFF, 0xFFCBFFFF, 0x000085FF, 0x00000200, 0xFFFFE700, 0xFFFFFF82, 0xFFFFFF05, 0xF3FFFFF3, 
0xFFFFFFFF, 0xFFFFF3FF, 0x00000085, 0x0000000A, 0xFFFFFFE7, 0xFFFFFFFF, 0xFFFFF3FF, 0xD1FFFFC3, 
0xFFFFFFFF, 0xFFFFFFFF, 0x84FFFFD9, 0x0B000000, 0xE7000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFC3, 
0x00000000, 0xFFFFEB00, 0xFBFFFFFF, 0xFFC5FFFF, 0x000083FF, 0x00000400, 0xFFFFE700, 0xFFFFFFFF, 
0x0082FFFF, 0x00050000, 0xFFCB0000, 0xFFFFFDFF, 0xE7FFFFFF, 0x0083FFFF, 0x00040000, 0xFFE70000, 
0xFFFFFFFF, 0x83FFFFFF, 0x05000000, 0xE3000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x82FFFFCD, 0x04000000, 
0xE7000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000083, 0x00000005, 0xF9FFFFC5, 0xFFFFFFFF, 0xFFFFF3FF, 
0x00000082, 0x00000004, 0xDFFFFFD3, 0xFFDFFFFF, 0x000084FF, 0x00000500, 0xFFFFD100, 0xDFFFFFDF, 
0xFFC9FFFF, 0x00009BFF, 0x00000100, 0x00000000
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
