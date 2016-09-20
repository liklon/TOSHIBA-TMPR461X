/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION :
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     : TSM-Driver
*   MODULE      : TSM stream api functions except for secure boot related
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.13 $
*   DATE        : $Date: 2015/07/04 09:23:29 $
*   TAG         : $Name: TSM_3_03_DRIVER_20150703_CUSTOM $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "tsmdefines.h"
#include "tsmapi_rest_stream.h"             /* Module/SHE API definitions for user*/
#include "tsmapi_common.h"                  /* Module/SHE API definitions for user and ipl*/
#include "tsmapi_irq_dma_stream.h"          /* Module API helper definitions for ISR and DMA for user */
#include "tsmapi_irq_dma_stream_intern.h"   /* Module API helper definitions for ISR and DMA for internal use */
#include "tsm_ap.h"
#include "tsm_ap_cr4.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/


/**********************************************
*                    Macros                   *
**********************************************/
#define TSM_BLOCK_SIZE_IN_WORDS                (4U)
#define TSM_MAC_SIZE_IN_WORDS                  (4U)
#define TSM_VERIFY_MAC_RESULT_SIZE_IN_WORDS    (4U)
#define TSM_MAX_128_BIT_SIZE                   (0x3FFFU)          /* maximum dma transfer size in 128 bits */
#define TSM_MAX_BIT_SIZE                       (0x1FFFE0U)        /* maximum dma transfer size in bits */
#define TSM_BIT_SIZE_TO_WORD_SIZE(bSize, wSize)  {if (0U!=((bSize) % 32U)) { (wSize) = (uint32_t)((bSize) /32U +1U);} else { (wSize) = (uint32_t) ((bSize) /32U); }}


/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

/*********************************************/
static uint32_t au32VerifyMacResultBuffer[4];
static tsm_mac_verification_status_e* peVerificationRslt;
/**********************************************
*             Function definition             *
*********************************************/


