/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference Interrupt Controller (INTC) Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Interrupt Controller (INTC)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef INTC_H
#define INTC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/

/*********************************************
*        Disable Misra Warnings/Rules        *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
/* disable warnings for nonstandard type for a bit field */
#pragma ghs nowarning 230
#pragma ghs nowarning 79
/* disable MISRA 2004 Rule 10.5 because for satisfaction this rule violation of rule 10.3 is required */
#pragma ghs nowarning 1849
#endif

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_INTC_H_REVISION     "$Revision: 1.12 $"
#define LLDD_INTC_H_TAG          "$Name: LLDD_1_6 $"


/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

/* Number of possible external interrupt source */
#define NUM_EXTERNAL_INT_SOURCES     9U
/* Number of possible internal interrupt source */
#define NUM_INTERNAL_INT_SOURCES     126U
/* Number of reserved interrupt source slots */
#define NUM_RESERVED_INT_SOURCES     57U

/* Total number of interrupt sources */
#define NUM_INT_SOURCES              (NUM_EXTERNAL_INT_SOURCES + NUM_INTERNAL_INT_SOURCES)

/* Maximum number of interrupt sources */
#define NUM_INT_SLOTS                (NUM_INT_SOURCES + NUM_RESERVED_INT_SOURCES)

/* Masks for compacting interrupt source information */
#define INT_VECTOR_MASK              0x000003FFU
#define IR_OFFSET_MASK               0x000000FFU
#define REC_MODE_MASK                0x0000000F
#define LAST_SRC_INDEX               178U

/*********************************************/


/**********************************************
*                    Macros                   *
**********************************************/

/* Extract register offset */
#define INTC_GET_ROFST(val)       (  ((uint32_t)(val)) &  ((uint32_t) IR_OFFSET_MASK ))
/* Compact register offset */
#define INTC_SET_ROFST(val)       ( ((uint32_t)(val)) & ((uint32_t) IR_OFFSET_MASK) )

/* Extract vector offset */
#define INTC_GET_VOFST(val)       ( ( ((uint32_t) (val) ) >> 8 ) & ( (uint32_t) INT_VECTOR_MASK ) )
/* Compact vector offset */
#define INTC_SET_VOFST(val)       ( ( ( (uint32_t) (val) ) & ( (uint32_t) INT_VECTOR_MASK )) << 8)

/* Extract recognition mode */
#define INTC_GET_MODE(val)        (  ( ((uint32_t) (val) ) >> 24 ) & ((uint32_t) REC_MODE_MASK) )
/* Compact recognition mode */
#define INTC_SET_MODE(val)        ( ((uint32_t) (val) ) << 24)

/*
 *  Pack register offset, vector offset
 *  and recognition mode in a single word
 */
#define INTC_CON(roffst, voffst, moffst)    ( INTC_SET_ROFST(roffst) | INTC_SET_VOFST(voffst) | INTC_SET_MODE(moffst) )

/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/

typedef enum tag_intc_enable_e
{
    INTC_DISABLE = 0,                       /* INTC disable */
    INTC_ENABLE  = 1                        /* INTC enable */
} intc_enable_e;

/*
 *  IR[00-47] parameter values
 */

/* IR[xx].EIM - Interrupt recognition mode */
typedef enum tag_intc_eim_e
{
    INTC_LEVEL_LO   = 0,                    /* Low-level active */
    INTC_LEVEL_HI   = 1,                    /* High-level active */
    INTC_EDGE_FALL  = 2,                    /* Falling-edge */
    INTC_EDGE_RISE  = 3,                    /* Rising-edge */
    INTC_RM_CONFIG  = 4,                    /* configurable recognition mode */
    INTC_RM_DEFAULT = 5,                    /* default recognition mode */
    INTC_NA         = 6                     /* NA for check */
} intc_eim_e;

/* IR[xx].DRS - Interrupt redirect selection */
typedef enum tag_intc_drs_e
{
    INTC_TO_CPU = 0,                        /* IRQ will be carried to the CPU */
    INTC_TO_DMA = 1                         /* IRQ used as request for DMA */
} intc_drs_e;

/* IR[xx].ACLR - Interrupt auto clearing */
typedef enum tag_intc_aclr_e
{
    INTC_AUTO_CLEAR_DISABLE = 0,            /* IRQ will be carried to the CPU */
    INTC_AUTO_CLEAR_ENABLE  = 1             /* IRQ used as request for DMA */
} intc_aclr_e;

