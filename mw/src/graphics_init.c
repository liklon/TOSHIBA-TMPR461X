/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Middleware graphic initialisation
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware-Bt
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.16 $
*   DATE        : $Date: 2015/06/10 13:39:12 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "ccr.h"
#include "layer.h"
#include "listmngr.h"
#include "gfunctions.h"
#include "graphics_init.h"
#include "mw_definitions.h"
#include "ga.h"
#include "png.h"
#include "pinconfig.h"
#include "dmc.h"
#include "config.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define MW_GRAPHICS_INIT_C_REVISION     "$Revision: 1.16 $"
#define MW_GRAPHICS_INIT_C_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/


/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8MW_GRAPHICS_INIT_C_REVISION[] = MW_GRAPHICS_INIT_C_REVISION;
static uint8_t au8MW_GRAPHICS_INIT_C_TAG[]      = MW_GRAPHICS_INIT_C_TAG;
static uint8_t au8MW_GRAPHICS_INIT_H_REVISION[] = MW_GRAPHICS_INIT_H_REVISION;
static uint8_t au8MW_GRAPHICS_INIT_H_TAG[]      = MW_GRAPHICS_INIT_H_TAG;


/**********************************************
*             Function definition             *
**********************************************/

/****************************************************************************/

void vGf_Graphics_Init_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                                  uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
   *pau8ModuleRevision = &au8MW_GRAPHICS_INIT_C_REVISION[0];
   *pau8ModuleTag      = &au8MW_GRAPHICS_INIT_C_TAG[0];
   *pau8HeaderRevision = &au8MW_GRAPHICS_INIT_H_REVISION[0];
   *pau8HeaderTag      = &au8MW_GRAPHICS_INIT_H_TAG[0];
}


/****************************************************************************/

