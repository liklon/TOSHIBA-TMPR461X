/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Display parameter
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : GDC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.13 $
*   DATE        : $Date: 2015/06/05 10:52:12 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef DISP_PARAM_H
#define DISP_PARAM_H

/**********************************************
*                Include files                *
**********************************************/
#include "config.h"


/*****************************************************************************************
*
*                        D I S P L A Y    -    P A R A M E T E R S
*
*****************************************************************************************/

/*****************************************************************************************
* GDC0
*****************************************************************************************/
#if(DISPLAY_RESOLUTION_0 == QVGA_RES_50)
#define HPulseWidth_0     (51)      /* Horizontal pulse width */
#define HPeriod_0        (424)      /* line period            */
#define HBackPorch_0      (35)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse with    */
#define VPeriod_0        (262)      /* Vertical period        */
#define VBackPorch_0      (16)      /* Wait after V-Sync      */
#define ClockFrequency_0 (162)      /* 5,5 MHz                */
#endif

#if(DISPLAY_RESOLUTION_0 == QVGA_RES_60)
#define HPulseWidth_0     (51)      /* Horizontal pulse width */
#define HPeriod_0        (424)      /* line period            */
#define HBackPorch_0      (35)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse with    */
#define VPeriod_0        (262)      /* Vertical period        */
#define VBackPorch_0      (16)      /* Wait after V-Sync      */
#define ClockFrequency_0 (136)      /* 6,1 MHz                */
#endif

#if(DISPLAY_RESOLUTION_0 == HNTSC_RES_60)
#define HPulseWidth_0     (20)      /* Horizontal pulse width */
#define HPeriod_0        (607)      /* line period            */
#define HBackPorch_0      (15)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (247)      /* Vertical period        */
#define VBackPorch_0       (2)      /* Wait after V-Sync      */
#define ClockFrequency_0 (100)      /* 7,4 MHz                */
#endif

#if(DISPLAY_RESOLUTION_0 == HVGA_RES_50)
#define HPulseWidth_0      (5)      /* Horizontal pulse width */
#define HPeriod_0        (709)      /* line period            */
#define HBackPorch_0      (37)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (251)      /* Vertical period        */
#define VBackPorch_0       (7)      /* Wait after V-Sync      */
#define ClockFrequency_0 (101)      /* 8,9 MHz                */
#endif

#if(DISPLAY_RESOLUTION_0 == HVGA_RES_60)
#define HPulseWidth_0      (5)      /* Horizontal pulse width */
#define HPeriod_0        (709)      /* line period            */
#define HBackPorch_0      (37)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (251)      /* Vertical period        */
#define VBackPorch_0       (7)      /* Wait after V-Sync      */
#define ClockFrequency_0  (85)      /* 10,6 MHz               */
#endif

#if(DISPLAY_RESOLUTION_0 == WIDE_RES_50)
#define HPulseWidth_0     (96)      /* Horizontal pulse width */
#define HPeriod_0       (1230)      /* line period            */
#define HBackPorch_0      (48)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (270)      /* Vertical period        */
#define VBackPorch_0      (33)      /* Wait after V-Sync      */
#define ClockFrequency_0  (54)      /* 16,6 MHz               */
#endif

#if(DISPLAY_RESOLUTION_0 == WIDE_RES_60)
#define HPulseWidth_0     (96)      /* Horizontal pulse width */
#define HPeriod_0       (1230)      /* line period            */
#define HBackPorch_0      (48)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (270)      /* Vertical period        */
#define VBackPorch_0      (33)      /* Wait after V-Sync      */
#define ClockFrequency_0  (45)      /* 20,0 MHz               */
#endif

#if(DISPLAY_RESOLUTION_0 == VGA_RES_50)
#define HPulseWidth_0     (96)      /* Horizontal pulse width */
#define HPeriod_0        (800)      /* line period            */
#define HBackPorch_0      (48)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (33)      /* Wait after V-Sync      */
#define ClockFrequency_0  (43)      /* 21,0 MHz               */
#endif

#if(DISPLAY_RESOLUTION_0 == VGA_RES_60)
#define HPulseWidth_0     (96)      /* Horizontal pulse width */
#define HPeriod_0        (800)      /* line period            */
#define HBackPorch_0      (48)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (33)      /* Wait after V-Sync      */
#define ClockFrequency_0  (36)      /* 25,0 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == WVGA_RES_45)
#define HPulseWidth_0    (128)      /* Horizontal pulse width */
#define HPeriod_0       (1020)      /* line period            */
#define HBackPorch_0      (88)      /* Wait after H-sync.     */
#define VPulseWidth_0      (5)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (26)      /* Wait after V-Sync      */
#define ClockFrequency_0  (37)      /* 24,32 MHz              */
#endif

