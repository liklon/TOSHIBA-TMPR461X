/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference SBI (I2C) Low Level Device Driver IO
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Serial Bus Interface (SBI) / I2C
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef IIC_IO_H
#define IIC_IO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"                      /* Core specific primitive type definitions */
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 230    /* Rule 6.4 [R] : nonstandard type for a bit field */
  #pragma ghs nowarning 1840   /* Rule 5.7 [A] : identifier reused from declaration of entity-kind "entity" */
#endif

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_IIC_IO_H_REVISION     "$Revision: 1.8 $"
#define LLDD_IIC_IO_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/


/****************************************************************************/

typedef uint8_t u8SBI0CR1_byte_view;        /* BYTE access */
                                            
typedef struct                              /* BIT access */
{ 
    uint8_t SCK :3;                         /* bit(s) r/w */
    uint8_t     :1;                         /* bit(s) ro */
    uint8_t ACK :1;                         /* bit(s) r/w */
    uint8_t BC  :3;                         /* bit(s) wo */
} SBI0CR1_bit_view_st;

/* pointer to byte access */
#define pu8SBI0CR1                          ((volatile u8SBI0CR1_byte_view *) (0xC0324000U))
 /* pointer to bit-access */                
#define pst_bitSBI0CR1                      ((volatile SBI0CR1_bit_view_st *) (0xC0324000U))

/*
   Shadow technique is manually generated code. IIC module requires shadowing 
   of the SBI0CR1 register which is partially write only. Several specific 
   definitons is required to implement shadowing successfully.
*/

/* Register-shadow function read/write operation */
typedef enum tag_iic_io_RegSetGet_e
{
    IIC_IO_SET = 0x0,                       /* Set register access */
    IIC_IO_GET = 0x1                        /* Get register access */
} iic_io_RegSetGet_e;

/* Default register value for shadow technique */
#define IIC_IO_SBI0CR1_DEFAULT              (0x09)

/* Mask covering all bits in the register */
#define IIC_IO_SBI0CR1_ALL_BITS             (0xFF)

/*
   Definitions per shadowed bit or group of bits, e.g. BC are 3 bits 
   (0x07 = b'111 mask) shifted by 5 (bits 7, 6 & 5 in SBI0CR1)
*/
#define IIC_IO_SBI0CR1_BC_SHIFT             (5)
#define IIC_IO_SBI0CR1_BC_BITS              (0x07)
#define IIC_IO_SBI0CR1_ACK_SHIFT            (4)
#define IIC_IO_SBI0CR1_ACK_BITS             (0x01)
#define IIC_IO_SBI0CR1_SCK_SHIFT            (0)
#define IIC_IO_SBI0CR1_SCK_BITS             (0x07)

/****************************************************************************/


/****************************************************************************
 *
 * Function:      IIC_IO_ShadowSBI0CR1
 *
 * Purpose:       Shadow service for SBI0CR1 register
 *
 * Inputs:        eRegSetGet  operation to be performed on the register:
 *
 * Outputs:       none
 *
 * Return Values: If IIC_IO_SET was a parameter then it retuns current value
 *                of the register
 *                If IIC_IO_GET was a parameter then it retuns current value
 *                of bits to be get
 * Limitations:   none
 *
 ***************************************************************************/
static uint8_t IIC_IO_ShadowSBI0CR1(iic_io_RegSetGet_e eRegSetGet, uint8_t u8AllSubBits,
                                    uint8_t u8NewSubBits, uint8_t u8BitsShift)
{
    static u8SBI0CR1_byte_view u8ShadowCrOne = IIC_IO_SBI0CR1_DEFAULT;
    u8SBI0CR1_byte_view u8RetVal = 0;
    
    /* Prepare clear mask */
    u8AllSubBits = u8AllSubBits << u8BitsShift;
    /* Prepare set maks */
    u8NewSubBits = u8NewSubBits << u8BitsShift;
    
    if( IIC_IO_SET == eRegSetGet )
    {
        /*
           Clear all bits belonging to the group
           Set bits to be changed
           Perform real register update
           Update the return value
         */
        u8ShadowCrOne = (u8ShadowCrOne & ~u8AllSubBits);
        u8ShadowCrOne = u8ShadowCrOne | (u8NewSubBits);
        *pu8SBI0CR1 = u8ShadowCrOne;
        u8RetVal = u8ShadowCrOne;
    }
    else
    {
        /* In this case return only interesting bits */
        u8RetVal = (u8ShadowCrOne & u8AllSubBits) >> u8BitsShift;
    }
    return u8RetVal;
}

