/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronic Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : Graphic Accelerator
*                 Reference Low-Level Driver (Drawing Engine)
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : GA (Drawing Engine)
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.15 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_7_GFX $
****************************************************************************/
#ifndef DRAW_H
#define DRAW_H

/**********************************************
*             Include Files                   *
**********************************************/

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */

#endif/**********************************************
*                Defs                         *
**********************************************/
#define LLDD_GA_DRAW_H_REVISION     "$Revision: 1.15 $"
#define LLDD_GA_DRAW_H_TAG          "$Name: LLDD_1_7_GFX $"

/*--------------------------------------------------------------------------
|       ------------------------------------------------------------        |
|      | >>>>>>         DRAWING ENGINE COMMAND INDEX         <<<<<< |       |
|       ------------------------------------------------------------        |
|---------------------------------------------------------------------------|
|---------------------------------------------------------------------------|
|                                                                           |
|                                                                           |
|                                                                           |
|                      ------------------------------                       |
|                     |      OPERATION COMMANDS      |                      |
|                      ------------------------------                       |
|                                                                           |
| - Commands:                                                               |
|   1. DRW_LINERGBA32       - Draw Line RGBA32 Command                      |
|   2. DRW_LINERGB16        - Draw Line RGB16 Command                       |
|   3. DRW_TRIANGLE_RGBA32  - Draw Triangle RGBA32 Command                  |
|   4. DRW_TRIANGLE_RGB16   - Draw Triangle RGB16 Command                   |
|                                                                           |
|                                                                           |
|---------------------------------------------------------------------------|
|                                                                           |
|                                                                           |
|                                                                           |
|                    ----------------------------------                     |
|                   |      LOAD REGISTER COMMANDS      |                    |
|                    ----------------------------------                     |
|                                                                           |
| - Destination Regs:                                                       |
|   1. DRW_LOAD_DESTADDR    - Load Destination Address Reg.         (DEDAR) |
|   2. DRW_LOAD_DESTDIM     - Load Destination Memory Dim. Reg.     (DEMWR) |
|                                                                           |
| - Color Regs:                                                             |
|   3. DRW_LOAD_RGBA32      - Load RGBA32 Color Register        (DERGBA32R) |
|   4. DRW_LOAD_RGB16       - Load RGB16 Color Register            (DERGBR) |
|   5. DRW_LOAD_RGBA32BGRND - Load RGBA32 Backgr. Color Register  (DEBKG32) |
|   6. DRW_LOAD_RGBA16BGRND - Load RGB16 Backgr. Color Register   (DEBKG16) |
|                                                                           |
| - Line Regs:                                                              |
|   7. DRW_LOAD_LINESTART   - Load Line Start Register              (DELSR) |
|   8. DRW_LOAD_LINEEND     - Load Line End Register                (DELER) |
|   9. DRW_LOAD_THICKNESS   - Load Line Thickness Register          (DELTR) |
|                                                                           |
| - Triangle Regs:                                                          |
|  10. DRW_LOAD_TRNGLE1     - Load Drw.Eng. Triangle Point 1 Reg.  (DETP1R) |
|  11. DRW_LOAD_TRNGLE2     - Load Drw.Eng. Triangle Point 2 Reg.  (DETP2R) |
|  12. DRW_LOAD_TRNGLE3     - Load Drw.Eng. Triangle Point 3 Reg.  (DETP3R) |
|                                                                           |
| - Clipping Window:                                                        |
|  13. DRW_LOAD_CLIPWNDSTART - Load Clipp.Wnd. Start Register      (DECWSR) |
|  14. DRW_LOAD_CLIPWNDEND   - Load Clipp.Wnd. Upper-Left Corner   (DECWER) |
|                                                                           |
 --------------------------------------------------------------------------*/
/*=========================================================================
|                            OPERATION COMMANDS                             |
 ==========================================================================*/
/*--------------------------------------------------------------------------
|
|  Command:   Draw Line RGBA32 Command
|
|  Descr  :   The Draw Line RGBA32 command is used to trigger the Drawing
|             Engine to draw a line in the RGBA32 color space, using the
|             coordinates already programmed in the Line Start Register
|             (DELSR) and Line End Register (DELER). Additionally the color
|             of the line will be the color specified in the RGBA32 Color
|             Register (DERGBAR). The command code is detailed in the
|             following table.
|
|  Params:    startPtStyle - Start point line caps style
|                            Use: DRW_BUTTEND      - Butt end NOT anti-aliased
|                                 DRW_BUTTEND_AA   - Butt end anti-aliased
|                                 DRW_CIRCULAR     - Circular line caps
|
|             endPtStyle - End point line caps style
|                          Use: DRW_BUTTEND        - Butt end NOT anti-aliased
|                               DRW_BUTTEND_AA     - Butt end anti-aliased
|                               DRW_CIRCULAR       - Circular line caps
|
|             blendMode   - Blending mode
|                           Use: DRW_BLEND_OPAQUE  - Opaque blending
|                                DRW_BLEND_TRANSP  - Transparent blending
|                                DRW_OVERWRITING   - Overwriting
|                                DRW_SATURATION    - Saturation
|
|             clippWndEn - Clipping Window Option
|                          Use: GA_EN              - Enable Option
|                               GA_DIS             - Disable Option
|
 -------------------------------------------------------------------------*/
