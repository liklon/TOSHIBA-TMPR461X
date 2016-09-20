/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : QSPI controler low level register access
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : QSPI
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.35 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef QSPIC_H
#define QSPIC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_QSPIC_H_REVISION     "$Revision: 1.35 $"
#define LLDD_QSPIC_H_TAG          "$Name: LLDD_1_6 $"

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : disable No reuse of identifiers */
#endif
/****************************************************************************
*                          CONTROLER SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/
typedef enum tag_qspic_cntrl_e
{
#ifdef FPGA
  QSPIC_CNTRL_0 = 0x0U,
  QSPIC_CNTRL_1 = 0x800U,
  QSPIC_CNTRL_2 = 0x1000
#else
  QSPIC_CNTRL_0 = 0,
  QSPIC_CNTRL_1 = 0xAF8000,  
  QSPIC_CNTRL_2 = 0x1000
#endif   
} qspic_cntrl_e;

/*********************************************/


/**********************************************
*                    Macros                   *
**********************************************/
extern void    read_burst4(int32_t i32addr, uint32_t * pu32Data);
extern void    read_burst8(int32_t i32addr, uint32_t * pu32Data);
extern void    word_write(int32_t i32addr, int32_t data);
extern void    hword_write(int32_t i32addr, int32_t data);
extern void    byte_write(int32_t i32addr, int32_t data);
extern int32_t word_read(int32_t i32addr);
extern int32_t hword_read(int32_t i32addr);
extern int32_t byte_read(int32_t i32addr);

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/* Command Operation Code */
typedef enum tag_qspic_CmdOp_e
{
  QSPI_CMD_READ_SINGLE        = 0x03,
  QSPI_CMD_FAST_READ_SINGLE   = 0x0B,
  QSPI_CMD_FAST_READ_DUAL_OUT = 0x3B,
  QSPI_CMD_FAST_READ_DUAL_IO  = 0xBB,
  QSPI_CMD_FAST_READ_QUAD_OUT = 0x6B,
  QSPI_CMD_FAST_READ_QUAD_IO  = 0xEB
} qspi_CmdOp_e;

/* SPI I/O Control */
typedef enum tag_qspic_IOCtrl_e
{
  QSPI_SINGLE = 0,
  QSPI_DUAL   = 1,
  QSPI_QUAD   = 2
} qspi_IOCtrl_e;

/* Address byte count */
typedef enum tag_qspic_AddrByte_e
{
  QSPI_ADDR_3BYTE = 0,
  QSPI_ADDR_4BYTE = 1
} qspi_AddrByte_e;

/* QSPI flash device no. */
typedef enum tag_qspic_dev_e
{
    QSPIC_DEV_0 = 0,                         /* QSPI flash on CS0 */
    QSPIC_DEV_1 = 1                          /* QSPI flash on CS1 */
} qspic_dev_e;

/* SPI flash density */
typedef enum tag_qspic_density_e
{
    /* dependant on SI_AddrByte */
    /* SI_AddrByte = 0 */
    QSPIC_64KB   = 0,                         /*  64 KB */
    QSPIC_128KB  = 1,                         /* 128 KB */
    QSPIC_256KB  = 2,                         /* 256 KB */
    QSPIC_512KB  = 3,                         /* 512 KB */
    QSPIC_1MB    = 4,                         /*   1 MB */
    QSPIC_2MB    = 5,                         /*   2 MB */
    QSPIC_4MB    = 6,                         /*   4 MB */
    QSPIC_8MB    = 7,                         /*   8 MB */
    QSPIC_16MB   = 8,                         /*  16 MB */
    /* SI_AddrByte = 1 */
    QSPIC_32MB   = 9,                         /*  32 MB */
    QSPIC_64MB   = 10,                        /*  64 MB */
    QSPIC_128MB  = 11,                        /* 128 MB */
    QSPIC_256MB  = 12                         /* 256 MB */
} qspic_density_e;

/* SPI data capture edge */
typedef enum tag_qspic_sdce_e
{
    QSPIC_1ST_POS_EDGE = 0x00,              /* data capture @ 1st positive edge */
    QSPIC_1ST_NEG_EDGE = 0x01,              /* data capture @ 1st negative edge */ 
    QSPIC_2ND_POS_EDGE = 0x02,              /* data capture @ 2nd positive edge */
    QSPIC_2ND_NEG_EDGE = 0x03               /* data capture @ 2nd negative edge */ 
} qspic_sdce_e;

