;/*****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH
;*   European LSI Design and Engineering Center (ELDEC)
;******************************************************************************
;*   DESCRIPTION : Low level exception handling routines
;******************************************************************************
;*   PLATFORM    : TMPR46xXBG-300
;*   PROJECT     :
;*   MODULE      : System
;*   LIBRARIES   : None
;;******************************************************************************
;*   VERSION     : $Revision: 1.6 $
;*   DATE        : $Date: 2015/05/04 09:07:18 $
;*   TAG         : $Name:  $
;*   RELEASE     : Preliminary & Confidential
;*****************************************************************************/

;/**********************************************
;*                   Symbols                   *
;**********************************************/


;/*********************************************/


;/**********************************************
;*         EXCEPTION HANDLER ROUTINE           *
;*         ==========================          *
;*                 Description                 *
;***********************************************/

    INCLUDE ..\inc\cr4_s_keil.h

    EXPORT  unhandled_exception
    EXPORT  irq_exception
    EXPORT  undef_exception
    EXPORT  svccall_exception
    EXPORT  pref_exception
    EXPORT  databort_exception
    EXPORT  irq_exception
    EXPORT  fiq_exception

; ************** Exception Handlers ********************

	AREA    exc_handler, CODE, READONLY, ALIGN=8
	
;/*********************************************/
; Default Handler
;/*********************************************/
unhandled_exception
    B        unhandled_exception

;/*********************************************/
; Undefined instruction exception handler
;/*********************************************/
undef_exception
    B        undef_exception                 ; Call the high level handler (it should never return)

;/*********************************************/
; Supervisor Call exception handler
;/*********************************************/
svccall_exception
    B        svccall_exception               ; Call the high level handler (it should never return)

;/*********************************************/
; Prefetch abort handler
;/*********************************************/
pref_exception
    B        pref_exception                  ; Call the high level handler (it should never return)

;/*********************************************/
; IRQ Handler
;/*********************************************/
databort_exception
    B        databort_exception              ; Call the high level handler (it should never return)

;/*********************************************/
; IRQ Handler
;/*********************************************/
irq_exception
    B        irq_exception                   ; Call the high level handler (it should never return)

;/*********************************************/
; IRQ Handler
;/*********************************************/
fiq_exception
    B        fiq_exception                   ; Call the high level handler (it should never return)

;/*********************************************/

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
;  conditions set forth in the �Handling Guide for Semiconductor Devices,�
;  or �TOSHIBA Semiconductor Reliability Handbook� etc..
;
;- The Toshiba products listed in this document are intended for usage in
; general electronics applications (computer, personal equipment, office
;  equipment, measuring equipment, industrial robotics, domestic appliances,
;  etc.). These Toshiba products are neither intended nor warranted for usage
;  in equipment that requires extraordinarily high quality and/or reliability
;  or a malfunction or failure of which may cause loss of human life or bodily
;  injury (�Unintended Usage�). Unintended Usage include atomic energy control
;  instruments, airplane or spaceship instruments, transportation instruments,
;  traffic signal instruments, combustion control instruments, medical
;  instruments, all types of safety devices, etc..
;  Unintended Usage of Toshiba products listed in this document shall be made
;  at the customer�s own risk.
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

