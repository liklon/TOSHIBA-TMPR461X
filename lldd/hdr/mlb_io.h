
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : MLB 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:57:06.907+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.6 $ 
/  Excel Sheet ver.             : vv1.1
/  Excel Sheet date             : 2013-June-19
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION :  MediaLB low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : 
*   LIBRARIES   :
*****************************************************************************
*   VERSION     : $Revision: 1.6 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef _MLBIO_H
#define _MLBIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */ 

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_MLB_IO_H_REVISION     "$Revision: 1.6 $"
#define LLDD_MLB_IO_H_TAG          "$Name: LLDD_1_6 $"
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: DCCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DCCR_REG__       0xC0D00000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MDA	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   	:15; 	 /* 8..22  bit(s) R */
  uint32_t   MRS	:1; 	 /* 23..23  bit(s) S/U */
  uint32_t   MHRE	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   MLE	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   MLK	:1; 	 /* 26..26  bit(s) R/U */
  uint32_t   M5PS	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   MCS	:2; 	 /* 28..29  bit(s) R/W */
  uint32_t   LBM	:1; 	 /* 30..30  bit(s) R/W */ 
  uint32_t   MDE	:1; 	 /* 31..31  bit(s) R/W */                    
} DCCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DCCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DCCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DCCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDCCR()     ((volatile DCCR_bit_view_st *)\
(DCCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8DCCR()     ((volatile DCCR_byte_view_st *)\
(DCCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DCCR()     ((volatile DCCR_halfword_view_st *)\
(DCCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32DCCR()     ((volatile u32DCCR_word_view *)\
(DCCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDCCR_MDA() (pst_bitDCCR() -> MDA)
#define vSetDCCR_MDA(ParValue)  (pst_bitDCCR() -> MDA=(ParValue)) 
#define vSetDCCR_MRS(ParValue) (pst_bitDCCR() -> MRS=(ParValue))
#define biGetDCCR_MHRE() (pst_bitDCCR() -> MHRE)
#define vSetDCCR_MHRE(ParValue)  (pst_bitDCCR() -> MHRE=(ParValue))
#define biGetDCCR_MLE() (pst_bitDCCR() -> MLE)
#define vSetDCCR_MLE(ParValue)  (pst_bitDCCR() -> MLE=(ParValue))            
#define biGetDCCR_MLK() (pst_bitDCCR() -> MLK)
#define biGetDCCR_M5PS() (pst_bitDCCR() -> M5PS)
#define vSetDCCR_M5PS(ParValue)  (pst_bitDCCR() -> M5PS=(ParValue))
#define biGetDCCR_MCS() (pst_bitDCCR() -> MCS)
#define vSetDCCR_MCS(ParValue)  (pst_bitDCCR() -> MCS=(ParValue))
#define biGetDCCR_LBM() (pst_bitDCCR() -> LBM)
#define vSetDCCR_LBM(ParValue)  (pst_bitDCCR() -> LBM=(ParValue))
#define biGetDCCR_MDE() (pst_bitDCCR() -> MDE)
#define vSetDCCR_MDE(ParValue)  (pst_bitDCCR() -> MDE=(ParValue))
            
/* LL-struct byte access */
#define vSetDCCRLL(ParValue) (pst_u8DCCR() -> u8LL = (ParValue))
#define u8GetDCCRLL() (pst_u8DCCR() -> u8LL)
/* LH-struct byte access */
#define vSetDCCRLH(ParValue) (pst_u8DCCR() -> u8LH = (ParValue))
#define u8GetDCCRLH() (pst_u8DCCR() -> u8LH)
/* HL-struct byte access */
#define vSetDCCRHL(ParValue) (pst_u8DCCR() -> u8HL = (ParValue))
#define u8GetDCCRHL() (pst_u8DCCR() -> u8HL)
/* HH-struct byte access */
#define vSetDCCRHH(ParValue) (pst_u8DCCR() -> u8HH = (ParValue))
#define u8GetDCCRHH() (pst_u8DCCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDCCRL(ParValue) (pst_u16DCCR() -> u16L = (ParValue))
#define u16GetDCCRL() (pst_u16DCCR() -> u16L)
#define vSetDCCRH(ParValue) (pst_u16DCCR() -> u16H = (ParValue))
#define u16GetDCCRH() (pst_u16DCCR() -> u16H)
            
/* Word access */
#define vSetDCCR(ParValue)  (*pu32DCCR() = (ParValue))
#define u32GetDCCR()  (*pu32DCCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SSCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00004                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SSCR_REG__       0xC0D00004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   SDR	:1; 	 /* 0..0  bit(s) R/C/U */
  uint8_t   SDNL	:1; 	 /* 1..1  bit(s) R/C/U */
  uint8_t   SDNU	:1; 	 /* 2..2  bit(s) R/C/U */
  uint8_t   SDCS	:1; 	 /* 3..3  bit(s) R/C/U */
  uint8_t   SDSC	:1; 	 /* 4..4  bit(s) R/C/U */
  uint8_t   SDML	:1; 	 /* 5..5  bit(s) R/C/U */
  uint8_t   SDMU	:1; 	 /* 6..6  bit(s) R/C/U */
  uint8_t   SSRE	:1; 	 /* 7..7  bit(s) R/S/U */                    
} SSCR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SSCR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSSCR()     ((volatile SSCR_bit_view_st *)\
(SSCR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8SSCR()     ((volatile u8SSCR_byte_view *)\
(SSCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSSCR_SDR() (pst_bitSSCR() -> SDR)
#define vClrSSCR_SDR() (pst_bitSSCR() -> SDR = (1))
#define biGetSSCR_SDNL() (pst_bitSSCR() -> SDNL)
#define vClrSSCR_SDNL() (pst_bitSSCR() -> SDNL = (1))
#define biGetSSCR_SDNU() (pst_bitSSCR() -> SDNU)
#define vClrSSCR_SDNU() (pst_bitSSCR() -> SDNU = (1))
#define biGetSSCR_SDCS() (pst_bitSSCR() -> SDCS)
#define vClrSSCR_SDCS() (pst_bitSSCR() -> SDCS = (1))
#define biGetSSCR_SDSC() (pst_bitSSCR() -> SDSC)
#define vClrSSCR_SDSC() (pst_bitSSCR() -> SDSC = (1))
#define biGetSSCR_SDML() (pst_bitSSCR() -> SDML)
#define vClrSSCR_SDML() (pst_bitSSCR() -> SDML = (1))
#define biGetSSCR_SDMU() (pst_bitSSCR() -> SDMU)
#define vClrSSCR_SDMU() (pst_bitSSCR() -> SDMU = (1))
#define biGetSSCR_SSRE() (pst_bitSSCR() -> SSRE)
#define vSetSSCR_SSRE(ParValue)  (pst_bitSSCR() -> SSRE=(ParValue))
            
/* byte access */
#define vSetSSCR(ParValue) (*pu8SSCR() = (ParValue))
#define u8GetSSCR() (*pu8SSCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SDCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SDCR_REG__       0xC0D00008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   MSD	:32; 	 /* 0..31  bit(s) R/U */                    
} SDCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SDCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SDCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SDCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSDCR()     ((volatile SDCR_bit_view_st *)\
(SDCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SDCR()     ((volatile SDCR_byte_view_st *)\
(SDCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SDCR()     ((volatile SDCR_halfword_view_st *)\
(SDCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SDCR()     ((volatile u32SDCR_word_view *)\
(SDCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSDCR_MSD() (pst_bitSDCR() -> MSD)
            
/* LL-struct byte access */
#define vSetSDCRLL(ParValue) (pst_u8SDCR() -> u8LL = (ParValue))
#define u8GetSDCRLL() (pst_u8SDCR() -> u8LL)
/* LH-struct byte access */
#define vSetSDCRLH(ParValue) (pst_u8SDCR() -> u8LH = (ParValue))
#define u8GetSDCRLH() (pst_u8SDCR() -> u8LH)
/* HL-struct byte access */
#define vSetSDCRHL(ParValue) (pst_u8SDCR() -> u8HL = (ParValue))
#define u8GetSDCRHL() (pst_u8SDCR() -> u8HL)
/* HH-struct byte access */
#define vSetSDCRHH(ParValue) (pst_u8SDCR() -> u8HH = (ParValue))
#define u8GetSDCRHH() (pst_u8SDCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSDCRL(ParValue) (pst_u16SDCR() -> u16L = (ParValue))
#define u16GetSDCRL() (pst_u16SDCR() -> u16L)
#define vSetSDCRH(ParValue) (pst_u16SDCR() -> u16H = (ParValue))
#define u16GetSDCRH() (pst_u16SDCR() -> u16H)
            
/* Word access */
#define vSetSDCR(ParValue)  (*pu32SDCR() = (ParValue))
#define u32GetSDCR()  (*pu32SDCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SMCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D0000C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SMCR_REG__       0xC0D0000CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   SMR	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   SMNL	:1; 	 /* 1..1  bit(s) R/W */
  uint8_t   SMNU	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   SMCS	:1; 	 /* 3..3  bit(s) R/W */
  uint8_t   SMSC	:1; 	 /* 4..4  bit(s) R/W */
  uint8_t   SMML	:1; 	 /* 5..5  bit(s) R/W */
  uint8_t   SMMU	:1; 	 /* 6..6  bit(s) R/W */ 
  uint8_t   	:1; 	 /* 7..31  bit(s) R */                    
} SMCR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8SMCR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSMCR()     ((volatile SMCR_bit_view_st *)\
(SMCR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8SMCR()     ((volatile u8SMCR_byte_view *)\
(SMCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSMCR_SMR() (pst_bitSMCR() -> SMR)
#define vSetSMCR_SMR(ParValue)  (pst_bitSMCR() -> SMR=(ParValue))
#define biGetSMCR_SMNL() (pst_bitSMCR() -> SMNL)
#define vSetSMCR_SMNL(ParValue)  (pst_bitSMCR() -> SMNL=(ParValue))
#define biGetSMCR_SMNU() (pst_bitSMCR() -> SMNU)
#define vSetSMCR_SMNU(ParValue)  (pst_bitSMCR() -> SMNU=(ParValue))
#define biGetSMCR_SMCS() (pst_bitSMCR() -> SMCS)
#define vSetSMCR_SMCS(ParValue)  (pst_bitSMCR() -> SMCS=(ParValue))
#define biGetSMCR_SMSC() (pst_bitSMCR() -> SMSC)
#define vSetSMCR_SMSC(ParValue)  (pst_bitSMCR() -> SMSC=(ParValue))
#define biGetSMCR_SMML() (pst_bitSMCR() -> SMML)
#define vSetSMCR_SMML(ParValue)  (pst_bitSMCR() -> SMML=(ParValue))
#define biGetSMCR_SMMU() (pst_bitSMCR() -> SMMU)
#define vSetSMCR_SMMU(ParValue)  (pst_bitSMCR() -> SMMU=(ParValue))
            
/* byte access */
#define vSetSMCR(ParValue) (*pu8SMCR() = (ParValue))
#define u8GetSMCR() (*pu8SMCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: VCCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D0001C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define VCCR_REG__       0xC0D0001CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MMI	:8; 	 /* 0..7  bit(s) R */
  uint32_t   MMA	:8; 	 /* 8..15  bit(s) R */
  uint32_t   TMI	:8; 	 /* 16..23  bit(s) R */ 
  uint32_t   TMA	:8; 	 /* 24..31  bit(s) R */                    
} VCCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} VCCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} VCCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32VCCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitVCCR()     ((volatile VCCR_bit_view_st *)\
(VCCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8VCCR()     ((volatile VCCR_byte_view_st *)\
(VCCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16VCCR()     ((volatile VCCR_halfword_view_st *)\
(VCCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32VCCR()     ((volatile u32VCCR_word_view *)\
(VCCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetVCCR_MMI() (pst_bitVCCR() -> MMI)            
#define biGetVCCR_MMA() (pst_bitVCCR() -> MMA)            
#define biGetVCCR_TMI() (pst_bitVCCR() -> TMI)            
#define biGetVCCR_TMA() (pst_bitVCCR() -> TMA)
            
/* LL-struct byte access */

#define u8GetVCCRLL() (pst_u8VCCR() -> u8LL)
/* LH-struct byte access */

#define u8GetVCCRLH() (pst_u8VCCR() -> u8LH)
/* HL-struct byte access */

#define u8GetVCCRHL() (pst_u8VCCR() -> u8HL)
/* HH-struct byte access */

#define u8GetVCCRHH() (pst_u8VCCR() -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetVCCRL() (pst_u16VCCR() -> u16L)

#define u16GetVCCRH() (pst_u16VCCR() -> u16H)
            
/* Word access */

#define u32GetVCCR()  (*pu32VCCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: SBCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define SBCR_REG__       0xC0D00020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   STBA	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   SRBA	:16; 	 /* 16..31  bit(s) R/W */                    
} SBCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SBCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SBCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SBCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSBCR()     ((volatile SBCR_bit_view_st *)\
(SBCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8SBCR()     ((volatile SBCR_byte_view_st *)\
(SBCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SBCR()     ((volatile SBCR_halfword_view_st *)\
(SBCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32SBCR()     ((volatile u32SBCR_word_view *)\
(SBCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSBCR_STBA() (pst_bitSBCR() -> STBA)
#define vSetSBCR_STBA(ParValue)  (pst_bitSBCR() -> STBA=(ParValue))
#define biGetSBCR_SRBA() (pst_bitSBCR() -> SRBA)
#define vSetSBCR_SRBA(ParValue)  (pst_bitSBCR() -> SRBA=(ParValue))
            
/* LL-struct byte access */
#define vSetSBCRLL(ParValue) (pst_u8SBCR() -> u8LL = (ParValue))
#define u8GetSBCRLL() (pst_u8SBCR() -> u8LL)
/* LH-struct byte access */
#define vSetSBCRLH(ParValue) (pst_u8SBCR() -> u8LH = (ParValue))
#define u8GetSBCRLH() (pst_u8SBCR() -> u8LH)
/* HL-struct byte access */
#define vSetSBCRHL(ParValue) (pst_u8SBCR() -> u8HL = (ParValue))
#define u8GetSBCRHL() (pst_u8SBCR() -> u8HL)
/* HH-struct byte access */
#define vSetSBCRHH(ParValue) (pst_u8SBCR() -> u8HH = (ParValue))
#define u8GetSBCRHH() (pst_u8SBCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSBCRL(ParValue) (pst_u16SBCR() -> u16L = (ParValue))
#define u16GetSBCRL() (pst_u16SBCR() -> u16L)
#define vSetSBCRH(ParValue) (pst_u16SBCR() -> u16H = (ParValue))
#define u16GetSBCRH() (pst_u16SBCR() -> u16H)
            
/* Word access */
#define vSetSBCR(ParValue)  (*pu32SBCR() = (ParValue))
#define u32GetSBCR()  (*pu32SBCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ABCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00024                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ABCR_REG__       0xC0D00024U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ATBA	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   ARBA	:16; 	 /* 16..31  bit(s) R/W */                    
} ABCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ABCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ABCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ABCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitABCR()     ((volatile ABCR_bit_view_st *)\
(ABCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8ABCR()     ((volatile ABCR_byte_view_st *)\
(ABCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ABCR()     ((volatile ABCR_halfword_view_st *)\
(ABCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32ABCR()     ((volatile u32ABCR_word_view *)\
(ABCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetABCR_ATBA() (pst_bitABCR() -> ATBA)
#define vSetABCR_ATBA(ParValue)  (pst_bitABCR() -> ATBA=(ParValue))
#define biGetABCR_ARBA() (pst_bitABCR() -> ARBA)
#define vSetABCR_ARBA(ParValue)  (pst_bitABCR() -> ARBA=(ParValue))
            
/* LL-struct byte access */
#define vSetABCRLL(ParValue) (pst_u8ABCR() -> u8LL = (ParValue))
#define u8GetABCRLL() (pst_u8ABCR() -> u8LL)
/* LH-struct byte access */
#define vSetABCRLH(ParValue) (pst_u8ABCR() -> u8LH = (ParValue))
#define u8GetABCRLH() (pst_u8ABCR() -> u8LH)
/* HL-struct byte access */
#define vSetABCRHL(ParValue) (pst_u8ABCR() -> u8HL = (ParValue))
#define u8GetABCRHL() (pst_u8ABCR() -> u8HL)
/* HH-struct byte access */
#define vSetABCRHH(ParValue) (pst_u8ABCR() -> u8HH = (ParValue))
#define u8GetABCRHH() (pst_u8ABCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetABCRL(ParValue) (pst_u16ABCR() -> u16L = (ParValue))
#define u16GetABCRL() (pst_u16ABCR() -> u16L)
#define vSetABCRH(ParValue) (pst_u16ABCR() -> u16H = (ParValue))
#define u16GetABCRH() (pst_u16ABCR() -> u16H)
            
/* Word access */
#define vSetABCR(ParValue)  (*pu32ABCR() = (ParValue))
#define u32GetABCR()  (*pu32ABCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CBCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00028                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CBCR_REG__       0xC0D00028U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CTBA	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   CRBA	:16; 	 /* 16..31  bit(s) R/W */                    
} CBCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CBCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CBCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CBCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCBCR()     ((volatile CBCR_bit_view_st *)\
(CBCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8CBCR()     ((volatile CBCR_byte_view_st *)\
(CBCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CBCR()     ((volatile CBCR_halfword_view_st *)\
(CBCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32CBCR()     ((volatile u32CBCR_word_view *)\
(CBCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCBCR_CTBA() (pst_bitCBCR() -> CTBA)
#define vSetCBCR_CTBA(ParValue)  (pst_bitCBCR() -> CTBA=(ParValue))
#define biGetCBCR_CRBA() (pst_bitCBCR() -> CRBA)
#define vSetCBCR_CRBA(ParValue)  (pst_bitCBCR() -> CRBA=(ParValue))
            
/* LL-struct byte access */
#define vSetCBCRLL(ParValue) (pst_u8CBCR() -> u8LL = (ParValue))
#define u8GetCBCRLL() (pst_u8CBCR() -> u8LL)
/* LH-struct byte access */
#define vSetCBCRLH(ParValue) (pst_u8CBCR() -> u8LH = (ParValue))
#define u8GetCBCRLH() (pst_u8CBCR() -> u8LH)
/* HL-struct byte access */
#define vSetCBCRHL(ParValue) (pst_u8CBCR() -> u8HL = (ParValue))
#define u8GetCBCRHL() (pst_u8CBCR() -> u8HL)
/* HH-struct byte access */
#define vSetCBCRHH(ParValue) (pst_u8CBCR() -> u8HH = (ParValue))
#define u8GetCBCRHH() (pst_u8CBCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCBCRL(ParValue) (pst_u16CBCR() -> u16L = (ParValue))
#define u16GetCBCRL() (pst_u16CBCR() -> u16L)
#define vSetCBCRH(ParValue) (pst_u16CBCR() -> u16H = (ParValue))
#define u16GetCBCRH() (pst_u16CBCR() -> u16H)
            
/* Word access */
#define vSetCBCR(ParValue)  (*pu32CBCR() = (ParValue))
#define u32GetCBCR()  (*pu32CBCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: IBCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D0002C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define IBCR_REG__       0xC0D0002CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ITBA	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   IRBA	:16; 	 /* 16..31  bit(s) R/W */                    
} IBCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} IBCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} IBCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32IBCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitIBCR()     ((volatile IBCR_bit_view_st *)\
(IBCR_REG__ ))
        
/* Pointer to BYTE-struct  */
#define pst_u8IBCR()     ((volatile IBCR_byte_view_st *)\
(IBCR_REG__ ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16IBCR()     ((volatile IBCR_halfword_view_st *)\
(IBCR_REG__ ))
            
/* Pointer to WORD  */ 
#define pu32IBCR()     ((volatile u32IBCR_word_view *)\
(IBCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIBCR_ITBA() (pst_bitIBCR() -> ITBA)
#define vSetIBCR_ITBA(ParValue)  (pst_bitIBCR() -> ITBA=(ParValue))
#define biGetIBCR_IRBA() (pst_bitIBCR() -> IRBA)
#define vSetIBCR_IRBA(ParValue)  (pst_bitIBCR() -> IRBA=(ParValue))
            
/* LL-struct byte access */
#define vSetIBCRLL(ParValue) (pst_u8IBCR() -> u8LL = (ParValue))
#define u8GetIBCRLL() (pst_u8IBCR() -> u8LL)
/* LH-struct byte access */
#define vSetIBCRLH(ParValue) (pst_u8IBCR() -> u8LH = (ParValue))
#define u8GetIBCRLH() (pst_u8IBCR() -> u8LH)
/* HL-struct byte access */
#define vSetIBCRHL(ParValue) (pst_u8IBCR() -> u8HL = (ParValue))
#define u8GetIBCRHL() (pst_u8IBCR() -> u8HL)
/* HH-struct byte access */
#define vSetIBCRHH(ParValue) (pst_u8IBCR() -> u8HH = (ParValue))
#define u8GetIBCRHH() (pst_u8IBCR() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetIBCRL(ParValue) (pst_u16IBCR() -> u16L = (ParValue))
#define u16GetIBCRL() (pst_u16IBCR() -> u16L)
#define vSetIBCRH(ParValue) (pst_u16IBCR() -> u16H = (ParValue))
#define u16GetIBCRH() (pst_u16IBCR() -> u16H)
            
/* Word access */
#define vSetIBCR(ParValue)  (*pu32IBCR() = (ParValue))
#define u32GetIBCR()  (*pu32IBCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CICR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00030                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CICR_REG__       0xC0D00030U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   CNSU	:6; 	 /* 0..5  bit(s) R/U */ 
  uint8_t   	:2; 	 /* 6..31  bit(s) R */                    
} CICR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8CICR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCICR()     ((volatile CICR_bit_view_st *)\
(CICR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8CICR()     ((volatile u8CICR_byte_view *)\
(CICR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCICR_CNSU() (pst_bitCICR() -> CNSU)
            
/* byte access */
#define vSetCICR(ParValue) (*pu8CICR() = (ParValue))
#define u8GetCICR() (*pu8CICR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CECR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00040                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CECR_REG__       0xC0D00040U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CA	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   PCTH_FSPC_IPL	:5; 	 /* 8..12  bit(s) R/W */
  uint32_t   IPL	:2; 	 /* 13..14  bit(s) R/W */
  uint32_t   FSCD_IPL	:1; 	 /* 15..15  bit(s) R/W */
  uint32_t   MASK	:8; 	 /* 16..23  bit(s) R/W */
  uint32_t   	:1; 	 /* 24..24  bit(s) R */
  uint32_t   MDS	:2; 	 /* 25..26  bit(s) R/W */
  uint32_t   PCE_FSE_FCE	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   CT	:2; 	 /* 28..29  bit(s) R/W */
  uint32_t   TR	:1; 	 /* 30..30  bit(s) R/W */ 
  uint32_t   CE	:1; 	 /* 31..31  bit(s) R/W/U */                    
} CECR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CECR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CECR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CECR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCECR(ch)     ((volatile CECR_bit_view_st *)\
(CECR_REG__  + ((uint16_t)(ch) * 0x10U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8CECR(ch)     ((volatile CECR_byte_view_st *)\
(CECR_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CECR(ch)     ((volatile CECR_halfword_view_st *)\
(CECR_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to WORD  */ 
#define pu32CECR(ch)     ((volatile u32CECR_word_view *)\
(CECR_REG__  + ((uint16_t)(ch) * 0x10U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCECR_CA(ch) (pst_bitCECR(ch) -> CA)
#define vSetCECR_CA(ch,ParValue)  (pst_bitCECR(ch) -> CA=(ParValue))
#define biGetCECR_PCTH_FSPC_IPL(ch) (pst_bitCECR(ch) -> PCTH_FSPC_IPL)
#define vSetCECR_PCTH_FSPC_IPL(ch,ParValue)  (pst_bitCECR(ch) -> PCTH_FSPC_IPL=(ParValue))
#define biGetCECR_IPL(ch) (pst_bitCECR(ch) -> IPL)
#define vSetCECR_IPL(ch,ParValue)  (pst_bitCECR(ch) -> IPL=(ParValue))
#define biGetCECR_FSCD_IPL(ch) (pst_bitCECR(ch) -> FSCD_IPL)
#define vSetCECR_FSCD_IPL(ch,ParValue)  (pst_bitCECR(ch) -> FSCD_IPL=(ParValue))
#define biGetCECR_MASK(ch) (pst_bitCECR(ch) -> MASK)
#define vSetCECR_MASK(ch,ParValue)  (pst_bitCECR(ch) -> MASK=(ParValue))
#define biGetCECR_MDS(ch) (pst_bitCECR(ch) -> MDS)
#define vSetCECR_MDS(ch,ParValue)  (pst_bitCECR(ch) -> MDS=(ParValue))
#define biGetCECR_PCE_FSE_FCE(ch) (pst_bitCECR(ch) -> PCE_FSE_FCE)
#define vSetCECR_PCE_FSE_FCE(ch,ParValue)  (pst_bitCECR(ch) -> PCE_FSE_FCE=(ParValue))
#define biGetCECR_CT(ch) (pst_bitCECR(ch) -> CT)
#define vSetCECR_CT(ch,ParValue)  (pst_bitCECR(ch) -> CT=(ParValue))
#define biGetCECR_TR(ch) (pst_bitCECR(ch) -> TR)
#define vSetCECR_TR(ch,ParValue)  (pst_bitCECR(ch) -> TR=(ParValue))
#define biGetCECR_CE(ch) (pst_bitCECR(ch) -> CE)
#define vSetCECR_CE(ch,ParValue)  (pst_bitCECR(ch) -> CE=(ParValue))
            
/* LL-struct byte access */
#define vSetCECRLL(ch,ParValue) (pst_u8CECR(ch) -> u8LL = (ParValue))
#define u8GetCECRLL(ch) (pst_u8CECR(ch) -> u8LL)
/* LH-struct byte access */
#define vSetCECRLH(ch,ParValue) (pst_u8CECR(ch) -> u8LH = (ParValue))
#define u8GetCECRLH(ch) (pst_u8CECR(ch) -> u8LH)
/* HL-struct byte access */
#define vSetCECRHL(ch,ParValue) (pst_u8CECR(ch) -> u8HL = (ParValue))
#define u8GetCECRHL(ch) (pst_u8CECR(ch) -> u8HL)
/* HH-struct byte access */
#define vSetCECRHH(ch,ParValue) (pst_u8CECR(ch) -> u8HH = (ParValue))
#define u8GetCECRHH(ch) (pst_u8CECR(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCECRL(ch,ParValue) (pst_u16CECR(ch) -> u16L = (ParValue))
#define u16GetCECRL(ch) (pst_u16CECR(ch) -> u16L)
#define vSetCECRH(ch,ParValue) (pst_u16CECR(ch) -> u16H = (ParValue))
#define u16GetCECRH(ch) (pst_u16CECR(ch) -> u16H)
            
/* Word access */
#define vSetCECR(ch,ParValue)  (*pu32CECR(ch) = (ParValue))
#define u32GetCECR(ch)  (*pu32CECR(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CSCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00044                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CSCR_REG__       0xC0D00044U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   STS0	:1; 	 /* 0..0  bit(s) R/C/U */
  uint32_t   STS1	:1; 	 /* 1..1  bit(s) R/C/U */
  uint32_t   STS2	:1; 	 /* 2..2  bit(s) R/C/U */
  uint32_t   STS3	:1; 	 /* 3..3  bit(s) R/C/U */
  uint32_t   STS4	:1; 	 /* 4..4  bit(s) R/C/U */
  uint32_t   STS5	:1; 	 /* 5..5  bit(s) R/C/U */
  uint32_t   STS6	:1; 	 /* 6..6  bit(s) R/C/U */
  uint32_t   STS7	:1; 	 /* 7..7  bit(s) R */
  uint32_t   STS8	:1; 	 /* 8..8  bit(s) R/C/U */
  uint32_t   STS9	:1; 	 /* 9..9  bit(s) R/C/U */
  uint32_t   STS10	:1; 	 /* 10..10  bit(s) R/C/U */
  uint32_t   STS11	:1; 	 /* 11..11  bit(s) R/C/U */
  uint32_t   STS15_12	:4; 	 /* 12..15  bit(s) R */
  uint32_t   RDY	:1; 	 /* 16..16  bit(s) R/S/C */
  uint32_t   GIRB_GB	:1; 	 /* 17..17  bit(s) R/S/U */
  uint32_t   IVB	:2; 	 /* 18..19  bit(s) R/U */
  uint32_t   	:10; 	 /* 20..29  bit(s) R */
  uint32_t   BF	:1; 	 /* 30..30  bit(s) R/U */ 
  uint32_t   BM	:1; 	 /* 31..31  bit(s) R/U */                    
} CSCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CSCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CSCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CSCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCSCR(ch)     ((volatile CSCR_bit_view_st *)\
(CSCR_REG__  + ((uint16_t)(ch) * 0x10U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8CSCR(ch)     ((volatile CSCR_byte_view_st *)\
(CSCR_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CSCR(ch)     ((volatile CSCR_halfword_view_st *)\
(CSCR_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to WORD  */ 
#define pu32CSCR(ch)     ((volatile u32CSCR_word_view *)\
(CSCR_REG__  + ((uint16_t)(ch) * 0x10U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCSCR_STS0(ch) (pst_bitCSCR(ch) -> STS0)
#define vClrCSCR_STS0(ch) (pst_bitCSCR(ch) -> STS0 = (1))
#define biGetCSCR_STS1(ch) (pst_bitCSCR(ch) -> STS1)
#define vClrCSCR_STS1(ch) (pst_bitCSCR(ch) -> STS1 = (1))
#define biGetCSCR_STS2(ch) (pst_bitCSCR(ch) -> STS2)
#define vClrCSCR_STS2(ch) (pst_bitCSCR(ch) -> STS2 = (1))
#define biGetCSCR_STS3(ch) (pst_bitCSCR(ch) -> STS3)
#define vClrCSCR_STS3(ch) (pst_bitCSCR(ch) -> STS3 = (1))
#define biGetCSCR_STS4(ch) (pst_bitCSCR(ch) -> STS4)
#define vClrCSCR_STS4(ch) (pst_bitCSCR(ch) -> STS4 = (1))
#define biGetCSCR_STS5(ch) (pst_bitCSCR(ch) -> STS5)
#define vClrCSCR_STS5(ch) (pst_bitCSCR(ch) -> STS5 = (1))
#define biGetCSCR_STS6(ch) (pst_bitCSCR(ch) -> STS6)
#define vClrCSCR_STS6(ch) (pst_bitCSCR(ch) -> STS6 = (1))            
#define biGetCSCR_STS7(ch) (pst_bitCSCR(ch) -> STS7)
#define biGetCSCR_STS8(ch) (pst_bitCSCR(ch) -> STS8)
#define vClrCSCR_STS8(ch) (pst_bitCSCR(ch) -> STS8 = (1))
#define biGetCSCR_STS9(ch) (pst_bitCSCR(ch) -> STS9)
#define vClrCSCR_STS9(ch) (pst_bitCSCR(ch) -> STS9 = (1))
#define biGetCSCR_STS10(ch) (pst_bitCSCR(ch) -> STS10)
#define vClrCSCR_STS10(ch) (pst_bitCSCR(ch) -> STS10 = (1))
#define biGetCSCR_STS11(ch) (pst_bitCSCR(ch) -> STS11)
#define vClrCSCR_STS11(ch) (pst_bitCSCR(ch) -> STS11 = (1))            
#define biGetCSCR_STS15_12(ch) (pst_bitCSCR(ch) -> STS15_12)
#define biGetCSCR_RDY(ch) (pst_bitCSCR(ch) -> RDY)
#define vSetCSCR_RDY(ch,ParValue)  (pst_bitCSCR(ch) -> RDY=(ParValue))
#define biGetCSCR_GIRB_GB(ch) (pst_bitCSCR(ch) -> GIRB_GB)
#define vSetCSCR_GIRB_GB(ch,ParValue)  (pst_bitCSCR(ch) -> GIRB_GB=(ParValue))            
#define biGetCSCR_IVB(ch) (pst_bitCSCR(ch) -> IVB)            
#define biGetCSCR_BF(ch) (pst_bitCSCR(ch) -> BF)            
#define biGetCSCR_BM(ch) (pst_bitCSCR(ch) -> BM)
            
/* LL-struct byte access */
#define vSetCSCRLL(ch,ParValue) (pst_u8CSCR(ch) -> u8LL = (ParValue))
#define u8GetCSCRLL(ch) (pst_u8CSCR(ch) -> u8LL)
/* LH-struct byte access */
#define vSetCSCRLH(ch,ParValue) (pst_u8CSCR(ch) -> u8LH = (ParValue))
#define u8GetCSCRLH(ch) (pst_u8CSCR(ch) -> u8LH)
/* HL-struct byte access */
#define vSetCSCRHL(ch,ParValue) (pst_u8CSCR(ch) -> u8HL = (ParValue))
#define u8GetCSCRHL(ch) (pst_u8CSCR(ch) -> u8HL)
/* HH-struct byte access */
#define vSetCSCRHH(ch,ParValue) (pst_u8CSCR(ch) -> u8HH = (ParValue))
#define u8GetCSCRHH(ch) (pst_u8CSCR(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCSCRL(ch,ParValue) (pst_u16CSCR(ch) -> u16L = (ParValue))
#define u16GetCSCRL(ch) (pst_u16CSCR(ch) -> u16L)
#define vSetCSCRH(ch,ParValue) (pst_u16CSCR(ch) -> u16H = (ParValue))
#define u16GetCSCRH(ch) (pst_u16CSCR(ch) -> u16H)
            
/* Word access */
#define vSetCSCR(ch,ParValue)  (*pu32CSCR(ch) = (ParValue))
#define u32GetCSCR(ch)  (*pu32CSCR(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CCBCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00048                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CCBCR_REG__       0xC0D00048U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   _BFA_RDB	:2; 	 /* 0..1  bit(s) R/U */
  uint32_t   BFA_RDB	:14; 	 /* 2..15  bit(s) R/U */
  uint32_t   _BCA_RDB	:2; 	 /* 16..17  bit(s) R/U */ 
  uint32_t   BCA_RDB	:14; 	 /* 18..31  bit(s) R/U */                    
} CCBCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CCBCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CCBCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CCBCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCCBCR(ch)     ((volatile CCBCR_bit_view_st *)\
(CCBCR_REG__  + ((uint16_t)(ch) * 0x10U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8CCBCR(ch)     ((volatile CCBCR_byte_view_st *)\
(CCBCR_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CCBCR(ch)     ((volatile CCBCR_halfword_view_st *)\
(CCBCR_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to WORD  */ 
#define pu32CCBCR(ch)     ((volatile u32CCBCR_word_view *)\
(CCBCR_REG__  + ((uint16_t)(ch) * 0x10U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCCBCR__BFA_RDB(ch) (pst_bitCCBCR(ch) -> _BFA_RDB)            
#define biGetCCBCR_BFA_RDB(ch) (pst_bitCCBCR(ch) -> BFA_RDB)            
#define biGetCCBCR__BCA_RDB(ch) (pst_bitCCBCR(ch) -> _BCA_RDB)            
#define biGetCCBCR_BCA_RDB(ch) (pst_bitCCBCR(ch) -> BCA_RDB)
            
/* LL-struct byte access */
#define vSetCCBCRLL(ch,ParValue) (pst_u8CCBCR(ch) -> u8LL = (ParValue))
#define u8GetCCBCRLL(ch) (pst_u8CCBCR(ch) -> u8LL)
/* LH-struct byte access */
#define vSetCCBCRLH(ch,ParValue) (pst_u8CCBCR(ch) -> u8LH = (ParValue))
#define u8GetCCBCRLH(ch) (pst_u8CCBCR(ch) -> u8LH)
/* HL-struct byte access */
#define vSetCCBCRHL(ch,ParValue) (pst_u8CCBCR(ch) -> u8HL = (ParValue))
#define u8GetCCBCRHL(ch) (pst_u8CCBCR(ch) -> u8HL)
/* HH-struct byte access */
#define vSetCCBCRHH(ch,ParValue) (pst_u8CCBCR(ch) -> u8HH = (ParValue))
#define u8GetCCBCRHH(ch) (pst_u8CCBCR(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCCBCRL(ch,ParValue) (pst_u16CCBCR(ch) -> u16L = (ParValue))
#define u16GetCCBCRL(ch) (pst_u16CCBCR(ch) -> u16L)
#define vSetCCBCRH(ch,ParValue) (pst_u16CCBCR(ch) -> u16H = (ParValue))
#define u16GetCCBCRH(ch) (pst_u16CCBCR(ch) -> u16H)
            
/* Word access */
#define vSetCCBCR(ch,ParValue)  (*pu32CCBCR(ch) = (ParValue))
#define u32GetCCBCR(ch)  (*pu32CCBCR(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CNBCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D0004C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CNBCR_REG__       0xC0D0004CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   _BEA_TDB	:2; 	 /* 0..1  bit(s) R/W */
  uint32_t   BEA_TDB	:14; 	 /* 2..15  bit(s) R/W */
  uint32_t   TDB	:2; 	 /* 16..17  bit(s) R/W */ 
  uint32_t   BSA_TDB	:14; 	 /* 18..31  bit(s) R/W */                    
} CNBCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CNBCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CNBCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CNBCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCNBCR(ch)     ((volatile CNBCR_bit_view_st *)\
(CNBCR_REG__  + ((uint16_t)(ch) * 0x10U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8CNBCR(ch)     ((volatile CNBCR_byte_view_st *)\
(CNBCR_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CNBCR(ch)     ((volatile CNBCR_halfword_view_st *)\
(CNBCR_REG__  + ((uint16_t)(ch) * 0x10U)))
            
/* Pointer to WORD  */ 
#define pu32CNBCR(ch)     ((volatile u32CNBCR_word_view *)\
(CNBCR_REG__  + ((uint16_t)(ch) * 0x10U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCNBCR__BEA_TDB(ch) (pst_bitCNBCR(ch) -> _BEA_TDB)
#define vSetCNBCR__BEA_TDB(ch,ParValue)  (pst_bitCNBCR(ch) -> _BEA_TDB=(ParValue))
#define biGetCNBCR_BEA_TDB(ch) (pst_bitCNBCR(ch) -> BEA_TDB)
#define vSetCNBCR_BEA_TDB(ch,ParValue)  (pst_bitCNBCR(ch) -> BEA_TDB=(ParValue))
#define biGetCNBCR_TDB(ch) (pst_bitCNBCR(ch) -> TDB)
#define vSetCNBCR_TDB(ch,ParValue)  (pst_bitCNBCR(ch) -> TDB=(ParValue))
#define biGetCNBCR_BSA_TDB(ch) (pst_bitCNBCR(ch) -> BSA_TDB)
#define vSetCNBCR_BSA_TDB(ch,ParValue)  (pst_bitCNBCR(ch) -> BSA_TDB=(ParValue))
            
/* LL-struct byte access */
#define vSetCNBCRLL(ch,ParValue) (pst_u8CNBCR(ch) -> u8LL = (ParValue))
#define u8GetCNBCRLL(ch) (pst_u8CNBCR(ch) -> u8LL)
/* LH-struct byte access */
#define vSetCNBCRLH(ch,ParValue) (pst_u8CNBCR(ch) -> u8LH = (ParValue))
#define u8GetCNBCRLH(ch) (pst_u8CNBCR(ch) -> u8LH)
/* HL-struct byte access */
#define vSetCNBCRHL(ch,ParValue) (pst_u8CNBCR(ch) -> u8HL = (ParValue))
#define u8GetCNBCRHL(ch) (pst_u8CNBCR(ch) -> u8HL)
/* HH-struct byte access */
#define vSetCNBCRHH(ch,ParValue) (pst_u8CNBCR(ch) -> u8HH = (ParValue))
#define u8GetCNBCRHH(ch) (pst_u8CNBCR(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCNBCRL(ch,ParValue) (pst_u16CNBCR(ch) -> u16L = (ParValue))
#define u16GetCNBCRL(ch) (pst_u16CNBCR(ch) -> u16L)
#define vSetCNBCRH(ch,ParValue) (pst_u16CNBCR(ch) -> u16H = (ParValue))
#define u16GetCNBCRH(ch) (pst_u16CNBCR(ch) -> u16H)
            
/* Word access */
#define vSetCNBCR(ch,ParValue)  (*pu32CNBCR(ch) = (ParValue))
#define u32GetCNBCR(ch)  (*pu32CNBCR(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: LCBCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0D00280                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define LCBCR_REG__       0xC0D00280U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SA	:13; 	 /* 0..12  bit(s) R/W */
  uint32_t   BD	:9; 	 /* 13..21  bit(s) R/W */ 
  uint32_t   TH	:10; 	 /* 22..31  bit(s) R/W */                    
} LCBCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} LCBCR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} LCBCR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32LCBCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitLCBCR(ch)     ((volatile LCBCR_bit_view_st *)\
(LCBCR_REG__  + ((uint16_t)(ch) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8LCBCR(ch)     ((volatile LCBCR_byte_view_st *)\
(LCBCR_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16LCBCR(ch)     ((volatile LCBCR_halfword_view_st *)\
(LCBCR_REG__  + ((uint16_t)(ch) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32LCBCR(ch)     ((volatile u32LCBCR_word_view *)\
(LCBCR_REG__  + ((uint16_t)(ch) * 0x4U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetLCBCR_SA(ch) (pst_bitLCBCR(ch) -> SA)
#define vSetLCBCR_SA(ch,ParValue)  (pst_bitLCBCR(ch) -> SA=(ParValue))
#define biGetLCBCR_BD(ch) (pst_bitLCBCR(ch) -> BD)
#define vSetLCBCR_BD(ch,ParValue)  (pst_bitLCBCR(ch) -> BD=(ParValue))
#define biGetLCBCR_TH(ch) (pst_bitLCBCR(ch) -> TH)
#define vSetLCBCR_TH(ch,ParValue)  (pst_bitLCBCR(ch) -> TH=(ParValue))
            
/* LL-struct byte access */
#define vSetLCBCRLL(ch,ParValue) (pst_u8LCBCR(ch) -> u8LL = (ParValue))
#define u8GetLCBCRLL(ch) (pst_u8LCBCR(ch) -> u8LL)
/* LH-struct byte access */
#define vSetLCBCRLH(ch,ParValue) (pst_u8LCBCR(ch) -> u8LH = (ParValue))
#define u8GetLCBCRLH(ch) (pst_u8LCBCR(ch) -> u8LH)
/* HL-struct byte access */
#define vSetLCBCRHL(ch,ParValue) (pst_u8LCBCR(ch) -> u8HL = (ParValue))
#define u8GetLCBCRHL(ch) (pst_u8LCBCR(ch) -> u8HL)
/* HH-struct byte access */
#define vSetLCBCRHH(ch,ParValue) (pst_u8LCBCR(ch) -> u8HH = (ParValue))
#define u8GetLCBCRHH(ch) (pst_u8LCBCR(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetLCBCRL(ch,ParValue) (pst_u16LCBCR(ch) -> u16L = (ParValue))
#define u16GetLCBCRL(ch) (pst_u16LCBCR(ch) -> u16L)
#define vSetLCBCRH(ch,ParValue) (pst_u16LCBCR(ch) -> u16H = (ParValue))
#define u16GetLCBCRH(ch) (pst_u16LCBCR(ch) -> u16H)
            
/* Word access */
#define vSetLCBCR(ch,ParValue)  (*pu32LCBCR(ch) = (ParValue))
#define u32GetLCBCR(ch)  (*pu32LCBCR(ch) )
            




    

#endif /* _MLBIO_H */ 
    
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

