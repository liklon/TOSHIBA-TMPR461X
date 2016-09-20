;*****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH,
;*   European LSI Design and Engineering Centre (ELDEC)
;*****************************************************************************
;*   DESCRIPTION : Cortex R4 burst access utilities
;*****************************************************************************
;*   PLATFORM    : TMPR46xXBG-300
;*   PROJECT     :
;*   MODULE      : Cortex R4 Core
;*   LIBRARIES   : None
;;*****************************************************************************
;*   VERSION     : $Revision: 1.7 $ 
;*   DATE        : $Date: 2015/05/04 09:07:18 $
;*   TAG         : $Name:  $
;*   RELEASE     : Preliminary and Confidential
;*****************************************************************************/
  
;*****************************************************************************
; Exported function prototypes
;*****************************************************************************
    EXPORT vASM_Init8WordsInBurst      
    EXPORT vASM_Copy8WordsInBurst
    EXPORT vASM_Copy4WordsInBurstMem2FiFo
    EXPORT vASM_Copy4WordsInBurstFiFo2Mem
    EXPORT vASM_Copy8WordsInBurstMem2FiFo
    EXPORT vASM_Copy8WordsInBurstFiFo2Mem
    

;*****************************************************************************
; Area definitions
;*****************************************************************************
    AREA    init, CODE, READONLY, ALIGN=8

;*****************************************************************************
; R0-> Data
; R1-> Addr
; R2-> Transaction count (8 words per transaction)
;*****************************************************************************
vASM_Init8WordsInBurst
    STMFD SP!,{r1-r12, lr}      ; Save return address and all modified registers to stack
    MOV r10, r1                 ; Destination address
    MOV r11, r0                 ; Data apttern to be written
    MOV r12, r2                 ; Transaction count        

    MOV r0, r11                 ; Populate the pattern
    MOV r1, r11
    MOV r2, r11
    MOV r3, r11
    MOV r4, r11
    MOV r5, r11
    MOV r6, r11
    MOV r7, r11

    LDR r8, =0x0                ; Initialize the counter

b8clear_loop
    STMIA r10!, {r0-r7}         ; Burst write of 8 words
    ADD   r8, r8, #1            ; Decrement the counter
    CMP   r8, r12               ; Compare
    BNE   b8clear_loop          ; Bottom out

    LDMFD SP!,{r1-r12,pc}       ; Restore and return 

;*****************************************************************************
; R0-> Source
; R1-> Destination
; R2-> Transaction count (8 words per transaction)
;*****************************************************************************
vASM_Copy8WordsInBurst   
    STMFD SP!,{r1-r12, lr}      ; Save return address and all modified registers to stack    
    MOV r10, r0                 ; Source address
    MOV r11, r1                 ; Destination address
    MOV r12, r2                 ; Transaction count        
    
    LDR r8, =0x0                ; Initialize the counter

b8copy_loop
    LDMIA r10!, {r0-r7}         ; Burst read of 8 words
    STMIA r11!, {r0-r7}         ; Burst write of 8 words
    ADD   r8, r8, #1            ; Decrement the counter
    CMP   r8, r12               ; Compare
    BNE   b8copy_loop           ; Bottom out

    LDMFD SP!,{r1-r12,pc}       ; Restore and return 


;*****************************************************************************
; R0-> Source
; R1-> Destination
; R2-> Transaction count (4 words per transaction)
;*****************************************************************************
vASM_Copy4WordsInBurstMem2FiFo   
    STMFD SP!,{r1-r12, lr}      ; Save return address and all modified registers to stack    
    MOV r10, r0                 ; Source address
    MOV r9,  r1                 ; backup Destination address    
    MOV r12, r2                 ; Transaction count        
    
    LDR r8, =0x0                ; Initialize the counter

b4copy_Mem2FiFo_loop
    MOV r11, r9                 ; restore destination address from back up
    LDMIA r10!, {r0-r3}         ; Burst read of 4 words
    STMIA r11!, {r0-r3}         ; Burst write of 4 words
    ADD   r8, r8, #1            ; Decrement the counter
    CMP   r8, r12               ; Compare
    BNE   b4copy_Mem2FiFo_loop ; Bottom out

    LDMFD SP!,{r1-r12,pc}       ; Restore and return 


;*****************************************************************************
; R0-> Source
; R1-> Destination
; R2-> Transaction count (4 words per transaction)
;*****************************************************************************
vASM_Copy4WordsInBurstFiFo2Mem   
    STMFD SP!,{r1-r12, lr}      ; Save return address and all modified registers to stack    
    MOV r11, r1                 ; Destination address
    MOV r9,  r0                 ; backup source address    
    MOV r12, r2                 ; Transaction count        
    
    LDR r8, =0x0                ; Initialize the counter

b4copy_FiFo2Mem_loop
    MOV r10, r9                 ; restore source address from back up
    LDMIA r10!, {r0-r3}         ; Burst read of 4 words
    STMIA r11!, {r0-r3}         ; Burst write of 4 words
    ADD   r8, r8, #1            ; Decrement the counter
    CMP   r8, r12               ; Compare
    BNE   b4copy_FiFo2Mem_loop  ; Bottom out

    LDMFD SP!,{r1-r12,pc}       ; Restore and return


;*****************************************************************************
; R0-> Source
; R1-> Destination
; R2-> Transaction count (8 words per transaction)
;*****************************************************************************
vASM_Copy8WordsInBurstMem2FiFo   
    STMFD SP!,{r1-r12, lr}      ; Save return address and all modified registers to stack    
    MOV r10, r0                 ; Source address
    MOV r9,  r1                 ; backup Destination address    
    MOV r12, r2                 ; Transaction count        
    
    LDR r8, =0x0                ; Initialize the counter

b8copy_Mem2FiFo_loop
    MOV r11, r9                 ; restore destination address from back up
    LDMIA r10!, {r0-r7}         ; Burst read of 4 words
    STMIA r11!, {r0-r7}         ; Burst write of 4 words
    ADD   r8, r8, #1            ; Decrement the counter
    CMP   r8, r12               ; Compare
    BNE   b8copy_Mem2FiFo_loop ; Bottom out

    LDMFD SP!,{r1-r12,pc}       ; Restore and return 


;*****************************************************************************
; R0-> Source
; R1-> Destination
; R2-> Transaction count (8 words per transaction)
;*****************************************************************************
vASM_Copy8WordsInBurstFiFo2Mem   
    STMFD SP!,{r1-r12, lr}      ; Save return address and all modified registers to stack    
    MOV r11, r1                 ; Destination address
    MOV r9,  r0                 ; backup source address    
    MOV r12, r2                 ; Transaction count        
    
    LDR r8, =0x0                ; Initialize the counter

b8copy_FiFo2Mem_loop
    MOV r10, r9                 ; restore source address from back up
    LDMIA r10!, {r0-r7}         ; Burst read of 4 words
    STMIA r11!, {r0-r7}         ; Burst write of 4 words
    ADD   r8, r8, #1            ; Decrement the counter
    CMP   r8, r12               ; Compare
    BNE   b8copy_FiFo2Mem_loop  ; Bottom out

    LDMFD SP!,{r1-r12,pc}       ; Restore and return

    END

;*****************************************************************************

;/************************** BEGIN of DISCLAIMER   ***************************
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
