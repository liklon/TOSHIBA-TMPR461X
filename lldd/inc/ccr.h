/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : CCR Low-level register
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : CCR
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.22 $
*   DATE        : $Date: 2015/05/18 13:49:55 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef CCR_LLDD_H
#define CCR_LLDD_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_CCR_H_REVISION     "$Revision: 1.22 $"
#define LLDD_CCR_H_TAG          "$Name: LLDD_1_6 $"

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1862  /* Rule 19.7 : disable function-like macro not allowed */
#endif
/*********************************************/

/**********************************************
*                    Macros                   *
**********************************************/
/* CCR unlock key value */
#define CCR_KEY_VAL 0xA5C0F17BU

/* CCR PDS unlock macro */
#define vCCR_PDS_UNLOCK()(vSetCCR_KEYR_KEYVAL(CCR_KEY_VAL))

/* CCR PDH unlock macro */
#define vCCR_PDH_UNLOCK()(vSetPDHR_KEYR_KEYVAL(CCR_KEY_VAL))

/**********************************************
*               Enumerations                  *
**********************************************/
typedef enum tag_ccr_enable_e
{
  CCR_DISABLE = 0,  /* disable */
  CCR_ENABLE  = 1   /* enable  */
} ccr_enable_e;

typedef enum tag_ccr_alarm_no_e
{
  CCR_ALARM_0  = 0,   /* Alarm 0 */
  CCR_ALARM_1  = 1   /* Alarm 1  */
} ccr_alarm_no_e;

/* Controller selection */
typedef enum tag_ccr_cntrl_e
{
    CCR_QSPI_0        =  0,   /* QSPI 0 */
    CCR_QSPI_1        =  1,   /* QSPI 1 */
    CCR_QSPI_INT      =  2,   /* QSPI Internal */
    CCR_SDRAM         =  3,   /* SDRAM */
    CCR_I2S           =  4,   /* I2S */
    CCR_GDC_0         =  5,   /* GDC 0 */
    CCR_GDC_1         =  6,   /* GDC 1 */
    CCR_DMA           =  7,   /* DMA */
    CCR_PARFLASH      =  8,   /* Parallel Flash */
    CCR_DAP           =  9,   /*  */
    CCR_GA            = 10,   /* GA Engine */
    CCR_PNG           = 11,   /* PNG Decoder */
    CCR_FG            = 12,   /* Framegrabber */
    CCR_MLB           = 13,   /* MLB */
    CCR_SMC           = 14,   /* Stepper Motor */
    CCR_HSPWM         = 15,   /* HSPWM */
    CCR_I2SM          = 16,   /* I2SM */
    CCR_TSM           = 17,   /* TSM */
    CCR_TRACE         = 18,   /* Trace */
    CCR_320MHz        = 19    /* 320MHz */
} ccr_cntrl_e;

/* Modulation type */
typedef enum tag_ccr_modulated_clk_e
{
    CCR_MODULATED     = 0,    /* modulated clock */
    CCR_NON_MODULATED = 1     /* non modulated clock */
} ccr_modulated_clk_e;

/*  */
typedef enum tag_ccr_clock_type_e
{
    CCR_MODULATED_GDC0       = 0,    /* Modulated clock for GDC0 */
    CCR_MODULATED_GDC1       = 1,    /* Modulated clock for GDC1 */
    CCR_NON_MODULATED_GDC0   = 2,    /* Non modulated clock for GDC0 */
    CCR_NON_MODULATED_GDC1   = 3,    /* Non modulated clock for GDC1 */
    CCR_DOTCLKIN             = 4,    /* DOTCLKIN for GDC0 or GDC1 */
    CCR_MODULATED_I2S        = 5,    /* Modulated clock for I2S */
    CCR_NON_MODULATED_I2S    = 6,    /* Non modulated clock for I2S */
    CCR_I2SMCLKIN            = 7,    /* I2SMCLKIN for I2S */
    CCR_MODULATED_320MHZ     = 8,    /* Modulated clock for 320MHz */
    CCR_NON_MODULATED_320MHZ = 9     /* Non modulated clock for 320MHz */
} ccr_clock_type_e;

/* Clock divider values (input clock: 900MHz) */
typedef enum tag_ccr_clk_freq_e
{
    CCR_CLKDIV_112_5MHz =  8,    /* 112,5 MHz output clk */
    CCR_CLKDIV_100_0MHz =  9,    /* 100,0 MHz output clk */
    CCR_CLKDIV_90_0MHz  = 10,    /*  90,0 MHz output clk */
    CCR_CLKDIV_81_8MHz  = 11,    /*  81,8 MHz output clk */
    CCR_CLKDIV_75_0MHz  = 12,    /*  75,0 MHz output clk */
    CCR_CLKDIV_69_2MHz  = 13,    /*  69,2 MHz output clk */
    CCR_CLKDIV_64_3MHz  = 14,    /*  64,3 MHz output clk */
    CCR_CLKDIV_60_0MHz  = 15,    /*  60,0 MHz output clk */
    CCR_CLKDIV_56_3MHz  = 16,    /*  56,3 MHz output clk */
    CCR_CLKDIV_52_9MHz  = 17,    /*  52,9 MHz output clk */
    CCR_CLKDIV_50_0MHz  = 18,    /*  50,0 MHz output clk */
    CCR_CLKDIV_47_4MHz  = 19,    /*  47,4 MHz output clk */
    CCR_CLKDIV_45_0MHz  = 20,    /*  45,0 MHz output clk */
    CCR_CLKDIV_42_9MHz  = 21,    /*  42,9 MHz output clk */
    CCR_CLKDIV_40_9MHz  = 22,    /*  40,9 MHz output clk */
    CCR_CLKDIV_39_1MHz  = 23,    /*  39,1 MHz output clk */
    CCR_CLKDIV_37_5MHz  = 24,    /*  37,5 MHz output clk */
    CCR_CLKDIV_36_0MHz  = 25,    /*  36,0 MHz output clk */
    CCR_CLKDIV_34_6MHz  = 26,    /*  34,6 MHz output clk */
    CCR_CLKDIV_33_3MHz  = 27,    /*  33,3 MHz output clk */
    CCR_CLKDIV_32_1MHz  = 28,    /*  32,1 MHz output clk */
    CCR_CLKDIV_31_0MHz  = 29,    /*  31,0 MHz output clk */
    CCR_CLKDIV_30_0MHz  = 30,    /*  30,0 MHz output clk */
    CCR_CLKDIV_29_0MHz  = 31,    /*  29,0 MHz output clk */
    CCR_CLKDIV_28_1MHz  = 32,    /*  28,1 MHz output clk */
    CCR_CLKDIV_27_2MHz  = 33,    /*  27,2 MHz output clk */
    CCR_CLKDIV_26_4MHz  = 34,    /*  26,4 MHz output clk */
    CCR_CLKDIV_25_7MHz  = 35,    /*  25,7 MHz output clk */
    CCR_CLKDIV_25_0MHz  = 36,    /*  25,0 MHz output clk */
    CCR_CLKDIV_24_3MHz  = 37,    /*  24,3 MHz output clk */
    CCR_CLKDIV_23_6MHz  = 38,    /*  23,6 MHz output clk */
    CCR_CLKDIV_23_0MHz  = 39,    /*  23,0 MHz output clk */
    CCR_CLKDIV_22_5MHz  = 40     /*  22,5 MHz output clk */
} ccr_clk_freq_e;

