/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Middleware graphic functions
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.18 $
*   DATE        : $Date: 2015/06/02 11:32:57 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef GFUNCTIONS_H
#define GFUNCTIONS_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "gf.h"
#include "layer.h"
#include "blit.h"
#include "transf.h"
#include "draw.h"
#include "rotation.h"
#include "ga.h"
#include "png.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define MW_GFUNCTIONS_H_REVISION     "$Revision: 1.18 $"
#define MW_GFUNCTIONS_H_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/


/**********************************************
*            External variables               *
**********************************************/

#ifdef MEASURE_TX
extern uint32_t u32TimeMeasure;
#endif

/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/

/**
* @brief Subpixel format selection
*/
typedef enum tag_subRes_e
{
    GA_PIXEL_RES = 0x0U,    /* !< pixel resolution */
    GA_HIGH_RES  = 0x1U     /* !< 1/16 resolution  */
} gf_subRes_e;


/*********************************************/

/**
* @brief Matrix modes
*/
typedef enum tag_matrixmodes_e
{
    GA_RE_PROJECTION = 0x0U,    /* !< Projection */
    GA_RE_MODELVIEW  = 0x1U,    /* !< Model view */
    GA_RE_IP         = 0x2U     /* !< IP */
} gf_matrixmodes_e;


/*********************************************/

/**
* @brief GA status
*/
typedef enum tag_ga_status_e
{
    GA_BUSY = 0x0U,    /* !< GA ist busy */
    GA_IDLE = 0x1U     /* !< GA is idle */
} gf_ga_status_e;


/**********************************************
*                 Structures                  *
**********************************************/

/**
* @brief Clipping rectangle structure
*/
typedef struct tag_cliprect_st
{
    uint16_t u16SrcOffsX;           /*!< Horiz. Offset from the begining of the image/buffer (in dots) */
    uint16_t u16SrcOffsY;           /*!< Vert. Offset from the begining of the image/buffer (in lines) */
    uint16_t u16Width;              /*!< Width of the rectangle in dots */
    uint16_t u16Height;             /*!< Height of the rectangle in lines */
} gf_cliprect_st;


/**
* @brief State structure
*/
typedef struct tag_gastate_st
{
    ga_en_e         eRedChPrtEn;       /*!< RED channel protection enable */
    ga_en_e         eGreenChPrtEn;     /*!< GREEN channel protection enable */
    ga_en_e         eBlueChPrtEn;      /*!< BLUE channel protection enable */
    ga_en_e         eAlphaChPrtEn;     /*!< ALPHA channel protection enable */

    ga_en_e         eSrcRedFad;        /*!< RED channel fading enable */
    ga_en_e         eSrcGreenFad;      /*!< GREEN channel fading enable */
    ga_en_e         eSrcBlueFad;       /*!< BLUE channel fading enable */
    ga_en_e         eSrcAlphaFad;      /*!< ALPHA channel fading enable */

    ga_en_e         eFilterEn;         /*!< Filter enable */

    ga_blendOrd_e   eBlndOrder;        /*!< Blend order */

    blt_fadeMode_e  eFadeMode;         /*!< Fading option */
    uint8_t         u8FadingFctr;      /*!< Fading factor */

    ga_en_e         eTranspColEn;      /*!< Transparency color option (only 16-bit src) */
    uint32_t        u32SrcTransVal;    /*!< Source transparency pattern (STPR register) */
    uint16_t        u16DstTransVal;    /*!< Destination transparency pattern (DTR register) */

    uint8_t         u8SrcAlphaVal;     /*!< Source alpha value */
    uint8_t         u8DstAlphaVal;     /*!< Destination alpha value */

    transf_Mode_e   eTsfMode;          /*!< Transformation mode (Pixel-/Color-mode) */
    uint32_t        u32TsfPredefColor; /*!< Predefined color for transformation */

    ga_en_e         eRastOpEn;         /*!< Enabling the raster operation */
    blt_rastChSel_e eRastOpMode;       /*!< Raster operation mode */
    blt_rastOpVal_e eRastOpValue;      /*!< Raster operation value */

    ga_en_e         eClipWndEn;        /*!< Clip window enable */
    uint16_t        u16ClipC1_X;       /*!< Point C1 x-position */
    uint16_t        u16ClipC1_Y;       /*!< Point C1 y-position */
    uint16_t        u16ClipC2_X;       /*!< Point C2 x-position */
    uint16_t        u16ClipC2_Y;       /*!< Point C2 y-position */
} gf_gastate_st;


/**
* @brief Color channel protection structure
*/
typedef struct tag_colorprt_st
{
    ga_en_e  eRedChPrtEn;    /*!< RED channel protection enable */
    ga_en_e  eGreenChPrtEn;  /*!< GREEN channel protection enable */
    ga_en_e  eBlueChPrtEn;   /*!< BLUE channel protection enable */
} gf_colorprt_st;


/**
* @brief Transparency value structure
*/
typedef struct tag_transval_st
{
    uint32_t u32SrcTransVal;  /*!< Source transparency value */
    uint16_t u16DstTransVal;  /*!< Destination transparency value */
} gf_transval_st;


/**
* @brief Alpha value structure
*/
typedef struct tag_alphaval_st
{
    uint8_t u8SrcAlphaVal;  /*!< Source alpha value */
    uint8_t u8DstAlphaVal;  /*!< Destination alpha value */
} gf_alphaval_st;


/**
* @brief Parameter for rotation of one image with base
*/
typedef struct tag_def_st
{
    uint16_t u16BlockHeight;    /*!< Height of block */
    uint16_t u16TipHeight;      /*!< Height of tip */
    uint16_t u16TipWidth;       /*!< Width of tip */
} gf_def_st;


/**
* Circle description structure
*/
typedef struct tag_circle_st
{
    drw_Color_st  stColor;           /*!< Color Configuration */
    drw_Point_st  stCenter;          /*!< Center points */
    ga_en_e       eAntialEn;         /*!< Anti aliasing option */
    uint16_t      u16Radius;         /*!< Radius of the circle */
} gf_circle_st;


/**
* Polygon description structure 
*/
typedef struct tag_polygon_st
{
    drw_Point_st  *pstPolyVertex;        /*!< pointer to vertices of polygon */
    ga_en_e       eAntialEn;             /*!< Anti aliasing option */
    drw_Color_st  stColor;               /*!< Color Configuration */
    uint16_t      u16NumVert;            /*!< number of vertices */
} gf_polygon_st;


/*********************************************/


/**********************************************
*            Function prototypes              *
**********************************************/

/**
* @brief Implementation of function vGf_Gfunctions_GetVersion
*
* Retrieve pointers to module and header revision and tag string
*
* @note none
*
* @param[in,out] pau8ModuleRevision    - pointer to module revision string
* @param[in,out] pau8ModuleTag         - pointer to module tag string
* @param[in,out] pau8HeaderRevision    - pointer to header revision string
* @param[in,out] pau8HeaderTag         - pointer to header tag string
* @param[in,out] pau8GfHeaderRevision  - pointer to gf-header revision string
* @param[in,out] pau8GfHeaderTag       - pointer to gf-header tag string
* @param[in,out] pau8DefHeaderRevision - pointer to definition-header revision string
* @param[in,out] pau8DefHeaderTag      - pointer to definition-header tag string
*
* @return void
*/
void vGf_Gfunctions_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                               uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                               uint8_t** pau8GfHeaderRevision, uint8_t** pau8GfHeaderTag,
                               uint8_t** pau8DefHeaderRevision, uint8_t** pau8DefHeaderTag);


/**
* @brief Implementation of function vGfWaitForVSync
*
* Waits for V-Sync
*
* @note none
*
* @param[in] eGDCNumber - GDC to wait on
*
* @return void
*/
void vGfWaitForVSync(gdc_ch_e eGDCNumber);


/**
* @brief Implementation of function u32GfGetVSyncStatus
*
* Returns V-Sync status
*
* @note none
*
* @param[in] eGDCNumber - GDC to wait on
*
* @return void
*/
uint32_t u32GfGetVSyncStatus(gdc_ch_e eGDCNumber);