/* SPI program access opcode */
typedef enum tag_qspic_opcode_e
{
    /* read */
    QSPIC_OPCODE_FAST_READ   = 0x0B,            /* Fast READ opcode */
    QSPIC_OPCODE_READ_ID     = 0x90,            /* Read ID */   
    QSPIC_OPCODE_READ_EXTID  = 0x9F,            /* Read Extended ID */
    /* write control */
    QSPIC_OPCODE_WRITE_EN    = 0x06,            /* WRITE enable */
    QSPIC_OPCODE_WRITE_DIS   = 0x04,            /* WRITE disable */
    /* erase */
    QSPIC_OPCODE_4KBS_ERASE  = 0x20,            /* 4kB sector ERASE */
    QSPIC_OPCODE_8KBS_ERASE  = 0x40,            /* 8kB sector ERASE */
    QSPIC_OPCODE_64KBS_ERASE = 0xD8,            /* 64kB sector ERASE */
    QSPIC_OPCODE_CHIP_ERASE  = 0xC7,            /* full chip ERASE opcode */
    /* program */
    QSPIC_OPCODE_PAGE_PGRM   = 0x02,            /* Page PROGRAM opcode */
    /* Status */
    QSPIC_OPCODE_RFST_READ   = 0x70,            /* Read Flag status register */
    QSPIC_OPCODE_STS_READ    = 0x05,            /* Status read opcode */
    QSPIC_OPCODE_STS_CLEAR   = 0x30,            /* Status clear */
    /* Configuration read */
    QSPIC_OPCODE_CFG_READ    = 0x35,            /* Configuration register read */
    QSPIC_OPCODE_CFGM_READ   = 0x15,            /* Configuration register read */
    /* Register write */
    QSPIC_OPCODE_WRITE_REG   = 0x01,            /* Write Configuration & Status register opcode */
    /* Release deep power down */
    QSPIC_OPCODE_RELEASE_DP  = 0xAB,            /* Release from deep power down mode */
    /* set 3/4 byte mode */
    QSPIC_OPCODE_3_BYTE_MODE  = 0xE9,           /* Enable 3-byte mode */
    QSPIC_OPCODE_4_BYTE_MODE  = 0xB7            /* Enable 4-byte mode */
} qspic_opcode_e;

/* Enable/disable */
typedef enum tag_qspic_en_e
{
    QSPIC_DISABLE = 0x0U,                       /* Disable */
    QSPIC_ENABLE  = 0x1U                        /* Enable */
} qspic_en_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/
/* SPI direct read control strucutre */
typedef struct tag_qspic_direct_rd_ctrl_st
{
    qspi_CmdOp_e     eCmd;                  /* Quad-SPI command code   */
    uint32_t         u32DummyByteCnt;       /* Number of dummy bytes   */
    qspi_AddrByte_e  eAddrByteCnt;          /* Address mode 3-/4-Byte  */
    qspi_IOCtrl_e    eSpiDatIOCtrl;         /* SPI Data I/O control    */
    qspi_IOCtrl_e    eSpiDmyIOCtrl;         /* SPI Dummy I/O control   */
    qspi_IOCtrl_e    eSpiAdrIOCtrl;         /* SPI Address I/O control */
} qspic_direct_rd_ctrl_st;

typedef struct tag_qspic_directconfig_st
{
    uint16_t                u16FlashBaseAddress;   /* physical base address (bits [31:16]), upper 4 bits are fixed and don't care */
    qspic_density_e         eFlashDensity;         /* flash density */
    qspic_en_e              eEnableMemMapRd;       /* enable memory map read */
    qspic_direct_rd_ctrl_st stRdCtrl;              /* SPI mode read */
    qspic_en_e              eWIPEnable;            /* WIP bit enable */
    uint8_t                 u8CSTime;              /* deassertion time */
    qspic_sdce_e            eEdge;                 /* capture edge */
} qspic_directconfig_st;