/* Clock stability */
typedef enum tag_ccr_clock_stability_e
{
    CCR_CLOCK_NOT_STABLE     = 0,    /* Clock is not stable */
    CCR_CLOCK_STABLE         = 1,    /* Clock is stable */
    CCR_CLOCK_STABILITY_FAIL = 2     /* Clock stability faild */
} ccr_clock_stability_e;

/* Clocks */
typedef enum tag_ccr_clocks_e
{
    CCR_OSC10M            = 0,    /* 10M clock */
    CCR_OSC32K            = 1,    /* 32K clock */
    CCR_RC100K            = 2,    /* RC100K clock */
    CCR_MODULATED_PLL     = 3,    /* modulated PLL */
    CCR_NON_MODULATED_PLL = 4     /* non-modulated PLL */
} ccr_clocks_e;

/* Reset types */
typedef enum tag_reset_type_e
{
    CCR_FULL_RST    = 0,    /* Software full reset */
    CCR_DBG_RST     = 1,    /* Debug reset */
    CCR_SW_PART_RST = 2     /* Software part reset */
} ccr_reset_type_e;

/* target device mode */
typedef enum tag_ccr_device_mode_e
{
    CCR_DEVICE_MODE_TRANSITION = 0x00000000,    /* M_PLL */
    CCR_DEVICE_MODE_M_PLL      = 0x005C0001,    /* M_PLL */
    CCR_DEVICE_MODE_M_OSC10    = 0x005C0002,    /* M_OSC10 */
    CCR_DEVICE_MODE_STB_OSC10  = 0x005C0004,    /* STB_OSC10 */
    CCR_DEVICE_MODE_SLP_OSC10  = 0x005C0008,    /* SLP_OSC10 */
    CCR_DEVICE_MODE_SLP_RC10   = 0x005C0010,    /* SLP_RC10 */
    CCR_DEVICE_MODE_STOP_R     = 0x005C0020,    /* STOP_R */
    CCR_DEVICE_MODE_STOP       = 0x005C0040     /* STOP */
} ccr_device_mode_e;

/* Interupts */
typedef enum tag_ccr_interrupts_e
{
    CCR_INTERRUPTS_STATE_CHANGE = 0,    /* state change interrupt*/
    CCR_INTERRUPTS_ALARM_0      = 1,    /* alarm comparator 0 interrupt */
    CCR_INTERRUPTS_ALARM_1      = 2,    /* alarm comparator 1 interrupt */
    CCR_INTERRUPTS_BECC         = 3,    /* backup RAM ECC interrupt */
    CCR_INTERRUPTS_MECC         = 4     /* main memory ECC interrupt */
} ccr_interrupts_e;

/* Interrupt occurred */
typedef enum tag_ccr_int_occurred_e
{
  CCR_INT_NOT_OCCURRED = 0,  /* interrupt did not occur */
  CCR_INT_OCCURRED     = 1   /* interrupt occurred */
} ccr_int_occurred_e;

/* Operation mode type */
typedef enum tag_ccr_operation_mode_type_e
{
    CCR_SSCG_MODE_DECIMAL_FACTOR = 0,    /* Decimal factor mode */
    CCR_SSCG_MODE_INTEGER_FACTOR = 1     /* Integer factor mode */
} ccr_operation_mode_type_e;

/* Modulation direction */
typedef enum tag_ccr_modulation_direction
{
    CCR_SSCG_MD_DOWN_SPREAD   = 0,    /* modulation direction is down spread */
    CCR_SSCG_MD_CENTER_SPREAD = 1     /* modulation direction is up spread */
} ccr_modulation_direction;

/* Feedback division ratio prescaler value */
typedef enum tag_ccr_fdr_prescaler_e
{
    CCR_FDR_PRESCALER_1 = 0,    /* feedback division ratio not doubled */
    CCR_FDR_PRESCALER_2 = 1     /* feedback division ratio doubled */
} ccr_fdr_prescaler_e;

/* Watchdof timer alarm output configuration */
typedef enum tag_ccr_wdt_alarm_type_e
{
    CCR_WDT_ALARM_AS_NMI   = 0,    /* watchdog timer alarm as watchdog timer NMI */
    CCR_WDT_ALARM_AS_RESET = 1     /* watchdog timer alarm as watchdog timer RESET */
} ccr_wdt_alarm_type_e;

/* CAN modes */
typedef enum tag_ccr_can_mode_e
{                                     /*             tranceiver , combined channels, sepatate channels, pin pairs, description */
    CCR_CAN_MODE_T_1_1_1_1  = 0x0,    /* CAN mode  1:     yes   ,         -        ,         4        ,    4     ,   1+1+1+1   */
    CCR_CAN_MODE_T_2_1_1    = 0x1,    /* CAN mode  2:     yes   ,         2        ,         2        ,    3     ,    2+1+1    */
    CCR_CAN_MODE_T_2_2      = 0x2,    /* CAN mode  3:     yes   ,         4        ,         -        ,    2     ,     2+2     */
    CCR_CAN_MODE_T_3_1      = 0x3,    /* CAN mode  4:     yes   ,         3        ,         1        ,    2     ,     3+1     */
    CCR_CAN_MODE_T_ALL      = 0x4,    /* CAN mode  5:     yes   ,         4        ,         -        ,    1     , all to one  */
    CCR_CAN_MODE_NT_1_1_1_1 = 0x8,    /* CAN mode  5:      no   ,         -        ,         4        ,    4     ,   1+1+1+1   */
    CCR_CAN_MODE_NT_2_1_1   = 0x9,    /* CAN mode  6:      no   ,         2        ,         2        ,    3     ,    2+1+1    */
    CCR_CAN_MODE_NT_2_2     = 0xA,    /* CAN mode  7:      no   ,         4        ,         -        ,    2     ,     2+2     */
    CCR_CAN_MODE_NT_3_1     = 0xB,    /* CAN mode  8:      no   ,         3        ,         1        ,    2     ,     3+1     */
    CCR_CAN_MODE_NT_ALL     = 0xC,    /* CAN mode  9:      no   ,         4        ,         -        ,    1     , all to all  */
    CCR_CAN_MODE_NT_INTER   = 0xF     /* CAN mode 10:      no   ,         -        ,         4        ,    -     , internal    */
} ccr_can_mode_e;

/* ECC modes */
typedef enum tag_ccr_ecc_mode_e
{
    CCR_ECC_MODE_256KB  = 0,    /* 256KB with ECC */
    CCR_ECC_MODE_128KB  = 2,    /* 128KB with ECC */
    CCR_ECC_MODE_NO_ECC = 3     /* without ECC */
} ccr_ecc_mode_e;

/* TBIO channel */
typedef enum tag_ccr_tbio_channel_e
{
    CCR_TBIO_0 = 0,    /* TBIO channel 0 */
    CCR_TBIO_1 = 1,    /* TBIO channel 1 */
    CCR_TBIO_2 = 2,    /* TBIO channel 2 */
    CCR_TBIO_3 = 3,    /* TBIO channel 3 */
    CCR_TBIO_4 = 4,    /* TBIO channel 4 */
    CCR_TBIO_5 = 5,    /* TBIO channel 5 */
    CCR_TBIO_6 = 6,    /* TBIO channel 6 */
    CCR_TBIO_7 = 7,    /* TBIO channel 7 */
    CCR_TBIO_8 = 8,    /* TBIO channel 8 */
    CCR_TBIO_9 = 9     /* TBIO channel 9 */
} ccr_tbio_channel_e;