/**
* @brief Implementation of function eGfGetGAStatus
*
* Read status of GA
*
* @note none
*
* @return GA_BUSY if GA is busy
* @return GA_IDLE if GA is not busy
*/
gf_ga_status_e eGfGetGAStatus(void);


/**
* @brief Implementation of function vGfWaitForGA
*
* Waits for GA ready
*
* @note none
*
* @return void
*/
void vGfWaitForGA(void);


/**
* @brief Implementation of function vGfWaitForPNGDecode
*
* Waits for PNG decode completion
*
* @note none
*
* @param[in] eStream - Stream to be decoded
*
* @return void
*/
void vGfWaitForPNGDecode(png_stream_e eStream);


/*****************************************************************************
 *
 *                          STATE-BASED FUNCTIONS
 *
 ****************************************************************************/

/**
* @brief Implementation of function vGfInitMWStateVariable
*
* Initializes the statestructure
*
* @note none
*
* @return void
*/
void vGfInitMWStateVariable(void);


/**
* @brief Implementation of function vGfSetNeedleNumber
*
* Sets the needle to be rotated
*
* @note none
*
* @param[in] u32Number - Number of needle
*
* @return void
*/
void vGfSetNeedleNumber(uint32_t u32Number);


/**
* @brief Implementation of function u32GfGetNeedleNumber
*
* Returns the needle to be rotated
*
* @note none
*
* @return Current selected needle number for rotation
*/
uint32_t u32GfGetNeedleNumber(void);


/**
* @brief Implementation of function vGfSetPaletteStream
*
* Sets the single palette stream flags
*
* @note This function MUST be called before calling blit 
*       functions to reset the palette table values 
*
* @return void
*/
void vGfSetPaletteStream(void);


/**
* @brief Implementation of function vGfSetStateRedChanProtect
*
* Enables red channel protection
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void vGfSetStateRedChanProtect(ga_en_e eEnable);


/**
* @brief Implementation of function vGfSetStateGreenChanProtect
*
* Enables green channel protection
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void vGfSetStateGreenChanProtect(ga_en_e eEnable);


/**
* @brief Implementation of function vGfSetStateBlueChanProtect
*
* Enables blue channel protection
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void vGfSetStateBlueChanProtect(ga_en_e eEnable);


/**
* @brief Implementation of function vGfSetStateColorChanProtect
*
* Sets color channel protection
*
* @note none
*
* @param[in] stColorPrt - Enable/disable red, green and blue color protection
*
* @return void
*/
void vGfSetStateColorChanProtect(gf_colorprt_st stColorPrt);


/**
* @brief Implementation of function stGfGetStateColorChanProtect
*
* Returns color channel protection values
*
* @note none
*
* @return Color channel protection values for red, green and blue channel
*/
gf_colorprt_st stGfGetStateColorChanProtect(void);


/**
* @brief Implementation of function vGfSetStateAlphaChanProtect
*
* Enables alpha channel protection
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void vGfSetStateAlphaChanProtect(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateAlphaChanProtect
*
* Return state of alpha channel protection
*
* @note none
*
* Outputs: eEnable - Enable/disable
*
* @return GA_DIS if alpha channel protection is disabled
* @return GA_EN if alpha channel protection is enabled
*/
ga_en_e eGfGetStateAlphaChanProtect(void);


/**
* @brief Implementation of function eGfSetStateRedChanFading
*
* Enables red channel fading
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void eGfSetStateRedChanFading(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateRedChanFading
*
* Return state of red channel fading
*
* @note none
*
* @return GA_DIS if red channel fading is disabled
* @return GA_EN if red channel fading is enabled
*/
ga_en_e eGfGetStateRedChanFading(void);


/**
* @brief Implementation of function eGfSetStateGreenChanFading
*
* Enables green channel fading
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void eGfSetStateGreenChanFading(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateGreenChanFading
*
* Return state of green channel fading
*
* @note none
*
* @return GA_DIS if green channel fading is disabled
* @return GA_EN if green channel fading is enabled
*/
ga_en_e eGfGetStateGreenChanFading(void);


/**
* @brief Implementation of function eGfSetStateBlueChanFading
*
* Enables blue channel fading
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void eGfSetStateBlueChanFading(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateBlueChanFading
*
* Return state of blue channel fading
*
* @note none
*
* @return GA_DIS if blue channel fading is disabled
* @return GA_EN if blue channel fading is enabled
*/
ga_en_e eGfGetStateBlueChanFading(void);


/**
* @brief Implementation of function eGfSetStateAlphaChanFading
*
* Enables alpha channel fading
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void eGfSetStateAlphaChanFading(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateAlphaChanFading
*
* Return state of alpha channel fading
*
* @note none
*
* @return GA_DIS if alpha channel fading is disabled
* @return GA_EN if alpha channel fading is enabled
*/
ga_en_e eGfGetStateAlphaChanFading(void);


/**
* @brief Implementation of function vGfSetStateFilter
*
* Enables filter
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void vGfSetStateFilter(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateFilter
*
* Returns if filter is enabled or disabled
*
* @note none
*
* @return GA_DIS if filter is disabled
* @return GA_EN if filter is enabled
*/
ga_en_e eGfGetStateFilter(void);


/**
* @brief Implementation of function vGfSetStateBlendOrder
*
* Sets the blend order
*
* @param[in] eBlendOrder - Blend order type
*
* @return void
*/
void vGfSetStateBlendOrder(ga_blendOrd_e eBlendOrder);


/**
* @brief Implementation of function eGfGetStateBlendOrder
*
* Sets the blend order
*
* @note none
*
* @return GA_ONTO_DEST if source is blended on destination
* @return GA_BEHIND_DEST if source is blended behind destination
*/
ga_blendOrd_e eGfGetStateBlendOrder(void);


/**
* @brief Implementation of function vGfSetStateFadeMode
*
* Sets the fade mode
*
* @note none
*
* @param[in] eFadeMode - Fade mode
*
* @return void
*/
void vGfSetStateFadeMode(blt_fadeMode_e eFadeMode);


/**
* @brief Implementation of function eGfGetStateFadeMode
*
* Returns the fade mode
*
* @note none
*
* @return BLT_NOFADING if no fading is done
* @return BLT_FADE_ALL if RGB and Alpha will be faded
* @return BLT_FADE_ALPHA if only Alpha will be faded
* @return BLT_FADE_RGB if only RGB will be faded
*/
blt_fadeMode_e eGfGetStateFadeMode(void);


/**
* @brief Implementation of function vGfSetStateFadingFactor
*
* Sets the fading factor
*
* @note none
*
* @param[in] u8FadeFactor - Fading factor
*
* @return void
*/
void vGfSetStateFadingFactor(uint8_t u8FadeFactor);


/**
* @brief Implementation of function u8GfGetStateFadingFactor
*
* Returns the fading factor
*
* @note none
*
* @return Fading factor value
*/
uint8_t u8GfGetStateFadingFactor(void);


/**
* @brief Implementation of function vGfSetStateTransparentColor
*
* Enables or disables color transparency
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void vGfSetStateTransparentColor(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateTransparentColor
*
* Returns color transparency
*
* @note none
*
* @return GA_DIS if transparent color is disabled
* @return GA_EN if transparent color is enabled
*/
ga_en_e eGfGetStateTransparentColor(void);


/**
* @brief Implementation of function vGfSetStateTransparencyValues
*
* Sets the color transparency values
*
* @note none
*
* @param[in] stTransVal - Source and destination transparency values
*
* @return void
*/
void vGfSetStateTransparencyValues(gf_transval_st stTransVal);


/**
* @brief Implementation of function stGfGetStateTransparencyValues
*
* Returns the color transparency values
*
* @note none
*
* @return Source and destination transparency values
*/
gf_transval_st stGfGetStateTransparencyValues(void);


/**
* @brief Implementation of function vGfSetStateAlphaValues
*
* Sets the alpha values
*
* @note none
*
* @param[in] stAlphaVal - Source and destination alpha values
*
* @return void
*/
void vGfSetStateAlphaValues(gf_alphaval_st stAlphaVal);


/**
* @brief Implementation of function stGfGetStateAlphaValues
*
* Returns the alpha values
*
* @note none
*
* @return Source and destination alpha values
*/
gf_alphaval_st stGfGetStateAlphaValues(void);


