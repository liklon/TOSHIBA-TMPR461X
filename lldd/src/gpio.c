/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference General Purpose Input Output Port Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : General Purpose Input Output Port (GPIO)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.21 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/

#include "gpio_io.h"    /* GPIO registers, bits and access macros defintion */
#include "gpio.h"       /* GPIO LLDD definitions */

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_GPIO_C_REVISION     "$Revision: 1.21 $"
#define LLDD_GPIO_C_TAG          "$Name: LLDD_1_6 $"
/*********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error */
  #pragma ghs nowarning 1835  /* Rule 11.4 [A] : allow cast from type "type" to type "type" */

  #pragma ghs nowarning 1849  /* Rule 8.1  [R] : alloww bit operation used in i7o header file */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1752  /* Rule 17.4 [R] : disable  pointer arithmetic not allowed, to use macros of i/o header files */
 #endif


/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_GPIO_C_REVISION[]    = LLDD_GPIO_C_REVISION;
static uint8_t au8LLDD_GPIO_C_TAG[]         = LLDD_GPIO_C_TAG;
static uint8_t au8LLDD_GPIO_H_REVISION[]    = LLDD_GPIO_H_REVISION;
static uint8_t au8LLDD_GPIO_H_TAG[]         = LLDD_GPIO_H_TAG;
static uint8_t au8LLDD_GPIO_IO_H_REVISION[] = LLDD_GPIO_IO_H_REVISION;
static uint8_t au8LLDD_GPIO_IO_H_TAG[]      = LLDD_GPIO_IO_H_TAG;

/*********************************************/

