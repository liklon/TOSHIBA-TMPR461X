/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Middleware layer handling
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.11 $
*   DATE        : $Date: 2015/07/03 09:17:05 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "layer.h"
#include "mw_definitions.h"
#include "gfunctions.h"
#include "config.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define MW_LAYER_C_REVISION     "$Revision: 1.11 $"
#define MW_LAYER_C_TAG          "$Name: Graphic_Middleware_V1_5 $"

/*********************************************/

#if (DISPLAY_RESOLUTION_0 == RES_960_720_50) && (DISPLAY_RESOLUTION_1 == RES_960_720_50)
    #define DUAL_GDC   ON
#else
    #define DUAL_GDC   OFF
#endif

/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8MW_LAYER_C_REVISION[] = MW_LAYER_C_REVISION;
static uint8_t au8MW_LAYER_C_TAG[]      = MW_LAYER_C_TAG;
static uint8_t au8MW_LAYER_H_REVISION[] = MW_LAYER_H_REVISION;
static uint8_t au8MW_LAYER_H_TAG[]      = MW_LAYER_H_TAG;

/*********************************************/

/**********************************************
*            Global variables                 *
**********************************************/

/* Layer description structures */
/* GDC0 */
gf_layer_st stGDC0LayerA;		/* Layer A */
gf_layer_st stGDC0LayerB;		/* Layer B */
gf_layer_st stGDC0LayerC;		/* Layer C */
gf_layer_st stGDC0LayerD;		/* Layer D */
gf_layer_st stGDC0LayerE;		/* Layer E */

/* GDC1 */
gf_layer_st stGDC1LayerA;		/* Layer A */
gf_layer_st stGDC1LayerB;		/* Layer B */
gf_layer_st stGDC1LayerC;		/* Layer C */
gf_layer_st stGDC1LayerD;		/* Layer D */
gf_layer_st stGDC1LayerE;		/* Layer E */

/**********************************************
*             Function definition             *
**********************************************/

/****************************************************************************/

void vGf_Layer_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                          uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag)
{
    *pau8ModuleRevision = &au8MW_LAYER_C_REVISION[0];
    *pau8ModuleTag      = &au8MW_LAYER_C_TAG[0];
    *pau8HeaderRevision = &au8MW_LAYER_H_REVISION[0];
    *pau8HeaderTag      = &au8MW_LAYER_H_TAG[0];
}

/****************************************************************************/

void vGfRegisterLayers(gdc_ch_e eGDCNumber, gf_gdc_config_st * stGDC)
{
    if(eGDCNumber == GDC0)
    {
	      /* configuration for GDC0 */

        /* Layer A */
        stGDC0LayerA.eLayer    = GDC_LAYER_A;
        stGDC0LayerA.u16StartX = stGDC->stLayerConf_A.u16StartX;
        stGDC0LayerA.u16StartY = stGDC->stLayerConf_A.u16StartY;
        stGDC0LayerA.u8Alpha   = stGDC->stLayerConf_A.u8Alpha;
        stGDC0LayerA.u16Width  = stGDC->stLayerConf_A.u16Width;
        stGDC0LayerA.u16Height = stGDC->stLayerConf_A.u16Height;

        stGDC0LayerA.stDispFB.u32Address = stGDC->stLayerConf_A.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERA_FULL_SIZE)
        stGDC0LayerA.stDispFB.u16Width   = stGDC0LayerA.u16Width + GDC1_LAYERA_WIDTH;
#else
        stGDC0LayerA.stDispFB.u16Width   = stGDC0LayerA.u16Width;
#endif
        stGDC0LayerA.stDispFB.u16Height  = stGDC0LayerA.u16Height;
        if(stGDC->stLayerConf_A.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC0LayerA.stWriteFB.u32Address = stGDC->stLayerConf_A.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERA_FULL_SIZE)
            stGDC0LayerA.stWriteFB.u16Width   = stGDC0LayerA.u16Width + GDC1_LAYERA_WIDTH;
#else
            stGDC0LayerA.stWriteFB.u16Width   = stGDC0LayerA.u16Width;
#endif
            stGDC0LayerA.stWriteFB.u16Height  = stGDC0LayerA.u16Height;
        }

        if (stGDC->stLayerConf_A.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC0LayerA.eFormat = GDC_RGB16;
            stGDC0LayerA.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_A.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerA.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC0LayerA.eFormat = GDC_RGBA32;
            stGDC0LayerA.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_A.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerA.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }

        /* Layer B */
        stGDC0LayerB.eLayer    = GDC_LAYER_B;
        stGDC0LayerB.u16StartX = stGDC->stLayerConf_B.u16StartX;
        stGDC0LayerB.u16StartY = stGDC->stLayerConf_B.u16StartY;
        stGDC0LayerB.u8Alpha   = stGDC->stLayerConf_B.u8Alpha;
        stGDC0LayerB.u16Width  = stGDC->stLayerConf_B.u16Width;
        stGDC0LayerB.u16Height = stGDC->stLayerConf_B.u16Height;

        stGDC0LayerB.stDispFB.u32Address = stGDC->stLayerConf_B.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERB_FULL_SIZE)
        stGDC0LayerB.stDispFB.u16Width   = stGDC0LayerB.u16Width + GDC1_LAYERB_WIDTH;
