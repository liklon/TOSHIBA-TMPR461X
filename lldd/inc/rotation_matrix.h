/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Graphic Accelerator
*                 Reference Low-Level Driver Matrix Form (Rotation Engine)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphic Accelerator Rotation Engine
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.15 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef ROTATION_MATRIX_H
#define ROTATION_MATRIX_H

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

#define LLDD_GA_ROTATE_MATRIX_H_REVISION     "$Revision: 1.15 $"
#define LLDD_GA_ROTATE_MATRIX_H_TAG          "$Name: LLDD_1_7_GFX $"

/*--------------------------------------------------------------------------
|       ------------------------------------------------------------        |
|      | >>>>>>         ROTATION ENGINE COMMAND INDEX        <<<<<< |       |
|       ------------------------------------------------------------        |
|---------------------------------------------------------------------------|
|---------------------------------------------------------------------------|
|                                                                           |
|                      ------------------------------                       |
|                     |      OPERATION COMMANDS      |                      |
|                      ------------------------------                       |
|                                                                           |
| - Commands:                                                               |
|   1. ROT_ROTATE           - Rotation Command                              |
|   2. ROT_ROTATEB          - Rotation Command with blending                |
|                                                                           |
|---------------------------------------------------------------------------|
|                                                                           |
|                    ----------------------------------                     |
|                   |      LOAD REGISTER COMMANDS      |                    |
|                    ----------------------------------                     |
|                                                                           |
| - Source Regs:                                                            |
|   1. ROT_LOAD_SOURCEADDR  -  Load Source Address Reg.               (SAR) |
|   2. ROT_LOAD_SRCWIDTH    -  Load Source Memory Width Reg.         (SMWR) |
|                                                                           |
| - Destination Regs:                                                       |
|   3. ROT_LOAD_DESTADDR    -  Load Destination Address Reg.          (DAR) |
|   4. ROT_LOAD_DESTMEMDIM  -  Load Destination Memory Dim. Reg.     (DMDR) |
|                                                                           |
| - Color Regs:                                                             |
|   5. ROT_LOAD_COLORFMT    -  Load Color Format Register             (CFR) |
|                                                                           |
| - Alpha Regs:                                                             |
|   6. ROT_LOAD_SRCALPHAVAL - Load Source Alpha Value Register       (SAVR) |
|   7. ROT_LOAD_DSTALPHAVAL - Load Destination Alpha Value Register  (DAVR) |
|                                                                           |
| - Rotation Regs:                                                          |
|   8. ROT_LOAD_A11         - Load SXR Register                      (SXR)  |
|   9. ROT_LOAD_A12         - Load SHXR Register                     (SHXR) |
|  10. ROT_LOAD_A21         - Load SHYR Register                     (SHYR) |
|  11. ROT_LOAD_A22         - Load SYR Register                      (SYR)  |
|  12. ROT_LOAD_A31         - Load W0R Register                      (W0R)  |
|  13. ROT_LOAD_A32         - Load W1R Register                      (W1R)  |
|  14. ROT_LOAD_A33         - Load W2R Register                      (W2R)  |
|                                                                           |
| - Forward-Rotation Regs:                                                  |
|  15. ROT_LOAD_SRCADDRPOS  - Load Rotated Src. Address Pos. Reg.     (RSA) |
|  16. ROT_LOAD_COORD1      - Load Frwd-Rot. Corner Coord. Reg. 1  (FRCCR1) |
|  17. ROT_LOAD_COORD2      - Load Frwd-Rot. Corner Coord. Reg. 2  (FRCCR2) |
|  18. ROT_LOAD_COORD3      - Load Frwd-Rot. Corner Coord. Reg. 3  (FRCCR3) |
|  19. ROT_LOAD_COORD4      - Load Frwd-Rot. Corner Coord. Reg. 4  (FRCCR4) |
|                                                                           |
| - Clipping Window:                                                        |
|  20. ROT_LOAD_CLIPWNDUL   - Load Clipp.Wnd. Upper-Left Corner      (CWUL) |
|  21. ROT_LOAD_CLIPWNDLR   - Load Clipp.Wnd. Upper-Left Corner      (CWLR) |
|                                                                           |
 --------------------------------------------------------------------------*/
/*=========================================================================
|                            OPERATION COMMANDS                             |
 ==========================================================================*/
