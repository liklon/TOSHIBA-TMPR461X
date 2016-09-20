/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference Interrupt Controller (INTC) Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Interrupt Controller (INTC)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.18 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "core.h"
#include "intc_io.h"                        /* INTC registers, bits and access macros defintion */
#include "intc.h"                           /* INTC definitions */

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1849    /* Rule 10.5 [R] : bitwise ~ or << expression must be immediately cast back to  underlying type, "unsigned char" */
  
  #pragma ghs nowarning 1864    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1865    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1866    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1867    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1868    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */

  #pragma ghs nowarning 1847    /* Rule 10.3 [R] :  Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1848    /* Rule 10.3 [R] :  Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1879    /* Rule 10.3 [R] :  Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1880    /* Rule 10.3 [R] :  Restrict explicit casts for integer type expressions */

  #pragma ghs nowarning 1834    /* Rule 11.3 [A] : disable casting error (used for result of i/o header amcros) */
  #pragma ghs nowarning 1840    /* Rule 5.7  [A] : identifier reused from declaration of entity-kind "entity" */
  

#endif /* defined(__GHS__) || defined(__ghs__) */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_INTC_C_REVISION     "$Revision: 1.18 $"
#define LLDD_INTC_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*             Constants & Macros              *
**********************************************/

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_INTC_C_REVISION[]    = LLDD_INTC_C_REVISION;
static uint8_t au8LLDD_INTC_C_TAG[]         = LLDD_INTC_C_TAG;
static uint8_t au8LLDD_INTC_H_REVISION[]    = LLDD_INTC_H_REVISION;
static uint8_t au8LLDD_INTC_H_TAG[]         = LLDD_INTC_H_TAG;
static uint8_t au8LLDD_INTC_IO_H_REVISION[] = LLDD_INTC_IO_H_REVISION;
static uint8_t au8LLDD_INTC_IO_H_TAG[]      = LLDD_INTC_IO_H_TAG;

#define IR_ACRL_SHIFT   7
#define IR_EIMR_SHIFT   5
#define IR_DRS_SHIFT    4

/*********************************************/

/**********************************************
*        Exported function definition         *
**********************************************/

void vINTC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_INTC_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_INTC_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_INTC_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_INTC_H_TAG[0];
   *pau8IORevision     = &au8LLDD_INTC_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_INTC_IO_H_TAG[0];
}


/****************************************************************************/

void vSetIR_ByIndex(uint8_t u8SrcIx, uint8_t u8Value_write)
{
    uint16_t u16RegIx;
    uint16_t u16FieldOffs;
    uint32_t u32RegValue;
    uint32_t u32RegValueNew;
    uint32_t u32RegMask[4] = {0xFFFFFF00U, 0xFFFF00FFU, 0xFF00FFFFU, 0x00FFFFFFU};

    /* find out which channel and which field (0..3) in related register */
    u16RegIx     = u8SrcIx >> 2;
    u16FieldOffs = u8SrcIx % 4;
    
    /* read register */
    u32RegValue = u32GetIR(u16RegIx);
    /* mask related bits */
    u32RegValue &= u32RegMask[u16FieldOffs];
    
    /* build 32 bit new value: */
    u32RegValueNew = (uint32_t)u8Value_write;
    u32RegValueNew <<= (8*u16FieldOffs);    
    u32RegValueNew |= u32RegValue;
    
    /* write back value in register: */
    vSetIR(u16RegIx, u32RegValueNew);
}


/****************************************************************************/

void vSetIR_EXT_ByIndex(uint8_t u8SrcIx, uint8_t u8EXT)
{
    uint16_t u16RegIx;
    uint16_t u16FieldOffs;

    /* find out which channel and which field (0..3) in related register */
    u16RegIx     = ((uint16_t) u8SrcIx) >> 2;
    u16FieldOffs = u8SrcIx % 4;
    
    switch ( u16FieldOffs )
    {
        case 0:
            vSetIR_EXT0(u16RegIx, u8EXT);
            break;

        case 1:
            vSetIR_EXT1(u16RegIx, u8EXT);
            break;

        case 2:
            vSetIR_EXT2(u16RegIx, u8EXT);
            break;

        default:
            vSetIR_EXT3(u16RegIx, u8EXT);
            break;
    }
    
    return;
}


/****************************************************************************/

