/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Some helper functions for ratation, scaling, shearing, 
*                 perspective operation.
*                 Reference Low-Level Driver (Rotation Engine)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphic Accelerator Rotation Engine
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/07/21 12:38:46 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef ROTATION_LIB_H
#define ROTATION_LIB_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "gf.h"
#include "rotation_matrix.h"

#ifdef GA_USE_MATH_LIB
#include "math.h"
#else
#include "sin_cos.h"
#endif /* GA_USE_MATH_LIB */

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_GA_ROTATE_LIB_H_REVISION     "$Revision: 1.10 $"
#define LLDD_GA_ROTATE_LIB_H_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/


/**********************************************
*       TRIGONOMETRY FUNCTION HOOKS           *
**********************************************/

#ifdef GA_USE_MATH_LIB
#ifdef __KEIL__
#define ROT_SIN(angle)((RE_FLOAT64ROUND((sin(angle))*4294967296.0)/4294967296))
#define ROT_COS(angle)((RE_FLOAT64ROUND((cos(angle))*4294967296.0)/4294967296))
#else
/* Standard implementation */
#define ROT_SIN(angle)(sin((angle)))
#define ROT_COS(angle)(cos((angle)))
#endif
#else

/* Custom Implementation */
/* Use Sin/Cos lookup table implementation */
#define ROT_SIN(angle)(i32SinLookup((angle)))
#define ROT_COS(angle)(i32CosLookup((angle)))

#endif /* GA_USE_MATH_LIB */

/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/

/**
* @brief Alignment for scale in source image
*/
typedef enum tag_rot_scaleAlign_e
{
    ROT_SCALE_ALIGN_00 = 0,  /*!< alignment to (0,0) */
    ROT_SCALE_ALIGN_W0 = 1,  /*!< alignment to (width,0) */
    ROT_SCALE_ALIGN_0H = 2,  /*!< alignment to (0,height) */
    ROT_SCALE_ALIGN_WH = 3,  /*!< alignment to (width/height) */
    ROT_SCALE_ALIGN_CC = 4   /*!< alignment to (center, center) */
} rot_scaleAlign_e;

/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/
/**
* @brief rotation configuration
*/
typedef struct tag_rot_cfg_st
{
    rot_rotCfg_st  stRotCfg;         /* Rotation configuration */
    int16_t        i16RotCentX;      /* Source Rotation Center X-Coord */
    int16_t        i16RotCentY;      /* Source Rotation Center Y-Coord */
    int16_t        i16OffsetX;       /* Dest. Offset */
    int16_t        i16OffsetY;       /* Dest. Offset */
} rot_cfg_st;


/**
* @brief rotation blend configuration
*/
typedef struct tag_rot_blendcfg_st
{
    rot_rotblendCfg_st  stRotBlendCfg;    /* Rotation blend configuration */
    int16_t             i16RotCentX;      /* Source Rotation Center X-Coord */
    int16_t             i16RotCentY;      /* Source Rotation Center Y-Coord */
    int16_t             i16OffsetX;       /* Dest. Offset */
    int16_t             i16OffsetY;       /* Dest. Offset */
} rot_blendcfg_st;


/**
* @brief Shear/Scale configuration
*/
typedef struct tag_rot_sscalCfg_st
{
    ga_colFmt_e      eSrcColFmt;    /*!< Source Color Format Selection */
    ga_colFmt_e      eDstColFmt;    /*!< Destination Color Format Selection */
    ga_en_e          eClipWndEn;    /*!< Clipping Window Enable */
    ga_en_e          eFilterEn;     /*!< Enable Filtering */
    int16_t          i16OffsetX;    /*!< Dest. Offset X-Coord */
    int16_t          i16OffsetY;    /*!< Dest. Offset Y-Coord */
#ifdef GA_USE_MATH_LIB
    float64_t        f64FactorX;    /*!< Shear/Scale Factor X */
    float64_t        f64FactorY;    /*!< Shear/Scale Factor Y */
#else
    int32_t          i32FactorX;    /*!< Shear/Scale Factor X */
    int32_t          i32FactorY;    /*!< Shear/Scale Factor Y */
#endif
    rot_scaleAlign_e eAlignment;    /*!< alignment in source image */
    uint8_t          u8FadingFctr;  /*!< Fading factor */
    uint8_t          u8SrcAlphaVal; /*!< Source Alpha value */
    uint8_t          u8DstAlphaVal; /*!< Destination Alpha value */

    /* Optional */
    rot_clipWnd_st tClipWnd;
} rot_sscalCfg_st;


