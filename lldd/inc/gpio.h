/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : General Purpose Input Output Port Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : General Purpose Input Output Port (GPIO)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_GPIO_H_REVISION     "$Revision: 1.12 $"
#define LLDD_GPIO_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

#define PORT_DDR_DQ0_AS_GPIO               0
#define PORT_DDR_DQ0_AS_ESEI1MISO          1
#define PORT_DDR_DQ0_AS_PWMOUT00           2

#define PORT_DDR_DQ1_AS_GPIO               0
#define PORT_DDR_DQ1_AS_ESEI1MOSI          1
#define PORT_DDR_DQ1_AS_PWMOUT01           2

#define PORT_DDR_DQ2_AS_GPIO               0
#define PORT_DDR_DQ2_AS_ESEI1SCLK          1
#define PORT_DDR_DQ2_AS_PWMOUT02           2

#define PORT_DDR_DQ3_AS_GPIO               0
#define PORT_DDR_DQ3_AS_ESEI1SSOI          1
#define PORT_DDR_DQ3_AS_PWMOUR03           2

#define PORT_DDR_DQ4_AS_GPIO               0
#define PORT_DDR_DQ4_AS_PWMOUT04           1
#define PORT_DDR_DQ4_AS_TBIO0              2

#define PORT_DDR_DQ5_AS_GPIO               0
#define PORT_DDR_DQ5_AS_PWMOUT05           1
#define PORT_DDR_DQ5_AS_TBIO1              2

#define PORT_DDR_DQ6_AS_GPIO               0
#define PORT_DDR_DQ6_AS_PWMOUT06           1
#define PORT_DDR_DQ6_AS_TBIO2              2

#define PORT_DDR_DQ7_AS_GPIO               0
#define PORT_DDR_DQ7_AS_PWMOUT07           1
#define PORT_DDR_DQ7_AS_TBIO3              2

#define PORT_DDR_DQ8_AS_GPIO               0
#define PORT_DDR_DQ8_AS_PWMOUT08           1
#define PORT_DDR_DQ8_AS_TBIO6              2

#define PORT_DDR_DQ9_AS_GPIO               0
#define PORT_DDR_DQ9_AS_PWMOUT09           1
#define PORT_DDR_DQ9_AS_TBIO7              2

#define PORT_DDR_DQ10_AS_GPIO              0
#define PORT_DDR_DQ10_AS_PWMOUT10          1
#define PORT_DDR_DQ10_AS_TBIO8             2

#define PORT_DDR_DQ11_AS_GPIO              0
#define PORT_DDR_DQ11_AS_PWMOUT11          1
#define PORT_DDR_DQ11_AS_TBIO9             2

#define PORT_DDR_DQ12_AS_GPIO              0
#define PORT_DDR_DQ12_AS_UART0RX           1
#define PORT_DDR_DQ12_AS_PWMOUT12          2

#define PORT_DDR_DQ13_AS_GPIO              0
#define PORT_DDR_DQ13_AS_UART0TX           1
#define PORT_DDR_DQ13_AS_PWMOUT13          2

#define PORT_DDR_DQ14_AS_GPIO              0
#define PORT_DDR_DQ14_AS_UART1RX           1
#define PORT_DDR_DQ14_AS_PWMOUT14          2

#define PORT_DDR_DQ15_AS_GPIO              0
#define PORT_DDR_DQ15_AS_UART1TX           1
#define PORT_DDR_DQ15_AS_PWMOUT15          2

#define PORT_DDR_DM0_AS_GPIO               0
#define PORT_DDR_DM0_AS_PWMOUT16           1

#define PORT_DDR_DM1_AS_GPIO               0
#define PORT_DDR_DM1_AS_PWMOUT17           1

#define PORT_DDR_WE_AS_GPIO                0
#define PORT_DDR_WE_AS_PWMOUT18            1

#define PORT_DDR_RAS_AS_GPIO               0
#define PORT_DDR_RAS_AS_PWMOUT19           1

#define PORT_DDR_CAS_AS_GPIO               0
#define PORT_DDR_CAS_AS_PWMOUT20           1

#define PORT_DDR_CS_AS_GPIO                0
#define PORT_DDR_CS_AS_PWMOUT21            1

#define PORT_DDR_CKE_AS_GPIO               0
#define PORT_DDR_CKE_AS_PWMOUT22           1

#define PORT_DDR_BA0_AS_GPIO               0
#define PORT_DDR_BA0_AS_QSPI1_SCLK         1
#define PORT_DDR_BA0_AS_PWMOUT23           2

#define PORT_DDR_BA1_AS_GPIO               0
#define PORT_DDR_BA1_AS_QSPI1_SIO0         1
#define PORT_DDR_BA1_AS_HSPWM0             2

#define PORT_DDR_A0_AS_GPIO                0
#define PORT_DDR_A0_AS_QSPI1_SIO1          1
#define PORT_DDR_A0_AS_HSPWM0N             2

#define PORT_DDR_A1_AS_GPIO                0
#define PORT_DDR_A1_AS_QSPI1_SIO2          1
#define PORT_DDR_A1_AS_HSPWM1              2

#define PORT_DDR_A2_AS_GPIO                0
#define PORT_DDR_A2_AS_QSPI1_SIO3          1
#define PORT_DDR_A2_AS_HSPWM1N             2

#define PORT_DDR_A3_AS_GPIO                0
#define PORT_DDR_A3_AS_QSPI1_CS0           1
#define PORT_DDR_A3_AS_HSPWM2              2

#define PORT_DDR_A4_AS_GPIO                0
#define PORT_DDR_A4_AS_QSPI1_CS1           1
#define PORT_DDR_A4_AS_HSPWM2N             2

#define PORT_DDR_A5_AS_GPIO                0
#define PORT_DDR_A5_AS_IRQ0                1
#define PORT_DDR_A5_AS_HSPWM3              2

#define PORT_DDR_A6_AS_GPIO                0
#define PORT_DDR_A6_AS_EBIF_AD08           1
#define PORT_DDR_A6_AS_HSPWM3N             2

#define PORT_DDR_A7_AS_GPIO                0
#define PORT_DDR_A7_AS_CMRGB0              1
#define PORT_DDR_A7_AS_EBIF_AD09           2

#define PORT_DDR_A8_AS_GPIO                0
#define PORT_DDR_A8_AS_CMRGB1              1
#define PORT_DDR_A8_AS_EBIF_AD10           2

#define PORT_DDR_A9_AS_GPIO                0
#define PORT_DDR_A9_AS_CMRGB2              1
#define PORT_DDR_A9_AS_EBIF_AD11           2

#define PORT_DDR_A10_AS_GPIO               0
#define PORT_DDR_A10_AS_CMRGB3             1
#define PORT_DDR_A10_AS_EBIF_AD12          2

#define PORT_DDR_A11_AS_GPIO               0
#define PORT_DDR_A11_AS_CMRGB4             1
#define PORT_DDR_A11_AS_EBIF_AD13          2

#define PORT_DDR_A12_AS_GPIO               0
#define PORT_DDR_A12_AS_CMRGB5             1
#define PORT_DDR_A12_AS_EBIF_AD14          2

#define PORT_DDR_A13_AS_GPIO               0
#define PORT_DDR_A13_AS_CMRGB6             1
#define PORT_DDR_A13_AS_EBIF_AD15          2
#define PORT_DDR_A13_AS_IRQ1               3

#define PORT_DDR_DQS0_AS_GPIO              0
#define PORT_DDR_DQS0_AS_GDC0_PWM          1
#define PORT_DDR_DQS0_AS_CMRGB7            2
#define PORT_DDR_DQS0_AS_EBIF_CS1          3
#define PORT_DDR_DQS0_AS_IRQ5              4

#define PORT_DDR_DQS1_AS_GPIO              0
#define PORT_DDR_DQS1_AS_GDC1_PWM          1
#define PORT_DDR_DQS1_AS_CMFOOD            2
#define PORT_DDR_DQS1_AS_IRQ4              3

#define PORT_DDR_DQS2_AS_GPIO              0
#define PORT_DDR_DQS2_AS_CMCBCR0           1
#define PORT_DDR_DQS2_AS_EBIF_AD00         2
#define PORT_DDR_DQS2_AS_NF_DATA0          3
#define PORT_DDR_DQS2_AS_IRQ3              4
#define PORT_DDR_DQS2_AS_PWMOUT04          5
#define PORT_DDR_DQS2_AS_HSPWM1            6

#define PORT_DDR_DQS3_AS_GPIO              0
#define PORT_DDR_DQS3_AS_CMCBCR1           1
#define PORT_DDR_DQS3_AS_EBIF_AD01         2
#define PORT_DDR_DQS3_AS_NF_DATA1          3
#define PORT_DDR_DQS3_AS_IRQ2              4
#define PORT_DDR_DQS3_AS_PWMOUT05          5
#define PORT_DDR_DQS3_AS_HSPWM1N           6

#define PORT_DDR_DM2_AS_GPIO               0
#define PORT_DDR_DM2_AS_D0RGB0             1
#define PORT_DDR_DM2_AS_CMCBCR2            2
#define PORT_DDR_DM2_AS_EBIF_AD02          3
#define PORT_DDR_DM2_AS_NF_DATA2           4
#define PORT_DDR_DM2_AS_PWMOUT06           5

#define PORT_DDR_DM3_AS_GPIO               0
#define PORT_DDR_DM3_AS_D0RGB1             1
#define PORT_DDR_DM3_AS_CMCBCR3            2
#define PORT_DDR_DM3_AS_EBIF_AD03          3
#define PORT_DDR_DM3_AS_NF_DATA3           4
#define PORT_DDR_DM3_AS_PWMOUT07           5

