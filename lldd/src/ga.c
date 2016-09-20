/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Graphic Accelerator
*                 Reference Low-Level Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphic Accelerator
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.20 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/*======================================
            Include Files
=======================================*/
#include "ga.h"
#include "ga_io.h"
#include "stdlib.h"
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1730  /* Rule 12.7 [R] : bitwise operation may not be performed on signed integer types */
  #pragma ghs nowarning 1752  /* Rule 17.4 [R] : pointer arithmetic not allowed */
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1858  /* Rule 17.4 [R] : subscript operator may only be applied to objects declared as an array type */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to narrower underlying type, "type", not allowed */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : conversion from underlying type, "int", to same width underlying type, "uint32_t", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1879  /* Rule 10.3 [R] :  cast of complex integer expression with underlying type "type" to same width type "type" not allowed */

  #pragma ghs nowarning 1737  /* Rule 12.1 [A] : expression may not depend on operator precedence rules */
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1855  /* Rule 13.2 [A] : Explicit test of a value against zero unless the expression is Boolean */

#endif


/*======================================
    Stat. Var and Func. Prototypes
=======================================*/

/*======================================
    Glob. Var and Func. Prototypes
=======================================*/

/*======================================
                Macros
=======================================*/

#define LLDD_GA_C_REVISION     "$Revision: 1.20 $"
#define LLDD_GA_C_TAG          "$Name: LLDD_1_7_GFX $"


#define GA_PROT_REGION_MASK  0xFFF
#define GA_IRQ_CLR_ALL       0xFFFFFFFDU
/*======================================
 Static variables and forward declarations
=======================================*/

static uint8_t au8LLDD_GA_C_REVISION[]          = LLDD_GA_C_REVISION;
static uint8_t au8LLDD_GA_C_TAG[]               = LLDD_GA_C_TAG;
static uint8_t au8LLDD_GA_H_REVISION[]          = LLDD_GA_H_REVISION;
static uint8_t au8LLDD_GA_H_TAG[]               = LLDD_GA_H_TAG;
static uint8_t au8LLDD_GA_COMMON_H_REVISION[]   = LLDD_GA_COMMON_H_REVISION;
static uint8_t au8LLDD_GA_COMMON_H_TAG[]        = LLDD_GA_COMMON_H_TAG;
static uint8_t au8LLDD_GA_IO_H_REVISION[]       = LLDD_GA_IO_H_REVISION;
static uint8_t au8LLDD_GA_IO_H_TAG[]            = LLDD_GA_IO_H_TAG;

static uint32_t u32MaxUsedBuffSize = 0U;

/*======================================
          Function definitions
=======================================*/

void vGA_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                    uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                    uint8_t** pau8CommonRevision, uint8_t** pau8CommonTag,
                    uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
     *pau8ModuleRevision = &au8LLDD_GA_C_REVISION[0];
     *pau8ModuleTag      = &au8LLDD_GA_C_TAG[0];
     *pau8HeaderRevision = &au8LLDD_GA_H_REVISION[0];
     *pau8HeaderTag      = &au8LLDD_GA_H_TAG[0];
     *pau8CommonRevision = &au8LLDD_GA_COMMON_H_REVISION[0];
     *pau8CommonTag      = &au8LLDD_GA_COMMON_H_TAG[0];
     *pau8IORevision     = &au8LLDD_GA_IO_H_REVISION[0];
     *pau8IOTag          = &au8LLDD_GA_IO_H_TAG[0];
}