/*--------------------------------------------------------------------------
|
|  Command:   ROT_ROTATE
|
|  Descr  :   Rotate source to destination without blending.
|
|  Params:    clippEn  - Clipping Control
|                        Use: GA_EN  - Enable Clipping
|                             GA_DIS - Disable Clipping
|
|             filterEn - Filter Control
|                        Use: GA_EN  - Enable Filter
|                             GA_DIS - Disable Filter
|
|
 -------------------------------------------------------------------------*/
#define ROT_ROTATE(clippEn, filterEn) (GA_CMN(GA_ROTATION, 1, GA_CMC_ROT,   \
                                       GA_FP ((clippEn),   1, GA_MASK1)   | \
                                       GA_FP ((filterEn),  0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   ROT_ROTATEB
|
|  Descr  :   Rotate source to destination with blending.
|
|  Params:    redChProt   - Red Channel Protection
|                           Use: GA_EN           - Channel Protected
|                                GA_DIS          - Channel Not Protected
|                         
|             greenChProt - Green Channel Protection
|                           Use: GA_EN           - Channel Protected
|                                GA_DIS          - Channel Not Protected
|                         
|             blueChProt  - Blue Channel Protection
|                           Use: GA_EN           - Channel Protected
|                                GA_DIS          - Channel Not Protected
|                         
|             alphaProt   - Alpha Channel Protection
|                           Use: GA_EN           - Channel Protected
|                                GA_DIS          - Channel Not Protected
|
|             redChFad    - Red Channel Fading
|                           Use: GA_EN           - Channel Protected
|                                GA_DIS          - Channel Not Protected
|                         
|             greenChFad  - Green Channel Fading
|                           Use: GA_EN           - Channel Protected
|                                GA_DIS          - Channel Not Protected
|                         
|             blueChFad   - Blue Channel Fading
|                           Use: GA_EN           - Channel Protected
|                                GA_DIS          - Channel Not Protected
|                         
|             alphaFad    - Alpha Channel Fading
|                           Use: GA_EN           - Channel Protected
|                                GA_DIS          - Channel Not Protected
|
|             blndOrder   - Blending Order
|                           Use: BLT_ONTO_DEST   - Onto destination
|                                BLT_BEHIND_DEST - Behind the destination
|                         
|             ClipWndEn   - Clipping Window Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             FilterContr - Filter Control Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|
|
 -------------------------------------------------------------------------*/
#define ROT_ROTATEB(redChProt,                                            \
                    greenChProt,                                          \
                    blueChProt,                                           \
                    alphaProt,                                            \
                    redChFad,                                             \
                    greenChFad,                                           \
                    blueChFad,                                            \
                    alphaFad,                                             \
                    blndOrder,                                            \
                    ClipWndEn,                                            \
                    FilterContr)                                          \
                    (GA_CMN(GA_ROTATION,   1, GA_CMC_ROTB,                \
                     GA_FP ((redChProt),  15, GA_MASK1)        |          \
                     GA_FP ((greenChProt),14, GA_MASK1)        |          \
                     GA_FP ((blueChProt), 13, GA_MASK1)        |          \
                     GA_FP ((alphaProt),  12, GA_MASK1)        |          \
                     GA_FP ((redChFad),   11, GA_MASK1)        |          \
                     GA_FP ((greenChFad), 10, GA_MASK1)        |          \
                     GA_FP ((blueChFad),   9, GA_MASK1)        |          \
                     GA_FP ((alphaFad),    8, GA_MASK1)        |          \
                     GA_FP ((blndOrder),   3, GA_MASK1)        |          \
                     GA_FP ((ClipWndEn),   1, GA_MASK1)        |          \
                     GA_FP ((FilterContr), 0, GA_MASK1)))

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
|             is the pointer to the first dot in memory of the source image.
|
|  Params:    addr - Source Address
|                    The lower 32 physical address bits that point to the
|                    first dot of the source.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_SOURCEADDR(addr) (GA_LOAD(GA_GPR9, (addr)))

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
#define ROT_LOAD_SRCWIDTH(width) (GA_LOAD(GA_GPR10, (width)))

