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
 * Image Dimensions : Width=12, Height=20
 * Input Filename: C:\Users\liklon\Desktop\CM000\10\disfont5.png
 * Data is RLE compressed
 * Uncompressed Data Size : 0.94 KB
 * Compressed Data Size : 0.42 KB
 * Compression Ratio : 55.00%
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
ALIGNED const uint32_t u32_disfont5_RLE[DISFONT5_SIZE] = {
0xFFFFC002, 0x87FFFFF7, 0x05FFFFFF, 0xD9FFFFFF, 0xFFC0FFFF, 0xFFFFC0FF, 0x87FFFFFB, 0x07FFFFFF, 
0xD9FFFFFF, 0xFFC0FFFF, 0xFFFFC0FF, 0xFFFFFFFF, 0xFFD5FFFF, 0xFFC087FF, 0xFFC005FF, 0xFFFFC4FF, 
0xFFFFFFFF, 0xFFD1FFFF, 0xFFC087FF, 0xFFC005FF, 0xFFFFC8FF, 0xFFFFFFFF, 0xFFCCFFFF, 0xFFC087FF, 
0xFFC005FF, 0xFFFFD1FF, 0xFFFFFFFF, 0xFFC8FFFF, 0xFFC087FF, 0xFFC005FF, 0xFFFFD1FF, 0xFFFFFFFF, 
0xFFC4FFFF, 0xFFC087FF, 0xFFC004FF, 0xFFFFD9FF, 0xFFFFFFFF, 0xC088FFFF, 0xC002FFFF, 0xFFDDFFFF, 
0xFFFF85FF, 0xFFFF03FF, 0xFFFFDDFF, 0x82FFFFCC, 0x02FFFFC0, 0xDDFFFFC0, 0xFF87FFFF, 0xFF02FFFF, 
0xFFE2FFFF, 0xFFC086FF, 0xFFC007FF, 0xFFFFC4FF, 0xFBFFFFDD, 0xFFFFFFFF, 0xFFFFFFFF, 0x87FFFFDD, 
0x06FFFFC0, 0xC8FFFFC0, 0xFFF7FFFF, 0xFFFFFFFF, 0xC4FFFFFB, 0xC087FFFF, 0xC005FFFF, 0xFFD9FFFF, 
0xFFFFFFFF, 0xD1FFFFFF, 0xC087FFFF, 0xC005FFFF, 0xFFCCFFFF, 0xFFFFFFFF, 0xD9FFFFFF, 0xC087FFFF, 
0xC005FFFF, 0xFFCCFFFF, 0xFFFFFFFF, 0xD5FFFFFF, 0xC087FFFF, 0xC005FFFF, 0xFFDDFFFF, 0xFFFFFFFF, 
0xCCFFFFFF, 0xC086FFFF, 0xC009FFFF, 0xFFC8FFFF, 0xFFFFFBFF, 0xEEFFFFFF, 0xFFC0FFFF, 0xFFFFEEFF, 
0xCCFFFFE2, 0xC082FFFF, 0xC008FFFF, 0xFFDDFFFF, 0xFFFFFBFF, 0xFFFFFFFF, 0xFFCCFFFF, 0xFFFFC0FF, 
0x86FFFFEE, 0x06FFFFFF, 0xFBFFFFFF, 0xFFD1FFFF, 0xFFFFC0FF, 0xEEFFFFC0, 0xFF84FFFF, 0xFF03FFFF, 
0xFFF3FFFF, 0xFFFFDDFF, 0xFFFFC083, 0xFFFFC001
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
