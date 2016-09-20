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
 * Input Filename: C:\Users\liklon\Desktop\CM000\13\a2.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.42 KB
 * Compression Ratio : 61.96%
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
ALIGNED const uint32_t u32_a2_RLE[A2_SIZE] = {
0x000000CA, 0x00000007, 0xD9FFFFC9, 0xFFDFFFFF, 0xFFFFDFFF, 0xC1FFFFD5, 0x0085FFFF, 0x00030000, 
0xFFC10000, 0xFFFFE1FF, 0xFFFFFF84, 0xFFFFFF03, 0xCDFFFFF7, 0x0084FFFF, 0x00020000, 0xFFEF0000, 
0xFFFF82FF, 0xFFFF07FF, 0xFFFFF1FF, 0xFFFFFFFD, 0xFFFFFFFF, 0xFFFFF9FF, 0x82FFFFC5, 0x0C000000, 
0xD9000000, 0xFFFFFFFF, 0xFFFFFFFF, 0xC5FFFFF1, 0x0000FFFF, 0x00000000, 0xFFFFFFE1, 0xFFFFFFFF, 
0xFFFFE1FF, 0x00000082, 0x00000005, 0xFFFFFFF5, 0xFFFDFFFF, 0xFFFFC9FF, 0x00000082, 0x0000000B, 
0xEFFFFFC3, 0xFFEFFFFF, 0xFFFFE1FF, 0x00000000, 0xFFC10000, 0xFFFFFFFF, 0xF5FFFFFF, 0x0089FFFF, 
0x00050000, 0xFFC70000, 0xFFFFFFFF, 0xEFFFFFFF, 0x0089FFFF, 0x00050000, 0xFFC10000, 0xFFFFFFFF, 
0xF3FFFFFF, 0x0084FFFF, 0x000B0000, 0xFFD70000, 0xFFFFDFFF, 0xC1FFFFDF, 0x0000FFFF, 0x00000000, 
0xFFFFFFF5, 0xFFFDFFFF, 0xFFFFC5FF, 0x00000083, 0x00000004, 0xFFFFFFF9, 0xFFFBFFFF, 0x000082FF, 
0x00000C00, 0xFFFFDD00, 0xFFFFFFFF, 0xFFEFFFFF, 0xFFFFC3FF, 0x00000000, 0xFFDB0000, 0xFFFFFFFF, 
0xEFFFFFFF, 0x0083FFFF, 0x000B0000, 0xFFF10000, 0xFFFFFFFF, 0xF9FFFFFF, 0xFFEFFFFF, 0xFFFFF9FF, 
0xFFFFFFFF, 0xFFFDFFFF, 0xFFFFC9FF, 0x00000083, 0x00000003, 0xE9FFFFC5, 0xFF84FFFF, 0xFF03FFFF, 
0xFFF9FFFF, 0xFFFFD3FF, 0x00000086, 0x00000007, 0xDFFFFFCB, 0xFFEBFFFF, 0xFFFFDFFF, 0xC3FFFFDB, 
0x009EFFFF, 0x00010000, 0x00000000
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
