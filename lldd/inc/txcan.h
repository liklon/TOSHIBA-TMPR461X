/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   DESCRIPTION : TCAN low level driver header file
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TCAN
*   LIBRARIES   : None
*****************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
****************************************************************************/
#ifndef _TXCAN_H
#define _TXCAN_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_TXCAN_H_REVISION     "$Revision: 1.12 $"
#define LLDD_TXCAN_H_TAG          "$Name: LLDD_1_6 $"

/****************************************************************************
*                          CONTROLER SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
typedef enum tag_TXCAN_CH_e
{
  TXCAN_CH0 =0,
  TXCAN_CH1 =0x1000,  
  TXCAN_CH2 =0x2000 
} TXCAN_CH_e;

/**********************************************
*                   Enums                     *
**********************************************/
/* TXCAN Mailbox selection values */
typedef enum tag_TXCAN_MB_e
{
  TXCAN_MB0  = 0x00,    /* Mailbox 0  */
  TXCAN_MB1  = 0x01,    /* Mailbox 1  */
  TXCAN_MB2  = 0x02,    /* Mailbox 2  */
  TXCAN_MB3  = 0x03,    /* Mailbox 3  */
  TXCAN_MB4  = 0x04,    /* Mailbox 4  */
  TXCAN_MB5  = 0x05,    /* Mailbox 5  */
  TXCAN_MB6  = 0x06,    /* Mailbox 6  */
  TXCAN_MB7  = 0x07,    /* Mailbox 7  */
  TXCAN_MB8  = 0x08,    /* Mailbox 8  */
  TXCAN_MB9  = 0x09,    /* Mailbox 9  */
  TXCAN_MB10 = 0x0A,    /* Mailbox 10 */
  TXCAN_MB11 = 0x0B,    /* Mailbox 11 */
  TXCAN_MB12 = 0x0C,    /* Mailbox 12 */
  TXCAN_MB13 = 0x0D,    /* Mailbox 13 */
  TXCAN_MB14 = 0x0E,    /* Mailbox 14 */
  TXCAN_MB15 = 0x0F,    /* Mailbox 15 */
  TXCAN_MB16 = 0x10,    /* Mailbox 16 */
  TXCAN_MB17 = 0x11,    /* Mailbox 17 */
  TXCAN_MB18 = 0x12,    /* Mailbox 18 */
  TXCAN_MB19 = 0x13,    /* Mailbox 19 */
  TXCAN_MB20 = 0x14,    /* Mailbox 20 */
  TXCAN_MB21 = 0x15,    /* Mailbox 21 */
  TXCAN_MB22 = 0x16,    /* Mailbox 22 */
  TXCAN_MB23 = 0x17,    /* Mailbox 23 */
  TXCAN_MB24 = 0x18,    /* Mailbox 24 */
  TXCAN_MB25 = 0x19,    /* Mailbox 25 */
  TXCAN_MB26 = 0x1A,    /* Mailbox 26 */
  TXCAN_MB27 = 0x1B,    /* Mailbox 27 */
  TXCAN_MB28 = 0x1C,    /* Mailbox 28 */
  TXCAN_MB29 = 0x1D,    /* Mailbox 29 */
  TXCAN_MB30 = 0x1E,    /* Mailbox 30 */
  TXCAN_MB31 = 0x1F     /* Mailbox 31 */
} TXCAN_MB_e;

/**********************************************
*                   Timing                    *
**********************************************/
typedef enum tag_TXCAN_Sampling_e
{
  TXCAN_SingleSampling = 0,	/* single sampling */
  TXCAN_TripleSampling		  /* triple sampling */
} TXCAN_Sampling_e;

typedef enum tag_TXCAN_BitLS_e
{
  TXCAN_BitLS1TQ = 0,  /* lengthening and shortening of 1 TQ */
  TXCAN_BitLS2TQ,      /* lengthening and shortening of 2 TQ */
  TXCAN_BitLS3TQ,      /* lengthening and shortening of 3 TQ */
  TXCAN_BitLS4TQ       /* lengthening and shortening of 4 TQ */
} TXCAN_BitLS_e;

/* TXCAN timing structure */
typedef struct tag_TXCAN_timing_st
{
    uint8_t            u8BaudRatePrescaler;     /* prescaler */
    uint8_t            u8BitTiming1;            /* bit timing parameter 1 */
    uint8_t            u8BitTiming2;            /* bit timing parameter 2 */
    TXCAN_Sampling_e   eSamplingType;           /* Source Memory Segment */
    TXCAN_BitLS_e      eBitLS;                  /* lengthening and shortening of bits */
} TXCAN_timing_st;