/**
* @brief Shear/Scale configuration with blending
*/
typedef struct tag_rot_sscalblendCfg_st
{
    ga_colFmt_e      eSrcColFmt;    /*!< Source Color Format Selection */
    ga_colFmt_e      eDstColFmt;    /*!< Destination Color Format Selection */
    ga_en_e          eClipWndEn;    /*!< Clipping Window Enable */
    ga_en_e          eFilterEn;     /*!< Enable Filtering */
    int16_t          i16OffsetX;    /*!< Dest. Offset X-Coord */
    int16_t          i16OffsetY;    /*!< Dest. Offset Y-Coord */
#ifdef GA_USE_MATH_LIB
    float64_t        f64FactorX;    /*!< Shear/Scale Factor X */
    float64_t        f64FactorY;    /*!< Shear/Scale Factor Y */
#else
    int32_t          i32FactorX;    /*!< Shear/Scale Factor X */
    int32_t          i32FactorY;    /*!< Shear/Scale Factor Y */
#endif
    rot_scaleAlign_e eAlignment;    /*!< alignment in source image */
    ga_en_e          eDstRedProt;   /*!< Destination red color protection */
    ga_en_e          eDstGreenProt; /*!< Destination green color protection */
    ga_en_e          eDstBlueProt;  /*!< Destination blue color protection */
    ga_en_e          eDstAlphaProt; /*!< Destination alpha protection */
    ga_en_e          eSrcRedFad;    /*!< Destination red color protection */
    ga_en_e          eSrcGreenFad;  /*!< Destination green color protection */
    ga_en_e          eSrcBlueFad;   /*!< Destination blue color protection */
    ga_en_e          eSrcAlphaFad;  /*!< Destination alpha protection */
    uint8_t          u8FadingFctr;  /*!< Fading factor */
    ga_blendOrd_e    eBldOrd;       /*!< Blend order */
    uint8_t          u8SrcAlphaVal; /*!< Source Alpha value */
    uint8_t          u8DstAlphaVal; /*!< Destination Alpha value */

    /* Optional */
    rot_clipWnd_st tClipWnd;
} rot_sscalblendCfg_st;


/**
* @brief Perspective configuration
*/
typedef struct tag_rot_perspectiveCfg_st
{
    ga_colFmt_e    eSrcColFmt;      /*!< Source Color Format Selection */
    ga_colFmt_e    eDstColFmt;      /*!< Destination Color Format Selection */
    ga_en_e        eClipWndEn;      /*!< Clipping Window Enable */
    ga_en_e        eFilterEn;       /*!< Enable Filtering */
    int16_t        i16OffsetX;      /*!< Dest. Offset X-Coord */
    int16_t        i16OffsetY;      /*!< Dest. Offset Y-Coord */
    uint32_t       u32RotPointX;    /*!< Rotation point X */
    uint32_t       u32RotPointY;    /*!< Rotation point Y */
#ifdef GA_USE_MATH_LIB
    float64_t      f64AngleX;       /*!< Perspective Angle X */
    float64_t      f64AngleY;       /*!< Perspective Angle Y */
    float64_t      f64AngleZ;       /*!< Perspective Angle Z */
    float64_t      f64ScaleX;       /*!< Scale Factor X */
    float64_t      f64ScaleY;       /*!< Scale Factor Y */
#else
    int32_t        i32AngleX;       /*!< Perspective Angle X */
    int32_t        i32AngleY;       /*!< Perspective Angle Y */
    int32_t        i32AngleZ;       /*!< Perspective Angle Z */
    int32_t        i32ScaleX;       /*!< Scale Factor X */
    int32_t        i32ScaleY;       /*!< Scale Factor Y */
#endif
    uint8_t        u8FadingFctr;    /*!< Fading factor */
    uint8_t        u8SrcAlphaVal;   /*!< Source Alpha value */
    uint8_t        u8DstAlphaVal;   /*!< Destination Alpha value */

    /* Optional */
    rot_clipWnd_st tClipWnd;
} rot_perspectiveCfg_st;


