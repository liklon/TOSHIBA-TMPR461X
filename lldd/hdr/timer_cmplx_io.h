
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : TIMERS_CMPLX_PM 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  18:02:28.023+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.10 $ 
/  Excel Sheet ver.             : vv1.1
/  Excel Sheet date             : 2013-Jun-21
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : TIMER_CMPLX low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_CMPLX
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.10 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef TIMERS_CMPLX_PMIO_H
#define TIMERS_CMPLX_PMIO_H

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

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_TIMER_CMPLX_IO_H_REVISION     "$Revision: 1.10 $"
#define LLDD_TIMER_CMPLX_IO_H_TAG          "$Name: LLDD_1_6 $"

/****************************************************************************
*                          CONTROLER SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
 
typedef enum tag_timer_cmplx_ch_def_e
{
  TIMER_CMPLX_PM_0__ =0,
  TIMER_CMPLX_PM_1__ =0x1000,  
  TIMER_CMPLX_PM_2__ =0x2000,  
  TIMER_CMPLX_PM_3__ =0x3000,  
  TIMER_CMPLX_PM_4__ =0x4000,  
  TIMER_CMPLX_PM_5__ =0x5000 
} timer_cmplx_ch_def_e;
  
         
    
/****************************************************************************   
*                                                                               
*       REGISTER: TBRUN                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC031C000                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TBRUN_REG__       0xC031C000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   TRUN	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   OFI	:1; 	 /* 1..1  bit(s) R/W */
  uint8_t   PRUN	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   IDL	:1; 	 /* 3..3  bit(s) R/W */
  uint8_t   	:2; 	 /* 4..5  bit(s) R */
  uint8_t   SYNC	:1; 	 /* 6..6  bit(s) R/W */
  uint8_t   DBE	:1; 	 /* 7..7  bit(s) R/W */                    
} TBRUN_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8TBRUN_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTBRUN(ctrlr)     ((volatile TBRUN_bit_view_st *)\
(TBRUN_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE  */
#define pu8TBRUN(ctrlr)     ((volatile u8TBRUN_byte_view *)\
(TBRUN_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetTBRUN_TRUN(ctrlr) (pst_bitTBRUN(ctrlr) -> TRUN)
#define vSetTBRUN_TRUN(ctrlr,ParValue)  (pst_bitTBRUN(ctrlr) -> TRUN=(ParValue))
#define biGetTBRUN_OFI(ctrlr) (pst_bitTBRUN(ctrlr) -> OFI)
#define vSetTBRUN_OFI(ctrlr,ParValue)  (pst_bitTBRUN(ctrlr) -> OFI=(ParValue))
#define biGetTBRUN_PRUN(ctrlr) (pst_bitTBRUN(ctrlr) -> PRUN)
#define vSetTBRUN_PRUN(ctrlr,ParValue)  (pst_bitTBRUN(ctrlr) -> PRUN=(ParValue))
#define biGetTBRUN_IDL(ctrlr) (pst_bitTBRUN(ctrlr) -> IDL)
#define vSetTBRUN_IDL(ctrlr,ParValue)  (pst_bitTBRUN(ctrlr) -> IDL=(ParValue))
#define biGetTBRUN_SYNC(ctrlr) (pst_bitTBRUN(ctrlr) -> SYNC)
#define vSetTBRUN_SYNC(ctrlr,ParValue)  (pst_bitTBRUN(ctrlr) -> SYNC=(ParValue))
#define biGetTBRUN_DBE(ctrlr) (pst_bitTBRUN(ctrlr) -> DBE)
#define vSetTBRUN_DBE(ctrlr,ParValue)  (pst_bitTBRUN(ctrlr) -> DBE=(ParValue))
            
/* byte access */
#define vSetTBRUN(ctrlr,ParValue) (*pu8TBRUN(ctrlr) = (ParValue))
#define u8GetTBRUN(ctrlr) (*pu8TBRUN(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: TBMOD                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC031C004                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TBMOD_REG__       0xC031C004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CLK	:3; 	 /* 0..2  bit(s) R/W */
  uint16_t   CLE	:1; 	 /* 3..3  bit(s) R/W */
  uint16_t   CPM	:2; 	 /* 4..5  bit(s) R/W */
  uint16_t   	:2; 	 /* 6..7  bit(s) R */
  uint16_t   CP0	:1; 	 /* 8..8  bit(s) W */
  uint16_t   RSRVD9	:1; 	 /* 9..9  bit(s) R/W */ 
  uint16_t   	:6; 	 /* 10..31  bit(s) R */                    
} TBMOD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} TBMOD_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16TBMOD_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTBMOD(ctrlr)     ((volatile TBMOD_bit_view_st *)\
(TBMOD_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TBMOD(ctrlr)     ((volatile TBMOD_byte_view_st *)\
(TBMOD_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16TBMOD(ctrlr)     ((volatile u16TBMOD_halfword_view *)\
(TBMOD_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetTBMOD_CLK(ctrlr) (pst_bitTBMOD(ctrlr) -> CLK)
#define vSetTBMOD_CLK(ctrlr,ParValue)  (pst_bitTBMOD(ctrlr) -> CLK=(ParValue))
#define biGetTBMOD_CLE(ctrlr) (pst_bitTBMOD(ctrlr) -> CLE)
#define vSetTBMOD_CLE(ctrlr,ParValue)  (pst_bitTBMOD(ctrlr) -> CLE=(ParValue))
#define biGetTBMOD_CPM(ctrlr) (pst_bitTBMOD(ctrlr) -> CPM)
#define vSetTBMOD_CPM(ctrlr,ParValue)  (pst_bitTBMOD(ctrlr) -> CPM=(ParValue)) 
#define vSetTBMOD_CP0(ctrlr,ParValue) (pst_bitTBMOD(ctrlr) -> CP0=(ParValue))
#define biGetTBMOD_RSRVD9(ctrlr) (pst_bitTBMOD(ctrlr) -> RSRVD9)
#define vSetTBMOD_RSRVD9(ctrlr,ParValue)  (pst_bitTBMOD(ctrlr) -> RSRVD9=(ParValue))
            
/* L-struct byte access */
#define vSetTBMODL(ctrlr,ParValue) (pst_u8TBMOD(ctrlr) -> u8L = (ParValue))
#define u8GetTBMODL(ctrlr) (pst_u8TBMOD(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetTBMODH(ctrlr,ParValue) (pst_u8TBMOD(ctrlr) -> u8H = (ParValue))
#define u8GetTBMODH(ctrlr) (pst_u8TBMOD(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetTBMOD(ctrlr,ParValue) (*pu16TBMOD(ctrlr)  = (ParValue))
#define u16GetTBMOD(ctrlr) (*pu16TBMOD(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: TBFF                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC031C008                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TBFF_REG__       0xC031C008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   MOD	:2; 	 /* 0..1  bit(s) W */
  uint8_t   INVC0	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   INVC1	:1; 	 /* 3..3  bit(s) R/W */
  uint8_t   INVL0	:1; 	 /* 4..4  bit(s) R/W */
  uint8_t   INVL1	:1; 	 /* 5..5  bit(s) R/W */ 
  uint8_t   	:2; 	 /* 6..31  bit(s) R */                    
} TBFF_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8TBFF_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTBFF(ctrlr)     ((volatile TBFF_bit_view_st *)\
(TBFF_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE  */
#define pu8TBFF(ctrlr)     ((volatile u8TBFF_byte_view *)\
(TBFF_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetTBFF_MOD(ctrlr,ParValue) (pst_bitTBFF(ctrlr) -> MOD=(ParValue))
#define biGetTBFF_INVC0(ctrlr) (pst_bitTBFF(ctrlr) -> INVC0)
#define vSetTBFF_INVC0(ctrlr,ParValue)  (pst_bitTBFF(ctrlr) -> INVC0=(ParValue))
#define biGetTBFF_INVC1(ctrlr) (pst_bitTBFF(ctrlr) -> INVC1)
#define vSetTBFF_INVC1(ctrlr,ParValue)  (pst_bitTBFF(ctrlr) -> INVC1=(ParValue))
#define biGetTBFF_INVL0(ctrlr) (pst_bitTBFF(ctrlr) -> INVL0)
#define vSetTBFF_INVL0(ctrlr,ParValue)  (pst_bitTBFF(ctrlr) -> INVL0=(ParValue))
#define biGetTBFF_INVL1(ctrlr) (pst_bitTBFF(ctrlr) -> INVL1)
#define vSetTBFF_INVL1(ctrlr,ParValue)  (pst_bitTBFF(ctrlr) -> INVL1=(ParValue))
            
/* byte access */
#define vSetTBFF(ctrlr,ParValue) (*pu8TBFF(ctrlr) = (ParValue))
#define u8GetTBFF(ctrlr) (*pu8TBFF(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: TB0REG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC031C00C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TB0REG_REG__       0xC031C00CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CMP0	:16; 	 /* 0..15  bit(s) R/W */                    
} TB0REG_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} TB0REG_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16TB0REG_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTB0REG(ctrlr)     ((volatile TB0REG_bit_view_st *)\
(TB0REG_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TB0REG(ctrlr)     ((volatile TB0REG_byte_view_st *)\
(TB0REG_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16TB0REG(ctrlr)     ((volatile u16TB0REG_halfword_view *)\
(TB0REG_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetTB0REG_CMP0(ctrlr) (pst_bitTB0REG(ctrlr) -> CMP0)
#define vSetTB0REG_CMP0(ctrlr,ParValue)  (pst_bitTB0REG(ctrlr) -> CMP0=(ParValue))
            
/* L-struct byte access */
#define vSetTB0REGL(ctrlr,ParValue) (pst_u8TB0REG(ctrlr) -> u8L = (ParValue))
#define u8GetTB0REGL(ctrlr) (pst_u8TB0REG(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetTB0REGH(ctrlr,ParValue) (pst_u8TB0REG(ctrlr) -> u8H = (ParValue))
#define u8GetTB0REGH(ctrlr) (pst_u8TB0REG(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetTB0REG(ctrlr,ParValue) (*pu16TB0REG(ctrlr)  = (ParValue))
#define u16GetTB0REG(ctrlr) (*pu16TB0REG(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: TB1REG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC031C010                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TB1REG_REG__       0xC031C010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CMP1	:16; 	 /* 0..15  bit(s) R/W */                    
} TB1REG_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} TB1REG_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16TB1REG_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTB1REG(ctrlr)     ((volatile TB1REG_bit_view_st *)\
(TB1REG_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TB1REG(ctrlr)     ((volatile TB1REG_byte_view_st *)\
(TB1REG_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16TB1REG(ctrlr)     ((volatile u16TB1REG_halfword_view *)\
(TB1REG_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetTB1REG_CMP1(ctrlr) (pst_bitTB1REG(ctrlr) -> CMP1)
#define vSetTB1REG_CMP1(ctrlr,ParValue)  (pst_bitTB1REG(ctrlr) -> CMP1=(ParValue))
            
/* L-struct byte access */
#define vSetTB1REGL(ctrlr,ParValue) (pst_u8TB1REG(ctrlr) -> u8L = (ParValue))
#define u8GetTB1REGL(ctrlr) (pst_u8TB1REG(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetTB1REGH(ctrlr,ParValue) (pst_u8TB1REG(ctrlr) -> u8H = (ParValue))
#define u8GetTB1REGH(ctrlr) (pst_u8TB1REG(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetTB1REG(ctrlr,ParValue) (*pu16TB1REG(ctrlr)  = (ParValue))
#define u16GetTB1REG(ctrlr) (*pu16TB1REG(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: TB0CP0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC031C014                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TB0CP0_REG__       0xC031C014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CP0	:16; 	 /* 0..15  bit(s) R */                    
} TB0CP0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} TB0CP0_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16TB0CP0_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTB0CP0(ctrlr)     ((volatile TB0CP0_bit_view_st *)\
(TB0CP0_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TB0CP0(ctrlr)     ((volatile TB0CP0_byte_view_st *)\
(TB0CP0_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16TB0CP0(ctrlr)     ((volatile u16TB0CP0_halfword_view *)\
(TB0CP0_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetTB0CP0_CP0(ctrlr) (pst_bitTB0CP0(ctrlr) -> CP0)
            
/* L-struct byte access */

#define u8GetTB0CP0L(ctrlr) (pst_u8TB0CP0(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetTB0CP0H(ctrlr) (pst_u8TB0CP0(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetTB0CP0(ctrlr) (*pu16TB0CP0(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: TB0CP1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC031C018                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TB0CP1_REG__       0xC031C018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CP1	:16; 	 /* 0..15  bit(s) R */                    
} TB0CP1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} TB0CP1_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16TB0CP1_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTB0CP1(ctrlr)     ((volatile TB0CP1_bit_view_st *)\
(TB0CP1_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TB0CP1(ctrlr)     ((volatile TB0CP1_byte_view_st *)\
(TB0CP1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16TB0CP1(ctrlr)     ((volatile u16TB0CP1_halfword_view *)\
(TB0CP1_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetTB0CP1_CP1(ctrlr) (pst_bitTB0CP1(ctrlr) -> CP1)
            
/* L-struct byte access */

#define u8GetTB0CP1L(ctrlr) (pst_u8TB0CP1(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetTB0CP1H(ctrlr) (pst_u8TB0CP1(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetTB0CP1(ctrlr) (*pu16TB0CP1(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: TB0CNT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC031C01C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TB0CNT_REG__       0xC031C01CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CNT	:16; 	 /* 0..15  bit(s) R */                    
} TB0CNT_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} TB0CNT_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16TB0CNT_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTB0CNT(ctrlr)     ((volatile TB0CNT_bit_view_st *)\
(TB0CNT_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TB0CNT(ctrlr)     ((volatile TB0CNT_byte_view_st *)\
(TB0CNT_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16TB0CNT(ctrlr)     ((volatile u16TB0CNT_halfword_view *)\
(TB0CNT_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetTB0CNT_CNT(ctrlr) (pst_bitTB0CNT(ctrlr) -> CNT)
            
/* L-struct byte access */

#define u8GetTB0CNTL(ctrlr) (pst_u8TB0CNT(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetTB0CNTH(ctrlr) (pst_u8TB0CNT(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetTB0CNT(ctrlr) (*pu16TB0CNT(ctrlr) )



/****************************************************************************/
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

    

#endif /* TIMERS_CMPLX_PMIO_H */ 
    
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

