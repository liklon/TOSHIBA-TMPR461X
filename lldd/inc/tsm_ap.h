/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : include file
*                 Access-Port Driver (common parts valid for CM3 and R4 core)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      :
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.25 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSM_AP_H
#define TSM_AP_H

/**
 * @mainpage TSM Access Port-LLDD drivers
  *
 * @section This part inlcudes enumerations and structures which are
 * used by M3 core and R4 core
 *
 */

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "tsm_erc.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_TSM_AP_REVISION     "$Revision: 1.25 $"
#define LLDD_TSM_AP_TAG          "$Name: LLDD_1_6 $"


/**********************************************
*                    Macros                   *
**********************************************/
#define DP_PARAM_SIZE_MAX    32U
#define FIFO_SIZE_MAX        512U /* Size of FIFO in words (512 x 32 bits) */

/**********************************************
*                global variabes              *
**********************************************/



/**********************************************
*               Enumerations                  *
**********************************************/

/*! TSM Command Identifier */
typedef enum tag_tsm_cmdID_e
{
    CMD_ID_NORM   = 0xA9,
    /*!< Normal Command, generating IRQ towards CM3 */

    CMD_ID_CANCEL = 0xA6
    /*!< Cancel Command, generating IRQ towards CM3  */
} tsm_cmdID_e;

/*! TSM-SHE commands that uses the RX-fifo */
typedef enum tag_tsm_fifo_cmd_e
{
    TSM_CMD_FIFO_QSPI_PINS_READY = 0x0001

} tsm_fifo_cmd_e;

/*! TSM-SHE commands */
typedef enum tag_tsm_cmd_e
{
    TSM_CMD_ENCRYPT_ECB      = 0x00001,
    /*!< Encryption in ECB mode */

    TSM_CMD_ENCRYPT_CBC      = 0x00002,
    /*!< Encryption in CBC mode */

    TSM_CMD_DECRYPT_ECB      = 0x00004,
    /*!< Decryption in ECB mode */

    TSM_CMD_DECRYPT_CBC      = 0x00008,
    /*!< Decryption in CBC mode */

    TSM_CMD_GENERATE_MAC     = 0x00010,
    /*!< CMAC generation */

    TSM_CMD_VERIFY_MAC       = 0x00020,
    /*!< Verify CMAC with a reference value */

    TSM_CMD_LOAD_KEY         = 0x00040,
    /*!< Load a Key */

    TSM_CMD_LOAD_PLAIN_KEY   = 0x00080,
    /*!< Load a plain key */

    TSM_CMD_EXPORT_RAM_KEY   = 0x00100,
    /*!< export RAM key to outside */

    TSM_CMD_INIT_RNG         = 0x00200,
    /*!< Initialize Random Generator */

    TSM_CMD_EXTEND_SEED      = 0x00400,
    /*!< Extend Seed  */

    TSM_CMD_RND              = 0x00800,
    /*!< Generate a Random No. */

    TSM_CMD_SECURE_BOOT      = 0x01000,
    /*!< Secure Boot */

    TSM_CMD_BOOT_FAILURE     = 0x02000,
    /*!< Boot Failed */

    TSM_CMD_BOOT_OK          = 0x04000,
    /*!< Boot was OK */

    TSM_CMD_GET_STATUS       = 0x08000,
    /*!< Get SHE-status */

    TSM_CMD_GET_ID           = 0x10000,
    /*!< Get ID of Key */

    TSM_CMD_CANCEL           = 0x20000,
    /*!< Cancelation */

    TSM_CMD_DEBUG            = 0x40000
    /*!< Debug */

} tsm_cmd_e;

/*! TSM-SHE sub commands */
typedef enum tag_tsm_subcmd_e
{
    TSM_SUBCMD_EMPTY     = 0x00000,
    /*!< one step cmd */

    TSM_SUBCMD_INIT      = 0x00001,
    /*!< three step command: 1'st step */

    TSM_SUBCMD_UPDATE    = 0x00002,
    /*!< three step command: 2'nd step */

    TSM_SUBCMD_FINALIZE  = 0x00004,
    /*!< three step command: 3'rd step */

    TSM_SUBCMD_NON_STANDARD = 0x00008,
    /*!< one step command: special cases */
    
    TSM_SUBCMD_INVALID   = 0x0000F
    /*!< invalid subcommand */    

} tsm_subcmd_e;