#define PORT_DDR_DQ16_AS_GPIO              0
#define PORT_DDR_DQ16_AS_D0RGB8            1
#define PORT_DDR_DQ16_AS_CMCBCR4           2
#define PORT_DDR_DQ16_AS_EBIF_AD04         3
#define PORT_DDR_DQ16_AS_NF_DATA4          4
#define PORT_DDR_DQ16_AS_PWMOUT08          5

#define PORT_DDR_DQ17_AS_GPIO              0
#define PORT_DDR_DQ17_AS_D0RGB9            1
#define PORT_DDR_DQ17_AS_CMCBCR5           2
#define PORT_DDR_DQ17_AS_EBIF_AD05         3
#define PORT_DDR_DQ17_AS_NF_DATA5          4
#define PORT_DDR_DQ17_AS_PWMOUT09          5

#define PORT_DDR_DQ18_AS_GPIO              0
#define PORT_DDR_DQ18_AS_D0RGB16           1
#define PORT_DDR_DQ18_AS_CMCBCR6           2
#define PORT_DDR_DQ18_AS_EBIF_AD06         3
#define PORT_DDR_DQ18_AS_NF_DATA6          4
#define PORT_DDR_DQ18_AS_PWMOUT10          5

#define PORT_DDR_DQ19_AS_GPIO              0
#define PORT_DDR_DQ19_AS_D0RGB17           1
#define PORT_DDR_DQ19_AS_CMCBCR7           2
#define PORT_DDR_DQ19_AS_EBIF_AD07         3
#define PORT_DDR_DQ19_AS_NF_DATA7          4
#define PORT_DDR_DQ19_AS_PWMOUT11          5

#define PORT_DDR_DQ20_AS_GPIO              0
#define PORT_DDR_DQ20_AS_CMCLK             1
#define PORT_DDR_DQ20_AS_EBIF_ALE          2
#define PORT_DDR_DQ20_AS_NF_ALE            3
#define PORT_DDR_DQ20_AS_PWMOUT12          4

#define PORT_DDR_DQ21_AS_GPIO              0
#define PORT_DDR_DQ21_AS_CMHDISP           1
#define PORT_DDR_DQ21_AS_EBIF_CS0          2
#define PORT_DDR_DQ21_AS_NF_CLE            3
#define PORT_DDR_DQ21_AS_PWMOUT13          4

#define PORT_DDR_DQ22_AS_GPIO              0
#define PORT_DDR_DQ22_AS_CMHSYNC           1
#define PORT_DDR_DQ22_AS_EBIF_OE           2
#define PORT_DDR_DQ22_AS_NF_RE             3
#define PORT_DDR_DQ22_AS_PWMOUT14          4

#define PORT_DDR_DQ23_AS_GPIO              0
#define PORT_DDR_DQ23_AS_CMVSYNC           1
#define PORT_DDR_DQ23_AS_EBIF_WE           2
#define PORT_DDR_DQ23_AS_NF_WE             3
#define PORT_DDR_DQ23_AS_PWMOUT15          4

#define PORT_DDR_DQ24_AS_GPIO              0
#define PORT_DDR_DQ24_AS_CMY0              1
#define PORT_DDR_DQ24_AS_EBIF_AEX0         2
#define PORT_DDR_DQ24_AS_NF_BUSYN          3
#define PORT_DDR_DQ24_AS_PWMOUT16          4

#define PORT_DDR_DQ25_AS_GPIO              0
#define PORT_DDR_DQ25_AS_CMY1              1
#define PORT_DDR_DQ25_AS_EBIF_AEX1         2
#define PORT_DDR_DQ25_AS_NF_CSN            3
#define PORT_DDR_DQ25_AS_PWMOUT17          4

#define PORT_DDR_DQ26_AS_GPIO              0
#define PORT_DDR_DQ26_AS_CMY2              1
#define PORT_DDR_DQ26_AS_EBIF_AEX2         2
#define PORT_DDR_DQ26_AS_NF_CSN2           3
#define PORT_DDR_DQ26_AS_PWMOUT18          4

#define PORT_DDR_DQ27_AS_GPIO              0
#define PORT_DDR_DQ27_AS_CMY3              1
#define PORT_DDR_DQ27_AS_EBIF_AEX3         2
#define PORT_DDR_DQ27_AS_PWMOUT19          3

#define PORT_DDR_DQ28_AS_GPIO              0
#define PORT_DDR_DQ28_AS_CMY4              1
#define PORT_DDR_DQ28_AS_EBIF_AEX4         2
#define PORT_DDR_DQ28_AS_ESEI1MISO         3
#define PORT_DDR_DQ28_AS_PWMOUT20          4

#define PORT_DDR_DQ29_AS_GPIO              0
#define PORT_DDR_DQ29_AS_CMY5              1
#define PORT_DDR_DQ29_AS_EBIF_AEX5         2
#define PORT_DDR_DQ29_AS_ESEI1MOSI         3
#define PORT_DDR_DQ29_AS_PWMOUT21          4

#define PORT_DDR_DQ30_AS_GPIO              0
#define PORT_DDR_DQ30_AS_CMY6              1
#define PORT_DDR_DQ30_RESERVED             2
#define PORT_DDR_DQ30_AS_ESEI1_SCLK        3
#define PORT_DDR_DQ30_AS_PWMOUT22          4

#define PORT_DDR_DQ31_AS_GPIO              0
#define PORT_DDR_DQ31_AS_CMY7              1
#define PORT_DDR_DQ31_AS_ESEI1SSOI         2
#define PORT_DDR_DQ31_AS_PWMOUT23          3

#define PORT_QSPI0_SIO0_AS_GPIO            0
#define PORT_QSPI0_SIO0_AS_QSPI0_SIO0      1
#define PORT_QSPI0_SIO0_AS_QSPI1_SIO0      2
#define PORT_QSPI0_SIO0_AS_EBIF_WAITN      3
#define PORT_QSPI0_SIO0_AS_NF_BUSYN        4

#define PORT_QSPI0_SIO1_AS_GPIO            0
#define PORT_QSPI0_SIO1_AS_QSPI0_SIO1      1
#define PORT_QSPI0_SIO1_AS_QSPI1_SIO1      2
#define PORT_QSPI0_SIO1_AS_EBIF_OE         3
#define PORT_QSPI0_SIO1_AS_NF_RE           4

#define PORT_QSPI0_SIO2_AS_GPIO            0
#define PORT_QSPI0_SIO2_AS_QSPI0_SIO2      1
#define PORT_QSPI0_SIO2_AS_QSPI1_SIO2      2
#define PORT_QSPI0_SIO2_AS_EBIF_WE         3
#define PORT_QSPI0_SIO2_AS_NF_WE           4

#define PORT_QSPI0_SIO3_AS_GPIO            0
#define PORT_QSPI0_SIO3_AS_QSPI0_SIO3      1
#define PORT_QSPI0_SIO3_AS_QSPI1_SIO3      2
#define PORT_QSPI0_SIO3_AS_EBIF_ALE        3
#define PORT_QSPI0_SIO3_AS_NF_ALE          4

#define PORT_QSPI0_CS0_AS_GPIO             0
#define PORT_QSPI0_CS0_AS_QSPI0_CS0        1
#define PORT_QSPI0_CS0_AS_QSPI1_CS0        2
#define PORT_QSPI0_CS0_AS_EBIF_CS0         3
#define PORT_QSPI0_CS0_AS_NF_CSN           4

#define PORT_QSPI0_SCLK_AS_GPIO            0
#define PORT_QSPI0_SCLK_AS_QSPI0_SCLK      1
#define PORT_QSPI0_SCLK_AS_QSPI1_SCLK      2
#define PORT_QSPI0_SCLK_AS_EBIF_SYSCLK0    3
#define PORT_QSPI0_SCLK_AS_NF_CLE          4

#define PORT_D0HDISP_AS_GPIO               0
#define PORT_D0HDISP_AS_D0HDISP            1

#define PORT_D0HSYNC_AS_GPIO               0
#define PORT_D0HSYNC_AS_D0HSYNC            1

#define PORT_D0VSYNC_AS_GPIO               0
#define PORT_D0VSYNC_AS_D0VSYNC            1

#define PORT_D0DOTCLK_AS_GPIO              0
#define PORT_D0DOTCLK_AS_D0DOTCLK          1

#define PORT_D0RGB0_AS_GPIO                0
#define PORT_D0RGB0_AS_D0RGB0              1
#define PORT_D0RGB0_AS_GDC0PWM             2

#define PORT_D0RGB1_AS_GPIO                0
#define PORT_D0RGB1_AS_D0RGB1              1

#define PORT_D0RGB2_AS_GPIO                0
#define PORT_D0RGB2_AS_D0RGB2              1
#define PORT_D0RGB2_AS_DSU_TRACED08        2

#define PORT_D0RGB3_AS_GPIO                0
#define PORT_D0RGB3_AS_D0RGB3              1
#define PORT_D0RGB3_AS_DSU_TRACED11        2

#define PORT_D0RGB4_AS_GPIO                0
#define PORT_D0RGB4_AS_D0RGB4              1
#define PORT_D0RGB4_AS_DSU_TRACECLK        2

#define PORT_D0RGB5_AS_GPIO                0
#define PORT_D0RGB5_AS_D0RGB5              1
#define PORT_D0RGB5_AS_DSU_TRACED02        2

#define PORT_D0RGB6_AS_GPIO                0
#define PORT_D0RGB6_AS_D0RGB6              1
#define PORT_D0RGB6_AS_DSU_TRACE05         2

