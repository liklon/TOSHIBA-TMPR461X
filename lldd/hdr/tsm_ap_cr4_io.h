
/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : TSM_AP_CR4 
/  Date of creation (y-m-d:time): 2012-10-18+02:00  :  10:48:24.307+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.4.7
/  Stylesheet  ver              : $Revision: 1.13 $ 
/  Excel Sheet ver.             : vv0.4
/  Excel Sheet date             : 2012-May-18
/  Excel Sheet author           : SUC
/##########################################################################*/

/****************************************************************************
*   COPYRIGHT 2005       All rights reserved
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
*   VERSION     : $Revision: 1.13 $ 
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/


#ifndef TSM_AP_CR4_IO_H
#define TSM_AP_CR4_IO_H

/* Following include file(s) needed for proper operation: */
#include "captypes.h"                    /* Core specific primitive type definitions */ 

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1862  /* Rule 19.7 [A] : disable function-like macro not allowed */
#endif

#ifdef HW_EMULATION_AP
/* following register on cm3 and cr4 have different address,
 * but for emulation they should be the same to have access to
 * their value on both sides: */
#define Reg_0xC010B000U Reg_0x46000000U
#define Reg_0xC010B004U Reg_0x46000004U
#define Reg_0xC010B008U Reg_0x46000008U

#define Reg_0xC010B0F0U Reg_0x460000F0U
#define Reg_0xC010B0F4U Reg_0x460000F4U
#define Reg_0xC010B0F8U Reg_0x460000F8U
#define Reg_0xC010B0FCU Reg_0x460000FCU

#define Reg_0xC010B100U Reg_0x46000100U

extern uint32_t Reg_0xC010B000U; //=Reg_0x46000000U  , Command
extern uint32_t Reg_0xC010B004U; //=Reg_0x46000004U  , STATUS
extern uint32_t Reg_0xC010B008U; //=Reg_0x46000008U  , ERC_FLAG
extern uint32_t Reg_0xC010B018U; //CR4_RX_FIFO_STATUS
extern uint32_t Reg_0xC010B01CU; //CR4_RX_FIFO_IRQ_CONFIG
extern uint32_t Reg_0xC010B020U; //CR4_TX_FIFO_STATUS
extern uint32_t Reg_0xC010B024U; //CR4_TX_FIFO_IRQ_CONFIG
extern uint32_t Reg_0xC010B0F0U; //=Reg_0x460000F0U  , UID_IN3
extern uint32_t Reg_0xC010B0F4U; //=Reg_0x460000F4U  , UID_IN2
extern uint32_t Reg_0xC010B0F8U; //=Reg_0x460000F8U  , UID_IN1
extern uint32_t Reg_0xC010B0FCU; //=Reg_0x460000FCU  , UID_IN0

extern uint32_t Reg_0xC010B100U[]; //=Reg_0x46000100U , CM3_DP_PARAM 
extern uint32_t Reg_0xC010B180U[]; //RX_FIFO_IN
extern uint32_t Reg_0xC010B1A0U[]; //TX_FIFO_OUT
#endif
/****************************************************************************   
*                                                                               
*       REGISTER: Command                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B000                              
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   SubCom :4;      /* 0..3  bit(s) R/W */
  uint32_t   Com    :20;     /* 4..23  bit(s) R/W */ 
  uint32_t   Ident  :8;      /* 24..31  bit(s) R/W */                    
} Command_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} Command_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} Command_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32Command_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitCommand()     ((volatile Command_bit_view_st *)\
(0xC0002000U ))
#else
#define pst_bitCommand()     ((volatile Command_bit_view_st *)\
(0xC010B000U ))
#endif
#else 
#define pst_bitCommand()     ((volatile Command_bit_view_st *)\
(&Reg_0xC010B000U ))
#endif
        
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8Command()     ((volatile Command_byte_view_st *)\
(0xC0002000U ))
#else
#define pst_u8Command()     ((volatile Command_byte_view_st *)\
(0xC010B000U ))
#endif
#else 
#define pst_u8Command()     ((volatile Command_byte_view_st *)\
(&Reg_0xC010B000U ))
#endif
            
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16Command()     ((volatile Command_halfword_view_st *)\
(0xC0002000U ))
#else    
#define pst_u16Command()     ((volatile Command_halfword_view_st *)\
(0xC010B000U ))
#endif
#else
#define pst_u16Command()     ((volatile Command_halfword_view_st *)\
(&Reg_0xC010B000U ))
#endif
            
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32Command()     ((volatile u32Command_word_view *)\
(0xC0002000U ))
#else    
#define pu32Command()     ((volatile u32Command_word_view *)\
(0xC010B000U ))
#endif
#else 
#define pu32Command()     ((volatile u32Command_word_view *)\
(&Reg_0xC010B000U ))
#endif
             

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCommand_SubCom() (pst_bitCommand() -> SubCom)
#define vSetCommand_SubCom(ParValue)  (pst_bitCommand() -> SubCom=(ParValue))
#define biGetCommand_Com() (pst_bitCommand() -> Com)
#define vSetCommand_Com(ParValue)  (pst_bitCommand() -> Com=(ParValue))
#define biGetCommand_Ident() (pst_bitCommand() -> Ident)
#define vSetCommand_Ident(ParValue)  (pst_bitCommand() -> Ident=(ParValue))
            
/* LL-struct byte access */
#define vSetCommandLL(ParValue) (pst_u8Command() -> u8LL = (ParValue))
#define u8GetCommandLL() (pst_u8Command() -> u8LL)
/* LH-struct byte access */
#define vSetCommandLH(ParValue) (pst_u8Command() -> u8LH = (ParValue))
#define u8GetCommandLH() (pst_u8Command() -> u8LH)
/* HL-struct byte access */
#define vSetCommandHL(ParValue) (pst_u8Command() -> u8HL = (ParValue))
#define u8GetCommandHL() (pst_u8Command() -> u8HL)
/* HH-struct byte access */
#define vSetCommandHH(ParValue) (pst_u8Command() -> u8HH = (ParValue))
#define u8GetCommandHH() (pst_u8Command() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCommandL(ParValue) (pst_u16Command() -> u16L = (ParValue))
#define u16GetCommandL() (pst_u16Command() -> u16L)
#define vSetCommandH(ParValue) (pst_u16Command() -> u16H = (ParValue))
#define u16GetCommandH() (pst_u16Command() -> u16H)
            
