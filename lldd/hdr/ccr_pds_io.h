
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : SysCon_PDS 
/  Date of creation (y-m-d:time): 2015-05-27+02:00  :  10:51:15.232+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.13 $ 
/  Excel Sheet ver.             : vv9.18
/  Excel Sheet date             : 2015-May-19
/  Excel Sheet author           : BEL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : CCD_PDS low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : CCR
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.13 $ 
*   DATE        : $Date: 2015/05/27 09:37:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef SysCon_PDSIO_H
#define SysCon_PDSIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */ 
/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_CCR_PDS_IO_H_REVISION     "$Revision: 1.13 $"
#define LLDD_CCR_PDS_IO_H_TAG          "$Name: LLDD_1_6 $"
     
/*********************************************/
/* disable following Misra errors for io files */
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1840   /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 230    /* Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types */
  #pragma ghs nowarning 1752   /* Rule 17.4 [R] : No pointer arithmetic other than array indexing */
#endif 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_KEYR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000000                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_KEYR_REG__       0xC0000000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   KEYVAL	:32; 	 /* 0..31  bit(s) R/W */                    
} CCR_KEYR_bit_view_st;
        

/* WORD View */
typedef uint32_t u32CCR_KEYR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_KEYR()     ((volatile CCR_KEYR_bit_view_st *)\
(CCR_KEYR_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32CCR_KEYR()     ((volatile u32CCR_KEYR_word_view *)\
(CCR_KEYR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_KEYR_KEYVAL() (pst_bitCCR_KEYR() -> KEYVAL)
#define vSetCCR_KEYR_KEYVAL(ParValue)  (pst_bitCCR_KEYR() -> KEYVAL=(ParValue))
            
/* Word access */
#define vSetCCR_KEYR(ParValue)  (*pu32CCR_KEYR() = (ParValue))
#define u32GetCCR_KEYR()  (*pu32CCR_KEYR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_CLKDIVM1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_CLKDIVM1_REG__       0xC0000004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GDC0	:12; 	 /* 0..11  bit(s) R/W */
  uint32_t   	:4; 	 /* 12..15  bit(s) R */
  uint32_t   GDC1	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} CCR_CLKDIVM1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_CLKDIVM1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_CLKDIVM1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_CLKDIVM1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_CLKDIVM1()     ((volatile CCR_CLKDIVM1_bit_view_st *)\
(CCR_CLKDIVM1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_CLKDIVM1()     ((volatile CCR_CLKDIVM1_byte_view_st *)\
(CCR_CLKDIVM1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_CLKDIVM1()     ((volatile CCR_CLKDIVM1_halfword_view_st *)\
(CCR_CLKDIVM1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_CLKDIVM1()     ((volatile u32CCR_CLKDIVM1_word_view *)\
(CCR_CLKDIVM1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_CLKDIVM1_GDC0() (pst_bitCCR_CLKDIVM1() -> GDC0)
#define vSetCCR_CLKDIVM1_GDC0(ParValue)  (pst_bitCCR_CLKDIVM1() -> GDC0=(ParValue))
#define biGetCCR_CLKDIVM1_GDC1() (pst_bitCCR_CLKDIVM1() -> GDC1)
#define vSetCCR_CLKDIVM1_GDC1(ParValue)  (pst_bitCCR_CLKDIVM1() -> GDC1=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_CLKDIVM1LL(ParValue) (pst_u8CCR_CLKDIVM1() -> u8LL = (ParValue))
#define u8GetCCR_CLKDIVM1LL() (pst_u8CCR_CLKDIVM1() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_CLKDIVM1LH(ParValue) (pst_u8CCR_CLKDIVM1() -> u8LH = (ParValue))
#define u8GetCCR_CLKDIVM1LH() (pst_u8CCR_CLKDIVM1() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_CLKDIVM1HL(ParValue) (pst_u8CCR_CLKDIVM1() -> u8HL = (ParValue))
#define u8GetCCR_CLKDIVM1HL() (pst_u8CCR_CLKDIVM1() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_CLKDIVM1HH(ParValue) (pst_u8CCR_CLKDIVM1() -> u8HH = (ParValue))
#define u8GetCCR_CLKDIVM1HH() (pst_u8CCR_CLKDIVM1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_CLKDIVM1L(ParValue) (pst_u16CCR_CLKDIVM1() -> u16L = (ParValue))
#define u16GetCCR_CLKDIVM1L() (pst_u16CCR_CLKDIVM1() -> u16L)
#define vSetCCR_CLKDIVM1H(ParValue) (pst_u16CCR_CLKDIVM1() -> u16H = (ParValue))
#define u16GetCCR_CLKDIVM1H() (pst_u16CCR_CLKDIVM1() -> u16H)
            
/* Word access */
#define vSetCCR_CLKDIVM1(ParValue)  (*pu32CCR_CLKDIVM1() = (ParValue))
#define u32GetCCR_CLKDIVM1()  (*pu32CCR_CLKDIVM1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_CLKDIVM2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_CLKDIVM2_REG__       0xC0000008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   QSPI0	:5; 	 /* 0..4  bit(s) R/W */
  uint32_t   	:3; 	 /* 5..7  bit(s) R */
  uint32_t   QSPI1	:5; 	 /* 8..12  bit(s) R/W */
  uint32_t   	:3; 	 /* 13..15  bit(s) R */
  uint32_t   QSPI2	:5; 	 /* 16..20  bit(s) R/W */
  uint32_t   	:3; 	 /* 21..23  bit(s) R */
  uint32_t   SDRAMIF	:4; 	 /* 24..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} CCR_CLKDIVM2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_CLKDIVM2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_CLKDIVM2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_CLKDIVM2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_CLKDIVM2()     ((volatile CCR_CLKDIVM2_bit_view_st *)\
(CCR_CLKDIVM2_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_CLKDIVM2()     ((volatile CCR_CLKDIVM2_byte_view_st *)\
(CCR_CLKDIVM2_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_CLKDIVM2()     ((volatile CCR_CLKDIVM2_halfword_view_st *)\
(CCR_CLKDIVM2_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_CLKDIVM2()     ((volatile u32CCR_CLKDIVM2_word_view *)\
(CCR_CLKDIVM2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_CLKDIVM2_QSPI0() (pst_bitCCR_CLKDIVM2() -> QSPI0)
#define vSetCCR_CLKDIVM2_QSPI0(ParValue)  (pst_bitCCR_CLKDIVM2() -> QSPI0=(ParValue))
#define biGetCCR_CLKDIVM2_QSPI1() (pst_bitCCR_CLKDIVM2() -> QSPI1)
#define vSetCCR_CLKDIVM2_QSPI1(ParValue)  (pst_bitCCR_CLKDIVM2() -> QSPI1=(ParValue))
#define biGetCCR_CLKDIVM2_QSPI2() (pst_bitCCR_CLKDIVM2() -> QSPI2)
#define vSetCCR_CLKDIVM2_QSPI2(ParValue)  (pst_bitCCR_CLKDIVM2() -> QSPI2=(ParValue))
#define biGetCCR_CLKDIVM2_SDRAMIF() (pst_bitCCR_CLKDIVM2() -> SDRAMIF)
#define vSetCCR_CLKDIVM2_SDRAMIF(ParValue)  (pst_bitCCR_CLKDIVM2() -> SDRAMIF=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_CLKDIVM2LL(ParValue) (pst_u8CCR_CLKDIVM2() -> u8LL = (ParValue))
#define u8GetCCR_CLKDIVM2LL() (pst_u8CCR_CLKDIVM2() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_CLKDIVM2LH(ParValue) (pst_u8CCR_CLKDIVM2() -> u8LH = (ParValue))
#define u8GetCCR_CLKDIVM2LH() (pst_u8CCR_CLKDIVM2() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_CLKDIVM2HL(ParValue) (pst_u8CCR_CLKDIVM2() -> u8HL = (ParValue))
#define u8GetCCR_CLKDIVM2HL() (pst_u8CCR_CLKDIVM2() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_CLKDIVM2HH(ParValue) (pst_u8CCR_CLKDIVM2() -> u8HH = (ParValue))
#define u8GetCCR_CLKDIVM2HH() (pst_u8CCR_CLKDIVM2() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_CLKDIVM2L(ParValue) (pst_u16CCR_CLKDIVM2() -> u16L = (ParValue))
#define u16GetCCR_CLKDIVM2L() (pst_u16CCR_CLKDIVM2() -> u16L)
#define vSetCCR_CLKDIVM2H(ParValue) (pst_u16CCR_CLKDIVM2() -> u16H = (ParValue))
#define u16GetCCR_CLKDIVM2H() (pst_u16CCR_CLKDIVM2() -> u16H)
            
/* Word access */
#define vSetCCR_CLKDIVM2(ParValue)  (*pu32CCR_CLKDIVM2() = (ParValue))
#define u32GetCCR_CLKDIVM2()  (*pu32CCR_CLKDIVM2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_CLKDIVM3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000000C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_CLKDIVM3_REG__       0xC000000CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   I2S	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   	:8; 	 /* 8..15  bit(s) R */
  uint32_t   PL353	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} CCR_CLKDIVM3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_CLKDIVM3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_CLKDIVM3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_CLKDIVM3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_CLKDIVM3()     ((volatile CCR_CLKDIVM3_bit_view_st *)\
(CCR_CLKDIVM3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_CLKDIVM3()     ((volatile CCR_CLKDIVM3_byte_view_st *)\
(CCR_CLKDIVM3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_CLKDIVM3()     ((volatile CCR_CLKDIVM3_halfword_view_st *)\
(CCR_CLKDIVM3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_CLKDIVM3()     ((volatile u32CCR_CLKDIVM3_word_view *)\
(CCR_CLKDIVM3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_CLKDIVM3_I2S() (pst_bitCCR_CLKDIVM3() -> I2S)
#define vSetCCR_CLKDIVM3_I2S(ParValue)  (pst_bitCCR_CLKDIVM3() -> I2S=(ParValue))
#define biGetCCR_CLKDIVM3_PL353() (pst_bitCCR_CLKDIVM3() -> PL353)
#define vSetCCR_CLKDIVM3_PL353(ParValue)  (pst_bitCCR_CLKDIVM3() -> PL353=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_CLKDIVM3LL(ParValue) (pst_u8CCR_CLKDIVM3() -> u8LL = (ParValue))
#define u8GetCCR_CLKDIVM3LL() (pst_u8CCR_CLKDIVM3() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_CLKDIVM3LH(ParValue) (pst_u8CCR_CLKDIVM3() -> u8LH = (ParValue))
#define u8GetCCR_CLKDIVM3LH() (pst_u8CCR_CLKDIVM3() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_CLKDIVM3HL(ParValue) (pst_u8CCR_CLKDIVM3() -> u8HL = (ParValue))
#define u8GetCCR_CLKDIVM3HL() (pst_u8CCR_CLKDIVM3() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_CLKDIVM3HH(ParValue) (pst_u8CCR_CLKDIVM3() -> u8HH = (ParValue))
#define u8GetCCR_CLKDIVM3HH() (pst_u8CCR_CLKDIVM3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_CLKDIVM3L(ParValue) (pst_u16CCR_CLKDIVM3() -> u16L = (ParValue))
#define u16GetCCR_CLKDIVM3L() (pst_u16CCR_CLKDIVM3() -> u16L)
#define vSetCCR_CLKDIVM3H(ParValue) (pst_u16CCR_CLKDIVM3() -> u16H = (ParValue))
#define u16GetCCR_CLKDIVM3H() (pst_u16CCR_CLKDIVM3() -> u16H)
            
/* Word access */
#define vSetCCR_CLKDIVM3(ParValue)  (*pu32CCR_CLKDIVM3() = (ParValue))
#define u32GetCCR_CLKDIVM3()  (*pu32CCR_CLKDIVM3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_CLKDIVNM1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_CLKDIVNM1_REG__       0xC0000010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GDC0	:12; 	 /* 0..11  bit(s) R/W */
  uint32_t   	:4; 	 /* 12..15  bit(s) R */
  uint32_t   GDC1	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} CCR_CLKDIVNM1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_CLKDIVNM1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_CLKDIVNM1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_CLKDIVNM1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_CLKDIVNM1()     ((volatile CCR_CLKDIVNM1_bit_view_st *)\
(CCR_CLKDIVNM1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_CLKDIVNM1()     ((volatile CCR_CLKDIVNM1_byte_view_st *)\
(CCR_CLKDIVNM1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_CLKDIVNM1()     ((volatile CCR_CLKDIVNM1_halfword_view_st *)\
(CCR_CLKDIVNM1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_CLKDIVNM1()     ((volatile u32CCR_CLKDIVNM1_word_view *)\
(CCR_CLKDIVNM1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_CLKDIVNM1_GDC0() (pst_bitCCR_CLKDIVNM1() -> GDC0)
#define vSetCCR_CLKDIVNM1_GDC0(ParValue)  (pst_bitCCR_CLKDIVNM1() -> GDC0=(ParValue))
#define biGetCCR_CLKDIVNM1_GDC1() (pst_bitCCR_CLKDIVNM1() -> GDC1)
#define vSetCCR_CLKDIVNM1_GDC1(ParValue)  (pst_bitCCR_CLKDIVNM1() -> GDC1=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_CLKDIVNM1LL(ParValue) (pst_u8CCR_CLKDIVNM1() -> u8LL = (ParValue))
#define u8GetCCR_CLKDIVNM1LL() (pst_u8CCR_CLKDIVNM1() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_CLKDIVNM1LH(ParValue) (pst_u8CCR_CLKDIVNM1() -> u8LH = (ParValue))
#define u8GetCCR_CLKDIVNM1LH() (pst_u8CCR_CLKDIVNM1() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_CLKDIVNM1HL(ParValue) (pst_u8CCR_CLKDIVNM1() -> u8HL = (ParValue))
#define u8GetCCR_CLKDIVNM1HL() (pst_u8CCR_CLKDIVNM1() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_CLKDIVNM1HH(ParValue) (pst_u8CCR_CLKDIVNM1() -> u8HH = (ParValue))
#define u8GetCCR_CLKDIVNM1HH() (pst_u8CCR_CLKDIVNM1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_CLKDIVNM1L(ParValue) (pst_u16CCR_CLKDIVNM1() -> u16L = (ParValue))
#define u16GetCCR_CLKDIVNM1L() (pst_u16CCR_CLKDIVNM1() -> u16L)
#define vSetCCR_CLKDIVNM1H(ParValue) (pst_u16CCR_CLKDIVNM1() -> u16H = (ParValue))
#define u16GetCCR_CLKDIVNM1H() (pst_u16CCR_CLKDIVNM1() -> u16H)
            
/* Word access */
#define vSetCCR_CLKDIVNM1(ParValue)  (*pu32CCR_CLKDIVNM1() = (ParValue))
#define u32GetCCR_CLKDIVNM1()  (*pu32CCR_CLKDIVNM1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_CLKDIVNM2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000014                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_CLKDIVNM2_REG__       0xC0000014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   TRACE	:5; 	 /* 0..4  bit(s) R/W */
  uint8_t   	:3; 	 /* 5..7  bit(s) R */                    
} CCR_CLKDIVNM2_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8CCR_CLKDIVNM2_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_CLKDIVNM2()     ((volatile CCR_CLKDIVNM2_bit_view_st *)\
(CCR_CLKDIVNM2_REG__ ))
        
/* Pointer to BYTE  */
#define pu8CCR_CLKDIVNM2()     ((volatile u8CCR_CLKDIVNM2_byte_view *)\
(CCR_CLKDIVNM2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_CLKDIVNM2_TRACE() (pst_bitCCR_CLKDIVNM2() -> TRACE)
#define vSetCCR_CLKDIVNM2_TRACE(ParValue)  (pst_bitCCR_CLKDIVNM2() -> TRACE=(ParValue))
            
/* byte access */
#define vSetCCR_CLKDIVNM2(ParValue) (*pu8CCR_CLKDIVNM2() = (ParValue))
#define u8GetCCR_CLKDIVNM2() (*pu8CCR_CLKDIVNM2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_CLKDIVNM3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_CLKDIVNM3_REG__       0xC0000018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   I2S	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   	:8; 	 /* 8..15  bit(s) R */
  uint32_t   PL353	:12; 	 /* 16..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} CCR_CLKDIVNM3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_CLKDIVNM3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_CLKDIVNM3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_CLKDIVNM3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_CLKDIVNM3()     ((volatile CCR_CLKDIVNM3_bit_view_st *)\
(CCR_CLKDIVNM3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_CLKDIVNM3()     ((volatile CCR_CLKDIVNM3_byte_view_st *)\
(CCR_CLKDIVNM3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_CLKDIVNM3()     ((volatile CCR_CLKDIVNM3_halfword_view_st *)\
(CCR_CLKDIVNM3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_CLKDIVNM3()     ((volatile u32CCR_CLKDIVNM3_word_view *)\
(CCR_CLKDIVNM3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_CLKDIVNM3_I2S() (pst_bitCCR_CLKDIVNM3() -> I2S)
#define vSetCCR_CLKDIVNM3_I2S(ParValue)  (pst_bitCCR_CLKDIVNM3() -> I2S=(ParValue))
#define biGetCCR_CLKDIVNM3_PL353() (pst_bitCCR_CLKDIVNM3() -> PL353)
#define vSetCCR_CLKDIVNM3_PL353(ParValue)  (pst_bitCCR_CLKDIVNM3() -> PL353=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_CLKDIVNM3LL(ParValue) (pst_u8CCR_CLKDIVNM3() -> u8LL = (ParValue))
#define u8GetCCR_CLKDIVNM3LL() (pst_u8CCR_CLKDIVNM3() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_CLKDIVNM3LH(ParValue) (pst_u8CCR_CLKDIVNM3() -> u8LH = (ParValue))
#define u8GetCCR_CLKDIVNM3LH() (pst_u8CCR_CLKDIVNM3() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_CLKDIVNM3HL(ParValue) (pst_u8CCR_CLKDIVNM3() -> u8HL = (ParValue))
#define u8GetCCR_CLKDIVNM3HL() (pst_u8CCR_CLKDIVNM3() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_CLKDIVNM3HH(ParValue) (pst_u8CCR_CLKDIVNM3() -> u8HH = (ParValue))
#define u8GetCCR_CLKDIVNM3HH() (pst_u8CCR_CLKDIVNM3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_CLKDIVNM3L(ParValue) (pst_u16CCR_CLKDIVNM3() -> u16L = (ParValue))
#define u16GetCCR_CLKDIVNM3L() (pst_u16CCR_CLKDIVNM3() -> u16L)
#define vSetCCR_CLKDIVNM3H(ParValue) (pst_u16CCR_CLKDIVNM3() -> u16H = (ParValue))
#define u16GetCCR_CLKDIVNM3H() (pst_u16CCR_CLKDIVNM3() -> u16H)
            
/* Word access */
#define vSetCCR_CLKDIVNM3(ParValue)  (*pu32CCR_CLKDIVNM3() = (ParValue))
#define u32GetCCR_CLKDIVNM3()  (*pu32CCR_CLKDIVNM3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_CLKDIVACK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000001C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_CLKDIVACK_REG__       0xC000001CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   RELOADACK_MGDC0	:1; 	 /* 0..0  bit(s) R/W0C */
  uint16_t   RELOADACK_MGDC1	:1; 	 /* 1..1  bit(s) R/W0C */
  uint16_t   RELOADACK_MQSPI0	:1; 	 /* 2..2  bit(s) R/W0C */
  uint16_t   RELOADACK_MQSPI1	:1; 	 /* 3..3  bit(s) R/W0C */
  uint16_t   RELOADACK_MQSPI2	:1; 	 /* 4..4  bit(s) R/W0C */
  uint16_t   RELOADACK_MSDRAM	:1; 	 /* 5..5  bit(s) R/W0C */
  uint16_t   RELOADACK_MI2S	:1; 	 /* 6..6  bit(s) R/W0C */
  uint16_t   RELOADACK_MPL353	:1; 	 /* 7..7  bit(s) R/W0C */
  uint16_t   RELOADACK_NMGDC0	:1; 	 /* 8..8  bit(s) R/W0C */
  uint16_t   RELOADACK_NMGDC1	:1; 	 /* 9..9  bit(s) R/W0C */
  uint16_t   RELOADACK_NMTRACE	:1; 	 /* 10..10  bit(s) R/W0C */
  uint16_t   	:3; 	 /* 11..13  bit(s) R */
  uint16_t   RELOADACK_NMI2S	:1; 	 /* 14..14  bit(s) R/W0C */
  uint16_t   RELOADACK_NMPL353	:1; 	 /* 15..15  bit(s) R/W0C */                    
} CCR_CLKDIVACK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} CCR_CLKDIVACK_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16CCR_CLKDIVACK_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_CLKDIVACK()     ((volatile CCR_CLKDIVACK_bit_view_st *)\
(CCR_CLKDIVACK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_CLKDIVACK()     ((volatile CCR_CLKDIVACK_byte_view_st *)\
(CCR_CLKDIVACK_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16CCR_CLKDIVACK()     ((volatile u16CCR_CLKDIVACK_halfword_view *)\
(CCR_CLKDIVACK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_CLKDIVACK_RELOADACK_MGDC0() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MGDC0)
#define vClrCCR_CLKDIVACK_RELOADACK_MGDC0() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MGDC0=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_MGDC1() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MGDC1)
#define vClrCCR_CLKDIVACK_RELOADACK_MGDC1() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MGDC1=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_MQSPI0() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MQSPI0)
#define vClrCCR_CLKDIVACK_RELOADACK_MQSPI0() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MQSPI0=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_MQSPI1() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MQSPI1)
#define vClrCCR_CLKDIVACK_RELOADACK_MQSPI1() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MQSPI1=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_MQSPI2() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MQSPI2)
#define vClrCCR_CLKDIVACK_RELOADACK_MQSPI2() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MQSPI2=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_MSDRAM() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MSDRAM)
#define vClrCCR_CLKDIVACK_RELOADACK_MSDRAM() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MSDRAM=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_MI2S() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MI2S)
#define vClrCCR_CLKDIVACK_RELOADACK_MI2S() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MI2S=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_MPL353() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MPL353)
#define vClrCCR_CLKDIVACK_RELOADACK_MPL353() (pst_bitCCR_CLKDIVACK() -> RELOADACK_MPL353=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_NMGDC0() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMGDC0)
#define vClrCCR_CLKDIVACK_RELOADACK_NMGDC0() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMGDC0=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_NMGDC1() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMGDC1)
#define vClrCCR_CLKDIVACK_RELOADACK_NMGDC1() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMGDC1=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_NMTRACE() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMTRACE)
#define vClrCCR_CLKDIVACK_RELOADACK_NMTRACE() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMTRACE=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_NMI2S() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMI2S)
#define vClrCCR_CLKDIVACK_RELOADACK_NMI2S() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMI2S=(0))
#define biGetCCR_CLKDIVACK_RELOADACK_NMPL353() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMPL353)
#define vClrCCR_CLKDIVACK_RELOADACK_NMPL353() (pst_bitCCR_CLKDIVACK() -> RELOADACK_NMPL353=(0))
            
/* L-struct byte access */
#define vSetCCR_CLKDIVACKL(ParValue) (pst_u8CCR_CLKDIVACK() -> u8L = (ParValue))
#define u8GetCCR_CLKDIVACKL() (pst_u8CCR_CLKDIVACK() -> u8L)
/* H-struct byte access */
#define vSetCCR_CLKDIVACKH(ParValue) (pst_u8CCR_CLKDIVACK() -> u8H = (ParValue))
#define u8GetCCR_CLKDIVACKH() (pst_u8CCR_CLKDIVACK() -> u8H)
            
/* Half-word access */ 
#define vSetCCR_CLKDIVACK(ParValue) (*pu16CCR_CLKDIVACK()  = (ParValue))
#define u16GetCCR_CLKDIVACK() (*pu16CCR_CLKDIVACK() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_CLKSEL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000020                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_CLKSEL_REG__       0xC0000020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CLK_DOT0_SEL	:2; 	 /* 0..1  bit(s) R/W */
  uint16_t   CLK_DOT1_SEL	:3; 	 /* 2..4  bit(s) R/W */
  uint16_t   CLK_I2S_SEL	:2; 	 /* 5..6  bit(s) R/W */
  uint16_t   	:1; 	 /* 7..7  bit(s) R */
  uint16_t   CLK_PL353_SEL	:2; 	 /* 8..9  bit(s) R/W */
  uint16_t   CLK_300_SEL	:1; 	 /* 10..10  bit(s) R/W */
  uint16_t   	:1; 	 /* 11..11  bit(s) R */
  uint16_t   CLK_ADC_SEL	:3; 	 /* 12..14  bit(s) R/W */ 
  uint16_t   	:1; 	 /* 15..31  bit(s) R */                    
} CCR_CLKSEL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} CCR_CLKSEL_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16CCR_CLKSEL_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_CLKSEL()     ((volatile CCR_CLKSEL_bit_view_st *)\
(CCR_CLKSEL_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_CLKSEL()     ((volatile CCR_CLKSEL_byte_view_st *)\
(CCR_CLKSEL_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16CCR_CLKSEL()     ((volatile u16CCR_CLKSEL_halfword_view *)\
(CCR_CLKSEL_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_CLKSEL_CLK_DOT0_SEL() (pst_bitCCR_CLKSEL() -> CLK_DOT0_SEL)
#define vSetCCR_CLKSEL_CLK_DOT0_SEL(ParValue)  (pst_bitCCR_CLKSEL() -> CLK_DOT0_SEL=(ParValue))
#define biGetCCR_CLKSEL_CLK_DOT1_SEL() (pst_bitCCR_CLKSEL() -> CLK_DOT1_SEL)
#define vSetCCR_CLKSEL_CLK_DOT1_SEL(ParValue)  (pst_bitCCR_CLKSEL() -> CLK_DOT1_SEL=(ParValue))
#define biGetCCR_CLKSEL_CLK_I2S_SEL() (pst_bitCCR_CLKSEL() -> CLK_I2S_SEL)
#define vSetCCR_CLKSEL_CLK_I2S_SEL(ParValue)  (pst_bitCCR_CLKSEL() -> CLK_I2S_SEL=(ParValue))
#define biGetCCR_CLKSEL_CLK_PL353_SEL() (pst_bitCCR_CLKSEL() -> CLK_PL353_SEL)
#define vSetCCR_CLKSEL_CLK_PL353_SEL(ParValue)  (pst_bitCCR_CLKSEL() -> CLK_PL353_SEL=(ParValue))
#define biGetCCR_CLKSEL_CLK_300_SEL() (pst_bitCCR_CLKSEL() -> CLK_300_SEL)
#define vSetCCR_CLKSEL_CLK_300_SEL(ParValue)  (pst_bitCCR_CLKSEL() -> CLK_300_SEL=(ParValue))
#define biGetCCR_CLKSEL_CLK_ADC_SEL() (pst_bitCCR_CLKSEL() -> CLK_ADC_SEL)
#define vSetCCR_CLKSEL_CLK_ADC_SEL(ParValue)  (pst_bitCCR_CLKSEL() -> CLK_ADC_SEL=(ParValue))
            
/* L-struct byte access */
#define vSetCCR_CLKSELL(ParValue) (pst_u8CCR_CLKSEL() -> u8L = (ParValue))
#define u8GetCCR_CLKSELL() (pst_u8CCR_CLKSEL() -> u8L)
/* H-struct byte access */
#define vSetCCR_CLKSELH(ParValue) (pst_u8CCR_CLKSEL() -> u8H = (ParValue))
#define u8GetCCR_CLKSELH() (pst_u8CCR_CLKSEL() -> u8H)
            
/* Half-word access */ 
#define vSetCCR_CLKSEL(ParValue) (*pu16CCR_CLKSEL()  = (ParValue))
#define u16GetCCR_CLKSEL() (*pu16CCR_CLKSEL() )     

/****************************************************************************   
*                                                                               
*       REGISTER: CCR_PERICLKGATE                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000024                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_PERICLKGATE_REG__       0xC0000024U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CLK_QSPI0_GATE	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   CLK_QSPI1_GATE	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   CLK_QSPI2_GATE	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   CLK_DMA_GATE	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   CLK_PARFL_GATE	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   CLK_DAP_GATE	:1; 	 /* 5..5  bit(s) R/W */
  uint32_t   CLK_GA_GATE	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   	:3; 	 /* 7..9  bit(s) R */
  uint32_t   CLK_PNG_GATE	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CLK_GDC0_GATE	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   CLK_GDC1_GATE	:1; 	 /* 12..12  bit(s) R/W */
  uint32_t   CLK_FG_GATE	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   CLK_MLB_GATE	:1; 	 /* 14..14  bit(s) R/W */
  uint32_t   CLK_SDRAM_GATE	:1; 	 /* 15..15  bit(s) R/W */
  uint32_t   CLK_SMC_GATE	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   	:1; 	 /* 17..17  bit(s) R */
  uint32_t   CLK_I2S_GATE	:1; 	 /* 18..18  bit(s) R/W */
  uint32_t   CLK_HSPWM_GATE	:1; 	 /* 19..19  bit(s) R/W */
  uint32_t   CLK_I2SM_GATE	:1; 	 /* 20..20  bit(s) R/W */
  uint32_t   CLK_TSM_GATE	:1; 	 /* 21..21  bit(s) R/W */ 
  uint32_t   	:10; 	 /* 22..31  bit(s) R */                    
} CCR_PERICLKGATE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_PERICLKGATE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_PERICLKGATE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_PERICLKGATE_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_PERICLKGATE()     ((volatile CCR_PERICLKGATE_bit_view_st *)\
(CCR_PERICLKGATE_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_PERICLKGATE()     ((volatile CCR_PERICLKGATE_byte_view_st *)\
(CCR_PERICLKGATE_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_PERICLKGATE()     ((volatile CCR_PERICLKGATE_halfword_view_st *)\
(CCR_PERICLKGATE_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_PERICLKGATE()     ((volatile u32CCR_PERICLKGATE_word_view *)\
(CCR_PERICLKGATE_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_PERICLKGATE_CLK_QSPI0_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_QSPI0_GATE)
#define vSetCCR_PERICLKGATE_CLK_QSPI0_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_QSPI0_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_QSPI1_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_QSPI1_GATE)
#define vSetCCR_PERICLKGATE_CLK_QSPI1_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_QSPI1_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_QSPI2_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_QSPI2_GATE)
#define vSetCCR_PERICLKGATE_CLK_QSPI2_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_QSPI2_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_DMA_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_DMA_GATE)
#define vSetCCR_PERICLKGATE_CLK_DMA_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_DMA_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_PARFL_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_PARFL_GATE)
#define vSetCCR_PERICLKGATE_CLK_PARFL_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_PARFL_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_DAP_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_DAP_GATE)
#define vSetCCR_PERICLKGATE_CLK_DAP_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_DAP_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_GA_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_GA_GATE)
#define vSetCCR_PERICLKGATE_CLK_GA_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_GA_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_PNG_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_PNG_GATE)
#define vSetCCR_PERICLKGATE_CLK_PNG_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_PNG_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_GDC0_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_GDC0_GATE)
#define vSetCCR_PERICLKGATE_CLK_GDC0_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_GDC0_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_GDC1_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_GDC1_GATE)
#define vSetCCR_PERICLKGATE_CLK_GDC1_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_GDC1_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_FG_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_FG_GATE)
#define vSetCCR_PERICLKGATE_CLK_FG_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_FG_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_MLB_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_MLB_GATE)
#define vSetCCR_PERICLKGATE_CLK_MLB_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_MLB_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_SDRAM_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_SDRAM_GATE)
#define vSetCCR_PERICLKGATE_CLK_SDRAM_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_SDRAM_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_SMC_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_SMC_GATE)
#define vSetCCR_PERICLKGATE_CLK_SMC_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_SMC_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_I2S_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_I2S_GATE)
#define vSetCCR_PERICLKGATE_CLK_I2S_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_I2S_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_HSPWM_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_HSPWM_GATE)
#define vSetCCR_PERICLKGATE_CLK_HSPWM_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_HSPWM_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_I2SM_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_I2SM_GATE)
#define vSetCCR_PERICLKGATE_CLK_I2SM_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_I2SM_GATE=(ParValue))
#define biGetCCR_PERICLKGATE_CLK_TSM_GATE() (pst_bitCCR_PERICLKGATE() -> CLK_TSM_GATE)
#define vSetCCR_PERICLKGATE_CLK_TSM_GATE(ParValue)  (pst_bitCCR_PERICLKGATE() -> CLK_TSM_GATE=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_PERICLKGATELL(ParValue) (pst_u8CCR_PERICLKGATE() -> u8LL = (ParValue))
#define u8GetCCR_PERICLKGATELL() (pst_u8CCR_PERICLKGATE() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_PERICLKGATELH(ParValue) (pst_u8CCR_PERICLKGATE() -> u8LH = (ParValue))
#define u8GetCCR_PERICLKGATELH() (pst_u8CCR_PERICLKGATE() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_PERICLKGATEHL(ParValue) (pst_u8CCR_PERICLKGATE() -> u8HL = (ParValue))
#define u8GetCCR_PERICLKGATEHL() (pst_u8CCR_PERICLKGATE() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_PERICLKGATEHH(ParValue) (pst_u8CCR_PERICLKGATE() -> u8HH = (ParValue))
#define u8GetCCR_PERICLKGATEHH() (pst_u8CCR_PERICLKGATE() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_PERICLKGATEL(ParValue) (pst_u16CCR_PERICLKGATE() -> u16L = (ParValue))
#define u16GetCCR_PERICLKGATEL() (pst_u16CCR_PERICLKGATE() -> u16L)
#define vSetCCR_PERICLKGATEH(ParValue) (pst_u16CCR_PERICLKGATE() -> u16H = (ParValue))
#define u16GetCCR_PERICLKGATEH() (pst_u16CCR_PERICLKGATE() -> u16H)
            
/* Word access */
#define vSetCCR_PERICLKGATE(ParValue)  (*pu32CCR_PERICLKGATE() = (ParValue))
#define u32GetCCR_PERICLKGATE()  (*pu32CCR_PERICLKGATE() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_SBCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000028                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_SBCR_REG__       0xC0000028U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   PLLSTBC	:5; 	 /* 0..4  bit(s) R/W */ 
  uint8_t   	:3; 	 /* 5..31  bit(s) R */                    
} CCR_SBCR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8CCR_SBCR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_SBCR()     ((volatile CCR_SBCR_bit_view_st *)\
(CCR_SBCR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8CCR_SBCR()     ((volatile u8CCR_SBCR_byte_view *)\
(CCR_SBCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_SBCR_PLLSTBC() (pst_bitCCR_SBCR() -> PLLSTBC)
#define vSetCCR_SBCR_PLLSTBC(ParValue)  (pst_bitCCR_SBCR() -> PLLSTBC=(ParValue))
            
/* byte access */
#define vSetCCR_SBCR(ParValue) (*pu8CCR_SBCR() = (ParValue))
#define u8GetCCR_SBCR() (*pu8CCR_SBCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_SBSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000002C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_SBSR_REG__       0xC000002CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   OSC10MRDY	:1; 	 /* 0..0  bit(s) R */
  uint8_t   OSC32KRDY	:1; 	 /* 1..1  bit(s) R */
  uint8_t   RC100KRDY	:1; 	 /* 2..2  bit(s) R */
  uint8_t   MPLLRDY	:1; 	 /* 3..3  bit(s) R */
  uint8_t   NMPLLRDY	:1; 	 /* 4..4  bit(s) R */ 
  uint8_t   	:3; 	 /* 5..31  bit(s) R */                    
} CCR_SBSR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8CCR_SBSR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_SBSR()     ((volatile CCR_SBSR_bit_view_st *)\
(CCR_SBSR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8CCR_SBSR()     ((volatile u8CCR_SBSR_byte_view *)\
(CCR_SBSR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCCR_SBSR_OSC10MRDY() (pst_bitCCR_SBSR() -> OSC10MRDY)            
#define biGetCCR_SBSR_OSC32KRDY() (pst_bitCCR_SBSR() -> OSC32KRDY)            
#define biGetCCR_SBSR_RC100KRDY() (pst_bitCCR_SBSR() -> RC100KRDY)            
#define biGetCCR_SBSR_MPLLRDY() (pst_bitCCR_SBSR() -> MPLLRDY)            
#define biGetCCR_SBSR_NMPLLRDY() (pst_bitCCR_SBSR() -> NMPLLRDY)
            
/* byte access */

#define u8GetCCR_SBSR() (*pu8CCR_SBSR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_RSTCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000030                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_RSTCR_REG__       0xC0000030U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SW_FULL_RST	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   	:8; 	 /* 8..15  bit(s) R */
  uint32_t   DBGRST	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   SW_PART_RST	:8; 	 /* 24..31  bit(s) R/W */                    
} CCR_RSTCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_RSTCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_RSTCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_RSTCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_RSTCR()     ((volatile CCR_RSTCR_bit_view_st *)\
(CCR_RSTCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_RSTCR()     ((volatile CCR_RSTCR_byte_view_st *)\
(CCR_RSTCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_RSTCR()     ((volatile CCR_RSTCR_halfword_view_st *)\
(CCR_RSTCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_RSTCR()     ((volatile u32CCR_RSTCR_word_view *)\
(CCR_RSTCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_RSTCR_SW_FULL_RST() (pst_bitCCR_RSTCR() -> SW_FULL_RST)
#define vSetCCR_RSTCR_SW_FULL_RST(ParValue)  (pst_bitCCR_RSTCR() -> SW_FULL_RST=(ParValue))
#define biGetCCR_RSTCR_DBGRST() (pst_bitCCR_RSTCR() -> DBGRST)
#define vSetCCR_RSTCR_DBGRST(ParValue)  (pst_bitCCR_RSTCR() -> DBGRST=(ParValue))
#define biGetCCR_RSTCR_SW_PART_RST() (pst_bitCCR_RSTCR() -> SW_PART_RST)
#define vSetCCR_RSTCR_SW_PART_RST(ParValue)  (pst_bitCCR_RSTCR() -> SW_PART_RST=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_RSTCRLL(ParValue) (pst_u8CCR_RSTCR() -> u8LL = (ParValue))
#define u8GetCCR_RSTCRLL() (pst_u8CCR_RSTCR() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_RSTCRLH(ParValue) (pst_u8CCR_RSTCR() -> u8LH = (ParValue))
#define u8GetCCR_RSTCRLH() (pst_u8CCR_RSTCR() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_RSTCRHL(ParValue) (pst_u8CCR_RSTCR() -> u8HL = (ParValue))
#define u8GetCCR_RSTCRHL() (pst_u8CCR_RSTCR() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_RSTCRHH(ParValue) (pst_u8CCR_RSTCR() -> u8HH = (ParValue))
#define u8GetCCR_RSTCRHH() (pst_u8CCR_RSTCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_RSTCRL(ParValue) (pst_u16CCR_RSTCR() -> u16L = (ParValue))
#define u16GetCCR_RSTCRL() (pst_u16CCR_RSTCR() -> u16L)
#define vSetCCR_RSTCRH(ParValue) (pst_u16CCR_RSTCR() -> u16H = (ParValue))
#define u16GetCCR_RSTCRH() (pst_u16CCR_RSTCR() -> u16H)
            
/* Word access */
#define vSetCCR_RSTCR(ParValue)  (*pu32CCR_RSTCR() = (ParValue))
#define u32GetCCR_RSTCR()  (*pu32CCR_RSTCR() )
                 
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_SCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000003C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_SCR_REG__       0xC000003CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MODECFGR	:7; 	 /* 0..6  bit(s) R/W */
  uint32_t   	:9; 	 /* 7..15  bit(s) R */
  uint32_t   MODETRAN	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} CCR_SCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_SCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_SCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_SCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_SCR()     ((volatile CCR_SCR_bit_view_st *)\
(CCR_SCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_SCR()     ((volatile CCR_SCR_byte_view_st *)\
(CCR_SCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_SCR()     ((volatile CCR_SCR_halfword_view_st *)\
(CCR_SCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_SCR()     ((volatile u32CCR_SCR_word_view *)\
(CCR_SCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_SCR_MODECFGR() (pst_bitCCR_SCR() -> MODECFGR)
#define vSetCCR_SCR_MODECFGR(ParValue)  (pst_bitCCR_SCR() -> MODECFGR=(ParValue))
#define biGetCCR_SCR_MODETRAN() (pst_bitCCR_SCR() -> MODETRAN)
#define vSetCCR_SCR_MODETRAN(ParValue)  (pst_bitCCR_SCR() -> MODETRAN=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_SCRLL(ParValue) (pst_u8CCR_SCR() -> u8LL = (ParValue))
#define u8GetCCR_SCRLL() (pst_u8CCR_SCR() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_SCRLH(ParValue) (pst_u8CCR_SCR() -> u8LH = (ParValue))
#define u8GetCCR_SCRLH() (pst_u8CCR_SCR() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_SCRHL(ParValue) (pst_u8CCR_SCR() -> u8HL = (ParValue))
#define u8GetCCR_SCRHL() (pst_u8CCR_SCR() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_SCRHH(ParValue) (pst_u8CCR_SCR() -> u8HH = (ParValue))
#define u8GetCCR_SCRHH() (pst_u8CCR_SCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_SCRL(ParValue) (pst_u16CCR_SCR() -> u16L = (ParValue))
#define u16GetCCR_SCRL() (pst_u16CCR_SCR() -> u16L)
#define vSetCCR_SCRH(ParValue) (pst_u16CCR_SCR() -> u16H = (ParValue))
#define u16GetCCR_SCRH() (pst_u16CCR_SCR() -> u16H)
            
/* Word access */
#define vSetCCR_SCR(ParValue)  (*pu32CCR_SCR() = (ParValue))
#define u32GetCCR_SCR()  (*pu32CCR_SCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_INTER                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000040                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_INTER_REG__       0xC0000040U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MODEINTEN	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   	:15; 	 /* 1..15  bit(s) R */
  uint32_t   ALARMINT0EN	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   ALARMINT1EN	:1; 	 /* 17..17  bit(s) R/W */ 
  uint32_t   	:14; 	 /* 18..31  bit(s) R */                    
} CCR_INTER_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_INTER_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_INTER_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_INTER_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_INTER()     ((volatile CCR_INTER_bit_view_st *)\
(CCR_INTER_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_INTER()     ((volatile CCR_INTER_byte_view_st *)\
(CCR_INTER_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_INTER()     ((volatile CCR_INTER_halfword_view_st *)\
(CCR_INTER_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_INTER()     ((volatile u32CCR_INTER_word_view *)\
(CCR_INTER_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_INTER_MODEINTEN() (pst_bitCCR_INTER() -> MODEINTEN)
#define vSetCCR_INTER_MODEINTEN(ParValue)  (pst_bitCCR_INTER() -> MODEINTEN=(ParValue))
#define biGetCCR_INTER_ALARMINT0EN() (pst_bitCCR_INTER() -> ALARMINT0EN)
#define vSetCCR_INTER_ALARMINT0EN(ParValue)  (pst_bitCCR_INTER() -> ALARMINT0EN=(ParValue))
#define biGetCCR_INTER_ALARMINT1EN() (pst_bitCCR_INTER() -> ALARMINT1EN)
#define vSetCCR_INTER_ALARMINT1EN(ParValue)  (pst_bitCCR_INTER() -> ALARMINT1EN=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_INTERLL(ParValue) (pst_u8CCR_INTER() -> u8LL = (ParValue))
#define u8GetCCR_INTERLL() (pst_u8CCR_INTER() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_INTERLH(ParValue) (pst_u8CCR_INTER() -> u8LH = (ParValue))
#define u8GetCCR_INTERLH() (pst_u8CCR_INTER() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_INTERHL(ParValue) (pst_u8CCR_INTER() -> u8HL = (ParValue))
#define u8GetCCR_INTERHL() (pst_u8CCR_INTER() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_INTERHH(ParValue) (pst_u8CCR_INTER() -> u8HH = (ParValue))
#define u8GetCCR_INTERHH() (pst_u8CCR_INTER() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_INTERL(ParValue) (pst_u16CCR_INTER() -> u16L = (ParValue))
#define u16GetCCR_INTERL() (pst_u16CCR_INTER() -> u16L)
#define vSetCCR_INTERH(ParValue) (pst_u16CCR_INTER() -> u16H = (ParValue))
#define u16GetCCR_INTERH() (pst_u16CCR_INTER() -> u16H)
            
/* Word access */
#define vSetCCR_INTER(ParValue)  (*pu32CCR_INTER() = (ParValue))
#define u32GetCCR_INTER()  (*pu32CCR_INTER() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_INTSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000044                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_INTSR_REG__       0xC0000044U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MODEINT	:1; 	 /* 0..0  bit(s) R */
  uint32_t   	:15; 	 /* 1..15  bit(s) R */
  uint32_t   ALARMINT0	:1; 	 /* 16..16  bit(s) R */
  uint32_t   ALARMINT1	:1; 	 /* 17..17  bit(s) R */
  uint32_t   	:6; 	 /* 18..23  bit(s) R */
  uint32_t   BKPRAM_ECCINT	:1; 	 /* 24..24  bit(s) R/W0C */
  uint32_t   MM_ECCINT	:1; 	 /* 25..25  bit(s) R/W0C */ 
  uint32_t   	:6; 	 /* 26..31  bit(s) R */                    
} CCR_INTSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_INTSR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_INTSR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_INTSR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_INTSR()     ((volatile CCR_INTSR_bit_view_st *)\
(CCR_INTSR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_INTSR()     ((volatile CCR_INTSR_byte_view_st *)\
(CCR_INTSR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_INTSR()     ((volatile CCR_INTSR_halfword_view_st *)\
(CCR_INTSR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_INTSR()     ((volatile u32CCR_INTSR_word_view *)\
(CCR_INTSR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCCR_INTSR_MODEINT() (pst_bitCCR_INTSR() -> MODEINT)            
#define biGetCCR_INTSR_ALARMINT0() (pst_bitCCR_INTSR() -> ALARMINT0)            
#define biGetCCR_INTSR_ALARMINT1() (pst_bitCCR_INTSR() -> ALARMINT1)
#define biGetCCR_INTSR_BKPRAM_ECCINT() (pst_bitCCR_INTSR() -> BKPRAM_ECCINT)
#define vClrCCR_INTSR_BKPRAM_ECCINT() (pst_bitCCR_INTSR() -> BKPRAM_ECCINT=(0))
#define biGetCCR_INTSR_MM_ECCINT() (pst_bitCCR_INTSR() -> MM_ECCINT)
#define vClrCCR_INTSR_MM_ECCINT() (pst_bitCCR_INTSR() -> MM_ECCINT=(0))
            
/* LL-struct byte access */
#define vSetCCR_INTSRLL(ParValue) (pst_u8CCR_INTSR() -> u8LL = (ParValue))
#define u8GetCCR_INTSRLL() (pst_u8CCR_INTSR() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_INTSRLH(ParValue) (pst_u8CCR_INTSR() -> u8LH = (ParValue))
#define u8GetCCR_INTSRLH() (pst_u8CCR_INTSR() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_INTSRHL(ParValue) (pst_u8CCR_INTSR() -> u8HL = (ParValue))
#define u8GetCCR_INTSRHL() (pst_u8CCR_INTSR() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_INTSRHH(ParValue) (pst_u8CCR_INTSR() -> u8HH = (ParValue))
#define u8GetCCR_INTSRHH() (pst_u8CCR_INTSR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_INTSRL(ParValue) (pst_u16CCR_INTSR() -> u16L = (ParValue))
#define u16GetCCR_INTSRL() (pst_u16CCR_INTSR() -> u16L)
#define vSetCCR_INTSRH(ParValue) (pst_u16CCR_INTSR() -> u16H = (ParValue))
#define u16GetCCR_INTSRH() (pst_u16CCR_INTSR() -> u16H)
            
/* Word access */
#define vSetCCR_INTSR(ParValue)  (*pu32CCR_INTSR() = (ParValue))
#define u32GetCCR_INTSR()  (*pu32CCR_INTSR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_INTCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000048                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_INTCR_REG__       0xC0000048U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MODEINTC	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   	:15; 	 /* 1..15  bit(s) R */
  uint32_t   ALARMINT0C	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   ALARMINT1C	:1; 	 /* 17..17  bit(s) R/W */ 
  uint32_t   	:14; 	 /* 18..31  bit(s) R */                    
} CCR_INTCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_INTCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_INTCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_INTCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_INTCR()     ((volatile CCR_INTCR_bit_view_st *)\
(CCR_INTCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_INTCR()     ((volatile CCR_INTCR_byte_view_st *)\
(CCR_INTCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_INTCR()     ((volatile CCR_INTCR_halfword_view_st *)\
(CCR_INTCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_INTCR()     ((volatile u32CCR_INTCR_word_view *)\
(CCR_INTCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_INTCR_MODEINTC() (pst_bitCCR_INTCR() -> MODEINTC)
#define vSetCCR_INTCR_MODEINTC(ParValue)  (pst_bitCCR_INTCR() -> MODEINTC=(ParValue))
#define biGetCCR_INTCR_ALARMINT0C() (pst_bitCCR_INTCR() -> ALARMINT0C)
#define vSetCCR_INTCR_ALARMINT0C(ParValue)  (pst_bitCCR_INTCR() -> ALARMINT0C=(ParValue))
#define biGetCCR_INTCR_ALARMINT1C() (pst_bitCCR_INTCR() -> ALARMINT1C)
#define vSetCCR_INTCR_ALARMINT1C(ParValue)  (pst_bitCCR_INTCR() -> ALARMINT1C=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_INTCRLL(ParValue) (pst_u8CCR_INTCR() -> u8LL = (ParValue))
#define u8GetCCR_INTCRLL() (pst_u8CCR_INTCR() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_INTCRLH(ParValue) (pst_u8CCR_INTCR() -> u8LH = (ParValue))
#define u8GetCCR_INTCRLH() (pst_u8CCR_INTCR() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_INTCRHL(ParValue) (pst_u8CCR_INTCR() -> u8HL = (ParValue))
#define u8GetCCR_INTCRHL() (pst_u8CCR_INTCR() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_INTCRHH(ParValue) (pst_u8CCR_INTCR() -> u8HH = (ParValue))
#define u8GetCCR_INTCRHH() (pst_u8CCR_INTCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_INTCRL(ParValue) (pst_u16CCR_INTCR() -> u16L = (ParValue))
#define u16GetCCR_INTCRL() (pst_u16CCR_INTCR() -> u16L)
#define vSetCCR_INTCRH(ParValue) (pst_u16CCR_INTCR() -> u16H = (ParValue))
#define u16GetCCR_INTCRH() (pst_u16CCR_INTCR() -> u16H)
            
/* Word access */
#define vSetCCR_INTCR(ParValue)  (*pu32CCR_INTCR() = (ParValue))
#define u32GetCCR_INTCR()  (*pu32CCR_INTCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_SYSDSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000004C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_SYSDSR_REG__       0xC000004CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   MODESTAT	:7; 	 /* 0..6  bit(s) R */ 
  uint8_t   	:1; 	 /* 7..31  bit(s) R */                    
} CCR_SYSDSR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8CCR_SYSDSR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_SYSDSR()     ((volatile CCR_SYSDSR_bit_view_st *)\
(CCR_SYSDSR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8CCR_SYSDSR()     ((volatile u8CCR_SYSDSR_byte_view *)\
(CCR_SYSDSR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCCR_SYSDSR_MODESTAT() (pst_bitCCR_SYSDSR() -> MODESTAT)
            
/* byte access */

#define u8GetCCR_SYSDSR() (*pu8CCR_SYSDSR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_SSCPLL_CTRL0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000050                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_SSCPLL_CTRL0_REG__       0xC0000050U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   SSCPLL_RESET	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   	:3; 	 /* 1..3  bit(s) R */
  uint8_t   	:1; 	 /* 4..4  bit(s) R */
  uint8_t   	:1; 	 /* 5..5  bit(s) R */
  uint8_t   SSCPLL_MODTYPE	:1; 	 /* 6..6  bit(s) R/W */
  uint8_t   	:1; 	 /* 7..7  bit(s) R */                    
} CCR_SSCPLL_CTRL0_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8CCR_SSCPLL_CTRL0_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_SSCPLL_CTRL0()     ((volatile CCR_SSCPLL_CTRL0_bit_view_st *)\
(CCR_SSCPLL_CTRL0_REG__ ))
        
/* Pointer to BYTE  */
#define pu8CCR_SSCPLL_CTRL0()     ((volatile u8CCR_SSCPLL_CTRL0_byte_view *)\
(CCR_SSCPLL_CTRL0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_SSCPLL_CTRL0_SSCPLL_RESET() (pst_bitCCR_SSCPLL_CTRL0() -> SSCPLL_RESET)
#define vSetCCR_SSCPLL_CTRL0_SSCPLL_RESET(ParValue)  (pst_bitCCR_SSCPLL_CTRL0() -> SSCPLL_RESET=(ParValue))
#define biGetCCR_SSCPLL_CTRL0_SSCPLL_MODTYPE() (pst_bitCCR_SSCPLL_CTRL0() -> SSCPLL_MODTYPE)
#define vSetCCR_SSCPLL_CTRL0_SSCPLL_MODTYPE(ParValue)  (pst_bitCCR_SSCPLL_CTRL0() -> SSCPLL_MODTYPE=(ParValue))
            
/* byte access */
#define vSetCCR_SSCPLL_CTRL0(ParValue) (*pu8CCR_SSCPLL_CTRL0() = (ParValue))
#define u8GetCCR_SSCPLL_CTRL0() (*pu8CCR_SSCPLL_CTRL0() )


/****************************************************************************   
*                                                                               
*       REGISTER: CCR_SSCPLL_CTRL2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000058                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_SSCPLL_CTRL2_REG__       0xC0000058U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SSCPLL_FNLEN	:7; 	 /* 0..6  bit(s) R/W */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   	:8; 	 /* 8..15  bit(s) R */ 
  uint32_t   SSCPLL_DSFT	:16; 	 /* 16..31  bit(s) R/W */                    
} CCR_SSCPLL_CTRL2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_SSCPLL_CTRL2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_SSCPLL_CTRL2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_SSCPLL_CTRL2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_SSCPLL_CTRL2()     ((volatile CCR_SSCPLL_CTRL2_bit_view_st *)\
(CCR_SSCPLL_CTRL2_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_SSCPLL_CTRL2()     ((volatile CCR_SSCPLL_CTRL2_byte_view_st *)\
(CCR_SSCPLL_CTRL2_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_SSCPLL_CTRL2()     ((volatile CCR_SSCPLL_CTRL2_halfword_view_st *)\
(CCR_SSCPLL_CTRL2_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_SSCPLL_CTRL2()     ((volatile u32CCR_SSCPLL_CTRL2_word_view *)\
(CCR_SSCPLL_CTRL2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_SSCPLL_CTRL2_SSCPLL_FNLEN() (pst_bitCCR_SSCPLL_CTRL2() -> SSCPLL_FNLEN)
#define vSetCCR_SSCPLL_CTRL2_SSCPLL_FNLEN(ParValue)  (pst_bitCCR_SSCPLL_CTRL2() -> SSCPLL_FNLEN=(ParValue))
#define biGetCCR_SSCPLL_CTRL2_SSCPLL_DSFT() (pst_bitCCR_SSCPLL_CTRL2() -> SSCPLL_DSFT)
#define vSetCCR_SSCPLL_CTRL2_SSCPLL_DSFT(ParValue)  (pst_bitCCR_SSCPLL_CTRL2() -> SSCPLL_DSFT=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_SSCPLL_CTRL2LL(ParValue) (pst_u8CCR_SSCPLL_CTRL2() -> u8LL = (ParValue))
#define u8GetCCR_SSCPLL_CTRL2LL() (pst_u8CCR_SSCPLL_CTRL2() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_SSCPLL_CTRL2LH(ParValue) (pst_u8CCR_SSCPLL_CTRL2() -> u8LH = (ParValue))
#define u8GetCCR_SSCPLL_CTRL2LH() (pst_u8CCR_SSCPLL_CTRL2() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_SSCPLL_CTRL2HL(ParValue) (pst_u8CCR_SSCPLL_CTRL2() -> u8HL = (ParValue))
#define u8GetCCR_SSCPLL_CTRL2HL() (pst_u8CCR_SSCPLL_CTRL2() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_SSCPLL_CTRL2HH(ParValue) (pst_u8CCR_SSCPLL_CTRL2() -> u8HH = (ParValue))
#define u8GetCCR_SSCPLL_CTRL2HH() (pst_u8CCR_SSCPLL_CTRL2() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_SSCPLL_CTRL2L(ParValue) (pst_u16CCR_SSCPLL_CTRL2() -> u16L = (ParValue))
#define u16GetCCR_SSCPLL_CTRL2L() (pst_u16CCR_SSCPLL_CTRL2() -> u16L)
#define vSetCCR_SSCPLL_CTRL2H(ParValue) (pst_u16CCR_SSCPLL_CTRL2() -> u16H = (ParValue))
#define u16GetCCR_SSCPLL_CTRL2H() (pst_u16CCR_SSCPLL_CTRL2() -> u16H)
            
/* Word access */
#define vSetCCR_SSCPLL_CTRL2(ParValue)  (*pu32CCR_SSCPLL_CTRL2() = (ParValue))
#define u32GetCCR_SSCPLL_CTRL2()  (*pu32CCR_SSCPLL_CTRL2() )


/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERIC_REG0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000064                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERIC_REG0_REG__       0xC0000064U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ALMWDT_RST_NMI	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   BEINJB	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   BEPAB	:6; 	 /* 2..7  bit(s) R/W */
  uint32_t   BEPBB	:6; 	 /* 8..13  bit(s) R/W */
  uint32_t   	:2; 	 /* 14..15  bit(s) R */
  uint32_t   QSPIC0_ADDRMODE	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   QSPIC1_ADDRMODE	:1; 	 /* 17..17  bit(s) R/W */ 
  uint32_t   	:14; 	 /* 18..31  bit(s) R */                    
} CCR_GENERIC_REG0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERIC_REG0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERIC_REG0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERIC_REG0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERIC_REG0()     ((volatile CCR_GENERIC_REG0_bit_view_st *)\
(CCR_GENERIC_REG0_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERIC_REG0()     ((volatile CCR_GENERIC_REG0_byte_view_st *)\
(CCR_GENERIC_REG0_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERIC_REG0()     ((volatile CCR_GENERIC_REG0_halfword_view_st *)\
(CCR_GENERIC_REG0_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERIC_REG0()     ((volatile u32CCR_GENERIC_REG0_word_view *)\
(CCR_GENERIC_REG0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_GENERIC_REG0_ALMWDT_RST_NMI() (pst_bitCCR_GENERIC_REG0() -> ALMWDT_RST_NMI)
#define vSetCCR_GENERIC_REG0_ALMWDT_RST_NMI(ParValue)  (pst_bitCCR_GENERIC_REG0() -> ALMWDT_RST_NMI=(ParValue))
#define biGetCCR_GENERIC_REG0_BEINJB() (pst_bitCCR_GENERIC_REG0() -> BEINJB)
#define vSetCCR_GENERIC_REG0_BEINJB(ParValue)  (pst_bitCCR_GENERIC_REG0() -> BEINJB=(ParValue))
#define biGetCCR_GENERIC_REG0_BEPAB() (pst_bitCCR_GENERIC_REG0() -> BEPAB)
#define vSetCCR_GENERIC_REG0_BEPAB(ParValue)  (pst_bitCCR_GENERIC_REG0() -> BEPAB=(ParValue))
#define biGetCCR_GENERIC_REG0_BEPBB() (pst_bitCCR_GENERIC_REG0() -> BEPBB)
#define vSetCCR_GENERIC_REG0_BEPBB(ParValue)  (pst_bitCCR_GENERIC_REG0() -> BEPBB=(ParValue))
#define biGetCCR_GENERIC_REG0_QSPIC0_ADDRMODE() (pst_bitCCR_GENERIC_REG0() -> QSPIC0_ADDRMODE)
#define vSetCCR_GENERIC_REG0_QSPIC0_ADDRMODE(ParValue)  (pst_bitCCR_GENERIC_REG0() -> QSPIC0_ADDRMODE=(ParValue))
#define biGetCCR_GENERIC_REG0_QSPIC1_ADDRMODE() (pst_bitCCR_GENERIC_REG0() -> QSPIC1_ADDRMODE)
#define vSetCCR_GENERIC_REG0_QSPIC1_ADDRMODE(ParValue)  (pst_bitCCR_GENERIC_REG0() -> QSPIC1_ADDRMODE=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_GENERIC_REG0LL(ParValue) (pst_u8CCR_GENERIC_REG0() -> u8LL = (ParValue))
#define u8GetCCR_GENERIC_REG0LL() (pst_u8CCR_GENERIC_REG0() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_GENERIC_REG0LH(ParValue) (pst_u8CCR_GENERIC_REG0() -> u8LH = (ParValue))
#define u8GetCCR_GENERIC_REG0LH() (pst_u8CCR_GENERIC_REG0() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_GENERIC_REG0HL(ParValue) (pst_u8CCR_GENERIC_REG0() -> u8HL = (ParValue))
#define u8GetCCR_GENERIC_REG0HL() (pst_u8CCR_GENERIC_REG0() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_GENERIC_REG0HH(ParValue) (pst_u8CCR_GENERIC_REG0() -> u8HH = (ParValue))
#define u8GetCCR_GENERIC_REG0HH() (pst_u8CCR_GENERIC_REG0() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_GENERIC_REG0L(ParValue) (pst_u16CCR_GENERIC_REG0() -> u16L = (ParValue))
#define u16GetCCR_GENERIC_REG0L() (pst_u16CCR_GENERIC_REG0() -> u16L)
#define vSetCCR_GENERIC_REG0H(ParValue) (pst_u16CCR_GENERIC_REG0() -> u16H = (ParValue))
#define u16GetCCR_GENERIC_REG0H() (pst_u16CCR_GENERIC_REG0() -> u16H)
            
/* Word access */
#define vSetCCR_GENERIC_REG0(ParValue)  (*pu32CCR_GENERIC_REG0() = (ParValue))
#define u32GetCCR_GENERIC_REG0()  (*pu32CCR_GENERIC_REG0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERIC_REG1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000068                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERIC_REG1_REG__       0xC0000068U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CANMODE	:4; 	 /* 0..3  bit(s) R/W */
  uint32_t   ECCM	:2; 	 /* 4..5  bit(s) R/W */
  uint32_t   	:2; 	 /* 6..7  bit(s) R */
  uint32_t   TBIO0_DIR	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   TBIO1_DIR	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   TBIO2_DIR	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   TBIO3_DIR	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   TBIO6_DIR	:1; 	 /* 12..12  bit(s) R/W */
  uint32_t   TBIO7_DIR	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   TBIO8_DIR	:1; 	 /* 14..14  bit(s) R/W */
  uint32_t   TBIO9_SEL	:1; 	 /* 15..15  bit(s) R/W */
  uint32_t   TBIN4_SEL	:4; 	 /* 16..19  bit(s) R/W */
  uint32_t   TBIN5_SEL	:4; 	 /* 20..23  bit(s) R/W */
  uint32_t   DISP0ON	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   DISP1ON	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   PNLON	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   S0EXTS1	:1; 	 /* 27..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} CCR_GENERIC_REG1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERIC_REG1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERIC_REG1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERIC_REG1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERIC_REG1()     ((volatile CCR_GENERIC_REG1_bit_view_st *)\
(CCR_GENERIC_REG1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERIC_REG1()     ((volatile CCR_GENERIC_REG1_byte_view_st *)\
(CCR_GENERIC_REG1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERIC_REG1()     ((volatile CCR_GENERIC_REG1_halfword_view_st *)\
(CCR_GENERIC_REG1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERIC_REG1()     ((volatile u32CCR_GENERIC_REG1_word_view *)\
(CCR_GENERIC_REG1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_GENERIC_REG1_CANMODE() (pst_bitCCR_GENERIC_REG1() -> CANMODE)
#define vSetCCR_GENERIC_REG1_CANMODE(ParValue)  (pst_bitCCR_GENERIC_REG1() -> CANMODE=(ParValue))
#define biGetCCR_GENERIC_REG1_ECCM() (pst_bitCCR_GENERIC_REG1() -> ECCM)
#define vSetCCR_GENERIC_REG1_ECCM(ParValue)  (pst_bitCCR_GENERIC_REG1() -> ECCM=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIO0_DIR() (pst_bitCCR_GENERIC_REG1() -> TBIO0_DIR)
#define vSetCCR_GENERIC_REG1_TBIO0_DIR(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIO0_DIR=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIO1_DIR() (pst_bitCCR_GENERIC_REG1() -> TBIO1_DIR)
#define vSetCCR_GENERIC_REG1_TBIO1_DIR(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIO1_DIR=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIO2_DIR() (pst_bitCCR_GENERIC_REG1() -> TBIO2_DIR)
#define vSetCCR_GENERIC_REG1_TBIO2_DIR(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIO2_DIR=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIO3_DIR() (pst_bitCCR_GENERIC_REG1() -> TBIO3_DIR)
#define vSetCCR_GENERIC_REG1_TBIO3_DIR(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIO3_DIR=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIO6_DIR() (pst_bitCCR_GENERIC_REG1() -> TBIO6_DIR)
#define vSetCCR_GENERIC_REG1_TBIO6_DIR(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIO6_DIR=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIO7_DIR() (pst_bitCCR_GENERIC_REG1() -> TBIO7_DIR)
#define vSetCCR_GENERIC_REG1_TBIO7_DIR(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIO7_DIR=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIO8_DIR() (pst_bitCCR_GENERIC_REG1() -> TBIO8_DIR)
#define vSetCCR_GENERIC_REG1_TBIO8_DIR(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIO8_DIR=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIO9_SEL() (pst_bitCCR_GENERIC_REG1() -> TBIO9_SEL)
#define vSetCCR_GENERIC_REG1_TBIO9_SEL(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIO9_SEL=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIN4_SEL() (pst_bitCCR_GENERIC_REG1() -> TBIN4_SEL)
#define vSetCCR_GENERIC_REG1_TBIN4_SEL(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIN4_SEL=(ParValue))
#define biGetCCR_GENERIC_REG1_TBIN5_SEL() (pst_bitCCR_GENERIC_REG1() -> TBIN5_SEL)
#define vSetCCR_GENERIC_REG1_TBIN5_SEL(ParValue)  (pst_bitCCR_GENERIC_REG1() -> TBIN5_SEL=(ParValue))
#define biGetCCR_GENERIC_REG1_DISP0ON() (pst_bitCCR_GENERIC_REG1() -> DISP0ON)
#define vSetCCR_GENERIC_REG1_DISP0ON(ParValue)  (pst_bitCCR_GENERIC_REG1() -> DISP0ON=(ParValue))
#define biGetCCR_GENERIC_REG1_DISP1ON() (pst_bitCCR_GENERIC_REG1() -> DISP1ON)
#define vSetCCR_GENERIC_REG1_DISP1ON(ParValue)  (pst_bitCCR_GENERIC_REG1() -> DISP1ON=(ParValue))
#define biGetCCR_GENERIC_REG1_PNLON() (pst_bitCCR_GENERIC_REG1() -> PNLON)
#define vSetCCR_GENERIC_REG1_PNLON(ParValue)  (pst_bitCCR_GENERIC_REG1() -> PNLON=(ParValue))
#define biGetCCR_GENERIC_REG1_S0EXTS1() (pst_bitCCR_GENERIC_REG1() -> S0EXTS1)
#define vSetCCR_GENERIC_REG1_S0EXTS1(ParValue)  (pst_bitCCR_GENERIC_REG1() -> S0EXTS1=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_GENERIC_REG1LL(ParValue) (pst_u8CCR_GENERIC_REG1() -> u8LL = (ParValue))
#define u8GetCCR_GENERIC_REG1LL() (pst_u8CCR_GENERIC_REG1() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_GENERIC_REG1LH(ParValue) (pst_u8CCR_GENERIC_REG1() -> u8LH = (ParValue))
#define u8GetCCR_GENERIC_REG1LH() (pst_u8CCR_GENERIC_REG1() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_GENERIC_REG1HL(ParValue) (pst_u8CCR_GENERIC_REG1() -> u8HL = (ParValue))
#define u8GetCCR_GENERIC_REG1HL() (pst_u8CCR_GENERIC_REG1() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_GENERIC_REG1HH(ParValue) (pst_u8CCR_GENERIC_REG1() -> u8HH = (ParValue))
#define u8GetCCR_GENERIC_REG1HH() (pst_u8CCR_GENERIC_REG1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_GENERIC_REG1L(ParValue) (pst_u16CCR_GENERIC_REG1() -> u16L = (ParValue))
#define u16GetCCR_GENERIC_REG1L() (pst_u16CCR_GENERIC_REG1() -> u16L)
#define vSetCCR_GENERIC_REG1H(ParValue) (pst_u16CCR_GENERIC_REG1() -> u16H = (ParValue))
#define u16GetCCR_GENERIC_REG1H() (pst_u16CCR_GENERIC_REG1() -> u16H)
            
/* Word access */
#define vSetCCR_GENERIC_REG1(ParValue)  (*pu32CCR_GENERIC_REG1() = (ParValue))
#define u32GetCCR_GENERIC_REG1()  (*pu32CCR_GENERIC_REG1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERIC_REG2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000006C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERIC_REG2_REG__       0xC000006CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ADDR_MASK0_0	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   ADDR_MATCH0_0	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   ADDR_MASK0_1	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   ADDR_MATCH0_1	:8; 	 /* 24..31  bit(s) R/W */                    
} CCR_GENERIC_REG2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERIC_REG2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERIC_REG2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERIC_REG2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERIC_REG2()     ((volatile CCR_GENERIC_REG2_bit_view_st *)\
(CCR_GENERIC_REG2_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERIC_REG2()     ((volatile CCR_GENERIC_REG2_byte_view_st *)\
(CCR_GENERIC_REG2_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERIC_REG2()     ((volatile CCR_GENERIC_REG2_halfword_view_st *)\
(CCR_GENERIC_REG2_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERIC_REG2()     ((volatile u32CCR_GENERIC_REG2_word_view *)\
(CCR_GENERIC_REG2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_GENERIC_REG2_ADDR_MASK0_0() (pst_bitCCR_GENERIC_REG2() -> ADDR_MASK0_0)
#define vSetCCR_GENERIC_REG2_ADDR_MASK0_0(ParValue)  (pst_bitCCR_GENERIC_REG2() -> ADDR_MASK0_0=(ParValue))
#define biGetCCR_GENERIC_REG2_ADDR_MATCH0_0() (pst_bitCCR_GENERIC_REG2() -> ADDR_MATCH0_0)
#define vSetCCR_GENERIC_REG2_ADDR_MATCH0_0(ParValue)  (pst_bitCCR_GENERIC_REG2() -> ADDR_MATCH0_0=(ParValue))
#define biGetCCR_GENERIC_REG2_ADDR_MASK0_1() (pst_bitCCR_GENERIC_REG2() -> ADDR_MASK0_1)
#define vSetCCR_GENERIC_REG2_ADDR_MASK0_1(ParValue)  (pst_bitCCR_GENERIC_REG2() -> ADDR_MASK0_1=(ParValue))
#define biGetCCR_GENERIC_REG2_ADDR_MATCH0_1() (pst_bitCCR_GENERIC_REG2() -> ADDR_MATCH0_1)
#define vSetCCR_GENERIC_REG2_ADDR_MATCH0_1(ParValue)  (pst_bitCCR_GENERIC_REG2() -> ADDR_MATCH0_1=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_GENERIC_REG2LL(ParValue) (pst_u8CCR_GENERIC_REG2() -> u8LL = (ParValue))
#define u8GetCCR_GENERIC_REG2LL() (pst_u8CCR_GENERIC_REG2() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_GENERIC_REG2LH(ParValue) (pst_u8CCR_GENERIC_REG2() -> u8LH = (ParValue))
#define u8GetCCR_GENERIC_REG2LH() (pst_u8CCR_GENERIC_REG2() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_GENERIC_REG2HL(ParValue) (pst_u8CCR_GENERIC_REG2() -> u8HL = (ParValue))
#define u8GetCCR_GENERIC_REG2HL() (pst_u8CCR_GENERIC_REG2() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_GENERIC_REG2HH(ParValue) (pst_u8CCR_GENERIC_REG2() -> u8HH = (ParValue))
#define u8GetCCR_GENERIC_REG2HH() (pst_u8CCR_GENERIC_REG2() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_GENERIC_REG2L(ParValue) (pst_u16CCR_GENERIC_REG2() -> u16L = (ParValue))
#define u16GetCCR_GENERIC_REG2L() (pst_u16CCR_GENERIC_REG2() -> u16L)
#define vSetCCR_GENERIC_REG2H(ParValue) (pst_u16CCR_GENERIC_REG2() -> u16H = (ParValue))
#define u16GetCCR_GENERIC_REG2H() (pst_u16CCR_GENERIC_REG2() -> u16H)
            
/* Word access */
#define vSetCCR_GENERIC_REG2(ParValue)  (*pu32CCR_GENERIC_REG2() = (ParValue))
#define u32GetCCR_GENERIC_REG2()  (*pu32CCR_GENERIC_REG2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERIC_REG3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000070                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERIC_REG3_REG__       0xC0000070U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ADDR_MASK1_0	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   ADDR_MATCH1_0	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   ADDR_MASK1_1	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   ADDR_MATCH1_1	:8; 	 /* 24..31  bit(s) R/W */                    
} CCR_GENERIC_REG3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERIC_REG3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERIC_REG3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERIC_REG3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERIC_REG3()     ((volatile CCR_GENERIC_REG3_bit_view_st *)\
(CCR_GENERIC_REG3_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERIC_REG3()     ((volatile CCR_GENERIC_REG3_byte_view_st *)\
(CCR_GENERIC_REG3_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERIC_REG3()     ((volatile CCR_GENERIC_REG3_halfword_view_st *)\
(CCR_GENERIC_REG3_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERIC_REG3()     ((volatile u32CCR_GENERIC_REG3_word_view *)\
(CCR_GENERIC_REG3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_GENERIC_REG3_ADDR_MASK1_0() (pst_bitCCR_GENERIC_REG3() -> ADDR_MASK1_0)
#define vSetCCR_GENERIC_REG3_ADDR_MASK1_0(ParValue)  (pst_bitCCR_GENERIC_REG3() -> ADDR_MASK1_0=(ParValue))
#define biGetCCR_GENERIC_REG3_ADDR_MATCH1_0() (pst_bitCCR_GENERIC_REG3() -> ADDR_MATCH1_0)
#define vSetCCR_GENERIC_REG3_ADDR_MATCH1_0(ParValue)  (pst_bitCCR_GENERIC_REG3() -> ADDR_MATCH1_0=(ParValue))
#define biGetCCR_GENERIC_REG3_ADDR_MASK1_1() (pst_bitCCR_GENERIC_REG3() -> ADDR_MASK1_1)
#define vSetCCR_GENERIC_REG3_ADDR_MASK1_1(ParValue)  (pst_bitCCR_GENERIC_REG3() -> ADDR_MASK1_1=(ParValue))
#define biGetCCR_GENERIC_REG3_ADDR_MATCH1_1() (pst_bitCCR_GENERIC_REG3() -> ADDR_MATCH1_1)
#define vSetCCR_GENERIC_REG3_ADDR_MATCH1_1(ParValue)  (pst_bitCCR_GENERIC_REG3() -> ADDR_MATCH1_1=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_GENERIC_REG3LL(ParValue) (pst_u8CCR_GENERIC_REG3() -> u8LL = (ParValue))
#define u8GetCCR_GENERIC_REG3LL() (pst_u8CCR_GENERIC_REG3() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_GENERIC_REG3LH(ParValue) (pst_u8CCR_GENERIC_REG3() -> u8LH = (ParValue))
#define u8GetCCR_GENERIC_REG3LH() (pst_u8CCR_GENERIC_REG3() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_GENERIC_REG3HL(ParValue) (pst_u8CCR_GENERIC_REG3() -> u8HL = (ParValue))
#define u8GetCCR_GENERIC_REG3HL() (pst_u8CCR_GENERIC_REG3() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_GENERIC_REG3HH(ParValue) (pst_u8CCR_GENERIC_REG3() -> u8HH = (ParValue))
#define u8GetCCR_GENERIC_REG3HH() (pst_u8CCR_GENERIC_REG3() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_GENERIC_REG3L(ParValue) (pst_u16CCR_GENERIC_REG3() -> u16L = (ParValue))
#define u16GetCCR_GENERIC_REG3L() (pst_u16CCR_GENERIC_REG3() -> u16L)
#define vSetCCR_GENERIC_REG3H(ParValue) (pst_u16CCR_GENERIC_REG3() -> u16H = (ParValue))
#define u16GetCCR_GENERIC_REG3H() (pst_u16CCR_GENERIC_REG3() -> u16H)
            
/* Word access */
#define vSetCCR_GENERIC_REG3(ParValue)  (*pu32CCR_GENERIC_REG3() = (ParValue))
#define u32GetCCR_GENERIC_REG3()  (*pu32CCR_GENERIC_REG3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERIC_REG4                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000074                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERIC_REG4_REG__       0xC0000074U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   BEINJ0	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   BEPA0	:4; 	 /* 1..4  bit(s) R/W */
  uint32_t   BEPB0	:4; 	 /* 5..8  bit(s) R/W */
  uint32_t   BEBSEL0	:3; 	 /* 9..11  bit(s) R/W */
  uint32_t   	:4; 	 /* 12..15  bit(s) R */
  uint32_t   BEINJ1	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   BEPA1	:4; 	 /* 17..20  bit(s) R/W */
  uint32_t   BEPB1	:4; 	 /* 21..24  bit(s) R/W */
  uint32_t   BEBSEL1	:3; 	 /* 25..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} CCR_GENERIC_REG4_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERIC_REG4_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERIC_REG4_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERIC_REG4_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERIC_REG4()     ((volatile CCR_GENERIC_REG4_bit_view_st *)\
(CCR_GENERIC_REG4_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERIC_REG4()     ((volatile CCR_GENERIC_REG4_byte_view_st *)\
(CCR_GENERIC_REG4_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERIC_REG4()     ((volatile CCR_GENERIC_REG4_halfword_view_st *)\
(CCR_GENERIC_REG4_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERIC_REG4()     ((volatile u32CCR_GENERIC_REG4_word_view *)\
(CCR_GENERIC_REG4_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_GENERIC_REG4_BEINJ0() (pst_bitCCR_GENERIC_REG4() -> BEINJ0)
#define vSetCCR_GENERIC_REG4_BEINJ0(ParValue)  (pst_bitCCR_GENERIC_REG4() -> BEINJ0=(ParValue))
#define biGetCCR_GENERIC_REG4_BEPA0() (pst_bitCCR_GENERIC_REG4() -> BEPA0)
#define vSetCCR_GENERIC_REG4_BEPA0(ParValue)  (pst_bitCCR_GENERIC_REG4() -> BEPA0=(ParValue))
#define biGetCCR_GENERIC_REG4_BEPB0() (pst_bitCCR_GENERIC_REG4() -> BEPB0)
#define vSetCCR_GENERIC_REG4_BEPB0(ParValue)  (pst_bitCCR_GENERIC_REG4() -> BEPB0=(ParValue))
#define biGetCCR_GENERIC_REG4_BEBSEL0() (pst_bitCCR_GENERIC_REG4() -> BEBSEL0)
#define vSetCCR_GENERIC_REG4_BEBSEL0(ParValue)  (pst_bitCCR_GENERIC_REG4() -> BEBSEL0=(ParValue))
#define biGetCCR_GENERIC_REG4_BEINJ1() (pst_bitCCR_GENERIC_REG4() -> BEINJ1)
#define vSetCCR_GENERIC_REG4_BEINJ1(ParValue)  (pst_bitCCR_GENERIC_REG4() -> BEINJ1=(ParValue))
#define biGetCCR_GENERIC_REG4_BEPA1() (pst_bitCCR_GENERIC_REG4() -> BEPA1)
#define vSetCCR_GENERIC_REG4_BEPA1(ParValue)  (pst_bitCCR_GENERIC_REG4() -> BEPA1=(ParValue))
#define biGetCCR_GENERIC_REG4_BEPB1() (pst_bitCCR_GENERIC_REG4() -> BEPB1)
#define vSetCCR_GENERIC_REG4_BEPB1(ParValue)  (pst_bitCCR_GENERIC_REG4() -> BEPB1=(ParValue))
#define biGetCCR_GENERIC_REG4_BEBSEL1() (pst_bitCCR_GENERIC_REG4() -> BEBSEL1)
#define vSetCCR_GENERIC_REG4_BEBSEL1(ParValue)  (pst_bitCCR_GENERIC_REG4() -> BEBSEL1=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_GENERIC_REG4LL(ParValue) (pst_u8CCR_GENERIC_REG4() -> u8LL = (ParValue))
#define u8GetCCR_GENERIC_REG4LL() (pst_u8CCR_GENERIC_REG4() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_GENERIC_REG4LH(ParValue) (pst_u8CCR_GENERIC_REG4() -> u8LH = (ParValue))
#define u8GetCCR_GENERIC_REG4LH() (pst_u8CCR_GENERIC_REG4() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_GENERIC_REG4HL(ParValue) (pst_u8CCR_GENERIC_REG4() -> u8HL = (ParValue))
#define u8GetCCR_GENERIC_REG4HL() (pst_u8CCR_GENERIC_REG4() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_GENERIC_REG4HH(ParValue) (pst_u8CCR_GENERIC_REG4() -> u8HH = (ParValue))
#define u8GetCCR_GENERIC_REG4HH() (pst_u8CCR_GENERIC_REG4() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_GENERIC_REG4L(ParValue) (pst_u16CCR_GENERIC_REG4() -> u16L = (ParValue))
#define u16GetCCR_GENERIC_REG4L() (pst_u16CCR_GENERIC_REG4() -> u16L)
#define vSetCCR_GENERIC_REG4H(ParValue) (pst_u16CCR_GENERIC_REG4() -> u16H = (ParValue))
#define u16GetCCR_GENERIC_REG4H() (pst_u16CCR_GENERIC_REG4() -> u16H)
            
/* Word access */
#define vSetCCR_GENERIC_REG4(ParValue)  (*pu32CCR_GENERIC_REG4() = (ParValue))
#define u32GetCCR_GENERIC_REG4()  (*pu32CCR_GENERIC_REG4() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERIC_REG5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000078                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERIC_REG5_REG__       0xC0000078U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   BEINJ2	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   BEPA2	:4; 	 /* 1..4  bit(s) R/W */
  uint32_t   BEPB2	:4; 	 /* 5..8  bit(s) R/W */
  uint32_t   BEBSEL2	:3; 	 /* 9..11  bit(s) R/W */
  uint32_t   	:4; 	 /* 12..15  bit(s) R */
  uint32_t   BEINJ3	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   BEPA3	:4; 	 /* 17..20  bit(s) R/W */
  uint32_t   BEPB3	:4; 	 /* 21..24  bit(s) R/W */
  uint32_t   BEBSEL3	:3; 	 /* 25..27  bit(s) R/W */ 
  uint32_t   	:4; 	 /* 28..31  bit(s) R */                    
} CCR_GENERIC_REG5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERIC_REG5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERIC_REG5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERIC_REG5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERIC_REG5()     ((volatile CCR_GENERIC_REG5_bit_view_st *)\
(CCR_GENERIC_REG5_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERIC_REG5()     ((volatile CCR_GENERIC_REG5_byte_view_st *)\
(CCR_GENERIC_REG5_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERIC_REG5()     ((volatile CCR_GENERIC_REG5_halfword_view_st *)\
(CCR_GENERIC_REG5_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERIC_REG5()     ((volatile u32CCR_GENERIC_REG5_word_view *)\
(CCR_GENERIC_REG5_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_GENERIC_REG5_BEINJ2() (pst_bitCCR_GENERIC_REG5() -> BEINJ2)
#define vSetCCR_GENERIC_REG5_BEINJ2(ParValue)  (pst_bitCCR_GENERIC_REG5() -> BEINJ2=(ParValue))
#define biGetCCR_GENERIC_REG5_BEPA2() (pst_bitCCR_GENERIC_REG5() -> BEPA2)
#define vSetCCR_GENERIC_REG5_BEPA2(ParValue)  (pst_bitCCR_GENERIC_REG5() -> BEPA2=(ParValue))
#define biGetCCR_GENERIC_REG5_BEPB2() (pst_bitCCR_GENERIC_REG5() -> BEPB2)
#define vSetCCR_GENERIC_REG5_BEPB2(ParValue)  (pst_bitCCR_GENERIC_REG5() -> BEPB2=(ParValue))
#define biGetCCR_GENERIC_REG5_BEBSEL2() (pst_bitCCR_GENERIC_REG5() -> BEBSEL2)
#define vSetCCR_GENERIC_REG5_BEBSEL2(ParValue)  (pst_bitCCR_GENERIC_REG5() -> BEBSEL2=(ParValue))
#define biGetCCR_GENERIC_REG5_BEINJ3() (pst_bitCCR_GENERIC_REG5() -> BEINJ3)
#define vSetCCR_GENERIC_REG5_BEINJ3(ParValue)  (pst_bitCCR_GENERIC_REG5() -> BEINJ3=(ParValue))
#define biGetCCR_GENERIC_REG5_BEPA3() (pst_bitCCR_GENERIC_REG5() -> BEPA3)
#define vSetCCR_GENERIC_REG5_BEPA3(ParValue)  (pst_bitCCR_GENERIC_REG5() -> BEPA3=(ParValue))
#define biGetCCR_GENERIC_REG5_BEPB3() (pst_bitCCR_GENERIC_REG5() -> BEPB3)
#define vSetCCR_GENERIC_REG5_BEPB3(ParValue)  (pst_bitCCR_GENERIC_REG5() -> BEPB3=(ParValue))
#define biGetCCR_GENERIC_REG5_BEBSEL3() (pst_bitCCR_GENERIC_REG5() -> BEBSEL3)
#define vSetCCR_GENERIC_REG5_BEBSEL3(ParValue)  (pst_bitCCR_GENERIC_REG5() -> BEBSEL3=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_GENERIC_REG5LL(ParValue) (pst_u8CCR_GENERIC_REG5() -> u8LL = (ParValue))
#define u8GetCCR_GENERIC_REG5LL() (pst_u8CCR_GENERIC_REG5() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_GENERIC_REG5LH(ParValue) (pst_u8CCR_GENERIC_REG5() -> u8LH = (ParValue))
#define u8GetCCR_GENERIC_REG5LH() (pst_u8CCR_GENERIC_REG5() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_GENERIC_REG5HL(ParValue) (pst_u8CCR_GENERIC_REG5() -> u8HL = (ParValue))
#define u8GetCCR_GENERIC_REG5HL() (pst_u8CCR_GENERIC_REG5() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_GENERIC_REG5HH(ParValue) (pst_u8CCR_GENERIC_REG5() -> u8HH = (ParValue))
#define u8GetCCR_GENERIC_REG5HH() (pst_u8CCR_GENERIC_REG5() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_GENERIC_REG5L(ParValue) (pst_u16CCR_GENERIC_REG5() -> u16L = (ParValue))
#define u16GetCCR_GENERIC_REG5L() (pst_u16CCR_GENERIC_REG5() -> u16L)
#define vSetCCR_GENERIC_REG5H(ParValue) (pst_u16CCR_GENERIC_REG5() -> u16H = (ParValue))
#define u16GetCCR_GENERIC_REG5H() (pst_u16CCR_GENERIC_REG5() -> u16H)
            
/* Word access */
#define vSetCCR_GENERIC_REG5(ParValue)  (*pu32CCR_GENERIC_REG5() = (ParValue))
#define u32GetCCR_GENERIC_REG5()  (*pu32CCR_GENERIC_REG5() )


/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERICAC_REG0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000084                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERICAC_REG0_REG__       0xC0000084U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WDT_ALMCLR	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   ECCECLRB	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   ECCWCLRB	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   ECCECLRS	:4; 	 /* 8..11  bit(s) R/W */
  uint32_t   ECCWCLRS	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   CPXTSYN_PM	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   CPXTSYN_PNM	:1; 	 /* 17..17  bit(s) R/W */ 
  uint32_t   	:14; 	 /* 18..31  bit(s) R */                    
} CCR_GENERICAC_REG0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERICAC_REG0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERICAC_REG0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERICAC_REG0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERICAC_REG0()     ((volatile CCR_GENERICAC_REG0_bit_view_st *)\
(CCR_GENERICAC_REG0_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERICAC_REG0()     ((volatile CCR_GENERICAC_REG0_byte_view_st *)\
(CCR_GENERICAC_REG0_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERICAC_REG0()     ((volatile CCR_GENERICAC_REG0_halfword_view_st *)\
(CCR_GENERICAC_REG0_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERICAC_REG0()     ((volatile u32CCR_GENERICAC_REG0_word_view *)\
(CCR_GENERICAC_REG0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCCR_GENERICAC_REG0_WDT_ALMCLR() (pst_bitCCR_GENERICAC_REG0() -> WDT_ALMCLR)
#define vSetCCR_GENERICAC_REG0_WDT_ALMCLR(ParValue)  (pst_bitCCR_GENERICAC_REG0() -> WDT_ALMCLR=(ParValue))
#define biGetCCR_GENERICAC_REG0_ECCECLRB() (pst_bitCCR_GENERICAC_REG0() -> ECCECLRB)
#define vSetCCR_GENERICAC_REG0_ECCECLRB(ParValue)  (pst_bitCCR_GENERICAC_REG0() -> ECCECLRB=(ParValue))
#define biGetCCR_GENERICAC_REG0_ECCWCLRB() (pst_bitCCR_GENERICAC_REG0() -> ECCWCLRB)
#define vSetCCR_GENERICAC_REG0_ECCWCLRB(ParValue)  (pst_bitCCR_GENERICAC_REG0() -> ECCWCLRB=(ParValue))
#define biGetCCR_GENERICAC_REG0_ECCECLRS() (pst_bitCCR_GENERICAC_REG0() -> ECCECLRS)
#define vSetCCR_GENERICAC_REG0_ECCECLRS(ParValue)  (pst_bitCCR_GENERICAC_REG0() -> ECCECLRS=(ParValue))
#define biGetCCR_GENERICAC_REG0_ECCWCLRS() (pst_bitCCR_GENERICAC_REG0() -> ECCWCLRS)
#define vSetCCR_GENERICAC_REG0_ECCWCLRS(ParValue)  (pst_bitCCR_GENERICAC_REG0() -> ECCWCLRS=(ParValue))
#define biGetCCR_GENERICAC_REG0_CPXTSYN_PM() (pst_bitCCR_GENERICAC_REG0() -> CPXTSYN_PM)
#define vSetCCR_GENERICAC_REG0_CPXTSYN_PM(ParValue)  (pst_bitCCR_GENERICAC_REG0() -> CPXTSYN_PM=(ParValue))
#define biGetCCR_GENERICAC_REG0_CPXTSYN_PNM() (pst_bitCCR_GENERICAC_REG0() -> CPXTSYN_PNM)
#define vSetCCR_GENERICAC_REG0_CPXTSYN_PNM(ParValue)  (pst_bitCCR_GENERICAC_REG0() -> CPXTSYN_PNM=(ParValue))
            
/* LL-struct byte access */
#define vSetCCR_GENERICAC_REG0LL(ParValue) (pst_u8CCR_GENERICAC_REG0() -> u8LL = (ParValue))
#define u8GetCCR_GENERICAC_REG0LL() (pst_u8CCR_GENERICAC_REG0() -> u8LL)
/* LH-struct byte access */
#define vSetCCR_GENERICAC_REG0LH(ParValue) (pst_u8CCR_GENERICAC_REG0() -> u8LH = (ParValue))
#define u8GetCCR_GENERICAC_REG0LH() (pst_u8CCR_GENERICAC_REG0() -> u8LH)
/* HL-struct byte access */
#define vSetCCR_GENERICAC_REG0HL(ParValue) (pst_u8CCR_GENERICAC_REG0() -> u8HL = (ParValue))
#define u8GetCCR_GENERICAC_REG0HL() (pst_u8CCR_GENERICAC_REG0() -> u8HL)
/* HH-struct byte access */
#define vSetCCR_GENERICAC_REG0HH(ParValue) (pst_u8CCR_GENERICAC_REG0() -> u8HH = (ParValue))
#define u8GetCCR_GENERICAC_REG0HH() (pst_u8CCR_GENERICAC_REG0() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCR_GENERICAC_REG0L(ParValue) (pst_u16CCR_GENERICAC_REG0() -> u16L = (ParValue))
#define u16GetCCR_GENERICAC_REG0L() (pst_u16CCR_GENERICAC_REG0() -> u16L)
#define vSetCCR_GENERICAC_REG0H(ParValue) (pst_u16CCR_GENERICAC_REG0() -> u16H = (ParValue))
#define u16GetCCR_GENERICAC_REG0H() (pst_u16CCR_GENERICAC_REG0() -> u16H)
            
/* Word access */
#define vSetCCR_GENERICAC_REG0(ParValue)  (*pu32CCR_GENERICAC_REG0() = (ParValue))
#define u32GetCCR_GENERICAC_REG0()  (*pu32CCR_GENERICAC_REG0() )
             
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERICSTAT_REG0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000008C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERICSTAT_REG0_REG__       0xC000008CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WDT_ALARM	:1; 	 /* 0..0  bit(s) R */
  uint32_t   ECCERRB	:1; 	 /* 1..1  bit(s) R */
  uint32_t   ECCWRNB	:1; 	 /* 2..2  bit(s) R */
  uint32_t   BEPOSB	:7; 	 /* 3..9  bit(s) R */
  uint32_t   BERESB	:1; 	 /* 10..10  bit(s) R */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   CR4DBGNOPWRDWN	:1; 	 /* 16..16  bit(s) R */ 
  uint32_t   	:15; 	 /* 17..31  bit(s) R */                    
} CCR_GENERICSTAT_REG0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERICSTAT_REG0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERICSTAT_REG0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERICSTAT_REG0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERICSTAT_REG0()     ((volatile CCR_GENERICSTAT_REG0_bit_view_st *)\
(CCR_GENERICSTAT_REG0_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERICSTAT_REG0()     ((volatile CCR_GENERICSTAT_REG0_byte_view_st *)\
(CCR_GENERICSTAT_REG0_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERICSTAT_REG0()     ((volatile CCR_GENERICSTAT_REG0_halfword_view_st *)\
(CCR_GENERICSTAT_REG0_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERICSTAT_REG0()     ((volatile u32CCR_GENERICSTAT_REG0_word_view *)\
(CCR_GENERICSTAT_REG0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCCR_GENERICSTAT_REG0_WDT_ALARM() (pst_bitCCR_GENERICSTAT_REG0() -> WDT_ALARM)            
#define biGetCCR_GENERICSTAT_REG0_ECCERRB() (pst_bitCCR_GENERICSTAT_REG0() -> ECCERRB)            
#define biGetCCR_GENERICSTAT_REG0_ECCWRNB() (pst_bitCCR_GENERICSTAT_REG0() -> ECCWRNB)            
#define biGetCCR_GENERICSTAT_REG0_BEPOSB() (pst_bitCCR_GENERICSTAT_REG0() -> BEPOSB)            
#define biGetCCR_GENERICSTAT_REG0_BERESB() (pst_bitCCR_GENERICSTAT_REG0() -> BERESB)            
#define biGetCCR_GENERICSTAT_REG0_CR4DBGNOPWRDWN() (pst_bitCCR_GENERICSTAT_REG0() -> CR4DBGNOPWRDWN)
            
/* LL-struct byte access */

#define u8GetCCR_GENERICSTAT_REG0LL() (pst_u8CCR_GENERICSTAT_REG0() -> u8LL)
/* LH-struct byte access */

#define u8GetCCR_GENERICSTAT_REG0LH() (pst_u8CCR_GENERICSTAT_REG0() -> u8LH)
/* HL-struct byte access */

#define u8GetCCR_GENERICSTAT_REG0HL() (pst_u8CCR_GENERICSTAT_REG0() -> u8HL)
/* HH-struct byte access */

#define u8GetCCR_GENERICSTAT_REG0HH() (pst_u8CCR_GENERICSTAT_REG0() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetCCR_GENERICSTAT_REG0L() (pst_u16CCR_GENERICSTAT_REG0() -> u16L)

#define u16GetCCR_GENERICSTAT_REG0H() (pst_u16CCR_GENERICSTAT_REG0() -> u16H)
            
/* Word access */

#define u32GetCCR_GENERICSTAT_REG0()  (*pu32CCR_GENERICSTAT_REG0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCR_GENERICSTAT_REG1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000090                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCR_GENERICSTAT_REG1_REG__       0xC0000090U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ECCERRS	:4; 	 /* 0..3  bit(s) R */
  uint32_t   ECCWRNS	:4; 	 /* 4..7  bit(s) R */
  uint32_t   BEPOSS	:20; 	 /* 8..27  bit(s) R */ 
  uint32_t   BERESS	:4; 	 /* 28..31  bit(s) R */                    
} CCR_GENERICSTAT_REG1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCR_GENERICSTAT_REG1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCR_GENERICSTAT_REG1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCR_GENERICSTAT_REG1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCR_GENERICSTAT_REG1()     ((volatile CCR_GENERICSTAT_REG1_bit_view_st *)\
(CCR_GENERICSTAT_REG1_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCR_GENERICSTAT_REG1()     ((volatile CCR_GENERICSTAT_REG1_byte_view_st *)\
(CCR_GENERICSTAT_REG1_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCR_GENERICSTAT_REG1()     ((volatile CCR_GENERICSTAT_REG1_halfword_view_st *)\
(CCR_GENERICSTAT_REG1_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CCR_GENERICSTAT_REG1()     ((volatile u32CCR_GENERICSTAT_REG1_word_view *)\
(CCR_GENERICSTAT_REG1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCCR_GENERICSTAT_REG1_ECCERRS() (pst_bitCCR_GENERICSTAT_REG1() -> ECCERRS)            
#define biGetCCR_GENERICSTAT_REG1_ECCWRNS() (pst_bitCCR_GENERICSTAT_REG1() -> ECCWRNS)            
#define biGetCCR_GENERICSTAT_REG1_BEPOSS() (pst_bitCCR_GENERICSTAT_REG1() -> BEPOSS)            
#define biGetCCR_GENERICSTAT_REG1_BERESS() (pst_bitCCR_GENERICSTAT_REG1() -> BERESS)
            
/* LL-struct byte access */

#define u8GetCCR_GENERICSTAT_REG1LL() (pst_u8CCR_GENERICSTAT_REG1() -> u8LL)
/* LH-struct byte access */

#define u8GetCCR_GENERICSTAT_REG1LH() (pst_u8CCR_GENERICSTAT_REG1() -> u8LH)
/* HL-struct byte access */

#define u8GetCCR_GENERICSTAT_REG1HL() (pst_u8CCR_GENERICSTAT_REG1() -> u8HL)
/* HH-struct byte access */

#define u8GetCCR_GENERICSTAT_REG1HH() (pst_u8CCR_GENERICSTAT_REG1() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetCCR_GENERICSTAT_REG1L() (pst_u16CCR_GENERICSTAT_REG1() -> u16L)

#define u16GetCCR_GENERICSTAT_REG1H() (pst_u16CCR_GENERICSTAT_REG1() -> u16H)
            
/* Word access */

#define u32GetCCR_GENERICSTAT_REG1()  (*pu32CCR_GENERICSTAT_REG1() )
                 
    
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
** |
** |     Requested Rules:
** |         Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types
** |                         Used for bit definitons generated by converter tool
** |         Rule 17.4 [R] : No pointer arithmetic other than array indexing:
** |                         This is necessary to have access to macros generated by converter tool
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/

#endif /* SysCon_PDSIO_H */ 
    
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