/* Default value write macro */
#define vSetSBI0CR1_DEFAULT()               (IIC_IO_ShadowSBI0CR1(IIC_IO_SET, IIC_IO_SBI0CR1_ALL_BITS,\
                                             IIC_IO_SBI0CR1_DEFAULT, 0))

/* Shadowed register set BC bits macro */
#define vSetSBI0CR1_BC(ParValue)            (IIC_IO_ShadowSBI0CR1(IIC_IO_SET, IIC_IO_SBI0CR1_BC_BITS,\
                                            (ParValue), IIC_IO_SBI0CR1_BC_SHIFT))

/* Shadowed register get BC bits macro */
#define biGetSBI0CR1_BC()                   (IIC_IO_ShadowSBI0CR1(IIC_IO_GET, IIC_IO_SBI0CR1_BC_BITS,\
                                             0, IIC_IO_SBI0CR1_BC_SHIFT))

/* Shadowed register set ACK bits macro */
#define vSetSBI0CR1_ACK(ParValue)           (IIC_IO_ShadowSBI0CR1(IIC_IO_SET, IIC_IO_SBI0CR1_ACK_BITS,\
                                            (ParValue), IIC_IO_SBI0CR1_ACK_SHIFT))

/* Shadowed register get ACK bits macro */
#define biGetSBI0CR1_ACK()                  (IIC_IO_ShadowSBI0CR1(IIC_IO_GET, IIC_IO_SBI0CR1_ACK_BITS,\
                                             0, IIC_IO_SBI0CR1_ACK_SHIFT))

/* Shadowed register set SCK bits macro */
#define vSetSBI0CR1_SCK(ParValue)           (IIC_IO_ShadowSBI0CR1(IIC_IO_SET, IIC_IO_SBI0CR1_SCK_BITS,\
                                            (ParValue), IIC_IO_SBI0CR1_SCK_SHIFT))

/* Shadowed register get SCK bits macro */
#define biGetSBI0CR1_SCK()                  (IIC_IO_ShadowSBI0CR1(IIC_IO_GET, IIC_IO_SBI0CR1_SCK_BITS,\
                                             0, IIC_IO_SBI0CR1_SCK_SHIFT))
/* Byte write */
#define vSetSBI0CR1(ParValue)               (IIC_IO_ShadowSBI0CR1(IIC_IO_SET, IIC_IO_SBI0CR1_ALL_BITS,\
                                            (ParValue), 0))

/* Byte read */
#define u8GetSBI0CR1()                      (IIC_IO_ShadowSBI0CR1(IIC_IO_GET, IIC_IO_SBI0CR1_ALL_BITS,\
                                             0, 0))

/****************************************************************************/


typedef uint8_t u8SBI0DBR_byte_view;        /* BYTE access */

typedef struct                              /* BIT access */
{ 
    uint8_t DB :8;                          /* bit(s) r/w */
} SBI0DBR_bit_view_st;

/* pointer to byte access */
#define pu8SBI0DBR                          ((volatile u8SBI0DBR_byte_view *) (0xC0324004U))

/* pointer to bit-access */
#define pst_bitSBI0DBR                      ((volatile SBI0DBR_bit_view_st *) (0xC0324004U))

/* bit access */
#define vSetSBI0DBR_DB(ParValue)            (pst_bitSBI0DBR->DB=(ParValue))
#define biGetSBI0DBR_DB()                   (pst_bitSBI0DBR->DB)

/* byte access */                           
#define vSetSBI0DBR(ParValue)               (*pu8SBI0DBR = (ParValue))
#define u8GetSBI0DBR()                      (*pu8SBI0DBR)

/****************************************************************************/


typedef uint8_t u8SBI0AR_byte_view;         /* BYTE access */

typedef struct                              /* BIT access */
{ 
    uint8_t ALS :1;                         /* bit(s) wo */
    uint8_t SA  :7;                         /* bit(s) wo */
} SBI0AR_bit_view_st;

