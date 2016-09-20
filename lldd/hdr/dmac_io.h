
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : DMAC 
/  Date of creation (y-m-d:time): 2014-12-18+01:00  :  11:47:29.455+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.11 $ 
/  Excel Sheet ver.             : vv1.2
/  Excel Sheet date             : 2014-Sep-12
/  Excel Sheet author           : ZUL
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
*   VERSION     : $Revision: 1.11 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/
#ifndef DMACIO_H
#define DMACIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */


/*********************************************
*         Disable Misra Warnings/Rules       *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1840 /* Rule  5.7 [A] : 	 [A] No reuse of identifiers */
#endif


/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_DMAC_IO_H_REVISION     "$Revision: 1.11 $"
#define LLDD_DMAC_IO_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/


/****************************************************************************   
*                                                                               
*       REGISTER: DMACIntStatus                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C000                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACIntStatus_REG__       0xC010C000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   IntStatus	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACIntStatus_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACIntStatus_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACIntStatus()     ((volatile DMACIntStatus_bit_view_st *)\
(DMACIntStatus_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACIntStatus()     ((volatile u32DMACIntStatus_word_view *)\
(DMACIntStatus_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACIntStatus_IntStatus() (pst_bitDMACIntStatus() -> IntStatus)            
            
           
/* Word access */