/*------------------------------
|     DESTINATION REGISTERS     |
 -------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Address Register (DAR)
|
|  Descr  :   The physical 32-bit address within the destination address
|             register is the pointer to the first dot in the memory region,
|             where the rotated bitmap will be placed. Depending on the
|             source color format, which is equal to the destination color
|             format, this address has to be word- (RGBA32) or halfword-
|             (RGB16) aligned.
|
|  Params:    addr   - Destination Address
|                      The lower 32 physical address bits that point to the
|                      first dot of the destination.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_DESTADDR(addr) (GA_LOAD(GA_GPR4, (addr)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Memory Dimension Register (DMDR)
|
|  Descr  :   The destination memory dimension register specifies the memory
|             reserved for one line within the destination image in number
|             of dots. Note that this value does not necessarily have to be
|             equal to the image width.
|
|  Params:    width  - Destination Memory Width
|                      Memory reserved per line within the source in dots
|                      (1 up to 4095)
|
|             height - Destination Memory Height
|                      Number of lines of the destination image
|                      (from 1 up to 4095).
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_DESTMEMDIM(width, height) (GA_LOAD(GA_GPR5,                    \
                                            GA_FP ((height), 16, GA_MASK12)  |  \
                                            GA_FP ((width),   0, GA_MASK12)))

/*------------------------------
|        COLOR REGISTERS        |
 -------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Color Format Register (CFR)
|
|  Descr  :   This register specifies the color format of both, source
|             and destination. As the rotation engine does not perform color
|             conversion.
|
|  Params:    dstformat - Destination color format
|                         Use parameters:
|                         GA_RGB16  - 16-bit RGB
|                         GA_RGBA32 - 32-bit RGBA
|
|             srcformat - Source color format
|                         Use parameters:
|                         GA_RGB16  - 16-bit RGB
|                         GA_RGBA32 - 32-bit RGBA
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_COLORFMT(dstformat, srcformat) (GA_LOAD(GA_GPR11,                    \
                                                 GA_FP ((dstformat), 1, GA_MASK1)  |  \
                                                 GA_FP ((srcformat), 0, GA_MASK1)))

/*------------------------------
|        ALPHA REGISTERS        |
 -------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Source Fading Factor Register (SFFR)
|
|  Descr  :   The Source Fading Factor Register holds the fading factor enumerator
|             (SFFE) of the fading factor.
|
|  Params:    factor - Source Fading Factor Enumerator
|                      These bits specify the enumerator of the fading
|                      factor FFACT.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_FADEFACT(factor) (GA_LOAD(GA_GPR26,                       \
                                   ((factor) & GA_MASK8)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Source Alpha Value Register (SAVR)
|
|  Descr  :   The Source Alpha Value Register keeps the alpha value for
|             conversion of the source dots from the 16-bit RGB format to
|             the 32-bit RGBA format for internal processing.
|
|  Params:    format - Source alpha value
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_SRCALPHAVAL(value) (GA_LOAD(GA_GPR27,                     \
                                     ((value) & GA_MASK8)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Alpha Value Register (DAVR)
|
|  Descr  :   The Destination Alpha Value Register keeps the alpha value
|             used during conversion of the destination dots from the
|             16-bit RGB format to the 32-bit RGBA format.
|
|  Params:    format - Source alpha value
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_DSTALPHAVAL(value) (GA_LOAD(GA_GPR28,                     \
                                     ((value) & GA_MASK8)))

/*------------------------------
|      ROTATION REGISTERS        |
 -------------------------------*/
               /* Rotation Matrix:
* 
*              [  sx   shx  0 ]
*              [  shy  sy   0 ]
*              [  w0   w1   w2]
*/
/*--------------------------------------------------------------------------
|
|  Command:   Load SXR Register
|
|  Descr  :   This register holds the SX value of the rotation matrix 
              multiplied by 65536. The signed two’s complement integer 
              value is in the range of -2097152 to +2097151.
|
|  Params:    val - The shifted and integer converted SX value of the
|                   rotation matrix.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_A11(val) (GA_LOAD(GA_GPR12,                               \
                           ((val) & GA_MASK22)))

/*--------------------------------------------------------------------------
|
|  Command:   Load SHXR Register
|
|  Descr  :   This register holds the SHX value of the rotation matrix 
|             multiplied by 65536. The signed two’s complement integer 
|             value is in the range of -2097152 to +2097151.
|
|  Params:    val - The shifted and integer converted SHX value of the
|                   rotation matrix.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_A12(val) (GA_LOAD(GA_GPR15,                               \
                           ((val) & GA_MASK22)))

/*--------------------------------------------------------------------------
|
|  Command:   Load SHYR Register
|
|  Descr  :   This register holds the SHY value of the rotation matrix 
|             multiplied by 65536. The signed two’s complement integer 
|             value is in the range of -2097152 to +2097151.
|
|  Params:    val - The shifted and integer converted SHY value of the
|                   rotation matrix.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_A21(val) (GA_LOAD(GA_GPR13,                               \
                           ((val) & GA_MASK22)))

/*--------------------------------------------------------------------------
|
|  Command:   Load SYR Register
|
|  Descr  :   This register holds the SHY value of the rotation matrix 
|             multiplied by 65536. The signed two’s complement integer 
|             value is in the range of -2097152 to +2097151.
|
|  Params:    val - The shifted and integer converted SYR value of the
|                   rotation matrix.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_A22(val) (GA_LOAD(GA_GPR14,                               \
                           ((val) & GA_MASK22)))

/*--------------------------------------------------------------------------
|
|  Command:   Load W0R Register
|
|  Descr  :   This register holds the W0 value of the rotation matrix 
|             multiplied by 65536. The signed two’s complement integer 
|             value is in the range of -2097152 to +2097151.
|
|  Params:    val - The shifted and integer converted W0 value of the
|                   rotation matrix.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_A31(val) (GA_LOAD(GA_GPR21,                               \
                           ((val) & GA_MASK22)))

/*--------------------------------------------------------------------------
|
|  Command:   Load W1R Register
|
|  Descr  :   This register holds the W0 value of the rotation matrix 
|             multiplied by 65536. The signed two’s complement integer 
|             value is in the range of -2097152 to +2097151.
|
|  Params:    val - The shifted and integer converted W1 value of the
|                   rotation matrix.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_A32(val) (GA_LOAD(GA_GPR22,                               \
                           ((val) & GA_MASK22)))

/*--------------------------------------------------------------------------
|
|  Command:   Load W2R Register
|
|  Descr  :   This register holds the W2 value of the rotation matrix 
|             multiplied by 65536. The signed two’s complement integer 
|             value is in the range of -2097152 to +2097151.
|
|  Params:    val - The shifted and integer converted W2 value of the
|                   rotation matrix.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_A33(val) (GA_LOAD(GA_GPR23,                               \
                           ((val) & GA_MASK22)))

/*------------------------------
|    FRWD-ROTATION REGISTERS    |
 ------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Rotated Source Address Position (RSA)
|
|  Descr  :   This value specifies the index of the rotated corner that at
|             it’s original position maps to the source image start address.
|
|
|  Params:    position - Rotated Source Address Position
|                        Use following values:
|                        GA_FRCCR1 - FRCCR1 maps to the source start addr.
|                        GA_FRCCR2 - FRCCR2 maps to the source start addr.
|                        GA_FRCCR3 - FRCCR3 maps to the source start addr.
|                        GA_FRCCR4 - FRCCR4 maps to the source start addr.
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_SRCADDRPOS(position) (GA_LOAD(GA_GPR20,                   \
                                       ((position) & GA_MASK2)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Forward-Rotated Corner Coordinates Register 1 (FRCCR1)
|
|  Descr  :   For detailed description how to select the please consult the
|             Capricorn documantation.
|
|             Please note that in order To provide a higher accuracy for
|             the Rotation Engine’s calculations, the forward-rotated
|             coordinate’s floating point values must be multiplied by 16
|             (shifted 4 bits to the left) before being converted to integer
|             and passed to the Rotation Engine.
|
|  Params:    x - Forward-rotated x-coordinate of corner 1 times 16.
|             y - Forward-rotated y-coordinate of corner 1 times 16
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_COORD1(x,y) (GA_LOAD(GA_GPR16,                      \
                              GA_FP ((x), 16, GA_MASK16)      |      \
                              GA_FP ((y),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Forward-Rotated Corner Coordinates Register 2 (FRCCR2)
|
|  Descr  :   For detailed description how to select the please consult the
|             Capricorn documantation.
|
|             Please note that in order To provide a higher accuracy for
|             the Rotation Engine’s calculations, the forward-rotated
|             coordinate’s floating point values must be multiplied by 16
|             (shifted 4 bits to the left) before being converted to integer
|             and passed to the Rotation Engine.
|
|  Params:    x - Forward-rotated x-coordinate of corner 2 times 16.
|             y - Forward-rotated y-coordinate of corner 2 times 16
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_COORD2(x,y) (GA_LOAD(GA_GPR17,                    \
                              GA_FP ((x), 16, GA_MASK16)     |     \
                              GA_FP ((y),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Forward-Rotated Corner Coordinates Register 3 (FRCCR3)
|
|  Descr  :   For detailed description how to select the please consult the
|             Capricorn documantation.
|
|             Please note that in order To provide a higher accuracy for
|             the Rotation Engine’s calculations, the forward-rotated
|             coordinate’s floating point values must be multiplied by 16
|             (shifted 4 bits to the left) before being converted to integer
|             and passed to the Rotation Engine.
|
|  Params:    x - Forward-rotated x-coordinate of corner 3 times 16.
|             y - Forward-rotated y-coordinate of corner 3 times 16
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_COORD3(x,y) (GA_LOAD(GA_GPR18,                       \
                              GA_FP ((x), 16, GA_MASK16)      |       \
                              GA_FP ((y),  0, GA_MASK16)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Forward-Rotated Corner Coordinates Register 4 (FRCCR4)
|
|  Descr  :   For detailed description how to select the please consult the
|             Capricorn documantation.
|
|             Please note that in order To provide a higher accuracy for
|             the Rotation Engine’s calculations, the forward-rotated
|             coordinate’s floating point values must be multiplied by 16
|             (shifted 4 bits to the left) before being converted to integer
|             and passed to the Rotation Engine.
|
|  Params:    x - Forward-rotated x-coordinate of corner 4 times 16.
|             y - Forward-rotated y-coordinate of corner 4 times 16
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_COORD4(x,y) (GA_LOAD(GA_GPR19,                       \
                              GA_FP ((x), 16, GA_MASK16)      |       \
                              GA_FP ((y),  0, GA_MASK16)))

/*------------------------------
|    CLIPPING-WND REGISTERS     |
 ------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Clipping Window Upper Left Corner Coord. Reg. (CWUL)
|
|  Descr  :   This register defines the upper left corner coordinate of the
|             clipping window relative to the destination start address in
|             number of pixels.
|
|  Params:    x - Clipping window upper left corner x-coordinate
|             y - Clipping window upper left corner y-coordinate
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_CLIPWNDUL(x,y) (GA_LOAD(GA_GPR1,                       \
                                 GA_FP ((x), 16, GA_MASK12)      |      \
                                 GA_FP ((y),  0, GA_MASK12)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Clipping Window Lower Right Corner Coord. Reg. (CWLR)
|
|  Descr  :   This register defines the upper left corner coordinate of the
|             clipping window relative to the destination start address in
|             number of pixels.
|
|  Params:    x - Clipping window lower right corner x-coordinate
|             y - Clipping window lower right corner y-coordinate
|
 -------------------------------------------------------------------------*/