/* pointer to byte access - reg wo, all bits */
#define pu8SBI0AR                           ((volatile u8SBI0AR_byte_view *) (0xC0324008U))
/* pointer to bit-access - reg wo, all bits */
#define pst_bitSBI0AR                       ((volatile SBI0AR_bit_view_st *) (0xC0324008U))

/* 
   Shadow technique is manually generated code. IIC module requires
   shadowing of the SBI0AR register which is write only
*/

/* Default register value for shadow technique */
#define IIC_IO_SBI0AR_DEFAULT               (0x00)

/* Mask covering all bits in the register */
#define IIC_IO_SBI0AR_ALL_BITS              (0xFF)

/* Definitions of shadowed bit or groups of bits */
#define IIC_IO_SBI0AR_ALS_SHIFT             (0)
#define IIC_IO_SBI0AR_ALS_BITS              (0x01)
#define IIC_IO_SBI0AR_SA_SHIFT              (1)
#define IIC_IO_SBI0AR_SA_BITS               ((0xFE ) >> 1 )

/****************************************************************************/


/****************************************************************************
 *
 * Function:      IIC_IO_ShadowSBI0AR
 *
 * Purpose:       Shadow service for SBI0AR register
 *
 * Inputs:        eRegSetGet   Operation to be performed on the register
 *
 * Outputs:       none
 *
 * Return Values: If IIC_IO_SET was a parameter then it retuns current value
 *                of the register
 *                If IIC_IO_GET was a parameter then it retuns current value
 *                of bits to be get
 * Limitations:   none
 *
 ***************************************************************************/
static uint8_t IIC_IO_ShadowSBI0AR(iic_io_RegSetGet_e eRegSetGet, uint8_t u8AllSubBits,
                                   uint8_t u8NewSubBits, uint8_t u8BitsShift)
{
    static u8SBI0AR_byte_view u8ShadowAr = IIC_IO_SBI0AR_DEFAULT;
    u8SBI0AR_byte_view u8RetVal = 0;
    
    /* Prepare clear mask */
    u8AllSubBits = u8AllSubBits << u8BitsShift;
    /* Prepare Set mask */
    u8NewSubBits = u8NewSubBits << u8BitsShift;
    
    if( IIC_IO_SET == eRegSetGet )
    {
        /*
            Clear all bits belonging to the group
            Set bits to be changed
            Perform real register update
            Update the return value
         */
        u8ShadowAr = (u8ShadowAr & ~u8AllSubBits);
        u8ShadowAr = u8ShadowAr | (u8NewSubBits);
        *pu8SBI0AR = u8ShadowAr;
        u8RetVal = u8ShadowAr;
    }
    else
    {
        /* In this case return only the bits of interest */
        u8RetVal = (u8ShadowAr & u8AllSubBits) >> u8BitsShift;
    }
    return u8RetVal;
}

/* Default value write macro */
#define vSetSBI0AR_DEFAULT()                (IIC_IO_ShadowSBI0AR(IIC_IO_SET, IIC_IO_SBI0AR_ALL_BITS,\
                                             IIC_IO_SBI0AR_DEFAULT, 0))

/* Shadowed register set ALS bit macro */
#define vSetSBI0AR_ALS(ParValue)            (IIC_IO_ShadowSBI0AR(IIC_IO_SET, IIC_IO_SBI0AR_ALS_BITS,\
                                            (ParValue), IIC_IO_SBI0AR_ALS_SHIFT))

/* Shadowed register get ALS bit macro */
#define biGetSBI0AR_ALS()                   (IIC_IO_ShadowSBI0AR(IIC_IO_GET, IIC_IO_SBI0AR_ALS_BITS,\
                                             0, IIC_IO_SBI0AR_ALS_SHIFT))

/* Shadowed register set SA bits macro */
#define vSetSBI0AR_SA(ParValue)             (IIC_IO_ShadowSBI0AR(IIC_IO_SET, IIC_IO_SBI0AR_SA_BITS,\
                                            (ParValue), IIC_IO_SBI0AR_SA_SHIFT))

/* Shadowed register get SA bits macro */
#define biGetSBI0AR_SA()                    (IIC_IO_ShadowSBI0AR(IIC_IO_GET, IIC_IO_SBI0AR_SA_BITS,\
                                             0, IIC_IO_SBI0AR_SA_SHIFT))

