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
*   VERSION     : $Revision: 1.32 $
*   DATE        : $Date: 2015/07/21 12:42:52 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "gfunctions.h"
#include "listmngr.h"
#include "mw_definitions.h"
#include "core.h"
#include "png.h"
#include "rotation.h"
#include "gdc_io.h"
#include "listmngr.h"

/*********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1847    /* MISRA 2004 Rule 10.3 */
  #pragma ghs nowarning 1848    /* MISRA 2004 Rule 10.3 */

  #pragma ghs nowarning 1863    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1864    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1865    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1866    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1867    /* MISRA 2004 Rule 10.1 */
  #pragma ghs nowarning 1868    /* MISRA 2004 Rule 10.1 */

  #pragma ghs nowarning 1872    /* MISRA 2004 Rule 10.2 */
  #pragma ghs nowarning 1873    /* MISRA 2004 Rule 10.2 */
#endif /* defined(__GHS__) || defined(__ghs__) */


/**********************************************
*                 Constants                   *
**********************************************/

#define MW_GFUNCTIONS_C_REVISION     "$Revision: 1.32 $"
#define MW_GFUNCTIONS_C_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/

#define SWAP_ROWS_float64_t(a, b) { float64_t *_tmp = a; (a)=(b); (b)=_tmp; }
#define SWAP_ROWS_FLOAT(a, b) { float64_t *_tmp = a; (a)=(b); (b)=_tmp; }
#define MAT(m,r,c) (m)[(c)*4+(r)]
#define MIN_FLOAT(a, b) ((a) < (b) ? (a) : (b))
#define ABS_INT(a) ((a) < 0 ? -(a) : (a))
#define GF_PI_BY_2 1.570796326794897
#define GF_2_PI 6.283185307179586
/*********************************************/


/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8MW_GFUNCTIONS_C_REVISION[]  = MW_GFUNCTIONS_C_REVISION;
static uint8_t au8MW_GFUNCTIONS_C_TAG[]       = MW_GFUNCTIONS_C_TAG;
static uint8_t au8MW_GFUNCTIONS_H_REVISION[]  = MW_GFUNCTIONS_H_REVISION;
static uint8_t au8MW_GFUNCTIONS_H_TAG[]       = MW_GFUNCTIONS_H_TAG;
static uint8_t au8MW_GF_H_REVISION[]          = MW_GF_H_REVISION;
static uint8_t au8MW_GF_H_TAG[]               = MW_GF_H_TAG;
static uint8_t au8MW_DEFINITIONS_H_REVISION[] = MW_DEFINITIONS_H_REVISION;
static uint8_t au8MW_DEFINITIONS_H_TAG[]      = MW_DEFINITIONS_H_TAG;

/*********************************************/


/**********************************************
*            External variables               *
**********************************************/
extern ga_list_st* pstWriteList;

extern uint32_t au32Coordinate[4][2];

extern float32_t f32SubResPPos;
extern uint32_t  u32SubResPPos;
extern float32_t f32SubResCPos;
extern uint32_t  u32SubResCPos;

/*********************************************/

extern float64_t obj[4][4];


/**********************************************
*              Global variables               *
**********************************************/
gf_gastate_st stGastate;

