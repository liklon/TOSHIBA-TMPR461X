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
 * Converted on: 22.04.2016 @ 18:20
 * Output format: FMT_RLERGBA24
 * Image Dimensions : Width=13, Height=20
 * Input Filename: C:\Users\liklon\Desktop\CM000\10\disfont3.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.02 KB
 * Compressed Data Size : 0.47 KB
 * Compression Ratio : 53.65%
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
ALIGNED const uint32_t u32_disfont3_RLE[DISFONT3_SIZE] = {
0xFFFFC004, 0xD1FFFFC0, 0xFFE2FFFF, 0xFFFF83FF, 0xFFFF03FF, 0xFFFFDDFF, 0x83FFFFC8, 0x02FFFFC0, 
0xDDFFFFC0, 0xFF87FFFF, 0xFF02FFFF, 0xFFD1FFFF, 0xFFC082FF, 0xFFC004FF, 0xFFFFDDFF, 0xD5FFFFEA, 
0xC082FFFF, 0xC006FFFF, 0xFFDDFFFF, 0xFFFFFBFF, 0xFBFFFFFF, 0xFFC4FFFF, 0xFFC088FF, 0xFFC005FF, 
0xFFFFD5FF, 0xFFFFFFFF, 0xFFDDFFFF, 0xFFC089FF, 0xFFC004FF, 0xFFFFFBFF, 0xE6FFFFFF, 0xC089FFFF, 
0xC004FFFF, 0xFFF7FFFF, 0xFFFFFFFF, 0x88FFFFE2, 0x05FFFFC0, 0xC4FFFFC0, 0xFFFFFFFF, 0xFFFFFFFF, 
0x88FFFFDD, 0x05FFFFC0, 0xE2FFFFC0, 0xFFFFFFFF, 0xFFFFFBFF, 0x86FFFFC4, 0x06FFFFC0, 0xD1FFFFC0, 
0xFFE6FFFF, 0xFFFFFFFF, 0xD1FFFFFF, 0xC083FFFF, 0xC002FFFF, 0xFFD1FFFF, 0xFFFF84FF, 0xFFFF03FF, 
0xFFFFE2FF, 0x84FFFFC8, 0x02FFFFC0, 0xD1FFFFC0, 0xFF85FFFF, 0xFF03FFFF, 0xFFE6FFFF, 0xFFFFCCFF, 
0xFFFFC087, 0xFFFFC007, 0xDDFFFFC4, 0xFFF7FFFF, 0xFFFFFFFF, 0xCCFFFFFF, 0xC088FFFF, 0xC005FFFF, 
0xFFC4FFFF, 0xFFFFF3FF, 0xF7FFFFFF, 0xC089FFFF, 0xC005FFFF, 0xFFD5FFFF, 0xFFFFFFFF, 0xCCFFFFFF, 
0xC088FFFF, 0xC005FFFF, 0xFFD1FFFF, 0xFFFFFFFF, 0xD1FFFFFF, 0xC088FFFF, 0xC007FFFF, 0xFFD5FFFF, 
0xFFFFFFFF, 0xCCFFFFFF, 0xFFD1FFFF, 0xFFFFE2FF, 0xFFFFC086, 0xFFFFC009, 0xFFFFFFF3, 0xFFF7FFFF, 
0xFFFFC0FF, 0xFFFFFFD1, 0xFFF3FFFF, 0xFFFFD9FF, 0xFFFFC082, 0xFFFFC009, 0xF3FFFFD9, 0xFFFFFFFF, 
0xFFFFFFFF, 0xC0FFFFD5, 0xFFC0FFFF, 0xFFFFDDFF, 0xFFFFFF87, 0xFFFFFF02, 0x83FFFFD5, 0x03FFFFC0, 
0xD1FFFFC0, 0xFFEEFFFF, 0xFFFF82FF, 0xFFFF04FF, 0xFFFFF3FF, 0xC4FFFFDD, 0xC082FFFF, 0xC001FFFF, 
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
