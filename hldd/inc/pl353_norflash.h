/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Flash access definitions
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : System
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.6 $
*   DATE        : $Date: 2015/05/04 09:07:17 $
*   TAG         : $Name: HLDD_1_1 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef PL353_NORFLASH_H
#define PL353_NORFLASH_H

/**********************************************
*                Include files                *
**********************************************/

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

/* Size of the device */
#define FLASH_SIZE_NOR                      (128*1024*1024)
#define FLASH_SECTOR_SIZE_128KB             (128*1024) 
#define FLASH_MASK_128KB                    0xFFFE0000UL

/* Base address according to the MMU table */
#define FLASH_BASEMMU_CACHED	            (0x20000000)
#define FLASH_BASEMMU_UNCACHED	            (0x20000000)

/* Device base address, according to the NORIF settings */
#define FLASH_BASE_CACHED		            (FLASH_BASEMMU_CACHED)
#define FLASH_BASE_UNCACHED		            (FLASH_BASEMMU_UNCACHED)
#define FLASH_END_CACHED                    (FLASH_BASE_CACHED + FLASH_SIZE_NOR)
#define FLASH_END_UNCACHED		            (FLASH_BASE_UNCACHED + FLASH_SIZE_NOR)

#define FLASH_BASE		                    (FLASH_BASE_UNCACHED)

/* 
 *   Registers/commands/status polling 
 *   Word mode: A0 will be always kept "low", thus the
 *   command address has to be shifted left by one, i.e.
 *   A1 will be used as LSB ad the device can recognize 
 *   the sequence!
 */
#define FLASH_ADDR_555	                    (0xAAA)     /* (0x555<<1) */
#define FLASH_ADDR_2AA	                    (0x554)     /* (0x2AA<<1) */
#define FLASH_DQ7		                    (0x80)
#define FLASH_DQ5		                    (0x20)

/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/
/* Error codes */
typedef enum tag_flash_errcodes_e
{
    FLASH_OK = 0,
    FLASH_NULL_PTR,
    FLASH_INVALID_PARAM,
    FLASH_OPERATION_ERROR,
    FLASH_TIMEOUT,
    FLASH_UNSUPPORTED_DEV,
    FLASH_UNKNWON_ERROR
} flash_errcodes_e;

/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/
/* Flash device descriptor */
typedef struct tag_flash_devdescr_st 
{                                         
    uint16_t ui16MID;                       /* Manufacturer ID */
    uint16_t ui16DID;                       /* Device ID */
} flash_devdescr_st;

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      eFLASH_Erase
 *
 * Purpose:       Erease the entire device
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: Flash success/error code
 *
 * Limitations:   none
 *
 ***************************************************************************/
extern flash_errcodes_e eFLASH_Erase(void);


/****************************************************************************
 *
 * Function:      eFLASH_EraseSectors
 *
 * Purpose:       Erase a number of sectors starting from specified address
 *
 * Inputs:        u32DeviceAddr:  Device physical address
 *                u32SectorCount: Sector count 
 *
 * Outputs:       none
 *
 * Return Values: Flash success/error code
 *
 * Limitations:   none
 *
 ***************************************************************************/
extern flash_errcodes_e eFLASH_EraseSectors(uint32_t u32DeviceAddr, uint32_t u32SectorCount);


/****************************************************************************
 *
 * Function:      eFLASH_Write
 *
 * Purpose:       Write a single 16-bit data to the specified address
 *
 * Inputs:        pui16Dest: Address
 *                ui16Data:  Data 
 *
 * Outputs:       none
 *
 * Return Values: Flash success/error code
 *
 * Limitations:   none
 *
 ***************************************************************************/
extern flash_errcodes_e eFLASH_Write(uint16_t* pui16Dest, uint16_t ui16Data);


/****************************************************************************
 *
 * Function:      eFLASH_GetID
 *
 * Purpose:       Retrieve device descriptor
 *
 * Inputs:        pstDeviceDesc: Empty decsriptor handle
 *
 * Outputs:       Device description
 *
 * Return Values: Flash success/error code
 *
 * Limitations:   none
 *
 ***************************************************************************/
extern flash_errcodes_e eFLASH_GetID(flash_devdescr_st* pstDeviceDesc);


#endif /* PL353_NORFLASH_H */

/***************************************************************************/


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
  conditions set forth in the Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (Unintended Usage).
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