const uint8_t au8PORTRegisterValue[340][3] =
{
                          /* pin                ,reg,bit, latch imp smt pd pu sel  */
    { 0, 0, 0x3F},        /* PORT_DDR_DQ0       ,  0,  0, 0x3F  */
    { 0, 1, 0x3F},        /* PORT_DDR_DQ1       ,  0,  1, 0x3F  */
    { 0, 2, 0x3F},        /* PORT_DDR_DQ2       ,  0,  2, 0x3F  */
    { 0, 3, 0x3F},        /* PORT_DDR_DQ3       ,  0,  3, 0x3F  */
    { 0, 4, 0x3F},        /* PORT_DDR_DQ4       ,  0,  4, 0x3F  */
    { 0, 5, 0x3F},        /* PORT_DDR_DQ5       ,  0,  5, 0x3F  */
    { 0, 6, 0x3F},        /* PORT_DDR_DQ6       ,  0,  6, 0x3F  */
    { 0, 7, 0x3F},        /* PORT_DDR_DQ7       ,  0,  7, 0x3F  */
    { 1, 0, 0x3F},        /* PORT_DDR_DQ8       ,  1,  0, 0x3F  */
    { 1, 1, 0x3F},        /* PORT_DDR_DQ9       ,  1,  1, 0x3F  */
    { 1, 2, 0x3F},        /* PORT_DDR_DQ10      ,  1,  2, 0x3F  */
    { 1, 3, 0x3F},        /* PORT_DDR_DQ11      ,  1,  3, 0x3F  */
    { 1, 4, 0x3F},        /* PORT_DDR_DQ12      ,  1,  4, 0x3F  */
    { 1, 5, 0x3F},        /* PORT_DDR_DQ13      ,  1,  5, 0x3F  */
    { 1, 6, 0x3F},        /* PORT_DDR_DQ14      ,  1,  6, 0x3F  */
    { 1, 7, 0x3F},        /* PORT_DDR_DQ15      ,  1,  7, 0x3F  */
    { 2, 0, 0x3F},        /* PORT_DDR_DM0       ,  2,  0, 0x3F  */
    { 2, 1, 0x3F},        /* PORT_DDR_DM1       ,  2,  1, 0x3F  */
    { 2, 2, 0x3F},        /* PORT_DDR_WE        ,  2,  2, 0x3F  */
    { 2, 3, 0x3F},        /* PORT_DDR_RAS       ,  2,  3, 0x3F  */
    { 2, 4, 0x3F},        /* PORT_DDR_CAS       ,  2,  4, 0x3F  */
    { 2, 5, 0x3F},        /* PORT_DDR_CS        ,  2,  5, 0x3F  */
    { 2, 6, 0x3F},        /* PORT_DDR_CKE       ,  2,  6, 0x3F  */
    {30,32, 0x3E},        /* PORT_DDR_CK        , 30, 32, 0x3E  */
    {30,32, 0x3E},        /* PORT_DDR_CKN       , 30, 32, 0x3E  */
    { 2, 7, 0x3F},        /* PORT_DDR_BA0       ,  2,  7, 0x3F  */
    { 3, 0, 0x3F},        /* PORT_DDR_BA1       ,  3,  0, 0x3F  */
    { 3, 1, 0x3F},        /* PORT_DDR_A0        ,  3,  1, 0x3F  */
    { 3, 2, 0x3F},        /* PORT_DDR_A1        ,  3,  2, 0x3F  */
    { 3, 3, 0x3F},        /* PORT_DDR_A2        ,  3,  3, 0x3F  */
    { 3, 4, 0x3F},        /* PORT_DDR_A3        ,  3,  4, 0x3F  */
    { 3, 5, 0x3F},        /* PORT_DDR_A4        ,  3,  5, 0x3F  */
    { 3, 6, 0x3F},        /* PORT_DDR_A5        ,  3,  6, 0x3F  */
    { 3, 7, 0x3F},        /* PORT_DDR_A6        ,  3,  7, 0x3F  */
    { 4, 0, 0x3F},        /* PORT_DDR_A7        ,  4,  0, 0x3F  */
    { 4, 1, 0x3F},        /* PORT_DDR_A8        ,  4,  1, 0x3F  */
    { 4, 2, 0x3F},        /* PORT_DDR_A9        ,  4,  2, 0x3F  */
    { 4, 3, 0x3F},        /* PORT_DDR_A10       ,  4,  3, 0x3F  */
    { 4, 4, 0x3F},        /* PORT_DDR_A11       ,  4,  4, 0x3F  */
    { 4, 5, 0x3F},        /* PORT_DDR_A12       ,  4,  5, 0x3F  */
    { 4, 6, 0x3F},        /* PORT_DDR_A13       ,  4,  6, 0x3F  */
    { 4, 7, 0x3F},        /* PORT_DDR_DQS0      ,  4,  7, 0x3F  */
    { 5, 0, 0x3F},        /* PORT_DDR_DQS1      ,  5,  0, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_0       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_1       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_2       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_3       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_4       , 30, 32, 0x00  */
    { 5, 1, 0x3F},        /* PORT_DDR_DQS2      ,  5,  1, 0x3F  */
    { 5, 2, 0x3F},        /* PORT_DDR_DQS3      ,  5,  2, 0x3F  */
    { 5, 3, 0x3F},        /* PORT_DDR_DM2       ,  5,  3, 0x3F  */
    { 5, 4, 0x3F},        /* PORT_DDR_DM3       ,  5,  4, 0x3F  */
    { 5, 5, 0x3F},        /* PORT_DDR_DQ16      ,  5,  5, 0x3F  */
    { 5, 6, 0x3F},        /* PORT_DDR_DQ17      ,  5,  6, 0x3F  */
    { 5, 7, 0x3F},        /* PORT_DDR_DQ18      ,  5,  7, 0x3F  */
    { 6, 0, 0x3F},        /* PORT_DDR_DQ19      ,  6,  0, 0x3F  */
    { 6, 1, 0x3F},        /* PORT_DDR_DQ20      ,  6,  1, 0x3F  */
    { 6, 2, 0x3F},        /* PORT_DDR_DQ21      ,  6,  2, 0x3F  */
    { 6, 3, 0x3F},        /* PORT_DDR_DQ22      ,  6,  3, 0x3F  */
    { 6, 4, 0x3F},        /* PORT_DDR_DQ23      ,  6,  4, 0x3F  */
    { 6, 5, 0x3F},        /* PORT_DDR_DQ24      ,  6,  5, 0x3F  */
    { 6, 6, 0x3F},        /* PORT_DDR_DQ25      ,  6,  6, 0x3F  */
    { 6, 7, 0x3F},        /* PORT_DDR_DQ26      ,  6,  7, 0x3F  */
    { 7, 0, 0x3F},        /* PORT_DDR_DQ27      ,  7,  0, 0x3F  */
    { 7, 1, 0x3F},        /* PORT_DDR_DQ28      ,  7,  1, 0x3F  */
    { 7, 2, 0x3F},        /* PORT_DDR_DQ29      ,  7,  2, 0x3F  */
    { 7, 3, 0x3F},        /* PORT_DDR_DQ30      ,  7,  3, 0x3F  */
    { 7, 4, 0x3F},        /* PORT_DDR_DQ31      ,  7,  4, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_5       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_6       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_7       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_8       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_9       , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_10      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_11      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_12      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_13      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_14      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_15      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_16      , 30, 32, 0x00  */
    { 8, 0, 0x3F},        /* PORT_QSPI0_SIO0    ,  8,  0, 0x3F  */
    { 8, 1, 0x3F},        /* PORT_QSPI0_SIO1    ,  8,  1, 0x3F  */
    { 8, 2, 0x3F},        /* PORT_QSPI0_SIO2    ,  8,  2, 0x3F  */
    { 8, 3, 0x3F},        /* PORT_QSPI0_SIO3    ,  8,  3, 0x3F  */
    { 8, 4, 0x3F},        /* PORT_QSPI0_CS0     ,  8,  4, 0x3F  */
    { 8, 5, 0x3F},        /* PORT_QSPI0_SCLK    ,  8,  5, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_17      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_18      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_19      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_20      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_21      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_22      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_23      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_24      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_25      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_26      , 30, 32, 0x00  */
    { 9, 0, 0x3F},        /* PORT_D0HDISP       ,  9,  0, 0x3F  */
    { 9, 1, 0x3F},        /* PORT_D0HSYNC       ,  9,  1, 0x3F  */
    { 9, 2, 0x3F},        /* PORT_D0VSYNC       ,  9,  2, 0x3F  */
    { 9, 3, 0x3F},        /* PORT_D0DOTCLK      ,  9,  3, 0x3F  */
    { 9, 4, 0x3F},        /* PORT_D0RGB0        ,  9,  4, 0x3F  */
    { 9, 5, 0x3F},        /* PORT_D0RGB1        ,  9,  5, 0x3F  */
    { 9, 6, 0x3F},        /* PORT_D0RGB2        ,  9,  6, 0x3F  */
    { 9, 7, 0x3F},        /* PORT_D0RGB3        ,  9,  7, 0x3F  */
    {10, 0, 0x3F},        /* PORT_D0RGB4        , 10,  0, 0x3F  */
    {10, 1, 0x3F},        /* PORT_D0RGB5        , 10,  1, 0x3F  */
    {10, 2, 0x3F},        /* PORT_D0RGB6        , 10,  2, 0x3F  */
    {10, 3, 0x3F},        /* PORT_D0RGB7        , 10,  3, 0x3F  */
    {10, 4, 0x3F},        /* PORT_D0RGB8        , 10,  4, 0x3F  */
    {10, 5, 0x3F},        /* PORT_D0RGB9        , 10,  5, 0x3F  */
    {10, 6, 0x3F},        /* PORT_D0RGB10       , 10,  6, 0x3F  */
    {10, 7, 0x3F},        /* PORT_D0RGB11       , 10,  7, 0x3F  */
    {11, 0, 0x3F},        /* PORT_D0RGB12       , 11,  0, 0x3F  */
    {11, 1, 0x3F},        /* PORT_D0RGB13       , 11,  1, 0x3F  */
    {11, 2, 0x3F},        /* PORT_D0RGB14       , 11,  2, 0x3F  */
    {11, 3, 0x3F},        /* PORT_D0RGB15       , 11,  3, 0x3F  */
    {11, 4, 0x3F},        /* PORT_D0RGB16       , 11,  4, 0x3F  */
    {11, 5, 0x3F},        /* PORT_D0RGB17       , 11,  5, 0x3F  */
    {11, 6, 0x3F},        /* PORT_D0RGB18       , 11,  6, 0x3F  */
    {11, 7, 0x3F},        /* PORT_D0RGB19       , 11,  7, 0x3F  */
    {12, 0, 0x3F},        /* PORT_D0RGB20       , 12,  0, 0x3F  */
    {12, 1, 0x3F},        /* PORT_D0RGB21       , 12,  1, 0x3F  */
    {12, 2, 0x3F},        /* PORT_D0RGB22       , 12,  2, 0x3F  */
    {12, 3, 0x3F},        /* PORT_D0RGB23       , 12,  3, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_27      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_28      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_29      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_30      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_31      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_32      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_33      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_34      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_35      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_36      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_37      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_38      , 30, 32, 0x00  */
    {13, 0, 0x3F},        /* PORT_DOTCLKIN      , 13,  0, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_39      , 30, 32, 0x00  */
    {30,32, 0x3F},        /* PORT_PNLGPP0       , 30, 32, 0x3F  */
    {30,32, 0x3F},        /* PORT_PNLGPP1       , 30, 32, 0x3F  */
    {30,32, 0x3F},        /* PORT_PNLGPP2       , 30, 32, 0x3F  */
    {30,32, 0x3F},        /* PORT_PNLGPP3       , 30, 32, 0x3F  */
    {13, 1, 0x3F},        /* PORT_PNLGPP4       , 13,  1, 0x3F  */
    {13, 2, 0x3F},        /* PORT_PNLGPP5       , 13,  2, 0x3F  */
    {13, 3, 0x3F},        /* PORT_PNLGPP6       , 13,  3, 0x3F  */
    {13, 4, 0x3F},        /* PORT_PNLGPP7       , 13,  4, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_40      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_41      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_42      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_43      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_44      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_45      , 30, 32, 0x00  */
    {14, 0, 0x3F},        /* PORT_D1HDISP       , 14,  0, 0x3F  */
    {14, 1, 0x3F},        /* PORT_D1HSYNC       , 14,  1, 0x3F  */
    {14, 2, 0x3F},        /* PORT_D1VSYNC       , 14,  2, 0x3F  */
    {14, 3, 0x3F},        /* PORT_D1DOTCLK      , 14,  3, 0x3F  */
    {14, 4, 0x3F},        /* PORT_D1RGB0        , 14,  4, 0x3F  */
    {14, 5, 0x3F},        /* PORT_D1RGB1        , 14,  5, 0x3F  */
    {14, 6, 0x3F},        /* PORT_D1RGB2        , 14,  6, 0x3F  */
    {14, 7, 0x3F},        /* PORT_D1RGB3        , 14,  7, 0x3F  */
    {15, 0, 0x3F},        /* PORT_D1RGB4        , 15,  0, 0x3F  */
    {15, 1, 0x3F},        /* PORT_D1RGB5        , 15,  1, 0x3F  */
    {15, 2, 0x3F},        /* PORT_D1RGB6        , 15,  2, 0x3F  */
    {15, 3, 0x3F},        /* PORT_D1RGB7        , 15,  3, 0x3F  */
    {15, 4, 0x3F},        /* PORT_D1RGB8        , 15,  4, 0x3F  */
    {15, 5, 0x3F},        /* PORT_D1RGB9        , 15,  5, 0x3F  */
    {15, 6, 0x3F},        /* PORT_D1RGB10       , 15,  6, 0x3F  */
    {15, 7, 0x3F},        /* PORT_D1RGB11       , 15,  7, 0x3F  */
    {16, 0, 0x3F},        /* PORT_D1RGB12       , 16,  0, 0x3F  */
    {16, 1, 0x3F},        /* PORT_D1RGB13       , 16,  1, 0x3F  */
    {16, 2, 0x3F},        /* PORT_D1RGB14       , 16,  2, 0x3F  */
    {16, 3, 0x3F},        /* PORT_D1RGB15       , 16,  3, 0x3F  */
    {16, 4, 0x3F},        /* PORT_D1RGB16       , 16,  4, 0x3F  */
    {16, 5, 0x3F},        /* PORT_D1RGB17       , 16,  5, 0x3F  */
    {16, 6, 0x3F},        /* PORT_D1RGB18       , 16,  6, 0x3F  */
    {16, 7, 0x3F},        /* PORT_D1RGB19       , 16,  7, 0x3F  */
    {17, 0, 0x3F},        /* PORT_D1RGB20       , 17,  0, 0x3F  */
    {17, 1, 0x3F},        /* PORT_D1RGB21       , 17,  1, 0x3F  */
    {17, 2, 0x3F},        /* PORT_D1RGB22       , 17,  2, 0x3F  */
    {17, 3, 0x3F},        /* PORT_D1RGB23       , 17,  3, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_46      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_47      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_48      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_49      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_50      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_51      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_52      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_53      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_54      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_55      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_56      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_57      , 30, 32, 0x00  */
    {18, 0, 0x3F},        /* PORT_CMCBCR0       , 18,  0, 0x3F  */
    {18, 1, 0x3F},        /* PORT_CMCBCR1       , 18,  1, 0x3F  */
    {18, 2, 0x3F},        /* PORT_CMCBCR2       , 18,  2, 0x3F  */
    {18, 3, 0x3F},        /* PORT_CMCBCR3       , 18,  3, 0x3F  */
    {18, 4, 0x3F},        /* PORT_CMCBCR4       , 18,  4, 0x3F  */
    {18, 5, 0x3F},        /* PORT_CMCBCR5       , 18,  5, 0x3F  */
    {18, 6, 0x3F},        /* PORT_CMCBCR6       , 18,  6, 0x3F  */
    {18, 7, 0x3F},        /* PORT_CMCBCR7       , 18,  7, 0x3F  */
    {19, 0, 0x3F},        /* PORT_CMCLK         , 19,  0, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_58      , 30, 32, 0x00  */
    {19, 1, 0x3F},        /* PORT_CMFOOD        , 19,  1, 0x3F  */
    {19, 2, 0x3F},        /* PORT_CMHDISP       , 19,  2, 0x3F  */
    {19, 3, 0x3F},        /* PORT_CMHSYNC       , 19,  3, 0x3F  */
    {19, 4, 0x3F},        /* PORT_CMVSYNC       , 19,  4, 0x3F  */
    {19, 5, 0x3F},        /* PORT_CMY0          , 19,  5, 0x3F  */
    {19, 6, 0x3F},        /* PORT_CMY1          , 19,  6, 0x3F  */
    {19, 7, 0x3F},        /* PORT_CMY2          , 19,  7, 0x3F  */
    {20, 0, 0x3F},        /* PORT_CMY3          , 20,  0, 0x3F  */
    {20, 1, 0x3F},        /* PORT_CMY4          , 20,  1, 0x3F  */
    {20, 2, 0x3F},        /* PORT_CMY5          , 20,  2, 0x3F  */
    {20, 3, 0x3F},        /* PORT_CMY6          , 20,  3, 0x3F  */
    {20, 4, 0x3F},        /* PORT_CMY7          , 20,  4, 0x3F  */
    {20, 5, 0x3F},        /* PORT_CMRGB0        , 20,  5, 0x3F  */
    {20, 6, 0x3F},        /* PORT_CMRGB1        , 20,  6, 0x3F  */
    {20, 7, 0x3F},        /* PORT_CMRGB2        , 20,  7, 0x3F  */
    {21, 0, 0x3F},        /* PORT_CMRGB3        , 21,  0, 0x3F  */
    {21, 1, 0x3F},        /* PORT_CMRGB4        , 21,  1, 0x3F  */
    {21, 2, 0x3F},        /* PORT_CMRGB5        , 21,  2, 0x3F  */
    {21, 3, 0x3F},        /* PORT_CMRGB6        , 21,  3, 0x3F  */
    {21, 4, 0x3F},        /* PORT_CMRGB7        , 21,  4, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_59      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_60      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_61      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_62      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_63      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_64      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_65      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_66      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_67      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_68      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_69      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_70      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_71      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_72      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_73      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_74      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_75      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_76      , 30, 32, 0x00  */
    {22, 0, 0x3F},        /* PORT_I2CCLK        , 22,  0, 0x3F  */
    {22, 1, 0x3F},        /* PORT_I2CDATA       , 22,  1, 0x3F  */
    {22, 2, 0x27},        /* PORT_CANRX0        , 22,  2, 0x27  */
    {22, 3, 0x3F},        /* PORT_CANTX0        , 22,  3, 0x3F  */
    {22, 4, 0x27},        /* PORT_CANRX1        , 22,  4, 0x27  */
    {22, 5, 0x3F},        /* PORT_CANTX1        , 22,  5, 0x3F  */
    {30,32, 0x3E},        /* PORT_MLBDAT_IO     , 30, 32, 0x3E  */
    {30,32, 0x3E},        /* PORT_MLBSIG_IO     , 30, 32, 0x3E  */
    {30,32, 0x2E},        /* PORT_MLBCLK        , 30, 32, 0x2E  */
    {30,32, 0x00},        /* PORT_DUMMY_77      , 30, 32, 0x00  */
    {23, 0, 0x27},        /* PORT_ESEI0MISO     , 23,  0, 0x27  */
    {23, 1, 0x27},        /* PORT_ESEI0MOSI     , 23,  1, 0x27  */
    {23, 2, 0x27},        /* PORT_ESEI0SCLK     , 23,  2, 0x27  */
    {23, 3, 0x27},        /* PORT_ESEI0SSOI     , 23,  3, 0x27  */
    {23, 4, 0x3F},        /* PORT_I2S0CLK       , 23,  4, 0x3F  */
    {23, 5, 0x3F},        /* PORT_I2S0WS        , 23,  5, 0x3F  */
    {23, 6, 0x3F},        /* PORT_I2S0SD        , 23,  6, 0x3F  */
    {23, 7, 0x3F},        /* PORT_I2SMCLK       , 23,  7, 0x3F  */
    {24, 0, 0x3F},        /* PORT_PWMOUT00      , 24,  0, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_78      , 30, 32, 0x00  */
    {24, 1, 0x3F},        /* PORT_HSPWM0        , 24,  1, 0x3F  */
    {24, 2, 0x3F},        /* PORT_HSPWM0N       , 24,  2, 0x3F  */
    {24, 3, 0x3F},        /* PORT_HSPWM1        , 24,  3, 0x3F  */
    {24, 4, 0x3F},        /* PORT_HSPWM1N       , 24,  4, 0x3F  */
    {24, 5, 0x3F},        /* PORT_UART0RX       , 24,  5, 0x3F  */
    {24, 6, 0x3F},        /* PORT_UART0TX       , 24,  6, 0x3F  */
    {30,32, 0x00},        /* PORT_DUMMY_79      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_80      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_81      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_82      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_83      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_84      , 30, 32, 0x00  */
    {30,32, 0x3E},        /* PORT_SIP_QSPI_SIO0 , 30, 32, 0x3E  */
    {30,32, 0x3E},        /* PORT_SIP_QSPI_SIO1 , 30, 32, 0x3E  */
    {30,32, 0x3E},        /* PORT_SIP_QSPI_SIO2 , 30, 32, 0x3E  */
    {30,32, 0x3E},        /* PORT_SIP_QSPI_SIO3 , 30, 32, 0x3E  */
    {30,32, 0x3E},        /* PORT_SIP_QSPI_CS   , 30, 32, 0x3E  */
    {30,32, 0x3E},        /* PORT_SIP_QSPI_SCLK , 30, 32, 0x3E  */
    {30,32, 0x00},        /* PORT_DUMMY_85      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_86      , 30, 32, 0x00  */
    {30,32, 0x2E},        /* PORT_NMI           , 30, 32, 0x2E  */
    {30,32, 0x2E},        /* PORT_RESETN        , 30, 32, 0x2E  */
    {30,32, 0x2E},        /* PORT_DSU_JTAG_SEL  , 30, 32, 0x2E  */
    {30,32, 0x2E},        /* PORT_DSU_GTCK      , 30, 32, 0x2E  */
    {30,32, 0x2E},        /* PORT_DSU_GTDI      , 30, 32, 0x2E  */
    {30,32, 0x1E},        /* PORT_DSU_GTMS      , 30, 32, 0x1E  */
    {30,32, 0x2E},        /* PORT_DSU_GTRST     , 30, 32, 0x2E  */
    {30,32, 0x1E},        /* PORT_DSU_TPC0_GTDO , 30, 32, 0x1E  */
    {30,32, 0x00},        /* PORT_DUMMY_87      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_88      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_89      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_90      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_91      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_92      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_93      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_94      , 30, 32, 0x00  */
    {25, 0, 0x2F},        /* PORT_ADC_IN0       , 25,  0, 0x2F  */
    {25, 1, 0x2F},        /* PORT_ADC_IN1       , 25,  1, 0x2F  */
    {25, 2, 0x2F},        /* PORT_ADC_IN2       , 25,  2, 0x2F  */
    {25, 3, 0x2F},        /* PORT_ADC_IN3       , 25,  3, 0x2F  */
    {25, 4, 0x2F},        /* PORT_ADC_IN4       , 25,  4, 0x2F  */
    {25, 5, 0x2F},        /* PORT_ADC_IN5       , 25,  5, 0x2F  */
    {25, 6, 0x2F},        /* PORT_ADC_IN6       , 25,  6, 0x2F  */
    {25, 7, 0x2F},        /* PORT_ADC_IN7       , 25,  7, 0x2F  */
    {26, 0, 0x2E},        /* PORT_ADC_IN8       , 26,  0, 0x2E  */
    {26, 1, 0x2E},        /* PORT_ADC_IN9       , 26,  1, 0x2E  */
    {26, 2, 0x2E},        /* PORT_ADC_IN10      , 26,  2, 0x2E  */
    {26, 3, 0x2E},        /* PORT_ADC_IN11      , 26,  3, 0x2E  */
    {26, 4, 0x2E},        /* PORT_ADC_IN12      , 26,  4, 0x2E  */
    {26, 5, 0x2E},        /* PORT_ADC_IN13      , 26,  5, 0x2E  */
    {30,32, 0x00},        /* PORT_DUMMY_95      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_96      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_97      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_98      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_99      , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_100     , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_101     , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_102     , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_103     , 30, 32, 0x00  */
    {30,32, 0x00},        /* PORT_DUMMY_104     , 30, 32, 0x00  */
    {27, 0, 0x01},        /* PORT_SC0_C0_LEFT   , 27,  0, 0x01  */
    {27, 1, 0x01},        /* PORT_SC0_C0_RIGHT  , 27,  1, 0x01  */
    {27, 2, 0x01},        /* PORT_SC0_C1_LEFT   , 27,  2, 0x01  */
    {27, 3, 0x01},        /* PORT_SC0_C1_RIGHT  , 27,  3, 0x01  */
    {27, 4, 0x01},        /* PORT_SC1_C0_LEFT   , 27,  4, 0x01  */
    {27, 5, 0x01},        /* PORT_SC1_C0_RIGHT  , 27,  5, 0x01  */
    {27, 6, 0x01},        /* PORT_SC1_C1_LEFT   , 27,  6, 0x01  */
    {27, 7, 0x01},        /* PORT_SC1_C1_RIGHT  , 27,  7, 0x01  */
    {28, 0, 0x01},        /* PORT_SC2_C0_LEFT   , 28,  0, 0x01  */
    {28, 1, 0x01},        /* PORT_SC2_C0_RIGHT  , 28,  1, 0x01  */
    {28, 2, 0x01},        /* PORT_SC2_C1_LEFT   , 28,  2, 0x01  */
    {28, 3, 0x01},        /* PORT_SC2_C1_RIGHT  , 28,  3, 0x01  */
    {28, 4, 0x01},        /* PORT_SC3_C0_LEFT   , 28,  4, 0x01  */
    {28, 5, 0x01},        /* PORT_SC3_C0_RIGHT  , 28,  5, 0x01  */
    {28, 6, 0x01},        /* PORT_SC3_C1_LEFT   , 28,  6, 0x01  */
    {28, 7, 0x01},        /* PORT_SC3_C1_RIGHT  , 28,  7, 0x01  */
    {29, 0, 0x01},        /* PORT_SC4_C0_LEFT   , 29,  0, 0x01  */
    {29, 1, 0x01},        /* PORT_SC4_C0_RIGHT  , 29,  1, 0x01  */
    {29, 2, 0x01},        /* PORT_SC4_C1_LEFT   , 29,  2, 0x01  */
    {29, 3, 0x01}         /* PORT_SC4_C1_RIGHT  , 29,  3, 0x01  */
};