#if (DISPLAY_RESOLUTION_0 == WVGA_RES_50)
#define HPulseWidth_0    (128)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (88)      /* Wait after H-sync.     */
#define VPulseWidth_0      (5)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (30)      /* Wait after V-Sync      */
#define ClockFrequency_0  (33)      /* 27,27 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == WVGA_RES_55)
#define HPulseWidth_0    (128)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (88)      /* Wait after H-sync.     */
#define VPulseWidth_0      (5)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (26)      /* Wait after V-Sync      */
#define ClockFrequency_0  (29)      /* 31,03 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == WVGA_RES_60)
#if 1
#define HPulseWidth_0    (128)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (88)      /* Wait after H-sync.     */
#define VPulseWidth_0      (5)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (30)      /* Wait after V-Sync      */
#define ClockFrequency_0  (27)      /* 33,3 MHz               */
#else
#define HPulseWidth_0    (10)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (46)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (23)      /* Wait after V-Sync      */
#define ClockFrequency_0  (27)      /* 33,3 MHz               */
#endif
#endif

#if (DISPLAY_RESOLUTION_0 == SVGA_RES_50)
#define HPulseWidth_0    (128)      /* Horizontal pulse width */
#define HPeriod_0       (1024)      /* line period            */
#define HBackPorch_0      (58)      /* Wait after H-sync.     */
#define VPulseWidth_0      (4)      /* Vertical pulse width   */
#define VPeriod_0        (625)      /* Vertical period        */
#define VBackPorch_0      (17)      /* Wait after V-Sync      */
#define ClockFrequency_0  (28)      /* 32,1 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == SVGA_RES_60)
#define HPulseWidth_0    (128)      /* Horizontal pulse width */
#define HPeriod_0       (1024)      /* line period            */
#define HBackPorch_0      (58)      /* Wait after H-sync.     */
#define VPulseWidth_0      (4)      /* Vertical pulse width   */
#define VPeriod_0        (625)      /* Vertical period        */
#define VBackPorch_0      (17)      /* Wait after V-Sync      */
#define ClockFrequency_0  (23)      /* 39,1 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == DVGA_RES_50)
#define HPulseWidth_0    (112)	    /* Horizontal pulse width */
#define HPeriod_0       (1660)	    /* line period           	*/
#define HBackPorch_0     (249)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (2)	    /* Vertical pulse width   */
#define VPeriod_0        (525)	    /* Vertical period        */
#define VBackPorch_0      (40)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (21)      /* 42,8 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == DVGA_RES_60)
#define HPulseWidth_0    (112)	    /* Horizontal pulse width */
#define HPeriod_0       (1660)	    /* line period           	*/
#define HBackPorch_0     (249)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (2)	    /* Vertical pulse width   */
#define VPeriod_0        (525)	    /* Vertical period        */
#define VBackPorch_0      (40)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (17)      /* 52,9 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == DVGA_1_RES_50)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1386)	    /* line period           	*/
#define HBackPorch_0      (20)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (2)	    /* Vertical pulse width   */
#define VPeriod_0        (500)	    /* Vertical period        */
#define VBackPorch_0      (10)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (26)      /* 34,6 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == DVGA_1_RES_60)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1386)	    /* line period           	*/
#define HBackPorch_0      (20)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (2)	    /* Vertical pulse width   */
#define VPeriod_0        (500)	    /* Vertical period        */
#define VBackPorch_0      (10)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (22)      /* 40,9 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == XGA_RES_50)
#define HPulseWidth_0    (136)	    /* Horizontal pulse width */
#define HPeriod_0       (1344)	    /* line period            */
#define HBackPorch_0     (160)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (6)	    /* Vertical pulse width   */
#define VPeriod_0        (806)	    /* Vertical period        */
#define VBackPorch_0      (29)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (17)      /* 52,9 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == XGA_RES_60)
#define HPulseWidth_0    (136)	    /* Horizontal pulse width */
#define HPeriod_0       (1344)	    /* line period            */
#define HBackPorch_0     (160)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (6)	    /* Vertical pulse width   */
#define VPeriod_0        (806)	    /* Vertical period        */
#define VBackPorch_0      (29)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (14)      /* 64,3 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == SXGA_RES_50)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1386)	    /* line period           	*/
#define HBackPorch_0      (20)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (6)	    /* Vertical pulse width   */
#define VPeriod_0       (1050)	    /* Vertical period        */
#define VBackPorch_0      (17)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (13)      /* 69,23 MHz                 */
#endif

