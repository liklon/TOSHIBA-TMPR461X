/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : WDT 
/  Date of creation (y-m-d:time): 2013-06-28+02:00  :  16:37:56.874+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.10 $ 
/  Excel Sheet ver.             : vv1.1
/  Excel Sheet date             : 2013-Jun-19
/  Excel Sheet author           : VAG
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
*   VERSION     : $Revision: 1.10 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef WDTIO_H
#define WDTIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */ 

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_WDT_IO_H_REVISION     "$Revision: 1.10 $"
#define LLDD_WDT_IO_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/
/* disable following Misra errors for io files */
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 230   /* Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types */
#endif    
/****************************************************************************   
*                                                                               
*       REGISTER: CNT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0002000                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CNT_REG__       0xC0002000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CNT	:20; 	 /* 0..19  bit(s) R */ 
  uint32_t   	:12; 	 /* 20..31  bit(s) R */                    
} CNT_bit_view_st;
        

/* WORD View */
typedef uint32_t u32CNT_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCNT()     ((volatile CNT_bit_view_st *)\
(CNT_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32CNT()     ((volatile u32CNT_word_view *)\
(CNT_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCNT_CNT() (pst_bitCNT() -> CNT)
            
/* Word access */

#define u32GetCNT()  (*pu32CNT() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MIN                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0002004                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MIN_REG__       0xC0002004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MIN	:20; 	 /* 0..19  bit(s) R/W */ 
  uint32_t   	:12; 	 /* 20..31  bit(s) R */                    
} MIN_bit_view_st;
        

/* WORD View */
typedef uint32_t u32MIN_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMIN()     ((volatile MIN_bit_view_st *)\
(MIN_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32MIN()     ((volatile u32MIN_word_view *)\
(MIN_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMIN_MIN() (pst_bitMIN() -> MIN)
#define vSetMIN_MIN(ParValue)  (pst_bitMIN() -> MIN=(ParValue))
            
/* Word access */
#define vSetMIN(ParValue)  (*pu32MIN() = (ParValue))
#define u32GetMIN()  (*pu32MIN() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: MAX                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0002008                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define MAX_REG__       0xC0002008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   MAX	:20; 	 /* 0..19  bit(s) R/W */ 
  uint32_t   	:12; 	 /* 20..31  bit(s) R */                    
} MAX_bit_view_st;
        

/* WORD View */
typedef uint32_t u32MAX_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitMAX()     ((volatile MAX_bit_view_st *)\
(MAX_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32MAX()     ((volatile u32MAX_word_view *)\
(MAX_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetMAX_MAX() (pst_bitMAX() -> MAX)
#define vSetMAX_MAX(ParValue)  (pst_bitMAX() -> MAX=(ParValue))
            
/* Word access */
#define vSetMAX(ParValue)  (*pu32MAX() = (ParValue))
#define u32GetMAX()  (*pu32MAX() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CTL                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC000200C                             
*       ACCESS  : BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CTL_REG__       0xC000200CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   WDTDIS	:1; 	 /* 0..0  bit(s) R/W */ 
  uint8_t   	:7; 	 /* 1..31  bit(s) R */                    
} CTL_bit_view_st;
        
     


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCTL()     ((volatile CTL_bit_view_st *)\
(CTL_REG__ ))
             

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCTL_WDTDIS() (pst_bitCTL() -> WDTDIS)
#define vSetCTL_WDTDIS(ParValue)  (pst_bitCTL() -> WDTDIS=(ParValue))     
    
/****************************************************************************   
*                                                                               
*       REGISTER: CMD                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0002010                             
*       ACCESS  : BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define CMD_REG__       0xC0002010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   CMD	:16; 	 /* 0..15  bit(s) W */                    
} CMD_bit_view_st;
        
     


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitCMD()     ((volatile CMD_bit_view_st *)\
(CMD_REG__ ))
             

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetCMD_CMD(ParValue) (pst_bitCMD() -> CMD=(ParValue))


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
** |     Requested Rules:
** |         Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types
** |                         Used for bit definitons generated by converter tool
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/

#endif /* WDTIO_H */ 
    
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

