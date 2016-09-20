/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Graphic Accelerator
*                 Reference Low-Level Driver (Rotation Engine matrix based)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphic Accelerator Rotation Engine
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
/*======================================
            Include Files
=======================================*/
#include "captypes.h"
#include "rotation_matrix.h"
#include "ga.h"

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1858  /* Rule 17.4 [R] : subscript operator may only be applied to objects declared as an array type */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : conversion from underlying type, "int", to same width underlying type, "uint32_t", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1878  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to wider type "type" not allowed */
  #pragma ghs nowarning 1879  /* Rule 10.3 [R] : Restrict explicit casts for integer type expressions */

  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */  
  #pragma ghs nowarning 1737  /* Rule 12.1 [A] :  expression may not depend on operator precedence rules */
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
#define LLDD_GA_ROTATE_MATRIX_C_REVISION     "$Revision: 1.12 $"
#define LLDD_GA_ROTATE_MATRIX_C_TAG          "$Name: LLDD_1_7_GFX $"

static uint8_t au8LLDD_GA_ROTATE_MATRIX_C_REVISION[] = LLDD_GA_ROTATE_MATRIX_C_REVISION;
static uint8_t au8LLDD_GA_ROTATE_MATRIX_C_TAG[]      = LLDD_GA_ROTATE_MATRIX_C_TAG;
static uint8_t au8LLDD_GA_ROTATE_MATRIX_H_REVISION[] = LLDD_GA_ROTATE_MATRIX_H_REVISION;
static uint8_t au8LLDD_GA_ROTATE_MATRIX_H_TAG[]      = LLDD_GA_ROTATE_MATRIX_H_TAG;

#define WxR_VALUE_ONE  0x10000  /* WxR register set to 1 (shifted by 16 bits)*/
/*======================================
          Function definitions
=======================================*/

void vRot_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
     *pau8ModuleRevision = &au8LLDD_GA_ROTATE_MATRIX_C_REVISION[0];
     *pau8ModuleTag      = &au8LLDD_GA_ROTATE_MATRIX_C_TAG[0];
     *pau8HeaderRevision = &au8LLDD_GA_ROTATE_MATRIX_H_REVISION[0];
     *pau8HeaderTag      = &au8LLDD_GA_ROTATE_MATRIX_H_TAG[0];
}

/* ....................................................................... */
void vRot_SetMemSrc(uint32_t u32Addr, uint32_t u32Width, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 3;
   
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

    pu64Curr[0] = ROT_LOAD_SRCWIDTH(u32Width);
    pu64Curr[1] = ROT_LOAD_SOURCEADDR(u32Addr);

    pstCmdList->pu64Current = &pu64Curr[2];
}

/* ....................................................................... */
void vRot_SetMemDest(uint32_t u32Addr, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;
    
#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 2U;
   
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

    pu64Curr[0] = ROT_LOAD_DESTADDR( u32Addr);

    pstCmdList->pu64Current = &pu64Curr[1];
    pstCmdList->u32UsedDoubleWords = 2U;
}

/* ....................................................................... */
void vRot_SetMemDim(uint16_t u16Width, uint16_t u16Height, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1U;
   
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

    pu64Curr[0] = ROT_LOAD_DESTMEMDIM(u16Width, u16Height);

    pstCmdList->pu64Current = &pu64Curr[1];
    pstCmdList->u32UsedDoubleWords = 1U;
}

/* ....................................................................... */
void vRot_SetColorFmt(ga_colFmt_e eDstColFormat, ga_colFmt_e eSrcColFormat, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1U;
   
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
    /* Color format for Rotation should be redefined to fit to HW implemenation:
     *  modify color format 0-->1 and 1-->0 
     *  */
    pu64Curr[0] = ROT_LOAD_COLORFMT((1 - (uint8_t) eDstColFormat), (1 - (uint8_t) eSrcColFormat));

    pstCmdList->pu64Current = &pu64Curr[1];
    pstCmdList->u32UsedDoubleWords = 1U;
}

