
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : SMC 
/  Date of creation (y-m-d:time): 2015-02-17+01:00  :  15:15:33.694+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision_: 1.14 $ 
/  Excel Sheet ver.             : vv2.1
/  Excel Sheet date             : 2014-Sep-17
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : SMC low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : SMC
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.10 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef SMCIO_H
#define SMCIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */ 

/* disable following Misra errors for io files */
#if defined(__GHS__) || defined(__ghs__)  
  #pragma ghs nowarning 230   /* Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types */
#endif

     
/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_SMC_IO_H_REVISION     "$Revision: 1.10 $"
#define LLDD_SMC_IO_H_TAG          "$Name: LLDD_1_6 $"
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCCLK_CTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300000                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCCLK_CTRL_REG__       0xC0300000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   PRE_SCALE	:4; 	 /* 0..3  bit(s) R/W */ 
  uint8_t   	:4; 	 /* 4..31  bit(s) R */                    
} SMCCLK_CTRL_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SMCCLK_CTRL_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCCLK_CTRL()     ((volatile SMCCLK_CTRL_bit_view_st *)\
(SMCCLK_CTRL_REG__ ))
        
/* Pointer to BYTE  */
#define pu8SMCCLK_CTRL()     ((volatile u8SMCCLK_CTRL_byte_view *)\
(SMCCLK_CTRL_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCCLK_CTRL_PRE_SCALE() (pst_bitSMCCLK_CTRL() -> PRE_SCALE)
#define vSetSMCCLK_CTRL_PRE_SCALE(ParValue)  (pst_bitSMCCLK_CTRL() -> PRE_SCALE=(ParValue))
            
/* byte access */
#define vSetSMCCLK_CTRL(ParValue) (*pu8SMCCLK_CTRL() = (ParValue))
#define u8GetSMCCLK_CTRL() (*pu8SMCCLK_CTRL() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCINT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCINT_REG__       0xC0300004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PPE	:5; 	 /* 0..4  bit(s) R/W1C */
  uint32_t   	:3; 	 /* 5..7  bit(s) R */
  uint32_t   MOV_END	:5; 	 /* 8..12  bit(s) R/W1C */
  uint32_t   	:3; 	 /* 13..15  bit(s) R */
  uint32_t   ZPDD	:5; 	 /* 16..20  bit(s) R/W1C */
  uint32_t   	:3; 	 /* 21..23  bit(s) R */
  uint32_t   CRAUM	:1; 	 /* 24..24  bit(s) R/W1C */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCINT_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCINT_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCINT_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCINT_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCINT()     ((volatile SMCINT_bit_view_st *)\
(SMCINT_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCINT()     ((volatile SMCINT_byte_view_st *)\
(SMCINT_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCINT()     ((volatile SMCINT_halfword_view_st *)\
(SMCINT_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SMCINT()     ((volatile u32SMCINT_word_view *)\
(SMCINT_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCINT_PPE() (pst_bitSMCINT() -> PPE)
/*---------------------------------------------------------------------------*/
/* SRA: Clr funnction can be applied for bit 0..4 for STM 0 to 4: */
#define vClrSMCINT_PPE(BitNo) (pst_bitSMCINT() -> PPE = ( (0x01U << (BitNo)) & 0x1FU) )
/* SRA: Clr funnction for multiple bits can be applied for multiple bits 0..4 for STM 0 to 4: */
#define vClrMultiSMCINT_PPE(Mask) (pst_bitSMCINT() -> PPE = ((Mask) & 0x1FU))
/*---------------------------------------------------------------------------*/

#define biGetSMCINT_MOV_END() (pst_bitSMCINT() -> MOV_END)
/*---------------------------------------------------------------------------*/
/* SRA: Clr funnction can be applied for bit 0..4 for STM 0 to 4: */
#define vClrSMCINT_MOV_END(BitNo) (pst_bitSMCINT() -> MOV_END = ( (0x01U << (BitNo)) & 0x1FU) )
/* SRA: Clr funnction for multiple bits can be applied for multiple bits 0..4 for STM 0 to 4: */
#define vClrMultiSMCINT_MOV_END(BitNo) (pst_bitSMCINT() -> MOV_END = ((Mask) & 0x1FU))
/*---------------------------------------------------------------------------*/

#define biGetSMCINT_ZPDD() (pst_bitSMCINT() -> ZPDD)
/*---------------------------------------------------------------------------*/
/* SRA: Clr funnction can be applied for bit 0..4 for STM 0 to 4: */
#define vClrSMCINT_ZPDD(BitNo) (pst_bitSMCINT() -> ZPDD =( (0x01U << (BitNo)) & 0x1FU) )
/* SRA: Clr funnction for multiple bits can be applied for multiple bits 0..4 for STM 0 to 4: */
#define vClrMultiSMCINT_ZPDD(BitNo) (pst_bitSMCINT() -> ZPDD = ((Mask) & 0x1FU))
/*---------------------------------------------------------------------------*/

#define biGetSMCINT_CRAUM() (pst_bitSMCINT() -> CRAUM)
#define vClrSMCINT_CRAUM() (pst_bitSMCINT() -> CRAUM = (0x1U))
            
/* LL-struct byte access */
#define vSetSMCINTLL(ParValue) (pst_u8SMCINT() -> u8LL = (ParValue))
#define u8GetSMCINTLL() (pst_u8SMCINT() -> u8LL)
/* LH-struct byte access */
#define vSetSMCINTLH(ParValue) (pst_u8SMCINT() -> u8LH = (ParValue))
#define u8GetSMCINTLH() (pst_u8SMCINT() -> u8LH)
/* HL-struct byte access */
#define vSetSMCINTHL(ParValue) (pst_u8SMCINT() -> u8HL = (ParValue))
#define u8GetSMCINTHL() (pst_u8SMCINT() -> u8HL)
/* HH-struct byte access */
#define vSetSMCINTHH(ParValue) (pst_u8SMCINT() -> u8HH = (ParValue))
#define u8GetSMCINTHH() (pst_u8SMCINT() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCINTL(ParValue) (pst_u16SMCINT() -> u16L = (ParValue))
#define u16GetSMCINTL() (pst_u16SMCINT() -> u16L)
#define vSetSMCINTH(ParValue) (pst_u16SMCINT() -> u16H = (ParValue))
#define u16GetSMCINTH() (pst_u16SMCINT() -> u16H)
            
/* Word access */
#define vSetSMCINT(ParValue)  (*pu32SMCINT() = (ParValue))
#define u32GetSMCINT()  (*pu32SMCINT() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCINT_MASK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCINT_MASK_REG__       0xC0300008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MASK_PPE	:5; 	 /* 0..4  bit(s) R/W */
  uint32_t   	:3; 	 /* 5..7  bit(s) R */
  uint32_t   MASK_MOV_END	:5; 	 /* 8..12  bit(s) R/W */
  uint32_t   	:3; 	 /* 13..15  bit(s) R */
  uint32_t   MASK_ZPDD	:5; 	 /* 16..20  bit(s) R/W */
  uint32_t   	:3; 	 /* 21..23  bit(s) R */
  uint32_t   MASK_CRAUM	:1; 	 /* 24..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCINT_MASK_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCINT_MASK_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCINT_MASK_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCINT_MASK_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCINT_MASK()     ((volatile SMCINT_MASK_bit_view_st *)\
(SMCINT_MASK_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCINT_MASK()     ((volatile SMCINT_MASK_byte_view_st *)\
(SMCINT_MASK_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCINT_MASK()     ((volatile SMCINT_MASK_halfword_view_st *)\
(SMCINT_MASK_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SMCINT_MASK()     ((volatile u32SMCINT_MASK_word_view *)\
(SMCINT_MASK_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCINT_MASK_MASK_PPE() (pst_bitSMCINT_MASK() -> MASK_PPE)
#define vSetSMCINT_MASK_MASK_PPE(ParValue)  (pst_bitSMCINT_MASK() -> MASK_PPE=(ParValue))
#define biGetSMCINT_MASK_MASK_MOV_END() (pst_bitSMCINT_MASK() -> MASK_MOV_END)
#define vSetSMCINT_MASK_MASK_MOV_END(ParValue)  (pst_bitSMCINT_MASK() -> MASK_MOV_END=(ParValue))
#define biGetSMCINT_MASK_MASK_ZPDD() (pst_bitSMCINT_MASK() -> MASK_ZPDD)
#define vSetSMCINT_MASK_MASK_ZPDD(ParValue)  (pst_bitSMCINT_MASK() -> MASK_ZPDD=(ParValue))
#define biGetSMCINT_MASK_MASK_CRAUM() (pst_bitSMCINT_MASK() -> MASK_CRAUM)
#define vSetSMCINT_MASK_MASK_CRAUM(ParValue)  (pst_bitSMCINT_MASK() -> MASK_CRAUM=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCINT_MASKLL(ParValue) (pst_u8SMCINT_MASK() -> u8LL = (ParValue))
#define u8GetSMCINT_MASKLL() (pst_u8SMCINT_MASK() -> u8LL)
/* LH-struct byte access */
#define vSetSMCINT_MASKLH(ParValue) (pst_u8SMCINT_MASK() -> u8LH = (ParValue))
#define u8GetSMCINT_MASKLH() (pst_u8SMCINT_MASK() -> u8LH)
/* HL-struct byte access */
#define vSetSMCINT_MASKHL(ParValue) (pst_u8SMCINT_MASK() -> u8HL = (ParValue))
#define u8GetSMCINT_MASKHL() (pst_u8SMCINT_MASK() -> u8HL)
/* HH-struct byte access */
#define vSetSMCINT_MASKHH(ParValue) (pst_u8SMCINT_MASK() -> u8HH = (ParValue))
#define u8GetSMCINT_MASKHH() (pst_u8SMCINT_MASK() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCINT_MASKL(ParValue) (pst_u16SMCINT_MASK() -> u16L = (ParValue))
#define u16GetSMCINT_MASKL() (pst_u16SMCINT_MASK() -> u16L)
#define vSetSMCINT_MASKH(ParValue) (pst_u16SMCINT_MASK() -> u16H = (ParValue))
#define u16GetSMCINT_MASKH() (pst_u16SMCINT_MASK() -> u16H)
            
/* Word access */
#define vSetSMCINT_MASK(ParValue)  (*pu32SMCINT_MASK() = (ParValue))
#define u32GetSMCINT_MASK()  (*pu32SMCINT_MASK() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCCTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030000C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCCTRL_REG__       0xC030000CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MSEL	:2; 	 /* 0..1  bit(s) R/W */
  uint32_t   OUTEN	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   DELAY_CYCLES	:5; 	 /* 3..7  bit(s) R/W */
  uint32_t   PERIOD_EXT	:7; 	 /* 8..14  bit(s) R/W */
  uint32_t   	:1; 	 /* 15..15  bit(s) R */
  uint32_t   SLEW_RATE	:3; 	 /* 16..18  bit(s) R/W */ 
  uint32_t   	:13; 	 /* 19..31  bit(s) R */                    
} SMCCTRL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCCTRL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCCTRL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCCTRL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCCTRL(ch)     ((volatile SMCCTRL_bit_view_st *)\
(SMCCTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCCTRL(ch)     ((volatile SMCCTRL_byte_view_st *)\
(SMCCTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCCTRL(ch)     ((volatile SMCCTRL_halfword_view_st *)\
(SMCCTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCCTRL(ch)     ((volatile u32SMCCTRL_word_view *)\
(SMCCTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCCTRL_MSEL(ch) (pst_bitSMCCTRL(ch) -> MSEL)
#define vSetSMCCTRL_MSEL(ch,ParValue)  (pst_bitSMCCTRL(ch) -> MSEL=(ParValue))
#define biGetSMCCTRL_OUTEN(ch) (pst_bitSMCCTRL(ch) -> OUTEN)
#define vSetSMCCTRL_OUTEN(ch,ParValue)  (pst_bitSMCCTRL(ch) -> OUTEN=(ParValue))
#define biGetSMCCTRL_DELAY_CYCLES(ch) (pst_bitSMCCTRL(ch) -> DELAY_CYCLES)
#define vSetSMCCTRL_DELAY_CYCLES(ch,ParValue)  (pst_bitSMCCTRL(ch) -> DELAY_CYCLES=(ParValue))
#define biGetSMCCTRL_PERIOD_EXT(ch) (pst_bitSMCCTRL(ch) -> PERIOD_EXT)
#define vSetSMCCTRL_PERIOD_EXT(ch,ParValue)  (pst_bitSMCCTRL(ch) -> PERIOD_EXT=(ParValue))
#define biGetSMCCTRL_SLEW_RATE(ch) (pst_bitSMCCTRL(ch) -> SLEW_RATE)
#define vSetSMCCTRL_SLEW_RATE(ch,ParValue)  (pst_bitSMCCTRL(ch) -> SLEW_RATE=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCCTRLLL(ch,ParValue) (pst_u8SMCCTRL(ch) -> u8LL = (ParValue))
#define u8GetSMCCTRLLL(ch) (pst_u8SMCCTRL(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCCTRLLH(ch,ParValue) (pst_u8SMCCTRL(ch) -> u8LH = (ParValue))
#define u8GetSMCCTRLLH(ch) (pst_u8SMCCTRL(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCCTRLHL(ch,ParValue) (pst_u8SMCCTRL(ch) -> u8HL = (ParValue))
#define u8GetSMCCTRLHL(ch) (pst_u8SMCCTRL(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCCTRLHH(ch,ParValue) (pst_u8SMCCTRL(ch) -> u8HH = (ParValue))
#define u8GetSMCCTRLHH(ch) (pst_u8SMCCTRL(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCCTRLL(ch,ParValue) (pst_u16SMCCTRL(ch) -> u16L = (ParValue))
#define u16GetSMCCTRLL(ch) (pst_u16SMCCTRL(ch) -> u16L)
#define vSetSMCCTRLH(ch,ParValue) (pst_u16SMCCTRL(ch) -> u16H = (ParValue))
#define u16GetSMCCTRLH(ch) (pst_u16SMCCTRL(ch) -> u16H)
            
/* Word access */
#define vSetSMCCTRL(ch,ParValue)  (*pu32SMCCTRL(ch) = (ParValue))
#define u32GetSMCCTRL(ch)  (*pu32SMCCTRL(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCISM_CTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCISM_CTRL_REG__       0xC0300020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DAMP_K	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   DAMP_L	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   ISM_TABLE_MODE	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   TABLE_IDX	:1; 	 /* 17..17  bit(s) R/W */
  uint32_t   DIS_DAMP	:1; 	 /* 18..18  bit(s) R/W */
  uint32_t   	:1; 	 /* 19..19  bit(s) R */
  uint32_t   RD_REQ	:1; 	 /* 20..20  bit(s) R/W */
  uint32_t   RD_FLAG	:1; 	 /* 21..21  bit(s) R */
  uint32_t   	:2; 	 /* 22..23  bit(s) R */
  uint32_t   FREEZE_REQ	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   FREEZE_FLAG	:1; 	 /* 25..25  bit(s) R */ 
  uint32_t   	:6; 	 /* 26..31  bit(s) R */                    
} SMCISM_CTRL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCISM_CTRL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCISM_CTRL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCISM_CTRL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCISM_CTRL(ch)     ((volatile SMCISM_CTRL_bit_view_st *)\
(SMCISM_CTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCISM_CTRL(ch)     ((volatile SMCISM_CTRL_byte_view_st *)\
(SMCISM_CTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCISM_CTRL(ch)     ((volatile SMCISM_CTRL_halfword_view_st *)\
(SMCISM_CTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCISM_CTRL(ch)     ((volatile u32SMCISM_CTRL_word_view *)\
(SMCISM_CTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCISM_CTRL_DAMP_K(ch) (pst_bitSMCISM_CTRL(ch) -> DAMP_K)
#define vSetSMCISM_CTRL_DAMP_K(ch,ParValue)  (pst_bitSMCISM_CTRL(ch) -> DAMP_K=(ParValue))
#define biGetSMCISM_CTRL_DAMP_L(ch) (pst_bitSMCISM_CTRL(ch) -> DAMP_L)
#define vSetSMCISM_CTRL_DAMP_L(ch,ParValue)  (pst_bitSMCISM_CTRL(ch) -> DAMP_L=(ParValue))
#define biGetSMCISM_CTRL_ISM_TABLE_MODE(ch) (pst_bitSMCISM_CTRL(ch) -> ISM_TABLE_MODE)
#define vSetSMCISM_CTRL_ISM_TABLE_MODE(ch,ParValue)  (pst_bitSMCISM_CTRL(ch) -> ISM_TABLE_MODE=(ParValue))
#define biGetSMCISM_CTRL_TABLE_IDX(ch) (pst_bitSMCISM_CTRL(ch) -> TABLE_IDX)
#define vSetSMCISM_CTRL_TABLE_IDX(ch,ParValue)  (pst_bitSMCISM_CTRL(ch) -> TABLE_IDX=(ParValue))
#define biGetSMCISM_CTRL_DIS_DAMP(ch) (pst_bitSMCISM_CTRL(ch) -> DIS_DAMP)
#define vSetSMCISM_CTRL_DIS_DAMP(ch,ParValue)  (pst_bitSMCISM_CTRL(ch) -> DIS_DAMP=(ParValue))
#define biGetSMCISM_CTRL_RD_REQ(ch) (pst_bitSMCISM_CTRL(ch) -> RD_REQ)
#define vSetSMCISM_CTRL_RD_REQ(ch,ParValue)  (pst_bitSMCISM_CTRL(ch) -> RD_REQ=(ParValue))            
#define biGetSMCISM_CTRL_RD_FLAG(ch) (pst_bitSMCISM_CTRL(ch) -> RD_FLAG)
#define biGetSMCISM_CTRL_FREEZE_REQ(ch) (pst_bitSMCISM_CTRL(ch) -> FREEZE_REQ)
#define vSetSMCISM_CTRL_FREEZE_REQ(ch,ParValue)  (pst_bitSMCISM_CTRL(ch) -> FREEZE_REQ=(ParValue))            
#define biGetSMCISM_CTRL_FREEZE_FLAG(ch) (pst_bitSMCISM_CTRL(ch) -> FREEZE_FLAG)
            
/* LL-struct byte access */
#define vSetSMCISM_CTRLLL(ch,ParValue) (pst_u8SMCISM_CTRL(ch) -> u8LL = (ParValue))
#define u8GetSMCISM_CTRLLL(ch) (pst_u8SMCISM_CTRL(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCISM_CTRLLH(ch,ParValue) (pst_u8SMCISM_CTRL(ch) -> u8LH = (ParValue))
#define u8GetSMCISM_CTRLLH(ch) (pst_u8SMCISM_CTRL(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCISM_CTRLHL(ch,ParValue) (pst_u8SMCISM_CTRL(ch) -> u8HL = (ParValue))
#define u8GetSMCISM_CTRLHL(ch) (pst_u8SMCISM_CTRL(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCISM_CTRLHH(ch,ParValue) (pst_u8SMCISM_CTRL(ch) -> u8HH = (ParValue))
#define u8GetSMCISM_CTRLHH(ch) (pst_u8SMCISM_CTRL(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCISM_CTRLL(ch,ParValue) (pst_u16SMCISM_CTRL(ch) -> u16L = (ParValue))
#define u16GetSMCISM_CTRLL(ch) (pst_u16SMCISM_CTRL(ch) -> u16L)
#define vSetSMCISM_CTRLH(ch,ParValue) (pst_u16SMCISM_CTRL(ch) -> u16H = (ParValue))
#define u16GetSMCISM_CTRLH(ch) (pst_u16SMCISM_CTRL(ch) -> u16H)
            
/* Word access */
#define vSetSMCISM_CTRL(ch,ParValue)  (*pu32SMCISM_CTRL(ch) = (ParValue))
#define u32GetSMCISM_CTRL(ch)  (*pu32SMCISM_CTRL(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCPOS_Dest                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300034                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCPOS_Dest_REG__       0xC0300034U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   FRACP	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   INTP	:17; 	 /* 8..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCPOS_Dest_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCPOS_Dest_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCPOS_Dest_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCPOS_Dest_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCPOS_Dest(ch)     ((volatile SMCPOS_Dest_bit_view_st *)\
(SMCPOS_Dest_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCPOS_Dest(ch)     ((volatile SMCPOS_Dest_byte_view_st *)\
(SMCPOS_Dest_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCPOS_Dest(ch)     ((volatile SMCPOS_Dest_halfword_view_st *)\
(SMCPOS_Dest_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCPOS_Dest(ch)     ((volatile u32SMCPOS_Dest_word_view *)\
(SMCPOS_Dest_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCPOS_Dest_FRACP(ch) (pst_bitSMCPOS_Dest(ch) -> FRACP)
#define vSetSMCPOS_Dest_FRACP(ch,ParValue)  (pst_bitSMCPOS_Dest(ch) -> FRACP=(ParValue))
#define biGetSMCPOS_Dest_INTP(ch) (pst_bitSMCPOS_Dest(ch) -> INTP)
#define vSetSMCPOS_Dest_INTP(ch,ParValue)  (pst_bitSMCPOS_Dest(ch) -> INTP=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCPOS_DestLL(ch,ParValue) (pst_u8SMCPOS_Dest(ch) -> u8LL = (ParValue))
#define u8GetSMCPOS_DestLL(ch) (pst_u8SMCPOS_Dest(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCPOS_DestLH(ch,ParValue) (pst_u8SMCPOS_Dest(ch) -> u8LH = (ParValue))
#define u8GetSMCPOS_DestLH(ch) (pst_u8SMCPOS_Dest(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCPOS_DestHL(ch,ParValue) (pst_u8SMCPOS_Dest(ch) -> u8HL = (ParValue))
#define u8GetSMCPOS_DestHL(ch) (pst_u8SMCPOS_Dest(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCPOS_DestHH(ch,ParValue) (pst_u8SMCPOS_Dest(ch) -> u8HH = (ParValue))
#define u8GetSMCPOS_DestHH(ch) (pst_u8SMCPOS_Dest(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCPOS_DestL(ch,ParValue) (pst_u16SMCPOS_Dest(ch) -> u16L = (ParValue))
#define u16GetSMCPOS_DestL(ch) (pst_u16SMCPOS_Dest(ch) -> u16L)
#define vSetSMCPOS_DestH(ch,ParValue) (pst_u16SMCPOS_Dest(ch) -> u16H = (ParValue))
#define u16GetSMCPOS_DestH(ch) (pst_u16SMCPOS_Dest(ch) -> u16H)
            
/* Word access */
#define vSetSMCPOS_Dest(ch,ParValue)  (*pu32SMCPOS_Dest(ch) = (ParValue))
#define u32GetSMCPOS_Dest(ch)  (*pu32SMCPOS_Dest(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCPWM                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300048                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCPWM_REG__       0xC0300048U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   COSDUTY	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   SINDUTY	:10; 	 /* 10..19  bit(s) R/W */
  uint32_t   QUADR	:2; 	 /* 20..21  bit(s) R/W */ 
  uint32_t   	:10; 	 /* 22..31  bit(s) R */                    
} SMCPWM_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCPWM_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCPWM_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCPWM_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCPWM(ch)     ((volatile SMCPWM_bit_view_st *)\
(SMCPWM_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCPWM(ch)     ((volatile SMCPWM_byte_view_st *)\
(SMCPWM_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCPWM(ch)     ((volatile SMCPWM_halfword_view_st *)\
(SMCPWM_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCPWM(ch)     ((volatile u32SMCPWM_word_view *)\
(SMCPWM_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCPWM_COSDUTY(ch) (pst_bitSMCPWM(ch) -> COSDUTY)
#define vSetSMCPWM_COSDUTY(ch,ParValue)  (pst_bitSMCPWM(ch) -> COSDUTY=(ParValue))
#define biGetSMCPWM_SINDUTY(ch) (pst_bitSMCPWM(ch) -> SINDUTY)
#define vSetSMCPWM_SINDUTY(ch,ParValue)  (pst_bitSMCPWM(ch) -> SINDUTY=(ParValue))
#define biGetSMCPWM_QUADR(ch) (pst_bitSMCPWM(ch) -> QUADR)
#define vSetSMCPWM_QUADR(ch,ParValue)  (pst_bitSMCPWM(ch) -> QUADR=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCPWMLL(ch,ParValue) (pst_u8SMCPWM(ch) -> u8LL = (ParValue))
#define u8GetSMCPWMLL(ch) (pst_u8SMCPWM(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCPWMLH(ch,ParValue) (pst_u8SMCPWM(ch) -> u8LH = (ParValue))
#define u8GetSMCPWMLH(ch) (pst_u8SMCPWM(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCPWMHL(ch,ParValue) (pst_u8SMCPWM(ch) -> u8HL = (ParValue))
#define u8GetSMCPWMHL(ch) (pst_u8SMCPWM(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCPWMHH(ch,ParValue) (pst_u8SMCPWM(ch) -> u8HH = (ParValue))
#define u8GetSMCPWMHH(ch) (pst_u8SMCPWM(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCPWML(ch,ParValue) (pst_u16SMCPWM(ch) -> u16L = (ParValue))
#define u16GetSMCPWML(ch) (pst_u16SMCPWM(ch) -> u16L)
#define vSetSMCPWMH(ch,ParValue) (pst_u16SMCPWM(ch) -> u16H = (ParValue))
#define u16GetSMCPWMH(ch) (pst_u16SMCPWM(ch) -> u16H)
            
/* Word access */
#define vSetSMCPWM(ch,ParValue)  (*pu32SMCPWM(ch) = (ParValue))
#define u32GetSMCPWM(ch)  (*pu32SMCPWM(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_PT1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030005C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_PT1_REG__       0xC030005CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PT1	:25; 	 /* 0..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_PT1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_PT1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_PT1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_PT1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_PT1(ch)     ((volatile SMCDCA_PT1_bit_view_st *)\
(SMCDCA_PT1_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_PT1(ch)     ((volatile SMCDCA_PT1_byte_view_st *)\
(SMCDCA_PT1_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_PT1(ch)     ((volatile SMCDCA_PT1_halfword_view_st *)\
(SMCDCA_PT1_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_PT1(ch)     ((volatile u32SMCDCA_PT1_word_view *)\
(SMCDCA_PT1_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_PT1_PT1(ch) (pst_bitSMCDCA_PT1(ch) -> PT1)
#define vSetSMCDCA_PT1_PT1(ch,ParValue)  (pst_bitSMCDCA_PT1(ch) -> PT1=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCDCA_PT1LL(ch,ParValue) (pst_u8SMCDCA_PT1(ch) -> u8LL = (ParValue))
#define u8GetSMCDCA_PT1LL(ch) (pst_u8SMCDCA_PT1(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCDCA_PT1LH(ch,ParValue) (pst_u8SMCDCA_PT1(ch) -> u8LH = (ParValue))
#define u8GetSMCDCA_PT1LH(ch) (pst_u8SMCDCA_PT1(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCDCA_PT1HL(ch,ParValue) (pst_u8SMCDCA_PT1(ch) -> u8HL = (ParValue))
#define u8GetSMCDCA_PT1HL(ch) (pst_u8SMCDCA_PT1(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCDCA_PT1HH(ch,ParValue) (pst_u8SMCDCA_PT1(ch) -> u8HH = (ParValue))
#define u8GetSMCDCA_PT1HH(ch) (pst_u8SMCDCA_PT1(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCDCA_PT1L(ch,ParValue) (pst_u16SMCDCA_PT1(ch) -> u16L = (ParValue))
#define u16GetSMCDCA_PT1L(ch) (pst_u16SMCDCA_PT1(ch) -> u16L)
#define vSetSMCDCA_PT1H(ch,ParValue) (pst_u16SMCDCA_PT1(ch) -> u16H = (ParValue))
#define u16GetSMCDCA_PT1H(ch) (pst_u16SMCDCA_PT1(ch) -> u16H)
            
/* Word access */
#define vSetSMCDCA_PT1(ch,ParValue)  (*pu32SMCDCA_PT1(ch) = (ParValue))
#define u32GetSMCDCA_PT1(ch)  (*pu32SMCDCA_PT1(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_PT2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300070                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_PT2_REG__       0xC0300070U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PT2	:25; 	 /* 0..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_PT2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_PT2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_PT2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_PT2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_PT2(ch)     ((volatile SMCDCA_PT2_bit_view_st *)\
(SMCDCA_PT2_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_PT2(ch)     ((volatile SMCDCA_PT2_byte_view_st *)\
(SMCDCA_PT2_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_PT2(ch)     ((volatile SMCDCA_PT2_halfword_view_st *)\
(SMCDCA_PT2_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_PT2(ch)     ((volatile u32SMCDCA_PT2_word_view *)\
(SMCDCA_PT2_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_PT2_PT2(ch) (pst_bitSMCDCA_PT2(ch) -> PT2)
#define vSetSMCDCA_PT2_PT2(ch,ParValue)  (pst_bitSMCDCA_PT2(ch) -> PT2=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCDCA_PT2LL(ch,ParValue) (pst_u8SMCDCA_PT2(ch) -> u8LL = (ParValue))
#define u8GetSMCDCA_PT2LL(ch) (pst_u8SMCDCA_PT2(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCDCA_PT2LH(ch,ParValue) (pst_u8SMCDCA_PT2(ch) -> u8LH = (ParValue))
#define u8GetSMCDCA_PT2LH(ch) (pst_u8SMCDCA_PT2(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCDCA_PT2HL(ch,ParValue) (pst_u8SMCDCA_PT2(ch) -> u8HL = (ParValue))
#define u8GetSMCDCA_PT2HL(ch) (pst_u8SMCDCA_PT2(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCDCA_PT2HH(ch,ParValue) (pst_u8SMCDCA_PT2(ch) -> u8HH = (ParValue))
#define u8GetSMCDCA_PT2HH(ch) (pst_u8SMCDCA_PT2(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCDCA_PT2L(ch,ParValue) (pst_u16SMCDCA_PT2(ch) -> u16L = (ParValue))
#define u16GetSMCDCA_PT2L(ch) (pst_u16SMCDCA_PT2(ch) -> u16L)
#define vSetSMCDCA_PT2H(ch,ParValue) (pst_u16SMCDCA_PT2(ch) -> u16H = (ParValue))
#define u16GetSMCDCA_PT2H(ch) (pst_u16SMCDCA_PT2(ch) -> u16H)
            
/* Word access */
#define vSetSMCDCA_PT2(ch,ParValue)  (*pu32SMCDCA_PT2(ch) = (ParValue))
#define u32GetSMCDCA_PT2(ch)  (*pu32SMCDCA_PT2(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_V_OLD                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300084                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_V_OLD_REG__       0xC0300084U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   V_OLD	:25; 	 /* 0..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_V_OLD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_V_OLD_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_V_OLD_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_V_OLD_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_V_OLD(ch)     ((volatile SMCDCA_V_OLD_bit_view_st *)\
(SMCDCA_V_OLD_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_V_OLD(ch)     ((volatile SMCDCA_V_OLD_byte_view_st *)\
(SMCDCA_V_OLD_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_V_OLD(ch)     ((volatile SMCDCA_V_OLD_halfword_view_st *)\
(SMCDCA_V_OLD_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_V_OLD(ch)     ((volatile u32SMCDCA_V_OLD_word_view *)\
(SMCDCA_V_OLD_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_V_OLD_V_OLD(ch) (pst_bitSMCDCA_V_OLD(ch) -> V_OLD)
#define vSetSMCDCA_V_OLD_V_OLD(ch,ParValue)  (pst_bitSMCDCA_V_OLD(ch) -> V_OLD=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCDCA_V_OLDLL(ch,ParValue) (pst_u8SMCDCA_V_OLD(ch) -> u8LL = (ParValue))
#define u8GetSMCDCA_V_OLDLL(ch) (pst_u8SMCDCA_V_OLD(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCDCA_V_OLDLH(ch,ParValue) (pst_u8SMCDCA_V_OLD(ch) -> u8LH = (ParValue))
#define u8GetSMCDCA_V_OLDLH(ch) (pst_u8SMCDCA_V_OLD(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCDCA_V_OLDHL(ch,ParValue) (pst_u8SMCDCA_V_OLD(ch) -> u8HL = (ParValue))
#define u8GetSMCDCA_V_OLDHL(ch) (pst_u8SMCDCA_V_OLD(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCDCA_V_OLDHH(ch,ParValue) (pst_u8SMCDCA_V_OLD(ch) -> u8HH = (ParValue))
#define u8GetSMCDCA_V_OLDHH(ch) (pst_u8SMCDCA_V_OLD(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCDCA_V_OLDL(ch,ParValue) (pst_u16SMCDCA_V_OLD(ch) -> u16L = (ParValue))
#define u16GetSMCDCA_V_OLDL(ch) (pst_u16SMCDCA_V_OLD(ch) -> u16L)
#define vSetSMCDCA_V_OLDH(ch,ParValue) (pst_u16SMCDCA_V_OLD(ch) -> u16H = (ParValue))
#define u16GetSMCDCA_V_OLDH(ch) (pst_u16SMCDCA_V_OLD(ch) -> u16H)
            
/* Word access */
#define vSetSMCDCA_V_OLD(ch,ParValue)  (*pu32SMCDCA_V_OLD(ch) = (ParValue))
#define u32GetSMCDCA_V_OLD(ch)  (*pu32SMCDCA_V_OLD(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_V_MAX                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300098                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_V_MAX_REG__       0xC0300098U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   V_MAX	:25; 	 /* 0..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_V_MAX_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_V_MAX_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_V_MAX_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_V_MAX_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_V_MAX(ch)     ((volatile SMCDCA_V_MAX_bit_view_st *)\
(SMCDCA_V_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_V_MAX(ch)     ((volatile SMCDCA_V_MAX_byte_view_st *)\
(SMCDCA_V_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_V_MAX(ch)     ((volatile SMCDCA_V_MAX_halfword_view_st *)\
(SMCDCA_V_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_V_MAX(ch)     ((volatile u32SMCDCA_V_MAX_word_view *)\
(SMCDCA_V_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_V_MAX_V_MAX(ch) (pst_bitSMCDCA_V_MAX(ch) -> V_MAX)
#define vSetSMCDCA_V_MAX_V_MAX(ch,ParValue)  (pst_bitSMCDCA_V_MAX(ch) -> V_MAX=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCDCA_V_MAXLL(ch,ParValue) (pst_u8SMCDCA_V_MAX(ch) -> u8LL = (ParValue))
#define u8GetSMCDCA_V_MAXLL(ch) (pst_u8SMCDCA_V_MAX(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCDCA_V_MAXLH(ch,ParValue) (pst_u8SMCDCA_V_MAX(ch) -> u8LH = (ParValue))
#define u8GetSMCDCA_V_MAXLH(ch) (pst_u8SMCDCA_V_MAX(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCDCA_V_MAXHL(ch,ParValue) (pst_u8SMCDCA_V_MAX(ch) -> u8HL = (ParValue))
#define u8GetSMCDCA_V_MAXHL(ch) (pst_u8SMCDCA_V_MAX(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCDCA_V_MAXHH(ch,ParValue) (pst_u8SMCDCA_V_MAX(ch) -> u8HH = (ParValue))
#define u8GetSMCDCA_V_MAXHH(ch) (pst_u8SMCDCA_V_MAX(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCDCA_V_MAXL(ch,ParValue) (pst_u16SMCDCA_V_MAX(ch) -> u16L = (ParValue))
#define u16GetSMCDCA_V_MAXL(ch) (pst_u16SMCDCA_V_MAX(ch) -> u16L)
#define vSetSMCDCA_V_MAXH(ch,ParValue) (pst_u16SMCDCA_V_MAX(ch) -> u16H = (ParValue))
#define u16GetSMCDCA_V_MAXH(ch) (pst_u16SMCDCA_V_MAX(ch) -> u16H)
            
/* Word access */
#define vSetSMCDCA_V_MAX(ch,ParValue)  (*pu32SMCDCA_V_MAX(ch) = (ParValue))
#define u32GetSMCDCA_V_MAX(ch)  (*pu32SMCDCA_V_MAX(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_ACC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03000AC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_ACC_REG__       0xC03000ACU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ACC	:25; 	 /* 0..24  bit(s) R */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_ACC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_ACC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_ACC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_ACC_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_ACC(ch)     ((volatile SMCDCA_ACC_bit_view_st *)\
(SMCDCA_ACC_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_ACC(ch)     ((volatile SMCDCA_ACC_byte_view_st *)\
(SMCDCA_ACC_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_ACC(ch)     ((volatile SMCDCA_ACC_halfword_view_st *)\
(SMCDCA_ACC_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_ACC(ch)     ((volatile u32SMCDCA_ACC_word_view *)\
(SMCDCA_ACC_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSMCDCA_ACC_ACC(ch) (pst_bitSMCDCA_ACC(ch) -> ACC)
            
/* LL-struct byte access */

#define u8GetSMCDCA_ACCLL(ch) (pst_u8SMCDCA_ACC(ch) -> u8LL)
/* LH-struct byte access */

#define u8GetSMCDCA_ACCLH(ch) (pst_u8SMCDCA_ACC(ch) -> u8LH)
/* HL-struct byte access */

#define u8GetSMCDCA_ACCHL(ch) (pst_u8SMCDCA_ACC(ch) -> u8HL)
/* HH-struct byte access */

#define u8GetSMCDCA_ACCHH(ch) (pst_u8SMCDCA_ACC(ch) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetSMCDCA_ACCL(ch) (pst_u16SMCDCA_ACC(ch) -> u16L)

#define u16GetSMCDCA_ACCH(ch) (pst_u16SMCDCA_ACC(ch) -> u16H)
            
/* Word access */

#define u32GetSMCDCA_ACC(ch)  (*pu32SMCDCA_ACC(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_A_MAX                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03000C0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_A_MAX_REG__       0xC03000C0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   A_MAX	:25; 	 /* 0..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_A_MAX_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_A_MAX_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_A_MAX_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_A_MAX_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_A_MAX(ch)     ((volatile SMCDCA_A_MAX_bit_view_st *)\
(SMCDCA_A_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_A_MAX(ch)     ((volatile SMCDCA_A_MAX_byte_view_st *)\
(SMCDCA_A_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_A_MAX(ch)     ((volatile SMCDCA_A_MAX_halfword_view_st *)\
(SMCDCA_A_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_A_MAX(ch)     ((volatile u32SMCDCA_A_MAX_word_view *)\
(SMCDCA_A_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_A_MAX_A_MAX(ch) (pst_bitSMCDCA_A_MAX(ch) -> A_MAX)
#define vSetSMCDCA_A_MAX_A_MAX(ch,ParValue)  (pst_bitSMCDCA_A_MAX(ch) -> A_MAX=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCDCA_A_MAXLL(ch,ParValue) (pst_u8SMCDCA_A_MAX(ch) -> u8LL = (ParValue))
#define u8GetSMCDCA_A_MAXLL(ch) (pst_u8SMCDCA_A_MAX(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCDCA_A_MAXLH(ch,ParValue) (pst_u8SMCDCA_A_MAX(ch) -> u8LH = (ParValue))
#define u8GetSMCDCA_A_MAXLH(ch) (pst_u8SMCDCA_A_MAX(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCDCA_A_MAXHL(ch,ParValue) (pst_u8SMCDCA_A_MAX(ch) -> u8HL = (ParValue))
#define u8GetSMCDCA_A_MAXHL(ch) (pst_u8SMCDCA_A_MAX(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCDCA_A_MAXHH(ch,ParValue) (pst_u8SMCDCA_A_MAX(ch) -> u8HH = (ParValue))
#define u8GetSMCDCA_A_MAXHH(ch) (pst_u8SMCDCA_A_MAX(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCDCA_A_MAXL(ch,ParValue) (pst_u16SMCDCA_A_MAX(ch) -> u16L = (ParValue))
#define u16GetSMCDCA_A_MAXL(ch) (pst_u16SMCDCA_A_MAX(ch) -> u16L)
#define vSetSMCDCA_A_MAXH(ch,ParValue) (pst_u16SMCDCA_A_MAX(ch) -> u16H = (ParValue))
#define u16GetSMCDCA_A_MAXH(ch) (pst_u16SMCDCA_A_MAX(ch) -> u16H)
            
/* Word access */
#define vSetSMCDCA_A_MAX(ch,ParValue)  (*pu32SMCDCA_A_MAX(ch) = (ParValue))
#define u32GetSMCDCA_A_MAX(ch)  (*pu32SMCDCA_A_MAX(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_D_MAX                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03000D4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_D_MAX_REG__       0xC03000D4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D_MAX	:25; 	 /* 0..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_D_MAX_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_D_MAX_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_D_MAX_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_D_MAX_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_D_MAX(ch)     ((volatile SMCDCA_D_MAX_bit_view_st *)\
(SMCDCA_D_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_D_MAX(ch)     ((volatile SMCDCA_D_MAX_byte_view_st *)\
(SMCDCA_D_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_D_MAX(ch)     ((volatile SMCDCA_D_MAX_halfword_view_st *)\
(SMCDCA_D_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_D_MAX(ch)     ((volatile u32SMCDCA_D_MAX_word_view *)\
(SMCDCA_D_MAX_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_D_MAX_D_MAX(ch) (pst_bitSMCDCA_D_MAX(ch) -> D_MAX)
#define vSetSMCDCA_D_MAX_D_MAX(ch,ParValue)  (pst_bitSMCDCA_D_MAX(ch) -> D_MAX=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCDCA_D_MAXLL(ch,ParValue) (pst_u8SMCDCA_D_MAX(ch) -> u8LL = (ParValue))
#define u8GetSMCDCA_D_MAXLL(ch) (pst_u8SMCDCA_D_MAX(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCDCA_D_MAXLH(ch,ParValue) (pst_u8SMCDCA_D_MAX(ch) -> u8LH = (ParValue))
#define u8GetSMCDCA_D_MAXLH(ch) (pst_u8SMCDCA_D_MAX(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCDCA_D_MAXHL(ch,ParValue) (pst_u8SMCDCA_D_MAX(ch) -> u8HL = (ParValue))
#define u8GetSMCDCA_D_MAXHL(ch) (pst_u8SMCDCA_D_MAX(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCDCA_D_MAXHH(ch,ParValue) (pst_u8SMCDCA_D_MAX(ch) -> u8HH = (ParValue))
#define u8GetSMCDCA_D_MAXHH(ch) (pst_u8SMCDCA_D_MAX(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCDCA_D_MAXL(ch,ParValue) (pst_u16SMCDCA_D_MAX(ch) -> u16L = (ParValue))
#define u16GetSMCDCA_D_MAXL(ch) (pst_u16SMCDCA_D_MAX(ch) -> u16L)
#define vSetSMCDCA_D_MAXH(ch,ParValue) (pst_u16SMCDCA_D_MAX(ch) -> u16H = (ParValue))
#define u16GetSMCDCA_D_MAXH(ch) (pst_u16SMCDCA_D_MAX(ch) -> u16H)
            
/* Word access */
#define vSetSMCDCA_D_MAX(ch,ParValue)  (*pu32SMCDCA_D_MAX(ch) = (ParValue))
#define u32GetSMCDCA_D_MAX(ch)  (*pu32SMCDCA_D_MAX(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_V1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03000E8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_V1_REG__       0xC03000E8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   V1TH	:25; 	 /* 0..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_V1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_V1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_V1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_V1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_V1(ch)     ((volatile SMCDCA_V1_bit_view_st *)\
(SMCDCA_V1_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_V1(ch)     ((volatile SMCDCA_V1_byte_view_st *)\
(SMCDCA_V1_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_V1(ch)     ((volatile SMCDCA_V1_halfword_view_st *)\
(SMCDCA_V1_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_V1(ch)     ((volatile u32SMCDCA_V1_word_view *)\
(SMCDCA_V1_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_V1_V1TH(ch) (pst_bitSMCDCA_V1(ch) -> V1TH)
#define vSetSMCDCA_V1_V1TH(ch,ParValue)  (pst_bitSMCDCA_V1(ch) -> V1TH=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCDCA_V1LL(ch,ParValue) (pst_u8SMCDCA_V1(ch) -> u8LL = (ParValue))
#define u8GetSMCDCA_V1LL(ch) (pst_u8SMCDCA_V1(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCDCA_V1LH(ch,ParValue) (pst_u8SMCDCA_V1(ch) -> u8LH = (ParValue))
#define u8GetSMCDCA_V1LH(ch) (pst_u8SMCDCA_V1(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCDCA_V1HL(ch,ParValue) (pst_u8SMCDCA_V1(ch) -> u8HL = (ParValue))
#define u8GetSMCDCA_V1HL(ch) (pst_u8SMCDCA_V1(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCDCA_V1HH(ch,ParValue) (pst_u8SMCDCA_V1(ch) -> u8HH = (ParValue))
#define u8GetSMCDCA_V1HH(ch) (pst_u8SMCDCA_V1(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCDCA_V1L(ch,ParValue) (pst_u16SMCDCA_V1(ch) -> u16L = (ParValue))
#define u16GetSMCDCA_V1L(ch) (pst_u16SMCDCA_V1(ch) -> u16L)
#define vSetSMCDCA_V1H(ch,ParValue) (pst_u16SMCDCA_V1(ch) -> u16H = (ParValue))
#define u16GetSMCDCA_V1H(ch) (pst_u16SMCDCA_V1(ch) -> u16H)
            
/* Word access */
#define vSetSMCDCA_V1(ch,ParValue)  (*pu32SMCDCA_V1(ch) = (ParValue))
#define u32GetSMCDCA_V1(ch)  (*pu32SMCDCA_V1(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_V2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC03000FC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_V2_REG__       0xC03000FCU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   V2TH	:25; 	 /* 0..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} SMCDCA_V2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCDCA_V2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCDCA_V2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCDCA_V2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_V2(ch)     ((volatile SMCDCA_V2_bit_view_st *)\
(SMCDCA_V2_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_V2(ch)     ((volatile SMCDCA_V2_byte_view_st *)\
(SMCDCA_V2_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCDCA_V2(ch)     ((volatile SMCDCA_V2_halfword_view_st *)\
(SMCDCA_V2_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCDCA_V2(ch)     ((volatile u32SMCDCA_V2_word_view *)\
(SMCDCA_V2_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_V2_V2TH(ch) (pst_bitSMCDCA_V2(ch) -> V2TH)
#define vSetSMCDCA_V2_V2TH(ch,ParValue)  (pst_bitSMCDCA_V2(ch) -> V2TH=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCDCA_V2LL(ch,ParValue) (pst_u8SMCDCA_V2(ch) -> u8LL = (ParValue))
#define u8GetSMCDCA_V2LL(ch) (pst_u8SMCDCA_V2(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCDCA_V2LH(ch,ParValue) (pst_u8SMCDCA_V2(ch) -> u8LH = (ParValue))
#define u8GetSMCDCA_V2LH(ch) (pst_u8SMCDCA_V2(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCDCA_V2HL(ch,ParValue) (pst_u8SMCDCA_V2(ch) -> u8HL = (ParValue))
#define u8GetSMCDCA_V2HL(ch) (pst_u8SMCDCA_V2(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCDCA_V2HH(ch,ParValue) (pst_u8SMCDCA_V2(ch) -> u8HH = (ParValue))
#define u8GetSMCDCA_V2HH(ch) (pst_u8SMCDCA_V2(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCDCA_V2L(ch,ParValue) (pst_u16SMCDCA_V2(ch) -> u16L = (ParValue))
#define u16GetSMCDCA_V2L(ch) (pst_u16SMCDCA_V2(ch) -> u16L)
#define vSetSMCDCA_V2H(ch,ParValue) (pst_u16SMCDCA_V2(ch) -> u16H = (ParValue))
#define u16GetSMCDCA_V2H(ch) (pst_u16SMCDCA_V2(ch) -> u16H)
            
/* Word access */
#define vSetSMCDCA_V2(ch,ParValue)  (*pu32SMCDCA_V2(ch) = (ParValue))
#define u32GetSMCDCA_V2(ch)  (*pu32SMCDCA_V2(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCDCA_TS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300110                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCDCA_TS_REG__       0xC0300110U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   TS_SEL	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   	:7; 	 /* 1..7  bit(s) R */
  uint16_t   TD_SEL	:1; 	 /* 8..8  bit(s) R/W */ 
  uint16_t   	:7; 	 /* 9..31  bit(s) R */                    
} SMCDCA_TS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} SMCDCA_TS_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16SMCDCA_TS_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCDCA_TS(ch)     ((volatile SMCDCA_TS_bit_view_st *)\
(SMCDCA_TS_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCDCA_TS(ch)     ((volatile SMCDCA_TS_byte_view_st *)\
(SMCDCA_TS_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD */
#define pu16SMCDCA_TS(ch)     ((volatile u16SMCDCA_TS_halfword_view *)\
(SMCDCA_TS_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCDCA_TS_TS_SEL(ch) (pst_bitSMCDCA_TS(ch) -> TS_SEL)
#define vSetSMCDCA_TS_TS_SEL(ch,ParValue)  (pst_bitSMCDCA_TS(ch) -> TS_SEL=(ParValue))            
#define biGetSMCDCA_TS_TD_SEL(ch) (pst_bitSMCDCA_TS(ch) -> TD_SEL)
#define vSetSMCDCA_TS_TD_SEL(ch,ParValue)  (pst_bitSMCDCA_TS(ch) -> TD_SEL=(ParValue))
            
/* L-struct byte access */
#define vSetSMCDCA_TSL(ch,ParValue) (pst_u8SMCDCA_TS(ch) -> u8L = (ParValue))
#define u8GetSMCDCA_TSL(ch) (pst_u8SMCDCA_TS(ch) -> u8L)
/* H-struct byte access */
#define vSetSMCDCA_TSH(ch,ParValue) (pst_u8SMCDCA_TS(ch) -> u8H = (ParValue))
#define u8GetSMCDCA_TSH(ch) (pst_u8SMCDCA_TS(ch) -> u8H)
            
/* Half-word access */ 
#define vSetSMCDCA_TS(ch,ParValue) (*pu16SMCDCA_TS(ch)  = (ParValue))
#define u16GetSMCDCA_TS(ch) (*pu16SMCDCA_TS(ch) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCZPD_CTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300124                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCZPD_CTRL_REG__       0xC0300124U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   IDX_INC_N	:7; 	 /* 0..6  bit(s) R/W */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   QUAD	:2; 	 /* 8..9  bit(s) R */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   FREQ_N	:4; 	 /* 16..19  bit(s) R/W */
  uint32_t   	:4; 	 /* 20..23  bit(s) R */
  uint32_t   VOLT_REF	:6; 	 /* 24..29  bit(s) R/W */ 
  uint32_t   	:2; 	 /* 30..31  bit(s) R */                    
} SMCZPD_CTRL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCZPD_CTRL_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCZPD_CTRL_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCZPD_CTRL_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCZPD_CTRL(ch)     ((volatile SMCZPD_CTRL_bit_view_st *)\
(SMCZPD_CTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCZPD_CTRL(ch)     ((volatile SMCZPD_CTRL_byte_view_st *)\
(SMCZPD_CTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCZPD_CTRL(ch)     ((volatile SMCZPD_CTRL_halfword_view_st *)\
(SMCZPD_CTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCZPD_CTRL(ch)     ((volatile u32SMCZPD_CTRL_word_view *)\
(SMCZPD_CTRL_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCZPD_CTRL_IDX_INC_N(ch) (pst_bitSMCZPD_CTRL(ch) -> IDX_INC_N)
#define vSetSMCZPD_CTRL_IDX_INC_N(ch,ParValue)  (pst_bitSMCZPD_CTRL(ch) -> IDX_INC_N=(ParValue))            
#define biGetSMCZPD_CTRL_QUAD(ch) (pst_bitSMCZPD_CTRL(ch) -> QUAD)
#define biGetSMCZPD_CTRL_FREQ_N(ch) (pst_bitSMCZPD_CTRL(ch) -> FREQ_N)
#define vSetSMCZPD_CTRL_FREQ_N(ch,ParValue)  (pst_bitSMCZPD_CTRL(ch) -> FREQ_N=(ParValue))
#define biGetSMCZPD_CTRL_VOLT_REF(ch) (pst_bitSMCZPD_CTRL(ch) -> VOLT_REF)
#define vSetSMCZPD_CTRL_VOLT_REF(ch,ParValue)  (pst_bitSMCZPD_CTRL(ch) -> VOLT_REF=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCZPD_CTRLLL(ch,ParValue) (pst_u8SMCZPD_CTRL(ch) -> u8LL = (ParValue))
#define u8GetSMCZPD_CTRLLL(ch) (pst_u8SMCZPD_CTRL(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCZPD_CTRLLH(ch,ParValue) (pst_u8SMCZPD_CTRL(ch) -> u8LH = (ParValue))
#define u8GetSMCZPD_CTRLLH(ch) (pst_u8SMCZPD_CTRL(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCZPD_CTRLHL(ch,ParValue) (pst_u8SMCZPD_CTRL(ch) -> u8HL = (ParValue))
#define u8GetSMCZPD_CTRLHL(ch) (pst_u8SMCZPD_CTRL(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCZPD_CTRLHH(ch,ParValue) (pst_u8SMCZPD_CTRL(ch) -> u8HH = (ParValue))
#define u8GetSMCZPD_CTRLHH(ch) (pst_u8SMCZPD_CTRL(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCZPD_CTRLL(ch,ParValue) (pst_u16SMCZPD_CTRL(ch) -> u16L = (ParValue))
#define u16GetSMCZPD_CTRLL(ch) (pst_u16SMCZPD_CTRL(ch) -> u16L)
#define vSetSMCZPD_CTRLH(ch,ParValue) (pst_u16SMCZPD_CTRL(ch) -> u16H = (ParValue))
#define u16GetSMCZPD_CTRLH(ch) (pst_u16SMCZPD_CTRL(ch) -> u16H)
            
/* Word access */
#define vSetSMCZPD_CTRL(ch,ParValue)  (*pu32SMCZPD_CTRL(ch) = (ParValue))
#define u32GetSMCZPD_CTRL(ch)  (*pu32SMCZPD_CTRL(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCZPD_TABLE                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0300C00                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCZPD_TABLE_REG__       0xC0300C00U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PORT_CTRL	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   INPUT_SEL	:2; 	 /* 8..9  bit(s) R/W */
  uint32_t   DLY_CNT	:10; 	 /* 10..19  bit(s) R/W */
  uint32_t   NOT_USED	:2; 	 /* 20..21  bit(s) R/W */
  uint32_t   LAST_ENTRY	:1; 	 /* 22..22  bit(s) R/W */
  uint32_t   MEASURE	:1; 	 /* 23..23  bit(s) R/W */ 
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} SMCZPD_TABLE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCZPD_TABLE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCZPD_TABLE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCZPD_TABLE_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCZPD_TABLE(ch)     ((volatile SMCZPD_TABLE_bit_view_st *)\
(SMCZPD_TABLE_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCZPD_TABLE(ch)     ((volatile SMCZPD_TABLE_byte_view_st *)\
(SMCZPD_TABLE_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCZPD_TABLE(ch)     ((volatile SMCZPD_TABLE_halfword_view_st *)\
(SMCZPD_TABLE_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCZPD_TABLE(ch)     ((volatile u32SMCZPD_TABLE_word_view *)\
(SMCZPD_TABLE_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCZPD_TABLE_PORT_CTRL(ch) (pst_bitSMCZPD_TABLE(ch) -> PORT_CTRL)
#define vSetSMCZPD_TABLE_PORT_CTRL(ch,ParValue)  (pst_bitSMCZPD_TABLE(ch) -> PORT_CTRL=(ParValue))
#define biGetSMCZPD_TABLE_INPUT_SEL(ch) (pst_bitSMCZPD_TABLE(ch) -> INPUT_SEL)
#define vSetSMCZPD_TABLE_INPUT_SEL(ch,ParValue)  (pst_bitSMCZPD_TABLE(ch) -> INPUT_SEL=(ParValue))
#define biGetSMCZPD_TABLE_DLY_CNT(ch) (pst_bitSMCZPD_TABLE(ch) -> DLY_CNT)
#define vSetSMCZPD_TABLE_DLY_CNT(ch,ParValue)  (pst_bitSMCZPD_TABLE(ch) -> DLY_CNT=(ParValue))
#define biGetSMCZPD_TABLE_NOT_USED(ch) (pst_bitSMCZPD_TABLE(ch) -> NOT_USED)
#define vSetSMCZPD_TABLE_NOT_USED(ch,ParValue)  (pst_bitSMCZPD_TABLE(ch) -> NOT_USED=(ParValue))
#define biGetSMCZPD_TABLE_LAST_ENTRY(ch) (pst_bitSMCZPD_TABLE(ch) -> LAST_ENTRY)
#define vSetSMCZPD_TABLE_LAST_ENTRY(ch,ParValue)  (pst_bitSMCZPD_TABLE(ch) -> LAST_ENTRY=(ParValue))
#define biGetSMCZPD_TABLE_MEASURE(ch) (pst_bitSMCZPD_TABLE(ch) -> MEASURE)
#define vSetSMCZPD_TABLE_MEASURE(ch,ParValue)  (pst_bitSMCZPD_TABLE(ch) -> MEASURE=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCZPD_TABLELL(ch,ParValue) (pst_u8SMCZPD_TABLE(ch) -> u8LL = (ParValue))
#define u8GetSMCZPD_TABLELL(ch) (pst_u8SMCZPD_TABLE(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCZPD_TABLELH(ch,ParValue) (pst_u8SMCZPD_TABLE(ch) -> u8LH = (ParValue))
#define u8GetSMCZPD_TABLELH(ch) (pst_u8SMCZPD_TABLE(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCZPD_TABLEHL(ch,ParValue) (pst_u8SMCZPD_TABLE(ch) -> u8HL = (ParValue))
#define u8GetSMCZPD_TABLEHL(ch) (pst_u8SMCZPD_TABLE(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCZPD_TABLEHH(ch,ParValue) (pst_u8SMCZPD_TABLE(ch) -> u8HH = (ParValue))
#define u8GetSMCZPD_TABLEHH(ch) (pst_u8SMCZPD_TABLE(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCZPD_TABLEL(ch,ParValue) (pst_u16SMCZPD_TABLE(ch) -> u16L = (ParValue))
#define u16GetSMCZPD_TABLEL(ch) (pst_u16SMCZPD_TABLE(ch) -> u16L)
#define vSetSMCZPD_TABLEH(ch,ParValue) (pst_u16SMCZPD_TABLE(ch) -> u16H = (ParValue))
#define u16GetSMCZPD_TABLEH(ch) (pst_u16SMCZPD_TABLE(ch) -> u16H)
            
/* Word access */
#define vSetSMCZPD_TABLE(ch,ParValue)  (*pu32SMCZPD_TABLE(ch) = (ParValue))
#define u32GetSMCZPD_TABLE(ch)  (*pu32SMCZPD_TABLE(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCISM_TABLE                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0301000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCISM_TABLE_REG__       0xC0301000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   COS_ISM	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   SIN_ISM	:10; 	 /* 10..19  bit(s) R/W */
  uint32_t   QUAD_ISM	:2; 	 /* 20..21  bit(s) R/W */ 
  uint32_t   	:10; 	 /* 22..31  bit(s) R */                    
} SMCISM_TABLE_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SMCISM_TABLE_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SMCISM_TABLE_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SMCISM_TABLE_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCISM_TABLE(ch)     ((volatile SMCISM_TABLE_bit_view_st *)\
(SMCISM_TABLE_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SMCISM_TABLE(ch)     ((volatile SMCISM_TABLE_byte_view_st *)\
(SMCISM_TABLE_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SMCISM_TABLE(ch)     ((volatile SMCISM_TABLE_halfword_view_st *)\
(SMCISM_TABLE_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SMCISM_TABLE(ch)     ((volatile u32SMCISM_TABLE_word_view *)\
(SMCISM_TABLE_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCISM_TABLE_COS_ISM(ch) (pst_bitSMCISM_TABLE(ch) -> COS_ISM)
#define vSetSMCISM_TABLE_COS_ISM(ch,ParValue)  (pst_bitSMCISM_TABLE(ch) -> COS_ISM=(ParValue))
#define biGetSMCISM_TABLE_SIN_ISM(ch) (pst_bitSMCISM_TABLE(ch) -> SIN_ISM)
#define vSetSMCISM_TABLE_SIN_ISM(ch,ParValue)  (pst_bitSMCISM_TABLE(ch) -> SIN_ISM=(ParValue))
#define biGetSMCISM_TABLE_QUAD_ISM(ch) (pst_bitSMCISM_TABLE(ch) -> QUAD_ISM)
#define vSetSMCISM_TABLE_QUAD_ISM(ch,ParValue)  (pst_bitSMCISM_TABLE(ch) -> QUAD_ISM=(ParValue))
            
/* LL-struct byte access */
#define vSetSMCISM_TABLELL(ch,ParValue) (pst_u8SMCISM_TABLE(ch) -> u8LL = (ParValue))
#define u8GetSMCISM_TABLELL(ch) (pst_u8SMCISM_TABLE(ch) -> u8LL)
/* LH-struct byte access */
#define vSetSMCISM_TABLELH(ch,ParValue) (pst_u8SMCISM_TABLE(ch) -> u8LH = (ParValue))
#define u8GetSMCISM_TABLELH(ch) (pst_u8SMCISM_TABLE(ch) -> u8LH)
/* HL-struct byte access */
#define vSetSMCISM_TABLEHL(ch,ParValue) (pst_u8SMCISM_TABLE(ch) -> u8HL = (ParValue))
#define u8GetSMCISM_TABLEHL(ch) (pst_u8SMCISM_TABLE(ch) -> u8HL)
/* HH-struct byte access */
#define vSetSMCISM_TABLEHH(ch,ParValue) (pst_u8SMCISM_TABLE(ch) -> u8HH = (ParValue))
#define u8GetSMCISM_TABLEHH(ch) (pst_u8SMCISM_TABLE(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSMCISM_TABLEL(ch,ParValue) (pst_u16SMCISM_TABLE(ch) -> u16L = (ParValue))
#define u16GetSMCISM_TABLEL(ch) (pst_u16SMCISM_TABLE(ch) -> u16L)
#define vSetSMCISM_TABLEH(ch,ParValue) (pst_u16SMCISM_TABLE(ch) -> u16H = (ParValue))
#define u16GetSMCISM_TABLEH(ch) (pst_u16SMCISM_TABLE(ch) -> u16H)
            
/* Word access */
#define vSetSMCISM_TABLE(ch,ParValue)  (*pu32SMCISM_TABLE(ch) = (ParValue))
#define u32GetSMCISM_TABLE(ch)  (*pu32SMCISM_TABLE(ch) )
            
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
** |
** |     Requested Rules:
** |         Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types
** |                         Used for bit definitons generated by converter tool
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/

   

#endif /* SMCIO_H */ 
    
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

