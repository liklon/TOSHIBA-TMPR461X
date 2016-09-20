
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : PWM 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  18:00:57.146+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.13 $ 
/  Excel Sheet ver.             : vv1.1
/  Excel Sheet date             : 2013-Jun-19
/  Excel Sheet author           : VAG
/##########################################################################*/

/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TIMER_PWM low level device driver io-header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_PWM
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.13 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/


#ifndef PWMIO_H
#define PWMIO_H

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
#define LLDD_TIMER_PWM_IO_H_REVISION     "$Revision: 1.13 $"
#define LLDD_TIMER_PWM_IO_H_TAG          "$Name: LLDD_1_6 $"    

/****************************************************************************
*                          CONTROLER SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
typedef enum tag_timer_pwm_cntrl_def_e
{
  TIMER_PWM_CNTRL_0__  =0,
  TIMER_PWM_CNTRL_1__  =0x1000,
  TIMER_PWM_CNTRL_2__  =0x2000,
  TIMER_PWM_CNTRL_3__  =0x3000,
  TIMER_PWM_CNTRL_4__  =0x4000,
  TIMER_PWM_CNTRL_5__  =0x5000,
  TIMER_PWM_CNTRL_6__  =0x6000,
  TIMER_PWM_CNTRL_7__  =0x7000,
  TIMER_PWM_CNTRL_8__  =0x8000,
  TIMER_PWM_CNTRL_9__  =0x9000,
  TIMER_PWM_CNTRL_10__ =0xA000,
  TIMER_PWM_CNTRL_11__ =0xB000,
  TIMER_PWM_CNTRL_12__ =0xC000,
  TIMER_PWM_CNTRL_13__ =0xD000,
  TIMER_PWM_CNTRL_14__ =0xE000,
  TIMER_PWM_CNTRL_15__ =0xF000,
  TIMER_PWM_CNTRL_16__ =0x10000,
  TIMER_PWM_CNTRL_17__ =0x11000,
  TIMER_PWM_CNTRL_18__ =0x12000,
  TIMER_PWM_CNTRL_19__ =0x13000,
  TIMER_PWM_CNTRL_20__ =0x14000,
  TIMER_PWM_CNTRL_21__ =0x15000,
  TIMER_PWM_CNTRL_22__ =0x16000,
  TIMER_PWM_CNTRL_23__ =0x17000
} timer_pwm_cntrl_def_e;


/****************************************************************************   
*                                                                               
*       REGISTER: PWMCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0304000                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PWMCR_REG__       0xC0304000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   TRUN	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   GDC	:2; 	 /* 1..2  bit(s) R/W */
  uint16_t   	:1; 	 /* 3..3  bit(s) R */
  uint16_t   OL	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   DB	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   IE	:1; 	 /* 6..6  bit(s) R/W */
  uint16_t   	:1; 	 /* 7..7  bit(s) R */
  uint16_t   HED	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   VED	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   RC	:2; 	 /* 10..11  bit(s) R/W */
  uint16_t   SCLK	:3; 	 /* 12..14  bit(s) R/W */
  uint16_t   RSRVD15	:1; 	 /* 15..15  bit(s) R/W */                    
} PWMCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PWMCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PWMCR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPWMCR(ctrlr)     ((volatile PWMCR_bit_view_st *)\
(PWMCR_REG__  + (uint32_t)(ctrlr) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PWMCR(ctrlr)     ((volatile PWMCR_byte_view_st *)\
(PWMCR_REG__  + (uint32_t)(ctrlr) ))
            
/* Pointer to HALFWORD */
#define pu16PWMCR(ctrlr)     ((volatile u16PWMCR_halfword_view *)\
(PWMCR_REG__  + (uint32_t)(ctrlr) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPWMCR_TRUN(ctrlr) (pst_bitPWMCR(ctrlr) -> TRUN)
#define vSetPWMCR_TRUN(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> TRUN=(ParValue))
#define biGetPWMCR_GDC(ctrlr) (pst_bitPWMCR(ctrlr) -> GDC)
#define vSetPWMCR_GDC(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> GDC=(ParValue))
#define biGetPWMCR_OL(ctrlr) (pst_bitPWMCR(ctrlr) -> OL)
#define vSetPWMCR_OL(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> OL=(ParValue))
#define biGetPWMCR_DB(ctrlr) (pst_bitPWMCR(ctrlr) -> DB)
#define vSetPWMCR_DB(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> DB=(ParValue))
#define biGetPWMCR_IE(ctrlr) (pst_bitPWMCR(ctrlr) -> IE)
#define vSetPWMCR_IE(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> IE=(ParValue))
#define biGetPWMCR_HED(ctrlr) (pst_bitPWMCR(ctrlr) -> HED)
#define vSetPWMCR_HED(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> HED=(ParValue))
#define biGetPWMCR_VED(ctrlr) (pst_bitPWMCR(ctrlr) -> VED)
#define vSetPWMCR_VED(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> VED=(ParValue))
#define biGetPWMCR_RC(ctrlr) (pst_bitPWMCR(ctrlr) -> RC)
#define vSetPWMCR_RC(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> RC=(ParValue))
#define biGetPWMCR_SCLK(ctrlr) (pst_bitPWMCR(ctrlr) -> SCLK)
#define vSetPWMCR_SCLK(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> SCLK=(ParValue))
#define biGetPWMCR_RSRVD15(ctrlr) (pst_bitPWMCR(ctrlr) -> RSRVD15)
#define vSetPWMCR_RSRVD15(ctrlr,ParValue)  (pst_bitPWMCR(ctrlr) -> RSRVD15=(ParValue))
            
/* L-struct byte access */
#define vSetPWMCRL(ctrlr,ParValue) (pst_u8PWMCR(ctrlr) -> u8L = (ParValue))
#define u8GetPWMCRL(ctrlr) (pst_u8PWMCR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetPWMCRH(ctrlr,ParValue) (pst_u8PWMCR(ctrlr) -> u8H = (ParValue))
#define u8GetPWMCRH(ctrlr) (pst_u8PWMCR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetPWMCR(ctrlr,ParValue) (*pu16PWMCR(ctrlr)  = (ParValue))
#define u16GetPWMCR(ctrlr) (*pu16PWMCR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PWMPDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0304004                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PWMPDR_REG__       0xC0304004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   PWMPDR	:16; 	 /* 0..15  bit(s) R/W */                    
} PWMPDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PWMPDR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PWMPDR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPWMPDR(ctrlr)     ((volatile PWMPDR_bit_view_st *)\
(PWMPDR_REG__  + (uint32_t)(ctrlr) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PWMPDR(ctrlr)     ((volatile PWMPDR_byte_view_st *)\
(PWMPDR_REG__  + (uint32_t)(ctrlr) ))
            
/* Pointer to HALFWORD */
#define pu16PWMPDR(ctrlr)     ((volatile u16PWMPDR_halfword_view *)\
(PWMPDR_REG__  + (uint32_t)(ctrlr) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPWMPDR_PWMPDR(ctrlr) (pst_bitPWMPDR(ctrlr) -> PWMPDR)
#define vSetPWMPDR_PWMPDR(ctrlr,ParValue)  (pst_bitPWMPDR(ctrlr) -> PWMPDR=(ParValue))
            
/* L-struct byte access */
#define vSetPWMPDRL(ctrlr,ParValue) (pst_u8PWMPDR(ctrlr) -> u8L = (ParValue))
#define u8GetPWMPDRL(ctrlr) (pst_u8PWMPDR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetPWMPDRH(ctrlr,ParValue) (pst_u8PWMPDR(ctrlr) -> u8H = (ParValue))
#define u8GetPWMPDRH(ctrlr) (pst_u8PWMPDR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetPWMPDR(ctrlr,ParValue) (*pu16PWMPDR(ctrlr)  = (ParValue))
#define u16GetPWMPDR(ctrlr) (*pu16PWMPDR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PWMDDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0304008                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PWMDDR_REG__       0xC0304008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   PWMDDR	:16; 	 /* 0..15  bit(s) R/W */                    
} PWMDDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PWMDDR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PWMDDR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPWMDDR(ctrlr)     ((volatile PWMDDR_bit_view_st *)\
(PWMDDR_REG__  + (uint32_t)(ctrlr) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PWMDDR(ctrlr)     ((volatile PWMDDR_byte_view_st *)\
(PWMDDR_REG__  + (uint32_t)(ctrlr) ))
            
/* Pointer to HALFWORD */
#define pu16PWMDDR(ctrlr)     ((volatile u16PWMDDR_halfword_view *)\
(PWMDDR_REG__  + (uint32_t)(ctrlr) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetPWMDDR_PWMDDR(ctrlr) (pst_bitPWMDDR(ctrlr) -> PWMDDR)
#define vSetPWMDDR_PWMDDR(ctrlr,ParValue)  (pst_bitPWMDDR(ctrlr) -> PWMDDR=(ParValue))
            
/* L-struct byte access */
#define vSetPWMDDRL(ctrlr,ParValue) (pst_u8PWMDDR(ctrlr) -> u8L = (ParValue))
#define u8GetPWMDDRL(ctrlr) (pst_u8PWMDDR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetPWMDDRH(ctrlr,ParValue) (pst_u8PWMDDR(ctrlr) -> u8H = (ParValue))
#define u8GetPWMDDRH(ctrlr) (pst_u8PWMDDR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetPWMDDR(ctrlr,ParValue) (*pu16PWMDDR(ctrlr)  = (ParValue))
#define u16GetPWMDDR(ctrlr) (*pu16PWMDDR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: PWMCNT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC030400C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define PWMCNT_REG__       0xC030400CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   PWMCNT	:16; 	 /* 0..15  bit(s) R */                    
} PWMCNT_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} PWMCNT_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16PWMCNT_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitPWMCNT(ctrlr)     ((volatile PWMCNT_bit_view_st *)\
(PWMCNT_REG__  + (uint32_t)(ctrlr) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8PWMCNT(ctrlr)     ((volatile PWMCNT_byte_view_st *)\
(PWMCNT_REG__  + (uint32_t)(ctrlr) ))
            
/* Pointer to HALFWORD */
#define pu16PWMCNT(ctrlr)     ((volatile u16PWMCNT_halfword_view *)\
(PWMCNT_REG__  + (uint32_t)(ctrlr) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetPWMCNT_PWMCNT(ctrlr) (pst_bitPWMCNT(ctrlr) -> PWMCNT)
            
/* L-struct byte access */

#define u8GetPWMCNTL(ctrlr) (pst_u8PWMCNT(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetPWMCNTH(ctrlr) (pst_u8PWMCNT(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetPWMCNT(ctrlr) (*pu16PWMCNT(ctrlr) )

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


    

#endif /* PWMIO_H */ 
    
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