/* ....................................................................... */
void vGA_ResetMaxUsedBuffSize(void)
{
     u32MaxUsedBuffSize = 0U;
}
/* ....................................................................... */
uint32_t u32GA_GetMaxUsedBuffSize(void)
{
     return u32MaxUsedBuffSize;
}
/* ....................................................................... */
int32_t i32GA_GetLastCmdBuffStatus(ga_list_st* pstCmdList)
{
     return pstCmdList->i32FreeSpaceStat;
}
/* ....................................................................... */
uint32_t u32GA_GetLastCmdSize(ga_list_st* pstCmdList)
{
     return pstCmdList->u32UsedDoubleWords;
}
/* ....................................................................... */
int32_t i32GA_CheckList(ga_list_st* pstCmdList, uint32_t u32NeededDW)
{
    int32_t i32Result;
   /* check if there are enough double words free */
   if ((pstCmdList->pu64Current + u32NeededDW-1) < &pstCmdList->ullCommands[GA_CMD_MAX])
   {
       i32Result = C_SUCCESS;
   }
   else
   {
       i32Result = C_FAILED;
   }
   return (i32Result);
}
/* ....................................................................... */
void vGA_ResetList(ga_list_st* pstCmdList)
{

    pstCmdList->pu64Current = &(pstCmdList->ullCommands[0]);
    pstCmdList->i32FreeSpaceStat   = C_SUCCESS;
    pstCmdList->u32UsedDoubleWords = 0U;

}

/* ....................................................................... */
void vGA_Enable(ga_en_e eEn)
{
    vSetGASCR_GAEN((uint8_t)eEn);
}

/* ....................................................................... */
void vGA_ReadAheadEnable(ga_en_e eEn)
{
    /* NOTE:
     * Disable ReadBuffer Read Ahead feature
     *   0: Read Ahead feature is enabled
     *   1: Read Ahead feature is disabled */
    if (GA_EN == eEn)
    {
        vSetGASCR_DISRA((uint8_t)GA_DIS);
    }
    else
    {
        vSetGASCR_DISRA((uint8_t)GA_EN);
    }
}

/* ....................................................................... */
void vGA_CloseList(ga_list_st* pstCmdList)
{
    uint32_t u32UsedBuffSize;
    uint64_t* pullCurr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW = 1;

    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif


    pullCurr[0] = GA_END();

    pstCmdList->pu64Current = &pullCurr[1];

    
    u32UsedBuffSize = pstCmdList->pu64Current - pstCmdList->ullCommands;
    if (u32UsedBuffSize > u32MaxUsedBuffSize) 
    {
      u32MaxUsedBuffSize = u32UsedBuffSize; 
    }
    pstCmdList->u32UsedDoubleWords = 1;
}

/* ....................................................................... */
void vGA_SyncList(ga_modul_e eModule, ga_list_st* pstCmdList)
{
    uint64_t* pullCurr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */

    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pullCurr[0] = GA_WAIT(eModule);

    pstCmdList->pu64Current = &pullCurr[1];
    pstCmdList->u32UsedDoubleWords = 1;
}

/* ....................................................................... */
void vGA_SetUserInt(uint8_t u8Number, ga_list_st* pstCmdList)
{
    uint64_t* pullCurr = (uint64_t*) pstCmdList->pu64Current;

#ifdef  GA_CMDSLIST_BOUNDARY_CHECK

    uint32_t u32NeededDW = 1;
   
    u32NeededDW += RESERVED_FOR_END_CMD; /* 1 Double word more for later END command */

    /* check if there is enough space in command list: */
    if ( i32GA_CheckList(pstCmdList, u32NeededDW) == C_FAILED)
    {
      pstCmdList->i32FreeSpaceStat = C_FAILED;
      pstCmdList->u32UsedDoubleWords = u32NeededDW;
      return;
    }
    else 
    {
      pstCmdList->i32FreeSpaceStat = C_SUCCESS;
    }
#endif

    pullCurr[0] = GA_USERINTERRUPT(u8Number);

    pstCmdList->pu64Current = &pullCurr[1];
    pstCmdList->u32UsedDoubleWords = 1;
}
/* ....................................................................... */
int32_t i32GA_Reset(void)
{
    int32_t  i32Ret = C_FAILED;
    int32_t  i32TimeOut = GA_TIMEOUT;
    uint32_t u32Res;

    vSetGASCR_GARESET();
    u32Res =  (uint32_t)biGetGASCR_GARESET();

    while((i32TimeOut > 0) && (u32Res == 1))
    {
        i32TimeOut--;
    }

    if(i32TimeOut > 0)
    {
        i32Ret = C_SUCCESS;
    }

    return i32Ret;
}

