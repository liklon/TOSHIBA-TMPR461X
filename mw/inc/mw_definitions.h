/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : MW specific definitions
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.17 $
*   DATE        : $Date: 2015/07/03 09:11:57 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef MW_DEFINITIONS_H
#define MW_DEFINITIONS_H

/**********************************************
*                Include files                *
**********************************************/

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define MW_DEFINITIONS_H_REVISION     "$Revision: 1.17 $"
#define MW_DEFINITIONS_H_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/

/* general */
#define ON      1
#define OFF	    0

/* Resolution Parameters  */
#define QVGA_RES_50                   (0)
#define QVGA_RES_60                   (1)
#define HNTSC_RES_60                  (2)
#define HVGA_RES_50                   (3)
#define HVGA_RES_60                   (4)
#define WIDE_RES_50                   (5)
#define WIDE_RES_60                   (6)
#define VGA_RES_50                    (7)
#define VGA_RES_60                    (8)
#define WVGA_RES_45                   (9)
#define WVGA_RES_50                  (10)
#define WVGA_RES_55                  (11)
#define WVGA_RES_60                  (12)
#define SVGA_RES_50                  (13)
#define SVGA_RES_60                  (14)
#define DVGA_RES_50                  (15)
#define DVGA_RES_60                  (16)
#define DVGA_1_RES_50                (17)
#define DVGA_1_RES_60                (18)
#define XGA_RES_50                   (19)
#define XGA_RES_60                   (20)
#define SXGA_RES_50                  (21)
#define SXGA_RES_60                  (22)
#define HD_RES                       (23)
#define HITACHI_TX31D06VM2AAA_RES_50 (24)
#define HITACHI_TX31D06VM2AAA_RES_60 (25)
#define SHARP_1280_422_50            (26)
#define SHARP_1280_422_60            (27)
#define TX18D35VM0AAA_50             (28)
#define TX18D35VM0AAA_60             (29)
#define RES_960_720_50               (30) 
#define AT070TN94_50             (31)
#define AT070TN94_60             (32)
#define  TC90195_60   (33)
#define  CLAA121WB   (34) 
#define	CLAA088WA	(35)
/* definition if layer is not used */
#define FMT_OFF         (0)

/* Data Formats */
#define FMT_RGBA32      (1)
#define FMT_RGBA24      (2)
#define FMT_RGB24       (3)
#define FMT_RGB16       (4)

#define FMT_GRAY8A     (10)
#define FMT_GRAY8      (11)
#define FMT_GRAY2      (12)
#define FMT_GRAY1      (13)
#define FMT_A          (14)

#define FMT_RLERGBA32  (15)
#define FMT_RLERGBA24  (16)
#define FMT_RLERGB24   (17)
#define FMT_RLERGB16   (18)
#define FMT_RLECLUT8   (19)
#define FMT_RLECLUT6   (20)
#define FMT_RLECLUT4   (21)
#define FMT_RLECLUT2   (22)
#define FMT_RLECLUT1   (23)
#define FMT_RLEGRAY8A  (24)
#define FMT_RLEGRAY8   (25)
#define FMT_RLEGRAY2   (26)
#define FMT_RLEGRAY1   (27)
#define FMT_RLEA       (28)

#define FMT_PNGRGBA32  (29)
#define FMT_PNGRGB24   (30)
#define FMT_PNGCLUT8   (31)
#define FMT_PNGCLUT4   (32)
#define FMT_PNGCLUT2   (33)
#define FMT_PNGCLUT1   (34)
#define FMT_PNGGRAY8A  (35)
#define FMT_PNGGRAY8   (36)
#define FMT_PNGGRAY4   (37)
#define FMT_PNGGRAY2   (38)
#define FMT_PNGGRAY1   (39)

/*********************************************/

/**********************************************
*            External variables               *
**********************************************/

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/

/**********************************************
*            Function prototypes              *
**********************************************/

/*********************************************/

#endif /* MW_DEFINITIONS_H */

/***************************************************************************/

/***********************  BEGIN of DISCLAIMER   *****************************

- TOSHIBA is continually working to improve the quality and reliability of
  its products.
  Nevertheless, semiconductor devices in general can malfunction or fail
  due to their inherent electrical sensitivity and vulnerability to physical
  stress. It is the responsibility of the buyer, when utilizing TOSHIBA
  products, to comply with the standards of safety in making a safe design
  for the entire system, and to avoid situations in which a malfunction or
  failure of such TOSHIBA products could cause loss of human life,
  bodily injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications. Also, please keep in mind the precautions and
  conditions set forth in the “Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (“Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer’s own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit,business interruption, loss of business
  information,and other pecuniary losses) occurring from the use of,
  or inability to use, this product.

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
