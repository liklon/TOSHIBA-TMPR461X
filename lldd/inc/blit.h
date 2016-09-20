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
*   VERSION     : $Revision: 1.15 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef BLIT_H
#define BLIT_H

/*======================================
             Include Files
=======================================*/
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

#define LLDD_GA_BLIT_H_REVISION     "$Revision: 1.15 $"
#define LLDD_GA_BLIT_H_TAG          "$Name: LLDD_1_7_GFX $"

/*--------------------------------------------------------------------------------------------
|          ------------------------------------------------------                             |
|         | >>>>>>     BLITTING ENGINE COMMAND INDEX      <<<<<< |                            |
|          ------------------------------------------------------                             |
|---------------------------------------------------------------------------------------------|
|---------------------------------------------------------------------------------------------|
|                                                                                             |
|                      ------------------------------                                         |
|                     |      OPERATION COMMANDS      |                                        |
|                      ------------------------------                                         |
|                                                                                             |
| - Overwrite:                                                                                |
|   1. BLT_ORGB16       - Blit Overw. 16-bit RGB                                     (BltO16) |
|   2. BLT_ORGBA32      - Blit Overw. 32-bit RGB                                     (BltO32) |
|   3. BLT_ORLEI16      - Blit Overw. Run-Len.Enc. 16-bit RGB                    (BltORLEI16) |
|   4. BLT_ORLEI24      - Blit Overwriting Run-Length Encoded Image 24-bit RGB   (BltORLEI24) |
|   5. BLT_ORLEI24A     - Blit Overwriting Run-Length Encoded Image 24-bit RGBA (BltORLEI24A) |
|   6. BLT_ORLEI32      - Blit Overw. Run-Len.Enc. 32-bit RGBA                   (BltORLEI32) |
|   7. BLT_OPRST_RGB16  - Blit Overw. Preset 16-bit RGB                             (BltOP16) |
|   8. BLT_OPRST_RGBA32 - Blit Overw. Preset 32-bit RGBA                            (BltOP32) |
|                                                                                             |
| - Blending:                                                                                 |
|   1. BLT_BRGB16       - Blit Blend. 16-bit RGB                                     (BltB16) |
|   2. BLT_BRGBA32      - Blit Blend. 32-bit RGBA                                    (BltB32) |
|   3. BLT_BRLEI16      - Blit Blend. Run-Len. Enc.16-bit RGB                    (BltBRLEI16) |
|   4. BLT_BRLEI24      - Blit Blending Run-Length Encoded Image 24-bit RGB      (BltBRLEI24) |
|   5. BLT_BRLEI24A     - Blit Blending Run-Length Encoded Image 24A-bit RGBA   (BltBRLEI24A) |
|   6. BLT_BRLEI32      - Blit Blend. Run-Len. Enc.32-bit RGBA                   (BltBRLEI32) |
|   7. BLT_BPRST_RGB16  - Blit Blend. Preset 16-bit RGB                             (BltBP16) |
|   8. BLT_BPRST_RGBA32 - Blit Blend. Preset 32-bit RGBA                            (BltBP32) |
|                                                                                             |
|---------------------------------------------------------------------------------------------|
|                                                                                             |
|                    ----------------------------------                                       |
|                   |      LOAD REGISTER COMMANDS      |                                      |
|                    ----------------------------------                                       |
|                                                                                             |
| - Source Regs:                                                                              |
|    1. BLT_LOAD_SOURCEADDR     -  Load Source Address Reg.                             (SAR) |
|    2. BLT_LOAD_SRCWIDTH       -  Load Source Memory Width Reg.                       (SMWR) |
|                                                                                             |
| - Destination Regs:                                                                         |
|    3. BLT_LOAD_DESTADDR       -  Load Destination Address Reg.                        (DAR) |
|    4. BLT_LOAD_DESTWIDTH      -  Load Destination Memory Width Reg.                  (DMWR) |
|    5. BLT_LOAD_DESTDOTCNT     -  Load Destination Blit DOT Count Reg.               (DBDCR) |
|    6. BLT_LOAD_DESTLINECNT    -  Load Destination Blit LINE Count Reg.              (DBLCR) |
|                                                                                             |
| - Clipping Window Regs:                                                                     |
|    9. BLT_LOAD_CLIP_STARTADDR - Load Clipp. Wnd. Start Addr. Reg.                   (CWSAR) |
|   10. BLT_LOAD_CLIP_WIDTH     - Load Clipping Window Width Reg.                      (CWWR) |
|   11. BLT_LOAD_CLIP_HEIGHT    - Load Clipping Window Height Reg.                     (CWHR) |
|                                                                                             |
| - Conversion Regs:                                                                          |
|   12. BLT_LOAD_SRCALPHA       - Load Source Alpha Value Reg.                         (SAVR) |
|   13. BLT_LOAD_SRCTRANSPATT   - Load Source Transp. Pattern Reg.                     (STPR) |
|   14. BLT_LOAD_DESTALPHA      - Load Destination Alpha Value Reg.                    (DAVR) |
|   15. BLT_LOAD_DESTTRANSPATT  - Load Destination Transparency Reg.                    (DTR) |
|                                                                                             |
| - Filling Regs:                                                                             |
|   16. BLT_LOAD_FILLRGBA       - Load RGBA Fill Preset Reg.                        (RGBAFPR) |
|   17. BLT_LOAD_FILLRGB        - Load RGB Fill Preset Reg.                          (RGBFPR) |
|                                                                                             |
| - Raster/Fading Regs:                                                                       |
|   19. BLT_LOAD_FADEFACT       - Load Fading Factor Reg.                               (FFR) |
|   20. BLT_LOAD_RASTOP         - Load Raster Operation Reg.                            (ROR) |
|                                                                                             |
 --------------------------------------------------------------------------------------------*/



/*=========================================================================
|                            OPERATION COMMANDS                             |
 ==========================================================================*/
