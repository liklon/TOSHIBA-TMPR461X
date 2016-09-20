;*****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH
;*   European LSI Design and Engineering Center (ELDEC)
;*****************************************************************************
;*   DESCRIPTION : Performance monitor unit routines based on ARM's V7 sample code'
;*****************************************************************************
;*   PLATFORM    : TMPR46xXBG-300
;*   PROJECT     :
;*   MODULE      : System
;*   LIBRARIES   : None
;;*****************************************************************************
;*   VERSION     : $Revision: 1.6 $
;*   DATE        : $Date: 2015/05/04 09:07:17 $
;*   TAG         : $Name:  $
;*   RELEASE     : Preliminary & Confidential
;*****************************************************************************

    AREA     |.text|, CODE, READONLY, ALIGN=8

; ****************************************************************************
  EXPORT u32CR4_GetPMN
  ; Returns the number of progammable counters
  ; uint32_t u32CR4_GetPMN(void)
u32CR4_GetPMN
  MRC     p15, 0, r0, c9, c12, 0 ; Read PMNC Register
  MOV     r0, r0, LSR #11        ; Shift N field down to bit 0
  AND     r0, r0, #0x1F          ; Mask to leave just the 5 N bits
  BX      lr

  
; ****************************************************************************
  EXPORT  vCR4_PMNConfig
  ; Sets the event for a programmable counter to record
  ; void vCR4_PMNConfig(uint32_t u32Counter, uint32_t u32Event)
  ; counter = r0 = Which counter to program  (e.g. 0 for PMN0, 1 for PMN1)
  ; event   = r1 = The event code
vCR4_PMNConfig
  AND     r0, r0, #0x1F          ; Mask to leave only bits 4:0
  MCR     p15, 0, r0, c9, c12, 5 ; Write PMNXSEL Register
  MCR     p15, 0, r1, c9, c13, 1 ; Write EVTSELx Register
  BX      lr

  
; ****************************************************************************
  EXPORT vCR4_SetCntDivider
  ; Enables/disables the divider (1/64) on CCNT
  ; void vCR4_SetCntDivider(uint32_t u32Divider)
  ; divider = r0 = If 0 disable divider, else enable dvider
vCR4_SetCntDivider
  MRC     p15, 0, r1, c9, c12, 0  ; Read PMNC

  CMP     r0, #0x0                ; IF (r0 == 0)
  BICEQ   r1, r1, #0x08           ; THEN: Clear the D bit (disables the divisor)
  ORRNE   r1, r1, #0x08           ; ELSE: Set the D bit (enables the divisor)

  MCR     p15, 0, r1, c9, c12, 0  ; Write PMNC
  BX      lr
 

; ****************************************************************************
  EXPORT vCR4_EnablePMU
  ; Global PMU enable
  ; void vCR4_EnablePMU(void)
vCR4_EnablePMU
  MRC     p15, 0, r0, c9, c12, 0  ; Read PMNC
  ORR     r0, r0, #0x01           ; Set E bit
  MCR     p15, 0, r0, c9, c12, 0  ; Write PMNC
  BX      lr


; ****************************************************************************
  EXPORT vCR4_DisablePMU
  ; Global PMU disable
  ; void vCR4_DisablePMU(void)
vCR4_DisablePMU
  MRC     p15, 0, r0, c9, c12, 0  ; Read PMNC
  BIC     r0, r0, #0x01           ; Clear E bit
  MCR     p15, 0, r0, c9, c12, 0  ; Write PMNC
  BX      lr

  
; ****************************************************************************
  EXPORT vCR4_EnableCCNT
  ; Enable the CCNT
  ; void vCR4_EnableCCNT(void)
vCR4_EnableCCNT
  MOV     r0, #0x80000000         ; Set C bit
  MCR     p15, 0, r0, c9, c12, 1  ; Write CNTENS Register
  BX      lr
  

; ****************************************************************************
  EXPORT vCR4_DisableCCNT
  ; Disable the CCNT
  ; void vCR4_DisableCCNT(void)
vCR4_DisableCCNT
  MOV     r0, #0x80000000         ; Clear C bit
  MCR     p15, 0, r0, c9, c12, 2  ; Write CNTENC Register
  BX      lr

  
; ****************************************************************************
  EXPORT vCR4_EnablePMN
  ; Enable PMN{n}
  ; void vCR4_EnablePMN(uint32_t u32Counter)
  ; counter = r0 = The counter to enable (e.g. 0 for PMN0, 1 for PMN1)
vCR4_EnablePMN
  MOV     r1, #0x1                ; Use arg (r0) to set which counter to disable
  MOV     r1, r1, LSL r0

  MCR     p15, 0, r1, c9, c12, 1  ; Write CNTENS Register
  BX      lr

  
; ****************************************************************************
  EXPORT vCR4_DisablePMN
  ; Enable PMN{n}
  ; void vCR4_DisablePMN(uint32_t u32Counter)
  ; counter = r0 = The counter to enable (e.g. 0 for PMN0, 1 for PMN1)
vCR4_DisablePMN
  MOV     r1, #0x1                ; Use arg (r0) to set which counter to disable
  MOV     r1, r1, LSL r0

  MCR     p15, 0, r1, c9, c12, 1  ; Write CNTENS Register
  BX      lr


; ****************************************************************************
  EXPORT u32CR4_ReadCCNT
  ; Returns the value of CCNT
  ; uint32_t u32CR4_ReadCCNT(void)
u32CR4_ReadCCNT
  MRC     p15, 0, r0, c9, c13, 0 ; Read CCNT Register
  BX      lr

