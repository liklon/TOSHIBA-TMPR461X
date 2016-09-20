/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : QSPI functions header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     : TSM-Driver
*   MODULE      : General
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.14 $
*   DATE        : $Date: 2015/06/24 15:14:52 $
*   TAG         : $Name: HLDD_1_1 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef _QSPI_H
#define _QSPI_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"
#include "qspic.h"
#include "ccr.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/
#define QSPI_WIP      0x1
#define QSPI_WE       0x80
#define SIZE_64KB     0x10000
#define SIZE_256B     0x100
#define MASK_64KB     0xFFFF0000

/*********************************************/

/**********************************************
*                    Macros                   *
**********************************************/

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/* qspi devices */
typedef enum qspi_dev_type_e
{
    DEV_MX25L3235E            =  1,   /* QSPI Device Type Micronix  - MX25L3235E */
    DEV_MX25L6435E            =  2,   /* QSPI Device Type Micronix  - MX25L6435E */
    DEV_MX25L12835F           =  3,   /* QSPI Device Type Micronix  - MX25L12835F */
    DEV_MX66L51239F_3BYTE_ADR =  4,   /* QSPI Device Type Micronix  - MX66L51239F 3 Byte Addressing */
    DEV_MX66L51239F_4BYTE_ADR =  5,   /* QSPI Device Type Micronix  - MX66L51239F 4 Byte Addressing */
    DEV_N25Q064A              =  6,   /* QSPI Device Type Micron    - DEV_N25Q064A new */
    DEV_N25Q512A_3BYTE_ADR    =  7,   /* QSPI Device Type Micron    - DEV_N25Q512A 3 Byte Addressing */
    DEV_N25Q512A_4BYTE_ADR    =  8,   /* QSPI Device Type Micron    - DEV_N25Q512A 4 Byte Addressing */
    DEV_S25FL032P             =  9,   /* QSPI Device Type Spansion  - S25FL032P */
    DEV_S25FL064P             = 10,   /* QSPI Device Type Spansion  - S25FL064P */
    DEV_S25FL127P             = 11,   /* QSPI Device Type Spansion  - S25FL127P */
    DEV_S25FL116KIF01         = 12,   /* QSPI Device Type Spansion  - DEV_S25FL116KIF01 */
    DEV_S25FL132KIF01         = 13,   /* QSPI Device Type Spansion  - DEV_S25FL132KIF01 */
    DEV_S25FL164KIF01         = 14,   /* QSPI Device Type Spansion  - DEV_S25FL164KIF01 */
    DEV_W25Q32B               = 15,   /* QSPI Device Type Winbond   - W25Q32B */
    DEV_W25Q64C               = 16,   /* QSPI Device Type Winbond   - W25Q64C */
    DEV_W25Q256F_3BYTE_ADR    = 17,   /* QSPI Device Type Winbond   - W25Q256F 3 Byte Addressing */
    DEV_W25Q256F_4BYTE_ADR    = 18,   /* QSPI Device Type Winbond   - W25Q256F 4 Byte Addressing */
    DEV_INTERNAL_32MBIT       = 19,   /* Internal QSPI (MX25L3235E) - 32MBit */
    DEV_INTERNAL_64MBIT       = 20,   /* Internal QSPI (MX25L6435E) - 64MBit */
    DEV_TYPE_INVALID          = 21    /* Device Invalid */
} qspi_dev_type_e;

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

/****************************************************************************
 *
 * Function:      vAssignQSPISettings
 *
 * Purpose:       assign settings dependant on
 *
 * Inputs:        u32QSPI_DeviceType   QSPI device selection (0 uses config in qspi_settings.h)
 *                u16BaseAddress       physical base address
 *
 * Outputs:       peClocFreq           pointer to clock frequence
 *                peModulationType     pointer to clock modulation type
 *                pstDirectConfig      pointer to direct interface configuration
 *                pstProgConfig        pointer to program interface configuration
 *
 * Return Values: C_SUCCESS/C_FAILED (parameter error)
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32AssignQSPISettings(qspi_dev_type_e eQSPI_DeviceType, uint16_t u16BaseAddress,
                              ccr_clk_freq_e * peClocFreq, ccr_modulated_clk_e * peModulationType,
                              qspic_directconfig_st * pstDirectConfig, qspic_prgconfig_st * pstProgConfig);

/****************************************************************************
 *
 * Function:      i32ClearFlash
 *
 * Purpose:       clears flash sector by sector
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *                u32SectorCount    number of sectors to be erased
 *
 * Outputs:       none
 *
 * Return Values: C_FAILED or C_SUCCESS
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ClearFlash(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint32_t u32SectorCount);

/****************************************************************************
 *
 * Function:      i32WriteToFlashWOE
 *
 * Purpose:       Perform program of Flash without erase
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *                u32DataCount      number of bytes to be written
 *                pu8Data           pointer to data buffer
 *
 * Outputs:       none
 *
 * Return Values: C_FAILED or C_SUCCESS
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32WriteToFlashWOE(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint32_t u32DataCount, uint8_t* const pu8Data);

/****************************************************************************
 *
 * Function:      i32WriteToFlashWE
 *
 * Purpose:       Perform program of Flash with erase
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *                u32DataCount      number of bytes to be written
 *                pu8Data           pointer to data buffer
 *
 * Outputs:       none
 *
 * Return Values: C_FAILED or C_SUCCESS
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32WriteToFlashWE(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint32_t u32DataCount, uint8_t* const pu8Data);


#endif /* _QSPI_H */


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