void vGfInitGDC0(gf_gdc_config_st * pstGDC)
{
    gdc_sync_st       stSyncCfg;
    gf_disp_params_st stDispParams;

    /* configure GDC0 pins */
#if (GDCx0 == ON)
    vPinconfig_GDC0();
#endif

    /* Sync Config */
    stSyncCfg.eSyncType = (gdc_csync_e)pstGDC->stDispConf.u8VSYNCType;	/* VSYNC type */
    stSyncCfg.eVSyncPol = (gdc_pol_e)pstGDC->stDispConf.u8VSYNCPol;      /* Polarity of VSYNC */
    stSyncCfg.eHSyncPol = (gdc_pol_e)pstGDC->stDispConf.u8HSYNCPol;      /* Polarity of HSYNC */

    stSyncCfg.u8HsyncWdth  = (uint8_t)pstGDC->stDispConf.u16HSYNCWidth;  /* Width of HSYNC (dot-clocks) */
    stSyncCfg.u16HLineLen  = pstGDC->stDispConf.u16HPeriod;              /* Horizontal line length (dot-clocks) */
    stSyncCfg.u8VsyncWdth  = (uint8_t)pstGDC->stDispConf.u16VSYNCWidth;  /* Width of VSYNC (lines) */
    stSyncCfg.u16VFrameLen = pstGDC->stDispConf.u16VPeriod;              /* Vertical Frame length (lines) */

    /*** CLOCK ***/
    /* switch GDC0 module-clock on */
    i32CCR_EnableModuleClock(CCR_GDC_0, CCR_ENABLE);
    /* Set Frequency */
    i32CCR_SetClockFreq(CCR_GDC_0, pstGDC->stDispConf.eClockFrequency, pstGDC->stDispConf.eModulated);

    /* GDC Driver Initialize */
    vGDC_Init(GDC0);

    /* Background Color */
    vGDC_SetBgrColor(GDC0, pstGDC->stDispConf.u32BGColor);

    /*** DOT-CLOCK ***/
    /* Select clock source */
    vGDC_SelDotClkSrc(GDC0, (gdc_idc_e)pstGDC->stDispConf.u8ClkSource);
    /* Set Polarity */
    vGDC_SetDotClkPol(GDC0, (gdc_pol_e)pstGDC->stDispConf.u8DotClkPol);

    /*** SYNCHRONIZATION ***/
    /* Sync signals direction */
    vGDC_SetSyncDir(GDC0, (gdc_dir_e)pstGDC->stDispConf.u8SyncDir);
    /* Synchronization Config.*/
    vGDC_SyncConfig(GDC0, &stSyncCfg);
    /* HDISP Polarity */
    vGDC_SetPolHDisp(GDC0, (gdc_pol_e)pstGDC->stDispConf.u8HDISPPol);

    /* set display parameter */
    vGDC_SetDispConfigType(GDC0, pstGDC->stDispConf.eDispConfigType);
    i32GDC_SetDisplayStart(GDC0, pstGDC->stDispConf.u16HSYNCWidth + pstGDC->stDispConf.u16HBackPorch + 64U + pstGDC->stDispConf.u16DispStartX,
                                 pstGDC->stDispConf.u16VSYNCWidth + pstGDC->stDispConf.u16VBackPorch + 64U + pstGDC->stDispConf.u16DispStartY);
    i32GDC_SetDisplaySize(GDC0, pstGDC->stDispConf.u16DispWidth, pstGDC->stDispConf.u16DispHeight);

    /* Initialisation of layer structures */
    vGfRegisterLayers(GDC0, pstGDC);

    /* Layer initialization */
    stDispParams.u16VSYNCWidth = pstGDC->stDispConf.u16VSYNCWidth;
    stDispParams.u16VBackPorch = pstGDC->stDispConf.u16VBackPorch;
    stDispParams.u16HSYNCWidth = pstGDC->stDispConf.u16HSYNCWidth;
    stDispParams.u16HBackPorch = pstGDC->stDispConf.u16HBackPorch;
    if (pstGDC->stLayerConf_A.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC0, &stGDC0LayerA, &stDispParams);
    }

    if (pstGDC->stLayerConf_B.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC0, &stGDC0LayerB, &stDispParams);
    }

    if (pstGDC->stLayerConf_C.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC0, &stGDC0LayerC, &stDispParams);
    }

    if (pstGDC->stLayerConf_D.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC0, &stGDC0LayerD, &stDispParams);
    }

    if (pstGDC->stLayerConf_E.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC0, &stGDC0LayerE, &stDispParams);
    }

    /* Dithering settings */
    vGDC_SetDitheringMode(GDC0, pstGDC->stDispConf.eDithering);

    /* set layer viewing order */
    vGDC_SetLayerOrder(GDC0, pstGDC->stDispConf.eLayerOrder);

    /* Switch-On the GDC */
    vCCR_EnableGDC0Interface(CCR_ENABLE);
    vGDC_Switch(GDC0, GDC_ON);
}


/****************************************************************************/