/* Word access */
#define vSetCommand(ParValue)  (*pu32Command() = (ParValue))
#define u32GetCommand()  (*pu32Command() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: STATUS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B004                              
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   BUSY   :1;      /* 0..0  bit(s) R */
  uint32_t   SECURE_BOOT    :1;      /* 1..1  bit(s) R */
  uint32_t   BOOT_INIT  :1;      /* 2..2  bit(s) R */
  uint32_t   BOOT_FINISHED  :1;      /* 3..3  bit(s) R */
  uint32_t   BOOT_OK    :1;      /* 4..4  bit(s) R */
  uint32_t   RND_INIT   :1;      /* 5..5  bit(s) R */
  uint32_t   EXT_DEBUGGER   :1;      /* 6..6  bit(s) R */
  uint32_t   INT_DEBUGGER   :1;      /* 7..7  bit(s) R */
  uint32_t   	:16; 	 /* 8..23  bit(s) R */
  uint32_t   FLASH_SIZE0	:1; 	 /* 24..24  bit(s) R */
  uint32_t   FLASH_SIZE1	:1; 	 /* 25..25  bit(s) R */
  uint32_t   	:3; 	 /* 26..28  bit(s) R */
  uint32_t   TSM_ready  :1;      /* 29..29  bit(s) R */
  uint32_t      :1;      /* 30..30  bit(s) R */ 
  uint32_t   SHE    :1;      /* 31..31  bit(s) R */                    
} STATUS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} STATUS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} STATUS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32STATUS_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitSTATUS()     ((volatile STATUS_bit_view_st *)\
(0xC0002004U ))
#else
#define pst_bitSTATUS()     ((volatile STATUS_bit_view_st *)\
(0xC010B004U ))
#endif
#else
#define pst_bitSTATUS()     ((volatile STATUS_bit_view_st *)\
(&Reg_0xC010B004U ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8STATUS()     ((volatile STATUS_byte_view_st *)\
(0xC0002004U ))
#else    
#define pst_u8STATUS()     ((volatile STATUS_byte_view_st *)\
(0xC010B004U ))
#endif
#else 
#define pst_u8STATUS()     ((volatile STATUS_byte_view_st *)\
(&Reg_0xC010B004U ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16STATUS()     ((volatile STATUS_halfword_view_st *)\
(0xC0002004U ))
#else
#define pst_u16STATUS()     ((volatile STATUS_halfword_view_st *)\
(0xC010B004U ))
#endif
#else 
#define pst_u16STATUS()     ((volatile STATUS_halfword_view_st *)\
(&Reg_0xC010B004U ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32STATUS()     ((volatile u32STATUS_word_view *)\
(0xC0002004U ))
#else
#define pu32STATUS()     ((volatile u32STATUS_word_view *)\
(0xC010B004U ))
#endif
#else 
#define pu32STATUS()     ((volatile u32STATUS_word_view *)\
(&Reg_0xC010B004U ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetSTATUS_BUSY() (pst_bitSTATUS() -> BUSY)            
#define biGetSTATUS_SECURE_BOOT() (pst_bitSTATUS() -> SECURE_BOOT)            
#define biGetSTATUS_BOOT_INIT() (pst_bitSTATUS() -> BOOT_INIT)            
#define biGetSTATUS_BOOT_FINISHED() (pst_bitSTATUS() -> BOOT_FINISHED)            
#define biGetSTATUS_BOOT_OK() (pst_bitSTATUS() -> BOOT_OK)            
#define biGetSTATUS_RND_INIT() (pst_bitSTATUS() -> RND_INIT)            
#define biGetSTATUS_EXT_DEBUGGER() (pst_bitSTATUS() -> EXT_DEBUGGER)            
#define biGetSTATUS_INT_DEBUGGER() (pst_bitSTATUS() -> INT_DEBUGGER)
#define biGetSTATUS_FLASH_SIZE0() (pst_bitSTATUS() -> FLASH_SIZE0)            
#define biGetSTATUS_FLASH_SIZE1() (pst_bitSTATUS() -> FLASH_SIZE1)                        
#define biGetSTATUS_TSM_ready() (pst_bitSTATUS() -> TSM_ready)            
#define biGetSTATUS_SHE() (pst_bitSTATUS() -> SHE)
            
/* LL-struct byte access */
#define u8GetSTATUSLL() (pst_u8STATUS() -> u8LL)
/* LH-struct byte access */
#define u8GetSTATUSLH() (pst_u8STATUS() -> u8LH)
/* HL-struct byte access */
#define u8GetSTATUSHL() (pst_u8STATUS() -> u8HL)
/* HH-struct byte access */
#define u8GetSTATUSHH() (pst_u8STATUS() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetSTATUSL() (pst_u16STATUS() -> u16L)
#define u16GetSTATUSH() (pst_u16STATUS() -> u16H)
            
/* Word access */
#define u32GetSTATUS()  (*pu32STATUS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: ERC_FLAG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B008                              
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   ERC_FLAG   :16;     /* 0..15  bit(s) R */
  uint32_t      :14;     /* 16..29  bit(s) R */
  uint32_t   Cancel :1;      /* 30..30  bit(s) R */ 
  uint32_t   Valid  :1;      /* 31..31  bit(s) R */                    
} ERC_FLAG_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} ERC_FLAG_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} ERC_FLAG_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32ERC_FLAG_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitERC_FLAG()     ((volatile ERC_FLAG_bit_view_st *)\
(0xC0002008U ))
#else
#define pst_bitERC_FLAG()     ((volatile ERC_FLAG_bit_view_st *)\
(0xC010B008U ))
#endif
#else 
#define pst_bitERC_FLAG()     ((volatile ERC_FLAG_bit_view_st *)\
(&Reg_0xC010B008U ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8ERC_FLAG()     ((volatile ERC_FLAG_byte_view_st *)\
(0xC0002008U ))
#else    
#define pst_u8ERC_FLAG()     ((volatile ERC_FLAG_byte_view_st *)\
(0xC010B008U ))
#endif
#else 
#define pst_u8ERC_FLAG()     ((volatile ERC_FLAG_byte_view_st *)\
(&Reg_0xC010B008U ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16ERC_FLAG()     ((volatile ERC_FLAG_halfword_view_st *)\
(0xC0002008U ))
#else
#define pst_u16ERC_FLAG()     ((volatile ERC_FLAG_halfword_view_st *)\
(0xC010B008U ))
#endif
#else
#define pst_u16ERC_FLAG()     ((volatile ERC_FLAG_halfword_view_st *)\
(&Reg_0xC010B008U ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32ERC_FLAG()     ((volatile u32ERC_FLAG_word_view *)\
(0xC0002008U ))
#else
#define pu32ERC_FLAG()     ((volatile u32ERC_FLAG_word_view *)\
(0xC010B008U ))
#endif
#else
#define pu32ERC_FLAG()     ((volatile u32ERC_FLAG_word_view *)\
(&Reg_0xC010B008U ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetERC_FLAG_ERC_FLAG() (pst_bitERC_FLAG() -> ERC_FLAG)            
#define biGetERC_FLAG_Cancel() (pst_bitERC_FLAG() -> Cancel)            
#define biGetERC_FLAG_Valid() (pst_bitERC_FLAG() -> Valid)
            
/* LL-struct byte access */
#define u8GetERC_FLAGLL() (pst_u8ERC_FLAG() -> u8LL)
/* LH-struct byte access */
#define u8GetERC_FLAGLH() (pst_u8ERC_FLAG() -> u8LH)
/* HL-struct byte access */
#define u8GetERC_FLAGHL() (pst_u8ERC_FLAG() -> u8HL)
/* HH-struct byte access */
#define u8GetERC_FLAGHH() (pst_u8ERC_FLAG() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetERC_FLAGL() (pst_u16ERC_FLAG() -> u16L)
#define u16GetERC_FLAGH() (pst_u16ERC_FLAG() -> u16H)
            
/* Word access */
#define u32GetERC_FLAG()  (*pu32ERC_FLAG() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CR4_RX_FIFO_STATUS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B018                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CR4_RX_F   :1;      /* 0..0  bit(s) R */
  uint32_t   CR4_RX_4A  :1;      /* 1..1  bit(s) R */
  uint32_t   CR4_RX_16A :1;      /* 2..2  bit(s) R */
  uint32_t   CR4_RX_128A    :1;      /* 3..3  bit(s) R */
  uint32_t   CR4_RX_256A    :1;      /* 4..4  bit(s) R */
  uint32_t   CR4_RX_384A    :1;      /* 5..5  bit(s) R */
  uint32_t   CR4_RX_E   :1;      /* 6..6  bit(s) R */
  uint32_t      :9;      /* 7..15  bit(s) R */ 
  uint32_t   CR4_RX_C   :16;     /* 16..31  bit(s) R */                    
} CR4_RX_FIFO_STATUS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CR4_RX_FIFO_STATUS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CR4_RX_FIFO_STATUS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CR4_RX_FIFO_STATUS_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitCR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_bit_view_st *)\
(0xC0002018U ))
#else
#define pst_bitCR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_bit_view_st *)\
(0xC010B018U ))
#endif
#else
#define pst_bitCR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_bit_view_st *)\
(&Reg_0xC010B018U ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8CR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_byte_view_st *)\
(0xC0002018U ))
#else
#define pst_u8CR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_byte_view_st *)\
(0xC010B018U ))
#endif
#else
#define pst_u8CR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_byte_view_st *)\
(&Reg_0xC010B018U ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16CR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_halfword_view_st *)\
(0xC0002018U ))
#else
#define pst_u16CR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_halfword_view_st *)\
(0xC010B018U ))
#endif
#else 
#define pst_u16CR4_RX_FIFO_STATUS()     ((volatile CR4_RX_FIFO_STATUS_halfword_view_st *)\
(&Reg_0xC010B018U ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32CR4_RX_FIFO_STATUS()     ((volatile u32CR4_RX_FIFO_STATUS_word_view *)\
(0xC0002018U ))
#else
#define pu32CR4_RX_FIFO_STATUS()     ((volatile u32CR4_RX_FIFO_STATUS_word_view *)\
(0xC010B018U ))
#endif
#else 
#define pu32CR4_RX_FIFO_STATUS()     ((volatile u32CR4_RX_FIFO_STATUS_word_view *)\
(&Reg_0xC010B018U ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCR4_RX_FIFO_STATUS_CR4_RX_F() (pst_bitCR4_RX_FIFO_STATUS() -> CR4_RX_F)            
#define biGetCR4_RX_FIFO_STATUS_CR4_RX_4A() (pst_bitCR4_RX_FIFO_STATUS() -> CR4_RX_4A)            
#define biGetCR4_RX_FIFO_STATUS_CR4_RX_16A() (pst_bitCR4_RX_FIFO_STATUS() -> CR4_RX_16A)            
#define biGetCR4_RX_FIFO_STATUS_CR4_RX_128A() (pst_bitCR4_RX_FIFO_STATUS() -> CR4_RX_128A)            
#define biGetCR4_RX_FIFO_STATUS_CR4_RX_256A() (pst_bitCR4_RX_FIFO_STATUS() -> CR4_RX_256A)            
#define biGetCR4_RX_FIFO_STATUS_CR4_RX_384A() (pst_bitCR4_RX_FIFO_STATUS() -> CR4_RX_384A)            
#define biGetCR4_RX_FIFO_STATUS_CR4_RX_E() (pst_bitCR4_RX_FIFO_STATUS() -> CR4_RX_E)            
#define biGetCR4_RX_FIFO_STATUS_CR4_RX_C() (pst_bitCR4_RX_FIFO_STATUS() -> CR4_RX_C)
            
/* LL-struct byte access */
#define u8GetCR4_RX_FIFO_STATUSLL() (pst_u8CR4_RX_FIFO_STATUS() -> u8LL)
/* LH-struct byte access */
#define u8GetCR4_RX_FIFO_STATUSLH() (pst_u8CR4_RX_FIFO_STATUS() -> u8LH)
/* HL-struct byte access */
#define u8GetCR4_RX_FIFO_STATUSHL() (pst_u8CR4_RX_FIFO_STATUS() -> u8HL)
/* HH-struct byte access */
#define u8GetCR4_RX_FIFO_STATUSHH() (pst_u8CR4_RX_FIFO_STATUS() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetCR4_RX_FIFO_STATUSL() (pst_u16CR4_RX_FIFO_STATUS() -> u16L)
#define u16GetCR4_RX_FIFO_STATUSH() (pst_u16CR4_RX_FIFO_STATUS() -> u16H)
            
/* Word access */
#define u32GetCR4_RX_FIFO_STATUS()  (*pu32CR4_RX_FIFO_STATUS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CR4_RX_FIFO_IRQ_CONFIG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B01C                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CR4_RX_F_EN    :1;      /* 0..0  bit(s) R/W */
  uint32_t   CR4_RX_4A_EN   :1;      /* 1..1  bit(s) R/W */
  uint32_t   CR4_RX_16A_EN  :1;      /* 2..2  bit(s) R/W */
  uint32_t   CR4_RX_128A_EN :1;      /* 3..3  bit(s) R/W */
  uint32_t   CR4_RX_256A_EN :1;      /* 4..4  bit(s) R/W */
  uint32_t   CR4_RX_384A_EN :1;      /* 5..5  bit(s) R/W */
  uint32_t   CR4_RX_E_EN    :1;      /* 6..6  bit(s) R/W */
  uint32_t      :17;     /* 7..23  bit(s) R */
  uint32_t   CR4_RX_CLEAR   :1;      /* 24..24  bit(s) R/W */
  uint32_t      :5;      /* 25..29  bit(s) R */
  uint32_t   CR4_RX_D_I :1;      /* 30..30  bit(s) R/W */ 
  uint32_t   CR4_RX_IRQ_EN  :1;      /* 31..31  bit(s) R/W */                    
} CR4_RX_FIFO_IRQ_CONFIG_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CR4_RX_FIFO_IRQ_CONFIG_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CR4_RX_FIFO_IRQ_CONFIG_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CR4_RX_FIFO_IRQ_CONFIG_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitCR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_bit_view_st *)\
(0xC000201CU ))
#else
#define pst_bitCR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_bit_view_st *)\
(0xC010B01CU ))
#endif
#else 
#define pst_bitCR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_bit_view_st *)\
(&Reg_0xC010B01CU ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8CR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_byte_view_st *)\
(0xC000201CU ))
#else
#define pst_u8CR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_byte_view_st *)\
(0xC010B01CU ))
#endif
#else
#define pst_u8CR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_byte_view_st *)\
(&Reg_0xC010B01CU ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16CR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_halfword_view_st *)\
(0xC000201CU ))
#else 
#define pst_u16CR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_halfword_view_st *)\
(0xC010B01CU ))
#endif
#else
#define pst_u16CR4_RX_FIFO_IRQ_CONFIG()     ((volatile CR4_RX_FIFO_IRQ_CONFIG_halfword_view_st *)\
(&Reg_0xC010B01CU ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32CR4_RX_FIFO_IRQ_CONFIG()     ((volatile u32CR4_RX_FIFO_IRQ_CONFIG_word_view *)\
(0xC000201CU ))
#else
#define pu32CR4_RX_FIFO_IRQ_CONFIG()     ((volatile u32CR4_RX_FIFO_IRQ_CONFIG_word_view *)\
(0xC010B01CU ))
#endif
#else 
#define pu32CR4_RX_FIFO_IRQ_CONFIG()     ((volatile u32CR4_RX_FIFO_IRQ_CONFIG_word_view *)\
(&Reg_0xC010B01CU ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_F_EN() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_F_EN)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_F_EN(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_F_EN=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_4A_EN() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_4A_EN)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_4A_EN(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_4A_EN=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_16A_EN() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_16A_EN)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_16A_EN(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_16A_EN=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_128A_EN() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_128A_EN)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_128A_EN(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_128A_EN=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_256A_EN() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_256A_EN)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_256A_EN(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_256A_EN=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_384A_EN() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_384A_EN)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_384A_EN(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_384A_EN=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_E_EN() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_E_EN)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_E_EN(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_E_EN=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_CLEAR() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_CLEAR)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_CLEAR(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_CLEAR=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_D_I() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_D_I)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_D_I(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_D_I=(ParValue))
#define biGetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_IRQ_EN() (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_IRQ_EN)
#define vSetCR4_RX_FIFO_IRQ_CONFIG_CR4_RX_IRQ_EN(ParValue)  (pst_bitCR4_RX_FIFO_IRQ_CONFIG() -> CR4_RX_IRQ_EN=(ParValue))
            
