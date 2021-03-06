/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   DESCRIPTION : Middleware Buffer definition
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Middleware
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.6 $
*   DATE        : $Date: 2015/06/05 13:48:13 $
*   TAG         : $Name: Graphic_Middleware_V1_5 $
*   RELEASE     : Preliminary & Confidential
****************************************************************************/
#ifndef FBUFFER_H
#define FBUFFER_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "config.h"
#include "gf.h"
#include "ga.h"

/**********************************************
*               Defs                          *
**********************************************/


/**********************************************
*               Structs                       *
**********************************************/


/**********************************************
*         External variables                  *
**********************************************/
/* Command-Lists */
extern ga_list_st* pstExecList;
extern ga_list_st* pstWriteList;


#ifdef LAYERA_FULL_SIZE
/* For asymmetric GDC0/1 setup, set the effective layer width */
    #define GDC0_LAYERA_EFF_WIDTH (GDC0_LAYERA_WIDTH + GDC1_LAYERA_WIDTH)
#else
    #define GDC0_LAYERA_EFF_WIDTH (GDC0_LAYERA_WIDTH)
#endif

#ifdef LAYERB_FULL_SIZE
/* For asymmetric GDC0/1 setup, set the effective layer width */
    #define GDC0_LAYERB_EFF_WIDTH (GDC0_LAYERB_WIDTH + GDC1_LAYERB_WIDTH)
#else
    #define GDC0_LAYERB_EFF_WIDTH (GDC0_LAYERB_WIDTH)
#endif

#ifdef LAYERC_FULL_SIZE
/* For asymmetric GDC0/1 setup, set the effective layer width */
    #define GDC0_LAYERC_EFF_WIDTH (GDC0_LAYERC_WIDTH + GDC1_LAYERC_WIDTH)
#else
    #define GDC0_LAYERC_EFF_WIDTH (GDC0_LAYERC_WIDTH)
#endif

#ifdef LAYERD_FULL_SIZE
/* For asymmetric GDC0/1 setup, set the effective layer width */
    #define GDC0_LAYERD_EFF_WIDTH (GDC0_LAYERD_WIDTH + GDC1_LAYERD_WIDTH)
#else
    #define GDC0_LAYERD_EFF_WIDTH (GDC0_LAYERD_WIDTH)
#endif

#ifdef LAYERE_FULL_SIZE
/* For asymmetric GDC0/1 setup, set the effective layer width */
    #define GDC0_LAYERE_EFF_WIDTH (GDC0_LAYERE_WIDTH + GDC1_LAYERE_WIDTH)
#else
    #define GDC0_LAYERE_EFF_WIDTH (GDC0_LAYERE_WIDTH)
#endif

/* GDC 0 Frame Buffers */
#if (GDCx0 == ON)

/* GDC0 framebuffer */
#if (GDC0_LAYER_A == ON)
		#if(GDC0_LAYER_A_COLOR_FORMAT != FMT_OFF)
				#if(GDC0_LAYER_A_COLOR_FORMAT == FMT_RGB16)
						extern  uint16_t FBuffRGB_GDC0_A0 [GDC0_LAYERA_EFF_WIDTH*GDC0_LAYERA_HEIGHT];
						#if(GDC0_LAYER_A_DOUBLEFUFFERING == ON)
								extern  uint16_t FBuffRGB_GDC0_A1 [GDC0_LAYERA_EFF_WIDTH*GDC0_LAYERA_HEIGHT];
						#endif
				#else
						extern  uint32_t FBuffRGBA_GDC0_A0 [GDC0_LAYERA_EFF_WIDTH*GDC0_LAYERA_HEIGHT];
						#if(GDC0_LAYER_A_DOUBLEFUFFERING == ON)
								extern  uint32_t FBuffRGBA_GDC0_A1 [GDC0_LAYERA_EFF_WIDTH*GDC0_LAYERA_HEIGHT];
						#endif
				#endif
		#endif
#endif

#if (GDC0_LAYER_B == ON)
		#if(GDC0_LAYER_B_COLOR_FORMAT == FMT_RGB16)
				extern  uint16_t FBuffRGB_GDC0_B0 [GDC0_LAYERB_EFF_WIDTH*GDC0_LAYERB_HEIGHT];
				#if(GDC0_LAYER_B_DOUBLEFUFFERING == ON)
						extern  uint16_t FBuffRGB_GDC0_B1 [GDC0_LAYERB_EFF_WIDTH*GDC0_LAYERB_HEIGHT];
				#endif
		#else
				extern  uint32_t FBuffRGBA_GDC0_B0 [GDC0_LAYERB_EFF_WIDTH*GDC0_LAYERB_HEIGHT];
				#if(GDC0_LAYER_B_DOUBLEFUFFERING == ON)
						extern  uint32_t FBuffRGBA_GDC0_B1 [GDC0_LAYERB_EFF_WIDTH*GDC0_LAYERB_HEIGHT];
				#endif
		#endif
#endif