/* TBIO port direction */
typedef enum tag_ccr_tbio_direction_e
{
    CCR_TBIO_IN  = 0,    /* TBIO pin as input */
    CCR_TBIO_OUT = 1     /* TBIO pin as output */
} ccr_tbio_direction_e;

/* TBIN0 signal select for Complex Timer 4 */
typedef enum tag_ccr_tbin_source_ctimer4_e
{
    CCR_TBIN_CTIMER4_PWMOUT00       =  0,    /* TBIN0 signal for Complex Timer 4 is PWMOUT00 */
    CCR_TBIN_CTIMER4_PWMOUT02       =  1,    /* TBIN0 signal for Complex Timer 4 is PWMOUT02 */
    CCR_TBIN_CTIMER4_PWMOUT04       =  2,    /* TBIN0 signal for Complex Timer 4 is PWMOUT04 */
    CCR_TBIN_CTIMER4_PWMOUT06       =  3,    /* TBIN0 signal for Complex Timer 4 is PWMOUT06 */
    CCR_TBIN_CTIMER4_PWMOUT08       =  4,    /* TBIN0 signal for Complex Timer 4 is PWMOUT08 */
    CCR_TBIN_CTIMER4_PWMOUT10       =  5,    /* TBIN0 signal for Complex Timer 4 is PWMOUT10 */
    CCR_TBIN_CTIMER4_PWMOUT12       =  6,    /* TBIN0 signal for Complex Timer 4 is PWMOUT12 */
    CCR_TBIN_CTIMER4_PWMOUT14       =  7,    /* TBIN0 signal for Complex Timer 4 is PWMOUT14 */
    CCR_TBIN_CTIMER4_PWMOUT16       =  8,    /* TBIN0 signal for Complex Timer 4 is PWMOUT16 */
    CCR_TBIN_CTIMER4_PWMOUT18       =  9,    /* TBIN0 signal for Complex Timer 4 is PWMOUT18 */
    CCR_TBIN_CTIMER4_PWMOUT20       = 10,    /* TBIN0 signal for Complex Timer 4 is PWMOUT20 */
    CCR_TBIN_CTIMER4_PWMOUT22       = 11,    /* TBIN0 signal for Complex Timer 4 is PWMOUT22 */
    CCR_TBIN_CTIMER4_GDC_PWMOUT0    = 12,    /* TBIN0 signal for Complex Timer 4 is GDC_PWMOUT0 */
    CCR_TBIN_CTIMER4_GDC_SIN_PLUS0  = 13,    /* TBIN0 signal for Complex Timer 4 is SIN_PLUS0 */
    CCR_TBIN_CTIMER4_GDC_SIN_MINUS0 = 14     /* TBIN0 signal for Complex Timer 4 is SIN_MINUS0 */
} ccr_tbin_source_ctimer4_e;

/* TBIN0 signal select for Complex Timer 5 */
typedef enum tag_ccr_tbin_source_ctimer5_e
{
    CCR_TBIN_CTIMER5_PWMOUT00       =  0,    /* TBIN0 signal for Complex Timer 4 is PWMOUT00 */
    CCR_TBIN_CTIMER5_PWMOUT02       =  1,    /* TBIN0 signal for Complex Timer 4 is PWMOUT02 */
    CCR_TBIN_CTIMER5_PWMOUT04       =  2,    /* TBIN0 signal for Complex Timer 4 is PWMOUT04 */
    CCR_TBIN_CTIMER5_PWMOUT06       =  3,    /* TBIN0 signal for Complex Timer 4 is PWMOUT06 */
    CCR_TBIN_CTIMER5_PWMOUT08       =  4,    /* TBIN0 signal for Complex Timer 4 is PWMOUT08 */
    CCR_TBIN_CTIMER5_PWMOUT10       =  5,    /* TBIN0 signal for Complex Timer 4 is PWMOUT10 */
    CCR_TBIN_CTIMER5_PWMOUT12       =  6,    /* TBIN0 signal for Complex Timer 4 is PWMOUT12 */
    CCR_TBIN_CTIMER5_PWMOUT14       =  7,    /* TBIN0 signal for Complex Timer 4 is PWMOUT14 */
    CCR_TBIN_CTIMER5_PWMOUT16       =  8,    /* TBIN0 signal for Complex Timer 4 is PWMOUT16 */
    CCR_TBIN_CTIMER5_PWMOUT18       =  9,    /* TBIN0 signal for Complex Timer 4 is PWMOUT18 */
    CCR_TBIN_CTIMER5_PWMOUT20       = 10,    /* TBIN0 signal for Complex Timer 4 is PWMOUT20 */
    CCR_TBIN_CTIMER5_PWMOUT22       = 11,    /* TBIN0 signal for Complex Timer 4 is PWMOUT22 */
    CCR_TBIN_CTIMER5_GDC_PWMOUT1    = 12,    /* TBIN0 signal for Complex Timer 4 is GDC_PWMOUT1 */
    CCR_TBIN_CTIMER5_GDC_COS_PLUS0  = 13,    /* TBIN0 signal for Complex Timer 4 is COS_PLUS0 */
    CCR_TBIN_CTIMER5_GDC_COS_MINUS0 = 14     /* TBIN0 signal for Complex Timer 4 is COS_MINUS0 */
} ccr_tbin_source_ctimer5_e;

/* Synchronisation between GDC0 and GDC1 */
typedef enum tag_ccr_gdc_sync_e
{
    CCR_GDC_SYNC_INDEPENDANT   = 0,    /* independant operation of GDC1 */
    CCR_GDC_SYNC_GDC1_USE_GDC0 = 1     /* GDC1 uses GDC0 synchronisation signals */
} ccr_gdc_sync_e;

/* NOR channel */
typedef enum tag_ccr_nor_channel_e
{
    CCR_NOR_CHANNEL_0 = 0,    /* NOR channel 0 */
    CCR_NOR_CHANNEL_1 = 1     /* NOR channel 1 */
} ccr_nor_channel_e;

/* NAND channel */
typedef enum tag_ccr_nand_channel_e
{
    CCR_NAND_CHANNEL_0 = 0,    /* NAND channel 0 */
    CCR_NAND_CHANNEL_1 = 1     /* NAND channel 1 */
} ccr_nand_channel_e;

/* SRAM channel */
typedef enum tag_ccr_sram_channel_e
{
    CCR_SRAM_CHANNEL_0 = 0,    /* SRAM channel 0 */
    CCR_SRAM_CHANNEL_1 = 1,    /* SRAM channel 1 */
    CCR_SRAM_CHANNEL_2 = 2,    /* SRAM channel 2 */
    CCR_SRAM_CHANNEL_3 = 3     /* SRAM channel 3 */
} ccr_sram_channel_e;

/* Complex timer */
typedef enum tag_ccr_complex_timer_e
{
    CCR_COMPLEX_TIMER_0_TO_5 = 0,    /* Complex timer 0 to 5 */
    CCR_COMPLEX_TIMER_6_TO_9 = 1     /* Complex timer 6 to 9 */
} ccr_complex_timer_e;

/* Device version */
typedef enum tag_ccr_device_version_e
{
    DEVICE_CAP_BT_1  = 0,    /* TMPR461XBG-300 (BGA-328, no SIP Flash)   */
    DEVICE_CAP_C     = 1,    /* TMPR462XBG-300 (BGA-328, with SIP Flash) */
    DEVICE_CAP_BT_0  = 2,    /* TMPR460XBG-300 (BGA-244, no SIP Flash)   */
    DEVICE_INVALID   = 3     /* Reserved   */
} ccr_device_version_e;