/* LL-struct byte access */
#define vSetCR4_RX_FIFO_IRQ_CONFIGLL(ParValue) (pst_u8CR4_RX_FIFO_IRQ_CONFIG() -> u8LL = (ParValue))
#define u8GetCR4_RX_FIFO_IRQ_CONFIGLL() (pst_u8CR4_RX_FIFO_IRQ_CONFIG() -> u8LL)
/* LH-struct byte access */
#define vSetCR4_RX_FIFO_IRQ_CONFIGLH(ParValue) (pst_u8CR4_RX_FIFO_IRQ_CONFIG() -> u8LH = (ParValue))
#define u8GetCR4_RX_FIFO_IRQ_CONFIGLH() (pst_u8CR4_RX_FIFO_IRQ_CONFIG() -> u8LH)
/* HL-struct byte access */
#define vSetCR4_RX_FIFO_IRQ_CONFIGHL(ParValue) (pst_u8CR4_RX_FIFO_IRQ_CONFIG() -> u8HL = (ParValue))
#define u8GetCR4_RX_FIFO_IRQ_CONFIGHL() (pst_u8CR4_RX_FIFO_IRQ_CONFIG() -> u8HL)
/* HH-struct byte access */
#define vSetCR4_RX_FIFO_IRQ_CONFIGHH(ParValue) (pst_u8CR4_RX_FIFO_IRQ_CONFIG() -> u8HH = (ParValue))
#define u8GetCR4_RX_FIFO_IRQ_CONFIGHH() (pst_u8CR4_RX_FIFO_IRQ_CONFIG() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCR4_RX_FIFO_IRQ_CONFIGL(ParValue) (pst_u16CR4_RX_FIFO_IRQ_CONFIG() -> u16L = (ParValue))
#define u16GetCR4_RX_FIFO_IRQ_CONFIGL() (pst_u16CR4_RX_FIFO_IRQ_CONFIG() -> u16L)
#define vSetCR4_RX_FIFO_IRQ_CONFIGH(ParValue) (pst_u16CR4_RX_FIFO_IRQ_CONFIG() -> u16H = (ParValue))
#define u16GetCR4_RX_FIFO_IRQ_CONFIGH() (pst_u16CR4_RX_FIFO_IRQ_CONFIG() -> u16H)
            