/* ....................................................................... */
void vGA_SetCmdListAddr(uint32_t u32Addr)
{
    vSetGACLAR(u32Addr);
}

/* ....................................................................... */
uint8_t u8GA_GetStatus(void)
{
    return ((uint8_t) u8GetGASR());
}

/* ....................................................................... */
bool_t boGA_CmdListFinished(void)
{
    bool_t boRes;
    boRes = ( 0x01 == biGetGASR_CSLEF() )? C_TRUE : C_FALSE;
    return (boRes);
}

/* ....................................................................... */
bool_t boGA_CmdListError(void)
{
    bool_t boRes;
    boRes = ( 0x01 == biGetGASR_CSCEF() )? C_TRUE : C_FALSE;
    return (boRes);
}

/* ....................................................................... */
bool_t boGA_CmdReg_IsBusy(void)
{
    bool_t boRes;
    boRes = ( 0x01 == biGetGASR_BUSY() )? C_TRUE : C_FALSE;
    return (boRes);
}

/* ....................................................................... */
uint32_t u32GA_GetIrqCause(void)
{
    uint32_t u32Result;
    
    u32Result = u32GetGAICR();
    
    return u32Result;
}

/* ....................................................................... */
void vGA_ClearIrqCause(uint32_t u32CauseMask)
{
    /* set bit 1 to o, since these bit is Read Only: */
    vSetGAICR(u32CauseMask & GA_IRQ_CLR_ALL);
}

/* ....................................................................... */
void vGA_SetIrqMask(uint32_t u32Mask)
{
  /* set bit 1 to o, since these bit is Read Only: */
    vSetGAIMR(u32Mask & GA_IRQ_CLR_ALL);
}

/* ....................................................................... */
void vGA_EnableUserIrq(uint8_t u8Number, ga_en_e eEn)
{
    uint32_t  u32GAIMR_CSLUIM;
    uint32_t  u32NewVal; 

    /* invalid parameter: */
    if (u8Number <= 23) 
    {
        u32GAIMR_CSLUIM = biGetGAIMR_CSLUIM();  

        u32NewVal = (eEn== GA_EN)? 1<<u8Number : 0;
    
        /* clear bit: */
        u32GAIMR_CSLUIM &= ~(1<<u8Number);
    
        /* modify bit: */
        u32GAIMR_CSLUIM |= u32NewVal;
    
        vSetGAIMR_CSLUIM(u32GAIMR_CSLUIM);
    }
    
    return;
}

/* ....................................................................... */
void vGA_CmdReg_EnableIrqCmdEnd(ga_en_e eEn)
{
    vSetGAIMR_GACENDIM((uint8_t) eEn);
}

/* ....................................................................... */
void vGA_CmdReg_ClearIrqCmdEnd(void)
{
    vClrGAICR_GACENDI();
}

/* ....................................................................... */
void vGA_EnableIrqCSCEI(ga_en_e eEn)
{
    vSetGAIMR_CSCEIM((uint8_t) eEn);
}

/* ....................................................................... */
void vGA_ClearIrqCSCEI(void)
{
    vClrGAICR_CSCEI();
}

/* ....................................................................... */
void vGA_EnableIrqCSLEI(ga_en_e eEn)
{
    vSetGAIMR_CSLEIM((uint8_t) eEn);
}

/* ....................................................................... */
void vGA_ClearIrqCSLEI(void)
{
    vClrGAICR_CSLEI();
}

/* ....................................................................... */
void vGA_SetGADelay(uint16_t u16Delay)
{
    vSetGADR((uint32_t) u16Delay);
}


/*+-----------------------------------------------------------------------+*
 *|     START-Extended new APIs                                           |*
 *+-----------------------------------------------------------------------+*/

/* ....................................................................... */
void vGA_EnableIrqGAWBWI(ga_en_e eEn)
{
    vSetGAIMR_GAWBWIM((uint8_t) eEn);
}

/* ....................................................................... */
void vGA_ClearIrqGAWBWI(void)
{
    vClrGAICR_GAWBWI();
}