/**
* @brief Implementation of function vGfSetStateTransformationMode
*
* Sets the transformation mode
*
* @note none
*
* @param[in] eTsfMode - Transformation mode
*
* @return void
*/
void vGfSetStateTransformationMode(transf_Mode_e eTsfMode);


/**
* @brief Implementation of function eGfGetStateTransformationMode
*
* Returns the transformation mode
*
* @note none
*
* @return TSF_MODE_PIXEL if pixel mode operation is selected
* @return TSF_MODE_COLOR if color mode operation is selected
*/
transf_Mode_e eGfGetStateTransformationMode(void);


/**
* @brief Implementation of function vGfSetStateTransformationPredefinedColor
*
* Sets predefined color for transformation
*
* @note none
*
* @param[in] u32PredefColor - Transformation predefined color
*
* @return void
*/
void vGfSetStateTransformationPredefinedColor(uint32_t u32PredefColor);


/**
* @brief Implementation of function eGfGetStateTransformationMode
*
* Returns the predefined color value for transformation
*
* @note none
*
* @return Predefined color for transformation
*/
uint32_t eGfGetStateTransformationPredefinedColor(void);


/**
* @brief Implementation of function vGfSetStateRasterOperationModeEnable
*
* Enables or disables raster operation mode
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void vGfSetStateRasterOperationModeEnable(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateRasterOperationModeEnable
*
* Returns raster operation mode
*
* @note none
*
* @return GA_DIS if raster operation is disabled
* @return GA_EN if raster operation is enabled
*/
ga_en_e eGfGetStateRasterOperationModeEnable(void);


/**
* @brief Implementation of function vGfSetStateRasterOperationMode
*
* Sets raster operation mode
*
* @note none
*
* @param[in] eRastOpMode - Raster operation mode
*
* @return void
*/
void vGfSetStateRasterOperationMode(blt_rastChSel_e eRastOpMode);


/**
* @brief Implementation of function eGfGetStateRasterOperationMode
*
* Returns raster operation mode
*
* @note none
*
* @return BLT_RGBA_CH if raster operation should be applied on all channels
* @return BLT_RGB_CH if raster operation should be applied on RGB channels
* @return BLT_ALPHA_CH if raster operation should be applied on Alpha channel only
* @return BLT_ALPHA_DEST_CH if raster operation should be applied on RGB and destination alpha channel should be kept
* @return BLT_ALPHA_SRC_CH if raster operation should be applied on RGB and source alpha channel should be kept
*/
blt_rastChSel_e eGfGetStateRasterOperationMode(void);


/**
* @brief Implementation of function vGfSetStateRasterOperationValue
*
* Sets raster operation value
*
* @note none
*
* @param[in] eRastOpValue - Raster operation value
*
* @return void
*/
void vGfSetStateRasterOperationValue(blt_rastOpVal_e eRastOpValue);


/**
* @brief Implementation of function eGfGetStateRasterOperationValue
*
* Returns raster operation value
*
* @note none
*
* @return BLT_RAST_SOURCE if source should be taken
* @return BLT_RAST_SRC_INV if source should be inverted
* @return BLT_RAST_DEST if destination should be taken
* @return BLT_RAST_DEST_ZERO if destination should be set to 0
* @return BLT_RAST_DEST_ONE if destination should be set to 1
* @return BLT_RAST_DEST_INV if destination should be inverted
* @return BLT_RAST_S_AND_D if ( source AND  destination)
* @return BLT_RAST_NS_AND_D if (~source AND  destination)
* @return BLT_RAST_S_AND_ND if ( source AND ~destination)
* @return BLT_RAST_S_AND_D_INV if ~( source AND  destination)
* @return BLT_RAST_S_OR_D if ( source OR  destination)
* @return BLT_RAST_NS_OR_D if (~source OR  destination)
* @return BLT_RAST_S_OR_ND if ( source OR ~destination)
* @return BLT_RAST_S_OR_D_INV if ~( source OR  destination)
* @return BLT_RAST_S_XOR_D if ( source XOR destination)
* @return BLT_RAST_S_XOR_D_INV if ~( source XOR destination)
*/
blt_rastOpVal_e eGfGetStateRasterOperationValue(void);


/**
* @brief Implementation of function vGfSetStateClipWindow
*
* Activates or deactivates ClipWindow
*
* @note none
*
* @param[in] eEnable - Enable/disable
*
* @return void
*/
void vGfSetStateClipWindow(ga_en_e eEnable);


/**
* @brief Implementation of function eGfGetStateClipWindow
*
* Returns if ClipWindow is enabled or disabled
*
* @note none
*
* @return GA_DIS if clip window is disabled
* @return GA_EN if clip window is enabled
*/
ga_en_e eGfGetStateClipWindow(void);


/**
* @brief Implementation of function vGfSetStateClipWindowCoordinates
*
* Set clip window parameter
*
* @note none
*
* @param[in] u16ClipC1_X - clip window upper left point x coordinate
* @param[in] u16ClipC1_Y - clip window upper left point y coordinate
* @param[in] u16ClipC2_X - clip window lower left point x coordinate
* @param[in] u16ClipC2_Y - clip window lower left point y coordinate
*
* @return void
*/
void vGfSetStateClipWindowCoordinates(uint16_t u16ClipC1_X, uint16_t u16ClipC1_Y, uint16_t u16ClipC2_X, uint16_t u16ClipC2_Y);

/**
* @brief Implementation of function vGfSetSubRes
*
* Sets sub position accuracy for position and rotation center point
*
* @note none
*
* @param[in] eResPPos - accuracy type for placement position
* @param[in] eResCPos - accuracy type for rotation center point position
*
* @return void
*/
void vGfSetSubRes(gf_subRes_e eResPPos, gf_subRes_e eResCPos);

/**
* @brief Implementation of function f32GA_GetSubRes_Position
*
* Return position sub resolution value
*
* @note none
*
* @return subresolution value in float32_t
*/
float32_t f32GfGetSubRes_Position(void);


/**
* @brief Implementation of function u32GA_GetSubRes_Position
*
* Return position sub resolution value
*
* @note none
*
* @return subresolution value in uint32_t
*/
uint32_t u32GfGetSubRes_Position(void);


/**
* @brief Implementation of function f32GA_GetSubRes_CenterPosition
*
* Return center position sub resolution value
*
* @note none
*
* @return subresolution value in float32_t
*/
float32_t f32GfGetSubRes_CenterPosition(void);


/**
* @brief Implementation of function u32GA_GetSubRes_CenterPosition
*
* Return center position sub resolution value
*
* @note none
*
* @return subresolution value in uint32_t
*/
uint32_t u32GfGetSubRes_CenterPosition(void);


/*****************************************************************************
 *
 *                          BUFFER-BASED FUNCTIONS
 *
 ****************************************************************************/

/**
* @brief Implementation of function vGfFillArea
*
* Fills the buffer area with the specified color
*
* @note No subpixel positioning possible.
*
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstImgPart  - Pointer to part to be filled
* @param[in] u32Color    - Color
*
* @return void
*/
void vGfBuffFillArea(gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart, uint32_t u32Color);


/**
* @brief Implementation of function u32GfBuffBlitBitmapFull
*
* Blits entire bitmap into the given destination buffer
* color format is taken into account
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
uint32_t u32GfBuffBlitBitmapFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                                 int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlitBitmapFull
*
* Blits entire bitmap into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlitBitmapFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                           int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlitBitmapPart
*
* Blits part of the bitmap into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstImgPart  - Part of the image to be copied
* @param[in] u32PosX     - X-offset from the destination buffer start
* @param[in] u32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlitBitmapPart(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                           uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function u32GfBuffBlitBitmapPart
*
* Blits part of the bitmap into the given destination buffer
* color format is taken into account
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstImgPart  - Part of the image to be copied
* @param[in] u32PosX     - X-offset from the destination buffer start
* @param[in] u32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
uint32_t u32GfBuffBlitBitmapPart(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                                 uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfBuffBlitBitmapRLE16
*
* Blits entire bitmap in RLE16 format into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlitBitmapRLE16(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                            int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlitBitmapRLE24
*
* Blits entire bitmap in RLE24 format into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlitBitmapRLE24(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                            int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlitBitmapRLE24A
*
* Blits entire bitmap in RLE24A format into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlitBitmapRLE24A(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlitBitmapRLE32
*
* Blits entire bitmap in RLE32 format into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlitBitmapRLE32(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                            int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlendFillArea
*
* Fills the specified area of the buffer with the specified color with blending
*
* @note No subpixel positioning possible.
*
* @param[in] pstDstImage - destination image
* @param[in] pstImgPart  - part to be filled
* @param[in] u32Color    - color
*
* @return void
*/
void vGfBuffBlendFillArea(gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart, uint32_t u32Color);