/* Word access */
#define vSetCR4_RX_FIFO_IRQ_CONFIG(ParValue)  (*pu32CR4_RX_FIFO_IRQ_CONFIG() = (ParValue))
#define u32GetCR4_RX_FIFO_IRQ_CONFIG()  (*pu32CR4_RX_FIFO_IRQ_CONFIG() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CR4_TX_FIFO_STATUS                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B020                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CR4_TX_E   :1;      /* 0..0  bit(s) R */
  uint32_t   CR4_TX_4A  :1;      /* 1..1  bit(s) R */
  uint32_t      :1;      /* 2..2  bit(s) R */
  uint32_t   CR4_TX_128A    :1;      /* 3..3  bit(s) R */
  uint32_t   CR4_TX_256A    :1;      /* 4..4  bit(s) R */
  uint32_t      :1;      /* 5..5  bit(s) R */
  uint32_t   CR4_TX_F   :1;      /* 6..6  bit(s) R */
  uint32_t      :9;      /* 7..15  bit(s) R */ 
  uint32_t   CR4_TX_C   :16;     /* 16..31  bit(s) R */                    
} CR4_TX_FIFO_STATUS_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CR4_TX_FIFO_STATUS_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CR4_TX_FIFO_STATUS_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CR4_TX_FIFO_STATUS_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitCR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_bit_view_st *)\
(0xC0002020U ))
#else
#define pst_bitCR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_bit_view_st *)\
(0xC010B020U ))
#endif
#else 
#define pst_bitCR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_bit_view_st *)\
(&Reg_0xC010B020U ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8CR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_byte_view_st *)\
(0xC0002020U ))
#else
#define pst_u8CR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_byte_view_st *)\
(0xC010B020U ))
#endif
#else
#define pst_u8CR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_byte_view_st *)\
(&Reg_0xC010B020U ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16CR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_halfword_view_st *)\
(0xC0002020U ))
#else
#define pst_u16CR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_halfword_view_st *)\
(0xC010B020U ))
#endif
#else 
#define pst_u16CR4_TX_FIFO_STATUS()     ((volatile CR4_TX_FIFO_STATUS_halfword_view_st *)\
(&Reg_0xC010B020U ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32CR4_TX_FIFO_STATUS()     ((volatile u32CR4_TX_FIFO_STATUS_word_view *)\
(0xC0002020U ))
#else
#define pu32CR4_TX_FIFO_STATUS()     ((volatile u32CR4_TX_FIFO_STATUS_word_view *)\
(0xC010B020U ))
#endif
#else 
#define pu32CR4_TX_FIFO_STATUS()     ((volatile u32CR4_TX_FIFO_STATUS_word_view *)\
(&Reg_0xC010B020U ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetCR4_TX_FIFO_STATUS_CR4_TX_E() (pst_bitCR4_TX_FIFO_STATUS() -> CR4_TX_E)            
#define biGetCR4_TX_FIFO_STATUS_CR4_TX_4A() (pst_bitCR4_TX_FIFO_STATUS() -> CR4_TX_4A)            
#define biGetCR4_TX_FIFO_STATUS_CR4_TX_128A() (pst_bitCR4_TX_FIFO_STATUS() -> CR4_TX_128A)            
#define biGetCR4_TX_FIFO_STATUS_CR4_TX_256A() (pst_bitCR4_TX_FIFO_STATUS() -> CR4_TX_256A)            
#define biGetCR4_TX_FIFO_STATUS_CR4_TX_F() (pst_bitCR4_TX_FIFO_STATUS() -> CR4_TX_F)            
#define biGetCR4_TX_FIFO_STATUS_CR4_TX_C() (pst_bitCR4_TX_FIFO_STATUS() -> CR4_TX_C)
            
/* LL-struct byte access */
#define u8GetCR4_TX_FIFO_STATUSLL() (pst_u8CR4_TX_FIFO_STATUS() -> u8LL)
/* LH-struct byte access */
#define u8GetCR4_TX_FIFO_STATUSLH() (pst_u8CR4_TX_FIFO_STATUS() -> u8LH)
/* HL-struct byte access */
#define u8GetCR4_TX_FIFO_STATUSHL() (pst_u8CR4_TX_FIFO_STATUS() -> u8HL)
/* HH-struct byte access */
#define u8GetCR4_TX_FIFO_STATUSHH() (pst_u8CR4_TX_FIFO_STATUS() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetCR4_TX_FIFO_STATUSL() (pst_u16CR4_TX_FIFO_STATUS() -> u16L)
#define u16GetCR4_TX_FIFO_STATUSH() (pst_u16CR4_TX_FIFO_STATUS() -> u16H)
            
/* Word access */
#define u32GetCR4_TX_FIFO_STATUS()  (*pu32CR4_TX_FIFO_STATUS() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CR4_TX_FIFO_IRQ_CONFIG                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B024                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   CR4_TX_E_EN    :1;      /* 0..0  bit(s) R/W */
  uint32_t   CR4_TX_4A_EN   :1;      /* 1..1  bit(s) R/W */
  uint32_t      :1;      /* 2..2  bit(s) R */
  uint32_t   CR4_TX_128A_EN :1;      /* 3..3  bit(s) R/W */
  uint32_t   CR4_TX_256A_EN :1;      /* 4..4  bit(s) R/W */
  uint32_t      :1;      /* 5..5  bit(s) R */
  uint32_t   CR4_TX_F_EN    :1;      /* 6..6  bit(s) R/W */
  uint32_t      :17;     /* 7..23  bit(s) R */
  uint32_t   CR4_TX_CLEAR   :1;      /* 24..24  bit(s) R/W */
  uint32_t      :5;      /* 25..29  bit(s) R */
  uint32_t   CR4_TX_D_I :1;      /* 30..30  bit(s) R/W */ 
  uint32_t   CR4_TX_IRQ_EN  :1;      /* 31..31  bit(s) R/W */                    
} CR4_TX_FIFO_IRQ_CONFIG_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CR4_TX_FIFO_IRQ_CONFIG_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CR4_TX_FIFO_IRQ_CONFIG_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CR4_TX_FIFO_IRQ_CONFIG_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitCR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_bit_view_st *)\
(0xC0002024U ))
#else
#define pst_bitCR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_bit_view_st *)\
(0xC010B024U ))
#endif
#else 
#define pst_bitCR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_bit_view_st *)\
(&Reg_0xC010B024U ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8CR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_byte_view_st *)\
(0xC0002024U ))
#else
#define pst_u8CR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_byte_view_st *)\
(0xC010B024U ))
#endif
#else 
#define pst_u8CR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_byte_view_st *)\
(&Reg_0xC010B024U ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16CR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_halfword_view_st *)\
(0xC0002024U ))
#else
#define pst_u16CR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_halfword_view_st *)\
(0xC010B024U ))
#endif
#else 
#define pst_u16CR4_TX_FIFO_IRQ_CONFIG()     ((volatile CR4_TX_FIFO_IRQ_CONFIG_halfword_view_st *)\
(&Reg_0xC010B024U ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32CR4_TX_FIFO_IRQ_CONFIG()     ((volatile u32CR4_TX_FIFO_IRQ_CONFIG_word_view *)\
(0xC0002024U ))
#else
#define pu32CR4_TX_FIFO_IRQ_CONFIG()     ((volatile u32CR4_TX_FIFO_IRQ_CONFIG_word_view *)\
(0xC010B024U ))
#endif
#else
#define pu32CR4_TX_FIFO_IRQ_CONFIG()     ((volatile u32CR4_TX_FIFO_IRQ_CONFIG_word_view *)\
(&Reg_0xC010B024U ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_E_EN() (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_E_EN)
#define vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_E_EN(ParValue)  (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_E_EN=(ParValue))
#define biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_4A_EN() (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_4A_EN)
#define vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_4A_EN(ParValue)  (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_4A_EN=(ParValue))
#define biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_128A_EN() (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_128A_EN)
#define vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_128A_EN(ParValue)  (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_128A_EN=(ParValue))
#define biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_256A_EN() (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_256A_EN)
#define vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_256A_EN(ParValue)  (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_256A_EN=(ParValue))
#define biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_F_EN() (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_F_EN)
#define vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_F_EN(ParValue)  (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_F_EN=(ParValue))
#define biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_CLEAR() (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_CLEAR)
#define vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_CLEAR(ParValue)  (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_CLEAR=(ParValue))
#define biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_D_I() (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_D_I)
#define vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_D_I(ParValue)  (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_D_I=(ParValue))
#define biGetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_IRQ_EN() (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_IRQ_EN)
#define vSetCR4_TX_FIFO_IRQ_CONFIG_CR4_TX_IRQ_EN(ParValue)  (pst_bitCR4_TX_FIFO_IRQ_CONFIG() -> CR4_TX_IRQ_EN=(ParValue))
            
/* LL-struct byte access */
#define vSetCR4_TX_FIFO_IRQ_CONFIGLL(ParValue) (pst_u8CR4_TX_FIFO_IRQ_CONFIG() -> u8LL = (ParValue))
#define u8GetCR4_TX_FIFO_IRQ_CONFIGLL() (pst_u8CR4_TX_FIFO_IRQ_CONFIG() -> u8LL)
/* LH-struct byte access */
#define vSetCR4_TX_FIFO_IRQ_CONFIGLH(ParValue) (pst_u8CR4_TX_FIFO_IRQ_CONFIG() -> u8LH = (ParValue))
#define u8GetCR4_TX_FIFO_IRQ_CONFIGLH() (pst_u8CR4_TX_FIFO_IRQ_CONFIG() -> u8LH)
/* HL-struct byte access */
#define vSetCR4_TX_FIFO_IRQ_CONFIGHL(ParValue) (pst_u8CR4_TX_FIFO_IRQ_CONFIG() -> u8HL = (ParValue))
#define u8GetCR4_TX_FIFO_IRQ_CONFIGHL() (pst_u8CR4_TX_FIFO_IRQ_CONFIG() -> u8HL)
/* HH-struct byte access */
#define vSetCR4_TX_FIFO_IRQ_CONFIGHH(ParValue) (pst_u8CR4_TX_FIFO_IRQ_CONFIG() -> u8HH = (ParValue))
#define u8GetCR4_TX_FIFO_IRQ_CONFIGHH() (pst_u8CR4_TX_FIFO_IRQ_CONFIG() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCR4_TX_FIFO_IRQ_CONFIGL(ParValue) (pst_u16CR4_TX_FIFO_IRQ_CONFIG() -> u16L = (ParValue))
#define u16GetCR4_TX_FIFO_IRQ_CONFIGL() (pst_u16CR4_TX_FIFO_IRQ_CONFIG() -> u16L)
#define vSetCR4_TX_FIFO_IRQ_CONFIGH(ParValue) (pst_u16CR4_TX_FIFO_IRQ_CONFIG() -> u16H = (ParValue))
#define u16GetCR4_TX_FIFO_IRQ_CONFIGH() (pst_u16CR4_TX_FIFO_IRQ_CONFIG() -> u16H)
            
/* Word access */
#define vSetCR4_TX_FIFO_IRQ_CONFIG(ParValue)  (*pu32CR4_TX_FIFO_IRQ_CONFIG() = (ParValue))
#define u32GetCR4_TX_FIFO_IRQ_CONFIG()  (*pu32CR4_TX_FIFO_IRQ_CONFIG() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: UID_IN3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B0F0                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   UID_IN3    :32;     /* 0..31  bit(s) R */                    
} UID_IN3_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} UID_IN3_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} UID_IN3_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32UID_IN3_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitUID_IN3(ch)     ((volatile UID_IN3_bit_view_st *)\
(0xC00020F0U ))
#else
#define pst_bitUID_IN3()     ((volatile UID_IN3_bit_view_st *)\
(0xC010B0F0U ))
#endif
#else
#define pst_bitUID_IN3()     ((volatile UID_IN3_bit_view_st *)\
(&Reg_0xC010B0F0U ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8UID_IN3(ch)     ((volatile UID_IN3_byte_view_st *)\
(0xC00020F0U ))
#else
#define pst_u8UID_IN3()     ((volatile UID_IN3_byte_view_st *)\
(0xC010B0F0U ))
#endif
#else 
#define pst_u8UID_IN3()     ((volatile UID_IN3_byte_view_st *)\
(&Reg_0xC010B0F0U ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16UID_IN3(ch)     ((volatile UID_IN3_halfword_view_st *)\
(0xC00020F0U ))
#else
#define pst_u16UID_IN3()     ((volatile UID_IN3_halfword_view_st *)\
(0xC010B0F0U ))
#endif
#else 
#define pst_u16UID_IN3()     ((volatile UID_IN3_halfword_view_st *)\
(&Reg_0xC010B0F0U ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32UID_IN3(ch)     ((volatile u32UID_IN3_word_view *)\
(0xC00020F0U ))
#else
#define pu32UID_IN3()     ((volatile u32UID_IN3_word_view *)\
(0xC010B0F0U ))
#endif
#else 
#define pu32UID_IN3()     ((volatile u32UID_IN3_word_view *)\
(&Reg_0xC010B0F0U ))
#endif
             

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetUID_IN3_UID_IN3() (pst_bitUID_IN3() -> UID_IN3)
            
