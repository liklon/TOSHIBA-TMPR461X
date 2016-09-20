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
*   VERSION     : $Revision: 1.14 $
*   DATE        : $Date: 2015/07/21 12:43:33 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "rotation.h"
#include "gf.h"
/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_GA_ROTATE_LIB_C_REVISION     "$Revision: 1.14 $"
#define LLDD_GA_ROTATE_LIB_C_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/

#define WxR_VALUE_ONE  (0x10000U)  /* WxR register set to 1 (shifted by 16 bits)*/
#define RE_MIN(a, b) ((a) < (b) ? (a) : (b))

/*********************************************/


/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 
static uint8_t au8LLDD_GA_ROTATE_LIB_C_REVISION[] = LLDD_GA_ROTATE_LIB_C_REVISION;
static uint8_t au8LLDD_GA_ROTATE_LIB_C_TAG[]      = LLDD_GA_ROTATE_LIB_C_TAG;
static uint8_t au8LLDD_GA_ROTATE_LIB_H_REVISION[] = LLDD_GA_ROTATE_LIB_H_REVISION;
static uint8_t au8LLDD_GA_ROTATE_LIB_H_TAG[]      = LLDD_GA_ROTATE_LIB_H_TAG;

/*********************************************/


/**********************************************
*              Global variables               *
**********************************************/
uint32_t  au32Coordinate[4][2];

float32_t f32SubResPPos = 16.0;
uint32_t  u32SubResPPos = 16U;
float32_t f32SubResCPos = 16.0;
uint32_t  u32SubResCPos = 16U;

/*********************************************/

float64_t obj[4][4];

/*********************************************/


/**********************************************
*             Function prototypes             *
**********************************************/
static ga_en_e vRotLib_CalculateCorrectClipWindow(rot_clipWnd_st* stClipWnd, ga_en_e eClipWndEn, rot_mem_st * pstMem, int* offset);
static void vSaveGlFwRotCornerCoord(rot_frccr_st *stCoord);
static GA_COORD_t RE_DEG2RAD(GA_COORD_t c);
static GA_MATRIX_t RE_ROTMATRIX (GA_COORD_t rot);
static GA_SCREENOBJ_t RE_CREATESCREENOBJECT(uint32_t u32Width, uint32_t u32Height, float64_t f64RotPoint_x, float64_t f64RotPoint_y);
static GA_COORD_t RE_VECTORMATRIXMULT (GA_COORD_t A, GA_MATRIX_t B);
static float64_t RE_MAX2(float64_t f64X, float64_t f64Y);
static GA_SCREENOBJ_t RE_3DTO2D(GA_SCREENOBJ_t S, float64_t f64Depth_shift);
static GA_COORD_t RE_MINSCREENOBJECTTYPE(GA_SCREENOBJ_t s);
static GA_SCREENOBJ_t RE_TRANSLATESCREENOBJECT(GA_SCREENOBJ_t a, GA_COORD_t b);
static GA_SCREENOBJ_t RE_SCALESCREENOBJECT_X(GA_SCREENOBJ_t S, float64_t f64Scale);
static GA_SCREENOBJ_t RE_SCALESCREENOBJECT_Y(GA_SCREENOBJ_t S, float64_t f64Scale);
static GA_SCREENOBJ_t RE_FORWARDROT(GA_COORD_t rot, float64_t f64Scale, uint32_t u32Width, uint32_t u32Height, float64_t f64RotPoint_x, float64_t f64RotPoint_y);
static int RE_SORTCORNERS (GA_SCREENOBJ_t* CC);
static GA_MATRIX_t RE_SCALEMATRIX(GA_MATRIX_t M, float64_t f64Scale);
static float64_t RE_DOUBLEABS(float64_t f64X);
static float64_t RE_MAXMATRIXELEMENT(GA_MATRIX_t M);
static GA_MATRIX_t RE_BACKWARDMATRIX(GA_SCREENOBJ_t FRCC, uint32_t u32Width, uint32_t u32Height);
static float64_t RE_FLOAT64ROUND(float64_t x);
static float64_t RE_FLOAT64TRUNC(float64_t x);
static void RE_TRANSLATEOBJECT(int32_t * offset, GA_SCREENOBJ_t * FRCC, float64_t * original);
static uint32_t RE_FLOAT64TOUINT32(float64_t x);
#ifdef GA_USE_MATH_LIB
static void vRotLib_CalculateForwardRotatedCornerCoordinates_RotateFull(rot_mem_st* pstMem, 
                                                                 int16_t i16RotCentX, int16_t i16RotCentY, 
                                                                 int16_t i16OffsetX, int16_t i16OffsetY, 
                                                                 rot_frccr_st* pstCoord, float64_t f64Angle);
#else
static void vRotLib_CalculateForwardRotatedCornerCoordinates_RotateFull(rot_mem_st* pstMem, 
                                                                 int16_t i16RotCentX, int16_t i16RotCentY, 
                                                                 int16_t i16OffsetX, int16_t i16OffsetY, 
                                                                 rot_frccr_st* pstCoord, int16_t i16Angle);
#endif
#ifdef GA_USE_MATH_LIB
static void vRotLib_CalculateForwardRotatedCornerCoordinates_RotatePart(rot_mem_part_st* pstMem, 
                                                                 int16_t i16RotCentX, int16_t i16RotCentY, 
                                                                 int16_t i16OffsetX, int16_t i16OffsetY, 
                                                                 rot_frccr_st* pstCoord, float64_t f64Angle);
#else
static void vRotLib_CalculateForwardRotatedCornerCoordinates_RotatePart(rot_mem_part_st* pstMem, 
                                                                 int16_t i16RotCentX, int16_t i16RotCentY, 
                                                                 int16_t i16OffsetX, int16_t i16OffsetY, 
                                                                 rot_frccr_st* pstCoord, int16_t i16Angle);
#endif
static void vRotLib_CalculateForwardRotatedCornerCoordinates_Shear(rot_mem_st* pstMem, 
                                                            int16_t i16OffsetX, int16_t i16OffsetY, 
                                                            float64_t f64FactorX, float64_t f64FactorY, 
                                                            rot_frccr_st* pstCoord);
#ifdef GA_USE_MATH_LIB
static void vRotLib_CalculateForwardRotatedCornerCoordinates_Scale(rot_mem_st* pstMem,
                                                            int16_t i16OffsetX, int16_t i16OffsetY,
                                                            float64_t f64FactorX, float64_t f64FactorY,
                                                            rot_scaleAlign_e eAlignment, rot_frccr_st* pstCoord);
#else
static void vRotLib_CalculateForwardRotatedCornerCoordinates_Scale(rot_mem_st* pstMem,
                                                            int16_t i16OffsetX, int16_t i16OffsetY,
                                                            int32_t i32FactorX, int32_t i32FactorY,
                                                            rot_scaleAlign_e eAlignment, rot_frccr_st* pstCoord);
#endif
static void vRotLib_CheckForNegativeCoordinates(rot_mem_st* pstMem, rot_rotCfg_st* pstParam, rot_frccr_st* pstCoord);
static void vRotLib_CheckForNegativeCoordinatesBlend(rot_mem_st* pstMem, rot_rotblendCfg_st* pstParam, rot_frccr_st* pstCoord);

/*********************************************/


/**********************************************
*             Function definition             *
**********************************************/

void vRotLib_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                        uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
     *pau8ModuleRevision = &au8LLDD_GA_ROTATE_LIB_C_REVISION[0];
     *pau8ModuleTag      = &au8LLDD_GA_ROTATE_LIB_C_TAG[0];
     *pau8HeaderRevision = &au8LLDD_GA_ROTATE_LIB_H_REVISION[0];
     *pau8HeaderTag      = &au8LLDD_GA_ROTATE_LIB_H_TAG[0];
}


/****************************************************************************/

/* Direct conversion from negative floats to unsigned int will cause undefined behaviour. Refer to C99 §6.3.1.4 */
static uint32_t RE_FLOAT64TOUINT32(float64_t x)
{
	return ((uint32_t)((int32_t)(x)));
}

/****************************************************************************/
/* calculate rounded float64_t */
static float64_t RE_FLOAT64ROUND(float64_t x)
{
    if (x>0.0)
    {
        return ((float64_t)((long long)(x + 0.5)));
    }
    else
    {
        return ((float64_t)((long long)(x - 0.5)));
    }
}

/****************************************************************************/