/* ....................................................................... */
void vGA_EnableIrqGAWBRI(ga_en_e eEn)
{
    vSetGAIMR_GAWBRIM((uint8_t) eEn);
}
/* ....................................................................... */
void vGA_ClearIrqGAWBRI(void)
{
    vClrGAICR_GAWBRI();
}

/* ....................................................................... */
void vGA_EnableIrqGACBI(ga_en_e eEn)
{
    vSetGAIMR_GACBIM((uint8_t) eEn);
}

/* ....................................................................... */
void vGA_ClearIrqGACBI(void)
{
    vClrGAICR_GACBI();
}

/* ....................................................................... */
void vGA_EnableIrqGARBI(ga_en_e eEn)
{
    vSetGAIMR_GARBIM((uint8_t) eEn);
}

/* ....................................................................... */
void vGA_ClearIrqGARBI(void)
{
    vClrGAICR_GARBI();
}

/* ....................................................................... */
void vGA_ClearUserIrq(uint8_t u8CmdListIntr)

{
    vClrGAICR_CSLUI(u8CmdListIntr);
}

/* ....................................................................... */
bool_t boGA_GetBusErrAddr(ga_bus_type_e eBusType, uint32_t* pu32BusErrAddr)
{
    bool_t boRes = C_TRUE;
    uint32_t u32BusErrAddr;
    
    if(0x00 != pu32BusErrAddr)
    {
        switch( eBusType )
        {
            case GA_READ_BUF_BUS:
                /* GA Read Buffer Bus: */
                u32BusErrAddr = (uint32_t) u32GetGARBBEAR();
                *pu32BusErrAddr = u32BusErrAddr;
                break;
             
            case GA_CACHE_BUF_BUS:
                /* GA Cache Buffer Bus: */
                u32BusErrAddr = (uint32_t) u32GetGACBBEAR();
                *pu32BusErrAddr = u32BusErrAddr;
                break;

            case GA_WRITE_BUF_READ_BUS:
                /* GA Write Buffer Read Bus: */
                u32BusErrAddr = (uint32_t) u32GetGAWBRBEAR();
                *pu32BusErrAddr = u32BusErrAddr;
                break;

            case GA_WRITE_BUF_WRITE_BUS:
                /* GA Write Buffer Write Bus: */
                u32BusErrAddr = (uint32_t) u32GetGAWBWBEAR();
                *pu32BusErrAddr = u32BusErrAddr;
                break;

            default:
                /* Invalid Bus Type */
                boRes = C_FALSE;
                break;
        }      
    }
    else
    {
        boRes = C_FALSE;
    }
    return  boRes;
}

