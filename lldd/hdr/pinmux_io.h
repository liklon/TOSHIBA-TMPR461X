/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : PINMUX 
/  Date of creation (y-m-d:time): 2015-01-20+01:00  :  10:55:54.218+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.13 $ 
/  Excel Sheet ver.             : vv1.4
/  Excel Sheet date             : 2014-Oct-21
/  Excel Sheet author           : AKL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : Pin Multiplexer low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : GPIO
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.13 $ 
*   DATE        : $Date: 2015/05/27 12:55:22 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/
#ifndef PINMUXIO_H
#define PINMUXIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */ 

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_PINMUX_IO_H_REVISION     "$Revision: 1.13 $"
#define LLDD_PINMUX_IO_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/
/* disable following Misra errors for io files */
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 47    /* Rule 5.1  [R] : No more than 31 chars to determine an identifier */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers  */
  #pragma ghs nowarning 230   /* Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types */
  #pragma ghs nowarning 1861  /* Rule 20.1 [R] : No definition, redefinition, or undefinition of reserved words and standard library names */
  #pragma ghs nowarning 1862  /* Rule 19.7 [A] : Disable function-like macro not allowed */
#endif
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ0_1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ0_1_REG__       0xC0302000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ0_1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ0_1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ0_1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ0_1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ0_1()     ((volatile DDR_DQ0_1_bit_view_st *)\
(DDR_DQ0_1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ0_1()     ((volatile DDR_DQ0_1_byte_view_st *)\
(DDR_DQ0_1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ0_1()     ((volatile DDR_DQ0_1_halfword_view_st *)\
(DDR_DQ0_1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ0_1()     ((volatile u32DDR_DQ0_1_word_view *)\
(DDR_DQ0_1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ0_1_DDR_DQ0_SEL() (pst_bitDDR_DQ0_1() -> DDR_DQ0_SEL)
#define vSetDDR_DQ0_1_DDR_DQ0_SEL(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ0_SEL=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ0_PU() (pst_bitDDR_DQ0_1() -> DDR_DQ0_PU)
#define vSetDDR_DQ0_1_DDR_DQ0_PU(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ0_PU=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ0_PD() (pst_bitDDR_DQ0_1() -> DDR_DQ0_PD)
#define vSetDDR_DQ0_1_DDR_DQ0_PD(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ0_PD=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ0_SMT() (pst_bitDDR_DQ0_1() -> DDR_DQ0_SMT)
#define vSetDDR_DQ0_1_DDR_DQ0_SMT(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ0_SMT=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ0_IMP() (pst_bitDDR_DQ0_1() -> DDR_DQ0_IMP)
#define vSetDDR_DQ0_1_DDR_DQ0_IMP(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ0_IMP=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ0_LATCHN() (pst_bitDDR_DQ0_1() -> DDR_DQ0_LATCHN)
#define vSetDDR_DQ0_1_DDR_DQ0_LATCHN(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ0_LATCHN=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ1_SEL() (pst_bitDDR_DQ0_1() -> DDR_DQ1_SEL)
#define vSetDDR_DQ0_1_DDR_DQ1_SEL(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ1_SEL=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ1_PU() (pst_bitDDR_DQ0_1() -> DDR_DQ1_PU)
#define vSetDDR_DQ0_1_DDR_DQ1_PU(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ1_PU=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ1_PD() (pst_bitDDR_DQ0_1() -> DDR_DQ1_PD)
#define vSetDDR_DQ0_1_DDR_DQ1_PD(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ1_PD=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ1_SMT() (pst_bitDDR_DQ0_1() -> DDR_DQ1_SMT)
#define vSetDDR_DQ0_1_DDR_DQ1_SMT(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ1_SMT=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ1_IMP() (pst_bitDDR_DQ0_1() -> DDR_DQ1_IMP)
#define vSetDDR_DQ0_1_DDR_DQ1_IMP(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ1_IMP=(ParValue))
#define biGetDDR_DQ0_1_DDR_DQ1_LATCHN() (pst_bitDDR_DQ0_1() -> DDR_DQ1_LATCHN)
#define vSetDDR_DQ0_1_DDR_DQ1_LATCHN(ParValue)  (pst_bitDDR_DQ0_1() -> DDR_DQ1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ0_1LL(ParValue) (pst_u8DDR_DQ0_1() -> u8LL = (ParValue))
#define u8GetDDR_DQ0_1LL() (pst_u8DDR_DQ0_1() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ0_1LH(ParValue) (pst_u8DDR_DQ0_1() -> u8LH = (ParValue))
#define u8GetDDR_DQ0_1LH() (pst_u8DDR_DQ0_1() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ0_1HL(ParValue) (pst_u8DDR_DQ0_1() -> u8HL = (ParValue))
#define u8GetDDR_DQ0_1HL() (pst_u8DDR_DQ0_1() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ0_1HH(ParValue) (pst_u8DDR_DQ0_1() -> u8HH = (ParValue))
#define u8GetDDR_DQ0_1HH() (pst_u8DDR_DQ0_1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ0_1L(ParValue) (pst_u16DDR_DQ0_1() -> u16L = (ParValue))
#define u16GetDDR_DQ0_1L() (pst_u16DDR_DQ0_1() -> u16L)
#define vSetDDR_DQ0_1H(ParValue) (pst_u16DDR_DQ0_1() -> u16H = (ParValue))
#define u16GetDDR_DQ0_1H() (pst_u16DDR_DQ0_1() -> u16H)
            
/* Word access */
#define vSetDDR_DQ0_1(ParValue)  (*pu32DDR_DQ0_1() = (ParValue))
#define u32GetDDR_DQ0_1()  (*pu32DDR_DQ0_1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ2_3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ2_3_REG__       0xC0302004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ2_3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ2_3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ2_3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ2_3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ2_3()     ((volatile DDR_DQ2_3_bit_view_st *)\
(DDR_DQ2_3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ2_3()     ((volatile DDR_DQ2_3_byte_view_st *)\
(DDR_DQ2_3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ2_3()     ((volatile DDR_DQ2_3_halfword_view_st *)\
(DDR_DQ2_3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ2_3()     ((volatile u32DDR_DQ2_3_word_view *)\
(DDR_DQ2_3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ2_3_DDR_DQ2_SEL() (pst_bitDDR_DQ2_3() -> DDR_DQ2_SEL)
#define vSetDDR_DQ2_3_DDR_DQ2_SEL(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ2_SEL=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ2_PU() (pst_bitDDR_DQ2_3() -> DDR_DQ2_PU)
#define vSetDDR_DQ2_3_DDR_DQ2_PU(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ2_PU=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ2_PD() (pst_bitDDR_DQ2_3() -> DDR_DQ2_PD)
#define vSetDDR_DQ2_3_DDR_DQ2_PD(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ2_PD=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ2_SMT() (pst_bitDDR_DQ2_3() -> DDR_DQ2_SMT)
#define vSetDDR_DQ2_3_DDR_DQ2_SMT(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ2_SMT=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ2_IMP() (pst_bitDDR_DQ2_3() -> DDR_DQ2_IMP)
#define vSetDDR_DQ2_3_DDR_DQ2_IMP(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ2_IMP=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ2_LATCHN() (pst_bitDDR_DQ2_3() -> DDR_DQ2_LATCHN)
#define vSetDDR_DQ2_3_DDR_DQ2_LATCHN(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ2_LATCHN=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ3_SEL() (pst_bitDDR_DQ2_3() -> DDR_DQ3_SEL)
#define vSetDDR_DQ2_3_DDR_DQ3_SEL(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ3_SEL=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ3_PU() (pst_bitDDR_DQ2_3() -> DDR_DQ3_PU)
#define vSetDDR_DQ2_3_DDR_DQ3_PU(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ3_PU=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ3_PD() (pst_bitDDR_DQ2_3() -> DDR_DQ3_PD)
#define vSetDDR_DQ2_3_DDR_DQ3_PD(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ3_PD=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ3_SMT() (pst_bitDDR_DQ2_3() -> DDR_DQ3_SMT)
#define vSetDDR_DQ2_3_DDR_DQ3_SMT(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ3_SMT=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ3_IMP() (pst_bitDDR_DQ2_3() -> DDR_DQ3_IMP)
#define vSetDDR_DQ2_3_DDR_DQ3_IMP(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ3_IMP=(ParValue))
#define biGetDDR_DQ2_3_DDR_DQ3_LATCHN() (pst_bitDDR_DQ2_3() -> DDR_DQ3_LATCHN)
#define vSetDDR_DQ2_3_DDR_DQ3_LATCHN(ParValue)  (pst_bitDDR_DQ2_3() -> DDR_DQ3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ2_3LL(ParValue) (pst_u8DDR_DQ2_3() -> u8LL = (ParValue))
#define u8GetDDR_DQ2_3LL() (pst_u8DDR_DQ2_3() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ2_3LH(ParValue) (pst_u8DDR_DQ2_3() -> u8LH = (ParValue))
#define u8GetDDR_DQ2_3LH() (pst_u8DDR_DQ2_3() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ2_3HL(ParValue) (pst_u8DDR_DQ2_3() -> u8HL = (ParValue))
#define u8GetDDR_DQ2_3HL() (pst_u8DDR_DQ2_3() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ2_3HH(ParValue) (pst_u8DDR_DQ2_3() -> u8HH = (ParValue))
#define u8GetDDR_DQ2_3HH() (pst_u8DDR_DQ2_3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ2_3L(ParValue) (pst_u16DDR_DQ2_3() -> u16L = (ParValue))
#define u16GetDDR_DQ2_3L() (pst_u16DDR_DQ2_3() -> u16L)
#define vSetDDR_DQ2_3H(ParValue) (pst_u16DDR_DQ2_3() -> u16H = (ParValue))
#define u16GetDDR_DQ2_3H() (pst_u16DDR_DQ2_3() -> u16H)
            
/* Word access */
#define vSetDDR_DQ2_3(ParValue)  (*pu32DDR_DQ2_3() = (ParValue))
#define u32GetDDR_DQ2_3()  (*pu32DDR_DQ2_3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ4_5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ4_5_REG__       0xC0302008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ4_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ4_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ4_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ4_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ4_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ4_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ5_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ5_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ5_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ5_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ5_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ5_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ4_5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ4_5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ4_5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ4_5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ4_5()     ((volatile DDR_DQ4_5_bit_view_st *)\
(DDR_DQ4_5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ4_5()     ((volatile DDR_DQ4_5_byte_view_st *)\
(DDR_DQ4_5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ4_5()     ((volatile DDR_DQ4_5_halfword_view_st *)\
(DDR_DQ4_5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ4_5()     ((volatile u32DDR_DQ4_5_word_view *)\
(DDR_DQ4_5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ4_5_DDR_DQ4_SEL() (pst_bitDDR_DQ4_5() -> DDR_DQ4_SEL)
#define vSetDDR_DQ4_5_DDR_DQ4_SEL(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ4_SEL=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ4_PU() (pst_bitDDR_DQ4_5() -> DDR_DQ4_PU)
#define vSetDDR_DQ4_5_DDR_DQ4_PU(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ4_PU=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ4_PD() (pst_bitDDR_DQ4_5() -> DDR_DQ4_PD)
#define vSetDDR_DQ4_5_DDR_DQ4_PD(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ4_PD=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ4_SMT() (pst_bitDDR_DQ4_5() -> DDR_DQ4_SMT)
#define vSetDDR_DQ4_5_DDR_DQ4_SMT(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ4_SMT=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ4_IMP() (pst_bitDDR_DQ4_5() -> DDR_DQ4_IMP)
#define vSetDDR_DQ4_5_DDR_DQ4_IMP(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ4_IMP=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ4_LATCHN() (pst_bitDDR_DQ4_5() -> DDR_DQ4_LATCHN)
#define vSetDDR_DQ4_5_DDR_DQ4_LATCHN(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ4_LATCHN=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ5_SEL() (pst_bitDDR_DQ4_5() -> DDR_DQ5_SEL)
#define vSetDDR_DQ4_5_DDR_DQ5_SEL(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ5_SEL=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ5_PU() (pst_bitDDR_DQ4_5() -> DDR_DQ5_PU)
#define vSetDDR_DQ4_5_DDR_DQ5_PU(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ5_PU=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ5_PD() (pst_bitDDR_DQ4_5() -> DDR_DQ5_PD)
#define vSetDDR_DQ4_5_DDR_DQ5_PD(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ5_PD=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ5_SMT() (pst_bitDDR_DQ4_5() -> DDR_DQ5_SMT)
#define vSetDDR_DQ4_5_DDR_DQ5_SMT(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ5_SMT=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ5_IMP() (pst_bitDDR_DQ4_5() -> DDR_DQ5_IMP)
#define vSetDDR_DQ4_5_DDR_DQ5_IMP(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ5_IMP=(ParValue))
#define biGetDDR_DQ4_5_DDR_DQ5_LATCHN() (pst_bitDDR_DQ4_5() -> DDR_DQ5_LATCHN)
#define vSetDDR_DQ4_5_DDR_DQ5_LATCHN(ParValue)  (pst_bitDDR_DQ4_5() -> DDR_DQ5_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ4_5LL(ParValue) (pst_u8DDR_DQ4_5() -> u8LL = (ParValue))
#define u8GetDDR_DQ4_5LL() (pst_u8DDR_DQ4_5() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ4_5LH(ParValue) (pst_u8DDR_DQ4_5() -> u8LH = (ParValue))
#define u8GetDDR_DQ4_5LH() (pst_u8DDR_DQ4_5() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ4_5HL(ParValue) (pst_u8DDR_DQ4_5() -> u8HL = (ParValue))
#define u8GetDDR_DQ4_5HL() (pst_u8DDR_DQ4_5() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ4_5HH(ParValue) (pst_u8DDR_DQ4_5() -> u8HH = (ParValue))
#define u8GetDDR_DQ4_5HH() (pst_u8DDR_DQ4_5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ4_5L(ParValue) (pst_u16DDR_DQ4_5() -> u16L = (ParValue))
#define u16GetDDR_DQ4_5L() (pst_u16DDR_DQ4_5() -> u16L)
#define vSetDDR_DQ4_5H(ParValue) (pst_u16DDR_DQ4_5() -> u16H = (ParValue))
#define u16GetDDR_DQ4_5H() (pst_u16DDR_DQ4_5() -> u16H)
            
/* Word access */
#define vSetDDR_DQ4_5(ParValue)  (*pu32DDR_DQ4_5() = (ParValue))
#define u32GetDDR_DQ4_5()  (*pu32DDR_DQ4_5() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ6_7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030200C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ6_7_REG__       0xC030200CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ6_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ6_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ6_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ6_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ6_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ6_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ7_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ7_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ7_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ7_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ7_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ7_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ6_7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ6_7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ6_7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ6_7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ6_7()     ((volatile DDR_DQ6_7_bit_view_st *)\
(DDR_DQ6_7_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ6_7()     ((volatile DDR_DQ6_7_byte_view_st *)\
(DDR_DQ6_7_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ6_7()     ((volatile DDR_DQ6_7_halfword_view_st *)\
(DDR_DQ6_7_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ6_7()     ((volatile u32DDR_DQ6_7_word_view *)\
(DDR_DQ6_7_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ6_7_DDR_DQ6_SEL() (pst_bitDDR_DQ6_7() -> DDR_DQ6_SEL)
#define vSetDDR_DQ6_7_DDR_DQ6_SEL(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ6_SEL=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ6_PU() (pst_bitDDR_DQ6_7() -> DDR_DQ6_PU)
#define vSetDDR_DQ6_7_DDR_DQ6_PU(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ6_PU=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ6_PD() (pst_bitDDR_DQ6_7() -> DDR_DQ6_PD)
#define vSetDDR_DQ6_7_DDR_DQ6_PD(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ6_PD=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ6_SMT() (pst_bitDDR_DQ6_7() -> DDR_DQ6_SMT)
#define vSetDDR_DQ6_7_DDR_DQ6_SMT(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ6_SMT=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ6_IMP() (pst_bitDDR_DQ6_7() -> DDR_DQ6_IMP)
#define vSetDDR_DQ6_7_DDR_DQ6_IMP(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ6_IMP=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ6_LATCHN() (pst_bitDDR_DQ6_7() -> DDR_DQ6_LATCHN)
#define vSetDDR_DQ6_7_DDR_DQ6_LATCHN(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ6_LATCHN=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ7_SEL() (pst_bitDDR_DQ6_7() -> DDR_DQ7_SEL)
#define vSetDDR_DQ6_7_DDR_DQ7_SEL(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ7_SEL=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ7_PU() (pst_bitDDR_DQ6_7() -> DDR_DQ7_PU)
#define vSetDDR_DQ6_7_DDR_DQ7_PU(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ7_PU=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ7_PD() (pst_bitDDR_DQ6_7() -> DDR_DQ7_PD)
#define vSetDDR_DQ6_7_DDR_DQ7_PD(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ7_PD=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ7_SMT() (pst_bitDDR_DQ6_7() -> DDR_DQ7_SMT)
#define vSetDDR_DQ6_7_DDR_DQ7_SMT(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ7_SMT=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ7_IMP() (pst_bitDDR_DQ6_7() -> DDR_DQ7_IMP)
#define vSetDDR_DQ6_7_DDR_DQ7_IMP(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ7_IMP=(ParValue))
#define biGetDDR_DQ6_7_DDR_DQ7_LATCHN() (pst_bitDDR_DQ6_7() -> DDR_DQ7_LATCHN)
#define vSetDDR_DQ6_7_DDR_DQ7_LATCHN(ParValue)  (pst_bitDDR_DQ6_7() -> DDR_DQ7_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ6_7LL(ParValue) (pst_u8DDR_DQ6_7() -> u8LL = (ParValue))
#define u8GetDDR_DQ6_7LL() (pst_u8DDR_DQ6_7() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ6_7LH(ParValue) (pst_u8DDR_DQ6_7() -> u8LH = (ParValue))
#define u8GetDDR_DQ6_7LH() (pst_u8DDR_DQ6_7() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ6_7HL(ParValue) (pst_u8DDR_DQ6_7() -> u8HL = (ParValue))
#define u8GetDDR_DQ6_7HL() (pst_u8DDR_DQ6_7() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ6_7HH(ParValue) (pst_u8DDR_DQ6_7() -> u8HH = (ParValue))
#define u8GetDDR_DQ6_7HH() (pst_u8DDR_DQ6_7() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ6_7L(ParValue) (pst_u16DDR_DQ6_7() -> u16L = (ParValue))
#define u16GetDDR_DQ6_7L() (pst_u16DDR_DQ6_7() -> u16L)
#define vSetDDR_DQ6_7H(ParValue) (pst_u16DDR_DQ6_7() -> u16H = (ParValue))
#define u16GetDDR_DQ6_7H() (pst_u16DDR_DQ6_7() -> u16H)
            
/* Word access */
#define vSetDDR_DQ6_7(ParValue)  (*pu32DDR_DQ6_7() = (ParValue))
#define u32GetDDR_DQ6_7()  (*pu32DDR_DQ6_7() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ8_9                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ8_9_REG__       0xC0302010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ8_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ8_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ8_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ8_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ8_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ8_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ9_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ9_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ9_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ9_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ9_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ9_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ8_9_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ8_9_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ8_9_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ8_9_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ8_9()     ((volatile DDR_DQ8_9_bit_view_st *)\
(DDR_DQ8_9_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ8_9()     ((volatile DDR_DQ8_9_byte_view_st *)\
(DDR_DQ8_9_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ8_9()     ((volatile DDR_DQ8_9_halfword_view_st *)\
(DDR_DQ8_9_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ8_9()     ((volatile u32DDR_DQ8_9_word_view *)\
(DDR_DQ8_9_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ8_9_DDR_DQ8_SEL() (pst_bitDDR_DQ8_9() -> DDR_DQ8_SEL)
#define vSetDDR_DQ8_9_DDR_DQ8_SEL(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ8_SEL=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ8_PU() (pst_bitDDR_DQ8_9() -> DDR_DQ8_PU)
#define vSetDDR_DQ8_9_DDR_DQ8_PU(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ8_PU=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ8_PD() (pst_bitDDR_DQ8_9() -> DDR_DQ8_PD)
#define vSetDDR_DQ8_9_DDR_DQ8_PD(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ8_PD=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ8_SMT() (pst_bitDDR_DQ8_9() -> DDR_DQ8_SMT)
#define vSetDDR_DQ8_9_DDR_DQ8_SMT(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ8_SMT=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ8_IMP() (pst_bitDDR_DQ8_9() -> DDR_DQ8_IMP)
#define vSetDDR_DQ8_9_DDR_DQ8_IMP(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ8_IMP=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ8_LATCHN() (pst_bitDDR_DQ8_9() -> DDR_DQ8_LATCHN)
#define vSetDDR_DQ8_9_DDR_DQ8_LATCHN(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ8_LATCHN=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ9_SEL() (pst_bitDDR_DQ8_9() -> DDR_DQ9_SEL)
#define vSetDDR_DQ8_9_DDR_DQ9_SEL(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ9_SEL=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ9_PU() (pst_bitDDR_DQ8_9() -> DDR_DQ9_PU)
#define vSetDDR_DQ8_9_DDR_DQ9_PU(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ9_PU=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ9_PD() (pst_bitDDR_DQ8_9() -> DDR_DQ9_PD)
#define vSetDDR_DQ8_9_DDR_DQ9_PD(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ9_PD=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ9_SMT() (pst_bitDDR_DQ8_9() -> DDR_DQ9_SMT)
#define vSetDDR_DQ8_9_DDR_DQ9_SMT(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ9_SMT=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ9_IMP() (pst_bitDDR_DQ8_9() -> DDR_DQ9_IMP)
#define vSetDDR_DQ8_9_DDR_DQ9_IMP(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ9_IMP=(ParValue))
#define biGetDDR_DQ8_9_DDR_DQ9_LATCHN() (pst_bitDDR_DQ8_9() -> DDR_DQ9_LATCHN)
#define vSetDDR_DQ8_9_DDR_DQ9_LATCHN(ParValue)  (pst_bitDDR_DQ8_9() -> DDR_DQ9_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ8_9LL(ParValue) (pst_u8DDR_DQ8_9() -> u8LL = (ParValue))
#define u8GetDDR_DQ8_9LL() (pst_u8DDR_DQ8_9() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ8_9LH(ParValue) (pst_u8DDR_DQ8_9() -> u8LH = (ParValue))
#define u8GetDDR_DQ8_9LH() (pst_u8DDR_DQ8_9() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ8_9HL(ParValue) (pst_u8DDR_DQ8_9() -> u8HL = (ParValue))
#define u8GetDDR_DQ8_9HL() (pst_u8DDR_DQ8_9() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ8_9HH(ParValue) (pst_u8DDR_DQ8_9() -> u8HH = (ParValue))
#define u8GetDDR_DQ8_9HH() (pst_u8DDR_DQ8_9() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ8_9L(ParValue) (pst_u16DDR_DQ8_9() -> u16L = (ParValue))
#define u16GetDDR_DQ8_9L() (pst_u16DDR_DQ8_9() -> u16L)
#define vSetDDR_DQ8_9H(ParValue) (pst_u16DDR_DQ8_9() -> u16H = (ParValue))
#define u16GetDDR_DQ8_9H() (pst_u16DDR_DQ8_9() -> u16H)
            
/* Word access */
#define vSetDDR_DQ8_9(ParValue)  (*pu32DDR_DQ8_9() = (ParValue))
#define u32GetDDR_DQ8_9()  (*pu32DDR_DQ8_9() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ10_11                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302014                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ10_11_REG__       0xC0302014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ10_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ10_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ10_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ10_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ10_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ10_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ11_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ11_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ11_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ11_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ11_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ11_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ10_11_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ10_11_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ10_11_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ10_11_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ10_11()     ((volatile DDR_DQ10_11_bit_view_st *)\
(DDR_DQ10_11_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ10_11()     ((volatile DDR_DQ10_11_byte_view_st *)\
(DDR_DQ10_11_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ10_11()     ((volatile DDR_DQ10_11_halfword_view_st *)\
(DDR_DQ10_11_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ10_11()     ((volatile u32DDR_DQ10_11_word_view *)\
(DDR_DQ10_11_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ10_11_DDR_DQ10_SEL() (pst_bitDDR_DQ10_11() -> DDR_DQ10_SEL)
#define vSetDDR_DQ10_11_DDR_DQ10_SEL(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ10_SEL=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ10_PU() (pst_bitDDR_DQ10_11() -> DDR_DQ10_PU)
#define vSetDDR_DQ10_11_DDR_DQ10_PU(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ10_PU=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ10_PD() (pst_bitDDR_DQ10_11() -> DDR_DQ10_PD)
#define vSetDDR_DQ10_11_DDR_DQ10_PD(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ10_PD=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ10_SMT() (pst_bitDDR_DQ10_11() -> DDR_DQ10_SMT)
#define vSetDDR_DQ10_11_DDR_DQ10_SMT(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ10_SMT=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ10_IMP() (pst_bitDDR_DQ10_11() -> DDR_DQ10_IMP)
#define vSetDDR_DQ10_11_DDR_DQ10_IMP(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ10_IMP=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ10_LATCHN() (pst_bitDDR_DQ10_11() -> DDR_DQ10_LATCHN)
#define vSetDDR_DQ10_11_DDR_DQ10_LATCHN(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ10_LATCHN=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ11_SEL() (pst_bitDDR_DQ10_11() -> DDR_DQ11_SEL)
#define vSetDDR_DQ10_11_DDR_DQ11_SEL(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ11_SEL=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ11_PU() (pst_bitDDR_DQ10_11() -> DDR_DQ11_PU)
#define vSetDDR_DQ10_11_DDR_DQ11_PU(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ11_PU=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ11_PD() (pst_bitDDR_DQ10_11() -> DDR_DQ11_PD)
#define vSetDDR_DQ10_11_DDR_DQ11_PD(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ11_PD=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ11_SMT() (pst_bitDDR_DQ10_11() -> DDR_DQ11_SMT)
#define vSetDDR_DQ10_11_DDR_DQ11_SMT(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ11_SMT=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ11_IMP() (pst_bitDDR_DQ10_11() -> DDR_DQ11_IMP)
#define vSetDDR_DQ10_11_DDR_DQ11_IMP(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ11_IMP=(ParValue))
#define biGetDDR_DQ10_11_DDR_DQ11_LATCHN() (pst_bitDDR_DQ10_11() -> DDR_DQ11_LATCHN)
#define vSetDDR_DQ10_11_DDR_DQ11_LATCHN(ParValue)  (pst_bitDDR_DQ10_11() -> DDR_DQ11_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ10_11LL(ParValue) (pst_u8DDR_DQ10_11() -> u8LL = (ParValue))
#define u8GetDDR_DQ10_11LL() (pst_u8DDR_DQ10_11() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ10_11LH(ParValue) (pst_u8DDR_DQ10_11() -> u8LH = (ParValue))
#define u8GetDDR_DQ10_11LH() (pst_u8DDR_DQ10_11() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ10_11HL(ParValue) (pst_u8DDR_DQ10_11() -> u8HL = (ParValue))
#define u8GetDDR_DQ10_11HL() (pst_u8DDR_DQ10_11() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ10_11HH(ParValue) (pst_u8DDR_DQ10_11() -> u8HH = (ParValue))
#define u8GetDDR_DQ10_11HH() (pst_u8DDR_DQ10_11() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ10_11L(ParValue) (pst_u16DDR_DQ10_11() -> u16L = (ParValue))
#define u16GetDDR_DQ10_11L() (pst_u16DDR_DQ10_11() -> u16L)
#define vSetDDR_DQ10_11H(ParValue) (pst_u16DDR_DQ10_11() -> u16H = (ParValue))
#define u16GetDDR_DQ10_11H() (pst_u16DDR_DQ10_11() -> u16H)
            
/* Word access */
#define vSetDDR_DQ10_11(ParValue)  (*pu32DDR_DQ10_11() = (ParValue))
#define u32GetDDR_DQ10_11()  (*pu32DDR_DQ10_11() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ12_13                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ12_13_REG__       0xC0302018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ12_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ12_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ12_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ12_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ12_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ12_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ13_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ13_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ13_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ13_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ13_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ13_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ12_13_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ12_13_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ12_13_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ12_13_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ12_13()     ((volatile DDR_DQ12_13_bit_view_st *)\
(DDR_DQ12_13_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ12_13()     ((volatile DDR_DQ12_13_byte_view_st *)\
(DDR_DQ12_13_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ12_13()     ((volatile DDR_DQ12_13_halfword_view_st *)\
(DDR_DQ12_13_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ12_13()     ((volatile u32DDR_DQ12_13_word_view *)\
(DDR_DQ12_13_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ12_13_DDR_DQ12_SEL() (pst_bitDDR_DQ12_13() -> DDR_DQ12_SEL)
#define vSetDDR_DQ12_13_DDR_DQ12_SEL(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ12_SEL=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ12_PU() (pst_bitDDR_DQ12_13() -> DDR_DQ12_PU)
#define vSetDDR_DQ12_13_DDR_DQ12_PU(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ12_PU=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ12_PD() (pst_bitDDR_DQ12_13() -> DDR_DQ12_PD)
#define vSetDDR_DQ12_13_DDR_DQ12_PD(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ12_PD=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ12_SMT() (pst_bitDDR_DQ12_13() -> DDR_DQ12_SMT)
#define vSetDDR_DQ12_13_DDR_DQ12_SMT(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ12_SMT=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ12_IMP() (pst_bitDDR_DQ12_13() -> DDR_DQ12_IMP)
#define vSetDDR_DQ12_13_DDR_DQ12_IMP(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ12_IMP=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ12_LATCHN() (pst_bitDDR_DQ12_13() -> DDR_DQ12_LATCHN)
#define vSetDDR_DQ12_13_DDR_DQ12_LATCHN(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ12_LATCHN=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ13_SEL() (pst_bitDDR_DQ12_13() -> DDR_DQ13_SEL)
#define vSetDDR_DQ12_13_DDR_DQ13_SEL(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ13_SEL=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ13_PU() (pst_bitDDR_DQ12_13() -> DDR_DQ13_PU)
#define vSetDDR_DQ12_13_DDR_DQ13_PU(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ13_PU=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ13_PD() (pst_bitDDR_DQ12_13() -> DDR_DQ13_PD)
#define vSetDDR_DQ12_13_DDR_DQ13_PD(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ13_PD=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ13_SMT() (pst_bitDDR_DQ12_13() -> DDR_DQ13_SMT)
#define vSetDDR_DQ12_13_DDR_DQ13_SMT(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ13_SMT=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ13_IMP() (pst_bitDDR_DQ12_13() -> DDR_DQ13_IMP)
#define vSetDDR_DQ12_13_DDR_DQ13_IMP(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ13_IMP=(ParValue))
#define biGetDDR_DQ12_13_DDR_DQ13_LATCHN() (pst_bitDDR_DQ12_13() -> DDR_DQ13_LATCHN)
#define vSetDDR_DQ12_13_DDR_DQ13_LATCHN(ParValue)  (pst_bitDDR_DQ12_13() -> DDR_DQ13_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ12_13LL(ParValue) (pst_u8DDR_DQ12_13() -> u8LL = (ParValue))
#define u8GetDDR_DQ12_13LL() (pst_u8DDR_DQ12_13() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ12_13LH(ParValue) (pst_u8DDR_DQ12_13() -> u8LH = (ParValue))
#define u8GetDDR_DQ12_13LH() (pst_u8DDR_DQ12_13() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ12_13HL(ParValue) (pst_u8DDR_DQ12_13() -> u8HL = (ParValue))
#define u8GetDDR_DQ12_13HL() (pst_u8DDR_DQ12_13() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ12_13HH(ParValue) (pst_u8DDR_DQ12_13() -> u8HH = (ParValue))
#define u8GetDDR_DQ12_13HH() (pst_u8DDR_DQ12_13() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ12_13L(ParValue) (pst_u16DDR_DQ12_13() -> u16L = (ParValue))
#define u16GetDDR_DQ12_13L() (pst_u16DDR_DQ12_13() -> u16L)
#define vSetDDR_DQ12_13H(ParValue) (pst_u16DDR_DQ12_13() -> u16H = (ParValue))
#define u16GetDDR_DQ12_13H() (pst_u16DDR_DQ12_13() -> u16H)
            
/* Word access */
#define vSetDDR_DQ12_13(ParValue)  (*pu32DDR_DQ12_13() = (ParValue))
#define u32GetDDR_DQ12_13()  (*pu32DDR_DQ12_13() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ14_15                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030201C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ14_15_REG__       0xC030201CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ14_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ14_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ14_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ14_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ14_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ14_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ15_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ15_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ15_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ15_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ15_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ15_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ14_15_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ14_15_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ14_15_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ14_15_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ14_15()     ((volatile DDR_DQ14_15_bit_view_st *)\
(DDR_DQ14_15_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ14_15()     ((volatile DDR_DQ14_15_byte_view_st *)\
(DDR_DQ14_15_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ14_15()     ((volatile DDR_DQ14_15_halfword_view_st *)\
(DDR_DQ14_15_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ14_15()     ((volatile u32DDR_DQ14_15_word_view *)\
(DDR_DQ14_15_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ14_15_DDR_DQ14_SEL() (pst_bitDDR_DQ14_15() -> DDR_DQ14_SEL)
#define vSetDDR_DQ14_15_DDR_DQ14_SEL(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ14_SEL=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ14_PU() (pst_bitDDR_DQ14_15() -> DDR_DQ14_PU)
#define vSetDDR_DQ14_15_DDR_DQ14_PU(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ14_PU=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ14_PD() (pst_bitDDR_DQ14_15() -> DDR_DQ14_PD)
#define vSetDDR_DQ14_15_DDR_DQ14_PD(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ14_PD=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ14_SMT() (pst_bitDDR_DQ14_15() -> DDR_DQ14_SMT)
#define vSetDDR_DQ14_15_DDR_DQ14_SMT(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ14_SMT=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ14_IMP() (pst_bitDDR_DQ14_15() -> DDR_DQ14_IMP)
#define vSetDDR_DQ14_15_DDR_DQ14_IMP(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ14_IMP=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ14_LATCHN() (pst_bitDDR_DQ14_15() -> DDR_DQ14_LATCHN)
#define vSetDDR_DQ14_15_DDR_DQ14_LATCHN(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ14_LATCHN=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ15_SEL() (pst_bitDDR_DQ14_15() -> DDR_DQ15_SEL)
#define vSetDDR_DQ14_15_DDR_DQ15_SEL(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ15_SEL=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ15_PU() (pst_bitDDR_DQ14_15() -> DDR_DQ15_PU)
#define vSetDDR_DQ14_15_DDR_DQ15_PU(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ15_PU=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ15_PD() (pst_bitDDR_DQ14_15() -> DDR_DQ15_PD)
#define vSetDDR_DQ14_15_DDR_DQ15_PD(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ15_PD=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ15_SMT() (pst_bitDDR_DQ14_15() -> DDR_DQ15_SMT)
#define vSetDDR_DQ14_15_DDR_DQ15_SMT(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ15_SMT=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ15_IMP() (pst_bitDDR_DQ14_15() -> DDR_DQ15_IMP)
#define vSetDDR_DQ14_15_DDR_DQ15_IMP(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ15_IMP=(ParValue))
#define biGetDDR_DQ14_15_DDR_DQ15_LATCHN() (pst_bitDDR_DQ14_15() -> DDR_DQ15_LATCHN)
#define vSetDDR_DQ14_15_DDR_DQ15_LATCHN(ParValue)  (pst_bitDDR_DQ14_15() -> DDR_DQ15_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ14_15LL(ParValue) (pst_u8DDR_DQ14_15() -> u8LL = (ParValue))
#define u8GetDDR_DQ14_15LL() (pst_u8DDR_DQ14_15() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ14_15LH(ParValue) (pst_u8DDR_DQ14_15() -> u8LH = (ParValue))
#define u8GetDDR_DQ14_15LH() (pst_u8DDR_DQ14_15() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ14_15HL(ParValue) (pst_u8DDR_DQ14_15() -> u8HL = (ParValue))
#define u8GetDDR_DQ14_15HL() (pst_u8DDR_DQ14_15() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ14_15HH(ParValue) (pst_u8DDR_DQ14_15() -> u8HH = (ParValue))
#define u8GetDDR_DQ14_15HH() (pst_u8DDR_DQ14_15() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ14_15L(ParValue) (pst_u16DDR_DQ14_15() -> u16L = (ParValue))
#define u16GetDDR_DQ14_15L() (pst_u16DDR_DQ14_15() -> u16L)
#define vSetDDR_DQ14_15H(ParValue) (pst_u16DDR_DQ14_15() -> u16H = (ParValue))
#define u16GetDDR_DQ14_15H() (pst_u16DDR_DQ14_15() -> u16H)
            
/* Word access */
#define vSetDDR_DQ14_15(ParValue)  (*pu32DDR_DQ14_15() = (ParValue))
#define u32GetDDR_DQ14_15()  (*pu32DDR_DQ14_15() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DM0_1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DM0_1_REG__       0xC0302020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DM0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DM0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DM0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DM0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DM0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DM0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DM1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DM1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DM1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DM1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DM1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DM1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DM0_1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DM0_1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DM0_1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DM0_1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DM0_1()     ((volatile DDR_DM0_1_bit_view_st *)\
(DDR_DM0_1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DM0_1()     ((volatile DDR_DM0_1_byte_view_st *)\
(DDR_DM0_1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DM0_1()     ((volatile DDR_DM0_1_halfword_view_st *)\
(DDR_DM0_1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DM0_1()     ((volatile u32DDR_DM0_1_word_view *)\
(DDR_DM0_1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DM0_1_DDR_DM0_SEL() (pst_bitDDR_DM0_1() -> DDR_DM0_SEL)
#define vSetDDR_DM0_1_DDR_DM0_SEL(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM0_SEL=(ParValue))
#define biGetDDR_DM0_1_DDR_DM0_PU() (pst_bitDDR_DM0_1() -> DDR_DM0_PU)
#define vSetDDR_DM0_1_DDR_DM0_PU(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM0_PU=(ParValue))
#define biGetDDR_DM0_1_DDR_DM0_PD() (pst_bitDDR_DM0_1() -> DDR_DM0_PD)
#define vSetDDR_DM0_1_DDR_DM0_PD(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM0_PD=(ParValue))
#define biGetDDR_DM0_1_DDR_DM0_SMT() (pst_bitDDR_DM0_1() -> DDR_DM0_SMT)
#define vSetDDR_DM0_1_DDR_DM0_SMT(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM0_SMT=(ParValue))
#define biGetDDR_DM0_1_DDR_DM0_IMP() (pst_bitDDR_DM0_1() -> DDR_DM0_IMP)
#define vSetDDR_DM0_1_DDR_DM0_IMP(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM0_IMP=(ParValue))
#define biGetDDR_DM0_1_DDR_DM0_LATCHN() (pst_bitDDR_DM0_1() -> DDR_DM0_LATCHN)
#define vSetDDR_DM0_1_DDR_DM0_LATCHN(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM0_LATCHN=(ParValue))
#define biGetDDR_DM0_1_DDR_DM1_SEL() (pst_bitDDR_DM0_1() -> DDR_DM1_SEL)
#define vSetDDR_DM0_1_DDR_DM1_SEL(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM1_SEL=(ParValue))
#define biGetDDR_DM0_1_DDR_DM1_PU() (pst_bitDDR_DM0_1() -> DDR_DM1_PU)
#define vSetDDR_DM0_1_DDR_DM1_PU(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM1_PU=(ParValue))
#define biGetDDR_DM0_1_DDR_DM1_PD() (pst_bitDDR_DM0_1() -> DDR_DM1_PD)
#define vSetDDR_DM0_1_DDR_DM1_PD(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM1_PD=(ParValue))
#define biGetDDR_DM0_1_DDR_DM1_SMT() (pst_bitDDR_DM0_1() -> DDR_DM1_SMT)
#define vSetDDR_DM0_1_DDR_DM1_SMT(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM1_SMT=(ParValue))
#define biGetDDR_DM0_1_DDR_DM1_IMP() (pst_bitDDR_DM0_1() -> DDR_DM1_IMP)
#define vSetDDR_DM0_1_DDR_DM1_IMP(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM1_IMP=(ParValue))
#define biGetDDR_DM0_1_DDR_DM1_LATCHN() (pst_bitDDR_DM0_1() -> DDR_DM1_LATCHN)
#define vSetDDR_DM0_1_DDR_DM1_LATCHN(ParValue)  (pst_bitDDR_DM0_1() -> DDR_DM1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DM0_1LL(ParValue) (pst_u8DDR_DM0_1() -> u8LL = (ParValue))
#define u8GetDDR_DM0_1LL() (pst_u8DDR_DM0_1() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DM0_1LH(ParValue) (pst_u8DDR_DM0_1() -> u8LH = (ParValue))
#define u8GetDDR_DM0_1LH() (pst_u8DDR_DM0_1() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DM0_1HL(ParValue) (pst_u8DDR_DM0_1() -> u8HL = (ParValue))
#define u8GetDDR_DM0_1HL() (pst_u8DDR_DM0_1() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DM0_1HH(ParValue) (pst_u8DDR_DM0_1() -> u8HH = (ParValue))
#define u8GetDDR_DM0_1HH() (pst_u8DDR_DM0_1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DM0_1L(ParValue) (pst_u16DDR_DM0_1() -> u16L = (ParValue))
#define u16GetDDR_DM0_1L() (pst_u16DDR_DM0_1() -> u16L)
#define vSetDDR_DM0_1H(ParValue) (pst_u16DDR_DM0_1() -> u16H = (ParValue))
#define u16GetDDR_DM0_1H() (pst_u16DDR_DM0_1() -> u16H)
            
/* Word access */
#define vSetDDR_DM0_1(ParValue)  (*pu32DDR_DM0_1() = (ParValue))
#define u32GetDDR_DM0_1()  (*pu32DDR_DM0_1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_WE_RAS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302024                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_WE_RAS_REG__       0xC0302024U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_WE_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_WE_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_WE_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_WE_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_WE_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_WE_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_RAS_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_RAS_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_RAS_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_RAS_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_RAS_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_RAS_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_WE_RAS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_WE_RAS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_WE_RAS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_WE_RAS_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_WE_RAS()     ((volatile DDR_WE_RAS_bit_view_st *)\
(DDR_WE_RAS_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_WE_RAS()     ((volatile DDR_WE_RAS_byte_view_st *)\
(DDR_WE_RAS_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_WE_RAS()     ((volatile DDR_WE_RAS_halfword_view_st *)\
(DDR_WE_RAS_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_WE_RAS()     ((volatile u32DDR_WE_RAS_word_view *)\
(DDR_WE_RAS_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_WE_RAS_DDR_WE_SEL() (pst_bitDDR_WE_RAS() -> DDR_WE_SEL)
#define vSetDDR_WE_RAS_DDR_WE_SEL(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_WE_SEL=(ParValue))
#define biGetDDR_WE_RAS_DDR_WE_PU() (pst_bitDDR_WE_RAS() -> DDR_WE_PU)
#define vSetDDR_WE_RAS_DDR_WE_PU(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_WE_PU=(ParValue))
#define biGetDDR_WE_RAS_DDR_WE_PD() (pst_bitDDR_WE_RAS() -> DDR_WE_PD)
#define vSetDDR_WE_RAS_DDR_WE_PD(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_WE_PD=(ParValue))
#define biGetDDR_WE_RAS_DDR_WE_SMT() (pst_bitDDR_WE_RAS() -> DDR_WE_SMT)
#define vSetDDR_WE_RAS_DDR_WE_SMT(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_WE_SMT=(ParValue))
#define biGetDDR_WE_RAS_DDR_WE_IMP() (pst_bitDDR_WE_RAS() -> DDR_WE_IMP)
#define vSetDDR_WE_RAS_DDR_WE_IMP(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_WE_IMP=(ParValue))
#define biGetDDR_WE_RAS_DDR_WE_LATCHN() (pst_bitDDR_WE_RAS() -> DDR_WE_LATCHN)
#define vSetDDR_WE_RAS_DDR_WE_LATCHN(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_WE_LATCHN=(ParValue))
#define biGetDDR_WE_RAS_DDR_RAS_SEL() (pst_bitDDR_WE_RAS() -> DDR_RAS_SEL)
#define vSetDDR_WE_RAS_DDR_RAS_SEL(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_RAS_SEL=(ParValue))
#define biGetDDR_WE_RAS_DDR_RAS_PU() (pst_bitDDR_WE_RAS() -> DDR_RAS_PU)
#define vSetDDR_WE_RAS_DDR_RAS_PU(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_RAS_PU=(ParValue))
#define biGetDDR_WE_RAS_DDR_RAS_PD() (pst_bitDDR_WE_RAS() -> DDR_RAS_PD)
#define vSetDDR_WE_RAS_DDR_RAS_PD(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_RAS_PD=(ParValue))
#define biGetDDR_WE_RAS_DDR_RAS_SMT() (pst_bitDDR_WE_RAS() -> DDR_RAS_SMT)
#define vSetDDR_WE_RAS_DDR_RAS_SMT(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_RAS_SMT=(ParValue))
#define biGetDDR_WE_RAS_DDR_RAS_IMP() (pst_bitDDR_WE_RAS() -> DDR_RAS_IMP)
#define vSetDDR_WE_RAS_DDR_RAS_IMP(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_RAS_IMP=(ParValue))
#define biGetDDR_WE_RAS_DDR_RAS_LATCHN() (pst_bitDDR_WE_RAS() -> DDR_RAS_LATCHN)
#define vSetDDR_WE_RAS_DDR_RAS_LATCHN(ParValue)  (pst_bitDDR_WE_RAS() -> DDR_RAS_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_WE_RASLL(ParValue) (pst_u8DDR_WE_RAS() -> u8LL = (ParValue))
#define u8GetDDR_WE_RASLL() (pst_u8DDR_WE_RAS() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_WE_RASLH(ParValue) (pst_u8DDR_WE_RAS() -> u8LH = (ParValue))
#define u8GetDDR_WE_RASLH() (pst_u8DDR_WE_RAS() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_WE_RASHL(ParValue) (pst_u8DDR_WE_RAS() -> u8HL = (ParValue))
#define u8GetDDR_WE_RASHL() (pst_u8DDR_WE_RAS() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_WE_RASHH(ParValue) (pst_u8DDR_WE_RAS() -> u8HH = (ParValue))
#define u8GetDDR_WE_RASHH() (pst_u8DDR_WE_RAS() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_WE_RASL(ParValue) (pst_u16DDR_WE_RAS() -> u16L = (ParValue))
#define u16GetDDR_WE_RASL() (pst_u16DDR_WE_RAS() -> u16L)
#define vSetDDR_WE_RASH(ParValue) (pst_u16DDR_WE_RAS() -> u16H = (ParValue))
#define u16GetDDR_WE_RASH() (pst_u16DDR_WE_RAS() -> u16H)
            
/* Word access */
#define vSetDDR_WE_RAS(ParValue)  (*pu32DDR_WE_RAS() = (ParValue))
#define u32GetDDR_WE_RAS()  (*pu32DDR_WE_RAS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_CAS_CS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302028                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_CAS_CS_REG__       0xC0302028U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_CAS_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_CAS_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_CAS_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_CAS_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_CAS_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_CAS_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_CS_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_CS_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_CS_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_CS_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_CS_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_CS_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_CAS_CS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_CAS_CS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_CAS_CS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_CAS_CS_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_CAS_CS()     ((volatile DDR_CAS_CS_bit_view_st *)\
(DDR_CAS_CS_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_CAS_CS()     ((volatile DDR_CAS_CS_byte_view_st *)\
(DDR_CAS_CS_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_CAS_CS()     ((volatile DDR_CAS_CS_halfword_view_st *)\
(DDR_CAS_CS_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_CAS_CS()     ((volatile u32DDR_CAS_CS_word_view *)\
(DDR_CAS_CS_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_CAS_CS_DDR_CAS_SEL() (pst_bitDDR_CAS_CS() -> DDR_CAS_SEL)
#define vSetDDR_CAS_CS_DDR_CAS_SEL(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CAS_SEL=(ParValue))
#define biGetDDR_CAS_CS_DDR_CAS_PU() (pst_bitDDR_CAS_CS() -> DDR_CAS_PU)
#define vSetDDR_CAS_CS_DDR_CAS_PU(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CAS_PU=(ParValue))
#define biGetDDR_CAS_CS_DDR_CAS_PD() (pst_bitDDR_CAS_CS() -> DDR_CAS_PD)
#define vSetDDR_CAS_CS_DDR_CAS_PD(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CAS_PD=(ParValue))
#define biGetDDR_CAS_CS_DDR_CAS_SMT() (pst_bitDDR_CAS_CS() -> DDR_CAS_SMT)
#define vSetDDR_CAS_CS_DDR_CAS_SMT(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CAS_SMT=(ParValue))
#define biGetDDR_CAS_CS_DDR_CAS_IMP() (pst_bitDDR_CAS_CS() -> DDR_CAS_IMP)
#define vSetDDR_CAS_CS_DDR_CAS_IMP(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CAS_IMP=(ParValue))
#define biGetDDR_CAS_CS_DDR_CAS_LATCHN() (pst_bitDDR_CAS_CS() -> DDR_CAS_LATCHN)
#define vSetDDR_CAS_CS_DDR_CAS_LATCHN(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CAS_LATCHN=(ParValue))
#define biGetDDR_CAS_CS_DDR_CS_SEL() (pst_bitDDR_CAS_CS() -> DDR_CS_SEL)
#define vSetDDR_CAS_CS_DDR_CS_SEL(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CS_SEL=(ParValue))
#define biGetDDR_CAS_CS_DDR_CS_PU() (pst_bitDDR_CAS_CS() -> DDR_CS_PU)
#define vSetDDR_CAS_CS_DDR_CS_PU(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CS_PU=(ParValue))
#define biGetDDR_CAS_CS_DDR_CS_PD() (pst_bitDDR_CAS_CS() -> DDR_CS_PD)
#define vSetDDR_CAS_CS_DDR_CS_PD(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CS_PD=(ParValue))
#define biGetDDR_CAS_CS_DDR_CS_SMT() (pst_bitDDR_CAS_CS() -> DDR_CS_SMT)
#define vSetDDR_CAS_CS_DDR_CS_SMT(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CS_SMT=(ParValue))
#define biGetDDR_CAS_CS_DDR_CS_IMP() (pst_bitDDR_CAS_CS() -> DDR_CS_IMP)
#define vSetDDR_CAS_CS_DDR_CS_IMP(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CS_IMP=(ParValue))
#define biGetDDR_CAS_CS_DDR_CS_LATCHN() (pst_bitDDR_CAS_CS() -> DDR_CS_LATCHN)
#define vSetDDR_CAS_CS_DDR_CS_LATCHN(ParValue)  (pst_bitDDR_CAS_CS() -> DDR_CS_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_CAS_CSLL(ParValue) (pst_u8DDR_CAS_CS() -> u8LL = (ParValue))
#define u8GetDDR_CAS_CSLL() (pst_u8DDR_CAS_CS() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_CAS_CSLH(ParValue) (pst_u8DDR_CAS_CS() -> u8LH = (ParValue))
#define u8GetDDR_CAS_CSLH() (pst_u8DDR_CAS_CS() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_CAS_CSHL(ParValue) (pst_u8DDR_CAS_CS() -> u8HL = (ParValue))
#define u8GetDDR_CAS_CSHL() (pst_u8DDR_CAS_CS() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_CAS_CSHH(ParValue) (pst_u8DDR_CAS_CS() -> u8HH = (ParValue))
#define u8GetDDR_CAS_CSHH() (pst_u8DDR_CAS_CS() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_CAS_CSL(ParValue) (pst_u16DDR_CAS_CS() -> u16L = (ParValue))
#define u16GetDDR_CAS_CSL() (pst_u16DDR_CAS_CS() -> u16L)
#define vSetDDR_CAS_CSH(ParValue) (pst_u16DDR_CAS_CS() -> u16H = (ParValue))
#define u16GetDDR_CAS_CSH() (pst_u16DDR_CAS_CS() -> u16H)
            
/* Word access */
#define vSetDDR_CAS_CS(ParValue)  (*pu32DDR_CAS_CS() = (ParValue))
#define u32GetDDR_CAS_CS()  (*pu32DDR_CAS_CS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_CKE_CK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030202C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_CKE_CK_REG__       0xC030202CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_CKE_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_CKE_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_CKE_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_CKE_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_CKE_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_CKE_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   DDR_CK_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_CK_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_CK_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_CK_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_CK_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_CKE_CK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_CKE_CK_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_CKE_CK_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_CKE_CK_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_CKE_CK()     ((volatile DDR_CKE_CK_bit_view_st *)\
(DDR_CKE_CK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_CKE_CK()     ((volatile DDR_CKE_CK_byte_view_st *)\
(DDR_CKE_CK_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_CKE_CK()     ((volatile DDR_CKE_CK_halfword_view_st *)\
(DDR_CKE_CK_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_CKE_CK()     ((volatile u32DDR_CKE_CK_word_view *)\
(DDR_CKE_CK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_CKE_CK_DDR_CKE_SEL() (pst_bitDDR_CKE_CK() -> DDR_CKE_SEL)
#define vSetDDR_CKE_CK_DDR_CKE_SEL(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CKE_SEL=(ParValue))
#define biGetDDR_CKE_CK_DDR_CKE_PU() (pst_bitDDR_CKE_CK() -> DDR_CKE_PU)
#define vSetDDR_CKE_CK_DDR_CKE_PU(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CKE_PU=(ParValue))
#define biGetDDR_CKE_CK_DDR_CKE_PD() (pst_bitDDR_CKE_CK() -> DDR_CKE_PD)
#define vSetDDR_CKE_CK_DDR_CKE_PD(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CKE_PD=(ParValue))
#define biGetDDR_CKE_CK_DDR_CKE_SMT() (pst_bitDDR_CKE_CK() -> DDR_CKE_SMT)
#define vSetDDR_CKE_CK_DDR_CKE_SMT(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CKE_SMT=(ParValue))
#define biGetDDR_CKE_CK_DDR_CKE_IMP() (pst_bitDDR_CKE_CK() -> DDR_CKE_IMP)
#define vSetDDR_CKE_CK_DDR_CKE_IMP(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CKE_IMP=(ParValue))
#define biGetDDR_CKE_CK_DDR_CKE_LATCHN() (pst_bitDDR_CKE_CK() -> DDR_CKE_LATCHN)
#define vSetDDR_CKE_CK_DDR_CKE_LATCHN(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CKE_LATCHN=(ParValue))
#define biGetDDR_CKE_CK_DDR_CK_PU() (pst_bitDDR_CKE_CK() -> DDR_CK_PU)
#define vSetDDR_CKE_CK_DDR_CK_PU(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CK_PU=(ParValue))
#define biGetDDR_CKE_CK_DDR_CK_PD() (pst_bitDDR_CKE_CK() -> DDR_CK_PD)
#define vSetDDR_CKE_CK_DDR_CK_PD(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CK_PD=(ParValue))
#define biGetDDR_CKE_CK_DDR_CK_SMT() (pst_bitDDR_CKE_CK() -> DDR_CK_SMT)
#define vSetDDR_CKE_CK_DDR_CK_SMT(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CK_SMT=(ParValue))
#define biGetDDR_CKE_CK_DDR_CK_IMP() (pst_bitDDR_CKE_CK() -> DDR_CK_IMP)
#define vSetDDR_CKE_CK_DDR_CK_IMP(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CK_IMP=(ParValue))
#define biGetDDR_CKE_CK_DDR_CK_LATCHN() (pst_bitDDR_CKE_CK() -> DDR_CK_LATCHN)
#define vSetDDR_CKE_CK_DDR_CK_LATCHN(ParValue)  (pst_bitDDR_CKE_CK() -> DDR_CK_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_CKE_CKLL(ParValue) (pst_u8DDR_CKE_CK() -> u8LL = (ParValue))
#define u8GetDDR_CKE_CKLL() (pst_u8DDR_CKE_CK() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_CKE_CKLH(ParValue) (pst_u8DDR_CKE_CK() -> u8LH = (ParValue))
#define u8GetDDR_CKE_CKLH() (pst_u8DDR_CKE_CK() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_CKE_CKHL(ParValue) (pst_u8DDR_CKE_CK() -> u8HL = (ParValue))
#define u8GetDDR_CKE_CKHL() (pst_u8DDR_CKE_CK() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_CKE_CKHH(ParValue) (pst_u8DDR_CKE_CK() -> u8HH = (ParValue))
#define u8GetDDR_CKE_CKHH() (pst_u8DDR_CKE_CK() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_CKE_CKL(ParValue) (pst_u16DDR_CKE_CK() -> u16L = (ParValue))
#define u16GetDDR_CKE_CKL() (pst_u16DDR_CKE_CK() -> u16L)
#define vSetDDR_CKE_CKH(ParValue) (pst_u16DDR_CKE_CK() -> u16H = (ParValue))
#define u16GetDDR_CKE_CKH() (pst_u16DDR_CKE_CK() -> u16H)
            
/* Word access */
#define vSetDDR_CKE_CK(ParValue)  (*pu32DDR_CKE_CK() = (ParValue))
#define u32GetDDR_CKE_CK()  (*pu32DDR_CKE_CK() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_CKN_BA0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302030                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_CKN_BA0_REG__       0xC0302030U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   DDR_CKN_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_CKN_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_CKN_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_CKN_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_CKN_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_BA0_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_BA0_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_BA0_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_BA0_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_BA0_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_BA0_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_CKN_BA0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_CKN_BA0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_CKN_BA0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_CKN_BA0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_CKN_BA0()     ((volatile DDR_CKN_BA0_bit_view_st *)\
(DDR_CKN_BA0_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_CKN_BA0()     ((volatile DDR_CKN_BA0_byte_view_st *)\
(DDR_CKN_BA0_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_CKN_BA0()     ((volatile DDR_CKN_BA0_halfword_view_st *)\
(DDR_CKN_BA0_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_CKN_BA0()     ((volatile u32DDR_CKN_BA0_word_view *)\
(DDR_CKN_BA0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_CKN_BA0_DDR_CKN_PU() (pst_bitDDR_CKN_BA0() -> DDR_CKN_PU)
#define vSetDDR_CKN_BA0_DDR_CKN_PU(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_CKN_PU=(ParValue))
#define biGetDDR_CKN_BA0_DDR_CKN_PD() (pst_bitDDR_CKN_BA0() -> DDR_CKN_PD)
#define vSetDDR_CKN_BA0_DDR_CKN_PD(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_CKN_PD=(ParValue))
#define biGetDDR_CKN_BA0_DDR_CKN_SMT() (pst_bitDDR_CKN_BA0() -> DDR_CKN_SMT)
#define vSetDDR_CKN_BA0_DDR_CKN_SMT(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_CKN_SMT=(ParValue))
#define biGetDDR_CKN_BA0_DDR_CKN_IMP() (pst_bitDDR_CKN_BA0() -> DDR_CKN_IMP)
#define vSetDDR_CKN_BA0_DDR_CKN_IMP(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_CKN_IMP=(ParValue))
#define biGetDDR_CKN_BA0_DDR_CKN_LATCHN() (pst_bitDDR_CKN_BA0() -> DDR_CKN_LATCHN)
#define vSetDDR_CKN_BA0_DDR_CKN_LATCHN(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_CKN_LATCHN=(ParValue))
#define biGetDDR_CKN_BA0_DDR_BA0_SEL() (pst_bitDDR_CKN_BA0() -> DDR_BA0_SEL)
#define vSetDDR_CKN_BA0_DDR_BA0_SEL(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_BA0_SEL=(ParValue))
#define biGetDDR_CKN_BA0_DDR_BA0_PU() (pst_bitDDR_CKN_BA0() -> DDR_BA0_PU)
#define vSetDDR_CKN_BA0_DDR_BA0_PU(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_BA0_PU=(ParValue))
#define biGetDDR_CKN_BA0_DDR_BA0_PD() (pst_bitDDR_CKN_BA0() -> DDR_BA0_PD)
#define vSetDDR_CKN_BA0_DDR_BA0_PD(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_BA0_PD=(ParValue))
#define biGetDDR_CKN_BA0_DDR_BA0_SMT() (pst_bitDDR_CKN_BA0() -> DDR_BA0_SMT)
#define vSetDDR_CKN_BA0_DDR_BA0_SMT(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_BA0_SMT=(ParValue))
#define biGetDDR_CKN_BA0_DDR_BA0_IMP() (pst_bitDDR_CKN_BA0() -> DDR_BA0_IMP)
#define vSetDDR_CKN_BA0_DDR_BA0_IMP(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_BA0_IMP=(ParValue))
#define biGetDDR_CKN_BA0_DDR_BA0_LATCHN() (pst_bitDDR_CKN_BA0() -> DDR_BA0_LATCHN)
#define vSetDDR_CKN_BA0_DDR_BA0_LATCHN(ParValue)  (pst_bitDDR_CKN_BA0() -> DDR_BA0_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_CKN_BA0LL(ParValue) (pst_u8DDR_CKN_BA0() -> u8LL = (ParValue))
#define u8GetDDR_CKN_BA0LL() (pst_u8DDR_CKN_BA0() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_CKN_BA0LH(ParValue) (pst_u8DDR_CKN_BA0() -> u8LH = (ParValue))
#define u8GetDDR_CKN_BA0LH() (pst_u8DDR_CKN_BA0() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_CKN_BA0HL(ParValue) (pst_u8DDR_CKN_BA0() -> u8HL = (ParValue))
#define u8GetDDR_CKN_BA0HL() (pst_u8DDR_CKN_BA0() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_CKN_BA0HH(ParValue) (pst_u8DDR_CKN_BA0() -> u8HH = (ParValue))
#define u8GetDDR_CKN_BA0HH() (pst_u8DDR_CKN_BA0() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_CKN_BA0L(ParValue) (pst_u16DDR_CKN_BA0() -> u16L = (ParValue))
#define u16GetDDR_CKN_BA0L() (pst_u16DDR_CKN_BA0() -> u16L)
#define vSetDDR_CKN_BA0H(ParValue) (pst_u16DDR_CKN_BA0() -> u16H = (ParValue))
#define u16GetDDR_CKN_BA0H() (pst_u16DDR_CKN_BA0() -> u16H)
            
/* Word access */
#define vSetDDR_CKN_BA0(ParValue)  (*pu32DDR_CKN_BA0() = (ParValue))
#define u32GetDDR_CKN_BA0()  (*pu32DDR_CKN_BA0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_BA1_A0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302034                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_BA1_A0_REG__       0xC0302034U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_BA1_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_BA1_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_BA1_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_BA1_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_BA1_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_BA1_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_A0_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_A0_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_A0_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_A0_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_A0_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_A0_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_BA1_A0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_BA1_A0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_BA1_A0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_BA1_A0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_BA1_A0()     ((volatile DDR_BA1_A0_bit_view_st *)\
(DDR_BA1_A0_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_BA1_A0()     ((volatile DDR_BA1_A0_byte_view_st *)\
(DDR_BA1_A0_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_BA1_A0()     ((volatile DDR_BA1_A0_halfword_view_st *)\
(DDR_BA1_A0_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_BA1_A0()     ((volatile u32DDR_BA1_A0_word_view *)\
(DDR_BA1_A0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_BA1_A0_DDR_BA1_SEL() (pst_bitDDR_BA1_A0() -> DDR_BA1_SEL)
#define vSetDDR_BA1_A0_DDR_BA1_SEL(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_BA1_SEL=(ParValue))
#define biGetDDR_BA1_A0_DDR_BA1_PU() (pst_bitDDR_BA1_A0() -> DDR_BA1_PU)
#define vSetDDR_BA1_A0_DDR_BA1_PU(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_BA1_PU=(ParValue))
#define biGetDDR_BA1_A0_DDR_BA1_PD() (pst_bitDDR_BA1_A0() -> DDR_BA1_PD)
#define vSetDDR_BA1_A0_DDR_BA1_PD(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_BA1_PD=(ParValue))
#define biGetDDR_BA1_A0_DDR_BA1_SMT() (pst_bitDDR_BA1_A0() -> DDR_BA1_SMT)
#define vSetDDR_BA1_A0_DDR_BA1_SMT(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_BA1_SMT=(ParValue))
#define biGetDDR_BA1_A0_DDR_BA1_IMP() (pst_bitDDR_BA1_A0() -> DDR_BA1_IMP)
#define vSetDDR_BA1_A0_DDR_BA1_IMP(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_BA1_IMP=(ParValue))
#define biGetDDR_BA1_A0_DDR_BA1_LATCHN() (pst_bitDDR_BA1_A0() -> DDR_BA1_LATCHN)
#define vSetDDR_BA1_A0_DDR_BA1_LATCHN(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_BA1_LATCHN=(ParValue))
#define biGetDDR_BA1_A0_DDR_A0_SEL() (pst_bitDDR_BA1_A0() -> DDR_A0_SEL)
#define vSetDDR_BA1_A0_DDR_A0_SEL(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_A0_SEL=(ParValue))
#define biGetDDR_BA1_A0_DDR_A0_PU() (pst_bitDDR_BA1_A0() -> DDR_A0_PU)
#define vSetDDR_BA1_A0_DDR_A0_PU(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_A0_PU=(ParValue))
#define biGetDDR_BA1_A0_DDR_A0_PD() (pst_bitDDR_BA1_A0() -> DDR_A0_PD)
#define vSetDDR_BA1_A0_DDR_A0_PD(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_A0_PD=(ParValue))
#define biGetDDR_BA1_A0_DDR_A0_SMT() (pst_bitDDR_BA1_A0() -> DDR_A0_SMT)
#define vSetDDR_BA1_A0_DDR_A0_SMT(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_A0_SMT=(ParValue))
#define biGetDDR_BA1_A0_DDR_A0_IMP() (pst_bitDDR_BA1_A0() -> DDR_A0_IMP)
#define vSetDDR_BA1_A0_DDR_A0_IMP(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_A0_IMP=(ParValue))
#define biGetDDR_BA1_A0_DDR_A0_LATCHN() (pst_bitDDR_BA1_A0() -> DDR_A0_LATCHN)
#define vSetDDR_BA1_A0_DDR_A0_LATCHN(ParValue)  (pst_bitDDR_BA1_A0() -> DDR_A0_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_BA1_A0LL(ParValue) (pst_u8DDR_BA1_A0() -> u8LL = (ParValue))
#define u8GetDDR_BA1_A0LL() (pst_u8DDR_BA1_A0() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_BA1_A0LH(ParValue) (pst_u8DDR_BA1_A0() -> u8LH = (ParValue))
#define u8GetDDR_BA1_A0LH() (pst_u8DDR_BA1_A0() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_BA1_A0HL(ParValue) (pst_u8DDR_BA1_A0() -> u8HL = (ParValue))
#define u8GetDDR_BA1_A0HL() (pst_u8DDR_BA1_A0() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_BA1_A0HH(ParValue) (pst_u8DDR_BA1_A0() -> u8HH = (ParValue))
#define u8GetDDR_BA1_A0HH() (pst_u8DDR_BA1_A0() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_BA1_A0L(ParValue) (pst_u16DDR_BA1_A0() -> u16L = (ParValue))
#define u16GetDDR_BA1_A0L() (pst_u16DDR_BA1_A0() -> u16L)
#define vSetDDR_BA1_A0H(ParValue) (pst_u16DDR_BA1_A0() -> u16H = (ParValue))
#define u16GetDDR_BA1_A0H() (pst_u16DDR_BA1_A0() -> u16H)
            
/* Word access */
#define vSetDDR_BA1_A0(ParValue)  (*pu32DDR_BA1_A0() = (ParValue))
#define u32GetDDR_BA1_A0()  (*pu32DDR_BA1_A0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_A1_A2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302038                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_A1_A2_REG__       0xC0302038U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_A1_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_A1_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_A1_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_A1_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_A1_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_A1_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_A2_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_A2_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_A2_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_A2_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_A2_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_A2_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_A1_A2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_A1_A2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_A1_A2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_A1_A2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_A1_A2()     ((volatile DDR_A1_A2_bit_view_st *)\
(DDR_A1_A2_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_A1_A2()     ((volatile DDR_A1_A2_byte_view_st *)\
(DDR_A1_A2_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_A1_A2()     ((volatile DDR_A1_A2_halfword_view_st *)\
(DDR_A1_A2_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_A1_A2()     ((volatile u32DDR_A1_A2_word_view *)\
(DDR_A1_A2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_A1_A2_DDR_A1_SEL() (pst_bitDDR_A1_A2() -> DDR_A1_SEL)
#define vSetDDR_A1_A2_DDR_A1_SEL(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A1_SEL=(ParValue))
#define biGetDDR_A1_A2_DDR_A1_PU() (pst_bitDDR_A1_A2() -> DDR_A1_PU)
#define vSetDDR_A1_A2_DDR_A1_PU(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A1_PU=(ParValue))
#define biGetDDR_A1_A2_DDR_A1_PD() (pst_bitDDR_A1_A2() -> DDR_A1_PD)
#define vSetDDR_A1_A2_DDR_A1_PD(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A1_PD=(ParValue))
#define biGetDDR_A1_A2_DDR_A1_SMT() (pst_bitDDR_A1_A2() -> DDR_A1_SMT)
#define vSetDDR_A1_A2_DDR_A1_SMT(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A1_SMT=(ParValue))
#define biGetDDR_A1_A2_DDR_A1_IMP() (pst_bitDDR_A1_A2() -> DDR_A1_IMP)
#define vSetDDR_A1_A2_DDR_A1_IMP(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A1_IMP=(ParValue))
#define biGetDDR_A1_A2_DDR_A1_LATCHN() (pst_bitDDR_A1_A2() -> DDR_A1_LATCHN)
#define vSetDDR_A1_A2_DDR_A1_LATCHN(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A1_LATCHN=(ParValue))
#define biGetDDR_A1_A2_DDR_A2_SEL() (pst_bitDDR_A1_A2() -> DDR_A2_SEL)
#define vSetDDR_A1_A2_DDR_A2_SEL(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A2_SEL=(ParValue))
#define biGetDDR_A1_A2_DDR_A2_PU() (pst_bitDDR_A1_A2() -> DDR_A2_PU)
#define vSetDDR_A1_A2_DDR_A2_PU(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A2_PU=(ParValue))
#define biGetDDR_A1_A2_DDR_A2_PD() (pst_bitDDR_A1_A2() -> DDR_A2_PD)
#define vSetDDR_A1_A2_DDR_A2_PD(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A2_PD=(ParValue))
#define biGetDDR_A1_A2_DDR_A2_SMT() (pst_bitDDR_A1_A2() -> DDR_A2_SMT)
#define vSetDDR_A1_A2_DDR_A2_SMT(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A2_SMT=(ParValue))
#define biGetDDR_A1_A2_DDR_A2_IMP() (pst_bitDDR_A1_A2() -> DDR_A2_IMP)
#define vSetDDR_A1_A2_DDR_A2_IMP(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A2_IMP=(ParValue))
#define biGetDDR_A1_A2_DDR_A2_LATCHN() (pst_bitDDR_A1_A2() -> DDR_A2_LATCHN)
#define vSetDDR_A1_A2_DDR_A2_LATCHN(ParValue)  (pst_bitDDR_A1_A2() -> DDR_A2_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_A1_A2LL(ParValue) (pst_u8DDR_A1_A2() -> u8LL = (ParValue))
#define u8GetDDR_A1_A2LL() (pst_u8DDR_A1_A2() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_A1_A2LH(ParValue) (pst_u8DDR_A1_A2() -> u8LH = (ParValue))
#define u8GetDDR_A1_A2LH() (pst_u8DDR_A1_A2() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_A1_A2HL(ParValue) (pst_u8DDR_A1_A2() -> u8HL = (ParValue))
#define u8GetDDR_A1_A2HL() (pst_u8DDR_A1_A2() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_A1_A2HH(ParValue) (pst_u8DDR_A1_A2() -> u8HH = (ParValue))
#define u8GetDDR_A1_A2HH() (pst_u8DDR_A1_A2() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_A1_A2L(ParValue) (pst_u16DDR_A1_A2() -> u16L = (ParValue))
#define u16GetDDR_A1_A2L() (pst_u16DDR_A1_A2() -> u16L)
#define vSetDDR_A1_A2H(ParValue) (pst_u16DDR_A1_A2() -> u16H = (ParValue))
#define u16GetDDR_A1_A2H() (pst_u16DDR_A1_A2() -> u16H)
            
/* Word access */
#define vSetDDR_A1_A2(ParValue)  (*pu32DDR_A1_A2() = (ParValue))
#define u32GetDDR_A1_A2()  (*pu32DDR_A1_A2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_A3_A4                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030203C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_A3_A4_REG__       0xC030203CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_A3_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_A3_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_A3_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_A3_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_A3_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_A3_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_A4_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_A4_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_A4_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_A4_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_A4_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_A4_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_A3_A4_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_A3_A4_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_A3_A4_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_A3_A4_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_A3_A4()     ((volatile DDR_A3_A4_bit_view_st *)\
(DDR_A3_A4_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_A3_A4()     ((volatile DDR_A3_A4_byte_view_st *)\
(DDR_A3_A4_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_A3_A4()     ((volatile DDR_A3_A4_halfword_view_st *)\
(DDR_A3_A4_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_A3_A4()     ((volatile u32DDR_A3_A4_word_view *)\
(DDR_A3_A4_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_A3_A4_DDR_A3_SEL() (pst_bitDDR_A3_A4() -> DDR_A3_SEL)
#define vSetDDR_A3_A4_DDR_A3_SEL(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A3_SEL=(ParValue))
#define biGetDDR_A3_A4_DDR_A3_PU() (pst_bitDDR_A3_A4() -> DDR_A3_PU)
#define vSetDDR_A3_A4_DDR_A3_PU(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A3_PU=(ParValue))
#define biGetDDR_A3_A4_DDR_A3_PD() (pst_bitDDR_A3_A4() -> DDR_A3_PD)
#define vSetDDR_A3_A4_DDR_A3_PD(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A3_PD=(ParValue))
#define biGetDDR_A3_A4_DDR_A3_SMT() (pst_bitDDR_A3_A4() -> DDR_A3_SMT)
#define vSetDDR_A3_A4_DDR_A3_SMT(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A3_SMT=(ParValue))
#define biGetDDR_A3_A4_DDR_A3_IMP() (pst_bitDDR_A3_A4() -> DDR_A3_IMP)
#define vSetDDR_A3_A4_DDR_A3_IMP(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A3_IMP=(ParValue))
#define biGetDDR_A3_A4_DDR_A3_LATCHN() (pst_bitDDR_A3_A4() -> DDR_A3_LATCHN)
#define vSetDDR_A3_A4_DDR_A3_LATCHN(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A3_LATCHN=(ParValue))
#define biGetDDR_A3_A4_DDR_A4_SEL() (pst_bitDDR_A3_A4() -> DDR_A4_SEL)
#define vSetDDR_A3_A4_DDR_A4_SEL(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A4_SEL=(ParValue))
#define biGetDDR_A3_A4_DDR_A4_PU() (pst_bitDDR_A3_A4() -> DDR_A4_PU)
#define vSetDDR_A3_A4_DDR_A4_PU(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A4_PU=(ParValue))
#define biGetDDR_A3_A4_DDR_A4_PD() (pst_bitDDR_A3_A4() -> DDR_A4_PD)
#define vSetDDR_A3_A4_DDR_A4_PD(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A4_PD=(ParValue))
#define biGetDDR_A3_A4_DDR_A4_SMT() (pst_bitDDR_A3_A4() -> DDR_A4_SMT)
#define vSetDDR_A3_A4_DDR_A4_SMT(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A4_SMT=(ParValue))
#define biGetDDR_A3_A4_DDR_A4_IMP() (pst_bitDDR_A3_A4() -> DDR_A4_IMP)
#define vSetDDR_A3_A4_DDR_A4_IMP(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A4_IMP=(ParValue))
#define biGetDDR_A3_A4_DDR_A4_LATCHN() (pst_bitDDR_A3_A4() -> DDR_A4_LATCHN)
#define vSetDDR_A3_A4_DDR_A4_LATCHN(ParValue)  (pst_bitDDR_A3_A4() -> DDR_A4_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_A3_A4LL(ParValue) (pst_u8DDR_A3_A4() -> u8LL = (ParValue))
#define u8GetDDR_A3_A4LL() (pst_u8DDR_A3_A4() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_A3_A4LH(ParValue) (pst_u8DDR_A3_A4() -> u8LH = (ParValue))
#define u8GetDDR_A3_A4LH() (pst_u8DDR_A3_A4() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_A3_A4HL(ParValue) (pst_u8DDR_A3_A4() -> u8HL = (ParValue))
#define u8GetDDR_A3_A4HL() (pst_u8DDR_A3_A4() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_A3_A4HH(ParValue) (pst_u8DDR_A3_A4() -> u8HH = (ParValue))
#define u8GetDDR_A3_A4HH() (pst_u8DDR_A3_A4() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_A3_A4L(ParValue) (pst_u16DDR_A3_A4() -> u16L = (ParValue))
#define u16GetDDR_A3_A4L() (pst_u16DDR_A3_A4() -> u16L)
#define vSetDDR_A3_A4H(ParValue) (pst_u16DDR_A3_A4() -> u16H = (ParValue))
#define u16GetDDR_A3_A4H() (pst_u16DDR_A3_A4() -> u16H)
            
/* Word access */
#define vSetDDR_A3_A4(ParValue)  (*pu32DDR_A3_A4() = (ParValue))
#define u32GetDDR_A3_A4()  (*pu32DDR_A3_A4() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_A5_A6                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302040                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_A5_A6_REG__       0xC0302040U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_A5_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_A5_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_A5_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_A5_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_A5_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_A5_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_A6_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_A6_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_A6_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_A6_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_A6_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_A6_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_A5_A6_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_A5_A6_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_A5_A6_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_A5_A6_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_A5_A6()     ((volatile DDR_A5_A6_bit_view_st *)\
(DDR_A5_A6_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_A5_A6()     ((volatile DDR_A5_A6_byte_view_st *)\
(DDR_A5_A6_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_A5_A6()     ((volatile DDR_A5_A6_halfword_view_st *)\
(DDR_A5_A6_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_A5_A6()     ((volatile u32DDR_A5_A6_word_view *)\
(DDR_A5_A6_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_A5_A6_DDR_A5_SEL() (pst_bitDDR_A5_A6() -> DDR_A5_SEL)
#define vSetDDR_A5_A6_DDR_A5_SEL(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A5_SEL=(ParValue))
#define biGetDDR_A5_A6_DDR_A5_PU() (pst_bitDDR_A5_A6() -> DDR_A5_PU)
#define vSetDDR_A5_A6_DDR_A5_PU(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A5_PU=(ParValue))
#define biGetDDR_A5_A6_DDR_A5_PD() (pst_bitDDR_A5_A6() -> DDR_A5_PD)
#define vSetDDR_A5_A6_DDR_A5_PD(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A5_PD=(ParValue))
#define biGetDDR_A5_A6_DDR_A5_SMT() (pst_bitDDR_A5_A6() -> DDR_A5_SMT)
#define vSetDDR_A5_A6_DDR_A5_SMT(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A5_SMT=(ParValue))
#define biGetDDR_A5_A6_DDR_A5_IMP() (pst_bitDDR_A5_A6() -> DDR_A5_IMP)
#define vSetDDR_A5_A6_DDR_A5_IMP(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A5_IMP=(ParValue))
#define biGetDDR_A5_A6_DDR_A5_LATCHN() (pst_bitDDR_A5_A6() -> DDR_A5_LATCHN)
#define vSetDDR_A5_A6_DDR_A5_LATCHN(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A5_LATCHN=(ParValue))
#define biGetDDR_A5_A6_DDR_A6_SEL() (pst_bitDDR_A5_A6() -> DDR_A6_SEL)
#define vSetDDR_A5_A6_DDR_A6_SEL(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A6_SEL=(ParValue))
#define biGetDDR_A5_A6_DDR_A6_PU() (pst_bitDDR_A5_A6() -> DDR_A6_PU)
#define vSetDDR_A5_A6_DDR_A6_PU(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A6_PU=(ParValue))
#define biGetDDR_A5_A6_DDR_A6_PD() (pst_bitDDR_A5_A6() -> DDR_A6_PD)
#define vSetDDR_A5_A6_DDR_A6_PD(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A6_PD=(ParValue))
#define biGetDDR_A5_A6_DDR_A6_SMT() (pst_bitDDR_A5_A6() -> DDR_A6_SMT)
#define vSetDDR_A5_A6_DDR_A6_SMT(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A6_SMT=(ParValue))
#define biGetDDR_A5_A6_DDR_A6_IMP() (pst_bitDDR_A5_A6() -> DDR_A6_IMP)
#define vSetDDR_A5_A6_DDR_A6_IMP(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A6_IMP=(ParValue))
#define biGetDDR_A5_A6_DDR_A6_LATCHN() (pst_bitDDR_A5_A6() -> DDR_A6_LATCHN)
#define vSetDDR_A5_A6_DDR_A6_LATCHN(ParValue)  (pst_bitDDR_A5_A6() -> DDR_A6_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_A5_A6LL(ParValue) (pst_u8DDR_A5_A6() -> u8LL = (ParValue))
#define u8GetDDR_A5_A6LL() (pst_u8DDR_A5_A6() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_A5_A6LH(ParValue) (pst_u8DDR_A5_A6() -> u8LH = (ParValue))
#define u8GetDDR_A5_A6LH() (pst_u8DDR_A5_A6() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_A5_A6HL(ParValue) (pst_u8DDR_A5_A6() -> u8HL = (ParValue))
#define u8GetDDR_A5_A6HL() (pst_u8DDR_A5_A6() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_A5_A6HH(ParValue) (pst_u8DDR_A5_A6() -> u8HH = (ParValue))
#define u8GetDDR_A5_A6HH() (pst_u8DDR_A5_A6() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_A5_A6L(ParValue) (pst_u16DDR_A5_A6() -> u16L = (ParValue))
#define u16GetDDR_A5_A6L() (pst_u16DDR_A5_A6() -> u16L)
#define vSetDDR_A5_A6H(ParValue) (pst_u16DDR_A5_A6() -> u16H = (ParValue))
#define u16GetDDR_A5_A6H() (pst_u16DDR_A5_A6() -> u16H)
            
/* Word access */
#define vSetDDR_A5_A6(ParValue)  (*pu32DDR_A5_A6() = (ParValue))
#define u32GetDDR_A5_A6()  (*pu32DDR_A5_A6() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_A7_A8                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302044                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_A7_A8_REG__       0xC0302044U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_A7_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_A7_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_A7_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_A7_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_A7_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_A7_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_A8_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_A8_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_A8_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_A8_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_A8_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_A8_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_A7_A8_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_A7_A8_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_A7_A8_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_A7_A8_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_A7_A8()     ((volatile DDR_A7_A8_bit_view_st *)\
(DDR_A7_A8_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_A7_A8()     ((volatile DDR_A7_A8_byte_view_st *)\
(DDR_A7_A8_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_A7_A8()     ((volatile DDR_A7_A8_halfword_view_st *)\
(DDR_A7_A8_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_A7_A8()     ((volatile u32DDR_A7_A8_word_view *)\
(DDR_A7_A8_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_A7_A8_DDR_A7_SEL() (pst_bitDDR_A7_A8() -> DDR_A7_SEL)
#define vSetDDR_A7_A8_DDR_A7_SEL(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A7_SEL=(ParValue))
#define biGetDDR_A7_A8_DDR_A7_PU() (pst_bitDDR_A7_A8() -> DDR_A7_PU)
#define vSetDDR_A7_A8_DDR_A7_PU(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A7_PU=(ParValue))
#define biGetDDR_A7_A8_DDR_A7_PD() (pst_bitDDR_A7_A8() -> DDR_A7_PD)
#define vSetDDR_A7_A8_DDR_A7_PD(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A7_PD=(ParValue))
#define biGetDDR_A7_A8_DDR_A7_SMT() (pst_bitDDR_A7_A8() -> DDR_A7_SMT)
#define vSetDDR_A7_A8_DDR_A7_SMT(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A7_SMT=(ParValue))
#define biGetDDR_A7_A8_DDR_A7_IMP() (pst_bitDDR_A7_A8() -> DDR_A7_IMP)
#define vSetDDR_A7_A8_DDR_A7_IMP(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A7_IMP=(ParValue))
#define biGetDDR_A7_A8_DDR_A7_LATCHN() (pst_bitDDR_A7_A8() -> DDR_A7_LATCHN)
#define vSetDDR_A7_A8_DDR_A7_LATCHN(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A7_LATCHN=(ParValue))
#define biGetDDR_A7_A8_DDR_A8_SEL() (pst_bitDDR_A7_A8() -> DDR_A8_SEL)
#define vSetDDR_A7_A8_DDR_A8_SEL(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A8_SEL=(ParValue))
#define biGetDDR_A7_A8_DDR_A8_PU() (pst_bitDDR_A7_A8() -> DDR_A8_PU)
#define vSetDDR_A7_A8_DDR_A8_PU(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A8_PU=(ParValue))
#define biGetDDR_A7_A8_DDR_A8_PD() (pst_bitDDR_A7_A8() -> DDR_A8_PD)
#define vSetDDR_A7_A8_DDR_A8_PD(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A8_PD=(ParValue))
#define biGetDDR_A7_A8_DDR_A8_SMT() (pst_bitDDR_A7_A8() -> DDR_A8_SMT)
#define vSetDDR_A7_A8_DDR_A8_SMT(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A8_SMT=(ParValue))
#define biGetDDR_A7_A8_DDR_A8_IMP() (pst_bitDDR_A7_A8() -> DDR_A8_IMP)
#define vSetDDR_A7_A8_DDR_A8_IMP(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A8_IMP=(ParValue))
#define biGetDDR_A7_A8_DDR_A8_LATCHN() (pst_bitDDR_A7_A8() -> DDR_A8_LATCHN)
#define vSetDDR_A7_A8_DDR_A8_LATCHN(ParValue)  (pst_bitDDR_A7_A8() -> DDR_A8_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_A7_A8LL(ParValue) (pst_u8DDR_A7_A8() -> u8LL = (ParValue))
#define u8GetDDR_A7_A8LL() (pst_u8DDR_A7_A8() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_A7_A8LH(ParValue) (pst_u8DDR_A7_A8() -> u8LH = (ParValue))
#define u8GetDDR_A7_A8LH() (pst_u8DDR_A7_A8() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_A7_A8HL(ParValue) (pst_u8DDR_A7_A8() -> u8HL = (ParValue))
#define u8GetDDR_A7_A8HL() (pst_u8DDR_A7_A8() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_A7_A8HH(ParValue) (pst_u8DDR_A7_A8() -> u8HH = (ParValue))
#define u8GetDDR_A7_A8HH() (pst_u8DDR_A7_A8() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_A7_A8L(ParValue) (pst_u16DDR_A7_A8() -> u16L = (ParValue))
#define u16GetDDR_A7_A8L() (pst_u16DDR_A7_A8() -> u16L)
#define vSetDDR_A7_A8H(ParValue) (pst_u16DDR_A7_A8() -> u16H = (ParValue))
#define u16GetDDR_A7_A8H() (pst_u16DDR_A7_A8() -> u16H)
            
/* Word access */
#define vSetDDR_A7_A8(ParValue)  (*pu32DDR_A7_A8() = (ParValue))
#define u32GetDDR_A7_A8()  (*pu32DDR_A7_A8() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_A9_A10                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302048                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_A9_A10_REG__       0xC0302048U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_A9_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_A9_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_A9_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_A9_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_A9_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_A9_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_A10_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_A10_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_A10_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_A10_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_A10_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_A10_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_A9_A10_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_A9_A10_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_A9_A10_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_A9_A10_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_A9_A10()     ((volatile DDR_A9_A10_bit_view_st *)\
(DDR_A9_A10_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_A9_A10()     ((volatile DDR_A9_A10_byte_view_st *)\
(DDR_A9_A10_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_A9_A10()     ((volatile DDR_A9_A10_halfword_view_st *)\
(DDR_A9_A10_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_A9_A10()     ((volatile u32DDR_A9_A10_word_view *)\
(DDR_A9_A10_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_A9_A10_DDR_A9_SEL() (pst_bitDDR_A9_A10() -> DDR_A9_SEL)
#define vSetDDR_A9_A10_DDR_A9_SEL(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A9_SEL=(ParValue))
#define biGetDDR_A9_A10_DDR_A9_PU() (pst_bitDDR_A9_A10() -> DDR_A9_PU)
#define vSetDDR_A9_A10_DDR_A9_PU(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A9_PU=(ParValue))
#define biGetDDR_A9_A10_DDR_A9_PD() (pst_bitDDR_A9_A10() -> DDR_A9_PD)
#define vSetDDR_A9_A10_DDR_A9_PD(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A9_PD=(ParValue))
#define biGetDDR_A9_A10_DDR_A9_SMT() (pst_bitDDR_A9_A10() -> DDR_A9_SMT)
#define vSetDDR_A9_A10_DDR_A9_SMT(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A9_SMT=(ParValue))
#define biGetDDR_A9_A10_DDR_A9_IMP() (pst_bitDDR_A9_A10() -> DDR_A9_IMP)
#define vSetDDR_A9_A10_DDR_A9_IMP(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A9_IMP=(ParValue))
#define biGetDDR_A9_A10_DDR_A9_LATCHN() (pst_bitDDR_A9_A10() -> DDR_A9_LATCHN)
#define vSetDDR_A9_A10_DDR_A9_LATCHN(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A9_LATCHN=(ParValue))
#define biGetDDR_A9_A10_DDR_A10_SEL() (pst_bitDDR_A9_A10() -> DDR_A10_SEL)
#define vSetDDR_A9_A10_DDR_A10_SEL(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A10_SEL=(ParValue))
#define biGetDDR_A9_A10_DDR_A10_PU() (pst_bitDDR_A9_A10() -> DDR_A10_PU)
#define vSetDDR_A9_A10_DDR_A10_PU(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A10_PU=(ParValue))
#define biGetDDR_A9_A10_DDR_A10_PD() (pst_bitDDR_A9_A10() -> DDR_A10_PD)
#define vSetDDR_A9_A10_DDR_A10_PD(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A10_PD=(ParValue))
#define biGetDDR_A9_A10_DDR_A10_SMT() (pst_bitDDR_A9_A10() -> DDR_A10_SMT)
#define vSetDDR_A9_A10_DDR_A10_SMT(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A10_SMT=(ParValue))
#define biGetDDR_A9_A10_DDR_A10_IMP() (pst_bitDDR_A9_A10() -> DDR_A10_IMP)
#define vSetDDR_A9_A10_DDR_A10_IMP(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A10_IMP=(ParValue))
#define biGetDDR_A9_A10_DDR_A10_LATCHN() (pst_bitDDR_A9_A10() -> DDR_A10_LATCHN)
#define vSetDDR_A9_A10_DDR_A10_LATCHN(ParValue)  (pst_bitDDR_A9_A10() -> DDR_A10_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_A9_A10LL(ParValue) (pst_u8DDR_A9_A10() -> u8LL = (ParValue))
#define u8GetDDR_A9_A10LL() (pst_u8DDR_A9_A10() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_A9_A10LH(ParValue) (pst_u8DDR_A9_A10() -> u8LH = (ParValue))
#define u8GetDDR_A9_A10LH() (pst_u8DDR_A9_A10() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_A9_A10HL(ParValue) (pst_u8DDR_A9_A10() -> u8HL = (ParValue))
#define u8GetDDR_A9_A10HL() (pst_u8DDR_A9_A10() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_A9_A10HH(ParValue) (pst_u8DDR_A9_A10() -> u8HH = (ParValue))
#define u8GetDDR_A9_A10HH() (pst_u8DDR_A9_A10() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_A9_A10L(ParValue) (pst_u16DDR_A9_A10() -> u16L = (ParValue))
#define u16GetDDR_A9_A10L() (pst_u16DDR_A9_A10() -> u16L)
#define vSetDDR_A9_A10H(ParValue) (pst_u16DDR_A9_A10() -> u16H = (ParValue))
#define u16GetDDR_A9_A10H() (pst_u16DDR_A9_A10() -> u16H)
            
/* Word access */
#define vSetDDR_A9_A10(ParValue)  (*pu32DDR_A9_A10() = (ParValue))
#define u32GetDDR_A9_A10()  (*pu32DDR_A9_A10() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_A11_A12                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030204C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_A11_A12_REG__       0xC030204CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_A11_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_A11_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_A11_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_A11_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_A11_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_A11_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_A12_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_A12_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_A12_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_A12_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_A12_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_A12_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_A11_A12_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_A11_A12_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_A11_A12_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_A11_A12_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_A11_A12()     ((volatile DDR_A11_A12_bit_view_st *)\
(DDR_A11_A12_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_A11_A12()     ((volatile DDR_A11_A12_byte_view_st *)\
(DDR_A11_A12_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_A11_A12()     ((volatile DDR_A11_A12_halfword_view_st *)\
(DDR_A11_A12_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_A11_A12()     ((volatile u32DDR_A11_A12_word_view *)\
(DDR_A11_A12_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_A11_A12_DDR_A11_SEL() (pst_bitDDR_A11_A12() -> DDR_A11_SEL)
#define vSetDDR_A11_A12_DDR_A11_SEL(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A11_SEL=(ParValue))
#define biGetDDR_A11_A12_DDR_A11_PU() (pst_bitDDR_A11_A12() -> DDR_A11_PU)
#define vSetDDR_A11_A12_DDR_A11_PU(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A11_PU=(ParValue))
#define biGetDDR_A11_A12_DDR_A11_PD() (pst_bitDDR_A11_A12() -> DDR_A11_PD)
#define vSetDDR_A11_A12_DDR_A11_PD(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A11_PD=(ParValue))
#define biGetDDR_A11_A12_DDR_A11_SMT() (pst_bitDDR_A11_A12() -> DDR_A11_SMT)
#define vSetDDR_A11_A12_DDR_A11_SMT(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A11_SMT=(ParValue))
#define biGetDDR_A11_A12_DDR_A11_IMP() (pst_bitDDR_A11_A12() -> DDR_A11_IMP)
#define vSetDDR_A11_A12_DDR_A11_IMP(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A11_IMP=(ParValue))
#define biGetDDR_A11_A12_DDR_A11_LATCHN() (pst_bitDDR_A11_A12() -> DDR_A11_LATCHN)
#define vSetDDR_A11_A12_DDR_A11_LATCHN(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A11_LATCHN=(ParValue))
#define biGetDDR_A11_A12_DDR_A12_SEL() (pst_bitDDR_A11_A12() -> DDR_A12_SEL)
#define vSetDDR_A11_A12_DDR_A12_SEL(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A12_SEL=(ParValue))
#define biGetDDR_A11_A12_DDR_A12_PU() (pst_bitDDR_A11_A12() -> DDR_A12_PU)
#define vSetDDR_A11_A12_DDR_A12_PU(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A12_PU=(ParValue))
#define biGetDDR_A11_A12_DDR_A12_PD() (pst_bitDDR_A11_A12() -> DDR_A12_PD)
#define vSetDDR_A11_A12_DDR_A12_PD(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A12_PD=(ParValue))
#define biGetDDR_A11_A12_DDR_A12_SMT() (pst_bitDDR_A11_A12() -> DDR_A12_SMT)
#define vSetDDR_A11_A12_DDR_A12_SMT(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A12_SMT=(ParValue))
#define biGetDDR_A11_A12_DDR_A12_IMP() (pst_bitDDR_A11_A12() -> DDR_A12_IMP)
#define vSetDDR_A11_A12_DDR_A12_IMP(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A12_IMP=(ParValue))
#define biGetDDR_A11_A12_DDR_A12_LATCHN() (pst_bitDDR_A11_A12() -> DDR_A12_LATCHN)
#define vSetDDR_A11_A12_DDR_A12_LATCHN(ParValue)  (pst_bitDDR_A11_A12() -> DDR_A12_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_A11_A12LL(ParValue) (pst_u8DDR_A11_A12() -> u8LL = (ParValue))
#define u8GetDDR_A11_A12LL() (pst_u8DDR_A11_A12() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_A11_A12LH(ParValue) (pst_u8DDR_A11_A12() -> u8LH = (ParValue))
#define u8GetDDR_A11_A12LH() (pst_u8DDR_A11_A12() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_A11_A12HL(ParValue) (pst_u8DDR_A11_A12() -> u8HL = (ParValue))
#define u8GetDDR_A11_A12HL() (pst_u8DDR_A11_A12() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_A11_A12HH(ParValue) (pst_u8DDR_A11_A12() -> u8HH = (ParValue))
#define u8GetDDR_A11_A12HH() (pst_u8DDR_A11_A12() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_A11_A12L(ParValue) (pst_u16DDR_A11_A12() -> u16L = (ParValue))
#define u16GetDDR_A11_A12L() (pst_u16DDR_A11_A12() -> u16L)
#define vSetDDR_A11_A12H(ParValue) (pst_u16DDR_A11_A12() -> u16H = (ParValue))
#define u16GetDDR_A11_A12H() (pst_u16DDR_A11_A12() -> u16H)
            
/* Word access */
#define vSetDDR_A11_A12(ParValue)  (*pu32DDR_A11_A12() = (ParValue))
#define u32GetDDR_A11_A12()  (*pu32DDR_A11_A12() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_A13_DQS0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302050                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_A13_DQS0_REG__       0xC0302050U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_A13_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_A13_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_A13_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_A13_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_A13_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_A13_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQS0_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQS0_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQS0_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQS0_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQS0_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQS0_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_A13_DQS0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_A13_DQS0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_A13_DQS0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_A13_DQS0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_A13_DQS0()     ((volatile DDR_A13_DQS0_bit_view_st *)\
(DDR_A13_DQS0_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_A13_DQS0()     ((volatile DDR_A13_DQS0_byte_view_st *)\
(DDR_A13_DQS0_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_A13_DQS0()     ((volatile DDR_A13_DQS0_halfword_view_st *)\
(DDR_A13_DQS0_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_A13_DQS0()     ((volatile u32DDR_A13_DQS0_word_view *)\
(DDR_A13_DQS0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_A13_DQS0_DDR_A13_SEL() (pst_bitDDR_A13_DQS0() -> DDR_A13_SEL)
#define vSetDDR_A13_DQS0_DDR_A13_SEL(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_A13_SEL=(ParValue))
#define biGetDDR_A13_DQS0_DDR_A13_PU() (pst_bitDDR_A13_DQS0() -> DDR_A13_PU)
#define vSetDDR_A13_DQS0_DDR_A13_PU(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_A13_PU=(ParValue))
#define biGetDDR_A13_DQS0_DDR_A13_PD() (pst_bitDDR_A13_DQS0() -> DDR_A13_PD)
#define vSetDDR_A13_DQS0_DDR_A13_PD(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_A13_PD=(ParValue))
#define biGetDDR_A13_DQS0_DDR_A13_SMT() (pst_bitDDR_A13_DQS0() -> DDR_A13_SMT)
#define vSetDDR_A13_DQS0_DDR_A13_SMT(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_A13_SMT=(ParValue))
#define biGetDDR_A13_DQS0_DDR_A13_IMP() (pst_bitDDR_A13_DQS0() -> DDR_A13_IMP)
#define vSetDDR_A13_DQS0_DDR_A13_IMP(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_A13_IMP=(ParValue))
#define biGetDDR_A13_DQS0_DDR_A13_LATCHN() (pst_bitDDR_A13_DQS0() -> DDR_A13_LATCHN)
#define vSetDDR_A13_DQS0_DDR_A13_LATCHN(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_A13_LATCHN=(ParValue))
#define biGetDDR_A13_DQS0_DDR_DQS0_SEL() (pst_bitDDR_A13_DQS0() -> DDR_DQS0_SEL)
#define vSetDDR_A13_DQS0_DDR_DQS0_SEL(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_DQS0_SEL=(ParValue))
#define biGetDDR_A13_DQS0_DDR_DQS0_PU() (pst_bitDDR_A13_DQS0() -> DDR_DQS0_PU)
#define vSetDDR_A13_DQS0_DDR_DQS0_PU(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_DQS0_PU=(ParValue))
#define biGetDDR_A13_DQS0_DDR_DQS0_PD() (pst_bitDDR_A13_DQS0() -> DDR_DQS0_PD)
#define vSetDDR_A13_DQS0_DDR_DQS0_PD(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_DQS0_PD=(ParValue))
#define biGetDDR_A13_DQS0_DDR_DQS0_SMT() (pst_bitDDR_A13_DQS0() -> DDR_DQS0_SMT)
#define vSetDDR_A13_DQS0_DDR_DQS0_SMT(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_DQS0_SMT=(ParValue))
#define biGetDDR_A13_DQS0_DDR_DQS0_IMP() (pst_bitDDR_A13_DQS0() -> DDR_DQS0_IMP)
#define vSetDDR_A13_DQS0_DDR_DQS0_IMP(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_DQS0_IMP=(ParValue))
#define biGetDDR_A13_DQS0_DDR_DQS0_LATCHN() (pst_bitDDR_A13_DQS0() -> DDR_DQS0_LATCHN)
#define vSetDDR_A13_DQS0_DDR_DQS0_LATCHN(ParValue)  (pst_bitDDR_A13_DQS0() -> DDR_DQS0_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_A13_DQS0LL(ParValue) (pst_u8DDR_A13_DQS0() -> u8LL = (ParValue))
#define u8GetDDR_A13_DQS0LL() (pst_u8DDR_A13_DQS0() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_A13_DQS0LH(ParValue) (pst_u8DDR_A13_DQS0() -> u8LH = (ParValue))
#define u8GetDDR_A13_DQS0LH() (pst_u8DDR_A13_DQS0() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_A13_DQS0HL(ParValue) (pst_u8DDR_A13_DQS0() -> u8HL = (ParValue))
#define u8GetDDR_A13_DQS0HL() (pst_u8DDR_A13_DQS0() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_A13_DQS0HH(ParValue) (pst_u8DDR_A13_DQS0() -> u8HH = (ParValue))
#define u8GetDDR_A13_DQS0HH() (pst_u8DDR_A13_DQS0() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_A13_DQS0L(ParValue) (pst_u16DDR_A13_DQS0() -> u16L = (ParValue))
#define u16GetDDR_A13_DQS0L() (pst_u16DDR_A13_DQS0() -> u16L)
#define vSetDDR_A13_DQS0H(ParValue) (pst_u16DDR_A13_DQS0() -> u16H = (ParValue))
#define u16GetDDR_A13_DQS0H() (pst_u16DDR_A13_DQS0() -> u16H)
            
/* Word access */
#define vSetDDR_A13_DQS0(ParValue)  (*pu32DDR_A13_DQS0() = (ParValue))
#define u32GetDDR_A13_DQS0()  (*pu32DDR_A13_DQS0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQS1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302054                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQS1_REG__       0xC0302054U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   DDR_DQS1_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint16_t   	:5; 	 /* 3..7  bit(s) R */
  uint16_t   DDR_DQS1_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   DDR_DQS1_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   DDR_DQS1_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint16_t   DDR_DQS1_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint16_t   DDR_DQS1_LATCHN	:1; 	 /* 13..13  bit(s) R/W */ 
  uint16_t   	:2; 	 /* 14..31  bit(s) R */                    
} DDR_DQS1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} DDR_DQS1_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16DDR_DQS1_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQS1()     ((volatile DDR_DQS1_bit_view_st *)\
(DDR_DQS1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQS1()     ((volatile DDR_DQS1_byte_view_st *)\
(DDR_DQS1_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16DDR_DQS1()     ((volatile u16DDR_DQS1_halfword_view *)\
(DDR_DQS1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQS1_DDR_DQS1_SEL() (pst_bitDDR_DQS1() -> DDR_DQS1_SEL)
#define vSetDDR_DQS1_DDR_DQS1_SEL(ParValue)  (pst_bitDDR_DQS1() -> DDR_DQS1_SEL=(ParValue))
#define biGetDDR_DQS1_DDR_DQS1_PU() (pst_bitDDR_DQS1() -> DDR_DQS1_PU)
#define vSetDDR_DQS1_DDR_DQS1_PU(ParValue)  (pst_bitDDR_DQS1() -> DDR_DQS1_PU=(ParValue))
#define biGetDDR_DQS1_DDR_DQS1_PD() (pst_bitDDR_DQS1() -> DDR_DQS1_PD)
#define vSetDDR_DQS1_DDR_DQS1_PD(ParValue)  (pst_bitDDR_DQS1() -> DDR_DQS1_PD=(ParValue))
#define biGetDDR_DQS1_DDR_DQS1_SMT() (pst_bitDDR_DQS1() -> DDR_DQS1_SMT)
#define vSetDDR_DQS1_DDR_DQS1_SMT(ParValue)  (pst_bitDDR_DQS1() -> DDR_DQS1_SMT=(ParValue))
#define biGetDDR_DQS1_DDR_DQS1_IMP() (pst_bitDDR_DQS1() -> DDR_DQS1_IMP)
#define vSetDDR_DQS1_DDR_DQS1_IMP(ParValue)  (pst_bitDDR_DQS1() -> DDR_DQS1_IMP=(ParValue))
#define biGetDDR_DQS1_DDR_DQS1_LATCHN() (pst_bitDDR_DQS1() -> DDR_DQS1_LATCHN)
#define vSetDDR_DQS1_DDR_DQS1_LATCHN(ParValue)  (pst_bitDDR_DQS1() -> DDR_DQS1_LATCHN=(ParValue))
            
/* L-struct byte access */
#define vSetDDR_DQS1L(ParValue) (pst_u8DDR_DQS1() -> u8L = (ParValue))
#define u8GetDDR_DQS1L() (pst_u8DDR_DQS1() -> u8L)
/* H-struct byte access */
#define vSetDDR_DQS1H(ParValue) (pst_u8DDR_DQS1() -> u8H = (ParValue))
#define u8GetDDR_DQS1H() (pst_u8DDR_DQS1() -> u8H)
            
/* Half-word access */ 
#define vSetDDR_DQS1(ParValue) (*pu16DDR_DQS1()  = (ParValue))
#define u16GetDDR_DQS1() (*pu16DDR_DQS1() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQS2_DQS3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302060                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQS2_DQS3_REG__       0xC0302060U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQS2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQS2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQS2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQS2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQS2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQS2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQS3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQS3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQS3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQS3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQS3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQS3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQS2_DQS3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQS2_DQS3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQS2_DQS3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQS2_DQS3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQS2_DQS3()     ((volatile DDR_DQS2_DQS3_bit_view_st *)\
(DDR_DQS2_DQS3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQS2_DQS3()     ((volatile DDR_DQS2_DQS3_byte_view_st *)\
(DDR_DQS2_DQS3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQS2_DQS3()     ((volatile DDR_DQS2_DQS3_halfword_view_st *)\
(DDR_DQS2_DQS3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQS2_DQS3()     ((volatile u32DDR_DQS2_DQS3_word_view *)\
(DDR_DQS2_DQS3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQS2_DQS3_DDR_DQS2_SEL() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_SEL)
#define vSetDDR_DQS2_DQS3_DDR_DQS2_SEL(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_SEL=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS2_PU() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_PU)
#define vSetDDR_DQS2_DQS3_DDR_DQS2_PU(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_PU=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS2_PD() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_PD)
#define vSetDDR_DQS2_DQS3_DDR_DQS2_PD(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_PD=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS2_SMT() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_SMT)
#define vSetDDR_DQS2_DQS3_DDR_DQS2_SMT(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_SMT=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS2_IMP() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_IMP)
#define vSetDDR_DQS2_DQS3_DDR_DQS2_IMP(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_IMP=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS2_LATCHN() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_LATCHN)
#define vSetDDR_DQS2_DQS3_DDR_DQS2_LATCHN(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS2_LATCHN=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS3_SEL() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_SEL)
#define vSetDDR_DQS2_DQS3_DDR_DQS3_SEL(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_SEL=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS3_PU() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_PU)
#define vSetDDR_DQS2_DQS3_DDR_DQS3_PU(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_PU=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS3_PD() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_PD)
#define vSetDDR_DQS2_DQS3_DDR_DQS3_PD(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_PD=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS3_SMT() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_SMT)
#define vSetDDR_DQS2_DQS3_DDR_DQS3_SMT(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_SMT=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS3_IMP() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_IMP)
#define vSetDDR_DQS2_DQS3_DDR_DQS3_IMP(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_IMP=(ParValue))
#define biGetDDR_DQS2_DQS3_DDR_DQS3_LATCHN() (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_LATCHN)
#define vSetDDR_DQS2_DQS3_DDR_DQS3_LATCHN(ParValue)  (pst_bitDDR_DQS2_DQS3() -> DDR_DQS3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQS2_DQS3LL(ParValue) (pst_u8DDR_DQS2_DQS3() -> u8LL = (ParValue))
#define u8GetDDR_DQS2_DQS3LL() (pst_u8DDR_DQS2_DQS3() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQS2_DQS3LH(ParValue) (pst_u8DDR_DQS2_DQS3() -> u8LH = (ParValue))
#define u8GetDDR_DQS2_DQS3LH() (pst_u8DDR_DQS2_DQS3() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQS2_DQS3HL(ParValue) (pst_u8DDR_DQS2_DQS3() -> u8HL = (ParValue))
#define u8GetDDR_DQS2_DQS3HL() (pst_u8DDR_DQS2_DQS3() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQS2_DQS3HH(ParValue) (pst_u8DDR_DQS2_DQS3() -> u8HH = (ParValue))
#define u8GetDDR_DQS2_DQS3HH() (pst_u8DDR_DQS2_DQS3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQS2_DQS3L(ParValue) (pst_u16DDR_DQS2_DQS3() -> u16L = (ParValue))
#define u16GetDDR_DQS2_DQS3L() (pst_u16DDR_DQS2_DQS3() -> u16L)
#define vSetDDR_DQS2_DQS3H(ParValue) (pst_u16DDR_DQS2_DQS3() -> u16H = (ParValue))
#define u16GetDDR_DQS2_DQS3H() (pst_u16DDR_DQS2_DQS3() -> u16H)
            
/* Word access */
#define vSetDDR_DQS2_DQS3(ParValue)  (*pu32DDR_DQS2_DQS3() = (ParValue))
#define u32GetDDR_DQS2_DQS3()  (*pu32DDR_DQS2_DQS3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DM2_DM3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302064                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DM2_DM3_REG__       0xC0302064U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DM2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DM2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DM2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DM2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DM2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DM2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DM3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DM3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DM3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DM3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DM3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DM3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DM2_DM3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DM2_DM3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DM2_DM3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DM2_DM3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DM2_DM3()     ((volatile DDR_DM2_DM3_bit_view_st *)\
(DDR_DM2_DM3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DM2_DM3()     ((volatile DDR_DM2_DM3_byte_view_st *)\
(DDR_DM2_DM3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DM2_DM3()     ((volatile DDR_DM2_DM3_halfword_view_st *)\
(DDR_DM2_DM3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DM2_DM3()     ((volatile u32DDR_DM2_DM3_word_view *)\
(DDR_DM2_DM3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DM2_DM3_DDR_DM2_SEL() (pst_bitDDR_DM2_DM3() -> DDR_DM2_SEL)
#define vSetDDR_DM2_DM3_DDR_DM2_SEL(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM2_SEL=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM2_PU() (pst_bitDDR_DM2_DM3() -> DDR_DM2_PU)
#define vSetDDR_DM2_DM3_DDR_DM2_PU(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM2_PU=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM2_PD() (pst_bitDDR_DM2_DM3() -> DDR_DM2_PD)
#define vSetDDR_DM2_DM3_DDR_DM2_PD(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM2_PD=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM2_SMT() (pst_bitDDR_DM2_DM3() -> DDR_DM2_SMT)
#define vSetDDR_DM2_DM3_DDR_DM2_SMT(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM2_SMT=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM2_IMP() (pst_bitDDR_DM2_DM3() -> DDR_DM2_IMP)
#define vSetDDR_DM2_DM3_DDR_DM2_IMP(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM2_IMP=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM2_LATCHN() (pst_bitDDR_DM2_DM3() -> DDR_DM2_LATCHN)
#define vSetDDR_DM2_DM3_DDR_DM2_LATCHN(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM2_LATCHN=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM3_SEL() (pst_bitDDR_DM2_DM3() -> DDR_DM3_SEL)
#define vSetDDR_DM2_DM3_DDR_DM3_SEL(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM3_SEL=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM3_PU() (pst_bitDDR_DM2_DM3() -> DDR_DM3_PU)
#define vSetDDR_DM2_DM3_DDR_DM3_PU(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM3_PU=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM3_PD() (pst_bitDDR_DM2_DM3() -> DDR_DM3_PD)
#define vSetDDR_DM2_DM3_DDR_DM3_PD(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM3_PD=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM3_SMT() (pst_bitDDR_DM2_DM3() -> DDR_DM3_SMT)
#define vSetDDR_DM2_DM3_DDR_DM3_SMT(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM3_SMT=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM3_IMP() (pst_bitDDR_DM2_DM3() -> DDR_DM3_IMP)
#define vSetDDR_DM2_DM3_DDR_DM3_IMP(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM3_IMP=(ParValue))
#define biGetDDR_DM2_DM3_DDR_DM3_LATCHN() (pst_bitDDR_DM2_DM3() -> DDR_DM3_LATCHN)
#define vSetDDR_DM2_DM3_DDR_DM3_LATCHN(ParValue)  (pst_bitDDR_DM2_DM3() -> DDR_DM3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DM2_DM3LL(ParValue) (pst_u8DDR_DM2_DM3() -> u8LL = (ParValue))
#define u8GetDDR_DM2_DM3LL() (pst_u8DDR_DM2_DM3() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DM2_DM3LH(ParValue) (pst_u8DDR_DM2_DM3() -> u8LH = (ParValue))
#define u8GetDDR_DM2_DM3LH() (pst_u8DDR_DM2_DM3() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DM2_DM3HL(ParValue) (pst_u8DDR_DM2_DM3() -> u8HL = (ParValue))
#define u8GetDDR_DM2_DM3HL() (pst_u8DDR_DM2_DM3() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DM2_DM3HH(ParValue) (pst_u8DDR_DM2_DM3() -> u8HH = (ParValue))
#define u8GetDDR_DM2_DM3HH() (pst_u8DDR_DM2_DM3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DM2_DM3L(ParValue) (pst_u16DDR_DM2_DM3() -> u16L = (ParValue))
#define u16GetDDR_DM2_DM3L() (pst_u16DDR_DM2_DM3() -> u16L)
#define vSetDDR_DM2_DM3H(ParValue) (pst_u16DDR_DM2_DM3() -> u16H = (ParValue))
#define u16GetDDR_DM2_DM3H() (pst_u16DDR_DM2_DM3() -> u16H)
            
/* Word access */
#define vSetDDR_DM2_DM3(ParValue)  (*pu32DDR_DM2_DM3() = (ParValue))
#define u32GetDDR_DM2_DM3()  (*pu32DDR_DM2_DM3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ16_DQ17                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302068                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ16_DQ17_REG__       0xC0302068U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ16_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ16_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ16_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ16_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ16_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ16_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ17_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ17_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ17_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ17_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ17_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ17_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ16_DQ17_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ16_DQ17_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ16_DQ17_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ16_DQ17_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ16_DQ17()     ((volatile DDR_DQ16_DQ17_bit_view_st *)\
(DDR_DQ16_DQ17_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ16_DQ17()     ((volatile DDR_DQ16_DQ17_byte_view_st *)\
(DDR_DQ16_DQ17_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ16_DQ17()     ((volatile DDR_DQ16_DQ17_halfword_view_st *)\
(DDR_DQ16_DQ17_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ16_DQ17()     ((volatile u32DDR_DQ16_DQ17_word_view *)\
(DDR_DQ16_DQ17_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ16_DQ17_DDR_DQ16_SEL() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_SEL)
#define vSetDDR_DQ16_DQ17_DDR_DQ16_SEL(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_SEL=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ16_PU() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_PU)
#define vSetDDR_DQ16_DQ17_DDR_DQ16_PU(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_PU=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ16_PD() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_PD)
#define vSetDDR_DQ16_DQ17_DDR_DQ16_PD(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_PD=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ16_SMT() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_SMT)
#define vSetDDR_DQ16_DQ17_DDR_DQ16_SMT(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_SMT=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ16_IMP() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_IMP)
#define vSetDDR_DQ16_DQ17_DDR_DQ16_IMP(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_IMP=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ16_LATCHN() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_LATCHN)
#define vSetDDR_DQ16_DQ17_DDR_DQ16_LATCHN(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ16_LATCHN=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ17_SEL() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_SEL)
#define vSetDDR_DQ16_DQ17_DDR_DQ17_SEL(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_SEL=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ17_PU() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_PU)
#define vSetDDR_DQ16_DQ17_DDR_DQ17_PU(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_PU=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ17_PD() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_PD)
#define vSetDDR_DQ16_DQ17_DDR_DQ17_PD(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_PD=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ17_SMT() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_SMT)
#define vSetDDR_DQ16_DQ17_DDR_DQ17_SMT(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_SMT=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ17_IMP() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_IMP)
#define vSetDDR_DQ16_DQ17_DDR_DQ17_IMP(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_IMP=(ParValue))
#define biGetDDR_DQ16_DQ17_DDR_DQ17_LATCHN() (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_LATCHN)
#define vSetDDR_DQ16_DQ17_DDR_DQ17_LATCHN(ParValue)  (pst_bitDDR_DQ16_DQ17() -> DDR_DQ17_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ16_DQ17LL(ParValue) (pst_u8DDR_DQ16_DQ17() -> u8LL = (ParValue))
#define u8GetDDR_DQ16_DQ17LL() (pst_u8DDR_DQ16_DQ17() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ16_DQ17LH(ParValue) (pst_u8DDR_DQ16_DQ17() -> u8LH = (ParValue))
#define u8GetDDR_DQ16_DQ17LH() (pst_u8DDR_DQ16_DQ17() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ16_DQ17HL(ParValue) (pst_u8DDR_DQ16_DQ17() -> u8HL = (ParValue))
#define u8GetDDR_DQ16_DQ17HL() (pst_u8DDR_DQ16_DQ17() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ16_DQ17HH(ParValue) (pst_u8DDR_DQ16_DQ17() -> u8HH = (ParValue))
#define u8GetDDR_DQ16_DQ17HH() (pst_u8DDR_DQ16_DQ17() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ16_DQ17L(ParValue) (pst_u16DDR_DQ16_DQ17() -> u16L = (ParValue))
#define u16GetDDR_DQ16_DQ17L() (pst_u16DDR_DQ16_DQ17() -> u16L)
#define vSetDDR_DQ16_DQ17H(ParValue) (pst_u16DDR_DQ16_DQ17() -> u16H = (ParValue))
#define u16GetDDR_DQ16_DQ17H() (pst_u16DDR_DQ16_DQ17() -> u16H)
            
/* Word access */
#define vSetDDR_DQ16_DQ17(ParValue)  (*pu32DDR_DQ16_DQ17() = (ParValue))
#define u32GetDDR_DQ16_DQ17()  (*pu32DDR_DQ16_DQ17() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ18_DQ19                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030206C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ18_DQ19_REG__       0xC030206CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ18_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ18_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ18_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ18_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ18_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ18_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ19_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ19_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ19_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ19_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ19_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ19_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ18_DQ19_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ18_DQ19_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ18_DQ19_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ18_DQ19_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ18_DQ19()     ((volatile DDR_DQ18_DQ19_bit_view_st *)\
(DDR_DQ18_DQ19_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ18_DQ19()     ((volatile DDR_DQ18_DQ19_byte_view_st *)\
(DDR_DQ18_DQ19_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ18_DQ19()     ((volatile DDR_DQ18_DQ19_halfword_view_st *)\
(DDR_DQ18_DQ19_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ18_DQ19()     ((volatile u32DDR_DQ18_DQ19_word_view *)\
(DDR_DQ18_DQ19_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ18_DQ19_DDR_DQ18_SEL() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_SEL)
#define vSetDDR_DQ18_DQ19_DDR_DQ18_SEL(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_SEL=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ18_PU() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_PU)
#define vSetDDR_DQ18_DQ19_DDR_DQ18_PU(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_PU=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ18_PD() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_PD)
#define vSetDDR_DQ18_DQ19_DDR_DQ18_PD(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_PD=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ18_SMT() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_SMT)
#define vSetDDR_DQ18_DQ19_DDR_DQ18_SMT(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_SMT=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ18_IMP() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_IMP)
#define vSetDDR_DQ18_DQ19_DDR_DQ18_IMP(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_IMP=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ18_LATCHN() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_LATCHN)
#define vSetDDR_DQ18_DQ19_DDR_DQ18_LATCHN(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ18_LATCHN=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ19_SEL() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_SEL)
#define vSetDDR_DQ18_DQ19_DDR_DQ19_SEL(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_SEL=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ19_PU() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_PU)
#define vSetDDR_DQ18_DQ19_DDR_DQ19_PU(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_PU=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ19_PD() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_PD)
#define vSetDDR_DQ18_DQ19_DDR_DQ19_PD(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_PD=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ19_SMT() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_SMT)
#define vSetDDR_DQ18_DQ19_DDR_DQ19_SMT(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_SMT=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ19_IMP() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_IMP)
#define vSetDDR_DQ18_DQ19_DDR_DQ19_IMP(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_IMP=(ParValue))
#define biGetDDR_DQ18_DQ19_DDR_DQ19_LATCHN() (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_LATCHN)
#define vSetDDR_DQ18_DQ19_DDR_DQ19_LATCHN(ParValue)  (pst_bitDDR_DQ18_DQ19() -> DDR_DQ19_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ18_DQ19LL(ParValue) (pst_u8DDR_DQ18_DQ19() -> u8LL = (ParValue))
#define u8GetDDR_DQ18_DQ19LL() (pst_u8DDR_DQ18_DQ19() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ18_DQ19LH(ParValue) (pst_u8DDR_DQ18_DQ19() -> u8LH = (ParValue))
#define u8GetDDR_DQ18_DQ19LH() (pst_u8DDR_DQ18_DQ19() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ18_DQ19HL(ParValue) (pst_u8DDR_DQ18_DQ19() -> u8HL = (ParValue))
#define u8GetDDR_DQ18_DQ19HL() (pst_u8DDR_DQ18_DQ19() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ18_DQ19HH(ParValue) (pst_u8DDR_DQ18_DQ19() -> u8HH = (ParValue))
#define u8GetDDR_DQ18_DQ19HH() (pst_u8DDR_DQ18_DQ19() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ18_DQ19L(ParValue) (pst_u16DDR_DQ18_DQ19() -> u16L = (ParValue))
#define u16GetDDR_DQ18_DQ19L() (pst_u16DDR_DQ18_DQ19() -> u16L)
#define vSetDDR_DQ18_DQ19H(ParValue) (pst_u16DDR_DQ18_DQ19() -> u16H = (ParValue))
#define u16GetDDR_DQ18_DQ19H() (pst_u16DDR_DQ18_DQ19() -> u16H)
            
/* Word access */
#define vSetDDR_DQ18_DQ19(ParValue)  (*pu32DDR_DQ18_DQ19() = (ParValue))
#define u32GetDDR_DQ18_DQ19()  (*pu32DDR_DQ18_DQ19() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ20_DQ21                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302070                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ20_DQ21_REG__       0xC0302070U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ20_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ20_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ20_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ20_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ20_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ20_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ21_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ21_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ21_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ21_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ21_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ21_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ20_DQ21_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ20_DQ21_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ20_DQ21_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ20_DQ21_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ20_DQ21()     ((volatile DDR_DQ20_DQ21_bit_view_st *)\
(DDR_DQ20_DQ21_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ20_DQ21()     ((volatile DDR_DQ20_DQ21_byte_view_st *)\
(DDR_DQ20_DQ21_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ20_DQ21()     ((volatile DDR_DQ20_DQ21_halfword_view_st *)\
(DDR_DQ20_DQ21_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ20_DQ21()     ((volatile u32DDR_DQ20_DQ21_word_view *)\
(DDR_DQ20_DQ21_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ20_DQ21_DDR_DQ20_SEL() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_SEL)
#define vSetDDR_DQ20_DQ21_DDR_DQ20_SEL(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_SEL=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ20_PU() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_PU)
#define vSetDDR_DQ20_DQ21_DDR_DQ20_PU(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_PU=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ20_PD() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_PD)
#define vSetDDR_DQ20_DQ21_DDR_DQ20_PD(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_PD=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ20_SMT() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_SMT)
#define vSetDDR_DQ20_DQ21_DDR_DQ20_SMT(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_SMT=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ20_IMP() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_IMP)
#define vSetDDR_DQ20_DQ21_DDR_DQ20_IMP(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_IMP=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ20_LATCHN() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_LATCHN)
#define vSetDDR_DQ20_DQ21_DDR_DQ20_LATCHN(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ20_LATCHN=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ21_SEL() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_SEL)
#define vSetDDR_DQ20_DQ21_DDR_DQ21_SEL(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_SEL=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ21_PU() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_PU)
#define vSetDDR_DQ20_DQ21_DDR_DQ21_PU(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_PU=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ21_PD() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_PD)
#define vSetDDR_DQ20_DQ21_DDR_DQ21_PD(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_PD=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ21_SMT() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_SMT)
#define vSetDDR_DQ20_DQ21_DDR_DQ21_SMT(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_SMT=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ21_IMP() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_IMP)
#define vSetDDR_DQ20_DQ21_DDR_DQ21_IMP(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_IMP=(ParValue))
#define biGetDDR_DQ20_DQ21_DDR_DQ21_LATCHN() (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_LATCHN)
#define vSetDDR_DQ20_DQ21_DDR_DQ21_LATCHN(ParValue)  (pst_bitDDR_DQ20_DQ21() -> DDR_DQ21_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ20_DQ21LL(ParValue) (pst_u8DDR_DQ20_DQ21() -> u8LL = (ParValue))
#define u8GetDDR_DQ20_DQ21LL() (pst_u8DDR_DQ20_DQ21() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ20_DQ21LH(ParValue) (pst_u8DDR_DQ20_DQ21() -> u8LH = (ParValue))
#define u8GetDDR_DQ20_DQ21LH() (pst_u8DDR_DQ20_DQ21() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ20_DQ21HL(ParValue) (pst_u8DDR_DQ20_DQ21() -> u8HL = (ParValue))
#define u8GetDDR_DQ20_DQ21HL() (pst_u8DDR_DQ20_DQ21() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ20_DQ21HH(ParValue) (pst_u8DDR_DQ20_DQ21() -> u8HH = (ParValue))
#define u8GetDDR_DQ20_DQ21HH() (pst_u8DDR_DQ20_DQ21() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ20_DQ21L(ParValue) (pst_u16DDR_DQ20_DQ21() -> u16L = (ParValue))
#define u16GetDDR_DQ20_DQ21L() (pst_u16DDR_DQ20_DQ21() -> u16L)
#define vSetDDR_DQ20_DQ21H(ParValue) (pst_u16DDR_DQ20_DQ21() -> u16H = (ParValue))
#define u16GetDDR_DQ20_DQ21H() (pst_u16DDR_DQ20_DQ21() -> u16H)
            
/* Word access */
#define vSetDDR_DQ20_DQ21(ParValue)  (*pu32DDR_DQ20_DQ21() = (ParValue))
#define u32GetDDR_DQ20_DQ21()  (*pu32DDR_DQ20_DQ21() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ22_DQ23                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302074                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ22_DQ23_REG__       0xC0302074U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ22_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ22_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ22_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ22_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ22_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ22_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ23_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ23_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ23_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ23_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ23_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ23_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ22_DQ23_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ22_DQ23_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ22_DQ23_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ22_DQ23_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ22_DQ23()     ((volatile DDR_DQ22_DQ23_bit_view_st *)\
(DDR_DQ22_DQ23_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ22_DQ23()     ((volatile DDR_DQ22_DQ23_byte_view_st *)\
(DDR_DQ22_DQ23_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ22_DQ23()     ((volatile DDR_DQ22_DQ23_halfword_view_st *)\
(DDR_DQ22_DQ23_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ22_DQ23()     ((volatile u32DDR_DQ22_DQ23_word_view *)\
(DDR_DQ22_DQ23_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ22_DQ23_DDR_DQ22_SEL() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_SEL)
#define vSetDDR_DQ22_DQ23_DDR_DQ22_SEL(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_SEL=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ22_PU() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_PU)
#define vSetDDR_DQ22_DQ23_DDR_DQ22_PU(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_PU=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ22_PD() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_PD)
#define vSetDDR_DQ22_DQ23_DDR_DQ22_PD(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_PD=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ22_SMT() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_SMT)
#define vSetDDR_DQ22_DQ23_DDR_DQ22_SMT(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_SMT=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ22_IMP() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_IMP)
#define vSetDDR_DQ22_DQ23_DDR_DQ22_IMP(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_IMP=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ22_LATCHN() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_LATCHN)
#define vSetDDR_DQ22_DQ23_DDR_DQ22_LATCHN(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ22_LATCHN=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ23_SEL() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_SEL)
#define vSetDDR_DQ22_DQ23_DDR_DQ23_SEL(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_SEL=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ23_PU() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_PU)
#define vSetDDR_DQ22_DQ23_DDR_DQ23_PU(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_PU=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ23_PD() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_PD)
#define vSetDDR_DQ22_DQ23_DDR_DQ23_PD(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_PD=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ23_SMT() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_SMT)
#define vSetDDR_DQ22_DQ23_DDR_DQ23_SMT(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_SMT=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ23_IMP() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_IMP)
#define vSetDDR_DQ22_DQ23_DDR_DQ23_IMP(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_IMP=(ParValue))
#define biGetDDR_DQ22_DQ23_DDR_DQ23_LATCHN() (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_LATCHN)
#define vSetDDR_DQ22_DQ23_DDR_DQ23_LATCHN(ParValue)  (pst_bitDDR_DQ22_DQ23() -> DDR_DQ23_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ22_DQ23LL(ParValue) (pst_u8DDR_DQ22_DQ23() -> u8LL = (ParValue))
#define u8GetDDR_DQ22_DQ23LL() (pst_u8DDR_DQ22_DQ23() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ22_DQ23LH(ParValue) (pst_u8DDR_DQ22_DQ23() -> u8LH = (ParValue))
#define u8GetDDR_DQ22_DQ23LH() (pst_u8DDR_DQ22_DQ23() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ22_DQ23HL(ParValue) (pst_u8DDR_DQ22_DQ23() -> u8HL = (ParValue))
#define u8GetDDR_DQ22_DQ23HL() (pst_u8DDR_DQ22_DQ23() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ22_DQ23HH(ParValue) (pst_u8DDR_DQ22_DQ23() -> u8HH = (ParValue))
#define u8GetDDR_DQ22_DQ23HH() (pst_u8DDR_DQ22_DQ23() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ22_DQ23L(ParValue) (pst_u16DDR_DQ22_DQ23() -> u16L = (ParValue))
#define u16GetDDR_DQ22_DQ23L() (pst_u16DDR_DQ22_DQ23() -> u16L)
#define vSetDDR_DQ22_DQ23H(ParValue) (pst_u16DDR_DQ22_DQ23() -> u16H = (ParValue))
#define u16GetDDR_DQ22_DQ23H() (pst_u16DDR_DQ22_DQ23() -> u16H)
            
/* Word access */
#define vSetDDR_DQ22_DQ23(ParValue)  (*pu32DDR_DQ22_DQ23() = (ParValue))
#define u32GetDDR_DQ22_DQ23()  (*pu32DDR_DQ22_DQ23() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ24_DQ25                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302078                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ24_DQ25_REG__       0xC0302078U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ24_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ24_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ24_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ24_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ24_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ24_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ25_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ25_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ25_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ25_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ25_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ25_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ24_DQ25_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ24_DQ25_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ24_DQ25_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ24_DQ25_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ24_DQ25()     ((volatile DDR_DQ24_DQ25_bit_view_st *)\
(DDR_DQ24_DQ25_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ24_DQ25()     ((volatile DDR_DQ24_DQ25_byte_view_st *)\
(DDR_DQ24_DQ25_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ24_DQ25()     ((volatile DDR_DQ24_DQ25_halfword_view_st *)\
(DDR_DQ24_DQ25_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ24_DQ25()     ((volatile u32DDR_DQ24_DQ25_word_view *)\
(DDR_DQ24_DQ25_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ24_DQ25_DDR_DQ24_SEL() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_SEL)
#define vSetDDR_DQ24_DQ25_DDR_DQ24_SEL(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_SEL=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ24_PU() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_PU)
#define vSetDDR_DQ24_DQ25_DDR_DQ24_PU(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_PU=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ24_PD() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_PD)
#define vSetDDR_DQ24_DQ25_DDR_DQ24_PD(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_PD=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ24_SMT() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_SMT)
#define vSetDDR_DQ24_DQ25_DDR_DQ24_SMT(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_SMT=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ24_IMP() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_IMP)
#define vSetDDR_DQ24_DQ25_DDR_DQ24_IMP(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_IMP=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ24_LATCHN() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_LATCHN)
#define vSetDDR_DQ24_DQ25_DDR_DQ24_LATCHN(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ24_LATCHN=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ25_SEL() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_SEL)
#define vSetDDR_DQ24_DQ25_DDR_DQ25_SEL(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_SEL=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ25_PU() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_PU)
#define vSetDDR_DQ24_DQ25_DDR_DQ25_PU(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_PU=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ25_PD() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_PD)
#define vSetDDR_DQ24_DQ25_DDR_DQ25_PD(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_PD=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ25_SMT() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_SMT)
#define vSetDDR_DQ24_DQ25_DDR_DQ25_SMT(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_SMT=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ25_IMP() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_IMP)
#define vSetDDR_DQ24_DQ25_DDR_DQ25_IMP(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_IMP=(ParValue))
#define biGetDDR_DQ24_DQ25_DDR_DQ25_LATCHN() (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_LATCHN)
#define vSetDDR_DQ24_DQ25_DDR_DQ25_LATCHN(ParValue)  (pst_bitDDR_DQ24_DQ25() -> DDR_DQ25_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ24_DQ25LL(ParValue) (pst_u8DDR_DQ24_DQ25() -> u8LL = (ParValue))
#define u8GetDDR_DQ24_DQ25LL() (pst_u8DDR_DQ24_DQ25() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ24_DQ25LH(ParValue) (pst_u8DDR_DQ24_DQ25() -> u8LH = (ParValue))
#define u8GetDDR_DQ24_DQ25LH() (pst_u8DDR_DQ24_DQ25() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ24_DQ25HL(ParValue) (pst_u8DDR_DQ24_DQ25() -> u8HL = (ParValue))
#define u8GetDDR_DQ24_DQ25HL() (pst_u8DDR_DQ24_DQ25() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ24_DQ25HH(ParValue) (pst_u8DDR_DQ24_DQ25() -> u8HH = (ParValue))
#define u8GetDDR_DQ24_DQ25HH() (pst_u8DDR_DQ24_DQ25() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ24_DQ25L(ParValue) (pst_u16DDR_DQ24_DQ25() -> u16L = (ParValue))
#define u16GetDDR_DQ24_DQ25L() (pst_u16DDR_DQ24_DQ25() -> u16L)
#define vSetDDR_DQ24_DQ25H(ParValue) (pst_u16DDR_DQ24_DQ25() -> u16H = (ParValue))
#define u16GetDDR_DQ24_DQ25H() (pst_u16DDR_DQ24_DQ25() -> u16H)
            
/* Word access */
#define vSetDDR_DQ24_DQ25(ParValue)  (*pu32DDR_DQ24_DQ25() = (ParValue))
#define u32GetDDR_DQ24_DQ25()  (*pu32DDR_DQ24_DQ25() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ26_DQ27                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030207C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ26_DQ27_REG__       0xC030207CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ26_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ26_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ26_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ26_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ26_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ26_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ27_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ27_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ27_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ27_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ27_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ27_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ26_DQ27_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ26_DQ27_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ26_DQ27_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ26_DQ27_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ26_DQ27()     ((volatile DDR_DQ26_DQ27_bit_view_st *)\
(DDR_DQ26_DQ27_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ26_DQ27()     ((volatile DDR_DQ26_DQ27_byte_view_st *)\
(DDR_DQ26_DQ27_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ26_DQ27()     ((volatile DDR_DQ26_DQ27_halfword_view_st *)\
(DDR_DQ26_DQ27_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ26_DQ27()     ((volatile u32DDR_DQ26_DQ27_word_view *)\
(DDR_DQ26_DQ27_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ26_DQ27_DDR_DQ26_SEL() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_SEL)
#define vSetDDR_DQ26_DQ27_DDR_DQ26_SEL(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_SEL=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ26_PU() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_PU)
#define vSetDDR_DQ26_DQ27_DDR_DQ26_PU(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_PU=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ26_PD() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_PD)
#define vSetDDR_DQ26_DQ27_DDR_DQ26_PD(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_PD=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ26_SMT() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_SMT)
#define vSetDDR_DQ26_DQ27_DDR_DQ26_SMT(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_SMT=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ26_IMP() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_IMP)
#define vSetDDR_DQ26_DQ27_DDR_DQ26_IMP(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_IMP=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ26_LATCHN() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_LATCHN)
#define vSetDDR_DQ26_DQ27_DDR_DQ26_LATCHN(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ26_LATCHN=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ27_SEL() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_SEL)
#define vSetDDR_DQ26_DQ27_DDR_DQ27_SEL(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_SEL=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ27_PU() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_PU)
#define vSetDDR_DQ26_DQ27_DDR_DQ27_PU(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_PU=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ27_PD() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_PD)
#define vSetDDR_DQ26_DQ27_DDR_DQ27_PD(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_PD=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ27_SMT() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_SMT)
#define vSetDDR_DQ26_DQ27_DDR_DQ27_SMT(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_SMT=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ27_IMP() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_IMP)
#define vSetDDR_DQ26_DQ27_DDR_DQ27_IMP(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_IMP=(ParValue))
#define biGetDDR_DQ26_DQ27_DDR_DQ27_LATCHN() (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_LATCHN)
#define vSetDDR_DQ26_DQ27_DDR_DQ27_LATCHN(ParValue)  (pst_bitDDR_DQ26_DQ27() -> DDR_DQ27_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ26_DQ27LL(ParValue) (pst_u8DDR_DQ26_DQ27() -> u8LL = (ParValue))
#define u8GetDDR_DQ26_DQ27LL() (pst_u8DDR_DQ26_DQ27() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ26_DQ27LH(ParValue) (pst_u8DDR_DQ26_DQ27() -> u8LH = (ParValue))
#define u8GetDDR_DQ26_DQ27LH() (pst_u8DDR_DQ26_DQ27() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ26_DQ27HL(ParValue) (pst_u8DDR_DQ26_DQ27() -> u8HL = (ParValue))
#define u8GetDDR_DQ26_DQ27HL() (pst_u8DDR_DQ26_DQ27() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ26_DQ27HH(ParValue) (pst_u8DDR_DQ26_DQ27() -> u8HH = (ParValue))
#define u8GetDDR_DQ26_DQ27HH() (pst_u8DDR_DQ26_DQ27() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ26_DQ27L(ParValue) (pst_u16DDR_DQ26_DQ27() -> u16L = (ParValue))
#define u16GetDDR_DQ26_DQ27L() (pst_u16DDR_DQ26_DQ27() -> u16L)
#define vSetDDR_DQ26_DQ27H(ParValue) (pst_u16DDR_DQ26_DQ27() -> u16H = (ParValue))
#define u16GetDDR_DQ26_DQ27H() (pst_u16DDR_DQ26_DQ27() -> u16H)
            
/* Word access */
#define vSetDDR_DQ26_DQ27(ParValue)  (*pu32DDR_DQ26_DQ27() = (ParValue))
#define u32GetDDR_DQ26_DQ27()  (*pu32DDR_DQ26_DQ27() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ28_DQ29                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302080                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ28_DQ29_REG__       0xC0302080U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ28_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ28_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ28_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ28_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ28_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ28_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ29_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ29_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ29_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ29_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ29_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ29_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ28_DQ29_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ28_DQ29_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ28_DQ29_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ28_DQ29_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ28_DQ29()     ((volatile DDR_DQ28_DQ29_bit_view_st *)\
(DDR_DQ28_DQ29_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ28_DQ29()     ((volatile DDR_DQ28_DQ29_byte_view_st *)\
(DDR_DQ28_DQ29_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ28_DQ29()     ((volatile DDR_DQ28_DQ29_halfword_view_st *)\
(DDR_DQ28_DQ29_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ28_DQ29()     ((volatile u32DDR_DQ28_DQ29_word_view *)\
(DDR_DQ28_DQ29_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ28_DQ29_DDR_DQ28_SEL() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_SEL)
#define vSetDDR_DQ28_DQ29_DDR_DQ28_SEL(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_SEL=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ28_PU() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_PU)
#define vSetDDR_DQ28_DQ29_DDR_DQ28_PU(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_PU=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ28_PD() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_PD)
#define vSetDDR_DQ28_DQ29_DDR_DQ28_PD(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_PD=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ28_SMT() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_SMT)
#define vSetDDR_DQ28_DQ29_DDR_DQ28_SMT(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_SMT=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ28_IMP() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_IMP)
#define vSetDDR_DQ28_DQ29_DDR_DQ28_IMP(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_IMP=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ28_LATCHN() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_LATCHN)
#define vSetDDR_DQ28_DQ29_DDR_DQ28_LATCHN(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ28_LATCHN=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ29_SEL() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_SEL)
#define vSetDDR_DQ28_DQ29_DDR_DQ29_SEL(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_SEL=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ29_PU() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_PU)
#define vSetDDR_DQ28_DQ29_DDR_DQ29_PU(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_PU=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ29_PD() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_PD)
#define vSetDDR_DQ28_DQ29_DDR_DQ29_PD(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_PD=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ29_SMT() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_SMT)
#define vSetDDR_DQ28_DQ29_DDR_DQ29_SMT(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_SMT=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ29_IMP() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_IMP)
#define vSetDDR_DQ28_DQ29_DDR_DQ29_IMP(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_IMP=(ParValue))
#define biGetDDR_DQ28_DQ29_DDR_DQ29_LATCHN() (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_LATCHN)
#define vSetDDR_DQ28_DQ29_DDR_DQ29_LATCHN(ParValue)  (pst_bitDDR_DQ28_DQ29() -> DDR_DQ29_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ28_DQ29LL(ParValue) (pst_u8DDR_DQ28_DQ29() -> u8LL = (ParValue))
#define u8GetDDR_DQ28_DQ29LL() (pst_u8DDR_DQ28_DQ29() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ28_DQ29LH(ParValue) (pst_u8DDR_DQ28_DQ29() -> u8LH = (ParValue))
#define u8GetDDR_DQ28_DQ29LH() (pst_u8DDR_DQ28_DQ29() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ28_DQ29HL(ParValue) (pst_u8DDR_DQ28_DQ29() -> u8HL = (ParValue))
#define u8GetDDR_DQ28_DQ29HL() (pst_u8DDR_DQ28_DQ29() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ28_DQ29HH(ParValue) (pst_u8DDR_DQ28_DQ29() -> u8HH = (ParValue))
#define u8GetDDR_DQ28_DQ29HH() (pst_u8DDR_DQ28_DQ29() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ28_DQ29L(ParValue) (pst_u16DDR_DQ28_DQ29() -> u16L = (ParValue))
#define u16GetDDR_DQ28_DQ29L() (pst_u16DDR_DQ28_DQ29() -> u16L)
#define vSetDDR_DQ28_DQ29H(ParValue) (pst_u16DDR_DQ28_DQ29() -> u16H = (ParValue))
#define u16GetDDR_DQ28_DQ29H() (pst_u16DDR_DQ28_DQ29() -> u16H)
            
/* Word access */
#define vSetDDR_DQ28_DQ29(ParValue)  (*pu32DDR_DQ28_DQ29() = (ParValue))
#define u32GetDDR_DQ28_DQ29()  (*pu32DDR_DQ28_DQ29() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DDR_DQ30_DQ31                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302084                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DDR_DQ30_DQ31_REG__       0xC0302084U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DDR_DQ30_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DDR_DQ30_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DDR_DQ30_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DDR_DQ30_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   DDR_DQ30_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   DDR_DQ30_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   DDR_DQ31_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   DDR_DQ31_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DDR_DQ31_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DDR_DQ31_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DDR_DQ31_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   DDR_DQ31_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DDR_DQ30_DQ31_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DDR_DQ30_DQ31_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DDR_DQ30_DQ31_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DDR_DQ30_DQ31_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDDR_DQ30_DQ31()     ((volatile DDR_DQ30_DQ31_bit_view_st *)\
(DDR_DQ30_DQ31_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DDR_DQ30_DQ31()     ((volatile DDR_DQ30_DQ31_byte_view_st *)\
(DDR_DQ30_DQ31_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DDR_DQ30_DQ31()     ((volatile DDR_DQ30_DQ31_halfword_view_st *)\
(DDR_DQ30_DQ31_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DDR_DQ30_DQ31()     ((volatile u32DDR_DQ30_DQ31_word_view *)\
(DDR_DQ30_DQ31_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDDR_DQ30_DQ31_DDR_DQ30_SEL() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_SEL)
#define vSetDDR_DQ30_DQ31_DDR_DQ30_SEL(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_SEL=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ30_PU() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_PU)
#define vSetDDR_DQ30_DQ31_DDR_DQ30_PU(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_PU=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ30_PD() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_PD)
#define vSetDDR_DQ30_DQ31_DDR_DQ30_PD(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_PD=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ30_SMT() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_SMT)
#define vSetDDR_DQ30_DQ31_DDR_DQ30_SMT(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_SMT=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ30_IMP() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_IMP)
#define vSetDDR_DQ30_DQ31_DDR_DQ30_IMP(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_IMP=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ30_LATCHN() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_LATCHN)
#define vSetDDR_DQ30_DQ31_DDR_DQ30_LATCHN(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ30_LATCHN=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ31_SEL() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_SEL)
#define vSetDDR_DQ30_DQ31_DDR_DQ31_SEL(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_SEL=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ31_PU() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_PU)
#define vSetDDR_DQ30_DQ31_DDR_DQ31_PU(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_PU=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ31_PD() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_PD)
#define vSetDDR_DQ30_DQ31_DDR_DQ31_PD(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_PD=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ31_SMT() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_SMT)
#define vSetDDR_DQ30_DQ31_DDR_DQ31_SMT(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_SMT=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ31_IMP() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_IMP)
#define vSetDDR_DQ30_DQ31_DDR_DQ31_IMP(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_IMP=(ParValue))
#define biGetDDR_DQ30_DQ31_DDR_DQ31_LATCHN() (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_LATCHN)
#define vSetDDR_DQ30_DQ31_DDR_DQ31_LATCHN(ParValue)  (pst_bitDDR_DQ30_DQ31() -> DDR_DQ31_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDDR_DQ30_DQ31LL(ParValue) (pst_u8DDR_DQ30_DQ31() -> u8LL = (ParValue))
#define u8GetDDR_DQ30_DQ31LL() (pst_u8DDR_DQ30_DQ31() -> u8LL)
/* LH-struct byte access */
#define vSetDDR_DQ30_DQ31LH(ParValue) (pst_u8DDR_DQ30_DQ31() -> u8LH = (ParValue))
#define u8GetDDR_DQ30_DQ31LH() (pst_u8DDR_DQ30_DQ31() -> u8LH)
/* HL-struct byte access */
#define vSetDDR_DQ30_DQ31HL(ParValue) (pst_u8DDR_DQ30_DQ31() -> u8HL = (ParValue))
#define u8GetDDR_DQ30_DQ31HL() (pst_u8DDR_DQ30_DQ31() -> u8HL)
/* HH-struct byte access */
#define vSetDDR_DQ30_DQ31HH(ParValue) (pst_u8DDR_DQ30_DQ31() -> u8HH = (ParValue))
#define u8GetDDR_DQ30_DQ31HH() (pst_u8DDR_DQ30_DQ31() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDDR_DQ30_DQ31L(ParValue) (pst_u16DDR_DQ30_DQ31() -> u16L = (ParValue))
#define u16GetDDR_DQ30_DQ31L() (pst_u16DDR_DQ30_DQ31() -> u16L)
#define vSetDDR_DQ30_DQ31H(ParValue) (pst_u16DDR_DQ30_DQ31() -> u16H = (ParValue))
#define u16GetDDR_DQ30_DQ31H() (pst_u16DDR_DQ30_DQ31() -> u16H)
            
/* Word access */
#define vSetDDR_DQ30_DQ31(ParValue)  (*pu32DDR_DQ30_DQ31() = (ParValue))
#define u32GetDDR_DQ30_DQ31()  (*pu32DDR_DQ30_DQ31() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPI0_SIO0_SIO1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020A0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPI0_SIO0_SIO1_REG__       0xC03020A0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   QSPI0_SIO0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   QSPI0_SIO0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   QSPI0_SIO0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   QSPI0_SIO0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   QSPI0_SIO0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   QSPI0_SIO0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   QSPI0_SIO1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   QSPI0_SIO1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   QSPI0_SIO1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   QSPI0_SIO1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   QSPI0_SIO1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   QSPI0_SIO1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} QSPI0_SIO0_SIO1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPI0_SIO0_SIO1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPI0_SIO0_SIO1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPI0_SIO0_SIO1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPI0_SIO0_SIO1()     ((volatile QSPI0_SIO0_SIO1_bit_view_st *)\
(QSPI0_SIO0_SIO1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPI0_SIO0_SIO1()     ((volatile QSPI0_SIO0_SIO1_byte_view_st *)\
(QSPI0_SIO0_SIO1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPI0_SIO0_SIO1()     ((volatile QSPI0_SIO0_SIO1_halfword_view_st *)\
(QSPI0_SIO0_SIO1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32QSPI0_SIO0_SIO1()     ((volatile u32QSPI0_SIO0_SIO1_word_view *)\
(QSPI0_SIO0_SIO1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO0_SEL() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_SEL)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO0_SEL(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_SEL=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO0_PU() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_PU)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO0_PU(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_PU=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO0_PD() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_PD)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO0_PD(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_PD=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO0_SMT() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_SMT)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO0_SMT(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_SMT=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO0_IMP() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_IMP)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO0_IMP(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_IMP=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO0_LATCHN() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_LATCHN)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO0_LATCHN(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO0_LATCHN=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO1_SEL() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_SEL)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO1_SEL(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_SEL=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO1_PU() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_PU)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO1_PU(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_PU=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO1_PD() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_PD)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO1_PD(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_PD=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO1_SMT() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_SMT)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO1_SMT(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_SMT=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO1_IMP() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_IMP)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO1_IMP(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_IMP=(ParValue))
#define biGetQSPI0_SIO0_SIO1_QSPI0_SIO1_LATCHN() (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_LATCHN)
#define vSetQSPI0_SIO0_SIO1_QSPI0_SIO1_LATCHN(ParValue)  (pst_bitQSPI0_SIO0_SIO1() -> QSPI0_SIO1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetQSPI0_SIO0_SIO1LL(ParValue) (pst_u8QSPI0_SIO0_SIO1() -> u8LL = (ParValue))
#define u8GetQSPI0_SIO0_SIO1LL() (pst_u8QSPI0_SIO0_SIO1() -> u8LL)
/* LH-struct byte access */
#define vSetQSPI0_SIO0_SIO1LH(ParValue) (pst_u8QSPI0_SIO0_SIO1() -> u8LH = (ParValue))
#define u8GetQSPI0_SIO0_SIO1LH() (pst_u8QSPI0_SIO0_SIO1() -> u8LH)
/* HL-struct byte access */
#define vSetQSPI0_SIO0_SIO1HL(ParValue) (pst_u8QSPI0_SIO0_SIO1() -> u8HL = (ParValue))
#define u8GetQSPI0_SIO0_SIO1HL() (pst_u8QSPI0_SIO0_SIO1() -> u8HL)
/* HH-struct byte access */
#define vSetQSPI0_SIO0_SIO1HH(ParValue) (pst_u8QSPI0_SIO0_SIO1() -> u8HH = (ParValue))
#define u8GetQSPI0_SIO0_SIO1HH() (pst_u8QSPI0_SIO0_SIO1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPI0_SIO0_SIO1L(ParValue) (pst_u16QSPI0_SIO0_SIO1() -> u16L = (ParValue))
#define u16GetQSPI0_SIO0_SIO1L() (pst_u16QSPI0_SIO0_SIO1() -> u16L)
#define vSetQSPI0_SIO0_SIO1H(ParValue) (pst_u16QSPI0_SIO0_SIO1() -> u16H = (ParValue))
#define u16GetQSPI0_SIO0_SIO1H() (pst_u16QSPI0_SIO0_SIO1() -> u16H)
            
/* Word access */
#define vSetQSPI0_SIO0_SIO1(ParValue)  (*pu32QSPI0_SIO0_SIO1() = (ParValue))
#define u32GetQSPI0_SIO0_SIO1()  (*pu32QSPI0_SIO0_SIO1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPI0_SIO2_SIO3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020A4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPI0_SIO2_SIO3_REG__       0xC03020A4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   QSPI0_SIO2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   QSPI0_SIO2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   QSPI0_SIO2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   QSPI0_SIO2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   QSPI0_SIO2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   QSPI0_SIO2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   QSPI0_SIO3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   QSPI0_SIO3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   QSPI0_SIO3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   QSPI0_SIO3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   QSPI0_SIO3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   QSPI0_SIO3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} QSPI0_SIO2_SIO3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPI0_SIO2_SIO3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPI0_SIO2_SIO3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPI0_SIO2_SIO3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPI0_SIO2_SIO3()     ((volatile QSPI0_SIO2_SIO3_bit_view_st *)\
(QSPI0_SIO2_SIO3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPI0_SIO2_SIO3()     ((volatile QSPI0_SIO2_SIO3_byte_view_st *)\
(QSPI0_SIO2_SIO3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPI0_SIO2_SIO3()     ((volatile QSPI0_SIO2_SIO3_halfword_view_st *)\
(QSPI0_SIO2_SIO3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32QSPI0_SIO2_SIO3()     ((volatile u32QSPI0_SIO2_SIO3_word_view *)\
(QSPI0_SIO2_SIO3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO2_SEL() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_SEL)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO2_SEL(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_SEL=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO2_PU() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_PU)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO2_PU(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_PU=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO2_PD() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_PD)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO2_PD(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_PD=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO2_SMT() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_SMT)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO2_SMT(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_SMT=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO2_IMP() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_IMP)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO2_IMP(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_IMP=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO2_LATCHN() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_LATCHN)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO2_LATCHN(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO2_LATCHN=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO3_SEL() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_SEL)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO3_SEL(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_SEL=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO3_PU() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_PU)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO3_PU(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_PU=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO3_PD() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_PD)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO3_PD(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_PD=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO3_SMT() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_SMT)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO3_SMT(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_SMT=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO3_IMP() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_IMP)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO3_IMP(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_IMP=(ParValue))
#define biGetQSPI0_SIO2_SIO3_QSPI0_SIO3_LATCHN() (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_LATCHN)
#define vSetQSPI0_SIO2_SIO3_QSPI0_SIO3_LATCHN(ParValue)  (pst_bitQSPI0_SIO2_SIO3() -> QSPI0_SIO3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetQSPI0_SIO2_SIO3LL(ParValue) (pst_u8QSPI0_SIO2_SIO3() -> u8LL = (ParValue))
#define u8GetQSPI0_SIO2_SIO3LL() (pst_u8QSPI0_SIO2_SIO3() -> u8LL)
/* LH-struct byte access */
#define vSetQSPI0_SIO2_SIO3LH(ParValue) (pst_u8QSPI0_SIO2_SIO3() -> u8LH = (ParValue))
#define u8GetQSPI0_SIO2_SIO3LH() (pst_u8QSPI0_SIO2_SIO3() -> u8LH)
/* HL-struct byte access */
#define vSetQSPI0_SIO2_SIO3HL(ParValue) (pst_u8QSPI0_SIO2_SIO3() -> u8HL = (ParValue))
#define u8GetQSPI0_SIO2_SIO3HL() (pst_u8QSPI0_SIO2_SIO3() -> u8HL)
/* HH-struct byte access */
#define vSetQSPI0_SIO2_SIO3HH(ParValue) (pst_u8QSPI0_SIO2_SIO3() -> u8HH = (ParValue))
#define u8GetQSPI0_SIO2_SIO3HH() (pst_u8QSPI0_SIO2_SIO3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPI0_SIO2_SIO3L(ParValue) (pst_u16QSPI0_SIO2_SIO3() -> u16L = (ParValue))
#define u16GetQSPI0_SIO2_SIO3L() (pst_u16QSPI0_SIO2_SIO3() -> u16L)
#define vSetQSPI0_SIO2_SIO3H(ParValue) (pst_u16QSPI0_SIO2_SIO3() -> u16H = (ParValue))
#define u16GetQSPI0_SIO2_SIO3H() (pst_u16QSPI0_SIO2_SIO3() -> u16H)
            
/* Word access */
#define vSetQSPI0_SIO2_SIO3(ParValue)  (*pu32QSPI0_SIO2_SIO3() = (ParValue))
#define u32GetQSPI0_SIO2_SIO3()  (*pu32QSPI0_SIO2_SIO3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPI0_CS0_SCLK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020A8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPI0_CS0_SCLK_REG__       0xC03020A8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   QSPI0_CS0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   QSPI0_CS0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   QSPI0_CS0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   QSPI0_CS0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   QSPI0_CS0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   QSPI0_CS0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   QSPI0_SCLK_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   QSPI0_SCLK_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   QSPI0_SCLK_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   QSPI0_SCLK_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   QSPI0_SCLK_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   QSPI0_SCLK_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} QSPI0_CS0_SCLK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPI0_CS0_SCLK_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPI0_CS0_SCLK_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPI0_CS0_SCLK_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPI0_CS0_SCLK()     ((volatile QSPI0_CS0_SCLK_bit_view_st *)\
(QSPI0_CS0_SCLK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPI0_CS0_SCLK()     ((volatile QSPI0_CS0_SCLK_byte_view_st *)\
(QSPI0_CS0_SCLK_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPI0_CS0_SCLK()     ((volatile QSPI0_CS0_SCLK_halfword_view_st *)\
(QSPI0_CS0_SCLK_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32QSPI0_CS0_SCLK()     ((volatile u32QSPI0_CS0_SCLK_word_view *)\
(QSPI0_CS0_SCLK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPI0_CS0_SCLK_QSPI0_CS0_SEL() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_SEL)
#define vSetQSPI0_CS0_SCLK_QSPI0_CS0_SEL(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_SEL=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_CS0_PU() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_PU)
#define vSetQSPI0_CS0_SCLK_QSPI0_CS0_PU(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_PU=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_CS0_PD() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_PD)
#define vSetQSPI0_CS0_SCLK_QSPI0_CS0_PD(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_PD=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_CS0_SMT() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_SMT)
#define vSetQSPI0_CS0_SCLK_QSPI0_CS0_SMT(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_SMT=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_CS0_IMP() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_IMP)
#define vSetQSPI0_CS0_SCLK_QSPI0_CS0_IMP(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_IMP=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_CS0_LATCHN() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_LATCHN)
#define vSetQSPI0_CS0_SCLK_QSPI0_CS0_LATCHN(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_CS0_LATCHN=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_SCLK_SEL() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_SEL)
#define vSetQSPI0_CS0_SCLK_QSPI0_SCLK_SEL(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_SEL=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_SCLK_PU() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_PU)
#define vSetQSPI0_CS0_SCLK_QSPI0_SCLK_PU(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_PU=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_SCLK_PD() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_PD)
#define vSetQSPI0_CS0_SCLK_QSPI0_SCLK_PD(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_PD=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_SCLK_SMT() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_SMT)
#define vSetQSPI0_CS0_SCLK_QSPI0_SCLK_SMT(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_SMT=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_SCLK_IMP() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_IMP)
#define vSetQSPI0_CS0_SCLK_QSPI0_SCLK_IMP(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_IMP=(ParValue))
#define biGetQSPI0_CS0_SCLK_QSPI0_SCLK_LATCHN() (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_LATCHN)
#define vSetQSPI0_CS0_SCLK_QSPI0_SCLK_LATCHN(ParValue)  (pst_bitQSPI0_CS0_SCLK() -> QSPI0_SCLK_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetQSPI0_CS0_SCLKLL(ParValue) (pst_u8QSPI0_CS0_SCLK() -> u8LL = (ParValue))
#define u8GetQSPI0_CS0_SCLKLL() (pst_u8QSPI0_CS0_SCLK() -> u8LL)
/* LH-struct byte access */
#define vSetQSPI0_CS0_SCLKLH(ParValue) (pst_u8QSPI0_CS0_SCLK() -> u8LH = (ParValue))
#define u8GetQSPI0_CS0_SCLKLH() (pst_u8QSPI0_CS0_SCLK() -> u8LH)
/* HL-struct byte access */
#define vSetQSPI0_CS0_SCLKHL(ParValue) (pst_u8QSPI0_CS0_SCLK() -> u8HL = (ParValue))
#define u8GetQSPI0_CS0_SCLKHL() (pst_u8QSPI0_CS0_SCLK() -> u8HL)
/* HH-struct byte access */
#define vSetQSPI0_CS0_SCLKHH(ParValue) (pst_u8QSPI0_CS0_SCLK() -> u8HH = (ParValue))
#define u8GetQSPI0_CS0_SCLKHH() (pst_u8QSPI0_CS0_SCLK() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPI0_CS0_SCLKL(ParValue) (pst_u16QSPI0_CS0_SCLK() -> u16L = (ParValue))
#define u16GetQSPI0_CS0_SCLKL() (pst_u16QSPI0_CS0_SCLK() -> u16L)
#define vSetQSPI0_CS0_SCLKH(ParValue) (pst_u16QSPI0_CS0_SCLK() -> u16H = (ParValue))
#define u16GetQSPI0_CS0_SCLKH() (pst_u16QSPI0_CS0_SCLK() -> u16H)
            
/* Word access */
#define vSetQSPI0_CS0_SCLK(ParValue)  (*pu32QSPI0_CS0_SCLK() = (ParValue))
#define u32GetQSPI0_CS0_SCLK()  (*pu32QSPI0_CS0_SCLK() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0HDISP_HSYNC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020C0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0HDISP_HSYNC_REG__       0xC03020C0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0HDISP_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0HDISP_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0HDISP_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0HDISP_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0HDISP_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0HDISP_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0HSYNC_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0HSYNC_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0HSYNC_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0HSYNC_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0HSYNC_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0HSYNC_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0HDISP_HSYNC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0HDISP_HSYNC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0HDISP_HSYNC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0HDISP_HSYNC_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0HDISP_HSYNC()     ((volatile D0HDISP_HSYNC_bit_view_st *)\
(D0HDISP_HSYNC_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0HDISP_HSYNC()     ((volatile D0HDISP_HSYNC_byte_view_st *)\
(D0HDISP_HSYNC_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0HDISP_HSYNC()     ((volatile D0HDISP_HSYNC_halfword_view_st *)\
(D0HDISP_HSYNC_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0HDISP_HSYNC()     ((volatile u32D0HDISP_HSYNC_word_view *)\
(D0HDISP_HSYNC_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0HDISP_HSYNC_D0HDISP_SEL() (pst_bitD0HDISP_HSYNC() -> D0HDISP_SEL)
#define vSetD0HDISP_HSYNC_D0HDISP_SEL(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HDISP_SEL=(ParValue))
#define biGetD0HDISP_HSYNC_D0HDISP_PU() (pst_bitD0HDISP_HSYNC() -> D0HDISP_PU)
#define vSetD0HDISP_HSYNC_D0HDISP_PU(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HDISP_PU=(ParValue))
#define biGetD0HDISP_HSYNC_D0HDISP_PD() (pst_bitD0HDISP_HSYNC() -> D0HDISP_PD)
#define vSetD0HDISP_HSYNC_D0HDISP_PD(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HDISP_PD=(ParValue))
#define biGetD0HDISP_HSYNC_D0HDISP_SMT() (pst_bitD0HDISP_HSYNC() -> D0HDISP_SMT)
#define vSetD0HDISP_HSYNC_D0HDISP_SMT(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HDISP_SMT=(ParValue))
#define biGetD0HDISP_HSYNC_D0HDISP_IMP() (pst_bitD0HDISP_HSYNC() -> D0HDISP_IMP)
#define vSetD0HDISP_HSYNC_D0HDISP_IMP(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HDISP_IMP=(ParValue))
#define biGetD0HDISP_HSYNC_D0HDISP_LATCHN() (pst_bitD0HDISP_HSYNC() -> D0HDISP_LATCHN)
#define vSetD0HDISP_HSYNC_D0HDISP_LATCHN(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HDISP_LATCHN=(ParValue))
#define biGetD0HDISP_HSYNC_D0HSYNC_SEL() (pst_bitD0HDISP_HSYNC() -> D0HSYNC_SEL)
#define vSetD0HDISP_HSYNC_D0HSYNC_SEL(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HSYNC_SEL=(ParValue))
#define biGetD0HDISP_HSYNC_D0HSYNC_PU() (pst_bitD0HDISP_HSYNC() -> D0HSYNC_PU)
#define vSetD0HDISP_HSYNC_D0HSYNC_PU(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HSYNC_PU=(ParValue))
#define biGetD0HDISP_HSYNC_D0HSYNC_PD() (pst_bitD0HDISP_HSYNC() -> D0HSYNC_PD)
#define vSetD0HDISP_HSYNC_D0HSYNC_PD(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HSYNC_PD=(ParValue))
#define biGetD0HDISP_HSYNC_D0HSYNC_SMT() (pst_bitD0HDISP_HSYNC() -> D0HSYNC_SMT)
#define vSetD0HDISP_HSYNC_D0HSYNC_SMT(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HSYNC_SMT=(ParValue))
#define biGetD0HDISP_HSYNC_D0HSYNC_IMP() (pst_bitD0HDISP_HSYNC() -> D0HSYNC_IMP)
#define vSetD0HDISP_HSYNC_D0HSYNC_IMP(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HSYNC_IMP=(ParValue))
#define biGetD0HDISP_HSYNC_D0HSYNC_LATCHN() (pst_bitD0HDISP_HSYNC() -> D0HSYNC_LATCHN)
#define vSetD0HDISP_HSYNC_D0HSYNC_LATCHN(ParValue)  (pst_bitD0HDISP_HSYNC() -> D0HSYNC_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0HDISP_HSYNCLL(ParValue) (pst_u8D0HDISP_HSYNC() -> u8LL = (ParValue))
#define u8GetD0HDISP_HSYNCLL() (pst_u8D0HDISP_HSYNC() -> u8LL)
/* LH-struct byte access */
#define vSetD0HDISP_HSYNCLH(ParValue) (pst_u8D0HDISP_HSYNC() -> u8LH = (ParValue))
#define u8GetD0HDISP_HSYNCLH() (pst_u8D0HDISP_HSYNC() -> u8LH)
/* HL-struct byte access */
#define vSetD0HDISP_HSYNCHL(ParValue) (pst_u8D0HDISP_HSYNC() -> u8HL = (ParValue))
#define u8GetD0HDISP_HSYNCHL() (pst_u8D0HDISP_HSYNC() -> u8HL)
/* HH-struct byte access */
#define vSetD0HDISP_HSYNCHH(ParValue) (pst_u8D0HDISP_HSYNC() -> u8HH = (ParValue))
#define u8GetD0HDISP_HSYNCHH() (pst_u8D0HDISP_HSYNC() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0HDISP_HSYNCL(ParValue) (pst_u16D0HDISP_HSYNC() -> u16L = (ParValue))
#define u16GetD0HDISP_HSYNCL() (pst_u16D0HDISP_HSYNC() -> u16L)
#define vSetD0HDISP_HSYNCH(ParValue) (pst_u16D0HDISP_HSYNC() -> u16H = (ParValue))
#define u16GetD0HDISP_HSYNCH() (pst_u16D0HDISP_HSYNC() -> u16H)
            
/* Word access */
#define vSetD0HDISP_HSYNC(ParValue)  (*pu32D0HDISP_HSYNC() = (ParValue))
#define u32GetD0HDISP_HSYNC()  (*pu32D0HDISP_HSYNC() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0VSYNC_DOTCLK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020C4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0VSYNC_DOTCLK_REG__       0xC03020C4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0VSYNC_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0VSYNC_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0VSYNC_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0VSYNC_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0VSYNC_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0VSYNC_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0DOTCLK_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0DOTCLK_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0DOTCLK_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0DOTCLK_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0DOTCLK_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0DOTCLK_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0VSYNC_DOTCLK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0VSYNC_DOTCLK_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0VSYNC_DOTCLK_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0VSYNC_DOTCLK_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0VSYNC_DOTCLK()     ((volatile D0VSYNC_DOTCLK_bit_view_st *)\
(D0VSYNC_DOTCLK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0VSYNC_DOTCLK()     ((volatile D0VSYNC_DOTCLK_byte_view_st *)\
(D0VSYNC_DOTCLK_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0VSYNC_DOTCLK()     ((volatile D0VSYNC_DOTCLK_halfword_view_st *)\
(D0VSYNC_DOTCLK_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0VSYNC_DOTCLK()     ((volatile u32D0VSYNC_DOTCLK_word_view *)\
(D0VSYNC_DOTCLK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0VSYNC_DOTCLK_D0VSYNC_SEL() (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_SEL)
#define vSetD0VSYNC_DOTCLK_D0VSYNC_SEL(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_SEL=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0VSYNC_PU() (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_PU)
#define vSetD0VSYNC_DOTCLK_D0VSYNC_PU(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_PU=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0VSYNC_PD() (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_PD)
#define vSetD0VSYNC_DOTCLK_D0VSYNC_PD(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_PD=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0VSYNC_SMT() (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_SMT)
#define vSetD0VSYNC_DOTCLK_D0VSYNC_SMT(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_SMT=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0VSYNC_IMP() (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_IMP)
#define vSetD0VSYNC_DOTCLK_D0VSYNC_IMP(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_IMP=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0VSYNC_LATCHN() (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_LATCHN)
#define vSetD0VSYNC_DOTCLK_D0VSYNC_LATCHN(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0VSYNC_LATCHN=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0DOTCLK_SEL() (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_SEL)
#define vSetD0VSYNC_DOTCLK_D0DOTCLK_SEL(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_SEL=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0DOTCLK_PU() (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_PU)
#define vSetD0VSYNC_DOTCLK_D0DOTCLK_PU(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_PU=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0DOTCLK_PD() (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_PD)
#define vSetD0VSYNC_DOTCLK_D0DOTCLK_PD(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_PD=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0DOTCLK_SMT() (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_SMT)
#define vSetD0VSYNC_DOTCLK_D0DOTCLK_SMT(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_SMT=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0DOTCLK_IMP() (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_IMP)
#define vSetD0VSYNC_DOTCLK_D0DOTCLK_IMP(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_IMP=(ParValue))
#define biGetD0VSYNC_DOTCLK_D0DOTCLK_LATCHN() (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_LATCHN)
#define vSetD0VSYNC_DOTCLK_D0DOTCLK_LATCHN(ParValue)  (pst_bitD0VSYNC_DOTCLK() -> D0DOTCLK_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0VSYNC_DOTCLKLL(ParValue) (pst_u8D0VSYNC_DOTCLK() -> u8LL = (ParValue))
#define u8GetD0VSYNC_DOTCLKLL() (pst_u8D0VSYNC_DOTCLK() -> u8LL)
/* LH-struct byte access */
#define vSetD0VSYNC_DOTCLKLH(ParValue) (pst_u8D0VSYNC_DOTCLK() -> u8LH = (ParValue))
#define u8GetD0VSYNC_DOTCLKLH() (pst_u8D0VSYNC_DOTCLK() -> u8LH)
/* HL-struct byte access */
#define vSetD0VSYNC_DOTCLKHL(ParValue) (pst_u8D0VSYNC_DOTCLK() -> u8HL = (ParValue))
#define u8GetD0VSYNC_DOTCLKHL() (pst_u8D0VSYNC_DOTCLK() -> u8HL)
/* HH-struct byte access */
#define vSetD0VSYNC_DOTCLKHH(ParValue) (pst_u8D0VSYNC_DOTCLK() -> u8HH = (ParValue))
#define u8GetD0VSYNC_DOTCLKHH() (pst_u8D0VSYNC_DOTCLK() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0VSYNC_DOTCLKL(ParValue) (pst_u16D0VSYNC_DOTCLK() -> u16L = (ParValue))
#define u16GetD0VSYNC_DOTCLKL() (pst_u16D0VSYNC_DOTCLK() -> u16L)
#define vSetD0VSYNC_DOTCLKH(ParValue) (pst_u16D0VSYNC_DOTCLK() -> u16H = (ParValue))
#define u16GetD0VSYNC_DOTCLKH() (pst_u16D0VSYNC_DOTCLK() -> u16H)
            
/* Word access */
#define vSetD0VSYNC_DOTCLK(ParValue)  (*pu32D0VSYNC_DOTCLK() = (ParValue))
#define u32GetD0VSYNC_DOTCLK()  (*pu32D0VSYNC_DOTCLK() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB0_RGB1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020C8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB0_RGB1_REG__       0xC03020C8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB0_RGB1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB0_RGB1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB0_RGB1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB0_RGB1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB0_RGB1()     ((volatile D0RGB0_RGB1_bit_view_st *)\
(D0RGB0_RGB1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB0_RGB1()     ((volatile D0RGB0_RGB1_byte_view_st *)\
(D0RGB0_RGB1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB0_RGB1()     ((volatile D0RGB0_RGB1_halfword_view_st *)\
(D0RGB0_RGB1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB0_RGB1()     ((volatile u32D0RGB0_RGB1_word_view *)\
(D0RGB0_RGB1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB0_RGB1_D0RGB0_SEL() (pst_bitD0RGB0_RGB1() -> D0RGB0_SEL)
#define vSetD0RGB0_RGB1_D0RGB0_SEL(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB0_SEL=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB0_PU() (pst_bitD0RGB0_RGB1() -> D0RGB0_PU)
#define vSetD0RGB0_RGB1_D0RGB0_PU(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB0_PU=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB0_PD() (pst_bitD0RGB0_RGB1() -> D0RGB0_PD)
#define vSetD0RGB0_RGB1_D0RGB0_PD(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB0_PD=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB0_SMT() (pst_bitD0RGB0_RGB1() -> D0RGB0_SMT)
#define vSetD0RGB0_RGB1_D0RGB0_SMT(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB0_SMT=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB0_IMP() (pst_bitD0RGB0_RGB1() -> D0RGB0_IMP)
#define vSetD0RGB0_RGB1_D0RGB0_IMP(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB0_IMP=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB0_LATCHN() (pst_bitD0RGB0_RGB1() -> D0RGB0_LATCHN)
#define vSetD0RGB0_RGB1_D0RGB0_LATCHN(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB0_LATCHN=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB1_SEL() (pst_bitD0RGB0_RGB1() -> D0RGB1_SEL)
#define vSetD0RGB0_RGB1_D0RGB1_SEL(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB1_SEL=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB1_PU() (pst_bitD0RGB0_RGB1() -> D0RGB1_PU)
#define vSetD0RGB0_RGB1_D0RGB1_PU(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB1_PU=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB1_PD() (pst_bitD0RGB0_RGB1() -> D0RGB1_PD)
#define vSetD0RGB0_RGB1_D0RGB1_PD(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB1_PD=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB1_SMT() (pst_bitD0RGB0_RGB1() -> D0RGB1_SMT)
#define vSetD0RGB0_RGB1_D0RGB1_SMT(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB1_SMT=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB1_IMP() (pst_bitD0RGB0_RGB1() -> D0RGB1_IMP)
#define vSetD0RGB0_RGB1_D0RGB1_IMP(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB1_IMP=(ParValue))
#define biGetD0RGB0_RGB1_D0RGB1_LATCHN() (pst_bitD0RGB0_RGB1() -> D0RGB1_LATCHN)
#define vSetD0RGB0_RGB1_D0RGB1_LATCHN(ParValue)  (pst_bitD0RGB0_RGB1() -> D0RGB1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB0_RGB1LL(ParValue) (pst_u8D0RGB0_RGB1() -> u8LL = (ParValue))
#define u8GetD0RGB0_RGB1LL() (pst_u8D0RGB0_RGB1() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB0_RGB1LH(ParValue) (pst_u8D0RGB0_RGB1() -> u8LH = (ParValue))
#define u8GetD0RGB0_RGB1LH() (pst_u8D0RGB0_RGB1() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB0_RGB1HL(ParValue) (pst_u8D0RGB0_RGB1() -> u8HL = (ParValue))
#define u8GetD0RGB0_RGB1HL() (pst_u8D0RGB0_RGB1() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB0_RGB1HH(ParValue) (pst_u8D0RGB0_RGB1() -> u8HH = (ParValue))
#define u8GetD0RGB0_RGB1HH() (pst_u8D0RGB0_RGB1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB0_RGB1L(ParValue) (pst_u16D0RGB0_RGB1() -> u16L = (ParValue))
#define u16GetD0RGB0_RGB1L() (pst_u16D0RGB0_RGB1() -> u16L)
#define vSetD0RGB0_RGB1H(ParValue) (pst_u16D0RGB0_RGB1() -> u16H = (ParValue))
#define u16GetD0RGB0_RGB1H() (pst_u16D0RGB0_RGB1() -> u16H)
            
/* Word access */
#define vSetD0RGB0_RGB1(ParValue)  (*pu32D0RGB0_RGB1() = (ParValue))
#define u32GetD0RGB0_RGB1()  (*pu32D0RGB0_RGB1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB2_RGB3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020CC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB2_RGB3_REG__       0xC03020CCU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB2_RGB3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB2_RGB3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB2_RGB3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB2_RGB3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB2_RGB3()     ((volatile D0RGB2_RGB3_bit_view_st *)\
(D0RGB2_RGB3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB2_RGB3()     ((volatile D0RGB2_RGB3_byte_view_st *)\
(D0RGB2_RGB3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB2_RGB3()     ((volatile D0RGB2_RGB3_halfword_view_st *)\
(D0RGB2_RGB3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB2_RGB3()     ((volatile u32D0RGB2_RGB3_word_view *)\
(D0RGB2_RGB3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB2_RGB3_D0RGB2_SEL() (pst_bitD0RGB2_RGB3() -> D0RGB2_SEL)
#define vSetD0RGB2_RGB3_D0RGB2_SEL(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB2_SEL=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB2_PU() (pst_bitD0RGB2_RGB3() -> D0RGB2_PU)
#define vSetD0RGB2_RGB3_D0RGB2_PU(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB2_PU=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB2_PD() (pst_bitD0RGB2_RGB3() -> D0RGB2_PD)
#define vSetD0RGB2_RGB3_D0RGB2_PD(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB2_PD=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB2_SMT() (pst_bitD0RGB2_RGB3() -> D0RGB2_SMT)
#define vSetD0RGB2_RGB3_D0RGB2_SMT(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB2_SMT=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB2_IMP() (pst_bitD0RGB2_RGB3() -> D0RGB2_IMP)
#define vSetD0RGB2_RGB3_D0RGB2_IMP(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB2_IMP=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB2_LATCHN() (pst_bitD0RGB2_RGB3() -> D0RGB2_LATCHN)
#define vSetD0RGB2_RGB3_D0RGB2_LATCHN(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB2_LATCHN=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB3_SEL() (pst_bitD0RGB2_RGB3() -> D0RGB3_SEL)
#define vSetD0RGB2_RGB3_D0RGB3_SEL(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB3_SEL=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB3_PU() (pst_bitD0RGB2_RGB3() -> D0RGB3_PU)
#define vSetD0RGB2_RGB3_D0RGB3_PU(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB3_PU=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB3_PD() (pst_bitD0RGB2_RGB3() -> D0RGB3_PD)
#define vSetD0RGB2_RGB3_D0RGB3_PD(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB3_PD=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB3_SMT() (pst_bitD0RGB2_RGB3() -> D0RGB3_SMT)
#define vSetD0RGB2_RGB3_D0RGB3_SMT(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB3_SMT=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB3_IMP() (pst_bitD0RGB2_RGB3() -> D0RGB3_IMP)
#define vSetD0RGB2_RGB3_D0RGB3_IMP(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB3_IMP=(ParValue))
#define biGetD0RGB2_RGB3_D0RGB3_LATCHN() (pst_bitD0RGB2_RGB3() -> D0RGB3_LATCHN)
#define vSetD0RGB2_RGB3_D0RGB3_LATCHN(ParValue)  (pst_bitD0RGB2_RGB3() -> D0RGB3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB2_RGB3LL(ParValue) (pst_u8D0RGB2_RGB3() -> u8LL = (ParValue))
#define u8GetD0RGB2_RGB3LL() (pst_u8D0RGB2_RGB3() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB2_RGB3LH(ParValue) (pst_u8D0RGB2_RGB3() -> u8LH = (ParValue))
#define u8GetD0RGB2_RGB3LH() (pst_u8D0RGB2_RGB3() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB2_RGB3HL(ParValue) (pst_u8D0RGB2_RGB3() -> u8HL = (ParValue))
#define u8GetD0RGB2_RGB3HL() (pst_u8D0RGB2_RGB3() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB2_RGB3HH(ParValue) (pst_u8D0RGB2_RGB3() -> u8HH = (ParValue))
#define u8GetD0RGB2_RGB3HH() (pst_u8D0RGB2_RGB3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB2_RGB3L(ParValue) (pst_u16D0RGB2_RGB3() -> u16L = (ParValue))
#define u16GetD0RGB2_RGB3L() (pst_u16D0RGB2_RGB3() -> u16L)
#define vSetD0RGB2_RGB3H(ParValue) (pst_u16D0RGB2_RGB3() -> u16H = (ParValue))
#define u16GetD0RGB2_RGB3H() (pst_u16D0RGB2_RGB3() -> u16H)
            
/* Word access */
#define vSetD0RGB2_RGB3(ParValue)  (*pu32D0RGB2_RGB3() = (ParValue))
#define u32GetD0RGB2_RGB3()  (*pu32D0RGB2_RGB3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB4_RGB5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020D0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB4_RGB5_REG__       0xC03020D0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB4_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB4_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB4_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB4_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB4_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB4_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB5_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB5_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB5_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB5_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB5_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB5_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB4_RGB5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB4_RGB5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB4_RGB5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB4_RGB5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB4_RGB5()     ((volatile D0RGB4_RGB5_bit_view_st *)\
(D0RGB4_RGB5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB4_RGB5()     ((volatile D0RGB4_RGB5_byte_view_st *)\
(D0RGB4_RGB5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB4_RGB5()     ((volatile D0RGB4_RGB5_halfword_view_st *)\
(D0RGB4_RGB5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB4_RGB5()     ((volatile u32D0RGB4_RGB5_word_view *)\
(D0RGB4_RGB5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB4_RGB5_D0RGB4_SEL() (pst_bitD0RGB4_RGB5() -> D0RGB4_SEL)
#define vSetD0RGB4_RGB5_D0RGB4_SEL(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB4_SEL=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB4_PU() (pst_bitD0RGB4_RGB5() -> D0RGB4_PU)
#define vSetD0RGB4_RGB5_D0RGB4_PU(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB4_PU=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB4_PD() (pst_bitD0RGB4_RGB5() -> D0RGB4_PD)
#define vSetD0RGB4_RGB5_D0RGB4_PD(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB4_PD=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB4_SMT() (pst_bitD0RGB4_RGB5() -> D0RGB4_SMT)
#define vSetD0RGB4_RGB5_D0RGB4_SMT(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB4_SMT=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB4_IMP() (pst_bitD0RGB4_RGB5() -> D0RGB4_IMP)
#define vSetD0RGB4_RGB5_D0RGB4_IMP(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB4_IMP=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB4_LATCHN() (pst_bitD0RGB4_RGB5() -> D0RGB4_LATCHN)
#define vSetD0RGB4_RGB5_D0RGB4_LATCHN(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB4_LATCHN=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB5_SEL() (pst_bitD0RGB4_RGB5() -> D0RGB5_SEL)
#define vSetD0RGB4_RGB5_D0RGB5_SEL(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB5_SEL=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB5_PU() (pst_bitD0RGB4_RGB5() -> D0RGB5_PU)
#define vSetD0RGB4_RGB5_D0RGB5_PU(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB5_PU=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB5_PD() (pst_bitD0RGB4_RGB5() -> D0RGB5_PD)
#define vSetD0RGB4_RGB5_D0RGB5_PD(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB5_PD=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB5_SMT() (pst_bitD0RGB4_RGB5() -> D0RGB5_SMT)
#define vSetD0RGB4_RGB5_D0RGB5_SMT(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB5_SMT=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB5_IMP() (pst_bitD0RGB4_RGB5() -> D0RGB5_IMP)
#define vSetD0RGB4_RGB5_D0RGB5_IMP(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB5_IMP=(ParValue))
#define biGetD0RGB4_RGB5_D0RGB5_LATCHN() (pst_bitD0RGB4_RGB5() -> D0RGB5_LATCHN)
#define vSetD0RGB4_RGB5_D0RGB5_LATCHN(ParValue)  (pst_bitD0RGB4_RGB5() -> D0RGB5_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB4_RGB5LL(ParValue) (pst_u8D0RGB4_RGB5() -> u8LL = (ParValue))
#define u8GetD0RGB4_RGB5LL() (pst_u8D0RGB4_RGB5() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB4_RGB5LH(ParValue) (pst_u8D0RGB4_RGB5() -> u8LH = (ParValue))
#define u8GetD0RGB4_RGB5LH() (pst_u8D0RGB4_RGB5() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB4_RGB5HL(ParValue) (pst_u8D0RGB4_RGB5() -> u8HL = (ParValue))
#define u8GetD0RGB4_RGB5HL() (pst_u8D0RGB4_RGB5() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB4_RGB5HH(ParValue) (pst_u8D0RGB4_RGB5() -> u8HH = (ParValue))
#define u8GetD0RGB4_RGB5HH() (pst_u8D0RGB4_RGB5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB4_RGB5L(ParValue) (pst_u16D0RGB4_RGB5() -> u16L = (ParValue))
#define u16GetD0RGB4_RGB5L() (pst_u16D0RGB4_RGB5() -> u16L)
#define vSetD0RGB4_RGB5H(ParValue) (pst_u16D0RGB4_RGB5() -> u16H = (ParValue))
#define u16GetD0RGB4_RGB5H() (pst_u16D0RGB4_RGB5() -> u16H)
            
/* Word access */
#define vSetD0RGB4_RGB5(ParValue)  (*pu32D0RGB4_RGB5() = (ParValue))
#define u32GetD0RGB4_RGB5()  (*pu32D0RGB4_RGB5() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB6_RGB7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020D4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB6_RGB7_REG__       0xC03020D4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB6_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB6_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB6_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB6_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB6_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB6_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB7_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB7_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB7_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB7_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB7_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB7_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB6_RGB7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB6_RGB7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB6_RGB7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB6_RGB7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB6_RGB7()     ((volatile D0RGB6_RGB7_bit_view_st *)\
(D0RGB6_RGB7_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB6_RGB7()     ((volatile D0RGB6_RGB7_byte_view_st *)\
(D0RGB6_RGB7_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB6_RGB7()     ((volatile D0RGB6_RGB7_halfword_view_st *)\
(D0RGB6_RGB7_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB6_RGB7()     ((volatile u32D0RGB6_RGB7_word_view *)\
(D0RGB6_RGB7_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB6_RGB7_D0RGB6_SEL() (pst_bitD0RGB6_RGB7() -> D0RGB6_SEL)
#define vSetD0RGB6_RGB7_D0RGB6_SEL(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB6_SEL=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB6_PU() (pst_bitD0RGB6_RGB7() -> D0RGB6_PU)
#define vSetD0RGB6_RGB7_D0RGB6_PU(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB6_PU=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB6_PD() (pst_bitD0RGB6_RGB7() -> D0RGB6_PD)
#define vSetD0RGB6_RGB7_D0RGB6_PD(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB6_PD=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB6_SMT() (pst_bitD0RGB6_RGB7() -> D0RGB6_SMT)
#define vSetD0RGB6_RGB7_D0RGB6_SMT(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB6_SMT=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB6_IMP() (pst_bitD0RGB6_RGB7() -> D0RGB6_IMP)
#define vSetD0RGB6_RGB7_D0RGB6_IMP(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB6_IMP=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB6_LATCHN() (pst_bitD0RGB6_RGB7() -> D0RGB6_LATCHN)
#define vSetD0RGB6_RGB7_D0RGB6_LATCHN(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB6_LATCHN=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB7_SEL() (pst_bitD0RGB6_RGB7() -> D0RGB7_SEL)
#define vSetD0RGB6_RGB7_D0RGB7_SEL(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB7_SEL=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB7_PU() (pst_bitD0RGB6_RGB7() -> D0RGB7_PU)
#define vSetD0RGB6_RGB7_D0RGB7_PU(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB7_PU=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB7_PD() (pst_bitD0RGB6_RGB7() -> D0RGB7_PD)
#define vSetD0RGB6_RGB7_D0RGB7_PD(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB7_PD=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB7_SMT() (pst_bitD0RGB6_RGB7() -> D0RGB7_SMT)
#define vSetD0RGB6_RGB7_D0RGB7_SMT(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB7_SMT=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB7_IMP() (pst_bitD0RGB6_RGB7() -> D0RGB7_IMP)
#define vSetD0RGB6_RGB7_D0RGB7_IMP(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB7_IMP=(ParValue))
#define biGetD0RGB6_RGB7_D0RGB7_LATCHN() (pst_bitD0RGB6_RGB7() -> D0RGB7_LATCHN)
#define vSetD0RGB6_RGB7_D0RGB7_LATCHN(ParValue)  (pst_bitD0RGB6_RGB7() -> D0RGB7_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB6_RGB7LL(ParValue) (pst_u8D0RGB6_RGB7() -> u8LL = (ParValue))
#define u8GetD0RGB6_RGB7LL() (pst_u8D0RGB6_RGB7() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB6_RGB7LH(ParValue) (pst_u8D0RGB6_RGB7() -> u8LH = (ParValue))
#define u8GetD0RGB6_RGB7LH() (pst_u8D0RGB6_RGB7() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB6_RGB7HL(ParValue) (pst_u8D0RGB6_RGB7() -> u8HL = (ParValue))
#define u8GetD0RGB6_RGB7HL() (pst_u8D0RGB6_RGB7() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB6_RGB7HH(ParValue) (pst_u8D0RGB6_RGB7() -> u8HH = (ParValue))
#define u8GetD0RGB6_RGB7HH() (pst_u8D0RGB6_RGB7() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB6_RGB7L(ParValue) (pst_u16D0RGB6_RGB7() -> u16L = (ParValue))
#define u16GetD0RGB6_RGB7L() (pst_u16D0RGB6_RGB7() -> u16L)
#define vSetD0RGB6_RGB7H(ParValue) (pst_u16D0RGB6_RGB7() -> u16H = (ParValue))
#define u16GetD0RGB6_RGB7H() (pst_u16D0RGB6_RGB7() -> u16H)
            
/* Word access */
#define vSetD0RGB6_RGB7(ParValue)  (*pu32D0RGB6_RGB7() = (ParValue))
#define u32GetD0RGB6_RGB7()  (*pu32D0RGB6_RGB7() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB8_RGB9                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020D8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB8_RGB9_REG__       0xC03020D8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB8_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB8_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB8_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB8_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB8_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB8_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB9_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB9_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB9_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB9_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB9_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB9_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB8_RGB9_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB8_RGB9_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB8_RGB9_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB8_RGB9_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB8_RGB9()     ((volatile D0RGB8_RGB9_bit_view_st *)\
(D0RGB8_RGB9_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB8_RGB9()     ((volatile D0RGB8_RGB9_byte_view_st *)\
(D0RGB8_RGB9_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB8_RGB9()     ((volatile D0RGB8_RGB9_halfword_view_st *)\
(D0RGB8_RGB9_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB8_RGB9()     ((volatile u32D0RGB8_RGB9_word_view *)\
(D0RGB8_RGB9_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB8_RGB9_D0RGB8_SEL() (pst_bitD0RGB8_RGB9() -> D0RGB8_SEL)
#define vSetD0RGB8_RGB9_D0RGB8_SEL(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB8_SEL=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB8_PU() (pst_bitD0RGB8_RGB9() -> D0RGB8_PU)
#define vSetD0RGB8_RGB9_D0RGB8_PU(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB8_PU=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB8_PD() (pst_bitD0RGB8_RGB9() -> D0RGB8_PD)
#define vSetD0RGB8_RGB9_D0RGB8_PD(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB8_PD=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB8_SMT() (pst_bitD0RGB8_RGB9() -> D0RGB8_SMT)
#define vSetD0RGB8_RGB9_D0RGB8_SMT(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB8_SMT=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB8_IMP() (pst_bitD0RGB8_RGB9() -> D0RGB8_IMP)
#define vSetD0RGB8_RGB9_D0RGB8_IMP(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB8_IMP=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB8_LATCHN() (pst_bitD0RGB8_RGB9() -> D0RGB8_LATCHN)
#define vSetD0RGB8_RGB9_D0RGB8_LATCHN(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB8_LATCHN=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB9_SEL() (pst_bitD0RGB8_RGB9() -> D0RGB9_SEL)
#define vSetD0RGB8_RGB9_D0RGB9_SEL(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB9_SEL=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB9_PU() (pst_bitD0RGB8_RGB9() -> D0RGB9_PU)
#define vSetD0RGB8_RGB9_D0RGB9_PU(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB9_PU=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB9_PD() (pst_bitD0RGB8_RGB9() -> D0RGB9_PD)
#define vSetD0RGB8_RGB9_D0RGB9_PD(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB9_PD=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB9_SMT() (pst_bitD0RGB8_RGB9() -> D0RGB9_SMT)
#define vSetD0RGB8_RGB9_D0RGB9_SMT(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB9_SMT=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB9_IMP() (pst_bitD0RGB8_RGB9() -> D0RGB9_IMP)
#define vSetD0RGB8_RGB9_D0RGB9_IMP(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB9_IMP=(ParValue))
#define biGetD0RGB8_RGB9_D0RGB9_LATCHN() (pst_bitD0RGB8_RGB9() -> D0RGB9_LATCHN)
#define vSetD0RGB8_RGB9_D0RGB9_LATCHN(ParValue)  (pst_bitD0RGB8_RGB9() -> D0RGB9_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB8_RGB9LL(ParValue) (pst_u8D0RGB8_RGB9() -> u8LL = (ParValue))
#define u8GetD0RGB8_RGB9LL() (pst_u8D0RGB8_RGB9() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB8_RGB9LH(ParValue) (pst_u8D0RGB8_RGB9() -> u8LH = (ParValue))
#define u8GetD0RGB8_RGB9LH() (pst_u8D0RGB8_RGB9() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB8_RGB9HL(ParValue) (pst_u8D0RGB8_RGB9() -> u8HL = (ParValue))
#define u8GetD0RGB8_RGB9HL() (pst_u8D0RGB8_RGB9() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB8_RGB9HH(ParValue) (pst_u8D0RGB8_RGB9() -> u8HH = (ParValue))
#define u8GetD0RGB8_RGB9HH() (pst_u8D0RGB8_RGB9() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB8_RGB9L(ParValue) (pst_u16D0RGB8_RGB9() -> u16L = (ParValue))
#define u16GetD0RGB8_RGB9L() (pst_u16D0RGB8_RGB9() -> u16L)
#define vSetD0RGB8_RGB9H(ParValue) (pst_u16D0RGB8_RGB9() -> u16H = (ParValue))
#define u16GetD0RGB8_RGB9H() (pst_u16D0RGB8_RGB9() -> u16H)
            
/* Word access */
#define vSetD0RGB8_RGB9(ParValue)  (*pu32D0RGB8_RGB9() = (ParValue))
#define u32GetD0RGB8_RGB9()  (*pu32D0RGB8_RGB9() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB10_RGB11                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020DC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB10_RGB11_REG__       0xC03020DCU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB10_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB10_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB10_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB10_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB10_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB10_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB11_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB11_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB11_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB11_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB11_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB11_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB10_RGB11_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB10_RGB11_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB10_RGB11_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB10_RGB11_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB10_RGB11()     ((volatile D0RGB10_RGB11_bit_view_st *)\
(D0RGB10_RGB11_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB10_RGB11()     ((volatile D0RGB10_RGB11_byte_view_st *)\
(D0RGB10_RGB11_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB10_RGB11()     ((volatile D0RGB10_RGB11_halfword_view_st *)\
(D0RGB10_RGB11_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB10_RGB11()     ((volatile u32D0RGB10_RGB11_word_view *)\
(D0RGB10_RGB11_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB10_RGB11_D0RGB10_SEL() (pst_bitD0RGB10_RGB11() -> D0RGB10_SEL)
#define vSetD0RGB10_RGB11_D0RGB10_SEL(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB10_SEL=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB10_PU() (pst_bitD0RGB10_RGB11() -> D0RGB10_PU)
#define vSetD0RGB10_RGB11_D0RGB10_PU(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB10_PU=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB10_PD() (pst_bitD0RGB10_RGB11() -> D0RGB10_PD)
#define vSetD0RGB10_RGB11_D0RGB10_PD(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB10_PD=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB10_SMT() (pst_bitD0RGB10_RGB11() -> D0RGB10_SMT)
#define vSetD0RGB10_RGB11_D0RGB10_SMT(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB10_SMT=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB10_IMP() (pst_bitD0RGB10_RGB11() -> D0RGB10_IMP)
#define vSetD0RGB10_RGB11_D0RGB10_IMP(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB10_IMP=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB10_LATCHN() (pst_bitD0RGB10_RGB11() -> D0RGB10_LATCHN)
#define vSetD0RGB10_RGB11_D0RGB10_LATCHN(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB10_LATCHN=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB11_SEL() (pst_bitD0RGB10_RGB11() -> D0RGB11_SEL)
#define vSetD0RGB10_RGB11_D0RGB11_SEL(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB11_SEL=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB11_PU() (pst_bitD0RGB10_RGB11() -> D0RGB11_PU)
#define vSetD0RGB10_RGB11_D0RGB11_PU(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB11_PU=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB11_PD() (pst_bitD0RGB10_RGB11() -> D0RGB11_PD)
#define vSetD0RGB10_RGB11_D0RGB11_PD(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB11_PD=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB11_SMT() (pst_bitD0RGB10_RGB11() -> D0RGB11_SMT)
#define vSetD0RGB10_RGB11_D0RGB11_SMT(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB11_SMT=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB11_IMP() (pst_bitD0RGB10_RGB11() -> D0RGB11_IMP)
#define vSetD0RGB10_RGB11_D0RGB11_IMP(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB11_IMP=(ParValue))
#define biGetD0RGB10_RGB11_D0RGB11_LATCHN() (pst_bitD0RGB10_RGB11() -> D0RGB11_LATCHN)
#define vSetD0RGB10_RGB11_D0RGB11_LATCHN(ParValue)  (pst_bitD0RGB10_RGB11() -> D0RGB11_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB10_RGB11LL(ParValue) (pst_u8D0RGB10_RGB11() -> u8LL = (ParValue))
#define u8GetD0RGB10_RGB11LL() (pst_u8D0RGB10_RGB11() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB10_RGB11LH(ParValue) (pst_u8D0RGB10_RGB11() -> u8LH = (ParValue))
#define u8GetD0RGB10_RGB11LH() (pst_u8D0RGB10_RGB11() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB10_RGB11HL(ParValue) (pst_u8D0RGB10_RGB11() -> u8HL = (ParValue))
#define u8GetD0RGB10_RGB11HL() (pst_u8D0RGB10_RGB11() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB10_RGB11HH(ParValue) (pst_u8D0RGB10_RGB11() -> u8HH = (ParValue))
#define u8GetD0RGB10_RGB11HH() (pst_u8D0RGB10_RGB11() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB10_RGB11L(ParValue) (pst_u16D0RGB10_RGB11() -> u16L = (ParValue))
#define u16GetD0RGB10_RGB11L() (pst_u16D0RGB10_RGB11() -> u16L)
#define vSetD0RGB10_RGB11H(ParValue) (pst_u16D0RGB10_RGB11() -> u16H = (ParValue))
#define u16GetD0RGB10_RGB11H() (pst_u16D0RGB10_RGB11() -> u16H)
            
/* Word access */
#define vSetD0RGB10_RGB11(ParValue)  (*pu32D0RGB10_RGB11() = (ParValue))
#define u32GetD0RGB10_RGB11()  (*pu32D0RGB10_RGB11() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB12_RGB13                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020E0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB12_RGB13_REG__       0xC03020E0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB12_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB12_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB12_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB12_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB12_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB12_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB13_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB13_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB13_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB13_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB13_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB13_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB12_RGB13_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB12_RGB13_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB12_RGB13_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB12_RGB13_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB12_RGB13()     ((volatile D0RGB12_RGB13_bit_view_st *)\
(D0RGB12_RGB13_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB12_RGB13()     ((volatile D0RGB12_RGB13_byte_view_st *)\
(D0RGB12_RGB13_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB12_RGB13()     ((volatile D0RGB12_RGB13_halfword_view_st *)\
(D0RGB12_RGB13_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB12_RGB13()     ((volatile u32D0RGB12_RGB13_word_view *)\
(D0RGB12_RGB13_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB12_RGB13_D0RGB12_SEL() (pst_bitD0RGB12_RGB13() -> D0RGB12_SEL)
#define vSetD0RGB12_RGB13_D0RGB12_SEL(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB12_SEL=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB12_PU() (pst_bitD0RGB12_RGB13() -> D0RGB12_PU)
#define vSetD0RGB12_RGB13_D0RGB12_PU(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB12_PU=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB12_PD() (pst_bitD0RGB12_RGB13() -> D0RGB12_PD)
#define vSetD0RGB12_RGB13_D0RGB12_PD(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB12_PD=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB12_SMT() (pst_bitD0RGB12_RGB13() -> D0RGB12_SMT)
#define vSetD0RGB12_RGB13_D0RGB12_SMT(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB12_SMT=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB12_IMP() (pst_bitD0RGB12_RGB13() -> D0RGB12_IMP)
#define vSetD0RGB12_RGB13_D0RGB12_IMP(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB12_IMP=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB12_LATCHN() (pst_bitD0RGB12_RGB13() -> D0RGB12_LATCHN)
#define vSetD0RGB12_RGB13_D0RGB12_LATCHN(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB12_LATCHN=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB13_SEL() (pst_bitD0RGB12_RGB13() -> D0RGB13_SEL)
#define vSetD0RGB12_RGB13_D0RGB13_SEL(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB13_SEL=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB13_PU() (pst_bitD0RGB12_RGB13() -> D0RGB13_PU)
#define vSetD0RGB12_RGB13_D0RGB13_PU(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB13_PU=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB13_PD() (pst_bitD0RGB12_RGB13() -> D0RGB13_PD)
#define vSetD0RGB12_RGB13_D0RGB13_PD(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB13_PD=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB13_SMT() (pst_bitD0RGB12_RGB13() -> D0RGB13_SMT)
#define vSetD0RGB12_RGB13_D0RGB13_SMT(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB13_SMT=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB13_IMP() (pst_bitD0RGB12_RGB13() -> D0RGB13_IMP)
#define vSetD0RGB12_RGB13_D0RGB13_IMP(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB13_IMP=(ParValue))
#define biGetD0RGB12_RGB13_D0RGB13_LATCHN() (pst_bitD0RGB12_RGB13() -> D0RGB13_LATCHN)
#define vSetD0RGB12_RGB13_D0RGB13_LATCHN(ParValue)  (pst_bitD0RGB12_RGB13() -> D0RGB13_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB12_RGB13LL(ParValue) (pst_u8D0RGB12_RGB13() -> u8LL = (ParValue))
#define u8GetD0RGB12_RGB13LL() (pst_u8D0RGB12_RGB13() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB12_RGB13LH(ParValue) (pst_u8D0RGB12_RGB13() -> u8LH = (ParValue))
#define u8GetD0RGB12_RGB13LH() (pst_u8D0RGB12_RGB13() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB12_RGB13HL(ParValue) (pst_u8D0RGB12_RGB13() -> u8HL = (ParValue))
#define u8GetD0RGB12_RGB13HL() (pst_u8D0RGB12_RGB13() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB12_RGB13HH(ParValue) (pst_u8D0RGB12_RGB13() -> u8HH = (ParValue))
#define u8GetD0RGB12_RGB13HH() (pst_u8D0RGB12_RGB13() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB12_RGB13L(ParValue) (pst_u16D0RGB12_RGB13() -> u16L = (ParValue))
#define u16GetD0RGB12_RGB13L() (pst_u16D0RGB12_RGB13() -> u16L)
#define vSetD0RGB12_RGB13H(ParValue) (pst_u16D0RGB12_RGB13() -> u16H = (ParValue))
#define u16GetD0RGB12_RGB13H() (pst_u16D0RGB12_RGB13() -> u16H)
            
/* Word access */
#define vSetD0RGB12_RGB13(ParValue)  (*pu32D0RGB12_RGB13() = (ParValue))
#define u32GetD0RGB12_RGB13()  (*pu32D0RGB12_RGB13() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB14_RGB15                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020E4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB14_RGB15_REG__       0xC03020E4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB14_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB14_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB14_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB14_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB14_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB14_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB15_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB15_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB15_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB15_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB15_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB15_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB14_RGB15_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB14_RGB15_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB14_RGB15_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB14_RGB15_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB14_RGB15()     ((volatile D0RGB14_RGB15_bit_view_st *)\
(D0RGB14_RGB15_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB14_RGB15()     ((volatile D0RGB14_RGB15_byte_view_st *)\
(D0RGB14_RGB15_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB14_RGB15()     ((volatile D0RGB14_RGB15_halfword_view_st *)\
(D0RGB14_RGB15_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB14_RGB15()     ((volatile u32D0RGB14_RGB15_word_view *)\
(D0RGB14_RGB15_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB14_RGB15_D0RGB14_SEL() (pst_bitD0RGB14_RGB15() -> D0RGB14_SEL)
#define vSetD0RGB14_RGB15_D0RGB14_SEL(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB14_SEL=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB14_PU() (pst_bitD0RGB14_RGB15() -> D0RGB14_PU)
#define vSetD0RGB14_RGB15_D0RGB14_PU(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB14_PU=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB14_PD() (pst_bitD0RGB14_RGB15() -> D0RGB14_PD)
#define vSetD0RGB14_RGB15_D0RGB14_PD(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB14_PD=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB14_SMT() (pst_bitD0RGB14_RGB15() -> D0RGB14_SMT)
#define vSetD0RGB14_RGB15_D0RGB14_SMT(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB14_SMT=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB14_IMP() (pst_bitD0RGB14_RGB15() -> D0RGB14_IMP)
#define vSetD0RGB14_RGB15_D0RGB14_IMP(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB14_IMP=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB14_LATCHN() (pst_bitD0RGB14_RGB15() -> D0RGB14_LATCHN)
#define vSetD0RGB14_RGB15_D0RGB14_LATCHN(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB14_LATCHN=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB15_SEL() (pst_bitD0RGB14_RGB15() -> D0RGB15_SEL)
#define vSetD0RGB14_RGB15_D0RGB15_SEL(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB15_SEL=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB15_PU() (pst_bitD0RGB14_RGB15() -> D0RGB15_PU)
#define vSetD0RGB14_RGB15_D0RGB15_PU(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB15_PU=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB15_PD() (pst_bitD0RGB14_RGB15() -> D0RGB15_PD)
#define vSetD0RGB14_RGB15_D0RGB15_PD(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB15_PD=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB15_SMT() (pst_bitD0RGB14_RGB15() -> D0RGB15_SMT)
#define vSetD0RGB14_RGB15_D0RGB15_SMT(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB15_SMT=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB15_IMP() (pst_bitD0RGB14_RGB15() -> D0RGB15_IMP)
#define vSetD0RGB14_RGB15_D0RGB15_IMP(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB15_IMP=(ParValue))
#define biGetD0RGB14_RGB15_D0RGB15_LATCHN() (pst_bitD0RGB14_RGB15() -> D0RGB15_LATCHN)
#define vSetD0RGB14_RGB15_D0RGB15_LATCHN(ParValue)  (pst_bitD0RGB14_RGB15() -> D0RGB15_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB14_RGB15LL(ParValue) (pst_u8D0RGB14_RGB15() -> u8LL = (ParValue))
#define u8GetD0RGB14_RGB15LL() (pst_u8D0RGB14_RGB15() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB14_RGB15LH(ParValue) (pst_u8D0RGB14_RGB15() -> u8LH = (ParValue))
#define u8GetD0RGB14_RGB15LH() (pst_u8D0RGB14_RGB15() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB14_RGB15HL(ParValue) (pst_u8D0RGB14_RGB15() -> u8HL = (ParValue))
#define u8GetD0RGB14_RGB15HL() (pst_u8D0RGB14_RGB15() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB14_RGB15HH(ParValue) (pst_u8D0RGB14_RGB15() -> u8HH = (ParValue))
#define u8GetD0RGB14_RGB15HH() (pst_u8D0RGB14_RGB15() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB14_RGB15L(ParValue) (pst_u16D0RGB14_RGB15() -> u16L = (ParValue))
#define u16GetD0RGB14_RGB15L() (pst_u16D0RGB14_RGB15() -> u16L)
#define vSetD0RGB14_RGB15H(ParValue) (pst_u16D0RGB14_RGB15() -> u16H = (ParValue))
#define u16GetD0RGB14_RGB15H() (pst_u16D0RGB14_RGB15() -> u16H)
            
/* Word access */
#define vSetD0RGB14_RGB15(ParValue)  (*pu32D0RGB14_RGB15() = (ParValue))
#define u32GetD0RGB14_RGB15()  (*pu32D0RGB14_RGB15() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB16_RGB17                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020E8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB16_RGB17_REG__       0xC03020E8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB16_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB16_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB16_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB16_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB16_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB16_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB17_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB17_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB17_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB17_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB17_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB17_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB16_RGB17_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB16_RGB17_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB16_RGB17_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB16_RGB17_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB16_RGB17()     ((volatile D0RGB16_RGB17_bit_view_st *)\
(D0RGB16_RGB17_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB16_RGB17()     ((volatile D0RGB16_RGB17_byte_view_st *)\
(D0RGB16_RGB17_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB16_RGB17()     ((volatile D0RGB16_RGB17_halfword_view_st *)\
(D0RGB16_RGB17_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB16_RGB17()     ((volatile u32D0RGB16_RGB17_word_view *)\
(D0RGB16_RGB17_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB16_RGB17_D0RGB16_SEL() (pst_bitD0RGB16_RGB17() -> D0RGB16_SEL)
#define vSetD0RGB16_RGB17_D0RGB16_SEL(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB16_SEL=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB16_PU() (pst_bitD0RGB16_RGB17() -> D0RGB16_PU)
#define vSetD0RGB16_RGB17_D0RGB16_PU(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB16_PU=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB16_PD() (pst_bitD0RGB16_RGB17() -> D0RGB16_PD)
#define vSetD0RGB16_RGB17_D0RGB16_PD(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB16_PD=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB16_SMT() (pst_bitD0RGB16_RGB17() -> D0RGB16_SMT)
#define vSetD0RGB16_RGB17_D0RGB16_SMT(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB16_SMT=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB16_IMP() (pst_bitD0RGB16_RGB17() -> D0RGB16_IMP)
#define vSetD0RGB16_RGB17_D0RGB16_IMP(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB16_IMP=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB16_LATCHN() (pst_bitD0RGB16_RGB17() -> D0RGB16_LATCHN)
#define vSetD0RGB16_RGB17_D0RGB16_LATCHN(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB16_LATCHN=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB17_SEL() (pst_bitD0RGB16_RGB17() -> D0RGB17_SEL)
#define vSetD0RGB16_RGB17_D0RGB17_SEL(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB17_SEL=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB17_PU() (pst_bitD0RGB16_RGB17() -> D0RGB17_PU)
#define vSetD0RGB16_RGB17_D0RGB17_PU(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB17_PU=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB17_PD() (pst_bitD0RGB16_RGB17() -> D0RGB17_PD)
#define vSetD0RGB16_RGB17_D0RGB17_PD(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB17_PD=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB17_SMT() (pst_bitD0RGB16_RGB17() -> D0RGB17_SMT)
#define vSetD0RGB16_RGB17_D0RGB17_SMT(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB17_SMT=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB17_IMP() (pst_bitD0RGB16_RGB17() -> D0RGB17_IMP)
#define vSetD0RGB16_RGB17_D0RGB17_IMP(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB17_IMP=(ParValue))
#define biGetD0RGB16_RGB17_D0RGB17_LATCHN() (pst_bitD0RGB16_RGB17() -> D0RGB17_LATCHN)
#define vSetD0RGB16_RGB17_D0RGB17_LATCHN(ParValue)  (pst_bitD0RGB16_RGB17() -> D0RGB17_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB16_RGB17LL(ParValue) (pst_u8D0RGB16_RGB17() -> u8LL = (ParValue))
#define u8GetD0RGB16_RGB17LL() (pst_u8D0RGB16_RGB17() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB16_RGB17LH(ParValue) (pst_u8D0RGB16_RGB17() -> u8LH = (ParValue))
#define u8GetD0RGB16_RGB17LH() (pst_u8D0RGB16_RGB17() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB16_RGB17HL(ParValue) (pst_u8D0RGB16_RGB17() -> u8HL = (ParValue))
#define u8GetD0RGB16_RGB17HL() (pst_u8D0RGB16_RGB17() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB16_RGB17HH(ParValue) (pst_u8D0RGB16_RGB17() -> u8HH = (ParValue))
#define u8GetD0RGB16_RGB17HH() (pst_u8D0RGB16_RGB17() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB16_RGB17L(ParValue) (pst_u16D0RGB16_RGB17() -> u16L = (ParValue))
#define u16GetD0RGB16_RGB17L() (pst_u16D0RGB16_RGB17() -> u16L)
#define vSetD0RGB16_RGB17H(ParValue) (pst_u16D0RGB16_RGB17() -> u16H = (ParValue))
#define u16GetD0RGB16_RGB17H() (pst_u16D0RGB16_RGB17() -> u16H)
            
/* Word access */
#define vSetD0RGB16_RGB17(ParValue)  (*pu32D0RGB16_RGB17() = (ParValue))
#define u32GetD0RGB16_RGB17()  (*pu32D0RGB16_RGB17() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB18_RGB19                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020EC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB18_RGB19_REG__       0xC03020ECU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB18_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB18_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB18_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB18_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB18_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB18_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB19_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB19_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB19_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB19_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB19_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB19_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB18_RGB19_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB18_RGB19_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB18_RGB19_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB18_RGB19_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB18_RGB19()     ((volatile D0RGB18_RGB19_bit_view_st *)\
(D0RGB18_RGB19_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB18_RGB19()     ((volatile D0RGB18_RGB19_byte_view_st *)\
(D0RGB18_RGB19_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB18_RGB19()     ((volatile D0RGB18_RGB19_halfword_view_st *)\
(D0RGB18_RGB19_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB18_RGB19()     ((volatile u32D0RGB18_RGB19_word_view *)\
(D0RGB18_RGB19_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB18_RGB19_D0RGB18_SEL() (pst_bitD0RGB18_RGB19() -> D0RGB18_SEL)
#define vSetD0RGB18_RGB19_D0RGB18_SEL(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB18_SEL=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB18_PU() (pst_bitD0RGB18_RGB19() -> D0RGB18_PU)
#define vSetD0RGB18_RGB19_D0RGB18_PU(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB18_PU=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB18_PD() (pst_bitD0RGB18_RGB19() -> D0RGB18_PD)
#define vSetD0RGB18_RGB19_D0RGB18_PD(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB18_PD=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB18_SMT() (pst_bitD0RGB18_RGB19() -> D0RGB18_SMT)
#define vSetD0RGB18_RGB19_D0RGB18_SMT(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB18_SMT=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB18_IMP() (pst_bitD0RGB18_RGB19() -> D0RGB18_IMP)
#define vSetD0RGB18_RGB19_D0RGB18_IMP(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB18_IMP=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB18_LATCHN() (pst_bitD0RGB18_RGB19() -> D0RGB18_LATCHN)
#define vSetD0RGB18_RGB19_D0RGB18_LATCHN(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB18_LATCHN=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB19_SEL() (pst_bitD0RGB18_RGB19() -> D0RGB19_SEL)
#define vSetD0RGB18_RGB19_D0RGB19_SEL(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB19_SEL=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB19_PU() (pst_bitD0RGB18_RGB19() -> D0RGB19_PU)
#define vSetD0RGB18_RGB19_D0RGB19_PU(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB19_PU=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB19_PD() (pst_bitD0RGB18_RGB19() -> D0RGB19_PD)
#define vSetD0RGB18_RGB19_D0RGB19_PD(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB19_PD=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB19_SMT() (pst_bitD0RGB18_RGB19() -> D0RGB19_SMT)
#define vSetD0RGB18_RGB19_D0RGB19_SMT(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB19_SMT=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB19_IMP() (pst_bitD0RGB18_RGB19() -> D0RGB19_IMP)
#define vSetD0RGB18_RGB19_D0RGB19_IMP(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB19_IMP=(ParValue))
#define biGetD0RGB18_RGB19_D0RGB19_LATCHN() (pst_bitD0RGB18_RGB19() -> D0RGB19_LATCHN)
#define vSetD0RGB18_RGB19_D0RGB19_LATCHN(ParValue)  (pst_bitD0RGB18_RGB19() -> D0RGB19_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB18_RGB19LL(ParValue) (pst_u8D0RGB18_RGB19() -> u8LL = (ParValue))
#define u8GetD0RGB18_RGB19LL() (pst_u8D0RGB18_RGB19() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB18_RGB19LH(ParValue) (pst_u8D0RGB18_RGB19() -> u8LH = (ParValue))
#define u8GetD0RGB18_RGB19LH() (pst_u8D0RGB18_RGB19() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB18_RGB19HL(ParValue) (pst_u8D0RGB18_RGB19() -> u8HL = (ParValue))
#define u8GetD0RGB18_RGB19HL() (pst_u8D0RGB18_RGB19() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB18_RGB19HH(ParValue) (pst_u8D0RGB18_RGB19() -> u8HH = (ParValue))
#define u8GetD0RGB18_RGB19HH() (pst_u8D0RGB18_RGB19() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB18_RGB19L(ParValue) (pst_u16D0RGB18_RGB19() -> u16L = (ParValue))
#define u16GetD0RGB18_RGB19L() (pst_u16D0RGB18_RGB19() -> u16L)
#define vSetD0RGB18_RGB19H(ParValue) (pst_u16D0RGB18_RGB19() -> u16H = (ParValue))
#define u16GetD0RGB18_RGB19H() (pst_u16D0RGB18_RGB19() -> u16H)
            
/* Word access */
#define vSetD0RGB18_RGB19(ParValue)  (*pu32D0RGB18_RGB19() = (ParValue))
#define u32GetD0RGB18_RGB19()  (*pu32D0RGB18_RGB19() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB20_RGB21                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020F0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB20_RGB21_REG__       0xC03020F0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB20_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB20_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB20_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB20_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB20_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB20_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB21_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB21_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB21_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB21_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB21_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB21_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB20_RGB21_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB20_RGB21_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB20_RGB21_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB20_RGB21_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB20_RGB21()     ((volatile D0RGB20_RGB21_bit_view_st *)\
(D0RGB20_RGB21_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB20_RGB21()     ((volatile D0RGB20_RGB21_byte_view_st *)\
(D0RGB20_RGB21_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB20_RGB21()     ((volatile D0RGB20_RGB21_halfword_view_st *)\
(D0RGB20_RGB21_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB20_RGB21()     ((volatile u32D0RGB20_RGB21_word_view *)\
(D0RGB20_RGB21_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB20_RGB21_D0RGB20_SEL() (pst_bitD0RGB20_RGB21() -> D0RGB20_SEL)
#define vSetD0RGB20_RGB21_D0RGB20_SEL(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB20_SEL=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB20_PU() (pst_bitD0RGB20_RGB21() -> D0RGB20_PU)
#define vSetD0RGB20_RGB21_D0RGB20_PU(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB20_PU=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB20_PD() (pst_bitD0RGB20_RGB21() -> D0RGB20_PD)
#define vSetD0RGB20_RGB21_D0RGB20_PD(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB20_PD=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB20_SMT() (pst_bitD0RGB20_RGB21() -> D0RGB20_SMT)
#define vSetD0RGB20_RGB21_D0RGB20_SMT(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB20_SMT=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB20_IMP() (pst_bitD0RGB20_RGB21() -> D0RGB20_IMP)
#define vSetD0RGB20_RGB21_D0RGB20_IMP(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB20_IMP=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB20_LATCHN() (pst_bitD0RGB20_RGB21() -> D0RGB20_LATCHN)
#define vSetD0RGB20_RGB21_D0RGB20_LATCHN(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB20_LATCHN=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB21_SEL() (pst_bitD0RGB20_RGB21() -> D0RGB21_SEL)
#define vSetD0RGB20_RGB21_D0RGB21_SEL(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB21_SEL=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB21_PU() (pst_bitD0RGB20_RGB21() -> D0RGB21_PU)
#define vSetD0RGB20_RGB21_D0RGB21_PU(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB21_PU=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB21_PD() (pst_bitD0RGB20_RGB21() -> D0RGB21_PD)
#define vSetD0RGB20_RGB21_D0RGB21_PD(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB21_PD=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB21_SMT() (pst_bitD0RGB20_RGB21() -> D0RGB21_SMT)
#define vSetD0RGB20_RGB21_D0RGB21_SMT(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB21_SMT=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB21_IMP() (pst_bitD0RGB20_RGB21() -> D0RGB21_IMP)
#define vSetD0RGB20_RGB21_D0RGB21_IMP(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB21_IMP=(ParValue))
#define biGetD0RGB20_RGB21_D0RGB21_LATCHN() (pst_bitD0RGB20_RGB21() -> D0RGB21_LATCHN)
#define vSetD0RGB20_RGB21_D0RGB21_LATCHN(ParValue)  (pst_bitD0RGB20_RGB21() -> D0RGB21_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB20_RGB21LL(ParValue) (pst_u8D0RGB20_RGB21() -> u8LL = (ParValue))
#define u8GetD0RGB20_RGB21LL() (pst_u8D0RGB20_RGB21() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB20_RGB21LH(ParValue) (pst_u8D0RGB20_RGB21() -> u8LH = (ParValue))
#define u8GetD0RGB20_RGB21LH() (pst_u8D0RGB20_RGB21() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB20_RGB21HL(ParValue) (pst_u8D0RGB20_RGB21() -> u8HL = (ParValue))
#define u8GetD0RGB20_RGB21HL() (pst_u8D0RGB20_RGB21() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB20_RGB21HH(ParValue) (pst_u8D0RGB20_RGB21() -> u8HH = (ParValue))
#define u8GetD0RGB20_RGB21HH() (pst_u8D0RGB20_RGB21() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB20_RGB21L(ParValue) (pst_u16D0RGB20_RGB21() -> u16L = (ParValue))
#define u16GetD0RGB20_RGB21L() (pst_u16D0RGB20_RGB21() -> u16L)
#define vSetD0RGB20_RGB21H(ParValue) (pst_u16D0RGB20_RGB21() -> u16H = (ParValue))
#define u16GetD0RGB20_RGB21H() (pst_u16D0RGB20_RGB21() -> u16H)
            
/* Word access */
#define vSetD0RGB20_RGB21(ParValue)  (*pu32D0RGB20_RGB21() = (ParValue))
#define u32GetD0RGB20_RGB21()  (*pu32D0RGB20_RGB21() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D0RGB22_RGB23                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03020F4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D0RGB22_RGB23_REG__       0xC03020F4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0RGB22_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D0RGB22_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D0RGB22_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D0RGB22_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D0RGB22_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D0RGB22_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D0RGB23_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D0RGB23_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D0RGB23_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D0RGB23_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D0RGB23_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D0RGB23_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D0RGB22_RGB23_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D0RGB22_RGB23_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D0RGB22_RGB23_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D0RGB22_RGB23_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD0RGB22_RGB23()     ((volatile D0RGB22_RGB23_bit_view_st *)\
(D0RGB22_RGB23_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D0RGB22_RGB23()     ((volatile D0RGB22_RGB23_byte_view_st *)\
(D0RGB22_RGB23_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D0RGB22_RGB23()     ((volatile D0RGB22_RGB23_halfword_view_st *)\
(D0RGB22_RGB23_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D0RGB22_RGB23()     ((volatile u32D0RGB22_RGB23_word_view *)\
(D0RGB22_RGB23_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD0RGB22_RGB23_D0RGB22_SEL() (pst_bitD0RGB22_RGB23() -> D0RGB22_SEL)
#define vSetD0RGB22_RGB23_D0RGB22_SEL(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB22_SEL=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB22_PU() (pst_bitD0RGB22_RGB23() -> D0RGB22_PU)
#define vSetD0RGB22_RGB23_D0RGB22_PU(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB22_PU=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB22_PD() (pst_bitD0RGB22_RGB23() -> D0RGB22_PD)
#define vSetD0RGB22_RGB23_D0RGB22_PD(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB22_PD=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB22_SMT() (pst_bitD0RGB22_RGB23() -> D0RGB22_SMT)
#define vSetD0RGB22_RGB23_D0RGB22_SMT(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB22_SMT=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB22_IMP() (pst_bitD0RGB22_RGB23() -> D0RGB22_IMP)
#define vSetD0RGB22_RGB23_D0RGB22_IMP(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB22_IMP=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB22_LATCHN() (pst_bitD0RGB22_RGB23() -> D0RGB22_LATCHN)
#define vSetD0RGB22_RGB23_D0RGB22_LATCHN(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB22_LATCHN=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB23_SEL() (pst_bitD0RGB22_RGB23() -> D0RGB23_SEL)
#define vSetD0RGB22_RGB23_D0RGB23_SEL(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB23_SEL=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB23_PU() (pst_bitD0RGB22_RGB23() -> D0RGB23_PU)
#define vSetD0RGB22_RGB23_D0RGB23_PU(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB23_PU=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB23_PD() (pst_bitD0RGB22_RGB23() -> D0RGB23_PD)
#define vSetD0RGB22_RGB23_D0RGB23_PD(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB23_PD=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB23_SMT() (pst_bitD0RGB22_RGB23() -> D0RGB23_SMT)
#define vSetD0RGB22_RGB23_D0RGB23_SMT(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB23_SMT=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB23_IMP() (pst_bitD0RGB22_RGB23() -> D0RGB23_IMP)
#define vSetD0RGB22_RGB23_D0RGB23_IMP(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB23_IMP=(ParValue))
#define biGetD0RGB22_RGB23_D0RGB23_LATCHN() (pst_bitD0RGB22_RGB23() -> D0RGB23_LATCHN)
#define vSetD0RGB22_RGB23_D0RGB23_LATCHN(ParValue)  (pst_bitD0RGB22_RGB23() -> D0RGB23_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD0RGB22_RGB23LL(ParValue) (pst_u8D0RGB22_RGB23() -> u8LL = (ParValue))
#define u8GetD0RGB22_RGB23LL() (pst_u8D0RGB22_RGB23() -> u8LL)
/* LH-struct byte access */
#define vSetD0RGB22_RGB23LH(ParValue) (pst_u8D0RGB22_RGB23() -> u8LH = (ParValue))
#define u8GetD0RGB22_RGB23LH() (pst_u8D0RGB22_RGB23() -> u8LH)
/* HL-struct byte access */
#define vSetD0RGB22_RGB23HL(ParValue) (pst_u8D0RGB22_RGB23() -> u8HL = (ParValue))
#define u8GetD0RGB22_RGB23HL() (pst_u8D0RGB22_RGB23() -> u8HL)
/* HH-struct byte access */
#define vSetD0RGB22_RGB23HH(ParValue) (pst_u8D0RGB22_RGB23() -> u8HH = (ParValue))
#define u8GetD0RGB22_RGB23HH() (pst_u8D0RGB22_RGB23() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD0RGB22_RGB23L(ParValue) (pst_u16D0RGB22_RGB23() -> u16L = (ParValue))
#define u16GetD0RGB22_RGB23L() (pst_u16D0RGB22_RGB23() -> u16L)
#define vSetD0RGB22_RGB23H(ParValue) (pst_u16D0RGB22_RGB23() -> u16H = (ParValue))
#define u16GetD0RGB22_RGB23H() (pst_u16D0RGB22_RGB23() -> u16H)
            
/* Word access */
#define vSetD0RGB22_RGB23(ParValue)  (*pu32D0RGB22_RGB23() = (ParValue))
#define u32GetD0RGB22_RGB23()  (*pu32D0RGB22_RGB23() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DOTCLKIN                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302110                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DOTCLKIN_REG__       0xC0302110U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   DOTCLKIN_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint16_t   	:5; 	 /* 3..7  bit(s) R */
  uint16_t   DOTCLKIN_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   DOTCLKIN_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   DOTCLKIN_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint16_t   DOTCLKIN_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint16_t   DOTCLKIN_LATCHN	:1; 	 /* 13..13  bit(s) R/W */ 
  uint16_t   	:2; 	 /* 14..31  bit(s) R */                    
} DOTCLKIN_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} DOTCLKIN_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16DOTCLKIN_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDOTCLKIN()     ((volatile DOTCLKIN_bit_view_st *)\
(DOTCLKIN_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DOTCLKIN()     ((volatile DOTCLKIN_byte_view_st *)\
(DOTCLKIN_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16DOTCLKIN()     ((volatile u16DOTCLKIN_halfword_view *)\
(DOTCLKIN_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDOTCLKIN_DOTCLKIN_SEL() (pst_bitDOTCLKIN() -> DOTCLKIN_SEL)
#define vSetDOTCLKIN_DOTCLKIN_SEL(ParValue)  (pst_bitDOTCLKIN() -> DOTCLKIN_SEL=(ParValue))
#define biGetDOTCLKIN_DOTCLKIN_PU() (pst_bitDOTCLKIN() -> DOTCLKIN_PU)
#define vSetDOTCLKIN_DOTCLKIN_PU(ParValue)  (pst_bitDOTCLKIN() -> DOTCLKIN_PU=(ParValue))
#define biGetDOTCLKIN_DOTCLKIN_PD() (pst_bitDOTCLKIN() -> DOTCLKIN_PD)
#define vSetDOTCLKIN_DOTCLKIN_PD(ParValue)  (pst_bitDOTCLKIN() -> DOTCLKIN_PD=(ParValue))
#define biGetDOTCLKIN_DOTCLKIN_SMT() (pst_bitDOTCLKIN() -> DOTCLKIN_SMT)
#define vSetDOTCLKIN_DOTCLKIN_SMT(ParValue)  (pst_bitDOTCLKIN() -> DOTCLKIN_SMT=(ParValue))
#define biGetDOTCLKIN_DOTCLKIN_IMP() (pst_bitDOTCLKIN() -> DOTCLKIN_IMP)
#define vSetDOTCLKIN_DOTCLKIN_IMP(ParValue)  (pst_bitDOTCLKIN() -> DOTCLKIN_IMP=(ParValue))
#define biGetDOTCLKIN_DOTCLKIN_LATCHN() (pst_bitDOTCLKIN() -> DOTCLKIN_LATCHN)
#define vSetDOTCLKIN_DOTCLKIN_LATCHN(ParValue)  (pst_bitDOTCLKIN() -> DOTCLKIN_LATCHN=(ParValue))
            
/* L-struct byte access */
#define vSetDOTCLKINL(ParValue) (pst_u8DOTCLKIN() -> u8L = (ParValue))
#define u8GetDOTCLKINL() (pst_u8DOTCLKIN() -> u8L)
/* H-struct byte access */
#define vSetDOTCLKINH(ParValue) (pst_u8DOTCLKIN() -> u8H = (ParValue))
#define u8GetDOTCLKINH() (pst_u8DOTCLKIN() -> u8H)
            
/* Half-word access */ 
#define vSetDOTCLKIN(ParValue) (*pu16DOTCLKIN()  = (ParValue))
#define u16GetDOTCLKIN() (*pu16DOTCLKIN() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNLGPP0_GPP1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302114                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNLGPP0_GPP1_REG__       0xC0302114U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PNLGPP0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   PNLGPP0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   PNLGPP0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   PNLGPP0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   PNLGPP0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   PNLGPP0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   PNLGPP1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   PNLGPP1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   PNLGPP1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   PNLGPP1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   PNLGPP1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   PNLGPP1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} PNLGPP0_GPP1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNLGPP0_GPP1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNLGPP0_GPP1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNLGPP0_GPP1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNLGPP0_GPP1()     ((volatile PNLGPP0_GPP1_bit_view_st *)\
(PNLGPP0_GPP1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNLGPP0_GPP1()     ((volatile PNLGPP0_GPP1_byte_view_st *)\
(PNLGPP0_GPP1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNLGPP0_GPP1()     ((volatile PNLGPP0_GPP1_halfword_view_st *)\
(PNLGPP0_GPP1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNLGPP0_GPP1()     ((volatile u32PNLGPP0_GPP1_word_view *)\
(PNLGPP0_GPP1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNLGPP0_GPP1_PNLGPP0_SEL() (pst_bitPNLGPP0_GPP1() -> PNLGPP0_SEL)
#define vSetPNLGPP0_GPP1_PNLGPP0_SEL(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP0_SEL=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP0_PU() (pst_bitPNLGPP0_GPP1() -> PNLGPP0_PU)
#define vSetPNLGPP0_GPP1_PNLGPP0_PU(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP0_PU=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP0_PD() (pst_bitPNLGPP0_GPP1() -> PNLGPP0_PD)
#define vSetPNLGPP0_GPP1_PNLGPP0_PD(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP0_PD=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP0_SMT() (pst_bitPNLGPP0_GPP1() -> PNLGPP0_SMT)
#define vSetPNLGPP0_GPP1_PNLGPP0_SMT(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP0_SMT=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP0_IMP() (pst_bitPNLGPP0_GPP1() -> PNLGPP0_IMP)
#define vSetPNLGPP0_GPP1_PNLGPP0_IMP(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP0_IMP=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP0_LATCHN() (pst_bitPNLGPP0_GPP1() -> PNLGPP0_LATCHN)
#define vSetPNLGPP0_GPP1_PNLGPP0_LATCHN(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP0_LATCHN=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP1_SEL() (pst_bitPNLGPP0_GPP1() -> PNLGPP1_SEL)
#define vSetPNLGPP0_GPP1_PNLGPP1_SEL(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP1_SEL=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP1_PU() (pst_bitPNLGPP0_GPP1() -> PNLGPP1_PU)
#define vSetPNLGPP0_GPP1_PNLGPP1_PU(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP1_PU=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP1_PD() (pst_bitPNLGPP0_GPP1() -> PNLGPP1_PD)
#define vSetPNLGPP0_GPP1_PNLGPP1_PD(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP1_PD=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP1_SMT() (pst_bitPNLGPP0_GPP1() -> PNLGPP1_SMT)
#define vSetPNLGPP0_GPP1_PNLGPP1_SMT(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP1_SMT=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP1_IMP() (pst_bitPNLGPP0_GPP1() -> PNLGPP1_IMP)
#define vSetPNLGPP0_GPP1_PNLGPP1_IMP(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP1_IMP=(ParValue))
#define biGetPNLGPP0_GPP1_PNLGPP1_LATCHN() (pst_bitPNLGPP0_GPP1() -> PNLGPP1_LATCHN)
#define vSetPNLGPP0_GPP1_PNLGPP1_LATCHN(ParValue)  (pst_bitPNLGPP0_GPP1() -> PNLGPP1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetPNLGPP0_GPP1LL(ParValue) (pst_u8PNLGPP0_GPP1() -> u8LL = (ParValue))
#define u8GetPNLGPP0_GPP1LL() (pst_u8PNLGPP0_GPP1() -> u8LL)
/* LH-struct byte access */
#define vSetPNLGPP0_GPP1LH(ParValue) (pst_u8PNLGPP0_GPP1() -> u8LH = (ParValue))
#define u8GetPNLGPP0_GPP1LH() (pst_u8PNLGPP0_GPP1() -> u8LH)
/* HL-struct byte access */
#define vSetPNLGPP0_GPP1HL(ParValue) (pst_u8PNLGPP0_GPP1() -> u8HL = (ParValue))
#define u8GetPNLGPP0_GPP1HL() (pst_u8PNLGPP0_GPP1() -> u8HL)
/* HH-struct byte access */
#define vSetPNLGPP0_GPP1HH(ParValue) (pst_u8PNLGPP0_GPP1() -> u8HH = (ParValue))
#define u8GetPNLGPP0_GPP1HH() (pst_u8PNLGPP0_GPP1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNLGPP0_GPP1L(ParValue) (pst_u16PNLGPP0_GPP1() -> u16L = (ParValue))
#define u16GetPNLGPP0_GPP1L() (pst_u16PNLGPP0_GPP1() -> u16L)
#define vSetPNLGPP0_GPP1H(ParValue) (pst_u16PNLGPP0_GPP1() -> u16H = (ParValue))
#define u16GetPNLGPP0_GPP1H() (pst_u16PNLGPP0_GPP1() -> u16H)
            
/* Word access */
#define vSetPNLGPP0_GPP1(ParValue)  (*pu32PNLGPP0_GPP1() = (ParValue))
#define u32GetPNLGPP0_GPP1()  (*pu32PNLGPP0_GPP1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNLGPP2_GPP3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302118                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNLGPP2_GPP3_REG__       0xC0302118U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PNLGPP2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   PNLGPP2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   PNLGPP2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   PNLGPP2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   PNLGPP2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   PNLGPP2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   PNLGPP3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   PNLGPP3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   PNLGPP3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   PNLGPP3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   PNLGPP3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   PNLGPP3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} PNLGPP2_GPP3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNLGPP2_GPP3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNLGPP2_GPP3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNLGPP2_GPP3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNLGPP2_GPP3()     ((volatile PNLGPP2_GPP3_bit_view_st *)\
(PNLGPP2_GPP3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNLGPP2_GPP3()     ((volatile PNLGPP2_GPP3_byte_view_st *)\
(PNLGPP2_GPP3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNLGPP2_GPP3()     ((volatile PNLGPP2_GPP3_halfword_view_st *)\
(PNLGPP2_GPP3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNLGPP2_GPP3()     ((volatile u32PNLGPP2_GPP3_word_view *)\
(PNLGPP2_GPP3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNLGPP2_GPP3_PNLGPP2_SEL() (pst_bitPNLGPP2_GPP3() -> PNLGPP2_SEL)
#define vSetPNLGPP2_GPP3_PNLGPP2_SEL(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP2_SEL=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP2_PU() (pst_bitPNLGPP2_GPP3() -> PNLGPP2_PU)
#define vSetPNLGPP2_GPP3_PNLGPP2_PU(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP2_PU=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP2_PD() (pst_bitPNLGPP2_GPP3() -> PNLGPP2_PD)
#define vSetPNLGPP2_GPP3_PNLGPP2_PD(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP2_PD=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP2_SMT() (pst_bitPNLGPP2_GPP3() -> PNLGPP2_SMT)
#define vSetPNLGPP2_GPP3_PNLGPP2_SMT(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP2_SMT=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP2_IMP() (pst_bitPNLGPP2_GPP3() -> PNLGPP2_IMP)
#define vSetPNLGPP2_GPP3_PNLGPP2_IMP(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP2_IMP=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP2_LATCHN() (pst_bitPNLGPP2_GPP3() -> PNLGPP2_LATCHN)
#define vSetPNLGPP2_GPP3_PNLGPP2_LATCHN(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP2_LATCHN=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP3_SEL() (pst_bitPNLGPP2_GPP3() -> PNLGPP3_SEL)
#define vSetPNLGPP2_GPP3_PNLGPP3_SEL(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP3_SEL=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP3_PU() (pst_bitPNLGPP2_GPP3() -> PNLGPP3_PU)
#define vSetPNLGPP2_GPP3_PNLGPP3_PU(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP3_PU=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP3_PD() (pst_bitPNLGPP2_GPP3() -> PNLGPP3_PD)
#define vSetPNLGPP2_GPP3_PNLGPP3_PD(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP3_PD=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP3_SMT() (pst_bitPNLGPP2_GPP3() -> PNLGPP3_SMT)
#define vSetPNLGPP2_GPP3_PNLGPP3_SMT(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP3_SMT=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP3_IMP() (pst_bitPNLGPP2_GPP3() -> PNLGPP3_IMP)
#define vSetPNLGPP2_GPP3_PNLGPP3_IMP(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP3_IMP=(ParValue))
#define biGetPNLGPP2_GPP3_PNLGPP3_LATCHN() (pst_bitPNLGPP2_GPP3() -> PNLGPP3_LATCHN)
#define vSetPNLGPP2_GPP3_PNLGPP3_LATCHN(ParValue)  (pst_bitPNLGPP2_GPP3() -> PNLGPP3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetPNLGPP2_GPP3LL(ParValue) (pst_u8PNLGPP2_GPP3() -> u8LL = (ParValue))
#define u8GetPNLGPP2_GPP3LL() (pst_u8PNLGPP2_GPP3() -> u8LL)
/* LH-struct byte access */
#define vSetPNLGPP2_GPP3LH(ParValue) (pst_u8PNLGPP2_GPP3() -> u8LH = (ParValue))
#define u8GetPNLGPP2_GPP3LH() (pst_u8PNLGPP2_GPP3() -> u8LH)
/* HL-struct byte access */
#define vSetPNLGPP2_GPP3HL(ParValue) (pst_u8PNLGPP2_GPP3() -> u8HL = (ParValue))
#define u8GetPNLGPP2_GPP3HL() (pst_u8PNLGPP2_GPP3() -> u8HL)
/* HH-struct byte access */
#define vSetPNLGPP2_GPP3HH(ParValue) (pst_u8PNLGPP2_GPP3() -> u8HH = (ParValue))
#define u8GetPNLGPP2_GPP3HH() (pst_u8PNLGPP2_GPP3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNLGPP2_GPP3L(ParValue) (pst_u16PNLGPP2_GPP3() -> u16L = (ParValue))
#define u16GetPNLGPP2_GPP3L() (pst_u16PNLGPP2_GPP3() -> u16L)
#define vSetPNLGPP2_GPP3H(ParValue) (pst_u16PNLGPP2_GPP3() -> u16H = (ParValue))
#define u16GetPNLGPP2_GPP3H() (pst_u16PNLGPP2_GPP3() -> u16H)
            
/* Word access */
#define vSetPNLGPP2_GPP3(ParValue)  (*pu32PNLGPP2_GPP3() = (ParValue))
#define u32GetPNLGPP2_GPP3()  (*pu32PNLGPP2_GPP3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNLGPP4_GPP5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030211C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNLGPP4_GPP5_REG__       0xC030211CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PNLGPP4_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   PNLGPP4_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   PNLGPP4_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   PNLGPP4_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   PNLGPP4_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   PNLGPP4_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   PNLGPP5_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   PNLGPP5_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   PNLGPP5_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   PNLGPP5_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   PNLGPP5_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   PNLGPP5_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} PNLGPP4_GPP5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNLGPP4_GPP5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNLGPP4_GPP5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNLGPP4_GPP5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNLGPP4_GPP5()     ((volatile PNLGPP4_GPP5_bit_view_st *)\
(PNLGPP4_GPP5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNLGPP4_GPP5()     ((volatile PNLGPP4_GPP5_byte_view_st *)\
(PNLGPP4_GPP5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNLGPP4_GPP5()     ((volatile PNLGPP4_GPP5_halfword_view_st *)\
(PNLGPP4_GPP5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNLGPP4_GPP5()     ((volatile u32PNLGPP4_GPP5_word_view *)\
(PNLGPP4_GPP5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNLGPP4_GPP5_PNLGPP4_SEL() (pst_bitPNLGPP4_GPP5() -> PNLGPP4_SEL)
#define vSetPNLGPP4_GPP5_PNLGPP4_SEL(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP4_SEL=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP4_PU() (pst_bitPNLGPP4_GPP5() -> PNLGPP4_PU)
#define vSetPNLGPP4_GPP5_PNLGPP4_PU(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP4_PU=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP4_PD() (pst_bitPNLGPP4_GPP5() -> PNLGPP4_PD)
#define vSetPNLGPP4_GPP5_PNLGPP4_PD(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP4_PD=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP4_SMT() (pst_bitPNLGPP4_GPP5() -> PNLGPP4_SMT)
#define vSetPNLGPP4_GPP5_PNLGPP4_SMT(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP4_SMT=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP4_IMP() (pst_bitPNLGPP4_GPP5() -> PNLGPP4_IMP)
#define vSetPNLGPP4_GPP5_PNLGPP4_IMP(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP4_IMP=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP4_LATCHN() (pst_bitPNLGPP4_GPP5() -> PNLGPP4_LATCHN)
#define vSetPNLGPP4_GPP5_PNLGPP4_LATCHN(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP4_LATCHN=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP5_SEL() (pst_bitPNLGPP4_GPP5() -> PNLGPP5_SEL)
#define vSetPNLGPP4_GPP5_PNLGPP5_SEL(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP5_SEL=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP5_PU() (pst_bitPNLGPP4_GPP5() -> PNLGPP5_PU)
#define vSetPNLGPP4_GPP5_PNLGPP5_PU(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP5_PU=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP5_PD() (pst_bitPNLGPP4_GPP5() -> PNLGPP5_PD)
#define vSetPNLGPP4_GPP5_PNLGPP5_PD(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP5_PD=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP5_SMT() (pst_bitPNLGPP4_GPP5() -> PNLGPP5_SMT)
#define vSetPNLGPP4_GPP5_PNLGPP5_SMT(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP5_SMT=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP5_IMP() (pst_bitPNLGPP4_GPP5() -> PNLGPP5_IMP)
#define vSetPNLGPP4_GPP5_PNLGPP5_IMP(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP5_IMP=(ParValue))
#define biGetPNLGPP4_GPP5_PNLGPP5_LATCHN() (pst_bitPNLGPP4_GPP5() -> PNLGPP5_LATCHN)
#define vSetPNLGPP4_GPP5_PNLGPP5_LATCHN(ParValue)  (pst_bitPNLGPP4_GPP5() -> PNLGPP5_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetPNLGPP4_GPP5LL(ParValue) (pst_u8PNLGPP4_GPP5() -> u8LL = (ParValue))
#define u8GetPNLGPP4_GPP5LL() (pst_u8PNLGPP4_GPP5() -> u8LL)
/* LH-struct byte access */
#define vSetPNLGPP4_GPP5LH(ParValue) (pst_u8PNLGPP4_GPP5() -> u8LH = (ParValue))
#define u8GetPNLGPP4_GPP5LH() (pst_u8PNLGPP4_GPP5() -> u8LH)
/* HL-struct byte access */
#define vSetPNLGPP4_GPP5HL(ParValue) (pst_u8PNLGPP4_GPP5() -> u8HL = (ParValue))
#define u8GetPNLGPP4_GPP5HL() (pst_u8PNLGPP4_GPP5() -> u8HL)
/* HH-struct byte access */
#define vSetPNLGPP4_GPP5HH(ParValue) (pst_u8PNLGPP4_GPP5() -> u8HH = (ParValue))
#define u8GetPNLGPP4_GPP5HH() (pst_u8PNLGPP4_GPP5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNLGPP4_GPP5L(ParValue) (pst_u16PNLGPP4_GPP5() -> u16L = (ParValue))
#define u16GetPNLGPP4_GPP5L() (pst_u16PNLGPP4_GPP5() -> u16L)
#define vSetPNLGPP4_GPP5H(ParValue) (pst_u16PNLGPP4_GPP5() -> u16H = (ParValue))
#define u16GetPNLGPP4_GPP5H() (pst_u16PNLGPP4_GPP5() -> u16H)
            
/* Word access */
#define vSetPNLGPP4_GPP5(ParValue)  (*pu32PNLGPP4_GPP5() = (ParValue))
#define u32GetPNLGPP4_GPP5()  (*pu32PNLGPP4_GPP5() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNLGPP6_GPP7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302120                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNLGPP6_GPP7_REG__       0xC0302120U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PNLGPP6_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   PNLGPP6_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   PNLGPP6_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   PNLGPP6_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   PNLGPP6_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   PNLGPP6_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   PNLGPP7_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   PNLGPP7_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   PNLGPP7_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   PNLGPP7_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   PNLGPP7_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   PNLGPP7_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} PNLGPP6_GPP7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNLGPP6_GPP7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNLGPP6_GPP7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNLGPP6_GPP7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNLGPP6_GPP7()     ((volatile PNLGPP6_GPP7_bit_view_st *)\
(PNLGPP6_GPP7_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNLGPP6_GPP7()     ((volatile PNLGPP6_GPP7_byte_view_st *)\
(PNLGPP6_GPP7_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNLGPP6_GPP7()     ((volatile PNLGPP6_GPP7_halfword_view_st *)\
(PNLGPP6_GPP7_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNLGPP6_GPP7()     ((volatile u32PNLGPP6_GPP7_word_view *)\
(PNLGPP6_GPP7_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNLGPP6_GPP7_PNLGPP6_SEL() (pst_bitPNLGPP6_GPP7() -> PNLGPP6_SEL)
#define vSetPNLGPP6_GPP7_PNLGPP6_SEL(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP6_SEL=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP6_PU() (pst_bitPNLGPP6_GPP7() -> PNLGPP6_PU)
#define vSetPNLGPP6_GPP7_PNLGPP6_PU(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP6_PU=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP6_PD() (pst_bitPNLGPP6_GPP7() -> PNLGPP6_PD)
#define vSetPNLGPP6_GPP7_PNLGPP6_PD(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP6_PD=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP6_SMT() (pst_bitPNLGPP6_GPP7() -> PNLGPP6_SMT)
#define vSetPNLGPP6_GPP7_PNLGPP6_SMT(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP6_SMT=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP6_IMP() (pst_bitPNLGPP6_GPP7() -> PNLGPP6_IMP)
#define vSetPNLGPP6_GPP7_PNLGPP6_IMP(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP6_IMP=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP6_LATCHN() (pst_bitPNLGPP6_GPP7() -> PNLGPP6_LATCHN)
#define vSetPNLGPP6_GPP7_PNLGPP6_LATCHN(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP6_LATCHN=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP7_SEL() (pst_bitPNLGPP6_GPP7() -> PNLGPP7_SEL)
#define vSetPNLGPP6_GPP7_PNLGPP7_SEL(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP7_SEL=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP7_PU() (pst_bitPNLGPP6_GPP7() -> PNLGPP7_PU)
#define vSetPNLGPP6_GPP7_PNLGPP7_PU(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP7_PU=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP7_PD() (pst_bitPNLGPP6_GPP7() -> PNLGPP7_PD)
#define vSetPNLGPP6_GPP7_PNLGPP7_PD(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP7_PD=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP7_SMT() (pst_bitPNLGPP6_GPP7() -> PNLGPP7_SMT)
#define vSetPNLGPP6_GPP7_PNLGPP7_SMT(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP7_SMT=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP7_IMP() (pst_bitPNLGPP6_GPP7() -> PNLGPP7_IMP)
#define vSetPNLGPP6_GPP7_PNLGPP7_IMP(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP7_IMP=(ParValue))
#define biGetPNLGPP6_GPP7_PNLGPP7_LATCHN() (pst_bitPNLGPP6_GPP7() -> PNLGPP7_LATCHN)
#define vSetPNLGPP6_GPP7_PNLGPP7_LATCHN(ParValue)  (pst_bitPNLGPP6_GPP7() -> PNLGPP7_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetPNLGPP6_GPP7LL(ParValue) (pst_u8PNLGPP6_GPP7() -> u8LL = (ParValue))
#define u8GetPNLGPP6_GPP7LL() (pst_u8PNLGPP6_GPP7() -> u8LL)
/* LH-struct byte access */
#define vSetPNLGPP6_GPP7LH(ParValue) (pst_u8PNLGPP6_GPP7() -> u8LH = (ParValue))
#define u8GetPNLGPP6_GPP7LH() (pst_u8PNLGPP6_GPP7() -> u8LH)
/* HL-struct byte access */
#define vSetPNLGPP6_GPP7HL(ParValue) (pst_u8PNLGPP6_GPP7() -> u8HL = (ParValue))
#define u8GetPNLGPP6_GPP7HL() (pst_u8PNLGPP6_GPP7() -> u8HL)
/* HH-struct byte access */
#define vSetPNLGPP6_GPP7HH(ParValue) (pst_u8PNLGPP6_GPP7() -> u8HH = (ParValue))
#define u8GetPNLGPP6_GPP7HH() (pst_u8PNLGPP6_GPP7() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNLGPP6_GPP7L(ParValue) (pst_u16PNLGPP6_GPP7() -> u16L = (ParValue))
#define u16GetPNLGPP6_GPP7L() (pst_u16PNLGPP6_GPP7() -> u16L)
#define vSetPNLGPP6_GPP7H(ParValue) (pst_u16PNLGPP6_GPP7() -> u16H = (ParValue))
#define u16GetPNLGPP6_GPP7H() (pst_u16PNLGPP6_GPP7() -> u16H)
            
/* Word access */
#define vSetPNLGPP6_GPP7(ParValue)  (*pu32PNLGPP6_GPP7() = (ParValue))
#define u32GetPNLGPP6_GPP7()  (*pu32PNLGPP6_GPP7() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1HDISP_HSYNC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302130                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1HDISP_HSYNC_REG__       0xC0302130U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1HDISP_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1HDISP_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1HDISP_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1HDISP_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1HDISP_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1HDISP_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1HSYNC_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1HSYNC_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1HSYNC_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1HSYNC_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1HSYNC_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1HSYNC_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1HDISP_HSYNC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1HDISP_HSYNC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1HDISP_HSYNC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1HDISP_HSYNC_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1HDISP_HSYNC()     ((volatile D1HDISP_HSYNC_bit_view_st *)\
(D1HDISP_HSYNC_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1HDISP_HSYNC()     ((volatile D1HDISP_HSYNC_byte_view_st *)\
(D1HDISP_HSYNC_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1HDISP_HSYNC()     ((volatile D1HDISP_HSYNC_halfword_view_st *)\
(D1HDISP_HSYNC_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1HDISP_HSYNC()     ((volatile u32D1HDISP_HSYNC_word_view *)\
(D1HDISP_HSYNC_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1HDISP_HSYNC_D1HDISP_SEL() (pst_bitD1HDISP_HSYNC() -> D1HDISP_SEL)
#define vSetD1HDISP_HSYNC_D1HDISP_SEL(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HDISP_SEL=(ParValue))
#define biGetD1HDISP_HSYNC_D1HDISP_PU() (pst_bitD1HDISP_HSYNC() -> D1HDISP_PU)
#define vSetD1HDISP_HSYNC_D1HDISP_PU(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HDISP_PU=(ParValue))
#define biGetD1HDISP_HSYNC_D1HDISP_PD() (pst_bitD1HDISP_HSYNC() -> D1HDISP_PD)
#define vSetD1HDISP_HSYNC_D1HDISP_PD(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HDISP_PD=(ParValue))
#define biGetD1HDISP_HSYNC_D1HDISP_SMT() (pst_bitD1HDISP_HSYNC() -> D1HDISP_SMT)
#define vSetD1HDISP_HSYNC_D1HDISP_SMT(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HDISP_SMT=(ParValue))
#define biGetD1HDISP_HSYNC_D1HDISP_IMP() (pst_bitD1HDISP_HSYNC() -> D1HDISP_IMP)
#define vSetD1HDISP_HSYNC_D1HDISP_IMP(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HDISP_IMP=(ParValue))
#define biGetD1HDISP_HSYNC_D1HDISP_LATCHN() (pst_bitD1HDISP_HSYNC() -> D1HDISP_LATCHN)
#define vSetD1HDISP_HSYNC_D1HDISP_LATCHN(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HDISP_LATCHN=(ParValue))
#define biGetD1HDISP_HSYNC_D1HSYNC_SEL() (pst_bitD1HDISP_HSYNC() -> D1HSYNC_SEL)
#define vSetD1HDISP_HSYNC_D1HSYNC_SEL(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HSYNC_SEL=(ParValue))
#define biGetD1HDISP_HSYNC_D1HSYNC_PU() (pst_bitD1HDISP_HSYNC() -> D1HSYNC_PU)
#define vSetD1HDISP_HSYNC_D1HSYNC_PU(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HSYNC_PU=(ParValue))
#define biGetD1HDISP_HSYNC_D1HSYNC_PD() (pst_bitD1HDISP_HSYNC() -> D1HSYNC_PD)
#define vSetD1HDISP_HSYNC_D1HSYNC_PD(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HSYNC_PD=(ParValue))
#define biGetD1HDISP_HSYNC_D1HSYNC_SMT() (pst_bitD1HDISP_HSYNC() -> D1HSYNC_SMT)
#define vSetD1HDISP_HSYNC_D1HSYNC_SMT(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HSYNC_SMT=(ParValue))
#define biGetD1HDISP_HSYNC_D1HSYNC_IMP() (pst_bitD1HDISP_HSYNC() -> D1HSYNC_IMP)
#define vSetD1HDISP_HSYNC_D1HSYNC_IMP(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HSYNC_IMP=(ParValue))
#define biGetD1HDISP_HSYNC_D1HSYNC_LATCHN() (pst_bitD1HDISP_HSYNC() -> D1HSYNC_LATCHN)
#define vSetD1HDISP_HSYNC_D1HSYNC_LATCHN(ParValue)  (pst_bitD1HDISP_HSYNC() -> D1HSYNC_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1HDISP_HSYNCLL(ParValue) (pst_u8D1HDISP_HSYNC() -> u8LL = (ParValue))
#define u8GetD1HDISP_HSYNCLL() (pst_u8D1HDISP_HSYNC() -> u8LL)
/* LH-struct byte access */
#define vSetD1HDISP_HSYNCLH(ParValue) (pst_u8D1HDISP_HSYNC() -> u8LH = (ParValue))
#define u8GetD1HDISP_HSYNCLH() (pst_u8D1HDISP_HSYNC() -> u8LH)
/* HL-struct byte access */
#define vSetD1HDISP_HSYNCHL(ParValue) (pst_u8D1HDISP_HSYNC() -> u8HL = (ParValue))
#define u8GetD1HDISP_HSYNCHL() (pst_u8D1HDISP_HSYNC() -> u8HL)
/* HH-struct byte access */
#define vSetD1HDISP_HSYNCHH(ParValue) (pst_u8D1HDISP_HSYNC() -> u8HH = (ParValue))
#define u8GetD1HDISP_HSYNCHH() (pst_u8D1HDISP_HSYNC() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1HDISP_HSYNCL(ParValue) (pst_u16D1HDISP_HSYNC() -> u16L = (ParValue))
#define u16GetD1HDISP_HSYNCL() (pst_u16D1HDISP_HSYNC() -> u16L)
#define vSetD1HDISP_HSYNCH(ParValue) (pst_u16D1HDISP_HSYNC() -> u16H = (ParValue))
#define u16GetD1HDISP_HSYNCH() (pst_u16D1HDISP_HSYNC() -> u16H)
            
/* Word access */
#define vSetD1HDISP_HSYNC(ParValue)  (*pu32D1HDISP_HSYNC() = (ParValue))
#define u32GetD1HDISP_HSYNC()  (*pu32D1HDISP_HSYNC() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1VSYNC_DOTCLK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302134                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1VSYNC_DOTCLK_REG__       0xC0302134U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1VSYNC_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1VSYNC_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1VSYNC_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1VSYNC_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1VSYNC_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1VSYNC_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1DOTCLK_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1DOTCLK_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1DOTCLK_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1DOTCLK_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1DOTCLK_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1DOTCLK_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1VSYNC_DOTCLK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1VSYNC_DOTCLK_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1VSYNC_DOTCLK_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1VSYNC_DOTCLK_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1VSYNC_DOTCLK()     ((volatile D1VSYNC_DOTCLK_bit_view_st *)\
(D1VSYNC_DOTCLK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1VSYNC_DOTCLK()     ((volatile D1VSYNC_DOTCLK_byte_view_st *)\
(D1VSYNC_DOTCLK_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1VSYNC_DOTCLK()     ((volatile D1VSYNC_DOTCLK_halfword_view_st *)\
(D1VSYNC_DOTCLK_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1VSYNC_DOTCLK()     ((volatile u32D1VSYNC_DOTCLK_word_view *)\
(D1VSYNC_DOTCLK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1VSYNC_DOTCLK_D1VSYNC_SEL() (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_SEL)
#define vSetD1VSYNC_DOTCLK_D1VSYNC_SEL(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_SEL=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1VSYNC_PU() (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_PU)
#define vSetD1VSYNC_DOTCLK_D1VSYNC_PU(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_PU=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1VSYNC_PD() (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_PD)
#define vSetD1VSYNC_DOTCLK_D1VSYNC_PD(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_PD=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1VSYNC_SMT() (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_SMT)
#define vSetD1VSYNC_DOTCLK_D1VSYNC_SMT(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_SMT=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1VSYNC_IMP() (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_IMP)
#define vSetD1VSYNC_DOTCLK_D1VSYNC_IMP(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_IMP=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1VSYNC_LATCHN() (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_LATCHN)
#define vSetD1VSYNC_DOTCLK_D1VSYNC_LATCHN(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1VSYNC_LATCHN=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1DOTCLK_SEL() (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_SEL)
#define vSetD1VSYNC_DOTCLK_D1DOTCLK_SEL(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_SEL=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1DOTCLK_PU() (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_PU)
#define vSetD1VSYNC_DOTCLK_D1DOTCLK_PU(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_PU=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1DOTCLK_PD() (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_PD)
#define vSetD1VSYNC_DOTCLK_D1DOTCLK_PD(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_PD=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1DOTCLK_SMT() (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_SMT)
#define vSetD1VSYNC_DOTCLK_D1DOTCLK_SMT(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_SMT=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1DOTCLK_IMP() (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_IMP)
#define vSetD1VSYNC_DOTCLK_D1DOTCLK_IMP(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_IMP=(ParValue))
#define biGetD1VSYNC_DOTCLK_D1DOTCLK_LATCHN() (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_LATCHN)
#define vSetD1VSYNC_DOTCLK_D1DOTCLK_LATCHN(ParValue)  (pst_bitD1VSYNC_DOTCLK() -> D1DOTCLK_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1VSYNC_DOTCLKLL(ParValue) (pst_u8D1VSYNC_DOTCLK() -> u8LL = (ParValue))
#define u8GetD1VSYNC_DOTCLKLL() (pst_u8D1VSYNC_DOTCLK() -> u8LL)
/* LH-struct byte access */
#define vSetD1VSYNC_DOTCLKLH(ParValue) (pst_u8D1VSYNC_DOTCLK() -> u8LH = (ParValue))
#define u8GetD1VSYNC_DOTCLKLH() (pst_u8D1VSYNC_DOTCLK() -> u8LH)
/* HL-struct byte access */
#define vSetD1VSYNC_DOTCLKHL(ParValue) (pst_u8D1VSYNC_DOTCLK() -> u8HL = (ParValue))
#define u8GetD1VSYNC_DOTCLKHL() (pst_u8D1VSYNC_DOTCLK() -> u8HL)
/* HH-struct byte access */
#define vSetD1VSYNC_DOTCLKHH(ParValue) (pst_u8D1VSYNC_DOTCLK() -> u8HH = (ParValue))
#define u8GetD1VSYNC_DOTCLKHH() (pst_u8D1VSYNC_DOTCLK() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1VSYNC_DOTCLKL(ParValue) (pst_u16D1VSYNC_DOTCLK() -> u16L = (ParValue))
#define u16GetD1VSYNC_DOTCLKL() (pst_u16D1VSYNC_DOTCLK() -> u16L)
#define vSetD1VSYNC_DOTCLKH(ParValue) (pst_u16D1VSYNC_DOTCLK() -> u16H = (ParValue))
#define u16GetD1VSYNC_DOTCLKH() (pst_u16D1VSYNC_DOTCLK() -> u16H)
            
/* Word access */
#define vSetD1VSYNC_DOTCLK(ParValue)  (*pu32D1VSYNC_DOTCLK() = (ParValue))
#define u32GetD1VSYNC_DOTCLK()  (*pu32D1VSYNC_DOTCLK() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB0_RGB1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302138                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB0_RGB1_REG__       0xC0302138U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB0_RGB1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB0_RGB1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB0_RGB1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB0_RGB1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB0_RGB1()     ((volatile D1RGB0_RGB1_bit_view_st *)\
(D1RGB0_RGB1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB0_RGB1()     ((volatile D1RGB0_RGB1_byte_view_st *)\
(D1RGB0_RGB1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB0_RGB1()     ((volatile D1RGB0_RGB1_halfword_view_st *)\
(D1RGB0_RGB1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB0_RGB1()     ((volatile u32D1RGB0_RGB1_word_view *)\
(D1RGB0_RGB1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB0_RGB1_D1RGB0_SEL() (pst_bitD1RGB0_RGB1() -> D1RGB0_SEL)
#define vSetD1RGB0_RGB1_D1RGB0_SEL(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB0_SEL=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB0_PU() (pst_bitD1RGB0_RGB1() -> D1RGB0_PU)
#define vSetD1RGB0_RGB1_D1RGB0_PU(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB0_PU=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB0_PD() (pst_bitD1RGB0_RGB1() -> D1RGB0_PD)
#define vSetD1RGB0_RGB1_D1RGB0_PD(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB0_PD=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB0_SMT() (pst_bitD1RGB0_RGB1() -> D1RGB0_SMT)
#define vSetD1RGB0_RGB1_D1RGB0_SMT(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB0_SMT=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB0_IMP() (pst_bitD1RGB0_RGB1() -> D1RGB0_IMP)
#define vSetD1RGB0_RGB1_D1RGB0_IMP(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB0_IMP=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB0_LATCHN() (pst_bitD1RGB0_RGB1() -> D1RGB0_LATCHN)
#define vSetD1RGB0_RGB1_D1RGB0_LATCHN(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB0_LATCHN=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB1_SEL() (pst_bitD1RGB0_RGB1() -> D1RGB1_SEL)
#define vSetD1RGB0_RGB1_D1RGB1_SEL(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB1_SEL=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB1_PU() (pst_bitD1RGB0_RGB1() -> D1RGB1_PU)
#define vSetD1RGB0_RGB1_D1RGB1_PU(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB1_PU=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB1_PD() (pst_bitD1RGB0_RGB1() -> D1RGB1_PD)
#define vSetD1RGB0_RGB1_D1RGB1_PD(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB1_PD=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB1_SMT() (pst_bitD1RGB0_RGB1() -> D1RGB1_SMT)
#define vSetD1RGB0_RGB1_D1RGB1_SMT(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB1_SMT=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB1_IMP() (pst_bitD1RGB0_RGB1() -> D1RGB1_IMP)
#define vSetD1RGB0_RGB1_D1RGB1_IMP(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB1_IMP=(ParValue))
#define biGetD1RGB0_RGB1_D1RGB1_LATCHN() (pst_bitD1RGB0_RGB1() -> D1RGB1_LATCHN)
#define vSetD1RGB0_RGB1_D1RGB1_LATCHN(ParValue)  (pst_bitD1RGB0_RGB1() -> D1RGB1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB0_RGB1LL(ParValue) (pst_u8D1RGB0_RGB1() -> u8LL = (ParValue))
#define u8GetD1RGB0_RGB1LL() (pst_u8D1RGB0_RGB1() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB0_RGB1LH(ParValue) (pst_u8D1RGB0_RGB1() -> u8LH = (ParValue))
#define u8GetD1RGB0_RGB1LH() (pst_u8D1RGB0_RGB1() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB0_RGB1HL(ParValue) (pst_u8D1RGB0_RGB1() -> u8HL = (ParValue))
#define u8GetD1RGB0_RGB1HL() (pst_u8D1RGB0_RGB1() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB0_RGB1HH(ParValue) (pst_u8D1RGB0_RGB1() -> u8HH = (ParValue))
#define u8GetD1RGB0_RGB1HH() (pst_u8D1RGB0_RGB1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB0_RGB1L(ParValue) (pst_u16D1RGB0_RGB1() -> u16L = (ParValue))
#define u16GetD1RGB0_RGB1L() (pst_u16D1RGB0_RGB1() -> u16L)
#define vSetD1RGB0_RGB1H(ParValue) (pst_u16D1RGB0_RGB1() -> u16H = (ParValue))
#define u16GetD1RGB0_RGB1H() (pst_u16D1RGB0_RGB1() -> u16H)
            
/* Word access */
#define vSetD1RGB0_RGB1(ParValue)  (*pu32D1RGB0_RGB1() = (ParValue))
#define u32GetD1RGB0_RGB1()  (*pu32D1RGB0_RGB1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB2_RGB3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030213C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB2_RGB3_REG__       0xC030213CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB2_RGB3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB2_RGB3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB2_RGB3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB2_RGB3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB2_RGB3()     ((volatile D1RGB2_RGB3_bit_view_st *)\
(D1RGB2_RGB3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB2_RGB3()     ((volatile D1RGB2_RGB3_byte_view_st *)\
(D1RGB2_RGB3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB2_RGB3()     ((volatile D1RGB2_RGB3_halfword_view_st *)\
(D1RGB2_RGB3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB2_RGB3()     ((volatile u32D1RGB2_RGB3_word_view *)\
(D1RGB2_RGB3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB2_RGB3_D1RGB2_SEL() (pst_bitD1RGB2_RGB3() -> D1RGB2_SEL)
#define vSetD1RGB2_RGB3_D1RGB2_SEL(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB2_SEL=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB2_PU() (pst_bitD1RGB2_RGB3() -> D1RGB2_PU)
#define vSetD1RGB2_RGB3_D1RGB2_PU(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB2_PU=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB2_PD() (pst_bitD1RGB2_RGB3() -> D1RGB2_PD)
#define vSetD1RGB2_RGB3_D1RGB2_PD(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB2_PD=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB2_SMT() (pst_bitD1RGB2_RGB3() -> D1RGB2_SMT)
#define vSetD1RGB2_RGB3_D1RGB2_SMT(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB2_SMT=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB2_IMP() (pst_bitD1RGB2_RGB3() -> D1RGB2_IMP)
#define vSetD1RGB2_RGB3_D1RGB2_IMP(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB2_IMP=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB2_LATCHN() (pst_bitD1RGB2_RGB3() -> D1RGB2_LATCHN)
#define vSetD1RGB2_RGB3_D1RGB2_LATCHN(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB2_LATCHN=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB3_SEL() (pst_bitD1RGB2_RGB3() -> D1RGB3_SEL)
#define vSetD1RGB2_RGB3_D1RGB3_SEL(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB3_SEL=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB3_PU() (pst_bitD1RGB2_RGB3() -> D1RGB3_PU)
#define vSetD1RGB2_RGB3_D1RGB3_PU(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB3_PU=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB3_PD() (pst_bitD1RGB2_RGB3() -> D1RGB3_PD)
#define vSetD1RGB2_RGB3_D1RGB3_PD(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB3_PD=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB3_SMT() (pst_bitD1RGB2_RGB3() -> D1RGB3_SMT)
#define vSetD1RGB2_RGB3_D1RGB3_SMT(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB3_SMT=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB3_IMP() (pst_bitD1RGB2_RGB3() -> D1RGB3_IMP)
#define vSetD1RGB2_RGB3_D1RGB3_IMP(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB3_IMP=(ParValue))
#define biGetD1RGB2_RGB3_D1RGB3_LATCHN() (pst_bitD1RGB2_RGB3() -> D1RGB3_LATCHN)
#define vSetD1RGB2_RGB3_D1RGB3_LATCHN(ParValue)  (pst_bitD1RGB2_RGB3() -> D1RGB3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB2_RGB3LL(ParValue) (pst_u8D1RGB2_RGB3() -> u8LL = (ParValue))
#define u8GetD1RGB2_RGB3LL() (pst_u8D1RGB2_RGB3() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB2_RGB3LH(ParValue) (pst_u8D1RGB2_RGB3() -> u8LH = (ParValue))
#define u8GetD1RGB2_RGB3LH() (pst_u8D1RGB2_RGB3() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB2_RGB3HL(ParValue) (pst_u8D1RGB2_RGB3() -> u8HL = (ParValue))
#define u8GetD1RGB2_RGB3HL() (pst_u8D1RGB2_RGB3() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB2_RGB3HH(ParValue) (pst_u8D1RGB2_RGB3() -> u8HH = (ParValue))
#define u8GetD1RGB2_RGB3HH() (pst_u8D1RGB2_RGB3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB2_RGB3L(ParValue) (pst_u16D1RGB2_RGB3() -> u16L = (ParValue))
#define u16GetD1RGB2_RGB3L() (pst_u16D1RGB2_RGB3() -> u16L)
#define vSetD1RGB2_RGB3H(ParValue) (pst_u16D1RGB2_RGB3() -> u16H = (ParValue))
#define u16GetD1RGB2_RGB3H() (pst_u16D1RGB2_RGB3() -> u16H)
            
/* Word access */
#define vSetD1RGB2_RGB3(ParValue)  (*pu32D1RGB2_RGB3() = (ParValue))
#define u32GetD1RGB2_RGB3()  (*pu32D1RGB2_RGB3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB4_RGB5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302140                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB4_RGB5_REG__       0xC0302140U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB4_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB4_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB4_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB4_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB4_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB4_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB5_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB5_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB5_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB5_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB5_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB5_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB4_RGB5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB4_RGB5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB4_RGB5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB4_RGB5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB4_RGB5()     ((volatile D1RGB4_RGB5_bit_view_st *)\
(D1RGB4_RGB5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB4_RGB5()     ((volatile D1RGB4_RGB5_byte_view_st *)\
(D1RGB4_RGB5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB4_RGB5()     ((volatile D1RGB4_RGB5_halfword_view_st *)\
(D1RGB4_RGB5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB4_RGB5()     ((volatile u32D1RGB4_RGB5_word_view *)\
(D1RGB4_RGB5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB4_RGB5_D1RGB4_SEL() (pst_bitD1RGB4_RGB5() -> D1RGB4_SEL)
#define vSetD1RGB4_RGB5_D1RGB4_SEL(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB4_SEL=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB4_PU() (pst_bitD1RGB4_RGB5() -> D1RGB4_PU)
#define vSetD1RGB4_RGB5_D1RGB4_PU(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB4_PU=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB4_PD() (pst_bitD1RGB4_RGB5() -> D1RGB4_PD)
#define vSetD1RGB4_RGB5_D1RGB4_PD(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB4_PD=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB4_SMT() (pst_bitD1RGB4_RGB5() -> D1RGB4_SMT)
#define vSetD1RGB4_RGB5_D1RGB4_SMT(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB4_SMT=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB4_IMP() (pst_bitD1RGB4_RGB5() -> D1RGB4_IMP)
#define vSetD1RGB4_RGB5_D1RGB4_IMP(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB4_IMP=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB4_LATCHN() (pst_bitD1RGB4_RGB5() -> D1RGB4_LATCHN)
#define vSetD1RGB4_RGB5_D1RGB4_LATCHN(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB4_LATCHN=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB5_SEL() (pst_bitD1RGB4_RGB5() -> D1RGB5_SEL)
#define vSetD1RGB4_RGB5_D1RGB5_SEL(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB5_SEL=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB5_PU() (pst_bitD1RGB4_RGB5() -> D1RGB5_PU)
#define vSetD1RGB4_RGB5_D1RGB5_PU(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB5_PU=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB5_PD() (pst_bitD1RGB4_RGB5() -> D1RGB5_PD)
#define vSetD1RGB4_RGB5_D1RGB5_PD(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB5_PD=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB5_SMT() (pst_bitD1RGB4_RGB5() -> D1RGB5_SMT)
#define vSetD1RGB4_RGB5_D1RGB5_SMT(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB5_SMT=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB5_IMP() (pst_bitD1RGB4_RGB5() -> D1RGB5_IMP)
#define vSetD1RGB4_RGB5_D1RGB5_IMP(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB5_IMP=(ParValue))
#define biGetD1RGB4_RGB5_D1RGB5_LATCHN() (pst_bitD1RGB4_RGB5() -> D1RGB5_LATCHN)
#define vSetD1RGB4_RGB5_D1RGB5_LATCHN(ParValue)  (pst_bitD1RGB4_RGB5() -> D1RGB5_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB4_RGB5LL(ParValue) (pst_u8D1RGB4_RGB5() -> u8LL = (ParValue))
#define u8GetD1RGB4_RGB5LL() (pst_u8D1RGB4_RGB5() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB4_RGB5LH(ParValue) (pst_u8D1RGB4_RGB5() -> u8LH = (ParValue))
#define u8GetD1RGB4_RGB5LH() (pst_u8D1RGB4_RGB5() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB4_RGB5HL(ParValue) (pst_u8D1RGB4_RGB5() -> u8HL = (ParValue))
#define u8GetD1RGB4_RGB5HL() (pst_u8D1RGB4_RGB5() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB4_RGB5HH(ParValue) (pst_u8D1RGB4_RGB5() -> u8HH = (ParValue))
#define u8GetD1RGB4_RGB5HH() (pst_u8D1RGB4_RGB5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB4_RGB5L(ParValue) (pst_u16D1RGB4_RGB5() -> u16L = (ParValue))
#define u16GetD1RGB4_RGB5L() (pst_u16D1RGB4_RGB5() -> u16L)
#define vSetD1RGB4_RGB5H(ParValue) (pst_u16D1RGB4_RGB5() -> u16H = (ParValue))
#define u16GetD1RGB4_RGB5H() (pst_u16D1RGB4_RGB5() -> u16H)
            
/* Word access */
#define vSetD1RGB4_RGB5(ParValue)  (*pu32D1RGB4_RGB5() = (ParValue))
#define u32GetD1RGB4_RGB5()  (*pu32D1RGB4_RGB5() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB6_RGB7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302144                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB6_RGB7_REG__       0xC0302144U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB6_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB6_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB6_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB6_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB6_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB6_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB7_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB7_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB7_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB7_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB7_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB7_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB6_RGB7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB6_RGB7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB6_RGB7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB6_RGB7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB6_RGB7()     ((volatile D1RGB6_RGB7_bit_view_st *)\
(D1RGB6_RGB7_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB6_RGB7()     ((volatile D1RGB6_RGB7_byte_view_st *)\
(D1RGB6_RGB7_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB6_RGB7()     ((volatile D1RGB6_RGB7_halfword_view_st *)\
(D1RGB6_RGB7_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB6_RGB7()     ((volatile u32D1RGB6_RGB7_word_view *)\
(D1RGB6_RGB7_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB6_RGB7_D1RGB6_SEL() (pst_bitD1RGB6_RGB7() -> D1RGB6_SEL)
#define vSetD1RGB6_RGB7_D1RGB6_SEL(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB6_SEL=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB6_PU() (pst_bitD1RGB6_RGB7() -> D1RGB6_PU)
#define vSetD1RGB6_RGB7_D1RGB6_PU(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB6_PU=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB6_PD() (pst_bitD1RGB6_RGB7() -> D1RGB6_PD)
#define vSetD1RGB6_RGB7_D1RGB6_PD(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB6_PD=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB6_SMT() (pst_bitD1RGB6_RGB7() -> D1RGB6_SMT)
#define vSetD1RGB6_RGB7_D1RGB6_SMT(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB6_SMT=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB6_IMP() (pst_bitD1RGB6_RGB7() -> D1RGB6_IMP)
#define vSetD1RGB6_RGB7_D1RGB6_IMP(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB6_IMP=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB6_LATCHN() (pst_bitD1RGB6_RGB7() -> D1RGB6_LATCHN)
#define vSetD1RGB6_RGB7_D1RGB6_LATCHN(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB6_LATCHN=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB7_SEL() (pst_bitD1RGB6_RGB7() -> D1RGB7_SEL)
#define vSetD1RGB6_RGB7_D1RGB7_SEL(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB7_SEL=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB7_PU() (pst_bitD1RGB6_RGB7() -> D1RGB7_PU)
#define vSetD1RGB6_RGB7_D1RGB7_PU(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB7_PU=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB7_PD() (pst_bitD1RGB6_RGB7() -> D1RGB7_PD)
#define vSetD1RGB6_RGB7_D1RGB7_PD(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB7_PD=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB7_SMT() (pst_bitD1RGB6_RGB7() -> D1RGB7_SMT)
#define vSetD1RGB6_RGB7_D1RGB7_SMT(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB7_SMT=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB7_IMP() (pst_bitD1RGB6_RGB7() -> D1RGB7_IMP)
#define vSetD1RGB6_RGB7_D1RGB7_IMP(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB7_IMP=(ParValue))
#define biGetD1RGB6_RGB7_D1RGB7_LATCHN() (pst_bitD1RGB6_RGB7() -> D1RGB7_LATCHN)
#define vSetD1RGB6_RGB7_D1RGB7_LATCHN(ParValue)  (pst_bitD1RGB6_RGB7() -> D1RGB7_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB6_RGB7LL(ParValue) (pst_u8D1RGB6_RGB7() -> u8LL = (ParValue))
#define u8GetD1RGB6_RGB7LL() (pst_u8D1RGB6_RGB7() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB6_RGB7LH(ParValue) (pst_u8D1RGB6_RGB7() -> u8LH = (ParValue))
#define u8GetD1RGB6_RGB7LH() (pst_u8D1RGB6_RGB7() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB6_RGB7HL(ParValue) (pst_u8D1RGB6_RGB7() -> u8HL = (ParValue))
#define u8GetD1RGB6_RGB7HL() (pst_u8D1RGB6_RGB7() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB6_RGB7HH(ParValue) (pst_u8D1RGB6_RGB7() -> u8HH = (ParValue))
#define u8GetD1RGB6_RGB7HH() (pst_u8D1RGB6_RGB7() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB6_RGB7L(ParValue) (pst_u16D1RGB6_RGB7() -> u16L = (ParValue))
#define u16GetD1RGB6_RGB7L() (pst_u16D1RGB6_RGB7() -> u16L)
#define vSetD1RGB6_RGB7H(ParValue) (pst_u16D1RGB6_RGB7() -> u16H = (ParValue))
#define u16GetD1RGB6_RGB7H() (pst_u16D1RGB6_RGB7() -> u16H)
            
/* Word access */
#define vSetD1RGB6_RGB7(ParValue)  (*pu32D1RGB6_RGB7() = (ParValue))
#define u32GetD1RGB6_RGB7()  (*pu32D1RGB6_RGB7() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB8_RGB9                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302148                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB8_RGB9_REG__       0xC0302148U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB8_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB8_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB8_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB8_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB8_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB8_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB9_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB9_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB9_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB9_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB9_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB9_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB8_RGB9_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB8_RGB9_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB8_RGB9_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB8_RGB9_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB8_RGB9()     ((volatile D1RGB8_RGB9_bit_view_st *)\
(D1RGB8_RGB9_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB8_RGB9()     ((volatile D1RGB8_RGB9_byte_view_st *)\
(D1RGB8_RGB9_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB8_RGB9()     ((volatile D1RGB8_RGB9_halfword_view_st *)\
(D1RGB8_RGB9_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB8_RGB9()     ((volatile u32D1RGB8_RGB9_word_view *)\
(D1RGB8_RGB9_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB8_RGB9_D1RGB8_SEL() (pst_bitD1RGB8_RGB9() -> D1RGB8_SEL)
#define vSetD1RGB8_RGB9_D1RGB8_SEL(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB8_SEL=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB8_PU() (pst_bitD1RGB8_RGB9() -> D1RGB8_PU)
#define vSetD1RGB8_RGB9_D1RGB8_PU(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB8_PU=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB8_PD() (pst_bitD1RGB8_RGB9() -> D1RGB8_PD)
#define vSetD1RGB8_RGB9_D1RGB8_PD(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB8_PD=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB8_SMT() (pst_bitD1RGB8_RGB9() -> D1RGB8_SMT)
#define vSetD1RGB8_RGB9_D1RGB8_SMT(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB8_SMT=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB8_IMP() (pst_bitD1RGB8_RGB9() -> D1RGB8_IMP)
#define vSetD1RGB8_RGB9_D1RGB8_IMP(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB8_IMP=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB8_LATCHN() (pst_bitD1RGB8_RGB9() -> D1RGB8_LATCHN)
#define vSetD1RGB8_RGB9_D1RGB8_LATCHN(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB8_LATCHN=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB9_SEL() (pst_bitD1RGB8_RGB9() -> D1RGB9_SEL)
#define vSetD1RGB8_RGB9_D1RGB9_SEL(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB9_SEL=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB9_PU() (pst_bitD1RGB8_RGB9() -> D1RGB9_PU)
#define vSetD1RGB8_RGB9_D1RGB9_PU(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB9_PU=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB9_PD() (pst_bitD1RGB8_RGB9() -> D1RGB9_PD)
#define vSetD1RGB8_RGB9_D1RGB9_PD(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB9_PD=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB9_SMT() (pst_bitD1RGB8_RGB9() -> D1RGB9_SMT)
#define vSetD1RGB8_RGB9_D1RGB9_SMT(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB9_SMT=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB9_IMP() (pst_bitD1RGB8_RGB9() -> D1RGB9_IMP)
#define vSetD1RGB8_RGB9_D1RGB9_IMP(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB9_IMP=(ParValue))
#define biGetD1RGB8_RGB9_D1RGB9_LATCHN() (pst_bitD1RGB8_RGB9() -> D1RGB9_LATCHN)
#define vSetD1RGB8_RGB9_D1RGB9_LATCHN(ParValue)  (pst_bitD1RGB8_RGB9() -> D1RGB9_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB8_RGB9LL(ParValue) (pst_u8D1RGB8_RGB9() -> u8LL = (ParValue))
#define u8GetD1RGB8_RGB9LL() (pst_u8D1RGB8_RGB9() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB8_RGB9LH(ParValue) (pst_u8D1RGB8_RGB9() -> u8LH = (ParValue))
#define u8GetD1RGB8_RGB9LH() (pst_u8D1RGB8_RGB9() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB8_RGB9HL(ParValue) (pst_u8D1RGB8_RGB9() -> u8HL = (ParValue))
#define u8GetD1RGB8_RGB9HL() (pst_u8D1RGB8_RGB9() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB8_RGB9HH(ParValue) (pst_u8D1RGB8_RGB9() -> u8HH = (ParValue))
#define u8GetD1RGB8_RGB9HH() (pst_u8D1RGB8_RGB9() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB8_RGB9L(ParValue) (pst_u16D1RGB8_RGB9() -> u16L = (ParValue))
#define u16GetD1RGB8_RGB9L() (pst_u16D1RGB8_RGB9() -> u16L)
#define vSetD1RGB8_RGB9H(ParValue) (pst_u16D1RGB8_RGB9() -> u16H = (ParValue))
#define u16GetD1RGB8_RGB9H() (pst_u16D1RGB8_RGB9() -> u16H)
            
/* Word access */
#define vSetD1RGB8_RGB9(ParValue)  (*pu32D1RGB8_RGB9() = (ParValue))
#define u32GetD1RGB8_RGB9()  (*pu32D1RGB8_RGB9() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB10_RGB11                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030214C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB10_RGB11_REG__       0xC030214CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB10_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB10_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB10_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB10_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB10_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB10_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB11_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB11_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB11_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB11_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB11_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB11_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB10_RGB11_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB10_RGB11_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB10_RGB11_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB10_RGB11_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB10_RGB11()     ((volatile D1RGB10_RGB11_bit_view_st *)\
(D1RGB10_RGB11_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB10_RGB11()     ((volatile D1RGB10_RGB11_byte_view_st *)\
(D1RGB10_RGB11_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB10_RGB11()     ((volatile D1RGB10_RGB11_halfword_view_st *)\
(D1RGB10_RGB11_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB10_RGB11()     ((volatile u32D1RGB10_RGB11_word_view *)\
(D1RGB10_RGB11_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB10_RGB11_D1RGB10_SEL() (pst_bitD1RGB10_RGB11() -> D1RGB10_SEL)
#define vSetD1RGB10_RGB11_D1RGB10_SEL(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB10_SEL=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB10_PU() (pst_bitD1RGB10_RGB11() -> D1RGB10_PU)
#define vSetD1RGB10_RGB11_D1RGB10_PU(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB10_PU=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB10_PD() (pst_bitD1RGB10_RGB11() -> D1RGB10_PD)
#define vSetD1RGB10_RGB11_D1RGB10_PD(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB10_PD=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB10_SMT() (pst_bitD1RGB10_RGB11() -> D1RGB10_SMT)
#define vSetD1RGB10_RGB11_D1RGB10_SMT(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB10_SMT=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB10_IMP() (pst_bitD1RGB10_RGB11() -> D1RGB10_IMP)
#define vSetD1RGB10_RGB11_D1RGB10_IMP(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB10_IMP=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB10_LATCHN() (pst_bitD1RGB10_RGB11() -> D1RGB10_LATCHN)
#define vSetD1RGB10_RGB11_D1RGB10_LATCHN(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB10_LATCHN=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB11_SEL() (pst_bitD1RGB10_RGB11() -> D1RGB11_SEL)
#define vSetD1RGB10_RGB11_D1RGB11_SEL(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB11_SEL=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB11_PU() (pst_bitD1RGB10_RGB11() -> D1RGB11_PU)
#define vSetD1RGB10_RGB11_D1RGB11_PU(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB11_PU=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB11_PD() (pst_bitD1RGB10_RGB11() -> D1RGB11_PD)
#define vSetD1RGB10_RGB11_D1RGB11_PD(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB11_PD=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB11_SMT() (pst_bitD1RGB10_RGB11() -> D1RGB11_SMT)
#define vSetD1RGB10_RGB11_D1RGB11_SMT(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB11_SMT=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB11_IMP() (pst_bitD1RGB10_RGB11() -> D1RGB11_IMP)
#define vSetD1RGB10_RGB11_D1RGB11_IMP(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB11_IMP=(ParValue))
#define biGetD1RGB10_RGB11_D1RGB11_LATCHN() (pst_bitD1RGB10_RGB11() -> D1RGB11_LATCHN)
#define vSetD1RGB10_RGB11_D1RGB11_LATCHN(ParValue)  (pst_bitD1RGB10_RGB11() -> D1RGB11_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB10_RGB11LL(ParValue) (pst_u8D1RGB10_RGB11() -> u8LL = (ParValue))
#define u8GetD1RGB10_RGB11LL() (pst_u8D1RGB10_RGB11() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB10_RGB11LH(ParValue) (pst_u8D1RGB10_RGB11() -> u8LH = (ParValue))
#define u8GetD1RGB10_RGB11LH() (pst_u8D1RGB10_RGB11() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB10_RGB11HL(ParValue) (pst_u8D1RGB10_RGB11() -> u8HL = (ParValue))
#define u8GetD1RGB10_RGB11HL() (pst_u8D1RGB10_RGB11() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB10_RGB11HH(ParValue) (pst_u8D1RGB10_RGB11() -> u8HH = (ParValue))
#define u8GetD1RGB10_RGB11HH() (pst_u8D1RGB10_RGB11() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB10_RGB11L(ParValue) (pst_u16D1RGB10_RGB11() -> u16L = (ParValue))
#define u16GetD1RGB10_RGB11L() (pst_u16D1RGB10_RGB11() -> u16L)
#define vSetD1RGB10_RGB11H(ParValue) (pst_u16D1RGB10_RGB11() -> u16H = (ParValue))
#define u16GetD1RGB10_RGB11H() (pst_u16D1RGB10_RGB11() -> u16H)
            
/* Word access */
#define vSetD1RGB10_RGB11(ParValue)  (*pu32D1RGB10_RGB11() = (ParValue))
#define u32GetD1RGB10_RGB11()  (*pu32D1RGB10_RGB11() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB12_RGB13                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302150                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB12_RGB13_REG__       0xC0302150U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB12_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB12_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB12_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB12_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB12_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB12_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB13_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB13_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB13_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB13_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB13_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB13_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB12_RGB13_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB12_RGB13_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB12_RGB13_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB12_RGB13_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB12_RGB13()     ((volatile D1RGB12_RGB13_bit_view_st *)\
(D1RGB12_RGB13_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB12_RGB13()     ((volatile D1RGB12_RGB13_byte_view_st *)\
(D1RGB12_RGB13_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB12_RGB13()     ((volatile D1RGB12_RGB13_halfword_view_st *)\
(D1RGB12_RGB13_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB12_RGB13()     ((volatile u32D1RGB12_RGB13_word_view *)\
(D1RGB12_RGB13_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB12_RGB13_D1RGB12_SEL() (pst_bitD1RGB12_RGB13() -> D1RGB12_SEL)
#define vSetD1RGB12_RGB13_D1RGB12_SEL(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB12_SEL=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB12_PU() (pst_bitD1RGB12_RGB13() -> D1RGB12_PU)
#define vSetD1RGB12_RGB13_D1RGB12_PU(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB12_PU=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB12_PD() (pst_bitD1RGB12_RGB13() -> D1RGB12_PD)
#define vSetD1RGB12_RGB13_D1RGB12_PD(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB12_PD=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB12_SMT() (pst_bitD1RGB12_RGB13() -> D1RGB12_SMT)
#define vSetD1RGB12_RGB13_D1RGB12_SMT(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB12_SMT=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB12_IMP() (pst_bitD1RGB12_RGB13() -> D1RGB12_IMP)
#define vSetD1RGB12_RGB13_D1RGB12_IMP(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB12_IMP=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB12_LATCHN() (pst_bitD1RGB12_RGB13() -> D1RGB12_LATCHN)
#define vSetD1RGB12_RGB13_D1RGB12_LATCHN(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB12_LATCHN=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB13_SEL() (pst_bitD1RGB12_RGB13() -> D1RGB13_SEL)
#define vSetD1RGB12_RGB13_D1RGB13_SEL(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB13_SEL=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB13_PU() (pst_bitD1RGB12_RGB13() -> D1RGB13_PU)
#define vSetD1RGB12_RGB13_D1RGB13_PU(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB13_PU=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB13_PD() (pst_bitD1RGB12_RGB13() -> D1RGB13_PD)
#define vSetD1RGB12_RGB13_D1RGB13_PD(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB13_PD=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB13_SMT() (pst_bitD1RGB12_RGB13() -> D1RGB13_SMT)
#define vSetD1RGB12_RGB13_D1RGB13_SMT(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB13_SMT=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB13_IMP() (pst_bitD1RGB12_RGB13() -> D1RGB13_IMP)
#define vSetD1RGB12_RGB13_D1RGB13_IMP(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB13_IMP=(ParValue))
#define biGetD1RGB12_RGB13_D1RGB13_LATCHN() (pst_bitD1RGB12_RGB13() -> D1RGB13_LATCHN)
#define vSetD1RGB12_RGB13_D1RGB13_LATCHN(ParValue)  (pst_bitD1RGB12_RGB13() -> D1RGB13_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB12_RGB13LL(ParValue) (pst_u8D1RGB12_RGB13() -> u8LL = (ParValue))
#define u8GetD1RGB12_RGB13LL() (pst_u8D1RGB12_RGB13() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB12_RGB13LH(ParValue) (pst_u8D1RGB12_RGB13() -> u8LH = (ParValue))
#define u8GetD1RGB12_RGB13LH() (pst_u8D1RGB12_RGB13() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB12_RGB13HL(ParValue) (pst_u8D1RGB12_RGB13() -> u8HL = (ParValue))
#define u8GetD1RGB12_RGB13HL() (pst_u8D1RGB12_RGB13() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB12_RGB13HH(ParValue) (pst_u8D1RGB12_RGB13() -> u8HH = (ParValue))
#define u8GetD1RGB12_RGB13HH() (pst_u8D1RGB12_RGB13() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB12_RGB13L(ParValue) (pst_u16D1RGB12_RGB13() -> u16L = (ParValue))
#define u16GetD1RGB12_RGB13L() (pst_u16D1RGB12_RGB13() -> u16L)
#define vSetD1RGB12_RGB13H(ParValue) (pst_u16D1RGB12_RGB13() -> u16H = (ParValue))
#define u16GetD1RGB12_RGB13H() (pst_u16D1RGB12_RGB13() -> u16H)
            
/* Word access */
#define vSetD1RGB12_RGB13(ParValue)  (*pu32D1RGB12_RGB13() = (ParValue))
#define u32GetD1RGB12_RGB13()  (*pu32D1RGB12_RGB13() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB14_RGB15                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302154                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB14_RGB15_REG__       0xC0302154U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB14_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB14_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB14_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB14_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB14_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB14_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB15_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB15_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB15_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB15_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB15_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB15_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB14_RGB15_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB14_RGB15_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB14_RGB15_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB14_RGB15_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB14_RGB15()     ((volatile D1RGB14_RGB15_bit_view_st *)\
(D1RGB14_RGB15_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB14_RGB15()     ((volatile D1RGB14_RGB15_byte_view_st *)\
(D1RGB14_RGB15_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB14_RGB15()     ((volatile D1RGB14_RGB15_halfword_view_st *)\
(D1RGB14_RGB15_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB14_RGB15()     ((volatile u32D1RGB14_RGB15_word_view *)\
(D1RGB14_RGB15_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB14_RGB15_D1RGB14_SEL() (pst_bitD1RGB14_RGB15() -> D1RGB14_SEL)
#define vSetD1RGB14_RGB15_D1RGB14_SEL(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB14_SEL=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB14_PU() (pst_bitD1RGB14_RGB15() -> D1RGB14_PU)
#define vSetD1RGB14_RGB15_D1RGB14_PU(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB14_PU=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB14_PD() (pst_bitD1RGB14_RGB15() -> D1RGB14_PD)
#define vSetD1RGB14_RGB15_D1RGB14_PD(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB14_PD=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB14_SMT() (pst_bitD1RGB14_RGB15() -> D1RGB14_SMT)
#define vSetD1RGB14_RGB15_D1RGB14_SMT(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB14_SMT=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB14_IMP() (pst_bitD1RGB14_RGB15() -> D1RGB14_IMP)
#define vSetD1RGB14_RGB15_D1RGB14_IMP(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB14_IMP=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB14_LATCHN() (pst_bitD1RGB14_RGB15() -> D1RGB14_LATCHN)
#define vSetD1RGB14_RGB15_D1RGB14_LATCHN(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB14_LATCHN=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB15_SEL() (pst_bitD1RGB14_RGB15() -> D1RGB15_SEL)
#define vSetD1RGB14_RGB15_D1RGB15_SEL(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB15_SEL=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB15_PU() (pst_bitD1RGB14_RGB15() -> D1RGB15_PU)
#define vSetD1RGB14_RGB15_D1RGB15_PU(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB15_PU=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB15_PD() (pst_bitD1RGB14_RGB15() -> D1RGB15_PD)
#define vSetD1RGB14_RGB15_D1RGB15_PD(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB15_PD=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB15_SMT() (pst_bitD1RGB14_RGB15() -> D1RGB15_SMT)
#define vSetD1RGB14_RGB15_D1RGB15_SMT(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB15_SMT=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB15_IMP() (pst_bitD1RGB14_RGB15() -> D1RGB15_IMP)
#define vSetD1RGB14_RGB15_D1RGB15_IMP(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB15_IMP=(ParValue))
#define biGetD1RGB14_RGB15_D1RGB15_LATCHN() (pst_bitD1RGB14_RGB15() -> D1RGB15_LATCHN)
#define vSetD1RGB14_RGB15_D1RGB15_LATCHN(ParValue)  (pst_bitD1RGB14_RGB15() -> D1RGB15_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB14_RGB15LL(ParValue) (pst_u8D1RGB14_RGB15() -> u8LL = (ParValue))
#define u8GetD1RGB14_RGB15LL() (pst_u8D1RGB14_RGB15() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB14_RGB15LH(ParValue) (pst_u8D1RGB14_RGB15() -> u8LH = (ParValue))
#define u8GetD1RGB14_RGB15LH() (pst_u8D1RGB14_RGB15() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB14_RGB15HL(ParValue) (pst_u8D1RGB14_RGB15() -> u8HL = (ParValue))
#define u8GetD1RGB14_RGB15HL() (pst_u8D1RGB14_RGB15() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB14_RGB15HH(ParValue) (pst_u8D1RGB14_RGB15() -> u8HH = (ParValue))
#define u8GetD1RGB14_RGB15HH() (pst_u8D1RGB14_RGB15() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB14_RGB15L(ParValue) (pst_u16D1RGB14_RGB15() -> u16L = (ParValue))
#define u16GetD1RGB14_RGB15L() (pst_u16D1RGB14_RGB15() -> u16L)
#define vSetD1RGB14_RGB15H(ParValue) (pst_u16D1RGB14_RGB15() -> u16H = (ParValue))
#define u16GetD1RGB14_RGB15H() (pst_u16D1RGB14_RGB15() -> u16H)
            
/* Word access */
#define vSetD1RGB14_RGB15(ParValue)  (*pu32D1RGB14_RGB15() = (ParValue))
#define u32GetD1RGB14_RGB15()  (*pu32D1RGB14_RGB15() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB16_RGB17                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302158                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB16_RGB17_REG__       0xC0302158U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB16_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB16_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB16_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB16_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB16_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB16_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB17_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB17_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB17_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB17_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB17_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB17_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB16_RGB17_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB16_RGB17_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB16_RGB17_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB16_RGB17_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB16_RGB17()     ((volatile D1RGB16_RGB17_bit_view_st *)\
(D1RGB16_RGB17_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB16_RGB17()     ((volatile D1RGB16_RGB17_byte_view_st *)\
(D1RGB16_RGB17_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB16_RGB17()     ((volatile D1RGB16_RGB17_halfword_view_st *)\
(D1RGB16_RGB17_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB16_RGB17()     ((volatile u32D1RGB16_RGB17_word_view *)\
(D1RGB16_RGB17_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB16_RGB17_D1RGB16_SEL() (pst_bitD1RGB16_RGB17() -> D1RGB16_SEL)
#define vSetD1RGB16_RGB17_D1RGB16_SEL(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB16_SEL=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB16_PU() (pst_bitD1RGB16_RGB17() -> D1RGB16_PU)
#define vSetD1RGB16_RGB17_D1RGB16_PU(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB16_PU=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB16_PD() (pst_bitD1RGB16_RGB17() -> D1RGB16_PD)
#define vSetD1RGB16_RGB17_D1RGB16_PD(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB16_PD=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB16_SMT() (pst_bitD1RGB16_RGB17() -> D1RGB16_SMT)
#define vSetD1RGB16_RGB17_D1RGB16_SMT(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB16_SMT=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB16_IMP() (pst_bitD1RGB16_RGB17() -> D1RGB16_IMP)
#define vSetD1RGB16_RGB17_D1RGB16_IMP(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB16_IMP=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB16_LATCHN() (pst_bitD1RGB16_RGB17() -> D1RGB16_LATCHN)
#define vSetD1RGB16_RGB17_D1RGB16_LATCHN(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB16_LATCHN=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB17_SEL() (pst_bitD1RGB16_RGB17() -> D1RGB17_SEL)
#define vSetD1RGB16_RGB17_D1RGB17_SEL(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB17_SEL=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB17_PU() (pst_bitD1RGB16_RGB17() -> D1RGB17_PU)
#define vSetD1RGB16_RGB17_D1RGB17_PU(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB17_PU=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB17_PD() (pst_bitD1RGB16_RGB17() -> D1RGB17_PD)
#define vSetD1RGB16_RGB17_D1RGB17_PD(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB17_PD=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB17_SMT() (pst_bitD1RGB16_RGB17() -> D1RGB17_SMT)
#define vSetD1RGB16_RGB17_D1RGB17_SMT(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB17_SMT=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB17_IMP() (pst_bitD1RGB16_RGB17() -> D1RGB17_IMP)
#define vSetD1RGB16_RGB17_D1RGB17_IMP(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB17_IMP=(ParValue))
#define biGetD1RGB16_RGB17_D1RGB17_LATCHN() (pst_bitD1RGB16_RGB17() -> D1RGB17_LATCHN)
#define vSetD1RGB16_RGB17_D1RGB17_LATCHN(ParValue)  (pst_bitD1RGB16_RGB17() -> D1RGB17_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB16_RGB17LL(ParValue) (pst_u8D1RGB16_RGB17() -> u8LL = (ParValue))
#define u8GetD1RGB16_RGB17LL() (pst_u8D1RGB16_RGB17() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB16_RGB17LH(ParValue) (pst_u8D1RGB16_RGB17() -> u8LH = (ParValue))
#define u8GetD1RGB16_RGB17LH() (pst_u8D1RGB16_RGB17() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB16_RGB17HL(ParValue) (pst_u8D1RGB16_RGB17() -> u8HL = (ParValue))
#define u8GetD1RGB16_RGB17HL() (pst_u8D1RGB16_RGB17() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB16_RGB17HH(ParValue) (pst_u8D1RGB16_RGB17() -> u8HH = (ParValue))
#define u8GetD1RGB16_RGB17HH() (pst_u8D1RGB16_RGB17() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB16_RGB17L(ParValue) (pst_u16D1RGB16_RGB17() -> u16L = (ParValue))
#define u16GetD1RGB16_RGB17L() (pst_u16D1RGB16_RGB17() -> u16L)
#define vSetD1RGB16_RGB17H(ParValue) (pst_u16D1RGB16_RGB17() -> u16H = (ParValue))
#define u16GetD1RGB16_RGB17H() (pst_u16D1RGB16_RGB17() -> u16H)
            
/* Word access */
#define vSetD1RGB16_RGB17(ParValue)  (*pu32D1RGB16_RGB17() = (ParValue))
#define u32GetD1RGB16_RGB17()  (*pu32D1RGB16_RGB17() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB18_RGB19                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030215C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB18_RGB19_REG__       0xC030215CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB18_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB18_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB18_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB18_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB18_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB18_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB19_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB19_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB19_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB19_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB19_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB19_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB18_RGB19_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB18_RGB19_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB18_RGB19_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB18_RGB19_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB18_RGB19()     ((volatile D1RGB18_RGB19_bit_view_st *)\
(D1RGB18_RGB19_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB18_RGB19()     ((volatile D1RGB18_RGB19_byte_view_st *)\
(D1RGB18_RGB19_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB18_RGB19()     ((volatile D1RGB18_RGB19_halfword_view_st *)\
(D1RGB18_RGB19_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB18_RGB19()     ((volatile u32D1RGB18_RGB19_word_view *)\
(D1RGB18_RGB19_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB18_RGB19_D1RGB18_SEL() (pst_bitD1RGB18_RGB19() -> D1RGB18_SEL)
#define vSetD1RGB18_RGB19_D1RGB18_SEL(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB18_SEL=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB18_PU() (pst_bitD1RGB18_RGB19() -> D1RGB18_PU)
#define vSetD1RGB18_RGB19_D1RGB18_PU(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB18_PU=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB18_PD() (pst_bitD1RGB18_RGB19() -> D1RGB18_PD)
#define vSetD1RGB18_RGB19_D1RGB18_PD(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB18_PD=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB18_SMT() (pst_bitD1RGB18_RGB19() -> D1RGB18_SMT)
#define vSetD1RGB18_RGB19_D1RGB18_SMT(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB18_SMT=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB18_IMP() (pst_bitD1RGB18_RGB19() -> D1RGB18_IMP)
#define vSetD1RGB18_RGB19_D1RGB18_IMP(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB18_IMP=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB18_LATCHN() (pst_bitD1RGB18_RGB19() -> D1RGB18_LATCHN)
#define vSetD1RGB18_RGB19_D1RGB18_LATCHN(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB18_LATCHN=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB19_SEL() (pst_bitD1RGB18_RGB19() -> D1RGB19_SEL)
#define vSetD1RGB18_RGB19_D1RGB19_SEL(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB19_SEL=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB19_PU() (pst_bitD1RGB18_RGB19() -> D1RGB19_PU)
#define vSetD1RGB18_RGB19_D1RGB19_PU(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB19_PU=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB19_PD() (pst_bitD1RGB18_RGB19() -> D1RGB19_PD)
#define vSetD1RGB18_RGB19_D1RGB19_PD(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB19_PD=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB19_SMT() (pst_bitD1RGB18_RGB19() -> D1RGB19_SMT)
#define vSetD1RGB18_RGB19_D1RGB19_SMT(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB19_SMT=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB19_IMP() (pst_bitD1RGB18_RGB19() -> D1RGB19_IMP)
#define vSetD1RGB18_RGB19_D1RGB19_IMP(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB19_IMP=(ParValue))
#define biGetD1RGB18_RGB19_D1RGB19_LATCHN() (pst_bitD1RGB18_RGB19() -> D1RGB19_LATCHN)
#define vSetD1RGB18_RGB19_D1RGB19_LATCHN(ParValue)  (pst_bitD1RGB18_RGB19() -> D1RGB19_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB18_RGB19LL(ParValue) (pst_u8D1RGB18_RGB19() -> u8LL = (ParValue))
#define u8GetD1RGB18_RGB19LL() (pst_u8D1RGB18_RGB19() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB18_RGB19LH(ParValue) (pst_u8D1RGB18_RGB19() -> u8LH = (ParValue))
#define u8GetD1RGB18_RGB19LH() (pst_u8D1RGB18_RGB19() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB18_RGB19HL(ParValue) (pst_u8D1RGB18_RGB19() -> u8HL = (ParValue))
#define u8GetD1RGB18_RGB19HL() (pst_u8D1RGB18_RGB19() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB18_RGB19HH(ParValue) (pst_u8D1RGB18_RGB19() -> u8HH = (ParValue))
#define u8GetD1RGB18_RGB19HH() (pst_u8D1RGB18_RGB19() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB18_RGB19L(ParValue) (pst_u16D1RGB18_RGB19() -> u16L = (ParValue))
#define u16GetD1RGB18_RGB19L() (pst_u16D1RGB18_RGB19() -> u16L)
#define vSetD1RGB18_RGB19H(ParValue) (pst_u16D1RGB18_RGB19() -> u16H = (ParValue))
#define u16GetD1RGB18_RGB19H() (pst_u16D1RGB18_RGB19() -> u16H)
            
/* Word access */
#define vSetD1RGB18_RGB19(ParValue)  (*pu32D1RGB18_RGB19() = (ParValue))
#define u32GetD1RGB18_RGB19()  (*pu32D1RGB18_RGB19() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB20_RGB21                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302160                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB20_RGB21_REG__       0xC0302160U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB20_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB20_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB20_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB20_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB20_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB20_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB21_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB21_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB21_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB21_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB21_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB21_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB20_RGB21_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB20_RGB21_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB20_RGB21_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB20_RGB21_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB20_RGB21()     ((volatile D1RGB20_RGB21_bit_view_st *)\
(D1RGB20_RGB21_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB20_RGB21()     ((volatile D1RGB20_RGB21_byte_view_st *)\
(D1RGB20_RGB21_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB20_RGB21()     ((volatile D1RGB20_RGB21_halfword_view_st *)\
(D1RGB20_RGB21_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB20_RGB21()     ((volatile u32D1RGB20_RGB21_word_view *)\
(D1RGB20_RGB21_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB20_RGB21_D1RGB20_SEL() (pst_bitD1RGB20_RGB21() -> D1RGB20_SEL)
#define vSetD1RGB20_RGB21_D1RGB20_SEL(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB20_SEL=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB20_PU() (pst_bitD1RGB20_RGB21() -> D1RGB20_PU)
#define vSetD1RGB20_RGB21_D1RGB20_PU(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB20_PU=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB20_PD() (pst_bitD1RGB20_RGB21() -> D1RGB20_PD)
#define vSetD1RGB20_RGB21_D1RGB20_PD(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB20_PD=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB20_SMT() (pst_bitD1RGB20_RGB21() -> D1RGB20_SMT)
#define vSetD1RGB20_RGB21_D1RGB20_SMT(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB20_SMT=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB20_IMP() (pst_bitD1RGB20_RGB21() -> D1RGB20_IMP)
#define vSetD1RGB20_RGB21_D1RGB20_IMP(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB20_IMP=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB20_LATCHN() (pst_bitD1RGB20_RGB21() -> D1RGB20_LATCHN)
#define vSetD1RGB20_RGB21_D1RGB20_LATCHN(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB20_LATCHN=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB21_SEL() (pst_bitD1RGB20_RGB21() -> D1RGB21_SEL)
#define vSetD1RGB20_RGB21_D1RGB21_SEL(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB21_SEL=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB21_PU() (pst_bitD1RGB20_RGB21() -> D1RGB21_PU)
#define vSetD1RGB20_RGB21_D1RGB21_PU(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB21_PU=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB21_PD() (pst_bitD1RGB20_RGB21() -> D1RGB21_PD)
#define vSetD1RGB20_RGB21_D1RGB21_PD(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB21_PD=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB21_SMT() (pst_bitD1RGB20_RGB21() -> D1RGB21_SMT)
#define vSetD1RGB20_RGB21_D1RGB21_SMT(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB21_SMT=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB21_IMP() (pst_bitD1RGB20_RGB21() -> D1RGB21_IMP)
#define vSetD1RGB20_RGB21_D1RGB21_IMP(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB21_IMP=(ParValue))
#define biGetD1RGB20_RGB21_D1RGB21_LATCHN() (pst_bitD1RGB20_RGB21() -> D1RGB21_LATCHN)
#define vSetD1RGB20_RGB21_D1RGB21_LATCHN(ParValue)  (pst_bitD1RGB20_RGB21() -> D1RGB21_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB20_RGB21LL(ParValue) (pst_u8D1RGB20_RGB21() -> u8LL = (ParValue))
#define u8GetD1RGB20_RGB21LL() (pst_u8D1RGB20_RGB21() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB20_RGB21LH(ParValue) (pst_u8D1RGB20_RGB21() -> u8LH = (ParValue))
#define u8GetD1RGB20_RGB21LH() (pst_u8D1RGB20_RGB21() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB20_RGB21HL(ParValue) (pst_u8D1RGB20_RGB21() -> u8HL = (ParValue))
#define u8GetD1RGB20_RGB21HL() (pst_u8D1RGB20_RGB21() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB20_RGB21HH(ParValue) (pst_u8D1RGB20_RGB21() -> u8HH = (ParValue))
#define u8GetD1RGB20_RGB21HH() (pst_u8D1RGB20_RGB21() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB20_RGB21L(ParValue) (pst_u16D1RGB20_RGB21() -> u16L = (ParValue))
#define u16GetD1RGB20_RGB21L() (pst_u16D1RGB20_RGB21() -> u16L)
#define vSetD1RGB20_RGB21H(ParValue) (pst_u16D1RGB20_RGB21() -> u16H = (ParValue))
#define u16GetD1RGB20_RGB21H() (pst_u16D1RGB20_RGB21() -> u16H)
            
/* Word access */
#define vSetD1RGB20_RGB21(ParValue)  (*pu32D1RGB20_RGB21() = (ParValue))
#define u32GetD1RGB20_RGB21()  (*pu32D1RGB20_RGB21() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: D1RGB22_RGB23                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302164                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define D1RGB22_RGB23_REG__       0xC0302164U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D1RGB22_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   D1RGB22_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   D1RGB22_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   D1RGB22_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   D1RGB22_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   D1RGB22_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   D1RGB23_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   D1RGB23_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D1RGB23_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   D1RGB23_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   D1RGB23_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   D1RGB23_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} D1RGB22_RGB23_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} D1RGB22_RGB23_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} D1RGB22_RGB23_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32D1RGB22_RGB23_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitD1RGB22_RGB23()     ((volatile D1RGB22_RGB23_bit_view_st *)\
(D1RGB22_RGB23_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8D1RGB22_RGB23()     ((volatile D1RGB22_RGB23_byte_view_st *)\
(D1RGB22_RGB23_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16D1RGB22_RGB23()     ((volatile D1RGB22_RGB23_halfword_view_st *)\
(D1RGB22_RGB23_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32D1RGB22_RGB23()     ((volatile u32D1RGB22_RGB23_word_view *)\
(D1RGB22_RGB23_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetD1RGB22_RGB23_D1RGB22_SEL() (pst_bitD1RGB22_RGB23() -> D1RGB22_SEL)
#define vSetD1RGB22_RGB23_D1RGB22_SEL(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB22_SEL=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB22_PU() (pst_bitD1RGB22_RGB23() -> D1RGB22_PU)
#define vSetD1RGB22_RGB23_D1RGB22_PU(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB22_PU=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB22_PD() (pst_bitD1RGB22_RGB23() -> D1RGB22_PD)
#define vSetD1RGB22_RGB23_D1RGB22_PD(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB22_PD=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB22_SMT() (pst_bitD1RGB22_RGB23() -> D1RGB22_SMT)
#define vSetD1RGB22_RGB23_D1RGB22_SMT(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB22_SMT=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB22_IMP() (pst_bitD1RGB22_RGB23() -> D1RGB22_IMP)
#define vSetD1RGB22_RGB23_D1RGB22_IMP(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB22_IMP=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB22_LATCHN() (pst_bitD1RGB22_RGB23() -> D1RGB22_LATCHN)
#define vSetD1RGB22_RGB23_D1RGB22_LATCHN(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB22_LATCHN=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB23_SEL() (pst_bitD1RGB22_RGB23() -> D1RGB23_SEL)
#define vSetD1RGB22_RGB23_D1RGB23_SEL(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB23_SEL=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB23_PU() (pst_bitD1RGB22_RGB23() -> D1RGB23_PU)
#define vSetD1RGB22_RGB23_D1RGB23_PU(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB23_PU=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB23_PD() (pst_bitD1RGB22_RGB23() -> D1RGB23_PD)
#define vSetD1RGB22_RGB23_D1RGB23_PD(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB23_PD=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB23_SMT() (pst_bitD1RGB22_RGB23() -> D1RGB23_SMT)
#define vSetD1RGB22_RGB23_D1RGB23_SMT(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB23_SMT=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB23_IMP() (pst_bitD1RGB22_RGB23() -> D1RGB23_IMP)
#define vSetD1RGB22_RGB23_D1RGB23_IMP(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB23_IMP=(ParValue))
#define biGetD1RGB22_RGB23_D1RGB23_LATCHN() (pst_bitD1RGB22_RGB23() -> D1RGB23_LATCHN)
#define vSetD1RGB22_RGB23_D1RGB23_LATCHN(ParValue)  (pst_bitD1RGB22_RGB23() -> D1RGB23_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetD1RGB22_RGB23LL(ParValue) (pst_u8D1RGB22_RGB23() -> u8LL = (ParValue))
#define u8GetD1RGB22_RGB23LL() (pst_u8D1RGB22_RGB23() -> u8LL)
/* LH-struct byte access */
#define vSetD1RGB22_RGB23LH(ParValue) (pst_u8D1RGB22_RGB23() -> u8LH = (ParValue))
#define u8GetD1RGB22_RGB23LH() (pst_u8D1RGB22_RGB23() -> u8LH)
/* HL-struct byte access */
#define vSetD1RGB22_RGB23HL(ParValue) (pst_u8D1RGB22_RGB23() -> u8HL = (ParValue))
#define u8GetD1RGB22_RGB23HL() (pst_u8D1RGB22_RGB23() -> u8HL)
/* HH-struct byte access */
#define vSetD1RGB22_RGB23HH(ParValue) (pst_u8D1RGB22_RGB23() -> u8HH = (ParValue))
#define u8GetD1RGB22_RGB23HH() (pst_u8D1RGB22_RGB23() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetD1RGB22_RGB23L(ParValue) (pst_u16D1RGB22_RGB23() -> u16L = (ParValue))
#define u16GetD1RGB22_RGB23L() (pst_u16D1RGB22_RGB23() -> u16L)
#define vSetD1RGB22_RGB23H(ParValue) (pst_u16D1RGB22_RGB23() -> u16H = (ParValue))
#define u16GetD1RGB22_RGB23H() (pst_u16D1RGB22_RGB23() -> u16H)
            
/* Word access */
#define vSetD1RGB22_RGB23(ParValue)  (*pu32D1RGB22_RGB23() = (ParValue))
#define u32GetD1RGB22_RGB23()  (*pu32D1RGB22_RGB23() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMCBCR0_CBCR1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302180                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMCBCR0_CBCR1_REG__       0xC0302180U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMCBCR0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMCBCR0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMCBCR0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMCBCR0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMCBCR0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMCBCR0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMCBCR1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMCBCR1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMCBCR1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMCBCR1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMCBCR1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMCBCR1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMCBCR0_CBCR1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMCBCR0_CBCR1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMCBCR0_CBCR1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMCBCR0_CBCR1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMCBCR0_CBCR1()     ((volatile CMCBCR0_CBCR1_bit_view_st *)\
(CMCBCR0_CBCR1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMCBCR0_CBCR1()     ((volatile CMCBCR0_CBCR1_byte_view_st *)\
(CMCBCR0_CBCR1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMCBCR0_CBCR1()     ((volatile CMCBCR0_CBCR1_halfword_view_st *)\
(CMCBCR0_CBCR1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMCBCR0_CBCR1()     ((volatile u32CMCBCR0_CBCR1_word_view *)\
(CMCBCR0_CBCR1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMCBCR0_CBCR1_CMCBCR0_SEL() (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_SEL)
#define vSetCMCBCR0_CBCR1_CMCBCR0_SEL(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_SEL=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR0_PU() (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_PU)
#define vSetCMCBCR0_CBCR1_CMCBCR0_PU(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_PU=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR0_PD() (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_PD)
#define vSetCMCBCR0_CBCR1_CMCBCR0_PD(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_PD=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR0_SMT() (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_SMT)
#define vSetCMCBCR0_CBCR1_CMCBCR0_SMT(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_SMT=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR0_IMP() (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_IMP)
#define vSetCMCBCR0_CBCR1_CMCBCR0_IMP(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_IMP=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR0_LATCHN() (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_LATCHN)
#define vSetCMCBCR0_CBCR1_CMCBCR0_LATCHN(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR0_LATCHN=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR1_SEL() (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_SEL)
#define vSetCMCBCR0_CBCR1_CMCBCR1_SEL(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_SEL=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR1_PU() (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_PU)
#define vSetCMCBCR0_CBCR1_CMCBCR1_PU(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_PU=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR1_PD() (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_PD)
#define vSetCMCBCR0_CBCR1_CMCBCR1_PD(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_PD=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR1_SMT() (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_SMT)
#define vSetCMCBCR0_CBCR1_CMCBCR1_SMT(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_SMT=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR1_IMP() (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_IMP)
#define vSetCMCBCR0_CBCR1_CMCBCR1_IMP(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_IMP=(ParValue))
#define biGetCMCBCR0_CBCR1_CMCBCR1_LATCHN() (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_LATCHN)
#define vSetCMCBCR0_CBCR1_CMCBCR1_LATCHN(ParValue)  (pst_bitCMCBCR0_CBCR1() -> CMCBCR1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMCBCR0_CBCR1LL(ParValue) (pst_u8CMCBCR0_CBCR1() -> u8LL = (ParValue))
#define u8GetCMCBCR0_CBCR1LL() (pst_u8CMCBCR0_CBCR1() -> u8LL)
/* LH-struct byte access */
#define vSetCMCBCR0_CBCR1LH(ParValue) (pst_u8CMCBCR0_CBCR1() -> u8LH = (ParValue))
#define u8GetCMCBCR0_CBCR1LH() (pst_u8CMCBCR0_CBCR1() -> u8LH)
/* HL-struct byte access */
#define vSetCMCBCR0_CBCR1HL(ParValue) (pst_u8CMCBCR0_CBCR1() -> u8HL = (ParValue))
#define u8GetCMCBCR0_CBCR1HL() (pst_u8CMCBCR0_CBCR1() -> u8HL)
/* HH-struct byte access */
#define vSetCMCBCR0_CBCR1HH(ParValue) (pst_u8CMCBCR0_CBCR1() -> u8HH = (ParValue))
#define u8GetCMCBCR0_CBCR1HH() (pst_u8CMCBCR0_CBCR1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMCBCR0_CBCR1L(ParValue) (pst_u16CMCBCR0_CBCR1() -> u16L = (ParValue))
#define u16GetCMCBCR0_CBCR1L() (pst_u16CMCBCR0_CBCR1() -> u16L)
#define vSetCMCBCR0_CBCR1H(ParValue) (pst_u16CMCBCR0_CBCR1() -> u16H = (ParValue))
#define u16GetCMCBCR0_CBCR1H() (pst_u16CMCBCR0_CBCR1() -> u16H)
            
/* Word access */
#define vSetCMCBCR0_CBCR1(ParValue)  (*pu32CMCBCR0_CBCR1() = (ParValue))
#define u32GetCMCBCR0_CBCR1()  (*pu32CMCBCR0_CBCR1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMCBCR2_CBCR3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302184                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMCBCR2_CBCR3_REG__       0xC0302184U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMCBCR2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMCBCR2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMCBCR2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMCBCR2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMCBCR2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMCBCR2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMCBCR3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMCBCR3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMCBCR3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMCBCR3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMCBCR3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMCBCR3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMCBCR2_CBCR3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMCBCR2_CBCR3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMCBCR2_CBCR3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMCBCR2_CBCR3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMCBCR2_CBCR3()     ((volatile CMCBCR2_CBCR3_bit_view_st *)\
(CMCBCR2_CBCR3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMCBCR2_CBCR3()     ((volatile CMCBCR2_CBCR3_byte_view_st *)\
(CMCBCR2_CBCR3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMCBCR2_CBCR3()     ((volatile CMCBCR2_CBCR3_halfword_view_st *)\
(CMCBCR2_CBCR3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMCBCR2_CBCR3()     ((volatile u32CMCBCR2_CBCR3_word_view *)\
(CMCBCR2_CBCR3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMCBCR2_CBCR3_CMCBCR2_SEL() (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_SEL)
#define vSetCMCBCR2_CBCR3_CMCBCR2_SEL(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_SEL=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR2_PU() (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_PU)
#define vSetCMCBCR2_CBCR3_CMCBCR2_PU(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_PU=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR2_PD() (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_PD)
#define vSetCMCBCR2_CBCR3_CMCBCR2_PD(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_PD=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR2_SMT() (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_SMT)
#define vSetCMCBCR2_CBCR3_CMCBCR2_SMT(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_SMT=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR2_IMP() (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_IMP)
#define vSetCMCBCR2_CBCR3_CMCBCR2_IMP(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_IMP=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR2_LATCHN() (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_LATCHN)
#define vSetCMCBCR2_CBCR3_CMCBCR2_LATCHN(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR2_LATCHN=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR3_SEL() (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_SEL)
#define vSetCMCBCR2_CBCR3_CMCBCR3_SEL(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_SEL=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR3_PU() (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_PU)
#define vSetCMCBCR2_CBCR3_CMCBCR3_PU(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_PU=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR3_PD() (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_PD)
#define vSetCMCBCR2_CBCR3_CMCBCR3_PD(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_PD=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR3_SMT() (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_SMT)
#define vSetCMCBCR2_CBCR3_CMCBCR3_SMT(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_SMT=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR3_IMP() (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_IMP)
#define vSetCMCBCR2_CBCR3_CMCBCR3_IMP(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_IMP=(ParValue))
#define biGetCMCBCR2_CBCR3_CMCBCR3_LATCHN() (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_LATCHN)
#define vSetCMCBCR2_CBCR3_CMCBCR3_LATCHN(ParValue)  (pst_bitCMCBCR2_CBCR3() -> CMCBCR3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMCBCR2_CBCR3LL(ParValue) (pst_u8CMCBCR2_CBCR3() -> u8LL = (ParValue))
#define u8GetCMCBCR2_CBCR3LL() (pst_u8CMCBCR2_CBCR3() -> u8LL)
/* LH-struct byte access */
#define vSetCMCBCR2_CBCR3LH(ParValue) (pst_u8CMCBCR2_CBCR3() -> u8LH = (ParValue))
#define u8GetCMCBCR2_CBCR3LH() (pst_u8CMCBCR2_CBCR3() -> u8LH)
/* HL-struct byte access */
#define vSetCMCBCR2_CBCR3HL(ParValue) (pst_u8CMCBCR2_CBCR3() -> u8HL = (ParValue))
#define u8GetCMCBCR2_CBCR3HL() (pst_u8CMCBCR2_CBCR3() -> u8HL)
/* HH-struct byte access */
#define vSetCMCBCR2_CBCR3HH(ParValue) (pst_u8CMCBCR2_CBCR3() -> u8HH = (ParValue))
#define u8GetCMCBCR2_CBCR3HH() (pst_u8CMCBCR2_CBCR3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMCBCR2_CBCR3L(ParValue) (pst_u16CMCBCR2_CBCR3() -> u16L = (ParValue))
#define u16GetCMCBCR2_CBCR3L() (pst_u16CMCBCR2_CBCR3() -> u16L)
#define vSetCMCBCR2_CBCR3H(ParValue) (pst_u16CMCBCR2_CBCR3() -> u16H = (ParValue))
#define u16GetCMCBCR2_CBCR3H() (pst_u16CMCBCR2_CBCR3() -> u16H)
            
/* Word access */
#define vSetCMCBCR2_CBCR3(ParValue)  (*pu32CMCBCR2_CBCR3() = (ParValue))
#define u32GetCMCBCR2_CBCR3()  (*pu32CMCBCR2_CBCR3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMCBCR4_CBCR5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302188                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMCBCR4_CBCR5_REG__       0xC0302188U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMCBCR4_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMCBCR4_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMCBCR4_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMCBCR4_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMCBCR4_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMCBCR4_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMCBCR5_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMCBCR5_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMCBCR5_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMCBCR5_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMCBCR5_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMCBCR5_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMCBCR4_CBCR5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMCBCR4_CBCR5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMCBCR4_CBCR5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMCBCR4_CBCR5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMCBCR4_CBCR5()     ((volatile CMCBCR4_CBCR5_bit_view_st *)\
(CMCBCR4_CBCR5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMCBCR4_CBCR5()     ((volatile CMCBCR4_CBCR5_byte_view_st *)\
(CMCBCR4_CBCR5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMCBCR4_CBCR5()     ((volatile CMCBCR4_CBCR5_halfword_view_st *)\
(CMCBCR4_CBCR5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMCBCR4_CBCR5()     ((volatile u32CMCBCR4_CBCR5_word_view *)\
(CMCBCR4_CBCR5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMCBCR4_CBCR5_CMCBCR4_SEL() (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_SEL)
#define vSetCMCBCR4_CBCR5_CMCBCR4_SEL(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_SEL=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR4_PU() (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_PU)
#define vSetCMCBCR4_CBCR5_CMCBCR4_PU(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_PU=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR4_PD() (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_PD)
#define vSetCMCBCR4_CBCR5_CMCBCR4_PD(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_PD=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR4_SMT() (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_SMT)
#define vSetCMCBCR4_CBCR5_CMCBCR4_SMT(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_SMT=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR4_IMP() (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_IMP)
#define vSetCMCBCR4_CBCR5_CMCBCR4_IMP(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_IMP=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR4_LATCHN() (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_LATCHN)
#define vSetCMCBCR4_CBCR5_CMCBCR4_LATCHN(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR4_LATCHN=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR5_SEL() (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_SEL)
#define vSetCMCBCR4_CBCR5_CMCBCR5_SEL(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_SEL=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR5_PU() (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_PU)
#define vSetCMCBCR4_CBCR5_CMCBCR5_PU(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_PU=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR5_PD() (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_PD)
#define vSetCMCBCR4_CBCR5_CMCBCR5_PD(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_PD=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR5_SMT() (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_SMT)
#define vSetCMCBCR4_CBCR5_CMCBCR5_SMT(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_SMT=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR5_IMP() (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_IMP)
#define vSetCMCBCR4_CBCR5_CMCBCR5_IMP(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_IMP=(ParValue))
#define biGetCMCBCR4_CBCR5_CMCBCR5_LATCHN() (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_LATCHN)
#define vSetCMCBCR4_CBCR5_CMCBCR5_LATCHN(ParValue)  (pst_bitCMCBCR4_CBCR5() -> CMCBCR5_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMCBCR4_CBCR5LL(ParValue) (pst_u8CMCBCR4_CBCR5() -> u8LL = (ParValue))
#define u8GetCMCBCR4_CBCR5LL() (pst_u8CMCBCR4_CBCR5() -> u8LL)
/* LH-struct byte access */
#define vSetCMCBCR4_CBCR5LH(ParValue) (pst_u8CMCBCR4_CBCR5() -> u8LH = (ParValue))
#define u8GetCMCBCR4_CBCR5LH() (pst_u8CMCBCR4_CBCR5() -> u8LH)
/* HL-struct byte access */
#define vSetCMCBCR4_CBCR5HL(ParValue) (pst_u8CMCBCR4_CBCR5() -> u8HL = (ParValue))
#define u8GetCMCBCR4_CBCR5HL() (pst_u8CMCBCR4_CBCR5() -> u8HL)
/* HH-struct byte access */
#define vSetCMCBCR4_CBCR5HH(ParValue) (pst_u8CMCBCR4_CBCR5() -> u8HH = (ParValue))
#define u8GetCMCBCR4_CBCR5HH() (pst_u8CMCBCR4_CBCR5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMCBCR4_CBCR5L(ParValue) (pst_u16CMCBCR4_CBCR5() -> u16L = (ParValue))
#define u16GetCMCBCR4_CBCR5L() (pst_u16CMCBCR4_CBCR5() -> u16L)
#define vSetCMCBCR4_CBCR5H(ParValue) (pst_u16CMCBCR4_CBCR5() -> u16H = (ParValue))
#define u16GetCMCBCR4_CBCR5H() (pst_u16CMCBCR4_CBCR5() -> u16H)
            
/* Word access */
#define vSetCMCBCR4_CBCR5(ParValue)  (*pu32CMCBCR4_CBCR5() = (ParValue))
#define u32GetCMCBCR4_CBCR5()  (*pu32CMCBCR4_CBCR5() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMCBCR6_CBCR7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030218C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMCBCR6_CBCR7_REG__       0xC030218CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMCBCR6_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMCBCR6_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMCBCR6_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMCBCR6_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMCBCR6_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMCBCR6_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMCBCR7_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMCBCR7_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMCBCR7_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMCBCR7_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMCBCR7_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMCBCR7_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMCBCR6_CBCR7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMCBCR6_CBCR7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMCBCR6_CBCR7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMCBCR6_CBCR7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMCBCR6_CBCR7()     ((volatile CMCBCR6_CBCR7_bit_view_st *)\
(CMCBCR6_CBCR7_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMCBCR6_CBCR7()     ((volatile CMCBCR6_CBCR7_byte_view_st *)\
(CMCBCR6_CBCR7_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMCBCR6_CBCR7()     ((volatile CMCBCR6_CBCR7_halfword_view_st *)\
(CMCBCR6_CBCR7_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMCBCR6_CBCR7()     ((volatile u32CMCBCR6_CBCR7_word_view *)\
(CMCBCR6_CBCR7_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMCBCR6_CBCR7_CMCBCR6_SEL() (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_SEL)
#define vSetCMCBCR6_CBCR7_CMCBCR6_SEL(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_SEL=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR6_PU() (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_PU)
#define vSetCMCBCR6_CBCR7_CMCBCR6_PU(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_PU=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR6_PD() (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_PD)
#define vSetCMCBCR6_CBCR7_CMCBCR6_PD(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_PD=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR6_SMT() (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_SMT)
#define vSetCMCBCR6_CBCR7_CMCBCR6_SMT(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_SMT=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR6_IMP() (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_IMP)
#define vSetCMCBCR6_CBCR7_CMCBCR6_IMP(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_IMP=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR6_LATCHN() (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_LATCHN)
#define vSetCMCBCR6_CBCR7_CMCBCR6_LATCHN(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR6_LATCHN=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR7_SEL() (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_SEL)
#define vSetCMCBCR6_CBCR7_CMCBCR7_SEL(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_SEL=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR7_PU() (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_PU)
#define vSetCMCBCR6_CBCR7_CMCBCR7_PU(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_PU=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR7_PD() (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_PD)
#define vSetCMCBCR6_CBCR7_CMCBCR7_PD(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_PD=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR7_SMT() (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_SMT)
#define vSetCMCBCR6_CBCR7_CMCBCR7_SMT(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_SMT=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR7_IMP() (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_IMP)
#define vSetCMCBCR6_CBCR7_CMCBCR7_IMP(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_IMP=(ParValue))
#define biGetCMCBCR6_CBCR7_CMCBCR7_LATCHN() (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_LATCHN)
#define vSetCMCBCR6_CBCR7_CMCBCR7_LATCHN(ParValue)  (pst_bitCMCBCR6_CBCR7() -> CMCBCR7_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMCBCR6_CBCR7LL(ParValue) (pst_u8CMCBCR6_CBCR7() -> u8LL = (ParValue))
#define u8GetCMCBCR6_CBCR7LL() (pst_u8CMCBCR6_CBCR7() -> u8LL)
/* LH-struct byte access */
#define vSetCMCBCR6_CBCR7LH(ParValue) (pst_u8CMCBCR6_CBCR7() -> u8LH = (ParValue))
#define u8GetCMCBCR6_CBCR7LH() (pst_u8CMCBCR6_CBCR7() -> u8LH)
/* HL-struct byte access */
#define vSetCMCBCR6_CBCR7HL(ParValue) (pst_u8CMCBCR6_CBCR7() -> u8HL = (ParValue))
#define u8GetCMCBCR6_CBCR7HL() (pst_u8CMCBCR6_CBCR7() -> u8HL)
/* HH-struct byte access */
#define vSetCMCBCR6_CBCR7HH(ParValue) (pst_u8CMCBCR6_CBCR7() -> u8HH = (ParValue))
#define u8GetCMCBCR6_CBCR7HH() (pst_u8CMCBCR6_CBCR7() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMCBCR6_CBCR7L(ParValue) (pst_u16CMCBCR6_CBCR7() -> u16L = (ParValue))
#define u16GetCMCBCR6_CBCR7L() (pst_u16CMCBCR6_CBCR7() -> u16L)
#define vSetCMCBCR6_CBCR7H(ParValue) (pst_u16CMCBCR6_CBCR7() -> u16H = (ParValue))
#define u16GetCMCBCR6_CBCR7H() (pst_u16CMCBCR6_CBCR7() -> u16H)
            
/* Word access */
#define vSetCMCBCR6_CBCR7(ParValue)  (*pu32CMCBCR6_CBCR7() = (ParValue))
#define u32GetCMCBCR6_CBCR7()  (*pu32CMCBCR6_CBCR7() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMCLK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302190                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMCLK_REG__       0xC0302190U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CMCLK_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint16_t   	:5; 	 /* 3..7  bit(s) R */
  uint16_t   CMCLK_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   CMCLK_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   CMCLK_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint16_t   CMCLK_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint16_t   CMCLK_LATCHN	:1; 	 /* 13..13  bit(s) R/W */ 
  uint16_t   	:2; 	 /* 14..31  bit(s) R */                    
} CMCLK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} CMCLK_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16CMCLK_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMCLK()     ((volatile CMCLK_bit_view_st *)\
(CMCLK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMCLK()     ((volatile CMCLK_byte_view_st *)\
(CMCLK_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16CMCLK()     ((volatile u16CMCLK_halfword_view *)\
(CMCLK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMCLK_CMCLK_SEL() (pst_bitCMCLK() -> CMCLK_SEL)
#define vSetCMCLK_CMCLK_SEL(ParValue)  (pst_bitCMCLK() -> CMCLK_SEL=(ParValue))
#define biGetCMCLK_CMCLK_PU() (pst_bitCMCLK() -> CMCLK_PU)
#define vSetCMCLK_CMCLK_PU(ParValue)  (pst_bitCMCLK() -> CMCLK_PU=(ParValue))
#define biGetCMCLK_CMCLK_PD() (pst_bitCMCLK() -> CMCLK_PD)
#define vSetCMCLK_CMCLK_PD(ParValue)  (pst_bitCMCLK() -> CMCLK_PD=(ParValue))
#define biGetCMCLK_CMCLK_SMT() (pst_bitCMCLK() -> CMCLK_SMT)
#define vSetCMCLK_CMCLK_SMT(ParValue)  (pst_bitCMCLK() -> CMCLK_SMT=(ParValue))
#define biGetCMCLK_CMCLK_IMP() (pst_bitCMCLK() -> CMCLK_IMP)
#define vSetCMCLK_CMCLK_IMP(ParValue)  (pst_bitCMCLK() -> CMCLK_IMP=(ParValue))
#define biGetCMCLK_CMCLK_LATCHN() (pst_bitCMCLK() -> CMCLK_LATCHN)
#define vSetCMCLK_CMCLK_LATCHN(ParValue)  (pst_bitCMCLK() -> CMCLK_LATCHN=(ParValue))
            
/* L-struct byte access */
#define vSetCMCLKL(ParValue) (pst_u8CMCLK() -> u8L = (ParValue))
#define u8GetCMCLKL() (pst_u8CMCLK() -> u8L)
/* H-struct byte access */
#define vSetCMCLKH(ParValue) (pst_u8CMCLK() -> u8H = (ParValue))
#define u8GetCMCLKH() (pst_u8CMCLK() -> u8H)
            
/* Half-word access */ 
#define vSetCMCLK(ParValue) (*pu16CMCLK()  = (ParValue))
#define u16GetCMCLK() (*pu16CMCLK() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMFODD_HDISP                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302194                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMFODD_HDISP_REG__       0xC0302194U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMFODD_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMFODD_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMFODD_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMFODD_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMFODD_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMFODD_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMHDISP_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMHDISP_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMHDISP_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMHDISP_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMHDISP_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMHDISP_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMFODD_HDISP_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMFODD_HDISP_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMFODD_HDISP_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMFODD_HDISP_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMFODD_HDISP()     ((volatile CMFODD_HDISP_bit_view_st *)\
(CMFODD_HDISP_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMFODD_HDISP()     ((volatile CMFODD_HDISP_byte_view_st *)\
(CMFODD_HDISP_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMFODD_HDISP()     ((volatile CMFODD_HDISP_halfword_view_st *)\
(CMFODD_HDISP_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMFODD_HDISP()     ((volatile u32CMFODD_HDISP_word_view *)\
(CMFODD_HDISP_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMFODD_HDISP_CMFODD_SEL() (pst_bitCMFODD_HDISP() -> CMFODD_SEL)
#define vSetCMFODD_HDISP_CMFODD_SEL(ParValue)  (pst_bitCMFODD_HDISP() -> CMFODD_SEL=(ParValue))
#define biGetCMFODD_HDISP_CMFODD_PU() (pst_bitCMFODD_HDISP() -> CMFODD_PU)
#define vSetCMFODD_HDISP_CMFODD_PU(ParValue)  (pst_bitCMFODD_HDISP() -> CMFODD_PU=(ParValue))
#define biGetCMFODD_HDISP_CMFODD_PD() (pst_bitCMFODD_HDISP() -> CMFODD_PD)
#define vSetCMFODD_HDISP_CMFODD_PD(ParValue)  (pst_bitCMFODD_HDISP() -> CMFODD_PD=(ParValue))
#define biGetCMFODD_HDISP_CMFODD_SMT() (pst_bitCMFODD_HDISP() -> CMFODD_SMT)
#define vSetCMFODD_HDISP_CMFODD_SMT(ParValue)  (pst_bitCMFODD_HDISP() -> CMFODD_SMT=(ParValue))
#define biGetCMFODD_HDISP_CMFODD_IMP() (pst_bitCMFODD_HDISP() -> CMFODD_IMP)
#define vSetCMFODD_HDISP_CMFODD_IMP(ParValue)  (pst_bitCMFODD_HDISP() -> CMFODD_IMP=(ParValue))
#define biGetCMFODD_HDISP_CMFODD_LATCHN() (pst_bitCMFODD_HDISP() -> CMFODD_LATCHN)
#define vSetCMFODD_HDISP_CMFODD_LATCHN(ParValue)  (pst_bitCMFODD_HDISP() -> CMFODD_LATCHN=(ParValue))
#define biGetCMFODD_HDISP_CMHDISP_SEL() (pst_bitCMFODD_HDISP() -> CMHDISP_SEL)
#define vSetCMFODD_HDISP_CMHDISP_SEL(ParValue)  (pst_bitCMFODD_HDISP() -> CMHDISP_SEL=(ParValue))
#define biGetCMFODD_HDISP_CMHDISP_PU() (pst_bitCMFODD_HDISP() -> CMHDISP_PU)
#define vSetCMFODD_HDISP_CMHDISP_PU(ParValue)  (pst_bitCMFODD_HDISP() -> CMHDISP_PU=(ParValue))
#define biGetCMFODD_HDISP_CMHDISP_PD() (pst_bitCMFODD_HDISP() -> CMHDISP_PD)
#define vSetCMFODD_HDISP_CMHDISP_PD(ParValue)  (pst_bitCMFODD_HDISP() -> CMHDISP_PD=(ParValue))
#define biGetCMFODD_HDISP_CMHDISP_SMT() (pst_bitCMFODD_HDISP() -> CMHDISP_SMT)
#define vSetCMFODD_HDISP_CMHDISP_SMT(ParValue)  (pst_bitCMFODD_HDISP() -> CMHDISP_SMT=(ParValue))
#define biGetCMFODD_HDISP_CMHDISP_IMP() (pst_bitCMFODD_HDISP() -> CMHDISP_IMP)
#define vSetCMFODD_HDISP_CMHDISP_IMP(ParValue)  (pst_bitCMFODD_HDISP() -> CMHDISP_IMP=(ParValue))
#define biGetCMFODD_HDISP_CMHDISP_LATCHN() (pst_bitCMFODD_HDISP() -> CMHDISP_LATCHN)
#define vSetCMFODD_HDISP_CMHDISP_LATCHN(ParValue)  (pst_bitCMFODD_HDISP() -> CMHDISP_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMFODD_HDISPLL(ParValue) (pst_u8CMFODD_HDISP() -> u8LL = (ParValue))
#define u8GetCMFODD_HDISPLL() (pst_u8CMFODD_HDISP() -> u8LL)
/* LH-struct byte access */
#define vSetCMFODD_HDISPLH(ParValue) (pst_u8CMFODD_HDISP() -> u8LH = (ParValue))
#define u8GetCMFODD_HDISPLH() (pst_u8CMFODD_HDISP() -> u8LH)
/* HL-struct byte access */
#define vSetCMFODD_HDISPHL(ParValue) (pst_u8CMFODD_HDISP() -> u8HL = (ParValue))
#define u8GetCMFODD_HDISPHL() (pst_u8CMFODD_HDISP() -> u8HL)
/* HH-struct byte access */
#define vSetCMFODD_HDISPHH(ParValue) (pst_u8CMFODD_HDISP() -> u8HH = (ParValue))
#define u8GetCMFODD_HDISPHH() (pst_u8CMFODD_HDISP() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMFODD_HDISPL(ParValue) (pst_u16CMFODD_HDISP() -> u16L = (ParValue))
#define u16GetCMFODD_HDISPL() (pst_u16CMFODD_HDISP() -> u16L)
#define vSetCMFODD_HDISPH(ParValue) (pst_u16CMFODD_HDISP() -> u16H = (ParValue))
#define u16GetCMFODD_HDISPH() (pst_u16CMFODD_HDISP() -> u16H)
            
/* Word access */
#define vSetCMFODD_HDISP(ParValue)  (*pu32CMFODD_HDISP() = (ParValue))
#define u32GetCMFODD_HDISP()  (*pu32CMFODD_HDISP() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMHSYNC_VSYNC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302198                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMHSYNC_VSYNC_REG__       0xC0302198U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMHSYNC_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMHSYNC_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMHSYNC_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMHSYNC_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMHSYNC_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMHSYNC_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMVSYNC_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMVSYNC_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMVSYNC_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMVSYNC_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMVSYNC_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMVSYNC_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMHSYNC_VSYNC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMHSYNC_VSYNC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMHSYNC_VSYNC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMHSYNC_VSYNC_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMHSYNC_VSYNC()     ((volatile CMHSYNC_VSYNC_bit_view_st *)\
(CMHSYNC_VSYNC_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMHSYNC_VSYNC()     ((volatile CMHSYNC_VSYNC_byte_view_st *)\
(CMHSYNC_VSYNC_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMHSYNC_VSYNC()     ((volatile CMHSYNC_VSYNC_halfword_view_st *)\
(CMHSYNC_VSYNC_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMHSYNC_VSYNC()     ((volatile u32CMHSYNC_VSYNC_word_view *)\
(CMHSYNC_VSYNC_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMHSYNC_VSYNC_CMHSYNC_SEL() (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_SEL)
#define vSetCMHSYNC_VSYNC_CMHSYNC_SEL(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_SEL=(ParValue))
#define biGetCMHSYNC_VSYNC_CMHSYNC_PU() (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_PU)
#define vSetCMHSYNC_VSYNC_CMHSYNC_PU(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_PU=(ParValue))
#define biGetCMHSYNC_VSYNC_CMHSYNC_PD() (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_PD)
#define vSetCMHSYNC_VSYNC_CMHSYNC_PD(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_PD=(ParValue))
#define biGetCMHSYNC_VSYNC_CMHSYNC_SMT() (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_SMT)
#define vSetCMHSYNC_VSYNC_CMHSYNC_SMT(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_SMT=(ParValue))
#define biGetCMHSYNC_VSYNC_CMHSYNC_IMP() (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_IMP)
#define vSetCMHSYNC_VSYNC_CMHSYNC_IMP(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_IMP=(ParValue))
#define biGetCMHSYNC_VSYNC_CMHSYNC_LATCHN() (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_LATCHN)
#define vSetCMHSYNC_VSYNC_CMHSYNC_LATCHN(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMHSYNC_LATCHN=(ParValue))
#define biGetCMHSYNC_VSYNC_CMVSYNC_SEL() (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_SEL)
#define vSetCMHSYNC_VSYNC_CMVSYNC_SEL(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_SEL=(ParValue))
#define biGetCMHSYNC_VSYNC_CMVSYNC_PU() (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_PU)
#define vSetCMHSYNC_VSYNC_CMVSYNC_PU(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_PU=(ParValue))
#define biGetCMHSYNC_VSYNC_CMVSYNC_PD() (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_PD)
#define vSetCMHSYNC_VSYNC_CMVSYNC_PD(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_PD=(ParValue))
#define biGetCMHSYNC_VSYNC_CMVSYNC_SMT() (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_SMT)
#define vSetCMHSYNC_VSYNC_CMVSYNC_SMT(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_SMT=(ParValue))
#define biGetCMHSYNC_VSYNC_CMVSYNC_IMP() (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_IMP)
#define vSetCMHSYNC_VSYNC_CMVSYNC_IMP(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_IMP=(ParValue))
#define biGetCMHSYNC_VSYNC_CMVSYNC_LATCHN() (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_LATCHN)
#define vSetCMHSYNC_VSYNC_CMVSYNC_LATCHN(ParValue)  (pst_bitCMHSYNC_VSYNC() -> CMVSYNC_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMHSYNC_VSYNCLL(ParValue) (pst_u8CMHSYNC_VSYNC() -> u8LL = (ParValue))
#define u8GetCMHSYNC_VSYNCLL() (pst_u8CMHSYNC_VSYNC() -> u8LL)
/* LH-struct byte access */
#define vSetCMHSYNC_VSYNCLH(ParValue) (pst_u8CMHSYNC_VSYNC() -> u8LH = (ParValue))
#define u8GetCMHSYNC_VSYNCLH() (pst_u8CMHSYNC_VSYNC() -> u8LH)
/* HL-struct byte access */
#define vSetCMHSYNC_VSYNCHL(ParValue) (pst_u8CMHSYNC_VSYNC() -> u8HL = (ParValue))
#define u8GetCMHSYNC_VSYNCHL() (pst_u8CMHSYNC_VSYNC() -> u8HL)
/* HH-struct byte access */
#define vSetCMHSYNC_VSYNCHH(ParValue) (pst_u8CMHSYNC_VSYNC() -> u8HH = (ParValue))
#define u8GetCMHSYNC_VSYNCHH() (pst_u8CMHSYNC_VSYNC() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMHSYNC_VSYNCL(ParValue) (pst_u16CMHSYNC_VSYNC() -> u16L = (ParValue))
#define u16GetCMHSYNC_VSYNCL() (pst_u16CMHSYNC_VSYNC() -> u16L)
#define vSetCMHSYNC_VSYNCH(ParValue) (pst_u16CMHSYNC_VSYNC() -> u16H = (ParValue))
#define u16GetCMHSYNC_VSYNCH() (pst_u16CMHSYNC_VSYNC() -> u16H)
            
/* Word access */
#define vSetCMHSYNC_VSYNC(ParValue)  (*pu32CMHSYNC_VSYNC() = (ParValue))
#define u32GetCMHSYNC_VSYNC()  (*pu32CMHSYNC_VSYNC() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMY0_Y1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030219C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMY0_Y1_REG__       0xC030219CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMY0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMY0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMY0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMY0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMY0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMY0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMY1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMY1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMY1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMY1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMY1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMY1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMY0_Y1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMY0_Y1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMY0_Y1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMY0_Y1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMY0_Y1()     ((volatile CMY0_Y1_bit_view_st *)\
(CMY0_Y1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMY0_Y1()     ((volatile CMY0_Y1_byte_view_st *)\
(CMY0_Y1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMY0_Y1()     ((volatile CMY0_Y1_halfword_view_st *)\
(CMY0_Y1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMY0_Y1()     ((volatile u32CMY0_Y1_word_view *)\
(CMY0_Y1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMY0_Y1_CMY0_SEL() (pst_bitCMY0_Y1() -> CMY0_SEL)
#define vSetCMY0_Y1_CMY0_SEL(ParValue)  (pst_bitCMY0_Y1() -> CMY0_SEL=(ParValue))
#define biGetCMY0_Y1_CMY0_PU() (pst_bitCMY0_Y1() -> CMY0_PU)
#define vSetCMY0_Y1_CMY0_PU(ParValue)  (pst_bitCMY0_Y1() -> CMY0_PU=(ParValue))
#define biGetCMY0_Y1_CMY0_PD() (pst_bitCMY0_Y1() -> CMY0_PD)
#define vSetCMY0_Y1_CMY0_PD(ParValue)  (pst_bitCMY0_Y1() -> CMY0_PD=(ParValue))
#define biGetCMY0_Y1_CMY0_SMT() (pst_bitCMY0_Y1() -> CMY0_SMT)
#define vSetCMY0_Y1_CMY0_SMT(ParValue)  (pst_bitCMY0_Y1() -> CMY0_SMT=(ParValue))
#define biGetCMY0_Y1_CMY0_IMP() (pst_bitCMY0_Y1() -> CMY0_IMP)
#define vSetCMY0_Y1_CMY0_IMP(ParValue)  (pst_bitCMY0_Y1() -> CMY0_IMP=(ParValue))
#define biGetCMY0_Y1_CMY0_LATCHN() (pst_bitCMY0_Y1() -> CMY0_LATCHN)
#define vSetCMY0_Y1_CMY0_LATCHN(ParValue)  (pst_bitCMY0_Y1() -> CMY0_LATCHN=(ParValue))
#define biGetCMY0_Y1_CMY1_SEL() (pst_bitCMY0_Y1() -> CMY1_SEL)
#define vSetCMY0_Y1_CMY1_SEL(ParValue)  (pst_bitCMY0_Y1() -> CMY1_SEL=(ParValue))
#define biGetCMY0_Y1_CMY1_PU() (pst_bitCMY0_Y1() -> CMY1_PU)
#define vSetCMY0_Y1_CMY1_PU(ParValue)  (pst_bitCMY0_Y1() -> CMY1_PU=(ParValue))
#define biGetCMY0_Y1_CMY1_PD() (pst_bitCMY0_Y1() -> CMY1_PD)
#define vSetCMY0_Y1_CMY1_PD(ParValue)  (pst_bitCMY0_Y1() -> CMY1_PD=(ParValue))
#define biGetCMY0_Y1_CMY1_SMT() (pst_bitCMY0_Y1() -> CMY1_SMT)
#define vSetCMY0_Y1_CMY1_SMT(ParValue)  (pst_bitCMY0_Y1() -> CMY1_SMT=(ParValue))
#define biGetCMY0_Y1_CMY1_IMP() (pst_bitCMY0_Y1() -> CMY1_IMP)
#define vSetCMY0_Y1_CMY1_IMP(ParValue)  (pst_bitCMY0_Y1() -> CMY1_IMP=(ParValue))
#define biGetCMY0_Y1_CMY1_LATCHN() (pst_bitCMY0_Y1() -> CMY1_LATCHN)
#define vSetCMY0_Y1_CMY1_LATCHN(ParValue)  (pst_bitCMY0_Y1() -> CMY1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMY0_Y1LL(ParValue) (pst_u8CMY0_Y1() -> u8LL = (ParValue))
#define u8GetCMY0_Y1LL() (pst_u8CMY0_Y1() -> u8LL)
/* LH-struct byte access */
#define vSetCMY0_Y1LH(ParValue) (pst_u8CMY0_Y1() -> u8LH = (ParValue))
#define u8GetCMY0_Y1LH() (pst_u8CMY0_Y1() -> u8LH)
/* HL-struct byte access */
#define vSetCMY0_Y1HL(ParValue) (pst_u8CMY0_Y1() -> u8HL = (ParValue))
#define u8GetCMY0_Y1HL() (pst_u8CMY0_Y1() -> u8HL)
/* HH-struct byte access */
#define vSetCMY0_Y1HH(ParValue) (pst_u8CMY0_Y1() -> u8HH = (ParValue))
#define u8GetCMY0_Y1HH() (pst_u8CMY0_Y1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMY0_Y1L(ParValue) (pst_u16CMY0_Y1() -> u16L = (ParValue))
#define u16GetCMY0_Y1L() (pst_u16CMY0_Y1() -> u16L)
#define vSetCMY0_Y1H(ParValue) (pst_u16CMY0_Y1() -> u16H = (ParValue))
#define u16GetCMY0_Y1H() (pst_u16CMY0_Y1() -> u16H)
            
/* Word access */
#define vSetCMY0_Y1(ParValue)  (*pu32CMY0_Y1() = (ParValue))
#define u32GetCMY0_Y1()  (*pu32CMY0_Y1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMY2_Y3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021A0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMY2_Y3_REG__       0xC03021A0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMY2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMY2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMY2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMY2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMY2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMY2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMY3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMY3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMY3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMY3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMY3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMY3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMY2_Y3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMY2_Y3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMY2_Y3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMY2_Y3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMY2_Y3()     ((volatile CMY2_Y3_bit_view_st *)\
(CMY2_Y3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMY2_Y3()     ((volatile CMY2_Y3_byte_view_st *)\
(CMY2_Y3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMY2_Y3()     ((volatile CMY2_Y3_halfword_view_st *)\
(CMY2_Y3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMY2_Y3()     ((volatile u32CMY2_Y3_word_view *)\
(CMY2_Y3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMY2_Y3_CMY2_SEL() (pst_bitCMY2_Y3() -> CMY2_SEL)
#define vSetCMY2_Y3_CMY2_SEL(ParValue)  (pst_bitCMY2_Y3() -> CMY2_SEL=(ParValue))
#define biGetCMY2_Y3_CMY2_PU() (pst_bitCMY2_Y3() -> CMY2_PU)
#define vSetCMY2_Y3_CMY2_PU(ParValue)  (pst_bitCMY2_Y3() -> CMY2_PU=(ParValue))
#define biGetCMY2_Y3_CMY2_PD() (pst_bitCMY2_Y3() -> CMY2_PD)
#define vSetCMY2_Y3_CMY2_PD(ParValue)  (pst_bitCMY2_Y3() -> CMY2_PD=(ParValue))
#define biGetCMY2_Y3_CMY2_SMT() (pst_bitCMY2_Y3() -> CMY2_SMT)
#define vSetCMY2_Y3_CMY2_SMT(ParValue)  (pst_bitCMY2_Y3() -> CMY2_SMT=(ParValue))
#define biGetCMY2_Y3_CMY2_IMP() (pst_bitCMY2_Y3() -> CMY2_IMP)
#define vSetCMY2_Y3_CMY2_IMP(ParValue)  (pst_bitCMY2_Y3() -> CMY2_IMP=(ParValue))
#define biGetCMY2_Y3_CMY2_LATCHN() (pst_bitCMY2_Y3() -> CMY2_LATCHN)
#define vSetCMY2_Y3_CMY2_LATCHN(ParValue)  (pst_bitCMY2_Y3() -> CMY2_LATCHN=(ParValue))
#define biGetCMY2_Y3_CMY3_SEL() (pst_bitCMY2_Y3() -> CMY3_SEL)
#define vSetCMY2_Y3_CMY3_SEL(ParValue)  (pst_bitCMY2_Y3() -> CMY3_SEL=(ParValue))
#define biGetCMY2_Y3_CMY3_PU() (pst_bitCMY2_Y3() -> CMY3_PU)
#define vSetCMY2_Y3_CMY3_PU(ParValue)  (pst_bitCMY2_Y3() -> CMY3_PU=(ParValue))
#define biGetCMY2_Y3_CMY3_PD() (pst_bitCMY2_Y3() -> CMY3_PD)
#define vSetCMY2_Y3_CMY3_PD(ParValue)  (pst_bitCMY2_Y3() -> CMY3_PD=(ParValue))
#define biGetCMY2_Y3_CMY3_SMT() (pst_bitCMY2_Y3() -> CMY3_SMT)
#define vSetCMY2_Y3_CMY3_SMT(ParValue)  (pst_bitCMY2_Y3() -> CMY3_SMT=(ParValue))
#define biGetCMY2_Y3_CMY3_IMP() (pst_bitCMY2_Y3() -> CMY3_IMP)
#define vSetCMY2_Y3_CMY3_IMP(ParValue)  (pst_bitCMY2_Y3() -> CMY3_IMP=(ParValue))
#define biGetCMY2_Y3_CMY3_LATCHN() (pst_bitCMY2_Y3() -> CMY3_LATCHN)
#define vSetCMY2_Y3_CMY3_LATCHN(ParValue)  (pst_bitCMY2_Y3() -> CMY3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMY2_Y3LL(ParValue) (pst_u8CMY2_Y3() -> u8LL = (ParValue))
#define u8GetCMY2_Y3LL() (pst_u8CMY2_Y3() -> u8LL)
/* LH-struct byte access */
#define vSetCMY2_Y3LH(ParValue) (pst_u8CMY2_Y3() -> u8LH = (ParValue))
#define u8GetCMY2_Y3LH() (pst_u8CMY2_Y3() -> u8LH)
/* HL-struct byte access */
#define vSetCMY2_Y3HL(ParValue) (pst_u8CMY2_Y3() -> u8HL = (ParValue))
#define u8GetCMY2_Y3HL() (pst_u8CMY2_Y3() -> u8HL)
/* HH-struct byte access */
#define vSetCMY2_Y3HH(ParValue) (pst_u8CMY2_Y3() -> u8HH = (ParValue))
#define u8GetCMY2_Y3HH() (pst_u8CMY2_Y3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMY2_Y3L(ParValue) (pst_u16CMY2_Y3() -> u16L = (ParValue))
#define u16GetCMY2_Y3L() (pst_u16CMY2_Y3() -> u16L)
#define vSetCMY2_Y3H(ParValue) (pst_u16CMY2_Y3() -> u16H = (ParValue))
#define u16GetCMY2_Y3H() (pst_u16CMY2_Y3() -> u16H)
            
/* Word access */
#define vSetCMY2_Y3(ParValue)  (*pu32CMY2_Y3() = (ParValue))
#define u32GetCMY2_Y3()  (*pu32CMY2_Y3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMY4_Y5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021A4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMY4_Y5_REG__       0xC03021A4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMY4_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMY4_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMY4_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMY4_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMY4_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMY4_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMY5_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMY5_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMY5_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMY5_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMY5_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMY5_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMY4_Y5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMY4_Y5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMY4_Y5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMY4_Y5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMY4_Y5()     ((volatile CMY4_Y5_bit_view_st *)\
(CMY4_Y5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMY4_Y5()     ((volatile CMY4_Y5_byte_view_st *)\
(CMY4_Y5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMY4_Y5()     ((volatile CMY4_Y5_halfword_view_st *)\
(CMY4_Y5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMY4_Y5()     ((volatile u32CMY4_Y5_word_view *)\
(CMY4_Y5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMY4_Y5_CMY4_SEL() (pst_bitCMY4_Y5() -> CMY4_SEL)
#define vSetCMY4_Y5_CMY4_SEL(ParValue)  (pst_bitCMY4_Y5() -> CMY4_SEL=(ParValue))
#define biGetCMY4_Y5_CMY4_PU() (pst_bitCMY4_Y5() -> CMY4_PU)
#define vSetCMY4_Y5_CMY4_PU(ParValue)  (pst_bitCMY4_Y5() -> CMY4_PU=(ParValue))
#define biGetCMY4_Y5_CMY4_PD() (pst_bitCMY4_Y5() -> CMY4_PD)
#define vSetCMY4_Y5_CMY4_PD(ParValue)  (pst_bitCMY4_Y5() -> CMY4_PD=(ParValue))
#define biGetCMY4_Y5_CMY4_SMT() (pst_bitCMY4_Y5() -> CMY4_SMT)
#define vSetCMY4_Y5_CMY4_SMT(ParValue)  (pst_bitCMY4_Y5() -> CMY4_SMT=(ParValue))
#define biGetCMY4_Y5_CMY4_IMP() (pst_bitCMY4_Y5() -> CMY4_IMP)
#define vSetCMY4_Y5_CMY4_IMP(ParValue)  (pst_bitCMY4_Y5() -> CMY4_IMP=(ParValue))
#define biGetCMY4_Y5_CMY4_LATCHN() (pst_bitCMY4_Y5() -> CMY4_LATCHN)
#define vSetCMY4_Y5_CMY4_LATCHN(ParValue)  (pst_bitCMY4_Y5() -> CMY4_LATCHN=(ParValue))
#define biGetCMY4_Y5_CMY5_SEL() (pst_bitCMY4_Y5() -> CMY5_SEL)
#define vSetCMY4_Y5_CMY5_SEL(ParValue)  (pst_bitCMY4_Y5() -> CMY5_SEL=(ParValue))
#define biGetCMY4_Y5_CMY5_PU() (pst_bitCMY4_Y5() -> CMY5_PU)
#define vSetCMY4_Y5_CMY5_PU(ParValue)  (pst_bitCMY4_Y5() -> CMY5_PU=(ParValue))
#define biGetCMY4_Y5_CMY5_PD() (pst_bitCMY4_Y5() -> CMY5_PD)
#define vSetCMY4_Y5_CMY5_PD(ParValue)  (pst_bitCMY4_Y5() -> CMY5_PD=(ParValue))
#define biGetCMY4_Y5_CMY5_SMT() (pst_bitCMY4_Y5() -> CMY5_SMT)
#define vSetCMY4_Y5_CMY5_SMT(ParValue)  (pst_bitCMY4_Y5() -> CMY5_SMT=(ParValue))
#define biGetCMY4_Y5_CMY5_IMP() (pst_bitCMY4_Y5() -> CMY5_IMP)
#define vSetCMY4_Y5_CMY5_IMP(ParValue)  (pst_bitCMY4_Y5() -> CMY5_IMP=(ParValue))
#define biGetCMY4_Y5_CMY5_LATCHN() (pst_bitCMY4_Y5() -> CMY5_LATCHN)
#define vSetCMY4_Y5_CMY5_LATCHN(ParValue)  (pst_bitCMY4_Y5() -> CMY5_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMY4_Y5LL(ParValue) (pst_u8CMY4_Y5() -> u8LL = (ParValue))
#define u8GetCMY4_Y5LL() (pst_u8CMY4_Y5() -> u8LL)
/* LH-struct byte access */
#define vSetCMY4_Y5LH(ParValue) (pst_u8CMY4_Y5() -> u8LH = (ParValue))
#define u8GetCMY4_Y5LH() (pst_u8CMY4_Y5() -> u8LH)
/* HL-struct byte access */
#define vSetCMY4_Y5HL(ParValue) (pst_u8CMY4_Y5() -> u8HL = (ParValue))
#define u8GetCMY4_Y5HL() (pst_u8CMY4_Y5() -> u8HL)
/* HH-struct byte access */
#define vSetCMY4_Y5HH(ParValue) (pst_u8CMY4_Y5() -> u8HH = (ParValue))
#define u8GetCMY4_Y5HH() (pst_u8CMY4_Y5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMY4_Y5L(ParValue) (pst_u16CMY4_Y5() -> u16L = (ParValue))
#define u16GetCMY4_Y5L() (pst_u16CMY4_Y5() -> u16L)
#define vSetCMY4_Y5H(ParValue) (pst_u16CMY4_Y5() -> u16H = (ParValue))
#define u16GetCMY4_Y5H() (pst_u16CMY4_Y5() -> u16H)
            
/* Word access */
#define vSetCMY4_Y5(ParValue)  (*pu32CMY4_Y5() = (ParValue))
#define u32GetCMY4_Y5()  (*pu32CMY4_Y5() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMY6_Y7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021A8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMY6_Y7_REG__       0xC03021A8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMY6_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMY6_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMY6_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMY6_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMY6_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMY6_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMY7_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMY7_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMY7_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMY7_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMY7_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMY7_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMY6_Y7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMY6_Y7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMY6_Y7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMY6_Y7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMY6_Y7()     ((volatile CMY6_Y7_bit_view_st *)\
(CMY6_Y7_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMY6_Y7()     ((volatile CMY6_Y7_byte_view_st *)\
(CMY6_Y7_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMY6_Y7()     ((volatile CMY6_Y7_halfword_view_st *)\
(CMY6_Y7_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMY6_Y7()     ((volatile u32CMY6_Y7_word_view *)\
(CMY6_Y7_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMY6_Y7_CMY6_SEL() (pst_bitCMY6_Y7() -> CMY6_SEL)
#define vSetCMY6_Y7_CMY6_SEL(ParValue)  (pst_bitCMY6_Y7() -> CMY6_SEL=(ParValue))
#define biGetCMY6_Y7_CMY6_PU() (pst_bitCMY6_Y7() -> CMY6_PU)
#define vSetCMY6_Y7_CMY6_PU(ParValue)  (pst_bitCMY6_Y7() -> CMY6_PU=(ParValue))
#define biGetCMY6_Y7_CMY6_PD() (pst_bitCMY6_Y7() -> CMY6_PD)
#define vSetCMY6_Y7_CMY6_PD(ParValue)  (pst_bitCMY6_Y7() -> CMY6_PD=(ParValue))
#define biGetCMY6_Y7_CMY6_SMT() (pst_bitCMY6_Y7() -> CMY6_SMT)
#define vSetCMY6_Y7_CMY6_SMT(ParValue)  (pst_bitCMY6_Y7() -> CMY6_SMT=(ParValue))
#define biGetCMY6_Y7_CMY6_IMP() (pst_bitCMY6_Y7() -> CMY6_IMP)
#define vSetCMY6_Y7_CMY6_IMP(ParValue)  (pst_bitCMY6_Y7() -> CMY6_IMP=(ParValue))
#define biGetCMY6_Y7_CMY6_LATCHN() (pst_bitCMY6_Y7() -> CMY6_LATCHN)
#define vSetCMY6_Y7_CMY6_LATCHN(ParValue)  (pst_bitCMY6_Y7() -> CMY6_LATCHN=(ParValue))
#define biGetCMY6_Y7_CMY7_SEL() (pst_bitCMY6_Y7() -> CMY7_SEL)
#define vSetCMY6_Y7_CMY7_SEL(ParValue)  (pst_bitCMY6_Y7() -> CMY7_SEL=(ParValue))
#define biGetCMY6_Y7_CMY7_PU() (pst_bitCMY6_Y7() -> CMY7_PU)
#define vSetCMY6_Y7_CMY7_PU(ParValue)  (pst_bitCMY6_Y7() -> CMY7_PU=(ParValue))
#define biGetCMY6_Y7_CMY7_PD() (pst_bitCMY6_Y7() -> CMY7_PD)
#define vSetCMY6_Y7_CMY7_PD(ParValue)  (pst_bitCMY6_Y7() -> CMY7_PD=(ParValue))
#define biGetCMY6_Y7_CMY7_SMT() (pst_bitCMY6_Y7() -> CMY7_SMT)
#define vSetCMY6_Y7_CMY7_SMT(ParValue)  (pst_bitCMY6_Y7() -> CMY7_SMT=(ParValue))
#define biGetCMY6_Y7_CMY7_IMP() (pst_bitCMY6_Y7() -> CMY7_IMP)
#define vSetCMY6_Y7_CMY7_IMP(ParValue)  (pst_bitCMY6_Y7() -> CMY7_IMP=(ParValue))
#define biGetCMY6_Y7_CMY7_LATCHN() (pst_bitCMY6_Y7() -> CMY7_LATCHN)
#define vSetCMY6_Y7_CMY7_LATCHN(ParValue)  (pst_bitCMY6_Y7() -> CMY7_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMY6_Y7LL(ParValue) (pst_u8CMY6_Y7() -> u8LL = (ParValue))
#define u8GetCMY6_Y7LL() (pst_u8CMY6_Y7() -> u8LL)
/* LH-struct byte access */
#define vSetCMY6_Y7LH(ParValue) (pst_u8CMY6_Y7() -> u8LH = (ParValue))
#define u8GetCMY6_Y7LH() (pst_u8CMY6_Y7() -> u8LH)
/* HL-struct byte access */
#define vSetCMY6_Y7HL(ParValue) (pst_u8CMY6_Y7() -> u8HL = (ParValue))
#define u8GetCMY6_Y7HL() (pst_u8CMY6_Y7() -> u8HL)
/* HH-struct byte access */
#define vSetCMY6_Y7HH(ParValue) (pst_u8CMY6_Y7() -> u8HH = (ParValue))
#define u8GetCMY6_Y7HH() (pst_u8CMY6_Y7() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMY6_Y7L(ParValue) (pst_u16CMY6_Y7() -> u16L = (ParValue))
#define u16GetCMY6_Y7L() (pst_u16CMY6_Y7() -> u16L)
#define vSetCMY6_Y7H(ParValue) (pst_u16CMY6_Y7() -> u16H = (ParValue))
#define u16GetCMY6_Y7H() (pst_u16CMY6_Y7() -> u16H)
            
/* Word access */
#define vSetCMY6_Y7(ParValue)  (*pu32CMY6_Y7() = (ParValue))
#define u32GetCMY6_Y7()  (*pu32CMY6_Y7() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMRGB0_RGB1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021AC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMRGB0_RGB1_REG__       0xC03021ACU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMRGB0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMRGB0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMRGB0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMRGB0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMRGB0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMRGB0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMRGB1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMRGB1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMRGB1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMRGB1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMRGB1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMRGB1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMRGB0_RGB1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMRGB0_RGB1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMRGB0_RGB1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMRGB0_RGB1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMRGB0_RGB1()     ((volatile CMRGB0_RGB1_bit_view_st *)\
(CMRGB0_RGB1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMRGB0_RGB1()     ((volatile CMRGB0_RGB1_byte_view_st *)\
(CMRGB0_RGB1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMRGB0_RGB1()     ((volatile CMRGB0_RGB1_halfword_view_st *)\
(CMRGB0_RGB1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMRGB0_RGB1()     ((volatile u32CMRGB0_RGB1_word_view *)\
(CMRGB0_RGB1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMRGB0_RGB1_CMRGB0_SEL() (pst_bitCMRGB0_RGB1() -> CMRGB0_SEL)
#define vSetCMRGB0_RGB1_CMRGB0_SEL(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB0_SEL=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB0_PU() (pst_bitCMRGB0_RGB1() -> CMRGB0_PU)
#define vSetCMRGB0_RGB1_CMRGB0_PU(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB0_PU=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB0_PD() (pst_bitCMRGB0_RGB1() -> CMRGB0_PD)
#define vSetCMRGB0_RGB1_CMRGB0_PD(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB0_PD=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB0_SMT() (pst_bitCMRGB0_RGB1() -> CMRGB0_SMT)
#define vSetCMRGB0_RGB1_CMRGB0_SMT(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB0_SMT=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB0_IMP() (pst_bitCMRGB0_RGB1() -> CMRGB0_IMP)
#define vSetCMRGB0_RGB1_CMRGB0_IMP(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB0_IMP=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB0_LATCHN() (pst_bitCMRGB0_RGB1() -> CMRGB0_LATCHN)
#define vSetCMRGB0_RGB1_CMRGB0_LATCHN(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB0_LATCHN=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB1_SEL() (pst_bitCMRGB0_RGB1() -> CMRGB1_SEL)
#define vSetCMRGB0_RGB1_CMRGB1_SEL(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB1_SEL=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB1_PU() (pst_bitCMRGB0_RGB1() -> CMRGB1_PU)
#define vSetCMRGB0_RGB1_CMRGB1_PU(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB1_PU=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB1_PD() (pst_bitCMRGB0_RGB1() -> CMRGB1_PD)
#define vSetCMRGB0_RGB1_CMRGB1_PD(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB1_PD=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB1_SMT() (pst_bitCMRGB0_RGB1() -> CMRGB1_SMT)
#define vSetCMRGB0_RGB1_CMRGB1_SMT(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB1_SMT=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB1_IMP() (pst_bitCMRGB0_RGB1() -> CMRGB1_IMP)
#define vSetCMRGB0_RGB1_CMRGB1_IMP(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB1_IMP=(ParValue))
#define biGetCMRGB0_RGB1_CMRGB1_LATCHN() (pst_bitCMRGB0_RGB1() -> CMRGB1_LATCHN)
#define vSetCMRGB0_RGB1_CMRGB1_LATCHN(ParValue)  (pst_bitCMRGB0_RGB1() -> CMRGB1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMRGB0_RGB1LL(ParValue) (pst_u8CMRGB0_RGB1() -> u8LL = (ParValue))
#define u8GetCMRGB0_RGB1LL() (pst_u8CMRGB0_RGB1() -> u8LL)
/* LH-struct byte access */
#define vSetCMRGB0_RGB1LH(ParValue) (pst_u8CMRGB0_RGB1() -> u8LH = (ParValue))
#define u8GetCMRGB0_RGB1LH() (pst_u8CMRGB0_RGB1() -> u8LH)
/* HL-struct byte access */
#define vSetCMRGB0_RGB1HL(ParValue) (pst_u8CMRGB0_RGB1() -> u8HL = (ParValue))
#define u8GetCMRGB0_RGB1HL() (pst_u8CMRGB0_RGB1() -> u8HL)
/* HH-struct byte access */
#define vSetCMRGB0_RGB1HH(ParValue) (pst_u8CMRGB0_RGB1() -> u8HH = (ParValue))
#define u8GetCMRGB0_RGB1HH() (pst_u8CMRGB0_RGB1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMRGB0_RGB1L(ParValue) (pst_u16CMRGB0_RGB1() -> u16L = (ParValue))
#define u16GetCMRGB0_RGB1L() (pst_u16CMRGB0_RGB1() -> u16L)
#define vSetCMRGB0_RGB1H(ParValue) (pst_u16CMRGB0_RGB1() -> u16H = (ParValue))
#define u16GetCMRGB0_RGB1H() (pst_u16CMRGB0_RGB1() -> u16H)
            
/* Word access */
#define vSetCMRGB0_RGB1(ParValue)  (*pu32CMRGB0_RGB1() = (ParValue))
#define u32GetCMRGB0_RGB1()  (*pu32CMRGB0_RGB1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMRGB2_RGB3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021B0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMRGB2_RGB3_REG__       0xC03021B0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMRGB2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMRGB2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMRGB2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMRGB2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMRGB2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMRGB2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMRGB3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMRGB3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMRGB3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMRGB3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMRGB3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMRGB3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMRGB2_RGB3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMRGB2_RGB3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMRGB2_RGB3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMRGB2_RGB3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMRGB2_RGB3()     ((volatile CMRGB2_RGB3_bit_view_st *)\
(CMRGB2_RGB3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMRGB2_RGB3()     ((volatile CMRGB2_RGB3_byte_view_st *)\
(CMRGB2_RGB3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMRGB2_RGB3()     ((volatile CMRGB2_RGB3_halfword_view_st *)\
(CMRGB2_RGB3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMRGB2_RGB3()     ((volatile u32CMRGB2_RGB3_word_view *)\
(CMRGB2_RGB3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMRGB2_RGB3_CMRGB2_SEL() (pst_bitCMRGB2_RGB3() -> CMRGB2_SEL)
#define vSetCMRGB2_RGB3_CMRGB2_SEL(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB2_SEL=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB2_PU() (pst_bitCMRGB2_RGB3() -> CMRGB2_PU)
#define vSetCMRGB2_RGB3_CMRGB2_PU(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB2_PU=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB2_PD() (pst_bitCMRGB2_RGB3() -> CMRGB2_PD)
#define vSetCMRGB2_RGB3_CMRGB2_PD(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB2_PD=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB2_SMT() (pst_bitCMRGB2_RGB3() -> CMRGB2_SMT)
#define vSetCMRGB2_RGB3_CMRGB2_SMT(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB2_SMT=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB2_IMP() (pst_bitCMRGB2_RGB3() -> CMRGB2_IMP)
#define vSetCMRGB2_RGB3_CMRGB2_IMP(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB2_IMP=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB2_LATCHN() (pst_bitCMRGB2_RGB3() -> CMRGB2_LATCHN)
#define vSetCMRGB2_RGB3_CMRGB2_LATCHN(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB2_LATCHN=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB3_SEL() (pst_bitCMRGB2_RGB3() -> CMRGB3_SEL)
#define vSetCMRGB2_RGB3_CMRGB3_SEL(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB3_SEL=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB3_PU() (pst_bitCMRGB2_RGB3() -> CMRGB3_PU)
#define vSetCMRGB2_RGB3_CMRGB3_PU(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB3_PU=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB3_PD() (pst_bitCMRGB2_RGB3() -> CMRGB3_PD)
#define vSetCMRGB2_RGB3_CMRGB3_PD(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB3_PD=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB3_SMT() (pst_bitCMRGB2_RGB3() -> CMRGB3_SMT)
#define vSetCMRGB2_RGB3_CMRGB3_SMT(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB3_SMT=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB3_IMP() (pst_bitCMRGB2_RGB3() -> CMRGB3_IMP)
#define vSetCMRGB2_RGB3_CMRGB3_IMP(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB3_IMP=(ParValue))
#define biGetCMRGB2_RGB3_CMRGB3_LATCHN() (pst_bitCMRGB2_RGB3() -> CMRGB3_LATCHN)
#define vSetCMRGB2_RGB3_CMRGB3_LATCHN(ParValue)  (pst_bitCMRGB2_RGB3() -> CMRGB3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMRGB2_RGB3LL(ParValue) (pst_u8CMRGB2_RGB3() -> u8LL = (ParValue))
#define u8GetCMRGB2_RGB3LL() (pst_u8CMRGB2_RGB3() -> u8LL)
/* LH-struct byte access */
#define vSetCMRGB2_RGB3LH(ParValue) (pst_u8CMRGB2_RGB3() -> u8LH = (ParValue))
#define u8GetCMRGB2_RGB3LH() (pst_u8CMRGB2_RGB3() -> u8LH)
/* HL-struct byte access */
#define vSetCMRGB2_RGB3HL(ParValue) (pst_u8CMRGB2_RGB3() -> u8HL = (ParValue))
#define u8GetCMRGB2_RGB3HL() (pst_u8CMRGB2_RGB3() -> u8HL)
/* HH-struct byte access */
#define vSetCMRGB2_RGB3HH(ParValue) (pst_u8CMRGB2_RGB3() -> u8HH = (ParValue))
#define u8GetCMRGB2_RGB3HH() (pst_u8CMRGB2_RGB3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMRGB2_RGB3L(ParValue) (pst_u16CMRGB2_RGB3() -> u16L = (ParValue))
#define u16GetCMRGB2_RGB3L() (pst_u16CMRGB2_RGB3() -> u16L)
#define vSetCMRGB2_RGB3H(ParValue) (pst_u16CMRGB2_RGB3() -> u16H = (ParValue))
#define u16GetCMRGB2_RGB3H() (pst_u16CMRGB2_RGB3() -> u16H)
            
/* Word access */
#define vSetCMRGB2_RGB3(ParValue)  (*pu32CMRGB2_RGB3() = (ParValue))
#define u32GetCMRGB2_RGB3()  (*pu32CMRGB2_RGB3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMRGB4_RGB5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021B4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMRGB4_RGB5_REG__       0xC03021B4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMRGB4_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMRGB4_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMRGB4_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMRGB4_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMRGB4_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMRGB4_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMRGB5_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMRGB5_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMRGB5_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMRGB5_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMRGB5_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMRGB5_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMRGB4_RGB5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMRGB4_RGB5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMRGB4_RGB5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMRGB4_RGB5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMRGB4_RGB5()     ((volatile CMRGB4_RGB5_bit_view_st *)\
(CMRGB4_RGB5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMRGB4_RGB5()     ((volatile CMRGB4_RGB5_byte_view_st *)\
(CMRGB4_RGB5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMRGB4_RGB5()     ((volatile CMRGB4_RGB5_halfword_view_st *)\
(CMRGB4_RGB5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMRGB4_RGB5()     ((volatile u32CMRGB4_RGB5_word_view *)\
(CMRGB4_RGB5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMRGB4_RGB5_CMRGB4_SEL() (pst_bitCMRGB4_RGB5() -> CMRGB4_SEL)
#define vSetCMRGB4_RGB5_CMRGB4_SEL(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB4_SEL=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB4_PU() (pst_bitCMRGB4_RGB5() -> CMRGB4_PU)
#define vSetCMRGB4_RGB5_CMRGB4_PU(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB4_PU=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB4_PD() (pst_bitCMRGB4_RGB5() -> CMRGB4_PD)
#define vSetCMRGB4_RGB5_CMRGB4_PD(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB4_PD=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB4_SMT() (pst_bitCMRGB4_RGB5() -> CMRGB4_SMT)
#define vSetCMRGB4_RGB5_CMRGB4_SMT(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB4_SMT=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB4_IMP() (pst_bitCMRGB4_RGB5() -> CMRGB4_IMP)
#define vSetCMRGB4_RGB5_CMRGB4_IMP(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB4_IMP=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB4_LATCHN() (pst_bitCMRGB4_RGB5() -> CMRGB4_LATCHN)
#define vSetCMRGB4_RGB5_CMRGB4_LATCHN(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB4_LATCHN=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB5_SEL() (pst_bitCMRGB4_RGB5() -> CMRGB5_SEL)
#define vSetCMRGB4_RGB5_CMRGB5_SEL(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB5_SEL=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB5_PU() (pst_bitCMRGB4_RGB5() -> CMRGB5_PU)
#define vSetCMRGB4_RGB5_CMRGB5_PU(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB5_PU=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB5_PD() (pst_bitCMRGB4_RGB5() -> CMRGB5_PD)
#define vSetCMRGB4_RGB5_CMRGB5_PD(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB5_PD=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB5_SMT() (pst_bitCMRGB4_RGB5() -> CMRGB5_SMT)
#define vSetCMRGB4_RGB5_CMRGB5_SMT(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB5_SMT=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB5_IMP() (pst_bitCMRGB4_RGB5() -> CMRGB5_IMP)
#define vSetCMRGB4_RGB5_CMRGB5_IMP(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB5_IMP=(ParValue))
#define biGetCMRGB4_RGB5_CMRGB5_LATCHN() (pst_bitCMRGB4_RGB5() -> CMRGB5_LATCHN)
#define vSetCMRGB4_RGB5_CMRGB5_LATCHN(ParValue)  (pst_bitCMRGB4_RGB5() -> CMRGB5_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMRGB4_RGB5LL(ParValue) (pst_u8CMRGB4_RGB5() -> u8LL = (ParValue))
#define u8GetCMRGB4_RGB5LL() (pst_u8CMRGB4_RGB5() -> u8LL)
/* LH-struct byte access */
#define vSetCMRGB4_RGB5LH(ParValue) (pst_u8CMRGB4_RGB5() -> u8LH = (ParValue))
#define u8GetCMRGB4_RGB5LH() (pst_u8CMRGB4_RGB5() -> u8LH)
/* HL-struct byte access */
#define vSetCMRGB4_RGB5HL(ParValue) (pst_u8CMRGB4_RGB5() -> u8HL = (ParValue))
#define u8GetCMRGB4_RGB5HL() (pst_u8CMRGB4_RGB5() -> u8HL)
/* HH-struct byte access */
#define vSetCMRGB4_RGB5HH(ParValue) (pst_u8CMRGB4_RGB5() -> u8HH = (ParValue))
#define u8GetCMRGB4_RGB5HH() (pst_u8CMRGB4_RGB5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMRGB4_RGB5L(ParValue) (pst_u16CMRGB4_RGB5() -> u16L = (ParValue))
#define u16GetCMRGB4_RGB5L() (pst_u16CMRGB4_RGB5() -> u16L)
#define vSetCMRGB4_RGB5H(ParValue) (pst_u16CMRGB4_RGB5() -> u16H = (ParValue))
#define u16GetCMRGB4_RGB5H() (pst_u16CMRGB4_RGB5() -> u16H)
            
/* Word access */
#define vSetCMRGB4_RGB5(ParValue)  (*pu32CMRGB4_RGB5() = (ParValue))
#define u32GetCMRGB4_RGB5()  (*pu32CMRGB4_RGB5() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMRGB6_RGB7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021B8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMRGB6_RGB7_REG__       0xC03021B8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMRGB6_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CMRGB6_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CMRGB6_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   CMRGB6_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CMRGB6_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   CMRGB6_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CMRGB7_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CMRGB7_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CMRGB7_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CMRGB7_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CMRGB7_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CMRGB7_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CMRGB6_RGB7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CMRGB6_RGB7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CMRGB6_RGB7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CMRGB6_RGB7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMRGB6_RGB7()     ((volatile CMRGB6_RGB7_bit_view_st *)\
(CMRGB6_RGB7_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CMRGB6_RGB7()     ((volatile CMRGB6_RGB7_byte_view_st *)\
(CMRGB6_RGB7_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CMRGB6_RGB7()     ((volatile CMRGB6_RGB7_halfword_view_st *)\
(CMRGB6_RGB7_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CMRGB6_RGB7()     ((volatile u32CMRGB6_RGB7_word_view *)\
(CMRGB6_RGB7_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCMRGB6_RGB7_CMRGB6_SEL() (pst_bitCMRGB6_RGB7() -> CMRGB6_SEL)
#define vSetCMRGB6_RGB7_CMRGB6_SEL(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB6_SEL=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB6_PU() (pst_bitCMRGB6_RGB7() -> CMRGB6_PU)
#define vSetCMRGB6_RGB7_CMRGB6_PU(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB6_PU=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB6_PD() (pst_bitCMRGB6_RGB7() -> CMRGB6_PD)
#define vSetCMRGB6_RGB7_CMRGB6_PD(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB6_PD=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB6_SMT() (pst_bitCMRGB6_RGB7() -> CMRGB6_SMT)
#define vSetCMRGB6_RGB7_CMRGB6_SMT(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB6_SMT=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB6_IMP() (pst_bitCMRGB6_RGB7() -> CMRGB6_IMP)
#define vSetCMRGB6_RGB7_CMRGB6_IMP(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB6_IMP=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB6_LATCHN() (pst_bitCMRGB6_RGB7() -> CMRGB6_LATCHN)
#define vSetCMRGB6_RGB7_CMRGB6_LATCHN(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB6_LATCHN=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB7_SEL() (pst_bitCMRGB6_RGB7() -> CMRGB7_SEL)
#define vSetCMRGB6_RGB7_CMRGB7_SEL(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB7_SEL=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB7_PU() (pst_bitCMRGB6_RGB7() -> CMRGB7_PU)
#define vSetCMRGB6_RGB7_CMRGB7_PU(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB7_PU=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB7_PD() (pst_bitCMRGB6_RGB7() -> CMRGB7_PD)
#define vSetCMRGB6_RGB7_CMRGB7_PD(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB7_PD=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB7_SMT() (pst_bitCMRGB6_RGB7() -> CMRGB7_SMT)
#define vSetCMRGB6_RGB7_CMRGB7_SMT(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB7_SMT=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB7_IMP() (pst_bitCMRGB6_RGB7() -> CMRGB7_IMP)
#define vSetCMRGB6_RGB7_CMRGB7_IMP(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB7_IMP=(ParValue))
#define biGetCMRGB6_RGB7_CMRGB7_LATCHN() (pst_bitCMRGB6_RGB7() -> CMRGB7_LATCHN)
#define vSetCMRGB6_RGB7_CMRGB7_LATCHN(ParValue)  (pst_bitCMRGB6_RGB7() -> CMRGB7_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCMRGB6_RGB7LL(ParValue) (pst_u8CMRGB6_RGB7() -> u8LL = (ParValue))
#define u8GetCMRGB6_RGB7LL() (pst_u8CMRGB6_RGB7() -> u8LL)
/* LH-struct byte access */
#define vSetCMRGB6_RGB7LH(ParValue) (pst_u8CMRGB6_RGB7() -> u8LH = (ParValue))
#define u8GetCMRGB6_RGB7LH() (pst_u8CMRGB6_RGB7() -> u8LH)
/* HL-struct byte access */
#define vSetCMRGB6_RGB7HL(ParValue) (pst_u8CMRGB6_RGB7() -> u8HL = (ParValue))
#define u8GetCMRGB6_RGB7HL() (pst_u8CMRGB6_RGB7() -> u8HL)
/* HH-struct byte access */
#define vSetCMRGB6_RGB7HH(ParValue) (pst_u8CMRGB6_RGB7() -> u8HH = (ParValue))
#define u8GetCMRGB6_RGB7HH() (pst_u8CMRGB6_RGB7() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCMRGB6_RGB7L(ParValue) (pst_u16CMRGB6_RGB7() -> u16L = (ParValue))
#define u16GetCMRGB6_RGB7L() (pst_u16CMRGB6_RGB7() -> u16L)
#define vSetCMRGB6_RGB7H(ParValue) (pst_u16CMRGB6_RGB7() -> u16H = (ParValue))
#define u16GetCMRGB6_RGB7H() (pst_u16CMRGB6_RGB7() -> u16H)
            
/* Word access */
#define vSetCMRGB6_RGB7(ParValue)  (*pu32CMRGB6_RGB7() = (ParValue))
#define u32GetCMRGB6_RGB7()  (*pu32CMRGB6_RGB7() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2CCLK_DATA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021E0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2CCLK_DATA_REG__       0xC03021E0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   I2CCLK_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   I2CCLK_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   I2CCLK_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   I2CCLK_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   I2CCLK_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   I2CCLK_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   I2CDATA_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   I2CDATA_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   I2CDATA_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   I2CDATA_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   I2CDATA_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   I2CDATA_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} I2CCLK_DATA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} I2CCLK_DATA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} I2CCLK_DATA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32I2CCLK_DATA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2CCLK_DATA()     ((volatile I2CCLK_DATA_bit_view_st *)\
(I2CCLK_DATA_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2CCLK_DATA()     ((volatile I2CCLK_DATA_byte_view_st *)\
(I2CCLK_DATA_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16I2CCLK_DATA()     ((volatile I2CCLK_DATA_halfword_view_st *)\
(I2CCLK_DATA_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32I2CCLK_DATA()     ((volatile u32I2CCLK_DATA_word_view *)\
(I2CCLK_DATA_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetI2CCLK_DATA_I2CCLK_SEL() (pst_bitI2CCLK_DATA() -> I2CCLK_SEL)
#define vSetI2CCLK_DATA_I2CCLK_SEL(ParValue)  (pst_bitI2CCLK_DATA() -> I2CCLK_SEL=(ParValue))
#define biGetI2CCLK_DATA_I2CCLK_PU() (pst_bitI2CCLK_DATA() -> I2CCLK_PU)
#define vSetI2CCLK_DATA_I2CCLK_PU(ParValue)  (pst_bitI2CCLK_DATA() -> I2CCLK_PU=(ParValue))
#define biGetI2CCLK_DATA_I2CCLK_PD() (pst_bitI2CCLK_DATA() -> I2CCLK_PD)
#define vSetI2CCLK_DATA_I2CCLK_PD(ParValue)  (pst_bitI2CCLK_DATA() -> I2CCLK_PD=(ParValue))
#define biGetI2CCLK_DATA_I2CCLK_SMT() (pst_bitI2CCLK_DATA() -> I2CCLK_SMT)
#define vSetI2CCLK_DATA_I2CCLK_SMT(ParValue)  (pst_bitI2CCLK_DATA() -> I2CCLK_SMT=(ParValue))
#define biGetI2CCLK_DATA_I2CCLK_IMP() (pst_bitI2CCLK_DATA() -> I2CCLK_IMP)
#define vSetI2CCLK_DATA_I2CCLK_IMP(ParValue)  (pst_bitI2CCLK_DATA() -> I2CCLK_IMP=(ParValue))
#define biGetI2CCLK_DATA_I2CCLK_LATCHN() (pst_bitI2CCLK_DATA() -> I2CCLK_LATCHN)
#define vSetI2CCLK_DATA_I2CCLK_LATCHN(ParValue)  (pst_bitI2CCLK_DATA() -> I2CCLK_LATCHN=(ParValue))
#define biGetI2CCLK_DATA_I2CDATA_SEL() (pst_bitI2CCLK_DATA() -> I2CDATA_SEL)
#define vSetI2CCLK_DATA_I2CDATA_SEL(ParValue)  (pst_bitI2CCLK_DATA() -> I2CDATA_SEL=(ParValue))
#define biGetI2CCLK_DATA_I2CDATA_PU() (pst_bitI2CCLK_DATA() -> I2CDATA_PU)
#define vSetI2CCLK_DATA_I2CDATA_PU(ParValue)  (pst_bitI2CCLK_DATA() -> I2CDATA_PU=(ParValue))
#define biGetI2CCLK_DATA_I2CDATA_PD() (pst_bitI2CCLK_DATA() -> I2CDATA_PD)
#define vSetI2CCLK_DATA_I2CDATA_PD(ParValue)  (pst_bitI2CCLK_DATA() -> I2CDATA_PD=(ParValue))
#define biGetI2CCLK_DATA_I2CDATA_SMT() (pst_bitI2CCLK_DATA() -> I2CDATA_SMT)
#define vSetI2CCLK_DATA_I2CDATA_SMT(ParValue)  (pst_bitI2CCLK_DATA() -> I2CDATA_SMT=(ParValue))
#define biGetI2CCLK_DATA_I2CDATA_IMP() (pst_bitI2CCLK_DATA() -> I2CDATA_IMP)
#define vSetI2CCLK_DATA_I2CDATA_IMP(ParValue)  (pst_bitI2CCLK_DATA() -> I2CDATA_IMP=(ParValue))
#define biGetI2CCLK_DATA_I2CDATA_LATCHN() (pst_bitI2CCLK_DATA() -> I2CDATA_LATCHN)
#define vSetI2CCLK_DATA_I2CDATA_LATCHN(ParValue)  (pst_bitI2CCLK_DATA() -> I2CDATA_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetI2CCLK_DATALL(ParValue) (pst_u8I2CCLK_DATA() -> u8LL = (ParValue))
#define u8GetI2CCLK_DATALL() (pst_u8I2CCLK_DATA() -> u8LL)
/* LH-struct byte access */
#define vSetI2CCLK_DATALH(ParValue) (pst_u8I2CCLK_DATA() -> u8LH = (ParValue))
#define u8GetI2CCLK_DATALH() (pst_u8I2CCLK_DATA() -> u8LH)
/* HL-struct byte access */
#define vSetI2CCLK_DATAHL(ParValue) (pst_u8I2CCLK_DATA() -> u8HL = (ParValue))
#define u8GetI2CCLK_DATAHL() (pst_u8I2CCLK_DATA() -> u8HL)
/* HH-struct byte access */
#define vSetI2CCLK_DATAHH(ParValue) (pst_u8I2CCLK_DATA() -> u8HH = (ParValue))
#define u8GetI2CCLK_DATAHH() (pst_u8I2CCLK_DATA() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetI2CCLK_DATAL(ParValue) (pst_u16I2CCLK_DATA() -> u16L = (ParValue))
#define u16GetI2CCLK_DATAL() (pst_u16I2CCLK_DATA() -> u16L)
#define vSetI2CCLK_DATAH(ParValue) (pst_u16I2CCLK_DATA() -> u16H = (ParValue))
#define u16GetI2CCLK_DATAH() (pst_u16I2CCLK_DATA() -> u16H)
            
/* Word access */
#define vSetI2CCLK_DATA(ParValue)  (*pu32I2CCLK_DATA() = (ParValue))
#define u32GetI2CCLK_DATA()  (*pu32I2CCLK_DATA() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CANRX0_TX0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021E4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CANRX0_TX0_REG__       0xC03021E4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CANRX0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CANRX0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CANRX0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   	:3; 	 /* 10..12  bit(s) R */
  uint32_t   CANRX0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CANTX0_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CANTX0_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CANTX0_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CANTX0_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CANTX0_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CANTX0_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CANRX0_TX0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CANRX0_TX0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CANRX0_TX0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CANRX0_TX0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCANRX0_TX0()     ((volatile CANRX0_TX0_bit_view_st *)\
(CANRX0_TX0_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CANRX0_TX0()     ((volatile CANRX0_TX0_byte_view_st *)\
(CANRX0_TX0_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CANRX0_TX0()     ((volatile CANRX0_TX0_halfword_view_st *)\
(CANRX0_TX0_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CANRX0_TX0()     ((volatile u32CANRX0_TX0_word_view *)\
(CANRX0_TX0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCANRX0_TX0_CANRX0_SEL() (pst_bitCANRX0_TX0() -> CANRX0_SEL)
#define vSetCANRX0_TX0_CANRX0_SEL(ParValue)  (pst_bitCANRX0_TX0() -> CANRX0_SEL=(ParValue))
#define biGetCANRX0_TX0_CANRX0_PU() (pst_bitCANRX0_TX0() -> CANRX0_PU)
#define vSetCANRX0_TX0_CANRX0_PU(ParValue)  (pst_bitCANRX0_TX0() -> CANRX0_PU=(ParValue))
#define biGetCANRX0_TX0_CANRX0_PD() (pst_bitCANRX0_TX0() -> CANRX0_PD)
#define vSetCANRX0_TX0_CANRX0_PD(ParValue)  (pst_bitCANRX0_TX0() -> CANRX0_PD=(ParValue))
#define biGetCANRX0_TX0_CANRX0_LATCHN() (pst_bitCANRX0_TX0() -> CANRX0_LATCHN)
#define vSetCANRX0_TX0_CANRX0_LATCHN(ParValue)  (pst_bitCANRX0_TX0() -> CANRX0_LATCHN=(ParValue))
#define biGetCANRX0_TX0_CANTX0_SEL() (pst_bitCANRX0_TX0() -> CANTX0_SEL)
#define vSetCANRX0_TX0_CANTX0_SEL(ParValue)  (pst_bitCANRX0_TX0() -> CANTX0_SEL=(ParValue))
#define biGetCANRX0_TX0_CANTX0_PU() (pst_bitCANRX0_TX0() -> CANTX0_PU)
#define vSetCANRX0_TX0_CANTX0_PU(ParValue)  (pst_bitCANRX0_TX0() -> CANTX0_PU=(ParValue))
#define biGetCANRX0_TX0_CANTX0_PD() (pst_bitCANRX0_TX0() -> CANTX0_PD)
#define vSetCANRX0_TX0_CANTX0_PD(ParValue)  (pst_bitCANRX0_TX0() -> CANTX0_PD=(ParValue))
#define biGetCANRX0_TX0_CANTX0_SMT() (pst_bitCANRX0_TX0() -> CANTX0_SMT)
#define vSetCANRX0_TX0_CANTX0_SMT(ParValue)  (pst_bitCANRX0_TX0() -> CANTX0_SMT=(ParValue))
#define biGetCANRX0_TX0_CANTX0_IMP() (pst_bitCANRX0_TX0() -> CANTX0_IMP)
#define vSetCANRX0_TX0_CANTX0_IMP(ParValue)  (pst_bitCANRX0_TX0() -> CANTX0_IMP=(ParValue))
#define biGetCANRX0_TX0_CANTX0_LATCHN() (pst_bitCANRX0_TX0() -> CANTX0_LATCHN)
#define vSetCANRX0_TX0_CANTX0_LATCHN(ParValue)  (pst_bitCANRX0_TX0() -> CANTX0_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCANRX0_TX0LL(ParValue) (pst_u8CANRX0_TX0() -> u8LL = (ParValue))
#define u8GetCANRX0_TX0LL() (pst_u8CANRX0_TX0() -> u8LL)
/* LH-struct byte access */
#define vSetCANRX0_TX0LH(ParValue) (pst_u8CANRX0_TX0() -> u8LH = (ParValue))
#define u8GetCANRX0_TX0LH() (pst_u8CANRX0_TX0() -> u8LH)
/* HL-struct byte access */
#define vSetCANRX0_TX0HL(ParValue) (pst_u8CANRX0_TX0() -> u8HL = (ParValue))
#define u8GetCANRX0_TX0HL() (pst_u8CANRX0_TX0() -> u8HL)
/* HH-struct byte access */
#define vSetCANRX0_TX0HH(ParValue) (pst_u8CANRX0_TX0() -> u8HH = (ParValue))
#define u8GetCANRX0_TX0HH() (pst_u8CANRX0_TX0() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCANRX0_TX0L(ParValue) (pst_u16CANRX0_TX0() -> u16L = (ParValue))
#define u16GetCANRX0_TX0L() (pst_u16CANRX0_TX0() -> u16L)
#define vSetCANRX0_TX0H(ParValue) (pst_u16CANRX0_TX0() -> u16H = (ParValue))
#define u16GetCANRX0_TX0H() (pst_u16CANRX0_TX0() -> u16H)
            
/* Word access */
#define vSetCANRX0_TX0(ParValue)  (*pu32CANRX0_TX0() = (ParValue))
#define u32GetCANRX0_TX0()  (*pu32CANRX0_TX0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CANRX1_TX1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021E8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CANRX1_TX1_REG__       0xC03021E8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CANRX1_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   CANRX1_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   CANRX1_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   	:3; 	 /* 10..12  bit(s) R */
  uint32_t   CANRX1_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   CANTX1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   CANTX1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   CANTX1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   CANTX1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   CANTX1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   CANTX1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} CANRX1_TX1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CANRX1_TX1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CANRX1_TX1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CANRX1_TX1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCANRX1_TX1()     ((volatile CANRX1_TX1_bit_view_st *)\
(CANRX1_TX1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CANRX1_TX1()     ((volatile CANRX1_TX1_byte_view_st *)\
(CANRX1_TX1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CANRX1_TX1()     ((volatile CANRX1_TX1_halfword_view_st *)\
(CANRX1_TX1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CANRX1_TX1()     ((volatile u32CANRX1_TX1_word_view *)\
(CANRX1_TX1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCANRX1_TX1_CANRX1_SEL() (pst_bitCANRX1_TX1() -> CANRX1_SEL)
#define vSetCANRX1_TX1_CANRX1_SEL(ParValue)  (pst_bitCANRX1_TX1() -> CANRX1_SEL=(ParValue))
#define biGetCANRX1_TX1_CANRX1_PU() (pst_bitCANRX1_TX1() -> CANRX1_PU)
#define vSetCANRX1_TX1_CANRX1_PU(ParValue)  (pst_bitCANRX1_TX1() -> CANRX1_PU=(ParValue))
#define biGetCANRX1_TX1_CANRX1_PD() (pst_bitCANRX1_TX1() -> CANRX1_PD)
#define vSetCANRX1_TX1_CANRX1_PD(ParValue)  (pst_bitCANRX1_TX1() -> CANRX1_PD=(ParValue))
#define biGetCANRX1_TX1_CANRX1_LATCHN() (pst_bitCANRX1_TX1() -> CANRX1_LATCHN)
#define vSetCANRX1_TX1_CANRX1_LATCHN(ParValue)  (pst_bitCANRX1_TX1() -> CANRX1_LATCHN=(ParValue))
#define biGetCANRX1_TX1_CANTX1_SEL() (pst_bitCANRX1_TX1() -> CANTX1_SEL)
#define vSetCANRX1_TX1_CANTX1_SEL(ParValue)  (pst_bitCANRX1_TX1() -> CANTX1_SEL=(ParValue))
#define biGetCANRX1_TX1_CANTX1_PU() (pst_bitCANRX1_TX1() -> CANTX1_PU)
#define vSetCANRX1_TX1_CANTX1_PU(ParValue)  (pst_bitCANRX1_TX1() -> CANTX1_PU=(ParValue))
#define biGetCANRX1_TX1_CANTX1_PD() (pst_bitCANRX1_TX1() -> CANTX1_PD)
#define vSetCANRX1_TX1_CANTX1_PD(ParValue)  (pst_bitCANRX1_TX1() -> CANTX1_PD=(ParValue))
#define biGetCANRX1_TX1_CANTX1_SMT() (pst_bitCANRX1_TX1() -> CANTX1_SMT)
#define vSetCANRX1_TX1_CANTX1_SMT(ParValue)  (pst_bitCANRX1_TX1() -> CANTX1_SMT=(ParValue))
#define biGetCANRX1_TX1_CANTX1_IMP() (pst_bitCANRX1_TX1() -> CANTX1_IMP)
#define vSetCANRX1_TX1_CANTX1_IMP(ParValue)  (pst_bitCANRX1_TX1() -> CANTX1_IMP=(ParValue))
#define biGetCANRX1_TX1_CANTX1_LATCHN() (pst_bitCANRX1_TX1() -> CANTX1_LATCHN)
#define vSetCANRX1_TX1_CANTX1_LATCHN(ParValue)  (pst_bitCANRX1_TX1() -> CANTX1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetCANRX1_TX1LL(ParValue) (pst_u8CANRX1_TX1() -> u8LL = (ParValue))
#define u8GetCANRX1_TX1LL() (pst_u8CANRX1_TX1() -> u8LL)
/* LH-struct byte access */
#define vSetCANRX1_TX1LH(ParValue) (pst_u8CANRX1_TX1() -> u8LH = (ParValue))
#define u8GetCANRX1_TX1LH() (pst_u8CANRX1_TX1() -> u8LH)
/* HL-struct byte access */
#define vSetCANRX1_TX1HL(ParValue) (pst_u8CANRX1_TX1() -> u8HL = (ParValue))
#define u8GetCANRX1_TX1HL() (pst_u8CANRX1_TX1() -> u8HL)
/* HH-struct byte access */
#define vSetCANRX1_TX1HH(ParValue) (pst_u8CANRX1_TX1() -> u8HH = (ParValue))
#define u8GetCANRX1_TX1HH() (pst_u8CANRX1_TX1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCANRX1_TX1L(ParValue) (pst_u16CANRX1_TX1() -> u16L = (ParValue))
#define u16GetCANRX1_TX1L() (pst_u16CANRX1_TX1() -> u16L)
#define vSetCANRX1_TX1H(ParValue) (pst_u16CANRX1_TX1() -> u16H = (ParValue))
#define u16GetCANRX1_TX1H() (pst_u16CANRX1_TX1() -> u16H)
            
/* Word access */
#define vSetCANRX1_TX1(ParValue)  (*pu32CANRX1_TX1() = (ParValue))
#define u32GetCANRX1_TX1()  (*pu32CANRX1_TX1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MLBDAT_IO_SIG_IO                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021EC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MLBDAT_IO_SIG_IO_REG__       0xC03021ECU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   MLBDAT_IO_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   MLBDAT_IO_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   MLBDAT_IO_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   MLBDAT_IO_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   MLBDAT_IO_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   MLBSIG_IO_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   MLBSIG_IO_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   MLBSIG_IO_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   MLBSIG_IO_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   MLBSIG_IO_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} MLBDAT_IO_SIG_IO_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} MLBDAT_IO_SIG_IO_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} MLBDAT_IO_SIG_IO_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32MLBDAT_IO_SIG_IO_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMLBDAT_IO_SIG_IO()     ((volatile MLBDAT_IO_SIG_IO_bit_view_st *)\
(MLBDAT_IO_SIG_IO_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8MLBDAT_IO_SIG_IO()     ((volatile MLBDAT_IO_SIG_IO_byte_view_st *)\
(MLBDAT_IO_SIG_IO_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16MLBDAT_IO_SIG_IO()     ((volatile MLBDAT_IO_SIG_IO_halfword_view_st *)\
(MLBDAT_IO_SIG_IO_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32MLBDAT_IO_SIG_IO()     ((volatile u32MLBDAT_IO_SIG_IO_word_view *)\
(MLBDAT_IO_SIG_IO_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMLBDAT_IO_SIG_IO_MLBDAT_IO_PU() (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_PU)
#define vSetMLBDAT_IO_SIG_IO_MLBDAT_IO_PU(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_PU=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBDAT_IO_PD() (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_PD)
#define vSetMLBDAT_IO_SIG_IO_MLBDAT_IO_PD(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_PD=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBDAT_IO_SMT() (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_SMT)
#define vSetMLBDAT_IO_SIG_IO_MLBDAT_IO_SMT(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_SMT=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBDAT_IO_IMP() (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_IMP)
#define vSetMLBDAT_IO_SIG_IO_MLBDAT_IO_IMP(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_IMP=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBDAT_IO_LATCHN() (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_LATCHN)
#define vSetMLBDAT_IO_SIG_IO_MLBDAT_IO_LATCHN(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBDAT_IO_LATCHN=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBSIG_IO_PU() (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_PU)
#define vSetMLBDAT_IO_SIG_IO_MLBSIG_IO_PU(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_PU=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBSIG_IO_PD() (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_PD)
#define vSetMLBDAT_IO_SIG_IO_MLBSIG_IO_PD(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_PD=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBSIG_IO_SMT() (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_SMT)
#define vSetMLBDAT_IO_SIG_IO_MLBSIG_IO_SMT(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_SMT=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBSIG_IO_IMP() (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_IMP)
#define vSetMLBDAT_IO_SIG_IO_MLBSIG_IO_IMP(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_IMP=(ParValue))
#define biGetMLBDAT_IO_SIG_IO_MLBSIG_IO_LATCHN() (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_LATCHN)
#define vSetMLBDAT_IO_SIG_IO_MLBSIG_IO_LATCHN(ParValue)  (pst_bitMLBDAT_IO_SIG_IO() -> MLBSIG_IO_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetMLBDAT_IO_SIG_IOLL(ParValue) (pst_u8MLBDAT_IO_SIG_IO() -> u8LL = (ParValue))
#define u8GetMLBDAT_IO_SIG_IOLL() (pst_u8MLBDAT_IO_SIG_IO() -> u8LL)
/* LH-struct byte access */
#define vSetMLBDAT_IO_SIG_IOLH(ParValue) (pst_u8MLBDAT_IO_SIG_IO() -> u8LH = (ParValue))
#define u8GetMLBDAT_IO_SIG_IOLH() (pst_u8MLBDAT_IO_SIG_IO() -> u8LH)
/* HL-struct byte access */
#define vSetMLBDAT_IO_SIG_IOHL(ParValue) (pst_u8MLBDAT_IO_SIG_IO() -> u8HL = (ParValue))
#define u8GetMLBDAT_IO_SIG_IOHL() (pst_u8MLBDAT_IO_SIG_IO() -> u8HL)
/* HH-struct byte access */
#define vSetMLBDAT_IO_SIG_IOHH(ParValue) (pst_u8MLBDAT_IO_SIG_IO() -> u8HH = (ParValue))
#define u8GetMLBDAT_IO_SIG_IOHH() (pst_u8MLBDAT_IO_SIG_IO() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetMLBDAT_IO_SIG_IOL(ParValue) (pst_u16MLBDAT_IO_SIG_IO() -> u16L = (ParValue))
#define u16GetMLBDAT_IO_SIG_IOL() (pst_u16MLBDAT_IO_SIG_IO() -> u16L)
#define vSetMLBDAT_IO_SIG_IOH(ParValue) (pst_u16MLBDAT_IO_SIG_IO() -> u16H = (ParValue))
#define u16GetMLBDAT_IO_SIG_IOH() (pst_u16MLBDAT_IO_SIG_IO() -> u16H)
            
/* Word access */
#define vSetMLBDAT_IO_SIG_IO(ParValue)  (*pu32MLBDAT_IO_SIG_IO() = (ParValue))
#define u32GetMLBDAT_IO_SIG_IO()  (*pu32MLBDAT_IO_SIG_IO() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MLBCLK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021F0                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MLBCLK_REG__       0xC03021F0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   	:8; 	 /* 0..7  bit(s) R */
  uint16_t   MLBCLK_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   MLBCLK_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   MLBCLK_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint16_t   	:2; 	 /* 11..12  bit(s) R */
  uint16_t   MLBCLK_LATCHN	:1; 	 /* 13..13  bit(s) R/W */ 
  uint16_t   	:2; 	 /* 14..31  bit(s) R */                    
} MLBCLK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} MLBCLK_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16MLBCLK_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMLBCLK()     ((volatile MLBCLK_bit_view_st *)\
(MLBCLK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8MLBCLK()     ((volatile MLBCLK_byte_view_st *)\
(MLBCLK_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16MLBCLK()     ((volatile u16MLBCLK_halfword_view *)\
(MLBCLK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMLBCLK_MLBCLK_PU() (pst_bitMLBCLK() -> MLBCLK_PU)
#define vSetMLBCLK_MLBCLK_PU(ParValue)  (pst_bitMLBCLK() -> MLBCLK_PU=(ParValue))
#define biGetMLBCLK_MLBCLK_PD() (pst_bitMLBCLK() -> MLBCLK_PD)
#define vSetMLBCLK_MLBCLK_PD(ParValue)  (pst_bitMLBCLK() -> MLBCLK_PD=(ParValue))
#define biGetMLBCLK_MLBCLK_SMT() (pst_bitMLBCLK() -> MLBCLK_SMT)
#define vSetMLBCLK_MLBCLK_SMT(ParValue)  (pst_bitMLBCLK() -> MLBCLK_SMT=(ParValue))
#define biGetMLBCLK_MLBCLK_LATCHN() (pst_bitMLBCLK() -> MLBCLK_LATCHN)
#define vSetMLBCLK_MLBCLK_LATCHN(ParValue)  (pst_bitMLBCLK() -> MLBCLK_LATCHN=(ParValue))
            
/* L-struct byte access */
#define vSetMLBCLKL(ParValue) (pst_u8MLBCLK() -> u8L = (ParValue))
#define u8GetMLBCLKL() (pst_u8MLBCLK() -> u8L)
/* H-struct byte access */
#define vSetMLBCLKH(ParValue) (pst_u8MLBCLK() -> u8H = (ParValue))
#define u8GetMLBCLKH() (pst_u8MLBCLK() -> u8H)
            
/* Half-word access */ 
#define vSetMLBCLK(ParValue) (*pu16MLBCLK()  = (ParValue))
#define u16GetMLBCLK() (*pu16MLBCLK() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: ESEI0MISO_MOSI                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021F4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ESEI0MISO_MOSI_REG__       0xC03021F4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ESEI0MISO_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ESEI0MISO_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ESEI0MISO_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   	:3; 	 /* 10..12  bit(s) R */
  uint32_t   ESEI0MISO_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   ESEI0MOSI_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ESEI0MOSI_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ESEI0MOSI_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   	:3; 	 /* 26..28  bit(s) R */
  uint32_t   ESEI0MOSI_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ESEI0MISO_MOSI_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ESEI0MISO_MOSI_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ESEI0MISO_MOSI_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ESEI0MISO_MOSI_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitESEI0MISO_MOSI()     ((volatile ESEI0MISO_MOSI_bit_view_st *)\
(ESEI0MISO_MOSI_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ESEI0MISO_MOSI()     ((volatile ESEI0MISO_MOSI_byte_view_st *)\
(ESEI0MISO_MOSI_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ESEI0MISO_MOSI()     ((volatile ESEI0MISO_MOSI_halfword_view_st *)\
(ESEI0MISO_MOSI_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ESEI0MISO_MOSI()     ((volatile u32ESEI0MISO_MOSI_word_view *)\
(ESEI0MISO_MOSI_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetESEI0MISO_MOSI_ESEI0MISO_SEL() (pst_bitESEI0MISO_MOSI() -> ESEI0MISO_SEL)
#define vSetESEI0MISO_MOSI_ESEI0MISO_SEL(ParValue)  (pst_bitESEI0MISO_MOSI() -> ESEI0MISO_SEL=(ParValue))
#define biGetESEI0MISO_MOSI_ESEI0MISO_PU() (pst_bitESEI0MISO_MOSI() -> ESEI0MISO_PU)
#define vSetESEI0MISO_MOSI_ESEI0MISO_PU(ParValue)  (pst_bitESEI0MISO_MOSI() -> ESEI0MISO_PU=(ParValue))
#define biGetESEI0MISO_MOSI_ESEI0MISO_PD() (pst_bitESEI0MISO_MOSI() -> ESEI0MISO_PD)
#define vSetESEI0MISO_MOSI_ESEI0MISO_PD(ParValue)  (pst_bitESEI0MISO_MOSI() -> ESEI0MISO_PD=(ParValue))
#define biGetESEI0MISO_MOSI_ESEI0MISO_LATCHN() (pst_bitESEI0MISO_MOSI() -> ESEI0MISO_LATCHN)
#define vSetESEI0MISO_MOSI_ESEI0MISO_LATCHN(ParValue)  (pst_bitESEI0MISO_MOSI() -> ESEI0MISO_LATCHN=(ParValue))
#define biGetESEI0MISO_MOSI_ESEI0MOSI_SEL() (pst_bitESEI0MISO_MOSI() -> ESEI0MOSI_SEL)
#define vSetESEI0MISO_MOSI_ESEI0MOSI_SEL(ParValue)  (pst_bitESEI0MISO_MOSI() -> ESEI0MOSI_SEL=(ParValue))
#define biGetESEI0MISO_MOSI_ESEI0MOSI_PU() (pst_bitESEI0MISO_MOSI() -> ESEI0MOSI_PU)
#define vSetESEI0MISO_MOSI_ESEI0MOSI_PU(ParValue)  (pst_bitESEI0MISO_MOSI() -> ESEI0MOSI_PU=(ParValue))
#define biGetESEI0MISO_MOSI_ESEI0MOSI_PD() (pst_bitESEI0MISO_MOSI() -> ESEI0MOSI_PD)
#define vSetESEI0MISO_MOSI_ESEI0MOSI_PD(ParValue)  (pst_bitESEI0MISO_MOSI() -> ESEI0MOSI_PD=(ParValue))
#define biGetESEI0MISO_MOSI_ESEI0MOSI_LATCHN() (pst_bitESEI0MISO_MOSI() -> ESEI0MOSI_LATCHN)
#define vSetESEI0MISO_MOSI_ESEI0MOSI_LATCHN(ParValue)  (pst_bitESEI0MISO_MOSI() -> ESEI0MOSI_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetESEI0MISO_MOSILL(ParValue) (pst_u8ESEI0MISO_MOSI() -> u8LL = (ParValue))
#define u8GetESEI0MISO_MOSILL() (pst_u8ESEI0MISO_MOSI() -> u8LL)
/* LH-struct byte access */
#define vSetESEI0MISO_MOSILH(ParValue) (pst_u8ESEI0MISO_MOSI() -> u8LH = (ParValue))
#define u8GetESEI0MISO_MOSILH() (pst_u8ESEI0MISO_MOSI() -> u8LH)
/* HL-struct byte access */
#define vSetESEI0MISO_MOSIHL(ParValue) (pst_u8ESEI0MISO_MOSI() -> u8HL = (ParValue))
#define u8GetESEI0MISO_MOSIHL() (pst_u8ESEI0MISO_MOSI() -> u8HL)
/* HH-struct byte access */
#define vSetESEI0MISO_MOSIHH(ParValue) (pst_u8ESEI0MISO_MOSI() -> u8HH = (ParValue))
#define u8GetESEI0MISO_MOSIHH() (pst_u8ESEI0MISO_MOSI() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetESEI0MISO_MOSIL(ParValue) (pst_u16ESEI0MISO_MOSI() -> u16L = (ParValue))
#define u16GetESEI0MISO_MOSIL() (pst_u16ESEI0MISO_MOSI() -> u16L)
#define vSetESEI0MISO_MOSIH(ParValue) (pst_u16ESEI0MISO_MOSI() -> u16H = (ParValue))
#define u16GetESEI0MISO_MOSIH() (pst_u16ESEI0MISO_MOSI() -> u16H)
            
/* Word access */
#define vSetESEI0MISO_MOSI(ParValue)  (*pu32ESEI0MISO_MOSI() = (ParValue))
#define u32GetESEI0MISO_MOSI()  (*pu32ESEI0MISO_MOSI() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ESEI0SCLK_SSOI                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021F8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ESEI0SCLK_SSOI_REG__       0xC03021F8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ESEI0SCLK_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ESEI0SCLK_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ESEI0SCLK_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   	:3; 	 /* 10..12  bit(s) R */
  uint32_t   ESEI0SCLK_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   ESEI0SSOI_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ESEI0SSOI_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ESEI0SSOI_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   	:3; 	 /* 26..28  bit(s) R */
  uint32_t   ESEI0SSOI_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ESEI0SCLK_SSOI_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ESEI0SCLK_SSOI_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ESEI0SCLK_SSOI_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ESEI0SCLK_SSOI_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitESEI0SCLK_SSOI()     ((volatile ESEI0SCLK_SSOI_bit_view_st *)\
(ESEI0SCLK_SSOI_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ESEI0SCLK_SSOI()     ((volatile ESEI0SCLK_SSOI_byte_view_st *)\
(ESEI0SCLK_SSOI_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ESEI0SCLK_SSOI()     ((volatile ESEI0SCLK_SSOI_halfword_view_st *)\
(ESEI0SCLK_SSOI_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ESEI0SCLK_SSOI()     ((volatile u32ESEI0SCLK_SSOI_word_view *)\
(ESEI0SCLK_SSOI_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetESEI0SCLK_SSOI_ESEI0SCLK_SEL() (pst_bitESEI0SCLK_SSOI() -> ESEI0SCLK_SEL)
#define vSetESEI0SCLK_SSOI_ESEI0SCLK_SEL(ParValue)  (pst_bitESEI0SCLK_SSOI() -> ESEI0SCLK_SEL=(ParValue))
#define biGetESEI0SCLK_SSOI_ESEI0SCLK_PU() (pst_bitESEI0SCLK_SSOI() -> ESEI0SCLK_PU)
#define vSetESEI0SCLK_SSOI_ESEI0SCLK_PU(ParValue)  (pst_bitESEI0SCLK_SSOI() -> ESEI0SCLK_PU=(ParValue))
#define biGetESEI0SCLK_SSOI_ESEI0SCLK_PD() (pst_bitESEI0SCLK_SSOI() -> ESEI0SCLK_PD)
#define vSetESEI0SCLK_SSOI_ESEI0SCLK_PD(ParValue)  (pst_bitESEI0SCLK_SSOI() -> ESEI0SCLK_PD=(ParValue))
#define biGetESEI0SCLK_SSOI_ESEI0SCLK_LATCHN() (pst_bitESEI0SCLK_SSOI() -> ESEI0SCLK_LATCHN)
#define vSetESEI0SCLK_SSOI_ESEI0SCLK_LATCHN(ParValue)  (pst_bitESEI0SCLK_SSOI() -> ESEI0SCLK_LATCHN=(ParValue))
#define biGetESEI0SCLK_SSOI_ESEI0SSOI_SEL() (pst_bitESEI0SCLK_SSOI() -> ESEI0SSOI_SEL)
#define vSetESEI0SCLK_SSOI_ESEI0SSOI_SEL(ParValue)  (pst_bitESEI0SCLK_SSOI() -> ESEI0SSOI_SEL=(ParValue))
#define biGetESEI0SCLK_SSOI_ESEI0SSOI_PU() (pst_bitESEI0SCLK_SSOI() -> ESEI0SSOI_PU)
#define vSetESEI0SCLK_SSOI_ESEI0SSOI_PU(ParValue)  (pst_bitESEI0SCLK_SSOI() -> ESEI0SSOI_PU=(ParValue))
#define biGetESEI0SCLK_SSOI_ESEI0SSOI_PD() (pst_bitESEI0SCLK_SSOI() -> ESEI0SSOI_PD)
#define vSetESEI0SCLK_SSOI_ESEI0SSOI_PD(ParValue)  (pst_bitESEI0SCLK_SSOI() -> ESEI0SSOI_PD=(ParValue))
#define biGetESEI0SCLK_SSOI_ESEI0SSOI_LATCHN() (pst_bitESEI0SCLK_SSOI() -> ESEI0SSOI_LATCHN)
#define vSetESEI0SCLK_SSOI_ESEI0SSOI_LATCHN(ParValue)  (pst_bitESEI0SCLK_SSOI() -> ESEI0SSOI_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetESEI0SCLK_SSOILL(ParValue) (pst_u8ESEI0SCLK_SSOI() -> u8LL = (ParValue))
#define u8GetESEI0SCLK_SSOILL() (pst_u8ESEI0SCLK_SSOI() -> u8LL)
/* LH-struct byte access */
#define vSetESEI0SCLK_SSOILH(ParValue) (pst_u8ESEI0SCLK_SSOI() -> u8LH = (ParValue))
#define u8GetESEI0SCLK_SSOILH() (pst_u8ESEI0SCLK_SSOI() -> u8LH)
/* HL-struct byte access */
#define vSetESEI0SCLK_SSOIHL(ParValue) (pst_u8ESEI0SCLK_SSOI() -> u8HL = (ParValue))
#define u8GetESEI0SCLK_SSOIHL() (pst_u8ESEI0SCLK_SSOI() -> u8HL)
/* HH-struct byte access */
#define vSetESEI0SCLK_SSOIHH(ParValue) (pst_u8ESEI0SCLK_SSOI() -> u8HH = (ParValue))
#define u8GetESEI0SCLK_SSOIHH() (pst_u8ESEI0SCLK_SSOI() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetESEI0SCLK_SSOIL(ParValue) (pst_u16ESEI0SCLK_SSOI() -> u16L = (ParValue))
#define u16GetESEI0SCLK_SSOIL() (pst_u16ESEI0SCLK_SSOI() -> u16L)
#define vSetESEI0SCLK_SSOIH(ParValue) (pst_u16ESEI0SCLK_SSOI() -> u16H = (ParValue))
#define u16GetESEI0SCLK_SSOIH() (pst_u16ESEI0SCLK_SSOI() -> u16H)
            
/* Word access */
#define vSetESEI0SCLK_SSOI(ParValue)  (*pu32ESEI0SCLK_SSOI() = (ParValue))
#define u32GetESEI0SCLK_SSOI()  (*pu32ESEI0SCLK_SSOI() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2S0CLK_WS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03021FC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2S0CLK_WS_REG__       0xC03021FCU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   I2S0CLK_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   I2S0CLK_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   I2S0CLK_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   I2S0CLK_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   I2S0CLK_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   I2S0CLK_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   I2S0WS_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   I2S0WS_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   I2S0WS_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   I2S0WS_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   I2S0WS_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   I2S0WS_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} I2S0CLK_WS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} I2S0CLK_WS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} I2S0CLK_WS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32I2S0CLK_WS_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2S0CLK_WS()     ((volatile I2S0CLK_WS_bit_view_st *)\
(I2S0CLK_WS_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2S0CLK_WS()     ((volatile I2S0CLK_WS_byte_view_st *)\
(I2S0CLK_WS_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16I2S0CLK_WS()     ((volatile I2S0CLK_WS_halfword_view_st *)\
(I2S0CLK_WS_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32I2S0CLK_WS()     ((volatile u32I2S0CLK_WS_word_view *)\
(I2S0CLK_WS_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetI2S0CLK_WS_I2S0CLK_SEL() (pst_bitI2S0CLK_WS() -> I2S0CLK_SEL)
#define vSetI2S0CLK_WS_I2S0CLK_SEL(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0CLK_SEL=(ParValue))
#define biGetI2S0CLK_WS_I2S0CLK_PU() (pst_bitI2S0CLK_WS() -> I2S0CLK_PU)
#define vSetI2S0CLK_WS_I2S0CLK_PU(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0CLK_PU=(ParValue))
#define biGetI2S0CLK_WS_I2S0CLK_PD() (pst_bitI2S0CLK_WS() -> I2S0CLK_PD)
#define vSetI2S0CLK_WS_I2S0CLK_PD(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0CLK_PD=(ParValue))
#define biGetI2S0CLK_WS_I2S0CLK_SMT() (pst_bitI2S0CLK_WS() -> I2S0CLK_SMT)
#define vSetI2S0CLK_WS_I2S0CLK_SMT(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0CLK_SMT=(ParValue))
#define biGetI2S0CLK_WS_I2S0CLK_IMP() (pst_bitI2S0CLK_WS() -> I2S0CLK_IMP)
#define vSetI2S0CLK_WS_I2S0CLK_IMP(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0CLK_IMP=(ParValue))
#define biGetI2S0CLK_WS_I2S0CLK_LATCHN() (pst_bitI2S0CLK_WS() -> I2S0CLK_LATCHN)
#define vSetI2S0CLK_WS_I2S0CLK_LATCHN(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0CLK_LATCHN=(ParValue))
#define biGetI2S0CLK_WS_I2S0WS_SEL() (pst_bitI2S0CLK_WS() -> I2S0WS_SEL)
#define vSetI2S0CLK_WS_I2S0WS_SEL(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0WS_SEL=(ParValue))
#define biGetI2S0CLK_WS_I2S0WS_PU() (pst_bitI2S0CLK_WS() -> I2S0WS_PU)
#define vSetI2S0CLK_WS_I2S0WS_PU(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0WS_PU=(ParValue))
#define biGetI2S0CLK_WS_I2S0WS_PD() (pst_bitI2S0CLK_WS() -> I2S0WS_PD)
#define vSetI2S0CLK_WS_I2S0WS_PD(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0WS_PD=(ParValue))
#define biGetI2S0CLK_WS_I2S0WS_SMT() (pst_bitI2S0CLK_WS() -> I2S0WS_SMT)
#define vSetI2S0CLK_WS_I2S0WS_SMT(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0WS_SMT=(ParValue))
#define biGetI2S0CLK_WS_I2S0WS_IMP() (pst_bitI2S0CLK_WS() -> I2S0WS_IMP)
#define vSetI2S0CLK_WS_I2S0WS_IMP(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0WS_IMP=(ParValue))
#define biGetI2S0CLK_WS_I2S0WS_LATCHN() (pst_bitI2S0CLK_WS() -> I2S0WS_LATCHN)
#define vSetI2S0CLK_WS_I2S0WS_LATCHN(ParValue)  (pst_bitI2S0CLK_WS() -> I2S0WS_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetI2S0CLK_WSLL(ParValue) (pst_u8I2S0CLK_WS() -> u8LL = (ParValue))
#define u8GetI2S0CLK_WSLL() (pst_u8I2S0CLK_WS() -> u8LL)
/* LH-struct byte access */
#define vSetI2S0CLK_WSLH(ParValue) (pst_u8I2S0CLK_WS() -> u8LH = (ParValue))
#define u8GetI2S0CLK_WSLH() (pst_u8I2S0CLK_WS() -> u8LH)
/* HL-struct byte access */
#define vSetI2S0CLK_WSHL(ParValue) (pst_u8I2S0CLK_WS() -> u8HL = (ParValue))
#define u8GetI2S0CLK_WSHL() (pst_u8I2S0CLK_WS() -> u8HL)
/* HH-struct byte access */
#define vSetI2S0CLK_WSHH(ParValue) (pst_u8I2S0CLK_WS() -> u8HH = (ParValue))
#define u8GetI2S0CLK_WSHH() (pst_u8I2S0CLK_WS() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetI2S0CLK_WSL(ParValue) (pst_u16I2S0CLK_WS() -> u16L = (ParValue))
#define u16GetI2S0CLK_WSL() (pst_u16I2S0CLK_WS() -> u16L)
#define vSetI2S0CLK_WSH(ParValue) (pst_u16I2S0CLK_WS() -> u16H = (ParValue))
#define u16GetI2S0CLK_WSH() (pst_u16I2S0CLK_WS() -> u16H)
            
/* Word access */
#define vSetI2S0CLK_WS(ParValue)  (*pu32I2S0CLK_WS() = (ParValue))
#define u32GetI2S0CLK_WS()  (*pu32I2S0CLK_WS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2S0SD_MCLK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302200                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2S0SD_MCLK_REG__       0xC0302200U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   I2S0SD_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   I2S0SD_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   I2S0SD_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   I2S0SD_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   I2S0SD_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   I2S0SD_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   I2SMCLK_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   I2SMCLK_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   I2SMCLK_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   I2SMCLK_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   I2SMCLK_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   I2SMCLK_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} I2S0SD_MCLK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} I2S0SD_MCLK_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} I2S0SD_MCLK_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32I2S0SD_MCLK_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2S0SD_MCLK()     ((volatile I2S0SD_MCLK_bit_view_st *)\
(I2S0SD_MCLK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2S0SD_MCLK()     ((volatile I2S0SD_MCLK_byte_view_st *)\
(I2S0SD_MCLK_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16I2S0SD_MCLK()     ((volatile I2S0SD_MCLK_halfword_view_st *)\
(I2S0SD_MCLK_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32I2S0SD_MCLK()     ((volatile u32I2S0SD_MCLK_word_view *)\
(I2S0SD_MCLK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetI2S0SD_MCLK_I2S0SD_SEL() (pst_bitI2S0SD_MCLK() -> I2S0SD_SEL)
#define vSetI2S0SD_MCLK_I2S0SD_SEL(ParValue)  (pst_bitI2S0SD_MCLK() -> I2S0SD_SEL=(ParValue))
#define biGetI2S0SD_MCLK_I2S0SD_PU() (pst_bitI2S0SD_MCLK() -> I2S0SD_PU)
#define vSetI2S0SD_MCLK_I2S0SD_PU(ParValue)  (pst_bitI2S0SD_MCLK() -> I2S0SD_PU=(ParValue))
#define biGetI2S0SD_MCLK_I2S0SD_PD() (pst_bitI2S0SD_MCLK() -> I2S0SD_PD)
#define vSetI2S0SD_MCLK_I2S0SD_PD(ParValue)  (pst_bitI2S0SD_MCLK() -> I2S0SD_PD=(ParValue))
#define biGetI2S0SD_MCLK_I2S0SD_SMT() (pst_bitI2S0SD_MCLK() -> I2S0SD_SMT)
#define vSetI2S0SD_MCLK_I2S0SD_SMT(ParValue)  (pst_bitI2S0SD_MCLK() -> I2S0SD_SMT=(ParValue))
#define biGetI2S0SD_MCLK_I2S0SD_IMP() (pst_bitI2S0SD_MCLK() -> I2S0SD_IMP)
#define vSetI2S0SD_MCLK_I2S0SD_IMP(ParValue)  (pst_bitI2S0SD_MCLK() -> I2S0SD_IMP=(ParValue))
#define biGetI2S0SD_MCLK_I2S0SD_LATCHN() (pst_bitI2S0SD_MCLK() -> I2S0SD_LATCHN)
#define vSetI2S0SD_MCLK_I2S0SD_LATCHN(ParValue)  (pst_bitI2S0SD_MCLK() -> I2S0SD_LATCHN=(ParValue))
#define biGetI2S0SD_MCLK_I2SMCLK_SEL() (pst_bitI2S0SD_MCLK() -> I2SMCLK_SEL)
#define vSetI2S0SD_MCLK_I2SMCLK_SEL(ParValue)  (pst_bitI2S0SD_MCLK() -> I2SMCLK_SEL=(ParValue))
#define biGetI2S0SD_MCLK_I2SMCLK_PU() (pst_bitI2S0SD_MCLK() -> I2SMCLK_PU)
#define vSetI2S0SD_MCLK_I2SMCLK_PU(ParValue)  (pst_bitI2S0SD_MCLK() -> I2SMCLK_PU=(ParValue))
#define biGetI2S0SD_MCLK_I2SMCLK_PD() (pst_bitI2S0SD_MCLK() -> I2SMCLK_PD)
#define vSetI2S0SD_MCLK_I2SMCLK_PD(ParValue)  (pst_bitI2S0SD_MCLK() -> I2SMCLK_PD=(ParValue))
#define biGetI2S0SD_MCLK_I2SMCLK_SMT() (pst_bitI2S0SD_MCLK() -> I2SMCLK_SMT)
#define vSetI2S0SD_MCLK_I2SMCLK_SMT(ParValue)  (pst_bitI2S0SD_MCLK() -> I2SMCLK_SMT=(ParValue))
#define biGetI2S0SD_MCLK_I2SMCLK_IMP() (pst_bitI2S0SD_MCLK() -> I2SMCLK_IMP)
#define vSetI2S0SD_MCLK_I2SMCLK_IMP(ParValue)  (pst_bitI2S0SD_MCLK() -> I2SMCLK_IMP=(ParValue))
#define biGetI2S0SD_MCLK_I2SMCLK_LATCHN() (pst_bitI2S0SD_MCLK() -> I2SMCLK_LATCHN)
#define vSetI2S0SD_MCLK_I2SMCLK_LATCHN(ParValue)  (pst_bitI2S0SD_MCLK() -> I2SMCLK_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetI2S0SD_MCLKLL(ParValue) (pst_u8I2S0SD_MCLK() -> u8LL = (ParValue))
#define u8GetI2S0SD_MCLKLL() (pst_u8I2S0SD_MCLK() -> u8LL)
/* LH-struct byte access */
#define vSetI2S0SD_MCLKLH(ParValue) (pst_u8I2S0SD_MCLK() -> u8LH = (ParValue))
#define u8GetI2S0SD_MCLKLH() (pst_u8I2S0SD_MCLK() -> u8LH)
/* HL-struct byte access */
#define vSetI2S0SD_MCLKHL(ParValue) (pst_u8I2S0SD_MCLK() -> u8HL = (ParValue))
#define u8GetI2S0SD_MCLKHL() (pst_u8I2S0SD_MCLK() -> u8HL)
/* HH-struct byte access */
#define vSetI2S0SD_MCLKHH(ParValue) (pst_u8I2S0SD_MCLK() -> u8HH = (ParValue))
#define u8GetI2S0SD_MCLKHH() (pst_u8I2S0SD_MCLK() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetI2S0SD_MCLKL(ParValue) (pst_u16I2S0SD_MCLK() -> u16L = (ParValue))
#define u16GetI2S0SD_MCLKL() (pst_u16I2S0SD_MCLK() -> u16L)
#define vSetI2S0SD_MCLKH(ParValue) (pst_u16I2S0SD_MCLK() -> u16H = (ParValue))
#define u16GetI2S0SD_MCLKH() (pst_u16I2S0SD_MCLK() -> u16H)
            
/* Word access */
#define vSetI2S0SD_MCLK(ParValue)  (*pu32I2S0SD_MCLK() = (ParValue))
#define u32GetI2S0SD_MCLK()  (*pu32I2S0SD_MCLK() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PWMOUT00                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302204                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PWMOUT00_REG__       0xC0302204U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   PWMOUT00_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint16_t   	:5; 	 /* 3..7  bit(s) R */
  uint16_t   PWMOUT00_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   PWMOUT00_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   PWMOUT00_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint16_t   PWMOUT00_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint16_t   PWMOUT00_LATCHN	:1; 	 /* 13..13  bit(s) R/W */ 
  uint16_t   	:2; 	 /* 14..31  bit(s) R */                    
} PWMOUT00_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PWMOUT00_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PWMOUT00_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPWMOUT00()     ((volatile PWMOUT00_bit_view_st *)\
(PWMOUT00_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PWMOUT00()     ((volatile PWMOUT00_byte_view_st *)\
(PWMOUT00_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PWMOUT00()     ((volatile u16PWMOUT00_halfword_view *)\
(PWMOUT00_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPWMOUT00_PWMOUT00_SEL() (pst_bitPWMOUT00() -> PWMOUT00_SEL)
#define vSetPWMOUT00_PWMOUT00_SEL(ParValue)  (pst_bitPWMOUT00() -> PWMOUT00_SEL=(ParValue))
#define biGetPWMOUT00_PWMOUT00_PU() (pst_bitPWMOUT00() -> PWMOUT00_PU)
#define vSetPWMOUT00_PWMOUT00_PU(ParValue)  (pst_bitPWMOUT00() -> PWMOUT00_PU=(ParValue))
#define biGetPWMOUT00_PWMOUT00_PD() (pst_bitPWMOUT00() -> PWMOUT00_PD)
#define vSetPWMOUT00_PWMOUT00_PD(ParValue)  (pst_bitPWMOUT00() -> PWMOUT00_PD=(ParValue))
#define biGetPWMOUT00_PWMOUT00_SMT() (pst_bitPWMOUT00() -> PWMOUT00_SMT)
#define vSetPWMOUT00_PWMOUT00_SMT(ParValue)  (pst_bitPWMOUT00() -> PWMOUT00_SMT=(ParValue))
#define biGetPWMOUT00_PWMOUT00_IMP() (pst_bitPWMOUT00() -> PWMOUT00_IMP)
#define vSetPWMOUT00_PWMOUT00_IMP(ParValue)  (pst_bitPWMOUT00() -> PWMOUT00_IMP=(ParValue))
#define biGetPWMOUT00_PWMOUT00_LATCHN() (pst_bitPWMOUT00() -> PWMOUT00_LATCHN)
#define vSetPWMOUT00_PWMOUT00_LATCHN(ParValue)  (pst_bitPWMOUT00() -> PWMOUT00_LATCHN=(ParValue))
            
/* L-struct byte access */
#define vSetPWMOUT00L(ParValue) (pst_u8PWMOUT00() -> u8L = (ParValue))
#define u8GetPWMOUT00L() (pst_u8PWMOUT00() -> u8L)
/* H-struct byte access */
#define vSetPWMOUT00H(ParValue) (pst_u8PWMOUT00() -> u8H = (ParValue))
#define u8GetPWMOUT00H() (pst_u8PWMOUT00() -> u8H)
            
/* Half-word access */ 
#define vSetPWMOUT00(ParValue) (*pu16PWMOUT00()  = (ParValue))
#define u16GetPWMOUT00() (*pu16PWMOUT00() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: HSPWM0_0N                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302208                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define HSPWM0_0N_REG__       0xC0302208U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   HSPWM0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   HSPWM0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   HSPWM0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   HSPWM0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   HSPWM0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   HSPWM0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   HSPWM0N_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   HSPWM0N_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   HSPWM0N_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   HSPWM0N_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   HSPWM0N_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   HSPWM0N_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} HSPWM0_0N_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} HSPWM0_0N_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} HSPWM0_0N_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32HSPWM0_0N_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitHSPWM0_0N()     ((volatile HSPWM0_0N_bit_view_st *)\
(HSPWM0_0N_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8HSPWM0_0N()     ((volatile HSPWM0_0N_byte_view_st *)\
(HSPWM0_0N_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16HSPWM0_0N()     ((volatile HSPWM0_0N_halfword_view_st *)\
(HSPWM0_0N_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32HSPWM0_0N()     ((volatile u32HSPWM0_0N_word_view *)\
(HSPWM0_0N_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetHSPWM0_0N_HSPWM0_SEL() (pst_bitHSPWM0_0N() -> HSPWM0_SEL)
#define vSetHSPWM0_0N_HSPWM0_SEL(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0_SEL=(ParValue))
#define biGetHSPWM0_0N_HSPWM0_PU() (pst_bitHSPWM0_0N() -> HSPWM0_PU)
#define vSetHSPWM0_0N_HSPWM0_PU(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0_PU=(ParValue))
#define biGetHSPWM0_0N_HSPWM0_PD() (pst_bitHSPWM0_0N() -> HSPWM0_PD)
#define vSetHSPWM0_0N_HSPWM0_PD(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0_PD=(ParValue))
#define biGetHSPWM0_0N_HSPWM0_SMT() (pst_bitHSPWM0_0N() -> HSPWM0_SMT)
#define vSetHSPWM0_0N_HSPWM0_SMT(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0_SMT=(ParValue))
#define biGetHSPWM0_0N_HSPWM0_IMP() (pst_bitHSPWM0_0N() -> HSPWM0_IMP)
#define vSetHSPWM0_0N_HSPWM0_IMP(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0_IMP=(ParValue))
#define biGetHSPWM0_0N_HSPWM0_LATCHN() (pst_bitHSPWM0_0N() -> HSPWM0_LATCHN)
#define vSetHSPWM0_0N_HSPWM0_LATCHN(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0_LATCHN=(ParValue))
#define biGetHSPWM0_0N_HSPWM0N_SEL() (pst_bitHSPWM0_0N() -> HSPWM0N_SEL)
#define vSetHSPWM0_0N_HSPWM0N_SEL(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0N_SEL=(ParValue))
#define biGetHSPWM0_0N_HSPWM0N_PU() (pst_bitHSPWM0_0N() -> HSPWM0N_PU)
#define vSetHSPWM0_0N_HSPWM0N_PU(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0N_PU=(ParValue))
#define biGetHSPWM0_0N_HSPWM0N_PD() (pst_bitHSPWM0_0N() -> HSPWM0N_PD)
#define vSetHSPWM0_0N_HSPWM0N_PD(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0N_PD=(ParValue))
#define biGetHSPWM0_0N_HSPWM0N_SMT() (pst_bitHSPWM0_0N() -> HSPWM0N_SMT)
#define vSetHSPWM0_0N_HSPWM0N_SMT(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0N_SMT=(ParValue))
#define biGetHSPWM0_0N_HSPWM0N_IMP() (pst_bitHSPWM0_0N() -> HSPWM0N_IMP)
#define vSetHSPWM0_0N_HSPWM0N_IMP(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0N_IMP=(ParValue))
#define biGetHSPWM0_0N_HSPWM0N_LATCHN() (pst_bitHSPWM0_0N() -> HSPWM0N_LATCHN)
#define vSetHSPWM0_0N_HSPWM0N_LATCHN(ParValue)  (pst_bitHSPWM0_0N() -> HSPWM0N_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetHSPWM0_0NLL(ParValue) (pst_u8HSPWM0_0N() -> u8LL = (ParValue))
#define u8GetHSPWM0_0NLL() (pst_u8HSPWM0_0N() -> u8LL)
/* LH-struct byte access */
#define vSetHSPWM0_0NLH(ParValue) (pst_u8HSPWM0_0N() -> u8LH = (ParValue))
#define u8GetHSPWM0_0NLH() (pst_u8HSPWM0_0N() -> u8LH)
/* HL-struct byte access */
#define vSetHSPWM0_0NHL(ParValue) (pst_u8HSPWM0_0N() -> u8HL = (ParValue))
#define u8GetHSPWM0_0NHL() (pst_u8HSPWM0_0N() -> u8HL)
/* HH-struct byte access */
#define vSetHSPWM0_0NHH(ParValue) (pst_u8HSPWM0_0N() -> u8HH = (ParValue))
#define u8GetHSPWM0_0NHH() (pst_u8HSPWM0_0N() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetHSPWM0_0NL(ParValue) (pst_u16HSPWM0_0N() -> u16L = (ParValue))
#define u16GetHSPWM0_0NL() (pst_u16HSPWM0_0N() -> u16L)
#define vSetHSPWM0_0NH(ParValue) (pst_u16HSPWM0_0N() -> u16H = (ParValue))
#define u16GetHSPWM0_0NH() (pst_u16HSPWM0_0N() -> u16H)
            
/* Word access */
#define vSetHSPWM0_0N(ParValue)  (*pu32HSPWM0_0N() = (ParValue))
#define u32GetHSPWM0_0N()  (*pu32HSPWM0_0N() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: HSPWM1_1N                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030220C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define HSPWM1_1N_REG__       0xC030220CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   HSPWM1_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   HSPWM1_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   HSPWM1_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   HSPWM1_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   HSPWM1_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   HSPWM1_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   HSPWM1N_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   HSPWM1N_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   HSPWM1N_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   HSPWM1N_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   HSPWM1N_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   HSPWM1N_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} HSPWM1_1N_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} HSPWM1_1N_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} HSPWM1_1N_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32HSPWM1_1N_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitHSPWM1_1N()     ((volatile HSPWM1_1N_bit_view_st *)\
(HSPWM1_1N_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8HSPWM1_1N()     ((volatile HSPWM1_1N_byte_view_st *)\
(HSPWM1_1N_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16HSPWM1_1N()     ((volatile HSPWM1_1N_halfword_view_st *)\
(HSPWM1_1N_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32HSPWM1_1N()     ((volatile u32HSPWM1_1N_word_view *)\
(HSPWM1_1N_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetHSPWM1_1N_HSPWM1_SEL() (pst_bitHSPWM1_1N() -> HSPWM1_SEL)
#define vSetHSPWM1_1N_HSPWM1_SEL(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1_SEL=(ParValue))
#define biGetHSPWM1_1N_HSPWM1_PU() (pst_bitHSPWM1_1N() -> HSPWM1_PU)
#define vSetHSPWM1_1N_HSPWM1_PU(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1_PU=(ParValue))
#define biGetHSPWM1_1N_HSPWM1_PD() (pst_bitHSPWM1_1N() -> HSPWM1_PD)
#define vSetHSPWM1_1N_HSPWM1_PD(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1_PD=(ParValue))
#define biGetHSPWM1_1N_HSPWM1_SMT() (pst_bitHSPWM1_1N() -> HSPWM1_SMT)
#define vSetHSPWM1_1N_HSPWM1_SMT(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1_SMT=(ParValue))
#define biGetHSPWM1_1N_HSPWM1_IMP() (pst_bitHSPWM1_1N() -> HSPWM1_IMP)
#define vSetHSPWM1_1N_HSPWM1_IMP(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1_IMP=(ParValue))
#define biGetHSPWM1_1N_HSPWM1_LATCHN() (pst_bitHSPWM1_1N() -> HSPWM1_LATCHN)
#define vSetHSPWM1_1N_HSPWM1_LATCHN(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1_LATCHN=(ParValue))
#define biGetHSPWM1_1N_HSPWM1N_SEL() (pst_bitHSPWM1_1N() -> HSPWM1N_SEL)
#define vSetHSPWM1_1N_HSPWM1N_SEL(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1N_SEL=(ParValue))
#define biGetHSPWM1_1N_HSPWM1N_PU() (pst_bitHSPWM1_1N() -> HSPWM1N_PU)
#define vSetHSPWM1_1N_HSPWM1N_PU(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1N_PU=(ParValue))
#define biGetHSPWM1_1N_HSPWM1N_PD() (pst_bitHSPWM1_1N() -> HSPWM1N_PD)
#define vSetHSPWM1_1N_HSPWM1N_PD(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1N_PD=(ParValue))
#define biGetHSPWM1_1N_HSPWM1N_SMT() (pst_bitHSPWM1_1N() -> HSPWM1N_SMT)
#define vSetHSPWM1_1N_HSPWM1N_SMT(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1N_SMT=(ParValue))
#define biGetHSPWM1_1N_HSPWM1N_IMP() (pst_bitHSPWM1_1N() -> HSPWM1N_IMP)
#define vSetHSPWM1_1N_HSPWM1N_IMP(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1N_IMP=(ParValue))
#define biGetHSPWM1_1N_HSPWM1N_LATCHN() (pst_bitHSPWM1_1N() -> HSPWM1N_LATCHN)
#define vSetHSPWM1_1N_HSPWM1N_LATCHN(ParValue)  (pst_bitHSPWM1_1N() -> HSPWM1N_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetHSPWM1_1NLL(ParValue) (pst_u8HSPWM1_1N() -> u8LL = (ParValue))
#define u8GetHSPWM1_1NLL() (pst_u8HSPWM1_1N() -> u8LL)
/* LH-struct byte access */
#define vSetHSPWM1_1NLH(ParValue) (pst_u8HSPWM1_1N() -> u8LH = (ParValue))
#define u8GetHSPWM1_1NLH() (pst_u8HSPWM1_1N() -> u8LH)
/* HL-struct byte access */
#define vSetHSPWM1_1NHL(ParValue) (pst_u8HSPWM1_1N() -> u8HL = (ParValue))
#define u8GetHSPWM1_1NHL() (pst_u8HSPWM1_1N() -> u8HL)
/* HH-struct byte access */
#define vSetHSPWM1_1NHH(ParValue) (pst_u8HSPWM1_1N() -> u8HH = (ParValue))
#define u8GetHSPWM1_1NHH() (pst_u8HSPWM1_1N() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetHSPWM1_1NL(ParValue) (pst_u16HSPWM1_1N() -> u16L = (ParValue))
#define u16GetHSPWM1_1NL() (pst_u16HSPWM1_1N() -> u16L)
#define vSetHSPWM1_1NH(ParValue) (pst_u16HSPWM1_1N() -> u16H = (ParValue))
#define u16GetHSPWM1_1NH() (pst_u16HSPWM1_1N() -> u16H)
            
/* Word access */
#define vSetHSPWM1_1N(ParValue)  (*pu32HSPWM1_1N() = (ParValue))
#define u32GetHSPWM1_1N()  (*pu32HSPWM1_1N() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: UART0RX_TX                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302210                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define UART0RX_TX_REG__       0xC0302210U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   UART0RX_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   UART0RX_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   UART0RX_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   UART0RX_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   UART0RX_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   UART0RX_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   UART0TX_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   UART0TX_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   UART0TX_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   UART0TX_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   UART0TX_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   UART0TX_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} UART0RX_TX_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} UART0RX_TX_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} UART0RX_TX_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32UART0RX_TX_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitUART0RX_TX()     ((volatile UART0RX_TX_bit_view_st *)\
(UART0RX_TX_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8UART0RX_TX()     ((volatile UART0RX_TX_byte_view_st *)\
(UART0RX_TX_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16UART0RX_TX()     ((volatile UART0RX_TX_halfword_view_st *)\
(UART0RX_TX_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32UART0RX_TX()     ((volatile u32UART0RX_TX_word_view *)\
(UART0RX_TX_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetUART0RX_TX_UART0RX_SEL() (pst_bitUART0RX_TX() -> UART0RX_SEL)
#define vSetUART0RX_TX_UART0RX_SEL(ParValue)  (pst_bitUART0RX_TX() -> UART0RX_SEL=(ParValue))
#define biGetUART0RX_TX_UART0RX_PU() (pst_bitUART0RX_TX() -> UART0RX_PU)
#define vSetUART0RX_TX_UART0RX_PU(ParValue)  (pst_bitUART0RX_TX() -> UART0RX_PU=(ParValue))
#define biGetUART0RX_TX_UART0RX_PD() (pst_bitUART0RX_TX() -> UART0RX_PD)
#define vSetUART0RX_TX_UART0RX_PD(ParValue)  (pst_bitUART0RX_TX() -> UART0RX_PD=(ParValue))
#define biGetUART0RX_TX_UART0RX_SMT() (pst_bitUART0RX_TX() -> UART0RX_SMT)
#define vSetUART0RX_TX_UART0RX_SMT(ParValue)  (pst_bitUART0RX_TX() -> UART0RX_SMT=(ParValue))
#define biGetUART0RX_TX_UART0RX_IMP() (pst_bitUART0RX_TX() -> UART0RX_IMP)
#define vSetUART0RX_TX_UART0RX_IMP(ParValue)  (pst_bitUART0RX_TX() -> UART0RX_IMP=(ParValue))
#define biGetUART0RX_TX_UART0RX_LATCHN() (pst_bitUART0RX_TX() -> UART0RX_LATCHN)
#define vSetUART0RX_TX_UART0RX_LATCHN(ParValue)  (pst_bitUART0RX_TX() -> UART0RX_LATCHN=(ParValue))
#define biGetUART0RX_TX_UART0TX_SEL() (pst_bitUART0RX_TX() -> UART0TX_SEL)
#define vSetUART0RX_TX_UART0TX_SEL(ParValue)  (pst_bitUART0RX_TX() -> UART0TX_SEL=(ParValue))
#define biGetUART0RX_TX_UART0TX_PU() (pst_bitUART0RX_TX() -> UART0TX_PU)
#define vSetUART0RX_TX_UART0TX_PU(ParValue)  (pst_bitUART0RX_TX() -> UART0TX_PU=(ParValue))
#define biGetUART0RX_TX_UART0TX_PD() (pst_bitUART0RX_TX() -> UART0TX_PD)
#define vSetUART0RX_TX_UART0TX_PD(ParValue)  (pst_bitUART0RX_TX() -> UART0TX_PD=(ParValue))
#define biGetUART0RX_TX_UART0TX_SMT() (pst_bitUART0RX_TX() -> UART0TX_SMT)
#define vSetUART0RX_TX_UART0TX_SMT(ParValue)  (pst_bitUART0RX_TX() -> UART0TX_SMT=(ParValue))
#define biGetUART0RX_TX_UART0TX_IMP() (pst_bitUART0RX_TX() -> UART0TX_IMP)
#define vSetUART0RX_TX_UART0TX_IMP(ParValue)  (pst_bitUART0RX_TX() -> UART0TX_IMP=(ParValue))
#define biGetUART0RX_TX_UART0TX_LATCHN() (pst_bitUART0RX_TX() -> UART0TX_LATCHN)
#define vSetUART0RX_TX_UART0TX_LATCHN(ParValue)  (pst_bitUART0RX_TX() -> UART0TX_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetUART0RX_TXLL(ParValue) (pst_u8UART0RX_TX() -> u8LL = (ParValue))
#define u8GetUART0RX_TXLL() (pst_u8UART0RX_TX() -> u8LL)
/* LH-struct byte access */
#define vSetUART0RX_TXLH(ParValue) (pst_u8UART0RX_TX() -> u8LH = (ParValue))
#define u8GetUART0RX_TXLH() (pst_u8UART0RX_TX() -> u8LH)
/* HL-struct byte access */
#define vSetUART0RX_TXHL(ParValue) (pst_u8UART0RX_TX() -> u8HL = (ParValue))
#define u8GetUART0RX_TXHL() (pst_u8UART0RX_TX() -> u8HL)
/* HH-struct byte access */
#define vSetUART0RX_TXHH(ParValue) (pst_u8UART0RX_TX() -> u8HH = (ParValue))
#define u8GetUART0RX_TXHH() (pst_u8UART0RX_TX() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetUART0RX_TXL(ParValue) (pst_u16UART0RX_TX() -> u16L = (ParValue))
#define u16GetUART0RX_TXL() (pst_u16UART0RX_TX() -> u16L)
#define vSetUART0RX_TXH(ParValue) (pst_u16UART0RX_TX() -> u16H = (ParValue))
#define u16GetUART0RX_TXH() (pst_u16UART0RX_TX() -> u16H)
            
/* Word access */
#define vSetUART0RX_TX(ParValue)  (*pu32UART0RX_TX() = (ParValue))
#define u32GetUART0RX_TX()  (*pu32UART0RX_TX() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIP_QSPI_SIO0_SIO1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302220                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIP_QSPI_SIO0_SIO1_REG__       0xC0302220U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   SIP_QSPI_SIO0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO0_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO0_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   SIP_QSPI_SIO1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO1_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO1_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} SIP_QSPI_SIO0_SIO1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SIP_QSPI_SIO0_SIO1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SIP_QSPI_SIO0_SIO1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SIP_QSPI_SIO0_SIO1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIP_QSPI_SIO0_SIO1()     ((volatile SIP_QSPI_SIO0_SIO1_bit_view_st *)\
(SIP_QSPI_SIO0_SIO1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SIP_QSPI_SIO0_SIO1()     ((volatile SIP_QSPI_SIO0_SIO1_byte_view_st *)\
(SIP_QSPI_SIO0_SIO1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SIP_QSPI_SIO0_SIO1()     ((volatile SIP_QSPI_SIO0_SIO1_halfword_view_st *)\
(SIP_QSPI_SIO0_SIO1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SIP_QSPI_SIO0_SIO1()     ((volatile u32SIP_QSPI_SIO0_SIO1_word_view *)\
(SIP_QSPI_SIO0_SIO1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_PU() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_PU)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_PU(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_PU=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_PD() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_PD)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_PD(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_PD=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_SMT() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_SMT)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_SMT(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_SMT=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_IMP() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_IMP)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_IMP(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_IMP=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_LATCHN() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_LATCHN)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO0_LATCHN(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO0_LATCHN=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_PU() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_PU)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_PU(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_PU=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_PD() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_PD)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_PD(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_PD=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_SMT() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_SMT)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_SMT(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_SMT=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_IMP() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_IMP)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_IMP(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_IMP=(ParValue))
#define biGetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_LATCHN() (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_LATCHN)
#define vSetSIP_QSPI_SIO0_SIO1_SIP_QSPI_SIO1_LATCHN(ParValue)  (pst_bitSIP_QSPI_SIO0_SIO1() -> SIP_QSPI_SIO1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetSIP_QSPI_SIO0_SIO1LL(ParValue) (pst_u8SIP_QSPI_SIO0_SIO1() -> u8LL = (ParValue))
#define u8GetSIP_QSPI_SIO0_SIO1LL() (pst_u8SIP_QSPI_SIO0_SIO1() -> u8LL)
/* LH-struct byte access */
#define vSetSIP_QSPI_SIO0_SIO1LH(ParValue) (pst_u8SIP_QSPI_SIO0_SIO1() -> u8LH = (ParValue))
#define u8GetSIP_QSPI_SIO0_SIO1LH() (pst_u8SIP_QSPI_SIO0_SIO1() -> u8LH)
/* HL-struct byte access */
#define vSetSIP_QSPI_SIO0_SIO1HL(ParValue) (pst_u8SIP_QSPI_SIO0_SIO1() -> u8HL = (ParValue))
#define u8GetSIP_QSPI_SIO0_SIO1HL() (pst_u8SIP_QSPI_SIO0_SIO1() -> u8HL)
/* HH-struct byte access */
#define vSetSIP_QSPI_SIO0_SIO1HH(ParValue) (pst_u8SIP_QSPI_SIO0_SIO1() -> u8HH = (ParValue))
#define u8GetSIP_QSPI_SIO0_SIO1HH() (pst_u8SIP_QSPI_SIO0_SIO1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSIP_QSPI_SIO0_SIO1L(ParValue) (pst_u16SIP_QSPI_SIO0_SIO1() -> u16L = (ParValue))
#define u16GetSIP_QSPI_SIO0_SIO1L() (pst_u16SIP_QSPI_SIO0_SIO1() -> u16L)
#define vSetSIP_QSPI_SIO0_SIO1H(ParValue) (pst_u16SIP_QSPI_SIO0_SIO1() -> u16H = (ParValue))
#define u16GetSIP_QSPI_SIO0_SIO1H() (pst_u16SIP_QSPI_SIO0_SIO1() -> u16H)
            
/* Word access */
#define vSetSIP_QSPI_SIO0_SIO1(ParValue)  (*pu32SIP_QSPI_SIO0_SIO1() = (ParValue))
#define u32GetSIP_QSPI_SIO0_SIO1()  (*pu32SIP_QSPI_SIO0_SIO1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIP_QSPI_SIO2_SIO3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302224                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIP_QSPI_SIO2_SIO3_REG__       0xC0302224U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   SIP_QSPI_SIO2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO2_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO2_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   SIP_QSPI_SIO3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO3_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO3_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   SIP_QSPI_SIO3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} SIP_QSPI_SIO2_SIO3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SIP_QSPI_SIO2_SIO3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SIP_QSPI_SIO2_SIO3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SIP_QSPI_SIO2_SIO3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIP_QSPI_SIO2_SIO3()     ((volatile SIP_QSPI_SIO2_SIO3_bit_view_st *)\
(SIP_QSPI_SIO2_SIO3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SIP_QSPI_SIO2_SIO3()     ((volatile SIP_QSPI_SIO2_SIO3_byte_view_st *)\
(SIP_QSPI_SIO2_SIO3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SIP_QSPI_SIO2_SIO3()     ((volatile SIP_QSPI_SIO2_SIO3_halfword_view_st *)\
(SIP_QSPI_SIO2_SIO3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SIP_QSPI_SIO2_SIO3()     ((volatile u32SIP_QSPI_SIO2_SIO3_word_view *)\
(SIP_QSPI_SIO2_SIO3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_PU() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_PU)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_PU(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_PU=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_PD() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_PD)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_PD(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_PD=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_SMT() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_SMT)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_SMT(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_SMT=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_IMP() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_IMP)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_IMP(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_IMP=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_LATCHN() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_LATCHN)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO2_LATCHN(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO2_LATCHN=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_PU() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_PU)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_PU(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_PU=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_PD() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_PD)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_PD(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_PD=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_SMT() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_SMT)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_SMT(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_SMT=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_IMP() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_IMP)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_IMP(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_IMP=(ParValue))
#define biGetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_LATCHN() (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_LATCHN)
#define vSetSIP_QSPI_SIO2_SIO3_SIP_QSPI_SIO3_LATCHN(ParValue)  (pst_bitSIP_QSPI_SIO2_SIO3() -> SIP_QSPI_SIO3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetSIP_QSPI_SIO2_SIO3LL(ParValue) (pst_u8SIP_QSPI_SIO2_SIO3() -> u8LL = (ParValue))
#define u8GetSIP_QSPI_SIO2_SIO3LL() (pst_u8SIP_QSPI_SIO2_SIO3() -> u8LL)
/* LH-struct byte access */
#define vSetSIP_QSPI_SIO2_SIO3LH(ParValue) (pst_u8SIP_QSPI_SIO2_SIO3() -> u8LH = (ParValue))
#define u8GetSIP_QSPI_SIO2_SIO3LH() (pst_u8SIP_QSPI_SIO2_SIO3() -> u8LH)
/* HL-struct byte access */
#define vSetSIP_QSPI_SIO2_SIO3HL(ParValue) (pst_u8SIP_QSPI_SIO2_SIO3() -> u8HL = (ParValue))
#define u8GetSIP_QSPI_SIO2_SIO3HL() (pst_u8SIP_QSPI_SIO2_SIO3() -> u8HL)
/* HH-struct byte access */
#define vSetSIP_QSPI_SIO2_SIO3HH(ParValue) (pst_u8SIP_QSPI_SIO2_SIO3() -> u8HH = (ParValue))
#define u8GetSIP_QSPI_SIO2_SIO3HH() (pst_u8SIP_QSPI_SIO2_SIO3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSIP_QSPI_SIO2_SIO3L(ParValue) (pst_u16SIP_QSPI_SIO2_SIO3() -> u16L = (ParValue))
#define u16GetSIP_QSPI_SIO2_SIO3L() (pst_u16SIP_QSPI_SIO2_SIO3() -> u16L)
#define vSetSIP_QSPI_SIO2_SIO3H(ParValue) (pst_u16SIP_QSPI_SIO2_SIO3() -> u16H = (ParValue))
#define u16GetSIP_QSPI_SIO2_SIO3H() (pst_u16SIP_QSPI_SIO2_SIO3() -> u16H)
            
/* Word access */
#define vSetSIP_QSPI_SIO2_SIO3(ParValue)  (*pu32SIP_QSPI_SIO2_SIO3() = (ParValue))
#define u32GetSIP_QSPI_SIO2_SIO3()  (*pu32SIP_QSPI_SIO2_SIO3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIP_QSPI_CS_SCLK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302228                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIP_QSPI_CS_SCLK_REG__       0xC0302228U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   SIP_QSPI_CS_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   SIP_QSPI_CS_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   SIP_QSPI_CS_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   SIP_QSPI_CS_IMP	:2; 	 /* 11..12  bit(s) R/W */
  uint32_t   SIP_QSPI_CS_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   SIP_QSPI_SCLK_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   SIP_QSPI_SCLK_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   SIP_QSPI_SCLK_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   SIP_QSPI_SCLK_IMP	:2; 	 /* 27..28  bit(s) R/W */
  uint32_t   SIP_QSPI_SCLK_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} SIP_QSPI_CS_SCLK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SIP_QSPI_CS_SCLK_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SIP_QSPI_CS_SCLK_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SIP_QSPI_CS_SCLK_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIP_QSPI_CS_SCLK()     ((volatile SIP_QSPI_CS_SCLK_bit_view_st *)\
(SIP_QSPI_CS_SCLK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SIP_QSPI_CS_SCLK()     ((volatile SIP_QSPI_CS_SCLK_byte_view_st *)\
(SIP_QSPI_CS_SCLK_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SIP_QSPI_CS_SCLK()     ((volatile SIP_QSPI_CS_SCLK_halfword_view_st *)\
(SIP_QSPI_CS_SCLK_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SIP_QSPI_CS_SCLK()     ((volatile u32SIP_QSPI_CS_SCLK_word_view *)\
(SIP_QSPI_CS_SCLK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_PU() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_PU)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_PU(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_PU=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_PD() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_PD)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_PD(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_PD=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_SMT() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_SMT)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_SMT(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_SMT=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_IMP() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_IMP)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_IMP(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_IMP=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_LATCHN() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_LATCHN)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_CS_LATCHN(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_CS_LATCHN=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_PU() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_PU)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_PU(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_PU=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_PD() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_PD)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_PD(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_PD=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_SMT() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_SMT)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_SMT(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_SMT=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_IMP() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_IMP)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_IMP(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_IMP=(ParValue))
#define biGetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_LATCHN() (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_LATCHN)
#define vSetSIP_QSPI_CS_SCLK_SIP_QSPI_SCLK_LATCHN(ParValue)  (pst_bitSIP_QSPI_CS_SCLK() -> SIP_QSPI_SCLK_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetSIP_QSPI_CS_SCLKLL(ParValue) (pst_u8SIP_QSPI_CS_SCLK() -> u8LL = (ParValue))
#define u8GetSIP_QSPI_CS_SCLKLL() (pst_u8SIP_QSPI_CS_SCLK() -> u8LL)
/* LH-struct byte access */
#define vSetSIP_QSPI_CS_SCLKLH(ParValue) (pst_u8SIP_QSPI_CS_SCLK() -> u8LH = (ParValue))
#define u8GetSIP_QSPI_CS_SCLKLH() (pst_u8SIP_QSPI_CS_SCLK() -> u8LH)
/* HL-struct byte access */
#define vSetSIP_QSPI_CS_SCLKHL(ParValue) (pst_u8SIP_QSPI_CS_SCLK() -> u8HL = (ParValue))
#define u8GetSIP_QSPI_CS_SCLKHL() (pst_u8SIP_QSPI_CS_SCLK() -> u8HL)
/* HH-struct byte access */
#define vSetSIP_QSPI_CS_SCLKHH(ParValue) (pst_u8SIP_QSPI_CS_SCLK() -> u8HH = (ParValue))
#define u8GetSIP_QSPI_CS_SCLKHH() (pst_u8SIP_QSPI_CS_SCLK() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSIP_QSPI_CS_SCLKL(ParValue) (pst_u16SIP_QSPI_CS_SCLK() -> u16L = (ParValue))
#define u16GetSIP_QSPI_CS_SCLKL() (pst_u16SIP_QSPI_CS_SCLK() -> u16L)
#define vSetSIP_QSPI_CS_SCLKH(ParValue) (pst_u16SIP_QSPI_CS_SCLK() -> u16H = (ParValue))
#define u16GetSIP_QSPI_CS_SCLKH() (pst_u16SIP_QSPI_CS_SCLK() -> u16H)
            
/* Word access */
#define vSetSIP_QSPI_CS_SCLK(ParValue)  (*pu32SIP_QSPI_CS_SCLK() = (ParValue))
#define u32GetSIP_QSPI_CS_SCLK()  (*pu32SIP_QSPI_CS_SCLK() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: NMI_RESETN                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302230                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define NMI_RESETN_REG__       0xC0302230U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   NMI_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   NMI_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   NMI_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   NMI_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   RESETN_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   RESETN_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   RESETN_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   RESETN_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} NMI_RESETN_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} NMI_RESETN_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} NMI_RESETN_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32NMI_RESETN_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitNMI_RESETN()     ((volatile NMI_RESETN_bit_view_st *)\
(NMI_RESETN_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8NMI_RESETN()     ((volatile NMI_RESETN_byte_view_st *)\
(NMI_RESETN_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16NMI_RESETN()     ((volatile NMI_RESETN_halfword_view_st *)\
(NMI_RESETN_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32NMI_RESETN()     ((volatile u32NMI_RESETN_word_view *)\
(NMI_RESETN_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetNMI_RESETN_NMI_PU() (pst_bitNMI_RESETN() -> NMI_PU)
#define vSetNMI_RESETN_NMI_PU(ParValue)  (pst_bitNMI_RESETN() -> NMI_PU=(ParValue))
#define biGetNMI_RESETN_NMI_PD() (pst_bitNMI_RESETN() -> NMI_PD)
#define vSetNMI_RESETN_NMI_PD(ParValue)  (pst_bitNMI_RESETN() -> NMI_PD=(ParValue))
#define biGetNMI_RESETN_NMI_SMT() (pst_bitNMI_RESETN() -> NMI_SMT)
#define vSetNMI_RESETN_NMI_SMT(ParValue)  (pst_bitNMI_RESETN() -> NMI_SMT=(ParValue))
#define biGetNMI_RESETN_NMI_LATCHN() (pst_bitNMI_RESETN() -> NMI_LATCHN)
#define vSetNMI_RESETN_NMI_LATCHN(ParValue)  (pst_bitNMI_RESETN() -> NMI_LATCHN=(ParValue))
#define biGetNMI_RESETN_RESETN_PU() (pst_bitNMI_RESETN() -> RESETN_PU)
#define vSetNMI_RESETN_RESETN_PU(ParValue)  (pst_bitNMI_RESETN() -> RESETN_PU=(ParValue))
#define biGetNMI_RESETN_RESETN_PD() (pst_bitNMI_RESETN() -> RESETN_PD)
#define vSetNMI_RESETN_RESETN_PD(ParValue)  (pst_bitNMI_RESETN() -> RESETN_PD=(ParValue))
#define biGetNMI_RESETN_RESETN_SMT() (pst_bitNMI_RESETN() -> RESETN_SMT)
#define vSetNMI_RESETN_RESETN_SMT(ParValue)  (pst_bitNMI_RESETN() -> RESETN_SMT=(ParValue))
#define biGetNMI_RESETN_RESETN_LATCHN() (pst_bitNMI_RESETN() -> RESETN_LATCHN)
#define vSetNMI_RESETN_RESETN_LATCHN(ParValue)  (pst_bitNMI_RESETN() -> RESETN_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetNMI_RESETNLL(ParValue) (pst_u8NMI_RESETN() -> u8LL = (ParValue))
#define u8GetNMI_RESETNLL() (pst_u8NMI_RESETN() -> u8LL)
/* LH-struct byte access */
#define vSetNMI_RESETNLH(ParValue) (pst_u8NMI_RESETN() -> u8LH = (ParValue))
#define u8GetNMI_RESETNLH() (pst_u8NMI_RESETN() -> u8LH)
/* HL-struct byte access */
#define vSetNMI_RESETNHL(ParValue) (pst_u8NMI_RESETN() -> u8HL = (ParValue))
#define u8GetNMI_RESETNHL() (pst_u8NMI_RESETN() -> u8HL)
/* HH-struct byte access */
#define vSetNMI_RESETNHH(ParValue) (pst_u8NMI_RESETN() -> u8HH = (ParValue))
#define u8GetNMI_RESETNHH() (pst_u8NMI_RESETN() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetNMI_RESETNL(ParValue) (pst_u16NMI_RESETN() -> u16L = (ParValue))
#define u16GetNMI_RESETNL() (pst_u16NMI_RESETN() -> u16L)
#define vSetNMI_RESETNH(ParValue) (pst_u16NMI_RESETN() -> u16H = (ParValue))
#define u16GetNMI_RESETNH() (pst_u16NMI_RESETN() -> u16H)
            
/* Word access */
#define vSetNMI_RESETN(ParValue)  (*pu32NMI_RESETN() = (ParValue))
#define u32GetNMI_RESETN()  (*pu32NMI_RESETN() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DSU_JTAG_SEL_GTCK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302234                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DSU_JTAG_SEL_GTCK_REG__       0xC0302234U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   DSU_JTAG_SEL_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DSU_JTAG_SEL_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DSU_JTAG_SEL_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   DSU_JTAG_SEL_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   DSU_GTCK_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DSU_GTCK_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DSU_GTCK_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   DSU_GTCK_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} DSU_JTAG_SEL_GTCK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DSU_JTAG_SEL_GTCK_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DSU_JTAG_SEL_GTCK_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DSU_JTAG_SEL_GTCK_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDSU_JTAG_SEL_GTCK()     ((volatile DSU_JTAG_SEL_GTCK_bit_view_st *)\
(DSU_JTAG_SEL_GTCK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DSU_JTAG_SEL_GTCK()     ((volatile DSU_JTAG_SEL_GTCK_byte_view_st *)\
(DSU_JTAG_SEL_GTCK_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DSU_JTAG_SEL_GTCK()     ((volatile DSU_JTAG_SEL_GTCK_halfword_view_st *)\
(DSU_JTAG_SEL_GTCK_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DSU_JTAG_SEL_GTCK()     ((volatile u32DSU_JTAG_SEL_GTCK_word_view *)\
(DSU_JTAG_SEL_GTCK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDSU_JTAG_SEL_GTCK_DSU_JTAG_SEL_PU() (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_JTAG_SEL_PU)
#define vSetDSU_JTAG_SEL_GTCK_DSU_JTAG_SEL_PU(ParValue)  (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_JTAG_SEL_PU=(ParValue))
#define biGetDSU_JTAG_SEL_GTCK_DSU_JTAG_SEL_PD() (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_JTAG_SEL_PD)
#define vSetDSU_JTAG_SEL_GTCK_DSU_JTAG_SEL_PD(ParValue)  (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_JTAG_SEL_PD=(ParValue))
#define biGetDSU_JTAG_SEL_GTCK_DSU_JTAG_SEL_SMT() (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_JTAG_SEL_SMT)
#define vSetDSU_JTAG_SEL_GTCK_DSU_JTAG_SEL_SMT(ParValue)  (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_JTAG_SEL_SMT=(ParValue))
#define biGetDSU_JTAG_SEL_GTCK_DSU_JTAG_SEL_LATCHN() (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_JTAG_SEL_LATCHN)
#define vSetDSU_JTAG_SEL_GTCK_DSU_JTAG_SEL_LATCHN(ParValue)  (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_JTAG_SEL_LATCHN=(ParValue))
#define biGetDSU_JTAG_SEL_GTCK_DSU_GTCK_PU() (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_GTCK_PU)
#define vSetDSU_JTAG_SEL_GTCK_DSU_GTCK_PU(ParValue)  (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_GTCK_PU=(ParValue))
#define biGetDSU_JTAG_SEL_GTCK_DSU_GTCK_PD() (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_GTCK_PD)
#define vSetDSU_JTAG_SEL_GTCK_DSU_GTCK_PD(ParValue)  (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_GTCK_PD=(ParValue))
#define biGetDSU_JTAG_SEL_GTCK_DSU_GTCK_SMT() (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_GTCK_SMT)
#define vSetDSU_JTAG_SEL_GTCK_DSU_GTCK_SMT(ParValue)  (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_GTCK_SMT=(ParValue))
#define biGetDSU_JTAG_SEL_GTCK_DSU_GTCK_LATCHN() (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_GTCK_LATCHN)
#define vSetDSU_JTAG_SEL_GTCK_DSU_GTCK_LATCHN(ParValue)  (pst_bitDSU_JTAG_SEL_GTCK() -> DSU_GTCK_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetDSU_JTAG_SEL_GTCKLL(ParValue) (pst_u8DSU_JTAG_SEL_GTCK() -> u8LL = (ParValue))
#define u8GetDSU_JTAG_SEL_GTCKLL() (pst_u8DSU_JTAG_SEL_GTCK() -> u8LL)
/* LH-struct byte access */
#define vSetDSU_JTAG_SEL_GTCKLH(ParValue) (pst_u8DSU_JTAG_SEL_GTCK() -> u8LH = (ParValue))
#define u8GetDSU_JTAG_SEL_GTCKLH() (pst_u8DSU_JTAG_SEL_GTCK() -> u8LH)
/* HL-struct byte access */
#define vSetDSU_JTAG_SEL_GTCKHL(ParValue) (pst_u8DSU_JTAG_SEL_GTCK() -> u8HL = (ParValue))
#define u8GetDSU_JTAG_SEL_GTCKHL() (pst_u8DSU_JTAG_SEL_GTCK() -> u8HL)
/* HH-struct byte access */
#define vSetDSU_JTAG_SEL_GTCKHH(ParValue) (pst_u8DSU_JTAG_SEL_GTCK() -> u8HH = (ParValue))
#define u8GetDSU_JTAG_SEL_GTCKHH() (pst_u8DSU_JTAG_SEL_GTCK() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDSU_JTAG_SEL_GTCKL(ParValue) (pst_u16DSU_JTAG_SEL_GTCK() -> u16L = (ParValue))
#define u16GetDSU_JTAG_SEL_GTCKL() (pst_u16DSU_JTAG_SEL_GTCK() -> u16L)
#define vSetDSU_JTAG_SEL_GTCKH(ParValue) (pst_u16DSU_JTAG_SEL_GTCK() -> u16H = (ParValue))
#define u16GetDSU_JTAG_SEL_GTCKH() (pst_u16DSU_JTAG_SEL_GTCK() -> u16H)
            
/* Word access */
#define vSetDSU_JTAG_SEL_GTCK(ParValue)  (*pu32DSU_JTAG_SEL_GTCK() = (ParValue))
#define u32GetDSU_JTAG_SEL_GTCK()  (*pu32DSU_JTAG_SEL_GTCK() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DSU_GTDI_GTMS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302238                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DSU_GTDI_GTMS_REG__       0xC0302238U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   DSU_GTDI_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DSU_GTDI_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DSU_GTDI_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   DSU_GTDI_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   DSU_GTMS_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DSU_GTMS_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DSU_GTMS_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DSU_GTMS_IMP	:2; 	 /* 27..28  bit(s) R/W */ 
  uint32_t   	:3; 	 /* 29..31  bit(s) R */                    
} DSU_GTDI_GTMS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DSU_GTDI_GTMS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DSU_GTDI_GTMS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DSU_GTDI_GTMS_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDSU_GTDI_GTMS()     ((volatile DSU_GTDI_GTMS_bit_view_st *)\
(DSU_GTDI_GTMS_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DSU_GTDI_GTMS()     ((volatile DSU_GTDI_GTMS_byte_view_st *)\
(DSU_GTDI_GTMS_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DSU_GTDI_GTMS()     ((volatile DSU_GTDI_GTMS_halfword_view_st *)\
(DSU_GTDI_GTMS_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DSU_GTDI_GTMS()     ((volatile u32DSU_GTDI_GTMS_word_view *)\
(DSU_GTDI_GTMS_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDSU_GTDI_GTMS_DSU_GTDI_PU() (pst_bitDSU_GTDI_GTMS() -> DSU_GTDI_PU)
#define vSetDSU_GTDI_GTMS_DSU_GTDI_PU(ParValue)  (pst_bitDSU_GTDI_GTMS() -> DSU_GTDI_PU=(ParValue))
#define biGetDSU_GTDI_GTMS_DSU_GTDI_PD() (pst_bitDSU_GTDI_GTMS() -> DSU_GTDI_PD)
#define vSetDSU_GTDI_GTMS_DSU_GTDI_PD(ParValue)  (pst_bitDSU_GTDI_GTMS() -> DSU_GTDI_PD=(ParValue))
#define biGetDSU_GTDI_GTMS_DSU_GTDI_SMT() (pst_bitDSU_GTDI_GTMS() -> DSU_GTDI_SMT)
#define vSetDSU_GTDI_GTMS_DSU_GTDI_SMT(ParValue)  (pst_bitDSU_GTDI_GTMS() -> DSU_GTDI_SMT=(ParValue))
#define biGetDSU_GTDI_GTMS_DSU_GTDI_LATCHN() (pst_bitDSU_GTDI_GTMS() -> DSU_GTDI_LATCHN)
#define vSetDSU_GTDI_GTMS_DSU_GTDI_LATCHN(ParValue)  (pst_bitDSU_GTDI_GTMS() -> DSU_GTDI_LATCHN=(ParValue))
#define biGetDSU_GTDI_GTMS_DSU_GTMS_PU() (pst_bitDSU_GTDI_GTMS() -> DSU_GTMS_PU)
#define vSetDSU_GTDI_GTMS_DSU_GTMS_PU(ParValue)  (pst_bitDSU_GTDI_GTMS() -> DSU_GTMS_PU=(ParValue))
#define biGetDSU_GTDI_GTMS_DSU_GTMS_PD() (pst_bitDSU_GTDI_GTMS() -> DSU_GTMS_PD)
#define vSetDSU_GTDI_GTMS_DSU_GTMS_PD(ParValue)  (pst_bitDSU_GTDI_GTMS() -> DSU_GTMS_PD=(ParValue))
#define biGetDSU_GTDI_GTMS_DSU_GTMS_SMT() (pst_bitDSU_GTDI_GTMS() -> DSU_GTMS_SMT)
#define vSetDSU_GTDI_GTMS_DSU_GTMS_SMT(ParValue)  (pst_bitDSU_GTDI_GTMS() -> DSU_GTMS_SMT=(ParValue))
#define biGetDSU_GTDI_GTMS_DSU_GTMS_IMP() (pst_bitDSU_GTDI_GTMS() -> DSU_GTMS_IMP)
#define vSetDSU_GTDI_GTMS_DSU_GTMS_IMP(ParValue)  (pst_bitDSU_GTDI_GTMS() -> DSU_GTMS_IMP=(ParValue))
            
/* LL-struct byte access */
#define vSetDSU_GTDI_GTMSLL(ParValue) (pst_u8DSU_GTDI_GTMS() -> u8LL = (ParValue))
#define u8GetDSU_GTDI_GTMSLL() (pst_u8DSU_GTDI_GTMS() -> u8LL)
/* LH-struct byte access */
#define vSetDSU_GTDI_GTMSLH(ParValue) (pst_u8DSU_GTDI_GTMS() -> u8LH = (ParValue))
#define u8GetDSU_GTDI_GTMSLH() (pst_u8DSU_GTDI_GTMS() -> u8LH)
/* HL-struct byte access */
#define vSetDSU_GTDI_GTMSHL(ParValue) (pst_u8DSU_GTDI_GTMS() -> u8HL = (ParValue))
#define u8GetDSU_GTDI_GTMSHL() (pst_u8DSU_GTDI_GTMS() -> u8HL)
/* HH-struct byte access */
#define vSetDSU_GTDI_GTMSHH(ParValue) (pst_u8DSU_GTDI_GTMS() -> u8HH = (ParValue))
#define u8GetDSU_GTDI_GTMSHH() (pst_u8DSU_GTDI_GTMS() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDSU_GTDI_GTMSL(ParValue) (pst_u16DSU_GTDI_GTMS() -> u16L = (ParValue))
#define u16GetDSU_GTDI_GTMSL() (pst_u16DSU_GTDI_GTMS() -> u16L)
#define vSetDSU_GTDI_GTMSH(ParValue) (pst_u16DSU_GTDI_GTMS() -> u16H = (ParValue))
#define u16GetDSU_GTDI_GTMSH() (pst_u16DSU_GTDI_GTMS() -> u16H)
            
/* Word access */
#define vSetDSU_GTDI_GTMS(ParValue)  (*pu32DSU_GTDI_GTMS() = (ParValue))
#define u32GetDSU_GTDI_GTMS()  (*pu32DSU_GTDI_GTMS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DSU_GTRST_TPC0_GTDO                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030223C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DSU_GTRST_TPC0_GTDO_REG__       0xC030223CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:8; 	 /* 0..7  bit(s) R */
  uint32_t   DSU_GTRST_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   DSU_GTRST_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DSU_GTRST_SMT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   DSU_GTRST_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:8; 	 /* 16..23  bit(s) R */
  uint32_t   DSU_TPC0_GTDO_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DSU_TPC0_GTDO_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   DSU_TPC0_GTDO_SMT	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DSU_TPC0_GTDO_IMP	:2; 	 /* 27..28  bit(s) R/W */ 
  uint32_t   	:3; 	 /* 29..31  bit(s) R */                    
} DSU_GTRST_TPC0_GTDO_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DSU_GTRST_TPC0_GTDO_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DSU_GTRST_TPC0_GTDO_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DSU_GTRST_TPC0_GTDO_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDSU_GTRST_TPC0_GTDO()     ((volatile DSU_GTRST_TPC0_GTDO_bit_view_st *)\
(DSU_GTRST_TPC0_GTDO_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DSU_GTRST_TPC0_GTDO()     ((volatile DSU_GTRST_TPC0_GTDO_byte_view_st *)\
(DSU_GTRST_TPC0_GTDO_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DSU_GTRST_TPC0_GTDO()     ((volatile DSU_GTRST_TPC0_GTDO_halfword_view_st *)\
(DSU_GTRST_TPC0_GTDO_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DSU_GTRST_TPC0_GTDO()     ((volatile u32DSU_GTRST_TPC0_GTDO_word_view *)\
(DSU_GTRST_TPC0_GTDO_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDSU_GTRST_TPC0_GTDO_DSU_GTRST_PU() (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_GTRST_PU)
#define vSetDSU_GTRST_TPC0_GTDO_DSU_GTRST_PU(ParValue)  (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_GTRST_PU=(ParValue))
#define biGetDSU_GTRST_TPC0_GTDO_DSU_GTRST_PD() (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_GTRST_PD)
#define vSetDSU_GTRST_TPC0_GTDO_DSU_GTRST_PD(ParValue)  (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_GTRST_PD=(ParValue))
#define biGetDSU_GTRST_TPC0_GTDO_DSU_GTRST_SMT() (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_GTRST_SMT)
#define vSetDSU_GTRST_TPC0_GTDO_DSU_GTRST_SMT(ParValue)  (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_GTRST_SMT=(ParValue))
#define biGetDSU_GTRST_TPC0_GTDO_DSU_GTRST_LATCHN() (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_GTRST_LATCHN)
#define vSetDSU_GTRST_TPC0_GTDO_DSU_GTRST_LATCHN(ParValue)  (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_GTRST_LATCHN=(ParValue))
#define biGetDSU_GTRST_TPC0_GTDO_DSU_TPC0_GTDO_PU() (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_TPC0_GTDO_PU)
#define vSetDSU_GTRST_TPC0_GTDO_DSU_TPC0_GTDO_PU(ParValue)  (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_TPC0_GTDO_PU=(ParValue))
#define biGetDSU_GTRST_TPC0_GTDO_DSU_TPC0_GTDO_PD() (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_TPC0_GTDO_PD)
#define vSetDSU_GTRST_TPC0_GTDO_DSU_TPC0_GTDO_PD(ParValue)  (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_TPC0_GTDO_PD=(ParValue))
#define biGetDSU_GTRST_TPC0_GTDO_DSU_TPC0_GTDO_SMT() (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_TPC0_GTDO_SMT)
#define vSetDSU_GTRST_TPC0_GTDO_DSU_TPC0_GTDO_SMT(ParValue)  (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_TPC0_GTDO_SMT=(ParValue))
#define biGetDSU_GTRST_TPC0_GTDO_DSU_TPC0_GTDO_IMP() (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_TPC0_GTDO_IMP)
#define vSetDSU_GTRST_TPC0_GTDO_DSU_TPC0_GTDO_IMP(ParValue)  (pst_bitDSU_GTRST_TPC0_GTDO() -> DSU_TPC0_GTDO_IMP=(ParValue))
            
/* LL-struct byte access */
#define vSetDSU_GTRST_TPC0_GTDOLL(ParValue) (pst_u8DSU_GTRST_TPC0_GTDO() -> u8LL = (ParValue))
#define u8GetDSU_GTRST_TPC0_GTDOLL() (pst_u8DSU_GTRST_TPC0_GTDO() -> u8LL)
/* LH-struct byte access */
#define vSetDSU_GTRST_TPC0_GTDOLH(ParValue) (pst_u8DSU_GTRST_TPC0_GTDO() -> u8LH = (ParValue))
#define u8GetDSU_GTRST_TPC0_GTDOLH() (pst_u8DSU_GTRST_TPC0_GTDO() -> u8LH)
/* HL-struct byte access */
#define vSetDSU_GTRST_TPC0_GTDOHL(ParValue) (pst_u8DSU_GTRST_TPC0_GTDO() -> u8HL = (ParValue))
#define u8GetDSU_GTRST_TPC0_GTDOHL() (pst_u8DSU_GTRST_TPC0_GTDO() -> u8HL)
/* HH-struct byte access */
#define vSetDSU_GTRST_TPC0_GTDOHH(ParValue) (pst_u8DSU_GTRST_TPC0_GTDO() -> u8HH = (ParValue))
#define u8GetDSU_GTRST_TPC0_GTDOHH() (pst_u8DSU_GTRST_TPC0_GTDO() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDSU_GTRST_TPC0_GTDOL(ParValue) (pst_u16DSU_GTRST_TPC0_GTDO() -> u16L = (ParValue))
#define u16GetDSU_GTRST_TPC0_GTDOL() (pst_u16DSU_GTRST_TPC0_GTDO() -> u16L)
#define vSetDSU_GTRST_TPC0_GTDOH(ParValue) (pst_u16DSU_GTRST_TPC0_GTDO() -> u16H = (ParValue))
#define u16GetDSU_GTRST_TPC0_GTDOH() (pst_u16DSU_GTRST_TPC0_GTDO() -> u16H)
            
/* Word access */
#define vSetDSU_GTRST_TPC0_GTDO(ParValue)  (*pu32DSU_GTRST_TPC0_GTDO() = (ParValue))
#define u32GetDSU_GTRST_TPC0_GTDO()  (*pu32DSU_GTRST_TPC0_GTDO() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADC_IN0_IN1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302250                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADC_IN0_IN1_REG__       0xC0302250U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ADC_IN0_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ADC_IN0_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ADC_IN0_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   ADC_IN0_PODN	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   ADC_IN0_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   ADC_IN1_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ADC_IN1_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ADC_IN1_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   ADC_IN1_PODN	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   ADC_IN1_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ADC_IN0_IN1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADC_IN0_IN1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADC_IN0_IN1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADC_IN0_IN1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADC_IN0_IN1()     ((volatile ADC_IN0_IN1_bit_view_st *)\
(ADC_IN0_IN1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADC_IN0_IN1()     ((volatile ADC_IN0_IN1_byte_view_st *)\
(ADC_IN0_IN1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADC_IN0_IN1()     ((volatile ADC_IN0_IN1_halfword_view_st *)\
(ADC_IN0_IN1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ADC_IN0_IN1()     ((volatile u32ADC_IN0_IN1_word_view *)\
(ADC_IN0_IN1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADC_IN0_IN1_ADC_IN0_SEL() (pst_bitADC_IN0_IN1() -> ADC_IN0_SEL)
#define vSetADC_IN0_IN1_ADC_IN0_SEL(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN0_SEL=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN0_PU() (pst_bitADC_IN0_IN1() -> ADC_IN0_PU)
#define vSetADC_IN0_IN1_ADC_IN0_PU(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN0_PU=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN0_PD() (pst_bitADC_IN0_IN1() -> ADC_IN0_PD)
#define vSetADC_IN0_IN1_ADC_IN0_PD(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN0_PD=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN0_PODN() (pst_bitADC_IN0_IN1() -> ADC_IN0_PODN)
#define vSetADC_IN0_IN1_ADC_IN0_PODN(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN0_PODN=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN0_LATCHN() (pst_bitADC_IN0_IN1() -> ADC_IN0_LATCHN)
#define vSetADC_IN0_IN1_ADC_IN0_LATCHN(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN0_LATCHN=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN1_SEL() (pst_bitADC_IN0_IN1() -> ADC_IN1_SEL)
#define vSetADC_IN0_IN1_ADC_IN1_SEL(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN1_SEL=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN1_PU() (pst_bitADC_IN0_IN1() -> ADC_IN1_PU)
#define vSetADC_IN0_IN1_ADC_IN1_PU(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN1_PU=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN1_PD() (pst_bitADC_IN0_IN1() -> ADC_IN1_PD)
#define vSetADC_IN0_IN1_ADC_IN1_PD(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN1_PD=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN1_PODN() (pst_bitADC_IN0_IN1() -> ADC_IN1_PODN)
#define vSetADC_IN0_IN1_ADC_IN1_PODN(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN1_PODN=(ParValue))
#define biGetADC_IN0_IN1_ADC_IN1_LATCHN() (pst_bitADC_IN0_IN1() -> ADC_IN1_LATCHN)
#define vSetADC_IN0_IN1_ADC_IN1_LATCHN(ParValue)  (pst_bitADC_IN0_IN1() -> ADC_IN1_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetADC_IN0_IN1LL(ParValue) (pst_u8ADC_IN0_IN1() -> u8LL = (ParValue))
#define u8GetADC_IN0_IN1LL() (pst_u8ADC_IN0_IN1() -> u8LL)
/* LH-struct byte access */
#define vSetADC_IN0_IN1LH(ParValue) (pst_u8ADC_IN0_IN1() -> u8LH = (ParValue))
#define u8GetADC_IN0_IN1LH() (pst_u8ADC_IN0_IN1() -> u8LH)
/* HL-struct byte access */
#define vSetADC_IN0_IN1HL(ParValue) (pst_u8ADC_IN0_IN1() -> u8HL = (ParValue))
#define u8GetADC_IN0_IN1HL() (pst_u8ADC_IN0_IN1() -> u8HL)
/* HH-struct byte access */
#define vSetADC_IN0_IN1HH(ParValue) (pst_u8ADC_IN0_IN1() -> u8HH = (ParValue))
#define u8GetADC_IN0_IN1HH() (pst_u8ADC_IN0_IN1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADC_IN0_IN1L(ParValue) (pst_u16ADC_IN0_IN1() -> u16L = (ParValue))
#define u16GetADC_IN0_IN1L() (pst_u16ADC_IN0_IN1() -> u16L)
#define vSetADC_IN0_IN1H(ParValue) (pst_u16ADC_IN0_IN1() -> u16H = (ParValue))
#define u16GetADC_IN0_IN1H() (pst_u16ADC_IN0_IN1() -> u16H)
            
/* Word access */
#define vSetADC_IN0_IN1(ParValue)  (*pu32ADC_IN0_IN1() = (ParValue))
#define u32GetADC_IN0_IN1()  (*pu32ADC_IN0_IN1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADC_IN2_IN3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302254                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADC_IN2_IN3_REG__       0xC0302254U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ADC_IN2_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ADC_IN2_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ADC_IN2_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   ADC_IN2_PODN	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   ADC_IN2_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   ADC_IN3_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ADC_IN3_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ADC_IN3_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   ADC_IN3_PODN	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   ADC_IN3_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ADC_IN2_IN3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADC_IN2_IN3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADC_IN2_IN3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADC_IN2_IN3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADC_IN2_IN3()     ((volatile ADC_IN2_IN3_bit_view_st *)\
(ADC_IN2_IN3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADC_IN2_IN3()     ((volatile ADC_IN2_IN3_byte_view_st *)\
(ADC_IN2_IN3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADC_IN2_IN3()     ((volatile ADC_IN2_IN3_halfword_view_st *)\
(ADC_IN2_IN3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ADC_IN2_IN3()     ((volatile u32ADC_IN2_IN3_word_view *)\
(ADC_IN2_IN3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADC_IN2_IN3_ADC_IN2_SEL() (pst_bitADC_IN2_IN3() -> ADC_IN2_SEL)
#define vSetADC_IN2_IN3_ADC_IN2_SEL(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN2_SEL=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN2_PU() (pst_bitADC_IN2_IN3() -> ADC_IN2_PU)
#define vSetADC_IN2_IN3_ADC_IN2_PU(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN2_PU=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN2_PD() (pst_bitADC_IN2_IN3() -> ADC_IN2_PD)
#define vSetADC_IN2_IN3_ADC_IN2_PD(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN2_PD=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN2_PODN() (pst_bitADC_IN2_IN3() -> ADC_IN2_PODN)
#define vSetADC_IN2_IN3_ADC_IN2_PODN(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN2_PODN=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN2_LATCHN() (pst_bitADC_IN2_IN3() -> ADC_IN2_LATCHN)
#define vSetADC_IN2_IN3_ADC_IN2_LATCHN(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN2_LATCHN=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN3_SEL() (pst_bitADC_IN2_IN3() -> ADC_IN3_SEL)
#define vSetADC_IN2_IN3_ADC_IN3_SEL(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN3_SEL=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN3_PU() (pst_bitADC_IN2_IN3() -> ADC_IN3_PU)
#define vSetADC_IN2_IN3_ADC_IN3_PU(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN3_PU=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN3_PD() (pst_bitADC_IN2_IN3() -> ADC_IN3_PD)
#define vSetADC_IN2_IN3_ADC_IN3_PD(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN3_PD=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN3_PODN() (pst_bitADC_IN2_IN3() -> ADC_IN3_PODN)
#define vSetADC_IN2_IN3_ADC_IN3_PODN(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN3_PODN=(ParValue))
#define biGetADC_IN2_IN3_ADC_IN3_LATCHN() (pst_bitADC_IN2_IN3() -> ADC_IN3_LATCHN)
#define vSetADC_IN2_IN3_ADC_IN3_LATCHN(ParValue)  (pst_bitADC_IN2_IN3() -> ADC_IN3_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetADC_IN2_IN3LL(ParValue) (pst_u8ADC_IN2_IN3() -> u8LL = (ParValue))
#define u8GetADC_IN2_IN3LL() (pst_u8ADC_IN2_IN3() -> u8LL)
/* LH-struct byte access */
#define vSetADC_IN2_IN3LH(ParValue) (pst_u8ADC_IN2_IN3() -> u8LH = (ParValue))
#define u8GetADC_IN2_IN3LH() (pst_u8ADC_IN2_IN3() -> u8LH)
/* HL-struct byte access */
#define vSetADC_IN2_IN3HL(ParValue) (pst_u8ADC_IN2_IN3() -> u8HL = (ParValue))
#define u8GetADC_IN2_IN3HL() (pst_u8ADC_IN2_IN3() -> u8HL)
/* HH-struct byte access */
#define vSetADC_IN2_IN3HH(ParValue) (pst_u8ADC_IN2_IN3() -> u8HH = (ParValue))
#define u8GetADC_IN2_IN3HH() (pst_u8ADC_IN2_IN3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADC_IN2_IN3L(ParValue) (pst_u16ADC_IN2_IN3() -> u16L = (ParValue))
#define u16GetADC_IN2_IN3L() (pst_u16ADC_IN2_IN3() -> u16L)
#define vSetADC_IN2_IN3H(ParValue) (pst_u16ADC_IN2_IN3() -> u16H = (ParValue))
#define u16GetADC_IN2_IN3H() (pst_u16ADC_IN2_IN3() -> u16H)
            
/* Word access */
#define vSetADC_IN2_IN3(ParValue)  (*pu32ADC_IN2_IN3() = (ParValue))
#define u32GetADC_IN2_IN3()  (*pu32ADC_IN2_IN3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADC_IN4_IN5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302258                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADC_IN4_IN5_REG__       0xC0302258U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ADC_IN4_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ADC_IN4_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ADC_IN4_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   ADC_IN4_PODN	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   ADC_IN4_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   ADC_IN5_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ADC_IN5_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ADC_IN5_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   ADC_IN5_PODN	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   ADC_IN5_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ADC_IN4_IN5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADC_IN4_IN5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADC_IN4_IN5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADC_IN4_IN5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADC_IN4_IN5()     ((volatile ADC_IN4_IN5_bit_view_st *)\
(ADC_IN4_IN5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADC_IN4_IN5()     ((volatile ADC_IN4_IN5_byte_view_st *)\
(ADC_IN4_IN5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADC_IN4_IN5()     ((volatile ADC_IN4_IN5_halfword_view_st *)\
(ADC_IN4_IN5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ADC_IN4_IN5()     ((volatile u32ADC_IN4_IN5_word_view *)\
(ADC_IN4_IN5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADC_IN4_IN5_ADC_IN4_SEL() (pst_bitADC_IN4_IN5() -> ADC_IN4_SEL)
#define vSetADC_IN4_IN5_ADC_IN4_SEL(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN4_SEL=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN4_PU() (pst_bitADC_IN4_IN5() -> ADC_IN4_PU)
#define vSetADC_IN4_IN5_ADC_IN4_PU(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN4_PU=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN4_PD() (pst_bitADC_IN4_IN5() -> ADC_IN4_PD)
#define vSetADC_IN4_IN5_ADC_IN4_PD(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN4_PD=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN4_PODN() (pst_bitADC_IN4_IN5() -> ADC_IN4_PODN)
#define vSetADC_IN4_IN5_ADC_IN4_PODN(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN4_PODN=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN4_LATCHN() (pst_bitADC_IN4_IN5() -> ADC_IN4_LATCHN)
#define vSetADC_IN4_IN5_ADC_IN4_LATCHN(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN4_LATCHN=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN5_SEL() (pst_bitADC_IN4_IN5() -> ADC_IN5_SEL)
#define vSetADC_IN4_IN5_ADC_IN5_SEL(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN5_SEL=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN5_PU() (pst_bitADC_IN4_IN5() -> ADC_IN5_PU)
#define vSetADC_IN4_IN5_ADC_IN5_PU(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN5_PU=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN5_PD() (pst_bitADC_IN4_IN5() -> ADC_IN5_PD)
#define vSetADC_IN4_IN5_ADC_IN5_PD(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN5_PD=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN5_PODN() (pst_bitADC_IN4_IN5() -> ADC_IN5_PODN)
#define vSetADC_IN4_IN5_ADC_IN5_PODN(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN5_PODN=(ParValue))
#define biGetADC_IN4_IN5_ADC_IN5_LATCHN() (pst_bitADC_IN4_IN5() -> ADC_IN5_LATCHN)
#define vSetADC_IN4_IN5_ADC_IN5_LATCHN(ParValue)  (pst_bitADC_IN4_IN5() -> ADC_IN5_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetADC_IN4_IN5LL(ParValue) (pst_u8ADC_IN4_IN5() -> u8LL = (ParValue))
#define u8GetADC_IN4_IN5LL() (pst_u8ADC_IN4_IN5() -> u8LL)
/* LH-struct byte access */
#define vSetADC_IN4_IN5LH(ParValue) (pst_u8ADC_IN4_IN5() -> u8LH = (ParValue))
#define u8GetADC_IN4_IN5LH() (pst_u8ADC_IN4_IN5() -> u8LH)
/* HL-struct byte access */
#define vSetADC_IN4_IN5HL(ParValue) (pst_u8ADC_IN4_IN5() -> u8HL = (ParValue))
#define u8GetADC_IN4_IN5HL() (pst_u8ADC_IN4_IN5() -> u8HL)
/* HH-struct byte access */
#define vSetADC_IN4_IN5HH(ParValue) (pst_u8ADC_IN4_IN5() -> u8HH = (ParValue))
#define u8GetADC_IN4_IN5HH() (pst_u8ADC_IN4_IN5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADC_IN4_IN5L(ParValue) (pst_u16ADC_IN4_IN5() -> u16L = (ParValue))
#define u16GetADC_IN4_IN5L() (pst_u16ADC_IN4_IN5() -> u16L)
#define vSetADC_IN4_IN5H(ParValue) (pst_u16ADC_IN4_IN5() -> u16H = (ParValue))
#define u16GetADC_IN4_IN5H() (pst_u16ADC_IN4_IN5() -> u16H)
            
/* Word access */
#define vSetADC_IN4_IN5(ParValue)  (*pu32ADC_IN4_IN5() = (ParValue))
#define u32GetADC_IN4_IN5()  (*pu32ADC_IN4_IN5() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADC_IN6_IN7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030225C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADC_IN6_IN7_REG__       0xC030225CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ADC_IN6_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ADC_IN6_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ADC_IN6_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   ADC_IN6_PODN	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   ADC_IN6_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   ADC_IN7_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ADC_IN7_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ADC_IN7_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   ADC_IN7_PODN	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   ADC_IN7_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ADC_IN6_IN7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADC_IN6_IN7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADC_IN6_IN7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADC_IN6_IN7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADC_IN6_IN7()     ((volatile ADC_IN6_IN7_bit_view_st *)\
(ADC_IN6_IN7_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADC_IN6_IN7()     ((volatile ADC_IN6_IN7_byte_view_st *)\
(ADC_IN6_IN7_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADC_IN6_IN7()     ((volatile ADC_IN6_IN7_halfword_view_st *)\
(ADC_IN6_IN7_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ADC_IN6_IN7()     ((volatile u32ADC_IN6_IN7_word_view *)\
(ADC_IN6_IN7_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADC_IN6_IN7_ADC_IN6_SEL() (pst_bitADC_IN6_IN7() -> ADC_IN6_SEL)
#define vSetADC_IN6_IN7_ADC_IN6_SEL(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN6_SEL=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN6_PU() (pst_bitADC_IN6_IN7() -> ADC_IN6_PU)
#define vSetADC_IN6_IN7_ADC_IN6_PU(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN6_PU=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN6_PD() (pst_bitADC_IN6_IN7() -> ADC_IN6_PD)
#define vSetADC_IN6_IN7_ADC_IN6_PD(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN6_PD=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN6_PODN() (pst_bitADC_IN6_IN7() -> ADC_IN6_PODN)
#define vSetADC_IN6_IN7_ADC_IN6_PODN(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN6_PODN=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN6_LATCHN() (pst_bitADC_IN6_IN7() -> ADC_IN6_LATCHN)
#define vSetADC_IN6_IN7_ADC_IN6_LATCHN(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN6_LATCHN=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN7_SEL() (pst_bitADC_IN6_IN7() -> ADC_IN7_SEL)
#define vSetADC_IN6_IN7_ADC_IN7_SEL(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN7_SEL=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN7_PU() (pst_bitADC_IN6_IN7() -> ADC_IN7_PU)
#define vSetADC_IN6_IN7_ADC_IN7_PU(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN7_PU=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN7_PD() (pst_bitADC_IN6_IN7() -> ADC_IN7_PD)
#define vSetADC_IN6_IN7_ADC_IN7_PD(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN7_PD=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN7_PODN() (pst_bitADC_IN6_IN7() -> ADC_IN7_PODN)
#define vSetADC_IN6_IN7_ADC_IN7_PODN(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN7_PODN=(ParValue))
#define biGetADC_IN6_IN7_ADC_IN7_LATCHN() (pst_bitADC_IN6_IN7() -> ADC_IN7_LATCHN)
#define vSetADC_IN6_IN7_ADC_IN7_LATCHN(ParValue)  (pst_bitADC_IN6_IN7() -> ADC_IN7_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetADC_IN6_IN7LL(ParValue) (pst_u8ADC_IN6_IN7() -> u8LL = (ParValue))
#define u8GetADC_IN6_IN7LL() (pst_u8ADC_IN6_IN7() -> u8LL)
/* LH-struct byte access */
#define vSetADC_IN6_IN7LH(ParValue) (pst_u8ADC_IN6_IN7() -> u8LH = (ParValue))
#define u8GetADC_IN6_IN7LH() (pst_u8ADC_IN6_IN7() -> u8LH)
/* HL-struct byte access */
#define vSetADC_IN6_IN7HL(ParValue) (pst_u8ADC_IN6_IN7() -> u8HL = (ParValue))
#define u8GetADC_IN6_IN7HL() (pst_u8ADC_IN6_IN7() -> u8HL)
/* HH-struct byte access */
#define vSetADC_IN6_IN7HH(ParValue) (pst_u8ADC_IN6_IN7() -> u8HH = (ParValue))
#define u8GetADC_IN6_IN7HH() (pst_u8ADC_IN6_IN7() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADC_IN6_IN7L(ParValue) (pst_u16ADC_IN6_IN7() -> u16L = (ParValue))
#define u16GetADC_IN6_IN7L() (pst_u16ADC_IN6_IN7() -> u16L)
#define vSetADC_IN6_IN7H(ParValue) (pst_u16ADC_IN6_IN7() -> u16H = (ParValue))
#define u16GetADC_IN6_IN7H() (pst_u16ADC_IN6_IN7() -> u16H)
            
/* Word access */
#define vSetADC_IN6_IN7(ParValue)  (*pu32ADC_IN6_IN7() = (ParValue))
#define u32GetADC_IN6_IN7()  (*pu32ADC_IN6_IN7() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADC_IN8_IN9                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302260                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADC_IN8_IN9_REG__       0xC0302260U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ADC_IN8_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ADC_IN8_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   ADC_IN8_PODN	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   ADC_IN8_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:3; 	 /* 16..18  bit(s) R */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ADC_IN9_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ADC_IN9_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   ADC_IN9_PODN	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   ADC_IN9_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ADC_IN8_IN9_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADC_IN8_IN9_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADC_IN8_IN9_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADC_IN8_IN9_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADC_IN8_IN9()     ((volatile ADC_IN8_IN9_bit_view_st *)\
(ADC_IN8_IN9_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADC_IN8_IN9()     ((volatile ADC_IN8_IN9_byte_view_st *)\
(ADC_IN8_IN9_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADC_IN8_IN9()     ((volatile ADC_IN8_IN9_halfword_view_st *)\
(ADC_IN8_IN9_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ADC_IN8_IN9()     ((volatile u32ADC_IN8_IN9_word_view *)\
(ADC_IN8_IN9_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADC_IN8_IN9_ADC_IN8_PU() (pst_bitADC_IN8_IN9() -> ADC_IN8_PU)
#define vSetADC_IN8_IN9_ADC_IN8_PU(ParValue)  (pst_bitADC_IN8_IN9() -> ADC_IN8_PU=(ParValue))
#define biGetADC_IN8_IN9_ADC_IN8_PD() (pst_bitADC_IN8_IN9() -> ADC_IN8_PD)
#define vSetADC_IN8_IN9_ADC_IN8_PD(ParValue)  (pst_bitADC_IN8_IN9() -> ADC_IN8_PD=(ParValue))
#define biGetADC_IN8_IN9_ADC_IN8_PODN() (pst_bitADC_IN8_IN9() -> ADC_IN8_PODN)
#define vSetADC_IN8_IN9_ADC_IN8_PODN(ParValue)  (pst_bitADC_IN8_IN9() -> ADC_IN8_PODN=(ParValue))
#define biGetADC_IN8_IN9_ADC_IN8_LATCHN() (pst_bitADC_IN8_IN9() -> ADC_IN8_LATCHN)
#define vSetADC_IN8_IN9_ADC_IN8_LATCHN(ParValue)  (pst_bitADC_IN8_IN9() -> ADC_IN8_LATCHN=(ParValue))
#define biGetADC_IN8_IN9_ADC_IN9_PU() (pst_bitADC_IN8_IN9() -> ADC_IN9_PU)
#define vSetADC_IN8_IN9_ADC_IN9_PU(ParValue)  (pst_bitADC_IN8_IN9() -> ADC_IN9_PU=(ParValue))
#define biGetADC_IN8_IN9_ADC_IN9_PD() (pst_bitADC_IN8_IN9() -> ADC_IN9_PD)
#define vSetADC_IN8_IN9_ADC_IN9_PD(ParValue)  (pst_bitADC_IN8_IN9() -> ADC_IN9_PD=(ParValue))
#define biGetADC_IN8_IN9_ADC_IN9_PODN() (pst_bitADC_IN8_IN9() -> ADC_IN9_PODN)
#define vSetADC_IN8_IN9_ADC_IN9_PODN(ParValue)  (pst_bitADC_IN8_IN9() -> ADC_IN9_PODN=(ParValue))
#define biGetADC_IN8_IN9_ADC_IN9_LATCHN() (pst_bitADC_IN8_IN9() -> ADC_IN9_LATCHN)
#define vSetADC_IN8_IN9_ADC_IN9_LATCHN(ParValue)  (pst_bitADC_IN8_IN9() -> ADC_IN9_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetADC_IN8_IN9LL(ParValue) (pst_u8ADC_IN8_IN9() -> u8LL = (ParValue))
#define u8GetADC_IN8_IN9LL() (pst_u8ADC_IN8_IN9() -> u8LL)
/* LH-struct byte access */
#define vSetADC_IN8_IN9LH(ParValue) (pst_u8ADC_IN8_IN9() -> u8LH = (ParValue))
#define u8GetADC_IN8_IN9LH() (pst_u8ADC_IN8_IN9() -> u8LH)
/* HL-struct byte access */
#define vSetADC_IN8_IN9HL(ParValue) (pst_u8ADC_IN8_IN9() -> u8HL = (ParValue))
#define u8GetADC_IN8_IN9HL() (pst_u8ADC_IN8_IN9() -> u8HL)
/* HH-struct byte access */
#define vSetADC_IN8_IN9HH(ParValue) (pst_u8ADC_IN8_IN9() -> u8HH = (ParValue))
#define u8GetADC_IN8_IN9HH() (pst_u8ADC_IN8_IN9() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADC_IN8_IN9L(ParValue) (pst_u16ADC_IN8_IN9() -> u16L = (ParValue))
#define u16GetADC_IN8_IN9L() (pst_u16ADC_IN8_IN9() -> u16L)
#define vSetADC_IN8_IN9H(ParValue) (pst_u16ADC_IN8_IN9() -> u16H = (ParValue))
#define u16GetADC_IN8_IN9H() (pst_u16ADC_IN8_IN9() -> u16H)
            
/* Word access */
#define vSetADC_IN8_IN9(ParValue)  (*pu32ADC_IN8_IN9() = (ParValue))
#define u32GetADC_IN8_IN9()  (*pu32ADC_IN8_IN9() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADC_IN10_IN11                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302264                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADC_IN10_IN11_REG__       0xC0302264U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ADC_IN10_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ADC_IN10_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   ADC_IN10_PODN	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   ADC_IN10_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:3; 	 /* 16..18  bit(s) R */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ADC_IN11_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ADC_IN11_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   ADC_IN11_PODN	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   ADC_IN11_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ADC_IN10_IN11_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADC_IN10_IN11_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADC_IN10_IN11_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADC_IN10_IN11_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADC_IN10_IN11()     ((volatile ADC_IN10_IN11_bit_view_st *)\
(ADC_IN10_IN11_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADC_IN10_IN11()     ((volatile ADC_IN10_IN11_byte_view_st *)\
(ADC_IN10_IN11_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADC_IN10_IN11()     ((volatile ADC_IN10_IN11_halfword_view_st *)\
(ADC_IN10_IN11_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ADC_IN10_IN11()     ((volatile u32ADC_IN10_IN11_word_view *)\
(ADC_IN10_IN11_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADC_IN10_IN11_ADC_IN10_PU() (pst_bitADC_IN10_IN11() -> ADC_IN10_PU)
#define vSetADC_IN10_IN11_ADC_IN10_PU(ParValue)  (pst_bitADC_IN10_IN11() -> ADC_IN10_PU=(ParValue))
#define biGetADC_IN10_IN11_ADC_IN10_PD() (pst_bitADC_IN10_IN11() -> ADC_IN10_PD)
#define vSetADC_IN10_IN11_ADC_IN10_PD(ParValue)  (pst_bitADC_IN10_IN11() -> ADC_IN10_PD=(ParValue))
#define biGetADC_IN10_IN11_ADC_IN10_PODN() (pst_bitADC_IN10_IN11() -> ADC_IN10_PODN)
#define vSetADC_IN10_IN11_ADC_IN10_PODN(ParValue)  (pst_bitADC_IN10_IN11() -> ADC_IN10_PODN=(ParValue))
#define biGetADC_IN10_IN11_ADC_IN10_LATCHN() (pst_bitADC_IN10_IN11() -> ADC_IN10_LATCHN)
#define vSetADC_IN10_IN11_ADC_IN10_LATCHN(ParValue)  (pst_bitADC_IN10_IN11() -> ADC_IN10_LATCHN=(ParValue))
#define biGetADC_IN10_IN11_ADC_IN11_PU() (pst_bitADC_IN10_IN11() -> ADC_IN11_PU)
#define vSetADC_IN10_IN11_ADC_IN11_PU(ParValue)  (pst_bitADC_IN10_IN11() -> ADC_IN11_PU=(ParValue))
#define biGetADC_IN10_IN11_ADC_IN11_PD() (pst_bitADC_IN10_IN11() -> ADC_IN11_PD)
#define vSetADC_IN10_IN11_ADC_IN11_PD(ParValue)  (pst_bitADC_IN10_IN11() -> ADC_IN11_PD=(ParValue))
#define biGetADC_IN10_IN11_ADC_IN11_PODN() (pst_bitADC_IN10_IN11() -> ADC_IN11_PODN)
#define vSetADC_IN10_IN11_ADC_IN11_PODN(ParValue)  (pst_bitADC_IN10_IN11() -> ADC_IN11_PODN=(ParValue))
#define biGetADC_IN10_IN11_ADC_IN11_LATCHN() (pst_bitADC_IN10_IN11() -> ADC_IN11_LATCHN)
#define vSetADC_IN10_IN11_ADC_IN11_LATCHN(ParValue)  (pst_bitADC_IN10_IN11() -> ADC_IN11_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetADC_IN10_IN11LL(ParValue) (pst_u8ADC_IN10_IN11() -> u8LL = (ParValue))
#define u8GetADC_IN10_IN11LL() (pst_u8ADC_IN10_IN11() -> u8LL)
/* LH-struct byte access */
#define vSetADC_IN10_IN11LH(ParValue) (pst_u8ADC_IN10_IN11() -> u8LH = (ParValue))
#define u8GetADC_IN10_IN11LH() (pst_u8ADC_IN10_IN11() -> u8LH)
/* HL-struct byte access */
#define vSetADC_IN10_IN11HL(ParValue) (pst_u8ADC_IN10_IN11() -> u8HL = (ParValue))
#define u8GetADC_IN10_IN11HL() (pst_u8ADC_IN10_IN11() -> u8HL)
/* HH-struct byte access */
#define vSetADC_IN10_IN11HH(ParValue) (pst_u8ADC_IN10_IN11() -> u8HH = (ParValue))
#define u8GetADC_IN10_IN11HH() (pst_u8ADC_IN10_IN11() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADC_IN10_IN11L(ParValue) (pst_u16ADC_IN10_IN11() -> u16L = (ParValue))
#define u16GetADC_IN10_IN11L() (pst_u16ADC_IN10_IN11() -> u16L)
#define vSetADC_IN10_IN11H(ParValue) (pst_u16ADC_IN10_IN11() -> u16H = (ParValue))
#define u16GetADC_IN10_IN11H() (pst_u16ADC_IN10_IN11() -> u16H)
            
/* Word access */
#define vSetADC_IN10_IN11(ParValue)  (*pu32ADC_IN10_IN11() = (ParValue))
#define u32GetADC_IN10_IN11()  (*pu32ADC_IN10_IN11() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADC_IN12_IN13                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302268                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADC_IN12_IN13_REG__       0xC0302268U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ADC_IN12_PU	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ADC_IN12_PD	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   ADC_IN12_PODN	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   	:2; 	 /* 11..12  bit(s) R */
  uint32_t   ADC_IN12_LATCHN	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   	:3; 	 /* 16..18  bit(s) R */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   ADC_IN13_PU	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   ADC_IN13_PD	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   ADC_IN13_PODN	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   	:2; 	 /* 27..28  bit(s) R */
  uint32_t   ADC_IN13_LATCHN	:1; 	 /* 29..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} ADC_IN12_IN13_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADC_IN12_IN13_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADC_IN12_IN13_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADC_IN12_IN13_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADC_IN12_IN13()     ((volatile ADC_IN12_IN13_bit_view_st *)\
(ADC_IN12_IN13_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADC_IN12_IN13()     ((volatile ADC_IN12_IN13_byte_view_st *)\
(ADC_IN12_IN13_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADC_IN12_IN13()     ((volatile ADC_IN12_IN13_halfword_view_st *)\
(ADC_IN12_IN13_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ADC_IN12_IN13()     ((volatile u32ADC_IN12_IN13_word_view *)\
(ADC_IN12_IN13_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADC_IN12_IN13_ADC_IN12_PU() (pst_bitADC_IN12_IN13() -> ADC_IN12_PU)
#define vSetADC_IN12_IN13_ADC_IN12_PU(ParValue)  (pst_bitADC_IN12_IN13() -> ADC_IN12_PU=(ParValue))
#define biGetADC_IN12_IN13_ADC_IN12_PD() (pst_bitADC_IN12_IN13() -> ADC_IN12_PD)
#define vSetADC_IN12_IN13_ADC_IN12_PD(ParValue)  (pst_bitADC_IN12_IN13() -> ADC_IN12_PD=(ParValue))
#define biGetADC_IN12_IN13_ADC_IN12_PODN() (pst_bitADC_IN12_IN13() -> ADC_IN12_PODN)
#define vSetADC_IN12_IN13_ADC_IN12_PODN(ParValue)  (pst_bitADC_IN12_IN13() -> ADC_IN12_PODN=(ParValue))
#define biGetADC_IN12_IN13_ADC_IN12_LATCHN() (pst_bitADC_IN12_IN13() -> ADC_IN12_LATCHN)
#define vSetADC_IN12_IN13_ADC_IN12_LATCHN(ParValue)  (pst_bitADC_IN12_IN13() -> ADC_IN12_LATCHN=(ParValue))
#define biGetADC_IN12_IN13_ADC_IN13_PU() (pst_bitADC_IN12_IN13() -> ADC_IN13_PU)
#define vSetADC_IN12_IN13_ADC_IN13_PU(ParValue)  (pst_bitADC_IN12_IN13() -> ADC_IN13_PU=(ParValue))
#define biGetADC_IN12_IN13_ADC_IN13_PD() (pst_bitADC_IN12_IN13() -> ADC_IN13_PD)
#define vSetADC_IN12_IN13_ADC_IN13_PD(ParValue)  (pst_bitADC_IN12_IN13() -> ADC_IN13_PD=(ParValue))
#define biGetADC_IN12_IN13_ADC_IN13_PODN() (pst_bitADC_IN12_IN13() -> ADC_IN13_PODN)
#define vSetADC_IN12_IN13_ADC_IN13_PODN(ParValue)  (pst_bitADC_IN12_IN13() -> ADC_IN13_PODN=(ParValue))
#define biGetADC_IN12_IN13_ADC_IN13_LATCHN() (pst_bitADC_IN12_IN13() -> ADC_IN13_LATCHN)
#define vSetADC_IN12_IN13_ADC_IN13_LATCHN(ParValue)  (pst_bitADC_IN12_IN13() -> ADC_IN13_LATCHN=(ParValue))
            
/* LL-struct byte access */
#define vSetADC_IN12_IN13LL(ParValue) (pst_u8ADC_IN12_IN13() -> u8LL = (ParValue))
#define u8GetADC_IN12_IN13LL() (pst_u8ADC_IN12_IN13() -> u8LL)
/* LH-struct byte access */
#define vSetADC_IN12_IN13LH(ParValue) (pst_u8ADC_IN12_IN13() -> u8LH = (ParValue))
#define u8GetADC_IN12_IN13LH() (pst_u8ADC_IN12_IN13() -> u8LH)
/* HL-struct byte access */
#define vSetADC_IN12_IN13HL(ParValue) (pst_u8ADC_IN12_IN13() -> u8HL = (ParValue))
#define u8GetADC_IN12_IN13HL() (pst_u8ADC_IN12_IN13() -> u8HL)
/* HH-struct byte access */
#define vSetADC_IN12_IN13HH(ParValue) (pst_u8ADC_IN12_IN13() -> u8HH = (ParValue))
#define u8GetADC_IN12_IN13HH() (pst_u8ADC_IN12_IN13() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADC_IN12_IN13L(ParValue) (pst_u16ADC_IN12_IN13() -> u16L = (ParValue))
#define u16GetADC_IN12_IN13L() (pst_u16ADC_IN12_IN13() -> u16L)
#define vSetADC_IN12_IN13H(ParValue) (pst_u16ADC_IN12_IN13() -> u16H = (ParValue))
#define u16GetADC_IN12_IN13H() (pst_u16ADC_IN12_IN13() -> u16H)
            
/* Word access */
#define vSetADC_IN12_IN13(ParValue)  (*pu32ADC_IN12_IN13() = (ParValue))
#define u32GetADC_IN12_IN13()  (*pu32ADC_IN12_IN13() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SC0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302280                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SC0_REG__       0xC0302280U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SC0_C0_LEFT_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:3; 	 /* 3..5  bit(s) R */
  uint32_t   SC0_LATCHN	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   SC0_PWDN	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   SC0_C0_RIGHT_SEL	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   SC0_C1_LEFT_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   SC0_C1_RIGHT_SEL	:3; 	 /* 24..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..31  bit(s) R */                    
} SC0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SC0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SC0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SC0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSC0()     ((volatile SC0_bit_view_st *)\
(SC0_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SC0()     ((volatile SC0_byte_view_st *)\
(SC0_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SC0()     ((volatile SC0_halfword_view_st *)\
(SC0_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SC0()     ((volatile u32SC0_word_view *)\
(SC0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSC0_SC0_C0_LEFT_SEL() (pst_bitSC0() -> SC0_C0_LEFT_SEL)
#define vSetSC0_SC0_C0_LEFT_SEL(ParValue)  (pst_bitSC0() -> SC0_C0_LEFT_SEL=(ParValue))
#define biGetSC0_SC0_LATCHN() (pst_bitSC0() -> SC0_LATCHN)
#define vSetSC0_SC0_LATCHN(ParValue)  (pst_bitSC0() -> SC0_LATCHN=(ParValue))
#define biGetSC0_SC0_PWDN() (pst_bitSC0() -> SC0_PWDN)
#define vSetSC0_SC0_PWDN(ParValue)  (pst_bitSC0() -> SC0_PWDN=(ParValue))
#define biGetSC0_SC0_C0_RIGHT_SEL() (pst_bitSC0() -> SC0_C0_RIGHT_SEL)
#define vSetSC0_SC0_C0_RIGHT_SEL(ParValue)  (pst_bitSC0() -> SC0_C0_RIGHT_SEL=(ParValue))
#define biGetSC0_SC0_C1_LEFT_SEL() (pst_bitSC0() -> SC0_C1_LEFT_SEL)
#define vSetSC0_SC0_C1_LEFT_SEL(ParValue)  (pst_bitSC0() -> SC0_C1_LEFT_SEL=(ParValue))
#define biGetSC0_SC0_C1_RIGHT_SEL() (pst_bitSC0() -> SC0_C1_RIGHT_SEL)
#define vSetSC0_SC0_C1_RIGHT_SEL(ParValue)  (pst_bitSC0() -> SC0_C1_RIGHT_SEL=(ParValue))
            
/* LL-struct byte access */
#define vSetSC0LL(ParValue) (pst_u8SC0() -> u8LL = (ParValue))
#define u8GetSC0LL() (pst_u8SC0() -> u8LL)
/* LH-struct byte access */
#define vSetSC0LH(ParValue) (pst_u8SC0() -> u8LH = (ParValue))
#define u8GetSC0LH() (pst_u8SC0() -> u8LH)
/* HL-struct byte access */
#define vSetSC0HL(ParValue) (pst_u8SC0() -> u8HL = (ParValue))
#define u8GetSC0HL() (pst_u8SC0() -> u8HL)
/* HH-struct byte access */
#define vSetSC0HH(ParValue) (pst_u8SC0() -> u8HH = (ParValue))
#define u8GetSC0HH() (pst_u8SC0() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSC0L(ParValue) (pst_u16SC0() -> u16L = (ParValue))
#define u16GetSC0L() (pst_u16SC0() -> u16L)
#define vSetSC0H(ParValue) (pst_u16SC0() -> u16H = (ParValue))
#define u16GetSC0H() (pst_u16SC0() -> u16H)
            
/* Word access */
#define vSetSC0(ParValue)  (*pu32SC0() = (ParValue))
#define u32GetSC0()  (*pu32SC0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SC1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302284                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SC1_REG__       0xC0302284U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SC1_C0_LEFT_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:3; 	 /* 3..5  bit(s) R */
  uint32_t   SC1_LATCHN	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   SC1_PWDN	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   SC1_C0_RIGHT_SEL	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   SC1_C1_LEFT_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   SC1_C1_RIGHT_SEL	:3; 	 /* 24..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..31  bit(s) R */                    
} SC1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SC1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SC1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SC1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSC1()     ((volatile SC1_bit_view_st *)\
(SC1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SC1()     ((volatile SC1_byte_view_st *)\
(SC1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SC1()     ((volatile SC1_halfword_view_st *)\
(SC1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SC1()     ((volatile u32SC1_word_view *)\
(SC1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSC1_SC1_C0_LEFT_SEL() (pst_bitSC1() -> SC1_C0_LEFT_SEL)
#define vSetSC1_SC1_C0_LEFT_SEL(ParValue)  (pst_bitSC1() -> SC1_C0_LEFT_SEL=(ParValue))
#define biGetSC1_SC1_LATCHN() (pst_bitSC1() -> SC1_LATCHN)
#define vSetSC1_SC1_LATCHN(ParValue)  (pst_bitSC1() -> SC1_LATCHN=(ParValue))
#define biGetSC1_SC1_PWDN() (pst_bitSC1() -> SC1_PWDN)
#define vSetSC1_SC1_PWDN(ParValue)  (pst_bitSC1() -> SC1_PWDN=(ParValue))
#define biGetSC1_SC1_C0_RIGHT_SEL() (pst_bitSC1() -> SC1_C0_RIGHT_SEL)
#define vSetSC1_SC1_C0_RIGHT_SEL(ParValue)  (pst_bitSC1() -> SC1_C0_RIGHT_SEL=(ParValue))
#define biGetSC1_SC1_C1_LEFT_SEL() (pst_bitSC1() -> SC1_C1_LEFT_SEL)
#define vSetSC1_SC1_C1_LEFT_SEL(ParValue)  (pst_bitSC1() -> SC1_C1_LEFT_SEL=(ParValue))
#define biGetSC1_SC1_C1_RIGHT_SEL() (pst_bitSC1() -> SC1_C1_RIGHT_SEL)
#define vSetSC1_SC1_C1_RIGHT_SEL(ParValue)  (pst_bitSC1() -> SC1_C1_RIGHT_SEL=(ParValue))
            
/* LL-struct byte access */
#define vSetSC1LL(ParValue) (pst_u8SC1() -> u8LL = (ParValue))
#define u8GetSC1LL() (pst_u8SC1() -> u8LL)
/* LH-struct byte access */
#define vSetSC1LH(ParValue) (pst_u8SC1() -> u8LH = (ParValue))
#define u8GetSC1LH() (pst_u8SC1() -> u8LH)
/* HL-struct byte access */
#define vSetSC1HL(ParValue) (pst_u8SC1() -> u8HL = (ParValue))
#define u8GetSC1HL() (pst_u8SC1() -> u8HL)
/* HH-struct byte access */
#define vSetSC1HH(ParValue) (pst_u8SC1() -> u8HH = (ParValue))
#define u8GetSC1HH() (pst_u8SC1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSC1L(ParValue) (pst_u16SC1() -> u16L = (ParValue))
#define u16GetSC1L() (pst_u16SC1() -> u16L)
#define vSetSC1H(ParValue) (pst_u16SC1() -> u16H = (ParValue))
#define u16GetSC1H() (pst_u16SC1() -> u16H)
            
/* Word access */
#define vSetSC1(ParValue)  (*pu32SC1() = (ParValue))
#define u32GetSC1()  (*pu32SC1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SC2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302288                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SC2_REG__       0xC0302288U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SC2_C0_LEFT_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:3; 	 /* 3..5  bit(s) R */
  uint32_t   SC2_LATCHN	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   SC2_PWDN	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   SC2_C0_RIGHT_SEL	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   SC2_C1_LEFT_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   SC2_C1_RIGHT_SEL	:3; 	 /* 24..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..31  bit(s) R */                    
} SC2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SC2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SC2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SC2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSC2()     ((volatile SC2_bit_view_st *)\
(SC2_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SC2()     ((volatile SC2_byte_view_st *)\
(SC2_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SC2()     ((volatile SC2_halfword_view_st *)\
(SC2_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SC2()     ((volatile u32SC2_word_view *)\
(SC2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSC2_SC2_C0_LEFT_SEL() (pst_bitSC2() -> SC2_C0_LEFT_SEL)
#define vSetSC2_SC2_C0_LEFT_SEL(ParValue)  (pst_bitSC2() -> SC2_C0_LEFT_SEL=(ParValue))
#define biGetSC2_SC2_LATCHN() (pst_bitSC2() -> SC2_LATCHN)
#define vSetSC2_SC2_LATCHN(ParValue)  (pst_bitSC2() -> SC2_LATCHN=(ParValue))
#define biGetSC2_SC2_PWDN() (pst_bitSC2() -> SC2_PWDN)
#define vSetSC2_SC2_PWDN(ParValue)  (pst_bitSC2() -> SC2_PWDN=(ParValue))
#define biGetSC2_SC2_C0_RIGHT_SEL() (pst_bitSC2() -> SC2_C0_RIGHT_SEL)
#define vSetSC2_SC2_C0_RIGHT_SEL(ParValue)  (pst_bitSC2() -> SC2_C0_RIGHT_SEL=(ParValue))
#define biGetSC2_SC2_C1_LEFT_SEL() (pst_bitSC2() -> SC2_C1_LEFT_SEL)
#define vSetSC2_SC2_C1_LEFT_SEL(ParValue)  (pst_bitSC2() -> SC2_C1_LEFT_SEL=(ParValue))
#define biGetSC2_SC2_C1_RIGHT_SEL() (pst_bitSC2() -> SC2_C1_RIGHT_SEL)
#define vSetSC2_SC2_C1_RIGHT_SEL(ParValue)  (pst_bitSC2() -> SC2_C1_RIGHT_SEL=(ParValue))
            
/* LL-struct byte access */
#define vSetSC2LL(ParValue) (pst_u8SC2() -> u8LL = (ParValue))
#define u8GetSC2LL() (pst_u8SC2() -> u8LL)
/* LH-struct byte access */
#define vSetSC2LH(ParValue) (pst_u8SC2() -> u8LH = (ParValue))
#define u8GetSC2LH() (pst_u8SC2() -> u8LH)
/* HL-struct byte access */
#define vSetSC2HL(ParValue) (pst_u8SC2() -> u8HL = (ParValue))
#define u8GetSC2HL() (pst_u8SC2() -> u8HL)
/* HH-struct byte access */
#define vSetSC2HH(ParValue) (pst_u8SC2() -> u8HH = (ParValue))
#define u8GetSC2HH() (pst_u8SC2() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSC2L(ParValue) (pst_u16SC2() -> u16L = (ParValue))
#define u16GetSC2L() (pst_u16SC2() -> u16L)
#define vSetSC2H(ParValue) (pst_u16SC2() -> u16H = (ParValue))
#define u16GetSC2H() (pst_u16SC2() -> u16H)
            
/* Word access */
#define vSetSC2(ParValue)  (*pu32SC2() = (ParValue))
#define u32GetSC2()  (*pu32SC2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SC3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030228C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SC3_REG__       0xC030228CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SC3_C0_LEFT_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:3; 	 /* 3..5  bit(s) R */
  uint32_t   SC3_LATCHN	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   SC3_PWDN	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   SC3_C0_RIGHT_SEL	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   SC3_C1_LEFT_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   SC3_C1_RIGHT_SEL	:3; 	 /* 24..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..31  bit(s) R */                    
} SC3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SC3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SC3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SC3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSC3()     ((volatile SC3_bit_view_st *)\
(SC3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SC3()     ((volatile SC3_byte_view_st *)\
(SC3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SC3()     ((volatile SC3_halfword_view_st *)\
(SC3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SC3()     ((volatile u32SC3_word_view *)\
(SC3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSC3_SC3_C0_LEFT_SEL() (pst_bitSC3() -> SC3_C0_LEFT_SEL)
#define vSetSC3_SC3_C0_LEFT_SEL(ParValue)  (pst_bitSC3() -> SC3_C0_LEFT_SEL=(ParValue))
#define biGetSC3_SC3_LATCHN() (pst_bitSC3() -> SC3_LATCHN)
#define vSetSC3_SC3_LATCHN(ParValue)  (pst_bitSC3() -> SC3_LATCHN=(ParValue))
#define biGetSC3_SC3_PWDN() (pst_bitSC3() -> SC3_PWDN)
#define vSetSC3_SC3_PWDN(ParValue)  (pst_bitSC3() -> SC3_PWDN=(ParValue))
#define biGetSC3_SC3_C0_RIGHT_SEL() (pst_bitSC3() -> SC3_C0_RIGHT_SEL)
#define vSetSC3_SC3_C0_RIGHT_SEL(ParValue)  (pst_bitSC3() -> SC3_C0_RIGHT_SEL=(ParValue))
#define biGetSC3_SC3_C1_LEFT_SEL() (pst_bitSC3() -> SC3_C1_LEFT_SEL)
#define vSetSC3_SC3_C1_LEFT_SEL(ParValue)  (pst_bitSC3() -> SC3_C1_LEFT_SEL=(ParValue))
#define biGetSC3_SC3_C1_RIGHT_SEL() (pst_bitSC3() -> SC3_C1_RIGHT_SEL)
#define vSetSC3_SC3_C1_RIGHT_SEL(ParValue)  (pst_bitSC3() -> SC3_C1_RIGHT_SEL=(ParValue))
            
/* LL-struct byte access */
#define vSetSC3LL(ParValue) (pst_u8SC3() -> u8LL = (ParValue))
#define u8GetSC3LL() (pst_u8SC3() -> u8LL)
/* LH-struct byte access */
#define vSetSC3LH(ParValue) (pst_u8SC3() -> u8LH = (ParValue))
#define u8GetSC3LH() (pst_u8SC3() -> u8LH)
/* HL-struct byte access */
#define vSetSC3HL(ParValue) (pst_u8SC3() -> u8HL = (ParValue))
#define u8GetSC3HL() (pst_u8SC3() -> u8HL)
/* HH-struct byte access */
#define vSetSC3HH(ParValue) (pst_u8SC3() -> u8HH = (ParValue))
#define u8GetSC3HH() (pst_u8SC3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSC3L(ParValue) (pst_u16SC3() -> u16L = (ParValue))
#define u16GetSC3L() (pst_u16SC3() -> u16L)
#define vSetSC3H(ParValue) (pst_u16SC3() -> u16H = (ParValue))
#define u16GetSC3H() (pst_u16SC3() -> u16H)
            
/* Word access */
#define vSetSC3(ParValue)  (*pu32SC3() = (ParValue))
#define u32GetSC3()  (*pu32SC3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SC4                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302290                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SC4_REG__       0xC0302290U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SC4_C0_LEFT_SEL	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:3; 	 /* 3..5  bit(s) R */
  uint32_t   SC4_LATCHN	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   SC4_PWDN	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   SC4_C0_RIGHT_SEL	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   SC4_C1_LEFT_SEL	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   SC4_C1_RIGHT_SEL	:3; 	 /* 24..26  bit(s) R/W */ 
  uint32_t   	:5; 	 /* 27..31  bit(s) R */                    
} SC4_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SC4_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SC4_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SC4_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSC4()     ((volatile SC4_bit_view_st *)\
(SC4_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SC4()     ((volatile SC4_byte_view_st *)\
(SC4_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SC4()     ((volatile SC4_halfword_view_st *)\
(SC4_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SC4()     ((volatile u32SC4_word_view *)\
(SC4_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSC4_SC4_C0_LEFT_SEL() (pst_bitSC4() -> SC4_C0_LEFT_SEL)
#define vSetSC4_SC4_C0_LEFT_SEL(ParValue)  (pst_bitSC4() -> SC4_C0_LEFT_SEL=(ParValue))
#define biGetSC4_SC4_LATCHN() (pst_bitSC4() -> SC4_LATCHN)
#define vSetSC4_SC4_LATCHN(ParValue)  (pst_bitSC4() -> SC4_LATCHN=(ParValue))
#define biGetSC4_SC4_PWDN() (pst_bitSC4() -> SC4_PWDN)
#define vSetSC4_SC4_PWDN(ParValue)  (pst_bitSC4() -> SC4_PWDN=(ParValue))
#define biGetSC4_SC4_C0_RIGHT_SEL() (pst_bitSC4() -> SC4_C0_RIGHT_SEL)
#define vSetSC4_SC4_C0_RIGHT_SEL(ParValue)  (pst_bitSC4() -> SC4_C0_RIGHT_SEL=(ParValue))
#define biGetSC4_SC4_C1_LEFT_SEL() (pst_bitSC4() -> SC4_C1_LEFT_SEL)
#define vSetSC4_SC4_C1_LEFT_SEL(ParValue)  (pst_bitSC4() -> SC4_C1_LEFT_SEL=(ParValue))
#define biGetSC4_SC4_C1_RIGHT_SEL() (pst_bitSC4() -> SC4_C1_RIGHT_SEL)
#define vSetSC4_SC4_C1_RIGHT_SEL(ParValue)  (pst_bitSC4() -> SC4_C1_RIGHT_SEL=(ParValue))
            
/* LL-struct byte access */
#define vSetSC4LL(ParValue) (pst_u8SC4() -> u8LL = (ParValue))
#define u8GetSC4LL() (pst_u8SC4() -> u8LL)
/* LH-struct byte access */
#define vSetSC4LH(ParValue) (pst_u8SC4() -> u8LH = (ParValue))
#define u8GetSC4LH() (pst_u8SC4() -> u8LH)
/* HL-struct byte access */
#define vSetSC4HL(ParValue) (pst_u8SC4() -> u8HL = (ParValue))
#define u8GetSC4HL() (pst_u8SC4() -> u8HL)
/* HH-struct byte access */
#define vSetSC4HH(ParValue) (pst_u8SC4() -> u8HH = (ParValue))
#define u8GetSC4HH() (pst_u8SC4() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSC4L(ParValue) (pst_u16SC4() -> u16L = (ParValue))
#define u16GetSC4L() (pst_u16SC4() -> u16L)
#define vSetSC4H(ParValue) (pst_u16SC4() -> u16H = (ParValue))
#define u16GetSC4H() (pst_u16SC4() -> u16H)
            
/* Word access */
#define vSetSC4(ParValue)  (*pu32SC4() = (ParValue))
#define u32GetSC4()  (*pu32SC4() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SDRAM_CFG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302294                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SDRAM_CFG_REG__       0xC0302294U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   SDRAM_IF_SEL	:2; 	 /* 0..1  bit(s) R/W */ 
  uint8_t   	:6; 	 /* 2..31  bit(s) R */                    
} SDRAM_CFG_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SDRAM_CFG_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSDRAM_CFG()     ((volatile SDRAM_CFG_bit_view_st *)\
(SDRAM_CFG_REG__ ))
        
/* Pointer to BYTE  */
#define pu8SDRAM_CFG()     ((volatile u8SDRAM_CFG_byte_view *)\
(SDRAM_CFG_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSDRAM_CFG_SDRAM_IF_SEL() (pst_bitSDRAM_CFG() -> SDRAM_IF_SEL)
#define vSetSDRAM_CFG_SDRAM_IF_SEL(ParValue)  (pst_bitSDRAM_CFG() -> SDRAM_IF_SEL=(ParValue))
            
/* byte access */
#define vSetSDRAM_CFG(ParValue) (*pu8SDRAM_CFG() = (ParValue))
#define u8GetSDRAM_CFG() (*pu8SDRAM_CFG() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GPIO                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302800                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define GPIO_REG__       0xC0302800U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GPIO_WDATA	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   GPIO_RDATA	:8; 	 /* 8..15  bit(s) R */
  uint32_t   GPIO_DIR	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} GPIO_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GPIO_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GPIO_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GPIO_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGPIO(ch)     ((volatile GPIO_bit_view_st *)\
(GPIO_REG__  + ((uint16_t)(ch) * 0x004U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8GPIO(ch)     ((volatile GPIO_byte_view_st *)\
(GPIO_REG__  + ((uint16_t)(ch) * 0x004U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GPIO(ch)     ((volatile GPIO_halfword_view_st *)\
(GPIO_REG__  + ((uint16_t)(ch) * 0x004U)))
            
/* Pointer to WORD  */ 
#define pu32GPIO(ch)     ((volatile u32GPIO_word_view *)\
(GPIO_REG__  + ((uint16_t)(ch) * 0x004U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGPIO_GPIO_WDATA(ch) (pst_bitGPIO(ch) -> GPIO_WDATA)
#define vSetGPIO_GPIO_WDATA(ch,ParValue)  (pst_bitGPIO(ch) -> GPIO_WDATA=(ParValue))            
#define biGetGPIO_GPIO_RDATA(ch) (pst_bitGPIO(ch) -> GPIO_RDATA)
#define biGetGPIO_GPIO_DIR(ch) (pst_bitGPIO(ch) -> GPIO_DIR)
#define vSetGPIO_GPIO_DIR(ch,ParValue)  (pst_bitGPIO(ch) -> GPIO_DIR=(ParValue))
            
/* LL-struct byte access */
#define vSetGPIOLL(ch,ParValue) (pst_u8GPIO(ch) -> u8LL = (ParValue))
#define u8GetGPIOLL(ch) (pst_u8GPIO(ch) -> u8LL)
/* LH-struct byte access */
#define vSetGPIOLH(ch,ParValue) (pst_u8GPIO(ch) -> u8LH = (ParValue))
#define u8GetGPIOLH(ch) (pst_u8GPIO(ch) -> u8LH)
/* HL-struct byte access */
#define vSetGPIOHL(ch,ParValue) (pst_u8GPIO(ch) -> u8HL = (ParValue))
#define u8GetGPIOHL(ch) (pst_u8GPIO(ch) -> u8HL)
/* HH-struct byte access */
#define vSetGPIOHH(ch,ParValue) (pst_u8GPIO(ch) -> u8HH = (ParValue))
#define u8GetGPIOHH(ch) (pst_u8GPIO(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGPIOL(ch,ParValue) (pst_u16GPIO(ch) -> u16L = (ParValue))
#define u16GetGPIOL(ch) (pst_u16GPIO(ch) -> u16L)
#define vSetGPIOH(ch,ParValue) (pst_u16GPIO(ch) -> u16H = (ParValue))
#define u16GetGPIOH(ch) (pst_u16GPIO(ch) -> u16H)
            
/* Word access */
#define vSetGPIO(ch,ParValue)  (*pu32GPIO(ch) = (ParValue))
#define u32GetGPIO(ch)  (*pu32GPIO(ch) )
            
/******************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */ 
/******************************************************************************/
    
/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :   Deactivated:
** |     Not requested Rules: 
** |         Rule 5.7  [A] : disable No reuse of identifiers
** |         Rule 19.7 [A] : Function used instead of function-like macro when possible
** |
** |     Requested Rules:
** |         Rule	5.1  [R] : No more than 31 chars to determine an identifier
** |         Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types
** |                         Used for bit definitons generated by converter tool
** |         Rule 20.1 [R] : No definition, redefinition, or undefinition of reserved words and standard library names
** |                         register names are generated by converter tool from HW specs
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/
/****************************************************************************/

#endif /* PINMUXIO_H */ 
    
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

