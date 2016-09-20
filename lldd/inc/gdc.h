/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference GDC Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphics Display Controller (GDC)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.20 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef GDC_H
#define GDC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_GDC_H_REVISION     "$Revision: 1.20 $"
#define LLDD_GDC_H_TAG          "$Name: LLDD_1_7_GFX $"

#define GDC_GAWID_MAX   0x3FF
#define GDC_GADEL_MAX   0x3FF

/* #define _EXTENDED_GDC_APIS_DISABLED_ */
/*********************************************/

/* Number of entries in a color look-up table (CLUT) */
#define GDC_CLUTSIZE_CORR                   256

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/* Graphics display controller (channel) */
typedef enum tag_gdc_ch_e
{
    GDC0 = 0,                               /* Controller (channel) 0 */
    GDC1 = 1                                /* Controller (channel) 1 */
} gdc_ch_e;

/* Clr Bits in GDCDCR:*/
typedef enum tag_gdc_dcr_err_e
{
    GDC_DCR_ERR_NONE            = 0x00U,     /* GBER bit in GDCDCR register   */
    GDC_DCR_ERR_GBER            = 0x01U,     /* GBER bit in GDCDCR register   */
    GDC_DCR_ERR_GAPCOL          = 0x02U,     /* GAPCOL bit in GDCDCR register */
    GDC_DCR_ERR_GBER_AND_GAPCOL = 0x03U      /* GBER and GAPCOL bit in GDCDCR register */
} gdc_dcr_err_e;

/* Used for Signal status of HDISP, HSYNC, VSYNC */
typedef enum tag_gdc_dithering_e
{
    GDC_DITHERING_DSIABLED                  = 0x00U,
    GDC_DITHERING_SIMPLE_ENABLED            = 0x01U,
    GDC_DITHERING_MAGIC_SQR_ENABLED         = 0x02U,
    GDC_DITHERING_MAGIC_SQR_SUBPIX_ENABLED  = 0x03U
} gdc_dithering_e;

/* Update Control for shadow registers: */
typedef enum tag_gdc_reg_update_mode_e
{
    GDC_UPDATE_BY_EVERY_VSYNC          = 0x01,  /* update with every VSYNC (default)   */
    GDC_UPDATE_BY_NEXT_VSYNC_ONLY      = 0x02   /* manual mode: update once at next VSYNC 
                                                   (HW will change it to 00 by next V-Sync. 
                                                   In this case NO Update will happen later) */
} gdc_reg_update_mode_e;

/* status of Update Control for shadow registers: */
typedef enum tag_gdc_reg_update_status_e
{
    GDC_UPDATE_STAT_DISABLED           = 0x00,  /* update is disabled (In case of 2, it will be reset by HW by next v-sync)  */
    GDC_UPDATE_STAT_EVERY_VSYNC        = 0x01,  /* update is with every VSYNC (default)   */
    GDC_UPDATE_STAT_NEXT_VSYNC_ONLY    = 0x02   /* update only for 1 vsync */
} gdc_reg_update_status_e;

/* Graphic Layers */
typedef enum tag_gdc_layer_e
{
    GDC_LAYER_A = 0x0U,                     /* Main Layer A */
    GDC_LAYER_B = 0x1U,                     /* Main Layer B */
    GDC_LAYER_C = 0x2U,                     /* Main Layer C */
    GDC_LAYER_D = 0x3U,                     /* Main Layer D */
    GDC_LAYER_E = 0x4U                      /* Main Layer E */
} gdc_layer_e;

/* Display Window */
typedef enum tag_gdc_win_e
{
    GDC_WIN_A = 0x0U,                       /* Layer A display window */
    GDC_WIN_B = 0x1U,                       /* Layer B display window */
    GDC_WIN_C = 0x2U,                       /* Layer C display window */
    GDC_WIN_D = 0x3U,                       /* Layer D display window */
    GDC_WIN_E = 0x4U                        /* Layer E display window */
} gdc_win_e;

/* *** */

/*
 *  GDCSAR parameter values
 */

/* Frame buffers */
typedef enum tag_gdc_frmbuff_e
{
    GDC_BUFF_DEFAULT = 0x0U,                /* Default Frame Buffer (must be always defined) */
    GDC_BUFF_SECOND  = 0x1U                 /* Second buffer is optional (used only during auto buffer switch) */
} gdc_frmbuff_e;

/* *** */

/*
 *  GDCMSEGR parameter values
 */

/* Memory segments */
typedef enum tag_gdc_seg_e
{
    GDC_SEG_LAYER_A = 0x1U,                 /* Layer A segment */
    GDC_SEG_LAYER_B = 0x2U,                 /* Layer B segment */
    GDC_SEG_LAYER_C = 0x3U,                 /* Layer C segment */
    GDC_SEG_LAYER_D = 0x4U,                 /* Layer D segment */
    GDC_SEG_LAYER_E = 0x5U,                 /* Layer E segment */
    GDC_SEG_WIN_A   = 0x6U,                 /* Layer A Display Window segment */
    GDC_SEG_WIN_B   = 0x7U,                 /* Layer B Display Window segment */
    GDC_SEG_WIN_C   = 0x8U,                 /* Layer C Display Window segment */
    GDC_SEG_WIN_D   = 0x9U,                 /* Layer D Display Window segment */
    GDC_SEG_WIN_E   = 0xAU                  /* Layer E Display Window segment */
} gdc_seg_e;

/* *** */

/*
 * GDCCR parameter values
 */

/* Enable/disable a controller, layer or window */
typedef enum tag_gdc_en_e
{
    GDC_DISABLE = 0x0U,                     /* Disable */
    GDC_ENABLE  = 0x1U                      /* Enable */
} gdc_en_e;

/* Selective color correction mode */
typedef enum tag_gdc_ccmode_e
{
    GDC_EXCEPT_CMPVAL = 0,                  /* No correction of the compare values */
    GDC_CMPVAL_ONLY   = 1                   /* Correct on match with the compare values only */
} gdc_ccmode_e;

/* Display config type */
typedef enum tag_disp_config_type_e
{
    GDC_USE_DISP_SET_DIRECT  = 0,            /* use direct setting (GDCDSR and GDCDIMR) */
    GDC_USE_DISP_SET_BY_LAYA = 1             /* use by setting of layer A (GDCLSRA and GDCLDRA) */
} gdc_disp_config_type_e;

/* GDC output, display, pannel control */
typedef enum tag_gdc_on_e
{
    GDC_OFF = 0x0U,                         /* GDC output off */
    GDC_ON  = 0x1U                          /* GDC output on */
} gdc_on_e;

/* Layer data format */
typedef enum tag_gdc_dfmt_e
{
    GDC_RGBA32 = 0x0U,                      /* RGBA 32-bit */
    GDC_RGB16  = 0x1U,                      /* RGB 16-bit */
    GDC_ARGB32 = 0x2U                       /* ARGB 32-bit */
} gdc_dfmt_e;

/* Frame buffer active status */
typedef enum tag_gdc_fbact_e
{
    GDC_BUFF0 = 0x0U,                       /* Frame buffer 0 is used for the next frame */
    GDC_BUFF1 = 0x1U                        /* Frame buffer 1 is used for the next frame */
} gdc_fbact_e;

/* Dot-clock Selector */
typedef enum tag_gdc_idc_e
{
    GDC_DOTCLK_EXT = 0x0U,                  /* External dot-clock used */
/* >>> WARNING <<< When using external dot clock, output drivers can be damaged when programming "1" (GDC_DOTCLK_INT) to the related bit >>> WARNING <<< */
    GDC_DOTCLK_INT = 0x1U                   /* Internal dot-clock used */

} gdc_idc_e;

/* Signal Polarity */
typedef enum tag_gdc_pol_e
{
    GDC_NEG = 0x0U,                         /* Negative */
    GDC_POS = 0x1U                          /* Positive */
} gdc_pol_e;

/* Artifact handling  */
typedef enum tag_gdc_arth_e
{
    GDC_NO_ACTION   = 0x0U,                 /* No Action */
    GDC_MULTI_BUFF  = 0x1U,                 /* Multi-buffer switching */
    GDC_VIDEO_BLEND = 0x3U                  /* Display window video blending */
} gdc_arth_e;

/* Artifact handling location  */
typedef enum tag_gdc_arthcd_e
{
    GDC_LAYER_AB = 0x0U,                    /* Display window layers A & B */
    GDC_LAYER_CD = 0x1U                     /* Display window layers C & D */
} gdc_arthcd_e;

/* Layer order */
typedef enum tag_gdc_vord_e
{
    GDC_ABCDE = 0x0U,                        /* A, B, C, D, E */
    GDC_ACBDE = 0x1U                         /* A, C, B, D, E */
} gdc_vord_e;

/* Direction input/output selection */
typedef enum tag_gdc_dir_e
{
    GDC_OUTPUT = 0x0U,                      /* Output mode */
    GDC_INPUT  = 0x1U                       /* Input mode */
} gdc_dir_e;