/* ....................................................................... */
void vRot_SetRotMtrx(rot_Mtrx_st* pstMatrix, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 7U;
   
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
    
    pu64Curr[0] = ROT_LOAD_A11(pstMatrix->u32A11);
    pu64Curr[1] = ROT_LOAD_A12(pstMatrix->u32A12);
    pu64Curr[2] = ROT_LOAD_A21(pstMatrix->u32A21);
    pu64Curr[3] = ROT_LOAD_A22(pstMatrix->u32A22);
    /* Load W0, W1, W2: */
    pu64Curr[4] = ROT_LOAD_A31(pstMatrix->u32A31);
    pu64Curr[5] = ROT_LOAD_A32(pstMatrix->u32A32);
    pu64Curr[6] = ROT_LOAD_A33(pstMatrix->u32A33);

    pstCmdList->pu64Current = &pu64Curr[7];
    pstCmdList->u32UsedDoubleWords = 7U;
}

/* ....................................................................... */
void vRot_SetFrwdCoord(rot_frccr_st* pstCoord, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 4U;
   
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

    pu64Curr[0] = ROT_LOAD_COORD1(pstCoord->u16X1, pstCoord->u16Y1);
    pu64Curr[1] = ROT_LOAD_COORD2(pstCoord->u16X2, pstCoord->u16Y2);
    pu64Curr[2] = ROT_LOAD_COORD3(pstCoord->u16X3, pstCoord->u16Y3);
    pu64Curr[3] = ROT_LOAD_COORD4(pstCoord->u16X4, pstCoord->u16Y4);

    pstCmdList->pu64Current = &pu64Curr[4];
    pstCmdList->u32UsedDoubleWords = 4U;
}

/* ....................................................................... */
void vRot_SetSrcAddrPos(rot_SrcSel_e eSrcSel, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1U;
   
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

    pu64Curr[0] = ROT_LOAD_SRCADDRPOS((uint8_t) eSrcSel);

    pstCmdList->pu64Current = &pu64Curr[1];
    pstCmdList->u32UsedDoubleWords = 4U;
}

/* ....................................................................... */
void vRot_SetRotationCmd(ga_en_e eClipWndEn, ga_en_e eFilterEn, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 1U;
   
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

    pu64Curr[0] = ROT_ROTATE(eClipWndEn, eFilterEn);

    pstCmdList->pu64Current = &pu64Curr[1];
    pstCmdList->u32UsedDoubleWords = 1U;
}

