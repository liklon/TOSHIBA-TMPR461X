/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION :
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     : TSM-Driver
*   MODULE      : TSM except for secure boot related
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.75 $
*   DATE        : $Date: 2015/05/04 09:07:18 $
*   TAG         : $Name:  $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "tsmdefines.h"
#include "tsmapi_rest.h"                    /* Module/SHE API definitions for user*/
#include "tsmapi_common.h"                  /* Module/SHE API definitions for user and ipl*/
#include "tsmapi_irq_dma_stream_intern.h"   /* Module helper definitions for ISR and DMA only for intern */
#include "tsm_ap.h"
#include "tsm_ap_cr4.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/
/* Major Version number is part of 16 high bits */
#define TSM_VERSION_MAJOR_SHIFT   0x10
#define TSM_VERSION_MASK          0xFFFFU
#ifndef RAM_EXECUTION
    /* TSM version is stored in ROM area */
    #define TSM_VERSION_ADDR           0xFFFFBFFCU
#else
    /* TSM version is stored in RAM area */
    #define TSM_VERSION_ADDR           0x00890004U
#endif

/* constant value for drv version. Shall be updated for every new version !! */
#define TSM_DRV_MAJOR_VERSION           0x03U
#define TSM_DRV_MINOR_VERSION           0x00U

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/


/**********************************************
*                    Macros                   *
**********************************************/

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/


/*********************************************/

/**********************************************
*             Function definition             *
*********************************************/

/****************************************************************************/
tsm_func_ret_e eTSM_CmdBootOKNoWait(void)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode;
    tsm_cmd_st stSheCommand;

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_BOOT_OK;
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

tsm_func_ret_e eTSM_CmdBootOKCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}
/****************************************************************************/
tsm_func_ret_e eTSM_CmdBootOK(void)
{
    tsm_func_ret_e  eFuncRetCode;

    /* make use of asynchronous trigger API */
    eFuncRetCode = eTSM_CmdBootOKNoWait();

    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdBootOKCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}


/****************************************************************************/