/* Composite synchronization */
typedef enum tag_gdc_csync_e
{
    GDC_VSYNC = 0x0U,                       /* Output VSync on DISP_vsync pin */
    GDC_CSYNC = 0x1U                        /* Output CSync on DISP_vsync pin */
} gdc_csync_e;

/* *** */

/*
 *  GDCINTR parameter values
 */

/* Interrupt status */
typedef enum tag_gdc_irqact_e
{
    GDC_IRQ_INACTIVE = 0x0U,                /* IRQ is inactive */
    GDC_IRQ_ACTIVE   = 0x1U                 /* IRQ is active */
} gdc_irqact_e;

/* *** */

/*
 *  GDCPTCR parameter values
 */

/* General purpose pin selection */
typedef enum tag_gdc_gpp_e
{
    GDC_GPP0 = 0x8U,                        /* General Purpose Pin #0, <GDCPTCR:bit 8> */
    GDC_GPP1,                               /* General Purpose Pin #1, <GDCPTCR:bit 9> */
    GDC_GPP2,
    GDC_GPP3,
    GDC_GPP4,
    GDC_GPP5,
    GDC_GPP6,
    GDC_GPP7,
    GDC_GPP8,
    GDC_GPP9,
    GDC_GPP10,
    GDC_GPP11                               /* General Purpose Pin #11 */
} gdc_gpp_e;

/* Positive panel synchronization select */
typedef enum tag_gdc_ppsync_e
{
    GDC_INPUT_LOW  = 0x0U,                    /* input is low active */
    GDC_INPUT_HIGH = 0x1U                     /* input is high active */
} gdc_ppsync_e;

/* Reduced Swing Differential Signaling select */
typedef enum tag_gdc_rsdsen_e
{
    GDC_RSDSEN_DIGITAL      = 0x0U,                    /* digital output */
    GDC_RSDSEN_DIFFERENTIAL = 0x1U                     /* differential output */
} gdc_rsdsen_e;

/* Reduced Swing Differential Signaling Output Mode */
typedef enum tag_gdc_rsdsoutmode_e
{
    GDC_RSDSOUT_HIGH      = 0x0U,                    /* high */
    GDC_RSDSOUT_MEDIUM    = 0x1U,                    /* medium */
    GDC_RSDSOUT_LOW       = 0x2U,                    /* low */
    GDC_RSDSOUT_HIZ       = 0x3U                     /* high impedance */
} gdc_rsdsoutmode_e;

/* Reduced Swing Differential Signaling Pre-Emphasis Mode */
typedef enum tag_gdc_rsdspreemp_e
{
    GDC_RSDSPEMD_HIGH      = 0x0U,                    /* high */
    GDC_RSDSPEMD_MEDIUM    = 0x1U,                    /* medium */
    GDC_RSDSPEMD_LOW       = 0x2U,                    /* low */
    GDC_RSDSPEMD_DISABLE   = 0x3U                     /* pre-emp disabled */
} gdc_rsdspreemp_e;



/* Data-data alignment */
typedef enum tag_gdc_ddal_e
{
    GDC_ALIGNED =  0x0U,                    /* Aligned */
    GDC_DELAYED =  0x1U                     /* Hal a cycle delayed */
} gdc_ddal_e;

/* Data-clock Alignment */
typedef enum tag_gdc_dcal_e
{
    GDC_RISING  = 0x0U,                     /* Output changes with rising edge */
    GDC_FALLING = 0x1U                      /* Output changes with falling edge */
} gdc_dcal_e;

/* *** */

/*
 *  GDCCLUT parameter values
 */

/* Color correction CLUT channel selection */
typedef enum tag_gdc_clut_e
{
    GDC_CLUT_RED   = 0x0U,                  /* Red CLUT */
    GDC_CLUT_GREEN = 0x1U,                  /* Green CLUT */
    GDC_CLUT_BLUE  = 0x2U                   /* Blue CLUT */
} gdc_clut_e;

/* *** */

/*
 *  GDCBAR parameter values
 */

/* Capture buffer selection */
typedef enum tag_gdc_cbuff_e
{
    GDC_CBUFF1 = 0x0U,                      /* Capture buffer 0 - first */
    GDC_CBUFF2 = 0x1U,                      /* Capture buffer 1 - second */
    GDC_CBUFF3 = 0x2U                       /* Capture buffer 2 - third */
} gdc_cbuff_e;

/* *** */

/*
 * GDCSCVRx parameter values
 */

/* Selective color correction compare activation */
typedef enum tag_gdc_active_e
{
    GDC_DEACTIVATED = 0,                    /* Active */
    GDC_ACTIVATED   = 1                     /* Inactive */
} gdc_active_e;

/* Selective color correction compare values */
typedef enum tag_gdc_cmp_e
{
    GDC_CCVAL0 = 0,                         /* Compare value 0 */
    GDC_CCVAL1 = 1,                         /* Compare value 1 */
    GDC_CCVAL2 = 2,                         /* Compare value 2 */
    GDC_CCVAL3 = 3,                         /* Compare value 3 */
    GDC_CCVAL4 = 4,                         /* Compare value 4 */
    GDC_CCVAL5 = 5,                         /* Compare value 5 */
    GDC_CCVAL6 = 6,                         /* Compare value 6 */
    GDC_CCVAL7 = 7                          /* Compare value 7 */
} gdc_cmp_e;

/* *** */

/*
 *  GDCAPCR parameter values
 */

/* APC mode */
typedef enum tag_gdc_apcm_e
{
    GDC_CPU_COMP  = 0,                      /* CPU mode */
    GCD_AUTO_COMP = 1                       /* AUTO mode */
} gdc_apcm_e;

/* APC pixel value */
typedef enum tag_gdc_apcp_e
{
    GDC_CURR_PIXVAL  = 0,                   /* Current mode */
    GCD_PREV_PIXVAL  = 1                    /* Previous mode */
} gdc_apcp_e;


/* *** */

/*
 *  GDCPROTR parameter values
 */

/* Write protection level for GDC registers */
typedef enum tag_gdc_write_protect_e
{
    GDC_WR_PROTECT_NONE            = 0x00U,   /* no protection                         */
    GDC_WR_PROTECT_DISPL_CONFIG    = 0x01U,   /* display configuration write-protected */
    GDC_WR_PROTECT_FEATURE_SWITCH  = 0x02U,   /* feature switches write-protected      */
    GDC_WR_PROTECT_LAYER_PARAMS    = 0x03U    /* ayer parameters write-protected       */
} gdc_write_protect_e;




/* *** */

/* Display Pulse Generator
 *  GDCGPCR-A, -B, -C parameter values
 */

/* General purpose Pulse Generator: pulse generator selection */
typedef enum tag_gdc_pg_gen_id_e
{
    GDC_PULSE_GEN_0  = 0x0U,      /* Pulse #0  Generator */
    GDC_PULSE_GEN_1  = 0x1U,      /* Pulse #1  Generator */
    GDC_PULSE_GEN_2  = 0x2U,      /* Pulse #2  Generator */
    GDC_PULSE_GEN_3  = 0x3U,      /* Pulse #3  Generator */
    GDC_PULSE_GEN_4  = 0x4U,      /* Pulse #4  Generator */
    GDC_PULSE_GEN_5  = 0x5U,      /* Pulse #5  Generator */
    GDC_PULSE_GEN_6  = 0x6U,      /* Pulse #6  Generator */
    GDC_PULSE_GEN_7  = 0x7U,      /* Pulse #7  Generator */
    GDC_PULSE_GEN_8  = 0x8U,      /* Pulse #8  Generator */
    GDC_PULSE_GEN_9  = 0x9U,      /* Pulse #9  Generator */
    GDC_PULSE_GEN_10 = 0xAU,      /* Pulse #10 Generator */
    GDC_PULSE_GEN_11 = 0xBU       /* Pulse #11 Generator */
} gdc_pg_gen_id_e;


/* General purpose Pulse Generator: output clock gating enable */
typedef enum tag_gdc_pg_cgsel_e
{
    GDC_PULSE = 0x0U,                       /* Output general purpose pulse */
    GDC_DCLK  = 0x1U                        /* Output dotclock gated with general purpose pulse */
} gdc_pg_cgsel_e;

/* General purpose Pulse Generator: output combined logic output select */
typedef enum tag_gdc_pg_outsel_e
{
    GDC_PGA          = 0x0U,      /* Pulse generator (PGA) */
    GDC_PGA_AND_PGB  = 0x1U,
    GDC_PGA_NAND_PGB = 0x2U,
    GDC_PGA_OR_PGB   = 0x3U,
    GDC_PGA_NOR_PGB  = 0x4U,
    GDC_PGA_XOR_PGB  = 0x5U,
    GDC_PGA_XNOR_PGB = 0x6U,
    GDC_PGB          = 0x7U        /* Pulse Generator (PGB) */
} gdc_pg_outsel_e;

