/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Graphic Accelerator
*                 Reference Low-Level Driver (Blitting Engine)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphic Accelerator Blitting Engine
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.14 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
/*======================================
            Include Files
=======================================*/
#include "ga.h"
#include "blit.h"

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/

#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1858  /* Rule 17.4 [R] : subscript operator may only be applied to objects declared as an array type */
  #pragma ghs nowarning 1879  /* Rule 10.3 [R] : Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1878  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to wider type "type" not allowed */

  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */

#endif
/*======================================
    Stat. Var and Func. Prototypes
=======================================*/


/*======================================
    Glob. Var and Func. Prototypes
=======================================*/

/*======================================
                Macros
=======================================*/

#define LLDD_GA_BLIT_C_REVISION     "$Revision: 1.14 $"
#define LLDD_GA_BLIT_C_TAG          "$Name: LLDD_1_7_GFX $"

/*======================================
 Static variables and forward declarations
=======================================*/

static uint8_t au8LLDD_GA_BLIT_C_REVISION[] = LLDD_GA_BLIT_C_REVISION;
static uint8_t au8LLDD_GA_BLIT_C_TAG[]      = LLDD_GA_BLIT_C_TAG;
static uint8_t au8LLDD_GA_BLIT_H_REVISION[] = LLDD_GA_BLIT_H_REVISION;
static uint8_t au8LLDD_GA_BLIT_H_TAG[]      = LLDD_GA_BLIT_H_TAG;


/*======================================
          Function definitions
=======================================*/

void vBlit_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
     *pau8ModuleRevision = &au8LLDD_GA_BLIT_C_REVISION[0];
     *pau8ModuleTag      = &au8LLDD_GA_BLIT_C_TAG[0];
     *pau8HeaderRevision = &au8LLDD_GA_BLIT_H_REVISION[0];
     *pau8HeaderTag      = &au8LLDD_GA_BLIT_H_TAG[0];
}
/* ....................................................................... */
void vBlit_SetClippWnd(uint32_t u32ClipAddr, uint16_t u16Width,
                       uint16_t u16Height, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;
#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 3U;
   
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

    pu64Curr[0] = BLT_LOAD_CLIP_STARTADDR(u32ClipAddr);
    pu64Curr[1] = BLT_LOAD_CLIP_WIDTH(u16Width);
    pu64Curr[2] = BLT_LOAD_CLIP_HEIGHT(u16Height);

    pstCmdList->pu64Current = &pu64Curr[3];

    pstCmdList->u32UsedDoubleWords = 3U;
}