#define PORT_D0RGB7_AS_GPIO                0
#define PORT_D0RGB7_AS_D0RGB7              1
#define PORT_D0RGB7_AS_DSU_TRACED14        2

#define PORT_D0RGB8_AS_GPIO                0
#define PORT_D0RGB8_AS_D0RGB8              1

#define PORT_D0RGB9_AS_GPIO                0
#define PORT_D0RGB9_AS_D0RGB9              1

#define PORT_D0RGB10_AS_GPIO               0
#define PORT_D0RGB10_AS_D0RGB10            1
#define PORT_D0RGB10_AS_DSU_TRACED09       2

#define PORT_D0RGB11_AS_GPIO               0
#define PORT_D0RGB11_AS_D0RGB11            1
#define PORT_D0RGB11_AS_DSU_TRACED12       2

#define PORT_D0RGB12_AS_GPIO               0
#define PORT_D0RGB12_AS_D0RGB12            1
#define PORT_D0RGB12_AS_DSU_TRACED00       2

#define PORT_D0RGB13_AS_GPIO               0
#define PORT_D0RGB13_AS_D0RGB13            1
#define PORT_D0RGB13_AS_DSU_TRACED03       2

#define PORT_D0RGB14_AS_GPIO               0
#define PORT_D0RGB14_AS_D0RGB14            1
#define PORT_D0RGB14_AS_DSU_TRACED06       2

#define PORT_D0RGB15_AS_TSM_TPC0_GTDO      0
#define PORT_D0RGB15_AS_D0RGB15            1
#define PORT_D0RGB15_AS_DSU_TRACED15       2
#define PORT_D0RGB15_AS_GPIO               3

#define PORT_D0RGB16_AS_GPIO               0
#define PORT_D0RGB16_AS_D0RGB16            1

#define PORT_D0RGB17_AS_GPIO               0
#define PORT_D0RGB17_AS_D0RGB17            1

#define PORT_D0RGB18_AS_GPIO               0
#define PORT_D0RGB18_AS_D0RGB18            1
#define PORT_D0RGB18_AS_DSU_TRACED10       2

#define PORT_D0RGB19_AS_GPIO               0
#define PORT_D0RGB19_AS_D0RGB19            1
#define PORT_D0RGB19_AS_DSU_TRACED13       2

#define PORT_D0RGB20_AS_GPIO               0
#define PORT_D0RGB20_AS_D0RGB20            1
#define PORT_D0RGB20_AS_DSU_TRACED01       2

#define PORT_D0RGB21_AS_GPIO               0
#define PORT_D0RGB21_AS_D0RGB21            1
#define PORT_D0RGB21_AS_DSU_TRACECTL       2

#define PORT_D0RGB22_AS_GPIO               0
#define PORT_D0RGB22_AS_D0RGB22            1
#define PORT_D0RGB22_AS_DSU_TRACED07       2

#define PORT_D0RGB23_AS_GPIO               0
#define PORT_D0RGB23_AS_D0RGB23            1
#define PORT_D0RGB23_AS_DSU_TRACED04       2

#define PORT_DOTCLKIN_AS_GPIO              0
#define PORT_DOTCLKIN_AS_DOTCLKIN          1
#define PORT_DOTCLKIN_AS_QSPI1_CS1         2
#define PORT_DOTCLKIN_AS_EBIF_CS1          3
#define PORT_DOTCLKIN_AS_NF_CSN2           4

#define PORT_PNLGPP0_AS_TSM_GTMS           0
#define PORT_PNLGPP0_AS_PNLGPP0            1
#define PORT_PNLGPP0_AS_QSPI1_CS0          2
#define PORT_PNLGPP0_AS_EBIF_AD08          3
#define PORT_PNLGPP0_AS_NF_DATA8           4
#define PORT_PNLGPP0_AS_I2S0SD             5
#define PORT_PNLGPP0_AS_ESEI0MISO          6
#define PORT_PNLGPP0_AS_TBIO0              7

#define PORT_PNLGPP1_AS_TSM_GTDI           0
#define PORT_PNLGPP1_AS_PNLGPP1            1
#define PORT_PNLGPP1_AS_QSPI1_SIO0         2
#define PORT_PNLGPP1_AS_EBIF_AD09          3
#define PORT_PNLGPP1_AS_NF_DATA9           4
#define PORT_PNLGPP1_AS_I2S0WS             5
#define PORT_PNLGPP1_AS_ESEI0MOSI          6
#define PORT_PNLGPP1_AS_TBIO1              7

#define PORT_PNLGPP2_AS_TSM_GTCK           0
#define PORT_PNLGPP2_AS_PNLGPP2            1
#define PORT_PNLGPP2_AS_QSPI1_SCLK         2
#define PORT_PNLGPP2_AS_EBIF_AD10          3
#define PORT_PNLGPP2_AS_NF_DATA10          4
#define PORT_PNLGPP2_AS_I2S0CLK            5
#define PORT_PNLGPP2_AS_ESEI0SCLK          6
#define PORT_PNLGPP2_AS_TBIO6              7

#define PORT_PNLGPP3_AS_TSM_GTRST          0
#define PORT_PNLGPP3_AS_PNLGPP3            1
#define PORT_PNLGPP3_AS_QSPI1_SIO1         2
#define PORT_PNLGPP3_AS_EBIF_AD11          3
#define PORT_PNLGPP3_AS_NF_DATA11          4
#define PORT_PNLGPP3_AS_I2SMCLK            5
#define PORT_PNLGPP3_AS_ESEI0SSOI          6
#define PORT_PNLGPP3_AS_TBIO7              4

#define PORT_PNLGPP4_AS_GPIO               0
#define PORT_PNLGPP4_AS_PNLGPP4            1
#define PORT_PNLGPP4_AS_QSPI1_SIO2         2
#define PORT_PNLGPP4_AS_EBIF_AD12          3
#define PORT_PNLGPP4_AS_NF_DATA12          4
#define PORT_PNLGPP4_AS_PWMOUT18           5

#define PORT_PNLGPP5_AS_GPIO               0
#define PORT_PNLGPP5_AS_PNLGPP5            1
#define PORT_PNLGPP5_AS_QSPI1_SIO3         2
#define PORT_PNLGPP5_AS_EBIF_AD13          3
#define PORT_PNLGPP5_AS_NF_DATA13          4
#define PORT_PNLGPP5_AS_PWMOUT19           5

#define PORT_PNLGPP6_AS_GPIO               0
#define PORT_PNLGPP6_AS_PNLGPP6            1
#define PORT_PNLGPP6_AS_GDC0PWM            2
#define PORT_PNLGPP6_AS_EBIF_AD14          3
#define PORT_PNLGPP6_AS_NF_DATA14          4
#define PORT_PNLGPP6_AS_PWMOUT20           5

#define PORT_PNLGPP7_AS_GPIO               0
#define PORT_PNLGPP7_AS_PNLGPP7            1
#define PORT_PNLGPP7_AS_GDC1PWM            2
#define PORT_PNLGPP7_AS_EBIF_AD15          3
#define PORT_PNLGPP7_AS_NF_DATA15          4
#define PORT_PNLGPP7_AS_PWMOUT21           5

#define PORT_D1HDISP_AS_GPIO               0
#define PORT_D1HDISP_AS_D1HDISP            1
#define PORT_D1HDISP_AS_EBIF_AEX3          2

#define PORT_D1HSYNC_AS_GPIO               0
#define PORT_D1HSYNC_AS_D1HSYNC            1
#define PORT_D1HSYNC_AS_EBIF_AEX4          2

#define PORT_D1VSYNC_AS_GPIO               0
#define PORT_D1VSYNC_AS_D1VSYNC            1
#define PORT_D1VSYNC_AS_EBIF_AEX5          2
#define PORT_D1VSYNC_AS_DMA_REQ            3
#define PORT_D1VSYNC_AS_DSU_TRACED08       4

#define PORT_D1DOTCLK_AS_GPIO              0
#define PORT_D1DOTCLK_AS_D1DOTCLK          1
#define PORT_D1DOTCLK_AS_DMA_ACK           2
#define PORT_D1DOTCLK_AS_DSU_TRACED11      3

#define PORT_D1RGB0_AS_GPIO                0
#define PORT_D1RGB0_AS_D1RGB0              1
#define PORT_D1RGB0_AS_GDC1PWM             2
#define PORT_D1RGB0_AS_EBIF_ALE            3
#define PORT_D1RGB0_AS_EBIF_AEX0           4
#define PORT_D1RGB0_AS_NF_BUSYN            5
#define PORT_D1RGB0_AS_HSPWM1              6
#define PORT_D1RGB0_AS_DSU_TRACECLK        7

#define PORT_D1RGB1_AS_GPIO                0
#define PORT_D1RGB1_AS_D1RGB1              1
#define PORT_D1RGB1_AS_EBIF_CS0            2
#define PORT_D1RGB1_AS_EBIF_AEX1           3
#define PORT_D1RGB1_AS_NF_CSN              4
#define PORT_D1RGB1_AS_PWMOUT11            5
#define PORT_D1RGB1_AS_HSPWM1N             6
#define PORT_D1RGB1_AS_DSU_TRACED02        7

#define PORT_D1RGB2_AS_GPIO                0
#define PORT_D1RGB2_AS_D1RGB2              1
#define PORT_D1RGB2_AS_RESERVED            2
#define PORT_D1RGB2_AS_NF_ALE              3
#define PORT_D1RGB2_AS_DSU_TRACED05        4