/**********************************************
*        Exported function definition         *
**********************************************/

void vGPIO_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_GPIO_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_GPIO_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_GPIO_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_GPIO_H_TAG[0];
   *pau8IORevision     = &au8LLDD_GPIO_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_GPIO_IO_H_TAG[0];
}


/****************************************************************************/
int32_t i32GPIO_EnablePullUp(gpio_portpin_e ePin, gpio_en_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    if(ePin <= PORT_ADC_IN13) 
    {
        /* check if feature available */
        if ((au8PORTRegisterValue[ePin][2] & 0x02U) > 0)
        {
            if (eEn == GPIO_ENABLE)
            {
                vSetGPIO_GPIOC_PU(ePin, GPIO_ENABLE);
                vSetGPIO_GPIOC_PD(ePin, GPIO_DISABLE);
            }
            else
            {
                vSetGPIO_GPIOC_PU(ePin, GPIO_DISABLE);
                vSetGPIO_GPIOC_PD(ePin, GPIO_DISABLE);
            }
        }
        else
        {
            i32Res = C_FAILED;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_EnablePullDown(gpio_portpin_e ePin, gpio_en_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    if(ePin <= PORT_ADC_IN13) 
    {
        /* check if feature available */
        if ((au8PORTRegisterValue[ePin][2] & 0x04U) > 0)
        {
            if (eEn == GPIO_ENABLE)
            {
                vSetGPIO_GPIOC_PU(ePin, GPIO_DISABLE);
                vSetGPIO_GPIOC_PD(ePin, GPIO_ENABLE);
            }
            else
            {
                vSetGPIO_GPIOC_PU(ePin, GPIO_DISABLE);
                vSetGPIO_GPIOC_PD(ePin, GPIO_DISABLE);
            }
        }
        else
        {
            i32Res = C_FAILED;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_EnableSchmittTrigger(gpio_portpin_e ePin, gpio_en_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    if(ePin <= PORT_ADC_IN13) 
    {
        /* check if feature available */
        if ((au8PORTRegisterValue[ePin][2] & 0x08U) > 0)
        {
            vSetGPIO_GPIOC_SMT(ePin, eEn);
        }
        else
        {
            i32Res = C_FAILED;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_SetOutputResistance(gpio_portpin_e ePin, gpio_output_resistance_e eOutputResistance)
{
    int32_t i32Res = C_SUCCESS;

    if(ePin < PORT_ADC_IN13) 
    {
        /* check if feature available */
        if ((au8PORTRegisterValue[ePin][2] & 0x10U) > 0)
        {
            vSetGPIO_GPIOC_IMP(ePin, eOutputResistance);
        }
        else
        {
            i32Res = C_FAILED;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_EnableLatchFunction(gpio_portpin_e ePin, gpio_en_e eEn)
{
    int32_t  i32Res = C_SUCCESS;
    uint32_t u32Channel;

    if(ePin <= PORT_ADC_IN13) 
    {
        /* check if feature available */
        if ((au8PORTRegisterValue[ePin][2] & 0x20U) > 0)
        {
            if (eEn == GPIO_ENABLE)
            {
                vSetGPIO_GPIOC_LATCH(ePin, GPIO_DISABLE);
            }
            else
            {
                vSetGPIO_GPIOC_LATCH(ePin, GPIO_ENABLE);
            }
        }
        else
        {
            i32Res = C_FAILED;
        }
    }
    else
    {
        if (ePin <= PORT_SC4_C1_RIGHT)
        {
            /* calculate SMC channel */
            u32Channel = ((uint32_t)ePin - (uint32_t)PORT_SC0_C0_LEFT) / 4;

            if (eEn == GPIO_ENABLE)
            {
                vSetSC_LATCHN(u32Channel, GPIO_DISABLE);
            }
            else
            {
                vSetSC_LATCHN(u32Channel, GPIO_ENABLE);
            }
        }
        else
        {
            i32Res = C_FAILED;
        }
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_EnableSMCMacro(gpio_smcmacro_e eSMCMacro, gpio_en_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    if (eSMCMacro <= GPIO_SMC_MACRO_4) 
    {
        vSetSC_PWDN(eSMCMacro, eEn);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_SetPinFunction(gpio_portpin_e ePin, uint8_t u8PinFunction)
{
    int32_t i32Res = C_SUCCESS;
    uint32_t u32Pin;
    uint32_t u32Channel;

    if (ePin <= PORT_ADC_IN13) 
    {
        /* check if function available */
        if ((au8PORTRegisterValue[ePin][2] & 0x01U) > 0)
        {
            /* set pin function */
            vSetGPIO_GPIOC_SEL(ePin, u8PinFunction);
        }
        else
        {
            i32Res = C_FAILED;
        }
    }
    else
    {
        if (ePin <= PORT_SC4_C1_RIGHT)
        {
            u32Channel = ((uint32_t)ePin - (uint32_t)PORT_SC0_C0_LEFT) / 4;
            u32Pin = ((uint32_t)ePin - (uint32_t)PORT_SC0_C0_LEFT) % 0x4;

            switch (u32Pin)
            {
                case 0:
                    vSetSC_C0_LEFT_SEL(u32Channel, u8PinFunction);
                    break;
                case 1:
                    vSetSC_C0_RIGHT_SEL(u32Channel, u8PinFunction);
                    break;
                case 2:
                    vSetSC_C1_LEFT_SEL(u32Channel, u8PinFunction);
                    break;
                default:
                    vSetSC_C1_RIGHT_SEL(u32Channel, u8PinFunction);
                    break;
            }
        }
        else
        {
            i32Res = C_FAILED;
        }
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_SetPinDirection(gpio_portpin_e ePin, gpio_direction_e ePinDirection)
{
    int32_t i32Res = C_SUCCESS;
    uint8_t u8Value;
    uint32_t u32PinLocal;

    if (au8PORTRegisterValue[ePin][0] < 30U) 
    {
        u8Value = biGetGPIO_GPIO_DIR(au8PORTRegisterValue[ePin][0]);
        if (ePinDirection == GPIO_INPUT)
        {
            u8Value = u8Value | (1U << au8PORTRegisterValue[ePin][1]);
            vSetGPIO_GPIO_DIR(au8PORTRegisterValue[ePin][0], u8Value);
        }
        else
        {
            /* port can only be changed to output if latchfunction is disabled */
            if (ePin <= PORT_ADC_IN13) 
            {
                if (biGetGPIO_GPIOC_LATCH(ePin) == GPIO_ENABLE)
                {
                    u8Value = u8Value & ~(1U << au8PORTRegisterValue[ePin][1]);
                    vSetGPIO_GPIO_DIR(au8PORTRegisterValue[ePin][0], u8Value);
                }
                else
                {
                    i32Res = C_FAILED;
                }
            }
            else
            {
                if (ePin <= PORT_SC4_C1_RIGHT)
                {
                    u32PinLocal = ((uint32_t)ePin - (uint32_t)PORT_SC0_C0_LEFT) / 0x4;
                    if (biGetSC_LATCHN(u32PinLocal) == GPIO_ENABLE)
                    {
                        u8Value = u8Value & ~(1U << au8PORTRegisterValue[ePin][1]);
                        vSetGPIO_GPIO_DIR(au8PORTRegisterValue[ePin][0], u8Value);
                    }
                    else
                    {
                        i32Res = C_FAILED;
                    }
                }
                else
                {
                    i32Res = C_FAILED;
                }
            }
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_SetPinState(gpio_portpin_e ePin, gpio_state_e ePinState)
{
    int32_t i32Res = C_SUCCESS;
    uint8_t u8Value;

    if (au8PORTRegisterValue[ePin][0] < 30U) 
    {
        u8Value = biGetGPIO_GPIO_WDATA(au8PORTRegisterValue[ePin][0]);
        if (ePinState == GPIO_HIGH)
        {
            u8Value = u8Value | (1U << au8PORTRegisterValue[ePin][1]);
        }
        else
        {
            u8Value = u8Value & ~(1U << au8PORTRegisterValue[ePin][1]);
        }
        vSetGPIO_GPIO_WDATA(au8PORTRegisterValue[ePin][0], u8Value);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_GetPinState(gpio_portpin_e ePin, gpio_state_e * ePinState)
{
    int32_t i32Res = C_SUCCESS;
    uint8_t u8Value;

    if (au8PORTRegisterValue[ePin][0] < 30) 
    {
        u8Value = biGetGPIO_GPIO_RDATA(au8PORTRegisterValue[ePin][0]);
        u8Value = u8Value & (1U << au8PORTRegisterValue[ePin][1]);
        if (u8Value > 0U)
        {
            *ePinState = GPIO_HIGH;
        }
        else
        {
            *ePinState = GPIO_LOW;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GPIO_SelectMemoryInterfaceConfiguration(gpio_mem_config_e eMemConfig)
{
    int32_t i32Res = C_SUCCESS;

    if (eMemConfig <= GPIO_MEM_CONFIG_LPDDR_16) 
    {
        vSetSDRAM_CFG_SDRAM_IF_SEL(eMemConfig);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :   Deactivated:
** |     Not requested Rules: 
** |         Rule 11.3 [A] : No casting between pointer and integral types
** |         Rule 11.4 [A] : No casting between different pointer to object
** |
** |     Requested Rules:
** |         Rule 8.1  [R] : Restrict implicit conversions for integer type expressions:
** |                         Used for asm
** |         Rule 10.1 [R] : Restrict implicit conversions for integer type expressions:
** |                         Used to have access to register bits of I/O header files
** |         Rule 10.3 [R] : Restrict explicit casts for integer type expressions
** |                         Used to have access to register bits of I/O header files
** |         Rule 17.4 [R] : No pointer arithmetic other than array indexing:
** |                         This is necessary to have access to RAM Data
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/
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