#else   
        stGDC0LayerB.stDispFB.u16Width   = stGDC0LayerB.u16Width;
#endif
        stGDC0LayerB.stDispFB.u16Height  = stGDC0LayerB.u16Height;
        if(stGDC->stLayerConf_B.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC0LayerB.stWriteFB.u32Address = stGDC->stLayerConf_B.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERB_FULL_SIZE)
            stGDC0LayerB.stWriteFB.u16Width   = stGDC0LayerB.u16Width + GDC1_LAYERB_WIDTH;
#else       
            stGDC0LayerB.stWriteFB.u16Width   = stGDC0LayerB.u16Width;
#endif
            stGDC0LayerB.stWriteFB.u16Height  = stGDC0LayerB.u16Height;
            
        }
        
        if (stGDC->stLayerConf_B.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC0LayerB.eFormat = GDC_RGB16;
            stGDC0LayerB.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_B.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerB.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC0LayerB.eFormat = GDC_RGBA32;
            stGDC0LayerB.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_B.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerB.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }

        /* Layer C */
        stGDC0LayerC.eLayer    = GDC_LAYER_C;
        stGDC0LayerC.u16StartX = stGDC->stLayerConf_C.u16StartX;
        stGDC0LayerC.u16StartY = stGDC->stLayerConf_C.u16StartY;
        stGDC0LayerC.u8Alpha   = stGDC->stLayerConf_C.u8Alpha;
        stGDC0LayerC.u16Width  = stGDC->stLayerConf_C.u16Width;
        stGDC0LayerC.u16Height = stGDC->stLayerConf_C.u16Height;

        stGDC0LayerC.stDispFB.u32Address = stGDC->stLayerConf_C.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERC_FULL_SIZE)
        stGDC0LayerC.stDispFB.u16Width   = stGDC0LayerC.u16Width + GDC1_LAYERC_WIDTH;
#else
        stGDC0LayerC.stDispFB.u16Width   = stGDC0LayerC.u16Width;
#endif
        stGDC0LayerC.stDispFB.u16Height  = stGDC0LayerC.u16Height;
        if(stGDC->stLayerConf_C.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC0LayerC.stWriteFB.u32Address = stGDC->stLayerConf_C.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERC_FULL_SIZE)
            stGDC0LayerC.stWriteFB.u16Width   = stGDC0LayerC.u16Width + GDC1_LAYERC_WIDTH;
#else
            stGDC0LayerC.stWriteFB.u16Width   = stGDC0LayerC.u16Width;