tsm_func_ret_e eTSM_CmdEncECBNoWait(const tsm_key_id_e eKeyId,
                         const uint32_t au32PlainText[4])
{
    tsm_ap_err_e    eApRetCode = TSM_AP_NO_ERROR;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;
    uint32_t u32ParamArray[1];

    if ( C_NULL == au32PlainText  )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* clear TX and RX FIFO */
        vTSM_AP_ClearRxFifo_CR4();
        vTSM_AP_ClearTxFifo_CR4();

        /* set the parameters */
        u32ParamArray[0] = (uint32_t) eKeyId;
        eApRetCode = u32TSM_AP_WriteDP_Param (&u32ParamArray[0], 1U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* write input data to RX FIFO */
            eApRetCode = eTSM_AP_WriteRxFIFO_4Words(au32PlainText);
        }

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_ENCRYPT_ECB;
            stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
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

tsm_func_ret_e eTSM_CmdEncECBCheckResult(uint32_t au32CipherText[4])
{
    tsm_func_ret_e  eFuncRetCode;

    if ( C_NULL == au32CipherText )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData_4Words(au32CipherText);
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdEncECB(const tsm_key_id_e eKeyId,
                         const uint32_t au32PlainText[4],
                         uint32_t au32CipherText[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* make call to asynchronus API accordingly, parameter check is made inside */
    eFuncRetCode = eTSM_CmdEncECBNoWait(eKeyId, au32PlainText);

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdEncECBCheckResult(au32CipherText);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}


/****************************************************************************/

tsm_func_ret_e eTSM_CmdEncCBCInitNoWait(const tsm_key_id_e eKeyId,
                             const uint32_t au32IV[4])
{
    tsm_ap_err_e    eApRetCode = TSM_AP_NO_ERROR;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;
    uint32_t u32ParamArray[5];

    if (C_NULL == au32IV)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* set the parameters */
        u32ParamArray[0] = (uint32_t) eKeyId;
        u32ParamArray[1] = au32IV[0];
        u32ParamArray[2] = au32IV[1];
        u32ParamArray[3] = au32IV[2];
        u32ParamArray[4] = au32IV[3];
        eApRetCode = u32TSM_AP_WriteDP_Param (&u32ParamArray[0], 5U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_ENCRYPT_CBC;
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

tsm_func_ret_e eTSM_CmdEncCBCInitCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdEncCBCInit(const tsm_key_id_e eKeyId,
                             const uint32_t au32IV[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* make call to asynchronus API accordingly, parameter check is made inside */
    eFuncRetCode = eTSM_CmdEncCBCInitNoWait(eKeyId, au32IV);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdEncCBCInitCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/

tsm_func_ret_e eTSM_CmdEncCBCUpdateNoWait(const uint32_t au32PlainText[], const uint32_t u32BlockSizeOf128Bits)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;
    uint32_t   u32SizeInWords;
    uint32_t   au32ParamArray[1];

    u32SizeInWords = u32BlockSizeOf128Bits << 2;

    if ( C_NULL == au32PlainText )
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
            eApRetCode = eTSM_AP_WriteRxFIFO(au32PlainText, u32SizeInWords);
            if (TSM_AP_NO_ERROR == eApRetCode)
            {
                /* send the command */
                stSheCommand.eCmdID = CMD_ID_NORM;
                stSheCommand.eCmd = TSM_CMD_ENCRYPT_CBC;
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

tsm_func_ret_e eTSM_CmdEncCBCUpdateCheckResult(uint32_t au32CipherText[], const uint32_t u32BlockSizeOf128Bits)
{
    tsm_func_ret_e  eFuncRetCode;
    uint32_t   u32SizeInWords;

    u32SizeInWords = u32BlockSizeOf128Bits << 2;

    if ( C_NULL == au32CipherText )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData(au32CipherText, u32SizeInWords);
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdEncCBCUpdate(const uint32_t au32PlainText[],
                         uint32_t au32CipherText[],
                         const uint32_t u32BlockSizeOf128Bits)
{
    tsm_func_ret_e  eFuncRetCode = TSM_FUNC_NO_ERROR;

    /* make call to asynchronus API accordingly, parameter check is made inside */
    eFuncRetCode = eTSM_CmdEncCBCUpdateNoWait(au32PlainText, u32BlockSizeOf128Bits);

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdEncCBCUpdateCheckResult(au32CipherText, u32BlockSizeOf128Bits);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/

tsm_func_ret_e eTSM_CmdEncCBCFinalizeNoWait(void)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_ENCRYPT_CBC;
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

tsm_func_ret_e eTSM_CmdEncCBCFinalizeCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdEncCBCFinalize(void)
{
    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly */
    eFuncRetCode = eTSM_CmdEncCBCFinalizeNoWait();

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdEncCBCFinalizeCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdDecECBNoWait(const tsm_key_id_e eKeyId, const uint32_t au32CipherText[4])
{
    tsm_ap_err_e    eApRetCode = TSM_AP_NO_ERROR;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[1];

    if ( C_NULL == au32CipherText )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* clear TX and RX FIFO */
        vTSM_AP_ClearRxFifo_CR4();
        vTSM_AP_ClearTxFifo_CR4();

        /* set the parameters */
        au32ParamArray[0] = (uint32_t) eKeyId;
        eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 1U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* write input data to RX FIFO */
            eApRetCode = eTSM_AP_WriteRxFIFO_4Words(au32CipherText);
        }

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_DECRYPT_ECB;
            stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
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

tsm_func_ret_e eTSM_CmdDecECBCheckResult(uint32_t au32PlainText[4])
{
    tsm_func_ret_e  eFuncRetCode;

    if ( C_NULL == au32PlainText )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData_4Words(au32PlainText);
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdDecECB(const tsm_key_id_e eKeyId,
                         const uint32_t au32CipherText[4],
                         uint32_t au32PlainText[4])
{
    tsm_func_ret_e  eFuncRetCode = TSM_FUNC_NO_ERROR;

    /* call the asynchronous API accrodingly, parameter check will be done insisde */
    eFuncRetCode = eTSM_CmdDecECBNoWait(eKeyId, au32CipherText);

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdDecECBCheckResult(au32PlainText);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdGenerateMACInitNoWait(const tsm_key_id_e eKeyId, const uint64_t u64MsgLen)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[3];

    /* set the parameters */
    au32ParamArray[0] = (uint32_t) eKeyId;
    au32ParamArray[1] = (uint32_t)(u64MsgLen & 0xFFFFFFFFU);
    au32ParamArray[2] = (uint32_t)((u64MsgLen >> 32) & 0xFFFFFFFFU);
    eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 3U);

    if (TSM_AP_NO_ERROR == eApRetCode)
    {
        /* send the command */
        stSheCommand.eCmdID = CMD_ID_NORM;
        stSheCommand.eCmd = TSM_CMD_GENERATE_MAC;
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

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdGenerateMACInitCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdGenerateMACInit(const tsm_key_id_e eKeyId, const uint64_t u64MsgLen)
{
    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly, parameters will be checked inside */
    eFuncRetCode = eTSM_CmdGenerateMACInitNoWait(eKeyId, u64MsgLen);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdGenerateMACInitCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdGenerateMACUpdateNoWait(const uint32_t au32Msg[], const uint32_t u32BlockSizeOf128Bits)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t        u32SizeInWords;
    uint32_t        au32ParamArray[1];

    u32SizeInWords = u32BlockSizeOf128Bits << 2;

    if (C_NULL == au32Msg)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        au32ParamArray[0] = u32BlockSizeOf128Bits;
        eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 1U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* clear RX FIFO */
            vTSM_AP_ClearRxFifo_CR4();

            /* write input data to RX FIFO */
            eApRetCode = eTSM_AP_WriteRxFIFO(au32Msg, u32SizeInWords);
            if (TSM_AP_NO_ERROR == eApRetCode)
            {
                /* send the command */
                stSheCommand.eCmdID = CMD_ID_NORM;
                stSheCommand.eCmd = TSM_CMD_GENERATE_MAC;
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

tsm_func_ret_e eTSM_CmdGenerateMACUpdateCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdGenerateMACUpdate(const uint32_t au32Msg[], const uint32_t u32BlockSizeOf128Bits)
{
    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly, parameters will be checked inside */
    eFuncRetCode = eTSM_CmdGenerateMACUpdateNoWait(au32Msg, u32BlockSizeOf128Bits);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdGenerateMACUpdateCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/

tsm_func_ret_e eTSM_CmdGenerateMACFinalizeNoWait(void)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;

    /* clear the TX FIFO */
    vTSM_AP_ClearTxFifo_CR4();

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_GENERATE_MAC;
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

tsm_func_ret_e eTSM_CmdGenerateMACFinalizeCheckResult(uint32_t au32MAC[4])
{
    tsm_func_ret_e  eFuncRetCode;

    if (C_NULL == au32MAC)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData(au32MAC, 4U);
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdGenerateMACFinalize(uint32_t au32MAC[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* call the asynchronous API accrodingly, parameter check will be done insisde */
    eFuncRetCode = eTSM_CmdGenerateMACFinalizeNoWait();

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdGenerateMACFinalizeCheckResult(au32MAC);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}
/****************************************************************************/
tsm_func_ret_e eTSM_CmdVerifyMACInitNoWait(const tsm_key_id_e eKeyId, const uint64_t u64MsgLen)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t u32ParamArray[3];

    /* set the parameters */
    u32ParamArray[0] = (uint32_t) eKeyId;
    u32ParamArray[1] = (uint32_t) (u64MsgLen & 0xFFFFFFFFU);
    u32ParamArray[2] = (uint32_t) ((u64MsgLen >>32) & 0xFFFFFFFFU);
    eApRetCode = u32TSM_AP_WriteDP_Param (&u32ParamArray[0], 3U);

    if (TSM_AP_NO_ERROR == eApRetCode)
    {
        /* send the command */
        stSheCommand.eCmdID = CMD_ID_NORM;
        stSheCommand.eCmd = TSM_CMD_VERIFY_MAC;
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

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdVerifyMACInitCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdVerifyMACInit(const tsm_key_id_e eKeyId, const uint64_t u64MsgLen)
{
    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly, parameters will be checked inside */
    eFuncRetCode = eTSM_CmdVerifyMACInitNoWait(eKeyId, u64MsgLen);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdVerifyMACInitCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdVerifyMACUpdateNoWait(const uint32_t au32Msg[], const uint32_t u32BlockSizeOf128Bits)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t        u32SizeInWords;
    uint32_t        au32ParamArray[1];

    u32SizeInWords = u32BlockSizeOf128Bits << 2;

    if (C_NULL == au32Msg)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        au32ParamArray[0] = u32BlockSizeOf128Bits;
        eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 1U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* clear RX FIFO */
            vTSM_AP_ClearRxFifo_CR4();

            eApRetCode = eTSM_AP_WriteRxFIFO(au32Msg, u32SizeInWords);

            if (TSM_AP_NO_ERROR == eApRetCode)
            {
                /* send the command */
                stSheCommand.eCmdID = CMD_ID_NORM;
                stSheCommand.eCmd = TSM_CMD_VERIFY_MAC;
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

tsm_func_ret_e eTSM_CmdVerifyMACUpdateCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdVerifyMACUpdate(const uint32_t au32Msg[], const uint32_t u32BlockSizeOf128Bits)
{
    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly, parameters will be checked inside */
    eFuncRetCode = eTSM_CmdVerifyMACUpdateNoWait(au32Msg, u32BlockSizeOf128Bits);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdVerifyMACUpdateCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdVerifyMACFinalizeNoWait(const uint32_t au32MAC[4], const uint32_t u32MACLen)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[5];

    if ( C_NULL == au32MAC )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* clear the TX FIFO */
        vTSM_AP_ClearTxFifo_CR4();

        /* set the parameters */
        au32ParamArray[0] = au32MAC[0];
        au32ParamArray[1] = au32MAC[1];
        au32ParamArray[2] = au32MAC[2];
        au32ParamArray[3] = au32MAC[3];
        au32ParamArray[4] = u32MACLen;
        eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 5U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_VERIFY_MAC;
            stSheCommand.eSubCmd = TSM_SUBCMD_FINALIZE;
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

tsm_func_ret_e eTSM_CmdVerifyMACFinalizeCheckResult(tsm_mac_verification_status_e* const peVerificationStatus)
{
    tsm_func_ret_e  eFuncRetCode;
    uint32_t  au32LocalVerify[4];

    if ( C_NULL == peVerificationStatus )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData(au32LocalVerify, 4U);

        if (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL != eFuncRetCode)
        {
            *peVerificationStatus = (tsm_mac_verification_status_e)au32LocalVerify[0];
        }
    }
    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdVerifyMACFinalize(const uint32_t au32MAC[4],
                                    const uint32_t u32MACLen,
                                    tsm_mac_verification_status_e* const peVerificationStatus)
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* call the asynchronous API accrodingly, parameter check will be done insisde */
    eFuncRetCode = eTSM_CmdVerifyMACFinalizeNoWait(au32MAC, u32MACLen);

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdVerifyMACFinalizeCheckResult(peVerificationStatus);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);

    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdLoadKeyNoWait(const uint32_t au32M1[4],
                          const uint32_t au32M2[8],
                          const uint32_t au32M3[4])
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[16];

    if ( (C_NULL == au32M1) || (C_NULL == au32M2) || (C_NULL == au32M3) )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* clear the TX FIFO */
        vTSM_AP_ClearTxFifo_CR4();

        /* set the parameters */
        au32ParamArray[0]  = au32M1[0];
        au32ParamArray[1]  = au32M1[1];
        au32ParamArray[2]  = au32M1[2];
        au32ParamArray[3]  = au32M1[3];
        au32ParamArray[4]  = au32M2[0];
        au32ParamArray[5]  = au32M2[1];
        au32ParamArray[6]  = au32M2[2];
        au32ParamArray[7]  = au32M2[3];
        au32ParamArray[8]  = au32M2[4];
        au32ParamArray[9]  = au32M2[5];
        au32ParamArray[10] = au32M2[6];
        au32ParamArray[11] = au32M2[7];
        au32ParamArray[12] = au32M3[0];
        au32ParamArray[13] = au32M3[1];
        au32ParamArray[14] = au32M3[2];
        au32ParamArray[15] = au32M3[3];
        eApRetCode = u32TSM_AP_WriteDP_Param(&au32ParamArray[0], 16U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_LOAD_KEY;
            stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
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

tsm_func_ret_e eTSM_CmdLoadKeyCheckResult(uint32_t au32M4[8], uint32_t au32M5[4])
{
    tsm_func_ret_e  eFuncRetCode;
    uint32_t au32M4M5[12];

    if ((C_NULL == au32M4) || (C_NULL == au32M5))
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData(au32M4M5, 12U);

        if (TSM_FUNC_NO_ERROR == eFuncRetCode)
        {
            /* copy data */
            /* M4 */
            au32M4[0] = au32M4M5[0];
            au32M4[1] = au32M4M5[1];
            au32M4[2] = au32M4M5[2];
            au32M4[3] = au32M4M5[3];
            au32M4[4] = au32M4M5[4];
            au32M4[5] = au32M4M5[5];
            au32M4[6] = au32M4M5[6];
            au32M4[7] = au32M4M5[7];
            /* M5 */
            au32M5[0] = au32M4M5[8];
            au32M5[1] = au32M4M5[9];
            au32M5[2] = au32M4M5[10];
            au32M5[3] = au32M4M5[11];
        }
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdLoadKey(const uint32_t au32M1[4],
                          const uint32_t au32M2[8],
                          const uint32_t au32M3[4],
                          uint32_t au32M4[8],
                          uint32_t au32M5[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* call the asynchronous API accrodingly, parameter check will be done inside */
    eFuncRetCode = eTSM_CmdLoadKeyNoWait(au32M1, au32M2, au32M3);

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        /* and wait for the ERC, retrieve data if applicable */
        if (TSM_FUNC_NO_ERROR == eFuncRetCode)
        {
            do
            {
                /* wait for ERC to come and retrieve output data, if appropriate */
                eFuncRetCode = eTSM_CmdLoadKeyCheckResult(au32M4, au32M5);
            } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
        }
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdLoadPlainKeyNoWait(const uint32_t au32Key[4])
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;

    if (C_NULL == au32Key)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eApRetCode = u32TSM_AP_WriteDP_Param (au32Key, 4U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_LOAD_PLAIN_KEY;
            stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
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

tsm_func_ret_e eTSM_CmdLoadPlainKeyCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdLoadPlainKey(const uint32_t au32Key[4])
{
    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly, parameters will be checked inside */
    eFuncRetCode = eTSM_CmdLoadPlainKeyNoWait(au32Key);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdLoadPlainKeyCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}
/****************************************************************************/

tsm_func_ret_e eTSM_CmdExportRAMKeyNoWait(void)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;

    /* clear the TX FIFO */
    vTSM_AP_ClearTxFifo_CR4();

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_EXPORT_RAM_KEY;
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

tsm_func_ret_e eTSM_CmdExportRAMKeyCheckResult(uint32_t au32M1[4],
                               uint32_t au32M2[8],
                               uint32_t au32M3[4],
                               uint32_t au32M4[8],
                               uint32_t au32M5[4])
{
    tsm_func_ret_e  eFuncRetCode;
    uint32_t au32M1M2M3M4M5[28];

    if ((C_NULL == au32M1) || (C_NULL == au32M2) ||
        (C_NULL == au32M3) || (C_NULL == au32M4) ||
        (C_NULL == au32M5))
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData(au32M1M2M3M4M5, 28U);

        if (TSM_FUNC_NO_ERROR == eFuncRetCode)
        {
            /* copy data */
            /* M1 */
            au32M1[0] = au32M1M2M3M4M5[0];
            au32M1[1] = au32M1M2M3M4M5[1];
            au32M1[2] = au32M1M2M3M4M5[2];
            au32M1[3] = au32M1M2M3M4M5[3];
            /* M2 */
            au32M2[0] = au32M1M2M3M4M5[4];
            au32M2[1] = au32M1M2M3M4M5[5];
            au32M2[2] = au32M1M2M3M4M5[6];
            au32M2[3] = au32M1M2M3M4M5[7];
            au32M2[4] = au32M1M2M3M4M5[8];
            au32M2[5] = au32M1M2M3M4M5[9];
            au32M2[6] = au32M1M2M3M4M5[10];
            au32M2[7] = au32M1M2M3M4M5[11];
            /* M3 */
            au32M3[0] = au32M1M2M3M4M5[12];
            au32M3[1] = au32M1M2M3M4M5[13];
            au32M3[2] = au32M1M2M3M4M5[14];
            au32M3[3] = au32M1M2M3M4M5[15];
            /* M4 */
            au32M4[0] = au32M1M2M3M4M5[16];
            au32M4[1] = au32M1M2M3M4M5[17];
            au32M4[2] = au32M1M2M3M4M5[18];
            au32M4[3] = au32M1M2M3M4M5[19];
            au32M4[4] = au32M1M2M3M4M5[20];
            au32M4[5] = au32M1M2M3M4M5[21];
            au32M4[6] = au32M1M2M3M4M5[22];
            au32M4[7] = au32M1M2M3M4M5[23];
            /* M5 */
            au32M5[0] = au32M1M2M3M4M5[24];
            au32M5[1] = au32M1M2M3M4M5[25];
            au32M5[2] = au32M1M2M3M4M5[26];
            au32M5[3] = au32M1M2M3M4M5[27];
        }
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdExportRAMKey(uint32_t au32M1[4],
                               uint32_t au32M2[8],
                               uint32_t au32M3[4],
                               uint32_t au32M4[8],
                               uint32_t au32M5[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* call the asynchronous API accrodingly, parameter check will be done inside */
    eFuncRetCode = eTSM_CmdExportRAMKeyNoWait();

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdExportRAMKeyCheckResult(au32M1, au32M2, au32M3, au32M4, au32M5);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdInitRNGNoWait(void)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_INIT_RNG;
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

tsm_func_ret_e eTSM_CmdInitRNGCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdInitRNG(void)
{

    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly, parameters will be checked inside */
    eFuncRetCode = eTSM_CmdInitRNGNoWait();

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdInitRNGCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdExtendSeedNoWait(const uint32_t au32Entropy[4])
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;

    if (C_NULL == au32Entropy)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eApRetCode = u32TSM_AP_WriteDP_Param (&au32Entropy[0], 4U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_EXTEND_SEED;
            stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
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

tsm_func_ret_e eTSM_CmdExtendSeedCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdExtendSeed(const uint32_t au32Entropy[4])
{

    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly, parameters will be checked inside */
    eFuncRetCode = eTSM_CmdExtendSeedNoWait(au32Entropy);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdExtendSeedCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdRndNoWait(void)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;

    /* clear the TX FIFO */
    vTSM_AP_ClearTxFifo_CR4();

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_RND;
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

tsm_func_ret_e eTSM_CmdRndCheckResult(uint32_t au32Rnd[4])
{
    tsm_func_ret_e  eFuncRetCode;

    if (C_NULL == au32Rnd)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData(au32Rnd, 4U);
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdRnd(uint32_t au32Rnd[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* call the asynchronous API accrodingly, parameter check will be done insisde */
    eFuncRetCode = eTSM_CmdRndNoWait();

    /* and wait for the ERC, retrieve data if applicable */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdRndCheckResult(au32Rnd);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}
/****************************************************************************/
tsm_func_ret_e eTSM_CmdGetIDNoWait(const uint32_t au32Challenge[4])
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;

    if ( C_NULL == au32Challenge )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* clear the TX FIFO */
        vTSM_AP_ClearTxFifo_CR4();

        /* set the parameters */
        eApRetCode = u32TSM_AP_WriteDP_Param (au32Challenge, 4U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_GET_ID;
            stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
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

tsm_func_ret_e eTSM_CmdGetIDCheckResult(uint32_t au32ID[4], uint8_t* const pu8SREG, uint32_t au32MAC[4])
{
    tsm_ap_err_e eApRetCode = TSM_AP_NO_ERROR;
    tsm_func_ret_e  eFuncRetCode;
    tsm_ap_status_st stTmpStatus;
    uint8_t u8TmpStatus = 0U;

    if ( (C_NULL == au32ID) || (C_NULL == pu8SREG) || (C_NULL == au32MAC) )
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* get the status */
        eApRetCode = eTSM_AP_GetStatus_CR4(&stTmpStatus);

        if ( TSM_AP_NO_ERROR == eApRetCode )
        {
            if (C_TRUE == stTmpStatus.eBusy) { u8TmpStatus |= (uint8_t) TSM_STATUS_BUSY; }
            if (C_TRUE == stTmpStatus.eSecure_Boot) { u8TmpStatus |= (uint8_t) TSM_STATUS_SECURE_BOOT; }
            if (C_TRUE == stTmpStatus.eBoot_Init) { u8TmpStatus |= (uint8_t) TSM_STATUS_BOOT_INIT; }
            if (C_TRUE == stTmpStatus.eBoot_finished) { u8TmpStatus |= (uint8_t) TSM_STATUS_BOOT_FINISHED; }
            if (C_TRUE == stTmpStatus.eBoot_Ok) { u8TmpStatus |= (uint8_t) TSM_STATUS_BOOT_OK; }
            if (C_TRUE == stTmpStatus.eRnd_Init) { u8TmpStatus |= (uint8_t) TSM_STATUS_RND_INIT; }
            if (C_TRUE == stTmpStatus.eExt_DebuggEr) { u8TmpStatus |= (uint8_t) TSM_STATUS_EXT_DEBUGGER; }
            if (C_TRUE == stTmpStatus.eInt_DebuggEr) { u8TmpStatus |= (uint8_t) TSM_STATUS_INT_DEBUGGER; }

            /* check ERC code and get data if available*/
            eFuncRetCode = eTSM_CheckForErcGetData(au32MAC, 4U);

            if( TSM_FUNC_NO_ERROR == eFuncRetCode )
            {
                /* Set the status only if cmd succeeded */
                *pu8SREG = u8TmpStatus;
                /* Get the ID from register */
                eApRetCode = eTSM_AP_GetUid_CR4(au32ID);
                if( TSM_AP_NO_ERROR != eApRetCode )
                {
                    eFuncRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
                }
            }
        }
        else
        {
            eFuncRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
        }
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdGetID(const uint32_t au32Challenge[4],
                        uint32_t au32ID[4],
                        uint8_t*  const pu8SREG,
                        uint32_t au32MAC[4])
{
    tsm_func_ret_e eFuncRetCode = TSM_FUNC_NO_ERROR;

    /* call the asynchronous API accrodingly, parameter check will be done inside */
    eFuncRetCode = eTSM_CmdGetIDNoWait(au32Challenge);

    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdGetIDCheckResult(au32ID, pu8SREG, au32MAC);
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdCancelNoWait(void)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;

    /* By Cancel Command HW will not stop the DMA transfer. The routine checks for pending DMA transfers for TSM and stops them
    * all data in the dma-fifos is lost  */
    vTSM_StopDmaTransfers ();

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_CANCEL;
    stSheCommand.eCmd = TSM_CMD_CANCEL;
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

tsm_func_ret_e eTSM_CmdCancelCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    if( TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL != eFuncRetCode )
    {
        /* By Cancel Command HW will not reset the Read/Write pointers of FIFO's. */
        /* This should be done by CR4-Driver here:                                */
        vTSM_AP_ClearRxFifo_CR4();
        vTSM_AP_ClearTxFifo_CR4();
    }

    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdCancel(void)
{
    tsm_func_ret_e eFuncRetCode;

    /* make call to the asynchronous API accordingly, parameters will be checked inside */
    eFuncRetCode = eTSM_CmdCancelNoWait();

    /* polling to get the ERC code */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdCancelCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}



/****************************************************************************/
tsm_func_ret_e eTSM_CmdDebugInitNoWait(void)
{
    tsm_ap_err_e    eApRetCode;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;

    /* clear the TX FIFO */
    vTSM_AP_ClearTxFifo_CR4();

    /* send the command */
    stSheCommand.eCmdID = CMD_ID_NORM;
    stSheCommand.eCmd = TSM_CMD_DEBUG;
    stSheCommand.eSubCmd = TSM_SUBCMD_INIT;
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

tsm_func_ret_e eTSM_CmdDebugInitCheckResult(uint32_t au32Challenge[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    if (C_NULL == au32Challenge)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        eFuncRetCode = eTSM_CheckForErcGetData(au32Challenge, 4U);
    }
    return eFuncRetCode;
}

tsm_func_ret_e eTSM_CmdDebugInit(uint32_t au32Challenge[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    if (C_NULL == au32Challenge)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* call the asynchronous API accrodingly */
        eFuncRetCode = eTSM_CmdDebugInitNoWait();

        /* and wait for the ERC, retrieve data if applicable */
        if (TSM_FUNC_NO_ERROR == eFuncRetCode)
        {
            do
            {
                /* wait for ERC to come and retrieve output data, if appropriate */
                eFuncRetCode = eTSM_CmdDebugInitCheckResult(au32Challenge);
            } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
        }
    }

    return eFuncRetCode;
}

/****************************************************************************/

tsm_func_ret_e eTSM_CmdDebugFinalizeNoWait(const uint32_t au32Authorization[4])
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[4];

    if (C_NULL == au32Authorization)
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {
        /* set the parameters */
        au32ParamArray[0] = au32Authorization[0];
        au32ParamArray[1] = au32Authorization[1];
        au32ParamArray[2] = au32Authorization[2];
        au32ParamArray[3] = au32Authorization[3];
        eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 4U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_DEBUG;
            stSheCommand.eSubCmd = TSM_SUBCMD_FINALIZE;
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

/****************************************************************************/

tsm_func_ret_e eTSM_CmdDebugFinalizeCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErcGetData(C_NULL, 0U);

    return eFuncRetCode;
}

/****************************************************************************/

tsm_func_ret_e eTSM_CmdDebugFinalize(const uint32_t au32Authorization[4])
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;

    /* make call to the asynchronous API accordingly, parameter check will be done inside  */
    eFuncRetCode = eTSM_CmdDebugFinalizeNoWait(au32Authorization);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdDebugFinalizeCheckResult();
        } while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;
}


/****************************************************************************/

tsm_func_ret_e eTSM_GetTsmVersion(uint16_t * const pu16TsmMajorVersion, uint16_t * const pu16TsmMinorVersion,
                                  uint16_t * const pu16TsmDrvMajorVersion, uint16_t * const pu16TsmDrvMinorVersion)
{
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    uint32_t u32TsmVersion;

    if ( ( C_NULL == pu16TsmMajorVersion) || (C_NULL == pu16TsmMinorVersion)
                                          ||
      ( C_NULL == pu16TsmDrvMajorVersion) || (C_NULL == pu16TsmDrvMinorVersion))
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
    }
    else
    {

        u32TsmVersion = (*((volatile uint32_t *) TSM_VERSION_ADDR ));
        /* set internal TSM version */
        *pu16TsmMajorVersion = (uint16_t) ( (u32TsmVersion >> TSM_VERSION_MAJOR_SHIFT) & TSM_VERSION_MASK);
        *pu16TsmMinorVersion = (uint16_t) (u32TsmVersion & TSM_VERSION_MASK);

        /* set driver version which is a constant value of the driver itself */
        *pu16TsmDrvMajorVersion= TSM_DRV_MAJOR_VERSION;
        *pu16TsmDrvMinorVersion= TSM_DRV_MINOR_VERSION;
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