#if (DISPLAY_RESOLUTION_0 == SXGA_RES_60)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1386)	    /* line period           	*/
#define HBackPorch_0      (20)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (6)	    /* Vertical pulse width   */
#define VPeriod_0       (1050)	    /* Vertical period        */
#define VBackPorch_0      (17)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (11)      /* 81,81 MHz                 */
#endif

#if (DISPLAY_RESOLUTION_0 == HD_RES)
#define HPulseWidth_0     (10)      /* Horizontal pulse width */
#define HPeriod_0       (1386)      /* line period            */
#define HBackPorch_0      (20)      /* Wait after H-sync.     */
#define VPulseWidth_0      (6)      /* Vertical pulse width   */
#define VPeriod_0        (800)      /* Vertical period        */
#define VBackPorch_0      (17)      /* Wait after V-Sync      */
#define ClockFrequency_0  (13/*16*/)      /* 56,25 MHz              */
#endif

#if (DISPLAY_RESOLUTION_0 == HITACHI_TX31D06VM2AAA_RES_50)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1325)	    /* line period            */
#define HBackPorch_0      (17)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (1)	    /* Vertical pulse width   */
#define VPeriod_0        (483)	    /* Vertical period        */
#define VBackPorch_0       (1)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (28)      /* 32,0 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == HITACHI_TX31D06VM2AAA_RES_60)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1325)	    /* line period            */
#define HBackPorch_0      (17)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (1)	    /* Vertical pulse width   */
#define VPeriod_0        (483)	    /* Vertical period        */
#define VBackPorch_0       (1)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (24)      /* 37,5 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == SHARP_1280_422_50)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1536)	    /* line period            */
#define HBackPorch_0     (194)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (1)	    /* Vertical pulse width   */
#define VPeriod_0        (480)	    /* Vertical period        */
#define VBackPorch_0      (35)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (24)      /* 37,5 MHz                 */
#endif

#if (DISPLAY_RESOLUTION_0 == SHARP_1280_422_60)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1536)	    /* line period            */
#define HBackPorch_0     (194)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (1)	    /* Vertical pulse width   */
#define VPeriod_0        (480)	    /* Vertical period        */
#define VBackPorch_0      (35)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (20)      /* 45 MHz                 */
#endif

#if (DISPLAY_RESOLUTION_0 == TX18D35VM0AAA_50)
#define HPulseWidth_0    (128)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (88)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (26)      /* Wait after V-Sync      */
#define ClockFrequency_0  (33)      /* 27,27 MHz              */
#endif

#if (DISPLAY_RESOLUTION_0 == TX18D35VM0AAA_60)
#define HPulseWidth_0    (128)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (88)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (26)      /* Wait after V-Sync      */
#define ClockFrequency_0  (27)      /* 33,3 MHz               */
#endif

/* Settings obtained from online resources for 960*720 @ 50hz refresh rate*/
#if (DISPLAY_RESOLUTION_0 == RES_960_720_50)
#define HPulseWidth_0    (168)	    /* Horizontal pulse width */
#define HPeriod_0       (1192)	    /* line period            */
#define HBackPorch_0      (32)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (6)	    /* Vertical pulse width   */
#define VPeriod_0        (760)	    /* Vertical period        */
#define VBackPorch_0      (20)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (20)      /* 45,0 MHz              */
#endif
#if (DISPLAY_RESOLUTION_0 == AT070TN94_50)
#define HPulseWidth_0    (10)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (46)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (23)      /* Wait after V-Sync      */
#define ClockFrequency_0  (33)      /* 27 MHz               */
#endif
#if (DISPLAY_RESOLUTION_0 == AT070TN94_60)
#define HPulseWidth_0    (32)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (46)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (23)      /* Wait after V-Sync      */
#define ClockFrequency_0  (27)      /* 33,3 MHz               */
#endif
#if (DISPLAY_RESOLUTION_0 == TC90195_60)
#define HPulseWidth_0    (32)      /* Horizontal pulse width */
#define HPeriod_0       (1056)      /* line period            */
#define HBackPorch_0      (46)      /* Wait after H-sync.     */
#define VPulseWidth_0      (2)      /* Vertical pulse width   */
#define VPeriod_0        (525)      /* Vertical period        */
#define VBackPorch_0      (23)      /* Wait after V-Sync      */
#define ClockFrequency_0  (27)      /* 33,3 MHz               */
#endif

#if (DISPLAY_RESOLUTION_0 == CLAA121WB)
#define HPulseWidth_0    (112)	    /* Horizontal pulse width */
#define HPeriod_0       (1660)	    /* line period           	*/
#define HBackPorch_0     (249)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (10)	    /* Vertical pulse width   */
#define VPeriod_0        (525)	    /* Vertical period        */
#define VBackPorch_0      (40)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (17)      /* 52,9 MHz               */
#endif