/*--------------------------------------------------------------------------
|
|  Command:   Blit Overwriting 16-bit RGB (BltO16)
|
|  Descr  :   The BltO16 command triggers a blitting operation that transfers
|             data from a source stored in the 16-bit RGB format to a
|             destination area stored either in 16-bit RGB or 32-bit RGBA
|             format.
|
|  Params:    destFrmt   - Destination Format
|                          Use: GA_RGB16       - dest. stored in 16-bit frmt.
|                               GA_RGBA32      - dest. stored in 32-bit frmt.
|
|             trnspColEn - Transparency Color Option
|                          Use: GA_EN          - Enable Option
|                               GA_DIS         - Disable Option
|
|             fading     - Fading Option
|                          Use: BLT_NOFADING   - No fading
|                               BLT_FADE_ALL   - RGB and Alpha will be faded
|                               BLT_FADE_ALPHA - Only Alpha will be faded
|                               BLT_FADE_RGB   - ONly RGB will be faded
|
|             ClipWndEn  - Clipping Window Option
|                          Use: GA_EN          - Enable Option
|                               GA_DIS         - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_ORGB16(destFrmt, trnspColEn, fading, ClipWndEn)             \
                   (GA_CMN(GA_BLITING,   1, GA_CMC_BLTO16,              \
                    GA_FP ((destFrmt),   4, GA_MASK1)          |        \
                    GA_FP ((trnspColEn), 3, GA_MASK1)          |        \
                    GA_FP ((fading),     1, GA_MASK2)          |        \
                    GA_FP ((ClipWndEn),  0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Overwriting 32-bit RGBA (BltO32)
|
|  Descr  :   The BltO32 command triggers a blitting operation that transfers
|             data from a source stored in the 32-bit RGB format to a
|             destination area stored either in 16-bit RGB or 32-bit RGBA
|             format.
|
|  Params:    destFrmt  - Destination Format
|                         Use: GA_RGB16       - dest. stored in 16-bit frmt.
|                              GA_RGBA32      - dest. stored in 32-bit frmt.
|
|             fading    - Fading Option
|                         Use: BLT_NOFADING   - No fading
|                              BLT_FADE_ALL   - RGB and Alpha will be faded
|                              BLT_FADE_ALPHA - Only Alpha will be faded
|                              BLT_FADE_RGB   - ONly RGB will be faded
|
|             ClipWndEn - Clipping Window Option
|                         Use: GA_EN          - Enable Option
|                              GA_DIS         - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_ORGBA32(destFrmt, fading, ClipWndEn)                     \
                    (GA_CMN(GA_BLITING,  1, GA_CMC_BLTO32,           \
                     GA_FP ((destFrmt),  3, GA_MASK1)       |        \
                     GA_FP ((fading),    1, GA_MASK2)       |        \
                     GA_FP ((ClipWndEn), 0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Overwriting Run-Length Encoded Image 16-bit RGB
|             (BltORLEI16)
|
|  Descr  :   The BltORLEI16 command triggers a blitting operation that
|             transfers data from a source stored in the run-length encoded
|             16-bit RGB format to a destination area stored either in 16-bit
|             RGB or 32-bit RGBA format.
|
|  Params:    destFrmt   - Destination Format
|                          Use: GA_RGB16       - dest. stored in 16-bit frmt.
|                               GA_RGBA32      - dest. stored in 32-bit frmt.
|
|             trnspColEn - Transparency Color Option
|                          Use: GA_EN          - Enable Option
|                               GA_DIS         - Disable Option
|
|             fading     - Fading Option
|                          Use: BLT_NOFADING   - No fading
|                               BLT_FADE_ALL   - RGB and Alpha will be faded
|                               BLT_FADE_ALPHA - Only Alpha will be faded
|                               BLT_FADE_RGB   - ONly RGB will be faded
|
|             ClipWndEn  - Clipping Window Option
|                          Use: GA_EN          - Enable Option
|                               GA_DIS         - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_ORLEI16(destFrmt, trnspColEn, fading, ClipWndEn)               \
                      (GA_CMN(GA_BLITING,   1, GA_CMC_BLTORLEI16,          \
                       GA_FP ((destFrmt),   4, GA_MASK1)        |          \
                       GA_FP ((trnspColEn), 3, GA_MASK1)        |          \
                       GA_FP ((fading),     1, GA_MASK2)        |          \
                       GA_FP ((ClipWndEn),  0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Overwriting Run-Length Encoded Image 24-bit RGB
|             (BltORLEI24)
|
|  Descr  :   The BltORLEI24 command triggers a blitting operation that
|             transfers data from a source stored in the run-length encoded
|             24-bit RGB format to a destination area stored either in 16-bit
|             RGB or 32-bit RGBA format.
|
|  Params:    destFrmt   - Destination Format
|                          Use: GA_RGB16       - dest. stored in 16-bit frmt.
|                               GA_RGBA32      - dest. stored in 32-bit frmt.
|
|             trnspColEn - Transparency Color Option
|                          Use: GA_EN          - Enable Option
|                               GA_DIS         - Disable Option
|
|             fading     - Fading Option
|                          Use: BLT_NOFADING   - No fading
|                               BLT_FADE_ALL   - RGB and Alpha will be faded
|                               BLT_FADE_ALPHA - Only Alpha will be faded
|                               BLT_FADE_RGB   - ONly RGB will be faded
|
|             ClipWndEn  - Clipping Window Option
|                          Use: GA_EN          - Enable Option
|                               GA_DIS         - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_ORLEI24(destFrmt, trnspColEn, fading, ClipWndEn)               \
                      (GA_CMN(GA_BLITING,   1, GA_CMC_BLTORLEI24,          \
                       GA_FP ((destFrmt),   4, GA_MASK1)        |          \
                       GA_FP ((trnspColEn), 3, GA_MASK1)        |          \
                       GA_FP ((fading),     1, GA_MASK2)        |          \
                       GA_FP ((ClipWndEn),  0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Overwriting Run-Length Encoded Image 24-bit RGBA
|             (BltORLEI24A)
|
|  Descr  :   The BltORLEI32 command triggers a blitting operation that
|             transfers data from a source stored in the run-length encoded
|             32-bit RGBA format to a destination area stored in 32-bit RGBA
|             format.
|
|  Params:    destFrmt  - Destination Format
|                         Use: GA_RGB16      - dest. stored in 16-bit frmt.
|                              GA_RGBA32     - dest. stored in 32-bit frmt.
|
|             fading    - Fading Option
|                         Use: BLT_NOFADING   - No fading
|                              BLT_FADE_ALL   - RGB and Alpha will be faded
|                              BLT_FADE_ALPHA - Only Alpha will be faded
|                              BLT_FADE_RGB   - ONly RGB will be faded
|
|             ClipWndEn - Clipping Window Option
|                         Use: GA_EN          - Enable Option
|                              GA_DIS         - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_ORLEI24A(destFrmt, fading, ClipWndEn)                           \
                     (GA_CMN(GA_BLITING,  1, GA_CMC_BLTORLEI24A,            \
                      GA_FP ((destFrmt),  3, GA_MASK1)          |           \
                      GA_FP ((fading),    1, GA_MASK2)          |           \
                      GA_FP ((ClipWndEn), 0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Overwriting Run-Length Encoded Image 32-bit RGBA
|             (BltORLEI32)
|
|  Descr  :   The BltORLEI32 command triggers a blitting operation that
|             transfers data from a source stored in the run-length encoded
|             32-bit RGBA format to a destination area stored in 32-bit RGBA
|             format.
|
|  Params:    destFrmt  - Destination Format
|                         Use: GA_RGB16      - dest. stored in 16-bit frmt.
|                              GA_RGBA32     - dest. stored in 32-bit frmt.
|
|             fading    - Fading Option
|                         Use: BLT_NOFADING   - No fading
|                              BLT_FADE_ALL   - RGB and Alpha will be faded
|                              BLT_FADE_ALPHA - Only Alpha will be faded
|                              BLT_FADE_RGB   - ONly RGB will be faded
|
|             ClipWndEn - Clipping Window Option
|                         Use: GA_EN          - Enable Option
|                              GA_DIS         - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_ORLEI32(destFrmt, fading, ClipWndEn)                            \
                     (GA_CMN(GA_BLITING,  1, GA_CMC_BLTORLEI32,             \
                      GA_FP ((destFrmt),  3, GA_MASK1)          |           \
                      GA_FP ((fading),    1, GA_MASK2)          |           \
                      GA_FP ((ClipWndEn), 0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Overwriting Preset 16-bit RGB (BltOP16)
|
|  Descr  :   The BltOP16 command triggers a blitting operation that blits
|             the data from the RGB Fill Preset Register with to the
|             destination stored in 16-bit RGB format.
|
|  Params:    fading    - Fading Option
|                         Use: BLT_NOFADING   - No fading
|                              BLT_FADE_ALL   - RGB and Alpha will be faded
|                              BLT_FADE_ALPHA - Only Alpha will be faded
|                              BLT_FADE_RGB   - ONly RGB will be faded
|
|             ClipWndEn - Clipping Window Option
|                         Use: GA_EN          - Enable Option
|                              GA_DIS         - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_OPRST_RGB16(fading, ClipWndEn)                                \
                       (GA_CMN(GA_BLITING,  1, GA_CMC_BLTOP16,            \
                        GA_FP ((fading),    1, GA_MASK2)    |             \
                        GA_FP ((ClipWndEn), 0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Overwriting Preset 32-bit RGBA (BltOP32)
|
|  Descr  :   The BltOP32 command triggers a blitting operation that blits
|             the data from the RGBA Fill Preset Register to the destination
|             stored in 32-bit RGBA format.
|
|  Params:    fading    - Fading Option
|                         Use: BLT_NOFADING   - No fading
|                              BLT_FADE_ALL   - RGB and Alpha will be faded
|                              BLT_FADE_ALPHA - Only Alpha will be faded
|                              BLT_FADE_RGB   - Only RGB will be faded
|
|             ClipWndEn - Clipping Window Option
|                         Use: GA_EN          - Enable Option
|                              GA_DIS         - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_OPRST_RGBA32(fading, ClipWndEn)                              \
                        (GA_CMN(GA_BLITING,  1, GA_CMC_BLTOP32,          \
                         GA_FP ((fading),    1, GA_MASK2)    |           \
                         GA_FP ((ClipWndEn), 0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Blending 16-bit RGB (BltB16)
|
|  Descr  :   The BltB16 command triggers a blitting operation that blends
|             data from a source stored in the 16-bit RGB format with a
|             destination area stored in either 16-bit RGB or 32-bit RGBA
|             format.
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
|             rastOpEn    - Raster Operation Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             blndOrder   - Blending Order
|                           Use: BLT_ONTO_DEST   - Onto destination
|                                BLT_BEHIND_DEST - Behind the destination
|                         
|             destFrmt    - Destination Format
|                           Use: GA_RGB16        - dest. stored in 16-bit frmt.
|                                GA_RGBA32       - dest. stored in 32-bit frmt.
|                         
|                         
|             trnspColEn  - Transparency Color Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             fading      - Fading Option
|                           Use: BLT_NOFADING    - No fading
|                                BLT_FADE_ALL    - RGB and Alpha will be faded
|                                BLT_FADE_ALPHA  - Only Alpha will be faded
|                                BLT_FADE_RGB    - ONly RGB will be faded
|                         
|             ClipWndEn   - Clipping Window Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
 -------------------------------------------------------------------------*/
