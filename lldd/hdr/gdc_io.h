
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : GDC 
/  Date of creation (y-m-d:time): 2013-06-14+02:00  :  15:35:28.447+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.12 $ 
/  Excel Sheet ver.             : vv1.9
/  Excel Sheet date             : 2013-Apr-11
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : GDC low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : GDC
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.12 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef GDC_IO_H
#define GDC_IO_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 230    /* Rule 6.4 [R] : nonstandard type for a bit field */
  #pragma ghs nowarning 1840   /* Rule 5.7 [A] : identifier reused from declaration of entity-kind "entity" */
#endif

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_GDC_IO_H_REVISION     "$Revision: 1.12 $"
#define LLDD_GDC_IO_H_TAG          "$Name: LLDD_1_7_GFX $"     

#ifndef HW_EMULATION_GDC
#define GDC1_REGADR_OFFSET    0x1000U
#else
#define GDC1_REGADR_OFFSET    0x08U
#endif

/**********************************************
*             extern defined varaibles
**********************************************/

 /* Following variables will be used to keep register data before writing in shadow registers:
  * they should be defined as global, otherwise the usage of macros in gdx_io.h by another 
  * applications will not work:*/

extern  volatile uint64_t u64GDCDCR_REG__Var[2];
extern  volatile uint64_t u64GDCCAVRA_REG__Var[2];
extern  volatile uint64_t u64GDCSCVRA_REG__Var[2];
extern  volatile uint64_t u64GDCSCVRB_REG__Var[2];
extern  volatile uint64_t u64GDCSCVRC_REG__Var[2];
extern  volatile uint64_t u64GDCSCVRD_REG__Var[2];
extern  volatile uint64_t u64APCCR_REG__Var[2];
extern  volatile uint64_t u64APCCWR_REG__Var[2];
extern  volatile uint64_t u64APCCSR_REG__Var[2];


extern  volatile uint32_t u32GDCLARA0_REG__Var[2];
extern  volatile uint32_t u32GDCLARA1_REG__Var[2];
extern  volatile uint32_t u32GDCWARA_REG__Var[2];
extern  volatile uint32_t u32GDCBGCR_REG__Var[2];
extern  volatile uint32_t u32GDCLARB0_REG__Var[2];
extern  volatile uint32_t u32GDCLARB1_REG__Var[2];
extern  volatile uint32_t u32GDCWARB_REG__Var[2];
extern  volatile uint32_t u32GDCLARC0_REG__Var[2];
extern  volatile uint32_t u32GDCLARC1_REG__Var[2];
extern  volatile uint32_t u32GDCLARD0_REG__Var[2];
extern  volatile uint32_t u32GDCLARD1_REG__Var[2];
extern  volatile uint32_t u32GDCMWRA_REG__Var[2];
extern  volatile uint32_t u32GDCMWRB_REG__Var[2];
extern  volatile uint32_t u32GDCMWRC_REG__Var[2];
extern  volatile uint32_t u32GDCMWRD_REG__Var[2];
extern  volatile uint32_t u32GDCMWRE_REG__Var[2];
extern  volatile uint32_t u32GDCLSRA_REG__Var[2];
extern  volatile uint32_t u32GDCLSRB_REG__Var[2];
extern  volatile uint32_t u32GDCLSRC_REG__Var[2];
extern  volatile uint32_t u32GDCLSRD_REG__Var[2];
extern  volatile uint32_t u32GDCLSRE_REG__Var[2];
extern  volatile uint32_t u32GDCLDRA_REG__Var[2];
extern  volatile uint32_t u32GDCLDRB_REG__Var[2];
extern  volatile uint32_t u32GDCLDRC_REG__Var[2];
extern  volatile uint32_t u32GDCLDRD_REG__Var[2];
extern  volatile uint32_t u32GDCLDRE_REG__Var[2];
extern  volatile uint32_t u32GDCWSRA_REG__Var[2];
extern  volatile uint32_t u32GDCWSRB_REG__Var[2];
extern  volatile uint32_t u32GDCWIMRA_REG__Var[2];
extern  volatile uint32_t u32GDCWIMRB_REG__Var[2];
extern  volatile uint32_t u32GDCCAVRB_REG__Var[2];
extern  volatile uint32_t u32GDCHSR_REG__Var[2];
extern  volatile uint32_t u32GDCVSR_REG__Var[2];

extern  volatile uint32_t u32GDCCBAR0_REG__Var[2];
extern  volatile uint32_t u32GDCCBAR1_REG__Var[2];
extern  volatile uint32_t u32GDCCBAR2_REG__Var[2];
extern  volatile uint32_t u32GDCPTCR_REG__Var[2];
extern  volatile uint32_t u32GDCGPCRA_REG__Var[2];
extern  volatile uint32_t u32GDCGPCRB_REG__Var[2];
extern  volatile uint32_t u32GDCGPCRC_REG__Var[2];
extern  volatile uint32_t u32GDCPSMR_REG__Var[2];
extern  volatile uint32_t u32GDCLARE0_REG__Var[2];
extern  volatile uint32_t u32GDCLARE1_REG__Var[2];
extern  volatile uint32_t u32GDCWARC_REG__Var[2];
extern  volatile uint32_t u32GDCWARD_REG__Var[2];
extern  volatile uint32_t u32GDCWARE_REG__Var[2];
extern  volatile uint32_t u32GDCWSRC_REG__Var[2];
extern  volatile uint32_t u32GDCWSRD_REG__Var[2];
extern  volatile uint32_t u32GDCWSRE_REG__Var[2];
extern  volatile uint32_t u32GDCWIMRC_REG__Var[2];
extern  volatile uint32_t u32GDCWIMRD_REG__Var[2];
extern  volatile uint32_t u32GDCWIMRE_REG__Var[2];
extern  volatile uint32_t u32GDCDSR_REG__Var[2];
extern  volatile uint32_t u32GDCDIMR_REG__Var[2];
extern  volatile uint32_t u32GDCPROTR_REG__Var[2];
extern  volatile uint32_t u32APCPROTR_REG__Var[2];

extern volatile uint32_t u32GDCPxGAR_REG__Var[2][12];
extern volatile uint32_t u32GDCPxGBR_REG__Var[2][12];

#ifdef HW_EMULATION_GDC

extern  volatile  uint64_t  GDCDCR_REG_EMUL[2];
extern  volatile  uint64_t  GDCCAVRA_REG_EMUL[2];
extern  volatile  uint64_t  GDCSCVRA_REG_EMUL[2];
extern  volatile  uint64_t  GDCSCVRB_REG_EMUL[2];
extern  volatile  uint64_t  GDCSCVRC_REG_EMUL[2];
extern  volatile  uint64_t  GDCSCVRD_REG_EMUL[2];
extern  volatile  uint64_t  APCCR_REG_EMUL[2];
extern  volatile  uint64_t  APCCWR_REG_EMUL[2];
extern  volatile  uint64_t  APCCSR_REG_EMUL[2];

extern  volatile  uint64_t  GDCLARA0_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARA1_REG_EMUL[2];
extern  volatile  uint64_t  GDCWARA_REG_EMUL[2];
extern  volatile  uint64_t  GDCBGCR_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARB0_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARB1_REG_EMUL[2];
extern  volatile  uint64_t  GDCWARB_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARC0_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARC1_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARD0_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARD1_REG_EMUL[2];
extern  volatile  uint64_t  GDCMWRA_REG_EMUL[2];
extern  volatile  uint64_t  GDCMWRB_REG_EMUL[2];
extern  volatile  uint64_t  GDCMWRC_REG_EMUL[2];
extern  volatile  uint64_t  GDCMWRD_REG_EMUL[2];
extern  volatile  uint64_t  GDCMWRE_REG_EMUL[2];
extern  volatile  uint64_t  GDCLSRA_REG_EMUL[2];
extern  volatile  uint64_t  GDCLSRB_REG_EMUL[2];
extern  volatile  uint64_t  GDCLSRC_REG_EMUL[2];
extern  volatile  uint64_t  GDCLSRD_REG_EMUL[2];
extern  volatile  uint64_t  GDCLSRE_REG_EMUL[2];
extern  volatile  uint64_t  GDCLDRA_REG_EMUL[2];
extern  volatile  uint64_t  GDCLDRB_REG_EMUL[2];
extern  volatile  uint64_t  GDCLDRC_REG_EMUL[2];
extern  volatile  uint64_t  GDCLDRD_REG_EMUL[2];
extern  volatile  uint64_t  GDCLDRE_REG_EMUL[2];
extern  volatile  uint64_t  GDCWSRA_REG_EMUL[2];
extern  volatile  uint64_t  GDCWSRB_REG_EMUL[2];
extern  volatile  uint64_t  GDCWIMRA_REG_EMUL[2];
extern  volatile  uint64_t  GDCWIMRB_REG_EMUL[2];
extern  volatile  uint64_t  GDCCAVRB_REG_EMUL[2];
extern  volatile  uint64_t  GDCHSR_REG_EMUL[2];
extern  volatile  uint64_t  GDCVSR_REG_EMUL[2];

extern  volatile  uint64_t  GDCCBAR0_REG_EMUL[2];
extern  volatile  uint64_t  GDCCBAR1_REG_EMUL[2];
extern  volatile  uint64_t  GDCCBAR2_REG_EMUL[2];
extern  volatile  uint64_t  GDCPTCR_REG_EMUL[2];
extern  volatile  uint64_t  GDCGPCRA_REG_EMUL[2];
extern  volatile  uint64_t  GDCGPCRB_REG_EMUL[2];
extern  volatile  uint64_t  GDCGPCRC_REG_EMUL[2];

extern  volatile  uint64_t  GDCP0GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP1GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP2GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP3GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP4GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP5GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP6GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP7GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP8GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP9GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP10GAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP11GAR_REG_EMUL[2];

extern  volatile  uint64_t  GDCP0GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP1GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP2GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP3GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP4GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP5GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP6GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP7GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP8GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP9GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP10GBR_REG_EMUL[2];
extern  volatile  uint64_t  GDCP11GBR_REG_EMUL[2];

extern  volatile  uint64_t  GDCPSMR_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARE0_REG_EMUL[2];
extern  volatile  uint64_t  GDCLARE1_REG_EMUL[2];
extern  volatile  uint64_t  GDCWARC_REG_EMUL[2];
extern  volatile  uint64_t  GDCWARD_REG_EMUL[2];
extern  volatile  uint64_t  GDCWARE_REG_EMUL[2];
extern  volatile  uint64_t  GDCWSRC_REG_EMUL[2];
extern  volatile  uint64_t  GDCWSRD_REG_EMUL[2];
extern  volatile  uint64_t  GDCWSRE_REG_EMUL[2];
extern  volatile  uint64_t  GDCWIMRC_REG_EMUL[2];
extern  volatile  uint64_t  GDCWIMRD_REG_EMUL[2];
extern  volatile  uint64_t  GDCWIMRE_REG_EMUL[2];
extern  volatile  uint64_t  GDCDSR_REG_EMUL[2];
extern  volatile  uint64_t  GDCDIMR_REG_EMUL[2];
extern  volatile  uint64_t  GDCPROTR_REG_EMUL[2];
extern  volatile  uint64_t  APCPROTR_REG_EMUL[2];

/* NOTE:  These registers are no shadow registes: */
extern  volatile  uint64_t  GDCINTR_REG_EMUL[2];
extern  volatile  uint64_t  GDCGBEAR_REG_EMUL[2];
extern  volatile  uint64_t  GDCGBECR_REG_EMUL[2];
extern  volatile  uint64_t  APCPVR_REG_EMUL[2];
extern  volatile  uint64_t  GDCCCLUTR_REG_EMUL[2][256];
extern  volatile  uint64_t  GDCCCLUTG_REG_EMUL[2][256];
extern  volatile  uint64_t  GDCCCLUTB_REG_EMUL[2][256];
extern  volatile  uint64_t  GDCGCAR_REG_EMUL[2];
#endif

/****************************************************************************   
*                                                                               
*       REGISTER: GDCDCR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02000                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC 
#define GDCDCR_REG__       0xC0C02000U
#else
#define GDCDCR_REG__ ((uint32_t) GDCDCR_REG_EMUL)
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   PHDISP	:1; 	 /* 0..0  bit(s) R/W */
  uint64_t   PHSYNC	:1; 	 /* 1..1  bit(s) R/W */
  uint64_t   PVSYNC	:1; 	 /* 2..2  bit(s) R/W */
  uint64_t   CSYNC	:1; 	 /* 3..3  bit(s) R/W */
  uint64_t   EXTSYNC	:1; 	 /* 4..4  bit(s) R/W */
  uint64_t   RSRVD5	:1; 	 /* 5..5  bit(s) R/W */
  uint64_t   RSRVD6	:1; 	 /* 6..6  bit(s) R/W */
  uint64_t   VORD	:1; 	 /* 7..7  bit(s) R/W */
  uint64_t   ARTH	:2; 	 /* 8..9  bit(s) R/W */
  uint64_t   ARTHCD	:1; 	 /* 10..10  bit(s) R/W */
  uint64_t   	:1; 	 /* 11..11  bit(s) R */
  uint64_t   PDC	:1; 	 /* 12..12  bit(s) R/W */
  uint64_t   IDC	:1; 	 /* 13..13  bit(s) R/W */
  uint64_t   ADBS	:1; 	 /* 14..14  bit(s) R/W */
  uint64_t   FBACT	:1; 	 /* 15..15  bit(s) R */
  uint64_t   HDISP	:1; 	 /* 16..16  bit(s) R */
  uint64_t   HSYNC	:1; 	 /* 17..17  bit(s) R */
  uint64_t   VSYNC	:1; 	 /* 18..18  bit(s) R */
  uint64_t   GBER	:1; 	 /* 19..19  bit(s) R/W1C */
  uint64_t   A16	:1; 	 /* 20..20  bit(s) R/W */
  uint64_t   B16	:1; 	 /* 21..21  bit(s) R/W */
  uint64_t   C16	:1; 	 /* 22..22  bit(s) R/W */
  uint64_t   D16	:1; 	 /* 23..23  bit(s) R/W */
  uint64_t   AEN	:1; 	 /* 24..24  bit(s) R/W */
  uint64_t   WAEN	:1; 	 /* 25..25  bit(s) R/W */
  uint64_t   BEN	:1; 	 /* 26..26  bit(s) R/W */
  uint64_t   WBEN	:1; 	 /* 27..27  bit(s) R/W */
  uint64_t   CEN	:1; 	 /* 28..28  bit(s) R/W */
  uint64_t   WCEN	:1; 	 /* 29..29  bit(s) R/W */
  uint64_t   DEN	:1; 	 /* 30..30  bit(s) R/W */
  uint64_t   WDEN	:1; 	 /* 31..31  bit(s) R/W */
  uint64_t   EEN	:1; 	 /* 32..32  bit(s) R/W */
  uint64_t   WEEN	:1; 	 /* 33..33  bit(s) R/W */
  uint64_t   	:2; 	 /* 34..35  bit(s) R */
  uint64_t   E16	:1; 	 /* 36..36  bit(s) R/W */
  uint64_t   	:3; 	 /* 37..39  bit(s) R */
  uint64_t   CCEN	:1; 	 /* 40..40  bit(s) R/W */
  uint64_t   SCCEN	:1; 	 /* 41..41  bit(s) R/W */
  uint64_t   SCCM	:1; 	 /* 42..42  bit(s) R/W */
  uint64_t   	:1; 	 /* 43..43  bit(s) R */
  uint64_t   DITHEN	:2; 	 /* 44..45  bit(s) R/W */
  uint64_t   	:6; 	 /* 46..51  bit(s) R */
  uint64_t   ARGBEN	:1; 	 /* 52..52  bit(s) R/W */
  uint64_t   LAD	:1; 	 /* 53..53  bit(s) R/W */
  uint64_t   UPDREG	:2; 	 /* 54..55  bit(s) R/W */
  uint64_t   GAPEN	:1; 	 /* 56..56  bit(s) R/W */
  uint64_t   GAPCOL	:1; 	 /* 57..57  bit(s) R/W1C */
  uint64_t   GAPACC	:1; 	 /* 58..58  bit(s) R */
  uint64_t   RSRVD59    :1;      /* 59..59  bit(s) R/W */
  uint64_t   	:1; 	 /* 60..60  bit(s) R */
  uint64_t   PNLIFON	:1; 	 /* 61..61  bit(s) R */
  uint64_t   DISPIFON	:1; 	 /* 62..62  bit(s) R */ 
  uint64_t   GDCON	:1; 	 /* 63..63  bit(s) R/W */                    
} GDCDCR_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} GDCDCR_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} GDCDCR_word_view_st;
            
/* LONGWORD View */
typedef uint64_t u64GDCDCR_longword_view;
             


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCDCR(ctrlr)     ((volatile GDCDCR_bit_view_st *)\
(GDCDCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16GDCDCR(ctrlr)     ((volatile GDCDCR_halfword_view_st *)\
(GDCDCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32GDCDCR(ctrlr)   ((volatile GDCDCR_word_view_st *) \
(GDCDCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to LONG_WORD  */
#define pu64GDCDCR(ctrlr)    ((volatile u64GDCDCR_longword_view *)\
(GDCDCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

#else
/* Pointer to BIT-struct of shadow register */
#define pst_bitGDCDCR_Direct(ctrlr)     ((volatile GDCDCR_bit_view_st *)\
(GDCDCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to BIT-struct */
#define pst_bitGDCDCR(ctrlr)     ((volatile GDCDCR_bit_view_st *) &u64GDCDCR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCDCR(ctrlr)     ((volatile GDCDCR_halfword_view_st *) &u64GDCDCR_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32GDCDCR(ctrlr)   ((volatile GDCDCR_word_view_st *) &u64GDCDCR_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64GDCDCR(ctrlr)    ((volatile u64GDCDCR_longword_view *) &u64GDCDCR_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD to shadow register */
#define pu64GDCDCR_Direct(ctrlr)    ((volatile u64GDCDCR_longword_view *)\
(GDCDCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

#endif


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCDCR_PHDISP(ctrlr) (pst_bitGDCDCR(ctrlr) -> PHDISP)
#define vSetGDCDCR_PHDISP(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> PHDISP=(ParValue))
#define biGetGDCDCR_PHSYNC(ctrlr) (pst_bitGDCDCR(ctrlr) -> PHSYNC)
#define vSetGDCDCR_PHSYNC(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> PHSYNC=(ParValue))
#define biGetGDCDCR_PVSYNC(ctrlr) (pst_bitGDCDCR(ctrlr) -> PVSYNC)
#define vSetGDCDCR_PVSYNC(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> PVSYNC=(ParValue))
#define biGetGDCDCR_CSYNC(ctrlr) (pst_bitGDCDCR(ctrlr) -> CSYNC)
#define vSetGDCDCR_CSYNC(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> CSYNC=(ParValue))
#define biGetGDCDCR_EXTSYNC(ctrlr) (pst_bitGDCDCR(ctrlr) -> EXTSYNC)
#define vSetGDCDCR_EXTSYNC(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> EXTSYNC=(ParValue))
#define biGetGDCDCR_RSRVD5(ctrlr) (pst_bitGDCDCR(ctrlr) -> RSRVD5)
#define vSetGDCDCR_RSRVD5(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> RSRVD5=(ParValue))
#define biGetGDCDCR_RSRVD6(ctrlr) (pst_bitGDCDCR(ctrlr) -> RSRVD6)
#define vSetGDCDCR_RSRVD6(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> RSRVD6=(ParValue))
#define biGetGDCDCR_VORD(ctrlr) (pst_bitGDCDCR(ctrlr) -> VORD)
#define vSetGDCDCR_VORD(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> VORD=(ParValue))
#define biGetGDCDCR_ARTH(ctrlr) (pst_bitGDCDCR(ctrlr) -> ARTH)
#define vSetGDCDCR_ARTH(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> ARTH=(ParValue))
#define biGetGDCDCR_ARTHCD(ctrlr) (pst_bitGDCDCR(ctrlr) -> ARTHCD)
#define vSetGDCDCR_ARTHCD(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> ARTHCD=(ParValue))
#define biGetGDCDCR_PDC(ctrlr) (pst_bitGDCDCR(ctrlr) -> PDC)
#define vSetGDCDCR_PDC(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> PDC=(ParValue))
#define biGetGDCDCR_IDC(ctrlr) (pst_bitGDCDCR(ctrlr) -> IDC)
#define vSetGDCDCR_IDC(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> IDC=(ParValue))
#define biGetGDCDCR_ADBS(ctrlr) (pst_bitGDCDCR(ctrlr) -> ADBS)
#define vSetGDCDCR_ADBS(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> ADBS=(ParValue))            

/**********************************************************************
 ** "Read Only" signals should be read directly fom shadow register  **
 **********************************************************************/
#define biGetGDCDCR_FBACT(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> FBACT)
#define biGetGDCDCR_HDISP(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> HDISP)
#define biGetGDCDCR_HSYNC(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> HSYNC)
#define biGetGDCDCR_VSYNC(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> VSYNC)
/**********************************************************************/

#define biGetGDCDCR_GBER(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> GBER)
#define vClrGDCDCR_GBER(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> GBER = (1))

#define biGetGDCDCR_A16(ctrlr) (pst_bitGDCDCR(ctrlr) -> A16)
#define vSetGDCDCR_A16(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> A16=(ParValue))
#define biGetGDCDCR_B16(ctrlr) (pst_bitGDCDCR(ctrlr) -> B16)
#define vSetGDCDCR_B16(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> B16=(ParValue))
#define biGetGDCDCR_C16(ctrlr) (pst_bitGDCDCR(ctrlr) -> C16)
#define vSetGDCDCR_C16(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> C16=(ParValue))
#define biGetGDCDCR_D16(ctrlr) (pst_bitGDCDCR(ctrlr) -> D16)
#define vSetGDCDCR_D16(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> D16=(ParValue))
#define biGetGDCDCR_AEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> AEN)
#define vSetGDCDCR_AEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> AEN=(ParValue))
#define biGetGDCDCR_WAEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> WAEN)
#define vSetGDCDCR_WAEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> WAEN=(ParValue))
#define biGetGDCDCR_BEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> BEN)
#define vSetGDCDCR_BEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> BEN=(ParValue))
#define biGetGDCDCR_WBEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> WBEN)
#define vSetGDCDCR_WBEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> WBEN=(ParValue))
#define biGetGDCDCR_CEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> CEN)
#define vSetGDCDCR_CEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> CEN=(ParValue))
#define biGetGDCDCR_WCEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> WCEN)
#define vSetGDCDCR_WCEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> WCEN=(ParValue))
#define biGetGDCDCR_DEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> DEN)
#define vSetGDCDCR_DEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> DEN=(ParValue))
#define biGetGDCDCR_WDEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> WDEN)
#define vSetGDCDCR_WDEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> WDEN=(ParValue))
#define biGetGDCDCR_EEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> EEN)
#define vSetGDCDCR_EEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> EEN=(ParValue))
#define biGetGDCDCR_WEEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> WEEN)
#define vSetGDCDCR_WEEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> WEEN=(ParValue))
#define biGetGDCDCR_E16(ctrlr) (pst_bitGDCDCR(ctrlr) -> E16)
#define vSetGDCDCR_E16(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> E16=(ParValue))
#define biGetGDCDCR_CCEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> CCEN)
#define vSetGDCDCR_CCEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> CCEN=(ParValue))
#define biGetGDCDCR_SCCEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> SCCEN)
#define vSetGDCDCR_SCCEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> SCCEN=(ParValue))
#define biGetGDCDCR_SCCM(ctrlr) (pst_bitGDCDCR(ctrlr) -> SCCM)
#define vSetGDCDCR_SCCM(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> SCCM=(ParValue))
#define biGetGDCDCR_DITHEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> DITHEN)
#define vSetGDCDCR_DITHEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> DITHEN=(ParValue))
#define biGetGDCDCR_ARGBEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> ARGBEN)
#define vSetGDCDCR_ARGBEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> ARGBEN=(ParValue))
#define biGetGDCDCR_LAD(ctrlr) (pst_bitGDCDCR(ctrlr) -> LAD)
#define vSetGDCDCR_LAD(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> LAD=(ParValue))

/**********************************************************************
 ** NOTE:
 *      "UPDREG" has an immediate influenc to HW, so 
 *      a) to get these bits, it should be read from HW shadow register
 *      b) to set these bits, it should NOT be set direct to shadow register, because
 *         the exisiting data in shadow register can be overwritten before VSNC was raised
 **********************************************************************/
#define biGetGDCDCR_UPDREG_Direct(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> UPDREG)
#define vSetGDCDCR_UPDREG(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> UPDREG=(ParValue))
/***********************************************************************/
#define biGetGDCDCR_GAPEN(ctrlr) (pst_bitGDCDCR(ctrlr) -> GAPEN)
#define vSetGDCDCR_GAPEN(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> GAPEN=(ParValue))

#define biGetGDCDCR_GAPCOL(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> GAPCOL)
#define vClrGDCDCR_GAPCOL(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> GAPCOL = (1))

/* "Read Only" signals will be read from shadow register: */
#define biGetGDCDCR_GAPACC(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> GAPACC)

/*"Read Only" signals will be read from shadow register: */
#define biGetGDCDCR_PNLIFON(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> PNLIFON)
#define biGetGDCDCR_DISPIFON(ctrlr) (pst_bitGDCDCR_Direct(ctrlr) -> DISPIFON)

#define biGetGDCDCR_GDCON(ctrlr) (pst_bitGDCDCR(ctrlr) -> GDCON)
#define vSetGDCDCR_GDCON(ctrlr,ParValue)  (pst_bitGDCDCR(ctrlr) -> GDCON=(ParValue))

/* Half-word struct access LL */ 
#define vSetGDCDCRLL(ctrlr,ParValue) (pst_u16GDCDCR(ctrlr) -> u16LL = (ParValue))
#define u16GetGDCDCRLL(ctrlr) (pst_u16GDCDCR(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetGDCDCRLH(ctrlr,ParValue) (pst_u16GDCDCR(ctrlr) -> u16LH = (ParValue))
#define u16GetGDCDCRLH(ctrlr) (pst_u16GDCDCR(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetGDCDCRHL(ctrlr,ParValue) (pst_u16GDCDCR(ctrlr) -> u16HL = (ParValue))
#define u16GetGDCDCRHL(ctrlr) (pst_u16GDCDCR(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetGDCDCRHH(ctrlr,ParValue) (pst_u16GDCDCR(ctrlr) -> u16HH = (ParValue))
#define u16GetGDCDCRHH(ctrlr) (pst_u16GDCDCR(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetGDCDCRL(ctrlr,ParValue) (pst_u32GDCDCR(ctrlr) -> u32L= (ParValue))
#define u32GetGDCDCRL(ctrlr) (pst_u32GDCDCR(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetGDCDCRH(ctrlr,ParValue) (pst_u32GDCDCR(ctrlr) -> u32H = (ParValue))
#define u32GetGDCDCRH(ctrlr) (pst_u32GDCDCR(ctrlr) -> u32H)
            
/* Long  Word access */ 
#define vSetGDCDCR(ctrlr,ParValue)  (*pu64GDCDCR(ctrlr) = (ParValue))
#define u64GetGDCDCR(ctrlr)  (*pu64GDCDCR(ctrlr) )


/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARA0                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARA0_REG__       0xC0C02010U
#else
#define GDCLARA0_REG__ ((uint32_t) GDCLARA0_REG_EMUL)
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARA0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARA0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARA0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARA0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARA0(ctrlr)     ((volatile GDCLARA0_bit_view_st *)\
(GDCLARA0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARA0(ctrlr)     ((volatile GDCLARA0_byte_view_st *)\
(GDCLARA0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARA0(ctrlr)     ((volatile GDCLARA0_halfword_view_st *)\
(GDCLARA0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARA0(ctrlr)     ((volatile u32GDCLARA0_word_view *)\
(GDCLARA0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARA0(ctrlr)     ((volatile GDCLARA0_bit_view_st *) &u32GDCLARA0_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARA0(ctrlr)     ((volatile GDCLARA0_byte_view_st *) &u32GDCLARA0_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARA0(ctrlr)     ((volatile GDCLARA0_halfword_view_st *) &u32GDCLARA0_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARA0(ctrlr)     ((volatile u32GDCLARA0_word_view *) &u32GDCLARA0_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARA0_SSCROLL(ctrlr) (pst_bitGDCLARA0(ctrlr) -> SSCROLL)
#define vSetGDCLARA0_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARA0(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARA0_SAR(ctrlr) (pst_bitGDCLARA0(ctrlr) -> SAR)
#define vSetGDCLARA0_SAR(ctrlr,ParValue)  (pst_bitGDCLARA0(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARA0LL(ctrlr,ParValue) (pst_u8GDCLARA0(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARA0LL(ctrlr) (pst_u8GDCLARA0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARA0LH(ctrlr,ParValue) (pst_u8GDCLARA0(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARA0LH(ctrlr) (pst_u8GDCLARA0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARA0HL(ctrlr,ParValue) (pst_u8GDCLARA0(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARA0HL(ctrlr) (pst_u8GDCLARA0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARA0HH(ctrlr,ParValue) (pst_u8GDCLARA0(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARA0HH(ctrlr) (pst_u8GDCLARA0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARA0L(ctrlr,ParValue) (pst_u16GDCLARA0(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARA0L(ctrlr) (pst_u16GDCLARA0(ctrlr) -> u16L)
#define vSetGDCLARA0H(ctrlr,ParValue) (pst_u16GDCLARA0(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARA0H(ctrlr) (pst_u16GDCLARA0(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARA0(ctrlr,ParValue)  (*pu32GDCLARA0(ctrlr) = (ParValue))
#define u32GetGDCLARA0(ctrlr)  (*pu32GDCLARA0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARA1                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARA1_REG__       0xC0C02018U
#else
#define GDCLARA1_REG__ ((uint32_t) GDCLARA1_REG_EMUL)
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARA1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARA1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARA1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARA1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARA1(ctrlr)     ((volatile GDCLARA1_bit_view_st *)\
(GDCLARA1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARA1(ctrlr)     ((volatile GDCLARA1_byte_view_st *)\
(GDCLARA1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARA1(ctrlr)     ((volatile GDCLARA1_halfword_view_st *)\
(GDCLARA1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARA1(ctrlr)     ((volatile u32GDCLARA1_word_view *)\
(GDCLARA1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARA1(ctrlr)     ((volatile GDCLARA1_bit_view_st *) &u32GDCLARA1_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARA1(ctrlr)     ((volatile GDCLARA1_byte_view_st *) &u32GDCLARA1_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARA1(ctrlr)     ((volatile GDCLARA1_halfword_view_st *) &u32GDCLARA1_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARA1(ctrlr)     ((volatile u32GDCLARA1_word_view *) &u32GDCLARA1_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARA1_SSCROLL(ctrlr) (pst_bitGDCLARA1(ctrlr) -> SSCROLL)
#define vSetGDCLARA1_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARA1(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARA1_SAR(ctrlr) (pst_bitGDCLARA1(ctrlr) -> SAR)
#define vSetGDCLARA1_SAR(ctrlr,ParValue)  (pst_bitGDCLARA1(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARA1LL(ctrlr,ParValue) (pst_u8GDCLARA1(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARA1LL(ctrlr) (pst_u8GDCLARA1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARA1LH(ctrlr,ParValue) (pst_u8GDCLARA1(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARA1LH(ctrlr) (pst_u8GDCLARA1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARA1HL(ctrlr,ParValue) (pst_u8GDCLARA1(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARA1HL(ctrlr) (pst_u8GDCLARA1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARA1HH(ctrlr,ParValue) (pst_u8GDCLARA1(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARA1HH(ctrlr) (pst_u8GDCLARA1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARA1L(ctrlr,ParValue) (pst_u16GDCLARA1(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARA1L(ctrlr) (pst_u16GDCLARA1(ctrlr) -> u16L)
#define vSetGDCLARA1H(ctrlr,ParValue) (pst_u16GDCLARA1(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARA1H(ctrlr) (pst_u16GDCLARA1(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARA1(ctrlr,ParValue)  (*pu32GDCLARA1(ctrlr) = (ParValue))
#define u32GetGDCLARA1(ctrlr)  (*pu32GDCLARA1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWARA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWARA_REG__       0xC0C02020U
#else
#define GDCWARA_REG__ ((uint32_t) GDCWARA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   WAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCWARA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWARA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWARA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWARA_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWARA(ctrlr)     ((volatile GDCWARA_bit_view_st *)\
(GDCWARA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWARA(ctrlr)     ((volatile GDCWARA_byte_view_st *)\
(GDCWARA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARA(ctrlr)     ((volatile GDCWARA_halfword_view_st *)\
(GDCWARA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWARA(ctrlr)     ((volatile u32GDCWARA_word_view *)\
(GDCWARA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWARA(ctrlr)     ((volatile GDCWARA_bit_view_st *) &u32GDCWARA_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWARA(ctrlr)     ((volatile GDCWARA_byte_view_st *) &u32GDCWARA_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARA(ctrlr)     ((volatile GDCWARA_halfword_view_st *) &u32GDCWARA_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWARA(ctrlr)     ((volatile u32GDCWARA_word_view *) &u32GDCWARA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWARA_WAR(ctrlr) (pst_bitGDCWARA(ctrlr) -> WAR)
#define vSetGDCWARA_WAR(ctrlr,ParValue)  (pst_bitGDCWARA(ctrlr) -> WAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWARALL(ctrlr,ParValue) (pst_u8GDCWARA(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWARALL(ctrlr) (pst_u8GDCWARA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWARALH(ctrlr,ParValue) (pst_u8GDCWARA(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWARALH(ctrlr) (pst_u8GDCWARA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWARAHL(ctrlr,ParValue) (pst_u8GDCWARA(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWARAHL(ctrlr) (pst_u8GDCWARA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWARAHH(ctrlr,ParValue) (pst_u8GDCWARA(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWARAHH(ctrlr) (pst_u8GDCWARA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWARAL(ctrlr,ParValue) (pst_u16GDCWARA(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWARAL(ctrlr) (pst_u16GDCWARA(ctrlr) -> u16L)
#define vSetGDCWARAH(ctrlr,ParValue) (pst_u16GDCWARA(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWARAH(ctrlr) (pst_u16GDCWARA(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWARA(ctrlr,ParValue)  (*pu32GDCWARA(ctrlr) = (ParValue))
#define u32GetGDCWARA(ctrlr)  (*pu32GDCWARA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCBGCR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02028                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCBGCR_REG__       0xC0C02028U
#else
#define GDCBGCR_REG__ ((uint32_t) GDCBGCR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   BGBLUE	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   BGGREEN	:8; 	 /* 16..23  bit(s) R/W */
  uint32_t   BGRED	:8; 	 /* 24..31  bit(s) R/W */                    
} GDCBGCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCBGCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCBGCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCBGCR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCBGCR(ctrlr)     ((volatile GDCBGCR_bit_view_st *)\
(GDCBGCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCBGCR(ctrlr)     ((volatile GDCBGCR_byte_view_st *)\
(GDCBGCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCBGCR(ctrlr)     ((volatile GDCBGCR_halfword_view_st *)\
(GDCBGCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCBGCR(ctrlr)     ((volatile u32GDCBGCR_word_view *)\
(GDCBGCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCBGCR(ctrlr)     ((volatile GDCBGCR_bit_view_st *) &u32GDCBGCR_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCBGCR(ctrlr)     ((volatile GDCBGCR_byte_view_st *) &u32GDCBGCR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCBGCR(ctrlr)     ((volatile GDCBGCR_halfword_view_st *) &u32GDCBGCR_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCBGCR(ctrlr)     ((volatile u32GDCBGCR_word_view *) &u32GDCBGCR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCBGCR_BGBLUE(ctrlr) (pst_bitGDCBGCR(ctrlr) -> BGBLUE)
#define vSetGDCBGCR_BGBLUE(ctrlr,ParValue)  (pst_bitGDCBGCR(ctrlr) -> BGBLUE=(ParValue))
#define biGetGDCBGCR_BGGREEN(ctrlr) (pst_bitGDCBGCR(ctrlr) -> BGGREEN)
#define vSetGDCBGCR_BGGREEN(ctrlr,ParValue)  (pst_bitGDCBGCR(ctrlr) -> BGGREEN=(ParValue))
#define biGetGDCBGCR_BGRED(ctrlr) (pst_bitGDCBGCR(ctrlr) -> BGRED)
#define vSetGDCBGCR_BGRED(ctrlr,ParValue)  (pst_bitGDCBGCR(ctrlr) -> BGRED=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCBGCRLL(ctrlr,ParValue) (pst_u8GDCBGCR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCBGCRLL(ctrlr) (pst_u8GDCBGCR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCBGCRLH(ctrlr,ParValue) (pst_u8GDCBGCR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCBGCRLH(ctrlr) (pst_u8GDCBGCR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCBGCRHL(ctrlr,ParValue) (pst_u8GDCBGCR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCBGCRHL(ctrlr) (pst_u8GDCBGCR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCBGCRHH(ctrlr,ParValue) (pst_u8GDCBGCR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCBGCRHH(ctrlr) (pst_u8GDCBGCR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCBGCRL(ctrlr,ParValue) (pst_u16GDCBGCR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCBGCRL(ctrlr) (pst_u16GDCBGCR(ctrlr) -> u16L)
#define vSetGDCBGCRH(ctrlr,ParValue) (pst_u16GDCBGCR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCBGCRH(ctrlr) (pst_u16GDCBGCR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCBGCR(ctrlr,ParValue)  (*pu32GDCBGCR(ctrlr) = (ParValue))
#define u32GetGDCBGCR(ctrlr)  (*pu32GDCBGCR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARB0                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02030                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARB0_REG__       0xC0C02030U
#else
#define GDCLARB0_REG__ ((uint32_t) GDCLARB0_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARB0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARB0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARB0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARB0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARB0(ctrlr)     ((volatile GDCLARB0_bit_view_st *)\
(GDCLARB0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARB0(ctrlr)     ((volatile GDCLARB0_byte_view_st *)\
(GDCLARB0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARB0(ctrlr)     ((volatile GDCLARB0_halfword_view_st *)\
(GDCLARB0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARB0(ctrlr)     ((volatile u32GDCLARB0_word_view *)\
(GDCLARB0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARB0(ctrlr)     ((volatile GDCLARB0_bit_view_st *) &u32GDCLARB0_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARB0(ctrlr)     ((volatile GDCLARB0_byte_view_st *) &u32GDCLARB0_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARB0(ctrlr)     ((volatile GDCLARB0_halfword_view_st *) &u32GDCLARB0_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARB0(ctrlr)     ((volatile u32GDCLARB0_word_view *) &u32GDCLARB0_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARB0_SSCROLL(ctrlr) (pst_bitGDCLARB0(ctrlr) -> SSCROLL)
#define vSetGDCLARB0_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARB0(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARB0_SAR(ctrlr) (pst_bitGDCLARB0(ctrlr) -> SAR)
#define vSetGDCLARB0_SAR(ctrlr,ParValue)  (pst_bitGDCLARB0(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARB0LL(ctrlr,ParValue) (pst_u8GDCLARB0(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARB0LL(ctrlr) (pst_u8GDCLARB0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARB0LH(ctrlr,ParValue) (pst_u8GDCLARB0(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARB0LH(ctrlr) (pst_u8GDCLARB0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARB0HL(ctrlr,ParValue) (pst_u8GDCLARB0(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARB0HL(ctrlr) (pst_u8GDCLARB0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARB0HH(ctrlr,ParValue) (pst_u8GDCLARB0(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARB0HH(ctrlr) (pst_u8GDCLARB0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARB0L(ctrlr,ParValue) (pst_u16GDCLARB0(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARB0L(ctrlr) (pst_u16GDCLARB0(ctrlr) -> u16L)
#define vSetGDCLARB0H(ctrlr,ParValue) (pst_u16GDCLARB0(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARB0H(ctrlr) (pst_u16GDCLARB0(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARB0(ctrlr,ParValue)  (*pu32GDCLARB0(ctrlr) = (ParValue))
#define u32GetGDCLARB0(ctrlr)  (*pu32GDCLARB0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARB1                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02038                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARB1_REG__       0xC0C02038U
#else
#define GDCLARB1_REG__ ((uint32_t) GDCLARB1_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARB1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARB1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARB1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARB1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARB1(ctrlr)     ((volatile GDCLARB1_bit_view_st *)\
(GDCLARB1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARB1(ctrlr)     ((volatile GDCLARB1_byte_view_st *)\
(GDCLARB1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARB1(ctrlr)     ((volatile GDCLARB1_halfword_view_st *)\
(GDCLARB1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARB1(ctrlr)     ((volatile u32GDCLARB1_word_view *)\
(GDCLARB1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARB1(ctrlr)     ((volatile GDCLARB1_bit_view_st *) &u32GDCLARB1_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARB1(ctrlr)     ((volatile GDCLARB1_byte_view_st *) &u32GDCLARB1_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARB1(ctrlr)     ((volatile GDCLARB1_halfword_view_st *) &u32GDCLARB1_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARB1(ctrlr)     ((volatile u32GDCLARB1_word_view *) &u32GDCLARB1_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARB1_SSCROLL(ctrlr) (pst_bitGDCLARB1(ctrlr) -> SSCROLL)
#define vSetGDCLARB1_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARB1(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARB1_SAR(ctrlr) (pst_bitGDCLARB1(ctrlr) -> SAR)
#define vSetGDCLARB1_SAR(ctrlr,ParValue)  (pst_bitGDCLARB1(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARB1LL(ctrlr,ParValue) (pst_u8GDCLARB1(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARB1LL(ctrlr) (pst_u8GDCLARB1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARB1LH(ctrlr,ParValue) (pst_u8GDCLARB1(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARB1LH(ctrlr) (pst_u8GDCLARB1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARB1HL(ctrlr,ParValue) (pst_u8GDCLARB1(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARB1HL(ctrlr) (pst_u8GDCLARB1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARB1HH(ctrlr,ParValue) (pst_u8GDCLARB1(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARB1HH(ctrlr) (pst_u8GDCLARB1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARB1L(ctrlr,ParValue) (pst_u16GDCLARB1(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARB1L(ctrlr) (pst_u16GDCLARB1(ctrlr) -> u16L)
#define vSetGDCLARB1H(ctrlr,ParValue) (pst_u16GDCLARB1(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARB1H(ctrlr) (pst_u16GDCLARB1(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARB1(ctrlr,ParValue)  (*pu32GDCLARB1(ctrlr) = (ParValue))
#define u32GetGDCLARB1(ctrlr)  (*pu32GDCLARB1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWARB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02040                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWARB_REG__       0xC0C02040U
#else
#define GDCWARB_REG__ ((uint32_t) GDCWARB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   WAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCWARB_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWARB_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWARB_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWARB_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWARB(ctrlr)     ((volatile GDCWARB_bit_view_st *)\
(GDCWARB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWARB(ctrlr)     ((volatile GDCWARB_byte_view_st *)\
(GDCWARB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARB(ctrlr)     ((volatile GDCWARB_halfword_view_st *)\
(GDCWARB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWARB(ctrlr)     ((volatile u32GDCWARB_word_view *)\
(GDCWARB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWARB(ctrlr)     ((volatile GDCWARB_bit_view_st *) &u32GDCWARB_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWARB(ctrlr)     ((volatile GDCWARB_byte_view_st *) &u32GDCWARB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARB(ctrlr)     ((volatile GDCWARB_halfword_view_st *) &u32GDCWARB_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWARB(ctrlr)     ((volatile u32GDCWARB_word_view *) &u32GDCWARB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWARB_WAR(ctrlr) (pst_bitGDCWARB(ctrlr) -> WAR)
#define vSetGDCWARB_WAR(ctrlr,ParValue)  (pst_bitGDCWARB(ctrlr) -> WAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWARBLL(ctrlr,ParValue) (pst_u8GDCWARB(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWARBLL(ctrlr) (pst_u8GDCWARB(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWARBLH(ctrlr,ParValue) (pst_u8GDCWARB(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWARBLH(ctrlr) (pst_u8GDCWARB(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWARBHL(ctrlr,ParValue) (pst_u8GDCWARB(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWARBHL(ctrlr) (pst_u8GDCWARB(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWARBHH(ctrlr,ParValue) (pst_u8GDCWARB(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWARBHH(ctrlr) (pst_u8GDCWARB(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWARBL(ctrlr,ParValue) (pst_u16GDCWARB(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWARBL(ctrlr) (pst_u16GDCWARB(ctrlr) -> u16L)
#define vSetGDCWARBH(ctrlr,ParValue) (pst_u16GDCWARB(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWARBH(ctrlr) (pst_u16GDCWARB(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWARB(ctrlr,ParValue)  (*pu32GDCWARB(ctrlr) = (ParValue))
#define u32GetGDCWARB(ctrlr)  (*pu32GDCWARB(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARC0                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02048                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARC0_REG__       0xC0C02048U
#else
#define GDCLARC0_REG__ ((uint32_t) GDCLARC0_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARC0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARC0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARC0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARC0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARC0(ctrlr)     ((volatile GDCLARC0_bit_view_st *)\
(GDCLARC0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARC0(ctrlr)     ((volatile GDCLARC0_byte_view_st *)\
(GDCLARC0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARC0(ctrlr)     ((volatile GDCLARC0_halfword_view_st *)\
(GDCLARC0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARC0(ctrlr)     ((volatile u32GDCLARC0_word_view *)\
(GDCLARC0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARC0(ctrlr)     ((volatile GDCLARC0_bit_view_st *) &u32GDCLARC0_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARC0(ctrlr)     ((volatile GDCLARC0_byte_view_st *)\ &u32GDCLARC0_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARC0(ctrlr)     ((volatile GDCLARC0_halfword_view_st *) &u32GDCLARC0_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARC0(ctrlr)     ((volatile u32GDCLARC0_word_view *) &u32GDCLARC0_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARC0_SSCROLL(ctrlr) (pst_bitGDCLARC0(ctrlr) -> SSCROLL)
#define vSetGDCLARC0_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARC0(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARC0_SAR(ctrlr) (pst_bitGDCLARC0(ctrlr) -> SAR)
#define vSetGDCLARC0_SAR(ctrlr,ParValue)  (pst_bitGDCLARC0(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARC0LL(ctrlr,ParValue) (pst_u8GDCLARC0(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARC0LL(ctrlr) (pst_u8GDCLARC0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARC0LH(ctrlr,ParValue) (pst_u8GDCLARC0(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARC0LH(ctrlr) (pst_u8GDCLARC0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARC0HL(ctrlr,ParValue) (pst_u8GDCLARC0(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARC0HL(ctrlr) (pst_u8GDCLARC0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARC0HH(ctrlr,ParValue) (pst_u8GDCLARC0(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARC0HH(ctrlr) (pst_u8GDCLARC0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARC0L(ctrlr,ParValue) (pst_u16GDCLARC0(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARC0L(ctrlr) (pst_u16GDCLARC0(ctrlr) -> u16L)
#define vSetGDCLARC0H(ctrlr,ParValue) (pst_u16GDCLARC0(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARC0H(ctrlr) (pst_u16GDCLARC0(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARC0(ctrlr,ParValue)  (*pu32GDCLARC0(ctrlr) = (ParValue))
#define u32GetGDCLARC0(ctrlr)  (*pu32GDCLARC0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARC1                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02050                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARC1_REG__       0xC0C02050U
#else
#define GDCLARC1_REG__ ((uint32_t) GDCLARC1_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARC1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARC1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARC1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARC1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARC1(ctrlr)     ((volatile GDCLARC1_bit_view_st *)\
(GDCLARC1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARC1(ctrlr)     ((volatile GDCLARC1_byte_view_st *)\
(GDCLARC1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARC1(ctrlr)     ((volatile GDCLARC1_halfword_view_st *)\
(GDCLARC1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARC1(ctrlr)     ((volatile u32GDCLARC1_word_view *)\
(GDCLARC1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARC1(ctrlr)     ((volatile GDCLARC1_bit_view_st *) &u32GDCLARC1_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARC1(ctrlr)     ((volatile GDCLARC1_byte_view_st *) &u32GDCLARC1_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARC1(ctrlr)     ((volatile GDCLARC1_halfword_view_st *) &u32GDCLARC1_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARC1(ctrlr)     ((volatile u32GDCLARC1_word_view *) &u32GDCLARC1_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARC1_SSCROLL(ctrlr) (pst_bitGDCLARC1(ctrlr) -> SSCROLL)
#define vSetGDCLARC1_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARC1(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARC1_SAR(ctrlr) (pst_bitGDCLARC1(ctrlr) -> SAR)
#define vSetGDCLARC1_SAR(ctrlr,ParValue)  (pst_bitGDCLARC1(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARC1LL(ctrlr,ParValue) (pst_u8GDCLARC1(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARC1LL(ctrlr) (pst_u8GDCLARC1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARC1LH(ctrlr,ParValue) (pst_u8GDCLARC1(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARC1LH(ctrlr) (pst_u8GDCLARC1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARC1HL(ctrlr,ParValue) (pst_u8GDCLARC1(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARC1HL(ctrlr) (pst_u8GDCLARC1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARC1HH(ctrlr,ParValue) (pst_u8GDCLARC1(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARC1HH(ctrlr) (pst_u8GDCLARC1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARC1L(ctrlr,ParValue) (pst_u16GDCLARC1(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARC1L(ctrlr) (pst_u16GDCLARC1(ctrlr) -> u16L)
#define vSetGDCLARC1H(ctrlr,ParValue) (pst_u16GDCLARC1(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARC1H(ctrlr) (pst_u16GDCLARC1(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARC1(ctrlr,ParValue)  (*pu32GDCLARC1(ctrlr) = (ParValue))
#define u32GetGDCLARC1(ctrlr)  (*pu32GDCLARC1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARD0                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02058                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARD0_REG__       0xC0C02058U
#else
#define GDCLARD0_REG__ ((uint32_t) GDCLARD0_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARD0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARD0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARD0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARD0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARD0(ctrlr)     ((volatile GDCLARD0_bit_view_st *)\
(GDCLARD0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARD0(ctrlr)     ((volatile GDCLARD0_byte_view_st *)\
(GDCLARD0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARD0(ctrlr)     ((volatile GDCLARD0_halfword_view_st *)\
(GDCLARD0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARD0(ctrlr)     ((volatile u32GDCLARD0_word_view *)\
(GDCLARD0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARD0(ctrlr)     ((volatile GDCLARD0_bit_view_st *) &u32GDCLARD0_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARD0(ctrlr)     ((volatile GDCLARD0_byte_view_st *) &u32GDCLARD0_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARD0(ctrlr)     ((volatile GDCLARD0_halfword_view_st *) &u32GDCLARD0_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARD0(ctrlr)     ((volatile u32GDCLARD0_word_view *) &u32GDCLARD0_REG__Var[(ctrlr)])

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARD0_SSCROLL(ctrlr) (pst_bitGDCLARD0(ctrlr) -> SSCROLL)
#define vSetGDCLARD0_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARD0(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARD0_SAR(ctrlr) (pst_bitGDCLARD0(ctrlr) -> SAR)
#define vSetGDCLARD0_SAR(ctrlr,ParValue)  (pst_bitGDCLARD0(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARD0LL(ctrlr,ParValue) (pst_u8GDCLARD0(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARD0LL(ctrlr) (pst_u8GDCLARD0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARD0LH(ctrlr,ParValue) (pst_u8GDCLARD0(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARD0LH(ctrlr) (pst_u8GDCLARD0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARD0HL(ctrlr,ParValue) (pst_u8GDCLARD0(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARD0HL(ctrlr) (pst_u8GDCLARD0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARD0HH(ctrlr,ParValue) (pst_u8GDCLARD0(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARD0HH(ctrlr) (pst_u8GDCLARD0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARD0L(ctrlr,ParValue) (pst_u16GDCLARD0(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARD0L(ctrlr) (pst_u16GDCLARD0(ctrlr) -> u16L)
#define vSetGDCLARD0H(ctrlr,ParValue) (pst_u16GDCLARD0(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARD0H(ctrlr) (pst_u16GDCLARD0(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARD0(ctrlr,ParValue)  (*pu32GDCLARD0(ctrlr) = (ParValue))
#define u32GetGDCLARD0(ctrlr)  (*pu32GDCLARD0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARD1                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02060                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARD1_REG__       0xC0C02060U
#else
#define GDCLARD1_REG__ ((uint32_t) GDCLARD1_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARD1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARD1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARD1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARD1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARD1(ctrlr)     ((volatile GDCLARD1_bit_view_st *)\
(GDCLARD1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARD1(ctrlr)     ((volatile GDCLARD1_byte_view_st *)\
(GDCLARD1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARD1(ctrlr)     ((volatile GDCLARD1_halfword_view_st *)\
(GDCLARD1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARD1(ctrlr)     ((volatile u32GDCLARD1_word_view *)\
(GDCLARD1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARD1(ctrlr)     ((volatile GDCLARD1_bit_view_st *) &u32GDCLARD1_REG__Var[(ctrlr)])
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARD1(ctrlr)     ((volatile GDCLARD1_byte_view_st *) &u32GDCLARD1_REG__Var[(ctrlr)])
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARD1(ctrlr)     ((volatile GDCLARD1_halfword_view_st *) &u32GDCLARD1_REG__Var[(ctrlr)])
            
/* Pointer to WORD  */ 
#define pu32GDCLARD1(ctrlr)     ((volatile u32GDCLARD1_word_view *) &u32GDCLARD1_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARD1_SSCROLL(ctrlr) (pst_bitGDCLARD1(ctrlr) -> SSCROLL)
#define vSetGDCLARD1_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARD1(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARD1_SAR(ctrlr) (pst_bitGDCLARD1(ctrlr) -> SAR)
#define vSetGDCLARD1_SAR(ctrlr,ParValue)  (pst_bitGDCLARD1(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARD1LL(ctrlr,ParValue) (pst_u8GDCLARD1(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARD1LL(ctrlr) (pst_u8GDCLARD1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARD1LH(ctrlr,ParValue) (pst_u8GDCLARD1(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARD1LH(ctrlr) (pst_u8GDCLARD1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARD1HL(ctrlr,ParValue) (pst_u8GDCLARD1(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARD1HL(ctrlr) (pst_u8GDCLARD1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARD1HH(ctrlr,ParValue) (pst_u8GDCLARD1(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARD1HH(ctrlr) (pst_u8GDCLARD1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARD1L(ctrlr,ParValue) (pst_u16GDCLARD1(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARD1L(ctrlr) (pst_u16GDCLARD1(ctrlr) -> u16L)
#define vSetGDCLARD1H(ctrlr,ParValue) (pst_u16GDCLARD1(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARD1H(ctrlr) (pst_u16GDCLARD1(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARD1(ctrlr,ParValue)  (*pu32GDCLARD1(ctrlr) = (ParValue))
#define u32GetGDCLARD1(ctrlr)  (*pu32GDCLARD1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCMWRA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02068                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCMWRA_REG__       0xC0C02068U
#else
#define GDCMWRA_REG__ ((uint32_t) GDCMWRA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   MWR	:13; 	 /* 0..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..63  bit(s) R */                    
} GDCMWRA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GDCMWRA_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GDCMWRA_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCMWRA(ctrlr)     ((volatile GDCMWRA_bit_view_st *)\
(GDCMWRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRA(ctrlr)     ((volatile GDCMWRA_byte_view_st *)\
(GDCMWRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD */
#define pu16GDCMWRA(ctrlr)     ((volatile u16GDCMWRA_halfword_view *)\
(GDCMWRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else
/* Pointer to BIT-struct */
#define pst_bitGDCMWRA(ctrlr)     ((volatile GDCMWRA_bit_view_st *) &u32GDCMWRA_REG__Var[(ctrlr)])
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRA(ctrlr)     ((volatile GDCMWRA_byte_view_st *) &u32GDCMWRA_REG__Var[(ctrlr)])
            
/* Pointer to HALFWORD */
#define pu16GDCMWRA(ctrlr)     ((volatile u16GDCMWRA_halfword_view *) &u32GDCMWRA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCMWRA_MWR(ctrlr) (pst_bitGDCMWRA(ctrlr) -> MWR)
#define vSetGDCMWRA_MWR(ctrlr,ParValue)  (pst_bitGDCMWRA(ctrlr) -> MWR=(ParValue))
            
/* L-struct byte access */
#define vSetGDCMWRAL(ctrlr,ParValue) (pst_u8GDCMWRA(ctrlr) -> u8L = (ParValue))
#define u8GetGDCMWRAL(ctrlr) (pst_u8GDCMWRA(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGDCMWRAH(ctrlr,ParValue) (pst_u8GDCMWRA(ctrlr) -> u8H = (ParValue))
#define u8GetGDCMWRAH(ctrlr) (pst_u8GDCMWRA(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGDCMWRA(ctrlr,ParValue) (*pu16GDCMWRA(ctrlr)  = (ParValue))
#define u16GetGDCMWRA(ctrlr) (*pu16GDCMWRA(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCMWRB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02070                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCMWRB_REG__       0xC0C02070U
#else
#define GDCMWRB_REG__ ((uint32_t) GDCMWRB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   MWR	:13; 	 /* 0..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..63  bit(s) R */                    
} GDCMWRB_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GDCMWRB_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GDCMWRB_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCMWRB(ctrlr)     ((volatile GDCMWRB_bit_view_st *)\
(GDCMWRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRB(ctrlr)     ((volatile GDCMWRB_byte_view_st *)\
(GDCMWRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD */
#define pu16GDCMWRB(ctrlr)     ((volatile u16GDCMWRB_halfword_view *)\
(GDCMWRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCMWRB(ctrlr)     ((volatile GDCMWRB_bit_view_st *) &u32GDCMWRB_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRB(ctrlr)     ((volatile GDCMWRB_byte_view_st *) &u32GDCMWRB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD */
#define pu16GDCMWRB(ctrlr)     ((volatile u16GDCMWRB_halfword_view *) &u32GDCMWRB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCMWRB_MWR(ctrlr) (pst_bitGDCMWRB(ctrlr) -> MWR)
#define vSetGDCMWRB_MWR(ctrlr,ParValue)  (pst_bitGDCMWRB(ctrlr) -> MWR=(ParValue))
            
/* L-struct byte access */
#define vSetGDCMWRBL(ctrlr,ParValue) (pst_u8GDCMWRB(ctrlr) -> u8L = (ParValue))
#define u8GetGDCMWRBL(ctrlr) (pst_u8GDCMWRB(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGDCMWRBH(ctrlr,ParValue) (pst_u8GDCMWRB(ctrlr) -> u8H = (ParValue))
#define u8GetGDCMWRBH(ctrlr) (pst_u8GDCMWRB(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGDCMWRB(ctrlr,ParValue) (*pu16GDCMWRB(ctrlr)  = (ParValue))
#define u16GetGDCMWRB(ctrlr) (*pu16GDCMWRB(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCMWRC                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02078                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCMWRC_REG__       0xC0C02078U
#else
#define GDCMWRC_REG__ ((uint32_t) GDCMWRC_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   MWR	:13; 	 /* 0..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..63  bit(s) R */                    
} GDCMWRC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GDCMWRC_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GDCMWRC_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCMWRC(ctrlr)     ((volatile GDCMWRC_bit_view_st *)\
(GDCMWRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRC(ctrlr)     ((volatile GDCMWRC_byte_view_st *)\
(GDCMWRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD */
#define pu16GDCMWRC(ctrlr)     ((volatile u16GDCMWRC_halfword_view *)\
(GDCMWRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCMWRC(ctrlr)     ((volatile GDCMWRC_bit_view_st *) &u32GDCMWRC_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRC(ctrlr)     ((volatile GDCMWRC_byte_view_st *) &u32GDCMWRC_REG__Var[(ctrlr)])

/* Pointer to HALFWORD */
#define pu16GDCMWRC(ctrlr)     ((volatile u16GDCMWRC_halfword_view *) &u32GDCMWRC_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCMWRC_MWR(ctrlr) (pst_bitGDCMWRC(ctrlr) -> MWR)
#define vSetGDCMWRC_MWR(ctrlr,ParValue)  (pst_bitGDCMWRC(ctrlr) -> MWR=(ParValue))
            
/* L-struct byte access */
#define vSetGDCMWRCL(ctrlr,ParValue) (pst_u8GDCMWRC(ctrlr) -> u8L = (ParValue))
#define u8GetGDCMWRCL(ctrlr) (pst_u8GDCMWRC(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGDCMWRCH(ctrlr,ParValue) (pst_u8GDCMWRC(ctrlr) -> u8H = (ParValue))
#define u8GetGDCMWRCH(ctrlr) (pst_u8GDCMWRC(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGDCMWRC(ctrlr,ParValue) (*pu16GDCMWRC(ctrlr)  = (ParValue))
#define u16GetGDCMWRC(ctrlr) (*pu16GDCMWRC(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCMWRD                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02080                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCMWRD_REG__       0xC0C02080U
#else
#define GDCMWRD_REG__ ((uint32_t) GDCMWRD_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   MWR	:13; 	 /* 0..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..63  bit(s) R */                    
} GDCMWRD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GDCMWRD_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GDCMWRD_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCMWRD(ctrlr)     ((volatile GDCMWRD_bit_view_st *)\
(GDCMWRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRD(ctrlr)     ((volatile GDCMWRD_byte_view_st *)\
(GDCMWRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD */
#define pu16GDCMWRD(ctrlr)     ((volatile u16GDCMWRD_halfword_view *)\
(GDCMWRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCMWRD(ctrlr)     ((volatile GDCMWRD_bit_view_st *) &u32GDCMWRD_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRD(ctrlr)     ((volatile GDCMWRD_byte_view_st *) &u32GDCMWRD_REG__Var[(ctrlr)])

/* Pointer to HALFWORD */
#define pu16GDCMWRD(ctrlr)     ((volatile u16GDCMWRD_halfword_view *) &u32GDCMWRD_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCMWRD_MWR(ctrlr) (pst_bitGDCMWRD(ctrlr) -> MWR)
#define vSetGDCMWRD_MWR(ctrlr,ParValue)  (pst_bitGDCMWRD(ctrlr) -> MWR=(ParValue))
            
/* L-struct byte access */
#define vSetGDCMWRDL(ctrlr,ParValue) (pst_u8GDCMWRD(ctrlr) -> u8L = (ParValue))
#define u8GetGDCMWRDL(ctrlr) (pst_u8GDCMWRD(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGDCMWRDH(ctrlr,ParValue) (pst_u8GDCMWRD(ctrlr) -> u8H = (ParValue))
#define u8GetGDCMWRDH(ctrlr) (pst_u8GDCMWRD(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGDCMWRD(ctrlr,ParValue) (*pu16GDCMWRD(ctrlr)  = (ParValue))
#define u16GetGDCMWRD(ctrlr) (*pu16GDCMWRD(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCMWRE                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02088                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCMWRE_REG__       0xC0C02088U
#else
#define GDCMWRE_REG__ ((uint32_t) GDCMWRE_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   MWR	:13; 	 /* 0..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..63  bit(s) R */                    
} GDCMWRE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GDCMWRE_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GDCMWRE_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCMWRE(ctrlr)     ((volatile GDCMWRE_bit_view_st *)\
(GDCMWRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRE(ctrlr)     ((volatile GDCMWRE_byte_view_st *)\
(GDCMWRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD */
#define pu16GDCMWRE(ctrlr)     ((volatile u16GDCMWRE_halfword_view *)\
(GDCMWRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCMWRE(ctrlr)     ((volatile GDCMWRE_bit_view_st *) &u32GDCMWRE_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCMWRE(ctrlr)     ((volatile GDCMWRE_byte_view_st *) &u32GDCMWRE_REG__Var[(ctrlr)])

/* Pointer to HALFWORD */
#define pu16GDCMWRE(ctrlr)     ((volatile u16GDCMWRE_halfword_view *) &u32GDCMWRE_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCMWRE_MWR(ctrlr) (pst_bitGDCMWRE(ctrlr) -> MWR)
#define vSetGDCMWRE_MWR(ctrlr,ParValue)  (pst_bitGDCMWRE(ctrlr) -> MWR=(ParValue))
            
/* L-struct byte access */
#define vSetGDCMWREL(ctrlr,ParValue) (pst_u8GDCMWRE(ctrlr) -> u8L = (ParValue))
#define u8GetGDCMWREL(ctrlr) (pst_u8GDCMWRE(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGDCMWREH(ctrlr,ParValue) (pst_u8GDCMWRE(ctrlr) -> u8H = (ParValue))
#define u8GetGDCMWREH(ctrlr) (pst_u8GDCMWRE(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGDCMWRE(ctrlr,ParValue) (*pu16GDCMWRE(ctrlr)  = (ParValue))
#define u16GetGDCMWRE(ctrlr) (*pu16GDCMWRE(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLSRA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02090                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLSRA_REG__       0xC0C02090U
#else
#define GDCLSRA_REG__ ((uint32_t) GDCLSRA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LVS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   LHS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCLSRA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLSRA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLSRA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLSRA_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLSRA(ctrlr)     ((volatile GDCLSRA_bit_view_st *)\
(GDCLSRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRA(ctrlr)     ((volatile GDCLSRA_byte_view_st *)\
(GDCLSRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRA(ctrlr)     ((volatile GDCLSRA_halfword_view_st *)\
(GDCLSRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLSRA(ctrlr)     ((volatile u32GDCLSRA_word_view *)\
(GDCLSRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else
/* Pointer to BIT-struct */
#define pst_bitGDCLSRA(ctrlr)     ((volatile GDCLSRA_bit_view_st *) &u32GDCLSRA_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRA(ctrlr)     ((volatile GDCLSRA_byte_view_st *) &u32GDCLSRA_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRA(ctrlr)     ((volatile GDCLSRA_halfword_view_st *) &u32GDCLSRA_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLSRA(ctrlr)     ((volatile u32GDCLSRA_word_view *) &u32GDCLSRA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLSRA_LVS(ctrlr) (pst_bitGDCLSRA(ctrlr) -> LVS)
#define vSetGDCLSRA_LVS(ctrlr,ParValue)  (pst_bitGDCLSRA(ctrlr) -> LVS=(ParValue))
#define biGetGDCLSRA_LHS(ctrlr) (pst_bitGDCLSRA(ctrlr) -> LHS)
#define vSetGDCLSRA_LHS(ctrlr,ParValue)  (pst_bitGDCLSRA(ctrlr) -> LHS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLSRALL(ctrlr,ParValue) (pst_u8GDCLSRA(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLSRALL(ctrlr) (pst_u8GDCLSRA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLSRALH(ctrlr,ParValue) (pst_u8GDCLSRA(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLSRALH(ctrlr) (pst_u8GDCLSRA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLSRAHL(ctrlr,ParValue) (pst_u8GDCLSRA(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLSRAHL(ctrlr) (pst_u8GDCLSRA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLSRAHH(ctrlr,ParValue) (pst_u8GDCLSRA(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLSRAHH(ctrlr) (pst_u8GDCLSRA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLSRAL(ctrlr,ParValue) (pst_u16GDCLSRA(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLSRAL(ctrlr) (pst_u16GDCLSRA(ctrlr) -> u16L)
#define vSetGDCLSRAH(ctrlr,ParValue) (pst_u16GDCLSRA(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLSRAH(ctrlr) (pst_u16GDCLSRA(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLSRA(ctrlr,ParValue)  (*pu32GDCLSRA(ctrlr) = (ParValue))
#define u32GetGDCLSRA(ctrlr)  (*pu32GDCLSRA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLSRB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02098                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLSRB_REG__       0xC0C02098U
#else
#define GDCLSRB_REG__ ((uint32_t) GDCLSRB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LVS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   LHS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCLSRB_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLSRB_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLSRB_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLSRB_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLSRB(ctrlr)     ((volatile GDCLSRB_bit_view_st *)\
(GDCLSRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRB(ctrlr)     ((volatile GDCLSRB_byte_view_st *)\
(GDCLSRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRB(ctrlr)     ((volatile GDCLSRB_halfword_view_st *)\
(GDCLSRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLSRB(ctrlr)     ((volatile u32GDCLSRB_word_view *)\
(GDCLSRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLSRB(ctrlr)     ((volatile GDCLSRB_bit_view_st *) &u32GDCLSRB_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRB(ctrlr)     ((volatile GDCLSRB_byte_view_st *) &u32GDCLSRB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRB(ctrlr)     ((volatile GDCLSRB_halfword_view_st *) &u32GDCLSRB_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLSRB(ctrlr)     ((volatile u32GDCLSRB_word_view *) &u32GDCLSRB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLSRB_LVS(ctrlr) (pst_bitGDCLSRB(ctrlr) -> LVS)
#define vSetGDCLSRB_LVS(ctrlr,ParValue)  (pst_bitGDCLSRB(ctrlr) -> LVS=(ParValue))
#define biGetGDCLSRB_LHS(ctrlr) (pst_bitGDCLSRB(ctrlr) -> LHS)
#define vSetGDCLSRB_LHS(ctrlr,ParValue)  (pst_bitGDCLSRB(ctrlr) -> LHS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLSRBLL(ctrlr,ParValue) (pst_u8GDCLSRB(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLSRBLL(ctrlr) (pst_u8GDCLSRB(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLSRBLH(ctrlr,ParValue) (pst_u8GDCLSRB(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLSRBLH(ctrlr) (pst_u8GDCLSRB(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLSRBHL(ctrlr,ParValue) (pst_u8GDCLSRB(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLSRBHL(ctrlr) (pst_u8GDCLSRB(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLSRBHH(ctrlr,ParValue) (pst_u8GDCLSRB(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLSRBHH(ctrlr) (pst_u8GDCLSRB(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLSRBL(ctrlr,ParValue) (pst_u16GDCLSRB(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLSRBL(ctrlr) (pst_u16GDCLSRB(ctrlr) -> u16L)
#define vSetGDCLSRBH(ctrlr,ParValue) (pst_u16GDCLSRB(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLSRBH(ctrlr) (pst_u16GDCLSRB(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLSRB(ctrlr,ParValue)  (*pu32GDCLSRB(ctrlr) = (ParValue))
#define u32GetGDCLSRB(ctrlr)  (*pu32GDCLSRB(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLSRC                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020A0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLSRC_REG__       0xC0C020A0U
#else
#define GDCLSRC_REG__ ((uint32_t) GDCLSRC_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LVS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   LHS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCLSRC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLSRC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLSRC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLSRC_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLSRC(ctrlr)     ((volatile GDCLSRC_bit_view_st *)\
(GDCLSRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRC(ctrlr)     ((volatile GDCLSRC_byte_view_st *)\
(GDCLSRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRC(ctrlr)     ((volatile GDCLSRC_halfword_view_st *)\
(GDCLSRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLSRC(ctrlr)     ((volatile u32GDCLSRC_word_view *)\
(GDCLSRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLSRC(ctrlr)     ((volatile GDCLSRC_bit_view_st *) &u32GDCLSRC_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRC(ctrlr)     ((volatile GDCLSRC_byte_view_st *) &u32GDCLSRC_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRC(ctrlr)     ((volatile GDCLSRC_halfword_view_st *) &u32GDCLSRC_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLSRC(ctrlr)     ((volatile u32GDCLSRC_word_view *) &u32GDCLSRC_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLSRC_LVS(ctrlr) (pst_bitGDCLSRC(ctrlr) -> LVS)
#define vSetGDCLSRC_LVS(ctrlr,ParValue)  (pst_bitGDCLSRC(ctrlr) -> LVS=(ParValue))
#define biGetGDCLSRC_LHS(ctrlr) (pst_bitGDCLSRC(ctrlr) -> LHS)
#define vSetGDCLSRC_LHS(ctrlr,ParValue)  (pst_bitGDCLSRC(ctrlr) -> LHS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLSRCLL(ctrlr,ParValue) (pst_u8GDCLSRC(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLSRCLL(ctrlr) (pst_u8GDCLSRC(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLSRCLH(ctrlr,ParValue) (pst_u8GDCLSRC(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLSRCLH(ctrlr) (pst_u8GDCLSRC(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLSRCHL(ctrlr,ParValue) (pst_u8GDCLSRC(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLSRCHL(ctrlr) (pst_u8GDCLSRC(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLSRCHH(ctrlr,ParValue) (pst_u8GDCLSRC(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLSRCHH(ctrlr) (pst_u8GDCLSRC(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLSRCL(ctrlr,ParValue) (pst_u16GDCLSRC(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLSRCL(ctrlr) (pst_u16GDCLSRC(ctrlr) -> u16L)
#define vSetGDCLSRCH(ctrlr,ParValue) (pst_u16GDCLSRC(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLSRCH(ctrlr) (pst_u16GDCLSRC(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLSRC(ctrlr,ParValue)  (*pu32GDCLSRC(ctrlr) = (ParValue))
#define u32GetGDCLSRC(ctrlr)  (*pu32GDCLSRC(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLSRD                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020A8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLSRD_REG__       0xC0C020A8U
#else
#define GDCLSRD_REG__ ((uint32_t) GDCLSRD_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LVS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   LHS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCLSRD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLSRD_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLSRD_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLSRD_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLSRD(ctrlr)     ((volatile GDCLSRD_bit_view_st *)\
(GDCLSRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRD(ctrlr)     ((volatile GDCLSRD_byte_view_st *)\
(GDCLSRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRD(ctrlr)     ((volatile GDCLSRD_halfword_view_st *)\
(GDCLSRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLSRD(ctrlr)     ((volatile u32GDCLSRD_word_view *)\
(GDCLSRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLSRD(ctrlr)     ((volatile GDCLSRD_bit_view_st *) &u32GDCLSRD_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRD(ctrlr)     ((volatile GDCLSRD_byte_view_st *) &u32GDCLSRD_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRD(ctrlr)     ((volatile GDCLSRD_halfword_view_st *) &u32GDCLSRD_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLSRD(ctrlr)     ((volatile u32GDCLSRD_word_view *) &u32GDCLSRD_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLSRD_LVS(ctrlr) (pst_bitGDCLSRD(ctrlr) -> LVS)
#define vSetGDCLSRD_LVS(ctrlr,ParValue)  (pst_bitGDCLSRD(ctrlr) -> LVS=(ParValue))
#define biGetGDCLSRD_LHS(ctrlr) (pst_bitGDCLSRD(ctrlr) -> LHS)
#define vSetGDCLSRD_LHS(ctrlr,ParValue)  (pst_bitGDCLSRD(ctrlr) -> LHS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLSRDLL(ctrlr,ParValue) (pst_u8GDCLSRD(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLSRDLL(ctrlr) (pst_u8GDCLSRD(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLSRDLH(ctrlr,ParValue) (pst_u8GDCLSRD(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLSRDLH(ctrlr) (pst_u8GDCLSRD(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLSRDHL(ctrlr,ParValue) (pst_u8GDCLSRD(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLSRDHL(ctrlr) (pst_u8GDCLSRD(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLSRDHH(ctrlr,ParValue) (pst_u8GDCLSRD(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLSRDHH(ctrlr) (pst_u8GDCLSRD(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLSRDL(ctrlr,ParValue) (pst_u16GDCLSRD(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLSRDL(ctrlr) (pst_u16GDCLSRD(ctrlr) -> u16L)
#define vSetGDCLSRDH(ctrlr,ParValue) (pst_u16GDCLSRD(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLSRDH(ctrlr) (pst_u16GDCLSRD(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLSRD(ctrlr,ParValue)  (*pu32GDCLSRD(ctrlr) = (ParValue))
#define u32GetGDCLSRD(ctrlr)  (*pu32GDCLSRD(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLSRE                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020B0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLSRE_REG__       0xC0C020B0U
#else
#define GDCLSRE_REG__ ((uint32_t) GDCLSRE_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LVS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   LHS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCLSRE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLSRE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLSRE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLSRE_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLSRE(ctrlr)     ((volatile GDCLSRE_bit_view_st *)\
(GDCLSRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRE(ctrlr)     ((volatile GDCLSRE_byte_view_st *)\
(GDCLSRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRE(ctrlr)     ((volatile GDCLSRE_halfword_view_st *)\
(GDCLSRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLSRE(ctrlr)     ((volatile u32GDCLSRE_word_view *)\
(GDCLSRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLSRE(ctrlr)     ((volatile GDCLSRE_bit_view_st *) &u32GDCLSRE_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLSRE(ctrlr)     ((volatile GDCLSRE_byte_view_st *) &u32GDCLSRE_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLSRE(ctrlr)     ((volatile GDCLSRE_halfword_view_st *) &u32GDCLSRE_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLSRE(ctrlr)     ((volatile u32GDCLSRE_word_view *) &u32GDCLSRE_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLSRE_LVS(ctrlr) (pst_bitGDCLSRE(ctrlr) -> LVS)
#define vSetGDCLSRE_LVS(ctrlr,ParValue)  (pst_bitGDCLSRE(ctrlr) -> LVS=(ParValue))
#define biGetGDCLSRE_LHS(ctrlr) (pst_bitGDCLSRE(ctrlr) -> LHS)
#define vSetGDCLSRE_LHS(ctrlr,ParValue)  (pst_bitGDCLSRE(ctrlr) -> LHS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLSRELL(ctrlr,ParValue) (pst_u8GDCLSRE(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLSRELL(ctrlr) (pst_u8GDCLSRE(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLSRELH(ctrlr,ParValue) (pst_u8GDCLSRE(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLSRELH(ctrlr) (pst_u8GDCLSRE(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLSREHL(ctrlr,ParValue) (pst_u8GDCLSRE(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLSREHL(ctrlr) (pst_u8GDCLSRE(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLSREHH(ctrlr,ParValue) (pst_u8GDCLSRE(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLSREHH(ctrlr) (pst_u8GDCLSRE(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLSREL(ctrlr,ParValue) (pst_u16GDCLSRE(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLSREL(ctrlr) (pst_u16GDCLSRE(ctrlr) -> u16L)
#define vSetGDCLSREH(ctrlr,ParValue) (pst_u16GDCLSRE(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLSREH(ctrlr) (pst_u16GDCLSRE(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLSRE(ctrlr,ParValue)  (*pu32GDCLSRE(ctrlr) = (ParValue))
#define u32GetGDCLSRE(ctrlr)  (*pu32GDCLSRE(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLDRA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020B8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLDRA_REG__       0xC0C020B8U
#else
#define GDCLDRA_REG__ ((uint32_t) GDCLDRA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   LWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCLDRA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLDRA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLDRA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLDRA_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLDRA(ctrlr)     ((volatile GDCLDRA_bit_view_st *)\
(GDCLDRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRA(ctrlr)     ((volatile GDCLDRA_byte_view_st *)\
(GDCLDRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRA(ctrlr)     ((volatile GDCLDRA_halfword_view_st *)\
(GDCLDRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLDRA(ctrlr)     ((volatile u32GDCLDRA_word_view *)\
(GDCLDRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLDRA(ctrlr)     ((volatile GDCLDRA_bit_view_st *) &u32GDCLDRA_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRA(ctrlr)     ((volatile GDCLDRA_byte_view_st *) &u32GDCLDRA_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRA(ctrlr)     ((volatile GDCLDRA_halfword_view_st *) &u32GDCLDRA_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLDRA(ctrlr)     ((volatile u32GDCLDRA_word_view *) &u32GDCLDRA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLDRA_LHEIGHT(ctrlr) (pst_bitGDCLDRA(ctrlr) -> LHEIGHT)
#define vSetGDCLDRA_LHEIGHT(ctrlr,ParValue)  (pst_bitGDCLDRA(ctrlr) -> LHEIGHT=(ParValue))
#define biGetGDCLDRA_LWIDTH(ctrlr) (pst_bitGDCLDRA(ctrlr) -> LWIDTH)
#define vSetGDCLDRA_LWIDTH(ctrlr,ParValue)  (pst_bitGDCLDRA(ctrlr) -> LWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLDRALL(ctrlr,ParValue) (pst_u8GDCLDRA(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLDRALL(ctrlr) (pst_u8GDCLDRA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLDRALH(ctrlr,ParValue) (pst_u8GDCLDRA(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLDRALH(ctrlr) (pst_u8GDCLDRA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLDRAHL(ctrlr,ParValue) (pst_u8GDCLDRA(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLDRAHL(ctrlr) (pst_u8GDCLDRA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLDRAHH(ctrlr,ParValue) (pst_u8GDCLDRA(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLDRAHH(ctrlr) (pst_u8GDCLDRA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLDRAL(ctrlr,ParValue) (pst_u16GDCLDRA(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLDRAL(ctrlr) (pst_u16GDCLDRA(ctrlr) -> u16L)
#define vSetGDCLDRAH(ctrlr,ParValue) (pst_u16GDCLDRA(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLDRAH(ctrlr) (pst_u16GDCLDRA(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLDRA(ctrlr,ParValue)  (*pu32GDCLDRA(ctrlr) = (ParValue))
#define u32GetGDCLDRA(ctrlr)  (*pu32GDCLDRA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLDRB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020C0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLDRB_REG__       0xC0C020C0U
#else
#define GDCLDRB_REG__ ((uint32_t) &GDCLDRB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   LWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCLDRB_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLDRB_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLDRB_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLDRB_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLDRB(ctrlr)     ((volatile GDCLDRB_bit_view_st *)\
(GDCLDRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRB(ctrlr)     ((volatile GDCLDRB_byte_view_st *)\
(GDCLDRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRB(ctrlr)     ((volatile GDCLDRB_halfword_view_st *)\
(GDCLDRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLDRB(ctrlr)     ((volatile u32GDCLDRB_word_view *)\
(GDCLDRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLDRB(ctrlr)     ((volatile GDCLDRB_bit_view_st *) &u32GDCLDRB_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRB(ctrlr)     ((volatile GDCLDRB_byte_view_st *) &u32GDCLDRB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRB(ctrlr)     ((volatile GDCLDRB_halfword_view_st *) &u32GDCLDRB_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLDRB(ctrlr)     ((volatile u32GDCLDRB_word_view *) &u32GDCLDRB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLDRB_LHEIGHT(ctrlr) (pst_bitGDCLDRB(ctrlr) -> LHEIGHT)
#define vSetGDCLDRB_LHEIGHT(ctrlr,ParValue)  (pst_bitGDCLDRB(ctrlr) -> LHEIGHT=(ParValue))
#define biGetGDCLDRB_LWIDTH(ctrlr) (pst_bitGDCLDRB(ctrlr) -> LWIDTH)
#define vSetGDCLDRB_LWIDTH(ctrlr,ParValue)  (pst_bitGDCLDRB(ctrlr) -> LWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLDRBLL(ctrlr,ParValue) (pst_u8GDCLDRB(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLDRBLL(ctrlr) (pst_u8GDCLDRB(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLDRBLH(ctrlr,ParValue) (pst_u8GDCLDRB(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLDRBLH(ctrlr) (pst_u8GDCLDRB(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLDRBHL(ctrlr,ParValue) (pst_u8GDCLDRB(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLDRBHL(ctrlr) (pst_u8GDCLDRB(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLDRBHH(ctrlr,ParValue) (pst_u8GDCLDRB(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLDRBHH(ctrlr) (pst_u8GDCLDRB(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLDRBL(ctrlr,ParValue) (pst_u16GDCLDRB(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLDRBL(ctrlr) (pst_u16GDCLDRB(ctrlr) -> u16L)
#define vSetGDCLDRBH(ctrlr,ParValue) (pst_u16GDCLDRB(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLDRBH(ctrlr) (pst_u16GDCLDRB(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLDRB(ctrlr,ParValue)  (*pu32GDCLDRB(ctrlr) = (ParValue))
#define u32GetGDCLDRB(ctrlr)  (*pu32GDCLDRB(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLDRC                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020C8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLDRC_REG__       0xC0C020C8U
#else
#define GDCLDRC_REG__ ((uint32_t) GDCLDRC_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   LWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCLDRC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLDRC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLDRC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLDRC_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLDRC(ctrlr)     ((volatile GDCLDRC_bit_view_st *)\
(GDCLDRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRC(ctrlr)     ((volatile GDCLDRC_byte_view_st *)\
(GDCLDRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRC(ctrlr)     ((volatile GDCLDRC_halfword_view_st *)\
(GDCLDRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLDRC(ctrlr)     ((volatile u32GDCLDRC_word_view *)\
(GDCLDRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLDRC(ctrlr)     ((volatile GDCLDRC_bit_view_st *) &u32GDCLDRC_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRC(ctrlr)     ((volatile GDCLDRC_byte_view_st *) &u32GDCLDRC_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRC(ctrlr)     ((volatile GDCLDRC_halfword_view_st *) &u32GDCLDRC_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLDRC(ctrlr)     ((volatile u32GDCLDRC_word_view *) &u32GDCLDRC_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLDRC_LHEIGHT(ctrlr) (pst_bitGDCLDRC(ctrlr) -> LHEIGHT)
#define vSetGDCLDRC_LHEIGHT(ctrlr,ParValue)  (pst_bitGDCLDRC(ctrlr) -> LHEIGHT=(ParValue))
#define biGetGDCLDRC_LWIDTH(ctrlr) (pst_bitGDCLDRC(ctrlr) -> LWIDTH)
#define vSetGDCLDRC_LWIDTH(ctrlr,ParValue)  (pst_bitGDCLDRC(ctrlr) -> LWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLDRCLL(ctrlr,ParValue) (pst_u8GDCLDRC(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLDRCLL(ctrlr) (pst_u8GDCLDRC(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLDRCLH(ctrlr,ParValue) (pst_u8GDCLDRC(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLDRCLH(ctrlr) (pst_u8GDCLDRC(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLDRCHL(ctrlr,ParValue) (pst_u8GDCLDRC(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLDRCHL(ctrlr) (pst_u8GDCLDRC(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLDRCHH(ctrlr,ParValue) (pst_u8GDCLDRC(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLDRCHH(ctrlr) (pst_u8GDCLDRC(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLDRCL(ctrlr,ParValue) (pst_u16GDCLDRC(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLDRCL(ctrlr) (pst_u16GDCLDRC(ctrlr) -> u16L)
#define vSetGDCLDRCH(ctrlr,ParValue) (pst_u16GDCLDRC(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLDRCH(ctrlr) (pst_u16GDCLDRC(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLDRC(ctrlr,ParValue)  (*pu32GDCLDRC(ctrlr) = (ParValue))
#define u32GetGDCLDRC(ctrlr)  (*pu32GDCLDRC(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLDRD                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020D0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLDRD_REG__       0xC0C020D0U
#else
#define GDCLDRD_REG__ ((uint32_t) GDCLDRD_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   LWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCLDRD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLDRD_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLDRD_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLDRD_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLDRD(ctrlr)     ((volatile GDCLDRD_bit_view_st *)\
(GDCLDRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRD(ctrlr)     ((volatile GDCLDRD_byte_view_st *)\
(GDCLDRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRD(ctrlr)     ((volatile GDCLDRD_halfword_view_st *)\
(GDCLDRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLDRD(ctrlr)     ((volatile u32GDCLDRD_word_view *)\
(GDCLDRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLDRD(ctrlr)     ((volatile GDCLDRD_bit_view_st *) &u32GDCLDRD_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRD(ctrlr)     ((volatile GDCLDRD_byte_view_st *) &u32GDCLDRD_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRD(ctrlr)     ((volatile GDCLDRD_halfword_view_st *) &u32GDCLDRD_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLDRD(ctrlr)     ((volatile u32GDCLDRD_word_view *) &u32GDCLDRD_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLDRD_LHEIGHT(ctrlr) (pst_bitGDCLDRD(ctrlr) -> LHEIGHT)
#define vSetGDCLDRD_LHEIGHT(ctrlr,ParValue)  (pst_bitGDCLDRD(ctrlr) -> LHEIGHT=(ParValue))
#define biGetGDCLDRD_LWIDTH(ctrlr) (pst_bitGDCLDRD(ctrlr) -> LWIDTH)
#define vSetGDCLDRD_LWIDTH(ctrlr,ParValue)  (pst_bitGDCLDRD(ctrlr) -> LWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLDRDLL(ctrlr,ParValue) (pst_u8GDCLDRD(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLDRDLL(ctrlr) (pst_u8GDCLDRD(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLDRDLH(ctrlr,ParValue) (pst_u8GDCLDRD(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLDRDLH(ctrlr) (pst_u8GDCLDRD(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLDRDHL(ctrlr,ParValue) (pst_u8GDCLDRD(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLDRDHL(ctrlr) (pst_u8GDCLDRD(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLDRDHH(ctrlr,ParValue) (pst_u8GDCLDRD(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLDRDHH(ctrlr) (pst_u8GDCLDRD(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLDRDL(ctrlr,ParValue) (pst_u16GDCLDRD(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLDRDL(ctrlr) (pst_u16GDCLDRD(ctrlr) -> u16L)
#define vSetGDCLDRDH(ctrlr,ParValue) (pst_u16GDCLDRD(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLDRDH(ctrlr) (pst_u16GDCLDRD(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLDRD(ctrlr,ParValue)  (*pu32GDCLDRD(ctrlr) = (ParValue))
#define u32GetGDCLDRD(ctrlr)  (*pu32GDCLDRD(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLDRE                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020D8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLDRE_REG__       0xC0C020D8U
#else
#define GDCLDRE_REG__ ((uint32_t) GDCLDRE_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   LWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCLDRE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLDRE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLDRE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLDRE_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLDRE(ctrlr)     ((volatile GDCLDRE_bit_view_st *)\
(GDCLDRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRE(ctrlr)     ((volatile GDCLDRE_byte_view_st *)\
(GDCLDRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRE(ctrlr)     ((volatile GDCLDRE_halfword_view_st *)\
(GDCLDRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLDRE(ctrlr)     ((volatile u32GDCLDRE_word_view *)\
(GDCLDRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLDRE(ctrlr)     ((volatile GDCLDRE_bit_view_st *) &u32GDCLDRE_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLDRE(ctrlr)     ((volatile GDCLDRE_byte_view_st *) &u32GDCLDRE_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLDRE(ctrlr)     ((volatile GDCLDRE_halfword_view_st *) &u32GDCLDRE_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLDRE(ctrlr)     ((volatile u32GDCLDRE_word_view *) &u32GDCLDRE_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLDRE_LHEIGHT(ctrlr) (pst_bitGDCLDRE(ctrlr) -> LHEIGHT)
#define vSetGDCLDRE_LHEIGHT(ctrlr,ParValue)  (pst_bitGDCLDRE(ctrlr) -> LHEIGHT=(ParValue))
#define biGetGDCLDRE_LWIDTH(ctrlr) (pst_bitGDCLDRE(ctrlr) -> LWIDTH)
#define vSetGDCLDRE_LWIDTH(ctrlr,ParValue)  (pst_bitGDCLDRE(ctrlr) -> LWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLDRELL(ctrlr,ParValue) (pst_u8GDCLDRE(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLDRELL(ctrlr) (pst_u8GDCLDRE(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLDRELH(ctrlr,ParValue) (pst_u8GDCLDRE(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLDRELH(ctrlr) (pst_u8GDCLDRE(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLDREHL(ctrlr,ParValue) (pst_u8GDCLDRE(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLDREHL(ctrlr) (pst_u8GDCLDRE(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLDREHH(ctrlr,ParValue) (pst_u8GDCLDRE(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLDREHH(ctrlr) (pst_u8GDCLDRE(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLDREL(ctrlr,ParValue) (pst_u16GDCLDRE(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLDREL(ctrlr) (pst_u16GDCLDRE(ctrlr) -> u16L)
#define vSetGDCLDREH(ctrlr,ParValue) (pst_u16GDCLDRE(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLDREH(ctrlr) (pst_u16GDCLDRE(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLDRE(ctrlr,ParValue)  (*pu32GDCLDRE(ctrlr) = (ParValue))
#define u32GetGDCLDRE(ctrlr)  (*pu32GDCLDRE(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWSRA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020E0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWSRA_REG__       0xC0C020E0U
#else
#define GDCWSRA_REG__ ((uint32_t) GDCWSRA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WVS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   WHS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCWSRA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWSRA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWSRA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWSRA_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWSRA(ctrlr)     ((volatile GDCWSRA_bit_view_st *)\
(GDCWSRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRA(ctrlr)     ((volatile GDCWSRA_byte_view_st *)\
(GDCWSRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRA(ctrlr)     ((volatile GDCWSRA_halfword_view_st *)\
(GDCWSRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWSRA(ctrlr)     ((volatile u32GDCWSRA_word_view *)\
(GDCWSRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWSRA(ctrlr)     ((volatile GDCWSRA_bit_view_st *) &u32GDCWSRA_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRA(ctrlr)     ((volatile GDCWSRA_byte_view_st *) &u32GDCWSRA_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRA(ctrlr)     ((volatile GDCWSRA_halfword_view_st *) &u32GDCWSRA_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWSRA(ctrlr)     ((volatile u32GDCWSRA_word_view *) &u32GDCWSRA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWSRA_WVS(ctrlr) (pst_bitGDCWSRA(ctrlr) -> WVS)
#define vSetGDCWSRA_WVS(ctrlr,ParValue)  (pst_bitGDCWSRA(ctrlr) -> WVS=(ParValue))
#define biGetGDCWSRA_WHS(ctrlr) (pst_bitGDCWSRA(ctrlr) -> WHS)
#define vSetGDCWSRA_WHS(ctrlr,ParValue)  (pst_bitGDCWSRA(ctrlr) -> WHS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWSRALL(ctrlr,ParValue) (pst_u8GDCWSRA(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWSRALL(ctrlr) (pst_u8GDCWSRA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWSRALH(ctrlr,ParValue) (pst_u8GDCWSRA(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWSRALH(ctrlr) (pst_u8GDCWSRA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWSRAHL(ctrlr,ParValue) (pst_u8GDCWSRA(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWSRAHL(ctrlr) (pst_u8GDCWSRA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWSRAHH(ctrlr,ParValue) (pst_u8GDCWSRA(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWSRAHH(ctrlr) (pst_u8GDCWSRA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWSRAL(ctrlr,ParValue) (pst_u16GDCWSRA(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWSRAL(ctrlr) (pst_u16GDCWSRA(ctrlr) -> u16L)
#define vSetGDCWSRAH(ctrlr,ParValue) (pst_u16GDCWSRA(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWSRAH(ctrlr) (pst_u16GDCWSRA(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWSRA(ctrlr,ParValue)  (*pu32GDCWSRA(ctrlr) = (ParValue))
#define u32GetGDCWSRA(ctrlr)  (*pu32GDCWSRA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWSRB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020E8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWSRB_REG__       0xC0C020E8U
#else
#define GDCWSRB_REG__ ((uint32_t) GDCWSRB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WVDS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   WHDS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCWSRB_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWSRB_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWSRB_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWSRB_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWSRB(ctrlr)     ((volatile GDCWSRB_bit_view_st *)\
(GDCWSRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRB(ctrlr)     ((volatile GDCWSRB_byte_view_st *)\
(GDCWSRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRB(ctrlr)     ((volatile GDCWSRB_halfword_view_st *)\
(GDCWSRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWSRB(ctrlr)     ((volatile u32GDCWSRB_word_view *)\
(GDCWSRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWSRB(ctrlr)     ((volatile GDCWSRB_bit_view_st *) &u32GDCWSRB_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRB(ctrlr)     ((volatile GDCWSRB_byte_view_st *) &u32GDCWSRB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRB(ctrlr)     ((volatile GDCWSRB_halfword_view_st *) &u32GDCWSRB_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWSRB(ctrlr)     ((volatile u32GDCWSRB_word_view *) &u32GDCWSRB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWSRB_WVDS(ctrlr) (pst_bitGDCWSRB(ctrlr) -> WVDS)
#define vSetGDCWSRB_WVDS(ctrlr,ParValue)  (pst_bitGDCWSRB(ctrlr) -> WVDS=(ParValue))
#define biGetGDCWSRB_WHDS(ctrlr) (pst_bitGDCWSRB(ctrlr) -> WHDS)
#define vSetGDCWSRB_WHDS(ctrlr,ParValue)  (pst_bitGDCWSRB(ctrlr) -> WHDS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWSRBLL(ctrlr,ParValue) (pst_u8GDCWSRB(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWSRBLL(ctrlr) (pst_u8GDCWSRB(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWSRBLH(ctrlr,ParValue) (pst_u8GDCWSRB(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWSRBLH(ctrlr) (pst_u8GDCWSRB(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWSRBHL(ctrlr,ParValue) (pst_u8GDCWSRB(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWSRBHL(ctrlr) (pst_u8GDCWSRB(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWSRBHH(ctrlr,ParValue) (pst_u8GDCWSRB(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWSRBHH(ctrlr) (pst_u8GDCWSRB(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWSRBL(ctrlr,ParValue) (pst_u16GDCWSRB(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWSRBL(ctrlr) (pst_u16GDCWSRB(ctrlr) -> u16L)
#define vSetGDCWSRBH(ctrlr,ParValue) (pst_u16GDCWSRB(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWSRBH(ctrlr) (pst_u16GDCWSRB(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWSRB(ctrlr,ParValue)  (*pu32GDCWSRB(ctrlr) = (ParValue))
#define u32GetGDCWSRB(ctrlr)  (*pu32GDCWSRB(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWIMRA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020F0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWIMRA_REG__       0xC0C020F0U
#else
#define GDCWIMRA_REG__ ((uint32_t) GDCWIMRA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   WWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCWIMRA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWIMRA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWIMRA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWIMRA_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWIMRA(ctrlr)     ((volatile GDCWIMRA_bit_view_st *)\
(GDCWIMRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRA(ctrlr)     ((volatile GDCWIMRA_byte_view_st *)\
(GDCWIMRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRA(ctrlr)     ((volatile GDCWIMRA_halfword_view_st *)\
(GDCWIMRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWIMRA(ctrlr)     ((volatile u32GDCWIMRA_word_view *)\
(GDCWIMRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWIMRA(ctrlr)     ((volatile GDCWIMRA_bit_view_st *) &u32GDCWIMRA_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRA(ctrlr)     ((volatile GDCWIMRA_byte_view_st *) &u32GDCWIMRA_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRA(ctrlr)     ((volatile GDCWIMRA_halfword_view_st *) &u32GDCWIMRA_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWIMRA(ctrlr)     ((volatile u32GDCWIMRA_word_view *) &u32GDCWIMRA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWIMRA_WHEIGHT(ctrlr) (pst_bitGDCWIMRA(ctrlr) -> WHEIGHT)
#define vSetGDCWIMRA_WHEIGHT(ctrlr,ParValue)  (pst_bitGDCWIMRA(ctrlr) -> WHEIGHT=(ParValue))
#define biGetGDCWIMRA_WWIDTH(ctrlr) (pst_bitGDCWIMRA(ctrlr) -> WWIDTH)
#define vSetGDCWIMRA_WWIDTH(ctrlr,ParValue)  (pst_bitGDCWIMRA(ctrlr) -> WWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWIMRALL(ctrlr,ParValue) (pst_u8GDCWIMRA(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWIMRALL(ctrlr) (pst_u8GDCWIMRA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWIMRALH(ctrlr,ParValue) (pst_u8GDCWIMRA(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWIMRALH(ctrlr) (pst_u8GDCWIMRA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWIMRAHL(ctrlr,ParValue) (pst_u8GDCWIMRA(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWIMRAHL(ctrlr) (pst_u8GDCWIMRA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWIMRAHH(ctrlr,ParValue) (pst_u8GDCWIMRA(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWIMRAHH(ctrlr) (pst_u8GDCWIMRA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWIMRAL(ctrlr,ParValue) (pst_u16GDCWIMRA(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWIMRAL(ctrlr) (pst_u16GDCWIMRA(ctrlr) -> u16L)
#define vSetGDCWIMRAH(ctrlr,ParValue) (pst_u16GDCWIMRA(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWIMRAH(ctrlr) (pst_u16GDCWIMRA(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWIMRA(ctrlr,ParValue)  (*pu32GDCWIMRA(ctrlr) = (ParValue))
#define u32GetGDCWIMRA(ctrlr)  (*pu32GDCWIMRA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWIMRB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C020F8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWIMRB_REG__       0xC0C020F8U
#else
#define GDCWIMRB_REG__ ((uint32_t) GDCWIMRB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   WWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCWIMRB_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWIMRB_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWIMRB_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWIMRB_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWIMRB(ctrlr)     ((volatile GDCWIMRB_bit_view_st *)\
(GDCWIMRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRB(ctrlr)     ((volatile GDCWIMRB_byte_view_st *)\
(GDCWIMRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRB(ctrlr)     ((volatile GDCWIMRB_halfword_view_st *)\
(GDCWIMRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWIMRB(ctrlr)     ((volatile u32GDCWIMRB_word_view *)\
(GDCWIMRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWIMRB(ctrlr)     ((volatile GDCWIMRB_bit_view_st *) &u32GDCWIMRB_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRB(ctrlr)     ((volatile GDCWIMRB_byte_view_st *) &u32GDCWIMRB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRB(ctrlr)     ((volatile GDCWIMRB_halfword_view_st *) &u32GDCWIMRB_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWIMRB(ctrlr)     ((volatile u32GDCWIMRB_word_view *) &u32GDCWIMRB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWIMRB_WHEIGHT(ctrlr) (pst_bitGDCWIMRB(ctrlr) -> WHEIGHT)
#define vSetGDCWIMRB_WHEIGHT(ctrlr,ParValue)  (pst_bitGDCWIMRB(ctrlr) -> WHEIGHT=(ParValue))
#define biGetGDCWIMRB_WWIDTH(ctrlr) (pst_bitGDCWIMRB(ctrlr) -> WWIDTH)
#define vSetGDCWIMRB_WWIDTH(ctrlr,ParValue)  (pst_bitGDCWIMRB(ctrlr) -> WWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWIMRBLL(ctrlr,ParValue) (pst_u8GDCWIMRB(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWIMRBLL(ctrlr) (pst_u8GDCWIMRB(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWIMRBLH(ctrlr,ParValue) (pst_u8GDCWIMRB(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWIMRBLH(ctrlr) (pst_u8GDCWIMRB(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWIMRBHL(ctrlr,ParValue) (pst_u8GDCWIMRB(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWIMRBHL(ctrlr) (pst_u8GDCWIMRB(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWIMRBHH(ctrlr,ParValue) (pst_u8GDCWIMRB(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWIMRBHH(ctrlr) (pst_u8GDCWIMRB(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWIMRBL(ctrlr,ParValue) (pst_u16GDCWIMRB(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWIMRBL(ctrlr) (pst_u16GDCWIMRB(ctrlr) -> u16L)
#define vSetGDCWIMRBH(ctrlr,ParValue) (pst_u16GDCWIMRB(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWIMRBH(ctrlr) (pst_u16GDCWIMRB(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWIMRB(ctrlr,ParValue)  (*pu32GDCWIMRB(ctrlr) = (ParValue))
#define u32GetGDCWIMRB(ctrlr)  (*pu32GDCWIMRB(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCCAVRA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02100                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCCAVRA_REG__       0xC0C02100U
#else
#define GDCCAVRA_REG__ ((uint32_t) GDCCAVRA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   ALPHAA	:8; 	 /* 0..7  bit(s) R/W */
  uint64_t   WALPHAA	:8; 	 /* 8..15  bit(s) R/W */
  uint64_t   ALPHAB	:8; 	 /* 16..23  bit(s) R/W */
  uint64_t   WALPHAB	:8; 	 /* 24..31  bit(s) R/W */
  uint64_t   ALPHAC	:8; 	 /* 32..39  bit(s) R/W */
  uint64_t   WALPHAC	:8; 	 /* 40..47  bit(s) R/W */
  uint64_t   ALPHAD	:8; 	 /* 48..55  bit(s) R/W */ 
  uint64_t   WALPHAD	:8; 	 /* 56..63  bit(s) R/W */                    
} GDCCAVRA_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} GDCCAVRA_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} GDCCAVRA_word_view_st;

/* LONGWORD View */
typedef uint64_t u64GDCCAVRA_longword_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCCAVRA(ctrlr)     ((volatile GDCCAVRA_bit_view_st *)\
(GDCCAVRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16GDCCAVRA(ctrlr)     ((volatile GDCCAVRA_halfword_view_st *)\
(GDCCAVRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32GDCCAVRA(ctrlr)   ((volatile GDCCAVRA_word_view_st *) \
(GDCCAVRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to LONG_WORD  */
#define pu64GDCCAVRA(ctrlr)    ((volatile u64GDCCAVRA_longword_view *)\
(GDCCAVRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCCAVRA(ctrlr)     ((volatile GDCCAVRA_bit_view_st *) &u64GDCCAVRA_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCCAVRA(ctrlr)     ((volatile GDCCAVRA_halfword_view_st *) &u64GDCCAVRA_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32GDCCAVRA(ctrlr)   ((volatile GDCCAVRA_word_view_st *) &u64GDCCAVRA_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64GDCCAVRA(ctrlr)    ((volatile u64GDCCAVRA_longword_view *) &u64GDCCAVRA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCCAVRA_ALPHAA(ctrlr) (pst_bitGDCCAVRA(ctrlr) -> ALPHAA)
#define vSetGDCCAVRA_ALPHAA(ctrlr,ParValue)  (pst_bitGDCCAVRA(ctrlr) -> ALPHAA=(ParValue))
#define biGetGDCCAVRA_WALPHAA(ctrlr) (pst_bitGDCCAVRA(ctrlr) -> WALPHAA)
#define vSetGDCCAVRA_WALPHAA(ctrlr,ParValue)  (pst_bitGDCCAVRA(ctrlr) -> WALPHAA=(ParValue))
#define biGetGDCCAVRA_ALPHAB(ctrlr) (pst_bitGDCCAVRA(ctrlr) -> ALPHAB)
#define vSetGDCCAVRA_ALPHAB(ctrlr,ParValue)  (pst_bitGDCCAVRA(ctrlr) -> ALPHAB=(ParValue))
#define biGetGDCCAVRA_WALPHAB(ctrlr) (pst_bitGDCCAVRA(ctrlr) -> WALPHAB)
#define vSetGDCCAVRA_WALPHAB(ctrlr,ParValue)  (pst_bitGDCCAVRA(ctrlr) -> WALPHAB=(ParValue))
#define biGetGDCCAVRA_ALPHAC(ctrlr) (pst_bitGDCCAVRA(ctrlr) -> ALPHAC)
#define vSetGDCCAVRA_ALPHAC(ctrlr,ParValue)  (pst_bitGDCCAVRA(ctrlr) -> ALPHAC=(ParValue))
#define biGetGDCCAVRA_WALPHAC(ctrlr) (pst_bitGDCCAVRA(ctrlr) -> WALPHAC)
#define vSetGDCCAVRA_WALPHAC(ctrlr,ParValue)  (pst_bitGDCCAVRA(ctrlr) -> WALPHAC=(ParValue))
#define biGetGDCCAVRA_ALPHAD(ctrlr) (pst_bitGDCCAVRA(ctrlr) -> ALPHAD)
#define vSetGDCCAVRA_ALPHAD(ctrlr,ParValue)  (pst_bitGDCCAVRA(ctrlr) -> ALPHAD=(ParValue))
#define biGetGDCCAVRA_WALPHAD(ctrlr) (pst_bitGDCCAVRA(ctrlr) -> WALPHAD)
#define vSetGDCCAVRA_WALPHAD(ctrlr,ParValue)  (pst_bitGDCCAVRA(ctrlr) -> WALPHAD=(ParValue))

/* Half-word struct access LL */ 
#define vSetGDCCAVRALL(ctrlr,ParValue) (pst_u16GDCCAVRA(ctrlr) -> u16LL = (ParValue))
#define u16GetGDCCAVRALL(ctrlr) (pst_u16GDCCAVRA(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetGDCCAVRALH(ctrlr,ParValue) (pst_u16GDCCAVRA(ctrlr) -> u16LH = (ParValue))
#define u16GetGDCCAVRALH(ctrlr) (pst_u16GDCCAVRA(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetGDCCAVRAHL(ctrlr,ParValue) (pst_u16GDCCAVRA(ctrlr) -> u16HL = (ParValue))
#define u16GetGDCCAVRAHL(ctrlr) (pst_u16GDCCAVRA(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetGDCCAVRAHH(ctrlr,ParValue) (pst_u16GDCCAVRA(ctrlr) -> u16HH = (ParValue))
#define u16GetGDCCAVRAHH(ctrlr) (pst_u16GDCCAVRA(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetGDCCAVRAL(ctrlr,ParValue) (pst_u32GDCCAVRA(ctrlr) -> u32L= (ParValue))
#define u32GetGDCCAVRAL(ctrlr) (pst_u32GDCCAVRA(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetGDCCAVRAH(ctrlr,ParValue) (pst_u32GDCCAVRA(ctrlr) -> u32H = (ParValue))
#define u32GetGDCCAVRAH(ctrlr) (pst_u32GDCCAVRA(ctrlr) -> u32H)

/* Long  Word access */ 
#define vSetGDCCAVRA(ctrlr,ParValue)  (*pu64GDCCAVRA(ctrlr) = (ParValue))
#define u64GetGDCCAVRA(ctrlr)  (*pu64GDCCAVRA(ctrlr) )

     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCCAVRB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02108                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCCAVRB_REG__       0xC0C02108U
#else
#define GDCCAVRB_REG__ ((uint32_t) GDCCAVRB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   ALPHAE	:8; 	 /* 0..7  bit(s) R/W */
  uint16_t   WALPHAE	:8; 	 /* 8..15  bit(s) R/W */                    
} GDCCAVRB_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GDCCAVRB_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GDCCAVRB_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCCAVRB(ctrlr)     ((volatile GDCCAVRB_bit_view_st *)\
(GDCCAVRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCCAVRB(ctrlr)     ((volatile GDCCAVRB_byte_view_st *)\
(GDCCAVRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD */
#define pu16GDCCAVRB(ctrlr)     ((volatile u16GDCCAVRB_halfword_view *)\
(GDCCAVRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCCAVRB(ctrlr)     ((volatile GDCCAVRB_bit_view_st *) &u32GDCCAVRB_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCCAVRB(ctrlr)     ((volatile GDCCAVRB_byte_view_st *) &u32GDCCAVRB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD */
#define pu16GDCCAVRB(ctrlr)     ((volatile u16GDCCAVRB_halfword_view *) &u32GDCCAVRB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCCAVRB_ALPHAE(ctrlr) (pst_bitGDCCAVRB(ctrlr) -> ALPHAE)
#define vSetGDCCAVRB_ALPHAE(ctrlr,ParValue)  (pst_bitGDCCAVRB(ctrlr) -> ALPHAE=(ParValue))
#define biGetGDCCAVRB_WALPHAE(ctrlr) (pst_bitGDCCAVRB(ctrlr) -> WALPHAE)
#define vSetGDCCAVRB_WALPHAE(ctrlr,ParValue)  (pst_bitGDCCAVRB(ctrlr) -> WALPHAE=(ParValue))
            
/* L-struct byte access */
#define vSetGDCCAVRBL(ctrlr,ParValue) (pst_u8GDCCAVRB(ctrlr) -> u8L = (ParValue))
#define u8GetGDCCAVRBL(ctrlr) (pst_u8GDCCAVRB(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGDCCAVRBH(ctrlr,ParValue) (pst_u8GDCCAVRB(ctrlr) -> u8H = (ParValue))
#define u8GetGDCCAVRBH(ctrlr) (pst_u8GDCCAVRB(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGDCCAVRB(ctrlr,ParValue) (*pu16GDCCAVRB(ctrlr)  = (ParValue))
#define u16GetGDCCAVRB(ctrlr) (*pu16GDCCAVRB(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCHSR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02110                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC

#define GDCHSR_REG__       0xC0C02110U
#else
#define GDCHSR_REG__ ((uint32_t) GDCHSR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   HCR	:13; 	 /* 0..12  bit(s) R/W */
  uint32_t   	:3; 	 /* 13..15  bit(s) R */
  uint32_t   HSPWR	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   	:8; 	 /* 24..63  bit(s) R */                    
} GDCHSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCHSR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCHSR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCHSR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCHSR(ctrlr)     ((volatile GDCHSR_bit_view_st *)\
(GDCHSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCHSR(ctrlr)     ((volatile GDCHSR_byte_view_st *)\
(GDCHSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCHSR(ctrlr)     ((volatile GDCHSR_halfword_view_st *)\
(GDCHSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCHSR(ctrlr)     ((volatile u32GDCHSR_word_view *)\
(GDCHSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCHSR(ctrlr)     ((volatile GDCHSR_bit_view_st *) &u32GDCHSR_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCHSR(ctrlr)     ((volatile GDCHSR_byte_view_st *) &u32GDCHSR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCHSR(ctrlr)     ((volatile GDCHSR_halfword_view_st *) &u32GDCHSR_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCHSR(ctrlr)     ((volatile u32GDCHSR_word_view *) &u32GDCHSR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCHSR_HCR(ctrlr) (pst_bitGDCHSR(ctrlr) -> HCR)
#define vSetGDCHSR_HCR(ctrlr,ParValue)  (pst_bitGDCHSR(ctrlr) -> HCR=(ParValue))
#define biGetGDCHSR_HSPWR(ctrlr) (pst_bitGDCHSR(ctrlr) -> HSPWR)
#define vSetGDCHSR_HSPWR(ctrlr,ParValue)  (pst_bitGDCHSR(ctrlr) -> HSPWR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCHSRLL(ctrlr,ParValue) (pst_u8GDCHSR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCHSRLL(ctrlr) (pst_u8GDCHSR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCHSRLH(ctrlr,ParValue) (pst_u8GDCHSR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCHSRLH(ctrlr) (pst_u8GDCHSR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCHSRHL(ctrlr,ParValue) (pst_u8GDCHSR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCHSRHL(ctrlr) (pst_u8GDCHSR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCHSRHH(ctrlr,ParValue) (pst_u8GDCHSR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCHSRHH(ctrlr) (pst_u8GDCHSR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCHSRL(ctrlr,ParValue) (pst_u16GDCHSR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCHSRL(ctrlr) (pst_u16GDCHSR(ctrlr) -> u16L)
#define vSetGDCHSRH(ctrlr,ParValue) (pst_u16GDCHSR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCHSRH(ctrlr) (pst_u16GDCHSR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCHSR(ctrlr,ParValue)  (*pu32GDCHSR(ctrlr) = (ParValue))
#define u32GetGDCHSR(ctrlr)  (*pu32GDCHSR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCVSR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02118                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCVSR_REG__       0xC0C02118U
#else
#define GDCVSR_REG__ ((uint32_t) GDCVSR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   VCR	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   VSPWR	:8; 	 /* 16..23  bit(s) R/W */
  uint32_t   RSRVD24	:2; 	 /* 24..25  bit(s) R/W */ 
  uint32_t   	:6; 	 /* 26..63  bit(s) R */                    
} GDCVSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCVSR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCVSR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCVSR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCVSR(ctrlr)     ((volatile GDCVSR_bit_view_st *)\
(GDCVSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCVSR(ctrlr)     ((volatile GDCVSR_byte_view_st *)\
(GDCVSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCVSR(ctrlr)     ((volatile GDCVSR_halfword_view_st *)\
(GDCVSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCVSR(ctrlr)     ((volatile u32GDCVSR_word_view *)\
(GDCVSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCVSR(ctrlr)     ((volatile GDCVSR_bit_view_st *) &u32GDCVSR_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCVSR(ctrlr)     ((volatile GDCVSR_byte_view_st *) &u32GDCVSR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCVSR(ctrlr)     ((volatile GDCVSR_halfword_view_st *) &u32GDCVSR_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCVSR(ctrlr)     ((volatile u32GDCVSR_word_view *) &u32GDCVSR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCVSR_VCR(ctrlr) (pst_bitGDCVSR(ctrlr) -> VCR)
#define vSetGDCVSR_VCR(ctrlr,ParValue)  (pst_bitGDCVSR(ctrlr) -> VCR=(ParValue))
#define biGetGDCVSR_VSPWR(ctrlr) (pst_bitGDCVSR(ctrlr) -> VSPWR)
#define vSetGDCVSR_VSPWR(ctrlr,ParValue)  (pst_bitGDCVSR(ctrlr) -> VSPWR=(ParValue))
#define biGetGDCVSR_RSRVD24(ctrlr) (pst_bitGDCVSR(ctrlr) -> RSRVD24)
#define vSetGDCVSR_RSRVD24(ctrlr,ParValue)  (pst_bitGDCVSR(ctrlr) -> RSRVD24=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCVSRLL(ctrlr,ParValue) (pst_u8GDCVSR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCVSRLL(ctrlr) (pst_u8GDCVSR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCVSRLH(ctrlr,ParValue) (pst_u8GDCVSR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCVSRLH(ctrlr) (pst_u8GDCVSR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCVSRHL(ctrlr,ParValue) (pst_u8GDCVSR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCVSRHL(ctrlr) (pst_u8GDCVSR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCVSRHH(ctrlr,ParValue) (pst_u8GDCVSR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCVSRHH(ctrlr) (pst_u8GDCVSR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCVSRL(ctrlr,ParValue) (pst_u16GDCVSR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCVSRL(ctrlr) (pst_u16GDCVSR(ctrlr) -> u16L)
#define vSetGDCVSRH(ctrlr,ParValue) (pst_u16GDCVSR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCVSRH(ctrlr) (pst_u16GDCVSR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCVSR(ctrlr,ParValue)  (*pu32GDCVSR(ctrlr) = (ParValue))
#define u32GetGDCVSR(ctrlr)  (*pu32GDCVSR(ctrlr) )
                
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCCBAR0                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02128                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCCBAR0_REG__       0xC0C02128U
#else
#define GDCCBAR0_REG__ ((uint32_t) GDCCBAR0_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   CBAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCCBAR0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCCBAR0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCCBAR0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCCBAR0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCCBAR0(ctrlr)     ((volatile GDCCBAR0_bit_view_st *)\
(GDCCBAR0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCCBAR0(ctrlr)     ((volatile GDCCBAR0_byte_view_st *)\
(GDCCBAR0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCCBAR0(ctrlr)     ((volatile GDCCBAR0_halfword_view_st *)\
(GDCCBAR0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCCBAR0(ctrlr)     ((volatile u32GDCCBAR0_word_view *)\
(GDCCBAR0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCCBAR0(ctrlr)     ((volatile GDCCBAR0_bit_view_st *) &u32GDCCBAR0_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCCBAR0(ctrlr)     ((volatile GDCCBAR0_byte_view_st *) &u32GDCCBAR0_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCCBAR0(ctrlr)     ((volatile GDCCBAR0_halfword_view_st *) &u32GDCCBAR0_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCCBAR0(ctrlr)     ((volatile u32GDCCBAR0_word_view *) &u32GDCCBAR0_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCCBAR0_CBAR(ctrlr) (pst_bitGDCCBAR0(ctrlr) -> CBAR)
#define vSetGDCCBAR0_CBAR(ctrlr,ParValue)  (pst_bitGDCCBAR0(ctrlr) -> CBAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCCBAR0LL(ctrlr,ParValue) (pst_u8GDCCBAR0(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCCBAR0LL(ctrlr) (pst_u8GDCCBAR0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCCBAR0LH(ctrlr,ParValue) (pst_u8GDCCBAR0(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCCBAR0LH(ctrlr) (pst_u8GDCCBAR0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCCBAR0HL(ctrlr,ParValue) (pst_u8GDCCBAR0(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCCBAR0HL(ctrlr) (pst_u8GDCCBAR0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCCBAR0HH(ctrlr,ParValue) (pst_u8GDCCBAR0(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCCBAR0HH(ctrlr) (pst_u8GDCCBAR0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCCBAR0L(ctrlr,ParValue) (pst_u16GDCCBAR0(ctrlr) -> u16L = (ParValue))
#define u16GetGDCCBAR0L(ctrlr) (pst_u16GDCCBAR0(ctrlr) -> u16L)
#define vSetGDCCBAR0H(ctrlr,ParValue) (pst_u16GDCCBAR0(ctrlr) -> u16H = (ParValue))
#define u16GetGDCCBAR0H(ctrlr) (pst_u16GDCCBAR0(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCCBAR0(ctrlr,ParValue)  (*pu32GDCCBAR0(ctrlr) = (ParValue))
#define u32GetGDCCBAR0(ctrlr)  (*pu32GDCCBAR0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCCBAR1                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02130                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCCBAR1_REG__       0xC0C02130U
#else
#define GDCCBAR1_REG__ ((uint32_t) GDCCBAR1_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   CBAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCCBAR1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCCBAR1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCCBAR1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCCBAR1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCCBAR1(ctrlr)     ((volatile GDCCBAR1_bit_view_st *)\
(GDCCBAR1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCCBAR1(ctrlr)     ((volatile GDCCBAR1_byte_view_st *)\
(GDCCBAR1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCCBAR1(ctrlr)     ((volatile GDCCBAR1_halfword_view_st *)\
(GDCCBAR1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCCBAR1(ctrlr)     ((volatile u32GDCCBAR1_word_view *)\
(GDCCBAR1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCCBAR1(ctrlr)     ((volatile GDCCBAR1_bit_view_st *) &u32GDCCBAR1_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCCBAR1(ctrlr)     ((volatile GDCCBAR1_byte_view_st *) &u32GDCCBAR1_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCCBAR1(ctrlr)     ((volatile GDCCBAR1_halfword_view_st *) &u32GDCCBAR1_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCCBAR1(ctrlr)     ((volatile u32GDCCBAR1_word_view *) &u32GDCCBAR1_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCCBAR1_CBAR(ctrlr) (pst_bitGDCCBAR1(ctrlr) -> CBAR)
#define vSetGDCCBAR1_CBAR(ctrlr,ParValue)  (pst_bitGDCCBAR1(ctrlr) -> CBAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCCBAR1LL(ctrlr,ParValue) (pst_u8GDCCBAR1(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCCBAR1LL(ctrlr) (pst_u8GDCCBAR1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCCBAR1LH(ctrlr,ParValue) (pst_u8GDCCBAR1(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCCBAR1LH(ctrlr) (pst_u8GDCCBAR1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCCBAR1HL(ctrlr,ParValue) (pst_u8GDCCBAR1(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCCBAR1HL(ctrlr) (pst_u8GDCCBAR1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCCBAR1HH(ctrlr,ParValue) (pst_u8GDCCBAR1(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCCBAR1HH(ctrlr) (pst_u8GDCCBAR1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCCBAR1L(ctrlr,ParValue) (pst_u16GDCCBAR1(ctrlr) -> u16L = (ParValue))
#define u16GetGDCCBAR1L(ctrlr) (pst_u16GDCCBAR1(ctrlr) -> u16L)
#define vSetGDCCBAR1H(ctrlr,ParValue) (pst_u16GDCCBAR1(ctrlr) -> u16H = (ParValue))
#define u16GetGDCCBAR1H(ctrlr) (pst_u16GDCCBAR1(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCCBAR1(ctrlr,ParValue)  (*pu32GDCCBAR1(ctrlr) = (ParValue))
#define u32GetGDCCBAR1(ctrlr)  (*pu32GDCCBAR1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCCBAR2                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02138                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCCBAR2_REG__       0xC0C02138U
#else
#define GDCCBAR2_REG__ ((uint32_t) GDCCBAR2_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   CBAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCCBAR2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCCBAR2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCCBAR2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCCBAR2_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCCBAR2(ctrlr)     ((volatile GDCCBAR2_bit_view_st *)\
(GDCCBAR2_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCCBAR2(ctrlr)     ((volatile GDCCBAR2_byte_view_st *)\
(GDCCBAR2_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCCBAR2(ctrlr)     ((volatile GDCCBAR2_halfword_view_st *)\
(GDCCBAR2_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCCBAR2(ctrlr)     ((volatile u32GDCCBAR2_word_view *)\
(GDCCBAR2_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCCBAR2(ctrlr)     ((volatile GDCCBAR2_bit_view_st *) &u32GDCCBAR2_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCCBAR2(ctrlr)     ((volatile GDCCBAR2_byte_view_st *) &u32GDCCBAR2_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCCBAR2(ctrlr)     ((volatile GDCCBAR2_halfword_view_st *)GDCCBAR2_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCCBAR2(ctrlr)     ((volatile u32GDCCBAR2_word_view *) &u32GDCCBAR2_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCCBAR2_CBAR(ctrlr) (pst_bitGDCCBAR2(ctrlr) -> CBAR)
#define vSetGDCCBAR2_CBAR(ctrlr,ParValue)  (pst_bitGDCCBAR2(ctrlr) -> CBAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCCBAR2LL(ctrlr,ParValue) (pst_u8GDCCBAR2(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCCBAR2LL(ctrlr) (pst_u8GDCCBAR2(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCCBAR2LH(ctrlr,ParValue) (pst_u8GDCCBAR2(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCCBAR2LH(ctrlr) (pst_u8GDCCBAR2(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCCBAR2HL(ctrlr,ParValue) (pst_u8GDCCBAR2(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCCBAR2HL(ctrlr) (pst_u8GDCCBAR2(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCCBAR2HH(ctrlr,ParValue) (pst_u8GDCCBAR2(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCCBAR2HH(ctrlr) (pst_u8GDCCBAR2(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCCBAR2L(ctrlr,ParValue) (pst_u16GDCCBAR2(ctrlr) -> u16L = (ParValue))
#define u16GetGDCCBAR2L(ctrlr) (pst_u16GDCCBAR2(ctrlr) -> u16L)
#define vSetGDCCBAR2H(ctrlr,ParValue) (pst_u16GDCCBAR2(ctrlr) -> u16H = (ParValue))
#define u16GetGDCCBAR2H(ctrlr) (pst_u16GDCCBAR2(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCCBAR2(ctrlr,ParValue)  (*pu32GDCCBAR2(ctrlr) = (ParValue))
#define u32GetGDCCBAR2(ctrlr)  (*pu32GDCCBAR2(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCINTR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02140                             
*       ACCESS  : 8, 16, 32, 64, BIT-level
*                        
*****************************************************************************/
/*NOTE!: This register is NOT a SHADOW-Register!:*/

/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCINTR_REG__       0xC0C02140U
#else
#define GDCINTR_REG__ ((uint32_t) GDCINTR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   GAPMSK	:1; 	 /* 0..0  bit(s) R/W */
  uint64_t   HSYNCMSK	:1; 	 /* 1..1  bit(s) R/W */
  uint64_t   VSYNCMSK	:1; 	 /* 2..2  bit(s) R/W */
  uint64_t   GBERMSK	:1; 	 /* 3..3  bit(s) R/W */
  uint64_t   GAPINT	:1; 	 /* 4..4  bit(s) R/W1C */
  uint64_t   HSYNCINT	:1; 	 /* 5..5  bit(s) R/W1C */
  uint64_t   VSYNCINT	:1; 	 /* 6..6  bit(s) R/W1C */
  uint64_t   GBERINT	:1; 	 /* 7..7  bit(s) R/W1C */
  uint64_t   IFURMSK	:1; 	 /* 8..8  bit(s) R/W */
  uint64_t   OFURMSK	:1; 	 /* 9..9  bit(s) R/W */
  uint64_t   RSRVD10	:1; 	 /* 10..10  bit(s) R/W */
  uint64_t   GPEMSK	:1; 	 /* 11..11  bit(s) R/W */
  uint64_t   IFURINT	:1; 	 /* 12..12  bit(s) R/W1C */
  uint64_t   OFURINT	:1; 	 /* 13..13  bit(s) R/W1C */
  uint64_t   	:1; 	 /* 14..14  bit(s) R */
  uint64_t   GPEINT	:1; 	 /* 15..15  bit(s) R/W1C */
  uint64_t   LINE	:11; 	 /* 16..26  bit(s) R/W */
  uint64_t   DLEMSK	:1; 	 /* 27..27  bit(s) R/W */
  uint64_t   	:3; 	 /* 28..30  bit(s) R */
  uint64_t   DLEINT	:1; 	 /* 31..31  bit(s) R/W1C */
  uint64_t   APCMSK	:1; 	 /* 32..32  bit(s) R/W */
  uint64_t   APEMSK	:1; 	 /* 33..33  bit(s) R/W */
  uint64_t   	:2; 	 /* 34..35  bit(s) R */
  uint64_t   APCINT	:1; 	 /* 36..36  bit(s) R/W1C */
  uint64_t   APEINT	:1; 	 /* 37..37  bit(s) R/W1C */ 
  uint64_t   	:26; 	 /* 38..63  bit(s) R */                    
} GDCINTR_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} GDCINTR_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} GDCINTR_word_view_st;
            
/* LONGWORD View */
typedef uint64_t u64GDCINTR_longword_view;
             


/************************     ACCESS POINTERS     ****************************/

/* Pointer to BIT-struct */
#define pst_bitGDCINTR(ctrlr)     ((volatile GDCINTR_bit_view_st *)\
(GDCINTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16GDCINTR(ctrlr)     ((volatile GDCINTR_halfword_view_st *)\
(GDCINTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32GDCINTR(ctrlr)   ((volatile GDCINTR_word_view_st *) \
(GDCINTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to LONG_WORD  */
#define pu64GDCINTR(ctrlr)    ((volatile u64GDCINTR_longword_view *)\
(GDCINTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))


#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCINTR_GAPMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> GAPMSK)
#define vSetGDCINTR_GAPMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> GAPMSK=(ParValue))
#define biGetGDCINTR_HSYNCMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> HSYNCMSK)
#define vSetGDCINTR_HSYNCMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> HSYNCMSK=(ParValue))
#define biGetGDCINTR_VSYNCMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> VSYNCMSK)
#define vSetGDCINTR_VSYNCMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> VSYNCMSK=(ParValue))
#define biGetGDCINTR_GBERMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> GBERMSK)
#define vSetGDCINTR_GBERMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> GBERMSK=(ParValue))
#define biGetGDCINTR_GAPINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> GAPINT)
#define vClrGDCINTR_GAPINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> GAPINT = (1))
#define biGetGDCINTR_HSYNCINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> HSYNCINT)
#define vClrGDCINTR_HSYNCINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> HSYNCINT = (1))
#define biGetGDCINTR_VSYNCINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> VSYNCINT)
#define vClrGDCINTR_VSYNCINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> VSYNCINT = (1))
#define biGetGDCINTR_GBERINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> GBERINT)
#define vClrGDCINTR_GBERINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> GBERINT = (1))
#define biGetGDCINTR_IFURMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> IFURMSK)
#define vSetGDCINTR_IFURMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> IFURMSK=(ParValue))
#define biGetGDCINTR_OFURMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> OFURMSK)
#define vSetGDCINTR_OFURMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> OFURMSK=(ParValue))
#define biGetGDCINTR_RSRVD10(ctrlr) (pst_bitGDCINTR(ctrlr) -> RSRVD10)
#define vSetGDCINTR_RSRVD10(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> RSRVD10=(ParValue))
#define biGetGDCINTR_GPEMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> GPEMSK)
#define vSetGDCINTR_GPEMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> GPEMSK=(ParValue))
#define biGetGDCINTR_IFURINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> IFURINT)
#define vClrGDCINTR_IFURINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> IFURINT = (1))
#define biGetGDCINTR_OFURINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> OFURINT)
#define vClrGDCINTR_OFURINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> OFURINT = (1))
#define biGetGDCINTR_GPEINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> GPEINT)
#define vClrGDCINTR_GPEINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> GPEINT = (1))
#define biGetGDCINTR_LINE(ctrlr) (pst_bitGDCINTR(ctrlr) -> LINE)
#define vSetGDCINTR_LINE(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> LINE=(ParValue))
#define biGetGDCINTR_DLEMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> DLEMSK)
#define vSetGDCINTR_DLEMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> DLEMSK=(ParValue))
#define biGetGDCINTR_DLEINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> DLEINT)
#define vClrGDCINTR_DLEINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> DLEINT = (1))
#define biGetGDCINTR_APCMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> APCMSK)
#define vSetGDCINTR_APCMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> APCMSK=(ParValue))
#define biGetGDCINTR_APEMSK(ctrlr) (pst_bitGDCINTR(ctrlr) -> APEMSK)
#define vSetGDCINTR_APEMSK(ctrlr,ParValue)  (pst_bitGDCINTR(ctrlr) -> APEMSK=(ParValue))
#define biGetGDCINTR_APCINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> APCINT)
#define vClrGDCINTR_APCINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> APCINT = (1))
#define biGetGDCINTR_APEINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> APEINT)
#define vClrGDCINTR_APEINT(ctrlr) (pst_bitGDCINTR(ctrlr) -> APEINT = (1))

/* Half-word struct access LL */ 
#define vSetGDCINTRLL(ctrlr,ParValue) (pst_u16GDCINTR(ctrlr) -> u16LL = (ParValue))
#define u16GetGDCINTRLL(ctrlr) (pst_u16GDCINTR(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetGDCINTRLH(ctrlr,ParValue) (pst_u16GDCINTR(ctrlr) -> u16LH = (ParValue))
#define u16GetGDCINTRLH(ctrlr) (pst_u16GDCINTR(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetGDCINTRHL(ctrlr,ParValue) (pst_u16GDCINTR(ctrlr) -> u16HL = (ParValue))
#define u16GetGDCINTRHL(ctrlr) (pst_u16GDCINTR(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetGDCINTRHH(ctrlr,ParValue) (pst_u16GDCINTR(ctrlr) -> u16HH = (ParValue))
#define u16GetGDCINTRHH(ctrlr) (pst_u16GDCINTR(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetGDCINTRL(ctrlr,ParValue) (pst_u32GDCINTR(ctrlr) -> u32L= (ParValue))
#define u32GetGDCINTRL(ctrlr) (pst_u32GDCINTR(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetGDCINTRH(ctrlr,ParValue) (pst_u32GDCINTR(ctrlr) -> u32H = (ParValue))
#define u32GetGDCINTRH(ctrlr) (pst_u32GDCINTR(ctrlr) -> u32H)
            
/* Long  Word access */ 
#define vSetGDCINTR(ctrlr,ParValue)  (*pu64GDCINTR(ctrlr) = (ParValue))
#define u64GetGDCINTR(ctrlr)  (*pu64GDCINTR(ctrlr) )
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCPTCR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02148                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCPTCR_REG__       0xC0C02148U
#else
#define GDCPTCR_REG__ ((uint32_t) GDCPTCR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ORGBEN	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   OINVEN	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   ERGBEN	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   EINVEN	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   ALT	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   DCAL	:1; 	 /* 5..5  bit(s) R/W */
  uint32_t   DDAL	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   PPSYNC	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   GPP0EN	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   GPP1EN	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   GPP2EN	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   GPP3EN	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GPP4EN	:1; 	 /* 12..12  bit(s) R/W */
  uint32_t   GPP5EN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   GPP6EN	:1; 	 /* 14..14  bit(s) R/W */
  uint32_t   GPP7EN	:1; 	 /* 15..15  bit(s) R/W */
  uint32_t   GPP8EN	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   GPP9EN	:1; 	 /* 17..17  bit(s) R/W */
  uint32_t   GPP10EN	:1; 	 /* 18..18  bit(s) R/W */
  uint32_t   GPP11EN	:1; 	 /* 19..19  bit(s) R/W */
  uint32_t   RSPUP	:1; 	 /* 20..20  bit(s) R */
  uint32_t   RSDRDY	:1; 	 /* 21..21  bit(s) R */
  uint32_t   RSDSEN	:1; 	 /* 22..22  bit(s) R/W */
  uint32_t   PSMEN	:1; 	 /* 23..23  bit(s) R/W */
  uint32_t   OCMD	:2; 	 /* 24..25  bit(s) R/W */
  uint32_t   PEMD	:2; 	 /* 26..27  bit(s) R/W */
  uint32_t   HIZEN	:1; 	 /* 28..28  bit(s) R/W */
  uint32_t   	:1; 	 /* 29..29  bit(s) R */
  uint32_t   PSYNC	:1; 	 /* 30..30  bit(s) R */
  uint32_t   PTCEN	:1; 	 /* 31..31  bit(s) R */                    
} GDCPTCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCPTCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCPTCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCPTCR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCPTCR(ctrlr)     ((volatile GDCPTCR_bit_view_st *)\
(GDCPTCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCPTCR(ctrlr)     ((volatile GDCPTCR_byte_view_st *)\
(GDCPTCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCPTCR(ctrlr)     ((volatile GDCPTCR_halfword_view_st *)\
(GDCPTCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCPTCR(ctrlr)     ((volatile u32GDCPTCR_word_view *)\
(GDCPTCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else
/* Pointer to BIT-struct of shadow register*/
#define pst_bitGDCPTCR_Direct(ctrlr)     ((volatile GDCPTCR_bit_view_st *)\
(GDCPTCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))


/* Pointer to BIT-struct */
#define pst_bitGDCPTCR(ctrlr)     ((volatile GDCPTCR_bit_view_st *) &u32GDCPTCR_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCPTCR(ctrlr)     ((volatile GDCPTCR_byte_view_st *) &u32GDCPTCR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCPTCR(ctrlr)     ((volatile GDCPTCR_halfword_view_st *) &u32GDCPTCR_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCPTCR(ctrlr)     ((volatile u32GDCPTCR_word_view *) &u32GDCPTCR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCPTCR_ORGBEN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> ORGBEN)
#define vSetGDCPTCR_ORGBEN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> ORGBEN=(ParValue))
#define biGetGDCPTCR_OINVEN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> OINVEN)
#define vSetGDCPTCR_OINVEN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> OINVEN=(ParValue))
#define biGetGDCPTCR_ERGBEN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> ERGBEN)
#define vSetGDCPTCR_ERGBEN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> ERGBEN=(ParValue))
#define biGetGDCPTCR_EINVEN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> EINVEN)
#define vSetGDCPTCR_EINVEN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> EINVEN=(ParValue))
#define biGetGDCPTCR_ALT(ctrlr) (pst_bitGDCPTCR(ctrlr) -> ALT)
#define vSetGDCPTCR_ALT(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> ALT=(ParValue))
#define biGetGDCPTCR_DCAL(ctrlr) (pst_bitGDCPTCR(ctrlr) -> DCAL)
#define vSetGDCPTCR_DCAL(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> DCAL=(ParValue))
#define biGetGDCPTCR_DDAL(ctrlr) (pst_bitGDCPTCR(ctrlr) -> DDAL)
#define vSetGDCPTCR_DDAL(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> DDAL=(ParValue))
#define biGetGDCPTCR_PPSYNC(ctrlr) (pst_bitGDCPTCR(ctrlr) -> PPSYNC)
#define vSetGDCPTCR_PPSYNC(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> PPSYNC=(ParValue))
#define biGetGDCPTCR_GPP0EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP0EN)
#define vSetGDCPTCR_GPP0EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP0EN=(ParValue))
#define biGetGDCPTCR_GPP1EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP1EN)
#define vSetGDCPTCR_GPP1EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP1EN=(ParValue))
#define biGetGDCPTCR_GPP2EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP2EN)
#define vSetGDCPTCR_GPP2EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP2EN=(ParValue))
#define biGetGDCPTCR_GPP3EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP3EN)
#define vSetGDCPTCR_GPP3EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP3EN=(ParValue))
#define biGetGDCPTCR_GPP4EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP4EN)
#define vSetGDCPTCR_GPP4EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP4EN=(ParValue))
#define biGetGDCPTCR_GPP5EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP5EN)
#define vSetGDCPTCR_GPP5EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP5EN=(ParValue))
#define biGetGDCPTCR_GPP6EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP6EN)
#define vSetGDCPTCR_GPP6EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP6EN=(ParValue))
#define biGetGDCPTCR_GPP7EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP7EN)
#define vSetGDCPTCR_GPP7EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP7EN=(ParValue))
#define biGetGDCPTCR_GPP8EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP8EN)
#define vSetGDCPTCR_GPP8EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP8EN=(ParValue))
#define biGetGDCPTCR_GPP9EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP9EN)
#define vSetGDCPTCR_GPP9EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP9EN=(ParValue))
#define biGetGDCPTCR_GPP10EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP10EN)
#define vSetGDCPTCR_GPP10EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP10EN=(ParValue))
#define biGetGDCPTCR_GPP11EN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> GPP11EN)
#define vSetGDCPTCR_GPP11EN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> GPP11EN=(ParValue))            

/**********************************************************************
 ** "Read Only" signals should be read directly fom shadow register  **
 **********************************************************************/
#define biGetGDCPTCR_RSPUP(ctrlr) (pst_bitGDCPTCR_Direct(ctrlr) -> RSPUP)
#define biGetGDCPTCR_RSDRDY(ctrlr) (pst_bitGDCPTCR_Direct(ctrlr) -> RSDRDY)
/**********************************************************************/

#define biGetGDCPTCR_RSDSEN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> RSDSEN)
#define vSetGDCPTCR_RSDSEN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> RSDSEN=(ParValue))
#define biGetGDCPTCR_PSMEN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> PSMEN)
#define vSetGDCPTCR_PSMEN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> PSMEN=(ParValue))
#define biGetGDCPTCR_OCMD(ctrlr) (pst_bitGDCPTCR(ctrlr) -> OCMD)
#define vSetGDCPTCR_OCMD(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> OCMD=(ParValue))
#define biGetGDCPTCR_PEMD(ctrlr) (pst_bitGDCPTCR(ctrlr) -> PEMD)
#define vSetGDCPTCR_PEMD(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> PEMD=(ParValue))
#define biGetGDCPTCR_HIZEN(ctrlr) (pst_bitGDCPTCR(ctrlr) -> HIZEN)
#define vSetGDCPTCR_HIZEN(ctrlr,ParValue)  (pst_bitGDCPTCR(ctrlr) -> HIZEN=(ParValue))            

/**********************************************************************
 ** "Read Only" signals should be read directly fom shadow register  **
 **********************************************************************/
#define biGetGDCPTCR_PSYNC(ctrlr) (pst_bitGDCPTCR_Direct(ctrlr) -> PSYNC)
#define biGetGDCPTCR_PTCEN(ctrlr) (pst_bitGDCPTCR_Direct(ctrlr) -> PTCEN)
/**********************************************************************/

/* LL-struct byte access */
#define vSetGDCPTCRLL(ctrlr,ParValue) (pst_u8GDCPTCR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCPTCRLL(ctrlr) (pst_u8GDCPTCR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCPTCRLH(ctrlr,ParValue) (pst_u8GDCPTCR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCPTCRLH(ctrlr) (pst_u8GDCPTCR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCPTCRHL(ctrlr,ParValue) (pst_u8GDCPTCR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCPTCRHL(ctrlr) (pst_u8GDCPTCR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCPTCRHH(ctrlr,ParValue) (pst_u8GDCPTCR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCPTCRHH(ctrlr) (pst_u8GDCPTCR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCPTCRL(ctrlr,ParValue) (pst_u16GDCPTCR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCPTCRL(ctrlr) (pst_u16GDCPTCR(ctrlr) -> u16L)
#define vSetGDCPTCRH(ctrlr,ParValue) (pst_u16GDCPTCR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCPTCRH(ctrlr) (pst_u16GDCPTCR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCPTCR(ctrlr,ParValue)  (*pu32GDCPTCR(ctrlr) = (ParValue))
#define u32GetGDCPTCR(ctrlr)  (*pu32GDCPTCR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCGPCRA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02150                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCGPCRA_REG__       0xC0C02150U
#else
#define GDCGPCRA_REG__ ((uint32_t) GDCGPCRA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   OUTSEL0	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   CGSEL0	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   TRIG0	:3; 	 /* 4..6  bit(s) R/W */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   OUTSEL1	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   CGSEL1	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   TRIG1	:3; 	 /* 12..14  bit(s) R/W */
  uint32_t   	:1; 	 /* 15..15  bit(s) R */
  uint32_t   OUTSEL2	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   CGSEL2	:1; 	 /* 19..19  bit(s) R/W */
  uint32_t   TRIG2	:3; 	 /* 20..22  bit(s) R/W */
  uint32_t   	:1; 	 /* 23..23  bit(s) R */
  uint32_t   OUTSEL3	:3; 	 /* 24..26  bit(s) R/W */
  uint32_t   CGSEL3	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   TRIG3	:3; 	 /* 28..30  bit(s) R/W */ 
  uint32_t   	:1; 	 /* 31..63  bit(s) R */                    
} GDCGPCRA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCGPCRA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCGPCRA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCGPCRA_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCGPCRA(ctrlr)     ((volatile GDCGPCRA_bit_view_st *)\
(GDCGPCRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCGPCRA(ctrlr)     ((volatile GDCGPCRA_byte_view_st *)\
(GDCGPCRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCGPCRA(ctrlr)     ((volatile GDCGPCRA_halfword_view_st *)\
(GDCGPCRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCGPCRA(ctrlr)     ((volatile u32GDCGPCRA_word_view *)\
(GDCGPCRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCGPCRA(ctrlr)     ((volatile GDCGPCRA_bit_view_st *) &u32GDCGPCRA_REG__Var[(ctrlr)])
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCGPCRA(ctrlr)     ((volatile GDCGPCRA_byte_view_st *) &u32GDCGPCRA_REG__Var[(ctrlr)])
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCGPCRA(ctrlr)     ((volatile GDCGPCRA_halfword_view_st *) &u32GDCGPCRA_REG__Var[(ctrlr)])
            
/* Pointer to WORD  */ 
#define pu32GDCGPCRA(ctrlr)     ((volatile u32GDCGPCRA_word_view *) &u32GDCGPCRA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCGPCRA_OUTSEL0(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> OUTSEL0)
#define vSetGDCGPCRA_OUTSEL0(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> OUTSEL0=(ParValue))
#define biGetGDCGPCRA_CGSEL0(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> CGSEL0)
#define vSetGDCGPCRA_CGSEL0(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> CGSEL0=(ParValue))
#define biGetGDCGPCRA_TRIG0(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> TRIG0)
#define vSetGDCGPCRA_TRIG0(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> TRIG0=(ParValue))
#define biGetGDCGPCRA_OUTSEL1(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> OUTSEL1)
#define vSetGDCGPCRA_OUTSEL1(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> OUTSEL1=(ParValue))
#define biGetGDCGPCRA_CGSEL1(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> CGSEL1)
#define vSetGDCGPCRA_CGSEL1(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> CGSEL1=(ParValue))
#define biGetGDCGPCRA_TRIG1(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> TRIG1)
#define vSetGDCGPCRA_TRIG1(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> TRIG1=(ParValue))
#define biGetGDCGPCRA_OUTSEL2(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> OUTSEL2)
#define vSetGDCGPCRA_OUTSEL2(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> OUTSEL2=(ParValue))
#define biGetGDCGPCRA_CGSEL2(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> CGSEL2)
#define vSetGDCGPCRA_CGSEL2(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> CGSEL2=(ParValue))
#define biGetGDCGPCRA_TRIG2(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> TRIG2)
#define vSetGDCGPCRA_TRIG2(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> TRIG2=(ParValue))
#define biGetGDCGPCRA_OUTSEL3(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> OUTSEL3)
#define vSetGDCGPCRA_OUTSEL3(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> OUTSEL3=(ParValue))
#define biGetGDCGPCRA_CGSEL3(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> CGSEL3)
#define vSetGDCGPCRA_CGSEL3(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> CGSEL3=(ParValue))
#define biGetGDCGPCRA_TRIG3(ctrlr) (pst_bitGDCGPCRA(ctrlr) -> TRIG3)
#define vSetGDCGPCRA_TRIG3(ctrlr,ParValue)  (pst_bitGDCGPCRA(ctrlr) -> TRIG3=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCGPCRALL(ctrlr,ParValue) (pst_u8GDCGPCRA(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCGPCRALL(ctrlr) (pst_u8GDCGPCRA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCGPCRALH(ctrlr,ParValue) (pst_u8GDCGPCRA(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCGPCRALH(ctrlr) (pst_u8GDCGPCRA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCGPCRAHL(ctrlr,ParValue) (pst_u8GDCGPCRA(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCGPCRAHL(ctrlr) (pst_u8GDCGPCRA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCGPCRAHH(ctrlr,ParValue) (pst_u8GDCGPCRA(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCGPCRAHH(ctrlr) (pst_u8GDCGPCRA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCGPCRAL(ctrlr,ParValue) (pst_u16GDCGPCRA(ctrlr) -> u16L = (ParValue))
#define u16GetGDCGPCRAL(ctrlr) (pst_u16GDCGPCRA(ctrlr) -> u16L)
#define vSetGDCGPCRAH(ctrlr,ParValue) (pst_u16GDCGPCRA(ctrlr) -> u16H = (ParValue))
#define u16GetGDCGPCRAH(ctrlr) (pst_u16GDCGPCRA(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCGPCRA(ctrlr,ParValue)  (*pu32GDCGPCRA(ctrlr) = (ParValue))
#define u32GetGDCGPCRA(ctrlr)  (*pu32GDCGPCRA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCGPCRB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02158                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCGPCRB_REG__       0xC0C02158U
#else
#define GDCGPCRB_REG__ ((uint32_t) GDCGPCRB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   OUTSEL4	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   CGSEL4	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   TRIG4	:3; 	 /* 4..6  bit(s) R/W */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   OUTSEL5	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   CGSEL5	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   TRIG5	:3; 	 /* 12..14  bit(s) R/W */
  uint32_t   	:1; 	 /* 15..15  bit(s) R */
  uint32_t   OUTSEL6	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   CGSEL6	:1; 	 /* 19..19  bit(s) R/W */
  uint32_t   TRIG6	:3; 	 /* 20..22  bit(s) R/W */
  uint32_t   	:1; 	 /* 23..23  bit(s) R */
  uint32_t   OUTSEL7	:3; 	 /* 24..26  bit(s) R/W */
  uint32_t   CGSEL7	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   TRIG7	:3; 	 /* 28..30  bit(s) R/W */ 
  uint32_t   	:1; 	 /* 31..63  bit(s) R */                    
} GDCGPCRB_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCGPCRB_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCGPCRB_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCGPCRB_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCGPCRB(ctrlr)     ((volatile GDCGPCRB_bit_view_st *)\
(GDCGPCRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCGPCRB(ctrlr)     ((volatile GDCGPCRB_byte_view_st *)\
(GDCGPCRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCGPCRB(ctrlr)     ((volatile GDCGPCRB_halfword_view_st *)\
(GDCGPCRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCGPCRB(ctrlr)     ((volatile u32GDCGPCRB_word_view *)\
(GDCGPCRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCGPCRB(ctrlr)     ((volatile GDCGPCRB_bit_view_st *) &u32GDCGPCRB_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCGPCRB(ctrlr)     ((volatile GDCGPCRB_byte_view_st *) &u32GDCGPCRB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCGPCRB(ctrlr)     ((volatile GDCGPCRB_halfword_view_st *) &u32GDCGPCRB_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCGPCRB(ctrlr)     ((volatile u32GDCGPCRB_word_view *) &u32GDCGPCRB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCGPCRB_OUTSEL4(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> OUTSEL4)
#define vSetGDCGPCRB_OUTSEL4(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> OUTSEL4=(ParValue))
#define biGetGDCGPCRB_CGSEL4(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> CGSEL4)
#define vSetGDCGPCRB_CGSEL4(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> CGSEL4=(ParValue))
#define biGetGDCGPCRB_TRIG4(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> TRIG4)
#define vSetGDCGPCRB_TRIG4(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> TRIG4=(ParValue))
#define biGetGDCGPCRB_OUTSEL5(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> OUTSEL5)
#define vSetGDCGPCRB_OUTSEL5(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> OUTSEL5=(ParValue))
#define biGetGDCGPCRB_CGSEL5(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> CGSEL5)
#define vSetGDCGPCRB_CGSEL5(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> CGSEL5=(ParValue))
#define biGetGDCGPCRB_TRIG5(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> TRIG5)
#define vSetGDCGPCRB_TRIG5(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> TRIG5=(ParValue))
#define biGetGDCGPCRB_OUTSEL6(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> OUTSEL6)
#define vSetGDCGPCRB_OUTSEL6(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> OUTSEL6=(ParValue))
#define biGetGDCGPCRB_CGSEL6(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> CGSEL6)
#define vSetGDCGPCRB_CGSEL6(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> CGSEL6=(ParValue))
#define biGetGDCGPCRB_TRIG6(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> TRIG6)
#define vSetGDCGPCRB_TRIG6(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> TRIG6=(ParValue))
#define biGetGDCGPCRB_OUTSEL7(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> OUTSEL7)
#define vSetGDCGPCRB_OUTSEL7(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> OUTSEL7=(ParValue))
#define biGetGDCGPCRB_CGSEL7(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> CGSEL7)
#define vSetGDCGPCRB_CGSEL7(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> CGSEL7=(ParValue))
#define biGetGDCGPCRB_TRIG7(ctrlr) (pst_bitGDCGPCRB(ctrlr) -> TRIG7)
#define vSetGDCGPCRB_TRIG7(ctrlr,ParValue)  (pst_bitGDCGPCRB(ctrlr) -> TRIG7=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCGPCRBLL(ctrlr,ParValue) (pst_u8GDCGPCRB(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCGPCRBLL(ctrlr) (pst_u8GDCGPCRB(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCGPCRBLH(ctrlr,ParValue) (pst_u8GDCGPCRB(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCGPCRBLH(ctrlr) (pst_u8GDCGPCRB(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCGPCRBHL(ctrlr,ParValue) (pst_u8GDCGPCRB(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCGPCRBHL(ctrlr) (pst_u8GDCGPCRB(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCGPCRBHH(ctrlr,ParValue) (pst_u8GDCGPCRB(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCGPCRBHH(ctrlr) (pst_u8GDCGPCRB(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCGPCRBL(ctrlr,ParValue) (pst_u16GDCGPCRB(ctrlr) -> u16L = (ParValue))
#define u16GetGDCGPCRBL(ctrlr) (pst_u16GDCGPCRB(ctrlr) -> u16L)
#define vSetGDCGPCRBH(ctrlr,ParValue) (pst_u16GDCGPCRB(ctrlr) -> u16H = (ParValue))
#define u16GetGDCGPCRBH(ctrlr) (pst_u16GDCGPCRB(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCGPCRB(ctrlr,ParValue)  (*pu32GDCGPCRB(ctrlr) = (ParValue))
#define u32GetGDCGPCRB(ctrlr)  (*pu32GDCGPCRB(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCGPCRC                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02160                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCGPCRC_REG__       0xC0C02160U
#else
#define GDCGPCRC_REG__ ((uint32_t) GDCGPCRC_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   OUTSEL8	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   CGSEL8	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   TRIG8	:3; 	 /* 4..6  bit(s) R/W */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   OUTSEL9	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   CGSEL9	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   TRIG9	:3; 	 /* 12..14  bit(s) R/W */
  uint32_t   	:1; 	 /* 15..15  bit(s) R */
  uint32_t   OUTSEL10	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   CGSEL10	:1; 	 /* 19..19  bit(s) R/W */
  uint32_t   TRIG10	:3; 	 /* 20..22  bit(s) R/W */
  uint32_t   	:1; 	 /* 23..23  bit(s) R */
  uint32_t   OUTSEL11	:3; 	 /* 24..26  bit(s) R/W */
  uint32_t   CGSEL11	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   TRIG11	:3; 	 /* 28..30  bit(s) R/W */ 
  uint32_t   	:1; 	 /* 31..63  bit(s) R */                    
} GDCGPCRC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCGPCRC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCGPCRC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCGPCRC_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCGPCRC(ctrlr)     ((volatile GDCGPCRC_bit_view_st *)\
(GDCGPCRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCGPCRC(ctrlr)     ((volatile GDCGPCRC_byte_view_st *)\
(GDCGPCRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCGPCRC(ctrlr)     ((volatile GDCGPCRC_halfword_view_st *)\
(GDCGPCRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCGPCRC(ctrlr)     ((volatile u32GDCGPCRC_word_view *)\
(GDCGPCRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCGPCRC(ctrlr)     ((volatile GDCGPCRC_bit_view_st *) &u32GDCGPCRC_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCGPCRC(ctrlr)     ((volatile GDCGPCRC_byte_view_st *) &u32GDCGPCRC_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCGPCRC(ctrlr)     ((volatile GDCGPCRC_halfword_view_st *) &u32GDCGPCRC_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCGPCRC(ctrlr)     ((volatile u32GDCGPCRC_word_view *) &u32GDCGPCRC_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCGPCRC_OUTSEL8(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> OUTSEL8)
#define vSetGDCGPCRC_OUTSEL8(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> OUTSEL8=(ParValue))
#define biGetGDCGPCRC_CGSEL8(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> CGSEL8)
#define vSetGDCGPCRC_CGSEL8(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> CGSEL8=(ParValue))
#define biGetGDCGPCRC_TRIG8(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> TRIG8)
#define vSetGDCGPCRC_TRIG8(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> TRIG8=(ParValue))
#define biGetGDCGPCRC_OUTSEL9(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> OUTSEL9)
#define vSetGDCGPCRC_OUTSEL9(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> OUTSEL9=(ParValue))
#define biGetGDCGPCRC_CGSEL9(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> CGSEL9)
#define vSetGDCGPCRC_CGSEL9(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> CGSEL9=(ParValue))
#define biGetGDCGPCRC_TRIG9(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> TRIG9)
#define vSetGDCGPCRC_TRIG9(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> TRIG9=(ParValue))
#define biGetGDCGPCRC_OUTSEL10(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> OUTSEL10)
#define vSetGDCGPCRC_OUTSEL10(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> OUTSEL10=(ParValue))
#define biGetGDCGPCRC_CGSEL10(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> CGSEL10)
#define vSetGDCGPCRC_CGSEL10(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> CGSEL10=(ParValue))
#define biGetGDCGPCRC_TRIG10(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> TRIG10)
#define vSetGDCGPCRC_TRIG10(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> TRIG10=(ParValue))
#define biGetGDCGPCRC_OUTSEL11(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> OUTSEL11)
#define vSetGDCGPCRC_OUTSEL11(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> OUTSEL11=(ParValue))
#define biGetGDCGPCRC_CGSEL11(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> CGSEL11)
#define vSetGDCGPCRC_CGSEL11(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> CGSEL11=(ParValue))
#define biGetGDCGPCRC_TRIG11(ctrlr) (pst_bitGDCGPCRC(ctrlr) -> TRIG11)
#define vSetGDCGPCRC_TRIG11(ctrlr,ParValue)  (pst_bitGDCGPCRC(ctrlr) -> TRIG11=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCGPCRCLL(ctrlr,ParValue) (pst_u8GDCGPCRC(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCGPCRCLL(ctrlr) (pst_u8GDCGPCRC(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCGPCRCLH(ctrlr,ParValue) (pst_u8GDCGPCRC(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCGPCRCLH(ctrlr) (pst_u8GDCGPCRC(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCGPCRCHL(ctrlr,ParValue) (pst_u8GDCGPCRC(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCGPCRCHL(ctrlr) (pst_u8GDCGPCRC(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCGPCRCHH(ctrlr,ParValue) (pst_u8GDCGPCRC(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCGPCRCHH(ctrlr) (pst_u8GDCGPCRC(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCGPCRCL(ctrlr,ParValue) (pst_u16GDCGPCRC(ctrlr) -> u16L = (ParValue))
#define u16GetGDCGPCRCL(ctrlr) (pst_u16GDCGPCRC(ctrlr) -> u16L)
#define vSetGDCGPCRCH(ctrlr,ParValue) (pst_u16GDCGPCRC(ctrlr) -> u16H = (ParValue))
#define u16GetGDCGPCRCH(ctrlr) (pst_u16GDCGPCRC(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCGPCRC(ctrlr,ParValue)  (*pu32GDCGPCRC(ctrlr) = (ParValue))
#define u32GetGDCGPCRC(ctrlr)  (*pu32GDCGPCRC(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP0GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02168                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP0GAR_REG__       0xC0C02168U
#else
#define GDCP0GAR_REG__ ((uint32_t) GDCP0GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP0GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP0GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP0GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP0GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP0GAR(ctrlr)     ((volatile GDCP0GAR_bit_view_st *)\
(GDCP0GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP0GAR(ctrlr)     ((volatile GDCP0GAR_byte_view_st *)\
(GDCP0GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP0GAR(ctrlr)     ((volatile GDCP0GAR_halfword_view_st *)\
(GDCP0GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP0GAR(ctrlr)     ((volatile u32GDCP0GAR_word_view *)\
(GDCP0GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP0GAR(ctrlr)     ((volatile GDCP0GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][0])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP0GAR(ctrlr)     ((volatile GDCP0GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][0])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP0GAR(ctrlr)     ((volatile GDCP0GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][0])

/* Pointer to WORD  */ 
#define pu32GDCP0GAR(ctrlr)     ((volatile u32GDCP0GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][0])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP0GAR_GAWID(ctrlr) (pst_bitGDCP0GAR(ctrlr) -> GAWID)
#define vSetGDCP0GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP0GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP0GAR_GAINV(ctrlr) (pst_bitGDCP0GAR(ctrlr) -> GAINV)
#define vSetGDCP0GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP0GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP0GAR_GADIV(ctrlr) (pst_bitGDCP0GAR(ctrlr) -> GADIV)
#define vSetGDCP0GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP0GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP0GAR_GADEL(ctrlr) (pst_bitGDCP0GAR(ctrlr) -> GADEL)
#define vSetGDCP0GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP0GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP0GAR_GABYP(ctrlr) (pst_bitGDCP0GAR(ctrlr) -> GABYP)
#define vSetGDCP0GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP0GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP0GAR_GAINSEL(ctrlr) (pst_bitGDCP0GAR(ctrlr) -> GAINSEL)
#define vSetGDCP0GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP0GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP0GAR_GALVL(ctrlr) (pst_bitGDCP0GAR(ctrlr) -> GALVL)
#define vSetGDCP0GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP0GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP0GARLL(ctrlr,ParValue) (pst_u8GDCP0GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP0GARLL(ctrlr) (pst_u8GDCP0GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP0GARLH(ctrlr,ParValue) (pst_u8GDCP0GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP0GARLH(ctrlr) (pst_u8GDCP0GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP0GARHL(ctrlr,ParValue) (pst_u8GDCP0GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP0GARHL(ctrlr) (pst_u8GDCP0GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP0GARHH(ctrlr,ParValue) (pst_u8GDCP0GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP0GARHH(ctrlr) (pst_u8GDCP0GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP0GARL(ctrlr,ParValue) (pst_u16GDCP0GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP0GARL(ctrlr) (pst_u16GDCP0GAR(ctrlr) -> u16L)
#define vSetGDCP0GARH(ctrlr,ParValue) (pst_u16GDCP0GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP0GARH(ctrlr) (pst_u16GDCP0GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP0GAR(ctrlr,ParValue)  (*pu32GDCP0GAR(ctrlr) = (ParValue))
#define u32GetGDCP0GAR(ctrlr)  (*pu32GDCP0GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP1GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02170                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP1GAR_REG__       0xC0C02170U
#else
#define GDCP1GAR_REG__ ((uint32_t) GDCP1GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP1GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP1GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP1GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP1GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP1GAR(ctrlr)     ((volatile GDCP1GAR_bit_view_st *)\
(GDCP1GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP1GAR(ctrlr)     ((volatile GDCP1GAR_byte_view_st *)\
(GDCP1GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP1GAR(ctrlr)     ((volatile GDCP1GAR_halfword_view_st *)\
(GDCP1GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP1GAR(ctrlr)     ((volatile u32GDCP1GAR_word_view *)\
(GDCP1GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP1GAR(ctrlr)     ((volatile GDCP1GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][1])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP1GAR(ctrlr)     ((volatile GDCP1GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][1])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP1GAR(ctrlr)     ((volatile GDCP1GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][1])

/* Pointer to WORD  */ 
#define pu32GDCP1GAR(ctrlr)     ((volatile u32GDCP1GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][1])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP1GAR_GAWID(ctrlr) (pst_bitGDCP1GAR(ctrlr) -> GAWID)
#define vSetGDCP1GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP1GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP1GAR_GAINV(ctrlr) (pst_bitGDCP1GAR(ctrlr) -> GAINV)
#define vSetGDCP1GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP1GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP1GAR_GADIV(ctrlr) (pst_bitGDCP1GAR(ctrlr) -> GADIV)
#define vSetGDCP1GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP1GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP1GAR_GADEL(ctrlr) (pst_bitGDCP1GAR(ctrlr) -> GADEL)
#define vSetGDCP1GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP1GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP1GAR_GABYP(ctrlr) (pst_bitGDCP1GAR(ctrlr) -> GABYP)
#define vSetGDCP1GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP1GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP1GAR_GAINSEL(ctrlr) (pst_bitGDCP1GAR(ctrlr) -> GAINSEL)
#define vSetGDCP1GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP1GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP1GAR_GALVL(ctrlr) (pst_bitGDCP1GAR(ctrlr) -> GALVL)
#define vSetGDCP1GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP1GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP1GARLL(ctrlr,ParValue) (pst_u8GDCP1GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP1GARLL(ctrlr) (pst_u8GDCP1GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP1GARLH(ctrlr,ParValue) (pst_u8GDCP1GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP1GARLH(ctrlr) (pst_u8GDCP1GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP1GARHL(ctrlr,ParValue) (pst_u8GDCP1GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP1GARHL(ctrlr) (pst_u8GDCP1GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP1GARHH(ctrlr,ParValue) (pst_u8GDCP1GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP1GARHH(ctrlr) (pst_u8GDCP1GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP1GARL(ctrlr,ParValue) (pst_u16GDCP1GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP1GARL(ctrlr) (pst_u16GDCP1GAR(ctrlr) -> u16L)
#define vSetGDCP1GARH(ctrlr,ParValue) (pst_u16GDCP1GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP1GARH(ctrlr) (pst_u16GDCP1GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP1GAR(ctrlr,ParValue)  (*pu32GDCP1GAR(ctrlr) = (ParValue))
#define u32GetGDCP1GAR(ctrlr)  (*pu32GDCP1GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP2GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02178                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP2GAR_REG__       0xC0C02178U
#else
#define GDCP2GAR_REG__ ((uint32_t) GDCP2GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP2GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP2GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP2GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP2GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP2GAR(ctrlr)     ((volatile GDCP2GAR_bit_view_st *)\
(GDCP2GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP2GAR(ctrlr)     ((volatile GDCP2GAR_byte_view_st *)\
(GDCP2GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP2GAR(ctrlr)     ((volatile GDCP2GAR_halfword_view_st *)\
(GDCP2GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP2GAR(ctrlr)     ((volatile u32GDCP2GAR_word_view *)\
(GDCP2GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP2GAR(ctrlr)     ((volatile GDCP2GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][2])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP2GAR(ctrlr)     ((volatile GDCP2GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][2])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP2GAR(ctrlr)     ((volatile GDCP2GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][2])

/* Pointer to WORD  */ 
#define pu32GDCP2GAR(ctrlr)     ((volatile u32GDCP2GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][2])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP2GAR_GAWID(ctrlr) (pst_bitGDCP2GAR(ctrlr) -> GAWID)
#define vSetGDCP2GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP2GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP2GAR_GAINV(ctrlr) (pst_bitGDCP2GAR(ctrlr) -> GAINV)
#define vSetGDCP2GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP2GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP2GAR_GADIV(ctrlr) (pst_bitGDCP2GAR(ctrlr) -> GADIV)
#define vSetGDCP2GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP2GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP2GAR_GADEL(ctrlr) (pst_bitGDCP2GAR(ctrlr) -> GADEL)
#define vSetGDCP2GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP2GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP2GAR_GABYP(ctrlr) (pst_bitGDCP2GAR(ctrlr) -> GABYP)
#define vSetGDCP2GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP2GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP2GAR_GAINSEL(ctrlr) (pst_bitGDCP2GAR(ctrlr) -> GAINSEL)
#define vSetGDCP2GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP2GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP2GAR_GALVL(ctrlr) (pst_bitGDCP2GAR(ctrlr) -> GALVL)
#define vSetGDCP2GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP2GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP2GARLL(ctrlr,ParValue) (pst_u8GDCP2GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP2GARLL(ctrlr) (pst_u8GDCP2GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP2GARLH(ctrlr,ParValue) (pst_u8GDCP2GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP2GARLH(ctrlr) (pst_u8GDCP2GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP2GARHL(ctrlr,ParValue) (pst_u8GDCP2GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP2GARHL(ctrlr) (pst_u8GDCP2GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP2GARHH(ctrlr,ParValue) (pst_u8GDCP2GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP2GARHH(ctrlr) (pst_u8GDCP2GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP2GARL(ctrlr,ParValue) (pst_u16GDCP2GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP2GARL(ctrlr) (pst_u16GDCP2GAR(ctrlr) -> u16L)
#define vSetGDCP2GARH(ctrlr,ParValue) (pst_u16GDCP2GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP2GARH(ctrlr) (pst_u16GDCP2GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP2GAR(ctrlr,ParValue)  (*pu32GDCP2GAR(ctrlr) = (ParValue))
#define u32GetGDCP2GAR(ctrlr)  (*pu32GDCP2GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP3GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02180                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP3GAR_REG__       0xC0C02180U
#else
#define GDCP3GAR_REG__ ((uint32_t) GDCP3GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP3GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP3GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP3GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP3GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP3GAR(ctrlr)     ((volatile GDCP3GAR_bit_view_st *)\
(GDCP3GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP3GAR(ctrlr)     ((volatile GDCP3GAR_byte_view_st *)\
(GDCP3GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP3GAR(ctrlr)     ((volatile GDCP3GAR_halfword_view_st *)\
(GDCP3GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP3GAR(ctrlr)     ((volatile u32GDCP3GAR_word_view *)\
(GDCP3GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP3GAR(ctrlr)     ((volatile GDCP3GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][3])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP3GAR(ctrlr)     ((volatile GDCP3GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][3])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP3GAR(ctrlr)     ((volatile GDCP3GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][3])

/* Pointer to WORD  */ 
#define pu32GDCP3GAR(ctrlr)     ((volatile u32GDCP3GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][3])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP3GAR_GAWID(ctrlr) (pst_bitGDCP3GAR(ctrlr) -> GAWID)
#define vSetGDCP3GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP3GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP3GAR_GAINV(ctrlr) (pst_bitGDCP3GAR(ctrlr) -> GAINV)
#define vSetGDCP3GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP3GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP3GAR_GADIV(ctrlr) (pst_bitGDCP3GAR(ctrlr) -> GADIV)
#define vSetGDCP3GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP3GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP3GAR_GADEL(ctrlr) (pst_bitGDCP3GAR(ctrlr) -> GADEL)
#define vSetGDCP3GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP3GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP3GAR_GABYP(ctrlr) (pst_bitGDCP3GAR(ctrlr) -> GABYP)
#define vSetGDCP3GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP3GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP3GAR_GAINSEL(ctrlr) (pst_bitGDCP3GAR(ctrlr) -> GAINSEL)
#define vSetGDCP3GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP3GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP3GAR_GALVL(ctrlr) (pst_bitGDCP3GAR(ctrlr) -> GALVL)
#define vSetGDCP3GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP3GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP3GARLL(ctrlr,ParValue) (pst_u8GDCP3GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP3GARLL(ctrlr) (pst_u8GDCP3GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP3GARLH(ctrlr,ParValue) (pst_u8GDCP3GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP3GARLH(ctrlr) (pst_u8GDCP3GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP3GARHL(ctrlr,ParValue) (pst_u8GDCP3GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP3GARHL(ctrlr) (pst_u8GDCP3GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP3GARHH(ctrlr,ParValue) (pst_u8GDCP3GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP3GARHH(ctrlr) (pst_u8GDCP3GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP3GARL(ctrlr,ParValue) (pst_u16GDCP3GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP3GARL(ctrlr) (pst_u16GDCP3GAR(ctrlr) -> u16L)
#define vSetGDCP3GARH(ctrlr,ParValue) (pst_u16GDCP3GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP3GARH(ctrlr) (pst_u16GDCP3GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP3GAR(ctrlr,ParValue)  (*pu32GDCP3GAR(ctrlr) = (ParValue))
#define u32GetGDCP3GAR(ctrlr)  (*pu32GDCP3GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP4GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02188                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP4GAR_REG__       0xC0C02188U
#else
#define GDCP4GAR_REG__ ((uint32_t) GDCP4GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP4GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP4GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP4GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP4GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP4GAR(ctrlr)     ((volatile GDCP4GAR_bit_view_st *)\
(GDCP4GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP4GAR(ctrlr)     ((volatile GDCP4GAR_byte_view_st *)\
(GDCP4GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP4GAR(ctrlr)     ((volatile GDCP4GAR_halfword_view_st *)\
(GDCP4GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP4GAR(ctrlr)     ((volatile u32GDCP4GAR_word_view *)\
(GDCP4GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP4GAR(ctrlr)     ((volatile GDCP4GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][4])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP4GAR(ctrlr)     ((volatile GDCP4GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][4])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP4GAR(ctrlr)     ((volatile GDCP4GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][4])

/* Pointer to WORD  */ 
#define pu32GDCP4GAR(ctrlr)     ((volatile u32GDCP4GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][4])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP4GAR_GAWID(ctrlr) (pst_bitGDCP4GAR(ctrlr) -> GAWID)
#define vSetGDCP4GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP4GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP4GAR_GAINV(ctrlr) (pst_bitGDCP4GAR(ctrlr) -> GAINV)
#define vSetGDCP4GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP4GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP4GAR_GADIV(ctrlr) (pst_bitGDCP4GAR(ctrlr) -> GADIV)
#define vSetGDCP4GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP4GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP4GAR_GADEL(ctrlr) (pst_bitGDCP4GAR(ctrlr) -> GADEL)
#define vSetGDCP4GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP4GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP4GAR_GABYP(ctrlr) (pst_bitGDCP4GAR(ctrlr) -> GABYP)
#define vSetGDCP4GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP4GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP4GAR_GAINSEL(ctrlr) (pst_bitGDCP4GAR(ctrlr) -> GAINSEL)
#define vSetGDCP4GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP4GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP4GAR_GALVL(ctrlr) (pst_bitGDCP4GAR(ctrlr) -> GALVL)
#define vSetGDCP4GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP4GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP4GARLL(ctrlr,ParValue) (pst_u8GDCP4GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP4GARLL(ctrlr) (pst_u8GDCP4GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP4GARLH(ctrlr,ParValue) (pst_u8GDCP4GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP4GARLH(ctrlr) (pst_u8GDCP4GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP4GARHL(ctrlr,ParValue) (pst_u8GDCP4GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP4GARHL(ctrlr) (pst_u8GDCP4GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP4GARHH(ctrlr,ParValue) (pst_u8GDCP4GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP4GARHH(ctrlr) (pst_u8GDCP4GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP4GARL(ctrlr,ParValue) (pst_u16GDCP4GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP4GARL(ctrlr) (pst_u16GDCP4GAR(ctrlr) -> u16L)
#define vSetGDCP4GARH(ctrlr,ParValue) (pst_u16GDCP4GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP4GARH(ctrlr) (pst_u16GDCP4GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP4GAR(ctrlr,ParValue)  (*pu32GDCP4GAR(ctrlr) = (ParValue))
#define u32GetGDCP4GAR(ctrlr)  (*pu32GDCP4GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP5GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02190                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP5GAR_REG__       0xC0C02190U
#else
#define GDCP5GAR_REG__ ((uint32_t) GDCP5GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP5GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP5GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP5GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP5GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP5GAR(ctrlr)     ((volatile GDCP5GAR_bit_view_st *)\
(GDCP5GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP5GAR(ctrlr)     ((volatile GDCP5GAR_byte_view_st *)\
(GDCP5GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP5GAR(ctrlr)     ((volatile GDCP5GAR_halfword_view_st *)\
(GDCP5GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP5GAR(ctrlr)     ((volatile u32GDCP5GAR_word_view *)\
(GDCP5GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP5GAR(ctrlr)     ((volatile GDCP5GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][5])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP5GAR(ctrlr)     ((volatile GDCP5GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][5])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP5GAR(ctrlr)     ((volatile GDCP5GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][5])

/* Pointer to WORD  */ 
#define pu32GDCP5GAR(ctrlr)     ((volatile u32GDCP5GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][5])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP5GAR_GAWID(ctrlr) (pst_bitGDCP5GAR(ctrlr) -> GAWID)
#define vSetGDCP5GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP5GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP5GAR_GAINV(ctrlr) (pst_bitGDCP5GAR(ctrlr) -> GAINV)
#define vSetGDCP5GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP5GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP5GAR_GADIV(ctrlr) (pst_bitGDCP5GAR(ctrlr) -> GADIV)
#define vSetGDCP5GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP5GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP5GAR_GADEL(ctrlr) (pst_bitGDCP5GAR(ctrlr) -> GADEL)
#define vSetGDCP5GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP5GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP5GAR_GABYP(ctrlr) (pst_bitGDCP5GAR(ctrlr) -> GABYP)
#define vSetGDCP5GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP5GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP5GAR_GAINSEL(ctrlr) (pst_bitGDCP5GAR(ctrlr) -> GAINSEL)
#define vSetGDCP5GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP5GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP5GAR_GALVL(ctrlr) (pst_bitGDCP5GAR(ctrlr) -> GALVL)
#define vSetGDCP5GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP5GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP5GARLL(ctrlr,ParValue) (pst_u8GDCP5GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP5GARLL(ctrlr) (pst_u8GDCP5GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP5GARLH(ctrlr,ParValue) (pst_u8GDCP5GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP5GARLH(ctrlr) (pst_u8GDCP5GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP5GARHL(ctrlr,ParValue) (pst_u8GDCP5GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP5GARHL(ctrlr) (pst_u8GDCP5GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP5GARHH(ctrlr,ParValue) (pst_u8GDCP5GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP5GARHH(ctrlr) (pst_u8GDCP5GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP5GARL(ctrlr,ParValue) (pst_u16GDCP5GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP5GARL(ctrlr) (pst_u16GDCP5GAR(ctrlr) -> u16L)
#define vSetGDCP5GARH(ctrlr,ParValue) (pst_u16GDCP5GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP5GARH(ctrlr) (pst_u16GDCP5GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP5GAR(ctrlr,ParValue)  (*pu32GDCP5GAR(ctrlr) = (ParValue))
#define u32GetGDCP5GAR(ctrlr)  (*pu32GDCP5GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP6GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02198                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP6GAR_REG__       0xC0C02198U
#else
#define GDCP6GAR_REG__ ((uint32_t) GDCP6GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP6GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP6GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP6GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP6GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP6GAR(ctrlr)     ((volatile GDCP6GAR_bit_view_st *)\
(GDCP6GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP6GAR(ctrlr)     ((volatile GDCP6GAR_byte_view_st *)\
(GDCP6GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP6GAR(ctrlr)     ((volatile GDCP6GAR_halfword_view_st *)\
(GDCP6GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP6GAR(ctrlr)     ((volatile u32GDCP6GAR_word_view *)\
(GDCP6GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP6GAR(ctrlr)     ((volatile GDCP6GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][6])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP6GAR(ctrlr)     ((volatile GDCP6GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][6])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP6GAR(ctrlr)     ((volatile GDCP6GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][6])

/* Pointer to WORD  */ 
#define pu32GDCP6GAR(ctrlr)     ((volatile u32GDCP6GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][6])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP6GAR_GAWID(ctrlr) (pst_bitGDCP6GAR(ctrlr) -> GAWID)
#define vSetGDCP6GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP6GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP6GAR_GAINV(ctrlr) (pst_bitGDCP6GAR(ctrlr) -> GAINV)
#define vSetGDCP6GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP6GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP6GAR_GADIV(ctrlr) (pst_bitGDCP6GAR(ctrlr) -> GADIV)
#define vSetGDCP6GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP6GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP6GAR_GADEL(ctrlr) (pst_bitGDCP6GAR(ctrlr) -> GADEL)
#define vSetGDCP6GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP6GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP6GAR_GABYP(ctrlr) (pst_bitGDCP6GAR(ctrlr) -> GABYP)
#define vSetGDCP6GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP6GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP6GAR_GAINSEL(ctrlr) (pst_bitGDCP6GAR(ctrlr) -> GAINSEL)
#define vSetGDCP6GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP6GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP6GAR_GALVL(ctrlr) (pst_bitGDCP6GAR(ctrlr) -> GALVL)
#define vSetGDCP6GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP6GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP6GARLL(ctrlr,ParValue) (pst_u8GDCP6GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP6GARLL(ctrlr) (pst_u8GDCP6GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP6GARLH(ctrlr,ParValue) (pst_u8GDCP6GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP6GARLH(ctrlr) (pst_u8GDCP6GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP6GARHL(ctrlr,ParValue) (pst_u8GDCP6GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP6GARHL(ctrlr) (pst_u8GDCP6GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP6GARHH(ctrlr,ParValue) (pst_u8GDCP6GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP6GARHH(ctrlr) (pst_u8GDCP6GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP6GARL(ctrlr,ParValue) (pst_u16GDCP6GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP6GARL(ctrlr) (pst_u16GDCP6GAR(ctrlr) -> u16L)
#define vSetGDCP6GARH(ctrlr,ParValue) (pst_u16GDCP6GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP6GARH(ctrlr) (pst_u16GDCP6GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP6GAR(ctrlr,ParValue)  (*pu32GDCP6GAR(ctrlr) = (ParValue))
#define u32GetGDCP6GAR(ctrlr)  (*pu32GDCP6GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP7GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021A0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP7GAR_REG__       0xC0C021A0U
#else
#define GDCP7GAR_REG__ ((uint32_t) GDCP7GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP7GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP7GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP7GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP7GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP7GAR(ctrlr)     ((volatile GDCP7GAR_bit_view_st *)\
(GDCP7GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP7GAR(ctrlr)     ((volatile GDCP7GAR_byte_view_st *)\
(GDCP7GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP7GAR(ctrlr)     ((volatile GDCP7GAR_halfword_view_st *)\
(GDCP7GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP7GAR(ctrlr)     ((volatile u32GDCP7GAR_word_view *)\
(GDCP7GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP7GAR(ctrlr)     ((volatile GDCP7GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][7])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP7GAR(ctrlr)     ((volatile GDCP7GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][7])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP7GAR(ctrlr)     ((volatile GDCP7GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][7])

/* Pointer to WORD  */ 
#define pu32GDCP7GAR(ctrlr)     ((volatile u32GDCP7GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][7])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP7GAR_GAWID(ctrlr) (pst_bitGDCP7GAR(ctrlr) -> GAWID)
#define vSetGDCP7GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP7GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP7GAR_GAINV(ctrlr) (pst_bitGDCP7GAR(ctrlr) -> GAINV)
#define vSetGDCP7GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP7GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP7GAR_GADIV(ctrlr) (pst_bitGDCP7GAR(ctrlr) -> GADIV)
#define vSetGDCP7GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP7GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP7GAR_GADEL(ctrlr) (pst_bitGDCP7GAR(ctrlr) -> GADEL)
#define vSetGDCP7GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP7GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP7GAR_GABYP(ctrlr) (pst_bitGDCP7GAR(ctrlr) -> GABYP)
#define vSetGDCP7GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP7GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP7GAR_GAINSEL(ctrlr) (pst_bitGDCP7GAR(ctrlr) -> GAINSEL)
#define vSetGDCP7GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP7GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP7GAR_GALVL(ctrlr) (pst_bitGDCP7GAR(ctrlr) -> GALVL)
#define vSetGDCP7GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP7GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP7GARLL(ctrlr,ParValue) (pst_u8GDCP7GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP7GARLL(ctrlr) (pst_u8GDCP7GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP7GARLH(ctrlr,ParValue) (pst_u8GDCP7GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP7GARLH(ctrlr) (pst_u8GDCP7GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP7GARHL(ctrlr,ParValue) (pst_u8GDCP7GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP7GARHL(ctrlr) (pst_u8GDCP7GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP7GARHH(ctrlr,ParValue) (pst_u8GDCP7GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP7GARHH(ctrlr) (pst_u8GDCP7GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP7GARL(ctrlr,ParValue) (pst_u16GDCP7GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP7GARL(ctrlr) (pst_u16GDCP7GAR(ctrlr) -> u16L)
#define vSetGDCP7GARH(ctrlr,ParValue) (pst_u16GDCP7GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP7GARH(ctrlr) (pst_u16GDCP7GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP7GAR(ctrlr,ParValue)  (*pu32GDCP7GAR(ctrlr) = (ParValue))
#define u32GetGDCP7GAR(ctrlr)  (*pu32GDCP7GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP8GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021A8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP8GAR_REG__       0xC0C021A8U
#else
#define GDCP8GAR_REG__ ((uint32_t) GDCP8GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP8GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP8GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP8GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP8GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP8GAR(ctrlr)     ((volatile GDCP8GAR_bit_view_st *)\
(GDCP8GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP8GAR(ctrlr)     ((volatile GDCP8GAR_byte_view_st *)\
(GDCP8GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP8GAR(ctrlr)     ((volatile GDCP8GAR_halfword_view_st *)\
(GDCP8GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP8GAR(ctrlr)     ((volatile u32GDCP8GAR_word_view *)\
(GDCP8GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP8GAR(ctrlr)     ((volatile GDCP8GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][8])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP8GAR(ctrlr)     ((volatile GDCP8GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][8])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP8GAR(ctrlr)     ((volatile GDCP8GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][8])

/* Pointer to WORD  */ 
#define pu32GDCP8GAR(ctrlr)     ((volatile u32GDCP8GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][8])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP8GAR_GAWID(ctrlr) (pst_bitGDCP8GAR(ctrlr) -> GAWID)
#define vSetGDCP8GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP8GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP8GAR_GAINV(ctrlr) (pst_bitGDCP8GAR(ctrlr) -> GAINV)
#define vSetGDCP8GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP8GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP8GAR_GADIV(ctrlr) (pst_bitGDCP8GAR(ctrlr) -> GADIV)
#define vSetGDCP8GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP8GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP8GAR_GADEL(ctrlr) (pst_bitGDCP8GAR(ctrlr) -> GADEL)
#define vSetGDCP8GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP8GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP8GAR_GABYP(ctrlr) (pst_bitGDCP8GAR(ctrlr) -> GABYP)
#define vSetGDCP8GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP8GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP8GAR_GAINSEL(ctrlr) (pst_bitGDCP8GAR(ctrlr) -> GAINSEL)
#define vSetGDCP8GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP8GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP8GAR_GALVL(ctrlr) (pst_bitGDCP8GAR(ctrlr) -> GALVL)
#define vSetGDCP8GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP8GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP8GARLL(ctrlr,ParValue) (pst_u8GDCP8GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP8GARLL(ctrlr) (pst_u8GDCP8GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP8GARLH(ctrlr,ParValue) (pst_u8GDCP8GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP8GARLH(ctrlr) (pst_u8GDCP8GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP8GARHL(ctrlr,ParValue) (pst_u8GDCP8GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP8GARHL(ctrlr) (pst_u8GDCP8GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP8GARHH(ctrlr,ParValue) (pst_u8GDCP8GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP8GARHH(ctrlr) (pst_u8GDCP8GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP8GARL(ctrlr,ParValue) (pst_u16GDCP8GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP8GARL(ctrlr) (pst_u16GDCP8GAR(ctrlr) -> u16L)
#define vSetGDCP8GARH(ctrlr,ParValue) (pst_u16GDCP8GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP8GARH(ctrlr) (pst_u16GDCP8GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP8GAR(ctrlr,ParValue)  (*pu32GDCP8GAR(ctrlr) = (ParValue))
#define u32GetGDCP8GAR(ctrlr)  (*pu32GDCP8GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP9GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021B0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP9GAR_REG__       0xC0C021B0U
#else
#define GDCP9GAR_REG__ ((uint32_t) GDCP9GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP9GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP9GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP9GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP9GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP9GAR(ctrlr)     ((volatile GDCP9GAR_bit_view_st *)\
(GDCP9GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP9GAR(ctrlr)     ((volatile GDCP9GAR_byte_view_st *)\
(GDCP9GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP9GAR(ctrlr)     ((volatile GDCP9GAR_halfword_view_st *)\
(GDCP9GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP9GAR(ctrlr)     ((volatile u32GDCP9GAR_word_view *)\
(GDCP9GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP9GAR(ctrlr)     ((volatile GDCP9GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][9])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP9GAR(ctrlr)     ((volatile GDCP9GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][9])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP9GAR(ctrlr)     ((volatile GDCP9GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][9])

/* Pointer to WORD  */ 
#define pu32GDCP9GAR(ctrlr)     ((volatile u32GDCP9GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][9])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP9GAR_GAWID(ctrlr) (pst_bitGDCP9GAR(ctrlr) -> GAWID)
#define vSetGDCP9GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP9GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP9GAR_GAINV(ctrlr) (pst_bitGDCP9GAR(ctrlr) -> GAINV)
#define vSetGDCP9GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP9GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP9GAR_GADIV(ctrlr) (pst_bitGDCP9GAR(ctrlr) -> GADIV)
#define vSetGDCP9GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP9GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP9GAR_GADEL(ctrlr) (pst_bitGDCP9GAR(ctrlr) -> GADEL)
#define vSetGDCP9GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP9GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP9GAR_GABYP(ctrlr) (pst_bitGDCP9GAR(ctrlr) -> GABYP)
#define vSetGDCP9GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP9GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP9GAR_GAINSEL(ctrlr) (pst_bitGDCP9GAR(ctrlr) -> GAINSEL)
#define vSetGDCP9GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP9GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP9GAR_GALVL(ctrlr) (pst_bitGDCP9GAR(ctrlr) -> GALVL)
#define vSetGDCP9GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP9GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP9GARLL(ctrlr,ParValue) (pst_u8GDCP9GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP9GARLL(ctrlr) (pst_u8GDCP9GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP9GARLH(ctrlr,ParValue) (pst_u8GDCP9GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP9GARLH(ctrlr) (pst_u8GDCP9GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP9GARHL(ctrlr,ParValue) (pst_u8GDCP9GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP9GARHL(ctrlr) (pst_u8GDCP9GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP9GARHH(ctrlr,ParValue) (pst_u8GDCP9GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP9GARHH(ctrlr) (pst_u8GDCP9GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP9GARL(ctrlr,ParValue) (pst_u16GDCP9GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP9GARL(ctrlr) (pst_u16GDCP9GAR(ctrlr) -> u16L)
#define vSetGDCP9GARH(ctrlr,ParValue) (pst_u16GDCP9GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP9GARH(ctrlr) (pst_u16GDCP9GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP9GAR(ctrlr,ParValue)  (*pu32GDCP9GAR(ctrlr) = (ParValue))
#define u32GetGDCP9GAR(ctrlr)  (*pu32GDCP9GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP10GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021B8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP10GAR_REG__       0xC0C021B8U
#else
#define GDCP10GAR_REG__ ((uint32_t) GDCP10GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP10GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP10GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP10GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP10GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP10GAR(ctrlr)     ((volatile GDCP10GAR_bit_view_st *)\
(GDCP10GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP10GAR(ctrlr)     ((volatile GDCP10GAR_byte_view_st *)\
(GDCP10GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP10GAR(ctrlr)     ((volatile GDCP10GAR_halfword_view_st *)\
(GDCP10GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP10GAR(ctrlr)     ((volatile u32GDCP10GAR_word_view *)\
(GDCP10GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP10GAR(ctrlr)     ((volatile GDCP10GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][10])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP10GAR(ctrlr)     ((volatile GDCP10GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][10])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP10GAR(ctrlr)     ((volatile GDCP10GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][10])

/* Pointer to WORD  */ 
#define pu32GDCP10GAR(ctrlr)     ((volatile u32GDCP10GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][10])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP10GAR_GAWID(ctrlr) (pst_bitGDCP10GAR(ctrlr) -> GAWID)
#define vSetGDCP10GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP10GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP10GAR_GAINV(ctrlr) (pst_bitGDCP10GAR(ctrlr) -> GAINV)
#define vSetGDCP10GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP10GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP10GAR_GADIV(ctrlr) (pst_bitGDCP10GAR(ctrlr) -> GADIV)
#define vSetGDCP10GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP10GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP10GAR_GADEL(ctrlr) (pst_bitGDCP10GAR(ctrlr) -> GADEL)
#define vSetGDCP10GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP10GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP10GAR_GABYP(ctrlr) (pst_bitGDCP10GAR(ctrlr) -> GABYP)
#define vSetGDCP10GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP10GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP10GAR_GAINSEL(ctrlr) (pst_bitGDCP10GAR(ctrlr) -> GAINSEL)
#define vSetGDCP10GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP10GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP10GAR_GALVL(ctrlr) (pst_bitGDCP10GAR(ctrlr) -> GALVL)
#define vSetGDCP10GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP10GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP10GARLL(ctrlr,ParValue) (pst_u8GDCP10GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP10GARLL(ctrlr) (pst_u8GDCP10GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP10GARLH(ctrlr,ParValue) (pst_u8GDCP10GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP10GARLH(ctrlr) (pst_u8GDCP10GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP10GARHL(ctrlr,ParValue) (pst_u8GDCP10GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP10GARHL(ctrlr) (pst_u8GDCP10GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP10GARHH(ctrlr,ParValue) (pst_u8GDCP10GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP10GARHH(ctrlr) (pst_u8GDCP10GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP10GARL(ctrlr,ParValue) (pst_u16GDCP10GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP10GARL(ctrlr) (pst_u16GDCP10GAR(ctrlr) -> u16L)
#define vSetGDCP10GARH(ctrlr,ParValue) (pst_u16GDCP10GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP10GARH(ctrlr) (pst_u16GDCP10GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP10GAR(ctrlr,ParValue)  (*pu32GDCP10GAR(ctrlr) = (ParValue))
#define u32GetGDCP10GAR(ctrlr)  (*pu32GDCP10GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP11GAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021C0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP11GAR_REG__       0xC0C021C0U
#else
#define GDCP11GAR_REG__ ((uint32_t) GDCP11GAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GAWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GAINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GADIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GADEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GABYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GAINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GALVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP11GAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP11GAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP11GAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP11GAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP11GAR(ctrlr)     ((volatile GDCP11GAR_bit_view_st *)\
(GDCP11GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP11GAR(ctrlr)     ((volatile GDCP11GAR_byte_view_st *)\
(GDCP11GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP11GAR(ctrlr)     ((volatile GDCP11GAR_halfword_view_st *)\
(GDCP11GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP11GAR(ctrlr)     ((volatile u32GDCP11GAR_word_view *)\
(GDCP11GAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP11GAR(ctrlr)     ((volatile GDCP11GAR_bit_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][11])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP11GAR(ctrlr)     ((volatile GDCP11GAR_byte_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][11])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP11GAR(ctrlr)     ((volatile GDCP11GAR_halfword_view_st *) &u32GDCPxGAR_REG__Var[(ctrlr)][11])

/* Pointer to WORD  */ 
#define pu32GDCP11GAR(ctrlr)     ((volatile u32GDCP11GAR_word_view *) &u32GDCPxGAR_REG__Var[(ctrlr)][11])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP11GAR_GAWID(ctrlr) (pst_bitGDCP11GAR(ctrlr) -> GAWID)
#define vSetGDCP11GAR_GAWID(ctrlr,ParValue)  (pst_bitGDCP11GAR(ctrlr) -> GAWID=(ParValue))
#define biGetGDCP11GAR_GAINV(ctrlr) (pst_bitGDCP11GAR(ctrlr) -> GAINV)
#define vSetGDCP11GAR_GAINV(ctrlr,ParValue)  (pst_bitGDCP11GAR(ctrlr) -> GAINV=(ParValue))
#define biGetGDCP11GAR_GADIV(ctrlr) (pst_bitGDCP11GAR(ctrlr) -> GADIV)
#define vSetGDCP11GAR_GADIV(ctrlr,ParValue)  (pst_bitGDCP11GAR(ctrlr) -> GADIV=(ParValue))
#define biGetGDCP11GAR_GADEL(ctrlr) (pst_bitGDCP11GAR(ctrlr) -> GADEL)
#define vSetGDCP11GAR_GADEL(ctrlr,ParValue)  (pst_bitGDCP11GAR(ctrlr) -> GADEL=(ParValue))
#define biGetGDCP11GAR_GABYP(ctrlr) (pst_bitGDCP11GAR(ctrlr) -> GABYP)
#define vSetGDCP11GAR_GABYP(ctrlr,ParValue)  (pst_bitGDCP11GAR(ctrlr) -> GABYP=(ParValue))
#define biGetGDCP11GAR_GAINSEL(ctrlr) (pst_bitGDCP11GAR(ctrlr) -> GAINSEL)
#define vSetGDCP11GAR_GAINSEL(ctrlr,ParValue)  (pst_bitGDCP11GAR(ctrlr) -> GAINSEL=(ParValue))
#define biGetGDCP11GAR_GALVL(ctrlr) (pst_bitGDCP11GAR(ctrlr) -> GALVL)
#define vSetGDCP11GAR_GALVL(ctrlr,ParValue)  (pst_bitGDCP11GAR(ctrlr) -> GALVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP11GARLL(ctrlr,ParValue) (pst_u8GDCP11GAR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP11GARLL(ctrlr) (pst_u8GDCP11GAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP11GARLH(ctrlr,ParValue) (pst_u8GDCP11GAR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP11GARLH(ctrlr) (pst_u8GDCP11GAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP11GARHL(ctrlr,ParValue) (pst_u8GDCP11GAR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP11GARHL(ctrlr) (pst_u8GDCP11GAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP11GARHH(ctrlr,ParValue) (pst_u8GDCP11GAR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP11GARHH(ctrlr) (pst_u8GDCP11GAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP11GARL(ctrlr,ParValue) (pst_u16GDCP11GAR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP11GARL(ctrlr) (pst_u16GDCP11GAR(ctrlr) -> u16L)
#define vSetGDCP11GARH(ctrlr,ParValue) (pst_u16GDCP11GAR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP11GARH(ctrlr) (pst_u16GDCP11GAR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP11GAR(ctrlr,ParValue)  (*pu32GDCP11GAR(ctrlr) = (ParValue))
#define u32GetGDCP11GAR(ctrlr)  (*pu32GDCP11GAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP0GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021C8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP0GBR_REG__       0xC0C021C8U
#else
#define GDCP0GBR_REG__ ((uint32_t) GDCP0GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP0GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP0GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP0GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP0GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP0GBR(ctrlr)     ((volatile GDCP0GBR_bit_view_st *)\
(GDCP0GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP0GBR(ctrlr)     ((volatile GDCP0GBR_byte_view_st *)\
(GDCP0GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP0GBR(ctrlr)     ((volatile GDCP0GBR_halfword_view_st *)\
(GDCP0GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP0GBR(ctrlr)     ((volatile u32GDCP0GBR_word_view *)\
(GDCP0GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP0GBR(ctrlr)     ((volatile GDCP0GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][0])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP0GBR(ctrlr)     ((volatile GDCP0GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][0])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP0GBR(ctrlr)     ((volatile GDCP0GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][0])

/* Pointer to WORD  */ 
#define pu32GDCP0GBR(ctrlr)     ((volatile u32GDCP0GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][0])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP0GBR_GBWID(ctrlr) (pst_bitGDCP0GBR(ctrlr) -> GBWID)
#define vSetGDCP0GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP0GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP0GBR_GBINV(ctrlr) (pst_bitGDCP0GBR(ctrlr) -> GBINV)
#define vSetGDCP0GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP0GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP0GBR_GBDIV(ctrlr) (pst_bitGDCP0GBR(ctrlr) -> GBDIV)
#define vSetGDCP0GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP0GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP0GBR_GBDEL(ctrlr) (pst_bitGDCP0GBR(ctrlr) -> GBDEL)
#define vSetGDCP0GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP0GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP0GBR_GBBYP(ctrlr) (pst_bitGDCP0GBR(ctrlr) -> GBBYP)
#define vSetGDCP0GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP0GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP0GBR_GBINSEL(ctrlr) (pst_bitGDCP0GBR(ctrlr) -> GBINSEL)
#define vSetGDCP0GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP0GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP0GBR_GBLVL(ctrlr) (pst_bitGDCP0GBR(ctrlr) -> GBLVL)
#define vSetGDCP0GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP0GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP0GBRLL(ctrlr,ParValue) (pst_u8GDCP0GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP0GBRLL(ctrlr) (pst_u8GDCP0GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP0GBRLH(ctrlr,ParValue) (pst_u8GDCP0GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP0GBRLH(ctrlr) (pst_u8GDCP0GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP0GBRHL(ctrlr,ParValue) (pst_u8GDCP0GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP0GBRHL(ctrlr) (pst_u8GDCP0GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP0GBRHH(ctrlr,ParValue) (pst_u8GDCP0GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP0GBRHH(ctrlr) (pst_u8GDCP0GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP0GBRL(ctrlr,ParValue) (pst_u16GDCP0GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP0GBRL(ctrlr) (pst_u16GDCP0GBR(ctrlr) -> u16L)
#define vSetGDCP0GBRH(ctrlr,ParValue) (pst_u16GDCP0GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP0GBRH(ctrlr) (pst_u16GDCP0GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP0GBR(ctrlr,ParValue)  (*pu32GDCP0GBR(ctrlr) = (ParValue))
#define u32GetGDCP0GBR(ctrlr)  (*pu32GDCP0GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP1GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021D0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP1GBR_REG__       0xC0C021D0U
#else
#define GDCP1GBR_REG__ ((uint32_t) GDCP1GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP1GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP1GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP1GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP1GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP1GBR(ctrlr)     ((volatile GDCP1GBR_bit_view_st *)\
(GDCP1GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP1GBR(ctrlr)     ((volatile GDCP1GBR_byte_view_st *)\
(GDCP1GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP1GBR(ctrlr)     ((volatile GDCP1GBR_halfword_view_st *)\
(GDCP1GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP1GBR(ctrlr)     ((volatile u32GDCP1GBR_word_view *)\
(GDCP1GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP1GBR(ctrlr)     ((volatile GDCP1GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][1])
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP1GBR(ctrlr)     ((volatile GDCP1GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][1])
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP1GBR(ctrlr)     ((volatile GDCP1GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][1])
            
/* Pointer to WORD  */ 
#define pu32GDCP1GBR(ctrlr)     ((volatile u32GDCP1GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][1])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP1GBR_GBWID(ctrlr) (pst_bitGDCP1GBR(ctrlr) -> GBWID)
#define vSetGDCP1GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP1GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP1GBR_GBINV(ctrlr) (pst_bitGDCP1GBR(ctrlr) -> GBINV)
#define vSetGDCP1GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP1GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP1GBR_GBDIV(ctrlr) (pst_bitGDCP1GBR(ctrlr) -> GBDIV)
#define vSetGDCP1GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP1GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP1GBR_GBDEL(ctrlr) (pst_bitGDCP1GBR(ctrlr) -> GBDEL)
#define vSetGDCP1GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP1GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP1GBR_GBBYP(ctrlr) (pst_bitGDCP1GBR(ctrlr) -> GBBYP)
#define vSetGDCP1GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP1GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP1GBR_GBINSEL(ctrlr) (pst_bitGDCP1GBR(ctrlr) -> GBINSEL)
#define vSetGDCP1GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP1GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP1GBR_GBLVL(ctrlr) (pst_bitGDCP1GBR(ctrlr) -> GBLVL)
#define vSetGDCP1GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP1GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP1GBRLL(ctrlr,ParValue) (pst_u8GDCP1GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP1GBRLL(ctrlr) (pst_u8GDCP1GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP1GBRLH(ctrlr,ParValue) (pst_u8GDCP1GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP1GBRLH(ctrlr) (pst_u8GDCP1GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP1GBRHL(ctrlr,ParValue) (pst_u8GDCP1GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP1GBRHL(ctrlr) (pst_u8GDCP1GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP1GBRHH(ctrlr,ParValue) (pst_u8GDCP1GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP1GBRHH(ctrlr) (pst_u8GDCP1GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP1GBRL(ctrlr,ParValue) (pst_u16GDCP1GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP1GBRL(ctrlr) (pst_u16GDCP1GBR(ctrlr) -> u16L)
#define vSetGDCP1GBRH(ctrlr,ParValue) (pst_u16GDCP1GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP1GBRH(ctrlr) (pst_u16GDCP1GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP1GBR(ctrlr,ParValue)  (*pu32GDCP1GBR(ctrlr) = (ParValue))
#define u32GetGDCP1GBR(ctrlr)  (*pu32GDCP1GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP2GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021D8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP2GBR_REG__       0xC0C021D8U
#else
#define GDCP2GBR_REG__ ((uint32_t) GDCP2GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP2GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP2GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP2GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP2GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP2GBR(ctrlr)     ((volatile GDCP2GBR_bit_view_st *)\
(GDCP2GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP2GBR(ctrlr)     ((volatile GDCP2GBR_byte_view_st *)\
(GDCP2GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP2GBR(ctrlr)     ((volatile GDCP2GBR_halfword_view_st *)\
(GDCP2GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP2GBR(ctrlr)     ((volatile u32GDCP2GBR_word_view *)\
(GDCP2GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP2GBR(ctrlr)     ((volatile GDCP2GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][2])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP2GBR(ctrlr)     ((volatile GDCP2GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][2])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP2GBR(ctrlr)     ((volatile GDCP2GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][2])

/* Pointer to WORD  */ 
#define pu32GDCP2GBR(ctrlr)     ((volatile u32GDCP2GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][2])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP2GBR_GBWID(ctrlr) (pst_bitGDCP2GBR(ctrlr) -> GBWID)
#define vSetGDCP2GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP2GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP2GBR_GBINV(ctrlr) (pst_bitGDCP2GBR(ctrlr) -> GBINV)
#define vSetGDCP2GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP2GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP2GBR_GBDIV(ctrlr) (pst_bitGDCP2GBR(ctrlr) -> GBDIV)
#define vSetGDCP2GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP2GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP2GBR_GBDEL(ctrlr) (pst_bitGDCP2GBR(ctrlr) -> GBDEL)
#define vSetGDCP2GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP2GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP2GBR_GBBYP(ctrlr) (pst_bitGDCP2GBR(ctrlr) -> GBBYP)
#define vSetGDCP2GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP2GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP2GBR_GBINSEL(ctrlr) (pst_bitGDCP2GBR(ctrlr) -> GBINSEL)
#define vSetGDCP2GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP2GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP2GBR_GBLVL(ctrlr) (pst_bitGDCP2GBR(ctrlr) -> GBLVL)
#define vSetGDCP2GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP2GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP2GBRLL(ctrlr,ParValue) (pst_u8GDCP2GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP2GBRLL(ctrlr) (pst_u8GDCP2GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP2GBRLH(ctrlr,ParValue) (pst_u8GDCP2GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP2GBRLH(ctrlr) (pst_u8GDCP2GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP2GBRHL(ctrlr,ParValue) (pst_u8GDCP2GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP2GBRHL(ctrlr) (pst_u8GDCP2GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP2GBRHH(ctrlr,ParValue) (pst_u8GDCP2GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP2GBRHH(ctrlr) (pst_u8GDCP2GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP2GBRL(ctrlr,ParValue) (pst_u16GDCP2GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP2GBRL(ctrlr) (pst_u16GDCP2GBR(ctrlr) -> u16L)
#define vSetGDCP2GBRH(ctrlr,ParValue) (pst_u16GDCP2GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP2GBRH(ctrlr) (pst_u16GDCP2GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP2GBR(ctrlr,ParValue)  (*pu32GDCP2GBR(ctrlr) = (ParValue))
#define u32GetGDCP2GBR(ctrlr)  (*pu32GDCP2GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP3GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021E0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP3GBR_REG__       0xC0C021E0U
#else
#define GDCP3GBR_REG__ ((uint32_t) GDCP3GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP3GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP3GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP3GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP3GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP3GBR(ctrlr)     ((volatile GDCP3GBR_bit_view_st *)\
(GDCP3GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP3GBR(ctrlr)     ((volatile GDCP3GBR_byte_view_st *)\
(GDCP3GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP3GBR(ctrlr)     ((volatile GDCP3GBR_halfword_view_st *)\
(GDCP3GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP3GBR(ctrlr)     ((volatile u32GDCP3GBR_word_view *)\
(GDCP3GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP3GBR(ctrlr)     ((volatile GDCP3GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][3])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP3GBR(ctrlr)     ((volatile GDCP3GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][3])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP3GBR(ctrlr)     ((volatile GDCP3GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][3])

/* Pointer to WORD  */ 
#define pu32GDCP3GBR(ctrlr)     ((volatile u32GDCP3GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][3])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP3GBR_GBWID(ctrlr) (pst_bitGDCP3GBR(ctrlr) -> GBWID)
#define vSetGDCP3GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP3GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP3GBR_GBINV(ctrlr) (pst_bitGDCP3GBR(ctrlr) -> GBINV)
#define vSetGDCP3GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP3GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP3GBR_GBDIV(ctrlr) (pst_bitGDCP3GBR(ctrlr) -> GBDIV)
#define vSetGDCP3GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP3GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP3GBR_GBDEL(ctrlr) (pst_bitGDCP3GBR(ctrlr) -> GBDEL)
#define vSetGDCP3GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP3GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP3GBR_GBBYP(ctrlr) (pst_bitGDCP3GBR(ctrlr) -> GBBYP)
#define vSetGDCP3GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP3GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP3GBR_GBINSEL(ctrlr) (pst_bitGDCP3GBR(ctrlr) -> GBINSEL)
#define vSetGDCP3GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP3GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP3GBR_GBLVL(ctrlr) (pst_bitGDCP3GBR(ctrlr) -> GBLVL)
#define vSetGDCP3GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP3GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP3GBRLL(ctrlr,ParValue) (pst_u8GDCP3GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP3GBRLL(ctrlr) (pst_u8GDCP3GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP3GBRLH(ctrlr,ParValue) (pst_u8GDCP3GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP3GBRLH(ctrlr) (pst_u8GDCP3GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP3GBRHL(ctrlr,ParValue) (pst_u8GDCP3GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP3GBRHL(ctrlr) (pst_u8GDCP3GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP3GBRHH(ctrlr,ParValue) (pst_u8GDCP3GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP3GBRHH(ctrlr) (pst_u8GDCP3GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP3GBRL(ctrlr,ParValue) (pst_u16GDCP3GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP3GBRL(ctrlr) (pst_u16GDCP3GBR(ctrlr) -> u16L)
#define vSetGDCP3GBRH(ctrlr,ParValue) (pst_u16GDCP3GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP3GBRH(ctrlr) (pst_u16GDCP3GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP3GBR(ctrlr,ParValue)  (*pu32GDCP3GBR(ctrlr) = (ParValue))
#define u32GetGDCP3GBR(ctrlr)  (*pu32GDCP3GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP4GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021E8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP4GBR_REG__       0xC0C021E8U
#else
#define GDCP4GBR_REG__ ((uint32_t) GDCP4GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP4GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP4GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP4GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP4GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP4GBR(ctrlr)     ((volatile GDCP4GBR_bit_view_st *)\
(GDCP4GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP4GBR(ctrlr)     ((volatile GDCP4GBR_byte_view_st *)\
(GDCP4GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP4GBR(ctrlr)     ((volatile GDCP4GBR_halfword_view_st *)\
(GDCP4GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP4GBR(ctrlr)     ((volatile u32GDCP4GBR_word_view *)\
(GDCP4GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP4GBR(ctrlr)     ((volatile GDCP4GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][4])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP4GBR(ctrlr)     ((volatile GDCP4GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][4])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP4GBR(ctrlr)     ((volatile GDCP4GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][4])

/* Pointer to WORD  */ 
#define pu32GDCP4GBR(ctrlr)     ((volatile u32GDCP4GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][4])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP4GBR_GBWID(ctrlr) (pst_bitGDCP4GBR(ctrlr) -> GBWID)
#define vSetGDCP4GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP4GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP4GBR_GBINV(ctrlr) (pst_bitGDCP4GBR(ctrlr) -> GBINV)
#define vSetGDCP4GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP4GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP4GBR_GBDIV(ctrlr) (pst_bitGDCP4GBR(ctrlr) -> GBDIV)
#define vSetGDCP4GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP4GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP4GBR_GBDEL(ctrlr) (pst_bitGDCP4GBR(ctrlr) -> GBDEL)
#define vSetGDCP4GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP4GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP4GBR_GBBYP(ctrlr) (pst_bitGDCP4GBR(ctrlr) -> GBBYP)
#define vSetGDCP4GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP4GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP4GBR_GBINSEL(ctrlr) (pst_bitGDCP4GBR(ctrlr) -> GBINSEL)
#define vSetGDCP4GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP4GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP4GBR_GBLVL(ctrlr) (pst_bitGDCP4GBR(ctrlr) -> GBLVL)
#define vSetGDCP4GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP4GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP4GBRLL(ctrlr,ParValue) (pst_u8GDCP4GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP4GBRLL(ctrlr) (pst_u8GDCP4GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP4GBRLH(ctrlr,ParValue) (pst_u8GDCP4GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP4GBRLH(ctrlr) (pst_u8GDCP4GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP4GBRHL(ctrlr,ParValue) (pst_u8GDCP4GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP4GBRHL(ctrlr) (pst_u8GDCP4GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP4GBRHH(ctrlr,ParValue) (pst_u8GDCP4GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP4GBRHH(ctrlr) (pst_u8GDCP4GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP4GBRL(ctrlr,ParValue) (pst_u16GDCP4GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP4GBRL(ctrlr) (pst_u16GDCP4GBR(ctrlr) -> u16L)
#define vSetGDCP4GBRH(ctrlr,ParValue) (pst_u16GDCP4GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP4GBRH(ctrlr) (pst_u16GDCP4GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP4GBR(ctrlr,ParValue)  (*pu32GDCP4GBR(ctrlr) = (ParValue))
#define u32GetGDCP4GBR(ctrlr)  (*pu32GDCP4GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP5GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021F0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP5GBR_REG__       0xC0C021F0U
#else
#define GDCP5GBR_REG__ ((uint32_t) GDCP5GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP5GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP5GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP5GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP5GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP5GBR(ctrlr)     ((volatile GDCP5GBR_bit_view_st *)\
(GDCP5GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP5GBR(ctrlr)     ((volatile GDCP5GBR_byte_view_st *)\
(GDCP5GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP5GBR(ctrlr)     ((volatile GDCP5GBR_halfword_view_st *)\
(GDCP5GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP5GBR(ctrlr)     ((volatile u32GDCP5GBR_word_view *)\
(GDCP5GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP5GBR(ctrlr)     ((volatile GDCP5GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][5])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP5GBR(ctrlr)     ((volatile GDCP5GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][5])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP5GBR(ctrlr)     ((volatile GDCP5GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][5])

/* Pointer to WORD  */ 
#define pu32GDCP5GBR(ctrlr)     ((volatile u32GDCP5GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][5])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP5GBR_GBWID(ctrlr) (pst_bitGDCP5GBR(ctrlr) -> GBWID)
#define vSetGDCP5GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP5GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP5GBR_GBINV(ctrlr) (pst_bitGDCP5GBR(ctrlr) -> GBINV)
#define vSetGDCP5GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP5GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP5GBR_GBDIV(ctrlr) (pst_bitGDCP5GBR(ctrlr) -> GBDIV)
#define vSetGDCP5GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP5GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP5GBR_GBDEL(ctrlr) (pst_bitGDCP5GBR(ctrlr) -> GBDEL)
#define vSetGDCP5GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP5GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP5GBR_GBBYP(ctrlr) (pst_bitGDCP5GBR(ctrlr) -> GBBYP)
#define vSetGDCP5GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP5GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP5GBR_GBINSEL(ctrlr) (pst_bitGDCP5GBR(ctrlr) -> GBINSEL)
#define vSetGDCP5GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP5GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP5GBR_GBLVL(ctrlr) (pst_bitGDCP5GBR(ctrlr) -> GBLVL)
#define vSetGDCP5GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP5GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP5GBRLL(ctrlr,ParValue) (pst_u8GDCP5GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP5GBRLL(ctrlr) (pst_u8GDCP5GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP5GBRLH(ctrlr,ParValue) (pst_u8GDCP5GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP5GBRLH(ctrlr) (pst_u8GDCP5GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP5GBRHL(ctrlr,ParValue) (pst_u8GDCP5GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP5GBRHL(ctrlr) (pst_u8GDCP5GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP5GBRHH(ctrlr,ParValue) (pst_u8GDCP5GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP5GBRHH(ctrlr) (pst_u8GDCP5GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP5GBRL(ctrlr,ParValue) (pst_u16GDCP5GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP5GBRL(ctrlr) (pst_u16GDCP5GBR(ctrlr) -> u16L)
#define vSetGDCP5GBRH(ctrlr,ParValue) (pst_u16GDCP5GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP5GBRH(ctrlr) (pst_u16GDCP5GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP5GBR(ctrlr,ParValue)  (*pu32GDCP5GBR(ctrlr) = (ParValue))
#define u32GetGDCP5GBR(ctrlr)  (*pu32GDCP5GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP6GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C021F8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP6GBR_REG__       0xC0C021F8U
#else
#define GDCP6GBR_REG__ ((uint32_t) GDCP6GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP6GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP6GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP6GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP6GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP6GBR(ctrlr)     ((volatile GDCP6GBR_bit_view_st *)\
(GDCP6GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP6GBR(ctrlr)     ((volatile GDCP6GBR_byte_view_st *)\
(GDCP6GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP6GBR(ctrlr)     ((volatile GDCP6GBR_halfword_view_st *)\
(GDCP6GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP6GBR(ctrlr)     ((volatile u32GDCP6GBR_word_view *)\
(GDCP6GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP6GBR(ctrlr)     ((volatile GDCP6GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][6])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP6GBR(ctrlr)     ((volatile GDCP6GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][6])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP6GBR(ctrlr)     ((volatile GDCP6GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][6])

/* Pointer to WORD  */ 
#define pu32GDCP6GBR(ctrlr)     ((volatile u32GDCP6GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][6])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP6GBR_GBWID(ctrlr) (pst_bitGDCP6GBR(ctrlr) -> GBWID)
#define vSetGDCP6GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP6GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP6GBR_GBINV(ctrlr) (pst_bitGDCP6GBR(ctrlr) -> GBINV)
#define vSetGDCP6GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP6GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP6GBR_GBDIV(ctrlr) (pst_bitGDCP6GBR(ctrlr) -> GBDIV)
#define vSetGDCP6GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP6GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP6GBR_GBDEL(ctrlr) (pst_bitGDCP6GBR(ctrlr) -> GBDEL)
#define vSetGDCP6GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP6GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP6GBR_GBBYP(ctrlr) (pst_bitGDCP6GBR(ctrlr) -> GBBYP)
#define vSetGDCP6GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP6GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP6GBR_GBINSEL(ctrlr) (pst_bitGDCP6GBR(ctrlr) -> GBINSEL)
#define vSetGDCP6GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP6GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP6GBR_GBLVL(ctrlr) (pst_bitGDCP6GBR(ctrlr) -> GBLVL)
#define vSetGDCP6GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP6GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP6GBRLL(ctrlr,ParValue) (pst_u8GDCP6GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP6GBRLL(ctrlr) (pst_u8GDCP6GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP6GBRLH(ctrlr,ParValue) (pst_u8GDCP6GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP6GBRLH(ctrlr) (pst_u8GDCP6GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP6GBRHL(ctrlr,ParValue) (pst_u8GDCP6GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP6GBRHL(ctrlr) (pst_u8GDCP6GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP6GBRHH(ctrlr,ParValue) (pst_u8GDCP6GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP6GBRHH(ctrlr) (pst_u8GDCP6GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP6GBRL(ctrlr,ParValue) (pst_u16GDCP6GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP6GBRL(ctrlr) (pst_u16GDCP6GBR(ctrlr) -> u16L)
#define vSetGDCP6GBRH(ctrlr,ParValue) (pst_u16GDCP6GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP6GBRH(ctrlr) (pst_u16GDCP6GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP6GBR(ctrlr,ParValue)  (*pu32GDCP6GBR(ctrlr) = (ParValue))
#define u32GetGDCP6GBR(ctrlr)  (*pu32GDCP6GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP7GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02200                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP7GBR_REG__       0xC0C02200U
#else
#define GDCP7GBR_REG__ ((uint32_t) GDCP7GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP7GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP7GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP7GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP7GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP7GBR(ctrlr)     ((volatile GDCP7GBR_bit_view_st *)\
(GDCP7GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP7GBR(ctrlr)     ((volatile GDCP7GBR_byte_view_st *)\
(GDCP7GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP7GBR(ctrlr)     ((volatile GDCP7GBR_halfword_view_st *)\
(GDCP7GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP7GBR(ctrlr)     ((volatile u32GDCP7GBR_word_view *)\
(GDCP7GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP7GBR(ctrlr)     ((volatile GDCP7GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][7])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP7GBR(ctrlr)     ((volatile GDCP7GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][7])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP7GBR(ctrlr)     ((volatile GDCP7GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][7])

/* Pointer to WORD  */ 
#define pu32GDCP7GBR(ctrlr)     ((volatile u32GDCP7GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][7])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP7GBR_GBWID(ctrlr) (pst_bitGDCP7GBR(ctrlr) -> GBWID)
#define vSetGDCP7GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP7GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP7GBR_GBINV(ctrlr) (pst_bitGDCP7GBR(ctrlr) -> GBINV)
#define vSetGDCP7GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP7GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP7GBR_GBDIV(ctrlr) (pst_bitGDCP7GBR(ctrlr) -> GBDIV)
#define vSetGDCP7GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP7GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP7GBR_GBDEL(ctrlr) (pst_bitGDCP7GBR(ctrlr) -> GBDEL)
#define vSetGDCP7GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP7GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP7GBR_GBBYP(ctrlr) (pst_bitGDCP7GBR(ctrlr) -> GBBYP)
#define vSetGDCP7GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP7GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP7GBR_GBINSEL(ctrlr) (pst_bitGDCP7GBR(ctrlr) -> GBINSEL)
#define vSetGDCP7GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP7GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP7GBR_GBLVL(ctrlr) (pst_bitGDCP7GBR(ctrlr) -> GBLVL)
#define vSetGDCP7GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP7GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP7GBRLL(ctrlr,ParValue) (pst_u8GDCP7GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP7GBRLL(ctrlr) (pst_u8GDCP7GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP7GBRLH(ctrlr,ParValue) (pst_u8GDCP7GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP7GBRLH(ctrlr) (pst_u8GDCP7GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP7GBRHL(ctrlr,ParValue) (pst_u8GDCP7GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP7GBRHL(ctrlr) (pst_u8GDCP7GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP7GBRHH(ctrlr,ParValue) (pst_u8GDCP7GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP7GBRHH(ctrlr) (pst_u8GDCP7GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP7GBRL(ctrlr,ParValue) (pst_u16GDCP7GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP7GBRL(ctrlr) (pst_u16GDCP7GBR(ctrlr) -> u16L)
#define vSetGDCP7GBRH(ctrlr,ParValue) (pst_u16GDCP7GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP7GBRH(ctrlr) (pst_u16GDCP7GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP7GBR(ctrlr,ParValue)  (*pu32GDCP7GBR(ctrlr) = (ParValue))
#define u32GetGDCP7GBR(ctrlr)  (*pu32GDCP7GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP8GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02208                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP8GBR_REG__       0xC0C02208U
#else
#define GDCP8GBR_REG__ ((uint32_t) GDCP8GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP8GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP8GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP8GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP8GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP8GBR(ctrlr)     ((volatile GDCP8GBR_bit_view_st *)\
(GDCP8GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP8GBR(ctrlr)     ((volatile GDCP8GBR_byte_view_st *)\
(GDCP8GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP8GBR(ctrlr)     ((volatile GDCP8GBR_halfword_view_st *)\
(GDCP8GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP8GBR(ctrlr)     ((volatile u32GDCP8GBR_word_view *)\
(GDCP8GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP8GBR(ctrlr)     ((volatile GDCP8GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][8])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP8GBR(ctrlr)     ((volatile GDCP8GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][8])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP8GBR(ctrlr)     ((volatile GDCP8GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][8])

/* Pointer to WORD  */ 
#define pu32GDCP8GBR(ctrlr)     ((volatile u32GDCP8GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][8])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP8GBR_GBWID(ctrlr) (pst_bitGDCP8GBR(ctrlr) -> GBWID)
#define vSetGDCP8GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP8GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP8GBR_GBINV(ctrlr) (pst_bitGDCP8GBR(ctrlr) -> GBINV)
#define vSetGDCP8GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP8GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP8GBR_GBDIV(ctrlr) (pst_bitGDCP8GBR(ctrlr) -> GBDIV)
#define vSetGDCP8GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP8GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP8GBR_GBDEL(ctrlr) (pst_bitGDCP8GBR(ctrlr) -> GBDEL)
#define vSetGDCP8GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP8GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP8GBR_GBBYP(ctrlr) (pst_bitGDCP8GBR(ctrlr) -> GBBYP)
#define vSetGDCP8GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP8GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP8GBR_GBINSEL(ctrlr) (pst_bitGDCP8GBR(ctrlr) -> GBINSEL)
#define vSetGDCP8GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP8GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP8GBR_GBLVL(ctrlr) (pst_bitGDCP8GBR(ctrlr) -> GBLVL)
#define vSetGDCP8GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP8GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP8GBRLL(ctrlr,ParValue) (pst_u8GDCP8GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP8GBRLL(ctrlr) (pst_u8GDCP8GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP8GBRLH(ctrlr,ParValue) (pst_u8GDCP8GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP8GBRLH(ctrlr) (pst_u8GDCP8GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP8GBRHL(ctrlr,ParValue) (pst_u8GDCP8GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP8GBRHL(ctrlr) (pst_u8GDCP8GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP8GBRHH(ctrlr,ParValue) (pst_u8GDCP8GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP8GBRHH(ctrlr) (pst_u8GDCP8GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP8GBRL(ctrlr,ParValue) (pst_u16GDCP8GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP8GBRL(ctrlr) (pst_u16GDCP8GBR(ctrlr) -> u16L)
#define vSetGDCP8GBRH(ctrlr,ParValue) (pst_u16GDCP8GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP8GBRH(ctrlr) (pst_u16GDCP8GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP8GBR(ctrlr,ParValue)  (*pu32GDCP8GBR(ctrlr) = (ParValue))
#define u32GetGDCP8GBR(ctrlr)  (*pu32GDCP8GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP9GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02210                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP9GBR_REG__       0xC0C02210U
#else
#define GDCP9GBR_REG__ ((uint32_t) GDCP9GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP9GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP9GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP9GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP9GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP9GBR(ctrlr)     ((volatile GDCP9GBR_bit_view_st *)\
(GDCP9GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP9GBR(ctrlr)     ((volatile GDCP9GBR_byte_view_st *)\
(GDCP9GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP9GBR(ctrlr)     ((volatile GDCP9GBR_halfword_view_st *)\
(GDCP9GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP9GBR(ctrlr)     ((volatile u32GDCP9GBR_word_view *)\
(GDCP9GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP9GBR(ctrlr)     ((volatile GDCP9GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][9])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP9GBR(ctrlr)     ((volatile GDCP9GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][9])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP9GBR(ctrlr)     ((volatile GDCP9GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][9])

/* Pointer to WORD  */ 
#define pu32GDCP9GBR(ctrlr)     ((volatile u32GDCP9GBR_word_view *)GDCP9GBR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP9GBR_GBWID(ctrlr) (pst_bitGDCP9GBR(ctrlr) -> GBWID)
#define vSetGDCP9GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP9GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP9GBR_GBINV(ctrlr) (pst_bitGDCP9GBR(ctrlr) -> GBINV)
#define vSetGDCP9GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP9GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP9GBR_GBDIV(ctrlr) (pst_bitGDCP9GBR(ctrlr) -> GBDIV)
#define vSetGDCP9GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP9GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP9GBR_GBDEL(ctrlr) (pst_bitGDCP9GBR(ctrlr) -> GBDEL)
#define vSetGDCP9GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP9GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP9GBR_GBBYP(ctrlr) (pst_bitGDCP9GBR(ctrlr) -> GBBYP)
#define vSetGDCP9GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP9GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP9GBR_GBINSEL(ctrlr) (pst_bitGDCP9GBR(ctrlr) -> GBINSEL)
#define vSetGDCP9GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP9GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP9GBR_GBLVL(ctrlr) (pst_bitGDCP9GBR(ctrlr) -> GBLVL)
#define vSetGDCP9GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP9GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP9GBRLL(ctrlr,ParValue) (pst_u8GDCP9GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP9GBRLL(ctrlr) (pst_u8GDCP9GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP9GBRLH(ctrlr,ParValue) (pst_u8GDCP9GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP9GBRLH(ctrlr) (pst_u8GDCP9GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP9GBRHL(ctrlr,ParValue) (pst_u8GDCP9GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP9GBRHL(ctrlr) (pst_u8GDCP9GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP9GBRHH(ctrlr,ParValue) (pst_u8GDCP9GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP9GBRHH(ctrlr) (pst_u8GDCP9GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP9GBRL(ctrlr,ParValue) (pst_u16GDCP9GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP9GBRL(ctrlr) (pst_u16GDCP9GBR(ctrlr) -> u16L)
#define vSetGDCP9GBRH(ctrlr,ParValue) (pst_u16GDCP9GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP9GBRH(ctrlr) (pst_u16GDCP9GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP9GBR(ctrlr,ParValue)  (*pu32GDCP9GBR(ctrlr) = (ParValue))
#define u32GetGDCP9GBR(ctrlr)  (*pu32GDCP9GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP10GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02218                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP10GBR_REG__       0xC0C02218U
#else
#define GDCP10GBR_REG__ ((uint32_t) GDCP10GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP10GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP10GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP10GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP10GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP10GBR(ctrlr)     ((volatile GDCP10GBR_bit_view_st *)\
(GDCP10GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP10GBR(ctrlr)     ((volatile GDCP10GBR_byte_view_st *)\
(GDCP10GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP10GBR(ctrlr)     ((volatile GDCP10GBR_halfword_view_st *)\
(GDCP10GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP10GBR(ctrlr)     ((volatile u32GDCP10GBR_word_view *)\
(GDCP10GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP10GBR(ctrlr)     ((volatile GDCP10GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][10])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP10GBR(ctrlr)     ((volatile GDCP10GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][10])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP10GBR(ctrlr)     ((volatile GDCP10GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][10])

/* Pointer to WORD  */ 
#define pu32GDCP10GBR(ctrlr)     ((volatile u32GDCP10GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][10])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP10GBR_GBWID(ctrlr) (pst_bitGDCP10GBR(ctrlr) -> GBWID)
#define vSetGDCP10GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP10GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP10GBR_GBINV(ctrlr) (pst_bitGDCP10GBR(ctrlr) -> GBINV)
#define vSetGDCP10GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP10GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP10GBR_GBDIV(ctrlr) (pst_bitGDCP10GBR(ctrlr) -> GBDIV)
#define vSetGDCP10GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP10GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP10GBR_GBDEL(ctrlr) (pst_bitGDCP10GBR(ctrlr) -> GBDEL)
#define vSetGDCP10GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP10GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP10GBR_GBBYP(ctrlr) (pst_bitGDCP10GBR(ctrlr) -> GBBYP)
#define vSetGDCP10GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP10GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP10GBR_GBINSEL(ctrlr) (pst_bitGDCP10GBR(ctrlr) -> GBINSEL)
#define vSetGDCP10GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP10GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP10GBR_GBLVL(ctrlr) (pst_bitGDCP10GBR(ctrlr) -> GBLVL)
#define vSetGDCP10GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP10GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP10GBRLL(ctrlr,ParValue) (pst_u8GDCP10GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP10GBRLL(ctrlr) (pst_u8GDCP10GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP10GBRLH(ctrlr,ParValue) (pst_u8GDCP10GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP10GBRLH(ctrlr) (pst_u8GDCP10GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP10GBRHL(ctrlr,ParValue) (pst_u8GDCP10GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP10GBRHL(ctrlr) (pst_u8GDCP10GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP10GBRHH(ctrlr,ParValue) (pst_u8GDCP10GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP10GBRHH(ctrlr) (pst_u8GDCP10GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP10GBRL(ctrlr,ParValue) (pst_u16GDCP10GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP10GBRL(ctrlr) (pst_u16GDCP10GBR(ctrlr) -> u16L)
#define vSetGDCP10GBRH(ctrlr,ParValue) (pst_u16GDCP10GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP10GBRH(ctrlr) (pst_u16GDCP10GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP10GBR(ctrlr,ParValue)  (*pu32GDCP10GBR(ctrlr) = (ParValue))
#define u32GetGDCP10GBR(ctrlr)  (*pu32GDCP10GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCP11GBR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02220                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCP11GBR_REG__       0xC0C02220U
#else
#define GDCP11GBR_REG__ ((uint32_t) GDCP11GBR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBWID	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   GBINV	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   GBDIV	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   GBDEL	:11; 	 /* 16..26  bit(s) R/W */
  uint32_t   GBBYP	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   GBINSEL	:3; 	 /* 28..30  bit(s) R/W */
  uint32_t   GBLVL	:1; 	 /* 31..31  bit(s) R/W */                    
} GDCP11GBR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCP11GBR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCP11GBR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCP11GBR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCP11GBR(ctrlr)     ((volatile GDCP11GBR_bit_view_st *)\
(GDCP11GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCP11GBR(ctrlr)     ((volatile GDCP11GBR_byte_view_st *)\
(GDCP11GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCP11GBR(ctrlr)     ((volatile GDCP11GBR_halfword_view_st *)\
(GDCP11GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCP11GBR(ctrlr)     ((volatile u32GDCP11GBR_word_view *)\
(GDCP11GBR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCP11GBR(ctrlr)     ((volatile GDCP11GBR_bit_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][11])

/* Pointer to BYTE-struct  */
#define pst_u8GDCP11GBR(ctrlr)     ((volatile GDCP11GBR_byte_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][11])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCP11GBR(ctrlr)     ((volatile GDCP11GBR_halfword_view_st *) &u32GDCPxGBR_REG__Var[(ctrlr)][11])

/* Pointer to WORD  */ 
#define pu32GDCP11GBR(ctrlr)     ((volatile u32GDCP11GBR_word_view *) &u32GDCPxGBR_REG__Var[(ctrlr)][11])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCP11GBR_GBWID(ctrlr) (pst_bitGDCP11GBR(ctrlr) -> GBWID)
#define vSetGDCP11GBR_GBWID(ctrlr,ParValue)  (pst_bitGDCP11GBR(ctrlr) -> GBWID=(ParValue))
#define biGetGDCP11GBR_GBINV(ctrlr) (pst_bitGDCP11GBR(ctrlr) -> GBINV)
#define vSetGDCP11GBR_GBINV(ctrlr,ParValue)  (pst_bitGDCP11GBR(ctrlr) -> GBINV=(ParValue))
#define biGetGDCP11GBR_GBDIV(ctrlr) (pst_bitGDCP11GBR(ctrlr) -> GBDIV)
#define vSetGDCP11GBR_GBDIV(ctrlr,ParValue)  (pst_bitGDCP11GBR(ctrlr) -> GBDIV=(ParValue))
#define biGetGDCP11GBR_GBDEL(ctrlr) (pst_bitGDCP11GBR(ctrlr) -> GBDEL)
#define vSetGDCP11GBR_GBDEL(ctrlr,ParValue)  (pst_bitGDCP11GBR(ctrlr) -> GBDEL=(ParValue))
#define biGetGDCP11GBR_GBBYP(ctrlr) (pst_bitGDCP11GBR(ctrlr) -> GBBYP)
#define vSetGDCP11GBR_GBBYP(ctrlr,ParValue)  (pst_bitGDCP11GBR(ctrlr) -> GBBYP=(ParValue))
#define biGetGDCP11GBR_GBINSEL(ctrlr) (pst_bitGDCP11GBR(ctrlr) -> GBINSEL)
#define vSetGDCP11GBR_GBINSEL(ctrlr,ParValue)  (pst_bitGDCP11GBR(ctrlr) -> GBINSEL=(ParValue))
#define biGetGDCP11GBR_GBLVL(ctrlr) (pst_bitGDCP11GBR(ctrlr) -> GBLVL)
#define vSetGDCP11GBR_GBLVL(ctrlr,ParValue)  (pst_bitGDCP11GBR(ctrlr) -> GBLVL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCP11GBRLL(ctrlr,ParValue) (pst_u8GDCP11GBR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCP11GBRLL(ctrlr) (pst_u8GDCP11GBR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCP11GBRLH(ctrlr,ParValue) (pst_u8GDCP11GBR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCP11GBRLH(ctrlr) (pst_u8GDCP11GBR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCP11GBRHL(ctrlr,ParValue) (pst_u8GDCP11GBR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCP11GBRHL(ctrlr) (pst_u8GDCP11GBR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCP11GBRHH(ctrlr,ParValue) (pst_u8GDCP11GBR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCP11GBRHH(ctrlr) (pst_u8GDCP11GBR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCP11GBRL(ctrlr,ParValue) (pst_u16GDCP11GBR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCP11GBRL(ctrlr) (pst_u16GDCP11GBR(ctrlr) -> u16L)
#define vSetGDCP11GBRH(ctrlr,ParValue) (pst_u16GDCP11GBR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCP11GBRH(ctrlr) (pst_u16GDCP11GBR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCP11GBR(ctrlr,ParValue)  (*pu32GDCP11GBR(ctrlr) = (ParValue))
#define u32GetGDCP11GBR(ctrlr)  (*pu32GDCP11GBR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCPSMR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02228                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCPSMR_REG__       0xC0C02228U
#else
#define GDCPSMR_REG__ ((uint32_t) GDCPSMR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PSDEL	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   PSDDEL	:4; 	 /* 16..19  bit(s) R/W */ 
  uint32_t   	:12; 	 /* 20..63  bit(s) R */                    
} GDCPSMR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCPSMR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCPSMR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCPSMR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCPSMR(ctrlr)     ((volatile GDCPSMR_bit_view_st *)\
(GDCPSMR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCPSMR(ctrlr)     ((volatile GDCPSMR_byte_view_st *)\
(GDCPSMR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCPSMR(ctrlr)     ((volatile GDCPSMR_halfword_view_st *)\
(GDCPSMR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCPSMR(ctrlr)     ((volatile u32GDCPSMR_word_view *)\
(GDCPSMR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCPSMR(ctrlr)     ((volatile GDCPSMR_bit_view_st *) &u32GDCPSMR_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCPSMR(ctrlr)     ((volatile GDCPSMR_byte_view_st *) &u32GDCPSMR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCPSMR(ctrlr)     ((volatile GDCPSMR_halfword_view_st *) &u32GDCPSMR_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCPSMR(ctrlr)     ((volatile u32GDCPSMR_word_view *) &u32GDCPSMR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCPSMR_PSDEL(ctrlr) (pst_bitGDCPSMR(ctrlr) -> PSDEL)
#define vSetGDCPSMR_PSDEL(ctrlr,ParValue)  (pst_bitGDCPSMR(ctrlr) -> PSDEL=(ParValue))
#define biGetGDCPSMR_PSDDEL(ctrlr) (pst_bitGDCPSMR(ctrlr) -> PSDDEL)
#define vSetGDCPSMR_PSDDEL(ctrlr,ParValue)  (pst_bitGDCPSMR(ctrlr) -> PSDDEL=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCPSMRLL(ctrlr,ParValue) (pst_u8GDCPSMR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCPSMRLL(ctrlr) (pst_u8GDCPSMR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCPSMRLH(ctrlr,ParValue) (pst_u8GDCPSMR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCPSMRLH(ctrlr) (pst_u8GDCPSMR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCPSMRHL(ctrlr,ParValue) (pst_u8GDCPSMR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCPSMRHL(ctrlr) (pst_u8GDCPSMR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCPSMRHH(ctrlr,ParValue) (pst_u8GDCPSMR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCPSMRHH(ctrlr) (pst_u8GDCPSMR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCPSMRL(ctrlr,ParValue) (pst_u16GDCPSMR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCPSMRL(ctrlr) (pst_u16GDCPSMR(ctrlr) -> u16L)
#define vSetGDCPSMRH(ctrlr,ParValue) (pst_u16GDCPSMR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCPSMRH(ctrlr) (pst_u16GDCPSMR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCPSMR(ctrlr,ParValue)  (*pu32GDCPSMR(ctrlr) = (ParValue))
#define u32GetGDCPSMR(ctrlr)  (*pu32GDCPSMR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARE0                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02230                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARE0_REG__       0xC0C02230U
#else
#define GDCLARE0_REG__ ((uint32_t) GDCLARE0_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARE0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARE0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARE0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARE0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARE0(ctrlr)     ((volatile GDCLARE0_bit_view_st *)\
(GDCLARE0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARE0(ctrlr)     ((volatile GDCLARE0_byte_view_st *)\
(GDCLARE0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARE0(ctrlr)     ((volatile GDCLARE0_halfword_view_st *)\
(GDCLARE0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARE0(ctrlr)     ((volatile u32GDCLARE0_word_view *)\
(GDCLARE0_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARE0(ctrlr)     ((volatile GDCLARE0_bit_view_st *) &u32GDCLARE0_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARE0(ctrlr)     ((volatile GDCLARE0_byte_view_st *) &u32GDCLARE0_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARE0(ctrlr)     ((volatile GDCLARE0_halfword_view_st *) &u32GDCLARE0_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARE0(ctrlr)     ((volatile u32GDCLARE0_word_view *) &u32GDCLARE0_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARE0_SSCROLL(ctrlr) (pst_bitGDCLARE0(ctrlr) -> SSCROLL)
#define vSetGDCLARE0_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARE0(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARE0_SAR(ctrlr) (pst_bitGDCLARE0(ctrlr) -> SAR)
#define vSetGDCLARE0_SAR(ctrlr,ParValue)  (pst_bitGDCLARE0(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARE0LL(ctrlr,ParValue) (pst_u8GDCLARE0(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARE0LL(ctrlr) (pst_u8GDCLARE0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARE0LH(ctrlr,ParValue) (pst_u8GDCLARE0(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARE0LH(ctrlr) (pst_u8GDCLARE0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARE0HL(ctrlr,ParValue) (pst_u8GDCLARE0(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARE0HL(ctrlr) (pst_u8GDCLARE0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARE0HH(ctrlr,ParValue) (pst_u8GDCLARE0(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARE0HH(ctrlr) (pst_u8GDCLARE0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARE0L(ctrlr,ParValue) (pst_u16GDCLARE0(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARE0L(ctrlr) (pst_u16GDCLARE0(ctrlr) -> u16L)
#define vSetGDCLARE0H(ctrlr,ParValue) (pst_u16GDCLARE0(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARE0H(ctrlr) (pst_u16GDCLARE0(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARE0(ctrlr,ParValue)  (*pu32GDCLARE0(ctrlr) = (ParValue))
#define u32GetGDCLARE0(ctrlr)  (*pu32GDCLARE0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCLARE1                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02238                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCLARE1_REG__       0xC0C02238U
#else
#define GDCLARE1_REG__ ((uint32_t) GDCLARE1_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:1; 	 /* 0..0  bit(s) R */
  uint32_t   SSCROLL	:2; 	 /* 1..2  bit(s) R/W */
  uint32_t   SAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCLARE1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCLARE1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCLARE1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCLARE1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCLARE1(ctrlr)     ((volatile GDCLARE1_bit_view_st *)\
(GDCLARE1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCLARE1(ctrlr)     ((volatile GDCLARE1_byte_view_st *)\
(GDCLARE1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARE1(ctrlr)     ((volatile GDCLARE1_halfword_view_st *)\
(GDCLARE1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCLARE1(ctrlr)     ((volatile u32GDCLARE1_word_view *)\
(GDCLARE1_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCLARE1(ctrlr)     ((volatile GDCLARE1_bit_view_st *) &u32GDCLARE1_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCLARE1(ctrlr)     ((volatile GDCLARE1_byte_view_st *) &u32GDCLARE1_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCLARE1(ctrlr)     ((volatile GDCLARE1_halfword_view_st *) &u32GDCLARE1_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCLARE1(ctrlr)     ((volatile u32GDCLARE1_word_view *) &u32GDCLARE1_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCLARE1_SSCROLL(ctrlr) (pst_bitGDCLARE1(ctrlr) -> SSCROLL)
#define vSetGDCLARE1_SSCROLL(ctrlr,ParValue)  (pst_bitGDCLARE1(ctrlr) -> SSCROLL=(ParValue))
#define biGetGDCLARE1_SAR(ctrlr) (pst_bitGDCLARE1(ctrlr) -> SAR)
#define vSetGDCLARE1_SAR(ctrlr,ParValue)  (pst_bitGDCLARE1(ctrlr) -> SAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCLARE1LL(ctrlr,ParValue) (pst_u8GDCLARE1(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCLARE1LL(ctrlr) (pst_u8GDCLARE1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCLARE1LH(ctrlr,ParValue) (pst_u8GDCLARE1(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCLARE1LH(ctrlr) (pst_u8GDCLARE1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCLARE1HL(ctrlr,ParValue) (pst_u8GDCLARE1(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCLARE1HL(ctrlr) (pst_u8GDCLARE1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCLARE1HH(ctrlr,ParValue) (pst_u8GDCLARE1(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCLARE1HH(ctrlr) (pst_u8GDCLARE1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCLARE1L(ctrlr,ParValue) (pst_u16GDCLARE1(ctrlr) -> u16L = (ParValue))
#define u16GetGDCLARE1L(ctrlr) (pst_u16GDCLARE1(ctrlr) -> u16L)
#define vSetGDCLARE1H(ctrlr,ParValue) (pst_u16GDCLARE1(ctrlr) -> u16H = (ParValue))
#define u16GetGDCLARE1H(ctrlr) (pst_u16GDCLARE1(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCLARE1(ctrlr,ParValue)  (*pu32GDCLARE1(ctrlr) = (ParValue))
#define u32GetGDCLARE1(ctrlr)  (*pu32GDCLARE1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWARC                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02240                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWARC_REG__       0xC0C02240U
#else
#define GDCWARC_REG__ ((uint32_t) GDCWARC_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   WAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCWARC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWARC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWARC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWARC_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWARC(ctrlr)     ((volatile GDCWARC_bit_view_st *)\
(GDCWARC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWARC(ctrlr)     ((volatile GDCWARC_byte_view_st *)\
(GDCWARC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARC(ctrlr)     ((volatile GDCWARC_halfword_view_st *)\
(GDCWARC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWARC(ctrlr)     ((volatile u32GDCWARC_word_view *)\
(GDCWARC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWARC(ctrlr)     ((volatile GDCWARC_bit_view_st *) &u32GDCWARC_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWARC(ctrlr)     ((volatile GDCWARC_byte_view_st *) &u32GDCWARC_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARC(ctrlr)     ((volatile GDCWARC_halfword_view_st *) &u32GDCWARC_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWARC(ctrlr)     ((volatile u32GDCWARC_word_view *) &u32GDCWARC_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWARC_WAR(ctrlr) (pst_bitGDCWARC(ctrlr) -> WAR)
#define vSetGDCWARC_WAR(ctrlr,ParValue)  (pst_bitGDCWARC(ctrlr) -> WAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWARCLL(ctrlr,ParValue) (pst_u8GDCWARC(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWARCLL(ctrlr) (pst_u8GDCWARC(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWARCLH(ctrlr,ParValue) (pst_u8GDCWARC(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWARCLH(ctrlr) (pst_u8GDCWARC(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWARCHL(ctrlr,ParValue) (pst_u8GDCWARC(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWARCHL(ctrlr) (pst_u8GDCWARC(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWARCHH(ctrlr,ParValue) (pst_u8GDCWARC(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWARCHH(ctrlr) (pst_u8GDCWARC(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWARCL(ctrlr,ParValue) (pst_u16GDCWARC(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWARCL(ctrlr) (pst_u16GDCWARC(ctrlr) -> u16L)
#define vSetGDCWARCH(ctrlr,ParValue) (pst_u16GDCWARC(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWARCH(ctrlr) (pst_u16GDCWARC(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWARC(ctrlr,ParValue)  (*pu32GDCWARC(ctrlr) = (ParValue))
#define u32GetGDCWARC(ctrlr)  (*pu32GDCWARC(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWARD                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02248                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWARD_REG__       0xC0C02248U
#else
#define GDCWARD_REG__ ((uint32_t) GDCWARD_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   WAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCWARD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWARD_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWARD_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWARD_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWARD(ctrlr)     ((volatile GDCWARD_bit_view_st *)\
(GDCWARD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWARD(ctrlr)     ((volatile GDCWARD_byte_view_st *)\
(GDCWARD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARD(ctrlr)     ((volatile GDCWARD_halfword_view_st *)\
(GDCWARD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWARD(ctrlr)     ((volatile u32GDCWARD_word_view *)\
(GDCWARD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWARD(ctrlr)     ((volatile GDCWARD_bit_view_st *) &u32GDCWARD_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWARD(ctrlr)     ((volatile GDCWARD_byte_view_st *) &u32GDCWARD_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARD(ctrlr)     ((volatile GDCWARD_halfword_view_st *) &u32GDCWARD_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWARD(ctrlr)     ((volatile u32GDCWARD_word_view *) &u32GDCWARD_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWARD_WAR(ctrlr) (pst_bitGDCWARD(ctrlr) -> WAR)
#define vSetGDCWARD_WAR(ctrlr,ParValue)  (pst_bitGDCWARD(ctrlr) -> WAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWARDLL(ctrlr,ParValue) (pst_u8GDCWARD(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWARDLL(ctrlr) (pst_u8GDCWARD(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWARDLH(ctrlr,ParValue) (pst_u8GDCWARD(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWARDLH(ctrlr) (pst_u8GDCWARD(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWARDHL(ctrlr,ParValue) (pst_u8GDCWARD(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWARDHL(ctrlr) (pst_u8GDCWARD(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWARDHH(ctrlr,ParValue) (pst_u8GDCWARD(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWARDHH(ctrlr) (pst_u8GDCWARD(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWARDL(ctrlr,ParValue) (pst_u16GDCWARD(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWARDL(ctrlr) (pst_u16GDCWARD(ctrlr) -> u16L)
#define vSetGDCWARDH(ctrlr,ParValue) (pst_u16GDCWARD(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWARDH(ctrlr) (pst_u16GDCWARD(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWARD(ctrlr,ParValue)  (*pu32GDCWARD(ctrlr) = (ParValue))
#define u32GetGDCWARD(ctrlr)  (*pu32GDCWARD(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWARE                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02250                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWARE_REG__       0xC0C02250U
#else
#define GDCWARE_REG__ ((uint32_t) GDCWARE_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   WAR	:29; 	 /* 3..31  bit(s) R/W */                    
} GDCWARE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWARE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWARE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWARE_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWARE(ctrlr)     ((volatile GDCWARE_bit_view_st *)\
(GDCWARE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWARE(ctrlr)     ((volatile GDCWARE_byte_view_st *)\
(GDCWARE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARE(ctrlr)     ((volatile GDCWARE_halfword_view_st *)\
(GDCWARE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWARE(ctrlr)     ((volatile u32GDCWARE_word_view *)\
(GDCWARE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWARE(ctrlr)     ((volatile GDCWARE_bit_view_st *) &u32GDCWARE_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWARE(ctrlr)     ((volatile GDCWARE_byte_view_st *) &u32GDCWARE_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWARE(ctrlr)     ((volatile GDCWARE_halfword_view_st *) &u32GDCWARE_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWARE(ctrlr)     ((volatile u32GDCWARE_word_view *) &u32GDCWARE_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWARE_WAR(ctrlr) (pst_bitGDCWARE(ctrlr) -> WAR)
#define vSetGDCWARE_WAR(ctrlr,ParValue)  (pst_bitGDCWARE(ctrlr) -> WAR=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWARELL(ctrlr,ParValue) (pst_u8GDCWARE(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWARELL(ctrlr) (pst_u8GDCWARE(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWARELH(ctrlr,ParValue) (pst_u8GDCWARE(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWARELH(ctrlr) (pst_u8GDCWARE(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWAREHL(ctrlr,ParValue) (pst_u8GDCWARE(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWAREHL(ctrlr) (pst_u8GDCWARE(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWAREHH(ctrlr,ParValue) (pst_u8GDCWARE(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWAREHH(ctrlr) (pst_u8GDCWARE(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWAREL(ctrlr,ParValue) (pst_u16GDCWARE(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWAREL(ctrlr) (pst_u16GDCWARE(ctrlr) -> u16L)
#define vSetGDCWAREH(ctrlr,ParValue) (pst_u16GDCWARE(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWAREH(ctrlr) (pst_u16GDCWARE(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWARE(ctrlr,ParValue)  (*pu32GDCWARE(ctrlr) = (ParValue))
#define u32GetGDCWARE(ctrlr)  (*pu32GDCWARE(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWSRC                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02258                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWSRC_REG__       0xC0C02258U
#else
#define GDCWSRC_REG__ ((uint32_t) GDCWSRC_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WVDS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   WHDS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCWSRC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWSRC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWSRC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWSRC_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWSRC(ctrlr)     ((volatile GDCWSRC_bit_view_st *)\
(GDCWSRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRC(ctrlr)     ((volatile GDCWSRC_byte_view_st *)\
(GDCWSRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRC(ctrlr)     ((volatile GDCWSRC_halfword_view_st *)\
(GDCWSRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWSRC(ctrlr)     ((volatile u32GDCWSRC_word_view *)\
(GDCWSRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWSRC(ctrlr)     ((volatile GDCWSRC_bit_view_st *) &u32GDCWSRC_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRC(ctrlr)     ((volatile GDCWSRC_byte_view_st *) &u32GDCWSRC_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRC(ctrlr)     ((volatile GDCWSRC_halfword_view_st *) &u32GDCWSRC_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWSRC(ctrlr)     ((volatile u32GDCWSRC_word_view *) &u32GDCWSRC_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWSRC_WVDS(ctrlr) (pst_bitGDCWSRC(ctrlr) -> WVDS)
#define vSetGDCWSRC_WVDS(ctrlr,ParValue)  (pst_bitGDCWSRC(ctrlr) -> WVDS=(ParValue))
#define biGetGDCWSRC_WHDS(ctrlr) (pst_bitGDCWSRC(ctrlr) -> WHDS)
#define vSetGDCWSRC_WHDS(ctrlr,ParValue)  (pst_bitGDCWSRC(ctrlr) -> WHDS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWSRCLL(ctrlr,ParValue) (pst_u8GDCWSRC(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWSRCLL(ctrlr) (pst_u8GDCWSRC(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWSRCLH(ctrlr,ParValue) (pst_u8GDCWSRC(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWSRCLH(ctrlr) (pst_u8GDCWSRC(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWSRCHL(ctrlr,ParValue) (pst_u8GDCWSRC(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWSRCHL(ctrlr) (pst_u8GDCWSRC(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWSRCHH(ctrlr,ParValue) (pst_u8GDCWSRC(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWSRCHH(ctrlr) (pst_u8GDCWSRC(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWSRCL(ctrlr,ParValue) (pst_u16GDCWSRC(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWSRCL(ctrlr) (pst_u16GDCWSRC(ctrlr) -> u16L)
#define vSetGDCWSRCH(ctrlr,ParValue) (pst_u16GDCWSRC(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWSRCH(ctrlr) (pst_u16GDCWSRC(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWSRC(ctrlr,ParValue)  (*pu32GDCWSRC(ctrlr) = (ParValue))
#define u32GetGDCWSRC(ctrlr)  (*pu32GDCWSRC(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWSRD                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02260                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWSRD_REG__       0xC0C02260U
#else
#define GDCWSRD_REG__ ((uint32_t) GDCWSRD_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WVDS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   WHDS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCWSRD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWSRD_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWSRD_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWSRD_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWSRD(ctrlr)     ((volatile GDCWSRD_bit_view_st *)\
(GDCWSRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRD(ctrlr)     ((volatile GDCWSRD_byte_view_st *)\
(GDCWSRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRD(ctrlr)     ((volatile GDCWSRD_halfword_view_st *)\
(GDCWSRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWSRD(ctrlr)     ((volatile u32GDCWSRD_word_view *)\
(GDCWSRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWSRD(ctrlr)     ((volatile GDCWSRD_bit_view_st *) &u32GDCWSRD_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRD(ctrlr)     ((volatile GDCWSRD_byte_view_st *) &u32GDCWSRD_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRD(ctrlr)     ((volatile GDCWSRD_halfword_view_st *) &u32GDCWSRD_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWSRD(ctrlr)     ((volatile u32GDCWSRD_word_view *) &u32GDCWSRD_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWSRD_WVDS(ctrlr) (pst_bitGDCWSRD(ctrlr) -> WVDS)
#define vSetGDCWSRD_WVDS(ctrlr,ParValue)  (pst_bitGDCWSRD(ctrlr) -> WVDS=(ParValue))
#define biGetGDCWSRD_WHDS(ctrlr) (pst_bitGDCWSRD(ctrlr) -> WHDS)
#define vSetGDCWSRD_WHDS(ctrlr,ParValue)  (pst_bitGDCWSRD(ctrlr) -> WHDS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWSRDLL(ctrlr,ParValue) (pst_u8GDCWSRD(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWSRDLL(ctrlr) (pst_u8GDCWSRD(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWSRDLH(ctrlr,ParValue) (pst_u8GDCWSRD(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWSRDLH(ctrlr) (pst_u8GDCWSRD(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWSRDHL(ctrlr,ParValue) (pst_u8GDCWSRD(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWSRDHL(ctrlr) (pst_u8GDCWSRD(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWSRDHH(ctrlr,ParValue) (pst_u8GDCWSRD(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWSRDHH(ctrlr) (pst_u8GDCWSRD(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWSRDL(ctrlr,ParValue) (pst_u16GDCWSRD(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWSRDL(ctrlr) (pst_u16GDCWSRD(ctrlr) -> u16L)
#define vSetGDCWSRDH(ctrlr,ParValue) (pst_u16GDCWSRD(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWSRDH(ctrlr) (pst_u16GDCWSRD(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWSRD(ctrlr,ParValue)  (*pu32GDCWSRD(ctrlr) = (ParValue))
#define u32GetGDCWSRD(ctrlr)  (*pu32GDCWSRD(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWSRE                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02268                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWSRE_REG__       0xC0C02268U
#else
#define GDCWSRE_REG__ ((uint32_t) GDCWSRE_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WVDS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   WHDS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCWSRE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWSRE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWSRE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWSRE_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWSRE(ctrlr)     ((volatile GDCWSRE_bit_view_st *)\
(GDCWSRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRE(ctrlr)     ((volatile GDCWSRE_byte_view_st *)\
(GDCWSRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRE(ctrlr)     ((volatile GDCWSRE_halfword_view_st *)\
(GDCWSRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWSRE(ctrlr)     ((volatile u32GDCWSRE_word_view *)\
(GDCWSRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWSRE(ctrlr)     ((volatile GDCWSRE_bit_view_st *) &u32GDCWSRE_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWSRE(ctrlr)     ((volatile GDCWSRE_byte_view_st *) &u32GDCWSRE_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWSRE(ctrlr)     ((volatile GDCWSRE_halfword_view_st *) &u32GDCWSRE_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWSRE(ctrlr)     ((volatile u32GDCWSRE_word_view *) &u32GDCWSRE_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWSRE_WVDS(ctrlr) (pst_bitGDCWSRE(ctrlr) -> WVDS)
#define vSetGDCWSRE_WVDS(ctrlr,ParValue)  (pst_bitGDCWSRE(ctrlr) -> WVDS=(ParValue))
#define biGetGDCWSRE_WHDS(ctrlr) (pst_bitGDCWSRE(ctrlr) -> WHDS)
#define vSetGDCWSRE_WHDS(ctrlr,ParValue)  (pst_bitGDCWSRE(ctrlr) -> WHDS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWSRELL(ctrlr,ParValue) (pst_u8GDCWSRE(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWSRELL(ctrlr) (pst_u8GDCWSRE(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWSRELH(ctrlr,ParValue) (pst_u8GDCWSRE(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWSRELH(ctrlr) (pst_u8GDCWSRE(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWSREHL(ctrlr,ParValue) (pst_u8GDCWSRE(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWSREHL(ctrlr) (pst_u8GDCWSRE(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWSREHH(ctrlr,ParValue) (pst_u8GDCWSRE(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWSREHH(ctrlr) (pst_u8GDCWSRE(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWSREL(ctrlr,ParValue) (pst_u16GDCWSRE(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWSREL(ctrlr) (pst_u16GDCWSRE(ctrlr) -> u16L)
#define vSetGDCWSREH(ctrlr,ParValue) (pst_u16GDCWSRE(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWSREH(ctrlr) (pst_u16GDCWSRE(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWSRE(ctrlr,ParValue)  (*pu32GDCWSRE(ctrlr) = (ParValue))
#define u32GetGDCWSRE(ctrlr)  (*pu32GDCWSRE(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWIMRC                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02270                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWIMRC_REG__       0xC0C02270U
#else
#define GDCWIMRC_REG__ ((uint32_t) GDCWIMRC_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   WWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCWIMRC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWIMRC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWIMRC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWIMRC_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWIMRC(ctrlr)     ((volatile GDCWIMRC_bit_view_st *)\
(GDCWIMRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRC(ctrlr)     ((volatile GDCWIMRC_byte_view_st *)\
(GDCWIMRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRC(ctrlr)     ((volatile GDCWIMRC_halfword_view_st *)\
(GDCWIMRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWIMRC(ctrlr)     ((volatile u32GDCWIMRC_word_view *)\
(GDCWIMRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWIMRC(ctrlr)     ((volatile GDCWIMRC_bit_view_st *) &u32GDCWIMRC_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRC(ctrlr)     ((volatile GDCWIMRC_byte_view_st *) &u32GDCWIMRC_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRC(ctrlr)     ((volatile GDCWIMRC_halfword_view_st *) &u32GDCWIMRC_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWIMRC(ctrlr)     ((volatile u32GDCWIMRC_word_view *) &u32GDCWIMRC_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWIMRC_WHEIGHT(ctrlr) (pst_bitGDCWIMRC(ctrlr) -> WHEIGHT)
#define vSetGDCWIMRC_WHEIGHT(ctrlr,ParValue)  (pst_bitGDCWIMRC(ctrlr) -> WHEIGHT=(ParValue))
#define biGetGDCWIMRC_WWIDTH(ctrlr) (pst_bitGDCWIMRC(ctrlr) -> WWIDTH)
#define vSetGDCWIMRC_WWIDTH(ctrlr,ParValue)  (pst_bitGDCWIMRC(ctrlr) -> WWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWIMRCLL(ctrlr,ParValue) (pst_u8GDCWIMRC(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWIMRCLL(ctrlr) (pst_u8GDCWIMRC(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWIMRCLH(ctrlr,ParValue) (pst_u8GDCWIMRC(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWIMRCLH(ctrlr) (pst_u8GDCWIMRC(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWIMRCHL(ctrlr,ParValue) (pst_u8GDCWIMRC(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWIMRCHL(ctrlr) (pst_u8GDCWIMRC(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWIMRCHH(ctrlr,ParValue) (pst_u8GDCWIMRC(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWIMRCHH(ctrlr) (pst_u8GDCWIMRC(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWIMRCL(ctrlr,ParValue) (pst_u16GDCWIMRC(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWIMRCL(ctrlr) (pst_u16GDCWIMRC(ctrlr) -> u16L)
#define vSetGDCWIMRCH(ctrlr,ParValue) (pst_u16GDCWIMRC(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWIMRCH(ctrlr) (pst_u16GDCWIMRC(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWIMRC(ctrlr,ParValue)  (*pu32GDCWIMRC(ctrlr) = (ParValue))
#define u32GetGDCWIMRC(ctrlr)  (*pu32GDCWIMRC(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWIMRD                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02278                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWIMRD_REG__       0xC0C02278U
#else
#define GDCWIMRD_REG__ ((uint32_t) GDCWIMRD_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   WWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCWIMRD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWIMRD_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWIMRD_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWIMRD_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWIMRD(ctrlr)     ((volatile GDCWIMRD_bit_view_st *)\
(GDCWIMRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRD(ctrlr)     ((volatile GDCWIMRD_byte_view_st *)\
(GDCWIMRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRD(ctrlr)     ((volatile GDCWIMRD_halfword_view_st *)\
(GDCWIMRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWIMRD(ctrlr)     ((volatile u32GDCWIMRD_word_view *)\
(GDCWIMRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWIMRD(ctrlr)     ((volatile GDCWIMRD_bit_view_st *) &u32GDCWIMRD_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRD(ctrlr)     ((volatile GDCWIMRD_byte_view_st *) &u32GDCWIMRD_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRD(ctrlr)     ((volatile GDCWIMRD_halfword_view_st *) &u32GDCWIMRD_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWIMRD(ctrlr)     ((volatile u32GDCWIMRD_word_view *) &u32GDCWIMRD_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWIMRD_WHEIGHT(ctrlr) (pst_bitGDCWIMRD(ctrlr) -> WHEIGHT)
#define vSetGDCWIMRD_WHEIGHT(ctrlr,ParValue)  (pst_bitGDCWIMRD(ctrlr) -> WHEIGHT=(ParValue))
#define biGetGDCWIMRD_WWIDTH(ctrlr) (pst_bitGDCWIMRD(ctrlr) -> WWIDTH)
#define vSetGDCWIMRD_WWIDTH(ctrlr,ParValue)  (pst_bitGDCWIMRD(ctrlr) -> WWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWIMRDLL(ctrlr,ParValue) (pst_u8GDCWIMRD(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWIMRDLL(ctrlr) (pst_u8GDCWIMRD(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWIMRDLH(ctrlr,ParValue) (pst_u8GDCWIMRD(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWIMRDLH(ctrlr) (pst_u8GDCWIMRD(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWIMRDHL(ctrlr,ParValue) (pst_u8GDCWIMRD(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWIMRDHL(ctrlr) (pst_u8GDCWIMRD(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWIMRDHH(ctrlr,ParValue) (pst_u8GDCWIMRD(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWIMRDHH(ctrlr) (pst_u8GDCWIMRD(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWIMRDL(ctrlr,ParValue) (pst_u16GDCWIMRD(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWIMRDL(ctrlr) (pst_u16GDCWIMRD(ctrlr) -> u16L)
#define vSetGDCWIMRDH(ctrlr,ParValue) (pst_u16GDCWIMRD(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWIMRDH(ctrlr) (pst_u16GDCWIMRD(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWIMRD(ctrlr,ParValue)  (*pu32GDCWIMRD(ctrlr) = (ParValue))
#define u32GetGDCWIMRD(ctrlr)  (*pu32GDCWIMRD(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCWIMRE                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02280                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCWIMRE_REG__       0xC0C02280U
#else
#define GDCWIMRE_REG__ ((uint32_t) GDCWIMRE_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   WWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCWIMRE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCWIMRE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCWIMRE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCWIMRE_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCWIMRE(ctrlr)     ((volatile GDCWIMRE_bit_view_st *)\
(GDCWIMRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRE(ctrlr)     ((volatile GDCWIMRE_byte_view_st *)\
(GDCWIMRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRE(ctrlr)     ((volatile GDCWIMRE_halfword_view_st *)\
(GDCWIMRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCWIMRE(ctrlr)     ((volatile u32GDCWIMRE_word_view *)\
(GDCWIMRE_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCWIMRE(ctrlr)     ((volatile GDCWIMRE_bit_view_st *) &u32GDCWIMRE_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCWIMRE(ctrlr)     ((volatile GDCWIMRE_byte_view_st *) &u32GDCWIMRE_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCWIMRE(ctrlr)     ((volatile GDCWIMRE_halfword_view_st *) &u32GDCWIMRE_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCWIMRE(ctrlr)     ((volatile u32GDCWIMRE_word_view *) &u32GDCWIMRE_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCWIMRE_WHEIGHT(ctrlr) (pst_bitGDCWIMRE(ctrlr) -> WHEIGHT)
#define vSetGDCWIMRE_WHEIGHT(ctrlr,ParValue)  (pst_bitGDCWIMRE(ctrlr) -> WHEIGHT=(ParValue))
#define biGetGDCWIMRE_WWIDTH(ctrlr) (pst_bitGDCWIMRE(ctrlr) -> WWIDTH)
#define vSetGDCWIMRE_WWIDTH(ctrlr,ParValue)  (pst_bitGDCWIMRE(ctrlr) -> WWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCWIMRELL(ctrlr,ParValue) (pst_u8GDCWIMRE(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCWIMRELL(ctrlr) (pst_u8GDCWIMRE(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCWIMRELH(ctrlr,ParValue) (pst_u8GDCWIMRE(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCWIMRELH(ctrlr) (pst_u8GDCWIMRE(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCWIMREHL(ctrlr,ParValue) (pst_u8GDCWIMRE(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCWIMREHL(ctrlr) (pst_u8GDCWIMRE(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCWIMREHH(ctrlr,ParValue) (pst_u8GDCWIMRE(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCWIMREHH(ctrlr) (pst_u8GDCWIMRE(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCWIMREL(ctrlr,ParValue) (pst_u16GDCWIMRE(ctrlr) -> u16L = (ParValue))
#define u16GetGDCWIMREL(ctrlr) (pst_u16GDCWIMRE(ctrlr) -> u16L)
#define vSetGDCWIMREH(ctrlr,ParValue) (pst_u16GDCWIMRE(ctrlr) -> u16H = (ParValue))
#define u16GetGDCWIMREH(ctrlr) (pst_u16GDCWIMRE(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCWIMRE(ctrlr,ParValue)  (*pu32GDCWIMRE(ctrlr) = (ParValue))
#define u32GetGDCWIMRE(ctrlr)  (*pu32GDCWIMRE(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCSCVRA                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02288                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCSCVRA_REG__       0xC0C02288U
#else
#define GDCSCVRA_REG__ ((uint32_t) GDCSCVRA_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   CCV0	:24; 	 /* 0..23  bit(s) R/W */
  uint64_t   	:7; 	 /* 24..30  bit(s) R */
  uint64_t   ACT0	:1; 	 /* 31..31  bit(s) R/W */
  uint64_t   CCV1	:24; 	 /* 32..55  bit(s) R/W */
  uint64_t   	:7; 	 /* 56..62  bit(s) R */ 
  uint64_t   ACT1	:1; 	 /* 63..63  bit(s) R/W */                    
} GDCSCVRA_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} GDCSCVRA_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} GDCSCVRA_word_view_st;

/* LONGWORD View */
typedef uint64_t u64GDCSCVRA_longword_view;                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCSCVRA(ctrlr)     ((volatile GDCSCVRA_bit_view_st *)\
(GDCSCVRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16GDCSCVRA(ctrlr)     ((volatile GDCSCVRA_halfword_view_st *)\
(GDCSCVRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32GDCSCVRA(ctrlr)   ((volatile GDCSCVRA_word_view_st *) \
(GDCSCVRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to LONG_WORD  */
#define pu64GDCSCVRA(ctrlr)    ((volatile u64GDCSCVRA_longword_view *)\
(GDCSCVRA_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCSCVRA(ctrlr)     ((volatile GDCSCVRA_bit_view_st *) &u64GDCSCVRA_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCSCVRA(ctrlr)     ((volatile GDCSCVRA_halfword_view_st *) &u64GDCSCVRA_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32GDCSCVRA(ctrlr)   ((volatile GDCSCVRA_word_view_st *) &u64GDCSCVRA_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64GDCSCVRA(ctrlr)    ((volatile u64GDCSCVRA_longword_view *) &u64GDCSCVRA_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCSCVRA_CCV0(ctrlr) (pst_bitGDCSCVRA(ctrlr) -> CCV0)
#define vSetGDCSCVRA_CCV0(ctrlr,ParValue)  (pst_bitGDCSCVRA(ctrlr) -> CCV0=(ParValue))
#define biGetGDCSCVRA_ACT0(ctrlr) (pst_bitGDCSCVRA(ctrlr) -> ACT0)
#define vSetGDCSCVRA_ACT0(ctrlr,ParValue)  (pst_bitGDCSCVRA(ctrlr) -> ACT0=(ParValue))
#define biGetGDCSCVRA_CCV1(ctrlr) (pst_bitGDCSCVRA(ctrlr) -> CCV1)
#define vSetGDCSCVRA_CCV1(ctrlr,ParValue)  (pst_bitGDCSCVRA(ctrlr) -> CCV1=(ParValue))
#define biGetGDCSCVRA_ACT1(ctrlr) (pst_bitGDCSCVRA(ctrlr) -> ACT1)
#define vSetGDCSCVRA_ACT1(ctrlr,ParValue)  (pst_bitGDCSCVRA(ctrlr) -> ACT1=(ParValue))

/* Half-word struct access LL */ 
#define vSetGDCSCVRALL(ctrlr,ParValue) (pst_u16GDCSCVRA(ctrlr) -> u16LL = (ParValue))
#define u16GetGDCSCVRALL(ctrlr) (pst_u16GDCSCVRA(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetGDCSCVRALH(ctrlr,ParValue) (pst_u16GDCSCVRA(ctrlr) -> u16LH = (ParValue))
#define u16GetGDCSCVRALH(ctrlr) (pst_u16GDCSCVRA(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetGDCSCVRAHL(ctrlr,ParValue) (pst_u16GDCSCVRA(ctrlr) -> u16HL = (ParValue))
#define u16GetGDCSCVRAHL(ctrlr) (pst_u16GDCSCVRA(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetGDCSCVRAHH(ctrlr,ParValue) (pst_u16GDCSCVRA(ctrlr) -> u16HH = (ParValue))
#define u16GetGDCSCVRAHH(ctrlr) (pst_u16GDCSCVRA(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetGDCSCVRAL(ctrlr,ParValue) (pst_u32GDCSCVRA(ctrlr) -> u32L= (ParValue))
#define u32GetGDCSCVRAL(ctrlr) (pst_u32GDCSCVRA(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetGDCSCVRAH(ctrlr,ParValue) (pst_u32GDCSCVRA(ctrlr) -> u32H = (ParValue))
#define u32GetGDCSCVRAH(ctrlr) (pst_u32GDCSCVRA(ctrlr) -> u32H)

/* Long  Word access */ 
#define vSetGDCSCVRA(ctrlr,ParValue)  (*pu64GDCSCVRA(ctrlr) = (ParValue))
#define u64GetGDCSCVRA(ctrlr)  (*pu64GDCSCVRA(ctrlr) )

                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCSCVRB                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02290                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                      
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCSCVRB_REG__       0xC0C02290U
#else
#define GDCSCVRB_REG__ ((uint32_t) GDCSCVRB_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   CCV2	:24; 	 /* 0..23  bit(s) R/W */
  uint64_t   	:7; 	 /* 24..30  bit(s) R */
  uint64_t   ACT2	:1; 	 /* 31..31  bit(s) R/W */
  uint64_t   CCV3	:24; 	 /* 32..55  bit(s) R/W */
  uint64_t   	:7; 	 /* 56..62  bit(s) R */ 
  uint64_t   ACT3	:1; 	 /* 63..63  bit(s) R/W */                    
} GDCSCVRB_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} GDCSCVRB_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} GDCSCVRB_word_view_st;

/* LONGWORD View */
typedef uint64_t u64GDCSCVRB_longword_view;



/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCSCVRB(ctrlr)     ((volatile GDCSCVRB_bit_view_st *)\
(GDCSCVRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16GDCSCVRB(ctrlr)     ((volatile GDCSCVRB_halfword_view_st *)\
(GDCSCVRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32GDCSCVRB(ctrlr)   ((volatile GDCSCVRB_word_view_st *) \
(GDCSCVRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to LONG_WORD  */
#define pu64GDCSCVRB(ctrlr)    ((volatile u64GDCSCVRB_longword_view *)\
(GDCSCVRB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCSCVRB(ctrlr)     ((volatile GDCSCVRB_bit_view_st *) &u64GDCSCVRB_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCSCVRB(ctrlr)     ((volatile GDCSCVRB_halfword_view_st *) &u64GDCSCVRB_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32GDCSCVRB(ctrlr)   ((volatile GDCSCVRB_word_view_st *) &u64GDCSCVRB_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64GDCSCVRB(ctrlr)    ((volatile u64GDCSCVRB_longword_view *) &u64GDCSCVRB_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCSCVRB_CCV2(ctrlr) (pst_bitGDCSCVRB(ctrlr) -> CCV2)
#define vSetGDCSCVRB_CCV2(ctrlr,ParValue)  (pst_bitGDCSCVRB(ctrlr) -> CCV2=(ParValue))
#define biGetGDCSCVRB_ACT2(ctrlr) (pst_bitGDCSCVRB(ctrlr) -> ACT2)
#define vSetGDCSCVRB_ACT2(ctrlr,ParValue)  (pst_bitGDCSCVRB(ctrlr) -> ACT2=(ParValue))
#define biGetGDCSCVRB_CCV3(ctrlr) (pst_bitGDCSCVRB(ctrlr) -> CCV3)
#define vSetGDCSCVRB_CCV3(ctrlr,ParValue)  (pst_bitGDCSCVRB(ctrlr) -> CCV3=(ParValue))
#define biGetGDCSCVRB_ACT3(ctrlr) (pst_bitGDCSCVRB(ctrlr) -> ACT3)
#define vSetGDCSCVRB_ACT3(ctrlr,ParValue)  (pst_bitGDCSCVRB(ctrlr) -> ACT3=(ParValue))

/* Half-word struct access LL */ 
#define vSetGDCSCVRBLL(ctrlr,ParValue) (pst_u16GDCSCVRB(ctrlr) -> u16LL = (ParValue))
#define u16GetGDCSCVRBLL(ctrlr) (pst_u16GDCSCVRB(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetGDCSCVRBLH(ctrlr,ParValue) (pst_u16GDCSCVRB(ctrlr) -> u16LH = (ParValue))
#define u16GetGDCSCVRBLH(ctrlr) (pst_u16GDCSCVRB(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetGDCSCVRBHL(ctrlr,ParValue) (pst_u16GDCSCVRB(ctrlr) -> u16HL = (ParValue))
#define u16GetGDCSCVRBHL(ctrlr) (pst_u16GDCSCVRB(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetGDCSCVRBHH(ctrlr,ParValue) (pst_u16GDCSCVRB(ctrlr) -> u16HH = (ParValue))
#define u16GetGDCSCVRBHH(ctrlr) (pst_u16GDCSCVRB(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetGDCSCVRBL(ctrlr,ParValue) (pst_u32GDCSCVRB(ctrlr) -> u32L= (ParValue))
#define u32GetGDCSCVRBL(ctrlr) (pst_u32GDCSCVRB(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetGDCSCVRBH(ctrlr,ParValue) (pst_u32GDCSCVRB(ctrlr) -> u32H = (ParValue))
#define u32GetGDCSCVRBH(ctrlr) (pst_u32GDCSCVRB(ctrlr) -> u32H)

/* Long  Word access */ 
#define vSetGDCSCVRB(ctrlr,ParValue)  (*pu64GDCSCVRB(ctrlr) = (ParValue))
#define u64GetGDCSCVRB(ctrlr)  (*pu64GDCSCVRB(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCSCVRC                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02298                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCSCVRC_REG__       0xC0C02298U
#else
#define GDCSCVRC_REG__ ((uint32_t) GDCSCVRC_REG_EMUL)
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   CCV4	:24; 	 /* 0..23  bit(s) R/W */
  uint64_t   	:7; 	 /* 24..30  bit(s) R */
  uint64_t   ACT4	:1; 	 /* 31..31  bit(s) R/W */
  uint64_t   CCV5	:24; 	 /* 32..55  bit(s) R/W */
  uint64_t   	:7; 	 /* 56..62  bit(s) R */ 
  uint64_t   ACT5	:1; 	 /* 63..63  bit(s) R/W */                    
} GDCSCVRC_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} GDCSCVRC_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} GDCSCVRC_word_view_st;
                 
/* LONGWORD View */
typedef uint64_t u64GDCSCVRC_longword_view;


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCSCVRC(ctrlr)     ((volatile GDCSCVRC_bit_view_st *)\
(GDCSCVRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16GDCSCVRC(ctrlr)     ((volatile GDCSCVRC_halfword_view_st *)\
(GDCSCVRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32GDCSCVRC(ctrlr)   ((volatile GDCSCVRC_word_view_st *) \
(GDCSCVRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to LONG_WORD  */
#define pu64GDCSCVRC(ctrlr)    ((volatile u64GDCSCVRC_longword_view *)\
(GDCSCVRC_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCSCVRC(ctrlr)     ((volatile GDCSCVRC_bit_view_st *) &u64GDCSCVRC_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCSCVRC(ctrlr)     ((volatile GDCSCVRC_halfword_view_st *) &u64GDCSCVRC_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32GDCSCVRC(ctrlr)   ((volatile GDCSCVRC_word_view_st *) &u64GDCSCVRC_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64GDCSCVRC(ctrlr)    ((volatile u64GDCSCVRC_longword_view *) &u64GDCSCVRC_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCSCVRC_CCV4(ctrlr) (pst_bitGDCSCVRC(ctrlr) -> CCV4)
#define vSetGDCSCVRC_CCV4(ctrlr,ParValue)  (pst_bitGDCSCVRC(ctrlr) -> CCV4=(ParValue))
#define biGetGDCSCVRC_ACT4(ctrlr) (pst_bitGDCSCVRC(ctrlr) -> ACT4)
#define vSetGDCSCVRC_ACT4(ctrlr,ParValue)  (pst_bitGDCSCVRC(ctrlr) -> ACT4=(ParValue))
#define biGetGDCSCVRC_CCV5(ctrlr) (pst_bitGDCSCVRC(ctrlr) -> CCV5)
#define vSetGDCSCVRC_CCV5(ctrlr,ParValue)  (pst_bitGDCSCVRC(ctrlr) -> CCV5=(ParValue))
#define biGetGDCSCVRC_ACT5(ctrlr) (pst_bitGDCSCVRC(ctrlr) -> ACT5)
#define vSetGDCSCVRC_ACT5(ctrlr,ParValue)  (pst_bitGDCSCVRC(ctrlr) -> ACT5=(ParValue))

/* Half-word struct access LL */ 
#define vSetGDCSCVRCLL(ctrlr,ParValue) (pst_u16GDCSCVRC(ctrlr) -> u16LL = (ParValue))
#define u16GetGDCSCVRCLL(ctrlr) (pst_u16GDCSCVRC(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetGDCSCVRCLH(ctrlr,ParValue) (pst_u16GDCSCVRC(ctrlr) -> u16LH = (ParValue))
#define u16GetGDCSCVRCLH(ctrlr) (pst_u16GDCSCVRC(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetGDCSCVRCHL(ctrlr,ParValue) (pst_u16GDCSCVRC(ctrlr) -> u16HL = (ParValue))
#define u16GetGDCSCVRCHL(ctrlr) (pst_u16GDCSCVRC(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetGDCSCVRCHH(ctrlr,ParValue) (pst_u16GDCSCVRC(ctrlr) -> u16HH = (ParValue))
#define u16GetGDCSCVRCHH(ctrlr) (pst_u16GDCSCVRC(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetGDCSCVRCL(ctrlr,ParValue) (pst_u32GDCSCVRC(ctrlr) -> u32L= (ParValue))
#define u32GetGDCSCVRCL(ctrlr) (pst_u32GDCSCVRC(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetGDCSCVRCH(ctrlr,ParValue) (pst_u32GDCSCVRC(ctrlr) -> u32H = (ParValue))
#define u32GetGDCSCVRCH(ctrlr) (pst_u32GDCSCVRC(ctrlr) -> u32H)

/* Long  Word access */ 
#define vSetGDCSCVRC(ctrlr,ParValue)  (*pu64GDCSCVRC(ctrlr) = (ParValue))
#define u64GetGDCSCVRC(ctrlr)  (*pu64GDCSCVRC(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCSCVRD                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C022A0                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCSCVRD_REG__       0xC0C022A0U
#else
#define GDCSCVRD_REG__ ((uint32_t) GDCSCVRD_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   CCV6	:24; 	 /* 0..23  bit(s) R/W */
  uint64_t   	:7; 	 /* 24..30  bit(s) R */
  uint64_t   ACT6	:1; 	 /* 31..31  bit(s) R/W */
  uint64_t   CCV7	:24; 	 /* 32..55  bit(s) R/W */
  uint64_t   	:7; 	 /* 56..62  bit(s) R */ 
  uint64_t   ACT7	:1; 	 /* 63..63  bit(s) R/W */                    
} GDCSCVRD_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} GDCSCVRD_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} GDCSCVRD_word_view_st;

/* LONGWORD View */
typedef uint64_t u64GDCSCVRD_longword_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCSCVRD(ctrlr)     ((volatile GDCSCVRD_bit_view_st *)\
(GDCSCVRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16GDCSCVRD(ctrlr)     ((volatile GDCSCVRD_halfword_view_st *)\
(GDCSCVRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32GDCSCVRD(ctrlr)   ((volatile GDCSCVRD_word_view_st *) \
(GDCSCVRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to LONG_WORD  */
#define pu64GDCSCVRD(ctrlr)    ((volatile u64GDCSCVRD_longword_view *)\
(GDCSCVRD_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCSCVRD(ctrlr)     ((volatile GDCSCVRD_bit_view_st *) &u64GDCSCVRD_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCSCVRD(ctrlr)     ((volatile GDCSCVRD_halfword_view_st *) &u64GDCSCVRD_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32GDCSCVRD(ctrlr)   ((volatile GDCSCVRD_word_view_st *)  &u64GDCSCVRD_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64GDCSCVRD(ctrlr)    ((volatile u64GDCSCVRD_longword_view *) &u64GDCSCVRD_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCSCVRD_CCV6(ctrlr) (pst_bitGDCSCVRD(ctrlr) -> CCV6)
#define vSetGDCSCVRD_CCV6(ctrlr,ParValue)  (pst_bitGDCSCVRD(ctrlr) -> CCV6=(ParValue))
#define biGetGDCSCVRD_ACT6(ctrlr) (pst_bitGDCSCVRD(ctrlr) -> ACT6)
#define vSetGDCSCVRD_ACT6(ctrlr,ParValue)  (pst_bitGDCSCVRD(ctrlr) -> ACT6=(ParValue))
#define biGetGDCSCVRD_CCV7(ctrlr) (pst_bitGDCSCVRD(ctrlr) -> CCV7)
#define vSetGDCSCVRD_CCV7(ctrlr,ParValue)  (pst_bitGDCSCVRD(ctrlr) -> CCV7=(ParValue))
#define biGetGDCSCVRD_ACT7(ctrlr) (pst_bitGDCSCVRD(ctrlr) -> ACT7)
#define vSetGDCSCVRD_ACT7(ctrlr,ParValue)  (pst_bitGDCSCVRD(ctrlr) -> ACT7=(ParValue))

/* Half-word struct access LL */ 
#define vSetGDCSCVRDLL(ctrlr,ParValue) (pst_u16GDCSCVRD(ctrlr) -> u16LL = (ParValue))
#define u16GetGDCSCVRDLL(ctrlr) (pst_u16GDCSCVRD(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetGDCSCVRDLH(ctrlr,ParValue) (pst_u16GDCSCVRD(ctrlr) -> u16LH = (ParValue))
#define u16GetGDCSCVRDLH(ctrlr) (pst_u16GDCSCVRD(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetGDCSCVRDHL(ctrlr,ParValue) (pst_u16GDCSCVRD(ctrlr) -> u16HL = (ParValue))
#define u16GetGDCSCVRDHL(ctrlr) (pst_u16GDCSCVRD(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetGDCSCVRDHH(ctrlr,ParValue) (pst_u16GDCSCVRD(ctrlr) -> u16HH = (ParValue))
#define u16GetGDCSCVRDHH(ctrlr) (pst_u16GDCSCVRD(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetGDCSCVRDL(ctrlr,ParValue) (pst_u32GDCSCVRD(ctrlr) -> u32L= (ParValue))
#define u32GetGDCSCVRDL(ctrlr) (pst_u32GDCSCVRD(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetGDCSCVRDH(ctrlr,ParValue) (pst_u32GDCSCVRD(ctrlr) -> u32H = (ParValue))
#define u32GetGDCSCVRDH(ctrlr) (pst_u32GDCSCVRD(ctrlr) -> u32H)

/* Long  Word access */ 
#define vSetGDCSCVRD(ctrlr,ParValue)  (*pu64GDCSCVRD(ctrlr) = (ParValue))
#define u64GetGDCSCVRD(ctrlr)  (*pu64GDCSCVRD(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCGCAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C022A8                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCGCAR_REG__       0xC0C022A8U
#else
#define GDCGCAR_REG__ ((uint32_t) GDCGCAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   GCAR	:16; 	 /* 0..15  bit(s) R/C */                    
} GDCGCAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GDCGCAR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GDCGCAR_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
/* Pointer to BIT-struct */
#define pst_bitGDCGCAR(ctrlr)     ((volatile GDCGCAR_bit_view_st *)\
(GDCGCAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCGCAR(ctrlr)     ((volatile GDCGCAR_byte_view_st *)\
(GDCGCAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD */
#define pu16GDCGCAR(ctrlr)     ((volatile u16GDCGCAR_halfword_view *)\
(GDCGCAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCGCAR_GCAR(ctrlr) (pst_bitGDCGCAR(ctrlr) -> GCAR)
            
/* L-struct byte access */
#define u8GetGDCGCARL(ctrlr) (pst_u8GDCGCAR(ctrlr) -> u8L)
/* H-struct byte access */
#define u8GetGDCGCARH(ctrlr) (pst_u8GDCGCAR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define u16GetGDCGCAR(ctrlr) (*pu16GDCGCAR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCDSR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C022B0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCDSR_REG__       0xC0C022B0U
#else
#define GDCDSR_REG__ ((uint32_t) GDCDSR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DVS	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   DHS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..63  bit(s) R */                    
} GDCDSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCDSR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCDSR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCDSR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCDSR(ctrlr)     ((volatile GDCDSR_bit_view_st *)\
(GDCDSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCDSR(ctrlr)     ((volatile GDCDSR_byte_view_st *)\
(GDCDSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCDSR(ctrlr)     ((volatile GDCDSR_halfword_view_st *)\
(GDCDSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCDSR(ctrlr)     ((volatile u32GDCDSR_word_view *)\
(GDCDSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCDSR(ctrlr)     ((volatile GDCDSR_bit_view_st *) &u32GDCDSR_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCDSR(ctrlr)     ((volatile GDCDSR_byte_view_st *) &u32GDCDSR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCDSR(ctrlr)     ((volatile GDCDSR_halfword_view_st *) &u32GDCDSR_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCDSR(ctrlr)     ((volatile u32GDCDSR_word_view *) &u32GDCDSR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCDSR_DVS(ctrlr) (pst_bitGDCDSR(ctrlr) -> DVS)
#define vSetGDCDSR_DVS(ctrlr,ParValue)  (pst_bitGDCDSR(ctrlr) -> DVS=(ParValue))
#define biGetGDCDSR_DHS(ctrlr) (pst_bitGDCDSR(ctrlr) -> DHS)
#define vSetGDCDSR_DHS(ctrlr,ParValue)  (pst_bitGDCDSR(ctrlr) -> DHS=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCDSRLL(ctrlr,ParValue) (pst_u8GDCDSR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCDSRLL(ctrlr) (pst_u8GDCDSR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCDSRLH(ctrlr,ParValue) (pst_u8GDCDSR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCDSRLH(ctrlr) (pst_u8GDCDSR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCDSRHL(ctrlr,ParValue) (pst_u8GDCDSR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCDSRHL(ctrlr) (pst_u8GDCDSR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCDSRHH(ctrlr,ParValue) (pst_u8GDCDSR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCDSRHH(ctrlr) (pst_u8GDCDSR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCDSRL(ctrlr,ParValue) (pst_u16GDCDSR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCDSRL(ctrlr) (pst_u16GDCDSR(ctrlr) -> u16L)
#define vSetGDCDSRH(ctrlr,ParValue) (pst_u16GDCDSR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCDSRH(ctrlr) (pst_u16GDCDSR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCDSR(ctrlr,ParValue)  (*pu32GDCDSR(ctrlr) = (ParValue))
#define u32GetGDCDSR(ctrlr)  (*pu32GDCDSR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCDIMR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C022B8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCDIMR_REG__       0xC0C022B8U
#else
#define GDCDIMR_REG__ ((uint32_t) GDCDIMR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DHEIGHT	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   DWIDTH	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..63  bit(s) R */                    
} GDCDIMR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCDIMR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCDIMR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCDIMR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCDIMR(ctrlr)     ((volatile GDCDIMR_bit_view_st *)\
(GDCDIMR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCDIMR(ctrlr)     ((volatile GDCDIMR_byte_view_st *)\
(GDCDIMR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCDIMR(ctrlr)     ((volatile GDCDIMR_halfword_view_st *)\
(GDCDIMR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCDIMR(ctrlr)     ((volatile u32GDCDIMR_word_view *)\
(GDCDIMR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCDIMR(ctrlr)     ((volatile GDCDIMR_bit_view_st *) &u32GDCDIMR_REG__Var[(ctrlr)])

/* Pointer to BYTE-struct  */
#define pst_u8GDCDIMR(ctrlr)     ((volatile GDCDIMR_byte_view_st *) &u32GDCDIMR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16GDCDIMR(ctrlr)     ((volatile GDCDIMR_halfword_view_st *) &u32GDCDIMR_REG__Var[(ctrlr)])

/* Pointer to WORD  */ 
#define pu32GDCDIMR(ctrlr)     ((volatile u32GDCDIMR_word_view *) &u32GDCDIMR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCDIMR_DHEIGHT(ctrlr) (pst_bitGDCDIMR(ctrlr) -> DHEIGHT)
#define vSetGDCDIMR_DHEIGHT(ctrlr,ParValue)  (pst_bitGDCDIMR(ctrlr) -> DHEIGHT=(ParValue))
#define biGetGDCDIMR_DWIDTH(ctrlr) (pst_bitGDCDIMR(ctrlr) -> DWIDTH)
#define vSetGDCDIMR_DWIDTH(ctrlr,ParValue)  (pst_bitGDCDIMR(ctrlr) -> DWIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetGDCDIMRLL(ctrlr,ParValue) (pst_u8GDCDIMR(ctrlr) -> u8LL = (ParValue))
#define u8GetGDCDIMRLL(ctrlr) (pst_u8GDCDIMR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetGDCDIMRLH(ctrlr,ParValue) (pst_u8GDCDIMR(ctrlr) -> u8LH = (ParValue))
#define u8GetGDCDIMRLH(ctrlr) (pst_u8GDCDIMR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetGDCDIMRHL(ctrlr,ParValue) (pst_u8GDCDIMR(ctrlr) -> u8HL = (ParValue))
#define u8GetGDCDIMRHL(ctrlr) (pst_u8GDCDIMR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetGDCDIMRHH(ctrlr,ParValue) (pst_u8GDCDIMR(ctrlr) -> u8HH = (ParValue))
#define u8GetGDCDIMRHH(ctrlr) (pst_u8GDCDIMR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGDCDIMRL(ctrlr,ParValue) (pst_u16GDCDIMR(ctrlr) -> u16L = (ParValue))
#define u16GetGDCDIMRL(ctrlr) (pst_u16GDCDIMR(ctrlr) -> u16L)
#define vSetGDCDIMRH(ctrlr,ParValue) (pst_u16GDCDIMR(ctrlr) -> u16H = (ParValue))
#define u16GetGDCDIMRH(ctrlr) (pst_u16GDCDIMR(ctrlr) -> u16H)
            
/* Word access */
#define vSetGDCDIMR(ctrlr,ParValue)  (*pu32GDCDIMR(ctrlr) = (ParValue))
#define u32GetGDCDIMR(ctrlr)  (*pu32GDCDIMR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCPROTR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C022C0                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCPROTR_REG__       0xC0C022C0U
#else
#define GDCPROTR_REG__ ((uint32_t) GDCPROTR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   GDCWPL	:2; 	 /* 0..1  bit(s) R/W */ 
  uint8_t   	:6; 	 /* 2..63  bit(s) R */                    
} GDCPROTR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GDCPROTR_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitGDCPROTR(ctrlr)     ((volatile GDCPROTR_bit_view_st *)\
(GDCPROTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE  */
#define pu8GDCPROTR(ctrlr)     ((volatile u8GDCPROTR_byte_view *)\
(GDCPROTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitGDCPROTR(ctrlr)     ((volatile GDCPROTR_bit_view_st *) &u32GDCPROTR_REG__Var[(ctrlr)])

/* Pointer to BYTE  */
#define pu8GDCPROTR(ctrlr)     ((volatile u8GDCPROTR_byte_view *) GDCPROTR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCPROTR_GDCWPL(ctrlr) (pst_bitGDCPROTR(ctrlr) -> GDCWPL)
#define vSetGDCPROTR_GDCWPL(ctrlr,ParValue)  (pst_bitGDCPROTR(ctrlr) -> GDCWPL=(ParValue))
            
/* byte access */
#define vSetGDCPROTR(ctrlr,ParValue) (*pu8GDCPROTR(ctrlr) = (ParValue))
#define u8GetGDCPROTR(ctrlr) (*pu8GDCPROTR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCGBEAR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C022C8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCGBEAR_REG__       0xC0C022C8U
#else
#define GDCGBEAR_REG__ ((uint32_t) GDCGBEAR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GBADDR	:32; 	 /* 0..31  bit(s) R */                    
} GDCGBEAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCGBEAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCGBEAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCGBEAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
/* Pointer to BIT-struct */
#define pst_bitGDCGBEAR(ctrlr)     ((volatile GDCGBEAR_bit_view_st *)\
(GDCGBEAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCGBEAR(ctrlr)     ((volatile GDCGBEAR_byte_view_st *)\
(GDCGBEAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCGBEAR(ctrlr)     ((volatile GDCGBEAR_halfword_view_st *)\
(GDCGBEAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCGBEAR(ctrlr)     ((volatile u32GDCGBEAR_word_view *)\
(GDCGBEAR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))


/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGDCGBEAR_GBADDR(ctrlr) (pst_bitGDCGBEAR(ctrlr) -> GBADDR)

/* LL-struct byte access */
#define u8GetGDCGBEARLL(ctrlr) (pst_u8GDCGBEAR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define u8GetGDCGBEARLH(ctrlr) (pst_u8GDCGBEAR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define u8GetGDCGBEARHL(ctrlr) (pst_u8GDCGBEAR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define u8GetGDCGBEARHH(ctrlr) (pst_u8GDCGBEAR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGDCGBEARL(ctrlr) (pst_u16GDCGBEAR(ctrlr) -> u16L)
#define u16GetGDCGBEARH(ctrlr) (pst_u16GDCGBEAR(ctrlr) -> u16H)
            
/* Word access */
#define u32GetGDCGBEAR(ctrlr)  (*pu32GDCGBEAR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCGBECR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C022D0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCGBECR_REG__       0xC0C022D0U
#else
#define GDCGBECR_REG__ ((uint32_t) GDCGBECR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WR	:1; 	 /* 0..0  bit(s) R */
  uint32_t   BTYPE	:1; 	 /* 1..1  bit(s) R */
  uint32_t   BSIZE	:3; 	 /* 2..4  bit(s) R */
  uint32_t   RTYPE	:2; 	 /* 5..6  bit(s) R */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   BEN	:8; 	 /* 8..15  bit(s) R */
  uint32_t   ID	:4; 	 /* 16..19  bit(s) R */
  uint32_t   LEN	:4; 	 /* 20..23  bit(s) R */ 
  uint32_t   	:8; 	 /* 24..63  bit(s) R */                    
} GDCGBECR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GDCGBECR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GDCGBECR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GDCGBECR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/

/* Pointer to BIT-struct */
#define pst_bitGDCGBECR(ctrlr)     ((volatile GDCGBECR_bit_view_st *)\
(GDCGBECR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GDCGBECR(ctrlr)     ((volatile GDCGBECR_byte_view_st *)\
(GDCGBECR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GDCGBECR(ctrlr)     ((volatile GDCGBECR_halfword_view_st *)\
(GDCGBECR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to WORD  */ 
#define pu32GDCGBECR(ctrlr)     ((volatile u32GDCGBECR_word_view *)\
(GDCGBECR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGDCGBECR_WR(ctrlr) (pst_bitGDCGBECR(ctrlr) -> WR)            
#define biGetGDCGBECR_BTYPE(ctrlr) (pst_bitGDCGBECR(ctrlr) -> BTYPE)            
#define biGetGDCGBECR_BSIZE(ctrlr) (pst_bitGDCGBECR(ctrlr) -> BSIZE)            
#define biGetGDCGBECR_RTYPE(ctrlr) (pst_bitGDCGBECR(ctrlr) -> RTYPE)            
#define biGetGDCGBECR_BEN(ctrlr) (pst_bitGDCGBECR(ctrlr) -> BEN)            
#define biGetGDCGBECR_ID(ctrlr) (pst_bitGDCGBECR(ctrlr) -> ID)            
#define biGetGDCGBECR_LEN(ctrlr) (pst_bitGDCGBECR(ctrlr) -> LEN)
            
/* LL-struct byte access */
#define u8GetGDCGBECRLL(ctrlr) (pst_u8GDCGBECR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define u8GetGDCGBECRLH(ctrlr) (pst_u8GDCGBECR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define u8GetGDCGBECRHL(ctrlr) (pst_u8GDCGBECR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define u8GetGDCGBECRHH(ctrlr) (pst_u8GDCGBECR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGDCGBECRL(ctrlr) (pst_u16GDCGBECR(ctrlr) -> u16L)
#define u16GetGDCGBECRH(ctrlr) (pst_u16GDCGBECR(ctrlr) -> u16H)
            
/* Word access */
#define u32GetGDCGBECR(ctrlr)  (*pu32GDCGBECR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: APCCR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02300                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                      
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define APCCR_REG__       0xC0C02300U
#else
#define APCCR_REG__ ((uint32_t) &APCCR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   APCCHKFR   :7;      /* 0..6  bit(s) R/W */
  uint64_t   APCCHKERR  :1;      /* 7..7  bit(s) R */
  uint64_t      :22;     /* 8..29  bit(s) R */
  uint64_t   APCAUTO    :1;      /* 30..30  bit(s) R/W */
  uint64_t   APCON  :1;      /* 31..31  bit(s) R/W */
  uint64_t   APCPG  :7;      /* 32..38  bit(s) R/W */
  uint64_t   Reserved   :1;      /* 39..39  bit(s) R */ 
  uint64_t      :24;     /* 40..63  bit(s) R */                    
} APCCR_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} APCCR_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} APCCR_word_view_st;
                 
/* LONGWORD View */
typedef uint64_t u64APCCR_longword_view;


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitAPCCR(ctrlr)     ((volatile APCCR_bit_view_st *)\
(APCCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16APCCR(ctrlr)     ((volatile APCCR_halfword_view_st *)\
(APCCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32APCCR(ctrlr)   ((volatile APCCR_word_view_st *) \
(APCCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to LONG_WORD  */
#define pu64APCCR(ctrlr)    ((volatile u64APCCR_longword_view *)\
(APCCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else
/* Pointer to BIT-struct */
#define pst_bitAPCCR_Direct(ctrlr)     ((volatile APCCR_bit_view_st *)\
(APCCR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to BIT-struct */
#define pst_bitAPCCR(ctrlr)     ((volatile APCCR_bit_view_st *) &u64APCCR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16APCCR(ctrlr)     ((volatile APCCR_halfword_view_st *) &u64APCCR_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32APCCR(ctrlr)   ((volatile APCCR_word_view_st *) &u64APCCR_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64APCCR(ctrlr)    ((volatile u64APCCR_longword_view *) &u64APCCR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetAPCCR_APCCHKFR(ctrlr) (pst_bitAPCCR(ctrlr) -> APCCHKFR)
#define vSetAPCCR_APCCHKFR(ctrlr,ParValue)  (pst_bitAPCCR(ctrlr) -> APCCHKFR=(ParValue))            

/**********************************************************************
 ** "Read Only" signals should be read directly fom shadow register  **
 **********************************************************************/
#define biGetAPCCR_APCCHKERR(ctrlr) (pst_bitAPCCR_Direct(ctrlr) -> APCCHKERR)

#define biGetAPCCR_APCAUTO(ctrlr) (pst_bitAPCCR(ctrlr) -> APCAUTO)
#define vSetAPCCR_APCAUTO(ctrlr,ParValue)  (pst_bitAPCCR(ctrlr) -> APCAUTO=(ParValue))
#define biGetAPCCR_APCON(ctrlr) (pst_bitAPCCR(ctrlr) -> APCON)
#define vSetAPCCR_APCON(ctrlr,ParValue)  (pst_bitAPCCR(ctrlr) -> APCON=(ParValue))
#define biGetAPCCR_APCPG(ctrlr) (pst_bitAPCCR(ctrlr) -> APCPG)
#define vSetAPCCR_APCPG(ctrlr,ParValue)  (pst_bitAPCCR(ctrlr) -> APCPG=(ParValue))            
#define biGetAPCCR_Reserved(ctrlr) (pst_bitAPCCR(ctrlr) -> Reserved)

/* Half-word struct access LL */ 
#define vSetAPCCRLL(ctrlr,ParValue) (pst_u16APCCR(ctrlr) -> u16LL = (ParValue))
#define u16GetAPCCRLL(ctrlr) (pst_u16APCCR(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetAPCCRLH(ctrlr,ParValue) (pst_u16APCCR(ctrlr) -> u16LH = (ParValue))
#define u16GetAPCCRLH(ctrlr) (pst_u16APCCR(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetAPCCRHL(ctrlr,ParValue) (pst_u16APCCR(ctrlr) -> u16HL = (ParValue))
#define u16GetAPCCRHL(ctrlr) (pst_u16APCCR(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetAPCCRHH(ctrlr,ParValue) (pst_u16APCCR(ctrlr) -> u16HH = (ParValue))
#define u16GetAPCCRHH(ctrlr) (pst_u16APCCR(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetAPCCRL(ctrlr,ParValue) (pst_u32APCCR(ctrlr) -> u32L= (ParValue))
#define u32GetAPCCRL(ctrlr) (pst_u32APCCR(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetAPCCRH(ctrlr,ParValue) (pst_u32APCCR(ctrlr) -> u32H = (ParValue))
#define u32GetAPCCRH(ctrlr) (pst_u32APCCR(ctrlr) -> u32H)

/* Long  Word access */ 
#define vSetAPCCR(ctrlr,ParValue)  (*pu64APCCR(ctrlr) = (ParValue))
#define u64GetAPCCR(ctrlr)  (*pu64APCCR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: APCCWR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02308                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define APCCWR_REG__       0xC0C02308U
#else
#define APCCWR_REG__ ((uint32_t) &APCCWR_REG_EMUL)
#endif            
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   VCWS	:11; 	 /* 0..10  bit(s) R/W */
  uint64_t   	:5; 	 /* 11..15  bit(s) R */
  uint64_t   HCWS	:12; 	 /* 16..27  bit(s) R/W */
  uint64_t   	:4; 	 /* 28..31  bit(s) R */
  uint64_t   CWHEIGHT	:7; 	 /* 32..38  bit(s) R/W */
  uint64_t   	:9; 	 /* 39..47  bit(s) R */
  uint64_t   CWWIDTH	:8; 	 /* 48..55  bit(s) R/W */ 
  uint64_t   	:8; 	 /* 56..63  bit(s) R */                    
} APCCWR_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} APCCWR_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} APCCWR_word_view_st;
            
/* LONGWORD View */
typedef uint64_t u64APCCWR_longword_view;
             


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitAPCCWR(ctrlr)     ((volatile APCCWR_bit_view_st *)\
(APCCWR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16APCCWR(ctrlr)     ((volatile APCCWR_halfword_view_st *)\
(APCCWR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32APCCWR(ctrlr)   ((volatile APCCWR_word_view_st *) \
(APCCWR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to LONG_WORD  */
#define pu64APCCWR(ctrlr)    ((volatile u64APCCWR_longword_view *)\
(APCCWR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitAPCCWR(ctrlr)     ((volatile APCCWR_bit_view_st *) &u64APCCWR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16APCCWR(ctrlr)     ((volatile APCCWR_halfword_view_st *) &u64APCCWR_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32APCCWR(ctrlr)   ((volatile APCCWR_word_view_st *)  &u64APCCWR_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64APCCWR(ctrlr)    ((volatile u64APCCWR_longword_view *) &u64APCCWR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetAPCCWR_VCWS(ctrlr) (pst_bitAPCCWR(ctrlr) -> VCWS)
#define vSetAPCCWR_VCWS(ctrlr,ParValue)  (pst_bitAPCCWR(ctrlr) -> VCWS=(ParValue))
#define biGetAPCCWR_HCWS(ctrlr) (pst_bitAPCCWR(ctrlr) -> HCWS)
#define vSetAPCCWR_HCWS(ctrlr,ParValue)  (pst_bitAPCCWR(ctrlr) -> HCWS=(ParValue))
#define biGetAPCCWR_CWHEIGHT(ctrlr) (pst_bitAPCCWR(ctrlr) -> CWHEIGHT)
#define vSetAPCCWR_CWHEIGHT(ctrlr,ParValue)  (pst_bitAPCCWR(ctrlr) -> CWHEIGHT=(ParValue))
#define biGetAPCCWR_CWWIDTH(ctrlr) (pst_bitAPCCWR(ctrlr) -> CWWIDTH)
#define vSetAPCCWR_CWWIDTH(ctrlr,ParValue)  (pst_bitAPCCWR(ctrlr) -> CWWIDTH=(ParValue))

/* Half-word struct access LL */ 
#define vSetAPCCWRLL(ctrlr,ParValue) (pst_u16APCCWR(ctrlr) -> u16LL = (ParValue))
#define u16GetAPCCWRLL(ctrlr) (pst_u16APCCWR(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetAPCCWRLH(ctrlr,ParValue) (pst_u16APCCWR(ctrlr) -> u16LH = (ParValue))
#define u16GetAPCCWRLH(ctrlr) (pst_u16APCCWR(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetAPCCWRHL(ctrlr,ParValue) (pst_u16APCCWR(ctrlr) -> u16HL = (ParValue))
#define u16GetAPCCWRHL(ctrlr) (pst_u16APCCWR(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetAPCCWRHH(ctrlr,ParValue) (pst_u16APCCWR(ctrlr) -> u16HH = (ParValue))
#define u16GetAPCCWRHH(ctrlr) (pst_u16APCCWR(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetAPCCWRL(ctrlr,ParValue) (pst_u32APCCWR(ctrlr) -> u32L= (ParValue))
#define u32GetAPCCWRL(ctrlr) (pst_u32APCCWR(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetAPCCWRH(ctrlr,ParValue) (pst_u32APCCWR(ctrlr) -> u32H = (ParValue))
#define u32GetAPCCWRH(ctrlr) (pst_u32APCCWR(ctrlr) -> u32H)
            
/* Long  Word access */ 
#define vSetAPCCWR(ctrlr,ParValue)  (*pu64APCCWR(ctrlr) = (ParValue))
#define u64GetAPCCWR(ctrlr)  (*pu64APCCWR(ctrlr) )
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: APCCSR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02310                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define APCCSR_REG__       0xC0C02310U
#else
#define APCCSR_REG__ ((uint32_t) &APCCSR_REG_EMUL)
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   CURCHKSUM	:22; 	 /* 0..21  bit(s) R/C */
  uint64_t   	:10; 	 /* 22..31  bit(s) R */
  uint64_t   EXPCHKSUM	:22; 	 /* 32..53  bit(s) R/W */ 
  uint64_t   	:10; 	 /* 54..63  bit(s) R */                    
} APCCSR_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} APCCSR_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} APCCSR_word_view_st;
            
/* LONGWORD View */
typedef uint64_t u64APCCSR_longword_view;
             


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitAPCCSR(ctrlr)     ((volatile APCCSR_bit_view_st *)\
(APCCSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16APCCSR(ctrlr)     ((volatile APCCSR_halfword_view_st *)\
(APCCSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32APCCSR(ctrlr)   ((volatile APCCSR_word_view_st *) \
(APCCSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to LONG_WORD  */
#define pu64APCCSR(ctrlr)    ((volatile u64APCCSR_longword_view *)\
(APCCSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct of shadow register:*/
#define pst_bitAPCCSR_Direct(ctrlr)     ((volatile APCCSR_bit_view_st *)\
(APCCSR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))

/* Pointer to BIT-struct */
#define pst_bitAPCCSR(ctrlr)     ((volatile APCCSR_bit_view_st *) &u64APCCSR_REG__Var[(ctrlr)])

/* Pointer to HALFWORD-struct */
#define pst_u16APCCSR(ctrlr)     ((volatile APCCSR_halfword_view_st *) &u64APCCSR_REG__Var[(ctrlr)])

/* Pointer to WORD-struct  */ 
#define pst_u32APCCSR(ctrlr)   ((volatile APCCSR_word_view_st *)  &APCCSR_REG__Var[(ctrlr)])

/* Pointer to LONG_WORD  */
#define pu64APCCSR(ctrlr)    ((volatile u64APCCSR_longword_view *)&u64APCCSR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */

/**********************************************************************
 ** "Read Only" signals should be read directly fom shadow register  **
 **********************************************************************/
#define biGetAPCCSR_CURCHKSUM(ctrlr) (pst_bitAPCCSR_Direct(ctrlr) -> CURCHKSUM)
/**********************************************************************/
/* CURCHKSUM is R/C bit, no SET:
#define vSetAPCCSR_CURCHKSUM(ctrlr) (pst_bitAPCCSR(ctrlr) -> CURCHKSUM=(0))
*/
#define biGetAPCCSR_EXPCHKSUM(ctrlr) (pst_bitAPCCSR(ctrlr) -> EXPCHKSUM)
#define vSetAPCCSR_EXPCHKSUM(ctrlr,ParValue)  (pst_bitAPCCSR(ctrlr) -> EXPCHKSUM=(ParValue))

/* Half-word struct access LL */ 
#define vSetAPCCSRLL(ctrlr,ParValue) (pst_u16APCCSR(ctrlr) -> u16LL = (ParValue))
#define u16GetAPCCSRLL(ctrlr) (pst_u16APCCSR(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define vSetAPCCSRLH(ctrlr,ParValue) (pst_u16APCCSR(ctrlr) -> u16LH = (ParValue))
#define u16GetAPCCSRLH(ctrlr) (pst_u16APCCSR(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define vSetAPCCSRHL(ctrlr,ParValue) (pst_u16APCCSR(ctrlr) -> u16HL = (ParValue))
#define u16GetAPCCSRHL(ctrlr) (pst_u16APCCSR(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define vSetAPCCSRHH(ctrlr,ParValue) (pst_u16APCCSR(ctrlr) -> u16HH = (ParValue))
#define u16GetAPCCSRHH(ctrlr) (pst_u16APCCSR(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define vSetAPCCSRL(ctrlr,ParValue) (pst_u32APCCSR(ctrlr) -> u32L= (ParValue))
#define u32GetAPCCSRL(ctrlr) (pst_u32APCCSR(ctrlr) -> u32L)
/* Word-struct access H */
#define vSetAPCCSRH(ctrlr,ParValue) (pst_u32APCCSR(ctrlr) -> u32H = (ParValue))
#define u32GetAPCCSRH(ctrlr) (pst_u32APCCSR(ctrlr) -> u32H)
            
/* Long  Word access */ 
#define vSetAPCCSR(ctrlr,ParValue)  (*pu64APCCSR(ctrlr) = (ParValue))
#define u64GetAPCCSR(ctrlr)  (*pu64APCCSR(ctrlr) )
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: APCPVR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02318                             
*       ACCESS  : 8, 16, 32, 64, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define APCPVR_REG__       0xC0C02318U
#else
#define APCPVR_REG__ ((uint32_t) &APCPVR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint64_t   BLUEL	:8; 	 /* 0..7  bit(s) R */
  uint64_t   GREENL	:8; 	 /* 8..15  bit(s) R */
  uint64_t   REDL	:8; 	 /* 16..23  bit(s) R */
  uint64_t   	:8; 	 /* 24..31  bit(s) R */
  uint64_t   BLUEP	:8; 	 /* 32..39  bit(s) R */
  uint64_t   GREENP	:8; 	 /* 40..47  bit(s) R */
  uint64_t   REDP	:8; 	 /* 48..55  bit(s) R */ 
  uint64_t   	:8; 	 /* 56..63  bit(s) R */                    
} APCPVR_bit_view_st;
        

/* HALFWORD View */
typedef struct{      
  uint16_t u16LL;    
  uint16_t u16LH;    
  uint16_t u16HL;    
  uint16_t u16HH;    
} APCPVR_halfword_view_st;
            
/* WORD View */
typedef struct{      
  uint32_t u32L;     
  uint32_t u32H;     
} APCPVR_word_view_st;
            
/* LONGWORD View */
typedef uint64_t u64APCPVR_longword_view;
             


/************************     ACCESS POINTERS     ****************************/

/* Pointer to BIT-struct */
#define pst_bitAPCPVR(ctrlr)     ((volatile APCPVR_bit_view_st *)\
(APCPVR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to HALFWORD-struct */
#define pst_u16APCPVR(ctrlr)     ((volatile APCPVR_halfword_view_st *)\
(APCPVR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
             
/* Pointer to WORD-struct  */ 
#define pst_u32APCPVR(ctrlr)   ((volatile APCPVR_word_view_st *) \
(APCPVR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
            
/* Pointer to LONG_WORD  */
#define pu64APCPVR(ctrlr)    ((volatile u64APCPVR_longword_view *)\
(APCPVR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))


/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetAPCPVR_BLUEL(ctrlr) (pst_bitAPCPVR(ctrlr) -> BLUEL)            
#define biGetAPCPVR_GREENL(ctrlr) (pst_bitAPCPVR(ctrlr) -> GREENL)            
#define biGetAPCPVR_REDL(ctrlr) (pst_bitAPCPVR(ctrlr) -> REDL)            
#define biGetAPCPVR_BLUEP(ctrlr) (pst_bitAPCPVR(ctrlr) -> BLUEP)            
#define biGetAPCPVR_GREENP(ctrlr) (pst_bitAPCPVR(ctrlr) -> GREENP)            
#define biGetAPCPVR_REDP(ctrlr) (pst_bitAPCPVR(ctrlr) -> REDP)

/* Half-word struct access LL */ 
#define u16GetAPCPVRLL(ctrlr) (pst_u16APCPVR(ctrlr) -> u16LL)
/* Half-word struct access LH */ 
#define u16GetAPCPVRLH(ctrlr) (pst_u16APCPVR(ctrlr) -> u16LH)
/* Half-word struct access HL */ 
#define u16GetAPCPVRHL(ctrlr) (pst_u16APCPVR(ctrlr) -> u16HL)
/* Half-word struct access HH */ 
#define u16GetAPCPVRHH(ctrlr) (pst_u16APCPVR(ctrlr) -> u16HH)
                      
            
/* Word-struct access L */
#define u32GetAPCPVRL(ctrlr) (pst_u32APCPVR(ctrlr) -> u32L)
/* Word-struct access H */
#define u32GetAPCPVRH(ctrlr) (pst_u32APCPVR(ctrlr) -> u32H)
            
/* Long  Word access */ 
#define u64GetAPCPVR(ctrlr)  (*pu64APCPVR(ctrlr) )
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: APCPROTR                                
*       SIZE    : 64-bits                        
*       ADDRESS : 0xC0C02320                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define APCPROTR_REG__       0xC0C02320U
#else
#define APCPROTR_REG__ ((uint32_t) &APCPROTR_REG_EMUL)
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   APCWPL	:2; 	 /* 0..1  bit(s) R/W */ 
  uint8_t   	:6; 	 /* 2..63  bit(s) R */                    
} APCPROTR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8APCPROTR_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
#if 0
/* Pointer to BIT-struct */
#define pst_bitAPCPROTR(ctrlr)     ((volatile APCPROTR_bit_view_st *)\
(APCPROTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
        
/* Pointer to BYTE  */
#define pu8APCPROTR(ctrlr)     ((volatile u8APCPROTR_byte_view *)\
(APCPROTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET) ))
#else

/* Pointer to BIT-struct */
#define pst_bitAPCPROTR(ctrlr)     ((volatile APCPROTR_bit_view_st *) &u32APCPROTR_REG__Var[(ctrlr)])

/* Pointer to BYTE  */
#define pu8APCPROTR(ctrlr)     ((volatile u8APCPROTR_byte_view *) &u32APCPROTR_REG__Var[(ctrlr)])

#endif
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetAPCPROTR_APCWPL(ctrlr) (pst_bitAPCPROTR(ctrlr) -> APCWPL)
#define vSetAPCPROTR_APCWPL(ctrlr,ParValue)  (pst_bitAPCPROTR(ctrlr) -> APCWPL=(ParValue))
            
/* byte access */
#define vSetAPCPROTR(ctrlr,ParValue) (*pu8APCPROTR(ctrlr) = (ParValue))
#define u8GetAPCPROTR(ctrlr) (*pu8APCPROTR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCCCLUTR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0C02400                             
*       ACCESS  : 8, BIT-level
*
*****************************************************************************/
/*NOTE!: This register is NOT a SHADOW-Register!:*/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCCCLUTR_REG__       0xC0C02400U
#else
#define GDCCCLUTR_REG__ ((uint32_t) &GDCCCLUTR_REG_EMUL[0])
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   CCV	:8; 	 /* 0..7  bit(s) R/W */                    
} GDCCCLUTR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GDCCCLUTR_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/

/* Pointer to BIT-struct */
#define pst_bitGDCCCLUTR(ctrlr,ch)     ((volatile GDCCCLUTR_bit_view_st *)\
(GDCCCLUTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET)  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE  */
#define pu8GDCCCLUTR(ctrlr,ch)     ((volatile u8GDCCCLUTR_byte_view *)\
(GDCCCLUTR_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET)  + ((uint16_t)(ch) * 0x4U)))


/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE WILL NOT BE APPLIED */
/* Bit-struct access */
#define biGetGDCCCLUTR_CCV(ctrlr,ch) (pst_bitGDCCCLUTR((ctrlr),(ch)) -> CCV)
#define vSetGDCCCLUTR_CCV(ctrlr,ch,ParValue)  (pst_bitGDCCCLUTR((ctrlr),(ch)) -> CCV=(ParValue))
            
/* byte access */
#define vSetGDCCCLUTR(ctrlr,ch,ParValue) (*pu8GDCCCLUTR((ctrlr),(ch)) = (ParValue))
#define u8GetGDCCCLUTR(ctrlr,ch) (*pu8GDCCCLUTR((ctrlr),(ch)) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCCCLUTG                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0C02800                             
*       ACCESS  : 8, BIT-level
* 
*****************************************************************************/
/*NOTE!: This register is NOT a SHADOW-Register!:*/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCCCLUTG_REG__       0xC0C02800U
#else
#define GDCCCLUTG_REG__ ((uint32_t) &GDCCCLUTG_REG_EMUL[0])
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   CCV	:8; 	 /* 0..7  bit(s) R/W */                    
} GDCCCLUTG_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GDCCCLUTG_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/

/* Pointer to BIT-struct */
#define pst_bitGDCCCLUTG(ctrlr,ch)     ((volatile GDCCCLUTG_bit_view_st *)\
(GDCCCLUTG_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET)  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE  */
#define pu8GDCCCLUTG(ctrlr,ch)     ((volatile u8GDCCCLUTG_byte_view *)\
(GDCCCLUTG_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET)  + ((uint16_t)(ch) * 0x4U)))


/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCCCLUTG_CCV(ctrlr,ch) (pst_bitGDCCCLUTG((ctrlr),(ch)) -> CCV)
#define vSetGDCCCLUTG_CCV(ctrlr,ch,ParValue)  (pst_bitGDCCCLUTG((ctrlr),(ch)) -> CCV=(ParValue))
            
/* byte access */
#define vSetGDCCCLUTG(ctrlr,ch,ParValue) (*pu8GDCCCLUTG((ctrlr),(ch)) = (ParValue))
#define u8GetGDCCCLUTG(ctrlr,ch) (*pu8GDCCCLUTG((ctrlr),(ch)) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GDCCCLUTB                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0C02C00                             
*       ACCESS  : 8, BIT-level
*
*****************************************************************************/
/*NOTE!: This register is NOT a SHADOW-Register!:*/
/* Assign Register address: */
#ifndef HW_EMULATION_GDC
#define GDCCCLUTB_REG__       0xC0C02C00U
#else
#define GDCCCLUTB_REG__ ((uint32_t) &GDCCCLUTB_REG_EMUL[0])
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   CCV	:8; 	 /* 0..7  bit(s) R/W */                    
} GDCCCLUTB_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GDCCCLUTB_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/

/* Pointer to BIT-struct */
#define pst_bitGDCCCLUTB(ctrlr,ch)     ((volatile GDCCCLUTB_bit_view_st *)\
(GDCCCLUTB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET)  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE  */
#define pu8GDCCCLUTB(ctrlr,ch)     ((volatile u8GDCCCLUTB_byte_view *)\
(GDCCCLUTB_REG__  + ((uint8_t)(ctrlr) * GDC1_REGADR_OFFSET)  + ((uint16_t)(ch) * 0x4U)))


/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGDCCCLUTB_CCV(ctrlr,ch) (pst_bitGDCCCLUTB((ctrlr),(ch)) -> CCV)
#define vSetGDCCCLUTB_CCV(ctrlr,ch,ParValue)  (pst_bitGDCCCLUTB((ctrlr),(ch)) -> CCV=(ParValue))
            
/* byte access */
#define vSetGDCCCLUTB(ctrlr,ch,ParValue) (*pu8GDCCCLUTB((ctrlr),(ch)) = (ParValue))
#define u8GetGDCCCLUTB(ctrlr,ch) (*pu8GDCCCLUTB((ctrlr),(ch)) )
            
/****************************************************************************/

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/
/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

#endif /* GDC_IO_H */ 

/****************************************************************************/


/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: gdc_io.c
**  $Revision: 1.12 $
**  $Date: 2015/05/04 09:07:16 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 230 / 6.4 - bitwise operation may not be performed on signed integer types
** | CONS.  : allow
** | REASON : to use macros generated by converter tool 
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/


/************************** BEGIN of DISCLAIMER   ************************* 

- TOSHIBA is continually working to improve the quality and reliability of 
  its products. Nevertheless, semiconductor devices in general can 
  malfunction or fail due to their inherent electrical sensitivity and  
  vulnerability to physical stress. It is the responsibility of the buyer, 
  when utilizing TOSHIBA products, to comply with the standards of safety 
  in making a safe design for the entire system, and to avoid situations in 
  which a malfunction or failure of such TOSHIBA products could cause loss of 
  human life, bodily injury or damage to property. 
  
  In developing your designs, please ensure that TOSHIBA products are used 
  within specified operating ranges as set forth in the most recent TOSHIBA 
  products specifications. 
  Also, please keep in mind the precautions and conditions set forth in the 
  Handling Guide for Semiconductor Devices, or 
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in 
  general electronics applications (computer, personal equipment, office 
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.). 
  These Toshiba products are neither intended nor warranted for usage in 
  equipment that requires extraordinarily high quality and/or reliability or 
  a malfunction or failure of which may cause loss of human life or bodily 
  injury (Unintended Usage). Unintended Usage include atomic energy control 
  instruments, airplane or spaceship instruments, transportation instruments, 
  traffic signal instruments, combustion control instruments, medical 
  instruments, all types of safety devices, etc.. 
  Unintended Usage of Toshiba products listed in this document shall be 
  made at the customers own risk. 

- Toshiba assumes no liability for any damage or losses (including but not 
  limited to, loss of business profit,business interruption, loss of business 
  information,and other pecuniary losses) occurring 
  from the use of, or inability to use, this product. 

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

