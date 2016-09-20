
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : ADCC 
/  Date of creation (y-m-d:time): 2015-02-19+01:00  :  13:32:47.742+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.11 $ 
/  Excel Sheet ver.             : vv1.4
/  Excel Sheet date             : 2015-Feb-19
/  Excel Sheet author           : BEL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : ADC low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : ADC
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.11 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef ADCCIO_H
#define ADCCIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */ 

/*********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 230    /* MISRA 2004 Rule 6.4 */
#endif /* defined(__GHS__) || defined(__ghs__) */

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_ADC_IO_H_REVISION     "$Revision: 1.11 $"
#define LLDD_ADC_IO_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADCMOD                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0410000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADCMOD_REG__       0xC0410000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SCAN	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   ADCH	:4; 	 /* 1..4  bit(s) R/W */
  uint32_t   REP	:1; 	 /* 5..5  bit(s) R/W */
  uint32_t   DME	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   ITM	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   TRGE	:1; 	 /* 8..8  bit(s) R/W */
  uint32_t   TSEL	:2; 	 /* 9..10  bit(s) R/W */
  uint32_t   	:5; 	 /* 11..15  bit(s) R */
  uint32_t   ADC_RT	:1; 	 /* 16..16  bit(s) R/W */ 
  uint32_t   	:15; 	 /* 17..31  bit(s) R */                    
} ADCMOD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADCMOD_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADCMOD_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADCMOD_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADCMOD()     ((volatile ADCMOD_bit_view_st *)\
(ADCMOD_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADCMOD()     ((volatile ADCMOD_byte_view_st *)\
(ADCMOD_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADCMOD()     ((volatile ADCMOD_halfword_view_st *)\
(ADCMOD_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ADCMOD()     ((volatile u32ADCMOD_word_view *)\
(ADCMOD_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADCMOD_SCAN() (pst_bitADCMOD() -> SCAN)
#define vSetADCMOD_SCAN(ParValue)  (pst_bitADCMOD() -> SCAN=(ParValue))
#define biGetADCMOD_ADCH() (pst_bitADCMOD() -> ADCH)
#define vSetADCMOD_ADCH(ParValue)  (pst_bitADCMOD() -> ADCH=(ParValue))
#define biGetADCMOD_REP() (pst_bitADCMOD() -> REP)
#define vSetADCMOD_REP(ParValue)  (pst_bitADCMOD() -> REP=(ParValue))
#define biGetADCMOD_DME() (pst_bitADCMOD() -> DME)
#define vSetADCMOD_DME(ParValue)  (pst_bitADCMOD() -> DME=(ParValue))
#define biGetADCMOD_ITM() (pst_bitADCMOD() -> ITM)
#define vSetADCMOD_ITM(ParValue)  (pst_bitADCMOD() -> ITM=(ParValue))
#define biGetADCMOD_TRGE() (pst_bitADCMOD() -> TRGE)
#define vSetADCMOD_TRGE(ParValue)  (pst_bitADCMOD() -> TRGE=(ParValue))
#define biGetADCMOD_TSEL() (pst_bitADCMOD() -> TSEL)
#define vSetADCMOD_TSEL(ParValue)  (pst_bitADCMOD() -> TSEL=(ParValue))
#define biGetADCMOD_ADC_RT() (pst_bitADCMOD() -> ADC_RT)
#define vSetADCMOD_ADC_RT(ParValue)  (pst_bitADCMOD() -> ADC_RT=(ParValue))
            
/* LL-struct byte access */
#define vSetADCMODLL(ParValue) (pst_u8ADCMOD() -> u8LL = (ParValue))
#define u8GetADCMODLL() (pst_u8ADCMOD() -> u8LL)
/* LH-struct byte access */
#define vSetADCMODLH(ParValue) (pst_u8ADCMOD() -> u8LH = (ParValue))
#define u8GetADCMODLH() (pst_u8ADCMOD() -> u8LH)
/* HL-struct byte access */
#define vSetADCMODHL(ParValue) (pst_u8ADCMOD() -> u8HL = (ParValue))
#define u8GetADCMODHL() (pst_u8ADCMOD() -> u8HL)
/* HH-struct byte access */
#define vSetADCMODHH(ParValue) (pst_u8ADCMOD() -> u8HH = (ParValue))
#define u8GetADCMODHH() (pst_u8ADCMOD() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADCMODL(ParValue) (pst_u16ADCMOD() -> u16L = (ParValue))
#define u16GetADCMODL() (pst_u16ADCMOD() -> u16L)
#define vSetADCMODH(ParValue) (pst_u16ADCMOD() -> u16H = (ParValue))
#define u16GetADCMODH() (pst_u16ADCMOD() -> u16H)
            
/* Word access */
#define vSetADCMOD(ParValue)  (*pu32ADCMOD() = (ParValue))
#define u32GetADCMOD()  (*pu32ADCMOD() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADCSTA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0410004                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADCSTA_REG__       0xC0410004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   ADSFT	:1; 	 /* 0..0  bit(s) W */
  uint8_t   	:3; 	 /* 1..3  bit(s) R */
  uint8_t   EOS	:1; 	 /* 4..4  bit(s) R/W0C */
  uint8_t   BUSY	:1; 	 /* 5..5  bit(s) R */ 
  uint8_t   	:2; 	 /* 6..31  bit(s) R */                    
} ADCSTA_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8ADCSTA_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADCSTA()     ((volatile ADCSTA_bit_view_st *)\
(ADCSTA_REG__ ))
        
/* Pointer to BYTE  */
#define pu8ADCSTA()     ((volatile u8ADCSTA_byte_view *)\
(ADCSTA_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetADCSTA_ADSFT(ParValue) (pst_bitADCSTA() -> ADSFT=(ParValue))
#define biGetADCSTA_EOS() (pst_bitADCSTA() -> EOS)
#define vClrADCSTA_EOS() (pst_bitADCSTA() -> EOS=(0))            
#define biGetADCSTA_BUSY() (pst_bitADCSTA() -> BUSY)
            
/* byte access */
#define vSetADCSTA(ParValue) (*pu8ADCSTA() = (ParValue))
#define u8GetADCSTA() (*pu8ADCSTA() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADCHP                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0410008                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADCHP_REG__       0xC0410008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   HPCH	:4; 	 /* 0..3  bit(s) R/W */
  uint16_t   HPRQ	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   HP	:1; 	 /* 5..5  bit(s) R */
  uint16_t   	:8; 	 /* 6..13  bit(s) R */
  uint16_t   HPE	:2; 	 /* 14..15  bit(s) R/C */                    
} ADCHP_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} ADCHP_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16ADCHP_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADCHP()     ((volatile ADCHP_bit_view_st *)\
(ADCHP_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADCHP()     ((volatile ADCHP_byte_view_st *)\
(ADCHP_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16ADCHP()     ((volatile u16ADCHP_halfword_view *)\
(ADCHP_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADCHP_HPCH() (pst_bitADCHP() -> HPCH)
#define vSetADCHP_HPCH(ParValue)  (pst_bitADCHP() -> HPCH=(ParValue))
#define biGetADCHP_HPRQ() (pst_bitADCHP() -> HPRQ)
#define vSetADCHP_HPRQ(ParValue)  (pst_bitADCHP() -> HPRQ=(ParValue))            
#define biGetADCHP_HP() (pst_bitADCHP() -> HP)
#define biGetADCHP_HPE() (pst_bitADCHP() -> HPE)
            
/* L-struct byte access */
#define vSetADCHPL(ParValue) (pst_u8ADCHP() -> u8L = (ParValue))
#define u8GetADCHPL() (pst_u8ADCHP() -> u8L)
/* H-struct byte access */
#define vSetADCHPH(ParValue) (pst_u8ADCHP() -> u8H = (ParValue))
#define u8GetADCHPH() (pst_u8ADCHP() -> u8H)
            
/* Half-word access */ 
#define vSetADCHP(ParValue) (*pu16ADCHP()  = (ParValue))
#define u16GetADCHP() (*pu16ADCHP() )                      
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADCCMP                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC041000C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADCCMP_REG__       0xC041000CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CVAL	:10; 	 /* 0..9  bit(s) R/W */
  uint32_t   CINT	:1; 	 /* 10..10  bit(s) R/W */
  uint32_t   CCON	:1; 	 /* 11..11  bit(s) R/W */
  uint32_t   CCH	:4; 	 /* 12..15  bit(s) R/W */
  uint32_t   CMON	:1; 	 /* 16..16  bit(s) R/W1C */ 
  uint32_t   	:15; 	 /* 17..31  bit(s) R */                    
} ADCCMP_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ADCCMP_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ADCCMP_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ADCCMP_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADCCMP(ch)     ((volatile ADCCMP_bit_view_st *)\
(ADCCMP_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADCCMP(ch)     ((volatile ADCCMP_byte_view_st *)\
(ADCCMP_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ADCCMP(ch)     ((volatile ADCCMP_halfword_view_st *)\
(ADCCMP_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32ADCCMP(ch)     ((volatile u32ADCCMP_word_view *)\
(ADCCMP_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetADCCMP_CVAL(ch) (pst_bitADCCMP(ch) -> CVAL)
#define vSetADCCMP_CVAL(ch,ParValue)  (pst_bitADCCMP(ch) -> CVAL=(ParValue))
#define biGetADCCMP_CINT(ch) (pst_bitADCCMP(ch) -> CINT)
#define vSetADCCMP_CINT(ch,ParValue)  (pst_bitADCCMP(ch) -> CINT=(ParValue))
#define biGetADCCMP_CCON(ch) (pst_bitADCCMP(ch) -> CCON)
#define vSetADCCMP_CCON(ch,ParValue)  (pst_bitADCCMP(ch) -> CCON=(ParValue))
#define biGetADCCMP_CCH(ch) (pst_bitADCCMP(ch) -> CCH)
#define vSetADCCMP_CCH(ch,ParValue)  (pst_bitADCCMP(ch) -> CCH=(ParValue))
#define biGetADCCMP_CMON(ch) (pst_bitADCCMP(ch) -> CMON)
#define vClrADCCMP_CMON(ch) (pst_bitADCCMP(ch) -> CMON = (1))
            
/* LL-struct byte access */
#define vSetADCCMPLL(ch,ParValue) (pst_u8ADCCMP(ch) -> u8LL = (ParValue))
#define u8GetADCCMPLL(ch) (pst_u8ADCCMP(ch) -> u8LL)
/* LH-struct byte access */
#define vSetADCCMPLH(ch,ParValue) (pst_u8ADCCMP(ch) -> u8LH = (ParValue))
#define u8GetADCCMPLH(ch) (pst_u8ADCCMP(ch) -> u8LH)
/* HL-struct byte access */
#define vSetADCCMPHL(ch,ParValue) (pst_u8ADCCMP(ch) -> u8HL = (ParValue))
#define u8GetADCCMPHL(ch) (pst_u8ADCCMP(ch) -> u8HL)
/* HH-struct byte access */
#define vSetADCCMPHH(ch,ParValue) (pst_u8ADCCMP(ch) -> u8HH = (ParValue))
#define u8GetADCCMPHH(ch) (pst_u8ADCCMP(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetADCCMPL(ch,ParValue) (pst_u16ADCCMP(ch) -> u16L = (ParValue))
#define u16GetADCCMPL(ch) (pst_u16ADCCMP(ch) -> u16L)
#define vSetADCCMPH(ch,ParValue) (pst_u16ADCCMP(ch) -> u16H = (ParValue))
#define u16GetADCCMPH(ch) (pst_u16ADCCMP(ch) -> u16H)
            
/* Word access */
#define vSetADCCMP(ch,ParValue)  (*pu32ADCCMP(ch) = (ParValue))
#define u32GetADCCMP(ch)  (*pu32ADCCMP(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADCRES                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0410014                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADCRES_REG__       0xC0410014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   DAT	:10; 	 /* 0..9  bit(s) R */
  uint16_t   	:4; 	 /* 10..13  bit(s) R */
  uint16_t   OVR	:1; 	 /* 14..14  bit(s) R */
  uint16_t   VAL	:1; 	 /* 15..15  bit(s) R */                    
} ADCRES_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} ADCRES_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16ADCRES_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADCRES(ch)     ((volatile ADCRES_bit_view_st *)\
(ADCRES_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADCRES(ch)     ((volatile ADCRES_byte_view_st *)\
(ADCRES_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD */
#define pu16ADCRES(ch)     ((volatile u16ADCRES_halfword_view *)\
(ADCRES_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetADCRES_DAT(ch) (pst_bitADCRES(ch) -> DAT)            
#define biGetADCRES_OVR(ch) (pst_bitADCRES(ch) -> OVR)            
#define biGetADCRES_VAL(ch) (pst_bitADCRES(ch) -> VAL)
            
/* L-struct byte access */

#define u8GetADCRESL(ch) (pst_u8ADCRES(ch) -> u8L)
/* H-struct byte access */

#define u8GetADCRESH(ch) (pst_u8ADCRES(ch) -> u8H)
            
/* Half-word access */ 

#define u16GetADCRES(ch) (*pu16ADCRES(ch) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: ADCHPR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0410054                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ADCHPR_REG__       0xC0410054U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   DAT	:10; 	 /* 0..9  bit(s) R */
  uint16_t   	:4; 	 /* 10..13  bit(s) R */
  uint16_t   OVR	:1; 	 /* 14..14  bit(s) R */
  uint16_t   VAL	:1; 	 /* 15..15  bit(s) R */                    
} ADCHPR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} ADCHPR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16ADCHPR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitADCHPR()     ((volatile ADCHPR_bit_view_st *)\
(ADCHPR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ADCHPR()     ((volatile ADCHPR_byte_view_st *)\
(ADCHPR_REG__ ))
            
/* Pointer to HALFWORD */
#define pu16ADCHPR()     ((volatile u16ADCHPR_halfword_view *)\
(ADCHPR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetADCHPR_DAT() (pst_bitADCHPR() -> DAT)            
#define biGetADCHPR_OVR() (pst_bitADCHPR() -> OVR)            
#define biGetADCHPR_VAL() (pst_bitADCHPR() -> VAL)
            
/* L-struct byte access */

#define u8GetADCHPRL() (pst_u8ADCHPR() -> u8L)
/* H-struct byte access */

#define u8GetADCHPRH() (pst_u8ADCHPR() -> u8H)
            
/* Half-word access */ 

#define u16GetADCHPR() (*pu16ADCHPR() )


#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
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

#endif /* ADCCIO_H */ 
    
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