/* SIP Flash size */
typedef enum tag_ccr_SIPflash_size_e
{
    CCR_SIP_FLASH_SIZE_2MB  = 0,    /*  2MB SIP FLASH size */
    CCR_SIP_FLASH_SIZE_4MB  = 1,    /*  4MB SIP FLASH size */
    CCR_SIP_FLASH_SIZE_8MB  = 2,    /*  8MB SIP FLASH size */
    CCR_SIP_FLASH_SIZE_16MB = 3     /* 16MB SIP FLASH size */
} ccr_SIPflash_size_e;

typedef enum tag_processor_device_e
{
    CCR_CR4 = 0,    /* processor R4 */
    CCR_M3  = 1     /* processor M3 */
} ccr_processor_device_e;

/* Voltage regulator current trim */
typedef enum tag_vreg_current_trim_e
{
    CCR_VREG_CURRENT_TRIM_M_40_PROZ = 4,    /* -40% */
    CCR_VREG_CURRENT_TRIM_M_30_PROZ = 5,    /* -30% */
    CCR_VREG_CURRENT_TRIM_M_20_PROZ = 6,    /* -20% */
    CCR_VREG_CURRENT_TRIM_M_10_PROZ = 7,    /* -10% */
    CCR_VREG_CURRENT_TRIM_0_PROZ    = 0,    /*   0% */
    CCR_VREG_CURRENT_TRIM_P_10_PROZ = 1,    /*  10% */
    CCR_VREG_CURRENT_TRIM_P_20_PROZ = 2,    /*  20% */
    CCR_VREG_CURRENT_TRIM_P_30_PROZ = 3     /*  30% */
} ccr_vreg_current_trim_e;

/* Voltage regulator reference voltage trim */
typedef enum tag_vreg_ref_voltage_trim_e
{
    CCR_VREG_REF_VOLTAGE_TRIM_M_7_5_PROZ = 15,    /* -7.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_7_0_PROZ = 14,    /* -7.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_6_5_PROZ = 13,    /* -6.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_6_0_PROZ = 12,    /* -6.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_5_5_PROZ = 11,    /* -5.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_5_0_PROZ = 10,    /* -5.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_4_5_PROZ =  9,    /* -4.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_4_0_PROZ =  8,    /* -4.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_3_5_PROZ =  7,    /* -3.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_3_0_PROZ =  6,    /* -3.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_2_5_PROZ =  5,    /* -2.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_2_0_PROZ =  4,    /* -2.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_1_5_PROZ =  3,    /* -1.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_1_0_PROZ =  2,    /* -1.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_M_0_5_PROZ =  1,    /* -0.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_0_PROZ     =  0,    /*    0% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_0_5_PROZ = 31,    /* 0.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_1_0_PROZ = 30,    /* 1.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_1_5_PROZ = 29,    /* 1.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_2_0_PROZ = 28,    /* 2.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_2_5_PROZ = 27,    /* 2.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_3_0_PROZ = 26,    /* 3.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_3_5_PROZ = 25,    /* 3.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_4_0_PROZ = 24,    /* 4.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_4_5_PROZ = 23,    /* 4.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_5_0_PROZ = 22,    /* 5.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_5_5_PROZ = 21,    /* 5.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_6_0_PROZ = 20,    /* 6.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_6_5_PROZ = 19,    /* 6.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_7_0_PROZ = 18,    /* 7.0% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_7_5_PROZ = 17,    /* 7.5% */
    CCR_VREG_REF_VOLTAGE_TRIM_P_8_0_PROZ = 16     /* 8.0% */
} ccr_vreg_ref_voltage_trim_e;

/* Voltage regulator current trim */
typedef enum tag_vreg_temperature_trim_e
{
    CCR_VREG_TEMPERATURE_TRIM_M_60_DEGC = 4,    /* -60degC */
    CCR_VREG_TEMPERATURE_TRIM_M_50_DEGC = 5,    /* -50degC */
    CCR_VREG_TEMPERATURE_TRIM_M_40_DEGC = 6,    /* -40degC */
    CCR_VREG_TEMPERATURE_TRIM_M_25_DEGC = 7,    /* -25degC */
    CCR_VREG_TEMPERATURE_TRIM_0_DEGC    = 0,    /*   0degC */
    CCR_VREG_TEMPERATURE_TRIM_P_25_DEGC = 1,    /*  25degC */
    CCR_VREG_TEMPERATURE_TRIM_P_50_DEGC = 2,    /*  50degC */
    CCR_VREG_TEMPERATURE_TRIM_P_70_DEGC = 3     /*  70degC */
} ccr_vreg_temperature_trim_e;

/* Oscillator adjustment */
typedef enum tag_osc_adjustment_e
{
    CCR_OSC_ADJUSTMENT_M_8 =  8,    /* -8 */
    CCR_OSC_ADJUSTMENT_M_7 =  9,    /* -7 */
    CCR_OSC_ADJUSTMENT_M_6 = 10,    /* -6 */
    CCR_OSC_ADJUSTMENT_M_5 = 11,    /* -5 */
    CCR_OSC_ADJUSTMENT_M_4 = 12,    /* -4 */
    CCR_OSC_ADJUSTMENT_M_3 = 13,    /* -3 */
    CCR_OSC_ADJUSTMENT_M_2 = 14,    /* -2 */
    CCR_OSC_ADJUSTMENT_M_1 = 15,    /* -1 */
    CCR_OSC_ADJUSTMENT_0   =  0,    /*  0 */
    CCR_OSC_ADJUSTMENT_P_1 =  1,    /*  1 */
    CCR_OSC_ADJUSTMENT_P_2 =  2,    /*  2 */
    CCR_OSC_ADJUSTMENT_P_3 =  3,    /*  3 */
    CCR_OSC_ADJUSTMENT_P_4 =  4,    /*  4 */
    CCR_OSC_ADJUSTMENT_P_5 =  5,    /*  5 */
    CCR_OSC_ADJUSTMENT_P_6 =  6,    /*  6 */
    CCR_OSC_ADJUSTMENT_P_7 =  7     /*  7 */
} ccr_osc_adjustment_e;

/* Threshold for power-good sensing */
typedef enum tag_threshold_power_good_sensing_e
{
    CCR_POWER_GOOD_SENSING_0 = 0,    /* threshold 0 */
    CCR_POWER_GOOD_SENSING_1 = 1,    /* threshold 1 */
    CCR_POWER_GOOD_SENSING_2 = 2,    /* threshold 2 */
    CCR_POWER_GOOD_SENSING_3 = 3,    /* threshold 3 */
    CCR_POWER_GOOD_SENSING_4 = 7,    /* threshold 4 */
    CCR_POWER_GOOD_SENSING_5 = 6,    /* threshold 5 */
    CCR_POWER_GOOD_SENSING_6 = 5,    /* threshold 6 */
    CCR_POWER_GOOD_SENSING_7 = 4     /* threshold 7 */
} ccr_threshold_power_good_sensing_e;

/* SMC IO level */
typedef enum tag_smc_io_level_e
{
    CCR_SMC_IO_LEVEL_5V0 = 0,    /* operate with 5V */
    CCR_SMC_IO_LEVEL_3V3 = 1     /* operate with 3.3V */
} ccr_smc_io_level_e;

