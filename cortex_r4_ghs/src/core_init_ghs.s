;/*****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH
;*   European LSI Design and Engineering Center (ELDEC)
;******************************************************************************
;*   File Name   : $RCSfile: core_init_ghs.s,v $
;*   Description : SRAM boot-up code sequence
;******************************************************************************
;*   PROJECT     : Capricorn Bt
;*   MODULE      : System
;*               : $Name:  $
;*   LIBRARIES   : None
;*   AUTHOR      : $Author: mto $
;******************************************************************************
;*   VERSION     : $Revision: 1.10 $
;*   RELEASE     : Preliminary & Confidential
;*   DATE        : $Date: 2013/10/14 07:29:09 $
;*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/cortex_r4_ghs/src/core_init_ghs.s,v $
;*   LOG:        : please have a look at the end of the file
;*****************************************************************************/


;/**********************************************
;*              Imported Symbols               *
;**********************************************/
    .globl      _reset    
    .globl      vASM_Init8WordsInBurst

;/*********************************************/
    .weak       __ghs_initial_dotsyscall

;/**********************************************
;*                   Symbols                   *
;**********************************************/
; Initial value of all general purpose registers (r0-r14)
GP_REG_INIT_VAL    EQU    0x00000000

;
; WARNING: STACK SIZE SHALL BE 64K !!!
;
SVC_STACK_SIZE     EQU    0x8000
ABT_STACK_SIZE     EQU    0x800
FIQ_STACK_SIZE     EQU    0x1000
UND_STACK_SIZE     EQU    0x800
IRQ_STACK_SIZE     EQU    0x2000
USR_STACK_SIZE     EQU    0x4000

;
; WARNING: STACK OFFSETS ARE BASED On THE ABOVE SIZES !!!
;
ABT_STACK_OFFSET   EQU    0x8000    ; (0+SVC_STACK_SIZE)
FIQ_STACK_OFFSET   EQU    0x8800    ; (ABT_STACK_OFFSET+ABT_STACK_SIZE) 
UND_STACK_OFFSET   EQU    0x9800    ; (FIQ_STACK_OFFSET+FIQ_STACK_SIZE) 
IRQ_STACK_OFFSET   EQU    0xA000    ; (USR_STACK_OFFSET+UND_STACK_SIZE) 
USR_STACK_OFFSET   EQU    0xC000    ; (IRQ_STACK_OFFSET+IRQ_STACK_SIZE) 

;/*********************************************/

    .section    ".exc_table", "ax"
    .align      8
    
    #include "excp_hndlr_ghs.h"

;/**********************************************
;*        EXCEPTION TABLE @  0x00000000        *
;*         ==========================          *
;*                 Description                 *
;***********************************************/
_reset:
    B     Reset_Hndlr                           ; reset - set up system (supervisor mode)
    B     undef_exception                       ; undefined instruction (undefined mode)
    B     svccall_exception                     ; supervisor call
    B     pref_exception                        ; prefetch abort (abort mode) 
    B     databort_exception                    ; data abort (abort mode) 
    B     unhandled_exception                   ; reserved (no handling is required)
    B     irq_exception                         ; IRQ (IRQ mode)
    B     fiq_exception                         ; FIQ (FIRQ mode)

    ; Place here the Fast IRQ handler for immediate processing
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP

; Hold the application if we jumped for some dark reason inhere
trap_sram
    B      trap_sram

;******************************************************************************


;/**********************************************
;*        INIT_CORE_AREA @  0x00800000         *
;*         ==========================          *
;*                 Description                 *
;***********************************************/
    .section    ".init", "ax"
    .align      8

    #include "cr4_s_ghs.h"

Reset_Hndlr 
;******************************************************************************
; Disable Imprecise Abort, IRQ and FIQ exceptions
;******************************************************************************
    MRS    r0, CPSR
    ORR    r0, r0, #(CPSR_I | CPSR_F | CPSR_A)
    MSR    CPSR_cx, r0

;******************************************************************************
; Disable Watchdog Timer (WDT)
;******************************************************************************
    LDR    r1, =0xC000200C                       ; (CTL) WDT Control Reg. Address
    LDR    r0, =0x1                              ; Value to write to CTL (Stops the WDT)
    STR    r0, [r1]                              ; Write value to CTL (First step to stop WDT)
    LDR    r1, =0xC0002010                       ; (CMD) WDT Command Reg. Address
    LDR    r0, =0x00005354                       ; Stop and Clear command 
    STR    r0, [r1]                              ; Write command to CMD (WDT stopped and cleared)