#define BLT_BRGB16(redChProt,                                           \
                   greenChProt,                                         \
                   blueChProt,                                          \
                   alphaProt,                                           \
                   rastOpEn,                                            \
                   destFrmt,                                            \
                   blndOrder,                                           \
                   trnspColEn,                                          \
                   fading,                                              \
                   ClipWndEn)                                           \
                   (GA_CMN((GA_BLITING),  1, GA_CMC_BLTB16,             \
                    GA_FP ((redChProt),  10, GA_MASK1)          |       \
                    GA_FP ((greenChProt), 9, GA_MASK1)          |       \
                    GA_FP ((blueChProt),  8, GA_MASK1)          |       \
                    GA_FP ((alphaProt),   7, GA_MASK1)          |       \
                    GA_FP ((rastOpEn),    6, GA_MASK1)          |       \
                    GA_FP ((destFrmt),    5, GA_MASK1)          |       \
                    GA_FP ((blndOrder),   4, GA_MASK1)          |       \
                    GA_FP ((trnspColEn),  3, GA_MASK1)          |       \
                    GA_FP ((fading),      1, GA_MASK2)          |       \
                    GA_FP ((ClipWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Blending 32-bit RGBA (BltB32)
|
|  Descr  :   The BltB32 command triggers a blitting operation that blends
|             data from a source stored in the 32-bit RGBA format with a
|             destination area stored in either 16-bit RGB or 32-bit RGBA
|             format.
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
|             rastOpEn    - Raster Operation Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             blndOrder   - Blending Order
|                           Use: BLT_ONTO_DEST   - Onto destination
|                                BLT_BEHIND_DEST - Behind the destination
|                         
|             destFrmt    - Destination Format
|                           Use: GA_RGB16        - dest. stored in 16-bit frmt.
|                                GA_RGBA32       - dest. stored in 32-bit frmt.
|                         
|             trnspColEn  - Transparency Color Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             fading      - Fading Option
|                           Use: BLT_NOFADING    - No fading
|                                BLT_FADE_ALL    - RGB and Alpha will be faded
|                                BLT_FADE_ALPHA  - Only Alpha will be faded
|                                BLT_FADE_RGB    - ONly RGB will be faded
|                         
|             ClipWndEn   - Clipping Window Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_BRGBA32(redChProt,                                           \
                    greenChProt,                                         \
                    blueChProt,                                          \
                    alphaProt,                                           \
                    rastOpEn,                                            \
                    destFrmt,                                            \
                    blndOrder,                                           \
                    trnspColEn,                                          \
                    fading,                                              \
                    ClipWndEn)                                           \
                    (GA_CMN(GA_BLITING,    1, GA_CMC_BLTB32,             \
                     GA_FP ((redChProt),  10, GA_MASK1)        |         \
                     GA_FP ((greenChProt), 9, GA_MASK1)        |         \
                     GA_FP ((blueChProt),  8, GA_MASK1)        |         \
                     GA_FP ((alphaProt),   7, GA_MASK1)        |         \
                     GA_FP ((rastOpEn),    6, GA_MASK1)        |         \
                     GA_FP ((destFrmt),    5, GA_MASK1)        |         \
                     GA_FP ((blndOrder),   4, GA_MASK1)        |         \
                     GA_FP ((trnspColEn),  3, GA_MASK1)        |         \
                     GA_FP ((fading),      1, GA_MASK2)        |         \
                     GA_FP ((ClipWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Blending Run-Length Encoded Image 16-bit RGB (BltBRLEI16)
|
|  Descr  :   The BltBRLEI16 command triggers a blitting operation that
|             blends data from a source stored in the run-length encoded
|             16-bit RGB format with a destination area stored in either
|             16-bit RGB or 32-bit RGBA format.
|
|  Params:    redChProt  - Red Channel Protection
|                          Use: GA_EN           - Channel Protected
|                               GA_DIS          - Channel Not Protected
|
|             greenChProt- Green Channel Protection
|                          Use: GA_EN           - Channel Protected
|                               GA_DIS          - Channel Not Protected
|
|             blueChProt - Blue Channel Protection
|                          Use: GA_EN           - Channel Protected
|                               GA_DIS          - Channel Not Protected
|
|             alphaProt  - Alpha Channel Protection
|                          Use: GA_EN           - Channel Protected
|                               GA_DIS          - Channel Not Protected
|
|             rastOpEn   - Raster Operation Option
|                          Use: GA_EN           - Enable Option
|                               GA_DIS          - Disable Option
|
|             blndOrder  - Blending Order
|                          Use: BLT_ONTO_DEST   - Onto destination
|                               BLT_BEHIND_DEST - Behind the destination
|
|             destFrmt   - Destination Format
|                          Use: GA_RGB16        - dest. stored in 16-bit frmt.
|                               GA_RGBA32       - dest. stored in 32-bit frmt.
|
|             trnspColEn - Transparency Color Option
|                          Use: GA_EN           - Enable Option
|                               GA_DIS          - Disable Option
|
|             fading     - Fading Option
|                          Use: BLT_NOFADING    - No fading
|                               BLT_FADE_ALL    - RGB and Alpha will be faded
|                               BLT_FADE_ALPHA  - Only Alpha will be faded
|                               BLT_FADE_RGB    - Only RGB will be faded
|
|             ClipWndEn  - Clipping Window Option
|                          Use: GA_EN           - Enable Option
|                               GA_DIS          - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_BRLEI16(redChProt,                                       \
                    greenChProt,                                     \
                    blueChProt,                                      \
                    alphaProt,                                       \
                    rastOpEn,                                        \
                    destFrmt,                                        \
                    blndOrder,                                       \
                    trnspColEn,                                      \
                    fading,                                          \
                    ClipWndEn)                                       \
                    (GA_CMN(GA_BLITING,  1, GA_CMC_BLTBRLEI16,       \
                     GA_FP ((redChProt),  10, GA_MASK1)        |     \
                     GA_FP ((greenChProt), 9, GA_MASK1)        |     \
                     GA_FP ((blueChProt),  8, GA_MASK1)        |     \
                     GA_FP ((alphaProt),   7, GA_MASK1)        |     \
                     GA_FP ((rastOpEn),    6, GA_MASK1)        |     \
                     GA_FP ((destFrmt),    5, GA_MASK1)        |     \
                     GA_FP ((blndOrder),   4, GA_MASK1)        |     \
                     GA_FP ((trnspColEn),  3, GA_MASK1)        |     \
                     GA_FP ((fading),      1, GA_MASK2)        |     \
                     GA_FP ((ClipWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Blending Run-Length Encoded Image 24-bit RGB (BltBRLEI24)
|
|  Descr  :   The BltBRLEI24 command triggers a blitting operation that
|             blends data from a source stored in the run-length encoded
|             16-bit RGB format with a destination area stored in either
|             16-bit RGB or 32-bit RGBA format.
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
|             rastOpEn    - Raster Operation Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             blndOrder   - Blending Order
|                           Use: BLT_ONTO_DEST   - Onto destination
|                                BLT_BEHIND_DEST - Behind the destination
|                         
|             destFrmt    - Destination Format
|                           Use: GA_RGB16        - dest. stored in 16-bit frmt.
|                                GA_RGBA32       - dest. stored in 32-bit frmt.
|                         
|             trnspColEn  - Transparency Color Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             fading      - Fading Option
|                           Use: BLT_NOFADING    - No fading
|                                BLT_FADE_ALL    - RGB and Alpha will be faded
|                                BLT_FADE_ALPHA  - Only Alpha will be faded
|                                BLT_FADE_RGB    - Only RGB will be faded
|                         
|             ClipWndEn   - Clipping Window Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_BRLEI24(redChProt,                                       \
                    greenChProt,                                     \
                    blueChProt,                                      \
                    alphaProt,                                       \
                    rastOpEn,                                        \
                    destFrmt,                                        \
                    blndOrder,                                       \
                    trnspColEn,                                      \
                    fading,                                          \
                    ClipWndEn)                                       \
                    (GA_CMN(GA_BLITING,  1, GA_CMC_BLTBRLEI24,       \
                     GA_FP ((redChProt),  10, GA_MASK1)        |     \
                     GA_FP ((greenChProt), 9, GA_MASK1)        |     \
                     GA_FP ((blueChProt),  8, GA_MASK1)        |     \
                     GA_FP ((alphaProt),   7, GA_MASK1)        |     \
                     GA_FP ((rastOpEn),    6, GA_MASK1)        |     \
                     GA_FP ((destFrmt),    5, GA_MASK1)        |     \
                     GA_FP ((blndOrder),   4, GA_MASK1)        |     \
                     GA_FP ((trnspColEn),  3, GA_MASK1)        |     \
                     GA_FP ((fading),      1, GA_MASK2)        |     \
                     GA_FP ((ClipWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Blending Run-Length Encoded Image 24A-bit RGBA (BltBRLEI24A)
|
|  Descr  :   The BltBRLEI24A command triggers a blitting operation that
|             blends data from a source stored in the run-length encoded
|             24-bit RGBA format with a destination area stored in 32-bit
|             RGBA format.
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
|             rastOpEn    - Raster Operation Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             destFrmt    - Destination Format
|                           Use: GA_RGB16        - dest. stored in 16-bit frmt.
|                                GA_RGBA32       - dest. stored in 32-bit frmt.
|                         
|             blndOrder   - Blending Order
|                           Use: BLT_ONTO_DEST   - Onto destination
|                                BLT_BEHIND_DEST - Behind the destination
|                         
|             trnspColEn  - Transparency Color Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             fading      - Fading Option
|                           Use: BLT_NOFADING    - No fading
|                                BLT_FADE_ALL    - RGB and Alpha will be faded
|                                BLT_FADE_ALPHA  - Only Alpha will be faded
|                                BLT_FADE_RGB    - Only RGB will be faded
|                         
|             ClipWndEn   - Clipping Window Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
 -------------------------------------------------------------------------*/
#define BLT_BRLEI24A(redChProt,                                       \
                     greenChProt,                                     \
                     blueChProt,                                      \
                     alphaProt,                                       \
                     rastOpEn,                                        \
                     destFrmt,                                        \
                     blndOrder,                                       \
                     trnspColEn,                                      \
                     fading,                                          \
                     ClipWndEn)                                       \
                     (GA_CMN(GA_BLITING,  1, GA_CMC_BLTBRLEI24A,      \
                      GA_FP ((redChProt),  10, GA_MASK1)        |     \
                      GA_FP ((greenChProt), 9, GA_MASK1)        |     \
                      GA_FP ((blueChProt),  8, GA_MASK1)        |     \
                      GA_FP ((alphaProt),   7, GA_MASK1)        |     \
                      GA_FP ((rastOpEn),    6, GA_MASK1)        |     \
                      GA_FP ((destFrmt),    5, GA_MASK1)        |     \
                      GA_FP ((blndOrder),   4, GA_MASK1)        |     \
                      GA_FP ((trnspColEn),  3, GA_MASK1)        |     \
                      GA_FP ((fading),      1, GA_MASK2)        |     \
                      GA_FP ((ClipWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Blending Run-Length Encoded Image 32-bit RGBA (BltBRLEI32)
|
|  Descr  :   The BltBRLEI32 command triggers a blitting operation that
|             blends data from a source stored in the run-length encoded
|             32-bit RGBA format with a destination area stored in 32-bit
|             RGBA format.
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
|             rastOpEn    - Raster Operation Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             destFrmt    - Destination Format
|                           Use: GA_RGB16        - dest. stored in 16-bit frmt.
|                                GA_RGBA32       - dest. stored in 32-bit frmt.
|                         
|             blndOrder   - Blending Order
|                           Use: BLT_ONTO_DEST   - Onto destination
|                                BLT_BEHIND_DEST - Behind the destination
|                         
|             trnspColEn  - Transparency Color Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             fading      - Fading Option
|                           Use: BLT_NOFADING    - No fading
|                                BLT_FADE_ALL    - RGB and Alpha will be faded
|                                BLT_FADE_ALPHA  - Only Alpha will be faded
|                                BLT_FADE_RGB    - Only RGB will be faded
|                         
|             ClipWndEn   - Clipping Window Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_BRLEI32(redChProt,                                       \
                    greenChProt,                                     \
                    blueChProt,                                      \
                    alphaProt,                                       \
                    rastOpEn,                                        \
                    destFrmt,                                        \
                    blndOrder,                                       \
                    trnspColEn,                                      \
                    fading,                                          \
                    ClipWndEn)                                       \
                    (GA_CMN(GA_BLITING,  1, GA_CMC_BLTBRLEI32,       \
                     GA_FP ((redChProt),  10, GA_MASK1)        |     \
                     GA_FP ((greenChProt), 9, GA_MASK1)        |     \
                     GA_FP ((blueChProt),  8, GA_MASK1)        |     \
                     GA_FP ((alphaProt),   7, GA_MASK1)        |     \
                     GA_FP ((rastOpEn),    6, GA_MASK1)        |     \
                     GA_FP ((destFrmt),    5, GA_MASK1)        |     \
                     GA_FP ((blndOrder),   4, GA_MASK1)        |     \
                     GA_FP ((trnspColEn),  3, GA_MASK1)        |     \
                     GA_FP ((fading),      1, GA_MASK2)        |     \
                     GA_FP ((ClipWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Blending Preset 16-bit RGB (BltBP16)
|
|  Descr  :   The BltBP16 command triggers a blitting operation that blends
|             the data from the RGB Fill Preset Register with a destination
|             stored in 16-bit RGB format.
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
|             rastOpEn    - Raster Operation Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             blndOrder   - Blending Order
|                           Use: BLT_ONTO_DEST   - Onto destination
|                                BLT_BEHIND_DEST - Behind the destination
|                         
|             fading      - Fading Option
|                           Use: BLT_NOFADING    - No fading
|                                BLT_FADE_ALL    - RGB and Alpha will be faded
|                                BLT_FADE_ALPHA  - Only Alpha will be faded
|                                BLT_FADE_RGB    - Only RGB will be faded
|                         
|             ClipWndEn   - Clipping Window Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_BPRST_RGB16(redChProt,                                        \
                        greenChProt,                                      \
                        blueChProt,                                       \
                        rastOpEn,                                         \
                        blndOrder,                                        \
                        fading,                                           \
                        ClipWndEn)                                        \
                        (GA_CMN(GA_BLITING,  1, GA_CMC_BLTBP16,           \
                         GA_FP ((redChProt),  10, GA_MASK1)        |      \
                         GA_FP ((greenChProt), 9, GA_MASK1)        |      \
                         GA_FP ((blueChProt),  8, GA_MASK1)        |      \
                         GA_FP (       0,      7, GA_MASK1)        |      \
                         GA_FP ((rastOpEn),    6, GA_MASK1)        |      \
                         GA_FP (       0,      5, GA_MASK1)        |      \
                         GA_FP (       0,      4, GA_MASK1)        |      \
                         GA_FP ((blndOrder),   3, GA_MASK1)        |      \
                         GA_FP ((fading),      1, GA_MASK2)        |      \
                         GA_FP ((ClipWndEn),   0, GA_MASK1)))

/*--------------------------------------------------------------------------
|
|  Command:   Blit Blending Preset 32-bit RGBA (BltBP32)
|
|  Descr  :   The BltBP32 command triggers a blitting operation that blends
|             the data from the RGBA Fill Preset Register with a destination
|             stored in 32-bit RGBA format.
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
|             rastOpEn    - Raster Operation Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             blndOrder   - Blending Order
|                           Use: BLT_ONTO_DEST   - Onto destination
|                                BLT_BEHIND_DEST - Behind the destination
|                         
|             trnspColEn  - Transparency Color Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|                         
|             fading      - Fading Option
|                           Use: BLT_NOFADING    - No fading
|                                BLT_FADE_ALL    - RGB and Alpha will be faded
|                                BLT_FADE_ALPHA  - Only Alpha will be faded
|                                BLT_FADE_RGB    - Only RGB will be faded
|                         
|             ClipWndEn   - Clipping Window Option
|                           Use: GA_EN           - Enable Option
|                                GA_DIS          - Disable Option
|
 -------------------------------------------------------------------------*/
#define BLT_BPRST_RGBA32(redChProt,                                       \
                         greenChProt,                                     \
                         blueChProt,                                      \
                         alphaProt,                                       \
                         rastOpEn,                                        \
                         blndOrder,                                       \
                         fading,                                          \
                         ClipWndEn)                                       \
                         (GA_CMN(GA_BLITING,  1, GA_CMC_BLTBP32,          \
                          GA_FP ((redChProt),  10, GA_MASK1)        |     \
                          GA_FP ((greenChProt), 9, GA_MASK1)        |     \
                          GA_FP ((blueChProt),  8, GA_MASK1)        |     \
                          GA_FP ((alphaProt),   7, GA_MASK1)        |     \
                          GA_FP ((rastOpEn),    6, GA_MASK1)        |     \
                          GA_FP (       0,      5, GA_MASK1)        |     \
                          GA_FP (       0,      4, GA_MASK1)        |     \
                          GA_FP ((blndOrder),   3, GA_MASK1)        |     \
                          GA_FP ((fading),      1, GA_MASK2)        |     \
                          GA_FP ((ClipWndEn),   0, GA_MASK1)))

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
|             is the pointer to the first dot in memory that should be
|             transferred from the source (within the source segment).
|
|  Params:    addr - Source Address
|                    The lower 32 physical address bits that point to the
|                    first dot of the source.
|
|  Limit.:    Depending on the source format this address has to be
|             doubleword, word, halfword or byte aligned. The following
|             table shows the possible alignments:
|
|                ---------------------------------------------
|               |   Src.Frmt.  |Dword | Word |Halfword | Byte |
|               |=============================================|
|               |  32-bit RGBA |  X   |  X   |         |      |
|               |  16-bit RGB  |  X   |  X   |    X    |      |
|               |  RLE 32      |  X   |      |         |      |
|               |  RLE 24      |  X   |      |         |      |
|               |  RLE 24A     |  X   |      |         |      |
|               |  RLE 16      |  X   |      |         |      |
|                ---------------------------------------------
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_SOURCEADDR(addr) (GA_LOAD(GA_GPR9, (addr)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Source Memory Width Register (SMWR)
|
|  Descr  :   The Load General-Purpose Register command is used to load SMWR.
|             The source memory width register specifies the memory reserved
|             for one line within the source image in number of dots.
|             (Note that this value can be different to the number of dots
|             to be blitted per line!)
|
|
|  Params:    width - Source Memory Width
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
#define BLT_LOAD_SRCWIDTH(width) (GA_LOAD(GA_GPR10, ((width) & GA_MASK12)))

/*------------------------------
|     DESTINATION REGISTERS     |
 ------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Address Register (DAR)
|
|  Descr  :   The Load General-Purpose Register command is used to load DAR.
|             The physical 32-bit address within the destination address
|             register is the pointer to the first dot in memory that should
|             be blitted to the destination (within the destination segment).
|
|  Params:    addr - Destination Address
|                    The lower 32 physical address bits that point to the
|                    first dot of the destination.
|
|  Limit.:    Depending on the destination format this address has to be
|             doubleword, word, halfword or byte aligned. The following
|             table shows the possible alignments:
|
|                --------------------------------------
|               |  Dest.Frmt.  | Word |Halfword | Byte |
|               |======================================|
|               |  32-bit RGBA |  X   |         |      |
|               |  16-bit RGB  |  X   |    X    |      |
|                --------------------------------------
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_DESTADDR(addr) (GA_LOAD(GA_GPR4, (addr)))

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
#define BLT_LOAD_DESTWIDTH(width) (GA_LOAD(GA_GPR5, ((width) & GA_MASK12)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Blit DOT Count Register (DBDCR)
|
|  Descr  :   The Destination Blit Dot Count Registers specifies the number
|             of dots per line that should be blitted into the destination.
|             If a clipping window is defined, the Blitting Engine could
|             process less dots per line.
|
|  Params:    dotCnt - Destination Blit Dot Count
|                      Number of dots to be blitted into the destination per
|                      line (1 up to 4095).
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_DESTDOTCNT(dotCnt) (GA_LOAD(GA_GPR6,                      \
                                     ((dotCnt) & GA_MASK12)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Blit LINE Count Register (DBLCR)
|
|  Descr  :   The Destination Blit Line Count Register specifies the number
|             if lines that should be transferred to the destination. If a
|             clipping window is defined the Blitting Engine could process
|             less lines.
|
|  Params:    lineCnt - Destination Blit Line Count
|                       Number of lines to be blitted into the destination
|                       (1 up to 4095).
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_DESTLINECNT(lineCnt) (GA_LOAD(GA_GPR7,                    \
                                       ((lineCnt) & GA_MASK12)))

/*------------------------------
|    CLIPPING WND. REGISTERS    |
 ------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Clipping Window Start Address Register (CWSAR)
|
|  Descr  :   The Clipping Window Start Address Register keeps the pointer
|             to the first dot within the clipping window. The upper 4
|             address bits are taken from the Destination Segment Register,
|             because the clipping window has to be defined with respect to
|             the destination.
|
|  Params:    addr - Clipping Window Start Address
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_CLIP_STARTADDR(addr) (GA_LOAD(GA_GPR0, (addr)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Clipping Window Width Register (CWWR)
|
|  Descr  :   The Clipping Window Width Register defines the number of dots
|             within the clipping window in horizontal direction.
|
|  Params:    width - Clipping Window Width
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_CLIP_WIDTH(width) (GA_LOAD(GA_GPR1,                       \
                                    ((width) & GA_MASK12)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Clipping Window Height Register (CWHR)
|
|  Descr  :   The Clipping Window Height Register defines the number of
|             lines within the clipping window.
|
|  Params:    height - Clipping Window Height
|                      Number of lines within the clipping window in
|                      horizontal direction (1 up to 4095).
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_CLIP_HEIGHT(height) (GA_LOAD(GA_GPR2,                     \
                                      ((height) & GA_MASK12)))

/*------------------------------
|   CONVERSION CFG. REGISTERS   |
 ------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Source Alpha Value Register (SAVR)
|
|  Descr  :   The Source Alpha Value Register keeps the alpha value for
|             conversion of the source dots from the 16-bit RGB format
|             to the 32-bit RGBA format for internal processing.
|
|  Params:    alpha - Source Alpha Value
|                     8-bit Alpha Value used for expanding source dots
|                     during conversion from 16-bit RGB to 32-bit RGBA
|                     for internal processing.
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_SRCALPHA(alpha) (GA_LOAD(GA_GPR13,                        \
                                  ((alpha) & GA_MASK8)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Source Transparency Pattern Register (STPR)
|
|  Descr  :   When the transparency color option is enabled the value stored
|             in this register is the comparison pattern during conversion
|             from 16-bit RGB to 32-bit RGBA format.
|
|  Params:    pattern - Source Transparency Pattern
|                       Pattern for comparison of source dots
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_SRCTRANSPATT(pattern) (GA_LOAD(GA_GPR14,                  \
                                        ((pattern) & GA_MASK24)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Alpha Value Register (DAVR)
|
|  Descr  :   The Destination Alpha Value Register keeps the alpha value
|             used during conversion of the destination dots from the 16-bit
|             RGB format to the 32-bit RGBA format.
|
|  Params:    alpha - Destination Alpha Value
|                     8-bit alpha value used for expanding destination dots
|                     during conversion from 16-bit RGB to 32-bit RGBA
|                     for internal processing.
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_DESTALPHA(alpha) (GA_LOAD(GA_GPR15,                       \
                                   ((alpha) & GA_MASK8)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Destination Transparency Register (DTR)
|
|  Descr  :   When the transparency color option is enabled the value stored
|             in this register is the comparison pattern during conversion
|             from 16-bit RGB to 32-bit RGBA format.
|
|  Params:    pattern - Destination Transparency Pattern
|                       Pattern for comparison of destination dots.
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_DESTTRANSPATT(pattern) (GA_LOAD(GA_GPR16,                 \
                                         ((pattern) & GA_MASK16)))

/*------------------------------
|     FILLING CFG. REGISTERS    |
 ------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load RGBA Fill Preset Register (RGBAFPR)
|
|  Descr  :   The RGBA Fill Preset Register content is used when the filling
|             option is enabled and the destination is in 32-bit RGBA mode.
|
|  Params:    val - RGBA Fill Preset (32-bit)
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_FILLRGBA(Val) (GA_LOAD(GA_GPR17,(Val)))

/*--------------------------------------------------------------------------
|
|  Command:   Load RGB Fill Preset Register (RGBFPR)
|
|  Descr  :   The content of the RGB Fill Preset Register is used, when the
|             destination is within the 16-bit RGB mode.
|
|  Params:    val - RGB Fill Preset (16-bit)
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_FILLRGB(Val) (GA_LOAD(GA_GPR18,((Val) & GA_MASK16)))

/*------------------------------
|    FADING/RASTER REGISTERS    |
 ------------------------------*/
/*--------------------------------------------------------------------------
|
|  Command:   Load Fading Factor Register (FFR)
|
|  Descr  :   The Fading Factor Register holds the fading factor enumerator
|             (FFE) of the fading factor.
|
|  Params:    factor - Fading Factor Enumerator
|                      These bits specify the enumerator of the fading
|                      factor FFACT.
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_FADEFACT(factor) (GA_LOAD(GA_GPR20,                       \
                                   ((factor) & GA_MASK8)))

/*--------------------------------------------------------------------------
|
|  Command:   Load Raster Operation Register (ROR)
|
|  Descr  :   The Raster Operation Register consists of the Raster Operation
|             Mode and the Raster Operation Value.
|
|  Params:    rastOpMode - Raster Operation Mode
|                          This setting determines on which channels the
|                          raster operation takes place.
|                          Use following parameters:
|                          BLT_RGBA_CH
|                          BLT_RGB_CH
|                          BLT_ALPHA_CH
|                          BLT_ALPHA_DEST_CH
|                          BLT_ALPHA_SRC_CH
|
|             rastOpVal  - Raster Operation Value
|
 -------------------------------------------------------------------------*/
#define BLT_LOAD_RASTOP(rastOpMode, rastOpVal) (GA_LOAD(GA_GPR21,      \
                        GA_FP ((rastOpMode), 16, GA_MASK3)   |         \
                        GA_FP ((rastOpVal),   0, GA_MASK4)))


/*======================================
                Enums
=======================================*/
/* RLEI Format in RGB mode without alpha channel */
typedef enum tag_blt_rleifmt_rgb_e
{
    RLEI_OVRFMT_RGB16       = 0x0u,     /* Source format in format RLEI-16  */
    RLEI_OVRFMT_RGB24       = 0x1u      /* Source format in format RLEI-24  */
} blt_rleifmt_rgb_e;

/* RLEI Format in RGBA mode with alpha channel */
typedef enum tag_blt_rleifmt_rgba_e
{
    RLEI_OVRFMT_RGBA24      = 0x2u,     /* Source format in format RLEI-24A */
    RLEI_OVRFMT_RGBA32      = 0x3u      /* Source format in format RLEI-32  */
} blt_rleifmt_rgba_e;

/* RLEI Format in RGBx mode with and without alpha channel */
typedef enum tag_blt_rleifmt_rgbx_e
{
    RLEI_BLNDFMT_RGB16       = 0x0u,     /* Source format in format RLEI-16  */
    RLEI_BLNDFMT_RGB24       = 0x1u,     /* Source format in format RLEI-24  */
    RLEI_BLNDFMT_RGBA24      = 0x2u,     /* Source format in format RLEI-24A */
    RLEI_BLNDFMT_RGBA32      = 0x3u      /* Source format in format RLEI-32  */
} blt_rleifmt_rgbx_e;

/* Memory Region Selection */
typedef enum tag_blt_memSel_e
{
    BLT_MEM_SRC          = 0x1u,     /* Source Memory Parameters */
    BLT_MEM_DST          = 0x2u,     /* Destination Memory Parameters */
    BLT_MEM_ALL          = 0x3u      /* Both Source and Destination */
} ga_memSel_e;

/* Fading Mode Selection */
typedef enum tag_blt_fadeMode_e
{
    BLT_NOFADING         = 0x0u,     /* No fading */
    BLT_FADE_ALL         = 0x1u,     /* RGB and Alpha will be faded */
    BLT_FADE_ALPHA       = 0x2u,     /* Only Alpha will be faded */
    BLT_FADE_RGB         = 0x3u      /* Only RGB will be faded */
} blt_fadeMode_e;

/* Raster Op. Channel selection */
typedef enum tag_blt_rastChSel_e
{
    BLT_RGBA_CH          = 0x0u,     /* Rast op. on all channels */
    BLT_RGB_CH           = 0x1u,     /* Rast op. on RGB channels */
    BLT_ALPHA_CH         = 0x2u,     /* Rast op. on Alpha ch. only */
    BLT_ALPHA_DEST_CH    = 0x3u,     /* Rast op. RGB and keep Dst. alpha ch.*/
    BLT_ALPHA_SRC_CH     = 0x4u      /* Rast op. RGB and keep Src. alpha ch.*/
} blt_rastChSel_e;

/* Raster Operation Values */
typedef enum tag_blt_rastOpVal_e
{
    /* Source ONLY */
    BLT_RAST_SOURCE      = 0xcu,     /* Source */
    BLT_RAST_SRC_INV     = 0x3u,     /* Inverts the Source */

    /* Destination ONLY */
    BLT_RAST_DEST        = 0xau,     /* Destination */
    BLT_RAST_DEST_ZERO   = 0x0u,     /* Sets destination to 0  */
    BLT_RAST_DEST_ONE    = 0xfu,     /* Sets destination to 1  */
    BLT_RAST_DEST_INV    = 0x5u,     /* Inverts the Destination*/

    /* Boolean AND */
    BLT_RAST_S_AND_D     = 0x8u,     /*  ( Src. AND  Dest.) */
    BLT_RAST_NS_AND_D    = 0x2u,     /*  (~Src. AND  Dest.) */
    BLT_RAST_S_AND_ND    = 0x4u,     /*  ( Src. AND ~Dest.) */
    BLT_RAST_S_AND_D_INV = 0x7u,     /* ~( Src. AND  Dest.) */

    /* Boolean OR */
    BLT_RAST_S_OR_D      = 0xeu,     /*  ( Src. OR  Dest.) */
    BLT_RAST_NS_OR_D     = 0xbu,     /*  (~Src. OR  Dest.) */
    BLT_RAST_S_OR_ND     = 0xdu,     /*  ( Src. OR ~Dest.) */
    BLT_RAST_S_OR_D_INV  = 0x1u,     /* ~( Src. OR  Dest.) */

    /* Boolean XOR */
    BLT_RAST_S_XOR_D     = 0x6u,     /*  ( Src. XOR Dest.) */
    BLT_RAST_S_XOR_D_INV = 0x9u      /* ~( Src. XOR Dest.) */
} blt_rastOpVal_e;


/*======================================
              Structures
=======================================*/

/* Memory Blitting structure */
typedef struct tag_blit_mem_st
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
    /* Blitting Area Size */
    uint16_t      u16DotCnt;         /* Dot Number per line to be blitted */
    uint16_t      u16LineCnt;        /* Line Number to be blitted */

} blit_mem_st;

/* Clipping Window Structure */
typedef struct tag_blit_ClipWnd_st
{
    uint32_t       u32ClipAddr;      /* Start Addr.(first dot within C.Wnd) */
    uint16_t       u16Width;         /* Width (nr. of dots in horiz. dir.)  */
    uint16_t       u16Height;        /* Height (nr.of dots in vertic. dir.) */
} blit_ClipWnd_st;

/* RGB/RGBA Operation parameter structure (Overwrite mode) */
typedef struct tag_blit_OvrRgb_st
{
    ga_colFmt_e     eSrcFmt;        /* Source Color format */
    ga_colFmt_e     eDestFmt;       /* Destination Color format */
    ga_en_e         eTranspColEn;   /* Transparency Color Option
                                      (avail. only for 16-bit RGB source) */
    blt_fadeMode_e  eFadeMode;      /* Fading Option */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */

    /* Optional */
    uint8_t         u8FadingFctr;   /* Fading factor */
    uint32_t        u32SrcTransVal; /* Src. Transpar. Pattern (STPR reg.) 
                                       Pattern for comparison of source dots. For 16-bit RGB to 32bit
                                       RGBA conversion, the bits 15:0 are regarded. For 24-bit RGB to
                                       32-bit RGBA conversion, the bits 23:0 are regarded. */    
    uint16_t        u16DstTransVal; /* Dest. Transp. Pattern (DTR reg.) */
    uint8_t         u8SrcAlphaVal;  /* Source Alpha Value */
    uint8_t         u8DstAlphaVal;  /* Destination Alpha Value */
} blit_OvrRgb_st;


/* RLEI Operation parameter structure (Overwrite mode) */
typedef struct tag_blit_OvrRlei_st
{
    blt_rleifmt_rgb_e  eRleiFmt; /* RLE Format of source image */ 
    ga_colFmt_e     eDestFmt;       /* Destination Color format */
    ga_en_e         eTranspColEn;   /* Transparency Color Option */
    blt_fadeMode_e  eFadeMode;      /* Fading Option */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */

    /* Optional */
    uint8_t         u8FadingFctr;   /* Fading factor */
    uint32_t        u32SrcTransVal; /* Src. Transpar. Pattern (STPR reg.) 
                                       Pattern for comparison of source dots. For 16-bit RGB to 32bit
                                       RGBA conversion, the bits 15:0 are regarded. For 24-bit RGB to
                                       32-bit RGBA conversion, the bits 23:0 are regarded.  */    
    uint16_t        u16DstTransVal; /* Dest. Transp. Pattern (DTR reg.) */
    uint8_t         u8SrcAlphaVal;  /* Source Alpha Value */
    uint8_t         u8DstAlphaVal;  /* Destination Alpha Value */
} blit_OvrRlei_st;

/* RLEI24A Operation parameter structure (Overwrite mode) */
typedef struct tag_blit_OvrRleiA_st
{
    blt_rleifmt_rgba_e  eRleiFmt; /* RLE Format of source image */
    ga_colFmt_e     eDestFmt;       /* Destination Color format */
    blt_fadeMode_e  eFadeMode;      /* Fading Option */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */

    /* Optional */
    uint8_t         u8FadingFctr;   /* Fading factor */
    uint8_t         u8SrcAlphaVal;  /* Source Alpha Value */
    uint8_t         u8DstAlphaVal;  /* Destination Alpha Value */
} blit_OvrRleiA_st;


/* RGB Preset Operation parameter structure (Overwrite mode) */
typedef struct tag_blit_OvrRgbP_st
{
    uint32_t        u32Color;       /* Fill Colour (RGB/RGBA format),
                                       depending on eSrcFmt setting */
    ga_colFmt_e     eSrcFmt;        /* Source Color Format */
    blt_fadeMode_e  eFadeMode;      /* Fading Option */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */

    /* Optional */
    uint8_t         u8FadingFctr;   /* Fading factor */
} blit_OvrRgbP_st;


/* RGB/RGBA Operation parameter structure (Blending mode) */
typedef struct tag_blit_BlndRgb_st
{
    ga_colFmt_e     eSrcFmt;        /* Source Color Format */
    ga_colFmt_e     eDestFmt;       /* Destination Color Format */
    ga_en_e         eRedChPrtEn;    /* RED channel Protection enable */
    ga_en_e         eGreenChPrtEn;  /* GREEN channel Protection enable */
    ga_en_e         eBlueChPrtEn;   /* BLUE channel Protection enable */
    ga_en_e         eAlphaChPrtEn;  /* ALPHA channel Protection enable */
    ga_en_e         eRastOpEn;      /* Enabling the Raster Operation */
    ga_en_e         eTranspColEn;   /* Transp. Col. Opt. (only 16-bit src) */
    blt_fadeMode_e  eFadeMode;      /* Fading Option */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */
    ga_blendOrd_e   eBlndOrder;     /* Blending Order */

    /* Optional */
    uint8_t         u8FadingFctr;   /* Fading factor */
    uint32_t        u32SrcTransVal; /* Src. Transpar. Pattern (STPR reg.) 
                                       Pattern for comparison of source dots. For 16-bit RGB to 32bit
                                       RGBA conversion, the bits 15:0 are regarded. For 24-bit RGB to
                                       32-bit RGBA conversion, the bits 23:0 are regarded. */    
    uint16_t        u16DstTransVal; /* Dest. Transp. Pattern (DTR reg.) */
    uint8_t         u8SrcAlphaVal;  /* Source Alpha Value */
    uint8_t         u8DstAlphaVal;  /* Destination Alpha Value */
    blt_rastChSel_e eRastOpMode;    /* Raster Operation Mode */
    blt_rastOpVal_e eRastOpValue;   /* Raster Operation Value */
} blit_BlndRgb_st;

/* Run-Length Encoded 16-bit Operation parameter structure (Blending mode) */
typedef struct tag_blit_BlndRlei_st
{
    blt_rleifmt_rgbx_e eRleiFmt;
    ga_colFmt_e     eDestFmt;       /* Destination Color Format */
    ga_en_e         eRedChPrtEn;    /* RED channel Protection enable */
    ga_en_e         eGreenChPrtEn;  /* GREEN channel Protection enable */
    ga_en_e         eBlueChPrtEn;   /* BLUE channel Protection enable */
    ga_en_e         eAlphaChPrtEn;  /* ALPHA channel Protection enable */
    ga_en_e         eRastOpEn;      /* Enabling the Raster Operation */
    ga_en_e         eTranspColEn;   /* Transp. Col. Opt. (only 16-bit src) */
    blt_fadeMode_e  eFadeMode;      /* Fading Option */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */
    ga_blendOrd_e   eBlndOrder;     /* Blending Order */

    /* Optional */
    uint8_t         u8FadingFctr;   /* Fading factor */
    uint32_t        u32SrcTransVal; /* Src. Transpar. Pattern (STPR reg.) 
                                       Pattern for comparison of source dots. For 16-bit RGB to 32bit
                                       RGBA conversion, the bits 15:0 are regarded. For 24-bit RGB to
                                       32-bit RGBA conversion, the bits 23:0 are regarded. */    
    uint16_t        u16DstTransVal; /* Dest. Transp. Pattern (DTR reg.) */
    uint8_t         u8SrcAlphaVal;  /* Source Alpha Value */
    uint8_t         u8DstAlphaVal;  /* Destination Alpha Value */
    blt_rastChSel_e eRastOpMode;    /* Raster Operation Mode */
    blt_rastOpVal_e eRastOpValue;   /* Raster Operation Value */
} blit_BlndRlei_st;

/* 16-bit Fill Operation parameter structure (Blending mode) */
typedef struct tag_blit_BlndFill16_st
{
    uint16_t        u16Color;        /* Fill Color RGB - format */
    ga_en_e         eRedChPrtEn;    /* RED channel Protection enable */
    ga_en_e         eGreenChPrtEn;  /* GREEN channel Protection enable */
    ga_en_e         eBlueChPrtEn;   /* BLUE channel Protection enable */
    ga_en_e         eRastOpEn;      /* Enabling the Raster Operation */
    ga_blendOrd_e   eBlndOrder;     /* Blending Order */
    blt_fadeMode_e  eFadeMode;      /* Fading Option */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */

    /* Optional */
    uint8_t         u8FadingFctr;   /* Fading factor */
    uint8_t         u8SrcAlphaVal;  /* Source Alpha Value */
    uint8_t         u8DstAlphaVal;  /* Destination Alpha Value */
    blt_rastChSel_e eRastOpMode;    /* Raster Operation Mode */
    blt_rastOpVal_e eRastOpValue;   /* Raster Operation Value */
} blit_BlndFill16_st;

/* 32-bit Fill Operation parameter structure (Blending mode) */
typedef struct tag_blit_BlndFill32_st
{
    uint32_t        u32Color;       /* Fill Color RGBA - format */
    ga_en_e         eRedChPrtEn;    /* RED channel Protection enable */
    ga_en_e         eGreenChPrtEn;  /* GREEN channel Protection enable */
    ga_en_e         eBlueChPrtEn;   /* BLUE channel Protection enable */
    ga_en_e         eAlphaChPrtEn;  /* ALPHA channel Protection enable */
    ga_en_e         eRastOpEn;      /* Enabling the Raster Operation */
    ga_blendOrd_e   eBlndOrder;     /* Blending Order */
    blt_fadeMode_e  eFadeMode;      /* Fading Option */
    ga_en_e         eClipWndEn;     /* Clipping Window Enable */

    /* Optional */
    uint8_t         u8FadingFctr;   /* Fading factor */
    blt_rastChSel_e eRastOpMode;    /* Raster Operation Mode */
    blt_rastOpVal_e eRastOpValue;   /* Raster Operation Value */
} blit_BlndFill32_st;

/*======================================
      Exported Function Prototypes
=======================================*/

/****************************************************************************
 *
 * Function:      vBlit_GetVersion
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
void vBlit_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag);

/*-------------------------------------------------------------------------
|
|                      B A S I C      O P E R A T I O N S
|
 --------------------------------------------------------------------------*/
/****************************************************************************
 *
 * Function:      vBlit_SetClippWnd
 *
 * Purpose:       Sets the Clipping Window (Source/Destination/Size)
 *
 * Inputs:        u32ClipAddr - Start Addr.(first dot within C.Wnd)
 *
 *                usWidth     - Clipping Window Width
 *                              (number of dots in horizontal dir.)
 *
 *                usHeight    - Clipping Window Height
 *                              (number of dots in horizontal dir.)
 *
 *                pstCmdList  - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vBlit_SetClippWnd(uint32_t u32ClipAddr, uint16_t u16Width,
                       uint16_t  u16Height, ga_list_st* pstCmdList);


/*-------------------------------------------------------------------------
|
|                  O V E R W R I T E      O P E R A T I O N S
|
 --------------------------------------------------------------------------*/
/****************************************************************************
 *
 * Function:      vBlit_OverwriteRGB
 *
 * Purpose:       Inserts the set of commands into a command list, which are
 *                necessary for starting an Overwrite function.
 *                In this case the source/destination is of RGB/RGBA type.
 *
 *                The function inserts the commands for necessary registers
 *                initialization and inserts the  appropriate Blit overwrite
 *                command (BLT_ORGB16/BLT_ORGBA32) depending of the source
 *                data format type .
 *
 *                     --------------------------------
 *                    |  Src.\ Dest  | RGBA | RGB |RLE |
 *                    |=================================
 *                    |  32-bit RGBA |  X   |  X  |    |
 *                    |  16-bit RGB  |  X   |  X  |    |
 *                    |  RLE 32      |      |     |    |
 *                    |  RLE 24A     |      |     |    |
 *                    |  RLE 24      |      |     |    |
 *                    |  RLE 16      |      |     |    |
 *                     --------------------------------
 *
 * Inputs:        tMem      - Pointer to the Source/Destination Memory params
 *                            as well as the blitting area size.
 *                            (for more details please see struct desc.)
 *
 *                tParam    - Pointer to Parameter Structure which specifies all requred
 *                            input data for overwrite blitting operation
 *                            (for more details please see struct desc.)
 *
 *                ptCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   The source and destination address alignment rules,
 *                as descirbed in BLT_LOAD_SOURCEADDR/BLT_LOAD_DESTADDR
 *                command description, MUST always be obeyed!!!
 *
 ***************************************************************************/
void vBlit_OverwriteRGB(blit_mem_st* pstMem, blit_OvrRgb_st* pstParam,
                        ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vBlit_OverwriteRLEI_RGB
 *
 * Purpose:       Inserts the commands into command list which are necessary
 *                for starting an Overwrite function where the source is of
 *                run-length encoded 16-bit RGB type while the destination
 *                is either of RGB or RGBA type.
 *
 *                This function inserts the commands for initialization of
 *                all necessary registers and inserts the appropriate Blit
 *                overwrite command.
 *
 *                     ---------------------------------
 *                    |  Src.\ Dest  | RGBA | RGB | RLE |
 *                    |==================================
 *                    |  32-bit RGBA |      |     |     |
 *                    |  16-bit RGB  |      |     |     |
 *                    |  RLE 32      |      |     |     |
 *                    |  RLE 24A     |      |     |     |
 *                    |  RLE 24      |      |     |     |
 *                    |  RLE 16      |  X   |  X  |     |
 *                     ---------------------------------
 *
 * Inputs:        stMem      - Pointer to the Source/Destination Memory params
 *                             as well as the blitting area size.
 *                             (for more details please see struct desc.)
 *
 *                stParam    - Pointer to Parameter Structure which specifies all requred
 *                             input data for overwrite blitting operation
 *                             (for more details please see struct desc.)
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
void vBlit_OverwriteRLEI_RGB(blit_mem_st* pstMem, blit_OvrRlei_st* pstParam,
                             ga_list_st* pstCmdList);


/****************************************************************************
 *
 * Function:      vBlit_OverwriteRLEI_RGBA
 *
 * Purpose:       Inserts the commands into command list which are necessary
 *                for starting an Overwrite function where the source is of
 *                run-length encoded 24-bit RGBA type, while the destination
 *                is stored in RGBA format.
 *
 *                This function inserts the commands for initialization of
 *                all necessary registers and inserts the appropriate Blit
 *                overwrite command.
 *
 *                     ---------------------------------
 *                    |  Src.\ Dest  | RGBA | RGB | RLE |
 *                    |==================================
 *                    |  32-bit RGBA |      |     |     |
 *                    |  16-bit RGB  |      |     |     |
 *                    |  RLE 32      |      |     |     |
 *                    |  RLE 24A     |  X   |  X  |     |
 *                    |  RLE 24      |      |     |     |
 *                    |  RLE 16      |      |     |     |
 *                     ---------------------------------
 *
 * Inputs:        stMem      - Pointer to the Source/Destination Memory params
 *                             as well as the blitting area size.
 *                             (for more details please see struct desc.)
 *
 *                stParam    - Pointer to Parameter Structure which specifies all requred
 *                             input data for overwrite blitting operation
 *                             (for more details please see struct desc.)
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
void vBlit_OverwriteRLEI_RGBA(blit_mem_st* pstMem, blit_OvrRleiA_st* pstParam,
                              ga_list_st* pstCmdList);


/****************************************************************************
 *
 * Function:      vBlit_OverwriteFillRGB
 *
 * Purpose:       Inserts the commands into command list which are necessary
 *                for starting an Overwrite function where the source is in
 *                RGBFP/RGBAFP Register and the destination is in same format.
 *
 *                This is basically the fill function where the FIll Color
 *                is taken from RGBFPReg.
 *
 *                     ---------------------------------
 *                    |  Src.\ Dest  | RGBA | RGB | RLE |
 *                    |==================================
 *                    |  32-bit RGBA |      |     |     |
 *                    |  16-bit RGB  |      |     |     |
 *                    |  RLE 32      |      |     |     |
 *                    |  RLE 16      |      |     |     |
 *                    |  RLE 24A     |      |     |     |
 *                    |  RLE 24      |      |     |     |
 *                    |  RGBFPReg    |      |  X  |     |
 *                    |  RGBAFPReg   |  X   |     |     |
 *                     ---------------------------------
 *
 * Inputs:        stMem      - Pointer to the Source/Destination Memory params
 *                             as well as the blitting area size.
 *                             (for more details please see struct desc.)
 *
 *                stParam    - Pointer to Parameter Structure which specifies all requred
 *                             input data for overwrite filling operation
 *                             (for more details please see struct desc.)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Please notice that the conversion between RGB and RGBA is
 *                not possible. The source format is ALWAYS equal to the
 *                destination format.
 *
 ***************************************************************************/
void vBlit_OverwriteFillRGB(blit_mem_st* pstMem, blit_OvrRgbP_st* pstParam,
                            ga_list_st* pstCmdList);

/*--------------------------------------------------------------------------
|
|                    B L E N D I N G      O P E R A T I O N S
|
 --------------------------------------------------------------------------*/

/****************************************************************************
 *
 * Function:      i32Blit_BlendRGB
 *
 * Purpose:       Inserts the commands into command list which are necessary
 *                for starting an blit blend function where the src/dst. is
 *                of 16/32-bit RGB/RGBA type.
 *
 *
 *                     ----------------------------------
 *                    |  Src.\ Dest  | RGBA | RGB | RLE  |
 *                    |===================================
 *                    |  32-bit RGBA |  X   |  X  |      |
 *                    |  16-bit RGB  |  X   |  X  |      |
 *                    |  RLE 32      |      |     |      |
 *                    |  RLE 24A     |      |     |      |
 *                    |  RLE 24      |      |     |      |
 *                    |  RLE 16      |      |     |      |
 *                     ----------------------------------
 *
 * Inputs:        stMem      - Pointer to the Source/Destination Memory params
 *                             as well as the blitting area size.
 *                             (for more details please see struct desc.)
 *
 *                stParam    - Pointer to Parameter Structure which specifies all requred
 *                             input data for overwrite blitting operation
 *                             (for more details please see struct desc.)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS - All conditions are fulfilled (See. Limitations)
 *                C_FAILED  - All conditions are not met (See. Limitations)
 *
 * Limitations: 1) When Raster Operation is enabled, the Source format MUST
 *                 be the SAME as Destination format. Please have in mind
 *                 that this function will prevent any illegal combination
 *                 to be executed. For this reason, always check the return
 *                 result of this function.
 
 *              2) When Raster Operation is enabled, then the options 
 *                 Transparency Color and Fading will be assumed as disabled and
 *                 the features in pstParam will be ignored.
 *
 *              3) Please note that Alpha Channel Protection value is ONLY
 *                 used when the destination is in 32-bit RGBA format.
 *
 ***************************************************************************/
int32_t i32Blit_BlendRGB(blit_mem_st* pstMem, blit_BlndRgb_st* pstParam,
                         ga_list_st* pstCmdList);
	                        
/****************************************************************************
 *
 * Function:      vBlit_BlendRLEI
 *
 * Purpose:       Inserts the commands into command list which are necessary
 *                for starting an blit blend function where the src is
 *                stored in run-length encoded 16-bit RGB format, while
 *                a destination is stored in 16-bit RGB or 32-bit RGBA
 *                format.
 *
 *                This function inserts the commands for initialization of
 *                all necessary registers and inserts the appropriate Blit
 *                Blend command.
 *
 *                     ----------------------------------
 *                    |  Src.\ Dest  | RGBA | RGB | RLE  |
 *                    |===================================
 *                    |  RLE 32      |  X   |  X  |      |
 *                    |  RLE 24A     |  X   |  X  |      |
 *                    |  RLE 24      |  X   |  X  |      |
 *                    |  RLE 16      |  X   |  X  |      |
 *                     ----------------------------------
 *
 * Inputs:        stMem      - Pointer to the Source/Destination Memory params
 *                             as well as the blitting area size.
 *                             (for more details please see struct desc.)
 *
 *                stParam    - Pointer to Parameter Structure which specifies all requred
 *                             input data for overwrite blitting operation
 *                             (for more details please see struct desc.)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:    When Raster Operation is enabled, then the options Transparency
 *                 Color and Fading will be assumed as disabled and the features 
 *                 in pstParam will be ignored.
 
*
 ***************************************************************************/
void vBlit_BlendRLEI(blit_mem_st* pstMem, blit_BlndRlei_st* pstParam,
                     ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vBlit_BlendFillRGB
 *
 * Purpose:       Inserts the commands into command list which are necessary
 *                for starting an Overwrite function where the source is in
 *                RGBFPReg Register and the destination is in 16-bit RGB
 *                format.
 *
 *                This function inserts the commands for initialization of
 *                all necessary registers and inserts the appropriate Blit
 *                overwrite command.
 *
 *                     ---------------------------------
 *                    |  Src.\ Dest  | RGBA | RGB | RLE |
 *                    |==================================
 *                    |  32-bit RGBA |      |     |     |
 *                    |  16-bit RGB  |      |     |     |
 *                    |  RLE 32      |      |     |     |
 *                    |  RLE 24A     |      |     |     |
 *                    |  RLE 24      |      |     |     |
 *                    |  RLE 16      |      |     |     |
 *                    |  RGBFPReg    |      |  X  |     |
 *                    |  RGBAFPReg   |      |     |     |
 *                     ---------------------------------
 *
 * Inputs:        stMem      - Pointer to the Source/Destination Memory params
 *                             as well as the blitting area size.
 *                            ( for more details please see struct desc.)
 *
 *                stParam    - Pointer to Parameter Structure which specifies all requred
 *                             input data for overwrite filling operation
 *                             (for more details please see struct desc.)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:    When Raster Operation is enabled, then the option Fading
 *                 will be assumed as disabled and the feature in pstParam
 *                 will be ognored. 
 *
 ***************************************************************************/
void vBlit_BlendFillRGB(blit_mem_st* pstMem, blit_BlndFill16_st* pstParam,
                        ga_list_st* pstCmdList);

/****************************************************************************
 *
 * Function:      vBlit_BlendFillRGBA
 *
 * Purpose:       Inserts the commands into command list which are necessary
 *                for starting an Overwrite function where the source is in
 *                RGBAFP Register and the destination is in 32-bit RGBA
 *                format.
 *
 *                This function inserts the commands for initialization of
 *                all necessary registers and inserts the appropriate Blit
 *                overwrite command.
 *
 *                     ---------------------------------
 *                    |  Src.\ Dest  | RGBA | RGB | RLE |
 *                    |==================================
 *                    |  32-bit RGBA |      |     |     |
 *                    |  16-bit RGB  |      |     |     |
 *                    |  RLE 32      |      |     |     |
 *                    |  RLE 24A     |      |     |     |
 *                    |  RLE 24      |      |     |     |
 *                    |  RLE 16      |      |     |     |
 *                    |  RGBFPReg    |      |     |     |
 *                    |  RGBAFPReg   |  X   |     |     |
 *                     ----------------------------------
 *
 * Inputs:        stMem      - Pointer to the Source/Destination Memory params
 *                             as well as the blitting area size.
 *                             (for more details please see struct desc.)
 *
 *                stParam    - Pointer to Parameter Structure which specifies all requred
 *                             input data for overwrite filling operation
 *                             (for more details please see struct desc.)
 *
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:    When Raster Operation is enabled, then then the option Fading
 *                 will be assumed as disabled and this feature in pstParam will
 *                 be ignored. 
 *
 ***************************************************************************/
void vBlit_BlendFillRGBA(blit_mem_st* pstMem, blit_BlndFill32_st* pstParam,
                         ga_list_st* pstCmdList);

/****************************************************************************/
/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/
#endif /* BLIT_H */

/****************************************************************************/


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: blit.h
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