/* Interrupts */
typedef enum tag_system_interrupt_e
{
    CCR_OSC10M_CLOCK_MISSING_INT = 0x00000001,    /* OSC10MHz */
    CCR_OSC32K_CLOCK_MISSING_INT = 0x00000100,    /* OSC32KHz */
    CCR_EROR_INT_0               = 0x00010000,    /* Error interrupt 0 */
    CCR_EROR_INT_1               = 0x00020000,    /* Error interrupt 1 */
    CCR_EROR_INT_2               = 0x00040000,    /* Error interrupt 2 */
    CCR_BACKUP_ECC_RAM_INT       = 0x01000000,    /* Backup ECC-RAM */
    CCR_MAIN_MEMORY_ECC_RAM_INT  = 0x02000000,    /* Main memory ECC-RAM */
    CCR_STPU_INT                 = 0x04000000,    /* STPU */
    CCR_WDT_INT                  = 0x08000000,    /* WDT */
    CCR_IO_INT                   = 0x10000000     /* IO */
} ccr_system_interrupt_e;

/* ECC */
typedef enum tag_ecc_e
{
    CCR_BACKUP_RAM_ECC  = 0,    /* Backup RAM ECC */
    CCR_MAIN_MEMORY_ECC = 1     /* Main memory ECC */
} ccr_ecc_e;

/* ECC interrupt type */
typedef enum tag_ecc_interrupt_type_e
{
    CCR_ECC_SYSC_INTR    = 0,    /* SYSC_INTR will be generated */
    CCR_ECC_SYSC_NMI     = 1,    /* SYSC_NMI will be generated */
    CCR_ECC_SW_FULL_RSTN = 2     /* SW_FULL_RSTN will be generated */
} ccr_ecc_interrupt_type_e;

/* Modes */
typedef enum tag_modes_e
{
    CCR_STB_MODE      = 0,    /* mission state entered from STB_ISC10 */
    CCR_SLPOSC10_MODE = 1,    /* mission state entered from SLP_OSC10 */
    CCR_SLPRCOSC_MODE = 2,    /* mission state entered from SLP_RD100K */
    CCR_STOPR_MODE    = 3,    /* mission state entered from STOP_R */
    CCR_STOP_MODE     = 4     /* mission state entered from STOP */
} ccr_modes_e;

/* Wakeup attributes */
typedef enum tag_wakeup_attribute_e
{
    CCR_LOW_LEVEL  = 0,    /* low level wakeup */
    CCR_HIGH_LEVEL = 1,    /* high level wakeup */
    CCR_FALL_EDGE  = 2,    /* falling edge wakeup */
    CCR_RISE_EDGE  = 3     /* rising edge wakeup */
} ccr_wakeup_attribute_e;

/* Wakeup sources */
typedef enum tag_wakeup_source_e
{
    CCR_WAKEUP_SOURCE_0     =  0,    /* wakeup source 0 */
    CCR_WAKEUP_SOURCE_1     =  1,    /* wakeup source 1 */
    CCR_WAKEUP_SOURCE_2     =  2,    /* wakeup source 2 */
    CCR_WAKEUP_SOURCE_3     =  3,    /* wakeup source 3 */
    CCR_WAKEUP_SOURCE_4     =  4,    /* wakeup source 4 */
    CCR_WAKEUP_SOURCE_5     =  5,    /* wakeup source 5 */
    CCR_WAKEUP_SOURCE_6     =  6,    /* wakeup source 6 */
    CCR_WAKEUP_SOURCE_7     =  7,    /* wakeup source 7 */
    CCR_WAKEUP_SOURCE_NMI   =  8,    /* wakeup source NMI */
    CCR_WAKEUP_SOURCE_ALARM =  9,    /* wakeup source ALARM */
    CCR_WAKEUP_SOURCE_RTC   = 10     /* wakeup source RTC */
} ccr_wakeup_source_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/* SSCG configuration structure */
typedef struct tag_ccr_sscg_congig_st
{
    ccr_modulation_direction  eModulationDirection;
    uint8_t                   u8ModulationCycleLengthFractionalN;
    uint16_t                  u16ModulationDegree;
} ccr_sscg_congig_st;

/* SRAM bit error inspection configuration */
typedef struct tag_ccr_sram_bit_error_insp_config_st
{
    uint8_t u8PosFirstError;     /* Position of first bit error to be injected in SRAM */
    uint8_t u8PosSecondError;    /* Position of second bit error to be injected in SRAM */
    uint8_t u8ByteSelect;        /* Byte select for bit error injection in SRAM */
} ccr_sram_bit_error_insp_config_st;

/*********************************************/

/**********************************************
*            Forward declarations             *
**********************************************/

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vCCR_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8IOPDHRevision  - pointer to PDH IO header revision string
 *                pau8IOPDHTag       - pointer to PDH IO header tag string
 *                pau8IOPDSRevision  - pointer to PDS IO header revision string
 *                pau8IOPDSTag       - pointer to PDS IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vCCR_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IOPDHRevision, uint8_t** pau8IOPDHTag,
                     uint8_t** pau8IOPDSRevision, uint8_t** pau8IOPDSTag);

/****************************************************************************
 *
 * Function:      i32CCR_EnableModuleClock
 *
 * Purpose:       Enable or disable module clock
 *                Normally first the clock frequency should be set. Than the
 *                module should be switched on. Switching off the module is not
 *                necessary before setting the clock frequency.
 *
 * Inputs:        eCntrl     Controller
 *                eEn        CCR_Enable if clock should be enabled
 *                           CCR_Disable if clock should be disabled
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_EnableModuleClock(ccr_cntrl_e eCntrl, ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      i32CCR_GetEnabledModuleClock
 *
 * Purpose:       Enable or disable module clock
 *                Normally first the clock frequency should be set. Than the
 *                module should be switched on. Switching off the module is not
 *                necessary before setting the clock frequency.
 *
 * Inputs:        eCntrl     Controller
 *                peEn       status of module clock
 *                           CCR_Enable clock is enabled
 *                           CCR_Disable clock is disabled
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on invalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_GetEnabledModuleClock(ccr_cntrl_e eCntrl, ccr_enable_e * peEn);

/****************************************************************************
 *
 * Function:      i32CCR_SetClockFreq
 *
 * Purpose:       Configures clock frequency
 *                Clock frequency can be changed every time because no glitch
 *                should occur during switching. To be on the save side every
 *                action of the module should be finished.
 *                Normally first the clock frequency should be set. Than the
 *                module should be switched on. Switching off the module is not
 *                necessary before setting the clock frequency.
 *
 * Inputs:        eCntrl     Controller
 *                eFreq      Target frequency
 *                eModulated modulation type
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetClockFreq(ccr_cntrl_e eCntrl, ccr_clk_freq_e eFreq, ccr_modulated_clk_e eModulated);

/****************************************************************************
 *
 * Function:      i32CCR_SelectClockType
 *
 * Purpose:       Select clock type
 *
 * Inputs:        eCntrl        Controller
 *                eClockType    Clock type
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SelectClockType(ccr_cntrl_e eCntrl, ccr_clock_type_e eClockType);

/****************************************************************************
 *
 * Function:      vCCR_SetPllClockStabilizationCompareValue
 *
 * Purpose:       Set Pll clock stabilization compare value
 *
 * Inputs:        u8Value    Stabilization compare value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_SetPllClockStabilizationCompareValue(uint8_t u8Value);

/****************************************************************************
 *
 * Function:      eCCR_ReadClockStability
 *
 * Purpose:       Read stability value of different oscillators and PLLs
 *
 * Inputs:        eClk        Clock or PLL
 *
 * Outputs:       none
 *
 * Return Values: clock stability value
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_clock_stability_e eCCR_ReadClockStability(ccr_clocks_e eClk);

/****************************************************************************
 *
 * Function:      i32CCR_GenerateReset
 *
 * Purpose:       Generate different types of reset
 *
 * Inputs:        eResetType     Reset type
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_GenerateReset(ccr_reset_type_e eResetType);

/****************************************************************************
 *
 * Function:      i32CCR_SetDeviceMode
 *
 * Purpose:       Set device mode
 *
 * Inputs:        eMode     Device mode
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   Transitions to STB_OSC10, SLP_OSC10, SLP_RC10, STOP_R
 *                and STOP are only possible in rom2ram-project without
 *                any probe connected.
 *
 ***************************************************************************/
