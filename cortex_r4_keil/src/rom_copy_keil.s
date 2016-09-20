;******************************************************************************
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
;*   VERSION     : $Revision: 1.5 $
;*   DATE        : $Date: 2015/05/04 09:07:18 $
;*   TAG         : $Name:  $
;*   RELEASE     : Preliminary & Confidential
;******************************************************************************

;;*********************************************
;*                  Symbols                   *
;**********************************************

    IMPORT    |Load$$APP$$RO$$Base|       [WEAK]
    IMPORT    |Image$$APP$$RO$$Base|      [WEAK]
    IMPORT    |Image$$APP$$RO$$Limit|     [WEAK]

    IMPORT    |Load$$APP$$RW$$Base|       [WEAK]
    IMPORT    |Image$$APP$$RW$$Base|      [WEAK]
    IMPORT    |Image$$APP$$RW$$Limit|     [WEAK]

    IMPORT    |Image$$V_RAM$$ZI$$Base|    [WEAK]
    IMPORT    |Image$$V_RAM$$ZI$$Limit|   [WEAK]

;/*********************************************/

    EXPORT     vASM_Copy_all_areas
    EXPORT     vASM_Init_zi

;-----------------------------------------------
;   Initializes all regions
;-----------------------------------------------

    AREA     init, CODE, READONLY, ALIGN=8

vASM_Copy_all_areas
    STMFD    SP!,{r1-r4,lr}                     ; save return address to stack

    ; copy exeption table
    LDR      r1, =0x02020000                    ; Load ROM start address
    LDR      r0, =0x00000000                    ; Load RAM start address
    LDR      r2, =0x00000040                    ; Load RAM end address      
    BL       data_copy                          ; copy data

    ; copy text
    LDR      r1, =|Load$$APP$$RO$$Base|         ; Load ROM start address
    LDR      r0, =|Image$$APP$$RO$$Base|        ; Load RAM start address
    LDR      r2, =|Image$$APP$$RO$$Limit|       ; Load RAM end address      
    BL       data_copy                          ; copy data

    ; copy data
    LDR      r1, =|Load$$APP$$RW$$Base|         ; Load ROM start address
    LDR      r0, =|Image$$APP$$RW$$Base|        ; Load RAM start address
    LDR      r2, =|Image$$APP$$RW$$Limit|       ; Load RAM end address
    BL       data_copy                          ; copy data

    LDMFD    SP!,{r1-r4,pc}                     ; return


vASM_Init_zi
    STMFD    SP!,{r1-r4,lr}                     ; save return address to stack

    ; init bss
    LDR      r0, =|Image$$V_RAM$$ZI$$Base|      ; Load RAM start address
    LDR      r2, =|Image$$V_RAM$$ZI$$Limit|     ; Load RAM end address
    BL       zi_init                            ; init section

    LDMFD    SP!,{r1-r4,pc}                     ; return

;-------------------------------------------

;==========================================================
;=================== COPY/INIT ROUTINES ===================
;==========================================================

; ----- Data-copy Routine -----
;| r0- RAM base (dst.) addr.  |
;| r1- ROM base (src.) addr.  |
;| r2- RAM end (dest.) addr.  |
; -----------------------------
data_copy
    STMFD    SP!,{r1-r4,lr}               ; save return address to stack
    B        copy_1_cmp                   ; jump to compare
copy_1
    LDR      r3,[r1],#4                   ; load temp with data, increment address
    STR      r3,[r0],#4                   ; store data, increment address
copy_1_cmp
    CMP      r0, r2                       ; check end address
    BLT      copy_1                       ; ... copy more
    LDMFD    SP!,{r1-r4,pc}               ; return

; ----- Zero-Init Routine -----
;| r0- ZI base addr.           |
;| r2- ZI limit addr.          |
; -----------------------------
zi_init
    STMFD    SP!,{r1-r4,lr}               ; save return address to stack
    LDR      r3, =0x00000000              ; load temp with data, increment address
    B        zi_init_1_cmp                ; jump to compare
zi_init_1
    STR      r3,[r0],#4                   ; store data, increment address
zi_init_1_cmp
    CMP      r0, r2                       ; check end address
    BLT      zi_init_1                    ; ... init more
    LDMFD    SP!,{r1-r4,pc}               ; return

;*****************************************************************************

    END

;************************* BEGIN of DISCLAIMER   *****************************

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
;****************************  END of DISCLAIMER ****************************

