;/****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH,
;*   European LSI Design and Engineering Centre (ELDEC)
;*****************************************************************************
;*   DESCRIPTION :
;*****************************************************************************
;*   PLATFORM    : TMPR46xXBG-300
;*   PROJECT     :
;*   MODULE      : 
;*   LIBRARIES   :
;;*****************************************************************************
;*   VERSION     : $Revision: 1.7 $ 
;*   DATE        : $Date: 2015/05/04 09:07:15 $
;*   TAG         : $Name: LLDD_1_6 $
;*   RELEASE     : Preliminary and Confidential
;*****************************************************************************/
  
;*****************************************************************************
; exported function prototypes
;*****************************************************************************
    EXPORT write_burst4
    EXPORT read_burst4
    EXPORT write_burst8
    EXPORT read_burst8
    EXPORT word_write
    EXPORT word_read
    EXPORT hword_write
    EXPORT hword_read
    EXPORT byte_write
    EXPORT byte_read

    AREA rw_support, CODE, READONLY ;READONLY is default for CODE

;*****************************************************************************
; write_burst4(int addr, int data)
; writes 4 words to an address with burst
;*****************************************************************************
; r0 contains addr
; r1-r4 contains data

write_burst4
    STMFD SP!,{lr}      ; save return address to stack
    STMIA r0!,{r1-r4}    
    LDMDB r0!,{r1-r4}
    LDMFD SP!,{pc}      ; return

;*****************************************************************************
; read_burst4(int addr)
; reads 4 words from an address with burst
;*****************************************************************************
; r0 contains addr

read_burst4
    STMFD SP!,{r1-r5,lr}      ; save return address to stack
    LDMIA r0!,{r2-r5}
    STMIA r1!,{r2-r5}
    LDMFD SP!,{r1-r5,pc}      ; return
    
;*****************************************************************************
; write_burst8(int addr, int data)
; writes 8 words to an address with burst
;*****************************************************************************
; r0 contains addr
; r1-r8 contains data

write_burst8
    STMFD SP!,{lr}      ; save return address to stack
    STMIA r0!,{r1-r8}    
    LDMDB r0!,{r1-r8}    
    LDMFD SP!,{pc}      ; return    
    
;*****************************************************************************
; read_burst8(int addr)
; reads 8 words from an address with burst
;*****************************************************************************
; r0 contains addr

read_burst8
    STMFD SP!,{r1-r9,lr}      ; save return address to stack
    MOV   r9, r1
    LDMIA r0!,{r1-r8}
    STMIA r9!,{r1-r8}
    LDMFD SP!,{r1-r9,pc}      ; return

;*****************************************************************************
; word_write(int addr, int data)
; writes a word to an address
;*****************************************************************************
; r0 contains addr
; r1 contains data

word_write
    STMFD SP!,{lr}      ; save return address to stack
    STR r1,[r0,#0]      ; store data
    LDMFD SP!,{pc}      ; return

;*****************************************************************************
; word_read(int addr)
; reads a word from an address
;*****************************************************************************
; r0 contains addr

word_read
    STMFD SP!,{r1,lr}   ; save return address and r1 to stack 
    LDR r1,[r0,#0]      ; load temp with data
    MOV r0, r1          ; copy temp to r0 for return value
    LDMFD SP!,{r1,pc}   ; return
 
;*****************************************************************************
; hword_write(int addr, int data)
; writes a half word to an address
;*****************************************************************************
; r0 contains addr
; r1 contains data

hword_write
    STMFD SP!,{lr}      ; save return address to stack
    STRH r1,[r0,#0]     ; store data
    LDMFD SP!,{pc}      ; return

;*****************************************************************************
; hword_read(int addr)
; reads a half word from an address
;*****************************************************************************
; r0 contains addr

hword_read
    STMFD SP!,{r1,lr}   ; save return address and r1 to stack
    LDRH r1,[r0,#0]     ; load temp with data
    MOV r0, r1          ; copy temp to r0 for return value
    LDMFD SP!,{r1,pc}   ; return
 
;*****************************************************************************
; byte_write(int addr, int data)
; writes a byte to an address
;*****************************************************************************
; r0 contains addr
; r1 contains data

byte_write
    STMFD SP!,{lr}      ; save return address to stack
    STRB r1,[r0,#0]     ; store data
    LDMFD SP!,{pc}      ; return
 
;*****************************************************************************
; byte_read(int addr)
; reads a byte from an address
;*****************************************************************************
; r0 contains addr

byte_read
    STMFD SP!,{r1,lr}   ; save return address and r1 to stack 
    LDRB r1,[r0,#0]     ; load temp with data
    MOV r0, r1          ; copy temp to r0 for return value    
    LDMFD SP!,{r1,pc}   ; return 
 
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