/* IR[xx].EXT - Priority of the interrupt source (DRS == 0) / DMA channel (DRS == 1) */
typedef enum tag_intc_ext_e
{
    INTC_LEVEL_0 = 0,                       /* Priority level 0 [disabled] / DMA Channel 0 */
    INTC_LEVEL_1 = 1,                       /* Priority level 1 [lowest]   / DMA Channel 1 */
    INTC_LEVEL_2 = 2,                       /* Priority level 2            / DMA Channel 2 */
    INTC_LEVEL_3 = 3,                       /* Priority level 3            / DMA Channel 3 */
    INTC_LEVEL_4 = 4,                       /* Priority level 4            / DMA Channel 4 */
    INTC_LEVEL_5 = 5,                       /* Priority level 5            / DMA Channel 5 */
    INTC_LEVEL_6 = 6,                       /* Priority level 6            / DMA Channel 6 */
    INTC_LEVEL_7 = 7                        /* Priority level 7 [highest]  / DMA Channel 7 */
} intc_ext_e;

/* *** */

/*
 *  Word compacting:
 *      - interrupt register number (not offset)
 *      - interrupt vector offset
 *      - default recognition mode
 */
typedef enum tag_intc_src_e
{
    INTC_DUMMY_0       = INTC_CON(  0, 0x000, INTC_NA),

    INTC_EXTINT0       = INTC_CON(  1, 0x004, INTC_RM_CONFIG),
    INTC_EXTINT1       = INTC_CON(  2, 0x008, INTC_RM_CONFIG),
    INTC_EXTINT2       = INTC_CON(  3, 0x00C, INTC_RM_CONFIG),
    INTC_EXTINT3       = INTC_CON(  4, 0x010, INTC_RM_CONFIG),
    INTC_EXTINT4       = INTC_CON(  5, 0x014, INTC_RM_CONFIG),
    INTC_EXTINT5       = INTC_CON(  6, 0x018, INTC_RM_CONFIG),

    INTC_DUMMY_1       = INTC_CON(  7, 0x01C, INTC_NA),
    INTC_DUMMY_2       = INTC_CON(  8, 0x020, INTC_NA),
    INTC_DUMMY_3       = INTC_CON(  9, 0x024, INTC_NA),
    INTC_DUMMY_4       = INTC_CON( 10, 0x028, INTC_NA),
    INTC_DUMMY_5       = INTC_CON( 11, 0x02C, INTC_NA),
    INTC_DUMMY_6       = INTC_CON( 12, 0x030, INTC_NA),
    INTC_DUMMY_7       = INTC_CON( 13, 0x034, INTC_NA),
    INTC_DUMMY_8       = INTC_CON( 14, 0x038, INTC_NA),

    INTC_WDT           = INTC_CON( 15, 0x03C, INTC_EDGE_RISE),

    INTC_DUMMY_9       = INTC_CON( 16, 0x040, INTC_NA),

    INTC_ECCSRAM       = INTC_CON( 17, 0x044, INTC_LEVEL_HI),
    INTC_DUMMY_10      = INTC_CON( 18, 0x048, INTC_NA),
    INTC_ECCBAKRAM     = INTC_CON( 19, 0x04C, INTC_LEVEL_HI),

    INTC_GAMPI         = INTC_CON( 20, 0x050, INTC_LEVEL_HI),

    INTC_PINMUX        = INTC_CON( 21, 0x054, INTC_EDGE_RISE),

    INTC_IRC           = INTC_CON( 22, 0x058, INTC_LEVEL_HI),

    INTC_TSMRXFIFO     = INTC_CON( 23, 0x05C, INTC_EDGE_RISE),
    INTC_TSMTXFIFO     = INTC_CON( 24, 0x060, INTC_EDGE_RISE),
    INTC_TSMAPERC      = INTC_CON( 25, 0x064, INTC_LEVEL_HI),
    INTC_TSMERCBUSY    = INTC_CON( 26, 0x068, INTC_EDGE_RISE),
    INTC_TSMFW         = INTC_CON( 27, 0x06C, INTC_EDGE_RISE),

    INTC_SYSC          = INTC_CON( 28, 0x070, INTC_LEVEL_HI),

    INTC_RTC           = INTC_CON( 29, 0x074, INTC_EDGE_RISE),

    INTC_APC0          = INTC_CON( 30, 0x078, INTC_LEVEL_HI),
    INTC_APC1          = INTC_CON( 31, 0x07C, INTC_LEVEL_HI),

    INTC_QSPI0         = INTC_CON( 32, 0x080, INTC_LEVEL_HI),
    INTC_QSPI1         = INTC_CON( 33, 0x084, INTC_LEVEL_HI),
    INTC_QSPI2         = INTC_CON( 34, 0x088, INTC_LEVEL_HI),

    INTC_PARFLINT      = INTC_CON( 35, 0x08C, INTC_LEVEL_HI),
    INTC_PARFLINT0     = INTC_CON( 36, 0x090, INTC_LEVEL_HI),
    INTC_PARFLINT1     = INTC_CON( 37, 0x094, INTC_LEVEL_HI),
    INTC_PARFLECCINT   = INTC_CON( 38, 0x098, INTC_LEVEL_HI),

    INTC_DUMMY_11      = INTC_CON( 39, 0x09C, INTC_NA),
    INTC_DUMMY_12      = INTC_CON( 40, 0x0A0, INTC_NA),

    INTC_SMC           = INTC_CON( 41, 0x0A4, INTC_EDGE_RISE),

    INTC_DUMMY_13      = INTC_CON( 42, 0x0A8, INTC_NA),
    INTC_DUMMY_14      = INTC_CON( 43, 0x0AC, INTC_NA),
    INTC_DUMMY_15      = INTC_CON( 44, 0x0B0, INTC_NA),

    INTC_GDC0          = INTC_CON( 45, 0x0B4, INTC_LEVEL_HI),
    INTC_GDC1          = INTC_CON( 46, 0x0B8, INTC_LEVEL_HI),

    INTC_FG            = INTC_CON( 47, 0x0BC, INTC_LEVEL_HI),

    INTC_GA            = INTC_CON( 48, 0x0C0, INTC_LEVEL_HI),

    INTC_PNGGIR        = INTC_CON( 49, 0x0C4, INTC_RM_CONFIG),
    INTC_PNGSIR0       = INTC_CON( 50, 0x0C8, INTC_RM_CONFIG),
    INTC_PNGSIR1       = INTC_CON( 51, 0x0CC, INTC_RM_CONFIG),
    INTC_PNGSIR2       = INTC_CON( 52, 0x0D0, INTC_RM_CONFIG),
    INTC_PNGSIR3       = INTC_CON( 53, 0x0D4, INTC_RM_CONFIG),
    INTC_PNGSIR4       = INTC_CON( 54, 0x0D8, INTC_RM_CONFIG),
    INTC_PNGSIR5       = INTC_CON( 55, 0x0DC, INTC_RM_CONFIG),
    INTC_PNGSIR6       = INTC_CON( 56, 0x0E0, INTC_RM_CONFIG),
    INTC_PNGSIR7       = INTC_CON( 57, 0x0E4, INTC_RM_CONFIG),

    INTC_MLBSYS        = INTC_CON( 58, 0x0E8, INTC_LEVEL_HI),
    INTC_MLBCHAN       = INTC_CON( 59, 0x0EC, INTC_LEVEL_HI),
    INTC_MLBDCHAN0     = INTC_CON( 60, 0x0F0, INTC_EDGE_RISE),
    INTC_MLBDCHAN1     = INTC_CON( 61, 0x0F4, INTC_EDGE_RISE),
    INTC_MLBDCHAN2     = INTC_CON( 62, 0x0F8, INTC_EDGE_RISE),
    INTC_MLBDCHAN3     = INTC_CON( 63, 0x0FC, INTC_EDGE_RISE),
    INTC_MLBDCHAN4     = INTC_CON( 64, 0x100, INTC_EDGE_RISE),
    INTC_MLBDCHAN5     = INTC_CON( 65, 0x104, INTC_EDGE_RISE),

    INTC_I2S0          = INTC_CON( 66, 0x108, INTC_LEVEL_HI),
    INTC_I2S1          = INTC_CON( 67, 0x10C, INTC_LEVEL_HI),

    INTC_TIM0_MAVAL0   = INTC_CON( 68, 0x110, INTC_EDGE_FALL),
    INTC_TIM0_MAVAL1   = INTC_CON( 69, 0x114, INTC_EDGE_FALL),
    INTC_TIM0_CMPVAL0  = INTC_CON( 70, 0x118, INTC_EDGE_FALL),
    INTC_TIM0_CMPVAL1  = INTC_CON( 71, 0x11C, INTC_EDGE_FALL),
    INTC_TIM1_MAVAL0   = INTC_CON( 72, 0x120, INTC_EDGE_FALL),
    INTC_TIM1_MAVAL1   = INTC_CON( 73, 0x124, INTC_EDGE_FALL),
    INTC_TIM1_CMPVAL0  = INTC_CON( 74, 0x128, INTC_EDGE_FALL),
    INTC_TIM1_CMPVAL1  = INTC_CON( 75, 0x12C, INTC_EDGE_FALL),
    INTC_TIM2_MAVAL0   = INTC_CON( 76, 0x130, INTC_EDGE_FALL),
    INTC_TIM2_MAVAL1   = INTC_CON( 77, 0x134, INTC_EDGE_FALL),
    INTC_TIM2_CMPVAL0  = INTC_CON( 78, 0x138, INTC_EDGE_FALL),
    INTC_TIM2_CMPVAL1  = INTC_CON( 79, 0x13C, INTC_EDGE_FALL),
    INTC_TIM3_MAVAL0   = INTC_CON( 80, 0x140, INTC_EDGE_FALL),
    INTC_TIM3_MAVAL1   = INTC_CON( 81, 0x144, INTC_EDGE_FALL),
    INTC_TIM3_CMPVAL0  = INTC_CON( 82, 0x148, INTC_EDGE_FALL),
    INTC_TIM3_CMPVAL1  = INTC_CON( 83, 0x14C, INTC_EDGE_FALL),
    INTC_TIM4_MAVAL0   = INTC_CON( 84, 0x150, INTC_EDGE_FALL),
    INTC_TIM4_MAVAL1   = INTC_CON( 85, 0x154, INTC_EDGE_FALL),
    INTC_TIM4_CMPVAL0  = INTC_CON( 86, 0x158, INTC_EDGE_FALL),
    INTC_TIM4_CMPVAL1  = INTC_CON( 87, 0x15C, INTC_EDGE_FALL),
    INTC_TIM5_MAVAL0   = INTC_CON( 88, 0x160, INTC_EDGE_FALL),
    INTC_TIM5_MAVAL1   = INTC_CON( 89, 0x164, INTC_EDGE_FALL),
    INTC_TIM5_CMPVAL0  = INTC_CON( 90, 0x168, INTC_EDGE_FALL),
    INTC_TIM5_CMPVAL1  = INTC_CON( 91, 0x16C, INTC_EDGE_FALL),
    INTC_TIM6_MAVAL0   = INTC_CON( 92, 0x170, INTC_EDGE_FALL),
    INTC_TIM6_MAVAL1   = INTC_CON( 93, 0x174, INTC_EDGE_FALL),
    INTC_TIM6_CMPVAL0  = INTC_CON( 94, 0x178, INTC_EDGE_FALL),
    INTC_TIM6_CMPVAL1  = INTC_CON( 95, 0x17C, INTC_EDGE_FALL),
    INTC_TIM7_MAVAL0   = INTC_CON( 96, 0x180, INTC_EDGE_FALL),
    INTC_TIM7_MAVAL1   = INTC_CON( 97, 0x184, INTC_EDGE_FALL),
    INTC_TIM7_CMPVAL0  = INTC_CON( 98, 0x188, INTC_EDGE_FALL),
    INTC_TIM7_CMPVAL1  = INTC_CON( 99, 0x18C, INTC_EDGE_FALL),
    INTC_TIM8_MAVAL0   = INTC_CON(100, 0x190, INTC_EDGE_FALL),
    INTC_TIM8_MAVAL1   = INTC_CON(101, 0x194, INTC_EDGE_FALL),
    INTC_TIM8_CMPVAL0  = INTC_CON(102, 0x198, INTC_EDGE_FALL),
    INTC_TIM8_CMPVAL1  = INTC_CON(103, 0x19C, INTC_EDGE_FALL),
    INTC_TIM9_MAVAL0   = INTC_CON(104, 0x1A0, INTC_EDGE_FALL),
    INTC_TIM9_MAVAL1   = INTC_CON(105, 0x1A4, INTC_EDGE_FALL),
    INTC_TIM9_CMPVAL0  = INTC_CON(106, 0x1A8, INTC_EDGE_FALL),
    INTC_TIM9_CMPVAL1  = INTC_CON(107, 0x1AC, INTC_EDGE_FALL),

    INTC_DMACINTR      = INTC_CON(108, 0x1B0, INTC_LEVEL_HI),

    INTC_ESEI_CH0_RX   = INTC_CON(109, 0x1B4, INTC_LEVEL_HI),
    INTC_ESEI_CH0_TX   = INTC_CON(110, 0x1B8, INTC_LEVEL_HI),
    INTC_ESEI_CH0_ST   = INTC_CON(111, 0x1BC, INTC_LEVEL_HI),
    INTC_ESEI_CH1_RX   = INTC_CON(112, 0x1C0, INTC_LEVEL_HI),
    INTC_ESEI_CH1_TX   = INTC_CON(113, 0x1C4, INTC_LEVEL_HI),
    INTC_ESEI_CH1_ST   = INTC_CON(114, 0x1C8, INTC_LEVEL_HI),

    INTC_TXCAN_CH0_RX  = INTC_CON(115, 0x1CC, INTC_LEVEL_HI),
    INTC_TXCAN_CH0_TX  = INTC_CON(116, 0x1D0, INTC_LEVEL_HI),
    INTC_TXCAN_CH0_ST  = INTC_CON(117, 0x1D4, INTC_LEVEL_HI),
    INTC_TXCAN_CH1_RX  = INTC_CON(118, 0x1D8, INTC_LEVEL_HI),
    INTC_TXCAN_CH1_TX  = INTC_CON(119, 0x1DC, INTC_LEVEL_HI),
    INTC_TXCAN_CH1_ST  = INTC_CON(120, 0x1E0, INTC_LEVEL_HI),
    INTC_TXCAN_CH2_RX  = INTC_CON(121, 0x1E4, INTC_LEVEL_HI),
    INTC_TXCAN_CH2_TX  = INTC_CON(122, 0x1E8, INTC_LEVEL_HI),
    INTC_TXCAN_CH2_ST  = INTC_CON(123, 0x1EC, INTC_LEVEL_HI),

    INTC_I2C           = INTC_CON(124, 0x1F0, INTC_EDGE_FALL),

    INTC_HSUART0_TX    = INTC_CON(125, 0x1F4, INTC_LEVEL_LO),
    INTC_HSUART0_RX    = INTC_CON(126, 0x1F8, INTC_LEVEL_LO),
    INTC_HSUART0_ST    = INTC_CON(127, 0x1FC, INTC_LEVEL_LO),
    INTC_HSUART1_TX    = INTC_CON(128, 0x200, INTC_LEVEL_LO),
    INTC_HSUART1_RX    = INTC_CON(129, 0x204, INTC_LEVEL_LO),
    INTC_HSUART1_ST    = INTC_CON(130, 0x208, INTC_LEVEL_LO),

    INTC_BCTRL_TOEC    = INTC_CON(131, 0x20C, INTC_LEVEL_HI),
    INTC_BCTRL_DS      = INTC_CON(132, 0x210, INTC_LEVEL_HI),
    INTC_BCFG0_TOEC    = INTC_CON(133, 0x214, INTC_LEVEL_HI),
    INTC_BCFG0_DS      = INTC_CON(134, 0x218, INTC_LEVEL_HI),
    INTC_BCFG1_TOEC    = INTC_CON(135, 0x21C, INTC_LEVEL_HI),
    INTC_BCFG1_DS      = INTC_CON(136, 0x220, INTC_LEVEL_HI),
    INTC_BPERIM_TOEC   = INTC_CON(137, 0x224, INTC_LEVEL_HI),
    INTC_BPERIM_DS     = INTC_CON(138, 0x228, INTC_LEVEL_HI),
    INTC_BPERINM_TOEC  = INTC_CON(139, 0x22C, INTC_LEVEL_HI),
    INTC_BPERINM_DS    = INTC_CON(140, 0x230, INTC_LEVEL_HI),
    INTC_BCFG0_GS_TOEC = INTC_CON(141, 0x234, INTC_LEVEL_HI),
    INTC_BCFG0_GS_DS   = INTC_CON(142, 0x238, INTC_LEVEL_HI),
    INTC_BCFG1_GS_TOEC = INTC_CON(143, 0x23C, INTC_LEVEL_HI),
    INTC_BCFG1_GS_DS   = INTC_CON(144, 0x240, INTC_LEVEL_HI),

    INTC_PWMT0         = INTC_CON(145, 0x244, INTC_EDGE_FALL),
    INTC_PWMT1         = INTC_CON(146, 0x248, INTC_EDGE_FALL),
    INTC_PWMT2         = INTC_CON(147, 0x24C, INTC_EDGE_FALL),
    INTC_PWMT3         = INTC_CON(148, 0x250, INTC_EDGE_FALL),
    INTC_PWMT4         = INTC_CON(149, 0x254, INTC_EDGE_FALL),
    INTC_PWMT5         = INTC_CON(150, 0x258, INTC_EDGE_FALL),
    INTC_PWMT6         = INTC_CON(151, 0x25C, INTC_EDGE_FALL),
    INTC_PWMT7         = INTC_CON(152, 0x260, INTC_EDGE_FALL),
    INTC_PWMT8         = INTC_CON(153, 0x264, INTC_EDGE_FALL),
    INTC_PWMT9         = INTC_CON(154, 0x268, INTC_EDGE_FALL),
    INTC_PWMT10        = INTC_CON(155, 0x26C, INTC_EDGE_FALL),
    INTC_PWMT11        = INTC_CON(156, 0x270, INTC_EDGE_FALL),
    INTC_PWMT12        = INTC_CON(157, 0x274, INTC_EDGE_FALL),
    INTC_PWMT13        = INTC_CON(158, 0x278, INTC_EDGE_FALL),
    INTC_PWMT14        = INTC_CON(159, 0x27C, INTC_EDGE_FALL),
    INTC_PWMT15        = INTC_CON(160, 0x280, INTC_EDGE_FALL),
    INTC_PWMT16        = INTC_CON(161, 0x284, INTC_EDGE_FALL),
    INTC_PWMT17        = INTC_CON(162, 0x288, INTC_EDGE_FALL),
    INTC_PWMT18        = INTC_CON(163, 0x28C, INTC_EDGE_FALL),
    INTC_PWMT19        = INTC_CON(164, 0x290, INTC_EDGE_FALL),
    INTC_PWMT20        = INTC_CON(165, 0x294, INTC_EDGE_FALL),
    INTC_PWMT21        = INTC_CON(166, 0x298, INTC_EDGE_FALL),
    INTC_PWMT22        = INTC_CON(167, 0x29C, INTC_EDGE_FALL),
    INTC_PWMT23        = INTC_CON(168, 0x2A0, INTC_EDGE_FALL),

    INTC_GPWMT0        = INTC_CON(169, 0x2A4, INTC_EDGE_FALL),
    INTC_GPWMT1        = INTC_CON(170, 0x2A8, INTC_EDGE_FALL),

    INTC_HSPWMT0       = INTC_CON(171, 0x2AC, INTC_EDGE_FALL),
    INTC_HSPWMT1       = INTC_CON(172, 0x2B0, INTC_EDGE_FALL),
    INTC_HSPWMT2       = INTC_CON(173, 0x2B4, INTC_EDGE_FALL),
    INTC_HSPWMT3       = INTC_CON(174, 0x2B8, INTC_EDGE_FALL),

    INTC_ADC_CC        = INTC_CON(175, 0x2BC, INTC_EDGE_RISE),
    INTC_ADC_HP        = INTC_CON(176, 0x2C0, INTC_EDGE_RISE),
    INTC_ADC_COM       = INTC_CON(177, 0x2C4, INTC_LEVEL_HI),

    INTC_WAKEUP        = INTC_CON(178, 0x2C8, INTC_RM_CONFIG)
} intc_src_e;

