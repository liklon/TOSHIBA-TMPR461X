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
*   VERSION     : $Revision: 1.15 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TRANSF_H
#define TRANSF_H

/*======================================
             Include Files
=======================================*/
#include "captypes.h"
#include "ga_common.h"

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1840   /* Rule 5.7 [A] : identifier reused from declaration of entity-kind "entity" */

#endif  

/*======================================
                Defs
=======================================*/

#define LLDD_GA_TRANSF_H_REVISION     "$Revision: 1.15 $"
#define LLDD_GA_TRANSF_H_TAG          "$Name: LLDD_1_7_GFX $"

/*--------------------------------------------------------------------------
|       ------------------------------------------------------------        |
|      | >>>>>>     TRANSFORMATION ENGINE COMMAND INDEX      <<<<<< |       |
|       ------------------------------------------------------------        |
|---------------------------------------------------------------------------|
|---------------------------------------------------------------------------|
|                                                                           |
|                      ------------------------------                       |
|                     |      OPERATION COMMANDS      |                      |
|                      ------------------------------                       |
|                                                                           |
| - Commands:                                                               |
|   1. TSF_TRANSF           -Transformation Command                         |
|   2. TSF_TRANSFB          -Transformation Command with blend              |
|                                                                           |
|---------------------------------------------------------------------------|
|                                                                           |
|                    ----------------------------------                     |
|                   |      LOAD REGISTER COMMANDS      |                    |
|                    ----------------------------------                     |
|                                                                           |
| - Source Regs:                                                            |
|   1. TSF_LOAD_SOURCEADDR  -  Load Source Address Reg.               (SAR) |
|   2. TSF_LOAD_SRCWIDTH    -  Load Source Memory Width Reg.         (SMWR) |
|   3. TSF_LOAD_SRCALPHA    -  Load Source Alpha Value Register      (SAVR) |
|   4. TSF_LOAD_SRCFADEFACT -  Load Source Fading Factor register    (SFFR) |
|                                                                           |
| - Destination Regs:                                                       |
|   5. TSF_LOAD_DESTADDR    -  Load Destination Address Reg.          (DAR) |
|   6. TSF_LOAD_DESTWIDTH   -  Load Destination Memory Width Reg.    (DMWR) |
|   7. TSF_LOAD_DEST_IMAGEWIDTH  -  Load Destination Image Width Reg. (DWR) |
|   8. TSF_LOAD_DESTLINECNT -  Load Destination Blit LINE Count Reg. (DLCR) |
|   9. TSF_LOAD_DESTALPHA   -  Load Destination Alpha Value Register (DAVR) |
|                                                                           |
| - CLUT Regs:                                                              |
|  10. TSF_LOAD_LUTADDR     -  Load LUT Address Register              (LAR) |
|  11. TSF_LOAD_LUTWIDTH    -  Load LUT Width Register                (LWR) |
|  12. TSF_LOAD_LUTLINECNT  -  Load LUT Line Count Register          (LLCR) |
|                                                                           |
| - Color Regs:                                                             |
|  13. TSF_LOAD_COLORFMT    - Load Color Format Register              (CFR) |
|  14. TSF_LOAD_PRECOLOR    - Load Clipping Window Width Reg.        (CWWR) |
|                                                                           |
 --------------------------------------------------------------------------*/

/*=========================================================================
|                            OPERATION COMMANDS                             |
 ==========================================================================*/
/*--------------------------------------------------------------------------
|
|  Command:   Transform
|
|  Descr  :   The Transformation Engine uses only one command pattern to be
|             triggered.
|
|  Params:    modeSel  - Mode Control
|                        Use: GA_MODE_PIXEL   - Pixel Mode
|                             GA_MODE_COLORCH - Color channel Mode
|
|             filterEn - Filter Control
|                        Use: GA_EN           - Enable Filter
|                             GA_DIS          - Disable Filter
|
|
 -------------------------------------------------------------------------*/
