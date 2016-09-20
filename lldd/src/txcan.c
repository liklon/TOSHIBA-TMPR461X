/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   DESCRIPTION : CAN Low-Level Driver (CAN)
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : CAN Low-Level Driver (CAN)
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "txcan_io.h"
#include "txcan.h"


/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_TXCAN_C_REVISION     "$Revision: 1.10 $"
#define LLDD_TXCAN_C_TAG          "$Name: LLDD_1_6 $"

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_TXCAN_C_REVISION[]    = LLDD_TXCAN_C_REVISION;
static uint8_t au8LLDD_TXCAN_C_TAG[]         = LLDD_TXCAN_C_TAG;
static uint8_t au8LLDD_TXCAN_H_REVISION[]    = LLDD_TXCAN_H_REVISION;
static uint8_t au8LLDD_TXCAN_H_TAG[]         = LLDD_TXCAN_H_TAG;
static uint8_t au8LLDD_TXCAN_IO_H_REVISION[] = LLDD_TXCAN_IO_H_REVISION;
static uint8_t au8LLDD_TXCAN_IO_H_TAG[]      = LLDD_TXCAN_IO_H_TAG;

/**********************************************
*                Variables                    *
**********************************************/
uint32_t u32MBOne[32] = {
  0x00000001,   /* mailbox 0  */
  0x00000002,   /* mailbox 1  */
  0x00000004,   /* mailbox 2  */
  0x00000008,   /* mailbox 3  */
  0x00000010,   /* mailbox 4  */
  0x00000020,   /* mailbox 5  */
  0x00000040,   /* mailbox 6  */
  0x00000080,   /* mailbox 7  */
  0x00000100,   /* mailbox 8  */
  0x00000200,   /* mailbox 9  */
  0x00000400,   /* mailbox 10 */
  0x00000800,   /* mailbox 11 */
  0x00001000,   /* mailbox 12 */
  0x00002000,   /* mailbox 13 */
  0x00004000,   /* mailbox 14 */
  0x00008000,   /* mailbox 15 */
  0x00010000,   /* mailbox 16 */
  0x00020000,   /* mailbox 17 */
  0x00040000,   /* mailbox 18 */
  0x00080000,   /* mailbox 19 */
  0x00100000,   /* mailbox 20 */
  0x00200000,   /* mailbox 21 */
  0x00400000,   /* mailbox 22 */
  0x00800000,   /* mailbox 23 */
  0x01000000,   /* mailbox 24 */
  0x02000000,   /* mailbox 25 */
  0x04000000,   /* mailbox 26 */
  0x08000000,   /* mailbox 27 */
  0x10000000,   /* mailbox 28 */
  0x20000000,   /* mailbox 29 */
  0x40000000,   /* mailbox 30 */
  0x80000000    /* mailbox 31 */
};

/**********************************************
*                 Functions                   *
**********************************************/

void vTXCAN_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                       uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                       uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_TXCAN_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_TXCAN_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_TXCAN_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_TXCAN_H_TAG[0];
   *pau8IORevision     = &au8LLDD_TXCAN_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_TXCAN_IO_H_TAG[0];
}

/****************************************************************************/

void vTXCAN_SetDatalength(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Length)
{
    vSetFTS_MBn_DLC(eCh, eMB, (u8Length & 0x0F));
}

/****************************************************************************/