#endif
            stGDC0LayerC.stWriteFB.u16Height  = stGDC0LayerC.u16Height;
        }
        
        if (stGDC->stLayerConf_C.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC0LayerC.eFormat = GDC_RGB16;
            stGDC0LayerC.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_C.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerC.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC0LayerC.eFormat = GDC_RGBA32;
            stGDC0LayerC.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_C.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerC.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }

        /* Layer D */
        stGDC0LayerD.eLayer    = GDC_LAYER_D;
        stGDC0LayerD.u16StartX = stGDC->stLayerConf_D.u16StartX;
        stGDC0LayerD.u16StartY = stGDC->stLayerConf_D.u16StartY;
        stGDC0LayerD.u8Alpha   = stGDC->stLayerConf_D.u8Alpha;
        stGDC0LayerD.u16Width  = stGDC->stLayerConf_D.u16Width;
        stGDC0LayerD.u16Height = stGDC->stLayerConf_D.u16Height;

        stGDC0LayerD.stDispFB.u32Address = stGDC->stLayerConf_D.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERD_FULL_SIZE)
        stGDC0LayerD.stDispFB.u16Width   = stGDC0LayerD.u16Width + GDC1_LAYERD_WIDTH;
#else
        stGDC0LayerD.stDispFB.u16Width   = stGDC0LayerD.u16Width;
#endif
        stGDC0LayerD.stDispFB.u16Height  = stGDC0LayerD.u16Height;
        if(stGDC->stLayerConf_D.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC0LayerD.stWriteFB.u32Address = stGDC->stLayerConf_D.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERD_FULL_SIZE)
            stGDC0LayerD.stWriteFB.u16Width   = stGDC0LayerD.u16Width + GDC1_LAYERD_WIDTH;
#else
            stGDC0LayerD.stWriteFB.u16Width   = stGDC0LayerD.u16Width;
#endif
            stGDC0LayerD.stWriteFB.u16Height  = stGDC0LayerD.u16Height;
        }
        
        if (stGDC->stLayerConf_D.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC0LayerD.eFormat = GDC_RGB16;
            stGDC0LayerD.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_D.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerD.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC0LayerD.eFormat = GDC_RGBA32;
            stGDC0LayerD.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_D.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerD.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }

        /* Layer E */
        stGDC0LayerE.eLayer    = GDC_LAYER_E;
        stGDC0LayerE.u16StartX = stGDC->stLayerConf_E.u16StartX;
        stGDC0LayerE.u16StartY = stGDC->stLayerConf_E.u16StartY;
        stGDC0LayerE.u8Alpha   = stGDC->stLayerConf_E.u8Alpha;
        stGDC0LayerE.u16Width  = stGDC->stLayerConf_E.u16Width;
        stGDC0LayerE.u16Height = stGDC->stLayerConf_E.u16Height;

        stGDC0LayerE.stDispFB.u32Address = stGDC->stLayerConf_E.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERE_FULL_SIZE)
        stGDC0LayerE.stDispFB.u16Width   = stGDC0LayerE.u16Width + GDC1_LAYERE_WIDTH;
#else
        stGDC0LayerE.stDispFB.u16Width   = stGDC0LayerE.u16Width;
#endif
        stGDC0LayerE.stDispFB.u16Height  = stGDC0LayerE.u16Height;
        if(stGDC->stLayerConf_E.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC0LayerE.stWriteFB.u32Address = stGDC->stLayerConf_E.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERE_FULL_SIZE)
            stGDC0LayerE.stWriteFB.u16Width   = stGDC0LayerE.u16Width + GDC1_LAYERE_WIDTH;
#else
            stGDC0LayerE.stWriteFB.u16Width   = stGDC0LayerE.u16Width;
#endif
            stGDC0LayerE.stWriteFB.u16Height  = stGDC0LayerE.u16Height;
        }
        
        if (stGDC->stLayerConf_E.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC0LayerE.eFormat = GDC_RGB16;
            stGDC0LayerE.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_E.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerE.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC0LayerE.eFormat = GDC_RGBA32;
            stGDC0LayerE.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_E.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC0LayerE.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }
    }
    else
    {
        /* configuration for GDC1 */
	
        /* Layer A */
        stGDC1LayerA.eLayer    = GDC_LAYER_A;
        stGDC1LayerA.u16StartX = stGDC->stLayerConf_A.u16StartX;
        stGDC1LayerA.u16StartY = stGDC->stLayerConf_A.u16StartY;
        stGDC1LayerA.u8Alpha   = stGDC->stLayerConf_A.u8Alpha;
        stGDC1LayerA.u16Width  = stGDC->stLayerConf_A.u16Width;
        stGDC1LayerA.u16Height = stGDC->stLayerConf_A.u16Height;

        stGDC1LayerA.stDispFB.u32Address = stGDC->stLayerConf_A.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERA_FULL_SIZE)
        stGDC1LayerA.stDispFB.u16Width   = stGDC1LayerA.u16Width + GDC0_LAYERA_WIDTH;
