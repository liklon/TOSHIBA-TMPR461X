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
 * Input Filename: C:\Users\liklon\Desktop\CM000\13\a0.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.46 KB
 * Compression Ratio : 57.77%
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
ALIGNED const uint32_t u32_a0_RLE[A0_SIZE] = {
0x000000CA, 0x00000002, 0x82FFFFD1, 0x02FFFFDF, 0xD3FFFFDF, 0x0086FFFF, 0x00030000, 0xFFC30000, 
0xFFFFEFFF, 0xFFFFFF84, 0xFFFFFF03, 0xCBFFFFF7, 0x0084FFFF, 0x00020000, 0xFFEF0000, 0xFFFF82FF, 
0xFFFF07FF, 0xFFFFF1FF, 0xFFFFFFF3, 0xFFFFFFFF, 0xFFFFF5FF, 0x82FFFFC1, 0x05000000, 0xCB000000, 
0xFFFFFFFF, 0xFFFFFFFF, 0x82FFFFF3, 0x05000000, 0xE5000000, 0xFFFFFFFF, 0xFFFFFFFF, 0x82FFFFCB, 
0x05000000, 0xCB000000, 0xFFDFFFFF, 0xFFFFDFFF, 0x82FFFFCD, 0x05000000, 0xE1000000, 0xFFFFFFFF, 
0xFFFFFFFF, 0x84FFFFD7, 0x05000000, 0xC7000000, 0xFFD7FFFF, 0xFFFFE9FF, 0x83FFFFF3, 0x02FFFFFF, 
0xD7FFFFFF, 0x0083FFFF, 0x00030000, 0xFFE10000, 0xFFFFFDFF, 0xFFFFFF83, 0xFFFFFF05, 0xFFFFFFF9, 
0xFFFFFFFF, 0xFFFFD7FF, 0x00000082, 0x0000000C, 0xFFFFFFDD, 0xFFFFFFFF, 0xFFFFF7FF, 0xD5FFFFE1, 
0xFFC9FFFF, 0xFFFFCFFF, 0xFFFFFFFF, 0xFFD7FFFF, 0x000082FF, 0x00000500, 0xFFFFF300, 0xFFFFFFFF, 
0xFFC5FFFF, 0x000082FF, 0x00000500, 0xFFFFDB00, 0xFFFFFFFF, 0xFFD7FFFF, 0x000082FF, 0x00000800, 
0xFFFFF500, 0xFDFFFFFF, 0xFFC5FFFF, 0x000000FF, 0xD9000000, 0xFF82FFFF, 0xFF02FFFF, 0xFFD7FFFF, 
0x000082FF, 0x00000700, 0xFFFFE900, 0xFFFFFFFF, 0xFFF9FFFF, 0xFFFFEFFF, 0x83FFFFFB, 0x02FFFFFF, 
0xDBFFFFFF, 0x0082FFFF, 0x00030000, 0xFFC70000, 0xFFFFF7FF, 0xFFFFFF84, 0xFFFFFF05, 0xFFFFFFE5, 
0xFFFFFFFF, 0xFFFFEBFF, 0x00000083, 0x0000000C, 0xD7FFFFC1, 0xFFE3FFFF, 0xFFFFE7FF, 0xC9FFFFDB, 
0x0000FFFF, 0xFFFFD900, 0xDFFFFFDF, 0xFFC1FFFF, 0x00009BFF, 0x00000100, 0x00000000
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
