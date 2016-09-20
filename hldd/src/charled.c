/******************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*******************************************************************************
*   DESCRIPTION : Display data on Character LED's 
*
*                 Below is some useful information for driving the LED on bord
*
*                 --select the Char-LED( {CSO, A27, A26} = L,1,0
*                
*                  LED PIN  :: Cap-Bt
*                  ------------------
*                  WR   = 1 :: EBIF_WE 
*                  RSTn = 1 :: 
*
*                  A27, A26 = 1, 0 : 
*                 
*                  FLn  = 1 :: EBIF_AEX5
*                  A4, A3 = 1, 1 :: EBIF_AEX4, EBIF_AEX3
*                  A2, A1, A0 = <LED Num> :: EBIF_AEX2, EBIF_AEX1, EBIF_AEX0
*
*                  D7=1 :: EBIF_AD7
*                  D6 .. D0 = <ASCI Code> :: EBIF_AD6 .. EBIF_AD0
*
*******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Capricorn Software
*   LIBRARIES   :
*******************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/04 09:07:18 $
*   TAG         : $Name: HLDD_1_1 $
*******************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include <string.h>

#include "core.h"
#include "charled.h"
#include "gpio.h"

/**********************************************
*             Constants & Macros              *
**********************************************/

/*NOR CS0 --> 0x18000000 to 0x19FFFFFF. CS1 --> 0x1C000000 to 0x1CDFFFFF  for
  NOR CS0 --> 0x20000000 to 0x21FFFFFF. CS1 --> 0x22000000 to 0x23FFFFFF  for
  *2 chip of 512mbits                                                    */

#define CHIP0_ADDRESS  0x30000000
#define CHIP1_ADDRESS  0x22000000
#define NOR_MASK0_0    0x000000FF
#define NOR_MATCH0_0   0x00003000
#define NOR_MASK0_1    0x00FE0000
#define NOR_MATCH0_1   0x22000000


/*NAND CS0 --> 0x24000000 to 0x23FFFFFF. CS1 --> 0x25000000 to 0x24FFFFFF  for
 * 2 chip of  arbitary valid non-overlapping address space             */
#define NAND_MASK1_0    0x000000FF
#define NAND_MATCH1_0   0x00002400
#define NAND_MASK1_1    0x00FF0000
#define NAND_MATCH1_1   0x25000000

#define PL353           0xc0200000
#define NOR_CHIP0       0x100
#define NOR_CHIP1       0x120
#define NAND_CHIP0      0x180
#define NAND_CHIP1      0x1A0

#define SET_OPMODE_REG     (*(volatile unsigned long *) (PL353 + 0x018))
#define SET_CYCLE          (*(volatile unsigned long *) (PL353 + 0x014))
#define SET_DIRECT_CMD_REG (*(volatile unsigned long *) (PL353 + 0x010))

#define CCR_KEYR               (*(volatile unsigned long *) (SYSC + 0x0000))
#define SYSC              0xC0000000  
#define CCR_GENERIC_REG2  0xC000006C 
#define CCR_GENERIC_REG3  0xC0000070 

/**********************************************
*   Local variables and forward declarations  *
**********************************************/


/**********************************************
*                  Functions                  *
**********************************************/