uint32_t u32MinMaxValues[20][4] = {{0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                   {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                   {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                   {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}};
uint32_t u32MinMaxValues_old[20][4] = {{0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                       {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                       {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                       {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}};
uint32_t u32MinMaxValues_old_old[20][4] = {{0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                           {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                           {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                           {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}};
uint32_t u32MinMaxValuesBase[20][4] = {{0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                       {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                       {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                       {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}};
uint32_t u32MinMaxValuesBase_old[20][4] = {{0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                           {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                           {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                           {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}};
uint32_t u32MinMaxValuesBase_old_old[20][4] = {{0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                               {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                               {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U},
                                               {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U}};
uint32_t u32NeedleNumber;

#ifdef MEASURE_TX
uint32_t u32TimeMeasure;
uint32_t u32TimeMeasureGA;
#endif

uint8_t u8PNG_Decoder = 0U;
uint8_t u8PNG_PaletteStream6 = 1U;
uint8_t u8PNG_PaletteStream7 = 1U;
uint8_t u8PreviousOperation = 1U;

float64_t viewport[4];
float64_t modelview[16];
float64_t projection[16];
float64_t ip[16];
gf_matrixmodes_e matrixmode;

/**********************************************
*             Function prototypes             *
**********************************************/
static uint32_t u32GfGetMinXCoordinate(void);
static uint32_t u32GfGetMinYCoordinate(void);
static uint32_t u32GfGetMaxXCoordinate(void);
static uint32_t u32GfGetMaxYCoordinate(void);
static ga_en_e eHandleClipWindowBlit(gf_image_st * pstDstImage, uint16_t u16SrcWidth, uint16_t u16SrcHeight, ga_en_e eClipWndEn, int32_t i32PosX, int32_t i32PosY);
static float32_t f32CheckAngle(float32_t f32Angle);
static void vGfDrawTriangleSort(gf_image_st *pstDstImage, drw_OpCfg_st *pstOption, drw_Trngl_st *pstTrngl, uint8_t u8AAEdge);
static void vGfDrawCircleWithEndCaps(gf_image_st *pstDstImage, drw_OpCfg_st *pstOption, gf_circle_st *pstCircle);
static float64_t* f64GETMATRIX(void);
static bool_t boIsAntiClockwise(drw_Trngl_st *pstTrngl);
static void vMMMUL4x4(float64_t* r, float64_t* a, float64_t *b);
static void vMVMUL4x4(float64_t* r, float64_t* m, float64_t* v);
static int iGfInvertMatrix4x4(float64_t *m, float64_t *out);
static int iProject(float64_t * pf64Win, float64_t * pf64Obj);

/**********************************************
*             Function definition             *
**********************************************/

/****************************************************************************/

void vGf_Gfunctions_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                               uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                               uint8_t** pau8GfHeaderRevision, uint8_t** pau8GfHeaderTag,
                               uint8_t** pau8DefHeaderRevision, uint8_t** pau8DefHeaderTag)
{
   *pau8ModuleRevision    = &au8MW_GFUNCTIONS_C_REVISION[0];
   *pau8ModuleTag         = &au8MW_GFUNCTIONS_C_TAG[0];
   *pau8HeaderRevision    = &au8MW_GFUNCTIONS_H_REVISION[0];
   *pau8HeaderTag         = &au8MW_GFUNCTIONS_H_TAG[0];
   *pau8GfHeaderRevision  = &au8MW_GF_H_REVISION[0];
   *pau8GfHeaderTag       = &au8MW_GF_H_TAG[0];
   *pau8DefHeaderRevision = &au8MW_DEFINITIONS_H_REVISION[0];
   *pau8DefHeaderTag      = &au8MW_DEFINITIONS_H_TAG[0];
}


/****************************************************************************/

static bool_t boIsAntiClockwise(drw_Trngl_st *pstTrngl)
{
    /* Cross product formula to determine if the points are in clockwise or anti clockwise direction */
    /* If i32Value is +ve/-ve  points are in Anti-Clockwise/Clockwise direction respectively */
    
    int32_t i32Value = (int32_t) ((((pstTrngl->stPt2.u16X - pstTrngl->stPt1.u16X) >> 4) * ((pstTrngl->stPt1.u16Y - pstTrngl->stPt3.u16Y) >> 4)) -
                                    (((pstTrngl->stPt3.u16X - pstTrngl->stPt1.u16X) >> 4) * ((pstTrngl->stPt1.u16Y - pstTrngl->stPt2.u16Y) >> 4)));
    if(i32Value < 0)
    {
        return C_FALSE; /* Not in Anti clockwise direction */
    }
    else
    {
        return C_TRUE; /* In Anti clockwise direction */
    }
}


/******************************************************************************/

static void vGfDrawTriangleSort(gf_image_st * pstDstImage, drw_OpCfg_st *pstOption, drw_Trngl_st *pstTrngl, uint8_t u8AAEdge)
{
    drw_Trngl_st stTrnglSrt;
    uint16_t u16PosX, u16PosY;
    uint8_t u8AAFlag;

    u16PosX = 0U;
    u16PosY = 0U;
    stTrnglSrt = (*pstTrngl);
    u8AAFlag = u8AAEdge;
    
    /* Of the three points, point with minimum Y is chosen the 1st point and points 2 and 3 are
       sorted based on the return value from boIsAntiClockwise() function such that the
       vGfDrawTriangleSort() function sorts the co-ordinates in Counter clockwise direction */
     
    /* When Point 1 has minimum Y */
    if((pstTrngl->stPt1.u16Y <= pstTrngl->stPt2.u16Y) && (pstTrngl->stPt1.u16Y <= pstTrngl->stPt3.u16Y))
    {   
        /* Condition to select point with maximum X as 1st point when Y co-ordinates are equal */
       if((pstTrngl->stPt1.u16Y == pstTrngl->stPt2.u16Y) && (pstTrngl->stPt1.u16X < pstTrngl->stPt2.u16X))
       {
           stTrnglSrt.stPt1.u16X = pstTrngl->stPt2.u16X;
           stTrnglSrt.stPt1.u16Y = pstTrngl->stPt2.u16Y;
           
           stTrnglSrt.stPt2.u16X = pstTrngl->stPt3.u16X;
           stTrnglSrt.stPt2.u16Y = pstTrngl->stPt3.u16Y;
           
           stTrnglSrt.stPt3.u16X = pstTrngl->stPt1.u16X;
           stTrnglSrt.stPt3.u16Y = pstTrngl->stPt1.u16Y;
           
           /* Arranging AA edges according to the sorted co-ordinates */
           u8AAFlag = 0U;
           u8AAFlag = (((u8AAEdge & 4U ) >> 1U) | ((u8AAEdge & 2U) >> 1U) | ((u8AAEdge & 1U) << 2U));
       }
       /* Condition to select point with maximum X as 1st point when Y co-ordinates are equal */
       if((pstTrngl->stPt1.u16Y == pstTrngl->stPt3.u16Y) && (pstTrngl->stPt1.u16X < pstTrngl->stPt3.u16X))
       {
          stTrnglSrt.stPt1.u16X = pstTrngl->stPt3.u16X;
          stTrnglSrt.stPt1.u16Y = pstTrngl->stPt3.u16Y;
          
          stTrnglSrt.stPt2.u16X = pstTrngl->stPt1.u16X;
          stTrnglSrt.stPt2.u16Y = pstTrngl->stPt1.u16Y;
           
          stTrnglSrt.stPt3.u16X = pstTrngl->stPt2.u16X;
          stTrnglSrt.stPt3.u16Y = pstTrngl->stPt2.u16Y;
          
          /* Arranging AA edges according to the sorted co-ordinates */
          u8AAFlag = 0U;
          u8AAFlag = (((u8AAEdge & 4U) >> 2U) | ((u8AAEdge & 2U) << 1U) | ((u8AAEdge & 1U) << 1U));
       }
    }
    else if((pstTrngl->stPt2.u16Y <= pstTrngl->stPt1.u16Y) 
                    && (pstTrngl->stPt2.u16Y <= pstTrngl->stPt3.u16Y)) /* point 2 has minimum Y */
    {
        stTrnglSrt.stPt1.u16X = pstTrngl->stPt2.u16X;
        stTrnglSrt.stPt1.u16Y = pstTrngl->stPt2.u16Y;

        stTrnglSrt.stPt2.u16X = pstTrngl->stPt3.u16X;
        stTrnglSrt.stPt2.u16Y = pstTrngl->stPt3.u16Y;

        stTrnglSrt.stPt3.u16X = pstTrngl->stPt1.u16X;
        stTrnglSrt.stPt3.u16Y = pstTrngl->stPt1.u16Y;
            
        /* Arranging AA edges according to the sorted co-ordinates */
        u8AAFlag = 0U;
        u8AAFlag = (((u8AAEdge & 4U) >> 1U) | ((u8AAEdge & 2U) >> 1U) | ((u8AAEdge & 1U) << 2U));  
        
        /* Condition to select point with maximum X as 1st point when Y co-ordinates are equal */
        if((pstTrngl->stPt2.u16Y == pstTrngl->stPt1.u16Y) && (pstTrngl->stPt2.u16X < pstTrngl->stPt1.u16X))
        {
            stTrnglSrt.stPt1.u16X = pstTrngl->stPt1.u16X;
            stTrnglSrt.stPt1.u16Y = pstTrngl->stPt1.u16Y;
            
            stTrnglSrt.stPt2.u16X = pstTrngl->stPt2.u16X;
            stTrnglSrt.stPt2.u16Y = pstTrngl->stPt2.u16Y;

            stTrnglSrt.stPt3.u16X = pstTrngl->stPt3.u16X;
            stTrnglSrt.stPt3.u16Y = pstTrngl->stPt3.u16Y;
            
            /* Arranging AA edges according to the sorted co-ordinates */
            u8AAFlag = 0U;
            u8AAFlag = u8AAEdge;
        }
        /* Condition to select point with maximum X as 1st point when Y co-ordinates are equal */
        if((pstTrngl->stPt2.u16Y == pstTrngl->stPt3.u16Y) && (pstTrngl->stPt2.u16X < pstTrngl->stPt3.u16X))
        {
            stTrnglSrt.stPt1.u16X = pstTrngl->stPt3.u16X;
            stTrnglSrt.stPt1.u16Y = pstTrngl->stPt3.u16Y;
            
            stTrnglSrt.stPt2.u16X = pstTrngl->stPt1.u16X;
            stTrnglSrt.stPt2.u16Y = pstTrngl->stPt1.u16Y;

            stTrnglSrt.stPt3.u16X = pstTrngl->stPt2.u16X;
            stTrnglSrt.stPt3.u16Y = pstTrngl->stPt2.u16Y;
            
            /* Arranging AA edges according to the sorted co-ordinates */
            u8AAFlag = 0U;
            u8AAFlag = (((u8AAEdge & 4U) >> 2U) | ((u8AAEdge & 2U) << 1U) | ((u8AAEdge & 1U) << 1U));
        }
        
    }
    else /* Point 3 has minimum Y */
    {
        stTrnglSrt.stPt1.u16X = pstTrngl->stPt3.u16X;
        stTrnglSrt.stPt1.u16Y = pstTrngl->stPt3.u16Y;//y3 is small;
        
        stTrnglSrt.stPt2.u16X = pstTrngl->stPt1.u16X;
        stTrnglSrt.stPt2.u16Y = pstTrngl->stPt1.u16Y;

        stTrnglSrt.stPt3.u16X = pstTrngl->stPt2.u16X;
        stTrnglSrt.stPt3.u16Y = pstTrngl->stPt2.u16Y;
        
        /* Arranging AA edges according to the sorted co-ordinates */
        u8AAFlag = 0U;
        u8AAFlag = (((u8AAEdge & 4U) >> 2U) | ((u8AAEdge & 2U) << 1U) | ((u8AAEdge & 1U) << 1U));
    }
    
    /* Check if point 2 and 3 are in anti clockwise direction and swap if in clockwise direction */    
    if(!(boIsAntiClockwise(&stTrnglSrt)))
    {
        /* swap points 2 and 3 */
        u16PosX = stTrnglSrt.stPt2.u16X;
        u16PosY = stTrnglSrt.stPt2.u16Y;
        
        stTrnglSrt.stPt2.u16X = stTrnglSrt.stPt3.u16X;
        stTrnglSrt.stPt2.u16Y = stTrnglSrt.stPt3.u16Y;

        stTrnglSrt.stPt3.u16X = u16PosX;
        stTrnglSrt.stPt3.u16Y = u16PosY;
        
        /* Arranging AA edges according to the sorted co-ordinates */
        u8AAFlag = (((u8AAFlag & 4U) >> 2U) | (u8AAFlag & 2U) | ((u8AAFlag & 1U) << 2U));
    }
    /* Enabling / Disabling AA effect for Edge 1 */
    stTrnglSrt.eAntialEn1 = (ga_en_e)(u8AAFlag & 1U);

    /* Enabling / Disabling AA effect for Edge 2 */
    stTrnglSrt.eAntialEn2 = (ga_en_e)((u8AAFlag & 2U) >> 1U);

    /* Enabling / Disabling AA effect for Edge 3 */
    stTrnglSrt.eAntialEn3 = (ga_en_e)((u8AAFlag & 4U) >> 2U);

     /* Call Draw triangle API to fill polygon */
    vGfBuffDrawTriangle(pstDstImage, pstOption, &stTrnglSrt);

}


/****************************************************************************/

static void vGfDrawCircleWithEndCaps(gf_image_st *pstDstImage, drw_OpCfg_st *pstOption, gf_circle_st *pstCircle)
{
    drw_Line_st stLine;
    
    stLine.stPtStart.u16X = pstCircle->stCenter.u16X;
    stLine.stPtStart.u16Y = pstCircle->stCenter.u16Y;
    
    /* a difference of 1/16 is added to the end X co-ordinate since a line with same start and end
       points cannot be drawn by draw engine */
    stLine.stPtEnd.u16X = pstCircle->stCenter.u16X + 1U;
    stLine.stPtEnd.u16Y = pstCircle->stCenter.u16Y;
    
    /* Circular end caps are used on both ends to get the circle */
    stLine.eStartCap = DRW_CIRCULAR;
    stLine.eEndCap   = DRW_CIRCULAR;
    stLine.stColor   = pstCircle->stColor;
    
    /* Double the radius will give thickness for the line */
    stLine.u16Thickness = pstCircle->u16Radius * 2U;
    
    vGfBuffDrawLine(pstDstImage, pstOption, &stLine);
}


/******************************************************************************/

static uint32_t u32GfGetMinXCoordinate(void)
{
    uint32_t u32Cnt, u32Value;
    int16_t i16Value;
    u32Value = au32Coordinate[0][0];
    i16Value = (int16_t)(au32Coordinate[0][0]);

    for (u32Cnt=1U; u32Cnt<4U; u32Cnt++)
    {
        if ((int16_t)(au32Coordinate[u32Cnt][0])<(i16Value))
        {
            i16Value = (int16_t)(au32Coordinate[u32Cnt][0]);
        }
    }
    /* If negative coordinate  */
    if(i16Value < 0)
    {
        u32Value = 1<<4;
    }
    else 
    {
        u32Value = (uint32_t)(i16Value);
    }
    return u32Value>>4;
}


/****************************************************************************/

static uint32_t u32GfGetMinYCoordinate(void)
{
    uint32_t u32Cnt, u32Value;
    int16_t i16Value;
    u32Value = au32Coordinate[0][1];
    i16Value = (int16_t)(au32Coordinate[0][1]);
    for (u32Cnt=1U; u32Cnt<4U; u32Cnt++)
    {
        if ((int16_t)(au32Coordinate[u32Cnt][1])<(i16Value))
        {
            i16Value = (int16_t)(au32Coordinate[u32Cnt][1]);
        }
    }
    /* If negative coordinate  */
     if(i16Value < 0)
    {
        u32Value = 1<<4;
    }
    else 
    {
        u32Value = (uint32_t)(i16Value);
    }
    return u32Value>>4;
}


/****************************************************************************/

static uint32_t u32GfGetMaxXCoordinate(void)
{
    uint32_t u32Cnt, u32Value;
    int16_t i16Value;
    u32Value = au32Coordinate[0][0];
    i16Value = (int16_t)(au32Coordinate[0][0]);
    for (u32Cnt=1U; u32Cnt<4U; u32Cnt++)
    {
        if (((int16_t)(au32Coordinate[u32Cnt][0]))>(i16Value))
        {
            i16Value = (signed short int)(au32Coordinate[u32Cnt][0]);
        }
    }
    
    /* If negative coordinate  */
    if(i16Value < 0)
    {
        i16Value = (-1)<<4;
    }
    
    u32Value = (uint32_t)(i16Value);
   
    return u32Value>>4;
}


/****************************************************************************/

static uint32_t u32GfGetMaxYCoordinate(void)
{
    uint32_t u32Cnt, u32Value;
    int16_t i16Value;
    u32Value = au32Coordinate[0][1];
    i16Value = (int16_t)(au32Coordinate[0][1]);
    for (u32Cnt=1U; u32Cnt<4U; u32Cnt++)
    {
        if (((int16_t)(au32Coordinate[u32Cnt][1]))>(i16Value))
        {
            i16Value = (int16_t)(au32Coordinate[u32Cnt][1]);
        }
    }
    
    /* If negative coordinate  */
    if(i16Value < 0)
    {
        i16Value = (-1)<<4;
    }
    
    u32Value = (uint32_t)(i16Value);
    return u32Value>>4;
}


/****************************************************************************/

void vGfWaitForVSync(gdc_ch_e eGDCNumber)
{
#ifdef MEASURE_TX
    uint32_t u32Measure;

    u32Measure = TIMER_GET();
#endif

    if (0U == biGetGDCDCR_PVSYNC(eGDCNumber))
    {
        while(1U == u32GDC_GetStatVSync(eGDCNumber)){}
    }
    else
    {
        while(0U == u32GDC_GetStatVSync(eGDCNumber)){}
    }

#ifdef MEASURE_TX
    u32Measure = TIMER_GET() - u32Measure;
    u32TimeMeasure = u32TimeMeasure + u32Measure;
#endif
}


/****************************************************************************/

uint32_t u32GfGetVSyncStatus(gdc_ch_e eGDCNumber)
{
    uint32_t u32Status;

    u32Status = u32GDC_GetStatVSync(eGDCNumber);

    return u32Status;
}


/****************************************************************************/

gf_ga_status_e eGfGetGAStatus(void)
{
    gf_ga_status_e eGAStatus;

    if ((u8GA_GetStatus() & 8U) == 0U)
    {
        eGAStatus = GA_BUSY;
    }
    else
    {
        eGAStatus = GA_IDLE;
    }

    return eGAStatus;
}


/****************************************************************************/

void vGfWaitForGA(void)
{
#ifdef MEASURE_TX
    uint32_t u32Measure;

    u32Measure = TIMER_GET();
#endif

    while((u8GA_GetStatus() & 8U) == 0U){}

#ifdef MEASURE_TX
    u32Measure = TIMER_GET() - u32Measure;
    u32TimeMeasure = u32TimeMeasure + u32Measure;
    u32TimeMeasureGA = u32TimeMeasureGA + u32Measure;
#endif
}


/****************************************************************************/

void vGfWaitForPNGDecode(png_stream_e eStream)
{
#ifdef MEASURE_TX
    uint32_t u32Measure;

    u32Measure = TIMER_GET();
#endif

    while (ePNG_GetStreamPhaseStatus(eStream) == PNG_DECODE_PHASE){}

#ifdef MEASURE_TX
    u32Measure = TIMER_GET() - u32Measure;
    u32TimeMeasure = u32TimeMeasure + u32Measure;
    u32TimeMeasureGA = u32TimeMeasureGA + u32Measure;
#endif
}


/****************************************************************************/

void vGfInitMWStateVariable(void)
{
    stGastate.eRedChPrtEn       = GA_DIS;              /* RED channel Protection enable */
    stGastate.eGreenChPrtEn     = GA_DIS;              /* GREEN channel Protection enable */
    stGastate.eBlueChPrtEn      = GA_DIS;              /* BLUE channel Protection enable */
    stGastate.eAlphaChPrtEn     = GA_DIS;              /* ALPHA channel Protection enable */

    stGastate.eSrcRedFad        = GA_DIS;              /* RED channel Fading enable */
    stGastate.eSrcGreenFad      = GA_DIS;              /* GREEN channel Fading enable */
    stGastate.eSrcBlueFad       = GA_DIS;              /* BLUE channel Fading enable */
    stGastate.eSrcAlphaFad      = GA_DIS;              /* ALPHA channel Fading enable */

    stGastate.eFilterEn         = GA_EN;               /* Filter enable */

    stGastate.eBlndOrder        = GA_ONTO_DEST;        /* Blending Order */

    stGastate.eFadeMode         = BLT_NOFADING;        /* Fading Option */
    stGastate.u8FadingFctr      = 0xFFU;               /* Fading factor */

    stGastate.eTranspColEn      = GA_DIS;              /* Transp. Col. Opt. (only 16-bit src) */
    stGastate.u32SrcTransVal    = 0xFFU;               /* Src. Transpar. Pattern (STPR reg.) */
    stGastate.u16DstTransVal    = 0xFFU;               /* Dest. Transp. Pattern (DTR reg.) */

    stGastate.u8SrcAlphaVal     = 0xFFU;               /* Source Alpha Value */
    stGastate.u8DstAlphaVal     = 0xFFU;               /* Destination Alpha Value */

    stGastate.eTsfMode          = TSF_MODE_PIXEL;      /* Transform. Mode (Pixel-/Color-Mode) */
    stGastate.u32TsfPredefColor = 0x00000000U;         /* Predefined color for transformation */

    stGastate.eRastOpEn         = GA_DIS;              /* Enabling the Raster Operation */
    stGastate.eRastOpMode       = BLT_RGBA_CH;         /* Raster Operation Mode */
    stGastate.eRastOpValue      = BLT_RAST_S_AND_D;    /* Raster Operation Value */

    stGastate.eClipWndEn        = GA_DIS;              /* Clip window enable */
    stGastate.u16ClipC1_X       = 0U;                  /* point C1 x-position */
    stGastate.u16ClipC1_Y       = 0U;                  /* point C1 y-position */
    stGastate.u16ClipC2_X       = 1U;                  /* point C2 x-position */
    stGastate.u16ClipC2_Y       = 1U;                  /* point C2 y-position */

    u32NeedleNumber             = 0U;                  /* needle to be rotated */
}


/****************************************************************************/

void vGfSetNeedleNumber(uint32_t u32Number)
{
    if (u32Number > 3U)
    {
        u32Number = 3U;
    }

    u32NeedleNumber = 5U * u32Number;
}


/****************************************************************************/

uint32_t u32GfGetNeedleNumber(void)
{
    return u32NeedleNumber / 5U;
}


/****************************************************************************/

void vGfSetPaletteStream(void)
{
    u8PNG_PaletteStream6 = 1U;
    u8PNG_PaletteStream7 = 1U;
}


/****************************************************************************/

void vGfSetStateRedChanProtect(ga_en_e eEnable)
{
    stGastate.eRedChPrtEn   = GA_DIS;
    stGastate.eGreenChPrtEn = eEnable;
    stGastate.eBlueChPrtEn  = eEnable;
}


/****************************************************************************/

void vGfSetStateGreenChanProtect(ga_en_e eEnable)
{
    stGastate.eRedChPrtEn   = eEnable;
    stGastate.eGreenChPrtEn = GA_DIS;
    stGastate.eBlueChPrtEn  = eEnable;
}


/****************************************************************************/

void vGfSetStateBlueChanProtect(ga_en_e eEnable)
{
    stGastate.eRedChPrtEn   = eEnable;
    stGastate.eGreenChPrtEn = eEnable;
    stGastate.eBlueChPrtEn  = GA_DIS;
}


/****************************************************************************/

void vGfSetStateColorChanProtect(gf_colorprt_st stColorPrt)
{
    stGastate.eRedChPrtEn   = stColorPrt.eRedChPrtEn;
    stGastate.eGreenChPrtEn = stColorPrt.eGreenChPrtEn;
    stGastate.eBlueChPrtEn  = stColorPrt.eBlueChPrtEn;
}


/****************************************************************************/

gf_colorprt_st stGfGetStateColorChanProtect(void)
{
    gf_colorprt_st stColorPrt;

    stColorPrt.eRedChPrtEn   = stGastate.eRedChPrtEn;
    stColorPrt.eGreenChPrtEn = stGastate.eGreenChPrtEn;
    stColorPrt.eBlueChPrtEn  = stGastate.eBlueChPrtEn;

    return stColorPrt;
}


/****************************************************************************/

void vGfSetStateAlphaChanProtect(ga_en_e eEnable)
{
    stGastate.eAlphaChPrtEn = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateAlphaChanProtect(void)
{
    return stGastate.eAlphaChPrtEn;
}


/****************************************************************************/

void eGfSetStateRedChanFading(ga_en_e eEnable)
{
    stGastate.eSrcRedFad = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateRedChanFading(void)
{
    return stGastate.eSrcRedFad;
}


/****************************************************************************/

void eGfSetStateGreenChanFading(ga_en_e eEnable)
{
    stGastate.eSrcGreenFad = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateGreenChanFading(void)
{
    return stGastate.eSrcGreenFad;
}


/****************************************************************************/

void eGfSetStateBlueChanFading(ga_en_e eEnable)
{
    stGastate.eSrcBlueFad = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateBlueChanFading(void)
{
    return stGastate.eSrcBlueFad;
}


/****************************************************************************/

void eGfSetStateAlphaChanFading(ga_en_e eEnable)
{
    stGastate.eSrcAlphaFad = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateAlphaChanFading(void)
{
    return stGastate.eSrcAlphaFad;
}


/****************************************************************************/

void vGfSetStateFilter(ga_en_e eEnable)
{
    stGastate.eFilterEn = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateFilter(void)
{
    return stGastate.eFilterEn;
}


/****************************************************************************/

void vGfSetStateBlendOrder(ga_blendOrd_e eBlendOrder)
{
    stGastate.eBlndOrder = eBlendOrder;
}


/****************************************************************************/

ga_blendOrd_e eGfGetStateBlendOrder(void)
{
    return stGastate.eBlndOrder;
}


/****************************************************************************/

void vGfSetStateFadeMode(blt_fadeMode_e eFadeMode)
{
    stGastate.eFadeMode = eFadeMode;
}


/****************************************************************************/

blt_fadeMode_e eGfGetStateFadeMode(void)
{
    return stGastate.eFadeMode;
}


/****************************************************************************/

void vGfSetStateFadingFactor(uint8_t u8FadeFactor)
{
    stGastate.u8FadingFctr = u8FadeFactor;
}


/****************************************************************************/

uint8_t u8GfGetStateFadingFactor(void)
{
    return stGastate.u8FadingFctr;
}


/****************************************************************************/

void vGfSetStateTransparentColor(ga_en_e eEnable)
{
    stGastate.eTranspColEn = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateTransparentColor(void)
{
    return stGastate.eTranspColEn;
}


/****************************************************************************/

void vGfSetStateTransparencyValues(gf_transval_st stTransVal)
{
    stGastate.u32SrcTransVal = stTransVal.u32SrcTransVal;
    stGastate.u16DstTransVal = stTransVal.u16DstTransVal;
}


/****************************************************************************/

gf_transval_st stGfGetStateTransparencyValues(void)
{
    gf_transval_st stTransVal;

    stTransVal.u32SrcTransVal = stGastate.u32SrcTransVal;
    stTransVal.u16DstTransVal = stGastate.u16DstTransVal;

    return stTransVal;
}


/****************************************************************************/

void vGfSetStateAlphaValues(gf_alphaval_st stAlphaVal)
{
    stGastate.u8SrcAlphaVal = stAlphaVal.u8SrcAlphaVal;
    stGastate.u8DstAlphaVal = stAlphaVal.u8DstAlphaVal;
}


/****************************************************************************/

gf_alphaval_st stGfGetStateAlphaValues(void)
{
    gf_alphaval_st stAlphaVal;

    stAlphaVal.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stAlphaVal.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    return stAlphaVal;
}


/****************************************************************************/

void vGfSetStateTransformationMode(transf_Mode_e eTsfMode)
{
    stGastate.eTsfMode = eTsfMode;
}


/****************************************************************************/

transf_Mode_e eGfGetStateTransformationMode(void)
{
    return stGastate.eTsfMode;
}


/****************************************************************************/

void vGfSetStateTransformationPredefinedColor(uint32_t u32PredefColor)
{
    stGastate.u32TsfPredefColor = u32PredefColor;
}


/****************************************************************************/

uint32_t eGfGetStateTransformationPredefinedColor(void)
{
    return stGastate.u32TsfPredefColor;
}


/****************************************************************************/

void vGfSetStateRasterOperationModeEnable(ga_en_e eEnable)
{
    stGastate.eRastOpEn = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateRasterOperationModeEnable(void)
{
    return stGastate.eRastOpEn;
}


/****************************************************************************/

void vGfSetStateRasterOperationMode(blt_rastChSel_e eRastOpMode)
{
    stGastate.eRastOpMode = eRastOpMode;
}


/****************************************************************************/

blt_rastChSel_e eGfGetStateRasterOperationMode(void)
{
    return stGastate.eRastOpMode;
}


/****************************************************************************/

void vGfSetStateRasterOperationValue(blt_rastOpVal_e eRastOpValue)
{
    stGastate.eRastOpValue = eRastOpValue;
}


/****************************************************************************/

blt_rastOpVal_e eGfGetStateRasterOperationValue(void)
{
    return stGastate.eRastOpValue;
}


/****************************************************************************/

void vGfSetStateClipWindow(ga_en_e eEnable)
{
    stGastate.eClipWndEn = eEnable;
}


/****************************************************************************/

ga_en_e eGfGetStateClipWindow(void)
{
    return stGastate.eClipWndEn;
}


/****************************************************************************/

void vGfSetStateClipWindowCoordinates(uint16_t u16ClipC1_X, uint16_t u16ClipC1_Y, uint16_t u16ClipC2_X, uint16_t u16ClipC2_Y)
{
    stGastate.u16ClipC1_X = u16ClipC1_X;
    stGastate.u16ClipC1_Y = u16ClipC1_Y;
    stGastate.u16ClipC2_X = u16ClipC2_X;
    stGastate.u16ClipC2_Y = u16ClipC2_Y;
}


/****************************************************************************/

void vGfSetSubRes(gf_subRes_e eResPPos, gf_subRes_e eResCPos)
{
    if (eResPPos == GA_PIXEL_RES)
    {
      f32SubResPPos = 16.0;
      u32SubResPPos = 16;
    }
    else
    {
      f32SubResPPos = 1.0;
      u32SubResPPos = 1;
    }

    if (eResCPos == GA_PIXEL_RES)
    {
      f32SubResCPos = 16.0;
      u32SubResCPos = 16;
    }
    else
    {
      f32SubResCPos = 1.0;
      u32SubResCPos = 1;
    }
}


/****************************************************************************/

float32_t f32GfGetSubRes_Position(void)
{
    return f32SubResPPos;
}


/****************************************************************************/

uint32_t u32GfGetSubRes_Position(void)
{
    return u32SubResPPos;
}


/****************************************************************************/

float32_t f32GfGetSubRes_CenterPosition(void)
{
    return f32SubResCPos;
}


/****************************************************************************/

uint32_t u32GfGetSubRes_CenterPosition(void)
{
    return u32SubResCPos;
}


/****************************************************************************/

static ga_en_e eHandleClipWindowBlit(gf_image_st * pstDstImage, uint16_t u16SrcWidth, uint16_t u16SrcHeight, ga_en_e eClipWndEn, int32_t i32PosX, int32_t i32PosY)
{
    uint32_t u32ClipStartAddr;
    uint16_t u16C1_X, u16C1_Y, u16C2_X, u16C2_Y;
    int32_t i32S1X, i32S1Y, i32S2X, i32S2Y;
    uint16_t u16UlX, u16UlY, u16LrX, u16LrY;
    ga_en_e  eCwEn = GA_DIS;
    uint8_t  u8DstNoOfBytes;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        u8DstNoOfBytes = 2U;
    }
    else
    {
        u8DstNoOfBytes = 4U;
    }

    if(eClipWndEn == GA_EN)
    {
        u16C1_X = stGastate.u16ClipC1_X;
        u16C1_Y = stGastate.u16ClipC1_Y;
        u16C2_X = stGastate.u16ClipC2_X;
        u16C2_Y = stGastate.u16ClipC2_Y;
    }
    else
    {
        u16C1_X = 0;
        u16C1_Y = 0;
        u16C2_X = 0;
        u16C2_Y = 0;
    }
    
    i32S1X = i32PosX;
    i32S1Y = i32PosY;
    i32S2X = i32PosX + (int32_t)u16SrcWidth;
    i32S2Y = i32PosY + (int32_t)u16SrcHeight;
    
    if((eClipWndEn == GA_EN) && (i32PosX >= 0) && (i32PosY >= 0))
    {
        eCwEn = GA_EN;
        /* check for overlapping region */
        if(((((int32_t)u16C1_X - i32S2X) ^ ((int32_t)u16C2_X  - i32S1X)) & (((int32_t)u16C1_Y - i32S2Y) ^ ((int32_t)u16C2_Y  - i32S1Y))) < 0)
        {
            /* calculate general start address of clip window */
            u32ClipStartAddr = pstDstImage->u32Address + u8DstNoOfBytes*(uint32_t)pstDstImage->u16Width*(uint32_t)u16C1_Y + u8DstNoOfBytes*(uint32_t)u16C1_X;
            vBlit_SetClippWnd(u32ClipStartAddr, u16C2_X-u16C1_X+1U, u16C2_Y-u16C1_Y+1U, pstWriteList);
        }
        else
        {
            /* no overlapping */
            eCwEn = GA_DIS;
        }        
    }
    else if((eClipWndEn == GA_EN) && ((i32PosX < 0) || (i32PosY < 0)))
    {
        eCwEn = GA_EN;

        /* Condition to check for overlap */
        if(((((int32_t)u16C1_X - i32S2X) ^ ((int32_t)u16C2_X  - i32S1X)) & (((int32_t)u16C1_Y - i32S2Y) ^ ( (int32_t)u16C2_Y  - i32S1Y))) < 0)
        {
        
            if (i32PosX <= 0)
            {
                u16UlX = u16C1_X;
                u16LrX = MIN_FLOAT(u16C2_X, (uint16_t)i32S2X - 1U);
            }
            else
            {
                u16UlX = (uint16_t)(ABS_INT(i32PosX));
                u16LrX = u16C2_X;
            }

            if (i32PosY <= 0)
            {
                u16UlY = u16C1_Y;
                u16LrY = MIN_FLOAT(u16C2_Y, (uint16_t)i32S2Y - 1U);
            }
            else
            {
                u16UlY = (uint16_t)(ABS_INT(i32PosY));
                u16LrY = u16C2_Y;
            }
            
            /* calculate general start address of clip window */
            u32ClipStartAddr = pstDstImage->u32Address + u8DstNoOfBytes*(uint32_t)pstDstImage->u16Width*(uint32_t)u16UlY + u8DstNoOfBytes*(uint32_t)u16UlX;
            vBlit_SetClippWnd(u32ClipStartAddr, u16LrX-u16UlX+1U, u16LrY-u16UlY+1U, pstWriteList);
        }
        else
        {
            /* There is no overlap between the clip window and the destination area */
            eCwEn = GA_DIS;
        }
    }
    else
    {
        /* Check for overlap with the */
        if((((- i32S2X) ^ ((int32_t)(pstDstImage->u16Width - 1U)  - i32S1X)) & ((- i32S2Y) ^ ( (int32_t)(pstDstImage->u16Height - 1U)  - i32S1Y))) <= 0)
        {
            /* If clip window is disabled */
            eCwEn = GA_EN;
            /* Calculate the clip window coordiantes */
            if (i32PosX < 0)
            {
                u16UlX = 0;
                u16LrX = MIN_FLOAT(u16SrcWidth - (uint16_t)(ABS_INT(i32PosX)) - 1U, (pstDstImage->u16Width - 1U));
            }
            else
            {
                u16UlX = (uint16_t)(i32PosX);
                u16LrX = u16SrcWidth + u16UlX - 1U;
                if(u16LrX  > (pstDstImage->u16Width - 1U))
                {
                    u16LrX = pstDstImage->u16Width - 1U;
                }
            }

            if (i32PosY < 0)
            {
                u16UlY = 0;
                u16LrY = MIN_FLOAT(u16SrcHeight - (uint16_t)(ABS_INT(i32PosY)) - 1U, (pstDstImage->u16Height - 1U) );
            }
            else
            {
                u16UlY = (uint16_t)(i32PosY);
                u16LrY = u16SrcHeight + u16UlY - 1U;
                if( u16LrY > (pstDstImage->u16Height - 1U) )
                {
                    u16LrY = pstDstImage->u16Height - 1U;
                }
            }
            u32ClipStartAddr = pstDstImage->u32Address + u8DstNoOfBytes*(uint32_t)pstDstImage->u16Width*(uint32_t)u16UlY + u8DstNoOfBytes*(uint32_t)u16UlX;
            vBlit_SetClippWnd(u32ClipStartAddr, u16LrX-u16UlX+1U, u16LrY-u16UlY+1U, pstWriteList);
        }
        else
        {
            /* Image is outside the destination area. So no need to make a draw call */
            eCwEn = GA_DIS;
        }
    }
    return eCwEn;
}


/****************************************************************************/

void vGfBuffFillArea(gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart, uint32_t u32Color)
{
    blit_mem_st      stMem;
    blit_OvrRgbP_st  stParam;
    ga_en_e eDraw;
    u8PreviousOperation = 0U;

    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstImgPart->u16Width;
    stMem.u16LineCnt  = pstImgPart->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstImgPart->u16Width, pstImgPart->u16Height, stGastate.eClipWndEn, (int32_t)pstImgPart->u16SrcOffsX, (int32_t)pstImgPart->u16SrcOffsY);

    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U* (uint32_t)pstDstImage->u16Width * (uint32_t)pstImgPart->u16SrcOffsY + 2U*(uint32_t)pstImgPart->u16SrcOffsX;
            stParam.eSrcFmt  = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U* (uint32_t)pstDstImage->u16Width * (uint32_t)pstImgPart->u16SrcOffsY + 4U*(uint32_t)pstImgPart->u16SrcOffsX;
            stParam.eSrcFmt  = GA_RGBA32;
        }

        stParam.eFadeMode    = stGastate.eFadeMode;
        stParam.u8FadingFctr = stGastate.u8FadingFctr;

        stParam.u32Color     = u32Color;

        vBlit_OverwriteFillRGB(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

uint32_t u32GfBuffBlitBitmapFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                                 int32_t i32PosX, int32_t i32PosY)
{
    uint32_t u32Error;

    if (pstSrcImage->eFormat <= (uint8_t)FMT_RGB16)
    {
        switch (pstSrcImage->eFormat)
        {
            case FMT_RGBA32:
                vGfBuffBlitBitmapFull(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                u32Error = 0U;
                break;
            case FMT_RGB16:
                vGfBuffBlitBitmapFull(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                u32Error = 0U;
                break;
            default: u32Error = 1U;
                break;
        }
    }
    else
    {
        if (pstSrcImage->eFormat >= (uint8_t)FMT_PNGRGBA32)
        {
            vGfBuffBlitBitmapFull(pstSrcImage, pstDstImage, i32PosX, i32PosY);
            u32Error = 0U;
        }
        else
        {
            switch (pstSrcImage->eFormat)
            {
                case FMT_RLERGBA32:
                    vGfBuffBlitBitmapRLE32(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                    u32Error = 0U;
                    break;
                case FMT_RLERGBA24:
                    vGfBuffBlitBitmapRLE24A(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                    u32Error = 0U;
                    break;
                case FMT_RLERGB24:
                    vGfBuffBlitBitmapRLE24(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                    u32Error = 0U;
                    break;
                case FMT_RLERGB16:
                    vGfBuffBlitBitmapRLE16(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                    u32Error = 0U;
                    break;
                default: u32Error = 1U;
                    break;
            }
        }
    }

    return u32Error;
}


/****************************************************************************/

void vGfBuffBlitBitmapFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                           int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st     stMem;
    blit_OvrRgb_st  stParam;
    ga_en_e eDraw;

    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    if (pstSrcImage->eFormat < (uint8_t)FMT_PNGRGBA32)
    {
        u8PreviousOperation = 0U;

        stMem.u32SrcAddr = pstSrcImage->u32Address;
        if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stParam.eSrcFmt = GA_RGB16;
        }
        else
        {
            stParam.eSrcFmt = GA_RGBA32;
        }
    }
    else
    {
        if (u8PreviousOperation == 0U)
        {
            vGfWaitForGA();
        }
        u8PreviousOperation = 1U;

        /* png */
        if (u8PNG_Decoder == 0U)
        {
            /* Palette Stream */
            if(pstSrcImage->u32Paletteaddress && u8PNG_PaletteStream6)
            {
                i32PNG_SetUpStream(PNG_STREAM_6, pstSrcImage->u32Paletteaddress, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
                vGfWaitForPNGDecode(PNG_STREAM_6);
                u8PNG_PaletteStream6 = 0U;
            }
            i32PNG_SetUpStream(PNG_STREAM_6, pstSrcImage->u32Address, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
            stMem.u32SrcAddr = (uint32_t)PNG_VIRTUAL_START_ADDRESS_STREAM_6;
            u8PNG_Decoder = 1U;
        }
        else
        {
            /* Palette Stream */
            if(pstSrcImage->u32Paletteaddress && u8PNG_PaletteStream7)
            {
                i32PNG_SetUpStream(PNG_STREAM_7, pstSrcImage->u32Paletteaddress, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
                vGfWaitForPNGDecode(PNG_STREAM_7);
                u8PNG_PaletteStream7 = 0U;
            }
            i32PNG_SetUpStream(PNG_STREAM_7, pstSrcImage->u32Address, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
            stMem.u32SrcAddr = (uint32_t)PNG_VIRTUAL_START_ADDRESS_STREAM_7;
            u8PNG_Decoder = 0U;
        }
        stParam.eSrcFmt = GA_RGBA32;
    }

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);
    
    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*(uint32_t)pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*(uint32_t)pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }   

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        vBlit_OverwriteRGB(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

uint32_t u32GfBuffBlitBitmapPart(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                                 uint32_t u32PosX, uint32_t u32PosY)
{
    uint32_t u32Error;

    if (pstSrcImage->eFormat <= (uint8_t)FMT_RGB16)
    {
        switch (pstSrcImage->eFormat)
        {
            case FMT_RGBA32:
                vGfBuffBlitBitmapPart(pstSrcImage, pstDstImage, pstImgPart, u32PosX, u32PosY);
                u32Error = 0U;
                break;
            case FMT_RGB16:
                vGfBuffBlitBitmapPart(pstSrcImage, pstDstImage, pstImgPart, u32PosX, u32PosY);
                u32Error = 0U;
                break;
            default: u32Error = 1U;
                break;
        }
    }
   else
    {
        if (pstSrcImage->eFormat >= (uint8_t)FMT_PNGRGBA32)
        {
            vGfBuffBlitBitmapPart(pstSrcImage, pstDstImage, pstImgPart, u32PosX, u32PosY);
            u32Error = 0U;
        }
        else
        {
            u32Error = 1U;
        }
    }

   return u32Error;
}


/****************************************************************************/

void vGfBuffBlitBitmapPart(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                           uint32_t u32PosX, uint32_t u32PosY)
{
    blit_mem_st     stMem;
    blit_OvrRgb_st  stParam;
    ga_en_e eDraw;

    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstImgPart->u16Width;
    stMem.u16LineCnt  = pstImgPart->u16Height;
    
    if(pstSrcImage->eFormat < (uint8_t)FMT_PNGRGBA32)
    {
        u8PreviousOperation = 0U;

        if (pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32SrcAddr = pstSrcImage->u32Address + 2U*(uint32_t)pstSrcImage->u16Width * (uint32_t)pstImgPart->u16SrcOffsY + 2U*(uint32_t)pstImgPart->u16SrcOffsX;
            stParam.eSrcFmt  = GA_RGB16;
        }
        else
        {
            stMem.u32SrcAddr = pstSrcImage->u32Address + 4U*(uint32_t)pstSrcImage->u16Width * (uint32_t)pstImgPart->u16SrcOffsY + 4U*(uint32_t)pstImgPart->u16SrcOffsX;
            stParam.eSrcFmt  = GA_RGBA32;
        }
    }
    else
    {
        if (u8PreviousOperation == 0U)
        {
            vGfWaitForGA();
        }
        u8PreviousOperation = 1U;

        if (u8PNG_Decoder == 0U)
        {
            /* Palette Stream */
            if(pstSrcImage->u32Paletteaddress && u8PNG_PaletteStream6)
            {
                i32PNG_SetUpStream(PNG_STREAM_6, pstSrcImage->u32Paletteaddress, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
                vGfWaitForPNGDecode(PNG_STREAM_6);
                u8PNG_PaletteStream6 = 0U;
            }
            i32PNG_SetUpStream(PNG_STREAM_6, pstSrcImage->u32Address, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
            stMem.u32SrcAddr = (uint32_t)PNG_VIRTUAL_START_ADDRESS_STREAM_6 + 4U*(uint32_t)pstSrcImage->u16Width * (uint32_t)pstImgPart->u16SrcOffsY + 4U*(uint32_t)pstImgPart->u16SrcOffsX;
            u8PNG_Decoder = 1U;
        }
        else
        {
            /* Palette Stream */
            if(pstSrcImage->u32Paletteaddress && u8PNG_PaletteStream7)
            {
                i32PNG_SetUpStream(PNG_STREAM_7, pstSrcImage->u32Paletteaddress, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
                vGfWaitForPNGDecode(PNG_STREAM_7);
                u8PNG_PaletteStream7 = 0U;
            }
            i32PNG_SetUpStream(PNG_STREAM_7, pstSrcImage->u32Address, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
            stMem.u32SrcAddr = (uint32_t)PNG_VIRTUAL_START_ADDRESS_STREAM_7 + 4U*(uint32_t)pstSrcImage->u16Width * (uint32_t)pstImgPart->u16SrcOffsY + 4U*(uint32_t)pstImgPart->u16SrcOffsX;
            u8PNG_Decoder = 0U;
        }
        stParam.eSrcFmt = GA_RGBA32;
    }

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstImgPart->u16Width, pstImgPart->u16Height, stGastate.eClipWndEn, u32PosX, u32PosY);

    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;

        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*(uint32_t)pstDstImage->u16Width * u32PosY + 2U*u32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*(uint32_t)pstDstImage->u16Width * u32PosY + 4U*u32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        vBlit_OverwriteRGB(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlitBitmapRLE16(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                            int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st       stMem;
    blit_OvrRlei_st   stParam;
    ga_en_e eDraw;
    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);
    
    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*(uint32_t)pstDstImage->u16Width * i32PosY + 2U*i32PosX; 
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*(uint32_t)pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRleiFmt = RLEI_OVRFMT_RGB16;
        vBlit_OverwriteRLEI_RGB(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlitBitmapRLE24(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                            int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st       stMem;
    blit_OvrRlei_st   stParam;
    ga_en_e eDraw;
    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);

    /* Draw only if there is an overlapping between clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*(uint32_t)pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*(uint32_t)pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRleiFmt = RLEI_OVRFMT_RGB24;
        vBlit_OverwriteRLEI_RGB(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlitBitmapRLE24A(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st       stMem;
    blit_OvrRleiA_st  stParam;
    ga_en_e eDraw;
    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);
    
    /* Draw only if there is an overlapping clip window and destinatio area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*(uint32_t)pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*(uint32_t)pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRleiFmt = RLEI_OVRFMT_RGBA24;
        vBlit_OverwriteRLEI_RGBA(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlitBitmapRLE32(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                            int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st       stMem;
    blit_OvrRleiA_st  stParam;
    ga_en_e eDraw;
    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);
    
    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*(uint32_t)pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*(uint32_t)pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRleiFmt = RLEI_OVRFMT_RGBA32;
        vBlit_OverwriteRLEI_RGBA(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlendFillArea(gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart, uint32_t u32Color)
{
    blit_mem_st        stMem;
    blit_BlndFill32_st stParam32;
    blit_BlndFill16_st stParam16;
    ga_en_e eDraw;
    u8PreviousOperation = 0U;

    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstImgPart->u16Width;
    stMem.u16LineCnt  = pstImgPart->u16Height;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        /* handle clip window */
        eDraw = eHandleClipWindowBlit(pstDstImage, pstImgPart->u16Width, pstImgPart->u16Height, stGastate.eClipWndEn, (int32_t)pstImgPart->u16SrcOffsX, (uint32_t)pstImgPart->u16SrcOffsY);
        
        /* Draw only if there is an overlapping clip windw and destination area */
        if(eDraw == GA_EN)
        {
            stParam16.eClipWndEn = eDraw;
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*(uint32_t)pstDstImage->u16Width * (uint32_t)pstImgPart->u16SrcOffsY + 2U*(uint32_t)pstImgPart->u16SrcOffsX;

            stParam16.eRedChPrtEn   = stGastate.eRedChPrtEn;
            stParam16.eGreenChPrtEn = stGastate.eGreenChPrtEn;
            stParam16.eBlueChPrtEn  = stGastate.eBlueChPrtEn;

            stParam16.eFadeMode     = stGastate.eFadeMode;
            stParam16.u8FadingFctr  = stGastate.u8FadingFctr;

            stParam16.eBlndOrder    = stGastate.eBlndOrder;

            stParam16.u16Color      = (uint16_t) u32Color;

            stParam16.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
            stParam16.u8DstAlphaVal = stGastate.u8DstAlphaVal;

            stParam16.eRastOpEn     = stGastate.eRastOpEn;
            stParam16.eRastOpMode   = stGastate.eRastOpMode;
            stParam16.eRastOpValue  = stGastate.eRastOpValue;

            vBlit_BlendFillRGB(&stMem, &stParam16, pstWriteList);
        }
    }
    else
    {
        /* handle clip window */
        eDraw = eHandleClipWindowBlit(pstDstImage, pstImgPart->u16Width, pstImgPart->u16Height, stGastate.eClipWndEn, (uint32_t)pstImgPart->u16SrcOffsX, (uint32_t)pstImgPart->u16SrcOffsY);

        /* Draw only if there is an overlapping clip window and destination area */
        if(eDraw == GA_EN)
        {
            stParam32.eClipWndEn = eDraw;
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*(uint32_t)pstDstImage->u16Width * (uint32_t)pstImgPart->u16SrcOffsY + 4U*(uint32_t)pstImgPart->u16SrcOffsX;

            stParam32.eRedChPrtEn   = stGastate.eRedChPrtEn;
            stParam32.eGreenChPrtEn = stGastate.eGreenChPrtEn;
            stParam32.eBlueChPrtEn  = stGastate.eBlueChPrtEn;
            stParam32.eAlphaChPrtEn = stGastate.eAlphaChPrtEn;

            stParam32.eFadeMode     = stGastate.eFadeMode;
            stParam32.u8FadingFctr  = stGastate.u8FadingFctr;

            stParam32.eBlndOrder    = stGastate.eBlndOrder;

            stParam32.u32Color      = u32Color;

            stParam32.eRastOpEn     = stGastate.eRastOpEn;
            stParam32.eRastOpMode   = stGastate.eRastOpMode;
            stParam32.eRastOpValue  = stGastate.eRastOpValue;

            vBlit_BlendFillRGBA(&stMem, &stParam32, pstWriteList);
        }
    }
}


/****************************************************************************/

uint32_t u32GfBuffBlendBitmapFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                                  int32_t i32PosX, int32_t i32PosY)
{
    uint32_t u32Error;

    if (pstSrcImage->eFormat <= (uint8_t)FMT_RGB16)
    {
        switch (pstSrcImage->eFormat)
        {
            case FMT_RGBA32:
                vGfBuffBlendBitmapFull(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                u32Error = 0U;
                break;
            case FMT_RGB16:
                vGfBuffBlendBitmapFull(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                u32Error = 0U;
                break;
            default: u32Error = 1U;
                break;
        }
    }
    else
    {
        if (pstSrcImage->eFormat >= (uint8_t)FMT_PNGRGBA32)
        {
            vGfBuffBlendBitmapFull(pstSrcImage, pstDstImage, i32PosX, i32PosY);
            u32Error = 0U;
        }
        else
        {
            switch (pstSrcImage->eFormat)
            {
                case FMT_RLERGBA32:
                    vGfBuffBlendBitmapRLE32(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                    u32Error = 0U;
                    break;
                case FMT_RLERGBA24:
                    vGfBuffBlendBitmapRLE24A(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                    u32Error = 0U;
                    break;
                case FMT_RLERGB24:
                    vGfBuffBlendBitmapRLE24(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                    u32Error = 0U;
                    break;
                case FMT_RLERGB16:
                    vGfBuffBlendBitmapRLE16(pstSrcImage, pstDstImage, i32PosX, i32PosY);
                    u32Error = 0U;
                    break;
                default: u32Error = 1U;
                    break;
            }
        }
    }

    return u32Error;
}


/****************************************************************************/

void vGfBuffBlendBitmapFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                            int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st     stMem;
    blit_BlndRgb_st stParam;
    ga_en_e eDraw;

    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    if (pstSrcImage->eFormat < (uint8_t)FMT_PNGRGBA32)
    {
        u8PreviousOperation = 0U;

        stMem.u32SrcAddr = pstSrcImage->u32Address;
        if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stParam.eSrcFmt = GA_RGB16;
        }
        else
        {
            stParam.eSrcFmt = GA_RGBA32;
        }
    }
    else
    {
        if (u8PreviousOperation == 0U)
        {
            vGfWaitForGA();
        }
        u8PreviousOperation = 1U;

        if (u8PNG_Decoder == 0U)
        {
            /* Palette Stream */
            if(pstSrcImage->u32Paletteaddress && u8PNG_PaletteStream6)
            {
                i32PNG_SetUpStream(PNG_STREAM_6, pstSrcImage->u32Paletteaddress, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
                vGfWaitForPNGDecode(PNG_STREAM_6);
                u8PNG_PaletteStream6 = 0U;
            }
            i32PNG_SetUpStream(PNG_STREAM_6, pstSrcImage->u32Address, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
            stMem.u32SrcAddr = (uint32_t)PNG_VIRTUAL_START_ADDRESS_STREAM_6;
            u8PNG_Decoder = 1U;
        }
        else
        {
            /* Palette Stream */
            if(pstSrcImage->u32Paletteaddress && u8PNG_PaletteStream7)
            {
                i32PNG_SetUpStream(PNG_STREAM_7, pstSrcImage->u32Paletteaddress, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
                vGfWaitForPNGDecode(PNG_STREAM_7);
                u8PNG_PaletteStream7 = 0U;
            }
            i32PNG_SetUpStream(PNG_STREAM_7, pstSrcImage->u32Address, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
            stMem.u32SrcAddr = (uint32_t)PNG_VIRTUAL_START_ADDRESS_STREAM_7;
            u8PNG_Decoder = 0U;
        }
        stParam.eSrcFmt = GA_RGBA32;
    }

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);

    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*(uint32_t)pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*(uint32_t)pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eRedChPrtEn    = stGastate.eRedChPrtEn;
        stParam.eGreenChPrtEn  = stGastate.eGreenChPrtEn;
        stParam.eBlueChPrtEn   = stGastate.eBlueChPrtEn;
        stParam.eAlphaChPrtEn  = stGastate.eAlphaChPrtEn;

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.eBlndOrder     = stGastate.eBlndOrder;

        stParam.eTranspColEn   = stGastate.eTranspColEn;

        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRastOpEn      = stGastate.eRastOpEn;
        stParam.eRastOpMode    = stGastate.eRastOpMode;
        stParam.eRastOpValue   = stGastate.eRastOpValue;

        i32Blit_BlendRGB(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

uint32_t u32GfBuffBlendBitmapPart(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                                  uint32_t u32PosX, uint32_t u32PosY)
{
    uint32_t u32Error;

    if (pstSrcImage->eFormat <= (uint8_t)FMT_RGB16)
    {
        switch (pstSrcImage->eFormat)
        {
            case FMT_RGBA32:
                vGfBuffBlendBitmapPart(pstSrcImage, pstDstImage, pstImgPart, u32PosX, u32PosY);
                u32Error = 0U;
                break;
            case FMT_RGB16:
                vGfBuffBlendBitmapPart(pstSrcImage, pstDstImage, pstImgPart, u32PosX, u32PosY);
                u32Error = 0U;
                break;
            default: u32Error = 1U;
                break;
        }
    }
    else
    {
        if (pstSrcImage->eFormat >= FMT_PNGRGBA32)
        {
            vGfBuffBlendBitmapPart(pstSrcImage, pstDstImage, pstImgPart, u32PosX, u32PosY);
            u32Error = 0U;
        }
        else
        {
            u32Error = 1U;
        }
    }

    return u32Error;
}


/****************************************************************************/

void vGfBuffBlendBitmapPart(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                            uint32_t u32PosX, uint32_t u32PosY)
{
    blit_mem_st     stMem;
    blit_BlndRgb_st stParam;
    ga_en_e eDraw;

    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstImgPart->u16Width;
    stMem.u16LineCnt  = pstImgPart->u16Height;

    if(pstSrcImage->eFormat < FMT_PNGRGBA32)
    {
        u8PreviousOperation = 0U;

        if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32SrcAddr = pstSrcImage->u32Address + 2U*pstSrcImage->u16Width * pstImgPart->u16SrcOffsY + 2U*pstImgPart->u16SrcOffsX;
            stParam.eSrcFmt  = GA_RGB16;
        }
        else
        {
            stMem.u32SrcAddr = pstSrcImage->u32Address + 4U*pstSrcImage->u16Width * pstImgPart->u16SrcOffsY + 4U*pstImgPart->u16SrcOffsX;
            stParam.eSrcFmt  = GA_RGBA32;
        }
    }
    else
    {
        if (u8PreviousOperation == 0U)
        {
            vGfWaitForGA();
        }
        u8PreviousOperation = 1U;

        if (u8PNG_Decoder == 0U)
        {
            /* Palette Stream */
            if(pstSrcImage->u32Paletteaddress && u8PNG_PaletteStream6)
            {
                i32PNG_SetUpStream(PNG_STREAM_6, pstSrcImage->u32Paletteaddress, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
                vGfWaitForPNGDecode(PNG_STREAM_6);
                u8PNG_PaletteStream6 = 0U;
            }
            i32PNG_SetUpStream(PNG_STREAM_6, pstSrcImage->u32Address, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, pstSrcImage->u16Width, pstSrcImage->u16Height);
            stMem.u32SrcAddr = PNG_VIRTUAL_START_ADDRESS_STREAM_6 + 4U*pstSrcImage->u16Width * pstImgPart->u16SrcOffsY + 4U*pstImgPart->u16SrcOffsX;
            u8PNG_Decoder = 1U;
        }
        else
        {
            /* Palette Stream */
            if(pstSrcImage->u32Paletteaddress && u8PNG_PaletteStream7)
            {
                i32PNG_SetUpStream(PNG_STREAM_7, pstSrcImage->u32Paletteaddress, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, (uint32_t)pstSrcImage->u16Width, (uint32_t)pstSrcImage->u16Height);
                vGfWaitForPNGDecode(PNG_STREAM_7);
                u8PNG_PaletteStream7 = 0U;
            }
            i32PNG_SetUpStream(PNG_STREAM_7, pstSrcImage->u32Address, PNG_SINGLE_DECODE_MODE, PNG_OUTPUT_FORMAT_RGBA32, pstSrcImage->u16Width, pstSrcImage->u16Height);
            stMem.u32SrcAddr = PNG_VIRTUAL_START_ADDRESS_STREAM_7 + 4U*pstSrcImage->u16Width * pstImgPart->u16SrcOffsY + 4U*pstImgPart->u16SrcOffsX;
            u8PNG_Decoder = 0U;
        }
        stParam.eSrcFmt = GA_RGBA32;
    }

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstImgPart->u16Width, pstImgPart->u16Height, stGastate.eClipWndEn, u32PosX, u32PosY);

    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        /* Dest. address calculation */
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*pstDstImage->u16Width * u32PosY + 2U*u32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*pstDstImage->u16Width * u32PosY + 4U*u32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eRedChPrtEn    = stGastate.eRedChPrtEn;
        stParam.eGreenChPrtEn  = stGastate.eGreenChPrtEn;
        stParam.eBlueChPrtEn   = stGastate.eBlueChPrtEn;
        stParam.eAlphaChPrtEn  = stGastate.eAlphaChPrtEn;

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.eBlndOrder     = stGastate.eBlndOrder;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRastOpEn      = stGastate.eRastOpEn;
        stParam.eRastOpMode    = stGastate.eRastOpMode;
        stParam.eRastOpValue   = stGastate.eRastOpValue;

        i32Blit_BlendRGB(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlendBitmapRLE16(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st        stMem;
    blit_BlndRlei_st   stParam;
    ga_en_e eDraw;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);
    
    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eRedChPrtEn    = stGastate.eRedChPrtEn;
        stParam.eGreenChPrtEn  = stGastate.eGreenChPrtEn;
        stParam.eBlueChPrtEn   = stGastate.eBlueChPrtEn;
        stParam.eAlphaChPrtEn  = stGastate.eAlphaChPrtEn;

        stParam.eBlndOrder     = stGastate.eBlndOrder;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRastOpEn      = stGastate.eRastOpEn;
        stParam.eRastOpMode    = stGastate.eRastOpMode;
        stParam.eRastOpValue   = stGastate.eRastOpValue;

        stParam.eRleiFmt = RLEI_BLNDFMT_RGB16;
        vBlit_BlendRLEI(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlendBitmapRLE24(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st        stMem;
    blit_BlndRlei_st   stParam;
    ga_en_e eDraw;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);
    
    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eRedChPrtEn    = stGastate.eRedChPrtEn;
        stParam.eGreenChPrtEn  = stGastate.eGreenChPrtEn;
        stParam.eBlueChPrtEn   = stGastate.eBlueChPrtEn;
        stParam.eAlphaChPrtEn  = stGastate.eAlphaChPrtEn;

        stParam.eBlndOrder     = stGastate.eBlndOrder;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRastOpEn      = stGastate.eRastOpEn;
        stParam.eRastOpMode    = stGastate.eRastOpMode;
        stParam.eRastOpValue   = stGastate.eRastOpValue;

        stParam.eRleiFmt = RLEI_BLNDFMT_RGB24;
        vBlit_BlendRLEI(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlendBitmapRLE24A(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                              int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st        stMem;
    blit_BlndRlei_st   stParam;
    ga_en_e eDraw;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);
    
    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eRedChPrtEn    = stGastate.eRedChPrtEn;
        stParam.eGreenChPrtEn  = stGastate.eGreenChPrtEn;
        stParam.eBlueChPrtEn   = stGastate.eBlueChPrtEn;
        stParam.eAlphaChPrtEn  = stGastate.eAlphaChPrtEn;

        stParam.eBlndOrder     = stGastate.eBlndOrder;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRastOpEn      = stGastate.eRastOpEn;
        stParam.eRastOpMode    = stGastate.eRastOpMode;
        stParam.eRastOpValue   = stGastate.eRastOpValue;

        stParam.eRleiFmt = RLEI_BLNDFMT_RGBA24;
        vBlit_BlendRLEI(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

void vGfBuffBlendBitmapRLE32(gf_image_st * pstSrcImage, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY)
{
    blit_mem_st       stMem;
    blit_BlndRlei_st  stParam;
    ga_en_e eDraw;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;
    stMem.u16DstWidth = pstDstImage->u16Width;
    stMem.u16DotCnt   = pstSrcImage->u16Width;
    stMem.u16LineCnt  = pstSrcImage->u16Height;

    /* handle clip window */
    eDraw = eHandleClipWindowBlit(pstDstImage, pstSrcImage->u16Width, pstSrcImage->u16Height, stGastate.eClipWndEn, i32PosX, i32PosY);
    
    /* Draw only if there is an overlapping clip window and destination area */
    if(eDraw == GA_EN)
    {
        stParam.eClipWndEn = eDraw;
        if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 2U*pstDstImage->u16Width * i32PosY + 2U*i32PosX;
            stParam.eDestFmt = GA_RGB16;
        }
        else
        {
            stMem.u32DstAddr = pstDstImage->u32Address + 4U*pstDstImage->u16Width * i32PosY + 4U*i32PosX;
            stParam.eDestFmt = GA_RGBA32;
        }

        stParam.eRedChPrtEn    = stGastate.eRedChPrtEn;
        stParam.eGreenChPrtEn  = stGastate.eGreenChPrtEn;
        stParam.eBlueChPrtEn   = stGastate.eBlueChPrtEn;
        stParam.eAlphaChPrtEn  = stGastate.eAlphaChPrtEn;

        stParam.eBlndOrder     = stGastate.eBlndOrder;

        stParam.eTranspColEn   = stGastate.eTranspColEn;
        stParam.u32SrcTransVal = stGastate.u32SrcTransVal;
        stParam.u16DstTransVal = stGastate.u16DstTransVal;

        stParam.eFadeMode      = stGastate.eFadeMode;
        stParam.u8FadingFctr   = stGastate.u8FadingFctr;

        stParam.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
        stParam.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

        stParam.eRastOpEn      = stGastate.eRastOpEn;
        stParam.eRastOpMode    = stGastate.eRastOpMode;
        stParam.eRastOpValue   = stGastate.eRastOpValue;

        stParam.eRleiFmt       = RLEI_BLNDFMT_RGBA32;
        vBlit_BlendRLEI(&stMem, &stParam, pstWriteList);
    }
}


/****************************************************************************/

static float32_t f32CheckAngle(float32_t f32Angle)
{
    float32_t f32AngleLocal = f32Angle;

    if(f32AngleLocal < 0.0)
    {
        /* modulo operation for float */
        f32AngleLocal = f32AngleLocal - ((int)(f32AngleLocal/360.0)) * 360.0;
        f32AngleLocal = f32AngleLocal + 360.0;
    }
	
    if(f32AngleLocal > 360.0)
    {
        /* modulo operation for float */
        f32AngleLocal = f32AngleLocal - ((int)(f32AngleLocal/360.0)) * 360.0;
    }

    return f32AngleLocal;
}


/****************************************************************************/

void vGfBuffRotateBitmapFull(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                             int32_t i32PosX, int32_t i32PosY)
{
    rot_mem_st  stMem;
    rot_cfg_st  stParam;
    float32_t   f32AngleLocal;

    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    stMem.u32SrcAddr      = pstSrcImage->u32Address;
    stMem.u16SrcHeight    = pstSrcImage->u16Height;
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.stRotCfg.eSrcColFmt = GA_RGBA32;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.stRotCfg.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.stRotCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParam.i16RotCentX            = pstSrcImage->i16CenterX;
    stParam.i16RotCentY            = pstSrcImage->i16CenterY;
    stParam.i16OffsetX             = i32PosX + (int32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParam.i16OffsetY             = i32PosY + (int32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));
    stParam.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

#ifdef GA_USE_MATH_LIB
    vRotLib_Rotate(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
    vRotLib_Rotate(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif
    
}


/****************************************************************************/

void vGfBuffRotateBitmapPart(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                             int32_t i32PosX, int32_t i32PosY)
{
    rot_mem_part_st stMem;
    rot_cfg_st      stParam;
    float32_t       f32AngleLocal;

    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    stMem.u16SrcHeight    = pstImgPart->u16Height;
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u16DotCnt       = pstImgPart->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stMem.u32SrcAddr            = pstSrcImage->u32Address + 2U*pstSrcImage->u16Width * pstImgPart->u16SrcOffsY + 2U*pstImgPart->u16SrcOffsX;
        stParam.stRotCfg.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stMem.u32SrcAddr            = pstSrcImage->u32Address + 4U*pstSrcImage->u16Width * pstImgPart->u16SrcOffsY + 4U*pstImgPart->u16SrcOffsX;
        stParam.stRotCfg.eSrcColFmt = GA_RGBA32;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.stRotCfg.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.stRotCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParam.i16RotCentX            = pstSrcImage->i16CenterX;
    stParam.i16RotCentY            = pstSrcImage->i16CenterY;
    stParam.i16OffsetX             = i32PosX + (int32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParam.i16OffsetY             = i32PosY + (int32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));
    stParam.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

#ifdef GA_USE_MATH_LIB
    vRotLib_Rotate_Part(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
    vRotLib_Rotate_Part(&stMem, &stParam, (int16_t)(10U* f32AngleLocal), pstWriteList);
#endif

}


/****************************************************************************/

void vGfBuffRotateBitmapOptimized(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                                  uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight)
{
    uint32_t        u32DivY, u32ModY, u32CountY;
    uint32_t        u32DivX, u32ModX, u32CountX;
    rot_mem_part_st stMem;
    rot_cfg_st      stParam;
    uint32_t        u32ByteCount;
    float32_t       f32AngleLocal;
    uint16_t        u16CorrectionX, u16CorrectionY;

    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    /* rotation settings */
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eSrcColFmt = GA_RGB16;
        u32ByteCount                = 2U;
    }
    else
    {
        stParam.stRotCfg.eSrcColFmt = GA_RGBA32;
        u32ByteCount                = 4U;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.stRotCfg.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window rotate */
    stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.stRotCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParam.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;
    stParam.i16OffsetX             = u32PosX + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParam.i16OffsetY             = u32PosY + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));

    u32DivX = pstSrcImage->u16Width/u32BlockWidth;
    u32ModX = pstSrcImage->u16Width%u32BlockWidth;
    u32DivY = pstSrcImage->u16Height/u32BlockHeight;
    u32ModY = pstSrcImage->u16Height%u32BlockHeight;

    for (u32CountY=0U; u32CountY<=u32DivY; u32CountY++)
    {
        for (u32CountX=0U; u32CountX<=u32DivX; u32CountX++)
        {
            if (u32CountX<u32DivX)
            {
                if (u32CountY<u32DivY)
                {
                    /* normal operation */
                    /* Add the required pixel offset so that overlapping of blocks is possible */
                    if( (u32ModY == 0) && (u32DivY - u32CountY == 1) )
                    {
                        u16CorrectionY = 0;
                    }
                    else
                    {
                        u16CorrectionY = 1;
                    }
                    
                    if( (u32ModX == 0) && (u32DivX - u32CountX == 1) )
                    {
                        u16CorrectionX = 0;
                    }
                    else
                    {
                        u16CorrectionX = 1;
                    }
                    stMem.u32SrcAddr    = pstSrcImage->u32Address + u32ByteCount*u32CountY*u32BlockHeight*pstSrcImage->u16Width + u32ByteCount*u32CountX*u32BlockWidth;
                    stMem.u16SrcHeight  = u32BlockHeight + u16CorrectionY;
                    stParam.i16RotCentX = pstSrcImage->i16CenterX - (17U-u32SubResCPos)*u32CountX*u32BlockWidth;
                    stParam.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32CountY*u32BlockHeight;
                    stMem.u16DotCnt     = u32BlockWidth + u16CorrectionX;

                    /* Reinitialize clip parameters */
                    stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
                    stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
                    stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
                    stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
                    stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;

#ifdef GA_USE_MATH_LIB
                    vRotLib_Rotate_Part(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
                    vRotLib_Rotate_Part(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif  
                    vGfListExecute();
                }
                else
                {
                    if (u32ModY != 0U)
                    {
                        /* lowest row */
                        if( (u32ModY == 0) && (u32DivY - u32CountY == 1) )
                        {
                            u16CorrectionY = 0;
                        }
                        else
                        {
                            u16CorrectionY = 1;
                        }

                        stMem.u32SrcAddr    = pstSrcImage->u32Address + u32ByteCount*u32DivY*u32BlockHeight*pstSrcImage->u16Width + u32ByteCount*u32CountX*u32BlockWidth;
                        stMem.u16SrcHeight  = pstSrcImage->u16Height  - u32DivY*u32BlockHeight;
                        stParam.i16RotCentX = pstSrcImage->i16CenterX - (17U-u32SubResCPos)*u32CountX*u32BlockWidth;
                        stParam.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32DivY*u32BlockHeight;
                        stMem.u16DotCnt     = u32BlockWidth + u16CorrectionY;

                        /* Reinitialize clip parameters */
                        stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
                        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
                        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
                        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
                        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;

#ifdef GA_USE_MATH_LIB
                        vRotLib_Rotate_Part(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
                        vRotLib_Rotate_Part(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif
                        vGfListExecute();
                    }
                }
            }
            else
            {
                if (u32ModX != 0U)
                {
                    if (u32CountY<u32DivY)
                    {
                        /* most right part */
                        stMem.u32SrcAddr    = pstSrcImage->u32Address + u32ByteCount*u32CountY*u32BlockHeight*pstSrcImage->u16Width + u32ByteCount*u32CountX*u32BlockWidth;
                        stMem.u16SrcHeight  = u32BlockHeight+1;
                        stParam.i16RotCentX = pstSrcImage->i16CenterX - (17U-u32SubResCPos)*u32DivX*u32BlockWidth;
                        stParam.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32CountY*u32BlockHeight;
                        stMem.u16DotCnt     = pstSrcImage->u16Width   - u32DivX*u32BlockWidth;

                        /* Reinitialize clip parameters */
                        stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
                        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
                        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
                        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
                        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;

#ifdef GA_USE_MATH_LIB
                        vRotLib_Rotate_Part(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
                        vRotLib_Rotate_Part(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif  
                        vGfListExecute();
                    }
                    else
                    {
                        if (u32ModY != 0U)
                        {
                            /* lower right part */
                            stMem.u32SrcAddr    = pstSrcImage->u32Address + u32ByteCount*u32DivY*u32BlockHeight*pstSrcImage->u16Width + u32ByteCount*u32CountX*u32BlockWidth;
                            stMem.u16SrcHeight  = pstSrcImage->u16Height  - u32DivY*u32BlockHeight;
                            stParam.i16RotCentX = pstSrcImage->i16CenterX - (17U-u32SubResCPos)*u32DivX*u32BlockWidth;
                            stParam.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32DivY*u32BlockHeight;
                            stMem.u16DotCnt     = pstSrcImage->u16Width   - u32DivX*u32BlockWidth;

                            /* Reinitialize clip parameters */
                            stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
                            stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
                            stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
                            stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
                            stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;

#ifdef GA_USE_MATH_LIB
                            vRotLib_Rotate_Part(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
                            vRotLib_Rotate_Part(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif
                            vGfListExecute();
                        }
                    }
                }
            }
        }
    }
}


/****************************************************************************/

void vGfBuffRotateBlendBitmapFull(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                                  int32_t i32PosX, int32_t i32PosY)
{
    rot_mem_st       stMem;
    rot_blendcfg_st  stParam;
    float32_t        f32AngleLocal;

    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    stMem.u32SrcAddr      = pstSrcImage->u32Address;
    stMem.u16SrcHeight    = pstSrcImage->u16Height;
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotBlendCfg.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.stRotBlendCfg.eSrcColFmt = GA_RGBA32;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotBlendCfg.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.stRotBlendCfg.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.stRotBlendCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.stRotBlendCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotBlendCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotBlendCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotBlendCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotBlendCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.stRotBlendCfg.eFilterEn     = stGastate.eFilterEn;

    stParam.i16RotCentX                 = pstSrcImage->i16CenterX;
    stParam.i16RotCentY                 = pstSrcImage->i16CenterY;
    stParam.i16OffsetX                  = i32PosX + (int32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParam.i16OffsetY                  = i32PosY + (int32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));

    stParam.stRotBlendCfg.eDstRedProt   = stGastate.eRedChPrtEn;
    stParam.stRotBlendCfg.eDstGreenProt = stGastate.eGreenChPrtEn;
    stParam.stRotBlendCfg.eDstBlueProt  = stGastate.eBlueChPrtEn;
    stParam.stRotBlendCfg.eDstAlphaProt = stGastate.eAlphaChPrtEn;

    stParam.stRotBlendCfg.eSrcRedFad    = stGastate.eSrcRedFad;
    stParam.stRotBlendCfg.eSrcGreenFad  = stGastate.eSrcGreenFad;
    stParam.stRotBlendCfg.eSrcBlueFad   = stGastate.eSrcBlueFad;
    stParam.stRotBlendCfg.eSrcAlphaFad  = stGastate.eSrcAlphaFad;

    stParam.stRotBlendCfg.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.stRotBlendCfg.eBldOrd       = stGastate.eBlndOrder;

    stParam.stRotBlendCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.stRotBlendCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

#ifdef GA_USE_MATH_LIB 
    vRotLib_RotateBlend(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
    vRotLib_RotateBlend(&stMem, &stParam, (int16_t)(10U * f32AngleLocal), pstWriteList);
#endif    
}


/****************************************************************************/

void vGfBuffRotateBlendBitmapPart(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage, gf_cliprect_st * pstImgPart,
                                  int32_t i32PosX, int32_t i32PosY)
{
    rot_mem_part_st  stMem;
    rot_blendcfg_st  stParam;
    float32_t        f32AngleLocal;

    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    stMem.u16SrcHeight    = pstImgPart->u16Height;
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u16DotCnt       = pstImgPart->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stMem.u32SrcAddr                 = pstSrcImage->u32Address + 2U*pstImgPart->u16SrcOffsY*pstSrcImage->u16Width + 2U*pstImgPart->u16SrcOffsX;
        stParam.stRotBlendCfg.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stMem.u32SrcAddr                 = pstSrcImage->u32Address + 4U*pstImgPart->u16SrcOffsY*pstSrcImage->u16Width + 4U*pstImgPart->u16SrcOffsX;
        stParam.stRotBlendCfg.eSrcColFmt = GA_RGBA32;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotBlendCfg.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.stRotBlendCfg.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.stRotBlendCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.stRotBlendCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotBlendCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotBlendCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotBlendCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotBlendCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.stRotBlendCfg.eFilterEn     = stGastate.eFilterEn;

    stParam.i16RotCentX                 = pstSrcImage->i16CenterX;
    stParam.i16RotCentY                 = pstSrcImage->i16CenterY;
    stParam.i16OffsetX                  = i32PosX + (int32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParam.i16OffsetY                  = i32PosY + (int32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));

    stParam.stRotBlendCfg.eDstRedProt   = stGastate.eRedChPrtEn;
    stParam.stRotBlendCfg.eDstGreenProt = stGastate.eGreenChPrtEn;
    stParam.stRotBlendCfg.eDstBlueProt  = stGastate.eBlueChPrtEn;
    stParam.stRotBlendCfg.eDstAlphaProt = stGastate.eAlphaChPrtEn;

    stParam.stRotBlendCfg.eSrcRedFad    = stGastate.eSrcRedFad;
    stParam.stRotBlendCfg.eSrcGreenFad  = stGastate.eSrcGreenFad;
    stParam.stRotBlendCfg.eSrcBlueFad   = stGastate.eSrcBlueFad;
    stParam.stRotBlendCfg.eSrcAlphaFad  = stGastate.eSrcAlphaFad;

    stParam.stRotBlendCfg.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.stRotBlendCfg.eBldOrd       = stGastate.eBlndOrder;

    stParam.stRotBlendCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.stRotBlendCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

#ifdef GA_USE_MATH_LIB 
    vRotLib_RotateBlend_Part(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
    vRotLib_RotateBlend_Part(&stMem, &stParam, (int16_t)(10U * f32AngleLocal), pstWriteList);
#endif    
   
}


/****************************************************************************/

void vGfBuffRotateNeedleFill(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                             uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockHeight)
{
    uint32_t        u32Div, u32Count;
    blit_mem_st     stMemFill;
    blit_OvrRgbP_st stParamFill;
    rot_mem_st      stMem;
    rot_cfg_st      stParam;
    uint8_t         u8SrcNoOfBytes, u8DstNoOfBytes;
    float32_t       f32AngleLocal;
    ga_en_e         eDraw;
    
    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    stParamFill.eSrcFmt      = GA_RGBA32;
    stParamFill.eFadeMode    = stGastate.eFadeMode;
    stParamFill.u8FadingFctr = stGastate.u8FadingFctr;
    stParamFill.u32Color     = 0x0U;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eSrcColFmt = GA_RGB16;
        u8SrcNoOfBytes              = 2U;
    }
    else
    {
        stParam.stRotCfg.eSrcColFmt = GA_RGBA32;
        u8SrcNoOfBytes              = 4U;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eDstColFmt = GA_RGB16;
        u8DstNoOfBytes              = 2U;
        stParamFill.eSrcFmt         = GA_RGB16;
    }
    else
    {
        stParam.stRotCfg.eDstColFmt = GA_RGBA32;
        u8DstNoOfBytes              = 4U;
        stParamFill.eSrcFmt         = GA_RGBA32;
    }

    /* handle clip window fill */
    stParamFill.eClipWndEn = stGastate.eClipWndEn;

    /* rotation settings */
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    /* handle clip window rotate */
    stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.stRotCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParam.i16RotCentX            = pstSrcImage->i16CenterX;
    stParam.i16RotCentY            = pstSrcImage->i16CenterY;
    stParam.i16OffsetX             = u32PosX + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParam.i16OffsetY             = u32PosY + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));
    stParam.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    u32Div = pstSrcImage->u16Height/u32BlockHeight;

    for (u32Count=0; u32Count<u32Div; u32Count++)
    {
        stMemFill.u16DotCnt  = u32MinMaxValues_old_old[u32NeedleNumber+u32Count][2] - u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0];
        stMemFill.u16LineCnt = u32MinMaxValues_old_old[u32NeedleNumber+u32Count][3] - u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1];
        /* handle clip window fill */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemFill.u16DotCnt, stMemFill.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0], u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamFill.eClipWndEn = eDraw;
            stMemFill.u16DstWidth = pstDstImage->u16Width;
            stMemFill.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0];
            vBlit_OverwriteFillRGB(&stMemFill, &stParamFill, pstWriteList);
            vGfListExecute();
            stParamFill.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    

    stMemFill.u16DotCnt  = u32MinMaxValues_old_old[u32NeedleNumber+3][2] - u32MinMaxValues_old_old[u32NeedleNumber+3][0];
    stMemFill.u16LineCnt = u32MinMaxValues_old_old[u32NeedleNumber+3][3] - u32MinMaxValues_old_old[u32NeedleNumber+3][1];
    /* handle clip window fill */
    eDraw = eHandleClipWindowBlit(pstDstImage, stMemFill.u16DotCnt, stMemFill.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues_old_old[u32NeedleNumber+3][0], u32MinMaxValues_old_old[u32NeedleNumber+3][1]);
    if(eDraw == GA_EN)
    {
        stParamFill.eClipWndEn = eDraw;
        stMemFill.u16DstWidth = pstDstImage->u16Width;
        stMemFill.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues_old_old[u32NeedleNumber+3][1] + u8DstNoOfBytes*u32MinMaxValues_old_old[u32NeedleNumber+3][0];
        vBlit_OverwriteFillRGB(&stMemFill, &stParamFill, pstWriteList);
        vGfListExecute();
        stParamFill.eClipWndEn = stGastate.eClipWndEn;
    }
    
    for (u32Count=0; u32Count<u32Div; u32Count++)
    {
        stMem.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*u32Count*u32BlockHeight*pstSrcImage->u16Width;
        stMem.u16SrcHeight  = u32BlockHeight;
        stParam.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32Count*u32BlockHeight;
        /* Reinitializing Clip window and Destination Address */
        stMem.u32DstAddr      = pstDstImage->u32Address;
        stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
        if(stParam.stRotCfg.eClipWndEn == GA_EN)
        {
            stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
            stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
            stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
            stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
        }
#ifdef GA_USE_MATH_LIB
        vRotLib_Rotate(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
        vRotLib_Rotate(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif  
        vGfListExecute();
  
        u32MinMaxValues[u32NeedleNumber+u32Count][0] = u32GfGetMinXCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][1] = u32GfGetMinYCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][2] = u32GfGetMaxXCoordinate()+1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][3] = u32GfGetMaxYCoordinate()+1U;
    }

    stMem.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*u32Div*u32BlockHeight*pstSrcImage->u16Width;
    stMem.u16SrcHeight  = pstSrcImage->u16Height - u32Div*u32BlockHeight;
    stParam.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32Div*u32BlockHeight;
    /* Reinitializing Clip window and Destination Address */
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if(stParam.stRotCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }
    if(stMem.u16SrcHeight > 0)
    {
#ifdef GA_USE_MATH_LIB
        vRotLib_Rotate(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
        vRotLib_Rotate(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif
        vGfListExecute();
    }

    u32MinMaxValues[u32NeedleNumber+3][0] = u32GfGetMinXCoordinate()-1U;
    u32MinMaxValues[u32NeedleNumber+3][1] = u32GfGetMinYCoordinate()-1U;
    u32MinMaxValues[u32NeedleNumber+3][2] = u32GfGetMaxXCoordinate()+1U;
    u32MinMaxValues[u32NeedleNumber+3][3] = u32GfGetMaxYCoordinate()+1U;

    u32MinMaxValues_old_old[u32NeedleNumber+0][0] = u32MinMaxValues_old[u32NeedleNumber+0][0];
    u32MinMaxValues_old_old[u32NeedleNumber+0][1] = u32MinMaxValues_old[u32NeedleNumber+0][1];
    u32MinMaxValues_old_old[u32NeedleNumber+0][2] = u32MinMaxValues_old[u32NeedleNumber+0][2];
    u32MinMaxValues_old_old[u32NeedleNumber+0][3] = u32MinMaxValues_old[u32NeedleNumber+0][3];
    u32MinMaxValues_old_old[u32NeedleNumber+1][0] = u32MinMaxValues_old[u32NeedleNumber+1][0];
    u32MinMaxValues_old_old[u32NeedleNumber+1][1] = u32MinMaxValues_old[u32NeedleNumber+1][1];
    u32MinMaxValues_old_old[u32NeedleNumber+1][2] = u32MinMaxValues_old[u32NeedleNumber+1][2];
    u32MinMaxValues_old_old[u32NeedleNumber+1][3] = u32MinMaxValues_old[u32NeedleNumber+1][3];
    u32MinMaxValues_old_old[u32NeedleNumber+2][0] = u32MinMaxValues_old[u32NeedleNumber+2][0];
    u32MinMaxValues_old_old[u32NeedleNumber+2][1] = u32MinMaxValues_old[u32NeedleNumber+2][1];
    u32MinMaxValues_old_old[u32NeedleNumber+2][2] = u32MinMaxValues_old[u32NeedleNumber+2][2];
    u32MinMaxValues_old_old[u32NeedleNumber+2][3] = u32MinMaxValues_old[u32NeedleNumber+2][3];
    u32MinMaxValues_old_old[u32NeedleNumber+3][0] = u32MinMaxValues_old[u32NeedleNumber+3][0];
    u32MinMaxValues_old_old[u32NeedleNumber+3][1] = u32MinMaxValues_old[u32NeedleNumber+3][1];
    u32MinMaxValues_old_old[u32NeedleNumber+3][2] = u32MinMaxValues_old[u32NeedleNumber+3][2];
    u32MinMaxValues_old_old[u32NeedleNumber+3][3] = u32MinMaxValues_old[u32NeedleNumber+3][3];
    u32MinMaxValues_old_old[u32NeedleNumber+4][0] = u32MinMaxValues_old[u32NeedleNumber+4][0];
    u32MinMaxValues_old_old[u32NeedleNumber+4][1] = u32MinMaxValues_old[u32NeedleNumber+4][1];
    u32MinMaxValues_old_old[u32NeedleNumber+4][2] = u32MinMaxValues_old[u32NeedleNumber+4][2];
    u32MinMaxValues_old_old[u32NeedleNumber+4][3] = u32MinMaxValues_old[u32NeedleNumber+4][3];

    u32MinMaxValues_old[u32NeedleNumber+0][0] = u32MinMaxValues[u32NeedleNumber+0][0];
    u32MinMaxValues_old[u32NeedleNumber+0][1] = u32MinMaxValues[u32NeedleNumber+0][1];
    u32MinMaxValues_old[u32NeedleNumber+0][2] = u32MinMaxValues[u32NeedleNumber+0][2];
    u32MinMaxValues_old[u32NeedleNumber+0][3] = u32MinMaxValues[u32NeedleNumber+0][3];
    u32MinMaxValues_old[u32NeedleNumber+1][0] = u32MinMaxValues[u32NeedleNumber+1][0];
    u32MinMaxValues_old[u32NeedleNumber+1][1] = u32MinMaxValues[u32NeedleNumber+1][1];
    u32MinMaxValues_old[u32NeedleNumber+1][2] = u32MinMaxValues[u32NeedleNumber+1][2];
    u32MinMaxValues_old[u32NeedleNumber+1][3] = u32MinMaxValues[u32NeedleNumber+1][3];
    u32MinMaxValues_old[u32NeedleNumber+2][0] = u32MinMaxValues[u32NeedleNumber+2][0];
    u32MinMaxValues_old[u32NeedleNumber+2][1] = u32MinMaxValues[u32NeedleNumber+2][1];
    u32MinMaxValues_old[u32NeedleNumber+2][2] = u32MinMaxValues[u32NeedleNumber+2][2];
    u32MinMaxValues_old[u32NeedleNumber+2][3] = u32MinMaxValues[u32NeedleNumber+2][3];
    u32MinMaxValues_old[u32NeedleNumber+3][0] = u32MinMaxValues[u32NeedleNumber+3][0];
    u32MinMaxValues_old[u32NeedleNumber+3][1] = u32MinMaxValues[u32NeedleNumber+3][1];
    u32MinMaxValues_old[u32NeedleNumber+3][2] = u32MinMaxValues[u32NeedleNumber+3][2];
    u32MinMaxValues_old[u32NeedleNumber+3][3] = u32MinMaxValues[u32NeedleNumber+3][3];
    u32MinMaxValues_old[u32NeedleNumber+4][0] = u32MinMaxValues[u32NeedleNumber+4][0];
    u32MinMaxValues_old[u32NeedleNumber+4][1] = u32MinMaxValues[u32NeedleNumber+4][1];
    u32MinMaxValues_old[u32NeedleNumber+4][2] = u32MinMaxValues[u32NeedleNumber+4][2];
    u32MinMaxValues_old[u32NeedleNumber+4][3] = u32MinMaxValues[u32NeedleNumber+4][3];
}


/****************************************************************************/

void vGfBuffRotateNeedle(gf_image_st * pstSrcImageBg, gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                         uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockHeight)
{
    uint32_t        u32Div, u32Count;
    blit_mem_st     stMemBlit;
    blit_OvrRgb_st  stParamBlit;
    rot_mem_st      stMem;
    rot_cfg_st      stParam;
    blit_mem_st     stMemBlend;
    blit_BlndRgb_st stParamBlend;
    uint8_t         u8SrcNoOfBytes, u8SrcNoOfBytesBg, u8DstNoOfBytes;
    float32_t       f32AngleLocal;
    ga_en_e         eDraw;
    
    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    /* restore blit */
    stMemBlit.u16SrcWidth = pstSrcImageBg->u16Width;
    stMemBlit.u16DstWidth = pstDstImage->u16Width;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eSrcColFmt = GA_RGB16;
        u8SrcNoOfBytes              = 2U;
    }
    else
    {
        stParam.stRotCfg.eSrcColFmt = GA_RGBA32;
        u8SrcNoOfBytes              = 4U;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.stRotCfg.eDstColFmt = GA_RGB16;
        stParamBlit.eDestFmt        = GA_RGB16;
        stParamBlend.eDestFmt       = GA_RGB16;
        u8DstNoOfBytes              = 2U;
        
        /* Source format should be same as the destination format for blitting */
        stParamBlit.eSrcFmt         = GA_RGB16; 
        stParamBlend.eSrcFmt        = GA_RGB16;
    }
    else
    {
        stParam.stRotCfg.eDstColFmt = GA_RGBA32;
        stParamBlit.eDestFmt        = GA_RGBA32;
        stParamBlend.eDestFmt       = GA_RGBA32;
        u8DstNoOfBytes              = 4U;
        
        /* Source format should be same as the destination format for blitting */   
        stParamBlit.eSrcFmt         = GA_RGBA32;
        stParamBlend.eSrcFmt        = GA_RGBA32;
    }

    if(pstSrcImageBg->eFormat == (uint8_t)FMT_RGB16)
    {
        u8SrcNoOfBytesBg     = 2U;
    }
    else
    {
        u8SrcNoOfBytesBg     = 4U;
    }

    stParamBlit.eFadeMode      = stGastate.eFadeMode;
    stParamBlit.u8FadingFctr   = stGastate.u8FadingFctr;
    stParamBlit.eTranspColEn   = stGastate.eTranspColEn;
    stParamBlit.u32SrcTransVal = stGastate.u32SrcTransVal;
    stParamBlit.u16DstTransVal = stGastate.u16DstTransVal;
    stParamBlit.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
    stParamBlit.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

    /* handle clip window blit */
    stParamBlit.eClipWndEn = stGastate.eClipWndEn;

    /* rotation settings */
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    /* handle clip window rotate */
    stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.stRotCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParam.i16RotCentX            = pstSrcImage->i16CenterX;
    stParam.i16RotCentY            = pstSrcImage->i16CenterY;
    stParam.i16OffsetX             = u32PosX + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParam.i16OffsetY             = u32PosY + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));
    stParam.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    /* restore blend rotation */
    stMemBlend.u16SrcWidth = pstSrcImageBg->u16Width;
    stMemBlend.u16DstWidth = pstDstImage->u16Width;

    stParamBlend.eClipWndEn     = stGastate.eClipWndEn;
    stParamBlend.eFadeMode      = stGastate.eFadeMode;
    stParamBlend.u8FadingFctr   = stGastate.u8FadingFctr;
    stParamBlend.eTranspColEn   = stGastate.eTranspColEn;
    stParamBlend.u32SrcTransVal = stGastate.u32SrcTransVal;
    stParamBlend.u16DstTransVal = stGastate.u16DstTransVal;
    stParamBlend.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
    stParamBlend.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

    stParamBlend.eRedChPrtEn    = stGastate.eRedChPrtEn;
    stParamBlend.eGreenChPrtEn  = stGastate.eGreenChPrtEn;
    stParamBlend.eBlueChPrtEn   = stGastate.eBlueChPrtEn;
    stParamBlend.eAlphaChPrtEn  = stGastate.eAlphaChPrtEn;
    stParamBlend.eRastOpEn      = GA_DIS;
    stParamBlend.eBlndOrder     = GA_BEHIND_DEST;

    u32Div = pstSrcImage->u16Height/u32BlockHeight;

    for (u32Count=0U; u32Count<u32Div; u32Count++)
    {
        stMemBlit.u16DotCnt  = u32MinMaxValues_old_old[u32NeedleNumber+u32Count][2] - u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0];
        stMemBlit.u16LineCnt = u32MinMaxValues_old_old[u32NeedleNumber+u32Count][3] - u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1];
        /* handle clip window blit */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlit.u16DotCnt, stMemBlit.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0], u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamBlit.eClipWndEn = eDraw;
            stMemBlit.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1]-pstSrcImageBg->i16CenterY)
                                   + u8SrcNoOfBytesBg*(u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0]-pstSrcImageBg->i16CenterX);
            stMemBlit.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0];
            vBlit_OverwriteRGB(&stMemBlit, &stParamBlit, pstWriteList);
            vGfListExecute();
            stParamBlit.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    stMemBlit.u16DotCnt  = u32MinMaxValues_old_old[u32NeedleNumber+3][2] - u32MinMaxValues_old_old[u32NeedleNumber+3][0];
    stMemBlit.u16LineCnt = u32MinMaxValues_old_old[u32NeedleNumber+3][3] - u32MinMaxValues_old_old[u32NeedleNumber+3][1];
    /* handle clip window blit */
    eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlit.u16DotCnt, stMemBlit.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues_old_old[u32NeedleNumber+3][0], u32MinMaxValues_old_old[u32NeedleNumber+3][1]);
    if(eDraw == GA_EN)
    {
        stParamBlit.eClipWndEn = eDraw;
        stMemBlit.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValues_old_old[u32NeedleNumber+3][1]-pstSrcImageBg->i16CenterY)
                               + u8SrcNoOfBytesBg*(u32MinMaxValues_old_old[u32NeedleNumber+3][0]-pstSrcImageBg->i16CenterX);
        stMemBlit.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues_old_old[u32NeedleNumber+3][1] + u8DstNoOfBytes*u32MinMaxValues_old_old[u32NeedleNumber+3][0];
        vBlit_OverwriteRGB(&stMemBlit, &stParamBlit, pstWriteList);
        vGfListExecute();
        stParamBlit.eClipWndEn = stGastate.eClipWndEn;
    }
    
    for (u32Count=0U; u32Count<u32Div; u32Count++)
    {
        stMem.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*u32Count*u32BlockHeight*pstSrcImage->u16Width;
        stMem.u16SrcHeight  = u32BlockHeight;
        stParam.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32Count*u32BlockHeight;
        /* Reinitializing Clip window and Destination Address */
        stMem.u32DstAddr    = pstDstImage->u32Address;
        stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
        if (stParam.stRotCfg.eClipWndEn == GA_EN)
        {
            stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
            stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
            stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
            stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
        }
#ifdef GA_USE_MATH_LIB
        vRotLib_Rotate(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
        vRotLib_Rotate(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif  
        vGfListExecute();

        u32MinMaxValues[u32NeedleNumber+u32Count][0] = u32GfGetMinXCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][1] = u32GfGetMinYCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][2] = u32GfGetMaxXCoordinate()+1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][3] = u32GfGetMaxYCoordinate()+1U;

        
        stMemBlend.u16DotCnt  = u32MinMaxValues[u32NeedleNumber+u32Count][2] - u32MinMaxValues[u32NeedleNumber+u32Count][0];
        stMemBlend.u16LineCnt = u32MinMaxValues[u32NeedleNumber+u32Count][3] - u32MinMaxValues[u32NeedleNumber+u32Count][1];
        /* handle clip window blend */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlend.u16DotCnt, stMemBlend.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues[u32NeedleNumber+u32Count][0], u32MinMaxValues[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamBlend.eClipWndEn = eDraw;
            stMemBlend.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValues[u32NeedleNumber+u32Count][1]-pstSrcImageBg->i16CenterY)
                                    + u8SrcNoOfBytesBg*(u32MinMaxValues[u32NeedleNumber+u32Count][0]-pstSrcImageBg->i16CenterX);
            stMemBlend.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValues[u32NeedleNumber+u32Count][0];
            i32Blit_BlendRGB(&stMemBlend, &stParamBlend, pstWriteList);
            vGfListExecute();
            stParamBlend.eClipWndEn = stGastate.eClipWndEn;
            
        }
    }

    stMem.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*u32Div*u32BlockHeight*pstSrcImage->u16Width;
    stMem.u16SrcHeight  = pstSrcImage->u16Height - u32Div*u32BlockHeight;
    stParam.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32Div*u32BlockHeight;
    /* Reinitializing Clip window and Destination Address */
    stMem.u32DstAddr    = pstDstImage->u32Address;
    stParam.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.stRotCfg.eClipWndEn == GA_EN)
    {
        stParam.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }
    if(stMem.u16SrcHeight > 0)
    {
#ifdef GA_USE_MATH_LIB
        vRotLib_Rotate(&stMem, &stParam, (float64_t)f32AngleLocal, pstWriteList);
#else
        vRotLib_Rotate(&stMem, &stParam, (int16_t)(f32AngleLocal*10U), pstWriteList);
#endif
        vGfListExecute();
    }

    u32MinMaxValues[u32NeedleNumber+3][0] = u32GfGetMinXCoordinate()-1U;
    u32MinMaxValues[u32NeedleNumber+3][1] = u32GfGetMinYCoordinate()-1U;
    u32MinMaxValues[u32NeedleNumber+3][2] = u32GfGetMaxXCoordinate()+1U;
    u32MinMaxValues[u32NeedleNumber+3][3] = u32GfGetMaxYCoordinate()+1U;

    
    stMemBlend.u16DotCnt  = u32MinMaxValues[u32NeedleNumber+3][2] - u32MinMaxValues[u32NeedleNumber+3][0];
    stMemBlend.u16LineCnt = u32MinMaxValues[u32NeedleNumber+3][3] - u32MinMaxValues[u32NeedleNumber+3][1];
    /* handle clip window blend */
    eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlend.u16DotCnt, stMemBlend.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues[u32NeedleNumber+3][0], u32MinMaxValues[u32NeedleNumber+3][1]);
    if(eDraw == GA_EN)
    {
        stParamBlend.eClipWndEn = GA_EN;
        stMemBlend.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValues[u32NeedleNumber+3][1]-pstSrcImageBg->i16CenterY)
                                + u8SrcNoOfBytesBg*(u32MinMaxValues[u32NeedleNumber+3][0]-pstSrcImageBg->i16CenterX);
        stMemBlend.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues[u32NeedleNumber+3][1] + u8DstNoOfBytes*u32MinMaxValues[u32NeedleNumber+3][0];
        i32Blit_BlendRGB(&stMemBlend, &stParamBlend, pstWriteList);
        vGfListExecute();
        stParamBlend.eClipWndEn = stGastate.eClipWndEn;
    }

    u32MinMaxValues_old_old[u32NeedleNumber+0][0] = u32MinMaxValues_old[u32NeedleNumber+0][0];
    u32MinMaxValues_old_old[u32NeedleNumber+0][1] = u32MinMaxValues_old[u32NeedleNumber+0][1];
    u32MinMaxValues_old_old[u32NeedleNumber+0][2] = u32MinMaxValues_old[u32NeedleNumber+0][2];
    u32MinMaxValues_old_old[u32NeedleNumber+0][3] = u32MinMaxValues_old[u32NeedleNumber+0][3];
    u32MinMaxValues_old_old[u32NeedleNumber+1][0] = u32MinMaxValues_old[u32NeedleNumber+1][0];
    u32MinMaxValues_old_old[u32NeedleNumber+1][1] = u32MinMaxValues_old[u32NeedleNumber+1][1];
    u32MinMaxValues_old_old[u32NeedleNumber+1][2] = u32MinMaxValues_old[u32NeedleNumber+1][2];
    u32MinMaxValues_old_old[u32NeedleNumber+1][3] = u32MinMaxValues_old[u32NeedleNumber+1][3];
    u32MinMaxValues_old_old[u32NeedleNumber+2][0] = u32MinMaxValues_old[u32NeedleNumber+2][0];
    u32MinMaxValues_old_old[u32NeedleNumber+2][1] = u32MinMaxValues_old[u32NeedleNumber+2][1];
    u32MinMaxValues_old_old[u32NeedleNumber+2][2] = u32MinMaxValues_old[u32NeedleNumber+2][2];
    u32MinMaxValues_old_old[u32NeedleNumber+2][3] = u32MinMaxValues_old[u32NeedleNumber+2][3];
    u32MinMaxValues_old_old[u32NeedleNumber+3][0] = u32MinMaxValues_old[u32NeedleNumber+3][0];
    u32MinMaxValues_old_old[u32NeedleNumber+3][1] = u32MinMaxValues_old[u32NeedleNumber+3][1];
    u32MinMaxValues_old_old[u32NeedleNumber+3][2] = u32MinMaxValues_old[u32NeedleNumber+3][2];
    u32MinMaxValues_old_old[u32NeedleNumber+3][3] = u32MinMaxValues_old[u32NeedleNumber+3][3];
    u32MinMaxValues_old_old[u32NeedleNumber+4][0] = u32MinMaxValues_old[u32NeedleNumber+4][0];
    u32MinMaxValues_old_old[u32NeedleNumber+4][1] = u32MinMaxValues_old[u32NeedleNumber+4][1];
    u32MinMaxValues_old_old[u32NeedleNumber+4][2] = u32MinMaxValues_old[u32NeedleNumber+4][2];
    u32MinMaxValues_old_old[u32NeedleNumber+4][3] = u32MinMaxValues_old[u32NeedleNumber+4][3];

    u32MinMaxValues_old[u32NeedleNumber+0][0] = u32MinMaxValues[u32NeedleNumber+0][0];
    u32MinMaxValues_old[u32NeedleNumber+0][1] = u32MinMaxValues[u32NeedleNumber+0][1];
    u32MinMaxValues_old[u32NeedleNumber+0][2] = u32MinMaxValues[u32NeedleNumber+0][2];
    u32MinMaxValues_old[u32NeedleNumber+0][3] = u32MinMaxValues[u32NeedleNumber+0][3];
    u32MinMaxValues_old[u32NeedleNumber+1][0] = u32MinMaxValues[u32NeedleNumber+1][0];
    u32MinMaxValues_old[u32NeedleNumber+1][1] = u32MinMaxValues[u32NeedleNumber+1][1];
    u32MinMaxValues_old[u32NeedleNumber+1][2] = u32MinMaxValues[u32NeedleNumber+1][2];
    u32MinMaxValues_old[u32NeedleNumber+1][3] = u32MinMaxValues[u32NeedleNumber+1][3];
    u32MinMaxValues_old[u32NeedleNumber+2][0] = u32MinMaxValues[u32NeedleNumber+2][0];
    u32MinMaxValues_old[u32NeedleNumber+2][1] = u32MinMaxValues[u32NeedleNumber+2][1];
    u32MinMaxValues_old[u32NeedleNumber+2][2] = u32MinMaxValues[u32NeedleNumber+2][2];
    u32MinMaxValues_old[u32NeedleNumber+2][3] = u32MinMaxValues[u32NeedleNumber+2][3];
    u32MinMaxValues_old[u32NeedleNumber+3][0] = u32MinMaxValues[u32NeedleNumber+3][0];
    u32MinMaxValues_old[u32NeedleNumber+3][1] = u32MinMaxValues[u32NeedleNumber+3][1];
    u32MinMaxValues_old[u32NeedleNumber+3][2] = u32MinMaxValues[u32NeedleNumber+3][2];
    u32MinMaxValues_old[u32NeedleNumber+3][3] = u32MinMaxValues[u32NeedleNumber+3][3];
    u32MinMaxValues_old[u32NeedleNumber+4][0] = u32MinMaxValues[u32NeedleNumber+4][0];
    u32MinMaxValues_old[u32NeedleNumber+4][1] = u32MinMaxValues[u32NeedleNumber+4][1];
    u32MinMaxValues_old[u32NeedleNumber+4][2] = u32MinMaxValues[u32NeedleNumber+4][2];
    u32MinMaxValues_old[u32NeedleNumber+4][3] = u32MinMaxValues[u32NeedleNumber+4][3];
}


/****************************************************************************/

void vGfBuffRotateNeedleTipandBaseFill(gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                                       uint32_t u32PosX, uint32_t u32PosY, gf_def_st * pstDef)
{
    uint32_t        u32Div, u32Count;
    blit_mem_st     stMemFill;
    blit_OvrRgbP_st stParamFill;
    rot_mem_part_st stMemTip;
    rot_cfg_st      stParamTip;
    rot_mem_part_st stMemBase;
    rot_cfg_st      stParamBase;
    uint8_t         u8SrcNoOfBytes, u8DstNoOfBytes;
    float32_t       f32AngleLocal;
    ga_en_e         eDraw;
    
    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    /* fill settings */
    stMemFill.u16DstWidth = pstDstImage->u16Width;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParamTip.stRotCfg.eSrcColFmt  = GA_RGB16;
        stParamBase.stRotCfg.eSrcColFmt = GA_RGB16;
        u8SrcNoOfBytes                  = 2U;
    }
    else
    {
        stParamTip.stRotCfg.eSrcColFmt  = GA_RGBA32;
        stParamBase.stRotCfg.eSrcColFmt = GA_RGBA32;
        u8SrcNoOfBytes                  = 4U;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParamTip.stRotCfg.eDstColFmt  = GA_RGB16;
        stParamBase.stRotCfg.eDstColFmt = GA_RGB16;
        u8DstNoOfBytes                  = 2U;
        
        stParamFill.eSrcFmt             = GA_RGB16;
    }
    else
    {
        stParamTip.stRotCfg.eDstColFmt  = GA_RGBA32;
        stParamBase.stRotCfg.eDstColFmt = GA_RGBA32;
        u8DstNoOfBytes                  = 4U;
        
        stParamFill.eSrcFmt             = GA_RGBA32;
    }

    stParamFill.eFadeMode    = stGastate.eFadeMode;
    stParamFill.u8FadingFctr = stGastate.u8FadingFctr;
    stParamFill.u32Color     = 0x0U;

    /* handle clip window fill */
    stParamFill.eClipWndEn = stGastate.eClipWndEn;

    /* rotation settings tip */
    stMemTip.u16SrcWidth     = pstSrcImage->u16Width;
    stMemTip.u32DstAddr      = pstDstImage->u32Address;
    stMemTip.u16DstImgWidth  = pstDstImage->u16Width;
    stMemTip.u16DstImgHeight = pstDstImage->u16Height;
    stMemTip.u16DotCnt       = pstDef->u16TipWidth;

    /* handle clip window rotate */
    stParamTip.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParamTip.stRotCfg.eClipWndEn == GA_EN)
    {
        stParamTip.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParamTip.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParamTip.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParamTip.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParamTip.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParamTip.i16RotCentX            = pstSrcImage->i16CenterX - (17U-u32SubResCPos)*((pstSrcImage->u16Width >> 1U) - (pstDef->u16TipWidth >> 1U));
    stParamTip.i16OffsetX             = u32PosX + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParamTip.i16OffsetY             = u32PosY + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));
    stParamTip.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParamTip.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    /* rotation settings base */
    stMemBase.u16SrcWidth     = pstSrcImage->u16Width;
    stMemBase.u32DstAddr      = pstDstImage->u32Address;
    stMemBase.u16DstImgWidth  = pstDstImage->u16Width;

    stMemBase.u16DstImgHeight = pstDstImage->u16Height;
    stMemBase.u16DotCnt       = pstSrcImage->u16Width >> 1U;

    /* handle clip window rotate */
    stParamBase.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParamBase.stRotCfg.eClipWndEn == GA_EN)
    {
        stParamBase.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParamBase.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParamBase.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParamBase.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParamBase.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParamBase.i16RotCentY            = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*pstDef->u16TipHeight;
    stParamBase.i16OffsetX             = u32PosX + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParamBase.i16OffsetY             = u32PosY + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));
    stParamBase.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParamBase.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;
                  
    u32Div = pstDef->u16TipHeight/pstDef->u16BlockHeight;

    /* restore old background of tip */
    for (u32Count=0; u32Count<u32Div; u32Count++)
    {
        stMemFill.u16DotCnt  = u32MinMaxValues_old_old[u32NeedleNumber+u32Count][2] - u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0];
        stMemFill.u16LineCnt = u32MinMaxValues_old_old[u32NeedleNumber+u32Count][3] - u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1];
        /* handle clip window fill */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemFill.u16DotCnt, stMemFill.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0], u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamFill.eClipWndEn = eDraw;
            stMemFill.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0];
            vBlit_OverwriteFillRGB(&stMemFill, &stParamFill, pstWriteList);
            vGfListExecute();
            stParamFill.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    if ((u32Div*pstDef->u16BlockHeight) != pstDef->u16TipHeight)
    {
        
        stMemFill.u16DotCnt  = u32MinMaxValues_old_old[u32NeedleNumber+3][2] - u32MinMaxValues_old_old[u32NeedleNumber+3][0];
        stMemFill.u16LineCnt = u32MinMaxValues_old_old[u32NeedleNumber+3][3] - u32MinMaxValues_old_old[u32NeedleNumber+3][1];
        /* handle clip window fill */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemFill.u16DotCnt, stMemFill.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues_old_old[u32NeedleNumber+3][0], u32MinMaxValues_old_old[u32NeedleNumber+3][1]);
        if(eDraw == GA_EN)
        {
            stParamFill.eClipWndEn = eDraw;
            stMemFill.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues_old_old[u32NeedleNumber+3][1] + u8DstNoOfBytes*u32MinMaxValues_old_old[u32NeedleNumber+3][0];
            vBlit_OverwriteFillRGB(&stMemFill, &stParamFill, pstWriteList);
            vGfListExecute();
            stParamFill.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    /* restore old background of base */
    for (u32Count=0; u32Count<2; u32Count++)
    {
        stMemFill.u16DotCnt  = u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][2] - u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][0];
        stMemFill.u16LineCnt = u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][3] - u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][1];
        /* handle clip window fill */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemFill.u16DotCnt, stMemFill.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][0], u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamFill.eClipWndEn = eDraw;
            stMemFill.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][0];
            vBlit_OverwriteFillRGB(&stMemFill, &stParamFill, pstWriteList);
            vGfListExecute();
            stParamFill.eClipWndEn = stGastate.eClipWndEn;;
        }
    }

    /* rotate needletip */
    for (u32Count=0U; u32Count<u32Div; u32Count++)
    {
        /* rotate needle tip */
        stMemTip.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*((pstSrcImage->u16Width >> 1U) -(pstDef->u16TipWidth >> 1U)) + u8SrcNoOfBytes*u32Count*pstDef->u16BlockHeight*pstSrcImage->u16Width;
        stMemTip.u16SrcHeight  = pstDef->u16BlockHeight;
        if((u32Count == u32Div - 1) && (u32Div*pstDef->u16BlockHeight) == pstDef->u16TipHeight)
        {
            /* Add 1 extra pixel so that the tip and base can overlap */
            stMemTip.u16SrcHeight  = pstDef->u16BlockHeight + 1U;
        }
        stParamTip.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32Count*pstDef->u16BlockHeight;
        /* Reinitializing Clip window and Destination Address */
        stMemTip.u32DstAddr      = pstDstImage->u32Address;
        stParamTip.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
        if(stParamTip.stRotCfg.eClipWndEn == GA_EN)
        {
            stParamTip.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
            stParamTip.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
            stParamTip.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
            stParamTip.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
        }
        
#ifdef GA_USE_MATH_LIB
        vRotLib_Rotate_Part(&stMemTip, &stParamTip, (float64_t)f32AngleLocal, pstWriteList);
#else
        vRotLib_Rotate_Part(&stMemTip, &stParamTip, (int16_t)(10U * f32AngleLocal), pstWriteList);
#endif
        vGfListExecute();

        u32MinMaxValues[u32NeedleNumber+u32Count][0] = u32GfGetMinXCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][1] = u32GfGetMinYCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][2] = u32GfGetMaxXCoordinate()+1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][3] = u32GfGetMaxYCoordinate()+1U;
    }

    /* rotate rest of tip */
    if ((u32Div*pstDef->u16BlockHeight) != pstDef->u16TipHeight)
    {
        /* rotate needle tip */
        stMemTip.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*((pstSrcImage->u16Width >> 1U) -(pstDef->u16TipWidth >> 1U)) + u8SrcNoOfBytes*u32Div*pstDef->u16BlockHeight*pstSrcImage->u16Width;
        /* Add 1 extra pixel so that the tip and base can overlap */
        stMemTip.u16SrcHeight  = pstDef->u16TipHeight - u32Div*pstDef->u16BlockHeight + 1U;
        stParamTip.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32Div*pstDef->u16BlockHeight;
        /* Reinitializing Clip window and Destination Address */
        stMemTip.u32DstAddr      = pstDstImage->u32Address;
        stParamTip.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
        if(stParamTip.stRotCfg.eClipWndEn == GA_EN)
        {
            stParamTip.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
            stParamTip.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
            stParamTip.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
            stParamTip.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
        }

        if(stMemTip.u16SrcHeight > 0)
        {
#ifdef GA_USE_MATH_LIB
            vRotLib_Rotate_Part(&stMemTip, &stParamTip, (float64_t)f32AngleLocal, pstWriteList);
#else
            vRotLib_Rotate_Part(&stMemTip, &stParamTip, (int16_t)(10U * f32AngleLocal), pstWriteList);
#endif
            vGfListExecute();
        }

        u32MinMaxValues[u32NeedleNumber+3][0] = u32GfGetMinXCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+3][1] = u32GfGetMinYCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+3][2] = u32GfGetMaxXCoordinate()+1U;
        u32MinMaxValues[u32NeedleNumber+3][3] = u32GfGetMaxYCoordinate()+1U;
    }

    /* rotate needle base */
    for (u32Count=0U; u32Count<2U; u32Count++)
    {
        /* rotate needle */
        stMemBase.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*pstSrcImage->u16Width*pstDef->u16TipHeight + u8SrcNoOfBytes*u32Count*(pstSrcImage->u16Width >> 1);
        stMemBase.u16SrcHeight  = pstSrcImage->u16Height - pstDef->u16TipHeight;
        stParamBase.i16RotCentX = pstSrcImage->i16CenterX - (17U-u32SubResCPos)*u32Count*(pstSrcImage->u16Width >> 1U);
        /* Reinitializing Clip window and Destination Address */
        stMemBase.u32DstAddr      = pstDstImage->u32Address;
        stParamBase.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
        if(stParamBase.stRotCfg.eClipWndEn == GA_EN)
        {
            stParamBase.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
            stParamBase.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
            stParamBase.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
            stParamBase.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
        }

        if(stMemBase.u16SrcHeight > 0)
        {
#ifdef GA_USE_MATH_LIB
            vRotLib_Rotate_Part(&stMemBase, &stParamBase, (float64_t)f32AngleLocal, pstWriteList);
#else
            vRotLib_Rotate_Part(&stMemBase, &stParamBase, (int16_t)(10U * f32AngleLocal), pstWriteList);
#endif  
            vGfListExecute();
        }
 
        u32MinMaxValuesBase[u32NeedleNumber+u32Count][0] = u32GfGetMinXCoordinate()-1U;
        u32MinMaxValuesBase[u32NeedleNumber+u32Count][1] = u32GfGetMinYCoordinate()-1U;
        u32MinMaxValuesBase[u32NeedleNumber+u32Count][2] = u32GfGetMaxXCoordinate()+1U;
        u32MinMaxValuesBase[u32NeedleNumber+u32Count][3] = u32GfGetMaxYCoordinate()+1U;
    }
    
    u32MinMaxValues_old_old[u32NeedleNumber+0][0] = u32MinMaxValues_old[u32NeedleNumber+0][0];
    u32MinMaxValues_old_old[u32NeedleNumber+0][1] = u32MinMaxValues_old[u32NeedleNumber+0][1];
    u32MinMaxValues_old_old[u32NeedleNumber+0][2] = u32MinMaxValues_old[u32NeedleNumber+0][2];
    u32MinMaxValues_old_old[u32NeedleNumber+0][3] = u32MinMaxValues_old[u32NeedleNumber+0][3];
    u32MinMaxValues_old_old[u32NeedleNumber+1][0] = u32MinMaxValues_old[u32NeedleNumber+1][0];
    u32MinMaxValues_old_old[u32NeedleNumber+1][1] = u32MinMaxValues_old[u32NeedleNumber+1][1];
    u32MinMaxValues_old_old[u32NeedleNumber+1][2] = u32MinMaxValues_old[u32NeedleNumber+1][2];
    u32MinMaxValues_old_old[u32NeedleNumber+1][3] = u32MinMaxValues_old[u32NeedleNumber+1][3];
    u32MinMaxValues_old_old[u32NeedleNumber+2][0] = u32MinMaxValues_old[u32NeedleNumber+2][0];
    u32MinMaxValues_old_old[u32NeedleNumber+2][1] = u32MinMaxValues_old[u32NeedleNumber+2][1];
    u32MinMaxValues_old_old[u32NeedleNumber+2][2] = u32MinMaxValues_old[u32NeedleNumber+2][2];
    u32MinMaxValues_old_old[u32NeedleNumber+2][3] = u32MinMaxValues_old[u32NeedleNumber+2][3];
    u32MinMaxValues_old_old[u32NeedleNumber+3][0] = u32MinMaxValues_old[u32NeedleNumber+3][0];
    u32MinMaxValues_old_old[u32NeedleNumber+3][1] = u32MinMaxValues_old[u32NeedleNumber+3][1];
    u32MinMaxValues_old_old[u32NeedleNumber+3][2] = u32MinMaxValues_old[u32NeedleNumber+3][2];
    u32MinMaxValues_old_old[u32NeedleNumber+3][3] = u32MinMaxValues_old[u32NeedleNumber+3][3];
    u32MinMaxValues_old_old[u32NeedleNumber+4][0] = u32MinMaxValues_old[u32NeedleNumber+4][0];
    u32MinMaxValues_old_old[u32NeedleNumber+4][1] = u32MinMaxValues_old[u32NeedleNumber+4][1];
    u32MinMaxValues_old_old[u32NeedleNumber+4][2] = u32MinMaxValues_old[u32NeedleNumber+4][2];
    u32MinMaxValues_old_old[u32NeedleNumber+4][3] = u32MinMaxValues_old[u32NeedleNumber+4][3];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+0][0] = u32MinMaxValuesBase_old[u32NeedleNumber+0][0];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+0][1] = u32MinMaxValuesBase_old[u32NeedleNumber+0][1];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+0][2] = u32MinMaxValuesBase_old[u32NeedleNumber+0][2];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+0][3] = u32MinMaxValuesBase_old[u32NeedleNumber+0][3];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+1][0] = u32MinMaxValuesBase_old[u32NeedleNumber+1][0];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+1][1] = u32MinMaxValuesBase_old[u32NeedleNumber+1][1];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+1][2] = u32MinMaxValuesBase_old[u32NeedleNumber+1][2];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+1][3] = u32MinMaxValuesBase_old[u32NeedleNumber+1][3];

    u32MinMaxValues_old[u32NeedleNumber+0][0] = u32MinMaxValues[u32NeedleNumber+0][0];
    u32MinMaxValues_old[u32NeedleNumber+0][1] = u32MinMaxValues[u32NeedleNumber+0][1];
    u32MinMaxValues_old[u32NeedleNumber+0][2] = u32MinMaxValues[u32NeedleNumber+0][2];
    u32MinMaxValues_old[u32NeedleNumber+0][3] = u32MinMaxValues[u32NeedleNumber+0][3];
    u32MinMaxValues_old[u32NeedleNumber+1][0] = u32MinMaxValues[u32NeedleNumber+1][0];
    u32MinMaxValues_old[u32NeedleNumber+1][1] = u32MinMaxValues[u32NeedleNumber+1][1];
    u32MinMaxValues_old[u32NeedleNumber+1][2] = u32MinMaxValues[u32NeedleNumber+1][2];
    u32MinMaxValues_old[u32NeedleNumber+1][3] = u32MinMaxValues[u32NeedleNumber+1][3];
    u32MinMaxValues_old[u32NeedleNumber+2][0] = u32MinMaxValues[u32NeedleNumber+2][0];
    u32MinMaxValues_old[u32NeedleNumber+2][1] = u32MinMaxValues[u32NeedleNumber+2][1];
    u32MinMaxValues_old[u32NeedleNumber+2][2] = u32MinMaxValues[u32NeedleNumber+2][2];
    u32MinMaxValues_old[u32NeedleNumber+2][3] = u32MinMaxValues[u32NeedleNumber+2][3];
    u32MinMaxValues_old[u32NeedleNumber+3][0] = u32MinMaxValues[u32NeedleNumber+3][0];
    u32MinMaxValues_old[u32NeedleNumber+3][1] = u32MinMaxValues[u32NeedleNumber+3][1];
    u32MinMaxValues_old[u32NeedleNumber+3][2] = u32MinMaxValues[u32NeedleNumber+3][2];
    u32MinMaxValues_old[u32NeedleNumber+3][3] = u32MinMaxValues[u32NeedleNumber+3][3];
    u32MinMaxValues_old[u32NeedleNumber+4][0] = u32MinMaxValues[u32NeedleNumber+4][0];
    u32MinMaxValues_old[u32NeedleNumber+4][1] = u32MinMaxValues[u32NeedleNumber+4][1];
    u32MinMaxValues_old[u32NeedleNumber+4][2] = u32MinMaxValues[u32NeedleNumber+4][2];
    u32MinMaxValues_old[u32NeedleNumber+4][3] = u32MinMaxValues[u32NeedleNumber+4][3];
    u32MinMaxValuesBase_old[u32NeedleNumber+0][0] = u32MinMaxValuesBase[u32NeedleNumber+0][0];
    u32MinMaxValuesBase_old[u32NeedleNumber+0][1] = u32MinMaxValuesBase[u32NeedleNumber+0][1];
    u32MinMaxValuesBase_old[u32NeedleNumber+0][2] = u32MinMaxValuesBase[u32NeedleNumber+0][2];
    u32MinMaxValuesBase_old[u32NeedleNumber+0][3] = u32MinMaxValuesBase[u32NeedleNumber+0][3];
    u32MinMaxValuesBase_old[u32NeedleNumber+1][0] = u32MinMaxValuesBase[u32NeedleNumber+1][0];
    u32MinMaxValuesBase_old[u32NeedleNumber+1][1] = u32MinMaxValuesBase[u32NeedleNumber+1][1];
    u32MinMaxValuesBase_old[u32NeedleNumber+1][2] = u32MinMaxValuesBase[u32NeedleNumber+1][2];
    u32MinMaxValuesBase_old[u32NeedleNumber+1][3] = u32MinMaxValuesBase[u32NeedleNumber+1][3];
}


/****************************************************************************/

void vGfBuffRotateNeedleTipandBase(gf_image_st * pstSrcImageBg, gf_image_st * pstSrcImage, float32_t f32Angle, gf_image_st * pstDstImage,
                                   uint32_t u32PosX, uint32_t u32PosY, gf_def_st * pstDef)
{
    uint32_t        u32Div, u32Count;
    blit_mem_st     stMemBlit;
    blit_OvrRgb_st  stParamBlit;
    rot_mem_part_st stMemTip;
    rot_cfg_st      stParamTip;
    rot_mem_part_st stMemBase;
    rot_cfg_st      stParamBase;
    blit_mem_st     stMemBlend;
    blit_BlndRgb_st stParamBlend;
    uint8_t         u8SrcNoOfBytes, u8SrcNoOfBytesBg, u8DstNoOfBytes;
    float32_t       f32AngleLocal;
    ga_en_e         eDraw;
    
    u8PreviousOperation = 0U;

    f32AngleLocal = f32CheckAngle(f32Angle);

    /* restore blit */
    stMemBlit.u16SrcWidth = pstSrcImageBg->u16Width;
    stMemBlit.u16DstWidth = pstDstImage->u16Width;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParamTip.stRotCfg.eSrcColFmt  = GA_RGB16;
        stParamBase.stRotCfg.eSrcColFmt = GA_RGB16;
        u8SrcNoOfBytes                  = 2U;
    }
    else
    {
        stParamTip.stRotCfg.eSrcColFmt  = GA_RGBA32;
        stParamBase.stRotCfg.eSrcColFmt = GA_RGBA32;
        u8SrcNoOfBytes                  = 4U;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParamBlit.eDestFmt            = GA_RGB16;
        stParamTip.stRotCfg.eDstColFmt  = GA_RGB16;
        stParamBase.stRotCfg.eDstColFmt = GA_RGB16;
        stParamBlend.eDestFmt           = GA_RGB16;
        u8DstNoOfBytes                  = 2U;
        
        stParamBlit.eSrcFmt             = GA_RGB16;
        stParamBlend.eSrcFmt            = GA_RGB16;
    }
    else
    {
        stParamBlit.eDestFmt            = GA_RGBA32;
        stParamTip.stRotCfg.eDstColFmt  = GA_RGBA32;
        stParamBase.stRotCfg.eDstColFmt = GA_RGBA32;
        stParamBlend.eDestFmt           = GA_RGBA32;
        u8DstNoOfBytes                  = 4U;
        
        stParamBlit.eSrcFmt             = GA_RGBA32;
        stParamBlend.eSrcFmt  = GA_RGBA32;
    }

    if(pstSrcImageBg->eFormat == (uint8_t)FMT_RGB16)
    {
        u8SrcNoOfBytesBg      = 2U;
    }
    else
    {
        u8SrcNoOfBytesBg      = 4U;
    }

    stParamBlit.eFadeMode      = stGastate.eFadeMode;
    stParamBlit.u8FadingFctr   = stGastate.u8FadingFctr;
    stParamBlit.eTranspColEn   = stGastate.eTranspColEn;
    stParamBlit.u32SrcTransVal = stGastate.u32SrcTransVal;
    stParamBlit.u16DstTransVal = stGastate.u16DstTransVal;
    stParamBlit.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
    stParamBlit.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

    /* handle clip window */
    stParamBlit.eClipWndEn = stGastate.eClipWndEn;

    /* rotation settings tip */
    stMemTip.u16SrcWidth     = pstSrcImage->u16Width;
    stMemTip.u32DstAddr      = pstDstImage->u32Address;
    stMemTip.u16DstImgWidth  = pstDstImage->u16Width;
    stMemTip.u16DstImgHeight = pstDstImage->u16Height;
    stMemTip.u16DotCnt       = pstDef->u16TipWidth;

    /* handle clip window rotate */
    stParamTip.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParamTip.stRotCfg.eClipWndEn == GA_EN)
    {
        stParamTip.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParamTip.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParamTip.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParamTip.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParamTip.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParamTip.i16RotCentX            = pstSrcImage->i16CenterX - (17U-u32SubResCPos)*((pstSrcImage->u16Width >> 1U) - (pstDef->u16TipWidth >> 1U));
    stParamTip.i16OffsetX             = u32PosX + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParamTip.i16OffsetY             = u32PosY + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));
    stParamTip.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParamTip.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    /* rotation settings base */
    stMemBase.u16SrcWidth     = pstSrcImage->u16Width;
    stMemBase.u32DstAddr      = pstDstImage->u32Address;
    stMemBase.u16DstImgWidth  = pstDstImage->u16Width;
    stMemBase.u16DstImgHeight = pstDstImage->u16Height;
    stMemBase.u16DotCnt       = pstSrcImage->u16Width >> 1U;

    /* handle clip window rotate */
    stParamBase.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
    if (stParamBase.stRotCfg.eClipWndEn == GA_EN)
    {
        stParamBase.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParamBase.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParamBase.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParamBase.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParamBase.stRotCfg.eFilterEn     = stGastate.eFilterEn;
    stParamBase.i16RotCentY            = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*pstDef->u16TipHeight;
    stParamBase.i16OffsetX             = u32PosX + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterX/(float32_t)(17U-u32SubResCPos));
    stParamBase.i16OffsetY             = u32PosY + (uint32_t)((float32_t)(17U-u32SubResPPos)*(float32_t)pstSrcImage->i16CenterY/(float32_t)(17U-u32SubResCPos));
    stParamBase.stRotCfg.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParamBase.stRotCfg.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    /* restore blend rotation */
    stMemBlend.u16SrcWidth = pstSrcImageBg->u16Width;
    stMemBlend.u16DstWidth = pstDstImage->u16Width;

    stParamBlend.eClipWndEn     = stGastate.eClipWndEn;
    stParamBlend.eFadeMode      = stGastate.eFadeMode;
    stParamBlend.u8FadingFctr   = stGastate.u8FadingFctr;
    stParamBlend.eTranspColEn   = stGastate.eTranspColEn;
    stParamBlend.u32SrcTransVal = stGastate.u32SrcTransVal;
    stParamBlend.u16DstTransVal = stGastate.u16DstTransVal;
    stParamBlend.u8SrcAlphaVal  = stGastate.u8SrcAlphaVal;
    stParamBlend.u8DstAlphaVal  = stGastate.u8DstAlphaVal;

    stParamBlend.eRedChPrtEn    = stGastate.eRedChPrtEn;
    stParamBlend.eGreenChPrtEn  = stGastate.eGreenChPrtEn;
    stParamBlend.eBlueChPrtEn   = stGastate.eBlueChPrtEn;
    stParamBlend.eAlphaChPrtEn  = stGastate.eAlphaChPrtEn;
    stParamBlend.eRastOpEn      = GA_DIS;
    stParamBlend.eBlndOrder     = GA_BEHIND_DEST;
    
    u32Div = pstDef->u16TipHeight/pstDef->u16BlockHeight;

    /* restore old background of tip */
    for (u32Count=0; u32Count<u32Div; u32Count++)
    {
        stMemBlit.u16DotCnt  = u32MinMaxValues_old_old[u32NeedleNumber+u32Count][2] - u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0];
        stMemBlit.u16LineCnt = u32MinMaxValues_old_old[u32NeedleNumber+u32Count][3] - u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1];
        /* handle clip window */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlit.u16DotCnt, stMemBlit.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0], u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamBlit.eClipWndEn = eDraw;
            stMemBlit.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1]-pstSrcImageBg->i16CenterY)
                                   + u8SrcNoOfBytesBg*(u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0]-pstSrcImageBg->i16CenterX);
            stMemBlit.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues_old_old[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValues_old_old[u32NeedleNumber+u32Count][0];
            vBlit_OverwriteRGB(&stMemBlit, &stParamBlit, pstWriteList);
            vGfListExecute();
            stParamBlit.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    if ((u32Div*pstDef->u16BlockHeight) != pstDef->u16TipHeight)
    {
        
        stMemBlit.u16DotCnt  = u32MinMaxValues_old_old[u32NeedleNumber+3][2] - u32MinMaxValues_old_old[u32NeedleNumber+3][0];
        stMemBlit.u16LineCnt = u32MinMaxValues_old_old[u32NeedleNumber+3][3] - u32MinMaxValues_old_old[u32NeedleNumber+3][1];
        /* handle clip window */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlit.u16DotCnt, stMemBlit.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues_old_old[u32NeedleNumber+3][0], u32MinMaxValues_old_old[u32NeedleNumber+3][1]);
        if(eDraw == GA_EN)
        {
            stParamBlit.eClipWndEn = GA_EN;
            stMemBlit.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValues_old_old[u32NeedleNumber+3][1]-pstSrcImageBg->i16CenterY)
                                   + u8SrcNoOfBytesBg*(u32MinMaxValues_old_old[u32NeedleNumber+3][0]-pstSrcImageBg->i16CenterX);
            stMemBlit.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues_old_old[u32NeedleNumber+3][1] + u8DstNoOfBytes*u32MinMaxValues_old_old[u32NeedleNumber+3][0];
            vBlit_OverwriteRGB(&stMemBlit, &stParamBlit, pstWriteList);
            vGfListExecute();
            stParamBlit.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    /* restore old background of base */
    for (u32Count=0U; u32Count<2U; u32Count++)
    {
        stMemBlit.u16DotCnt  = u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][2] - u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][0];
        stMemBlit.u16LineCnt = u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][3] - u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][1];
        /* handle clip window */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlit.u16DotCnt, stMemBlit.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][0], u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamBlit.eClipWndEn = eDraw;
            stMemBlit.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][1]-pstSrcImageBg->i16CenterY)
                                   + u8SrcNoOfBytesBg*(u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][0]-pstSrcImageBg->i16CenterX);
            stMemBlit.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValuesBase_old_old[u32NeedleNumber+u32Count][0];
            vBlit_OverwriteRGB(&stMemBlit, &stParamBlit, pstWriteList);
            vGfListExecute();
            stParamBlit.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    /* rotate needletip and restore background */
    for (u32Count=0; u32Count<u32Div; u32Count++)
    {
        /* rotate needle tip */
        stMemTip.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*((pstSrcImage->u16Width >> 1) -(pstDef->u16TipWidth >> 1)) + u8SrcNoOfBytes*u32Count*pstDef->u16BlockHeight*pstSrcImage->u16Width;
        stMemTip.u16SrcHeight  = pstDef->u16BlockHeight;
        if((u32Count == u32Div - 1U) && (u32Div*pstDef->u16BlockHeight) == pstDef->u16TipHeight)
        {
            /* Add 1 extra pixel so that the tip and base can overlap */
            stMemTip.u16SrcHeight  = pstDef->u16BlockHeight + 1U;
        }
        stParamTip.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32Count*pstDef->u16BlockHeight;
        /* Reinitializing Clip window and Destination Address */
        stMemTip.u32DstAddr      = pstDstImage->u32Address;
        stParamTip.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
        if (stParamTip.stRotCfg.eClipWndEn == GA_EN)
        {
            stParamTip.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
            stParamTip.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
            stParamTip.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
            stParamTip.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
        }

#ifdef GA_USE_MATH_LIB
        vRotLib_Rotate_Part(&stMemTip, &stParamTip, (float64_t)f32AngleLocal, pstWriteList);
#else
        vRotLib_Rotate_Part(&stMemTip, &stParamTip, (int16_t)(10U * f32AngleLocal), pstWriteList);
#endif
        vGfListExecute();
               
        u32MinMaxValues[u32NeedleNumber+u32Count][0] = u32GfGetMinXCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][1] = u32GfGetMinYCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][2] = u32GfGetMaxXCoordinate()+1U;
        u32MinMaxValues[u32NeedleNumber+u32Count][3] = u32GfGetMaxYCoordinate()+1U;

        
        stMemBlend.u16DotCnt  = u32MinMaxValues[u32NeedleNumber+u32Count][2] - u32MinMaxValues[u32NeedleNumber+u32Count][0];
        stMemBlend.u16LineCnt = u32MinMaxValues[u32NeedleNumber+u32Count][3] - u32MinMaxValues[u32NeedleNumber+u32Count][1];
        /* handle clip window */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlend.u16DotCnt, stMemBlend.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues[u32NeedleNumber+u32Count][0], u32MinMaxValues[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamBlend.eClipWndEn = eDraw;
            /* restore background */
            stMemBlend.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValues[u32NeedleNumber+u32Count][1]-pstSrcImageBg->i16CenterY)
                                    + u8SrcNoOfBytesBg*(u32MinMaxValues[u32NeedleNumber+u32Count][0]-pstSrcImageBg->i16CenterX);
            stMemBlend.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValues[u32NeedleNumber+u32Count][0];
            i32Blit_BlendRGB(&stMemBlend, &stParamBlend, pstWriteList);
            vGfListExecute();
            stParamBlend.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    /* rotate rest of tip */
    if ((u32Div*pstDef->u16BlockHeight) != pstDef->u16TipHeight)
    {
        /* rotate needle tip */
        stMemTip.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*((pstSrcImage->u16Width >> 1U) -(pstDef->u16TipWidth >> 1U)) + u8SrcNoOfBytes*u32Div*pstDef->u16BlockHeight*pstSrcImage->u16Width;
        /* Add 1 extra pixel so that the tip and base can overlap */
        stMemTip.u16SrcHeight  = pstDef->u16TipHeight - u32Div*pstDef->u16BlockHeight + 1U;
        stParamTip.i16RotCentY = pstSrcImage->i16CenterY - (17U-u32SubResCPos)*u32Div*pstDef->u16BlockHeight;
        /* Reinitializing Clip window and Destination Address */
        stMemTip.u32DstAddr      = pstDstImage->u32Address;
        stParamTip.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
        if (stParamTip.stRotCfg.eClipWndEn == GA_EN)
        {
            stParamTip.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
            stParamTip.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
            stParamTip.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
            stParamTip.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
        }
        if(stMemTip.u16SrcHeight > 0)
        {
#ifdef GA_USE_MATH_LIB
            vRotLib_Rotate_Part(&stMemTip, &stParamTip, (float64_t)f32AngleLocal, pstWriteList);
#else
            vRotLib_Rotate_Part(&stMemTip, &stParamTip, (int16_t)(10U * f32AngleLocal), pstWriteList);
#endif  
            vGfListExecute();
        }

        u32MinMaxValues[u32NeedleNumber+3][0] = u32GfGetMinXCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+3][1] = u32GfGetMinYCoordinate()-1U;
        u32MinMaxValues[u32NeedleNumber+3][2] = u32GfGetMaxXCoordinate()+1U;
        u32MinMaxValues[u32NeedleNumber+3][3] = u32GfGetMaxYCoordinate()+1U;

        
        stMemBlend.u16DotCnt  = u32MinMaxValues[u32NeedleNumber+3][2] - u32MinMaxValues[u32NeedleNumber+3][0];
        stMemBlend.u16LineCnt = u32MinMaxValues[u32NeedleNumber+3][3] - u32MinMaxValues[u32NeedleNumber+3][1];
        /* handle clip window */
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlend.u16DotCnt, stMemBlend.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValues[u32NeedleNumber+3][0], u32MinMaxValues[u32NeedleNumber+3][1]);
        if(eDraw ==  GA_EN)
        {
            stParamBlend.eClipWndEn = eDraw;
            /* restore background */
            stMemBlend.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValues[u32NeedleNumber+3][1]-pstSrcImageBg->i16CenterY)
                                    + u8SrcNoOfBytesBg*(u32MinMaxValues[u32NeedleNumber+3][0]-pstSrcImageBg->i16CenterX);
            stMemBlend.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValues[u32NeedleNumber+3][1] + u8DstNoOfBytes*u32MinMaxValues[u32NeedleNumber+3][0];
            i32Blit_BlendRGB(&stMemBlend, &stParamBlend, pstWriteList);
            vGfListExecute();
            stParamBlend.eClipWndEn = stGastate.eClipWndEn;
        }
    }

    /* rotate needle base */
    for (u32Count=0; u32Count<2; u32Count++)
    {
        /* rotate needle */
        stMemBase.u32SrcAddr    = pstSrcImage->u32Address + u8SrcNoOfBytes*pstSrcImage->u16Width*pstDef->u16TipHeight + u8SrcNoOfBytes*u32Count*(pstSrcImage->u16Width >> 1U);
        stMemBase.u16SrcHeight  = pstSrcImage->u16Height - pstDef->u16TipHeight;
        stParamBase.i16RotCentX = pstSrcImage->i16CenterX - (17U-u32SubResCPos)*u32Count*(pstSrcImage->u16Width >> 1U);
        /* Reinitializing Clip window and Destination Address */
        stMemBase.u32DstAddr      = pstDstImage->u32Address;
        stParamBase.stRotCfg.eClipWndEn = stGastate.eClipWndEn;
	    if (stParamBase.stRotCfg.eClipWndEn == GA_EN)
        {
            stParamBase.stRotCfg.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
            stParamBase.stRotCfg.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
            stParamBase.stRotCfg.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
            stParamBase.stRotCfg.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
        }

        if(stMemBase.u16SrcHeight > 0)
        {
#ifdef GA_USE_MATH_LIB
            vRotLib_Rotate_Part(&stMemBase, &stParamBase, (float64_t)f32AngleLocal, pstWriteList);
#else
            vRotLib_Rotate_Part(&stMemBase, &stParamBase, (int16_t)(10U * f32AngleLocal), pstWriteList);
#endif  
            vGfListExecute();
        }

        u32MinMaxValuesBase[u32NeedleNumber+u32Count][0] = u32GfGetMinXCoordinate()-1U;
        u32MinMaxValuesBase[u32NeedleNumber+u32Count][1] = u32GfGetMinYCoordinate()-1U;
        u32MinMaxValuesBase[u32NeedleNumber+u32Count][2] = u32GfGetMaxXCoordinate()+1U;
        u32MinMaxValuesBase[u32NeedleNumber+u32Count][3] = u32GfGetMaxYCoordinate()+1U;

        stMemBlend.u16DotCnt  = u32MinMaxValuesBase[u32NeedleNumber+u32Count][2] - u32MinMaxValuesBase[u32NeedleNumber+u32Count][0];
        stMemBlend.u16LineCnt = u32MinMaxValuesBase[u32NeedleNumber+u32Count][3] - u32MinMaxValuesBase[u32NeedleNumber+u32Count][1];
        /* handle clip window */  
        eDraw = eHandleClipWindowBlit(pstDstImage, stMemBlend.u16DotCnt, stMemBlend.u16LineCnt, stGastate.eClipWndEn, u32MinMaxValuesBase[u32NeedleNumber+u32Count][0], u32MinMaxValuesBase[u32NeedleNumber+u32Count][1]);
        if(eDraw == GA_EN)
        {
            stParamBlend.eClipWndEn = eDraw;
            /* restore background */
            stMemBlend.u32SrcAddr = pstSrcImageBg->u32Address + u8SrcNoOfBytesBg*pstSrcImageBg->u16Width*(u32MinMaxValuesBase[u32NeedleNumber+u32Count][1]-pstSrcImageBg->i16CenterY)
                                    + u8SrcNoOfBytesBg*(u32MinMaxValuesBase[u32NeedleNumber+u32Count][0]-pstSrcImageBg->i16CenterX);
            stMemBlend.u32DstAddr = pstDstImage->u32Address + u8DstNoOfBytes*pstDstImage->u16Width*u32MinMaxValuesBase[u32NeedleNumber+u32Count][1] + u8DstNoOfBytes*u32MinMaxValuesBase[u32NeedleNumber+u32Count][0];
            i32Blit_BlendRGB(&stMemBlend, &stParamBlend, pstWriteList);
            vGfListExecute();
            stParamBlend.eClipWndEn = stGastate.eClipWndEn;
        }
    }
    
    u32MinMaxValues_old_old[u32NeedleNumber+0][0] = u32MinMaxValues_old[u32NeedleNumber+0][0];
    u32MinMaxValues_old_old[u32NeedleNumber+0][1] = u32MinMaxValues_old[u32NeedleNumber+0][1];
    u32MinMaxValues_old_old[u32NeedleNumber+0][2] = u32MinMaxValues_old[u32NeedleNumber+0][2];
    u32MinMaxValues_old_old[u32NeedleNumber+0][3] = u32MinMaxValues_old[u32NeedleNumber+0][3];
    u32MinMaxValues_old_old[u32NeedleNumber+1][0] = u32MinMaxValues_old[u32NeedleNumber+1][0];
    u32MinMaxValues_old_old[u32NeedleNumber+1][1] = u32MinMaxValues_old[u32NeedleNumber+1][1];
    u32MinMaxValues_old_old[u32NeedleNumber+1][2] = u32MinMaxValues_old[u32NeedleNumber+1][2];
    u32MinMaxValues_old_old[u32NeedleNumber+1][3] = u32MinMaxValues_old[u32NeedleNumber+1][3];
    u32MinMaxValues_old_old[u32NeedleNumber+2][0] = u32MinMaxValues_old[u32NeedleNumber+2][0];
    u32MinMaxValues_old_old[u32NeedleNumber+2][1] = u32MinMaxValues_old[u32NeedleNumber+2][1];
    u32MinMaxValues_old_old[u32NeedleNumber+2][2] = u32MinMaxValues_old[u32NeedleNumber+2][2];
    u32MinMaxValues_old_old[u32NeedleNumber+2][3] = u32MinMaxValues_old[u32NeedleNumber+2][3];
    u32MinMaxValues_old_old[u32NeedleNumber+3][0] = u32MinMaxValues_old[u32NeedleNumber+3][0];
    u32MinMaxValues_old_old[u32NeedleNumber+3][1] = u32MinMaxValues_old[u32NeedleNumber+3][1];
    u32MinMaxValues_old_old[u32NeedleNumber+3][2] = u32MinMaxValues_old[u32NeedleNumber+3][2];
    u32MinMaxValues_old_old[u32NeedleNumber+3][3] = u32MinMaxValues_old[u32NeedleNumber+3][3];
    u32MinMaxValues_old_old[u32NeedleNumber+4][0] = u32MinMaxValues_old[u32NeedleNumber+4][0];
    u32MinMaxValues_old_old[u32NeedleNumber+4][1] = u32MinMaxValues_old[u32NeedleNumber+4][1];
    u32MinMaxValues_old_old[u32NeedleNumber+4][2] = u32MinMaxValues_old[u32NeedleNumber+4][2];
    u32MinMaxValues_old_old[u32NeedleNumber+4][3] = u32MinMaxValues_old[u32NeedleNumber+4][3];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+0][0] = u32MinMaxValuesBase_old[u32NeedleNumber+0][0];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+0][1] = u32MinMaxValuesBase_old[u32NeedleNumber+0][1];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+0][2] = u32MinMaxValuesBase_old[u32NeedleNumber+0][2];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+0][3] = u32MinMaxValuesBase_old[u32NeedleNumber+0][3];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+1][0] = u32MinMaxValuesBase_old[u32NeedleNumber+1][0];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+1][1] = u32MinMaxValuesBase_old[u32NeedleNumber+1][1];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+1][2] = u32MinMaxValuesBase_old[u32NeedleNumber+1][2];
    u32MinMaxValuesBase_old_old[u32NeedleNumber+1][3] = u32MinMaxValuesBase_old[u32NeedleNumber+1][3];

    u32MinMaxValues_old[u32NeedleNumber+0][0] = u32MinMaxValues[u32NeedleNumber+0][0];
    u32MinMaxValues_old[u32NeedleNumber+0][1] = u32MinMaxValues[u32NeedleNumber+0][1];
    u32MinMaxValues_old[u32NeedleNumber+0][2] = u32MinMaxValues[u32NeedleNumber+0][2];
    u32MinMaxValues_old[u32NeedleNumber+0][3] = u32MinMaxValues[u32NeedleNumber+0][3];
    u32MinMaxValues_old[u32NeedleNumber+1][0] = u32MinMaxValues[u32NeedleNumber+1][0];
    u32MinMaxValues_old[u32NeedleNumber+1][1] = u32MinMaxValues[u32NeedleNumber+1][1];
    u32MinMaxValues_old[u32NeedleNumber+1][2] = u32MinMaxValues[u32NeedleNumber+1][2];
    u32MinMaxValues_old[u32NeedleNumber+1][3] = u32MinMaxValues[u32NeedleNumber+1][3];
    u32MinMaxValues_old[u32NeedleNumber+2][0] = u32MinMaxValues[u32NeedleNumber+2][0];
    u32MinMaxValues_old[u32NeedleNumber+2][1] = u32MinMaxValues[u32NeedleNumber+2][1];
    u32MinMaxValues_old[u32NeedleNumber+2][2] = u32MinMaxValues[u32NeedleNumber+2][2];
    u32MinMaxValues_old[u32NeedleNumber+2][3] = u32MinMaxValues[u32NeedleNumber+2][3];
    u32MinMaxValues_old[u32NeedleNumber+3][0] = u32MinMaxValues[u32NeedleNumber+3][0];
    u32MinMaxValues_old[u32NeedleNumber+3][1] = u32MinMaxValues[u32NeedleNumber+3][1];
    u32MinMaxValues_old[u32NeedleNumber+3][2] = u32MinMaxValues[u32NeedleNumber+3][2];
    u32MinMaxValues_old[u32NeedleNumber+3][3] = u32MinMaxValues[u32NeedleNumber+3][3];
    u32MinMaxValues_old[u32NeedleNumber+4][0] = u32MinMaxValues[u32NeedleNumber+4][0];
    u32MinMaxValues_old[u32NeedleNumber+4][1] = u32MinMaxValues[u32NeedleNumber+4][1];
    u32MinMaxValues_old[u32NeedleNumber+4][2] = u32MinMaxValues[u32NeedleNumber+4][2];

    u32MinMaxValues_old[u32NeedleNumber+4][3] = u32MinMaxValues[u32NeedleNumber+4][3];
    u32MinMaxValuesBase_old[u32NeedleNumber+0][0] = u32MinMaxValuesBase[u32NeedleNumber+0][0];
    u32MinMaxValuesBase_old[u32NeedleNumber+0][1] = u32MinMaxValuesBase[u32NeedleNumber+0][1];
    u32MinMaxValuesBase_old[u32NeedleNumber+0][2] = u32MinMaxValuesBase[u32NeedleNumber+0][2];
    u32MinMaxValuesBase_old[u32NeedleNumber+0][3] = u32MinMaxValuesBase[u32NeedleNumber+0][3];
    u32MinMaxValuesBase_old[u32NeedleNumber+1][0] = u32MinMaxValuesBase[u32NeedleNumber+1][0];
    u32MinMaxValuesBase_old[u32NeedleNumber+1][1] = u32MinMaxValuesBase[u32NeedleNumber+1][1];
    u32MinMaxValuesBase_old[u32NeedleNumber+1][2] = u32MinMaxValuesBase[u32NeedleNumber+1][2];
    u32MinMaxValuesBase_old[u32NeedleNumber+1][3] = u32MinMaxValuesBase[u32NeedleNumber+1][3];
}


