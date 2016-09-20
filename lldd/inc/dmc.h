/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : DMC low level driver header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : DMC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.14 $
*   DATE        : $Date: 2015/05/18 13:49:55 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef DMC_H
#define DMC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_DMC_H_REVISION     "$Revision: 1.14 $"
#define LLDD_DMC_H_TAG          "$Name: LLDD_1_6 $"

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1772  /* Rule 5.1 : disable identifier too long */  
#endif 
/*********************************************/

#define SDRAM_ADDRESS_BASE (0x40000000)

/**********************************************
*               Enumerations                  *
**********************************************/

/*!< enable/disable */
typedef enum tag_dmc_enable_e
{
    DMC_DISABLE = 0U,   /*!< Disable */
    DMC_ENABLE  = 1U    /*!< Enable */
} dmc_enable_e;

/*!< Low/High */
typedef enum tag_dmc_high_e
{
    DMC_LOW     = 0U,   /*!< Low */
    DMC_HIGH    = 1U    /*!< High */
} dmc_high_e;

/*!< Status definitions */
typedef enum tag_dmc_status_e
{
    DMC_STATUS_CONFIG    = 0U,   /*!< STATUS_CONFIG */
    DMC_STATUS_READY     = 1U,   /*!< STATUS_READY */
    DMC_STATUS_PAUSED    = 2U,   /*!< STATUS_PAUSED */
    DMC_STATUS_LOW_POWER = 3U    /*!< STATUS_LOW_POWER */
} dmc_status_e;

/*!< Commands */
typedef enum tag_dmc_cmd_e
{
    DMC_CMD_GO           = 0U,   /*!< Command GO */
    DMC_CMD_SLEEP        = 1U,   /*!< Command SLEEP */
    DMC_CMD_WAKEUP       = 2U,   /*!< Command WAKEUP */
    DMC_CMD_PAUSE        = 3U,   /*!< Command PAUSE */
    DMC_CMD_CONFIGURE    = 4U,   /*!< Command CONFIGURE */
    DMC_CMD_ACTIVE_PAUSE = 7U    /*!< Command ACTIVE_PAUSE */
} dmc_cmd_e;

/*!< Memory type */
typedef enum tag_dmc_type_e
{
    DMC_TYPE_SDRAM       = 0U,   /*!< SDR SDRAM */
    DMC_TYPE_LPDDR       = 3U,   /*!< LPDDR */
    DMC_TYPE_LPDDR_SDRAM = 4U   /*!< Combined SDR-LPDDR SDRAM */
} dmc_type_e;

/*!< Memory chip selects */
typedef enum tag_dmc_mem_chips_e
{
    DMC_ONE_CHIP       = 0U,   /*!< 1 Chip  */
    DMC_TWO_CHIPS      = 1U,   /*!< 2 Chips */
    DMC_THREE_CHIPS    = 2U,   /*!< 3 Chips */
    DMC_FOUR_CHIPS     = 3U    /*!< 4 Chips */
} dmc_mem_chips_e;

/*!< Memory chip selects */
typedef enum tag_dmc_mem_banks_e
{
    DMC_FOUR_BANKS     = 0U,   /*!< Four Banks */
    DMC_TWO_BANKS      = 1U    /*!< Two Banks  */
} dmc_mem_banks_e;

/*!< Access Monitor resources */
typedef enum tag_dmc_monitors_e
{
    DMC_ZERO_MONITOR   = 0U,   /*!< 0 Monitors */
    DMC_ONE_MONITOR    = 1U,   /*!< 1 Monitor  */
    DMC_TWO_MONITORS   = 2U,   /*!< 2 Monitors */
    DMC_FOUR_MONITORS  = 3U    /*!< 4 Monitors */
} dmc_monitors_e;

/*!< DMC Device commands */
typedef enum tag_dmc_direct_cmd_e
{
    DMC_PRECHARGEALL   = 0U,   /*!< PRECHARGEALL Command */
    DMC_AUTO_REFRESH   = 1U,   /*!< AUTO REFRESH Command */
    DMC_MODEREG        = 2U,   /*!< MODEREG/Extended MODEREG Command */
    DMC_NOP            = 3U,   /*!< NOP Command */
    DMC_DPD            = 4U    /*!< DPD Command */
} dmc_direct_cmd_e;

/*!< DMC Memory Configs */
typedef enum tag_dmc_mem_config_e
{
    DMC_MEM_ZERO       = 0U,   /*!< Config value: Zero */
    DMC_MEM_ONE        = 1U,   /*!< Config value: One */
    DMC_MEM_TWO        = 2U,   /*!< Config value: Two */
    DMC_MEM_THREE      = 3U,   /*!< Config value: Three */
    DMC_MEM_FOUR       = 4U,   /*!< Config value: Four */
    DMC_MEM_FIVE       = 5U   /*!< Config value: Five */
} dmc_mem_config_e;

/*!< Auto Precharge */
typedef enum tag_dmc_auto_precharge_e
{
    DMC_ADDR_BIT_10    = 0U,   /*!< address bit 10 */
    DMC_ADDR_BIT_8     = 1U   /*!< address bit 8  */
} dmc_auto_precharge_e;