#else
        stGDC1LayerA.stDispFB.u16Width   = stGDC1LayerA.u16Width;
#endif
        stGDC1LayerA.stDispFB.u16Height  = stGDC1LayerA.u16Height;
        if(stGDC->stLayerConf_A.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC1LayerA.stWriteFB.u32Address = stGDC->stLayerConf_A.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERA_FULL_SIZE)
            stGDC1LayerA.stWriteFB.u16Width   = stGDC1LayerA.u16Width + GDC0_LAYERA_WIDTH;
#else
            stGDC1LayerA.stWriteFB.u16Width   = stGDC1LayerA.u16Width;
#endif
            stGDC1LayerA.stWriteFB.u16Height  = stGDC1LayerA.u16Height;
        }
        
        if (stGDC->stLayerConf_A.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC1LayerA.eFormat = GDC_RGB16;
            stGDC1LayerA.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_A.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerA.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC1LayerA.eFormat = GDC_RGBA32;
            stGDC1LayerA.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_A.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerA.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }

        /* Layer B */
        stGDC1LayerB.eLayer    = GDC_LAYER_B;
        stGDC1LayerB.u16StartX = stGDC->stLayerConf_B.u16StartX;
        stGDC1LayerB.u16StartY = stGDC->stLayerConf_B.u16StartY;
        stGDC1LayerB.u8Alpha   = stGDC->stLayerConf_B.u8Alpha;
        stGDC1LayerB.u16Width  = stGDC->stLayerConf_B.u16Width;
        stGDC1LayerB.u16Height = stGDC->stLayerConf_B.u16Height;

        stGDC1LayerB.stDispFB.u32Address = stGDC->stLayerConf_B.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERB_FULL_SIZE)
        stGDC1LayerB.stDispFB.u16Width   = stGDC1LayerB.u16Width + GDC0_LAYERB_WIDTH;
#else
        stGDC1LayerB.stDispFB.u16Width   = stGDC1LayerB.u16Width;
#endif
        stGDC1LayerB.stDispFB.u16Height  = stGDC1LayerB.u16Height;
        if(stGDC->stLayerConf_B.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC1LayerB.stWriteFB.u32Address = stGDC->stLayerConf_B.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERB_FULL_SIZE)
            stGDC1LayerB.stWriteFB.u16Width   = stGDC1LayerB.u16Width + GDC0_LAYERB_WIDTH;
#else
            stGDC1LayerB.stWriteFB.u16Width   = stGDC1LayerB.u16Width;
#endif
            stGDC1LayerB.stWriteFB.u16Height  = stGDC1LayerB.u16Height;
        }
        
        if (stGDC->stLayerConf_B.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC1LayerB.eFormat = GDC_RGB16;
            stGDC1LayerB.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_B.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerB.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC1LayerB.eFormat = GDC_RGBA32;
            stGDC1LayerB.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_B.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerB.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }

        /* Layer C */
        stGDC1LayerC.eLayer    = GDC_LAYER_C;
        stGDC1LayerC.u16StartX = stGDC->stLayerConf_C.u16StartX;
        stGDC1LayerC.u16StartY = stGDC->stLayerConf_C.u16StartY;
        stGDC1LayerC.u8Alpha   = stGDC->stLayerConf_C.u8Alpha;
        stGDC1LayerC.u16Width  = stGDC->stLayerConf_C.u16Width;
        stGDC1LayerC.u16Height = stGDC->stLayerConf_C.u16Height;

        stGDC1LayerC.stDispFB.u32Address = stGDC->stLayerConf_C.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERC_FULL_SIZE)
        stGDC1LayerC.stDispFB.u16Width   = stGDC1LayerC.u16Width + GDC0_LAYERC_WIDTH;
#else
        stGDC1LayerC.stDispFB.u16Width   = stGDC1LayerC.u16Width;
