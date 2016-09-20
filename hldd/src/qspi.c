/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : QSPI functions
******************************************************************************
*    PLATFORM    : TMPR46xXBG-300
*   PROJECT     : TSM-Driver
*   MODULE      : General
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.21 $
*   DATE        : $Date: 2015/06/24 15:15:15 $
*   TAG         : $Name: HLDD_1_1 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
/**********************************************
*                Include files                *
**********************************************/
#include <stdio.h>
#include "qspi.h"
#include "qspic_io.h"

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
static qspi_dev_type_e  eQSPI_DeviceHldd = DEV_TYPE_INVALID;

/*********************************************/

/**********************************************
*                 Functions                   *
**********************************************/

int32_t i32AssignQSPISettings(qspi_dev_type_e eQSPI_DeviceType, uint16_t u16BaseAddress,
                              ccr_clk_freq_e * peClocFreq, ccr_modulated_clk_e * peModulationType,
                              qspic_directconfig_st * pstDirectConfig, qspic_prgconfig_st * pstProgConfig)
{
    int32_t i32Res = C_SUCCESS;
    
    /* check pointer not to be zerro: */
    if ((peClocFreq == 0) || (peModulationType == 0) ||(pstDirectConfig == 0) ||(pstProgConfig == 0) )
    {
        return C_FAILED; 
    }    
    
    /* depend on type of flash: */
    switch(eQSPI_DeviceType)
    {
        case DEV_MX25L3235E: /* MX25L3235E */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_4MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte count */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Address Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_MX25L6435E: /* MX25L6435E */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_8MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_MX25L12835F: /* MX25L12835F */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_16MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_MX66L51239F_3BYTE_ADR: /* MX66L51239F - 3 byte address mode */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_32MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */

            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_MX66L51239F_4BYTE_ADR: /* MX66L51239F - 4 byte address mode */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_64MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */

            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_4BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_4BYTE;                  /* address byte count */
            break;

        case DEV_N25Q064A: /* N25Q064A */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_39_1MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_32MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_SINGLE;  /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 1;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_SINGLE;                /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_SINGLE;                /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_SINGLE;                /* Adress Io Ctrl */

            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_N25Q512A_3BYTE_ADR: /* N25Q512A - 3 byte address mode */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_39_1MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_32MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_SINGLE;  /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 1;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_SINGLE;                /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_SINGLE;                /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_SINGLE;                /* Adress Io Ctrl */

            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_N25Q512A_4BYTE_ADR: /* N25Q512A - 4 byte address mode */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_39_1MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_64MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */

            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_SINGLE;  /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 1;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_4BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_SINGLE;                /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_SINGLE;                /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_SINGLE;                /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_4BYTE;                  /* address byte count */
            break;

        case DEV_S25FL032P: /* S25FL032P */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_4MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte count */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Address Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_S25FL064P: /* S25FL064P */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_8MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_S25FL127P: /* S25FL127P */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_16MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */

            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_S25FL132KIF01: /* S25FL132KIF01 */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_4MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte count */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Address Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_S25FL164KIF01: /* S25FL164KIF01 */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_8MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_S25FL116KIF01: /* S25FL116KIF01 */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_2MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */

            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_W25Q32B: /* W25Q32B */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_4MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte count */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Address Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_W25Q64C: /* W25Q64C */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_8MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_W25Q256F_3BYTE_ADR: /* W25Q256F - 3 byte address mode */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_32MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_W25Q256F_4BYTE_ADR: /* W25Q256F - 4 byte address mode */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_64MB;                       /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_4BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_INTERNAL_32MBIT: /* MX25L3235E internal */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_4MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte count */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Address Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        case DEV_INTERNAL_64MBIT: /* MX25L6435E internal */
            eQSPI_DeviceHldd = eQSPI_DeviceType;

            *peClocFreq       = CCR_CLKDIV_56_3MHz;
            *peModulationType = CCR_NON_MODULATED;

            pstDirectConfig->u16FlashBaseAddress = u16BaseAddress;                   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
            pstDirectConfig->eFlashDensity       = QSPIC_8MB;                        /* flash density */
            pstDirectConfig->eEnableMemMapRd     = QSPIC_ENABLE;                     /* enable memory map read */
            
            pstDirectConfig->stRdCtrl.eCmd             = QSPI_CMD_FAST_READ_QUAD_IO; /* command OP */
            pstDirectConfig->stRdCtrl.u32DummyByteCnt  = 3;                          /* dummy byte */
            pstDirectConfig->stRdCtrl.eAddrByteCnt     = QSPI_ADDR_3BYTE;            /* Address byte cuont */
            pstDirectConfig->stRdCtrl.eSpiDatIOCtrl    = QSPI_QUAD;                  /* Data Io Ctrl */
            pstDirectConfig->stRdCtrl.eSpiDmyIOCtrl    = QSPI_QUAD;                  /* Dummy Io Ctrl  */
            pstDirectConfig->stRdCtrl.eSpiAdrIOCtrl    = QSPI_QUAD;                  /* Adress Io Ctrl */
            
            pstDirectConfig->eWIPEnable          = QSPIC_DISABLE;                    /* WIP bit disable */
            pstDirectConfig->u8CSTime            = 0x20;                             /* deassertion time */
            pstDirectConfig->eEdge               = QSPIC_1ST_NEG_EDGE;               /* capture edge */

            pstProgConfig->u8CSTime              = 0x20;                             /* deassertion time */
            pstProgConfig->eEdge                 = QSPIC_1ST_NEG_EDGE;               /* capture edge */
            pstProgConfig->eAddrByteCnt          = QSPI_ADDR_3BYTE;                  /* address byte count */
            break;

        default: /* error */
            eQSPI_DeviceHldd = DEV_TYPE_INVALID;
            i32Res = C_FAILED;
            break;
    }
  return i32Res;  
}


