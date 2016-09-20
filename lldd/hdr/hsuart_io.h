
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : HSUART 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:55:36.218+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.12 $ 
/  Excel Sheet ver.             : vv1.7
/  Excel Sheet date             : 2013-Jun-21
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : HSUART low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : HSUART
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.12 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef HSUARTIO_H
#define HSUARTIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */ 

/*********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1835  /* Rule 11.4 [A] : No casting between different pointer to object */
  #pragma ghs nowarning 230   /* Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types */
#endif
/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_UART_IO_H_REVISION     "$Revision: 1.12 $"
#define LLDD_UART_IO_H_TAG          "$Name: LLDD_1_6 $"
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SILCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0404000                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SILCR_REG__       (0xC0404000U)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   UMODE	:2; 	 /* 0..1  bit(s) R/W */
  uint16_t   USBL	:1; 	 /* 2..2  bit(s) R/W */
  uint16_t   UPEN	:1; 	 /* 3..3  bit(s) R/W */
  uint16_t   UEPS	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   RSRVD5	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   RSRVD6	:2; 	 /* 6..7  bit(s) R/W */
  uint16_t   LSBF	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   RSRVD9	:3; 	 /* 9..11  bit(s) R/W */
  uint16_t   RSRVD12	:1; 	 /* 12..12  bit(s) R/W */
  uint16_t   RSRVD13	:1; 	 /* 13..13  bit(s) R/W */
  uint16_t   TWUB	:1; 	 /* 14..14  bit(s) R/W */
  uint16_t   RWUB	:1; 	 /* 15..15  bit(s) R/W */                    
} SILCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SILCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SILCR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSILCR(ctrlr)     ((volatile SILCR_bit_view_st *)\
(SILCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SILCR(ctrlr)     ((volatile SILCR_byte_view_st *)\
(SILCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SILCR(ctrlr)     ((volatile u16SILCR_halfword_view *)\
(SILCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSILCR_UMODE(ctrlr) (pst_bitSILCR(ctrlr) -> UMODE)
#define vSetSILCR_UMODE(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> UMODE=(ParValue))
#define biGetSILCR_USBL(ctrlr) (pst_bitSILCR(ctrlr) -> USBL)
#define vSetSILCR_USBL(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> USBL=(ParValue))
#define biGetSILCR_UPEN(ctrlr) (pst_bitSILCR(ctrlr) -> UPEN)
#define vSetSILCR_UPEN(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> UPEN=(ParValue))
#define biGetSILCR_UEPS(ctrlr) (pst_bitSILCR(ctrlr) -> UEPS)
#define vSetSILCR_UEPS(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> UEPS=(ParValue))
#define biGetSILCR_RSRVD5(ctrlr) (pst_bitSILCR(ctrlr) -> RSRVD5)
#define vSetSILCR_RSRVD5(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> RSRVD5=(ParValue))
#define biGetSILCR_RSRVD6(ctrlr) (pst_bitSILCR(ctrlr) -> RSRVD6)
#define vSetSILCR_RSRVD6(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> RSRVD6=(ParValue))
#define biGetSILCR_LSBF(ctrlr) (pst_bitSILCR(ctrlr) -> LSBF)
#define vSetSILCR_LSBF(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> LSBF=(ParValue))
#define biGetSILCR_RSRVD9(ctrlr) (pst_bitSILCR(ctrlr) -> RSRVD9)
#define vSetSILCR_RSRVD9(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> RSRVD9=(ParValue))
#define biGetSILCR_RSRVD12(ctrlr) (pst_bitSILCR(ctrlr) -> RSRVD12)
#define vSetSILCR_RSRVD12(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> RSRVD12=(ParValue))
#define biGetSILCR_RSRVD13(ctrlr) (pst_bitSILCR(ctrlr) -> RSRVD13)
#define vSetSILCR_RSRVD13(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> RSRVD13=(ParValue))
#define biGetSILCR_TWUB(ctrlr) (pst_bitSILCR(ctrlr) -> TWUB)
#define vSetSILCR_TWUB(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> TWUB=(ParValue))
#define biGetSILCR_RWUB(ctrlr) (pst_bitSILCR(ctrlr) -> RWUB)
#define vSetSILCR_RWUB(ctrlr,ParValue)  (pst_bitSILCR(ctrlr) -> RWUB=(ParValue))
            
/* L-struct byte access */
#define vSetSILCRL(ctrlr,ParValue) (pst_u8SILCR(ctrlr) -> u8L = (ParValue))
#define u8GetSILCRL(ctrlr) (pst_u8SILCR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSILCRH(ctrlr,ParValue) (pst_u8SILCR(ctrlr) -> u8H = (ParValue))
#define u8GetSILCRH(ctrlr) (pst_u8SILCR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSILCR(ctrlr,ParValue) (*pu16SILCR(ctrlr)  = (ParValue))
#define u16GetSILCR(ctrlr) (*pu16SILCR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIDICR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0404004                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIDICR_REG__       (0xC0404004U)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   SIUB	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   SIAS	:1; 	 /* 1..1  bit(s) R/W */
  uint16_t   SITR	:1; 	 /* 2..2  bit(s) R/W */
  uint16_t   SIBRK	:1; 	 /* 3..3  bit(s) R/W */
  uint16_t   SICTS	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   SIOE	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   RXTOUT_EN	:1; 	 /* 6..6  bit(s) R/W */
  uint16_t   	:2; 	 /* 7..8  bit(s) R */
  uint16_t   CTSAC	:2; 	 /* 9..10  bit(s) R/W */
  uint16_t   SPIR	:1; 	 /* 11..11  bit(s) R/W */
  uint16_t   RIR	:1; 	 /* 12..12  bit(s) R/W */
  uint16_t   TIR	:1; 	 /* 13..13  bit(s) R/W */
  uint16_t   RSRVD14	:2; 	 /* 14..15  bit(s) R/W */                    
} SIDICR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SIDICR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SIDICR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIDICR(ctrlr)     ((volatile SIDICR_bit_view_st *)\
(SIDICR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SIDICR(ctrlr)     ((volatile SIDICR_byte_view_st *)\
(SIDICR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SIDICR(ctrlr)     ((volatile u16SIDICR_halfword_view *)\
(SIDICR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSIDICR_SIUB(ctrlr) (pst_bitSIDICR(ctrlr) -> SIUB)
#define vSetSIDICR_SIUB(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> SIUB=(ParValue))
#define biGetSIDICR_SIAS(ctrlr) (pst_bitSIDICR(ctrlr) -> SIAS)
#define vSetSIDICR_SIAS(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> SIAS=(ParValue))
#define biGetSIDICR_SITR(ctrlr) (pst_bitSIDICR(ctrlr) -> SITR)
#define vSetSIDICR_SITR(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> SITR=(ParValue))
#define biGetSIDICR_SIBRK(ctrlr) (pst_bitSIDICR(ctrlr) -> SIBRK)
#define vSetSIDICR_SIBRK(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> SIBRK=(ParValue))
#define biGetSIDICR_SICTS(ctrlr) (pst_bitSIDICR(ctrlr) -> SICTS)
#define vSetSIDICR_SICTS(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> SICTS=(ParValue))
#define biGetSIDICR_SIOE(ctrlr) (pst_bitSIDICR(ctrlr) -> SIOE)
#define vSetSIDICR_SIOE(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> SIOE=(ParValue))
#define biGetSIDICR_RXTOUT_EN(ctrlr) (pst_bitSIDICR(ctrlr) -> RXTOUT_EN)
#define vSetSIDICR_RXTOUT_EN(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> RXTOUT_EN=(ParValue))
#define biGetSIDICR_CTSAC(ctrlr) (pst_bitSIDICR(ctrlr) -> CTSAC)
#define vSetSIDICR_CTSAC(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> CTSAC=(ParValue))
#define biGetSIDICR_SPIR(ctrlr) (pst_bitSIDICR(ctrlr) -> SPIR)
#define vSetSIDICR_SPIR(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> SPIR=(ParValue))
#define biGetSIDICR_RIR(ctrlr) (pst_bitSIDICR(ctrlr) -> RIR)
#define vSetSIDICR_RIR(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> RIR=(ParValue))
#define biGetSIDICR_TIR(ctrlr) (pst_bitSIDICR(ctrlr) -> TIR)
#define vSetSIDICR_TIR(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> TIR=(ParValue))
#define biGetSIDICR_RSRVD14(ctrlr) (pst_bitSIDICR(ctrlr) -> RSRVD14)
#define vSetSIDICR_RSRVD14(ctrlr,ParValue)  (pst_bitSIDICR(ctrlr) -> RSRVD14=(ParValue))
            
/* L-struct byte access */
#define vSetSIDICRL(ctrlr,ParValue) (pst_u8SIDICR(ctrlr) -> u8L = (ParValue))
#define u8GetSIDICRL(ctrlr) (pst_u8SIDICR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSIDICRH(ctrlr,ParValue) (pst_u8SIDICR(ctrlr) -> u8H = (ParValue))
#define u8GetSIDICRH(ctrlr) (pst_u8SIDICR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSIDICR(ctrlr,ParValue) (*pu16SIDICR(ctrlr)  = (ParValue))
#define u16GetSIDICR(ctrlr) (*pu16SIDICR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIDISR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0404008                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIDISR_REG__       (0xC0404008U)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   RFDN	:5; 	 /* 0..4  bit(s) R */
  uint16_t   	:1; 	 /* 5..5  bit(s) R */
  uint16_t   STIS	:1; 	 /* 6..6  bit(s) R/W0C */
  uint16_t   RDIS	:1; 	 /* 7..7  bit(s) R/W0C */
  uint16_t   TDIS	:1; 	 /* 8..8  bit(s) R/W0C */
  uint16_t   TOUT	:1; 	 /* 9..9  bit(s) R/W0C */
  uint16_t   ERI	:1; 	 /* 10..10  bit(s) R/W0C */
  uint16_t   RSRVD11	:1; 	 /* 11..11  bit(s) R */
  uint16_t   UPER	:1; 	 /* 12..12  bit(s) R */
  uint16_t   UFER	:1; 	 /* 13..13  bit(s) R */
  uint16_t   UVALID	:1; 	 /* 14..14  bit(s) R */
  uint16_t   UBRK	:1; 	 /* 15..15  bit(s) R */                    
} SIDISR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SIDISR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SIDISR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIDISR(ctrlr)     ((volatile SIDISR_bit_view_st *)\
(SIDISR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SIDISR(ctrlr)     ((volatile SIDISR_byte_view_st *)\
(SIDISR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SIDISR(ctrlr)     ((volatile u16SIDISR_halfword_view *)\
(SIDISR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSIDISR_RFDN(ctrlr) (pst_bitSIDISR(ctrlr) -> RFDN)
#define biGetSIDISR_STIS(ctrlr) (pst_bitSIDISR(ctrlr) -> STIS)
#define vClrSIDISR_STIS(ctrlr) (pst_bitSIDISR(ctrlr) -> STIS=(0))
#define biGetSIDISR_RDIS(ctrlr) (pst_bitSIDISR(ctrlr) -> RDIS)
#define vClrSIDISR_RDIS(ctrlr) (pst_bitSIDISR(ctrlr) -> RDIS=(0))
#define biGetSIDISR_TDIS(ctrlr) (pst_bitSIDISR(ctrlr) -> TDIS)
#define vClrSIDISR_TDIS(ctrlr) (pst_bitSIDISR(ctrlr) -> TDIS=(0))
#define biGetSIDISR_TOUT(ctrlr) (pst_bitSIDISR(ctrlr) -> TOUT)
#define vClrSIDISR_TOUT(ctrlr) (pst_bitSIDISR(ctrlr) -> TOUT=(0))
#define biGetSIDISR_ERI(ctrlr) (pst_bitSIDISR(ctrlr) -> ERI)
#define vClrSIDISR_ERI(ctrlr) (pst_bitSIDISR(ctrlr) -> ERI=(0))            
#define biGetSIDISR_RSRVD11(ctrlr) (pst_bitSIDISR(ctrlr) -> RSRVD11)            
#define biGetSIDISR_UPER(ctrlr) (pst_bitSIDISR(ctrlr) -> UPER)            
#define biGetSIDISR_UFER(ctrlr) (pst_bitSIDISR(ctrlr) -> UFER)            
#define biGetSIDISR_UVALID(ctrlr) (pst_bitSIDISR(ctrlr) -> UVALID)            
#define biGetSIDISR_UBRK(ctrlr) (pst_bitSIDISR(ctrlr) -> UBRK)
            
/* L-struct byte access */
#define vSetSIDISRL(ctrlr,ParValue) (pst_u8SIDISR(ctrlr) -> u8L = (ParValue))
#define u8GetSIDISRL(ctrlr) (pst_u8SIDISR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSIDISRH(ctrlr,ParValue) (pst_u8SIDISR(ctrlr) -> u8H = (ParValue))
#define u8GetSIDISRH(ctrlr) (pst_u8SIDISR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSIDISR(ctrlr,ParValue) (*pu16SIDISR(ctrlr)  = (ParValue))
#define u16GetSIDISR(ctrlr) (*pu16SIDISR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SISCISR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC040400C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SISCISR_REG__       (0xC040400CU)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   UBRKD	:1; 	 /* 0..0  bit(s) R/W0C */
  uint8_t   TXALS	:1; 	 /* 1..1  bit(s) R */
  uint8_t   TRDY	:1; 	 /* 2..2  bit(s) R */
  uint8_t   RBRKD	:1; 	 /* 3..3  bit(s) R */
  uint8_t   CTSS	:1; 	 /* 4..4  bit(s) R */
  uint8_t   OERS	:1; 	 /* 5..5  bit(s) R/C */ 
  uint8_t   	:2; 	 /* 6..31  bit(s) R */                    
} SISCISR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SISCISR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSISCISR(ctrlr)     ((volatile SISCISR_bit_view_st *)\
(SISCISR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8SISCISR(ctrlr)     ((volatile u8SISCISR_byte_view *)\
(SISCISR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSISCISR_UBRKD(ctrlr) (pst_bitSISCISR(ctrlr) -> UBRKD)
#define vClrSISCISR_UBRKD(ctrlr) (pst_bitSISCISR(ctrlr) -> UBRKD=(0))            
#define biGetSISCISR_TXALS(ctrlr) (pst_bitSISCISR(ctrlr) -> TXALS)            
#define biGetSISCISR_TRDY(ctrlr) (pst_bitSISCISR(ctrlr) -> TRDY)            
#define biGetSISCISR_RBRKD(ctrlr) (pst_bitSISCISR(ctrlr) -> RBRKD)            
#define biGetSISCISR_CTSS(ctrlr) (pst_bitSISCISR(ctrlr) -> CTSS)
#define biGetSISCISR_OERS(ctrlr) (pst_bitSISCISR(ctrlr) -> OERS)
#define vSetSISCISR_OERS(ctrlr) (pst_bitSISCISR(ctrlr) -> OERS=(0))
            
/* byte access */
#define vSetSISCISR(ctrlr,ParValue) (*pu8SISCISR(ctrlr) = (ParValue))
#define u8GetSISCISR(ctrlr) (*pu8SISCISR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIFCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0404010                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIFCR_REG__       (0xC0404010U)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   FRSTEW	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   RFRST	:1; 	 /* 1..1  bit(s) R/W */
  uint16_t   TFRST	:1; 	 /* 2..2  bit(s) R/W */
  uint16_t   TDIL	:4; 	 /* 3..6  bit(s) R/W */
  uint16_t   RDIL	:4; 	 /* 7..10  bit(s) R/W */
  uint16_t   	:2; 	 /* 11..12  bit(s) R */
  uint16_t   RSTST	:1; 	 /* 13..13  bit(s) R */
  uint16_t   	:1; 	 /* 14..14  bit(s) R */
  uint16_t   SWRST	:1; 	 /* 15..15  bit(s) W */                    
} SIFCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SIFCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SIFCR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIFCR(ctrlr)     ((volatile SIFCR_bit_view_st *)\
(SIFCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SIFCR(ctrlr)     ((volatile SIFCR_byte_view_st *)\
(SIFCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SIFCR(ctrlr)     ((volatile u16SIFCR_halfword_view *)\
(SIFCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSIFCR_FRSTEW(ctrlr) (pst_bitSIFCR(ctrlr) -> FRSTEW)
#define vSetSIFCR_FRSTEW(ctrlr,ParValue)  (pst_bitSIFCR(ctrlr) -> FRSTEW=(ParValue))
#define biGetSIFCR_RFRST(ctrlr) (pst_bitSIFCR(ctrlr) -> RFRST)
#define vSetSIFCR_RFRST(ctrlr,ParValue)  (pst_bitSIFCR(ctrlr) -> RFRST=(ParValue))
#define biGetSIFCR_TFRST(ctrlr) (pst_bitSIFCR(ctrlr) -> TFRST)
#define vSetSIFCR_TFRST(ctrlr,ParValue)  (pst_bitSIFCR(ctrlr) -> TFRST=(ParValue))
#define biGetSIFCR_TDIL(ctrlr) (pst_bitSIFCR(ctrlr) -> TDIL)
#define vSetSIFCR_TDIL(ctrlr,ParValue)  (pst_bitSIFCR(ctrlr) -> TDIL=(ParValue))
#define biGetSIFCR_RDIL(ctrlr) (pst_bitSIFCR(ctrlr) -> RDIL)
#define vSetSIFCR_RDIL(ctrlr,ParValue)  (pst_bitSIFCR(ctrlr) -> RDIL=(ParValue))            
#define biGetSIFCR_RSTST(ctrlr) (pst_bitSIFCR(ctrlr) -> RSTST) 
#define vSetSIFCR_SWRST(ctrlr,ParValue) (pst_bitSIFCR(ctrlr) -> SWRST=(ParValue))
            
/* L-struct byte access */
#define vSetSIFCRL(ctrlr,ParValue) (pst_u8SIFCR(ctrlr) -> u8L = (ParValue))
#define u8GetSIFCRL(ctrlr) (pst_u8SIFCR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSIFCRH(ctrlr,ParValue) (pst_u8SIFCR(ctrlr) -> u8H = (ParValue))
#define u8GetSIFCRH(ctrlr) (pst_u8SIFCR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSIFCR(ctrlr,ParValue) (*pu16SIFCR(ctrlr)  = (ParValue))
#define u16GetSIFCR(ctrlr) (*pu16SIFCR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIFLCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0404014                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIFLCR_REG__       (0xC0404014U)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   TBRK	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   RTSTL	:4; 	 /* 1..4  bit(s) R/W */
  uint16_t   	:2; 	 /* 5..6  bit(s) R */
  uint16_t   TSDR	:1; 	 /* 7..7  bit(s) R/W */
  uint16_t   RSDR	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   RTSSC	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   	:1; 	 /* 10..10  bit(s) R */
  uint16_t   TRS	:1; 	 /* 11..11  bit(s) R/W */
  uint16_t   RCS	:1; 	 /* 12..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..31  bit(s) R */                    
} SIFLCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SIFLCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SIFLCR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIFLCR(ctrlr)     ((volatile SIFLCR_bit_view_st *)\
(SIFLCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SIFLCR(ctrlr)     ((volatile SIFLCR_byte_view_st *)\
(SIFLCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SIFLCR(ctrlr)     ((volatile u16SIFLCR_halfword_view *)\
(SIFLCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSIFLCR_TBRK(ctrlr) (pst_bitSIFLCR(ctrlr) -> TBRK)
#define vSetSIFLCR_TBRK(ctrlr,ParValue)  (pst_bitSIFLCR(ctrlr) -> TBRK=(ParValue))
#define biGetSIFLCR_RTSTL(ctrlr) (pst_bitSIFLCR(ctrlr) -> RTSTL)
#define vSetSIFLCR_RTSTL(ctrlr,ParValue)  (pst_bitSIFLCR(ctrlr) -> RTSTL=(ParValue))
#define biGetSIFLCR_TSDR(ctrlr) (pst_bitSIFLCR(ctrlr) -> TSDR)
#define vSetSIFLCR_TSDR(ctrlr,ParValue)  (pst_bitSIFLCR(ctrlr) -> TSDR=(ParValue))
#define biGetSIFLCR_RSDR(ctrlr) (pst_bitSIFLCR(ctrlr) -> RSDR)
#define vSetSIFLCR_RSDR(ctrlr,ParValue)  (pst_bitSIFLCR(ctrlr) -> RSDR=(ParValue))
#define biGetSIFLCR_RTSSC(ctrlr) (pst_bitSIFLCR(ctrlr) -> RTSSC)
#define vSetSIFLCR_RTSSC(ctrlr,ParValue)  (pst_bitSIFLCR(ctrlr) -> RTSSC=(ParValue))
#define biGetSIFLCR_TRS(ctrlr) (pst_bitSIFLCR(ctrlr) -> TRS)
#define vSetSIFLCR_TRS(ctrlr,ParValue)  (pst_bitSIFLCR(ctrlr) -> TRS=(ParValue))
#define biGetSIFLCR_RCS(ctrlr) (pst_bitSIFLCR(ctrlr) -> RCS)
#define vSetSIFLCR_RCS(ctrlr,ParValue)  (pst_bitSIFLCR(ctrlr) -> RCS=(ParValue))
            
/* L-struct byte access */
#define vSetSIFLCRL(ctrlr,ParValue) (pst_u8SIFLCR(ctrlr) -> u8L = (ParValue))
#define u8GetSIFLCRL(ctrlr) (pst_u8SIFLCR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSIFLCRH(ctrlr,ParValue) (pst_u8SIFLCR(ctrlr) -> u8H = (ParValue))
#define u8GetSIFLCRH(ctrlr) (pst_u8SIFLCR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSIFLCR(ctrlr,ParValue) (*pu16SIFLCR(ctrlr)  = (ParValue))
#define u16GetSIFLCR(ctrlr) (*pu16SIFLCR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIBGR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0404018                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIBGR_REG__       (0xC0404018U)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   BRD	:8; 	 /* 0..7  bit(s) R/W */
  uint16_t   BCLK	:3; 	 /* 8..10  bit(s) R/W */ 
  uint16_t   	:5; 	 /* 11..31  bit(s) R */                    
} SIBGR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SIBGR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SIBGR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIBGR(ctrlr)     ((volatile SIBGR_bit_view_st *)\
(SIBGR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SIBGR(ctrlr)     ((volatile SIBGR_byte_view_st *)\
(SIBGR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SIBGR(ctrlr)     ((volatile u16SIBGR_halfword_view *)\
(SIBGR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSIBGR_BRD(ctrlr) (pst_bitSIBGR(ctrlr) -> BRD)
#define vSetSIBGR_BRD(ctrlr,ParValue)  (pst_bitSIBGR(ctrlr) -> BRD=(ParValue))
#define biGetSIBGR_BCLK(ctrlr) (pst_bitSIBGR(ctrlr) -> BCLK)
#define vSetSIBGR_BCLK(ctrlr,ParValue)  (pst_bitSIBGR(ctrlr) -> BCLK=(ParValue))
            
/* L-struct byte access */
#define vSetSIBGRL(ctrlr,ParValue) (pst_u8SIBGR(ctrlr) -> u8L = (ParValue))
#define u8GetSIBGRL(ctrlr) (pst_u8SIBGR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSIBGRH(ctrlr,ParValue) (pst_u8SIBGR(ctrlr) -> u8H = (ParValue))
#define u8GetSIBGRH(ctrlr) (pst_u8SIBGR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSIBGR(ctrlr,ParValue) (*pu16SIBGR(ctrlr)  = (ParValue))
#define u16GetSIBGR(ctrlr) (*pu16SIBGR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SITFIFO                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC040401C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SITFIFO_REG__       (0xC040401CU)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   TXD	:8; 	 /* 0..7  bit(s) W */                    
} SITFIFO_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SITFIFO_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSITFIFO(ctrlr)     ((volatile SITFIFO_bit_view_st *)\
(SITFIFO_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8SITFIFO(ctrlr)     ((volatile u8SITFIFO_byte_view *)\
(SITFIFO_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetSITFIFO_TXD(ctrlr,ParValue) (pst_bitSITFIFO(ctrlr) -> TXD=(ParValue))
            
/* byte access */
#define vSetSITFIFO(ctrlr,ParValue) (*pu8SITFIFO(ctrlr) = (ParValue))
#define u8GetSITFIFO(ctrlr) (*pu8SITFIFO(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SIRFIFO                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0404020                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SIRFIFO_REG__       (0xC0404020U)
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   RXD	:8; 	 /* 0..7  bit(s) R */                    
} SIRFIFO_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SIRFIFO_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSIRFIFO(ctrlr)     ((volatile SIRFIFO_bit_view_st *)\
(SIRFIFO_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8SIRFIFO(ctrlr)     ((volatile u8SIRFIFO_byte_view *)\
(SIRFIFO_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSIRFIFO_RXD(ctrlr) (pst_bitSIRFIFO(ctrlr) -> RXD)
            
/* byte access */

#define u8GetSIRFIFO(ctrlr) (*pu8SIRFIFO(ctrlr) )

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
** |         Rule 11.4 [A] : No casting between different pointer to object
** |
** |     Requested Rules:
** |         Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types
** |                         Used for bit definitons generated by converter tool
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/
/****************************************************************************/


#endif /* HSUARTIO_H */ 
    
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