static void vSaveGlFwRotCornerCoord(rot_frccr_st *stCoord)
{
    au32Coordinate[0][0] = stCoord->u16X1;
    au32Coordinate[0][1] = stCoord->u16Y1;
    au32Coordinate[1][0] = stCoord->u16X2;
    au32Coordinate[1][1] = stCoord->u16Y2;
    au32Coordinate[2][0] = stCoord->u16X3;
    au32Coordinate[2][1] = stCoord->u16Y3;
    au32Coordinate[3][0] = stCoord->u16X4;
    au32Coordinate[3][1] = stCoord->u16Y4;
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vRotLib_CalculateTransformationMatrix_Rotate(rot_Mtrx_st* pstMatrix, float64_t f64Angle)
#else
void vRotLib_CalculateTransformationMatrix_Rotate(rot_Mtrx_st* pstMatrix, int16_t i16Angle)
#endif
{
#ifdef GA_USE_MATH_LIB
    float64_t f64AngRad;
    float64_t f64Sin,f64Cos;
#else
    int32_t i32Sin, i32Cos;
#endif

#ifdef GA_USE_MATH_LIB
    /* Angle Conversion to radians */
    f64AngRad = (2.0 * GA_CONST_PI * f64Angle)/360.0 ;

    f64Sin = ROT_SIN(f64AngRad);
    f64Cos = ROT_COS(f64AngRad);

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1865    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1866    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1867    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
    pstMatrix -> u32A11 = (uint32_t)((int64_t)( f64Cos * 65536.0) + 0xFFFFFFFFFFFFFFFFUL + 0x1UL);
    pstMatrix -> u32A12 = (uint32_t)((int64_t)(-f64Sin * 65536.0) + 0xFFFFFFFFFFFFFFFFUL + 0x1UL);
    pstMatrix -> u32A21 = (uint32_t)((int64_t)( f64Sin * 65536.0) + 0xFFFFFFFFFFFFFFFFUL + 0x1UL);
    pstMatrix -> u32A22 = (uint32_t)((int64_t)( f64Cos * 65536.0) + 0xFFFFFFFFFFFFFFFFUL + 0x1UL);
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

#else

    /* Calculate only once Sine and Cosine */
    i32Sin = ROT_SIN(i16Angle);
    i32Cos = ROT_COS(i16Angle);
   
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1865    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1866    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1867    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
    /* Transformation Matrix Config. */
    pstMatrix -> u32A11 = (uint32_t)(( i32Cos) + 0xFFFFFFFFU + 0x1U);
    pstMatrix -> u32A12 = (uint32_t)((-i32Sin) + 0xFFFFFFFFU + 0x1U);
    pstMatrix -> u32A21 = (uint32_t)(( i32Sin) + 0xFFFFFFFFU + 0x1U);
    pstMatrix -> u32A22 = (uint32_t)(( i32Cos) + 0xFFFFFFFFU + 0x1U);
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

#endif

    /* Fill W0=0, W1=0, W2=1: */
    pstMatrix -> u32A31 = (uint32_t)(0);
    pstMatrix -> u32A32 = (uint32_t)(0);
    pstMatrix -> u32A33 = (uint32_t)(WxR_VALUE_ONE);
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vRotLib_CalculateTransformationMatrix_Shear(rot_Mtrx_st* pstMatrix, float64_t  f64FactorX, float64_t  f64FactorY)
#else
void vRotLib_CalculateTransformationMatrix_Shear(rot_Mtrx_st* pstMatrix, int32_t i32FactorX, int32_t i32FactorY)
#endif
{
    /* Transformation Matrix Setup */
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1863    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
#ifdef GA_USE_MATH_LIB
    pstMatrix -> u32A11 = (uint32_t)((int64_t)((65536.0/(1.0-(f64FactorX * f64FactorY)))) + 0xFFFFFFFFFFFFFFFFUL + 0x1UL);
    pstMatrix -> u32A12 = (uint32_t)((int64_t)(((-f64FactorY * 65536.0) / (1.0-(f64FactorX * f64FactorY)))) + 0xFFFFFFFFFFFFFFFFUL + 0x1UL);
    pstMatrix -> u32A21 = (uint32_t)((int64_t)(((-f64FactorX*65536.0) / (1.0-(f64FactorX * f64FactorY)))) + 0xFFFFFFFFFFFFFFFFUL + 0x1UL);
    pstMatrix -> u32A22 = (uint32_t)((int64_t)((65536.0/(1.0-(f64FactorX * f64FactorY)))) + 0xFFFFFFFFFFFFFFFFUL + 0x1UL);
#else
    pstMatrix -> u32A11 = (uint32_t)((65536U * (65536U/(1U-(i32FactorX * i32FactorY))) ) + 0xFFFFFFFFU + 0x1U);
    pstMatrix -> u32A12 = (uint32_t)((65536U * ((-i32FactorY * 65536U) / (1U-(i32FactorX * i32FactorY))) ) + 0xFFFFFFFFU + 0x1U);
    pstMatrix -> u32A21 = (uint32_t)((65536U * ((-i32FactorX*65536U) / (1U-(i32FactorX * i32FactorY))) ) + 0xFFFFFFFFU + 0x1U);
    pstMatrix -> u32A22 = (uint32_t)((65536U * (65536U/(1-(i32FactorX * i32FactorY))) ) + 0xFFFFFFFFU + 0x1U);
#endif
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

    /* Fill W0=0, W1=0, W2=1: */
    pstMatrix -> u32A31 = (uint32_t)(0);
    pstMatrix -> u32A32 = (uint32_t)(0);
    pstMatrix -> u32A33 = (uint32_t)(WxR_VALUE_ONE);
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vRotLib_CalculateTransformationMatrix_Scale(rot_Mtrx_st* pstMatrix, float64_t  f64FactorX, float64_t  f64FactorY)
#else
void vRotLib_CalculateTransformationMatrix_Scale(rot_Mtrx_st* pstMatrix, int32_t i32FactorX, int32_t i32FactorY)
#endif
{
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1864    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
#ifdef GA_USE_MATH_LIB
    /* Transformation Matrix Setup */
    pstMatrix -> u32A11 = RE_FLOAT64TOUINT32((65536.0 / f64FactorX));
    pstMatrix -> u32A12 = 0U;
    pstMatrix -> u32A21 = 0U;
    pstMatrix -> u32A22 = RE_FLOAT64TOUINT32((65536.0 / f64FactorY));
#else
    /* Transformation Matrix Setup */
    pstMatrix -> u32A11 = (uint64_t)(65536U * (65536U / i32FactorX));
    pstMatrix -> u32A12 = 0U;
    pstMatrix -> u32A21 = 0U;
    pstMatrix -> u32A22 = (uint64_t)(65536U * (65536U / i32FactorY));
#endif
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

    /* Fill W0=0, W1=0, W2=1: */
    pstMatrix -> u32A31 = (uint32_t)(0);
    pstMatrix -> u32A32 = (uint32_t)(0);
    pstMatrix -> u32A33 = (uint32_t)(WxR_VALUE_ONE);
    
}

/****************************************************************************/
static ga_en_e vRotLib_CalculateCorrectClipWindow(rot_clipWnd_st* stClipWnd, ga_en_e eClipWndEn, rot_mem_st * pstMem, int* offset)
{
    ga_en_e eDraw = GA_EN;
    /* correct clip window */
    if(eClipWndEn == GA_EN)
    {
        if(offset[0] >= 0)
        {
            /* If offset is positive */
            if(offset[0] >= stClipWnd->u16UlX && offset[0] <= stClipWnd->u16LrX)
            {
                /* When is there is a partial overlap of clip window */
                stClipWnd->u16UlX = 0;
                stClipWnd->u16LrX = stClipWnd->u16LrX - offset[0];
            }
            else
            {
                /* Clip window is either completely inside the destination area or completely outside the destination area */
                stClipWnd->u16UlX = stClipWnd->u16UlX - offset[0];
                stClipWnd->u16LrX = stClipWnd->u16LrX - offset[0];           
            }
        }
        else
        {
            /* If offset is negative */
            stClipWnd->u16UlX = (uint16_t)RE_DOUBLEABS(offset[0]) + stClipWnd->u16UlX;
            stClipWnd->u16LrX = (uint16_t)(RE_MIN(pstMem->u16DstImgWidth - 1, (uint32_t)(RE_DOUBLEABS(offset[0])) + stClipWnd->u16LrX));
        }

        if(offset[1] >= 0)
        {
            /* If offset is positive */
            if(offset[1] >= stClipWnd->u16UlY && offset[1]  <= stClipWnd->u16LrY)
            {
                /* When is there is a partial overlap of clip window */
                stClipWnd->u16UlY = 0;
                stClipWnd->u16LrY = stClipWnd->u16LrY - offset[1];
            }
            else
            {
                /* Clip window is either completely inside the destination area or completely outside the destination area */
                stClipWnd->u16UlY = stClipWnd->u16UlY - offset[1];
                stClipWnd->u16LrY = stClipWnd->u16LrY - offset[1];
            }
        }
        else
        {
            /* If offset is negative */
            stClipWnd->u16UlY = (uint16_t)RE_DOUBLEABS(offset[1]) + stClipWnd->u16UlY;
            stClipWnd->u16LrY = (uint16_t)(RE_MIN(pstMem->u16DstImgHeight - 1, (uint32_t)(RE_DOUBLEABS(offset[1])) + stClipWnd->u16LrY));
        }

        eDraw = GA_EN;
        if(stClipWnd->u16UlX > 0x8000 || stClipWnd->u16UlY > 0x8000)
        {
            /* when there is no overlap of clip window with the destination area, disable drawing i.e Don't make a call to LLDD */

            stClipWnd->u16UlX = 0;
            stClipWnd->u16UlY = 0;
            stClipWnd->u16LrX = 0;
            stClipWnd->u16LrY = 0;
            eDraw = GA_DIS;
        }
    }
    else
    {
        eDraw = GA_EN;
        if(offset[0] < 0)
        {
            stClipWnd->u16UlX = (uint16_t)RE_DOUBLEABS(offset[0]);
            stClipWnd->u16LrX = pstMem->u16DstImgWidth - 1;
        }
        else
        {
            stClipWnd->u16UlX = 0;
            stClipWnd->u16LrX = pstMem->u16DstImgWidth - (uint16_t)RE_DOUBLEABS(offset[0]) - 1;
        }

        if(offset[1] < 0)
        {
            stClipWnd->u16UlY = (uint16_t)RE_DOUBLEABS(offset[1]);
            stClipWnd->u16LrY = pstMem->u16DstImgHeight - 1;
        }
        else
        {
            stClipWnd->u16UlY = 0;
            stClipWnd->u16LrY = pstMem->u16DstImgHeight - (uint16_t)RE_DOUBLEABS(offset[1]) - 1;
        }
    }
    return eDraw;
}


/****************************************************************************/

ga_en_e vRotLib_CheckForOverlap(rot_frccr_st * stCoord, rot_clipWnd_st * stClipWnd, ga_en_e eClipWndEn)
{
    ga_en_e eResult;
    uint16_t u16XMax, u16YMax;
    eResult = GA_EN;

    if(eClipWndEn == GA_EN)
    {
        u16XMax = stCoord->u16X4;
        u16YMax = stCoord->u16Y3;
       
        u16XMax = u16XMax >> 4;
        u16YMax = u16YMax >> 4;
        
		/* Check if the FRCC overlaps with the destination region by atleast 1 pixel and also check make sure that Y coordinates of FRCC are not equal */
        if(((u16YMax - stClipWnd->u16UlY) >= 1) && ((u16XMax - stClipWnd->u16UlX) >= 1) &&
			 ( ((stCoord->u16Y1 >> 4) ^  (stCoord->u16Y2 >> 4)) | ((stCoord->u16Y2 >> 4) ^  (stCoord->u16Y3 >> 4)) |
			    ((stCoord->u16Y3 >> 4) ^  (stCoord->u16Y3 >> 4)) | ((stCoord->u16Y4 >> 4) ^  (stCoord->u16Y1 >> 4)) ))
        {
            eResult = GA_EN;
        }
        else
        {
            eResult = GA_DIS;
        }
    }
    return eResult;  
    
}

/****************************************************************************/

static GA_COORD_t RE_DEG2RAD(GA_COORD_t c)
{
    c.x = (c.x*(float64_t)3.141592654)/(float64_t)180.0;
    c.y = (c.y*(float64_t)3.141592654)/(float64_t)180.0;
    c.z = (c.z*(float64_t)3.141592654)/(float64_t)180.0;

    return(c);
}


/****************************************************************************/

static GA_MATRIX_t RE_ROTMATRIX (GA_COORD_t rot)
{
    GA_MATRIX_t R;
    float64_t cx, sx, cy, sy, cz, sz;

    cx = (float64_t)cos(rot.x);
    sx = (float64_t)sin(rot.x);
    cy = (float64_t)cos(rot.y);
    sy = (float64_t)sin(rot.y);
    cz = (float64_t)cos(rot.z);
    sz = (float64_t)sin(rot.z);

    R.sx  = cy*cz;
    R.shx = -cy*sz;
    R.tx  = sy;
    R.shy = sx*sy*cz  + cx*sz;
    R.sy  = -sx*sy*sz + cx*cz;
    R.ty  = -sx*cy;
    R.w0  = -cx*sy*cz + sx*sz;
    R.w1  = cx*sy*sz + sx*cz;
    R.w2  = cx*cy;

    return(R);
}


/****************************************************************************/

static GA_SCREENOBJ_t RE_CREATESCREENOBJECT(uint32_t u32Width, uint32_t u32Height, float64_t f64RotPoint_x, float64_t f64RotPoint_y)
{
    GA_SCREENOBJ_t s;

    /* lower left */
    s.p1.x = - f64RotPoint_x;
    s.p1.y = - f64RotPoint_y;
    s.p1.z = 0.0;

    /* upper left */
    s.p2.x = - f64RotPoint_x;
    s.p2.y = (float64_t)u32Height - f64RotPoint_y;
    s.p2.z = 0.0;

    /* upper right */
    s.p3.x = (float64_t)u32Width  - f64RotPoint_x;
    s.p3.y = (float64_t)u32Height - f64RotPoint_y;
    s.p3.z = 0.0;

    /* lower right */
    s.p4.x =   (float64_t)u32Width - f64RotPoint_x;
    s.p4.y = - f64RotPoint_y;
    s.p4.z = 0.0;

    s.c.x = 0.0;
    s.c.y = 0.0;
    s.c.z = 0.0;

    return(s);
}


/****************************************************************************/

static GA_COORD_t RE_VECTORMATRIXMULT (GA_COORD_t A, GA_MATRIX_t B)
{
    GA_COORD_t C;

    C.x = A.x*B.sx  + A.y*B.shy + A.z*B.w0;
    C.y = A.x*B.shx + A.y*B.sy  + A.z*B.w1;
    C.z = A.x*B.tx  + A.y*B.ty  + A.z*B.w2;

    return(C);
}


/****************************************************************************/

static float64_t RE_MAX2(float64_t f64X, float64_t f64Y)
{
    float64_t f64Value;

    if (f64X>f64Y)
    {
        f64Value = f64X;
    }
    else
    {
        f64Value = f64Y;
    }

    return f64Value;
}


/****************************************************************************/

static GA_SCREENOBJ_t RE_3DTO2D(GA_SCREENOBJ_t S, float64_t f64Depth_shift)
{
    float64_t z;

    z = S.p1.z + f64Depth_shift;
    S.p1.x = S.p1.x/z;
    S.p1.y = S.p1.y/z;
    S.p1.z = 0.0;

    z = S.p2.z + f64Depth_shift;
    S.p2.x = S.p2.x/z;
    S.p2.y = S.p2.y/z;
    S.p2.z = 0.0;

    z = S.p3.z + f64Depth_shift;
    S.p3.x = S.p3.x/z;
    S.p3.y = S.p3.y/z;
    S.p3.z = 0.0;

    z  =S.p4.z + f64Depth_shift;
    S.p4.x = S.p4.x/z;
    S.p4.y = S.p4.y/z;
    S.p4.z = 0.0;

    return(S);
}


/****************************************************************************/

static GA_COORD_t RE_MINSCREENOBJECTTYPE(GA_SCREENOBJ_t s)
{
    GA_COORD_t dummy;

    dummy.x = s.p1.x;
    dummy.y = s.p1.y;
    dummy.z = s.p1.z;

    if (dummy.x > s.p2.x) {dummy.x = s.p2.x;}
    if (dummy.x > s.p3.x) {dummy.x = s.p3.x;}
    if (dummy.x > s.p4.x) {dummy.x = s.p4.x;}

    if (dummy.y > s.p2.y) {dummy.y = s.p2.y;}
    if (dummy.y > s.p3.y) {dummy.y = s.p3.y;}
    if (dummy.y > s.p4.y) {dummy.y = s.p4.y;}

    if (dummy.z > s.p2.z) {dummy.z = s.p2.z;}
    if (dummy.z > s.p3.z) {dummy.z = s.p3.z;}
    if (dummy.z > s.p4.z) {dummy.z = s.p4.z;}

    return(dummy);
}


/****************************************************************************/

static GA_SCREENOBJ_t RE_TRANSLATESCREENOBJECT(GA_SCREENOBJ_t a, GA_COORD_t b)
{
    a.p1.x = a.p1.x - b.x;
    a.p1.y = a.p1.y - b.y;
    a.p1.z = a.p1.z - b.z;

    a.p2.x = a.p2.x - b.x;
    a.p2.y = a.p2.y - b.y;
    a.p2.z = a.p2.z - b.z;

    a.p3.x = a.p3.x - b.x;
    a.p3.y = a.p3.y - b.y;
    a.p3.z = a.p3.z - b.z;

    a.p4.x = a.p4.x - b.x;
    a.p4.y = a.p4.y - b.y;
    a.p4.z = a.p4.z - b.z;

    a.c.x = a.c.x - b.x;
    a.c.y = a.c.y - b.y;
    a.c.z = a.c.z - b.z;

    return(a);
}


/****************************************************************************/

static GA_SCREENOBJ_t RE_SCALESCREENOBJECT_X(GA_SCREENOBJ_t S, float64_t f64Scale)
{
    S.p1.x = S.p1.x * f64Scale;
    S.p2.x = S.p2.x * f64Scale;
    S.p3.x = S.p3.x * f64Scale;
    S.p4.x = S.p4.x * f64Scale;
    S.c.x  = S.c.x  * f64Scale;

    return(S);
}


/****************************************************************************/

static GA_SCREENOBJ_t RE_SCALESCREENOBJECT_Y(GA_SCREENOBJ_t S, float64_t f64Scale)
{
    S.p1.y = S.p1.y * f64Scale;
    S.p2.y = S.p2.y * f64Scale;
    S.p3.y = S.p3.y * f64Scale;
    S.p4.y = S.p4.y * f64Scale;
    S.c.y  = S.c.y  * f64Scale;

    return(S);
}


/****************************************************************************/

static GA_SCREENOBJ_t RE_FORWARDROT(GA_COORD_t rot, float64_t f64Scale, uint32_t u32Width, uint32_t u32Height, float64_t f64RotPoint_x, float64_t f64RotPoint_y)
{
    GA_MATRIX_t R;
    GA_SCREENOBJ_t S;
    GA_COORD_t min;

    R = RE_ROTMATRIX(RE_DEG2RAD(rot));
    S = RE_CREATESCREENOBJECT(u32Width, u32Height, f64RotPoint_x, f64RotPoint_y);

    S.p1 = RE_VECTORMATRIXMULT(S.p1, R);
    S.p2 = RE_VECTORMATRIXMULT(S.p2, R);
    S.p3 = RE_VECTORMATRIXMULT(S.p3, R);
    S.p4 = RE_VECTORMATRIXMULT(S.p4, R);

    S = RE_3DTO2D(S,RE_MAX2((float64_t)u32Width, (float64_t)u32Height));
    min = RE_MINSCREENOBJECTTYPE(S);
    S = RE_TRANSLATESCREENOBJECT(S, min);
    S = RE_SCALESCREENOBJECT_X(S, f64Scale);
    S = RE_SCALESCREENOBJECT_Y(S, f64Scale);

    return(S);
}


/****************************************************************************/
static int RE_SORTCORNERS(GA_SCREENOBJ_t* CC)
{
    int32_t p1, p2, p3, p4;
    float64_t cx1;
    float64_t cy1;
    float64_t cx2;
    float64_t cy2;
    float64_t cx3;
    float64_t cy3;
    float64_t cx4;
    float64_t cy4;
    float64_t ox1;
    float64_t oy1;
    float64_t ox2;
    float64_t oy2;
    float64_t ox3;
    float64_t oy3;
    float64_t ox4;
    float64_t oy4;
    float64_t alpha1, alpha2, alpha3;
    GA_SCREENOBJ_t pCC;
    int iReturnCode = -1;

    pCC.p1.x = (int32_t)((*CC).p1.x);
    pCC.p2.x = (int32_t)((*CC).p2.x);
    pCC.p3.x = (int32_t)((*CC).p3.x);
    pCC.p4.x = (int32_t)((*CC).p4.x);
    pCC.p1.y = (int32_t)((*CC).p1.y);
    pCC.p2.y = (int32_t)((*CC).p2.y);
    pCC.p3.y = (int32_t)((*CC).p3.y);
    pCC.p4.y = (int32_t)((*CC).p4.y);

    pCC.p1.z = 0.0;
    pCC.p2.z = 0.0;
    pCC.p3.z = 0.0;
    pCC.p4.z = 0.0;

    (*CC).p1.x = ((*CC).p1.x);
    (*CC).p2.x = ((*CC).p2.x);
    (*CC).p3.x = ((*CC).p3.x);
    (*CC).p4.x = ((*CC).p4.x);
    (*CC).p1.y = ((*CC).p1.y);
    (*CC).p2.y = ((*CC).p2.y);
    (*CC).p3.y = ((*CC).p3.y);
    (*CC).p4.y = ((*CC).p4.y);

    p1 = (((int32_t)(pCC.p1.y))<<16) + ((int32_t)(pCC.p1.x));
    p2 = (((int32_t)(pCC.p2.y))<<16) + ((int32_t)(pCC.p2.x));
    p3 = (((int32_t)(pCC.p3.y))<<16) + ((int32_t)(pCC.p3.x));
    p4 = (((int32_t)(pCC.p4.y))<<16) + ((int32_t)(pCC.p4.x));

    cx1 = (pCC.p1.x);
    cy1 = (pCC.p1.y);
    cx2 = (pCC.p2.x);
    cy2 = (pCC.p2.y);
    cx3 = (pCC.p3.x);
    cy3 = (pCC.p3.y);
    cx4 = (pCC.p4.x);
    cy4 = (pCC.p4.y);

    ox1 = ((*CC).p1.x);
    oy1 = ((*CC).p1.y);
    ox2 = ((*CC).p2.x);
    oy2 = ((*CC).p2.y);
    ox3 = ((*CC).p3.x);
    oy3 = ((*CC).p3.y);
    ox4 = ((*CC).p4.x);
    oy4 = ((*CC).p4.y);

    /* corner 1 has the smallest coordinates */
    if ((p1<p2) && (p1<p3) && (p1<p4))
    {
        (*CC).p1.x = RE_FLOAT64TOUINT32(ox1);
        (*CC).p1.y = RE_FLOAT64TOUINT32(oy1);
        /* calculate the angle of all vectors from corner 1 to the other corners */
        alpha1 = ((cx2-cx1) / sqrt((cx2-cx1)*(cx2-cx1) + (cy2-cy1)*(cy2-cy1)));
        alpha2 = ((cx3-cx1) / sqrt((cx3-cx1)*(cx3-cx1) + (cy3-cy1)*(cy3-cy1)));
        alpha3 = ((cx4-cx1) / sqrt((cx4-cx1)*(cx4-cx1) + (cy4-cy1)*(cy4-cy1)));

        /* sort remaining corners dependant on angle */
        if ((alpha1<alpha2) && (alpha1<alpha3))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox2);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy2);
            if (alpha2<alpha3)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy3);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy4);
                iReturnCode = 1;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy4);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy3);
                iReturnCode = 1;
            }
        }
        else if ((alpha2<alpha1) && (alpha2<alpha3))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox3);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy3);
            if (alpha1<alpha3)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy2);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy4);
                iReturnCode = 1;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy4);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy2);
                iReturnCode = 1;
            }
        }
        else if ((alpha3<alpha1) && (alpha3<alpha2))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox4);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy4);
            if (alpha1<alpha2)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy2);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy3);
                iReturnCode = 1;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy3);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy2);
                iReturnCode = 1;
            }
        }
        else
        {
            iReturnCode = -1;
        }
    }
    /* corner 2 has the smallest coordinates*/
    else if ((p2<p1) && (p2<p3) && (p2<p4))
    {
        (*CC).p1.x = RE_FLOAT64TOUINT32(ox2);
        (*CC).p1.y = RE_FLOAT64TOUINT32(oy2);
        /* calculate the angle of all vectors from corner 2 to the other corners */
        alpha1 = ((cx1-cx2) / sqrt((cx1-cx2)*(cx1-cx2) + (cy1-cy2)*(cy1-cy2)));
        alpha2 = ((cx3-cx2) / sqrt((cx3-cx2)*(cx3-cx2) + (cy3-cy2)*(cy3-cy2)));
        alpha3 = ((cx4-cx2) / sqrt((cx4-cx2)*(cx4-cx2) + (cy4-cy2)*(cy4-cy2)));
        /* sort remaining corners dependant on angle */
        if ((alpha1<alpha2) && (alpha1<alpha3))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox1);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy1);
            if (alpha2<alpha3)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy3);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy4);
                iReturnCode = 2;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy4);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy3);
                iReturnCode = 2;
            }
        }
        else if ((alpha2<alpha1) && (alpha2<alpha3))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox3);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy3);
            if (alpha1<alpha3)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy1);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy4);
                iReturnCode = 3;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy4);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy1);
                iReturnCode = 4;
            }
        }
        else if ((alpha3<alpha1) && (alpha3<alpha2))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox4);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy4);
            if (alpha1<alpha2)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy1);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy3);
                iReturnCode = 3;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy3);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy1);
                iReturnCode = 4;
            }
        }
        else
        {
            iReturnCode = -1;
        }
    }
    /* corner 3 has the smallest coordinates */
    else if ((p3<p1) && (p3<p2) && (p3<p4))
    {
        (*CC).p1.x = RE_FLOAT64TOUINT32(ox3);
        (*CC).p1.y = RE_FLOAT64TOUINT32(oy3);
        /* calculate the angle of all vectors from corner 3 to the other corners */
        alpha1 = ((cx1-cx3) / sqrt((cx1-cx3)*(cx1-cx3) + (cy1-cy3)*(cy1-cy3)));
        alpha2 = ((cx2-cx3) / sqrt((cx2-cx3)*(cx2-cx3) + (cy2-cy3)*(cy2-cy3)));
        alpha3 = ((cx4-cx3) / sqrt((cx4-cx3)*(cx4-cx3) + (cy4-cy3)*(cy4-cy3)));
        /* sort remaining corners dependant on angle */
        if ((alpha1<alpha2) && (alpha1<alpha3))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox1);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy1);
            if (alpha2<alpha3)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy2);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy4);
                iReturnCode = 2;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy4);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy2);
                iReturnCode = 2;
            }
        }
        else if ((alpha2<alpha1) && (alpha2<alpha3))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox2);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy2);
            if (alpha1<alpha3)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy1);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy4);
                iReturnCode = 3;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox4);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy4);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy1);
                iReturnCode = 4;
            }
        }
        else if ((alpha3<alpha1) && (alpha3<alpha2))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox4);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy4);
            if (alpha1<alpha2)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy1);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy2);
                iReturnCode = 3;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy2);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy1);
                iReturnCode = 4;
            }
        }
        else
        {
            iReturnCode = -1;
        }
    }
    /* corner 4 has the smallest coordinates */
    else if ((p4<p1) && (p4<p2) && (p4<p3))
    {
        (*CC).p1.x = RE_FLOAT64TOUINT32(ox4);
        (*CC).p1.y = RE_FLOAT64TOUINT32(oy4);
        /* calculate the angle of all vectors from corner 4 to the other corners */
        alpha1 = ((cx1-cx4) / sqrt((cx1-cx4)*(cx1-cx4) + (cy1-cy4)*(cy1-cy4)));
        alpha2 = ((cx2-cx4) / sqrt((cx2-cx4)*(cx2-cx4) + (cy2-cy4)*(cy2-cy4)));
        alpha3 = ((cx3-cx4) / sqrt((cx3-cx4)*(cx3-cx4) + (cy3-cy4)*(cy3-cy4)));
        /* sort remaining corners dependant on angle */
        if ((alpha1<alpha2) && (alpha1<alpha3))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox1);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy1);
            if (alpha2<alpha3)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy2);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy3);
                iReturnCode = 2;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy3);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy2);
                iReturnCode = 2;
            }
        }
        else if ((alpha2<alpha1) && (alpha2<alpha3))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox2);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy2);
            if (alpha1<alpha3)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy1);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy3);
                iReturnCode = 3;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox3);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy3);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy1);
                iReturnCode = 4;
            }
        }
        else if ((alpha3<alpha1) && (alpha3<alpha2))
        {
            (*CC).p2.x = RE_FLOAT64TOUINT32(ox3);
            (*CC).p2.y = RE_FLOAT64TOUINT32(oy3);
            if (alpha1<alpha2)
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy1);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy2);
                iReturnCode = 3;
            }
            else
            {
                (*CC).p3.x = RE_FLOAT64TOUINT32(ox2);
                (*CC).p3.y = RE_FLOAT64TOUINT32(oy2);
                (*CC).p4.x = RE_FLOAT64TOUINT32(ox1);
                (*CC).p4.y = RE_FLOAT64TOUINT32(oy1);
                iReturnCode = 4;
            }
        }
        else
        {
            iReturnCode = -1;
        }
    }
    else
    {
        iReturnCode = -1;
    }

    return iReturnCode;
}


/****************************************************************************/

static GA_MATRIX_t RE_SCALEMATRIX(GA_MATRIX_t M, float64_t f64Scale)
{
    M.sx  = M.sx  * f64Scale;
    M.shx = M.shx * f64Scale;
    M.tx  = M.tx  * f64Scale;
    M.shy = M.shy * f64Scale;
    M.sy  = M.sy  * f64Scale;
    M.ty  = M.ty  * f64Scale;
    M.w0  = M.w0  * f64Scale;
    M.w1  = M.w1  * f64Scale;
    M.w2  = M.w2  * f64Scale;

    return(M);
}


/****************************************************************************/

static float64_t RE_DOUBLEABS(float64_t f64X)
{
    float64_t f64Value;

    if (f64X > 0.0)
    {
        f64Value = f64X;
    }
    else
    {
        f64Value = -f64X;
    }

    return f64Value;
}


/****************************************************************************/
static float64_t RE_MAXMATRIXELEMENT(GA_MATRIX_t M)
{
    float64_t f64X;

    f64X = RE_DOUBLEABS(M.sx);

    if (RE_DOUBLEABS(M.shx) > f64X)
    {
        f64X = RE_DOUBLEABS(M.shx);
    }
    if (RE_DOUBLEABS(M.tx) > f64X)
    {
        f64X = RE_DOUBLEABS(M.tx);
    }
    if (RE_DOUBLEABS(M.shy) > f64X)
    {
        f64X = RE_DOUBLEABS(M.shy);
    }
    if (RE_DOUBLEABS(M.sy) > f64X)
    {
        f64X = RE_DOUBLEABS(M.sy);
    }
    if (RE_DOUBLEABS(M.ty) > f64X)
    {
        f64X = RE_DOUBLEABS(M.ty);
    }
    if (RE_DOUBLEABS(M.w0) > f64X)
    {
        f64X = RE_DOUBLEABS(M.w0);
    }
    if (RE_DOUBLEABS(M.w1) > f64X)
    {
        f64X = RE_DOUBLEABS(M.w1);
    }
    if (RE_DOUBLEABS(M.w2) > f64X)
    {
        f64X = RE_DOUBLEABS(M.w2);
    }

    return(f64X);
}


/****************************************************************************/

#if defined (__KEIL__)
float64_t round(float64_t f64Value)
{
    return (f64Value >= 0.0) ? floor(f64Value + 0.5) : ceil(f64Value - 0.5);
}
#endif


/****************************************************************************/