#if (GDC0_LAYER_C == ON)
		#if(GDC0_LAYER_C_COLOR_FORMAT == FMT_RGB16)
				extern  uint16_t FBuffRGB_GDC0_C0 [GDC0_LAYERC_EFF_WIDTH*GDC0_LAYERC_HEIGHT];
				#if(GDC0_LAYER_C_DOUBLEFUFFERING == ON)
						extern  uint16_t FBuffRGB_GDC0_C1 [GDC0_LAYERC_EFF_WIDTH*GDC0_LAYERC_HEIGHT];
				#endif
		#else
				extern  uint32_t FBuffRGBA_GDC0_C0 [GDC0_LAYERC_EFF_WIDTH*GDC0_LAYERC_HEIGHT];
				#if(GDC0_LAYER_C_DOUBLEFUFFERING == ON)
						extern  uint32_t FBuffRGBA_GDC0_C1 [GDC0_LAYERC_EFF_WIDTH*GDC0_LAYERC_HEIGHT];
				#endif
		#endif
#endif

#if(GDC0_LAYER_D == ON)
		#if(GDC0_LAYER_D_COLOR_FORMAT == FMT_RGB16)
				extern  uint16_t FBuffRGB_GDC0_D0 [GDC0_LAYERD_EFF_WIDTH*GDC0_LAYERD_HEIGHT];
				#if(GDC0_LAYER_D_DOUBLEFUFFERING == ON)
						extern  uint16_t FBuffRGB_GDC0_D1 [GDC0_LAYERD_EFF_WIDTH*GDC0_LAYERD_HEIGHT];
				#endif
		#else
				extern  uint32_t FBuffRGBA_GDC0_D0 [GDC0_LAYERD_EFF_WIDTH*GDC0_LAYERD_HEIGHT];
				#if(GDC0_LAYER_D_DOUBLEFUFFERING == ON)
						extern  uint32_t FBuffRGBA_GDC0_D1 [GDC0_LAYERD_EFF_WIDTH*GDC0_LAYERD_HEIGHT];
				#endif
		#endif
#endif

#if(GDC0_LAYER_E == ON)
		#if(GDC0_LAYER_E_COLOR_FORMAT == FMT_RGB16)
				extern  uint16_t FBuffRGB_GDC0_E0 [GDC0_LAYERE_EFF_WIDTH*GDC0_LAYERE_HEIGHT];
				#if(GDC0_LAYER_E_DOUBLEFUFFERING == ON)
						extern  uint16_t FBuffRGB_GDC0_E1 [GDC0_LAYERE_EFF_WIDTH*GDC0_LAYERE_HEIGHT];
				#endif
		#else
				extern  uint32_t FBuffRGBA_GDC0_E0 [GDC0_LAYERE_EFF_WIDTH*GDC0_LAYERE_HEIGHT];
				#if(GDC0_LAYER_E_DOUBLEFUFFERING == ON)
						extern  uint32_t FBuffRGBA_GDC0_E1 [GDC0_LAYERE_EFF_WIDTH*GDC0_LAYERE_HEIGHT];
				#endif
		#endif
#endif

#endif /* GDC0 */


/* GDC 1 Frame Buffers */
#if (GDCx1 == ON)

#ifndef LAYERA_FULL_SIZE
    /* GDC1 framebuffer */
    #if(GDC1_LAYER_A == ON)
            #if(GDC1_LAYER_A_COLOR_FORMAT == FMT_RGB16)
                    extern  uint16_t FBuffRGB_GDC1_A0 [GDC1_LAYERA_HEIGHT*GDC1_LAYERA_WIDTH];
                    #if(GDC1_LAYER_A_DOUBLEFUFFERING == ON)
                            extern  uint16_t FBuffRGB_GDC1_A1 [GDC1_LAYERA_HEIGHT*GDC1_LAYERA_WIDTH];
                    #endif
            #else
                    extern  uint32_t FBuffRGBA_GDC1_A0 [GDC1_LAYERA_HEIGHT*GDC1_LAYERA_WIDTH];
                    #if(GDC1_LAYER_A_DOUBLEFUFFERING == ON)
                            extern  uint32_t FBuffRGBA_GDC1_A1 [GDC1_LAYERA_HEIGHT*GDC1_LAYERA_WIDTH];
                    #endif
            #endif
    #endif
#endif

#ifndef LAYERB_FULL_SIZE
    #if(GDC1_LAYER_B == ON)
            #if(GDC1_LAYER_B_COLOR_FORMAT == FMT_RGB16)
                    extern  uint16_t FBuffRGB_GDC1_B0 [GDC1_LAYERB_HEIGHT*GDC1_LAYERB_WIDTH];
                    #if(GDC1_LAYER_B_DOUBLEFUFFERING == ON)
                            extern  uint16_t FBuffRGB_GDC1_B1 [GDC1_LAYERB_HEIGHT*GDC1_LAYERB_WIDTH];
                    #endif
            #else
                    extern  uint32_t FBuffRGBA_GDC1_B0 [GDC1_LAYERB_HEIGHT*GDC1_LAYERB_WIDTH];
                    #if(GDC1_LAYER_B_DOUBLEFUFFERING == ON)
                            extern  uint32_t FBuffRGBA_GDC1_B1 [GDC1_LAYERB_HEIGHT*GDC1_LAYERB_WIDTH];
                    #endif
            #endif
    #endif
