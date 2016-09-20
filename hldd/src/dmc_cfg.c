/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : DMC functions
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

/**********************************************
*                Include files                *
**********************************************/
#include "dmc_cfg.h"
#include "dmc_io.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

/*********************************************/

/**********************************************
*                    Macros                   *
**********************************************/

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*********************************************/

/**********************************************
*              Global Variables               *
**********************************************/

/*********************************************/

/**********************************************
*                 Functions                   *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section text = ".init"
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#if defined(__KEIL__)
#pragma arm section code = "init"
#else
#pragma arm section code = ".init"
#endif
#endif /* defined(__arm__) && defined(__ARMCC_VERSION) */

#define CR4DEBUG_ENABLE      // RYZ for CS/MP chip debug
void vDMC_Cfg(void)
{
    mem_device_st stDeviceParams;

    /* get parameters for device: */
    boGetMemDeviceParams(&stDeviceParams);

    /* configure device */
    vDMC_Init(&stDeviceParams);
 
#ifdef CR4DEBUG_ENABLE    
    /* Cortex R4 Debug Port enable/disable 1: Debug Port disabled 0: Debug Port enabled */
    *((volatile uint32_t *) 0xC0000410U) = 0x00;      /* enable CR4DEBUG  RYZ for CS/MP chip debug */
#endif
}


/****************************************************************************/