/* LL-struct byte access */
#define u8GetUID_IN3LL() (pst_u8UID_IN3() -> u8LL)
/* LH-struct byte access */
#define u8GetUID_IN3LH() (pst_u8UID_IN3() -> u8LH)
/* HL-struct byte access */
#define u8GetUID_IN3HL() (pst_u8UID_IN3() -> u8HL)
/* HH-struct byte access */
#define u8GetUID_IN3HH() (pst_u8UID_IN3() -> u8HH)
            
            
/* Half-word struct access */ 
#define u16GetUID_IN3L() (pst_u16UID_IN3() -> u16L)
#define u16GetUID_IN3H() (pst_u16UID_IN3() -> u16H)
            
/* Word access */
#define u32GetUID_IN3()  (*pu32UID_IN3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: UID_IN2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B0F4                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   UID_IN2    :32;     /* 0..31  bit(s) R */                    
} UID_IN2_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} UID_IN2_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} UID_IN2_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32UID_IN2_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitUID_IN2(ch)     ((volatile UID_IN2_bit_view_st *)\
(0xC00020F4U ))
#else
#define pst_bitUID_IN2()     ((volatile UID_IN2_bit_view_st *)\
(0xC010B0F4U ))
#endif
#else 
#define pst_bitUID_IN2()     ((volatile UID_IN2_bit_view_st *)\
(&Reg_0xC010B0F4U ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8UID_IN2(ch)     ((volatile UID_IN2_byte_view_st *)\
(0xC00020F4U ))
#else
#define pst_u8UID_IN2()     ((volatile UID_IN2_byte_view_st *)\
(0xC010B0F4U ))
#endif
#else 
#define pst_u8UID_IN2()     ((volatile UID_IN2_byte_view_st *)\
(&Reg_0xC010B0F4U ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16UID_IN2(ch)     ((volatile UID_IN2_halfword_view_st *)\
(0xC00020F4U ))
#else
#define pst_u16UID_IN2()     ((volatile UID_IN2_halfword_view_st *)\
(0xC010B0F4U ))
#endif
#else 
#define pst_u16UID_IN2()     ((volatile UID_IN2_halfword_view_st *)\
(&Reg_0xC010B0F4U ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32UID_IN2(ch)     ((volatile u32UID_IN2_word_view *)\
(0xC00020F4U ))
#else
#define pu32UID_IN2()     ((volatile u32UID_IN2_word_view *)\
(0xC010B0F4U ))
#endif
#else 
#define pu32UID_IN2()     ((volatile u32UID_IN2_word_view *)\
(&Reg_0xC010B0F4U ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetUID_IN2_UID_IN2() (pst_bitUID_IN2() -> UID_IN2)
            
/* LL-struct byte access */
#define vSetUID_IN2LL(ParValue) (pst_u8UID_IN2() -> u8LL = (ParValue))
#define u8GetUID_IN2LL() (pst_u8UID_IN2() -> u8LL)
/* LH-struct byte access */
#define vSetUID_IN2LH(ParValue) (pst_u8UID_IN2() -> u8LH = (ParValue))
#define u8GetUID_IN2LH() (pst_u8UID_IN2() -> u8LH)
/* HL-struct byte access */
#define vSetUID_IN2HL(ParValue) (pst_u8UID_IN2() -> u8HL = (ParValue))
#define u8GetUID_IN2HL() (pst_u8UID_IN2() -> u8HL)
/* HH-struct byte access */
#define vSetUID_IN2HH(ParValue) (pst_u8UID_IN2() -> u8HH = (ParValue))
#define u8GetUID_IN2HH() (pst_u8UID_IN2() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetUID_IN2L(ParValue) (pst_u16UID_IN2() -> u16L = (ParValue))
#define u16GetUID_IN2L() (pst_u16UID_IN2() -> u16L)
#define vSetUID_IN2H(ParValue) (pst_u16UID_IN2() -> u16H = (ParValue))
#define u16GetUID_IN2H() (pst_u16UID_IN2() -> u16H)
            
/* Word access */
#define vSetUID_IN2(ParValue)  (*pu32UID_IN2() = (ParValue))
#define u32GetUID_IN2()  (*pu32UID_IN2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: UID_IN1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B0F8                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   UID_IN1    :32;     /* 0..31  bit(s) R */                    
} UID_IN1_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} UID_IN1_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} UID_IN1_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32UID_IN1_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitUID_IN1()     ((volatile UID_IN1_bit_view_st *)\
(0xC00020F8U ))
#else
#define pst_bitUID_IN1()     ((volatile UID_IN1_bit_view_st *)\
(0xC010B0F8U ))
#endif
#else 
#define pst_bitUID_IN1()     ((volatile UID_IN1_bit_view_st *)\
(&Reg_0xC010B0F8U ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8UID_IN1(ch)     ((volatile UID_IN1_byte_view_st *)\
(0xC00020F8U ))
#else
#define pst_u8UID_IN1()     ((volatile UID_IN1_byte_view_st *)\
(0xC010B0F8U ))
#endif
#else 
#define pst_u8UID_IN1()     ((volatile UID_IN1_byte_view_st *)\
(&Reg_0xC010B0F8U ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16UID_IN1()     ((volatile UID_IN1_halfword_view_st *)\
(0xC00020F8U ))
#else
#define pst_u16UID_IN1()     ((volatile UID_IN1_halfword_view_st *)\
(0xC010B0F8U ))
#endif
#else 
#define pst_u16UID_IN1()     ((volatile UID_IN1_halfword_view_st *)\
(&Reg_0xC010B0F8U ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32UID_IN1()     ((volatile u32UID_IN1_word_view *)\
(0xC00020F8U ))
#else
#define pu32UID_IN1()     ((volatile u32UID_IN1_word_view *)\
(0xC010B0F8U ))
#endif
#else 
#define pu32UID_IN1()     ((volatile u32UID_IN1_word_view *)\
(&Reg_0xC010B0F8U ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetUID_IN1_UID_IN1() (pst_bitUID_IN1() -> UID_IN1)
            
/* LL-struct byte access */
#define vSetUID_IN1LL(ParValue) (pst_u8UID_IN1() -> u8LL = (ParValue))
#define u8GetUID_IN1LL() (pst_u8UID_IN1() -> u8LL)
/* LH-struct byte access */
#define vSetUID_IN1LH(ParValue) (pst_u8UID_IN1() -> u8LH = (ParValue))
#define u8GetUID_IN1LH() (pst_u8UID_IN1() -> u8LH)
/* HL-struct byte access */
#define vSetUID_IN1HL(ParValue) (pst_u8UID_IN1() -> u8HL = (ParValue))
#define u8GetUID_IN1HL() (pst_u8UID_IN1() -> u8HL)
/* HH-struct byte access */
#define vSetUID_IN1HH(ParValue) (pst_u8UID_IN1() -> u8HH = (ParValue))
#define u8GetUID_IN1HH() (pst_u8UID_IN1() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetUID_IN1L(ParValue) (pst_u16UID_IN1() -> u16L = (ParValue))
#define u16GetUID_IN1L() (pst_u16UID_IN1() -> u16L)
#define vSetUID_IN1H(ParValue) (pst_u16UID_IN1() -> u16H = (ParValue))
#define u16GetUID_IN1H() (pst_u16UID_IN1() -> u16H)
            
/* Word access */
#define vSetUID_IN1(ParValue)  (*pu32UID_IN1() = (ParValue))
#define u32GetUID_IN1()  (*pu32UID_IN1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: UID_IN0                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B0FC                             
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t      :8;      /* 0..7  bit(s) R */ 
  uint32_t   UID_IN0    :24;     /* 8..31  bit(s) R */                    
} UID_IN0_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} UID_IN0_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} UID_IN0_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32UID_IN0_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitUID_IN0()     ((volatile UID_IN0_bit_view_st *)\
(0xC00020FCU ))
#else
#define pst_bitUID_IN0()     ((volatile UID_IN0_bit_view_st *)\
(0xC010B0FCU ))
#endif
#else 
#define pst_bitUID_IN0()     ((volatile UID_IN0_bit_view_st *)\
(&Reg_0xC010B0FCU ))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8UID_IN0()     ((volatile UID_IN0_byte_view_st *)\
(0xC00020FCU ))
#else
#define pst_u8UID_IN0()     ((volatile UID_IN0_byte_view_st *)\
(0xC010B0FCU ))
#endif
#else 
#define pst_u8UID_IN0()     ((volatile UID_IN0_byte_view_st *)\
(&Reg_0xC010B0FCU ))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16UID_IN0()     ((volatile UID_IN0_halfword_view_st *)\
(0xC00020FCU ))
#else
#define pst_u16UID_IN0()     ((volatile UID_IN0_halfword_view_st *)\
(0xC010B0FCU ))
#endif
#else 
#define pst_u16UID_IN0()     ((volatile UID_IN0_halfword_view_st *)\
(&Reg_0xC010B0FCU ))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32UID_IN0()     ((volatile u32UID_IN0_word_view *)\
(0xC00020FCU ))
#else
#define pu32UID_IN0()     ((volatile u32UID_IN0_word_view *)\
(0xC010B0FCU ))
#endif
#else
#define pu32UID_IN0()     ((volatile u32UID_IN0_word_view *)\
(&Reg_0xC010B0FCU ))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetUID_IN0_UID_IN0() (pst_bitUID_IN0() -> UID_IN0)
            
