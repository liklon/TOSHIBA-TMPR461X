/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Board specific initialization routines
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : System
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.2 $
*   DATE        : $Date: 2015/10/16 12:19:36 $
*   TAG         : $Name: Demo_Version_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                       /* Core specific primitive type definitions */
#include "boardcfg.h"                       /* Own definitions and prototypes */
#include "ccr.h"                            /* CCR */
#include "config.h"                         
#include "ccr.h"                            
#include "dmc.h"     
#include "gpio.h"                           
#include "qspi.h"                           
#include "gdc.h"
#include "fbuffer.h"
#include "boardcfg.h"
#include "core.h"
#include "dispparams.h"
#include "graphics_init.h"
#include "pinconfig.h"
#include "fg.h"

/*********************************************/


/**********************************************
*             Constants & Macros              *
**********************************************/


/*********************************************/


/**********************************************
*             Function definition             *
**********************************************/

/***************************************************************************/
void vInitGraphicsSystem(void)
{
    gf_gdc_config_st stGDC0;
    gf_gdc_config_st stGDC1;
    gf_fg_config_st  stFG;

    /* configuration for GDC0 */
    stGDC0.u8GDCActive = GDCx0;

    stGDC0.stDispConf.u8DispRes       = DISPLAY_RESOLUTION_0;
    stGDC0.stDispConf.u16DispStartX   = 0;
    stGDC0.stDispConf.u16DispStartY   = 0;
    stGDC0.stDispConf.u16DispWidth    = GDC0_DISPLAY_WIDTH;
    stGDC0.stDispConf.u16DispHeight   = GDC0_DISPLAY_HEIGHT;
    stGDC0.stDispConf.eDispConfigType = GDC_USE_DISP_SET_BY_LAYA;

    stGDC0.stDispConf.u8VSYNCType     = GDC_VSYNC;
#if (OUTPUT_DEVICE == 0)
    stGDC0.stDispConf.u8VSYNCPol      = GDC_POS;
#else
    stGDC0.stDispConf.u8VSYNCPol      = GDC_NEG;
#endif
    stGDC0.stDispConf.u16VSYNCWidth   = VPulseWidth_0;
    stGDC0.stDispConf.u16VPeriod      = VPeriod_0;
    stGDC0.stDispConf.u16VBackPorch   = VBackPorch_0;

#if (OUTPUT_DEVICE == 0)
    stGDC0.stDispConf.u8HSYNCPol      = GDC_POS;
#else
    stGDC0.stDispConf.u8HSYNCPol      = GDC_NEG;
#endif
    stGDC0.stDispConf.u16HSYNCWidth   = HPulseWidth_0;
    stGDC0.stDispConf.u16HPeriod      = HPeriod_0;
    stGDC0.stDispConf.u16HBackPorch   = HBackPorch_0;

    stGDC0.stDispConf.u8HDISPPol      = GDC_POS;

    stGDC0.stDispConf.u32BGColor      = 0x000000;
    stGDC0.stDispConf.u8SyncDir       = GDC_OUTPUT;

    stGDC0.stDispConf.u8DotClkPol     = GDC_POS;
    stGDC0.stDispConf.u8ClkSource     = GDC_DOTCLK_INT;
    stGDC0.stDispConf.eClockFrequency = (ccr_clk_freq_e)ClockFrequency_0;
    stGDC0.stDispConf.eModulated      = CCR_NON_MODULATED;

    stGDC0.stDispConf.eDithering      = GDC_DITHERING_MAGIC_SQR_SUBPIX_ENABLED;
    stGDC0.stDispConf.eLayerOrder     = GDC_ABCDE;
#if GDC0_LAYER_A
    /* Setting Layer A *******************************************************/
    stGDC0.stLayerConf_A.u8LayerActive   = GDC0_LAYER_A;
    stGDC0.stLayerConf_A.u8DisplayFormat = GDC0_LAYER_A_COLOR_FORMAT;
    stGDC0.stLayerConf_A.u8DoubleBuffer  = GDC0_LAYER_A_DOUBLEFUFFERING;
    stGDC0.stLayerConf_A.u8Alpha         = 0xff;
    stGDC0.stLayerConf_A.u16StartX       = GDC0_LAYERA_STARTX;
    stGDC0.stLayerConf_A.u16StartY       = GDC0_LAYERA_STARTY;
    stGDC0.stLayerConf_A.u16Width        = GDC0_LAYERA_WIDTH;
    stGDC0.stLayerConf_A.u16Height       = GDC0_LAYERA_HEIGHT;
    stGDC0.stLayerConf_A.u32FB0StartAddress = PHYSICAL(&FBuffRGBA_GDC0_A0[0]);
  #if GDC0_LAYER_A_DOUBLEFUFFERING
    stGDC0.stLayerConf_A.u32FB1StartAddress = PHYSICAL(&FBuffRGBA_GDC0_A1[0]);
  #else
    stGDC0.stLayerConf_A.u32FB1StartAddress = 0;
  #endif    
#endif
#if GDC0_LAYER_B
    /* Setting Layer B *******************************************************/
    stGDC0.stLayerConf_B.u8LayerActive   = GDC0_LAYER_B;
    stGDC0.stLayerConf_B.u8DisplayFormat = GDC0_LAYER_B_COLOR_FORMAT;
    stGDC0.stLayerConf_B.u8DoubleBuffer  = GDC0_LAYER_B_DOUBLEFUFFERING;
    stGDC0.stLayerConf_B.u8Alpha         = 0xFF;
    stGDC0.stLayerConf_B.u16StartX       = GDC0_LAYERB_STARTX;
    stGDC0.stLayerConf_B.u16StartY       = GDC0_LAYERB_STARTY;
    stGDC0.stLayerConf_B.u16Width        = GDC0_LAYERB_WIDTH;
    stGDC0.stLayerConf_B.u16Height       = GDC0_LAYERB_HEIGHT;
    stGDC0.stLayerConf_B.u32FB0StartAddress = PHYSICAL(&FBuffRGBA_GDC0_B0[0]);
  #if GDC0_LAYER_B_DOUBLEFUFFERING
    stGDC0.stLayerConf_B.u32FB1StartAddress = PHYSICAL(&FBuffRGBA_GDC0_B1[0]);
  #else
    stGDC0.stLayerConf_B.u32FB1StartAddress = 0;
  #endif    
#endif
#if GDC0_LAYER_C
    /* Setting Layer C *******************************************************/
    stGDC0.stLayerConf_C.u8LayerActive   = GDC0_LAYER_C;
    stGDC0.stLayerConf_C.u8DisplayFormat = GDC0_LAYER_C_COLOR_FORMAT;
    stGDC0.stLayerConf_C.u8DoubleBuffer  = GDC0_LAYER_C_DOUBLEFUFFERING;
    stGDC0.stLayerConf_C.u8Alpha         = 0xFF;
    stGDC0.stLayerConf_C.u16StartX       = GDC0_LAYERC_STARTX;
    stGDC0.stLayerConf_C.u16StartY       = GDC0_LAYERC_STARTY;
    stGDC0.stLayerConf_C.u16Width        = GDC0_LAYERC_WIDTH;
    stGDC0.stLayerConf_C.u16Height       = GDC0_LAYERC_HEIGHT;
    stGDC0.stLayerConf_C.u32FB0StartAddress = PHYSICAL(&FBuffRGBA_GDC0_C0[0]);
  #if GDC0_LAYER_C_DOUBLEFUFFERING
    stGDC0.stLayerConf_C.u32FB1StartAddress = PHYSICAL(&FBuffRGBA_GDC0_C1[0]);
  #else
    stGDC0.stLayerConf_C.u32FB1StartAddress = 0;
  #endif    
#endif
#if GDC0_LAYER_D
    /* Setting Layer D *******************************************************/
    stGDC0.stLayerConf_D.u8LayerActive   = GDC0_LAYER_D;
    stGDC0.stLayerConf_D.u8DisplayFormat = GDC0_LAYER_D_COLOR_FORMAT;
    stGDC0.stLayerConf_D.u8DoubleBuffer  = GDC0_LAYER_D_DOUBLEFUFFERING;
    stGDC0.stLayerConf_D.u8Alpha         = 0xFF;
    stGDC0.stLayerConf_D.u16StartX       = GDC0_LAYERD_STARTX;
    stGDC0.stLayerConf_D.u16StartY       = GDC0_LAYERD_STARTY;
    stGDC0.stLayerConf_D.u16Width        = GDC0_LAYERD_WIDTH;
    stGDC0.stLayerConf_D.u16Height       = GDC0_LAYERD_HEIGHT;
    stGDC0.stLayerConf_D.u32FB0StartAddress = PHYSICAL(&FBuffRGBA_GDC0_D0[0]);
  #if GDC0_LAYER_D_DOUBLEFUFFERING
    stGDC0.stLayerConf_D.u32FB1StartAddress = PHYSICAL(&FBuffRGBA_GDC0_D1[0]);
  #else
    stGDC0.stLayerConf_D.u32FB1StartAddress = 0;
  #endif    
#endif
#if GDC0_LAYER_E
    /* Setting Layer E *******************************************************/
    stGDC0.stLayerConf_E.u8LayerActive   = GDC0_LAYER_E;
    stGDC0.stLayerConf_E.u8DisplayFormat = GDC0_LAYER_E_COLOR_FORMAT;
    stGDC0.stLayerConf_E.u8DoubleBuffer  = GDC0_LAYER_E_DOUBLEFUFFERING;
    stGDC0.stLayerConf_E.u8Alpha         = 0xFF;
    stGDC0.stLayerConf_E.u16StartX       = GDC0_LAYERE_STARTX;
    stGDC0.stLayerConf_E.u16StartY       = GDC0_LAYERE_STARTY;
    stGDC0.stLayerConf_E.u16Width        = GDC0_LAYERE_WIDTH;
    stGDC0.stLayerConf_E.u16Height       = GDC0_LAYERE_HEIGHT;
    stGDC0.stLayerConf_E.u32FB0StartAddress = PHYSICAL(&FBuffRGBA_GDC0_E0[0]);
  #if GDC0_LAYER_E_DOUBLEFUFFERING
    stGDC0.stLayerConf_E.u32FB1StartAddress = PHYSICAL(&FBuffRGBA_GDC0_E1[0]);
  #else
    stGDC0.stLayerConf_E.u32FB1StartAddress = 0;
  #endif    
#endif

    /* configuration for GDC1 */
    stGDC1.u8GDCActive = GDCx1;
#if GDCx1    
    stGDC1.stDispConf.u8DispRes       = DISPLAY_RESOLUTION_1;
    stGDC1.stDispConf.u16DispStartX   = 64;
    stGDC1.stDispConf.u16DispStartY   = 64;
    stGDC1.stDispConf.u16DispWidth    = GDC1_DISPLAY_WIDTH;
    stGDC1.stDispConf.u16DispHeight   = GDC1_DISPLAY_HEIGHT;
    stGDC1.stDispConf.eDispConfigType = GDC_USE_DISP_SET_BY_LAYA;

    stGDC1.stDispConf.eGDC1Synchronisation = CCR_GDC_SYNC_INDEPENDANT;
    
    stGDC1.stDispConf.u8VSYNCType     = GDC_VSYNC;
#if (OUTPUT_DEVICE == 0)
    stGDC1.stDispConf.u8VSYNCPol      = GDC_POS;
#else
    stGDC1.stDispConf.u8VSYNCPol      = GDC_NEG;
#endif
    stGDC1.stDispConf.u16VSYNCWidth   = VPulseWidth_1;
    stGDC1.stDispConf.u16VPeriod      = VPeriod_1;
    stGDC1.stDispConf.u16VBackPorch   = VBackPorch_1;

#if (OUTPUT_DEVICE == 0)
    stGDC1.stDispConf.u8HSYNCPol      = GDC_POS;
#else
    stGDC1.stDispConf.u8HSYNCPol      = GDC_NEG;
#endif
    stGDC1.stDispConf.u16HSYNCWidth   = HPulseWidth_1;
    stGDC1.stDispConf.u16HPeriod      = HPeriod_1;
    stGDC1.stDispConf.u16HBackPorch   = HBackPorch_1;

    stGDC1.stDispConf.u8HDISPPol      = GDC_POS;

    stGDC1.stDispConf.u32BGColor      = 0x000000;
    stGDC1.stDispConf.u8SyncDir       = GDC_OUTPUT;

    stGDC1.stDispConf.u8DotClkPol     = GDC_POS;
    stGDC1.stDispConf.u8ClkSource     = GDC_DOTCLK_INT;
    stGDC1.stDispConf.eClockFrequency = (ccr_clk_freq_e)ClockFrequency_1;
    stGDC1.stDispConf.eModulated      = CCR_NON_MODULATED;

    stGDC1.stDispConf.eDithering      = GDC_DITHERING_MAGIC_SQR_SUBPIX_ENABLED;
    stGDC1.stDispConf.eLayerOrder     = GDC_ABCDE;

    stGDC1.stLayerConf_A.u8LayerActive   = GDC1_LAYER_A;
    stGDC1.stLayerConf_A.u8DisplayFormat = GDC1_LAYER_A_COLOR_FORMAT;
    stGDC1.stLayerConf_A.u8DoubleBuffer  = GDC1_LAYER_A_DOUBLEFUFFERING;
    stGDC1.stLayerConf_A.u8Alpha         = 0xFF;
    stGDC1.stLayerConf_A.u16StartX       = GDC1_LAYERA_STARTX;
    stGDC1.stLayerConf_A.u16StartY       = GDC1_LAYERA_STARTY;
    stGDC1.stLayerConf_A.u16Width        = GDC1_LAYERA_WIDTH;
    stGDC1.stLayerConf_A.u16Height       = GDC1_LAYERA_HEIGHT;
    stGDC1.stLayerConf_A.u32FB0StartAddress = PHYSICAL(&FBuffRGBA_GDC1_A0[0]);
    stGDC1.stLayerConf_A.u32FB1StartAddress = PHYSICAL(&FBuffRGBA_GDC1_A1[0]);

    stGDC1.stLayerConf_B.u8LayerActive   = GDC1_LAYER_B;
    stGDC1.stLayerConf_B.u8DisplayFormat = GDC1_LAYER_B_COLOR_FORMAT;
    stGDC1.stLayerConf_B.u8DoubleBuffer  = GDC1_LAYER_B_DOUBLEFUFFERING;
    stGDC1.stLayerConf_B.u8Alpha         = 0xFF;
    stGDC1.stLayerConf_B.u16StartX       = GDC1_LAYERB_STARTX;
    stGDC1.stLayerConf_B.u16StartY       = GDC1_LAYERB_STARTY;
    stGDC1.stLayerConf_B.u16Width        = GDC1_LAYERB_WIDTH;
    stGDC1.stLayerConf_B.u16Height       = GDC1_LAYERB_HEIGHT;
    stGDC1.stLayerConf_B.u32FB0StartAddress = 0;
    stGDC1.stLayerConf_B.u32FB1StartAddress = 0;

    stGDC1.stLayerConf_C.u8LayerActive   = GDC1_LAYER_C;
    stGDC1.stLayerConf_C.u8DisplayFormat = GDC1_LAYER_C_COLOR_FORMAT;
    stGDC1.stLayerConf_C.u8DoubleBuffer  = GDC1_LAYER_C_DOUBLEFUFFERING;
    stGDC1.stLayerConf_C.u8Alpha         = 0xFF;
    stGDC1.stLayerConf_C.u16StartX       = GDC1_LAYERC_STARTX;
    stGDC1.stLayerConf_C.u16StartY       = GDC1_LAYERC_STARTY;
    stGDC1.stLayerConf_C.u16Width        = GDC1_LAYERC_WIDTH;
    stGDC1.stLayerConf_C.u16Height       = GDC1_LAYERC_HEIGHT;
    stGDC1.stLayerConf_C.u32FB0StartAddress = 0;
    stGDC1.stLayerConf_C.u32FB1StartAddress = 0;

    stGDC1.stLayerConf_D.u8LayerActive   = GDC1_LAYER_D;
    stGDC1.stLayerConf_D.u8DisplayFormat = GDC1_LAYER_D_COLOR_FORMAT;
    stGDC1.stLayerConf_D.u8DoubleBuffer  = GDC1_LAYER_D_DOUBLEFUFFERING;
    stGDC1.stLayerConf_D.u8Alpha         = 0xFF;
    stGDC1.stLayerConf_D.u16StartX       = GDC1_LAYERD_STARTX;
    stGDC1.stLayerConf_D.u16StartY       = GDC1_LAYERD_STARTY;
    stGDC1.stLayerConf_D.u16Width        = GDC1_LAYERD_WIDTH;
    stGDC1.stLayerConf_D.u16Height       = GDC1_LAYERD_HEIGHT;
    stGDC1.stLayerConf_D.u32FB0StartAddress = 0;
    stGDC1.stLayerConf_D.u32FB1StartAddress = 0;

    stGDC1.stLayerConf_E.u8LayerActive   = GDC1_LAYER_E;
    stGDC1.stLayerConf_E.u8DisplayFormat = GDC1_LAYER_E_COLOR_FORMAT;
    stGDC1.stLayerConf_E.u8DoubleBuffer  = GDC1_LAYER_E_DOUBLEFUFFERING;
    stGDC1.stLayerConf_E.u8Alpha         = 0xFF;
    stGDC1.stLayerConf_E.u16StartX       = GDC1_LAYERE_STARTX;
    stGDC1.stLayerConf_E.u16StartY       = GDC1_LAYERE_STARTY;
    stGDC1.stLayerConf_E.u16Width        = GDC1_LAYERE_WIDTH;
    stGDC1.stLayerConf_E.u16Height       = GDC1_LAYERE_HEIGHT;
    stGDC1.stLayerConf_E.u32FB0StartAddress = 0;
    stGDC1.stLayerConf_E.u32FB1StartAddress = 0;
#endif

    /* configuration of FG */
    stFG.u8FGActive = GDC_OFF;

    stFG.stFgBuffer.u32CbaBufferAddr1 = 0x0;
    stFG.stFgBuffer.u32CbaBufferAddr2 = 0x0;
    stFG.stFgBuffer.u32CbaBufferAddr3 = 0x0;
    stFG.stFgBuffer.eCbactUsedBuffer  = FG_SINGEL_BUFFERING;
    stFG.stFgBuffer.u16LorLineOffset  = GDC0_LAYERA_WIDTH;

    stFG.stFgSwapYcbCr.eScbCr   = FG_SCBCR_CB_CR;
    stFG.stFgSwapYcbCr.eSycbcr  = FG_SYCBCR_Y2Y_CBCR2CBCR_CHANNEL;

    stFG.stFgInMode.eBwex       = FG_BWEX_INTERPRET_CAMERAINPUT;
    stFG.stFgInMode.eComd       = FG_INP_COLORMODE_RGB;
    stFG.stFgInMode.eInterlMode = FG_INT_NORMAL_OPERATION;
    stFG.stFgInMode.eNvmd       = FG_VIDEO_DATA;
    stFG.stFgInMode.eRgb16_24   = FG_RGB888;
    stFG.stFgInMode.eRgbPa      = FG_RGB_PARALLEL;
    stFG.stFgInMode.u8Alpha     = 0xFF;

    stFG.stFgOutMode.eDeInterl       = FG_DINT_NO_DEINTERLACED;
    stFG.stFgOutMode.eMonochrome     = FG_MONO_COLOUR;
    stFG.stFgOutMode.eOutputSelector = FG_YCBRO_RGB;
    stFG.stFgOutMode.eRgbFormat      = FG_RRGB_RGBA32;
    stFG.stFgOutMode.eYcbcr2RgbConv  = FG_YCBCR2RGB_ITU601;

    stFG.stFgSignal.eHdact = FG_HIGH_ACTIVE;
    stFG.stFgSignal.eHsact = FG_HIGH_ACTIVE;
    stFG.stFgSignal.eVsact = FG_HIGH_ACTIVE;
    stFG.stFgSignal.eNegPc = FG_NEGPC_NEG_EDGE;
    stFG.stFgSignal.eNfOdd = FG_NFODD_LOWSIGNAL_FIRST;
    stFG.stFgSignal.eOnec  = FG_ONEC_DATA_OVER_BOTH_INPCHANNELS;
    stFG.stFgSignal.eUdsp  = FG_UDSP_HDISP_USED;
    stFG.stFgSignal.eUsync = FG_USYNC_HVSYNC_USED;

    stFG.stCroppConfig.u16ItrHorizWait   = 0;
    stFG.stCroppConfig.u16ItrVertWait    = 0;
    stFG.stCroppConfig.u16HcrCroppLeftX  = 0;  
    stFG.stCroppConfig.u16VcrCroppTopY   = 0;  
    stFG.stCroppConfig.u16HcrCroppWidth  = 640;
    stFG.stCroppConfig.u16VcrCroppHeight = 480;
    stFG.eCroppingEnable                 = FG_ENABLE;

    stFG.u32ScaleX = 0x800;
    stFG.u32ScaleY = 0x800;

    stFG.stMeasurement.eVcr   = FG_ENABLE;
    stFG.stMeasurement.eHcr   = FG_ENABLE;
    stFG.stMeasurement.eVspwr = FG_ENABLE;
    stFG.stMeasurement.eHspwr = FG_ENABLE;
    stFG.stMeasurement.eHdisp = FG_ENABLE;

    stFG.eFGEnable = FG_DISABLE;

    // Initialize the middleware
    vGfInitGfxMiddleWare(&stGDC0, &stGDC1, &stFG);
}