typedef struct tag_qspic_prgconfig_st
{
    uint8_t             u8CSTime;           /* deassertion time */
    qspic_sdce_e        eEdge;              /* capture edge */
    qspi_AddrByte_e     eAddrByteCnt;       /* Address mode 3-/4-Byte  */
} qspic_prgconfig_st;

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
 * Function:      vQSPIC_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8IORevision     - pointer to IO header revision string
 *                pau8IOTag          - pointer to IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vQSPIC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                       uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                       uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      i32QSPIC_ConfigureDirectControl
 *
 * Purpose:       does complete configuration for direct access
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *                pstDirConf     pointer to configuration for direct access
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   The base address must be aligned on a boundary that is an integer
 *                 multiple of the density of the SPI Flash selected
 *                otherwise, correct operation is not guaranteed
 *
 ***************************************************************************/
int32_t i32QSPIC_ConfigureDirectControl(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_directconfig_st *pstDirConf);

/****************************************************************************
 *
 * Function:      i32QSPIC_ConfigurePrgControl
 *
 * Purpose:       does complete configuration for program access
 *
 * Inputs:        eController     flash controller no.
 *                pstPrgConf      pointer to configuration for program access
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_ConfigurePrgControl(qspic_cntrl_e eController, qspic_prgconfig_st *pstPrgConf);

/****************************************************************************
 *
 * Function:      i32QSPIC_SetDirectFlashBaseAddress
 *
 * Purpose:       set memory mapping and flash size
 *
 * Inputs:        eController           flash controller no.
 *                eDevice               device no.
 *                u16FlashBaseAddress   physical base address (bits [31:16]), upper 4 bits are fixed and don't care
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   Specifies the base address of a CPU memory space to which SPI Flash #0/1
 *                should be mapped.
 *                The base address must be aligned on a boundary that is an integer
 *                multiple of the density of the SPI Flash selected
 *                otherwise, correct operation is not guaranteed
 *
 ***************************************************************************/
int32_t i32QSPIC_SetDirectFlashBaseAddress(qspic_cntrl_e eController, qspic_dev_e eDevice, uint16_t u16FlashBaseAddress);

/****************************************************************************
 *
 * Function:      i32QSPIC_GetDirectFlashBaseAddress 
 *
 * Purpose:       Reads memory base address of flash.
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       physical base address (bits [31:16]), upper 4 bits are fixed and don't care
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_GetDirectFlashBaseAddress(qspic_cntrl_e eController, qspic_dev_e eDevice, uint16_t * u16FlashBaseAddress);

/****************************************************************************
 *
 * Function:      i32QSPIC_SetDirectFlashDensity
 *
 * Purpose:       set flash size
 *
 * Inputs:        eController      flash controller no.
 *                eDevice          device no.
 *                eFlashDensity    flash density (size)
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_SetDirectFlashDensity(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_density_e eFlashDensity);

/****************************************************************************
 *
 * Function:      i32QSPIC_GetDirectFlashDensity 
 *
 * Purpose:       Reads flash density.
 *
 * Inputs:        eController      flash controller no.
 *                eDevice          device no.
 *
 * Outputs:       flash density (size)
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_GetDirectFlashDensity(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_density_e * eFlashDensity);

/****************************************************************************
 *
 * Function:      i32QSPIC_EnableDirectMemMapRd 
 *
 * Purpose:       Enables and disables read access.
 *                If disabled, the SPI Flash device is not memory-mapped.
 *
 * Inputs:        eController      flash controller no.
 *                eDevice          device no.
 *                eEnableMemMap    enable/disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_EnableDirectMemMapRd(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_en_e eEnableMemMap);

/****************************************************************************
 *
 * Function:      i32QSPIC_GetDirectMemMapStatusRd 
 *
 * Purpose:       Reads status of direct memory map read.
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       enable/disable
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_GetDirectMemMapStatusRd(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_en_e * eEnableMemMap);

/****************************************************************************
 *
 * Function:      i32QSPIC_SetDirectFlashMemMap
 *
 * Purpose:       set memory mapping and flash size
 *
 * Inputs:        eController            flash controller no.
 *                eDevice                device no.
 *                u16FlashBaseAddress    physical base address (bits [31:16]), upper 4 bits are fixed and don't care
 *                eFlashDensity          flash density (size)
 *                eEnableMemMapRd        enable/disable read
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   Specifies the base address of a CPU memory space to which SPI Flash #0/1
 *                should be mapped.
 *                The base address must be aligned on a boundary that is an integer
 *                multiple of the density of the SPI Flash selected
 *                otherwise, correct operation is not guaranteed
 *
 ***************************************************************************/