/**
* @brief Perspective configuration with blending
*/
typedef struct tag_rot_perspectiveblendCfg_st
{
    ga_colFmt_e    eSrcColFmt;      /*!< Source Color Format Selection */
    ga_colFmt_e    eDstColFmt;      /*!< Destination Color Format Selection */
    ga_en_e        eClipWndEn;      /*!< Clipping Window Enable */
    ga_en_e        eFilterEn;       /*!< Enable Filtering */
    int16_t        i16OffsetX;      /*!< Dest. Offset X-Coord */
    int16_t        i16OffsetY;      /*!< Dest. Offset Y-Coord */
    uint32_t       u32RotPointX;    /*!< Rotation point X */
    uint32_t       u32RotPointY;    /*!< Rotation point Y */
#ifdef GA_USE_MATH_LIB
    float64_t      f64AngleX;       /*!< Perspective Angle X */
    float64_t      f64AngleY;       /*!< Perspective Angle Y */
    float64_t      f64AngleZ;       /*!< Perspective Angle Z */
    float64_t      f64Scale;        /*!< Scale Factor */
    float64_t      f64ScaleX;       /*!< Scale Factor X */
    float64_t      f64ScaleY;       /*!< Scale Factor Y */
#else
    int32_t        i32AngleX;       /*!< Perspective Angle X */
    int32_t        i32AngleY;       /*!< Perspective Angle Y */
    int32_t        i32AngleZ;       /*!< Perspective Angle Z */
    int32_t        i32ScaleX;       /*!< Scale Factor X */
    int32_t        i32ScaleY;       /*!< Scale Factor Y */
#endif
    ga_en_e        eDstRedProt;     /*!< Destination red color protection */
    ga_en_e        eDstGreenProt;   /*!< Destination green color protection */
    ga_en_e        eDstBlueProt;    /*!< Destination blue color protection */
    ga_en_e        eDstAlphaProt;   /*!< Destination alpha protection */
    ga_en_e        eSrcRedFad;      /*!< Destination red color protection */
    ga_en_e        eSrcGreenFad;    /*!< Destination green color protection */
    ga_en_e        eSrcBlueFad;     /*!< Destination blue color protection */
    ga_en_e        eSrcAlphaFad;    /*!< Destination alpha protection */
    uint8_t        u8FadingFctr;    /*!< Fading factor */
    ga_blendOrd_e  eBldOrd;         /*!< Blend order */
    uint8_t        u8SrcAlphaVal;   /*!< Source Alpha value */
    uint8_t        u8DstAlphaVal;   /*!< Destination Alpha value */

    /* Optional */
    rot_clipWnd_st tClipWnd;
} rot_perspectiveblendCfg_st;


/**
* @brief Rotation of part of image
*/
typedef struct tag_rot_mem_part_st
{
    /* Source Mem. Params */
    uint16_t      u16SrcHeight;      /*!< Source Memory Height (Line Number) */
    uint16_t      u16SrcWidth;       /*!< Source Memory Width (Dots Per Line) */
    uint32_t      u32SrcAddr;        /*!< Source Memory Addr. First Src. Dot
                                       (Each function specifies its own
                                        memory alignment rules) */
    uint16_t      u16DotCnt;         /*!< Dot Number per line to be blitted */

    /* Destination Mem. Params */
    uint32_t      u32DstAddr;        /*!< Dest. Memory Addr. First Src. Dot
                                       (Each function specifies its own
                                        memory alignment rules) */
    /* Dest. Image Area Size */
    uint16_t      u16DstImgWidth;    /*!< Destination Image Width */
    uint16_t      u16DstImgHeight;   /*!< Destination Image Height */
} rot_mem_part_st;


/**
* @brief Matrix parameter
*/
typedef struct tag_GA_MATRIX_t
{
    double sx;       /*!< Parameter sx */
    double shx;      /*!< Parameter shx */
    double tx;       /*!< Parameter tx */
    double shy;      /*!< Parameter shy */
    double sy;       /*!< Parameter sy */
    double ty;       /*!< Parameter ty */
    double w0;       /*!< Parameter w0 */
    double w1;       /*!< Parameter w1 */
    double w2;       /*!< Parameter w2 */
} GA_MATRIX_t;


/**
* @brief Coordinate point
*/
typedef struct tag_GA_COORD_t
{
    double x;       /*!< Coordinate x */
    double y;       /*!< Coordinate y */
    double z;       /*!< Coordinate z */
} GA_COORD_t;