/**
* @brief Implementation of function u32GfBuffBlendBitmapFull
*
* Blends entire bitmap into the given destination buffer
* color format is taken into account
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
uint32_t u32GfBuffBlendBitmapFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                                  int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlendBitmapFull
*
* Blends entire bitmap into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlendBitmapFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                            int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function u32GfBuffBlendBitmapPart
*
* Blends given part of the bitmap into the given destination buffer
* color format is taken into account
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstImgPart  - Pointer to part of the image to be copied
* @param[in] u32PosX     - X-offset from the destination buffer start
* @param[in] u32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
uint32_t u32GfBuffBlendBitmapPart(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                                  uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfBuffBlendBitmapPart
*
* Blends given part of the bitmap into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstImgPart  - Pointe to part of the image to be copied
* @param[in] u32PosX     - X-offset from the destination buffer start
* @param[in] u32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlendBitmapPart(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                            uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfBuffBlendBitmapRLE16
*
* Blends entire bitmap in RLE16 format into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlendBitmapRLE16(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlendBitmapRLE24
*
* Blends entire bitmap in RLE24 format into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlendBitmapRLE24(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlendBitmapRLE24A
*
* Blends entire bitmap in RLE24A format into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlendBitmapRLE24A(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                              int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffBlendBitmapRLE32
*
* Blends entire bitmap in RLE32 format into the given destination buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffBlendBitmapRLE32(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffRotateBitmapFull
*
* Rotates the entire bitmap into the given destination buffer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] f32Angle    - Rotation angle
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffRotateBitmapFull(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffRotateBitmapPart
*
* Rotates part of the bitmap into the given destination buffer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] f32Angle    - Rotation angle
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstImgPart  - Pointer to part of the image to be copied
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffRotateBitmapPart(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffRotateBitmapOptimized
*
* Rotates the entire bitmap cache optimized into the given
* destination buffer
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       No subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstSrcImage    - Pointer to source image
* @param[in] f32Angle       - Rotation angle
* @param[in] pstDstImage    - Pointer to destination image
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockWidth  - Width of block
* @param[in] u32BlockHeight - Height of block
*
* @return void
*/
void vGfBuffRotateBitmapOptimized(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                                  uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfBuffRotateBlendBitmapFull
*
* Rotates the entire bitmap and blend it into the given destination buffer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] f32Angle    - Rotation angle
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffRotateBlendBitmapFull(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                                  int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffRotateBlendBitmapPart
*
* Rotates the entire bitmap and blend it into the given destination buffer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] f32Angle    - Rotation angle
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstImgPart  - Pointer to part of the image to be copied
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffRotateBlendBitmapPart(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                                  int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffRotateNeedleFill
*
* Rotates the entire needle into the given destination buffer with fill
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible in x-direction. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstSrcImage    - Pointer to source image of needle
* @param[in] f32Angle       - Rotation angle
* @param[in] pstDstImage    - Pointer to destination image
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockHeight - Height of block
*
* @return void
*/
void vGfBuffRotateNeedleFill(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                             uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfBuffRotateNeedle
*
* Rotates and blends the entire needle image into the given destination
* buffer
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible in x-direction. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstSrcImageBg  - Pointer to background source image
* @param[in] pstSrcImage    - Pointer to source image of needle
* @param[in] f32Angle       - Rotation angle
* @param[in] pstDstImage    - Pointer to destination image
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockHeight - Height of block
*
* @return void
*/
void vGfBuffRotateNeedle(gf_image_st * pstSrcImageBg, gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                         uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfBuffRotateNeedleTipandBaseFill
*
* Rotates optimized and blends the entire needle image into the given layer
* with restoring the background by filling
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       No subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstSrcImage  - Pointer to source image of needle
* @param[in] f32Angle     - Rotation angle
* @param[in] pstDstImage  - Pointer to destination image
* @param[in] u32PosX      - X-offset from the destination buffer start
* @param[in] u32PosY      - Y-offset from the destination buffer start
* @param[in] pstDef       - Parameter for image
*
* @return void
*/
void vGfBuffRotateNeedleTipandBaseFill(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                                       uint32_t u32PosX, uint32_t u32PosY, gf_def_st * pstDef);


/**
* @brief Implementation of function vGfBuffRotateNeedleTipandBase
*
* Rotates optimized and blends the entire needle image into the given layer
* with restoring the background
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       No subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstSrcImageBg - Pointer to background source image
* @param[in] pstSrcImage   - Pointer to source image of needle
* @param[in] f32Angle      - Rotation angle
* @param[in] pstDstImage   - Pointer to destination image
* @param[in] u32PosX       - X-offset from the destination buffer start
* @param[in] u32PosY       - Y-offset from the destination buffer start
* @param[in] pstDef        - Parameter for image
*
* @return void
*/
void vGfBuffRotateNeedleTipandBase(gf_image_st * pstSrcImageBg, gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                                   uint32_t u32PosX, uint32_t u32PosY, gf_def_st * pstDef);


/**
* @brief Implementation of function vGfBuffShearFull
*
* Shears an image in x- and y-direction by the specified factors into the given destination
* buffer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] f32FactorX  - Shearing factor in x-direction
* @param[in] f32FactorY  - Shearing factor in y-direction
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffShearFull(gf_image_st * pstSrcImage, float32_t f32FactorX, float32_t f32FactorY, gf_image_st * pstDstImage,
                      int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffShearBlendFull
*
* Shears an image in x- and y-direction by the specified factors into the given destination
* buffer with blending
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] f32FactorX  - Shearing factor in x-direction
* @param[in] f32FactorY  - Shearing factor in y-direction
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffShearBlendFull(gf_image_st * pstSrcImage, float32_t f32FactorX, float32_t f32FactorY, gf_image_st * pstDstImage,
                           int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffScaleFull
*
* Scales an image in x- and y-direction by the specified factors into the given destination
* buffer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] f32FactorX  - Scaling factor in x-direction
* @param[in] f32FactorY  - Scaling factor in y-direction
* @param[in] eAlignment  - Alignment in Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffScaleFull(gf_image_st * pstSrcImage, float32_t f32FactorX, float32_t f32FactorY,
                      rot_scaleAlign_e eAlignment, gf_image_st * pstDstImage,
                      int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfBuffScaleBlendFull
*
* Scales an image in x- and y-direction by the specified factors into the given destination
* buffer with blending
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] f32FactorX  - Scaling factor in x-direction
* @param[in] f32FactorY  - Scaling factor in y-direction
* @param[in] eAlignment  - Alignment in Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] i32PosX     - X-offset from the destination buffer start
* @param[in] i32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffScaleBlendFull(gf_image_st * pstSrcImage, float32_t f32FactorX, float32_t f32FactorY,
                           rot_scaleAlign_e eAlignment, gf_image_st * pstDstImage,
                           int32_t i32PosX, int32_t i32PosY);


#ifdef GA_USE_MATH_LIB
/**
* @brief Implementation of function vGfBuffPerspectiveBlitFull
*
* Puts an image into perspective by rotation on x-, y- and z-axis by the specified angle
* and blits it into the given buffer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstSrcImage  - Pointer to source image
* @param[in] f32AngleX    - Rotation angle x-axis
* @param[in] f32AngleY    - Rotation angle y-axis
* @param[in] f32AngleZ    - Rotation angle z-axis
* @param[in] f32FactorX   - Scaling factor X
* @param[in] f32FactorY   - Scaling factor Y
* @param[in] pstDstImage  - Pointer to destination image
* @param[in] i32PosX      - X-offset from the destination buffer start
* @param[in] i32PosY      - Y-offset from the destination buffer start
* @param[in] u32RotPointX - Rotation point X
* @param[in] u32RotPointY - Rotation point Y
*
* @return void
*/
void vGfBuffPerspectiveBlitFull(gf_image_st * pstSrcImage, float32_t f32AngleX, float32_t f32AngleY, float32_t f32AngleZ,
                                float32_t f32FactorX, float32_t f32FactorY, gf_image_st * pstDstImage,
                                int32_t i32PosX, int32_t i32PosY,
                                uint32_t u32RotPointX, uint32_t u32RotPointY);


/**
* @brief Implementation of function vGfBuffPerspectiveBlendFull
*
* Puts an image into perspective by rotation on x-, y- and z-axis by the specified angle
* and blends it into the given buffer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstSrcImage  - Pointer to source image
* @param[in] f32AngleX    - Rotation angle x-axis
* @param[in] f32AngleY    - Rotation angle y-axis
* @param[in] f32AngleZ    - Rotation angle z-axis
* @param[in] f32FactorX   - Scaling factor X
* @param[in] f32FactorY   - Scaling factor Y
* @param[in] pstDstImage  - Pointer to destination image
* @param[in] i32PosX      - X-offset from the destination buffer start
* @param[in] i32PosY      - Y-offset from the destination buffer start
* @param[in] u32RotPointX - Rotation point X
* @param[in] u32RotPointY - Rotation point Y
*
* @return void
*/
void vGfBuffPerspectiveBlendFull(gf_image_st * pstSrcImage, float32_t f32AngleX, float32_t f32AngleY, float32_t f32AngleZ,
                                 float32_t f32FactorX, float32_t f32FactorY, gf_image_st * pstDstImage,
                                 int32_t i32PosX, int32_t i32PosY,
                                 uint32_t u32RotPointX, uint32_t u32RotPointY);
#endif


/**
* @brief Implementation of function vGfBuffTransformationFull
*
* Starts the transformation of the entire image into the given destination
* buffer
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstTable    - Pointer to transformation table
* @param[in] u32PosX     - X-offset from the destination buffer start
* @param[in] u32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffTransformationFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_table_st * pstTable,
                               uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfBuffTransformationFullOptimized
*
* Starts the transformation of the entire image into the given destination
* buffer cache optimized
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage    - Pointer to source image
* @param[in] pstDstImage    - Pointer to destination image
* @param[in] pstTable       - Pointer to transformation table
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockWidth  - Block width
* @param[in] u32BlockHeight - Block height
*
* @return void
*/
void vGfBuffTransformationFullOptimized(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_table_st * pstTable,
                                        uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfBuffTransformationBlendFull
*
* Starts the transformation of the entire image into the given destination
* buffer with blending
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
* @param[in] pstTable    - Pointer to transformation table
* @param[in] u32PosX     - X-offset from the destination buffer start
* @param[in] u32PosY     - Y-offset from the destination buffer start
*
* @return void
*/
void vGfBuffTransformationBlendFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_table_st * pstTable,
                                    uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfBuffTransformationBlendFull
*
* Starts the transformation of the entire image into the given destination
* buffer with blending cache optimized
*
* @note No subpixel positioning possible.
*
* @param[in] pstSrcImage    - Pointer to source image
* @param[in] pstDstImage    - Pointer to destination image
* @param[in] pstTable       - Pointer to transformation table
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockWidth  - Block width
* @param[in] u32BlockHeight - Block height
*
* @return void
*/
void vGfBuffTransformationBlendFullOptimized(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_table_st * pstTable,
                                             uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfBuffDrawLine
*
* Draw line
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel linewidth possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstDstImage  - destination image
* @param[in] pstOption    - pointer to option for draw operation
* @param[in] pstLine      - pointer to line properties for draw operation
*
* @return void
*/
void vGfBuffDrawLine(gf_image_st * pstDstImage, drw_OpCfg_st *pstOption, drw_Line_st *pstLine);


/**
* @brief Implementation of function vGfBuffDrawTriangle
*
* Draw triangle
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstDstImage  - destination image
* @param[in] pstOption    - pointer to option for draw operation
* @param[in] pstTrngl     - pointer to triangle properties for draw operation
*
* @return void
*/
void vGfBuffDrawTriangle(gf_image_st * pstDstImage, drw_OpCfg_st *pstOption, drw_Trngl_st *pstTrngl);


/**
* @brief Implementation of function vGfBuffDrawCircle
*
* Draw cirlce
*
* @note Subpixel positioning possible. Center Coordinates have to be set accordingly (only using eResPPos parameter of function vGfSetSubRes).
*       (Do not set eResCPos parameter of function vGfSetSubRes for Subpixel positioning of center coordinates)
*
* @param[in] pstDstImage  - destination image
* @param[in] pstOption    - pointer to option for draw operation
* @param[in] pstCircle    - pointer to circle properties for draw operation
*                           like center co-ordinates, radius, draw colour and AA effect
*
* Limitation : The center and radius of the circle should be given such that the circle lies completely in the positive quadrant. 
*
* @return void
*/
void vGfBuffDrawCircle(gf_image_st *pstDstImage, drw_OpCfg_st *pstOption, gf_circle_st *pstCircle);


/**
* @brief Implementation of function vGfBuffDrawPolygon
*
* Draw polygon
*
* @note Subpixel positioning possible. Coordinates parameter have to be set accordingly (using eResPPos parameter of function vGfSetSubRes).
*
* @param[in] pstDstImage  - destination image
* @param[in] pstOption    - pointer to option for draw operation
* @param[in] pstPolygon   - Pointer to the vertices of the polygon, Number of vertices, draw colour and AA effects
*
* Limitation : The vertices should be given either in clockwise or anticlockwise direction only. The API will support only convex polygons.
*
* @return void
*/
void vGfBuffDrawPolygon(gf_image_st *pstDstImage, drw_OpCfg_st *pstOption, gf_polygon_st *pstPolygon);


/**
* @brief Implementation of function vGfInsertList
*
* Insert commands in commandlist
*
* @note none
*
* @param[in] pu64Values  - start address
* @param[in] u32Length   - length of command list to be inserted
*
* @return void
*/
void vGfInsertList(uint64_t * pu64Values, uint32_t u32Length);


/**
* @brief Implementation of function vGfViewport
*
* Function vGfViewport specifies the affine transformation of X and Y from normalised system coordinates to window coordiantes.
* If (xnd, ynd) are normalised system coordinates the window coordinates (xw, yw) are calculated as defined below:
*   xw = (xnd + 1)(width / 2)  + x
*   yw = (ynd + 1)(height / 2) + y
*
* @note (vgl. http://wiki.delphigl.com/)
*
* @param[in] f64X      - Viewport start in x-direction
* @param[in] f64Y      - Viewport start in y-direction
* @param[in] f64Width  - Viewport width
* @param[in] f64Height - Viewport height
*
* @return void
*/
void vGfViewport(float64_t f64X, float64_t f64Y, float64_t f64Width, float64_t f64Height);


/**
* @brief Implementation of function vGfFrustum
*
* Function vGfFrustum describes a perspective matrix doing a perspektive projection.
* The current matrix (compare vGfMatrixMode) will be multiplied with this matrix. The result replaces the current matrix.
*
* @note none
*
* @param[in] f64Left   - Specifies the coordinate for the left (vertical) intersection.
* @param[in] f64Right  - Specifies the coordinate for the right (vertical)intersection.
* @param[in] f64Bottom - Specifies the coordinate for the lower (horizontal) intersection.
* @param[in] f64Top    - Specifies the coordinate for the upper (horizontal) intersection.
* @param[in] f64zNear  - Specifies the coordinate of the near layer. The value should be positive.
* @param[in] f64zFar   - Specifies the coordinate of the far layer. The value should be positive.
*
* @return void
*/
void vGfFrustum(float64_t f64Left, float64_t f64Right, float64_t f64Bottom, float64_t f64Top, float64_t f64zNear, float64_t f64zFar);


/**
* @brief Implementation of function vGfMatrixMode
*
* Set current Matrix-mode
* GA_RE_MODELVIEW  - Apply future matrix operations to modelview-matrixstack.
* GA_RE_PROJECTION - Apply future matrix operations to projektion-matrixstack.
*
* @note none
*
* @param[in] eMatrix - Matrix mode type
*
* @return void
*/
void vGfMatrixMode(gf_matrixmodes_e eMatrix);


/**
* @brief Implementation of function vGfLoadIdentity
*
* Function vGfLoadIdentity replaces the current matrix by the identity matrix.
*
* @note none
*
* @param[in] void
*
* @return void
*/
void vGfLoadIdentity(void);
	
	
/**
* @brief Implementation of function vGfLoadIP
*
* Function vGfLoadIP loads the IP-matrix.
*
* @note none
*
* @param[in] void
*
* @return void
*/
void vGfLoadIP(void);


/**
* @brief Implementation of function vGfTranslate
*
* The function vGfTranslate translates the point of origin to the point (x,y,z).
* Vector (x,y,z) is used to generate a 4x4 translation matix. The current matrix is multiplied by it.
* The result replaces the current matrix.
*  | 1  0  0  x |
*  | 0  1  0  y |
*  | 0  0  1  z |
*  | 0  0  0  1 |
* If the current matrix is GA_RE_MODELVIEW or GA_RE_PROJECTION objects rendered after a call to function vGfTranslate will be translated accordingly.
*
* @note none
*
* @param[in] f64X - Translation in x direction
* @param[in] f64X - Translation in y direction
* @param[in] f64X - Translation in z direction
*
* @return void
*/
void vGfTranslate(float64_t f64X, float64_t f64Y, float64_t f64Z);


/**
* @brief Implementation of function vGfScale
*
* Function vGfScale is doing a distortion or mirowing of the coordinate system.
* To do this a scaling-matrix is multiplied with the current matrix.
* The scaling-matrix can be found below:
*  | x  0  0  0 |
*  | 0  y  0  0 |
*  | 0  0  z  0 |
*  | 0  0  0  1 |
* Here x, y, z corrspond to the function parameters.
* Never scale a coordinate sxxis to 0 (x,y and z always <> 0.0)!
*
* @note none
*
* @param[in] f64X - Scaling factor in x direction
* @param[in] f64X - Scaling factor in y direction
* @param[in] f64X - Scaling factor in z direction
*
* @return void
*/
void vGfScale(float64_t f64X, float64_t f64Y, float64_t f64Z);


/**
* @brief Implementation of function vGfRotate
*
* Function vGfRotate multiplies the current matrix with a rotation-matrix R.
* By this rotationmmatrix all points are rotated counter clockwise by the defined angle around the vector specified by (x,y,z).
* Below the rotation-matrix R can be found:
*  | x²(1-c)+c    xy(1-c)-zs   xz(1-c)+ys   0 |
*  | yx(1-c)+zs   y²(1-c)+c    yz(1-c)-xs   0 |
*  | xz(1-c)-ys   yz(1-c)+xs   z²(1-c)+c    0 |
*  |     0            0            0        1 |
* with
* c = cos(angle)
* s = sin(angle)
* length(x,y,z) = 1
*
* @note none
*
* @param[in] f64Angle - Rotation angle
* @param[in] f64X     - X-axxis for rotation
* @param[in] f64X     - Y-axxis for rotation
* @param[in] f64X     - Z-axxis for rotation
*
* @return void
*/
void vGfRotate(float64_t f64Angle, float64_t f64X, float64_t f64Y, float64_t f64Z);


/**
* @brief Implementation of function iGfProject
*
* Function iGfProject converts object-coordinates to window-coordinates by using modelview-, projection- and viewport-matrix.
* The result is stored internally for further calculation.
*
* @note Code taken from https://www.opengl.org/wiki/GluProject_and_gluUnProject_code
*
* @param[in]     pf64Obj - Pointer to array of 4 valuese (x,y,z,w)
*
* @return void
*/
int iGfProject(float64_t * pf64Obj);


/**
* @brief Implementation of function iGfUnProject
*
* Function iGfUnProject converts window-coordinates (pf64Win) to object-coordinates by using modelview-, projection- and viewport-matrix.
* The result is stored in pf64Obj.
*
* @note Code taken from https://www.opengl.org/wiki/GluProject_and_gluUnProject_code
*
* @param[in,out] pf64Win - Pointer to array of 4 valuese (x,y,z,w)
* @param[in]     pf64Obj - Pointer to array of 4 valuese (x,y,z,w)
*
* @return void
*/
int iGfUnProject(float64_t * pf64Obj, float64_t * pf64Win);


/**
* @brief Implementation of function vGfSetIP
*
* Function vGfSetIP calculates the "identityProjection"-matrix for the object to be transformed.
* Precondition: The height of the objects is normalized to 1, the width is width/height. The center of the object should be positioned in the center of the coordinate system.
* p1x=-(width/2)*height; 	p1y=-0.5;  	p1z= 0;  	p1w= 1;
*	p2x=-(width/2)*height; 	p2y= 0.5;  	p2z= 0;  	p2w= 1;
*	p3x= (width/2)*height; 	p3y= 0.5;  	p3z= 0;  	p3w= 1;
*	p4x= (width/2)*height; 	p4y=-0.5;  	p4z= 0;  	p4w= 1;
*
* @note (c) TEEBEL
*
* @param[in] f64ImgWidth  - Image width
* @param[in] f64ImgHeight - Image height
* @param[in] f64Znear     - Defines the distance to the near layer. The value should be positive.
* @param[in] f64Zfar      - Defines the distance to the far layer. The value should be positive.
*
* @return void
*/
void vGfSetIP(float64_t f64ImgWidth, float64_t f64ImgHeight, float64_t f64Znear, float64_t f64Zfar);


/**
* @brief Implementation of function vGfBuffBlitElement
*
* Render an image configured in OpenGL style
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
*
* @return void
*/
void vGfBuffBlitElement(gf_image_st * pstSrcImage, gf_image_st * pstDstImage);


/**
* @brief Implementation of function vGfBuffBlendElement
*
* Render an image configured in OpenGL style with blending
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstDstImage - Pointer to destination image
*
* @return void
*/
void vGfBuffBlendElement(gf_image_st * pstSrcImage, gf_image_st * pstDstImage);


/*****************************************************************************
 *
 *                      LAYER-BASED (WRAPPER) FUNCTIONS
 *
 ****************************************************************************/

/**
* @brief Implementation of function vGfLayerFillArea
*
* Fills the layer area with the specified color
*
* @note No subpixel positioning possible.
*
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstImgPart - Pointer to part of image
* @param[in] u32Color   - Height of area to be filled
*
* @return void
*/
void vGfLayerFillArea(gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                      uint32_t u32Color);


/**
* @brief Implementation of function u32GfLayerBlitBitmapFull
*
* Blits entire bitmap into the given layer
* color format is taken into account
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
uint32_t u32GfLayerBlitBitmapFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                                  int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlitBitmapFull
*
* Blits entire bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlitBitmapFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                            int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function u32GfLayerBlitBitmapPart
*
* Blits part of the bitmap into the given layer
* color format is taken into account
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstImgPart - Pointer to part of the image to be copied
* @param[in] u32PosX    - X-offset from the destination buffer start
* @param[in] u32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
uint32_t u32GfLayerBlitBitmapPart(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                                  uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfLayerBlitBitmapPart
*
* Blits part of the bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstImgPart - Pointer to part of the image to be copied
* @param[in] u32PosX    - X-offset from the destination buffer start
* @param[in] u32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlitBitmapPart(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                            uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfLayerBlitBitmapRLE16
*
* Blits entire RLE16 bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlitBitmapRLE16(gf_image_st * pstImage, gf_layer_st * pstLayer,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlitBitmapRLE24
*
* Blits entire RLE24A bitmap into the given layer
*
* @note none
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return No subpixel positioning possible.
*/
void vGfLayerBlitBitmapRLE24(gf_image_st * pstImage, gf_layer_st * pstLayer,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlitBitmapRLE24A
*
* Blits entire RLE24A bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlitBitmapRLE24A(gf_image_st * pstImage, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlitBitmapRLE32
*
* Blits entire RLE32 bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlitBitmapRLE32(gf_image_st * pstImage, gf_layer_st * pstLayer,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlendFillArea
*
* Fills the specified area of the buffer with the specified color with blending
*
* @note No subpixel positioning possible.
*
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstImgPart - Pointer to part of image to be filled
* @param[in] u32Color   - Color
*
* @return void
*/
void vGfLayerBlendFillArea(gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart, uint32_t u32Color);


/**
* @brief Implementation of function u32GfLayerBlendBitmapFull
*
* Blends entire bitmap into the given layer
* color format is taken into account
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
uint32_t u32GfLayerBlendBitmapFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                                   int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlendBitmapFull
*
* Blends entire bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlendBitmapFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                             int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function u32GfLayerBlendBitmapPart
*
* Blends the given part of the bitmap into the given layer
* color format is taken into account
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstImgPart - Pointer to part of the image to be copied
* @param[in] u32PosX    - X-offset from the destination buffer start
* @param[in] u32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
uint32_t u32GfLayerBlendBitmapPart(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                                   uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfLayerBlendBitmapPart
*
* Blends the given part of the bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstImgPart - Pointer to part of the image to be copied
* @param[in] u32PosX    - X-offset from the destination buffer start
* @param[in] u32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlendBitmapPart(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                             uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfLayerBlendBitmapRLE16
*
* Blits entire RLE16 bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlendBitmapRLE16(gf_image_st * pstImage, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlendBitmapRLE24
*
* Blends entire RLE24A bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlendBitmapRLE24(gf_image_st * pstImage, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlendBitmapRLE24A
*
* Blends entire RLE24A bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlendBitmapRLE24A(gf_image_st * pstImage, gf_layer_st * pstLayer,
                               int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerBlendBitmapRLE32
*
* Blits entire RLE32 bitmap into the given layer
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerBlendBitmapRLE32(gf_image_st * pstImage, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerRotateBitmapFull
*
* Rotates the entire bitmap into the given layer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstImage - Pointer to source image
* @param[in] f32Angle - Rotation angle
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerRotateBitmapFull(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerRotateBitmapPart
*
* Rotates part of a bitmap
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       
*
* @param[in] pstImage   - Pointer to source image
* @param[in] f32Angle   - Rotation angle
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstImgPart - Pointer to part of the source image to be rotated
* @param[in] i32PosX    - X-offset from the destination buffer start
* @param[in] i32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerRotateBitmapPart(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                              int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerRotateBitmapOptimized
*
* Rotates the entire bitmap cache optimized into the given
* destination layer
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       No subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstSrcImage    - Pointer to source image
* @param[in] f32Angle       - Rotation angle
* @param[in] pstLayer       - Pointer to destination layer
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockWidth  - Width of block
* @param[in] u32BlockHeight - Height of block
*
* @return void
*/
void vGfLayerRotateBitmapOptimized(gf_image_st * pstSrcImage, float32_t f32Angle, gf_layer_st * pstLayer,
                                   uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfLayerRotateBlendBitmapFull
*
* Rotates entire bitmap and blend it into the given layer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstImage - Pointer to source image
* @param[in] f32Angle - Rotation angle
* @param[in] pstLayer - Pointer to destination layer
* @param[in] i32PosX  - X-offset from the destination buffer start
* @param[in] i32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerRotateBlendBitmapFull(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer,
                                   int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerRotateBlendBitmapPart
*
* Rotates entire bitmap and blend it into the given layer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] f32Angle   - Rotation angle
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstImgPart - Part of the image to be copied
* @param[in] i32PosX    - X-offset from the destination buffer start
* @param[in] i32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerRotateBlendBitmapPart(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                                   int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerRotateNeedleFull
*
* Rotates the entire needle into the given layer
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible in x-direction. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstImage       - Pointer to source image of needle
* @param[in] f32Angle       - Rotation angle
* @param[in] pstLayer       - Pointer to destination layer
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockHeight - Height of block
*
* @return void
*/
void vGfLayerRotateNeedleFill(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer,
                              uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfLayerRotateNeedle
*
* Rotates optimized and blends the entire needle image into the given layer
* with restoring the background
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible in x-direction. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstImageBg     - Pointer to background source image
* @param[in] pstImage       - Pointer to source image of needle
* @param[in] f32Angle       - Rotation angle
* @param[in] pstLayer       - Pointer to destination layer
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockHeight - Height of block
*
* @return void
*/
void vGfLayerRotateNeedle(gf_image_st * pstImageBg, gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer,
                          uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfLayerRotateNeedleTipandBaseFill
*
* Rotates optimized and blends the entire needle image into the given layer
* with restoring the background by filling
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       No subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in]  pstSrcImage - Pointer to source image of needle
* @param[in]  f32Angle    - Rotation angle
* @param[in]  pstLayer    - Pointer to destination layer
* @param[in]  u32PosX     - X-offset from the destination buffer start
* @param[in]  u32PosY     - Y-offset from the destination buffer start
* @param[in]  pstDef      - Parameter for image
*
* @return void
*/
void vGfLayerRotateNeedleTipandBaseFill(gf_image_st * pstSrcImage, float32_t f32Angle, gf_layer_st * pstLayer,
                                        uint32_t u32PosX, uint32_t u32PosY, gf_def_st * pstDef);


/**
* @brief Implementation of function vGfLayerRotateNeedleTipandBase
*
* Rotates optimized and blends the entire needle image into the given layer
* with restoring the background
*
* @note No subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*       The complete output should be inside the destination image for all degrees.
*
* @param[in] pstSrcImageBg - Pointer to background source image
* @param[in] pstSrcImage   - Source image of needle
* @param[in] f32Angle      - Rotation angle
* @param[in] pstLayer      - Pointer to destination layer
* @param[in] u32PosX       - X-offset from the destination buffer start
* @param[in] u32PosY       - Y-offset from the destination buffer start
* @param[in] pstDef        - Pointer to parameter for image
*
* @return void
*/
void vGfLayerRotateNeedleTipandBase(gf_image_st * pstSrcImageBg, gf_image_st * pstSrcImage, float32_t f32Angle, gf_layer_st * pstLayer,
                                    uint32_t u32PosX, uint32_t u32PosY, gf_def_st * pstDef);


/**
* @brief Implementation of function vGfLayerShearFull
*
* Shears an image in x- and y-direction by the specified factors into the given layer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] f32FactorX - Shearing factor in x-direction
* @param[in] f32FactorY - Shearing factor in y-direction
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] i32PosX    - X-offset from the destination buffer start
* @param[in] i32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerShearFull(gf_image_st * pstImage, float32_t f32FactorX, float32_t f32FactorY, gf_layer_st * pstLayer,
                       int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerShearBlendFull
*
* Shears an image in x- and y-direction by the specified factors into the given layer with blending
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] f32FactorX - Shearing factor in x-direction
* @param[in] f32FactorY - Shearing factor in y-direction
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] i32PosX    - X-offset from the destination buffer start
* @param[in] i32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerShearBlendFull(gf_image_st * pstImage, float32_t f32FactorX, float32_t f32FactorY, gf_layer_st * pstLayer,
                            int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerScaleFull
*
* Scales an image in x- and y-direction by the specified factors into the given layer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] f32FactorX - Scaling factor in x-direction
* @param[in] f32FactorY - Scaling factor in y-direction
* @param[in] eAlignment - Alignment in source image
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] i32PosX    - X-offset from the destination buffer start
* @param[in] i32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerScaleFull(gf_image_st * pstImage, float32_t f32FactorX, float32_t f32FactorY,
                       rot_scaleAlign_e eAlignment, gf_layer_st * pstLayer,
                       int32_t i32PosX, int32_t i32PosY);


#ifdef GA_USE_MATH_LIB
/**
* @brief Implementation of function vGfLayerScaleBlendFull
*
* Scales an image in x- and y-direction by the specified factors into the given layer with blending
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstImage   - Pointer to source image
* @param[in] f32FactorX - Scaling factor in x-direction
* @param[in] f32FactorY - Scaling factor in y-direction
* @param[in] eAlignment - Alignment in source image
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] i32PosX    - X-offset from the destination buffer start
* @param[in] i32PosY    - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerScaleBlendFull(gf_image_st * pstImage, float32_t f32FactorX, float32_t f32FactorY,
                            rot_scaleAlign_e eAlignment, gf_layer_st * pstLayer,
                            int32_t i32PosX, int32_t i32PosY);


/**
* @brief Implementation of function vGfLayerPerspectiveBlitFull
*
* Puts an image into perspective by rotation on x-, y- and z-axis by the specified angle
* and blits it into the given layer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstImage     - Pointer to source image
* @param[in] f32AngleX    - Rotation angle x-axis
* @param[in] f32AngleY    - Rotation angle y-axis
* @param[in] f32AngleZ    - Rotation angle z-axis
* @param[in] f32FactorX   - Scaling factor X
* @param[in] f32FactorY   - Scaling factor Y
* @param[in] pstLayer     - Pointer to destination layer
* @param[in] i32PosX      - X-offset from the destination buffer start
* @param[in] i32PosY      - Y-offset from the destination buffer start
* @param[in] u32RotPointX - Rotation point X
* @param[in] u32RotPointY - Rotation point Y
*
* @return void
*/
void vGfLayerPerspectiveBlitFull(gf_image_st * pstImage, float32_t f32AngleX, float32_t f32AngleY, float32_t f32AngleZ,
                                 float32_t f32FactorX, float32_t f32FactorY, gf_layer_st * pstLayer,
                                 int32_t i32PosX, int32_t i32PosY,
                                 uint32_t u32RotPointX, uint32_t u32RotPointY);
#endif


/**
* @brief Implementation of function vGfLayerPerspectiveBlendFull
*
* Puts an image into perspective by rotation on x-, y- and z-axis by the specified angle
* and blends it into the given layer
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel rotation point positioning possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstImage     - Pointer to source image
* @param[in] f32AngleX    - Rotation angle x-axis
* @param[in] f32AngleY    - Rotation angle y-axis
* @param[in] f32AngleZ    - Rotation angle z-axis
* @param[in] f32FactorX   - Scaling factor X
* @param[in] f32FactorY   - Scaling factor Y
* @param[in] pstLayer     - Pointer to destination layer
* @param[in] i32PosX      - X-offset from the destination buffer start
* @param[in] i32PosY      - Y-offset from the destination buffer start
* @param[in] u32RotPointX - Rotation point X
* @param[in] u32RotPointY - Rotation point Y
*
* @return void
*/
void vGfLayerPerspectiveBlendFull(gf_image_st * pstImage, float32_t f32AngleX, float32_t f32AngleY, float32_t f32AngleZ,
                                  float32_t f32FactorX, float32_t f32FactorY, gf_layer_st * pstLayer,
                                  int32_t i32PosX, int32_t i32PosY,
                                  uint32_t u32RotPointX, uint32_t u32RotPointY);


/**
* @brief Implementation of function vGfLayerTransformationFull
*
* Transforms an image with the transformation table
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage  - Pointer to source image
* @param[in] pstLayer  - Pointer to destination layer
* @param[in] pstTable  - Pointer to transformation table
* @param[in] u32PosX   - X-offset from the destination buffer start
* @param[in] u32PosY   - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerTransformationFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                                gf_table_st * pstTable, uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfLayerTransformationFullOptimized
*
* Transforms an image with the transformation table cache optimized
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage       - Pointer to source image
* @param[in] pstLayer       - Pointer to destination layer
* @param[in] pstTable       - Pointer to transformation table
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockWidth  - Block width
* @param[in] u32BlockHeight - Block height
*
* @return void
*/
void vGfLayerTransformationFullOptimized(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_table_st * pstTable,
                                         uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfLayerTransformationBlendFull
*
* Transforms an image with the transformation table with blend
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage - Pointer to source image
* @param[in] pstLayer - Pointer to destination layer
* @param[in] pstTable - Pointer to transformation table
* @param[in] u32PosX  - X-offset from the destination buffer start
* @param[in] u32PosY  - Y-offset from the destination buffer start
*
* @return void
*/
void vGfLayerTransformationBlendFull(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_table_st * pstTable,
                                     uint32_t u32PosX, uint32_t u32PosY);


/**
* @brief Implementation of function vGfLayerTransformationBlendFullOptimized
*
* Transforms an image with the transformation table cache optimized with blend
*
* @note No subpixel positioning possible.
*
* @param[in] pstImage       - Pointer to source image
* @param[in] pstLayer       - Pointer to destination layer
* @param[in] pstTable       - Pointer to transformation table
* @param[in] u32PosX        - X-offset from the destination buffer start
* @param[in] u32PosY        - Y-offset from the destination buffer start
* @param[in] u32BlockWidth  - Block width
* @param[in] u32BlockHeight - Block height
*
* @return void
*/
void vGfLayerTransformationBlendFullOptimized(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_table_st * pstTable,
                                              uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight);


/**
* @brief Implementation of function vGfLayerDrawLine
*
* Draw a line
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*       Subpixel linewidth possible. Parameter (eResCPos of function vGfSetSubRes) has to be set accordingly.
*
* @param[in] pstLayer  - Pointer to destination layer
* @param[in] pstOption - Pointer to option for draw operation
* @param[in] pstLine   - Pointer to line properties for draw operation
*
* @return void
*/
void vGfLayerDrawLine(gf_layer_st * pstLayer, drw_OpCfg_st *pstOption, drw_Line_st *pstLine);


/**
* @brief Implementation of function vGfLayerDrawTriangle
*
* Draw triangle
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstLayer  - Pointer to destination layer
* @param[in] pstOption - Pointer to option for draw operation
* @param[in] pstTrngl  - Pointer to triangle properties for draw operation
*
* @return void
*/
void vGfLayerDrawTriangle(gf_layer_st * pstLayer, drw_OpCfg_st *pstOption, drw_Trngl_st *pstTrngl);


/**
* @brief Implementation of function vGfLayerDrawCircle
*
* Draw circle
*
* @note Subpixel positioning possible. Center Coordinates have to be set accordingly(only using eResPPos parameter of function vGfSetSubRes).
*       (Do not set eResCPos parameter of function vGfSetSubRes for Subpixel positioning of center coordinates)     
*       
* @param[in] pstLayer  - Pointer to destination layer
* @param[in] pstOption - Pointer to option for draw operation
* @param[in] pstCircle - pointer to circle properties for draw operation
*                        like center co-ordinates, radius, draw colour and AA effect
*
* Limitation : The center and radius of the circle should be given such that the circle lies completely in the positive quadrant.
*
* @return void
*/
void vGfLayerDrawCircle(gf_layer_st *pstLayer, drw_OpCfg_st *pstOption, gf_circle_st *pstCircle);


/**
* @brief Implementation of function vGfLayerDrawPolygon
*
* Draw polygon
*
* @note Subpixel positioning possible. Coordinates parameter have to be set accordingly(using eResPPos parameter of function vGfSetSubRes).
*
* @param[in] pstLayer   - Pointer to destination layer
* @param[in] pstOption  - Pointer to option for draw operation
* @param[in] pstPolygon - Pointer to the vertices of the polygon, Number of vertices, draw colour and AA effects
*
* Limitation : The vertices should be given either in clockwise or anticlockwise direction only. The API will support only convex polygons.
*
* @return void
*/
void vGfLayerDrawPolygon(gf_layer_st *pstLayer, drw_OpCfg_st *pstOption, gf_polygon_st *pstPolygon);


/**
* @brief Implementation of function vGfLayerBlitElement
*
* Set image configured in OpenGL style
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstLayer    - Pointer to destination layer
*
* @return void
*/
void vGfLayerBlitElement(gf_image_st * pstSrcImage, gf_layer_st * pstLayer);


/**
* @brief Implementation of function vGfLayerBlendElement
*
* Set image configured in OpenGL style with blending
*
* @note Subpixel positioning possible. Coordinates and position parameter (eResPPos of function vGfSetSubRes) have to be set accordingly.
*
* @param[in] pstSrcImage - Pointer to source image
* @param[in] pstLayer    - Pointer to destination layer
*
* @return void
*/
void vGfLayerBlendElement(gf_image_st * pstSrcImage, gf_layer_st * pstLayer);


/***************************************************************************/

#endif /* GFUNCTIONS_H */

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
