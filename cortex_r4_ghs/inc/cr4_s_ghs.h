;/*****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH
;*   European LSI Design and Engineering Center (ELDEC)
;******************************************************************************
;*   File Name   : $RCSfile: cr4_s_ghs.h,v $
;*   Description : Assembly header file for Cortex A9 generic definitions
;******************************************************************************
;*   PROJECT     : Capricorn Bt
;*   MODULE      : Cortex R4 Core
;*               : $Name:  $
;*   LIBRARIES   : None
;*   AUTHOR      : $Author: mto $
;******************************************************************************
;*   VERSION     : $Revision: 1.1 $
;*   RELEASE     : Preliminary & Confidential
;*   DATE        : $Date: 2013-06-03 13:57:44 $
;*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/cortex_r4_ghs/inc/cr4_s_ghs.h,v $
;*   LOG:        : please have a look at the end of the file
;*****************************************************************************/


;/**********************************************
;*                 Constants                   *
;**********************************************/
; Interrupt controll bits in CPSR
CPSR_I                EQU     0x80          ; when I bit is set, IRQ is disabled
CPSR_F                EQU     0x40          ; when F bit is set, FIQ is disabled
CPSR_A                EQU     0x100         ; when A bit is set, Abort is disabled

; Modes definition used for fast CPS instruction change
USR_MODE              EQU     16
FIQ_MODE              EQU     17
IRQ_MODE              EQU     18
SVC_MODE              EQU     19
ABT_MODE              EQU     23
UND_MODE              EQU     27
SYS_MODE              EQU     31

; Cache Parity Error setting
CACHE_ERR_DIS         EQU     0x0           ; Disabled Cache Parity checking
CACHE_ERR_ABORT       EQU     0x4 << 3      ; Generate Abort on parity error, enable HW recovery
CACHE_ERR_NOABORT     EQU     0x5 << 3      ; No Abort generated, enable HW recovery
CACHE_ERR_MASK        EQU     0xFFFFFFC7    ; Mask for Auxilary Control Register (CR4 TRM r1p4 page 4-40)

; TCM setting
TCM_ATCMPCEN          EQU     0x2000000     ; ATCM parity or ECC check
TCM_B0TCMPCEN         EQU     0x4000000     ; B0TCM parity or ECC check
TCM_ATCMECEN          EQU     0x1           ; ATCM External Error Enable
TCM_B0TCMECEN         EQU     0x2           ; B0TCM External Error Enable
TCM_ATCMECC           EQU     0xFFFFFFFB    ; Correction for internal ECC logic on ATCM port
TCM_BTCMECC           EQU     0xFFFFFFF7    ; Correction for internal ECC logic on BTCM port

;A/BTCM Region Register
TCMRR_EN              EQU     0x1           ; TCM Enable
TCMRR_BASE_ADDR_POS   EQU     12            ; TCM Base address position
TCMRR_BASE_ADDR_MSK   EQU     0xFFFFF000    ; TCM Base address mask

;TCM Base Adresses
TCM_A_BASE            EQU     0x00008000    ; Cap-Bt TCMB0 base address
TCM_B_BASE            EQU     0x00000000    ; Cap-Bt TCMA base address

; EXCEPTION CODEs definitions
UNDEF_EXCP_CODE       EQU     0x04 << 8     ; UNDEFINED CODE
SVC_EXCP_CODE         EQU     0x08 << 8     ; SVC CALL CODE
PREF_EXCP_CODE        EQU     0x0C << 8     ; PREFETCH ABORT CODE
DABRT_EXCP_CODE       EQU     0x10 << 8     ; DATA ABORT CODE
UNH_EXCP_CODE         EQU     0x14 << 8     ; RESERVED CODE
IRQ_EXCP_CODE         EQU     0x18 << 8     ; IRQ CODE
FIQ_EXCP_CODE         EQU     0x1C << 8     ; FIQ CODE


;/*********************************************/


;/**********************************************
;*                    Macros                   *
;**********************************************/


;/****************************************************************************/


;/***********************  BEGIN of DISCLAIMER   *****************************
;
;- TOSHIBA is continually working to improve the quality and reliability of
;  its products.
;  Nevertheless, semiconductor devices in general can malfunction or fail
;  due to their inherent electrical sensitivity and vulnerability to physical
;  stress. It is the responsibility of the buyer, when utilizing TOSHIBA
;  products, to comply with the standards of safety in making a safe design
;  for the entire system, and to avoid situations in which a malfunction or
;  failure of such TOSHIBA products could cause loss of human life,
;  bodily injury or damage to property.
;
;  In developing your designs, please ensure that TOSHIBA products are used
;  within specified operating ranges as set forth in the most recent TOSHIBA
;  products specifications. Also, please keep in mind the precautions and
;  conditions set forth in the “Handling Guide for Semiconductor Devices, or
;  TOSHIBA Semiconductor Reliability Handbook etc..
;
;- The Toshiba products listed in this document are intended for usage in
;  general electronics applications (computer, personal equipment,
;  office equipment, measuring equipment,industrial robotics, domestic
;  appliances, etc.). These Toshiba products are neither intended nor
;  warranted for usage in equipment that requires extraordinarily high quality
;  and/or reliability or a malfunction or failure of which may cause loss
;  of human life or bodily injury (“Unintended Usage).
;  Unintended Usage include atomic energy control instruments, airplane or
;  spaceship instruments, transportation instruments, traffic signal
;  instruments, combustion control instruments, medical instruments,
;  all types of safety devices, etc..
;  Unintended Usage of Toshiba products listed in this document shall be made
;  at the customer’s own risk.
;
;- Toshiba assumes no liability for any damage or losses (including but not
;  limited to, loss of business profit,business interruption, loss of business
;  information,and other pecuniary losses) occurring from the use of,
;  or inability to use, this product.
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

;/********************************* BEGIN OF LOG ******************************
;*
;* $Log: cr4_s_ghs.h,v $
;* Revision 1.1  2013-06-03 13:57:44  mto
;* initial version for GHS
;*
;*
;*********************************** END OF LOG ******************************/