#endif
        stGDC1LayerC.stDispFB.u16Height  = stGDC1LayerC.u16Height;
        if(stGDC->stLayerConf_C.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC1LayerC.stWriteFB.u32Address = stGDC->stLayerConf_C.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERC_FULL_SIZE)
            stGDC1LayerC.stWriteFB.u16Width   = stGDC1LayerC.u16Width + GDC0_LAYERC_WIDTH;
#else
            stGDC1LayerC.stWriteFB.u16Width   = stGDC1LayerC.u16Width;
#endif
            stGDC1LayerC.stWriteFB.u16Height  = stGDC1LayerC.u16Height;
        }
        
        if (stGDC->stLayerConf_C.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC1LayerC.eFormat = GDC_RGB16;
            stGDC1LayerC.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_C.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerC.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC1LayerC.eFormat = GDC_RGBA32;
            stGDC1LayerC.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_C.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerC.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }

        /* Layer D */
        stGDC1LayerD.eLayer    = GDC_LAYER_D;
        stGDC1LayerD.u16StartX = stGDC->stLayerConf_D.u16StartX;
        stGDC1LayerD.u16StartY = stGDC->stLayerConf_D.u16StartY;
        stGDC1LayerD.u8Alpha   = stGDC->stLayerConf_D.u8Alpha;
        stGDC1LayerD.u16Width  = stGDC->stLayerConf_D.u16Width;
        stGDC1LayerD.u16Height = stGDC->stLayerConf_D.u16Height;

        stGDC1LayerD.stDispFB.u32Address = stGDC->stLayerConf_D.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERD_FULL_SIZE)
        stGDC1LayerD.stDispFB.u16Width   = stGDC1LayerD.u16Width + GDC0_LAYERD_WIDTH;
#else
        stGDC1LayerD.stDispFB.u16Width   = stGDC1LayerD.u16Width;
#endif
        stGDC1LayerD.stDispFB.u16Height  = stGDC1LayerD.u16Height;
        if(stGDC->stLayerConf_D.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC1LayerD.stWriteFB.u32Address = stGDC->stLayerConf_D.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERD_FULL_SIZE)
            stGDC1LayerD.stWriteFB.u16Width   = stGDC1LayerD.u16Width + GDC0_LAYERD_WIDTH;
#else
            stGDC1LayerD.stWriteFB.u16Width   = stGDC1LayerD.u16Width;
#endif
            stGDC1LayerD.stWriteFB.u16Height  = stGDC1LayerD.u16Height;
        }
        
        if (stGDC->stLayerConf_D.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC1LayerD.eFormat = GDC_RGB16;
            stGDC1LayerD.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_D.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerD.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC1LayerD.eFormat = GDC_RGBA32;
            stGDC1LayerD.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_D.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerD.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }

        /* Layer E */
        stGDC1LayerE.eLayer    = GDC_LAYER_E;
        stGDC1LayerE.u16StartX = stGDC->stLayerConf_E.u16StartX;
        stGDC1LayerE.u16StartY = stGDC->stLayerConf_E.u16StartY;
        stGDC1LayerE.u8Alpha   = stGDC->stLayerConf_E.u8Alpha;
        stGDC1LayerE.u16Width  = stGDC->stLayerConf_E.u16Width;
        stGDC1LayerE.u16Height = stGDC->stLayerConf_E.u16Height;

        stGDC1LayerE.stDispFB.u32Address = stGDC->stLayerConf_E.u32FB0StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERE_FULL_SIZE)
        stGDC1LayerE.stDispFB.u16Width   = stGDC1LayerE.u16Width + GDC0_LAYERE_WIDTH;
#else
        stGDC1LayerE.stDispFB.u16Width   = stGDC1LayerE.u16Width;