;******************************************************************************
; Initialize the CPU Core Registers in all Operating Modes
;******************************************************************************
;
;
;     - Initialized Registers per Op.Mode -
;  --------------------------------------------
; | USR/SYS | IRQ | FIQ | Undef | Abort | SVC  |
; |--------------------------------------------|  
; |   r0    |     |     |       |       |      |
; |   r1    |     |     |       |       |      |
; |   r2    |     |     |       |       |      |
; |   r3    |     |     |       |       |      |
; |   r4    |     |     |       |       |      |
; |   r5    |     |     |       |       |      |
; |   r6    |     |     |       |       |      |
; |   r7    |     |     |       |       |      |
; |   r8    |     | r8  |       |       |      |
; |   r9    |     | r9  |       |       |      |
; |   r10   |     | r10 |       |       |      |
; |   r11   |     | r11 |       |       |      |
; |   r12   |     | r12 |       |       |      |
; |   sp    | sp  | sp  |  sp   |  sp   | sp   |
; |   lr    | lr  | lr  |  lr   |  lr   | lr   |
; |--------------------------------------------|
; |  cpsr   | spsr| spsr| spsr  | spsr  | spsr |
;  --------------------------------------------
;
;******************************************************************************

; USER/SYSTEM MODE   
    CPSID  aif, #SYS_MODE                        ; switch to SYS mode
    MOV    r0, #GP_REG_INIT_VAL
    MOV    r1, #GP_REG_INIT_VAL
    MOV    r2, #GP_REG_INIT_VAL
    MOV    r3, #GP_REG_INIT_VAL
    MOV    r4, #GP_REG_INIT_VAL
    MOV    r5, #GP_REG_INIT_VAL
    MOV    r6, #GP_REG_INIT_VAL
    MOV    r7, #GP_REG_INIT_VAL
    MOV    r8, #GP_REG_INIT_VAL
    MOV    r9, #GP_REG_INIT_VAL
    MOV    r10,#GP_REG_INIT_VAL
    MOV    r11,#GP_REG_INIT_VAL
    MOV    r12,#GP_REG_INIT_VAL
    MOV    lr, #GP_REG_INIT_VAL
    LDR    sp, =__ghsend_stack-USR_STACK_OFFSET
    
; IRQ MODE   
    CPSID  aif, #IRQ_MODE                        ; switch to IRQ mode
    MOV    lr, #GP_REG_INIT_VAL
    LDR    sp, =__ghsend_stack-IRQ_STACK_OFFSET

; FIQ MODE
    CPSID  aif, #FIQ_MODE                        ; switch to FIQ mode
    MOV    r8, #GP_REG_INIT_VAL
    MOV    r9, #GP_REG_INIT_VAL
    MOV    r10,#GP_REG_INIT_VAL
    MOV    r11,#GP_REG_INIT_VAL
    MOV    r12,#GP_REG_INIT_VAL
    MOV    lr, #GP_REG_INIT_VAL
    LDR    sp, =__ghsend_stack-FIQ_STACK_OFFSET

; UNDEF MODE
    CPSID  aif, #UND_MODE                        ; switch to UNDEF mode
    MOV    lr, #GP_REG_INIT_VAL   
    LDR    sp, =__ghsend_stack-UND_STACK_OFFSET
    
; ABORT MODE
    CPSID  aif, #ABT_MODE                        ; switch to ABORT mode
    MOV    r0, #GP_REG_INIT_VAL
    MOV    lr, #GP_REG_INIT_VAL   
    LDR    sp, =__ghsend_stack-ABT_STACK_OFFSET

; SVC MODE
    CPSID  aif, #SVC_MODE                        ; switch to SVC mode
    MOV    r0, #GP_REG_INIT_VAL
    MOV    lr, #GP_REG_INIT_VAL   
    LDR    sp, =__ghsend_stack
    