/* ....................................................................... */
void vRot_SetClippWnd(rot_clipWnd_st* pstClipWnd, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW  = 2U;
   
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

    pu64Curr[0] = ROT_LOAD_CLIPWNDUL(pstClipWnd->u16UlX,pstClipWnd->u16UlY);
    pu64Curr[1] = ROT_LOAD_CLIPWNDLR(pstClipWnd->u16LrX,pstClipWnd->u16LrY);

    pstCmdList->pu64Current = &pu64Curr[2];
    pstCmdList->u32UsedDoubleWords = 2U;
}
/* ....................................................................... */
void vRot_RotateMatrix(rot_mem_st* pstMem, rot_rotCfg_st* pstParam, 
                       rot_Mtrx_st* pstMatrix, rot_frccr_st* pstCoord,
                       ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 20U;
    uint64_t* pu64Curr;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK
    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr;
    if(pstParam->eClipWndEn == GA_EN)
    {
        u32NeededDW += 2; /* window parameters */
    }
    u32NeededDW++; /* for ROT_ROTATE */

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

    pu64Curr = (uint64_t*) pstCmdList->pu64Current;

    /* Source Mem. Params */
    pu64Curr[0] = ROT_LOAD_SRCWIDTH(pstMem->u16SrcWidth);
    pu64Curr[1] = ROT_LOAD_SOURCEADDR(pstMem->u32SrcAddr);

    /* Destination Mem. Params */
    pu64Curr[2] = ROT_LOAD_DESTADDR( pstMem->u32DstAddr);
    pu64Curr[3] = ROT_LOAD_DESTMEMDIM(pstMem->u16DstImgWidth, pstMem->u16DstImgHeight);

    /* Color format for Rotation should be redefined to fit to HW implemenation:
     *  modify color format 0-->1 and 1-->0 
     *  */
    pu64Curr[4] = ROT_LOAD_COLORFMT((1 - (uint8_t)(pstParam->eDstColFmt)), (1 - (uint8_t)(pstParam->eSrcColFmt)));

    /* Transformation Matrix Config. */
    pu64Curr[5] = ROT_LOAD_A11(pstMatrix->u32A11);
    pu64Curr[6] = ROT_LOAD_A12(pstMatrix->u32A12);
    pu64Curr[7] = ROT_LOAD_A21(pstMatrix->u32A21);
    pu64Curr[8] = ROT_LOAD_A22(pstMatrix->u32A22);

    /* Load W0, W1, W2: */
    pu64Curr[9]  = ROT_LOAD_A31(pstMatrix->u32A31);
    pu64Curr[10] = ROT_LOAD_A32(pstMatrix->u32A32);
    pu64Curr[11] = ROT_LOAD_A33(pstMatrix->u32A33);

    /* write forward rotated corner coordinates */
    pu64Curr[12] = ROT_LOAD_COORD1(pstCoord->u16X1, pstCoord->u16Y1);
    pu64Curr[13] = ROT_LOAD_COORD2(pstCoord->u16X2, pstCoord->u16Y2);
    pu64Curr[14] = ROT_LOAD_COORD3(pstCoord->u16X3, pstCoord->u16Y3);
    pu64Curr[15] = ROT_LOAD_COORD4(pstCoord->u16X4, pstCoord->u16Y4);

    pu64Curr[16] = ROT_LOAD_SRCADDRPOS(pstCoord->u8ScrAddrPos);

    pu64Curr[17] = ROT_LOAD_FADEFACT(pstParam->u8FadingFctr);

    pu64Curr[18] = ROT_LOAD_SRCALPHAVAL(pstParam->u8SrcAlphaVal);
    pu64Curr[19] = ROT_LOAD_DSTALPHAVAL(pstParam->u8DstAlphaVal);
    
    /* Clipping Window */
    if(pstParam->eClipWndEn == GA_EN)
    {
        pu64Curr[u8Curr] = ROT_LOAD_CLIPWNDUL(pstParam->tClipWnd.u16UlX, pstParam->tClipWnd.u16UlY);
        u8Curr++;

        pu64Curr[u8Curr] = ROT_LOAD_CLIPWNDLR(pstParam->tClipWnd.u16LrX, pstParam->tClipWnd.u16LrY);
        u8Curr++;
    }

    /* Rotation Command */
    pu64Curr[u8Curr] = ROT_ROTATE(pstParam->eClipWndEn, pstParam->eFilterEn);
    u8Curr++;

    pstCmdList->pu64Current = &pu64Curr[u8Curr];
    pstCmdList->u32UsedDoubleWords = u8Curr;
}