void initCLED(void)
{
    unsigned long long ReadVal32;
    volatile unsigned long  *pWord;
    unsigned long  wrWord;
    unsigned long set_burst_align;
    unsigned long set_bls;
    unsigned long set_adv;
    unsigned long set_baa;
    unsigned long set_wr_bl;
    unsigned long set_wr_sync;
    unsigned long set_rd_bl;
    unsigned long set_rd_sync;
    unsigned long set_mw;
  
    unsigned long chip_select;
    unsigned long cmd_type;
    unsigned long set_cre;
    unsigned long cmd_addr_match;

    // setup Interface GDC1 for NOR Flash
    setNORflash_interface_gdc1();

    // All chip select must be configured otherwise reset ("0") values will generate
    // chip select constantly
    //Program Interface 0 CCR with 2 chips selects. Chip0 -> first 256Mbit, 
    //Chip1 -> second 256Mbit

    CCR_KEYR  = 0xA5C0F17B; // unlock SYSC registers
    //CCR Match and MASK to interface 0
    pWord    =  (volatile unsigned long *) CCR_GENERIC_REG2;  
    wrWord   = NOR_MATCH0_1 + NOR_MASK0_1 + NOR_MATCH0_0 + NOR_MASK0_0; 
    *pWord   = wrWord; 

    //Program Interface 1 CCR with 2 chips selects. 
    //with valid values
    CCR_KEYR = 0xA5C0F17B; // unlock SYSC registers
    //CCR Match and MASK to interface 1
    pWord  = (volatile unsigned long *) CCR_GENERIC_REG3;  
    wrWord = NAND_MATCH1_1 + NAND_MASK1_1 + NAND_MATCH1_0 + NAND_MASK1_0; 
    *pWord = wrWord; 

    // reconfigure reserved_m clock to 
    *(volatile unsigned int*)(SYSC) = 0xA5C0F17B;
    *(volatile unsigned short*)(SYSC+0x000E) = 1024;

    //SRAM_CYCLES0_0 
    pWord     = (volatile unsigned long *) (PL353 + NOR_CHIP0);
    ReadVal32 = *pWord;
    SET_CYCLE  = (ReadVal32 & 0xFFFFF8F0) | 0x0000010F; // we_time = 0, t_ceoe = 1, t_rc = 15
  
    // user_status
    pWord     = (volatile unsigned long *) (PL353 + 0x200);
    ReadVal32 = *pWord;

    //            set_burst_align set_bls set_adv set_baa set_wr_bl set_wr_sync set_rd_bl set_rd_sync  mw
    //set_opmode {[15:13],        [12],   [11],   [10],   [9:7],    [6],        [5:3],    [2],         [1:0]},
    set_burst_align =  0x0000 << 13;
    set_bls         =  0x0000 << 12;
    set_adv         =  0x0000 << 11;  // a MUST
    set_baa         =  0x0000 << 10;
    set_wr_bl       =  0x0000 << 7;
    set_wr_sync     =  0x0000 << 6;
    set_rd_bl       =  0x0000 << 3;
    set_rd_sync     =  0x0000 << 2;    // QPSIO _CLK gets clk_out when set 1 (eyeball this once and it worked along with fb_clk) 
    set_mw          =  0x0001; 
    SET_OPMODE_REG  =  set_burst_align + set_bls + set_adv + set_baa + set_wr_bl + set_wr_sync + set_rd_bl + set_rd_sync + set_mw; 

    //program direct commmand register to update opmode settings 
    chip_select    = 0x0000 << 23;  // interface 0 chip 0
    cmd_type       = 0x0002 << 21;  // UpdateReg
    set_cre        = 0x0000 << 20;  // NA
    cmd_addr_match = 0x0000;        // NA in UpdateReg

    SET_DIRECT_CMD_REG = chip_select + cmd_type + set_cre + cmd_addr_match;

    //SRAM_CYCLES0_1 
    pWord     = (volatile unsigned long *) (PL353 + NOR_CHIP1);
    ReadVal32 = *pWord;
    SET_CYCLE = (ReadVal32 & 0xFFFFF8F0) | 0x0000010F; // we_time = 0, t_ceoe = 1, t_rc = 15

    chip_select = 0x0001 << 23;  // interface 0 chip 1
    SET_DIRECT_CMD_REG = chip_select + cmd_type + set_cre + cmd_addr_match;

    //opmode0_0 
    pWord     = (volatile unsigned long *) (PL353 + NOR_CHIP0 + 4);
    ReadVal32 = *pWord;
   
    //opmode0_1 
    pWord     = (volatile unsigned long *) (PL353 + NOR_CHIP1 + 4);
    ReadVal32 = *pWord;
}

/****************************************************************************/


void setCLED(char *text)
{
    int i=0;
    int size = strlen(text);
    if(size>8) size = 8;

    // blank display
    for(i=0;i<8;i++)
    {
        *(volatile unsigned short*) (CHIP0_ADDRESS + (0x38 + i << 1)) = ' ';
        __DSB();
    }

    // put text on display right handed
    for(i=0;i<size;i++)
    {
        *(volatile unsigned short*) (CHIP0_ADDRESS + (0x38 + i << 1)) = text[i];
        __DSB();
    }
}

