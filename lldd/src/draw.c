/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronic Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : Low-Level Driver for draw engine
* 
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : GA (Drawing Engine)
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.15 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
****************************************************************************/

/**********************************************
*            Include Files                    *
**********************************************/
#include "ga_io.h"
#include "ga.h"
#include "draw.h"

/*********************************************/
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1858  /* Rule 17.4 [R] : subscript operator may only be applied to objects declared as an array type */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to narrower underlying type, "type", not allowed */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : conversion from underlying type, "int", to same width underlying type, "uint32_t", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1878  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to wider type "type" not allowed */
  #pragma ghs nowarning 1879  /* Rule 10.3 [R] : Restrict explicit casts for integer type expressions */

  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1855  /* Rule 13.2 [A] : Explicit test of a value against zero unless the expression is Boolean */
  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */
  #pragma ghs nowarning 1737  /* Rule 12.1 [A] : expression may not depend on operator precedence rules */

#endif
/**********************************************
*    Stat. Var and Func. Prototypes           *
**********************************************/

/*********************************************/

/**********************************************
*    Glob. Var and Func. Prototypes           *
**********************************************/

/*********************************************/

/**********************************************
*                Macros                       *
**********************************************/
#define LLDD_GA_DRAW_C_REVISION     "$Revision: 1.15 $"
#define LLDD_GA_DRAW_C_TAG          "$Name: LLDD_1_7_GFX $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8LLDD_GA_DRAW_C_REVISION[] = LLDD_GA_DRAW_C_REVISION;
static uint8_t au8LLDD_GA_DRAW_C_TAG[]      = LLDD_GA_DRAW_C_TAG;
static uint8_t au8LLDD_GA_DRAW_H_REVISION[] = LLDD_GA_DRAW_H_REVISION;
static uint8_t au8LLDD_GA_DRAW_H_TAG[]      = LLDD_GA_DRAW_H_TAG;

/*********************************************/

/**********************************************
*          Functions                          *
**********************************************/
void vDrw_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
    *pau8ModuleRevision = &au8LLDD_GA_DRAW_C_REVISION[0];
    *pau8ModuleTag      = &au8LLDD_GA_DRAW_C_TAG[0];
    *pau8HeaderRevision = &au8LLDD_GA_DRAW_H_REVISION[0];
    *pau8HeaderTag      = &au8LLDD_GA_DRAW_H_TAG[0];
}