uint8_t vTXCAN_GetDatalength(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetFTS_MBn_DLC(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_SetRemoteFrameTransmissionRequest(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_RemoteFrameTransmissionRequest_e eRTR)
{
    vSetFTS_MBn_RTR(eCh, eMB, (eRTR & 0x01));
}

/****************************************************************************/

TXCAN_RemoteFrameTransmissionRequest_e eTXCAN_GetRemoteFrameTransmissionRequest(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return (TXCAN_RemoteFrameTransmissionRequest_e)biGetFTS_MBn_RTR(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_SetTimeStampCounterValue(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint16_t u16TSV)
{
    vSetFTS_MBn_TSV(eCh, eMB, (u16TSV & 0x0FFFF));
}

/****************************************************************************/

uint16_t u16TXCAN_GetTimeStampCounterValue(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetFTS_MBn_TSV(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_SetExtID(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint16_t u16ID)
{
    vSetID_MBn_EXT_ID(eCh, eMB, (u16ID & 0x01FFFF));
}

/****************************************************************************/

uint32_t u32TXCAN_GetExtID(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetID_MBn_EXT_ID(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_SetStdID(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint16_t u16ID)
{
    vSetID_MBn_STD_ID(eCh, eMB, (u16ID & 0x07FF));
}

/****************************************************************************/

uint16_t u16TXCAN_GetStdID(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetID_MBn_STD_ID(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_SetRemoteFrameHandling(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_RemoteFrameHandling_e eRFH)
{
    vSetID_MBn_RFH(eCh, eMB, (eRFH & 0x01));
}

/****************************************************************************/

TXCAN_RemoteFrameHandling_e eTXCAN_GetRemoteFrameHandling(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return (TXCAN_RemoteFrameHandling_e)biGetID_MBn_RFH(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_SetGlobalAcceptanceMask(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_GlobalAcceptanceMask_e eGAME)
{
    vSetID_MBn_GAME(eCh, eMB, (eGAME & 0x01));
}

/****************************************************************************/

TXCAN_GlobalAcceptanceMask_e eTXCAN_GetGlobalAcceptanceMask(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return (TXCAN_GlobalAcceptanceMask_e)biGetID_MBn_GAME(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_SetFrameType(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_FrameType_e eIDE)
{
    vSetID_MBn_IDE(eCh, eMB, (eIDE & 0x01));
}

/****************************************************************************/

TXCAN_FrameType_e eTXCAN_GetFrameType(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return (TXCAN_FrameType_e)biGetID_MBn_IDE(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxD0(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data)
{
    vSetDATL_MBn_D0(eCh, eMB, u8Data);
}

/****************************************************************************/

uint8_t u8TXCAN_ReadMailboxD0(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetDATL_MBn_D0(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxD1(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data)
{
    vSetDATL_MBn_D1(eCh, eMB, u8Data);
}

/****************************************************************************/

uint8_t u8TXCAN_ReadMailboxD1(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetDATL_MBn_D1(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxD2(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data)
{
    vSetDATL_MBn_D2(eCh, eMB, u8Data);
}

/****************************************************************************/

uint8_t u8TXCAN_ReadMailboxD2(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetDATL_MBn_D2(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxD3(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data)
{
    vSetDATL_MBn_D3(eCh, eMB, u8Data);
}

/****************************************************************************/

uint8_t u8TXCAN_ReadMailboxD3(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetDATL_MBn_D3(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxD4(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data)
{
    vSetDATH_MBn_D4(eCh, eMB, u8Data);
}

/****************************************************************************/

uint8_t u8TXCAN_ReadMailboxD4(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetDATH_MBn_D4(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxD5(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data)
{
    vSetDATH_MBn_D5(eCh, eMB, u8Data);
}

/****************************************************************************/

uint8_t u8TXCAN_ReadMailboxD5(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetDATH_MBn_D5(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxD6(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data)
{
    vSetDATH_MBn_D6(eCh, eMB, u8Data);
}

/****************************************************************************/

uint8_t u8TXCAN_ReadMailboxD6(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetDATH_MBn_D6(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxD7(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data)
{
    vSetDATH_MBn_D7(eCh, eMB, u8Data);
}

/****************************************************************************/

uint8_t u8TXCAN_ReadMailboxD7(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetDATH_MBn_D7(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxLow(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint32_t u32Data)
{
    vSetDATL_MBn(eCh, eMB, u32Data);
}

/****************************************************************************/

uint32_t u32TXCAN_ReadMailboxLow(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return u32GetDATL_MBn(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailboxHigh(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint32_t u32Data)
{
    vSetDATH_MBn(eCh, eMB, u32Data);
}

/****************************************************************************/

uint32_t u32TXCAN_ReadMailboxHigh(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return u32GetDATH_MBn(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_WriteMailbox(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint64_t u64Data)
{
    vSetDATL_MBn(eCh, eMB, (u64Data & 0xFFFFFFFF));
    vSetDATH_MBn(eCh, eMB, ((u64Data >> 32) & 0xFFFFFFFF));
}

/****************************************************************************/

uint64_t u64TXCAN_ReadMailbox(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint64_t u64Value;
    
    u64Value = u32GetDATH_MBn(eCh, eMB);
    u64Value = u64Value << 32;
    u64Value = u64Value + u32GetDATL_MBn(eCh, eMB);

    return u64Value;
}

/****************************************************************************/

void vTXCAN_MailboxEnableAll(TXCAN_CH_e eCh)
{
    vSetMC(eCh, 0xFFFF);
}

/****************************************************************************/

void vTXCAN_MailboxDisableAll(TXCAN_CH_e eCh)
{
    vSetMC(eCh, 0x0);
}

/****************************************************************************/

void vTXCAN_MailboxEnable(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMC(eCh) | u32MBOne[eMB];
    vSetMC(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_MailboxDisable(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMC(eCh) & ~u32MBOne[eMB];
    vSetMC(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_SetMailboxDirectionAll(TXCAN_CH_e eCh, uint32_t u32DirectionCode)
{
    vSetMD(eCh, u32DirectionCode);
}

/****************************************************************************/

uint32_t u32TXCAN_GetMailboxDirectionAll(TXCAN_CH_e eCh)
{
    return u32GetMD(eCh);
}

/****************************************************************************/

void vTXCAN_SetMailboxDirection(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_MailboxDiretion_e eDirection)
{
    uint32_t u32Value;

    u32Value = u32GetMD(eCh) & ~u32MBOne[eMB];
    if (eDirection == 1)
    {
        u32Value = u32Value | u32MBOne[eMB];
    }

    vSetMD(eCh, u32Value);
}

/****************************************************************************/

TXCAN_MailboxDiretion_e eGetMailboxDirection(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value = 0;
    TXCAN_MailboxDiretion_e eDirection = TXCAN_Output;

    u32Value = u32GetMD(eCh) & u32MBOne[eMB];
    if (u32Value > 0)
    {
        eDirection = TXCAN_Input;
    }

    return eDirection;
}

/****************************************************************************/

void vTXCAN_ConfigureMailbox(TXCAN_MBconfig_st * stMBConfig)
{
    vTXCAN_SetDatalength(stMBConfig->eChannel, stMBConfig->eMailbox, stMBConfig->u8DataLength);
    vTXCAN_SetRemoteFrameTransmissionRequest(stMBConfig->eChannel, stMBConfig->eMailbox, stMBConfig->eRemoteFrameTransmissionRequest);
    vTXCAN_SetTimeStampCounterValue(stMBConfig->eChannel, stMBConfig->eMailbox, 0x0);
    vTXCAN_SetExtID(stMBConfig->eChannel, stMBConfig->eMailbox, stMBConfig->u32ExtendedIdentifier);
    vTXCAN_SetStdID(stMBConfig->eChannel, stMBConfig->eMailbox, stMBConfig->u16StandardIdentifier);
    vTXCAN_SetRemoteFrameHandling(stMBConfig->eChannel, stMBConfig->eMailbox, stMBConfig->eRemoteFrameHandling);
    vTXCAN_SetGlobalAcceptanceMask(stMBConfig->eChannel, stMBConfig->eMailbox, stMBConfig->eGlobalAcceptanceMask);
    vTXCAN_SetFrameType(stMBConfig->eChannel, stMBConfig->eMailbox, stMBConfig->eFrameType);
    vTXCAN_SetMailboxDirection(stMBConfig->eChannel, stMBConfig->eMailbox, stMBConfig->eMailboxDirection);
    vTXCAN_MailboxEnable(stMBConfig->eChannel, stMBConfig->eMailbox);
}

/****************************************************************************/

void vTXCAN_TransmitAll(TXCAN_CH_e eCh, uint32_t u32TransmitCode)
{
    vSetTRS(eCh, u32TransmitCode);
}

/****************************************************************************/

void vTXCAN_Transmit(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMC(eCh) & ~u32MBOne[eMB];
    vSetTRS(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_SendMsg(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint64_t u64Data)
{
    uint32_t u32Value;

    vSetDATL_MBn(eCh, eMB, (u64Data & 0xFFFFFFFF));
    vSetDATH_MBn(eCh, eMB, ((u64Data >> 32) & 0xFFFFFFFF));

    u32Value = u32GetTRS(eCh) | u32MBOne[eMB];
    vSetTRS(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_CancelTransmissionAll(TXCAN_CH_e eCh, uint32_t u32CancelCode)
{
    vSetTRR(eCh, u32CancelCode);
}

/****************************************************************************/

void vTXCAN_CancelTransmission(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetTRR(eCh) | u32MBOne[eMB];
    vSetTRR(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_ClearTransmissionAcknowledgeAll(TXCAN_CH_e eCh, uint32_t u32TransmissionCode)
{
    vSetTA(eCh, u32TransmissionCode);
}

/****************************************************************************/

void vTXCAN_ClearTransmissionAcknowledge(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetTA(eCh) | u32MBOne[eMB];
    vSetTA(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_ClearTransmissionAbortAcknowledgeAll(TXCAN_CH_e eCh, uint32_t u32TransmissionCode)
{
    vSetAA(eCh, u32TransmissionCode);
}

/****************************************************************************/

void vTXCAN_ClearTransmissionAbortAcknowledge(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetAA(eCh) | u32MBOne[eMB];
    vSetAA(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_SetChangeDataRequestAll(TXCAN_CH_e eCh, uint32_t u32Value)
{
    vSetCDR(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_SetChangeDataRequest(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetCDR(eCh) | u32MBOne[eMB];
    vSetCDR(eCh, u32Value);
}

/****************************************************************************/

uint32_t u32TXCAN_GetChangeDataRequestAll(TXCAN_CH_e eCh)
{
    return u32GetCDR(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetChangeDataRequest(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetCDR(eCh) & u32MBOne[eMB];
    if (u32Value == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/****************************************************************************/

uint32_t u32TXCAN_GetPendingReceiveMessages(TXCAN_CH_e eCh)
{
    return u32GetRMP(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetPendingReceiveMessage(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetRMP(eCh) & u32MBOne[eMB];
    if (u32Value == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/****************************************************************************/

void vTXCAN_ClearPendingReceiveMessages(TXCAN_CH_e eCh, uint32_t u32Value)
{
    vSetRMP(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_ClearPendingReceiveMessage(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetRMP(eCh) | u32MBOne[eMB];
    vSetRMP(eCh, u32Value);
}

/****************************************************************************/

uint32_t u32TXCAN_GetReceiveMessageLosts(TXCAN_CH_e eCh)
{
    return u32GetRML(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetReceiveMessageLost(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetRML(eCh) & u32MBOne[eMB];
    if (u32Value == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/****************************************************************************/

void vTXCAN_ClearReceiveMessageLosts(TXCAN_CH_e eCh, uint32_t u32Value)
{
    vSetRML(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_ClearReceiveMessageLost(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetRML(eCh) | u32MBOne[eMB];
    vSetRML(eCh, u32Value);
}

/****************************************************************************/

uint32_t u32TXCAN_GetPendingRemoteFrames(TXCAN_CH_e eCh)
{
    return u32GetRFP(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetPendingRemoteFrame(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetRFP(eCh) & u32MBOne[eMB];
    if (u32Value == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/****************************************************************************/

void vSetAcceptanceMaskType(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_AcceptanceMaskType_e eType)
{
    vSetMBnAM_AMI(eCh, eMB, eType);
}

/****************************************************************************/

TXCAN_AcceptanceMaskType_e eGetAcceptanceMaskType(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return (TXCAN_AcceptanceMaskType_e)biGetMBnAM_AMI(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_SetAcceptanceMask(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint32_t u32Value)
{
    vSetMBnAM_AM(eCh, eMB, u32Value);
}

/****************************************************************************/

uint32_t u32TXCAN_GetAcceptanceMask(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    return biGetMBnAM_AM(eCh, eMB);
}

/****************************************************************************/

void vTXCAN_ConfigureChannel(TXCAN_CH_e eCh, TXCAN_CHconfig_st * stConfig)
{
    vSetMCR_SRES(eCh, stConfig->eSoftwareReset);
    vSetMCR_TSCC(eCh, stConfig->eTimeStampCounter);
    vSetMCR_MTOS(eCh, stConfig->eTransmissionOrder);
    vSetMCR_WUBA(eCh, stConfig->eWakeUp);
    vSetMCR_SMR(eCh, stConfig->eSleepMode);
    vSetMCR_CCR(eCh, stConfig->eChangeConfig);
    vSetMCR_TSTERR(eCh, stConfig->eTestError);
    vSetMCR_TSTLB(eCh, stConfig->eTestLoopback);
    vSetMCR_INTLB(eCh, stConfig->eInternalLoopback);
    vSetMCR_SUR(eCh, stConfig->eSuspendMode);
}

/****************************************************************************/

void vTXCAN_GetChannelConfiguration(TXCAN_CH_e eCh, TXCAN_CHconfig_st * stConfig)
{
    stConfig->eSoftwareReset = (TXCAN_SoftwareReset_e)biGetMCR_SRES(eCh);
    stConfig->eTimeStampCounter = (TXCAN_TimeStampCounter_e)biGetMCR_TSCC(eCh);
    stConfig->eTransmissionOrder = (TXCAN_TransmissionOrder_e)biGetMCR_MTOS(eCh);
    stConfig->eWakeUp = (TXCAN_WakeUpOnBus_e)biGetMCR_WUBA(eCh);
    stConfig->eSleepMode = (TXCAN_Sleep_e)biGetMCR_SMR(eCh);
    stConfig->eChangeConfig = (TXCAN_ChangeConfig_e)biGetMCR_CCR(eCh);
    stConfig->eTestError = (TXCAN_TestError_e)biGetMCR_TSTERR(eCh);
    stConfig->eTestLoopback = (TXCAN_TestLoopback_e)biGetMCR_TSTLB(eCh);
    stConfig->eInternalLoopback = (TXCAN_InternalLoopback_e)biGetMCR_INTLB(eCh);
    stConfig->eSuspendMode = (TXCAN_Suspend_e)biGetMCR_SUR(eCh);
}

/****************************************************************************/

void vTXCAN_ConfigureTiming(TXCAN_CH_e eCh, TXCAN_timing_st * stTiming)
{
    vSetMCR_CCR(eCh, 1);
    vSetBCR1_BRP(eCh, stTiming->u8BaudRatePrescaler);
    vSetBCR2_TSEG1(eCh, stTiming->u8BitTiming1);
    vSetBCR2_TSEG2(eCh, stTiming->u8BitTiming2);
    vSetMCR_CCR(eCh, 0);

    vSetBCR2_SAM(eCh, stTiming->eSamplingType);
    vSetBCR2_SJW(eCh, stTiming->eBitLS);
}

/****************************************************************************/

void vTXCAN_GetTimingConfiguration(TXCAN_CH_e eCh, TXCAN_timing_st * stTiming)
{
    stTiming->u8BaudRatePrescaler = (uint8_t)biGetBCR1_BRP(eCh);
    stTiming->u8BitTiming1 = (uint8_t)biGetBCR2_TSEG1(eCh);
    stTiming->u8BitTiming2 = (uint8_t)biGetBCR2_TSEG2(eCh);
    stTiming->eSamplingType = (TXCAN_Sampling_e)biGetBCR2_SAM(eCh);
    stTiming->eBitLS = (TXCAN_BitLS_e)biGetBCR2_SJW(eCh);
}

/****************************************************************************/

uint16_t u16TXCAN_GetTimeStampCounter(TXCAN_CH_e eCh)
{
    return biGetTSC_TSC(eCh);
}

/****************************************************************************/

void vTXCAN_ClearTimeStampValue(TXCAN_CH_e eCh)
{
    vSetMCR_TSCC(eCh, 1);
}

/****************************************************************************/

void vTXCAN_SetTimeStampCounterPrescaler(TXCAN_CH_e eCh, uint8_t u8Value)
{
    vSetTSP_TSP(eCh, (u8Value & 0xF));
}

/****************************************************************************/

uint8_t u8TXCAN_GetTimeStampCounterPrescaler(TXCAN_CH_e eCh)
{
    return biGetTSP_TSP(eCh);
}

/****************************************************************************/

uint32_t u32TXCAN_GetGlobalStatus(TXCAN_CH_e eCh)
{
    return u32GetGSR(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetWarningStatus(TXCAN_CH_e eCh)
{
    return biGetGSR_EW(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetErrorPassiveStatus(TXCAN_CH_e eCh)
{
    return biGetGSR_EP(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetBusOffStatus(TXCAN_CH_e eCh)
{
    return biGetGSR_BO(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetTimeStampOverflowFlag(TXCAN_CH_e eCh)
{
    return biGetGSR_TSO(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetSleepModeAcknowledge(TXCAN_CH_e eCh)
{
    return biGetGSR_SMA(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetChangeConfigurationEnable(TXCAN_CH_e eCh)
{
    return biGetGSR_CCE(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetSuspendModeAcknowledge(TXCAN_CH_e eCh)
{
    return biGetGSR_SUA(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetTransmitMode(TXCAN_CH_e eCh)
{
    return biGetGSR_TM(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetReceiveMode(TXCAN_CH_e eCh)
{
    return biGetGSR_RM(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetMessageInSlot(TXCAN_CH_e eCh)
{
    return biGetGSR_MIS(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetReceiveErrorCounter(TXCAN_CH_e eCh)
{
    return biGetCEC_REC(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetTransmitErrorCounter(TXCAN_CH_e eCh)
{
    return biGetCEC_TEC(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetGlobalInterruptFlags(TXCAN_CH_e eCh)
{
    return u8GetGIF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearGlobalInterruptFlags(TXCAN_CH_e eCh, uint8_t u8Flags)
{
    vSetGIF(eCh, u8Flags);
}

/****************************************************************************/

uint8_t u8TXCAN_GetWarningLevelInterruptFlag(TXCAN_CH_e eCh)
{
    return biGetGIF_WLIF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearWarningLevelInterruptFlag(TXCAN_CH_e eCh)
{
    vClrGIF_WLIF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetErrorPassiveInterruptFlag(TXCAN_CH_e eCh)
{
    return biGetGIF_EPIF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearErrorPassiveInterruptFlag(TXCAN_CH_e eCh)
{
    vClrGIF_EPIF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetBusOffInterruptFlag(TXCAN_CH_e eCh)
{
    return biGetGIF_BOIF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearBusOffInterruptFlag(TXCAN_CH_e eCh)
{
    vClrGIF_BOIF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetTimeStampCounterOverflowInterruptFlag(TXCAN_CH_e eCh)
{
    return biGetGIF_TSOIF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearTimeStampCounterOverflowInterruptFlag(TXCAN_CH_e eCh)
{
    vClrGIF_TSOIF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetTransmitAbortFlag(TXCAN_CH_e eCh)
{
    return biGetGIF_TRMABF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearTransmitAbortFlag(TXCAN_CH_e eCh)
{
    vClrGIF_TRMABF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetReceiveMessageLostInterruptFlag(TXCAN_CH_e eCh)
{
    return biGetGIF_RMLIF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearReceiveMessageLostInterruptFlag(TXCAN_CH_e eCh)
{
    vClrGIF_RMLIF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetWakeUpInterruptFlag(TXCAN_CH_e eCh)
{
    return biGetGIF_WUIF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearWakeUpInterruptFlag(TXCAN_CH_e eCh)
{
    vClrGIF_WUIF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetRemoteFramePendingFlag(TXCAN_CH_e eCh)
{
    return biGetGIF_RFPF(eCh);
}

/****************************************************************************/

void vTXCAN_ClearRemoteFramePendingFlag(TXCAN_CH_e eCh)
{
    vClrGIF_RFPF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetGlobalInterruptMasks(TXCAN_CH_e eCh)
{
    return u8GetGIM(eCh);
}

/****************************************************************************/

void vTXCAN_SetGlobalInterruptMasks(TXCAN_CH_e eCh, uint8_t u8Masks)
{
    uint8_t u8Value;

    u8Value = u8GetGIM(eCh) | u8Masks;
    vSetGIM(eCh, u8Value);
}

/****************************************************************************/

uint8_t u8TXCAN_GetWarningLevelInterruptMask(TXCAN_CH_e eCh)
{
    return biGetGIM_WLIM(eCh);
}

/****************************************************************************/

void vTXCAN_SetWarningLevelInterruptMask(TXCAN_CH_e eCh)
{
    vSetGIM_WLIM(eCh, 1);
}

/****************************************************************************/

uint8_t u8TXCAN_GetErrorPassiveInterruptMask(TXCAN_CH_e eCh)
{
    return biGetGIM_EPIM(eCh);
}

/****************************************************************************/

void vTXCAN_SetErrorPassiveInterruptMask(TXCAN_CH_e eCh)
{
    vSetGIM_EPIM(eCh, 1);
}

/****************************************************************************/

uint8_t u8TXCAN_GetBusOffInterruptMask(TXCAN_CH_e eCh)
{
    return biGetGIM_BOIM(eCh);
}

/****************************************************************************/

void vTXCAN_SetBusOffInterruptMask(TXCAN_CH_e eCh)
{
    vSetGIM_BOIM(eCh, 1);
}

/****************************************************************************/

uint8_t u8TXCAN_GetTimeStampCounterOverflowInterruptMask(TXCAN_CH_e eCh)
{
    return biGetGIM_TSOIM(eCh);
}

/****************************************************************************/

void vTXCAN_SetTimeStampCounterOverflowInterruptMask(TXCAN_CH_e eCh)
{
    vSetGIM_TSOIM(eCh, 1);
}

/****************************************************************************/

uint8_t u8TXCAN_GetTransmitAbortMask(TXCAN_CH_e eCh)
{
    return biGetGIM_TRMABFM(eCh);
}

/****************************************************************************/

void vTXCAN_SetTransmitAbortMask(TXCAN_CH_e eCh)
{
    vSetGIM_TRMABFM(eCh, 1);
}

/****************************************************************************/

uint8_t u8TXCAN_GetReceiveMessageLostInterruptMask(TXCAN_CH_e eCh)
{
    return biGetGIM_RMLIM(eCh);
}

/****************************************************************************/

void vTXCAN_SetReceiveMessageLostInterruptMask(TXCAN_CH_e eCh)
{
    vSetGIM_RMLIM(eCh, 1);
}

/****************************************************************************/

uint8_t u8TXCAN_GetWakeUpInterruptMask(TXCAN_CH_e eCh)
{
    return biGetGIM_WUIM(eCh);
}

/****************************************************************************/

void vTXCAN_SetWakeUpInterruptMask(TXCAN_CH_e eCh)
{
    vSetGIM_WUIM(eCh, 1);
}

/****************************************************************************/

uint8_t u8TXCAN_GetRemoteFramePendingMask(TXCAN_CH_e eCh)
{
    return biGetGIM_RFPM(eCh);
}

/****************************************************************************/

void vTXCAN_SetRemoteFramePendingMask(TXCAN_CH_e eCh)
{
    vSetGIM_RFPM(eCh, 1);
}

/****************************************************************************/

void vTXCAN_EnableInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMBIM(eCh) | u32MBOne[eMB];
    vSetMBIM(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_DisableInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMBIM(eCh) & ~u32MBOne[eMB];
    vSetMBIM(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_EnableInterrupts(TXCAN_CH_e eCh, uint32_t u32Value)
{
    vSetMBIM(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_ClearTransmitInterrupts(TXCAN_CH_e eCh, uint32_t u32Value)
{
    vSetMBTIF(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_ClearTransmitInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMBTIF(eCh) | u32MBOne[eMB];
    vSetMBTIF(eCh, u32Value);
}

/****************************************************************************/

uint32_t u32TXCAN_GetTransmitInterrupts(TXCAN_CH_e eCh)
{
    return u32GetMBTIF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetTransmitInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMBTIF(eCh) & u32MBOne[eMB];
    if (u32Value == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/****************************************************************************/

void vTXCAN_ClearReceiveInterrupts(TXCAN_CH_e eCh, uint32_t u32Value)
{
    vSetMBRIF(eCh, u32Value);
}

/****************************************************************************/

void vTXCAN_ClearReceiveInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMBRIF(eCh) | u32MBOne[eMB];
    vSetMBRIF(eCh, u32Value);
}

/****************************************************************************/

uint32_t u32TXCAN_GetReceiveInterrupts(TXCAN_CH_e eCh)
{
    return u32GetMBRIF(eCh);
}

/****************************************************************************/

uint8_t u8TXCAN_GetReceiveInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB)
{
    uint32_t u32Value;

    u32Value = u32GetMBRIF(eCh) & u32MBOne[eMB];
    if (u32Value == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/****************************************************************************/

/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: txcan.c
**  $Revision: 1.10 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :  5 (0286) String literal contains character which is not a
** |                    member of the basic source character set.
** |           5 (0288) Source file '<TEXT>' has comments containing characters
** |                    which are not members of the basic source character set.
** |          22 (3218) File scope static, '<TEXT>', only accessed in one
** |                    function.
** |          45 (0303) Cast between a pointer to volatile object and an
** |                    integral type.
** |          52 (1503) The function '%1s' is defined but is not used within
** |                    this project.
** |
** | REASON : This is neccessary because of driver version control.
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
  conditions set forth in the “Handling Guide for Semiconductor Devices,” or
  “TOSHIBA Semiconductor Reliability Handbook” etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (“Unintended Usage”).
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

****************************  END of DISCALIMER ****************************/

