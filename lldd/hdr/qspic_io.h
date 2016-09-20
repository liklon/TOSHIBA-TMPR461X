
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : QSPIC 
/  Date of creation (y-m-d:time): 2015-01-20+01:00  :  09:50:23.19+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.25 $ 
/  Excel Sheet ver.             : v1.21
/  Excel Sheet date             : 2015-Jan-12
/  Excel Sheet author           : ALN
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : QSPI low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : QSPI
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.25 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef QSPICIO_H
#define QSPICIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_QSPIC_IO_H_REVISION     "$Revision: 1.25 $"
#define LLDD_QSPIC_IO_H_TAG          "$Name: LLDD_1_6 $"

/* disable following Misra errors for io files */
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1840   /* Rule 5.7   [A] : No reuse of identifiers  */
  #pragma ghs nowarning 230    /* Rule 6.4   [R] : Bitfields can only have `unsigned int' or `signed int' types */
  #pragma ghs nowarning 1829   /* Rule 19.10 [R] : 	In function-like macro definition, wrap each parameter reference in parentheses */
#endif

/****************************************************************************
*                          CONTROLER SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
typedef enum tag_qspic_cntrl_def_e
{
  QSPIC_CNTRL_0__ = 0,
  QSPIC_CNTRL_1__ = 0xAF8000,
  QSPIC_CNTRL_2__ = 0x1000 
} qspic_cntrl_def_e; 

/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_FlshMemMap0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0109000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_FlshMemMap0_REG__       0xC0109000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   RE	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   RSRVD1	:1; 	 /* 1..1  bit(s) R */
  uint32_t   FDEN	:4; 	 /* 2..5  bit(s) R/W */
  uint32_t   RSRVD6	:10; 	 /* 6..15  bit(s) R */ 
  uint32_t   FBA	:16; 	 /* 16..31  bit(s) R/W */                    
} QSPIC_FlshMemMap0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_FlshMemMap0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_FlshMemMap0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_FlshMemMap0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_FlshMemMap0(ctrlr)     ((volatile QSPIC_FlshMemMap0_bit_view_st *)\
(QSPIC_FlshMemMap0_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_FlshMemMap0(ctrlr)     ((volatile QSPIC_FlshMemMap0_byte_view_st *)\
(QSPIC_FlshMemMap0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_FlshMemMap0(ctrlr)     ((volatile QSPIC_FlshMemMap0_halfword_view_st *)\
(QSPIC_FlshMemMap0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_FlshMemMap0(ctrlr)     ((volatile u32QSPIC_FlshMemMap0_word_view *)\
(QSPIC_FlshMemMap0_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPIC_FlshMemMap0_RE(ctrlr) (pst_bitQSPIC_FlshMemMap0(ctrlr) -> RE)
#define vSetQSPIC_FlshMemMap0_RE(ctrlr,ParValue)  (pst_bitQSPIC_FlshMemMap0(ctrlr) -> RE=(ParValue))            
#define biGetQSPIC_FlshMemMap0_RSRVD1(ctrlr) (pst_bitQSPIC_FlshMemMap0(ctrlr) -> RSRVD1)
#define biGetQSPIC_FlshMemMap0_FDEN(ctrlr) (pst_bitQSPIC_FlshMemMap0(ctrlr) -> FDEN)
#define vSetQSPIC_FlshMemMap0_FDEN(ctrlr,ParValue)  (pst_bitQSPIC_FlshMemMap0(ctrlr) -> FDEN=(ParValue))            
#define biGetQSPIC_FlshMemMap0_RSRVD6(ctrlr) (pst_bitQSPIC_FlshMemMap0(ctrlr) -> RSRVD6)
#define biGetQSPIC_FlshMemMap0_FBA(ctrlr) (pst_bitQSPIC_FlshMemMap0(ctrlr) -> FBA)
#define vSetQSPIC_FlshMemMap0_FBA(ctrlr,ParValue)  (pst_bitQSPIC_FlshMemMap0(ctrlr) -> FBA=(ParValue))
            
/* LL-struct byte access */
#define vSetQSPIC_FlshMemMap0LL(ctrlr,ParValue) (pst_u8QSPIC_FlshMemMap0(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_FlshMemMap0LL(ctrlr) (pst_u8QSPIC_FlshMemMap0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_FlshMemMap0LH(ctrlr,ParValue) (pst_u8QSPIC_FlshMemMap0(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_FlshMemMap0LH(ctrlr) (pst_u8QSPIC_FlshMemMap0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_FlshMemMap0HL(ctrlr,ParValue) (pst_u8QSPIC_FlshMemMap0(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_FlshMemMap0HL(ctrlr) (pst_u8QSPIC_FlshMemMap0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_FlshMemMap0HH(ctrlr,ParValue) (pst_u8QSPIC_FlshMemMap0(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_FlshMemMap0HH(ctrlr) (pst_u8QSPIC_FlshMemMap0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_FlshMemMap0L(ctrlr,ParValue) (pst_u16QSPIC_FlshMemMap0(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_FlshMemMap0L(ctrlr) (pst_u16QSPIC_FlshMemMap0(ctrlr) -> u16L)
#define vSetQSPIC_FlshMemMap0H(ctrlr,ParValue) (pst_u16QSPIC_FlshMemMap0(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_FlshMemMap0H(ctrlr) (pst_u16QSPIC_FlshMemMap0(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_FlshMemMap0(ctrlr,ParValue)  (*pu32QSPIC_FlshMemMap0(ctrlr) = (ParValue))
#define u32GetQSPIC_FlshMemMap0(ctrlr)  (*pu32QSPIC_FlshMemMap0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_FlshMemMap1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0109004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_FlshMemMap1_REG__       0xC0109004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   RE	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   RSRVD1	:1; 	 /* 1..1  bit(s) R */
  uint32_t   FDEN	:4; 	 /* 2..5  bit(s) R/W */
  uint32_t   RSRVD6	:10; 	 /* 6..15  bit(s) R */ 
  uint32_t   FBA	:16; 	 /* 16..31  bit(s) R/W */                    
} QSPIC_FlshMemMap1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_FlshMemMap1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_FlshMemMap1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_FlshMemMap1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_FlshMemMap1(ctrlr)     ((volatile QSPIC_FlshMemMap1_bit_view_st *)\
(QSPIC_FlshMemMap1_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_FlshMemMap1(ctrlr)     ((volatile QSPIC_FlshMemMap1_byte_view_st *)\
(QSPIC_FlshMemMap1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_FlshMemMap1(ctrlr)     ((volatile QSPIC_FlshMemMap1_halfword_view_st *)\
(QSPIC_FlshMemMap1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_FlshMemMap1(ctrlr)     ((volatile u32QSPIC_FlshMemMap1_word_view *)\
(QSPIC_FlshMemMap1_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPIC_FlshMemMap1_RE(ctrlr) (pst_bitQSPIC_FlshMemMap1(ctrlr) -> RE)
#define vSetQSPIC_FlshMemMap1_RE(ctrlr,ParValue)  (pst_bitQSPIC_FlshMemMap1(ctrlr) -> RE=(ParValue))            
#define biGetQSPIC_FlshMemMap1_RSRVD1(ctrlr) (pst_bitQSPIC_FlshMemMap1(ctrlr) -> RSRVD1)
#define biGetQSPIC_FlshMemMap1_FDEN(ctrlr) (pst_bitQSPIC_FlshMemMap1(ctrlr) -> FDEN)
#define vSetQSPIC_FlshMemMap1_FDEN(ctrlr,ParValue)  (pst_bitQSPIC_FlshMemMap1(ctrlr) -> FDEN=(ParValue))            
#define biGetQSPIC_FlshMemMap1_RSRVD6(ctrlr) (pst_bitQSPIC_FlshMemMap1(ctrlr) -> RSRVD6)
#define biGetQSPIC_FlshMemMap1_FBA(ctrlr) (pst_bitQSPIC_FlshMemMap1(ctrlr) -> FBA)
#define vSetQSPIC_FlshMemMap1_FBA(ctrlr,ParValue)  (pst_bitQSPIC_FlshMemMap1(ctrlr) -> FBA=(ParValue))
            
/* LL-struct byte access */
#define vSetQSPIC_FlshMemMap1LL(ctrlr,ParValue) (pst_u8QSPIC_FlshMemMap1(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_FlshMemMap1LL(ctrlr) (pst_u8QSPIC_FlshMemMap1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_FlshMemMap1LH(ctrlr,ParValue) (pst_u8QSPIC_FlshMemMap1(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_FlshMemMap1LH(ctrlr) (pst_u8QSPIC_FlshMemMap1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_FlshMemMap1HL(ctrlr,ParValue) (pst_u8QSPIC_FlshMemMap1(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_FlshMemMap1HL(ctrlr) (pst_u8QSPIC_FlshMemMap1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_FlshMemMap1HH(ctrlr,ParValue) (pst_u8QSPIC_FlshMemMap1(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_FlshMemMap1HH(ctrlr) (pst_u8QSPIC_FlshMemMap1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_FlshMemMap1L(ctrlr,ParValue) (pst_u16QSPIC_FlshMemMap1(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_FlshMemMap1L(ctrlr) (pst_u16QSPIC_FlshMemMap1(ctrlr) -> u16L)
#define vSetQSPIC_FlshMemMap1H(ctrlr,ParValue) (pst_u16QSPIC_FlshMemMap1(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_FlshMemMap1H(ctrlr) (pst_u16QSPIC_FlshMemMap1(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_FlshMemMap1(ctrlr,ParValue)  (*pu32QSPIC_FlshMemMap1(ctrlr) = (ParValue))
#define u32GetQSPIC_FlshMemMap1(ctrlr)  (*pu32QSPIC_FlshMemMap1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_DirAccCtrl0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0109008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_DirAccCtrl0_REG__       0xC0109008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SMOD	:2; 	 /* 0..1  bit(s) R */
  uint32_t   RSRVD2	:2; 	 /* 2..3  bit(s) R */
  uint32_t   SDCE	:2; 	 /* 4..5  bit(s) R/W */
  uint32_t   PollWIP	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   RSRVD7	:1; 	 /* 7..7  bit(s) R */
  uint32_t   SCSD	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   RSRVD16	:5; 	 /* 16..20  bit(s) R */ 
  uint32_t   RSRVD21	:11; 	 /* 21..31  bit(s) R */
} QSPIC_DirAccCtrl0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_DirAccCtrl0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_DirAccCtrl0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_DirAccCtrl0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_DirAccCtrl0(ctrlr)     ((volatile QSPIC_DirAccCtrl0_bit_view_st *)\
(QSPIC_DirAccCtrl0_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_DirAccCtrl0(ctrlr)     ((volatile QSPIC_DirAccCtrl0_byte_view_st *)\
(QSPIC_DirAccCtrl0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_DirAccCtrl0(ctrlr)     ((volatile QSPIC_DirAccCtrl0_halfword_view_st *)\
(QSPIC_DirAccCtrl0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_DirAccCtrl0(ctrlr)     ((volatile u32QSPIC_DirAccCtrl0_word_view *)\
(QSPIC_DirAccCtrl0_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetQSPIC_DirAccCtrl0_SMOD(ctrlr) (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> SMOD)            
#define biGetQSPIC_DirAccCtrl0_RSRVD2(ctrlr) (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> RSRVD2)
#define biGetQSPIC_DirAccCtrl0_SDCE(ctrlr) (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> SDCE)
#define vSetQSPIC_DirAccCtrl0_SDCE(ctrlr,ParValue)  (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> SDCE=(ParValue))
#define biGetQSPIC_DirAccCtrl0_PollWIP(ctrlr) (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> PollWIP)
#define vSetQSPIC_DirAccCtrl0_PollWIP(ctrlr,ParValue)  (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> PollWIP=(ParValue))            
#define biGetQSPIC_DirAccCtrl0_RSRVD7(ctrlr) (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> RSRVD7)
#define biGetQSPIC_DirAccCtrl0_SCSD(ctrlr) (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> SCSD)
#define vSetQSPIC_DirAccCtrl0_SCSD(ctrlr,ParValue)  (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> SCSD=(ParValue))            
#define biGetQSPIC_DirAccCtrl0_RSRVD16(ctrlr) (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> RSRVD16)            
#define biGetQSPIC_DirAccCtrl0_RSRVD21(ctrlr) (pst_bitQSPIC_DirAccCtrl0(ctrlr) -> RSRVD21)
            
/* LL-struct byte access */
#define vSetQSPIC_DirAccCtrl0LL(ctrlr,ParValue) (pst_u8QSPIC_DirAccCtrl0(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_DirAccCtrl0LL(ctrlr) (pst_u8QSPIC_DirAccCtrl0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_DirAccCtrl0LH(ctrlr,ParValue) (pst_u8QSPIC_DirAccCtrl0(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_DirAccCtrl0LH(ctrlr) (pst_u8QSPIC_DirAccCtrl0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_DirAccCtrl0HL(ctrlr,ParValue) (pst_u8QSPIC_DirAccCtrl0(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_DirAccCtrl0HL(ctrlr) (pst_u8QSPIC_DirAccCtrl0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_DirAccCtrl0HH(ctrlr,ParValue) (pst_u8QSPIC_DirAccCtrl0(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_DirAccCtrl0HH(ctrlr) (pst_u8QSPIC_DirAccCtrl0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_DirAccCtrl0L(ctrlr,ParValue) (pst_u16QSPIC_DirAccCtrl0(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_DirAccCtrl0L(ctrlr) (pst_u16QSPIC_DirAccCtrl0(ctrlr) -> u16L)
#define vSetQSPIC_DirAccCtrl0H(ctrlr,ParValue) (pst_u16QSPIC_DirAccCtrl0(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_DirAccCtrl0H(ctrlr) (pst_u16QSPIC_DirAccCtrl0(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_DirAccCtrl0(ctrlr,ParValue)  (*pu32QSPIC_DirAccCtrl0(ctrlr) = (ParValue))
#define u32GetQSPIC_DirAccCtrl0(ctrlr)  (*pu32QSPIC_DirAccCtrl0(ctrlr) )                 

    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_DirAccCtrl1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010900C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_DirAccCtrl1_REG__       0xC010900CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SMOD	:2; 	 /* 0..1  bit(s) R */
  uint32_t   RSRVD2	:2; 	 /* 2..3  bit(s) R */
  uint32_t   SDCE	:2; 	 /* 4..5  bit(s) R/W */
  uint32_t   PollWIP	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   RSRVD7	:1; 	 /* 7..7  bit(s) R */
  uint32_t   SCSD	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   RSRVD16	:5; 	 /* 16..20  bit(s) R */ 
  uint32_t   RSRVD21	:11; 	 /* 21..31  bit(s) R */                                        
} QSPIC_DirAccCtrl1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_DirAccCtrl1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_DirAccCtrl1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_DirAccCtrl1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_DirAccCtrl1(ctrlr)     ((volatile QSPIC_DirAccCtrl1_bit_view_st *)\
(QSPIC_DirAccCtrl1_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_DirAccCtrl1(ctrlr)     ((volatile QSPIC_DirAccCtrl1_byte_view_st *)\
(QSPIC_DirAccCtrl1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_DirAccCtrl1(ctrlr)     ((volatile QSPIC_DirAccCtrl1_halfword_view_st *)\
(QSPIC_DirAccCtrl1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_DirAccCtrl1(ctrlr)     ((volatile u32QSPIC_DirAccCtrl1_word_view *)\
(QSPIC_DirAccCtrl1_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetQSPIC_DirAccCtrl1_SMOD(ctrlr) (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> SMOD)            
#define biGetQSPIC_DirAccCtrl1_RSRVD2(ctrlr) (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> RSRVD2)
#define biGetQSPIC_DirAccCtrl1_SDCE(ctrlr) (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> SDCE)
#define vSetQSPIC_DirAccCtrl1_SDCE(ctrlr,ParValue)  (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> SDCE=(ParValue))
#define biGetQSPIC_DirAccCtrl1_PollWIP(ctrlr) (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> PollWIP)
#define vSetQSPIC_DirAccCtrl1_PollWIP(ctrlr,ParValue)  (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> PollWIP=(ParValue))            
#define biGetQSPIC_DirAccCtrl1_RSRVD7(ctrlr) (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> RSRVD7)
#define biGetQSPIC_DirAccCtrl1_SCSD(ctrlr) (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> SCSD)
#define vSetQSPIC_DirAccCtrl1_SCSD(ctrlr,ParValue)  (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> SCSD=(ParValue))            
#define biGetQSPIC_DirAccCtrl1_RSRVD16(ctrlr) (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> RSRVD16)            
#define biGetQSPIC_DirAccCtrl1_RSRVD21(ctrlr) (pst_bitQSPIC_DirAccCtrl1(ctrlr) -> RSRVD21)
            
/* LL-struct byte access */
#define vSetQSPIC_DirAccCtrl1LL(ctrlr,ParValue) (pst_u8QSPIC_DirAccCtrl1(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_DirAccCtrl1LL(ctrlr) (pst_u8QSPIC_DirAccCtrl1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_DirAccCtrl1LH(ctrlr,ParValue) (pst_u8QSPIC_DirAccCtrl1(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_DirAccCtrl1LH(ctrlr) (pst_u8QSPIC_DirAccCtrl1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_DirAccCtrl1HL(ctrlr,ParValue) (pst_u8QSPIC_DirAccCtrl1(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_DirAccCtrl1HL(ctrlr) (pst_u8QSPIC_DirAccCtrl1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_DirAccCtrl1HH(ctrlr,ParValue) (pst_u8QSPIC_DirAccCtrl1(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_DirAccCtrl1HH(ctrlr) (pst_u8QSPIC_DirAccCtrl1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_DirAccCtrl1L(ctrlr,ParValue) (pst_u16QSPIC_DirAccCtrl1(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_DirAccCtrl1L(ctrlr) (pst_u16QSPIC_DirAccCtrl1(ctrlr) -> u16L)
#define vSetQSPIC_DirAccCtrl1H(ctrlr,ParValue) (pst_u16QSPIC_DirAccCtrl1(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_DirAccCtrl1H(ctrlr) (pst_u16QSPIC_DirAccCtrl1(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_DirAccCtrl1(ctrlr,ParValue)  (*pu32QSPIC_DirAccCtrl1(ctrlr) = (ParValue))
#define u32GetQSPIC_DirAccCtrl1(ctrlr)  (*pu32QSPIC_DirAccCtrl1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_DirRdCtrl0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0109010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_DirRdCtrl0_REG__       0xC0109010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SpiCmdIOCtrl	:2; 	 /* 0..1  bit(s) R */
  uint32_t   SpiAdrIOCtrl	:2; 	 /* 2..3  bit(s) R/W */
  uint32_t   SpiDmyIOCtrl	:2; 	 /* 4..5  bit(s) R/W */
  uint32_t   SpiDatIOCtrl	:2; 	 /* 6..7  bit(s) R/W */
  uint32_t   RSRVD8	:3; 	 /* 8..10  bit(s) R */
  uint32_t   SpiAddrByteCnt	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   SpiDmyByteCnt	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   RSRVD16	:8; 	 /* 16..23  bit(s) R */ 
  uint32_t   SpiRdCmdOp	:8; 	 /* 24..31  bit(s) R/W */                                        
} QSPIC_DirRdCtrl0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_DirRdCtrl0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_DirRdCtrl0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_DirRdCtrl0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_DirRdCtrl0(ctrlr)     ((volatile QSPIC_DirRdCtrl0_bit_view_st *)\
(QSPIC_DirRdCtrl0_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_DirRdCtrl0(ctrlr)     ((volatile QSPIC_DirRdCtrl0_byte_view_st *)\
(QSPIC_DirRdCtrl0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_DirRdCtrl0(ctrlr)     ((volatile QSPIC_DirRdCtrl0_halfword_view_st *)\
(QSPIC_DirRdCtrl0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_DirRdCtrl0(ctrlr)     ((volatile u32QSPIC_DirRdCtrl0_word_view *)\
(QSPIC_DirRdCtrl0_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetQSPIC_DirRdCtrl0_SpiCmdIOCtrl(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiCmdIOCtrl)
#define biGetQSPIC_DirRdCtrl0_SpiAdrIOCtrl(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiAdrIOCtrl)
#define vSetQSPIC_DirRdCtrl0_SpiAdrIOCtrl(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiAdrIOCtrl=(ParValue))
#define biGetQSPIC_DirRdCtrl0_SpiDmyIOCtrl(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiDmyIOCtrl)
#define vSetQSPIC_DirRdCtrl0_SpiDmyIOCtrl(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiDmyIOCtrl=(ParValue))
#define biGetQSPIC_DirRdCtrl0_SpiDatIOCtrl(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiDatIOCtrl)
#define vSetQSPIC_DirRdCtrl0_SpiDatIOCtrl(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiDatIOCtrl=(ParValue))            
#define biGetQSPIC_DirRdCtrl0_RSRVD8(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> RSRVD8)
#define biGetQSPIC_DirRdCtrl0_SpiAddrByteCnt(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiAddrByteCnt)
#define vSetQSPIC_DirRdCtrl0_SpiAddrByteCnt(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiAddrByteCnt=(ParValue))
#define biGetQSPIC_DirRdCtrl0_SpiDmyByteCnt(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiDmyByteCnt)
#define vSetQSPIC_DirRdCtrl0_SpiDmyByteCnt(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiDmyByteCnt=(ParValue))            
#define biGetQSPIC_DirRdCtrl0_RSRVD16(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> RSRVD16)
#define biGetQSPIC_DirRdCtrl0_SpiRdCmdOp(ctrlr) (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiRdCmdOp)
#define vSetQSPIC_DirRdCtrl0_SpiRdCmdOp(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl0(ctrlr) -> SpiRdCmdOp=(ParValue))
            
/* LL-struct byte access */
#define vSetQSPIC_DirRdCtrl0LL(ctrlr,ParValue) (pst_u8QSPIC_DirRdCtrl0(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_DirRdCtrl0LL(ctrlr) (pst_u8QSPIC_DirRdCtrl0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_DirRdCtrl0LH(ctrlr,ParValue) (pst_u8QSPIC_DirRdCtrl0(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_DirRdCtrl0LH(ctrlr) (pst_u8QSPIC_DirRdCtrl0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_DirRdCtrl0HL(ctrlr,ParValue) (pst_u8QSPIC_DirRdCtrl0(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_DirRdCtrl0HL(ctrlr) (pst_u8QSPIC_DirRdCtrl0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_DirRdCtrl0HH(ctrlr,ParValue) (pst_u8QSPIC_DirRdCtrl0(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_DirRdCtrl0HH(ctrlr) (pst_u8QSPIC_DirRdCtrl0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_DirRdCtrl0L(ctrlr,ParValue) (pst_u16QSPIC_DirRdCtrl0(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_DirRdCtrl0L(ctrlr) (pst_u16QSPIC_DirRdCtrl0(ctrlr) -> u16L)
#define vSetQSPIC_DirRdCtrl0H(ctrlr,ParValue) (pst_u16QSPIC_DirRdCtrl0(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_DirRdCtrl0H(ctrlr) (pst_u16QSPIC_DirRdCtrl0(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_DirRdCtrl0(ctrlr,ParValue)  (*pu32QSPIC_DirRdCtrl0(ctrlr) = (ParValue))
#define u32GetQSPIC_DirRdCtrl0(ctrlr)  (*pu32QSPIC_DirRdCtrl0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_DirRdCtrl1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0109014                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_DirRdCtrl1_REG__       0xC0109014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SpiCmdIOCtrl	:2; 	 /* 0..1  bit(s) R */
  uint32_t   SpiAdrIOCtrl	:2; 	 /* 2..3  bit(s) R/W */
  uint32_t   SpiDmyIOCtrl	:2; 	 /* 4..5  bit(s) R/W */
  uint32_t   SpiDatIOCtrl	:2; 	 /* 6..7  bit(s) R/W */
  uint32_t   RSRVD8	:3; 	 /* 8..10  bit(s) R */
  uint32_t   SpiAddrByteCnt	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   SpiDmyByteCnt	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   RSRVD16	:8; 	 /* 16..23  bit(s) R */ 
  uint32_t   SpiRdCmdOp	:8; 	 /* 24..31  bit(s) R/W */ 
} QSPIC_DirRdCtrl1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_DirRdCtrl1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_DirRdCtrl1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_DirRdCtrl1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_DirRdCtrl1(ctrlr)     ((volatile QSPIC_DirRdCtrl1_bit_view_st *)\
(QSPIC_DirRdCtrl1_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_DirRdCtrl1(ctrlr)     ((volatile QSPIC_DirRdCtrl1_byte_view_st *)\
(QSPIC_DirRdCtrl1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_DirRdCtrl1(ctrlr)     ((volatile QSPIC_DirRdCtrl1_halfword_view_st *)\
(QSPIC_DirRdCtrl1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_DirRdCtrl1(ctrlr)     ((volatile u32QSPIC_DirRdCtrl1_word_view *)\
(QSPIC_DirRdCtrl1_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetQSPIC_DirRdCtrl1_SpiCmdIOCtrl(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiCmdIOCtrl)
#define biGetQSPIC_DirRdCtrl1_SpiAdrIOCtrl(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiAdrIOCtrl)
#define vSetQSPIC_DirRdCtrl1_SpiAdrIOCtrl(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiAdrIOCtrl=(ParValue))
#define biGetQSPIC_DirRdCtrl1_SpiDmyIOCtrl(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiDmyIOCtrl)
#define vSetQSPIC_DirRdCtrl1_SpiDmyIOCtrl(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiDmyIOCtrl=(ParValue))
#define biGetQSPIC_DirRdCtrl1_SpiDatIOCtrl(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiDatIOCtrl)
#define vSetQSPIC_DirRdCtrl1_SpiDatIOCtrl(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiDatIOCtrl=(ParValue))            
#define biGetQSPIC_DirRdCtrl1_RSRVD8(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> RSRVD8)
#define biGetQSPIC_DirRdCtrl1_SpiAddrByteCnt(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiAddrByteCnt)
#define vSetQSPIC_DirRdCtrl1_SpiAddrByteCnt(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiAddrByteCnt=(ParValue))
#define biGetQSPIC_DirRdCtrl1_SpiDmyByteCnt(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiDmyByteCnt)
#define vSetQSPIC_DirRdCtrl1_SpiDmyByteCnt(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiDmyByteCnt=(ParValue))            
#define biGetQSPIC_DirRdCtrl1_RSRVD16(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> RSRVD16)
#define biGetQSPIC_DirRdCtrl1_SpiRdCmdOp(ctrlr) (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiRdCmdOp)
#define vSetQSPIC_DirRdCtrl1_SpiRdCmdOp(ctrlr,ParValue)  (pst_bitQSPIC_DirRdCtrl1(ctrlr) -> SpiRdCmdOp=(ParValue))
            
/* LL-struct byte access */
#define vSetQSPIC_DirRdCtrl1LL(ctrlr,ParValue) (pst_u8QSPIC_DirRdCtrl1(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_DirRdCtrl1LL(ctrlr) (pst_u8QSPIC_DirRdCtrl1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_DirRdCtrl1LH(ctrlr,ParValue) (pst_u8QSPIC_DirRdCtrl1(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_DirRdCtrl1LH(ctrlr) (pst_u8QSPIC_DirRdCtrl1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_DirRdCtrl1HL(ctrlr,ParValue) (pst_u8QSPIC_DirRdCtrl1(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_DirRdCtrl1HL(ctrlr) (pst_u8QSPIC_DirRdCtrl1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_DirRdCtrl1HH(ctrlr,ParValue) (pst_u8QSPIC_DirRdCtrl1(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_DirRdCtrl1HH(ctrlr) (pst_u8QSPIC_DirRdCtrl1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_DirRdCtrl1L(ctrlr,ParValue) (pst_u16QSPIC_DirRdCtrl1(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_DirRdCtrl1L(ctrlr) (pst_u16QSPIC_DirRdCtrl1(ctrlr) -> u16L)
#define vSetQSPIC_DirRdCtrl1H(ctrlr,ParValue) (pst_u16QSPIC_DirRdCtrl1(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_DirRdCtrl1H(ctrlr) (pst_u16QSPIC_DirRdCtrl1(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_DirRdCtrl1(ctrlr,ParValue)  (*pu32QSPIC_DirRdCtrl1(ctrlr) = (ParValue))
#define u32GetQSPIC_DirRdCtrl1(ctrlr)  (*pu32QSPIC_DirRdCtrl1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_PrgAccCtrl0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0109400                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_PrgAccCtrl0_REG__       0xC0109400U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SMOD	:2; 	 /* 0..1  bit(s) R */
  uint32_t   RSRVD2	:2; 	 /* 2..3  bit(s) R */
  uint32_t   SDCE	:2; 	 /* 4..5  bit(s) R/W */
  uint32_t   RSRVD6	:2; 	 /* 6..7  bit(s) R */
  uint32_t   SCSD	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   RSRVD16	:5; 	 /* 16..20  bit(s) R */ 
  uint32_t   RSRVD21	:11; 	 /* 21..31  bit(s) R */
} QSPIC_PrgAccCtrl0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_PrgAccCtrl0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_PrgAccCtrl0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_PrgAccCtrl0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_PrgAccCtrl0(ctrlr)     ((volatile QSPIC_PrgAccCtrl0_bit_view_st *)\
(QSPIC_PrgAccCtrl0_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_PrgAccCtrl0(ctrlr)     ((volatile QSPIC_PrgAccCtrl0_byte_view_st *)\
(QSPIC_PrgAccCtrl0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_PrgAccCtrl0(ctrlr)     ((volatile QSPIC_PrgAccCtrl0_halfword_view_st *)\
(QSPIC_PrgAccCtrl0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_PrgAccCtrl0(ctrlr)     ((volatile u32QSPIC_PrgAccCtrl0_word_view *)\
(QSPIC_PrgAccCtrl0_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetQSPIC_PrgAccCtrl0_SMOD(ctrlr) (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> SMOD)            
#define biGetQSPIC_PrgAccCtrl0_RSRVD2(ctrlr) (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> RSRVD2)
#define biGetQSPIC_PrgAccCtrl0_SDCE(ctrlr) (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> SDCE)
#define vSetQSPIC_PrgAccCtrl0_SDCE(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> SDCE=(ParValue))            
#define biGetQSPIC_PrgAccCtrl0_RSRVD6(ctrlr) (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> RSRVD6)
#define biGetQSPIC_PrgAccCtrl0_SCSD(ctrlr) (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> SCSD)
#define vSetQSPIC_PrgAccCtrl0_SCSD(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> SCSD=(ParValue))
#define biGetQSPIC_PrgAccCtrl0_RSRVD16(ctrlr) (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> RSRVD16)
#define biGetQSPIC_PrgAccCtrl0_RSRVD21(ctrlr) (pst_bitQSPIC_PrgAccCtrl0(ctrlr) -> RSRVD21)
            
/* LL-struct byte access */
#define vSetQSPIC_PrgAccCtrl0LL(ctrlr,ParValue) (pst_u8QSPIC_PrgAccCtrl0(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_PrgAccCtrl0LL(ctrlr) (pst_u8QSPIC_PrgAccCtrl0(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_PrgAccCtrl0LH(ctrlr,ParValue) (pst_u8QSPIC_PrgAccCtrl0(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_PrgAccCtrl0LH(ctrlr) (pst_u8QSPIC_PrgAccCtrl0(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_PrgAccCtrl0HL(ctrlr,ParValue) (pst_u8QSPIC_PrgAccCtrl0(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_PrgAccCtrl0HL(ctrlr) (pst_u8QSPIC_PrgAccCtrl0(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_PrgAccCtrl0HH(ctrlr,ParValue) (pst_u8QSPIC_PrgAccCtrl0(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_PrgAccCtrl0HH(ctrlr) (pst_u8QSPIC_PrgAccCtrl0(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_PrgAccCtrl0L(ctrlr,ParValue) (pst_u16QSPIC_PrgAccCtrl0(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_PrgAccCtrl0L(ctrlr) (pst_u16QSPIC_PrgAccCtrl0(ctrlr) -> u16L)
#define vSetQSPIC_PrgAccCtrl0H(ctrlr,ParValue) (pst_u16QSPIC_PrgAccCtrl0(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_PrgAccCtrl0H(ctrlr) (pst_u16QSPIC_PrgAccCtrl0(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_PrgAccCtrl0(ctrlr,ParValue)  (*pu32QSPIC_PrgAccCtrl0(ctrlr) = (ParValue))
#define u32GetQSPIC_PrgAccCtrl0(ctrlr)  (*pu32QSPIC_PrgAccCtrl0(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_PrgAccCtrl1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0109404                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_PrgAccCtrl1_REG__       0xC0109404U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SpiCycGo	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   SpiCsNum	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   RSRVD2	:2; 	 /* 2..3  bit(s) R */
  uint32_t   PriBufEn	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   SecBufEn	:1; 	 /* 5..5  bit(s) R/W */
  uint32_t   RSRVD6	:10; 	 /* 6..15  bit(s) R */
  uint32_t   PriBufDatByteCnt	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   RSRVD19	:5; 	 /* 19..23  bit(s) R */ 
  uint32_t   SecBufDatByteCnt	:8; 	 /* 24..31  bit(s) R/W */                    
} QSPIC_PrgAccCtrl1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_PrgAccCtrl1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_PrgAccCtrl1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_PrgAccCtrl1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_PrgAccCtrl1(ctrlr)     ((volatile QSPIC_PrgAccCtrl1_bit_view_st *)\
(QSPIC_PrgAccCtrl1_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_PrgAccCtrl1(ctrlr)     ((volatile QSPIC_PrgAccCtrl1_byte_view_st *)\
(QSPIC_PrgAccCtrl1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_PrgAccCtrl1(ctrlr)     ((volatile QSPIC_PrgAccCtrl1_halfword_view_st *)\
(QSPIC_PrgAccCtrl1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_PrgAccCtrl1(ctrlr)     ((volatile u32QSPIC_PrgAccCtrl1_word_view *)\
(QSPIC_PrgAccCtrl1_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPIC_PrgAccCtrl1_SpiCycGo(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> SpiCycGo)
#define vSetQSPIC_PrgAccCtrl1_SpiCycGo(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> SpiCycGo=(ParValue))
#define biGetQSPIC_PrgAccCtrl1_SpiCsNum(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> SpiCsNum)
#define vSetQSPIC_PrgAccCtrl1_SpiCsNum(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> SpiCsNum=(ParValue))            
#define biGetQSPIC_PrgAccCtrl1_RSRVD2(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> RSRVD2)
#define biGetQSPIC_PrgAccCtrl1_PriBufEn(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> PriBufEn)
#define vSetQSPIC_PrgAccCtrl1_PriBufEn(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> PriBufEn=(ParValue))
#define biGetQSPIC_PrgAccCtrl1_SecBufEn(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> SecBufEn)
#define vSetQSPIC_PrgAccCtrl1_SecBufEn(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> SecBufEn=(ParValue))            
#define biGetQSPIC_PrgAccCtrl1_RSRVD6(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> RSRVD6)
#define biGetQSPIC_PrgAccCtrl1_PriBufDatByteCnt(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> PriBufDatByteCnt)
#define vSetQSPIC_PrgAccCtrl1_PriBufDatByteCnt(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> PriBufDatByteCnt=(ParValue))            
#define biGetQSPIC_PrgAccCtrl1_RSRVD19(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> RSRVD19)
#define biGetQSPIC_PrgAccCtrl1_SecBufDatByteCnt(ctrlr) (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> SecBufDatByteCnt)
#define vSetQSPIC_PrgAccCtrl1_SecBufDatByteCnt(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccCtrl1(ctrlr) -> SecBufDatByteCnt=(ParValue))
            
/* LL-struct byte access */
#define vSetQSPIC_PrgAccCtrl1LL(ctrlr,ParValue) (pst_u8QSPIC_PrgAccCtrl1(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_PrgAccCtrl1LL(ctrlr) (pst_u8QSPIC_PrgAccCtrl1(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_PrgAccCtrl1LH(ctrlr,ParValue) (pst_u8QSPIC_PrgAccCtrl1(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_PrgAccCtrl1LH(ctrlr) (pst_u8QSPIC_PrgAccCtrl1(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_PrgAccCtrl1HL(ctrlr,ParValue) (pst_u8QSPIC_PrgAccCtrl1(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_PrgAccCtrl1HL(ctrlr) (pst_u8QSPIC_PrgAccCtrl1(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_PrgAccCtrl1HH(ctrlr,ParValue) (pst_u8QSPIC_PrgAccCtrl1(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_PrgAccCtrl1HH(ctrlr) (pst_u8QSPIC_PrgAccCtrl1(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_PrgAccCtrl1L(ctrlr,ParValue) (pst_u16QSPIC_PrgAccCtrl1(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_PrgAccCtrl1L(ctrlr) (pst_u16QSPIC_PrgAccCtrl1(ctrlr) -> u16L)
#define vSetQSPIC_PrgAccCtrl1H(ctrlr,ParValue) (pst_u16QSPIC_PrgAccCtrl1(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_PrgAccCtrl1H(ctrlr) (pst_u16QSPIC_PrgAccCtrl1(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_PrgAccCtrl1(ctrlr,ParValue)  (*pu32QSPIC_PrgAccCtrl1(ctrlr) = (ParValue))
#define u32GetQSPIC_PrgAccCtrl1(ctrlr)  (*pu32QSPIC_PrgAccCtrl1(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_PrgAccIntEn                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0109408                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_PrgAccIntEn_REG__       0xC0109408U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SpiIntEn	:1; 	 /* 0..0  bit(s) R/W */ 
  uint32_t   RSRVD1	:31; 	 /* 1..31  bit(s) R */                    
} QSPIC_PrgAccIntEn_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_PrgAccIntEn_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_PrgAccIntEn_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_PrgAccIntEn_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_PrgAccIntEn(ctrlr)     ((volatile QSPIC_PrgAccIntEn_bit_view_st *)\
(QSPIC_PrgAccIntEn_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_PrgAccIntEn(ctrlr)     ((volatile QSPIC_PrgAccIntEn_byte_view_st *)\
(QSPIC_PrgAccIntEn_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_PrgAccIntEn(ctrlr)     ((volatile QSPIC_PrgAccIntEn_halfword_view_st *)\
(QSPIC_PrgAccIntEn_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_PrgAccIntEn(ctrlr)     ((volatile u32QSPIC_PrgAccIntEn_word_view *)\
(QSPIC_PrgAccIntEn_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPIC_PrgAccIntEn_SpiIntEn(ctrlr) (pst_bitQSPIC_PrgAccIntEn(ctrlr) -> SpiIntEn)
#define vSetQSPIC_PrgAccIntEn_SpiIntEn(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccIntEn(ctrlr) -> SpiIntEn=(ParValue))            
#define biGetQSPIC_PrgAccIntEn_RSRVD1(ctrlr) (pst_bitQSPIC_PrgAccIntEn(ctrlr) -> RSRVD1)
            
/* LL-struct byte access */
#define vSetQSPIC_PrgAccIntEnLL(ctrlr,ParValue) (pst_u8QSPIC_PrgAccIntEn(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_PrgAccIntEnLL(ctrlr) (pst_u8QSPIC_PrgAccIntEn(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_PrgAccIntEnLH(ctrlr,ParValue) (pst_u8QSPIC_PrgAccIntEn(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_PrgAccIntEnLH(ctrlr) (pst_u8QSPIC_PrgAccIntEn(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_PrgAccIntEnHL(ctrlr,ParValue) (pst_u8QSPIC_PrgAccIntEn(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_PrgAccIntEnHL(ctrlr) (pst_u8QSPIC_PrgAccIntEn(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_PrgAccIntEnHH(ctrlr,ParValue) (pst_u8QSPIC_PrgAccIntEn(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_PrgAccIntEnHH(ctrlr) (pst_u8QSPIC_PrgAccIntEn(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_PrgAccIntEnL(ctrlr,ParValue) (pst_u16QSPIC_PrgAccIntEn(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_PrgAccIntEnL(ctrlr) (pst_u16QSPIC_PrgAccIntEn(ctrlr) -> u16L)
#define vSetQSPIC_PrgAccIntEnH(ctrlr,ParValue) (pst_u16QSPIC_PrgAccIntEn(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_PrgAccIntEnH(ctrlr) (pst_u16QSPIC_PrgAccIntEn(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_PrgAccIntEn(ctrlr,ParValue)  (*pu32QSPIC_PrgAccIntEn(ctrlr) = (ParValue))
#define u32GetQSPIC_PrgAccIntEn(ctrlr)  (*pu32QSPIC_PrgAccIntEn(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_PrgAccStat                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010940C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_PrgAccStat_REG__       0xC010940CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SpiCycDone	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   SpiCycInPrgrs	:1; 	 /* 1..1  bit(s) R/W */ 
  uint32_t   RSRVD2	:30; 	 /* 2..31  bit(s) R */                    
} QSPIC_PrgAccStat_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} QSPIC_PrgAccStat_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} QSPIC_PrgAccStat_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32QSPIC_PrgAccStat_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_PrgAccStat(ctrlr)     ((volatile QSPIC_PrgAccStat_bit_view_st *)\
(QSPIC_PrgAccStat_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8QSPIC_PrgAccStat(ctrlr)     ((volatile QSPIC_PrgAccStat_byte_view_st *)\
(QSPIC_PrgAccStat_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16QSPIC_PrgAccStat(ctrlr)     ((volatile QSPIC_PrgAccStat_halfword_view_st *)\
(QSPIC_PrgAccStat_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32QSPIC_PrgAccStat(ctrlr)     ((volatile u32QSPIC_PrgAccStat_word_view *)\
(QSPIC_PrgAccStat_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPIC_PrgAccStat_SpiCycDone(ctrlr) (pst_bitQSPIC_PrgAccStat(ctrlr) -> SpiCycDone)
#define vSetQSPIC_PrgAccStat_SpiCycDone(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccStat(ctrlr) -> SpiCycDone=(ParValue))
#define biGetQSPIC_PrgAccStat_SpiCycInPrgrs(ctrlr) (pst_bitQSPIC_PrgAccStat(ctrlr) -> SpiCycInPrgrs)
#define vSetQSPIC_PrgAccStat_SpiCycInPrgrs(ctrlr,ParValue)  (pst_bitQSPIC_PrgAccStat(ctrlr) -> SpiCycInPrgrs=(ParValue))            
#define biGetQSPIC_PrgAccStat_RSRVD2(ctrlr) (pst_bitQSPIC_PrgAccStat(ctrlr) -> RSRVD2)
            
/* LL-struct byte access */
#define vSetQSPIC_PrgAccStatLL(ctrlr,ParValue) (pst_u8QSPIC_PrgAccStat(ctrlr) -> u8LL = (ParValue))
#define u8GetQSPIC_PrgAccStatLL(ctrlr) (pst_u8QSPIC_PrgAccStat(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetQSPIC_PrgAccStatLH(ctrlr,ParValue) (pst_u8QSPIC_PrgAccStat(ctrlr) -> u8LH = (ParValue))
#define u8GetQSPIC_PrgAccStatLH(ctrlr) (pst_u8QSPIC_PrgAccStat(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetQSPIC_PrgAccStatHL(ctrlr,ParValue) (pst_u8QSPIC_PrgAccStat(ctrlr) -> u8HL = (ParValue))
#define u8GetQSPIC_PrgAccStatHL(ctrlr) (pst_u8QSPIC_PrgAccStat(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetQSPIC_PrgAccStatHH(ctrlr,ParValue) (pst_u8QSPIC_PrgAccStat(ctrlr) -> u8HH = (ParValue))
#define u8GetQSPIC_PrgAccStatHH(ctrlr) (pst_u8QSPIC_PrgAccStat(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetQSPIC_PrgAccStatL(ctrlr,ParValue) (pst_u16QSPIC_PrgAccStat(ctrlr) -> u16L = (ParValue))
#define u16GetQSPIC_PrgAccStatL(ctrlr) (pst_u16QSPIC_PrgAccStat(ctrlr) -> u16L)
#define vSetQSPIC_PrgAccStatH(ctrlr,ParValue) (pst_u16QSPIC_PrgAccStat(ctrlr) -> u16H = (ParValue))
#define u16GetQSPIC_PrgAccStatH(ctrlr) (pst_u16QSPIC_PrgAccStat(ctrlr) -> u16H)
            
/* Word access */
#define vSetQSPIC_PrgAccStat(ctrlr,ParValue)  (*pu32QSPIC_PrgAccStat(ctrlr) = (ParValue))
#define u32GetQSPIC_PrgAccStat(ctrlr)  (*pu32QSPIC_PrgAccStat(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_PriBufDatN                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0109500                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_PriBufDatN_REG__       0xC0109500U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   PriBufDatN	:8; 	 /* 0..7  bit(s) R/W */                    
} QSPIC_PriBufDatN_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8QSPIC_PriBufDatN_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_PriBufDatN(ctrlr,ch)     ((volatile QSPIC_PriBufDatN_bit_view_st *)\
(QSPIC_PriBufDatN_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x001U)))
        
/* Pointer to BYTE  */
#define pu8QSPIC_PriBufDatN(ctrlr,ch)     ((volatile u8QSPIC_PriBufDatN_byte_view *)\
(QSPIC_PriBufDatN_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x001U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPIC_PriBufDatN_PriBufDatN(ctrlr,ch) (pst_bitQSPIC_PriBufDatN(ctrlr,ch) -> PriBufDatN)
#define vSetQSPIC_PriBufDatN_PriBufDatN(ctrlr,ch,ParValue)  (pst_bitQSPIC_PriBufDatN(ctrlr,ch) -> PriBufDatN=(ParValue))
            
/* byte access */
#define vSetQSPIC_PriBufDatN(ctrlr,ch,ParValue) (*pu8QSPIC_PriBufDatN(ctrlr,ch) = (ParValue))
#define u8GetQSPIC_PriBufDatN(ctrlr,ch) (*pu8QSPIC_PriBufDatN(ctrlr,ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: QSPIC_SecBufDatN                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0109600                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define QSPIC_SecBufDatN_REG__       0xC0109600U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   SecBufDatN	:8; 	 /* 0..7  bit(s) R/W */                    
} QSPIC_SecBufDatN_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8QSPIC_SecBufDatN_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitQSPIC_SecBufDatN(ctrlr,ch)     ((volatile QSPIC_SecBufDatN_bit_view_st *)\
(QSPIC_SecBufDatN_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x001U)))
        
/* Pointer to BYTE  */
#define pu8QSPIC_SecBufDatN(ctrlr,ch)     ((volatile u8QSPIC_SecBufDatN_byte_view *)\
(QSPIC_SecBufDatN_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x001U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetQSPIC_SecBufDatN_SecBufDatN(ctrlr,ch) (pst_bitQSPIC_SecBufDatN(ctrlr,ch) -> SecBufDatN)
#define vSetQSPIC_SecBufDatN_SecBufDatN(ctrlr,ch,ParValue)  (pst_bitQSPIC_SecBufDatN(ctrlr,ch) -> SecBufDatN=(ParValue))
            
/* byte access */
#define vSetQSPIC_SecBufDatN(ctrlr,ch,ParValue) (*pu8QSPIC_SecBufDatN(ctrlr,ch) = (ParValue))
#define u8GetQSPIC_SecBufDatN(ctrlr,ch) (*pu8QSPIC_SecBufDatN(ctrlr,ch) )

/******************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */ 
/******************************************************************************/

/****************************************************************************/	
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
** |
** |         Rule 6.4  [R]   : Bitfields can only have `unsigned int' or `signed int' types
** |                           Used for bit definitons generated by converter tool
** |         Rule 19.10 [R] : In function-like macro definition, wrap each parameter reference in parentheses
** |                          Used to call macros generated by converter tool
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/
/****************************************************************************/

#endif /* QSPICIO_H */ 
    
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