/****************************************************************************/
tsm_func_ret_e eTSM_CmdEncCBCStreamNoWait(const tsm_key_id_e eKeyId,
                                    const uint32_t au32PlainText[],
                                    const uint32_t au32CipherText[],
                                    const uint32_t au32IV[4],
                                    const uint32_t u32N)
{

    tsm_ap_err_e    eApRetCode = TSM_AP_NO_ERROR;
    tsm_func_ret_e  eFuncRetCode   = TSM_FUNC_NO_ERROR;
    tsm_cmd_st stSheCommand;
    uint32_t u32ParamArray[6];

    eFuncRetCode = TSM_FUNC_NO_ERROR;

    /* check that configuration of DMA channels and ISR for TSM are already done */
    if ( C_FALSE == bTSM_IsDMAConfigurationDone())
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR;
    }

    if ( TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        if ( (C_NULL == au32PlainText) || (C_NULL == au32CipherText) || (C_NULL == au32IV) || (0U == u32N) || (TSM_MAX_128_BIT_SIZE < u32N) )
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
            u32ParamArray[5] = u32N;
            eApRetCode = u32TSM_AP_WriteDP_Param (&u32ParamArray[0], 6U);

            if (TSM_AP_NO_ERROR == eApRetCode)
            {
                /* send the command */
                stSheCommand.eCmdID = CMD_ID_NORM;
                stSheCommand.eCmd = TSM_CMD_ENCRYPT_CBC;
                stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
                eApRetCode = eTSM_AP_SetCommand (&stSheCommand);
            }

            /* Don't wait for ERC, if no error by access port returns OK: */
            if (TSM_AP_NO_ERROR == eApRetCode)
            {
                vTSM_StartDmaTransfers(au32PlainText, (uint16_t) (u32N * TSM_BLOCK_SIZE_IN_WORDS), au32CipherText, (uint16_t) ( u32N * TSM_BLOCK_SIZE_IN_WORDS));
            }
            else
            {
                /* Error recognized: return Error Code: */
                eFuncRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
            }
        }
    }
    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdEncCBCStreamCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErc();

    if (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL != eFuncRetCode)
    {
        /* in case of erc-value available stop DMA transfer */
        vTSM_StopDmaTransfers();
    }
    
    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdEncCBCStream(const tsm_key_id_e eKeyId,
                                    const uint32_t au32PlainText[],
                                    const uint32_t au32CipherText[],
                                    const uint32_t au32IV[4],
                                    const uint32_t u32N)
{
    tsm_func_ret_e eFuncRetCode;

    eFuncRetCode = eTSM_CmdEncCBCStreamNoWait(eKeyId, &au32PlainText[0], &au32CipherText[0], &au32IV[0],u32N);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdEncCBCStreamCheckResult();
        }
        while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;

}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdDecCBCStreamNoWait(const tsm_key_id_e eKeyId,
                             const uint32_t au32CipherText[],
                             const uint32_t au32PlainText[],
                             const uint32_t au32IV[4],
                             const uint32_t u32N)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[6];

    eFuncRetCode = TSM_FUNC_NO_ERROR;

    /* check that configuration of DMA channels and ISR for TSM are already done */
    if ( C_FALSE == bTSM_IsDMAConfigurationDone())
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR;
    }

    if ( TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        if ( (C_NULL == au32CipherText) || (C_NULL == au32PlainText) || (C_NULL == au32IV) || (0U == u32N)  || (TSM_MAX_128_BIT_SIZE < u32N) )
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
            au32ParamArray[5] = u32N;
            eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 6U);

            if (TSM_AP_NO_ERROR == eApRetCode)
            {
                /* send the command */
                stSheCommand.eCmdID = CMD_ID_NORM;
                stSheCommand.eCmd = TSM_CMD_DECRYPT_CBC;
                stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
                eApRetCode = eTSM_AP_SetCommand (&stSheCommand);
            }
            /* Don't wait for ERC, if no error by access port returns OK: */
            if (TSM_AP_NO_ERROR == eApRetCode)
            {
                vTSM_StartDmaTransfers(au32CipherText, (uint16_t) (u32N * TSM_BLOCK_SIZE_IN_WORDS), au32PlainText, (uint16_t)(u32N * TSM_BLOCK_SIZE_IN_WORDS) );
            }
            else
            {
                /* Error recognized: return Error Code: */
                eFuncRetCode = TSM_FUNC_GENERAL_ERROR_INTERNAL;
            }
        }
    }
    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdDecCBCStreamCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErc();

    if (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL != eFuncRetCode)
    {
        /* in case of erc-value available stop DMA transfer */
        vTSM_StopDmaTransfers();
    }

    return eFuncRetCode;
}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdDecCBCStream(const tsm_key_id_e eKeyId,
                             const uint32_t au32CipherText[],
                             const uint32_t au32PlainText[],
                             const uint32_t au32IV[4],
                             const uint32_t u32N)
{
    tsm_func_ret_e eFuncRetCode;

    eFuncRetCode = eTSM_CmdDecCBCStreamNoWait( eKeyId, &au32CipherText[0], &au32PlainText[0], &au32IV[0], u32N);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdDecCBCStreamCheckResult();
        }
        while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;

}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdGenerateMACStreamNoWait(const tsm_key_id_e eKeyId,
                                               const uint32_t au32Msg[],
                                               const uint32_t au32Mac[4],
                                               const uint64_t u64MsgLen)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[3];
    uint32_t u32XferLen;

    eFuncRetCode = TSM_FUNC_NO_ERROR;

    /* check that configuration of DMA channels and ISR for TSM are already done */
    if ( C_FALSE == bTSM_IsDMAConfigurationDone())
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR;
    }

    if ( TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        if ( (C_NULL == au32Msg)  || (TSM_MAX_BIT_SIZE < u64MsgLen) )
        {
            eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
        }
    }

    if ( TSM_FUNC_NO_ERROR == eFuncRetCode)
    {

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
            stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
            eApRetCode = eTSM_AP_SetCommand (&stSheCommand);
        }

        /* Don't wait for ERC, if no error by access port returns OK: */
        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* calculate size in bits to word size */
            TSM_BIT_SIZE_TO_WORD_SIZE(u64MsgLen, u32XferLen)

            /* calculate transfer size in words but only multiple of 4 word transfer is allowed */
            if (0U != (u32XferLen & 0x03U))
            {
                u32XferLen = (u32XferLen ^ 0x03U) + 4U;
            }
            vTSM_StartDmaTransfers(au32Msg, (uint16_t) (u32XferLen), au32Mac, (uint16_t) (TSM_MAC_SIZE_IN_WORDS) );
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
tsm_func_ret_e eTSM_CmdGenerateMACStreamCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErc();

    if (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL != eFuncRetCode)
    {
        /* in case of erc-value available stop DMA transfer */
        vTSM_StopDmaTransfers();
    }

    return eFuncRetCode;
}


/****************************************************************************/
tsm_func_ret_e eTSM_CmdGenerateMACStream(const tsm_key_id_e eKeyId,
                                         const uint32_t au32Msg[],
                                         const uint32_t au32Mac[4],
                                         const uint64_t u64MsgLen)
{
    tsm_func_ret_e eFuncRetCode;

    eFuncRetCode = eTSM_CmdGenerateMACStreamNoWait( eKeyId, &au32Msg[0], &au32Mac[0], u64MsgLen);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdGenerateMACStreamCheckResult();
        }
        while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
    }

    return eFuncRetCode;

}