#if (DISPLAY_RESOLUTION_0 == CLAA088WA)
#define HPulseWidth_0     (10)	    /* Horizontal pulse width */
#define HPeriod_0       (1386)	    /* line period           	*/
#define HBackPorch_0     (20)	    /* Wait after H-sync.     */
#define VPulseWidth_0      (2)	    /* Vertical pulse width   */
#define VPeriod_0        (506)	    /* Vertical period        */
#define VBackPorch_0      (10)	    /* Wait after V-Sync      */
#define ClockFrequency_0  (20)      /* 52,9 MHz               */
#endif


/* Set display size */
#if(DISPLAY_RESOLUTION_0 == QVGA_RES_50)
		#define GDC0_DISPLAY_WIDTH   (320)
		#define GDC0_DISPLAY_HEIGHT  (240)
#elif(DISPLAY_RESOLUTION_0 == QVGA_RES_60)
		#define GDC0_DISPLAY_WIDTH   (320)
		#define GDC0_DISPLAY_HEIGHT  (240)
#elif (DISPLAY_RESOLUTION_0 == HNTSC_RES_60)
		#define GDC0_DISPLAY_WIDTH   (480)
		#define GDC0_DISPLAY_HEIGHT  (240)
#elif (DISPLAY_RESOLUTION_0 == HVGA_RES_50)
		#define GDC0_DISPLAY_WIDTH   (640)
		#define GDC0_DISPLAY_HEIGHT  (240)
#elif (DISPLAY_RESOLUTION_0 == HVGA_RES_60)
		#define GDC0_DISPLAY_WIDTH   (640)
		#define GDC0_DISPLAY_HEIGHT  (240)
#elif (DISPLAY_RESOLUTION_0 == WIDE_RES_50)
		#define GDC0_DISPLAY_WIDTH  (1074)
		#define GDC0_DISPLAY_HEIGHT  (224)
#elif (DISPLAY_RESOLUTION_0 == WIDE_RES_60)
		#define GDC0_DISPLAY_WIDTH  (1074)
		#define GDC0_DISPLAY_HEIGHT  (224)
#elif (DISPLAY_RESOLUTION_0 == VGA_RES_50)
		#define GDC0_DISPLAY_WIDTH   (640)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == VGA_RES_60)
		#define GDC0_DISPLAY_WIDTH   (640)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == WVGA_RES_45)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == WVGA_RES_50)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == WVGA_RES_55)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == WVGA_RES_60)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == SVGA_RES_50)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (600)
#elif (DISPLAY_RESOLUTION_0 == SVGA_RES_60)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (600)
#elif (DISPLAY_RESOLUTION_0 == DVGA_RES_50)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == DVGA_RES_60)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == DVGA_1_RES_50)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == DVGA_1_RES_60)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == XGA_RES_50)
		#define GDC0_DISPLAY_WIDTH  (1024)
		#define GDC0_DISPLAY_HEIGHT  (768)
#elif (DISPLAY_RESOLUTION_0 == XGA_RES_60)
		#define GDC0_DISPLAY_WIDTH  (1024)
		#define GDC0_DISPLAY_HEIGHT  (768)
#elif (DISPLAY_RESOLUTION_0 == SXGA_RES_50)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (768)
#elif (DISPLAY_RESOLUTION_0 == SXGA_RES_60)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (768)
#elif (DISPLAY_RESOLUTION_0 == HD_RES)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT ( 720)
#elif (DISPLAY_RESOLUTION_0 == HITACHI_TX31D06VM2AAA_RES_50)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == HITACHI_TX31D06VM2AAA_RES_60)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == SHARP_1280_422_50)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (422)
#elif (DISPLAY_RESOLUTION_0 == SHARP_1280_422_60)
		#define GDC0_DISPLAY_WIDTH  (1280)
		#define GDC0_DISPLAY_HEIGHT  (422)
#elif (DISPLAY_RESOLUTION_0 == TX18D35VM0AAA_50)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == TX18D35VM0AAA_60)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == RES_960_720_50)
		#define GDC0_DISPLAY_WIDTH  (960)
		#define GDC0_DISPLAY_HEIGHT (720)
#elif (DISPLAY_RESOLUTION_0 == AT070TN94_50)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == AT070TN94_60)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == TC90195_60)
		#define GDC0_DISPLAY_WIDTH   (800)
		#define GDC0_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_0 == CLAA121WB)
		#define GDC0_DISPLAY_WIDTH   (1280)
		#define GDC0_DISPLAY_HEIGHT  (420)	
#elif (DISPLAY_RESOLUTION_0 == CLAA088WA)
		#define GDC0_DISPLAY_WIDTH   (1280)
		#define GDC0_DISPLAY_HEIGHT  (480)	