/* ....................................................................... */
bool_t boGA_GetBusErrCtrlStatus(ga_bus_type_e eBusType, ga_bus_err_ctrl_st* pstCtrlStatus)
{
    bool_t boRes = C_TRUE;
    
    if(0x00 != pstCtrlStatus)
    {
        switch( eBusType )
        {
            case GA_READ_BUF_BUS:
                /* GA Read Buffer Bus: */
                pstCtrlStatus->eDirection    = (ga_buserr_dir_e) biGetGARBBECR_WR();
                pstCtrlStatus->eBurstType    = (ga_buserr_bursttype) biGetGARBBECR_BTYPE();
                pstCtrlStatus->eBurstSize    = (ga_buserr_burstsize) biGetGARBBECR_BSIZE();
                pstCtrlStatus->eRespType     = (ga_buserr_resptype) biGetGARBBECR_RTYPE();
                pstCtrlStatus->u8ByteEnables = (uint8_t) biGetGARBBECR_BEN();
                pstCtrlStatus->u8ID          = (uint8_t) biGetGARBBECR_ID();
                pstCtrlStatus->u8BurstLength = (uint8_t) biGetGARBBECR_LEN();
                break;

            case GA_CACHE_BUF_BUS:
                /* GA Cache Buffer Bus: */
                pstCtrlStatus->eDirection    = (ga_buserr_dir_e) biGetGACBBECR_WR();
                pstCtrlStatus->eBurstType    = (ga_buserr_bursttype) biGetGACBBECR_BTYPE();
                pstCtrlStatus->eBurstSize    = (ga_buserr_burstsize) biGetGACBBECR_BSIZE();
                pstCtrlStatus->eRespType     = (ga_buserr_resptype) biGetGACBBECR_RTYPE();
                pstCtrlStatus->u8ByteEnables = (uint8_t) biGetGACBBECR_BEN();
                pstCtrlStatus->u8ID          = (uint8_t) biGetGACBBECR_ID();
                pstCtrlStatus->u8BurstLength = (uint8_t) biGetGACBBECR_LEN();
                break;

            case GA_WRITE_BUF_READ_BUS:
                /* GA Write Buffer Read Bus: */
                pstCtrlStatus->eDirection    = (ga_buserr_dir_e) biGetGAWBRBECR_WR();
                pstCtrlStatus->eBurstType    = (ga_buserr_bursttype) biGetGAWBRBECR_BTYPE();
                pstCtrlStatus->eBurstSize    = (ga_buserr_burstsize) biGetGAWBRBECR_BSIZE();
                pstCtrlStatus->eRespType     = (ga_buserr_resptype) biGetGAWBRBECR_RTYPE();
                pstCtrlStatus->u8ByteEnables = (uint8_t) biGetGAWBRBECR_BEN();
                pstCtrlStatus->u8ID          = (uint8_t) biGetGAWBRBECR_ID();
                pstCtrlStatus->u8BurstLength = (uint8_t) biGetGAWBRBECR_LEN();
                break;

            case GA_WRITE_BUF_WRITE_BUS:
                /* GA Write Buffer Write Bus: */
                pstCtrlStatus->eDirection    = (ga_buserr_dir_e) biGetGAWBWBECR_WR();
                pstCtrlStatus->eBurstType    = (ga_buserr_bursttype) biGetGAWBWBECR_BTYPE();
                pstCtrlStatus->eBurstSize    = (ga_buserr_burstsize) biGetGAWBWBECR_BSIZE();
                pstCtrlStatus->eRespType     = (ga_buserr_resptype) biGetGAWBWBECR_RTYPE();
                pstCtrlStatus->u8ByteEnables = (uint8_t) biGetGAWBWBECR_BEN();
                pstCtrlStatus->u8ID          = (uint8_t) biGetGAWBWBECR_ID();
                pstCtrlStatus->u8BurstLength = (uint8_t) biGetGAWBWBECR_LEN();
                break;

            default:
                /* Invalid Bus Type */
                boRes = C_FALSE;
                break;
        }      
    }
    else
    {
        boRes = C_FALSE;
    }
    return  boRes;
}

/* ....................................................................... */
bool_t boGA_SetMemoryProtRegionAddr(ga_memory_region_e eRegion, uint32_t u32LowAddress, uint32_t u32HighAddress)
{
    bool_t boRes = C_TRUE;
    
     /* Th memory regions are defined with a granularity of 4KB:
        check addresses: */    
    if ( (0x00 ==(u32LowAddress & GA_PROT_REGION_MASK)) && (0xFFF ==(u32HighAddress & GA_PROT_REGION_MASK)) )
    {
        switch( eRegion )
        {
            case GA_MEMORY_PROT_REGION_0:
                /* GA Read Buffer Bus: */
                vSetGAMPR0LR(u32LowAddress);
                vSetGAMPR0HR(u32HighAddress);
                break;
             
            case GA_MEMORY_PROT_REGION_1:
                /* GA Read Buffer Bus: */
                vSetGAMPR1LR(u32LowAddress);
                vSetGAMPR1HR(u32HighAddress);
                break;

            default:
                /* Invalid Bus Type */
                boRes = C_FALSE;
                break;
        }
    }
    else
    {
        boRes = C_FALSE;
    }
    return  boRes;
}

/* ....................................................................... */
void vGA_EnableMemoryProtecConfigIrq(ga_en_e eEn)
{
    vSetGAMPIMR_GAMPCIM((uint8_t) eEn);
}