#endif
        stGDC1LayerE.stDispFB.u16Height  = stGDC1LayerE.u16Height;
        if(stGDC->stLayerConf_E.u8DoubleBuffer == (uint8_t)ON)
        {
            stGDC1LayerE.stWriteFB.u32Address = stGDC->stLayerConf_E.u32FB1StartAddress;
#if (DUAL_GDC == ON) && defined(LAYERE_FULL_SIZE)
            stGDC1LayerE.stWriteFB.u16Width   = stGDC1LayerE.u16Width + GDC0_LAYERE_WIDTH;
#else
            stGDC1LayerE.stWriteFB.u16Width   = stGDC1LayerE.u16Width;
#endif
            stGDC1LayerE.stWriteFB.u16Height  = stGDC1LayerE.u16Height;
        }
        
        if (stGDC->stLayerConf_E.u8DisplayFormat == (uint8_t)FMT_RGB16)
        {
            stGDC1LayerE.eFormat = GDC_RGB16;
            stGDC1LayerE.stDispFB.eFormat = (uint8_t)FMT_RGB16;
            if(stGDC->stLayerConf_E.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerE.stWriteFB.eFormat = (uint8_t)FMT_RGB16;
            }
        }
        else
        {
            stGDC1LayerE.eFormat = GDC_RGBA32;
            stGDC1LayerE.stDispFB.eFormat = (uint8_t)FMT_RGBA32;
            if(stGDC->stLayerConf_E.u8DoubleBuffer == (uint8_t)ON)
            {
                stGDC1LayerE.stWriteFB.eFormat = (uint8_t)FMT_RGBA32;
            }
        }
    }
}

/****************************************************************************/

void vGfSetLayer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer, gf_disp_params_st* pstDispParams)
{
    gdc_fbcfg_st stGDCBuff;

    /* Layer Data Format */
    i32GDC_SetDataFormat(eGDCNumber, pstLayer->eLayer, pstLayer->eFormat);

    /* Frame Buffer Configuration for Display buffer (Foreground buffer)*/
    stGDCBuff.u32Addr  = pstLayer->stDispFB.u32Address;
    stGDCBuff.u16Width = pstLayer->stDispFB.u16Width;
    stGDCBuff.eBuff    = GDC_BUFF_DEFAULT;
    i32GDC_FrameBuffConfig(eGDCNumber, pstLayer->eLayer, &stGDCBuff);

    /* Frame Buffer Configuration for Write buffer (Background buffer)*/
    stGDCBuff.u32Addr  = pstLayer->stWriteFB.u32Address;
    stGDCBuff.eBuff    = GDC_BUFF_SECOND;
    i32GDC_FrameBuffConfig(eGDCNumber, pstLayer->eLayer, &stGDCBuff);

    /* Layer Start */
    vGDC_SetLayerStart(eGDCNumber, pstLayer->eLayer, pstDispParams->u16HSYNCWidth + pstDispParams->u16HBackPorch + 64U + pstLayer->u16StartX,
                       pstDispParams->u16VSYNCWidth + pstDispParams->u16VBackPorch + 64U + pstLayer->u16StartY);

    /* Set Common Alpha-blending + Display Size */
    switch(pstLayer->eLayer)
    {
        case GDC_LAYER_A:
            i32GDC_SetCommonAlpha(eGDCNumber, GDC_SEG_LAYER_A, pstLayer->u8Alpha);
            i32GDC_SetLayerSize(eGDCNumber, pstLayer->eLayer, pstLayer->u16Width, pstLayer->u16Height);
            break;
        case GDC_LAYER_B:
            i32GDC_SetCommonAlpha(eGDCNumber, GDC_SEG_LAYER_B, pstLayer->u8Alpha);
            i32GDC_SetLayerSize(eGDCNumber, pstLayer->eLayer, pstLayer->u16Width, pstLayer->u16Height);
            break;
        case GDC_LAYER_C:
            i32GDC_SetCommonAlpha(eGDCNumber, GDC_SEG_LAYER_C, pstLayer->u8Alpha);
            i32GDC_SetLayerSize(eGDCNumber, pstLayer->eLayer, pstLayer->u16Width, pstLayer->u16Height);
            break;
        case GDC_LAYER_D:
            i32GDC_SetCommonAlpha(eGDCNumber, GDC_SEG_LAYER_D, pstLayer->u8Alpha);
            i32GDC_SetLayerSize(eGDCNumber, pstLayer->eLayer, pstLayer->u16Width, pstLayer->u16Height);
            break;
        case GDC_LAYER_E:
            i32GDC_SetCommonAlpha(eGDCNumber, GDC_SEG_LAYER_E, pstLayer->u8Alpha);
            i32GDC_SetLayerSize(eGDCNumber, pstLayer->eLayer, pstLayer->u16Width, pstLayer->u16Height);
            break;
	default: break;
    }
}