#define PORT_D1RGB3_AS_GPIO                0
#define PORT_D1RGB3_AS_D1RGB3              1
#define PORT_D1RGB3_AS_EBIF_OE             2
#define PORT_D1RGB3_AS_NF_CLE              3
#define PORT_D1RGB3_AS_DSU_TRACED14        4

#define PORT_D1RGB4_AS_GPIO                0
#define PORT_D1RGB4_AS_D1RGB4              1
#define PORT_D1RGB4_AS_EBIF_WE             2
#define PORT_D1RGB4_AS_NF_WE               3

#define PORT_D1RGB5_AS_GPIO                0
#define PORT_D1RGB5_AS_D1RGB5              1
#define PORT_D1RGB5_AS_EBIF_AD00           2
#define PORT_D1RGB5_AS_NF_RE               3

#define PORT_D1RGB6_AS_GPIO                0
#define PORT_D1RGB6_AS_D1RGB6              1
#define PORT_D1RGB6_AS_EBIF_AD01           2
#define PORT_D1RGB6_AS_NF_DATA0            3
#define PORT_D1RGB6_AS_DSU_TRACED09        4

#define PORT_D1RGB7_AS_GPIO                0
#define PORT_D1RGB7_AS_D1RGB7              1
#define PORT_D1RGB7_AS_EBIF_AD02           2
#define PORT_D1RGB7_AS_NF_DATA1            3
#define PORT_D1RGB7_AS_DSU_TRACED12        4

#define PORT_D1RGB8_AS_GPIO                0
#define PORT_D1RGB8_AS_D1RGB8              1
#define PORT_D1RGB8_AS_EBIF_AD03           2
#define PORT_D1RGB8_AS_EBIF_AEX2           3
#define PORT_D1RGB8_AS_NFDATA2             4
#define PORT_D1RGB8_AS_HSPWM2              5
#define PORT_D1RGB8_AS_DSU_TRACED00        6

#define PORT_D1RGB9_AS_GPIO                0
#define PORT_D1RGB9_AS_D1RGB9              1
#define PORT_D1RGB9_AS_EBIF_AD04           2
#define PORT_D1RGB9_AS_EBIF_AEX3           3
#define PORT_D1RGB9_AS_NF_DATA3            4
#define PORT_D1RGB9_AS_PWMOUT12            5
#define PORT_D1RGB9_AS_HSPWM2N             6
#define PORT_D1RGB9_AS_DSU_TRACED03        7

#define PORT_D1RGB10_AS_GPIO               0
#define PORT_D1RGB10_AS_D1RGB10            1
#define PORT_D1RGB10_AS_EBIF_AD05          2
#define PORT_D1RGB10_AS_NF_DATA4           3
#define PORT_D1RGB10_AS_DSU_TRACED06       4

#define PORT_D1RGB11_AS_GPIO               0
#define PORT_D1RGB11_AS_D1RGB11            1
#define PORT_D1RGB11_AS_EBIF_AD06          2
#define PORT_D1RGB11_AS_NF_DATA5           3
#define PORT_D1RGB11_AS_DSU_TRACED15       4

#define PORT_D1RGB12_AS_GPIO               0
#define PORT_D1RGB12_AS_D1RGB12            1
#define PORT_D1RGB12_AS_EBIF_AD07          2
#define PORT_D1RGB12_AS_NF_DATA6           3

#define PORT_D1RGB13_AS_GPIO               0
#define PORT_D1RGB13_AS_D1RGB13            1
#define PORT_D1RGB13_AS_EBIF_AD08          2
#define PORT_D1RGB13_AS_NF_DATA7           3

#define PORT_D1RGB14_AS_GPIO               0
#define PORT_D1RGB14_AS_D1RGB14            1
#define PORT_D1RGB14_AS_EBIF_AD09          2
#define PORT_D1RGB14_AS_NF_DATA8           3
#define PORT_D1RGB14_AS_DSU_TRACED10       4

#define PORT_D1RGB15_AS_GPIO               0
#define PORT_D1RGB15_AS_D1RGB15            1
#define PORT_D1RGB15_AS_EBIF_AD10          2
#define PORT_D1RGB15_AS_NF_DATA9           3
#define PORT_D1RGB15_AS_DSU_TRACED13       4

#define PORT_D1RGB16_AS_GPIO               0
#define PORT_D1RGB16_AS_D1RGB16            1
#define PORT_D1RGB16_AS_EBIF_AD11          2
#define PORT_D1RGB16_AS_EBIF_AEX4          3
#define PORT_D1RGB16_AS_NF_DATA10          4
#define PORT_D1RGB16_AS_HSPWM3             5
#define PORT_D1RGB16_AS_DSU_TRACED01       6

#define PORT_D1RGB17_AS_GPIO               0
#define PORT_D1RGB17_AS_D1RGB17            1
#define PORT_D1RGB17_AS_EBIF_AD12          2
#define PORT_D1RGB17_AS_EBIF_AEX5          3
#define PORT_D1RGB17_AS_NF_DATA11          4
#define PORT_D1RGB17_AS_PWMOUT13           5
#define PORT_D1RGB17_AS_HSPWM3N            6
#define PORT_D1RGB17_AS_DSU_TRACETL        7

#define PORT_D1RGB18_AS_GPIO               0
#define PORT_D1RGB18_AS_D1RGB18            1
#define PORT_D1RGB18_AS_EBIF_AD13          2
#define PORT_D1RGB18_AS_NF_DATA12          3
#define PORT_D1RGB18_AS_DSU_TRACED07       4

#define PORT_D1RGB19_AS_GPIO               0
#define PORT_D1RGB19_AS_D1RGB19            1
#define PORT_D1RGB19_AS_EBIF_AD14          2
#define PORT_D1RGB19_AS_NF_DATA13          3
#define PORT_D1RGB19_AS_DSU_TRACED04       4

#define PORT_D1RGB20_AS_GPIO               0
#define PORT_D1RGB20_AS_D1RGB20            1
#define PORT_D1RGB20_AS_EBIF_AD15          2
#define PORT_D1RGB20_AS_NF_DATA14          3

#define PORT_D1RGB21_AS_GPIO               0
#define PORT_D1RGB21_AS_D1RGB21            1
#define PORT_D1RGB21_AS_EBIF_AEX0          2
#define PORT_D1RGB21_AS_NF_DATA15          3

#define PORT_D1RGB22_AS_GPIO               0
#define PORT_D1RGB22_AS_D1RGB22            1
#define PORT_D1RGB22_AS_EBIF_AEX1          2
#define PORT_D1RGB22_AS_NF_CSN2            3

#define PORT_D1RGB23_AS_GPIO               0
#define PORT_D1RGB23_AS_D1RGB23            1
#define PORT_D1RGB23_AS_EBIF_AEX2          2

#define PORT_CMCBCR0_AS_CMCBCR0            0
#define PORT_CMCBCR0_AS_EBIF_AD08          1
#define PORT_CMCBCR0_AS_PWMOUT01           2
#define PORT_CMCBCR0_AS_GPIO               3

#define PORT_CMCBCR1_AS_CMCBCR1            0
#define PORT_CMCBCR1_AS_EBIF_AD09          1
#define PORT_CMCBCR1_AS_NF_CSN2            2
#define PORT_CMCBCR1_AS_PWMOUT02           3
#define PORT_CMCBCR1_AS_GPIO               4

#define PORT_CMCBCR2_AS_CMCBCR2            0
#define PORT_CMCBCR2_AS_EBIF_AD10          1
#define PORT_CMCBCR2_AS_NF_BUSYN           2
#define PORT_CMCBCR2_AS_PWMOUT03           3
#define PORT_CMCBCR2_AS_GPIO               4

#define PORT_CMCBCR3_AS_CMCBCR3            0
#define PORT_CMCBCR3_AS_EBIF_AD11          1
#define PORT_CMCBCR3_AS_NF_CSN             2
#define PORT_CMCBCR3_AS_PWMOUT04           3
#define PORT_CMCBCR3_AS_GPIO               4

#define PORT_CMCBCR4_AS_CMCBCR4            0
#define PORT_CMCBCR4_AS_EBIF_AD12          1
#define PORT_CMCBCR4_AS_NF_ALE             2
#define PORT_CMCBCR4_AS_PWMOUT05           3
#define PORT_CMCBCR4_AS_GPIO               4

#define PORT_CMCBCR5_AS_CMCBR5             0
#define PORT_CMCBCR5_AS_EBIF_AD13          1
#define PORT_CMCBCR5_AS_NF_CLE             2
#define PORT_CMCBCR5_AS_PWMOUT06           3
#define PORT_CMCBCR5_AS_GPIO               4

#define PORT_CMCBCR6_AS_CMCBCR6            0
#define PORT_CMCBCR6_AS_EBIF_AD14          1
#define PORT_CMCBCR6_AS_NF_WE              2
#define PORT_CMCBCR6_AS_PWMOUT07           3
#define PORT_CMCBCR6_AS_GPIO               4

#define PORT_CMCBCR7_AS_CMCBCR7            0
#define PORT_CMCBCR7_AS_EBIF_AD15          1
#define PORT_CMCBCR7_AS_NF_RE              2
#define PORT_CMCBCR7_AS_PWMOUT08           3
#define PORT_CMCBCR7_AS_GPIO               4

#define PORT_CMCLK_AS_CMCLK                0
#define PORT_CMCLK_AS_EBIF_ALE             1
#define PORT_CMCLK_AS_PWMOUT09             2
#define PORT_CMCLK_AS_GPIO                 3