#else
		#error Resolution not Defined and/or not supported !!!
#endif



/*****************************************************************************************
* GDC1
*****************************************************************************************/
#if(DISPLAY_RESOLUTION_1 == QVGA_RES_50)
#define HPulseWidth_1     (51)      /* Horizontal pulse width */
#define HPeriod_1        (424)      /* line period            */
#define HBackPorch_1      (35)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse with    */
#define VPeriod_1        (262)      /* Vertical period        */
#define VBackPorch_1      (16)      /* Wait after V-Sync      */
#define ClockFrequency_1 (162)      /* 5,5 MHz                */
#endif

#if(DISPLAY_RESOLUTION_1 == QVGA_RES_60)
#define HPulseWidth_1     (51)      /* Horizontal pulse width */
#define HPeriod_1        (424)      /* line period            */
#define HBackPorch_1      (35)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse with    */
#define VPeriod_1        (262)      /* Vertical period        */
#define VBackPorch_1      (16)      /* Wait after V-Sync      */
#define ClockFrequency_1 (136)      /* 6,1 MHz                */
#endif

#if(DISPLAY_RESOLUTION_1 == HNTSC_RES_60)
#define HPulseWidth_1     (20)      /* Horizontal pulse width */
#define HPeriod_1        (607)      /* line period            */
#define HBackPorch_1      (15)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (247)      /* Vertical period        */
#define VBackPorch_1       (2)      /* Wait after V-Sync      */
#define ClockFrequency_1 (100)      /* 7,4 MHz                */
#endif

#if(DISPLAY_RESOLUTION_1 == HVGA_RES_50)
#define HPulseWidth_1      (5)      /* Horizontal pulse width */
#define HPeriod_1        (709)      /* line period            */
#define HBackPorch_1      (37)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (251)      /* Vertical period        */
#define VBackPorch_1       (7)      /* Wait after V-Sync      */
#define ClockFrequency_1 (101)      /* 8,9 MHz                */
#endif

#if(DISPLAY_RESOLUTION_1 == HVGA_RES_60)
#define HPulseWidth_1      (5)      /* Horizontal pulse width */
#define HPeriod_1        (709)      /* line period            */
#define HBackPorch_1      (37)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (251)      /* Vertical period        */
#define VBackPorch_1       (7)      /* Wait after V-Sync      */
#define ClockFrequency_1  (85)      /* 10,6 MHz               */
#endif

#if(DISPLAY_RESOLUTION_1 == WIDE_RES_50)
#define HPulseWidth_1     (96)      /* Horizontal pulse width */
#define HPeriod_1       (1230)      /* line period            */
#define HBackPorch_1      (48)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (270)      /* Vertical period        */
#define VBackPorch_1      (33)      /* Wait after V-Sync      */
#define ClockFrequency_1  (54)      /* 16,6 MHz               */
#endif

#if(DISPLAY_RESOLUTION_1 == WIDE_RES_60)
#define HPulseWidth_1     (96)      /* Horizontal pulse width */
#define HPeriod_1       (1230)      /* line period            */
#define HBackPorch_1      (48)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (270)      /* Vertical period        */
#define VBackPorch_1      (33)      /* Wait after V-Sync      */
#define ClockFrequency_1  (45)      /* 20,0 MHz               */
#endif

#if(DISPLAY_RESOLUTION_1 == VGA_RES_50)
#define HPulseWidth_1     (96)      /* Horizontal pulse width */
#define HPeriod_1        (800)      /* line period            */
#define HBackPorch_1      (48)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (525)      /* Vertical period        */
#define VBackPorch_1      (33)      /* Wait after V-Sync      */
#define ClockFrequency_1  (43)      /* 21,0 MHz               */
#endif

#if(DISPLAY_RESOLUTION_1 == VGA_RES_60)
#define HPulseWidth_1     (96)      /* Horizontal pulse width */
#define HPeriod_1        (800)      /* line period            */
#define HBackPorch_1      (48)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (525)      /* Vertical period        */
#define VBackPorch_1      (33)      /* Wait after V-Sync      */
#define ClockFrequency_1  (36)      /* 25,0 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == WVGA_RES_45)
#define HPulseWidth_1    (128)      /* Horizontal pulse width */
#define HPeriod_1       (1020)      /* line period            */
#define HBackPorch_1      (88)      /* Wait after H-sync.     */
#define VPulseWidth_1      (5)      /* Vertical pulse width   */
#define VPeriod_1        (525)      /* Vertical period        */
#define VBackPorch_1      (26)      /* Wait after V-Sync      */
#define ClockFrequency_1  (37)      /* 24,32 MHz              */
#endif