/****************************************************************************/
        
void vGfBuffShearFull(gf_image_st * pstSrcImage, float32_t f32FactorX, float32_t f32FactorY, gf_image_st * pstDstImage,
                      int32_t i32PosX, int32_t i32PosY)
{
    rot_mem_st      stMem;
    rot_sscalCfg_st stParam;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr      = pstSrcImage->u32Address;
    stMem.u16SrcHeight    = pstSrcImage->u16Height;
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.eSrcColFmt = GA_RGBA32;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.eClipWndEn == GA_EN)
    {
        stParam.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.eFilterEn     = stGastate.eFilterEn;
    stParam.i16OffsetX    = i32PosX;
    stParam.i16OffsetY    = i32PosY;
#ifdef GA_USE_MATH_LIB
    stParam.f64FactorX    = f32FactorX;
    stParam.f64FactorY    = f32FactorY;
#else
    stParam.i32FactorX    = (int32_t)(65536.0 * f32FactorX);
    stParam.i32FactorY    = (int32_t)(65536.0 * f32FactorY);
#endif
    stParam.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    vRotLib_Shear(&stMem, &stParam, pstWriteList);
}


/****************************************************************************/

void vGfBuffShearBlendFull(gf_image_st * pstSrcImage, float32_t f32FactorX, float32_t f32FactorY, gf_image_st * pstDstImage,
                           int32_t i32PosX, int32_t i32PosY)
{
    rot_mem_st           stMem;
    rot_sscalblendCfg_st stParam;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr      = pstSrcImage->u32Address;
    stMem.u16SrcHeight    = pstSrcImage->u16Height;
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.eSrcColFmt = GA_RGBA32;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.eClipWndEn == GA_EN)
    {
        stParam.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.eFilterEn     = stGastate.eFilterEn;
    stParam.i16OffsetX    = i32PosX;
    stParam.i16OffsetY    = i32PosY;
#ifdef GA_USE_MATH_LIB
    stParam.f64FactorX    = f32FactorX;
    stParam.f64FactorY    = f32FactorY;
#else
    stParam.i32FactorX    = (int32_t)(65536.0 * f32FactorX);
    stParam.i32FactorY    = (int32_t)(65536.0 * f32FactorY);
#endif
    stParam.eBldOrd       = stGastate.eBlndOrder;
    stParam.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    stParam.eDstRedProt   = stGastate.eRedChPrtEn;
    stParam.eDstGreenProt = stGastate.eGreenChPrtEn;
    stParam.eDstBlueProt  = stGastate.eBlueChPrtEn;
    stParam.eDstAlphaProt = stGastate.eAlphaChPrtEn;
    stParam.eSrcRedFad    = stGastate.eSrcRedFad;
    stParam.eSrcGreenFad  = stGastate.eSrcGreenFad;
    stParam.eSrcBlueFad   = stGastate.eSrcBlueFad;
    stParam.eSrcAlphaFad  = stGastate.eSrcAlphaFad;
    
    vRotLib_ShearBlend(&stMem, &stParam, pstWriteList);
}


