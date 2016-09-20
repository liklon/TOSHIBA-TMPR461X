
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : PNGDe 
/  Date of creation (y-m-d:time): 2015-01-23+01:00  :  12:06:21.789+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.11 $ 
/  Excel Sheet ver.             : vv1.16
/  Excel Sheet date             : 2014-Oct-28
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : PNG low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : PNG
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.11 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef PNGDeIO_H
#define PNGDeIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */ 

/*********************************************/
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */

#endif

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_PNG_IO_H_REVISION     "$Revision: 1.11 $"
#define LLDD_PNG_IO_H_TAG          "$Name: LLDD_1_7_GFX $"

/*********************************************/
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGVER                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGVER_REG__       0xC0C04000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   VERSION	:32; 	 /* 0..31  bit(s) R */                    
} PNGVER_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGVER_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGVER_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGVER_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGVER()     ((volatile PNGVER_bit_view_st *)\
(PNGVER_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGVER()     ((volatile PNGVER_byte_view_st *)\
(PNGVER_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGVER()     ((volatile PNGVER_halfword_view_st *)\
(PNGVER_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGVER()     ((volatile u32PNGVER_word_view *)\
(PNGVER_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGVER_VERSION() (pst_bitPNGVER() -> VERSION)
            
/* LL-struct byte access */

#define u8GetPNGVERLL() (pst_u8PNGVER() -> u8LL)
/* LH-struct byte access */

#define u8GetPNGVERLH() (pst_u8PNGVER() -> u8LH)
/* HL-struct byte access */

#define u8GetPNGVERHL() (pst_u8PNGVER() -> u8HL)
/* HH-struct byte access */

#define u8GetPNGVERHH() (pst_u8PNGVER() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGVERL() (pst_u16PNGVER() -> u16L)

#define u16GetPNGVERH() (pst_u16PNGVER() -> u16H)
            
/* Word access */

#define u32GetPNGVER()  (*pu32PNGVER() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGGCTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGGCTRL_REG__       0xC0C04004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   IPRE	:1; 	 /* 0..0  bit(s) R/W */ 
  uint32_t   RSRVD1	:31; 	 /* 1..31  bit(s) R */                    
} PNGGCTRL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGGCTRL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGGCTRL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGGCTRL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGGCTRL()     ((volatile PNGGCTRL_bit_view_st *)\
(PNGGCTRL_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGGCTRL()     ((volatile PNGGCTRL_byte_view_st *)\
(PNGGCTRL_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGGCTRL()     ((volatile PNGGCTRL_halfword_view_st *)\
(PNGGCTRL_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGGCTRL()     ((volatile u32PNGGCTRL_word_view *)\
(PNGGCTRL_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGGCTRL_IPRE() (pst_bitPNGGCTRL() -> IPRE)
#define vSetPNGGCTRL_IPRE(ParValue)  (pst_bitPNGGCTRL() -> IPRE=(ParValue))            
#define biGetPNGGCTRL_RSRVD1() (pst_bitPNGGCTRL() -> RSRVD1)
            
/* LL-struct byte access */
#define vSetPNGGCTRLLL(ParValue) (pst_u8PNGGCTRL() -> u8LL = (ParValue))
#define u8GetPNGGCTRLLL() (pst_u8PNGGCTRL() -> u8LL)
/* LH-struct byte access */
#define vSetPNGGCTRLLH(ParValue) (pst_u8PNGGCTRL() -> u8LH = (ParValue))
#define u8GetPNGGCTRLLH() (pst_u8PNGGCTRL() -> u8LH)
/* HL-struct byte access */
#define vSetPNGGCTRLHL(ParValue) (pst_u8PNGGCTRL() -> u8HL = (ParValue))
#define u8GetPNGGCTRLHL() (pst_u8PNGGCTRL() -> u8HL)
/* HH-struct byte access */
#define vSetPNGGCTRLHH(ParValue) (pst_u8PNGGCTRL() -> u8HH = (ParValue))
#define u8GetPNGGCTRLHH() (pst_u8PNGGCTRL() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGGCTRLL(ParValue) (pst_u16PNGGCTRL() -> u16L = (ParValue))
#define u16GetPNGGCTRLL() (pst_u16PNGGCTRL() -> u16L)
#define vSetPNGGCTRLH(ParValue) (pst_u16PNGGCTRL() -> u16H = (ParValue))
#define u16GetPNGGCTRLH() (pst_u16PNGGCTRL() -> u16H)
            
/* Word access */
#define vSetPNGGCTRL(ParValue)  (*pu32PNGGCTRL() = (ParValue))
#define u32GetPNGGCTRL()  (*pu32PNGGCTRL() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGGINTE                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGGINTE_REG__       0xC0C04008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   VSWAEIE	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   VSUAEIE	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   CW2ROEIE	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   CRSVAEIE	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   CPEIE	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   SWBEIE	:1; 	 /* 5..5  bit(s) R/W */
  uint32_t   SSBEIE	:1; 	 /* 6..6  bit(s) R/W */ 
  uint32_t   RSRVD7	:25; 	 /* 7..31  bit(s) R */                    
} PNGGINTE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGGINTE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGGINTE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGGINTE_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGGINTE()     ((volatile PNGGINTE_bit_view_st *)\
(PNGGINTE_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGGINTE()     ((volatile PNGGINTE_byte_view_st *)\
(PNGGINTE_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGGINTE()     ((volatile PNGGINTE_halfword_view_st *)\
(PNGGINTE_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGGINTE()     ((volatile u32PNGGINTE_word_view *)\
(PNGGINTE_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGGINTE_VSWAEIE() (pst_bitPNGGINTE() -> VSWAEIE)
#define vSetPNGGINTE_VSWAEIE(ParValue)  (pst_bitPNGGINTE() -> VSWAEIE=(ParValue))
#define biGetPNGGINTE_VSUAEIE() (pst_bitPNGGINTE() -> VSUAEIE)
#define vSetPNGGINTE_VSUAEIE(ParValue)  (pst_bitPNGGINTE() -> VSUAEIE=(ParValue))
#define biGetPNGGINTE_CW2ROEIE() (pst_bitPNGGINTE() -> CW2ROEIE)
#define vSetPNGGINTE_CW2ROEIE(ParValue)  (pst_bitPNGGINTE() -> CW2ROEIE=(ParValue))
#define biGetPNGGINTE_CRSVAEIE() (pst_bitPNGGINTE() -> CRSVAEIE)
#define vSetPNGGINTE_CRSVAEIE(ParValue)  (pst_bitPNGGINTE() -> CRSVAEIE=(ParValue))
#define biGetPNGGINTE_CPEIE() (pst_bitPNGGINTE() -> CPEIE)
#define vSetPNGGINTE_CPEIE(ParValue)  (pst_bitPNGGINTE() -> CPEIE=(ParValue))
#define biGetPNGGINTE_SWBEIE() (pst_bitPNGGINTE() -> SWBEIE)
#define vSetPNGGINTE_SWBEIE(ParValue)  (pst_bitPNGGINTE() -> SWBEIE=(ParValue))
#define biGetPNGGINTE_SSBEIE() (pst_bitPNGGINTE() -> SSBEIE)
#define vSetPNGGINTE_SSBEIE(ParValue)  (pst_bitPNGGINTE() -> SSBEIE=(ParValue))            
#define biGetPNGGINTE_RSRVD7() (pst_bitPNGGINTE() -> RSRVD7)
            
/* LL-struct byte access */
#define vSetPNGGINTELL(ParValue) (pst_u8PNGGINTE() -> u8LL = (ParValue))
#define u8GetPNGGINTELL() (pst_u8PNGGINTE() -> u8LL)
/* LH-struct byte access */
#define vSetPNGGINTELH(ParValue) (pst_u8PNGGINTE() -> u8LH = (ParValue))
#define u8GetPNGGINTELH() (pst_u8PNGGINTE() -> u8LH)
/* HL-struct byte access */
#define vSetPNGGINTEHL(ParValue) (pst_u8PNGGINTE() -> u8HL = (ParValue))
#define u8GetPNGGINTEHL() (pst_u8PNGGINTE() -> u8HL)
/* HH-struct byte access */
#define vSetPNGGINTEHH(ParValue) (pst_u8PNGGINTE() -> u8HH = (ParValue))
#define u8GetPNGGINTEHH() (pst_u8PNGGINTE() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGGINTEL(ParValue) (pst_u16PNGGINTE() -> u16L = (ParValue))
#define u16GetPNGGINTEL() (pst_u16PNGGINTE() -> u16L)
#define vSetPNGGINTEH(ParValue) (pst_u16PNGGINTE() -> u16H = (ParValue))
#define u16GetPNGGINTEH() (pst_u16PNGGINTE() -> u16H)
            
/* Word access */
#define vSetPNGGINTE(ParValue)  (*pu32PNGGINTE() = (ParValue))
#define u32GetPNGGINTE()  (*pu32PNGGINTE() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGGINTS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0400C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGGINTS_REG__       0xC0C0400CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   VSWAEIS	:1; 	 /* 0..0  bit(s) R */
  uint32_t   VSUAEIS	:1; 	 /* 1..1  bit(s) R */
  uint32_t   CW2ROEIS	:1; 	 /* 2..2  bit(s) R */
  uint32_t   CRSVAEIS	:1; 	 /* 3..3  bit(s) R */
  uint32_t   CPEIS	:1; 	 /* 4..4  bit(s) R */
  uint32_t   SWBEIS	:1; 	 /* 5..5  bit(s) R */
  uint32_t   SSBEIS	:1; 	 /* 6..6  bit(s) R */ 
  uint32_t   RSRVD7	:25; 	 /* 7..31  bit(s) R */                    
} PNGGINTS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGGINTS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGGINTS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGGINTS_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGGINTS()     ((volatile PNGGINTS_bit_view_st *)\
(PNGGINTS_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGGINTS()     ((volatile PNGGINTS_byte_view_st *)\
(PNGGINTS_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGGINTS()     ((volatile PNGGINTS_halfword_view_st *)\
(PNGGINTS_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGGINTS()     ((volatile u32PNGGINTS_word_view *)\
(PNGGINTS_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGGINTS_VSWAEIS() (pst_bitPNGGINTS() -> VSWAEIS)            
#define biGetPNGGINTS_VSUAEIS() (pst_bitPNGGINTS() -> VSUAEIS)            
#define biGetPNGGINTS_CW2ROEIS() (pst_bitPNGGINTS() -> CW2ROEIS)            
#define biGetPNGGINTS_CRSVAEIS() (pst_bitPNGGINTS() -> CRSVAEIS)            
#define biGetPNGGINTS_CPEIS() (pst_bitPNGGINTS() -> CPEIS)            
#define biGetPNGGINTS_SWBEIS() (pst_bitPNGGINTS() -> SWBEIS)            
#define biGetPNGGINTS_SSBEIS() (pst_bitPNGGINTS() -> SSBEIS)            
#define biGetPNGGINTS_RSRVD7() (pst_bitPNGGINTS() -> RSRVD7)
            
/* LL-struct byte access */

#define u8GetPNGGINTSLL() (pst_u8PNGGINTS() -> u8LL)
/* LH-struct byte access */

#define u8GetPNGGINTSLH() (pst_u8PNGGINTS() -> u8LH)
/* HL-struct byte access */

#define u8GetPNGGINTSHL() (pst_u8PNGGINTS() -> u8HL)
/* HH-struct byte access */

#define u8GetPNGGINTSHH() (pst_u8PNGGINTS() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGGINTSL() (pst_u16PNGGINTS() -> u16L)

#define u16GetPNGGINTSH() (pst_u16PNGGINTS() -> u16H)
            
/* Word access */

#define u32GetPNGGINTS()  (*pu32PNGGINTS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGGINTC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGGINTC_REG__       0xC0C04010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   VSWAEIC	:1; 	 /* 0..0  bit(s) R/W1C */
  uint32_t   VSUAEIC	:1; 	 /* 1..1  bit(s) R/W1C */
  uint32_t   CW2ROEIC	:1; 	 /* 2..2  bit(s) R/W1C */
  uint32_t   CRSVAEIC	:1; 	 /* 3..3  bit(s) R/W1C */
  uint32_t   CPEIC	:1; 	 /* 4..4  bit(s) R/W1C */
  uint32_t   SWBEIC	:1; 	 /* 5..5  bit(s) R/W1C */
  uint32_t   SSBEIC	:1; 	 /* 6..6  bit(s) R/W1C */ 
  uint32_t   RSRVD7	:25; 	 /* 7..31  bit(s) R */                    
} PNGGINTC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGGINTC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGGINTC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGGINTC_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGGINTC()     ((volatile PNGGINTC_bit_view_st *)\
(PNGGINTC_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGGINTC()     ((volatile PNGGINTC_byte_view_st *)\
(PNGGINTC_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGGINTC()     ((volatile PNGGINTC_halfword_view_st *)\
(PNGGINTC_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGGINTC()     ((volatile u32PNGGINTC_word_view *)\
(PNGGINTC_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGGINTC_VSWAEIC() (pst_bitPNGGINTC() -> VSWAEIC)
#define vClrPNGGINTC_VSWAEIC() (pst_bitPNGGINTC() -> VSWAEIC = (1))
#define biGetPNGGINTC_VSUAEIC() (pst_bitPNGGINTC() -> VSUAEIC)
#define vClrPNGGINTC_VSUAEIC() (pst_bitPNGGINTC() -> VSUAEIC = (1))
#define biGetPNGGINTC_CW2ROEIC() (pst_bitPNGGINTC() -> CW2ROEIC)
#define vClrPNGGINTC_CW2ROEIC() (pst_bitPNGGINTC() -> CW2ROEIC = (1))
#define biGetPNGGINTC_CRSVAEIC() (pst_bitPNGGINTC() -> CRSVAEIC)
#define vClrPNGGINTC_CRSVAEIC() (pst_bitPNGGINTC() -> CRSVAEIC = (1))
#define biGetPNGGINTC_CPEIC() (pst_bitPNGGINTC() -> CPEIC)
#define vClrPNGGINTC_CPEIC() (pst_bitPNGGINTC() -> CPEIC = (1))
#define biGetPNGGINTC_SWBEIC() (pst_bitPNGGINTC() -> SWBEIC)
#define vClrPNGGINTC_SWBEIC() (pst_bitPNGGINTC() -> SWBEIC = (1))
#define biGetPNGGINTC_SSBEIC() (pst_bitPNGGINTC() -> SSBEIC)
#define vClrPNGGINTC_SSBEIC() (pst_bitPNGGINTC() -> SSBEIC = (1))            
#define biGetPNGGINTC_RSRVD7() (pst_bitPNGGINTC() -> RSRVD7)
            
/* LL-struct byte access */
#define vSetPNGGINTCLL(ParValue) (pst_u8PNGGINTC() -> u8LL = (ParValue))
#define u8GetPNGGINTCLL() (pst_u8PNGGINTC() -> u8LL)
/* LH-struct byte access */
#define vSetPNGGINTCLH(ParValue) (pst_u8PNGGINTC() -> u8LH = (ParValue))
#define u8GetPNGGINTCLH() (pst_u8PNGGINTC() -> u8LH)
/* HL-struct byte access */
#define vSetPNGGINTCHL(ParValue) (pst_u8PNGGINTC() -> u8HL = (ParValue))
#define u8GetPNGGINTCHL() (pst_u8PNGGINTC() -> u8HL)
/* HH-struct byte access */
#define vSetPNGGINTCHH(ParValue) (pst_u8PNGGINTC() -> u8HH = (ParValue))
#define u8GetPNGGINTCHH() (pst_u8PNGGINTC() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGGINTCL(ParValue) (pst_u16PNGGINTC() -> u16L = (ParValue))
#define u16GetPNGGINTCL() (pst_u16PNGGINTC() -> u16L)
#define vSetPNGGINTCH(ParValue) (pst_u16PNGGINTC() -> u16H = (ParValue))
#define u16GetPNGGINTCH() (pst_u16PNGGINTC() -> u16H)
            
/* Word access */
#define vSetPNGGINTC(ParValue)  (*pu32PNGGINTC() = (ParValue))
#define u32GetPNGGINTC()  (*pu32PNGGINTC() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSWBEA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04014                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSWBEA_REG__       0xC0C04014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   ADDR	:32; 	 /* 0..31  bit(s) R */                    
} PNGSWBEA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSWBEA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSWBEA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSWBEA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSWBEA()     ((volatile PNGSWBEA_bit_view_st *)\
(PNGSWBEA_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSWBEA()     ((volatile PNGSWBEA_byte_view_st *)\
(PNGSWBEA_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSWBEA()     ((volatile PNGSWBEA_halfword_view_st *)\
(PNGSWBEA_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGSWBEA()     ((volatile u32PNGSWBEA_word_view *)\
(PNGSWBEA_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSWBEA_ADDR() (pst_bitPNGSWBEA() -> ADDR)
            
/* LL-struct byte access */

#define u8GetPNGSWBEALL() (pst_u8PNGSWBEA() -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSWBEALH() (pst_u8PNGSWBEA() -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSWBEAHL() (pst_u8PNGSWBEA() -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSWBEAHH() (pst_u8PNGSWBEA() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSWBEAL() (pst_u16PNGSWBEA() -> u16L)

#define u16GetPNGSWBEAH() (pst_u16PNGSWBEA() -> u16H)
            
/* Word access */

#define u32GetPNGSWBEA()  (*pu32PNGSWBEA() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSWBEC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSWBEC_REG__       0xC0C04018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WR	:1; 	 /* 0..0  bit(s) R */
  uint32_t   BTYPE	:1; 	 /* 1..1  bit(s) R */
  uint32_t   BSIZE	:3; 	 /* 2..4  bit(s) R */
  uint32_t   RTYPE	:2; 	 /* 5..6  bit(s) R */
  uint32_t   RSRVD7	:1; 	 /* 7..7  bit(s) R */
  uint32_t   BEN	:8; 	 /* 8..15  bit(s) R */
  uint32_t   ID	:4; 	 /* 16..19  bit(s) R */
  uint32_t   LEN	:4; 	 /* 20..23  bit(s) R */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGSWBEC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSWBEC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSWBEC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSWBEC_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSWBEC()     ((volatile PNGSWBEC_bit_view_st *)\
(PNGSWBEC_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSWBEC()     ((volatile PNGSWBEC_byte_view_st *)\
(PNGSWBEC_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSWBEC()     ((volatile PNGSWBEC_halfword_view_st *)\
(PNGSWBEC_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGSWBEC()     ((volatile u32PNGSWBEC_word_view *)\
(PNGSWBEC_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSWBEC_WR() (pst_bitPNGSWBEC() -> WR)            
#define biGetPNGSWBEC_BTYPE() (pst_bitPNGSWBEC() -> BTYPE)            
#define biGetPNGSWBEC_BSIZE() (pst_bitPNGSWBEC() -> BSIZE)            
#define biGetPNGSWBEC_RTYPE() (pst_bitPNGSWBEC() -> RTYPE)            
#define biGetPNGSWBEC_RSRVD7() (pst_bitPNGSWBEC() -> RSRVD7)            
#define biGetPNGSWBEC_BEN() (pst_bitPNGSWBEC() -> BEN)            
#define biGetPNGSWBEC_ID() (pst_bitPNGSWBEC() -> ID)            
#define biGetPNGSWBEC_LEN() (pst_bitPNGSWBEC() -> LEN)            
#define biGetPNGSWBEC_RSRVD24() (pst_bitPNGSWBEC() -> RSRVD24)
            
/* LL-struct byte access */

#define u8GetPNGSWBECLL() (pst_u8PNGSWBEC() -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSWBECLH() (pst_u8PNGSWBEC() -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSWBECHL() (pst_u8PNGSWBEC() -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSWBECHH() (pst_u8PNGSWBEC() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSWBECL() (pst_u16PNGSWBEC() -> u16L)

#define u16GetPNGSWBECH() (pst_u16PNGSWBEC() -> u16H)
            
/* Word access */

#define u32GetPNGSWBEC()  (*pu32PNGSWBEC() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSSBEA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0401C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSSBEA_REG__       0xC0C0401CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   ADDR	:32; 	 /* 0..31  bit(s) R */                    
} PNGSSBEA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSSBEA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSSBEA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSSBEA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSSBEA()     ((volatile PNGSSBEA_bit_view_st *)\
(PNGSSBEA_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSSBEA()     ((volatile PNGSSBEA_byte_view_st *)\
(PNGSSBEA_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSSBEA()     ((volatile PNGSSBEA_halfword_view_st *)\
(PNGSSBEA_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGSSBEA()     ((volatile u32PNGSSBEA_word_view *)\
(PNGSSBEA_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSSBEA_ADDR() (pst_bitPNGSSBEA() -> ADDR)
            
/* LL-struct byte access */

#define u8GetPNGSSBEALL() (pst_u8PNGSSBEA() -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSSBEALH() (pst_u8PNGSSBEA() -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSSBEAHL() (pst_u8PNGSSBEA() -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSSBEAHH() (pst_u8PNGSSBEA() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSSBEAL() (pst_u16PNGSSBEA() -> u16L)

#define u16GetPNGSSBEAH() (pst_u16PNGSSBEA() -> u16H)
            
/* Word access */

#define u32GetPNGSSBEA()  (*pu32PNGSSBEA() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSSBEC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSSBEC_REG__       0xC0C04020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WR	:1; 	 /* 0..0  bit(s) R */
  uint32_t   BTYPE	:1; 	 /* 1..1  bit(s) R */
  uint32_t   BSIZE	:3; 	 /* 2..4  bit(s) R */
  uint32_t   RTYPE	:2; 	 /* 5..6  bit(s) R */
  uint32_t   RSRVD7	:1; 	 /* 7..7  bit(s) R */
  uint32_t   BEN	:8; 	 /* 8..15  bit(s) R */
  uint32_t   ID	:4; 	 /* 16..19  bit(s) R */
  uint32_t   LEN	:4; 	 /* 20..23  bit(s) R */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGSSBEC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSSBEC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSSBEC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSSBEC_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSSBEC()     ((volatile PNGSSBEC_bit_view_st *)\
(PNGSSBEC_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSSBEC()     ((volatile PNGSSBEC_byte_view_st *)\
(PNGSSBEC_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSSBEC()     ((volatile PNGSSBEC_halfword_view_st *)\
(PNGSSBEC_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PNGSSBEC()     ((volatile u32PNGSSBEC_word_view *)\
(PNGSSBEC_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSSBEC_WR() (pst_bitPNGSSBEC() -> WR)            
#define biGetPNGSSBEC_BTYPE() (pst_bitPNGSSBEC() -> BTYPE)            
#define biGetPNGSSBEC_BSIZE() (pst_bitPNGSSBEC() -> BSIZE)            
#define biGetPNGSSBEC_RTYPE() (pst_bitPNGSSBEC() -> RTYPE)            
#define biGetPNGSSBEC_RSRVD7() (pst_bitPNGSSBEC() -> RSRVD7)            
#define biGetPNGSSBEC_BEN() (pst_bitPNGSSBEC() -> BEN)            
#define biGetPNGSSBEC_ID() (pst_bitPNGSSBEC() -> ID)            
#define biGetPNGSSBEC_LEN() (pst_bitPNGSSBEC() -> LEN)            
#define biGetPNGSSBEC_RSRVD24() (pst_bitPNGSSBEC() -> RSRVD24)
            
/* LL-struct byte access */

#define u8GetPNGSSBECLL() (pst_u8PNGSSBEC() -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSSBECLH() (pst_u8PNGSSBEC() -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSSBECHL() (pst_u8PNGSSBEC() -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSSBECHH() (pst_u8PNGSSBEC() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSSBECL() (pst_u16PNGSSBEC() -> u16L)

#define u16GetPNGSSBECH() (pst_u16PNGSSBEC() -> u16H)
            
/* Word access */

#define u32GetPNGSSBEC()  (*pu32PNGSSBEC() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSCTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04080                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSCTRL_REG__       0xC0C04080U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   TRIG	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   SRST	:1; 	 /* 1..1  bit(s) R/S */
  uint32_t   LOOP	:1; 	 /* 2..2  bit(s) R/W */ 
  uint32_t   RSRVD3	:29; 	 /* 3..31  bit(s) R */                    
} PNGSCTRL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSCTRL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSCTRL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSCTRL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSCTRL(ch)     ((volatile PNGSCTRL_bit_view_st *)\
(PNGSCTRL_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSCTRL(ch)     ((volatile PNGSCTRL_byte_view_st *)\
(PNGSCTRL_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSCTRL(ch)     ((volatile PNGSCTRL_halfword_view_st *)\
(PNGSCTRL_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSCTRL(ch)     ((volatile u32PNGSCTRL_word_view *)\
(PNGSCTRL_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGSCTRL_TRIG(ch) (pst_bitPNGSCTRL(ch) -> TRIG)
#define vSetPNGSCTRL_TRIG(ch,ParValue)  (pst_bitPNGSCTRL(ch) -> TRIG=(ParValue))
#define biGetPNGSCTRL_SRST(ch) (pst_bitPNGSCTRL(ch) -> SRST)
#define vSetPNGSCTRL_SRST(ch) (pst_bitPNGSCTRL(ch) -> SRST=(1))
#define biGetPNGSCTRL_LOOP(ch) (pst_bitPNGSCTRL(ch) -> LOOP)
#define vSetPNGSCTRL_LOOP(ch,ParValue)  (pst_bitPNGSCTRL(ch) -> LOOP=(ParValue))            
#define biGetPNGSCTRL_RSRVD3(ch) (pst_bitPNGSCTRL(ch) -> RSRVD3)
            
/* LL-struct byte access */
#define vSetPNGSCTRLLL(ch,ParValue) (pst_u8PNGSCTRL(ch) -> u8LL = (ParValue))
#define u8GetPNGSCTRLLL(ch) (pst_u8PNGSCTRL(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGSCTRLLH(ch,ParValue) (pst_u8PNGSCTRL(ch) -> u8LH = (ParValue))
#define u8GetPNGSCTRLLH(ch) (pst_u8PNGSCTRL(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGSCTRLHL(ch,ParValue) (pst_u8PNGSCTRL(ch) -> u8HL = (ParValue))
#define u8GetPNGSCTRLHL(ch) (pst_u8PNGSCTRL(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGSCTRLHH(ch,ParValue) (pst_u8PNGSCTRL(ch) -> u8HH = (ParValue))
#define u8GetPNGSCTRLHH(ch) (pst_u8PNGSCTRL(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGSCTRLL(ch,ParValue) (pst_u16PNGSCTRL(ch) -> u16L = (ParValue))
#define u16GetPNGSCTRLL(ch) (pst_u16PNGSCTRL(ch) -> u16L)
#define vSetPNGSCTRLH(ch,ParValue) (pst_u16PNGSCTRL(ch) -> u16H = (ParValue))
#define u16GetPNGSCTRLH(ch) (pst_u16PNGSCTRL(ch) -> u16H)
            
/* Word access */
#define vSetPNGSCTRL(ch,ParValue)  (*pu32PNGSCTRL(ch) = (ParValue))
#define u32GetPNGSCTRL(ch)  (*pu32PNGSCTRL(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSOF                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04084                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSOF_REG__       0xC0C04084U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   FSEL	:3; 	 /* 0..2  bit(s) R/W */ 
  uint32_t   RSRVD3	:29; 	 /* 3..31  bit(s) R */                    
} PNGSOF_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSOF_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSOF_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSOF_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSOF(ch)     ((volatile PNGSOF_bit_view_st *)\
(PNGSOF_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSOF(ch)     ((volatile PNGSOF_byte_view_st *)\
(PNGSOF_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSOF(ch)     ((volatile PNGSOF_halfword_view_st *)\
(PNGSOF_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSOF(ch)     ((volatile u32PNGSOF_word_view *)\
(PNGSOF_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGSOF_FSEL(ch) (pst_bitPNGSOF(ch) -> FSEL)
#define vSetPNGSOF_FSEL(ch,ParValue)  (pst_bitPNGSOF(ch) -> FSEL=(ParValue))            
#define biGetPNGSOF_RSRVD3(ch) (pst_bitPNGSOF(ch) -> RSRVD3)
            
/* LL-struct byte access */
#define vSetPNGSOFLL(ch,ParValue) (pst_u8PNGSOF(ch) -> u8LL = (ParValue))
#define u8GetPNGSOFLL(ch) (pst_u8PNGSOF(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGSOFLH(ch,ParValue) (pst_u8PNGSOF(ch) -> u8LH = (ParValue))
#define u8GetPNGSOFLH(ch) (pst_u8PNGSOF(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGSOFHL(ch,ParValue) (pst_u8PNGSOF(ch) -> u8HL = (ParValue))
#define u8GetPNGSOFHL(ch) (pst_u8PNGSOF(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGSOFHH(ch,ParValue) (pst_u8PNGSOF(ch) -> u8HH = (ParValue))
#define u8GetPNGSOFHH(ch) (pst_u8PNGSOF(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGSOFL(ch,ParValue) (pst_u16PNGSOF(ch) -> u16L = (ParValue))
#define u16GetPNGSOFL(ch) (pst_u16PNGSOF(ch) -> u16L)
#define vSetPNGSOFH(ch,ParValue) (pst_u16PNGSOF(ch) -> u16H = (ParValue))
#define u16GetPNGSOFH(ch) (pst_u16PNGSOF(ch) -> u16H)
            
/* Word access */
#define vSetPNGSOF(ch,ParValue)  (*pu32PNGSOF(ch) = (ParValue))
#define u32GetPNGSOF(ch)  (*pu32PNGSOF(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSSTAT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04088                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSSTAT_REG__       0xC0C04088U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PHASE	:1; 	 /* 0..0  bit(s) R */
  uint32_t   PTL	:1; 	 /* 1..1  bit(s) R */
  uint32_t   CHUNK	:2; 	 /* 2..3  bit(s) R */
  uint32_t   RSRVD4	:3; 	 /* 4..6  bit(s) R */
  uint32_t   NPE	:9; 	 /* 7..15  bit(s) R */
  uint32_t   NIDAT	:12; 	 /* 16..27  bit(s) R */ 
  uint32_t   RSRVD28	:4; 	 /* 28..31  bit(s) R */                    
} PNGSSTAT_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSSTAT_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSSTAT_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSSTAT_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSSTAT(ch)     ((volatile PNGSSTAT_bit_view_st *)\
(PNGSSTAT_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSSTAT(ch)     ((volatile PNGSSTAT_byte_view_st *)\
(PNGSSTAT_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSSTAT(ch)     ((volatile PNGSSTAT_halfword_view_st *)\
(PNGSSTAT_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSSTAT(ch)     ((volatile u32PNGSSTAT_word_view *)\
(PNGSSTAT_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSSTAT_PHASE(ch) (pst_bitPNGSSTAT(ch) -> PHASE)            
#define biGetPNGSSTAT_PTL(ch) (pst_bitPNGSSTAT(ch) -> PTL)            
#define biGetPNGSSTAT_CHUNK(ch) (pst_bitPNGSSTAT(ch) -> CHUNK)            
#define biGetPNGSSTAT_RSRVD4(ch) (pst_bitPNGSSTAT(ch) -> RSRVD4)            
#define biGetPNGSSTAT_NPE(ch) (pst_bitPNGSSTAT(ch) -> NPE)            
#define biGetPNGSSTAT_NIDAT(ch) (pst_bitPNGSSTAT(ch) -> NIDAT)            
#define biGetPNGSSTAT_RSRVD28(ch) (pst_bitPNGSSTAT(ch) -> RSRVD28)
            
/* LL-struct byte access */

#define u8GetPNGSSTATLL(ch) (pst_u8PNGSSTAT(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSSTATLH(ch) (pst_u8PNGSSTAT(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSSTATHL(ch) (pst_u8PNGSSTAT(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSSTATHH(ch) (pst_u8PNGSSTAT(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSSTATL(ch) (pst_u16PNGSSTAT(ch) -> u16L)

#define u16GetPNGSSTATH(ch) (pst_u16PNGSSTAT(ch) -> u16H)
            
/* Word access */

#define u32GetPNGSSTAT(ch)  (*pu32PNGSSTAT(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSIHDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0408C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSIHDR_REG__       0xC0C0408CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   BITDEPTH	:5; 	 /* 0..4  bit(s) R */
  uint32_t   CLRTYP	:3; 	 /* 5..7  bit(s) R */
  uint32_t   CMPMTH	:8; 	 /* 8..15  bit(s) R */
  uint32_t   FLTMTH	:8; 	 /* 16..23  bit(s) R */ 
  uint32_t   INTMTH	:8; 	 /* 24..31  bit(s) R */                    
} PNGSIHDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSIHDR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSIHDR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSIHDR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSIHDR(ch)     ((volatile PNGSIHDR_bit_view_st *)\
(PNGSIHDR_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSIHDR(ch)     ((volatile PNGSIHDR_byte_view_st *)\
(PNGSIHDR_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSIHDR(ch)     ((volatile PNGSIHDR_halfword_view_st *)\
(PNGSIHDR_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSIHDR(ch)     ((volatile u32PNGSIHDR_word_view *)\
(PNGSIHDR_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSIHDR_BITDEPTH(ch) (pst_bitPNGSIHDR(ch) -> BITDEPTH)            
#define biGetPNGSIHDR_CLRTYP(ch) (pst_bitPNGSIHDR(ch) -> CLRTYP)            
#define biGetPNGSIHDR_CMPMTH(ch) (pst_bitPNGSIHDR(ch) -> CMPMTH)            
#define biGetPNGSIHDR_FLTMTH(ch) (pst_bitPNGSIHDR(ch) -> FLTMTH)            
#define biGetPNGSIHDR_INTMTH(ch) (pst_bitPNGSIHDR(ch) -> INTMTH)
            
/* LL-struct byte access */

#define u8GetPNGSIHDRLL(ch) (pst_u8PNGSIHDR(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSIHDRLH(ch) (pst_u8PNGSIHDR(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSIHDRHL(ch) (pst_u8PNGSIHDR(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSIHDRHH(ch) (pst_u8PNGSIHDR(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSIHDRL(ch) (pst_u16PNGSIHDR(ch) -> u16L)

#define u16GetPNGSIHDRH(ch) (pst_u16PNGSIHDR(ch) -> u16H)
            
/* Word access */

#define u32GetPNGSIHDR(ch)  (*pu32PNGSIHDR(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSZHDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04090                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSZHDR_REG__       0xC0C04090U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CM	:4; 	 /* 0..3  bit(s) R */
  uint32_t   CINFO	:4; 	 /* 4..7  bit(s) R */
  uint32_t   FCHECK	:5; 	 /* 8..12  bit(s) R */
  uint32_t   FDICT	:1; 	 /* 13..13  bit(s) R */
  uint32_t   FLEVEL	:2; 	 /* 14..15  bit(s) R */ 
  uint32_t   RSRVD16	:16; 	 /* 16..31  bit(s) R */                    
} PNGSZHDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSZHDR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSZHDR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSZHDR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSZHDR(ch)     ((volatile PNGSZHDR_bit_view_st *)\
(PNGSZHDR_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSZHDR(ch)     ((volatile PNGSZHDR_byte_view_st *)\
(PNGSZHDR_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSZHDR(ch)     ((volatile PNGSZHDR_halfword_view_st *)\
(PNGSZHDR_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSZHDR(ch)     ((volatile u32PNGSZHDR_word_view *)\
(PNGSZHDR_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSZHDR_CM(ch) (pst_bitPNGSZHDR(ch) -> CM)            
#define biGetPNGSZHDR_CINFO(ch) (pst_bitPNGSZHDR(ch) -> CINFO)            
#define biGetPNGSZHDR_FCHECK(ch) (pst_bitPNGSZHDR(ch) -> FCHECK)            
#define biGetPNGSZHDR_FDICT(ch) (pst_bitPNGSZHDR(ch) -> FDICT)            
#define biGetPNGSZHDR_FLEVEL(ch) (pst_bitPNGSZHDR(ch) -> FLEVEL)            
#define biGetPNGSZHDR_RSRVD16(ch) (pst_bitPNGSZHDR(ch) -> RSRVD16)
            
/* LL-struct byte access */

#define u8GetPNGSZHDRLL(ch) (pst_u8PNGSZHDR(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSZHDRLH(ch) (pst_u8PNGSZHDR(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSZHDRHL(ch) (pst_u8PNGSZHDR(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSZHDRHH(ch) (pst_u8PNGSZHDR(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSZHDRL(ch) (pst_u16PNGSZHDR(ch) -> u16L)

#define u16GetPNGSZHDRH(ch) (pst_u16PNGSZHDR(ch) -> u16H)
            
/* Word access */

#define u32GetPNGSZHDR(ch)  (*pu32PNGSZHDR(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSH                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04094                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSH_REG__       0xC0C04094U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   HEIGHT	:32; 	 /* 0..31  bit(s) R */                    
} PNGSH_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSH_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSH_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSH_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSH(ch)     ((volatile PNGSH_bit_view_st *)\
(PNGSH_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSH(ch)     ((volatile PNGSH_byte_view_st *)\
(PNGSH_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSH(ch)     ((volatile PNGSH_halfword_view_st *)\
(PNGSH_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSH(ch)     ((volatile u32PNGSH_word_view *)\
(PNGSH_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSH_HEIGHT(ch) (pst_bitPNGSH(ch) -> HEIGHT)
            
/* LL-struct byte access */

#define u8GetPNGSHLL(ch) (pst_u8PNGSH(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSHLH(ch) (pst_u8PNGSH(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSHHL(ch) (pst_u8PNGSH(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSHHH(ch) (pst_u8PNGSH(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSHL(ch) (pst_u16PNGSH(ch) -> u16L)

#define u16GetPNGSHH(ch) (pst_u16PNGSH(ch) -> u16H)
            
/* Word access */

#define u32GetPNGSH(ch)  (*pu32PNGSH(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSW                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04098                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSW_REG__       0xC0C04098U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   WIDTH	:32; 	 /* 0..31  bit(s) R */                    
} PNGSW_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSW_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSW_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSW_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSW(ch)     ((volatile PNGSW_bit_view_st *)\
(PNGSW_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSW(ch)     ((volatile PNGSW_byte_view_st *)\
(PNGSW_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSW(ch)     ((volatile PNGSW_halfword_view_st *)\
(PNGSW_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSW(ch)     ((volatile u32PNGSW_word_view *)\
(PNGSW_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSW_WIDTH(ch) (pst_bitPNGSW(ch) -> WIDTH)
            
/* LL-struct byte access */

#define u8GetPNGSWLL(ch) (pst_u8PNGSW(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSWLH(ch) (pst_u8PNGSW(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSWHL(ch) (pst_u8PNGSW(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSWHH(ch) (pst_u8PNGSW(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSWL(ch) (pst_u16PNGSW(ch) -> u16L)

#define u16GetPNGSWH(ch) (pst_u16PNGSW(ch) -> u16H)
            
/* Word access */

#define u32GetPNGSW(ch)  (*pu32PNGSW(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGDSFLVL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0409C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGDSFLVL_REG__       0xC0C0409CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DSFLEVEL	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   RSRVD8	:24; 	 /* 8..31  bit(s) R */                    
} PNGDSFLVL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGDSFLVL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGDSFLVL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGDSFLVL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGDSFLVL(ch)     ((volatile PNGDSFLVL_bit_view_st *)\
(PNGDSFLVL_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGDSFLVL(ch)     ((volatile PNGDSFLVL_byte_view_st *)\
(PNGDSFLVL_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGDSFLVL(ch)     ((volatile PNGDSFLVL_halfword_view_st *)\
(PNGDSFLVL_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGDSFLVL(ch)     ((volatile u32PNGDSFLVL_word_view *)\
(PNGDSFLVL_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGDSFLVL_DSFLEVEL(ch) (pst_bitPNGDSFLVL(ch) -> DSFLEVEL)            
#define biGetPNGDSFLVL_RSRVD8(ch) (pst_bitPNGDSFLVL(ch) -> RSRVD8)
            
/* LL-struct byte access */

#define u8GetPNGDSFLVLLL(ch) (pst_u8PNGDSFLVL(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGDSFLVLLH(ch) (pst_u8PNGDSFLVL(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGDSFLVLHL(ch) (pst_u8PNGDSFLVL(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGDSFLVLHH(ch) (pst_u8PNGDSFLVL(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGDSFLVLL(ch) (pst_u16PNGDSFLVL(ch) -> u16L)

#define u16GetPNGDSFLVLH(ch) (pst_u16PNGDSFLVL(ch) -> u16H)
            
/* Word access */

#define u32GetPNGDSFLVL(ch)  (*pu32PNGDSFLVL(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSSBSA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040A0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSSBSA_REG__       0xC0C040A0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   SA	:32; 	 /* 0..31  bit(s) R/W */                    
} PNGSSBSA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSSBSA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSSBSA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSSBSA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSSBSA(ch)     ((volatile PNGSSBSA_bit_view_st *)\
(PNGSSBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSSBSA(ch)     ((volatile PNGSSBSA_byte_view_st *)\
(PNGSSBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSSBSA(ch)     ((volatile PNGSSBSA_halfword_view_st *)\
(PNGSSBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSSBSA(ch)     ((volatile u32PNGSSBSA_word_view *)\
(PNGSSBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGSSBSA_SA(ch) (pst_bitPNGSSBSA(ch) -> SA)
#define vSetPNGSSBSA_SA(ch,ParValue)  (pst_bitPNGSSBSA(ch) -> SA=(ParValue))
            
/* LL-struct byte access */
#define vSetPNGSSBSALL(ch,ParValue) (pst_u8PNGSSBSA(ch) -> u8LL = (ParValue))
#define u8GetPNGSSBSALL(ch) (pst_u8PNGSSBSA(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGSSBSALH(ch,ParValue) (pst_u8PNGSSBSA(ch) -> u8LH = (ParValue))
#define u8GetPNGSSBSALH(ch) (pst_u8PNGSSBSA(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGSSBSAHL(ch,ParValue) (pst_u8PNGSSBSA(ch) -> u8HL = (ParValue))
#define u8GetPNGSSBSAHL(ch) (pst_u8PNGSSBSA(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGSSBSAHH(ch,ParValue) (pst_u8PNGSSBSA(ch) -> u8HH = (ParValue))
#define u8GetPNGSSBSAHH(ch) (pst_u8PNGSSBSA(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGSSBSAL(ch,ParValue) (pst_u16PNGSSBSA(ch) -> u16L = (ParValue))
#define u16GetPNGSSBSAL(ch) (pst_u16PNGSSBSA(ch) -> u16L)
#define vSetPNGSSBSAH(ch,ParValue) (pst_u16PNGSSBSA(ch) -> u16H = (ParValue))
#define u16GetPNGSSBSAH(ch) (pst_u16PNGSSBSA(ch) -> u16H)
            
/* Word access */
#define vSetPNGSSBSA(ch,ParValue)  (*pu32PNGSSBSA(ch) = (ParValue))
#define u32GetPNGSSBSA(ch)  (*pu32PNGSSBSA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSWBSA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040A4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSWBSA_REG__       0xC0C040A4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   SA	:32; 	 /* 0..31  bit(s) R/W */                    
} PNGSWBSA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSWBSA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSWBSA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSWBSA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSWBSA(ch)     ((volatile PNGSWBSA_bit_view_st *)\
(PNGSWBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSWBSA(ch)     ((volatile PNGSWBSA_byte_view_st *)\
(PNGSWBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSWBSA(ch)     ((volatile PNGSWBSA_halfword_view_st *)\
(PNGSWBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSWBSA(ch)     ((volatile u32PNGSWBSA_word_view *)\
(PNGSWBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGSWBSA_SA(ch) (pst_bitPNGSWBSA(ch) -> SA)
#define vSetPNGSWBSA_SA(ch,ParValue)  (pst_bitPNGSWBSA(ch) -> SA=(ParValue))
            
/* LL-struct byte access */
#define vSetPNGSWBSALL(ch,ParValue) (pst_u8PNGSWBSA(ch) -> u8LL = (ParValue))
#define u8GetPNGSWBSALL(ch) (pst_u8PNGSWBSA(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGSWBSALH(ch,ParValue) (pst_u8PNGSWBSA(ch) -> u8LH = (ParValue))
#define u8GetPNGSWBSALH(ch) (pst_u8PNGSWBSA(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGSWBSAHL(ch,ParValue) (pst_u8PNGSWBSA(ch) -> u8HL = (ParValue))
#define u8GetPNGSWBSAHL(ch) (pst_u8PNGSWBSA(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGSWBSAHH(ch,ParValue) (pst_u8PNGSWBSA(ch) -> u8HH = (ParValue))
#define u8GetPNGSWBSAHH(ch) (pst_u8PNGSWBSA(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGSWBSAL(ch,ParValue) (pst_u16PNGSWBSA(ch) -> u16L = (ParValue))
#define u16GetPNGSWBSAL(ch) (pst_u16PNGSWBSA(ch) -> u16L)
#define vSetPNGSWBSAH(ch,ParValue) (pst_u16PNGSWBSA(ch) -> u16H = (ParValue))
#define u16GetPNGSWBSAH(ch) (pst_u16PNGSWBSA(ch) -> u16H)
            
/* Word access */
#define vSetPNGSWBSA(ch,ParValue)  (*pu32PNGSWBSA(ch) = (ParValue))
#define u32GetPNGSWBSA(ch)  (*pu32PNGSWBSA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGFSBSA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040A8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGFSBSA_REG__       0xC0C040A8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   SA	:32; 	 /* 0..31  bit(s) R/W */                    
} PNGFSBSA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGFSBSA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGFSBSA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGFSBSA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGFSBSA(ch)     ((volatile PNGFSBSA_bit_view_st *)\
(PNGFSBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGFSBSA(ch)     ((volatile PNGFSBSA_byte_view_st *)\
(PNGFSBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGFSBSA(ch)     ((volatile PNGFSBSA_halfword_view_st *)\
(PNGFSBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGFSBSA(ch)     ((volatile u32PNGFSBSA_word_view *)\
(PNGFSBSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGFSBSA_SA(ch) (pst_bitPNGFSBSA(ch) -> SA)
#define vSetPNGFSBSA_SA(ch,ParValue)  (pst_bitPNGFSBSA(ch) -> SA=(ParValue))
            
/* LL-struct byte access */
#define vSetPNGFSBSALL(ch,ParValue) (pst_u8PNGFSBSA(ch) -> u8LL = (ParValue))
#define u8GetPNGFSBSALL(ch) (pst_u8PNGFSBSA(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGFSBSALH(ch,ParValue) (pst_u8PNGFSBSA(ch) -> u8LH = (ParValue))
#define u8GetPNGFSBSALH(ch) (pst_u8PNGFSBSA(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGFSBSAHL(ch,ParValue) (pst_u8PNGFSBSA(ch) -> u8HL = (ParValue))
#define u8GetPNGFSBSAHL(ch) (pst_u8PNGFSBSA(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGFSBSAHH(ch,ParValue) (pst_u8PNGFSBSA(ch) -> u8HH = (ParValue))
#define u8GetPNGFSBSAHH(ch) (pst_u8PNGFSBSA(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGFSBSAL(ch,ParValue) (pst_u16PNGFSBSA(ch) -> u16L = (ParValue))
#define u16GetPNGFSBSAL(ch) (pst_u16PNGFSBSA(ch) -> u16L)
#define vSetPNGFSBSAH(ch,ParValue) (pst_u16PNGFSBSA(ch) -> u16H = (ParValue))
#define u16GetPNGFSBSAH(ch) (pst_u16PNGFSBSA(ch) -> u16H)
            
/* Word access */
#define vSetPNGFSBSA(ch,ParValue)  (*pu32PNGFSBSA(ch) = (ParValue))
#define u32GetPNGFSBSA(ch)  (*pu32PNGFSBSA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGDSVSA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040AC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGDSVSA_REG__       0xC0C040ACU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   SA	:32; 	 /* 0..31  bit(s) R/W */                    
} PNGDSVSA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGDSVSA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGDSVSA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGDSVSA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGDSVSA(ch)     ((volatile PNGDSVSA_bit_view_st *)\
(PNGDSVSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGDSVSA(ch)     ((volatile PNGDSVSA_byte_view_st *)\
(PNGDSVSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGDSVSA(ch)     ((volatile PNGDSVSA_halfword_view_st *)\
(PNGDSVSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGDSVSA(ch)     ((volatile u32PNGDSVSA_word_view *)\
(PNGDSVSA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGDSVSA_SA(ch) (pst_bitPNGDSVSA(ch) -> SA)
#define vSetPNGDSVSA_SA(ch,ParValue)  (pst_bitPNGDSVSA(ch) -> SA=(ParValue))
            
/* LL-struct byte access */
#define vSetPNGDSVSALL(ch,ParValue) (pst_u8PNGDSVSA(ch) -> u8LL = (ParValue))
#define u8GetPNGDSVSALL(ch) (pst_u8PNGDSVSA(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGDSVSALH(ch,ParValue) (pst_u8PNGDSVSA(ch) -> u8LH = (ParValue))
#define u8GetPNGDSVSALH(ch) (pst_u8PNGDSVSA(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGDSVSAHL(ch,ParValue) (pst_u8PNGDSVSA(ch) -> u8HL = (ParValue))
#define u8GetPNGDSVSAHL(ch) (pst_u8PNGDSVSA(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGDSVSAHH(ch,ParValue) (pst_u8PNGDSVSA(ch) -> u8HH = (ParValue))
#define u8GetPNGDSVSAHH(ch) (pst_u8PNGDSVSA(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGDSVSAL(ch,ParValue) (pst_u16PNGDSVSA(ch) -> u16L = (ParValue))
#define u16GetPNGDSVSAL(ch) (pst_u16PNGDSVSA(ch) -> u16L)
#define vSetPNGDSVSAH(ch,ParValue) (pst_u16PNGDSVSA(ch) -> u16H = (ParValue))
#define u16GetPNGDSVSAH(ch) (pst_u16PNGDSVSA(ch) -> u16H)
            
/* Word access */
#define vSetPNGDSVSA(ch,ParValue)  (*pu32PNGDSVSA(ch) = (ParValue))
#define u32GetPNGDSVSA(ch)  (*pu32PNGDSVSA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGDSVEA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040B0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGDSVEA_REG__       0xC0C040B0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   EA	:32; 	 /* 0..31  bit(s) R/W */                    
} PNGDSVEA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGDSVEA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGDSVEA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGDSVEA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGDSVEA(ch)     ((volatile PNGDSVEA_bit_view_st *)\
(PNGDSVEA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGDSVEA(ch)     ((volatile PNGDSVEA_byte_view_st *)\
(PNGDSVEA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGDSVEA(ch)     ((volatile PNGDSVEA_halfword_view_st *)\
(PNGDSVEA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGDSVEA(ch)     ((volatile u32PNGDSVEA_word_view *)\
(PNGDSVEA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGDSVEA_EA(ch) (pst_bitPNGDSVEA(ch) -> EA)
#define vSetPNGDSVEA_EA(ch,ParValue)  (pst_bitPNGDSVEA(ch) -> EA=(ParValue))
            
/* LL-struct byte access */
#define vSetPNGDSVEALL(ch,ParValue) (pst_u8PNGDSVEA(ch) -> u8LL = (ParValue))
#define u8GetPNGDSVEALL(ch) (pst_u8PNGDSVEA(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGDSVEALH(ch,ParValue) (pst_u8PNGDSVEA(ch) -> u8LH = (ParValue))
#define u8GetPNGDSVEALH(ch) (pst_u8PNGDSVEA(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGDSVEAHL(ch,ParValue) (pst_u8PNGDSVEA(ch) -> u8HL = (ParValue))
#define u8GetPNGDSVEAHL(ch) (pst_u8PNGDSVEA(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGDSVEAHH(ch,ParValue) (pst_u8PNGDSVEA(ch) -> u8HH = (ParValue))
#define u8GetPNGDSVEAHH(ch) (pst_u8PNGDSVEA(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGDSVEAL(ch,ParValue) (pst_u16PNGDSVEA(ch) -> u16L = (ParValue))
#define u16GetPNGDSVEAL(ch) (pst_u16PNGDSVEA(ch) -> u16L)
#define vSetPNGDSVEAH(ch,ParValue) (pst_u16PNGDSVEA(ch) -> u16H = (ParValue))
#define u16GetPNGDSVEAH(ch) (pst_u16PNGDSVEA(ch) -> u16H)
            
/* Word access */
#define vSetPNGDSVEA(ch,ParValue)  (*pu32PNGDSVEA(ch) = (ParValue))
#define u32GetPNGDSVEA(ch)  (*pu32PNGDSVEA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSSBCA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040B4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSSBCA_REG__       0xC0C040B4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   CA	:32; 	 /* 0..31  bit(s) R */                    
} PNGSSBCA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSSBCA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSSBCA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSSBCA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSSBCA(ch)     ((volatile PNGSSBCA_bit_view_st *)\
(PNGSSBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSSBCA(ch)     ((volatile PNGSSBCA_byte_view_st *)\
(PNGSSBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSSBCA(ch)     ((volatile PNGSSBCA_halfword_view_st *)\
(PNGSSBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSSBCA(ch)     ((volatile u32PNGSSBCA_word_view *)\
(PNGSSBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSSBCA_CA(ch) (pst_bitPNGSSBCA(ch) -> CA)
            
/* LL-struct byte access */

#define u8GetPNGSSBCALL(ch) (pst_u8PNGSSBCA(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSSBCALH(ch) (pst_u8PNGSSBCA(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSSBCAHL(ch) (pst_u8PNGSSBCA(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSSBCAHH(ch) (pst_u8PNGSSBCA(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSSBCAL(ch) (pst_u16PNGSSBCA(ch) -> u16L)

#define u16GetPNGSSBCAH(ch) (pst_u16PNGSSBCA(ch) -> u16H)
            
/* Word access */

#define u32GetPNGSSBCA(ch)  (*pu32PNGSSBCA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSWBCA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040B8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSWBCA_REG__       0xC0C040B8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   CA	:32; 	 /* 0..31  bit(s) R */                    
} PNGSWBCA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSWBCA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSWBCA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSWBCA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSWBCA(ch)     ((volatile PNGSWBCA_bit_view_st *)\
(PNGSWBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSWBCA(ch)     ((volatile PNGSWBCA_byte_view_st *)\
(PNGSWBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSWBCA(ch)     ((volatile PNGSWBCA_halfword_view_st *)\
(PNGSWBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSWBCA(ch)     ((volatile u32PNGSWBCA_word_view *)\
(PNGSWBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSWBCA_CA(ch) (pst_bitPNGSWBCA(ch) -> CA)
            
/* LL-struct byte access */

#define u8GetPNGSWBCALL(ch) (pst_u8PNGSWBCA(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSWBCALH(ch) (pst_u8PNGSWBCA(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSWBCAHL(ch) (pst_u8PNGSWBCA(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSWBCAHH(ch) (pst_u8PNGSWBCA(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSWBCAL(ch) (pst_u16PNGSWBCA(ch) -> u16L)

#define u16GetPNGSWBCAH(ch) (pst_u16PNGSWBCA(ch) -> u16H)
            
/* Word access */

#define u32GetPNGSWBCA(ch)  (*pu32PNGSWBCA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGFSBCA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040BC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGFSBCA_REG__       0xC0C040BCU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   CA	:32; 	 /* 0..31  bit(s) R */                    
} PNGFSBCA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGFSBCA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGFSBCA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGFSBCA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGFSBCA(ch)     ((volatile PNGFSBCA_bit_view_st *)\
(PNGFSBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGFSBCA(ch)     ((volatile PNGFSBCA_byte_view_st *)\
(PNGFSBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGFSBCA(ch)     ((volatile PNGFSBCA_halfword_view_st *)\
(PNGFSBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGFSBCA(ch)     ((volatile u32PNGFSBCA_word_view *)\
(PNGFSBCA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGFSBCA_CA(ch) (pst_bitPNGFSBCA(ch) -> CA)
            
/* LL-struct byte access */

#define u8GetPNGFSBCALL(ch) (pst_u8PNGFSBCA(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGFSBCALH(ch) (pst_u8PNGFSBCA(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGFSBCAHL(ch) (pst_u8PNGFSBCA(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGFSBCAHH(ch) (pst_u8PNGFSBCA(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGFSBCAL(ch) (pst_u16PNGFSBCA(ch) -> u16L)

#define u16GetPNGFSBCAH(ch) (pst_u16PNGFSBCA(ch) -> u16H)
            
/* Word access */

#define u32GetPNGFSBCA(ch)  (*pu32PNGFSBCA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGDSCVA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040C0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGDSCVA_REG__       0xC0C040C0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   CA	:32; 	 /* 0..31  bit(s) R */                    
} PNGDSCVA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGDSCVA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGDSCVA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGDSCVA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGDSCVA(ch)     ((volatile PNGDSCVA_bit_view_st *)\
(PNGDSCVA_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGDSCVA(ch)     ((volatile PNGDSCVA_byte_view_st *)\
(PNGDSCVA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGDSCVA(ch)     ((volatile PNGDSCVA_halfword_view_st *)\
(PNGDSCVA_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGDSCVA(ch)     ((volatile u32PNGDSCVA_word_view *)\
(PNGDSCVA_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGDSCVA_CA(ch) (pst_bitPNGDSCVA(ch) -> CA)
            
/* LL-struct byte access */

#define u8GetPNGDSCVALL(ch) (pst_u8PNGDSCVA(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGDSCVALH(ch) (pst_u8PNGDSCVA(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGDSCVAHL(ch) (pst_u8PNGDSCVA(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGDSCVAHH(ch) (pst_u8PNGDSCVA(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGDSCVAL(ch) (pst_u16PNGDSCVA(ch) -> u16L)

#define u16GetPNGDSCVAH(ch) (pst_u16PNGDSCVA(ch) -> u16H)
            
/* Word access */

#define u32GetPNGDSCVA(ch)  (*pu32PNGDSCVA(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSINTE                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040C4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSINTE_REG__       0xC0C040C4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   BJMPEIE	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   UFMTEIE	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   OOCEIE	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   CHSEIE	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   EYEOSEIE	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   NOEOSEIE	:1; 	 /* 5..5  bit(s) R/W */
  uint32_t   CMPEIE	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   BTYPEEIE	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   DISTEIE	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   NCBSEIE	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   DECEIE	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   RSRVD11	:5; 	 /* 11..15  bit(s) R */
  uint32_t   FJMPWIE	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   UCHNKWIE	:1; 	 /* 17..17  bit(s) R/W */
  uint32_t   PDICTWIE	:1; 	 /* 18..18  bit(s) R/W */
  uint32_t   ULLWIE	:1; 	 /* 19..19  bit(s) R/W */
  uint32_t   UDISTWIE	:1; 	 /* 20..20  bit(s) R/W */
  uint32_t   OFCWIE	:1; 	 /* 21..21  bit(s) R/W */
  uint32_t   RSRVD22	:2; 	 /* 22..23  bit(s) R */
  uint32_t   IHDRDIE	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   PLTEDIE	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   IDATDIE	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   IENDDIE	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   DCDSIE	:1; 	 /* 28..28  bit(s) R/W */
  uint32_t   SIDLEIE	:1; 	 /* 29..29  bit(s) R/W */
  uint32_t   DSFFULLIE	:1; 	 /* 30..30  bit(s) R/W */ 
  uint32_t   RSRVD31	:1; 	 /* 31..31  bit(s) R */                    
} PNGSINTE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSINTE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSINTE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSINTE_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSINTE(ch)     ((volatile PNGSINTE_bit_view_st *)\
(PNGSINTE_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSINTE(ch)     ((volatile PNGSINTE_byte_view_st *)\
(PNGSINTE_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSINTE(ch)     ((volatile PNGSINTE_halfword_view_st *)\
(PNGSINTE_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSINTE(ch)     ((volatile u32PNGSINTE_word_view *)\
(PNGSINTE_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGSINTE_BJMPEIE(ch) (pst_bitPNGSINTE(ch) -> BJMPEIE)
#define vSetPNGSINTE_BJMPEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> BJMPEIE=(ParValue))
#define biGetPNGSINTE_UFMTEIE(ch) (pst_bitPNGSINTE(ch) -> UFMTEIE)
#define vSetPNGSINTE_UFMTEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> UFMTEIE=(ParValue))
#define biGetPNGSINTE_OOCEIE(ch) (pst_bitPNGSINTE(ch) -> OOCEIE)
#define vSetPNGSINTE_OOCEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> OOCEIE=(ParValue))
#define biGetPNGSINTE_CHSEIE(ch) (pst_bitPNGSINTE(ch) -> CHSEIE)
#define vSetPNGSINTE_CHSEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> CHSEIE=(ParValue))
#define biGetPNGSINTE_EYEOSEIE(ch) (pst_bitPNGSINTE(ch) -> EYEOSEIE)
#define vSetPNGSINTE_EYEOSEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> EYEOSEIE=(ParValue))
#define biGetPNGSINTE_NOEOSEIE(ch) (pst_bitPNGSINTE(ch) -> NOEOSEIE)
#define vSetPNGSINTE_NOEOSEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> NOEOSEIE=(ParValue))
#define biGetPNGSINTE_CMPEIE(ch) (pst_bitPNGSINTE(ch) -> CMPEIE)
#define vSetPNGSINTE_CMPEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> CMPEIE=(ParValue))
#define biGetPNGSINTE_BTYPEEIE(ch) (pst_bitPNGSINTE(ch) -> BTYPEEIE)
#define vSetPNGSINTE_BTYPEEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> BTYPEEIE=(ParValue))
#define biGetPNGSINTE_DISTEIE(ch) (pst_bitPNGSINTE(ch) -> DISTEIE)
#define vSetPNGSINTE_DISTEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> DISTEIE=(ParValue))
#define biGetPNGSINTE_NCBSEIE(ch) (pst_bitPNGSINTE(ch) -> NCBSEIE)
#define vSetPNGSINTE_NCBSEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> NCBSEIE=(ParValue))
#define biGetPNGSINTE_DECEIE(ch) (pst_bitPNGSINTE(ch) -> DECEIE)
#define vSetPNGSINTE_DECEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> DECEIE=(ParValue))            
#define biGetPNGSINTE_RSRVD11(ch) (pst_bitPNGSINTE(ch) -> RSRVD11)
#define biGetPNGSINTE_FJMPWIE(ch) (pst_bitPNGSINTE(ch) -> FJMPWIE)
#define vSetPNGSINTE_FJMPWIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> FJMPWIE=(ParValue))
#define biGetPNGSINTE_UCHNKWIE(ch) (pst_bitPNGSINTE(ch) -> UCHNKWIE)
#define vSetPNGSINTE_UCHNKWIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> UCHNKWIE=(ParValue))
#define biGetPNGSINTE_PDICTWIE(ch) (pst_bitPNGSINTE(ch) -> PDICTWIE)
#define vSetPNGSINTE_PDICTWIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> PDICTWIE=(ParValue))
#define biGetPNGSINTE_ULLWIE(ch) (pst_bitPNGSINTE(ch) -> ULLWIE)
#define vSetPNGSINTE_ULLWIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> ULLWIE=(ParValue))
#define biGetPNGSINTE_UDISTWIE(ch) (pst_bitPNGSINTE(ch) -> UDISTWIE)
#define vSetPNGSINTE_UDISTWIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> UDISTWIE=(ParValue))
#define biGetPNGSINTE_OFCWIE(ch) (pst_bitPNGSINTE(ch) -> OFCWIE)
#define vSetPNGSINTE_OFCWIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> OFCWIE=(ParValue))            
#define biGetPNGSINTE_RSRVD22(ch) (pst_bitPNGSINTE(ch) -> RSRVD22)
#define biGetPNGSINTE_IHDRDIE(ch) (pst_bitPNGSINTE(ch) -> IHDRDIE)
#define vSetPNGSINTE_IHDRDIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> IHDRDIE=(ParValue))
#define biGetPNGSINTE_PLTEDIE(ch) (pst_bitPNGSINTE(ch) -> PLTEDIE)
#define vSetPNGSINTE_PLTEDIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> PLTEDIE=(ParValue))
#define biGetPNGSINTE_IDATDIE(ch) (pst_bitPNGSINTE(ch) -> IDATDIE)
#define vSetPNGSINTE_IDATDIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> IDATDIE=(ParValue))
#define biGetPNGSINTE_IENDDIE(ch) (pst_bitPNGSINTE(ch) -> IENDDIE)
#define vSetPNGSINTE_IENDDIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> IENDDIE=(ParValue))
#define biGetPNGSINTE_DCDSIE(ch) (pst_bitPNGSINTE(ch) -> DCDSIE)
#define vSetPNGSINTE_DCDSIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> DCDSIE=(ParValue))
#define biGetPNGSINTE_SIDLEIE(ch) (pst_bitPNGSINTE(ch) -> SIDLEIE)
#define vSetPNGSINTE_SIDLEIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> SIDLEIE=(ParValue))
#define biGetPNGSINTE_DSFFULLIE(ch) (pst_bitPNGSINTE(ch) -> DSFFULLIE)
#define vSetPNGSINTE_DSFFULLIE(ch,ParValue)  (pst_bitPNGSINTE(ch) -> DSFFULLIE=(ParValue))            
#define biGetPNGSINTE_RSRVD31(ch) (pst_bitPNGSINTE(ch) -> RSRVD31)
            
/* LL-struct byte access */
#define vSetPNGSINTELL(ch,ParValue) (pst_u8PNGSINTE(ch) -> u8LL = (ParValue))
#define u8GetPNGSINTELL(ch) (pst_u8PNGSINTE(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGSINTELH(ch,ParValue) (pst_u8PNGSINTE(ch) -> u8LH = (ParValue))
#define u8GetPNGSINTELH(ch) (pst_u8PNGSINTE(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGSINTEHL(ch,ParValue) (pst_u8PNGSINTE(ch) -> u8HL = (ParValue))
#define u8GetPNGSINTEHL(ch) (pst_u8PNGSINTE(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGSINTEHH(ch,ParValue) (pst_u8PNGSINTE(ch) -> u8HH = (ParValue))
#define u8GetPNGSINTEHH(ch) (pst_u8PNGSINTE(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGSINTEL(ch,ParValue) (pst_u16PNGSINTE(ch) -> u16L = (ParValue))
#define u16GetPNGSINTEL(ch) (pst_u16PNGSINTE(ch) -> u16L)
#define vSetPNGSINTEH(ch,ParValue) (pst_u16PNGSINTE(ch) -> u16H = (ParValue))
#define u16GetPNGSINTEH(ch) (pst_u16PNGSINTE(ch) -> u16H)
            
/* Word access */
#define vSetPNGSINTE(ch,ParValue)  (*pu32PNGSINTE(ch) = (ParValue))
#define u32GetPNGSINTE(ch)  (*pu32PNGSINTE(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSINTS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040C8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSINTS_REG__       0xC0C040C8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   BJMPEIS	:1; 	 /* 0..0  bit(s) R */
  uint32_t   UFMTEIS	:1; 	 /* 1..1  bit(s) R */
  uint32_t   OOCEIS	:1; 	 /* 2..2  bit(s) R */
  uint32_t   CHSEIS	:1; 	 /* 3..3  bit(s) R */
  uint32_t   EYEOSEIS	:1; 	 /* 4..4  bit(s) R */
  uint32_t   NOEOSEIS	:1; 	 /* 5..5  bit(s) R */
  uint32_t   CMPEIS	:1; 	 /* 6..6  bit(s) R */
  uint32_t   BTYPEEIS	:1; 	 /* 7..7  bit(s) R */
  uint32_t   DISTEIS	:1; 	 /* 8..8  bit(s) R */
  uint32_t   NCBSEIS	:1; 	 /* 9..9  bit(s) R */
  uint32_t   DECEIS	:1; 	 /* 10..10  bit(s) R */
  uint32_t   RSRVD11	:5; 	 /* 11..15  bit(s) R */
  uint32_t   FJMPWIS	:1; 	 /* 16..16  bit(s) R */
  uint32_t   UCHNKWIS	:1; 	 /* 17..17  bit(s) R */
  uint32_t   PDICTWIS	:1; 	 /* 18..18  bit(s) R */
  uint32_t   ULLWIS	:1; 	 /* 19..19  bit(s) R */
  uint32_t   UDISTWIS	:1; 	 /* 20..20  bit(s) R */
  uint32_t   OFCWIS	:1; 	 /* 21..21  bit(s) R */
  uint32_t   RSRVD22	:2; 	 /* 22..23  bit(s) R */
  uint32_t   IHDRDIS	:1; 	 /* 24..24  bit(s) R */
  uint32_t   PLTEDIS	:1; 	 /* 25..25  bit(s) R */
  uint32_t   IDATDIS	:1; 	 /* 26..26  bit(s) R */
  uint32_t   IENDDIS	:1; 	 /* 27..27  bit(s) R */
  uint32_t   DCDSIS	:1; 	 /* 28..28  bit(s) R */
  uint32_t   SIDLEIS	:1; 	 /* 29..29  bit(s) R */
  uint32_t   DSFFULLIS	:1; 	 /* 30..30  bit(s) R */ 
  uint32_t   RSRVD31	:1; 	 /* 31..31  bit(s) R */                    
} PNGSINTS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSINTS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSINTS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSINTS_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSINTS(ch)     ((volatile PNGSINTS_bit_view_st *)\
(PNGSINTS_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSINTS(ch)     ((volatile PNGSINTS_byte_view_st *)\
(PNGSINTS_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSINTS(ch)     ((volatile PNGSINTS_halfword_view_st *)\
(PNGSINTS_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSINTS(ch)     ((volatile u32PNGSINTS_word_view *)\
(PNGSINTS_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPNGSINTS_BJMPEIS(ch) (pst_bitPNGSINTS(ch) -> BJMPEIS)            
#define biGetPNGSINTS_UFMTEIS(ch) (pst_bitPNGSINTS(ch) -> UFMTEIS)            
#define biGetPNGSINTS_OOCEIS(ch) (pst_bitPNGSINTS(ch) -> OOCEIS)            
#define biGetPNGSINTS_CHSEIS(ch) (pst_bitPNGSINTS(ch) -> CHSEIS)            
#define biGetPNGSINTS_EYEOSEIS(ch) (pst_bitPNGSINTS(ch) -> EYEOSEIS)            
#define biGetPNGSINTS_NOEOSEIS(ch) (pst_bitPNGSINTS(ch) -> NOEOSEIS)            
#define biGetPNGSINTS_CMPEIS(ch) (pst_bitPNGSINTS(ch) -> CMPEIS)            
#define biGetPNGSINTS_BTYPEEIS(ch) (pst_bitPNGSINTS(ch) -> BTYPEEIS)            
#define biGetPNGSINTS_DISTEIS(ch) (pst_bitPNGSINTS(ch) -> DISTEIS)            
#define biGetPNGSINTS_NCBSEIS(ch) (pst_bitPNGSINTS(ch) -> NCBSEIS)            
#define biGetPNGSINTS_DECEIS(ch) (pst_bitPNGSINTS(ch) -> DECEIS)            
#define biGetPNGSINTS_RSRVD11(ch) (pst_bitPNGSINTS(ch) -> RSRVD11)            
#define biGetPNGSINTS_FJMPWIS(ch) (pst_bitPNGSINTS(ch) -> FJMPWIS)            
#define biGetPNGSINTS_UCHNKWIS(ch) (pst_bitPNGSINTS(ch) -> UCHNKWIS)            
#define biGetPNGSINTS_PDICTWIS(ch) (pst_bitPNGSINTS(ch) -> PDICTWIS)            
#define biGetPNGSINTS_ULLWIS(ch) (pst_bitPNGSINTS(ch) -> ULLWIS)            
#define biGetPNGSINTS_UDISTWIS(ch) (pst_bitPNGSINTS(ch) -> UDISTWIS)            
#define biGetPNGSINTS_OFCWIS(ch) (pst_bitPNGSINTS(ch) -> OFCWIS)            
#define biGetPNGSINTS_RSRVD22(ch) (pst_bitPNGSINTS(ch) -> RSRVD22)            
#define biGetPNGSINTS_IHDRDIS(ch) (pst_bitPNGSINTS(ch) -> IHDRDIS)            
#define biGetPNGSINTS_PLTEDIS(ch) (pst_bitPNGSINTS(ch) -> PLTEDIS)            
#define biGetPNGSINTS_IDATDIS(ch) (pst_bitPNGSINTS(ch) -> IDATDIS)            
#define biGetPNGSINTS_IENDDIS(ch) (pst_bitPNGSINTS(ch) -> IENDDIS)            
#define biGetPNGSINTS_DCDSIS(ch) (pst_bitPNGSINTS(ch) -> DCDSIS)            
#define biGetPNGSINTS_SIDLEIS(ch) (pst_bitPNGSINTS(ch) -> SIDLEIS)            
#define biGetPNGSINTS_DSFFULLIS(ch) (pst_bitPNGSINTS(ch) -> DSFFULLIS)            
#define biGetPNGSINTS_RSRVD31(ch) (pst_bitPNGSINTS(ch) -> RSRVD31)
            
/* LL-struct byte access */

#define u8GetPNGSINTSLL(ch) (pst_u8PNGSINTS(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetPNGSINTSLH(ch) (pst_u8PNGSINTS(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetPNGSINTSHL(ch) (pst_u8PNGSINTS(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetPNGSINTSHH(ch) (pst_u8PNGSINTS(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPNGSINTSL(ch) (pst_u16PNGSINTS(ch) -> u16L)

#define u16GetPNGSINTSH(ch) (pst_u16PNGSINTS(ch) -> u16H)
            
/* Word access */

#define u32GetPNGSINTS(ch)  (*pu32PNGSINTS(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGSINTC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C040CC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGSINTC_REG__       0xC0C040CCU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   BJMPEIC	:1; 	 /* 0..0  bit(s) R/W1C */
  uint32_t   UFMTEIC	:1; 	 /* 1..1  bit(s) R/W1C */
  uint32_t   OOCEIC	:1; 	 /* 2..2  bit(s) R/W1C */
  uint32_t   CHSEIC	:1; 	 /* 3..3  bit(s) R/W1C */
  uint32_t   EYEOSEIC	:1; 	 /* 4..4  bit(s) R/W1C */
  uint32_t   NOEOSEIC	:1; 	 /* 5..5  bit(s) R/W1C */
  uint32_t   CMPEIC	:1; 	 /* 6..6  bit(s) R/W1C */
  uint32_t   BTYPEEIC	:1; 	 /* 7..7  bit(s) R/W1C */
  uint32_t   DISTEIC	:1; 	 /* 8..8  bit(s) R/W1C */
  uint32_t   NCBSEIC	:1; 	 /* 9..9  bit(s) R/W1C */
  uint32_t   DECEIC	:1; 	 /* 10..10  bit(s) R/W1C */
  uint32_t   RSRVD11	:5; 	 /* 11..15  bit(s) R */
  uint32_t   FJMPWIC	:1; 	 /* 16..16  bit(s) R/W1C */
  uint32_t   UCHNKWIC	:1; 	 /* 17..17  bit(s) R/W1C */
  uint32_t   PDICTWIC	:1; 	 /* 18..18  bit(s) R/W1C */
  uint32_t   ULLWIC	:1; 	 /* 19..19  bit(s) R/W1C */
  uint32_t   UDISTWIC	:1; 	 /* 20..20  bit(s) R/W1C */
  uint32_t   OFCWIC	:1; 	 /* 21..21  bit(s) R/W1C */
  uint32_t   RSRVD22	:2; 	 /* 22..23  bit(s) R */
  uint32_t   IHDRDIC	:1; 	 /* 24..24  bit(s) R/W1C */
  uint32_t   PLTEDIC	:1; 	 /* 25..25  bit(s) R/W1C */
  uint32_t   IDATDIC	:1; 	 /* 26..26  bit(s) R/W1C */
  uint32_t   IENDDIC	:1; 	 /* 27..27  bit(s) R/W1C */
  uint32_t   DCDSIC	:1; 	 /* 28..28  bit(s) R/W1C */
  uint32_t   SIDLEIC	:1; 	 /* 29..29  bit(s) R/W1C */
  uint32_t   DSFFULLIC	:1; 	 /* 30..30  bit(s) R/W1C */ 
  uint32_t   RSRVD31	:1; 	 /* 31..31  bit(s) R */                    
} PNGSINTC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGSINTC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGSINTC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGSINTC_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGSINTC(ch)     ((volatile PNGSINTC_bit_view_st *)\
(PNGSINTC_REG__  + ((uint16_t)(ch) * 0x0100U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGSINTC(ch)     ((volatile PNGSINTC_byte_view_st *)\
(PNGSINTC_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGSINTC(ch)     ((volatile PNGSINTC_halfword_view_st *)\
(PNGSINTC_REG__  + ((uint16_t)(ch) * 0x0100U)))
            
/* Pointer to WORD  */ 
#define pu32PNGSINTC(ch)     ((volatile u32PNGSINTC_word_view *)\
(PNGSINTC_REG__  + ((uint16_t)(ch) * 0x0100U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGSINTC_BJMPEIC(ch) (pst_bitPNGSINTC(ch) -> BJMPEIC)
#define vClrPNGSINTC_BJMPEIC(ch) (pst_bitPNGSINTC(ch) -> BJMPEIC = (1))
#define biGetPNGSINTC_UFMTEIC(ch) (pst_bitPNGSINTC(ch) -> UFMTEIC)
#define vClrPNGSINTC_UFMTEIC(ch) (pst_bitPNGSINTC(ch) -> UFMTEIC = (1))
#define biGetPNGSINTC_OOCEIC(ch) (pst_bitPNGSINTC(ch) -> OOCEIC)
#define vClrPNGSINTC_OOCEIC(ch) (pst_bitPNGSINTC(ch) -> OOCEIC = (1))
#define biGetPNGSINTC_CHSEIC(ch) (pst_bitPNGSINTC(ch) -> CHSEIC)
#define vClrPNGSINTC_CHSEIC(ch) (pst_bitPNGSINTC(ch) -> CHSEIC = (1))
#define biGetPNGSINTC_EYEOSEIC(ch) (pst_bitPNGSINTC(ch) -> EYEOSEIC)
#define vClrPNGSINTC_EYEOSEIC(ch) (pst_bitPNGSINTC(ch) -> EYEOSEIC = (1))
#define biGetPNGSINTC_NOEOSEIC(ch) (pst_bitPNGSINTC(ch) -> NOEOSEIC)
#define vClrPNGSINTC_NOEOSEIC(ch) (pst_bitPNGSINTC(ch) -> NOEOSEIC = (1))
#define biGetPNGSINTC_CMPEIC(ch) (pst_bitPNGSINTC(ch) -> CMPEIC)
#define vClrPNGSINTC_CMPEIC(ch) (pst_bitPNGSINTC(ch) -> CMPEIC = (1))
#define biGetPNGSINTC_BTYPEEIC(ch) (pst_bitPNGSINTC(ch) -> BTYPEEIC)
#define vClrPNGSINTC_BTYPEEIC(ch) (pst_bitPNGSINTC(ch) -> BTYPEEIC = (1))
#define biGetPNGSINTC_DISTEIC(ch) (pst_bitPNGSINTC(ch) -> DISTEIC)
#define vClrPNGSINTC_DISTEIC(ch) (pst_bitPNGSINTC(ch) -> DISTEIC = (1))
#define biGetPNGSINTC_NCBSEIC(ch) (pst_bitPNGSINTC(ch) -> NCBSEIC)
#define vClrPNGSINTC_NCBSEIC(ch) (pst_bitPNGSINTC(ch) -> NCBSEIC = (1))
#define biGetPNGSINTC_DECEIC(ch) (pst_bitPNGSINTC(ch) -> DECEIC)
#define vClrPNGSINTC_DECEIC(ch) (pst_bitPNGSINTC(ch) -> DECEIC = (1))            
#define biGetPNGSINTC_RSRVD11(ch) (pst_bitPNGSINTC(ch) -> RSRVD11)
#define biGetPNGSINTC_FJMPWIC(ch) (pst_bitPNGSINTC(ch) -> FJMPWIC)
#define vClrPNGSINTC_FJMPWIC(ch) (pst_bitPNGSINTC(ch) -> FJMPWIC = (1))
#define biGetPNGSINTC_UCHNKWIC(ch) (pst_bitPNGSINTC(ch) -> UCHNKWIC)
#define vClrPNGSINTC_UCHNKWIC(ch) (pst_bitPNGSINTC(ch) -> UCHNKWIC = (1))
#define biGetPNGSINTC_PDICTWIC(ch) (pst_bitPNGSINTC(ch) -> PDICTWIC)
#define vClrPNGSINTC_PDICTWIC(ch) (pst_bitPNGSINTC(ch) -> PDICTWIC = (1))
#define biGetPNGSINTC_ULLWIC(ch) (pst_bitPNGSINTC(ch) -> ULLWIC)
#define vClrPNGSINTC_ULLWIC(ch) (pst_bitPNGSINTC(ch) -> ULLWIC = (1))
#define biGetPNGSINTC_UDISTWIC(ch) (pst_bitPNGSINTC(ch) -> UDISTWIC)
#define vClrPNGSINTC_UDISTWIC(ch) (pst_bitPNGSINTC(ch) -> UDISTWIC = (1))
#define biGetPNGSINTC_OFCWIC(ch) (pst_bitPNGSINTC(ch) -> OFCWIC)
#define vClrPNGSINTC_OFCWIC(ch) (pst_bitPNGSINTC(ch) -> OFCWIC = (1))            
#define biGetPNGSINTC_RSRVD22(ch) (pst_bitPNGSINTC(ch) -> RSRVD22)
#define biGetPNGSINTC_IHDRDIC(ch) (pst_bitPNGSINTC(ch) -> IHDRDIC)
#define vClrPNGSINTC_IHDRDIC(ch) (pst_bitPNGSINTC(ch) -> IHDRDIC = (1))
#define biGetPNGSINTC_PLTEDIC(ch) (pst_bitPNGSINTC(ch) -> PLTEDIC)
#define vClrPNGSINTC_PLTEDIC(ch) (pst_bitPNGSINTC(ch) -> PLTEDIC = (1))
#define biGetPNGSINTC_IDATDIC(ch) (pst_bitPNGSINTC(ch) -> IDATDIC)
#define vClrPNGSINTC_IDATDIC(ch) (pst_bitPNGSINTC(ch) -> IDATDIC = (1))
#define biGetPNGSINTC_IENDDIC(ch) (pst_bitPNGSINTC(ch) -> IENDDIC)
#define vClrPNGSINTC_IENDDIC(ch) (pst_bitPNGSINTC(ch) -> IENDDIC = (1))
#define biGetPNGSINTC_DCDSIC(ch) (pst_bitPNGSINTC(ch) -> DCDSIC)
#define vClrPNGSINTC_DCDSIC(ch) (pst_bitPNGSINTC(ch) -> DCDSIC = (1))
#define biGetPNGSINTC_SIDLEIC(ch) (pst_bitPNGSINTC(ch) -> SIDLEIC)
#define vClrPNGSINTC_SIDLEIC(ch) (pst_bitPNGSINTC(ch) -> SIDLEIC = (1))
#define biGetPNGSINTC_DSFFULLIC(ch) (pst_bitPNGSINTC(ch) -> DSFFULLIC)
#define vClrPNGSINTC_DSFFULLIC(ch) (pst_bitPNGSINTC(ch) -> DSFFULLIC = (1))            
#define biGetPNGSINTC_RSRVD31(ch) (pst_bitPNGSINTC(ch) -> RSRVD31)
            
/* LL-struct byte access */
#define vSetPNGSINTCLL(ch,ParValue) (pst_u8PNGSINTC(ch) -> u8LL = (ParValue))
#define u8GetPNGSINTCLL(ch) (pst_u8PNGSINTC(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGSINTCLH(ch,ParValue) (pst_u8PNGSINTC(ch) -> u8LH = (ParValue))
#define u8GetPNGSINTCLH(ch) (pst_u8PNGSINTC(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGSINTCHL(ch,ParValue) (pst_u8PNGSINTC(ch) -> u8HL = (ParValue))
#define u8GetPNGSINTCHL(ch) (pst_u8PNGSINTC(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGSINTCHH(ch,ParValue) (pst_u8PNGSINTC(ch) -> u8HH = (ParValue))
#define u8GetPNGSINTCHH(ch) (pst_u8PNGSINTC(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGSINTCL(ch,ParValue) (pst_u16PNGSINTC(ch) -> u16L = (ParValue))
#define u16GetPNGSINTCL(ch) (pst_u16PNGSINTC(ch) -> u16L)
#define vSetPNGSINTCH(ch,ParValue) (pst_u16PNGSINTC(ch) -> u16H = (ParValue))
#define u16GetPNGSINTCH(ch) (pst_u16PNGSINTC(ch) -> u16H)
            
/* Word access */
#define vSetPNGSINTC(ch,ParValue)  (*pu32PNGSINTC(ch) = (ParValue))
#define u32GetPNGSINTC(ch)  (*pu32PNGSINTC(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGPLT0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C04C00                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGPLT0_REG__       0xC0C04C00U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PLTVAL0	:24; 	 /* 0..23  bit(s) R/W */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGPLT0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGPLT0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGPLT0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGPLT0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGPLT0(ch)     ((volatile PNGPLT0_bit_view_st *)\
(PNGPLT0_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGPLT0(ch)     ((volatile PNGPLT0_byte_view_st *)\
(PNGPLT0_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGPLT0(ch)     ((volatile PNGPLT0_halfword_view_st *)\
(PNGPLT0_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32PNGPLT0(ch)     ((volatile u32PNGPLT0_word_view *)\
(PNGPLT0_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGPLT0_PLTVAL0(ch) (pst_bitPNGPLT0(ch) -> PLTVAL0)
#define vSetPNGPLT0_PLTVAL0(ch,ParValue)  (pst_bitPNGPLT0(ch) -> PLTVAL0=(ParValue))            
#define biGetPNGPLT0_RSRVD24(ch) (pst_bitPNGPLT0(ch) -> RSRVD24)
            
/* LL-struct byte access */
#define vSetPNGPLT0LL(ch,ParValue) (pst_u8PNGPLT0(ch) -> u8LL = (ParValue))
#define u8GetPNGPLT0LL(ch) (pst_u8PNGPLT0(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGPLT0LH(ch,ParValue) (pst_u8PNGPLT0(ch) -> u8LH = (ParValue))
#define u8GetPNGPLT0LH(ch) (pst_u8PNGPLT0(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGPLT0HL(ch,ParValue) (pst_u8PNGPLT0(ch) -> u8HL = (ParValue))
#define u8GetPNGPLT0HL(ch) (pst_u8PNGPLT0(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGPLT0HH(ch,ParValue) (pst_u8PNGPLT0(ch) -> u8HH = (ParValue))
#define u8GetPNGPLT0HH(ch) (pst_u8PNGPLT0(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGPLT0L(ch,ParValue) (pst_u16PNGPLT0(ch) -> u16L = (ParValue))
#define u16GetPNGPLT0L(ch) (pst_u16PNGPLT0(ch) -> u16L)
#define vSetPNGPLT0H(ch,ParValue) (pst_u16PNGPLT0(ch) -> u16H = (ParValue))
#define u16GetPNGPLT0H(ch) (pst_u16PNGPLT0(ch) -> u16H)
            
/* Word access */
#define vSetPNGPLT0(ch,ParValue)  (*pu32PNGPLT0(ch) = (ParValue))
#define u32GetPNGPLT0(ch)  (*pu32PNGPLT0(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGPLT1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C05000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGPLT1_REG__       0xC0C05000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PLTVAL1	:24; 	 /* 0..23  bit(s) R/W */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGPLT1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGPLT1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGPLT1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGPLT1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGPLT1(ch)     ((volatile PNGPLT1_bit_view_st *)\
(PNGPLT1_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGPLT1(ch)     ((volatile PNGPLT1_byte_view_st *)\
(PNGPLT1_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGPLT1(ch)     ((volatile PNGPLT1_halfword_view_st *)\
(PNGPLT1_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32PNGPLT1(ch)     ((volatile u32PNGPLT1_word_view *)\
(PNGPLT1_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGPLT1_PLTVAL1(ch) (pst_bitPNGPLT1(ch) -> PLTVAL1)
#define vSetPNGPLT1_PLTVAL1(ch,ParValue)  (pst_bitPNGPLT1(ch) -> PLTVAL1=(ParValue))            
#define biGetPNGPLT1_RSRVD24(ch) (pst_bitPNGPLT1(ch) -> RSRVD24)
            
/* LL-struct byte access */
#define vSetPNGPLT1LL(ch,ParValue) (pst_u8PNGPLT1(ch) -> u8LL = (ParValue))
#define u8GetPNGPLT1LL(ch) (pst_u8PNGPLT1(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGPLT1LH(ch,ParValue) (pst_u8PNGPLT1(ch) -> u8LH = (ParValue))
#define u8GetPNGPLT1LH(ch) (pst_u8PNGPLT1(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGPLT1HL(ch,ParValue) (pst_u8PNGPLT1(ch) -> u8HL = (ParValue))
#define u8GetPNGPLT1HL(ch) (pst_u8PNGPLT1(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGPLT1HH(ch,ParValue) (pst_u8PNGPLT1(ch) -> u8HH = (ParValue))
#define u8GetPNGPLT1HH(ch) (pst_u8PNGPLT1(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGPLT1L(ch,ParValue) (pst_u16PNGPLT1(ch) -> u16L = (ParValue))
#define u16GetPNGPLT1L(ch) (pst_u16PNGPLT1(ch) -> u16L)
#define vSetPNGPLT1H(ch,ParValue) (pst_u16PNGPLT1(ch) -> u16H = (ParValue))
#define u16GetPNGPLT1H(ch) (pst_u16PNGPLT1(ch) -> u16H)
            
/* Word access */
#define vSetPNGPLT1(ch,ParValue)  (*pu32PNGPLT1(ch) = (ParValue))
#define u32GetPNGPLT1(ch)  (*pu32PNGPLT1(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGPLT2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C05400                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGPLT2_REG__       0xC0C05400U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PLTVAL2	:24; 	 /* 0..23  bit(s) R/W */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGPLT2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGPLT2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGPLT2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGPLT2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGPLT2(ch)     ((volatile PNGPLT2_bit_view_st *)\
(PNGPLT2_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGPLT2(ch)     ((volatile PNGPLT2_byte_view_st *)\
(PNGPLT2_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGPLT2(ch)     ((volatile PNGPLT2_halfword_view_st *)\
(PNGPLT2_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32PNGPLT2(ch)     ((volatile u32PNGPLT2_word_view *)\
(PNGPLT2_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGPLT2_PLTVAL2(ch) (pst_bitPNGPLT2(ch) -> PLTVAL2)
#define vSetPNGPLT2_PLTVAL2(ch,ParValue)  (pst_bitPNGPLT2(ch) -> PLTVAL2=(ParValue))            
#define biGetPNGPLT2_RSRVD24(ch) (pst_bitPNGPLT2(ch) -> RSRVD24)
            
/* LL-struct byte access */
#define vSetPNGPLT2LL(ch,ParValue) (pst_u8PNGPLT2(ch) -> u8LL = (ParValue))
#define u8GetPNGPLT2LL(ch) (pst_u8PNGPLT2(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGPLT2LH(ch,ParValue) (pst_u8PNGPLT2(ch) -> u8LH = (ParValue))
#define u8GetPNGPLT2LH(ch) (pst_u8PNGPLT2(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGPLT2HL(ch,ParValue) (pst_u8PNGPLT2(ch) -> u8HL = (ParValue))
#define u8GetPNGPLT2HL(ch) (pst_u8PNGPLT2(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGPLT2HH(ch,ParValue) (pst_u8PNGPLT2(ch) -> u8HH = (ParValue))
#define u8GetPNGPLT2HH(ch) (pst_u8PNGPLT2(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGPLT2L(ch,ParValue) (pst_u16PNGPLT2(ch) -> u16L = (ParValue))
#define u16GetPNGPLT2L(ch) (pst_u16PNGPLT2(ch) -> u16L)
#define vSetPNGPLT2H(ch,ParValue) (pst_u16PNGPLT2(ch) -> u16H = (ParValue))
#define u16GetPNGPLT2H(ch) (pst_u16PNGPLT2(ch) -> u16H)
            
/* Word access */
#define vSetPNGPLT2(ch,ParValue)  (*pu32PNGPLT2(ch) = (ParValue))
#define u32GetPNGPLT2(ch)  (*pu32PNGPLT2(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGPLT3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C05800                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGPLT3_REG__       0xC0C05800U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PLTVAL3	:24; 	 /* 0..23  bit(s) R/W */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGPLT3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGPLT3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGPLT3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGPLT3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGPLT3(ch)     ((volatile PNGPLT3_bit_view_st *)\
(PNGPLT3_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGPLT3(ch)     ((volatile PNGPLT3_byte_view_st *)\
(PNGPLT3_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGPLT3(ch)     ((volatile PNGPLT3_halfword_view_st *)\
(PNGPLT3_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32PNGPLT3(ch)     ((volatile u32PNGPLT3_word_view *)\
(PNGPLT3_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGPLT3_PLTVAL3(ch) (pst_bitPNGPLT3(ch) -> PLTVAL3)
#define vSetPNGPLT3_PLTVAL3(ch,ParValue)  (pst_bitPNGPLT3(ch) -> PLTVAL3=(ParValue))            
#define biGetPNGPLT3_RSRVD24(ch) (pst_bitPNGPLT3(ch) -> RSRVD24)
            
/* LL-struct byte access */
#define vSetPNGPLT3LL(ch,ParValue) (pst_u8PNGPLT3(ch) -> u8LL = (ParValue))
#define u8GetPNGPLT3LL(ch) (pst_u8PNGPLT3(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGPLT3LH(ch,ParValue) (pst_u8PNGPLT3(ch) -> u8LH = (ParValue))
#define u8GetPNGPLT3LH(ch) (pst_u8PNGPLT3(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGPLT3HL(ch,ParValue) (pst_u8PNGPLT3(ch) -> u8HL = (ParValue))
#define u8GetPNGPLT3HL(ch) (pst_u8PNGPLT3(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGPLT3HH(ch,ParValue) (pst_u8PNGPLT3(ch) -> u8HH = (ParValue))
#define u8GetPNGPLT3HH(ch) (pst_u8PNGPLT3(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGPLT3L(ch,ParValue) (pst_u16PNGPLT3(ch) -> u16L = (ParValue))
#define u16GetPNGPLT3L(ch) (pst_u16PNGPLT3(ch) -> u16L)
#define vSetPNGPLT3H(ch,ParValue) (pst_u16PNGPLT3(ch) -> u16H = (ParValue))
#define u16GetPNGPLT3H(ch) (pst_u16PNGPLT3(ch) -> u16H)
            
/* Word access */
#define vSetPNGPLT3(ch,ParValue)  (*pu32PNGPLT3(ch) = (ParValue))
#define u32GetPNGPLT3(ch)  (*pu32PNGPLT3(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGPLT4                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C05C00                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGPLT4_REG__       0xC0C05C00U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PLTVAL4	:24; 	 /* 0..23  bit(s) R/W */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGPLT4_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGPLT4_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGPLT4_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGPLT4_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGPLT4(ch)     ((volatile PNGPLT4_bit_view_st *)\
(PNGPLT4_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGPLT4(ch)     ((volatile PNGPLT4_byte_view_st *)\
(PNGPLT4_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGPLT4(ch)     ((volatile PNGPLT4_halfword_view_st *)\
(PNGPLT4_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32PNGPLT4(ch)     ((volatile u32PNGPLT4_word_view *)\
(PNGPLT4_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGPLT4_PLTVAL4(ch) (pst_bitPNGPLT4(ch) -> PLTVAL4)
#define vSetPNGPLT4_PLTVAL4(ch,ParValue)  (pst_bitPNGPLT4(ch) -> PLTVAL4=(ParValue))            
#define biGetPNGPLT4_RSRVD24(ch) (pst_bitPNGPLT4(ch) -> RSRVD24)
            
/* LL-struct byte access */
#define vSetPNGPLT4LL(ch,ParValue) (pst_u8PNGPLT4(ch) -> u8LL = (ParValue))
#define u8GetPNGPLT4LL(ch) (pst_u8PNGPLT4(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGPLT4LH(ch,ParValue) (pst_u8PNGPLT4(ch) -> u8LH = (ParValue))
#define u8GetPNGPLT4LH(ch) (pst_u8PNGPLT4(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGPLT4HL(ch,ParValue) (pst_u8PNGPLT4(ch) -> u8HL = (ParValue))
#define u8GetPNGPLT4HL(ch) (pst_u8PNGPLT4(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGPLT4HH(ch,ParValue) (pst_u8PNGPLT4(ch) -> u8HH = (ParValue))
#define u8GetPNGPLT4HH(ch) (pst_u8PNGPLT4(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGPLT4L(ch,ParValue) (pst_u16PNGPLT4(ch) -> u16L = (ParValue))
#define u16GetPNGPLT4L(ch) (pst_u16PNGPLT4(ch) -> u16L)
#define vSetPNGPLT4H(ch,ParValue) (pst_u16PNGPLT4(ch) -> u16H = (ParValue))
#define u16GetPNGPLT4H(ch) (pst_u16PNGPLT4(ch) -> u16H)
            
/* Word access */
#define vSetPNGPLT4(ch,ParValue)  (*pu32PNGPLT4(ch) = (ParValue))
#define u32GetPNGPLT4(ch)  (*pu32PNGPLT4(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGPLT5                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C06000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGPLT5_REG__       0xC0C06000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PLTVAL5	:24; 	 /* 0..23  bit(s) R/W */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGPLT5_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGPLT5_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGPLT5_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGPLT5_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGPLT5(ch)     ((volatile PNGPLT5_bit_view_st *)\
(PNGPLT5_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGPLT5(ch)     ((volatile PNGPLT5_byte_view_st *)\
(PNGPLT5_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGPLT5(ch)     ((volatile PNGPLT5_halfword_view_st *)\
(PNGPLT5_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32PNGPLT5(ch)     ((volatile u32PNGPLT5_word_view *)\
(PNGPLT5_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGPLT5_PLTVAL5(ch) (pst_bitPNGPLT5(ch) -> PLTVAL5)
#define vSetPNGPLT5_PLTVAL5(ch,ParValue)  (pst_bitPNGPLT5(ch) -> PLTVAL5=(ParValue))            
#define biGetPNGPLT5_RSRVD24(ch) (pst_bitPNGPLT5(ch) -> RSRVD24)
            
/* LL-struct byte access */
#define vSetPNGPLT5LL(ch,ParValue) (pst_u8PNGPLT5(ch) -> u8LL = (ParValue))
#define u8GetPNGPLT5LL(ch) (pst_u8PNGPLT5(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGPLT5LH(ch,ParValue) (pst_u8PNGPLT5(ch) -> u8LH = (ParValue))
#define u8GetPNGPLT5LH(ch) (pst_u8PNGPLT5(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGPLT5HL(ch,ParValue) (pst_u8PNGPLT5(ch) -> u8HL = (ParValue))
#define u8GetPNGPLT5HL(ch) (pst_u8PNGPLT5(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGPLT5HH(ch,ParValue) (pst_u8PNGPLT5(ch) -> u8HH = (ParValue))
#define u8GetPNGPLT5HH(ch) (pst_u8PNGPLT5(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGPLT5L(ch,ParValue) (pst_u16PNGPLT5(ch) -> u16L = (ParValue))
#define u16GetPNGPLT5L(ch) (pst_u16PNGPLT5(ch) -> u16L)
#define vSetPNGPLT5H(ch,ParValue) (pst_u16PNGPLT5(ch) -> u16H = (ParValue))
#define u16GetPNGPLT5H(ch) (pst_u16PNGPLT5(ch) -> u16H)
            
/* Word access */
#define vSetPNGPLT5(ch,ParValue)  (*pu32PNGPLT5(ch) = (ParValue))
#define u32GetPNGPLT5(ch)  (*pu32PNGPLT5(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGPLT6                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C06400                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGPLT6_REG__       0xC0C06400U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PLTVAL6	:24; 	 /* 0..23  bit(s) R/W */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGPLT6_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGPLT6_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGPLT6_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGPLT6_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGPLT6(ch)     ((volatile PNGPLT6_bit_view_st *)\
(PNGPLT6_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGPLT6(ch)     ((volatile PNGPLT6_byte_view_st *)\
(PNGPLT6_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGPLT6(ch)     ((volatile PNGPLT6_halfword_view_st *)\
(PNGPLT6_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32PNGPLT6(ch)     ((volatile u32PNGPLT6_word_view *)\
(PNGPLT6_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGPLT6_PLTVAL6(ch) (pst_bitPNGPLT6(ch) -> PLTVAL6)
#define vSetPNGPLT6_PLTVAL6(ch,ParValue)  (pst_bitPNGPLT6(ch) -> PLTVAL6=(ParValue))            
#define biGetPNGPLT6_RSRVD24(ch) (pst_bitPNGPLT6(ch) -> RSRVD24)
            
/* LL-struct byte access */
#define vSetPNGPLT6LL(ch,ParValue) (pst_u8PNGPLT6(ch) -> u8LL = (ParValue))
#define u8GetPNGPLT6LL(ch) (pst_u8PNGPLT6(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGPLT6LH(ch,ParValue) (pst_u8PNGPLT6(ch) -> u8LH = (ParValue))
#define u8GetPNGPLT6LH(ch) (pst_u8PNGPLT6(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGPLT6HL(ch,ParValue) (pst_u8PNGPLT6(ch) -> u8HL = (ParValue))
#define u8GetPNGPLT6HL(ch) (pst_u8PNGPLT6(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGPLT6HH(ch,ParValue) (pst_u8PNGPLT6(ch) -> u8HH = (ParValue))
#define u8GetPNGPLT6HH(ch) (pst_u8PNGPLT6(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGPLT6L(ch,ParValue) (pst_u16PNGPLT6(ch) -> u16L = (ParValue))
#define u16GetPNGPLT6L(ch) (pst_u16PNGPLT6(ch) -> u16L)
#define vSetPNGPLT6H(ch,ParValue) (pst_u16PNGPLT6(ch) -> u16H = (ParValue))
#define u16GetPNGPLT6H(ch) (pst_u16PNGPLT6(ch) -> u16H)
            
/* Word access */
#define vSetPNGPLT6(ch,ParValue)  (*pu32PNGPLT6(ch) = (ParValue))
#define u32GetPNGPLT6(ch)  (*pu32PNGPLT6(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PNGPLT7                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C06800                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PNGPLT7_REG__       0xC0C06800U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PLTVAL7	:24; 	 /* 0..23  bit(s) R/W */ 
  uint32_t   RSRVD24	:8; 	 /* 24..31  bit(s) R */                    
} PNGPLT7_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PNGPLT7_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PNGPLT7_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PNGPLT7_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPNGPLT7(ch)     ((volatile PNGPLT7_bit_view_st *)\
(PNGPLT7_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8PNGPLT7(ch)     ((volatile PNGPLT7_byte_view_st *)\
(PNGPLT7_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PNGPLT7(ch)     ((volatile PNGPLT7_halfword_view_st *)\
(PNGPLT7_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32PNGPLT7(ch)     ((volatile u32PNGPLT7_word_view *)\
(PNGPLT7_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPNGPLT7_PLTVAL7(ch) (pst_bitPNGPLT7(ch) -> PLTVAL7)
#define vSetPNGPLT7_PLTVAL7(ch,ParValue)  (pst_bitPNGPLT7(ch) -> PLTVAL7=(ParValue))            
#define biGetPNGPLT7_RSRVD24(ch) (pst_bitPNGPLT7(ch) -> RSRVD24)
            
/* LL-struct byte access */
#define vSetPNGPLT7LL(ch,ParValue) (pst_u8PNGPLT7(ch) -> u8LL = (ParValue))
#define u8GetPNGPLT7LL(ch) (pst_u8PNGPLT7(ch) -> u8LL)
/* LH-struct byte access */
#define vSetPNGPLT7LH(ch,ParValue) (pst_u8PNGPLT7(ch) -> u8LH = (ParValue))
#define u8GetPNGPLT7LH(ch) (pst_u8PNGPLT7(ch) -> u8LH)
/* HL-struct byte access */
#define vSetPNGPLT7HL(ch,ParValue) (pst_u8PNGPLT7(ch) -> u8HL = (ParValue))
#define u8GetPNGPLT7HL(ch) (pst_u8PNGPLT7(ch) -> u8HL)
/* HH-struct byte access */
#define vSetPNGPLT7HH(ch,ParValue) (pst_u8PNGPLT7(ch) -> u8HH = (ParValue))
#define u8GetPNGPLT7HH(ch) (pst_u8PNGPLT7(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPNGPLT7L(ch,ParValue) (pst_u16PNGPLT7(ch) -> u16L = (ParValue))
#define u16GetPNGPLT7L(ch) (pst_u16PNGPLT7(ch) -> u16L)
#define vSetPNGPLT7H(ch,ParValue) (pst_u16PNGPLT7(ch) -> u16H = (ParValue))
#define u16GetPNGPLT7H(ch) (pst_u16PNGPLT7(ch) -> u16H)
            
/* Word access */
#define vSetPNGPLT7(ch,ParValue)  (*pu32PNGPLT7(ch) = (ParValue))
#define u32GetPNGPLT7(ch)  (*pu32PNGPLT7(ch) )
            
/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

#endif /* PNGDeIO_H */ 
    
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