/* !TSM-Type */
typedef enum tag_tsm_ap_TsmType_e
{
    TSM_L_MODE   = 0x00,
    /*!<  TSM has TSM-L-Mode functionality */

    TSM_FULL_SHE  = 0x01
    /*!<  TSM has full SHE functionality */

} tsm_ap_TsmType_e;


 /*! Errors detected by TSM Access Port-API's */
typedef enum tag_tsm_ap_err_e
{
    TSM_AP_NO_ERROR  = 0,
    /*!< Successful operation */

    TSM_AP_WRONG_PARAMS,
    /*!< Parameters not correct, including NULL pointer */

    TSM_AP_FIFO_NOT_ENOUGH_SPACE_FREE,
    /*!< It shows there are not enough free spaces in FIFO for write operation */

    TSM_AP_FIFO_NOT_ENOUGH_DATA_AVAIL,
    /*!< It shows there are not enough data in FIFO for read */

    TSM_AP_FIFO_NOT_EMPTY,
    /*!< It shows there are not enough data in FIFO for read */

    TSM_AP_WRONG_PARAMS_RANGE,
    /*!< Parameters not in range of valid data */

    TSM_AP_HW_IS_BUSY,
    /*!< HW is busy */
    
    TSM_AP_INTERNAL_ERROR
    /*!< Internal error */    

} tsm_ap_err_e;


/**********************************************
*                 Structures                  *
**********************************************/
/*! Structure for SHE command */
typedef struct tag_tsm_cmd_st
{
    tsm_cmdID_e   eCmdID;
    /*!<TSM-SHE command ID */

    tsm_cmd_e     eCmd;
    /*!<TSM-SHE command */

    tsm_subcmd_e  eSubCmd;
    /* !TSM-SHE Sub Command */

} tsm_cmd_st;


/*! Structure for ERC Flag and its status */
typedef struct tag_tsm_ap_Erc_st
{
    bool_t    eValid;
    /*!<Valid Flag */

    bool_t    eCancel;
    /*!<Cancel Flag */

    tsm_erc_e          eErc_Flags;
    /* !ERC-Status (16 bit) */

} tsm_ap_Erc_st;

/*! Enumaration for flash size type for 2 bits which can have values 00, 01, 10, 11 */
typedef enum tag_tsm_ap_FlashSizeX_e
{
    eApFlashSize_0 = 0,
    /*!< Flash Size 0 */

    eApFlashSize_1 = 1,
    /*!< Flash Size 1 */

    eApFlashSize_2 = 2,
    /*!< Flash Size 2 */

    eApFlashSize_3 = 3
    /*!< Flash Size 4 */

} tsm_ap_FlashSizeX_e;

/*! Structure for TSM-Status */
typedef struct tag_tsm_ap_status_st
{
    tsm_ap_TsmType_e   eShe;
    /*!<Shows if tsm has a full SHE functionality or not. */

    bool_t    eTsm_Ready;
    /*!<Shows if SHE is ready after booting up or not */

    bool_t    eInt_DebuggEr;
    /*!<Shows if internal debugging mechanism of SHE is activated or not */

    bool_t    eExt_DebuggEr;
    /*!<Shows if an external debugger connected to the chip */

    bool_t    eRnd_Init;
    /*!<Shows if the random generator is initialized or not */
    
    tsm_ap_FlashSizeX_e    eFlashSize;
    /*!<Integrated Flash Size */

    bool_t    eBoot_Ok;
    /*!<Shows if secure boot was successful, If CMD_BOOT_FAILURE is called the bit is erased.*/

    bool_t    eBoot_finished;
    /*!<Shows if the boot preocess has been finished */

    bool_t    eBoot_Init;
    /*!<Shows if the secure booting has been personalized during the boot sequence or not. */

    bool_t    eSecure_Boot;
    /*!<Shows if the secure booting is activated or not. */

    bool_t    eBusy;
    /*!<Shows whenever SHE is processing a command */

} tsm_ap_status_st;

/**********************************************
*        Exported function prototypes         *
**********************************************/


 #endif /* _TSM_AP_H */

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