/****************************************************************************/

void vGfBuffScaleFull(gf_image_st * pstSrcImage, float32_t f32FactorX, float32_t f32FactorY,
                      rot_scaleAlign_e eAlignment, gf_image_st * pstDstImage,
                      int32_t i32PosX, int32_t i32PosY)
{
    rot_mem_st      stMem;
    rot_sscalCfg_st stParam;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr      = pstSrcImage->u32Address;
    stMem.u16SrcHeight    = pstSrcImage->u16Height;
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.eSrcColFmt = GA_RGBA32;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.eClipWndEn == GA_EN)
    {
        stParam.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.eFilterEn     = stGastate.eFilterEn;
    stParam.i16OffsetX    = i32PosX;
    stParam.i16OffsetY    = i32PosY;
#ifdef GA_USE_MATH_LIB
    stParam.f64FactorX    = f32FactorX;
    stParam.f64FactorY    = f32FactorY;
#else
    stParam.i32FactorX    = (int32_t)(65536.0 * f32FactorX);
    stParam.i32FactorY    = (int32_t)(65536.0 * f32FactorY);
#endif
    stParam.eAlignment    = eAlignment;
    stParam.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    vRotLib_Scale(&stMem, &stParam, pstWriteList);
}


/****************************************************************************/

void vGfBuffScaleBlendFull(gf_image_st * pstSrcImage, float32_t f32FactorX, float32_t f32FactorY,
                           rot_scaleAlign_e eAlignment, gf_image_st * pstDstImage,
                           int32_t i32PosX, int32_t i32PosY)
{
    rot_mem_st           stMem;
    rot_sscalblendCfg_st stParam;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr      = pstSrcImage->u32Address;
    stMem.u16SrcHeight    = pstSrcImage->u16Height;
    stMem.u16SrcWidth     = pstSrcImage->u16Width;
    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.eSrcColFmt = GA_RGBA32;
    }

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.eDstColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.eClipWndEn == GA_EN)
    {
        stParam.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.eFilterEn     = stGastate.eFilterEn;
    stParam.i16OffsetX    = i32PosX;
    stParam.i16OffsetY    = i32PosY;
#ifdef GA_USE_MATH_LIB
    stParam.f64FactorX    = f32FactorX;
    stParam.f64FactorY    = f32FactorY;
#else
    stParam.i32FactorX    = (int32_t)(65536.0 * f32FactorX);
    stParam.i32FactorY    = (int32_t)(65536.0 * f32FactorY);
#endif
    stParam.eAlignment    = eAlignment;
    stParam.eBldOrd       = stGastate.eBlndOrder;
    stParam.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    stParam.eDstRedProt   = stGastate.eRedChPrtEn;
    stParam.eDstGreenProt = stGastate.eGreenChPrtEn;
    stParam.eDstBlueProt  = stGastate.eBlueChPrtEn;
    stParam.eDstAlphaProt = stGastate.eAlphaChPrtEn;
    stParam.eSrcRedFad    = stGastate.eSrcRedFad;
    stParam.eSrcGreenFad  = stGastate.eSrcGreenFad;
    stParam.eSrcBlueFad   = stGastate.eSrcBlueFad;
    stParam.eSrcAlphaFad  = stGastate.eSrcAlphaFad;
    
    vRotLib_ScaleBlend(&stMem, &stParam, pstWriteList);
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vGfBuffPerspectiveBlitFull(gf_image_st * pstSrcImage, float32_t f32AngleX, float32_t f32AngleY, float32_t f32AngleZ,
                                float32_t f32FactorX, float32_t f32FactorY, gf_image_st * pstDstImage,
                                int32_t i32PosX, int32_t i32PosY,
                                uint32_t u32RotPointX, uint32_t u32RotPointY)
{
    rot_mem_st stMem;
    rot_perspectiveCfg_st stParam;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr   = pstSrcImage->u32Address;
    stMem.u16SrcHeight = pstSrcImage->u16Height;
    stMem.u16SrcWidth  = pstSrcImage->u16Width;
    stMem.u32DstAddr   = pstDstImage->u32Address;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.eDstColFmt = GA_RGBA32;
    }

    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.eSrcColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.eClipWndEn == GA_EN)
    {
        stParam.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.eFilterEn    = stGastate.eFilterEn;
    stParam.i16OffsetX   = i32PosX;
    stParam.i16OffsetY   = i32PosY;
    stParam.u32RotPointX = u32RotPointX;
    stParam.u32RotPointY = u32RotPointY;
#ifdef GA_USE_MATH_LIB
    stParam.f64AngleX = f32AngleX;
    stParam.f64AngleY = f32AngleY;
    stParam.f64AngleZ = f32AngleZ;
    stParam.f64ScaleX = f32FactorX;
    stParam.f64ScaleY = f32FactorY;
#else
    stParam.i32AngleX = (int32_t)(65536.0 * f32AngleX);
    stParam.i32AngleY = (int32_t)(65536.0 * f32AngleY);
    stParam.i32AngleZ = (int32_t)(65536.0 * f32AngleZ);
    stParam.i32ScaleX = (int32_t)(65536.0 * f32FactorX);
    stParam.i32ScaleY = (int32_t)(65536.0 * f32FactorY);
#endif
    stParam.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    vRotLib_Perspective(&stMem, &stParam, pstWriteList);
}


