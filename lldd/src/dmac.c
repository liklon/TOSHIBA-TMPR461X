/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : DMAC low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : DMAC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.16 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "dmac_io.h"                   /* DMAC registers, bits and access macros defintion */
#include "dmac.h"                      /* Own definitions */

/*********************************************
*         Disable Misra Warnings/Rules       *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1723    /* Rule 5.6 [A] :  No identifiers with the same name in different name spaces except 
                                                   for struct and union members                                           */
  #pragma ghs nowarning 1834    /* Rule 11.3 [A] : No casting between pointer and integral types                          */
  #pragma ghs nowarning 1853    /* Rule 12.6 [A] : Operands of logical operators must be Boolean, and Boolean expressions 
                                                   may not be used as operands of other operators                         */
  #pragma ghs nowarning 1855    /* Rule 13.2 [A] : Explicit test of a value against zero unless the expression is Boolean */
  #pragma ghs nowarning 1864    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1865    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1866    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1867    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1868    /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */

  #pragma ghs nowarning 1847    /* Rule 10.3 [R] : 	Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1848    /* Rule 10.3 [R] : 	Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1879    /* Rule 10.3 [R] : 	Restrict explicit casts for integer type expressions */

#endif /* defined(__GHS__) || defined(__ghs__) */


/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_DMAC_C_REVISION     "$Revision: 1.16 $"
#define LLDD_DMAC_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/


/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_DMAC_C_REVISION[]    = LLDD_DMAC_C_REVISION;
static uint8_t au8LLDD_DMAC_C_TAG[]         = LLDD_DMAC_C_TAG;
static uint8_t au8LLDD_DMAC_H_REVISION[]    = LLDD_DMAC_H_REVISION;
static uint8_t au8LLDD_DMAC_H_TAG[]         = LLDD_DMAC_H_TAG;
static uint8_t au8LLDD_DMAC_IO_H_REVISION[] = LLDD_DMAC_IO_H_REVISION;
static uint8_t au8LLDD_DMAC_IO_H_TAG[]      = LLDD_DMAC_IO_H_TAG;

/*********************************************/


/**********************************************
*              Global variables               *
**********************************************/
static uint8_t u8ChannelMask[8] = {0x01U,
                            0x02U,
                            0x04U,
                            0x08U,
                            0x10U,
                            0x20U,
                            0x40U,
                            0x80U};

/*********************************************/


/**********************************************
*             Function definition             *
**********************************************/

void vDMAC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_DMAC_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_DMAC_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_DMAC_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_DMAC_H_TAG[0];
   *pau8IORevision     = &au8LLDD_DMAC_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_DMAC_IO_H_TAG[0];
}


/****************************************************************************/

