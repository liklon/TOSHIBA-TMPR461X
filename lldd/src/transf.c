/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Graphic Accelerator
*                 Reference Low-Level Driver (Transformation Engine)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphic Accelerator Transformation Engine
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.13 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/*======================================
            Include Files
=======================================*/
#include "transf.h"
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

#define LLDD_GA_TRANSF_C_REVISION     "$Revision: 1.13 $"
#define LLDD_GA_TRANSF_C_TAG          "$Name: LLDD_1_7_GFX $"

/*======================================
 Static variables and forward declarations
=======================================*/

static uint8_t au8LLDD_GA_TRANSF_C_REVISION[] = LLDD_GA_TRANSF_C_REVISION;
static uint8_t au8LLDD_GA_TRANSF_C_TAG[]      = LLDD_GA_TRANSF_C_TAG;
static uint8_t au8LLDD_GA_TRANSF_H_REVISION[] = LLDD_GA_TRANSF_H_REVISION;
static uint8_t au8LLDD_GA_TRANSF_H_TAG[]      = LLDD_GA_TRANSF_H_TAG;

/*======================================
          Function definitions
=======================================*/

void vTransf_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                        uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
     *pau8ModuleRevision = &au8LLDD_GA_TRANSF_C_REVISION[0];
     *pau8ModuleTag      = &au8LLDD_GA_TRANSF_C_TAG[0];
     *pau8HeaderRevision = &au8LLDD_GA_TRANSF_H_REVISION[0];
     *pau8HeaderTag      = &au8LLDD_GA_TRANSF_H_TAG[0];
}

/* ....................................................................... */
void vTransf_SetMemSrc(uint32_t u32Addr, uint32_t u32Width, ga_list_st* pstCmdList)
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

    pu64Curr[0] = TSF_LOAD_SRCWIDTH(u32Width);
    pu64Curr[1] = TSF_LOAD_SOURCEADDR(u32Addr);

    pstCmdList->pu64Current = &pu64Curr[2];
    
    pstCmdList->u32UsedDoubleWords = 2U;

}

/* ....................................................................... */
void vTransf_SetDstImgSize(uint32_t u32Width, uint32_t u32Lines,
                          ga_list_st* pstCmdList)
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

    pu64Curr[0] = TSF_LOAD_DEST_IMAGEWIDTH(u32Width);
    pu64Curr[1] = TSF_LOAD_DESTLINECNT(u32Lines);

    pstCmdList->pu64Current = &pu64Curr[2];
    pstCmdList->u32UsedDoubleWords = 2U;
}

/* ....................................................................... */
void vTransf_SetMemDest(uint32_t u32Addr, uint32_t u32Width, ga_list_st* pstCmdList)
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

    pu64Curr[0] = TSF_LOAD_DESTWIDTH(u32Width);
    pu64Curr[1] = TSF_LOAD_DESTADDR(u32Addr);

    pstCmdList->pu64Current = &pu64Curr[2];
    pstCmdList->u32UsedDoubleWords = 2U;
}

/* ....................................................................... */
void vTransf_ConfigLUT(transf_Lut_st* pstCfg, ga_list_st* pstCmdList)
{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW = 3;

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

    pu64Curr[0] = TSF_LOAD_LUTADDR(pstCfg->u32Addr);
    pu64Curr[1] = TSF_LOAD_LUTWIDTH(pstCfg->u16Width);
    pu64Curr[2] = TSF_LOAD_LUTLINECNT(pstCfg->u16LineCnt);

    pstCmdList->pu64Current = &pu64Curr[3];
    pstCmdList->u32UsedDoubleWords = 3U;
}

/* ....................................................................... */
void vTransf_SetColorFmt(ga_colFmt_e eSrcColFormat, ga_colFmt_e eDstColFormat, ga_list_st* pstCmdList)
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

    /* Color format for Rotation should be redefined to fit to HW implemenation:
     *  modify color format 0-->1 and 1-->0 
     *  */
    pu64Curr[0] = TSF_LOAD_COLORFMT((1 - (uint8_t) eDstColFormat), (1 - (uint8_t) eSrcColFormat));

    pstCmdList->pu64Current = &pu64Curr[1];
    pstCmdList->u32UsedDoubleWords = 1U;
}

/* ....................................................................... */
void vTransf_SetPredefColor(uint32_t u32Color, ga_list_st* pstCmdList)
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

    pu64Curr[0] = TSF_LOAD_PRECOLOR(u32Color);

    pstCmdList->pu64Current = &pu64Curr[1];
    pstCmdList->u32UsedDoubleWords = 1U;
}

/* ....................................................................... */
void vTransf_SetTransfCmd(transf_Mode_e eOpMode, ga_en_e eFilterEn,
                         ga_list_st* pstCmdList)
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

    pu64Curr[0] = TSF_TRANSF(eOpMode,eFilterEn);

    pstCmdList->pu64Current = &pu64Curr[1];
    pstCmdList->u32UsedDoubleWords = 1U;
}

/* ....................................................................... */
void vTransf_ConfigTransfOp(transf_mem_st* pstMem, transf_Lut_st* pstLutCfg,
                            transf_Prm_st* pstTsfPrm, ga_list_st* pstCmdList)