/*!< Memory Protocol */
typedef enum tag_dmc_mem_protocol_e
{
    DMC_SDR_PROTOCOL   = 0U,   /*!< SDR Protocol */
    DMC_LPDDR_PROTOCOL = 3U   /*!< LPDDR Protocol */
} dmc_mem_protocol_e;

/*!< Read Delay Cycles */
typedef enum tag_dmc_read_delay_e
{
    DMC_DELAY_ONE_CYCLE   = 1U,   /*!< One Idle Cycle */
    DMC_DELAY_TWO_CYCLE   = 2U   /*!< Two Idle Cycle */
} dmc_read_delay_e;

/*!< AXI Address format */
typedef enum tag_dmc_addr_format_e
{
    DMC_ADDR_RBC   = 0U,   /*!< One Idle Cycle */
    DMC_ADDR_BRC   = 1U   /*!< Two Idle Cycle */
} dmc_addr_format_e;

/*!< Clock rate */
typedef enum tag_dmc_clock_rate_e
{
    DMC_CLOCK_RATE_166MHz = 0U,   /*!< 166 MHz */
    DMC_CLOCK_RATE_133MHz = 1U    /*!< 133 MHz */
} dmc_clock_rate_e;

/*!< Memory density */
typedef enum tag_dmc_density_e
{
    DMC_DENSITY_128Mbit = 0U,   /*!< 128 Mbit */
    DMC_DENSITY_256Mbit = 1U,   /*!< 256 Mbit */
    DMC_DENSITY_1Gbit   = 2U,   /*!< 1 Gbit */
    DMC_DENSITY_2Gbit   = 3U    /*!< 2 Gbit */
} dmc_density_e;

/*!< Bus width */
typedef enum tag_dmc_width_e
{
    DMC_BUSWIDTH_16BIT = 0U,   /*!< 16 Bit */
    DMC_BUSWIDTH_32BIT = 1U    /*!< 32 Bit */
} dmc_width_e;

/*!< SDRAM/LPDDR state */
typedef enum tag_dmc_mem_device_state_e
{
    DMC_DEV_STATE_POWER_UP        = 0U,   /*!< State POWER_UP */
    DMC_DEV_STATE_SELF_REFRESH    = 1U,   /*!< State SELF_REFRESH */
    DMC_DEV_STATE_POWER_DOWN      = 2U,   /*!< State POWER_DOWN */
    DMC_DEV_STATE_DEEP_POWER_DOWN = 3U    /*!< State DEEP_POWER_DOWN */
} dmc_mem_device_state_e;

/*!< System Controller Operating mode */
typedef enum tag_sys_ctrl_op_mode_e
{
    SYS_STATE_FULL_MODE           = 0U,   /*!< State POWER_UP */
    SYS_STATE_STOP_MODE           = 1U,   /*!< State POWER_DOWN */
    SYS_STATE_SLEEP_MODE          = 2U,   /*!< State SLEEP */
    SYS_STATE_STANDBY_MODE        = 3U   /*!< State STAND BY */
} sys_ctrl_op_mode_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/
/*!< DMC status structure */
typedef struct tag_dmc_memc_status_st
{
    dmc_status_e    eMemcStatus;        /*!< Status of DMC */
    dmc_width_e     eMemoryWidth;       /*!< Memory data bus width */
    dmc_type_e      eMemoryType;        /*!< Type of SDRAM that the DMC Supports */
    dmc_mem_chips_e eMemChips;          /*!< Number of chip selects that the DMC supports */
    dmc_mem_banks_e eMemBanks;          /*!< Number of banks that the DMC supports */
    dmc_monitors_e  eMonitors;          /*!< Number of exclusive access monitor resources */
} dmc_memc_status_st;

/*!< register description for register user_config */
typedef struct tag_dmc_user_config_bit_view_st
{
    uint32_t   gear_ratio0       : 11;  /*!<  0..10 bit(s) */
    uint32_t                     : 5;   /*!< 11..15 bit(s) */
    uint32_t   gear_ratio1       : 11;  /*!< 16..26 bit(s) */
    uint32_t                     : 5;   /*!< 27..31 bit(s) */
} dmc_user_config_bit_view_st;

/*!< register description for register user_config1 */
typedef struct tag_dmc_user_config1_bit_view_st
{
    uint32_t   gear_ratio2       : 11;  /*!<  0..10 bit(s) */
    uint32_t                     : 1;   /*!< 11  bit(s)    */
    uint32_t   enable            : 1;   /*!< 12  bit(s)    */
    uint32_t   clock_mode_change : 1;   /*!< 13  bit(s)    */
    uint32_t   use_min_delay     : 1;   /*!< 14  bit(s)    */
    uint32_t                     : 1;   /*!< 15 bit(s)     */
    uint32_t   gear_ratio3       : 11;  /*!< 16..26 bit(s) */
    uint32_t                     : 5;   /*!< 27..31 bit(s) */
} dmc_user_config1_bit_view_st;

