/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : include file
*                 Access-Port Driver (internal parts valid for CM3 and R4 core,
*                                     not part of customer driver)
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : TSM
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.7 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef TSM_AP_INTERNAL_H
#define TSM_AP_INTERNAL_H


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


 /*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

/**********************************************
*                    Macros                   *
**********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/



/*! internal undocumented commands */
typedef enum tag_tsm_cmd_internal_e
{
    TSM_CMD_LOAD_KEY_UID = 0x00041,
    /*!< Load the ROM UID key  */

    TSM_CMD_LOAD_KEY_SECRET_KEY = 0x00042,
    /*!< Load the ROM Secret key */  
    
    TSM_CMD_GET_STATUS_UID  = 0x08001,
    /*!< Get UID Key status */

    TSM_CMD_GET_STATUS_SECRET_KEY   = 0x08002
    /*!< Get Secret Key status */
} tsm_cmd_internal_e;

/**********************************************
*                 Structs                   *
**********************************************/



/**********************************************
*        Exported function prototypes         *
**********************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* TSM_AP_INTERNAL_H */

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