/****************************************************************************/


void hexCLED(unsigned long number)
{
    unsigned short i=0;
    unsigned short charnum = 0;

    // put number on display right handed
    for(i=0;i<8;i++)
    {
        charnum = ((number>>(28-i*4)) & 0x0000000f)+48;
        if(charnum>48+9) charnum +=7;
        *(volatile unsigned short*) (CHIP0_ADDRESS + (0x38 + i << 1)) = charnum;
    }
}

/****************************************************************************/


void decCLED (unsigned long long text)
{
    int i=0;
    unsigned int number = 0;
    unsigned int unit = 112;    // "p"

    if (text > 1000000000)
    {
        text = text / 1000000000;
        unit = 109;             // "m"
    }
    else if (text > 1000000)
    {
        text = text / 1000000;
        unit = 117;             // "u"
    }
    else if (text > 1000)
    {
        text = text / 1000;
        unit = 110;             // "n"
    }

    *(volatile unsigned short*) (CHIP0_ADDRESS + (0x38 + 7 << 1)) = unit;

    // put text on display right-handed
    for(i=0;i<7;i++)
    {
        if (i == 0)
            number = text % 10;
        else
        {
            text = text / 10;
            number = text % 10;
        }

        *(volatile unsigned short*) (CHIP0_ADDRESS + (0x38 + (6-i) << 1)) = number + 48;
    }
}

/****************************************************************************/


void disp_rtc_time_on_CLED (void)
{
     unsigned short   tt;
     unsigned char  read_val_8b, tt_c;
     unsigned long   time_1, time_2;

      //Read the timer 2 times and process only if both times got the same value
      time_1 = *(volatile unsigned long *) (0xC0001000);
      time_2 = *(volatile unsigned long *) (0xC0001000);
      while (time_1 != time_2)
      {
        time_1 = *(volatile unsigned long *) (0xC0001000);
        time_2 = *(volatile unsigned long *) (0xC0001000);
      } 

      //1. Display the seconds data
      tt=0;
      //read_val_8b = *(volatile unsigned char *) (0xC0001000 + 0x00);
      read_val_8b = time_2;

      tt = tt + (((read_val_8b >> 0) & 0x1 ) * 1 ) ;
      tt = tt + (((read_val_8b >> 1) & 0x1 ) * 2 ) ;
      tt = tt + (((read_val_8b >> 2) & 0x1 ) * 4 ) ;
      tt = tt + (((read_val_8b >> 3) & 0x1 ) * 8 ) ;
      tt = tt + (((read_val_8b >> 4) & 0x1 ) * 10 ) ;
      tt = tt + (((read_val_8b >> 5) & 0x1 ) * 20 ) ;
      tt = tt + (((read_val_8b >> 6) & 0x1 ) * 40 ) ;

      //--Print upper char
      tt_c = (tt/10) + 48;
      *(volatile unsigned short*) (0x30000000 + (0x38 + 6 << 1)) = tt_c;
        
      //--Print lowar char
      tt_c = (tt/10) ;
      tt_c = tt - (tt_c*10) + 48;
      *(volatile unsigned short*) (0x30000000 + (0x38 + 7 << 1)) = tt_c;

      //--Display the '-'
      *(volatile unsigned short*) (0x30000000 + (0x38 + 5 << 1)) = ':';

      //2. Display the minutes data
      tt=0;
      //read_val_8b = *(volatile unsigned char *) (0xC0001000 + 0x01);
      read_val_8b = (time_2 >> 8);

      tt = tt + (((read_val_8b >> 0) & 0x1 ) * 1 ) ;
      tt = tt + (((read_val_8b >> 1) & 0x1 ) * 2 ) ;
      tt = tt + (((read_val_8b >> 2) & 0x1 ) * 4 ) ;
      tt = tt + (((read_val_8b >> 3) & 0x1 ) * 8 ) ;
      tt = tt + (((read_val_8b >> 4) & 0x1 ) * 10 ) ;
      tt = tt + (((read_val_8b >> 5) & 0x1 ) * 20 ) ;
      tt = tt + (((read_val_8b >> 6) & 0x1 ) * 40 ) ;

      //--Print upper char
      tt_c = (tt/10) + 48;
      *(volatile unsigned short*) (0x30000000 + (0x38 + 3 << 1)) = tt_c;
        
      //--Print lowar char
      tt_c = (tt/10) ;
      tt_c = tt - (tt_c*10) + 48;
      *(volatile unsigned short*) (0x30000000 + (0x38 + 4 << 1)) = tt_c;

      //--Display the '-'
      *(volatile unsigned short*) (0x30000000 + (0x38 + 2 << 1)) = ':';

      //3. Display the hours data
      tt=0;
      //read_val_8b = *(volatile unsigned char *) (0xC0001002 + 0x00);
      read_val_8b = (time_2 >> 16);

      tt = tt + (((read_val_8b >> 0) & 0x1 ) * 1 ) ;
      tt = tt + (((read_val_8b >> 1) & 0x1 ) * 2 ) ;
      tt = tt + (((read_val_8b >> 2) & 0x1 ) * 4 ) ;
      tt = tt + (((read_val_8b >> 3) & 0x1 ) * 8 ) ;
      tt = tt + (((read_val_8b >> 4) & 0x1 ) * 10 ) ;
      tt = tt + (((read_val_8b >> 5) & 0x1 ) * 20 ) ;

      //--Print upper char
      tt_c = (tt/10) + 48;
      *(volatile unsigned short*) (0x30000000 + (0x38 + 0 << 1)) = tt_c;
        
      //--Print lowar char
      tt_c = (tt/10) ;
      tt_c = tt - (tt_c*10) + 48;
      *(volatile unsigned short*) (0x30000000 + (0x38 + 1 << 1)) = tt_c;
}

