
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : RTC 
/  Date of creation (y-m-d:time): 2015-02-20+01:00  :  10:30:26.483+01:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.8 $ 
/  Excel Sheet ver.             : vv1.2
/  Excel Sheet date             : 2015-Feb-19
/  Excel Sheet author           : ALN
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : RTC low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : 
*   LIBRARIES   :
*****************************************************************************
*   VERSION     : $Revision: 1.8 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef RTCIO_H
#define RTCIO_H

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
#define LLDD_RTC_IO_H_REVISION     "$Revision: 1.8 $"
#define LLDD_RTC_IO_H_TAG          "$Name: LLDD_1_6 $"     
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCSECR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001000                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCSECR_REG__       0xC0001000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   SEC_DATA	:7; 	 /* 0..6  bit(s) R/W */ 
  uint8_t   	:1; 	 /* 7..7  bit(s) R */                    
} RTCSECR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCSECR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCSECR()     ((volatile RTCSECR_bit_view_st *)\
(RTCSECR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCSECR()     ((volatile u8RTCSECR_byte_view *)\
(RTCSECR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCSECR_SEC_DATA() (pst_bitRTCSECR() -> SEC_DATA)
#define vSetRTCSECR_SEC_DATA(ParValue)  (pst_bitRTCSECR() -> SEC_DATA=(ParValue))
            
/* byte access */
#define vSetRTCSECR(ParValue) (*pu8RTCSECR() = (ParValue))
#define u8GetRTCSECR() (*pu8RTCSECR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCMINR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001001                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCMINR_REG__       0xC0001001U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   MIN_DATA	:7; 	 /* 0..6  bit(s) R/W */ 
  uint8_t   	:1; 	 /* 7..7  bit(s) R */                    
} RTCMINR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCMINR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCMINR()     ((volatile RTCMINR_bit_view_st *)\
(RTCMINR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCMINR()     ((volatile u8RTCMINR_byte_view *)\
(RTCMINR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCMINR_MIN_DATA() (pst_bitRTCMINR() -> MIN_DATA)
#define vSetRTCMINR_MIN_DATA(ParValue)  (pst_bitRTCMINR() -> MIN_DATA=(ParValue))
            
/* byte access */
#define vSetRTCMINR(ParValue) (*pu8RTCMINR() = (ParValue))
#define u8GetRTCMINR() (*pu8RTCMINR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCHOURR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001002                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCHOURR_REG__       0xC0001002U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   HOUR_DATA	:6; 	 /* 0..5  bit(s) R/W */ 
  uint8_t   	:2; 	 /* 6..7  bit(s) R */                    
} RTCHOURR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCHOURR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCHOURR()     ((volatile RTCHOURR_bit_view_st *)\
(RTCHOURR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCHOURR()     ((volatile u8RTCHOURR_byte_view *)\
(RTCHOURR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCHOURR_HOUR_DATA() (pst_bitRTCHOURR() -> HOUR_DATA)
#define vSetRTCHOURR_HOUR_DATA(ParValue)  (pst_bitRTCHOURR() -> HOUR_DATA=(ParValue))
            
/* byte access */
#define vSetRTCHOURR(ParValue) (*pu8RTCHOURR() = (ParValue))
#define u8GetRTCHOURR() (*pu8RTCHOURR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCDAYR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001004                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCDAYR_REG__       0xC0001004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   DAY_DATA	:3; 	 /* 0..2  bit(s) R/W */ 
  uint8_t   	:5; 	 /* 3..7  bit(s) R */                    
} RTCDAYR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCDAYR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCDAYR()     ((volatile RTCDAYR_bit_view_st *)\
(RTCDAYR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCDAYR()     ((volatile u8RTCDAYR_byte_view *)\
(RTCDAYR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCDAYR_DAY_DATA() (pst_bitRTCDAYR() -> DAY_DATA)
#define vSetRTCDAYR_DAY_DATA(ParValue)  (pst_bitRTCDAYR() -> DAY_DATA=(ParValue))
            
/* byte access */
#define vSetRTCDAYR(ParValue) (*pu8RTCDAYR() = (ParValue))
#define u8GetRTCDAYR() (*pu8RTCDAYR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCDATER                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001005                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCDATER_REG__       0xC0001005U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   DATE_DATA	:6; 	 /* 0..5  bit(s) R/W */ 
  uint8_t   	:2; 	 /* 6..7  bit(s) R */                    
} RTCDATER_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCDATER_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCDATER()     ((volatile RTCDATER_bit_view_st *)\
(RTCDATER_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCDATER()     ((volatile u8RTCDATER_byte_view *)\
(RTCDATER_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCDATER_DATE_DATA() (pst_bitRTCDATER() -> DATE_DATA)
#define vSetRTCDATER_DATE_DATA(ParValue)  (pst_bitRTCDATER() -> DATE_DATA=(ParValue))
            
/* byte access */
#define vSetRTCDATER(ParValue) (*pu8RTCDATER() = (ParValue))
#define u8GetRTCDATER() (*pu8RTCDATER() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCMONTHR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001006                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCMONTHR_REG__       0xC0001006U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   MON_DATA	:8; 	 /* 0..7  bit(s) R/W */                    
} RTCMONTHR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCMONTHR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCMONTHR()     ((volatile RTCMONTHR_bit_view_st *)\
(RTCMONTHR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCMONTHR()     ((volatile u8RTCMONTHR_byte_view *)\
(RTCMONTHR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCMONTHR_MON_DATA() (pst_bitRTCMONTHR() -> MON_DATA)
#define vSetRTCMONTHR_MON_DATA(ParValue)  (pst_bitRTCMONTHR() -> MON_DATA=(ParValue))
            
/* byte access */
#define vSetRTCMONTHR(ParValue) (*pu8RTCMONTHR() = (ParValue))
#define u8GetRTCMONTHR() (*pu8RTCMONTHR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCYEARR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001007                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCYEARR_REG__       0xC0001007U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   YEAR_DATA	:8; 	 /* 0..7  bit(s) R/W */                    
} RTCYEARR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCYEARR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCYEARR()     ((volatile RTCYEARR_bit_view_st *)\
(RTCYEARR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCYEARR()     ((volatile u8RTCYEARR_byte_view *)\
(RTCYEARR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCYEARR_YEAR_DATA() (pst_bitRTCYEARR() -> YEAR_DATA)
#define vSetRTCYEARR_YEAR_DATA(ParValue)  (pst_bitRTCYEARR() -> YEAR_DATA=(ParValue))
            
/* byte access */
#define vSetRTCYEARR(ParValue) (*pu8RTCYEARR() = (ParValue))
#define u8GetRTCYEARR() (*pu8RTCYEARR() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCPAGER                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001008                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCPAGER_REG__       0xC0001008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   PAGE	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   	:1; 	 /* 1..1  bit(s) R */
  uint8_t   ENAALM	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   ENATMR	:1; 	 /* 3..3  bit(s) R/W */
  uint8_t   ADJUST	:1; 	 /* 4..4  bit(s) R/W */
  uint8_t   	:2; 	 /* 5..6  bit(s) R */ 
  uint8_t   INTENA	:1; 	 /* 7..7  bit(s) R/W */                    
} RTCPAGER_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCPAGER_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCPAGER()     ((volatile RTCPAGER_bit_view_st *)\
(RTCPAGER_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCPAGER()     ((volatile u8RTCPAGER_byte_view *)\
(RTCPAGER_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCPAGER_PAGE() (pst_bitRTCPAGER() -> PAGE)
#define vSetRTCPAGER_PAGE(ParValue)  (pst_bitRTCPAGER() -> PAGE=(ParValue))
#define biGetRTCPAGER_ENAALM() (pst_bitRTCPAGER() -> ENAALM)
#define vSetRTCPAGER_ENAALM(ParValue)  (pst_bitRTCPAGER() -> ENAALM=(ParValue))
#define biGetRTCPAGER_ENATMR() (pst_bitRTCPAGER() -> ENATMR)
#define vSetRTCPAGER_ENATMR(ParValue)  (pst_bitRTCPAGER() -> ENATMR=(ParValue))
#define biGetRTCPAGER_ADJUST() (pst_bitRTCPAGER() -> ADJUST)
#define vSetRTCPAGER_ADJUST(ParValue)  (pst_bitRTCPAGER() -> ADJUST=(ParValue))
#define biGetRTCPAGER_INTENA() (pst_bitRTCPAGER() -> INTENA)
#define vSetRTCPAGER_INTENA(ParValue)  (pst_bitRTCPAGER() -> INTENA=(ParValue))
            
/* byte access */
#define vSetRTCPAGER(ParValue) (*pu8RTCPAGER() = (ParValue))
#define u8GetRTCPAGER() (*pu8RTCPAGER() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCRESTR                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC000100C                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCRESTR_REG__       0xC000100CU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   DIS8HZ	:1; 	 /* 0..0  bit(s) R/W */
  uint8_t   DIS4HZ	:1; 	 /* 1..1  bit(s) R/W */
  uint8_t   DIS2HZ	:1; 	 /* 2..2  bit(s) R/W */
  uint8_t   	:1; 	 /* 3..3  bit(s) W */
  uint8_t   RSTALM	:1; 	 /* 4..4  bit(s) R/W */
  uint8_t   RSTTMR	:1; 	 /* 5..5  bit(s) R/W */
  uint8_t   DIS16HZ	:1; 	 /* 6..6  bit(s) R/W */ 
  uint8_t   DIS1HZ	:1; 	 /* 7..7  bit(s) R/W */                    
} RTCRESTR_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCRESTR_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCRESTR()     ((volatile RTCRESTR_bit_view_st *)\
(RTCRESTR_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCRESTR()     ((volatile u8RTCRESTR_byte_view *)\
(RTCRESTR_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCRESTR_DIS8HZ() (pst_bitRTCRESTR() -> DIS8HZ)
#define vSetRTCRESTR_DIS8HZ(ParValue)  (pst_bitRTCRESTR() -> DIS8HZ=(ParValue))
#define biGetRTCRESTR_DIS4HZ() (pst_bitRTCRESTR() -> DIS4HZ)
#define vSetRTCRESTR_DIS4HZ(ParValue)  (pst_bitRTCRESTR() -> DIS4HZ=(ParValue))
#define biGetRTCRESTR_DIS2HZ() (pst_bitRTCRESTR() -> DIS2HZ)
#define vSetRTCRESTR_DIS2HZ(ParValue)  (pst_bitRTCRESTR() -> DIS2HZ=(ParValue))
#define biGetRTCRESTR_RSTALM() (pst_bitRTCRESTR() -> RSTALM)
#define vSetRTCRESTR_RSTALM(ParValue)  (pst_bitRTCRESTR() -> RSTALM=(ParValue))
#define biGetRTCRESTR_RSTTMR() (pst_bitRTCRESTR() -> RSTTMR)
#define vSetRTCRESTR_RSTTMR(ParValue)  (pst_bitRTCRESTR() -> RSTTMR=(ParValue))
#define biGetRTCRESTR_DIS16HZ() (pst_bitRTCRESTR() -> DIS16HZ)
#define vSetRTCRESTR_DIS16HZ(ParValue)  (pst_bitRTCRESTR() -> DIS16HZ=(ParValue))
#define biGetRTCRESTR_DIS1HZ() (pst_bitRTCRESTR() -> DIS1HZ)
#define vSetRTCRESTR_DIS1HZ(ParValue)  (pst_bitRTCRESTR() -> DIS1HZ=(ParValue))
            
/* byte access */
#define vSetRTCRESTR(ParValue) (*pu8RTCRESTR() = (ParValue))
#define u8GetRTCRESTR() (*pu8RTCRESTR() )
    
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCCALIBCTRL0                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001010                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCCALIBCTRL0_REG__       0xC0001010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint8_t   CAL_INTRVL	:8; 	 /* 0..7  bit(s) R/W */                    
} RTCCALIBCTRL0_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCCALIBCTRL0_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCCALIBCTRL0()     ((volatile RTCCALIBCTRL0_bit_view_st *)\
(RTCCALIBCTRL0_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCCALIBCTRL0()     ((volatile u8RTCCALIBCTRL0_byte_view *)\
(RTCCALIBCTRL0_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCCALIBCTRL0_CAL_INTRVL() (pst_bitRTCCALIBCTRL0() -> CAL_INTRVL)
#define vSetRTCCALIBCTRL0_CAL_INTRVL(ParValue)  (pst_bitRTCCALIBCTRL0() -> CAL_INTRVL=(ParValue))
            
/* byte access */
#define vSetRTCCALIBCTRL0(ParValue) (*pu8RTCCALIBCTRL0() = (ParValue))
#define u8GetRTCCALIBCTRL0() (*pu8RTCCALIBCTRL0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RTCCALIBCTRL1                                
*       SIZE    : 8-bits                        
*       ADDRESS : 0xC0001011                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define RTCCALIBCTRL1_REG__       0xC0001011U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint8_t   CAL_INTRVL	:5; 	 /* 0..4  bit(s) R/W */
  uint8_t   CLK_RTC_SEL	:2; 	 /* 5..6  bit(s) R/W */ 
  uint8_t   CAL_ENB	:1; 	 /* 7..7  bit(s) R/W */                    
} RTCCALIBCTRL1_bit_view_st;
        

/* BYTE View */
typedef uint8_t u8RTCCALIBCTRL1_byte_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitRTCCALIBCTRL1()     ((volatile RTCCALIBCTRL1_bit_view_st *)\
(RTCCALIBCTRL1_REG__ ))
        
/* Pointer to BYTE  */
#define pu8RTCCALIBCTRL1()     ((volatile u8RTCCALIBCTRL1_byte_view *)\
(RTCCALIBCTRL1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetRTCCALIBCTRL1_CAL_INTRVL() (pst_bitRTCCALIBCTRL1() -> CAL_INTRVL)
#define vSetRTCCALIBCTRL1_CAL_INTRVL(ParValue)  (pst_bitRTCCALIBCTRL1() -> CAL_INTRVL=(ParValue))
#define biGetRTCCALIBCTRL1_CLK_RTC_SEL() (pst_bitRTCCALIBCTRL1() -> CLK_RTC_SEL)
#define vSetRTCCALIBCTRL1_CLK_RTC_SEL(ParValue)  (pst_bitRTCCALIBCTRL1() -> CLK_RTC_SEL=(ParValue))
#define biGetRTCCALIBCTRL1_CAL_ENB() (pst_bitRTCCALIBCTRL1() -> CAL_ENB)
#define vSetRTCCALIBCTRL1_CAL_ENB(ParValue)  (pst_bitRTCCALIBCTRL1() -> CAL_ENB=(ParValue))
            
/* byte access */
#define vSetRTCCALIBCTRL1(ParValue) (*pu8RTCCALIBCTRL1() = (ParValue))
#define u8GetRTCCALIBCTRL1() (*pu8RTCCALIBCTRL1() )
            
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

    

#endif /* RTCIO_H */ 
    
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