/*
 *  IRST parameter values
 */

/* IRST.RDR[x] - Clear DMA Request channel */
typedef enum tag_intc_req_e
{
    INTC_DMA_CH0 = 0,                            /* Clear DMA request to channel 0 */
    INTC_DMA_CH1 = 1,                            /* Clear DMA request to channel 1 */
    INTC_DMA_CH2 = 2,                           /* Clear DMA request to channel 2 */
    INTC_DMA_CH3 = 3,                           /* Clear DMA request to channel 3 */
    INTC_DMA_CH4 = 4,                           /* Clear DMA request to channel 4 */
    INTC_DMA_CH5 = 5,                           /* Clear DMA request to channel 5 */
    INTC_DMA_CH6 = 6,                           /* Clear DMA request to channel 6 */
    INTC_DMA_CH7 = 7,                           /* Clear DMA request to channel 7 */
    INTC_DMA_CH_ALL = 0xFF                  /* Clear all requests */
} intc_irst_e;


/*
 *  ILEV parameter values
 */

/* ILEV.MLEV - modify interrupt level */
typedef enum tag_intc_ilev_e
{
    INTC_RESTORE_OLD = 0,                   /* Restore old interrupt level */
    INTC_MODIFY_CURR                        /* Modify current interrupt level */
} intc_ilev_e;

