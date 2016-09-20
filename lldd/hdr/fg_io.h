
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : FG 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:51:46.292+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.11 $ 
/  Excel Sheet ver.             : vv1.4
/  Excel Sheet date             : 2013-Jun-19
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : FG low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : FG
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.11 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef FGIO_H
#define FGIO_H
/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */

/*********************************************/
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 230    /* Rule 6.4 [R] : 	nonstandard type for a bit field */
  #pragma ghs nowarning 1840   /* Rule 5.7 [A] : identifier reused from declaration of entity-kind "entity" */
#endif
/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_FG_IO_H_REVISION     "$Revision: 1.11 $"
#define LLDD_FG_IO_H_TAG          "$Name: LLDD_1_7_GFX $"     
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGDCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGDCR_REG__       0xC0C08000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   FODDS	:1; 	 /* 0..0  bit(s) R */
  uint32_t   NFODD	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   	:2; 	 /* 2..3  bit(s) R */
  uint32_t   NEGPC	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   	:2; 	 /* 5..6  bit(s) R */
  uint32_t   ONEC	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   HSACT	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   VSACT	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   HDACT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   UDSP	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   USYNC	:1; 	 /* 12..12  bit(s) R/W */
  uint32_t   	:1; 	 /* 13..13  bit(s) R */
  uint32_t   SYCBCR	:1; 	 /* 14..14  bit(s) R/W */
  uint32_t   SCBCR	:1; 	 /* 15..15  bit(s) R/W */
  uint32_t   COMD	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   CVMD	:1; 	 /* 17..17  bit(s) R/W */
  uint32_t   MONO	:1; 	 /* 18..18  bit(s) R/W */
  uint32_t   BWEX	:1; 	 /* 19..19  bit(s) R/W */
  uint32_t   RRGB	:1; 	 /* 20..20  bit(s) R/W */
  uint32_t   YCBRO	:1; 	 /* 21..21  bit(s) R/W */
  uint32_t   INT	:1; 	 /* 22..22  bit(s) R/W */
  uint32_t   DINT	:1; 	 /* 23..23  bit(s) R/W */
  uint32_t   NVMD	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   RGB24	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   RGBPA	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CCEN	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   	:1; 	 /* 28..28  bit(s) R */
  uint32_t   CREN	:1; 	 /* 29..29  bit(s) R/W */
  uint32_t   	:1; 	 /* 30..30  bit(s) R */ 
  uint32_t   FGACT	:1; 	 /* 31..31  bit(s) R/W */                    
} FGDCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGDCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGDCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGDCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGDCR()     ((volatile FGDCR_bit_view_st *)\
(FGDCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGDCR()     ((volatile FGDCR_byte_view_st *)\
(FGDCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGDCR()     ((volatile FGDCR_halfword_view_st *)\
(FGDCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGDCR()     ((volatile u32FGDCR_word_view *)\
(FGDCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetFGDCR_FODDS() (pst_bitFGDCR() -> FODDS)
#define biGetFGDCR_NFODD() (pst_bitFGDCR() -> NFODD)
#define vSetFGDCR_NFODD(ParValue)  (pst_bitFGDCR() -> NFODD=(ParValue))
#define biGetFGDCR_NEGPC() (pst_bitFGDCR() -> NEGPC)
#define vSetFGDCR_NEGPC(ParValue)  (pst_bitFGDCR() -> NEGPC=(ParValue))
#define biGetFGDCR_ONEC() (pst_bitFGDCR() -> ONEC)
#define vSetFGDCR_ONEC(ParValue)  (pst_bitFGDCR() -> ONEC=(ParValue))
#define biGetFGDCR_HSACT() (pst_bitFGDCR() -> HSACT)
#define vSetFGDCR_HSACT(ParValue)  (pst_bitFGDCR() -> HSACT=(ParValue))
#define biGetFGDCR_VSACT() (pst_bitFGDCR() -> VSACT)
#define vSetFGDCR_VSACT(ParValue)  (pst_bitFGDCR() -> VSACT=(ParValue))
#define biGetFGDCR_HDACT() (pst_bitFGDCR() -> HDACT)
#define vSetFGDCR_HDACT(ParValue)  (pst_bitFGDCR() -> HDACT=(ParValue))
#define biGetFGDCR_UDSP() (pst_bitFGDCR() -> UDSP)
#define vSetFGDCR_UDSP(ParValue)  (pst_bitFGDCR() -> UDSP=(ParValue))
#define biGetFGDCR_USYNC() (pst_bitFGDCR() -> USYNC)
#define vSetFGDCR_USYNC(ParValue)  (pst_bitFGDCR() -> USYNC=(ParValue))
#define biGetFGDCR_SYCBCR() (pst_bitFGDCR() -> SYCBCR)
#define vSetFGDCR_SYCBCR(ParValue)  (pst_bitFGDCR() -> SYCBCR=(ParValue))
#define biGetFGDCR_SCBCR() (pst_bitFGDCR() -> SCBCR)
#define vSetFGDCR_SCBCR(ParValue)  (pst_bitFGDCR() -> SCBCR=(ParValue))
#define biGetFGDCR_COMD() (pst_bitFGDCR() -> COMD)
#define vSetFGDCR_COMD(ParValue)  (pst_bitFGDCR() -> COMD=(ParValue))
#define biGetFGDCR_CVMD() (pst_bitFGDCR() -> CVMD)
#define vSetFGDCR_CVMD(ParValue)  (pst_bitFGDCR() -> CVMD=(ParValue))
#define biGetFGDCR_MONO() (pst_bitFGDCR() -> MONO)
#define vSetFGDCR_MONO(ParValue)  (pst_bitFGDCR() -> MONO=(ParValue))
#define biGetFGDCR_BWEX() (pst_bitFGDCR() -> BWEX)
#define vSetFGDCR_BWEX(ParValue)  (pst_bitFGDCR() -> BWEX=(ParValue))
#define biGetFGDCR_RRGB() (pst_bitFGDCR() -> RRGB)
#define vSetFGDCR_RRGB(ParValue)  (pst_bitFGDCR() -> RRGB=(ParValue))
#define biGetFGDCR_YCBRO() (pst_bitFGDCR() -> YCBRO)
#define vSetFGDCR_YCBRO(ParValue)  (pst_bitFGDCR() -> YCBRO=(ParValue))
#define biGetFGDCR_INT() (pst_bitFGDCR() -> INT)
#define vSetFGDCR_INT(ParValue)  (pst_bitFGDCR() -> INT=(ParValue))
#define biGetFGDCR_DINT() (pst_bitFGDCR() -> DINT)
#define vSetFGDCR_DINT(ParValue)  (pst_bitFGDCR() -> DINT=(ParValue))
#define biGetFGDCR_NVMD() (pst_bitFGDCR() -> NVMD)
#define vSetFGDCR_NVMD(ParValue)  (pst_bitFGDCR() -> NVMD=(ParValue))
#define biGetFGDCR_RGB24() (pst_bitFGDCR() -> RGB24)
#define vSetFGDCR_RGB24(ParValue)  (pst_bitFGDCR() -> RGB24=(ParValue))
#define biGetFGDCR_RGBPA() (pst_bitFGDCR() -> RGBPA)
#define vSetFGDCR_RGBPA(ParValue)  (pst_bitFGDCR() -> RGBPA=(ParValue))
#define biGetFGDCR_CCEN() (pst_bitFGDCR() -> CCEN)
#define vSetFGDCR_CCEN(ParValue)  (pst_bitFGDCR() -> CCEN=(ParValue))
#define biGetFGDCR_CREN() (pst_bitFGDCR() -> CREN)
#define vSetFGDCR_CREN(ParValue)  (pst_bitFGDCR() -> CREN=(ParValue))
#define biGetFGDCR_FGACT() (pst_bitFGDCR() -> FGACT)
#define vSetFGDCR_FGACT(ParValue)  (pst_bitFGDCR() -> FGACT=(ParValue))
            
/* LL-struct byte access */
#define vSetFGDCRLL(ParValue) (pst_u8FGDCR() -> u8LL = (ParValue))
#define u8GetFGDCRLL() (pst_u8FGDCR() -> u8LL)
/* LH-struct byte access */
#define vSetFGDCRLH(ParValue) (pst_u8FGDCR() -> u8LH = (ParValue))
#define u8GetFGDCRLH() (pst_u8FGDCR() -> u8LH)
/* HL-struct byte access */
#define vSetFGDCRHL(ParValue) (pst_u8FGDCR() -> u8HL = (ParValue))
#define u8GetFGDCRHL() (pst_u8FGDCR() -> u8HL)
/* HH-struct byte access */
#define vSetFGDCRHH(ParValue) (pst_u8FGDCR() -> u8HH = (ParValue))
#define u8GetFGDCRHH() (pst_u8FGDCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGDCRL(ParValue) (pst_u16FGDCR() -> u16L = (ParValue))
#define u16GetFGDCRL() (pst_u16FGDCR() -> u16L)
#define vSetFGDCRH(ParValue) (pst_u16FGDCR() -> u16H = (ParValue))
#define u16GetFGDCRH() (pst_u16FGDCR() -> u16H)
            
/* Word access */
#define vSetFGDCR(ParValue)  (*pu32FGDCR() = (ParValue))
#define u32GetFGDCR()  (*pu32FGDCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGIDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGIDR_REG__       0xC0C08004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   HEIGHT	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   WIDTH	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..31  bit(s) R */                    
} FGIDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGIDR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGIDR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGIDR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGIDR()     ((volatile FGIDR_bit_view_st *)\
(FGIDR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGIDR()     ((volatile FGIDR_byte_view_st *)\
(FGIDR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGIDR()     ((volatile FGIDR_halfword_view_st *)\
(FGIDR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGIDR()     ((volatile u32FGIDR_word_view *)\
(FGIDR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGIDR_HEIGHT() (pst_bitFGIDR() -> HEIGHT)
#define vSetFGIDR_HEIGHT(ParValue)  (pst_bitFGIDR() -> HEIGHT=(ParValue))
#define biGetFGIDR_WIDTH() (pst_bitFGIDR() -> WIDTH)
#define vSetFGIDR_WIDTH(ParValue)  (pst_bitFGIDR() -> WIDTH=(ParValue))
            
/* LL-struct byte access */
#define vSetFGIDRLL(ParValue) (pst_u8FGIDR() -> u8LL = (ParValue))
#define u8GetFGIDRLL() (pst_u8FGIDR() -> u8LL)
/* LH-struct byte access */
#define vSetFGIDRLH(ParValue) (pst_u8FGIDR() -> u8LH = (ParValue))
#define u8GetFGIDRLH() (pst_u8FGIDR() -> u8LH)
/* HL-struct byte access */
#define vSetFGIDRHL(ParValue) (pst_u8FGIDR() -> u8HL = (ParValue))
#define u8GetFGIDRHL() (pst_u8FGIDR() -> u8HL)
/* HH-struct byte access */
#define vSetFGIDRHH(ParValue) (pst_u8FGIDR() -> u8HH = (ParValue))
#define u8GetFGIDRHH() (pst_u8FGIDR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGIDRL(ParValue) (pst_u16FGIDR() -> u16L = (ParValue))
#define u16GetFGIDRL() (pst_u16FGIDR() -> u16L)
#define vSetFGIDRH(ParValue) (pst_u16FGIDR() -> u16H = (ParValue))
#define u16GetFGIDRH() (pst_u16FGIDR() -> u16H)
            
/* Word access */
#define vSetFGIDR(ParValue)  (*pu32FGIDR() = (ParValue))
#define u32GetFGIDR()  (*pu32FGIDR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGITR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGITR_REG__       0xC0C08008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   VWAIT	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   HWAIT	:10; 	 /* 16..25  bit(s) R/W */ 
  uint32_t   	:6; 	 /* 26..31  bit(s) R */                    
} FGITR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGITR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGITR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGITR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGITR()     ((volatile FGITR_bit_view_st *)\
(FGITR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGITR()     ((volatile FGITR_byte_view_st *)\
(FGITR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGITR()     ((volatile FGITR_halfword_view_st *)\
(FGITR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGITR()     ((volatile u32FGITR_word_view *)\
(FGITR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGITR_VWAIT() (pst_bitFGITR() -> VWAIT)
#define vSetFGITR_VWAIT(ParValue)  (pst_bitFGITR() -> VWAIT=(ParValue))
#define biGetFGITR_HWAIT() (pst_bitFGITR() -> HWAIT)
#define vSetFGITR_HWAIT(ParValue)  (pst_bitFGITR() -> HWAIT=(ParValue))
            
/* LL-struct byte access */
#define vSetFGITRLL(ParValue) (pst_u8FGITR() -> u8LL = (ParValue))
#define u8GetFGITRLL() (pst_u8FGITR() -> u8LL)
/* LH-struct byte access */
#define vSetFGITRLH(ParValue) (pst_u8FGITR() -> u8LH = (ParValue))
#define u8GetFGITRLH() (pst_u8FGITR() -> u8LH)
/* HL-struct byte access */
#define vSetFGITRHL(ParValue) (pst_u8FGITR() -> u8HL = (ParValue))
#define u8GetFGITRHL() (pst_u8FGITR() -> u8HL)
/* HH-struct byte access */
#define vSetFGITRHH(ParValue) (pst_u8FGITR() -> u8HH = (ParValue))
#define u8GetFGITRHH() (pst_u8FGITR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGITRL(ParValue) (pst_u16FGITR() -> u16L = (ParValue))
#define u16GetFGITRL() (pst_u16FGITR() -> u16L)
#define vSetFGITRH(ParValue) (pst_u16FGITR() -> u16H = (ParValue))
#define u16GetFGITRH() (pst_u16FGITR() -> u16H)
            
/* Word access */
#define vSetFGITR(ParValue)  (*pu32FGITR() = (ParValue))
#define u32GetFGITR()  (*pu32FGITR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGHCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0800C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGHCR_REG__       0xC0C0800CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   HCW	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   HCS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..31  bit(s) R */                    
} FGHCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGHCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGHCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGHCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGHCR()     ((volatile FGHCR_bit_view_st *)\
(FGHCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGHCR()     ((volatile FGHCR_byte_view_st *)\
(FGHCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGHCR()     ((volatile FGHCR_halfword_view_st *)\
(FGHCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGHCR()     ((volatile u32FGHCR_word_view *)\
(FGHCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGHCR_HCW() (pst_bitFGHCR() -> HCW)
#define vSetFGHCR_HCW(ParValue)  (pst_bitFGHCR() -> HCW=(ParValue))
#define biGetFGHCR_HCS() (pst_bitFGHCR() -> HCS)
#define vSetFGHCR_HCS(ParValue)  (pst_bitFGHCR() -> HCS=(ParValue))
            
/* LL-struct byte access */
#define vSetFGHCRLL(ParValue) (pst_u8FGHCR() -> u8LL = (ParValue))
#define u8GetFGHCRLL() (pst_u8FGHCR() -> u8LL)
/* LH-struct byte access */
#define vSetFGHCRLH(ParValue) (pst_u8FGHCR() -> u8LH = (ParValue))
#define u8GetFGHCRLH() (pst_u8FGHCR() -> u8LH)
/* HL-struct byte access */
#define vSetFGHCRHL(ParValue) (pst_u8FGHCR() -> u8HL = (ParValue))
#define u8GetFGHCRHL() (pst_u8FGHCR() -> u8HL)
/* HH-struct byte access */
#define vSetFGHCRHH(ParValue) (pst_u8FGHCR() -> u8HH = (ParValue))
#define u8GetFGHCRHH() (pst_u8FGHCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGHCRL(ParValue) (pst_u16FGHCR() -> u16L = (ParValue))
#define u16GetFGHCRL() (pst_u16FGHCR() -> u16L)
#define vSetFGHCRH(ParValue) (pst_u16FGHCR() -> u16H = (ParValue))
#define u16GetFGHCRH() (pst_u16FGHCR() -> u16H)
            
/* Word access */
#define vSetFGHCR(ParValue)  (*pu32FGHCR() = (ParValue))
#define u32GetFGHCR()  (*pu32FGHCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGVCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGVCR_REG__       0xC0C08010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   VCH	:11; 	 /* 0..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   VCS	:11; 	 /* 16..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..31  bit(s) R */                    
} FGVCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGVCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGVCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGVCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGVCR()     ((volatile FGVCR_bit_view_st *)\
(FGVCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGVCR()     ((volatile FGVCR_byte_view_st *)\
(FGVCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGVCR()     ((volatile FGVCR_halfword_view_st *)\
(FGVCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGVCR()     ((volatile u32FGVCR_word_view *)\
(FGVCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGVCR_VCH() (pst_bitFGVCR() -> VCH)
#define vSetFGVCR_VCH(ParValue)  (pst_bitFGVCR() -> VCH=(ParValue))
#define biGetFGVCR_VCS() (pst_bitFGVCR() -> VCS)
#define vSetFGVCR_VCS(ParValue)  (pst_bitFGVCR() -> VCS=(ParValue))
            
/* LL-struct byte access */
#define vSetFGVCRLL(ParValue) (pst_u8FGVCR() -> u8LL = (ParValue))
#define u8GetFGVCRLL() (pst_u8FGVCR() -> u8LL)
/* LH-struct byte access */
#define vSetFGVCRLH(ParValue) (pst_u8FGVCR() -> u8LH = (ParValue))
#define u8GetFGVCRLH() (pst_u8FGVCR() -> u8LH)
/* HL-struct byte access */
#define vSetFGVCRHL(ParValue) (pst_u8FGVCR() -> u8HL = (ParValue))
#define u8GetFGVCRHL() (pst_u8FGVCR() -> u8HL)
/* HH-struct byte access */
#define vSetFGVCRHH(ParValue) (pst_u8FGVCR() -> u8HH = (ParValue))
#define u8GetFGVCRHH() (pst_u8FGVCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGVCRL(ParValue) (pst_u16FGVCR() -> u16L = (ParValue))
#define u16GetFGVCRL() (pst_u16FGVCR() -> u16L)
#define vSetFGVCRH(ParValue) (pst_u16FGVCR() -> u16H = (ParValue))
#define u16GetFGVCRH() (pst_u16FGVCR() -> u16H)
            
/* Word access */
#define vSetFGVCR(ParValue)  (*pu32FGVCR() = (ParValue))
#define u32GetFGVCR()  (*pu32FGVCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGCAR1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08014                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGCAR1_REG__       0xC0C08014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   CBA1	:29; 	 /* 3..31  bit(s) R/W */                    
} FGCAR1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGCAR1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGCAR1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGCAR1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGCAR1()     ((volatile FGCAR1_bit_view_st *)\
(FGCAR1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGCAR1()     ((volatile FGCAR1_byte_view_st *)\
(FGCAR1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGCAR1()     ((volatile FGCAR1_halfword_view_st *)\
(FGCAR1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGCAR1()     ((volatile u32FGCAR1_word_view *)\
(FGCAR1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGCAR1_CBA1() (pst_bitFGCAR1() -> CBA1)
#define vSetFGCAR1_CBA1(ParValue)  (pst_bitFGCAR1() -> CBA1=(ParValue))
            
/* LL-struct byte access */
#define vSetFGCAR1LL(ParValue) (pst_u8FGCAR1() -> u8LL = (ParValue))
#define u8GetFGCAR1LL() (pst_u8FGCAR1() -> u8LL)
/* LH-struct byte access */
#define vSetFGCAR1LH(ParValue) (pst_u8FGCAR1() -> u8LH = (ParValue))
#define u8GetFGCAR1LH() (pst_u8FGCAR1() -> u8LH)
/* HL-struct byte access */
#define vSetFGCAR1HL(ParValue) (pst_u8FGCAR1() -> u8HL = (ParValue))
#define u8GetFGCAR1HL() (pst_u8FGCAR1() -> u8HL)
/* HH-struct byte access */
#define vSetFGCAR1HH(ParValue) (pst_u8FGCAR1() -> u8HH = (ParValue))
#define u8GetFGCAR1HH() (pst_u8FGCAR1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGCAR1L(ParValue) (pst_u16FGCAR1() -> u16L = (ParValue))
#define u16GetFGCAR1L() (pst_u16FGCAR1() -> u16L)
#define vSetFGCAR1H(ParValue) (pst_u16FGCAR1() -> u16H = (ParValue))
#define u16GetFGCAR1H() (pst_u16FGCAR1() -> u16H)
            
/* Word access */
#define vSetFGCAR1(ParValue)  (*pu32FGCAR1() = (ParValue))
#define u32GetFGCAR1()  (*pu32FGCAR1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGCAR2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGCAR2_REG__       0xC0C08018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   CBA2	:29; 	 /* 3..31  bit(s) R/W */                    
} FGCAR2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGCAR2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGCAR2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGCAR2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGCAR2()     ((volatile FGCAR2_bit_view_st *)\
(FGCAR2_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGCAR2()     ((volatile FGCAR2_byte_view_st *)\
(FGCAR2_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGCAR2()     ((volatile FGCAR2_halfword_view_st *)\
(FGCAR2_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGCAR2()     ((volatile u32FGCAR2_word_view *)\
(FGCAR2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGCAR2_CBA2() (pst_bitFGCAR2() -> CBA2)
#define vSetFGCAR2_CBA2(ParValue)  (pst_bitFGCAR2() -> CBA2=(ParValue))
            
/* LL-struct byte access */
#define vSetFGCAR2LL(ParValue) (pst_u8FGCAR2() -> u8LL = (ParValue))
#define u8GetFGCAR2LL() (pst_u8FGCAR2() -> u8LL)
/* LH-struct byte access */
#define vSetFGCAR2LH(ParValue) (pst_u8FGCAR2() -> u8LH = (ParValue))
#define u8GetFGCAR2LH() (pst_u8FGCAR2() -> u8LH)
/* HL-struct byte access */
#define vSetFGCAR2HL(ParValue) (pst_u8FGCAR2() -> u8HL = (ParValue))
#define u8GetFGCAR2HL() (pst_u8FGCAR2() -> u8HL)
/* HH-struct byte access */
#define vSetFGCAR2HH(ParValue) (pst_u8FGCAR2() -> u8HH = (ParValue))
#define u8GetFGCAR2HH() (pst_u8FGCAR2() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGCAR2L(ParValue) (pst_u16FGCAR2() -> u16L = (ParValue))
#define u16GetFGCAR2L() (pst_u16FGCAR2() -> u16L)
#define vSetFGCAR2H(ParValue) (pst_u16FGCAR2() -> u16H = (ParValue))
#define u16GetFGCAR2H() (pst_u16FGCAR2() -> u16H)
            
/* Word access */
#define vSetFGCAR2(ParValue)  (*pu32FGCAR2() = (ParValue))
#define u32GetFGCAR2()  (*pu32FGCAR2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGCAR3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0801C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGCAR3_REG__       0xC0C0801CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   CBA3	:29; 	 /* 3..31  bit(s) R/W */                    
} FGCAR3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGCAR3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGCAR3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGCAR3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGCAR3()     ((volatile FGCAR3_bit_view_st *)\
(FGCAR3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGCAR3()     ((volatile FGCAR3_byte_view_st *)\
(FGCAR3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGCAR3()     ((volatile FGCAR3_halfword_view_st *)\
(FGCAR3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGCAR3()     ((volatile u32FGCAR3_word_view *)\
(FGCAR3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGCAR3_CBA3() (pst_bitFGCAR3() -> CBA3)
#define vSetFGCAR3_CBA3(ParValue)  (pst_bitFGCAR3() -> CBA3=(ParValue))
            
/* LL-struct byte access */
#define vSetFGCAR3LL(ParValue) (pst_u8FGCAR3() -> u8LL = (ParValue))
#define u8GetFGCAR3LL() (pst_u8FGCAR3() -> u8LL)
/* LH-struct byte access */
#define vSetFGCAR3LH(ParValue) (pst_u8FGCAR3() -> u8LH = (ParValue))
#define u8GetFGCAR3LH() (pst_u8FGCAR3() -> u8LH)
/* HL-struct byte access */
#define vSetFGCAR3HL(ParValue) (pst_u8FGCAR3() -> u8HL = (ParValue))
#define u8GetFGCAR3HL() (pst_u8FGCAR3() -> u8HL)
/* HH-struct byte access */
#define vSetFGCAR3HH(ParValue) (pst_u8FGCAR3() -> u8HH = (ParValue))
#define u8GetFGCAR3HH() (pst_u8FGCAR3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGCAR3L(ParValue) (pst_u16FGCAR3() -> u16L = (ParValue))
#define u16GetFGCAR3L() (pst_u16FGCAR3() -> u16L)
#define vSetFGCAR3H(ParValue) (pst_u16FGCAR3() -> u16H = (ParValue))
#define u16GetFGCAR3H() (pst_u16FGCAR3() -> u16H)
            
/* Word access */
#define vSetFGCAR3(ParValue)  (*pu32FGCAR3() = (ParValue))
#define u32GetFGCAR3()  (*pu32FGCAR3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGCCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGCCR_REG__       0xC0C08020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CBSA	:4; 	 /* 0..3  bit(s) R/W */
  uint32_t   	:4; 	 /* 4..7  bit(s) R */
  uint32_t   CBACT	:2; 	 /* 8..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   CBCUR	:2; 	 /* 16..17  bit(s) R */ 
  uint32_t   	:14; 	 /* 18..31  bit(s) R */                    
} FGCCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGCCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGCCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGCCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGCCR()     ((volatile FGCCR_bit_view_st *)\
(FGCCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGCCR()     ((volatile FGCCR_byte_view_st *)\
(FGCCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGCCR()     ((volatile FGCCR_halfword_view_st *)\
(FGCCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGCCR()     ((volatile u32FGCCR_word_view *)\
(FGCCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGCCR_CBSA() (pst_bitFGCCR() -> CBSA)
#define vSetFGCCR_CBSA(ParValue)  (pst_bitFGCCR() -> CBSA=(ParValue))
#define biGetFGCCR_CBACT() (pst_bitFGCCR() -> CBACT)
#define vSetFGCCR_CBACT(ParValue)  (pst_bitFGCCR() -> CBACT=(ParValue))            
#define biGetFGCCR_CBCUR() (pst_bitFGCCR() -> CBCUR)
            
/* LL-struct byte access */
#define vSetFGCCRLL(ParValue) (pst_u8FGCCR() -> u8LL = (ParValue))
#define u8GetFGCCRLL() (pst_u8FGCCR() -> u8LL)
/* LH-struct byte access */
#define vSetFGCCRLH(ParValue) (pst_u8FGCCR() -> u8LH = (ParValue))
#define u8GetFGCCRLH() (pst_u8FGCCR() -> u8LH)
/* HL-struct byte access */
#define vSetFGCCRHL(ParValue) (pst_u8FGCCR() -> u8HL = (ParValue))
#define u8GetFGCCRHL() (pst_u8FGCCR() -> u8HL)
/* HH-struct byte access */
#define vSetFGCCRHH(ParValue) (pst_u8FGCCR() -> u8HH = (ParValue))
#define u8GetFGCCRHH() (pst_u8FGCCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGCCRL(ParValue) (pst_u16FGCCR() -> u16L = (ParValue))
#define u16GetFGCCRL() (pst_u16FGCCR() -> u16L)
#define vSetFGCCRH(ParValue) (pst_u16FGCCR() -> u16H = (ParValue))
#define u16GetFGCCRH() (pst_u16FGCCR() -> u16H)
            
/* Word access */
#define vSetFGCCR(ParValue)  (*pu32FGCCR() = (ParValue))
#define u32GetFGCCR()  (*pu32FGCCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGCIR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08024                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGCIR_REG__       0xC0C08024U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ALPHA	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   BLUE	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   GREEN	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   RED	:8; 	 /* 24..31  bit(s) R/W */                    
} FGCIR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGCIR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGCIR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGCIR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGCIR()     ((volatile FGCIR_bit_view_st *)\
(FGCIR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGCIR()     ((volatile FGCIR_byte_view_st *)\
(FGCIR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGCIR()     ((volatile FGCIR_halfword_view_st *)\
(FGCIR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGCIR()     ((volatile u32FGCIR_word_view *)\
(FGCIR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGCIR_ALPHA() (pst_bitFGCIR() -> ALPHA)
#define vSetFGCIR_ALPHA(ParValue)  (pst_bitFGCIR() -> ALPHA=(ParValue))
#define biGetFGCIR_BLUE() (pst_bitFGCIR() -> BLUE)
#define vSetFGCIR_BLUE(ParValue)  (pst_bitFGCIR() -> BLUE=(ParValue))
#define biGetFGCIR_GREEN() (pst_bitFGCIR() -> GREEN)
#define vSetFGCIR_GREEN(ParValue)  (pst_bitFGCIR() -> GREEN=(ParValue))
#define biGetFGCIR_RED() (pst_bitFGCIR() -> RED)
#define vSetFGCIR_RED(ParValue)  (pst_bitFGCIR() -> RED=(ParValue))
            
/* LL-struct byte access */
#define vSetFGCIRLL(ParValue) (pst_u8FGCIR() -> u8LL = (ParValue))
#define u8GetFGCIRLL() (pst_u8FGCIR() -> u8LL)
/* LH-struct byte access */
#define vSetFGCIRLH(ParValue) (pst_u8FGCIR() -> u8LH = (ParValue))
#define u8GetFGCIRLH() (pst_u8FGCIR() -> u8LH)
/* HL-struct byte access */
#define vSetFGCIRHL(ParValue) (pst_u8FGCIR() -> u8HL = (ParValue))
#define u8GetFGCIRHL() (pst_u8FGCIR() -> u8HL)
/* HH-struct byte access */
#define vSetFGCIRHH(ParValue) (pst_u8FGCIR() -> u8HH = (ParValue))
#define u8GetFGCIRHH() (pst_u8FGCIR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGCIRL(ParValue) (pst_u16FGCIR() -> u16L = (ParValue))
#define u16GetFGCIRL() (pst_u16FGCIR() -> u16L)
#define vSetFGCIRH(ParValue) (pst_u16FGCIR() -> u16H = (ParValue))
#define u16GetFGCIRH() (pst_u16FGCIR() -> u16H)
            
/* Word access */
#define vSetFGCIR(ParValue)  (*pu32FGCIR() = (ParValue))
#define u32GetFGCIR()  (*pu32FGCIR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08028                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGSR_REG__       0xC0C08028U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   YSCALE	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   XSCALE	:16; 	 /* 16..31  bit(s) R/W */                    
} FGSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGSR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGSR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGSR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGSR()     ((volatile FGSR_bit_view_st *)\
(FGSR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGSR()     ((volatile FGSR_byte_view_st *)\
(FGSR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGSR()     ((volatile FGSR_halfword_view_st *)\
(FGSR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGSR()     ((volatile u32FGSR_word_view *)\
(FGSR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGSR_YSCALE() (pst_bitFGSR() -> YSCALE)
#define vSetFGSR_YSCALE(ParValue)  (pst_bitFGSR() -> YSCALE=(ParValue))
#define biGetFGSR_XSCALE() (pst_bitFGSR() -> XSCALE)
#define vSetFGSR_XSCALE(ParValue)  (pst_bitFGSR() -> XSCALE=(ParValue))
            
/* LL-struct byte access */
#define vSetFGSRLL(ParValue) (pst_u8FGSR() -> u8LL = (ParValue))
#define u8GetFGSRLL() (pst_u8FGSR() -> u8LL)
/* LH-struct byte access */
#define vSetFGSRLH(ParValue) (pst_u8FGSR() -> u8LH = (ParValue))
#define u8GetFGSRLH() (pst_u8FGSR() -> u8LH)
/* HL-struct byte access */
#define vSetFGSRHL(ParValue) (pst_u8FGSR() -> u8HL = (ParValue))
#define u8GetFGSRHL() (pst_u8FGSR() -> u8HL)
/* HH-struct byte access */
#define vSetFGSRHH(ParValue) (pst_u8FGSR() -> u8HH = (ParValue))
#define u8GetFGSRHH() (pst_u8FGSR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGSRL(ParValue) (pst_u16FGSR() -> u16L = (ParValue))
#define u16GetFGSRL() (pst_u16FGSR() -> u16L)
#define vSetFGSRH(ParValue) (pst_u16FGSR() -> u16H = (ParValue))
#define u16GetFGSRH() (pst_u16FGSR() -> u16H)
            
/* Word access */
#define vSetFGSR(ParValue)  (*pu32FGSR() = (ParValue))
#define u32GetFGSR()  (*pu32FGSR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGLOR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0802C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGLOR_REG__       0xC0C0802CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   LOFF	:16; 	 /* 0..15  bit(s) R/W */                    
} FGLOR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} FGLOR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16FGLOR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGLOR()     ((volatile FGLOR_bit_view_st *)\
(FGLOR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGLOR()     ((volatile FGLOR_byte_view_st *)\
(FGLOR_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16FGLOR()     ((volatile u16FGLOR_halfword_view *)\
(FGLOR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGLOR_LOFF() (pst_bitFGLOR() -> LOFF)
#define vSetFGLOR_LOFF(ParValue)  (pst_bitFGLOR() -> LOFF=(ParValue))
            
/* L-struct byte access */
#define vSetFGLORL(ParValue) (pst_u8FGLOR() -> u8L = (ParValue))
#define u8GetFGLORL() (pst_u8FGLOR() -> u8L)
/* H-struct byte access */
#define vSetFGLORH(ParValue) (pst_u8FGLOR() -> u8H = (ParValue))
#define u8GetFGLORH() (pst_u8FGLOR() -> u8H)
            
/* Half-word access */ 
#define vSetFGLOR(ParValue) (*pu16FGLOR()  = (ParValue))
#define u16GetFGLOR() (*pu16FGLOR() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGHMR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08030                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGHMR_REG__       0xC0C08030U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MHSPWR	:12; 	 /* 0..11  bit(s) R */
  uint32_t   	:4; 	 /* 12..15  bit(s) R */
  uint32_t   MHCR	:12; 	 /* 16..27  bit(s) R */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} FGHMR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGHMR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGHMR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGHMR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGHMR()     ((volatile FGHMR_bit_view_st *)\
(FGHMR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGHMR()     ((volatile FGHMR_byte_view_st *)\
(FGHMR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGHMR()     ((volatile FGHMR_halfword_view_st *)\
(FGHMR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGHMR()     ((volatile u32FGHMR_word_view *)\
(FGHMR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetFGHMR_MHSPWR() (pst_bitFGHMR() -> MHSPWR)            
#define biGetFGHMR_MHCR() (pst_bitFGHMR() -> MHCR)
            
/* LL-struct byte access */

#define u8GetFGHMRLL() (pst_u8FGHMR() -> u8LL)
/* LH-struct byte access */

#define u8GetFGHMRLH() (pst_u8FGHMR() -> u8LH)
/* HL-struct byte access */

#define u8GetFGHMRHL() (pst_u8FGHMR() -> u8HL)
/* HH-struct byte access */

#define u8GetFGHMRHH() (pst_u8FGHMR() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetFGHMRL() (pst_u16FGHMR() -> u16L)

#define u16GetFGHMRH() (pst_u16FGHMR() -> u16H)
            
/* Word access */

#define u32GetFGHMR()  (*pu32FGHMR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGVMR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08034                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGVMR_REG__       0xC0C08034U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MVSPWR	:12; 	 /* 0..11  bit(s) R */
  uint32_t   	:4; 	 /* 12..15  bit(s) R */
  uint32_t   MVCR	:12; 	 /* 16..27  bit(s) R */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} FGVMR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGVMR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGVMR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGVMR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGVMR()     ((volatile FGVMR_bit_view_st *)\
(FGVMR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGVMR()     ((volatile FGVMR_byte_view_st *)\
(FGVMR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGVMR()     ((volatile FGVMR_halfword_view_st *)\
(FGVMR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGVMR()     ((volatile u32FGVMR_word_view *)\
(FGVMR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetFGVMR_MVSPWR() (pst_bitFGVMR() -> MVSPWR)            
#define biGetFGVMR_MVCR() (pst_bitFGVMR() -> MVCR)
            
/* LL-struct byte access */

#define u8GetFGVMRLL() (pst_u8FGVMR() -> u8LL)
/* LH-struct byte access */

#define u8GetFGVMRLH() (pst_u8FGVMR() -> u8LH)
/* HL-struct byte access */

#define u8GetFGVMRHL() (pst_u8FGVMR() -> u8HL)
/* HH-struct byte access */

#define u8GetFGVMRHH() (pst_u8FGVMR() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetFGVMRL() (pst_u16FGVMR() -> u16L)

#define u16GetFGVMRH() (pst_u16FGVMR() -> u16H)
            
/* Word access */

#define u32GetFGVMR()  (*pu32FGVMR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGMCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08038                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGMCR_REG__       0xC0C08038U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   HDISP	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   HCR	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   HSPWR	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   VCR	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   VSPWR	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   	:11; 	 /* 5..15  bit(s) R */
  uint32_t   MHDISP	:12; 	 /* 16..27  bit(s) R */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} FGMCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGMCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGMCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGMCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGMCR()     ((volatile FGMCR_bit_view_st *)\
(FGMCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGMCR()     ((volatile FGMCR_byte_view_st *)\
(FGMCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGMCR()     ((volatile FGMCR_halfword_view_st *)\
(FGMCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGMCR()     ((volatile u32FGMCR_word_view *)\
(FGMCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGMCR_HDISP() (pst_bitFGMCR() -> HDISP)
#define vSetFGMCR_HDISP(ParValue)  (pst_bitFGMCR() -> HDISP=(ParValue))
#define biGetFGMCR_HCR() (pst_bitFGMCR() -> HCR)
#define vSetFGMCR_HCR(ParValue)  (pst_bitFGMCR() -> HCR=(ParValue))
#define biGetFGMCR_HSPWR() (pst_bitFGMCR() -> HSPWR)
#define vSetFGMCR_HSPWR(ParValue)  (pst_bitFGMCR() -> HSPWR=(ParValue))
#define biGetFGMCR_VCR() (pst_bitFGMCR() -> VCR)
#define vSetFGMCR_VCR(ParValue)  (pst_bitFGMCR() -> VCR=(ParValue))
#define biGetFGMCR_VSPWR() (pst_bitFGMCR() -> VSPWR)
#define vSetFGMCR_VSPWR(ParValue)  (pst_bitFGMCR() -> VSPWR=(ParValue))            
#define biGetFGMCR_MHDISP() (pst_bitFGMCR() -> MHDISP)
            
/* LL-struct byte access */
#define vSetFGMCRLL(ParValue) (pst_u8FGMCR() -> u8LL = (ParValue))
#define u8GetFGMCRLL() (pst_u8FGMCR() -> u8LL)
/* LH-struct byte access */
#define vSetFGMCRLH(ParValue) (pst_u8FGMCR() -> u8LH = (ParValue))
#define u8GetFGMCRLH() (pst_u8FGMCR() -> u8LH)
/* HL-struct byte access */
#define vSetFGMCRHL(ParValue) (pst_u8FGMCR() -> u8HL = (ParValue))
#define u8GetFGMCRHL() (pst_u8FGMCR() -> u8HL)
/* HH-struct byte access */
#define vSetFGMCRHH(ParValue) (pst_u8FGMCR() -> u8HH = (ParValue))
#define u8GetFGMCRHH() (pst_u8FGMCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGMCRL(ParValue) (pst_u16FGMCR() -> u16L = (ParValue))
#define u16GetFGMCRL() (pst_u16FGMCR() -> u16L)
#define vSetFGMCRH(ParValue) (pst_u16FGMCR() -> u16H = (ParValue))
#define u16GetFGMCRH() (pst_u16FGMCR() -> u16H)
            
/* Word access */
#define vSetFGMCR(ParValue)  (*pu32FGMCR() = (ParValue))
#define u32GetFGMCR()  (*pu32FGMCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGIMR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0803C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGIMR_REG__       0xC0C0803CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   CDI	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   VBTOI	:1; 	 /* 1..1  bit(s) R/W */
  uint8_t   VSI	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   MRDYI	:1; 	 /* 3..3  bit(s) R/W */
  uint8_t   NVI	:1; 	 /* 4..4  bit(s) R/W */ 
  uint8_t   RPEI	:1; 	 /* 5..5  bit(s) R/W */
  uint8_t   MPEI	:1; 	 /* 6..6  bit(s) R/W */ 
  uint8_t   	:1; 	 /* 7..31  bit(s) R */                    
} FGIMR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8FGIMR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGIMR()     ((volatile FGIMR_bit_view_st *)\
(FGIMR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8FGIMR()     ((volatile u8FGIMR_byte_view *)\
(FGIMR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGIMR_CDI() (pst_bitFGIMR() -> CDI)
#define vSetFGIMR_CDI(ParValue)  (pst_bitFGIMR() -> CDI=(ParValue))
#define biGetFGIMR_VBTOI() (pst_bitFGIMR() -> VBTOI)
#define vSetFGIMR_VBTOI(ParValue)  (pst_bitFGIMR() -> VBTOI=(ParValue))
#define biGetFGIMR_VSI() (pst_bitFGIMR() -> VSI)
#define vSetFGIMR_VSI(ParValue)  (pst_bitFGIMR() -> VSI=(ParValue))
#define biGetFGIMR_MRDYI() (pst_bitFGIMR() -> MRDYI)
#define vSetFGIMR_MRDYI(ParValue)  (pst_bitFGIMR() -> MRDYI=(ParValue))
#define biGetFGIMR_NVI() (pst_bitFGIMR() -> NVI)
#define vSetFGIMR_NVI(ParValue)  (pst_bitFGIMR() -> NVI=(ParValue))
#define biGetFGIMR_RPEI() (pst_bitFGIMR() -> RPEI)
#define vSetFGIMR_RPEI(ParValue)  (pst_bitFGIMR() -> RPEI=(ParValue))
#define biGetFGIMR_MPEI() (pst_bitFGIMR() -> MPEI)
#define vSetFGIMR_MPEI(ParValue)  (pst_bitFGIMR() -> MPEI=(ParValue))
            
/* byte access */
#define vSetFGIMR(ParValue) (*pu8FGIMR() = (ParValue))
#define u8GetFGIMR() (*pu8FGIMR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGISR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08040                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGISR_REG__       0xC0C08040U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   CDS	:1; 	 /* 0..0  bit(s) R/W1C */
  uint8_t   VBTOS	:1; 	 /* 1..1  bit(s) R/W1C */
  uint8_t   VSS	:1; 	 /* 2..2  bit(s) R/W1C */
  uint8_t   MRDYS	:1; 	 /* 3..3  bit(s) R/W1C */
  uint8_t   NVS	:1; 	 /* 4..4  bit(s) R/W1C */ 
  uint8_t   RPES	:1; 	 /* 5..5  bit(s) R/W1C */
  uint8_t   MPES	:1; 	 /* 6..6  bit(s) R/W1C */ 
  uint8_t   	:1; 	 /* 7..31  bit(s) R */                    
} FGISR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8FGISR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGISR()     ((volatile FGISR_bit_view_st *)\
(FGISR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8FGISR()     ((volatile u8FGISR_byte_view *)\
(FGISR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGISR_CDS() (pst_bitFGISR() -> CDS)
#define vClrFGISR_CDS() (pst_bitFGISR() -> CDS = (1))
#define biGetFGISR_VBTOS() (pst_bitFGISR() -> VBTOS)
#define vClrFGISR_VBTOS() (pst_bitFGISR() -> VBTOS = (1))
#define biGetFGISR_VSS() (pst_bitFGISR() -> VSS)
#define vClrFGISR_VSS() (pst_bitFGISR() -> VSS = (1))
#define biGetFGISR_MRDYS() (pst_bitFGISR() -> MRDYS)
#define vClrFGISR_MRDYS() (pst_bitFGISR() -> MRDYS = (1))
#define biGetFGISR_NVS() (pst_bitFGISR() -> NVS)
#define vClrFGISR_NVS() (pst_bitFGISR() -> NVS = (1))
#define biGetFGISR_RPES() (pst_bitFGISR() -> RPES)
#define vClrFGISR_RPES() (pst_bitFGISR() -> RPES = (1))
#define biGetFGISR_MPES() (pst_bitFGISR() -> MPES)
#define vClrFGISR_MPES() (pst_bitFGISR() -> MPES = (1))
            
/* byte access */
#define vSetFGISR(ParValue) (*pu8FGISR() = (ParValue))
#define u8GetFGISR() (*pu8FGISR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGMASR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08044                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGMASR_REG__       0xC0C08044U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:2; 	 /* 0..1  bit(s) R */ 
  uint32_t   MAS	:30; 	 /* 2..31  bit(s) R/W */                    
} FGMASR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGMASR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGMASR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGMASR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGMASR()     ((volatile FGMASR_bit_view_st *)\
(FGMASR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGMASR()     ((volatile FGMASR_byte_view_st *)\
(FGMASR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGMASR()     ((volatile FGMASR_halfword_view_st *)\
(FGMASR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGMASR()     ((volatile u32FGMASR_word_view *)\
(FGMASR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGMASR_MAS() (pst_bitFGMASR() -> MAS)
#define vSetFGMASR_MAS(ParValue)  (pst_bitFGMASR() -> MAS=(ParValue))
            
/* LL-struct byte access */
#define vSetFGMASRLL(ParValue) (pst_u8FGMASR() -> u8LL = (ParValue))
#define u8GetFGMASRLL() (pst_u8FGMASR() -> u8LL)
/* LH-struct byte access */
#define vSetFGMASRLH(ParValue) (pst_u8FGMASR() -> u8LH = (ParValue))
#define u8GetFGMASRLH() (pst_u8FGMASR() -> u8LH)
/* HL-struct byte access */
#define vSetFGMASRHL(ParValue) (pst_u8FGMASR() -> u8HL = (ParValue))
#define u8GetFGMASRHL() (pst_u8FGMASR() -> u8HL)
/* HH-struct byte access */
#define vSetFGMASRHH(ParValue) (pst_u8FGMASR() -> u8HH = (ParValue))
#define u8GetFGMASRHH() (pst_u8FGMASR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGMASRL(ParValue) (pst_u16FGMASR() -> u16L = (ParValue))
#define u16GetFGMASRL() (pst_u16FGMASR() -> u16L)
#define vSetFGMASRH(ParValue) (pst_u16FGMASR() -> u16H = (ParValue))
#define u16GetFGMASRH() (pst_u16FGMASR() -> u16H)
            
/* Word access */
#define vSetFGMASR(ParValue)  (*pu32FGMASR() = (ParValue))
#define u32GetFGMASR()  (*pu32FGMASR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGMAER                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08048                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGMAER_REG__       0xC0C08048U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:2; 	 /* 0..1  bit(s) R */ 
  uint32_t   MAE	:30; 	 /* 2..31  bit(s) R/W */                    
} FGMAER_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGMAER_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGMAER_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGMAER_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGMAER()     ((volatile FGMAER_bit_view_st *)\
(FGMAER_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGMAER()     ((volatile FGMAER_byte_view_st *)\
(FGMAER_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGMAER()     ((volatile FGMAER_halfword_view_st *)\
(FGMAER_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGMAER()     ((volatile u32FGMAER_word_view *)\
(FGMAER_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGMAER_MAE() (pst_bitFGMAER() -> MAE)
#define vSetFGMAER_MAE(ParValue)  (pst_bitFGMAER() -> MAE=(ParValue))
            
/* LL-struct byte access */
#define vSetFGMAERLL(ParValue) (pst_u8FGMAER() -> u8LL = (ParValue))
#define u8GetFGMAERLL() (pst_u8FGMAER() -> u8LL)
/* LH-struct byte access */
#define vSetFGMAERLH(ParValue) (pst_u8FGMAER() -> u8LH = (ParValue))
#define u8GetFGMAERLH() (pst_u8FGMAER() -> u8LH)
/* HL-struct byte access */
#define vSetFGMAERHL(ParValue) (pst_u8FGMAER() -> u8HL = (ParValue))
#define u8GetFGMAERHL() (pst_u8FGMAER() -> u8HL)
/* HH-struct byte access */
#define vSetFGMAERHH(ParValue) (pst_u8FGMAER() -> u8HH = (ParValue))
#define u8GetFGMAERHH() (pst_u8FGMAER() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFGMAERL(ParValue) (pst_u16FGMAER() -> u16L = (ParValue))
#define u16GetFGMAERL() (pst_u16FGMAER() -> u16L)
#define vSetFGMAERH(ParValue) (pst_u16FGMAER() -> u16H = (ParValue))
#define u16GetFGMAERH() (pst_u16FGMAER() -> u16H)
            
/* Word access */
#define vSetFGMAER(ParValue)  (*pu32FGMAER() = (ParValue))
#define u32GetFGMAER()  (*pu32FGMAER() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGVBEAR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0804C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGVBEAR_REG__       0xC0C0804CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   VBADDR	:32; 	 /* 0..31  bit(s) R */                    
} FGVBEAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGVBEAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGVBEAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGVBEAR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGVBEAR()     ((volatile FGVBEAR_bit_view_st *)\
(FGVBEAR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGVBEAR()     ((volatile FGVBEAR_byte_view_st *)\
(FGVBEAR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGVBEAR()     ((volatile FGVBEAR_halfword_view_st *)\
(FGVBEAR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGVBEAR()     ((volatile u32FGVBEAR_word_view *)\
(FGVBEAR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetFGVBEAR_VBADDR() (pst_bitFGVBEAR() -> VBADDR)
            
/* LL-struct byte access */

#define u8GetFGVBEARLL() (pst_u8FGVBEAR() -> u8LL)
/* LH-struct byte access */

#define u8GetFGVBEARLH() (pst_u8FGVBEAR() -> u8LH)
/* HL-struct byte access */

#define u8GetFGVBEARHL() (pst_u8FGVBEAR() -> u8HL)
/* HH-struct byte access */

#define u8GetFGVBEARHH() (pst_u8FGVBEAR() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetFGVBEARL() (pst_u16FGVBEAR() -> u16L)

#define u16GetFGVBEARH() (pst_u16FGVBEAR() -> u16H)
            
/* Word access */

#define u32GetFGVBEAR()  (*pu32FGVBEAR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGVBECR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C08050                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGVBECR_REG__       0xC0C08050U
     
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
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} FGVBECR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FGVBECR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FGVBECR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FGVBECR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGVBECR()     ((volatile FGVBECR_bit_view_st *)\
(FGVBECR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8FGVBECR()     ((volatile FGVBECR_byte_view_st *)\
(FGVBECR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FGVBECR()     ((volatile FGVBECR_halfword_view_st *)\
(FGVBECR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32FGVBECR()     ((volatile u32FGVBECR_word_view *)\
(FGVBECR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetFGVBECR_WR() (pst_bitFGVBECR() -> WR)            
#define biGetFGVBECR_BTYPE() (pst_bitFGVBECR() -> BTYPE)            
#define biGetFGVBECR_BSIZE() (pst_bitFGVBECR() -> BSIZE)            
#define biGetFGVBECR_RTYPE() (pst_bitFGVBECR() -> RTYPE)            
#define biGetFGVBECR_BEN() (pst_bitFGVBECR() -> BEN)            
#define biGetFGVBECR_ID() (pst_bitFGVBECR() -> ID)            
#define biGetFGVBECR_LEN() (pst_bitFGVBECR() -> LEN)
            
/* LL-struct byte access */

#define u8GetFGVBECRLL() (pst_u8FGVBECR() -> u8LL)
/* LH-struct byte access */

#define u8GetFGVBECRLH() (pst_u8FGVBECR() -> u8LH)
/* HL-struct byte access */

#define u8GetFGVBECRHL() (pst_u8FGVBECR() -> u8HL)
/* HH-struct byte access */

#define u8GetFGVBECRHH() (pst_u8FGVBECR() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetFGVBECRL() (pst_u16FGVBECR() -> u16L)

#define u16GetFGVBECRH() (pst_u16FGVBECR() -> u16H)
            
/* Word access */

#define u32GetFGVBECR()  (*pu32FGVBECR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGCCLR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0C08400                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGCCLR_REG__       0xC0C08400U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   CCV	:8; 	 /* 0..7  bit(s) R/W */                    
} FGCCLR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8FGCCLR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGCCLR(ch)     ((volatile FGCCLR_bit_view_st *)\
(FGCCLR_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE  */
#define pu8FGCCLR(ch)     ((volatile u8FGCCLR_byte_view *)\
(FGCCLR_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGCCLR_CCV(ch) (pst_bitFGCCLR(ch) -> CCV)
#define vSetFGCCLR_CCV(ch,ParValue)  (pst_bitFGCCLR(ch) -> CCV=(ParValue))
            
/* byte access */
#define vSetFGCCLR(ch,ParValue) (*pu8FGCCLR(ch) = (ParValue))
#define u8GetFGCCLR(ch) (*pu8FGCCLR(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGCCLG                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0C08800                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGCCLG_REG__       0xC0C08800U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   CCV	:8; 	 /* 0..7  bit(s) R/W */                    
} FGCCLG_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8FGCCLG_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGCCLG(ch)     ((volatile FGCCLG_bit_view_st *)\
(FGCCLG_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE  */
#define pu8FGCCLG(ch)     ((volatile u8FGCCLG_byte_view *)\
(FGCCLG_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGCCLG_CCV(ch) (pst_bitFGCCLG(ch) -> CCV)
#define vSetFGCCLG_CCV(ch,ParValue)  (pst_bitFGCCLG(ch) -> CCV=(ParValue))
            
/* byte access */
#define vSetFGCCLG(ch,ParValue) (*pu8FGCCLG(ch) = (ParValue))
#define u8GetFGCCLG(ch) (*pu8FGCCLG(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FGCCLB                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0C08C00                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FGCCLB_REG__       0xC0C08C00U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   CCV	:8; 	 /* 0..7  bit(s) R/W */                    
} FGCCLB_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8FGCCLB_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFGCCLB(ch)     ((volatile FGCCLB_bit_view_st *)\
(FGCCLB_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE  */
#define pu8FGCCLB(ch)     ((volatile u8FGCCLB_byte_view *)\
(FGCCLB_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFGCCLB_CCV(ch) (pst_bitFGCCLB(ch) -> CCV)
#define vSetFGCCLB_CCV(ch,ParValue)  (pst_bitFGCCLB(ch) -> CCV=(ParValue))
            
/* byte access */
#define vSetFGCCLB(ch,ParValue) (*pu8FGCCLB(ch) = (ParValue))
#define u8GetFGCCLB(ch) (*pu8FGCCLB(ch) )
            


/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */
/****************************************************************************/
    

#endif /* FGIO_H */ 

/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: ga_io.c
**  $Revision: 1.11 $
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