int32_t i32QSPIC_SetDirectFlashMemMap(qspic_cntrl_e eController, qspic_dev_e eDevice, uint16_t u16FlashBaseAddress,
                                      qspic_density_e eFlashDensity, qspic_en_e eEnableMemMapRd);

/****************************************************************************
 *
 * Function:      i32QSPIC_DirectSetReadCtrl  
 *
 * Purpose:       specifies the configuration of the read command 
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *                u32Ctrl        read control value 
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   specifies the configuration of the read command
 *                that the hardware sequencer should issue to an
 *                SPI Flash device for direct read accesses.
 *                It affects Dual I/O and Quad I/O reads
 *
 ***************************************************************************/
int32_t i32QSPIC_DirectSetReadCtrl(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32Ctrl);

/****************************************************************************
 *
 * Function:      i32QSPIC_DirectGetReadCtrl 
 *
 * Purpose:       Reads the configuration of the read command.
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       read control value
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_DirectGetReadCtrl(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t * u32Ctrl);

/****************************************************************************
 *
 * Function:      i32QSPIC_DirectEnableWIPPolling      
 *
 * Purpose:       Enables and disables the polling of the WIP bit of the
 *                status register in the SPI Flash (until the SPI Flash write
 *                is completed) before issuing a read command to it. 
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *                eEnable        enable/disable 
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_DirectEnableWIPPolling(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_en_e eEnable);

/****************************************************************************
 *
 * Function:      i32QSPIC_DirectGetStatusWIPPolling 
 *
 * Purpose:       Reads Status of WIP polling bit.
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       enable/disable
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_DirectGetStatusWIPPolling(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_en_e * eEnable);

/****************************************************************************
 *
 * Function:      i32QSPIC_DirectSetCSDeassertionTime
 *
 * Purpose:       Specifies the deassertion time of SPI_CS_N for direct access
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *                u8CSTime       numerical value = (CSTime / HBUS cycle time)
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_DirectSetCSDeassertionTime(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8CSTime);

/****************************************************************************
 *
 * Function:      i32QSPIC_DirectGetCSDeassertionTime 
 *
 * Purpose:       Reads Direct Deassertion Time.
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       numerical value = (CSTime / HBUS cycle time)
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_DirectGetCSDeassertionTime(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t * u8CSTime);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmSetCSDeassertionTime
 *
 * Purpose:       specifies the deassertion time of SPI_CS_0/1 for program access
 *
 * Inputs:        eController    flash controller no.
 *                u8CSTime       numerical value = (CSTime / HBUS cycle time) 
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmSetCSDeassertionTime(qspic_cntrl_e eController, uint8_t u8CSTime);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmGetCSDeassertionTime 
 *
 * Purpose:       Reads Program Deassertion Time.
 *
 * Inputs:        eController    flash controller no.
 *
 * Outputs:       numerical value = (CSTime / HBUS cycle time)
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmGetCSDeassertionTime(qspic_cntrl_e eController, uint8_t * u8CSTime);

/****************************************************************************
 *
 * Function:      i32QSPIC_DirectSetDataCaptureEdge
 *
 * Purpose:       Selects the active edge of SPI_CLK used to capture
 *                data on the SPI bus for direct access
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *                eEdge          1st pos. edge / 1st neg. edge 
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_DirectSetDataCaptureEdge(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_sdce_e eEdge);

/****************************************************************************
 *
 * Function:      i32QSPIC_DirectGetDataCaptureEdge 
 *
 * Purpose:       Reads Direct Capture Edge.
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       1st pos. edge / 1st neg. edge
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_DirectGetDataCaptureEdge(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_sdce_e * eEdge);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmSetDataCaptureEdge
 *
 * Purpose:       Selects the active edge of SPI_CLK used to capture
 *                data on the SPI bus for programm access
 *
 * Inputs:        eController    flash controller no.
 *                eEdge          capture edge: 1st pos. edge / 1st neg. edge
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmSetDataCaptureEdge(qspic_cntrl_e eController, qspic_sdce_e eEdge);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmGetDataCaptureEdge 
 *
 * Purpose:       Reads Program Capture Edge.
 *
 * Inputs:        eController    flash controller no.
 *
 * Outputs:       Capture edge: 1st pos. edge / 1st neg. edge
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmGetDataCaptureEdge(qspic_cntrl_e eController, qspic_sdce_e * eEdge);

/****************************************************************************
 *
 * Function:      i32QSPIC_EnableInterrupt      
 *
 * Purpose:       Enables and disables SPI interrupts generated on completion
 *                of a program register access cycle 
 *
 * Inputs:        eController    flash controller no.
 *                eEnable        enable/disable 
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   If enabled, generates an interrupt when the
 *                SPI Cycle Done bit is set to 1.
 *
 ***************************************************************************/