#define ROT_LOAD_CLIPWNDLR(x,y) (GA_LOAD(GA_GPR2,                       \
                                 GA_FP ((x), 16, GA_MASK12)      |      \
                                 GA_FP ((y),  0, GA_MASK12)))

/*======================================
                Enums
=======================================*/
/* Rot.Src. Address Position  */
typedef enum tag_rot_SrcSel_e
{
    GA_FRCCR1 = 0x0u,
    GA_FRCCR2 = 0x1u,
    GA_FRCCR3 = 0x2u,
    GA_FRCCR4 = 0x3u
} rot_SrcSel_e;

/*======================================
              Structures
=======================================*/
/* rotation matrix Parameters (all values are mult. by 16) */
typedef struct tag_rot_Mtrx_st
{
    uint32_t  u32A11;                /* The shifted and integer conv. sx  */
    uint32_t  u32A12;                /* The shifted and integer conv. shx */
    uint32_t  u32A21;                /* The shifted and integer conv. shy */
    uint32_t  u32A22;                /* The shifted and integer conv. sy  */
    uint32_t  u32A31;                /* The shifted and integer conv. w0  */
    uint32_t  u32A32;                /* The shifted and integer conv. w1  */
    uint32_t  u32A33;                /* The shifted and integer conv. w2  */
} rot_Mtrx_st;

