;/*****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH
;*   European LSI Design and Engineering Center (ELDEC)
;******************************************************************************
;*   DESCRIPTION : SRAM boot-up code sequence
;******************************************************************************
;*   PLATFORM    : TMPR46xXBG-300
;*   PROJECT     :
;*   MODULE      : System
;*   LIBRARIES   : None
;;******************************************************************************
;*   VERSION     : $Revision: 1.7 $
;*   DATE        : $Date: 2015/05/11 13:33:11 $
;*   TAG         : $Name:  $
;*   RELEASE     : Preliminary & Confidential
;*****************************************************************************/

;/**********************************************
;*              Imported Symbols               *
;**********************************************/
    IMPORT   vASM_Init8WordsInBurst
    IMPORT   vDMC_Cfg
    IMPORT   vASM_Copy_all_areas
    IMPORT   vASM_Init_zi
    IMPORT   vAppMain
    IMPORT   |Image$$ARM_LIB_STACK$$ZI$$Limit|

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

    AREA     exc_table, CODE, READONLY, ALIGN=8

    INCLUDE  ..\inc\excp_hndlr_keil.h

    ENTRY
    ARM

;/**********************************************
;*        EXCEPTION TABLE @ 0x00000000         *
;*        ============================         *
;*                Description                  *
;***********************************************/
    B     Reset_Hndlr                      ; reset - set up system (supervisor mode)
    B     undef_exception                  ; undefined instruction (undefined mode)
    B     svccall_exception                ; supervisor call
    B     pref_exception                   ; prefetch abort (abort mode)
    B     databort_exception               ; data abort (abort mode)
    B     unhandled_exception              ; reserved (no handling is required)
    B     irq_exception                    ; IRQ (IRQ mode)
    B     fiq_exception                    ; FIQ (FIRQ mode)

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

;/**********************************************
;*        INIT_CORE_AREA @  0x00840000         *
;*        ============================         *
;*                 Description                 *
;***********************************************/

    AREA     init, CODE, READONLY, ALIGN=8
    PRESERVE8                               ; We do preserve the eight-byte aligment of the stack within the file

    INCLUDE  ..\inc\cr4_s_keil.h

Reset_Hndlr
;******************************************************************************
; Disable the Abort, IRQ and FIQ exceptions
;******************************************************************************
    MRS   r0, CPSR
    ORR   r0, r0, #(CPSR_I :or: CPSR_F :or: CPSR_A)
    MSR   CPSR_cx, r0

;******************************************************************************
; Disable Watchdog Timer (WDT)
;******************************************************************************
    LDR   r1, =0xC000200C                  ; (CTL) WDT Control Reg. Address
    LDR   r0, =0x1                         ; Value to write to CTL (Stops the WDT)
    STR   r0, [r1]                         ; Write value to CTL (First step to stop WDT)
    LDR   r1, =0xC0002010                  ; (CMD) WDT Command Reg. Address
    LDR   r0, =0x00005354                  ; Stop and Clear command
    STR   r0, [r1]                         ; Write command to CMD (WDT stopped and cleared)

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
    LDR    sp, =|Image$$ARM_LIB_STACK$$ZI$$Limit|-USR_STACK_OFFSET
    
; IRQ MODE   
    CPSID  aif, #IRQ_MODE                        ; switch to IRQ mode
    MOV    lr, #GP_REG_INIT_VAL
    LDR    sp, =|Image$$ARM_LIB_STACK$$ZI$$Limit|-IRQ_STACK_OFFSET

; FIQ MODE
    CPSID  aif, #FIQ_MODE                        ; switch to FIQ mode
    MOV    r8, #GP_REG_INIT_VAL
    MOV    r9, #GP_REG_INIT_VAL
    MOV    r10,#GP_REG_INIT_VAL
    MOV    r11,#GP_REG_INIT_VAL
    MOV    r12,#GP_REG_INIT_VAL
    MOV    lr, #GP_REG_INIT_VAL
    LDR    sp, =|Image$$ARM_LIB_STACK$$ZI$$Limit|-FIQ_STACK_OFFSET

; UNDEF MODE
    CPSID  aif, #UND_MODE                        ; switch to UNDEF mode
    MOV    lr, #GP_REG_INIT_VAL   
    LDR    sp, =|Image$$ARM_LIB_STACK$$ZI$$Limit|-UND_STACK_OFFSET
    
; ABORT MODE
    CPSID  aif, #ABT_MODE                        ; switch to ABORT mode
    MOV    r0, #GP_REG_INIT_VAL
    MOV    lr, #GP_REG_INIT_VAL   
    LDR    sp, =|Image$$ARM_LIB_STACK$$ZI$$Limit|-ABT_STACK_OFFSET

; SVC MODE
    CPSID  aif, #SVC_MODE                        ; switch to SVC mode
    MOV    r0, #GP_REG_INIT_VAL
    MOV    lr, #GP_REG_INIT_VAL   
    LDR    sp, =|Image$$ARM_LIB_STACK$$ZI$$Limit|

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
    ORR    r0, r0, #0x1 << 2                    ; Enable data  cache bit
    DSB
	MCR    p15, 0, r0, c15, c5, 0 				; Invalidate entire data cache
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
; init DDR-interface
;******************************************************************************
    MOVW  R0, #0xf17b                       ; Move PDHR KEY Value to register
    MOVT  R0, #0xa5c0
    MOVW  R8, #0x0400                       ; Move PDHR KEY Register Address to register 
    MOVT  R8, #0xc000
    STR   R0,[R8]                          ; Write PDHR KEY Register with PDHR KEY Value

    MOVW  R8, #0x0440                       ; Move Previous State Register to register
    MOVT  R8, #0xc000
    LDRB  R7,[R8]                          ; Load contents of Previous State Register 
                                           ; to register
    CMP   R7, #0                            ; Checking the POWER ON RESET or SLEEP 
    BLEQ  vDMC_Cfg                         ; Only POWER ON RESET, do DMC Init  
    NOP
    NOP
    NOP

;******************************************************************************
; copy all areas from flash to RAM
;******************************************************************************
    BL    vASM_Copy_all_areas                    ; copy all areas
    NOP
    NOP

;******************************************************************************
; initialize zi areas
;******************************************************************************
    BL    vASM_Init_zi                           ; init all areas
    NOP
    NOP

;******************************************************************************
; change from hivec to lowvec
;******************************************************************************
    MRC   p15, 0, r0, c1, c0, 0
    AND   r0, r0, #0xFFFFDFFF                    ; clear V bit
    MCR   p15, 0, r0, c1, c0, 0

;******************************************************************************
; Clear argc, argv, envp
;******************************************************************************
    LDR   r0, =0x0
    LDR   r1, =0x0
    LDR   r2, =0x0

;******************************************************************************
; Jump to the main function
;******************************************************************************
    B     vAppMain
    NOP
    NOP

;******************************************************************************
    END

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