/* General purpose Pulse Generator: Trigger selection */
typedef enum tag_gdc_pg_trigger_e
{
    GDC_TRIG_VSYNK  = 0x2U,
    GDC_TRIG_HSYNC  = 0x3U,
    GDC_TRIG_VDISP  = 0x4U,
    GDC_TRIG_HDISP  = 0x5U,
    GDC_TRIG_PNL    = 0x6U
} gdc_pg_trigger_e;

/* *** */

/* Display Pulse Generator
 *  parameter values for  General purpose Pulse Generator 
 *  GDCPxGxR  Px: P0..P11 /GxR: GAR, GBR
 */
/* Pulse generator A or B: */
typedef enum tag_gdc_pg_A_B_e
{
    GDC_PULSE_GEN_A = 0x0U,
    GDC_PULSE_GEN_B = 0x1U
} gdc_pg_A_B_e;

/* Pulse generator input signal select: */
typedef enum tag_gdc_pg_input_e
{
    GDC_INP_DOTCLK = 0x1U,
    GDC_INP_VSYNK  = 0x2U,
    GDC_INP_HSYNC  = 0x3U,
    GDC_INP_VDISP  = 0x4U,
    GDC_INP_HDISP  = 0x5U,
    GDC_INP_PNL    = 0x6U
} gdc_pg_input_e;

/* Pulse generator active level select:: */
typedef enum tag_gdc_pg_active_level_e
{
    GDC_ACTIVE_LVL_0 = 0x0U,   /* active level is 0 */
    GDC_ACTIVE_LVL_1 = 0x1U    /* active level is 1 */
} gdc_pg_active_level_e;

/*Divider value is defined by DIV+1 */
typedef enum tag_gdc_pg_divider_e
{
    GDC_DIVIDER_BYPASS   = 0x00U,
    GDC_DIVIDER_2        = 0x01U,
    GDC_DIVIDER_3        = 0x02U,
    GDC_DIVIDER_4        = 0x03U,
    GDC_DIVIDER_5        = 0x04U,
    GDC_DIVIDER_6        = 0x05U,
    GDC_DIVIDER_7        = 0x06U,
    GDC_DIVIDER_8        = 0x07U,
    GDC_DIVIDER_9        = 0x08U,
    GDC_DIVIDER_10       = 0x09U,
    GDC_DIVIDER_11       = 0x0AU,
    GDC_DIVIDER_12       = 0x0BU,
    GDC_DIVIDER_13       = 0x0CU,
    GDC_DIVIDER_14       = 0x0DU,
    GDC_DIVIDER_15       = 0x0EU,
    GDC_DIVIDER_16       = 0x0FU
} gdc_pg_divider_e;


/*
 *  GDCGBECR parameter values
 */
/* Read / Write Direction */
typedef enum tag_gdc_buserr_dir_e
{
    GDC_BUSERR_READ_TRANSF   = 0x0U,
    GDC_BUSERR_WRITE_TRANSF  = 0x1U
} gdc_buserr_dir_e;

/* Burst Type */
typedef enum tag_gdc_buserr_bursttype_e
{
    GDC_BUSERR_BURST_TYPE_FIXED   = 0x0U,
    GDC_BUSERR_BURST_TYPE_INCR    = 0x1U
} gdc_buserr_bursttype_e;

/* Burst Size */
typedef enum tag_gdc_buserr_burstsize_e
{
    GDC_BUSERR_BURST_1BYTE     = 0x0U,
    GDC_BUSERR_BURST_2BYTE     = 0x1U,
    GDC_BUSERR_BURST_4BYTE     = 0x2U,
    GDC_BUSERR_BURST_81BYTE    = 0x3U,
    GDC_BUSERR_BURST_16BYTE    = 0x4U,
    GDC_BUSERR_BURST_32BYTE    = 0x5U,
    GDC_BUSERR_BURST_64BYTE    = 0x6U,
    GDC_BUSERR_BURST_128BYTE   = 0x7U
} gdc_buserr_burstsize_e;


/* Response Type */
typedef enum tag_gdc_buserr_resptype_e
{
    GDC_BUSERR_RESP_OK        = 0x0U,
    GDC_BUSERR_RESP_EXOKAY    = 0x1U,
    GDC_BUSERR_RESP_SLVERR    = 0x2U,
    GDC_BUSERR_RESP_DECERR    = 0x3U
} gdc_buserr_resptype_e;


/* *** */


/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/

/* Frame buffer configuration structure */
typedef struct tag_gdc_fbcfg_st
{
    gdc_frmbuff_e eBuff;                    /* Frame buffer selection (default/second) */
    uint32_t      u32Addr;                  /* Frame buffer physical start address */
    uint16_t      u16Width;                 /* Frame buffer memory width (line width), limited to 13-bits */
} gdc_fbcfg_st;

/* Synchronization configuration structure */
typedef struct tag_gdc_sync_st
{
    gdc_csync_e eSyncType;                  /* Selects between VSYNC and CSYNC type */
    gdc_pol_e   eVSyncPol;                  /* Polarity of VSYNC */
    gdc_pol_e   eHSyncPol;                  /* Polarity of HSYNC */
    uint8_t     u8HsyncWdth;                /* Width of HSYNC (dot-clocks) */
    uint8_t     u8VsyncWdth;                /* Width of VSYNC (lines) */
    uint16_t    u16HLineLen;                /* Horizontal line length (dot-clocks) */
    uint16_t    u16VFrameLen;               /* Vertical frame length (lines) */
} gdc_sync_st;

/* IRQ configuration structure */
typedef struct tag_gdc_irqcgf_st
{
    gdc_en_e eAPCIrqEn;                     /* Automatic Pixel Checker (APC) Mask */
    uint16_t u16LineNr;                     /* Line Number HSYNCINT [Range 0x0 - 0x7FF] */
    gdc_en_e eHSyncIrqEn;                   /* HSYNCINT Mask */
    gdc_en_e eVSyncIrqEn;                   /* VSYNCINT Mask */
    gdc_en_e eIfurIrqEn;                    /* IFURINT IRQ Mask */
    gdc_en_e eOfurIrqEn;                    /* IFURINT IRQ Mask */
} gdc_irqcgf_st;

/* APC configuration structure */
typedef struct tag_gdc_apccfg_st
{
    gdc_apcm_e eMode;                       /* APC Mode */
    uint8_t    u8Frames;                    /* 7 bits:  Computation interval length [in frames] */
    uint8_t    u8WWidth;                    /* 8 bits:  Window width */
    uint8_t    u8WHeight;                   /* 7 bits:  Window height */
    uint16_t   u16HStart;                   /* 12 bits: Horizontal start position */
    uint16_t   u16VStart;                   /* 11 bits: Vertical start position */
    uint32_t   u32AutoChkSum;               /* 22 bits: Expected checksum in AUTO mode */
} gdc_apccfg_st;

/* GDC bus Error Control Signal-Structure */
typedef struct tag_gdc_bus_err_ctrl_st
{
    gdc_buserr_dir_e        eDirection;       /* Read / Write direction */
    gdc_buserr_bursttype_e  eBurstType;       /* Burst type */
    gdc_buserr_burstsize_e  eBurstSize;       /* Burst size */
    gdc_buserr_resptype_e   eRespType;        /* Response Type */
    uint8_t                 u8ByteEnables;    /* Byte-enables for the erroneous transfer. */
    uint8_t                 u8ID;             /* ID tag of the read/write transaction that triggered an error response. */
    uint8_t                 u8BurstLength;    /* Burst length of the read/write transaction that triggered an error response */
} gdc_bus_err_ctrl_st;


/* Structure for General Purpose Pulse Generator Registers (GDCPnGxR) */
typedef struct tag_gdc_pulse_config_st
{
    gdc_pg_active_level_e   eActiveLevel;    /* Pulse generator active level select: */
    gdc_pg_input_e          eSelectedInput;  /* Pulse generator input signal select: */
    gdc_en_e                eByPassEnb;      /* Pulse generator bypass enable: */
    uint16_t                u16PulseDelay;   /* Delay of generated pulse */
    gdc_pg_divider_e        ePulseDivider;   /* Divider value is defined by DIV+1 */
    gdc_en_e                eInvertEnb;      /* Pulse generator inversion enable: */
    uint16_t                u16PulseWidth;   /* Width of generated pulse, measured in dot clock cycles for all input sources but VSYNC and VDISP */
} gdc_pulse_config_st;


/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/


/****************************************************************************
 *
 * Function:      vGDC_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8IORevision     - pointer to IO header revision string
 *                pau8IOTag          - pointer to IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGDC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);


/***************************************************************************
*
*                  G E N E R A L    C O N F I G U R A T I O N
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      vGDC_Init
 *
 * Purpose:       Initializes the GDC driver and the register shadow list
 *                for the controller specified
 *
 * Inputs:        eGDC     Controller channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   The clock gating for the controller must be enabled first!
 *                [Please refer to CCRCR register description]
 *
 ***************************************************************************/
