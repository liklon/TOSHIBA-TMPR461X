
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : TCAN 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:51:06.103+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.17 $ 
/  Excel Sheet ver.             : v1.1
/  Excel Sheet date             : 2013-Jun-21
/  Excel Sheet author           : ZUL
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : TXCAN low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TXCAN
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.17 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef TCANIO_H
#define TCANIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */ 

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_TXCAN_IO_H_REVISION     "$Revision: 1.17 $"
#define LLDD_TXCAN_IO_H_TAG          "$Name: LLDD_1_6 $"

/****************************************************************************
*                          CONTROLER SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
typedef enum tag_txcan_ch_def_e
{
  TXCAN_CH0__ = 0,
  TXCAN_CH1__ = 0x1000,  
  TXCAN_CH2__ = 0x2000 
} txcan_ch_def_e;

/****************************************************************************   
*                                                                               
*       REGISTER: ID_MBn                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define ID_MBn_REG__       0xC0400000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   EXT_ID	:18; 	 /* 0..17  bit(s) R/W */
  uint32_t   STD_ID	:11; 	 /* 18..28  bit(s) R/W */
  uint32_t   RFH	:1; 	 /* 29..29  bit(s) R/W */
  uint32_t   GAME	:1; 	 /* 30..30  bit(s) R/W */ 
  uint32_t   IDE	:1; 	 /* 31..31  bit(s) R/W */                    
} ID_MBn_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ID_MBn_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ID_MBn_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ID_MBn_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitID_MBn(ctrlr,ch)     ((volatile ID_MBn_bit_view_st *)\
(ID_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8ID_MBn(ctrlr,ch)     ((volatile ID_MBn_byte_view_st *)\
(ID_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16ID_MBn(ctrlr,ch)     ((volatile ID_MBn_halfword_view_st *)\
(ID_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
            
/* Pointer to WORD  */ 
#define pu32ID_MBn(ctrlr,ch)     ((volatile u32ID_MBn_word_view *)\
(ID_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetID_MBn_EXT_ID(ctrlr,ch) (pst_bitID_MBn(ctrlr,ch) -> EXT_ID)
#define vSetID_MBn_EXT_ID(ctrlr,ch,ParValue)  (pst_bitID_MBn(ctrlr,ch) -> EXT_ID=(ParValue))
#define biGetID_MBn_STD_ID(ctrlr,ch) (pst_bitID_MBn(ctrlr,ch) -> STD_ID)
#define vSetID_MBn_STD_ID(ctrlr,ch,ParValue)  (pst_bitID_MBn(ctrlr,ch) -> STD_ID=(ParValue))
#define biGetID_MBn_RFH(ctrlr,ch) (pst_bitID_MBn(ctrlr,ch) -> RFH)
#define vSetID_MBn_RFH(ctrlr,ch,ParValue)  (pst_bitID_MBn(ctrlr,ch) -> RFH=(ParValue))
#define biGetID_MBn_GAME(ctrlr,ch) (pst_bitID_MBn(ctrlr,ch) -> GAME)
#define vSetID_MBn_GAME(ctrlr,ch,ParValue)  (pst_bitID_MBn(ctrlr,ch) -> GAME=(ParValue))
#define biGetID_MBn_IDE(ctrlr,ch) (pst_bitID_MBn(ctrlr,ch) -> IDE)
#define vSetID_MBn_IDE(ctrlr,ch,ParValue)  (pst_bitID_MBn(ctrlr,ch) -> IDE=(ParValue))
            
/* LL-struct byte access */
#define vSetID_MBnLL(ctrlr,ch,ParValue) (pst_u8ID_MBn(ctrlr,ch) -> u8LL = (ParValue))
#define u8GetID_MBnLL(ctrlr,ch) (pst_u8ID_MBn(ctrlr,ch) -> u8LL)
/* LH-struct byte access */
#define vSetID_MBnLH(ctrlr,ch,ParValue) (pst_u8ID_MBn(ctrlr,ch) -> u8LH = (ParValue))
#define u8GetID_MBnLH(ctrlr,ch) (pst_u8ID_MBn(ctrlr,ch) -> u8LH)
/* HL-struct byte access */
#define vSetID_MBnHL(ctrlr,ch,ParValue) (pst_u8ID_MBn(ctrlr,ch) -> u8HL = (ParValue))
#define u8GetID_MBnHL(ctrlr,ch) (pst_u8ID_MBn(ctrlr,ch) -> u8HL)
/* HH-struct byte access */
#define vSetID_MBnHH(ctrlr,ch,ParValue) (pst_u8ID_MBn(ctrlr,ch) -> u8HH = (ParValue))
#define u8GetID_MBnHH(ctrlr,ch) (pst_u8ID_MBn(ctrlr,ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetID_MBnL(ctrlr,ch,ParValue) (pst_u16ID_MBn(ctrlr,ch) -> u16L = (ParValue))
#define u16GetID_MBnL(ctrlr,ch) (pst_u16ID_MBn(ctrlr,ch) -> u16L)
#define vSetID_MBnH(ctrlr,ch,ParValue) (pst_u16ID_MBn(ctrlr,ch) -> u16H = (ParValue))
#define u16GetID_MBnH(ctrlr,ch) (pst_u16ID_MBn(ctrlr,ch) -> u16H)
            
/* Word access */
#define vSetID_MBn(ctrlr,ch,ParValue)  (*pu32ID_MBn(ctrlr,ch) = (ParValue))
#define u32GetID_MBn(ctrlr,ch)  (*pu32ID_MBn(ctrlr,ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: FTS_MBn                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define FTS_MBn_REG__       0xC0400008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DLC	:4; 	 /* 0..3  bit(s) R/W */
  uint32_t   RTR	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   	:11; 	 /* 5..15  bit(s) R */ 
  uint32_t   TSV	:16; 	 /* 16..31  bit(s) R/W */                    
} FTS_MBn_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} FTS_MBn_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} FTS_MBn_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32FTS_MBn_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitFTS_MBn(ctrlr,ch)     ((volatile FTS_MBn_bit_view_st *)\
(FTS_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8FTS_MBn(ctrlr,ch)     ((volatile FTS_MBn_byte_view_st *)\
(FTS_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16FTS_MBn(ctrlr,ch)     ((volatile FTS_MBn_halfword_view_st *)\
(FTS_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
            
/* Pointer to WORD  */ 
#define pu32FTS_MBn(ctrlr,ch)     ((volatile u32FTS_MBn_word_view *)\
(FTS_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetFTS_MBn_DLC(ctrlr,ch) (pst_bitFTS_MBn(ctrlr,ch) -> DLC)
#define vSetFTS_MBn_DLC(ctrlr,ch,ParValue)  (pst_bitFTS_MBn(ctrlr,ch) -> DLC=(ParValue))
#define biGetFTS_MBn_RTR(ctrlr,ch) (pst_bitFTS_MBn(ctrlr,ch) -> RTR)
#define vSetFTS_MBn_RTR(ctrlr,ch,ParValue)  (pst_bitFTS_MBn(ctrlr,ch) -> RTR=(ParValue))
#define biGetFTS_MBn_TSV(ctrlr,ch) (pst_bitFTS_MBn(ctrlr,ch) -> TSV)
#define vSetFTS_MBn_TSV(ctrlr,ch,ParValue)  (pst_bitFTS_MBn(ctrlr,ch) -> TSV=(ParValue))
            
/* LL-struct byte access */
#define vSetFTS_MBnLL(ctrlr,ch,ParValue) (pst_u8FTS_MBn(ctrlr,ch) -> u8LL = (ParValue))
#define u8GetFTS_MBnLL(ctrlr,ch) (pst_u8FTS_MBn(ctrlr,ch) -> u8LL)
/* LH-struct byte access */
#define vSetFTS_MBnLH(ctrlr,ch,ParValue) (pst_u8FTS_MBn(ctrlr,ch) -> u8LH = (ParValue))
#define u8GetFTS_MBnLH(ctrlr,ch) (pst_u8FTS_MBn(ctrlr,ch) -> u8LH)
/* HL-struct byte access */
#define vSetFTS_MBnHL(ctrlr,ch,ParValue) (pst_u8FTS_MBn(ctrlr,ch) -> u8HL = (ParValue))
#define u8GetFTS_MBnHL(ctrlr,ch) (pst_u8FTS_MBn(ctrlr,ch) -> u8HL)
/* HH-struct byte access */
#define vSetFTS_MBnHH(ctrlr,ch,ParValue) (pst_u8FTS_MBn(ctrlr,ch) -> u8HH = (ParValue))
#define u8GetFTS_MBnHH(ctrlr,ch) (pst_u8FTS_MBn(ctrlr,ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetFTS_MBnL(ctrlr,ch,ParValue) (pst_u16FTS_MBn(ctrlr,ch) -> u16L = (ParValue))
#define u16GetFTS_MBnL(ctrlr,ch) (pst_u16FTS_MBn(ctrlr,ch) -> u16L)
#define vSetFTS_MBnH(ctrlr,ch,ParValue) (pst_u16FTS_MBn(ctrlr,ch) -> u16H = (ParValue))
#define u16GetFTS_MBnH(ctrlr,ch) (pst_u16FTS_MBn(ctrlr,ch) -> u16H)
            
/* Word access */
#define vSetFTS_MBn(ctrlr,ch,ParValue)  (*pu32FTS_MBn(ctrlr,ch) = (ParValue))
#define u32GetFTS_MBn(ctrlr,ch)  (*pu32FTS_MBn(ctrlr,ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DATL_MBn                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DATL_MBn_REG__       0xC0400010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D0	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   D1	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   D2	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   D3	:8; 	 /* 24..31  bit(s) R/W */                    
} DATL_MBn_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DATL_MBn_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DATL_MBn_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DATL_MBn_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDATL_MBn(ctrlr,ch)     ((volatile DATL_MBn_bit_view_st *)\
(DATL_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8DATL_MBn(ctrlr,ch)     ((volatile DATL_MBn_byte_view_st *)\
(DATL_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DATL_MBn(ctrlr,ch)     ((volatile DATL_MBn_halfword_view_st *)\
(DATL_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
            
/* Pointer to WORD  */ 
#define pu32DATL_MBn(ctrlr,ch)     ((volatile u32DATL_MBn_word_view *)\
(DATL_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDATL_MBn_D0(ctrlr,ch) (pst_bitDATL_MBn(ctrlr,ch) -> D0)
#define vSetDATL_MBn_D0(ctrlr,ch,ParValue)  (pst_bitDATL_MBn(ctrlr,ch) -> D0=(ParValue))
#define biGetDATL_MBn_D1(ctrlr,ch) (pst_bitDATL_MBn(ctrlr,ch) -> D1)
#define vSetDATL_MBn_D1(ctrlr,ch,ParValue)  (pst_bitDATL_MBn(ctrlr,ch) -> D1=(ParValue))
#define biGetDATL_MBn_D2(ctrlr,ch) (pst_bitDATL_MBn(ctrlr,ch) -> D2)
#define vSetDATL_MBn_D2(ctrlr,ch,ParValue)  (pst_bitDATL_MBn(ctrlr,ch) -> D2=(ParValue))
#define biGetDATL_MBn_D3(ctrlr,ch) (pst_bitDATL_MBn(ctrlr,ch) -> D3)
#define vSetDATL_MBn_D3(ctrlr,ch,ParValue)  (pst_bitDATL_MBn(ctrlr,ch) -> D3=(ParValue))
            
/* LL-struct byte access */
#define vSetDATL_MBnLL(ctrlr,ch,ParValue) (pst_u8DATL_MBn(ctrlr,ch) -> u8LL = (ParValue))
#define u8GetDATL_MBnLL(ctrlr,ch) (pst_u8DATL_MBn(ctrlr,ch) -> u8LL)
/* LH-struct byte access */
#define vSetDATL_MBnLH(ctrlr,ch,ParValue) (pst_u8DATL_MBn(ctrlr,ch) -> u8LH = (ParValue))
#define u8GetDATL_MBnLH(ctrlr,ch) (pst_u8DATL_MBn(ctrlr,ch) -> u8LH)
/* HL-struct byte access */
#define vSetDATL_MBnHL(ctrlr,ch,ParValue) (pst_u8DATL_MBn(ctrlr,ch) -> u8HL = (ParValue))
#define u8GetDATL_MBnHL(ctrlr,ch) (pst_u8DATL_MBn(ctrlr,ch) -> u8HL)
/* HH-struct byte access */
#define vSetDATL_MBnHH(ctrlr,ch,ParValue) (pst_u8DATL_MBn(ctrlr,ch) -> u8HH = (ParValue))
#define u8GetDATL_MBnHH(ctrlr,ch) (pst_u8DATL_MBn(ctrlr,ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDATL_MBnL(ctrlr,ch,ParValue) (pst_u16DATL_MBn(ctrlr,ch) -> u16L = (ParValue))
#define u16GetDATL_MBnL(ctrlr,ch) (pst_u16DATL_MBn(ctrlr,ch) -> u16L)
#define vSetDATL_MBnH(ctrlr,ch,ParValue) (pst_u16DATL_MBn(ctrlr,ch) -> u16H = (ParValue))
#define u16GetDATL_MBnH(ctrlr,ch) (pst_u16DATL_MBn(ctrlr,ch) -> u16H)
            
/* Word access */
#define vSetDATL_MBn(ctrlr,ch,ParValue)  (*pu32DATL_MBn(ctrlr,ch) = (ParValue))
#define u32GetDATL_MBn(ctrlr,ch)  (*pu32DATL_MBn(ctrlr,ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DATH_MBn                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DATH_MBn_REG__       0xC0400018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   D4	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   D5	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   D6	:8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   D7	:8; 	 /* 24..31  bit(s) R/W */                    
} DATH_MBn_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} DATH_MBn_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} DATH_MBn_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32DATH_MBn_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDATH_MBn(ctrlr,ch)     ((volatile DATH_MBn_bit_view_st *)\
(DATH_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8DATH_MBn(ctrlr,ch)     ((volatile DATH_MBn_byte_view_st *)\
(DATH_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16DATH_MBn(ctrlr,ch)     ((volatile DATH_MBn_halfword_view_st *)\
(DATH_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
            
/* Pointer to WORD  */ 
#define pu32DATH_MBn(ctrlr,ch)     ((volatile u32DATH_MBn_word_view *)\
(DATH_MBn_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDATH_MBn_D4(ctrlr,ch) (pst_bitDATH_MBn(ctrlr,ch) -> D4)
#define vSetDATH_MBn_D4(ctrlr,ch,ParValue)  (pst_bitDATH_MBn(ctrlr,ch) -> D4=(ParValue))
#define biGetDATH_MBn_D5(ctrlr,ch) (pst_bitDATH_MBn(ctrlr,ch) -> D5)
#define vSetDATH_MBn_D5(ctrlr,ch,ParValue)  (pst_bitDATH_MBn(ctrlr,ch) -> D5=(ParValue))
#define biGetDATH_MBn_D6(ctrlr,ch) (pst_bitDATH_MBn(ctrlr,ch) -> D6)
#define vSetDATH_MBn_D6(ctrlr,ch,ParValue)  (pst_bitDATH_MBn(ctrlr,ch) -> D6=(ParValue))
#define biGetDATH_MBn_D7(ctrlr,ch) (pst_bitDATH_MBn(ctrlr,ch) -> D7)
#define vSetDATH_MBn_D7(ctrlr,ch,ParValue)  (pst_bitDATH_MBn(ctrlr,ch) -> D7=(ParValue))
            
/* LL-struct byte access */
#define vSetDATH_MBnLL(ctrlr,ch,ParValue) (pst_u8DATH_MBn(ctrlr,ch) -> u8LL = (ParValue))
#define u8GetDATH_MBnLL(ctrlr,ch) (pst_u8DATH_MBn(ctrlr,ch) -> u8LL)
/* LH-struct byte access */
#define vSetDATH_MBnLH(ctrlr,ch,ParValue) (pst_u8DATH_MBn(ctrlr,ch) -> u8LH = (ParValue))
#define u8GetDATH_MBnLH(ctrlr,ch) (pst_u8DATH_MBn(ctrlr,ch) -> u8LH)
/* HL-struct byte access */
#define vSetDATH_MBnHL(ctrlr,ch,ParValue) (pst_u8DATH_MBn(ctrlr,ch) -> u8HL = (ParValue))
#define u8GetDATH_MBnHL(ctrlr,ch) (pst_u8DATH_MBn(ctrlr,ch) -> u8HL)
/* HH-struct byte access */
#define vSetDATH_MBnHH(ctrlr,ch,ParValue) (pst_u8DATH_MBn(ctrlr,ch) -> u8HH = (ParValue))
#define u8GetDATH_MBnHH(ctrlr,ch) (pst_u8DATH_MBn(ctrlr,ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetDATH_MBnL(ctrlr,ch,ParValue) (pst_u16DATH_MBn(ctrlr,ch) -> u16L = (ParValue))
#define u16GetDATH_MBnL(ctrlr,ch) (pst_u16DATH_MBn(ctrlr,ch) -> u16L)
#define vSetDATH_MBnH(ctrlr,ch,ParValue) (pst_u16DATH_MBn(ctrlr,ch) -> u16H = (ParValue))
#define u16GetDATH_MBnH(ctrlr,ch) (pst_u16DATH_MBn(ctrlr,ch) -> u16H)
            
/* Word access */
#define vSetDATH_MBn(ctrlr,ch,ParValue)  (*pu32DATH_MBn(ctrlr,ch) = (ParValue))
#define u32GetDATH_MBn(ctrlr,ch)  (*pu32DATH_MBn(ctrlr,ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400400                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MC_REG__       0xC0400400U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   MC	:32; 	 /* 0..31  bit(s) R/W */                    
} MC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} MC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} MC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32MC_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMC(ctrlr)     ((volatile MC_bit_view_st *)\
(MC_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8MC(ctrlr)     ((volatile MC_byte_view_st *)\
(MC_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16MC(ctrlr)     ((volatile MC_halfword_view_st *)\
(MC_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32MC(ctrlr)     ((volatile u32MC_word_view *)\
(MC_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMC_MC(ctrlr) (pst_bitMC(ctrlr) -> MC)
#define vSetMC_MC(ctrlr,ParValue)  (pst_bitMC(ctrlr) -> MC=(ParValue))
            
/* LL-struct byte access */
#define vSetMCLL(ctrlr,ParValue) (pst_u8MC(ctrlr) -> u8LL = (ParValue))
#define u8GetMCLL(ctrlr) (pst_u8MC(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetMCLH(ctrlr,ParValue) (pst_u8MC(ctrlr) -> u8LH = (ParValue))
#define u8GetMCLH(ctrlr) (pst_u8MC(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetMCHL(ctrlr,ParValue) (pst_u8MC(ctrlr) -> u8HL = (ParValue))
#define u8GetMCHL(ctrlr) (pst_u8MC(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetMCHH(ctrlr,ParValue) (pst_u8MC(ctrlr) -> u8HH = (ParValue))
#define u8GetMCHH(ctrlr) (pst_u8MC(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetMCL(ctrlr,ParValue) (pst_u16MC(ctrlr) -> u16L = (ParValue))
#define u16GetMCL(ctrlr) (pst_u16MC(ctrlr) -> u16L)
#define vSetMCH(ctrlr,ParValue) (pst_u16MC(ctrlr) -> u16H = (ParValue))
#define u16GetMCH(ctrlr) (pst_u16MC(ctrlr) -> u16H)
            
/* Word access */
#define vSetMC(ctrlr,ParValue)  (*pu32MC(ctrlr) = (ParValue))
#define u32GetMC(ctrlr)  (*pu32MC(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MD                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400408                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MD_REG__       0xC0400408U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MD	:31; 	 /* 0..30  bit(s) R/W */ 
  uint32_t   MD31	:1; 	 /* 31..31  bit(s) R */                    
} MD_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} MD_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} MD_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32MD_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMD(ctrlr)     ((volatile MD_bit_view_st *)\
(MD_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8MD(ctrlr)     ((volatile MD_byte_view_st *)\
(MD_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16MD(ctrlr)     ((volatile MD_halfword_view_st *)\
(MD_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32MD(ctrlr)     ((volatile u32MD_word_view *)\
(MD_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMD_MD(ctrlr) (pst_bitMD(ctrlr) -> MD)
#define vSetMD_MD(ctrlr,ParValue)  (pst_bitMD(ctrlr) -> MD=(ParValue))            
#define biGetMD_MD31(ctrlr) (pst_bitMD(ctrlr) -> MD31)
            
/* LL-struct byte access */
#define vSetMDLL(ctrlr,ParValue) (pst_u8MD(ctrlr) -> u8LL = (ParValue))
#define u8GetMDLL(ctrlr) (pst_u8MD(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetMDLH(ctrlr,ParValue) (pst_u8MD(ctrlr) -> u8LH = (ParValue))
#define u8GetMDLH(ctrlr) (pst_u8MD(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetMDHL(ctrlr,ParValue) (pst_u8MD(ctrlr) -> u8HL = (ParValue))
#define u8GetMDHL(ctrlr) (pst_u8MD(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetMDHH(ctrlr,ParValue) (pst_u8MD(ctrlr) -> u8HH = (ParValue))
#define u8GetMDHH(ctrlr) (pst_u8MD(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetMDL(ctrlr,ParValue) (pst_u16MD(ctrlr) -> u16L = (ParValue))
#define u16GetMDL(ctrlr) (pst_u16MD(ctrlr) -> u16L)
#define vSetMDH(ctrlr,ParValue) (pst_u16MD(ctrlr) -> u16H = (ParValue))
#define u16GetMDH(ctrlr) (pst_u16MD(ctrlr) -> u16H)
            
/* Word access */
#define vSetMD(ctrlr,ParValue)  (*pu32MD(ctrlr) = (ParValue))
#define u32GetMD(ctrlr)  (*pu32MD(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: TRS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400410                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TRS_REG__       0xC0400410U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   TRS	:31; 	 /* 0..30  bit(s) R/S */ 
  uint32_t   	:1; 	 /* 31..31  bit(s) R */                    
} TRS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} TRS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} TRS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32TRS_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTRS(ctrlr)     ((volatile TRS_bit_view_st *)\
(TRS_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TRS(ctrlr)     ((volatile TRS_byte_view_st *)\
(TRS_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16TRS(ctrlr)     ((volatile TRS_halfword_view_st *)\
(TRS_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32TRS(ctrlr)     ((volatile u32TRS_word_view *)\
(TRS_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetTRS_TRS(ctrlr) (pst_bitTRS(ctrlr) -> TRS)
#define vSetTRS_TRS(ctrlr) (pst_bitTRS(ctrlr) -> TRS=(1))
            
/* LL-struct byte access */
#define vSetTRSLL(ctrlr,ParValue) (pst_u8TRS(ctrlr) -> u8LL = (ParValue))
#define u8GetTRSLL(ctrlr) (pst_u8TRS(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetTRSLH(ctrlr,ParValue) (pst_u8TRS(ctrlr) -> u8LH = (ParValue))
#define u8GetTRSLH(ctrlr) (pst_u8TRS(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetTRSHL(ctrlr,ParValue) (pst_u8TRS(ctrlr) -> u8HL = (ParValue))
#define u8GetTRSHL(ctrlr) (pst_u8TRS(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetTRSHH(ctrlr,ParValue) (pst_u8TRS(ctrlr) -> u8HH = (ParValue))
#define u8GetTRSHH(ctrlr) (pst_u8TRS(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetTRSL(ctrlr,ParValue) (pst_u16TRS(ctrlr) -> u16L = (ParValue))
#define u16GetTRSL(ctrlr) (pst_u16TRS(ctrlr) -> u16L)
#define vSetTRSH(ctrlr,ParValue) (pst_u16TRS(ctrlr) -> u16H = (ParValue))
#define u16GetTRSH(ctrlr) (pst_u16TRS(ctrlr) -> u16H)
            
/* Word access */
#define vSetTRS(ctrlr,ParValue)  (*pu32TRS(ctrlr) = (ParValue))
#define u32GetTRS(ctrlr)  (*pu32TRS(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: TRR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400418                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TRR_REG__       0xC0400418U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   TRR	:31; 	 /* 0..30  bit(s) R/S */ 
  uint32_t   	:1; 	 /* 31..31  bit(s) R */                    
} TRR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} TRR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} TRR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32TRR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTRR(ctrlr)     ((volatile TRR_bit_view_st *)\
(TRR_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TRR(ctrlr)     ((volatile TRR_byte_view_st *)\
(TRR_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16TRR(ctrlr)     ((volatile TRR_halfword_view_st *)\
(TRR_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32TRR(ctrlr)     ((volatile u32TRR_word_view *)\
(TRR_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetTRR_TRR(ctrlr) (pst_bitTRR(ctrlr) -> TRR)
#define vSetTRR_TRR(ctrlr) (pst_bitTRR(ctrlr) -> TRR=(1))
            
/* LL-struct byte access */
#define vSetTRRLL(ctrlr,ParValue) (pst_u8TRR(ctrlr) -> u8LL = (ParValue))
#define u8GetTRRLL(ctrlr) (pst_u8TRR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetTRRLH(ctrlr,ParValue) (pst_u8TRR(ctrlr) -> u8LH = (ParValue))
#define u8GetTRRLH(ctrlr) (pst_u8TRR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetTRRHL(ctrlr,ParValue) (pst_u8TRR(ctrlr) -> u8HL = (ParValue))
#define u8GetTRRHL(ctrlr) (pst_u8TRR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetTRRHH(ctrlr,ParValue) (pst_u8TRR(ctrlr) -> u8HH = (ParValue))
#define u8GetTRRHH(ctrlr) (pst_u8TRR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetTRRL(ctrlr,ParValue) (pst_u16TRR(ctrlr) -> u16L = (ParValue))
#define u16GetTRRL(ctrlr) (pst_u16TRR(ctrlr) -> u16L)
#define vSetTRRH(ctrlr,ParValue) (pst_u16TRR(ctrlr) -> u16H = (ParValue))
#define u16GetTRRH(ctrlr) (pst_u16TRR(ctrlr) -> u16H)
            
/* Word access */
#define vSetTRR(ctrlr,ParValue)  (*pu32TRR(ctrlr) = (ParValue))
#define u32GetTRR(ctrlr)  (*pu32TRR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: TA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400420                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TA_REG__       0xC0400420U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   TA	:31; 	 /* 0..30  bit(s) R/W1C */ 
  uint32_t   	:1; 	 /* 31..31  bit(s) R */                    
} TA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} TA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} TA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32TA_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTA(ctrlr)     ((volatile TA_bit_view_st *)\
(TA_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TA(ctrlr)     ((volatile TA_byte_view_st *)\
(TA_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16TA(ctrlr)     ((volatile TA_halfword_view_st *)\
(TA_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32TA(ctrlr)     ((volatile u32TA_word_view *)\
(TA_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetTA_TA(ctrlr) (pst_bitTA(ctrlr) -> TA)
/*---------------------------------------------------------------------------*/
/* SRA: Clr function can be applied for bit 0..30: */
#define vClrTA_TA(ctrlr, BitNo) (pst_bitTA(ctrlr) -> TA = ( (0x00000001 << BitNo) & 0x7FFFFFFFU)) )
/* SRA: Clr funnction for multiple bits can be applied for multiple interrupt 0..30: */
#define vClrMultiTA_TA(ctrlr, Mask) (pst_bitTA(ctrlr) -> TA = (Mask & 0x7FFFFFFFU))
/*---------------------------------------------------------------------------*/

/* LL-struct byte access */
#define vSetTALL(ctrlr,ParValue) (pst_u8TA(ctrlr) -> u8LL = (ParValue))
#define u8GetTALL(ctrlr) (pst_u8TA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetTALH(ctrlr,ParValue) (pst_u8TA(ctrlr) -> u8LH = (ParValue))
#define u8GetTALH(ctrlr) (pst_u8TA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetTAHL(ctrlr,ParValue) (pst_u8TA(ctrlr) -> u8HL = (ParValue))
#define u8GetTAHL(ctrlr) (pst_u8TA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetTAHH(ctrlr,ParValue) (pst_u8TA(ctrlr) -> u8HH = (ParValue))
#define u8GetTAHH(ctrlr) (pst_u8TA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetTAL(ctrlr,ParValue) (pst_u16TA(ctrlr) -> u16L = (ParValue))
#define u16GetTAL(ctrlr) (pst_u16TA(ctrlr) -> u16L)
#define vSetTAH(ctrlr,ParValue) (pst_u16TA(ctrlr) -> u16H = (ParValue))
#define u16GetTAH(ctrlr) (pst_u16TA(ctrlr) -> u16H)
            
/* Word access */
#define vSetTA(ctrlr,ParValue)  (*pu32TA(ctrlr) = (ParValue))
#define u32GetTA(ctrlr)  (*pu32TA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: AA                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400428                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define AA_REG__       0xC0400428U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   AA	:31; 	 /* 0..30  bit(s) R/W1C */ 
  uint32_t   	:1; 	 /* 31..31  bit(s) R */                    
} AA_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} AA_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} AA_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32AA_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitAA(ctrlr)     ((volatile AA_bit_view_st *)\
(AA_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8AA(ctrlr)     ((volatile AA_byte_view_st *)\
(AA_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16AA(ctrlr)     ((volatile AA_halfword_view_st *)\
(AA_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32AA(ctrlr)     ((volatile u32AA_word_view *)\
(AA_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetAA_AA(ctrlr) (pst_bitAA(ctrlr) -> AA)
/*---------------------------------------------------------------------------*/
/* SRA: Clr function can be applied for bit 0..30: */
#define vClrAA_AA(ctrlr, BitNo) (pst_bitAA(ctrlr) -> AA = ( (0x00000001 << BitNo) & 0x7FFFFFFFU)) )
/* SRA: Clr funnction for multiple bits can be applied for multiple interrupt 0..30: */
#define vClrMultiAA_AA(ctrlr, Mask) (pst_bitAA(ctrlr) -> AA = (Mask & 0x7FFFFFFFU))
/*---------------------------------------------------------------------------*/
            
/* LL-struct byte access */
#define vSetAALL(ctrlr,ParValue) (pst_u8AA(ctrlr) -> u8LL = (ParValue))
#define u8GetAALL(ctrlr) (pst_u8AA(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetAALH(ctrlr,ParValue) (pst_u8AA(ctrlr) -> u8LH = (ParValue))
#define u8GetAALH(ctrlr) (pst_u8AA(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetAAHL(ctrlr,ParValue) (pst_u8AA(ctrlr) -> u8HL = (ParValue))
#define u8GetAAHL(ctrlr) (pst_u8AA(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetAAHH(ctrlr,ParValue) (pst_u8AA(ctrlr) -> u8HH = (ParValue))
#define u8GetAAHH(ctrlr) (pst_u8AA(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetAAL(ctrlr,ParValue) (pst_u16AA(ctrlr) -> u16L = (ParValue))
#define u16GetAAL(ctrlr) (pst_u16AA(ctrlr) -> u16L)
#define vSetAAH(ctrlr,ParValue) (pst_u16AA(ctrlr) -> u16H = (ParValue))
#define u16GetAAH(ctrlr) (pst_u16AA(ctrlr) -> u16H)
            
/* Word access */
#define vSetAA(ctrlr,ParValue)  (*pu32AA(ctrlr) = (ParValue))
#define u32GetAA(ctrlr)  (*pu32AA(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RMP                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400430                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RMP_REG__       0xC0400430U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   RMP	:32; 	 /* 0..31  bit(s) R/W1C */                    
} RMP_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} RMP_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} RMP_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32RMP_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRMP(ctrlr)     ((volatile RMP_bit_view_st *)\
(RMP_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8RMP(ctrlr)     ((volatile RMP_byte_view_st *)\
(RMP_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16RMP(ctrlr)     ((volatile RMP_halfword_view_st *)\
(RMP_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32RMP(ctrlr)     ((volatile u32RMP_word_view *)\
(RMP_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRMP_RMP(ctrlr) (pst_bitRMP(ctrlr) -> RMP)
/*---------------------------------------------------------------------------*/
/* SRA: Clr funnction can be applied for bit 0..31: */
#define vClrRMP_RMP(ctrlr, BitNo) (pst_bitRMP(ctrlr) -> RMP = (0x00000001 << BitNo))
/* SRA: Clr funnction for multiple bits can be applied for multiple interrupt 0..31: */
#define vClrMultiRMP_RMP(ctrlr, Mask) (pst_bitRMP(ctrlr) -> RMP = (Mask))
/*---------------------------------------------------------------------------*/
           
/* LL-struct byte access */
#define vSetRMPLL(ctrlr,ParValue) (pst_u8RMP(ctrlr) -> u8LL = (ParValue))
#define u8GetRMPLL(ctrlr) (pst_u8RMP(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetRMPLH(ctrlr,ParValue) (pst_u8RMP(ctrlr) -> u8LH = (ParValue))
#define u8GetRMPLH(ctrlr) (pst_u8RMP(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetRMPHL(ctrlr,ParValue) (pst_u8RMP(ctrlr) -> u8HL = (ParValue))
#define u8GetRMPHL(ctrlr) (pst_u8RMP(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetRMPHH(ctrlr,ParValue) (pst_u8RMP(ctrlr) -> u8HH = (ParValue))
#define u8GetRMPHH(ctrlr) (pst_u8RMP(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetRMPL(ctrlr,ParValue) (pst_u16RMP(ctrlr) -> u16L = (ParValue))
#define u16GetRMPL(ctrlr) (pst_u16RMP(ctrlr) -> u16L)
#define vSetRMPH(ctrlr,ParValue) (pst_u16RMP(ctrlr) -> u16H = (ParValue))
#define u16GetRMPH(ctrlr) (pst_u16RMP(ctrlr) -> u16H)
            
/* Word access */
#define vSetRMP(ctrlr,ParValue)  (*pu32RMP(ctrlr) = (ParValue))
#define u32GetRMP(ctrlr)  (*pu32RMP(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RML                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400438                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RML_REG__       0xC0400438U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   RML	:32; 	 /* 0..31  bit(s) R/W1C */                    
} RML_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} RML_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} RML_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32RML_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRML(ctrlr)     ((volatile RML_bit_view_st *)\
(RML_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8RML(ctrlr)     ((volatile RML_byte_view_st *)\
(RML_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16RML(ctrlr)     ((volatile RML_halfword_view_st *)\
(RML_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32RML(ctrlr)     ((volatile u32RML_word_view *)\
(RML_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRML_RML(ctrlr) (pst_bitRML(ctrlr) -> RML)
/*---------------------------------------------------------------------------*/
/* SRA: Clr funnction can be applied for bit 0..31: */
#define vClrRML_RML(ctrlr, BitNo) (pst_bitRML(ctrlr) -> RML = (0x00000001 << BitNo))
/* SRA: Clr funnction for multiple bits can be applied for multiple interrupt 0..31: */
#define vClrMultiRML_RML(ctrlr, Mask) (pst_bitRML(ctrlr) -> RML = (Mask))
/*---------------------------------------------------------------------------*/
            
/* LL-struct byte access */
#define vSetRMLLL(ctrlr,ParValue) (pst_u8RML(ctrlr) -> u8LL = (ParValue))
#define u8GetRMLLL(ctrlr) (pst_u8RML(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetRMLLH(ctrlr,ParValue) (pst_u8RML(ctrlr) -> u8LH = (ParValue))
#define u8GetRMLLH(ctrlr) (pst_u8RML(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetRMLHL(ctrlr,ParValue) (pst_u8RML(ctrlr) -> u8HL = (ParValue))
#define u8GetRMLHL(ctrlr) (pst_u8RML(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetRMLHH(ctrlr,ParValue) (pst_u8RML(ctrlr) -> u8HH = (ParValue))
#define u8GetRMLHH(ctrlr) (pst_u8RML(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetRMLL(ctrlr,ParValue) (pst_u16RML(ctrlr) -> u16L = (ParValue))
#define u16GetRMLL(ctrlr) (pst_u16RML(ctrlr) -> u16L)
#define vSetRMLH(ctrlr,ParValue) (pst_u16RML(ctrlr) -> u16H = (ParValue))
#define u16GetRMLH(ctrlr) (pst_u16RML(ctrlr) -> u16H)
            
/* Word access */
#define vSetRML(ctrlr,ParValue)  (*pu32RML(ctrlr) = (ParValue))
#define u32GetRML(ctrlr)  (*pu32RML(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400450                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MCR_REG__       0xC0400450U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   SRES	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   TSCC	:1; 	 /* 1..1  bit(s) R/W */
  uint16_t   	:1; 	 /* 2..2  bit(s) R */
  uint16_t   MTOS	:1; 	 /* 3..3  bit(s) R/W */
  uint16_t   WUBA	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   TSBTEST	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   SMR	:1; 	 /* 6..6  bit(s) R/W */
  uint16_t   CCR	:1; 	 /* 7..7  bit(s) R/W */
  uint16_t   TSTERR	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   TSTLB	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   INTLB	:1; 	 /* 10..10  bit(s) R/W */
  uint16_t   SUR	:1; 	 /* 11..11  bit(s) R/W */ 
  uint16_t   	:4; 	 /* 12..31  bit(s) R */                    
} MCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} MCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16MCR_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMCR(ctrlr)     ((volatile MCR_bit_view_st *)\
(MCR_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8MCR(ctrlr)     ((volatile MCR_byte_view_st *)\
(MCR_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16MCR(ctrlr)     ((volatile u16MCR_halfword_view *)\
(MCR_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMCR_SRES(ctrlr) (pst_bitMCR(ctrlr) -> SRES)
#define vSetMCR_SRES(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> SRES=(ParValue))
#define biGetMCR_TSCC(ctrlr) (pst_bitMCR(ctrlr) -> TSCC)
#define vSetMCR_TSCC(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> TSCC=(ParValue))
#define biGetMCR_MTOS(ctrlr) (pst_bitMCR(ctrlr) -> MTOS)
#define vSetMCR_MTOS(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> MTOS=(ParValue))
#define biGetMCR_WUBA(ctrlr) (pst_bitMCR(ctrlr) -> WUBA)
#define vSetMCR_WUBA(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> WUBA=(ParValue))
#define biGetMCR_TSBTEST(ctrlr) (pst_bitMCR(ctrlr) -> TSBTEST)
#define vSetMCR_TSBTEST(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> TSBTEST=(ParValue))
#define biGetMCR_SMR(ctrlr) (pst_bitMCR(ctrlr) -> SMR)
#define vSetMCR_SMR(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> SMR=(ParValue))
#define biGetMCR_CCR(ctrlr) (pst_bitMCR(ctrlr) -> CCR)
#define vSetMCR_CCR(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> CCR=(ParValue))
#define biGetMCR_TSTERR(ctrlr) (pst_bitMCR(ctrlr) -> TSTERR)
#define vSetMCR_TSTERR(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> TSTERR=(ParValue))
#define biGetMCR_TSTLB(ctrlr) (pst_bitMCR(ctrlr) -> TSTLB)
#define vSetMCR_TSTLB(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> TSTLB=(ParValue))
#define biGetMCR_INTLB(ctrlr) (pst_bitMCR(ctrlr) -> INTLB)
#define vSetMCR_INTLB(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> INTLB=(ParValue))
#define biGetMCR_SUR(ctrlr) (pst_bitMCR(ctrlr) -> SUR)
#define vSetMCR_SUR(ctrlr,ParValue)  (pst_bitMCR(ctrlr) -> SUR=(ParValue))
            
/* L-struct byte access */
#define vSetMCRL(ctrlr,ParValue) (pst_u8MCR(ctrlr) -> u8L = (ParValue))
#define u8GetMCRL(ctrlr) (pst_u8MCR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetMCRH(ctrlr,ParValue) (pst_u8MCR(ctrlr) -> u8H = (ParValue))
#define u8GetMCRH(ctrlr) (pst_u8MCR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetMCR(ctrlr,ParValue) (*pu16MCR(ctrlr)  = (ParValue))
#define u16GetMCR(ctrlr) (*pu16MCR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GSR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400458                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define GSR_REG__       0xC0400458U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   EW	:1; 	 /* 0..0  bit(s) R */
  uint32_t   EP	:1; 	 /* 1..1  bit(s) R */
  uint32_t   BO	:1; 	 /* 2..2  bit(s) R */
  uint32_t   TSO	:1; 	 /* 3..3  bit(s) R */
  uint32_t   	:2; 	 /* 4..5  bit(s) R */
  uint32_t   SMA	:1; 	 /* 6..6  bit(s) R */
  uint32_t   CCE	:1; 	 /* 7..7  bit(s) R */
  uint32_t   SUA	:1; 	 /* 8..8  bit(s) R */
  uint32_t   	:1; 	 /* 9..9  bit(s) R */
  uint32_t   TM	:1; 	 /* 10..10  bit(s) R */
  uint32_t   RM	:1; 	 /* 11..11  bit(s) R */
  uint32_t   MIS	:5; 	 /* 12..16  bit(s) R */ 
  uint32_t   	:15; 	 /* 17..31  bit(s) R */                    
} GSR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GSR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} GSR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GSR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGSR(ctrlr)     ((volatile GSR_bit_view_st *)\
(GSR_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8GSR(ctrlr)     ((volatile GSR_byte_view_st *)\
(GSR_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GSR(ctrlr)     ((volatile GSR_halfword_view_st *)\
(GSR_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32GSR(ctrlr)     ((volatile u32GSR_word_view *)\
(GSR_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGSR_EW(ctrlr) (pst_bitGSR(ctrlr) -> EW)            
#define biGetGSR_EP(ctrlr) (pst_bitGSR(ctrlr) -> EP)            
#define biGetGSR_BO(ctrlr) (pst_bitGSR(ctrlr) -> BO)            
#define biGetGSR_TSO(ctrlr) (pst_bitGSR(ctrlr) -> TSO)            
#define biGetGSR_SMA(ctrlr) (pst_bitGSR(ctrlr) -> SMA)            
#define biGetGSR_CCE(ctrlr) (pst_bitGSR(ctrlr) -> CCE)            
#define biGetGSR_SUA(ctrlr) (pst_bitGSR(ctrlr) -> SUA)            
#define biGetGSR_TM(ctrlr) (pst_bitGSR(ctrlr) -> TM)            
#define biGetGSR_RM(ctrlr) (pst_bitGSR(ctrlr) -> RM)            
#define biGetGSR_MIS(ctrlr) (pst_bitGSR(ctrlr) -> MIS)
            
/* LL-struct byte access */

#define u8GetGSRLL(ctrlr) (pst_u8GSR(ctrlr) -> u8LL)
/* LH-struct byte access */

#define u8GetGSRLH(ctrlr) (pst_u8GSR(ctrlr) -> u8LH)
/* HL-struct byte access */

#define u8GetGSRHL(ctrlr) (pst_u8GSR(ctrlr) -> u8HL)
/* HH-struct byte access */

#define u8GetGSRHH(ctrlr) (pst_u8GSR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetGSRL(ctrlr) (pst_u16GSR(ctrlr) -> u16L)

#define u16GetGSRH(ctrlr) (pst_u16GSR(ctrlr) -> u16H)
            
/* Word access */

#define u32GetGSR(ctrlr)  (*pu32GSR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: BCR1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400460                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define BCR1_REG__       0xC0400460U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   BRP	:10; 	 /* 0..9  bit(s) R/W */ 
  uint16_t   	:6; 	 /* 10..31  bit(s) R */                    
} BCR1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} BCR1_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16BCR1_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitBCR1(ctrlr)     ((volatile BCR1_bit_view_st *)\
(BCR1_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8BCR1(ctrlr)     ((volatile BCR1_byte_view_st *)\
(BCR1_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16BCR1(ctrlr)     ((volatile u16BCR1_halfword_view *)\
(BCR1_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetBCR1_BRP(ctrlr) (pst_bitBCR1(ctrlr) -> BRP)
#define vSetBCR1_BRP(ctrlr,ParValue)  (pst_bitBCR1(ctrlr) -> BRP=(ParValue))
            
/* L-struct byte access */
#define vSetBCR1L(ctrlr,ParValue) (pst_u8BCR1(ctrlr) -> u8L = (ParValue))
#define u8GetBCR1L(ctrlr) (pst_u8BCR1(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetBCR1H(ctrlr,ParValue) (pst_u8BCR1(ctrlr) -> u8H = (ParValue))
#define u8GetBCR1H(ctrlr) (pst_u8BCR1(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetBCR1(ctrlr,ParValue) (*pu16BCR1(ctrlr)  = (ParValue))
#define u16GetBCR1(ctrlr) (*pu16BCR1(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: BCR2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400468                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define BCR2_REG__       0xC0400468U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   TSEG1	:4; 	 /* 0..3  bit(s) R/W */
  uint16_t   TSEG2	:3; 	 /* 4..6  bit(s) R/W */
  uint16_t   SAM	:1; 	 /* 7..7  bit(s) R/W */
  uint16_t   SJW	:2; 	 /* 8..9  bit(s) R/W */ 
  uint16_t   	:6; 	 /* 10..31  bit(s) R */                    
} BCR2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} BCR2_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16BCR2_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitBCR2(ctrlr)     ((volatile BCR2_bit_view_st *)\
(BCR2_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8BCR2(ctrlr)     ((volatile BCR2_byte_view_st *)\
(BCR2_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16BCR2(ctrlr)     ((volatile u16BCR2_halfword_view *)\
(BCR2_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetBCR2_TSEG1(ctrlr) (pst_bitBCR2(ctrlr) -> TSEG1)
#define vSetBCR2_TSEG1(ctrlr,ParValue)  (pst_bitBCR2(ctrlr) -> TSEG1=(ParValue))
#define biGetBCR2_TSEG2(ctrlr) (pst_bitBCR2(ctrlr) -> TSEG2)
#define vSetBCR2_TSEG2(ctrlr,ParValue)  (pst_bitBCR2(ctrlr) -> TSEG2=(ParValue))
#define biGetBCR2_SAM(ctrlr) (pst_bitBCR2(ctrlr) -> SAM)
#define vSetBCR2_SAM(ctrlr,ParValue)  (pst_bitBCR2(ctrlr) -> SAM=(ParValue))
#define biGetBCR2_SJW(ctrlr) (pst_bitBCR2(ctrlr) -> SJW)
#define vSetBCR2_SJW(ctrlr,ParValue)  (pst_bitBCR2(ctrlr) -> SJW=(ParValue))
            
/* L-struct byte access */
#define vSetBCR2L(ctrlr,ParValue) (pst_u8BCR2(ctrlr) -> u8L = (ParValue))
#define u8GetBCR2L(ctrlr) (pst_u8BCR2(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetBCR2H(ctrlr,ParValue) (pst_u8BCR2(ctrlr) -> u8H = (ParValue))
#define u8GetBCR2H(ctrlr) (pst_u8BCR2(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetBCR2(ctrlr,ParValue) (*pu16BCR2(ctrlr)  = (ParValue))
#define u16GetBCR2(ctrlr) (*pu16BCR2(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GIF                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400470                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define GIF_REG__       0xC0400470U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   WLIF	:1; 	 /* 0..0  bit(s) R/W1C */
  uint8_t   EPIF	:1; 	 /* 1..1  bit(s) R/W1C */
  uint8_t   BOIF	:1; 	 /* 2..2  bit(s) R/W1C */
  uint8_t   TSOIF	:1; 	 /* 3..3  bit(s) R/W1C */
  uint8_t   TRMABF	:1; 	 /* 4..4  bit(s) R/W1C */
  uint8_t   RMLIF	:1; 	 /* 5..5  bit(s) R/W1C */
  uint8_t   WUIF	:1; 	 /* 6..6  bit(s) R/W1C */
  uint8_t   RFPF	:1; 	 /* 7..7  bit(s) R/W1C */                    
} GIF_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GIF_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGIF(ctrlr)     ((volatile GIF_bit_view_st *)\
(GIF_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE  */
#define pu8GIF(ctrlr)     ((volatile u8GIF_byte_view *)\
(GIF_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGIF_WLIF(ctrlr) (pst_bitGIF(ctrlr) -> WLIF)
#define vClrGIF_WLIF(ctrlr) (pst_bitGIF(ctrlr) -> WLIF = (1))
#define biGetGIF_EPIF(ctrlr) (pst_bitGIF(ctrlr) -> EPIF)
#define vClrGIF_EPIF(ctrlr) (pst_bitGIF(ctrlr) -> EPIF = (1))
#define biGetGIF_BOIF(ctrlr) (pst_bitGIF(ctrlr) -> BOIF)
#define vClrGIF_BOIF(ctrlr) (pst_bitGIF(ctrlr) -> BOIF = (1))
#define biGetGIF_TSOIF(ctrlr) (pst_bitGIF(ctrlr) -> TSOIF)
#define vClrGIF_TSOIF(ctrlr) (pst_bitGIF(ctrlr) -> TSOIF = (1))
#define biGetGIF_TRMABF(ctrlr) (pst_bitGIF(ctrlr) -> TRMABF)
#define vClrGIF_TRMABF(ctrlr) (pst_bitGIF(ctrlr) -> TRMABF = (1))
#define biGetGIF_RMLIF(ctrlr) (pst_bitGIF(ctrlr) -> RMLIF)
#define vClrGIF_RMLIF(ctrlr) (pst_bitGIF(ctrlr) -> RMLIF = (1))
#define biGetGIF_WUIF(ctrlr) (pst_bitGIF(ctrlr) -> WUIF)
#define vClrGIF_WUIF(ctrlr) (pst_bitGIF(ctrlr) -> WUIF = (1))
#define biGetGIF_RFPF(ctrlr) (pst_bitGIF(ctrlr) -> RFPF)
#define vClrGIF_RFPF(ctrlr) (pst_bitGIF(ctrlr) -> RFPF = (1))
            
/* byte access */
#define vSetGIF(ctrlr,ParValue) (*pu8GIF(ctrlr) = (ParValue))
#define u8GetGIF(ctrlr) (*pu8GIF(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: GIM                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400478                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define GIM_REG__       0xC0400478U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   WLIM	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   EPIM	:1; 	 /* 1..1  bit(s) R/W */
  uint8_t   BOIM	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   TSOIM	:1; 	 /* 3..3  bit(s) R/W */
  uint8_t   TRMABFM	:1; 	 /* 4..4  bit(s) R/W */
  uint8_t   RMLIM	:1; 	 /* 5..5  bit(s) R/W */
  uint8_t   WUIM	:1; 	 /* 6..6  bit(s) R/W */
  uint8_t   RFPM	:1; 	 /* 7..7  bit(s) R/W */                    
} GIM_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8GIM_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGIM(ctrlr)     ((volatile GIM_bit_view_st *)\
(GIM_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE  */
#define pu8GIM(ctrlr)     ((volatile u8GIM_byte_view *)\
(GIM_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGIM_WLIM(ctrlr) (pst_bitGIM(ctrlr) -> WLIM)
#define vSetGIM_WLIM(ctrlr,ParValue)  (pst_bitGIM(ctrlr) -> WLIM=(ParValue))
#define biGetGIM_EPIM(ctrlr) (pst_bitGIM(ctrlr) -> EPIM)
#define vSetGIM_EPIM(ctrlr,ParValue)  (pst_bitGIM(ctrlr) -> EPIM=(ParValue))
#define biGetGIM_BOIM(ctrlr) (pst_bitGIM(ctrlr) -> BOIM)
#define vSetGIM_BOIM(ctrlr,ParValue)  (pst_bitGIM(ctrlr) -> BOIM=(ParValue))
#define biGetGIM_TSOIM(ctrlr) (pst_bitGIM(ctrlr) -> TSOIM)
#define vSetGIM_TSOIM(ctrlr,ParValue)  (pst_bitGIM(ctrlr) -> TSOIM=(ParValue))
#define biGetGIM_TRMABFM(ctrlr) (pst_bitGIM(ctrlr) -> TRMABFM)
#define vSetGIM_TRMABFM(ctrlr,ParValue)  (pst_bitGIM(ctrlr) -> TRMABFM=(ParValue))
#define biGetGIM_RMLIM(ctrlr) (pst_bitGIM(ctrlr) -> RMLIM)
#define vSetGIM_RMLIM(ctrlr,ParValue)  (pst_bitGIM(ctrlr) -> RMLIM=(ParValue))
#define biGetGIM_WUIM(ctrlr) (pst_bitGIM(ctrlr) -> WUIM)
#define vSetGIM_WUIM(ctrlr,ParValue)  (pst_bitGIM(ctrlr) -> WUIM=(ParValue))
#define biGetGIM_RFPM(ctrlr) (pst_bitGIM(ctrlr) -> RFPM)
#define vSetGIM_RFPM(ctrlr,ParValue)  (pst_bitGIM(ctrlr) -> RFPM=(ParValue))
            
/* byte access */
#define vSetGIM(ctrlr,ParValue) (*pu8GIM(ctrlr) = (ParValue))
#define u8GetGIM(ctrlr) (*pu8GIM(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MBTIF                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400480                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MBTIF_REG__       0xC0400480U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MBTIF	:31; 	 /* 0..30  bit(s) R/W1C */ 
  uint32_t   	:1; 	 /* 31..31  bit(s) R */                    
} MBTIF_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} MBTIF_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} MBTIF_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32MBTIF_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMBTIF(ctrlr)     ((volatile MBTIF_bit_view_st *)\
(MBTIF_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8MBTIF(ctrlr)     ((volatile MBTIF_byte_view_st *)\
(MBTIF_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16MBTIF(ctrlr)     ((volatile MBTIF_halfword_view_st *)\
(MBTIF_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32MBTIF(ctrlr)     ((volatile u32MBTIF_word_view *)\
(MBTIF_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMBTIF_MBTIF(ctrlr) (pst_bitMBTIF(ctrlr) -> MBTIF)
/*---------------------------------------------------------------------------*/
/* SRA: Clr funnction can be applied for bit 0..30: */
#define vClrMBTIF_MBTIF(ctrlr, BitNo) (pst_bitMBTIF(ctrlr) -> MBTIF = ( (0x00000001 << BitNo) & 0x7FFFFFFFU)) )
/* SRA: Clr funnction for multiple bits can be applied for multiple interrupt 0..30: */
#define vClrMultiMBTIF_MBTIF(ctrlr, Mask) (pst_bitMBTIF(ctrlr) -> MBTIF = (Mask & 0x7FFFFFFFU))
/*---------------------------------------------------------------------------*/
            
/* LL-struct byte access */
#define vSetMBTIFLL(ctrlr,ParValue) (pst_u8MBTIF(ctrlr) -> u8LL = (ParValue))
#define u8GetMBTIFLL(ctrlr) (pst_u8MBTIF(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetMBTIFLH(ctrlr,ParValue) (pst_u8MBTIF(ctrlr) -> u8LH = (ParValue))
#define u8GetMBTIFLH(ctrlr) (pst_u8MBTIF(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetMBTIFHL(ctrlr,ParValue) (pst_u8MBTIF(ctrlr) -> u8HL = (ParValue))
#define u8GetMBTIFHL(ctrlr) (pst_u8MBTIF(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetMBTIFHH(ctrlr,ParValue) (pst_u8MBTIF(ctrlr) -> u8HH = (ParValue))
#define u8GetMBTIFHH(ctrlr) (pst_u8MBTIF(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetMBTIFL(ctrlr,ParValue) (pst_u16MBTIF(ctrlr) -> u16L = (ParValue))
#define u16GetMBTIFL(ctrlr) (pst_u16MBTIF(ctrlr) -> u16L)
#define vSetMBTIFH(ctrlr,ParValue) (pst_u16MBTIF(ctrlr) -> u16H = (ParValue))
#define u16GetMBTIFH(ctrlr) (pst_u16MBTIF(ctrlr) -> u16H)
            
/* Word access */
#define vSetMBTIF(ctrlr,ParValue)  (*pu32MBTIF(ctrlr) = (ParValue))
#define u32GetMBTIF(ctrlr)  (*pu32MBTIF(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MBRIF                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400488                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MBRIF_REG__       0xC0400488U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   MBRIF	:32; 	 /* 0..31  bit(s) R/W1C */                    
} MBRIF_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} MBRIF_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} MBRIF_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32MBRIF_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMBRIF(ctrlr)     ((volatile MBRIF_bit_view_st *)\
(MBRIF_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8MBRIF(ctrlr)     ((volatile MBRIF_byte_view_st *)\
(MBRIF_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16MBRIF(ctrlr)     ((volatile MBRIF_halfword_view_st *)\
(MBRIF_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32MBRIF(ctrlr)     ((volatile u32MBRIF_word_view *)\
(MBRIF_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMBRIF_MBRIF(ctrlr) (pst_bitMBRIF(ctrlr) -> MBRIF)
/*---------------------------------------------------------------------------*/
/* SRA: Clr funnction can be applied for bit 0..31: */
#define vClrMBRIF_MBRIF(ctrlr, BitNo) (pst_bitMBRIF(ctrlr) -> MBRIF = (0x00000001 << BitNo))
/* SRA: Clr funnction for multiple bits can be applied for multiple interrupt 0..31: */
#define vClrMultiMBRIF_MBRIF(ctrlr, Mask) (pst_bitMBRIF(ctrlr) -> MBRIF = (Mask))
/*---------------------------------------------------------------------------*/
            
/* LL-struct byte access */
#define vSetMBRIFLL(ctrlr,ParValue) (pst_u8MBRIF(ctrlr) -> u8LL = (ParValue))
#define u8GetMBRIFLL(ctrlr) (pst_u8MBRIF(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetMBRIFLH(ctrlr,ParValue) (pst_u8MBRIF(ctrlr) -> u8LH = (ParValue))
#define u8GetMBRIFLH(ctrlr) (pst_u8MBRIF(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetMBRIFHL(ctrlr,ParValue) (pst_u8MBRIF(ctrlr) -> u8HL = (ParValue))
#define u8GetMBRIFHL(ctrlr) (pst_u8MBRIF(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetMBRIFHH(ctrlr,ParValue) (pst_u8MBRIF(ctrlr) -> u8HH = (ParValue))
#define u8GetMBRIFHH(ctrlr) (pst_u8MBRIF(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetMBRIFL(ctrlr,ParValue) (pst_u16MBRIF(ctrlr) -> u16L = (ParValue))
#define u16GetMBRIFL(ctrlr) (pst_u16MBRIF(ctrlr) -> u16L)
#define vSetMBRIFH(ctrlr,ParValue) (pst_u16MBRIF(ctrlr) -> u16H = (ParValue))
#define u16GetMBRIFH(ctrlr) (pst_u16MBRIF(ctrlr) -> u16H)
            
/* Word access */
#define vSetMBRIF(ctrlr,ParValue)  (*pu32MBRIF(ctrlr) = (ParValue))
#define u32GetMBRIF(ctrlr)  (*pu32MBRIF(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MBIM                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400490                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MBIM_REG__       0xC0400490U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   MBIM	:32; 	 /* 0..31  bit(s) R/W */                    
} MBIM_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} MBIM_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} MBIM_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32MBIM_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMBIM(ctrlr)     ((volatile MBIM_bit_view_st *)\
(MBIM_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8MBIM(ctrlr)     ((volatile MBIM_byte_view_st *)\
(MBIM_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16MBIM(ctrlr)     ((volatile MBIM_halfword_view_st *)\
(MBIM_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32MBIM(ctrlr)     ((volatile u32MBIM_word_view *)\
(MBIM_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMBIM_MBIM(ctrlr) (pst_bitMBIM(ctrlr) -> MBIM)
#define vSetMBIM_MBIM(ctrlr,ParValue)  (pst_bitMBIM(ctrlr) -> MBIM=(ParValue))
            
/* LL-struct byte access */
#define vSetMBIMLL(ctrlr,ParValue) (pst_u8MBIM(ctrlr) -> u8LL = (ParValue))
#define u8GetMBIMLL(ctrlr) (pst_u8MBIM(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetMBIMLH(ctrlr,ParValue) (pst_u8MBIM(ctrlr) -> u8LH = (ParValue))
#define u8GetMBIMLH(ctrlr) (pst_u8MBIM(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetMBIMHL(ctrlr,ParValue) (pst_u8MBIM(ctrlr) -> u8HL = (ParValue))
#define u8GetMBIMHL(ctrlr) (pst_u8MBIM(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetMBIMHH(ctrlr,ParValue) (pst_u8MBIM(ctrlr) -> u8HH = (ParValue))
#define u8GetMBIMHH(ctrlr) (pst_u8MBIM(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetMBIML(ctrlr,ParValue) (pst_u16MBIM(ctrlr) -> u16L = (ParValue))
#define u16GetMBIML(ctrlr) (pst_u16MBIM(ctrlr) -> u16L)
#define vSetMBIMH(ctrlr,ParValue) (pst_u16MBIM(ctrlr) -> u16H = (ParValue))
#define u16GetMBIMH(ctrlr) (pst_u16MBIM(ctrlr) -> u16H)
            
/* Word access */
#define vSetMBIM(ctrlr,ParValue)  (*pu32MBIM(ctrlr) = (ParValue))
#define u32GetMBIM(ctrlr)  (*pu32MBIM(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0400498                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CDR_REG__       0xC0400498U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CDR	:31; 	 /* 0..30  bit(s) R/W */ 
  uint32_t   	:1; 	 /* 31..31  bit(s) R */                    
} CDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CDR_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CDR_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CDR_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCDR(ctrlr)     ((volatile CDR_bit_view_st *)\
(CDR_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8CDR(ctrlr)     ((volatile CDR_byte_view_st *)\
(CDR_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16CDR(ctrlr)     ((volatile CDR_halfword_view_st *)\
(CDR_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32CDR(ctrlr)     ((volatile u32CDR_word_view *)\
(CDR_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCDR_CDR(ctrlr) (pst_bitCDR(ctrlr) -> CDR)
#define vSetCDR_CDR(ctrlr,ParValue)  (pst_bitCDR(ctrlr) -> CDR=(ParValue))
            
/* LL-struct byte access */
#define vSetCDRLL(ctrlr,ParValue) (pst_u8CDR(ctrlr) -> u8LL = (ParValue))
#define u8GetCDRLL(ctrlr) (pst_u8CDR(ctrlr) -> u8LL)
/* LH-struct byte access */
#define vSetCDRLH(ctrlr,ParValue) (pst_u8CDR(ctrlr) -> u8LH = (ParValue))
#define u8GetCDRLH(ctrlr) (pst_u8CDR(ctrlr) -> u8LH)
/* HL-struct byte access */
#define vSetCDRHL(ctrlr,ParValue) (pst_u8CDR(ctrlr) -> u8HL = (ParValue))
#define u8GetCDRHL(ctrlr) (pst_u8CDR(ctrlr) -> u8HL)
/* HH-struct byte access */
#define vSetCDRHH(ctrlr,ParValue) (pst_u8CDR(ctrlr) -> u8HH = (ParValue))
#define u8GetCDRHH(ctrlr) (pst_u8CDR(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCDRL(ctrlr,ParValue) (pst_u16CDR(ctrlr) -> u16L = (ParValue))
#define u16GetCDRL(ctrlr) (pst_u16CDR(ctrlr) -> u16L)
#define vSetCDRH(ctrlr,ParValue) (pst_u16CDR(ctrlr) -> u16H = (ParValue))
#define u16GetCDRH(ctrlr) (pst_u16CDR(ctrlr) -> u16H)
            
/* Word access */
#define vSetCDR(ctrlr,ParValue)  (*pu32CDR(ctrlr) = (ParValue))
#define u32GetCDR(ctrlr)  (*pu32CDR(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RFP                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC04004A0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RFP_REG__       0xC04004A0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   RFP	:32; 	 /* 0..31  bit(s) R */                    
} RFP_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} RFP_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} RFP_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32RFP_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRFP(ctrlr)     ((volatile RFP_bit_view_st *)\
(RFP_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8RFP(ctrlr)     ((volatile RFP_byte_view_st *)\
(RFP_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD-struct */
#define pst_u16RFP(ctrlr)     ((volatile RFP_halfword_view_st *)\
(RFP_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to WORD  */ 
#define pu32RFP(ctrlr)     ((volatile u32RFP_word_view *)\
(RFP_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetRFP_RFP(ctrlr) (pst_bitRFP(ctrlr) -> RFP)
            
/* LL-struct byte access */

#define u8GetRFPLL(ctrlr) (pst_u8RFP(ctrlr) -> u8LL)
/* LH-struct byte access */

#define u8GetRFPLH(ctrlr) (pst_u8RFP(ctrlr) -> u8LH)
/* HL-struct byte access */

#define u8GetRFPHL(ctrlr) (pst_u8RFP(ctrlr) -> u8HL)
/* HH-struct byte access */

#define u8GetRFPHH(ctrlr) (pst_u8RFP(ctrlr) -> u8HH)
            
            
/* Half-word struct access */ 

#define u16GetRFPL(ctrlr) (pst_u16RFP(ctrlr) -> u16L)

#define u16GetRFPH(ctrlr) (pst_u16RFP(ctrlr) -> u16H)
            
/* Word access */

#define u32GetRFP(ctrlr)  (*pu32RFP(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CEC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC04004A8                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CEC_REG__       0xC04004A8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   REC	:8; 	 /* 0..7  bit(s) R */
  uint16_t   TEC	:8; 	 /* 8..15  bit(s) R */                    
} CEC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} CEC_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16CEC_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCEC(ctrlr)     ((volatile CEC_bit_view_st *)\
(CEC_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8CEC(ctrlr)     ((volatile CEC_byte_view_st *)\
(CEC_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16CEC(ctrlr)     ((volatile u16CEC_halfword_view *)\
(CEC_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCEC_REC(ctrlr) (pst_bitCEC(ctrlr) -> REC)            
#define biGetCEC_TEC(ctrlr) (pst_bitCEC(ctrlr) -> TEC)
            
/* L-struct byte access */

#define u8GetCECL(ctrlr) (pst_u8CEC(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetCECH(ctrlr) (pst_u8CEC(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetCEC(ctrlr) (*pu16CEC(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: TSP                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC04004B0                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TSP_REG__       0xC04004B0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   TSP	:4; 	 /* 0..3  bit(s) R/W */ 
  uint8_t   	:4; 	 /* 4..31  bit(s) R */                    
} TSP_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8TSP_byte_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTSP(ctrlr)     ((volatile TSP_bit_view_st *)\
(TSP_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE  */
#define pu8TSP(ctrlr)     ((volatile u8TSP_byte_view *)\
(TSP_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetTSP_TSP(ctrlr) (pst_bitTSP(ctrlr) -> TSP)
#define vSetTSP_TSP(ctrlr,ParValue)  (pst_bitTSP(ctrlr) -> TSP=(ParValue))
            
/* byte access */
#define vSetTSP(ctrlr,ParValue) (*pu8TSP(ctrlr) = (ParValue))
#define u8GetTSP(ctrlr) (*pu8TSP(ctrlr) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: TSC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC04004B8                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define TSC_REG__       0xC04004B8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   TSC	:16; 	 /* 0..15  bit(s) R */                    
} TSC_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} TSC_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16TSC_halfword_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitTSC(ctrlr)     ((volatile TSC_bit_view_st *)\
(TSC_REG__  + ((int32_t)(ctrlr))))
        
/* Pointer to BYTE-struct  */
#define pst_u8TSC(ctrlr)     ((volatile TSC_byte_view_st *)\
(TSC_REG__  + ((int32_t)(ctrlr))))
            
/* Pointer to HALFWORD */
#define pu16TSC(ctrlr)     ((volatile u16TSC_halfword_view *)\
(TSC_REG__  + ((int32_t)(ctrlr))))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetTSC_TSC(ctrlr) (pst_bitTSC(ctrlr) -> TSC)
            
/* L-struct byte access */

#define u8GetTSCL(ctrlr) (pst_u8TSC(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetTSCH(ctrlr) (pst_u8TSC(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetTSC(ctrlr) (*pu16TSC(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: MBnAM                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC04004C0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MBnAM_REG__       0xC04004C0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   AM	:29; 	 /* 0..28  bit(s) R/W */
  uint32_t   	:2; 	 /* 29..30  bit(s) R */ 
  uint32_t   AMI	:1; 	 /* 31..31  bit(s) R/W */                    
} MBnAM_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} MBnAM_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} MBnAM_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32MBnAM_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMBnAM(ctrlr,ch)     ((volatile MBnAM_bit_view_st *)\
(MBnAM_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x8U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8MBnAM(ctrlr,ch)     ((volatile MBnAM_byte_view_st *)\
(MBnAM_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x8U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16MBnAM(ctrlr,ch)     ((volatile MBnAM_halfword_view_st *)\
(MBnAM_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x8U)))
            
/* Pointer to WORD  */ 
#define pu32MBnAM(ctrlr,ch)     ((volatile u32MBnAM_word_view *)\
(MBnAM_REG__  + ((int32_t)(ctrlr)) + ((int32_t)(ch) * 0x8U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMBnAM_AM(ctrlr,ch) (pst_bitMBnAM(ctrlr,ch) -> AM)
#define vSetMBnAM_AM(ctrlr,ch,ParValue)  (pst_bitMBnAM(ctrlr,ch) -> AM=(ParValue))
#define biGetMBnAM_AMI(ctrlr,ch) (pst_bitMBnAM(ctrlr,ch) -> AMI)
#define vSetMBnAM_AMI(ctrlr,ch,ParValue)  (pst_bitMBnAM(ctrlr,ch) -> AMI=(ParValue))
            
/* LL-struct byte access */
#define vSetMBnAMLL(ctrlr,ch,ParValue) (pst_u8MBnAM(ctrlr,ch) -> u8LL = (ParValue))
#define u8GetMBnAMLL(ctrlr,ch) (pst_u8MBnAM(ctrlr,ch) -> u8LL)
/* LH-struct byte access */
#define vSetMBnAMLH(ctrlr,ch,ParValue) (pst_u8MBnAM(ctrlr,ch) -> u8LH = (ParValue))
#define u8GetMBnAMLH(ctrlr,ch) (pst_u8MBnAM(ctrlr,ch) -> u8LH)
/* HL-struct byte access */
#define vSetMBnAMHL(ctrlr,ch,ParValue) (pst_u8MBnAM(ctrlr,ch) -> u8HL = (ParValue))
#define u8GetMBnAMHL(ctrlr,ch) (pst_u8MBnAM(ctrlr,ch) -> u8HL)
/* HH-struct byte access */
#define vSetMBnAMHH(ctrlr,ch,ParValue) (pst_u8MBnAM(ctrlr,ch) -> u8HH = (ParValue))
#define u8GetMBnAMHH(ctrlr,ch) (pst_u8MBnAM(ctrlr,ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetMBnAML(ctrlr,ch,ParValue) (pst_u16MBnAM(ctrlr,ch) -> u16L = (ParValue))
#define u16GetMBnAML(ctrlr,ch) (pst_u16MBnAM(ctrlr,ch) -> u16L)
#define vSetMBnAMH(ctrlr,ch,ParValue) (pst_u16MBnAM(ctrlr,ch) -> u16H = (ParValue))
#define u16GetMBnAMH(ctrlr,ch) (pst_u16MBnAM(ctrlr,ch) -> u16H)
            
/* Word access */
#define vSetMBnAM(ctrlr,ch,ParValue)  (*pu32MBnAM(ctrlr,ch) = (ParValue))
#define u32GetMBnAM(ctrlr,ch)  (*pu32MBnAM(ctrlr,ch) )
            




    

#endif /* TCANIO_H */ 
    
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