void vSetIR_DRS_ByIndex(uint8_t u8SrcIx, uint8_t u8DRS)
{
    uint16_t u16RegIx;
    uint16_t u16FieldOffs;

    /* find out which channel and which field (0..3) in related register */
    u16RegIx     = ((uint16_t) u8SrcIx) >> 2;
    u16FieldOffs = u8SrcIx % 4;
    
    switch ( u16FieldOffs )
    {
        case 0:
            vSetIR_DRS0(u16RegIx, u8DRS);
            break;

        case 1:
            vSetIR_DRS1(u16RegIx, u8DRS);
            break;

        case 2:
            vSetIR_DRS2(u16RegIx, u8DRS);
            break;

        default:
            vSetIR_DRS3(u16RegIx, u8DRS);
            break;
    }
    
    return;
}


/****************************************************************************/

void vSetIR_ACLR_ByIndex(uint8_t u8SrcIx, uint8_t u8ACLR)
{
    uint16_t u16RegIx;
    uint16_t u16FieldOffs;

    /* find out which channel and which field (0..3) in related register */
    u16RegIx     = ((uint16_t) u8SrcIx) >> 2;
    u16FieldOffs = u8SrcIx % 4;
    
    switch ( u16FieldOffs )
    {
        case 0:
            vSetIR_ACLR0(u16RegIx, u8ACLR);
            break;

        case 1:
            vSetIR_ACLR1(u16RegIx, u8ACLR);
            break;

        case 2:
            vSetIR_ACLR2(u16RegIx, u8ACLR);
            break;

        default:
            vSetIR_ACLR3(u16RegIx, u8ACLR);
            break;
    }
    
    return;
}


/****************************************************************************/

void vSetIR_EIM_ByIndex(uint8_t u8SrcIx, uint8_t u8EIM)
{
    uint16_t u16RegIx;
    uint16_t u16FieldOffs;

    /* find out which channel and which field (0..3) in related register */
    u16RegIx     = u8SrcIx >> 2;
    u16FieldOffs = u8SrcIx % 4;
    
    switch ( u16FieldOffs )
    {
        case 0:
            vSetIR_EIM0(u16RegIx, u8EIM);
            break;

        case 1:
            vSetIR_EIM1(u16RegIx, u8EIM);
            break;

        case 2:
            vSetIR_EIM2(u16RegIx, u8EIM);
            break;

        default:
            vSetIR_EIM3(u16RegIx, u8EIM);
            break;
    }
    
    return;
}


/****************************************************************************/

