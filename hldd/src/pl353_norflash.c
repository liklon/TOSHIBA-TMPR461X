/*****************************************************************************
*   This software is copyright protected.yright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Flash access routines
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : System
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/05/04 09:07:18 $
*   TAG         : $Name: HLDD_1_1 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include <stdio.h>                          /* Standard IO header needed by all debug prints */
#include "captypes.h"                       /* Core specific primitive type definitions */
#include "pl353_norflash.h"                 /* Own definitions */ 
#include "core.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define FLASH_ERASE_INDICATOR_INTERVAL      0x19876UL

/*********************************************/


/**********************************************
*   Local variables and forward declarations  *
**********************************************/

uint32_t u32NorDevOffset = 0;

/*********************************************/


/**********************************************
*             Function definition             *
**********************************************/

/***************************************************************************/
static flash_errcodes_e eFLASH_CheckResult(uint16_t* pui16Addr, uint16_t ui16Expect)
{
    uint16_t ui16Status;
    uint16_t u32StatusCnt = 0;

    while( 1 )
    {
        ui16Status = *pui16Addr;
        __DSB();

        if( ui16Expect == (ui16Status & FLASH_DQ7) )
        {
            return FLASH_OK;
        }
        else
        {
            /* Completed? */
            if( FLASH_DQ5 == (ui16Status & FLASH_DQ5) )
            {
                /* Re-read the status */
                ui16Status = *pui16Addr;
                __DSB();

                if( ui16Expect == (ui16Status & FLASH_DQ7) )
                {
                    return FLASH_OK;
                }
                else
                {
                    /* Timeout expired */
                    return FLASH_TIMEOUT;  
                }
            }
        }
        /* Status indication */
        u32StatusCnt++;
        if( FLASH_ERASE_INDICATOR_INTERVAL == u32StatusCnt )
        {
            printf(".");
            u32StatusCnt = 0;
        }
    }
}


/***************************************************************************/
static flash_errcodes_e eFLASH_EraseSector(uint32_t u32StartAddr)
{
    /* Send the erase command */
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x00AA;  /* Unlock cycle 1 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_2AA) = 0x0055;  /* Unlock cycle 2 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x0080;  /* Setup command */
    __DSB();

    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x00AA;  /* Unlock cycle 1 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_2AA) = 0x0055;  /* Unlock cycle 2 */
    __DSB();
    /* Start address range: 0x0000000 - 0x3FF0000 */
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + u32StartAddr) = 0x0030;    /* Sector erase command */ 
    __DSB();

    return eFLASH_CheckResult((uint16_t*)(FLASH_BASE + u32NorDevOffset), FLASH_DQ7);
}


/***************************************************************************/
flash_errcodes_e eFLASH_Erase(void)
{    
    /* Send the erase command */
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x00AA;  /* Unlock cycle 1 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_2AA) = 0x0055;  /* Unlock cycle 2 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x0080;  /* Setup command */
    __DSB();

    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x00AA;  /* Unlock cycle 1 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_2AA) = 0x0055;  /* Unlock cycle 2 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x0010;  /* Chip erase command */ 
    __DSB();

    return eFLASH_CheckResult((uint16_t*)(FLASH_BASE + u32NorDevOffset), FLASH_DQ7);
}


/***************************************************************************/
flash_errcodes_e eFLASH_EraseSectors(uint32_t u32DeviceAddr, uint32_t u32SectorCount)
{    
    flash_errcodes_e eRes = FLASH_OK;
    uint32_t u32EraseIndex;

    /* Erase the complete device */
    if( 0 == u32SectorCount )
    {
        /* erase complete flash */
        eFLASH_Erase();
    }
    else
    {
        /* Erase the require sectors only */
        for(u32EraseIndex = 0; u32EraseIndex < u32SectorCount; u32EraseIndex++)
        {
            /* Erase sector */            
            eRes = eFLASH_EraseSector(u32DeviceAddr + u32EraseIndex*FLASH_SECTOR_SIZE_128KB);           
            printf("Erase sector: %d\n", u32EraseIndex);
        }
    }

    return eRes;
}


/***************************************************************************/
flash_errcodes_e eFLASH_Write(uint16_t* pui16Dest, uint16_t ui16Data)
{    
    /* Send the command */
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x00AA; /* Unlock cycle 1 */ 
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_2AA) = 0x0055; /* Unlock cycle 2 */ 
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x00A0; /* Setup command */
    __DSB();

    /* Send the data */
    *pui16Dest = ui16Data;   
    __DSB();

    /* Poll the status */ 
    return eFLASH_CheckResult(pui16Dest, (ui16Data & FLASH_DQ7));
}


/***************************************************************************/
flash_errcodes_e eFLASH_GetID(flash_devdescr_st* pstDeviceDesc)
{
    flash_errcodes_e eRetVal = FLASH_OK;

    /* Exit autoselect/Reset command */
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset) = 0x00F0;
    __DSB();

    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x00AA; /* Unlock cycle 1 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_2AA) = 0x0055; /* Unlock cycle 2 */
    __DSB();
    *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + FLASH_ADDR_555) = 0x0090; /* Autoselect command */
    __DSB();

    if( C_NULL != pstDeviceDesc )
    {    
        pstDeviceDesc->ui16MID = *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + 0);
        __DSB();
        pstDeviceDesc->ui16DID = *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset + (1<<1));
        __DSB();

        /* Autoselect exit/Reset */
        *(volatile uint16_t*)(FLASH_BASE + u32NorDevOffset) = 0x00F0;
        __DSB();

        printf("FLASH Manufacturer ID: 0x%X\n", pstDeviceDesc->ui16MID);    
        printf("FLASH Device ID: 0x%X\n", pstDeviceDesc->ui16DID);    
        
        /* !!! Add other manufacturer if needed !!! */
        if( (0x0001 != (pstDeviceDesc->ui16MID & 0x00FF)) && (0x0020 != (pstDeviceDesc->ui16MID & 0x00FF)) )	
        {
            printf("\nERROR: Unsupported FLASH Device Manufacturer ID!\n");
            eRetVal = FLASH_UNSUPPORTED_DEV;
        }
    }
    else
    {
        eRetVal = FLASH_NULL_PTR;
    }

    return eRetVal;
}


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