/* ....................................................................... */
void vRot_RotateBlendMatrix(rot_mem_st* pstMem, rot_rotblendCfg_st* pstParam, 
                            rot_Mtrx_st* pstMatrix, rot_frccr_st* pstCoord, 
                            ga_list_st* pstCmdList)
{
    uint8_t u8Curr = 20U;
    uint64_t* pu64Curr;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK
    uint32_t u32NeededDW ;
    
    u32NeededDW = u8Curr;
    if(pstParam->eClipWndEn == GA_EN)
    {
        u32NeededDW += 2; /* window parameters */
    }
    u32NeededDW++; /* for ROT_ROTATEB */

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

    pu64Curr = (uint64_t*) pstCmdList->pu64Current;

    /* Source Mem. Params */
    pu64Curr[0] = ROT_LOAD_SRCWIDTH(pstMem->u16SrcWidth);
    pu64Curr[1] = ROT_LOAD_SOURCEADDR(pstMem->u32SrcAddr);

    /* Destination Mem. Params */
    pu64Curr[2] = ROT_LOAD_DESTADDR(pstMem->u32DstAddr);
    pu64Curr[3] = ROT_LOAD_DESTMEMDIM(pstMem->u16DstImgWidth, pstMem->u16DstImgHeight);

    /* Color format for Rotation should be redefined to fit to HW implemenation:
     *  modify color format 0-->1 and 1-->0 
     *  */
    pu64Curr[4] = ROT_LOAD_COLORFMT((1 - (uint8_t)(pstParam->eDstColFmt)), (1 - (uint8_t)(pstParam->eSrcColFmt)));

    /* Transformation Matrix Config. */
    pu64Curr[5] = ROT_LOAD_A11(pstMatrix->u32A11);
    pu64Curr[6] = ROT_LOAD_A12(pstMatrix->u32A12);
    pu64Curr[7] = ROT_LOAD_A21(pstMatrix->u32A21);
    pu64Curr[8] = ROT_LOAD_A22(pstMatrix->u32A22);

    /* Load W0, W1, W2: */
    pu64Curr[9]  = ROT_LOAD_A31(pstMatrix->u32A31);
    pu64Curr[10] = ROT_LOAD_A32(pstMatrix->u32A32);
    pu64Curr[11] = ROT_LOAD_A33(pstMatrix->u32A33);
    
    /* write forward rotated corner coordinates */
    pu64Curr[12] = ROT_LOAD_COORD1(pstCoord->u16X1, pstCoord->u16Y1);
    pu64Curr[13] = ROT_LOAD_COORD2(pstCoord->u16X2, pstCoord->u16Y2);
    pu64Curr[14] = ROT_LOAD_COORD3(pstCoord->u16X3, pstCoord->u16Y3);
    pu64Curr[15] = ROT_LOAD_COORD4(pstCoord->u16X4, pstCoord->u16Y4);

    pu64Curr[16] = ROT_LOAD_SRCADDRPOS(pstCoord->u8ScrAddrPos);

    pu64Curr[17] = ROT_LOAD_FADEFACT(pstParam->u8FadingFctr);

    pu64Curr[18] = ROT_LOAD_SRCALPHAVAL(pstParam->u8SrcAlphaVal);

    pu64Curr[19] = ROT_LOAD_DSTALPHAVAL(pstParam->u8DstAlphaVal);

    /* Clipping Window */
    if(pstParam->eClipWndEn == GA_EN)
    {
        pu64Curr[u8Curr] = ROT_LOAD_CLIPWNDUL(pstParam->tClipWnd.u16UlX, pstParam->tClipWnd.u16UlY);
        u8Curr++;

        pu64Curr[u8Curr] = ROT_LOAD_CLIPWNDLR(pstParam->tClipWnd.u16LrX, pstParam->tClipWnd.u16LrY);
        u8Curr++;
    }

    /* Rotation Command */
    pu64Curr[u8Curr] = ROT_ROTATEB(pstParam->eDstRedProt,
                                   pstParam->eDstGreenProt,
                                   pstParam->eDstBlueProt,
                                   pstParam->eDstAlphaProt,
                                   pstParam->eSrcRedFad,
                                   pstParam->eSrcGreenFad,
                                   pstParam->eSrcBlueFad,
                                   pstParam->eSrcAlphaFad,
                                   pstParam->eBldOrd,
                                   pstParam->eClipWndEn,
                                   pstParam->eFilterEn);

    u8Curr++;

    pstCmdList->pu64Current = &pu64Curr[u8Curr];

    pstCmdList->u32UsedDoubleWords = u8Curr;
}
/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/
/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: rotation_matrix.c
**  $Revision: 1.12 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
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
** | RULE   : 1865 /10.1  -  implicit conversion from underlying type, "type", 
** |                         to same width underlying type, "type", not allowed
** | CONS.  : allow
** | REASON : for usage of macros from io header files
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

