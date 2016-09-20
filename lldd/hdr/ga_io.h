/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : GA 
/  Date of creation (y-m-d:time): 2013-06-14+02:00  :  15:42:04.554+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.12 $ 
/  Excel Sheet ver.             : vv1.0
/  Excel Sheet date             : 2013-Apr-24
/  Excel Sheet author           : BEL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION :
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : 
*   LIBRARIES   :
*****************************************************************************
*   VERSION     : $Revision: 1.12 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef GAIO_H
#define GAIO_H

/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */ 
/*********************************************/

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 230    /* Rule 6.4 [R] : 	nonstandard type for a bit field */
  #pragma ghs nowarning 1840   /* Rule 5.7 [A] : identifier reused from declaration of entity-kind "entity" */
#endif

/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_GA_IO_H_REVISION     "$Revision: 1.12 $"
#define LLDD_GA_IO_H_TAG          "$Name: LLDD_1_7_GFX $"

/**********************************************
*             extern defined varaibles
**********************************************/
#ifdef HW_EMULATION_GA
extern  volatile  uint32_t  GASCR_REG_EMUL;
extern  volatile  uint32_t  GACLAR_REG_EMUL;
extern  volatile  uint32_t  GASR_REG_EMUL;
extern  volatile  uint32_t  GAICR_REG_EMUL;
extern  volatile  uint32_t  GAIMR_REG_EMUL;
extern  volatile  uint32_t  GADR_REG_EMUL;
extern  volatile  uint32_t  GARBBEAR_REG_EMUL;
extern  volatile  uint32_t  GARBBECR_REG_EMUL;
extern  volatile  uint32_t  GACBBEAR_REG_EMUL;
extern  volatile  uint32_t  GACBBECR_REG_EMUL;
extern  volatile  uint32_t  GAWBRBEAR_REG_EMUL;
extern  volatile  uint32_t  GAWBRBECR_REG_EMUL;
extern  volatile  uint32_t  GAWBWBEAR_REG_EMUL;
extern  volatile  uint32_t  GAWBWBECR_REG_EMUL;
extern  volatile  uint32_t  GAMPR0LR_REG_EMUL;
extern  volatile  uint32_t  GAMPR0HR_REG_EMUL;
extern  volatile  uint32_t  GAMPR1LR_REG_EMUL;
extern  volatile  uint32_t  GAMPR1HR_REG_EMUL;
extern  volatile  uint32_t  GAMPICR_REG_EMUL;
extern  volatile  uint32_t  GAMPIMR_REG_EMUL;
extern  volatile  uint32_t  GAMPACR_REG_EMUL;
extern  volatile  uint32_t  GAGPR_REG_EMUL[32];
extern  volatile  uint32_t  GACMDL_REG_EMUL;
extern  volatile  uint32_t  GACMDH_REG_EMUL;
extern  volatile  uint32_t  GADEFCR_REG_EMUL[64];

