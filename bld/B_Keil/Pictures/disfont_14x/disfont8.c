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
 * Input Filename: C:\Users\liklon\Desktop\CM000\10\disfont8.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.02 KB
 * Compressed Data Size : 0.61 KB
 * Compression Ratio : 40.29%
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
ALIGNED const uint32_t u32_disfont8_RLE[DISFONT8_SIZE] = {
0xFFFFC082, 0xFFFFC003, 0xE6FFFFCC, 0xFF82FFFF, 0xFF03FFFF, 0xFFEAFFFF, 0xFFFFD5FF, 0xFFFFC084, 
0xFFFFC002, 0x86FFFFD9, 0x02FFFFFF, 0xE6FFFFFF, 0xC082FFFF, 0xC011FFFF, 0xFFD1FFFF, 0xFFFFFFFF, 
0xEAFFFFFF, 0xFFC8FFFF, 0xFFFFC0FF, 0xE2FFFFC0, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0FFFFDD, 0xFFC0FFFF, 
0xFFFFEAFF, 0xF3FFFFFF, 0xC084FFFF, 0xC009FFFF, 0xFFE2FFFF, 0xFFFFFFFF, 0xC0FFFFFB, 0xFFC0FFFF, 
0xFFFFF7FF, 0xDDFFFFFF, 0xC084FFFF, 0xC009FFFF, 0xFFCCFFFF, 0xFFFFFFFF, 0xC8FFFFFF, 0xFFC0FFFF, 
0xFFFFF7FF, 0xDDFFFFFF, 0xC084FFFF, 0xC009FFFF, 0xFFCCFFFF, 0xFFFFFFFF, 0xC4FFFFFF, 0xFFC0FFFF, 
0xFFFFE6FF, 0xF3FFFFFF, 0xC084FFFF, 0xC011FFFF, 0xFFE2FFFF, 0xFFFFFFFF, 0xC0FFFFF3, 0xFFC0FFFF, 
0xFFFFC8FF, 0xFFFFFFFB, 0xFFEEFFFF, 0xFFFFC8FF, 0xC4FFFFC0, 0xFFE6FFFF, 0xFFFFFFFF, 0xD5FFFFFF, 
0xC082FFFF, 0xC003FFFF, 0xFFCCFFFF, 0xFFFFFBFF, 0xFFFFFF85, 0xFFFFFF02, 0x83FFFFD5, 0x03FFFFC0, 
0xC8FFFFC0, 0xFFE6FFFF, 0xFFFF84FF, 0xFFFF03FF, 0xFFFFEEFF, 0x82FFFFD1, 0x11FFFFC0, 0xCCFFFFC0, 
0xFFFBFFFF, 0xFFFFFFFF, 0xC4FFFFE6, 0xFFC0FFFF, 0xFFFFC0FF, 0xFFFFFFDD, 0xFFFFFFFF, 0xFFFFD9FF, 
0xC4FFFFC0, 0xFFF7FFFF, 0xFFFFFFFF, 0x84FFFFE2, 0x08FFFFC0, 0xD5FFFFC0, 0xFFFFFFFF, 0xFFFFFFFF, 
0xDDFFFFCC, 0xFFFFFFFF, 0xFFFFFBFF, 0xFFFFC086, 0xFFFFC007, 0xFFFFFFEA, 0xFFEEFFFF, 0xFFFFEAFF, 
0xEEFFFFFF, 0xC086FFFF, 0xC007FFFF, 0xFFDDFFFF, 0xFFFFFFFF, 0xEEFFFFFF, 0xFFFFFFFF, 0xFFFFEEFF, 
0xFFFFC086, 0xFFFFC007, 0xFFFFFFDD, 0xFFFFFFFF, 0xFFFFEAFF, 0xFBFFFFFF, 0xC086FFFF, 0xC008FFFF, 
0xFFEAFFFF, 0xFFFFFFFF, 0xD9FFFFFB, 0xFFFFFFFF, 0xFFFFFFFF, 0x84FFFFDD, 0x15FFFFC0, 0xCCFFFFC0, 
0xFFFFFFFF, 0xFFFFFFFF, 0xC0FFFFE6, 0xFFF3FFFF, 0xFFFFFFFF, 0xE2FFFFFF, 0xFFC4FFFF, 0xFFFFC0FF, 
0xDDFFFFC0, 0xFFFFFFFF, 0xFFFFFFFF, 0xC8FFFFFB, 0xFFC0FFFF, 0xFFFFC4FF, 0x86FFFFEE, 0x03FFFFFF, 
0xFBFFFFFF, 0xFFD1FFFF, 0xFFC083FF, 0xFFC003FF, 0xFFFFD9FF, 0x82FFFFEA, 0x03FFFFFF, 0xF3FFFFFF, 
0xFFDDFFFF, 0xFFC082FF, 0xFFC001FF, 0x000000FF
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