#define DRW_LINERGBA32(startPtStyle,                                   \
                       endPtStyle,                                     \
                       blendMode,                                      \
                       clippWndEn)                                     \
                       (GA_CMN(GA_DRAWING,    1, GA_CMC_DE_DLRGBA32,   \
                        GA_FP((startPtStyle), 8, GA_MASK4)   |         \
                        GA_FP((endPtStyle),   4, GA_MASK4)   |         \
                        GA_FP((blendMode),    1, GA_MASK3)   |         \
                        GA_FP((clippWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Draw Line RGB16 Command
|
|  Descr  :   The Draw Line command is used to trigger the Drawing Engine to
|             draw a line in the RGB16 color space, using the coordinates
|             already programmed in the Line Start Register (DELSR) and Line
|             End Register(DELER). Additionally the color of the line will be
|             the color specified in the RGB16 Color Register (DERGBR).
|             The command code is detailed in the following table.
|
|  Params:    startPtStyle - Start point line caps style
|                            Use: DRW_BUTTEND      - Butt end NOT anti-aliased
|                                 DRW_BUTTEND_AA   - Butt end anti-aliased
|                                 DRW_CIRCULAR     - Circular line caps
|
|             endPtStyle - End point line caps style
|                          Use: DRW_BUTTEND        - Butt end NOT anti-aliased
|                               DRW_BUTTEND_AA     - Butt end anti-aliased
|                               DRW_CIRCULAR       - Circular line caps
|
|             blendMode   - Blending mode
|                           Use: DRW_BLEND_OPAQUE  - Opaque blending
|                                DRW_BLEND_TRANSP  - Transparent blending
|                                DRW_OVERWRITING   - Overwriting
|
|             clippWndEn - Clipping Window Option
|                          Use: GA_EN              - Enable Option
|                               GA_DIS             - Disable Option
|
 -------------------------------------------------------------------------*/
#define DRW_LINERGB16(startPtStyle,                                   \
                      endPtStyle,                                     \
                      blendMode,                                      \
                      clippWndEn)                                     \
                      (GA_CMN(GA_DRAWING,    1, GA_CMC_DE_DLRGB16,    \
                       GA_FP((startPtStyle), 8, GA_MASK4)   |         \
                       GA_FP((endPtStyle),   4, GA_MASK4)   |         \
                       GA_FP((blendMode),    1, GA_MASK3)   |         \
                       GA_FP((clippWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Draw Triangle RGBA32 Command
|
|  Descr  :   The Draw Triangle command is used to trigger the Drawing Engine
|             to draw a triangle. The triangle will have the vertices
|             specified in the Triangle Point 1, 2, and 3 Registers (DEPP1,
|             DEPP2, and DEPP3), and the color specified in the RGBA32 Color
|             Register (DERGBAR).
|
|  Params:    edgAntiEn1,2,3 - Edge 1,2 and 3 antialiasing
|                              Use: GA_EN            - Anti-aliased is on
|                                   GA_DIS           - Anti-aliased is off
|
|             blendMode      - Blending mode
|                              Use: DRW_BLEND_OPAQUE - Opaque blending
|                                   DRW_BLEND_TRANSP - Transparent blending
|                                   DRW_OVERWRITING  - Overwriting
|                                   DRW_SATURATION   - Saturation
|
|             clippWndEn     - Clipping Window Option
|                              Use: GA_EN            - Enable Option
|                                   GA_DIS           - Disable Option
|
|
 -------------------------------------------------------------------------*/
#define DRW_TRIANGLE_RGBA32(edgAntiEn3,                                   \
                            edgAntiEn2,                                   \
                            edgAntiEn1,                                   \
                            blendMode,                                    \
                            clippWndEn)                                   \
                            (GA_CMN(GA_DRAWING,  1, GA_CMC_DE_DTRGBA32,   \
                             GA_FP((edgAntiEn3), 6, GA_MASK1)   |         \
                             GA_FP((edgAntiEn2), 5, GA_MASK1)   |         \
                             GA_FP((edgAntiEn1), 4, GA_MASK1)   |         \
                             GA_FP((blendMode),  1, GA_MASK3)   |         \
                             GA_FP((clippWndEn), 0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Draw Triangle RGB16 Command
|
|  Descr  :   The Draw Triangle command is used to trigger the Drawing Engine
|             to draw a triangle. The triangle will have the vertices
|             specified in the Triangle Point 1, 2, and 3 Registers (DEPP1,
|             DEPP2, and DEPP3), and the color specified in the RGB16 Color
|             Register (DERGBR), according to the color format in use.
|
|  Params:    edgAntiEn1,2,3 - Edge 1,2 and 3 anti-aliasing
|                              Use: GA_EN            - Anti-aliasing is ON
|                                   GA_DIS           - Anti-aliasing is OFF
|
|             blendMode      - Blending mode
|                              Use: DRW_BLEND_OPAQUE - Opaque blending
|                                   DRW_BLEND_TRANSP - Transparent blending
|                                   DRW_OVERWRITING  - Overwriting
|
|             clippWndEn     - Clipping Window Option
|                              Use: GA_EN            - Enable Option
|                                   GA_DIS           - Disable Option
|
 -------------------------------------------------------------------------*/
#define DRW_TRIANGLE_RGB16(edgAntiEn3,                                  \
                           edgAntiEn2,                                  \
                           edgAntiEn1,                                  \
                           blendMode,                                   \
                           clippWndEn)                                  \
                           (GA_CMN(GA_DRAWING,  1, GA_CMC_DE_DTRGB16,   \
                            GA_FP((edgAntiEn3), 6, GA_MASK1)   |        \
                            GA_FP((edgAntiEn2), 5, GA_MASK1)   |        \
                            GA_FP((edgAntiEn1), 4, GA_MASK1)   |        \
                            GA_FP((blendMode),  1, GA_MASK3)   |        \
                            GA_FP((clippWndEn), 0, GA_MASK1)))


/*=========================================================================
|                          LOAD REGISTER COMMANDS                           |
 ==========================================================================*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Clipping Window Start Register (DECWSR)
|
|  Descr  :   This register contains X and Y coordinates of the start
|             (upper left corner) of the clipping window from the origin of
|             the destination area. The offset is programmed in pixels
|             coordinates starting from (0,0), no subpixel resolution is
|             possible in the positioning of the clipping window.
|
|  Params:    x - X starting coordinate of the clipping window
|
|             y - Y starting coordinate of the clipping window
|
|  Limit.:    The contents of this register will be used only if the clipping
|             window option will be selected in one of the Draw Line or Draw
|             Triangle commands.
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_CLIPWNDSTART(x,y) (GA_LOAD(GA_GPR1,                \
                                    GA_FP((y), 16, GA_MASK12)  |    \
                                    GA_FP((x),  0, GA_MASK12)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Clipping Window End Register (DECWER)
|
|  Descr  :   The end coordinates (lower right corner) of the clipping window
|             in pixels, will be programmed into this register. The user has
|             to take care that the clipping window does not exceed the
|             destination area where the primitives will be drawn, otherwise
|             unexpected results may occur.
|
|  Params:    x - X ending coordinate of the clipping window
|
|             y - Y ending coordinate of the clipping window
|
|  Limit.:    The contents of this register will be used only if the clipping
|             window option will be selected in one of the Draw Line or Draw
|             Triangle commands.
|
|             The maximum allowed values for CYEND and CXEND are (MHEIGHT-1)
|             and (MWIDTH-1).
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_CLIPWNDEND(x,y) (GA_LOAD(GA_GPR2,                 \
                                  GA_FP((y), 16, GA_MASK12)  |     \
                                  GA_FP((x),  0, GA_MASK12)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Destination Address Register (DEDAR)
|
|  Descr  :   This register contains the lower 32 bits of the physical
|             address of the start location of the destination area, on which
|             primitives will be drawn. The address should point to the start
|             of the destination area (e.g. start of frame buffer), since the
|             offsets will be calculated inside the Drawing Engine according
|             to start and end coordinates of the primitives.
|
|  Params:    addr - Lower 32 bits (address lines [31:0]) of the physical
|                    address of the starting location of the destination
|                    memory area.
|
|  Limit.:    The address programmed, must be word aligned if an RGBA32 color
|             space is used,half-word aligned if an RGB16 color space is used.
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_DESTADDR(addr) (GA_LOAD(GA_GPR4,(addr)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Destination Memory Width and Height
|             Register (DEMWR)
|
|  Descr  :   This register contains the width, in pixels, of the memory area
|             used as frame buffer or where primitives will be stored.
|             The value contained in this register is used allow the Drawing
|             Engine to calculate the correct addresses for read or writes,
|             given the X,Y offsets of the current calculations.
|
|
|  Params:    width  - Width of display area, in pixels, any value between 16
|                      and 4095 are allowed.
|
|             height - Height of display area, in pixels, any value between
|                      16 and 4095 are allowed.
|
|
|  Limit.:    Image width can be specified only as an integer number of
|             pixels, no sub-pixel resolution is available in this register.
|
|             If a primitive will be programmed, which partially falls
|             outside the display area, a hard-clipping of this part will be
|             performed.
|
|             !!! Failing to program this register will lead to malfunction
|             of the Drawing Engine.!!!
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_DESTDIM(width, height) (GA_LOAD(GA_GPR5,                   \
                                         GA_FP((height), 16, GA_MASK12)  |  \
                                         GA_FP((width),   0, GA_MASK12)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Line Start Register (DELSR)
|
|  Descr  :   This register contains the START coordinates of the line to be
|             drawn. They are expressed as an integer coordinate followed by
|             a fractional part. The fractional part is not decimal, rather
|             expressed in 1/16 of a pixelas (see the Capricorn datasheet).
|
|
|  Params:    x - The X coordinate of the start position of the line
|
|             y - The Y coordinate of the start position of the line
|
|
|  Limit.:    The integer and sub-pixel position should not be disregarded
|             (for more details please see the Capricorn M datasheet)
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_LINESTART(x,y) (GA_LOAD(GA_GPR6,                 \
                                 GA_FP ((y), 16, GA_MASK16)   |   \
                                 GA_FP ((x),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Line End Register (DELER)
|
|  Descr  :   This register contains the END coordinates of the line to be
|             drawn. They are expressed as an integer coordinate followed by
|             a fractional part. The fractional part is not decimal, rather
|             expressed in 1/16 of a pixelas (see the Capricorn datasheet).
|
|
|  Params:    x - The X coordinate of the start position of the line
|
|             y - The Y coordinate of the start position of the line
|
|
|  Limit.:    The integer and sub-pixel position should not be disregarded
|             (for more details please see the Capricorn M datasheet)
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_LINEEND(x,y) (GA_LOAD(GA_GPR7,                 \
                               GA_FP((y), 16, GA_MASK16)   |    \
                               GA_FP((x),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Triangle Point 1 Register (DEPP1R)
|
|  Descr  :   This register holds the X and Y coordinates of point 1 of a
|             triangle. The coordinates are expressed by an integer part and
|             a fractional part. The fractional part allows positioning the
|             coordinates with 1/16 of pixel precision.
|
|
|  Params:    x - The X coordinate of point 1
|
|             y - The Y coordinate of point 1
|
|
|  Limit.:    The integer and sub-pixel position should not be disregarded
|             (for more details please see the Capricorn M datasheet)
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_TRNGLE1(x,y) (GA_LOAD(GA_GPR6,                  \
                               GA_FP ((y), 16, GA_MASK16)   |    \
                               GA_FP ((x),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Triangle Point 2 Register (DEPP2R)
|
|  Descr  :   This register holds the X and Y coordinates of point 2 of a
|             triangle. The coordinates are expressed by an integer part and
|             a fractional part. The fractional part allows positioning the
|             coordinates with 1/16 of pixel precision.
|
|
|  Params:    x - The X coordinate of point 2
|
|             y - The Y coordinate of point 2
|
|
|  Limit.:    The integer and sub-pixel position should not be disregarded
|             (for more details please see the Capricorn M datasheet)
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_TRNGLE2(x,y) (GA_LOAD(GA_GPR7,                 \
                               GA_FP((y), 16, GA_MASK16)   |    \
                               GA_FP((x),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Triangle Point 3 Register (DEPP3R)
|
|  Descr  :   This register holds the X and Y coordinates of point 3 of a
|             triangle. The coordinates are expressed by an integer part and
|             a fractional part. The fractional part allows positioning the
|             coordinates with 1/16 of pixel precision.
|
|
|  Params:    x - The X coordinate of point 3
|
|             y - The Y coordinate of point 3
|
|
|  Limit.:    The integer and sub-pixel position should not be disregarded
|             (for more details please see the Capricorn M datasheet)
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_TRNGLE3(x,y) (GA_LOAD(GA_GPR8,                  \
                               GA_FP ((y), 16, GA_MASK16)   |    \
                               GA_FP ((x),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine Line Thickness Register (DELTR)
|
|  Descr  :   This register contains the thickness of the line to be drawn.
|             The thickness is expressed by an integer value followed by a
|             four-bit fractional part that allows adjusting line thickness
|             with a precision of 1/16 of a pixel. Sub-pixel thicknesses are
|             possible by programming the integer value to zero.
|
|
|  Params:    val - line thickness value
|
|  Limit.:    Note that programming a value of zero in both intg and sub
|             fields is not possible if the register has to be used.
|
|             The apparent thickness depends on the filter coefficients
|             as well.
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_THICKNESS(val) (GA_LOAD(GA_GPR9,                \
                                 GA_FP((val), 0, GA_MASK9)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine RGBA32 Color Register (DERGBAR)
|
|  Descr  :   When using the RGBA32 color space, the color used to draw
|             primitives has to be programmed into this register.
|
|
|  Params:    color  - Color Component: color[31-24] - Red
|                                       color[23-16] - Green
|                                       color[15-8]  - Blue
|                                       color[7-0]   - Alpha
 -------------------------------------------------------------------------*/
#define DRW_LOAD_RGBA32(color) (GA_LOAD(GA_GPR10,                 \
                                GA_FP((color), 0, GA_MASK32)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine RGB16 Color Register (DERGBR)
|
|  Descr  :   When using the RGB16 color space, the color used to draw
|             primitives has to be programmed into this register.
|             This register provides also an AVAL field, to set the alpha
|             value of the primitive. The RGB16 mode does not support alpha,
|             but this value will be used to set the transparency value of a
|             primitive.
|
|
|  Params:    color  - Color Component RGB565: color[15-11] - Red
|                                              color[10-5]  - Green
|                                              color[4-0]   - Blue
|
|             alpha  - Alpha value for RGB16 format alpha[7-0].
|                      Although RGB16 doesn’t directly support alpha, this
|                      value will be used as transparency value if the
|                      transparency blending method is used.
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_RGB16(color,alpha) (GA_LOAD(GA_GPR10,                 \
                                     GA_FP ((alpha), 16, GA_MASK8)  |  \
                                     GA_FP ((color),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine RGBA32 Background Color Register (DEBKG32)
|
|  Descr  :   When performing operations in non-blending mode, the color of
|             the background has to be programmed into this register.
|             The Drawing Engine, in this case, will not read the contents
|             of memory but only overwrite its contents. The color
|             information is needed to perform antialiasing against a flat
|             background.
|
|
|  Params:    color  - Color Component: color[31-24] - Red
|                                       color[23-16] - Green
|                                       color[15-8]  - Blue
|                                       color[7-0]   - Alpha
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_RGBA32BGRND(color) (GA_LOAD(GA_GPR11,               \
                                     GA_FP ((color), 0, GA_MASK32)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Drawing Engine RGB16 Background Color Register (DEBKG16R)
|
|  Descr  :   When performing operations in non-blending mode, the color of
|             the background has to be programmed into this register.
|             The Drawing Engine, in this case, will not read the contents
|             of memory but only overwrite its contents. The color
|             information is needed to perform antialiasing against a flat
|             background.
|
|
|  Params:    color  - Color Component RGB565: color[15-11] - Red
|                                              color[10-5]  - Green
|                                              color[4-0]   - Blue
|
|             alpha  - Alphablending component value (8-bit)
|
 -------------------------------------------------------------------------*/
#define DRW_LOAD_RGB16BGRND(color) (GA_LOAD(GA_GPR11,              \
                                    GA_FP((color), 0, GA_MASK16)))


/**********************************************
*                Enums                        *
**********************************************/
#define LAST_FILTER_COEF_INDEX   63 /* 0..63 = 64x4=256 entries */
/* Start-/End- point line caps style */
typedef enum tag_drw_CapStyle_e
{
    DRW_BUTTEND    = 0x0u,          /* Butt-end not anti-aliased */
    DRW_BUTTEND_AA = 0x1u,          /* Butt-end anti-aliased */
    DRW_CIRCULAR   = 0x2u           /* Circular line caps */
} drw_CapStyle_e;

/* Blending Mode */
typedef enum tag_drw_blendMode_e
{
    DRW_BLEND_OPAQUE            = 0x0u,    /* Opaque Blending Mode */
    DRW_BLEND_TRANSP            = 0x1u,    /* Transparent Blending Mode */
    DRW_OVERWRITING             = 0x2u,    /* Overwriting Mode */
    DRW_BLEND_RGBA32_SATURATION = 0x3u     /* Saturation Mode - Valid only for RGBA32 mode */
} drw_blendMode_e;

/**********************************************
*              Structures                     *
**********************************************/
/* Memory Configuration */
typedef struct tag_drw_mem_st
{
    /* Destination Mem. Params */
    uint32_t u32DstAddr;            /* Dest. Memory Addr. First Src. Dot*/
    uint16_t u16DstImgWidth;        /* Dest. Image Width */
    uint16_t u16DstImgHeight;       /* Dest. Image Height */
} drw_mem_st;

/* Point Structure */
typedef struct tag_drw_Point_st
{
    uint16_t u16X;                 /* X- Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels */
    uint16_t u16Y;                 /* Y- Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels */
} drw_Point_st;

/* Clipping Window Coordinates */
typedef struct tag_drw_clipWnd_st
{
    uint16_t u16UlX;                /* Upper Left X-Coord */
    uint16_t u16UlY;                /* Upper Left Y-Coord */
    uint16_t u16LrX;                /* Lower Right X-Coord */
    uint16_t u16LrY;                /* Lower Right Y-Coord */
} drw_clipWnd_st;

/* Line (RGB16/RGBA32) Command desc. structure */
typedef struct tag_drw_LnOpCfg_st
{
    ga_colFmt_e     eColFmt;        /* Line Color fmt. (RGB16/RGBA32)*/
    drw_blendMode_e eBlndMode;      /* Blending Mode */
    drw_CapStyle_e  eStartCap;      /* Cap Style of start point */
    drw_CapStyle_e  eEndCap;        /* Cap Style of end point */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */
} drw_LnOpCfg_st;

/* Triangle (RGB16/RGBA32) Command desc. structure */
typedef struct tag_drw_TriOpCfg_st
{
    ga_colFmt_e     eColFmt;        /* Line Color fmt. (RGB16/RGBA32)*/
    drw_blendMode_e eBlndMode;      /* Blending Mode */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */
    ga_en_e         eAntialEn1;     /* Antial. Enable for Edge 1 */
    ga_en_e         eAntialEn2;     /* Antial. Enable for Edge 2 */
    ga_en_e         eAntialEn3;     /* Antial. Enable for Edge 3 */
} drw_TriOpCfg_st;

/* Line/Triangle Draw common config. options */
typedef struct tag_drw_OpCfg_st
{
    drw_blendMode_e eBlndMode;      /* Blending Mode */
    uint32_t        u32BgColor;     /* Background color (RGB16/RGBA32) */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */
    drw_clipWnd_st  stClipWnd;      /* Clipping Window Parameters */
} drw_OpCfg_st;

/* Color config. options */
typedef struct tag_drw_Color_st
{
    ga_colFmt_e  eColFmt;           /* Primitive Color fmt. (RGB16/RGBA32)*/
    uint32_t     u32Color;          /* Primitive color (RGB16/RGBA32) */
    uint8_t      u8Alpha;           /* Primitive alpha-blending (only if
                                       Transp. blending mode is used) */
} drw_Color_st;

/* Line description structure */
typedef struct tag_drw_Line_st
{
    drw_Point_st   stPtStart;       /* Line Start Point */
    drw_Point_st   stPtEnd;         /* Line End Point */

    drw_CapStyle_e eStartCap;       /* Cap Style of start point */
    drw_CapStyle_e eEndCap;         /* Cap Style of end point */

    drw_Color_st   stColor;         /* Color Configuration */
    uint16_t u16Thickness;          /* Line Thickness-Integer part 12 bits + 4 bits sub pixels */
} drw_Line_st;

/* Triangle desription structure */
typedef struct tag_drw_Trngl_st
{
    drw_Point_st stPt1;             /* Triangle Point 1 */
    drw_Point_st stPt2;             /* Triangle Point 2 */
    drw_Point_st stPt3;             /* Triangle Point 3 */

    ga_en_e      eAntialEn1;        /* Antial. Enable for Edge 1 */
    ga_en_e      eAntialEn2;        /* Antial. Enable for Edge 2 */
    ga_en_e      eAntialEn3;        /* Antial. Enable for Edge 3 */

    drw_Color_st stColor;           /* Color Configuration */
} drw_Trngl_st;

/**********************************************
*      Exported Function Prototypes           *
**********************************************/
/*-------------------------------------------------------------------------
|
|                      B A S I C      O P E R A T I O N S
|
 --------------------------------------------------------------------------*/
/****************************************************************************
 *
 * Function:      vDrw_GetVersion
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
void vDrw_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);

/****************************************************************************
 *
 * Function:      vDrw_SetMemDest
 *
 * Purpose:       Sets the destination memory parameters in the Command List
 *
 * Inputs:        pvAddr     - Destination Memory Address
 *                             (First Dot of the destination)
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
void vDrw_SetMemDest(const void* pvAddr, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetMemDim
 *
 * Purpose:       Sets the destination memory size in the Command List
 *
 * Inputs:        u16Width   - Destination Memory Width
 *                             Number of lines of the destination image
 *                             (from 1 up to 4095).
 *
 *                u16Height  - Destination Memory Height
 *                             Memory reserved per line within the destination
 *                             in dots (from 1 up to 4095).
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
void vDrw_SetMemDim(uint16_t u16Width, uint16_t u16Height, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetColorRGB16
 *
 * Purpose:       Sets the color that will be used for drawing the primitives
 *                when using RGB16 color space.
 *
 * Inputs:        u16Color   - Color 16-bit RGB Value
 *
 *                u8Alpha    - Alpha blending (8-bit)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Please note that although RGB16 does not have alpha
 *                blending, the value specified as ucAlpha will be used as
 *                such, but only if transparency blending method is used.
 *
 ***************************************************************************/
void vDrw_SetColorRGB16(uint16_t u16Color, uint8_t u8Alpha, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetColorRGBA32
 *
 * Purpose:       Sets the color that will be used for drawing the primitives
 *                when using RGBA32 color space.
 *
 * Inputs:        u32Color   - 32-bit RGBA Color Value
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
void vDrw_SetColorRGBA32(uint32_t u32Color, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetBgColorRGBA32
 *
 * Purpose:       Sets the background color that will be used for drawing
 *                the primitives in non-blending mode and when RGBA32 color
 *                space is used. The Drawing Engine, in this case, will not
 *                read the contents of memory but only overwr. its contents.
 *
 * Inputs:        u32Color   - 32-bit RGBA Color Value
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
void vDrw_SetBgColorRGBA32(uint32_t u32Color, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetBgColorRGB16
 *
 * Purpose:       Sets the background color that will be used for drawing
 *                the primitives in non-blending mode and when RGB16 color
 *                space is used. The Drawing Engine, in this case, will not
 *                read the contents of memory but only overwr. its contents.
 *
 * Inputs:        u16Color   - 16-bit RGB Color Value
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
void vDrw_SetBgColorRGB16(uint16_t u16Color, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetLineStart
 *
 * Purpose:       Sets the coordinates of a point where the line should start.
 *                Note: The pixel coordinates: Bits: 15..4  integer part
 *                                             Bits:  3..0  sub pixel (in 1/16 steps)
 *
 * Inputs:        u16X        - X- Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels 
 *
 *                u16Y        - Y Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   API will not check the range of values (because of performance).
 *
 ***************************************************************************/
void vDrw_SetLineStart(uint16_t u16X,  uint16_t u16Y, ga_list_st* pstCmdList);
/****************************************************************************
 *
 * Function:      vDrw_SetLineEnd
 *
 * Purpose:       Sets the coordinates of a point where the line should end
 *
 * Inputs:        u16X        - X- Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels 
 *
 *                u16Y        - Y Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   API will not check the range of values (because of performance).
 *
 ***************************************************************************/
void vDrw_SetLineEnd(uint16_t u16X,  uint16_t u16Y, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetLineThickness
 *
 * Purpose:       Sets the line thickness
 *                Note: The line Thickness: Bits: 15..4  integer part
 *                                          Bits:  3..0  sub pixel (in 1/16 steps)
 *
 * Inputs:        u16Val        Line thickness value-Integer part 12 bits + 4 bits sub pixels 
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   API will not check the range of values (because of performance).
 *
 ***************************************************************************/
void vDrw_SetLineThickness(uint16_t u16Val, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetTriangle1
 *
 * Purpose:       Sets the point 1 of the triangle
 *                Note: The pixel coordinates: Bits: 15..4  integer part
 *                                             Bits:  3..0  sub pixel (in 1/16 steps)
 *
 * Inputs:        u16X        - X- Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels 
 *
 *                u16Y        - Y Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   API will not check the range of values (because of performance).
 * 
 ***************************************************************************/
void vDrw_SetTriangle1(uint16_t u16X,  uint16_t u16Y, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetTriangle2
 *
 * Purpose:       Sets the point 2 of the triangle
 *                Note: The pixel coordinates: Bits: 15..4  integer part
 *                                             Bits:  3..0  sub pixel (in 1/16 steps)
 *
 * Inputs:        u16X        - X- Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels 
 *
 *                u16Y        - Y Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   API will not check the range of values (because of performance).
 *
 ***************************************************************************/
void vDrw_SetTriangle2(uint16_t u16X,  uint16_t u16Y, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetTriangle3
 *
 * Purpose:       Sets the point 1 of the triangle
 *                Note: The pixel coordinates: Bits: 15..4  integer part
 *                                             Bits:  3..0  sub pixel (in 1/16 steps)
  *
 * Inputs:        u16X        - X- Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels 
 *
 *                u16Y        - Y Coordinate of the Point-Integer part 12 bits + 4 bits sub pixels
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   API will not check the range of values (because of performance).
 *
 ***************************************************************************/
void vDrw_SetTriangle3(uint16_t u16X,  uint16_t u16Y, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetClippWnd
 *
 * Purpose:       Sets the Clipping Window Coordinates
 *
 * Inputs:        pstClipWnd - Pointer to Clipping Window Coordinates
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
void vDrw_SetClippWnd(drw_clipWnd_st* pstClipWnd, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetLineCmd
 *
 * Purpose:       Inserts the appropriate Line (RGBA32/RGB16) command. The
 *                type of the command is determined by the given color space
 *
 * Inputs:        pstParam   - Pointer to Line Command option parameters
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Blend mode DRW_BLEND_RGBA32_SATURATION in pstParam will be
 *                vaild only for RGBA32 mode. Because of performance reason API
 *                will not check it.
 *
 ***************************************************************************/
void vDrw_SetLineCmd(drw_LnOpCfg_st* pstParam, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_SetTriangleCmd
 *
 * Purpose:       Inserts the appropriate Triangle (RGBA32/RGB16) command.
 *                The exact type of the command is determined by the given
 *                color space.
 *
 * Inputs:        pstParam   - Pointer to Triangle Command option parameters
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Blend mode DRW_BLEND_RGBA32_SATURATION in pstParam will be
 *                vaild only for RGBA32 mode. Because of performance reason API
 *                will not check it.
 *
 ***************************************************************************/
void vDrw_SetTriangleCmd(drw_TriOpCfg_st* pstParam, ga_list_st* pstCmdList);

/*-------------------------------------------------------------------------
|
|                    D R A W I N G      O P E R A T I O N S
|
 --------------------------------------------------------------------------*/
/****************************************************************************
 *
 * Function:      vDrw_DrawLine
 *
 * Purpose:       Inserts all neccessarry commands for drawing the line
 *                Note: The pixel coordinates: Bits: 15..4  integer part
 *                                             Bits:  3..0  sub pixel (in 1/16 steps)
 *
 * Inputs:        pstMem     - Pointer to Destination Memory description parameters
 *
 *                pstOption  - Pointer to Configuration options required for line draw
 *                             operation
 *
 *                pstLine    - Pointer to Specifying line that should be drawn
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Blend mode DRW_BLEND_RGBA32_SATURATION in pstParam will be
 *                vaild only for RGBA32 mode. Because of performance reason API
 *                will not check it.
 *
 ***************************************************************************/
void vDrw_DrawLine(drw_mem_st* pstMem, drw_OpCfg_st *pstOption,
                   drw_Line_st *pstLine, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vDrw_DrawTriangle
 *
 * Purpose:       Inserts all neccessarry commands for drawing the triangle
 *                Note: The pixel coordinates: Bits: 15..4  integer part
 *                                             Bits:  3..0  sub pixel (in 1/16 steps)
 *
 * Inputs:        stMem      - Destination Memory description parameters
 *
 *                stOption   - Configuration options required for line draw
 *                             operation
 *
 *                stTrngl    - Specifies the triangle that should be drawn
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Blend mode DRW_BLEND_RGBA32_SATURATION in pstParam will be
 *                vaild only for RGBA32 mode. Because of performance reason API
 *                will not check it.
 *
 ***************************************************************************/
void vDrw_DrawTriangle(drw_mem_st* pstMem, drw_OpCfg_st *pstOption,
                       drw_Trngl_st *pstTrngl, ga_list_st* pstCmdList);
                       

/****************************************************************************
 *
 * Function:      boDrw_SetFilterCoefDrawEngine
 *
 * Purpose:       Sets 32-Bit Filter Coeffcients for 4 entries(4 x 8 Bits).
 *
 * Inputs:        u8CoefIndex  - Index of location for Coefficents 
 *                              (0 .. LAST_FILTER_COEF_INDEX)
 *
 *                u32CoefValue - 32 Bit values for 4 entries (4 x 8 Bits).
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE: Ok
 *                C_FALSE: wrong parameter 
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boDrw_SetFilterCoefDrawEngine (uint8_t u8CoefIndex,  
                                      uint32_t u32CoefValue);
                       

/****************************************************************************/
/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/


#endif /* DRAW_H */

/****************************************************************************/


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: draw.h
**  $Revision: 1.15 $
**  $Date: 2015/05/04 09:07:14 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 
** | CONS.  : 
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