/* ILEV.PMASK/ILEV.CMAKS - interruüpt levels */
typedef enum tag_intc_level_e
{
    INTC_CURRENT = 0,                       /* Current IRQ level */
    INTC_PREV0,                             /* Previous [0]  IRQ level */
    INTC_PREV1,
    INTC_PREV2,
    INTC_PREV3,
    INTC_PREV4,
    INTC_PREV5                              /* Previous [5] IRQ level */
} intc_level_e;

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vINTC_GetVersion
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
void vINTC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      vSetIR_EXT_ByIndex
 *
 * Purpose:       Set bit fields EXT in IR register for a specific channel
 *
 * Inputs:        u8SrcIx     0 to LAST_SRC_INDEX
 *                u8EXT       value of EXT
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vSetIR_EXT_ByIndex (uint8_t u8SrcIx, uint8_t u8EXT);

/****************************************************************************
 *
 * Function:      vSetIR_DRS_ByIndex
 *
 * Purpose:       Set bit fields DRS in IR register for a specific channel
 *
 * Inputs:        u8SrcIx     0 to LAST_SRC_INDEX
 *                u8DRS       value of DRS
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vSetIR_DRS_ByIndex (uint8_t u8SrcIx, uint8_t u8DRS);


/****************************************************************************
 *
 * Function:      vSetIR_EIM_ByIndex
 *
 * Purpose:       Set bit fields EIM in IR register for a specific channel
 *
 * Inputs:        u8SrcIx     0 to LAST_SRC_INDEX
 *                u8EIM       value of EIM
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vSetIR_EIM_ByIndex (uint8_t u8SrcIx, uint8_t u8EIM);


/****************************************************************************
 *
 * Function:      vSetIR_ACLR_ByIndex
 *
 * Purpose:       Set bit fields ACLR in IR register for a specific channel
 *
 * Inputs:        u8SrcIx     0 to LAST_SRC_INDEX
 *                u8ACLR      value of ACLR
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vSetIR_ACLR_ByIndex(uint8_t u8SrcIx, uint8_t u8ACLR);


/****************************************************************************
 *
 * Function:      vSetIR_ByIndex
 *
 * Purpose:       Set IR register with bit fields EXT, DRS, EIM and ACLR for a 
 *                specific channel
 *
 * Inputs:        u8SrcIx          0 to LAST_SRC_INDEX
 *                u8Value_write    value of EXT
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vSetIR_ByIndex (uint8_t u8SrcIx, uint8_t u8Value_write);


/****************************************************************************
 *
 * Function:      i32INTC_SourceConfig
 *
 * Purpose:       Configure each interrupt source in the INTC
 *
 * Inputs:        eSrc        Interrupt source
 *                eMode       Recognition mode. Please note that if
 *                            INTC_DEFAULT is specified then the it
 *                            is set to the default value for the
 *                            selected module [source]
 *                eDst        Specifies where IRQ request will be routed
 *                            [CPU/DMA/MeP]
 *                eLevel      If the request is routed to the CPU, it
 *                            specifies the priority level, otherwise
 *                            specifies the DMA channel
 *                eAutoClear  Specifies for edge sensitive interrupts
 *                            if the interrupt is cleared automatically
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on sucess
 *                C_FAILED on invalid parameters [out of range or not
 *                supported values]. The opeartion will be aborted at
 *                the point of detection, thus some values may not be
 *                set
 *
 * Limitations:   INTC_RM_DEFAULT recognition mode cannot be used for
 *                external interrupt sources (INTC_EINT[0-8]). In such
 *                cases the routine will return C_FAILED and will not
 *                set any value
 *
 *                When routing the IRQ request to DMA the eLevel shall
 *                specify the DMA channel number (0 .. 7). In such cases
 *                the routine will return C_FAILED and will not set any
 *                value
 *
 ***************************************************************************/