#define PORT_CMFOOD_AS_CMFOOD              0
#define PORT_CMFOOD_AS_EBIF_CS0            1
#define PORT_CMFOOD_AS_PWMOUT10            2
#define PORT_CMFOOD_AS_GPIO                3

#define PORT_CMHDISP_AS_CMHDISP            0
#define PORT_CMHDISP_AS_RESERVED           1
#define PORT_CMHDISP_AS_PWMOUT11           2
#define PORT_CMHDISP_AS_GPIO               3

#define PORT_CMHSYNC_AS_CMHSYNC            0
#define PORT_CMHSYNC_AS_EBIF_OE            1
#define PORT_CMHSYNC_AS_PWMOUT12           2
#define PORT_CMHSYNC_AS_GPIO               3

#define PORT_CMVSYNC_AS_CMVSYNC            0
#define PORT_CMVSYNC_AS_EBIF_WE            1
#define PORT_CMVSYNC_AS_PWMOUT13           2
#define PORT_CMVSYNC_AS_GPIO               3

#define PORT_CMY0_AS_CMY0                  0
#define PORT_CMY0_AS_EBIF_AEX0             1
#define PORT_CMY0_AS_NF_DATA8              2
#define PORT_CMY0_AS_PWMOUT14              3
#define PORT_CMY0_AS_GPIO                  4

#define PORT_CMY1_AS_CMY1                  0
#define PORT_CMY1_AS_EBIF_AEX1             1
#define PORT_CMY1_AS_NF_DATA9              2
#define PORT_CMY1_AS_PWMOUT15              3
#define PORT_CMY1_AS_GPIO                  4

#define PORT_CMY2_AS_CMY2                  0
#define PORT_CMY2_AS_EBIF_AEX2             1
#define PORT_CMY2_AS_NF_DATA10             2
#define PORT_CMY2_AS_PWMOUT16              3
#define PORT_CMY2_AS_GPIO                  4

#define PORT_CMY3_AS_CMY3                  0
#define PORT_CMY3_AS_EBIF_AEX3             1
#define PORT_CMY3_AS_NF_DATA11             2
#define PORT_CMY3_AS_PWMOUT17              3
#define PORT_CMY3_AS_GPIO                  4

#define PORT_CMY4_AS_CMY4                  0
#define PORT_CMY4_AS_EBIF_AEX4             1
#define PORT_CMY4_AS_NF_DATA12             2
#define PORT_CMY4_AS_PWMOUT18              3
#define PORT_CMY4_AS_GPIO                  4

#define PORT_CMY5_AS_CMY5                  0
#define PORT_CMY5_AS_EBIF_AEX5             1
#define PORT_CMY5_AS_NF_DATA13             2
#define PORT_CMY5_AS_PWMOUT19              3
#define PORT_CMY5_AS_GPIO                  4

#define PORT_CMY6_AS_CMY6                  0
#define PORT_CMY6_AS_EBIF_CS1              1
#define PORT_CMY6_AS_NF_DATA14             2
#define PORT_CMY6_AS_DMA_REQ               3
#define PORT_CMY6_AS_PWMOUT20              4
#define PORT_CMY6_AS_GPIO                  5

#define PORT_CMY7_AS_CMY7                  0
#define PORT_CMY7_AS_NF_DATA15             1
#define PORT_CMY7_AS_DMA_ACK               2
#define PORT_CMY7_AS_PWMOUT21              3
#define PORT_CMY7_AS_GPIO                  4

#define PORT_CMRGB0_AS_CMRGB0              0
#define PORT_CMRGB0_AS_EBIF_AD00           1
#define PORT_CMRGB0_AS_EBIF_AD00S          2
#define PORT_CMRGB0_AS_NF_DATA0            3
#define PORT_CMRGB0_AS_NF_DATA0S           4
#define PORT_CMRGB0_AS_IRQ2                5
#define PORT_CMRGB0_AS_ESEI1MISO           6
#define PORT_CMRGB0_AS_GPIO                7

#define PORT_CMRGB1_AS_CMRGB1              0
#define PORT_CMRGB1_AS_EBIF_AD01           1
#define PORT_CMRGB1_AS_EBIF_AD01S          2
#define PORT_CMRGB1_AS_NF_DATA1            3
#define PORT_CMRGB1_AS_NF_DATA1S           4
#define PORT_CMRGB1_AS_IRQ3                5
#define PORT_CMRGB1_AS_ESEI1MOSI           6
#define PORT_CMRGB1_AS_GPIO                7

#define PORT_CMRGB2_AS_CMRGB2              0
#define PORT_CMRGB2_AS_EBIF_AD02           1
#define PORT_CMRGB2_AS_EBIF_AD02S          2
#define PORT_CMRGB2_AS_NF_DATA2            3
#define PORT_CMRGB2_AS_NF_DATA2S           4
#define PORT_CMRGB2_AS_IRQ4                5
#define PORT_CMRGB2_AS_ESEI1SCLK           6
#define PORT_CMRGB2_AS_GPIO                7

#define PORT_CMRGB3_AS_CMRGB3              0
#define PORT_CMRGB3_AS_EBIF_AD03           1
#define PORT_CMRGB3_AS_EBIF_AD03S          2
#define PORT_CMRGB3_AS_NF_DATA3            3
#define PORT_CMRGB3_AS_NF_DATA3S           4
#define PORT_CMRGB3_AS_IRQ5                5
#define PORT_CMRGB3_AS_ESEI1SSOI           6
#define PORT_CMRGB3_AS_GPIO                7

#define PORT_CMRGB4_AS_CMRGB4              0
#define PORT_CMRGB4_AS_EBIF_AD04           1
#define PORT_CMRGB4_AS_EBIF_AD04S          2
#define PORT_CMRGB4_AS_NF_DATA4            3
#define PORT_CMRGB4_AS_NF_DATA4S           4
#define PORT_CMRGB4_AS_IRQ0                5
#define PORT_CMRGB4_AS_UART1RX             6
#define PORT_CMRGB4_AS_GPIO                7

#define PORT_CMRGB5_AS_CMRGB5              0
#define PORT_CMRGB5_AS_EBIF_AD05           1
#define PORT_CMRGB5_AS_EBIF_AD05S          2
#define PORT_CMRGB5_AS_NF_DATA5            3
#define PORT_CMRGB5_AS_NF_DATA5S           4
#define PORT_CMRGB5_AS_IRQ1                5
#define PORT_CMRGB5_AS_UART1TX             6
#define PORT_CMRGB5_AS_GPIO                7

#define PORT_CMRGB6_AS_CMRGB6              0
#define PORT_CMRGB6_AS_EBIF_AD06           1
#define PORT_CMRGB6_AS_EBIF_AD06S          2
#define PORT_CMRGB6_AS_NF_DATA6            3
#define PORT_CMRGB6_AS_NF_DATA6S           4
#define PORT_CMRGB6_AS_CANRX2              5
#define PORT_CMRGB6_AS_PWMOUT22            6
#define PORT_CMRGB6_AS_GPIO                7

#define PORT_CMRGB7_AS_CMRGB7              0
#define PORT_CMRGB7_AS_EBIF_AD07           1
#define PORT_CMRGB7_AS_EBIF_AD07S          2
#define PORT_CMRGB7_AS_NF_DATA7            3
#define PORT_CMRGB7_AS_NF_DATA7S           4
#define PORT_CMRGB7_AS_CANTX2              5
#define PORT_CMRGB7_AS_PWMOUT23            6
#define PORT_CMRGB7_AS_GPIO                7

#define PORT_I2CCLK_AS_GPIO                0
#define PORT_I2CCLK_AS_DOTCLKIN            1
#define PORT_I2CCLK_AS_UART1RX             2
#define PORT_I2CCLK_AS_I2CCLK              3

#define PORT_I2CDATA_AS_GPIO               0
#define PORT_I2CDATA_AS_UART1TX            1
#define PORT_I2CDATA_AS_I2CDATA            2

#define PORT_CANRX0_AS_GPIO                0
#define PORT_CANRX0_AS_DMA_REQ             1
#define PORT_CANRX0_AS_CANRX0              2
#define PORT_CANRX0_AS_HSPWM2              3

#define PORT_CANTX0_AS_GPIO                0
#define PORT_CANTX0_AS_DMA_ACK             1
#define PORT_CANTX0_AS_CANTX0              2
#define PORT_CANTX0_AS_HSPWM2N             3

#define PORT_CANRX1_AS_GPIO                0
#define PORT_CANRX1_AS_UART0RX             1
#define PORT_CANRX1_AS_CANRX1              2
#define PORT_CANRX1_AS_PWMOUT17            3

#define PORT_CANTX1_AS_GPIO                0
#define PORT_CANTX1_AS_UART0TX             1
#define PORT_CANTX1_AS_CANTX1              2
#define PORT_CANTX1_AS_PWMOUT18            3

#define PORT_ESEI0MISO_AS_GPIO             0
#define PORT_ESEI0MISO_AS_ESEI0MISO        1
#define PORT_ESEI0MISO_AS_TBIO2            2

#define PORT_ESEI0MOSI_AS_GPIO             0
#define PORT_ESEI0MOSI_AS_ESEI0MOSI        1
#define PORT_ESEI0MOSI_AS_TBIO3            2

#define PORT_ESEI0SCLK_AS_GPIO             0
#define PORT_ESEI0SCLK_AS_IRQ0             1
#define PORT_ESEI0SCLK_AS_ESEI0CLK         2
#define PORT_ESEI0SCLK_AS_TBIO8            3