/**
* @brief Screenobject
*/
typedef struct tag_GA_SCREENOBJ_t
{
    GA_COORD_t p1;       /*!< Point p1 */
    GA_COORD_t p2;       /*!< Point p2 */
    GA_COORD_t p3;       /*!< Point p3 */
    GA_COORD_t p4;       /*!< Point p4 */
    GA_COORD_t c;        /*!< Point c */
} GA_SCREENOBJ_t;

/*********************************************/


/**********************************************
*            Function prototypes              *
**********************************************/

/**
* @brief Implementation of round off function for KEIL
*
* @note none
*
* @param[in] f64Value - The floating point value to be rounded off
*
* @return The rounded off value
*/
#if defined (__KEIL__)
float64_t round(float64_t f64Value);
#endif


/**
* @brief Implementation of function vRotLib_GetVersion
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
void vRotLib_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                        uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);


#ifdef GA_USE_MATH_LIB
/**
* @brief Implementation of function vRotLib_CalculateTransformationMatrix_Rotate
*
* Calculates rotation matrix on hand of angle
*
* @note none
*
* @param[in] pstMatrix - Pointer to rotation matrix
* @param[in] f64Angle  - angle in degree 
*
* @return void
*/
void vRotLib_CalculateTransformationMatrix_Rotate(rot_Mtrx_st* pstMatrix, float64_t f64Angle);
#else
/**
* @brief Implementation of function vRotLib_CalculateTransformationMatrix_Rotate
*
* Calculates rotation matrix on hand of angle
*
* @note none
*
* @param[in] pstMatrix - Pointer to rotation matrix
* @param[in] i16Angle  - angle in degree 
*
* @return void
*/
void vRotLib_CalculateTransformationMatrix_Rotate(rot_Mtrx_st* pstMatrix, int16_t i16Angle);
#endif


#ifdef GA_USE_MATH_LIB
/**
* @brief Implementation of function vRotLib_CalculateTransformationMatrix_Shear
*
* Calculates rotation matrix for shear operation
*
* @note none
*
* @param[in] pstMatrix  - Pointer to rotation matrix
* @param[in] f64FactorX - Factor X for Shear 
* @param[in] f64FactorY - Factor Y for Shear 
*
* @return void
*/
void vRotLib_CalculateTransformationMatrix_Shear(rot_Mtrx_st* pstMatrix, float64_t f64FactorX, float64_t f64FactorY);
#else
/**
* @brief Implementation of function vRotLib_CalculateTransformationMatrix_Shear
*
* Calculates rotation matrix for shear operation
*
* @note none
*
* @param[in] pstMatrix  - Pointer to rotation matrix
* @param[in] i32FactorX - Factor X for Shear 
* @param[in] i32FactorY - Factor Y for Shear 
*
* @return void
*/
void vRotLib_CalculateTransformationMatrix_Shear(rot_Mtrx_st* pstMatrix, int32_t i32FactorX, int32_t i32FactorY);
#endif


#ifdef GA_USE_MATH_LIB
/**
* @brief Implementation of function vRotLib_CalculateTransformationMatrix_Scale
*
* Calculates rotation matrix for scale operation
*
* @note none
*
* @param[in] pstMatrix  - Pointer to rotation matrix
* @param[in] f64FactorX - Factor X for scaling 
* @param[in] f64FactorY - Factor Y for scaling 
*
* @return void
*/
void vRotLib_CalculateTransformationMatrix_Scale(rot_Mtrx_st* pstMatrix, float64_t f64FactorX, float64_t f64FactorY);
#else
/**
* @brief Implementation of function vRotLib_CalculateTransformationMatrix_Scale
*
* Calculates rotation matrix for scale operation
*
* @note none
*
* @param[in] pstMatrix  - Pointer to rotation matrix
* @param[in] i32FactorX - Factor X for scaling 
* @param[in] i32FactorY - Factor Y for scaling 
*
* @return void
*/
void vRotLib_CalculateTransformationMatrix_Scale(rot_Mtrx_st* pstMatrix, int32_t i32FactorX, int32_t i32FactorY);
#endif