/****************************************************************************/

void vGfBuffPerspectiveBlendFull(gf_image_st * pstSrcImage, float32_t f32AngleX, float32_t f32AngleY, float32_t f32AngleZ,
                                 float32_t f32FactorX, float32_t f32FactorY, gf_image_st * pstDstImage,
                                 int32_t i32PosX, int32_t i32PosY,
                                 uint32_t u32RotPointX, uint32_t u32RotPointY)
{
    rot_mem_st stMem;
    rot_perspectiveblendCfg_st stParam;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr   = pstSrcImage->u32Address;
    stMem.u16SrcHeight = pstSrcImage->u16Height;
    stMem.u16SrcWidth  = pstSrcImage->u16Width;
    stMem.u32DstAddr   = pstDstImage->u32Address;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eDstColFmt = GA_RGB16;
    }
    else
    {
      stParam.eDstColFmt = GA_RGBA32;
    }

    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.eSrcColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.eClipWndEn == GA_EN)
    {
        stParam.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.eFilterEn    = stGastate.eFilterEn;
    stParam.i16OffsetX   = i32PosX;
    stParam.i16OffsetY   = i32PosY;
    stParam.u32RotPointX = u32RotPointX;
    stParam.u32RotPointY = u32RotPointY;
#ifdef GA_USE_MATH_LIB
    stParam.f64AngleX = f32AngleX;
    stParam.f64AngleY = f32AngleY;
    stParam.f64AngleZ = f32AngleZ;
    stParam.f64ScaleX = f32FactorX;
    stParam.f64ScaleY = f32FactorY;
#else
    stParam.i32AngleX = (int32_t)(65536.0 * f32AngleX);
    stParam.i32AngleY = (int32_t)(65536.0 * f32AngleY);
    stParam.i32AngleZ = (int32_t)(65536.0 * f32AngleZ);
    stParam.i32ScaleX = (int32_t)(65536.0 * f32FactorX);
    stParam.i32ScaleY = (int32_t)(65536.0 * f32FactorY);
#endif
    stParam.eBldOrd       = stGastate.eBlndOrder;
    stParam.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    stParam.eDstRedProt   = stGastate.eRedChPrtEn;
    stParam.eDstGreenProt = stGastate.eGreenChPrtEn;
    stParam.eDstBlueProt  = stGastate.eBlueChPrtEn;
    stParam.eDstAlphaProt = stGastate.eAlphaChPrtEn;
    stParam.eSrcRedFad    = stGastate.eSrcRedFad;
    stParam.eSrcGreenFad  = stGastate.eSrcGreenFad;
    stParam.eSrcBlueFad   = stGastate.eSrcBlueFad;
    stParam.eSrcAlphaFad  = stGastate.eSrcAlphaFad;

    vRotLib_PerspectiveBlend(&stMem, &stParam, pstWriteList);
}
#endif