#define PORT_ESEI0SSOI_AS_GPIO             0
#define PORT_ESEI0SSOI_AS_IRQ1             1
#define PORT_ESEI0SSOI_AS_ESEI0SSOI        2
#define PORT_ESEI0SSOI_AS_PWMOUT19         3
#define PORT_ESEI0SSOI_AS_TBIO9            4

#define PORT_I2S0CLK_AS_GPIO               0
#define PORT_I2S0CLK_AS_IRQ2               1
#define PORT_I2S0CLK_AS_I2S0CLK            2
#define PORT_I2S0CLK_AS_ESEI1MISO          3
#define PORT_I2S0CLK_AS_PWMOUT20           4
#define PORT_I2S0CLK_AS_TBIO0              5

#define PORT_I2S0WS_AS_GPIO                0
#define PORT_I2S0WS_AS_IRQ3                1
#define PORT_I2S0WS_AS_I2S0WS              2
#define PORT_I2S0WS_AS_ESEI1MOSI           3
#define PORT_I2S0WS_AS_PWMOUT21            4
#define PORT_I2S0WS_AS_TBIO1               5

#define PORT_I2S0SD_AS_GPIO                0
#define PORT_I2S0SD_AS_IRQ4                1
#define PORT_I2S0SD_AS_I2S0SD              2
#define PORT_I2S0SD_AS_ESEI1SCLK           3
#define PORT_I2S0SD_AS_PWMOUT22            4
#define PORT_I2S0SD_AS_TBIO6               5

#define PORT_I2SMCLK_AS_GPIO               0
#define PORT_I2SMCLK_AS_I2SMCLK            1
#define PORT_I2SMCLK_AS_ESEI1SSOI          2
#define PORT_I2SMCLK_AS_PWMOUT23           3
#define PORT_I2SMCLK_AS_TBIO7              4

#define PORT_PWMOUT00_AS_GPIO              0
#define PORT_PWMOUT00_AS_PWMOUT0           1

#define PORT_HSPWM0_AS_GPIO                0
#define PORT_HSPWM0_AS_GDC0PWM             1
#define PORT_HSPWM0_AS_IRQ2                2
#define PORT_HSPWM0_AS_PWMOUT01            3
#define PORT_HSPWM0_AS_HSPWM0              4

#define PORT_HSPWM0N_AS_GPIO               0
#define PORT_HSPWM0N_AS_I2S1CLK            1
#define PORT_HSPWM0N_AS_PWMOUT02           2
#define PORT_HSPWM0N_AS_HSPWM0N            3

#define PORT_HSPWM1_AS_GPIO                0
#define PORT_HSPWM1_AS_GDC1PWM             1
#define PORT_HSPWM1_AS_I2S1WS              2
#define PORT_HSPWM1_AS_CANRX2              3
#define PORT_HSPWM1_AS_PWMOUT03            4
#define PORT_HSPWM1_AS_HSPWM1              5

#define PORT_HSPWM1N_AS_GPIO               0
#define PORT_HSPWM1N_AS_I2S1SD             1
#define PORT_HSPWM1N_AS_CANTX2             2
#define PORT_HSPWM1N_AS_PWMOUT04           3
#define PORT_HSPWM1N_AS_HSPWM1N            4

#define PORT_UART0RX_AS_GPIO               0
#define PORT_UART0RX_AS_UART0RX            1
#define PORT_UART0RX_AS_PWMOUT05           2

#define PORT_UART0TX_AS_GPIO               0
#define PORT_UART0TX_AS_UART0TX            1
#define PORT_UART0TX_AS_PWMOUT06           2

#define PORT_ADC_IN0_AS_ADC_IN0            0
#define PORT_ADC_IN0_AS_IRQ1               1
#define PORT_ADC_IN0_AS_GPIO               2

#define PORT_ADC_IN1_AS_ADC_IN1            0
#define PORT_ADC_IN1_AS_IRQ0               1
#define PORT_ADC_IN1_AS_GPIO               2

#define PORT_ADC_IN2_AS_ADC_IN2            0
#define PORT_ADC_IN2_AS_IRQ5               1
#define PORT_ADC_IN2_AS_GPIO               2

#define PORT_ADC_IN3_AS_ADC_IN3            0
#define PORT_ADC_IN3_AS_IRQ4               1
#define PORT_ADC_IN3_AS_GPIO               2

#define PORT_ADC_IN4_AS_ADC_IN4            0
#define PORT_ADC_IN4_AS_IRQ3               1
#define PORT_ADC_IN4_AS_GPIO               2

#define PORT_ADC_IN5_AS_ADC_IN5            0
#define PORT_ADC_IN5_AS_IRQ2               1
#define PORT_ADC_IN5_AS_GPIO               2
                                    
#define PORT_ADC_IN6_AS_ADC_IN6            0
#define PORT_ADC_IN6_AS_IRQ1               1
#define PORT_ADC_IN6_AS_GPIO               2
                                    
#define PORT_ADC_IN7_AS_ADC_IN7            0
#define PORT_ADC_IN7_AS_IRQ0               1
#define PORT_ADC_IN7_AS_GPIO               2

#define PORT_SC0_C0_LEFT_AS_SC0_C0_LEFT    0
#define PORT_SC0_C0_LEFT_AS_PWMOUT11       1
#define PORT_SC0_C0_LEFT_AS_GPIO           2

#define PORT_SC0_C0_RIGHT_AS_SC0_C0_RIGHT  0
#define PORT_SC0_C0_RIGHT_AS_PWMOUT10      1
#define PORT_SC0_C0_RIGHT_AS_GPIO          2

#define PORT_SC0_C1_LEFT_AS_SC0_C1_LEFT    0
#define PORT_SC0_C1_LEFT_AS_PWMOUT09       1
#define PORT_SC0_C1_LEFT_AS_GPIO           2

#define PORT_SC0_C1_RIGHT_AS_SC0_C1_RIGHT  0
#define PORT_SC0_C1_RIGHT_AS_PWMOUT08      1
#define PORT_SC0_C1_RIGHT_AS_GPIO          2

#define PORT_SC1_C0_LEFT_AS_SC1_C0_LEFT    0
#define PORT_SC1_C0_LEFT_AS_PWMOUT07       1
#define PORT_SC1_C0_LEFT_AS_GPIO           2

#define PORT_SC1_C0_RIGHT_AS_SC1_C0_RIGHT  0
#define PORT_SC1_C0_RIGHT_AS_PWMOUT06      1
#define PORT_SC1_C0_RIGHT_AS_GPIO          2

#define PORT_SC1_C1_LEFT_AS_SC1_C1_LEFT    0
#define PORT_SC1_C1_LEFT_AS_PWMOUT05       1
#define PORT_SC1_C1_LEFT_AS_GPIO           2

#define PORT_SC1_C1_RIGHT_AS_SC1_C1_RIGHT  0
#define PORT_SC1_C1_RIGHT_AS_PWMOUT04      1
#define PORT_SC1_C1_RIGHT_AS_GPIO          2

#define PORT_SC2_C0_LEFT_AS_SC2_C0_LEFT    0
#define PORT_SC2_C0_LEFT_AS_PWMOUT03       1
#define PORT_SC2_C0_LEFT_AS_GPIO           2

#define PORT_SC2_C0_RIGHT_AS_SC2_C0_RIGHT  0
#define PORT_SC2_C0_RIGHT_AS_PWMOUT02      1
#define PORT_SC2_C0_RIGHT_AS_GPIO          2

#define PORT_SC2_C1_LEFT_AS_SC2_C1_LEFT    0
#define PORT_SC2_C1_LEFT_AS_IRQ5           1
#define PORT_SC2_C1_LEFT_AS_PWMOUT01       2
#define PORT_SC2_C1_LEFT_AS_GPIO           3

#define PORT_SC2_C1_RIGHT_AS_SC2_C1_RIGHT  0
#define PORT_SC2_C1_RIGHT_AS_IRQ4          1
#define PORT_SC2_C1_RIGHT_AS_PWMOUT00      2
#define PORT_SC2_C1_RIGHT_AS_GPIO          3

#define PORT_SC3_C0_LEFT_AS_SC3_C0_LEFT    0
#define PORT_SC3_C0_LEFT_AS_IRQ3           1
#define PORT_SC3_C0_LEFT_AS_PWMOUT23       2
#define PORT_SC3_C0_LEFT_AS_TBIO2          3
#define PORT_SC3_C0_LEFT_AS_GPIO           4

#define PORT_SC3_C0_RIGHT_AS_SC3_C0_RIGHT  0
#define PORT_SC3_C0_RIGHT_AS_IRQ2          1
#define PORT_SC3_C0_RIGHT_AS_PWMOUT22      2
#define PORT_SC3_C0_RIGHT_AS_TBIO3         3
#define PORT_SC3_C0_RIGHT_AS_GPIO          4

#define PORT_SC3_C1_LEFT_AS_SC3_C1_LEFT    0
#define PORT_SC3_C1_LEFT_AS_IRQ1           1
#define PORT_SC3_C1_LEFT_AS_PWMOUT21       2
#define PORT_SC3_C1_LEFT_AS_TBIO8          3
#define PORT_SC3_C1_LEFT_AS_GPIO           4

#define PORT_SC3_C1_RIGHT_AS_SC3_C1_RIGHT  0
#define PORT_SC3_C1_RIGHT_AS_IRQ0          1
#define PORT_SC3_C1_RIGHT_AS_PWMOUT20      2
#define PORT_SC3_C1_RIGHT_AS_TBIO9         3
#define PORT_SC3_C1_RIGHT_AS_GPIO          4

#define PORT_SC4_C0_LEFT_AS_SC4_C0_LEFT    0
#define PORT_SC4_C0_LEFT_AS_PWMOUT19       1
#define PORT_SC4_C0_LEFT_AS_GPIO           2

