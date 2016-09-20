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
;*   VERSION     : $Revision: 1.5 $ 
;*   DATE        : $Date: 2015/05/04 09:07:19 $
;*   TAG         : $Name:  $
;*   RELEASE     : Preliminary and Confidential
;*****************************************************************************/
  
;*****************************************************************************
; exported function prototypes
;*****************************************************************************
    EXPORT asm_copy_word
    EXPORT asm_copy_hword
    EXPORT asm_copy_byte

    AREA copy_function, CODE, READONLY ;READONLY is default for CODE

;*****************************************************************************
; asm_copy_word(uint32_t arg1, uint32_t arg2, uint32_t arg3)
; copies source block to destination block copying words
;*****************************************************************************
; arg1 = start adresse source
; arg2 = end adresse source
; arg3 = start adresse destination

asm_copy_word
    STMFD SP!,{r1-r4,lr}      ; save return address to stack

wordcopy
    LDR   r3,[r0],#4          ; load temp with data, increment address
    STR   r3,[r2],#4          ; store data, increment address
    SUBS  r4,r1,r0            ; check end address
    BPL   wordcopy            ; ... copy more

    LDMFD SP!,{r1-r4,pc}      ; return

;*****************************************************************************
; asm_copy_hword(uint32_t arg1, uint32_t arg2, uint32_t arg3)
; copies source block to destination block copying half words
;*****************************************************************************
; arg1 = start adresse source
; arg2 = end adresse source
; arg3 = start adresse destination

asm_copy_hword
    STMFD SP!,{r1-r4,lr}      ; save return address to stack

hwordcopy
    LDRH  r3,[r0],#2          ; load temp with data, increment address
    STRH  r3,[r2],#2          ; store data, increment address
    SUBS  r4,r1,r0            ; check end address
    BPL   hwordcopy           ; ... copy more

    LDMFD SP!,{r1-r4,pc}      ; return

;*****************************************************************************
; asm_copy_byte(uint32_t arg1, uint32_t arg2, uint32_t arg3)
; copies source block to destination block copying bytes
;*****************************************************************************
; arg1 = start adresse source
; arg2 = end adresse source
; arg3 = start adresse destination

asm_copy_byte
    STMFD SP!,{r1-r4,lr}      ; save return address to stack

bytecopy
    LDRB  r3,[r0],#1          ; load temp with data, increment address
    STRB  r3,[r2],#1          ; store data, increment address
    SUBS  r4,r1,r0            ; check end address
    BPL   bytecopy            ; ... copy more

    LDMFD SP!,{r1-r4,pc}      ; return

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