/* LL-struct byte access */
#define vSetUID_IN0LL(ParValue) (pst_u8UID_IN0() -> u8LL = (ParValue))
#define u8GetUID_IN0LL() (pst_u8UID_IN0() -> u8LL)
/* LH-struct byte access */
#define vSetUID_IN0LH(ParValue) (pst_u8UID_IN0() -> u8LH = (ParValue))
#define u8GetUID_IN0LH() (pst_u8UID_IN0() -> u8LH)
/* HL-struct byte access */
#define vSetUID_IN0HL(ParValue) (pst_u8UID_IN0() -> u8HL = (ParValue))
#define u8GetUID_IN0HL() (pst_u8UID_IN0() -> u8HL)
/* HH-struct byte access */
#define vSetUID_IN0HH(ParValue) (pst_u8UID_IN0() -> u8HH = (ParValue))
#define u8GetUID_IN0HH() (pst_u8UID_IN0() -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetUID_IN0L(ParValue) (pst_u16UID_IN0() -> u16L = (ParValue))
#define u16GetUID_IN0L() (pst_u16UID_IN0() -> u16L)
#define vSetUID_IN0H(ParValue) (pst_u16UID_IN0() -> u16H = (ParValue))
#define u16GetUID_IN0H() (pst_u16UID_IN0() -> u16H)
            