/* Forward-Rotated Corner Coordinates (all values are mult. by 16) */
typedef struct tag_rot_frccr_st
{
    uint16_t  u16X1;                 /* Frwd. Rotd. X-Coord (corner 1) */
    uint16_t  u16Y1;                 /* Frwd. Rotd. Y-Coord (corner 1) */
    uint16_t  u16X2;                 /* Frwd. Rotd. X-Coord (corner 2) */
    uint16_t  u16Y2;                 /* Frwd. Rotd. Y-Coord (corner 2) */
    uint16_t  u16X3;                 /* Frwd. Rotd. X-Coord (corner 3) */
    uint16_t  u16Y3;                 /* Frwd. Rotd. Y-Coord (corner 3) */
    uint16_t  u16X4;                 /* Frwd. Rotd. X-Coord (corner 4) */
    uint16_t  u16Y4;                 /* Frwd. Rotd. Y-Coord (corner 4) */

    uint8_t  u8ScrAddrPos;           /* Source address position */
} rot_frccr_st;

/* Memory Configuration */
typedef struct tag_rot_mem_st
{
    /* Source Mem. Params */
    uint16_t      u16SrcHeight;      /* Source Memory Height (Line Number) */
    uint16_t      u16SrcWidth;       /* Source Memory Width (Dots Per Line) */
    uint32_t      u32SrcAddr;        /* Source Memory Addr. First Src. Dot
                                       (Each function specifies its own
                                        memory alignment rules) */

    /* Destination Mem. Params */
    uint32_t      u32DstAddr;        /* Dest. Memory Addr. First Src. Dot
                                       (Each function specifies its own
                                        memory alignment rules) */
    /* Dest. Image Area Size */
    uint16_t      u16DstImgWidth;    /* Destination Image Width */
    uint16_t      u16DstImgHeight;   /* Destination Image Height */
} rot_mem_st;