/****************************************************************************/

void vGfBuffTransformationFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_table_st * pstTable,
                               uint32_t u32PosX, uint32_t u32PosY)
{
    transf_mem_st stMem;
    transf_Lut_st stLutCfg;
    transf_Prm_st stTsfPrm;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr     = pstSrcImage->u32Address;
    stMem.u16SrcWidth    = pstSrcImage->u16Width;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stMem.u32DstAddr    = pstDstImage->u32Address + 2U*pstDstImage->u16Width * u32PosY + 2U*u32PosX;
        stTsfPrm.eDstColFmt = GA_RGB16;
    }
    else
    {
        stMem.u32DstAddr    = pstDstImage->u32Address + 4U*pstDstImage->u16Width * u32PosY + 4U*u32PosX;
        stTsfPrm.eDstColFmt = GA_RGBA32;
    }

    stMem.u16DstWidth    = pstDstImage->u16Width;
    stMem.u16LineCnt     = pstTable->u16Height;
    if(stGastate.eTsfMode == TSF_MODE_COLOR)
    {
        if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u16DstImgWidth = pstTable->u16Width/3U;
        }
        else
        {
            stMem.u16DstImgWidth = pstTable->u16Width/4U;
        }
    }
    else
    {
        stMem.u16DstImgWidth = pstTable->u16Width;
    }
    stLutCfg.u32Addr    = pstTable->u32Address;
    stLutCfg.u16Width   = pstTable->u16Width;
    stLutCfg.u16LineCnt = pstTable->u16Height;

    stTsfPrm.eTsfMode   = stGastate.eTsfMode;

    stTsfPrm.eFilterEn  = stGastate.eFilterEn;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stTsfPrm.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stTsfPrm.eSrcColFmt = GA_RGBA32;
    }

    stTsfPrm.u32Color      = stGastate.u32TsfPredefColor;
    stTsfPrm.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stTsfPrm.u8DstAlphaVal = stGastate.u8DstAlphaVal;


    vTransf_ConfigTransfOp(&stMem, &stLutCfg, &stTsfPrm, pstWriteList);
}


/****************************************************************************/

void vGfBuffTransformationFullOptimized(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_table_st * pstTable,
                                        uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight)
{
    transf_mem_st stMem;
    transf_Lut_st stLutCfg;
    transf_Prm_st stTsfPrm;
    uint32_t      u32DivX, u32ModX, u32CountX;
    uint32_t      u32DivY, u32ModY, u32CountY;
    uint32_t      u32ByteCountDest;
    uint32_t      u32LutIndexCount;
    uint32_t      u32LUTBlockWidth;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr  = pstSrcImage->u32Address;
    stMem.u16SrcWidth = pstSrcImage->u16Width;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stTsfPrm.eDstColFmt = GA_RGB16;
        u32ByteCountDest    = 2U;
    }
    else
    {
        stTsfPrm.eDstColFmt = GA_RGBA32;
        u32ByteCountDest    = 4U;
    }

    stMem.u16DstWidth   = pstDstImage->u16Width;

    stLutCfg.u16Width   = pstTable->u16Width;

    stTsfPrm.eTsfMode   = stGastate.eTsfMode;
    stTsfPrm.eFilterEn  = stGastate.eFilterEn;
    if(stGastate.eTsfMode == TSF_MODE_COLOR)
    {
        if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u16DstImgWidth = pstTable->u16Width/3U;
            u32LUTBlockWidth     = u32BlockWidth*3U;
            u32LutIndexCount     = 3U;
        }
        else
        {
            stMem.u16DstImgWidth = pstTable->u16Width/4U;
            u32LUTBlockWidth     = u32BlockWidth*4U;
            u32LutIndexCount     = 4U;
        }
    }
    else
    {
        stMem.u16DstImgWidth = pstTable->u16Width;
        u32LUTBlockWidth     = u32BlockWidth;
        u32LutIndexCount     = 1U;
    }
    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stTsfPrm.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stTsfPrm.eSrcColFmt = GA_RGBA32;
    }

    stTsfPrm.u32Color      = stGastate.u32TsfPredefColor;
    stTsfPrm.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stTsfPrm.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    u32DivX = pstTable->u16Width/u32LUTBlockWidth;
    u32ModX = pstTable->u16Width - u32DivX*u32LUTBlockWidth;
    u32DivY = pstTable->u16Height/u32BlockHeight;
    u32ModY = pstTable->u16Height - u32DivY*u32BlockHeight;

    for (u32CountY=0U; u32CountY<=u32DivY; u32CountY++)
    {
        for (u32CountX=0U; u32CountX<=u32DivX; u32CountX++)
        {
            if (u32CountX<u32DivX)
            {
                if (u32CountY<u32DivY)
                {
                    /* normal operation */
                    stMem.u32DstAddr     = pstDstImage->u32Address + u32ByteCountDest*pstDstImage->u16Width * u32PosY + u32ByteCountDest*u32PosX +
                                           u32ByteCountDest*u32CountY*u32BlockHeight*pstDstImage->u16Width + u32ByteCountDest*u32CountX*u32BlockWidth;
                    stMem.u16DstImgWidth = u32BlockWidth;
                    stMem.u16LineCnt     = u32BlockHeight;
                    stLutCfg.u32Addr     = pstTable->u32Address + 4U*u32CountY*u32BlockHeight*pstTable->u16Width + 4U*u32CountX*u32LUTBlockWidth;
                    stLutCfg.u16LineCnt  = u32BlockHeight;

                    vTransf_ConfigTransfOp(&stMem, &stLutCfg, &stTsfPrm, pstWriteList);
                    vGfListExecute();
                }
                else
                {
                    if (u32ModY != 0U)
                    {
                        /* lowest row */
                        stMem.u32DstAddr     = pstDstImage->u32Address + u32ByteCountDest*pstDstImage->u16Width * u32PosY + u32ByteCountDest*u32PosX +
                                               u32ByteCountDest*u32CountY*u32BlockHeight*pstDstImage->u16Width + u32ByteCountDest*u32CountX*u32BlockWidth;
                        stMem.u16DstImgWidth = u32BlockWidth;
                        stMem.u16LineCnt     = pstTable->u16Height - u32DivY*u32BlockHeight;
                        stLutCfg.u32Addr     = pstTable->u32Address + 4U*u32CountY*u32BlockHeight*pstTable->u16Width + 4U*u32CountX*u32LUTBlockWidth;
                        stLutCfg.u16LineCnt  = pstTable->u16Height - u32DivY*u32BlockHeight;

                        vTransf_ConfigTransfOp(&stMem, &stLutCfg, &stTsfPrm, pstWriteList);
                        vGfListExecute();
                    }
                }
            }
            else
            {
                if (u32ModX != 0U)
                {
                    if (u32CountY<u32DivY)
                    {
                        /* most right part */
                        stMem.u32DstAddr     = pstDstImage->u32Address + u32ByteCountDest*pstDstImage->u16Width * u32PosY + u32ByteCountDest*u32PosX +
                                               u32ByteCountDest*u32CountY*u32BlockHeight*pstDstImage->u16Width + u32ByteCountDest*u32CountX*u32BlockWidth;
                        stMem.u16DstImgWidth = (pstTable->u16Width - u32DivX*u32LUTBlockWidth)/u32LutIndexCount;
                        stMem.u16LineCnt     = u32BlockHeight;
                        stLutCfg.u32Addr     = pstTable->u32Address + 4U*u32CountY*u32BlockHeight*pstTable->u16Width + 4U*u32CountX*u32LUTBlockWidth;
                        stLutCfg.u16LineCnt  = u32BlockHeight;

                        vTransf_ConfigTransfOp(&stMem, &stLutCfg, &stTsfPrm, pstWriteList);
                        vGfListExecute();
                    }
                    else
                    {
                        if (u32ModY != 0U)
                        {
                            /* lower right part */
                            stMem.u32DstAddr     = pstDstImage->u32Address + u32ByteCountDest*pstDstImage->u16Width * u32PosY + u32ByteCountDest*u32PosX +
                                                   u32ByteCountDest*u32CountY*u32BlockHeight*pstDstImage->u16Width + u32ByteCountDest*u32CountX*u32BlockWidth;
                            stMem.u16DstImgWidth = (pstTable->u16Width - u32DivX*u32LUTBlockWidth)/u32LutIndexCount;
                            stMem.u16LineCnt     = pstTable->u16Height - u32DivY*u32BlockHeight;
                            stLutCfg.u32Addr     = pstTable->u32Address + 4U*u32CountY*u32BlockHeight*pstTable->u16Width + 4U*u32CountX*u32LUTBlockWidth;
                            stLutCfg.u16LineCnt  = pstTable->u16Height - u32DivY*u32BlockHeight;

                            vTransf_ConfigTransfOp(&stMem, &stLutCfg, &stTsfPrm, pstWriteList);
                            vGfListExecute();
                        }
                    }
                }
            }
        }
    }
}


