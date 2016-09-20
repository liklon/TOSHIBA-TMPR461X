/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Middleware layer handling
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/06/10 13:41:10 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef LAYER_H
#define LAYER_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "graphics_init.h"
#include "gf.h"
#include "gdc.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define MW_LAYER_H_REVISION     "$Revision: 1.8 $"
#define MW_LAYER_H_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/**
* @brief Layer Structure
*/
typedef struct tag_layer_st
{
    gdc_layer_e  eLayer;       /*!< Layer Selection   */
    gdc_dfmt_e   eFormat;      /*!< Format (RGB/RGBA) */
    uint16_t     u16StartX;    /*!< X-Start position  */
    uint16_t     u16StartY;    /*!< Y-Start position  */
    uint16_t     u16Height;    /*!< Display Height    */
    uint16_t     u16Width;     /*!< Display Width     */
    uint8_t      u8Alpha;      /*!< Alpha-blending for the layer */
    gf_image_st  stDispFB;     /*!< Display Frame-buffer config. */
    gf_image_st  stWriteFB;    /*!< Write Frame-buffer config. */
} gf_layer_st;

/**
* @brief Display parameter
*/
typedef struct tag_disp_params_st
{
    uint16_t     u16VSYNCWidth;    /*!< width of VSYNC pulse  */
    uint16_t     u16VBackPorch;    /*!< vertical back porch   */
    uint16_t     u16HSYNCWidth;    /*!< width of HSYNC pulse  */
    uint16_t     u16HBackPorch;    /*!< horizontal back porch */
} gf_disp_params_st;

/*********************************************/


/**********************************************
*            External variables               *
**********************************************/

/* Layer description structures */
/* GDC0 */
extern gf_layer_st stGDC0LayerA;		/* Layer A */
extern gf_layer_st stGDC0LayerB;		/* Layer B */
extern gf_layer_st stGDC0LayerC;		/* Layer C */
extern gf_layer_st stGDC0LayerD;		/* Layer D */
extern gf_layer_st stGDC0LayerE;		/* Layer E */

/* GDC1 */
extern gf_layer_st stGDC1LayerA;		/* Layer A */
extern gf_layer_st stGDC1LayerB;		/* Layer B */
extern gf_layer_st stGDC1LayerC;		/* Layer C */
extern gf_layer_st stGDC1LayerD;		/* Layer D */
extern gf_layer_st stGDC1LayerE;		/* Layer E */

/*********************************************/

/**********************************************
*            Function prototypes              *
**********************************************/

/**
* @brief Implementation of function vGf_Layer_GetVersion
*
* Retrieve pointers to module and header revision and tag string
*
* @note none
*
* @param[in,out] pau8ModuleRevision - pointer to module revision string
* @param[in,out] pau8ModuleTag      - pointer to module tag string
* @param[in,out] pau8HeaderRevision - pointer to header revision string
* @param[in,out] pau8HeaderTag      - pointer to header tag string
*
* @return void
*/
void vGf_Layer_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                          uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);


/**
* @brief Implementation of function vGfRegisterLayers
*
* Registers parameters for all layers
*
* @note This function MUST be called before all other layer
*       manipulation functions.
*
* @param[in] eGDCNumber - GDC selection
* @param[in] stGDC      - Pointer to GDC-configuration
*
* @return void
*/
void vGfRegisterLayers(gdc_ch_e eGDCNumber, gf_gdc_config_st * stGDC);


/**
* @brief Implementation of function  vGfSetLayer
*
* Initializes given layer of the GDC
*
* @note The vRegisterLayers() function must be called first
*
* @param[in] eGDCNumber    - GDC selection
* @param[in] pstLayer      - Pinter to Layer selection
* @param[in] pstDispParams - Pinter to display parameter
*
* @return void
*/
void vGfSetLayer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer, gf_disp_params_st* pstDispParams);


/**
* @brief Implementation of function  vGfShowLayer
*
* Shows given layer
*
* @note none
*
* @param[in] eGDCNumber - GDC selection
* @param[in] pstLayer   - Pointer to Layer selection
*
* @return void
*/
void vGfShowLayer(gdc_ch_e eGDCNumber, gf_layer_st *pstLayer);


/**
* @brief Implementation of function  vGfHideLayer
*
* Hides given layer
*
* @note none
*
* @param[in] eGDCNumber - GDC selection
* @param[in] pstLayer   - Pointer to Layer selection
*
* @return void
*/
void vGfHideLayer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer);


/**
* @brief Implementation of function  vGfPositionLayer
*
* Sets the position of the layer
*
* @note none
*
* @param[in] eGDCNumber    - GDC selection
* @param[in] pstLayer      - Pointer to Layer selection
* @param[in] pstDispParams - Pointer to parameter
*
* @return void
*/
void vGfPositionLayer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer, gf_disp_params_st* pstDispParams);


/**
* @brief Implementation of function vGfSwitchBuffer
*
* GDC0 framebuffer switching
*
* @note none
*
* @param[in] eGDCNumber - layer selection
* @param[in] pstLayer   - pointer to layer
*
* @return void
*/
void vGfLayerSwitchBuffer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer);


/**
* @brief Implementation of function vGfLayerSwitchBufferSync
*
* GDC0 framebuffer switching
*
* @note none
*
* @param[in] eGDCNumber - layer selection
* @param[in] pstLayer   - pointer to layer selection
*
* @return void
*/
void vGfLayerSwitchBufferSync(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer);


/**
* @brief Implementation of function vGfGetDispLayerAddr
*
* Returns the address of the display frame buffer
*
* @note none
*
* @param[in] pstLayer - pointer to layer selection
*
* @return Returns display layer start address
*/
uint32_t uiGfGetDispLayerAddr(gf_layer_st* pstLayer);


/**
* @brief Implementation of function vGfGetWriteLayerAddr
*
* Returns the address of the write frame buffer
*
* @note none
*
* @param[in] pstLayer - pointer to layer selection
*
* @return Returns write layer start address
*/
uint32_t uiGfGetWriteLayerAddr(gf_layer_st* pstLayer);


/**
* @brief Implementation of function vGfGetDispLayerWidth
*
* Returns the width of the display frame buffer
*
* @note none
*
* @param[in] pstLayer - pointer to layer selection
*
* @return Returns the display layer width
*/
uint32_t uiGfGetDispLayerWidth(gf_layer_st* pstLayer);


/**
* @brief Implementation of function vGfGetWriteLayerWidth
*
* Returns the width of the write frame buffer
*
* @note none
*
* @param[in] pstLayer - pointer to layer selection
*
* @return Returns the write layer width
*/
uint32_t uiGfGetWriteLayerWidth(gf_layer_st* pstLayer);


/**
* @brief Implementation of function eGfGetWriteLayerFormat
*
* Returns the Format of the frame buffer
*
* @note none
*
* @param[in] pstLayer - pointer to layer selection
*
* @return GDC_RGBA32 in case of RGBA 32-bit
* @return GDC_RGB16 in case of RGB 16-bit
* @return GDC_ARGB32 in case of ARGB 32-bit
*/
gdc_dfmt_e eGfGetWriteLayerFormat(gf_layer_st* pstLayer);


/***************************************************************************/

#endif /* LAYER_H */

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
