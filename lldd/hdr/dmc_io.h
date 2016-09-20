/*##########################################################################    
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE 
/  Module                       : pl340_dmc_PL340r4p0_53e 
/  Date of creation (y-m-d:time): 2015-02-10+01:00  :  10:13:21.822+01:00
/  Excel2XML Tool ver.          : 
/  Stylesheet  ver              : $Revision: 1.10 $ 
/  Excel Sheet ver.             : vr4p0_v1.0
/  Excel Sheet date             : 10.01.2015
/  Excel Sheet author           : TEE_SPIRIT_CONVERTER_SCRIPT Ver.:v1.3
/##########################################################################*/

/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Centre (ELDEC)
*****************************************************************************
*   DESCRIPTION : DMC low level driver io-header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : DMC
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.10 $ 
*   DATE        : $Date: 2015/05/27 12:19:07 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/
#ifndef DMC_IO_H
#define DMC_IO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */ 

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_DMC_IO_H_REVISION     "$Revision: 1.10 $"
#define LLDD_DMC_IO_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/
/* disable following Misra errors for io files */
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1772  /* Rule 5.1  [R] : No more than 31 chars to determine an identifier */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1861  /* Rule 20.1 [R] : No definition, redefinition, or undefinition of reserved words and standard library names */
  #pragma ghs nowarning 1862  /* Rule 19.7 [A] : Disable function-like macro not allowed */
#endif     
    
/****************************************************************************   
*                                                                               
*       REGISTER: memc_status                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01000                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define memc_status_REG__       0xc0d01000U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   memc_status	:2; 	 /* 0..1  bit(s) R */
  uint32_t   max_memory_width	:2; 	 /* 2..3  bit(s) R */
  uint32_t   memory_support	:3; 	 /* 4..6  bit(s) R */
  uint32_t   memory_chips	:2; 	 /* 7..8  bit(s) R */
  uint32_t   banks_bit0	:1; 	 /* 9..9  bit(s) R */
  uint32_t   exclusive_monitors	:2; 	 /* 10..11  bit(s) R */
  uint32_t   banks_bit1	:1; 	 /* 12..12  bit(s) R */ 
  uint32_t   Reserved0	:19; 	 /* 13..31  bit(s) R */                    
} memc_status_bit_view_st;
        

