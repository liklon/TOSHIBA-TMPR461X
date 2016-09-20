/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : GPIO low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : GPIO
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.13 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/
#ifndef GPIO_IO_H
#define GPIO_IO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */ 

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_GPIO_IO_H_REVISION     "$Revision: 1.13 $"
#define LLDD_GPIO_IO_H_TAG          "$Name: LLDD_1_6 $"

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers  */
  #pragma ghs nowarning 230   /* Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types */
#endif

/*********************************************/


/****************************************************************************   
*                                                                               
*       REGISTER: GPIOC
*       SIZE    : 16-bits                        
*       ADDRESS : 0xC0302000 onwards
*       ACCESS  : 8, 16, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/

/* BIT View */
typedef struct
{
  uint16_t   GPIOC_SEL   :3;   /*   0..2  bit(s) R/W */
  uint16_t               :5;   /*   3..7  bit(s) R */
  uint16_t   GPIOC_PU	   :1;   /*   8..8  bit(s) R/W */
  uint16_t   GPIOC_PD	   :1;   /*   9..9  bit(s) R/W */
  uint16_t   GPIOC_SMT   :1;   /* 10..10  bit(s) R/W */
  uint16_t   GPIOC_IMP   :2;   /* 11..12  bit(s) R/W */
  uint16_t   GPIOC_LATCH :1;   /* 13..13  bit(s) R/W */
  uint16_t               :2;   /* 14..15  bit(s) R */
} GPIOC_bit_view_st;

/* BYTE View */
typedef struct
{
  uint8_t u8L;      
  uint8_t u8H;      
} GPIOC_byte_view_st;
            
/* HALFWORD View */
typedef struct
{
  uint16_t u16L;     
  uint16_t u16H;     
} GPIOC_halfword_view_st;