/* Memory device stucture */
typedef struct tag_mem_device_st
{
    dmc_type_e        eType;  /* MEMORY_TYPE */
    dmc_width_e       eWidth;   /* MEMORY_WIDTH */
    dmc_clock_rate_e  eClock_rate;  /* MEMORY_CLOCK_RATE */
    uint32_t          u32GearRatio_0;  /* GEAR_RATIO_0  */
    uint32_t          u32GearRatio_1;  /* GEAR_RATIO_1  */
    uint32_t          u32GearRatio_2;  /* GEAR_RATIO_2  */
    uint32_t          u32GearRatio_3;  /* GEAR_RATIO_3  */
    uint32_t          u32T_CAS;  /* MEMORY_T_CAS */
    uint32_t          u32T_RAS;  /* MEMORY_T_RAS */
    uint32_t          u32T_MRD;  /* MEMORY_T_MRD */
    uint32_t          u32T_RC;   /* MEMORY_T_RC  */
    uint32_t          u32T_RCD;  /* MEMORY_T_RCD */
    uint32_t          u32T_RFC;  /* MEMORY_T_RFC */
    uint32_t          u32T_RP;   /* MEMORY_T_RP  */
    uint32_t          u32T_RRD;  /* MEMORY_T_RRD */
    uint32_t          u32T_WR;   /* MEMORY_T_WR  */
    uint32_t          u32T_WTR;  /* MEMORY_T_WTR */
    uint32_t          u32T_XP;   /* MEMORY_T_XP  */
    uint32_t          u32T_XSR;  /* MEMORY_T_XSR */
    uint32_t          u32T_ESR;  /* MEMORY_T_ESR */
} mem_device_st;


/*********************************************/

/**********************************************
*            Forward declarations             *
**********************************************/

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/**
* @brief Implementation of function vDMC_GetVersion
*
* Retrieve pointers to module and header revision and tag string
*
* @note No Limitations
*
* @param[in] none
*
* @param[in,out] pau8ModuleRevision - pointer to module revision string
* @param[in,out] pau8ModuleTag      - pointer to module tag string
* @param[in,out] pau8HeaderRevision - pointer to header revision string
* @param[in,out] pau8HeaderTag      - pointer to header tag string
* @param[in,out] pau8IORevision     - pointer to IO header revision string
* @param[in,out] pau8IOTag          - pointer to IO header tag string
*
* @return void
*/
void vDMC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);


/**
* @brief Implementation of function vDMC_Init
*
* Initialisation of memory controller for LPDDR/SDRAM
*
* @note No Limitations
*
* @param[in] pstDeviceParams - Pointer to memory device structure
*
* @param[in,out] none
*
* @return void
*/
void vDMC_Init(mem_device_st *pstDeviceParams);


/**
* @brief Implementation of function vDMC_MemoryDeviceInit
*
* Initializes the memory device
*
* @note No Limitations
*
* @param[in] none
*
* @param[in,out] none
*
* @return void
*/
void vDMC_MemoryDeviceInit(void);


/**
* @brief Implementation of function i32DMC_EnterDeviceMode
*
* Changes the device(lpddr/sdram) mode based on System controller's 
* operating mode
*
* @note No Limitations
*
* @param[in] eOpMode         - System controller operating mode
* @param[in] eState          - Memory device mode
* @param[in] pstDeviceParams - Pointer to memory device structure
*
* @param[in,out] none
*
* @return C_SUCCESS on success
*         C_FAILED on failure
*/
int32_t i32DMC_EnterDeviceMode(sys_ctrl_op_mode_e eOpMode, dmc_mem_device_state_e eState,
                               mem_device_st *pstDeviceParams)
;


/**
* @brief Implementation of function i32DMC_ExitDeviceMode
*
* Exit from the device(lpddr/sdram) mode based on System controller's 
* operating mode
*
* @note No Limitations
*
* @param[in] eOpMode         - System controller operating mode
* @param[in] eState          - Memory device mode
* @param[in] pstDeviceParams - Pointer to memory device structure
*
* @param[in,out] none
*
* @return C_SUCCESS on success
*         C_FAILED on failure
*/
int32_t i32DMC_ExitDeviceMode(sys_ctrl_op_mode_e eOpMode, dmc_mem_device_state_e eState,
                              mem_device_st *pstDeviceParams);


/**
* @brief Implementation of function eDMC_GetStatus
*
* Reads the status bits of the Memory Controller Status Register to 
* determine the current state of the memory controller
*
* @note No Limitations
*
* @param[in] none
*
* @param[in,out] none
*
* @return dma status
*/
dmc_status_e eDMC_GetStatus(void);


/**
* @brief Implementation of function vDMC_GetFixedConfig
*
* Reads the configuration and current state of the DMC
*
* @note No Limitations
*
* @param[in] none
*
* @param[in,out] pstMemcStatus - Pointer to DMC configuration and status
*
* @return void
*/
void vDMC_GetFixedConfig(dmc_memc_status_st *pstMemcStatus);