bool_t boGetMemDeviceParams(mem_device_st *pstDeviceParams)
{
    bool_t boResult = C_TRUE;
    dmc_dev_type_e  eDMC_DeviceType = DEV_INVALID_TYPE;    
    
    eDMC_DeviceType = DMC_DEVICE_TYPE;
    
    switch(eDMC_DeviceType)
    {
        case DEV_MT46H8M32LFB5:                                            /* DEV_MT46H8M32LFB5-6 */
            pstDeviceParams->eType            = DMC_TYPE_LPDDR;            /* MEMORY_TYPE */
            pstDeviceParams->eWidth           = DMC_BUSWIDTH_32BIT;        /* MEMORY_WIDTH */
            pstDeviceParams->eClock_rate      = DMC_CLOCK_RATE_166MHz;     /* MEMORY_CLOCK_RATE */
            pstDeviceParams->u32GearRatio_0   = 0x3ffU;                    /* GEAR_RATIO_0  */
            pstDeviceParams->u32GearRatio_1   = 0x3ffU;                    /* GEAR_RATIO_1  */
            pstDeviceParams->u32GearRatio_2   = 0x3ffU;                    /* GEAR_RATIO_2  */
            pstDeviceParams->u32GearRatio_3   = 0x3ffU;                    /* GEAR_RATIO_3  */
            pstDeviceParams->u32T_CAS         = 0x00000006U;               /* MEMORY_T_CAS */
            pstDeviceParams->u32T_RAS         = 0x00000007U;               /* MEMORY_T_RAS */
            pstDeviceParams->u32T_MRD         = 0x00000002U;               /* MEMORY_T_MRD */
            pstDeviceParams->u32T_RC          = 0x0000000BU;               /* MEMORY_T_RC  */
            pstDeviceParams->u32T_RCD         = 0x00000003U;               /* MEMORY_T_RCD */
            pstDeviceParams->u32T_RFC         = 0x00000212U;               /* MEMORY_T_RFC */
            pstDeviceParams->u32T_RP          = 0x0000001DU;               /* MEMORY_T_RP  */
            pstDeviceParams->u32T_RRD         = 0x00000002U;               /* MEMORY_T_RRD */
            pstDeviceParams->u32T_WR          = 0x00000003U;               /* MEMORY_T_WR  */
            pstDeviceParams->u32T_WTR         = 0x00000002U;               /* MEMORY_T_WTR */
            pstDeviceParams->u32T_XP          = 0x00000001U;               /* MEMORY_T_XP  */
            pstDeviceParams->u32T_XSR         = 0x0000000CU;               /* MEMORY_T_XSR */
            pstDeviceParams->u32T_ESR         = 0x00000014U;               /* MEMORY_T_ESR */
        break;
        case DEV_MT46H16M32LFB5:                                           /* DEV_MT46H16M32LFB5-6 */
            pstDeviceParams->eType            = DMC_TYPE_LPDDR;            /* MEMORY_TYPE */
            pstDeviceParams->eWidth           = DMC_BUSWIDTH_32BIT;        /* MEMORY_WIDTH */
            pstDeviceParams->eClock_rate      = DMC_CLOCK_RATE_166MHz;     /* MEMORY_CLOCK_RATE */
            pstDeviceParams->u32GearRatio_0   = 0x3ffU;                    /* GEAR_RATIO_0  */
            pstDeviceParams->u32GearRatio_1   = 0x3ffU;                    /* GEAR_RATIO_1  */
            pstDeviceParams->u32GearRatio_2   = 0x3ffU;                    /* GEAR_RATIO_2  */
            pstDeviceParams->u32GearRatio_3   = 0x3ffU;                    /* GEAR_RATIO_3  */
            pstDeviceParams->u32T_CAS         = 0x00000006U;               /* MEMORY_T_CAS */
            pstDeviceParams->u32T_RAS         = 0x00000007U;               /* MEMORY_T_RAS */
            pstDeviceParams->u32T_MRD         = 0x00000002U;               /* MEMORY_T_MRD */
            pstDeviceParams->u32T_RC          = 0x0000000BU;               /* MEMORY_T_RC  */
            pstDeviceParams->u32T_RCD         = 0x00000003U;               /* MEMORY_T_RCD */
            pstDeviceParams->u32T_RFC         = 0x00000212U;               /* MEMORY_T_RFC */
            pstDeviceParams->u32T_RP          = 0x0000001DU;               /* MEMORY_T_RP  */
            pstDeviceParams->u32T_RRD         = 0x00000002U;               /* MEMORY_T_RRD */
            pstDeviceParams->u32T_WR          = 0x00000003U;               /* MEMORY_T_WR  */
            pstDeviceParams->u32T_WTR         = 0x00000002U;               /* MEMORY_T_WTR */
            pstDeviceParams->u32T_XP          = 0x00000001U;               /* MEMORY_T_XP  */
            pstDeviceParams->u32T_XSR         = 0x0000000CU;               /* MEMORY_T_XSR */
            pstDeviceParams->u32T_ESR         = 0x00000014U;               /* MEMORY_T_ESR */
        break;
        case DEV_IS42S32800D:                                              /* DEV_IS42S32800D-6 */
            pstDeviceParams->eType            = DMC_TYPE_SDRAM;            /* MEMORY_TYPE */
            pstDeviceParams->eWidth           = DMC_BUSWIDTH_32BIT;        /* MEMORY_WIDTH */
            pstDeviceParams->eClock_rate      = DMC_CLOCK_RATE_166MHz;     /* MEMORY_CLOCK_RATE */
            pstDeviceParams->u32GearRatio_0   = 0x3ffU;                    /* GEAR_RATIO_0  */
            pstDeviceParams->u32GearRatio_1   = 0x3ffU;                    /* GEAR_RATIO_1  */
            pstDeviceParams->u32GearRatio_2   = 0x3ffU;                    /* GEAR_RATIO_2  */
            pstDeviceParams->u32GearRatio_3   = 0x3ffU;                    /* GEAR_RATIO_3  */
            pstDeviceParams->u32T_CAS         = 0x00000006U;               /* MEMORY_T_CAS */
            pstDeviceParams->u32T_RAS         = 0x00000007U;               /* MEMORY_T_RAS */
            pstDeviceParams->u32T_MRD         = 0x00000002U;               /* MEMORY_T_MRD */
            pstDeviceParams->u32T_RC          = 0x0000000BU;               /* MEMORY_T_RC  */
            pstDeviceParams->u32T_RCD         = 0x00000003U;               /* MEMORY_T_RCD */
            pstDeviceParams->u32T_RFC         = 0x00000212U;               /* MEMORY_T_RFC */
            pstDeviceParams->u32T_RP          = 0x0000001DU;               /* MEMORY_T_RP  */
            pstDeviceParams->u32T_RRD         = 0x00000002U;               /* MEMORY_T_RRD */
            pstDeviceParams->u32T_WR          = 0x00000003U;               /* MEMORY_T_WR  */
            pstDeviceParams->u32T_WTR         = 0x00000002U;               /* MEMORY_T_WTR */
            pstDeviceParams->u32T_XP          = 0x00000001U;               /* MEMORY_T_XP  */
            pstDeviceParams->u32T_XSR         = 0x0000000CU;               /* MEMORY_T_XSR */
            pstDeviceParams->u32T_ESR         = 0x00000014U;               /* MEMORY_T_ESR */
        break;
        default:
            boResult = C_TRUE;
            break;
    }
    return boResult;
}
#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section text = default
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#pragma arm section code 
#endif /* defined(__arm__) && defined(__ARMCC_VERSION) */

/***************************************************************************/


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