/* Clipping Window Corner Coordinates */
typedef struct tag_rot_clipWnd_st
{
    uint16_t  u16UlX;                /* Upper Left X-Coord */
    uint16_t  u16UlY;                /* Upper Left Y-Coord */
    uint16_t  u16LrX;                /* Lower Right X-Coord */
    uint16_t  u16LrY;                /* Lower Right Y-Coord */
} rot_clipWnd_st;


/* Rotation Config. */
typedef struct tag_rot_rotCfg_st
{
    ga_colFmt_e    eSrcColFmt;       /* Source Color Format Selection */
    ga_colFmt_e    eDstColFmt;       /* Destination Color Format Selection */
    ga_en_e        eClipWndEn;       /* Clipping Window Enable */
    ga_en_e        eFilterEn;        /* Enable Filtering */
    uint8_t        u8FadingFctr;     /* Fading factor */
    uint8_t        u8SrcAlphaVal;    /* Source Alpha value */
    uint8_t        u8DstAlphaVal;    /* Destination Alpha value */

    /* Optional */
    rot_clipWnd_st tClipWnd;
} rot_rotCfg_st;

/* Rotation with blending Config.  */
typedef struct tag_rot_rotblendCfg_st
{
    ga_colFmt_e   eSrcColFmt;        /* Source Color Format Selection */
    ga_colFmt_e   eDstColFmt;        /* Destination Color Format Selection */
    ga_en_e       eClipWndEn;        /* Clipping Window Enable */
    ga_en_e       eFilterEn;         /* Enable Filtering */
    ga_en_e       eDstRedProt;       /* Destination red color protection */
    ga_en_e       eDstGreenProt;     /* Destination green color protection */
    ga_en_e       eDstBlueProt;      /* Destination blue color protection */
    ga_en_e       eDstAlphaProt;     /* Destination alpha protection */
    ga_en_e       eSrcRedFad;        /* Destination red color protection */
    ga_en_e       eSrcGreenFad;      /* Destination green color protection */
    ga_en_e       eSrcBlueFad;       /* Destination blue color protection */
    ga_en_e       eSrcAlphaFad;      /* Destination alpha protection */
    uint8_t       u8FadingFctr;      /* Fading factor */
    ga_blendOrd_e eBldOrd;           /* Blend order */
    uint8_t       u8SrcAlphaVal;     /* Source Alpha value */
    uint8_t       u8DstAlphaVal;     /* Destination Alpha value */

    /* Optional */
    rot_clipWnd_st tClipWnd;
} rot_rotblendCfg_st;


