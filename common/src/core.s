;/****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH,
;*   European LSI Design and Engineering Centre (ELDEC)
;*****************************************************************************
;*   DESCRIPTION : functions for copying arrays
;*****************************************************************************
;*   PLATFORM    : TMPR46xXBG-300
;*   PROJECT     :
;*   MODULE      : 
;*   LIBRARIES   :
;;*****************************************************************************
;*   VERSION     : $Revision: 1.8 $ 
;*   DATE        : $Date: 2015/05/04 09:07:19 $
;*   TAG         : $Name:  $
;*   RELEASE     : Preliminary and Confidential
;*****************************************************************************/
  
;*****************************************************************************
; exported function prototypes
;*****************************************************************************
    EXPORT __DSB
    EXPORT __ISB
    EXPORT asm_enable_core_int
    EXPORT asm_disable_core_int
    EXPORT asm_enable_core_fast_int
    EXPORT asm_disable_core_fast_int
    EXPORT asm_enable_core_vic_port
    EXPORT asm_disable_core_vic_port

    AREA core_function, CODE, READONLY ;READONLY is default for CODE

;*****************************************************************************
; __DSB(void)
; data barrier
;*****************************************************************************
__DSB
    DSB    
    BX     lr                ; return


;*****************************************************************************
; __ISB(void)
; instruction barrier
;*****************************************************************************
__ISB
    ISB    
    BX     lr                ; return


;*****************************************************************************
; asm_enable_core_int(void)
; enable interrupt of the core
;*****************************************************************************
asm_enable_core_int
    MRS    r0, CPSR
    AND    r0, r0, #0xFFFFFF7F
    MSR    CPSR_cx, r0
    BX     lr                ; return

;*****************************************************************************
; asm_disable_core_int(void)
; disable interrupt of the core
;*****************************************************************************
asm_disable_core_int
    MRS    r0, CPSR
    ORR    r0, r0, #0x00000080
    MSR    CPSR_cx, r0
    BX     lr                ; return

;*****************************************************************************
; asm_enable_core_fast_int(void)
; enable fast interrupt of the core
;*****************************************************************************
asm_enable_core_fast_int
    MRS    r0, CPSR
    AND    r0, r0, #0xFFFFFFBF
    MSR    CPSR_cx, r0
    BX     lr                ; return

;*****************************************************************************
; asm_disable_core_fast_int(void)
; disable fast interrupt of the core
;*****************************************************************************
asm_disable_core_fast_int
    MRS    r0, CPSR
    ORR    r0, r0, #0x00000040
    MSR    CPSR_cx, r0
    BX     lr                ; return

;*****************************************************************************
; asm_enable_core_vic_port(void)
; enable vic port of the core
;*****************************************************************************
asm_enable_core_vic_port
    MRC     p15, 0, r0, c1, c0, 0
    ORR     r0, r0, #0x01000000
    MCR     p15, 0, r0, c1, c0, 0
    ;ISB
    BX     lr                ; return

;*****************************************************************************
; asm_disable_core_vic_port(void)
; enable vic port of the core
;*****************************************************************************
asm_disable_core_vic_port
    MRC     p15, 0, r0, c1, c0, 0
    AND     r0, r0, #0xFEFFFFFF
    MCR     p15, 0, r0, c1, c0, 0
    ;ISB
    BX     lr                ; return

    END

;/************************** BEGIN of DISCLAIMER   ************************* 
;
;- TOSHIBA is continually working to improve the quality and reliability of 
;  its products. Nevertheless, semiconductor devices in general can 
;  malfunction or fail due to their inherent electrical sensitivity and  
;  vulnerability to physical stress. It is the responsibility of the buyer, 
;  when utilizing TOSHIBA products, to comply with the standards of safety 
;  in making a safe design for the entire system, and to avoid situations in 
;  which a malfunction or failure of such TOSHIBA products could cause loss of 
;  human life, bodily injury or damage to property. 
;  
;  In developing your designs, please ensure that TOSHIBA products are used 
;  within specified operating ranges as set forth in the most recent TOSHIBA 
;  products specifications. 
;  Also, please keep in mind the precautions and conditions set forth in the 
;  Handling Guide for Semiconductor Devices, or 
;  TOSHIBA Semiconductor Reliability Handbook etc..
;
;- The Toshiba products listed in this document are intended for usage in 
;  general electronics applications (computer, personal equipment, office 
;  equipment, measuring equipment, industrial robotics, domestic appliances,
;  etc.). 
;  These Toshiba products are neither intended nor warranted for usage in 
;  equipment that requires extraordinarily high quality and/or reliability or 
;  a malfunction or failure of which may cause loss of human life or bodily 
;  injury (Unintended Usage). Unintended Usage include atomic energy control 
;  instruments, airplane or spaceship instruments, transportation instruments, 
;  traffic signal instruments, combustion control instruments, medical 
;  instruments, all types of safety devices, etc.. 
;  Unintended Usage of Toshiba products listed in this document shall be 
;  made at the customers own risk. 
;
;- Toshiba assumes no liability for any damage or losses (including but not 
;  limited to, loss of business profit,business interruption, loss of business 
;  information,and other pecuniary losses) occurring 
;  from the use of, or inability to use, this product. 
;
;- The products described in this document are subject to the foreign exchange 
;  and foreign trade laws. 
;
;- The products described in this document contain components made in the 
;  United States and subject to export control of the U.S. authorities. 
;  Diversion contrary to the U.S. law is prohibited. 
;
;- The information contained herein is presented only as a guide for the 
;  applications of our products. 
;  No responsibility is assumed by TOSHIBA CORPORATION for any infringements 
;  of intellectual property or other rights of the third parties which may 
;  result from its use.  
;  No license is granted by implication or otherwise under any intellectual 
;  property or other rights of TOSHIBA CORPORATION or others. 
;
;- The information contained herein is subject to change without notice. 
;
;****************************  END of DISCLAIMER ****************************/ 
;
