/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Middleware graphic initialisation
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/06/10 13:39:31 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef GRAPHICS_INIT_H
#define GRAPHICS_INIT_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "gdc.h"
#include "fg.h"
#include "ccr.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define MW_GRAPHICS_INIT_H_REVISION     "$Revision: 1.8 $"
#define MW_GRAPHICS_INIT_H_TAG          "$Name: Graphic_Middleware_V1_5 $"

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

/**
* @brief Display configuration
*/
typedef struct tag_disp_config_st
{
		uint8_t                 u8DispRes;                /*!< Display resolution */
    uint16_t                u16DispStartX;            /*!< Display start position in x-direction */
    uint16_t                u16DispStartY;            /*!< Display start position in y-direction */
		uint16_t                u16DispWidth;             /*!< Display width */
		uint16_t                u16DispHeight;            /*!< Display heigt */
		gdc_disp_config_type_e  eDispConfigType;          /*!<  */

		uint8_t                 u8VSYNCType;              /*!< VSYNC type */
		uint8_t                 u8VSYNCPol;               /*!< VSYNC polarity */
		uint16_t                u16VSYNCWidth;            /*!< VSYNC pulse width */
		uint16_t                u16VPeriod;               /*!< VSYNC period */
		uint16_t                u16VBackPorch;            /*!< Vertical back porch */
		
		uint8_t                 u8HSYNCPol;               /*!< HSYNC polarity */
		uint16_t                u16HSYNCWidth;            /*!< HSYNC pulse width */
		uint16_t                u16HPeriod;               /*!< HSYNC period */
		uint16_t                u16HBackPorch;            /*!< Horizontal back porch */

		uint8_t                 u8HDISPPol;               /*!< HDISP polarity */
		
		uint32_t                u32BGColor;               /*!< Background color */
		uint8_t                 u8SyncDir;                /*!< Synchronisation direction */

		uint8_t                 u8DotClkPol;              /*!< DotClock polarity */
		uint8_t                 u8ClkSource;              /*!< DotClock source */
		ccr_clk_freq_e          eClockFrequency;          /*!< DotClock frequency (division factor) */
		ccr_modulated_clk_e     eModulated;               /*!< DotClock modulation type */

		gdc_dithering_e         eDithering;               /*!< Dithering type */
		gdc_vord_e              eLayerOrder;              /*!< Layer viewing order */

    ccr_gdc_sync_e          eGDC1Synchronisation;     /*!< GDC0 - GDC1 synchronisation setting */
} gf_disp_config_st;


/**
* @brief Layer configuration
*/
typedef struct tag_layer_config_st
{
		uint8_t	 u8LayerActive;              /*!< Indication if layer is active */
		uint8_t  u8DisplayFormat;            /*!< Display color format */
		uint8_t  u8DoubleBuffer;             /*!< Indication if layer should be double buffered or not */
		uint8_t  u8Alpha;                    /*!< Layer alpha value */
		uint16_t u16StartX;                  /*!< Layer start point in x-direction */
		uint16_t u16StartY;                  /*!< Layer start point in y-direction */
		uint16_t u16Width;                   /*!< Layer width */
		uint16_t u16Height;                  /*!< Layer height */
		uint32_t u32FB0StartAddress;         /*!< Framebuffer 0 start address */
		uint32_t u32FB1StartAddress;         /*!< Framebuffer 1 start address */
} gf_layer_config_st;


/**
* @brief GDC-config structure
*/
typedef struct tag_gdc_config_st
{
		uint8_t            u8GDCActive;             /*!< Indication if GDC is active */
		gf_disp_config_st  stDispConf;              /*!< Display configuration */
		gf_layer_config_st stLayerConf_A;           /*!< Configuration of layer A */
		gf_layer_config_st stLayerConf_B;           /*!< Configuration of layer B */
		gf_layer_config_st stLayerConf_C;           /*!< Configuration of layer C */
		gf_layer_config_st stLayerConf_D;           /*!< Configuration of layer D */
		gf_layer_config_st stLayerConf_E;           /*!< Configuration of layer E */
} gf_gdc_config_st;


/**
* @brief FG-config structure
*/
typedef struct tag_fg_config_st
{
		uint8_t                       u8FGActive;         /*!< Indication if FG is active */
		fg_en_e                       eFGEnable;          /*!< Enable FG after configuration*/
    fg_capture_buffer_st          stFgBuffer;         /*!< Capture buffer configuration */
    fg_input_format_st            stFgInMode;         /*!< Input format configuration */
    fg_output_format_st           stFgOutMode;        /*!< Output format configuration */
    fg_swap_ycbcr_st              stFgSwapYcbCr;      /*!< Color conversion configuration */
    fg_signals_st                 stFgSignal;         /*!< FG-signal configuration */
    fg_input_cropp_st             stCroppConfig;      /*!< Cropping configuration */
		fg_en_e                       eCroppingEnable;    /*!< enable/disable cropping */
    uint32_t                      u32ScaleX;          /*!< Scaling factor in x-direction */
    uint32_t                      u32ScaleY;          /*!< Scaling factor in y-direction */
    fg_measure_extsync_control_st stMeasurement;      /*!< Measurement configuration */
} gf_fg_config_st;

/*********************************************/


/**********************************************
*            Function prototypes              *
**********************************************/

/**
* @brief Implementation of function vGf_Graphics_Init_GetVersion
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
void vGf_Graphics_Init_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                                  uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);


/**
* @brief Implementation of function vGfInitGDC0
*
* Initializes the GDC0
*
* @note none
*
* @param[in] pstGDC - pointer to configuration of GDC0
*
* @return void
*/
void vGfInitGDC0(gf_gdc_config_st* pstGDC);


/**
* @brief Implementation of function vGfInitGDC1
*
* Initializes the GDC1
*
* @note none
*
* @param[in] pstGDC - pointer to configuration of GDC1
*
* @return void
*/
void vGfInitGDC1(gf_gdc_config_st* pstGDC);


/**
* @brief Implementation of function vGfInitFG
*
* Initializes the FG
*
* @note none
*
* @param[in] pstFG - pointer to configuration of FG
*
* @return void
*/
void vGfInitFG(gf_fg_config_st* pstFG);


/**
* @brief Implementation of function vGfInitGA
*
* Initializes Graphics Accelerator
*
* @note none
*
* @return void
*/
void vGfInitGA(void);


/**
* @brief Implementation of function vGfInitGfxMiddleWare
*
* Initializes the Graphics middleware
*
* @note none
*
* @param[in] pstGDC0 - pointer to configuration of GDC0
* @param[in] pstGDC1 - pointer to configuration of GDC1
* @param[in] pstFG   - pointer to configuration of FG
*
* @return void
*/
void vGfInitGfxMiddleWare(gf_gdc_config_st* pstGDC0, gf_gdc_config_st* pstGDC1, gf_fg_config_st* pstFG);


/***************************************************************************/


#endif /* GRAPHICS_INIT_H */

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