int32_t i32INTC_SourceConfig(intc_src_e eSrc, intc_drs_e eDst, intc_eim_e eMode, intc_ext_e eLevel, intc_aclr_e eAutoClear);


/****************************************************************************
 *
 * Function:      i32INTC_SetEIM_ByIndex
 *
 * Purpose:       Configure interrupt bits EIM by an source Index
 *
 * Inputs:        u8SrcIx     0 to LAST_SRC_INDEX
 *                eMode       Recognition mode. Please note that only
 *                            following values can be set:
 *                            INTC_LEVEL_LO, , INTC_LEVEL_HI, INTC_EDGE_FALL
 *                            or INTC_EDGE_RISE
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on sucess
 *                C_FAILED on invalid parameters [out of range or not
 *                supported values].
 *
 * Limitations:   INTC_RM_DEFAULT recognition mode cannot be used for
 *                external interrupt sources (INTC_EINT[0-8]). In such
 *                cases the routine will return C_FAILED and will not
 *                set any value
 *
 ***************************************************************************/
int32_t i32INTC_SetEIM_ByIndex(uint8_t u8SrcIx, intc_eim_e eMode);


/****************************************************************************
 *
 * Function:      i32INTC_SetDrsByIndex
 *
 * Purpose:       Configure interrupt bits DRS by an source Index
 *
 * Inputs:        u8SrcIx     0 to LAST_SRC_INDEX
 *                eDst        Specifies where IRQ request will be routed
 *                            [CPU/DMA/MeP]
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on sucess
 *                C_FAILED on invalid parameters [out of range or not
 *                supported values].
 *
 * Limitations:   INTC_RM_DEFAULT recognition mode cannot be used for
 *                external interrupt sources (INTC_EINT[0-8]). In such
 *                cases the routine will return C_FAILED and will not
 *                set any value
 *
 ***************************************************************************/
