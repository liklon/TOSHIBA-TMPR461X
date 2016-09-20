/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION :
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     : TSM-Driver
*   MODULE      : TSM Secure boot related
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.33 $
*   DATE        : $Date: 2015/05/04 09:07:18 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/


/**********************************************
*                Include files                *
**********************************************/
#include "tsmdefines.h"
#include "tsmapi_common.h"
#include "tsm_ap.h"
#include "tsm_ap_cr4.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/
#ifdef __ERC_LOOP_WITH_TIMER__
#define TSM_POOL_MAX_LOOPS 1000000000UL

#define TSM_FIFO_TIMEOUT_NSEC 1000000000UL
#define CLOCK_REALTIME 0

#endif

/* Major Version number is part of 16 high bits */
#define TSM_VERSION_MAJOR_SHIFT   0x10

#ifndef RAM_EXECUTION
    /* TSM version is stored in ROM area */
    #define TSM_VERSION_ADDR           0xFFFFBFFCU
#else
    /* TSM version is stored in RAM area */
    #define TSM_VERSION_ADDR           0x00890004U
#endif

#define TSM_VER_INVALID_VALUE_ALL_BITS   0xFFFFFFFFU
#define TSM_INVALID_VER_VALUE_NO_BITS    0x00000000U

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/
#ifdef __ERC_LOOP_WITH_TIMER__
/* NOTE: time datatypes to be replaced by <time.h> in a POSIX environment */
typedef uint32_t time_t;
typedef uint32_t clockid_t;

struct timespec
{
    /* seconds */
    time_t tv_sec;
    /* nanoseconds */
    uint32_t tv_nsec;
};
#endif

/**********************************************
*                    Macros                   *
**********************************************/

/*********************************************/


/**********************************************
*  Static variables and forward declarations  *
**********************************************/
#ifdef __ERC_LOOP_WITH_TIMER__
static uint32_t stTimeDiffNanosec (struct timespec stTimeEnd, struct timespec stTimeStart);
static uint32_t clock_gettime(clockid_t clk_id, struct timespec *tp);
#endif
/*********************************************/


/**********************************************
*             Function definition             *
*********************************************/

/****************************************************************************/
#ifdef __ERC_LOOP_WITH_TIMER__
static uint32_t stTimeDiffNanosec(struct timespec stTimeEnd, struct timespec stTimeStart)
{
    struct timespec stTimeDiff;
    uint32_t u32TimeDiff;

    stTimeDiff.tv_sec = stTimeEnd.tv_sec - stTimeStart.tv_sec;
    stTimeDiff.tv_nsec = stTimeEnd.tv_nsec - stTimeStart.tv_nsec;

    /* Calculate the time difference in nanoseconds */
    u32TimeDiff = stTimeDiff.tv_nsec + (stTimeDiff.tv_sec * 1000000000UL);

    return u32TimeDiff;
}


/****************************************************************************/
/* Dummy placeholder - to be replaced by POSIX call from OS */
static uint32_t clock_gettime(clockid_t clk_id, struct timespec *tp)    /* PRQA S 3206 */
{
    tp->tv_nsec = 0;
    tp->tv_sec = 0;
    return 0;
}
#endif