/**
* @brief Implementation of function vDMC_SetMemCntrlCommand
*
* Sets the operating state of the DMC
*
* @note Setting is not accessible in the Reset or Power-On Reset
*
* @param[in] eCmd - DMC Operating state
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemCntrlCommand(dmc_cmd_e eCmd);


/**
* @brief Implementation of function vDMC_SetDirectCommand
*
* Writes data to the Direct Command Register to generates 
* commands to external memory device(sdram/lpddr)
*
* @note Only accessible when DMC is in Config state
*
* @param[in] u32Value    - Memory device command information
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetDirectCommand(uint32_t u32Value);

/**
* @brief Implementation of function vDMC_SetExternalMemCommand
*
* Writes command to the Direct Command Register to generates 
* commands to external memory device(sdram/lpddr)
*
* @note Only accessible when DMC is in Config state
*
* @param[in] eDirCmd    - Memory device command
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetExternalMemCommand(dmc_direct_cmd_e eDirCmd);


/**
* @brief Implementation of function vDMC_SetChipNumber
*
* Sets the external memory chip select
*
* @note Only accessible when DMC is in Config state
*
* @param[in] u8ChipNo   - Chip Select
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetChipNumber(uint8_t u8ChipNo);


/**
* @brief Implementation of function vDMC_SetBankAddress
*
* Sets external memory bank address
*
* @note Only accessible when DMC is in Config state
*
* @param[in] u8BankAddr - External memory bank address
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetBankAddress(uint8_t u8BankAddr);


/**
* @brief Implementation of function vDMC_SetMemoryAddress
*
* Sets external memory address
*
* @note Only accessible when DMC is in Config state
*
* @param[in] u16Address - Mapped external memory address
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemoryAddress(uint16_t u16Address);


/**
* @brief Implementation of function vDMC_SetMemConfig
*
* Sets memory configuration
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u32Config  - Memory configuration
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfig(uint32_t u32Config);


/**
* @brief Implementation of function u32DMC_GetMemConfig
*
* Gets memory configuration
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] void
*
* @param[in,out] void
*
* @return memory configuration
*/
uint32_t u32DMC_GetMemConfig(void);


/**
* @brief Implementation of function vDMC_SetMemConfigActiveChips
*
* Sets number of active chips
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eActChips  - active chip
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigActiveChips(dmc_mem_chips_e eActChips);


/**
* @brief Implementation of function eDMC_GetMemConfigActiveChips
*
* Gets number of active chips
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return number of active chips
*/
dmc_mem_chips_e eDMC_GetMemConfigActiveChips(void);


/**
* @brief Implementation of function vDMC_SetMemConfigQoS
*
* Sets qos value
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eQoS  - qos value
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigQoS(dmc_mem_config_e eQoS);


/**
* @brief Implementation of function eDMC_GetMemConfigQoS
*
* Gets qos value
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return qos value
*/
dmc_mem_config_e eDMC_GetMemConfigQoS(void);


/**
* @brief Implementation of function vDMC_SetMemConfigBurst
*
* Sets the number of data accesses that DMC performs on memory
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eBurst  - number of data accesses
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigBurst(dmc_mem_config_e eBurst);


/**
* @brief Implementation of function eDMC_GetMemConfigBurst
*
* Gets the number of data accesses that DMC performs on memory
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return number of data accesses
*/
dmc_mem_config_e eDMC_GetMemConfigBurst(void);


/**
* @brief Implementation of function vDMC_SetMemConfigRowAddr
*
* Sets the row address
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eRowAddr  - Row address
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigRowAddr(dmc_mem_config_e eRowAddr);


/**
* @brief Implementation of function eDMC_GetMemConfigRowAddr
*
* Gets the row address
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return row address
*/
dmc_mem_config_e eDMC_GetMemConfigRowAddr(void);


/**
* @brief Implementation of function vDMC_SetMemConfigColAddr
*
* Sets the column address
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eColAddr  - Column address
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigColAddr(dmc_mem_config_e eColAddr);


/**
* @brief Implementation of function eDMC_GetMemConfigColAddr
*
* Gets the column address
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return Column address
*/
dmc_mem_config_e eDMC_GetMemConfigColAddr(void);


/**
* @brief Implementation of function vDMC_SetMemConfigStopClk
*
* Enable/Disable the memory clock to stop dynamically
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eColAddr  - Column address
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigStopClk(dmc_enable_e eStopClk);


/**
* @brief Implementation of function eDMC_GetMemConfigStopClk
*
* Gets memory clock state whether its enabled/disabled to stop dynamically
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return memory clock state
*/
dmc_enable_e eDMC_GetMemConfigStopClk(void);


/**
* @brief Implementation of function vDMC_SetMemConfigAutoPowerDown
*
* Sets the number of memory clock cycles for auto power-down
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] ePoweDown  - Number of memory clock cycles
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigAutoPowerDown(dmc_enable_e ePoweDown);


/**
* @brief Implementation of function eDMC_GetMemConfigAutoPowerDown
*
* Gets the number of memory clock cycles that set for auto power-down
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return Number of memory clock cycles
*/
dmc_enable_e eDMC_GetMemConfigAutoPowerDown(void);


/**
* @brief Implementation of function vDMC_SetMemConfigAutoPreCharge
*
* Sets the position of the auto-precharge bit in the memory address
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] ePrecharge  - auto-precharge bit position
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigAutoPreCharge(dmc_auto_precharge_e ePrecharge);


/**
* @brief Implementation of function eDMC_GetMemConfigAutoPreCharge
*
* Gets the position of the auto-precharge bit in the memory address
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the position of the auto-precharge bit
*/
dmc_auto_precharge_e eDMC_GetMemConfigAutoPreCharge(void);