/* Word access */
#define vSetUID_IN0(ParValue)  (*pu32UID_IN0() = (ParValue))
#define u32GetUID_IN0()  (*pu32UID_IN0() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: CR4_DP_PARAM                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B100                              
*       ACCESS  : 8, 16, 32, BIT-level                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{ 
  uint32_t   PARAM_DATA :32;     /* 0..31  bit(s) R/W */                    
} CR4_DP_PARAM_bit_view_st;
        

/* BYTE View */
typedef struct{      
  uint8_t u8LL;      
  uint8_t u8LH;      
  uint8_t u8HL;      
  uint8_t u8HH;      
} CR4_DP_PARAM_byte_view_st;
            
/* HALFWORD View */
typedef struct{      
  uint16_t u16L;     
  uint16_t u16H;     
} CR4_DP_PARAM_halfword_view_st;
            
/* WORD View */
typedef uint32_t u32CR4_DP_PARAM_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to BIT-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_bitCR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_bit_view_st *)\
(0xC0002100U  + ((uint16_t)(ch) * 0x4U)))
#else
#define pst_bitCR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_bit_view_st *)\
(0xC010B100U  + ((uint16_t)(ch) * 0x4U)))
#endif
#else 
#define pst_bitCR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_bit_view_st *)\
(&Reg_0xC010B100U[ch]))
//(&Reg_0xC010B100U[0]  + ((uint16_t)(ch) * 0x4U)))
#endif
    