/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGPIOC(pin)    ((volatile GPIOC_bit_view_st *)\
(0xC0302000U + ((uint32_t)(pin) * 0x2U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8GPIOC(pin)     ((volatile GPIOC_byte_view_st *)\
(0xC0302000U + ((uint32_t)(pin) * 0x2U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GPIOC(pin)    ((volatile GPIOC_halfword_view_st *)\
(0xC0302000U + ((uint32_t)(pin) * 0x2U)))

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGPIO_GPIOC_SEL(pin)           (pst_bitGPIOC(pin) -> GPIOC_SEL)
#define vSetGPIO_GPIOC_SEL(pin,ParValue)   (pst_bitGPIOC(pin) -> GPIOC_SEL = (ParValue))
#define biGetGPIO_GPIOC_PU(pin)            (pst_bitGPIOC(pin) -> GPIOC_PU)
#define vSetGPIO_GPIOC_PU(pin,ParValue)    (pst_bitGPIOC(pin) -> GPIOC_PU = (ParValue))
#define biGetGPIO_GPIOC_PD(pin)            (pst_bitGPIOC(pin) -> GPIOC_PD)
#define vSetGPIO_GPIOC_PD(pin,ParValue)    (pst_bitGPIOC(pin) -> GPIOC_PD = (ParValue))
#define biGetGPIO_GPIOC_SMT(pin)           (pst_bitGPIOC(pin) -> GPIOC_SMT)
#define vSetGPIO_GPIOC_SMT(pin,ParValue)   (pst_bitGPIOC(pin) -> GPIOC_SMT = (ParValue))
#define biGetGPIO_GPIOC_IMP(pin)           (pst_bitGPIOC(pin) -> GPIOC_IMP)
#define vSetGPIO_GPIOC_IMP(pin,ParValue)   (pst_bitGPIOC(pin) -> GPIOC_IMP = (ParValue))
#define biGetGPIO_GPIOC_LATCH(pin)         (pst_bitGPIOC(pin) -> GPIOC_LATCH)
#define vSetGPIO_GPIOC_LATCH(pin,ParValue) (pst_bitGPIOC(pin) -> GPIOC_LATCH = (ParValue))
            
/* LL-struct byte access */
#define vSetGPIOCLL(pin,ParValue)     (pst_u8GPIOC(pin) -> u8L = (ParValue))
#define u8GetGPIOCLL(pin)             (pst_u8GPIOC(pin) -> u8L)
/* LH-struct byte access */
#define vSetGPIOCLH(pin,ParValue)     (pst_u8GPIOC(pin) -> u8H = (ParValue))
#define u8GetGPIOCLH(pin)             (pst_u8GPIOC(pin) -> u8H)
            
/* Half-word struct access */ 
#define vSetGPIOC(pin,ParValue)       (pst_u16GPIOC(pin) -> u16L = (ParValue))
#define u16GetGPIOC(pin)              (pst_u16GPIOC(pin) -> u16L)

/****************************************************************************   
*                                                                               
*       REGISTER: SC                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302280                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
/* BIT View */
typedef struct{
  uint32_t   SC_C0_LEFT_SEL  :3; 	 /* 0..2  bit(s) R/W */
  uint32_t                   :3; 	 /* 3..5  bit(s) R */
  uint32_t   SC_LATCHN       :1; 	 /* 6..6  bit(s) R/W */
  uint32_t   SC_PWDN         :1; 	 /* 7..7  bit(s) R/W */
  uint32_t   SC_C0_RIGHT_SEL :3; 	 /* 8..10  bit(s) R/W */
  uint32_t                   :5; 	 /* 11..15  bit(s) R */
  uint32_t   SC_C1_LEFT_SEL	 :3; 	 /* 16..18  bit(s) R/W */
  uint32_t                   :5; 	 /* 19..23  bit(s) R */
  uint32_t   SC_C1_RIGHT_SEL :3; 	 /* 24..26  bit(s) R/W */ 
  uint32_t                   :5; 	 /* 27..31  bit(s) R */                    
} SC_bit_view_st;
        
/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} SC_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} SC_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32SC_word_view;

/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSC(pin)     ((volatile SC_bit_view_st *)\
(0xC0302280U + ((uint32_t)(pin) * 0x4U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8SC(pin)     ((volatile SC_byte_view_st *)\
(0xC0302280U + ((uint32_t)(pin) * 0x4U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16SC(pin)     ((volatile SC_halfword_view_st *)\
(0xC0302280U + ((uint32_t)(pin) * 0x4U)))
            
/* Pointer to WORD  */ 
#define pu32SC(pin)     ((volatile u32SC_word_view *)\
(0xC0302280U + ((uint32_t)(pin) * 0x4U)))
                 
/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSC_C0_LEFT_SEL(pin)          (pst_bitSC(pin) -> SC_C0_LEFT_SEL)
#define vSetSC_C0_LEFT_SEL(pin,ParValue)  (pst_bitSC(pin) -> SC_C0_LEFT_SEL=(ParValue))
#define biGetSC_LATCHN(pin)               (pst_bitSC(pin) -> SC_LATCHN)
#define vSetSC_LATCHN(pin,ParValue)       (pst_bitSC(pin) -> SC_LATCHN=(ParValue))
#define biGetSC_PWDN(pin)                 (pst_bitSC(pin) -> SC_PWDN)
#define vSetSC_PWDN(pin,ParValue)         (pst_bitSC(pin) -> SC_PWDN=(ParValue))
#define biGetSC_C0_RIGHT_SEL(pin)         (pst_bitSC(pin) -> SC_C0_RIGHT_SEL)
#define vSetSC_C0_RIGHT_SEL(pin,ParValue) (pst_bitSC(pin) -> SC_C0_RIGHT_SEL=(ParValue))
#define biGetSC_C1_LEFT_SEL(pin)          (pst_bitSC(pin) -> SC_C1_LEFT_SEL)
#define vSetSC_C1_LEFT_SEL(pin,ParValue)  (pst_bitSC(pin) -> SC_C1_LEFT_SEL=(ParValue))
#define biGetSC_C1_RIGHT_SEL(pin)         (pst_bitSC(pin) -> SC_C1_RIGHT_SEL)
#define vSetSC_C1_RIGHT_SEL(pin,ParValue) (pst_bitSC(pin) -> SC_C1_RIGHT_SEL=(ParValue))
            
/* LL-struct byte access */
#define vSetSCLL(pin,ParValue) (pst_u8SC(pin) -> u8LL = (ParValue))
#define u8GetS0LL(pin) (pst_u8SC(pin) -> u8LL)
/* LH-struct byte access */
#define vSetSCLH(pin,ParValue) (pst_u8SC(pin) -> u8LH = (ParValue))
#define u8GetSCLH(pin) (pst_u8SC(pin) -> u8LH)
/* HL-struct byte access */
#define vSetSCHL(pin,ParValue) (pst_u8SC(pin) -> u8HL = (ParValue))
#define u8GetSCHL(pin) (pst_u8SC(pin) -> u8HL)
/* HH-struct byte access */
#define vSetSCHH(pin,ParValue) (pst_u8SC(pin) -> u8HH = (ParValue))
#define u8GetSCHH(pin) (pst_u8SC(pin) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetSCL(pin,ParValue) (pst_u16SC(pin) -> u16L = (ParValue))
#define u16GetSCL(pin) (pst_u16SC(pin) -> u16L)
#define vSetSCH(pin,ParValue) (pst_u16SC(pin) -> u16H = (ParValue))
#define u16GetSCH(pin) (pst_u16SC(pin) -> u16H)
            
/* Word access */
#define vSetSC(pin,ParValue)  (*pu32SC(pin) = (ParValue))
#define u32GetSC(pin)  (*pu32SC(pin) )

/****************************************************************************   
*                                                                               
*       REGISTER: SDRAM_CFG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302294                             
*       ACCESS  : 8, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
        
/* BIT View */
typedef struct
{
  uint8_t   SDRAM_IF_SEL	:2;    /*  0..1  bit(s) R/W */ 
  uint8_t   	            :6;    /* 2..31  bit(s) R */                    
} SDRAM_CFG_bit_view_st;

/* BYTE View */
typedef uint8_t u8SDRAM_CFG_byte_view;

/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitSDRAM_CFG()     ((volatile SDRAM_CFG_bit_view_st *)\
(0xC0302294U ))
        
/* Pointer to BYTE  */
#define pu8SDRAM_CFG()         ((volatile u8SDRAM_CFG_byte_view *)\
(0xC0302294U ))

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetSDRAM_CFG_SDRAM_IF_SEL()         (pst_bitSDRAM_CFG() -> SDRAM_IF_SEL)
#define vSetSDRAM_CFG_SDRAM_IF_SEL(ParValue)  (pst_bitSDRAM_CFG() -> SDRAM_IF_SEL=(ParValue))
            
/* byte access */
#define vSetSDRAM_CFG(ParValue)               (*pu8SDRAM_CFG() = (ParValue))
#define u8GetSDRAM_CFG()                      (*pu8SDRAM_CFG() )


/****************************************************************************   
*                                                                               
*       REGISTER: GPIO                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC0302800                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/

/* BIT View */
typedef struct
{
  uint32_t   GPIO_WDATA	:8; 	 /*   0..7  bit(s) R/W */
  uint32_t   GPIO_RDATA	:8; 	 /*  8..15  bit(s) R */
  uint32_t   GPIO_DIR	  :8; 	 /* 16..23  bit(s) R/W */ 
  uint32_t   	          :8; 	 /* 24..31  bit(s) R */                    
} GPIO_bit_view_st;

/* BYTE View */
typedef struct
{
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} GPIO_byte_view_st;
            
/* HALFWORD View */
typedef struct
{
  uint16_t u16L;     
  uint16_t u16H;     
} GPIO_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32GPIO_word_view;

/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitGPIO(ch)        ((volatile GPIO_bit_view_st *)\
(0xC0302800U  + ((uint32_t)(ch) * 0x004U)))
        
/* Pointer to BYTE-struct  */
#define pst_u8GPIO(ch)         ((volatile GPIO_byte_view_st *)\
(0xC0302800U  + ((uint32_t)(ch) * 0x004U)))
            
/* Pointer to HALFWORD-struct */
#define pst_u16GPIO(ch)        ((volatile GPIO_halfword_view_st *)\
(0xC0302800U  + ((uint32_t)(ch) * 0x004U)))
            
/* Pointer to WORD  */ 
#define pu32GPIO(ch)           ((volatile u32GPIO_word_view *)\
(0xC0302800U  + ((uint32_t)(ch) * 0x004U)))

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetGPIO_GPIO_WDATA(ch)          (pst_bitGPIO(ch) -> GPIO_WDATA)
#define vSetGPIO_GPIO_WDATA(ch,ParValue)  (pst_bitGPIO(ch) -> GPIO_WDATA = (ParValue))            
#define biGetGPIO_GPIO_RDATA(ch)          (pst_bitGPIO(ch) -> GPIO_RDATA)
#define biGetGPIO_GPIO_DIR(ch)            (pst_bitGPIO(ch) -> GPIO_DIR)
#define vSetGPIO_GPIO_DIR(ch,ParValue)    (pst_bitGPIO(ch) -> GPIO_DIR = (ParValue))

/* LL-struct byte access */
#define vSetGPIOLL(ch,ParValue)           (pst_u8GPIO(ch) -> u8LL = (ParValue))
#define u8GetGPIOLL(ch)                   (pst_u8GPIO(ch) -> u8LL)
/* LH-struct byte access */
#define vSetGPIOLH(ch,ParValue)           (pst_u8GPIO(ch) -> u8LH = (ParValue))
#define u8GetGPIOLH(ch)                   (pst_u8GPIO(ch) -> u8LH)
/* HL-struct byte access */
#define vSetGPIOHL(ch,ParValue)           (pst_u8GPIO(ch) -> u8HL = (ParValue))
#define u8GetGPIOHL(ch)                   (pst_u8GPIO(ch) -> u8HL)
/* HH-struct byte access */
#define vSetGPIOHH(ch,ParValue)           (pst_u8GPIO(ch) -> u8HH = (ParValue))
#define u8GetGPIOHH(ch)                   (pst_u8GPIO(ch) -> u8HH)

/* Half-word struct access */ 
#define vSetGPIOL(ch,ParValue)            (pst_u16GPIO(ch) -> u16L = (ParValue))
#define u16GetGPIOL(ch)                   (pst_u16GPIO(ch) -> u16L)
#define vSetGPIOH(ch,ParValue)            (pst_u16GPIO(ch) -> u16H = (ParValue))
#define u16GetGPIOH(ch)                   (pst_u16GPIO(ch) -> u16H)

/* Word access */
#define vSetGPIO(ch,ParValue)             (*pu32GPIO(ch) = (ParValue))
#define u32GetGPIO(ch)                    (*pu32GPIO(ch) )

/******************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */ 
/******************************************************************************/


/****************************************************************************/	
/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :   Deactivated:
** |     Not requested Rules: 
** |         Rule 5.7  [A] : disable No reuse of identifiers
** |
** |     Requested Rules:
** |
** |         Rule 6.4  [R] : Bitfields can only have `unsigned int' or `signed int' types
** |                         Used for bit definitons generated by converter tool
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/
/****************************************************************************/

#endif /* GPIO_IO_H */ 

/****************************************************************************/

    
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

