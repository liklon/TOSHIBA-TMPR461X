;;****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH
;*   European LSI Design and Engineering Center (ELDEC)
;******************************************************************************
;*   File Name   : $RCSfile: rom_copy_ghs.s,v $
;*   Description : SRAM boot-up code sequence
;******************************************************************************
;*   PROJECT     : Capricorn Bt
;*   MODULE      : System
;*               : $Name:  $
;*   LIBRARIES   : None
;*   AUTHOR      : $Author: mto $
;******************************************************************************
;*   VERSION     : $Revision: 1.2 $
;*   RELEASE     : Preliminary & Confidential
;*   DATE        : $Date: 2013-07-24 13:38:10 $
;*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/cortex_r4_ghs/src/rom_copy_ghs.s,v $
;*   LOG:        : please have a look at the end of the file
;******************************************************************************

;;*********************************************
;*                  Symbols                   *
;**********************************************
    .weak    __begin_ROM_exc_table
    .weak    __begin_RAM_exc_table
    .weak    __end_RAM_exc_table

    .weak    __begin_ROM_text
    .weak    __begin_RAM_text
    .weak    __end_RAM_text

    .weak    __begin_ROM_rodata
    .weak    __begin_RAM_rodata
    .weak    __end_RAM_rodata

    .weak    __begin_ROM_data
    .weak    __begin_RAM_data
    .weak    __end_RAM_data

    .weak    __begin_ROM_syscall
    .weak    __begin_RAM_syscall
    .weak    __end_RAM_syscall

    .weak    __begin_RAM_bss
    .weak    __end_RAM_bss

;/*********************************************/

    EXPORT     init_all_areas

;-----------------------------------------------
;   Initializes all regions
;-----------------------------------------------
    .section    ".init", "ax"
    .align      8

init_all_areas
    STMFD    SP!,{r1-r4,lr}               ; save return address to stack

    ; copy exc_table
    LDR      r1, =__begin_ROM_exc_table   ; Load ROM start address
    LDR      r0, =__begin_RAM_exc_table   ; Load RAM start address
    LDR      r2, =__end_RAM_exc_table     ; Load RAM end address
    BL       data_copy                    ; copy data

    ; copy text
    LDR      r1, =__begin_ROM_text        ; Load ROM start address
    LDR      r0, =__begin_RAM_text        ; Load RAM start address
    LDR      r2, =__end_RAM_text          ; Load RAM end address      
    BL       data_copy                    ; copy data

    ; copy rodata
    LDR      r1, =__begin_ROM_rodata      ; Load ROM start address
    LDR      r0, =__begin_RAM_rodata      ; Load RAM start address
    LDR      r2, =__end_RAM_rodata        ; Load RAM end address
    BL       data_copy                    ; copy data

    ; copy data
    LDR      r1, =__begin_ROM_data        ; Load ROM start address
    LDR      r0, =__begin_RAM_data        ; Load RAM start address
    LDR      r2, =__end_RAM_data          ; Load RAM end address
    BL       data_copy                    ; copy data

    ; copy syscall
    LDR      r1, =__begin_ROM_syscall     ; Load ROM start address
    LDR      r0, =__begin_RAM_syscall     ; Load RAM start address
    LDR      r2, =__end_RAM_syscall       ; Load RAM end address
    BL       data_copy                    ; copy data

    ; init bss
    LDR      r0, =__begin_RAM_bss         ; Load RAM start address
    LDR      r2, =__end_RAM_bss           ; Load RAM end address
    BL       zi_init                      ; init section

    LDMFD    SP!,{r1-r4,pc}               ; return

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

;******************************** BEGIN OF LOG ******************************
;*
;* $Log: rom_copy_ghs.s,v $
;* Revision 1.2  2013-07-24 13:38:10  mto
;* modify copy and init routines
;*
;* Revision 1.1  2013-06-03 13:57:44  mto
;* initial version for GHS
;*
;*
;*********************************** END OF LOG *****************************