;******************************************************************************
; Disable D- and I-cache in case it was left enabled (TRM: 8.5.5 Cache interaction with memory system)
;******************************************************************************
    MRC    p15, 0, r0, c1, c0, 0                 ; Read SCTLR
    BIC    r0, r0, #0x1 << 2                     ; Disable data cache bit
    BIC    r0, r0, #0x1 << 12                    ; Disable instruction cache bit
    DSB
    MCR    p15, 0, r0, c1, c0, 0                 ; Write SCTLR
    ISB                                          ; Ensures following instructions are 
                                                 ; not executed from cache
                              
;******************************************************************************
; Init I-cache by enabling error-checking (CR4-TRM r1p4 Chapt.8.5.5 )
;******************************************************************************
    MRC    p15, 0, r1, c1, c0, 1                 ; Read ACTLR
    AND    r1, r1, #0xFFFFFFC7                   ; Reset Error control bits
    ORR    r1, r1, #CACHE_ERR_NOABORT            ; Do not generate abort on parity errors, force write-through, enable hardware recovery
    MCR    p15, 0, r1, c1, c0, 1                 ; Write ACTLR
    MRC    p15, 0, r1, c1, c0, 1 ;test
    MCR    p15, 0, r0, c7, c5, 0                 ; Invalidate entire instruction cache
    MRC    p15, 0, r0, c1, c0, 0                 ; Read SCTLR
    ORR    r0, r0, #0x1 << 12                    ; Enable instruction cache bit
    DSB
    MCR    p15, 0, r0, c1, c0, 0                 ; Write SCTLR
    ISB

;******************************************************************************
; The following initialization sequence was commented out, as it 
; reflects the default values of the corresponding bits after POR. 
; The only change is that the external ECC correction and exception
; handling will be disabled by default, as no other master shall
; access the TSM during the IPL execution
;******************************************************************************
;    MRC    p15, 0, r1, c1, c0, 1                 ; Read ACTLR
;    ORR    r1,r1, #TCM_ATCMECEN:OR:TCM_B0TCMECEN ; External Error Enable for ATCM & B0TCM and 
;    MOV    r0, #TCM_ATCMPCEN                     ; ATCM Parity or ECC check enable
;    MOV    r2, #TCM_B0TCMPCEN                    ; B0TCM Parity or ECC check enable 
;    ORR    r0, r0, r2
;    ORR    r1, r1, r0                              
;    MCR    p15, 0, r1, c1, c0, 1                 ; Write ACTLR
;    ISB                                          ; Instruction barrier
;    MRC    p15, 0, r1, c15, c0, 0                ; Read Secondary ACTLR
;    AND    r1,r1, #TCM_ATCMECC:AND:TCM_BTCMECC   ; Enable Correction for internal ECC logic on ATCM & BTCM
;    MCR    p15, 0, r1, c15, c0, 0                ; Write Secondary ACTLR
;    ISB                                          ; Instruction barrier
;******************************************************************************

;******************************************************************************
; Initialize memory with a predefined pattern in 8 words bursts
; R0-> Data
; R1-> Addr
; R2-> Transaction count (8 words per transaction)
;******************************************************************************
    LDR    r0, =0x0
    LDR    r1, =0x00000040                       ; Load with the start address of the TCMA [LOVECS exception handlers must be preserved]
    LDR    r2, =0x7FE                            ; Number of transactions is 64KB divided into
    BL     vASM_Init8WordsInBurst                ; (8 words per transaction*4 bytes in word) = 2048 - 2
    DSB

;******************************************************************************
; copy all areas from flash to RAM, initialize areas
;******************************************************************************
    BL    init_all_areas                         ; init all areas
    NOP
    NOP

;******************************************************************************
; change from hivec to lowvec
;******************************************************************************
    MRC   p15, 0, r0, c1, c0, 0
    AND   r0, r0, #0xFFFFDFFF                    ; clear V bit
    MCR   p15, 0, r0, c1, c0, 0

;******************************************************************************
; make system call
;******************************************************************************
    mov   r0, 20                                 ; Set call type
    mov   r1, 1                                  ; Another argument
    bl    __dotsyscall                           ; Make system call
    cmp   r0, 0                                  ; Did we found Multi?

;******************************************************************************
; Clear argc, argv, envp
;******************************************************************************
    LDR   r0, =0x0
    LDR   r1, =0x0
    LDR   r2, =0x0

;******************************************************************************
; Jump to the main function
;******************************************************************************
    B     main
    NOP
    NOP

;******************************************************************************
; make system call
;******************************************************************************
    .section ".syscall", "ax"

    .globl	__dotsyscall
