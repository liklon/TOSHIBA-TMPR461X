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
 * Input Filename: C:\Users\liklon\Desktop\CM000\13\a19.png
 * Data is RLE compressed
 * Uncompressed Data Size : 1.09 KB
 * Compressed Data Size : 0.38 KB
 * Compression Ratio : 65.27%
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
ALIGNED const uint32_t u32_a19_RLE[A19_SIZE] = {
0x00000092, 0x00000004, 0xDFFFFFDF, 0xFFD7FFFF, 0x00008AFF, 0x00000400, 0xFFFFFF00, 0xEFFFFFFF, 
0x008AFFFF, 0x00040000, 0xFFFF0000, 0xFFFFFFFF, 0x8AFFFFEF, 0x04000000, 0xFF000000, 0xFFFFFFFF, 
0xFFFFEFFF, 0x00000086, 0x00000002, 0x82FFFFCB, 0x04FFFFDF, 0xFFFFFFDF, 0xFFFFFFFF, 0xFFFFF7FF, 
0xFFFFDF82, 0xFFFFDF02, 0x82FFFFDB, 0x02000000, 0xD7000000, 0xFF88FFFF, 0xFF02FFFF, 0xFFF7FFFF, 
0x000082FF, 0x00000200, 0xFFFFD100, 0xFFFFEF82, 0xFFFFEF04, 0xFFFFFFFF, 0xFFFBFFFF, 0xFFEF82FF, 
0xFFEF02FF, 0xFFFFE9FF, 0x00000086, 0x00000004, 0xFFFFFFFF, 0xFFEFFFFF, 0x00008AFF, 0x00000400, 
0xFFFFFF00, 0xEFFFFFFF, 0x008AFFFF, 0x00040000, 0xFFFF0000, 0xFFFFFFFF, 0x8AFFFFEF, 0x04000000, 
0xFF000000, 0xFFFFFFFF, 0xFFFFEFFF, 0x0000008A, 0x00000004, 0xFFFFFFFF, 0xFFEFFFFF, 0x00008AFF, 
0x00000400, 0xFFFFFB00, 0xEFFFFFFF, 0x008AFFFF, 0x00040000, 0xFFF10000, 0xFFFFFFFF, 0x82FFFFFB, 
0x03000000, 0xC1000000, 0xFFCBFFFF, 0x000085FF, 0x00000900, 0xFFFFDB00, 0xFFFFFFFF, 0xFFFBFFFF, 
0xFFFFEFFF, 0xFBFFFFEF, 0xFFE7FFFF, 0x000086FF, 0x00000200, 0xFFFFED00, 0xFFFFFF84, 0xFFFFFF02, 
0x87FFFFE7, 0x07000000, 0xD3000000, 0xFFDFFFFF, 0xFFFFEFFF, 0xDDFFFFE5, 0xFFC7FFFF, 0x00009CFF, 
0x00000100, 0x00000000
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