/****************************************************************************/

void vGfBuffTransformationBlendFull(gf_image_st * pstSrcImage, gf_image_st * pstDstImage, gf_table_st * pstTable,
                                    uint32_t u32PosX, uint32_t u32PosY)
{
    transf_mem_st stMem;
    transf_Lut_st stLutCfg;
    transf_PrmBlend_st stTsfPrm;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr     = pstSrcImage->u32Address;
    stMem.u16SrcWidth    = pstSrcImage->u16Width;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stMem.u32DstAddr    = pstDstImage->u32Address + 2U*pstDstImage->u16Width * u32PosY + 2U*u32PosX;
        stTsfPrm.eDstColFmt = GA_RGB16;
    }
    else
    {
        stMem.u32DstAddr    = pstDstImage->u32Address + 4U*pstDstImage->u16Width * u32PosY + 4U*u32PosX;
        stTsfPrm.eDstColFmt = GA_RGBA32;
    }

    stMem.u16DstWidth    = pstDstImage->u16Width;
    stMem.u16LineCnt     = pstTable->u16Height;
    if(stGastate.eTsfMode == TSF_MODE_COLOR)
    {
        if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
        {
            stMem.u16DstImgWidth = pstTable->u16Width/3U;
        }
        else
        {
            stMem.u16DstImgWidth = pstTable->u16Width/4U;
        }
    }
    else
    {
        stMem.u16DstImgWidth = pstTable->u16Width;
    }
    stLutCfg.u32Addr    = pstTable->u32Address;
    stLutCfg.u16Width   = pstTable->u16Width;
    stLutCfg.u16LineCnt = pstTable->u16Height;

    stTsfPrm.eTsfMode      = stGastate.eTsfMode;

    stTsfPrm.eFilterEn     = stGastate.eFilterEn;
    stTsfPrm.eDstRedProt   = stGastate.eRedChPrtEn;
    stTsfPrm.eDstGreenProt = stGastate.eGreenChPrtEn;
    stTsfPrm.eDstBlueProt  = stGastate.eBlueChPrtEn;
    stTsfPrm.eDstAlphaProt = stGastate.eAlphaChPrtEn;

    stTsfPrm.eSrcRedFad    = GA_DIS;
    stTsfPrm.eSrcGreenFad  = GA_DIS;
    stTsfPrm.eSrcBlueFad   = GA_DIS;
    stTsfPrm.eSrcAlphaFad  = GA_DIS;

    stTsfPrm.eBldOrd       = stGastate.eBlndOrder;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stTsfPrm.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stTsfPrm.eSrcColFmt = GA_RGBA32;
    }

    stTsfPrm.u32Color      = stGastate.u32TsfPredefColor;
    stTsfPrm.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stTsfPrm.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    /* rearrange pixel by transformation */
    vTransf_ConfigTransfBlendOp(&stMem, &stLutCfg, &stTsfPrm, pstWriteList);
}


/****************************************************************************/

void vGfBuffDrawLine(gf_image_st * pstDstImage, drw_OpCfg_st *pstOption, drw_Line_st *pstLine)
{
    drw_mem_st  stMem;
    drw_Line_st stLineLocal;

    u8PreviousOperation = 0U;

    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    stLineLocal.stPtStart.u16X = (17U-u32SubResPPos)*pstLine->stPtStart.u16X;
    stLineLocal.stPtStart.u16Y = (17U-u32SubResPPos)*pstLine->stPtStart.u16Y;
    stLineLocal.stPtEnd.u16X   = (17U-u32SubResPPos)*pstLine->stPtEnd.u16X;
    stLineLocal.stPtEnd.u16Y   = (17U-u32SubResPPos)*pstLine->stPtEnd.u16Y;
    stLineLocal.eStartCap      = pstLine->eStartCap;
    stLineLocal.eEndCap        = pstLine->eEndCap;
    stLineLocal.stColor        = pstLine->stColor;
    stLineLocal.u16Thickness   = pstLine->u16Thickness;

    vDrw_DrawLine(&stMem, pstOption, &stLineLocal, pstWriteList);
}


/*****************************************************************************************/

void vGfBuffDrawTriangle(gf_image_st * pstDstImage, drw_OpCfg_st *pstOption, drw_Trngl_st *pstTrngl)

{
    drw_mem_st   stMem;
    drw_Trngl_st stTrnglLocal;

    u8PreviousOperation = 0U;

    stMem.u32DstAddr      = pstDstImage->u32Address;
    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    stTrnglLocal.stPt1.u16X = (17U-u32SubResPPos)*pstTrngl->stPt1.u16X;
    stTrnglLocal.stPt1.u16Y = (17U-u32SubResPPos)*pstTrngl->stPt1.u16Y;
    stTrnglLocal.stPt2.u16X = (17U-u32SubResPPos)*pstTrngl->stPt2.u16X;
    stTrnglLocal.stPt2.u16Y = (17U-u32SubResPPos)*pstTrngl->stPt2.u16Y;
    stTrnglLocal.stPt3.u16X = (17U-u32SubResPPos)*pstTrngl->stPt3.u16X;
    stTrnglLocal.stPt3.u16Y = (17U-u32SubResPPos)*pstTrngl->stPt3.u16Y;
    stTrnglLocal.eAntialEn1 = pstTrngl->eAntialEn1;
    stTrnglLocal.eAntialEn2 = pstTrngl->eAntialEn2;
    stTrnglLocal.eAntialEn3 = pstTrngl->eAntialEn3;
    stTrnglLocal.stColor    = pstTrngl->stColor;

    vDrw_DrawTriangle(&stMem, pstOption, &stTrnglLocal, pstWriteList);
}


/****************************************************************************/

void vGfBuffDrawCircle(gf_image_st *pstDstImage, drw_OpCfg_st *pstOption, gf_circle_st *pstCircle)
{
    float32_t f32Angle, f32AngleDelta, f32PosX, f32PosY;
    drw_Trngl_st stTrngl;
    uint32_t u32ResPPos, u32ResCPos;
    gf_subRes_e ePPos, eCPos; 
    uint16_t u16Count, u16Index, u16Radius;

    /* Get Sub resolution values */ 
    u32ResPPos = u32GfGetSubRes_Position();
    u32ResCPos = u32GfGetSubRes_CenterPosition();
    ePPos = GA_PIXEL_RES;
    eCPos = GA_PIXEL_RES;
    
    /* Sub Resolution position is already handled before calling vGfBuffDrawTriangle() API.
       Hence u32SubResPPos is initialised to default value */
    vGfSetSubRes(GA_PIXEL_RES, GA_PIXEL_RES);

    /* Initializing Radius and triangle colour value */
    u16Radius = pstCircle->u16Radius;
    stTrngl.stColor = pstCircle->stColor;
    pstCircle->stCenter.u16X = (uint16_t)((17U-u32ResPPos)*(pstCircle->stCenter.u16X));
    pstCircle->stCenter.u16Y = (uint16_t)((17U-u32ResPPos)*(pstCircle->stCenter.u16Y));

    /* Draw line feature with Circular end caps is used to get circle when radius < 16 and when AA is enabled */
    if((u16Radius < 256U) && (pstCircle->eAntialEn == GA_EN))
    {
        vGfDrawCircleWithEndCaps(pstDstImage, pstOption, pstCircle);
    }
    else
    {
        /* Circles with radius more than or equal to 16 will be drawn using triangles */
        /* Number of triangles for semicircle - 1 */
        u16Count = (uint16_t)(GA_CONST_PI / (acos((u16Radius >> 4U) / ((u16Radius >> 4U) + 0.125)) * 2U));
        /* Triangle count is increased to odd value to avoid overlap between the triangles */
        u16Count += (u16Count & 1U);

        /* angle for each triangle over a semicircle */
        f32Angle = (GA_CONST_PI / (u16Count + 1U));
        f32AngleDelta = f32Angle;

        /* Pattern for arranging vertices in Ist quadrant ; u16Count is used for first half circle */
        /* AA settings for Ist quadrant */
        stTrngl.eAntialEn1 = GA_DIS;
        stTrngl.eAntialEn2 = GA_DIS;
        stTrngl.eAntialEn3 = pstCircle->eAntialEn;
        
        f32PosX = u16Radius * cos(f32Angle);
        f32PosY = u16Radius * sin(f32Angle);

        stTrngl.stPt3.u16X = (uint16_t)(pstCircle->stCenter.u16X + f32PosX);
        stTrngl.stPt3.u16Y = (uint16_t)(pstCircle->stCenter.u16Y - f32PosY);
        
        stTrngl.stPt2.u16X = pstCircle->stCenter.u16X;
        stTrngl.stPt2.u16Y = pstCircle->stCenter.u16Y;
        
        f32Angle += f32AngleDelta;
        
        /* Check for angle between 0 to 90 degree and triangle count for first half of the circle; 
           u16Index = 2 because the first triangle is skipped and 
           joined with last triangle of the circle to avoid overlap */
        for(u16Index = 2U; (u16Index <= u16Count) && (f32Angle <= GF_PI_BY_2 ); u16Index++)
        {
            f32PosX = u16Radius * cos(f32Angle);
            f32PosY = u16Radius * sin(f32Angle);
            
            stTrngl.stPt1.u16X = (uint16_t)(pstCircle->stCenter.u16X + f32PosX);
            stTrngl.stPt1.u16Y = (uint16_t)(pstCircle->stCenter.u16Y - f32PosY);

            vGfBuffDrawTriangle(pstDstImage, pstOption, &stTrngl);

            stTrngl.stPt3.u16X = stTrngl.stPt1.u16X;
            stTrngl.stPt3.u16Y = stTrngl.stPt1.u16Y;
            
            f32Angle += f32AngleDelta;
        }
        
        /* Pattern for arranging vertices in 2nd quadrant */
        /* AA settings for II quadrant */
        stTrngl.eAntialEn1 = pstCircle->eAntialEn;
        stTrngl.eAntialEn2 = GA_DIS;
        stTrngl.eAntialEn3 = GA_DIS;
        
        /* check for angle which covers both I and II quadrant */
        stTrngl.stPt3.u16X = pstCircle->stCenter.u16X;
        stTrngl.stPt3.u16Y = pstCircle->stCenter.u16Y;

        f32PosX = u16Radius * cos(f32Angle);
        f32PosY = u16Radius * sin(f32Angle);

        stTrngl.stPt2.u16X = (uint16_t)(pstCircle->stCenter.u16X + f32PosX);
        stTrngl.stPt2.u16Y = (uint16_t)(pstCircle->stCenter.u16Y - f32PosY);

        /* Check for anticlockwise direction and sorting */
        if(stTrngl.stPt1.u16Y > stTrngl.stPt2.u16Y)
        {
            /* AA flag is not required to be sorted in circle so passing 0 as argument to sort function*/
            vGfDrawTriangleSort(pstDstImage, pstOption, &stTrngl, pstCircle->eAntialEn & 1);

            /* Reset center and AA settings for triangles to be drawn in IInd quadrant */
            stTrngl.stPt3.u16X = pstCircle->stCenter.u16X;
            stTrngl.stPt3.u16Y = pstCircle->stCenter.u16Y;

            stTrngl.eAntialEn1 = pstCircle->eAntialEn;
            stTrngl.eAntialEn2 = GA_DIS;
            stTrngl.eAntialEn3 = GA_DIS;
        }
        else /* If the points are arranged in properly no change in AA effect and coordinates arrangement */
        {
            vGfBuffDrawTriangle(pstDstImage, pstOption, &stTrngl);

            stTrngl.stPt1.u16X = stTrngl.stPt2.u16X;
            stTrngl.stPt1.u16Y = stTrngl.stPt2.u16Y;
        }
        f32Angle += f32AngleDelta;
        u16Index++;

        /* Check for angle between 90 to 180 degree and triangle count for first half of the circle */
        for(; (u16Index <= u16Count) && (GF_PI_BY_2 < f32Angle) && (f32Angle < GA_CONST_PI); u16Index++)
        {
            f32PosX = u16Radius * cos(f32Angle);
            f32PosY = u16Radius * sin(f32Angle);

            stTrngl.stPt2.u16X = (uint16_t)(pstCircle->stCenter.u16X + f32PosX);
            stTrngl.stPt2.u16Y = (uint16_t)(pstCircle->stCenter.u16Y - f32PosY);

            vGfBuffDrawTriangle(pstDstImage, pstOption, &stTrngl);

            stTrngl.stPt1.u16X = stTrngl.stPt2.u16X;
            stTrngl.stPt1.u16Y = stTrngl.stPt2.u16Y;

            f32Angle += f32AngleDelta;
        }
        
        /* Pattern for arranging vertices in 3rd and 4th quadrant */
        /* Last triangle of 2nd quadrant and first triangle of 3rd quadrant are drawn as single triangle
           to avoid overlap between two triangles  */

        /* AA settings for triangle between III and IV quadrant */
        stTrngl.eAntialEn1 = pstCircle->eAntialEn;
        stTrngl.eAntialEn2 = GA_DIS;
        stTrngl.eAntialEn3 = GA_DIS;

        f32Angle = GA_CONST_PI + f32AngleDelta;

        f32PosX = u16Radius * cos(f32Angle);
        f32PosY = u16Radius * sin(f32Angle);

        stTrngl.stPt2.u16X = (uint16_t)(pstCircle->stCenter.u16X + f32PosX);
        stTrngl.stPt2.u16Y = (uint16_t)(pstCircle->stCenter.u16Y - f32PosY);

        stTrngl.stPt3.u16X = pstCircle->stCenter.u16X;
        stTrngl.stPt3.u16Y = pstCircle->stCenter.u16Y;
        
        vGfBuffDrawTriangle(pstDstImage, pstOption, &stTrngl);
        
         /* AA settings and co-ordinate arrangement for III and IV quadrant */
        stTrngl.stPt1.u16X = pstCircle->stCenter.u16X;
        stTrngl.stPt1.u16Y = pstCircle->stCenter.u16Y;
        
        stTrngl.eAntialEn1 = GA_DIS;
        stTrngl.eAntialEn2 = pstCircle->eAntialEn;
        stTrngl.eAntialEn3 = GA_DIS;
        
        f32Angle += f32AngleDelta;
        u16Index++;
        /* Check for angle between 180 to 360 degree and triangle count for second half of the circle */
        /* Same pattern of arrangement is used for points in 3rd and 4th quadrant since point1 is same */
        for(;(u16Index <= (u16Count * 2U)) && (f32Angle < GF_2_PI) && (f32Angle > GA_CONST_PI); u16Index++)
        {
            f32PosX = u16Radius * cos(f32Angle);
            f32PosY = u16Radius * sin(f32Angle);

            stTrngl.stPt3.u16X = (uint16_t)(pstCircle->stCenter.u16X + f32PosX);
            stTrngl.stPt3.u16Y = (uint16_t)(pstCircle->stCenter.u16Y - f32PosY);

            vGfBuffDrawTriangle(pstDstImage, pstOption, &stTrngl);

            stTrngl.stPt2.u16X = stTrngl.stPt3.u16X;
            stTrngl.stPt2.u16Y = stTrngl.stPt3.u16Y;

            f32Angle += f32AngleDelta;
        }
        /* AA and co-ordinate arrangements for last triangle to complete the circle */
        /* Last triangle of 4th quadrant and first triangle of 1st quadrant are drawn as single triangle
           to avoid overlap between two triangles  */
        f32PosX = u16Radius * cos(f32AngleDelta);
        f32PosY = u16Radius * sin(f32AngleDelta);
        
        stTrngl.stPt1.u16X = (uint16_t)(pstCircle->stCenter.u16X + f32PosX);
        stTrngl.stPt1.u16Y = (uint16_t)(pstCircle->stCenter.u16Y - f32PosY);

        stTrngl.stPt2.u16X = pstCircle->stCenter.u16X;
        stTrngl.stPt2.u16Y = pstCircle->stCenter.u16Y;

        stTrngl.eAntialEn2 = GA_DIS;
        stTrngl.eAntialEn3 = pstCircle->eAntialEn;

        vGfBuffDrawTriangle(pstDstImage, pstOption, &stTrngl);
    }
    /* Reset the Sub Resolution positions */
    if(u32ResPPos == 1U)
    {
        ePPos = GA_HIGH_RES;
    }
    if(u32ResCPos == 1U)
    {
        eCPos = GA_HIGH_RES;
    }
    vGfSetSubRes(ePPos, eCPos);
}


/****************************************************************************/

void vGfBuffDrawPolygon(gf_image_st *pstDstImage, drw_OpCfg_st *pstOption, gf_polygon_st *pstPolygon)
{
    drw_Trngl_st stTrngl;
    uint16_t u16NumVert;
    uint16_t u16Count;
    uint8_t u8AAEdge;
    
    u16NumVert = pstPolygon->u16NumVert;
    stTrngl.stColor = pstPolygon->stColor;
    
    /* First co-ordinate will remain common for all triangles */
    stTrngl.stPt1.u16X = pstPolygon->pstPolyVertex[0U].u16X;
    stTrngl.stPt1.u16Y = pstPolygon->pstPolyVertex[0U].u16Y;
    
    /* AAEdge1 will be enabled only for the first time */
    u8AAEdge = (uint8_t)(pstPolygon->eAntialEn);
    for(u16Count = 0U;u16Count < u16NumVert - 2U; u16Count++)
    {
        /* Values for second and third co-ordinate */
        stTrngl.stPt2.u16X = pstPolygon->pstPolyVertex[u16Count + 1U].u16X;
        stTrngl.stPt2.u16Y = pstPolygon->pstPolyVertex[u16Count + 1U].u16Y;

        stTrngl.stPt3.u16X = pstPolygon->pstPolyVertex[u16Count + 2U].u16X;
        stTrngl.stPt3.u16Y = pstPolygon->pstPolyVertex[u16Count + 2U].u16Y;

        /*
         * Anti aliasing flag needs to enabled for all outer edges
         * in the following conditions and the conditions needs to be 
         * checked for all edges of the triangle.
         * 1) The difference between the vertex index is equals to 1.
         * 2) The difference between the vertex index is equals to (total number of polygon vertices-1)
         *    for the last edge drawn to close the polygon should have AA enabled.
         */
        if(pstPolygon->eAntialEn == GA_EN)
        {
            /* Edge2: Enable 2 bit (0010). Edge2 is always enabled */
            u8AAEdge |= 2U;

            if((u16Count + 2U) == (u16NumVert - 1U))
            {
                /* Edge3: Enable 3 bit (0100)*/
                u8AAEdge |= 4U;
            }
        }
        
        /* Sorting function to sort the co-ordinates in anticlockwise direction and AntiAliasing edge
           and then draw the triangle */
        vGfDrawTriangleSort(pstDstImage, pstOption, &stTrngl, u8AAEdge);
        /*Reset AA settings */
        u8AAEdge = 0U;
    }
}


/****************************************************************************/

void vGfInsertList(uint64_t * pu64Values, uint32_t u32Length)
{
    uint32_t u32Curr;
    ga_list_st * pstCmdList;
    uint64_t   * pu64Curr;

    /* get pointer to write list */
    pstCmdList = pstGfListGetWrite();

    /* Update Pointer */
    pu64Curr = (uint64_t*) pstCmdList->pu64Current;

    /* fill list */
    for(u32Curr=0; u32Curr<u32Length; u32Curr++)
    {
        pu64Curr[u32Curr] = *(pu64Values + u32Curr);
    }

    /* Update List Pointer */
    pstCmdList->pu64Current = &pu64Curr[u32Curr];

    pstCmdList->u32UsedDoubleWords = u32Curr;
}


/****************************************************************************/

static float64_t* f64GETMATRIX(void)
{
    float64_t * matrix;

    switch (matrixmode)
    {
        case GA_RE_PROJECTION:
            matrix = ((float64_t*)projection);
            break;
        case GA_RE_MODELVIEW:
            matrix = ((float64_t*)modelview);
            break;
        case GA_RE_IP:
            matrix = ((float64_t*)ip);
            break;
    }

    return matrix;
}


/****************************************************************************/

static void vMMMUL4x4(float64_t* r, float64_t* a, float64_t *b)
{
    float64_t n[16];
    uint32_t  i;

    n[0] = a[0]*b[0] + a[4]*b[1] + a[8]*b[2]  + a[12]*b[3];
    n[1] = a[1]*b[0] + a[5]*b[1] + a[9]*b[2]  + a[13]*b[3];
    n[2] = a[2]*b[0] + a[6]*b[1] + a[10]*b[2] + a[14]*b[3];
    n[3] = a[3]*b[0] + a[7]*b[1] + a[11]*b[2] + a[15]*b[3];

    n[4] = a[0]*b[4] + a[4]*b[5] + a[8]*b[6]  + a[12]*b[7];
    n[5] = a[1]*b[4] + a[5]*b[5] + a[9]*b[6]  + a[13]*b[7];
    n[6] = a[2]*b[4] + a[6]*b[5] + a[10]*b[6] + a[14]*b[7];
    n[7] = a[3]*b[4] + a[7]*b[5] + a[11]*b[6] + a[15]*b[7];

    n[8]  = a[0]*b[8] + a[4]*b[9] + a[8]*b[10]  + a[12]*b[11];
    n[9]  = a[1]*b[8] + a[5]*b[9] + a[9]*b[10]  + a[13]*b[11];
    n[10] = a[2]*b[8] + a[6]*b[9] + a[10]*b[10] + a[14]*b[11];
    n[11] = a[3]*b[8] + a[7]*b[9] + a[11]*b[10] + a[15]*b[11];

    n[12] = a[0]*b[12] + a[4]*b[13] + a[8]*b[14]  + a[12]*b[15];
    n[13] = a[1]*b[12] + a[5]*b[13] + a[9]*b[14]  + a[13]*b[15];
    n[14] = a[2]*b[12] + a[6]*b[13] + a[10]*b[14] + a[14]*b[15];
    n[15] = a[3]*b[12] + a[7]*b[13] + a[11]*b[14] + a[15]*b[15];

    for (i=0; i<16; i++)
    {
        r[i] = n[i];
    }
}


/****************************************************************************/

static void vMVMUL4x4(float64_t* r, float64_t* m, float64_t* v)
{
    float64_t n[4];
    uint32_t i;

    n[0] = m[0]*v[0] + m[4]*v[1] + m[8]*v[2]  + m[12]*v[3];
    n[1] = m[1]*v[0] + m[5]*v[1] + m[9]*v[2]  + m[13]*v[3];
    n[2] = m[2]*v[0] + m[6]*v[1] + m[10]*v[2] + m[14]*v[3];
    n[3] = m[3]*v[0] + m[7]*v[1] + m[11]*v[2] + m[15]*v[3];

    for (i=0; i<4; i++)
    {
        r[i]=n[i];
    }
}


/****************************************************************************/

