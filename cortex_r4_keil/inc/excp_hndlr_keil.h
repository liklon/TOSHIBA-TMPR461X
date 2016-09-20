;/*****************************************************************************
;*   This software is copyright protected. All rights reserved
;*   Toshiba Electronics Europe GmbH
;*   European LSI Design and Engineering Center (ELDEC)
;******************************************************************************
;*   DESCRIPTION : Capricorn_Bt exception handlers
;******************************************************************************
;*   PLATFORM    : TMPR46xXBG-300
;*   PROJECT     :
;*   MODULE      : System
;*   LIBRARIES   : None
;;******************************************************************************
;*   VERSION     : $Revision: 1.5 $
;*   DATE        : $Date: 2015/05/04 09:07:16 $
;*   TAG         : $Name:  $
;*   RELEASE     : Preliminary & Confidential
;*****************************************************************************/

;/**********************************************
;*                 Constants                   *
;**********************************************/


;/*********************************************/


;/**********************************************
;*                    Macros                   *
;**********************************************/


;/*********************************************/


;/**********************************************
;*        Exported function prototypes         *
;**********************************************/

;/****************************************************************************
; *
; * Function:       unhandled_exception
; *
; * Purpose:        Unhandled exception
; *
; * Inputs:         none
; *
; * Outputs:        none
; *
; * Return Values:  none
; *
; * Limitations:    none
; *
; ***************************************************************************/
    IMPORT unhandled_exception

;/****************************************************************************
; *
; * Function:       irq_exception
; *
; * Purpose:        IRQ exception
; *
; * Inputs:         none
; *
; * Outputs:        none
; *
; * Return Values:  none
; *
; * Limitations:    none
; *
; ***************************************************************************/
    IMPORT irq_exception

;/****************************************************************************
; *
; * Function:       undef_exception
; *
; * Purpose:        Undefined instruction exception
; *
; * Inputs:         none
; *
; * Outputs:        none
; *
; * Return Values:  none
; *
; * Limitations:    none
; *
; ***************************************************************************/
    IMPORT undef_exception

;/****************************************************************************
; *
; * Function:       svccall_exception
; *
; * Purpose:        Supervisor call exception
; *
; * Inputs:         none
; *
; * Outputs:        none
; *
; * Return Values:  none
; *
; * Limitations:    none
; *
; ***************************************************************************/
    IMPORT svccall_exception

;/****************************************************************************
; *
; * Function:       pref_exception
; *
; * Purpose:        Prefetch exception
; *
; * Inputs:         none
; *
; * Outputs:        none
; *
; * Return Values:  none
; *
; * Limitations:    none
; *
; ***************************************************************************/
    IMPORT pref_exception

;/****************************************************************************
; *
; * Function:       databort_exception
; *
; * Purpose:        Data abort exception
; *
; * Inputs:         none
; *
; * Outputs:        none
; *
; * Return Values:  none
; *
; * Limitations:    none
; *
; ***************************************************************************/
    IMPORT databort_exception

;/****************************************************************************
; *
; * Function:       fiq_exception
; *
; * Purpose:        Data abort exception
; *
; * Inputs:         none
; *
; * Outputs:        none
; *
; * Return Values:  none
; *
; * Limitations:    none
; *
; ***************************************************************************/
    IMPORT fiq_exception

;/****************************************************************************/

    END

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

