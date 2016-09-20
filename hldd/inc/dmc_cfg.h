/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : DMC functions header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Capricorn Software
*   LIBRARIES   :
******************************************************************************
*   VERSION     : $Revision: 1.3 $
*   DATE        : $Date: 2015/05/27 09:48:09 $
*   TAG         : $Name: HLDD_1_1 $
*****************************************************************************/
#ifndef DMC_CFG_H
#define DMC_CFG_H

/**********************************************
*                Include files                *
**********************************************/
#include "config.h"
#include "captypes.h"
#include "dmc.h"

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/* !< LPDDR devices */
typedef enum tag_dmc_dev_type_e
{
    DEV_MT46H8M32LFB5         =  1,   /* !< LPDDR Device Type Micronix  - MT46H8M32LFB5-6 */
    DEV_MT46H16M32LFB5        =  2,   /* !< LPDDR Device Type Micronix  - MT46H16M32LFB5-6 */
    DEV_IS42S32800D           =  3,   /* !< SDRAM Device Type Micronix  - IS42S32800D-6 */
    DEV_INVALID_TYPE          =  4    /* !< Device Invalid */
} dmc_dev_type_e;

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

/**********************************************
*   MT46H8M32LFB5-6                           *
**********************************************/
#if (RAM_DEVICE == 1)
#define DMC_DEVICE_TYPE (DEV_MT46H8M32LFB5)

/**********************************************
*   MT46H16M32LFB5-6                          *
**********************************************/
#elif (RAM_DEVICE == 2)
#define DMC_DEVICE_TYPE (DEV_MT46H16M32LFB5)

/**********************************************
*   IS42S32800D-6                             *
**********************************************/
#elif (RAM_DEVICE == 3)
#define DMC_DEVICE_TYPE (DEV_IS42S32800D)
/*********************************************/
#else
		#error Memory configuration not supported !!!
#endif

/*********************************************/

/**********************************************
*                    Macros                   *
**********************************************/

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/

/**********************************************
*            Forward declarations             *
**********************************************/

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/**
* @brief Implementation of function vDMC_Cfg
*
* Configure Memory device 
*
* @note No Limitations
*
* @param[in,out] none
*
* @return void
*/
void vDMC_Cfg(void);

/**
* @brief Implementation of function boGetMemDeviceParams
*
* Assign settings of dmc device dependant on 
*
* @note No Limitations
*
* @param[in,out] pstDeviceParams - pointer to DMC device parameters
*
* @return void C_SUCCESS in case of success
* @return void C_FAILED in case of parameter error
*/
bool_t boGetMemDeviceParams(mem_device_st *pstDeviceParams);
                         

#endif /* DMC_CFG_H */


/************************* BEGIN of DISCLAIMER   *****************************

- TOSHIBA is continually working to improve the quality and reliability of its
  products. Nevertheless, semiconductor devices in general can malfunction or
  fail due to their inherent electrical sensitivity and vulnerability to
  physical stress. It is the responsibility of the buyer, when utilizing
  TOSHIBA products, to comply with the standards of safety in making a safe
  design for the entire system, and to avoid situations in which a malfunction
  or failure of such TOSHIBA products could cause loss of human life, bodily
  injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications. Also, please keep in mind the precautions and
  conditions set forth in the ?Handling Guide for Semiconductor Devices,?
  or ?TOSHIBA Semiconductor Reliability Handbook? etc..

- The Toshiba products listed in this document are intended for usage in
 general electronics applications (computer, personal equipment, office
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.). These Toshiba products are neither intended nor warranted for usage
  in equipment that requires extraordinarily high quality and/or reliability
  or a malfunction or failure of which may cause loss of human life or bodily
  injury (?Unintended Usage?). Unintended Usage include atomic energy control
  instruments, airplane or spaceship instruments, transportation instruments,
  traffic signal instruments, combustion control instruments, medical
  instruments, all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer?s own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit, business interruption, loss of business
  information, and other pecuniary losses) occurring from the use of, or
  inability to use, this product.

- The products described in this document are subject to the foreign exchange
  and foreign trade laws.

- The products described in this document contain components made in the
  United States and subject to export control of the U.S. authorities.
  Diversion contrary to the U.S. law is prohibited.

- The information contained herein is presented only as a guide for the
  applications of our products. No responsibility is assumed by TOSHIBA
  CORPORATION for any infringements of intellectual property or other rights
  of the third parties which may result from its use. No license is granted by
  implication or otherwise under any intellectual property or other rights
  of TOSHIBA CORPORATION or others.

- The information contained herein is subject to change without notice.

****************************  END of DISCLAIMER *****************************/