void vGDC_Init(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      vGDC_Switch
 *
 * Purpose:       Switch GDC output On/Off
 *
 * Inputs:        eGDC     Controller channel
 *                eSwitch  On/off request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_Switch(gdc_ch_e eGDC, gdc_on_e eSwitch);


/****************************************************************************
 *
 * Function:      vGDC_SetShadowRegUpdateMode
 *
 * Purpose:       Set the mechanism of shadow register updating. 
 *
 * Inputs:        eGDC     Controller channel
 *                eCtrl    Updating mechanism
 *                         Important NOTE: 
 *                         GDC_UPDATE_BY_NEXT_VSYNC_ONLY: this mode can be used to 
 *                         disable update shadow register option. In this case
 *                         user application should wait after after the call, until
 *                         update register bit has been set to 0 by HW (eGetShadowRegUpdateStatus()     
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGDC_SetShadowRegUpdateMode(gdc_ch_e eGDC, gdc_reg_update_mode_e eCtrl);


/****************************************************************************
 *
 * Function:      eGetShadowRegUpdateStatus
 *
 * Purpose:       Gets the actual update mode for shadow register from HW. 
 *                NOTE: If last setting was "GDC_UPDATE_BY_NEXT_VSYNC_ONLY", 
 *                      the HW will reset it to "0" by next VSync.
 *
 * Inputs:        eGDC     Controller channel
 *
 * Outputs:       none
 *
 * Return Values: status of shadow register update
 *
 * Limitations:   none
 *
 ***************************************************************************/
gdc_reg_update_status_e eGetShadowRegUpdateStatus(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      vGDC_ADBSEnable
 *
 * Purpose:       Enable/disable the "Automatic buffer switching" for all
 *                layers
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_ADBSEnable(gdc_ch_e eGDC, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_ColorCorrectEnable
 *
 * Purpose:       Enable/disable the per channel color correction
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_ColorCorrectEnable(gdc_ch_e eGDC, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_SetArthMode
 *
 * Purpose:       Select the artifact handling mode
 *
 * Inputs:        eGDC   Controller channel
 *                eMode  Artifact handling mode
 *                eLoc   Artifact handling location
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_SetArthMode(gdc_ch_e eGDC, gdc_arth_e eMode, gdc_arthcd_e eLoc);


/****************************************************************************
 *
 * Function:      vGDC_SetDitheringMode
 *
 * Purpose:       Select the artifact handling mode
 *
 * Inputs:        eGDC   Controller channel
 *                eDith  Deithering mode
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_SetDitheringMode(gdc_ch_e eGDC, gdc_dithering_e eDith);


/****************************************************************************
 *
 * Function:      vGDC_SetBgrColor
 *
 * Purpose:       Set the background color
 *
 * Inputs:        eGDC      Controller channel
 *                u32Color  Background color in a RGB16 format:
 *                              Red   : u32Color[23:16]
 *                              Green : u32Color[15:8]
 *                              Blue  : u32Color[7:0]
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   The color data is internally adjusted to the register layout
 *                [shifted left by 8 bits to adjust the bit values]
 *
 ***************************************************************************/
void vGDC_SetBgrColor(gdc_ch_e eGDC, uint32_t u32Color);


/****************************************************************************
 *
 * Function:      eGDC_GetDispStat
 *
 * Purpose:       Retrieve the display interface status [enabled/disabled]
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       none
 *
 * Return Values: Interface enabled/disabled status
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
gdc_en_e eGDC_GetDispStat(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      eGDC_GetPanelStat
 *
 * Purpose:       Retrieve the panel interface status [enabled/disabled]
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       none
 *
 * Return Values: Interface enabled/disabled status
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
gdc_en_e eGDC_GetPanelStat(gdc_ch_e eGDC);


#ifndef _EXTENDED_GDC_APIS_DISABLED_
/****************************************************************************
 *
 * Function:      vGDC_SetGdcWriteProtection
 *
 * Purpose:       Defines level of Write protection for GDC control registers
 *                a register .
 *
 * Inputs:        eGDC         Controller channel
 *                eProtection  Protection Level
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGDC_SetGdcWriteProtection(gdc_ch_e eGDC, gdc_write_protect_e eProtection);


/****************************************************************************
 *
 * Function:      vGDC_GAPIFEnable
 *
 * Purpose:       Enable/Disable GA-Programming Interface (GAPIF)
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable GAPIF
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_GAPIFEnable(gdc_ch_e eGDC, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      boGDC_AccessToGapif
 *
 * Purpose:       Check if GA-Programming Interface (GAPIF) has been accessed
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       none
 *
 * Return Values: Access(C_TRUE)/ No access (C_FALSE)
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
bool_t boGDC_AccessToGapif(gdc_ch_e eGDC);


#endif /* _EXTENDED_GDC_APIS_DISABLED_ */
/****************************************************************************/



/***************************************************************************
*
*                             D O T  -  C L O C K
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      vGDC_SelDotClkSrc
 *
 * Purpose:       Configure the dot-clock source [internal/external]
 *
 * Inputs:        eGDC  Controller channel
 *                eSel  Source selection
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   !!! >>>  ATTENTION  <<< !!!
 *                When using internal clock, please pay attention on output
 *                drivers as they can be damaged. For more information about
 *                this topic, please refer to the Capricorn data-book
 *
 ***************************************************************************/
void vGDC_SelDotClkSrc(gdc_ch_e eGDC, gdc_idc_e eSel);


/****************************************************************************
 *
 * Function:      vGDC_SetDotClkPol
 *
 * Purpose:       Configure the dot-clock polarity [positive/negative]
 *
 * Inputs:        eGDC  Controller channel
 *                ePol  Polarity request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_SetDotClkPol(gdc_ch_e eGDC, gdc_pol_e ePol);


/****************************************************************************/



/***************************************************************************
*
*                      L A Y E R    M A N I P U L A T I O N
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      i32GDC_LayerEnable
 *
 * Purpose:       Enable/disable a layer
 *
 * Inputs:        eGDC    Controller channel
 *                eLayer  Layer selection
 *                eEn     Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid layer
 *
 * Limitations:   Process one layer at a time
 *
 ***************************************************************************/
int32_t i32GDC_LayerEnable(gdc_ch_e eGDC, gdc_layer_e eLayer, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      i32GDC_SetDataFormat
 *
 * Purpose:       Set the data format (32-bit RGBA/16-bit RGB/32-bit ARGB)
 *                for a layer
 *
 * Inputs:        eGDC    Controller channel
 *                eLayer  Layer selection
 *                eFmt    Data format (32-bit RGBA/16-bit RGB/32-bit ARGB)
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on invalid layer or invalid pixel format
 *
 * Limitations:   The proper operation depends on the bit layout, thus it
 *                it must not to be changed: bit 0 of the eFmt parameter
 *                determines the data bit-width, whereas bit 1 determines
 *                the alpha position, which is not appicable and therefore
 *                ignored in 16-bit mode
 *
 ***************************************************************************/
int32_t i32GDC_SetDataFormat(gdc_ch_e eGDC, gdc_layer_e eLayer, gdc_dfmt_e eFmt);


/****************************************************************************
 *
 * Function:      vGDC_SetLayerStart
 *
 * Purpose:       Configure the layer start position of a layer [A, B, C,
 *                D or E]
 *
 * Inputs:        eGDC       Controller channel
 *                eLayer     Layer selection
 *                u16HStart  Horizontal start position in dot-clocks, counted
 *                           from the leading edge of HSYNC, being in the range
 *                           [64 - 2047]
 *                u16VStart  Vertical start position in number of lines,
 *                           counted from the leading edge of VSYNC, being in
 *                           the range [64 - 1023]
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one layer at a time. Start position parameters
 *                will be truncated to 11 and 10 bits respectively. All
 *                reserved bits will be kept as zeros. No parameter
 *                validity check is performed
 *
 ***************************************************************************/
void vGDC_SetLayerStart(gdc_ch_e eGDC, gdc_layer_e eLayer, uint16_t u16HStart, uint16_t u16VStart);


/****************************************************************************
 *
 * Function:      i32GDC_SetLayerSize
 *
 * Purpose:       Set the layer size [width * height] for a layer [A, B,
 *                C, D or E]
 *
 * Inputs:        eGDC      Controller channel
 *                eLayer    Layer selection
 *                u16Width  Horizontal size in the range [64-4095]
 *                u16Height Vertical size in the range [32-2047]
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on invalid lower width range
 *
 * Limitations:   Process one layer at a time. Start position parameters
 *                will be truncated to 12 and 11 bits respectively. All
 *                reserved bits will be kept as zeros. No further parameter
 *                validity check is performed
 *
 ***************************************************************************/
 int32_t i32GDC_SetLayerSize(gdc_ch_e eGDC, gdc_layer_e eLayer,
                             uint16_t u16Width, uint16_t u16Height);
 
 
/****************************************************************************
 *
 * Function:      vGDC_SetLayerOrder
 *
 * Purpose:       Select the layer order  [A-B-C-D-E or A-C-B-D-E]
 *
 * Inputs:        eGDC    Controller channel
 *                eOrder  Layer order selection
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_SetLayerOrder(gdc_ch_e eGDC, gdc_vord_e eOrder);


/****************************************************************************
 *
 * Function:      i32GDC_SetCommonAlpha
 *
 * Purpose:       Set the comon alpha value for a layer or a display window
 *                in the range [A, B, C, D, E]
 *
 * Inputs:        eGDC     Controller channel
 *                eEntity  Layer or display window
 *                u8Alpha  Alpha value in the range [0x00 - 0xFF], where:
 *                             0x00 - transparent
 *                             0xFF - opaque
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid layer/display window
 *
 * Limitations:   Process one layer/display window at a time
 *
 ***************************************************************************/
int32_t i32GDC_SetCommonAlpha(gdc_ch_e eGDC, gdc_seg_e eEntity, uint8_t u8Alpha);


/****************************************************************************
 *
 * Function:      u8GDC_GetCommonAlpha
 *
 * Purpose:       Retrieve the comon alpha value for a layer or a display
 *                window in the range [A, B, C, D, E]
 *
 * Inputs:        eGDC      Controller channel
 *                eEntity   Layer or display window
 *                pu8Alpha  Result destination
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid layer/display window
 *
 * Limitations:   Process one layer/display window at a time
 *
 ***************************************************************************/
int32_t i32GDC_GetCommonAlpha(gdc_ch_e eGDC, gdc_seg_e eEntity, uint8_t* pu8Alpha);

/****************************************************************************/



/***************************************************************************
*
*                          F R A M E -  B U F F E R
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      i32GDC_FrameBuffConfig
 *
 * Purpose:       Configure a frame buffer for layer A, B, C, D or E
 *
 * Inputs:        eGDC        Controller channel
 *                eLayer      Layer selection [A, B, C, D or E]
 *                pstBuffCfg  Pointer to frame buffer configuration
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid layer
 *
 * Limitations:   Process one layer at a time. The scroll bits will
 *                be modified. All reserved bits are hard-wired to
 *                zero and will not be modified even a different
 *                value is passed!
 *
 ***************************************************************************/
int32_t i32GDC_FrameBuffConfig(gdc_ch_e eGDC, gdc_layer_e eLayer, gdc_fbcfg_st* pstBuffCfg);


/****************************************************************************
 *
 * Function:      eGDC_GetActiveFrameBuff
 *
 * Purpose:       Check the next active frame buffer for all layers
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Next active buffer
 *
 * Return Values: none
 *
 * Limitations:   Process one layer at a time
 *
 ***************************************************************************/
gdc_frmbuff_e eGDC_GetActiveFrameBuff(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      vGDC_SetMemWidth
 *
 * Purpose:       Set the image width of the frame buffer memory in number
 *                of dots
 *
 * Inputs:        eGDC      Controller channel
 *                eLayer    Layer selection [A, B, C, D or E]
 *                u16Width  Horizontal line length of the frame buffer image,
 *                          limited to 13-bits for all layers
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one segment at a time. No parameter range check
 *                is performed
 *
 ***************************************************************************/
void vGDC_SetMemWidth(gdc_ch_e eGDC, gdc_layer_e eLayer, uint16_t u16Width);


/****************************************************************************
 *
 * Function:      i32GDC_SetLayerStartAddr
 *
 * Purpose:       Configure the start address of a layer [A, B, C, D or E]
 *
 * Inputs:        eGDC     Controller channel
 *                eLayer   Layer selection
 *                eBuff    Frame Buffer selection [Default or second (in case
 *                         of double buffering only)]
 *                u32Addr  Frame Buffer 32-bit physical start address
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid layer
 *
 * Limitations:   Any previous existing scroll value will be kept. Bit 0 is
 *                hard-wired to zero and will not be modified even a different
 *                value is passed. Process one layer at a time
 *
 ***************************************************************************/
int32_t i32GDC_SetLayerStartAddr(gdc_ch_e eGDC, gdc_layer_e eLayer,
                                 gdc_frmbuff_e eBuff, uint32_t u32Addr);


/****************************************************************************
 *
 * Function:      i32GDC_SetScrollVal
 *
 * Purpose:       Set the scroll value of a layer [A, B, C, D or E]
 *
 * Inputs:        eGDC      Controller channel
 *                eLayer    Layer selection
 *                eBuff     Frame Buffer selection [Default or second (in case
 *                         of double buffering only)]
 *                u8ScrVal  Scrolling value
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid layer
 *
 * Limitations:   Process one layer at a time. Both SSCROLL bits will be
 *                set regardless of the data format mode [32-bit/16-bit],
 *                thus scrolling value validation has to be done by the
 *                caller of this API
 *
 ***************************************************************************/
int32_t i32GDC_SetScrollVal(gdc_ch_e eGDC, gdc_layer_e eLayer,
                            gdc_frmbuff_e eBuff, uint8_t u8ScrVal);


/****************************************************************************
 *
 * Function:      vGDC_SetStartAddrCapture
 *
 * Purpose:       Set the start address of a capture buffer
 *
 * Inputs:        eGDC     Controller channel
 *                eBuff    Capture buffer [0, 1 or 2]
 *                u32Addr  Capture buffer physical start address
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   That last three bits of the address [2:0] are hard-wired
 *                to zero, thus will be ignored
 *
 ***************************************************************************/
void vGDC_SetStartAddrCapture(gdc_ch_e eGDC, gdc_cbuff_e eBuff, uint32_t u32Addr);

/****************************************************************************/



/***************************************************************************
*
*          P E R    C H A N N E L    C O L O R    C O R R E C T I O N
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      vGDC_InitCorrClut
 *
 * Purpose:       Initialize a color correction look-up table [Red, Green, Blue]
 *
 * Inputs:        eGDC     Controller channel
 *                eClut    CLUT table selection
 *                pu8Data  Pointer to buffer with the 256x 8-bit entries
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Access is based on relative controller offset, as defined
 *                in gdc_ch_e. Process one table at a time
 *
 ***************************************************************************/
void vGDC_InitCorrClut(gdc_ch_e eGDC, gdc_clut_e eClut, const uint8_t* pu8Data);


/****************************************************************************
 *
 * Function:      bovGDC_SetSelectCorrCompVal
 *
 * Purpose:       Set a selective color correction compare value
 *
 * Inputs:        eGDC            Controller channel
 *                eSelection      Selected CCV
 *                u32CorrCompVal  Compare value to be set
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one value at a time
 *
 ***************************************************************************/
void vGDC_SetSelectCorrCompVal(gdc_ch_e eGDC,  gdc_cmp_e eSelection, uint32_t u32CorrCompVal);


/****************************************************************************
 *
 * Function:      vGDC_ActivateCorrCompVal
 *
 * Purpose:       Activate a selective color correction compare value
 *
 * Inputs:        eGDC        Controller channel
 *                eSelection  Selected CCV
 *                eActive     Activate/deactivate request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one value at a time
 *
 ***************************************************************************/
void  vGDC_ActivateCorrCompVal(gdc_ch_e eGDC, gdc_cmp_e eSelection, gdc_active_e eActive);


/****************************************************************************
 *
 * Function:      vGDC_EnableSelectiveCorr
 *
 * Purpose:       Enable/disable the selective color correction in a specified
 *                mode
 *
 * Inputs:        eGDC   Controller channel
 *                eEn    Enable/disable request
 *                eMode  Correction mode
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_EnableSelectiveCorr(gdc_ch_e eGDC, gdc_en_e eEn, gdc_ccmode_e eMode);

/****************************************************************************/



/***************************************************************************
*
*                               D I S P L A Y
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      vGDC_SetDispConfigType
 *
 * Purpose:       Set display config type
 *
 * Inputs:        eGDC             Controller channel
 *                eDispConfigType  Display config type
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process a controller at a time
 *
 ***************************************************************************/
void vGDC_SetDispConfigType(gdc_ch_e eGDC, gdc_disp_config_type_e eDispConfigType);


/****************************************************************************
 *
 * Function:      i32GDC_SetDisplayStart
 *
 * Purpose:       Configure the display start position
 *
 * Inputs:        eGDC       Controller channel
 *                u16HStart  Horizontal start position in dot-clocks, counted
 *                           from the leading edge of HSYNC, being in the range
 *                           [64 - 2047]
 *                u16VStart  Vertical start position in number of lines,
 *                           counted from the leading edge of VSYNC, being in
 *                           the range [64 - 1023]
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on invalid lower width range
 *
 * Limitations:   Process one layer at a time. Start position parameters
 *                will be truncated to 10 and 10 bits respectively. All
 *                reserved bits will be kept as zeros. No parameter
 *                validity check is performed
 *
 ***************************************************************************/
int32_t i32GDC_SetDisplayStart(gdc_ch_e eGDC, uint16_t u16HStart, uint16_t u16VStart);


/****************************************************************************
 *
 * Function:      i32GDC_SetDisplaySize
 *
 * Purpose:       Set the layer size [width * height]
 *
 * Inputs:        eGDC      Controller channel
 *                u16Width  Horizontal display width using number of dots [64-2047]
 *                u16Height Vertical display height using number of lines [1-1023]
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on invalid lower width range
 *
 * Limitations:   Process one layer at a time. Start position parameters
 *                will be truncated to 12 and 11 bits respectively. All
 *                reserved bits will be kept as zeros. No further parameter
 *                validity check is performed
 *
 ***************************************************************************/
 int32_t i32GDC_SetDisplaySize(gdc_ch_e eGDC, uint16_t u16Width, uint16_t u16Height);


/****************************************************************************/



/***************************************************************************
*
*                                W I N D O W
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      vGDC_WindowEnable
 *
 * Purpose:       Enable/disable a layer's display window
 *
 * Inputs:        eGDC     Controller channel
 *                eWindow  Window
 *                eEn      Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one window at a time
 *
 ***************************************************************************/
void vGDC_WindowEnable(gdc_ch_e eGDC, gdc_win_e eWindow, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      i32GDC_SetWindowSize
 *
 * Purpose:       Set a display window size [width & height]
 *
 * Inputs:        eGDC       Controller channel
 *                eWindow    Window selection [A, B, C, D or E]
 *                u16Width   Horizontal window size in the range [64-4095]
 *                u16Height  Vertical window size in the range [32-2047]
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on invalid lower width range
 *
 * Limitations:   Process one window at a time. Start position parameters
 *                will be truncated to 12 and 11 bits respectively. All
 *                reserved bits will be kept as zeros. No further parameter
 *                validity check is performed
 *
 ***************************************************************************/
int32_t i32GDC_SetWindowSize(gdc_ch_e eGDC, gdc_win_e eWindow,
                             uint16_t u16Width, uint16_t u16Height);


/****************************************************************************
 *
 * Function:      vGDC_SetWindowStartPos
 *
 * Purpose:       Configure the window start position of a layer [A, B, C,
 *                D or E]
 *
 * Inputs:        eGDC       Controller channel
 *                eWindow    Window selection
 *                u16HStart  Horizontal start position in dot-clocks, counted
 *                           from the leading edge of HSYNC [64..2047]
 *                u16VStart  Vertical start position in number of lines,
 *                           counted from the leading edge of VSYNC [64..1023]
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one window at a time. Start position parameters
 *                will be truncated to 11 and 10 bits respectively. All
 *                reserved bits will be kept as zeros. No parameter
 *                validity check is performed
 *
 ***************************************************************************/
void vGDC_SetWindowStartPos(gdc_ch_e eGDC, gdc_win_e eWindow,
                            uint16_t u16HStart, uint16_t u16VStart);


/****************************************************************************
 *
 * Function:      i32GDC_SetWindowStartAddr
 *
 * Purpose:       Sets the start address of a window [A, B, C, D or E]
 *
 * Inputs:        eGDC     Controller channel
 *                eWindow  Window selection
 *                u32Addr  Frame buffer physical start address
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid window
 *
 * Limitations:   Bits 2-0 are hard-wired to zero and will not be modified
 *                even a different value is passed. Process one window at
 *                a time
 *
 ***************************************************************************/
int32_t i32GDC_SetWindowStartAddr(gdc_ch_e eGDC, gdc_win_e eWindow, uint32_t u32Addr);

/****************************************************************************/



/***************************************************************************
*
*                       S Y N C H R O N I Z A T I O N
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      vGDC_SyncConfig
 *
 * Purpose:       Configure the VSYNC and HSYNC signals by setting type,
 *                polarity, signal width, line-length and vertical frame
 *                length for a controller
 *
 * Inputs:        eGDC         Controller channel
 *                pstSyncCfg   Pointer to HSYNC/VSYNC configuration structure
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time. No parameter range or
 *                validity checks are performed
 *
 ***************************************************************************/
void vGDC_SyncConfig(gdc_ch_e eGDC, gdc_sync_st* pstSyncCfg);


/****************************************************************************
 *
 * Function:      vGDC_SetSyncDir
 *
 * Purpose:       Set the direction of VSYNC and HSYNC lines
 *
 * Inputs:        eGDC  Controller channel
 *                eDir  HSYNC/VSYNC signal direction
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 *                                !!! >>>  ATTENTION  <<< !!!
 *                When using external sync signals, the output drivers can
 *                be damaged if the direction is configure to output !!!
 *
 ***************************************************************************/
void vGDC_SetSyncDir(gdc_ch_e eGDC, gdc_dir_e eDir);


/****************************************************************************
 *
 * Function:      vGDC_SelectCompSync
 *
 * Purpose:       Set composite signal synchronization
 *
 * Inputs:        eGDC   Controller channel
 *                eSync  VSYNC/CSYNC selection request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SelectCompSync(gdc_ch_e eGDC, gdc_csync_e eSync);


/****************************************************************************
 *
 * Function:      vGDC_SetPolVSync
 *
 * Purpose:       Select the VSYNC mode [negative/positive], where:
 *                    negative => DISP_vsync is low active
 *                    positive => DISP_vsync is high active
 *
 * Inputs:        eGDC   Controller channel
 *                eMode  Positive/negative mode request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPolVSync(gdc_ch_e eGDC, gdc_pol_e eMode);


/****************************************************************************
 *
 * Function:      vGDC_SetPolHSync
 *
 * Purpose:       Select the HSYNC mode [negative/positive], where:
 *                    negative => DISP_hsync is low active
 *                    positive => DISP_hsync is high active
 *
 * Inputs:        eGDC   Controller channel
 *                eMode  Positive/negative mode request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPolHSync(gdc_ch_e eGDC, gdc_pol_e eMode);


/****************************************************************************
 *
 * Function:      vGDC_SetPolHDisp
 *
 * Purpose:       Select the HDISP mode [negative/positive], where:
 *                    negative => DISP_hdisp is low active
 *                    positive => DISP_hdisp is high active
 *
 * Inputs:        eGDC   Controller channel
 *                eMode  Positive/negative mode request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPolHDisp(gdc_ch_e eGDC, gdc_pol_e eMode);


/****************************************************************************
 *
 * Function:      vGDC_SetHSync
 *
 * Purpose:       Set the HSYNC pulse width and line length
 *
 * Inputs:        eGDC          Controller channel
 *                u8PulseWidth  Pulse width in number of dot-clocks
 *                u16LineLen    Line length in number of dot-clocks
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time. No parameter validity
 *                check is performed
 *
 ***************************************************************************/
void vGDC_SetHSync(gdc_ch_e eGDC, uint8_t u8PulseWidth, uint16_t u16LineLen);


/****************************************************************************
 *
 * Function:      vGDC_SetVSync
 *
 * Purpose:       Set the VSYNC pulse width and vertical frame length
 *
 * Inputs:        eGDC           Controller channel
 *                u8PulseWidth   Pulse width in number of lines
 *                u16VFrameLen   Vertical frame length in number of lines
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time. No parameter validity
 *                check is performed
 *
 ***************************************************************************/
void vGDC_SetVSync(gdc_ch_e eGDC, uint8_t u8PulseWidth, uint16_t u16VFrameLen);


/****************************************************************************
 *
 * Function:      u32GDC_GetPolVSync
 *
 * Purpose:       Retrieve the current VSYNC mode [negative/positive], where:
 *                    negative => DISP_vsync is low active
 *                    positive => DISP_vsync is high active
 *
 * Inputs:        eGDC   Controller channel
 *
 * Outputs:       Current mode
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
uint32_t u32GDC_GetPolVSync(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      u32GDC_GetStatVSync
 *
 * Purpose:       Retrieve the current vertical synchronization signal status
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Current signal status
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
uint32_t u32GDC_GetStatVSync(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      u32GDC_GetStatHSync
 *
 * Purpose:       Retrieve the current horizontal synchronization signal status
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Current signal status
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
uint32_t u32GDC_GetStatHSync(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      u32GDC_GetStatHDisp
 *
 * Purpose:       Retrieve the current status of the horizontal display data
 *                ready signal
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Current signal status
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
uint32_t u32GDC_GetStatHDisp(gdc_ch_e eGDC);

/****************************************************************************/



/***************************************************************************
*
*                             I N T E R R U P T S
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      GDC_IrqConfig
 *
 * Purpose:       Configure all GDC related interrupt sources of a controller
 *
 * Inputs:        eGDC    Controller channel
 *                pstCfg  Pointer to interrupt configuration structure
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_IrqConfig(gdc_ch_e eGDC, gdc_irqcgf_st* pstCfg);


/****************************************************************************
 *
 * Function:      vGDC_SetIrqMaskAPC
 *
 * Purpose:       Enable/disable the Automatic Pixel Checker Interrupt [APCINT]
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetIrqMaskAPC(gdc_ch_e eGDC, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_SetHsyncIrqLine
 *
 * Purpose:       Set the number of lines in which the HSYNCINT should be
 *                generated
 *
 * Inputs:        eGDC        Controller channel
 *                u16LineNr   Line number on which the HSYNC interrupt shall
 *                            be generated. Parameter range is [0x0 - 0x7FF]
 *                            If zero is specified, the interrupt will be
 *                            generated on every line
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetHsyncIrqLine(gdc_ch_e eGDC, uint16_t u16LineNr);


/****************************************************************************
 *
 * Function:      vGDC_SetIrqMaskFifoIn
 *
 * Purpose:       Enable/disable the Input FIFO Underrun Interrupt [IFURINT]
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetIrqMaskFifoIn(gdc_ch_e eGDC, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_SetIrqMaskFifoOut
 *
 * Purpose:       Enable/disable the Output FIFO Underrun Interrupt [OFURINT]
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetIrqMaskFifoOut(gdc_ch_e eGDC, gdc_en_e eEn);

/****************************************************************************
 *
 * Function:      vGDC_SetIrqMaskVSync
 *
 * Purpose:       Enable/disable the VSYNC Interrupt [VSYNCINT]
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetIrqMaskVSync(gdc_ch_e eGDC, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_SetIrqMaskHSync
 *
 * Purpose:       Enable/disable the HSYNC Interrupt [HSYNCINT]
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetIrqMaskHSync(gdc_ch_e eGDC, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      eGDC_IsIrqHSync
 *
 * Purpose:       Check whether HSYNC Interrupt [HSYNCINT] is active and
 *                clear the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqHSync(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      eGDC_IsIrqVSync
 *
 * Purpose:       Check whether VSYNC Interrupt [VSYNCINT] is active and
 *                clear the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqVSync(gdc_ch_e eGDC);

/****************************************************************************
 *
 * Function:      eGDC_IsIrqFifoIn
 *
 * Purpose:       Check whether Input FIFO Underrun Interrupt [IFURINT]
 *                is active and clear the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqFifoIn(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      eGDC_IsIrqFifoOut
 *
 * Purpose:       Check whether Output FIFO Underrun Interrupt [OFURINT]
 *                is active and clear the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqFifoOut(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      eGDC_IsIrqAPC
 *
 * Purpose:       Check whether APC Interrupt [APCINT] is active and clear
 *                the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqAPC(gdc_ch_e eGDC);


#ifndef _EXTENDED_GDC_APIS_DISABLED_
/****************************************************************************
 *
 * Function:      eGDC_IsIrqGap
 *
 * Purpose:       The function checks whether APC interrupt (GAPINT) is active 
 *                and if it is, clears the corresponding flag. 
 *                Note:
 *                     By clearing GAPINT the error bit GAPCOL in GDCDCR register
 *                     will also be cleared.
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqGap(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      eGDC_IsIrqGber
 *
 * Purpose:       Check whether GBUS error Interrupt (GBERINT)is active and
 *                clear the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqGber(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      eGDC_IsIrqGpe
 *
 * Purpose:       Check whether GPEINT Interrupt is active and
 *                clear the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e  eGDC_IsIrqGpe(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      eGDC_IsIrqDle
 *
 * Purpose:       Check whether DLEINT Interrupt is active and
 *                clear the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqDle(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      eGDC_IsIrqApe
 *
 * Purpose:       Check whether APEINT Interrupt is active and
 *                clear the corresponding flag
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Active status
 *
 * Return Values: none
 *
 * Limitations:   Interrupt flag will be cleared if it was active. Process
 *                one controller at a time
 *
 ***************************************************************************/
gdc_irqact_e eGDC_IsIrqApe(gdc_ch_e eGDC);


#endif /* _EXTENDED_GDC_APIS_DISABLED_ */

/****************************************************************************/



/***************************************************************************
*
*                        P A N E L   I N T E R F A C E
*                  A P I' s   V A L I D  O N L Y   F O R   GDC0
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      vGDC_PnlGppOutEnable
 *
 * Purpose:       Enable/disable the General Purpose Pulse Output
 *                Valid only for GDC0
 *
 * Inputs:        ePin  General purpose pin [GPPx]
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_PnlGppOutEnable(gdc_gpp_e ePin, gdc_en_e eEn);

/****************************************************************************
 *
 * Function:      vGDC_SetPnlPositiveSyncSelect
 *
 * Purpose:       Set positive panel synchronization select
 *                Valid only for GDC0
 *
 * Inputs:        eSync    low-/high-active input
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPnlPositiveSyncSelect(gdc_ppsync_e eSync);

/****************************************************************************
 *
 * Function:      boGDC_IsPnlRSPowerUpFinished
 *
 * Purpose:       Check if Reduced Swing Power Up sequence is finished
 *                Valid only for GDC0
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: C_FALSE  RSDS power up sequence not finished
 *                C_TRUE   RSDS power up sequence finished
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGDC_IsPnlRSPowerUpFinished(void);

/****************************************************************************
 *
 * Function:      boGDC_IsPnlRSReady
 *
 * Purpose:       Check if Reduced Swing DS is ready to be used
 *                Valid only for GDC0
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: C_FALSE  RSDS power up and enable sequence not finished
 *                C_TRUE   RSDS is read to be used
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGDC_IsPnlRSReady(void);

/****************************************************************************
 *
 * Function:      vGDC_SetPnlRSDSEnable
 *
 * Purpose:       Enable Reduced Swing Differential Signaling
 *                Valid only for GDC0
 *
 * Inputs:        eOutput  digital / differential output
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPnlRSDSEnable(gdc_rsdsen_e eOutput);

/****************************************************************************
 *
 * Function:      vGDC_SetPnlSyncModeEnable
 *
 * Purpose:       Panel Synchronization Mode Enable
 *                Valid only for GDC0
 *
 * Inputs:        eEn      disable / enable to trigger PNL_syncin
 *                         Panel Timing Control Interface Output
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPnlSyncModeEnable(gdc_en_e eEn);

/****************************************************************************
 *
 * Function:      vGDC_SetPnlRSDSOutputCurrentMode
 *
 * Purpose:       Set RSDS output current mode
 *                Valid only for GDC0
 *
 * Inputs:        eOutMode Output Current mode (high, medium, low, HI-Z)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPnlRSDSOutputCurrentMode(gdc_rsdsoutmode_e eOutMode);

/****************************************************************************
 *
 * Function:      vGDC_SetPnlRSDSPreEmphasisMode
 *
 * Purpose:       Set RSDS pre-emphasis mode
 *                Valid only for GDC0
 *
 * Inputs:        ePreEmp  pre-emphasis mode (high, medium, low, disabled)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPnlRSDSPreEmphasisMode(gdc_rsdspreemp_e ePreEmp);

/****************************************************************************
 *
 * Function:      vGDC_SetPnlRSDSHighImpedanceEnable
 *
 * Purpose:       Enable RSDS high impedance, or select differential output
 *                Valid only for GDC0
 *
 * Inputs:        eEn      enable high impedance
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPnlRSDSHighImpedanceEnable(gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      boGDC_IsPnlInputSync
 *
 * Purpose:       Check if monitoring bit for synchronization input signal
 *                from panel is set
 *                Valid only for GDC0
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: C_FALSE  not synchronized
 *                C_TRUE   synchronized
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGDC_IsPnlInputSync(void);


/****************************************************************************
 *
 * Function:      boGDC_IsPnlTimingControlInterfaceEnabled
 *
 * Purpose:       Check if panel timing control interface is enabled
 *                Valid only for GDC0
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: C_FALSE  panel timing control interface disabled
 *                C_TRUE   panel timing control interface enabled
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGDC_IsPnlTimingControlInterfaceEnabled(void);


/****************************************************************************
 *
 * Function:      vGDC_SetPnlAlignData
 *
 * Purpose:       Set the data alignment between DISP_RGB and PNL_ERGB bus
 *                [DISP_RGB and PNL_ERGB can change values at same clock edge
 *                or PNL_ERGB output is delayed by half of PNL_CLOCK cycle]
 *                Valid only for GDC0
 *
 * Inputs:        eAllign  Alignment request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetAlignData(gdc_ddal_e eAllign);


/****************************************************************************
 *
 * Function:      vGDC_SetPnlAlignClock
 *
 * Purpose:       Set the data to clock alignment [DISP_RGB output can change
 *                with rising or falling DISP_dotclk edge]
 *                Valid only for GDC0
 *
 * Inputs:        eEdge  Active DISP_dotclk edge selection
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetPnlAlignClock(gdc_dcal_e eEdge);


/****************************************************************************
 *
 * Function:      vGDC_PnlAlterEnable
 *
 * Purpose:       Enable/disable data alternation [DISP_RGB and PNL_ERGB]
 *                Valid only for GDC0
 *
 * Inputs:        eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_PnlAlterEnable(gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_PnlEvenDataInvEnable
 *
 * Purpose:       Enable/disable the even interface data inversion [RGB out]
 *                Valid only for GDC0
 *
 * Inputs:        eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Please note that inversion can be only achieved when
 *                GPP1 == 1. Process one controller at a time
 *
 ***************************************************************************/
void vGDC_PnlEvenDataInvEnable(gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_PnlEvenRgbOutEnable
 *
 * Purpose:       Enable/disable PNL_ERGB output [Even RGB interface]
 *                Valid only for GDC0
 *
 * Inputs:        eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_PnlEvenRgbOutEnable(gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_PnlOddDataInvEnable
 *
 * Purpose:       Enable/disable the odd interface data inversion [RGB out]
 *                Valid only for GDC0
 *
 * Inputs:        eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Please note that inversion can be only achieved when
 *                GPP0 == 1. Process one controller at a time
 *
 ***************************************************************************/
void vGDC_PnlOddDataInvEnable(gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      vGDC_PnlOddRgbOutEnable
 *
 * Purpose:       Enables/disables output for DISP_RGB (Odd RGB interface)
 *                Valid only for GDC0
 *
 * Inputs:        eEn   Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_PnlOddRgbOutEnable(gdc_en_e eEn);

/****************************************************************************
 *
 * Function:      i32GDC_PnlSyncMode
 *
 * Purpose:       Affect the delay time between synchronization input and data output.
 *                It is combined out of u16PnlSyncModeDelay  and u16PnlSyncDataDelay.
 *                Valid only for GDC0
 *
 * Inputs:        u16PnlSyncModeDelay:  Panel Synchronization Mode Delay
 *                                        Value may be in the range of 7 to 2047.
 *                u8PnlSyncDataDelay:   Panel Synchronization Mode Data Delay
 *                                        Value may be in the range of 0 to 15.
 * Outputs:       none
 *
 * Return Values: C_SUCCESS : No error
 *                C_FAILED  : parameter range problem
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
int32_t i32GDC_PnlSyncMode(uint16_t u16PnlSyncModeDelay, uint8_t u8PnlSyncDataDelay);


#ifndef _EXTENDED_GDC_APIS_DISABLED_
/****************************************************************************
 *
 * Function:      boGDC_SetPulseGen
 *
 * Purpose:       Set Pulse Generator properties
 *
 * Inputs:        eGDC        Controller channel
 *                ePGenID:    Selected pulse generator (0..11) to configure
 *                ePGenOut:   Combinatorial logic output selection
 *                ePGenClk:   Clock-gating enables Output general purpose pulse 
 *                            or Output dot clock gated with general purpose pulse
 *                ePGenTrig:  Trigger signal selection for related general purpose 
 *                            pulse generator
 * 
 * Outputs:       none
 *
 * Return Values: C_TRUE/C_FALSE
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
 bool_t boGDC_SetPulseGen(gdc_ch_e eGDC,
                          gdc_pg_gen_id_e   ePGenID,
                          gdc_pg_outsel_e   ePGenOut,
                          gdc_pg_cgsel_e    ePGenClk,
                          gdc_pg_trigger_e  ePGenTrig);

/****************************************************************************
 *
 * Function:      boGDC_ConfigPulseGenA_B
 *
 * Purpose:       Configures One Shot Pulsgenerator A or B
 *
 * Inputs:        eGDC         Controller channel
 *                ePGenID:     Selected pulse generator (0..11) to configure 
 *                eGenA_B:     Selected generator A or B to configure
 *                pstConfig:   Pointer to configuration structure for  pulse generator A or B
 * 
 * Outputs:        none
 *
 * Return Values: C_TRUE/C_FALSE
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGDC_ConfigPulseGenA_B(gdc_ch_e eGDC,
                               gdc_pg_gen_id_e      ePGenID,
                               gdc_pg_A_B_e         eGenA_B,
                               gdc_pulse_config_st  *pstConfig);

#endif /* _EXTENDED_GDC_APIS_DISABLED_ */

/****************************************************************************/



/***************************************************************************
*
*            A U T O M A T I C    P I X E L    C H E C K E R
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      vGDC_APCConfigure
 *
 * Purpose:       Configure the automatic pixel checker
 *
 * Inputs:        eGDC    Controller channel
 *                pstCfg  Pointer to configuration structure
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_APCConfigure(gdc_ch_e eGDC, gdc_apccfg_st* pstCfg);


/****************************************************************************
 *
 * Function:      vGDC_APCEnable
 *
 * Purpose:       Enable/disable the automatic pixel checker
 *
 * Inputs:        eGDC  Controller channel
 *                eEn   Enable/disable request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_APCEnable(gdc_ch_e eGDC, gdc_en_e eEn);


/****************************************************************************
 *
 * Function:      boGDC_IsAPCError
 *
 * Purpose:       Check whether compare error was detected
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE  if detected
 *                C_FALSE if not detected
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGDC_IsAPCError(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      vGDC_SetAPCCR_PolynomialGen
 *
 * Purpose:       Change Polynomial generator (default: 0x23)
 *                NOTE: Changing this value is not recommended!
 *
 * Inputs:        eGDC      Controller channel
 *                u8PgValue PG-Value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
void vGDC_SetAPCCR_PolynomialGen(gdc_ch_e eGDC, uint8_t u8PgValue);


/****************************************************************************
 *
 * Function:      u32GDC_GetAPCResult
 *
 * Purpose:       Retrieve the result of the last computation
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       Last computation result
 *
 * Return Values: none
 *
 * Limitations:   The bits will be automatically cleared after the read.
 *                Process one controller at a time
 *
 ***************************************************************************/
uint32_t u32GDC_GetAPCResult(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      u32GDC_GetAPCPixelVal
 *
 * Purpose:       Retrieve current/previous pixel value set
 *
 * Inputs:        eGDC  Controller channel
 *                ePix  Pixel set
 *
 * Outputs:       Pixel value set
 *
 * Return Values: none
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
uint32_t u32GDC_GetAPCPixelVal(gdc_ch_e eGDC, gdc_apcp_e ePix);


#ifndef _EXTENDED_GDC_APIS_DISABLED_
/*+-----------------------------------------------------------------------+*
 *|     START-Extended new APIs                                           |*
 *+-----------------------------------------------------------------------+*/

/****************************************************************************
 *
 * Function:      vGDC_SetApcWriteProtection
 *
 * Purpose:       Defines level of Write protection for APC control registers
 *
 * Inputs:        eGDC         Controller channel
 *                eProtection  Protection Level
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGDC_SetApcWriteProtection(gdc_ch_e eGDC, gdc_write_protect_e eProtection);


#endif /* _EXTENDED_GDC_APIS_DISABLED_ */



#ifndef _EXTENDED_GDC_APIS_DISABLED_
/***************************************************************************
*
*                      Bus Errors and Collision Detection
*
****************************************************************************/

/****************************************************************************
 *
 * Function:      u16GDC_GetLastGAPIFColAddr
 *
 * Purpose:       Get last GAPIF colision error address
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       none
 *
 * Return Values: the address
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
uint16_t u16GDC_GetLastGAPIFColAddr(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      boGDC_GetBusErrAddr
 *
 * Purpose:       Returns the triggering access’s address after bus error on GB 
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       pu32BusErrAddr: Pointer to bus error address
 *
 * Return Values: Any Error?
 *                C_TRUE:  No Error
 *                C_FALSE: NULL pointer
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGDC_GetBusErrAddr(gdc_ch_e eGDC, uint32_t* pu32BusErrAddr);


/****************************************************************************
 *
 * Function:      boGDC_GetBusErrCtrlStatus
 *
 * Purpose:       Returns the triggering access’s control status after bus error on GB
 *
 * Inputs:        eGDC  Controller channel
 *
 * Outputs:       control status structure
 *
 * Return Values: Any Error?
 *                C_TRUE:  No Error
 *                C_FALSE: NULL pointer
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGDC_GetBusErrCtrlStatus(gdc_ch_e eGDC, gdc_bus_err_ctrl_st* pstCtrlStatus);


/****************************************************************************
 *
 * Function:      eGDC_GetDcrBusErrors
 *
 * Purpose:       Get status of bus error in GDCDCR register
 *
 * Inputs:        eGDC      Controller channel
 *
 * Outputs:       none
 *
 * Return Values: evtl. raised errors
 *
 * Limitations:   none
 *
 ***************************************************************************/
gdc_dcr_err_e eGDC_GetDcrBusErrors(gdc_ch_e eGDC);


/****************************************************************************
 *
 * Function:      boGDC_ClrDcrBusErrors
 *
 * Purpose:       Clears error Bits (GBER, GAPCOL) in GDC register
 *                Note:
 *                     Clear GAPINT by call of function eGDC_IsIrqGap() will also
 *                     clear GAPCOL error bit.
 *
 * Inputs:        eGDC      Controller channel
 *                eClrBits  Clear Bits
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boGDC_ClrDcrBusErrors(gdc_ch_e eGDC, gdc_dcr_err_e eClrBits);


#endif /* _EXTENDED_GDC_APIS_DISABLED_ */


/*+-----------------------------------------------------------------------+*
 *|     END-Extended new APIs                                             |*
 *+-----------------------------------------------------------------------+*/

/****************************************************************************/

#endif /* GDC_H */

/****************************************************************************/


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: gdc.h
**  $Revision: 1.20 $
**  $Date: 2015/05/04 09:07:14 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :
** |
** | CONS.  :
** |
** | REASON :
** |
**  ------------------------------------------------------------------------
*****************************************************************************
****************************************************************************/

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