#ifdef GA_USE_MATH_LIB 
/**
* @brief Implementation of function vRotLib_Rotate
*
* Inserts all required parameters for source object rotation
*
* @note Please note that this function will perform rotation angle
*       conversion from degrees to radians.
*
* @param[in] pstMem   - Pointer to memory configuration parameters
* @param[in] pstParam - Pointer to rotation Parameters
*                       (for more details see struct. desc.)
* @param[in] f64Angle - Rotation angle (degrees)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_Rotate(rot_mem_st* pstMem, rot_cfg_st* pstParam, float64_t f64Angle,
                    ga_list_st* pstCmdList);
#else
/**
* @brief Implementation of function vRotLib_Rotate
*
* Inserts all required parameters for source object rotation
*
* @note Please note that this function will perform rotation angle
*       conversion from degrees to radians.
*
* @param[in] pstMem   - Pointer to memory configuration parameters
* @param[in] pstParam - Pointer to rotation Parameters
*                       (for more details see struct. desc.)
* @param[in] i16Angle - 10times integer rotation angle
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_Rotate(rot_mem_st* pstMem, rot_cfg_st* pstParam, int16_t   i16Angle,
                    ga_list_st* pstCmdList);
#endif


#ifdef GA_USE_MATH_LIB 
/**
* @brief Implementation of function vRotLib_Rotate_Part
*
* Inserts all required parameters for part source object rotation
*
* @note Please note that this function will perform rotation angle
*       conversion from degrees to radians.
*
* @param[in] pstMem   - Pointer to memory configuration parameters
* @param[in] pstParam - Pointer to rotation Parameters
*                       (for more details see struct. desc.)
* @param[in] f64Angle - Rotation angle (degrees)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_Rotate_Part(rot_mem_part_st* pstMem, rot_cfg_st* pstParam, float64_t f64Angle,
                         ga_list_st* pstCmdList);
#else
/**
* @brief Implementation of function vRotLib_Rotate_Part
*
* Inserts all required parameters for part source object rotation
*
* @note Please note that this function will perform rotation angle
*       conversion from degrees to radians.
*
* @param[in] pstMem   - Pointer to memory configuration parameters
* @param[in] pstParam - Pointer to rotation Parameters
*                       (for more details see struct. desc.)
* @param[in] i16Angle - 10times integer rotation angle
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_Rotate_Part(rot_mem_part_st* pstMem, rot_cfg_st* pstParam, int16_t   i16Angle,
                         ga_list_st* pstCmdList);
#endif


#ifdef GA_USE_MATH_LIB 
/**
* @brief Implementation of function vRotLib_RotateBlend
*
* Inserts all required parameters for source object rotation
*
* @note Please note that this function will perform rotation angle
*       conversion from degrees to radians.
*
* @param[in] pstMem   - Pointer to memory configuration parameters
* @param[in] pstParam - Pointer to rotation Parameters
*                       (for more details see struct. desc.)
* @param[in] f64Angle - Rotation angle (degrees)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_RotateBlend(rot_mem_st* pstMem, rot_blendcfg_st* pstParam, float64_t f64Angle,
                         ga_list_st* pstCmdList);
#else
/**
* @brief Implementation of function vRotLib_RotateBlend
*
* Inserts all required parameters for source object rotation
*
* @note Please note that this function will perform rotation angle
*       conversion from degrees to radians.
*
* @param[in] pstMem   - Pointer to memory configuration parameters
* @param[in] pstParam - Pointer to rotation Parameters
*                       (for more details see struct. desc.)
* @param[in] i16Angle - 10times integer rotation angle
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_RotateBlend(rot_mem_st* pstMem, rot_blendcfg_st* pstParam, int16_t   i16Angle,
                         ga_list_st* pstCmdList);
#endif


#ifdef GA_USE_MATH_LIB
/**
* @brief Implementation of function vRotLib_RotateBlend_Part
*
* Inserts all required parameters for part source object rotation
*
* @note Please note that this function will perform rotation angle
*       conversion from degrees to radians.
*
* @param[in] pstMem   - Pointer to memory configuration parameters
* @param[in] pstParam - Pointer to rotation Parameters
*                       (for more details see struct. desc.)
* @param[in] f64Angle - Rotation angle (degrees)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_RotateBlend_Part(rot_mem_part_st* pstMem, rot_blendcfg_st* pstParam, float64_t f64Angle,
                              ga_list_st* pstCmdList);
#else
/**
* @brief Implementation of function vRotLib_RotateBlend_Part
*
* Inserts all required parameters for part source object rotation
*
* @note Please note that this function will perform rotation angle
*       conversion from degrees to radians.
*
* @param[in] pstMem   - Pointer to memory configuration parameters
* @param[in] pstParam - Pointer to rotation Parameters
*                       (for more details see struct. desc.)
* @param[in] i16Angle - 10times integer rotation angle
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_RotateBlend_Part(rot_mem_part_st* pstMem, rot_blendcfg_st* pstParam, int16_t   i16Angle,
                              ga_list_st* pstCmdList);
#endif


#ifdef GA_USE_MATH_LIB 
/**
* @brief Implementation of function vRotLib_Shear
*
* Inserts all required parameters for source object shearing operation
*
* @note none
*
* @param[in] pstMem     - Memory configuration parameters
* @param[in] pstParam   - Shearing Parameters
*                         (for more details see struct. desc.)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_Shear(rot_mem_st* pstMem, rot_sscalCfg_st* pstParam,
                   ga_list_st* pstCmdList);


/**
* @brief Implementation of function vRotLib_ShearBlend
*
* Inserts all required parameters for source object shearing operation
*
* @note none
*
* @param[in] pstMem     - Pointer to memory configuration parameters
* @param[in] pstParam   - Pointer to shearing Parameters
*                         (for more details see struct. desc.)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_ShearBlend(rot_mem_st* pstMem, rot_sscalblendCfg_st* pstParam,
                        ga_list_st* pstCmdList);

#endif /* GA_USE_MATH_LIB */