/**********************************************
*                  Channel                    *
**********************************************/
typedef enum tag_TXCAN_SoftwareReset_e
{
  TXCAN_SRDisable = 0,  /* disable software reset */
  TXCAN_SREnable        /* enable software reset */
} TXCAN_SoftwareReset_e;

typedef enum tag_TXCAN_TimeStampCounter_e
{
  TXCAN_TSCDisable = 0,   /* disable software reset */
  TXCAN_TSCClear          /* enable software reset */
} TXCAN_TimeStampCounter_e;

typedef enum tag_TXCAN_TransmissionOrder_e
{
  TXCAN_MailboxNumber = 0,	/* mailbox number */
  TXCAN_IdentifierPriority	/* identifier priority */
} TXCAN_TransmissionOrder_e;

typedef enum tag_TXCAN_WakeUpOnBus_e
{
  TXCAN_WriteToMCR = 0,   /* wakeup by write access to MCR */
  TXCAN_BusActivity       /* wakeup by bus activity */
} TXCAN_WakeUpOnBus_e;

typedef enum tag_TXCAN_Sleep_e
{
  TXCAN_noRequest = 0,   /* no sleep mode request */
  TXCAN_SleepMode        /* sleep mode request */
} TXCAN_Sleep_e;

typedef enum tag_TXCAN_ChangeConfig_e
{
  TXCAN_CCNormalOperation = 0,   /* normal operation requested */
  TXCAN_WriteAccess              /* write access to config register */
} TXCAN_ChangeConfig_e;

typedef enum tag_TXCAN_TestError_e
{
  TXCAN_TENormalOperation = 0,   /* normal operation requested */
  TXCAN_TestErrorMode            /* test error mode requested */
} TXCAN_TestError_e;

typedef enum tag_TXCAN_TestLoopback_e
{
  TXCAN_TLBNormalOperation = 0,   /* normal operation requested */
  TXCAN_TestLoopbackMode          /* test loopback mode requested */
} TXCAN_TestLoopback_e;

typedef enum tag_TXCAN_InternalLoopback_e
{
  TXCAN_ILBNormalOperation = 0,   /* normal operation requested */
  TXCAN_InternalLoopbackMode      /* internal loopback mode requested */
} TXCAN_InternalLoopback_e;

typedef enum tag_TXCAN_Suspend_e
{
  TXCAN_SNormalOperation = 0,   /* normal operation requested */
  TXCAN_SuspendkMode            /* internal loopback mode requested */
} TXCAN_Suspend_e;

/* TXCAN configuration structure */
typedef struct tag_TXCAN_CHconfig_st
{
    TXCAN_SoftwareReset_e	    eSoftwareReset;     /* enable software reset */
    TXCAN_TimeStampCounter_e  eTimeStampCounter;  /* time stamp counter */
    TXCAN_TransmissionOrder_e eTransmissionOrder; /* transmission order */
    TXCAN_WakeUpOnBus_e       eWakeUp;            /* wake up on bus activity */
    TXCAN_Sleep_e             eSleepMode;         /* sleep mode request */
    TXCAN_ChangeConfig_e      eChangeConfig;      /* change config request */
    TXCAN_TestError_e         eTestError;         /* test error mode */
    TXCAN_TestLoopback_e      eTestLoopback;      /* test loopback mode */
    TXCAN_InternalLoopback_e  eInternalLoopback;  /* internal loopback mode */
    TXCAN_Suspend_e           eSuspendMode;       /* suspend mode request */
} TXCAN_CHconfig_st;

/**********************************************
*                 Mailbox                     *
**********************************************/
typedef enum tag_TXCAN_RemoteFrameTransmissionRequest_e
{
	TXCAN_NormalFrame = 0,   /* normal frame */
	TXCAN_RemoteFrame        /* remote frame */
} TXCAN_RemoteFrameTransmissionRequest_e;

typedef enum tag_TXCAN_RemoteFrameHandling_e
{
  TXCAN_SoftwareHandled = 0,    /* software mus handle remote frames */
  TXCAN_Automatically           /* mailbox will automatically answer to remote frames */
} TXCAN_RemoteFrameHandling_e;

typedef enum tag_TXCAN_GlobalAcceptanceMask_e
{
  TXCAN_Identifier = 0,         /* The received message will only be stored, when the received identifier is identical to that in the mailbox */
  TXCAN_GlobalAcceptanceMask    /* The global acceptance mask will be used for acceptance filtering */
} TXCAN_GlobalAcceptanceMask_e;

typedef enum tag_TXCAN_FrameType_e
{
  TXCAN_Standard = 0,    /* standard frames, 11 bit */
  TXCAN_Extended         /* extended frames, 29 bit */
} TXCAN_FrameType_e;