/* Macro for byte write */
#define vSetSBI0AR(ParValue)                (IIC_IO_ShadowSBI0AR(IIC_IO_SET, IIC_IO_SBI0AR_ALL_BITS, (ParValue), 0))

/* Macro for byte read */
#define u8GetSBI0AR()                       (IIC_IO_ShadowSBI0AR(IIC_IO_GET, IIC_IO_SBI0AR_ALL_BITS, 0, 0))

/****************************************************************************/


typedef uint8_t u8SBI0CR2_byte_view;        /* BYTE access */

typedef struct                              /* BIT access */
{ 
    uint8_t SWRST :2;                       /* bit(s) wo */
    uint8_t SBIM  :2;                       /* bit(s) wo */
    uint8_t PIN   :1;                       /* bit(s) wo */
    uint8_t BB    :1;                       /* bit(s) wo */
    uint8_t TRX   :1;                       /* bit(s) wo */
    uint8_t MST   :1;                       /* bit(s) wo */
} SBI0CR2_bit_view_st;

/* pointer to byte access - reg wo, all bits */
#define pu8SBI0CR2                          ((volatile u8SBI0CR2_byte_view *) (0xC032400CU))
/* pointer to bit-access - reg wo, all bits */
#define pst_bitSBI0CR2                      ((volatile SBI0CR2_bit_view_st *) (0xC032400CU))

/* bit access */
#define vSetSBI0CR2_SWRST(ParValue)         (pst_bitSBI0CR2->SWRST=(ParValue))
#define vSetSBI0CR2_SBIM(ParValue)          (pst_bitSBI0CR2->SBIM=(ParValue))
#define vSetSBI0CR2_PIN(ParValue)           (pst_bitSBI0CR2->PIN=(ParValue))
#define vSetSBI0CR2_BB(ParValue)            (pst_bitSBI0CR2->BB=(ParValue))
#define vSetSBI0CR2_TRX(ParValue)           (pst_bitSBI0CR2->TRX=(ParValue))
#define vSetSBI0CR2_MST(ParValue)           (pst_bitSBI0CR2->MST=(ParValue))
                                            
/* byte access */                           
#define vSetSBI0CR2(ParValue)               (*pu8SBI0CR2 = (ParValue))

/****************************************************************************/


typedef uint8_t u8SBI0SR_byte_view;         /* BYTE access */
                                            
typedef struct                              /* BIT access */
{ 
    uint8_t LRB :1;                         /* bit(s) ro */
    uint8_t AD0 :1;                         /* bit(s) ro */
    uint8_t AAS :1;                         /* bit(s) ro */
    uint8_t AL  :1;                         /* bit(s) ro */
    uint8_t PIN :1;                         /* bit(s) ro */
    uint8_t BB  :1;                         /* bit(s) ro */
    uint8_t TRX :1;                         /* bit(s) ro */
    uint8_t MST :1;                         /* bit(s) ro */
} SBI0SR_bit_view_st;

/* pointer to byte access - reg ro, all bits */
#define pu8SBI0SR                           ((volatile u8SBI0SR_byte_view *) (0xC032400CU))
/* pointer to bit-access - reg ro, all bits */
#define pst_bitSBI0SR                       ((volatile SBI0SR_bit_view_st *) (0xC032400CU))

/* bit access */
#define biGetSBI0SR_LRB()                   (pst_bitSBI0SR->LRB)
#define biGetSBI0SR_AD0()                   (pst_bitSBI0SR->AD0)
#define biGetSBI0SR_AAS()                   (pst_bitSBI0SR->AAS)
#define biGetSBI0SR_AL()                    (pst_bitSBI0SR->AL)
#define biGetSBI0SR_PIN()                   (pst_bitSBI0SR->PIN)
#define biGetSBI0SR_BB()                    (pst_bitSBI0SR->BB)
#define biGetSBI0SR_TRX()                   (pst_bitSBI0SR->TRX)
#define biGetSBI0SR_MST()                   (pst_bitSBI0SR->MST)
                                            
/* byte access */                           
#define u8GetSBI0SR()                       (*pu8SBI0SR)

/****************************************************************************/
/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 230 / 6.4 - bitwise operation may not be performed on signed integer types
** | CONS.  : allow
** | REASON : to use macros generated by converter tool 
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/    


#endif /* IIC_IO_H */

/****************************************************************************/


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
  conditions set forth in the “Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (“Unintended Usage).
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