/**
* @brief Implementation of function vDMC_SetMemConfigPwrDownPrd
*
* Sets the number of memory clock cycles for auto power-down
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8PwrDownPrd  - Number of memory clock cycles
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfigPwrDownPrd(uint8_t u8PwrDownPrd);


/**
* @brief Implementation of function u8DMC_GetMemConfigPwrDownPrd
*
* Gets the number of memory clock cycles that set for auto power-down
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return Number of memory clock cycles
*/
uint8_t u8DMC_GetMemConfigPwrDownPrd(void);


/**
* @brief Implementation of function vDMC_SetRefreshPeriod
*
* Sets the refresh period
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u16RefPrd  - Refresh period
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetRefreshPeriod(uint16_t u16RefPrd);


/**
* @brief Implementation of function u16DMC_GetRefreshPeriod
*
* Gets the refresh period
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the refresh period
*/
uint16_t u16DMC_GetRefreshPeriod(void);


/**
* @brief Implementation of function vDMC_SetCASLatency
*
* Sets the CAS latency time in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8CASLatency  - CAS latency time
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetCASLatency(uint8_t u8CASLatency);


/**
* @brief Implementation of function u8DMC_GetCASLatency
*
* Gets CAS latency time in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the CAS latency time
*/
uint8_t u8DMC_GetCASLatency(void);


/**
* @brief Implementation of function vDMC_SetCASHalfCycle
*
* Sets the CAS latency time as 2.5
*
* @note Only accessible when DMC is in Config/Low power state,
* use only when DMC accesses DDR devices and cas_latency field=2.
*
* @param[in] eHalfCycle  - CAS latency time
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetCASHalfCycle(dmc_enable_e eHalfCycle);


/**
* @brief Implementation of function eDMC_GetCASHalfCycle
*
* Checks whether CAS latency half cycle is enabled/disabled or not
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the CAS latency half cycle enable/disable status
*/
dmc_enable_e eDMC_GetCASHalfCycle(void);


/**
* @brief Implementation of function vDMC_SetDQSTiming
*
* Sets the DQS delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8CASLatency  - CAS latency time
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetDQSTiming(uint8_t u8DQSTiming);


/**
* @brief Implementation of function u8DMC_GetDQSTiming
*
* Gets DQS delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the DQS delay
*/
uint8_t u8DMC_GetDQSTiming(void);


/**
* @brief Implementation of function vDMC_SetModeRegTiming
*
* Sets MODEREG to command delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - MODEREG to command delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetModeRegTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetModeRegTiming
*
* Gets MODEREG to command delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the MODEREG to command delay
*/
uint8_t u8DMC_GetModeRegTiming(void);


/**
* @brief Implementation of function vDMC_SetActiveToPrechargeTiming
*
* Sets ACTIVE to PRECHARGE delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - MODEREG to command delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetActiveToPrechargeTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetActiveToPrechargeTiming
*
* Gets ACTIVE to PRECHARGE delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the ACTIVE to PRECHARGE delay
*/
uint8_t u8DMC_GetActiveToPrechargeTiming(void);


/**
* @brief Implementation of function vDMC_SetActiveToActiveTiming
*
* Sets ACTIVE bank x to ACTIVE bank x delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - ACTIVE bank x to ACTIVE bank x delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetActiveToActiveTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetActiveToActiveTiming
*
* Gets ACTIVE bank x to ACTIVE bank x delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the ACTIVE bank x to ACTIVE bank x delay
*/
uint8_t u8DMC_GetActiveToActiveTiming(void);


/**
* @brief Implementation of function vDMC_SetActiveToRWTiming
*
* Sets delay between an ACTIVE command and another memory command, 
* other than ACTIVE, to the same bank
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - delay between an ACTIVE command 
*                       and another memory command
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetActiveToRWTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetActiveToRWTiming
*
* Gets the delay between an ACTIVE command and another memory command, 
* other than ACTIVE, to the same bank
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the delay between an ACTIVE command and another 
*         memory command
*/
uint8_t u8DMC_GetActiveToRWTiming(void);


/**
* @brief Implementation of function vDMC_SetScheduleRCD
*
* Sets the RAS to CAS delay in module clock cycles minus 3
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - RAS to CAS delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetScheduleRCD(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetScheduleRCD
*
* Gets the RAS to CAS delay in module clock cycles minus 3
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the RAS to CAS delay
*/
uint8_t u8DMC_GetScheduleRCD(void);


/**
* @brief Implementation of function vDMC_Set_T_RCD
*
* Sets t_RCD, the RAS to CAS delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - RAS to CAS delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_Set_T_RCD(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_Get_T_RCD
*
* Gets the t_RCD, the RAS to CAS delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the RAS to CAS delay
*/
uint8_t u8DMC_Get_T_RCD(void);