{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK
    uint32_t u32NeededDW = 14U;

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

    /* Source Mem. */
    pu64Curr[0] = TSF_LOAD_SRCWIDTH(pstMem->u16SrcWidth);
    pu64Curr[1] = TSF_LOAD_SOURCEADDR(pstMem->u32SrcAddr);

    /* Dest Mem. */
    pu64Curr[2] = TSF_LOAD_DESTWIDTH(pstMem->u16DstWidth);
    pu64Curr[3] = TSF_LOAD_DESTADDR(pstMem->u32DstAddr);

    /* Image Size */
    pu64Curr[4] = TSF_LOAD_DEST_IMAGEWIDTH(pstMem->u16DstImgWidth);
    pu64Curr[5] = TSF_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /* LUT Params */
    pu64Curr[6] = TSF_LOAD_LUTADDR(pstLutCfg->u32Addr);
    pu64Curr[7] = TSF_LOAD_LUTWIDTH(pstLutCfg->u16Width);
    pu64Curr[8] = TSF_LOAD_LUTLINECNT(pstLutCfg->u16LineCnt);

    /* Color Params */
    /* Color format for Rotation should be redefined to fit to HW implemenation:
     *  modify color format 0-->1 and 1-->0 
     *  */
    pu64Curr[9]  = TSF_LOAD_COLORFMT((1 - (uint8_t)(pstTsfPrm->eDstColFmt)), (1 - (uint8_t)(pstTsfPrm->eSrcColFmt)));
    pu64Curr[10] = TSF_LOAD_PRECOLOR(pstTsfPrm->u32Color);

    /* alpha values */
    pu64Curr[11] = TSF_LOAD_SRCALPHA(pstTsfPrm->u8SrcAlphaVal);
    pu64Curr[12] = TSF_LOAD_DESTALPHA(pstTsfPrm->u8DstAlphaVal);

    /* transformation */
    pu64Curr[13] = TSF_TRANSF(pstTsfPrm->eTsfMode, pstTsfPrm->eFilterEn);

    pstCmdList->pu64Current = &pu64Curr[14];
    
    pstCmdList->u32UsedDoubleWords = 14U;
}

/* ....................................................................... */
void vTransf_ConfigTransfBlendOp(transf_mem_st* pstMem, transf_Lut_st* pstLutCfg,
                                 transf_PrmBlend_st* pstTsfPrm, ga_list_st* pstCmdList)

{
    uint64_t* pu64Curr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK
    uint32_t u32NeededDW = 15U;

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
    /* Source Mem. */
    pu64Curr[0] = TSF_LOAD_SRCWIDTH(pstMem->u16SrcWidth);
    pu64Curr[1] = TSF_LOAD_SOURCEADDR(pstMem->u32SrcAddr);

    /* Dest Mem. */
    pu64Curr[2] = TSF_LOAD_DESTWIDTH(pstMem->u16DstWidth);
    pu64Curr[3] = TSF_LOAD_DESTADDR(pstMem->u32DstAddr);

    /* Image Size */
    pu64Curr[4] = TSF_LOAD_DEST_IMAGEWIDTH(pstMem->u16DstImgWidth);
    pu64Curr[5] = TSF_LOAD_DESTLINECNT(pstMem->u16LineCnt);

    /* LUT Params */
    pu64Curr[6] = TSF_LOAD_LUTADDR(pstLutCfg->u32Addr);
    pu64Curr[7] = TSF_LOAD_LUTWIDTH(pstLutCfg->u16Width);
    pu64Curr[8] = TSF_LOAD_LUTLINECNT(pstLutCfg->u16LineCnt);

    /* Color Params */
    /* Color format for Rotation should be redefined to fit to HW implemenation:
     *  modify color format 0-->1 and 1-->0 
     *  */
    pu64Curr[9]  = TSF_LOAD_COLORFMT((1 - (uint8_t)(pstTsfPrm->eDstColFmt)), (1 - (uint8_t)(pstTsfPrm->eSrcColFmt)));
    pu64Curr[10] = TSF_LOAD_PRECOLOR(pstTsfPrm->u32Color);

    /* Fading factor values */
    pu64Curr[11] = TSF_LOAD_SRCFADEFACT(pstTsfPrm->u8FadingFctr);

    /* alpha values */
    pu64Curr[12] = TSF_LOAD_SRCALPHA(pstTsfPrm->u8SrcAlphaVal);
    pu64Curr[13] = TSF_LOAD_DESTALPHA(pstTsfPrm->u8DstAlphaVal);    

    /* transformation with blend */
    pu64Curr[14] = TSF_TRANSFB(pstTsfPrm->eTsfMode,
                               pstTsfPrm->eDstRedProt,
                               pstTsfPrm->eDstGreenProt,
                               pstTsfPrm->eDstBlueProt,
                               pstTsfPrm->eDstAlphaProt,
                               pstTsfPrm->eSrcRedFad,
                               pstTsfPrm->eSrcGreenFad,
                               pstTsfPrm->eSrcBlueFad,
                               pstTsfPrm->eSrcAlphaFad,
                               pstTsfPrm->eBldOrd,
                               pstTsfPrm->eFilterEn);

    pstCmdList->pu64Current = &pu64Curr[15];
    pstCmdList->u32UsedDoubleWords = 15;
}

/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/

/****************************************************************************/
/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: transf.c
**  $Revision: 1.13 $
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

