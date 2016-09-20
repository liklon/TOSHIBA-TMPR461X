/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: pinconfig.c,v $
*   Description : Port configuration
******************************************************************************
*   PROJECT     : Capricorn-Bt/C
*   MODULE      : System
*               : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.1 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/05/09 14:05:52 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Basic_Graphics_Keil/src/pinconfig.c,v $
*   LOG:        : please have a look at the end of the file
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "gpio.h"
#include "pinconfig.h"

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

/*********************************************/

/**********************************************
*   Local variables and forward declarations  *
**********************************************/

/*********************************************/

/**********************************************
*                  Functions                  *
**********************************************/

void vPinconfig_GDC0(void)
{
    /* PORT_D0HDISP */
    i32GPIO_EnableLatchFunction(PORT_D0HDISP, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0HDISP, PORT_D0HDISP_AS_D0HDISP);
    i32GPIO_EnablePullUp(PORT_D0HDISP, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0HDISP, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0HSYNC */
    i32GPIO_EnableLatchFunction(PORT_D0HSYNC, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0HSYNC, PORT_D0HSYNC_AS_D0HSYNC);
    i32GPIO_EnablePullUp(PORT_D0HSYNC, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0HSYNC, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0VSYNC */
    i32GPIO_EnableLatchFunction(PORT_D0VSYNC, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0VSYNC, PORT_D0VSYNC_AS_D0VSYNC);
    i32GPIO_EnablePullUp(PORT_D0VSYNC, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0VSYNC, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0DOTCLK */
    i32GPIO_EnableLatchFunction(PORT_D0DOTCLK, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0DOTCLK, PORT_D0DOTCLK_AS_D0DOTCLK);
    i32GPIO_EnablePullUp(PORT_D0DOTCLK, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0DOTCLK, GPIO_OUTPUT_RESISTANCE_50);
#if 0
    /* PORT_D0RGB0 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB0, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB0, PORT_D0RGB0_AS_D0RGB0);
    i32GPIO_EnablePullUp(PORT_D0RGB0, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB0, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB1 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB1, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB1, PORT_D0RGB1_AS_D0RGB1);
    i32GPIO_EnablePullUp(PORT_D0RGB1, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB1, GPIO_OUTPUT_RESISTANCE_50);
#endif

    /* PORT_D0RGB2 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB2, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB2, PORT_D0RGB2_AS_D0RGB2);
    i32GPIO_EnablePullUp(PORT_D0RGB2, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB2, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB3 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB3, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB3, PORT_D0RGB3_AS_D0RGB3);
    i32GPIO_EnablePullUp(PORT_D0RGB3, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB3, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB4 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB4, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB4, PORT_D0RGB4_AS_D0RGB4);
    i32GPIO_EnablePullUp(PORT_D0RGB4, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB4, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB5 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB5, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB5, PORT_D0RGB5_AS_D0RGB5);
    i32GPIO_EnablePullUp(PORT_D0RGB5, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB5, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB6 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB6, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB6, PORT_D0RGB6_AS_D0RGB6);
    i32GPIO_EnablePullUp(PORT_D0RGB6, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB6, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB7 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB7, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB7, PORT_D0RGB7_AS_D0RGB7);
    i32GPIO_EnablePullUp(PORT_D0RGB7, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB7, GPIO_OUTPUT_RESISTANCE_50);
#if 0
    /* PORT_D0RGB8 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB8, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB8, PORT_D0RGB8_AS_D0RGB8);
    i32GPIO_EnablePullUp(PORT_D0RGB8, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB8, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB9 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB9, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB9, PORT_D0RGB9_AS_D0RGB9);
    i32GPIO_EnablePullUp(PORT_D0RGB9, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB9, GPIO_OUTPUT_RESISTANCE_50);
#endif
    /* PORT_D0RGB10 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB10, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB10, PORT_D0RGB10_AS_D0RGB10);
    i32GPIO_EnablePullUp(PORT_D0RGB10, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB10, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB11 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB11, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB11, PORT_D0RGB11_AS_D0RGB11);
    i32GPIO_EnablePullUp(PORT_D0RGB11, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB11, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB12 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB12, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB12, PORT_D0RGB12_AS_D0RGB12);
    i32GPIO_EnablePullUp(PORT_D0RGB12, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB12, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB13 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB13, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB13, PORT_D0RGB13_AS_D0RGB13);
    i32GPIO_EnablePullUp(PORT_D0RGB13, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB13, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB14 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB14, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB14, PORT_D0RGB14_AS_D0RGB14);
    i32GPIO_EnablePullUp(PORT_D0RGB14, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB14, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB15 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB15, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB15, PORT_D0RGB15_AS_D0RGB15);
    i32GPIO_EnablePullUp(PORT_D0RGB15, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB15, GPIO_OUTPUT_RESISTANCE_50);
#if 0
    /* PORT_D0RGB16 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB16, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB16, PORT_D0RGB16_AS_D0RGB16);
    i32GPIO_EnablePullUp(PORT_D0RGB16, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB16, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB17 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB17, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB17, PORT_D0RGB17_AS_D0RGB17);
    i32GPIO_EnablePullUp(PORT_D0RGB17, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB17, GPIO_OUTPUT_RESISTANCE_50);
#endif
    /* PORT_D0RGB18 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB18, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB18, PORT_D0RGB18_AS_D0RGB18);
    i32GPIO_EnablePullUp(PORT_D0RGB18, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB18, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB19 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB19, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB19, PORT_D0RGB19_AS_D0RGB19);
    i32GPIO_EnablePullUp(PORT_D0RGB19, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB19, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB20 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB20, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB20, PORT_D0RGB20_AS_D0RGB20);
    i32GPIO_EnablePullUp(PORT_D0RGB20, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB20, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB21 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB21, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB21, PORT_D0RGB21_AS_D0RGB21);
    i32GPIO_EnablePullUp(PORT_D0RGB21, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB21, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB22 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB22, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB22, PORT_D0RGB22_AS_D0RGB22);
    i32GPIO_EnablePullUp(PORT_D0RGB22, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB22, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D0RGB23 */
    i32GPIO_EnableLatchFunction(PORT_D0RGB23, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D0RGB23, PORT_D0RGB23_AS_D0RGB23);
    i32GPIO_EnablePullUp(PORT_D0RGB23, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D0RGB23, GPIO_OUTPUT_RESISTANCE_50);
}


/****************************************************************************/

void vPinconfig_GDC1(void)
{
#if 0
    /* PORT_D1HDISP */
    i32GPIO_EnableLatchFunction(PORT_D1HDISP, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1HDISP, PORT_D1HDISP_AS_D1HDISP);
    i32GPIO_EnablePullUp(PORT_D1HDISP, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1HDISP, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1HSYNC */
    i32GPIO_EnableLatchFunction(PORT_D1HSYNC, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1HSYNC, PORT_D1HSYNC_AS_D1HSYNC);
    i32GPIO_EnablePullUp(PORT_D1HSYNC, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1HSYNC, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1VSYNC */
    i32GPIO_EnableLatchFunction(PORT_D1VSYNC, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1VSYNC, PORT_D1VSYNC_AS_D1VSYNC);
    i32GPIO_EnablePullUp(PORT_D1VSYNC, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1VSYNC, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1DOTCLK */
    i32GPIO_EnableLatchFunction(PORT_D1DOTCLK, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1DOTCLK, PORT_D1DOTCLK_AS_D1DOTCLK);
    i32GPIO_EnablePullUp(PORT_D1DOTCLK, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1DOTCLK, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB0 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB0, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB0, PORT_D1RGB0_AS_D1RGB0);
    i32GPIO_EnablePullUp(PORT_D1RGB0, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB0, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB1 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB1, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB1, PORT_D1RGB1_AS_D1RGB1);
    i32GPIO_EnablePullUp(PORT_D1RGB1, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB1, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB2 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB2, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB2, PORT_D1RGB2_AS_D1RGB2);
    i32GPIO_EnablePullUp(PORT_D1RGB2, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB2, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB3 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB3, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB3, PORT_D1RGB3_AS_D1RGB3);
    i32GPIO_EnablePullUp(PORT_D1RGB3, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB3, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB4 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB4, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB4, PORT_D1RGB4_AS_D1RGB4);
    i32GPIO_EnablePullUp(PORT_D1RGB4, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB4, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB5 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB5, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB5, PORT_D1RGB5_AS_D1RGB5);
    i32GPIO_EnablePullUp(PORT_D1RGB5, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB5, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB6 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB6, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB6, PORT_D1RGB6_AS_D1RGB6);
    i32GPIO_EnablePullUp(PORT_D1RGB6, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB6, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB7 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB7, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB7, PORT_D1RGB7_AS_D1RGB7);
    i32GPIO_EnablePullUp(PORT_D1RGB7, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB7, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB8 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB8, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB8, PORT_D1RGB8_AS_D1RGB8);
    i32GPIO_EnablePullUp(PORT_D1RGB8, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB8, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB9 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB9, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB9, PORT_D1RGB9_AS_D1RGB9);
    i32GPIO_EnablePullUp(PORT_D1RGB9, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB9, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB10 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB10, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB10, PORT_D1RGB10_AS_D1RGB10);
    i32GPIO_EnablePullUp(PORT_D1RGB10, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB10, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB11 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB11, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB11, PORT_D1RGB11_AS_D1RGB11);
    i32GPIO_EnablePullUp(PORT_D1RGB11, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB11, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB12 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB12, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB12, PORT_D1RGB12_AS_D1RGB12);
    i32GPIO_EnablePullUp(PORT_D1RGB12, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB12, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB13 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB13, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB13, PORT_D1RGB13_AS_D1RGB13);
    i32GPIO_EnablePullUp(PORT_D1RGB13, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB13, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB14 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB14, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB14, PORT_D1RGB14_AS_D1RGB14);
    i32GPIO_EnablePullUp(PORT_D1RGB14, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB14, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB15 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB15, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB15, PORT_D1RGB15_AS_D1RGB15);
    i32GPIO_EnablePullUp(PORT_D1RGB15, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB15, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB16 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB16, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB16, PORT_D1RGB16_AS_D1RGB16);
    i32GPIO_EnablePullUp(PORT_D1RGB16, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB16, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB17 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB17, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB17, PORT_D1RGB17_AS_D1RGB17);
    i32GPIO_EnablePullUp(PORT_D1RGB17, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB17, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB18 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB18, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB18, PORT_D1RGB18_AS_D1RGB18);
    i32GPIO_EnablePullUp(PORT_D1RGB18, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB18, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB19 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB19, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB19, PORT_D1RGB19_AS_D1RGB19);
    i32GPIO_EnablePullUp(PORT_D1RGB19, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB19, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB20 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB20, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB20, PORT_D1RGB20_AS_D1RGB20);
    i32GPIO_EnablePullUp(PORT_D1RGB20, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB20, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB21 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB21, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB21, PORT_D1RGB21_AS_D1RGB21);
    i32GPIO_EnablePullUp(PORT_D1RGB21, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB21, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB22 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB22, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB22, PORT_D1RGB22_AS_D1RGB22);
    i32GPIO_EnablePullUp(PORT_D1RGB22, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB22, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_D1RGB23 */
    i32GPIO_EnableLatchFunction(PORT_D1RGB23, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB23, PORT_D1RGB23_AS_D1RGB23);
    i32GPIO_EnablePullUp(PORT_D1RGB23, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB23, GPIO_OUTPUT_RESISTANCE_50);
#endif
}


/****************************************************************************/

void vPinconfig_Buttons(void)
{
    /* set input port for button 1 */
    i32GPIO_SetPinFunction(PORT_I2SMCLK, PORT_I2SMCLK_AS_GPIO);
    i32GPIO_EnableLatchFunction(PORT_I2SMCLK, GPIO_DISABLE);
    i32GPIO_SetPinDirection(PORT_I2SMCLK, GPIO_INPUT);
    i32GPIO_EnablePullUp(PORT_I2SMCLK,GPIO_ENABLE);

    /* set input port for button 2 */
    i32GPIO_SetPinFunction(PORT_I2S0SD, PORT_I2S0SD_AS_GPIO);
    i32GPIO_EnableLatchFunction(PORT_I2S0SD, GPIO_DISABLE);
    i32GPIO_SetPinDirection(PORT_I2S0SD, GPIO_INPUT);
    i32GPIO_EnablePullUp(PORT_I2S0SD,GPIO_ENABLE);
    /* set input port for button 3 */
    i32GPIO_SetPinFunction(PORT_I2S0WS, PORT_I2S0WS_AS_GPIO);
    i32GPIO_EnableLatchFunction(PORT_I2S0WS, GPIO_DISABLE);

    i32GPIO_EnablePullUp(PORT_I2S0WS,GPIO_ENABLE);
    /* set input port for button 4 */
    i32GPIO_SetPinFunction(PORT_I2S0CLK, PORT_I2S0CLK_AS_GPIO);
    i32GPIO_EnableLatchFunction(PORT_I2S0CLK, GPIO_DISABLE);
    i32GPIO_SetPinDirection(PORT_I2S0CLK, GPIO_INPUT);
    i32GPIO_EnablePullUp(PORT_I2S0CLK,GPIO_ENABLE);
    /* set input port for encoder 1 */    
    i32GPIO_SetPinFunction(PORT_PNLGPP4, PORT_PNLGPP4_AS_GPIO);
    i32GPIO_EnableLatchFunction(PORT_PNLGPP4, GPIO_DISABLE);
    i32GPIO_SetPinDirection(PORT_PNLGPP4, GPIO_INPUT);
    i32GPIO_EnablePullUp(PORT_PNLGPP4,GPIO_ENABLE);
    /* set input port for encoder 1 */    
//    i32GPIO_SetPinFunction(PORT_PNLGPP5, PORT_PNLGPP5_AS_GPIO);
//    i32GPIO_EnableLatchFunction(PORT_PNLGPP5, GPIO_DISABLE);
//    i32GPIO_SetPinDirection(PORT_PNLGPP5, GPIO_INPUT);
//    i32GPIO_EnablePullUp(PORT_PNLGPP5,GPIO_ENABLE);
    /* set input port for encoder 2 */    
 //   i32GPIO_SetPinFunction(PORT_PNLGPP6, PORT_PNLGPP6_AS_GPIO);
  //  i32GPIO_EnableLatchFunction(PORT_PNLGPP6, GPIO_DISABLE);
 //   i32GPIO_SetPinDirection(PORT_PNLGPP6, GPIO_INPUT);
// i32GPIO_EnablePullUp(PORT_PNLGPP6,GPIO_ENABLE);
}


void vPinconfig_CAN(void)
{
    /* PORT_CANRX0 */
    i32GPIO_EnableLatchFunction(PORT_CANRX0, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_CANRX0, PORT_CANRX0_AS_CANRX0);
    i32GPIO_EnablePullUp(PORT_CANRX0, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_CANRX0, GPIO_OUTPUT_RESISTANCE_50);

    /* PORT_CANTX0 */
    i32GPIO_EnableLatchFunction(PORT_CANTX0, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_CANTX0, PORT_CANTX0_AS_CANTX0);
    i32GPIO_EnablePullUp(PORT_CANTX0, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_CANTX0, GPIO_OUTPUT_RESISTANCE_50);
}




/***************************************************************************/


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

/********************************* BEGIN OF LOG ******************************
*
* $Log: pinconfig.c,v $
* Revision 1.1  2014/05/09 14:05:52  mto
* initial version
*
*
*********************************** END OF LOG ******************************/