typedef enum tag_TXCAN_MailboxDiretion_e
{
	TXCAN_Output = 0,    /* mailbox is output */
	TXCAN_Input          /* mailbox is input */
} TXCAN_MailboxDiretion_e;

typedef struct tag_TXCAN_MBconfig_st
{
    TXCAN_CH_e                             eChannel;                          /* CAN channel */
    TXCAN_MB_e                             eMailbox;                          /* CAN mailbox */
    uint8_t                                u8DataLength;                      /* data length */
    TXCAN_RemoteFrameTransmissionRequest_e eRemoteFrameTransmissionRequest;   /* remote frame transmission request */
    uint32_t                               u32ExtendedIdentifier;             /* extended identifier */
    uint16_t                               u16StandardIdentifier;             /* standard identifier */
    TXCAN_RemoteFrameHandling_e            eRemoteFrameHandling;              /* handling of remote frames */
    TXCAN_GlobalAcceptanceMask_e           eGlobalAcceptanceMask;             /* global acceptance mask */
    TXCAN_FrameType_e                      eFrameType;                        /* frame type */
    TXCAN_MailboxDiretion_e                eMailboxDirection;                 /* mailbox direction */
} TXCAN_MBconfig_st;

/**********************************************
*                 General                     *
**********************************************/
typedef enum tag_TXCAN_AcceptanceMaskType_e
{
	TXCAN_IdentifierBitLAM = 0,     /* The identifier extension bit stored in the mailbox determines
                                     which messages shall be received */
	TXCAN_StandardandExtendedLAM    /* Don’t care: standard and extended frames can be received */
} TXCAN_AcceptanceMaskType_e;

/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vTXCAN_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8IORevision     - pointer to IO header revision string
 *                pau8IOTag          - pointer to IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                       uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                       uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      vTXCAN_SetDatalength
 *
 * Purpose:       sets data length
 *
 * Inputs:        eCh      - CAN channel
 *                eMB      - mailbox
 *                u8Length - data length
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetDatalength(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Length);

/****************************************************************************
 *
 * Function:      vTXCAN_GetDatalength
 *
 * Purpose:       reads data length
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: data length
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t vTXCAN_GetDatalength(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SetRemoteFrameTransmissionRequest
 *
 * Purpose:       sets frame transmission request
 *
 * Inputs:        eCh  - CAN channel
 *                eMB  - mailbox
 *                eRTR - frame transmission request type
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetRemoteFrameTransmissionRequest(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_RemoteFrameTransmissionRequest_e eRTR);

/****************************************************************************
 *
 * Function:      eTXCAN_GetRemoteFrameTransmissionRequest
 *
 * Purpose:       reads frame transmission request individual
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: remote frame transmission request
 *
 * Limitations:   none
 *
 ***************************************************************************/