int32_t i32QSPIC_EnableInterrupt(qspic_cntrl_e eController, qspic_en_e eEnable);

/****************************************************************************
 *
 * Function:      i32QSPIC_GetInterruptStatus 
 *
 * Purpose:       Reads Interrupt status.
 *
 * Inputs:        eController    flash controller no.
 *
 * Outputs:       Interrupt Status
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_GetInterruptStatus(qspic_cntrl_e eController, qspic_en_e * eEnable);

/****************************************************************************
 *
 * Function:      i32QSPIC_IsSpiCycleDone 
 *
 * Purpose:       checks if SPI cycle is in progress and clears the cycle
 *                done flag.
 *
 * Inputs:        eController    flash controller no.
 *
 * Outputs:       C_TRUE or C_FALSE
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_IsSpiCycleDone(qspic_cntrl_e eController, bool_t * bResult);

/****************************************************************************
 *
 * Function:      boQSPIC_IsSpiCycleInPgrs 
 *
 * Purpose:       checks if SPI cycle is in progress 
 *
 * Inputs:        eController    flash controller no.
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boQSPIC_IsSpiCycleInPgrs(qspic_cntrl_e eController);

/****************************************************************************
 *
 * Function:      boQSPIC_IsSpiCycleDone 
 *
 * Purpose:       checks if SPI cycle is in progress and clears the cycle
 *                done flag.
 *
 * Inputs:        eController    flash controller no.
 *
 * Outputs:       none
 *
 * Return Values: CC_TRUE or C_FALSE
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boQSPIC_IsSpiCycleDone(qspic_cntrl_e eController);

/****************************************************************************
 *
 * Function:      i32QSPIC_WaitForCompletion 
 *
 * Purpose:       Wait for cycle completion of previous program access
 *
 * Inputs:        eController    flash controller no.
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_WaitForCompletion(qspic_cntrl_e eController);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmStatusRead 
 *
 * Purpose:       Retrieve the value of the status register
 *                in the addressed SPI Flash device
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       *pu8Status    status register of SPI Flash device
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmStatusRead(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8Status);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmStatusFlagRead 
 *
 * Purpose:       Retrieve the value of the status register
 *                in the addressed SPI Flash device for Micron
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       *pu8Status    status register of SPI Flash device
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmStatusFlagRead(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8Status);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmClearStatus 
 *
 * Purpose:       Clear the status register
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       None
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   None
 *
 ***************************************************************************/
extern int32_t i32QSPIC_PgrmClearStatus(qspic_cntrl_e eController, qspic_dev_e eDevice);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmReleaseDP 
 *
 * Purpose:       Release from deep sleep power mode
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       None
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   None
 *
 ***************************************************************************/
extern int32_t i32QSPIC_PgrmReleaseDP(qspic_cntrl_e eController, qspic_dev_e eDevice);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmConfigurationRead 
 *
 * Purpose:       Retrieve the current value of the configuration register
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       pu8Configuration Handle to the current configuration value
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   None
 *
 ***************************************************************************/
extern int32_t i32QSPIC_PgrmConfigurationRead(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8Configuration);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmConfigurationWrite 
 *
 * Purpose:       Modify the value of the Status and Configuration registers
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *                u8Status       Desired value of the Status register  
 *                u8Conf         Desired value of the Configuration register  
 *
 * Outputs:       pu8Configuration Handle to the current configuration value
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   None
 *
 ***************************************************************************/