/* ....................................................................... */
void vBlit_OverwriteRGB(blit_mem_st* pstMem, blit_OvrRgb_st* pstParam, ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 6U;
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW;
    
    u32NeededDW = u8Curr + 2U; /* 2 for Src/Dst Alpha */
    if(pstParam->eFadeMode != BLT_NOFADING)
    {
        u32NeededDW++;  /* for fade factor */
    }
    if(pstParam->eSrcFmt == GA_RGB16 && pstParam->eTranspColEn == GA_EN)
    {
        u32NeededDW+=2; /* for Src/Dst Transparency */
    }
    u32NeededDW++; /* for command itself */
    
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

    /* Source Memory Params */
    pu64Curr[0] = BLT_LOAD_SOURCEADDR(pstMem->u32SrcAddr);
    pu64Curr[1] = BLT_LOAD_SRCWIDTH(pstMem->u16SrcWidth);

    /* Destination Memory Params */
    pu64Curr[2] = BLT_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[3] = BLT_LOAD_DESTWIDTH(pstMem->u16DstWidth);

    /* Blitting Area Size */
    pu64Curr[4] = BLT_LOAD_DESTDOTCNT(pstMem->u16DotCnt);
    pu64Curr[5] = BLT_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /*** Operation Specific Params ***/

    /* Fading Factor Setup */
    if(pstParam->eFadeMode != BLT_NOFADING)
    {
        pu64Curr[u8Curr] = BLT_LOAD_FADEFACT(pstParam->u8FadingFctr);
        u8Curr++;
    }

   /* Source Alpha Blending Value */
   pu64Curr[u8Curr] = BLT_LOAD_SRCALPHA(pstParam->u8SrcAlphaVal);
   u8Curr++;

   /* Destination Alpha Blending Value */
   pu64Curr[u8Curr] = BLT_LOAD_DESTALPHA(pstParam->u8DstAlphaVal);
   u8Curr++;

    /* Source Type Selection */
    if(pstParam->eSrcFmt == GA_RGB16)
    {
        /** 16-bit RGB Source **/

        /* Transparency Color Option */
        if(pstParam->eTranspColEn == GA_EN)
        {
            pu64Curr[u8Curr] = BLT_LOAD_SRCTRANSPATT(pstParam->u32SrcTransVal);
            u8Curr++;
            pu64Curr[u8Curr] = BLT_LOAD_DESTTRANSPATT(pstParam->u16DstTransVal);
            u8Curr++;

        }

        /* Overwrite 16-bit RGB */
        pu64Curr[u8Curr] = BLT_ORGB16(pstParam->eDestFmt,
                                      pstParam->eTranspColEn,
                                      pstParam->eFadeMode,
                                      pstParam->eClipWndEn);
    }
    else
    {
        /** 32-bit RGBA Source **/
        pu64Curr[u8Curr] = BLT_ORGBA32(pstParam->eDestFmt,
                                       pstParam->eFadeMode,
                                       pstParam->eClipWndEn);
    }

    u8Curr++;    

    /* Update List Pointer */
    pstCmdList->pu64Current = &pu64Curr[u8Curr];

    pstCmdList->u32UsedDoubleWords = u8Curr;

}    

/* ....................................................................... */
void vBlit_OverwriteRLEI_RGB(blit_mem_st* pstMem, blit_OvrRlei_st* pstParam,
                             ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 6U;
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr + 2; /* 2 for Src/Dst Alpha */
    if(pstParam->eFadeMode != BLT_NOFADING)
    {
        u32NeededDW++;  /* for fade factor */
    }
    if(pstParam->eTranspColEn == GA_EN)
    {
        u32NeededDW+=2; /* for Src/Dst Transparency */
    }
    u32NeededDW++; /* for command itself */

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

    /* Source Memory Params */
    pu64Curr[0] = BLT_LOAD_SOURCEADDR(pstMem->u32SrcAddr);
    pu64Curr[1] = BLT_LOAD_SRCWIDTH(pstMem->u16SrcWidth);

    /* Destination Memory Params */
    pu64Curr[2] = BLT_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[3] = BLT_LOAD_DESTWIDTH(pstMem->u16DstWidth);

    /* Blitting Area Size */
    pu64Curr[4] = BLT_LOAD_DESTDOTCNT(pstMem->u16DotCnt);
    pu64Curr[5] = BLT_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /* Source Alpha Blending Value */
    pu64Curr[u8Curr] = BLT_LOAD_SRCALPHA(pstParam->u8SrcAlphaVal);
    u8Curr++;

    /* Destination Alpha Blending Value */
    pu64Curr[u8Curr] = BLT_LOAD_DESTALPHA(pstParam->u8DstAlphaVal);
    u8Curr++;

    /*** Operation Specific Params ***/

    if(pstParam->eTranspColEn == GA_EN)
    {
        /* Transparency Color Option */
        pu64Curr[u8Curr] = BLT_LOAD_SRCTRANSPATT(pstParam->u32SrcTransVal);
        u8Curr++;
        pu64Curr[u8Curr] = BLT_LOAD_DESTTRANSPATT(pstParam->u16DstTransVal);
        u8Curr++;
    }

    /* Fading Factor Setup */
    if(pstParam->eFadeMode != BLT_NOFADING)
    {
        pu64Curr[u8Curr] = BLT_LOAD_FADEFACT(pstParam->u8FadingFctr);
        u8Curr++;
    }
    if (pstParam->eRleiFmt == RLEI_OVRFMT_RGB16)
    {
        /* Run-Length 16-bit RGB */
        pu64Curr[u8Curr] = BLT_ORLEI16(pstParam->eDestFmt,
                                       pstParam->eTranspColEn,
                                       pstParam->eFadeMode,
                                       pstParam->eClipWndEn);
    }
    else
    {
        /* Run-Length 16-bit RGB */
        pu64Curr[u8Curr] = BLT_ORLEI24(pstParam->eDestFmt,
                                       pstParam->eTranspColEn,
                                       pstParam->eFadeMode,
                                       pstParam->eClipWndEn);
    }
    u8Curr++;

    /* Update List Pointer */
    pstCmdList->pu64Current = &pu64Curr[u8Curr];

    pstCmdList->u32UsedDoubleWords = u8Curr;

}

