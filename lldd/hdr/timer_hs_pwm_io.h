
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : HSPWM 
/  Date of creation (y-m-d:time): 2015-02-18+01:00  :  15:40:00.056+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.12 $ 
/  Excel Sheet ver.             : vv1.2
/  Excel Sheet date             : 2014-Sep-17
/  Excel Sheet author           : ZUL
/##########################################################################*/

/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TIMER_HS_PWM low level device driver io-header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_HS_PWM
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/


#ifndef HSPWMIO_H
#define HSPWMIO_H

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
#define LLDD_TIMER_HS_PWM_IO_H_REVISION     "$Revision: 1.12 $"
#define LLDD_TIMER_HS_PWM_IO_H_TAG          "$Name: LLDD_1_6 $"
     
/****************************************************************************
*                          CHANNEL SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/

typedef enum tag_timer_hs_pwm_cntrl_def_e
{
  TIMER_HS_PWM_CNTRL_0__ = 0,
  TIMER_HS_PWM_CNTRL_1__ = 0x1000,  
  TIMER_HS_PWM_CNTRL_2__ = 0x2000,
  TIMER_HS_PWM_CNTRL_3__ = 0x3000 
} timer_hs_pwm_cntrl_def_e;

/****************************************************************************   
*                                                                               
*       REGISTER: HSPWMCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0408000                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define HSPWMCR_REG__       0xC0408000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   TRUN	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   RSRVD1	:1; 	 /* 1..1  bit(s) R/W */
  uint16_t   PREEN	:1; 	 /* 2..2  bit(s) R/W */
  uint16_t   	:1; 	 /* 3..3  bit(s) R */
  uint16_t   OL	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   DB	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   IE	:1; 	 /* 6..6  bit(s) R/W */
  uint16_t   RSRVD7	:5; 	 /* 7..11  bit(s) R/W */
  uint16_t   SCLK	:3; 	 /* 12..14  bit(s) R/W */
  uint16_t   RSRVD15	:1; 	 /* 15..15  bit(s) R/W */                    
} HSPWMCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} HSPWMCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16HSPWMCR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitHSPWMCR(ctrlr)     ((volatile HSPWMCR_bit_view_st *)\
(HSPWMCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8HSPWMCR(ctrlr)     ((volatile HSPWMCR_byte_view_st *)\
(HSPWMCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16HSPWMCR(ctrlr)     ((volatile u16HSPWMCR_halfword_view *)\
(HSPWMCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetHSPWMCR_TRUN(ctrlr) (pst_bitHSPWMCR(ctrlr) -> TRUN)
#define vSetHSPWMCR_TRUN(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> TRUN=(ParValue))
#define biGetHSPWMCR_RSRVD1(ctrlr) (pst_bitHSPWMCR(ctrlr) -> RSRVD1)
#define vSetHSPWMCR_RSRVD1(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> RSRVD1=(ParValue))
#define biGetHSPWMCR_PREEN(ctrlr) (pst_bitHSPWMCR(ctrlr) -> PREEN)
#define vSetHSPWMCR_PREEN(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> PREEN=(ParValue))
#define biGetHSPWMCR_OL(ctrlr) (pst_bitHSPWMCR(ctrlr) -> OL)
#define vSetHSPWMCR_OL(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> OL=(ParValue))
#define biGetHSPWMCR_DB(ctrlr) (pst_bitHSPWMCR(ctrlr) -> DB)
#define vSetHSPWMCR_DB(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> DB=(ParValue))
#define biGetHSPWMCR_IE(ctrlr) (pst_bitHSPWMCR(ctrlr) -> IE)
#define vSetHSPWMCR_IE(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> IE=(ParValue))
#define biGetHSPWMCR_RSRVD7(ctrlr) (pst_bitHSPWMCR(ctrlr) -> RSRVD7)
#define vSetHSPWMCR_RSRVD7(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> RSRVD7=(ParValue))
#define biGetHSPWMCR_SCLK(ctrlr) (pst_bitHSPWMCR(ctrlr) -> SCLK)
#define vSetHSPWMCR_SCLK(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> SCLK=(ParValue))
#define biGetHSPWMCR_RSRVD15(ctrlr) (pst_bitHSPWMCR(ctrlr) -> RSRVD15)
#define vSetHSPWMCR_RSRVD15(ctrlr,ParValue)  (pst_bitHSPWMCR(ctrlr) -> RSRVD15=(ParValue))
            
/* L-struct byte access */
#define vSetHSPWMCRL(ctrlr,ParValue) (pst_u8HSPWMCR(ctrlr) -> u8L = (ParValue))
#define u8GetHSPWMCRL(ctrlr) (pst_u8HSPWMCR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetHSPWMCRH(ctrlr,ParValue) (pst_u8HSPWMCR(ctrlr) -> u8H = (ParValue))
#define u8GetHSPWMCRH(ctrlr) (pst_u8HSPWMCR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetHSPWMCR(ctrlr,ParValue) (*pu16HSPWMCR(ctrlr)  = (ParValue))
#define u16GetHSPWMCR(ctrlr) (*pu16HSPWMCR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: HSPWMPDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0408004                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define HSPWMPDR_REG__       0xC0408004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   HSPWMPDR	:16; 	 /* 0..15  bit(s) R/W */                    
} HSPWMPDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} HSPWMPDR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16HSPWMPDR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitHSPWMPDR(ctrlr)     ((volatile HSPWMPDR_bit_view_st *)\
(HSPWMPDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8HSPWMPDR(ctrlr)     ((volatile HSPWMPDR_byte_view_st *)\
(HSPWMPDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16HSPWMPDR(ctrlr)     ((volatile u16HSPWMPDR_halfword_view *)\
(HSPWMPDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetHSPWMPDR_HSPWMPDR(ctrlr) (pst_bitHSPWMPDR(ctrlr) -> HSPWMPDR)
#define vSetHSPWMPDR_HSPWMPDR(ctrlr,ParValue)  (pst_bitHSPWMPDR(ctrlr) -> HSPWMPDR=(ParValue))
            
/* L-struct byte access */
#define vSetHSPWMPDRL(ctrlr,ParValue) (pst_u8HSPWMPDR(ctrlr) -> u8L = (ParValue))
#define u8GetHSPWMPDRL(ctrlr) (pst_u8HSPWMPDR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetHSPWMPDRH(ctrlr,ParValue) (pst_u8HSPWMPDR(ctrlr) -> u8H = (ParValue))
#define u8GetHSPWMPDRH(ctrlr) (pst_u8HSPWMPDR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetHSPWMPDR(ctrlr,ParValue) (*pu16HSPWMPDR(ctrlr)  = (ParValue))
#define u16GetHSPWMPDR(ctrlr) (*pu16HSPWMPDR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: HSPWMDDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0408008                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define HSPWMDDR_REG__       0xC0408008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   HSPWMDDR	:16; 	 /* 0..15  bit(s) R/W */                    
} HSPWMDDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} HSPWMDDR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16HSPWMDDR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitHSPWMDDR(ctrlr)     ((volatile HSPWMDDR_bit_view_st *)\
(HSPWMDDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8HSPWMDDR(ctrlr)     ((volatile HSPWMDDR_byte_view_st *)\
(HSPWMDDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16HSPWMDDR(ctrlr)     ((volatile u16HSPWMDDR_halfword_view *)\
(HSPWMDDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetHSPWMDDR_HSPWMDDR(ctrlr) (pst_bitHSPWMDDR(ctrlr) -> HSPWMDDR)
#define vSetHSPWMDDR_HSPWMDDR(ctrlr,ParValue)  (pst_bitHSPWMDDR(ctrlr) -> HSPWMDDR=(ParValue))
            
/* L-struct byte access */
#define vSetHSPWMDDRL(ctrlr,ParValue) (pst_u8HSPWMDDR(ctrlr) -> u8L = (ParValue))
#define u8GetHSPWMDDRL(ctrlr) (pst_u8HSPWMDDR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetHSPWMDDRH(ctrlr,ParValue) (pst_u8HSPWMDDR(ctrlr) -> u8H = (ParValue))
#define u8GetHSPWMDDRH(ctrlr) (pst_u8HSPWMDDR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetHSPWMDDR(ctrlr,ParValue) (*pu16HSPWMDDR(ctrlr)  = (ParValue))
#define u16GetHSPWMDDR(ctrlr) (*pu16HSPWMDDR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: HSPWMCNT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC040800C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define HSPWMCNT_REG__       0xC040800CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   HSPWMCNT	:16; 	 /* 0..15  bit(s) R/W */                    
} HSPWMCNT_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} HSPWMCNT_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16HSPWMCNT_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitHSPWMCNT(ctrlr)     ((volatile HSPWMCNT_bit_view_st *)\
(HSPWMCNT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8HSPWMCNT(ctrlr)     ((volatile HSPWMCNT_byte_view_st *)\
(HSPWMCNT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16HSPWMCNT(ctrlr)     ((volatile u16HSPWMCNT_halfword_view *)\
(HSPWMCNT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetHSPWMCNT_HSPWMCNT(ctrlr) (pst_bitHSPWMCNT(ctrlr) -> HSPWMCNT)
#define vSetHSPWMCNT_HSPWMCNT(ctrlr,ParValue)  (pst_bitHSPWMCNT(ctrlr) -> HSPWMCNT=(ParValue))
            
/* L-struct byte access */
#define vSetHSPWMCNTL(ctrlr,ParValue) (pst_u8HSPWMCNT(ctrlr) -> u8L = (ParValue))
#define u8GetHSPWMCNTL(ctrlr) (pst_u8HSPWMCNT(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetHSPWMCNTH(ctrlr,ParValue) (pst_u8HSPWMCNT(ctrlr) -> u8H = (ParValue))
#define u8GetHSPWMCNTH(ctrlr) (pst_u8HSPWMCNT(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetHSPWMCNT(ctrlr,ParValue) (*pu16HSPWMCNT(ctrlr)  = (ParValue))
#define u16GetHSPWMCNT(ctrlr) (*pu16HSPWMCNT(ctrlr) )


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

    

#endif /* HSPWMIO_H */ 
    
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