/***************************************************************************/

int32_t i32ClearFlash(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint32_t u32SectorCount)
{
    uint16_t u16EraseIndex;
    uint8_t  *pu8Status;
    uint8_t  u8Status;
    int32_t  i32Res = C_FAILED;
    uint32_t u32BaseAddress;
    uint32_t u16SectorOffset;

    /* get status pointer */
    pu8Status = &u8Status;

    /* wait for cycle completion of previous program access */
    i32QSPIC_WaitForCompletion(eController);

    /* check status of flash */
    if ((eQSPI_DeviceHldd == DEV_N25Q512A_3BYTE_ADR) || (eQSPI_DeviceHldd == DEV_N25Q512A_4BYTE_ADR))
    {
        do {
            i32QSPIC_PgrmStatusFlagRead(eController, eDevice, pu8Status);
        } while ((u8Status&QSPI_WE) == 0);
    }
    else
    {
        do {
            i32QSPIC_PgrmStatusRead(eController, eDevice, pu8Status);
        } while ((u8Status&QSPI_WIP) == 1);
    }

    /* erase device */
    if (u32SectorCount == 0)
    {
        /* erase complete flash */
        i32QSPIC_PgrmChipErase(eController, eDevice);
    }
    else
    {
        /* calculate sector offset */
        u32BaseAddress = (biGetQSPIC_FlshMemMap0_FBA(eController) << 16);
        u16SectorOffset = (u32SpiPhysAddr - u32BaseAddress) / SIZE_64KB;

        /* erase given number of sectors */
        for (u16EraseIndex=0; u16EraseIndex<u32SectorCount; u16EraseIndex++)
        {
            /* enable writing */
            i32QSPIC_PgrmWriteEnable(eController, eDevice);

            /* erase 64KB sector */
            i32QSPIC_PgrmSectErase(eController, eDevice, QSPIC_OPCODE_64KBS_ERASE, u32SpiPhysAddr + u16EraseIndex*SIZE_64KB);

            /* display progress */
            printf("Erase sector: %d\n", u16SectorOffset + u16EraseIndex);

            /* check status of flash */
            if ((eQSPI_DeviceHldd == DEV_N25Q512A_3BYTE_ADR) || (eQSPI_DeviceHldd == DEV_N25Q512A_4BYTE_ADR))
            {
                do {
                    i32QSPIC_PgrmStatusFlagRead(eController, eDevice, pu8Status);
                } while ((u8Status&QSPI_WE) == 0);
            }
            else
            {
                do {
                    i32QSPIC_PgrmStatusRead(eController, eDevice, pu8Status);
                } while ((u8Status&QSPI_WIP) == 1);
            }
        }
    }

    i32Res = C_SUCCESS;

    return i32Res;
}