#endif
/****************************************************************************   
*                                                                               
*       REGISTER: GASCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00000                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GASCR_REG__       0xC0C00000U
#else
#define GASCR_REG__       &GASCR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   GARESET	:1; 	 /* 0..0  bit(s) R/S */
  uint16_t   GAEN	:1; 	 /* 1..1  bit(s) R/W */
  uint16_t   	:6; 	 /* 2..7  bit(s) R */
  uint16_t   DISRA	:1; 	 /* 8..8  bit(s) R/W */ 
  uint16_t   	:7; 	 /* 9..31  bit(s) R */                    
} GASCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GASCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GASCR_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGASCR()     ((volatile GASCR_bit_view_st *)\
(GASCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GASCR()     ((volatile GASCR_byte_view_st *)\
(GASCR_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16GASCR()     ((volatile u16GASCR_halfword_view *)\
(GASCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGASCR_GARESET() (pst_bitGASCR() -> GARESET)
#define vSetGASCR_GARESET() (pst_bitGASCR() -> GARESET=(1))
#define biGetGASCR_GAEN() (pst_bitGASCR() -> GAEN)
#define vSetGASCR_GAEN(ParValue)  (pst_bitGASCR() -> GAEN=(ParValue))
#define biGetGASCR_DISRA() (pst_bitGASCR() -> DISRA)
#define vSetGASCR_DISRA(ParValue)  (pst_bitGASCR() -> DISRA=(ParValue))
            
/* L-struct byte access */
#define vSetGASCRL(ParValue) (pst_u8GASCR() -> u8L = (ParValue))
#define u8GetGASCRL() (pst_u8GASCR() -> u8L)
/* H-struct byte access */
#define vSetGASCRH(ParValue) (pst_u8GASCR() -> u8H = (ParValue))
#define u8GetGASCRH() (pst_u8GASCR() -> u8H)
            
/* Half-word access */ 
#define vSetGASCR(ParValue) (*pu16GASCR()  = (ParValue))
#define u16GetGASCR() (*pu16GASCR() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GACLAR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GACLAR_REG__       0xC0C00004U
#else
#define GACLAR_REG__       &GACLAR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   CSLA	:29; 	 /* 3..31  bit(s) R/W */                    
} GACLAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GACLAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GACLAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GACLAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGACLAR()     ((volatile GACLAR_bit_view_st *)\
(GACLAR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GACLAR()     ((volatile GACLAR_byte_view_st *)\
(GACLAR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GACLAR()     ((volatile GACLAR_halfword_view_st *)\
(GACLAR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GACLAR()     ((volatile u32GACLAR_word_view *)\
(GACLAR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGACLAR_CSLA() (pst_bitGACLAR() -> CSLA)
#define vSetGACLAR_CSLA(ParValue)  (pst_bitGACLAR() -> CSLA=(ParValue))
            
/* LL-struct byte access */
#define vSetGACLARLL(ParValue) (pst_u8GACLAR() -> u8LL = (ParValue))
#define u8GetGACLARLL() (pst_u8GACLAR() -> u8LL)
/* LH-struct byte access */
#define vSetGACLARLH(ParValue) (pst_u8GACLAR() -> u8LH = (ParValue))
#define u8GetGACLARLH() (pst_u8GACLAR() -> u8LH)
/* HL-struct byte access */
#define vSetGACLARHL(ParValue) (pst_u8GACLAR() -> u8HL = (ParValue))
#define u8GetGACLARHL() (pst_u8GACLAR() -> u8HL)
/* HH-struct byte access */
#define vSetGACLARHH(ParValue) (pst_u8GACLAR() -> u8HH = (ParValue))
#define u8GetGACLARHH() (pst_u8GACLAR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGACLARL(ParValue) (pst_u16GACLAR() -> u16L = (ParValue))
#define u16GetGACLARL() (pst_u16GACLAR() -> u16L)
#define vSetGACLARH(ParValue) (pst_u16GACLAR() -> u16H = (ParValue))
#define u16GetGACLARH() (pst_u16GACLAR() -> u16H)
            
/* Word access */
#define vSetGACLAR(ParValue)  (*pu32GACLAR() = (ParValue))
#define u32GetGACLAR()  (*pu32GACLAR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GASR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00008                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GASR_REG__       0xC0C00008U
#else
#define GASR_REG__       &GASR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   BUSY	:1; 	 /* 0..0  bit(s) R */
  uint8_t   	:1; 	 /* 1..1  bit(s) R */
  uint8_t   CSCEF	:1; 	 /* 2..2  bit(s) R */
  uint8_t   CSLEF	:1; 	 /* 3..3  bit(s) R */ 
  uint8_t   	:4; 	 /* 4..31  bit(s) R */                    
} GASR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GASR_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGASR()     ((volatile GASR_bit_view_st *)\
(GASR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8GASR()     ((volatile u8GASR_byte_view *)\
(GASR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGASR_BUSY() (pst_bitGASR() -> BUSY)            
#define biGetGASR_CSCEF() (pst_bitGASR() -> CSCEF)            
#define biGetGASR_CSLEF() (pst_bitGASR() -> CSLEF)
            
/* byte access */
#define u8GetGASR() (*pu8GASR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAICR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0000C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAICR_REG__       0xC0C0000CU
#else
#define GAICR_REG__       &GAICR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GACENDI	:1; 	 /* 0..0  bit(s) R/W1C */
  uint32_t   	:1; 	 /* 1..1  bit(s) R */
  uint32_t   CSCEI	:1; 	 /* 2..2  bit(s) R/W1C */
  uint32_t   CSLEI	:1; 	 /* 3..3  bit(s) R/W1C */
  uint32_t   GAWBWI	:1; 	 /* 4..4  bit(s) R/W1C */
  uint32_t   GAWBRI	:1; 	 /* 5..5  bit(s) R/W1C */
  uint32_t   GACBI	:1; 	 /* 6..6  bit(s) R/W1C */
  uint32_t   GARBI	:1; 	 /* 7..7  bit(s) R/W1C */ 
  uint32_t   CSLUI	:24; 	 /* 8..31  bit(s) R/W1C */                    
} GAICR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAICR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAICR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAICR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAICR()     ((volatile GAICR_bit_view_st *)\
(GAICR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAICR()     ((volatile GAICR_byte_view_st *)\
(GAICR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAICR()     ((volatile GAICR_halfword_view_st *)\
(GAICR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAICR()     ((volatile u32GAICR_word_view *)\
(GAICR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGAICR_GACENDI() (pst_bitGAICR() -> GACENDI)
#define vClrGAICR_GACENDI() (pst_bitGAICR() -> GACENDI = (1))
#define biGetGAICR_CSCEI() (pst_bitGAICR() -> CSCEI)
#define vClrGAICR_CSCEI() (pst_bitGAICR() -> CSCEI = (1))
#define biGetGAICR_CSLEI() (pst_bitGAICR() -> CSLEI)
#define vClrGAICR_CSLEI() (pst_bitGAICR() -> CSLEI = (1))
#define biGetGAICR_GAWBWI() (pst_bitGAICR() -> GAWBWI)
#define vClrGAICR_GAWBWI() (pst_bitGAICR() -> GAWBWI = (1))
#define biGetGAICR_GAWBRI() (pst_bitGAICR() -> GAWBRI)
#define vClrGAICR_GAWBRI() (pst_bitGAICR() -> GAWBRI = (1))
#define biGetGAICR_GACBI() (pst_bitGAICR() -> GACBI)
#define vClrGAICR_GACBI() (pst_bitGAICR() -> GACBI = (1))
#define biGetGAICR_GARBI() (pst_bitGAICR() -> GARBI)
#define vClrGAICR_GARBI() (pst_bitGAICR() -> GARBI = (1))

#define biGetGAICR_CSLUI() (pst_bitGAICR() -> CSLUI)
/*---------------------------------------------------------------------------*/
/* SRA: Clr funnction can be applied for each interrupt 0..23: */
#define vClrGAICR_CSLUI(BitNo) (pst_bitGAICR() -> CSLUI = ( (0x000001 << (BitNo)) & 0xFFFFFFU) )
/* SRA: Clr funnction for multiple bits can be applied for multiple interrupt 0..23: */
#define vClrMultiGAICR_CSLUI(Mask) (pst_bitGAICR() -> CSLUI = ((Mask) & 0xFFFFFFU))
/*---------------------------------------------------------------------------*/
/* LL-struct byte access */
#define vSetGAICRLL(ParValue) (pst_u8GAICR() -> u8LL = (ParValue))
#define u8GetGAICRLL() (pst_u8GAICR() -> u8LL)
/* LH-struct byte access */
#define vSetGAICRLH(ParValue) (pst_u8GAICR() -> u8LH = (ParValue))
#define u8GetGAICRLH() (pst_u8GAICR() -> u8LH)
/* HL-struct byte access */
#define vSetGAICRHL(ParValue) (pst_u8GAICR() -> u8HL = (ParValue))
#define u8GetGAICRHL() (pst_u8GAICR() -> u8HL)
/* HH-struct byte access */
#define vSetGAICRHH(ParValue) (pst_u8GAICR() -> u8HH = (ParValue))
#define u8GetGAICRHH() (pst_u8GAICR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGAICRL(ParValue) (pst_u16GAICR() -> u16L = (ParValue))
#define u16GetGAICRL() (pst_u16GAICR() -> u16L)
#define vSetGAICRH(ParValue) (pst_u16GAICR() -> u16H = (ParValue))
#define u16GetGAICRH() (pst_u16GAICR() -> u16H)
            
/* Word access */
#define vSetGAICR(ParValue)  (*pu32GAICR() = (ParValue))
#define u32GetGAICR()  (*pu32GAICR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAIMR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAIMR_REG__       0xC0C00010U
#else
#define GAIMR_REG__       &GAIMR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   GACENDIM	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   	:1; 	 /* 1..1  bit(s) R */
  uint32_t   CSCEIM	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   CSLEIM	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   GAWBWIM	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   GAWBRIM	:1; 	 /* 5..5  bit(s) R/W */
  uint32_t   GACBIM	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   GARBIM	:1; 	 /* 7..7  bit(s) R/W */ 
  uint32_t   CSLUIM	:24; 	 /* 8..31  bit(s) R/W */                    
} GAIMR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAIMR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAIMR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAIMR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAIMR()     ((volatile GAIMR_bit_view_st *)\
(GAIMR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAIMR()     ((volatile GAIMR_byte_view_st *)\
(GAIMR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAIMR()     ((volatile GAIMR_halfword_view_st *)\
(GAIMR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAIMR()     ((volatile u32GAIMR_word_view *)\
(GAIMR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGAIMR_GACENDIM() (pst_bitGAIMR() -> GACENDIM)
#define vSetGAIMR_GACENDIM(ParValue)  (pst_bitGAIMR() -> GACENDIM=(ParValue))
#define biGetGAIMR_CSCEIM() (pst_bitGAIMR() -> CSCEIM)
#define vSetGAIMR_CSCEIM(ParValue)  (pst_bitGAIMR() -> CSCEIM=(ParValue))
#define biGetGAIMR_CSLEIM() (pst_bitGAIMR() -> CSLEIM)
#define vSetGAIMR_CSLEIM(ParValue)  (pst_bitGAIMR() -> CSLEIM=(ParValue))
#define biGetGAIMR_GAWBWIM() (pst_bitGAIMR() -> GAWBWIM)
#define vSetGAIMR_GAWBWIM(ParValue)  (pst_bitGAIMR() -> GAWBWIM=(ParValue))
#define biGetGAIMR_GAWBRIM() (pst_bitGAIMR() -> GAWBRIM)
#define vSetGAIMR_GAWBRIM(ParValue)  (pst_bitGAIMR() -> GAWBRIM=(ParValue))
#define biGetGAIMR_GACBIM() (pst_bitGAIMR() -> GACBIM)
#define vSetGAIMR_GACBIM(ParValue)  (pst_bitGAIMR() -> GACBIM=(ParValue))
#define biGetGAIMR_GARBIM() (pst_bitGAIMR() -> GARBIM)
#define vSetGAIMR_GARBIM(ParValue)  (pst_bitGAIMR() -> GARBIM=(ParValue))
#define biGetGAIMR_CSLUIM() (pst_bitGAIMR() -> CSLUIM)
#define vSetGAIMR_CSLUIM(ParValue)  (pst_bitGAIMR() -> CSLUIM=(ParValue))
            
/* LL-struct byte access */
#define vSetGAIMRLL(ParValue) (pst_u8GAIMR() -> u8LL = (ParValue))
#define u8GetGAIMRLL() (pst_u8GAIMR() -> u8LL)
/* LH-struct byte access */
#define vSetGAIMRLH(ParValue) (pst_u8GAIMR() -> u8LH = (ParValue))
#define u8GetGAIMRLH() (pst_u8GAIMR() -> u8LH)
/* HL-struct byte access */
#define vSetGAIMRHL(ParValue) (pst_u8GAIMR() -> u8HL = (ParValue))
#define u8GetGAIMRHL() (pst_u8GAIMR() -> u8HL)
/* HH-struct byte access */
#define vSetGAIMRHH(ParValue) (pst_u8GAIMR() -> u8HH = (ParValue))
#define u8GetGAIMRHH() (pst_u8GAIMR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGAIMRL(ParValue) (pst_u16GAIMR() -> u16L = (ParValue))
#define u16GetGAIMRL() (pst_u16GAIMR() -> u16L)
#define vSetGAIMRH(ParValue) (pst_u16GAIMR() -> u16H = (ParValue))
#define u16GetGAIMRH() (pst_u16GAIMR() -> u16H)
            
/* Word access */
#define vSetGAIMR(ParValue)  (*pu32GAIMR() = (ParValue))
#define u32GetGAIMR()  (*pu32GAIMR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GADR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00014                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GADR_REG__       0xC0C00014U
#else
#define GADR_REG__       &GADR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   GAD	:16; 	 /* 0..15  bit(s) R/W */                    
} GADR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GADR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GADR_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGADR()     ((volatile GADR_bit_view_st *)\
(GADR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GADR()     ((volatile GADR_byte_view_st *)\
(GADR_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16GADR()     ((volatile u16GADR_halfword_view *)\
(GADR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGADR_GAD() (pst_bitGADR() -> GAD)
#define vSetGADR_GAD(ParValue)  (pst_bitGADR() -> GAD=(ParValue))
            
/* L-struct byte access */
#define vSetGADRL(ParValue) (pst_u8GADR() -> u8L = (ParValue))
#define u8GetGADRL() (pst_u8GADR() -> u8L)
/* H-struct byte access */
#define vSetGADRH(ParValue) (pst_u8GADR() -> u8H = (ParValue))
#define u8GetGADRH() (pst_u8GADR() -> u8H)
            
/* Half-word access */ 
#define vSetGADR(ParValue) (*pu16GADR()  = (ParValue))
#define u16GetGADR() (*pu16GADR() )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GARBBEAR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GARBBEAR_REG__       0xC0C00020U
#else
#define GARBBEAR_REG__       &GARBBEAR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   RBA	:29; 	 /* 3..31  bit(s) R */                    
} GARBBEAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GARBBEAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GARBBEAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GARBBEAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGARBBEAR()     ((volatile GARBBEAR_bit_view_st *)\
(GARBBEAR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GARBBEAR()     ((volatile GARBBEAR_byte_view_st *)\
(GARBBEAR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GARBBEAR()     ((volatile GARBBEAR_halfword_view_st *)\
(GARBBEAR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GARBBEAR()     ((volatile u32GARBBEAR_word_view *)\
(GARBBEAR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGARBBEAR_RBA() (pst_bitGARBBEAR() -> RBA)
            
/* LL-struct byte access */
#define u8GetGARBBEARLL() (pst_u8GARBBEAR() -> u8LL)
/* LH-struct byte access */
#define u8GetGARBBEARLH() (pst_u8GARBBEAR() -> u8LH)
/* HL-struct byte access */
#define u8GetGARBBEARHL() (pst_u8GARBBEAR() -> u8HL)
/* HH-struct byte access */
#define u8GetGARBBEARHH() (pst_u8GARBBEAR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGARBBEARL() (pst_u16GARBBEAR() -> u16L)
#define u16GetGARBBEARH() (pst_u16GARBBEAR() -> u16H)
            
/* Word access */
#define u32GetGARBBEAR()  (*pu32GARBBEAR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GARBBECR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00024                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GARBBECR_REG__       0xC0C00024U
#else
#define GARBBECR_REG__       &GARBBECR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WR	:1; 	 /* 0..0  bit(s) R */
  uint32_t   BTYPE	:1; 	 /* 1..1  bit(s) R */
  uint32_t   BSIZE	:3; 	 /* 2..4  bit(s) R */
  uint32_t   RTYPE	:2; 	 /* 5..6  bit(s) R */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   BEN	:8; 	 /* 8..15  bit(s) R */
  uint32_t   ID	:4; 	 /* 16..19  bit(s) R */
  uint32_t   LEN	:4; 	 /* 20..23  bit(s) R */ 
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} GARBBECR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GARBBECR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GARBBECR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GARBBECR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGARBBECR()     ((volatile GARBBECR_bit_view_st *)\
(GARBBECR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GARBBECR()     ((volatile GARBBECR_byte_view_st *)\
(GARBBECR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GARBBECR()     ((volatile GARBBECR_halfword_view_st *)\
(GARBBECR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GARBBECR()     ((volatile u32GARBBECR_word_view *)\
(GARBBECR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGARBBECR_WR() (pst_bitGARBBECR() -> WR)            
#define biGetGARBBECR_BTYPE() (pst_bitGARBBECR() -> BTYPE)            
#define biGetGARBBECR_BSIZE() (pst_bitGARBBECR() -> BSIZE)            
#define biGetGARBBECR_RTYPE() (pst_bitGARBBECR() -> RTYPE)            
#define biGetGARBBECR_BEN() (pst_bitGARBBECR() -> BEN)            
#define biGetGARBBECR_ID() (pst_bitGARBBECR() -> ID)            
#define biGetGARBBECR_LEN() (pst_bitGARBBECR() -> LEN)
            
/* LL-struct byte access */
#define u8GetGARBBECRLL() (pst_u8GARBBECR() -> u8LL)
/* LH-struct byte access */
#define u8GetGARBBECRLH() (pst_u8GARBBECR() -> u8LH)
/* HL-struct byte access */
#define u8GetGARBBECRHL() (pst_u8GARBBECR() -> u8HL)
/* HH-struct byte access */
#define u8GetGARBBECRHH() (pst_u8GARBBECR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGARBBECRL() (pst_u16GARBBECR() -> u16L)
#define u16GetGARBBECRH() (pst_u16GARBBECR() -> u16H)
            
/* Word access */
#define u32GetGARBBECR()  (*pu32GARBBECR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GACBBEAR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00028                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GACBBEAR_REG__       0xC0C00028U
#else
#define GACBBEAR_REG__       &GACBBEAR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   CBA	:29; 	 /* 3..31  bit(s) R */                    
} GACBBEAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GACBBEAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GACBBEAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GACBBEAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGACBBEAR()     ((volatile GACBBEAR_bit_view_st *)\
(GACBBEAR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GACBBEAR()     ((volatile GACBBEAR_byte_view_st *)\
(GACBBEAR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GACBBEAR()     ((volatile GACBBEAR_halfword_view_st *)\
(GACBBEAR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GACBBEAR()     ((volatile u32GACBBEAR_word_view *)\
(GACBBEAR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGACBBEAR_CBA() (pst_bitGACBBEAR() -> CBA)
            
/* LL-struct byte access */
#define u8GetGACBBEARLL() (pst_u8GACBBEAR() -> u8LL)
/* LH-struct byte access */
#define u8GetGACBBEARLH() (pst_u8GACBBEAR() -> u8LH)
/* HL-struct byte access */
#define u8GetGACBBEARHL() (pst_u8GACBBEAR() -> u8HL)
/* HH-struct byte access */
#define u8GetGACBBEARHH() (pst_u8GACBBEAR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGACBBEARL() (pst_u16GACBBEAR() -> u16L)
#define u16GetGACBBEARH() (pst_u16GACBBEAR() -> u16H)
            
/* Word access */
#define u32GetGACBBEAR()  (*pu32GACBBEAR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GACBBECR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0002C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GACBBECR_REG__       0xC0C0002CU
#else
#define GACBBECR_REG__       &GACBBECR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WR	:1; 	 /* 0..0  bit(s) R */
  uint32_t   BTYPE	:1; 	 /* 1..1  bit(s) R */
  uint32_t   BSIZE	:3; 	 /* 2..4  bit(s) R */
  uint32_t   RTYPE	:2; 	 /* 5..6  bit(s) R */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   BEN	:8; 	 /* 8..15  bit(s) R */
  uint32_t   ID	:4; 	 /* 16..19  bit(s) R */
  uint32_t   LEN	:4; 	 /* 20..23  bit(s) R */ 
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} GACBBECR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GACBBECR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GACBBECR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GACBBECR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGACBBECR()     ((volatile GACBBECR_bit_view_st *)\
(GACBBECR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GACBBECR()     ((volatile GACBBECR_byte_view_st *)\
(GACBBECR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GACBBECR()     ((volatile GACBBECR_halfword_view_st *)\
(GACBBECR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GACBBECR()     ((volatile u32GACBBECR_word_view *)\
(GACBBECR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGACBBECR_WR() (pst_bitGACBBECR() -> WR)            
#define biGetGACBBECR_BTYPE() (pst_bitGACBBECR() -> BTYPE)            
#define biGetGACBBECR_BSIZE() (pst_bitGACBBECR() -> BSIZE)            
#define biGetGACBBECR_RTYPE() (pst_bitGACBBECR() -> RTYPE)            
#define biGetGACBBECR_BEN() (pst_bitGACBBECR() -> BEN)            
#define biGetGACBBECR_ID() (pst_bitGACBBECR() -> ID)            
#define biGetGACBBECR_LEN() (pst_bitGACBBECR() -> LEN)
            
/* LL-struct byte access */
#define u8GetGACBBECRLL() (pst_u8GACBBECR() -> u8LL)
/* LH-struct byte access */
#define u8GetGACBBECRLH() (pst_u8GACBBECR() -> u8LH)
/* HL-struct byte access */
#define u8GetGACBBECRHL() (pst_u8GACBBECR() -> u8HL)
/* HH-struct byte access */
#define u8GetGACBBECRHH() (pst_u8GACBBECR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGACBBECRL() (pst_u16GACBBECR() -> u16L)
#define u16GetGACBBECRH() (pst_u16GACBBECR() -> u16H)
            
/* Word access */
#define u32GetGACBBECR()  (*pu32GACBBECR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAWBRBEAR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00030                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAWBRBEAR_REG__       0xC0C00030U
#else
#define GAWBRBEAR_REG__       &GAWBRBEAR_REG_EMUL
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   WBRA	:29; 	 /* 3..31  bit(s) R */                    
} GAWBRBEAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAWBRBEAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAWBRBEAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAWBRBEAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAWBRBEAR()     ((volatile GAWBRBEAR_bit_view_st *)\
(GAWBRBEAR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAWBRBEAR()     ((volatile GAWBRBEAR_byte_view_st *)\
(GAWBRBEAR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAWBRBEAR()     ((volatile GAWBRBEAR_halfword_view_st *)\
(GAWBRBEAR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAWBRBEAR()     ((volatile u32GAWBRBEAR_word_view *)\
(GAWBRBEAR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGAWBRBEAR_WBRA() (pst_bitGAWBRBEAR() -> WBRA)
            
/* LL-struct byte access */
#define u8GetGAWBRBEARLL() (pst_u8GAWBRBEAR() -> u8LL)
/* LH-struct byte access */
#define u8GetGAWBRBEARLH() (pst_u8GAWBRBEAR() -> u8LH)
/* HL-struct byte access */
#define u8GetGAWBRBEARHL() (pst_u8GAWBRBEAR() -> u8HL)
/* HH-struct byte access */
#define u8GetGAWBRBEARHH() (pst_u8GAWBRBEAR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGAWBRBEARL() (pst_u16GAWBRBEAR() -> u16L)
#define u16GetGAWBRBEARH() (pst_u16GAWBRBEAR() -> u16H)
            
/* Word access */
#define u32GetGAWBRBEAR()  (*pu32GAWBRBEAR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAWBRBECR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00034                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAWBRBECR_REG__       0xC0C00034U
#else
#define GAWBRBECR_REG__       &GAWBRBECR_REG_EMUL
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WR	:1; 	 /* 0..0  bit(s) R */
  uint32_t   BTYPE	:1; 	 /* 1..1  bit(s) R */
  uint32_t   BSIZE	:3; 	 /* 2..4  bit(s) R */
  uint32_t   RTYPE	:2; 	 /* 5..6  bit(s) R */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   BEN	:8; 	 /* 8..15  bit(s) R */
  uint32_t   ID	:4; 	 /* 16..19  bit(s) R */
  uint32_t   LEN	:4; 	 /* 20..23  bit(s) R */ 
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} GAWBRBECR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAWBRBECR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAWBRBECR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAWBRBECR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAWBRBECR()     ((volatile GAWBRBECR_bit_view_st *)\
(GAWBRBECR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAWBRBECR()     ((volatile GAWBRBECR_byte_view_st *)\
(GAWBRBECR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAWBRBECR()     ((volatile GAWBRBECR_halfword_view_st *)\
(GAWBRBECR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAWBRBECR()     ((volatile u32GAWBRBECR_word_view *)\
(GAWBRBECR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGAWBRBECR_WR() (pst_bitGAWBRBECR() -> WR)            
#define biGetGAWBRBECR_BTYPE() (pst_bitGAWBRBECR() -> BTYPE)            
#define biGetGAWBRBECR_BSIZE() (pst_bitGAWBRBECR() -> BSIZE)            
#define biGetGAWBRBECR_RTYPE() (pst_bitGAWBRBECR() -> RTYPE)            
#define biGetGAWBRBECR_BEN() (pst_bitGAWBRBECR() -> BEN)            
#define biGetGAWBRBECR_ID() (pst_bitGAWBRBECR() -> ID)            
#define biGetGAWBRBECR_LEN() (pst_bitGAWBRBECR() -> LEN)
            
/* LL-struct byte access */
#define u8GetGAWBRBECRLL() (pst_u8GAWBRBECR() -> u8LL)
/* LH-struct byte access */
#define u8GetGAWBRBECRLH() (pst_u8GAWBRBECR() -> u8LH)
/* HL-struct byte access */
#define u8GetGAWBRBECRHL() (pst_u8GAWBRBECR() -> u8HL)
/* HH-struct byte access */
#define u8GetGAWBRBECRHH() (pst_u8GAWBRBECR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGAWBRBECRL() (pst_u16GAWBRBECR() -> u16L)
#define u16GetGAWBRBECRH() (pst_u16GAWBRBECR() -> u16H)
            
/* Word access */
#define u32GetGAWBRBECR()  (*pu32GAWBRBECR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAWBWBEAR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00038                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAWBWBEAR_REG__       0xC0C00038U
#else
#define GAWBWBEAR_REG__       &GAWBWBEAR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   WBWA	:29; 	 /* 3..31  bit(s) R */                    
} GAWBWBEAR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAWBWBEAR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAWBWBEAR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAWBWBEAR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAWBWBEAR()     ((volatile GAWBWBEAR_bit_view_st *)\
(GAWBWBEAR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAWBWBEAR()     ((volatile GAWBWBEAR_byte_view_st *)\
(GAWBWBEAR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAWBWBEAR()     ((volatile GAWBWBEAR_halfword_view_st *)\
(GAWBWBEAR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAWBWBEAR()     ((volatile u32GAWBWBEAR_word_view *)\
(GAWBWBEAR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGAWBWBEAR_WBWA() (pst_bitGAWBWBEAR() -> WBWA)
            
/* LL-struct byte access */
#define u8GetGAWBWBEARLL() (pst_u8GAWBWBEAR() -> u8LL)
/* LH-struct byte access */
#define u8GetGAWBWBEARLH() (pst_u8GAWBWBEAR() -> u8LH)
/* HL-struct byte access */
#define u8GetGAWBWBEARHL() (pst_u8GAWBWBEAR() -> u8HL)
/* HH-struct byte access */
#define u8GetGAWBWBEARHH() (pst_u8GAWBWBEAR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGAWBWBEARL() (pst_u16GAWBWBEAR() -> u16L)
#define u16GetGAWBWBEARH() (pst_u16GAWBWBEAR() -> u16H)
            
/* Word access */
#define u32GetGAWBWBEAR()  (*pu32GAWBWBEAR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAWBWBECR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0003C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAWBWBECR_REG__       0xC0C0003CU
#else
#define GAWBWBECR_REG__       &GAWBWBECR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   WR	:1; 	 /* 0..0  bit(s) R */
  uint32_t   BTYPE	:1; 	 /* 1..1  bit(s) R */
  uint32_t   BSIZE	:3; 	 /* 2..4  bit(s) R */
  uint32_t   RTYPE	:2; 	 /* 5..6  bit(s) R */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   BEN	:8; 	 /* 8..15  bit(s) R */
  uint32_t   ID	:4; 	 /* 16..19  bit(s) R */
  uint32_t   LEN	:4; 	 /* 20..23  bit(s) R */ 
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} GAWBWBECR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAWBWBECR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAWBWBECR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAWBWBECR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAWBWBECR()     ((volatile GAWBWBECR_bit_view_st *)\
(GAWBWBECR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAWBWBECR()     ((volatile GAWBWBECR_byte_view_st *)\
(GAWBWBECR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAWBWBECR()     ((volatile GAWBWBECR_halfword_view_st *)\
(GAWBWBECR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAWBWBECR()     ((volatile u32GAWBWBECR_word_view *)\
(GAWBWBECR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGAWBWBECR_WR() (pst_bitGAWBWBECR() -> WR)            
#define biGetGAWBWBECR_BTYPE() (pst_bitGAWBWBECR() -> BTYPE)            
#define biGetGAWBWBECR_BSIZE() (pst_bitGAWBWBECR() -> BSIZE)            
#define biGetGAWBWBECR_RTYPE() (pst_bitGAWBWBECR() -> RTYPE)            
#define biGetGAWBWBECR_BEN() (pst_bitGAWBWBECR() -> BEN)            
#define biGetGAWBWBECR_ID() (pst_bitGAWBWBECR() -> ID)            
#define biGetGAWBWBECR_LEN() (pst_bitGAWBWBECR() -> LEN)
            
/* LL-struct byte access */
#define u8GetGAWBWBECRLL() (pst_u8GAWBWBECR() -> u8LL)
/* LH-struct byte access */
#define u8GetGAWBWBECRLH() (pst_u8GAWBWBECR() -> u8LH)
/* HL-struct byte access */
#define u8GetGAWBWBECRHL() (pst_u8GAWBWBECR() -> u8HL)
/* HH-struct byte access */
#define u8GetGAWBWBECRHH() (pst_u8GAWBWBECR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGAWBWBECRL() (pst_u16GAWBWBECR() -> u16L)
#define u16GetGAWBWBECRH() (pst_u16GAWBWBECR() -> u16H)
            
/* Word access */
#define u32GetGAWBWBECR()  (*pu32GAWBWBECR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAMPR0LR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00040                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAMPR0LR_REG__       0xC0C00040U
#else
#define GAMPR0LR_REG__       &GAMPR0LR_REG_EMUL
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:12; 	 /* 0..11  bit(s) R */ 
  uint32_t   MPR0L	:20; 	 /* 12..31  bit(s) R/W */                    
} GAMPR0LR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAMPR0LR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAMPR0LR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAMPR0LR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAMPR0LR()     ((volatile GAMPR0LR_bit_view_st *)\
(GAMPR0LR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAMPR0LR()     ((volatile GAMPR0LR_byte_view_st *)\
(GAMPR0LR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAMPR0LR()     ((volatile GAMPR0LR_halfword_view_st *)\
(GAMPR0LR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAMPR0LR()     ((volatile u32GAMPR0LR_word_view *)\
(GAMPR0LR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGAMPR0LR_MPR0L() (pst_bitGAMPR0LR() -> MPR0L)
#define vSetGAMPR0LR_MPR0L(ParValue)  (pst_bitGAMPR0LR() -> MPR0L=(ParValue))
            
/* LL-struct byte access */
#define vSetGAMPR0LRLL(ParValue) (pst_u8GAMPR0LR() -> u8LL = (ParValue))
#define u8GetGAMPR0LRLL() (pst_u8GAMPR0LR() -> u8LL)
/* LH-struct byte access */
#define vSetGAMPR0LRLH(ParValue) (pst_u8GAMPR0LR() -> u8LH = (ParValue))
#define u8GetGAMPR0LRLH() (pst_u8GAMPR0LR() -> u8LH)
/* HL-struct byte access */
#define vSetGAMPR0LRHL(ParValue) (pst_u8GAMPR0LR() -> u8HL = (ParValue))
#define u8GetGAMPR0LRHL() (pst_u8GAMPR0LR() -> u8HL)
/* HH-struct byte access */
#define vSetGAMPR0LRHH(ParValue) (pst_u8GAMPR0LR() -> u8HH = (ParValue))
#define u8GetGAMPR0LRHH() (pst_u8GAMPR0LR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGAMPR0LRL(ParValue) (pst_u16GAMPR0LR() -> u16L = (ParValue))
#define u16GetGAMPR0LRL() (pst_u16GAMPR0LR() -> u16L)
#define vSetGAMPR0LRH(ParValue) (pst_u16GAMPR0LR() -> u16H = (ParValue))
#define u16GetGAMPR0LRH() (pst_u16GAMPR0LR() -> u16H)
            
/* Word access */
#define vSetGAMPR0LR(ParValue)  (*pu32GAMPR0LR() = (ParValue))
#define u32GetGAMPR0LR()  (*pu32GAMPR0LR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAMPR0HR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00044                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAMPR0HR_REG__       0xC0C00044U
#else
#define GAMPR0HR_REG__       &GAMPR0HR_REG_EMUL
#endif

/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:12; 	 /* 0..11  bit(s) R */ 
  uint32_t   MPR0H	:20; 	 /* 12..31  bit(s) R/W */                    
} GAMPR0HR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAMPR0HR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAMPR0HR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAMPR0HR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAMPR0HR()     ((volatile GAMPR0HR_bit_view_st *)\
(GAMPR0HR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAMPR0HR()     ((volatile GAMPR0HR_byte_view_st *)\
(GAMPR0HR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAMPR0HR()     ((volatile GAMPR0HR_halfword_view_st *)\
(GAMPR0HR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAMPR0HR()     ((volatile u32GAMPR0HR_word_view *)\
(GAMPR0HR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGAMPR0HR_MPR0H() (pst_bitGAMPR0HR() -> MPR0H)
#define vSetGAMPR0HR_MPR0H(ParValue)  (pst_bitGAMPR0HR() -> MPR0H=(ParValue))
            
/* LL-struct byte access */
#define vSetGAMPR0HRLL(ParValue) (pst_u8GAMPR0HR() -> u8LL = (ParValue))
#define u8GetGAMPR0HRLL() (pst_u8GAMPR0HR() -> u8LL)
/* LH-struct byte access */
#define vSetGAMPR0HRLH(ParValue) (pst_u8GAMPR0HR() -> u8LH = (ParValue))
#define u8GetGAMPR0HRLH() (pst_u8GAMPR0HR() -> u8LH)
/* HL-struct byte access */
#define vSetGAMPR0HRHL(ParValue) (pst_u8GAMPR0HR() -> u8HL = (ParValue))
#define u8GetGAMPR0HRHL() (pst_u8GAMPR0HR() -> u8HL)
/* HH-struct byte access */
#define vSetGAMPR0HRHH(ParValue) (pst_u8GAMPR0HR() -> u8HH = (ParValue))
#define u8GetGAMPR0HRHH() (pst_u8GAMPR0HR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGAMPR0HRL(ParValue) (pst_u16GAMPR0HR() -> u16L = (ParValue))
#define u16GetGAMPR0HRL() (pst_u16GAMPR0HR() -> u16L)
#define vSetGAMPR0HRH(ParValue) (pst_u16GAMPR0HR() -> u16H = (ParValue))
#define u16GetGAMPR0HRH() (pst_u16GAMPR0HR() -> u16H)
            
/* Word access */
#define vSetGAMPR0HR(ParValue)  (*pu32GAMPR0HR() = (ParValue))
#define u32GetGAMPR0HR()  (*pu32GAMPR0HR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAMPR1LR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00048                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAMPR1LR_REG__       0xC0C00048U
#else
#define GAMPR1LR_REG__       &GAMPR1LR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:12; 	 /* 0..11  bit(s) R */ 
  uint32_t   MPR1L	:20; 	 /* 12..31  bit(s) R/W */                    
} GAMPR1LR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAMPR1LR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAMPR1LR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAMPR1LR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAMPR1LR()     ((volatile GAMPR1LR_bit_view_st *)\
(GAMPR1LR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAMPR1LR()     ((volatile GAMPR1LR_byte_view_st *)\
(GAMPR1LR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAMPR1LR()     ((volatile GAMPR1LR_halfword_view_st *)\
(GAMPR1LR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAMPR1LR()     ((volatile u32GAMPR1LR_word_view *)\
(GAMPR1LR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGAMPR1LR_MPR1L() (pst_bitGAMPR1LR() -> MPR1L)
#define vSetGAMPR1LR_MPR1L(ParValue)  (pst_bitGAMPR1LR() -> MPR1L=(ParValue))
            
/* LL-struct byte access */
#define vSetGAMPR1LRLL(ParValue) (pst_u8GAMPR1LR() -> u8LL = (ParValue))
#define u8GetGAMPR1LRLL() (pst_u8GAMPR1LR() -> u8LL)
/* LH-struct byte access */
#define vSetGAMPR1LRLH(ParValue) (pst_u8GAMPR1LR() -> u8LH = (ParValue))
#define u8GetGAMPR1LRLH() (pst_u8GAMPR1LR() -> u8LH)
/* HL-struct byte access */
#define vSetGAMPR1LRHL(ParValue) (pst_u8GAMPR1LR() -> u8HL = (ParValue))
#define u8GetGAMPR1LRHL() (pst_u8GAMPR1LR() -> u8HL)
/* HH-struct byte access */
#define vSetGAMPR1LRHH(ParValue) (pst_u8GAMPR1LR() -> u8HH = (ParValue))
#define u8GetGAMPR1LRHH() (pst_u8GAMPR1LR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGAMPR1LRL(ParValue) (pst_u16GAMPR1LR() -> u16L = (ParValue))
#define u16GetGAMPR1LRL() (pst_u16GAMPR1LR() -> u16L)
#define vSetGAMPR1LRH(ParValue) (pst_u16GAMPR1LR() -> u16H = (ParValue))
#define u16GetGAMPR1LRH() (pst_u16GAMPR1LR() -> u16H)
            
/* Word access */
#define vSetGAMPR1LR(ParValue)  (*pu32GAMPR1LR() = (ParValue))
#define u32GetGAMPR1LR()  (*pu32GAMPR1LR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAMPR1HR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C0004C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAMPR1HR_REG__       0xC0C0004CU
#else
#define GAMPR1HR_REG__       &GAMPR1HR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:12; 	 /* 0..11  bit(s) R */ 
  uint32_t   MPR1H	:20; 	 /* 12..31  bit(s) R/W */                    
} GAMPR1HR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAMPR1HR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAMPR1HR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAMPR1HR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAMPR1HR()     ((volatile GAMPR1HR_bit_view_st *)\
(GAMPR1HR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAMPR1HR()     ((volatile GAMPR1HR_byte_view_st *)\
(GAMPR1HR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAMPR1HR()     ((volatile GAMPR1HR_halfword_view_st *)\
(GAMPR1HR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAMPR1HR()     ((volatile u32GAMPR1HR_word_view *)\
(GAMPR1HR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGAMPR1HR_MPR1H() (pst_bitGAMPR1HR() -> MPR1H)
#define vSetGAMPR1HR_MPR1H(ParValue)  (pst_bitGAMPR1HR() -> MPR1H=(ParValue))
            
/* LL-struct byte access */
#define vSetGAMPR1HRLL(ParValue) (pst_u8GAMPR1HR() -> u8LL = (ParValue))
#define u8GetGAMPR1HRLL() (pst_u8GAMPR1HR() -> u8LL)
/* LH-struct byte access */
#define vSetGAMPR1HRLH(ParValue) (pst_u8GAMPR1HR() -> u8LH = (ParValue))
#define u8GetGAMPR1HRLH() (pst_u8GAMPR1HR() -> u8LH)
/* HL-struct byte access */
#define vSetGAMPR1HRHL(ParValue) (pst_u8GAMPR1HR() -> u8HL = (ParValue))
#define u8GetGAMPR1HRHL() (pst_u8GAMPR1HR() -> u8HL)
/* HH-struct byte access */
#define vSetGAMPR1HRHH(ParValue) (pst_u8GAMPR1HR() -> u8HH = (ParValue))
#define u8GetGAMPR1HRHH() (pst_u8GAMPR1HR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGAMPR1HRL(ParValue) (pst_u16GAMPR1HR() -> u16L = (ParValue))
#define u16GetGAMPR1HRL() (pst_u16GAMPR1HR() -> u16L)
#define vSetGAMPR1HRH(ParValue) (pst_u16GAMPR1HR() -> u16H = (ParValue))
#define u16GetGAMPR1HRH() (pst_u16GAMPR1HR() -> u16H)
            
/* Word access */
#define vSetGAMPR1HR(ParValue)  (*pu32GAMPR1HR() = (ParValue))
#define u32GetGAMPR1HR()  (*pu32GAMPR1HR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAMPICR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00050                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAMPICR_REG__       0xC0C00050U
#else
#define GAMPICR_REG__       &GAMPICR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   GAMPI	:1; 	 /* 0..0  bit(s) R/W1C */
  uint8_t   GAMPCI	:1; 	 /* 1..1  bit(s) R/W1C */ 
  uint8_t   	:6; 	 /* 2..31  bit(s) R */                    
} GAMPICR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GAMPICR_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAMPICR()     ((volatile GAMPICR_bit_view_st *)\
(GAMPICR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8GAMPICR()     ((volatile u8GAMPICR_byte_view *)\
(GAMPICR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGAMPICR_GAMPI() (pst_bitGAMPICR() -> GAMPI)
#define vClrGAMPICR_GAMPI() (pst_bitGAMPICR() -> GAMPI = (1))
#define biGetGAMPICR_GAMPCI() (pst_bitGAMPICR() -> GAMPCI)
#define vClrGAMPICR_GAMPCI() (pst_bitGAMPICR() -> GAMPCI = (1))
            
/* byte access */
#define vSetGAMPICR(ParValue) (*pu8GAMPICR() = (ParValue))
#define u8GetGAMPICR() (*pu8GAMPICR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAMPIMR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00054                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAMPIMR_REG__       0xC0C00054U
#else
#define GAMPIMR_REG__       &GAMPIMR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   GAMPIM	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   GAMPCIM	:1; 	 /* 1..1  bit(s) R/W */ 
  uint8_t   	:6; 	 /* 2..31  bit(s) R */                    
} GAMPIMR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GAMPIMR_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAMPIMR()     ((volatile GAMPIMR_bit_view_st *)\
(GAMPIMR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8GAMPIMR()     ((volatile u8GAMPIMR_byte_view *)\
(GAMPIMR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGAMPIMR_GAMPIM() (pst_bitGAMPIMR() -> GAMPIM)
#define vSetGAMPIMR_GAMPIM(ParValue)  (pst_bitGAMPIMR() -> GAMPIM=(ParValue))
#define biGetGAMPIMR_GAMPCIM() (pst_bitGAMPIMR() -> GAMPCIM)
#define vSetGAMPIMR_GAMPCIM(ParValue)  (pst_bitGAMPIMR() -> GAMPCIM=(ParValue))
            
/* byte access */
#define vSetGAMPIMR(ParValue) (*pu8GAMPIMR() = (ParValue))
#define u8GetGAMPIMR() (*pu8GAMPIMR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAMPACR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00058                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAMPACR_REG__       0xC0C00058U
#else
#define GAMPACR_REG__       &GAMPACR_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   	:3; 	 /* 0..2  bit(s) R */ 
  uint32_t   MPVA	:29; 	 /* 3..31  bit(s) R */                    
} GAMPACR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GAMPACR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GAMPACR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GAMPACR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGAMPACR()     ((volatile GAMPACR_bit_view_st *)\
(GAMPACR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GAMPACR()     ((volatile GAMPACR_byte_view_st *)\
(GAMPACR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GAMPACR()     ((volatile GAMPACR_halfword_view_st *)\
(GAMPACR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32GAMPACR()     ((volatile u32GAMPACR_word_view *)\
(GAMPACR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGAMPACR_MPVA() (pst_bitGAMPACR() -> MPVA)
            
/* LL-struct byte access */
#define u8GetGAMPACRLL() (pst_u8GAMPACR() -> u8LL)
/* LH-struct byte access */
#define u8GetGAMPACRLH() (pst_u8GAMPACR() -> u8LH)
/* HL-struct byte access */
#define u8GetGAMPACRHL() (pst_u8GAMPACR() -> u8HL)
/* HH-struct byte access */
#define u8GetGAMPACRHH() (pst_u8GAMPACR() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetGAMPACRL() (pst_u16GAMPACR() -> u16L)
#define u16GetGAMPACRH() (pst_u16GAMPACR() -> u16H)
            
/* Word access */
#define u32GetGAMPACR()  (*pu32GAMPACR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GAGPR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00080                             
*       ACCESS  : 32,                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GAGPR_REG__       0xC0C00080U
#else
#define GAGPR_REG__       &GAGPR_REG_EMUL[0]
#endif
     
/************************       STRUCTURES        ***************************/
        
/* WORD View */
typedef uint32_t u32GAGPR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to WORD  */ 
#define pu32GAGPR(ch)     ((volatile u32GAGPR_word_view *)\
(GAGPR_REG__  + ((uint16_t)(ch) * 0x04U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
            
/* Word access */
#define vSetGAGPR(ch,ParValue)  (*pu32GAGPR(ch) = (ParValue))
#define u32GetGAGPR(ch)  (*pu32GAGPR(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GACMDL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00100                             
*       ACCESS  : 32,                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GACMDL_REG__       0xC0C00100U
#else
#define GACMDL_REG__       &GACMDL_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
        
/* WORD View */
typedef uint32_t u32GACMDL_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to WORD  */ 
#define pu32GACMDL()     ((volatile u32GACMDL_word_view *)\
(GACMDL_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
            
/* Word access */
#define vSetGACMDL(ParValue)  (*pu32GACMDL() = (ParValue))
#define u32GetGACMDL()  (*pu32GACMDL() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GACMDH                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00104                             
*       ACCESS  : 32,                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GACMDH_REG__       0xC0C00104U
#else
#define GACMDH_REG__       &GACMDH_REG_EMUL
#endif
     
/************************       STRUCTURES        ***************************/
        
/* WORD View */
typedef uint32_t u32GACMDH_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to WORD  */ 
#define pu32GACMDH()     ((volatile u32GACMDH_word_view *)\
(GACMDH_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
            
/* Word access */
#define vSetGACMDH(ParValue)  (*pu32GACMDH() = (ParValue))
#define u32GetGACMDH()  (*pu32GACMDH() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GADEFCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0C00200                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#ifndef HW_EMULATION_GA 
#define GADEFCR_REG__       0xC0C00200U
#else
#define GADEFCR_REG__       &GADEFCR_REG_EMUL[0]
#endif
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   FC3	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   FC2	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   FC1	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   FC0	:8; 	 /* 24..31  bit(s) R/W */                    
} GADEFCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GADEFCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GADEFCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GADEFCR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGADEFCR(ch)     ((volatile GADEFCR_bit_view_st *)\
(GADEFCR_REG__  + ((uint16_t)(ch) * 0x04U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8GADEFCR(ch)     ((volatile GADEFCR_byte_view_st *)\
(GADEFCR_REG__  + ((uint16_t)(ch) * 0x04U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GADEFCR(ch)     ((volatile GADEFCR_halfword_view_st *)\
(GADEFCR_REG__  + ((uint16_t)(ch) * 0x04U)))
            
/* Pointer to WORD  */ 
#define pu32GADEFCR(ch)     ((volatile u32GADEFCR_word_view *)\
(GADEFCR_REG__  + ((uint16_t)(ch) * 0x04U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGADEFCR_FC3(ch) (pst_bitGADEFCR(ch) -> FC3)
#define vSetGADEFCR_FC3(ch,ParValue)  (pst_bitGADEFCR(ch) -> FC3=(ParValue))
#define biGetGADEFCR_FC2(ch) (pst_bitGADEFCR(ch) -> FC2)
#define vSetGADEFCR_FC2(ch,ParValue)  (pst_bitGADEFCR(ch) -> FC2=(ParValue))
#define biGetGADEFCR_FC1(ch) (pst_bitGADEFCR(ch) -> FC1)
#define vSetGADEFCR_FC1(ch,ParValue)  (pst_bitGADEFCR(ch) -> FC1=(ParValue))
#define biGetGADEFCR_FC0(ch) (pst_bitGADEFCR(ch) -> FC0)
#define vSetGADEFCR_FC0(ch,ParValue)  (pst_bitGADEFCR(ch) -> FC0=(ParValue))
            
/* LL-struct byte access */
#define vSetGADEFCRLL(ch,ParValue) (pst_u8GADEFCR(ch) -> u8LL = (ParValue))
#define u8GetGADEFCRLL(ch) (pst_u8GADEFCR(ch) -> u8LL)
/* LH-struct byte access */
#define vSetGADEFCRLH(ch,ParValue) (pst_u8GADEFCR(ch) -> u8LH = (ParValue))
#define u8GetGADEFCRLH(ch) (pst_u8GADEFCR(ch) -> u8LH)
/* HL-struct byte access */
#define vSetGADEFCRHL(ch,ParValue) (pst_u8GADEFCR(ch) -> u8HL = (ParValue))
#define u8GetGADEFCRHL(ch) (pst_u8GADEFCR(ch) -> u8HL)
/* HH-struct byte access */
#define vSetGADEFCRHH(ch,ParValue) (pst_u8GADEFCR(ch) -> u8HH = (ParValue))
#define u8GetGADEFCRHH(ch) (pst_u8GADEFCR(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetGADEFCRL(ch,ParValue) (pst_u16GADEFCR(ch) -> u16L = (ParValue))
#define u16GetGADEFCRL(ch) (pst_u16GADEFCR(ch) -> u16L)
#define vSetGADEFCRH(ch,ParValue) (pst_u16GADEFCR(ch) -> u16H = (ParValue))
#define u16GetGADEFCRH(ch) (pst_u16GADEFCR(ch) -> u16H)
            
/* Word access */
#define vSetGADEFCR(ch,ParValue)  (*pu32GADEFCR(ch) = (ParValue))
#define u32GetGADEFCR(ch)  (*pu32GADEFCR(ch) )


/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

#endif /* GAIO_H */  

/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: ga_io.c
**  $Revision: 1.12 $
**  $Date: 2015/05/04 09:07:16 $
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