int32_t i32CCR_SetDeviceMode(ccr_device_mode_e eMode);

/****************************************************************************
 *
 * Function:      i32CCR_EnableInterrupt
 *
 * Purpose:       Enable interrupts
 *
 * Inputs:        eInterrupt     Interrupt type
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_EnableInterrupt(ccr_interrupts_e eInterrupt, ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      u32CCR_GetInterruptStatusAll
 *
 * Purpose:       Read status of all interrupts
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Status of all interrupts
 *
 * Limitations:
 *
 ***************************************************************************/
uint32_t u32CCR_GetInterruptStatusAll(void);

/****************************************************************************
 *
 * Function:      i32CCR_GetInterruptStatus
 *
 * Purpose:       Read interrupt status
 *
 * Inputs:        eInterrupt     Interrupt type
 *
 * Outputs:       peIntOccurred  Status of interrupt
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_GetInterruptStatusSingle(ccr_interrupts_e eInterrupt, ccr_int_occurred_e * peIntOccurred);

/****************************************************************************
 *
 * Function:      vCCR_ClearInterruptsAll
 *
 * Purpose:       Clear all interrupts
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_ClearInterruptsAll(void);

/****************************************************************************
 *
 * Function:      i32CCR_ClearInterruptSingle
 *
 * Purpose:       Clear single interrupt
 *
 * Inputs:        eInterrupt     Interrupt type
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_ClearInterruptSingle(ccr_interrupts_e eInterrupt);

/****************************************************************************
 *
 * Function:      eCCR_GetCurrentDeviceMode
 *
 * Purpose:       Read current device mode
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Device mode
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_device_mode_e eCCR_GetCurrentDeviceMode(void);

/****************************************************************************
 *
 * Function:      vCCR_ConfigureSSCG
 *
 * Purpose:       Configure the SSCG and start it with new settings
 *
 * Inputs:        pstSSCGConfig    Pointer to SSCG-configuration
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_ConfigureSSCG(ccr_sscg_congig_st * pstSSCGConfig);

/****************************************************************************
 *
 * Function:      vCCR_SetWDTAlarmType
 *
 * Purpose:       Configure WDT alarm type
 *
 * Inputs:        eAlarmType    WDT alarm type
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_SetWDTAlarmType(ccr_wdt_alarm_type_e eAlarmType);

/****************************************************************************
 *
 * Function:      vCCR_EnableBitErrorInjectionInRAM
 *
 * Purpose:       Enable or disable error injection in Back-up RAM
 *
 * Inputs:        eEn    Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_EnableBitErrorInjectionInRAM(ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      vCCR_SetPositionOfBitErrorInjectionInRAM
 *
 * Purpose:       Set bit positions to be injected in Back-up RAM
 *
 * Inputs:        u8FirstPosition     first position
 *                u8SecondPosition    second position
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_SetPositionOfBitErrorInjectionInRAM(uint8_t u8FirstPosition, uint8_t u8SecondPosition);

/****************************************************************************
 *
 * Function:      vCCR_SetCANMode
 *
 * Purpose:       Set CAN mode
 *
 * Inputs:        eCANMode     CAN mode
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_SetCANMode(ccr_can_mode_e eCANMode);

/****************************************************************************
 *
 * Function:      vCCR_SetECCMode
 *
 * Purpose:       Set ECC mode
 *
 * Inputs:        eECCMode     ECC mode
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_SetECCMode(ccr_ecc_mode_e eECCMode);

/****************************************************************************
 *
 * Function:      i32CCR_SetTBIODirection
 *
 * Purpose:       Set TBIO port direction
 *
 * Inputs:        eTBIOChannel     TBIO channel
 *                eDirection       Pin direction
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetTBIODirection(ccr_tbio_channel_e eTBIOChannel, ccr_tbio_direction_e eDirection);

/****************************************************************************
 *
 * Function:      vCCR_SetInputForComplexTimer4
 *
 * Purpose:       Set signal for Complex Timer 4
 *
 * Inputs:        eSource     Source for timer
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_SetInputForComplexTimer4(ccr_tbin_source_ctimer4_e eSource);

/****************************************************************************
 *
 * Function:      vCCR_SetInputForComplexTimer5
 *
 * Purpose:       Set signal for Complex Timer 5
 *
 * Inputs:        eSource     Source for timer
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_SetInputForComplexTimer5(ccr_tbin_source_ctimer5_e eSource);

/****************************************************************************
 *
 * Function:      vCCR_EnableGDC0Interface
 *
 * Purpose:       Enable/disable GDC0 interface
 *
 * Inputs:        eEn     Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_EnableGDC0Interface(ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      vCCR_EnableGDC1Interface
 *
 * Purpose:       Enable/disable GDC1 interface
 *
 * Inputs:        eEn     Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_EnableGDC1Interface(ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      vCCR_EnableGDCPanelInterface
 *
 * Purpose:       Enable/disable GDC panel interface
 *
 * Inputs:        eEn     Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_EnableGDCPanelInterface(ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      vCCR_SetGDCSynchronisation
 *
 * Purpose:       Set synchronisation type between GDC0 and GDC1
 *
 * Inputs:        eGDCSync     GDC synchronisation type
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_SetGDCSynchronisation(ccr_gdc_sync_e eGDCSync);

/****************************************************************************
 *
 * Function:      i32CCR_SetNORAddressMask
 *
 * Purpose:       Set NOR-interface address mask
 *
 * Inputs:        eChannel          NOR-channel
 *                u16AddressMask    Address maks
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetNORAddressMask(ccr_nor_channel_e eChannel, uint16_t u16AddressMask);

/****************************************************************************
 *
 * Function:      i32CCR_SetNORAddressMatch
 *
 * Purpose:       Set NOR-interface address match
 *
 * Inputs:        eChannel          NOR-channel
 *                u16AddressMask    Address match
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetNORAddressMatch(ccr_nor_channel_e eChannel, uint16_t u16AddressMatch);

/****************************************************************************
 *
 * Function:      i32CCR_SetNANDAddressMask
 *
 * Purpose:       Set NAND-interface address mask
 *
 * Inputs:        eChannel          NAND-channel
 *                u16AddressMask    Address maks
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetNANDAddressMask(ccr_nand_channel_e eChannel, uint16_t u16AddressMask);

/****************************************************************************
 *
 * Function:      i32CCR_SetNANDAddressMatch
 *
 * Purpose:       Set NAND-interface address match
 *
 * Inputs:        eChannel          NAND-channel
 *                u16AddressMask    Address match
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetNANDAddressMatch(ccr_nand_channel_e eChannel, uint16_t u16AddressMatch);

/****************************************************************************
 *
 * Function:      vCCR_SetNORChipSelect
 *
 * Purpose:       Set NAND-interface address mask & address match as a word
 *                for channel 0 and 1
 *
 * Inputs:        u32Value:   value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void  vCCR_SetNORChipSelect(uint32_t u32Value);

/****************************************************************************
 *
 * Function:      vCCR_SetNANDChipSelect
 *
 * Purpose:       Set NOR-interface address mask & address match as a word
 *                for channel 0 and 1
 *
 * Inputs:        u32Value:  value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void  vCCR_SetNANDChipSelect(uint32_t u32Value);

/****************************************************************************
 *
 * Function:      i32CCR_EnableSRAMBitErrorInspection
 *
 * Purpose:       Enable or disable SRAM bit error inspection
 *
 * Inputs:        eChannel    SRAM-channel
 *                eEn         Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_EnableSRAMBitErrorInspection(ccr_sram_channel_e eChannel, ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      i32CCR_SetSRAMBitErrorInspectionConfiguration
 *
 * Purpose:       Set SRAM bit error inspection configuration
 *
 * Inputs:        eChannel    SRAM-channel
 *                pstConfig   Pointer to configuration
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetSRAMBitErrorInspectionConfiguration(ccr_sram_channel_e eChannel, ccr_sram_bit_error_insp_config_st * pstConfig);

/****************************************************************************
 *
 * Function:      vCCR_ClearWDTAlarm
 *
 * Purpose:       Clear WDT alarm bit
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_ClearWDTAlarm(void);

/****************************************************************************
 *
 * Function:      vCCR_ClearErrorIrgFlagOfBackupRAM
 *
 * Purpose:       Clear error IRQ flag of Back-up RAM
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_ClearErrorIrgFlagOfBackupRAM(void);

/****************************************************************************
 *
 * Function:      vCCR_ClearWarningIrgFlagOfBackupRAM
 *
 * Purpose:       Clear warning IRQ flag of Back-up RAM
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_ClearWarningIrgFlagOfBackupRAM(void);

/****************************************************************************
 *
 * Function:      i32CCR_ClearErrorIrgFlagOfSRAM
 *
 * Purpose:       Clear error IRQ flag of SRAM
 *
 * Inputs:        eChannel    SRAM-channel
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_ClearErrorIrgFlagOfSRAM(ccr_sram_channel_e eChannel);

/****************************************************************************
 *
 * Function:      i32CCR_ClearWarningIrgFlagOfSRAM
 *
 * Purpose:       Clear warning IRQ flag of SRAM
 *
 * Inputs:        eChannel    SRAM-channel
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_ClearWarningIrgFlagOfSRAM(ccr_sram_channel_e eChannel);

/****************************************************************************
 *
 * Function:      i32CCR_IssueSynchronPulseToCTimer
 *
 * Purpose:       Issue synchronous pulse to complex timer 0 to 5 or  to 9
 *
 * Inputs:        eComplexTimer    Complex timers
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_IssueSynchronPulseToCTimer(ccr_complex_timer_e eComplexTimer);

/****************************************************************************
 *
 * Function:      eCCR_GetWDTAlarmStatusBit
 *
 * Purpose:       Get WDT alarm status bit
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Enable or disable
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GetWDTAlarmStatusBit(void);

/****************************************************************************
 *
 * Function:      eCCR_GetIRQErrorFlafForBackupRAM
 *
 * Purpose:       Get IRQ flag for error condition for Back-up RAM
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Enable or disable
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GetIRQErrorFlafForBackupRAM(void);

/****************************************************************************
 *
 * Function:      eCCR_GetIRQWarningFlafForBackupRAM
 *
 * Purpose:       Get IRQ flag for warning condition for Back-up RAM
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Enable or disable
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GetIRQWarningFlafForBackupRAM(void);

/****************************************************************************
 *
 * Function:      u8CCR_GetPosOfBitErrorInBackupRAM
 *
 * Purpose:       Get position of bit error for Back-up RAM
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Enable or disable
 *
 * Limitations:
 *
 ***************************************************************************/