#define u32GetDMACIntStatus()  (*pu32DMACIntStatus() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACIntTCStatus                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C004                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACIntTCStatus_REG__       0xC010C004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   IntTCStatus	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACIntTCStatus_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACIntTCStatus_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACIntTCStatus()     ((volatile DMACIntTCStatus_bit_view_st *)\
(DMACIntTCStatus_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACIntTCStatus()     ((volatile u32DMACIntTCStatus_word_view *)\
(DMACIntTCStatus_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACIntTCStatus_IntTCStatus() (pst_bitDMACIntTCStatus() -> IntTCStatus)            
            
            
/* Word access */

#define u32GetDMACIntTCStatus()  (*pu32DMACIntTCStatus() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACIntTCClear                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C008                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACIntTCClear_REG__       0xC010C008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   IntTCClear	:8; 	 /* 0..7  bit(s) W */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) W */                    
} DMACIntTCClear_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACIntTCClear_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACIntTCClear()     ((volatile DMACIntTCClear_bit_view_st *)\
(DMACIntTCClear_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACIntTCClear()     ((volatile u32DMACIntTCClear_word_view *)\
(DMACIntTCClear_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetDMACIntTCClear_IntTCClear(ParValue) (pst_bitDMACIntTCClear() -> IntTCClear=(ParValue)) 
            
/* Word access */
#define vSetDMACIntTCClear(ParValue)  (*pu32DMACIntTCClear() = (ParValue))
#define u32GetDMACIntTCClear()  (*pu32DMACIntTCClear() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACIntErrorStatus                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C00C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACIntErrorStatus_REG__       0xC010C00CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   IntErrorStatus	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACIntErrorStatus_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACIntErrorStatus_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACIntErrorStatus()     ((volatile DMACIntErrorStatus_bit_view_st *)\
(DMACIntErrorStatus_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACIntErrorStatus()     ((volatile u32DMACIntErrorStatus_word_view *)\
(DMACIntErrorStatus_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACIntErrorStatus_IntErrorStatus() (pst_bitDMACIntErrorStatus() -> IntErrorStatus)            
            
/* Word access */

#define u32GetDMACIntErrorStatus()  (*pu32DMACIntErrorStatus() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACIntErrClr                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C010                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACIntErrClr_REG__       0xC010C010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   IntErrClr	:8; 	 /* 0..7  bit(s) W */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) W */                    
} DMACIntErrClr_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACIntErrClr_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACIntErrClr()     ((volatile DMACIntErrClr_bit_view_st *)\
(DMACIntErrClr_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACIntErrClr()     ((volatile u32DMACIntErrClr_word_view *)\
(DMACIntErrClr_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetDMACIntErrClr_IntErrClr(ParValue) (pst_bitDMACIntErrClr() -> IntErrClr=(ParValue)) 
            
/* Word access */
#define vSetDMACIntErrClr(ParValue)  (*pu32DMACIntErrClr() = (ParValue))
#define u32GetDMACIntErrClr()  (*pu32DMACIntErrClr() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACRawIntTCStatus                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C014                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACRawIntTCStatus_REG__       0xC010C014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   RawIntTCStatus	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACRawIntTCStatus_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACRawIntTCStatus_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACRawIntTCStatus()     ((volatile DMACRawIntTCStatus_bit_view_st *)\
(DMACRawIntTCStatus_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACRawIntTCStatus()     ((volatile u32DMACRawIntTCStatus_word_view *)\
(DMACRawIntTCStatus_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACRawIntTCStatus_RawIntTCStatus() (pst_bitDMACRawIntTCStatus() -> RawIntTCStatus)            
            
/* Word access */

#define u32GetDMACRawIntTCStatus()  (*pu32DMACRawIntTCStatus() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACRawIntErrorStatus                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACRawIntErrorStatus_REG__       0xC010C018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   RawIntErrorStatus	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACRawIntErrorStatus_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACRawIntErrorStatus_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACRawIntErrorStatus()     ((volatile DMACRawIntErrorStatus_bit_view_st *)\
(DMACRawIntErrorStatus_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACRawIntErrorStatus()     ((volatile u32DMACRawIntErrorStatus_word_view *)\
(DMACRawIntErrorStatus_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACRawIntErrorStatus_RawIntErrorStatus() (pst_bitDMACRawIntErrorStatus() -> RawIntErrorStatus)            
            
/* Word access */

#define u32GetDMACRawIntErrorStatus()  (*pu32DMACRawIntErrorStatus() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACEnbldChns                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C01C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACEnbldChns_REG__       0xC010C01CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   EnabledChannels	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACEnbldChns_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACEnbldChns_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACEnbldChns()     ((volatile DMACEnbldChns_bit_view_st *)\
(DMACEnbldChns_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACEnbldChns()     ((volatile u32DMACEnbldChns_word_view *)\
(DMACEnbldChns_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACEnbldChns_EnabledChannels() (pst_bitDMACEnbldChns() -> EnabledChannels)            
            
/* Word access */

#define u32GetDMACEnbldChns()  (*pu32DMACEnbldChns() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACSoftBReq                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACSoftBReq_REG__       0xC010C020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SoftBReq	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   Reserved	:16; 	 /* 16..31  bit(s) R */                    
} DMACSoftBReq_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACSoftBReq_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACSoftBReq()     ((volatile DMACSoftBReq_bit_view_st *)\
(DMACSoftBReq_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACSoftBReq()     ((volatile u32DMACSoftBReq_word_view *)\
(DMACSoftBReq_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACSoftBReq_SoftBReq() (pst_bitDMACSoftBReq() -> SoftBReq)
#define vSetDMACSoftBReq_SoftBReq(ParValue)  (pst_bitDMACSoftBReq() -> SoftBReq=(ParValue))            
            
/* Word access */
#define vSetDMACSoftBReq(ParValue)  (*pu32DMACSoftBReq() = (ParValue))
#define u32GetDMACSoftBReq()  (*pu32DMACSoftBReq() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACSoftSReq                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C024                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACSoftSReq_REG__       0xC010C024U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SoftSReq	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   Reserved	:16; 	 /* 16..31  bit(s) R */                    
} DMACSoftSReq_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACSoftSReq_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACSoftSReq()     ((volatile DMACSoftSReq_bit_view_st *)\
(DMACSoftSReq_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACSoftSReq()     ((volatile u32DMACSoftSReq_word_view *)\
(DMACSoftSReq_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACSoftSReq_SoftSReq() (pst_bitDMACSoftSReq() -> SoftSReq)
#define vSetDMACSoftSReq_SoftSReq(ParValue)  (pst_bitDMACSoftSReq() -> SoftSReq=(ParValue))            
            
/* Word access */
#define vSetDMACSoftSReq(ParValue)  (*pu32DMACSoftSReq() = (ParValue))
#define u32GetDMACSoftSReq()  (*pu32DMACSoftSReq() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACSoftLBReq                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C028                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACSoftLBReq_REG__       0xC010C028U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SoftLBReq	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   Reserved	:16; 	 /* 16..31  bit(s) R */                    
} DMACSoftLBReq_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACSoftLBReq_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACSoftLBReq()     ((volatile DMACSoftLBReq_bit_view_st *)\
(DMACSoftLBReq_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACSoftLBReq()     ((volatile u32DMACSoftLBReq_word_view *)\
(DMACSoftLBReq_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACSoftLBReq_SoftLBReq() (pst_bitDMACSoftLBReq() -> SoftLBReq)
#define vSetDMACSoftLBReq_SoftLBReq(ParValue)  (pst_bitDMACSoftLBReq() -> SoftLBReq=(ParValue))            
            
/* Word access */
#define vSetDMACSoftLBReq(ParValue)  (*pu32DMACSoftLBReq() = (ParValue))
#define u32GetDMACSoftLBReq()  (*pu32DMACSoftLBReq() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACSoftLSReq                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C02C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACSoftLSReq_REG__       0xC010C02CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SoftLSReq	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   Reserved	:16; 	 /* 16..31  bit(s) R */                    
} DMACSoftLSReq_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACSoftLSReq_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACSoftLSReq()     ((volatile DMACSoftLSReq_bit_view_st *)\
(DMACSoftLSReq_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACSoftLSReq()     ((volatile u32DMACSoftLSReq_word_view *)\
(DMACSoftLSReq_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACSoftLSReq_SoftLSReq() (pst_bitDMACSoftLSReq() -> SoftLSReq)
#define vSetDMACSoftLSReq_SoftLSReq(ParValue)  (pst_bitDMACSoftLSReq() -> SoftLSReq=(ParValue))            
            
/* Word access */
#define vSetDMACSoftLSReq(ParValue)  (*pu32DMACSoftLSReq() = (ParValue))
#define u32GetDMACSoftLSReq()  (*pu32DMACSoftLSReq() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACConfig                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C030                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACConfig_REG__       0xC010C030U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   E	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   M1	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   M2	:1; 	 /* 2..2  bit(s) R/W */ 
  uint32_t   Reserved	:29; 	 /* 3..31  bit(s) R */                    
} DMACConfig_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACConfig_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACConfig()     ((volatile DMACConfig_bit_view_st *)\
(DMACConfig_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACConfig()     ((volatile u32DMACConfig_word_view *)\
(DMACConfig_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACConfig_E() (pst_bitDMACConfig() -> E)
#define vSetDMACConfig_E(ParValue)  (pst_bitDMACConfig() -> E=(ParValue))
#define biGetDMACConfig_M1() (pst_bitDMACConfig() -> M1)
#define vSetDMACConfig_M1(ParValue)  (pst_bitDMACConfig() -> M1=(ParValue))
#define biGetDMACConfig_M2() (pst_bitDMACConfig() -> M2)
#define vSetDMACConfig_M2(ParValue)  (pst_bitDMACConfig() -> M2=(ParValue))            
            
/* Word access */
#define vSetDMACConfig(ParValue)  (*pu32DMACConfig() = (ParValue))
#define u32GetDMACConfig()  (*pu32DMACConfig() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACSync                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C034                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACSync_REG__       0xC010C034U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DMACSync	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   Reserved	:16; 	 /* 16..31  bit(s) R */                    
} DMACSync_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACSync_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACSync()     ((volatile DMACSync_bit_view_st *)\
(DMACSync_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACSync()     ((volatile u32DMACSync_word_view *)\
(DMACSync_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACSync_DMACSync() (pst_bitDMACSync() -> DMACSync)
#define vSetDMACSync_DMACSync(ParValue)  (pst_bitDMACSync() -> DMACSync=(ParValue))            
            
/* Word access */
#define vSetDMACSync(ParValue)  (*pu32DMACSync() = (ParValue))
#define u32GetDMACSync()  (*pu32DMACSync() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACC0SrcAddr                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C100                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACC0SrcAddr_REG__       0xC010C100U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   SrcAddr	:32; 	 /* 0..31  bit(s) R/W */                    
} DMACC0SrcAddr_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACC0SrcAddr_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACC0SrcAddr(ch)     ((volatile DMACC0SrcAddr_bit_view_st *)\
(DMACC0SrcAddr_REG__  + ((uint16_t)(ch) * 0x020U)))
        
/* Pointer to WORD  */ 
#define pu32DMACC0SrcAddr(ch)     ((volatile u32DMACC0SrcAddr_word_view *)\
(DMACC0SrcAddr_REG__  + ((uint16_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACC0SrcAddr_SrcAddr(ch) (pst_bitDMACC0SrcAddr(ch) -> SrcAddr)
#define vSetDMACC0SrcAddr_SrcAddr(ch,ParValue)  (pst_bitDMACC0SrcAddr(ch) -> SrcAddr=(ParValue))
            
/* Word access */
#define vSetDMACC0SrcAddr(ch,ParValue)  (*pu32DMACC0SrcAddr(ch) = (ParValue))
#define u32GetDMACC0SrcAddr(ch)  (*pu32DMACC0SrcAddr(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACC0DestAddr                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C104                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACC0DestAddr_REG__       0xC010C104U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   DestAddr	:32; 	 /* 0..31  bit(s) R/W */                    
} DMACC0DestAddr_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACC0DestAddr_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACC0DestAddr(ch)     ((volatile DMACC0DestAddr_bit_view_st *)\
(DMACC0DestAddr_REG__  + ((uint16_t)(ch) * 0x020U)))
        
/* Pointer to WORD  */ 
#define pu32DMACC0DestAddr(ch)     ((volatile u32DMACC0DestAddr_word_view *)\
(DMACC0DestAddr_REG__  + ((uint16_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACC0DestAddr_DestAddr(ch) (pst_bitDMACC0DestAddr(ch) -> DestAddr)
#define vSetDMACC0DestAddr_DestAddr(ch,ParValue)  (pst_bitDMACC0DestAddr(ch) -> DestAddr=(ParValue))
            
/* Word access */
#define vSetDMACC0DestAddr(ch,ParValue)  (*pu32DMACC0DestAddr(ch) = (ParValue))
#define u32GetDMACC0DestAddr(ch)  (*pu32DMACC0DestAddr(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACC0LLI                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C108                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACC0LLI_REG__       0xC010C108U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   LM	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   	:1; 	 /* 1..1  bit(s) R */ 
  uint32_t   LLI	:30; 	 /* 2..31  bit(s) R/W */                    
} DMACC0LLI_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACC0LLI_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACC0LLI(ch)     ((volatile DMACC0LLI_bit_view_st *)\
(DMACC0LLI_REG__  + ((uint16_t)(ch) * 0x020U)))
        
/* Pointer to WORD  */ 
#define pu32DMACC0LLI(ch)     ((volatile u32DMACC0LLI_word_view *)\
(DMACC0LLI_REG__  + ((uint16_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACC0LLI_LM(ch) (pst_bitDMACC0LLI(ch) -> LM)
#define vSetDMACC0LLI_LM(ch,ParValue)  (pst_bitDMACC0LLI(ch) -> LM=(ParValue))
#define biGetDMACC0LLI_LLI(ch) (pst_bitDMACC0LLI(ch) -> LLI)
#define vSetDMACC0LLI_LLI(ch,ParValue)  (pst_bitDMACC0LLI(ch) -> LLI=(ParValue))
            
/* Word access */
#define vSetDMACC0LLI(ch,ParValue)  (*pu32DMACC0LLI(ch) = (ParValue))
#define u32GetDMACC0LLI(ch)  (*pu32DMACC0LLI(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACC0Control                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C10C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACC0Control_REG__       0xC010C10CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   TransferSize	:12; 	 /* 0..11  bit(s) R/W */
  uint32_t   SBSize	:3; 	 /* 12..14  bit(s) R/W */
  uint32_t   DBSize	:3; 	 /* 15..17  bit(s) R/W */
  uint32_t   SWidth	:3; 	 /* 18..20  bit(s) R/W */
  uint32_t   DWidth	:3; 	 /* 21..23  bit(s) R/W */
  uint32_t   S	:1; 	 /* 24..24  bit(s) R/W */
  uint32_t   D	:1; 	 /* 25..25  bit(s) R/W */
  uint32_t   SI	:1; 	 /* 26..26  bit(s) R/W */
  uint32_t   DI	:1; 	 /* 27..27  bit(s) R/W */
  uint32_t   Prot	:3; 	 /* 28..30  bit(s) R/W */ 
  uint32_t   I	:1; 	 /* 31..31  bit(s) R/W */                    
} DMACC0Control_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACC0Control_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACC0Control(ch)     ((volatile DMACC0Control_bit_view_st *)\
(DMACC0Control_REG__  + ((uint16_t)(ch) * 0x020U)))
        
/* Pointer to WORD  */ 
#define pu32DMACC0Control(ch)     ((volatile u32DMACC0Control_word_view *)\
(DMACC0Control_REG__  + ((uint16_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACC0Control_TransferSize(ch) (pst_bitDMACC0Control(ch) -> TransferSize)
#define vSetDMACC0Control_TransferSize(ch,ParValue)  (pst_bitDMACC0Control(ch) -> TransferSize=(ParValue))
#define biGetDMACC0Control_SBSize(ch) (pst_bitDMACC0Control(ch) -> SBSize)
#define vSetDMACC0Control_SBSize(ch,ParValue)  (pst_bitDMACC0Control(ch) -> SBSize=(ParValue))
#define biGetDMACC0Control_DBSize(ch) (pst_bitDMACC0Control(ch) -> DBSize)
#define vSetDMACC0Control_DBSize(ch,ParValue)  (pst_bitDMACC0Control(ch) -> DBSize=(ParValue))
#define biGetDMACC0Control_SWidth(ch) (pst_bitDMACC0Control(ch) -> SWidth)
#define vSetDMACC0Control_SWidth(ch,ParValue)  (pst_bitDMACC0Control(ch) -> SWidth=(ParValue))
#define biGetDMACC0Control_DWidth(ch) (pst_bitDMACC0Control(ch) -> DWidth)
#define vSetDMACC0Control_DWidth(ch,ParValue)  (pst_bitDMACC0Control(ch) -> DWidth=(ParValue))
#define biGetDMACC0Control_S(ch) (pst_bitDMACC0Control(ch) -> S)
#define vSetDMACC0Control_S(ch,ParValue)  (pst_bitDMACC0Control(ch) -> S=(ParValue))
#define biGetDMACC0Control_D(ch) (pst_bitDMACC0Control(ch) -> D)
#define vSetDMACC0Control_D(ch,ParValue)  (pst_bitDMACC0Control(ch) -> D=(ParValue))
#define biGetDMACC0Control_SI(ch) (pst_bitDMACC0Control(ch) -> SI)
#define vSetDMACC0Control_SI(ch,ParValue)  (pst_bitDMACC0Control(ch) -> SI=(ParValue))
#define biGetDMACC0Control_DI(ch) (pst_bitDMACC0Control(ch) -> DI)
#define vSetDMACC0Control_DI(ch,ParValue)  (pst_bitDMACC0Control(ch) -> DI=(ParValue))
#define biGetDMACC0Control_Prot(ch) (pst_bitDMACC0Control(ch) -> Prot)
#define vSetDMACC0Control_Prot(ch,ParValue)  (pst_bitDMACC0Control(ch) -> Prot=(ParValue))
#define biGetDMACC0Control_I(ch) (pst_bitDMACC0Control(ch) -> I)
#define vSetDMACC0Control_I(ch,ParValue)  (pst_bitDMACC0Control(ch) -> I=(ParValue))
            
/* Word access */
#define vSetDMACC0Control(ch,ParValue)  (*pu32DMACC0Control(ch) = (ParValue))
#define u32GetDMACC0Control(ch)  (*pu32DMACC0Control(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACC0Config                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C110                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACC0Config_REG__       0xC010C110U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   E	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   SrcPeripherala	:4; 	 /* 1..4  bit(s) R/W */
  uint32_t   	:1; 	 /* 5..5  bit(s) R */
  uint32_t   DestPeripherala	:4; 	 /* 6..9  bit(s) R/W */
  uint32_t   	:1; 	 /* 10..10  bit(s) R */
  uint32_t   FlowCntrl	:3; 	 /* 11..13  bit(s) R/W */
  uint32_t   IE	:1; 	 /* 14..14  bit(s) R/W */
  uint32_t   ITC	:1; 	 /* 15..15  bit(s) R/W */
  uint32_t   L	:1; 	 /* 16..16  bit(s) R/W */
  uint32_t   A	:1; 	 /* 17..17  bit(s) R */
  uint32_t   H	:1; 	 /* 18..18  bit(s) R/W */ 
  uint32_t   Reserved	:13; 	 /* 19..31  bit(s) R */                    
} DMACC0Config_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACC0Config_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACC0Config(ch)     ((volatile DMACC0Config_bit_view_st *)\
(DMACC0Config_REG__  + ((uint16_t)(ch) * 0x020U)))
        
/* Pointer to WORD  */ 
#define pu32DMACC0Config(ch)     ((volatile u32DMACC0Config_word_view *)\
(DMACC0Config_REG__  + ((uint16_t)(ch) * 0x020U)))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACC0Config_E(ch) (pst_bitDMACC0Config(ch) -> E)
#define vSetDMACC0Config_E(ch,ParValue)  (pst_bitDMACC0Config(ch) -> E=(ParValue))
#define biGetDMACC0Config_SrcPeripherala(ch) (pst_bitDMACC0Config(ch) -> SrcPeripherala)
#define vSetDMACC0Config_SrcPeripherala(ch,ParValue)  (pst_bitDMACC0Config(ch) -> SrcPeripherala=(ParValue))
#define biGetDMACC0Config_DestPeripherala(ch) (pst_bitDMACC0Config(ch) -> DestPeripherala)
#define vSetDMACC0Config_DestPeripherala(ch,ParValue)  (pst_bitDMACC0Config(ch) -> DestPeripherala=(ParValue))
#define biGetDMACC0Config_FlowCntrl(ch) (pst_bitDMACC0Config(ch) -> FlowCntrl)
#define vSetDMACC0Config_FlowCntrl(ch,ParValue)  (pst_bitDMACC0Config(ch) -> FlowCntrl=(ParValue))
#define biGetDMACC0Config_IE(ch) (pst_bitDMACC0Config(ch) -> IE)
#define vSetDMACC0Config_IE(ch,ParValue)  (pst_bitDMACC0Config(ch) -> IE=(ParValue))
#define biGetDMACC0Config_ITC(ch) (pst_bitDMACC0Config(ch) -> ITC)
#define vSetDMACC0Config_ITC(ch,ParValue)  (pst_bitDMACC0Config(ch) -> ITC=(ParValue))
#define biGetDMACC0Config_L(ch) (pst_bitDMACC0Config(ch) -> L)
#define vSetDMACC0Config_L(ch,ParValue)  (pst_bitDMACC0Config(ch) -> L=(ParValue))
#define biGetDMACC0Config_A(ch) (pst_bitDMACC0Config(ch) -> A)
#define biGetDMACC0Config_H(ch) (pst_bitDMACC0Config(ch) -> H)
#define vSetDMACC0Config_H(ch,ParValue)  (pst_bitDMACC0Config(ch) -> H=(ParValue))            
            
/* Word access */
#define vSetDMACC0Config(ch,ParValue)  (*pu32DMACC0Config(ch) = (ParValue))
#define u32GetDMACC0Config(ch)  (*pu32DMACC0Config(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACPeriID0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010CFE0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACPeriID0_REG__       0xC010CFE0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PartNumber0	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACPeriID0_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACPeriID0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACPeriID0()     ((volatile DMACPeriID0_bit_view_st *)\
(DMACPeriID0_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACPeriID0()     ((volatile u32DMACPeriID0_word_view *)\
(DMACPeriID0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACPeriID0_PartNumber0() (pst_bitDMACPeriID0() -> PartNumber0)            
            
/* Word access */

#define u32GetDMACPeriID0()  (*pu32DMACPeriID0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACPeriID1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010CFE4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACPeriID1_REG__       0xC010CFE4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   PartNumber1	:4; 	 /* 0..3  bit(s) R */
  uint32_t   Designer0	:4; 	 /* 4..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACPeriID1_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACPeriID1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACPeriID1()     ((volatile DMACPeriID1_bit_view_st *)\
(DMACPeriID1_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACPeriID1()     ((volatile u32DMACPeriID1_word_view *)\
(DMACPeriID1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACPeriID1_PartNumber1() (pst_bitDMACPeriID1() -> PartNumber1)            
#define biGetDMACPeriID1_Designer0() (pst_bitDMACPeriID1() -> Designer0)            
            
/* Word access */

#define u32GetDMACPeriID1()  (*pu32DMACPeriID1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACPeriID2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010CFE8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACPeriID2_REG__       0xC010CFE8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   Designer1	:4; 	 /* 0..3  bit(s) R */
  uint32_t   Revision	:4; 	 /* 4..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACPeriID2_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACPeriID2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACPeriID2()     ((volatile DMACPeriID2_bit_view_st *)\
(DMACPeriID2_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACPeriID2()     ((volatile u32DMACPeriID2_word_view *)\
(DMACPeriID2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACPeriID2_Designer1() (pst_bitDMACPeriID2() -> Designer1)            
#define biGetDMACPeriID2_Revision() (pst_bitDMACPeriID2() -> Revision)            
            
/* Word access */

#define u32GetDMACPeriID2()  (*pu32DMACPeriID2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACPeriID3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010CFEC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACPeriID3_REG__       0xC010CFECU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   Designer1	:3; 	 /* 0..2  bit(s) R */
  uint32_t   Revision	:1; 	 /* 3..3  bit(s) R */
  uint32_t   Reserved1	:3; 	 /* 4..6  bit(s) R */
  uint32_t   Reserved2	:1; 	 /* 7..7  bit(s) R */ 
  uint32_t   Reserved3	:24; 	 /* 8..31  bit(s) R */                    
} DMACPeriID3_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACPeriID3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACPeriID3()     ((volatile DMACPeriID3_bit_view_st *)\
(DMACPeriID3_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACPeriID3()     ((volatile u32DMACPeriID3_word_view *)\
(DMACPeriID3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACPeriID3_Designer1() (pst_bitDMACPeriID3() -> Designer1)            
#define biGetDMACPeriID3_Revision() (pst_bitDMACPeriID3() -> Revision)            
            
/* Word access */

#define u32GetDMACPeriID3()  (*pu32DMACPeriID3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACPCellID0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010CFF0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACPCellID0_REG__       0xC010CFF0U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DMACPCellID0	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACPCellID0_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACPCellID0_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACPCellID0()     ((volatile DMACPCellID0_bit_view_st *)\
(DMACPCellID0_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACPCellID0()     ((volatile u32DMACPCellID0_word_view *)\
(DMACPCellID0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACPCellID0_DMACPCellID0() (pst_bitDMACPCellID0() -> DMACPCellID0)
            
/* Word access */

#define u32GetDMACPCellID0()  (*pu32DMACPCellID0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACPCellID1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010CFF4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACPCellID1_REG__       0xC010CFF4U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DMACPCellID1	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACPCellID1_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACPCellID1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACPCellID1()     ((volatile DMACPCellID1_bit_view_st *)\
(DMACPCellID1_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACPCellID1()     ((volatile u32DMACPCellID1_word_view *)\
(DMACPCellID1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACPCellID1_DMACPCellID1() (pst_bitDMACPCellID1() -> DMACPCellID1)            
            
/* Word access */

#define u32GetDMACPCellID1()  (*pu32DMACPCellID1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACPCellID2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010CFF8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACPCellID2_REG__       0xC010CFF8U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DMACPCellID2	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACPCellID2_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACPCellID2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACPCellID2()     ((volatile DMACPCellID2_bit_view_st *)\
(DMACPCellID2_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACPCellID2()     ((volatile u32DMACPCellID2_word_view *)\
(DMACPCellID2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACPCellID2_DMACPCellID2() (pst_bitDMACPCellID2() -> DMACPCellID2)            
            
/* Word access */

#define u32GetDMACPCellID2()  (*pu32DMACPCellID2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACPCellID3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010CFFC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACPCellID3_REG__       0xC010CFFCU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DMACPCellID3	:8; 	 /* 0..7  bit(s) R */ 
  uint32_t   Reserved	:24; 	 /* 8..31  bit(s) R */                    
} DMACPCellID3_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACPCellID3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACPCellID3()     ((volatile DMACPCellID3_bit_view_st *)\
(DMACPCellID3_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACPCellID3()     ((volatile u32DMACPCellID3_word_view *)\
(DMACPCellID3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetDMACPCellID3_DMACPCellID3() (pst_bitDMACPCellID3() -> DMACPCellID3)            
            
/* Word access */

#define u32GetDMACPCellID3()  (*pu32DMACPCellID3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACITCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C500                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACITCR_REG__       0xC010C500U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   T	:1; 	 /* 0..0  bit(s) R/W */ 
  uint32_t   Reserved	:31; 	 /* 1..31  bit(s) R */                    
} DMACITCR_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACITCR_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACITCR()     ((volatile DMACITCR_bit_view_st *)\
(DMACITCR_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACITCR()     ((volatile u32DMACITCR_word_view *)\
(DMACITCR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACITCR_T() (pst_bitDMACITCR() -> T)
#define vSetDMACITCR_T(ParValue)  (pst_bitDMACITCR() -> T=(ParValue))            
            
/* Word access */
#define vSetDMACITCR(ParValue)  (*pu32DMACITCR() = (ParValue))
#define u32GetDMACITCR()  (*pu32DMACITCR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACITOP1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C504                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACITOP1_REG__       0xC010C504U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DMACCLR	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   Reserved	:16; 	 /* 16..31  bit(s) R */                    
} DMACITOP1_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACITOP1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACITOP1()     ((volatile DMACITOP1_bit_view_st *)\
(DMACITOP1_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACITOP1()     ((volatile u32DMACITOP1_word_view *)\
(DMACITOP1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACITOP1_DMACCLR() (pst_bitDMACITOP1() -> DMACCLR)
#define vSetDMACITOP1_DMACCLR(ParValue)  (pst_bitDMACITOP1() -> DMACCLR=(ParValue))            
            
/* Word access */
#define vSetDMACITOP1(ParValue)  (*pu32DMACITOP1() = (ParValue))
#define u32GetDMACITOP1()  (*pu32DMACITOP1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACITOP2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C508                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACITOP2_REG__       0xC010C508U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   DMACTC	:16; 	 /* 0..15  bit(s) R/W */ 
  uint32_t   Reserved	:16; 	 /* 16..31  bit(s) R */                    
} DMACITOP2_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACITOP2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACITOP2()     ((volatile DMACITOP2_bit_view_st *)\
(DMACITOP2_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACITOP2()     ((volatile u32DMACITOP2_word_view *)\
(DMACITOP2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACITOP2_DMACTC() (pst_bitDMACITOP2() -> DMACTC)
#define vSetDMACITOP2_DMACTC(ParValue)  (pst_bitDMACITOP2() -> DMACTC=(ParValue))            
            
/* Word access */
#define vSetDMACITOP2(ParValue)  (*pu32DMACITOP2() = (ParValue))
#define u32GetDMACITOP2()  (*pu32DMACITOP2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: DMACITOP3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010C50C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define DMACITOP3_REG__       0xC010C50CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   TC	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   E	:1; 	 /* 1..1  bit(s) R */ 
  uint32_t   Reserved	:30; 	 /* 2..31  bit(s) R */                    
} DMACITOP3_bit_view_st;
        

/* WORD View */
typedef uint32_t u32DMACITOP3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitDMACITOP3()     ((volatile DMACITOP3_bit_view_st *)\
(DMACITOP3_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32DMACITOP3()     ((volatile u32DMACITOP3_word_view *)\
(DMACITOP3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetDMACITOP3_TC() (pst_bitDMACITOP3() -> TC)
#define vSetDMACITOP3_TC(ParValue)  (pst_bitDMACITOP3() -> TC=(ParValue))            
#define biGetDMACITOP3_E() (pst_bitDMACITOP3() -> E)            
            
/* Word access */
#define vSetDMACITOP3(ParValue)  (*pu32DMACITOP3() = (ParValue))
#define u32GetDMACITOP3()  (*pu32DMACITOP3() )
            

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning /* enable Rule 3.5 [R] : derived  disable warnings for nonstandard type for a bit field */
#endif /* defined(__GHS__) || defined(__ghs__) */


#endif /* _DMACIO_H */

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