/* ....................................................................... */
void vGA_EnableMemoryProtecAccessIrq(ga_en_e eEn)
{
    vSetGAMPIMR_GAMPIM((uint8_t) eEn);
}

/* ....................................................................... */
void vGA_ClearMemoryProtecConfigIrq(void)
{
    vClrGAMPICR_GAMPCI();
}

/* ....................................................................... */
void vGA_ClearMemoryProtecAccessIrq(void)
{
    vClrGAMPICR_GAMPI();
}


/* ....................................................................... */
uint32_t u32GA_GetMemoryProtecErr_CaptAddr(void)
{
    uint32_t u32Addr;
    
    u32Addr = u32GetGAMPACR();
    
    return (u32Addr);
}


/* ....................................................................... */
bool_t boGA_SetGeneralPurposeRegister (uint8_t u8RegNo, uint32_t u32RegValue)
{
    bool_t   boRes = C_TRUE;
    uint32_t u32Res;
    
    u32Res = (uint32_t)biGetGASR_BUSY();
    /* check parameters and if GA is not busy: */
    if ( (u8RegNo > 31) || (0x00U != u32Res ) )
    {
        boRes = C_FALSE;
    }
    else
    {
        vSetGAGPR(u8RegNo, u32RegValue);
    }
    return (boRes);
}


/* ....................................................................... */
bool_t boGA_GetGeneralPurposeRegister (uint8_t u8RegNo, uint32_t* pu32RegValue)
{
    bool_t    boRes = C_TRUE;
    uint32_t  u32Value;
    
    /* check parameters: */
    if ( (u8RegNo > 31) || (0x00U == pu32RegValue) )
    {
        boRes = C_FALSE;
    }
    else
    {
        u32Value = u32GetGAGPR(u8RegNo);
        *pu32RegValue = u32Value;
    }
    return (boRes);
}


/* ....................................................................... */
bool_t boGA_SetCommandRegisterLowHigh (uint32_t u32LowValue,  uint32_t u32HighValue)
{
    bool_t boRes = C_TRUE;
    
    /* check if GA is not busy: */
    if (0x00U != biGetGASR_BUSY() )
    {
        boRes = C_FALSE;
    }
    else
    {
        /* it is important to write first the low register!: */
        vSetGACMDL(u32LowValue);
        
        /* then write high register!: */
        vSetGACMDH(u32HighValue);

    }
    return (boRes);
}

/* ....................................................................... */
/*+-----------------------------------------------------------------------+*
 *|     END-Extended new APIs                                             |*
 *+-----------------------------------------------------------------------+*/

/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/

/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: ga.c
**  $Revision: 1.20 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 1730 / 12.7 - bitwise operation may not be performed on signed integer types
** | CONS.  : allow
** | REASON : to generate masks in run time using shift oeprations 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1752 / 17.4 - pointer arithmetic not allowed
** | CONS.  : allow
** | REASON : to increment command list pointer 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1847 / 10.3 - cast of complex integer expression with underlying type
** |                        "type" to non-integer type "type" not allowed 
** | CONS.  : disable
** | REASON : to use macros from i/o header files, unavoidable when addressing 
** |          memory mapped registers 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1858 /17.4  - subscript operator may only be applied to objects 
** |                        declared as an array type
** | CONS.  : allow
** | REASON : to handle array of data by usage of pointer 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1864 /10.1  - implicit conversion from underlying type, "type", 
** |                        to narrower underlying type, "type", not allowed
** | CONS.  : allow
** | REASON : to use macros from i/o header files 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1865 /10.1  -  implicit conversion from underlying type, "type", 
** |                         to same width underlying type, "type", not allowed
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1866 /10.1  -  implicit conversion from underlying type, "type",  
** |                         to underlying type, "type", changes signedness
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1867 /10.1  -  implicit conversion from underlying type, "type", 
** |                         to underlying type, "type", changes signedness
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1879 /10.3  -   cast of complex integer expression with underlying
** |                          type "type" to same width type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as macros in io header file
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