static GA_MATRIX_t RE_BACKWARDMATRIX(GA_SCREENOBJ_t FRCC, uint32_t u32Width, uint32_t u32Height)
{
    GA_MATRIX_t im1;
    float64_t f64Width  = (float64_t)u32Width;
    float64_t f64Height = (float64_t)u32Height;

    im1.sx=(((FRCC.p4.x-FRCC.p3.x)*FRCC.p1.y+FRCC.p3.x*FRCC.p4.y+(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y-FRCC.p4.y*FRCC.p1.x)*((FRCC.p4.x-FRCC.p3.x)*FRCC.p2.y+FRCC.p3.x*FRCC.p4.y+(FRCC.p2.x-FRCC.p4.x)*FRCC.p3.y-FRCC.p2.x*FRCC.p4.y)*f64Width*(FRCC.p1.y-FRCC.p2.y)) /
           ((-FRCC.p2.x*(FRCC.p3.x-FRCC.p4.x)*(FRCC.p3.x-FRCC.p4.x)*FRCC.p2.y+FRCC.p4.y*FRCC.p3.x*FRCC.p3.x*FRCC.p4.x+((FRCC.p2.x*FRCC.p2.x-FRCC.p4.x*FRCC.p4.x)*FRCC.p3.y-2*FRCC.p4.y*FRCC.p4.x*FRCC.p2.x)*FRCC.p3.x-2*FRCC.p2.x*((FRCC.p2.x-FRCC.p4.x)*FRCC.p3.y-0.5*FRCC.p2.x*FRCC.p4.y)*FRCC.p4.x)*FRCC.p1.y*FRCC.p1.y +
           (FRCC.p1.x*(FRCC.p3.x-FRCC.p4.x)*(FRCC.p3.x-FRCC.p4.x)*FRCC.p2.y*FRCC.p2.y-2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p3.x)*FRCC.p2.y-FRCC.p3.x*FRCC.p3.x*FRCC.p4.y*FRCC.p4.y*FRCC.p1.x+2*FRCC.p2.x*((FRCC.p4.x-FRCC.p2.x)*FRCC.p3.y+FRCC.p4.y*FRCC.p1.x)*FRCC.p4.y*FRCC.p3.x -
           ((FRCC.p1.x-2*FRCC.p2.x)*FRCC.p4.x+FRCC.p2.x*FRCC.p1.x)*(FRCC.p2.x-FRCC.p4.x)*FRCC.p3.y*FRCC.p3.y+2*FRCC.p1.x*FRCC.p2.x*FRCC.p4.y*(FRCC.p2.x-FRCC.p4.x)*FRCC.p3.y-FRCC.p2.x*FRCC.p2.x*FRCC.p4.y*FRCC.p4.y*FRCC.p1.x)*FRCC.p1.y+(-2*FRCC.p4.y*(FRCC.p1.x-0.5*FRCC.p4.x)*FRCC.p3.x*FRCC.p3.x +
           (-(FRCC.p1.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y+2*FRCC.p4.y*FRCC.p1.x*FRCC.p1.x)*FRCC.p3.x-FRCC.p4.x*FRCC.p1.x*FRCC.p1.x*FRCC.p4.y)*FRCC.p2.y*FRCC.p2.y+(2*(FRCC.p1.x-0.5*FRCC.p2.x)*FRCC.p4.y*FRCC.p4.y*FRCC.p3.x*FRCC.p3.x-2*((FRCC.p4.x-FRCC.p2.x)*FRCC.p3.y+FRCC.p4.y*FRCC.p1.x)*FRCC.p4.y*FRCC.p1.x*FRCC.p3.x +
           FRCC.p2.x*(FRCC.p1.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y*FRCC.p3.y-2*FRCC.p1.x*FRCC.p1.x*FRCC.p4.y*(FRCC.p2.x-FRCC.p4.x)*FRCC.p3.y+FRCC.p1.x*FRCC.p1.x*FRCC.p4.y*FRCC.p4.y*FRCC.p2.x)*FRCC.p2.y+FRCC.p4.y*FRCC.p3.y*(FRCC.p1.x-FRCC.p2.x)*(FRCC.p1.x-FRCC.p2.x)*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y));
    im1.shx=-((FRCC.p1.x-FRCC.p2.x)*((FRCC.p4.y-FRCC.p2.y)*FRCC.p3.x+(FRCC.p2.x-FRCC.p4.x)*FRCC.p3.y+FRCC.p4.x*FRCC.p2.y-FRCC.p2.x*FRCC.p4.y)*((FRCC.p4.y-FRCC.p1.y)*FRCC.p3.x+(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y+FRCC.p4.x*FRCC.p1.y-FRCC.p4.y*FRCC.p1.x)*f64Width) /
             ((FRCC.p4.y*(FRCC.p1.y-FRCC.p2.y)*(FRCC.p1.y-FRCC.p2.y)*FRCC.p4.x+((2*FRCC.p2.y-FRCC.p1.y)*FRCC.p1.x-FRCC.p2.x*FRCC.p2.y)*FRCC.p4.y*FRCC.p4.y+2*(FRCC.p1.y*FRCC.p2.x*FRCC.p2.y-FRCC.p1.x*FRCC.p2.y*FRCC.p2.y)*FRCC.p4.y+FRCC.p1.y*FRCC.p2.y*(FRCC.p2.y*FRCC.p1.x-FRCC.p2.x*FRCC.p1.y))*FRCC.p3.x*FRCC.p3.x +
             ((-(FRCC.p1.y-FRCC.p2.y)*(FRCC.p1.y-FRCC.p2.y)*FRCC.p4.x*FRCC.p4.x+2*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p2.y*FRCC.p1.x-FRCC.p2.x*FRCC.p1.y)*FRCC.p4.x+(FRCC.p1.x-FRCC.p2.x)*(FRCC.p1.x-FRCC.p2.x)*FRCC.p4.y*FRCC.p4.y+2*(FRCC.p2.x*FRCC.p1.x*FRCC.p2.y-FRCC.p1.y*FRCC.p2.x*FRCC.p2.x)*FRCC.p4.y+FRCC.p1.y*FRCC.p1.y*FRCC.p2.x*FRCC.p2.x-FRCC.p2.y*FRCC.p2.y*FRCC.p1.x*FRCC.p1.x)*FRCC.p3.y +
             2*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p4.y*FRCC.p1.x-FRCC.p4.x*FRCC.p1.y)*(FRCC.p2.y*FRCC.p1.x-FRCC.p2.x*FRCC.p1.y))*FRCC.p3.x+((FRCC.p1.x*FRCC.p1.y-2*FRCC.p2.x*(FRCC.p1.y-0.5*FRCC.p2.y))*FRCC.p4.x*FRCC.p4.x+(-(FRCC.p1.x-FRCC.p2.x)*(FRCC.p1.x-FRCC.p2.x)*FRCC.p4.y +
             2*FRCC.p1.y*FRCC.p2.x*FRCC.p2.x-2*FRCC.p2.x*FRCC.p1.x*FRCC.p2.y)*FRCC.p4.x+FRCC.p1.x*FRCC.p2.x*(FRCC.p2.y*FRCC.p1.x-FRCC.p2.x*FRCC.p1.y))*FRCC.p3.y*FRCC.p3.y-2*(FRCC.p2.x-FRCC.p4.x)*(FRCC.p4.y*FRCC.p1.x-FRCC.p4.x*FRCC.p1.y)*(FRCC.p2.y*FRCC.p1.x-FRCC.p2.x*FRCC.p1.y)*FRCC.p3.y +
             (FRCC.p2.x*FRCC.p4.y-FRCC.p4.x*FRCC.p2.y)*(FRCC.p4.y*FRCC.p1.x-FRCC.p4.x*FRCC.p1.y)*(FRCC.p2.y*FRCC.p1.x-FRCC.p2.x*FRCC.p1.y));
    im1.tx=(((FRCC.p3.y-FRCC.p4.y)*FRCC.p1.x+(FRCC.p4.x-FRCC.p3.x)*FRCC.p1.y+FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*f64Width*((FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x+(FRCC.p4.x-FRCC.p3.x)*FRCC.p2.y+FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.y*FRCC.p1.x-FRCC.p2.x*FRCC.p1.y)) /
           ((FRCC.p2.y*(FRCC.p3.y-FRCC.p4.y)*(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x+((2*FRCC.p4.y-FRCC.p3.y)*FRCC.p3.x-FRCC.p4.y*FRCC.p4.x)*FRCC.p2.y*FRCC.p2.y+2*(FRCC.p4.y*FRCC.p4.x*FRCC.p3.y-FRCC.p4.y*FRCC.p4.y*FRCC.p3.x)*FRCC.p2.y+FRCC.p4.y*FRCC.p3.y*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y))*FRCC.p1.x*FRCC.p1.x +
           ((-(FRCC.p3.y-FRCC.p4.y)*(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x*FRCC.p2.x-2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.y-FRCC.p4.y)*FRCC.p2.x+(FRCC.p3.x-FRCC.p4.x)*(FRCC.p3.x-FRCC.p4.x)*FRCC.p2.y*FRCC.p2.y+2*(FRCC.p4.y*FRCC.p4.x*FRCC.p3.x-FRCC.p4.x*FRCC.p4.x*FRCC.p3.y)*FRCC.p2.y-FRCC.p3.x*FRCC.p3.x*FRCC.p4.y*FRCC.p4.y +
           FRCC.p4.x*FRCC.p4.x*FRCC.p3.y*FRCC.p3.y)*FRCC.p1.y+2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x))*FRCC.p1.x+((FRCC.p3.y*FRCC.p3.x-2*(FRCC.p3.y-0.5*FRCC.p4.y)*FRCC.p4.x)*FRCC.p2.x*FRCC.p2.x +
           (-(FRCC.p3.x-FRCC.p4.x)*(FRCC.p3.x-FRCC.p4.x)*FRCC.p2.y-2*FRCC.p4.y*FRCC.p4.x*FRCC.p3.x+2*FRCC.p4.x*FRCC.p4.x*FRCC.p3.y)*FRCC.p2.x+FRCC.p4.x*FRCC.p3.x*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y))*FRCC.p1.y*FRCC.p1.y-2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.x-FRCC.p4.x)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x)*FRCC.p1.y +
           (FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.x*FRCC.p4.y-FRCC.p4.x*FRCC.p2.y)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x));
    im1.shy=-(((FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x+(FRCC.p4.x-FRCC.p3.x)*FRCC.p2.y+FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*((FRCC.p3.y-FRCC.p1.y)*FRCC.p2.x+(FRCC.p1.x-FRCC.p3.x)*FRCC.p2.y-FRCC.p3.y*FRCC.p1.x+FRCC.p3.x*FRCC.p1.y)*f64Height*(FRCC.p1.y-FRCC.p4.y)) /
             ((FRCC.p3.y*(FRCC.p1.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p4.y)*FRCC.p3.x+((2*FRCC.p4.x-FRCC.p1.x)*FRCC.p1.y-FRCC.p4.y*FRCC.p4.x)*FRCC.p3.y*FRCC.p3.y+2*(FRCC.p1.y*FRCC.p1.x*FRCC.p4.y-FRCC.p4.x*FRCC.p1.y*FRCC.p1.y)*FRCC.p3.y+FRCC.p1.y*FRCC.p1.y*FRCC.p4.y*FRCC.p4.x-FRCC.p1.y*FRCC.p4.y*FRCC.p4.y*FRCC.p1.x)*FRCC.p2.x*FRCC.p2.x+
             ((-(FRCC.p1.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p4.y)*FRCC.p3.x*FRCC.p3.x-2*(FRCC.p1.y-FRCC.p3.y)*(FRCC.p4.y*FRCC.p1.x-FRCC.p4.x*FRCC.p1.y)*FRCC.p3.x+(FRCC.p1.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y*FRCC.p3.y+2*(FRCC.p4.x*FRCC.p1.y*FRCC.p1.x-FRCC.p4.y*FRCC.p1.x*FRCC.p1.x)*FRCC.p3.y-FRCC.p4.x*FRCC.p4.x*FRCC.p1.y*FRCC.p1.y +
             FRCC.p4.y*FRCC.p4.y*FRCC.p1.x*FRCC.p1.x)*FRCC.p2.y+2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p1.y-FRCC.p3.y)*(FRCC.p4.y*FRCC.p1.x-FRCC.p4.x*FRCC.p1.y))*FRCC.p2.x+((FRCC.p1.x*FRCC.p1.y-2*FRCC.p4.y*(FRCC.p1.x-0.5*FRCC.p4.x))*FRCC.p3.x*FRCC.p3.x +
             (-(FRCC.p1.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y-2*FRCC.p4.x*FRCC.p1.y*FRCC.p1.x+2*FRCC.p4.y*FRCC.p1.x*FRCC.p1.x)*FRCC.p3.x-FRCC.p4.x*FRCC.p1.x*FRCC.p1.x*FRCC.p4.y+FRCC.p4.x*FRCC.p4.x*FRCC.p1.y*FRCC.p1.x)*FRCC.p2.y*FRCC.p2.y-2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p1.x-FRCC.p3.x)*(FRCC.p4.y*FRCC.p1.x-FRCC.p4.x*FRCC.p1.y)*FRCC.p2.y +
             (FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p4.y*FRCC.p1.x-FRCC.p4.x*FRCC.p1.y)*(FRCC.p3.y*FRCC.p1.x-FRCC.p3.x*FRCC.p1.y));
    im1.sy=((FRCC.p1.x-FRCC.p4.x)*((FRCC.p2.y-FRCC.p3.y)*FRCC.p4.x+(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x-FRCC.p3.x*(FRCC.p2.y-FRCC.p4.y))*f64Height*((FRCC.p2.y-FRCC.p3.y)*FRCC.p1.x+(FRCC.p3.y-FRCC.p1.y)*FRCC.p2.x+FRCC.p3.x*(FRCC.p1.y-FRCC.p2.y))) /
           ((-FRCC.p4.y*(FRCC.p2.y-FRCC.p3.y)*(FRCC.p2.y-FRCC.p3.y)*FRCC.p4.x+FRCC.p2.y*(FRCC.p3.y-FRCC.p4.y)*(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x-((FRCC.p3.y-2*FRCC.p4.y)*FRCC.p2.y+FRCC.p4.y*FRCC.p3.y)*FRCC.p3.x*(FRCC.p2.y-FRCC.p4.y))*FRCC.p1.x*FRCC.p1.x+(FRCC.p1.y*(FRCC.p2.y-FRCC.p3.y)*(FRCC.p2.y-FRCC.p3.y)*FRCC.p4.x*FRCC.p4.x +
           2*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p4.x-FRCC.p1.y*(FRCC.p3.y-FRCC.p4.y)*(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x*FRCC.p2.x-2*FRCC.p3.x*FRCC.p4.y*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p2.x +
           FRCC.p3.x*FRCC.p3.x*(FRCC.p2.y-FRCC.p4.y)*((FRCC.p1.y-2*FRCC.p4.y)*FRCC.p2.y+FRCC.p1.y*FRCC.p4.y))*FRCC.p1.x+(-(FRCC.p1.y-FRCC.p3.y)*((FRCC.p1.y+FRCC.p3.y)*FRCC.p2.y-2*FRCC.p1.y*FRCC.p3.y)*FRCC.p2.x-FRCC.p3.x*FRCC.p3.y*(FRCC.p1.y-FRCC.p2.y)*(FRCC.p1.y-FRCC.p2.y))*FRCC.p4.x*FRCC.p4.x +
           (((2*FRCC.p1.y-FRCC.p4.y)*FRCC.p3.y*FRCC.p3.y-2*FRCC.p1.y*FRCC.p1.y*FRCC.p3.y+FRCC.p1.y*FRCC.p1.y*FRCC.p4.y)*FRCC.p2.x*FRCC.p2.x+2*FRCC.p1.y*FRCC.p3.x*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p2.x+FRCC.p4.y*FRCC.p3.x*FRCC.p3.x*(FRCC.p1.y-FRCC.p2.y)*(FRCC.p1.y-FRCC.p2.y))*FRCC.p4.x+FRCC.p2.x*FRCC.p3.x*(FRCC.p1.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p4.y)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x));
    im1.ty=-(((FRCC.p2.y-FRCC.p3.y)*FRCC.p1.x+(FRCC.p3.x-FRCC.p2.x)*FRCC.p1.y+FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x)*(FRCC.p4.y*FRCC.p1.x-FRCC.p4.x*FRCC.p1.y)*((FRCC.p2.y-FRCC.p3.y)*FRCC.p4.x+(FRCC.p3.x-FRCC.p2.x)*FRCC.p4.y+FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x)*f64Height) /
            ((-FRCC.p4.y*(FRCC.p2.y-FRCC.p3.y)*(FRCC.p2.y-FRCC.p3.y)*FRCC.p4.x+(FRCC.p2.x*FRCC.p2.y-2*(FRCC.p2.y-0.5*FRCC.p3.y)*FRCC.p3.x)*FRCC.p4.y*FRCC.p4.y+2*(FRCC.p2.y*FRCC.p2.y*FRCC.p3.x-FRCC.p3.y*FRCC.p2.y*FRCC.p2.x)*FRCC.p4.y+FRCC.p2.y*FRCC.p3.y*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x))*FRCC.p1.x*FRCC.p1.x +
            (((FRCC.p2.y-FRCC.p3.y)*(FRCC.p2.y-FRCC.p3.y)*FRCC.p4.x*FRCC.p4.x+2*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x)*FRCC.p4.x-(FRCC.p2.x-FRCC.p3.x)*(FRCC.p2.x-FRCC.p3.x)*FRCC.p4.y*FRCC.p4.y+2*(FRCC.p2.x*FRCC.p2.x*FRCC.p3.y-FRCC.p3.x*FRCC.p2.y*FRCC.p2.x)*FRCC.p4.y-FRCC.p2.x*FRCC.p2.x*FRCC.p3.y*FRCC.p3.y +
            FRCC.p2.y*FRCC.p2.y*FRCC.p3.x*FRCC.p3.x)*FRCC.p1.y+2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x))*FRCC.p1.x+(((2*FRCC.p3.y-FRCC.p2.y)*FRCC.p2.x-FRCC.p3.y*FRCC.p3.x)*FRCC.p4.x*FRCC.p4.x+((FRCC.p2.x-FRCC.p3.x)*(FRCC.p2.x-FRCC.p3.x)*FRCC.p4.y +
            2*FRCC.p3.x*FRCC.p2.y*FRCC.p2.x-2*FRCC.p2.x*FRCC.p2.x*FRCC.p3.y)*FRCC.p4.x+FRCC.p2.x*FRCC.p3.x*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x))*FRCC.p1.y*FRCC.p1.y-2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.x-FRCC.p4.x)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x)*FRCC.p1.y+(FRCC.p3.x*FRCC.p4.y -
            FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.x*FRCC.p4.y-FRCC.p4.x*FRCC.p2.y)*(FRCC.p2.x*FRCC.p3.y-FRCC.p2.y*FRCC.p3.x));
    im1.w0=(((FRCC.p3.x-FRCC.p4.x)*(FRCC.p3.x-FRCC.p4.x)*FRCC.p2.y+(FRCC.p2.x-FRCC.p4.x)*(FRCC.p2.x-2*FRCC.p3.x+FRCC.p4.x)*FRCC.p3.y-(FRCC.p2.x-FRCC.p3.x)*(FRCC.p2.x-FRCC.p3.x)*FRCC.p4.y)*FRCC.p1.y*FRCC.p1.y+(-(FRCC.p3.x-FRCC.p4.x)*(FRCC.p3.x-FRCC.p4.x)*FRCC.p2.y*FRCC.p2.y-2*(FRCC.p3.y-FRCC.p4.y)*(FRCC.p2.x-FRCC.p4.x) *
           (FRCC.p1.x-FRCC.p3.x)*FRCC.p2.y+2*(FRCC.p2.x-FRCC.p4.x)*(FRCC.p1.x-0.5*FRCC.p2.x-0.5*FRCC.p4.x)*FRCC.p3.y*FRCC.p3.y-2*FRCC.p4.y*(FRCC.p2.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p3.x)*FRCC.p3.y+(FRCC.p2.x-FRCC.p3.x)*(FRCC.p2.x-FRCC.p3.x)*FRCC.p4.y*FRCC.p4.y)*FRCC.p1.y +
           ((FRCC.p1.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y-(FRCC.p1.x-FRCC.p3.x)*FRCC.p4.y*(FRCC.p1.x-2*FRCC.p4.x+FRCC.p3.x))*FRCC.p2.y*FRCC.p2.y+(-(FRCC.p1.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y*FRCC.p3.y+2*FRCC.p4.y*(FRCC.p2.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p3.x)*FRCC.p3.y +
           FRCC.p4.y*FRCC.p4.y*(FRCC.p1.x-FRCC.p3.x)*(FRCC.p1.x-2*FRCC.p2.x+FRCC.p3.x))*FRCC.p2.y+FRCC.p3.y*FRCC.p4.y*(FRCC.p1.x-FRCC.p2.x)*(FRCC.p1.x-FRCC.p2.x)*(FRCC.p3.y-FRCC.p4.y))/((-FRCC.p2.x*(FRCC.p3.x-FRCC.p4.x)*(FRCC.p3.x-FRCC.p4.x)*FRCC.p2.y+((FRCC.p3.x-2*FRCC.p4.x)*FRCC.p2.x+FRCC.p3.x*FRCC.p4.x)*(FRCC.p2.x-FRCC.p4.x)*FRCC.p3.y+FRCC.p4.x*FRCC.p4.y*(FRCC.p2.x-FRCC.p3.x)*(FRCC.p2.x-FRCC.p3.x))*FRCC.p1.y*FRCC.p1.y+(FRCC.p1.x*(FRCC.p3.x-FRCC.p4.x)*(FRCC.p3.x-FRCC.p4.x)*FRCC.p2.y*FRCC.p2.y-2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y)*(FRCC.p2.x-FRCC.p4.x) *
           (FRCC.p1.x-FRCC.p3.x)*FRCC.p2.y-(FRCC.p2.x-FRCC.p4.x)*((FRCC.p2.x+FRCC.p4.x)*FRCC.p1.x-2*FRCC.p2.x*FRCC.p4.x)*FRCC.p3.y*FRCC.p3.y+2*FRCC.p2.x*FRCC.p4.y*(FRCC.p2.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p3.x)*FRCC.p3.y-FRCC.p4.y*FRCC.p4.y*FRCC.p1.x*(FRCC.p2.x-FRCC.p3.x)*(FRCC.p2.x-FRCC.p3.x))*FRCC.p1.y +
           (-FRCC.p3.x*(FRCC.p1.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y+2*FRCC.p4.y*((FRCC.p3.x-0.5*FRCC.p4.x)*FRCC.p1.x-0.5*FRCC.p3.x*FRCC.p4.x)*(FRCC.p1.x-FRCC.p3.x))*FRCC.p2.y*FRCC.p2.y+(FRCC.p2.x*(FRCC.p1.x-FRCC.p4.x)*(FRCC.p1.x-FRCC.p4.x)*FRCC.p3.y*FRCC.p3.y-2*FRCC.p1.x*FRCC.p4.y*(FRCC.p2.x-FRCC.p4.x) *
           (FRCC.p1.x-FRCC.p3.x)*FRCC.p3.y+FRCC.p4.y*FRCC.p4.y*((FRCC.p2.x-2*FRCC.p3.x)*FRCC.p1.x+FRCC.p2.x*FRCC.p3.x)*(FRCC.p1.x-FRCC.p3.x))*FRCC.p2.y+FRCC.p4.y*FRCC.p3.y*(FRCC.p1.x-FRCC.p2.x)*(FRCC.p1.x-FRCC.p2.x)*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y));
    im1.w1=((-(FRCC.p3.y-FRCC.p4.y)*(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x-(FRCC.p2.y-FRCC.p4.y)*(FRCC.p2.y-2*FRCC.p3.y+FRCC.p4.y)*FRCC.p3.x+FRCC.p4.x*(FRCC.p2.y-FRCC.p3.y)*(FRCC.p2.y-FRCC.p3.y))*FRCC.p1.x*FRCC.p1.x+((FRCC.p3.y-FRCC.p4.y)*(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x*FRCC.p2.x+2*(FRCC.p3.x-FRCC.p4.x) *
           (FRCC.p2.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p2.x-2*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p1.y-0.5*FRCC.p2.y-0.5*FRCC.p4.y)*FRCC.p3.x*FRCC.p3.x+2*FRCC.p4.x*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p3.x -
           (FRCC.p2.y-FRCC.p3.y)*(FRCC.p2.y-FRCC.p3.y)*FRCC.p4.x*FRCC.p4.x)*FRCC.p1.x+(-(FRCC.p1.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p4.y)*FRCC.p3.x+FRCC.p4.x*(FRCC.p1.y-FRCC.p3.y)*(FRCC.p1.y-2*FRCC.p4.y+FRCC.p3.y))*FRCC.p2.x*FRCC.p2.x+((FRCC.p1.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p4.y)*FRCC.p3.x*FRCC.p3.x-2*FRCC.p4.x*(FRCC.p2.y-FRCC.p4.y) *
           (FRCC.p1.y-FRCC.p3.y)*FRCC.p3.x-FRCC.p4.x*FRCC.p4.x*(FRCC.p1.y-FRCC.p3.y)*(FRCC.p1.y-2*FRCC.p2.y+FRCC.p3.y))*FRCC.p2.x-FRCC.p3.x*FRCC.p4.x*(FRCC.p1.y-FRCC.p2.y)*(FRCC.p1.y-FRCC.p2.y)*(FRCC.p3.x-FRCC.p4.x))/((FRCC.p2.y*(FRCC.p3.y-FRCC.p4.y)*(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x-((FRCC.p3.y-2*FRCC.p4.y)*FRCC.p2.y+FRCC.p4.y*FRCC.p3.y)*(FRCC.p2.y-FRCC.p4.y)*FRCC.p3.x-FRCC.p4.y*(FRCC.p2.y-FRCC.p3.y)*(FRCC.p2.y-FRCC.p3.y)*FRCC.p4.x)*FRCC.p1.x*FRCC.p1.x+(-FRCC.p1.y*(FRCC.p3.y-FRCC.p4.y)*(FRCC.p3.y-FRCC.p4.y)*FRCC.p2.x*FRCC.p2.x-2*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y) *
           (FRCC.p2.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p2.x+((FRCC.p2.y+FRCC.p4.y)*FRCC.p1.y-2*FRCC.p2.y*FRCC.p4.y)*(FRCC.p2.y-FRCC.p4.y)*FRCC.p3.x*FRCC.p3.x-2*FRCC.p2.y*FRCC.p4.x*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p3.x+FRCC.p1.y*FRCC.p4.x*FRCC.p4.x *
           (FRCC.p2.y-FRCC.p3.y)*(FRCC.p2.y-FRCC.p3.y))*FRCC.p1.x+(FRCC.p3.y*(FRCC.p1.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p4.y)*FRCC.p3.x-2*((FRCC.p3.y-0.5*FRCC.p4.y)*FRCC.p1.y-0.5*FRCC.p4.y*FRCC.p3.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p4.x)*FRCC.p2.x*FRCC.p2.x+(-FRCC.p2.y*(FRCC.p1.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p4.y)*FRCC.p3.x*FRCC.p3.x +
           2*FRCC.p1.y*FRCC.p4.x*(FRCC.p2.y-FRCC.p4.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p3.x-((FRCC.p2.y-2*FRCC.p3.y)*FRCC.p1.y+FRCC.p3.y*FRCC.p2.y)*(FRCC.p1.y-FRCC.p3.y)*FRCC.p4.x*FRCC.p4.x)*FRCC.p2.x+FRCC.p3.x*FRCC.p4.x*(FRCC.p1.y-FRCC.p2.y)*(FRCC.p1.y-FRCC.p2.y)*(FRCC.p3.x*FRCC.p4.y-FRCC.p4.x*FRCC.p3.y));
    im1.w2=1.0;

    im1.sx  = im1.sx  - im1.tx*im1.w0;
    im1.shx = im1.shx - im1.tx*im1.w1;
    im1.tx  = 0.0;

    im1.shy = im1.shy - im1.ty*im1.w0;
    im1.sy  = im1.sy  - im1.ty*im1.w1;
    im1.ty  = 0.0;

    im1 = RE_SCALEMATRIX(im1, 2097151.0/RE_MAXMATRIXELEMENT(im1));

    im1.sx  = round(im1.sx);
    im1.shx = round(im1.shx);
    im1.shy = round(im1.shy);
    im1.sy  = round(im1.sy);
    im1.w0  = round(im1.w0);
    im1.w1  = round(im1.w1);
    im1.w2  = round(im1.w2);

    return(im1);
}


/****************************************************************************/

/* calculate truncated double */
static float64_t RE_FLOAT64TRUNC(float64_t x)
{
    return ((float64_t)((long long)(x)));
}


/****************************************************************************/

static void RE_TRANSLATEOBJECT(int32_t * offset, GA_SCREENOBJ_t * FRCC, float64_t * original)
{
    float64_t minX;
    float64_t minY;
    uint32_t  i;

    minX = original[4*0 + 0];
    for (i=1; i<4; i++)
    {
        if (original[4*i + 0] < minX)
        {
            minX = original[4*i + 0];
        }
    }

    minY = original[4*0 + 1];
    for (i=1; i<4; i++)
    {
        if (original[4*i + 1] < minY)
        {
            minY = original[4*i + 1];
        }
    }

    offset[0] = (int32_t)RE_FLOAT64TRUNC(RE_FLOAT64ROUND(minX*4294967296.0)/4294967296);
    offset[1] = (int32_t)RE_FLOAT64TRUNC(RE_FLOAT64ROUND(minY*4294967296.0)/4294967296);

    FRCC->p1.x = original[0]  - offset[0];
    FRCC->p1.y = original[1]  - offset[1];
    FRCC->p2.x = original[4]  - offset[0];
    FRCC->p2.y = original[5]  - offset[1];
    FRCC->p3.x = original[8]  - offset[0];
    FRCC->p3.y = original[9]  - offset[1];
    FRCC->p4.x = original[12] - offset[0];
    FRCC->p4.y = original[13] - offset[1];
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
static void vRotLib_CalculateForwardRotatedCornerCoordinates_RotateFull(rot_mem_st* pstMem, 
                                                                 int16_t i16RotCentX, int16_t i16RotCentY, 
                                                                 int16_t i16OffsetX, int16_t i16OffsetY, 
                                                                 rot_frccr_st* pstCoord, float64_t f64Angle)
#else
static void vRotLib_CalculateForwardRotatedCornerCoordinates_RotateFull(rot_mem_st* pstMem, 
                                                                 int16_t i16RotCentX, int16_t i16RotCentY, 
                                                                 int16_t i16OffsetX, int16_t i16OffsetY, 
                                                                 rot_frccr_st* pstCoord, int16_t i16Angle)
#endif
{
#ifdef GA_USE_MATH_LIB
    float64_t f64AngRad;
    float64_t f64Sin,f64Cos;
#else
    int32_t   i32Sin, i32Cos;
#endif  
    rot_frccr_st stCoordlocal;
    uint16_t     u16PixelOffset;

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */

    u16PixelOffset = 1;
    if( (pstMem->u16SrcHeight == 1) && (pstMem->u16SrcWidth == 1) )
    {
        u16PixelOffset = 0;
    }

#ifdef GA_USE_MATH_LIB

    /* Angle Conversion to radians */
    f64AngRad = (2.0 * GA_CONST_PI * f64Angle)/360.0 ;
    
    /* Calculate only once Sine and Cosine */
    f64Sin = ROT_SIN(f64AngRad);
    f64Cos = ROT_COS(f64AngRad);

    /* Forward Rotated Coordinates Calculation */
    /* From Source Img. point (0, 0) */
    stCoordlocal.u16X1 = RE_FLOAT64TOUINT32((((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Cos)
                                   - ((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Sin))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetX));

    stCoordlocal.u16Y1 = RE_FLOAT64TOUINT32((((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Sin)
                                   + ((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Cos))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetY));

    /* From Source Img. point (0, Image_Height-PixelOffset) */
    stCoordlocal.u16X2 = RE_FLOAT64TOUINT32((((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Cos)
                                   - ((16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentY)* f64Sin))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetX));

    stCoordlocal.u16Y2 = RE_FLOAT64TOUINT32((((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Sin)
                                   + ((16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Cos))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetY));

    /* From Source Img. point (Image_Width-PixelOffset, Image_Height-PixelOffset) */
    stCoordlocal.u16X3 = RE_FLOAT64TOUINT32((((16.0 * (float64_t)(pstMem->u16SrcWidth-u16PixelOffset)  - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Cos)
                                   - ((16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Sin))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetX));

    stCoordlocal.u16Y3 = RE_FLOAT64TOUINT32((((16.0 * (float64_t)(pstMem->u16SrcWidth-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Sin)
                                   + ((16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Cos))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetY));

    /* From Source Img. point (Image_Width-PixelOffset, 0) */
    stCoordlocal.u16X4 = RE_FLOAT64TOUINT32((((16.0 * (float64_t)(pstMem->u16SrcWidth-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Cos)
                                   - ((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Sin))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetX));

    stCoordlocal.u16Y4 = RE_FLOAT64TOUINT32((((16.0 * (float64_t)(pstMem->u16SrcWidth-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Sin)
                                   + ((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Cos))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetY));

#else
   
    /* Calculate only once Sine and Cosine */
    i32Sin = ROT_SIN(i16Angle);
    i32Cos = ROT_COS(i16Angle);
   
    /* Forward Rotated Coordinates Calculation */
    /* From Source Img. point (0, 0) */
    stCoordlocal.u16X1 = (uint32_t)(((((16U * 0U - u32SubResCPos * i16RotCentX) * i32Cos)
                                    - ((16U * 0U - u32SubResCPos * i16RotCentY) * i32Sin))
                                    + (u32SubResPPos * i16OffsetX * 65536U)) / 65536U);
    
    stCoordlocal.u16Y1 = (uint32_t)(((((16U * 0U - u32SubResCPos * i16RotCentX) * i32Sin)
                                    + ((16U * 0U - u32SubResCPos * i16RotCentY) * i32Cos))
                                    + (u32SubResPPos * i16OffsetY * 65536U)) / 65536U);
    
    /* From Source Img. point (0, Image_Height-PixelOffset) */
    stCoordlocal.u16X2 = (uint32_t)(((((16U * 0U - u32SubResCPos * i16RotCentX) * i32Cos)
                                    - ((16U * (pstMem->u16SrcHeight-u16PixelOffset) - u32SubResCPos * i16RotCentY)* i32Sin))
                                    + (u32SubResPPos * i16OffsetX * 65536U)) / 65536U);

    stCoordlocal.u16Y2 = (uint32_t)(((((16U * 0U - u32SubResCPos * i16RotCentX) * i32Sin)
                                    + ((16U * (pstMem->u16SrcHeight-u16PixelOffset) - u32SubResCPos * i16RotCentY) * i32Cos))
                                    + (u32SubResPPos * i16OffsetY * 65536U)) / 65536U);

    /* From Source Img. point (Image_Width-PixelOffset, Image_Height-PixelOffset) */
    stCoordlocal.u16X3 = (uint32_t)(((((16U * (pstMem->u16SrcWidth-u16PixelOffset) - u32SubResCPos * i16RotCentX) * i32Cos)
                                    - ((16U * (pstMem->u16SrcHeight-u16PixelOffset) - u32SubResCPos * i16RotCentY) * i32Sin))
                                    + (u32SubResPPos * i16OffsetX * 65536U)) / 65536U);

    stCoordlocal.u16Y3 = (uint32_t)(((((16U * (pstMem->u16SrcWidth-u16PixelOffset) - u32SubResCPos * i16RotCentX) * i32Sin)
                                    + ((16U * (pstMem->u16SrcHeight-u16PixelOffset) - u32SubResCPos * i16RotCentY) * i32Cos))
                                    + (u32SubResPPos * i16OffsetY * 65536U)) / 65536U);

    /* From Source Img. point (Image_Width-PixelOffset, 0) */
    stCoordlocal.u16X4 = (uint32_t)(((((16U * (pstMem->u16SrcWidth-u16PixelOffset) - u32SubResCPos * i16RotCentX) * i32Cos)
                                    - ((16U * 0U - u32SubResCPos * i16RotCentY) * i32Sin))
                                    + (u32SubResPPos * i16OffsetX * 65536U)) / 65536U);

    stCoordlocal.u16Y4 = (uint32_t)(((((16U * (pstMem->u16SrcWidth-u16PixelOffset) - u32SubResCPos * i16RotCentX) * i32Sin)
                                    + ((16U * 0U - u32SubResCPos * i16RotCentY) * i32Cos))
                                    + (u32SubResPPos * i16OffsetY * 65536U)) / 65536U);

#endif /* GA_USE_MATH_LIB */

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

    /* save calculated coordinates for later usage in a glocal array: */
    vSaveGlFwRotCornerCoord(&stCoordlocal);

    /* Coordinate Sorting */
#ifdef GA_USE_MATH_LIB    
    if(f64Angle < 90.0)
#else
    if(i16Angle < 900U)
#endif
    {
        pstCoord -> u16X1 = stCoordlocal.u16X1;
        pstCoord -> u16Y1 = stCoordlocal.u16Y1;
        pstCoord -> u16X2 = stCoordlocal.u16X2;
        pstCoord -> u16Y2 = stCoordlocal.u16Y2;
        pstCoord -> u16X3 = stCoordlocal.u16X3;
        pstCoord -> u16Y3 = stCoordlocal.u16Y3;
        pstCoord -> u16X4 = stCoordlocal.u16X4;
        pstCoord -> u16Y4 = stCoordlocal.u16Y4;

        pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR1;
    }
#ifdef GA_USE_MATH_LIB        
    else if(f64Angle < 180.0)
#else
    else if(i16Angle < 1800U)
#endif
    {
        pstCoord -> u16X1 = stCoordlocal.u16X2;
        pstCoord -> u16Y1 = stCoordlocal.u16Y2;
        pstCoord -> u16X2 = stCoordlocal.u16X3;
        pstCoord -> u16Y2 = stCoordlocal.u16Y3;
        pstCoord -> u16X3 = stCoordlocal.u16X4;
        pstCoord -> u16Y3 = stCoordlocal.u16Y4;
        pstCoord -> u16X4 = stCoordlocal.u16X1;
        pstCoord -> u16Y4 = stCoordlocal.u16Y1;

        pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR4;
    }
#ifdef GA_USE_MATH_LIB     
    else if (f64Angle < 270.0)
#else
    else if (i16Angle < 2700U)
#endif
    {
        pstCoord -> u16X1 = stCoordlocal.u16X3;
        pstCoord -> u16Y1 = stCoordlocal.u16Y3;
        pstCoord -> u16X2 = stCoordlocal.u16X4;
        pstCoord -> u16Y2 = stCoordlocal.u16Y4;
        pstCoord -> u16X3 = stCoordlocal.u16X1;
        pstCoord -> u16Y3 = stCoordlocal.u16Y1;
        pstCoord -> u16X4 = stCoordlocal.u16X2;
        pstCoord -> u16Y4 = stCoordlocal.u16Y2;

        pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR3;
    }
    else
    {
        pstCoord -> u16X1 = stCoordlocal.u16X4;
        pstCoord -> u16Y1 = stCoordlocal.u16Y4;
        pstCoord -> u16X2 = stCoordlocal.u16X1;
        pstCoord -> u16Y2 = stCoordlocal.u16Y1;
        pstCoord -> u16X3 = stCoordlocal.u16X2;
        pstCoord -> u16Y3 = stCoordlocal.u16Y2;
        pstCoord -> u16X4 = stCoordlocal.u16X3;
        pstCoord -> u16Y4 = stCoordlocal.u16Y3;

        pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR2;
    }
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
static void vRotLib_CalculateForwardRotatedCornerCoordinates_RotatePart(rot_mem_part_st* pstMem, 
                                                                 int16_t i16RotCentX, int16_t i16RotCentY, 
                                                                 int16_t i16OffsetX, int16_t i16OffsetY, 
                                                                 rot_frccr_st* pstCoord, float64_t f64Angle)
#else
static void vRotLib_CalculateForwardRotatedCornerCoordinates_RotatePart(rot_mem_part_st* pstMem, 
                                                                 int16_t i16RotCentX, int16_t i16RotCentY, 
                                                                 int16_t i16OffsetX, int16_t i16OffsetY, 
                                                                 rot_frccr_st* pstCoord, int16_t i16Angle)
#endif

{
#ifdef GA_USE_MATH_LIB
    float64_t f64AngRad;
    float64_t f64Sin,f64Cos;
#else
    int32_t   i32Sin, i32Cos;
#endif  
    rot_frccr_st stCoordlocal;
    uint16_t     u16PixelOffset;

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */

    u16PixelOffset = 1;
    if( (pstMem->u16SrcHeight == 1) && (pstMem->u16DotCnt == 1) )
    {
        u16PixelOffset = 0;
    }

#ifdef GA_USE_MATH_LIB

    /* Angle Conversion to radians */
    f64AngRad = (2 * GA_CONST_PI * f64Angle)/360.0 ;

    /* Calculate only once Sine and Cosine */
    f64Sin = ROT_SIN(f64AngRad);
    f64Cos = ROT_COS(f64AngRad);

    /* Forward Rotated Coordinates Calculation */
    /* From Source Img. point (0, 0) */
    stCoordlocal.u16X1 = RE_FLOAT64TOUINT32((((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Cos)
                                   - ((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Sin))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetX));
    
    stCoordlocal.u16Y1 = RE_FLOAT64TOUINT32((((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Sin)
                                   + ((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Cos))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetY));
    
    /* From Source Img. point (0, Image_Height-PixelOffset) */
    stCoordlocal.u16X2 = RE_FLOAT64TOUINT32((((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Cos)
                                   - ((16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentY)* f64Sin))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetX));

    stCoordlocal.u16Y2 = RE_FLOAT64TOUINT32((((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Sin)
                                   + ((16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Cos))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetY));

    /* From Source Img. point (DotCnt-PixelOffset, Image_Height-PixelOffset) */
    stCoordlocal.u16X3 = RE_FLOAT64TOUINT32((((16.0 * (float64_t)(pstMem->u16DotCnt-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Cos)
                                   - ((16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Sin))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetX));

    stCoordlocal.u16Y3 = RE_FLOAT64TOUINT32((((16.0 * (float64_t)(pstMem->u16DotCnt-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Sin)
                                   + ((16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Cos))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetY));

    /* From Source Img. point (DotCnt-1, 0) */
    stCoordlocal.u16X4 = RE_FLOAT64TOUINT32((((16.0 * (float64_t)(pstMem->u16DotCnt-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Cos)
                                   - ((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Sin))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetX));

    stCoordlocal.u16Y4 = RE_FLOAT64TOUINT32((((16.0 * (float64_t)(pstMem->u16DotCnt-u16PixelOffset) - (float64_t)f32SubResCPos * (float64_t)i16RotCentX) * f64Sin)
                                   + ((16.0 * 0.0 - (float64_t)f32SubResCPos * (float64_t)i16RotCentY) * f64Cos))
                                   + ((float64_t)f32SubResPPos * (float64_t)i16OffsetY));

#else
   
    /* Calculate only once Sine and Cosine */
    i32Sin = ROT_SIN(i16Angle);
    i32Cos = ROT_COS(i16Angle);
   
    /* Forward Rotated Coordinates Calculation */
    /* From Source Img. point (0, 0) */
    stCoordlocal.u16X1 = (uint32_t)(((((16U * 0U - u32SubResCPos * i16RotCentX) * i32Cos)
                                    - ((16U * 0U - u32SubResCPos * i16RotCentY) * i32Sin))
                                    + (u32SubResPPos * i16OffsetX * 65536U)) / 65536U);
    
    stCoordlocal.u16Y1 = (uint32_t)(((((16U * 0U - u32SubResCPos * i16RotCentX) * i32Sin)
                                    + ((16U * 0U - u32SubResCPos * i16RotCentY) * i32Cos))
                                    + (u32SubResPPos * i16OffsetY * 65536U)) / 65536U);
    
    /* From Source Img. point (0, Image_Height-PixelOffset) */
    stCoordlocal.u16X2 = (uint32_t)(((((16U * 0U - u32SubResCPos * i16RotCentX) * i32Cos)
                                    - ((16U * (pstMem->u16SrcHeight-u16PixelOffset) - u32SubResCPos * i16RotCentY)* i32Sin))
                                    + (u32SubResPPos * i16OffsetX * 65536U)) / 65536U);

    stCoordlocal.u16Y2 = (uint32_t)(((((16U * 0U - u32SubResCPos * i16RotCentX) * i32Sin)
                                    + ((16U * (pstMem->u16SrcHeight-u16PixelOffset) - u32SubResCPos * i16RotCentY) * i32Cos))
                                    + (u32SubResPPos * i16OffsetY * 65536U)) / 65536U);

    /* From Source Img. point (DotCnt-PixelOffset, Image_Height-PixelOffset) */
    stCoordlocal.u16X3 = (uint32_t)(((((16U * (pstMem->u16DotCnt-u16PixelOffset) - u32SubResCPos * i16RotCentX) * i32Cos)
                                    - ((16U * (pstMem->u16SrcHeight-u16PixelOffset) - u32SubResCPos * i16RotCentY) * i32Sin))
                                    + (u32SubResPPos * i16OffsetX * 65536U)) / 65536U);

    stCoordlocal.u16Y3 = (uint32_t)(((((16U * (pstMem->u16DotCnt-u16PixelOffset) - u32SubResCPos * i16RotCentX) * i32Sin)
                                    + ((16U * (pstMem->u16SrcHeight-u16PixelOffset) - u32SubResCPos * i16RotCentY) * i32Cos))
                                    + (u32SubResPPos * i16OffsetY * 65536U)) / 65536U);

    /* From Source Img. point (DotCnt-PixelOffset, 0) */
    stCoordlocal.u16X4 = (uint32_t)(((((16U * (pstMem->u16DotCnt-u16PixelOffset) - u32SubResCPos * i16RotCentX) * i32Cos)
                                    - ((16U * 0U - u32SubResCPos * i16RotCentY) * i32Sin))
                                    + (u32SubResPPos * i16OffsetX * 65536U)) / 65536U);

    stCoordlocal.u16Y4 = (uint32_t)(((((16U * (pstMem->u16DotCnt-u16PixelOffset) - u32SubResCPos * i16RotCentX) * i32Sin)
                                    + ((16U * 0U - u32SubResCPos * i16RotCentY) * i32Cos))
                                    + (u32SubResPPos * i16OffsetY * 65536U)) / 65536U);
    
#endif

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

    /* save calculated coordinates for later usage in a glocal array: */
    vSaveGlFwRotCornerCoord(&stCoordlocal);

    /* Coordinate Sorting */
#ifdef GA_USE_MATH_LIB
    if(f64Angle < 90.0)
#else
    if(i16Angle < 900U)
#endif
    {
        pstCoord -> u16X1 = stCoordlocal.u16X1;
        pstCoord -> u16Y1 = stCoordlocal.u16Y1;
        pstCoord -> u16X2 = stCoordlocal.u16X2;
        pstCoord -> u16Y2 = stCoordlocal.u16Y2;
        pstCoord -> u16X3 = stCoordlocal.u16X3;
        pstCoord -> u16Y3 = stCoordlocal.u16Y3;
        pstCoord -> u16X4 = stCoordlocal.u16X4;
        pstCoord -> u16Y4 = stCoordlocal.u16Y4;

        pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR1;
    }
#ifdef GA_USE_MATH_LIB    
    else if(f64Angle < 180.0)
#else
    else if(i16Angle < 1800U)
#endif
    {
        pstCoord -> u16X1 = stCoordlocal.u16X2;
        pstCoord -> u16Y1 = stCoordlocal.u16Y2;
        pstCoord -> u16X2 = stCoordlocal.u16X3;
        pstCoord -> u16Y2 = stCoordlocal.u16Y3;
        pstCoord -> u16X3 = stCoordlocal.u16X4;
        pstCoord -> u16Y3 = stCoordlocal.u16Y4;
        pstCoord -> u16X4 = stCoordlocal.u16X1;
        pstCoord -> u16Y4 = stCoordlocal.u16Y1;

        pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR4;
    }
#ifdef GA_USE_MATH_LIB    
    else if (f64Angle < 270.0)
#else
    else if (i16Angle < 2700U)
#endif
    {
        pstCoord -> u16X1 = stCoordlocal.u16X3;
        pstCoord -> u16Y1 = stCoordlocal.u16Y3;
        pstCoord -> u16X2 = stCoordlocal.u16X4;
        pstCoord -> u16Y2 = stCoordlocal.u16Y4;
        pstCoord -> u16X3 = stCoordlocal.u16X1;
        pstCoord -> u16Y3 = stCoordlocal.u16Y1;
        pstCoord -> u16X4 = stCoordlocal.u16X2;
        pstCoord -> u16Y4 = stCoordlocal.u16Y2;

        pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR3;
    }
    else
    {
        pstCoord -> u16X1 = stCoordlocal.u16X4;
        pstCoord -> u16Y1 = stCoordlocal.u16Y4;
        pstCoord -> u16X2 = stCoordlocal.u16X1;
        pstCoord -> u16Y2 = stCoordlocal.u16Y1;
        pstCoord -> u16X3 = stCoordlocal.u16X2;
        pstCoord -> u16Y3 = stCoordlocal.u16Y2;
        pstCoord -> u16X4 = stCoordlocal.u16X3;
        pstCoord -> u16Y4 = stCoordlocal.u16Y3;

        pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR2;
    }
}


/****************************************************************************/

static void vRotLib_CalculateForwardRotatedCornerCoordinates_Shear(rot_mem_st* pstMem, 
                                                            int16_t i16OffsetX, int16_t i16OffsetY, 
                                                            float64_t f64FactorX, float64_t f64FactorY, 
                                                            rot_frccr_st* pstCoord)
{
    rot_frccr_st   stCoordlocal;
    GA_SCREENOBJ_t sortedFRCC;
    uint16_t       u16PixelOffset;

    u16PixelOffset = 1;
    if( (pstMem->u16SrcWidth == 1) && (pstMem->u16SrcHeight == 1) )
    {
        u16PixelOffset = 0;
    }

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
    /* Forward Rotated Coordinates Calculation */
    stCoordlocal.u16X1 = RE_FLOAT64TOUINT32((float64_t)f32SubResPPos * (float64_t)i16OffsetX);
    stCoordlocal.u16Y1 = RE_FLOAT64TOUINT32((float64_t)f32SubResPPos * (float64_t)i16OffsetY);

    stCoordlocal.u16X2 = RE_FLOAT64TOUINT32((float64_t)stCoordlocal.u16X1 + (16.0 * (f64FactorX * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset))));
    stCoordlocal.u16Y2 = stCoordlocal.u16Y1 + 16U * (pstMem->u16SrcHeight-u16PixelOffset);

    stCoordlocal.u16X3 = stCoordlocal.u16X2 + 16U * (pstMem->u16SrcWidth-u16PixelOffset);
    stCoordlocal.u16Y3 = RE_FLOAT64TOUINT32((float64_t)stCoordlocal.u16Y2 + (16.0 * (f64FactorY * (float64_t)(pstMem->u16SrcWidth-u16PixelOffset))));

    stCoordlocal.u16X4 = stCoordlocal.u16X1 + 16U * (pstMem->u16SrcWidth-u16PixelOffset);
    stCoordlocal.u16Y4 = RE_FLOAT64TOUINT32((float64_t)stCoordlocal.u16Y1 + (16.0 * (f64FactorY * (float64_t)(pstMem->u16SrcWidth-u16PixelOffset))));

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */
    
    /* save calculated coordinates for later usage in a glocal array: */
    vSaveGlFwRotCornerCoord(&stCoordlocal);

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1847    /* MISRA 2004 Rule 10.3 */
#endif /* defined(__GHS__) || defined(__ghs__) */
    /* Coordinate Sorting */
    sortedFRCC.p1.x = (float64_t)(int16_t)(stCoordlocal.u16X1 + 0xFFFFU + 0x1U);
    sortedFRCC.p1.y = (float64_t)(int16_t)(stCoordlocal.u16Y1 + 0xFFFFU + 0x1U);
    sortedFRCC.p2.x = (float64_t)(int16_t)(stCoordlocal.u16X2 + 0xFFFFU + 0x1U);
    sortedFRCC.p2.y = (float64_t)(int16_t)(stCoordlocal.u16Y2 + 0xFFFFU + 0x1U);
    sortedFRCC.p3.x = (float64_t)(int16_t)(stCoordlocal.u16X3 + 0xFFFFU + 0x1U);
    sortedFRCC.p3.y = (float64_t)(int16_t)(stCoordlocal.u16Y3 + 0xFFFFU + 0x1U);
    sortedFRCC.p4.x = (float64_t)(int16_t)(stCoordlocal.u16X4 + 0xFFFFU + 0x1U);
    sortedFRCC.p4.y = (float64_t)(int16_t)(stCoordlocal.u16Y4 + 0xFFFFU + 0x1U);
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

	/* sort corners as required by RE and get start corner */
    pstCoord -> u8ScrAddrPos  = (uint8_t)RE_SORTCORNERS(&sortedFRCC) - 1;

    pstCoord->u16X1 = (uint16_t)sortedFRCC.p1.x;
    pstCoord->u16Y1 = (uint16_t)sortedFRCC.p1.y;
    pstCoord->u16X2 = (uint16_t)sortedFRCC.p2.x;
    pstCoord->u16Y2 = (uint16_t)sortedFRCC.p2.y;
	pstCoord->u16X3 = (uint16_t)sortedFRCC.p3.x;
	pstCoord->u16Y3 = (uint16_t)sortedFRCC.p3.y;
    pstCoord->u16X4 = (uint16_t)sortedFRCC.p4.x;
    pstCoord->u16Y4 = (uint16_t)sortedFRCC.p4.y;
    
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
static void vRotLib_CalculateForwardRotatedCornerCoordinates_Scale(rot_mem_st* pstMem,
                                                            int16_t i16OffsetX, int16_t i16OffsetY,
                                                            float64_t f64FactorX, float64_t f64FactorY,
                                                            rot_scaleAlign_e eAlignment, rot_frccr_st* pstCoord)
#else
static void vRotLib_CalculateForwardRotatedCornerCoordinates_Scale(rot_mem_st* pstMem,
                                                            int16_t i16OffsetX, int16_t i16OffsetY,
                                                            int32_t i32FactorX, int32_t i32FactorY,
                                                            rot_scaleAlign_e eAlignment, rot_frccr_st* pstCoord)
#endif
{
    rot_frccr_st stCoordlocal;
    uint32_t     u32DiffX, u32DiffY;
    uint16_t     u16CorrectionX, u16CorrectionY;
    uint16_t     u16PixelOffset;

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */

    u16PixelOffset = 1;
    if( (pstMem->u16SrcHeight == 1) && (pstMem->u16SrcWidth == 1) )
    {
        u16PixelOffset = 0;
    }

#ifdef GA_USE_MATH_LIB

    /* Forward Rotated Coordinates Calculation */
    stCoordlocal.u16X1 = RE_FLOAT64TOUINT32((float64_t)f32SubResPPos * (float64_t)i16OffsetX);
    stCoordlocal.u16Y1 = RE_FLOAT64TOUINT32((float64_t)f32SubResPPos * (float64_t)i16OffsetY);

    stCoordlocal.u16X2 = stCoordlocal.u16X1;
    stCoordlocal.u16Y2 = RE_FLOAT64TOUINT32((float64_t)stCoordlocal.u16Y1 + (16.0 * (float64_t)(pstMem->u16SrcHeight-u16PixelOffset) * f64FactorY));

    stCoordlocal.u16X3 = RE_FLOAT64TOUINT32((float64_t)stCoordlocal.u16X2 + (16.0 * f64FactorX * (float64_t)(pstMem->u16SrcWidth-u16PixelOffset)));
    stCoordlocal.u16Y3 = stCoordlocal.u16Y2;

    stCoordlocal.u16X4 = stCoordlocal.u16X3;
    stCoordlocal.u16Y4 = stCoordlocal.u16Y1;

    /* 1 pixel value is needed to later get the correct size of the image */
    u16CorrectionX     = 16.0*u16PixelOffset*f64FactorX;
    u16CorrectionY     = 16.0*u16PixelOffset*f64FactorY;

#else

    /* Forward Rotated Coordinates Calculation */
    stCoordlocal.u16X1 = u32SubResPPos * i16OffsetX;
    stCoordlocal.u16Y1 = u32SubResPPos * i16OffsetY;

    stCoordlocal.u16X2 = stCoordlocal.u16X1;
    stCoordlocal.u16Y2 = (stCoordlocal.u16Y1 + ((16U * (pstMem->u16SrcHeight-u16PixelOffset) * i32FactorY) / 65536U));

    stCoordlocal.u16X3 = (stCoordlocal.u16X2 + ((16U * i32FactorX * (pstMem->u16SrcWidth-u16PixelOffset)) / 65536U));
    stCoordlocal.u16Y3 = stCoordlocal.u16Y2;

    stCoordlocal.u16X4 = stCoordlocal.u16X3;
    stCoordlocal.u16Y4 = stCoordlocal.u16Y1;

    /* 1 pixel value is needed to later get the correct size of the image */
    u16CorrectionX     = 16.0*u16PixelOffset*i32FactorX/65536;
    u16CorrectionY     = 16.0*u16PixelOffset*i32FactorY/65536;

#endif

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

#ifdef GA_USE_MATH_LIB
    if (!((f64FactorX > 1.0) || (f64FactorY > 1.0)))
#else
    if (!((i32FactorX > 65536U) || (i32FactorY > 65536U)))
#endif
    {
        switch (eAlignment)
        {
            case ROT_SCALE_ALIGN_W0:
                u32DiffX = 16U * pstMem->u16SrcWidth - (stCoordlocal.u16X3 - stCoordlocal.u16X1 + u16CorrectionX);
                stCoordlocal.u16X1 = stCoordlocal.u16X1 + u32DiffX;
                stCoordlocal.u16X2 = stCoordlocal.u16X2 + u32DiffX;
                stCoordlocal.u16X3 = stCoordlocal.u16X3 + u32DiffX;
                stCoordlocal.u16X4 = stCoordlocal.u16X4 + u32DiffX;
                break;
            case ROT_SCALE_ALIGN_0H:
                u32DiffY = 16U * pstMem->u16SrcHeight - (stCoordlocal.u16Y3 - stCoordlocal.u16Y1 + u16CorrectionY);
                stCoordlocal.u16Y1 = stCoordlocal.u16Y1 + u32DiffY;
                stCoordlocal.u16Y2 = stCoordlocal.u16Y2 + u32DiffY;
                stCoordlocal.u16Y3 = stCoordlocal.u16Y3 + u32DiffY;
                stCoordlocal.u16Y4 = stCoordlocal.u16Y4 + u32DiffY;
                break;
            case ROT_SCALE_ALIGN_WH:
                u32DiffX = 16U * pstMem->u16SrcWidth  - (stCoordlocal.u16X3 - stCoordlocal.u16X1 + u16CorrectionX);
                u32DiffY = 16U * pstMem->u16SrcHeight - (stCoordlocal.u16Y3 - stCoordlocal.u16Y1 + u16CorrectionY);
                stCoordlocal.u16X1 = stCoordlocal.u16X1 + u32DiffX;
                stCoordlocal.u16Y1 = stCoordlocal.u16Y1 + u32DiffY;
                stCoordlocal.u16X2 = stCoordlocal.u16X2 + u32DiffX;
                stCoordlocal.u16Y2 = stCoordlocal.u16Y2 + u32DiffY;
                stCoordlocal.u16X3 = stCoordlocal.u16X3 + u32DiffX;
                stCoordlocal.u16Y3 = stCoordlocal.u16Y3 + u32DiffY;
                stCoordlocal.u16X4 = stCoordlocal.u16X4 + u32DiffX;
                stCoordlocal.u16Y4 = stCoordlocal.u16Y4 + u32DiffY;
                break;
            case ROT_SCALE_ALIGN_CC:
                u32DiffX = (((16U * pstMem->u16SrcWidth)  - (int16_t)((int16_t)(stCoordlocal.u16X3) - (int16_t)(stCoordlocal.u16X1) + (int16_t)(u16CorrectionX) )) >> 1U);
                u32DiffY = (((16U * pstMem->u16SrcHeight) - (int16_t)((int16_t)(stCoordlocal.u16Y3) - (int16_t)(stCoordlocal.u16Y1) + (int16_t)(u16CorrectionY) )) >> 1U);
                stCoordlocal.u16X1 = stCoordlocal.u16X1 + u32DiffX;
                stCoordlocal.u16Y1 = stCoordlocal.u16Y1 + u32DiffY;
                stCoordlocal.u16X2 = stCoordlocal.u16X2 + u32DiffX;
                stCoordlocal.u16Y2 = stCoordlocal.u16Y2 + u32DiffY;
                stCoordlocal.u16X3 = stCoordlocal.u16X3 + u32DiffX;
                stCoordlocal.u16Y3 = stCoordlocal.u16Y3 + u32DiffY;
                stCoordlocal.u16X4 = stCoordlocal.u16X4 + u32DiffX;
                stCoordlocal.u16Y4 = stCoordlocal.u16Y4 + u32DiffY;
                break;
            default: /* upper left */
                ;
        }
    }

    /* save calculated coordinates for later usage in a glocal array: */
    vSaveGlFwRotCornerCoord(&stCoordlocal);
    
    /* Forward Rotated Coordinates */
    pstCoord -> u16X1 = stCoordlocal.u16X1;
    pstCoord -> u16Y1 = stCoordlocal.u16Y1;
    pstCoord -> u16X2 = stCoordlocal.u16X2;
    pstCoord -> u16Y2 = stCoordlocal.u16Y2;
    pstCoord -> u16X3 = stCoordlocal.u16X3;
    pstCoord -> u16Y3 = stCoordlocal.u16Y3;
    pstCoord -> u16X4 = stCoordlocal.u16X4;
    pstCoord -> u16Y4 = stCoordlocal.u16Y4;

    pstCoord -> u8ScrAddrPos = (uint8_t) GA_FRCCR1;
}


/****************************************************************************/

static void vRotLib_CheckForNegativeCoordinates(rot_mem_st* pstMem, rot_rotCfg_st* pstParam, rot_frccr_st* pstCoord)
{
    uint16_t  u16CoordinateX, u16CoordinateY;
    uint16_t  u16UpX, u16UpY;
    int16_t   i16CoordinateX, i16CoordinateY, i16Coordinate2, i16Coordinate3, i16Coordinate4;

    /* check if one coordinate in x-direction is negative */
    u16CoordinateX = 0U;
    if ((pstCoord->u16X1 > 0x8000U) || (pstCoord->u16X2 > 0x8000U) || (pstCoord->u16X3 > 0x8000U) || (pstCoord->u16X4 > 0x8000U))
    {
        /* get most negative coordinate */
        i16CoordinateX = pstCoord->u16X1 + 0xFFFFU + 0x1U;
        i16Coordinate2 = pstCoord->u16X2 + 0xFFFFU + 0x1U;
        i16Coordinate3 = pstCoord->u16X3 + 0xFFFFU + 0x1U;
        i16Coordinate4 = pstCoord->u16X4 + 0xFFFFU + 0x1U;
        if (i16CoordinateX > i16Coordinate2) {i16CoordinateX = i16Coordinate2;}
        if (i16CoordinateX > i16Coordinate3) {i16CoordinateX = i16Coordinate3;}
        if (i16CoordinateX > i16Coordinate4) {i16CoordinateX = i16Coordinate4;}
        u16CoordinateX = i16CoordinateX + 0xFFFFU + 0x1U;

        /* update x coordinates */
        u16CoordinateX = 0xFFFFU - u16CoordinateX + 1U;
        u16UpX = 16U*((u16CoordinateX>>4U) + 1U);
        pstCoord->u16X1 = pstCoord->u16X1 + u16UpX;
        pstCoord->u16X2 = pstCoord->u16X2 + u16UpX;
        pstCoord->u16X3 = pstCoord->u16X3 + u16UpX;
        pstCoord->u16X4 = pstCoord->u16X4 + u16UpX;
    }

    /* check if one coordinate in y-direction is negative */
    u16CoordinateY = 0U;
    if ((pstCoord->u16Y1 > 0x8000U) || (pstCoord->u16Y2 > 0x8000U) || (pstCoord->u16Y3 > 0x8000U) || (pstCoord->u16Y4 > 0x8000U))
    {
        /* get most negative coordinate */
        i16CoordinateY = pstCoord->u16Y1 + 0xFFFFU + 0x1U;
        i16Coordinate2 = pstCoord->u16Y2 + 0xFFFFU + 0x1U;
        i16Coordinate3 = pstCoord->u16Y3 + 0xFFFFU + 0x1U;
        i16Coordinate4 = pstCoord->u16Y4 + 0xFFFFU + 0x1U;
        if (i16CoordinateY > i16Coordinate2) {i16CoordinateY = i16Coordinate2;}
        if (i16CoordinateY > i16Coordinate3) {i16CoordinateY = i16Coordinate3;}
        if (i16CoordinateY > i16Coordinate4) {i16CoordinateY = i16Coordinate4;}
        u16CoordinateY = i16CoordinateY + 0xFFFFU + 0x1U;

        /* update y coordinates */
        u16CoordinateY = 0xFFFFU - u16CoordinateY + 1U;
        u16UpY = 16U*((u16CoordinateY>>4U) + 1U);
        pstCoord->u16Y1 = pstCoord->u16Y1 + u16UpY;
        pstCoord->u16Y2 = pstCoord->u16Y2 + u16UpY;
        pstCoord->u16Y3 = pstCoord->u16Y3 + u16UpY;
        pstCoord->u16Y4 = pstCoord->u16Y4 + u16UpY;

        /* update Dst-image height */
        pstMem->u16DstImgHeight = pstMem->u16DstImgHeight + (u16CoordinateY >> 4U);
    }

    /* if negative coordinates are available */
    if ((u16CoordinateX != 0U) || (u16CoordinateY != 0U))
    {
        /* extract pixel */
        if (u16CoordinateX != 0U)
        {
            u16CoordinateX = (u16CoordinateX >> 4U) + 1U;
        }
        if (u16CoordinateY != 0U)
        {
            u16CoordinateY = (u16CoordinateY >> 4U) + 1U;
        }

        /* update Dst-image startaddress */
        if (pstParam->eDstColFmt == GA_RGB16)
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr - 2U*u16CoordinateY*pstMem->u16DstImgWidth - 2U*u16CoordinateX;
        }
        else
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr - 4U*u16CoordinateY*pstMem->u16DstImgWidth - 4U*u16CoordinateX;
        }

        /* update clipwindow */
        if (pstParam->eClipWndEn == GA_EN)
        {
            pstParam->tClipWnd.u16UlX = pstParam->tClipWnd.u16UlX + u16CoordinateX;
            pstParam->tClipWnd.u16UlY = pstParam->tClipWnd.u16UlY + u16CoordinateY;
            pstParam->tClipWnd.u16LrX = (uint16_t)RE_MIN((pstParam->tClipWnd.u16LrX + u16CoordinateX), (pstMem->u16DstImgWidth-1U));
            pstParam->tClipWnd.u16LrY = (uint16_t)RE_MIN((pstParam->tClipWnd.u16LrY + u16CoordinateY), (pstMem->u16DstImgHeight-1U));
        }
        else
        {
            pstParam->eClipWndEn = GA_EN;
            pstParam->tClipWnd.u16UlX = u16CoordinateX;
            pstParam->tClipWnd.u16UlY = u16CoordinateY;
            pstParam->tClipWnd.u16LrX = (pstMem->u16DstImgWidth-1U);
            pstParam->tClipWnd.u16LrY = (pstMem->u16DstImgHeight-1U);
        }
    }

    /* set clipwindow if image is overlapping upper border */
    if (((pstCoord->u16Y1>>4U) >= pstMem->u16DstImgHeight) ||
        ((pstCoord->u16Y2>>4U) >= pstMem->u16DstImgHeight) ||
        ((pstCoord->u16Y3>>4U) >= pstMem->u16DstImgHeight) ||
        ((pstCoord->u16Y4>>4U) >= pstMem->u16DstImgHeight))
    {
        if (pstParam->eClipWndEn != GA_EN)
        {
            pstParam->eClipWndEn = GA_EN;
            pstParam->tClipWnd.u16UlX = u16CoordinateX;
            pstParam->tClipWnd.u16UlY = u16CoordinateY;
            pstParam->tClipWnd.u16LrX = (pstMem->u16DstImgWidth-1U)  + u16CoordinateX;
            pstParam->tClipWnd.u16LrY = (pstMem->u16DstImgHeight-1U) + u16CoordinateY;
        }
    }
}


/****************************************************************************/

static void vRotLib_CheckForNegativeCoordinatesBlend(rot_mem_st* pstMem, rot_rotblendCfg_st* pstParam, rot_frccr_st* pstCoord)
{
    uint16_t  u16CoordinateX, u16CoordinateY;
    uint16_t  u16UpX, u16UpY;
    int16_t   i16CoordinateX, i16CoordinateY, i16Coordinate2, i16Coordinate3, i16Coordinate4;

    /* check if one coordinate in x-direction is negative */
    u16CoordinateX = 0U;
    if ((pstCoord->u16X1 > 0x8000U) || (pstCoord->u16X2 > 0x8000U) || (pstCoord->u16X3 > 0x8000U) || (pstCoord->u16X4 > 0x8000U))
    {
        /* get most negative coordinate */
        i16CoordinateX = pstCoord->u16X1 + 0xFFFFU + 0x1U;
        i16Coordinate2 = pstCoord->u16X2 + 0xFFFFU + 0x1U;
        i16Coordinate3 = pstCoord->u16X3 + 0xFFFFU + 0x1U;
        i16Coordinate4 = pstCoord->u16X4 + 0xFFFFU + 0x1U;
        if (i16CoordinateX > i16Coordinate2) {i16CoordinateX = i16Coordinate2;}
        if (i16CoordinateX > i16Coordinate3) {i16CoordinateX = i16Coordinate3;}
        if (i16CoordinateX > i16Coordinate4) {i16CoordinateX = i16Coordinate4;}
        u16CoordinateX = i16CoordinateX + 0xFFFFU + 0x1U;

        /* update x coordinates */
        u16CoordinateX = 0xFFFFU - u16CoordinateX + 1U;
        u16UpX = 16U*((u16CoordinateX>>4U) + 1U);
        pstCoord->u16X1 = pstCoord->u16X1 + u16UpX;
        pstCoord->u16X2 = pstCoord->u16X2 + u16UpX;
        pstCoord->u16X3 = pstCoord->u16X3 + u16UpX;
        pstCoord->u16X4 = pstCoord->u16X4 + u16UpX;
    }

    /* check if one coordinate in y-direction is negative */
    u16CoordinateY = 0U;
    if ((pstCoord->u16Y1 > 0x8000U) || (pstCoord->u16Y2 > 0x8000U) || (pstCoord->u16Y3 > 0x8000U) || (pstCoord->u16Y4 > 0x8000U))
    {
        /* get most negative coordinate */
        i16CoordinateY = pstCoord->u16Y1 + 0xFFFFU + 0x1U;
        i16Coordinate2 = pstCoord->u16Y2 + 0xFFFFU + 0x1U;
        i16Coordinate3 = pstCoord->u16Y3 + 0xFFFFU + 0x1U;
        i16Coordinate4 = pstCoord->u16Y4 + 0xFFFFU + 0x1U;
        if (i16CoordinateY > i16Coordinate2) {i16CoordinateY = i16Coordinate2;}
        if (i16CoordinateY > i16Coordinate3) {i16CoordinateY = i16Coordinate3;}
        if (i16CoordinateY > i16Coordinate4) {i16CoordinateY = i16Coordinate4;}
        u16CoordinateY = i16CoordinateY + 0xFFFFU + 0x1U;

        /* update y coordinates */
        u16CoordinateY = 0xFFFFU - u16CoordinateY + 1U;
        u16UpY = 16U*((u16CoordinateY>>4U) + 1U);
        pstCoord->u16Y1 = pstCoord->u16Y1 + u16UpY;
        pstCoord->u16Y2 = pstCoord->u16Y2 + u16UpY;
        pstCoord->u16Y3 = pstCoord->u16Y3 + u16UpY;
        pstCoord->u16Y4 = pstCoord->u16Y4 + u16UpY;

        /* update Dst-image height */
        pstMem->u16DstImgHeight = pstMem->u16DstImgHeight + (u16CoordinateY >> 4U);
    }

    /* if negative coordinates are available */
    if ((u16CoordinateX != 0U) || (u16CoordinateY != 0U))
    {
        /* extract pixel */
        if (u16CoordinateX != 0U)
        {
            u16CoordinateX = (u16CoordinateX >> 4U) + 1U;
        }
        if (u16CoordinateY != 0U)
        {
            u16CoordinateY = (u16CoordinateY >> 4U) + 1U;
        }

        /* update Dst-image startaddress */
        if (pstParam->eDstColFmt == GA_RGB16)
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr - 2U*u16CoordinateY*pstMem->u16DstImgWidth - 2U*u16CoordinateX;
        }
        else
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr - 4U*u16CoordinateY*pstMem->u16DstImgWidth - 4U*u16CoordinateX;
        }

        /* update clipwindow */
        if (pstParam->eClipWndEn == GA_EN)
        {
            pstParam->tClipWnd.u16UlX = pstParam->tClipWnd.u16UlX + u16CoordinateX;
            pstParam->tClipWnd.u16UlY = pstParam->tClipWnd.u16UlY + u16CoordinateY;
            pstParam->tClipWnd.u16LrX = pstParam->tClipWnd.u16LrX + u16CoordinateX;
            pstParam->tClipWnd.u16LrY = pstParam->tClipWnd.u16LrY + u16CoordinateY;
        }
        else
        {
            pstParam->eClipWndEn = GA_EN;
            pstParam->tClipWnd.u16UlX = u16CoordinateX;
            pstParam->tClipWnd.u16UlY = u16CoordinateY;
            pstParam->tClipWnd.u16LrX = (pstMem->u16DstImgWidth-1U)  + u16CoordinateX;
            pstParam->tClipWnd.u16LrY = (pstMem->u16DstImgHeight-1U) + u16CoordinateY;
        }
    }

    /* set clipwindow if image is overlapping upper border */
    if (((pstCoord->u16Y1>>4U) >= pstMem->u16DstImgHeight) ||
        ((pstCoord->u16Y2>>4U) >= pstMem->u16DstImgHeight) ||
        ((pstCoord->u16Y3>>4U) >= pstMem->u16DstImgHeight) ||
        ((pstCoord->u16Y4>>4U) >= pstMem->u16DstImgHeight))
    {
        if (pstParam->eClipWndEn != GA_EN)
        {
            pstParam->eClipWndEn = GA_EN;
            pstParam->tClipWnd.u16UlX = u16CoordinateX;
            pstParam->tClipWnd.u16UlY = u16CoordinateY;
            pstParam->tClipWnd.u16LrX = (pstMem->u16DstImgWidth-1U)  + u16CoordinateX;
            pstParam->tClipWnd.u16LrY = (pstMem->u16DstImgHeight-1U) + u16CoordinateY;
        }
    }
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vRotLib_Rotate(rot_mem_st* pstMem, rot_cfg_st* pstParam, float64_t f64Angle, ga_list_st* pstCmdList)
#else
void vRotLib_Rotate(rot_mem_st* pstMem, rot_cfg_st* pstParam, int16_t   i16Angle, ga_list_st* pstCmdList)
#endif
{
    rot_Mtrx_st    stMatrix;
    rot_frccr_st   stCoord;

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateTransformationMatrix_Rotate(&stMatrix, f64Angle);
#else
    vRotLib_CalculateTransformationMatrix_Rotate(&stMatrix, i16Angle);
#endif

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateForwardRotatedCornerCoordinates_RotateFull(pstMem, pstParam->i16RotCentX, pstParam->i16RotCentY, 
                                                                pstParam->i16OffsetX, pstParam->i16OffsetY, &stCoord, f64Angle);
#else
    vRotLib_CalculateForwardRotatedCornerCoordinates_RotateFull(pstMem, pstParam->i16RotCentX, pstParam->i16RotCentY, 
                                                                pstParam->i16OffsetX, pstParam->i16OffsetY, &stCoord, i16Angle);
#endif

    vRotLib_CheckForNegativeCoordinates(pstMem, &pstParam->stRotCfg, &stCoord);

    if(pstParam->stRotCfg.eClipWndEn == GA_DIS)
    {
        /* RE expects atleast 2 pixels to overlap with the draw region. When the clip window is disabled, and the 
        coordinates are also positive, it might so happen that all the 4 (Y coords >> 4) are 0. i.e they Y coord of 
        all 4 points lie on Y = 0;. In such cases RE hangs. Since this is an extreme and it does not occur so often,
        this block of  coded might affect the performance */
        
        pstParam->stRotCfg.eClipWndEn = GA_EN;
        pstParam->stRotCfg.tClipWnd.u16UlX = 0;
        pstParam->stRotCfg.tClipWnd.u16UlY = 0;
        pstParam->stRotCfg.tClipWnd.u16LrX = pstMem->u16DstImgWidth - 1U;
        pstParam->stRotCfg.tClipWnd.u16LrY = pstMem->u16DstImgHeight - 1U;
    }
    if(vRotLib_CheckForOverlap(&stCoord, &pstParam->stRotCfg.tClipWnd, pstParam->stRotCfg.eClipWndEn) == GA_EN)
    {
        vRot_RotateMatrix(pstMem, &pstParam->stRotCfg, &stMatrix, &stCoord, pstCmdList);
    }
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vRotLib_Rotate_Part(rot_mem_part_st* pstMem, rot_cfg_st* pstParam, float64_t f64Angle, ga_list_st* pstCmdList)
#else
void vRotLib_Rotate_Part(rot_mem_part_st* pstMem, rot_cfg_st* pstParam, int16_t   i16Angle, ga_list_st* pstCmdList)
#endif
{
    rot_mem_st    stMem_local;
    rot_Mtrx_st   stMatrix;
    rot_frccr_st  stCoord;

    #ifdef GA_USE_MATH_LIB
    vRotLib_CalculateTransformationMatrix_Rotate(&stMatrix, f64Angle);
#else
    vRotLib_CalculateTransformationMatrix_Rotate(&stMatrix, i16Angle);
#endif

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateForwardRotatedCornerCoordinates_RotatePart(pstMem, 
                                                                pstParam->i16RotCentX, pstParam->i16RotCentY, 
                                                                pstParam->i16OffsetX,  pstParam->i16OffsetY, 
                                                                &stCoord, f64Angle);
#else
    vRotLib_CalculateForwardRotatedCornerCoordinates_RotatePart(pstMem, 
                                                                pstParam->i16RotCentX, pstParam->i16RotCentY, 
                                                                pstParam->i16OffsetX,  pstParam->i16OffsetY, 
                                                                &stCoord, i16Angle);
#endif
    stMem_local.u16SrcHeight    = pstMem->u16SrcHeight;
    stMem_local.u16SrcWidth     = pstMem->u16SrcWidth;
    stMem_local.u32SrcAddr      = pstMem->u32SrcAddr;
    stMem_local.u32DstAddr      = pstMem->u32DstAddr;
    stMem_local.u16DstImgWidth  = pstMem->u16DstImgWidth;
    stMem_local.u16DstImgHeight = pstMem->u16DstImgHeight;

    vRotLib_CheckForNegativeCoordinates(&stMem_local, &pstParam->stRotCfg, &stCoord);
    if(pstParam->stRotCfg.eClipWndEn == GA_DIS)
    {
        /* RE expects atleast 2 pixels to overlap with the draw region. When the clip window is disabled, and the 
        coordinates are also positive, it might so happen that all the 4 (Y coords >> 4) are 0. i.e they Y coord of 
        all 4 points lie on Y = 0;. In such cases RE hangs. Since this is an extreme and it does not occur so often,
        this block of  coded might affect the performance */
        
        pstParam->stRotCfg.eClipWndEn = GA_EN;
        pstParam->stRotCfg.tClipWnd.u16UlX = 0;
        pstParam->stRotCfg.tClipWnd.u16UlY = 0;
        pstParam->stRotCfg.tClipWnd.u16LrX = pstMem->u16DstImgWidth - 1U;
        pstParam->stRotCfg.tClipWnd.u16LrY = pstMem->u16DstImgHeight - 1U;
    }
    
    if(vRotLib_CheckForOverlap(&stCoord, &pstParam->stRotCfg.tClipWnd, pstParam->stRotCfg.eClipWndEn) == GA_EN)
    {
        vRot_RotateMatrix(&stMem_local, &pstParam->stRotCfg, &stMatrix, &stCoord, pstCmdList);
    }
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vRotLib_RotateBlend(rot_mem_st* pstMem, rot_blendcfg_st* pstParam, float64_t f64Angle, ga_list_st* pstCmdList)
#else
void vRotLib_RotateBlend(rot_mem_st* pstMem, rot_blendcfg_st* pstParam, int16_t   i16Angle, ga_list_st* pstCmdList)
#endif
{
    rot_Mtrx_st   stMatrix;
    rot_frccr_st  stCoord;

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateTransformationMatrix_Rotate(&stMatrix, f64Angle);
#else
    vRotLib_CalculateTransformationMatrix_Rotate(&stMatrix, i16Angle);
#endif

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateForwardRotatedCornerCoordinates_RotateFull(pstMem, pstParam->i16RotCentX, pstParam->i16RotCentY, 
                                                                pstParam->i16OffsetX, pstParam->i16OffsetY, &stCoord, f64Angle);
#else
    vRotLib_CalculateForwardRotatedCornerCoordinates_RotateFull(pstMem, pstParam->i16RotCentX, pstParam->i16RotCentY, 
                                                                pstParam->i16OffsetX, pstParam->i16OffsetY, &stCoord, i16Angle);
#endif

    vRotLib_CheckForNegativeCoordinatesBlend(pstMem, &pstParam->stRotBlendCfg, &stCoord);

    if(pstParam->stRotBlendCfg.eClipWndEn == GA_DIS)
    {
        /* RE expects atleast 2 pixels to overlap with the draw region. When the clip window is disabled, and the 
        coordinates are also positive, it might so happen that all the 4 (Y coords >> 4) are 0. i.e they Y coord of 
        all 4 points lie on Y = 0;. In such cases RE hangs. Since this is an extreme and it does not occur so often,
        this block of  coded might affect the performance */
        
        pstParam->stRotBlendCfg.eClipWndEn = GA_EN;
        pstParam->stRotBlendCfg.tClipWnd.u16UlX = 0;
        pstParam->stRotBlendCfg.tClipWnd.u16UlY = 0;
        pstParam->stRotBlendCfg.tClipWnd.u16LrX = pstMem->u16DstImgWidth - 1U;
        pstParam->stRotBlendCfg.tClipWnd.u16LrY = pstMem->u16DstImgHeight - 1U;
    }
    
    if(vRotLib_CheckForOverlap(&stCoord, &pstParam->stRotBlendCfg.tClipWnd, pstParam->stRotBlendCfg.eClipWndEn) == GA_EN)
    {
        vRot_RotateBlendMatrix(pstMem, &pstParam->stRotBlendCfg, &stMatrix, &stCoord, pstCmdList);
    }
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB 
void vRotLib_RotateBlend_Part(rot_mem_part_st* pstMem, rot_blendcfg_st* pstParam, float64_t f64Angle, ga_list_st* pstCmdList)
#else
void vRotLib_RotateBlend_Part(rot_mem_part_st* pstMem, rot_blendcfg_st* pstParam, int16_t   i16Angle, ga_list_st* pstCmdList)
#endif
{
    rot_mem_st    stMem_local;
    rot_Mtrx_st   stMatrix;
    rot_frccr_st  stCoord;

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateTransformationMatrix_Rotate(&stMatrix, f64Angle);
#else
    vRotLib_CalculateTransformationMatrix_Rotate(&stMatrix, i16Angle);
#endif

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateForwardRotatedCornerCoordinates_RotatePart(pstMem, 
                                                                pstParam->i16RotCentX, pstParam->i16RotCentY, 
                                                                pstParam->i16OffsetX,  pstParam->i16OffsetY, 
                                                                &stCoord, f64Angle);
#else
    vRotLib_CalculateForwardRotatedCornerCoordinates_RotatePart(pstMem, 
                                                                pstParam->i16RotCentX, pstParam->i16RotCentY, 
                                                                pstParam->i16OffsetX,  pstParam->i16OffsetY, 
                                                                &stCoord, i16Angle);
#endif
    stMem_local.u16SrcHeight    = pstMem->u16SrcHeight;
    stMem_local.u16SrcWidth     = pstMem->u16SrcWidth;
    stMem_local.u32SrcAddr      = pstMem->u32SrcAddr;
    stMem_local.u32DstAddr      = pstMem->u32DstAddr;
    stMem_local.u16DstImgWidth  = pstMem->u16DstImgWidth;
    stMem_local.u16DstImgHeight = pstMem->u16DstImgHeight;

    vRotLib_CheckForNegativeCoordinatesBlend(&stMem_local, &pstParam->stRotBlendCfg, &stCoord);

    if(pstParam->stRotBlendCfg.eClipWndEn == GA_DIS)
    {
        /* RE expects atleast 2 pixels to overlap with the draw region. When the clip window is disabled, and the 
        coordinates are also positive, it might so happen that all the 4 (Y coords >> 4) are 0. i.e they Y coord of 
        all 4 points lie on Y = 0;. In such cases RE hangs. Since this is an extreme and it does not occur so often,
        this block of  coded might affect the performance */
        
        pstParam->stRotBlendCfg.eClipWndEn = GA_EN;
        pstParam->stRotBlendCfg.tClipWnd.u16UlX = 0;
        pstParam->stRotBlendCfg.tClipWnd.u16UlY = 0;
        pstParam->stRotBlendCfg.tClipWnd.u16LrX = pstMem->u16DstImgWidth - 1U;
        pstParam->stRotBlendCfg.tClipWnd.u16LrY = pstMem->u16DstImgHeight - 1U;
    }
    if(vRotLib_CheckForOverlap(&stCoord, &pstParam->stRotBlendCfg.tClipWnd, pstParam->stRotBlendCfg.eClipWndEn) == GA_EN)
    {
        vRot_RotateBlendMatrix(&stMem_local, &pstParam->stRotBlendCfg, &stMatrix, &stCoord, pstCmdList);
    }
}


/****************************************************************************/

void vRotLib_Shear(rot_mem_st* pstMem, rot_sscalCfg_st* pstParam, ga_list_st* pstCmdList)
{
    rot_cfg_st    stParam_local;
    rot_Mtrx_st   stMatrix;
    rot_frccr_st  stCoord;

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateTransformationMatrix_Shear(&stMatrix, pstParam->f64FactorX, pstParam->f64FactorY);
    vRotLib_CalculateForwardRotatedCornerCoordinates_Shear(pstMem, 
                                                           pstParam->i16OffsetX, pstParam->i16OffsetY, 
                                                           pstParam->f64FactorX, pstParam->f64FactorY, 
                                                           &stCoord);
#else
    vRotLib_CalculateTransformationMatrix_Shear(&stMatrix, pstParam->i32FactorX, pstParam->i32FactorY);
    vRotLib_CalculateForwardRotatedCornerCoordinates_Shear(pstMem, 
                                                           pstParam->i16OffsetX, pstParam->i16OffsetY, 
                                                           pstParam->i32FactorX, pstParam->i32FactorY, 
                                                           &stCoord);
#endif

    stParam_local.stRotCfg.eSrcColFmt    = pstParam->eSrcColFmt;
    stParam_local.stRotCfg.eDstColFmt    = pstParam->eDstColFmt;
    stParam_local.stRotCfg.eClipWndEn    = pstParam->eClipWndEn;
    stParam_local.stRotCfg.eFilterEn     = pstParam->eFilterEn;
    stParam_local.i16RotCentX            = 0U;
    stParam_local.i16RotCentY            = 0U;
    stParam_local.i16OffsetX             = pstParam->i16OffsetX;
    stParam_local.i16OffsetY             = pstParam->i16OffsetY;
    stParam_local.stRotCfg.u8FadingFctr  = pstParam->u8FadingFctr;
    stParam_local.stRotCfg.u8SrcAlphaVal = pstParam->u8SrcAlphaVal;
    stParam_local.stRotCfg.u8DstAlphaVal = pstParam->u8DstAlphaVal;
    stParam_local.stRotCfg.tClipWnd      = pstParam->tClipWnd;

    vRotLib_CheckForNegativeCoordinates(pstMem, &stParam_local.stRotCfg, &stCoord);

    if(stParam_local.stRotCfg.eClipWndEn == GA_DIS)
    {
        /* RE expects atleast 2 pixels to overlap with the draw region. When the clip window is disabled, and the 
        coordinates are also positive, it might so happen that all the 4 (Y coords >> 4) are 0. i.e they Y coord of 
        all 4 points lie on Y = 0;. In such cases RE hangs. Since this is an extreme and it does not occur so often,
        this block of  coded might affect the performance */
        
        stParam_local.stRotCfg.eClipWndEn = GA_EN;
        stParam_local.stRotCfg.tClipWnd.u16UlX = 0;
        stParam_local.stRotCfg.tClipWnd.u16UlY = 0;
        stParam_local.stRotCfg.tClipWnd.u16LrX = pstMem->u16DstImgWidth - 1U;
        stParam_local.stRotCfg.tClipWnd.u16LrY = pstMem->u16DstImgHeight - 1U;
    }
    if(vRotLib_CheckForOverlap(&stCoord, &stParam_local.stRotCfg.tClipWnd, stParam_local.stRotCfg.eClipWndEn) == GA_EN)
    {
        vRot_RotateMatrix(pstMem, &stParam_local.stRotCfg, &stMatrix, &stCoord, pstCmdList);
    }
}


/****************************************************************************/

void vRotLib_ShearBlend(rot_mem_st* pstMem, rot_sscalblendCfg_st* pstParam, ga_list_st* pstCmdList)
{
    rot_blendcfg_st  stParam_local;
    rot_Mtrx_st      stMatrix;
    rot_frccr_st     stCoord;

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateTransformationMatrix_Shear(&stMatrix, pstParam->f64FactorX, pstParam->f64FactorY);
    vRotLib_CalculateForwardRotatedCornerCoordinates_Shear(pstMem, 
                                                           pstParam->i16OffsetX, pstParam->i16OffsetY, 
                                                           pstParam->f64FactorX, pstParam->f64FactorY, 
                                                           &stCoord);
#else
    vRotLib_CalculateTransformationMatrix_Shear(&stMatrix, pstParam->i32FactorX, pstParam->i32FactorY);
    vRotLib_CalculateForwardRotatedCornerCoordinates_Shear(pstMem, 
                                                           pstParam->i16OffsetX, pstParam->i16OffsetY, 
                                                           pstParam->i32FactorX, pstParam->i32FactorY, 
                                                           &stCoord);
#endif

    stParam_local.stRotBlendCfg.eSrcColFmt    = pstParam->eSrcColFmt;
    stParam_local.stRotBlendCfg.eDstColFmt    = pstParam->eDstColFmt;
    stParam_local.stRotBlendCfg.eClipWndEn    = pstParam->eClipWndEn;
    stParam_local.stRotBlendCfg.eFilterEn     = pstParam->eFilterEn;
    stParam_local.i16RotCentX                 = 0U;
    stParam_local.i16RotCentY                 = 0U;
    stParam_local.i16OffsetX                  = pstParam->i16OffsetX;
    stParam_local.i16OffsetY                  = pstParam->i16OffsetY;
    stParam_local.stRotBlendCfg.eDstRedProt   = pstParam->eDstRedProt;
    stParam_local.stRotBlendCfg.eDstGreenProt = pstParam->eDstGreenProt;
    stParam_local.stRotBlendCfg.eDstBlueProt  = pstParam->eDstBlueProt;
    stParam_local.stRotBlendCfg.eDstAlphaProt = pstParam->eDstAlphaProt;
    stParam_local.stRotBlendCfg.eSrcRedFad    = pstParam->eSrcRedFad;
    stParam_local.stRotBlendCfg.eSrcGreenFad  = pstParam->eSrcGreenFad;
    stParam_local.stRotBlendCfg.eSrcBlueFad   = pstParam->eSrcBlueFad;
    stParam_local.stRotBlendCfg.eSrcAlphaFad  = pstParam->eSrcAlphaFad;
    stParam_local.stRotBlendCfg.u8FadingFctr  = pstParam->u8FadingFctr;
    stParam_local.stRotBlendCfg.eBldOrd       = pstParam->eBldOrd;
    stParam_local.stRotBlendCfg.u8SrcAlphaVal = pstParam->u8SrcAlphaVal;
    stParam_local.stRotBlendCfg.u8DstAlphaVal = pstParam->u8DstAlphaVal;
    stParam_local.stRotBlendCfg.tClipWnd      = pstParam->tClipWnd;

    vRotLib_CheckForNegativeCoordinatesBlend(pstMem, &stParam_local.stRotBlendCfg, &stCoord);

    if(stParam_local.stRotBlendCfg.eClipWndEn == GA_DIS)
    {
        /* RE expects atleast 2 pixels to overlap with the draw region. When the clip window is disabled, and the 
        coordinates are also positive, it might so happen that all the 4 (Y coords >> 4) are 0. i.e they Y coord of 
        all 4 points lie on Y = 0;. In such cases RE hangs. Since this is an extreme and it does not occur so often,
        this block of  coded might affect the performance */
        
        stParam_local.stRotBlendCfg.eClipWndEn = GA_EN;
        stParam_local.stRotBlendCfg.tClipWnd.u16UlX = 0;
        stParam_local.stRotBlendCfg.tClipWnd.u16UlY = 0;
        stParam_local.stRotBlendCfg.tClipWnd.u16LrX = pstMem->u16DstImgWidth - 1U;
        stParam_local.stRotBlendCfg.tClipWnd.u16LrY = pstMem->u16DstImgHeight - 1U;
    }
    if(vRotLib_CheckForOverlap(&stCoord, &stParam_local.stRotBlendCfg.tClipWnd, stParam_local.stRotBlendCfg.eClipWndEn) == GA_EN)
    {
        vRot_RotateBlendMatrix(pstMem, &stParam_local.stRotBlendCfg, &stMatrix, &stCoord, pstCmdList);
    }
}


/****************************************************************************/

void vRotLib_Scale(rot_mem_st* pstMem, rot_sscalCfg_st* pstParam, ga_list_st* pstCmdList)
{
    rot_cfg_st    stParam_local;
    rot_Mtrx_st   stMatrix;
    rot_frccr_st  stCoord;

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateTransformationMatrix_Scale(&stMatrix, pstParam->f64FactorX, pstParam->f64FactorY);
#else
    vRotLib_CalculateTransformationMatrix_Scale(&stMatrix, pstParam->i32FactorX, pstParam->i32FactorY);
#endif
#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateForwardRotatedCornerCoordinates_Scale(pstMem,
                                                           pstParam->i16OffsetX, pstParam->i16OffsetY,
                                                           pstParam->f64FactorX, pstParam->f64FactorY,
                                                           pstParam->eAlignment, &stCoord);
#else
    vRotLib_CalculateForwardRotatedCornerCoordinates_Scale(pstMem,
                                                           pstParam->i16OffsetX, pstParam->i16OffsetY,
                                                           pstParam->i32FactorX, pstParam->i32FactorY,
                                                           pstParam->eAlignment, &stCoord);
#endif

    stParam_local.stRotCfg.eSrcColFmt    = pstParam->eSrcColFmt;
    stParam_local.stRotCfg.eDstColFmt    = pstParam->eDstColFmt;
    stParam_local.stRotCfg.eClipWndEn    = pstParam->eClipWndEn;
    stParam_local.stRotCfg.eFilterEn     = pstParam->eFilterEn;
    stParam_local.i16RotCentX            = 0U;
    stParam_local.i16RotCentY            = 0U;
    stParam_local.i16OffsetX             = pstParam->i16OffsetX;
    stParam_local.i16OffsetY             = pstParam->i16OffsetY;
    stParam_local.stRotCfg.u8FadingFctr  = pstParam->u8FadingFctr;
    stParam_local.stRotCfg.u8SrcAlphaVal = pstParam->u8SrcAlphaVal;
    stParam_local.stRotCfg.u8DstAlphaVal = pstParam->u8DstAlphaVal;
    stParam_local.stRotCfg.tClipWnd      = pstParam->tClipWnd;

    vRotLib_CheckForNegativeCoordinates(pstMem, &stParam_local.stRotCfg, &stCoord);

    if((RE_DOUBLEABS((stCoord.u16X1>>4) - (stCoord.u16X4>>4)) > 0) && (RE_DOUBLEABS((stCoord.u16Y1>>4) - (stCoord.u16Y3>>4)) > 0))
    {
        if(stParam_local.stRotCfg.eClipWndEn == GA_DIS)
        {
            /* RE expects atleast 2 pixels to overlap with the draw region. When the clip window is disabled, and the 
            coordinates are also positive, it might so happen that all the 4 (Y coords >> 4) are 0. i.e they Y coord of 
            all 4 points lie on Y = 0;. In such cases RE hangs. Since this is an extreme and it does not occur so often,
            this block of  coded might affect the performance */
            
            stParam_local.stRotCfg.eClipWndEn = GA_EN;
            stParam_local.stRotCfg.tClipWnd.u16UlX = 0;
            stParam_local.stRotCfg.tClipWnd.u16UlY = 0;
            stParam_local.stRotCfg.tClipWnd.u16LrX = pstMem->u16DstImgWidth - 1U;
            stParam_local.stRotCfg.tClipWnd.u16LrY = pstMem->u16DstImgHeight - 1U;
        }
        if(vRotLib_CheckForOverlap(&stCoord, &stParam_local.stRotCfg.tClipWnd, stParam_local.stRotCfg.eClipWndEn) == GA_EN)
        {
            vRot_RotateMatrix(pstMem, &stParam_local.stRotCfg, &stMatrix, &stCoord, pstCmdList);
        }
    }
}


/****************************************************************************/

void vRotLib_ScaleBlend(rot_mem_st* pstMem, rot_sscalblendCfg_st* pstParam, ga_list_st* pstCmdList)
{

    rot_blendcfg_st  stParam_local;
    rot_Mtrx_st      stMatrix;
    rot_frccr_st     stCoord;

#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateTransformationMatrix_Scale(&stMatrix, pstParam->f64FactorX, pstParam->f64FactorY);
#else
    vRotLib_CalculateTransformationMatrix_Scale(&stMatrix, pstParam->i32FactorX, pstParam->i32FactorY);
#endif
#ifdef GA_USE_MATH_LIB
    vRotLib_CalculateForwardRotatedCornerCoordinates_Scale(pstMem,
                                                           pstParam->i16OffsetX, pstParam->i16OffsetY,
                                                           pstParam->f64FactorX, pstParam->f64FactorY,
                                                           pstParam->eAlignment, &stCoord);
#else
    vRotLib_CalculateForwardRotatedCornerCoordinates_Scale(pstMem,
                                                           pstParam->i16OffsetX, pstParam->i16OffsetY,
                                                           pstParam->i32FactorX, pstParam->i32FactorY,
                                                           pstParam->eAlignment, &stCoord);
#endif

    stParam_local.stRotBlendCfg.eSrcColFmt    = pstParam->eSrcColFmt;
    stParam_local.stRotBlendCfg.eDstColFmt    = pstParam->eDstColFmt;
    stParam_local.stRotBlendCfg.eClipWndEn    = pstParam->eClipWndEn;
    stParam_local.stRotBlendCfg.eFilterEn     = pstParam->eFilterEn;
    stParam_local.i16RotCentX                 = 0U;
    stParam_local.i16RotCentY                 = 0U;
    stParam_local.i16OffsetX                  = pstParam->i16OffsetX;
    stParam_local.i16OffsetY                  = pstParam->i16OffsetY;
    stParam_local.stRotBlendCfg.eDstRedProt   = pstParam->eDstRedProt;
    stParam_local.stRotBlendCfg.eDstGreenProt = pstParam->eDstGreenProt;
    stParam_local.stRotBlendCfg.eDstBlueProt  = pstParam->eDstBlueProt;
    stParam_local.stRotBlendCfg.eDstAlphaProt = pstParam->eDstAlphaProt;
    stParam_local.stRotBlendCfg.eSrcRedFad    = pstParam->eSrcRedFad;
    stParam_local.stRotBlendCfg.eSrcGreenFad  = pstParam->eSrcGreenFad;
    stParam_local.stRotBlendCfg.eSrcBlueFad   = pstParam->eSrcBlueFad;
    stParam_local.stRotBlendCfg.eSrcAlphaFad  = pstParam->eSrcAlphaFad;
    stParam_local.stRotBlendCfg.eBldOrd       = pstParam->eBldOrd;
    stParam_local.stRotBlendCfg.u8FadingFctr  = pstParam->u8FadingFctr;
    stParam_local.stRotBlendCfg.u8SrcAlphaVal = pstParam->u8SrcAlphaVal;
    stParam_local.stRotBlendCfg.u8DstAlphaVal = pstParam->u8DstAlphaVal;
    stParam_local.stRotBlendCfg.tClipWnd      = pstParam->tClipWnd;

    vRotLib_CheckForNegativeCoordinatesBlend(pstMem, &stParam_local.stRotBlendCfg, &stCoord);

    if((RE_DOUBLEABS((stCoord.u16X1>>4) - (stCoord.u16X4>>4)) > 0) && (RE_DOUBLEABS((stCoord.u16Y1>>4) - (stCoord.u16Y3>>4)) > 0))
    {
        if(stParam_local.stRotBlendCfg.eClipWndEn == GA_DIS)
        {
            /* RE expects atleast 2 pixels to overlap with the draw region. When the clip window is disabled, and the 
            coordinates are also positive, it might so happen that all the 4 (Y coords >> 4) are 0. i.e they Y coord of 
            all 4 points lie on Y = 0;. In such cases RE hangs. Since this is an extreme and it does not occur so often,
            this block of  coded might affect the performance */
            
            stParam_local.stRotBlendCfg.eClipWndEn = GA_EN;
            stParam_local.stRotBlendCfg.tClipWnd.u16UlX = 0;
            stParam_local.stRotBlendCfg.tClipWnd.u16UlY = 0;
            stParam_local.stRotBlendCfg.tClipWnd.u16LrX = pstMem->u16DstImgWidth - 1U;
            stParam_local.stRotBlendCfg.tClipWnd.u16LrY = pstMem->u16DstImgHeight - 1U;
        }
        if(vRotLib_CheckForOverlap(&stCoord, &stParam_local.stRotBlendCfg.tClipWnd, stParam_local.stRotBlendCfg.eClipWndEn) == GA_EN)
        {
            vRot_RotateBlendMatrix(pstMem, &stParam_local.stRotBlendCfg, &stMatrix, &stCoord, pstCmdList);
        }
    }
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vRotLib_Perspective(rot_mem_st* pstMem, rot_perspectiveCfg_st* pstParam, ga_list_st* pstCmdList)
{
    rot_cfg_st     stParam_local;
    GA_COORD_t     rot;
    GA_MATRIX_t    iR;
    GA_SCREENOBJ_t FRCC;
    GA_SCREENOBJ_t sortedFRCC;
    rot_Mtrx_st    stMatrix;
    rot_frccr_st   stCoord;
    float64_t      f64OffsetX, f64OffsetY;
    uint16_t       u16SubResDivX, u16SubResDivY;
    uint16_t       u16MinX, u16MinY;

    rot.x = -pstParam->f64AngleX;
    rot.y = -pstParam->f64AngleY;
    rot.z = -pstParam->f64AngleZ;

    /* forward rotate corners */
    FRCC = RE_FORWARDROT(rot, 1U, (uint32_t)pstMem->u16SrcWidth, (uint32_t)pstMem->u16SrcHeight, (float64_t)pstParam->u32RotPointX/(17.0 - (float64_t)f32SubResCPos), (float64_t)pstParam->u32RotPointY/(17.0 - (float64_t)f32SubResCPos));
    FRCC = RE_SCALESCREENOBJECT_X(FRCC, pstMem->u16SrcWidth*pstParam->f64ScaleX);
    FRCC = RE_SCALESCREENOBJECT_Y(FRCC, pstMem->u16SrcHeight*pstParam->f64ScaleY);

    sortedFRCC.p1.x = 16.0*FRCC.p1.x;
    sortedFRCC.p1.y = 16.0*FRCC.p1.y;
    sortedFRCC.p2.x = 16.0*FRCC.p2.x;
    sortedFRCC.p2.y = 16.0*FRCC.p2.y;
    sortedFRCC.p3.x = 16.0*FRCC.p3.x;
    sortedFRCC.p3.y = 16.0*FRCC.p3.y;
    sortedFRCC.p4.x = 16.0*FRCC.p4.x;
    sortedFRCC.p4.y = 16.0*FRCC.p4.y;

    /* sort corners as required by RE and get start corner */
    stCoord.u8ScrAddrPos = (uint8_t)RE_SORTCORNERS(&sortedFRCC) - 1U;

    if (stCoord.u8ScrAddrPos != 254U)
    {
        /* calculate offset */
        f64OffsetX = 16.0*(((float64_t)pstParam->i16OffsetX / (17.0 -(float64_t)f32SubResPPos)) - (FRCC.c.x - ((float64_t)pstParam->u32RotPointX / (17.0 - (float64_t)f32SubResCPos))));
        f64OffsetY = 16.0*(((float64_t)pstParam->i16OffsetY / (17.0 -(float64_t)f32SubResPPos)) - (FRCC.c.y - ((float64_t)pstParam->u32RotPointY / (17.0 - (float64_t)f32SubResCPos))));

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
        /* correct offset */
        stCoord.u16X1 = 0xFFFFU & ((uint32_t)(sortedFRCC.p1.x + f64OffsetX));
        stCoord.u16Y1 = 0xFFFFU & ((uint32_t)(sortedFRCC.p1.y + f64OffsetY));
        stCoord.u16X2 = 0xFFFFU & ((uint32_t)(sortedFRCC.p2.x + f64OffsetX));
        stCoord.u16Y2 = 0xFFFFU & ((uint32_t)(sortedFRCC.p2.y + f64OffsetY));
        stCoord.u16X3 = 0xFFFFU & ((uint32_t)(sortedFRCC.p3.x + f64OffsetX));
        stCoord.u16Y3 = 0xFFFFU & ((uint32_t)(sortedFRCC.p3.y + f64OffsetY));
        stCoord.u16X4 = 0xFFFFU & ((uint32_t)(sortedFRCC.p4.x + f64OffsetX));
        stCoord.u16Y4 = 0xFFFFU & ((uint32_t)(sortedFRCC.p4.y + f64OffsetY));
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

        /* create matrix as required by RE */
        iR = RE_BACKWARDMATRIX(FRCC, (uint32_t)pstMem->u16SrcWidth, (uint32_t)pstMem->u16SrcHeight);

        /* assign matrix */
        stMatrix.u32A11 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.sx  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A12 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.shy + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A21 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.shx + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A22 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.sy  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A31 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w0  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A32 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w1  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A33 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w2  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));

        stParam_local.stRotCfg.eSrcColFmt    = pstParam->eSrcColFmt;
        stParam_local.stRotCfg.eDstColFmt    = pstParam->eDstColFmt;
        stParam_local.stRotCfg.eClipWndEn    = pstParam->eClipWndEn;
        stParam_local.stRotCfg.eFilterEn     = pstParam->eFilterEn;
        stParam_local.i16RotCentX            = 0U;
        stParam_local.i16RotCentY            = 0U;
        stParam_local.i16OffsetX             = pstParam->i16OffsetX;
        stParam_local.i16OffsetY             = pstParam->i16OffsetY;
        stParam_local.stRotCfg.u8FadingFctr  = pstParam->u8FadingFctr;
        stParam_local.stRotCfg.u8SrcAlphaVal = pstParam->u8SrcAlphaVal;
        stParam_local.stRotCfg.u8DstAlphaVal = pstParam->u8DstAlphaVal;
        stParam_local.stRotCfg.tClipWnd      = pstParam->tClipWnd;

        vRotLib_CheckForNegativeCoordinates(pstMem, &stParam_local.stRotCfg, &stCoord);

        /* get MinX and MinY of coordinates */
        u16MinX = stCoord.u16X1;
        if (stCoord.u16X2 < u16MinX) {u16MinX = stCoord.u16X2;}
        if (stCoord.u16X3 < u16MinX) {u16MinX = stCoord.u16X3;}
        if (stCoord.u16X4 < u16MinX) {u16MinX = stCoord.u16X4;}
        u16MinY = stCoord.u16Y1;
        if (stCoord.u16Y2 < u16MinY) {u16MinY = stCoord.u16Y2;}
        if (stCoord.u16Y3 < u16MinY) {u16MinY = stCoord.u16Y3;}
        if (stCoord.u16Y4 < u16MinY) {u16MinY = stCoord.u16Y4;}

        u16SubResDivX  = u16MinX >> 4U;
        u16SubResDivY  = u16MinY >> 4U;

        /* correct offset of coordinates */
        stCoord.u16X1 = stCoord.u16X1 - 16U*u16SubResDivX;
        stCoord.u16Y1 = stCoord.u16Y1 - 16U*u16SubResDivY;
        stCoord.u16X2 = stCoord.u16X2 - 16U*u16SubResDivX;
        stCoord.u16Y2 = stCoord.u16Y2 - 16U*u16SubResDivY;
        stCoord.u16X3 = stCoord.u16X3 - 16U*u16SubResDivX;
        stCoord.u16Y3 = stCoord.u16Y3 - 16U*u16SubResDivY;
        stCoord.u16X4 = stCoord.u16X4 - 16U*u16SubResDivX;
        stCoord.u16Y4 = stCoord.u16Y4 - 16U*u16SubResDivY;

        /* correct startaddress */
        if (pstParam->eDstColFmt == GA_RGB16)
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr + 2U*pstMem->u16DstImgWidth*u16SubResDivY + 2U*u16SubResDivX;
        }
        else
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr + 4U*pstMem->u16DstImgWidth*u16SubResDivY + 4U*u16SubResDivX;
        }

        /* correct clip window */
        if (pstParam->eClipWndEn == GA_EN)
        {
            pstParam->tClipWnd.u16UlX = pstParam->tClipWnd.u16UlX - u16SubResDivX;
            pstParam->tClipWnd.u16UlY = pstParam->tClipWnd.u16UlY - u16SubResDivY;
            pstParam->tClipWnd.u16LrX = pstParam->tClipWnd.u16LrX - u16SubResDivX;
            pstParam->tClipWnd.u16LrY = pstParam->tClipWnd.u16LrY - u16SubResDivY;
            stParam_local.stRotCfg.tClipWnd = pstParam->tClipWnd;
        }

        vRot_RotateMatrix(pstMem, &stParam_local.stRotCfg, &stMatrix, &stCoord, pstCmdList);
    }
}


/****************************************************************************/

void vRotLib_PerspectiveBlend(rot_mem_st* pstMem, rot_perspectiveblendCfg_st* pstParam, ga_list_st* pstCmdList)
{
    rot_blendcfg_st  stParam_local;
    GA_COORD_t       rot;
    GA_MATRIX_t      iR;
    GA_SCREENOBJ_t   FRCC;
    GA_SCREENOBJ_t   sortedFRCC;
    rot_Mtrx_st      stMatrix;
    rot_frccr_st     stCoord;
    float64_t        f64OffsetX, f64OffsetY;
    uint16_t         u16SubResDivX, u16SubResDivY;
    uint16_t         u16MinX, u16MinY;

    rot.x = -pstParam->f64AngleX;
    rot.y = -pstParam->f64AngleY;
    rot.z = -pstParam->f64AngleZ;

    /* forward rotate corners */
    FRCC = RE_FORWARDROT(rot, 1U, (uint32_t)pstMem->u16SrcWidth, (uint32_t)pstMem->u16SrcHeight, (float64_t)pstParam->u32RotPointX/(17.0 - (float64_t)f32SubResCPos), (float64_t)pstParam->u32RotPointY/(17.0 - (float64_t)f32SubResCPos));
    FRCC = RE_SCALESCREENOBJECT_X(FRCC, pstMem->u16SrcWidth*pstParam->f64ScaleX);
    FRCC = RE_SCALESCREENOBJECT_Y(FRCC, pstMem->u16SrcHeight*pstParam->f64ScaleY);

    sortedFRCC.p1.x = 16.0*FRCC.p1.x;
    sortedFRCC.p1.y = 16.0*FRCC.p1.y;
    sortedFRCC.p2.x = 16.0*FRCC.p2.x;
    sortedFRCC.p2.y = 16.0*FRCC.p2.y;
    sortedFRCC.p3.x = 16.0*FRCC.p3.x;
    sortedFRCC.p3.y = 16.0*FRCC.p3.y;
    sortedFRCC.p4.x = 16.0*FRCC.p4.x;
    sortedFRCC.p4.y = 16.0*FRCC.p4.y;

    /* sort corners as required by RE and get start corner */
    stCoord.u8ScrAddrPos = (uint8_t)RE_SORTCORNERS(&sortedFRCC) - 1U;

    if (stCoord.u8ScrAddrPos != 254U)
    {
        /* calculate offset */
        f64OffsetX = 16.0*(((float64_t)pstParam->i16OffsetX / (17.0 -(float64_t)f32SubResPPos)) - (FRCC.c.x - ((float64_t)pstParam->u32RotPointX / (17.0 - (float64_t)f32SubResCPos))));
        f64OffsetY = 16.0*(((float64_t)pstParam->i16OffsetY / (17.0 -(float64_t)f32SubResPPos)) - (FRCC.c.y - ((float64_t)pstParam->u32RotPointY / (17.0 - (float64_t)f32SubResCPos))));

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
        /* correct offset */
        stCoord.u16X1 = 0xFFFFU & ((uint32_t)(sortedFRCC.p1.x + f64OffsetX));
        stCoord.u16Y1 = 0xFFFFU & ((uint32_t)(sortedFRCC.p1.y + f64OffsetY));
        stCoord.u16X2 = 0xFFFFU & ((uint32_t)(sortedFRCC.p2.x + f64OffsetX));
        stCoord.u16Y2 = 0xFFFFU & ((uint32_t)(sortedFRCC.p2.y + f64OffsetY));
        stCoord.u16X3 = 0xFFFFU & ((uint32_t)(sortedFRCC.p3.x + f64OffsetX));
        stCoord.u16Y3 = 0xFFFFU & ((uint32_t)(sortedFRCC.p3.y + f64OffsetY));
        stCoord.u16X4 = 0xFFFFU & ((uint32_t)(sortedFRCC.p4.x + f64OffsetX));
        stCoord.u16Y4 = 0xFFFFU & ((uint32_t)(sortedFRCC.p4.y + f64OffsetY));
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

        /* create matrix as required by RE */
        iR=RE_BACKWARDMATRIX(FRCC, (uint32_t)pstMem->u16SrcWidth, (uint32_t)pstMem->u16SrcHeight);

        stMatrix.u32A11 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.sx  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A12 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.shy + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A21 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.shx + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A22 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.sy  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A31 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w0  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A32 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w1  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A33 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w2  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));

        stParam_local.stRotBlendCfg.eSrcColFmt    = pstParam->eSrcColFmt;
        stParam_local.stRotBlendCfg.eDstColFmt    = pstParam->eDstColFmt;
        stParam_local.stRotBlendCfg.eClipWndEn    = pstParam->eClipWndEn;
        stParam_local.stRotBlendCfg.eFilterEn     = pstParam->eFilterEn;
        stParam_local.i16RotCentX                 = 0U;
        stParam_local.i16RotCentY                 = 0U;
        stParam_local.i16OffsetX                  = pstParam->i16OffsetX;
        stParam_local.i16OffsetY                  = pstParam->i16OffsetY;
        stParam_local.stRotBlendCfg.eDstRedProt   = pstParam->eDstRedProt;
        stParam_local.stRotBlendCfg.eDstGreenProt = pstParam->eDstGreenProt;
        stParam_local.stRotBlendCfg.eDstBlueProt  = pstParam->eDstBlueProt;
        stParam_local.stRotBlendCfg.eDstAlphaProt = pstParam->eDstAlphaProt;
        stParam_local.stRotBlendCfg.eSrcRedFad    = pstParam->eSrcRedFad;
        stParam_local.stRotBlendCfg.eSrcGreenFad  = pstParam->eSrcGreenFad;
        stParam_local.stRotBlendCfg.eSrcBlueFad   = pstParam->eSrcBlueFad;
        stParam_local.stRotBlendCfg.eSrcAlphaFad  = pstParam->eSrcAlphaFad;
        stParam_local.stRotBlendCfg.eBldOrd       = pstParam->eBldOrd;
        stParam_local.stRotBlendCfg.u8FadingFctr  = pstParam->u8FadingFctr;
        stParam_local.stRotBlendCfg.u8SrcAlphaVal = pstParam->u8SrcAlphaVal;
        stParam_local.stRotBlendCfg.u8DstAlphaVal = pstParam->u8DstAlphaVal;
        stParam_local.stRotBlendCfg.tClipWnd      = pstParam->tClipWnd;

        vRotLib_CheckForNegativeCoordinatesBlend(pstMem, &stParam_local.stRotBlendCfg, &stCoord);

        /* get MinX and MinY of coordinates */
        u16MinX = stCoord.u16X1;
        if (stCoord.u16X2 < u16MinX) {u16MinX = stCoord.u16X2;}
        if (stCoord.u16X3 < u16MinX) {u16MinX = stCoord.u16X3;}
        if (stCoord.u16X4 < u16MinX) {u16MinX = stCoord.u16X4;}
        u16MinY = stCoord.u16Y1;
        if (stCoord.u16Y2 < u16MinY) {u16MinY = stCoord.u16Y2;}
        if (stCoord.u16Y3 < u16MinY) {u16MinY = stCoord.u16Y3;}
        if (stCoord.u16Y4 < u16MinY) {u16MinY = stCoord.u16Y4;}

        u16SubResDivX  = u16MinX >> 4U;
        u16SubResDivY  = u16MinY >> 4U;

        /* correct offset of coordinates */
        stCoord.u16X1 = stCoord.u16X1 - 16U*u16SubResDivX;
        stCoord.u16Y1 = stCoord.u16Y1 - 16U*u16SubResDivY;
        stCoord.u16X2 = stCoord.u16X2 - 16U*u16SubResDivX;
        stCoord.u16Y2 = stCoord.u16Y2 - 16U*u16SubResDivY;
        stCoord.u16X3 = stCoord.u16X3 - 16U*u16SubResDivX;
        stCoord.u16Y3 = stCoord.u16Y3 - 16U*u16SubResDivY;
        stCoord.u16X4 = stCoord.u16X4 - 16U*u16SubResDivX;
        stCoord.u16Y4 = stCoord.u16Y4 - 16U*u16SubResDivY;

        /* correct startaddress */
        if (pstParam->eDstColFmt == GA_RGB16)
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr + 2U*pstMem->u16DstImgWidth*u16SubResDivY + 2U*u16SubResDivX;
        }
        else
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr + 4U*pstMem->u16DstImgWidth*u16SubResDivY + 4U*u16SubResDivX;
        }

        /* correct clip window */
        if (pstParam->eClipWndEn == GA_EN)
        {
            pstParam->tClipWnd.u16UlX = pstParam->tClipWnd.u16UlX - u16SubResDivX;
            pstParam->tClipWnd.u16UlY = pstParam->tClipWnd.u16UlY - u16SubResDivY;
            pstParam->tClipWnd.u16LrX = pstParam->tClipWnd.u16LrX - u16SubResDivX;
            pstParam->tClipWnd.u16LrY = pstParam->tClipWnd.u16LrY - u16SubResDivY;
            stParam_local.stRotBlendCfg.tClipWnd = pstParam->tClipWnd;
        }

        vRot_RotateBlendMatrix(pstMem, &stParam_local.stRotBlendCfg, &stMatrix, &stCoord, pstCmdList);
    }
}


/****************************************************************************/

void vRotLib_PerspectiveOGL(rot_mem_st * pstMem, rot_perspectiveCfg_st * pstParam, ga_list_st * pstCmdList)
{
    int32_t        offset[2];
    rot_cfg_st     stParam_local;
    rot_Mtrx_st    stMatrix;
    rot_frccr_st   stCoord;
    uint16_t       u16SubResDivX, u16SubResDivY;
    uint16_t       u16MinX, u16MinY;
    GA_MATRIX_t    iR;
    GA_SCREENOBJ_t sortedFRCC, FRCC;
    ga_en_e        eDraw;

    RE_TRANSLATEOBJECT((int32_t*)offset, &FRCC, (float64_t*)obj);

    /* create matrix as required by RE */
    iR = RE_BACKWARDMATRIX(FRCC, (uint32_t)pstMem->u16SrcWidth, (uint32_t)pstMem->u16SrcHeight);

    sortedFRCC.p1.x = 16.0*FRCC.p1.x;
    sortedFRCC.p1.y = 16.0*FRCC.p1.y;
    sortedFRCC.p2.x = 16.0*FRCC.p2.x;
    sortedFRCC.p2.y = 16.0*FRCC.p2.y;
    sortedFRCC.p3.x = 16.0*FRCC.p3.x;
    sortedFRCC.p3.y = 16.0*FRCC.p3.y;
    sortedFRCC.p4.x = 16.0*FRCC.p4.x;
    sortedFRCC.p4.y = 16.0*FRCC.p4.y;
                           
    /* sort corners as required by RE and get start corner */
    stCoord.u8ScrAddrPos = (uint8_t)RE_SORTCORNERS(&sortedFRCC) - 1U;

    if (stCoord.u8ScrAddrPos != 254U)
    {
        /* assign matrix */
        stMatrix.u32A11 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.sx  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A12 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.shy + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A21 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.shx + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A22 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.sy  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A31 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w0  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A32 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w1  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A33 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w2  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
        /* correct offset */
        stCoord.u16X1 = 0xFFFFU & ((uint32_t)sortedFRCC.p1.x);
        stCoord.u16Y1 = 0xFFFFU & ((uint32_t)sortedFRCC.p1.y);
        stCoord.u16X2 = 0xFFFFU & ((uint32_t)sortedFRCC.p2.x);
        stCoord.u16Y2 = 0xFFFFU & ((uint32_t)sortedFRCC.p2.y);
        stCoord.u16X3 = 0xFFFFU & ((uint32_t)sortedFRCC.p3.x);
        stCoord.u16Y3 = 0xFFFFU & ((uint32_t)sortedFRCC.p3.y);
        stCoord.u16X4 = 0xFFFFU & ((uint32_t)sortedFRCC.p4.x);
        stCoord.u16Y4 = 0xFFFFU & ((uint32_t)sortedFRCC.p4.y);
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

        stParam_local.stRotCfg.eSrcColFmt    = pstParam->eSrcColFmt;
        stParam_local.stRotCfg.eDstColFmt    = pstParam->eDstColFmt;
        stParam_local.stRotCfg.eClipWndEn    = pstParam->eClipWndEn;
        stParam_local.stRotCfg.eFilterEn     = pstParam->eFilterEn;
        stParam_local.i16RotCentX            = 0U;
        stParam_local.i16RotCentY            = 0U;
        stParam_local.i16OffsetX             = 0U;
        stParam_local.i16OffsetY             = 0U;
        stParam_local.stRotCfg.u8FadingFctr  = pstParam->u8FadingFctr;
        stParam_local.stRotCfg.u8SrcAlphaVal = pstParam->u8SrcAlphaVal;
        stParam_local.stRotCfg.u8DstAlphaVal = pstParam->u8DstAlphaVal;
        stParam_local.stRotCfg.tClipWnd      = pstParam->tClipWnd;
        
        vRotLib_CheckForNegativeCoordinates(pstMem, &stParam_local.stRotCfg, &stCoord);

        /* get MinX and MinY of coordinates */
        u16MinX = stCoord.u16X1;
        if (stCoord.u16X2 < u16MinX) {u16MinX = stCoord.u16X2;}
        if (stCoord.u16X3 < u16MinX) {u16MinX = stCoord.u16X3;}
        if (stCoord.u16X4 < u16MinX) {u16MinX = stCoord.u16X4;}
        u16MinY = stCoord.u16Y1;
        if (stCoord.u16Y2 < u16MinY) {u16MinY = stCoord.u16Y2;}
        if (stCoord.u16Y3 < u16MinY) {u16MinY = stCoord.u16Y3;}
        if (stCoord.u16Y4 < u16MinY) {u16MinY = stCoord.u16Y4;}

        u16SubResDivX  = u16MinX >> 4U;
        u16SubResDivY  = u16MinY >> 4U;

        /* correct offset of coordinates */
        stCoord.u16X1 = stCoord.u16X1 - 16U*u16SubResDivX;
        stCoord.u16Y1 = stCoord.u16Y1 - 16U*u16SubResDivY;
        stCoord.u16X2 = stCoord.u16X2 - 16U*u16SubResDivX;
        stCoord.u16Y2 = stCoord.u16Y2 - 16U*u16SubResDivY;
        stCoord.u16X3 = stCoord.u16X3 - 16U*u16SubResDivX;
        stCoord.u16Y3 = stCoord.u16Y3 - 16U*u16SubResDivY;
        stCoord.u16X4 = stCoord.u16X4 - 16U*u16SubResDivX;
        stCoord.u16Y4 = stCoord.u16Y4 - 16U*u16SubResDivY;

        /* correct startaddress */
        if (pstParam->eDstColFmt == GA_RGB16)
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr + 2U*pstMem->u16DstImgWidth*offset[1] + 2U*offset[0];
        }
        else
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr + 4U*pstMem->u16DstImgWidth*offset[1] + 4U*offset[0];
        }

        
        /* Update the clip window parameters if it was modified in the CheckForNegative() */
        pstParam->tClipWnd = stParam_local.stRotCfg.tClipWnd;
        pstParam->eClipWndEn = stParam_local.stRotCfg.eClipWndEn;
            
        /* correct clip window */
        eDraw = vRotLib_CalculateCorrectClipWindow(&pstParam->tClipWnd, pstParam->eClipWndEn, pstMem, &offset[0]);
        /* Draw only if there is an overlapping clip window and destination area */
        if(eDraw == GA_EN)
        {   
            if(vRotLib_CheckForOverlap(&stCoord, &pstParam->tClipWnd, eDraw) == GA_EN)
            {
                /* check pstParam->tClipWnd */
                pstParam->eClipWndEn = eDraw;
                stParam_local.stRotCfg.tClipWnd = pstParam->tClipWnd;
                stParam_local.stRotCfg.eClipWndEn = pstParam->eClipWndEn;

                vRot_RotateMatrix(pstMem, &stParam_local.stRotCfg, &stMatrix, &stCoord, pstCmdList);
            }
        }
    }
}

/****************************************************************************/

void vRotLib_PerspectiveBlendOGL(rot_mem_st * pstMem, rot_perspectiveblendCfg_st * pstParam, ga_list_st * pstCmdList)
{
    int32_t         offset[2];
    rot_blendcfg_st stParam_local;
    rot_Mtrx_st     stMatrix;
    rot_frccr_st    stCoord;
    uint16_t        u16SubResDivX, u16SubResDivY;
    uint16_t        u16MinX, u16MinY;
    GA_MATRIX_t     iR;
    GA_SCREENOBJ_t  sortedFRCC, FRCC;
    ga_en_e         eDraw;

    RE_TRANSLATEOBJECT((int32_t*)offset, &FRCC, (float64_t*)obj);

    /* create matrix as required by RE */
    iR = RE_BACKWARDMATRIX(FRCC, (uint32_t)pstMem->u16SrcWidth, (uint32_t)pstMem->u16SrcHeight);

    sortedFRCC.p1.x = 16.0*FRCC.p1.x;
    sortedFRCC.p1.y = 16.0*FRCC.p1.y;
    sortedFRCC.p2.x = 16.0*FRCC.p2.x;
    sortedFRCC.p2.y = 16.0*FRCC.p2.y;
    sortedFRCC.p3.x = 16.0*FRCC.p3.x;
    sortedFRCC.p3.y = 16.0*FRCC.p3.y;
    sortedFRCC.p4.x = 16.0*FRCC.p4.x;
    sortedFRCC.p4.y = 16.0*FRCC.p4.y;
                           
    /* sort corners as required by RE and get start corner */
    stCoord.u8ScrAddrPos = (uint8_t)RE_SORTCORNERS(&sortedFRCC) - 1U;

    if (stCoord.u8ScrAddrPos != 254U)
    {
        /* assign matrix */
        stMatrix.u32A11 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.sx  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A12 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.shy + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A21 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.shx + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A22 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.sy  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A31 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w0  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A32 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w1  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));
        stMatrix.u32A33 = 0x3FFFFFU & ((uint32_t)((int64_t)iR.w2  + 0xFFFFFFFFFFFFFFFFUL + 0x1UL));

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */
        /* correct offset */
        stCoord.u16X1 = 0xFFFFU & ((uint32_t)sortedFRCC.p1.x);
        stCoord.u16Y1 = 0xFFFFU & ((uint32_t)sortedFRCC.p1.y);
        stCoord.u16X2 = 0xFFFFU & ((uint32_t)sortedFRCC.p2.x);
        stCoord.u16Y2 = 0xFFFFU & ((uint32_t)sortedFRCC.p2.y);
        stCoord.u16X3 = 0xFFFFU & ((uint32_t)sortedFRCC.p3.x);
        stCoord.u16Y3 = 0xFFFFU & ((uint32_t)sortedFRCC.p3.y);
        stCoord.u16X4 = 0xFFFFU & ((uint32_t)sortedFRCC.p4.x);
        stCoord.u16Y4 = 0xFFFFU & ((uint32_t)sortedFRCC.p4.y);
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

        stParam_local.stRotBlendCfg.eSrcColFmt    = pstParam->eSrcColFmt;
        stParam_local.stRotBlendCfg.eDstColFmt    = pstParam->eDstColFmt;
        stParam_local.stRotBlendCfg.eClipWndEn    = pstParam->eClipWndEn;
        stParam_local.stRotBlendCfg.eFilterEn     = pstParam->eFilterEn;
        stParam_local.i16RotCentX                 = 0U;
        stParam_local.i16RotCentY                 = 0U;
        stParam_local.i16OffsetX                  = 0U;
        stParam_local.i16OffsetY                  = 0U;
        stParam_local.stRotBlendCfg.eDstRedProt   = pstParam->eDstRedProt;
        stParam_local.stRotBlendCfg.eDstGreenProt = pstParam->eDstGreenProt;
        stParam_local.stRotBlendCfg.eDstBlueProt  = pstParam->eDstBlueProt;
        stParam_local.stRotBlendCfg.eDstAlphaProt = pstParam->eDstAlphaProt;
        stParam_local.stRotBlendCfg.eSrcRedFad    = pstParam->eSrcRedFad;
        stParam_local.stRotBlendCfg.eSrcGreenFad  = pstParam->eSrcGreenFad;
        stParam_local.stRotBlendCfg.eSrcBlueFad   = pstParam->eSrcBlueFad;
        stParam_local.stRotBlendCfg.eSrcAlphaFad  = pstParam->eSrcAlphaFad;
        stParam_local.stRotBlendCfg.eBldOrd       = pstParam->eBldOrd;
        stParam_local.stRotBlendCfg.u8FadingFctr  = pstParam->u8FadingFctr;
        stParam_local.stRotBlendCfg.u8SrcAlphaVal = pstParam->u8SrcAlphaVal;
        stParam_local.stRotBlendCfg.u8DstAlphaVal = pstParam->u8DstAlphaVal;
        stParam_local.stRotBlendCfg.tClipWnd      = pstParam->tClipWnd;
        
        vRotLib_CheckForNegativeCoordinatesBlend(pstMem, &stParam_local.stRotBlendCfg, &stCoord);

        /* get MinX and MinY of coordinates */
        u16MinX = stCoord.u16X1;
        if (stCoord.u16X2 < u16MinX) {u16MinX = stCoord.u16X2;}
        if (stCoord.u16X3 < u16MinX) {u16MinX = stCoord.u16X3;}
        if (stCoord.u16X4 < u16MinX) {u16MinX = stCoord.u16X4;}
        u16MinY = stCoord.u16Y1;
        if (stCoord.u16Y2 < u16MinY) {u16MinY = stCoord.u16Y2;}
        if (stCoord.u16Y3 < u16MinY) {u16MinY = stCoord.u16Y3;}
        if (stCoord.u16Y4 < u16MinY) {u16MinY = stCoord.u16Y4;}

        u16SubResDivX  = u16MinX >> 4U;
        u16SubResDivY  = u16MinY >> 4U;

        /* correct offset of coordinates */
        stCoord.u16X1 = stCoord.u16X1 - 16U*u16SubResDivX;
        stCoord.u16Y1 = stCoord.u16Y1 - 16U*u16SubResDivY;
        stCoord.u16X2 = stCoord.u16X2 - 16U*u16SubResDivX;
        stCoord.u16Y2 = stCoord.u16Y2 - 16U*u16SubResDivY;
        stCoord.u16X3 = stCoord.u16X3 - 16U*u16SubResDivX;
        stCoord.u16Y3 = stCoord.u16Y3 - 16U*u16SubResDivY;
        stCoord.u16X4 = stCoord.u16X4 - 16U*u16SubResDivX;
        stCoord.u16Y4 = stCoord.u16Y4 - 16U*u16SubResDivY;

        /* correct startaddress */
        if (pstParam->eDstColFmt == GA_RGB16)
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr + 2U*pstMem->u16DstImgWidth*offset[1] + 2U*offset[0];
        }
        else
        {
            pstMem->u32DstAddr = pstMem->u32DstAddr + 4U*pstMem->u16DstImgWidth*offset[1] + 4U*offset[0];
        }

        /* Update the clip window parameters, if it was modified in the CheckForNegative() */
        pstParam->tClipWnd = stParam_local.stRotBlendCfg.tClipWnd;
        pstParam->eClipWndEn = stParam_local.stRotBlendCfg.eClipWndEn;
            
        /* correct clip window */
        eDraw = vRotLib_CalculateCorrectClipWindow(&pstParam->tClipWnd, pstParam->eClipWndEn, pstMem, &offset[0]);
        /* Draw only if there is an overlapping clip window and destination area */
        if(eDraw == GA_EN)
        {
            if(vRotLib_CheckForOverlap(&stCoord, &pstParam->tClipWnd, eDraw) == GA_EN)
            {
                pstParam->eClipWndEn = eDraw;
                stParam_local.stRotBlendCfg.tClipWnd = pstParam->tClipWnd;
                stParam_local.stRotBlendCfg.eClipWndEn = pstParam->eClipWndEn;

                vRot_RotateBlendMatrix(pstMem, &stParam_local.stRotBlendCfg, &stMatrix, &stCoord, pstCmdList);
            }
        }
    }
}

#endif


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
  conditions set forth in the �Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (�Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer�s own risk.

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