uint8_t u8CCR_GetPosOfBitErrorInBackupRAM(void);

/****************************************************************************
 *
 * Function:      eCCR_GetLastCheckResultForBackupRAM
 *
 * Purpose:       Get last check result for Back-up RAM
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Enable or disable
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GetLastCheckResultForBackupRAM(void);

/****************************************************************************
 *
 * Function:      eCCR_GetDebuggerCR4PowerDownRequestStatus
 *
 * Purpose:       Get status of debugger CR4 power down request
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Status
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GetDebuggerCR4PowerDownRequestStatus(void);

/****************************************************************************
 *
 * Function:      i32CCR_GetSRAMIrgErrorCondition
 *
 * Purpose:       Get IRQ flag error condition for SRAM
 *
 * Inputs:        eChannel    SRAM-channel
 *                peEn        Pointer to bit result
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_GetSRAMIrgErrorCondition(ccr_sram_channel_e eChannel, ccr_enable_e * peEn);

/****************************************************************************
 *
 * Function:      i32CCR_GetSRAMIrgWarningCondition
 *
 * Purpose:       Get IRQ flag warning condition for SRAM
 *
 * Inputs:        eChannel    SRAM-channel
 *                peEn        Pointer to bit result
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_GetSRAMIrgWarningCondition(ccr_sram_channel_e eChannel, ccr_enable_e * peEn);

/****************************************************************************
 *
 * Function:      i32CCR_GetSRAMPositionOfBitError
 *
 * Purpose:       Get position of bit error for SRAM
 *
 * Inputs:        eChannel      SRAM-channel
 *                pu8Position   Pointer to position
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_GetSRAMPositionOfBitError(ccr_sram_channel_e eChannel, uint8_t * pu8Position);

/****************************************************************************
 *
 * Function:      i32CCR_GetSRAMLastCheckResult
 *
 * Purpose:       Get last check result for SRAM
 *
 * Inputs:        eChannel    SRAM-channel
 *                peEn        Pointer to bit result
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_GetSRAMLastCheckResult(ccr_sram_channel_e eChannel, ccr_enable_e * peEn);

/****************************************************************************
 *
 * Function:      eCCR_GetDeviceVersion
 *
 * Purpose:       Read device version
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: device version
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_device_version_e eCCR_GetDeviceVersion(void);

/****************************************************************************
 *
 * Function:      eCCR_GetSIPFlashSize
 *
 * Purpose:       Read size of SIP flash
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: SIP flash size
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_SIPflash_size_e eCCR_GetSIPFlashSize(void);

/****************************************************************************
 *
 * Function:      eCCR_GeCR4DebugStatus
 *
 * Purpose:       Provides information about the availability of the debug port.
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: CCR_DISABLE - Debug Port DISABLED
 *                CCR_ENABLE  - Debug Port ENABLED
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GeCR4DebugStatus(void);

/****************************************************************************
 *
 * Function:      i32CCR_EnableR4DebugPort
 *
 * Purpose:       Enable or disable debug port of processors
 *
 * Inputs:        eProcessorType     Processor type
 *                eEn                Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_EnableR4DebugPort(ccr_processor_device_e eProcessorType, ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      i32CCR_SetVRegCurrentTrim
 *
 * Purpose:       Set voltage regulator current trim value
 *
 * Inputs:        eValue     voltage regulator current trim value
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetVRegCurrentTrim(ccr_vreg_current_trim_e eValue);

/****************************************************************************
 *
 * Function:      i32CCR_SetVRegRefVoltageTrim
 *
 * Purpose:       Set voltage regulator reference voltage trim value
 *
 * Inputs:        eValue     voltage regulator reference voltage trim value
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetVRegRefVoltageTrim(ccr_vreg_ref_voltage_trim_e eValue);

/****************************************************************************
 *
 * Function:      i32CCR_SetVRegTemperatureTrim
 *
 * Purpose:       Set voltage regulator temperature trim value
 *
 * Inputs:        eValue     voltage regulator temperature trim value
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetVRegTemperatureTrim(ccr_vreg_temperature_trim_e eValue);

/****************************************************************************
 *
 * Function:      i32CCR_SetOscAdjustment
 *
 * Purpose:       Set oscillator adjustment value
 *
 * Inputs:        eValue     oscillator adjustment value
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetOscAdjustment(ccr_osc_adjustment_e eValue);

/****************************************************************************
 *
 * Function:      i32CCR_SetThresholdPowerGoodSensing
 *
 * Purpose:       Set threshold for power good sensing
 *
 * Inputs:        eValue     threshold for power good sensing
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetThresholdPowerGoodSensing(ccr_threshold_power_good_sensing_e eValue);

/****************************************************************************
 *
 * Function:      i32CCR_SetAlarmComparatorThreshold
 *
 * Purpose:       Set alarm comparator threshold for Alarm 0 or 1
 *
 * Inputs:        eAlarmNo :  alarm comparator 0 or 1
 *                u8Value     alarm comparator threshold setting (0..31)
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetAlarmComparatorThreshold(ccr_alarm_no_e eAlarmNo, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      vCCR_EnableAlarm
 *
 * Purpose:       Enables/Disables CCR alarm comparator
 *
 * Inputs:        eAlarmNo :  alarm comparator 0 or 1
 *                eEn      :  enable/disbale alarm
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_EnableAlarm(ccr_alarm_no_e eAlarmNo, ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      i32CCR_EnableClockSupervisor
 *
 * Purpose:       Enable/disable clock supervisor
 *
 * Inputs:        eClocks    clock type
 *                eEN        enable or disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_EnableClockSupervisor(ccr_clocks_e eClocks, ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      vCCR_EnableOSC10MClockSupervisorOutputResetFunction
 *
 * Purpose:       Enable/disable OSC10M clock supervisor output reset function
 *
 * Inputs:        eEN     enable or disable
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_EnableOSC10MClockSupervisorOutputResetFunction(ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      vCCR_EnableOSC32KHz
 *
 * Purpose:       Enable/disable OSC32KHz
 *
 * Inputs:        eEN     enable or disable
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_EnableOSC32KHz(ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      vCCR_ConfigureSmcIOLevel
 *
 * Purpose:       Set SMC IO level
 *
 * Inputs:        eLevel     SMC IO level
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:
 *
 ***************************************************************************/