#endif

#ifndef LAYERC_FULL_SIZE
    #if(GDC1_LAYER_C == ON)
            #if(GDC1_LAYER_C_COLOR_FORMAT == FMT_RGB16)
                    extern  uint16_t FBuffRGB_GDC1_C0 [GDC1_LAYERC_HEIGHT*GDC1_LAYERC_WIDTH];
                    #if(GDC1_LAYER_C_DOUBLEFUFFERING == ON)
                            extern  uint16_t FBuffRGB_GDC1_C1 [GDC1_LAYERC_HEIGHT*GDC1_LAYERC_WIDTH];
                    #endif
            #else
                    extern  uint32_t FBuffRGBA_GDC1_C0 [GDC1_LAYERC_HEIGHT*GDC1_LAYERC_WIDTH];
                    #if(GDC1_LAYER_C_DOUBLEFUFFERING == ON)
                            extern  uint32_t FBuffRGBA_GDC1_C1 [GDC1_LAYERC_HEIGHT*GDC1_LAYERC_WIDTH];
                    #endif
            #endif
    #endif
#endif

#ifndef LAYERD_FULL_SIZE
    #if(GDC1_LAYER_D == ON)
            #if(GDC1_LAYER_D_COLOR_FORMAT == FMT_RGB16)
                    extern  uint16_t FBuffRGB_GDC1_D0 [GDC1_LAYERD_HEIGHT*GDC1_LAYERD_WIDTH];
                    #if(GDC1_LAYER_D_DOUBLEFUFFERING == ON)
                            extern  uint16_t FBuffRGB_GDC1_D1 [GDC1_LAYERD_HEIGHT*GDC1_LAYERD_WIDTH];
                    #endif
            #else
                    extern  uint32_t FBuffRGBA_GDC1_D0 [GDC1_LAYERD_HEIGHT*GDC1_LAYERD_WIDTH];
                    #if(GDC1_LAYER_D_DOUBLEFUFFERING == ON)
                            extern  uint32_t FBuffRGBA_GDC1_D1 [GDC1_LAYERD_HEIGHT*GDC1_LAYERD_WIDTH];
                    #endif
            #endif
    #endif
#endif

#ifndef LAYERE_FULL_SIZE
    #if(GDC1_LAYER_E == ON)
            #if(GDC1_LAYER_E_COLOR_FORMAT == FMT_RGB16)
                    extern  uint16_t FBuffRGB_GDC1_E0 [GDC1_LAYERE_HEIGHT*GDC1_LAYERE_WIDTH];
                    #if(GDC1_LAYER_E_DOUBLEFUFFERING == ON)
                            extern  uint16_t FBuffRGB_GDC1_E1 [GDC1_LAYERE_HEIGHT*GDC1_LAYERE_WIDTH];
                    #endif
            #else
                    extern  uint32_t FBuffRGBA_GDC1_E0 [GDC1_LAYERE_HEIGHT*GDC1_LAYERE_WIDTH];
                    #if(GDC1_LAYER_E_DOUBLEFUFFERING == ON)
                            extern  uint32_t FBuffRGBA_GDC1_E1 [GDC1_LAYERE_HEIGHT*GDC1_LAYERE_WIDTH];
                    #endif
            #endif
    #endif
#endif
#endif /* GDC1 */

/* FG Frame Buffers */
#if (FRAMEGRABBER == ON)

#if(FG_BUFFER_1 == ON)
		#if(FG_BUFFER_COLOR_FORMAT == FMT_RGB16)
				extern  uint16_t FG_RGBBuff_0 [FG_BUFFER_HEIGHT*FG_BUFFER_WIDTH];
		#else
				extern  uint32_t FG_RGBABuff_0 [FG_BUFFER_HEIGHT*FG_BUFFER_WIDTH];
		#endif
#endif

#if(FG_BUFFER_2 == ON)
		#if(FG_BUFFER_COLOR_FORMAT == FMT_RGB16)
				extern  uint16_t FG_RGBBuff_1 [FG_BUFFER_HEIGHT*FG_BUFFER_WIDTH];
		#else
				extern  uint32_t FG_RGBABuff_1 [FG_BUFFER_HEIGHT*FG_BUFFER_WIDTH];
		#endif
#endif

#if(FG_BUFFER_3 == ON)
		#if(FG_BUFFER_COLOR_FORMAT == FMT_RGB16)
				extern  uint16_t FG_RGBBuff_3 [FG_BUFFER_HEIGHT*FG_BUFFER_WIDTH];
		#else
				extern  uint32_t FG_RGBABuff_3 [FG_BUFFER_HEIGHT*FG_BUFFER_WIDTH];
		#endif
#endif

#endif /* FG */


#endif /* FBUFFER_H */

/************************* BEGIN of DISCLAIMER   *****************************

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
  conditions set forth in the �Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (�Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer�s own risk.

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

****************************  END of DISCLAIMER *****************************/