void vGfInitGDC1(gf_gdc_config_st * pstGDC)
{
    gdc_sync_st       stSyncCfg;
    gf_disp_params_st stDispParams;

    /* configure GDC1 pins */
#if (GDCx1 == ON)
    vPinconfig_GDC1();
#endif

    /* Sync Config */
    stSyncCfg.eSyncType = (gdc_csync_e)pstGDC->stDispConf.u8VSYNCType;  /* VSYNC type */
    stSyncCfg.eVSyncPol = (gdc_pol_e)pstGDC->stDispConf.u8VSYNCPol;     /* Polarity of VSYNC */
    stSyncCfg.eHSyncPol = (gdc_pol_e)pstGDC->stDispConf.u8HSYNCPol;     /* Polarity of HSYNC */

    stSyncCfg.u8HsyncWdth  = (uint8_t)pstGDC->stDispConf.u16HSYNCWidth; /* Width of HSYNC (dot-clocks) */
    stSyncCfg.u16HLineLen  = pstGDC->stDispConf.u16HPeriod;             /* Horizontal line length (dot-clocks) */
    stSyncCfg.u8VsyncWdth  = (uint8_t)pstGDC->stDispConf.u16VSYNCWidth; /* Width of VSYNC (lines) */
    stSyncCfg.u16VFrameLen = pstGDC->stDispConf.u16VPeriod;             /* Vertical Frame length (lines) */

    /*** CLOCK ***/
    /* switch GDC1 module-clock on */
    i32CCR_EnableModuleClock(CCR_GDC_1, CCR_ENABLE);
    /* Set Frequency */
    i32CCR_SetClockFreq(CCR_GDC_1, pstGDC->stDispConf.eClockFrequency, pstGDC->stDispConf.eModulated);
    /* set synchronisation mode between GDC0 and GDC1 */
    vCCR_SetGDCSynchronisation(pstGDC->stDispConf.eGDC1Synchronisation);

    /* GDC Driver Initialize */
    vGDC_Init(GDC1);

    /* Background Color */
    vGDC_SetBgrColor(GDC1, pstGDC->stDispConf.u32BGColor);

    /*** DOT-CLOCK ***/
    /* Select clock source */
    vGDC_SelDotClkSrc(GDC1, (gdc_idc_e)pstGDC->stDispConf.u8ClkSource);
    /* Set Polarity */
    vGDC_SetDotClkPol(GDC1, (gdc_pol_e)pstGDC->stDispConf.u8DotClkPol);

    /*** SYNCHRONIZATION ***/
    /* Sync signals direction */
    vGDC_SetSyncDir(GDC1, (gdc_dir_e)pstGDC->stDispConf.u8SyncDir);
    /* Synchronization Config.*/
    vGDC_SyncConfig(GDC1, &stSyncCfg);
    /* HDISP Polarity */
    vGDC_SetPolHDisp(GDC1, (gdc_pol_e)pstGDC->stDispConf.u8HDISPPol);

    /* set display parameter */
    vGDC_SetDispConfigType(GDC1, pstGDC->stDispConf.eDispConfigType);
    i32GDC_SetDisplayStart(GDC1, pstGDC->stDispConf.u16HSYNCWidth + pstGDC->stDispConf.u16HBackPorch + 64U + pstGDC->stDispConf.u16DispStartX,
                                 pstGDC->stDispConf.u16VSYNCWidth + pstGDC->stDispConf.u16VBackPorch + 64U + pstGDC->stDispConf.u16DispStartY);
    i32GDC_SetDisplaySize(GDC1, pstGDC->stDispConf.u16DispWidth, pstGDC->stDispConf.u16DispHeight);

    /* initialisation of display layer */
    vGfRegisterLayers(GDC1, pstGDC);

    /* Layer initialization */
    stDispParams.u16VSYNCWidth = pstGDC->stDispConf.u16VSYNCWidth;
    stDispParams.u16VBackPorch = pstGDC->stDispConf.u16VBackPorch;
    stDispParams.u16HSYNCWidth = pstGDC->stDispConf.u16HSYNCWidth;
    stDispParams.u16HBackPorch = pstGDC->stDispConf.u16HBackPorch;
    if (pstGDC->stLayerConf_A.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC1, &stGDC1LayerA, &stDispParams);
    }

    if (pstGDC->stLayerConf_B.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC1, &stGDC1LayerB, &stDispParams);
    }

    if (pstGDC->stLayerConf_C.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC1, &stGDC1LayerC, &stDispParams);
    }

    if (pstGDC->stLayerConf_D.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC1, &stGDC1LayerD, &stDispParams);
    }

    if (pstGDC->stLayerConf_E.u8LayerActive == (uint8_t)ON)
    {
        vGfSetLayer(GDC1, &stGDC1LayerE, &stDispParams);
    }

    /* Dithering settings */
    vGDC_SetDitheringMode(GDC1, pstGDC->stDispConf.eDithering);

    /* set layer viewing order */
    vGDC_SetLayerOrder(GDC1, pstGDC->stDispConf.eLayerOrder);

    /* Switch-On the GDC */
    vCCR_EnableGDC1Interface(CCR_ENABLE);
    vGDC_Switch(GDC1, GDC_ON);
}


/****************************************************************************/