#define TSF_TRANSF(modeSel,filterEn)(GA_CMN(GA_TRANSFORM, 1, GA_CMC_TRANSF,\
                                     GA_FP ((modeSel),    1, GA_MASK1)   | \
                                     GA_FP ((filterEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Transform blend
|
|  Descr  :   The Transformation Engine uses only one command pattern to be
|             triggered.
|
|  Params:   modeSel      - Mode Control
|                           Use: GA_MODE_PIXEL    - Pixel Mode
|                                GA_MODE_COLORCH  - Color channel Mode
|                         
|            redChProt    - Red Channel Protection
|                           Use: GA_EN            - Channel Protected
|                                GA_DIS           - Channel Not Protected
|                         
|             greenChProt - Green Channel Protection
|                           Use: GA_EN            - Channel Protected
|                                GA_DIS           - Channel Not Protected
|                         
|             blueChProt  - Blue Channel Protection
|                           Use: GA_EN            - Channel Protected
|                                GA_DIS           - Channel Not Protected
|                         
|             alphaProt   - Alpha Channel Protection
|                           Use: GA_EN            - Channel Protected
|                                GA_DIS           - Channel Not Protected
|                         
|             redChFad    - Red Channel Fading
|                            Use: GA_EN           - Channel Protected
|                                 GA_DIS          - Channel Not Protected
|                         
|             greenChFad  - Green Channel Fading
|                            Use: GA_EN           - Channel Protected
|                                 GA_DIS          - Channel Not Protected
|                         
|             blueChFad   - Blue Channel Fading
|                            Use: GA_EN           - Channel Protected
|                                 GA_DIS          - Channel Not Protected
|                         
|             alphaFad    - Alpha Channel Fading
|                            Use: GA_EN           - Channel Protected
|                                 GA_DIS          - Channel Not Protected
|                         
|             blndOrder    - Blending Order
|                            Use: TSF_ONTO_DEST   - Onto destination
|                                 TSF_BEHIND_DEST - Behind the destination
|                         
|             filterEn     - Filter Control
|                            Use: GA_EN           - Enable Filter
|                                 GA_DIS          - Disable Filter
|
|
 -------------------------------------------------------------------------*/
#define TSF_TRANSFB(modeSel,                                               \
                    redChProt,                                             \
                    greenChProt,                                           \
                    blueChProt,                                            \
                    alphaProt,                                             \
                    redChFad,                                              \
                    greenChFad,                                            \
                    blueChFad,                                             \
                    alphaFad,                                              \
                    blndOrder,                                             \
                    filterEn)                                              \
                        (GA_CMN(GA_TRANSFORM,  1, GA_CMC_TRANSFB,          \
                         GA_FP ((redChProt),  15, GA_MASK1)        |       \
                         GA_FP ((greenChProt),14, GA_MASK1)        |       \
                         GA_FP ((blueChProt), 13, GA_MASK1)        |       \
                         GA_FP ((alphaProt),  12, GA_MASK1)        |       \
                         GA_FP ((redChFad),   11, GA_MASK1)        |       \
                         GA_FP ((greenChFad), 10, GA_MASK1)        |       \
                         GA_FP ((blueChFad),   9, GA_MASK1)        |       \
                         GA_FP ((alphaFad),    8, GA_MASK1)        |       \
                         GA_FP ((blndOrder),   3, GA_MASK2)        |       \
                         GA_FP ((modeSel),     1, GA_MASK1)        |       \
                         GA_FP ((filterEn),    0, GA_MASK1)))


/*=========================================================================
|                          LOAD REGISTER COMMANDS                           |
 ==========================================================================*/
/*------------------------------
|        SOURCE REGISTERS       |
 -------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Source Address Register (SAR)
|
|  Descr  :   The Load General-Purpose Register command is used to load SAR.
|             The physical 32-bit address within the source address register
|             is the pointer to the first dot of the source.
|
|  Params:    addr - Source Address
|                    The lower 32 physical address bits that point to the
|                    first dot of the source.
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_SOURCEADDR(addr) (GA_LOAD(GA_GPR9, (addr)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Source Memory Width Register (SMWR)
|
|  Descr  :   The Load General-Purpose Register command is used to load SMWR.
|             The source memory width register specifies the memory reserved
|             for one line within the source image in number of dots.
|
|
|  Params:    width - Source Memory Width
|                     Memory reserved per line within the source in dots
|                     (1 up to 4095)
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_SRCWIDTH(width) (GA_LOAD(GA_GPR10, (width)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Alpha Value Register (SAVR)
|
|  Descr  :   The Source Alpha Value Register keeps the alpha value for
|             conversion of the source dots from the 16-bit RGB format to
|             the 32-bit RGBA format for internal processing.
|
|  Params:    srcalpha - source alpha value
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_SRCALPHA(srcalpha) (GA_LOAD(GA_GPR27,                     \
                                     ((srcalpha) & GA_MASK8)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Source Fading Factor Register (SFFR)
|
|  Descr  :   The Source Fading Factor Register holds the fading factor enumerator
|             (SFFE) of the fading factor.
|
|  Params:    factor  - Source Fading Factor Enumerator
|                       These bits specify the enumerator of the fading
|                       factor FFACT.
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_SRCFADEFACT(factor) (GA_LOAD(GA_GPR26,                       \
                                   ((factor) & GA_MASK8)))

/*------------------------------
|     DESTINATION REGISTERS     |
 -------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Address Register (DAR)
|
|  Descr  :   The physical 32-bit address within the destination address
|             register is the pointer to the first dot in the memory region,
|             where the transformed bitmap will be placed. Depending on
|             the source color format, which is equal to the destination
|             color format, this address has to be word- (RGBA32) or
|             halfword- (RGB16) aligned.
|
|  Params:    addr - Destination Address
|                    The lower 32 physical address bits that point to the
|                    first dot of the destination.
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_DESTADDR(addr) (GA_LOAD(GA_GPR4, (addr)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Memory Width Register (DMWR)
|
|  Descr  :   The destination memory width register specifies the memory
|             reserved for one line within the destination image in number
|             of dots.
|             Note that this value can be greater than the number of dots
|             to be blitted per line.
|
|  Params:    width - Destination Memory Width
|                     Memory reserved per line within the source in dots
|                     (1 up to 4095)
|
|  Limit.:    The content of this register is not taken into account when the
|             Blitting Engine is configured to read a run-length encoded
|             image. When the source is run-length encoded the destinations
|             dimensions have to match the dimensions of the source exactly
|             (number of dots).
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_DESTWIDTH(width) (GA_LOAD(GA_GPR5, (width)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Image Width Register (DWR)
|
|  Descr  :   The destination image width register specifies the number of
|             dots per line of the destination image. In pixel mode, the
|             least value of LUT Width Register and Destination Image Width
|             Register is used to determine the width of the processed area.
|
|  Params:    width - Destination Image Width
|                     Dots per line within the destination
|                     (from 1 up to 1023).
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_DEST_IMAGEWIDTH(width) (GA_LOAD(GA_GPR6,                 \
                                         ((width)& GA_MASK10)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Image Line Count Register (DLCR)
|
|  Descr  :   The destination line count register specifies the number of
|             lines of the destination image. The least value of LUT Line
|             Count Register and Destination Image Line Count Register is
|             used to determine the height of the processed area.
|
|  Params:    lineCnt - Number of destination lines to be processed
|                       (from 1 up to 1023).
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_DESTLINECNT(lineCnt) (GA_LOAD(GA_GPR7,                   \
                                       ((lineCnt) & GA_MASK10)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Alpha Value Register (DAVR)
|
|  Descr  :   The Destination Alpha Value Register keeps the alpha value
|             used during conversion of the destination dots from the
|             16-bit RGB format to the 32-bit RGBA format.
|
|  Params:    dstalpha - destination alpha value
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_DESTALPHA(dstalpha) (GA_LOAD(GA_GPR28,                    \
                                      ((dstalpha) & GA_MASK8)))


/*------------------------------
|         L U T REGISTERS       |
 -------------------------------*/

/*--------------------------------------------------------------------------
|
|  Command:   Load LUT Address Register (LAR)
|
|  Descr  :   The Load General-Purpose Register command is used to load LAR.
|             The physical 32-bit address within the look-up table address
|             register is the pointer to the first look-up table entry in
|             memory. This address has to be word-aligned.
|
|  Params:    addr - LUT Address
|                    The lower 32 physical address bits that point to the
|                    first entry of the LUT.
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_LUTADDR(addr) (GA_LOAD(GA_GPR13, (addr)))

/*--------------------------------------------------------------------------
|
|  Command:   Load LUT Width Register (LWR)
|
|  Descr  :   The LUT width register specifies the number of entries per line
|             within the look-up table. In pixel mode, the least value of LUT
|             width register and destination image width register is used to
|             determine the width of the processed area. In color channel
|             mode, this width has to be three times the destination image
|             width for RGB16 color format and four times the destination
|             image width for RGBA32 color format.
|
|
|  Params:    width - LUT Width
|                     Entries per line within the look-up table
|                     (from 1 up to 4095).
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_LUTWIDTH(width) (GA_LOAD(GA_GPR14,                        \
                                  ((width)& GA_MASK12)))

/*--------------------------------------------------------------------------
|
|  Command:   Load LUT Line Count Register (LLCR)
|
|  Descr  :   The source line count register specifies the number of lines
|             of the look-up table. The least value of LUT Line Count
|             Register and Destination Image Line Count Register is used to
|             determine the height of the processed area.
|
|
|  Params:    lineCnt - LUT Line Count
|                       Number of source lines to be transformed
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_LUTLINECNT(lineCnt) (GA_LOAD(GA_GPR15,                   \
                                      ((lineCnt) & GA_MASK10)))



/*------------------------------
|        COLOR REGISTERS        |
 -------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Color Format Register (CFR)
|
|  Descr  :   This register specifies the color format of source
|             and destination.
|
|  Params:    srcformat  - Source color format
|                       	 Use parameters:
|                       	 GA_RGB16    - 16-bit RGB
|                       	 GA_RGBA32   - 32-bit RGBA
|  				 dstformat   - destination color format
|                       	 Use parameters:
|                       	 GA_RGB16    - 16-bit RGB
|                       	 GA_RGBA32   - 32-bit RGBA
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_COLORFMT(dstformat, srcformat) (GA_LOAD(GA_GPR16,        \
                                   (GA_FP((dstformat), 1, GA_MASK1)   |	  \
                                    GA_FP((srcformat), 0, GA_MASK1))))

/*--------------------------------------------------------------------------
|
|  Command:   Load Predefined Color Register (PCR)
|
|  Descr  :   The Predefined Color Register gives the color of the
|             destination dot, if the LUT indexes position 0xFFFF for the x
|             coordinate and 0xFFFF for the y coordinate.
|
|             When using 32-bit RGBA color format, the complete 32 bit of
|             the register are assigned as color value to the corresponding
|             pixel. When using 16-bit RGB color format, only the bits [15:0]
|             are used as predefined color. The bits [31:16] are not
|             regarded.
|
|  Params:    colVal - Predefined Color
|                      This color is used for LUT entries which point to
|                      (0xFFFF/0xFFFF).
|
 -------------------------------------------------------------------------*/
#define TSF_LOAD_PRECOLOR(colVal) (GA_LOAD(GA_GPR17, (colVal)))

/*======================================
                Enums
=======================================*/
/* Transformation mode */
typedef enum tag_transf_Mode_e
{
    TSF_MODE_PIXEL = 0x0u,          /* Pixel Mode Operation */
    TSF_MODE_COLOR = 0x1u           /* Color Mode Operation */
} transf_Mode_e;

/*======================================
              Structures
=======================================*/
/* LUT Configuration Strucuture */
typedef struct tag_transf_Lut_st
{
    uint32_t u32Addr;               /* Look-up table address */
    uint16_t u16Width;              /* Look-up table width  (1 to 4095) */
    uint16_t u16LineCnt;            /* Look-up table line count(1 to 1023) */
} transf_Lut_st;

/* Memory Configuration structure */
typedef struct tag_transf_mem_st
{
    /* Source Mem. Params */
    uint16_t      u16SrcWidth;      /* Source Memory Width (Dots Per Line) */
    uint32_t      u32SrcAddr;       /* Source Memory Addr. First Src. Dot
                                       (Each function specifies its own
                                        memory alignment rules) */
    /* Destination Mem. Params */
    uint16_t      u16DstWidth;      /* Dest. Memory Width (Dots Per Line) */
    uint32_t      u32DstAddr;       /* Dest. Memory Addr. First Src. Dot
                                       (Each function specifies its own
                                        memory alignment rules) */
    /* Dest. Image Area Size */
    uint16_t      u16DstImgWidth;   /* Dot Number per line to be blitted */
    uint16_t      u16LineCnt;       /* Line Number to be blitted */
} transf_mem_st;

/* Transform Config Struct */
typedef struct tag_transf_Prm_st
{
    transf_Mode_e   eTsfMode;       /* Transform. Mode (Pixel-/Color-Mode) */
    ga_en_e         eFilterEn;      /* Enable Filtering */
    ga_colFmt_e     eSrcColFmt;     /* Source Color Format selection */
    ga_colFmt_e     eDstColFmt;     /* Destination Color Format selection */
    uint32_t        u32Color;       /* Predefined Color (used for
                                       LUT 0xFFFF entries) */
    uint8_t        u8SrcAlphaVal;   /* Source Alpha value */
    uint8_t        u8DstAlphaVal;   /* Destination Alpha value */
} transf_Prm_st;

/* Transform Blend Config Struct */
typedef struct tag_transf_PrmBlend_st
{
    transf_Mode_e   eTsfMode;       /* Transform. Mode (Pixel-/Color-Mode) */
    ga_en_e         eFilterEn;      /* Enable Filtering */
    ga_en_e         eDstRedProt;    /* Destination red color protection */
    ga_en_e         eDstGreenProt;  /* Destination green color protection */
    ga_en_e         eDstBlueProt;   /* Destination blue color protection */
    ga_en_e         eDstAlphaProt;  /* Destination alpha protection */
    ga_en_e         eSrcRedFad;     /* Source red color protection */
    ga_en_e         eSrcGreenFad;   /* Source green color protection */
    ga_en_e         eSrcBlueFad;    /* Source blue color protection */
    ga_en_e         eSrcAlphaFad;   /* Source alpha protection */
    ga_blendOrd_e   eBldOrd;        /* Blend order */
    ga_colFmt_e     eSrcColFmt;     /* Source Color Format selection */
    ga_colFmt_e     eDstColFmt;     /* Destination Color Format selection */
    uint32_t        u32Color;       /* Predefined Color (used for
                                       LUT 0xFFFF entries) */
    uint8_t        u8FadingFctr;    /* Fading facror */
    uint8_t        u8SrcAlphaVal;   /* Source Alpha value */
    uint8_t        u8DstAlphaVal;   /* Destination Alpha value */
} transf_PrmBlend_st;


/*======================================
      Exported Function Prototypes
=======================================*/

/****************************************************************************
 *
 * Function:      vTransf_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                        uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);

/*-------------------------------------------------------------------------
|
|                      B A S I C      O P E R A T I O N S
|
 --------------------------------------------------------------------------*/
/****************************************************************************
 *
 * Function:      vTransf_SetMemSrc
 *
 * Purpose:       Sets Transf source parameters in Command List
 *
 * Inputs:        u32Addr    - Source Memory Address
 *                             (First Dot of the source)
 *
 *                u32Width   - Source Memory Width
 *                             (Memory reserved per line within the source in
 *                              dots: 1 up to 4095)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_SetMemSrc(uint32_t u32Addr, uint32_t u32Width, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vTransf_SetDstImgSize
 *
 * Purpose:       Sets in the Command List the size of the destination image
 *                (number of dots per line and number of image lines)
 *
 * Inputs:        u32Width   - Destination Image Width in Dot Number
 *                             (1 up to 4095)
 *                u32Lines   - Destination Image Line Number
 *                             (1 up to 1023)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_SetDstImgSize(uint32_t u32Width, uint32_t u32Lines,
                           ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vTransf_SetMemDest
 *
 * Purpose:       Sets the destination memory parameters in the Command List
 *
 * Inputs:        u32Addr    - Destination Memory Address
 *                             (First Dot of the destination)
 *
 *                u32Width   - Destination Memory Width
 *                             (Memory reserved per line within the destinatio
 *                              in dots: 1 up to 4095)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_SetMemDest(uint32_t u32Addr, uint32_t u32Width, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vTransf_ConfigLUT
 *
 * Purpose:       Configures the transformation look-up table parameters
 *                  - Memory location,
 *                  - LUT Width,
 *                  - LUT line count
 *
 * Inputs:        stCfg      - pointer to LUT configuration parameters
 *                             (for more details see the struct. desc.s)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_ConfigLUT(transf_Lut_st* pstCfg, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vTransf_SetColorFmt
 *
 * Purpose:       Sets the color format of the both source and destination.
 *
 * Inputs:        eSrcColFormat - Source Color Format Selection
 *                             		(16-bit RGB/ 32-bit RGBA)
 * 								eDstColFormat - Destination Color Format Selection
 *                             	  (16-bit RGB/ 32-bit RGBA)
 *
 *                pstCmdList    - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Please note that Transformation Engine cannot convert color
 *                format, therefore formats for both (src. and dst.) must be
 *                the same.
 *
 ***************************************************************************/
void vTransf_SetColorFmt(ga_colFmt_e eSrcColFormat, ga_colFmt_e eDstColFormat, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vTransf_SetPredefColor
 *
 * Purpose:       Sets the predefined color which is used for LUT entries
 *                which point to (0xFFFF/0xFFFF).
 *
 * Inputs:        u32Color   - Color Value. Must be set in the same format as
 *                             the format specified by Transf_SetColorFmt().
 *                             This means that in RGBA format all 32-bits will
 *                             be evaluated and in case of RGB only 16-bits.
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_SetPredefColor(uint32_t u32Color, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vTransf_SetTransfCmd
 *
 * Purpose:       Inserts the transformation command in the Command List
 *
 * Inputs:        eOpMode    - Mode Control selects between Pixel Mode and
 *                             Channel Control Mode.
 *
 *                eFilterEn  - Filter Control (Enables/Disables the filter)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_SetTransfCmd(transf_Mode_e eOpMode, ga_en_e eFilterEn,
                         ga_list_st* pstCmdList);

/*-------------------------------------------------------------------------
|
|            T R A N S F O R M A T I O N     O P E R A T I O N
|
 --------------------------------------------------------------------------*/
/****************************************************************************
 *
 * Function:      vTransf_ConfigTransfOp
 *
 * Purpose:       Inserts in the Command List the transformation-command and
 *                commands for loading of all parameters required for the
 *                transformation command execution.
 *
 * Inputs:        stMem      - pointer to memory configuration parameters
 *
 *                tLutCfg    - pointer to look-up table configuration parameters
 *
 *                tColCfg    - pointer to color Config Parameters
 *
 *                pstCmdList - Pointer to the Command List
 *
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_ConfigTransfOp(transf_mem_st* pstMem, transf_Lut_st* pstLutCfg,
                            transf_Prm_st* pstTsfPrm, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vTransf_ConfigTransfBlendOp
 *
 * Purpose:       Inserts in the Command List the transformation-command and
 *                commands for loading of all parameters required for the
 *                transformation blen command execution.
 *
 * Inputs:        stMem      - pointer to memory configuration parameters
 *
 *                tLutCfg    - pointer to look-up table configuration parameters
 *
 *                tColCfg    - pointer to color Config Parameters
 *
 *                pstCmdList - pointer to the Command List
 *
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTransf_ConfigTransfBlendOp(transf_mem_st* pstMem, transf_Lut_st* pstLutCfg,
                                 transf_PrmBlend_st* pstTsfPrm, ga_list_st* pstCmdList);


/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/

#endif /* TRANSF_H */

/****************************************************************************/


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: transf.h
**  $Revision: 1.15 $
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