/* WORD View */
typedef uint32_t u32memc_status_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitmemc_status()     ((volatile memc_status_bit_view_st *)\
(memc_status_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32memc_status()     ((volatile u32memc_status_word_view *)\
(memc_status_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetmemc_status_memc_status() (pst_bitmemc_status() -> memc_status)            
#define biGetmemc_status_max_memory_width() (pst_bitmemc_status() -> max_memory_width)            
#define biGetmemc_status_memory_support() (pst_bitmemc_status() -> memory_support)            
#define biGetmemc_status_memory_chips() (pst_bitmemc_status() -> memory_chips)            
#define biGetmemc_status_banks_bit0() (pst_bitmemc_status() -> banks_bit0)            
#define biGetmemc_status_exclusive_monitors() (pst_bitmemc_status() -> exclusive_monitors)            
#define biGetmemc_status_banks_bit1() (pst_bitmemc_status() -> banks_bit1)            
            
/* Word access */

#define u32Getmemc_status()  (*pu32memc_status() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: memc_cmd                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01004                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define memc_cmd_REG__       0xc0d01004U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   memc_cmd	:3; 	 /* 0..2  bit(s) W */ 
  uint32_t   Reserved0	:29; 	 /* 3..31  bit(s) W */                    
} memc_cmd_bit_view_st;
        

/* WORD View */
typedef uint32_t u32memc_cmd_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitmemc_cmd()     ((volatile memc_cmd_bit_view_st *)\
(memc_cmd_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32memc_cmd()     ((volatile u32memc_cmd_word_view *)\
(memc_cmd_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetmemc_cmd_memc_cmd(ParValue) (pst_bitmemc_cmd() -> memc_cmd=(ParValue)) 
            
/* Word access */
#define vSetmemc_cmd(ParValue)  (*pu32memc_cmd() = (ParValue))
#define u32Getmemc_cmd()  (*pu32memc_cmd() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: direct_cmd                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01008                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define direct_cmd_REG__       0xc0d01008U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   addr_13_to_0	:14; 	 /* 0..13  bit(s) W */
  uint32_t   Reserved0	:2; 	 /* 14..15  bit(s) W */
  uint32_t   bank_addr	:2; 	 /* 16..17  bit(s) W */
  uint32_t   memory_cmd	:2; 	 /* 18..19  bit(s) W */
  uint32_t   chip_nmbr	:2; 	 /* 20..21  bit(s) W */
  uint32_t   ext_mem_cmd	:1; 	 /* 22..22  bit(s) W */ 
  uint32_t   Reserved1	:9; 	 /* 23..31  bit(s) W */                    
} direct_cmd_bit_view_st;
        

/* WORD View */
typedef uint32_t u32direct_cmd_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitdirect_cmd()     ((volatile direct_cmd_bit_view_st *)\
(direct_cmd_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32direct_cmd()     ((volatile u32direct_cmd_word_view *)\
(direct_cmd_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetdirect_cmd_addr_13_to_0(ParValue) (pst_bitdirect_cmd() -> addr_13_to_0=(ParValue)) 
#define vSetdirect_cmd_bank_addr(ParValue) (pst_bitdirect_cmd() -> bank_addr=(ParValue)) 
#define vSetdirect_cmd_memory_cmd(ParValue) (pst_bitdirect_cmd() -> memory_cmd=(ParValue)) 
#define vSetdirect_cmd_chip_nmbr(ParValue) (pst_bitdirect_cmd() -> chip_nmbr=(ParValue)) 
#define vSetdirect_cmd_ext_mem_cmd(ParValue) (pst_bitdirect_cmd() -> ext_mem_cmd=(ParValue)) 
            
/* Word access */
#define vSetdirect_cmd(ParValue)  (*pu32direct_cmd() = (ParValue))
#define u32Getdirect_cmd()  (*pu32direct_cmd() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: memory_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0100c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define memory_cfg_REG__       0xc0d0100cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   column_bits	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   row_bits	:3; 	 /* 3..5  bit(s) R/W */
  uint32_t   ap_bit	:1; 	 /* 6..6  bit(s) R/W */
  uint32_t   power_dwn_prd	:6; 	 /* 7..12  bit(s) R/W */
  uint32_t   auto_power_down	:1; 	 /* 13..13  bit(s) R/W */
  uint32_t   stop_mem_clock	:1; 	 /* 14..14  bit(s) R/W */
  uint32_t   memory_burst	:3; 	 /* 15..17  bit(s) R/W */
  uint32_t   qos_master_bits	:3; 	 /* 18..20  bit(s) R/W */
  uint32_t   active_chips	:2; 	 /* 21..22  bit(s) R/W */ 
  uint32_t   Reserved0	:9; 	 /* 23..31  bit(s) R/W */                    
} memory_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32memory_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitmemory_cfg()     ((volatile memory_cfg_bit_view_st *)\
(memory_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32memory_cfg()     ((volatile u32memory_cfg_word_view *)\
(memory_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetmemory_cfg_column_bits() (pst_bitmemory_cfg() -> column_bits)
#define vSetmemory_cfg_column_bits(ParValue)  (pst_bitmemory_cfg() -> column_bits=(ParValue))
#define biGetmemory_cfg_row_bits() (pst_bitmemory_cfg() -> row_bits)
#define vSetmemory_cfg_row_bits(ParValue)  (pst_bitmemory_cfg() -> row_bits=(ParValue))
#define biGetmemory_cfg_ap_bit() (pst_bitmemory_cfg() -> ap_bit)
#define vSetmemory_cfg_ap_bit(ParValue)  (pst_bitmemory_cfg() -> ap_bit=(ParValue))
#define biGetmemory_cfg_power_dwn_prd() (pst_bitmemory_cfg() -> power_dwn_prd)
#define vSetmemory_cfg_power_dwn_prd(ParValue)  (pst_bitmemory_cfg() -> power_dwn_prd=(ParValue))
#define biGetmemory_cfg_auto_power_down() (pst_bitmemory_cfg() -> auto_power_down)
#define vSetmemory_cfg_auto_power_down(ParValue)  (pst_bitmemory_cfg() -> auto_power_down=(ParValue))
#define biGetmemory_cfg_stop_mem_clock() (pst_bitmemory_cfg() -> stop_mem_clock)
#define vSetmemory_cfg_stop_mem_clock(ParValue)  (pst_bitmemory_cfg() -> stop_mem_clock=(ParValue))
#define biGetmemory_cfg_memory_burst() (pst_bitmemory_cfg() -> memory_burst)
#define vSetmemory_cfg_memory_burst(ParValue)  (pst_bitmemory_cfg() -> memory_burst=(ParValue))
#define biGetmemory_cfg_qos_master_bits() (pst_bitmemory_cfg() -> qos_master_bits)
#define vSetmemory_cfg_qos_master_bits(ParValue)  (pst_bitmemory_cfg() -> qos_master_bits=(ParValue))
#define biGetmemory_cfg_active_chips() (pst_bitmemory_cfg() -> active_chips)
#define vSetmemory_cfg_active_chips(ParValue)  (pst_bitmemory_cfg() -> active_chips=(ParValue))
            
/* Word access */
#define vSetmemory_cfg(ParValue)  (*pu32memory_cfg() = (ParValue))
#define u32Getmemory_cfg()  (*pu32memory_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: refresh_prd                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01010                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define refresh_prd_REG__       0xc0d01010U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   refresh_prd	:15; 	 /* 0..14  bit(s) R/W */ 
  uint32_t   Reserved0	:17; 	 /* 15..31  bit(s) R/W */                    
} refresh_prd_bit_view_st;
        

/* WORD View */
typedef uint32_t u32refresh_prd_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitrefresh_prd()     ((volatile refresh_prd_bit_view_st *)\
(refresh_prd_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32refresh_prd()     ((volatile u32refresh_prd_word_view *)\
(refresh_prd_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetrefresh_prd_refresh_prd() (pst_bitrefresh_prd() -> refresh_prd)
#define vSetrefresh_prd_refresh_prd(ParValue)  (pst_bitrefresh_prd() -> refresh_prd=(ParValue))
            
/* Word access */
#define vSetrefresh_prd(ParValue)  (*pu32refresh_prd() = (ParValue))
#define u32Getrefresh_prd()  (*pu32refresh_prd() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: cas_latency                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01014                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define cas_latency_REG__       0xc0d01014U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   cas_half_cycle	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   cas_latency	:3; 	 /* 1..3  bit(s) R/W */ 
  uint32_t   Reserved0	:28; 	 /* 4..31  bit(s) R/W */                    
} cas_latency_bit_view_st;
        

/* WORD View */
typedef uint32_t u32cas_latency_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitcas_latency()     ((volatile cas_latency_bit_view_st *)\
(cas_latency_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32cas_latency()     ((volatile u32cas_latency_word_view *)\
(cas_latency_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetcas_latency_cas_half_cycle() (pst_bitcas_latency() -> cas_half_cycle)
#define vSetcas_latency_cas_half_cycle(ParValue)  (pst_bitcas_latency() -> cas_half_cycle=(ParValue))
#define biGetcas_latency_cas_latency() (pst_bitcas_latency() -> cas_latency)
#define vSetcas_latency_cas_latency(ParValue)  (pst_bitcas_latency() -> cas_latency=(ParValue))
            
/* Word access */
#define vSetcas_latency(ParValue)  (*pu32cas_latency() = (ParValue))
#define u32Getcas_latency()  (*pu32cas_latency() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_dqss                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01018                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_dqss_REG__       0xc0d01018U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_dqss	:2; 	 /* 0..1  bit(s) R/W */ 
  uint32_t   Reserved0	:30; 	 /* 2..31  bit(s) R/W */                    
} t_dqss_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_dqss_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_dqss()     ((volatile t_dqss_bit_view_st *)\
(t_dqss_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_dqss()     ((volatile u32t_dqss_word_view *)\
(t_dqss_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_dqss_t_dqss() (pst_bitt_dqss() -> t_dqss)
#define vSett_dqss_t_dqss(ParValue)  (pst_bitt_dqss() -> t_dqss=(ParValue))
            
/* Word access */
#define vSett_dqss(ParValue)  (*pu32t_dqss() = (ParValue))
#define u32Gett_dqss()  (*pu32t_dqss() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_mrd                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0101c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_mrd_REG__       0xc0d0101cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_mrd	:7; 	 /* 0..6  bit(s) R/W */ 
  uint32_t   Reserved0	:25; 	 /* 7..31  bit(s) R/W */                    
} t_mrd_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_mrd_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_mrd()     ((volatile t_mrd_bit_view_st *)\
(t_mrd_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_mrd()     ((volatile u32t_mrd_word_view *)\
(t_mrd_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_mrd_t_mrd() (pst_bitt_mrd() -> t_mrd)
#define vSett_mrd_t_mrd(ParValue)  (pst_bitt_mrd() -> t_mrd=(ParValue))
            
/* Word access */
#define vSett_mrd(ParValue)  (*pu32t_mrd() = (ParValue))
#define u32Gett_mrd()  (*pu32t_mrd() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_ras                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01020                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_ras_REG__       0xc0d01020U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_ras	:4; 	 /* 0..3  bit(s) R/W */ 
  uint32_t   Reserved0	:28; 	 /* 4..31  bit(s) R/W */                    
} t_ras_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_ras_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_ras()     ((volatile t_ras_bit_view_st *)\
(t_ras_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_ras()     ((volatile u32t_ras_word_view *)\
(t_ras_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_ras_t_ras() (pst_bitt_ras() -> t_ras)
#define vSett_ras_t_ras(ParValue)  (pst_bitt_ras() -> t_ras=(ParValue))
            
/* Word access */
#define vSett_ras(ParValue)  (*pu32t_ras() = (ParValue))
#define u32Gett_ras()  (*pu32t_ras() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_rc                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01024                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_rc_REG__       0xc0d01024U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_rc	:4; 	 /* 0..3  bit(s) R/W */ 
  uint32_t   Reserved0	:28; 	 /* 4..31  bit(s) R/W */                    
} t_rc_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_rc_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_rc()     ((volatile t_rc_bit_view_st *)\
(t_rc_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_rc()     ((volatile u32t_rc_word_view *)\
(t_rc_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_rc_t_rc() (pst_bitt_rc() -> t_rc)
#define vSett_rc_t_rc(ParValue)  (pst_bitt_rc() -> t_rc=(ParValue))
            
/* Word access */
#define vSett_rc(ParValue)  (*pu32t_rc() = (ParValue))
#define u32Gett_rc()  (*pu32t_rc() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_rcd                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01028                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_rcd_REG__       0xc0d01028U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_rcd	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   schedule_rcd	:3; 	 /* 3..5  bit(s) R/W */ 
  uint32_t   Reserved0	:26; 	 /* 6..31  bit(s) R/W */                    
} t_rcd_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_rcd_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_rcd()     ((volatile t_rcd_bit_view_st *)\
(t_rcd_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_rcd()     ((volatile u32t_rcd_word_view *)\
(t_rcd_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_rcd_t_rcd() (pst_bitt_rcd() -> t_rcd)
#define vSett_rcd_t_rcd(ParValue)  (pst_bitt_rcd() -> t_rcd=(ParValue))
#define biGett_rcd_schedule_rcd() (pst_bitt_rcd() -> schedule_rcd)
#define vSett_rcd_schedule_rcd(ParValue)  (pst_bitt_rcd() -> schedule_rcd=(ParValue))
            
/* Word access */
#define vSett_rcd(ParValue)  (*pu32t_rcd() = (ParValue))
#define u32Gett_rcd()  (*pu32t_rcd() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_rfc                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0102c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_rfc_REG__       0xc0d0102cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_rfc	:5; 	 /* 0..4  bit(s) R/W */
  uint32_t   schedule_rfc	:5; 	 /* 5..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} t_rfc_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_rfc_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_rfc()     ((volatile t_rfc_bit_view_st *)\
(t_rfc_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_rfc()     ((volatile u32t_rfc_word_view *)\
(t_rfc_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_rfc_t_rfc() (pst_bitt_rfc() -> t_rfc)
#define vSett_rfc_t_rfc(ParValue)  (pst_bitt_rfc() -> t_rfc=(ParValue))
#define biGett_rfc_schedule_rfc() (pst_bitt_rfc() -> schedule_rfc)
#define vSett_rfc_schedule_rfc(ParValue)  (pst_bitt_rfc() -> schedule_rfc=(ParValue))
            
/* Word access */
#define vSett_rfc(ParValue)  (*pu32t_rfc() = (ParValue))
#define u32Gett_rfc()  (*pu32t_rfc() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_rp                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01030                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_rp_REG__       0xc0d01030U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_rp	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   schedule_rp	:3; 	 /* 3..5  bit(s) R/W */ 
  uint32_t   Reserved0	:26; 	 /* 6..31  bit(s) R/W */                    
} t_rp_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_rp_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_rp()     ((volatile t_rp_bit_view_st *)\
(t_rp_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_rp()     ((volatile u32t_rp_word_view *)\
(t_rp_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_rp_t_rp() (pst_bitt_rp() -> t_rp)
#define vSett_rp_t_rp(ParValue)  (pst_bitt_rp() -> t_rp=(ParValue))
#define biGett_rp_schedule_rp() (pst_bitt_rp() -> schedule_rp)
#define vSett_rp_schedule_rp(ParValue)  (pst_bitt_rp() -> schedule_rp=(ParValue))
            
/* Word access */
#define vSett_rp(ParValue)  (*pu32t_rp() = (ParValue))
#define u32Gett_rp()  (*pu32t_rp() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_rrd                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01034                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_rrd_REG__       0xc0d01034U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_rrd	:4; 	 /* 0..3  bit(s) R/W */ 
  uint32_t   Reserved0	:28; 	 /* 4..31  bit(s) R/W */                    
} t_rrd_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_rrd_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_rrd()     ((volatile t_rrd_bit_view_st *)\
(t_rrd_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_rrd()     ((volatile u32t_rrd_word_view *)\
(t_rrd_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_rrd_t_rrd() (pst_bitt_rrd() -> t_rrd)
#define vSett_rrd_t_rrd(ParValue)  (pst_bitt_rrd() -> t_rrd=(ParValue))
            
/* Word access */
#define vSett_rrd(ParValue)  (*pu32t_rrd() = (ParValue))
#define u32Gett_rrd()  (*pu32t_rrd() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_wr                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01038                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_wr_REG__       0xc0d01038U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_wr	:3; 	 /* 0..2  bit(s) R/W */ 
  uint32_t   Reserved0	:29; 	 /* 3..31  bit(s) R/W */                    
} t_wr_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_wr_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_wr()     ((volatile t_wr_bit_view_st *)\
(t_wr_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_wr()     ((volatile u32t_wr_word_view *)\
(t_wr_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_wr_t_wr() (pst_bitt_wr() -> t_wr)
#define vSett_wr_t_wr(ParValue)  (pst_bitt_wr() -> t_wr=(ParValue))
            
/* Word access */
#define vSett_wr(ParValue)  (*pu32t_wr() = (ParValue))
#define u32Gett_wr()  (*pu32t_wr() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_wtr                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0103c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_wtr_REG__       0xc0d0103cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_wtr	:3; 	 /* 0..2  bit(s) R/W */ 
  uint32_t   Reserved0	:29; 	 /* 3..31  bit(s) R/W */                    
} t_wtr_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_wtr_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_wtr()     ((volatile t_wtr_bit_view_st *)\
(t_wtr_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_wtr()     ((volatile u32t_wtr_word_view *)\
(t_wtr_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_wtr_t_wtr() (pst_bitt_wtr() -> t_wtr)
#define vSett_wtr_t_wtr(ParValue)  (pst_bitt_wtr() -> t_wtr=(ParValue))
            
/* Word access */
#define vSett_wtr(ParValue)  (*pu32t_wtr() = (ParValue))
#define u32Gett_wtr()  (*pu32t_wtr() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_xp                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01040                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_xp_REG__       0xc0d01040U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_xp	:8; 	 /* 0..7  bit(s) R/W */ 
  uint32_t   Reserved0	:24; 	 /* 8..31  bit(s) R/W */                    
} t_xp_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_xp_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_xp()     ((volatile t_xp_bit_view_st *)\
(t_xp_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_xp()     ((volatile u32t_xp_word_view *)\
(t_xp_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_xp_t_xp() (pst_bitt_xp() -> t_xp)
#define vSett_xp_t_xp(ParValue)  (pst_bitt_xp() -> t_xp=(ParValue))
            
/* Word access */
#define vSett_xp(ParValue)  (*pu32t_xp() = (ParValue))
#define u32Gett_xp()  (*pu32t_xp() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_xsr                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01044                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_xsr_REG__       0xc0d01044U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_xsr	:8; 	 /* 0..7  bit(s) R/W */ 
  uint32_t   Reserved0	:24; 	 /* 8..31  bit(s) R/W */                    
} t_xsr_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_xsr_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_xsr()     ((volatile t_xsr_bit_view_st *)\
(t_xsr_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_xsr()     ((volatile u32t_xsr_word_view *)\
(t_xsr_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_xsr_t_xsr() (pst_bitt_xsr() -> t_xsr)
#define vSett_xsr_t_xsr(ParValue)  (pst_bitt_xsr() -> t_xsr=(ParValue))
            
/* Word access */
#define vSett_xsr(ParValue)  (*pu32t_xsr() = (ParValue))
#define u32Gett_xsr()  (*pu32t_xsr() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: t_esr                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01048                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define t_esr_REG__       0xc0d01048U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   t_esr	:8; 	 /* 0..7  bit(s) R/W */ 
  uint32_t   Reserved0	:24; 	 /* 8..31  bit(s) R/W */                    
} t_esr_bit_view_st;
        

/* WORD View */
typedef uint32_t u32t_esr_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitt_esr()     ((volatile t_esr_bit_view_st *)\
(t_esr_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32t_esr()     ((volatile u32t_esr_word_view *)\
(t_esr_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGett_esr_t_esr() (pst_bitt_esr() -> t_esr)
#define vSett_esr_t_esr(ParValue)  (pst_bitt_esr() -> t_esr=(ParValue))
            
/* Word access */
#define vSett_esr(ParValue)  (*pu32t_esr() = (ParValue))
#define u32Gett_esr()  (*pu32t_esr() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: memory_cfg2                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0104c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define memory_cfg2_REG__       0xc0d0104cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   clock_cfg	:2; 	 /* 0..1  bit(s) R/W */
  uint32_t   dqm_init	:1; 	 /* 2..2  bit(s) R/W */
  uint32_t   cke_init	:1; 	 /* 3..3  bit(s) R/W */
  uint32_t   memory_width	:2; 	 /* 4..5  bit(s) R/W */
  uint32_t   memory_protocol	:3; 	 /* 6..8  bit(s) R/W */
  uint32_t   read_delay	:2; 	 /* 9..10  bit(s) R/W */ 
  uint32_t   Reserved0	:21; 	 /* 11..31  bit(s) R/W */                    
} memory_cfg2_bit_view_st;
        

/* WORD View */
typedef uint32_t u32memory_cfg2_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitmemory_cfg2()     ((volatile memory_cfg2_bit_view_st *)\
(memory_cfg2_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32memory_cfg2()     ((volatile u32memory_cfg2_word_view *)\
(memory_cfg2_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetmemory_cfg2_clock_cfg() (pst_bitmemory_cfg2() -> clock_cfg)
#define vSetmemory_cfg2_clock_cfg(ParValue)  (pst_bitmemory_cfg2() -> clock_cfg=(ParValue))
#define biGetmemory_cfg2_dqm_init() (pst_bitmemory_cfg2() -> dqm_init)
#define vSetmemory_cfg2_dqm_init(ParValue)  (pst_bitmemory_cfg2() -> dqm_init=(ParValue))
#define biGetmemory_cfg2_cke_init() (pst_bitmemory_cfg2() -> cke_init)
#define vSetmemory_cfg2_cke_init(ParValue)  (pst_bitmemory_cfg2() -> cke_init=(ParValue))
#define biGetmemory_cfg2_memory_width() (pst_bitmemory_cfg2() -> memory_width)
#define vSetmemory_cfg2_memory_width(ParValue)  (pst_bitmemory_cfg2() -> memory_width=(ParValue))
#define biGetmemory_cfg2_memory_protocol() (pst_bitmemory_cfg2() -> memory_protocol)
#define vSetmemory_cfg2_memory_protocol(ParValue)  (pst_bitmemory_cfg2() -> memory_protocol=(ParValue))
#define biGetmemory_cfg2_read_delay() (pst_bitmemory_cfg2() -> read_delay)
#define vSetmemory_cfg2_read_delay(ParValue)  (pst_bitmemory_cfg2() -> read_delay=(ParValue))
            
/* Word access */
#define vSetmemory_cfg2(ParValue)  (*pu32memory_cfg2() = (ParValue))
#define u32Getmemory_cfg2()  (*pu32memory_cfg2() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: memory_cfg3                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01050                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define memory_cfg3_REG__       0xc0d01050U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   max_outs_refs	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   prescale	:10; 	 /* 3..12  bit(s) R/W */ 
  uint32_t   Reserved0	:19; 	 /* 13..31  bit(s) R/W */                    
} memory_cfg3_bit_view_st;
        

/* WORD View */
typedef uint32_t u32memory_cfg3_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitmemory_cfg3()     ((volatile memory_cfg3_bit_view_st *)\
(memory_cfg3_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32memory_cfg3()     ((volatile u32memory_cfg3_word_view *)\
(memory_cfg3_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetmemory_cfg3_max_outs_refs() (pst_bitmemory_cfg3() -> max_outs_refs)
#define vSetmemory_cfg3_max_outs_refs(ParValue)  (pst_bitmemory_cfg3() -> max_outs_refs=(ParValue))
#define biGetmemory_cfg3_prescale() (pst_bitmemory_cfg3() -> prescale)
#define vSetmemory_cfg3_prescale(ParValue)  (pst_bitmemory_cfg3() -> prescale=(ParValue))
            
/* Word access */
#define vSetmemory_cfg3(ParValue)  (*pu32memory_cfg3() = (ParValue))
#define u32Getmemory_cfg3()  (*pu32memory_cfg3() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: read_transfer_delay                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0107c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define read_transfer_delay_REG__       0xc0d0107cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   read_transfer_delay	:2; 	 /* 0..1  bit(s) R/W */ 
  uint32_t   Reserved0	:30; 	 /* 2..31  bit(s) R/W */                    
} read_transfer_delay_bit_view_st;
        

/* WORD View */
typedef uint32_t u32read_transfer_delay_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitread_transfer_delay()     ((volatile read_transfer_delay_bit_view_st *)\
(read_transfer_delay_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32read_transfer_delay()     ((volatile u32read_transfer_delay_word_view *)\
(read_transfer_delay_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetread_transfer_delay_read_transfer_delay() (pst_bitread_transfer_delay() -> read_transfer_delay)
#define vSetread_transfer_delay_read_transfer_delay(ParValue)  (pst_bitread_transfer_delay() -> read_transfer_delay=(ParValue))
            
/* Word access */
#define vSetread_transfer_delay(ParValue)  (*pu32read_transfer_delay() = (ParValue))
#define u32Getread_transfer_delay()  (*pu32read_transfer_delay() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_0_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01100                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_0_cfg_REG__       0xc0d01100U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable0	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min0	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max0	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_0_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_0_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_0_cfg()     ((volatile id_0_cfg_bit_view_st *)\
(id_0_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_0_cfg()     ((volatile u32id_0_cfg_word_view *)\
(id_0_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_0_cfg_qos_enable0() (pst_bitid_0_cfg() -> qos_enable0)
#define vSetid_0_cfg_qos_enable0(ParValue)  (pst_bitid_0_cfg() -> qos_enable0=(ParValue))
#define biGetid_0_cfg_qos_min0() (pst_bitid_0_cfg() -> qos_min0)
#define vSetid_0_cfg_qos_min0(ParValue)  (pst_bitid_0_cfg() -> qos_min0=(ParValue))
#define biGetid_0_cfg_qos_max0() (pst_bitid_0_cfg() -> qos_max0)
#define vSetid_0_cfg_qos_max0(ParValue)  (pst_bitid_0_cfg() -> qos_max0=(ParValue))
            
/* Word access */
#define vSetid_0_cfg(ParValue)  (*pu32id_0_cfg() = (ParValue))
#define u32Getid_0_cfg()  (*pu32id_0_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_1_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01104                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_1_cfg_REG__       0xc0d01104U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable1	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min1	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max1	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_1_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_1_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_1_cfg()     ((volatile id_1_cfg_bit_view_st *)\
(id_1_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_1_cfg()     ((volatile u32id_1_cfg_word_view *)\
(id_1_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_1_cfg_qos_enable1() (pst_bitid_1_cfg() -> qos_enable1)
#define vSetid_1_cfg_qos_enable1(ParValue)  (pst_bitid_1_cfg() -> qos_enable1=(ParValue))
#define biGetid_1_cfg_qos_min1() (pst_bitid_1_cfg() -> qos_min1)
#define vSetid_1_cfg_qos_min1(ParValue)  (pst_bitid_1_cfg() -> qos_min1=(ParValue))
#define biGetid_1_cfg_qos_max1() (pst_bitid_1_cfg() -> qos_max1)
#define vSetid_1_cfg_qos_max1(ParValue)  (pst_bitid_1_cfg() -> qos_max1=(ParValue))
            
/* Word access */
#define vSetid_1_cfg(ParValue)  (*pu32id_1_cfg() = (ParValue))
#define u32Getid_1_cfg()  (*pu32id_1_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_2_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01108                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_2_cfg_REG__       0xc0d01108U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable2	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min2	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max2	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_2_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_2_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_2_cfg()     ((volatile id_2_cfg_bit_view_st *)\
(id_2_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_2_cfg()     ((volatile u32id_2_cfg_word_view *)\
(id_2_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_2_cfg_qos_enable2() (pst_bitid_2_cfg() -> qos_enable2)
#define vSetid_2_cfg_qos_enable2(ParValue)  (pst_bitid_2_cfg() -> qos_enable2=(ParValue))
#define biGetid_2_cfg_qos_min2() (pst_bitid_2_cfg() -> qos_min2)
#define vSetid_2_cfg_qos_min2(ParValue)  (pst_bitid_2_cfg() -> qos_min2=(ParValue))
#define biGetid_2_cfg_qos_max2() (pst_bitid_2_cfg() -> qos_max2)
#define vSetid_2_cfg_qos_max2(ParValue)  (pst_bitid_2_cfg() -> qos_max2=(ParValue))
            
/* Word access */
#define vSetid_2_cfg(ParValue)  (*pu32id_2_cfg() = (ParValue))
#define u32Getid_2_cfg()  (*pu32id_2_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_3_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0110c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_3_cfg_REG__       0xc0d0110cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable3	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min3	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max3	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_3_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_3_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_3_cfg()     ((volatile id_3_cfg_bit_view_st *)\
(id_3_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_3_cfg()     ((volatile u32id_3_cfg_word_view *)\
(id_3_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_3_cfg_qos_enable3() (pst_bitid_3_cfg() -> qos_enable3)
#define vSetid_3_cfg_qos_enable3(ParValue)  (pst_bitid_3_cfg() -> qos_enable3=(ParValue))
#define biGetid_3_cfg_qos_min3() (pst_bitid_3_cfg() -> qos_min3)
#define vSetid_3_cfg_qos_min3(ParValue)  (pst_bitid_3_cfg() -> qos_min3=(ParValue))
#define biGetid_3_cfg_qos_max3() (pst_bitid_3_cfg() -> qos_max3)
#define vSetid_3_cfg_qos_max3(ParValue)  (pst_bitid_3_cfg() -> qos_max3=(ParValue))
            
/* Word access */
#define vSetid_3_cfg(ParValue)  (*pu32id_3_cfg() = (ParValue))
#define u32Getid_3_cfg()  (*pu32id_3_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_4_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01110                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_4_cfg_REG__       0xc0d01110U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable4	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min4	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max4	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_4_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_4_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_4_cfg()     ((volatile id_4_cfg_bit_view_st *)\
(id_4_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_4_cfg()     ((volatile u32id_4_cfg_word_view *)\
(id_4_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_4_cfg_qos_enable4() (pst_bitid_4_cfg() -> qos_enable4)
#define vSetid_4_cfg_qos_enable4(ParValue)  (pst_bitid_4_cfg() -> qos_enable4=(ParValue))
#define biGetid_4_cfg_qos_min4() (pst_bitid_4_cfg() -> qos_min4)
#define vSetid_4_cfg_qos_min4(ParValue)  (pst_bitid_4_cfg() -> qos_min4=(ParValue))
#define biGetid_4_cfg_qos_max4() (pst_bitid_4_cfg() -> qos_max4)
#define vSetid_4_cfg_qos_max4(ParValue)  (pst_bitid_4_cfg() -> qos_max4=(ParValue))
            
/* Word access */
#define vSetid_4_cfg(ParValue)  (*pu32id_4_cfg() = (ParValue))
#define u32Getid_4_cfg()  (*pu32id_4_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_5_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01114                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_5_cfg_REG__       0xc0d01114U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable5	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min5	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max5	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_5_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_5_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_5_cfg()     ((volatile id_5_cfg_bit_view_st *)\
(id_5_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_5_cfg()     ((volatile u32id_5_cfg_word_view *)\
(id_5_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_5_cfg_qos_enable5() (pst_bitid_5_cfg() -> qos_enable5)
#define vSetid_5_cfg_qos_enable5(ParValue)  (pst_bitid_5_cfg() -> qos_enable5=(ParValue))
#define biGetid_5_cfg_qos_min5() (pst_bitid_5_cfg() -> qos_min5)
#define vSetid_5_cfg_qos_min5(ParValue)  (pst_bitid_5_cfg() -> qos_min5=(ParValue))
#define biGetid_5_cfg_qos_max5() (pst_bitid_5_cfg() -> qos_max5)
#define vSetid_5_cfg_qos_max5(ParValue)  (pst_bitid_5_cfg() -> qos_max5=(ParValue))
            
/* Word access */
#define vSetid_5_cfg(ParValue)  (*pu32id_5_cfg() = (ParValue))
#define u32Getid_5_cfg()  (*pu32id_5_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_6_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01118                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_6_cfg_REG__       0xc0d01118U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable6	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min6	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max6	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_6_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_6_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_6_cfg()     ((volatile id_6_cfg_bit_view_st *)\
(id_6_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_6_cfg()     ((volatile u32id_6_cfg_word_view *)\
(id_6_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_6_cfg_qos_enable6() (pst_bitid_6_cfg() -> qos_enable6)
#define vSetid_6_cfg_qos_enable6(ParValue)  (pst_bitid_6_cfg() -> qos_enable6=(ParValue))
#define biGetid_6_cfg_qos_min6() (pst_bitid_6_cfg() -> qos_min6)
#define vSetid_6_cfg_qos_min6(ParValue)  (pst_bitid_6_cfg() -> qos_min6=(ParValue))
#define biGetid_6_cfg_qos_max6() (pst_bitid_6_cfg() -> qos_max6)
#define vSetid_6_cfg_qos_max6(ParValue)  (pst_bitid_6_cfg() -> qos_max6=(ParValue))
            
/* Word access */
#define vSetid_6_cfg(ParValue)  (*pu32id_6_cfg() = (ParValue))
#define u32Getid_6_cfg()  (*pu32id_6_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_7_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0111c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_7_cfg_REG__       0xc0d0111cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable7	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min7	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max7	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_7_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_7_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_7_cfg()     ((volatile id_7_cfg_bit_view_st *)\
(id_7_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_7_cfg()     ((volatile u32id_7_cfg_word_view *)\
(id_7_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_7_cfg_qos_enable7() (pst_bitid_7_cfg() -> qos_enable7)
#define vSetid_7_cfg_qos_enable7(ParValue)  (pst_bitid_7_cfg() -> qos_enable7=(ParValue))
#define biGetid_7_cfg_qos_min7() (pst_bitid_7_cfg() -> qos_min7)
#define vSetid_7_cfg_qos_min7(ParValue)  (pst_bitid_7_cfg() -> qos_min7=(ParValue))
#define biGetid_7_cfg_qos_max7() (pst_bitid_7_cfg() -> qos_max7)
#define vSetid_7_cfg_qos_max7(ParValue)  (pst_bitid_7_cfg() -> qos_max7=(ParValue))
            
/* Word access */
#define vSetid_7_cfg(ParValue)  (*pu32id_7_cfg() = (ParValue))
#define u32Getid_7_cfg()  (*pu32id_7_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_8_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01120                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_8_cfg_REG__       0xc0d01120U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable8	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min8	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max8	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_8_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_8_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_8_cfg()     ((volatile id_8_cfg_bit_view_st *)\
(id_8_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_8_cfg()     ((volatile u32id_8_cfg_word_view *)\
(id_8_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_8_cfg_qos_enable8() (pst_bitid_8_cfg() -> qos_enable8)
#define vSetid_8_cfg_qos_enable8(ParValue)  (pst_bitid_8_cfg() -> qos_enable8=(ParValue))
#define biGetid_8_cfg_qos_min8() (pst_bitid_8_cfg() -> qos_min8)
#define vSetid_8_cfg_qos_min8(ParValue)  (pst_bitid_8_cfg() -> qos_min8=(ParValue))
#define biGetid_8_cfg_qos_max8() (pst_bitid_8_cfg() -> qos_max8)
#define vSetid_8_cfg_qos_max8(ParValue)  (pst_bitid_8_cfg() -> qos_max8=(ParValue))
            
/* Word access */
#define vSetid_8_cfg(ParValue)  (*pu32id_8_cfg() = (ParValue))
#define u32Getid_8_cfg()  (*pu32id_8_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_9_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01124                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_9_cfg_REG__       0xc0d01124U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable9	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min9	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max9	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_9_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_9_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_9_cfg()     ((volatile id_9_cfg_bit_view_st *)\
(id_9_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_9_cfg()     ((volatile u32id_9_cfg_word_view *)\
(id_9_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_9_cfg_qos_enable9() (pst_bitid_9_cfg() -> qos_enable9)
#define vSetid_9_cfg_qos_enable9(ParValue)  (pst_bitid_9_cfg() -> qos_enable9=(ParValue))
#define biGetid_9_cfg_qos_min9() (pst_bitid_9_cfg() -> qos_min9)
#define vSetid_9_cfg_qos_min9(ParValue)  (pst_bitid_9_cfg() -> qos_min9=(ParValue))
#define biGetid_9_cfg_qos_max9() (pst_bitid_9_cfg() -> qos_max9)
#define vSetid_9_cfg_qos_max9(ParValue)  (pst_bitid_9_cfg() -> qos_max9=(ParValue))
            
/* Word access */
#define vSetid_9_cfg(ParValue)  (*pu32id_9_cfg() = (ParValue))
#define u32Getid_9_cfg()  (*pu32id_9_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_10_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01128                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_10_cfg_REG__       0xc0d01128U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable10	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min10	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max10	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_10_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_10_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_10_cfg()     ((volatile id_10_cfg_bit_view_st *)\
(id_10_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_10_cfg()     ((volatile u32id_10_cfg_word_view *)\
(id_10_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_10_cfg_qos_enable10() (pst_bitid_10_cfg() -> qos_enable10)
#define vSetid_10_cfg_qos_enable10(ParValue)  (pst_bitid_10_cfg() -> qos_enable10=(ParValue))
#define biGetid_10_cfg_qos_min10() (pst_bitid_10_cfg() -> qos_min10)
#define vSetid_10_cfg_qos_min10(ParValue)  (pst_bitid_10_cfg() -> qos_min10=(ParValue))
#define biGetid_10_cfg_qos_max10() (pst_bitid_10_cfg() -> qos_max10)
#define vSetid_10_cfg_qos_max10(ParValue)  (pst_bitid_10_cfg() -> qos_max10=(ParValue))
            
/* Word access */
#define vSetid_10_cfg(ParValue)  (*pu32id_10_cfg() = (ParValue))
#define u32Getid_10_cfg()  (*pu32id_10_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_11_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0112c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_11_cfg_REG__       0xc0d0112cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable11	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min11	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max11	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_11_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_11_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_11_cfg()     ((volatile id_11_cfg_bit_view_st *)\
(id_11_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_11_cfg()     ((volatile u32id_11_cfg_word_view *)\
(id_11_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_11_cfg_qos_enable11() (pst_bitid_11_cfg() -> qos_enable11)
#define vSetid_11_cfg_qos_enable11(ParValue)  (pst_bitid_11_cfg() -> qos_enable11=(ParValue))
#define biGetid_11_cfg_qos_min11() (pst_bitid_11_cfg() -> qos_min11)
#define vSetid_11_cfg_qos_min11(ParValue)  (pst_bitid_11_cfg() -> qos_min11=(ParValue))
#define biGetid_11_cfg_qos_max11() (pst_bitid_11_cfg() -> qos_max11)
#define vSetid_11_cfg_qos_max11(ParValue)  (pst_bitid_11_cfg() -> qos_max11=(ParValue))
            
/* Word access */
#define vSetid_11_cfg(ParValue)  (*pu32id_11_cfg() = (ParValue))
#define u32Getid_11_cfg()  (*pu32id_11_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_12_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01130                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_12_cfg_REG__       0xc0d01130U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable12	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min12	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max12	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_12_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_12_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_12_cfg()     ((volatile id_12_cfg_bit_view_st *)\
(id_12_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_12_cfg()     ((volatile u32id_12_cfg_word_view *)\
(id_12_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_12_cfg_qos_enable12() (pst_bitid_12_cfg() -> qos_enable12)
#define vSetid_12_cfg_qos_enable12(ParValue)  (pst_bitid_12_cfg() -> qos_enable12=(ParValue))
#define biGetid_12_cfg_qos_min12() (pst_bitid_12_cfg() -> qos_min12)
#define vSetid_12_cfg_qos_min12(ParValue)  (pst_bitid_12_cfg() -> qos_min12=(ParValue))
#define biGetid_12_cfg_qos_max12() (pst_bitid_12_cfg() -> qos_max12)
#define vSetid_12_cfg_qos_max12(ParValue)  (pst_bitid_12_cfg() -> qos_max12=(ParValue))
            
/* Word access */
#define vSetid_12_cfg(ParValue)  (*pu32id_12_cfg() = (ParValue))
#define u32Getid_12_cfg()  (*pu32id_12_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_13_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01134                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_13_cfg_REG__       0xc0d01134U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable13	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min13	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max13	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_13_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_13_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_13_cfg()     ((volatile id_13_cfg_bit_view_st *)\
(id_13_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_13_cfg()     ((volatile u32id_13_cfg_word_view *)\
(id_13_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_13_cfg_qos_enable13() (pst_bitid_13_cfg() -> qos_enable13)
#define vSetid_13_cfg_qos_enable13(ParValue)  (pst_bitid_13_cfg() -> qos_enable13=(ParValue))
#define biGetid_13_cfg_qos_min13() (pst_bitid_13_cfg() -> qos_min13)
#define vSetid_13_cfg_qos_min13(ParValue)  (pst_bitid_13_cfg() -> qos_min13=(ParValue))
#define biGetid_13_cfg_qos_max13() (pst_bitid_13_cfg() -> qos_max13)
#define vSetid_13_cfg_qos_max13(ParValue)  (pst_bitid_13_cfg() -> qos_max13=(ParValue))
            
/* Word access */
#define vSetid_13_cfg(ParValue)  (*pu32id_13_cfg() = (ParValue))
#define u32Getid_13_cfg()  (*pu32id_13_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_14_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01138                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_14_cfg_REG__       0xc0d01138U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable14	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min14	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max14	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_14_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_14_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_14_cfg()     ((volatile id_14_cfg_bit_view_st *)\
(id_14_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_14_cfg()     ((volatile u32id_14_cfg_word_view *)\
(id_14_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_14_cfg_qos_enable14() (pst_bitid_14_cfg() -> qos_enable14)
#define vSetid_14_cfg_qos_enable14(ParValue)  (pst_bitid_14_cfg() -> qos_enable14=(ParValue))
#define biGetid_14_cfg_qos_min14() (pst_bitid_14_cfg() -> qos_min14)
#define vSetid_14_cfg_qos_min14(ParValue)  (pst_bitid_14_cfg() -> qos_min14=(ParValue))
#define biGetid_14_cfg_qos_max14() (pst_bitid_14_cfg() -> qos_max14)
#define vSetid_14_cfg_qos_max14(ParValue)  (pst_bitid_14_cfg() -> qos_max14=(ParValue))
            
/* Word access */
#define vSetid_14_cfg(ParValue)  (*pu32id_14_cfg() = (ParValue))
#define u32Getid_14_cfg()  (*pu32id_14_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: id_15_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0113c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define id_15_cfg_REG__       0xc0d0113cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   qos_enable15	:1; 	 /* 0..0  bit(s) R/W */
  uint32_t   qos_min15	:1; 	 /* 1..1  bit(s) R/W */
  uint32_t   qos_max15	:8; 	 /* 2..9  bit(s) R/W */ 
  uint32_t   Reserved0	:22; 	 /* 10..31  bit(s) R/W */                    
} id_15_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32id_15_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitid_15_cfg()     ((volatile id_15_cfg_bit_view_st *)\
(id_15_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32id_15_cfg()     ((volatile u32id_15_cfg_word_view *)\
(id_15_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetid_15_cfg_qos_enable15() (pst_bitid_15_cfg() -> qos_enable15)
#define vSetid_15_cfg_qos_enable15(ParValue)  (pst_bitid_15_cfg() -> qos_enable15=(ParValue))
#define biGetid_15_cfg_qos_min15() (pst_bitid_15_cfg() -> qos_min15)
#define vSetid_15_cfg_qos_min15(ParValue)  (pst_bitid_15_cfg() -> qos_min15=(ParValue))
#define biGetid_15_cfg_qos_max15() (pst_bitid_15_cfg() -> qos_max15)
#define vSetid_15_cfg_qos_max15(ParValue)  (pst_bitid_15_cfg() -> qos_max15=(ParValue))
            
/* Word access */
#define vSetid_15_cfg(ParValue)  (*pu32id_15_cfg() = (ParValue))
#define u32Getid_15_cfg()  (*pu32id_15_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: chip_cfg                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01200                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define chip_cfg_REG__       0xc0d01200U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   address_mask	:8; 	 /* 0..7  bit(s) R/W */
  uint32_t   address_match	:8; 	 /* 8..15  bit(s) R/W */
  uint32_t   address_fmt	:1; 	 /* 16..16  bit(s) R/W */ 
  uint32_t   Reserved0	:15; 	 /* 17..31  bit(s) R/W */                    
} chip_cfg_bit_view_st;
        

/* WORD View */
typedef uint32_t u32chip_cfg_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitchip_cfg()     ((volatile chip_cfg_bit_view_st *)\
(chip_cfg_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32chip_cfg()     ((volatile u32chip_cfg_word_view *)\
(chip_cfg_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetchip_cfg_address_mask() (pst_bitchip_cfg() -> address_mask)
#define vSetchip_cfg_address_mask(ParValue)  (pst_bitchip_cfg() -> address_mask=(ParValue))
#define biGetchip_cfg_address_match() (pst_bitchip_cfg() -> address_match)
#define vSetchip_cfg_address_match(ParValue)  (pst_bitchip_cfg() -> address_match=(ParValue))
#define biGetchip_cfg_address_fmt() (pst_bitchip_cfg() -> address_fmt)
#define vSetchip_cfg_address_fmt(ParValue)  (pst_bitchip_cfg() -> address_fmt=(ParValue))
            
/* Word access */
#define vSetchip_cfg(ParValue)  (*pu32chip_cfg() = (ParValue))
#define u32Getchip_cfg()  (*pu32chip_cfg() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: user_status                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01300                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define user_status_REG__       0xc0d01300U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   Lock	:1; 	 /* 0..0  bit(s) R */ 
  uint32_t   Reserved0	:31; 	 /* 1..31  bit(s) R */                    
} user_status_bit_view_st;
        

/* WORD View */
typedef uint32_t u32user_status_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bituser_status()     ((volatile user_status_bit_view_st *)\
(user_status_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32user_status()     ((volatile u32user_status_word_view *)\
(user_status_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */            
#define biGetuser_status_Lock() (pst_bituser_status() -> Lock)            
            
/* Word access */

#define u32Getuser_status()  (*pu32user_status() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: user_config                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01304                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define user_config_REG__       0xc0d01304U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   gear_ratio0	:11; 	 /* 0..10  bit(s) W */
  uint32_t   Reserved0	:5; 	 /* 11..15  bit(s) W */
  uint32_t   gear_ratio1	:11; 	 /* 16..26  bit(s) W */ 
  uint32_t   Reserved1	:5; 	 /* 27..31  bit(s) W */                    
} user_config_bit_view_st;
        

/* WORD View */
typedef uint32_t u32user_config_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bituser_config()     ((volatile user_config_bit_view_st *)\
(user_config_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32user_config()     ((volatile u32user_config_word_view *)\
(user_config_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetuser_config_gear_ratio0(ParValue) (pst_bituser_config() -> gear_ratio0=(ParValue)) 
#define vSetuser_config_gear_ratio1(ParValue) (pst_bituser_config() -> gear_ratio1=(ParValue)) 
            
/* Word access */
#define vSetuser_config(ParValue)  (*pu32user_config() = (ParValue))
#define u32Getuser_config()  (*pu32user_config() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: user_config1                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d01308                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define user_config1_REG__       0xc0d01308U
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   gear_ratio2	:11; 	 /* 0..10  bit(s) W */
  uint32_t   Reserved0	:1; 	 /* 11..11  bit(s) W */
  uint32_t   Enable	:1; 	 /* 12..12  bit(s) W */
  uint32_t   Clock_Mode_Change	:1; 	 /* 13..13  bit(s) W */
  uint32_t   Use_Min_Delay	:1; 	 /* 14..14  bit(s) W */
  uint32_t   Reserved1	:1; 	 /* 15..15  bit(s) W */
  uint32_t   gear_ratio3	:11; 	 /* 16..26  bit(s) W */ 
  uint32_t   Reserved2	:5; 	 /* 27..31  bit(s) W */                    
} user_config1_bit_view_st;
        

/* WORD View */
typedef uint32_t u32user_config1_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bituser_config1()     ((volatile user_config1_bit_view_st *)\
(user_config1_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32user_config1()     ((volatile u32user_config1_word_view *)\
(user_config1_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */ 
#define vSetuser_config1_gear_ratio2(ParValue) (pst_bituser_config1() -> gear_ratio2=(ParValue)) 
#define vSetuser_config1_Enable(ParValue) (pst_bituser_config1() -> Enable=(ParValue)) 
#define vSetuser_config1_Clock_Mode_Change(ParValue) (pst_bituser_config1() -> Clock_Mode_Change=(ParValue)) 
#define vSetuser_config1_Use_Min_Delay(ParValue) (pst_bituser_config1() -> Use_Min_Delay=(ParValue)) 
#define vSetuser_config1_gear_ratio3(ParValue) (pst_bituser_config1() -> gear_ratio3=(ParValue)) 
            
/* Word access */
#define vSetuser_config1(ParValue)  (*pu32user_config1() = (ParValue))
#define u32Getuser_config1()  (*pu32user_config1() )
                 
    
/****************************************************************************   
*                                                                               
*       REGISTER: feature_ctrl                                
*       SIZE    : 32-bits                        
*       ADDRESS : 0xc0d0130c                             
*       ACCESS  : 32, BIT-level                       
*                                                                               
*****************************************************************************/
/* Assign Register address: */
#define feature_ctrl_REG__       0xc0d0130cU
     
/************************       STRUCTURES        ***************************/
         
        
/* BIT View */
typedef struct{
  uint32_t   stop_early_bresp	:1; 	 /* 0..0  bit(s) R/W */ 
  uint32_t   Reserved0	:31; 	 /* 1..31  bit(s) R/W */                    
} feature_ctrl_bit_view_st;
        

/* WORD View */
typedef uint32_t u32feature_ctrl_word_view;
                 


/************************     ACCESS POINTERS    ****************************/
        
/* Pointer to BIT-struct */
#define pst_bitfeature_ctrl()     ((volatile feature_ctrl_bit_view_st *)\
(feature_ctrl_REG__ ))
        
/* Pointer to WORD  */ 
#define pu32feature_ctrl()     ((volatile u32feature_ctrl_word_view *)\
(feature_ctrl_REG__ ))
                 

/************************ REGISTER ACCESS MACROS ****************************/
            
/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetfeature_ctrl_stop_early_bresp() (pst_bitfeature_ctrl() -> stop_early_bresp)
#define vSetfeature_ctrl_stop_early_bresp(ParValue)  (pst_bitfeature_ctrl() -> stop_early_bresp=(ParValue))
            
/* Word access */
#define vSetfeature_ctrl(ParValue)  (*pu32feature_ctrl() = (ParValue))
#define u32Getfeature_ctrl()  (*pu32feature_ctrl() )
            
/****************************************************************************/	
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
** |     Not requested Rules: 
** |         Rule 5.7  [A] : No reuse of identifiers
** |         Rule 19.7 [A] : Function used instead of function-like macro when possible
** |
** |     Requested Rules:
** |         Rule	5.1  [R] : No more than 31 chars to determine an identifier
** |         Rule 20.1 [R] : No definition, redefinition, or undefinition of reserved words
** |                         and standard library names register names are generated by 
** |                         converter tool from HW specs
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/

#endif /* DMC_IO_H */ 

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