/* ....................................................................... */
void vDrw_SetMemDest(const void* pvAddr, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;
    
#ifdef  GA_CMDSLIST_BOUNDARY_CHECK
    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif
    
    pu64Curr[0] = DRW_LOAD_DESTADDR((uint64_t) pvAddr);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetMemDim(uint16_t u16Width, uint16_t u16Height, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;
    
#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif
    
    pu64Curr[0] = DRW_LOAD_DESTDIM(u16Width, u16Height);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetColorRGB16(uint16_t u16Color, uint8_t u8Alpha, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_RGB16(u16Color,u8Alpha);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetColorRGBA32(uint32_t u32Color, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_RGBA32(u32Color);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetBgColorRGBA32(uint32_t u32Color, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_RGBA32BGRND(u32Color);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetBgColorRGB16(uint16_t u16Color, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_RGB16BGRND(u16Color);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetLineStart(uint16_t u16X, uint16_t u16Y, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_LINESTART( u16X, u16Y);
    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetLineEnd(uint16_t u16X, uint16_t u16Y, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_LINEEND( u16X, u16Y);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */

void vDrw_SetLineThickness(uint16_t u16Val, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_THICKNESS(u16Val);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetTriangle1(uint16_t u16X, uint16_t u16Y, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_TRNGLE1(u16X, u16Y);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetTriangle2(uint16_t u16X, uint16_t u16Y, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_TRNGLE2(u16X, u16Y);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetTriangle3(uint16_t u16X, uint16_t u16Y, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_TRNGLE3(u16X, u16Y);

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetClippWnd(drw_clipWnd_st* pstClipWnd, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 2;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pu64Curr[0] = DRW_LOAD_CLIPWNDSTART(pstClipWnd->u16UlX, pstClipWnd->u16UlY);
    pu64Curr[1] = DRW_LOAD_CLIPWNDEND(pstClipWnd->u16LrX, pstClipWnd->u16LrY);

    pstCmdList->pu64Current = &pu64Curr[2];
}

/* ....................................................................... */
void vDrw_SetLineCmd(drw_LnOpCfg_st* pstParam, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    if(pstParam->eColFmt == GA_RGB16)
    {
        pu64Curr[0] = DRW_LINERGB16(pstParam->eStartCap,
                                    pstParam->eEndCap,
                                    pstParam->eBlndMode,
                                    pstParam->eClipWndEn);
    }
    else
    {
        pu64Curr[0] = DRW_LINERGBA32(pstParam->eStartCap,
                                     pstParam->eEndCap,
                                     pstParam->eBlndMode,
                                     pstParam->eClipWndEn);
        
    }
    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_SetTriangleCmd(drw_TriOpCfg_st* pstParam, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    if(pstParam->eColFmt == GA_RGB16)
    {
        pu64Curr[0] = DRW_TRIANGLE_RGB16(pstParam->eAntialEn3,
                                         pstParam->eAntialEn2,
                                         pstParam->eAntialEn1,
                                         pstParam->eBlndMode,
                                         pstParam->eClipWndEn);
    }
    else
    {
        pu64Curr[0] = DRW_TRIANGLE_RGBA32(pstParam->eAntialEn3,
                                          pstParam->eAntialEn2,
                                          pstParam->eAntialEn1,
                                          pstParam->eBlndMode,
                                          pstParam->eClipWndEn);
    }

    pstCmdList->pu64Current = &pu64Curr[1];
}

/* ....................................................................... */
void vDrw_DrawLine(drw_mem_st* pstMem, drw_OpCfg_st *pstOption,
                   drw_Line_st *pstLine, ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 5;
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 6;
    if(pstOption->eClipWndEn == GA_EN)
    {
        u32NeededDW = u32NeededDW + 2;
    }
    if(pstOption->eBlndMode == DRW_OVERWRITING)
    {
        u32NeededDW++;
    }
    u32NeededDW = u32NeededDW + RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    /* Destination Memory */
    pu64Curr[0] = DRW_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[1] = DRW_LOAD_DESTDIM(pstMem->u16DstImgWidth, pstMem->u16DstImgHeight);

    /* Line Parameters */
    pu64Curr[2] = DRW_LOAD_LINESTART(pstLine->stPtStart.u16X, pstLine->stPtStart.u16Y);
    pu64Curr[3] = DRW_LOAD_LINEEND(pstLine->stPtEnd.u16X, pstLine->stPtEnd.u16Y);
    pu64Curr[4] = DRW_LOAD_THICKNESS(pstLine->u16Thickness);

    /* Clipping Window */
    if(pstOption->eClipWndEn == GA_EN)
    {
        pu64Curr[u8Curr] = DRW_LOAD_CLIPWNDSTART(pstOption->stClipWnd.u16UlX,
                                                 pstOption->stClipWnd.u16UlY);
        u8Curr++;
        pu64Curr[u8Curr] = DRW_LOAD_CLIPWNDEND(pstOption->stClipWnd.u16LrX,
                                               pstOption->stClipWnd.u16LrY);
        u8Curr++;
    }

    if(pstLine->stColor.eColFmt == GA_RGB16)
    {
        /* Background Color */
        if(pstOption->eBlndMode == DRW_OVERWRITING)
        {
            pu64Curr[u8Curr] = DRW_LOAD_RGB16BGRND(pstOption->u32BgColor);
            u8Curr++;
        }

        /* Line Color */
        pu64Curr[u8Curr] = DRW_LOAD_RGB16((uint16_t)(pstLine->stColor.u32Color),
                                           pstLine->stColor.u8Alpha);
        u8Curr++;

        /* Line Draw Command */
        pu64Curr[u8Curr] = DRW_LINERGB16(pstLine->eStartCap,
                                         pstLine->eEndCap,
                                         pstOption->eBlndMode,
                                         pstOption->eClipWndEn);
        u8Curr++;
    }
    else
    {
        if(pstOption->eBlndMode == DRW_OVERWRITING)
        {
            pu64Curr[u8Curr] = DRW_LOAD_RGBA32BGRND(pstOption->u32BgColor);
            u8Curr++;
        }

        pu64Curr[u8Curr] = DRW_LOAD_RGBA32(pstLine->stColor.u32Color);
        u8Curr++;

        pu64Curr[u8Curr] = DRW_LINERGBA32(pstLine->eStartCap,
                                          pstLine->eEndCap,
                                          pstOption->eBlndMode,
                                          pstOption->eClipWndEn);
        u8Curr++;
    }

    pstCmdList->pu64Current = &pu64Curr[u8Curr];
}

/* ....................................................................... */
void vDrw_DrawTriangle(drw_mem_st* pstMem, drw_OpCfg_st *pstOption,
                       drw_Trngl_st *pstTrngl, ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 5;
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 6;
   
    if(pstOption->eClipWndEn == GA_EN)
    {
        u32NeededDW = u32NeededDW + 2;
    }
    if(pstOption->eBlndMode == DRW_OVERWRITING)
    {
        u32NeededDW++;
    }
    u32NeededDW = u32NeededDW + RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */
    
    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    /* Destination Memory */
    pu64Curr[0] = DRW_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[1] = DRW_LOAD_DESTDIM(pstMem->u16DstImgWidth, pstMem->u16DstImgHeight);

    /* Triangle Points */
    pu64Curr[2] = DRW_LOAD_TRNGLE1(pstTrngl->stPt1.u16X, pstTrngl->stPt1.u16Y);
    pu64Curr[3] = DRW_LOAD_TRNGLE2(pstTrngl->stPt2.u16X, pstTrngl->stPt2.u16Y);
    pu64Curr[4] = DRW_LOAD_TRNGLE3(pstTrngl->stPt3.u16X, pstTrngl->stPt3.u16Y);
    /* Clipping Window */
    if(pstOption->eClipWndEn == GA_EN)
    {
        pu64Curr[u8Curr] = DRW_LOAD_CLIPWNDSTART(pstOption->stClipWnd.u16UlX,
                                                 pstOption->stClipWnd.u16UlY);
        u8Curr++;
        pu64Curr[u8Curr] = DRW_LOAD_CLIPWNDEND(pstOption->stClipWnd.u16LrX,
                                               pstOption->stClipWnd.u16LrY);
        u8Curr++;
    }

    if(pstTrngl->stColor.eColFmt == GA_RGB16)
    {
        /* Background Color */
        if(pstOption->eBlndMode == DRW_OVERWRITING)
        {
            pu64Curr[u8Curr] = DRW_LOAD_RGB16BGRND(pstOption->u32BgColor);
            u8Curr++;
        }

        /* Line Color */
        pu64Curr[u8Curr] = DRW_LOAD_RGB16((uint16_t)(pstTrngl->stColor.u32Color),
                                          pstTrngl->stColor.u8Alpha);
        u8Curr++;

        /* Triangle Draw Command */
        pu64Curr[u8Curr] = DRW_TRIANGLE_RGB16(pstTrngl->eAntialEn3,
                                              pstTrngl->eAntialEn2,
                                              pstTrngl->eAntialEn1,
                                              pstOption->eBlndMode,
                                              pstOption->eClipWndEn);
        u8Curr++;
    }
    else
    {
        /* Background Color */
        if(pstOption->eBlndMode == DRW_OVERWRITING)
        {
            pu64Curr[u8Curr] = DRW_LOAD_RGBA32BGRND(pstOption->u32BgColor);
            u8Curr++;
        }

        /* Line Color */
        pu64Curr[u8Curr] = DRW_LOAD_RGBA32(pstTrngl->stColor.u32Color);
        u8Curr++;

        /* Triangle Draw Command */
        pu64Curr[u8Curr] = DRW_TRIANGLE_RGBA32(pstTrngl->eAntialEn3,
                                               pstTrngl->eAntialEn2,
                                               pstTrngl->eAntialEn1,
                                               pstOption->eBlndMode,
                                               pstOption->eClipWndEn);
        u8Curr++;
    }

    pstCmdList->pu64Current = &pu64Curr[u8Curr];
}

/* ....................................................................... */
bool_t boDrw_SetFilterCoefDrawEngine (uint8_t u8CoefIndex,  
                                      uint32_t u32CoefValue)
{
    bool_t    boRes = C_TRUE;
    
    /* check parameters: */
    if (u8CoefIndex > LAST_FILTER_COEF_INDEX)
    {
        boRes = C_FALSE;
    }
    else
    {
        vSetGADEFCR(u8CoefIndex, u32CoefValue);
    }
    return (boRes);
}
/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/

/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: draw.c
**  $Revision: 1.15 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**
**  ------------------------------------------------------------------------
** |
** | RULE   : 1847 / 10.3 - cast of complex integer expression with underlying type
** |                        "type" to non-integer type "type" not allowed 
** | CONS.  : disable
** | REASON : to use macros from i/o header files, unavoidable when addressing 
** |          memory mapped registers 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1858 /17.4  - subscript operator may only be applied to objects 
** |                        declared as an array type
** | CONS.  : allow
** | REASON : to handle array of data by usage of pointer 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1864 /10.1  - implicit conversion from underlying type, "type", 
** |                        to narrower underlying type, "type", not allowed
** | CONS.  : allow
** | REASON : to use macros from i/o header files 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1865 /10.1  -  implicit conversion from underlying type, "type", 
** |                         to same width underlying type, "type", not allowed
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1866 /10.1  -  implicit conversion from underlying type, "type",  
** |                         to underlying type, "type", changes signedness
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1867 /10.1  -  implicit conversion from underlying type, "type", 
** |                         to underlying type, "type", changes signedness
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1878 /10.3  -   cast of complex integer expression with underlying 
** |                          type "type" to wider type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as variables in io 
** |          header file or to allow shift operation
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1879 /10.3  - 	 cast of complex integer expression with underlying
** |                           type "type" to same width type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as macros in io header file
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/


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
  conditions set forth in the “Handling Guide for Semiconductor Devices,” or
  “TOSHIBA Semiconductor Reliability Handbook” etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (“Unintended Usage”).
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

****************************  END of DISCALIMER ****************************/