/***************************************************************************/

int32_t i32WriteToFlashWOE(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint32_t u32DataCount, uint8_t* const pu8Data)
{
    uint32_t u32ProgramIndex;
    uint32_t u32ProgramCount;
    uint16_t u16ByteCount;
    uint8_t *pu8Buffer;
    uint8_t *pu8Status;
    uint8_t u8Status;
    int32_t i32Res = C_FAILED;

    /* get result buffer pointer */
    pu8Buffer = pu8Data;

    /* get status pointer */
    pu8Status = &u8Status;

    /* check for valid data buffer pointer */
    if (C_NULL == pu8Buffer)
    {
        return i32Res;
    }

    /* wait for cycle completion of previous program access */
    i32QSPIC_WaitForCompletion(eController);

    /* check status of flash */
    if ((eQSPI_DeviceHldd == DEV_N25Q512A_3BYTE_ADR) || (eQSPI_DeviceHldd == DEV_N25Q512A_4BYTE_ADR))
    {
        do {
            i32QSPIC_PgrmStatusFlagRead(eController, eDevice, pu8Status);
        } while ((u8Status&QSPI_WE) == 0);
    }
    else
    {
        do {
            i32QSPIC_PgrmStatusRead(eController, eDevice, pu8Status);
        } while ((u8Status&QSPI_WIP) == 1);
    }

    /* calculate number of SIZE_256B blocks */
    u32ProgramCount = u32DataCount / SIZE_256B;
    if (u32DataCount % SIZE_256B != 0)
    {
    	u32ProgramCount = u32ProgramCount + 1;
    }

    /* program device */
    for (u32ProgramIndex=0; u32ProgramIndex<u32ProgramCount; u32ProgramIndex++)
    {
        /* calculate number of bytes to be written */
        if ((u32DataCount-u32ProgramIndex*SIZE_256B)>=SIZE_256B)
        {
            u16ByteCount = SIZE_256B;
        }
        else
        {
            u16ByteCount = u32DataCount - u32ProgramIndex*SIZE_256B;
        }

        /* enable writing */
        i32QSPIC_PgrmWriteEnable(eController, eDevice);

        /* write to flash */
        i32QSPIC_PgrmPagePgrm(eController, eDevice, u32SpiPhysAddr + u32ProgramIndex*SIZE_256B, u16ByteCount, (pu8Data+u32ProgramIndex*SIZE_256B));

        /* check status of flash */
        if ((eQSPI_DeviceHldd == DEV_N25Q512A_3BYTE_ADR) || (eQSPI_DeviceHldd == DEV_N25Q512A_4BYTE_ADR))
        {
            do {
                i32QSPIC_PgrmStatusFlagRead(eController, eDevice, pu8Status);
            } while ((u8Status&QSPI_WE) == 0);
        }
        else
        {
            do {
                i32QSPIC_PgrmStatusRead(eController, eDevice, pu8Status);
            } while ((u8Status&QSPI_WIP) == 1);
        }
    }

    i32Res = C_SUCCESS;

    return i32Res;
}


/***************************************************************************/

