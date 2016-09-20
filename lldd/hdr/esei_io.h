
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : ESEI 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:53:46.122+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.11 $ 
/  Excel Sheet ver.             : vv1.1
/  Excel Sheet date             : 2013-Jun-21
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : ESEI low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : ESEI
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.11 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef X_ESEIIO_H   /* for MISRA 2004 check ESEIIO_H not possible */
#define X_ESEIIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 230    /* Rule 6.4 [R] : nonstandard type for a bit field */
  #pragma ghs nowarning 1840   /* Rule 5.7 [A] : identifier reused from declaration of entity-kind "entity" */
#endif

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_ESEI_IO_H_REVISION     "$Revision: 1.11 $"
#define LLDD_ESEI_IO_H_TAG          "$Name: LLDD_1_6 $"
     
/****************************************************************************
*                          CHANNEL SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
typedef enum tag_esei_ch_def_e
{
    ESEI_0__ = 0x0,                       /* Channel 0 */
    ESEI_1__ = 0x1000                     /* Channel 1 */
} esei_ch_def_e; 

/****************************************************************************   
*                                                                               
*       REGISTER: SEMCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322000                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SEMCR_REG__       0xC0322000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   BCLR	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   SESTP	:1; 	 /* 1..1  bit(s) R/W */
  uint8_t   DLOOP	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   	:3; 	 /* 3..5  bit(s) R */
  uint8_t   OPMODE	:2; 	 /* 6..7  bit(s) R/W */                    
} SEMCR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SEMCR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSEMCR(ctrlr)     ((volatile SEMCR_bit_view_st *)\
(SEMCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8SEMCR(ctrlr)     ((volatile u8SEMCR_byte_view *)\
(SEMCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSEMCR_BCLR(ctrlr) (pst_bitSEMCR(ctrlr) -> BCLR)
#define vSetSEMCR_BCLR(ctrlr,ParValue)  (pst_bitSEMCR(ctrlr) -> BCLR=(ParValue))
#define biGetSEMCR_SESTP(ctrlr) (pst_bitSEMCR(ctrlr) -> SESTP)
#define vSetSEMCR_SESTP(ctrlr,ParValue)  (pst_bitSEMCR(ctrlr) -> SESTP=(ParValue))
#define biGetSEMCR_DLOOP(ctrlr) (pst_bitSEMCR(ctrlr) -> DLOOP)
#define vSetSEMCR_DLOOP(ctrlr,ParValue)  (pst_bitSEMCR(ctrlr) -> DLOOP=(ParValue))
#define biGetSEMCR_OPMODE(ctrlr) (pst_bitSEMCR(ctrlr) -> OPMODE)
#define vSetSEMCR_OPMODE(ctrlr,ParValue)  (pst_bitSEMCR(ctrlr) -> OPMODE=(ParValue))
            
/* byte access */
#define vSetSEMCR(ctrlr,ParValue) (*pu8SEMCR(ctrlr) = (ParValue))
#define u8GetSEMCR(ctrlr) (*pu8SEMCR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SECR0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322004                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SECR0_REG__       0xC0322004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   SPOL	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   SPHA	:1; 	 /* 1..1  bit(s) R/W */
  uint16_t   SBOS	:1; 	 /* 2..2  bit(s) R/W */
  uint16_t   MSTR	:1; 	 /* 3..3  bit(s) R/W */
  uint16_t   IFSPSE	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   SSIVAL	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   	:2; 	 /* 6..7  bit(s) R */
  uint16_t   STFIE	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   SUEIE	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   SOEIE	:1; 	 /* 10..10  bit(s) R/W */
  uint16_t   SILIE	:1; 	 /* 11..11  bit(s) R/W */ 
  uint16_t   	:4; 	 /* 12..31  bit(s) R */                    
} SECR0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SECR0_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SECR0_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSECR0(ctrlr)     ((volatile SECR0_bit_view_st *)\
(SECR0_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SECR0(ctrlr)     ((volatile SECR0_byte_view_st *)\
(SECR0_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SECR0(ctrlr)     ((volatile u16SECR0_halfword_view *)\
(SECR0_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSECR0_SPOL(ctrlr) (pst_bitSECR0(ctrlr) -> SPOL)
#define vSetSECR0_SPOL(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> SPOL=(ParValue))
#define biGetSECR0_SPHA(ctrlr) (pst_bitSECR0(ctrlr) -> SPHA)
#define vSetSECR0_SPHA(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> SPHA=(ParValue))
#define biGetSECR0_SBOS(ctrlr) (pst_bitSECR0(ctrlr) -> SBOS)
#define vSetSECR0_SBOS(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> SBOS=(ParValue))
#define biGetSECR0_MSTR(ctrlr) (pst_bitSECR0(ctrlr) -> MSTR)
#define vSetSECR0_MSTR(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> MSTR=(ParValue))
#define biGetSECR0_IFSPSE(ctrlr) (pst_bitSECR0(ctrlr) -> IFSPSE)
#define vSetSECR0_IFSPSE(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> IFSPSE=(ParValue))
#define biGetSECR0_SSIVAL(ctrlr) (pst_bitSECR0(ctrlr) -> SSIVAL)
#define vSetSECR0_SSIVAL(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> SSIVAL=(ParValue))
#define biGetSECR0_STFIE(ctrlr) (pst_bitSECR0(ctrlr) -> STFIE)
#define vSetSECR0_STFIE(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> STFIE=(ParValue))
#define biGetSECR0_SUEIE(ctrlr) (pst_bitSECR0(ctrlr) -> SUEIE)
#define vSetSECR0_SUEIE(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> SUEIE=(ParValue))
#define biGetSECR0_SOEIE(ctrlr) (pst_bitSECR0(ctrlr) -> SOEIE)
#define vSetSECR0_SOEIE(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> SOEIE=(ParValue))
#define biGetSECR0_SILIE(ctrlr) (pst_bitSECR0(ctrlr) -> SILIE)
#define vSetSECR0_SILIE(ctrlr,ParValue)  (pst_bitSECR0(ctrlr) -> SILIE=(ParValue))
            
/* L-struct byte access */
#define vSetSECR0L(ctrlr,ParValue) (pst_u8SECR0(ctrlr) -> u8L = (ParValue))
#define u8GetSECR0L(ctrlr) (pst_u8SECR0(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSECR0H(ctrlr,ParValue) (pst_u8SECR0(ctrlr) -> u8H = (ParValue))
#define u8GetSECR0H(ctrlr) (pst_u8SECR0(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSECR0(ctrlr,ParValue) (*pu16SECR0(ctrlr)  = (ParValue))
#define u16GetSECR0(ctrlr) (*pu16SECR0(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SECR1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322008                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SECR1_REG__       0xC0322008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   SSZ	:5; 	 /* 0..4  bit(s) R/W */
  uint16_t   	:3; 	 /* 5..7  bit(s) R */
  uint16_t   SER	:8; 	 /* 8..15  bit(s) R/W */                    
} SECR1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SECR1_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SECR1_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSECR1(ctrlr)     ((volatile SECR1_bit_view_st *)\
(SECR1_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SECR1(ctrlr)     ((volatile SECR1_byte_view_st *)\
(SECR1_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SECR1(ctrlr)     ((volatile u16SECR1_halfword_view *)\
(SECR1_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSECR1_SSZ(ctrlr) (pst_bitSECR1(ctrlr) -> SSZ)
#define vSetSECR1_SSZ(ctrlr,ParValue)  (pst_bitSECR1(ctrlr) -> SSZ=(ParValue))
#define biGetSECR1_SER(ctrlr) (pst_bitSECR1(ctrlr) -> SER)
#define vSetSECR1_SER(ctrlr,ParValue)  (pst_bitSECR1(ctrlr) -> SER=(ParValue))
            
/* L-struct byte access */
#define vSetSECR1L(ctrlr,ParValue) (pst_u8SECR1(ctrlr) -> u8L = (ParValue))
#define u8GetSECR1L(ctrlr) (pst_u8SECR1(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSECR1H(ctrlr,ParValue) (pst_u8SECR1(ctrlr) -> u8H = (ParValue))
#define u8GetSECR1H(ctrlr) (pst_u8SECR1(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSECR1(ctrlr,ParValue) (*pu16SECR1(ctrlr)  = (ParValue))
#define u16GetSECR1(ctrlr) (*pu16SECR1(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SEFSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC032200C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SEFSR_REG__       0xC032200CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   IFS	:10; 	 /* 0..9  bit(s) R/W */ 
  uint16_t   	:6; 	 /* 10..31  bit(s) R */                    
} SEFSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SEFSR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SEFSR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSEFSR(ctrlr)     ((volatile SEFSR_bit_view_st *)\
(SEFSR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SEFSR(ctrlr)     ((volatile SEFSR_byte_view_st *)\
(SEFSR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SEFSR(ctrlr)     ((volatile u16SEFSR_halfword_view *)\
(SEFSR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSEFSR_IFS(ctrlr) (pst_bitSEFSR(ctrlr) -> IFS)
#define vSetSEFSR_IFS(ctrlr,ParValue)  (pst_bitSEFSR(ctrlr) -> IFS=(ParValue))
            
/* L-struct byte access */
#define vSetSEFSRL(ctrlr,ParValue) (pst_u8SEFSR(ctrlr) -> u8L = (ParValue))
#define u8GetSEFSRL(ctrlr) (pst_u8SEFSR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSEFSRH(ctrlr,ParValue) (pst_u8SEFSR(ctrlr) -> u8H = (ParValue))
#define u8GetSEFSRH(ctrlr) (pst_u8SEFSR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSEFSR(ctrlr,ParValue) (*pu16SEFSR(ctrlr)  = (ParValue))
#define u16GetSEFSR(ctrlr) (*pu16SEFSR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SSSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322010                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SSSR_REG__       0xC0322010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   SSS	:8; 	 /* 0..7  bit(s) R/W */                    
} SSSR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SSSR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSSSR(ctrlr)     ((volatile SSSR_bit_view_st *)\
(SSSR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8SSSR(ctrlr)     ((volatile u8SSSR_byte_view *)\
(SSSR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSSSR_SSS(ctrlr) (pst_bitSSSR(ctrlr) -> SSS)
#define vSetSSSR_SSS(ctrlr,ParValue)  (pst_bitSSSR(ctrlr) -> SSS=(ParValue))
            
/* byte access */
#define vSetSSSR(ctrlr,ParValue) (*pu8SSSR(ctrlr) = (ParValue))
#define u8GetSSSR(ctrlr) (*pu8SSSR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SESR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322014                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SESR_REG__       0xC0322014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SRRDY	:1; 	 /* 0..0  bit(s) R */
  uint32_t   STRDY	:1; 	 /* 1..1  bit(s) R */
  uint32_t   SIDLE	:1; 	 /* 2..2  bit(s) R */
  uint32_t   IFSD	:1; 	 /* 3..3  bit(s) R */
  uint32_t   	:1; 	 /* 4..4  bit(s) R */
  uint32_t   SETF	:1; 	 /* 5..5  bit(s) R/W1C */
  uint32_t   SEUE	:1; 	 /* 6..6  bit(s) R/W1C */
  uint32_t   SEOE	:1; 	 /* 7..7  bit(s) R/W1C */
  uint32_t   	:6; 	 /* 8..13  bit(s) R */
  uint32_t   RBSI	:1; 	 /* 14..14  bit(s) R */
  uint32_t   TBSI	:1; 	 /* 15..15  bit(s) R */
  uint32_t   SEILC	:1; 	 /* 16..16  bit(s) R */
  uint32_t   PAR	:1; 	 /* 17..17  bit(s) R/W1C */
  uint32_t   RBF	:1; 	 /* 18..18  bit(s) R */
  uint32_t   TBF	:1; 	 /* 19..19  bit(s) R */ 
  uint32_t   	:12; 	 /* 20..31  bit(s) R */                    
} SESR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SESR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SESR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SESR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSESR(ctrlr)     ((volatile SESR_bit_view_st *)\
(SESR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SESR(ctrlr)     ((volatile SESR_byte_view_st *)\
(SESR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SESR(ctrlr)     ((volatile SESR_halfword_view_st *)\
(SESR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to WORD  */ 
#define pu32SESR(ctrlr)     ((volatile u32SESR_word_view *)\
(SESR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSESR_SRRDY(ctrlr) (pst_bitSESR(ctrlr) -> SRRDY)            
#define biGetSESR_STRDY(ctrlr) (pst_bitSESR(ctrlr) -> STRDY)            
#define biGetSESR_SIDLE(ctrlr) (pst_bitSESR(ctrlr) -> SIDLE)            
#define biGetSESR_IFSD(ctrlr) (pst_bitSESR(ctrlr) -> IFSD)
#define biGetSESR_SETF(ctrlr) (pst_bitSESR(ctrlr) -> SETF)
#define vClrSESR_SETF(ctrlr) (pst_bitSESR(ctrlr) -> SETF = (1))
#define biGetSESR_SEUE(ctrlr) (pst_bitSESR(ctrlr) -> SEUE)
#define vClrSESR_SEUE(ctrlr) (pst_bitSESR(ctrlr) -> SEUE = (1))
#define biGetSESR_SEOE(ctrlr) (pst_bitSESR(ctrlr) -> SEOE)
#define vClrSESR_SEOE(ctrlr) (pst_bitSESR(ctrlr) -> SEOE = (1))            
#define biGetSESR_RBSI(ctrlr) (pst_bitSESR(ctrlr) -> RBSI)            
#define biGetSESR_TBSI(ctrlr) (pst_bitSESR(ctrlr) -> TBSI)            
#define biGetSESR_SEILC(ctrlr) (pst_bitSESR(ctrlr) -> SEILC)
#define biGetSESR_PAR(ctrlr) (pst_bitSESR(ctrlr) -> PAR)
#define vClrSESR_PAR(ctrlr) (pst_bitSESR(ctrlr) -> PAR = (1))            
#define biGetSESR_RBF(ctrlr) (pst_bitSESR(ctrlr) -> RBF)            
#define biGetSESR_TBF(ctrlr) (pst_bitSESR(ctrlr) -> TBF)
            
/* LL-struct byte access */
#define vSetSESRLL(ctrlr,ParValue) (pst_u8SESR(ctrlr) -> u8LL = (ParValue))
#define u8GetSESRLL(ctrlr) (pst_u8SESR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetSESRLH(ctrlr,ParValue) (pst_u8SESR(ctrlr) -> u8LH = (ParValue))
#define u8GetSESRLH(ctrlr) (pst_u8SESR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetSESRHL(ctrlr,ParValue) (pst_u8SESR(ctrlr) -> u8HL = (ParValue))
#define u8GetSESRHL(ctrlr) (pst_u8SESR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetSESRHH(ctrlr,ParValue) (pst_u8SESR(ctrlr) -> u8HH = (ParValue))
#define u8GetSESRHH(ctrlr) (pst_u8SESR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSESRL(ctrlr,ParValue) (pst_u16SESR(ctrlr) -> u16L = (ParValue))
#define u16GetSESRL(ctrlr) (pst_u16SESR(ctrlr) -> u16L)
#define vSetSESRH(ctrlr,ParValue) (pst_u16SESR(ctrlr) -> u16H = (ParValue))
#define u16GetSESRH(ctrlr) (pst_u16SESR(ctrlr) -> u16H)
            
/* Word access */
#define vSetSESR(ctrlr,ParValue)  (*pu32SESR(ctrlr) = (ParValue))
#define u32GetSESR(ctrlr)  (*pu32SESR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SEDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322018                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SEDR_REG__       0xC0322018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   DR	:16; 	 /* 0..15  bit(s) R/W */                    
} SEDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SEDR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SEDR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSEDR(ctrlr)     ((volatile SEDR_bit_view_st *)\
(SEDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SEDR(ctrlr)     ((volatile SEDR_byte_view_st *)\
(SEDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SEDR(ctrlr)     ((volatile u16SEDR_halfword_view *)\
(SEDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSEDR_DR(ctrlr) (pst_bitSEDR(ctrlr) -> DR)
#define vSetSEDR_DR(ctrlr,ParValue)  (pst_bitSEDR(ctrlr) -> DR=(ParValue))
            
/* L-struct byte access */
#define vSetSEDRL(ctrlr,ParValue) (pst_u8SEDR(ctrlr) -> u8L = (ParValue))
#define u8GetSEDRL(ctrlr) (pst_u8SEDR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSEDRH(ctrlr,ParValue) (pst_u8SEDR(ctrlr) -> u8H = (ParValue))
#define u8GetSEDRH(ctrlr) (pst_u8SEDR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSEDR(ctrlr,ParValue) (*pu16SEDR(ctrlr)  = (ParValue))
#define u16GetSEDR(ctrlr) (*pu16SEDR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SERSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC032201C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SERSR_REG__       0xC032201CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   RS	:16; 	 /* 0..15  bit(s) R */                    
} SERSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SERSR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SERSR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSERSR(ctrlr)     ((volatile SERSR_bit_view_st *)\
(SERSR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SERSR(ctrlr)     ((volatile SERSR_byte_view_st *)\
(SERSR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SERSR(ctrlr)     ((volatile u16SERSR_halfword_view *)\
(SERSR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSERSR_RS(ctrlr) (pst_bitSERSR(ctrlr) -> RS)
            
/* L-struct byte access */

#define u8GetSERSRL(ctrlr) (pst_u8SERSR(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetSERSRH(ctrlr) (pst_u8SERSR(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetSERSR(ctrlr) (*pu16SERSR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SEFLR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322020                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SEFLR_REG__       0xC0322020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   SRBFL	:5; 	 /* 0..4  bit(s) R */
  uint16_t   	:3; 	 /* 5..7  bit(s) R */
  uint16_t   STBFL	:5; 	 /* 8..12  bit(s) R */ 
  uint16_t   	:3; 	 /* 13..31  bit(s) R */                    
} SEFLR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SEFLR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SEFLR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSEFLR(ctrlr)     ((volatile SEFLR_bit_view_st *)\
(SEFLR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SEFLR(ctrlr)     ((volatile SEFLR_byte_view_st *)\
(SEFLR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SEFLR(ctrlr)     ((volatile u16SEFLR_halfword_view *)\
(SEFLR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSEFLR_SRBFL(ctrlr) (pst_bitSEFLR(ctrlr) -> SRBFL)            
#define biGetSEFLR_STBFL(ctrlr) (pst_bitSEFLR(ctrlr) -> STBFL)
            
/* L-struct byte access */

#define u8GetSEFLRL(ctrlr) (pst_u8SEFLR(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetSEFLRH(ctrlr) (pst_u8SEFLR(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetSEFLR(ctrlr) (*pu16SEFLR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SEILR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322024                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SEILR_REG__       0xC0322024U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   RXIFL	:5; 	 /* 0..4  bit(s) R/W */
  uint16_t   	:3; 	 /* 5..7  bit(s) R */
  uint16_t   TXIFL	:5; 	 /* 8..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..31  bit(s) R */                    
} SEILR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SEILR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SEILR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSEILR(ctrlr)     ((volatile SEILR_bit_view_st *)\
(SEILR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SEILR(ctrlr)     ((volatile SEILR_byte_view_st *)\
(SEILR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16SEILR(ctrlr)     ((volatile u16SEILR_halfword_view *)\
(SEILR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSEILR_RXIFL(ctrlr) (pst_bitSEILR(ctrlr) -> RXIFL)
#define vSetSEILR_RXIFL(ctrlr,ParValue)  (pst_bitSEILR(ctrlr) -> RXIFL=(ParValue))
#define biGetSEILR_TXIFL(ctrlr) (pst_bitSEILR(ctrlr) -> TXIFL)
#define vSetSEILR_TXIFL(ctrlr,ParValue)  (pst_bitSEILR(ctrlr) -> TXIFL=(ParValue))
            
/* L-struct byte access */
#define vSetSEILRL(ctrlr,ParValue) (pst_u8SEILR(ctrlr) -> u8L = (ParValue))
#define u8GetSEILRL(ctrlr) (pst_u8SEILR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetSEILRH(ctrlr,ParValue) (pst_u8SEILR(ctrlr) -> u8H = (ParValue))
#define u8GetSEILRH(ctrlr) (pst_u8SEILR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetSEILR(ctrlr,ParValue) (*pu16SEILR(ctrlr)  = (ParValue))
#define u16GetSEILR(ctrlr) (*pu16SEILR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SEPR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322028                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SEPR_REG__       0xC0322028U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   SPISE	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   SPIE	:1; 	 /* 1..1  bit(s) R/W */
  uint8_t   SPEO	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   	:1; 	 /* 3..3  bit(s) R */
  uint8_t   SPEN	:1; 	 /* 4..4  bit(s) R/W */
  uint8_t   SPP01	:2; 	 /* 5..6  bit(s) R/W */ 
  uint8_t   	:1; 	 /* 7..31  bit(s) R */                    
} SEPR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SEPR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSEPR(ctrlr)     ((volatile SEPR_bit_view_st *)\
(SEPR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8SEPR(ctrlr)     ((volatile u8SEPR_byte_view *)\
(SEPR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSEPR_SPISE(ctrlr) (pst_bitSEPR(ctrlr) -> SPISE)
#define vSetSEPR_SPISE(ctrlr,ParValue)  (pst_bitSEPR(ctrlr) -> SPISE=(ParValue))
#define biGetSEPR_SPIE(ctrlr) (pst_bitSEPR(ctrlr) -> SPIE)
#define vSetSEPR_SPIE(ctrlr,ParValue)  (pst_bitSEPR(ctrlr) -> SPIE=(ParValue))
#define biGetSEPR_SPEO(ctrlr) (pst_bitSEPR(ctrlr) -> SPEO)
#define vSetSEPR_SPEO(ctrlr,ParValue)  (pst_bitSEPR(ctrlr) -> SPEO=(ParValue))
#define biGetSEPR_SPEN(ctrlr) (pst_bitSEPR(ctrlr) -> SPEN)
#define vSetSEPR_SPEN(ctrlr,ParValue)  (pst_bitSEPR(ctrlr) -> SPEN=(ParValue))
#define biGetSEPR_SPP01(ctrlr) (pst_bitSEPR(ctrlr) -> SPP01)
#define vSetSEPR_SPP01(ctrlr,ParValue)  (pst_bitSEPR(ctrlr) -> SPP01=(ParValue))
            
/* byte access */
#define vSetSEPR(ctrlr,ParValue) (*pu8SEPR(ctrlr) = (ParValue))
#define u8GetSEPR(ctrlr) (*pu8SEPR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SELCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC032202C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SELCR_REG__       0xC032202CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   SLB	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   SLTB	:1; 	 /* 1..1  bit(s) R/W */ 
  uint8_t   	:6; 	 /* 2..31  bit(s) R */                    
} SELCR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SELCR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSELCR(ctrlr)     ((volatile SELCR_bit_view_st *)\
(SELCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8SELCR(ctrlr)     ((volatile u8SELCR_byte_view *)\
(SELCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSELCR_SLB(ctrlr) (pst_bitSELCR(ctrlr) -> SLB)
#define vSetSELCR_SLB(ctrlr,ParValue)  (pst_bitSELCR(ctrlr) -> SLB=(ParValue))
#define biGetSELCR_SLTB(ctrlr) (pst_bitSELCR(ctrlr) -> SLTB)
#define vSetSELCR_SLTB(ctrlr,ParValue)  (pst_bitSELCR(ctrlr) -> SLTB=(ParValue))
            
/* byte access */
#define vSetSELCR(ctrlr,ParValue) (*pu8SELCR(ctrlr) = (ParValue))
#define u8GetSELCR(ctrlr) (*pu8SELCR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SEDER_R                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322030                             
*       ACCESS  : 32,                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SEDER_R_REG__       0xC0322030U
     
/************************       STRUCTURES        ***************************/
        
/* WORD View */
typedef uint32_t u32SEDER_R_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to WORD  */ 
#define pu32SEDER_R(ctrlr)     ((volatile u32SEDER_R_word_view *)\
(SEDER_R_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
            
/* Word access */

#define u32GetSEDER_R(ctrlr)  (*pu32SEDER_R(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SEDER_W                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0322030                             
*       ACCESS  : 32,                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SEDER_W_REG__       0xC0322030U
     
/************************       STRUCTURES        ***************************/
        
/* WORD View */
typedef uint32_t u32SEDER_W_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to WORD  */ 
#define pu32SEDER_W(ctrlr)     ((volatile u32SEDER_W_word_view *)\
(SEDER_W_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
            
/* Word access */
#define vSetSEDER_W(ctrlr,ParValue)  (*pu32SEDER_W(ctrlr) = (ParValue))
#define u32GetSEDER_W(ctrlr)  (*pu32SEDER_W(ctrlr) )
            
/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
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

#endif /* X_ESEIIO_H */ 
    
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