int32_t i32INTC_SourceConfig(intc_src_e eSrc, intc_drs_e eDst, intc_eim_e eMode, intc_ext_e eLevel, intc_aclr_e eAutoClear)
{
    int32_t     i32Res = C_SUCCESS;
    uint8_t     u8SrcIx;
    intc_eim_e  eSrcEim;
    uint8_t     u8Value_write;
    uint8_t     u8EIM_write, u8DRS_write, u8EXT_write, u8ACLR_write;


    u8SrcIx = (uint8_t)INTC_GET_ROFST(eSrc);

    /* Check the requested source */
    if( u8SrcIx > LAST_SRC_INDEX )
    {
        /* Invalid source */
        i32Res = C_FAILED;
    }
    else
    {
        /* check valid parameters: */
        if( (eMode < INTC_NA) && (eLevel <= INTC_LEVEL_7) && (eAutoClear <= INTC_AUTO_CLEAR_ENABLE) && (eDst <= INTC_TO_DMA))
        {
            /* get source mode: */
            eSrcEim = (intc_eim_e) INTC_GET_MODE(eSrc);

            /* Default mode was requested */
            if( INTC_RM_DEFAULT == eMode )
            {
                /* Is there a valid default mode for this source */
                if( INTC_NA == eSrcEim )
                {
                    /* No default mode available, e.g. external interrupt source */
                    i32Res = C_FAILED;
                }
                else
                {
                    /* Use default recognition mode*/
                    u8EIM_write = (uint8_t) eSrcEim;
                }
            }
            else
            {
                /* Use given recognition mode */
                u8EIM_write = (uint8_t) eMode;
            }

            if( C_SUCCESS == i32Res )
            {
                /* Destination set */
                u8DRS_write = (uint8_t) eDst;

                /* IRQ Level/DMA channel */
                u8EXT_write = (uint8_t) eLevel;

                /* Set Auto clear */
                u8ACLR_write = (uint8_t) eAutoClear;
            }
        }
        else
        {
            /* Invalid source */
            i32Res = C_FAILED;
        }
    }

    if( C_SUCCESS == i32Res )
    {

#if defined(__GHS__) || defined(__ghs__)

  /* disable MISRA 2004 Rule 10.5 because for satisfaction this rule violation of rule 10.3 is required */
  #pragma ghs nowarning 1849

#endif
        u8Value_write =  (u8ACLR_write << IR_ACRL_SHIFT) |(u8EIM_write<< IR_EIMR_SHIFT) | (u8DRS_write << IR_DRS_SHIFT) | (u8EXT_write);

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

        vSetIR_ByIndex(u8SrcIx, u8Value_write);
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32INTC_SetEIM_ByIndex(uint8_t u8SrcIx, intc_eim_e eMode)
{
    int32_t  i32Res = C_SUCCESS;

    /* Check the requested source */
    if( (u8SrcIx > LAST_SRC_INDEX) || (eMode>INTC_EDGE_RISE) )
    {
        /* Invalid source */
        i32Res = C_FAILED;
    }
    else
    {
        vSetIR_EIM_ByIndex(u8SrcIx, (uint8_t) eMode);
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32INTC_SetDrsByIndex(uint8_t u8SrcIx, intc_drs_e eDst)
{
    int32_t  i32Res = C_SUCCESS;

    /* Check the requested source */
    if( (u8SrcIx > LAST_SRC_INDEX) || (eDst > INTC_TO_DMA) )
    {
        /* Invalid source */
        i32Res = C_FAILED;
    }
    else
    {
        vSetIR_DRS_ByIndex(u8SrcIx, (uint8_t) eDst);
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32INTC_SetExtByIndex(uint8_t u8SrcIx, intc_ext_e eLevel)
{
    int32_t  i32Res = C_SUCCESS;

    /* Check the requested source */
    if( (u8SrcIx > LAST_SRC_INDEX) || (eLevel > INTC_LEVEL_7) )
    {
        /* Invalid source */
        i32Res = C_FAILED;
    }
    else
    {
        vSetIR_EXT_ByIndex(u8SrcIx, (uint8_t) eLevel);
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32INTC_SetAclrByIndex(uint8_t u8SrcIx, intc_aclr_e eAutoClear)
{
    int32_t  i32Res = C_SUCCESS;

    /* Check the requested source */
    if( (u8SrcIx > LAST_SRC_INDEX) || (eAutoClear > INTC_AUTO_CLEAR_ENABLE) )
    {
        /* Invalid source */
        i32Res = C_FAILED;
    }
    else
    {
        vSetIR_ACLR_ByIndex(u8SrcIx, (uint8_t) eAutoClear);
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32INTC_SetVectBaseAddr(uint32_t u32Addr)
{
    int32_t i32Res = C_SUCCESS;

    /* Check if address is aligned */
    if( 0U == (u32Addr & INT_VECTOR_MASK) )
    {
        vSetIVR( (uint32_t)u32Addr );
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

uint32_t u32INTC_GetVectAddr(void)
{
    return u32GetIVR();
}


/****************************************************************************/

void vINTC_ModifyIrqLevel(intc_ilev_e eMode, intc_ext_e eLevel)
{
    uint32_t u32ILEV;

    if(eMode == INTC_RESTORE_OLD)
    {
        /* To restore the old level we have to write 0 to the ILEV register */
        vSetILEV(0U);
    }
    else
    {
        /* Adjust the MLEV bit */
        u32ILEV = ((uint32_t)eMode << 31);
        /* Update CMASK */
        u32ILEV = u32ILEV | ((uint32_t)eLevel & 0x07U);
        vSetILEV(u32ILEV);
    }
}


/****************************************************************************/

int32_t i32INTC_ClearIrq(uint32_t u32Voffset)
{
    int32_t i32Res = C_SUCCESS;

    /* Check if the offset is in range */
    if( (u32Voffset & INT_VECTOR_MASK) <= INTC_GET_VOFST(INTC_WAKEUP) )
    {
        vSetICLR((uint32_t) (u32Voffset & INT_VECTOR_MASK));
        /*
         *  Ensure that the interrupt is really cleared before
         *  returning. ARM data barrier replaces the MIPS "sync"
         */
        __DSB();
    }
    else
    {
        /* Offset out of range */
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

void vINTC_ClearDmaReq(intc_irst_e eReqCh)
{
    /* Clear the requested channel */
    switch ( eReqCh )
    {
        case INTC_DMA_CH0:
            vClrIRST_RDR0();
            break;

        case INTC_DMA_CH1:
            vClrIRST_RDR1();
            break;

        case INTC_DMA_CH2:
            vClrIRST_RDR2();
            break;

        case INTC_DMA_CH3:
            vClrIRST_RDR3();
            break;

        case INTC_DMA_CH4:
            vClrIRST_RDR4();
            break;

        case INTC_DMA_CH5:
            vClrIRST_RDR5();
            break;

        case INTC_DMA_CH6:
            vClrIRST_RDR6();
            break;

        case INTC_DMA_CH7:
            vClrIRST_RDR7();
            break;

        case INTC_DMA_CH_ALL:

        default:
            /* Clear all requests */
            vSetIRST(INTC_DMA_CH_ALL);
            break;
    }
}


/****************************************************************************/

void vINTC_BlockVectUpdate(void)
{
    /*
     *  Write access to IBLK prevents IVR from being updated
     *  until a write access to ICLR is performed
     */
    vSetIBLK(0);
}


/****************************************************************************/

uint8_t u8INTC_GetIrqLevel(intc_level_e eLevel)
{
    uint32_t u32IrqLevel;

    switch( eLevel )
    {
        case INTC_PREV0:
            u32IrqLevel = biGetILEV_PMASK0();
            break;

        case INTC_PREV1:
            u32IrqLevel = biGetILEV_PMASK1();
            break;

        case INTC_PREV2:
            u32IrqLevel = biGetILEV_PMASK2();
            break;

        case INTC_PREV3:
            u32IrqLevel = biGetILEV_PMASK3();
            break;

        case INTC_PREV4:
            u32IrqLevel = biGetILEV_PMASK4();
            break;

        case INTC_PREV5:
            u32IrqLevel = biGetILEV_PMASK5();
            break;

        case INTC_CURRENT:

        default:
            /* Current IRQ Level */
            u32IrqLevel = biGetILEV_CMASK();
            break;
    }

    return (uint8_t)u32IrqLevel;
}


/****************************************************************************/

uint32_t u32INTC_GetIrqStatus(intc_src_e eSrc)
{
    uint32_t u32IntNumber, u32IRREST, u32BitNumber, u32Ret;

    /* Get the vector offset of the interrupt source */
    u32IntNumber = INTC_GET_VOFST(eSrc);

    /* Calculate the interrupt number [vector offset divided by 4] */
    u32IntNumber = u32IntNumber >> 2;

    /* Find out the status register [IRREST] to be used (divide by 32) */
    u32IRREST = (u32IntNumber >> 5) + 1;

    /* Calculate the corresponding bit number */
    u32BitNumber = u32IntNumber - (32 * (u32IRREST - 1));

    /* Retrieve the entire status register */
    switch( u32IRREST )
    {
        case 1:
            u32Ret = u32GetIRREST0();
            break;

        case 2:
            u32Ret = u32GetIRREST1();
            break;

        case 3:
            u32Ret = u32GetIRREST2();
            break;

        case 4:
            u32Ret = u32GetIRREST3();
            break;

        case 5:
            u32Ret = u32GetIRREST4();
            break;

        case 6:
            u32Ret = u32GetIRREST5();
            break;

        /* On not existing source simply return not pending */
        default:
            u32Ret = 0;
            break;
    }

    /* mask out the corresponding bit */
    u32Ret = u32Ret << ( 31 - u32BitNumber);
    u32Ret = u32Ret >> 31;

    return u32Ret;
}


/****************************************************************************/

void vINTC_EnableInterrupts(intc_enable_e eEnable)
{
    vSetIWPERR_IWPNTEN(eEnable);
}


/****************************************************************************/

intc_enable_e eINTC_GetEnabled( void )
{
    intc_enable_e eEnable;

    if (0 < biGetIWPERR_IWPNTEN())
    {
        eEnable = INTC_ENABLE;
    }
    else
    {
        eEnable = INTC_DISABLE;
    }
    return eEnable;

}


/****************************************************************************/

void vINTC_ClearInterrupt(void)
{
    vSetIWPERR_IWPINTCLR(0x1);
}


/****************************************************************************/

void vINTC_SetISRStartAddress(intc_src_e eSrc, uint32_t u32Address)
{
    vSetISRADDR(INTC_GET_ROFST(eSrc), u32Address);
}


/****************************************************************************/

uint32_t u32INTC_GetISRStartAddress(intc_src_e eSrc)
{
    return u32GetISRADDR(INTC_GET_ROFST(eSrc));
}

#if defined(__GHS__) || defined(__ghs__)
/* enable warnings for Misra 10.1 & 10.3 */
#pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: gdc.c
**  $Revision: 1.18 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 1849 / 10.5 - bitwise ~ or << expression must be immediately cast 
** |                       back to  underlying type, "unsigned char" 
** | CONS.  : allow
** | REASON : We shift 8 bit value but saved before as 16 bit. So with shift by 2
** |          no data will be lost.
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/


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

