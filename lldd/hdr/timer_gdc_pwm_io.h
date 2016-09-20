
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : GDCPWM 
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:54:56.233+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.12 $ 
/  Excel Sheet ver.             : vv1.1
/  Excel Sheet date             : 2013-Jun-19
/  Excel Sheet author           : VAG
/##########################################################################*/

/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : TIMER_GDC_PWM low level device driver io-header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TIMER_GDC_PWM
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/


#ifndef GDCPWMIO_H
#define GDCPWMIO_H

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
#define LLDD_TIMER_GDC_PWM_IO_H_REVISION     "$Revision: 1.12 $"
#define LLDD_TIMER_GDC_PWM_IO_H_TAG          "$Name: LLDD_1_6 $"
     
/****************************************************************************
*                          CHANNEL SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/

typedef enum tag_timer_gdc_pwm_cntrl_def_e
{
  TIMER_GDC_PWM_CNTRL_0__ = 0,
  TIMER_GDC_PWM_CNTRL_1__ = 0x1000 
} timer_gdc_pwm_cntrl_def_e;


/****************************************************************************   
*                                                                               
*       REGISTER: GPWMCR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0325000                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define GPWMCR_REG__       0xC0325000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   TRUN	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   GDC	:2; 	 /* 1..2  bit(s) R/W */
  uint16_t   	:1; 	 /* 3..3  bit(s) R */
  uint16_t   OL	:1; 	 /* 4..4  bit(s) R/W */
  uint16_t   DB	:1; 	 /* 5..5  bit(s) R/W */
  uint16_t   IE	:1; 	 /* 6..6  bit(s) R/W */
  uint16_t   TCORE_EN	:1; 	 /* 7..7  bit(s) R/W */
  uint16_t   HED	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   VED	:1; 	 /* 9..9  bit(s) R/W */
  uint16_t   RC	:2; 	 /* 10..11  bit(s) R/W */
  uint16_t   SCLK	:3; 	 /* 12..14  bit(s) R/W */
  uint16_t   RSRVD15	:1; 	 /* 15..15  bit(s) R/W */                    
} GPWMCR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GPWMCR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GPWMCR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGPWMCR(ctrlr)     ((volatile GPWMCR_bit_view_st *)\
(GPWMCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GPWMCR(ctrlr)     ((volatile GPWMCR_byte_view_st *)\
(GPWMCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16GPWMCR(ctrlr)     ((volatile u16GPWMCR_halfword_view *)\
(GPWMCR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGPWMCR_TRUN(ctrlr) (pst_bitGPWMCR(ctrlr) -> TRUN)
#define vSetGPWMCR_TRUN(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> TRUN=(ParValue))
#define biGetGPWMCR_GDC(ctrlr) (pst_bitGPWMCR(ctrlr) -> GDC)
#define vSetGPWMCR_GDC(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> GDC=(ParValue))
#define biGetGPWMCR_OL(ctrlr) (pst_bitGPWMCR(ctrlr) -> OL)
#define vSetGPWMCR_OL(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> OL=(ParValue))
#define biGetGPWMCR_DB(ctrlr) (pst_bitGPWMCR(ctrlr) -> DB)
#define vSetGPWMCR_DB(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> DB=(ParValue))
#define biGetGPWMCR_IE(ctrlr) (pst_bitGPWMCR(ctrlr) -> IE)
#define vSetGPWMCR_IE(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> IE=(ParValue))
#define biGetGPWMCR_TCORE_EN(ctrlr) (pst_bitGPWMCR(ctrlr) -> TCORE_EN)
#define vSetGPWMCR_TCORE_EN(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> TCORE_EN=(ParValue))
#define biGetGPWMCR_HED(ctrlr) (pst_bitGPWMCR(ctrlr) -> HED)
#define vSetGPWMCR_HED(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> HED=(ParValue))
#define biGetGPWMCR_VED(ctrlr) (pst_bitGPWMCR(ctrlr) -> VED)
#define vSetGPWMCR_VED(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> VED=(ParValue))
#define biGetGPWMCR_RC(ctrlr) (pst_bitGPWMCR(ctrlr) -> RC)
#define vSetGPWMCR_RC(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> RC=(ParValue))
#define biGetGPWMCR_SCLK(ctrlr) (pst_bitGPWMCR(ctrlr) -> SCLK)
#define vSetGPWMCR_SCLK(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> SCLK=(ParValue))
#define biGetGPWMCR_RSRVD15(ctrlr) (pst_bitGPWMCR(ctrlr) -> RSRVD15)
#define vSetGPWMCR_RSRVD15(ctrlr,ParValue)  (pst_bitGPWMCR(ctrlr) -> RSRVD15=(ParValue))
            
/* L-struct byte access */
#define vSetGPWMCRL(ctrlr,ParValue) (pst_u8GPWMCR(ctrlr) -> u8L = (ParValue))
#define u8GetGPWMCRL(ctrlr) (pst_u8GPWMCR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGPWMCRH(ctrlr,ParValue) (pst_u8GPWMCR(ctrlr) -> u8H = (ParValue))
#define u8GetGPWMCRH(ctrlr) (pst_u8GPWMCR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGPWMCR(ctrlr,ParValue) (*pu16GPWMCR(ctrlr)  = (ParValue))
#define u16GetGPWMCR(ctrlr) (*pu16GPWMCR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GPWMPDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0325004                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define GPWMPDR_REG__       0xC0325004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   GPWMPDR	:16; 	 /* 0..15  bit(s) R/W */                    
} GPWMPDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GPWMPDR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GPWMPDR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGPWMPDR(ctrlr)     ((volatile GPWMPDR_bit_view_st *)\
(GPWMPDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GPWMPDR(ctrlr)     ((volatile GPWMPDR_byte_view_st *)\
(GPWMPDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16GPWMPDR(ctrlr)     ((volatile u16GPWMPDR_halfword_view *)\
(GPWMPDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGPWMPDR_GPWMPDR(ctrlr) (pst_bitGPWMPDR(ctrlr) -> GPWMPDR)
#define vSetGPWMPDR_GPWMPDR(ctrlr,ParValue)  (pst_bitGPWMPDR(ctrlr) -> GPWMPDR=(ParValue))
            
/* L-struct byte access */
#define vSetGPWMPDRL(ctrlr,ParValue) (pst_u8GPWMPDR(ctrlr) -> u8L = (ParValue))
#define u8GetGPWMPDRL(ctrlr) (pst_u8GPWMPDR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGPWMPDRH(ctrlr,ParValue) (pst_u8GPWMPDR(ctrlr) -> u8H = (ParValue))
#define u8GetGPWMPDRH(ctrlr) (pst_u8GPWMPDR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGPWMPDR(ctrlr,ParValue) (*pu16GPWMPDR(ctrlr)  = (ParValue))
#define u16GetGPWMPDR(ctrlr) (*pu16GPWMPDR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GPWMDDR                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0325008                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define GPWMDDR_REG__       0xC0325008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   GPWMDDR	:16; 	 /* 0..15  bit(s) R/W */                    
} GPWMDDR_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GPWMDDR_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GPWMDDR_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGPWMDDR(ctrlr)     ((volatile GPWMDDR_bit_view_st *)\
(GPWMDDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GPWMDDR(ctrlr)     ((volatile GPWMDDR_byte_view_st *)\
(GPWMDDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16GPWMDDR(ctrlr)     ((volatile u16GPWMDDR_halfword_view *)\
(GPWMDDR_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGPWMDDR_GPWMDDR(ctrlr) (pst_bitGPWMDDR(ctrlr) -> GPWMDDR)
#define vSetGPWMDDR_GPWMDDR(ctrlr,ParValue)  (pst_bitGPWMDDR(ctrlr) -> GPWMDDR=(ParValue))
            
/* L-struct byte access */
#define vSetGPWMDDRL(ctrlr,ParValue) (pst_u8GPWMDDR(ctrlr) -> u8L = (ParValue))
#define u8GetGPWMDDRL(ctrlr) (pst_u8GPWMDDR(ctrlr) -> u8L)
/* H-struct byte access */
#define vSetGPWMDDRH(ctrlr,ParValue) (pst_u8GPWMDDR(ctrlr) -> u8H = (ParValue))
#define u8GetGPWMDDRH(ctrlr) (pst_u8GPWMDDR(ctrlr) -> u8H)
            
/* Half-word access */ 
#define vSetGPWMDDR(ctrlr,ParValue) (*pu16GPWMDDR(ctrlr)  = (ParValue))
#define u16GetGPWMDDR(ctrlr) (*pu16GPWMDDR(ctrlr) )     
    
/****************************************************************************   
*                                                                               
*       REGISTER: GPWMCNT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC032500C                             
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define GPWMCNT_REG__       0xC032500CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint16_t   GPWMCNT	:16; 	 /* 0..15  bit(s) R */                    
} GPWMCNT_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8L;       
  uint8_t u8H;       
} GPWMCNT_byte_view_st;
            
/* HALFWORD View */
typedef uint16_t u16GPWMCNT_halfword_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGPWMCNT(ctrlr)     ((volatile GPWMCNT_bit_view_st *)\
(GPWMCNT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
        
/* Pointer to BYTE-struct  */
#define pst_u8GPWMCNT(ctrlr)     ((volatile GPWMCNT_byte_view_st *)\
(GPWMCNT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
            
/* Pointer to HALFWORD */
#define pu16GPWMCNT(ctrlr)     ((volatile u16GPWMCNT_halfword_view *)\
(GPWMCNT_REG__  + ((uint8_t)(ctrlr) * 0x1000U) ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetGPWMCNT_GPWMCNT(ctrlr) (pst_bitGPWMCNT(ctrlr) -> GPWMCNT)
            
/* L-struct byte access */

#define u8GetGPWMCNTL(ctrlr) (pst_u8GPWMCNT(ctrlr) -> u8L)
/* H-struct byte access */

#define u8GetGPWMCNTH(ctrlr) (pst_u8GPWMCNT(ctrlr) -> u8H)
            
/* Half-word access */ 

#define u16GetGPWMCNT(ctrlr) (*pu16GPWMCNT(ctrlr) )


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



    

#endif /* GDCPWMIO_H */ 
    
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