__dotsyscall:
    orr   r0, r0, r0                             ; This is where we set the breakpoint
    mov   pc, lr                                 ; Return

    .type   __dotsyscall,$function	
    .size   __dotsyscall,.-__dotsyscall	
    .fsize  __dotsyscall, -4
    .scall  __dotsyscall,__leaf__

    .weak   __ghs_initial_dotsyscall
    .set    __ghs_initial_dotsyscall, __dotsyscall


;******************************************************************************

;/************************* BEGIN of DISCLAIMER   *****************************

;- TOSHIBA is continually working to improve the quality and reliability of its
;  products. Nevertheless, semiconductor devices in general can malfunction or
;  fail due to their inherent electrical sensitivity and vulnerability to
;  physical stress. It is the responsibility of the buyer, when utilizing
;  TOSHIBA products, to comply with the standards of safety in making a safe
;  design for the entire system, and to avoid situations in which a malfunction
;  or failure of such TOSHIBA products could cause loss of human life, bodily
;  injury or damage to property.
;
;  In developing your designs, please ensure that TOSHIBA products are used
;  within specified operating ranges as set forth in the most recent TOSHIBA
;  products specifications. Also, please keep in mind the precautions and
;  conditions set forth in the “Handling Guide for Semiconductor Devices,”
;  or “TOSHIBA Semiconductor Reliability Handbook” etc..
;
;- The Toshiba products listed in this document are intended for usage in
; general electronics applications (computer, personal equipment, office
;  equipment, measuring equipment, industrial robotics, domestic appliances,
;  etc.). These Toshiba products are neither intended nor warranted for usage
;  in equipment that requires extraordinarily high quality and/or reliability
;  or a malfunction or failure of which may cause loss of human life or bodily
;  injury (“Unintended Usage”). Unintended Usage include atomic energy control
;  instruments, airplane or spaceship instruments, transportation instruments,
;  traffic signal instruments, combustion control instruments, medical
;  instruments, all types of safety devices, etc..
;  Unintended Usage of Toshiba products listed in this document shall be made
;  at the customer’s own risk.
;
;- Toshiba assumes no liability for any damage or losses (including but not
;  limited to, loss of business profit, business interruption, loss of business
;  information, and other pecuniary losses) occurring from the use of, or
;  inability to use, this product.
;
;- The products described in this document are subject to the foreign exchange
;  and foreign trade laws.
;
;- The products described in this document contain components made in the
;  United States and subject to export control of the U.S. authorities.
;  Diversion contrary to the U.S. law is prohibited.
;
;- The information contained herein is presented only as a guide for the
;  applications of our products. No responsibility is assumed by TOSHIBA
;  CORPORATION for any infringements of intellectual property or other rights
;  of the third parties which may result from its use. No license is granted by
;  implication or otherwise under any intellectual property or other rights
;  of TOSHIBA CORPORATION or others.
;
;- The information contained herein is subject to change without notice.
;
;****************************  END of DISCLAIMER *****************************/

;/********************************* BEGIN OF LOG ******************************
;*
;* $Log: core_init_ghs.s,v $
;* Revision 1.10  2013/10/14 07:29:09  mto
;* modify TCMA & TCMB initialisation
;*
;* Revision 1.9  2013-10-10 15:41:54  rvalchev
;* Initialized the stack pointers for all modes. 64K stack size assumed
;*
;* Revision 1.8  2013-10-07 07:49:58  mto
;* clear r0 to r2 (arguments) before jumping to main
;*
;* Revision 1.7  2013-09-20 10:41:43  mto
;* add call to __dotsyscall
;*
;* Revision 1.6  2013-07-25 14:53:02  mto
;* add call to function init_all_areas to initialise bss-section
;*
;* Revision 1.5  2013-07-24 13:42:06  mto
;* remove call to function init_all_areas
;*
;* Revision 1.4  2013-06-18 09:19:22  rvalchev
;* Excluded the LOVECS exception table from the TCMA clearance
;*
;* Revision 1.3  2013-06-14 13:02:44  mto
;* update startadress if .init area in comment to 0x00800000
;*
;* Revision 1.2  2013-06-13 15:09:30  mto
;* remove call to DMC-init function
;*
;* Revision 1.1  2013-06-03 13:57:44  mto
;* initial version for GHS
;*
;*
;*********************************** END OF LOG ******************************/
