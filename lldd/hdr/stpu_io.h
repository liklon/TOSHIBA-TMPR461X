
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : STPU_8TMR 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:50:44.884+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.9 $ 
/  Excel Sheet ver.             : vv1.0
/  Excel Sheet date             : 2013-Jun-21
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : STPU low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : STPU
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.9 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef STPU_8TMRIO_H
#define STPU_8TMRIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */ 
     
/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_STPU_IO_H_REVISION     "$Revision: 1.9 $"
#define LLDD_STPU_IO_H_TAG          "$Name: LLDD_1_6 $"
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRVER                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRVER_REG__       0xC0100000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   VER	:32; 	 /* 0..31  bit(s) R */                    
} STPU_TMRVER_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRVER_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRVER_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRVER_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRVER()     ((volatile STPU_TMRVER_bit_view_st *)\
(STPU_TMRVER_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRVER()     ((volatile STPU_TMRVER_byte_view_st *)\
(STPU_TMRVER_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRVER()     ((volatile STPU_TMRVER_halfword_view_st *)\
(STPU_TMRVER_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRVER()     ((volatile u32STPU_TMRVER_word_view *)\
(STPU_TMRVER_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSTPU_TMRVER_VER() (pst_bitSTPU_TMRVER() -> VER)
            
/* LL-struct byte access */

#define u8GetSTPU_TMRVERLL() (pst_u8STPU_TMRVER() -> u8LL)
/* LH-struct byte access */

#define u8GetSTPU_TMRVERLH() (pst_u8STPU_TMRVER() -> u8LH)
/* HL-struct byte access */

#define u8GetSTPU_TMRVERHL() (pst_u8STPU_TMRVER() -> u8HL)
/* HH-struct byte access */

#define u8GetSTPU_TMRVERHH() (pst_u8STPU_TMRVER() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetSTPU_TMRVERL() (pst_u16STPU_TMRVER() -> u16L)

#define u16GetSTPU_TMRVERH() (pst_u16STPU_TMRVER() -> u16H)
            
/* Word access */

#define u32GetSTPU_TMRVER()  (*pu32STPU_TMRVER() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_CFG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_CFG_REG__       0xC0100004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CMPRSCLR	:6; 	 /* 0..5  bit(s) R/W */
  uint32_t   RSRV1	:2; 	 /* 6..7  bit(s) R */
  uint32_t   CMPRSCLREN	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   RSRV2	:7; 	 /* 9..15  bit(s) R */
  uint32_t   INTREN	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   RSRV3	:7; 	 /* 17..23  bit(s) R */
  uint32_t   DIGNMDEN	:1; 	 /* 24..24  bit(s) R/W */ 
  uint32_t   RSRV4	:7; 	 /* 25..31  bit(s) R */                    
} STPU_CFG_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_CFG_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_CFG_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_CFG_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_CFG()     ((volatile STPU_CFG_bit_view_st *)\
(STPU_CFG_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_CFG()     ((volatile STPU_CFG_byte_view_st *)\
(STPU_CFG_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_CFG()     ((volatile STPU_CFG_halfword_view_st *)\
(STPU_CFG_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32STPU_CFG()     ((volatile u32STPU_CFG_word_view *)\
(STPU_CFG_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSTPU_CFG_CMPRSCLR() (pst_bitSTPU_CFG() -> CMPRSCLR)
#define vSetSTPU_CFG_CMPRSCLR(ParValue)  (pst_bitSTPU_CFG() -> CMPRSCLR=(ParValue))            
#define biGetSTPU_CFG_RSRV1() (pst_bitSTPU_CFG() -> RSRV1)
#define biGetSTPU_CFG_CMPRSCLREN() (pst_bitSTPU_CFG() -> CMPRSCLREN)
#define vSetSTPU_CFG_CMPRSCLREN(ParValue)  (pst_bitSTPU_CFG() -> CMPRSCLREN=(ParValue))            
#define biGetSTPU_CFG_RSRV2() (pst_bitSTPU_CFG() -> RSRV2)
#define biGetSTPU_CFG_INTREN() (pst_bitSTPU_CFG() -> INTREN)
#define vSetSTPU_CFG_INTREN(ParValue)  (pst_bitSTPU_CFG() -> INTREN=(ParValue))            
#define biGetSTPU_CFG_RSRV3() (pst_bitSTPU_CFG() -> RSRV3)
#define biGetSTPU_CFG_DIGNMDEN() (pst_bitSTPU_CFG() -> DIGNMDEN)
#define vSetSTPU_CFG_DIGNMDEN(ParValue)  (pst_bitSTPU_CFG() -> DIGNMDEN=(ParValue))            
#define biGetSTPU_CFG_RSRV4() (pst_bitSTPU_CFG() -> RSRV4)
            
/* LL-struct byte access */
#define vSetSTPU_CFGLL(ParValue) (pst_u8STPU_CFG() -> u8LL = (ParValue))
#define u8GetSTPU_CFGLL() (pst_u8STPU_CFG() -> u8LL)
/* LH-struct byte access */
#define vSetSTPU_CFGLH(ParValue) (pst_u8STPU_CFG() -> u8LH = (ParValue))
#define u8GetSTPU_CFGLH() (pst_u8STPU_CFG() -> u8LH)
/* HL-struct byte access */
#define vSetSTPU_CFGHL(ParValue) (pst_u8STPU_CFG() -> u8HL = (ParValue))
#define u8GetSTPU_CFGHL() (pst_u8STPU_CFG() -> u8HL)
/* HH-struct byte access */
#define vSetSTPU_CFGHH(ParValue) (pst_u8STPU_CFG() -> u8HH = (ParValue))
#define u8GetSTPU_CFGHH() (pst_u8STPU_CFG() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSTPU_CFGL(ParValue) (pst_u16STPU_CFG() -> u16L = (ParValue))
#define u16GetSTPU_CFGL() (pst_u16STPU_CFG() -> u16L)
#define vSetSTPU_CFGH(ParValue) (pst_u16STPU_CFG() -> u16H = (ParValue))
#define u16GetSTPU_CFGH() (pst_u16STPU_CFG() -> u16H)
            
/* Word access */
#define vSetSTPU_CFG(ParValue)  (*pu32STPU_CFG() = (ParValue))
#define u32GetSTPU_CFG()  (*pu32STPU_CFG() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRST                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRST_REG__       0xC0100008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   IST	:32; 	 /* 0..31  bit(s) R */                    
} STPU_TMRST_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRST_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRST_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRST_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRST()     ((volatile STPU_TMRST_bit_view_st *)\
(STPU_TMRST_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRST()     ((volatile STPU_TMRST_byte_view_st *)\
(STPU_TMRST_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRST()     ((volatile STPU_TMRST_halfword_view_st *)\
(STPU_TMRST_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRST()     ((volatile u32STPU_TMRST_word_view *)\
(STPU_TMRST_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSTPU_TMRST_IST() (pst_bitSTPU_TMRST() -> IST)
            
/* LL-struct byte access */

#define u8GetSTPU_TMRSTLL() (pst_u8STPU_TMRST() -> u8LL)
/* LH-struct byte access */

#define u8GetSTPU_TMRSTLH() (pst_u8STPU_TMRST() -> u8LH)
/* HL-struct byte access */

#define u8GetSTPU_TMRSTHL() (pst_u8STPU_TMRST() -> u8HL)
/* HH-struct byte access */

#define u8GetSTPU_TMRSTHH() (pst_u8STPU_TMRST() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetSTPU_TMRSTL() (pst_u16STPU_TMRST() -> u16L)

#define u16GetSTPU_TMRSTH() (pst_u16STPU_TMRST() -> u16H)
            
/* Word access */

#define u32GetSTPU_TMRST()  (*pu32STPU_TMRST() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRINTDS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010000C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRINTDS_REG__       0xC010000CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   INTD	:32; 	 /* 0..31  bit(s) R/W */                    
} STPU_TMRINTDS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRINTDS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRINTDS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRINTDS_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRINTDS()     ((volatile STPU_TMRINTDS_bit_view_st *)\
(STPU_TMRINTDS_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRINTDS()     ((volatile STPU_TMRINTDS_byte_view_st *)\
(STPU_TMRINTDS_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRINTDS()     ((volatile STPU_TMRINTDS_halfword_view_st *)\
(STPU_TMRINTDS_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRINTDS()     ((volatile u32STPU_TMRINTDS_word_view *)\
(STPU_TMRINTDS_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSTPU_TMRINTDS_INTD() (pst_bitSTPU_TMRINTDS() -> INTD)
#define vSetSTPU_TMRINTDS_INTD(ParValue)  (pst_bitSTPU_TMRINTDS() -> INTD=(ParValue))
            
/* LL-struct byte access */
#define vSetSTPU_TMRINTDSLL(ParValue) (pst_u8STPU_TMRINTDS() -> u8LL = (ParValue))
#define u8GetSTPU_TMRINTDSLL() (pst_u8STPU_TMRINTDS() -> u8LL)
/* LH-struct byte access */
#define vSetSTPU_TMRINTDSLH(ParValue) (pst_u8STPU_TMRINTDS() -> u8LH = (ParValue))
#define u8GetSTPU_TMRINTDSLH() (pst_u8STPU_TMRINTDS() -> u8LH)
/* HL-struct byte access */
#define vSetSTPU_TMRINTDSHL(ParValue) (pst_u8STPU_TMRINTDS() -> u8HL = (ParValue))
#define u8GetSTPU_TMRINTDSHL() (pst_u8STPU_TMRINTDS() -> u8HL)
/* HH-struct byte access */
#define vSetSTPU_TMRINTDSHH(ParValue) (pst_u8STPU_TMRINTDS() -> u8HH = (ParValue))
#define u8GetSTPU_TMRINTDSHH() (pst_u8STPU_TMRINTDS() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSTPU_TMRINTDSL(ParValue) (pst_u16STPU_TMRINTDS() -> u16L = (ParValue))
#define u16GetSTPU_TMRINTDSL() (pst_u16STPU_TMRINTDS() -> u16L)
#define vSetSTPU_TMRINTDSH(ParValue) (pst_u16STPU_TMRINTDS() -> u16H = (ParValue))
#define u16GetSTPU_TMRINTDSH() (pst_u16STPU_TMRINTDS() -> u16H)
            
/* Word access */
#define vSetSTPU_TMRINTDS(ParValue)  (*pu32STPU_TMRINTDS() = (ParValue))
#define u32GetSTPU_TMRINTDS()  (*pu32STPU_TMRINTDS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRINTRST                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRINTRST_REG__       0xC0100010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   INTST	:32; 	 /* 0..31  bit(s) R */                    
} STPU_TMRINTRST_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRINTRST_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRINTRST_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRINTRST_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRINTRST()     ((volatile STPU_TMRINTRST_bit_view_st *)\
(STPU_TMRINTRST_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRINTRST()     ((volatile STPU_TMRINTRST_byte_view_st *)\
(STPU_TMRINTRST_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRINTRST()     ((volatile STPU_TMRINTRST_halfword_view_st *)\
(STPU_TMRINTRST_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRINTRST()     ((volatile u32STPU_TMRINTRST_word_view *)\
(STPU_TMRINTRST_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSTPU_TMRINTRST_INTST() (pst_bitSTPU_TMRINTRST() -> INTST)
            
/* LL-struct byte access */

#define u8GetSTPU_TMRINTRSTLL() (pst_u8STPU_TMRINTRST() -> u8LL)
/* LH-struct byte access */

#define u8GetSTPU_TMRINTRSTLH() (pst_u8STPU_TMRINTRST() -> u8LH)
/* HL-struct byte access */

#define u8GetSTPU_TMRINTRSTHL() (pst_u8STPU_TMRINTRST() -> u8HL)
/* HH-struct byte access */

#define u8GetSTPU_TMRINTRSTHH() (pst_u8STPU_TMRINTRST() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetSTPU_TMRINTRSTL() (pst_u16STPU_TMRINTRST() -> u16L)

#define u16GetSTPU_TMRINTRSTH() (pst_u16STPU_TMRINTRST() -> u16H)
            
/* Word access */

#define u32GetSTPU_TMRINTRST()  (*pu32STPU_TMRINTRST() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRINTREN                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100014                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRINTREN_REG__       0xC0100014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   IEN	:32; 	 /* 0..31  bit(s) R/W */                    
} STPU_TMRINTREN_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRINTREN_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRINTREN_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRINTREN_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRINTREN()     ((volatile STPU_TMRINTREN_bit_view_st *)\
(STPU_TMRINTREN_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRINTREN()     ((volatile STPU_TMRINTREN_byte_view_st *)\
(STPU_TMRINTREN_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRINTREN()     ((volatile STPU_TMRINTREN_halfword_view_st *)\
(STPU_TMRINTREN_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRINTREN()     ((volatile u32STPU_TMRINTREN_word_view *)\
(STPU_TMRINTREN_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSTPU_TMRINTREN_IEN() (pst_bitSTPU_TMRINTREN() -> IEN)
#define vSetSTPU_TMRINTREN_IEN(ParValue)  (pst_bitSTPU_TMRINTREN() -> IEN=(ParValue))
            
/* LL-struct byte access */
#define vSetSTPU_TMRINTRENLL(ParValue) (pst_u8STPU_TMRINTREN() -> u8LL = (ParValue))
#define u8GetSTPU_TMRINTRENLL() (pst_u8STPU_TMRINTREN() -> u8LL)
/* LH-struct byte access */
#define vSetSTPU_TMRINTRENLH(ParValue) (pst_u8STPU_TMRINTREN() -> u8LH = (ParValue))
#define u8GetSTPU_TMRINTRENLH() (pst_u8STPU_TMRINTREN() -> u8LH)
/* HL-struct byte access */
#define vSetSTPU_TMRINTRENHL(ParValue) (pst_u8STPU_TMRINTREN() -> u8HL = (ParValue))
#define u8GetSTPU_TMRINTRENHL() (pst_u8STPU_TMRINTREN() -> u8HL)
/* HH-struct byte access */
#define vSetSTPU_TMRINTRENHH(ParValue) (pst_u8STPU_TMRINTREN() -> u8HH = (ParValue))
#define u8GetSTPU_TMRINTRENHH() (pst_u8STPU_TMRINTREN() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSTPU_TMRINTRENL(ParValue) (pst_u16STPU_TMRINTREN() -> u16L = (ParValue))
#define u16GetSTPU_TMRINTRENL() (pst_u16STPU_TMRINTREN() -> u16L)
#define vSetSTPU_TMRINTRENH(ParValue) (pst_u16STPU_TMRINTREN() -> u16H = (ParValue))
#define u16GetSTPU_TMRINTRENH() (pst_u16STPU_TMRINTREN() -> u16H)
            
/* Word access */
#define vSetSTPU_TMRINTREN(ParValue)  (*pu32STPU_TMRINTREN() = (ParValue))
#define u32GetSTPU_TMRINTREN()  (*pu32STPU_TMRINTREN() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRINTRCL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRINTRCL_REG__       0xC0100018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   ICL	:32; 	 /* 0..31  bit(s) R/W */                    
} STPU_TMRINTRCL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRINTRCL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRINTRCL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRINTRCL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRINTRCL()     ((volatile STPU_TMRINTRCL_bit_view_st *)\
(STPU_TMRINTRCL_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRINTRCL()     ((volatile STPU_TMRINTRCL_byte_view_st *)\
(STPU_TMRINTRCL_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRINTRCL()     ((volatile STPU_TMRINTRCL_halfword_view_st *)\
(STPU_TMRINTRCL_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRINTRCL()     ((volatile u32STPU_TMRINTRCL_word_view *)\
(STPU_TMRINTRCL_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSTPU_TMRINTRCL_ICL() (pst_bitSTPU_TMRINTRCL() -> ICL)
#define vSetSTPU_TMRINTRCL_ICL(ParValue)  (pst_bitSTPU_TMRINTRCL() -> ICL=(ParValue))
            
/* LL-struct byte access */
#define vSetSTPU_TMRINTRCLLL(ParValue) (pst_u8STPU_TMRINTRCL() -> u8LL = (ParValue))
#define u8GetSTPU_TMRINTRCLLL() (pst_u8STPU_TMRINTRCL() -> u8LL)
/* LH-struct byte access */
#define vSetSTPU_TMRINTRCLLH(ParValue) (pst_u8STPU_TMRINTRCL() -> u8LH = (ParValue))
#define u8GetSTPU_TMRINTRCLLH() (pst_u8STPU_TMRINTRCL() -> u8LH)
/* HL-struct byte access */
#define vSetSTPU_TMRINTRCLHL(ParValue) (pst_u8STPU_TMRINTRCL() -> u8HL = (ParValue))
#define u8GetSTPU_TMRINTRCLHL() (pst_u8STPU_TMRINTRCL() -> u8HL)
/* HH-struct byte access */
#define vSetSTPU_TMRINTRCLHH(ParValue) (pst_u8STPU_TMRINTRCL() -> u8HH = (ParValue))
#define u8GetSTPU_TMRINTRCLHH() (pst_u8STPU_TMRINTRCL() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSTPU_TMRINTRCLL(ParValue) (pst_u16STPU_TMRINTRCL() -> u16L = (ParValue))
#define u16GetSTPU_TMRINTRCLL() (pst_u16STPU_TMRINTRCL() -> u16L)
#define vSetSTPU_TMRINTRCLH(ParValue) (pst_u16STPU_TMRINTRCL() -> u16H = (ParValue))
#define u16GetSTPU_TMRINTRCLH() (pst_u16STPU_TMRINTRCL() -> u16H)
            
/* Word access */
#define vSetSTPU_TMRINTRCL(ParValue)  (*pu32STPU_TMRINTRCL() = (ParValue))
#define u32GetSTPU_TMRINTRCL()  (*pu32STPU_TMRINTRCL() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRCTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010001C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRCTRL_REG__       0xC010001CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   RSRV5	:29; 	 /* 0..28  bit(s) R */
  uint32_t   CON	:1; 	 /* 29..29  bit(s) R/W */
  uint32_t   STP	:1; 	 /* 30..30  bit(s) R/W */ 
  uint32_t   STR	:1; 	 /* 31..31  bit(s) R/W */                    
} STPU_TMRCTRL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRCTRL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRCTRL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRCTRL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRCTRL(ch)     ((volatile STPU_TMRCTRL_bit_view_st *)\
(STPU_TMRCTRL_REG__  + ((uint16_t)(ch) * 0x10U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRCTRL(ch)     ((volatile STPU_TMRCTRL_byte_view_st *)\
(STPU_TMRCTRL_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRCTRL(ch)     ((volatile STPU_TMRCTRL_halfword_view_st *)\
(STPU_TMRCTRL_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRCTRL(ch)     ((volatile u32STPU_TMRCTRL_word_view *)\
(STPU_TMRCTRL_REG__  + ((uint16_t)(ch) * 0x10U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSTPU_TMRCTRL_RSRV5(ch) (pst_bitSTPU_TMRCTRL(ch) -> RSRV5)
#define biGetSTPU_TMRCTRL_CON(ch) (pst_bitSTPU_TMRCTRL(ch) -> CON)
#define vSetSTPU_TMRCTRL_CON(ch,ParValue)  (pst_bitSTPU_TMRCTRL(ch) -> CON=(ParValue))
#define biGetSTPU_TMRCTRL_STP(ch) (pst_bitSTPU_TMRCTRL(ch) -> STP)
#define vSetSTPU_TMRCTRL_STP(ch,ParValue)  (pst_bitSTPU_TMRCTRL(ch) -> STP=(ParValue))
#define biGetSTPU_TMRCTRL_STR(ch) (pst_bitSTPU_TMRCTRL(ch) -> STR)
#define vSetSTPU_TMRCTRL_STR(ch,ParValue)  (pst_bitSTPU_TMRCTRL(ch) -> STR=(ParValue))
            
/* LL-struct byte access */
#define vSetSTPU_TMRCTRLLL(ch,ParValue) (pst_u8STPU_TMRCTRL(ch) -> u8LL = (ParValue))
#define u8GetSTPU_TMRCTRLLL(ch) (pst_u8STPU_TMRCTRL(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSTPU_TMRCTRLLH(ch,ParValue) (pst_u8STPU_TMRCTRL(ch) -> u8LH = (ParValue))
#define u8GetSTPU_TMRCTRLLH(ch) (pst_u8STPU_TMRCTRL(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSTPU_TMRCTRLHL(ch,ParValue) (pst_u8STPU_TMRCTRL(ch) -> u8HL = (ParValue))
#define u8GetSTPU_TMRCTRLHL(ch) (pst_u8STPU_TMRCTRL(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSTPU_TMRCTRLHH(ch,ParValue) (pst_u8STPU_TMRCTRL(ch) -> u8HH = (ParValue))
#define u8GetSTPU_TMRCTRLHH(ch) (pst_u8STPU_TMRCTRL(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSTPU_TMRCTRLL(ch,ParValue) (pst_u16STPU_TMRCTRL(ch) -> u16L = (ParValue))
#define u16GetSTPU_TMRCTRLL(ch) (pst_u16STPU_TMRCTRL(ch) -> u16L)
#define vSetSTPU_TMRCTRLH(ch,ParValue) (pst_u16STPU_TMRCTRL(ch) -> u16H = (ParValue))
#define u16GetSTPU_TMRCTRLH(ch) (pst_u16STPU_TMRCTRL(ch) -> u16H)
            
/* Word access */
#define vSetSTPU_TMRCTRL(ch,ParValue)  (*pu32STPU_TMRCTRL(ch) = (ParValue))
#define u32GetSTPU_TMRCTRL(ch)  (*pu32STPU_TMRCTRL(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRMDCTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRMDCTRL_REG__       0xC0100020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   TMRMD	:2; 	 /* 0..1  bit(s) R/W */
  uint32_t   TMRPRLD	:1; 	 /* 2..2  bit(s) R/W */ 
  uint32_t   RSRV6	:29; 	 /* 3..31  bit(s) R */                    
} STPU_TMRMDCTRL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRMDCTRL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRMDCTRL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRMDCTRL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRMDCTRL(ch)     ((volatile STPU_TMRMDCTRL_bit_view_st *)\
(STPU_TMRMDCTRL_REG__  + ((uint16_t)(ch) * 0x10U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRMDCTRL(ch)     ((volatile STPU_TMRMDCTRL_byte_view_st *)\
(STPU_TMRMDCTRL_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRMDCTRL(ch)     ((volatile STPU_TMRMDCTRL_halfword_view_st *)\
(STPU_TMRMDCTRL_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRMDCTRL(ch)     ((volatile u32STPU_TMRMDCTRL_word_view *)\
(STPU_TMRMDCTRL_REG__  + ((uint16_t)(ch) * 0x10U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSTPU_TMRMDCTRL_TMRMD(ch) (pst_bitSTPU_TMRMDCTRL(ch) -> TMRMD)
#define vSetSTPU_TMRMDCTRL_TMRMD(ch,ParValue)  (pst_bitSTPU_TMRMDCTRL(ch) -> TMRMD=(ParValue))
#define biGetSTPU_TMRMDCTRL_TMRPRLD(ch) (pst_bitSTPU_TMRMDCTRL(ch) -> TMRPRLD)
#define vSetSTPU_TMRMDCTRL_TMRPRLD(ch,ParValue)  (pst_bitSTPU_TMRMDCTRL(ch) -> TMRPRLD=(ParValue))            
#define biGetSTPU_TMRMDCTRL_RSRV6(ch) (pst_bitSTPU_TMRMDCTRL(ch) -> RSRV6)
            
/* LL-struct byte access */
#define vSetSTPU_TMRMDCTRLLL(ch,ParValue) (pst_u8STPU_TMRMDCTRL(ch) -> u8LL = (ParValue))
#define u8GetSTPU_TMRMDCTRLLL(ch) (pst_u8STPU_TMRMDCTRL(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSTPU_TMRMDCTRLLH(ch,ParValue) (pst_u8STPU_TMRMDCTRL(ch) -> u8LH = (ParValue))
#define u8GetSTPU_TMRMDCTRLLH(ch) (pst_u8STPU_TMRMDCTRL(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSTPU_TMRMDCTRLHL(ch,ParValue) (pst_u8STPU_TMRMDCTRL(ch) -> u8HL = (ParValue))
#define u8GetSTPU_TMRMDCTRLHL(ch) (pst_u8STPU_TMRMDCTRL(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSTPU_TMRMDCTRLHH(ch,ParValue) (pst_u8STPU_TMRMDCTRL(ch) -> u8HH = (ParValue))
#define u8GetSTPU_TMRMDCTRLHH(ch) (pst_u8STPU_TMRMDCTRL(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSTPU_TMRMDCTRLL(ch,ParValue) (pst_u16STPU_TMRMDCTRL(ch) -> u16L = (ParValue))
#define u16GetSTPU_TMRMDCTRLL(ch) (pst_u16STPU_TMRMDCTRL(ch) -> u16L)
#define vSetSTPU_TMRMDCTRLH(ch,ParValue) (pst_u16STPU_TMRMDCTRL(ch) -> u16H = (ParValue))
#define u16GetSTPU_TMRMDCTRLH(ch) (pst_u16STPU_TMRMDCTRL(ch) -> u16H)
            
/* Word access */
#define vSetSTPU_TMRMDCTRL(ch,ParValue)  (*pu32STPU_TMRMDCTRL(ch) = (ParValue))
#define u32GetSTPU_TMRMDCTRL(ch)  (*pu32STPU_TMRMDCTRL(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRBTPL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100024                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRBTPL_REG__       0xC0100024U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   BTPL	:32; 	 /* 0..31  bit(s) R/W */                    
} STPU_TMRBTPL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRBTPL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRBTPL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRBTPL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRBTPL(ch)     ((volatile STPU_TMRBTPL_bit_view_st *)\
(STPU_TMRBTPL_REG__  + ((uint16_t)(ch) * 0x10U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRBTPL(ch)     ((volatile STPU_TMRBTPL_byte_view_st *)\
(STPU_TMRBTPL_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRBTPL(ch)     ((volatile STPU_TMRBTPL_halfword_view_st *)\
(STPU_TMRBTPL_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRBTPL(ch)     ((volatile u32STPU_TMRBTPL_word_view *)\
(STPU_TMRBTPL_REG__  + ((uint16_t)(ch) * 0x10U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSTPU_TMRBTPL_BTPL(ch) (pst_bitSTPU_TMRBTPL(ch) -> BTPL)
#define vSetSTPU_TMRBTPL_BTPL(ch,ParValue)  (pst_bitSTPU_TMRBTPL(ch) -> BTPL=(ParValue))
            
/* LL-struct byte access */
#define vSetSTPU_TMRBTPLLL(ch,ParValue) (pst_u8STPU_TMRBTPL(ch) -> u8LL = (ParValue))
#define u8GetSTPU_TMRBTPLLL(ch) (pst_u8STPU_TMRBTPL(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSTPU_TMRBTPLLH(ch,ParValue) (pst_u8STPU_TMRBTPL(ch) -> u8LH = (ParValue))
#define u8GetSTPU_TMRBTPLLH(ch) (pst_u8STPU_TMRBTPL(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSTPU_TMRBTPLHL(ch,ParValue) (pst_u8STPU_TMRBTPL(ch) -> u8HL = (ParValue))
#define u8GetSTPU_TMRBTPLHL(ch) (pst_u8STPU_TMRBTPL(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSTPU_TMRBTPLHH(ch,ParValue) (pst_u8STPU_TMRBTPL(ch) -> u8HH = (ParValue))
#define u8GetSTPU_TMRBTPLHH(ch) (pst_u8STPU_TMRBTPL(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSTPU_TMRBTPLL(ch,ParValue) (pst_u16STPU_TMRBTPL(ch) -> u16L = (ParValue))
#define u16GetSTPU_TMRBTPLL(ch) (pst_u16STPU_TMRBTPL(ch) -> u16L)
#define vSetSTPU_TMRBTPLH(ch,ParValue) (pst_u16STPU_TMRBTPL(ch) -> u16H = (ParValue))
#define u16GetSTPU_TMRBTPLH(ch) (pst_u16STPU_TMRBTPL(ch) -> u16H)
            
/* Word access */
#define vSetSTPU_TMRBTPL(ch,ParValue)  (*pu32STPU_TMRBTPL(ch) = (ParValue))
#define u32GetSTPU_TMRBTPL(ch)  (*pu32STPU_TMRBTPL(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STPU_TMRCCV                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0100028                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define STPU_TMRCCV_REG__       0xC0100028U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   TMRCCV	:32; 	 /* 0..31  bit(s) R */                    
} STPU_TMRCCV_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STPU_TMRCCV_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STPU_TMRCCV_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STPU_TMRCCV_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSTPU_TMRCCV(ch)     ((volatile STPU_TMRCCV_bit_view_st *)\
(STPU_TMRCCV_REG__  + ((uint16_t)(ch) * 0x10U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8STPU_TMRCCV(ch)     ((volatile STPU_TMRCCV_byte_view_st *)\
(STPU_TMRCCV_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16STPU_TMRCCV(ch)     ((volatile STPU_TMRCCV_halfword_view_st *)\
(STPU_TMRCCV_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to WORD  */ 
#define pu32STPU_TMRCCV(ch)     ((volatile u32STPU_TMRCCV_word_view *)\
(STPU_TMRCCV_REG__  + ((uint16_t)(ch) * 0x10U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSTPU_TMRCCV_TMRCCV(ch) (pst_bitSTPU_TMRCCV(ch) -> TMRCCV)
            
/* LL-struct byte access */

#define u8GetSTPU_TMRCCVLL(ch) (pst_u8STPU_TMRCCV(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetSTPU_TMRCCVLH(ch) (pst_u8STPU_TMRCCV(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetSTPU_TMRCCVHL(ch) (pst_u8STPU_TMRCCV(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetSTPU_TMRCCVHH(ch) (pst_u8STPU_TMRCCV(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetSTPU_TMRCCVL(ch) (pst_u16STPU_TMRCCV(ch) -> u16L)

#define u16GetSTPU_TMRCCVH(ch) (pst_u16STPU_TMRCCV(ch) -> u16H)
            
/* Word access */

#define u32GetSTPU_TMRCCV(ch)  (*pu32STPU_TMRCCV(ch) )
            




    

#endif /* STPU_8TMRIO_H */ 
    
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