extern int32_t i32QSPIC_PgrmConfigurationWrite(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8Status,  uint8_t u8Conf);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmWriteEnable
 *
 * Purpose:       Enable writing
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmWriteEnable(qspic_cntrl_e eController, qspic_dev_e eDevice);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmWriteDisable
 *
 * Purpose:       Disable writing
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmWriteDisable(qspic_cntrl_e eController, qspic_dev_e eDevice);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmSectErase
 *
 * Purpose:       SPI Flash Sector Erase
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                eOpcode           Sector erase opcode
 *                u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmSectErase(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_opcode_e eOpcode, uint32_t u32SpiPhysAddr);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmChipErase
 *
 * Purpose:       Full Chip Erase
 *
 * Inputs:        eController    flash controller no.
 *                eDevice        device no.
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmChipErase(qspic_cntrl_e eController, qspic_dev_e eDevice);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmPagePgrm
 *
 * Purpose:       Programming 256 bytes of data
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *                u16DataCount      number of bytes to be written
 *                pu8Data           pointer to data buffer to be written into
 *                                  flash device
 *
 * Outputs:       
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmPagePgrm(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint16_t u16DataCount, uint8_t* const pu8Data);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmFastRead 
 *
 * Purpose:       Perform fast reading of 256 byte of data
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *                u16DataCount      number of bytes to be written
 *
 * Outputs:       pu8Data           pointer to data buffer 
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmFastRead(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint16_t u16DataCount, uint8_t* const pu8Data);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmGetID 
 *
 * Purpose:       Retrieve device identification
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *
 * Outputs:       pu8ManID          Manufacturer ID
 *                pu8DevID          Device ID
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmGetID(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8ManID, uint8_t* const pu8DevID);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmGetExtendedID 
 *
 * Purpose:       Retrieve extended device identification
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *
 * Outputs:       pu8Information    Handle to the infromation buffer
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmGetExtendedID(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8Information);

/****************************************************************************
 *
 * Function:      i32QSPIC_WriteByte 
 *
 * Purpose:       Write one Byte to the device
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                u8Value           value to be send
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_WriteByte(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmGetRegister 
 *
 * Purpose:       Retrieve content of register
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                u8Command         command to be issued
 *                u16Count          number of bytes to be read
 *
 * Outputs:       pu8Information    Handle to the infromation buffer
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmGetRegister(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8Command, uint16_t u16Count, uint8_t* pu8Information);

/****************************************************************************
 *
 * Function:      i32QSPIC_PgrmWriteRegister 
 *
 * Purpose:       Write data
 *
 * Inputs:        eController       flash controller no.
 *                eDevice           device no.
 *                u8Command         command to be issued
 *                u16Count          number of bytes to be read
 *                pu8Information    Handle to the infromation buffer
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32QSPIC_PgrmWriteRegister(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8Command, uint16_t u16Count, uint8_t* pu8Information);

/****************************************************************************
 *
 * Function:      u32QSPIC_DirectReadWord
 *
 * Purpose:       Perform reading of one word from QSPI
 *
 * Inputs:        u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *
 * Outputs:       none
 *
 * Return Values: read word
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32QSPIC_DirectReadWord(uint32_t u32SpiPhysAddr);

/****************************************************************************
 *
 * Function:      vQSPIC_DirectReadBurst4
 *
 * Purpose:       Perform reading 4 words in burst from QSPI
 *
 * Inputs:        u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *                pu32Data          pointer to return memory
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vQSPIC_DirectReadBurst4(uint32_t u32SpiPhysAddr, uint32_t * pu32Data);

/****************************************************************************
 *
 * Function:      vQSPIC_DirectReadBurst8
 *
 * Purpose:       Perform reading 8 words in burst from QSPI
 *
 * Inputs:        u32SpiPhysAddr    addr [23:0] of phys. SPI flash device
 *                pu32Data          pointer to return memory
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vQSPIC_DirectReadBurst8(uint32_t u32SpiPhysAddr, uint32_t * pu32Data);

/****************************************************************************/


#endif /* QSPIC_H */

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