#define PORT_SC4_C0_RIGHT_AS_SC4_C0_RIGHT  0
#define PORT_SC4_C0_RIGHT_AS_PWMOUT18      1
#define PORT_SC4_C0_RIGHT_AS_GPIO          2

#define PORT_SC4_C1_LEFT_AS_SC4_C1_LEFT    0
#define PORT_SC4_C1_LEFT_AS_PWMOUT17       1
#define PORT_SC4_C1_LEFT_AS_GPIO           2

#define PORT_SC4_C1_RIGHT_AS_SC4_C1_RIGHT  0
#define PORT_SC4_C1_RIGHT_AS_PWMOUT16      1
#define PORT_SC4_C1_RIGHT_AS_GPIO          2

/**********************************************
*               Enumerations                  *
**********************************************/

/* List of all pins */
typedef enum tag_portpin_e
{
    PORT_DDR_DQ0 = 0,
    PORT_DDR_DQ1,
    PORT_DDR_DQ2,
    PORT_DDR_DQ3,
    PORT_DDR_DQ4,
    PORT_DDR_DQ5,
    PORT_DDR_DQ6,
    PORT_DDR_DQ7,
    PORT_DDR_DQ8,
    PORT_DDR_DQ9,
    PORT_DDR_DQ10,
    PORT_DDR_DQ11,
    PORT_DDR_DQ12,
    PORT_DDR_DQ13,
    PORT_DDR_DQ14,
    PORT_DDR_DQ15,
    PORT_DDR_DM0,
    PORT_DDR_DM1,
    PORT_DDR_WE,
    PORT_DDR_RAS,
    PORT_DDR_CAS,
    PORT_DDR_CS,
    PORT_DDR_CKE,
    PORT_DDR_CK,
    PORT_DDR_CKN,
    PORT_DDR_BA0,
    PORT_DDR_BA1,
    PORT_DDR_A0,
    PORT_DDR_A1,
    PORT_DDR_A2,
    PORT_DDR_A3,
    PORT_DDR_A4,
    PORT_DDR_A5,
    PORT_DDR_A6,
    PORT_DDR_A7,
    PORT_DDR_A8,
    PORT_DDR_A9,
    PORT_DDR_A10,
    PORT_DDR_A11,
    PORT_DDR_A12,
    PORT_DDR_A13,
    PORT_DDR_DQS0,
    PORT_DDR_DQS1,
    PORT_DUMMY_0,
    PORT_DUMMY_1,
    PORT_DUMMY_2,
    PORT_DUMMY_3,
    PORT_DUMMY_4,
    PORT_DDR_DQS2,
    PORT_DDR_DQS3,
    PORT_DDR_DM2,
    PORT_DDR_DM3,
    PORT_DDR_DQ16,
    PORT_DDR_DQ17,
    PORT_DDR_DQ18,
    PORT_DDR_DQ19,
    PORT_DDR_DQ20,
    PORT_DDR_DQ21,
    PORT_DDR_DQ22,
    PORT_DDR_DQ23,
    PORT_DDR_DQ24,
    PORT_DDR_DQ25,
    PORT_DDR_DQ26,
    PORT_DDR_DQ27,
    PORT_DDR_DQ28,
    PORT_DDR_DQ29,
    PORT_DDR_DQ30,
    PORT_DDR_DQ31,
    PORT_DUMMY_5,
    PORT_DUMMY_6,
    PORT_DUMMY_7,
    PORT_DUMMY_8,
    PORT_DUMMY_9,
    PORT_DUMMY_10,
    PORT_DUMMY_11,
    PORT_DUMMY_12,
    PORT_DUMMY_13,
    PORT_DUMMY_14,
    PORT_DUMMY_15,
    PORT_DUMMY_16,
    PORT_QSPI0_SIO0,
    PORT_QSPI0_SIO1,
    PORT_QSPI0_SIO2,
    PORT_QSPI0_SIO3,
    PORT_QSPI0_CS0,
    PORT_QSPI0_SCLK,
    PORT_DUMMY_17,
    PORT_DUMMY_18,
    PORT_DUMMY_19,
    PORT_DUMMY_20,
    PORT_DUMMY_21,
    PORT_DUMMY_22,
    PORT_DUMMY_23,
    PORT_DUMMY_24,
    PORT_DUMMY_25,
    PORT_DUMMY_26,
    PORT_D0HDISP,
    PORT_D0HSYNC,
    PORT_D0VSYNC,
    PORT_D0DOTCLK,
    PORT_D0RGB0,
    PORT_D0RGB1,
    PORT_D0RGB2,
    PORT_D0RGB3,
    PORT_D0RGB4,
    PORT_D0RGB5,
    PORT_D0RGB6,
    PORT_D0RGB7,
    PORT_D0RGB8,
    PORT_D0RGB9,
    PORT_D0RGB10,
    PORT_D0RGB11,
    PORT_D0RGB12,
    PORT_D0RGB13,
    PORT_D0RGB14,
    PORT_D0RGB15,
    PORT_D0RGB16,
    PORT_D0RGB17,
    PORT_D0RGB18,
    PORT_D0RGB19,
    PORT_D0RGB20,
    PORT_D0RGB21,
    PORT_D0RGB22,
    PORT_D0RGB23,
    PORT_DUMMY_27,
    PORT_DUMMY_28,
    PORT_DUMMY_29,
    PORT_DUMMY_30,
    PORT_DUMMY_31,
    PORT_DUMMY_32,
    PORT_DUMMY_33,
    PORT_DUMMY_34,
    PORT_DUMMY_35,
    PORT_DUMMY_36,
    PORT_DUMMY_37,
    PORT_DUMMY_38,
    PORT_DOTCLKIN,
    PORT_DUMMY_39,
    PORT_PNLGPP0,
    PORT_PNLGPP1,
    PORT_PNLGPP2,
    PORT_PNLGPP3,
    PORT_PNLGPP4,
    PORT_PNLGPP5,
    PORT_PNLGPP6,
    PORT_PNLGPP7,
    PORT_DUMMY_40,
    PORT_DUMMY_41,
    PORT_DUMMY_42,
    PORT_DUMMY_43,
    PORT_DUMMY_44,
    PORT_DUMMY_45,
    PORT_D1HDISP,
    PORT_D1HSYNC,
    PORT_D1VSYNC,
    PORT_D1DOTCLK,
    PORT_D1RGB0,
    PORT_D1RGB1,
    PORT_D1RGB2,
    PORT_D1RGB3,
    PORT_D1RGB4,
    PORT_D1RGB5,
    PORT_D1RGB6,
    PORT_D1RGB7,
    PORT_D1RGB8,
    PORT_D1RGB9,
    PORT_D1RGB10,
    PORT_D1RGB11,
    PORT_D1RGB12,
    PORT_D1RGB13,
    PORT_D1RGB14,
    PORT_D1RGB15,
    PORT_D1RGB16,
    PORT_D1RGB17,
    PORT_D1RGB18,
    PORT_D1RGB19,
    PORT_D1RGB20,
    PORT_D1RGB21,
    PORT_D1RGB22,
    PORT_D1RGB23,
    PORT_DUMMY_46,
    PORT_DUMMY_47,
    PORT_DUMMY_48,
    PORT_DUMMY_49,
    PORT_DUMMY_50,
    PORT_DUMMY_51,
    PORT_DUMMY_52,
    PORT_DUMMY_53,
    PORT_DUMMY_54,
    PORT_DUMMY_55,
    PORT_DUMMY_56,
    PORT_DUMMY_57,
    PORT_CMCBCR0,
    PORT_CMCBCR1,
    PORT_CMCBCR2,
    PORT_CMCBCR3,
    PORT_CMCBCR4,
    PORT_CMCBCR5,
    PORT_CMCBCR6,
    PORT_CMCBCR7,
    PORT_CMCLK,
    PORT_DUMMY_58,
    PORT_CMFOOD,
    PORT_CMHDISP,
    PORT_CMHSYNC,
    PORT_CMVSYNC,
    PORT_CMY0,        
    PORT_CMY1,        
    PORT_CMY2,        
    PORT_CMY3,        
    PORT_CMY4,        
    PORT_CMY5,        
    PORT_CMY6,        
    PORT_CMY7,        
    PORT_CMRGB0,        
    PORT_CMRGB1,        
    PORT_CMRGB2,        
    PORT_CMRGB3,        
    PORT_CMRGB4,        
    PORT_CMRGB5,        
    PORT_CMRGB6,        
    PORT_CMRGB7,        
    PORT_DUMMY_59,
    PORT_DUMMY_60,
    PORT_DUMMY_61,
    PORT_DUMMY_62,
    PORT_DUMMY_63,
    PORT_DUMMY_64,
    PORT_DUMMY_65,
    PORT_DUMMY_66,
    PORT_DUMMY_67,
    PORT_DUMMY_68,
    PORT_DUMMY_69,
    PORT_DUMMY_70,
    PORT_DUMMY_71,
    PORT_DUMMY_72,
    PORT_DUMMY_73,
    PORT_DUMMY_74,
    PORT_DUMMY_75,
    PORT_DUMMY_76,
    PORT_I2CCLK,
    PORT_I2CDATA,
    PORT_CANRX0,
    PORT_CANTX0,
    PORT_CANRX1,
    PORT_CANTX1,
    PORT_MLBDAT_IO,
    PORT_MLBSIG_IO,
    PORT_MLBCLK,
    PORT_DUMMY_77,
    PORT_ESEI0MISO,
    PORT_ESEI0MOSI,
    PORT_ESEI0SCLK,
    PORT_ESEI0SSOI,
    PORT_I2S0CLK,
    PORT_I2S0WS,
    PORT_I2S0SD,
    PORT_I2SMCLK,
    PORT_PWMOUT00,
    PORT_DUMMY_78,
    PORT_HSPWM0,
    PORT_HSPWM0N,
    PORT_HSPWM1,
    PORT_HSPWM1N,
    PORT_UART0RX,
    PORT_UART0TX,
    PORT_DUMMY_79,
    PORT_DUMMY_80,
    PORT_DUMMY_81,
    PORT_DUMMY_82,
    PORT_DUMMY_83,
    PORT_DUMMY_84,
    PORT_SIP_QSPI_SIO0,
    PORT_SIP_QSPI_SIO1,
    PORT_SIP_QSPI_SIO2,
    PORT_SIP_QSPI_SIO3,
    PORT_SIP_QSPI_CS,
    PORT_SIP_QSPI_SCLK,
    PORT_DUMMY_85,
    PORT_DUMMY_86,
    PORT_NMI,
    PORT_RESETN,
    PORT_DSU_JTAG_SEL,
    PORT_DSU_GTCK,
    PORT_DSU_GTDI,
    PORT_DSU_GTMS,
    PORT_DSU_GTRST,
    PORT_DSU_TPC0_GTDO,
    PORT_DUMMY_87,
    PORT_DUMMY_88,
    PORT_DUMMY_89,
    PORT_DUMMY_90,
    PORT_DUMMY_91,
    PORT_DUMMY_92,
    PORT_DUMMY_93,
    PORT_DUMMY_94,
    PORT_ADC_IN0,
    PORT_ADC_IN1,
    PORT_ADC_IN2,
    PORT_ADC_IN3,
    PORT_ADC_IN4,
    PORT_ADC_IN5,
    PORT_ADC_IN6,
    PORT_ADC_IN7,
    PORT_ADC_IN8,
    PORT_ADC_IN9,
    PORT_ADC_IN10,
    PORT_ADC_IN11,
    PORT_ADC_IN12,
    PORT_ADC_IN13,
    PORT_DUMMY_95,
    PORT_DUMMY_96,
    PORT_DUMMY_97,
    PORT_DUMMY_98,
    PORT_DUMMY_99,
    PORT_DUMMY_100,
    PORT_DUMMY_101,
    PORT_DUMMY_102,
    PORT_DUMMY_103,
    PORT_DUMMY_104,
    PORT_SC0_C0_LEFT,
    PORT_SC0_C0_RIGHT,
    PORT_SC0_C1_LEFT,
    PORT_SC0_C1_RIGHT,
    PORT_SC1_C0_LEFT,
    PORT_SC1_C0_RIGHT,
    PORT_SC1_C1_LEFT,
    PORT_SC1_C1_RIGHT,
    PORT_SC2_C0_LEFT,
    PORT_SC2_C0_RIGHT,
    PORT_SC2_C1_LEFT,
    PORT_SC2_C1_RIGHT,
    PORT_SC3_C0_LEFT,
    PORT_SC3_C0_RIGHT,
    PORT_SC3_C1_LEFT,
    PORT_SC3_C1_RIGHT,
    PORT_SC4_C0_LEFT,
    PORT_SC4_C0_RIGHT,
    PORT_SC4_C1_LEFT,
    PORT_SC4_C1_RIGHT
} gpio_portpin_e;