int32_t i32WriteToFlashWE(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint32_t u32DataCount, uint8_t* const pu8Data)
{
    uint16_t u16EraseIndex;
    uint16_t u16EraseSectorCount;
    uint32_t u32ProgramIndex;
    uint32_t u32ProgramCount;
    uint16_t u16ByteCount;
    uint8_t *pu8Buffer;
    uint8_t *pu8Status;
    uint8_t u8Status;
    uint8_t u8Information[2];
    int32_t i32Res = C_FAILED;

    /* get result buffer pointer */
    pu8Buffer = pu8Data;

    /* get status pointer */
    pu8Status = &u8Status;

    /* check for valid data buffer pointer */
    if (C_NULL == pu8Buffer)
    {
        return i32Res;
    }

    /* wait for cycle completion of previous program access */
    i32QSPIC_WaitForCompletion(eController);

    /* check status of flash */
    if ((eQSPI_DeviceHldd == DEV_N25Q512A_3BYTE_ADR) || (eQSPI_DeviceHldd == DEV_N25Q512A_4BYTE_ADR))
    {
        do {
            i32QSPIC_PgrmStatusFlagRead(eController, eDevice, pu8Status);
        } while ((u8Status&QSPI_WE) == 0);
    }
    else
    {
        do {
            i32QSPIC_PgrmStatusRead(eController, eDevice, pu8Status);
        } while ((u8Status&QSPI_WIP) == 1);
    }

    /* calculate number of 64KB sectors to be erased */
    u16EraseSectorCount = u32DataCount / SIZE_64KB;
    if (u32DataCount % SIZE_64KB != 0)
    {
      u16EraseSectorCount = u16EraseSectorCount + 1;
    }

    /* erase device */
    for (u16EraseIndex=0; u16EraseIndex<u16EraseSectorCount; u16EraseIndex++)
    {
        /* enable writing */
        i32QSPIC_PgrmWriteEnable(eController, eDevice);
        /* erase 64KB sector */
        i32QSPIC_PgrmSectErase(eController, eDevice, QSPIC_OPCODE_64KBS_ERASE, u32SpiPhysAddr + u16EraseIndex*SIZE_64KB);

        if ((eQSPI_DeviceHldd == DEV_N25Q512A_3BYTE_ADR) || (eQSPI_DeviceHldd == DEV_N25Q512A_4BYTE_ADR))
        {
            i32QSPIC_PgrmGetRegister(eController, eDevice, 0x70, 1, &u8Information[0]);
        }

        /* display progress */
     	  printf("Erase sector: %d\n", u16EraseIndex);

        /* check status of flash */
        if ((eQSPI_DeviceHldd == DEV_N25Q512A_3BYTE_ADR) || (eQSPI_DeviceHldd == DEV_N25Q512A_4BYTE_ADR))
        {
            do {
                i32QSPIC_PgrmStatusFlagRead(eController, eDevice, pu8Status);
            } while ((u8Status&QSPI_WE) == 0);
        }
        else
        {
            do {
                i32QSPIC_PgrmStatusRead(eController, eDevice, pu8Status);
            } while ((u8Status&QSPI_WIP) == 1);
        }
    }

    /* calculate number of SIZE_256B blocks */
    u32ProgramCount = u32DataCount / SIZE_256B;
    if (u32DataCount % SIZE_256B != 0)
    {
    	u32ProgramCount = u32ProgramCount + 1;
    }

    /* program device */
    for (u32ProgramIndex=0; u32ProgramIndex<u32ProgramCount; u32ProgramIndex++)
    {
        /* enable writing */
        i32QSPIC_PgrmWriteEnable(eController, eDevice);

        /* calculate number of bytes to be written */
        if ((u32DataCount-u32ProgramIndex*SIZE_256B)>=SIZE_256B)
        {
            u16ByteCount = SIZE_256B;
        }
        else
        {
            u16ByteCount = u32DataCount - u32ProgramIndex*SIZE_256B;
        }

        /* write to flash */
        i32QSPIC_PgrmPagePgrm(eController, eDevice, u32SpiPhysAddr + u32ProgramIndex*SIZE_256B, u16ByteCount, (pu8Data+u32ProgramIndex*SIZE_256B));

        /* check status of flash */
        if ((eQSPI_DeviceHldd == DEV_N25Q512A_3BYTE_ADR) || (eQSPI_DeviceHldd == DEV_N25Q512A_4BYTE_ADR))
        {
            do {
                i32QSPIC_PgrmStatusFlagRead(eController, eDevice, pu8Status);
            } while ((u8Status&QSPI_WE) == 0);
        }
        else
        {
            do {
                i32QSPIC_PgrmStatusRead(eController, eDevice, pu8Status);
            } while ((u8Status&QSPI_WIP) == 1);
        }
    }

    i32Res = C_SUCCESS;

    return i32Res;
}

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