#if (DISPLAY_RESOLUTION_1 == WVGA_RES_50)
#define HPulseWidth_1    (128)      /* Horizontal pulse width */
#define HPeriod_1       (1056)      /* line period            */
#define HBackPorch_1      (88)      /* Wait after H-sync.     */
#define VPulseWidth_1      (5)      /* Vertical pulse width   */
#define VPeriod_1        (525)      /* Vertical period        */
#define VBackPorch_1      (30)      /* Wait after V-Sync      */
#define ClockFrequency_1  (33)      /* 27,27 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == WVGA_RES_55)
#define HPulseWidth_1    (128)      /* Horizontal pulse width */
#define HPeriod_1       (1056)      /* line period            */
#define HBackPorch_1      (88)      /* Wait after H-sync.     */
#define VPulseWidth_1      (5)      /* Vertical pulse width   */
#define VPeriod_1        (525)      /* Vertical period        */
#define VBackPorch_1      (26)      /* Wait after V-Sync      */
#define ClockFrequency_1  (29)      /* 31,03 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == WVGA_RES_60)
#define HPulseWidth_1    (128)      /* Horizontal pulse width */
#define HPeriod_1       (1056)      /* line period            */
#define HBackPorch_1      (88)      /* Wait after H-sync.     */
#define VPulseWidth_1      (5)      /* Vertical pulse width   */
#define VPeriod_1        (525)      /* Vertical period        */
#define VBackPorch_1      (30)      /* Wait after V-Sync      */
#define ClockFrequency_1  (27)      /* 33,3 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == SVGA_RES_50)
#define HPulseWidth_1    (128)      /* Horizontal pulse width */
#define HPeriod_1       (1024)      /* line period            */
#define HBackPorch_1      (58)      /* Wait after H-sync.     */
#define VPulseWidth_1      (4)      /* Vertical pulse width   */
#define VPeriod_1        (625)      /* Vertical period        */
#define VBackPorch_1      (17)      /* Wait after V-Sync      */
#define ClockFrequency_1  (28)      /* 32,1 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == SVGA_RES_60)
#define HPulseWidth_1    (128)      /* Horizontal pulse width */
#define HPeriod_1       (1024)      /* line period            */
#define HBackPorch_1      (58)      /* Wait after H-sync.     */
#define VPulseWidth_1      (4)      /* Vertical pulse width   */
#define VPeriod_1        (625)      /* Vertical period        */
#define VBackPorch_1      (17)      /* Wait after V-Sync      */
#define ClockFrequency_1  (23)      /* 39,1 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == DVGA_RES_50)
#define HPulseWidth_1    (112)	    /* Horizontal pulse width */
#define HPeriod_1       (1660)	    /* line period           	*/
#define HBackPorch_1     (249)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (2)	    /* Vertical pulse width   */
#define VPeriod_1        (525)	    /* Vertical period        */
#define VBackPorch_1      (40)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (21)      /* 42,8 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == DVGA_RES_60)
#define HPulseWidth_1    (112)	    /* Horizontal pulse width */
#define HPeriod_1       (1660)	    /* line period           	*/
#define HBackPorch_1     (249)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (2)	    /* Vertical pulse width   */
#define VPeriod_1        (525)	    /* Vertical period        */
#define VBackPorch_1      (40)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (17)      /* 52,9 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == DVGA_1_RES_50)
#define HPulseWidth_1     (10)	    /* Horizontal pulse width */
#define HPeriod_1       (1386)	    /* line period           	*/
#define HBackPorch_1      (20)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (2)	    /* Vertical pulse width   */
#define VPeriod_1        (500)	    /* Vertical period        */
#define VBackPorch_1      (10)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (26)      /* 34,6 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == DVGA_1_RES_60)
#define HPulseWidth_1     (10)	    /* Horizontal pulse width */
#define HPeriod_1       (1386)	    /* line period           	*/
#define HBackPorch_1      (20)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (2)	    /* Vertical pulse width   */
#define VPeriod_1        (500)	    /* Vertical period        */
#define VBackPorch_1      (10)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (22)      /* 40,9 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == XGA_RES_50)
#define HPulseWidth_1    (136)	    /* Horizontal pulse width */
#define HPeriod_1       (1344)	    /* line period            */
#define HBackPorch_1     (160)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (6)	    /* Vertical pulse width   */
#define VPeriod_1        (806)	    /* Vertical period        */
#define VBackPorch_1      (29)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (17)      /* 52,9 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == XGA_RES_60)
#define HPulseWidth_1    (136)	    /* Horizontal pulse width */
#define HPeriod_1       (1344)	    /* line period            */
#define HBackPorch_1     (160)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (6)	    /* Vertical pulse width   */
#define VPeriod_1        (806)	    /* Vertical period        */
#define VBackPorch_1      (29)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (14)      /* 64,3 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == SXGA_RES_50)
#define HPulseWidth_1     (10)	    /* Horizontal pulse width */
#define HPeriod_1       (1386)	    /* line period           	*/
#define HBackPorch_1      (20)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (6)	    /* Vertical pulse width   */
#define VPeriod_1       (1050)	    /* Vertical period        */
#define VBackPorch_1      (17)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (13)      /* 69,23 MHz                 */
#endif