/****************************************************************************/
static void vInterruptEnable(void)
{
    /* Enable the VIC port(code from Init.s of verification ENV) */
    asm_enable_core_vic_port();

    /* enable interrupts in the core */
    asm_enable_core_int();
    asm_enable_core_fast_int();
}


/****************************************************************************/
#ifndef CAPBT_ROMEXEC
static void vConfigureQSPI0ReadAccess(void)
{
    qspic_directconfig_st stDirConf;
    ccr_clk_freq_e eClocFreq;
    ccr_modulated_clk_e eModulationType;
    qspic_prgconfig_st stPrgConfig;

    i32AssignQSPISettings((qspi_dev_type_e)QSPI_DEVICE, 0x0200, &eClocFreq, &eModulationType, &stDirConf, &stPrgConfig);
    eClocFreq = CCR_CLKDIV_90_0MHz;

    /* Configure QSPI clock */
    i32CCR_EnableModuleClock(CCR_QSPI_0, CCR_ENABLE);
    i32CCR_SetClockFreq(CCR_QSPI_0, eClocFreq, eModulationType);    

    /* Configure direct mode */
    i32QSPIC_ConfigureDirectControl(QSPIC_CNTRL_0, QSPIC_DEV_0, &stDirConf);

    /* Configure program mode */
    i32QSPIC_ConfigurePrgControl(QSPIC_CNTRL_0, &stPrgConfig);

    /* Configure the IO pins */
    i32GPIO_EnableLatchFunction(PORT_QSPI0_SCLK, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_QSPI0_SCLK, PORT_QSPI0_SCLK_AS_QSPI0_SCLK);
    i32GPIO_SetOutputResistance(PORT_QSPI0_SCLK, GPIO_OUTPUT_RESISTANCE_25);
    i32GPIO_EnablePullDown(PORT_QSPI0_SCLK, GPIO_DISABLE);

    i32GPIO_EnableLatchFunction(PORT_QSPI0_CS0, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_QSPI0_CS0, PORT_QSPI0_CS0_AS_QSPI0_CS0);
    i32GPIO_SetOutputResistance(PORT_QSPI0_CS0, GPIO_OUTPUT_RESISTANCE_25);
    i32GPIO_EnablePullDown(PORT_QSPI0_CS0, GPIO_DISABLE);

    i32GPIO_EnableLatchFunction(PORT_QSPI0_SIO0, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_QSPI0_SIO0, PORT_QSPI0_SIO0_AS_QSPI0_SIO0);
    i32GPIO_SetOutputResistance(PORT_QSPI0_SIO0, GPIO_OUTPUT_RESISTANCE_25);
    i32GPIO_EnablePullDown(PORT_QSPI0_SIO0, GPIO_DISABLE);

    i32GPIO_EnableLatchFunction(PORT_QSPI0_SIO1, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_QSPI0_SIO1, PORT_QSPI0_SIO1_AS_QSPI0_SIO1);
    i32GPIO_SetOutputResistance(PORT_QSPI0_SIO1, GPIO_OUTPUT_RESISTANCE_25);
    i32GPIO_EnablePullDown(PORT_QSPI0_SIO1, GPIO_DISABLE);

    i32GPIO_EnableLatchFunction(PORT_QSPI0_SIO2, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_QSPI0_SIO2, PORT_QSPI0_SIO2_AS_QSPI0_SIO2);
    i32GPIO_SetOutputResistance(PORT_QSPI0_SIO2, GPIO_OUTPUT_RESISTANCE_25);
    i32GPIO_EnablePullDown(PORT_QSPI0_SIO2, GPIO_DISABLE);

    i32GPIO_EnableLatchFunction(PORT_QSPI0_SIO3, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_QSPI0_SIO3, PORT_QSPI0_SIO3_AS_QSPI0_SIO3);
    i32GPIO_SetOutputResistance(PORT_QSPI0_SIO3, GPIO_OUTPUT_RESISTANCE_25);
    i32GPIO_EnablePullDown(PORT_QSPI0_SIO3, GPIO_DISABLE);
}

#endif /* CAPBT_ROMEXEC */


/****************************************************************************/

void vBoardCfg(void)
{   
#ifndef CAPBT_ROMEXEC
    /* Graphics need to be copied from QSPI, thus direct mapping is required */
    vConfigureQSPI0ReadAccess();
#endif /* CAPBT_ROMEXEC */    

    vInterruptEnable();
}

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