/**
* @brief Implementation of function vDMC_SetAutoRefreshTiming
*
* Sets the AUTO REFRESH to command delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u16Timing - AUTO REFRESH to command delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetAutoRefreshTiming(uint16_t u16Timing);


/**
* @brief Implementation of function u16DMC_GetAutoRefreshTiming
*
* Gets the AUTO REFRESH to command delay in memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the AUTO REFRESH to command delay
*/
uint16_t u16DMC_GetAutoRefreshTiming(void);


/**
* @brief Implementation of function vDMC_SetScheduleRFC
*
* Sets the AUTO REFRESH to command delay in module clock
* cycles minus 3
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - AUTO REFRESH to command delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetScheduleRFC(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetScheduleRFC
*
* Gets the AUTO REFRESH to command delay in module clock
* cycles minus 3
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the AUTO REFRESH to command delay
*/
uint8_t u8DMC_GetScheduleRFC(void);


/**
* @brief Implementation of function vDMC_Set_T_RFC
*
* Sets t_RFC, the AUTO REFRESH to command delay in
* memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - AUTO REFRESH to command delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_Set_T_RFC(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetScheduleRFC
*
* Gets t_RFC, the AUTO REFRESH to command delay in
* memory clock cycles
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the AUTO REFRESH to command delay
*/
uint8_t u8DMC_Get_T_RFC(void);


/**
* @brief Implementation of function vDMC_SetPrechargeTiming
*
* Sets the PRECHARGE to RAS delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - PRECHARGE to RAS delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetPrechargeTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetPrechargeTiming
*
* Gets the PRECHARGE to RAS delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the PRECHARGE to RAS delay
*/
uint8_t u8DMC_GetPrechargeTiming(void);


/**
* @brief Implementation of function vDMC_SetScheduleRP
*
* Sets the PRECHARGE to RAS delay in module clock
* cycles minus 3.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - PRECHARGE to RAS delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetScheduleRP(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetScheduleRP
*
* Gets the PRECHARGE to RAS delay in module clock
* cycles minus 3.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the PRECHARGE to RAS delay
*/
uint8_t u8DMC_GetScheduleRP(void);