/****************************************************************************/

void vGfShowLayer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer)
{
    i32GDC_LayerEnable(eGDCNumber, pstLayer->eLayer, GDC_ENABLE);
}

/****************************************************************************/

void vGfHideLayer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer)
{
    i32GDC_LayerEnable(eGDCNumber, pstLayer->eLayer, GDC_DISABLE);
}

/****************************************************************************/


void vGfPositionLayer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer, gf_disp_params_st* pstDispParams)
{
    vGDC_SetLayerStart(eGDCNumber, pstLayer->eLayer, pstDispParams->u16HSYNCWidth + pstDispParams->u16HBackPorch + 64U + pstLayer->u16StartX,
                       pstDispParams->u16VSYNCWidth + pstDispParams->u16VBackPorch + 64U + pstLayer->u16StartY);
}

/****************************************************************************/

void vGfLayerSwitchBuffer(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer)
{
    gf_image_st stTempBuffer;

    /* TO DO: Change to pointer based!!! */
    stTempBuffer.u32Address = pstLayer->stDispFB.u32Address;
    stTempBuffer.u16Width   = pstLayer->stDispFB.u16Width;

    pstLayer->stDispFB.u32Address = pstLayer->stWriteFB.u32Address;
    pstLayer->stDispFB.u16Width   = pstLayer->stWriteFB.u16Width;

    pstLayer->stWriteFB.u32Address = stTempBuffer.u32Address;
    pstLayer->stWriteFB.u16Width   = stTempBuffer.u16Width;

    /* Wait on GA to complete the current list */
    vGfWaitForGA();

    /* Set new Display frame-buffer */
    i32GDC_SetLayerStartAddr(eGDCNumber, pstLayer->eLayer, GDC_BUFF_DEFAULT, pstLayer->stDispFB.u32Address);
}

/****************************************************************************/

void vGfLayerSwitchBufferSync(gdc_ch_e eGDCNumber, gf_layer_st* pstLayer)
{
    gf_image_st stTempBuffer;

    /* TO DO: Change to pointer based!!! */
    stTempBuffer.u32Address = pstLayer->stDispFB.u32Address;
    stTempBuffer.u16Width   = pstLayer->stDispFB.u16Width;

    pstLayer->stDispFB.u32Address = pstLayer->stWriteFB.u32Address;
    pstLayer->stDispFB.u16Width   = pstLayer->stWriteFB.u16Width;

    pstLayer->stWriteFB.u32Address = stTempBuffer.u32Address;
    pstLayer->stWriteFB.u16Width   = stTempBuffer.u16Width;

    /* Wait on GA to complete the current list */
    vGfWaitForGA();

    /* Set new Display frame-buffer */
    i32GDC_SetLayerStartAddr(eGDCNumber, pstLayer->eLayer, GDC_BUFF_DEFAULT, pstLayer->stDispFB.u32Address);

    /* Wait on VSync */
    vGfWaitForVSync(eGDCNumber);
}

/****************************************************************************/

uint32_t uiGfGetDispLayerAddr(gf_layer_st* pstLayer)
{
    return pstLayer->stDispFB.u32Address;
}

/****************************************************************************/

uint32_t uiGfGetWriteLayerAddr(gf_layer_st* pstLayer)
{
    return pstLayer->stWriteFB.u32Address;
}

/****************************************************************************/

uint32_t uiGfGetDispLayerWidth(gf_layer_st* pstLayer)
{
    return (uint32_t)pstLayer->stDispFB.u16Width;
}

/****************************************************************************/

uint32_t uiGfGetWriteLayerWidth(gf_layer_st* pstLayer)
{
    return (uint32_t)pstLayer->stWriteFB.u16Width;
}

/****************************************************************************/

gdc_dfmt_e eGfGetWriteLayerFormat(gf_layer_st* pstLayer)
{
    return pstLayer->eFormat;
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