/* Pointer to BYTE-struct  */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u8CR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_byte_view_st *)\
(0xC0002100U  + ((uint16_t)(ch) * 0x4U)))
#else
#define pst_u8CR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_byte_view_st *)\
(0xC010B100U  + ((uint16_t)(ch) * 0x4U)))
#endif
#else 
#define pst_u8CR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_byte_view_st *)\
(&Reg_0xC010B100U[ch]))
//(&Reg_0xC010B100U[0]  + ((uint16_t)(ch) * 0x4U)))
#endif
        
/* Pointer to HALFWORD-struct */
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pst_u16CR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_halfword_view_st *)\
(0xC0002100U  + ((uint16_t)(ch) * 0x4U)))
#else
#define pst_u16CR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_halfword_view_st *)\
(0xC010B100U  + ((uint16_t)(ch) * 0x4U)))
#endif
#else
#define pst_u16CR4_DP_PARAM(ch)     ((volatile CR4_DP_PARAM_halfword_view_st *)\
(&Reg_0xC010B100U[ch]))
//(&Reg_0xC010B100U[0]  + ((uint16_t)(ch) * 0x4U)))
#endif
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32CR4_DP_PARAM(ch)     ((volatile u32CR4_DP_PARAM_word_view *)\
(0xC0002100U  + ((uint16_t)(ch) * 0x4U)))
#else
#define pu32CR4_DP_PARAM(ch)     ((volatile u32CR4_DP_PARAM_word_view *)\
(0xC010B100U  + ((uint16_t)(ch) * 0x4U)))
#endif
#else 
#define pu32CR4_DP_PARAM(ch)     ((volatile u32CR4_DP_PARAM_word_view *)\
(&Reg_0xC010B100U[ch]))
//(&Reg_0xC010B100U[0]  + ((uint16_t)(ch) * 0x4U)))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetCR4_DP_PARAM_PARAM_DATA(ch) (pst_bitCR4_DP_PARAM(ch) -> PARAM_DATA)
#define vSetCR4_DP_PARAM_PARAM_DATA(ch,ParValue)  (pst_bitCR4_DP_PARAM(ch) -> PARAM_DATA=(ParValue))
            
/* LL-struct byte access */
#define vSetCR4_DP_PARAMLL(ch,ParValue) (pst_u8CR4_DP_PARAM(ch) -> u8LL = (ParValue))
#define u8GetCR4_DP_PARAMLL(ch) (pst_u8CR4_DP_PARAM(ch) -> u8LL)
/* LH-struct byte access */
#define vSetCR4_DP_PARAMLH(ch,ParValue) (pst_u8CR4_DP_PARAM(ch) -> u8LH = (ParValue))
#define u8GetCR4_DP_PARAMLH(ch) (pst_u8CR4_DP_PARAM(ch) -> u8LH)
/* HL-struct byte access */
#define vSetCR4_DP_PARAMHL(ch,ParValue) (pst_u8CR4_DP_PARAM(ch) -> u8HL = (ParValue))
#define u8GetCR4_DP_PARAMHL(ch) (pst_u8CR4_DP_PARAM(ch) -> u8HL)
/* HH-struct byte access */
#define vSetCR4_DP_PARAMHH(ch,ParValue) (pst_u8CR4_DP_PARAM(ch) -> u8HH = (ParValue))
#define u8GetCR4_DP_PARAMHH(ch) (pst_u8CR4_DP_PARAM(ch) -> u8HH)
            
            
/* Half-word struct access */ 
#define vSetCR4_DP_PARAML(ch,ParValue) (pst_u16CR4_DP_PARAM(ch) -> u16L = (ParValue))
#define u16GetCR4_DP_PARAML(ch) (pst_u16CR4_DP_PARAM(ch) -> u16L)
#define vSetCR4_DP_PARAMH(ch,ParValue) (pst_u16CR4_DP_PARAM(ch) -> u16H = (ParValue))
#define u16GetCR4_DP_PARAMH(ch) (pst_u16CR4_DP_PARAM(ch) -> u16H)
            
/* Word access */
#define vSetCR4_DP_PARAM(ch,ParValue)  (*pu32CR4_DP_PARAM(ch) = (ParValue))
#define u32GetCR4_DP_PARAM(ch)  (*pu32CR4_DP_PARAM(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: RX_FIFO_IN                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B180                             
*       ACCESS  : 32,                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
        
/* WORD View */
typedef uint32_t u32RX_FIFO_IN_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32RX_FIFO_IN(ch)     ((volatile u32RX_FIFO_IN_word_view *)\
(0xC0002180U  + ((uint16_t)(ch) * 0x4U)))
#else
#define pu32RX_FIFO_IN(ch)     ((volatile u32RX_FIFO_IN_word_view *)\
(0xC010B180U  + ((uint16_t)(ch) * 0x4U)))
#endif
#else 
#define pu32RX_FIFO_IN(ch)     ((volatile u32RX_FIFO_IN_word_view *)\
(&Reg_0xC010B180U[ch]))
//(&Reg_0xC010B180U[0]  + ((uint16_t)(ch) * 0x4U)))
#endif
             

/************************ REGISTER ACCESS MACROS ****************************/
            
            
/* Word access */
#define vSetRX_FIFO_IN(ch,ParValue)  (*pu32RX_FIFO_IN(ch) = (ParValue))
#define u32GetRX_FIFO_IN(ch)  (*pu32RX_FIFO_IN(ch) )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: TX_FIFO_OUT                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xC010B1A0                             
*       ACCESS  : 32,                       
*                                                                               
*****************************************************************************/
     
/************************       STRUCTURES        ***************************/
        
/* WORD View */
typedef uint32_t u32TX_FIFO_OUT_word_view;
                 


/************************     ACCESS POINTERS     ****************************/
        
/* Pointer to WORD  */ 
#ifndef HW_EMULATION_AP
#ifdef HW_PLTFRM_FPGA
#define pu32TX_FIFO_OUT(ch)     ((volatile u32TX_FIFO_OUT_word_view *)\
(0xC00021A0U  + ((uint16_t)(ch) * 0x4U)))
#else
#define pu32TX_FIFO_OUT(ch)     ((volatile u32TX_FIFO_OUT_word_view *)\
(0xC010B1A0U  + ((uint16_t)(ch) * 0x4U)))
#endif
#else 
#define pu32TX_FIFO_OUT(ch)     ((volatile u32TX_FIFO_OUT_word_view *)\
(&Reg_0xC010B1A0U[ch]))
//(&Reg_0xC010B1A0U[0]  + ((uint16_t)(ch) * 0x4U)))
#endif
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
            
/* Word access */
#define u32GetTX_FIFO_OUT(ch)  (*pu32TX_FIFO_OUT(ch) )
            
#endif /* _TSM_AP_CR4_IO_H */ 
    
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