TXCAN_RemoteFrameTransmissionRequest_e eTXCAN_GetRemoteFrameTransmissionRequest(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SetTimeStampCounterValue
 *
 * Purpose:       sets time stamp counter value
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u16TSV - time stamp counter value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetTimeStampCounterValue(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint16_t u16TSV);

/****************************************************************************
 *
 * Function:      u16TXCAN_GetTimeStampCounterValue
 *
 * Purpose:       reads time stamp counter value
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: time stamp counter value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TXCAN_GetTimeStampCounterValue(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SetExtID
 *
 * Purpose:       sets ext. ID
 *
 * Inputs:        eCh   - CAN channel
 *                eMB   - mailbox
 *                u16ID - ext. ID
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetExtID(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint16_t u16ID);

/****************************************************************************
 *
 * Function:      u16TXCAN_GetExtID
 *
 * Purpose:       reads ext. ID
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: ext. ID
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetExtID(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SetStdID
 *
 * Purpose:       sets std. ID
 *
 * Inputs:        eCh   - CAN channel
 *                eMB   - mailbox
 *                u16ID - std. ID
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetStdID(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint16_t u16ID);

/****************************************************************************
 *
 * Function:      u16TXCAN_GetStdID
 *
 * Purpose:       reads std. ID
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: std. ID
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TXCAN_GetStdID(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SetRemoteFrameHandling
 *
 * Purpose:       sets remote frame handling
 *
 * Inputs:        eCh  - CAN channel
 *                eMB  - mailbox
 *                eRFH - remote frame handling type
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetRemoteFrameHandling(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_RemoteFrameHandling_e eRFH);

/****************************************************************************
 *
 * Function:      eTXCAN_GetRemoteFrameHandling
 *
 * Purpose:       reads remote frame handling
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: remote frame handling
 *
 * Limitations:   none
 *
 ***************************************************************************/
TXCAN_RemoteFrameHandling_e eTXCAN_GetRemoteFrameHandling(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SetGlobalAcceptanceMask
 *
 * Purpose:       sets global acceptance mask
 *
 * Inputs:        eCh   - CAN channel
 *                eMB   - mailbox
 *                eGAME - global acceptance mask
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetGlobalAcceptanceMask(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_GlobalAcceptanceMask_e eGAME);

/****************************************************************************
 *
 * Function:      eTXCAN_GetGlobalAcceptanceMask
 *
 * Purpose:       reads global acceptance mask
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: global acceptance mask
 *
 * Limitations:   none
 *
 ***************************************************************************/
TXCAN_GlobalAcceptanceMask_e eTXCAN_GetGlobalAcceptanceMask(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SetFrameType
 *
 * Purpose:       set frame type
 *
 * Inputs:        eCh  - CAN channel
 *                eMB  - mailbox
 *                eIDE - frame type
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetFrameType(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_FrameType_e eIDE);

/****************************************************************************
 *
 * Function:      eTXCAN_GetFrameType
 *
 * Purpose:       reads frame type
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: frame type
 *
 * Limitations:   none
 *
 ***************************************************************************/
TXCAN_FrameType_e eTXCAN_GetFrameType(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxD0
 *
 * Purpose:       write data into D0 of mailbox
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u8Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxD0(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data);

/****************************************************************************
 *
 * Function:      u8TXCAN_ReadMailboxD0
 *
 * Purpose:       read data from D0 of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox D0 value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_ReadMailboxD0(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxD1
 *
 * Purpose:       write data into D1 of mailbox
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u8Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxD1(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data);

/****************************************************************************
 *
 * Function:      u8TXCAN_ReadMailboxD1
 *
 * Purpose:       read data from D1 of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox D1 value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_ReadMailboxD1(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxD2
 *
 * Purpose:       write data into D2 of mailbox
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u8Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxD2(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data);

/****************************************************************************
 *
 * Function:      u8TXCAN_ReadMailboxD2
 *
 * Purpose:       read data from D2 of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox D2 value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_ReadMailboxD2(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxD3
 *
 * Purpose:       write data into D3 of mailbox
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u8Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxD3(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data);

/****************************************************************************
 *
 * Function:      u8TXCAN_ReadMailboxD3
 *
 * Purpose:       read data from D3 of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox D3 value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_ReadMailboxD3(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxD4
 *
 * Purpose:       write data into D4 of mailbox
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u8Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxD4(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data);

/****************************************************************************
 *
 * Function:      u8TXCAN_ReadMailboxD4
 *
 * Purpose:       read data from D4 of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox D4 value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_ReadMailboxD4(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxD5
 *
 * Purpose:       write data into D5 of mailbox
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u8Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxD5(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data);

/****************************************************************************
 *
 * Function:      u8TXCAN_ReadMailboxD5
 *
 * Purpose:       read data from D5 of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox D5 value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_ReadMailboxD5(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxD6
 *
 * Purpose:       write data into D6 of mailbox
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u8Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxD6(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data);

/****************************************************************************
 *
 * Function:      u8TXCAN_ReadMailboxD6
 *
 * Purpose:       read data from D6 of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox D6 value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_ReadMailboxD6(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxD7
 *
 * Purpose:       write data into D7 of mailbox
 *
 * Inputs:        eCh    - CAN channel
 *                eMB    - mailbox
 *                u8Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxD7(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint8_t u8Data);

/****************************************************************************
 *
 * Function:      u8TXCAN_ReadMailboxD7
 *
 * Purpose:       read data from D7 of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox D7 value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_ReadMailboxD7(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxLow
 *
 * Purpose:       write low part of mailbox
 *
 * Inputs:        eCh     - CAN channel
 *                eMB     - mailbox
 *                u32Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxLow(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint32_t u32Data);

/****************************************************************************
 *
 * Function:      u32TXCAN_ReadMailboxLow
 *
 * Purpose:       read low part of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox low value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_ReadMailboxLow(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailboxHigh
 *
 * Purpose:       write high part of mailbox
 *
 * Inputs:        eCh     - CAN channel
 *                eMB     - mailbox
 *                u32Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailboxHigh(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint32_t u32Data);

/****************************************************************************
 *
 * Function:      u32TXCAN_ReadMailboxHigh
 *
 * Purpose:       read high part of mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox high value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_ReadMailboxHigh(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_WriteMailbox
 *
 * Purpose:       write data to mailbox
 *
 * Inputs:        eCh     - CAN channel
 *                eMB     - mailbox
 *                u64Data - mailbox data
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_WriteMailbox(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint64_t u64Data);

/****************************************************************************
 *
 * Function:      u64TXCAN_ReadMailbox
 *
 * Purpose:       read data from mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint64_t u64TXCAN_ReadMailbox(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_MailboxEnableAll
 *
 * Purpose:       enable all mailboxes
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_MailboxEnableAll(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_MailboxDisableAll
 *
 * Purpose:       disable all mailboxes
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_MailboxDisableAll(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_MailboxEnable
 *
 * Purpose:       enable mailbox individual
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_MailboxEnable(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_MailboxDisable
 *
 * Purpose:       disable mailbox individual
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_MailboxDisable(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SetMailboxDirectionAll
 *
 * Purpose:       set mailbox direction
 *
 * Inputs:        eCh              - CAN channel
 *                u32DirectionCode - direction code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetMailboxDirectionAll(TXCAN_CH_e eCh, uint32_t u32DirectionCode);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetMailboxDirectionAll
 *
 * Purpose:       get mailbox direction
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: mailbox direction
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetMailboxDirectionAll(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetMailboxDirection
 *
 * Purpose:       set mailbox direction individual
 *
 * Inputs:        eCh        - CAN channel
 *                eMB        - mailbox
 *                eDirection - mailbox direction
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetMailboxDirection(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_MailboxDiretion_e eDirection);

/****************************************************************************
 *
 * Function:      eGetMailboxDirection
 *
 * Purpose:       returns direction of mailbox
 *
 * Inputs:        eCh        - CAN channel
 *                eMB        - mailbox
 *
 * Outputs:       none
 *
 * Return Values: mailbox direction
 *
 * Limitations:   none
 *
 ***************************************************************************/
TXCAN_MailboxDiretion_e eGetMailboxDirection(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_ConfigureMailbox
 *
 * Purpose:       configures mailbox
 *
 * Inputs:        stMBConfig - mailbox configuration
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ConfigureMailbox(TXCAN_MBconfig_st * stMBConfig);

/****************************************************************************
 *
 * Function:      vTXCAN_TransmitAll
 *
 * Purpose:       transmit mailbox
 *
 * Inputs:        eCh             - CAN channel
 *                u32TransmitCode - transmit code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_TransmitAll(TXCAN_CH_e eCh, uint32_t u32TransmitCode);

/****************************************************************************
 *
 * Function:      vTXCAN_Transmit
 *
 * Purpose:       transmit mailbox individual
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       data to CAN network
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_Transmit(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_SendMsg
 *
 * Purpose:       send message
 *
 * Inputs:        eCh     - CAN channel
 *                eMB     - mailbox
 *                u64Data - data to be send
 *
 * Outputs:       data to CAN network
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SendMsg(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint64_t u64Data);

/****************************************************************************
 *
 * Function:      vTXCAN_CancelTransmissionAll
 *
 * Purpose:       cancel transmission
 *
 * Inputs:        eCh           - CAN channel
 *                u32CancelCode - cancel code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_CancelTransmissionAll(TXCAN_CH_e eCh, uint32_t u32CancelCode);

/****************************************************************************
 *
 * Function:      vTXCAN_CancelTransmission
 *
 * Purpose:       cancel transmission individual
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_CancelTransmission(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTransmissionAcknowledgeAll
 *
 * Purpose:       clear transmission acknowledge
 *
 * Inputs:        eCh                 - CAN channel
 *                u32TransmissionCode - transmission code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTransmissionAcknowledgeAll(TXCAN_CH_e eCh, uint32_t u32TransmissionCode);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTransmissionAcknowledge
 *
 * Purpose:       clear transmission acknowledge individual
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTransmissionAcknowledge(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTransmissionAbortAcknowledgeAll
 *
 * Purpose:       clear transmission abort acknowledge
 *
 * Inputs:        eCh - CAN channel
 *                u32TransmissionCode - transmission code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTransmissionAbortAcknowledgeAll(TXCAN_CH_e eCh, uint32_t u32TransmissionCode);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTransmissionAbortAcknowledge
 *
 * Purpose:       clear transmission abort acknowledge individual
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTransmissionAbortAcknowledge(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetPendingReceiveMessages
 *
 * Purpose:       get pending receive messages
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: pending receive massages
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetPendingReceiveMessages(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetChangeDataRequestAll
 *
 * Purpose:       set change data request for all mailboxes
 *
 * Inputs:        eCh      - CAN channel
 *                u32Value - value to be set
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetChangeDataRequestAll(TXCAN_CH_e eCh, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      vTXCAN_SetChangeDataRequest
 *
 * Purpose:       set change data request for selected mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetChangeDataRequest(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetChangeDataRequestAll
 *
 * Purpose:       get change data request of all mailboxes
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: change data request value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetChangeDataRequestAll(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetChangeDataRequest
 *
 * Purpose:       get change data request of selected mailbox
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: change data request value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetChangeDataRequest(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetPendingReceiveMessage
 *
 * Purpose:       get pending receive message
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: pending receive massage
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetPendingReceiveMessage(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearPendingReceiveMessages
 *
 * Purpose:       clear pending receive messages
 *
 * Inputs:        eCh      - CAN channel
 *                u32Value - clear code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearPendingReceiveMessages(TXCAN_CH_e eCh, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearPendingReceiveMessage
 *
 * Purpose:       clear pending receive message
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearPendingReceiveMessage(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetReceiveMessageLosts
 *
 * Purpose:       get receive message slots
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: lost receive messages
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetReceiveMessageLosts(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetReceiveMessageLost
 *
 * Purpose:       get receive message slot
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: lost receive message
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetReceiveMessageLost(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearReceiveMessageLosts
 *
 * Purpose:       clear receive message slots
 *
 * Inputs:        eCh      - CAN channel
 *                u32Value - clear code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearReceiveMessageLosts(TXCAN_CH_e eCh, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearReceiveMessageLost
 *
 * Purpose:       clear receive message slot
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearReceiveMessageLost(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetPendingRemoteFrames
 *
 * Purpose:       get pending remote frames
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: pending remote frames
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetPendingRemoteFrames(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetPendingRemoteFrame
 *
 * Purpose:       get pending remote frame
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: pending remote frame
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetPendingRemoteFrame(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vSetAcceptanceMaskType
 *
 * Purpose:       sets type of acceptance mask
 *
 * Inputs:        eCh   - CAN channel
 *                eMB   - Mailbox
 *                eType - mask type
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSetAcceptanceMaskType(TXCAN_CH_e eCh, TXCAN_MB_e eMB, TXCAN_AcceptanceMaskType_e eType);

/****************************************************************************
 *
 * Function:      eGetAcceptanceMaskType
 *
 * Purpose:       reads type of acceptance mask
 *
 * Inputs:        eCh - CAN channel
 *                eMB - Mailbox
 *
 * Outputs:       none
 *
 * Return Values: acceptance mask type
 *
 * Limitations:   none
 *
 ***************************************************************************/
TXCAN_AcceptanceMaskType_e eGetAcceptanceMaskType(TXCAN_CH_e eCh, TXCAN_MB_e eMB);







/****************************************************************************
 *
 * Function:      vTXCAN_SetAcceptanceMask
 *
 * Purpose:       sets type of acceptance mask all
 *
 * Inputs:        eCh      - CAN channel
 *                eMB      - mailbox
 *                u32Value - mask value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetAcceptanceMask(TXCAN_CH_e eCh, TXCAN_MB_e eMB, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetAcceptanceMask
 *
 * Purpose:       gets type of acceptance mask all
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: acceptance mask
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetAcceptanceMask(TXCAN_CH_e eCh, TXCAN_MB_e eMB);






/****************************************************************************
 *
 * Function:      vTXCAN_ConfigureChannel
 *
 * Purpose:       configure channel
 *
 * Inputs:        eCh      - CAN channel
 *                stConfig - channel configuration
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ConfigureChannel(TXCAN_CH_e eCh, TXCAN_CHconfig_st * stConfig);

/****************************************************************************
 *
 * Function:      vTXCAN_GetChannelConfiguration
 *
 * Purpose:       read channel configuration
 *
 * Inputs:        eCh      - CAN channel
 *                stConfig - channel configuration
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_GetChannelConfiguration(TXCAN_CH_e eCh, TXCAN_CHconfig_st * stConfig);

/****************************************************************************
 *
 * Function:      vTXCAN_ConfigureTiming
 *
 * Purpose:       configure timing
 *
 * Inputs:        eCh      - CAN channel
 *                stTiming - channel timing
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ConfigureTiming(TXCAN_CH_e eCh, TXCAN_timing_st * stTiming);

/****************************************************************************
 *
 * Function:      vTXCAN_GetTimingConfiguration
 *
 * Purpose:       read timing configuration
 *
 * Inputs:        eCh      - CAN channel
 *                stTiming - channel timing
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_GetTimingConfiguration(TXCAN_CH_e eCh, TXCAN_timing_st * stTiming);

/****************************************************************************
 *
 * Function:      u16TXCAN_GetTimeStampCounter
 *
 * Purpose:       read time stamp counter register
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: time stamp value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16TXCAN_GetTimeStampCounter(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTimeStampValue
 *
 * Purpose:       clear time stamp value
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTimeStampValue(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetTimeStampCounterPrescaler
 *
 * Purpose:       set time stamp counter prescaler value
 *
 * Inputs:        eCh     - CAN channel
 *                u8Value - prescaler value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetTimeStampCounterPrescaler(TXCAN_CH_e eCh, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTimeStampCounterPrescaler
 *
 * Purpose:       read time stamp counter prescaler value
 *
 * Inputs:        eCh     - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: time stamp counter prescaler value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTimeStampCounterPrescaler(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetGlobalStatus
 *
 * Purpose:       read global status
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: global status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetGlobalStatus(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetWarningStatus
 *
 * Purpose:       read warning status
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: warning status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetWarningStatus(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetErrorPassiveStatus
 *
 * Purpose:       read error passive status
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: error passive status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetErrorPassiveStatus(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetBusOffStatus
 *
 * Purpose:       read buss off status
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: bus off status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetBusOffStatus(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTimeStampOverflowFlag
 *
 * Purpose:       read time stamp overflov flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: time stamp overflow flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTimeStampOverflowFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetSleepModeAcknowledge
 *
 * Purpose:       read sleep mode acknowledge
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: sleep mode acknowledge
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetSleepModeAcknowledge(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetChangeConfigurationEnable
 *
 * Purpose:       read change config enable
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: change config enable
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetChangeConfigurationEnable(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetSuspendModeAcknowledge
 *
 * Purpose:       read suspend mode acknowledge
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: suspend mode acknowledge
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetSuspendModeAcknowledge(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTransmitMode
 *
 * Purpose:       read transmit mode
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: transmit mode
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTransmitMode(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetReceiveMode
 *
 * Purpose:       read receive mode
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: receive mode
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetReceiveMode(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetMessageInSlot
 *
 * Purpose:       read message in slot
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: message in slot
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetMessageInSlot(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetReceiveErrorCounter
 *
 * Purpose:       read receive error counter
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: receive error counter value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetReceiveErrorCounter(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTransmitErrorCounter
 *
 * Purpose:       read transmit error counter
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: transmit error counter value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTransmitErrorCounter(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetGlobalInterruptFlags
 *
 * Purpose:       read global interrupt flags
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: global interrupt flags
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetGlobalInterruptFlags(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearGlobalInterruptFlags
 *
 * Purpose:       clear global interrupt flags
 *
 * Inputs:        eCh     - CAN channel
 *                u8Flags - global interrupt flags
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearGlobalInterruptFlags(TXCAN_CH_e eCh, uint8_t u8Flags);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetWarningLevelInterruptFlag
 *
 * Purpose:       read warning level interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: warning level interrupt flag value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetWarningLevelInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearWarningLevelInterruptFlag
 *
 * Purpose:       clear warning level interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearWarningLevelInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetErrorPassiveInterruptFlag
 *
 * Purpose:       read error passive interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: error passive interrupt flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetErrorPassiveInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearErrorPassiveInterruptFlag
 *
 * Purpose:       clear error passive interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearErrorPassiveInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetBusOffInterruptFlag
 *
 * Purpose:       read bus off interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: bus off interrupt flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetBusOffInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearBusOffInterruptFlag
 *
 * Purpose:       clear bus off interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearBusOffInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTimeStampCounterOverflowInterruptFlag
 *
 * Purpose:       read time stamp counter overflow flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: time stamp counter overflow flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTimeStampCounterOverflowInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTimeStampCounterOverflowInterruptFlag
 *
 * Purpose:       clear time stamp counter overflow flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTimeStampCounterOverflowInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTransmitAbortFlag
 *
 * Purpose:       read transmit abort flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: transmit abort flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTransmitAbortFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTransmitAbortFlag
 *
 * Purpose:       clear transmit abort flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTransmitAbortFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetReceiveMessageLostInterruptFlag
 *
 * Purpose:       read receive message lost flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: receive message lost flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetReceiveMessageLostInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearReceiveMessageLostInterruptFlag
 *
 * Purpose:       clear receive message lost flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearReceiveMessageLostInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetWakeUpInterruptFlag
 *
 * Purpose:       read wake-up interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: wake-up interrupt flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetWakeUpInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearWakeUpInterruptFlag
 *
 * Purpose:       clear wake-up interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearWakeUpInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetRemoteFramePendingFlag
 *
 * Purpose:       read remote frame pending flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: remote frame pending flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetRemoteFramePendingFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearRemoteFramePendingFlag
 *
 * Purpose:       clear remote frame pending flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearRemoteFramePendingFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetGlobalInterruptMasks
 *
 * Purpose:       read global interrupt masks
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: global interrupt masks
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetGlobalInterruptMasks(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetGlobalInterruptMasks
 *
 * Purpose:       set global interrupt masks
 *
 * Inputs:        eCh     - CAN channel
 *                u8Masks - global interrupt masks
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetGlobalInterruptMasks(TXCAN_CH_e eCh, uint8_t u8Masks);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetWarningLevelInterruptMask
 *
 * Purpose:       read warning level interrupt mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: warning level interrupt mask value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetWarningLevelInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetWarningLevelInterruptMask
 *
 * Purpose:       set warning level interrupt mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetWarningLevelInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetErrorPassiveInterruptMask
 *
 * Purpose:       read error passive interrupt mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: error passive interrupt mask
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetErrorPassiveInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetErrorPassiveInterruptMask
 *
 * Purpose:       set error passive interrupt mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetErrorPassiveInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetBusOffInterruptFlag
 *
 * Purpose:       read bus off interrupt flag
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: bus off interrupt flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetBusOffInterruptFlag(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetBusOffInterruptMask
 *
 * Purpose:       set bus off interrupt mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetBusOffInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTimeStampCounterOverflowInterruptMask
 *
 * Purpose:       read time stamp counter overflow mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: time stamp counter overflow mask
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTimeStampCounterOverflowInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetTimeStampCounterOverflowInterruptMask
 *
 * Purpose:       set time stamp counter overflow mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetTimeStampCounterOverflowInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTransmitAbortMask
 *
 * Purpose:       read transmit abort mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: transmit abort mask
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTransmitAbortMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetTransmitAbortMask
 *
 * Purpose:       set transmit abort mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetTransmitAbortMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetReceiveMessageLostInterruptMask
 *
 * Purpose:       read receive message lost mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: receive message lost mask
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetReceiveMessageLostInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetReceiveMessageLostInterruptMask
 *
 * Purpose:       set receive message lost mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetReceiveMessageLostInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetWakeUpInterruptMask
 *
 * Purpose:       read wake-up interrupt mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: wake-up interrupt mask
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetWakeUpInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetWakeUpInterruptMask
 *
 * Purpose:       set wake-up interrupt mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetWakeUpInterruptMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetRemoteFramePendingMask
 *
 * Purpose:       read remote frame pending mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: remote frame pending mask
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetRemoteFramePendingMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_SetRemoteFramePendingMask
 *
 * Purpose:       set remote frame pending mask
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_SetRemoteFramePendingMask(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      vTXCAN_EnableInterrupt
 *
 * Purpose:       enable interrupt
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_EnableInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_DisableInterrupt
 *
 * Purpose:       disable interrupt
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_DisableInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_EnableInterrupts
 *
 * Purpose:       enable interrupts
 *
 * Inputs:        eCh      - CAN channel
 *                u32Value - interrupt code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_EnableInterrupts(TXCAN_CH_e eCh, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTransmitInterrupts
 *
 * Purpose:       clear transmit interrupts
 *
 * Inputs:        eCh      - CAN channel
 *                u32Value - interrupt code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTransmitInterrupts(TXCAN_CH_e eCh, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearTransmitInterrupt
 *
 * Purpose:       clear transmit interrupt
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearTransmitInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetTransmitInterrupts
 *
 * Purpose:       get transmit interrupts
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: transmit interrupts
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetTransmitInterrupts(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetTransmitInterrupt
 *
 * Purpose:       get transmit interrupt
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: transmit interrupt
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetTransmitInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearReceiveInterrupts
 *
 * Purpose:       clear receive interrupts
 *
 * Inputs:        eCh      - CAN channel
 *                u32Value - interrupt code
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearReceiveInterrupts(TXCAN_CH_e eCh, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      vTXCAN_ClearReceiveInterrupt
 *
 * Purpose:       clear receive interrupt
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vTXCAN_ClearReceiveInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************
 *
 * Function:      u32TXCAN_GetReceiveInterrupts
 *
 * Purpose:       get receive interrupts
 *
 * Inputs:        eCh - CAN channel
 *
 * Outputs:       none
 *
 * Return Values: receive inteerrupts
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32TXCAN_GetReceiveInterrupts(TXCAN_CH_e eCh);

/****************************************************************************
 *
 * Function:      u8TXCAN_GetReceiveInterrupt
 *
 * Purpose:       get receive interrupt
 *
 * Inputs:        eCh - CAN channel
 *                eMB - mailbox
 *
 * Outputs:       none
 *
 * Return Values: receive interrupt
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8TXCAN_GetReceiveInterrupt(TXCAN_CH_e eCh, TXCAN_MB_e eMB);

/****************************************************************************/


#endif	/* _TXCAN_H */

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