/****************************************************************************/
tsm_func_ret_e eTSM_CmdVerifyMACStreamNoWait(const tsm_key_id_e eKeyId,
                                             const uint32_t au32Msg[],
                                             const uint64_t u64MsgLen,
                                             const uint32_t au32MAC[4],
                                             const uint32_t u32MACLen,
                                             tsm_mac_verification_status_e* const peVerificationStatus)
{
    tsm_ap_err_e eApRetCode;
    tsm_func_ret_e eFuncRetCode;
    tsm_cmd_st stSheCommand;
    uint32_t au32ParamArray[8];
    uint32_t u32XferLenSrc;

    eFuncRetCode = TSM_FUNC_NO_ERROR;

    /* check that configuration of DMA channels and ISR for TSM are already done */
    if ( C_FALSE == bTSM_IsDMAConfigurationDone())
    {
        eFuncRetCode = TSM_FUNC_GENERAL_ERROR;
    }

    if ( TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        /* validate input parameter */
        if ( (0U == au32Msg) || (0U == u64MsgLen) || (C_NULL == au32MAC) || (TSM_MAX_BIT_SIZE < u64MsgLen) )
        {
            eFuncRetCode = TSM_FUNC_GENERAL_ERROR_WRONG_PARAM;
        }
    }

    if ( TSM_FUNC_NO_ERROR == eFuncRetCode)
    {

        /* set the parameters */
        au32ParamArray[0] = (uint32_t) eKeyId;
        au32ParamArray[1] = (uint32_t) (u64MsgLen & 0xFFFFFFFFU);
        au32ParamArray[2] = (uint32_t) ((u64MsgLen >>32) & 0xFFFFFFFFU);

        au32ParamArray[3] = au32MAC[0];
        au32ParamArray[4] = au32MAC[1];
        au32ParamArray[5] = au32MAC[2];
        au32ParamArray[6] = au32MAC[3];
        au32ParamArray[7] = u32MACLen;

        eApRetCode = u32TSM_AP_WriteDP_Param (&au32ParamArray[0], 8U);

        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            /* send the command */
            stSheCommand.eCmdID = CMD_ID_NORM;
            stSheCommand.eCmd = TSM_CMD_VERIFY_MAC;
            stSheCommand.eSubCmd = TSM_SUBCMD_EMPTY;
            eApRetCode = eTSM_AP_SetCommand (&stSheCommand);
        }
        /* Don't wait for ERC, if no error by access port returns OK: */
        if (TSM_AP_NO_ERROR == eApRetCode)
        {
            eFuncRetCode = TSM_FUNC_NO_ERROR;

            /* calculate size in bits to word size */
            TSM_BIT_SIZE_TO_WORD_SIZE(u64MsgLen, u32XferLenSrc)

             /* calculate transfer size in words but only multiple of 4 word transfer is allowed */
            if (0U != (u32XferLenSrc & 0x03U))
            {
                u32XferLenSrc = (u32XferLenSrc ^ 0x03U) + 4U;
            }
            /* store pointer for later use */
            peVerificationRslt = peVerificationStatus;

            vTSM_StartDmaTransfers(au32Msg, (uint16_t) (u32XferLenSrc) , au32VerifyMacResultBuffer, (uint16_t) (TSM_VERIFY_MAC_RESULT_SIZE_IN_WORDS) );
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
tsm_func_ret_e eTSM_CmdVerifyMACStreamCheckResult(void)
{
    tsm_func_ret_e  eFuncRetCode;

    eFuncRetCode = eTSM_CheckForErc();

    if (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL != eFuncRetCode)
    {
        /* in case of erc-value available stop DMA transfer */
        vTSM_StopDmaTransfers();
        *peVerificationRslt = (tsm_mac_verification_status_e)au32VerifyMacResultBuffer[0];
    }

    return eFuncRetCode;
}


/****************************************************************************/
tsm_func_ret_e eTSM_CmdVerifyMACStream(const tsm_key_id_e eKeyId,
                                       const uint32_t au32Msg[],
                                       const uint64_t u64MsgLen,
                                       const uint32_t au32MAC[4],
                                       const uint32_t u32MACLen,
                                       tsm_mac_verification_status_e* const peVerificationStatus)
{
    tsm_func_ret_e eFuncRetCode;

    eFuncRetCode = eTSM_CmdVerifyMACStreamNoWait( eKeyId, &au32Msg[0], u64MsgLen, &au32MAC[0], u32MACLen, peVerificationStatus);

    /* wait for the ERC to come */
    if (TSM_FUNC_NO_ERROR == eFuncRetCode)
    {
        do
        {
            /* wait for ERC to come and retrieve output data, if appropriate */
            eFuncRetCode = eTSM_CmdVerifyMACStreamCheckResult();
        }
        while (TSM_FUNC_GENERAL_ERROR_ERC_NOT_AVAIL == eFuncRetCode);
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