/* ....................................................................... */
void vBlit_OverwriteRLEI_RGBA(blit_mem_st* pstMem, blit_OvrRleiA_st* pstParam,
                              ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 6U;
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr;    
    if(pstParam->eFadeMode != BLT_NOFADING)
    {
        u32NeededDW++;  /* for fade factor*/
    }
    u32NeededDW++; /* for command itself */

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

    /* Source Memory Params */
    pu64Curr[0] = BLT_LOAD_SOURCEADDR(pstMem->u32SrcAddr);
    pu64Curr[1] = BLT_LOAD_SRCWIDTH(pstMem->u16SrcWidth);

    /* Destination Memory Params */
    pu64Curr[2] = BLT_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[3] = BLT_LOAD_DESTWIDTH(pstMem->u16DstWidth);

    /* Blitting Area Size */
    pu64Curr[4] = BLT_LOAD_DESTDOTCNT(pstMem->u16DotCnt);
    pu64Curr[5] = BLT_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /*** Operation Specific Params ***/

    /* Fading Factor Setup */
    if(pstParam->eFadeMode != BLT_NOFADING)
    {
        pu64Curr[u8Curr] = BLT_LOAD_FADEFACT(pstParam->u8FadingFctr);
        u8Curr++;
    }

    if (pstParam->eRleiFmt == RLEI_OVRFMT_RGBA24)
    {
        /* Run-Length 32-bit RGB */
        pu64Curr[u8Curr] = BLT_ORLEI24A(pstParam->eDestFmt,
                                        pstParam->eFadeMode,
                                        pstParam->eClipWndEn);
    }
    else
    {
        /* Run-Length 32-bit RGB */
        pu64Curr[u8Curr] = BLT_ORLEI32(pstParam->eDestFmt,
                                       pstParam->eFadeMode,
                                       pstParam->eClipWndEn);
    }
    u8Curr++;

    /* Update List Pointer */
    pstCmdList->pu64Current = &pu64Curr[u8Curr];

    pstCmdList->u32UsedDoubleWords = u8Curr;

}