int32_t i32INTC_SetDrsByIndex(uint8_t u8SrcIx, intc_drs_e eDst);


/****************************************************************************
 *
 * Function:      i32INTC_SetExtByIndex
 *
 * Purpose:       Configure interrupt bits EXT by an source Index
 *
 * Inputs:        u8SrcIx     0 to LAST_SRC_INDEX
 *                eLevel      If the request is routed to the CPU, it
 *                            specifies the priority level, otherwise
 *                            specifies the DMA channel
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on sucess
 *                C_FAILED on invalid parameters [out of range or not
 *                supported values].
 *
 * Limitations:   INTC_RM_DEFAULT recognition mode cannot be used for
 *                external interrupt sources (INTC_EINT[0-8]). In such
 *                cases the routine will return C_FAILED and will not
 *                set any value
 *
 ***************************************************************************/
int32_t i32INTC_SetExtByIndex(uint8_t u8SrcIx, intc_ext_e eLevel);


/****************************************************************************
 *
 * Function:      i32INTC_SetAclrByIndex
 *
 * Purpose:       Configure interrupt bits ACRL by an source Index
 *
 * Inputs:        u8SrcIx     0 to LAST_SRC_INDEX
 *                eAutoClear  Specifies for edge sensitive interrupts
 *                            if the interrupt is cleared automatically
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on sucess
 *                C_FAILED on invalid parameters [out of range or not
 *                supported values].
 *
 * Limitations:   INTC_RM_DEFAULT recognition mode cannot be used for
 *                external interrupt sources (INTC_EINT[0-8]). In such
 *                cases the routine will return C_FAILED and will not
 *                set any value
 *
 ***************************************************************************/
