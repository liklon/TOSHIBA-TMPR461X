
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : SysCon_PDH 
/  Date of creation (y-m-d:time): 2015-01-20+01:00  :  10:13:41.386+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.16 $ 
/  Excel Sheet ver.             : vv9.19
/  Excel Sheet date             : 2014-Oct-24
/  Excel Sheet author           : BEL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : CCR_PDH low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : CCR
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.16 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef SysCon_PDHIO_H
#define SysCon_PDHIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */ 

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_CCR_PDH_IO_H_REVISION     "$Revision: 1.16 $"
#define LLDD_CCR_PDH_IO_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/
/* disable following Misra errors for io files */
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : disable No reuse of identifiers */
  #pragma ghs nowarning 230   /* Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types */
#endif
 
/**********************************************
*                 globale variables           *
**********************************************/
#ifdef FPGA
extern volatile uint16_t u16CcrBootPins;
#endif     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_KEYR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000400                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_KEYR_REG__       0xC0000400U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   KEYVAL	:32; 	 /* 0..31  bit(s) R/W */                    
} PDHR_KEYR_bit_view_st;
        

/* WORD View */
typedef uint32_t u32PDHR_KEYR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_KEYR()     ((volatile PDHR_KEYR_bit_view_st *)\
(PDHR_KEYR_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32PDHR_KEYR()     ((volatile u32PDHR_KEYR_word_view *)\
(PDHR_KEYR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_KEYR_KEYVAL() (pst_bitPDHR_KEYR() -> KEYVAL)
#define vSetPDHR_KEYR_KEYVAL(ParValue)  (pst_bitPDHR_KEYR() -> KEYVAL=(ParValue))
            
/* Word access */
#define vSetPDHR_KEYR(ParValue)  (*pu32PDHR_KEYR() = (ParValue))
#define u32GetPDHR_KEYR()  (*pu32PDHR_KEYR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_VER                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000040C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_VER_REG__       0xC000040CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   VER	:2; 	 /* 0..1  bit(s) R */
  uint16_t   	:6; 	 /* 2..7  bit(s) R */
  uint16_t   FLASH_SIZE	:2; 	 /* 8..9  bit(s) R */ 
  uint16_t   	:6; 	 /* 10..31  bit(s) R */                    
} PDHR_VER_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_VER_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_VER_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_VER()     ((volatile PDHR_VER_bit_view_st *)\
(PDHR_VER_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_VER()     ((volatile PDHR_VER_byte_view_st *)\
(PDHR_VER_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_VER()     ((volatile u16PDHR_VER_halfword_view *)\
(PDHR_VER_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPDHR_VER_VER() (pst_bitPDHR_VER() -> VER)            
#define biGetPDHR_VER_FLASH_SIZE() (pst_bitPDHR_VER() -> FLASH_SIZE)
            
/* L-struct byte access */

#define u8GetPDHR_VERL() (pst_u8PDHR_VER() -> u8L)
/* H-struct byte access */

#define u8GetPDHR_VERH() (pst_u8PDHR_VER() -> u8H)
            
/* Half-word access */ 

#define u16GetPDHR_VER() (*pu16PDHR_VER() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_DBG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000410                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_DBG_REG__       0xC0000410U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CR4DEBUG	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   	:7; 	 /* 1..7  bit(s) R */
  uint16_t   CM3DEBUG	:1; 	 /* 8..8  bit(s) R */ 
  uint16_t   	:7; 	 /* 9..31  bit(s) R */                    
} PDHR_DBG_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_DBG_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_DBG_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_DBG()     ((volatile PDHR_DBG_bit_view_st *)\
(PDHR_DBG_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_DBG()     ((volatile PDHR_DBG_byte_view_st *)\
(PDHR_DBG_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_DBG()     ((volatile u16PDHR_DBG_halfword_view *)\
(PDHR_DBG_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_DBG_CR4DEBUG() (pst_bitPDHR_DBG() -> CR4DEBUG)
#define vSetPDHR_DBG_CR4DEBUG(ParValue)  (pst_bitPDHR_DBG() -> CR4DEBUG=(ParValue))            
#define biGetPDHR_DBG_CM3DEBUG() (pst_bitPDHR_DBG() -> CM3DEBUG)
            
/* L-struct byte access */
#define vSetPDHR_DBGL(ParValue) (pst_u8PDHR_DBG() -> u8L = (ParValue))
#define u8GetPDHR_DBGL() (pst_u8PDHR_DBG() -> u8L)
/* H-struct byte access */
#define vSetPDHR_DBGH(ParValue) (pst_u8PDHR_DBG() -> u8H = (ParValue))
#define u8GetPDHR_DBGH() (pst_u8PDHR_DBG() -> u8H)
            
/* Half-word access */ 
#define vSetPDHR_DBG(ParValue) (*pu16PDHR_DBG()  = (ParValue))
#define u16GetPDHR_DBG() (*pu16PDHR_DBG() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_VREGCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000414                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_VREGCR_REG__       0xC0000414U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   VREG_IT	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:5; 	 /* 3..7  bit(s) R */
  uint32_t   VREG_VT	:5; 	 /* 8..12  bit(s) R/W */
  uint32_t   	:3; 	 /* 13..15  bit(s) R */
  uint32_t   VREG_TT	:3; 	 /* 16..18  bit(s) R/W */ 
  uint32_t   	:13; 	 /* 19..31  bit(s) R */                    
} PDHR_VREGCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PDHR_VREGCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PDHR_VREGCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PDHR_VREGCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_VREGCR()     ((volatile PDHR_VREGCR_bit_view_st *)\
(PDHR_VREGCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_VREGCR()     ((volatile PDHR_VREGCR_byte_view_st *)\
(PDHR_VREGCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PDHR_VREGCR()     ((volatile PDHR_VREGCR_halfword_view_st *)\
(PDHR_VREGCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PDHR_VREGCR()     ((volatile u32PDHR_VREGCR_word_view *)\
(PDHR_VREGCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_VREGCR_VREG_IT() (pst_bitPDHR_VREGCR() -> VREG_IT)
#define vSetPDHR_VREGCR_VREG_IT(ParValue)  (pst_bitPDHR_VREGCR() -> VREG_IT=(ParValue))
#define biGetPDHR_VREGCR_VREG_VT() (pst_bitPDHR_VREGCR() -> VREG_VT)
#define vSetPDHR_VREGCR_VREG_VT(ParValue)  (pst_bitPDHR_VREGCR() -> VREG_VT=(ParValue))
#define biGetPDHR_VREGCR_VREG_TT() (pst_bitPDHR_VREGCR() -> VREG_TT)
#define vSetPDHR_VREGCR_VREG_TT(ParValue)  (pst_bitPDHR_VREGCR() -> VREG_TT=(ParValue))
            
/* LL-struct byte access */
#define vSetPDHR_VREGCRLL(ParValue) (pst_u8PDHR_VREGCR() -> u8LL = (ParValue))
#define u8GetPDHR_VREGCRLL() (pst_u8PDHR_VREGCR() -> u8LL)
/* LH-struct byte access */
#define vSetPDHR_VREGCRLH(ParValue) (pst_u8PDHR_VREGCR() -> u8LH = (ParValue))
#define u8GetPDHR_VREGCRLH() (pst_u8PDHR_VREGCR() -> u8LH)
/* HL-struct byte access */
#define vSetPDHR_VREGCRHL(ParValue) (pst_u8PDHR_VREGCR() -> u8HL = (ParValue))
#define u8GetPDHR_VREGCRHL() (pst_u8PDHR_VREGCR() -> u8HL)
/* HH-struct byte access */
#define vSetPDHR_VREGCRHH(ParValue) (pst_u8PDHR_VREGCR() -> u8HH = (ParValue))
#define u8GetPDHR_VREGCRHH() (pst_u8PDHR_VREGCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPDHR_VREGCRL(ParValue) (pst_u16PDHR_VREGCR() -> u16L = (ParValue))
#define u16GetPDHR_VREGCRL() (pst_u16PDHR_VREGCR() -> u16L)
#define vSetPDHR_VREGCRH(ParValue) (pst_u16PDHR_VREGCR() -> u16H = (ParValue))
#define u16GetPDHR_VREGCRH() (pst_u16PDHR_VREGCR() -> u16H)
            
/* Word access */
#define vSetPDHR_VREGCR(ParValue)  (*pu32PDHR_VREGCR() = (ParValue))
#define u32GetPDHR_VREGCR()  (*pu32PDHR_VREGCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_ANACR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000418                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_ANACR_REG__       0xC0000418U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   RCOSC_ADJUST	:4; 	 /* 0..3  bit(s) R/W */
  uint32_t   	:12; 	 /* 4..15  bit(s) R */
  uint32_t   LVD_THRSH	:3; 	 /* 16..18  bit(s) R/W */ 
  uint32_t   	:13; 	 /* 19..31  bit(s) R */                    
} PDHR_ANACR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PDHR_ANACR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PDHR_ANACR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PDHR_ANACR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_ANACR()     ((volatile PDHR_ANACR_bit_view_st *)\
(PDHR_ANACR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_ANACR()     ((volatile PDHR_ANACR_byte_view_st *)\
(PDHR_ANACR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PDHR_ANACR()     ((volatile PDHR_ANACR_halfword_view_st *)\
(PDHR_ANACR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PDHR_ANACR()     ((volatile u32PDHR_ANACR_word_view *)\
(PDHR_ANACR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_ANACR_RCOSC_ADJUST() (pst_bitPDHR_ANACR() -> RCOSC_ADJUST)
#define vSetPDHR_ANACR_RCOSC_ADJUST(ParValue)  (pst_bitPDHR_ANACR() -> RCOSC_ADJUST=(ParValue))
#define biGetPDHR_ANACR_LVD_THRSH() (pst_bitPDHR_ANACR() -> LVD_THRSH)
#define vSetPDHR_ANACR_LVD_THRSH(ParValue)  (pst_bitPDHR_ANACR() -> LVD_THRSH=(ParValue))
            
/* LL-struct byte access */
#define vSetPDHR_ANACRLL(ParValue) (pst_u8PDHR_ANACR() -> u8LL = (ParValue))
#define u8GetPDHR_ANACRLL() (pst_u8PDHR_ANACR() -> u8LL)
/* LH-struct byte access */
#define vSetPDHR_ANACRLH(ParValue) (pst_u8PDHR_ANACR() -> u8LH = (ParValue))
#define u8GetPDHR_ANACRLH() (pst_u8PDHR_ANACR() -> u8LH)
/* HL-struct byte access */
#define vSetPDHR_ANACRHL(ParValue) (pst_u8PDHR_ANACR() -> u8HL = (ParValue))
#define u8GetPDHR_ANACRHL() (pst_u8PDHR_ANACR() -> u8HL)
/* HH-struct byte access */
#define vSetPDHR_ANACRHH(ParValue) (pst_u8PDHR_ANACR() -> u8HH = (ParValue))
#define u8GetPDHR_ANACRHH() (pst_u8PDHR_ANACR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPDHR_ANACRL(ParValue) (pst_u16PDHR_ANACR() -> u16L = (ParValue))
#define u16GetPDHR_ANACRL() (pst_u16PDHR_ANACR() -> u16L)
#define vSetPDHR_ANACRH(ParValue) (pst_u16PDHR_ANACR() -> u16H = (ParValue))
#define u16GetPDHR_ANACRH() (pst_u16PDHR_ANACR() -> u16H)
            
/* Word access */
#define vSetPDHR_ANACR(ParValue)  (*pu32PDHR_ANACR() = (ParValue))
#define u32GetPDHR_ANACR()  (*pu32PDHR_ANACR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_ALAMCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000041C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_ALAMCR_REG__       0xC000041CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ALM_THRSH0	:6; 	 /* 0..5  bit(s) R/W */
  uint32_t   VMAIN_DROP	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   V33_DROP	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   ALM_EN_0	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   ALM_EN	:1; 	 /* 9..9  bit(s) R/W */
  uint32_t   	:6; 	 /* 10..15  bit(s) R */
  uint32_t   ALM_THRSH1	:6; 	 /* 16..21  bit(s) R/W */
  uint32_t   VSUB_DROP	:1; 	 /* 22..22  bit(s) R/W */
  uint32_t   	:1; 	 /* 23..23  bit(s) R */
  uint32_t   ALM_EN_1	:1; 	 /* 24..24  bit(s) R/W */ 
  uint32_t   	:7; 	 /* 25..31  bit(s) R */                    
} PDHR_ALAMCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PDHR_ALAMCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PDHR_ALAMCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PDHR_ALAMCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_ALAMCR()     ((volatile PDHR_ALAMCR_bit_view_st *)\
(PDHR_ALAMCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_ALAMCR()     ((volatile PDHR_ALAMCR_byte_view_st *)\
(PDHR_ALAMCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PDHR_ALAMCR()     ((volatile PDHR_ALAMCR_halfword_view_st *)\
(PDHR_ALAMCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PDHR_ALAMCR()     ((volatile u32PDHR_ALAMCR_word_view *)\
(PDHR_ALAMCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_ALAMCR_ALM_THRSH0() (pst_bitPDHR_ALAMCR() -> ALM_THRSH0)
#define vSetPDHR_ALAMCR_ALM_THRSH0(ParValue)  (pst_bitPDHR_ALAMCR() -> ALM_THRSH0=(ParValue))
#define biGetPDHR_ALAMCR_VMAIN_DROP() (pst_bitPDHR_ALAMCR() -> VMAIN_DROP)
#define vSetPDHR_ALAMCR_VMAIN_DROP(ParValue)  (pst_bitPDHR_ALAMCR() -> VMAIN_DROP=(ParValue))
#define biGetPDHR_ALAMCR_V33_DROP() (pst_bitPDHR_ALAMCR() -> V33_DROP)
#define vSetPDHR_ALAMCR_V33_DROP(ParValue)  (pst_bitPDHR_ALAMCR() -> V33_DROP=(ParValue))
#define biGetPDHR_ALAMCR_ALM_EN_0() (pst_bitPDHR_ALAMCR() -> ALM_EN_0)
#define vSetPDHR_ALAMCR_ALM_EN_0(ParValue)  (pst_bitPDHR_ALAMCR() -> ALM_EN_0=(ParValue))
#define biGetPDHR_ALAMCR_ALM_EN() (pst_bitPDHR_ALAMCR() -> ALM_EN)
#define vSetPDHR_ALAMCR_ALM_EN(ParValue)  (pst_bitPDHR_ALAMCR() -> ALM_EN=(ParValue))
#define biGetPDHR_ALAMCR_ALM_THRSH1() (pst_bitPDHR_ALAMCR() -> ALM_THRSH1)
#define vSetPDHR_ALAMCR_ALM_THRSH1(ParValue)  (pst_bitPDHR_ALAMCR() -> ALM_THRSH1=(ParValue))
#define biGetPDHR_ALAMCR_VSUB_DROP() (pst_bitPDHR_ALAMCR() -> VSUB_DROP)
#define vSetPDHR_ALAMCR_VSUB_DROP(ParValue)  (pst_bitPDHR_ALAMCR() -> VSUB_DROP=(ParValue))
#define biGetPDHR_ALAMCR_ALM_EN_1() (pst_bitPDHR_ALAMCR() -> ALM_EN_1)
#define vSetPDHR_ALAMCR_ALM_EN_1(ParValue)  (pst_bitPDHR_ALAMCR() -> ALM_EN_1=(ParValue))
            
/* LL-struct byte access */
#define vSetPDHR_ALAMCRLL(ParValue) (pst_u8PDHR_ALAMCR() -> u8LL = (ParValue))
#define u8GetPDHR_ALAMCRLL() (pst_u8PDHR_ALAMCR() -> u8LL)
/* LH-struct byte access */
#define vSetPDHR_ALAMCRLH(ParValue) (pst_u8PDHR_ALAMCR() -> u8LH = (ParValue))
#define u8GetPDHR_ALAMCRLH() (pst_u8PDHR_ALAMCR() -> u8LH)
/* HL-struct byte access */
#define vSetPDHR_ALAMCRHL(ParValue) (pst_u8PDHR_ALAMCR() -> u8HL = (ParValue))
#define u8GetPDHR_ALAMCRHL() (pst_u8PDHR_ALAMCR() -> u8HL)
/* HH-struct byte access */
#define vSetPDHR_ALAMCRHH(ParValue) (pst_u8PDHR_ALAMCR() -> u8HH = (ParValue))
#define u8GetPDHR_ALAMCRHH() (pst_u8PDHR_ALAMCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPDHR_ALAMCRL(ParValue) (pst_u16PDHR_ALAMCR() -> u16L = (ParValue))
#define u16GetPDHR_ALAMCRL() (pst_u16PDHR_ALAMCR() -> u16L)
#define vSetPDHR_ALAMCRH(ParValue) (pst_u16PDHR_ALAMCR() -> u16H = (ParValue))
#define u16GetPDHR_ALAMCRH() (pst_u16PDHR_ALAMCR() -> u16H)
            
/* Word access */
#define vSetPDHR_ALAMCR(ParValue)  (*pu32PDHR_ALAMCR() = (ParValue))
#define u32GetPDHR_ALAMCR()  (*pu32PDHR_ALAMCR() )                 

    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_CSVOSC10M                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000420                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_CSVOSC10M_REG__       0xC0000420U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CSV_OSC10MEN	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   	:7; 	 /* 1..7  bit(s) R */
  uint16_t   CSV_OSC10MRST	:1; 	 /* 8..8  bit(s) R/W */ 
  uint16_t   	:7; 	 /* 9..31  bit(s) R */                    
} PDHR_CSVOSC10M_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_CSVOSC10M_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_CSVOSC10M_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_CSVOSC10M()     ((volatile PDHR_CSVOSC10M_bit_view_st *)\
(PDHR_CSVOSC10M_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_CSVOSC10M()     ((volatile PDHR_CSVOSC10M_byte_view_st *)\
(PDHR_CSVOSC10M_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_CSVOSC10M()     ((volatile u16PDHR_CSVOSC10M_halfword_view *)\
(PDHR_CSVOSC10M_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_CSVOSC10M_CSV_OSC10MEN() (pst_bitPDHR_CSVOSC10M() -> CSV_OSC10MEN)
#define vSetPDHR_CSVOSC10M_CSV_OSC10MEN(ParValue)  (pst_bitPDHR_CSVOSC10M() -> CSV_OSC10MEN=(ParValue))
#define biGetPDHR_CSVOSC10M_CSV_OSC10MRST() (pst_bitPDHR_CSVOSC10M() -> CSV_OSC10MRST)
#define vSetPDHR_CSVOSC10M_CSV_OSC10MRST(ParValue)  (pst_bitPDHR_CSVOSC10M() -> CSV_OSC10MRST=(ParValue))
            
/* L-struct byte access */
#define vSetPDHR_CSVOSC10ML(ParValue) (pst_u8PDHR_CSVOSC10M() -> u8L = (ParValue))
#define u8GetPDHR_CSVOSC10ML() (pst_u8PDHR_CSVOSC10M() -> u8L)
/* H-struct byte access */
#define vSetPDHR_CSVOSC10MH(ParValue) (pst_u8PDHR_CSVOSC10M() -> u8H = (ParValue))
#define u8GetPDHR_CSVOSC10MH() (pst_u8PDHR_CSVOSC10M() -> u8H)
            
/* Half-word access */ 
#define vSetPDHR_CSVOSC10M(ParValue) (*pu16PDHR_CSVOSC10M()  = (ParValue))
#define u16GetPDHR_CSVOSC10M() (*pu16PDHR_CSVOSC10M() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_CSVOSC32KEN                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000424                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_CSVOSC32KEN_REG__       0xC0000424U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   CSV_OSC32KEN	:1; 	 /* 0..0  bit(s) R/W */ 
  uint8_t   	:7; 	 /* 1..31  bit(s) R */                    
} PDHR_CSVOSC32KEN_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8PDHR_CSVOSC32KEN_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_CSVOSC32KEN()     ((volatile PDHR_CSVOSC32KEN_bit_view_st *)\
(PDHR_CSVOSC32KEN_REG__ ))
        
/* Pointer to BYTE  */
#define pu8PDHR_CSVOSC32KEN()     ((volatile u8PDHR_CSVOSC32KEN_byte_view *)\
(PDHR_CSVOSC32KEN_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_CSVOSC32KEN_CSV_OSC32KEN() (pst_bitPDHR_CSVOSC32KEN() -> CSV_OSC32KEN)
#define vSetPDHR_CSVOSC32KEN_CSV_OSC32KEN(ParValue)  (pst_bitPDHR_CSVOSC32KEN() -> CSV_OSC32KEN=(ParValue))
            
/* byte access */
#define vSetPDHR_CSVOSC32KEN(ParValue) (*pu8PDHR_CSVOSC32KEN() = (ParValue))
#define u8GetPDHR_CSVOSC32KEN() (*pu8PDHR_CSVOSC32KEN() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_CFGR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000428                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_CFGR_REG__       0xC0000428U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   OSC32KD	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   	:7; 	 /* 1..7  bit(s) R */
  uint16_t   SMC3VONLY	:1; 	 /* 8..8  bit(s) R/W */ 
  uint16_t   	:7; 	 /* 9..31  bit(s) R */                    
} PDHR_CFGR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_CFGR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_CFGR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_CFGR()     ((volatile PDHR_CFGR_bit_view_st *)\
(PDHR_CFGR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_CFGR()     ((volatile PDHR_CFGR_byte_view_st *)\
(PDHR_CFGR_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_CFGR()     ((volatile u16PDHR_CFGR_halfword_view *)\
(PDHR_CFGR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_CFGR_OSC32KD() (pst_bitPDHR_CFGR() -> OSC32KD)
#define vSetPDHR_CFGR_OSC32KD(ParValue)  (pst_bitPDHR_CFGR() -> OSC32KD=(ParValue))
#define biGetPDHR_CFGR_SMC3VONLY() (pst_bitPDHR_CFGR() -> SMC3VONLY)
#define vSetPDHR_CFGR_SMC3VONLY(ParValue)  (pst_bitPDHR_CFGR() -> SMC3VONLY=(ParValue))
            
/* L-struct byte access */
#define vSetPDHR_CFGRL(ParValue) (pst_u8PDHR_CFGR() -> u8L = (ParValue))
#define u8GetPDHR_CFGRL() (pst_u8PDHR_CFGR() -> u8L)
/* H-struct byte access */
#define vSetPDHR_CFGRH(ParValue) (pst_u8PDHR_CFGR() -> u8H = (ParValue))
#define u8GetPDHR_CFGRH() (pst_u8PDHR_CFGR() -> u8H)
            
/* Half-word access */ 
#define vSetPDHR_CFGR(ParValue) (*pu16PDHR_CFGR()  = (ParValue))
#define u16GetPDHR_CFGR() (*pu16PDHR_CFGR() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_SBCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000042C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_SBCR_REG__       0xC000042CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   OSC10MSTBC	:5; 	 /* 0..4  bit(s) R/W */
  uint16_t   	:3; 	 /* 5..7  bit(s) R */
  uint16_t   OSC32KSTBC	:5; 	 /* 8..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..31  bit(s) R */                    
} PDHR_SBCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_SBCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_SBCR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_SBCR()     ((volatile PDHR_SBCR_bit_view_st *)\
(PDHR_SBCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_SBCR()     ((volatile PDHR_SBCR_byte_view_st *)\
(PDHR_SBCR_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_SBCR()     ((volatile u16PDHR_SBCR_halfword_view *)\
(PDHR_SBCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_SBCR_OSC10MSTBC() (pst_bitPDHR_SBCR() -> OSC10MSTBC)
#define vSetPDHR_SBCR_OSC10MSTBC(ParValue)  (pst_bitPDHR_SBCR() -> OSC10MSTBC=(ParValue))
#define biGetPDHR_SBCR_OSC32KSTBC() (pst_bitPDHR_SBCR() -> OSC32KSTBC)
#define vSetPDHR_SBCR_OSC32KSTBC(ParValue)  (pst_bitPDHR_SBCR() -> OSC32KSTBC=(ParValue))
            
/* L-struct byte access */
#define vSetPDHR_SBCRL(ParValue) (pst_u8PDHR_SBCR() -> u8L = (ParValue))
#define u8GetPDHR_SBCRL() (pst_u8PDHR_SBCR() -> u8L)
/* H-struct byte access */
#define vSetPDHR_SBCRH(ParValue) (pst_u8PDHR_SBCR() -> u8H = (ParValue))
#define u8GetPDHR_SBCRH() (pst_u8PDHR_SBCR() -> u8H)
            
/* Half-word access */ 
#define vSetPDHR_SBCR(ParValue) (*pu16PDHR_SBCR()  = (ParValue))
#define u16GetPDHR_SBCR() (*pu16PDHR_SBCR() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_BOOTOPT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000430                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifdef FPGA
#define PDHR_BOOTOPT_REG__       (&u16CcrBootPins)
#else
#define PDHR_BOOTOPT_REG__       0xC0000430U
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   BOOT_SRC	:3; 	 /* 0..2  bit(s) R */
  uint16_t   BOOT_OPT	:2; 	 /* 3..4  bit(s) R */
  uint16_t   NAND_XTRA_BLK	:1; 	 /* 5..5  bit(s) R */
  uint16_t   NAND_ECC_TYPE	:1; 	 /* 6..6  bit(s) R */
  uint16_t   PORT_SELECTION	:2; 	 /* 7..8  bit(s) R */
  uint16_t   TSM_Debug	:1; 	 /* 9..9  bit(s) R */
  uint16_t   CR4_START	:1; 	 /* 10..10  bit(s) R */
  uint16_t   SSCEN	:1; 	 /* 11..11  bit(s) R */
  uint16_t   FRQSEL	:1; 	 /* 12..12  bit(s) R */
  uint16_t   	:1; 	 /* 13..13  bit(s) R */
  uint16_t   STBCDIS	:1; 	 /* 14..14  bit(s) R */
  uint16_t   TESTMODEN	:1; 	 /* 15..15  bit(s) R */                    
} PDHR_BOOTOPT_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_BOOTOPT_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_BOOTOPT_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_BOOTOPT()     ((volatile PDHR_BOOTOPT_bit_view_st *)\
(PDHR_BOOTOPT_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_BOOTOPT()     ((volatile PDHR_BOOTOPT_byte_view_st *)\
(PDHR_BOOTOPT_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_BOOTOPT()     ((volatile u16PDHR_BOOTOPT_halfword_view *)\
(PDHR_BOOTOPT_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPDHR_BOOTOPT_BOOT_SRC() (pst_bitPDHR_BOOTOPT() -> BOOT_SRC)            
#define biGetPDHR_BOOTOPT_BOOT_OPT() (pst_bitPDHR_BOOTOPT() -> BOOT_OPT)            
#define biGetPDHR_BOOTOPT_NAND_XTRA_BLK() (pst_bitPDHR_BOOTOPT() -> NAND_XTRA_BLK)            
#define biGetPDHR_BOOTOPT_NAND_ECC_TYPE() (pst_bitPDHR_BOOTOPT() -> NAND_ECC_TYPE)            
#define biGetPDHR_BOOTOPT_PORT_SELECTION() (pst_bitPDHR_BOOTOPT() -> PORT_SELECTION)            
#define biGetPDHR_BOOTOPT_TSM_Debug() (pst_bitPDHR_BOOTOPT() -> TSM_Debug)
#define biGetPDHR_BOOTOPT_CR4_START() (pst_bitPDHR_BOOTOPT() -> CR4_START)            
#define biGetPDHR_BOOTOPT_SSCEN() (pst_bitPDHR_BOOTOPT() -> SSCEN)            
#define biGetPDHR_BOOTOPT_FRQSEL() (pst_bitPDHR_BOOTOPT() -> FRQSEL)            
#define biGetPDHR_BOOTOPT_STBCDIS() (pst_bitPDHR_BOOTOPT() -> STBCDIS)            
#define biGetPDHR_BOOTOPT_TESTMODEN() (pst_bitPDHR_BOOTOPT() -> TESTMODEN)
            
/* L-struct byte access */

#define u8GetPDHR_BOOTOPTL() (pst_u8PDHR_BOOTOPT() -> u8L)
/* H-struct byte access */

#define u8GetPDHR_BOOTOPTH() (pst_u8PDHR_BOOTOPT() -> u8H)
            
/* Half-word access */ 

#define u16GetPDHR_BOOTOPT() (*pu16PDHR_BOOTOPT() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_INTSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000434                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_INTSR_REG__       0xC0000434U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CSV10MINT	:1; 	 /* 0..0  bit(s) R */
  uint32_t   	:7; 	 /* 1..7  bit(s) R */
  uint32_t   CSV32KINT	:1; 	 /* 8..8  bit(s) R */
  uint32_t   	:7; 	 /* 9..15  bit(s) R */
  uint32_t   ERRINT0	:1; 	 /* 16..16  bit(s) R */
  uint32_t   ERRINT1	:1; 	 /* 17..17  bit(s) R */
  uint32_t   ERRINT2	:1; 	 /* 18..18  bit(s) R */
  uint32_t   	:5; 	 /* 19..23  bit(s) R */
  uint32_t   BKPRAM_ECCNMI	:1; 	 /* 24..24  bit(s) R */
  uint32_t   MM_ECCNMI	:1; 	 /* 25..25  bit(s) R */
  uint32_t   STPU_NMI	:1; 	 /* 26..26  bit(s) R */
  uint32_t   WDT_NMI	:1; 	 /* 27..27  bit(s) R */
  uint32_t   IO_NMI	:1; 	 /* 28..28  bit(s) R */ 
  uint32_t   	:3; 	 /* 29..31  bit(s) R */                    
} PDHR_INTSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PDHR_INTSR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PDHR_INTSR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PDHR_INTSR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_INTSR()     ((volatile PDHR_INTSR_bit_view_st *)\
(PDHR_INTSR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_INTSR()     ((volatile PDHR_INTSR_byte_view_st *)\
(PDHR_INTSR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PDHR_INTSR()     ((volatile PDHR_INTSR_halfword_view_st *)\
(PDHR_INTSR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PDHR_INTSR()     ((volatile u32PDHR_INTSR_word_view *)\
(PDHR_INTSR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPDHR_INTSR_CSV10MINT() (pst_bitPDHR_INTSR() -> CSV10MINT)            
#define biGetPDHR_INTSR_CSV32KINT() (pst_bitPDHR_INTSR() -> CSV32KINT)            
#define biGetPDHR_INTSR_ERRINT0() (pst_bitPDHR_INTSR() -> ERRINT0)            
#define biGetPDHR_INTSR_ERRINT1() (pst_bitPDHR_INTSR() -> ERRINT1)            
#define biGetPDHR_INTSR_ERRINT2() (pst_bitPDHR_INTSR() -> ERRINT2)            
#define biGetPDHR_INTSR_BKPRAM_ECCNMI() (pst_bitPDHR_INTSR() -> BKPRAM_ECCNMI)            
#define biGetPDHR_INTSR_MM_ECCNMI() (pst_bitPDHR_INTSR() -> MM_ECCNMI)            
#define biGetPDHR_INTSR_STPU_NMI() (pst_bitPDHR_INTSR() -> STPU_NMI)            
#define biGetPDHR_INTSR_WDT_NMI() (pst_bitPDHR_INTSR() -> WDT_NMI)            
#define biGetPDHR_INTSR_IO_NMI() (pst_bitPDHR_INTSR() -> IO_NMI)
            
/* LL-struct byte access */

#define u8GetPDHR_INTSRLL() (pst_u8PDHR_INTSR() -> u8LL)
/* LH-struct byte access */

#define u8GetPDHR_INTSRLH() (pst_u8PDHR_INTSR() -> u8LH)
/* HL-struct byte access */

#define u8GetPDHR_INTSRHL() (pst_u8PDHR_INTSR() -> u8HL)
/* HH-struct byte access */

#define u8GetPDHR_INTSRHH() (pst_u8PDHR_INTSR() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetPDHR_INTSRL() (pst_u16PDHR_INTSR() -> u16L)

#define u16GetPDHR_INTSRH() (pst_u16PDHR_INTSR() -> u16H)
            
/* Word access */

#define u32GetPDHR_INTSR()  (*pu32PDHR_INTSR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_INTCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000438                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_INTCR_REG__       0xC0000438U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CSV10MINTC	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   	:7; 	 /* 1..7  bit(s) R */
  uint32_t   CSV32KINTC	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   	:7; 	 /* 9..15  bit(s) R */
  uint32_t   ERRINT0C	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   ERRINT1C	:1; 	 /* 17..17  bit(s) R/W */
  uint32_t   ERRINT2C	:1; 	 /* 18..18  bit(s) R/W */
  uint32_t   	:9; 	 /* 19..27  bit(s) R */
  uint32_t   IO_NMIC	:1; 	 /* 28..28  bit(s) R/W */ 
  uint32_t   	:3; 	 /* 29..31  bit(s) R */                    
} PDHR_INTCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PDHR_INTCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PDHR_INTCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PDHR_INTCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_INTCR()     ((volatile PDHR_INTCR_bit_view_st *)\
(PDHR_INTCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_INTCR()     ((volatile PDHR_INTCR_byte_view_st *)\
(PDHR_INTCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PDHR_INTCR()     ((volatile PDHR_INTCR_halfword_view_st *)\
(PDHR_INTCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PDHR_INTCR()     ((volatile u32PDHR_INTCR_word_view *)\
(PDHR_INTCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_INTCR_CSV10MINTC() (pst_bitPDHR_INTCR() -> CSV10MINTC)
#define vSetPDHR_INTCR_CSV10MINTC(ParValue)  (pst_bitPDHR_INTCR() -> CSV10MINTC=(ParValue))
#define biGetPDHR_INTCR_CSV32KINTC() (pst_bitPDHR_INTCR() -> CSV32KINTC)
#define vSetPDHR_INTCR_CSV32KINTC(ParValue)  (pst_bitPDHR_INTCR() -> CSV32KINTC=(ParValue))
#define biGetPDHR_INTCR_ERRINT0C() (pst_bitPDHR_INTCR() -> ERRINT0C)
#define vSetPDHR_INTCR_ERRINT0C(ParValue)  (pst_bitPDHR_INTCR() -> ERRINT0C=(ParValue))
#define biGetPDHR_INTCR_ERRINT1C() (pst_bitPDHR_INTCR() -> ERRINT1C)
#define vSetPDHR_INTCR_ERRINT1C(ParValue)  (pst_bitPDHR_INTCR() -> ERRINT1C=(ParValue))
#define biGetPDHR_INTCR_ERRINT2C() (pst_bitPDHR_INTCR() -> ERRINT2C)
#define vSetPDHR_INTCR_ERRINT2C(ParValue)  (pst_bitPDHR_INTCR() -> ERRINT2C=(ParValue))
#define biGetPDHR_INTCR_IO_NMIC() (pst_bitPDHR_INTCR() -> IO_NMIC)
#define vSetPDHR_INTCR_IO_NMIC(ParValue)  (pst_bitPDHR_INTCR() -> IO_NMIC=(ParValue))
            
/* LL-struct byte access */
#define vSetPDHR_INTCRLL(ParValue) (pst_u8PDHR_INTCR() -> u8LL = (ParValue))
#define u8GetPDHR_INTCRLL() (pst_u8PDHR_INTCR() -> u8LL)
/* LH-struct byte access */
#define vSetPDHR_INTCRLH(ParValue) (pst_u8PDHR_INTCR() -> u8LH = (ParValue))
#define u8GetPDHR_INTCRLH() (pst_u8PDHR_INTCR() -> u8LH)
/* HL-struct byte access */
#define vSetPDHR_INTCRHL(ParValue) (pst_u8PDHR_INTCR() -> u8HL = (ParValue))
#define u8GetPDHR_INTCRHL() (pst_u8PDHR_INTCR() -> u8HL)
/* HH-struct byte access */
#define vSetPDHR_INTCRHH(ParValue) (pst_u8PDHR_INTCR() -> u8HH = (ParValue))
#define u8GetPDHR_INTCRHH() (pst_u8PDHR_INTCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPDHR_INTCRL(ParValue) (pst_u16PDHR_INTCR() -> u16L = (ParValue))
#define u16GetPDHR_INTCRL() (pst_u16PDHR_INTCR() -> u16L)
#define vSetPDHR_INTCRH(ParValue) (pst_u16PDHR_INTCR() -> u16H = (ParValue))
#define u16GetPDHR_INTCRH() (pst_u16PDHR_INTCR() -> u16H)
            
/* Word access */
#define vSetPDHR_INTCR(ParValue)  (*pu32PDHR_INTCR() = (ParValue))
#define u32GetPDHR_INTCR()  (*pu32PDHR_INTCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_ECCEN                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000043C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_ECCEN_REG__       0xC000043CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   BKPRAM_ECCEN	:2; 	 /* 0..1  bit(s) R/W */
  uint16_t   	:6; 	 /* 2..7  bit(s) R */
  uint16_t   MM_ECCEN	:2; 	 /* 8..9  bit(s) R/W */ 
  uint16_t   	:6; 	 /* 10..31  bit(s) R */                    
} PDHR_ECCEN_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_ECCEN_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_ECCEN_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_ECCEN()     ((volatile PDHR_ECCEN_bit_view_st *)\
(PDHR_ECCEN_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_ECCEN()     ((volatile PDHR_ECCEN_byte_view_st *)\
(PDHR_ECCEN_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_ECCEN()     ((volatile u16PDHR_ECCEN_halfword_view *)\
(PDHR_ECCEN_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_ECCEN_BKPRAM_ECCEN() (pst_bitPDHR_ECCEN() -> BKPRAM_ECCEN)
#define vSetPDHR_ECCEN_BKPRAM_ECCEN(ParValue)  (pst_bitPDHR_ECCEN() -> BKPRAM_ECCEN=(ParValue))
#define biGetPDHR_ECCEN_MM_ECCEN() (pst_bitPDHR_ECCEN() -> MM_ECCEN)
#define vSetPDHR_ECCEN_MM_ECCEN(ParValue)  (pst_bitPDHR_ECCEN() -> MM_ECCEN=(ParValue))
            
/* L-struct byte access */
#define vSetPDHR_ECCENL(ParValue) (pst_u8PDHR_ECCEN() -> u8L = (ParValue))
#define u8GetPDHR_ECCENL() (pst_u8PDHR_ECCEN() -> u8L)
/* H-struct byte access */
#define vSetPDHR_ECCENH(ParValue) (pst_u8PDHR_ECCEN() -> u8H = (ParValue))
#define u8GetPDHR_ECCENH() (pst_u8PDHR_ECCEN() -> u8H)
            
/* Half-word access */ 
#define vSetPDHR_ECCEN(ParValue) (*pu16PDHR_ECCEN()  = (ParValue))
#define u16GetPDHR_ECCEN() (*pu16PDHR_ECCEN() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_PRVSTATE                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000440                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_PRVSTATE_REG__       0xC0000440U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   STB_MODE	:1; 	 /* 0..0  bit(s) R */
  uint8_t   SLPOSC10_MODE	:1; 	 /* 1..1  bit(s) R */
  uint8_t   SLPRCOSC_MODE	:1; 	 /* 2..2  bit(s) R */
  uint8_t   STOPR_MODE	:1; 	 /* 3..3  bit(s) R */
  uint8_t   STOP_MODE	:1; 	 /* 4..4  bit(s) R */ 
  uint8_t   	:3; 	 /* 5..31  bit(s) R */                    
} PDHR_PRVSTATE_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8PDHR_PRVSTATE_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_PRVSTATE()     ((volatile PDHR_PRVSTATE_bit_view_st *)\
(PDHR_PRVSTATE_REG__ ))
        
/* Pointer to BYTE  */
#define pu8PDHR_PRVSTATE()     ((volatile u8PDHR_PRVSTATE_byte_view *)\
(PDHR_PRVSTATE_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPDHR_PRVSTATE_STB_MODE() (pst_bitPDHR_PRVSTATE() -> STB_MODE)            
#define biGetPDHR_PRVSTATE_SLPOSC10_MODE() (pst_bitPDHR_PRVSTATE() -> SLPOSC10_MODE)            
#define biGetPDHR_PRVSTATE_SLPRCOSC_MODE() (pst_bitPDHR_PRVSTATE() -> SLPRCOSC_MODE)            
#define biGetPDHR_PRVSTATE_STOPR_MODE() (pst_bitPDHR_PRVSTATE() -> STOPR_MODE)            
#define biGetPDHR_PRVSTATE_STOP_MODE() (pst_bitPDHR_PRVSTATE() -> STOP_MODE)
            
/* byte access */

#define u8GetPDHR_PRVSTATE() (*pu8PDHR_PRVSTATE() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_IOWKP_CFG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000444                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_IOWKP_CFG_REG__       0xC0000444U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WAK_SEL0	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   WAKINTEN0	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   WAK_SEL1	:3; 	 /* 4..6  bit(s) R/W */
  uint32_t   WAKINTEN1	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   WAK_SEL2	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   WAKINTEN2	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   WAK_SEL3	:3; 	 /* 12..14  bit(s) R/W */
  uint32_t   WAKINTEN3	:1; 	 /* 15..15  bit(s) R/W */
  uint32_t   WAK_SEL4	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   WAKINTEN4	:1; 	 /* 19..19  bit(s) R/W */
  uint32_t   WAK_SEL5	:3; 	 /* 20..22  bit(s) R/W */
  uint32_t   WAKINTEN5	:1; 	 /* 23..23  bit(s) R/W */
  uint32_t   WAK_SEL6	:3; 	 /* 24..26  bit(s) R/W */
  uint32_t   WAKINTEN6	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   WAK_SEL7	:3; 	 /* 28..30  bit(s) R/W */ 
  uint32_t   WAKINTEN7	:1; 	 /* 31..31  bit(s) R/W */                    
} PDHR_IOWKP_CFG_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} PDHR_IOWKP_CFG_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} PDHR_IOWKP_CFG_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32PDHR_IOWKP_CFG_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_IOWKP_CFG()     ((volatile PDHR_IOWKP_CFG_bit_view_st *)\
(PDHR_IOWKP_CFG_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_IOWKP_CFG()     ((volatile PDHR_IOWKP_CFG_byte_view_st *)\
(PDHR_IOWKP_CFG_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16PDHR_IOWKP_CFG()     ((volatile PDHR_IOWKP_CFG_halfword_view_st *)\
(PDHR_IOWKP_CFG_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32PDHR_IOWKP_CFG()     ((volatile u32PDHR_IOWKP_CFG_word_view *)\
(PDHR_IOWKP_CFG_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_IOWKP_CFG_WAK_SEL0() (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL0)
#define vSetPDHR_IOWKP_CFG_WAK_SEL0(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL0=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAKINTEN0() (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN0)
#define vSetPDHR_IOWKP_CFG_WAKINTEN0(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN0=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAK_SEL1() (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL1)
#define vSetPDHR_IOWKP_CFG_WAK_SEL1(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL1=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAKINTEN1() (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN1)
#define vSetPDHR_IOWKP_CFG_WAKINTEN1(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN1=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAK_SEL2() (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL2)
#define vSetPDHR_IOWKP_CFG_WAK_SEL2(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL2=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAKINTEN2() (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN2)
#define vSetPDHR_IOWKP_CFG_WAKINTEN2(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN2=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAK_SEL3() (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL3)
#define vSetPDHR_IOWKP_CFG_WAK_SEL3(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL3=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAKINTEN3() (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN3)
#define vSetPDHR_IOWKP_CFG_WAKINTEN3(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN3=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAK_SEL4() (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL4)
#define vSetPDHR_IOWKP_CFG_WAK_SEL4(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL4=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAKINTEN4() (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN4)
#define vSetPDHR_IOWKP_CFG_WAKINTEN4(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN4=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAK_SEL5() (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL5)
#define vSetPDHR_IOWKP_CFG_WAK_SEL5(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL5=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAKINTEN5() (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN5)
#define vSetPDHR_IOWKP_CFG_WAKINTEN5(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN5=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAK_SEL6() (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL6)
#define vSetPDHR_IOWKP_CFG_WAK_SEL6(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL6=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAKINTEN6() (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN6)
#define vSetPDHR_IOWKP_CFG_WAKINTEN6(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN6=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAK_SEL7() (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL7)
#define vSetPDHR_IOWKP_CFG_WAK_SEL7(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAK_SEL7=(ParValue))
#define biGetPDHR_IOWKP_CFG_WAKINTEN7() (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN7)
#define vSetPDHR_IOWKP_CFG_WAKINTEN7(ParValue)  (pst_bitPDHR_IOWKP_CFG() -> WAKINTEN7=(ParValue))
            
/* LL-struct byte access */
#define vSetPDHR_IOWKP_CFGLL(ParValue) (pst_u8PDHR_IOWKP_CFG() -> u8LL = (ParValue))
#define u8GetPDHR_IOWKP_CFGLL() (pst_u8PDHR_IOWKP_CFG() -> u8LL)
/* LH-struct byte access */
#define vSetPDHR_IOWKP_CFGLH(ParValue) (pst_u8PDHR_IOWKP_CFG() -> u8LH = (ParValue))
#define u8GetPDHR_IOWKP_CFGLH() (pst_u8PDHR_IOWKP_CFG() -> u8LH)
/* HL-struct byte access */
#define vSetPDHR_IOWKP_CFGHL(ParValue) (pst_u8PDHR_IOWKP_CFG() -> u8HL = (ParValue))
#define u8GetPDHR_IOWKP_CFGHL() (pst_u8PDHR_IOWKP_CFG() -> u8HL)
/* HH-struct byte access */
#define vSetPDHR_IOWKP_CFGHH(ParValue) (pst_u8PDHR_IOWKP_CFG() -> u8HH = (ParValue))
#define u8GetPDHR_IOWKP_CFGHH() (pst_u8PDHR_IOWKP_CFG() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetPDHR_IOWKP_CFGL(ParValue) (pst_u16PDHR_IOWKP_CFG() -> u16L = (ParValue))
#define u16GetPDHR_IOWKP_CFGL() (pst_u16PDHR_IOWKP_CFG() -> u16L)
#define vSetPDHR_IOWKP_CFGH(ParValue) (pst_u16PDHR_IOWKP_CFG() -> u16H = (ParValue))
#define u16GetPDHR_IOWKP_CFGH() (pst_u16PDHR_IOWKP_CFG() -> u16H)
            
/* Word access */
#define vSetPDHR_IOWKP_CFG(ParValue)  (*pu32PDHR_IOWKP_CFG() = (ParValue))
#define u32GetPDHR_IOWKP_CFG()  (*pu32PDHR_IOWKP_CFG() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_WAKINTS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0000448                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_WAKINTS_REG__       0xC0000448U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   WAKINTS0	:1; 	 /* 0..0  bit(s) R */
  uint16_t   WAKINTS1	:1; 	 /* 1..1  bit(s) R */
  uint16_t   WAKINTS2	:1; 	 /* 2..2  bit(s) R */
  uint16_t   WAKINTS3	:1; 	 /* 3..3  bit(s) R */
  uint16_t   WAKINTS4	:1; 	 /* 4..4  bit(s) R */
  uint16_t   WAKINTS5	:1; 	 /* 5..5  bit(s) R */
  uint16_t   WAKINTS6	:1; 	 /* 6..6  bit(s) R */
  uint16_t   WAKINTS7	:1; 	 /* 7..7  bit(s) R */
  uint16_t   NMI	:1; 	 /* 8..8  bit(s) R */
  uint16_t   ALARM	:1; 	 /* 9..9  bit(s) R */
  uint16_t   RTC	:1; 	 /* 10..10  bit(s) R */ 
  uint16_t   	:5; 	 /* 11..31  bit(s) R */                    
} PDHR_WAKINTS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_WAKINTS_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_WAKINTS_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_WAKINTS()     ((volatile PDHR_WAKINTS_bit_view_st *)\
(PDHR_WAKINTS_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_WAKINTS()     ((volatile PDHR_WAKINTS_byte_view_st *)\
(PDHR_WAKINTS_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_WAKINTS()     ((volatile u16PDHR_WAKINTS_halfword_view *)\
(PDHR_WAKINTS_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPDHR_WAKINTS_WAKINTS0() (pst_bitPDHR_WAKINTS() -> WAKINTS0)            
#define biGetPDHR_WAKINTS_WAKINTS1() (pst_bitPDHR_WAKINTS() -> WAKINTS1)            
#define biGetPDHR_WAKINTS_WAKINTS2() (pst_bitPDHR_WAKINTS() -> WAKINTS2)            
#define biGetPDHR_WAKINTS_WAKINTS3() (pst_bitPDHR_WAKINTS() -> WAKINTS3)            
#define biGetPDHR_WAKINTS_WAKINTS4() (pst_bitPDHR_WAKINTS() -> WAKINTS4)            
#define biGetPDHR_WAKINTS_WAKINTS5() (pst_bitPDHR_WAKINTS() -> WAKINTS5)            
#define biGetPDHR_WAKINTS_WAKINTS6() (pst_bitPDHR_WAKINTS() -> WAKINTS6)            
#define biGetPDHR_WAKINTS_WAKINTS7() (pst_bitPDHR_WAKINTS() -> WAKINTS7)            
#define biGetPDHR_WAKINTS_NMI() (pst_bitPDHR_WAKINTS() -> NMI)            
#define biGetPDHR_WAKINTS_ALARM() (pst_bitPDHR_WAKINTS() -> ALARM)            
#define biGetPDHR_WAKINTS_RTC() (pst_bitPDHR_WAKINTS() -> RTC)
            
/* L-struct byte access */

#define u8GetPDHR_WAKINTSL() (pst_u8PDHR_WAKINTS() -> u8L)
/* H-struct byte access */

#define u8GetPDHR_WAKINTSH() (pst_u8PDHR_WAKINTS() -> u8H)
            
/* Half-word access */ 

#define u16GetPDHR_WAKINTS() (*pu16PDHR_WAKINTS() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PDHR_WAKINTC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000044C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PDHR_WAKINTC_REG__       0xC000044CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   WAKINTC0	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   WAKINTC1	:1; 	 /* 1..1  bit(s) R/W */
  uint16_t   WAKINTC2	:1; 	 /* 2..2  bit(s) R/W */
  uint16_t   WAKINTC3	:1; 	 /* 3..3  bit(s) R/W */
  uint16_t   WAKINTC4	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   WAKINTC5	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   WAKINTC6	:1; 	 /* 6..6  bit(s) R/W */
  uint16_t   WAKINTC7	:1; 	 /* 7..7  bit(s) R/W */
  uint16_t   NMI_SC	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   ALARM_SC	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   RTC_SC	:1; 	 /* 10..10  bit(s) R/W */ 
  uint16_t   	:5; 	 /* 11..31  bit(s) R */                    
} PDHR_WAKINTC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PDHR_WAKINTC_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PDHR_WAKINTC_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPDHR_WAKINTC()     ((volatile PDHR_WAKINTC_bit_view_st *)\
(PDHR_WAKINTC_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PDHR_WAKINTC()     ((volatile PDHR_WAKINTC_byte_view_st *)\
(PDHR_WAKINTC_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16PDHR_WAKINTC()     ((volatile u16PDHR_WAKINTC_halfword_view *)\
(PDHR_WAKINTC_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPDHR_WAKINTC_WAKINTC0() (pst_bitPDHR_WAKINTC() -> WAKINTC0)
#define vSetPDHR_WAKINTC_WAKINTC0(ParValue)  (pst_bitPDHR_WAKINTC() -> WAKINTC0=(ParValue))
#define biGetPDHR_WAKINTC_WAKINTC1() (pst_bitPDHR_WAKINTC() -> WAKINTC1)
#define vSetPDHR_WAKINTC_WAKINTC1(ParValue)  (pst_bitPDHR_WAKINTC() -> WAKINTC1=(ParValue))
#define biGetPDHR_WAKINTC_WAKINTC2() (pst_bitPDHR_WAKINTC() -> WAKINTC2)
#define vSetPDHR_WAKINTC_WAKINTC2(ParValue)  (pst_bitPDHR_WAKINTC() -> WAKINTC2=(ParValue))
#define biGetPDHR_WAKINTC_WAKINTC3() (pst_bitPDHR_WAKINTC() -> WAKINTC3)
#define vSetPDHR_WAKINTC_WAKINTC3(ParValue)  (pst_bitPDHR_WAKINTC() -> WAKINTC3=(ParValue))
#define biGetPDHR_WAKINTC_WAKINTC4() (pst_bitPDHR_WAKINTC() -> WAKINTC4)
#define vSetPDHR_WAKINTC_WAKINTC4(ParValue)  (pst_bitPDHR_WAKINTC() -> WAKINTC4=(ParValue))
#define biGetPDHR_WAKINTC_WAKINTC5() (pst_bitPDHR_WAKINTC() -> WAKINTC5)
#define vSetPDHR_WAKINTC_WAKINTC5(ParValue)  (pst_bitPDHR_WAKINTC() -> WAKINTC5=(ParValue))
#define biGetPDHR_WAKINTC_WAKINTC6() (pst_bitPDHR_WAKINTC() -> WAKINTC6)
#define vSetPDHR_WAKINTC_WAKINTC6(ParValue)  (pst_bitPDHR_WAKINTC() -> WAKINTC6=(ParValue))
#define biGetPDHR_WAKINTC_WAKINTC7() (pst_bitPDHR_WAKINTC() -> WAKINTC7)
#define vSetPDHR_WAKINTC_WAKINTC7(ParValue)  (pst_bitPDHR_WAKINTC() -> WAKINTC7=(ParValue))
#define biGetPDHR_WAKINTC_NMI_SC() (pst_bitPDHR_WAKINTC() -> NMI_SC)
#define vSetPDHR_WAKINTC_NMI_SC(ParValue)  (pst_bitPDHR_WAKINTC() -> NMI_SC=(ParValue))
#define biGetPDHR_WAKINTC_ALARM_SC() (pst_bitPDHR_WAKINTC() -> ALARM_SC)
#define vSetPDHR_WAKINTC_ALARM_SC(ParValue)  (pst_bitPDHR_WAKINTC() -> ALARM_SC=(ParValue))
#define biGetPDHR_WAKINTC_RTC_SC() (pst_bitPDHR_WAKINTC() -> RTC_SC)
#define vSetPDHR_WAKINTC_RTC_SC(ParValue)  (pst_bitPDHR_WAKINTC() -> RTC_SC=(ParValue))
            
/* L-struct byte access */
#define vSetPDHR_WAKINTCL(ParValue) (pst_u8PDHR_WAKINTC() -> u8L = (ParValue))
#define u8GetPDHR_WAKINTCL() (pst_u8PDHR_WAKINTC() -> u8L)
/* H-struct byte access */
#define vSetPDHR_WAKINTCH(ParValue) (pst_u8PDHR_WAKINTC() -> u8H = (ParValue))
#define u8GetPDHR_WAKINTCH() (pst_u8PDHR_WAKINTC() -> u8H)
            
/* Half-word access */ 
#define vSetPDHR_WAKINTC(ParValue) (*pu16PDHR_WAKINTC()  = (ParValue))
#define u16GetPDHR_WAKINTC() (*pu16PDHR_WAKINTC() )

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
** |         Rule 5.7  [A] : No reuse of identifiers
** |
** |     Requested Rules:
** |         Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types
** |                         Used for bit definitons generated by converter tool
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/

#endif /* SysCon_PDHIO_H */ 
    
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