void vGfInitFG(gf_fg_config_st* pstFG)
{
    /* Configure pins */
#if (FRAMEGRABBER == ON)
    vPinconfig_FG();
#endif

    /* Enable FG clock */
    i32CCR_EnableModuleClock(CCR_FG, CCR_ENABLE);

    /* Buffer config */
    vFG_SetCaptureBuffers(&(pstFG->stFgBuffer));

    /* Set input configuration */
    pstFG->stFgInMode.stSwapYcbCr = pstFG->stFgSwapYcbCr;
    vFG_SetInputMode(&(pstFG->stFgInMode));

    /* Set output mode */
    vFG_SetOutputMode(&(pstFG->stFgOutMode));

    /* Set configuration signals */
    vFG_ConfigureFgSignal(&(pstFG->stFgSignal));

    /* Configure cropping */
    vFG_SetInputCropp(&(pstFG->stCroppConfig));
    vFG_CroppingEnable(pstFG->eCroppingEnable);

    /* Configure scaling */
    vFG_SetScalingFactors(pstFG->u32ScaleX, pstFG->u32ScaleY);

    /* Enable timing measurement */
    vFG_EnableMeasurements(&(pstFG->stMeasurement));

    /* Activate FG */
    vFG_FrameGrabberEnable(pstFG->eFGEnable);
}


/****************************************************************************/

void vGfInitGA(void)
{
    uint8_t u8Counter = 0U;
    uint32_t u32FilterCoefficients[64] =
    {
        0xffffffffU, 0xffffffffU, 0xffffffffU, 0xfefefefeU, 0xfefdfdfdU, 0xfdfcfcfcU, 0xfcfbfbfaU, 0xfafaf9f9U,
        0xf9f8f8f7U, 0xf7f6f6f5U, 0xf5f4f4f3U, 0xf3f2f2f1U, 0xf0f0efeeU, 0xeeededecU, 0xebeaeae9U, 0xe8e8e7e6U,
        0xe5e4e4e3U, 0xe2e1e0dfU, 0xdfdedddcU, 0xdbdad9d8U, 0xd7d6d5d5U, 0xd4d3d2d1U, 0xd0cfceccU, 0xcbcac9c8U,
        0xc7c6c5c4U, 0xc3c2c1bfU, 0xbebdbcbbU, 0xbab9b7b6U, 0xb5b4b3b1U, 0xb0afaeadU, 0xabaaa9a8U, 0xa6a5a4a2U,
        0xa1a09f9dU, 0x9c9b9998U, 0x97969493U, 0x92908f8eU, 0x8c8b8a88U, 0x87868483U, 0x81807f7dU, 0x7c7b7978U,
        0x77757472U, 0x71706e6dU, 0x6c6a6968U, 0x66656362U, 0x615f5e5dU, 0x5b5a5857U, 0x56545352U, 0x504f4e4cU,
        0x4b4a4847U, 0x46444342U, 0x403f3e3cU, 0x3b3a3937U, 0x36353332U, 0x31302e2dU, 0x2c2b2928U, 0x27262423U,
        0x2221201eU, 0x1d1c1b1aU, 0x18171615U, 0x14131210U, 0x0f0e0d0cU, 0x0b0a0908U, 0x07060504U, 0x03020100U
    };

    /* Enable GA Module Clocks */
    i32CCR_EnableModuleClock(CCR_GA, CCR_ENABLE);

    /* Enable Graphic Accelerator */
    vGA_Enable(GA_EN);

    /* disable read ahead */
    vGA_ReadAheadEnable(GA_DIS);

    /* initialisation of filter coefficients of drawing engine  */
    for (u8Counter=0U; u8Counter<64U; u8Counter++)
    {
        boDrw_SetFilterCoefDrawEngine(u8Counter, u32FilterCoefficients[u8Counter]);
    }
}


/****************************************************************************/

void vGfInitGfxMiddleWare(gf_gdc_config_st* pstGDC0, gf_gdc_config_st* pstGDC1, gf_fg_config_st* pstFG)
{
    /* Init GA */
    vGfInitGA();

    /* Init PNG-decoder */
    i32CCR_EnableModuleClock(CCR_PNG, CCR_ENABLE);
    vPNG_Init();
    vSetEarlyWriteResponse(DMC_ENABLE);

    vGfInitMWStateVariable();

    /* Initialize GA list management */
    vGfListInit();

    /* configure GDC0 */
    if (pstGDC0->u8GDCActive == (uint8_t)ON)
    {
        vGfInitGDC0(pstGDC0);
    }

    /* configure GDC1 */
    if (pstGDC1->u8GDCActive == (uint8_t)ON)
    {
        vGfInitGDC1(pstGDC1);
    }

    /* configure FG */
    if (pstFG->u8FGActive == (uint8_t)ON)
    {
        vGfInitFG(pstFG);
    }
}

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