/* ....................................................................... */
void vBlit_OverwriteFillRGB(blit_mem_st* pstMem, blit_OvrRgbP_st* pstParam,
                            ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 4U;
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr;
    
    if(pstParam->eFadeMode != BLT_NOFADING)
    {
        u32NeededDW++;  /* for fade factor*/
    }
    u32NeededDW+=2; /* for color and command itself */

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

    /* Destination Memory Params */
    pu64Curr[0] = BLT_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[1] = BLT_LOAD_DESTWIDTH(pstMem->u16DstWidth);

    /* Blitting Area Size */
    pu64Curr[2] = BLT_LOAD_DESTDOTCNT(pstMem->u16DotCnt);
    pu64Curr[3] = BLT_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /*** Operation Specific Params ***/

    /* Fading Factor Setup */
    if(pstParam->eFadeMode != BLT_NOFADING)
    {
        pu64Curr[u8Curr] = BLT_LOAD_FADEFACT(pstParam->u8FadingFctr);
        u8Curr++;
    }

    /* Source Format Selection */
    if(pstParam->eSrcFmt == GA_RGB16)
    {
        pu64Curr[u8Curr] = BLT_LOAD_FILLRGB(pstParam->u32Color);
        u8Curr++;
        pu64Curr[u8Curr] = BLT_OPRST_RGB16(pstParam->eFadeMode, pstParam->eClipWndEn);
    }
    else
    {
        pu64Curr[u8Curr] = BLT_LOAD_FILLRGBA(pstParam->u32Color);
        u8Curr++;
        pu64Curr[u8Curr] = BLT_OPRST_RGBA32(pstParam->eFadeMode, pstParam->eClipWndEn);
    }

    u8Curr++;

    /* Update List Pointer */
    pstCmdList->pu64Current = &pu64Curr[u8Curr];

    pstCmdList->u32UsedDoubleWords = u8Curr;

}