/* Enable/disable */
typedef enum tag_gpio_en_e
{
    GPIO_DISABLE = 0x0,                       /* Disable */
    GPIO_ENABLE  = 0x1                        /* Enable */
} gpio_en_e;

/* Output resistance */
typedef enum tag_gpio_output_resistance_e
{
    GPIO_OUTPUT_RESISTANCE_25  = 0x0,         /* Output_resistance 25 Ohm */
    GPIO_OUTPUT_RESISTANCE_50  = 0x1,         /* Output_resistance 50 Ohm */
    GPIO_OUTPUT_RESISTANCE_75  = 0x2,         /* Output_resistance 75 Ohm */
    GPIO_OUTPUT_RESISTANCE_150 = 0x3          /* Output_resistance 150 Ohm */
} gpio_output_resistance_e;

/* SMC macro */
typedef enum tag_gpio_smcmacro_e
{
    GPIO_SMC_MACRO_0 = 0x0,                   /* SMC macro 0 */
    GPIO_SMC_MACRO_1 = 0x1,                   /* SMC macro 1 */
    GPIO_SMC_MACRO_2 = 0x2,                   /* SMC macro 2 */
    GPIO_SMC_MACRO_3 = 0x3,                   /* SMC macro 3 */
    GPIO_SMC_MACRO_4 = 0x4                    /* SMC macro 4 */
} gpio_smcmacro_e;

/* Memory configuration */
typedef enum tag_gpio_mem_config_e
{
    GPIO_MEM_CONFIG_NO_SDRAM = 0x0,           /* no SDRAM -> GPIO functionality */
    GPIO_MEM_CONFIG_LPDDR_32 = 0x1,           /* LPDDR 32 bit */
    GPIO_MEM_CONFIG_SDRAM_32 = 0x2,           /* SDRAM 32 bit */
    GPIO_MEM_CONFIG_LPDDR_16 = 0x3            /* LPDDR 16 bit */
} gpio_mem_config_e;

/* Direction */
typedef enum tag_gpio_direction_e
{
    GPIO_OUTPUT = 0x0,                        /* Output */
    GPIO_INPUT  = 0x1                         /* Input */
} gpio_direction_e;

/* GPIO state */
typedef enum tag_gpio_state_e
{
    GPIO_LOW  = 0x0,                          /* Low */
    GPIO_HIGH = 0x1                           /* High */
} gpio_state_e;

/****************************************************************************/


/**********************************************
*                 Structures                  *
**********************************************/


/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vGPIO_GetVersion
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
void vGPIO_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      i32GPIO_EnablePullUp
 *
 * Purpose:       Enable/disable pull-up
 *
 * Inputs:        ePin    Pin type
 *                eEn     Enable/disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32GPIO_EnablePullUp(gpio_portpin_e ePin, gpio_en_e eEn);

/****************************************************************************
 *
 * Function:      i32GPIO_EnablePullDown
 *
 * Purpose:       Enable/disable pull-down
 *
 * Inputs:        ePin    Pin type
 *                eEn     Enable/disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32GPIO_EnablePullDown(gpio_portpin_e ePin, gpio_en_e eEn);

/****************************************************************************
 *
 * Function:      i32GPIO_EnableSchmittTrigger
 *
 * Purpose:       Enable/disable schmitt trigger
 *
 * Inputs:        ePin    Pin type
 *                eEn     Enable/disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32GPIO_EnableSchmittTrigger(gpio_portpin_e ePin, gpio_en_e eEn);

/****************************************************************************
 *
 * Function:      i32GPIO_SetOutputResistance
 *
 * Purpose:       Set output resistance
 *
 * Inputs:        ePin                  Pin type
 *                eOutputResistance     Output resistance
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32GPIO_SetOutputResistance(gpio_portpin_e ePin, gpio_output_resistance_e eOutputResistance);

/****************************************************************************
 *
 * Function:      i32GPIO_EnableLatchFunction
 *
 * Purpose:       Enable/disable latch function
 *
 * Inputs:        ePin    Pin type
 *                eEn     Enable/disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32GPIO_EnableLatchFunction(gpio_portpin_e ePin, gpio_en_e eEn);

/****************************************************************************
 *
 * Function:      i32GPIO_EnableSMCMacro
 *
 * Purpose:       Enable/disable SMC macro
 *
 * Inputs:        eSMCMacro    SMC macro
 *                eEn          Enable/disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32GPIO_EnableSMCMacro(gpio_smcmacro_e eSMCMacro, gpio_en_e eEn);

/****************************************************************************
 *
 * Function:      i32GPIO_SetPinFunction
 *
 * Purpose:       Set pin function
 *
 * Inputs:        ePin             Pin type
 *                u8PinFunction    Pin function
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32GPIO_SetPinFunction(gpio_portpin_e ePin, uint8_t u8PinFunction);

/****************************************************************************
 *
 * Function:      i32GPIO_SetPinDirection
 *
 * Purpose:       Set pin direction
 *
 * Inputs:        ePin             port pin no.
 *                ePinDirection    pin direction
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32GPIO_SetPinDirection(gpio_portpin_e ePin, gpio_direction_e ePinDirection);

/****************************************************************************
 *
 * Function:      i32GPIO_SetPinState
 *
 * Purpose:       Set pin state
 *
 * Inputs:        ePin         port pin no.
 *                ePinState    pin state
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32GPIO_SetPinState(gpio_portpin_e ePin, gpio_state_e ePinState);

/****************************************************************************
 *
 * Function:      i32GPIO_GetPinState
 *
 * Purpose:       Set pin state
 *
 * Inputs:        ePin         port pin no.
 *
 * Outputs:       ePinState    pin state
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32GPIO_GetPinState(gpio_portpin_e ePin, gpio_state_e * ePinState);

/****************************************************************************
 *
 * Function:      i32GPIO_SelectMemoryInterfaceConfiguration
 *
 * Purpose:       Set memory interface configuration
 *
 * Inputs:        eMemConfig    Memory interface configuration
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:
 *
 ***************************************************************************/
int32_t i32GPIO_SelectMemoryInterfaceConfiguration(gpio_mem_config_e eMemConfig);

/****************************************************************************/


#endif /* GPIO_H */

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