/**
* @brief Implementation of function vDMC_Set_T_RP
*
* Sets t_RP, the PRECHARGE to RAS delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - t_RP
*
* @param[in,out] void
*
* @return void
*/
void vDMC_Set_T_RP(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_Get_T_RP
*
* Gets t_RP, the PRECHARGE to RAS delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the t_RP delay
*/
uint8_t u8DMC_Get_T_RP(void);


/**
* @brief Implementation of function vDMC_SetActiveDiffBankTiming
*
* Sets ACTIVE bank x to ACTIVE bank y delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - ACTIVE bank x to ACTIVE bank y delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetActiveDiffBankTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetActiveDiffBankTiming
*
* Gets ACTIVE bank x to ACTIVE bank y delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the ACTIVE bank x to ACTIVE bank y delay
*/
uint8_t u8DMC_GetActiveDiffBankTiming(void);


/**
* @brief Implementation of function vDMC_SetWriteToPrechargeTiming
*
* Sets Write to PRECHARGE delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - Write to PRECHARGE delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetWriteToPrechargeTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetWriteToPrechargeTiming
*
* Gets Write to PRECHARGE delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the Write to PRECHARGE delay
*/
uint8_t u8DMC_GetWriteToPrechargeTiming(void);


/**
* @brief Implementation of function vDMC_SetWriteToReadTiming
*
* Sets Write to Read delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - Write to PRECHARGE delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetWriteToReadTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetWriteToReadTiming
*
* Gets Write to Read delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return the Write to PRECHARGE delay
*/
uint8_t u8DMC_GetWriteToReadTiming(void);


/**
* @brief Implementation of function vDMC_SetExitPowerDownTiming
*
* Sets exit power-down to command delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - exit power-down to command delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetExitPowerDownTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetExitPowerDownTiming
*
* Gets exit power-down to command delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return exit power-down to command delay
*/
uint8_t u8DMC_GetExitPowerDownTiming(void);


/**
* @brief Implementation of function vDMC_SetExitSelfRefreshTiming
*
* Sets the exit self-refresh to command delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - exit self-refresh to command delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetExitSelfRefreshTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetExitSelfRefreshTiming
*
* Gets the exit self-refresh to command delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return exit self-refresh to command delay
*/
uint8_t u8DMC_GetExitSelfRefreshTiming(void);


/**
* @brief Implementation of function vDMC_SetSelfRefreshTiming
*
* Sets self-refresh to command delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Timing - self-refresh to command delay
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetSelfRefreshTiming(uint8_t u8Timing);


/**
* @brief Implementation of function u8DMC_GetSelfRefreshTiming
*
* Gets the self-refresh to command delay in memory clock cycles.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return self-refresh to command delay
*/
uint8_t u8DMC_GetSelfRefreshTiming(void);


/**
* @brief Implementation of function vDMC_SetMemConfig2
*
* Sets the configuration of DMC.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u32Config - DMC Configuration
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfig2(uint32_t u32Config);


/**
* @brief Implementation of function u32DMC_GetMemConfig2
*
* Gets the configuration of DMC.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return DMC Configuration
*/
uint32_t u32DMC_GetMemConfig2(void);


/**
* @brief Implementation of function vDMC_SetMemCfg2ReadDelay
*
* Sets the number of memory clock cycles before the
* controller captures the read data, from the memory device,
* into the memory clock domain.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8Delay - memory clock cycles between 0-2.
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemCfg2ReadDelay(uint8_t u8Delay);


/**
* @brief Implementation of function u8DMC_GetMemCfg2ReadDelay
*
* Gets number of memory clock cycles before the
* controller captures the read data, from the memory device,
* into the memory clock domain.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return memory clock cycles
*/
uint8_t u8DMC_GetMemCfg2ReadDelay(void);


/**
* @brief Implementation of function vDMC_SetMemCfg2MemProtocol
*
* Sets the memory protocal that DMC supports.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eProtocol - memory protocal
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemCfg2MemProtocol(dmc_mem_protocol_e eProtocol);


/**
* @brief Implementation of function eDMC_GetMemCfg2MemProtocol
*
* Gets the memory protocal that DMC supports.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return memory protocal
*/
dmc_mem_protocol_e eDMC_GetMemCfg2MemProtocol(void);


/**
* @brief Implementation of function vDMC_SetMemCfg2MemWidth
*
* Sets memory data bus width.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eWidth - bus width
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemCfg2MemWidth(dmc_width_e eMemWidth);


/**
* @brief Implementation of function eDMC_GetMemCfg2MemWidth
*
* Gets the memory data bus width.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return memory data bus width
*/
dmc_width_e eDMC_GetMemCfg2MemWidth(void);


/**
* @brief Implementation of function vDMC_SetMemCfg2CkeInit
*
* Sets the state of cke.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eInit - State of cke(LOW/HIGH)
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemCfg2CkeInit(dmc_high_e eInit);


/**
* @brief Implementation of function eDMC_GetMemCfg2CkeInit
*
* Gets the state of cke.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return state of cke.
*/
dmc_high_e eDMC_GetMemCfg2CkeInit(void);


/**
* @brief Implementation of function vDMC_SetMemCfg2DqmInit
*
* Sets sets the state of the dqm outputs.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eInit - State of dqm(LOW/HIGH)
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemCfg2DqmInit(dmc_high_e eInit);


/**
* @brief Implementation of function eDMC_GetMemCfg2DqmInit
*
* Gets the state of dqm outputs.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return state of dqm.
*/
dmc_high_e eDMC_GetMemCfg2DqmInit(void);


/**
* @brief Implementation of function vDMC_SetMemConfig3
*
* Sets the power_dwn_prd prescalar value and
* number of outstanding AUTO REFRESH commands.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u32Config - prescalar and number of 
*                        outstanding AUTO REFRESH commands.
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemConfig3(uint32_t u32Config);


/**
* @brief Implementation of function u32DMC_GetMemConfig3
*
* Gets the power_dwn_prd prescalar value and
* number of outstanding AUTO REFRESH commands.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return prescalar and number of 
*         outstanding AUTO REFRESH commands.
*/
uint32_t u32DMC_GetMemConfig3(void);


/**
* @brief Implementation of function vDMC_SetMemCfg3PreScale
*
* Sets the power_dwn_prd prescalar value.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u16Prescale - prescalar value
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemCfg3PreScale(uint16_t u16Prescale);


/**
* @brief Implementation of function u16DMC_GetMemCfg3PreScale
*
* Gets the power_dwn_prd prescalar value.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return prescalar value
*/
uint16_t u16DMC_GetMemCfg3PreScale(void);


/**
* @brief Implementation of function vDMC_SetMemCfg3MaxRefsCmds
*
* Sets the number of outstanding AUTO REFRESH commands.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8MaxRefsCmds - number of outstanding 
*                            AUTO REFRESH commands
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetMemCfg3MaxRefsCmds(uint8_t u8MaxRefsCmds);


/**
* @brief Implementation of function u8DMC_GetMemCfg3MaxRefsCmds
*
* Gets the number of outstanding AUTO REFRESH commands.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return number of outstanding AUTO REFRESH commands.
*/
uint8_t u8DMC_GetMemCfg3MaxRefsCmds(void);


/**
* @brief Implementation of function vDMC_SetReadTransferDelay
*
* Sets number of idle cycles between back-to-back reads 
* to different memory devices.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eDelay - number of idle cycles
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetReadTransferDelay(dmc_read_delay_e eDelay);


/**
* @brief Implementation of function eDMC_GetReadTransferDelay
*
* Gets the number of idle cycles between back-to-back reads 
* to different memory devices.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return number of idle cycles.
*/
dmc_read_delay_e eDMC_GetReadTransferDelay(void);


/**
* @brief Implementation of function vDMC_SetIdConfig
*
* Sets the value of QoS.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8CfgID    - Configuration ID, between 0 to 15
* @param[in] u8QosMax   - maximum QoS value, between 0 to 255
* @param[in] eQosMin    - minimum QoS value
* @param[in] eQosEnable - enable/disable applying QoS to read transfer
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetIdConfig(uint8_t u8CfgID, uint8_t u8QosMax, 
                      dmc_enable_e eQosMin, dmc_enable_e eQosEnable);


/**
* @brief Implementation of function vDMC_GetIdConfig
*
* Gets the value of QoS.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8CfgID  - Configuration ID, between 0 to 15
*
* @param[in,out] u8QosMax   - pointer to maximum QoS value
* @param[in,out] eQosMin    - pointer to minimum QoS value
* @param[in,out] eQosEnable - pointer to QoS enable/disable state
*
* @return void
*/
void vDMC_GetIdConfig(uint8_t u8CfgID, uint8_t *pu8QosMax, 
                        dmc_enable_e *pQosMin, dmc_enable_e *pQosEnable);


/**
* @brief Implementation of function vDMC_SetChipConfig
*
* Sets the address decode for chip select bank, row, column 
* organization of the memory device that connects to chip select.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u32Config - external memory device configuration 
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetChipConfig(uint32_t u32Config);


/**
* @brief Implementation of function u32DMC_GetChipConfig
*
* Gets the address decode for chip select bank, row, column 
* organization of the memory device that connects to chip select.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return external memory device configuration 
*/
uint32_t u32DMC_GetChipConfig(void);


/**
* @brief Implementation of function vDMC_SetChipConfigAddrFmt
*
* Sets the memory organization format(RBC/BRC).
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eAddrFmt - memory organization format
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetChipConfigAddrFmt(dmc_addr_format_e eAddrFmt);


/**
* @brief Implementation of function eDMC_GetChipConfigAddrFmt
*
* Gets the memory organization format(RBC/BRC).
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return memory organization format
*/
dmc_addr_format_e eDMC_GetChipConfigAddrFmt(void);


/**
* @brief Implementation of function vDMC_SetChipConfigAddrMatch
*
* Sets the reference address field to select the memory device.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8AddrMatch - reference address field
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetChipConfigAddrMatch(uint8_t u8AddrMatch);


/**
* @brief Implementation of function u8DMC_GetChipConfigAddrMatch
*
* Gets the reference address field used to select the memory device.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return reference address field
*/
uint8_t u8DMC_GetChipConfigAddrMatch(void);


/**
* @brief Implementation of function vDMC_SetChipConfigAddrMask
*
* Sets the address mask value used to select the memory device.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u8AddrMask - address mask
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetChipConfigAddrMask(uint8_t u8AddrMask);


/**
* @brief Implementation of function u8DMC_GetChipConfigAddrMask
*
* Gets the address mask value used to select the memory device.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return address mask
*/
uint8_t u8DMC_GetChipConfigAddrMask(void);


/**
* @brief Implementation of function eDMC_GetUserStatus
*
* Gets the status of the user_status inputs.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] none
*
* @param[in,out] void
*
* @return user status inputs
*/
dmc_enable_e eDMC_GetUserStatus(void);


/**
* @brief Implementation of function vDMC_SetUserConfig
*
* Sets the state of the user config outputs.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u32Config - user config state(gear ratio)
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfig(uint32_t u32Config);


/**
* @brief Implementation of function vDMC_SetUserConfigGearRatio0
*
* Sets the user config's gear ratio0.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u16GearRatio - gear ratio0.
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfigGearRatio0(uint16_t u16GearRatio);


/**
* @brief Implementation of function vDMC_SetUserConfigGearRatio1
*
* Sets the user config's gear ratio1.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u16GearRatio - gear ratio1.
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfigGearRatio1(uint16_t u16GearRatio);


/**
* @brief Implementation of function vDMC_SetUserConfig1
*
* Sets the state of the user config1 outputs.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u32Config - user config1 state
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfig1(uint32_t u32Config);


/**
* @brief Implementation of function vDMC_SetUserConfig1GearRatio3
*
* Sets the user config1's gear ratio3.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u16GearRatio - gear ratio3.
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfig1GearRatio3(uint16_t u16GearRatio);


/**
* @brief Implementation of function vDMC_SetUserConfig1UseMinDelay
*
* Sets the delay to compensate the DLLs minimum Delay in LPDDR mode.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] boDelay - delay.
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfig1UseMinDelay(bool_t boDelay);


/**
* @brief Implementation of function vDMC_SetUserConfig1ClkModeChange
*
* Sets the Clock Mode Change of Leaf DLL cells.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eModeChange - Clock Mode Change
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfig1ClkModeChange(dmc_enable_e eModeChange);


/**
* @brief Implementation of function vDMC_SetUserConfig1SignalEn
*
* Enable/Disable signal for Master DLL.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] eEnable - Enable/Disable signal for Master DLL
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfig1SignalEn(dmc_enable_e eEnable);


/**
* @brief Implementation of function vDMC_SetUserConfig1GearRatio2
*
* Sets the user config1's gear ratio2.
*
* @note Only accessible when DMC is in Config/Low power state
*
* @param[in] u16GearRatio - gear ratio2.
*
* @param[in,out] void
*
* @return void
*/
void vDMC_SetUserConfig1GearRatio2(uint16_t u16GearRatio);


/**
* @brief Implementation of function vSetEarlyWriteResponse
*
* Configure Early Write Response
*
* @note No Limitations
*
* @param[in] eEnable - enable or disable Early Write Response
*
* @param[in,out] none
*
* @return void
*/
void vSetEarlyWriteResponse(dmc_enable_e eEnable);


/****************************************************************************/


#endif /* DMC_H */

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