; ****************************************************************************
  EXPORT  u32CR4_ReadPMN
  ; Returns the value of PMN{n}
  ; uint32_t u32CR4_ReadPMN(uint32_t u32Counter)
  ; counter = r0 =  The counter to read (e.g. 0 for PMN0, 1 for PMN1)
u32CR4_ReadPMN
  AND     r0, r0, #0x1F          ; Mask to leave only bits 4:0
  MCR     p15, 0, r0, c9, c12, 5 ; Write PMNXSEL Register
  MRC     p15, 0, r0, c9, c13, 2 ; Read current PMNx Register
  BX      lr
    

; ****************************************************************************
  EXPORT u32CR4_ReadFlags
  ; Returns the value of the overflow flags
  ; uint32_t u32CR4_ReadFlags(void)
u32CR4_ReadFlags
  MRC     p15, 0, r0, c9, c12, 3 ; Read FLAG Register
  BX      lr

  
; ****************************************************************************
  EXPORT vCR4_WriteFlags
  ; Writes the overflow flags
  ; void vCR4_WriteFlags(uint32_t u32Flags)
vCR4_WriteFlags
  MCR     p15, 0, r0, c9, c12, 3 ; Write FLAG Register
  BX      lr
  

; ****************************************************************************
  EXPORT  vCR4_EnableCCNTIrq
  ; Enables interrupt generation on overflow of the CCNT
  ; void vCR4_EnableCCNTIrq(void)
vCR4_EnableCCNTIrq
  MOV     r0, #0x80000000
  MCR     p15, 0, r0, c9, c14, 1  ; Write INTENS Register
  BX      lr


; ****************************************************************************
  EXPORT  vCR4_DisableCCNTIrq
  ; Disables interrupt generation on overflow of the CCNT
  ; void vCR4_DisableCCNTIrq(void)
vCR4_DisableCCNTIrq
  MOV     r0, #0x80000000
  MCR     p15, 0, r0, c9, c14, 2   ; Write INTENC Register
  BX      lr

  
; ****************************************************************************
  EXPORT vCR4_EnablePmnIrq
  ; Enables interrupt generation on overflow of PMN{x}
  ; void vCR4_EnablePmnIrq(uint32_t u32Counter)
  ; counter = r0 =  The counter to enable the interrupt for (e.g. 0 for PMN0, 1 for PMN1)
vCR4_EnablePmnIrq
  MOV     r1, #0x1                 ; Use arg (r0) to set which counter to disable
  MOV     r0, r1, LSL r0
  MCR     p15, 0, r0, c9, c14, 1   ; Write INTENS Register
  BX      lr


; ****************************************************************************
  EXPORT vCR4_DisablePMNIrq
  ; Disables interrupt generation on overflow of PMN{x}
  ; void vCR4_DisablePMNIrq(uint32_t u32Counter)
  ; counter = r0 =  The counter to disable the interrupt for (e.g. 0 for PMN0, 1 for PMN1)
vCR4_DisablePMNIrq
  MOV     r1, #0x1                ; Use arg (r0) to set which counter to disable
  MOV     r0, r1, LSL r0
  MCR     p15, 0, r0, c9, c14, 2  ; Write INTENC Register
  BX      lr


; ****************************************************************************
  EXPORT vCR4_ResetPMN
  ; Resets the programmable counters
  ; void vCR4_ResetPMN(void)
vCR4_ResetPMN
  MRC     p15, 0, r0, c9, c12, 0  ; Read PMNC
  ORR     r0, r0, #0x02           ; Set P bit (Event Counter Reset)
  MCR     p15, 0, r0, c9, c12, 0  ; Write PMNC
  BX      lr


; ****************************************************************************
  EXPORT  vCR4_ResetCCNT
  ; Resets the CCNT
  ; void vCR4_ResetCCNT(void)
vCR4_ResetCCNT
  MRC     p15, 0, r0, c9, c12, 0  ; Read PMNC
  ORR     r0, r0, #0x04           ; Set C bit (Event Counter Reset)
  MCR     p15, 0, r0, c9, c12, 0  ; Write PMNC
  BX      lr


; ****************************************************************************
  EXPORT vCR4_PMUSoftwareIncrement
  ; Writes to software increment register
  ; void vCR4_PMUSoftwareIncrement(uint32_t u32Counter)
  ; counter = r0 =  The counter to increment (e.g. 0 for PMN0, 1 for PMN1)
vCR4_PMUSoftwareIncrement
  MOV     r1, #0x01
  MOV			r1, r1, LSL r0
  MCR     p15, 0, r1, c9, c12, 4 ; Write SWINCR Register
  BX      lr


; ****************************************************************************  
  EXPORT  vCR4_EnablePMUUserAccess
  ; Enables User mode access to the PMU (must be called in a priviledged mode)
  ; void vCR4_EnablePMUUserAccess(void)
vCR4_EnablePMUUserAccess
  MRC     p15, 0, r0, c9, c14, 0  ; Read PMUSERENR Register
  ORR     r0, r0, #0x01           ; Set EN bit (bit 0)
  MCR     p15, 0, r0, c9, c14, 0  ; Write PMUSERENR Register
  BX      lr

  
; ****************************************************************************  
  EXPORT  vCR4_DisablePMUUserAccess
  ; Disables User mode access to the PMU (must be called in a priviledged mode)
  ; void vCR4_DisablePMUUserAccess(void)
vCR4_DisablePMUUserAccess
  MRC     p15, 0, r0, c9, c14, 0  ; Read PMUSERENR Register
  BIC     r0, r0, #0x01           ; Clear EN bit (bit 0)
  MCR     p15, 0, r0, c9, c14, 0  ; Write PMUSERENR Register
  BX      lr

; ****************************************************************************

	END

;************************ BEGIN of DISCLAIMER   *****************************

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

