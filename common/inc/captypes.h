/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Standard core definitions
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Capricorn standard C types
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.6 $
*   DATE        : $Date: 2015/05/04 09:07:19 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef CAPTYPES_H
#define CAPTYPES_H

/**********************************************
*                Include files                *
**********************************************/

/*********************************************/


/**********************************************
*                Definitions                  *
**********************************************/
/* Simple error codes */
#define C_SUCCESS                           (0)
#define C_FAILED                            (-1)

/* Simple boolean value */
#define C_FALSE                             (0)
#define C_TRUE                              (1)

/* NULL pointer definition */
#define C_NULL                              ((void*)0)

/* NULL pointer definition */
#define TYPES_NULL_PTR   ((void *)0UL)

/*********************************************/


/**********************************************
*            Primitive data types             *
**********************************************/

/*
 *  MISRA-C & ELDEC MPU/MCU software coding
 *  guideline compliant type definitions
 */
typedef signed char int8_t;                 /* 1 byte,  prefix i8 */
typedef signed short int16_t;               /* 2 bytes, prefix i16 */
typedef signed int int32_t;                 /* 4 bytes, prefix i32 */
typedef signed long long int64_t;           /* 8 bytes, prefix i64 */
typedef unsigned char uint8_t;              /* 1 byte,  prefix u8 */
typedef unsigned short uint16_t;            /* 2 bytes, prefix u16 */
typedef unsigned int uint32_t;              /* 4 bytes, prefix u32 */
typedef unsigned long long uint64_t;        /* 8 bytes, prefix u64 */
typedef int bool_t;                         /* 4 bytes, prefix bo */
typedef float float32_t;                    /* 4 bytes, prefix f32 */
typedef double float64_t;                   /* 8 bytes, prefix f64 */

/*********************************************/
/*
 Definition for Cortex R4 32-bit memory/registers */
#define TYPES_REG32 (volatile int32_t*)
/*
 Definition for Cortex R4 16-bit memory/registers */
#define TYPES_REG16 (volatile uint16_t*)
/*
 Definition for Cortex R4 8-bit memory/registers */
#define TYPES_REG8 (volatile uint8_t*)


#endif /* CAPTYPES_H */

/***************************************************************************/


/***********************  BEGIN of DISCLAIMER   *****************************

- TOSHIBA is continually working to improve the quality and reliability of
  its products.
  Nevertheless, semiconductor devices in general can malfunction or fail
  due to their inherent electrical sensitivity and vulnerability to physical
  stress. It is the responsibility of the buyer, when utilizing TOSHIBA
  products, to comply with the standards of safety in making a safe design
  for the entire system, and to avoid situations in which a malfunction or
  failure of such TOSHIBA products could cause loss of human life,
  bodily injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications. Also, please keep in mind the precautions and
  conditions set forth in the Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer’s own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit,business interruption, loss of business
  information,and other pecuniary losses) occurring from the use of,
  or inability to use, this product.

- The products described in this document are subject to the foreign exchange
  and foreign trade laws.

- The products described in this document contain components made in the
  United States and subject to export control of the U.S. authorities.
  Diversion contrary to the U.S. law is prohibited.

- The information contained herein is presented only as a guide for the
  applications of our products.
  No responsibility is assumed by TOSHIBA CORPORATION for any infringements
  of intellectual property or other rights of the third parties which may
  result from its use.
  No license is granted by implication or otherwise under any intellectual
  property or other rights of TOSHIBA CORPORATION or others.

- The information contained herein is subject to change without notice.

****************************  END of DISCLAIMER ****************************/