/* ....................................................................... */
int32_t i32Blit_BlendRGB(blit_mem_st* pstMem, blit_BlndRgb_st* pstParam,
                         ga_list_st* pstCmdList)
{
    int32_t i32Res = C_FAILED;
    uint8_t u8Curr = 6U;
    uint64_t* pu64Curr;
    ga_en_e         eTranspColEn_valid;
    blt_fadeMode_e  eFadeMode_valid;

    if(pstParam->eRastOpEn == GA_EN)
    {
        /* Raster option requires disabled Fading and Transp. Col. Opt. 
         * If it is enabled Transparency Color and Fade mode will be
         * assuemed as disbaled */
        eTranspColEn_valid = GA_DIS;
        eFadeMode_valid    = BLT_NOFADING;
    }
    else
    {
        eTranspColEn_valid = pstParam->eTranspColEn;
        eFadeMode_valid    = pstParam->eFadeMode;
    }

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr;
    u32NeededDW += 2; /* 2 for Src/Dst Alpha */
    if(pstParam->eRastOpEn == GA_EN)
    {
        u32NeededDW++; /* for raster value */
    }
    else
    {
        if(eFadeMode_valid != BLT_NOFADING)
        {
            u32NeededDW++;  /* for fade factor*/
        }
        if(eTranspColEn_valid == GA_EN)
        {
            u32NeededDW+=2; /* for Src/Dst Transparency */
        }
    }
    u32NeededDW++; /* for command itself */

    if(pstParam->eRastOpEn == GA_EN && pstParam->eSrcFmt != pstParam->eDestFmt)    
    {
      /* in this case no command will be writen : */
      u32NeededDW = u8Curr;
    }

    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */

    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return C_FAILED;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif 

    /* Check Whether Raster Operation is enabled */
    if(pstParam->eRastOpEn == GA_EN)
    {
        /* Source and Destination must have the same Format */
        if(pstParam->eSrcFmt == pstParam->eDestFmt)
        {
            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_SUCCESS;
    }

    /* Check if all conditions are met */
    if(i32Res == C_SUCCESS)
    {
        /* Update Pointer */
        pu64Curr = (uint64_t*) pstCmdList->pu64Current;

        /* Source Memory Params */
        pu64Curr[0] = BLT_LOAD_SOURCEADDR(pstMem->u32SrcAddr);
        pu64Curr[1] = BLT_LOAD_SRCWIDTH(pstMem->u16SrcWidth);

        /* Destination Memory Params */
        pu64Curr[2] = BLT_LOAD_DESTADDR(pstMem->u32DstAddr);
        pu64Curr[3] = BLT_LOAD_DESTWIDTH(pstMem->u16DstWidth);

        /* Blitting Area Size */
        pu64Curr[4] = BLT_LOAD_DESTDOTCNT(pstMem->u16DotCnt);
        pu64Curr[5] = BLT_LOAD_DESTLINECNT(pstMem->u16LineCnt);

        /*** Operation Specific Params ***/

        /* Raster Parameter Setup */
        if(pstParam->eRastOpEn == GA_EN)
        {
            pu64Curr[u8Curr] = BLT_LOAD_RASTOP(pstParam->eRastOpMode, pstParam->eRastOpValue);
            u8Curr++;
        }
        /* Fading Parameter Setup */
        if(eFadeMode_valid != BLT_NOFADING)
        {
            pu64Curr[u8Curr] = BLT_LOAD_FADEFACT(pstParam->u8FadingFctr);
            u8Curr++;
        }

        /* Source Alpha Blending Value */
        pu64Curr[u8Curr] = BLT_LOAD_SRCALPHA(pstParam->u8SrcAlphaVal);
        u8Curr++;

        /* Destination Alpha Blending Value */
        pu64Curr[u8Curr] = BLT_LOAD_DESTALPHA(pstParam->u8DstAlphaVal);
        u8Curr++;

        /* Transparency Parameters */
        if(eTranspColEn_valid == GA_EN)
        {
            /* Transparency Color Option */
            pu64Curr[u8Curr] = BLT_LOAD_SRCTRANSPATT(pstParam->u32SrcTransVal);
            u8Curr++;
            pu64Curr[u8Curr] = BLT_LOAD_DESTTRANSPATT(pstParam->u16DstTransVal);
            u8Curr++;
        }

        /* Source Selection */
        if(pstParam->eSrcFmt == GA_RGB16)
        {
            /* Blit Blend. 16-bit RGB */
            pu64Curr[u8Curr] = BLT_BRGB16(pstParam->eRedChPrtEn,
                                          pstParam->eGreenChPrtEn,
                                          pstParam->eBlueChPrtEn,
                                          pstParam->eAlphaChPrtEn,
                                          pstParam->eRastOpEn,
                                          pstParam->eDestFmt,
                                          pstParam->eBlndOrder,
                                          eTranspColEn_valid ,  /* if eRastOpEn is enabled then this parameter will be disabled */ 
                                          eFadeMode_valid,      /* if eRastOpEn is enabled then this parameter will be disabled */
                                          pstParam->eClipWndEn);
        }
        else
        {
            /* Blit Blend. 32-bit RGBA */
            pu64Curr[u8Curr] = BLT_BRGBA32(pstParam->eRedChPrtEn,
                                           pstParam->eGreenChPrtEn,
                                           pstParam->eBlueChPrtEn,
                                           pstParam->eAlphaChPrtEn,
                                           pstParam->eRastOpEn,
                                           pstParam->eDestFmt,
                                           pstParam->eBlndOrder,
                                           eTranspColEn_valid ,  /* if eRastOpEn is enabled then this parameter will be disabled */ 
                                           eFadeMode_valid,      /* if eRastOpEn is enabled then this parameter will be disabled */
                                           pstParam->eClipWndEn);
        }

        u8Curr++;

        /* Update List Pointer */
        pstCmdList->pu64Current = &pu64Curr[u8Curr];
    }

    pstCmdList->u32UsedDoubleWords = u8Curr;

    return i32Res;
}

/* ....................................................................... */
void vBlit_BlendRLEI(blit_mem_st* pstMem, blit_BlndRlei_st* pstParam,
                     ga_list_st* pstCmdList)
{
    uint8_t         u8Curr = 6U;
    ga_en_e         eTranspColEn_valid;
    blt_fadeMode_e  eFadeMode_valid;
    uint64_t*       pu64Curr = (uint64_t*) pstCmdList->pu64Current;

    if(pstParam->eRastOpEn == GA_EN)
    {
        /* Raster option requires disabled Fading and Transp. Col. Opt. 
         * If it is enabled Transparency Color and Fade mode will be
         * assuemed as disbaled */
        eTranspColEn_valid = GA_DIS;
        eFadeMode_valid    = BLT_NOFADING;
    }
    else
    {
        eTranspColEn_valid = pstParam->eTranspColEn;
        eFadeMode_valid    = pstParam->eFadeMode;
    }

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr + 2; /* 2 for Src/Dst Alpha */
    if(pstParam->eRastOpEn == GA_EN)
    {
        u32NeededDW++; /* for raster value */
    }
    else
    {
        if(eFadeMode_valid != BLT_NOFADING)
        {
            u32NeededDW++;  /* for fade factor*/
        }
        if(eTranspColEn_valid == GA_EN)
        {
            u32NeededDW+=2; /* for Src/Dst Transparency */
        }
    }
    u32NeededDW++; /* for command itself */

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

    /* Source Memory Params */
    pu64Curr[0] = BLT_LOAD_SOURCEADDR(pstMem->u32SrcAddr);
    pu64Curr[1] = BLT_LOAD_SRCWIDTH(pstMem->u16SrcWidth);

    /* Destination Memory Params */
    pu64Curr[2] = BLT_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[3] = BLT_LOAD_DESTWIDTH(pstMem->u16DstWidth);

    /* Blitting Area Size */
    pu64Curr[4] = BLT_LOAD_DESTDOTCNT(pstMem->u16DotCnt);
    pu64Curr[5] = BLT_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /*** Operation Specific Params ***/

    /* Raster Parameter Setup */
    if(pstParam->eRastOpEn == GA_EN)
    {
        pu64Curr[u8Curr] = BLT_LOAD_RASTOP(pstParam->eRastOpMode, pstParam->eRastOpValue);
        u8Curr++;
    }

    /* Fading Parameter Setup */
    if(eFadeMode_valid != BLT_NOFADING)
    {
        pu64Curr[u8Curr] = BLT_LOAD_FADEFACT(pstParam->u8FadingFctr);
        u8Curr++;
    }

    pu64Curr[u8Curr] = BLT_LOAD_SRCALPHA(pstParam->u8SrcAlphaVal);
    u8Curr++;

    pu64Curr[u8Curr] = BLT_LOAD_DESTALPHA(pstParam->u8DstAlphaVal);
    u8Curr++;    
    
    /* Transparency Parameters */
    if(eTranspColEn_valid == GA_EN)
    {
        /* Transparency Color Option */
        pu64Curr[u8Curr] = BLT_LOAD_SRCTRANSPATT(pstParam->u32SrcTransVal);
        u8Curr++;

        pu64Curr[u8Curr] = BLT_LOAD_DESTTRANSPATT(pstParam->u16DstTransVal);
        u8Curr++;
    }
    switch( pstParam->eRleiFmt )
    {
        case RLEI_BLNDFMT_RGB16:
            /* Blit Blend. Run-Len. Enc. 16-bit RGB */
            pu64Curr[u8Curr] = BLT_BRLEI16(pstParam->eRedChPrtEn,
                                           pstParam->eGreenChPrtEn,
                                           pstParam->eBlueChPrtEn,
                                           pstParam->eAlphaChPrtEn,
                                           pstParam->eRastOpEn,
                                           pstParam->eDestFmt,
                                           pstParam->eBlndOrder,
                                           eTranspColEn_valid ,  /* if eRastOpEn is enabled then this parameter will be disabled */ 
                                           eFadeMode_valid,      /* if eRastOpEn is enabled then this parameter will be disabled */
                                           pstParam->eClipWndEn);
            break;
        case RLEI_BLNDFMT_RGB24:
            /* Blit Blend. Run-Len. Enc. 24bit RGB */
            pu64Curr[u8Curr] = BLT_BRLEI24(pstParam->eRedChPrtEn,
                                           pstParam->eGreenChPrtEn,
                                           pstParam->eBlueChPrtEn,
                                           pstParam->eAlphaChPrtEn,
                                           pstParam->eRastOpEn,
                                           pstParam->eDestFmt,
                                           pstParam->eBlndOrder,
                                           eTranspColEn_valid ,  /* if eRastOpEn is enabled then this parameter will be disabled */ 
                                           eFadeMode_valid,      /* if eRastOpEn is enabled then this parameter will be disabled */
                                           pstParam->eClipWndEn);
            break;
        case RLEI_BLNDFMT_RGBA24:
            /* Blit Blend. Run-Len. Enc. 24-bit RGBA */
            pu64Curr[u8Curr] = BLT_BRLEI24A(pstParam->eRedChPrtEn,
                                           pstParam->eGreenChPrtEn,
                                           pstParam->eBlueChPrtEn,
                                           pstParam->eAlphaChPrtEn,
                                           pstParam->eRastOpEn,
                                           pstParam->eDestFmt,
                                           pstParam->eBlndOrder,
                                           eTranspColEn_valid ,  /* if eRastOpEn is enabled then this parameter will be disabled */ 
                                           eFadeMode_valid,      /* if eRastOpEn is enabled then this parameter will be disabled */
                                           pstParam->eClipWndEn);
            break;
        default:
            /* Blit Blend. Run-Len. Enc. 32-bit RGBA */
            pu64Curr[u8Curr] = BLT_BRLEI32(pstParam->eRedChPrtEn,
                                           pstParam->eGreenChPrtEn,
                                           pstParam->eBlueChPrtEn,
                                           pstParam->eAlphaChPrtEn,
                                           pstParam->eRastOpEn,
                                           pstParam->eDestFmt,
                                           pstParam->eBlndOrder,
                                           eTranspColEn_valid ,  /* if eRastOpEn is enabled then this parameter will be disabled */ 
                                           eFadeMode_valid,      /* if eRastOpEn is enabled then this parameter will be disabled */
                                           pstParam->eClipWndEn);
            break;
         
    }
    u8Curr++;

    /* Update List Pointer */
    pstCmdList->pu64Current = &pu64Curr[u8Curr];

    pstCmdList->u32UsedDoubleWords = u8Curr;
}

/* ....................................................................... */
void vBlit_BlendFillRGB(blit_mem_st* pstMem, blit_BlndFill16_st* pstParam,
                        ga_list_st* pstCmdList)
{
    uint8_t         u8Curr = 7U;
    blt_fadeMode_e  eFadeMode_valid;
    uint64_t*       pu64Curr = (uint64_t*) pstCmdList->pu64Current;
    

    if(pstParam->eRastOpEn == GA_EN)
    {
        /* Raster option requires disabled Fading Opt. 
         * If it is enabled Fade mode will be  assuemed as disbaled */
        eFadeMode_valid = BLT_NOFADING;
    }
    else
    {
        eFadeMode_valid = pstParam->eFadeMode;
    }

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr;
    if(pstParam->eRastOpEn == GA_EN)
    {
        u32NeededDW++; /* for raster value */
    }
    else
    {
        if(eFadeMode_valid != BLT_NOFADING)
        {
            u32NeededDW++;  /* for fade factor*/
        }
    }
    u32NeededDW++; /* for command itself */

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

    /* Destination Memory Params */
    pu64Curr[0] = BLT_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[1] = BLT_LOAD_DESTWIDTH(pstMem->u16DstWidth);

    /* Blitting Area Size */
    pu64Curr[2] = BLT_LOAD_DESTDOTCNT(pstMem->u16DotCnt);
    pu64Curr[3] = BLT_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /*** Operation Specific Params ***/

    /* Fill Color */
    pu64Curr[4] = BLT_LOAD_FILLRGB(pstParam->u16Color);

    /* Source and Destination Alpha Blending */
    pu64Curr[5] = BLT_LOAD_SRCALPHA(pstParam->u8SrcAlphaVal);
    pu64Curr[6] = BLT_LOAD_DESTALPHA(pstParam->u8DstAlphaVal);

    /* Raster Parameter Setup */
    if(pstParam->eRastOpEn == GA_EN)
    {
        pu64Curr[u8Curr] = BLT_LOAD_RASTOP(pstParam->eRastOpMode, pstParam->eRastOpValue);
        u8Curr++;
    }

    /* Fading Factor Setup */
    if(eFadeMode_valid != BLT_NOFADING)
    {
        pu64Curr[u8Curr] = BLT_LOAD_FADEFACT(pstParam->u8FadingFctr);
        u8Curr++;
    }

    /* Blit Blend. Preset 16-bit RGB  */
    pu64Curr[u8Curr] = BLT_BPRST_RGB16(pstParam->eRedChPrtEn,
                                       pstParam->eGreenChPrtEn,
                                       pstParam->eBlueChPrtEn,
                                       pstParam->eRastOpEn,
                                       pstParam->eBlndOrder,
                                       eFadeMode_valid,      /* if eRastOpEn is enabled then this parameter will be disabled */
                                       pstParam->eClipWndEn);
    u8Curr++;

    /* Update List Pointer */
    pstCmdList->pu64Current = &pu64Curr[u8Curr];

    pstCmdList->u32UsedDoubleWords = u8Curr;

}

/* ....................................................................... */
void vBlit_BlendFillRGBA(blit_mem_st* pstMem, blit_BlndFill32_st* pstParam,
                         ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 5U;
    blt_fadeMode_e  eFadeMode_valid;
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

    if(pstParam->eRastOpEn == GA_EN)
    {
        /* Raster option requires disabled Fading Opt. 
         * If it is enabled Fade mode will be  assuemed as disbaled */
        eFadeMode_valid = BLT_NOFADING;
    }
    else
    {
        eFadeMode_valid = pstParam->eFadeMode;
    }

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr;
    if(pstParam->eRastOpEn == GA_EN)
    {
        u32NeededDW++; /* for raster value */
    }
    else
    {
        if(eFadeMode_valid != BLT_NOFADING)
        {
            u32NeededDW++;  /* for fade factor*/
        }
    }
    u32NeededDW++; /* for command itself */

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

    /* Destination Memory Params */
    pu64Curr[0] = BLT_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[1] = BLT_LOAD_DESTWIDTH(pstMem->u16DstWidth);

    /* Blitting Area Size */
    pu64Curr[2] = BLT_LOAD_DESTDOTCNT(pstMem->u16DotCnt);
    pu64Curr[3] = BLT_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /* Fill Color */
    pu64Curr[4] = BLT_LOAD_FILLRGBA(pstParam->u32Color);

    /*** Operation Specific Params ***/

    /* Raster Parameter Setup */
    if(pstParam->eRastOpEn == GA_EN)
    {
        pu64Curr[u8Curr] = BLT_LOAD_RASTOP(pstParam->eRastOpMode, pstParam->eRastOpValue);
        u8Curr++;
    }

    /* Fading Factor Setup */
    if(eFadeMode_valid != BLT_NOFADING)
    {
        pu64Curr[u8Curr] = BLT_LOAD_FADEFACT(pstParam->u8FadingFctr);
        u8Curr++;
    }

    /* Blit Blend. Preset 16-bit RGB  */
    pu64Curr[u8Curr] = BLT_BPRST_RGBA32(pstParam->eRedChPrtEn,
                                        pstParam->eGreenChPrtEn,
                                        pstParam->eBlueChPrtEn,
                                        pstParam->eAlphaChPrtEn,
                                        pstParam->eRastOpEn,
                                        pstParam->eBlndOrder,
                                        eFadeMode_valid,      /* if eRastOpEn is enabled then this parameter will be disabled */
                                        pstParam->eClipWndEn);
    u8Curr++;

    /* Update List Pointer */
    pstCmdList->pu64Current = &pu64Curr[u8Curr];

    pstCmdList->u32UsedDoubleWords = u8Curr;

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
**  File: blit.c
**  $Revision: 1.14 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**
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
** | RULE   : 1879 /10.3  - 	 cast of complex integer expression with underlying
** |                           type "type" to same width type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as macros in io header file
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