uint8_t u8DMAC_GetInterruptStatusAll(void)
{
    return ( (uint8_t)biGetDMACIntStatus_IntStatus() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetInterruptStatus(dmac_channel_e eDMAChannel)
{
    uint8_t u8Status;
    dmac_enable_e eDmacStatus;


    u8Status = (uint8_t)biGetDMACIntStatus_IntStatus();
    u8Status = u8Status & u8ChannelMask[eDMAChannel];
    if (u8Status > 0U)
    {
        eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}


/****************************************************************************/

uint8_t u8DMAC_GetInterruptTCStatusAll(void)
{
    return ( (uint8_t)biGetDMACIntTCStatus_IntTCStatus() ); 
}


/****************************************************************************/

dmac_enable_e eDMAC_GetInterruptTCStatus(dmac_channel_e eDMAChannel)
{
    uint8_t u8Status;
    dmac_enable_e eDmacStatus;

    u8Status = (uint8_t)biGetDMACIntTCStatus_IntTCStatus();
    u8Status = u8Status & u8ChannelMask[eDMAChannel];
    if (u8Status > 0U)
    {
        eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;

}


/****************************************************************************/

void vDMAC_ClearInterruptTCStatusAll(void)
{
    vSetDMACIntTCClear(0xFFU);
}


/****************************************************************************/

void vDMAC_ClearInterruptTCStatus(dmac_channel_e eDMAChannel)
{
    vSetDMACIntTCClear(u8ChannelMask[eDMAChannel]);
}


/****************************************************************************/

uint8_t u8DMAC_GetInterruptErrorStatusAll(void)
{
    return ( (uint8_t)biGetDMACIntErrorStatus_IntErrorStatus() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetInterruptErrorStatus(dmac_channel_e eDMAChannel)
{
    uint8_t u8Status;
    dmac_enable_e eDmacStatus;

    u8Status = (uint8_t)biGetDMACIntErrorStatus_IntErrorStatus();
    u8Status = u8Status & u8ChannelMask[eDMAChannel];
    if (u8Status > 0U)
    {
        eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}


/****************************************************************************/

void vDMAC_ClearInterruptErrorAll(void)
{
    vSetDMACIntErrClr(0xFFU);
}


/****************************************************************************/

void vDMAC_ClearInterruptError(dmac_channel_e eDMAChannel)
{
    vSetDMACIntErrClr(u8ChannelMask[eDMAChannel]);
}


/****************************************************************************/

uint8_t u8DMAC_GetRawInterruptTCStatusAll(void)
{
    return ( (uint8_t)biGetDMACRawIntTCStatus_RawIntTCStatus() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetRawInterruptTCStatus(dmac_channel_e eDMAChannel)
{
    uint8_t u8Status;
    dmac_enable_e eDmacStatus;

    u8Status = (uint8_t)biGetDMACRawIntTCStatus_RawIntTCStatus();
    u8Status = u8Status & u8ChannelMask[eDMAChannel];
    if (u8Status > 0U)
    {
        eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}


/****************************************************************************/

uint8_t u8DMAC_GetRawInterruptErrorStatusAll(void)
{
    return ( (uint8_t)biGetDMACRawIntErrorStatus_RawIntErrorStatus() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetRawInterruptErrorStatus(dmac_channel_e eDMAChannel)
{
    uint8_t u8Status;
    dmac_enable_e eDmacStatus;

    u8Status = (uint8_t)biGetDMACRawIntErrorStatus_RawIntErrorStatus();
    u8Status = u8Status & u8ChannelMask[eDMAChannel];
    if (u8Status > 0U)
    {
        eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;

}


/****************************************************************************/

uint8_t u8DMAC_GetEnabledChannelAll(void)
{
    return ( (uint8_t)biGetDMACEnbldChns_EnabledChannels() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetEnabledChannel(dmac_channel_e eDMAChannel)
{
    uint8_t u8Status;
    dmac_enable_e eDmacStatus;

    u8Status = (uint8_t)biGetDMACEnbldChns_EnabledChannels();
    u8Status = u8Status & u8ChannelMask[eDMAChannel];
    if (u8Status > 0U)
    {
         eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}

/****************************************************************************/

dmac_enable_e eDMAC_GetEnabled( void )
{
    dmac_enable_e eEnable;

    if ( biGetDMACConfig_E () )
    {
        eEnable = DMAC_ENABLE;
    }
    else
    {
        eEnable = DMAC_DISABLE;
    }
    return eEnable;
}

/****************************************************************************/

void vDMAC_EnableSoftwareBurstRequestAll(uint16_t u16Value)
{
    vSetDMACSoftBReq(u16Value);
}


/****************************************************************************/

void vDMAC_EnableSoftwareBurstRequest(dmac_request_e eDMARequest)
{
    vSetDMACSoftBReq_SoftBReq((uint32_t)eDMARequest);
}


/****************************************************************************/

uint16_t u16DMAC_GetEnabledSoftwareBurstRequestAll(void)
{
    return ( (uint16_t)biGetDMACSoftBReq_SoftBReq() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetEnabledSoftwareBurstRequest(dmac_request_e eDMARequest)
{
    uint16_t u16Request;
    dmac_enable_e eDmacStatus;

    u16Request = (uint16_t)biGetDMACSoftBReq_SoftBReq();
    u16Request = u16Request & (uint16_t)eDMARequest;
    if (u16Request > 0U)
    {
        eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}


/****************************************************************************/

void vDMAC_EnableSoftwareSingleRequestAll(uint16_t u16Value)
{
    vSetDMACSoftSReq_SoftSReq(u16Value);
}


/****************************************************************************/

void vDMAC_EnableSoftwareSingleRequest(dmac_request_e eDMARequest)
{
    vSetDMACSoftSReq_SoftSReq((uint16_t)eDMARequest);
}


/****************************************************************************/

uint16_t u16DMAC_GetEnabledSoftwareSingleRequestAll(void)
{
    return ( (uint16_t)biGetDMACSoftSReq_SoftSReq() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetEnabledSoftwareSingleRequest(dmac_request_e eDMARequest)
{
    uint16_t u16Request;
    dmac_enable_e eDmacStatus;

    u16Request = (uint16_t)biGetDMACSoftSReq_SoftSReq();
    u16Request = u16Request & (uint16_t)eDMARequest;
    if (u16Request > 0U)
    {
         eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}


/****************************************************************************/

void vDMAC_EnableSoftwareLastBurstRequestAll(uint16_t u16Value)
{
    vSetDMACSoftLBReq_SoftLBReq(u16Value);
}


/****************************************************************************/

void vDMAC_EnableSoftwareLastBurstRequest(dmac_request_e eDMARequest)
{
    vSetDMACSoftLBReq_SoftLBReq((uint16_t)eDMARequest);
}


/****************************************************************************/

uint16_t u16DMAC_GetEnabledSoftwareLastBurstRequestAll(void)
{
    return ( (uint16_t)biGetDMACSoftLBReq_SoftLBReq() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetEnabledSoftwareLastBurstRequest(dmac_request_e eDMARequest)
{
    uint16_t u16Request;
    dmac_enable_e eDmacStatus;

    u16Request = (uint16_t)biGetDMACSoftLBReq_SoftLBReq();
    u16Request = u16Request & (uint16_t)eDMARequest;
    if (u16Request > 0U)
    {
        eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}


/****************************************************************************/

void vDMAC_EnableSoftwareLastSingleRequestAll(uint16_t u16Value)
{
    vSetDMACSoftLSReq_SoftLSReq(u16Value);
}


/****************************************************************************/

void vDMAC_EnableSoftwareLastSingleRequest(dmac_request_e eDMARequest)
{
    vSetDMACSoftLSReq_SoftLSReq((uint16_t)eDMARequest);
}


/****************************************************************************/

uint16_t u16DMAC_GetEnabledSoftwareLastSingleRequestAll(void)
{
    return ( (uint16_t)biGetDMACSoftLSReq_SoftLSReq() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetEnabledSoftwareLastSingleRequest(dmac_request_e eDMARequest)
{
    uint16_t u16Request;
    dmac_enable_e eDmacStatus;

    u16Request = (uint16_t)biGetDMACSoftLSReq_SoftLSReq();
    u16Request = u16Request & (uint16_t)eDMARequest;
    if (u16Request > 0U)
    {
         eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}


/****************************************************************************/

void vDMAC_Enable(dmac_enable_e eEnable)
{
    uint8_t u8Channel;
    uint8_t u8Mask = 0x1U;
    uint8_t u8Loop;

    if (eEnable == DMAC_ENABLE)
    {
        vSetDMACConfig_E((uint32_t)DMAC_ENABLE);
    }
    else
    {
        for (u8Loop=0; u8Loop < 8U; u8Loop++)
        {
            /* read if a DMA channel is enabled */
            u8Channel = ((uint8_t)biGetDMACEnbldChns_EnabledChannels()) & u8Mask;

            if (u8Channel != 0U)
            {
                /* halt channel */
                vSetDMACC0Config_H(u8Loop, DMAC_DISABLE);

                /* poll till channel is halted */
                while (1U == (uint32_t) biGetDMACC0Config_A(u8Loop))
                {
                    ;
                }

                /* disable channel */
                vSetDMACC0Config_E(u8Loop, DMAC_DISABLE);
            }

            u8Mask = (uint8_t)(u8Mask << 1);
        }

        vSetDMACConfig_E((uint32_t)DMAC_DISABLE);
    }
}


/****************************************************************************/

void vDMAC_EnableSynchronisationAll(uint16_t u16Value)
{
    vSetDMACSync(u16Value);
}


/****************************************************************************/

void vDMAC_EnableSynchronisation(dmac_request_e eDMARequest)
{
    vSetDMACSync((uint16_t)eDMARequest);
}


/****************************************************************************/

uint16_t u16DMAC_GetSynchronisationAll(void)
{
    return ( (uint16_t)biGetDMACSync_DMACSync() );
}


/****************************************************************************/

dmac_enable_e eDMAC_GetSynchronisation(dmac_request_e eDMARequest)
{
    uint16_t u16Sync;
    dmac_enable_e eDmacStatus;

    u16Sync = (uint16_t)biGetDMACSync_DMACSync();
    u16Sync = u16Sync & (uint16_t)eDMARequest;
    if (u16Sync > 0U)
    {
        eDmacStatus = DMAC_ENABLE;
    }
    else
    {
        eDmacStatus = DMAC_DISABLE;
    }
    return eDmacStatus;
}


/****************************************************************************/

void vDMAC_SetSourceAddress(dmac_channel_e eDMAChannel, uint32_t u32Address)
{
    vSetDMACC0SrcAddr(eDMAChannel, u32Address);
}


/****************************************************************************/

uint32_t u32DMAC_GetSourceAddress(dmac_channel_e eDMAChannel)
{
    return u32GetDMACC0SrcAddr(eDMAChannel);
}


/****************************************************************************/

void vDMAC_SetDestinationAddress(dmac_channel_e eDMAChannel, uint32_t u32Address)
{
    vSetDMACC0DestAddr(eDMAChannel, u32Address);
}


/****************************************************************************/

uint32_t u32DMAC_GetDestinationAddress(dmac_channel_e eDMAChannel)
{
    return u32GetDMACC0DestAddr(eDMAChannel);
}


/****************************************************************************/

void vDMAC_SetLinkListItem(dmac_channel_e eDMAChannel, dmac_linklistitem_st * stLinkListItem)
{
    vSetDMACC0LLI_LM(eDMAChannel, stLinkListItem->eAHBMasterSelect);
    vSetDMACC0LLI_LLI(eDMAChannel, (stLinkListItem->u32LLIAddress>>2));
}


/****************************************************************************/

void vDMAC_GetLinkListItem(dmac_channel_e eDMAChannel, dmac_linklistitem_st * stLinkListItem)
{
    stLinkListItem->eAHBMasterSelect = (dmac_AHB_master_sel_e)biGetDMACC0LLI_LM(eDMAChannel);
    stLinkListItem->u32LLIAddress    = (uint32_t)biGetDMACC0LLI_LLI(eDMAChannel);
}


/****************************************************************************/

void vDMAC_SetControl(dmac_channel_e eDMAChannel, dmac_control_st * stControl)
{
    vSetDMACC0Control_I(eDMAChannel, stControl->eTCInterruptEnable);
    vSetDMACC0Control_Prot(eDMAChannel, stControl->u8Protection);
    vSetDMACC0Control_DI(eDMAChannel, stControl->eDstInc);
    vSetDMACC0Control_SI(eDMAChannel, stControl->eSourceInc);
    vSetDMACC0Control_D(eDMAChannel, stControl->eDstAHBMasterSelect);
    vSetDMACC0Control_S(eDMAChannel, stControl->eSourceAHBMasterSelect);
    vSetDMACC0Control_DWidth(eDMAChannel, stControl->eDstTransferWidth);
    vSetDMACC0Control_SWidth(eDMAChannel, stControl->eSourceTransferWidth);
    vSetDMACC0Control_DBSize(eDMAChannel, stControl->eDstBurstLength);
    vSetDMACC0Control_SBSize(eDMAChannel, stControl->eSourceBurstLength);
    vSetDMACC0Control_TransferSize(eDMAChannel, stControl->u16TransferSize);
}


/****************************************************************************/

void vDMAC_SetTransferSize(dmac_channel_e eDMAChannel, uint16_t u16TransferSize)
{
    vSetDMACC0Control_TransferSize(eDMAChannel, u16TransferSize);
}


/****************************************************************************/

uint32_t u32DMAC_GenerateControlValue(dmac_control_st * stControl)
{
    uint32_t u32Value;

    u32Value = (((uint32_t) (stControl->eTCInterruptEnable)<<31));

    u32Value = (((uint32_t)stControl->eTCInterruptEnable)<<31) + ((uint32_t)(stControl->u8Protection)<<28) + (((uint32_t)stControl->eDstInc)<<27) + (((uint32_t)stControl->eSourceInc)<<26) +
               ((uint32_t)(stControl->eDstAHBMasterSelect) <<25) + (((uint32_t)stControl->eSourceAHBMasterSelect)<<24) + (((uint32_t)stControl->eDstTransferWidth)<<21) +
               ((uint32_t)(stControl->eSourceTransferWidth)<<18) + ((uint32_t)(stControl->eDstBurstLength)<<15) + (((uint32_t)stControl->eSourceBurstLength)<<12) + stControl->u16TransferSize;

    return u32Value;
}


/****************************************************************************/

bool_t boDMAC_GetControl(dmac_channel_e eDMAChannel, dmac_control_st * stControl)
{
    bool_t  boResult = C_FALSE;
    uint8_t u8Channel;
    
    /* read if related DMA channel is enabled */
    u8Channel = ((uint8_t)biGetDMACEnbldChns_EnabledChannels()) & u8ChannelMask[eDMAChannel];
    /* register data can be read only if channel is disabled: */
    if (u8Channel == 0U)
    {
        stControl->u16TransferSize        = (uint16_t)biGetDMACC0Control_TransferSize(eDMAChannel);
        stControl->eSourceBurstLength     = (dmac_burst_length_e)biGetDMACC0Control_SBSize(eDMAChannel);
        stControl->eDstBurstLength        = (dmac_burst_length_e)biGetDMACC0Control_DBSize(eDMAChannel);
        stControl->eSourceTransferWidth   = (dmac_transfer_width_e)biGetDMACC0Control_SWidth(eDMAChannel);
        stControl->eDstTransferWidth      = (dmac_transfer_width_e)biGetDMACC0Control_DWidth(eDMAChannel);
        stControl->eSourceAHBMasterSelect = (dmac_AHB_master_sel_e)biGetDMACC0Control_S(eDMAChannel);
        stControl->eDstAHBMasterSelect    = (dmac_AHB_master_sel_e)biGetDMACC0Control_D(eDMAChannel);
        stControl->eSourceInc             = (dmac_address_inc_e)biGetDMACC0Control_SI(eDMAChannel);
        stControl->eDstInc                = (dmac_address_inc_e)biGetDMACC0Control_DI(eDMAChannel);
        stControl->u8Protection           = (uint8_t)biGetDMACC0Control_Prot(eDMAChannel);
        stControl->eTCInterruptEnable     = (dmac_enable_e)biGetDMACC0Control_I(eDMAChannel);
        
        boResult = C_TRUE;
    }
    return boResult;
}


/****************************************************************************/

void vDMAC_SetConfiguration(dmac_channel_e eDMAChannel, dmac_config_st * stConfiguration)
{
    vSetDMACC0Config_SrcPeripherala(eDMAChannel, stConfiguration->u8SourcePeripheral);
    vSetDMACC0Config_DestPeripherala(eDMAChannel, stConfiguration->u8DstPeripheral);
    vSetDMACC0Config_FlowCntrl(eDMAChannel, stConfiguration->eFlowControl);
    vSetDMACC0Config_IE(eDMAChannel, stConfiguration->eMaskErrorInterrupt);
    vSetDMACC0Config_ITC(eDMAChannel, stConfiguration->eMaskTCInterrupt);
    vSetDMACC0Config_L(eDMAChannel, stConfiguration->eLockedTransfer);
    vSetDMACC0Config_H(eDMAChannel, stConfiguration->eHalt);
}


/****************************************************************************/

uint32_t u32DMAC_GenerateConfigurationValue(dmac_config_st * stConfiguration)
{
    uint32_t u32Value;

    u32Value = (((uint32_t)stConfiguration->eHalt)<<18) + (((uint32_t)stConfiguration->eActive)<<17) + (((uint32_t)stConfiguration->eLockedTransfer)<<16) +
               ((uint32_t)(stConfiguration->eMaskTCInterrupt)<<15) + ((uint32_t)(stConfiguration->eMaskErrorInterrupt)<<14) + ((uint32_t)(stConfiguration->eFlowControl)<<11) +
               ((uint32_t)(stConfiguration->u8DstPeripheral)<<6) + ((uint32_t)(stConfiguration->u8SourcePeripheral)<<1);

    return u32Value;
}


/****************************************************************************/

void vDMAC_GetConfiguration(dmac_channel_e eDMAChannel, dmac_config_st * stConfiguration)
{
    stConfiguration->u8SourcePeripheral  = (uint8_t)biGetDMACC0Config_SrcPeripherala(eDMAChannel);
    stConfiguration->u8DstPeripheral     = (uint8_t)biGetDMACC0Config_DestPeripherala(eDMAChannel);
    stConfiguration->eFlowControl        = (dmac_flow_control_e)biGetDMACC0Config_FlowCntrl(eDMAChannel);
    stConfiguration->eMaskErrorInterrupt = (dmac_enable_e)biGetDMACC0Config_IE(eDMAChannel);
    stConfiguration->eMaskTCInterrupt    = (dmac_enable_e)biGetDMACC0Config_ITC(eDMAChannel);
    stConfiguration->eLockedTransfer     = (dmac_enable_e)biGetDMACC0Config_L(eDMAChannel);
    stConfiguration->eActive             = (dmac_enable_e)biGetDMACC0Config_A(eDMAChannel);
    stConfiguration->eHalt               = (dmac_enable_e)biGetDMACC0Config_H(eDMAChannel);
}


/****************************************************************************/

void vDMAC_HoldChannel(dmac_channel_e eDMAChannel, dmac_halt_e eHalt)
{
    vSetDMACC0Config_H(eDMAChannel, eHalt);
}


/****************************************************************************/

void vDMAC_StartTransfer(dmac_channel_e eDMAChannel)
{
    vSetDMACC0Config_E(eDMAChannel, 0x1);
}

/****************************************************************************/

void vDMAC_StopTransfer(dmac_channel_e eDMAChannel)
{
    vSetDMACC0Config_E(eDMAChannel, 0x0);
}

/****************************************************************************/

dmac_enable_e eDMACTransferStarted(dmac_channel_e eDMAChannel)
{
    return (dmac_enable_e)biGetDMACC0Config_E(eDMAChannel);
}

#if defined(__GHS__) || defined(__ghs__)
/* enable warnings for Misra 10.1 & 10.3 */
#pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

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