/*======================================
          Function definitions
=======================================*/
/****************************************************************************
 *
 * Function:      vRot_GetVersion
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
void vRot_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                            uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);

/****************************************************************************
 *
 * Function:      vRot_SetMemSrc
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
void vRot_SetMemSrc(uint32_t u32Addr, uint32_t u32Width, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_SetMemDest
 *
 * Purpose:       Sets the destination memory parameters in the Command List
 *
 * Inputs:        u32Addr    - Destination Memory Address
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
void vRot_SetMemDest(uint32_t u32Addr, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_SetMemDim
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
void vRot_SetMemDim(uint16_t u16Width, uint16_t u16Height, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_SetColorFmt
 *
 * Purpose:       Sets the color format of the both source and destination.
 *
 * Inputs:        eDstColFormat - Destination Color Format Selection
 *                                (16-bit RGB/ 32-bit RGBA)
 *
 *                eSrcColFormat - SourceColor Format Selection
 *                                (16-bit RGB/ 32-bit RGBA)
 *
 *                pstCmdList    - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Please note that Rotation Engine cannot convert color
 *                format, therefore formats for both (src. and dst.) must be
 *                the same.
 *
 ***************************************************************************/
void vRot_SetColorFmt(ga_colFmt_e eDstColFormat, ga_colFmt_e eSrcColFormat, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_SetRotMtrx
 *
 * Purpose:       Sets the rotation matrix coefficients.
 *
 * Inputs:        pstMatrix   - Pointer to rotation matrix Coefficients
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Please note that the signed two’s complement integer values
 *                are in the range of -2097152 to +2097151.
 *
 ***************************************************************************/
void vRot_SetRotMtrx(rot_Mtrx_st* pstMatrix, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_SetFrwdCoord
 *
 * Purpose:       Sets the Forward Rotated Coordinates of all four corners.
 *
 * Inputs:        pstCoord    - Pointer to forward-rotated Corner Coordinates
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Please note that if coordinates are not given in required
 *                order it will be automatically re-arranged before they are
 *                inserted in the command list (as described in FRCCReg
 *                chapter).
 *
 ***************************************************************************/
void vRot_SetFrwdCoord(rot_frccr_st* pstCoord, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_SetSrcAddrPos
 *
 * Purpose:       Sets the Rotated Source Address Position. This value
 *                specifies the index of the rotated corner that at it’s
 *                original position maps to the source image start address.
 *
 * Inputs:        eSrcSel    - Forward-Rotated Corner Coordinates
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
void vRot_SetSrcAddrPos(rot_SrcSel_e eSrcSel, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_SetRotationCmd
 *
 * Purpose:       Inserts the rotation command in the Command List
 *
 * Inputs:        eClipWndEn - Enable Clipping Window
 *
 *                eFilterEn  - Enable Filtering
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
void vRot_SetRotationCmd(ga_en_e eClipWndEn, ga_en_e eFilterEn, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_SetClippWnd
 *
 * Purpose:       Sets the Clipping Window Coordinates
 *
 * Inputs:        stClipWnd  - Pointer to clipping Window Coordinates
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
void vRot_SetClippWnd(rot_clipWnd_st* pstClipWnd, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_RotateMatrix
 *
 * Purpose:       Inserts all required parameters for source object rotation
 *                operation
 *
 * Inputs:        pstMem      - Pointer to memory configuration parameters
 *
 *                pstParam    - Pointer to scaling Parameters
 *
 *                pstMatrix   - Pointer to transformation matrix
 *
 *                pstCoord    - Pointer to forward rotated corner coordinates
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
void vRot_RotateMatrix(rot_mem_st* pstMem, rot_rotCfg_st* pstParam, rot_Mtrx_st* pstMatrix,
                       rot_frccr_st* pstCoord, ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vRot_RotateBlendMatrix
 *
 * Purpose:       Inserts all required parameters for source object rotation
 *                operation with blending
 *
 * Inputs:        pstMem      - Pointer to memory configuration parameters
 *
 *                pstParam    - Pointer to scaling Parameters
 *
 *                pstMatrix   - Pointer to transformation matrix
 *
 *                pstCoord    - Pointer to forward rotated corner coordinates
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
void vRot_RotateBlendMatrix(rot_mem_st* pstMem, rot_rotblendCfg_st* pstParam, rot_Mtrx_st* pstMatrix,
                            rot_frccr_st* pstCoord, ga_list_st* pstCmdList);

/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */
/****************************************************************************/

#endif /* ROATATION_MATRIX_H */


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: rotation_matrix.h
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

