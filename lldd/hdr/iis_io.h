
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : I2S 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:56:16.578+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.9 $ 
/  Excel Sheet ver.             : vv1.1
/  Excel Sheet date             : 2013-Jun-21
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : IIS low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : IIS
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.9 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef I2SIO_H
#define I2SIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */ 

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
#define LLDD_IIS_IO_H_REVISION     "$Revision: 1.9 $"
#define LLDD_IIS_IO_H_TAG          "$Name: LLDD_1_6 $"
     
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2SCTRL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0406000                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2SCTRL_REG__       0xC0406000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   TXRXEN	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   TXRXSEL	:1; 	 /* 1..1  bit(s) R/W */
  uint16_t   MSSLV	:1; 	 /* 2..2  bit(s) R/W */
  uint16_t   	:1; 	 /* 3..3  bit(s) R */
  uint16_t   EmptyRes	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   FullRes	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   	:2; 	 /* 6..7  bit(s) R */
  uint16_t   POL	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   WSPol	:1; 	 /* 9..9  bit(s) R/W */ 
  uint16_t   	:6; 	 /* 10..31  bit(s) R */                    
} I2SCTRL_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} I2SCTRL_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16I2SCTRL_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2SCTRL(ctrlr)     ((volatile I2SCTRL_bit_view_st *)\
(I2SCTRL_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2SCTRL(ctrlr)     ((volatile I2SCTRL_byte_view_st *)\
(I2SCTRL_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16I2SCTRL(ctrlr)     ((volatile u16I2SCTRL_halfword_view *)\
(I2SCTRL_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetI2SCTRL_TXRXEN(ctrlr) (pst_bitI2SCTRL(ctrlr) -> TXRXEN)
#define vSetI2SCTRL_TXRXEN(ctrlr,ParValue)  (pst_bitI2SCTRL(ctrlr) -> TXRXEN=(ParValue))
#define biGetI2SCTRL_TXRXSEL(ctrlr) (pst_bitI2SCTRL(ctrlr) -> TXRXSEL)
#define vSetI2SCTRL_TXRXSEL(ctrlr,ParValue)  (pst_bitI2SCTRL(ctrlr) -> TXRXSEL=(ParValue))
#define biGetI2SCTRL_MSSLV(ctrlr) (pst_bitI2SCTRL(ctrlr) -> MSSLV)
#define vSetI2SCTRL_MSSLV(ctrlr,ParValue)  (pst_bitI2SCTRL(ctrlr) -> MSSLV=(ParValue))
#define biGetI2SCTRL_EmptyRes(ctrlr) (pst_bitI2SCTRL(ctrlr) -> EmptyRes)
#define vSetI2SCTRL_EmptyRes(ctrlr,ParValue)  (pst_bitI2SCTRL(ctrlr) -> EmptyRes=(ParValue))
#define biGetI2SCTRL_FullRes(ctrlr) (pst_bitI2SCTRL(ctrlr) -> FullRes)
#define vSetI2SCTRL_FullRes(ctrlr,ParValue)  (pst_bitI2SCTRL(ctrlr) -> FullRes=(ParValue))
#define biGetI2SCTRL_POL(ctrlr) (pst_bitI2SCTRL(ctrlr) -> POL)
#define vSetI2SCTRL_POL(ctrlr,ParValue)  (pst_bitI2SCTRL(ctrlr) -> POL=(ParValue))
#define biGetI2SCTRL_WSPol(ctrlr) (pst_bitI2SCTRL(ctrlr) -> WSPol)
#define vSetI2SCTRL_WSPol(ctrlr,ParValue)  (pst_bitI2SCTRL(ctrlr) -> WSPol=(ParValue))
            
/* L-struct byte access */
#define vSetI2SCTRLL(ctrlr,ParValue) (pst_u8I2SCTRL(ctrlr) -> u8L = (ParValue))
#define u8GetI2SCTRLL(ctrlr) (pst_u8I2SCTRL(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetI2SCTRLH(ctrlr,ParValue) (pst_u8I2SCTRL(ctrlr) -> u8H = (ParValue))
#define u8GetI2SCTRLH(ctrlr) (pst_u8I2SCTRL(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetI2SCTRL(ctrlr,ParValue) (*pu16I2SCTRL(ctrlr)  = (ParValue))
#define u16GetI2SCTRL(ctrlr) (*pu16I2SCTRL(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2SLENGTH                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0406004                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2SLENGTH_REG__       0xC0406004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   WSLength	:5; 	 /* 0..4  bit(s) R/W */
  uint16_t   	:3; 	 /* 5..7  bit(s) R */
  uint16_t   DataWidth	:5; 	 /* 8..12  bit(s) R/W */ 
  uint16_t   	:3; 	 /* 13..31  bit(s) R */                    
} I2SLENGTH_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} I2SLENGTH_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16I2SLENGTH_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2SLENGTH(ctrlr)     ((volatile I2SLENGTH_bit_view_st *)\
(I2SLENGTH_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2SLENGTH(ctrlr)     ((volatile I2SLENGTH_byte_view_st *)\
(I2SLENGTH_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16I2SLENGTH(ctrlr)     ((volatile u16I2SLENGTH_halfword_view *)\
(I2SLENGTH_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetI2SLENGTH_WSLength(ctrlr) (pst_bitI2SLENGTH(ctrlr) -> WSLength)
#define vSetI2SLENGTH_WSLength(ctrlr,ParValue)  (pst_bitI2SLENGTH(ctrlr) -> WSLength=(ParValue))
#define biGetI2SLENGTH_DataWidth(ctrlr) (pst_bitI2SLENGTH(ctrlr) -> DataWidth)
#define vSetI2SLENGTH_DataWidth(ctrlr,ParValue)  (pst_bitI2SLENGTH(ctrlr) -> DataWidth=(ParValue))
            
/* L-struct byte access */
#define vSetI2SLENGTHL(ctrlr,ParValue) (pst_u8I2SLENGTH(ctrlr) -> u8L = (ParValue))
#define u8GetI2SLENGTHL(ctrlr) (pst_u8I2SLENGTH(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetI2SLENGTHH(ctrlr,ParValue) (pst_u8I2SLENGTH(ctrlr) -> u8H = (ParValue))
#define u8GetI2SLENGTHH(ctrlr) (pst_u8I2SLENGTH(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetI2SLENGTH(ctrlr,ParValue) (*pu16I2SLENGTH(ctrlr)  = (ParValue))
#define u16GetI2SLENGTH(ctrlr) (*pu16I2SLENGTH(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2SCLKCONF                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0406008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2SCLKCONF_REG__       0xC0406008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   BCLKDIV	:2; 	 /* 0..1  bit(s) R/W */
  uint32_t   LTM	:5; 	 /* 2..6  bit(s) R/W */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   MCLKDIV	:10; 	 /* 8..17  bit(s) R/W */
  uint32_t   	:2; 	 /* 18..19  bit(s) R */
  uint32_t   MCLKSRCSEL	:1; 	 /* 20..20  bit(s) R/W */
  uint32_t   MCLKOUTEN	:1; 	 /* 21..21  bit(s) R/W */
  uint32_t   	:1; 	 /* 22..22  bit(s) R */
  uint32_t   MCLKEN	:1; 	 /* 23..23  bit(s) R/W */ 
  uint32_t   	:8; 	 /* 24..31  bit(s) R */                    
} I2SCLKCONF_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} I2SCLKCONF_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} I2SCLKCONF_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32I2SCLKCONF_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2SCLKCONF(ctrlr)     ((volatile I2SCLKCONF_bit_view_st *)\
(I2SCLKCONF_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2SCLKCONF(ctrlr)     ((volatile I2SCLKCONF_byte_view_st *)\
(I2SCLKCONF_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16I2SCLKCONF(ctrlr)     ((volatile I2SCLKCONF_halfword_view_st *)\
(I2SCLKCONF_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to WORD  */ 
#define pu32I2SCLKCONF(ctrlr)     ((volatile u32I2SCLKCONF_word_view *)\
(I2SCLKCONF_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetI2SCLKCONF_BCLKDIV(ctrlr) (pst_bitI2SCLKCONF(ctrlr) -> BCLKDIV)
#define vSetI2SCLKCONF_BCLKDIV(ctrlr,ParValue)  (pst_bitI2SCLKCONF(ctrlr) -> BCLKDIV=(ParValue))
#define biGetI2SCLKCONF_LTM(ctrlr) (pst_bitI2SCLKCONF(ctrlr) -> LTM)
#define vSetI2SCLKCONF_LTM(ctrlr,ParValue)  (pst_bitI2SCLKCONF(ctrlr) -> LTM=(ParValue))
#define biGetI2SCLKCONF_MCLKDIV(ctrlr) (pst_bitI2SCLKCONF(ctrlr) -> MCLKDIV)
#define vSetI2SCLKCONF_MCLKDIV(ctrlr,ParValue)  (pst_bitI2SCLKCONF(ctrlr) -> MCLKDIV=(ParValue))
#define biGetI2SCLKCONF_MCLKSRCSEL(ctrlr) (pst_bitI2SCLKCONF(ctrlr) -> MCLKSRCSEL)
#define vSetI2SCLKCONF_MCLKSRCSEL(ctrlr,ParValue)  (pst_bitI2SCLKCONF(ctrlr) -> MCLKSRCSEL=(ParValue))
#define biGetI2SCLKCONF_MCLKOUTEN(ctrlr) (pst_bitI2SCLKCONF(ctrlr) -> MCLKOUTEN)
#define vSetI2SCLKCONF_MCLKOUTEN(ctrlr,ParValue)  (pst_bitI2SCLKCONF(ctrlr) -> MCLKOUTEN=(ParValue))
#define biGetI2SCLKCONF_MCLKEN(ctrlr) (pst_bitI2SCLKCONF(ctrlr) -> MCLKEN)
#define vSetI2SCLKCONF_MCLKEN(ctrlr,ParValue)  (pst_bitI2SCLKCONF(ctrlr) -> MCLKEN=(ParValue))
            
/* LL-struct byte access */
#define vSetI2SCLKCONFLL(ctrlr,ParValue) (pst_u8I2SCLKCONF(ctrlr) -> u8LL = (ParValue))
#define u8GetI2SCLKCONFLL(ctrlr) (pst_u8I2SCLKCONF(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetI2SCLKCONFLH(ctrlr,ParValue) (pst_u8I2SCLKCONF(ctrlr) -> u8LH = (ParValue))
#define u8GetI2SCLKCONFLH(ctrlr) (pst_u8I2SCLKCONF(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetI2SCLKCONFHL(ctrlr,ParValue) (pst_u8I2SCLKCONF(ctrlr) -> u8HL = (ParValue))
#define u8GetI2SCLKCONFHL(ctrlr) (pst_u8I2SCLKCONF(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetI2SCLKCONFHH(ctrlr,ParValue) (pst_u8I2SCLKCONF(ctrlr) -> u8HH = (ParValue))
#define u8GetI2SCLKCONFHH(ctrlr) (pst_u8I2SCLKCONF(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetI2SCLKCONFL(ctrlr,ParValue) (pst_u16I2SCLKCONF(ctrlr) -> u16L = (ParValue))
#define u16GetI2SCLKCONFL(ctrlr) (pst_u16I2SCLKCONF(ctrlr) -> u16L)
#define vSetI2SCLKCONFH(ctrlr,ParValue) (pst_u16I2SCLKCONF(ctrlr) -> u16H = (ParValue))
#define u16GetI2SCLKCONFH(ctrlr) (pst_u16I2SCLKCONF(ctrlr) -> u16H)
            
/* Word access */
#define vSetI2SCLKCONF(ctrlr,ParValue)  (*pu32I2SCLKCONF(ctrlr) = (ParValue))
#define u32GetI2SCLKCONF(ctrlr)  (*pu32I2SCLKCONF(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2SIRSTAT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC040600C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2SIRSTAT_REG__       0xC040600CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   TxAEINT	:1; 	 /* 0..0  bit(s) R */
  uint8_t   TxERROR	:1; 	 /* 1..1  bit(s) R */
  uint8_t   TxNFINT	:1; 	 /* 2..2  bit(s) R */
  uint8_t   RxAFINT	:1; 	 /* 3..3  bit(s) R */
  uint8_t   RxHFINT	:1; 	 /* 4..4  bit(s) R */
  uint8_t   RxERROR	:1; 	 /* 5..5  bit(s) R */ 
  uint8_t   	:2; 	 /* 6..31  bit(s) R */                    
} I2SIRSTAT_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8I2SIRSTAT_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2SIRSTAT(ctrlr)     ((volatile I2SIRSTAT_bit_view_st *)\
(I2SIRSTAT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8I2SIRSTAT(ctrlr)     ((volatile u8I2SIRSTAT_byte_view *)\
(I2SIRSTAT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetI2SIRSTAT_TxAEINT(ctrlr) (pst_bitI2SIRSTAT(ctrlr) -> TxAEINT)            
#define biGetI2SIRSTAT_TxERROR(ctrlr) (pst_bitI2SIRSTAT(ctrlr) -> TxERROR)            
#define biGetI2SIRSTAT_TxNFINT(ctrlr) (pst_bitI2SIRSTAT(ctrlr) -> TxNFINT)            
#define biGetI2SIRSTAT_RxAFINT(ctrlr) (pst_bitI2SIRSTAT(ctrlr) -> RxAFINT)            
#define biGetI2SIRSTAT_RxHFINT(ctrlr) (pst_bitI2SIRSTAT(ctrlr) -> RxHFINT)            
#define biGetI2SIRSTAT_RxERROR(ctrlr) (pst_bitI2SIRSTAT(ctrlr) -> RxERROR)
            
/* byte access */

#define u8GetI2SIRSTAT(ctrlr) (*pu8I2SIRSTAT(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2SIRCLR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0406010                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2SIRCLR_REG__       0xC0406010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   	:1; 	 /* 0..0  bit(s) W */
  uint8_t   TxERRORCLR	:1; 	 /* 1..1  bit(s) W */
  uint8_t   	:3; 	 /* 2..4  bit(s) W */
  uint8_t   RxERRORCLR	:1; 	 /* 5..5  bit(s) W */ 
  uint8_t   	:2; 	 /* 6..31  bit(s) W */                    
} I2SIRCLR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8I2SIRCLR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2SIRCLR(ctrlr)     ((volatile I2SIRCLR_bit_view_st *)\
(I2SIRCLR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8I2SIRCLR(ctrlr)     ((volatile u8I2SIRCLR_byte_view *)\
(I2SIRCLR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetI2SIRCLR_TxERRORCLR(ctrlr,ParValue) (pst_bitI2SIRCLR(ctrlr) -> TxERRORCLR=(ParValue)) 
#define vSetI2SIRCLR_RxERRORCLR(ctrlr,ParValue) (pst_bitI2SIRCLR(ctrlr) -> RxERRORCLR=(ParValue))
            
/* byte access */
#define vSetI2SIRCLR(ctrlr,ParValue) (*pu8I2SIRCLR(ctrlr) = (ParValue))
#define u8GetI2SIRCLR(ctrlr) (*pu8I2SIRCLR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2SIRMASK                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0406014                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2SIRMASK_REG__       0xC0406014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   TxAEMSK	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   TxERRORMSK	:1; 	 /* 1..1  bit(s) R/W */
  uint8_t   TxNFMSK	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   RxAFMSK	:1; 	 /* 3..3  bit(s) R/W */
  uint8_t   RxHFMSK	:1; 	 /* 4..4  bit(s) R/W */
  uint8_t   RxERRORMSK	:1; 	 /* 5..5  bit(s) R/W */
  uint8_t   I2SINTMSK	:1; 	 /* 6..6  bit(s) R/W */ 
  uint8_t   	:1; 	 /* 7..31  bit(s) R */                    
} I2SIRMASK_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8I2SIRMASK_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2SIRMASK(ctrlr)     ((volatile I2SIRMASK_bit_view_st *)\
(I2SIRMASK_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE  */
#define pu8I2SIRMASK(ctrlr)     ((volatile u8I2SIRMASK_byte_view *)\
(I2SIRMASK_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetI2SIRMASK_TxAEMSK(ctrlr) (pst_bitI2SIRMASK(ctrlr) -> TxAEMSK)
#define vSetI2SIRMASK_TxAEMSK(ctrlr,ParValue)  (pst_bitI2SIRMASK(ctrlr) -> TxAEMSK=(ParValue))
#define biGetI2SIRMASK_TxERRORMSK(ctrlr) (pst_bitI2SIRMASK(ctrlr) -> TxERRORMSK)
#define vSetI2SIRMASK_TxERRORMSK(ctrlr,ParValue)  (pst_bitI2SIRMASK(ctrlr) -> TxERRORMSK=(ParValue))
#define biGetI2SIRMASK_TxNFMSK(ctrlr) (pst_bitI2SIRMASK(ctrlr) -> TxNFMSK)
#define vSetI2SIRMASK_TxNFMSK(ctrlr,ParValue)  (pst_bitI2SIRMASK(ctrlr) -> TxNFMSK=(ParValue))
#define biGetI2SIRMASK_RxAFMSK(ctrlr) (pst_bitI2SIRMASK(ctrlr) -> RxAFMSK)
#define vSetI2SIRMASK_RxAFMSK(ctrlr,ParValue)  (pst_bitI2SIRMASK(ctrlr) -> RxAFMSK=(ParValue))
#define biGetI2SIRMASK_RxHFMSK(ctrlr) (pst_bitI2SIRMASK(ctrlr) -> RxHFMSK)
#define vSetI2SIRMASK_RxHFMSK(ctrlr,ParValue)  (pst_bitI2SIRMASK(ctrlr) -> RxHFMSK=(ParValue))
#define biGetI2SIRMASK_RxERRORMSK(ctrlr) (pst_bitI2SIRMASK(ctrlr) -> RxERRORMSK)
#define vSetI2SIRMASK_RxERRORMSK(ctrlr,ParValue)  (pst_bitI2SIRMASK(ctrlr) -> RxERRORMSK=(ParValue))
#define biGetI2SIRMASK_I2SINTMSK(ctrlr) (pst_bitI2SIRMASK(ctrlr) -> I2SINTMSK)
#define vSetI2SIRMASK_I2SINTMSK(ctrlr,ParValue)  (pst_bitI2SIRMASK(ctrlr) -> I2SINTMSK=(ParValue))
            
/* byte access */
#define vSetI2SIRMASK(ctrlr,ParValue) (*pu8I2SIRMASK(ctrlr) = (ParValue))
#define u8GetI2SIRMASK(ctrlr) (*pu8I2SIRMASK(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2STXDATA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0406018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2STXDATA_REG__       0xC0406018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   TxDATA	:32; 	 /* 0..31  bit(s) W */                    
} I2STXDATA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} I2STXDATA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} I2STXDATA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32I2STXDATA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2STXDATA(ctrlr)     ((volatile I2STXDATA_bit_view_st *)\
(I2STXDATA_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2STXDATA(ctrlr)     ((volatile I2STXDATA_byte_view_st *)\
(I2STXDATA_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16I2STXDATA(ctrlr)     ((volatile I2STXDATA_halfword_view_st *)\
(I2STXDATA_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to WORD  */ 
#define pu32I2STXDATA(ctrlr)     ((volatile u32I2STXDATA_word_view *)\
(I2STXDATA_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetI2STXDATA_TxDATA(ctrlr,ParValue) (pst_bitI2STXDATA(ctrlr) -> TxDATA=(ParValue))
            
/* LL-struct byte access */
#define vSetI2STXDATALL(ctrlr,ParValue) (pst_u8I2STXDATA(ctrlr) -> u8LL = (ParValue))
#define u8GetI2STXDATALL(ctrlr) (pst_u8I2STXDATA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetI2STXDATALH(ctrlr,ParValue) (pst_u8I2STXDATA(ctrlr) -> u8LH = (ParValue))
#define u8GetI2STXDATALH(ctrlr) (pst_u8I2STXDATA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetI2STXDATAHL(ctrlr,ParValue) (pst_u8I2STXDATA(ctrlr) -> u8HL = (ParValue))
#define u8GetI2STXDATAHL(ctrlr) (pst_u8I2STXDATA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetI2STXDATAHH(ctrlr,ParValue) (pst_u8I2STXDATA(ctrlr) -> u8HH = (ParValue))
#define u8GetI2STXDATAHH(ctrlr) (pst_u8I2STXDATA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetI2STXDATAL(ctrlr,ParValue) (pst_u16I2STXDATA(ctrlr) -> u16L = (ParValue))
#define u16GetI2STXDATAL(ctrlr) (pst_u16I2STXDATA(ctrlr) -> u16L)
#define vSetI2STXDATAH(ctrlr,ParValue) (pst_u16I2STXDATA(ctrlr) -> u16H = (ParValue))
#define u16GetI2STXDATAH(ctrlr) (pst_u16I2STXDATA(ctrlr) -> u16H)
            
/* Word access */
#define vSetI2STXDATA(ctrlr,ParValue)  (*pu32I2STXDATA(ctrlr) = (ParValue))
#define u32GetI2STXDATA(ctrlr)  (*pu32I2STXDATA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2SRXDATA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC040601C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2SRXDATA_REG__       0xC040601CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   RxDATA	:32; 	 /* 0..31  bit(s) R */                    
} I2SRXDATA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} I2SRXDATA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} I2SRXDATA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32I2SRXDATA_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2SRXDATA(ctrlr)     ((volatile I2SRXDATA_bit_view_st *)\
(I2SRXDATA_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2SRXDATA(ctrlr)     ((volatile I2SRXDATA_byte_view_st *)\
(I2SRXDATA_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16I2SRXDATA(ctrlr)     ((volatile I2SRXDATA_halfword_view_st *)\
(I2SRXDATA_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to WORD  */ 
#define pu32I2SRXDATA(ctrlr)     ((volatile u32I2SRXDATA_word_view *)\
(I2SRXDATA_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetI2SRXDATA_RxDATA(ctrlr) (pst_bitI2SRXDATA(ctrlr) -> RxDATA)
            
/* LL-struct byte access */

#define u8GetI2SRXDATALL(ctrlr) (pst_u8I2SRXDATA(ctrlr) -> u8LL)
/* LH-struct byte access */

#define u8GetI2SRXDATALH(ctrlr) (pst_u8I2SRXDATA(ctrlr) -> u8LH)
/* HL-struct byte access */

#define u8GetI2SRXDATAHL(ctrlr) (pst_u8I2SRXDATA(ctrlr) -> u8HL)
/* HH-struct byte access */

#define u8GetI2SRXDATAHH(ctrlr) (pst_u8I2SRXDATA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetI2SRXDATAL(ctrlr) (pst_u16I2SRXDATA(ctrlr) -> u16L)

#define u16GetI2SRXDATAH(ctrlr) (pst_u16I2SRXDATA(ctrlr) -> u16H)
            
/* Word access */

#define u32GetI2SRXDATA(ctrlr)  (*pu32I2SRXDATA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: I2SFIFOSTAT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC040603C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define I2SFIFOSTAT_REG__       0xC040603CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   RxFull	:1; 	 /* 0..0  bit(s) R */
  uint32_t   RxAF	:1; 	 /* 1..1  bit(s) R */
  uint32_t   RxHF	:1; 	 /* 2..2  bit(s) R */
  uint32_t   RxAE	:1; 	 /* 3..3  bit(s) R */
  uint32_t   RxEmpty	:1; 	 /* 4..4  bit(s) R */
  uint32_t   	:11; 	 /* 5..15  bit(s) R */
  uint32_t   TxFull	:1; 	 /* 16..16  bit(s) R */
  uint32_t   TxAF	:1; 	 /* 17..17  bit(s) R */
  uint32_t   TxHF	:1; 	 /* 18..18  bit(s) R */
  uint32_t   TxAE	:1; 	 /* 19..19  bit(s) R */
  uint32_t   TxEmpty	:1; 	 /* 20..20  bit(s) R */ 
  uint32_t   	:11; 	 /* 21..31  bit(s) R */                    
} I2SFIFOSTAT_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} I2SFIFOSTAT_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} I2SFIFOSTAT_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32I2SFIFOSTAT_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitI2SFIFOSTAT(ctrlr)     ((volatile I2SFIFOSTAT_bit_view_st *)\
(I2SFIFOSTAT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8I2SFIFOSTAT(ctrlr)     ((volatile I2SFIFOSTAT_byte_view_st *)\
(I2SFIFOSTAT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD-struct */
#define pst_u16I2SFIFOSTAT(ctrlr)     ((volatile I2SFIFOSTAT_halfword_view_st *)\
(I2SFIFOSTAT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to WORD  */ 
#define pu32I2SFIFOSTAT(ctrlr)     ((volatile u32I2SFIFOSTAT_word_view *)\
(I2SFIFOSTAT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetI2SFIFOSTAT_RxFull(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> RxFull)            
#define biGetI2SFIFOSTAT_RxAF(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> RxAF)            
#define biGetI2SFIFOSTAT_RxHF(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> RxHF)            
#define biGetI2SFIFOSTAT_RxAE(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> RxAE)            
#define biGetI2SFIFOSTAT_RxEmpty(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> RxEmpty)            
#define biGetI2SFIFOSTAT_TxFull(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> TxFull)            
#define biGetI2SFIFOSTAT_TxAF(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> TxAF)            
#define biGetI2SFIFOSTAT_TxHF(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> TxHF)            
#define biGetI2SFIFOSTAT_TxAE(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> TxAE)            
#define biGetI2SFIFOSTAT_TxEmpty(ctrlr) (pst_bitI2SFIFOSTAT(ctrlr) -> TxEmpty)
            
/* LL-struct byte access */

#define u8GetI2SFIFOSTATLL(ctrlr) (pst_u8I2SFIFOSTAT(ctrlr) -> u8LL)
/* LH-struct byte access */

#define u8GetI2SFIFOSTATLH(ctrlr) (pst_u8I2SFIFOSTAT(ctrlr) -> u8LH)
/* HL-struct byte access */

#define u8GetI2SFIFOSTATHL(ctrlr) (pst_u8I2SFIFOSTAT(ctrlr) -> u8HL)
/* HH-struct byte access */

#define u8GetI2SFIFOSTATHH(ctrlr) (pst_u8I2SFIFOSTAT(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetI2SFIFOSTATL(ctrlr) (pst_u16I2SFIFOSTAT(ctrlr) -> u16L)

#define u16GetI2SFIFOSTATH(ctrlr) (pst_u16I2SFIFOSTAT(ctrlr) -> u16H)
            
/* Word access */

#define u32GetI2SFIFOSTAT(ctrlr)  (*pu32I2SFIFOSTAT(ctrlr) )
            


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

    

#endif /* I2SIO_H */ 
    
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

