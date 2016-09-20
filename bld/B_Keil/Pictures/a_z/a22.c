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
 * Input Filename: C:\Users\liklon\Desktop\CM000\13\a22.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.51 KB
 * Compression Ratio : 52.95%
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
ALIGNED const uint32_t u32_a22_RLE[A22_SIZE] = {
0x000000C6, 0x00000014, 0xDFFFFFDF, 0xFFD7FFFF, 0x000000FF, 0xDB000000, 0xFFDFFFFF, 0xFFFFDBFF, 
0x00000000, 0xFFD70000, 0xFFFFDFFF, 0x00FFFFDF, 0xFFF30000, 0xFFFFFFFF, 0x00FFFFF9, 0xFFC30000, 
0xFFFF82FF, 0xFFFF0CFF, 0xFFFFC3FF, 0xF5000000, 0xFFFFFFFF, 0xFFFFF3FF, 0xE5000000, 0xFFFFFFFF, 
0xFFFFFFFF, 0xCDFFFFC3, 0xFF82FFFF, 0xFF2FFFFF, 0xFFCDFFFF, 0xFFFFC1FF, 0xFFFFFFFF, 0xFFE5FFFF, 
0x000000FF, 0xFFFFFFD7, 0xFFFFFFFF, 0xFFFFCDFF, 0xFFFFFFDB, 0xFFFBFFFF, 0xFFFFFFFF, 0xCBFFFFDB, 
0xFFFFFFFF, 0xFFFFFFFF, 0x00FFFFD7, 0xFFC90000, 0xFFFFFFFF, 0xDBFFFFFF, 0xFFE5FFFF, 0xFFFFFFFF, 
0xFFFFFFF9, 0xFFE5FFFF, 0xFFFFD5FF, 0xFFFFFFFF, 0xFFCBFFFF, 0x000000FF, 0xFB000000, 0xFFFFFFFF, 
0xFFFFE5FF, 0xFFFFFFF3, 0xFFEDFFFF, 0xFFFFFFFF, 0xE1FFFFF3, 0xFFFFFFFF, 0xFFFFFDFF, 0x00000082, 
0x0000000C, 0xFFFFFFED, 0xFFF1FFFF, 0xFFFFFDFF, 0xD5FFFFFF, 0xFFFFFFFF, 0xFFFFFDFF, 0xFFFFFFEB, 
0xFFEFFFFF, 0x000082FF, 0x00000C00, 0xFFFFDF00, 0xF7FFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFBFFFFC1, 
0xFFFFFFFF, 0xFFFFF9FF, 0xE3FFFFFF, 0x0082FFFF, 0x000C0000, 0xFFD30000, 0xFFFFFFFF, 0xFFFFFFFB, 
0xFFF3FFFF, 0x000000FF, 0xFFFFFFF1, 0xFFFBFFFF, 0xFFFFFFFF, 0x82FFFFD3, 0x02000000, 0xC3000000, 
0xFF82FFFF, 0xFF04FFFF, 0xFFE9FFFF, 0x000000FF, 0x82FFFFE5, 0x02FFFFFF, 0xC7FFFFFF, 0x0083FFFF, 
0x000A0000, 0xFFF50000, 0xFFFFFFFF, 0xDDFFFFFF, 0x0000FFFF, 0xFFFFD900, 0xFFFFFFFF, 0xFFF9FFFF, 
0x000084FF, 0x00000A00, 0xFFFFE700, 0xFFFFFFFF, 0xFFD1FFFF, 0x000000FF, 0xFFFFFFCD, 0xFFFFFFFF, 
0xFFFFEBFF, 0x00000084, 0x0000000A, 0xEFFFFFD5, 0xFFEFFFFF, 0xFFFFC5FF, 0xC1000000, 0xFFEFFFFF, 
0xFFFFEFFF, 0x9DFFFFD7, 0x01000000, 0x00000000
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