#if (DISPLAY_RESOLUTION_1 == SXGA_RES_60)
#define HPulseWidth_1     (10)	    /* Horizontal pulse width */
#define HPeriod_1       (1386)	    /* line period           	*/
#define HBackPorch_1      (20)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (6)	    /* Vertical pulse width   */
#define VPeriod_1       (1050)	    /* Vertical period        */
#define VBackPorch_1      (17)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (11)      /* 81,81 MHz                 */
#endif

#if (DISPLAY_RESOLUTION_1 == HD_RES)
#define HPulseWidth_1     (10)      /* Horizontal pulse width */
#define HPeriod_1       (1386)      /* line period            */
#define HBackPorch_1      (20)      /* Wait after H-sync.     */
#define VPulseWidth_1      (6)      /* Vertical pulse width   */
#define VPeriod_1        (800)      /* Vertical period        */
#define VBackPorch_1      (17)      /* Wait after V-Sync      */
#define ClockFrequency_1  (13/*16*/)      /* 56,25 MHz              */
#endif

#if (DISPLAY_RESOLUTION_1 == HITACHI_TX31D06VM2AAA_RES_50)
#define HPulseWidth_1     (10)	    /* Horizontal pulse width */
#define HPeriod_1       (1325)	    /* line period            */
#define HBackPorch_1      (17)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (1)	    /* Vertical pulse width   */
#define VPeriod_1        (483)	    /* Vertical period        */
#define VBackPorch_1       (1)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (28)      /* 32,0 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == HITACHI_TX31D06VM2AAA_RES_60)
#define HPulseWidth_1     (10)	    /* Horizontal pulse width */
#define HPeriod_1       (1325)	    /* line period            */
#define HBackPorch_1      (17)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (1)	    /* Vertical pulse width   */
#define VPeriod_1        (483)	    /* Vertical period        */
#define VBackPorch_1       (1)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (24)      /* 37,5 MHz               */
#endif

#if (DISPLAY_RESOLUTION_1 == SHARP_1280_422_50)
#define HPulseWidth_1     (10)	    /* Horizontal pulse width */
#define HPeriod_1       (1536)	    /* line period            */
#define HBackPorch_1     (194)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (1)	    /* Vertical pulse width   */
#define VPeriod_1        (480)	    /* Vertical period        */
#define VBackPorch_1      (35)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (24)      /* 37,5 MHz                 */
#endif

#if (DISPLAY_RESOLUTION_1 == SHARP_1280_422_60)
#define HPulseWidth_1     (10)	    /* Horizontal pulse width */
#define HPeriod_1       (1536)	    /* line period            */
#define HBackPorch_1     (194)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (1)	    /* Vertical pulse width   */
#define VPeriod_1        (480)	    /* Vertical period        */
#define VBackPorch_1      (35)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (20)      /* 45 MHz                 */
#endif

#if (DISPLAY_RESOLUTION_1 == TX18D35VM0AAA_50)
#define HPulseWidth_1    (128)      /* Horizontal pulse width */
#define HPeriod_1       (1056)      /* line period            */
#define HBackPorch_1      (88)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (525)      /* Vertical period        */
#define VBackPorch_1      (26)      /* Wait after V-Sync      */
#define ClockFrequency_1  (33)      /* 27,27 MHz              */
#endif

#if (DISPLAY_RESOLUTION_1 == TX18D35VM0AAA_60)
#define HPulseWidth_1    (128)      /* Horizontal pulse width */
#define HPeriod_1       (1056)      /* line period            */
#define HBackPorch_1      (88)      /* Wait after H-sync.     */
#define VPulseWidth_1      (2)      /* Vertical pulse width   */
#define VPeriod_1        (525)      /* Vertical period        */
#define VBackPorch_1      (26)      /* Wait after V-Sync      */
#define ClockFrequency_1  (27)      /* 33,3 MHz               */
#endif

/* Settings obtained from online resources for 960*720 @ 50hz refresh rate*/
#if (DISPLAY_RESOLUTION_1 == RES_960_720_50)
#define HPulseWidth_1    (168)	    /* Horizontal pulse width */
#define HPeriod_1       (1192)	    /* line period            */
#define HBackPorch_1      (32)	    /* Wait after H-sync.     */
#define VPulseWidth_1      (6)	    /* Vertical pulse width   */
#define VPeriod_1        (760)	    /* Vertical period        */
#define VBackPorch_1      (20)	    /* Wait after V-Sync      */
#define ClockFrequency_1  (20)      /* 45,0 MHz                 */
#endif