/****************************************************************************/


void setNORflash_interface_gdc1()
{
    // EBIF_AD00 
    i32GPIO_EnableLatchFunction(PORT_D1RGB5, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB5, PORT_D1RGB5_AS_EBIF_AD00);
    i32GPIO_EnablePullUp(PORT_D1RGB5, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB5, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD01 
    i32GPIO_EnableLatchFunction(PORT_D1RGB6, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB6, PORT_D1RGB6_AS_EBIF_AD01);
    i32GPIO_EnablePullUp(PORT_D1RGB6, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB6, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD02 
    i32GPIO_EnableLatchFunction(PORT_D1RGB7, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB7, PORT_D1RGB7_AS_EBIF_AD02);
    i32GPIO_EnablePullUp(PORT_D1RGB7, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB7, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD03 
    i32GPIO_EnableLatchFunction(PORT_D1RGB8, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB8, PORT_D1RGB8_AS_EBIF_AD03);
    i32GPIO_EnablePullUp(PORT_D1RGB8, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB8, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD04
    i32GPIO_EnableLatchFunction(PORT_D1RGB9, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB9, PORT_D1RGB9_AS_EBIF_AD04);
    i32GPIO_EnablePullUp(PORT_D1RGB9, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB9, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD05
    i32GPIO_EnableLatchFunction(PORT_D1RGB10, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB10, PORT_D1RGB10_AS_EBIF_AD05);
    i32GPIO_EnablePullUp(PORT_D1RGB10, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB10, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD06
    i32GPIO_EnableLatchFunction(PORT_D1RGB11, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB11, PORT_D1RGB11_AS_EBIF_AD06);
    i32GPIO_EnablePullUp(PORT_D1RGB11, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB11, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD07
    i32GPIO_EnableLatchFunction(PORT_D1RGB12, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB12, PORT_D1RGB12_AS_EBIF_AD07);
    i32GPIO_EnablePullUp(PORT_D1RGB12, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB12, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD08
    i32GPIO_EnableLatchFunction(PORT_D1RGB13, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB13, PORT_D1RGB13_AS_EBIF_AD08);
    i32GPIO_EnablePullUp(PORT_D1RGB13, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB13, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD09
    i32GPIO_EnableLatchFunction(PORT_D1RGB14, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB14, PORT_D1RGB14_AS_EBIF_AD09);
    i32GPIO_EnablePullUp(PORT_D1RGB14, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB14, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD10
    i32GPIO_EnableLatchFunction(PORT_D1RGB15, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB15, PORT_D1RGB15_AS_EBIF_AD10);
    i32GPIO_EnablePullUp(PORT_D1RGB15, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB15, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD11
    i32GPIO_EnableLatchFunction(PORT_D1RGB16, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB16, PORT_D1RGB16_AS_EBIF_AD11);
    i32GPIO_EnablePullUp(PORT_D1RGB16, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB16, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD12
    i32GPIO_EnableLatchFunction(PORT_D1RGB17, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB17, PORT_D1RGB17_AS_EBIF_AD12);
    i32GPIO_EnablePullUp(PORT_D1RGB17, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB17, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD13
    i32GPIO_EnableLatchFunction(PORT_D1RGB18, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB18, PORT_D1RGB18_AS_EBIF_AD13);
    i32GPIO_EnablePullUp(PORT_D1RGB18, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB18, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD14
    i32GPIO_EnableLatchFunction(PORT_D1RGB19, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB19, PORT_D1RGB19_AS_EBIF_AD14);
    i32GPIO_EnablePullUp(PORT_D1RGB19, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB19, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AD15
    i32GPIO_EnableLatchFunction(PORT_D1RGB20, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB20, PORT_D1RGB20_AS_EBIF_AD15);
    i32GPIO_EnablePullUp(PORT_D1RGB20, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB20, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AEX0
    i32GPIO_EnableLatchFunction(PORT_D1RGB21, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB21, PORT_D1RGB21_AS_EBIF_AEX0);
    i32GPIO_EnablePullUp(PORT_D1RGB21, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB21, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AEX1
    i32GPIO_EnableLatchFunction(PORT_D1RGB22, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB22, PORT_D1RGB22_AS_EBIF_AEX1);
    i32GPIO_EnablePullUp(PORT_D1RGB22, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB22, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AEX2
    i32GPIO_EnableLatchFunction(PORT_D1RGB23, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB23, PORT_D1RGB23_AS_EBIF_AEX2);
    i32GPIO_EnablePullUp(PORT_D1RGB23, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB23, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AEX3
    i32GPIO_EnableLatchFunction(PORT_D1HDISP, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1HDISP, PORT_D1HDISP_AS_EBIF_AEX3);
    i32GPIO_EnablePullUp(PORT_D1HDISP, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1HDISP, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AEX4
    i32GPIO_EnableLatchFunction(PORT_D1HSYNC, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1HSYNC, PORT_D1HSYNC_AS_EBIF_AEX4);
    i32GPIO_EnablePullUp(PORT_D1HSYNC, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1HSYNC, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_AEX5
    i32GPIO_EnableLatchFunction(PORT_D1VSYNC, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1VSYNC, PORT_D1VSYNC_AS_EBIF_AEX5);
    i32GPIO_EnablePullUp(PORT_D1VSYNC, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1VSYNC, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_ALE
    i32GPIO_EnableLatchFunction(PORT_D1RGB0, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB0, PORT_D1RGB0_AS_EBIF_ALE);
    i32GPIO_EnablePullUp(PORT_D1RGB0, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB0, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_CS0
    i32GPIO_EnableLatchFunction(PORT_D1RGB1, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB1, PORT_D1RGB1_AS_EBIF_CS0);
    i32GPIO_EnablePullUp(PORT_D1RGB1, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB1, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_OE
    i32GPIO_EnableLatchFunction(PORT_D1RGB3, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB3, PORT_D1RGB3_AS_EBIF_OE);
    i32GPIO_EnablePullUp(PORT_D1RGB3, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB3, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_WE
    i32GPIO_EnableLatchFunction(PORT_D1RGB4, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_D1RGB4, PORT_D1RGB4_AS_EBIF_WE);
    i32GPIO_EnablePullUp(PORT_D1RGB4, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB4, GPIO_OUTPUT_RESISTANCE_50);
    // EBIF_WAITN
    i32GPIO_EnableLatchFunction(PORT_D1RGB2, GPIO_DISABLE);
    i32GPIO_EnablePullUp(PORT_D1RGB2, GPIO_DISABLE);
    i32GPIO_SetOutputResistance(PORT_D1RGB2, GPIO_OUTPUT_RESISTANCE_50);
}

/****************************************************************************/

/*************************  BEGIN of DISCLAIMER   ***************************

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

***************************  END of DISCALIMER  ****************************/

