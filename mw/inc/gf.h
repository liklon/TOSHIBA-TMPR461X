/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronic Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : Contains declarations for Image structures
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/07/21 12:38:02 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
****************************************************************************/
#ifndef GF_H
#define GF_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define MW_GF_H_REVISION     "$Revision: 1.8 $"
#define MW_GF_H_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/
/*---------------------------------------
|             MATH LIBRARY USE           |
 ---------------------------------------*/
/* Enables use of standard math library */
/* if following define is disabled, LLDD/GA rotation and scaling are using integer instead of float */
/* and sin/cos lookup table is used instead of math library functions */

#define GA_USE_MATH_LIB

#ifdef GA_USE_MATH_LIB
/* Pi Constant Value */
#define GA_CONST_PI 3.1415926535897932384626433
#endif

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

/**
* @brief Transformation table structure
*/
typedef struct tag_table_st
{
    uint32_t    u32Address;         /*!< Table source address */
    uint16_t    u16Width;           /*!< Image width */
    uint16_t    u16Height;          /*!< Image height */
} gf_table_st;


/**
* @brief Image description structure
*/
typedef struct tag_image_st
{
    uint32_t    u32Address;         /*!< Image source address */
    uint16_t    u16Width;           /*!< Image width */
    uint16_t    u16Height;          /*!< Image height */
    int16_t     i16CenterX;         /*!< Image rotation center X-coord (optional) */
    int16_t     i16CenterY;         /*!< Image rotation center Y-coord (optional) */
    uint8_t     eFormat;            /*!< Image Format */
    uint32_t    u32Paletteaddress;  /*!< palette address for PNG */
} gf_image_st;


/**
* @brief CLUT description structure
*/
typedef struct tag_clut_st
{
    uint32_t    u32Address;         /*!< CLUT source address */
    uint8_t     u8Length;           /*!< CLUT length */
} gf_clut_st;

/*********************************************/


/**********************************************
*            Function prototypes              *
**********************************************/


/***************************************************************************/

#endif /* GF_H */

/***************************************************************************/

/************************* BEGIN of DISCLAIMER   *****************************

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

****************************  END of DISCLAIMER *****************************/