/* Set display size */
#if(DISPLAY_RESOLUTION_1 == QVGA_RES_50)
		#define GDC1_DISPLAY_WIDTH   (320)
		#define GDC1_DISPLAY_HEIGHT  (240)
#elif(DISPLAY_RESOLUTION_1 == QVGA_RES_60)
		#define GDC1_DISPLAY_WIDTH   (320)
		#define GDC1_DISPLAY_HEIGHT  (240)
#elif (DISPLAY_RESOLUTION_1 == HNTSC_RES_60)
		#define GDC1_DISPLAY_WIDTH   (480)
		#define GDC1_DISPLAY_HEIGHT  (240)
#elif (DISPLAY_RESOLUTION_1 == HVGA_RES_50)
		#define GDC1_DISPLAY_WIDTH   (640)
		#define GDC1_DISPLAY_HEIGHT  (240)
#elif (DISPLAY_RESOLUTION_1 == HVGA_RES_60)
		#define GDC1_DISPLAY_WIDTH   (640)
		#define GDC1_DISPLAY_HEIGHT  (240)
#elif (DISPLAY_RESOLUTION_1 == WIDE_RES_50)
		#define GDC1_DISPLAY_WIDTH  (1074)
		#define GDC1_DISPLAY_HEIGHT  (224)
#elif (DISPLAY_RESOLUTION_1 == WIDE_RES_60)
		#define GDC1_DISPLAY_WIDTH  (1074)
		#define GDC1_DISPLAY_HEIGHT  (224)
#elif (DISPLAY_RESOLUTION_1 == VGA_RES_50)
		#define GDC1_DISPLAY_WIDTH   (640)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == VGA_RES_60)
		#define GDC1_DISPLAY_WIDTH   (640)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == WVGA_RES_45)
		#define GDC1_DISPLAY_WIDTH   (800)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == WVGA_RES_50)
		#define GDC1_DISPLAY_WIDTH   (800)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == WVGA_RES_55)
		#define GDC1_DISPLAY_WIDTH   (800)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == WVGA_RES_60)
		#define GDC1_DISPLAY_WIDTH   (800)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == SVGA_RES_50)
		#define GDC1_DISPLAY_WIDTH   (800)
		#define GDC1_DISPLAY_HEIGHT  (600)
#elif (DISPLAY_RESOLUTION_1 == SVGA_RES_60)
		#define GDC1_DISPLAY_WIDTH   (800)
		#define GDC1_DISPLAY_HEIGHT  (600)
#elif (DISPLAY_RESOLUTION_1 == DVGA_RES_50)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == DVGA_RES_60)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == DVGA_1_RES_50)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == DVGA_1_RES_60)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == XGA_RES_50)
		#define GDC1_DISPLAY_WIDTH  (1024)
		#define GDC1_DISPLAY_HEIGHT  (768)
#elif (DISPLAY_RESOLUTION_1 == XGA_RES_60)
		#define GDC1_DISPLAY_WIDTH  (1024)
		#define GDC1_DISPLAY_HEIGHT  (768)
#elif (DISPLAY_RESOLUTION_1 == SXGA_RES_50)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (768)
#elif (DISPLAY_RESOLUTION_1 == SXGA_RES_60)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (768)
#elif (DISPLAY_RESOLUTION_1 == HD_RES)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT ( 720)
#elif (DISPLAY_RESOLUTION_1 == HITACHI_TX31D06VM2AAA_RES_50)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == HITACHI_TX31D06VM2AAA_RES_60)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == SHARP_1280_422_50)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (422)
#elif (DISPLAY_RESOLUTION_1 == SHARP_1280_422_60)
		#define GDC1_DISPLAY_WIDTH  (1280)
		#define GDC1_DISPLAY_HEIGHT  (422)
#elif (DISPLAY_RESOLUTION_1 == TX18D35VM0AAA_50)
		#define GDC1_DISPLAY_WIDTH   (800)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == TX18D35VM0AAA_60)
		#define GDC1_DISPLAY_WIDTH   (800)
		#define GDC1_DISPLAY_HEIGHT  (480)
#elif (DISPLAY_RESOLUTION_1 == RES_960_720_50)
		#define GDC1_DISPLAY_WIDTH  (960)
		#define GDC1_DISPLAY_HEIGHT (720)
#else
		#error Resolution not Defined and/or not supported !!!
#endif


#endif /* DISP_PARAM_H */

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