/****************************************************************************/
tsm_func_ret_e eTSM_PollForErc(void)
{
    tsm_func_ret_e eRetCode;
    tsm_erc_e eTmpErc = TSM_ERC_NO_ERROR;

#ifdef __ERC_LOOP_WITH_TIMER__
    struct timespec stTime1;
    struct timespec stTime2;

    uint32_t u32ClockFuncRes;
    uint32_t u32LoopCounter = 0;

    u32ClockFuncRes = clock_gettime(CLOCK_REALTIME, &stTime1);

    if( 0 != u32ClockFuncRes )
    {
        eRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
    }
    else
    {
        /* Loop until there is a valid ERC or timeout occurs */
        do
        {
            uint32_t u32TmpTimeDiff;
            u32ClockFuncRes = clock_gettime(CLOCK_REALTIME, &stTime2);
            u32TmpTimeDiff = stTimeDiffNanosec (stTime2, stTime1);
            if ( (0 != u32ClockFuncRes) || (u32TmpTimeDiff > TSM_FIFO_TIMEOUT_NSEC) || (u32LoopCounter > TSM_POOL_MAX_LOOPS) ) {
                eRetCode = TSM_FUNC_GENERAL_ERROR_TIMEOUT;
            }
            else
            {
                eRetCode = eTSM_GetErrorResultCode(&eTmpErc);
            }
            u32LoopCounter++;
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eRetCode);
    }
#else
        /* Loop until there is a valid ERC */
        do {
                eRetCode = eTSM_GetErrorResultCode(&eTmpErc);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eRetCode);
#endif

    /* Translate ERC to function return code */
    if (TSM_FUNC_NO_ERROR == eRetCode)
    {
        switch (eTmpErc)
        {
            case TSM_ERC_NO_ERROR:
                eRetCode = TSM_FUNC_NO_ERROR;
                break;
            case TSM_ERC_SEQUENCE_ERROR:
                eRetCode = TSM_FUNC_SEQUENCE_ERROR;
                break;
            case TSM_ERC_KEY_NOT_AVAILABLE:
                eRetCode = TSM_FUNC_KEY_NOT_AVAILABLE;
                break;
            case TSM_ERC_KEY_INVALID:
                eRetCode = TSM_FUNC_KEY_INVALID;
                break;
            case TSM_ERC_KEY_EMPTY:
                eRetCode = TSM_FUNC_KEY_EMPTY;
                break;
            case TSM_ERC_NO_SECURE_BOOT:
                eRetCode = TSM_FUNC_NO_SECURE_BOOT;
                break;
            case TSM_ERC_KEY_WRITE_PROTECTED:
                eRetCode = TSM_FUNC_KEY_WRITE_PROTECTED;
                break;
            case TSM_ERC_KEY_UPDATE_ERROR:
                eRetCode = TSM_FUNC_KEY_UPDATE_ERROR;
                break;
            case TSM_ERC_RNG_SEED:
                eRetCode = TSM_FUNC_RNG_SEED;
                break;
            case TSM_ERC_NO_DEBUGGING:
                eRetCode = TSM_FUNC_NO_DEBUGGING;
                break;
            case TSM_ERC_BUSY:
                eRetCode = TSM_FUNC_BUSY;
                break;
            case TSM_ERC_MEMORY_FAILURE:
                eRetCode = TSM_FUNC_MEMORY_FAILURE;
                break;
            case TSM_ERC_GENERAL_ERROR:
                eRetCode = TSM_FUNC_GENERAL_ERROR;
                break;
            default:
                eRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
                break;
          }
    }

    /* If wrong ERC is returned, check if it's a BUSY scenario */
    if ((TSM_FUNC_GENERAL_ERROR_ERC_WRONG == eRetCode) && ((uint32_t)eTmpErc & (uint32_t)TSM_ERC_BUSY))
    {
        eRetCode = TSM_FUNC_BUSY;
    }

    return eRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_PollForErcGetData(uint32_t au32OutData[], const uint32_t u32N)
{
    tsm_func_ret_e eRetCode;
    tsm_ap_err_e    eApRetCode = TSM_AP_NO_ERROR;

    /* in case length parameter is not zero, then check for pointer being NULL */
    if ( (C_NULL == au32OutData) && (0U != u32N) )
    {
        eRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* first wait for the ERC to come */
        eRetCode = eTSM_PollForErc();

        /* in case there is output data to be retrieved and no error */
        if ( (0U != u32N) && (TSM_FUNC_NO_ERROR == eRetCode) )
        {
            /* read output data from TX FIFO */
            eApRetCode = eTSM_AP_ReadTxFIFO(au32OutData, u32N);
        }
        /* check for LLDD AP error */
        if ( (TSM_AP_NO_ERROR != eApRetCode) && (TSM_FUNC_NO_ERROR == eRetCode) )
        {
            eRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
        }

    }
    return eRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CheckForErc(void)
{
    tsm_func_ret_e eRetCode;
    tsm_erc_e eTmpErc = TSM_ERC_NO_ERROR;

    eRetCode = eTSM_GetErrorResultCode(&eTmpErc);

    /* Translate ERC to function return code */
    /* for the case of busy the translation is already done by
     * the function call */
    if (TSM_FUNC_NO_ERROR == eRetCode)
    {
        switch (eTmpErc)
        {
            case TSM_ERC_NO_ERROR:
                eRetCode = TSM_FUNC_NO_ERROR;
                break;
            case TSM_ERC_SEQUENCE_ERROR:
                eRetCode = TSM_FUNC_SEQUENCE_ERROR;
                break;
            case TSM_ERC_KEY_NOT_AVAILABLE:
                eRetCode = TSM_FUNC_KEY_NOT_AVAILABLE;
                break;
            case TSM_ERC_KEY_INVALID:
                eRetCode = TSM_FUNC_KEY_INVALID;
                break;
            case TSM_ERC_KEY_EMPTY:
                eRetCode = TSM_FUNC_KEY_EMPTY;
                break;
            case TSM_ERC_NO_SECURE_BOOT:
                eRetCode = TSM_FUNC_NO_SECURE_BOOT;
                break;
            case TSM_ERC_KEY_WRITE_PROTECTED:
                eRetCode = TSM_FUNC_KEY_WRITE_PROTECTED;
                break;
            case TSM_ERC_KEY_UPDATE_ERROR:
                eRetCode = TSM_FUNC_KEY_UPDATE_ERROR;
                break;
            case TSM_ERC_RNG_SEED:
                eRetCode = TSM_FUNC_RNG_SEED;
                break;
            case TSM_ERC_NO_DEBUGGING:
                eRetCode = TSM_FUNC_NO_DEBUGGING;
                break;
            case TSM_ERC_BUSY:
                eRetCode = TSM_FUNC_BUSY;
                break;
            case TSM_ERC_MEMORY_FAILURE:
                eRetCode = TSM_FUNC_MEMORY_FAILURE;
                break;
            case TSM_ERC_GENERAL_ERROR:
                eRetCode = TSM_FUNC_GENERAL_ERROR;
                break;
            default:
                eRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
                break;
          }
    }

    return eRetCode;
}

tsm_func_ret_e eTSM_CheckForErcGetData(uint32_t au32OutData[], const uint32_t u32N)
{
    tsm_func_ret_e eRetCode;
    tsm_ap_err_e    eApRetCode = TSM_AP_NO_ERROR;

    /* in case length parameter is not zero, then check for pointer being NULL */
    if ( (C_NULL == au32OutData) && (0U != u32N) )
    {
        eRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* first check if ERC is available */
        eRetCode = eTSM_CheckForErc();

        /* in case there is output data to be retrieved and no error */
        if ( (0U != u32N) && (TSM_FUNC_NO_ERROR == eRetCode) )
        {
            /* read output data from TX FIFO */
            eApRetCode = eTSM_AP_ReadTxFIFO(au32OutData, u32N);
        }
        /* check for LLDD AP error */
        if ( (TSM_AP_NO_ERROR != eApRetCode) && (TSM_FUNC_NO_ERROR == eRetCode) )
        {
            eRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
        }

    }
    return eRetCode;
}

tsm_func_ret_e eTSM_CheckForErcGetData_4Words(uint32_t au32OutData[])
{
    tsm_func_ret_e eRetCode;
    tsm_ap_err_e    eApRetCode = TSM_AP_NO_ERROR;

    /* check for pointer being NULL */
    if ( C_NULL == au32OutData )
    {
        eRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* first check if ERC is available */
        eRetCode = eTSM_CheckForErc();

        /* in case there is output data to be retrieved and no error */
        if ( TSM_FUNC_NO_ERROR == eRetCode )
        {
            /* read output data from TX FIFO */
            eApRetCode = eTSM_AP_ReadTxFIFO_4Words(au32OutData);
        }
        /* check for LLDD AP error */
        if ( (TSM_AP_NO_ERROR != eApRetCode) && (TSM_FUNC_NO_ERROR == eRetCode) )
        {
            eRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
        }

    }
    return eRetCode;
}
/****************************************************************************/
tsm_func_ret_e eTSM_GetErrorResultCode(tsm_erc_e* const peErc)
{
    tsm_ap_Erc_st     stApErc;
    tsm_erc_e         eErcStatus = TSM_ERC_GENERAL_ERROR;
    tsm_func_ret_e    eRetCode = TSM_FUNC_NO_ERROR;

    if( C_NULL == peErc )
    {
        eRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* call AP-get status and check if return value is ok: */
        if (TSM_AP_NO_ERROR == eTSM_AP_GetErcStatus_CR4(&stApErc))
        {
            /* read the returned value of ERC register (eErc_Flags): */
            eErcStatus = stApErc.eErc_Flags;

            /* check if the valid flag is not set: */
            if (C_TRUE != stApErc.eValid)
            {
                /* valid flag is not set, check if HW_BUSY flag is set: */
                if ( ((uint32_t)eErcStatus & (uint32_t)TSM_ERC_BUSY)> 0U )
                {
                    /* set Erc to TSM_ERC_BUSY */
                    eRetCode = TSM_FUNC_BUSY;
                }
                else
                {
                    /* Valid flag is not set, Hw is not busy, it means
                     * ERC value is not available. No return of ERC!: */
                    eRetCode = TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL;
                }
            }
        }
        else
        {
            /* AP-LLDD function returns any error: */
            eRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
        }

        if( TSM_FUNC_NO_ERROR == eRetCode )
        {
            *peErc = eErcStatus;

            /* Verify that the ERC is within the enum values */
            switch( eErcStatus )
            {
              case TSM_ERC_NO_ERROR:
              case TSM_ERC_SEQUENCE_ERROR:
              case TSM_ERC_KEY_NOT_AVAILABLE:
              case TSM_ERC_KEY_INVALID:
              case TSM_ERC_KEY_EMPTY:
              case TSM_ERC_NO_SECURE_BOOT:
              case TSM_ERC_KEY_WRITE_PROTECTED:
              case TSM_ERC_KEY_UPDATE_ERROR:
              case TSM_ERC_RNG_SEED:
              case TSM_ERC_NO_DEBUGGING:
              case TSM_ERC_BUSY:
              case TSM_ERC_MEMORY_FAILURE:
              case TSM_ERC_GENERAL_ERROR:
                  break;

              /*
               *  Violation of MISRA Rule 52 "Switch default label is unreachable". The parameter is transfered via a hardware FIFO
               *  as 32-bit integer, thus it may have a vlaue different than the subset as defined by the enumerated type tsm_erc_e.
               */
              default:    /* PRQA S 2018 */
                  eRetCode = TSM_FUNC_GENERAL_ERROR_ERC_WRONG;
                  break;
            }
        }
    }
    return eRetCode;
}

/****************************************************************************/

tsm_func_ret_e eTSM_CmdDecCBCInitNoWait(const tsm_key_id_e eKeyId,
                             const uint32_t au32IV[4])
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[5];

    if (C_NULL == au32IV)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* set the parameters */
        au32ParamArray[0] = (uint32_t) eKeyId;
        au32ParamArray[1] = au32IV[0];
        au32ParamArray[2] = au32IV[1];
        au32ParamArray[3] = au32IV[2];
        au32ParamArray[4] = au32IV[3];
        eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 5U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_DECRYPT_CBC;
            stSheCommand.eSubCmd = TSM_SUBCMD_INIT;
            eApRetCode = eTSM_AP_SetCommand (&stSheCommand);
        }
        /* Don't wait for ERC, if no error by access port returns OK: */
        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            eFuncRetCode = TSM_FUNC_NO_ERROR;
        }
        else
        {
            /* Error recognized: return Error Code: */
            eFuncRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
        }
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdDecCBCInitCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdDecCBCInit(const tsm_key_id_e eKeyId,
                             const uint32_t au32IV[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* make call to asynchronus API accordingly, parameter check is made inside */
    eFuncRetCode = eTSM_CmdDecCBCInitNoWait(eKeyId, au32IV);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdDecCBCInitCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/

tsm_func_ret_e eTSM_CmdDecCBCUpdateNoWait(const uint32_t au32CipherText[], const uint32_t u32BlockSizeOf128Bits)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st      stSheCommand;
    uint32_t        u32SizeInWords;
    uint32_t        au32ParamArray[1];

    u32SizeInWords = u32BlockSizeOf128Bits << 2;

    if (C_NULL == au32CipherText)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        au32ParamArray[0] = u32BlockSizeOf128Bits;
        eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 1U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* clear TX and RX FIFO */
            vTSM_AP_ClearRxFifo_CR4();
            vTSM_AP_ClearTxFifo_CR4();

            /* write input data to RX FIFO */
            eApRetCode = eTSM_AP_WriteRxFIFO(au32CipherText, u32SizeInWords);
            if (TSM_AP_NO_ERROR == eApRetCode)
            {
                /* send the command */
                stSheCommand.eCmdID = CMD_ID_NORM;
                stSheCommand.eCmd = TSM_CMD_DECRYPT_CBC;
                stSheCommand.eSubCmd = TSM_SUBCMD_UPDATE;
                eApRetCode = eTSM_AP_SetCommand (&stSheCommand);
            }
        }
        /* Don't wait for ERC, if no error by access port returns OK: */
        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            eFuncRetCode = TSM_FUNC_NO_ERROR;
        }
        else
        {
            /* Error recognized: return Error Code: */
            eFuncRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
        }
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdDecCBCUpdateCheckResult(uint32_t au32PlainText[], const uint32_t u32BlockSizeOf128Bits)
{
    tsm_func_ret_e  eFuncRetCode;
    uint32_t   u32SizeInWords;

    u32SizeInWords = u32BlockSizeOf128Bits << 2;

    if ( C_NULL == au32PlainText )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData(au32PlainText, u32SizeInWords);
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdDecCBCUpdate(const uint32_t au32CipherText[],
                                    uint32_t au32PlainText[],
                                    const uint32_t u32BlockSizeOf128Bits)
{
    tsm_func_ret_e  eFuncRetCode = TSM_FUNC_NO_ERROR;

    /* make call to asynchronus API accordingly, parameter check is made inside */
    eFuncRetCode = eTSM_CmdDecCBCUpdateNoWait(au32CipherText, u32BlockSizeOf128Bits);

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdDecCBCUpdateCheckResult(au32PlainText, u32BlockSizeOf128Bits);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}


/****************************************************************************/

tsm_func_ret_e eTSM_CmdDecCBCFinalizeNoWait(void)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_DECRYPT_CBC;
    stSheCommand.eSubCmd = TSM_SUBCMD_FINALIZE;
    eApRetCode = eTSM_AP_SetCommand (&stSheCommand);

    /* Don't wait for ERC, if no error by access port returns OK: */
    if (TSM_AP_NO_ERROR == eApRetCode)
    {
        eFuncRetCode = TSM_FUNC_NO_ERROR;
    }
    else
    {
        /* Error recognized: return Error Code: */
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdDecCBCFinalizeCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdDecCBCFinalize(void)
{
    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly */
    eFuncRetCode = eTSM_CmdDecCBCFinalizeNoWait();

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdDecCBCFinalizeCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdGetStatus(uint8_t* const pu8Status)
{
    tsm_func_ret_e eReturnVal = TSM_FUNC_NO_ERROR;
    tsm_ap_err_e eApRetVal;
    tsm_ap_status_st stStatus;
    uint8_t u8TmpStatus;

    if (C_NULL == pu8Status)
    {
        eReturnVal = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eApRetVal = eTSM_AP_GetStatus_CR4(&stStatus);
        if (TSM_AP_NO_ERROR == eApRetVal)
        {
            u8TmpStatus = 0U;
            if (C_TRUE == stStatus.eBusy) { u8TmpStatus |= (uint8_t) TSM_STATUS_BUSY; }
            if (C_TRUE == stStatus.eSecure_Boot) { u8TmpStatus |= (uint8_t) TSM_STATUS_SECURE_BOOT; }
            if (C_TRUE == stStatus.eBoot_Init) { u8TmpStatus |= (uint8_t) TSM_STATUS_BOOT_INIT; }
            if (C_TRUE == stStatus.eBoot_finished) { u8TmpStatus |= (uint8_t) TSM_STATUS_BOOT_FINISHED; }
            if (C_TRUE == stStatus.eBoot_Ok) { u8TmpStatus |= (uint8_t) TSM_STATUS_BOOT_OK; }
            if (C_TRUE == stStatus.eRnd_Init) { u8TmpStatus |= (uint8_t) TSM_STATUS_RND_INIT; }
            if (C_TRUE == stStatus.eExt_DebuggEr) { u8TmpStatus |= (uint8_t) TSM_STATUS_EXT_DEBUGGER; }
            if (C_TRUE == stStatus.eInt_DebuggEr) { u8TmpStatus |= (uint8_t) TSM_STATUS_INT_DEBUGGER; }
            *pu8Status = u8TmpStatus;
        }
        else
        {
            eReturnVal = TSM_FUNC_GENERAL_ERROR_INTERNAL;
        }
    }

    return eReturnVal;
}


/****************************************************************************/
tsm_func_ret_e eTSM_CmdBootFailureNoWait(void)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode;
    tsm_cmd_st stSheCommand;

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_BOOT_FAILURE;
    stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
    eApRetCode = eTSM_AP_SetCommand (&stSheCommand);
    /* Don't wait for ERC, if no error by access port returns OK: */
    if (TSM_AP_NO_ERROR == eApRetCode)
    {
        eFuncRetCode = TSM_FUNC_NO_ERROR;
    }
    else
    {
        /* Error recognized: return Error Code: */
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdBootFailureCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdBootFailure(void)
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* make call to the asynchronous API accordingly */
    eFuncRetCode = eTSM_CmdBootFailureNoWait();

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdBootFailureCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

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
  conditions set forth in the Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customers own risk.

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