void vCCR_ConfigureSmcIOLevel(ccr_smc_io_level_e eLevel);

/****************************************************************************
 *
 * Function:      i32CCR_SetClockStabilizationCompareValue
 *
 * Purpose:       Set Clock Stabilization Compare Value
 *
 * Inputs:        eClocks    clock type
 *                u8Value    clock stabilization compare value
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetClockStabilizationCompareValue(ccr_clocks_e eClocks, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      u16CCR_getBootOptions
 *
 * Purpose:       Read boot options
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Boot options
 *
 * Limitations:
 *
 ***************************************************************************/
uint16_t u16CCR_GetBootOptions(void);

/****************************************************************************
 *
 * Function:      u32CCR_GetSystemIntStatusAll
 *
 * Purpose:       Read interrupt status of all interrupts
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Interrupt status of all interrupts
 *
 * Limitations:
 *
 ***************************************************************************/
uint32_t u32CCR_GetSystemIntStatusAll(void);

/****************************************************************************
 *
 * Function:      eCCR_GetSystemIntStatusSingle
 *
 * Purpose:       Read interrupt status of a singe interrupt
 *
 * Inputs:        eInt    Interrupt
 *
 * Outputs:       none
 *
 * Return Values: enabled or disabled
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GetSystemIntStatusSingle(ccr_system_interrupt_e eInt);

/****************************************************************************
 *
 * Function:      i32CCR_SetClockStabilizationCompareValue
 *
 * Purpose:       Clear interrupt status of a single interrupt
 *
 * Inputs:        eInt    Interrupt
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_ClearSystemIntStatusSingle(ccr_system_interrupt_e eInt);

/****************************************************************************
 *
 * Function:      i32CCR_EnableECCInterrupt
 *
 * Purpose:       Enable ECC interrupt
 *
 * Inputs:        eEccType      ECC type
 *                eEccIntType   ECC inte3rrupt type
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_EnableECCInterrupt(ccr_ecc_e eEccType, ccr_ecc_interrupt_type_e eEccIntType);

/****************************************************************************
 *
 * Function:      u8CCR_GetDeviceModesAll
 *
 * Purpose:       Read all device modes
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
uint8_t u8CCR_GetDeviceModesAll(void);

/****************************************************************************
 *
 * Function:      eCCR_GetDeviceModesSingle
 *
 * Purpose:       read single device mode
 *
 * Inputs:        eMode      Device mode
 *
 * Outputs:       none
 *
 * Return Values: enabled or disabled
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GetDeviceModesSingle(ccr_modes_e eMode);

/****************************************************************************
 *
 * Function:      i32CCR_EnableWakeupSource
 *
 * Purpose:       Enable or disable wakeup source
 *
 * Inputs:        eSource    wakeup source
 *                eEn        enable or disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_EnableWakeupSource(ccr_wakeup_source_e eSource, ccr_enable_e eEn);

/****************************************************************************
 *
 * Function:      i32CCR_SetWakeupAttribute
 *
 * Purpose:       Set wakeup attribute
 *
 * Inputs:        eSource       wakeup source
 *                eAttribute    wakeup attribute
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_SetWakeupAttribute(ccr_wakeup_source_e eSource, ccr_wakeup_attribute_e eAttribute);

/****************************************************************************
 *
 * Function:      u16CCR_GetWakeupSourceInterruptAll
 *
 * Purpose:       Read all wakeup source interrupts
 *
 * Inputs:        eSource       wakeup source
 *
 * Outputs:       none
 *
 * Return Values: wakeup source interrupt status vector
 *
 * Limitations:
 *
 ***************************************************************************/
uint16_t u16CCR_GetWakeupSourceInterruptAll(ccr_wakeup_source_e eSource);

/****************************************************************************
 *
 * Function:      eCCR_GetWakeupSourceInterruptSingle
 *
 * Purpose:       Read single wakeup source interrupts
 *
 * Inputs:        eSource       wakeup source
 *
 * Outputs:       none
 *
 * Return Values: enabled or disabled
 *
 * Limitations:
 *
 ***************************************************************************/
ccr_enable_e eCCR_GetWakeupSourceInterruptSingle(ccr_wakeup_source_e eSource);

/****************************************************************************
 *
 * Function:      i32CCR_ClearWakeupInterruptSource
 *
 * Purpose:       Clear wakeup interrupt source
 *
 * Inputs:        eSource       wakeup source
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32CCR_ClearWakeupInterruptSource(ccr_wakeup_source_e eSource);

/****************************************************************************/


#endif /* CCR_LLDD_H */

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