/**
* @brief Implementation of function vRotLib_Scale
*
* Inserts all required parameters for source object scaling operation
*
* @note none
*
* @param[in] pstMem     - Pointer to memory configuration parameters
* @param[in] pstParam   - Pointer to scaling parameters
*                         (for more details see struct. desc.)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_Scale(rot_mem_st* pstMem, rot_sscalCfg_st* pstParam,
                   ga_list_st* pstCmdList);


/**
* @brief Implementation of function vRotLib_ScaleBlend
*
* Inserts all required parameters for source object scaling operation
*
* @note none
*
* @param[in] pstMem     - Pointer to memory configuration parameters
* @param[in] pstParam   - Pointer to scaling parameters
*                         (for more details see struct. desc.)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_ScaleBlend(rot_mem_st* pstMem, rot_sscalblendCfg_st* pstParam,
                        ga_list_st* pstCmdList);


#ifdef GA_USE_MATH_LIB
/**
* @brief Implementation of function vRotLib_Perspective
*
* Inserts all required parameters for source object perspective operation
*
* @note none
*
* @param[in] pstMem     - Pointer to memory configuration parameters
* @param[in] pstParam   - Pointer to perspective parameters
*                         (for more details see struct. desc.)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_Perspective(rot_mem_st* pstMem, rot_perspectiveCfg_st* pstParam,
                         ga_list_st* pstCmdList);


/**
* @brief Implementation of function vRotLib_PerspectiveBlend
*
* Inserts all required parameters for source object perspective operation
*
* @note none
*
* @param[in] pstMem     - Pointer to memory configuration parameters
* @param[in] pstParam   - Pointer to perspective parameters
*                         (for more details see struct. desc.)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_PerspectiveBlend(rot_mem_st* pstMem, rot_perspectiveblendCfg_st* pstParam,
                              ga_list_st* pstCmdList);


/**
* @brief Implementation of function vRotLib_PerspectiveOGL
*
* Inserts all required parameters for source object perspective operation in OpenGL style
*
* @note none
*
* @param[in] pstMem     - Pointer to memory configuration parameters
* @param[in] pstParam   - Pointer to perspective parameters
*                         (for more details see struct. desc.)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_PerspectiveOGL(rot_mem_st * pstMem, rot_perspectiveCfg_st * pstParam, ga_list_st * pstCmdList);


/**
* @brief Implementation of function vRotLib_PerspectiveOGL
*
* Inserts all required parameters for source object perspective operation in OpenGL style
*
* @note none
*
* @param[in] pstMem     - Pointer to memory configuration parameters
* @param[in] pstParam   - Pointer to perspective parameters
*                         (for more details see struct. desc.)
*
* @param[in,out] pstCmdList - Pointer to the Command List
*
* @return void
*/
void vRotLib_PerspectiveBlendOGL(rot_mem_st * pstMem, rot_perspectiveblendCfg_st * pstParam, ga_list_st * pstCmdList);

#endif


/****************************************************************************/


#endif /* ROTATION_LIB_H */

/****************************************************************************/


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