/* This code comes directly from GLU except that it is for float64_t */
static int iGfInvertMatrix4x4(float64_t *m, float64_t *out)
{
    float64_t wtmp[4][8];
    float64_t m0, m1, m2, m3, s;
    float64_t *r0, *r1, *r2, *r3;

    r0 = wtmp[0];
    r1 = wtmp[1];
    r2 = wtmp[2];
    r3 = wtmp[3];

    r0[0] = MAT(m, 0, 0);
    r0[1] = MAT(m, 0, 1);
    r0[2] = MAT(m, 0, 2);
    r0[3] = MAT(m, 0, 3);
    r0[4] = 1.0;
    r0[5] = 0.0;
    r0[6] = 0.0;
    r0[7] = 0.0;
    r1[0] = MAT(m, 1, 0);
    r1[1] = MAT(m, 1, 1);
    r1[2] = MAT(m, 1, 2);
    r1[3] = MAT(m, 1, 3);
    r1[5] = 1.0;
    r1[4] = 0.0;
    r1[6] = 0.0;
    r1[7] = 0.0;
    r2[0] = MAT(m, 2, 0);
    r2[1] = MAT(m, 2, 1);
    r2[2] = MAT(m, 2, 2);
    r2[3] = MAT(m, 2, 3);
    r2[6] = 1.0;
    r2[4] = 0.0;
    r2[5] = 0.0;
    r2[7] = 0.0;
    r3[0] = MAT(m, 3, 0);
    r3[1] = MAT(m, 3, 1);
    r3[2] = MAT(m, 3, 2);
    r3[3] = MAT(m, 3, 3);
    r3[7] = 1.0;
    r3[4] = 0.0;
    r3[5] = 0.0;
    r3[6] = 0.0;
    /* choose pivot - or die */
    if (fabs(r3[0]) > fabs(r2[0]))
    {
        SWAP_ROWS_FLOAT(r3, r2);
    }
    if (fabs(r2[0]) > fabs(r1[0]))
    {
        SWAP_ROWS_FLOAT(r2, r1);
    }
    if (fabs(r1[0]) > fabs(r0[0]))
    {
        SWAP_ROWS_FLOAT(r1, r0);
    }
    if (0.0 == r0[0])
    {
        return 0;
    }
    /* eliminate first variable */
    m1 = r1[0] / r0[0];
    m2 = r2[0] / r0[0];
    m3 = r3[0] / r0[0];
    s  = r0[1];
    r1[1] -= m1 * s;
    r2[1] -= m2 * s;
    r3[1] -= m3 * s;
    s = r0[2];
    r1[2] -= m1 * s;
    r2[2] -= m2 * s;
    r3[2] -= m3 * s;
    s = r0[3];
    r1[3] -= m1 * s;
    r2[3] -= m2 * s;
    r3[3] -= m3 * s;
    s = r0[4];
    if (s != 0.0)
    {
        r1[4] -= m1 * s;
        r2[4] -= m2 * s;
        r3[4] -= m3 * s;
    }
    s = r0[5];
    if (s != 0.0)
    {
        r1[5] -= m1 * s;
        r2[5] -= m2 * s;
        r3[5] -= m3 * s;
    }
    s = r0[6];
    if (s != 0.0)
    {
        r1[6] -= m1 * s;
        r2[6] -= m2 * s;
        r3[6] -= m3 * s;
    }
    s = r0[7];
    if (s != 0.0)
    {
        r1[7] -= m1 * s;
        r2[7] -= m2 * s;
        r3[7] -= m3 * s;
    }
    /* choose pivot - or die */
    if (fabs(r3[1]) > fabs(r2[1]))
    {
        SWAP_ROWS_FLOAT(r3, r2);
    }
    if (fabs(r2[1]) > fabs(r1[1]))
    {
        SWAP_ROWS_FLOAT(r2, r1);
    }
    if (0.0 == r1[1])
    {
        return 0;
    }
    /* eliminate second variable */
    m2 = r2[1] / r1[1];
    m3 = r3[1] / r1[1];
    r2[2] -= m2 * r1[2];
    r3[2] -= m3 * r1[2];
    r2[3] -= m2 * r1[3];
    r3[3] -= m3 * r1[3];
    s = r1[4];
    if (0.0 != s)
    {
        r2[4] -= m2 * s;
        r3[4] -= m3 * s;
    }
    s = r1[5];
    if (0.0 != s)
    {
        r2[5] -= m2 * s;
        r3[5] -= m3 * s;
    }
    s = r1[6];
    if (0.0 != s)
    {
        r2[6] -= m2 * s;
        r3[6] -= m3 * s;
    }
    s = r1[7];
    if (0.0 != s)
    {
        r2[7] -= m2 * s;
        r3[7] -= m3 * s;
    }
    /* choose pivot - or die */
    if (fabs(r3[2]) > fabs(r2[2]))
    {
        SWAP_ROWS_FLOAT(r3, r2);
    }
    if (0.0 == r2[2])
    {
        return 0;
    }
    /* eliminate third variable */
    m3 = r3[2] / r2[2];
    r3[3] -= m3 * r2[3];
    r3[4] -= m3 * r2[4];
    r3[5] -= m3 * r2[5];
    r3[6] -= m3 * r2[6];
    r3[7] -= m3 * r2[7];
    /* last check */
    if (0.0 == r3[3])
    {
        return 0;
    }
    s = 1.0 / r3[3];		/* now back substitute row 3 */
    r3[4] *= s;
    r3[5] *= s;
    r3[6] *= s;
    r3[7] *= s;
    m2 = r2[3];			/* now back substitute row 2 */
    s = 1.0 / r2[2];
    r2[4] = s * (r2[4] - r3[4] * m2);
    r2[5] = s * (r2[5] - r3[5] * m2);
    r2[6] = s * (r2[6] - r3[6] * m2);
    r2[7] = s * (r2[7] - r3[7] * m2);
    m1 = r1[3];
    r1[4] -= r3[4] * m1;
    r1[5] -= r3[5] * m1;
    r1[6] -= r3[6] * m1;
    r1[7] -= r3[7] * m1;
    m0 = r0[3];
    r0[4] -= r3[4] * m0;
    r0[5] -= r3[5] * m0;
    r0[6] -= r3[6] * m0;
    r0[7] -= r3[7] * m0;
    m1 = r1[2];			/* now back substitute row 1 */
    s = 1.0 / r1[1];
    r1[4] = s * (r1[4] - r2[4] * m1);
    r1[5] = s * (r1[5] - r2[5] * m1);
    r1[6] = s * (r1[6] - r2[6] * m1);
    r1[7] = s * (r1[7] - r2[7] * m1);
    m0 = r0[2];
    r0[4] -= r2[4] * m0;
    r0[5] -= r2[5] * m0;
    r0[6] -= r2[6] * m0;
    r0[7] -= r2[7] * m0;
    m0 = r0[1];			/* now back substitute row 0 */
    s = 1.0 / r0[0];
    r0[4] = s * (r0[4] - r1[4] * m0);
    r0[5] = s * (r0[5] - r1[5] * m0);
    r0[6] = s * (r0[6] - r1[6] * m0);
    r0[7] = s * (r0[7] - r1[7] * m0);
    MAT(out, 0, 0) = r0[4];
    MAT(out, 0, 1) = r0[5];
    MAT(out, 0, 2) = r0[6];
    MAT(out, 0, 3) = r0[7];
    MAT(out, 1, 0) = r1[4];
    MAT(out, 1, 1) = r1[5];
    MAT(out, 1, 2) = r1[6];
    MAT(out, 1, 3) = r1[7];
    MAT(out, 2, 0) = r2[4];
    MAT(out, 2, 1) = r2[5];
    MAT(out, 2, 2) = r2[6];
    MAT(out, 2, 3) = r2[7];
    MAT(out, 3, 0) = r3[4];
    MAT(out, 3, 1) = r3[5];
    MAT(out, 3, 2) = r3[6];
    MAT(out, 3, 3) = r3[7];

    return 1;
}


/****************************************************************************/

void vGfViewport(float64_t f64X, float64_t f64Y, float64_t f64Width, float64_t f64Height)
{
    viewport[0] = f64X;
    viewport[1] = f64Y;
    viewport[2] = f64Width;
    viewport[3] = f64Height;
}


/****************************************************************************/

void vGfFrustum(float64_t f64Left, float64_t f64Right, float64_t f64Bottom, float64_t f64Top, float64_t f64zNear, float64_t f64zFar)
{
    float64_t* m;
    float64_t  f[16];

    m = f64GETMATRIX();

    f[0]  = (2.0*f64zNear)/(f64Right - f64Left);
    f[1]  = 0.0;
    f[2]  = 0.0;
    f[3]  = 0.0;
    f[4]  = 0.0;
    f[5]  = (2.0*f64zNear)/(f64Top - f64Bottom);
    f[6]  = 0.0;
    f[7]  = 0.0;
    f[8]  = (f64Right + f64Left)/(f64Right - f64Left);
    f[9]  = (f64Top + f64Bottom)/(f64Top - f64Bottom);
    f[10] = -(f64zFar + f64zNear)/(f64zFar - f64zNear);
    f[11] = -1.0;
    f[12] = 0.0;
    f[13] = 0.0;
    f[14] = (-2.0*f64zFar*f64zNear)/(f64zFar - f64zNear);
    f[15] = 0.0;

    vMMMUL4x4(m, m, f);
}


/****************************************************************************/

void vGfMatrixMode(gf_matrixmodes_e eMatrix)
{
    matrixmode = eMatrix;
}


/****************************************************************************/

void vGfLoadIdentity(void)
{
    float64_t* m;

    m = f64GETMATRIX();

    m[0]  = 1.0;
    m[1]  = 0.0;
    m[2]  = 0.0;
    m[3]  = 0.0;
    m[4]  = 0.0;
    m[5]  = 1.0;
    m[6]  = 0.0;
    m[7]  = 0.0;
    m[8]  = 0.0;
    m[9]  = 0.0;
    m[10] = 1.0;
    m[11] = 0.0;
    m[12] = 0.0;
    m[13] = 0.0;
    m[14] = 0.0;
    m[15] = 1.0;
}


/****************************************************************************/

void vGfLoadIP(void)
{
    float64_t* m;

    m = f64GETMATRIX();

    m[0]  = ip[0];
    m[1]  = ip[1];
    m[2]  = ip[2];
    m[3]  = ip[3];
    m[4]  = ip[4];
    m[5]  = ip[5];
    m[6]  = ip[6];
    m[7]  = ip[7];
    m[8]  = ip[8];
    m[9]  = ip[9];
    m[10] = ip[10];
    m[11] = ip[11];
    m[12] = ip[12];
    m[13] = ip[13];
    m[14] = ip[14];
    m[15] = ip[15];
}


/****************************************************************************/

void vGfTranslate(float64_t f64X, float64_t f64Y, float64_t f64Z)
{
    float64_t* m;
    float64_t  f[16];

    m = f64GETMATRIX();

    f[0]  = 1.0;
    f[1]  = 0.0;
    f[2]  = 0.0;
    f[3]  = 0.0;
    f[4]  = 0.0;
    f[5]  = 1.0;
    f[6]  = 0.0;
    f[7]  = 0.0;
    f[8]  = 0.0;
    f[9]  = 0.0;
    f[10] = 1.0;
    f[11] = 0.0;
    f[12] = f64X;
    f[13] = f64Y;
    f[14] = f64Z;
    f[15] = 1.0;

    vMMMUL4x4(m, m, f);
}


/****************************************************************************/

void vGfScale(float64_t f64X, float64_t f64Y, float64_t f64Z)
{
    float64_t* m;
    float64_t  f[16];

    m = f64GETMATRIX();

    f[0]  = f64X;
    f[1]  = 0.0;
    f[2]  = 0.0;
    f[3]  = 0.0;
    f[4]  = 0.0;
    f[5]  = f64Y;
    f[6]  = 0.0;
    f[7]  = 0.0;
    f[8]  = 0.0;
    f[9]  = 0.0;
    f[10] = f64Z;
    f[11] = 0.0;
    f[12] = 0.0;
    f[13] = 0.0;
    f[14] = 0.0;
    f[15] = 1.0;

    vMMMUL4x4(m, m, f);
}


/****************************************************************************/

void vGfRotate(float64_t f64Angle, float64_t f64X, float64_t f64Y, float64_t f64Z)
{
    float64_t* m;
    float64_t  f[16];
    float64_t  c;
    float64_t  s;
    float64_t  n;
    float64_t  x;
    float64_t  y;
    float64_t  z;

    m = f64GETMATRIX();

    /* normalize (x,y,z) vector */
    n = sqrt(f64X*f64X + f64Y*f64Y + f64Z*f64Z);
    x = f64X/n;
    y = f64Y/n;
    z = f64Z/n;

    c = cos(f64Angle*GA_CONST_PI/180.0);
    s = sin(f64Angle*GA_CONST_PI/180.0);

    f[0]  = x*x*(1.0-c) + c;
    f[1]  = y*x*(1.0-c) + z*s;
    f[2]  = x*z*(1.0-c) - y*s;
    f[3]  = 0;
    f[4]  = x*y*(1.0-c) - z*s;
    f[5]  = y*y*(1.0-c) + c;
    f[6]  = y*z*(1.0-c) + x*s;
    f[7]  = 0;
    f[8]  = x*z*(1.0-c) + y*s;
    f[9]  = y*z*(1.0-c) - x*s;
    f[10] = z*z*(1.0-c) + c;
    f[11] = 0;
    f[12] = 0;
    f[13] = 0;
    f[14] = 0;
    f[15] = 1;

    vMMMUL4x4(m, m, f);
}


/****************************************************************************/

static int iProject(float64_t * pf64Win, float64_t * pf64Obj)
{
    /* Transformation vectors */
    float64_t tmp[4];

    /* Modelview transform */
    vMVMUL4x4(tmp, modelview, pf64Obj);

    /* Projection transform */
    vMVMUL4x4(tmp, projection, tmp);

    /* The result normalizes between -1 and 1 */
    if(tmp[3] == 0.0) /* The w value */
    {
        return 0;
    }
    tmp[3] = 1.0/tmp[3];

    /* Perspective division */
    tmp[0]*= tmp[3];
    tmp[1]*= tmp[3];
    tmp[2]*= tmp[3];

    /* Window coordinates */
    /* Map x, y to range 0-1 */
    pf64Win[0] = (tmp[0]*0.5 + 0.5)*viewport[2] + viewport[0];
    pf64Win[1] = (/*-*/tmp[1]*0.5 + 0.5)*viewport[3] + viewport[1];

    /* This is only correct when glDepthRange(0.0, 1.0) */
    pf64Win[2] = (1.0 + tmp[2])*0.5;    /* Between 0 and 1 */

    return 1;
}


/****************************************************************************/

int iGfProject(float64_t * pf64Obj)
{
    if (0 == iProject(obj[0], pf64Obj))
    {
        return 0;
    }
    if (0 == iProject(obj[1], pf64Obj+4))
    {
        return 0;
    }
    if (0 == iProject(obj[2], pf64Obj+8))
    {
        return 0;
    }
    if (0 == iProject(obj[3], pf64Obj+12))
    {
        return 0;
    }

    return 1;
}

/****************************************************************************/

int iGfUnProject(float64_t * pf64Obj, float64_t * pf64Win)
{
    /* Transformation matrices */
    float64_t m[16], A[16];
    float64_t in[4], out[4];
    /* Calculation for inverting a matrix, compute projection x modelview */
    /* and store in A[16] */
    vMMMUL4x4(A, projection, modelview);
    /* Now compute the inverse of matrix A */
    if(iGfInvertMatrix4x4(A, m)==0)
    {
        return 0;
    }

    /* Transformation of normalized coordinates between -1 and 1 */
    in[0] = (pf64Win[0] - (float64_t)viewport[0])/(float64_t)viewport[2]*2.0 - 1.0;
    in[1] = (pf64Win[1] - (float64_t)viewport[1])/(float64_t)viewport[3]*2.0 - 1.0;
    in[2] = 2.0*pf64Win[2]-1.0;
    in[3] = 1.0;
    /* Objects coordinates */
    vMVMUL4x4(out, m, in);

    if(out[3]==0.0)
    {
        return 0;
    }

    out[3] = 1.0/out[3];

    pf64Obj[0] = out[0]*out[3];
    pf64Obj[1] = /*-*/out[1]*out[3];
    pf64Obj[2] = out[2]*out[3];

    return 1;
}


/****************************************************************************/

void vGfSetIP(float64_t f64ImgWidth, float64_t f64ImgHeight, float64_t f64Znear, float64_t f64Zfar)
{
    float64_t obj_local[4];
    float64_t img[4];

    vGfMatrixMode(GA_RE_IP);
    vGfLoadIdentity();
    vGfTranslate(0, 0, -(f64Zfar - f64Znear)/2);

    img[0] = f64ImgWidth/f64ImgHeight;
    img[1] = 1;
    img[2] = 0;
    img[3] = 1;

    vGfMatrixMode(GA_RE_MODELVIEW);
    vGfLoadIP();
    iProject(obj_local, img);

    obj_local[0] = (obj_local[0] - viewport[0]) - (viewport[2]/2);
    obj_local[1] = (obj_local[1] - viewport[1]) - (viewport[3]/2);

    vGfMatrixMode(GA_RE_IP);
    vGfScale(f64ImgWidth/obj_local[0], f64ImgHeight/obj_local[1], 1);
}


/****************************************************************************/

void vGfBuffBlitElement(gf_image_st * pstSrcImage, gf_image_st * pstDstImage)
{
    rot_mem_st stMem;
    rot_perspectiveCfg_st stParam;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr   = pstSrcImage->u32Address;
    stMem.u16SrcHeight = pstSrcImage->u16Height;
    stMem.u16SrcWidth  = pstSrcImage->u16Width;
    stMem.u32DstAddr   = pstDstImage->u32Address;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.eDstColFmt = GA_RGBA32;
    }

    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.eSrcColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.eClipWndEn == GA_EN)
    {
        stParam.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.eFilterEn     = stGastate.eFilterEn;

    stParam.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    vRotLib_PerspectiveOGL(&stMem, &stParam, pstWriteList);
}


/****************************************************************************/

void vGfBuffBlendElement(gf_image_st * pstSrcImage, gf_image_st * pstDstImage)
{
    rot_mem_st stMem;
    rot_perspectiveblendCfg_st stParam;

    u8PreviousOperation = 0U;

    stMem.u32SrcAddr   = pstSrcImage->u32Address;
    stMem.u16SrcHeight = pstSrcImage->u16Height;
    stMem.u16SrcWidth  = pstSrcImage->u16Width;
    stMem.u32DstAddr   = pstDstImage->u32Address;

    if(pstDstImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eDstColFmt = GA_RGB16;
    }
    else
    {
        stParam.eDstColFmt = GA_RGBA32;
    }

    stMem.u16DstImgWidth  = pstDstImage->u16Width;
    stMem.u16DstImgHeight = pstDstImage->u16Height;

    if(pstSrcImage->eFormat == (uint8_t)FMT_RGB16)
    {
        stParam.eSrcColFmt = GA_RGB16;
    }
    else
    {
        stParam.eSrcColFmt = GA_RGBA32;
    }

    /* handle clip window */
    stParam.eClipWndEn = stGastate.eClipWndEn;
    if (stParam.eClipWndEn == GA_EN)
    {
        stParam.tClipWnd.u16UlX = stGastate.u16ClipC1_X;
        stParam.tClipWnd.u16UlY = stGastate.u16ClipC1_Y;
        stParam.tClipWnd.u16LrX = stGastate.u16ClipC2_X;
        stParam.tClipWnd.u16LrY = stGastate.u16ClipC2_Y;
    }

    stParam.eFilterEn     = stGastate.eFilterEn;

    stParam.eBldOrd       = stGastate.eBlndOrder;
    stParam.u8FadingFctr  = stGastate.u8FadingFctr;
    stParam.u8SrcAlphaVal = stGastate.u8SrcAlphaVal;
    stParam.u8DstAlphaVal = stGastate.u8DstAlphaVal;

    stParam.eDstRedProt   = stGastate.eRedChPrtEn;
    stParam.eDstGreenProt = stGastate.eGreenChPrtEn;
    stParam.eDstBlueProt  = stGastate.eBlueChPrtEn;
    stParam.eDstAlphaProt = stGastate.eAlphaChPrtEn;
    stParam.eSrcRedFad    = stGastate.eSrcRedFad;
    stParam.eSrcGreenFad  = stGastate.eSrcGreenFad;
    stParam.eSrcBlueFad   = stGastate.eSrcBlueFad;
    stParam.eSrcAlphaFad  = stGastate.eSrcAlphaFad;

    vRotLib_PerspectiveBlendOGL(&stMem, &stParam, pstWriteList);
}

/*****************************************************************************
 *
 *                      LAYER-BASED (WRAPPER) FUNCTIONS
 *
 *****************************************************************************/

 /****************************************************************************/

void vGfLayerFillArea(gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                      uint32_t u32Color)
{
    vGfBuffFillArea(&(pstLayer->stWriteFB), pstImgPart, u32Color);
}


/****************************************************************************/

uint32_t u32GfLayerBlitBitmapFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                                  int32_t i32PosX, int32_t i32PosY)
{
    return u32GfBuffBlitBitmapFull(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlitBitmapFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                            int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlitBitmapFull(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlitBitmapPart(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                            uint32_t u32PosX, uint32_t u32PosY)
{
    vGfBuffBlitBitmapPart(pstImage, &(pstLayer->stWriteFB), pstImgPart, u32PosX, u32PosY);
}


/****************************************************************************/

uint32_t u32GfLayerBlitBitmapPart(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                                  uint32_t u32PosX, uint32_t u32PosY)
{
    return u32GfBuffBlitBitmapPart(pstImage, &(pstLayer->stWriteFB), pstImgPart, u32PosX, u32PosY);
}


/****************************************************************************/

void vGfLayerBlitBitmapRLE16(gf_image_st * pstImage, gf_layer_st * pstLayer,
                             int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlitBitmapRLE16(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlitBitmapRLE24(gf_image_st * pstImage, gf_layer_st * pstLayer,
                             int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlitBitmapRLE24(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlitBitmapRLE24A(gf_image_st * pstImage, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlitBitmapRLE24A(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlitBitmapRLE32(gf_image_st * pstImage, gf_layer_st * pstLayer,
                             int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlitBitmapRLE32(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlendFillArea(gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart, uint32_t u32Color)
{
    vGfBuffBlendFillArea(&(pstLayer->stWriteFB), pstImgPart, u32Color);
}


/****************************************************************************/

uint32_t u32GfLayerBlendBitmapFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                                   int32_t i32PosX, int32_t i32PosY)
{
    return u32GfBuffBlendBitmapFull(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlendBitmapFull(gf_image_st * pstImage, gf_layer_st * pstLayer,
                             int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlendBitmapFull(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

uint32_t u32GfLayerBlendBitmapPart(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                                   uint32_t u32PosX, uint32_t u32PosY)
{
    return u32GfBuffBlendBitmapPart(pstImage, &(pstLayer->stWriteFB), pstImgPart, u32PosX, u32PosY);
}


/****************************************************************************/

void vGfLayerBlendBitmapPart(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                             uint32_t u32PosX, uint32_t u32PosY)
{
    vGfBuffBlendBitmapPart(pstImage, &(pstLayer->stWriteFB), pstImgPart, u32PosX, u32PosY);
}


/****************************************************************************/

void vGfLayerBlendBitmapRLE16(gf_image_st * pstImage, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlendBitmapRLE16(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlendBitmapRLE24(gf_image_st * pstImage, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlendBitmapRLE24(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlendBitmapRLE24A(gf_image_st * pstImage, gf_layer_st * pstLayer,
                               int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlendBitmapRLE24A(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerBlendBitmapRLE32(gf_image_st * pstImage, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffBlendBitmapRLE32(pstImage, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerRotateBitmapFull(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer,
                              int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffRotateBitmapFull(pstImage, f32Angle, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerRotateBitmapPart(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                              int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffRotateBitmapPart(pstImage, f32Angle, &(pstLayer->stWriteFB), pstImgPart, i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerRotateBitmapOptimized(gf_image_st * pstSrcImage, float32_t f32Angle, gf_layer_st * pstLayer,
                                   uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockWidth, uint32_t u32BlockHeight)
{
    vGfBuffRotateBitmapOptimized(pstSrcImage, f32Angle, &(pstLayer->stWriteFB), u32PosX, u32PosY, u32BlockWidth, u32BlockHeight);
}


/****************************************************************************/

void vGfLayerRotateBlendBitmapFull(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer,
                                   int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffRotateBlendBitmapFull(pstImage, f32Angle, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerRotateBlendBitmapPart(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer, gf_cliprect_st * pstImgPart,
                                   int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffRotateBlendBitmapPart(pstImage, f32Angle, &(pstLayer->stWriteFB), pstImgPart, i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerRotateNeedleFill(gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer,
                              uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockHeight)
{
    vGfBuffRotateNeedleFill(pstImage, f32Angle, &(pstLayer->stWriteFB), u32PosX, u32PosY, u32BlockHeight);
}


/****************************************************************************/

void vGfLayerRotateNeedle(gf_image_st * pstImageBg, gf_image_st * pstImage, float32_t f32Angle, gf_layer_st * pstLayer,
                          uint32_t u32PosX, uint32_t u32PosY, uint32_t u32BlockHeight)
{
    vGfBuffRotateNeedle(pstImageBg, pstImage, f32Angle, &(pstLayer->stWriteFB), u32PosX, u32PosY, u32BlockHeight);
}

 
/****************************************************************************/

void vGfLayerRotateNeedleTipandBaseFill(gf_image_st * pstSrcImage, float32_t f32Angle, gf_layer_st * pstLayer,
                                        uint32_t u32PosX, uint32_t u32PosY, gf_def_st * pstDef)
{
    vGfBuffRotateNeedleTipandBaseFill(pstSrcImage, f32Angle, &(pstLayer->stWriteFB), u32PosX, u32PosY, pstDef);
}


/****************************************************************************/

void vGfLayerRotateNeedleTipandBase(gf_image_st * pstSrcImageBg, gf_image_st * pstSrcImage, float32_t f32Angle, gf_layer_st * pstLayer,
                                    uint32_t u32PosX, uint32_t u32PosY, gf_def_st * pstDef)
{
    vGfBuffRotateNeedleTipandBase(pstSrcImageBg, pstSrcImage, f32Angle, &(pstLayer->stWriteFB), u32PosX, u32PosY, pstDef);
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vGfLayerShearFull(gf_image_st * pstImage, float32_t f32FactorX, float32_t f32FactorY, gf_layer_st * pstLayer,
                       int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffShearFull(pstImage, f32FactorX, f32FactorY, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerShearBlendFull(gf_image_st * pstImage, float32_t f32FactorX, float32_t f32FactorY, gf_layer_st * pstLayer,
                            int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffShearBlendFull(pstImage, f32FactorX, f32FactorY, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}
#endif /* GA_USE_MATH_LIB */


/****************************************************************************/

void vGfLayerScaleFull(gf_image_st * pstImage, float32_t f32FactorX, float32_t f32FactorY,
                       rot_scaleAlign_e eAlignment, gf_layer_st * pstLayer,
                       int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffScaleFull(pstImage, f32FactorX, f32FactorY, eAlignment, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

void vGfLayerScaleBlendFull(gf_image_st * pstImage, float32_t f32FactorX, float32_t f32FactorY,
                            rot_scaleAlign_e eAlignment, gf_layer_st * pstLayer,
                            int32_t i32PosX, int32_t i32PosY)
{
    vGfBuffScaleBlendFull(pstImage, f32FactorX, f32FactorY, eAlignment, &(pstLayer->stWriteFB), i32PosX, i32PosY);
}


/****************************************************************************/

#ifdef GA_USE_MATH_LIB
void vGfLayerPerspectiveBlitFull(gf_image_st * pstImage, float32_t f32AngleX, float32_t f32AngleY, float32_t f32AngleZ,
                                 float32_t f32FactorX, float32_t f32FactorY, gf_layer_st * pstLayer,
                                 int32_t i32PosX, int32_t i32PosY,
                                 uint32_t u32RotPointX, uint32_t u32RotPointY)
{
    vGfBuffPerspectiveBlitFull(pstImage, f32AngleX, f32AngleY, f32AngleZ, f32FactorX, f32FactorY, &(pstLayer->stWriteFB), i32PosX, i32PosY, u32RotPointX, u32RotPointY);
}


/****************************************************************************/

void vGfLayerPerspectiveBlendFull(gf_image_st * pstImage, float32_t f32AngleX, float32_t f32AngleY, float32_t f32AngleZ,
                                  float32_t f32FactorX, float32_t f32FactorY, gf_layer_st * pstLayer,
                                  int32_t i32PosX, int32_t i32PosY,
                                  uint32_t u32RotPointX, uint32_t u32RotPointY)
{
    vGfBuffPerspectiveBlendFull(pstImage, f32AngleX, f32AngleY, f32AngleZ, f32FactorX, f32FactorY, &(pstLayer->stWriteFB), i32PosX, i32PosY, u32RotPointX, u32RotPointY);
}
#endif


/****************************************************************************/

void vGfLayerTransformationFull(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_table_st * pstTable, uint32_t u32PosX, uint32_t u32PosY)
{
    vGfBuffTransformationFull(pstImage, &(pstLayer->stWriteFB), pstTable, u32PosX, u32PosY);
}


/****************************************************************************/

void vGfLayerTransformationFullOptimized(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_table_st * pstTable, uint32_t u32PosX, uint32_t u32PosY,
                                         uint32_t u32BlockWidth, uint32_t u32BlockHeight)
{
    vGfBuffTransformationFullOptimized(pstImage, &(pstLayer->stWriteFB), pstTable, u32PosX, u32PosY, u32BlockWidth, u32BlockHeight);
}


/****************************************************************************/

void vGfLayerTransformationBlendFull(gf_image_st * pstImage, gf_layer_st * pstLayer, gf_table_st * pstTable,
                                     uint32_t u32PosX, uint32_t u32PosY)
{
    vGfBuffTransformationBlendFull(pstImage, &(pstLayer->stWriteFB), pstTable, u32PosX, u32PosY);
}


/****************************************************************************/

void vGfLayerDrawLine(gf_layer_st * pstLayer, drw_OpCfg_st *pstOption, drw_Line_st *pstLine)
{
    vGfBuffDrawLine(&(pstLayer->stWriteFB), pstOption, pstLine);
}


/****************************************************************************/

void vGfLayerDrawTriangle(gf_layer_st * pstLayer, drw_OpCfg_st *pstOption, drw_Trngl_st *pstTrngl)
{
    vGfBuffDrawTriangle(&(pstLayer->stWriteFB), pstOption, pstTrngl);
}


/****************************************************************************/

void vGfLayerDrawCircle(gf_layer_st *pstLayer, drw_OpCfg_st *pstOption, gf_circle_st *pstCircle)
{
    vGfBuffDrawCircle(&(pstLayer->stWriteFB), pstOption, pstCircle);
}


/*******************************************************************************/

void vGfLayerDrawPolygon(gf_layer_st *pstLayer, drw_OpCfg_st *pstOption, gf_polygon_st *pstPolygon)
{
    vGfBuffDrawPolygon(&(pstLayer->stWriteFB), pstOption, pstPolygon);
}


/****************************************************************************/

void vGfLayerBlitElement(gf_image_st * pstSrcImage, gf_layer_st * pstLayer)
{
    vGfBuffBlitElement(pstSrcImage, &(pstLayer->stWriteFB));
}


/****************************************************************************/

void vGfLayerBlendElement(gf_image_st * pstSrcImage, gf_layer_st * pstLayer)
{
    vGfBuffBlendElement(pstSrcImage, &(pstLayer->stWriteFB));
}


#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

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
  conditions set forth in the Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer's own risk.

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