int32_t i32INTC_SetAclrByIndex(uint8_t u8SrcIx, intc_aclr_e eAutoClear);


/****************************************************************************
 *
 * Function:      i32INTC_SetVectBaseAddr
 *
 * Purpose:       Configure the vector base address
 *
 * Inputs:        uiAddr  Virtual vector base address (1024-bytes aligned)
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on sucess
 *                C_FAILED if address is not aligned
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32INTC_SetVectBaseAddr(uint32_t u32Addr);


/****************************************************************************
 *
 * Function:      u32INTC_GetVectAddr
 *
 * Purpose:       Retrieve the vector offset of the currently pending interrupt
 *                with the highest priority level
 *
 * Inputs:        none
 *
 * Outputs:       Interrupt vector address, relevant to the entry made in IVR
 *
 * Return Values: none
 *
 * Limitations:   Vector base [BVA bits] must be set in advance, otherwise the
 *                the vector address may be invalid
 *
 ***************************************************************************/
uint32_t u32INTC_GetVectAddr(void);


/****************************************************************************
 *
 * Function:      vINTC_ModifyIrqLevel
 *
 * Purpose:       Modify the masked interrupt level
 *
 * Inputs:        eMode  Specifies whether interrupt level
 *                       will be modified or the old one
 *                       shall be restored
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vINTC_ModifyIrqLevel(intc_ilev_e eMode, intc_ext_e eLevel);


/****************************************************************************
 *
 * Function:      i32INTC_ClearIrq
 *
 * Purpose:       Clear interrupt source
 *
 * Inputs:        uiVoffset  Vector offset address of the interrupt
 *                           source to be cleared. Internal filtering
 *                           is always applied, so the return value of
 *                           u32INTC_GetVectAddr or inc_voffset_e
 *                           constant can be directly used
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on sucess
 *                C_FAILED if vector offset address is not valid
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32INTC_ClearIrq(uint32_t u32Voffset);


/****************************************************************************
 *
 * Function:      vINTC_ClearDmaReq
 *
 * Purpose:       Clear DMA request
 *
 * Inputs:        eReqCh  DMA channel reqest to be cleared
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vINTC_ClearDmaReq(intc_irst_e eReqCh);


/****************************************************************************
 *
 * Function:      vINTC_BlockVectUpdate
 *
 * Purpose:       Protect the IVR against updates from higher priority
 *                interrupts
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vINTC_BlockVectUpdate(void);


/****************************************************************************
 *
 * Function:      u8INTC_GetIrqLevel
 *
 * Purpose:       Retrieve nested interrupt level
 *
 *
 * Inputs:        eLevel  Nested interrupt level, whose priority should
 *                        be retrieved
 *
 * Outputs:       The priority of the requested level
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8INTC_GetIrqLevel(intc_level_e eLevel);


/****************************************************************************
 *
 * Function:      u32INTC_GetIrqStatus
 *
 * Purpose:       Retrieve interrupt request status
 *
 *
 * Inputs:        eSrc  Interrupt source
 *
 * Outputs:       0 - not pending
 *                1 - interrupt requested
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32INTC_GetIrqStatus(intc_src_e eSrc);


/****************************************************************************
 *
 * Function:      vINTC_EnableInterrupts
 *
 * Purpose:       Enable interrupts
 *
 *
 * Inputs:        eEnable  INTC_DISABLE or INTC_ENABLE
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vINTC_EnableInterrupts(intc_enable_e eEnable);


/****************************************************************************
 *
 * Function:      eINTC_GetEnabled
 *
 * Purpose:       returns interrupts status
 *
 *
 * Inputs:        none
 *
 * Outputs:       INTC_DISABLE or INTC_ENABLE
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
intc_enable_e eINTC_GetEnabled( void );


/****************************************************************************
 *
 * Function:      vINTC_ClearInterrupt
 *
 * Purpose:       Clear interrupts
 *
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vINTC_ClearInterrupt(void);


/****************************************************************************
 *
 * Function:      vINTC_SetISRStartAddress
 *
 * Purpose:       Set ISR start address
 *
 *
 * Inputs:        eSrc        Interrupt source
 *                u32Address  ISR start address
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vINTC_SetISRStartAddress(intc_src_e eSrc, uint32_t u32Address);


/****************************************************************************
 *
 * Function:      u32INTC_GetISRStartAddress
 *
 * Purpose:       Get ISR start address
 *
 *
 * Inputs:        eSrc  Interrupt source
 *
 * Outputs:       ISR start address
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32INTC_GetISRStartAddress(intc_src_e eSrc);


#if defined(__GHS__) || defined(__ghs__)
/* enable warnings 230 and 79 for nonstandard type for a bit field */
#pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

#endif /* _INTC_H */

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

