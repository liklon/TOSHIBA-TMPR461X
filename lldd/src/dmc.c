/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : DMC low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : DMC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.20 $
*   DATE        : $Date: 2015/05/18 13:49:55 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "dmc_io.h"                   /* DMC registers, bits and access macros defintion */
#include "dmc.h"                      /* Own definitions */
#include "pinmux_io.h"                /* Pin multiplex register access macros definition */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_DMC_C_REVISION     "$Revision: 1.20 $"
#define LLDD_DMC_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error */  
  #pragma ghs nowarning 1849  /* Rule 8.1  [R] : bitwise ~ or << expression must be immediately cast back to  underlying type, "unsigned char" */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : conversion from underlying type, "int", to same width underlying type, "uint32_t", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", not allowed */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1879  /* Rule 10.3 [R] : Restrict explicit casts for integer type expressions */
  #pragma ghs nowarning 1880  /* Rule 10.3 [R] : Restrict explicit casts for integer type expressions */
#endif  

/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8LLDD_DMC_C_REVISION[]    = LLDD_DMC_C_REVISION;
static uint8_t au8LLDD_DMC_C_TAG[]         = LLDD_DMC_C_TAG;
static uint8_t au8LLDD_DMC_H_REVISION[]    = LLDD_DMC_H_REVISION;
static uint8_t au8LLDD_DMC_H_TAG[]         = LLDD_DMC_H_TAG;
static uint8_t au8LLDD_DMC_IO_H_REVISION[] = LLDD_DMC_IO_H_REVISION;
static uint8_t au8LLDD_DMC_IO_H_TAG[]      = LLDD_DMC_IO_H_TAG;

/*********************************************/

/**********************************************
*             Function definition             *
**********************************************/

void vDMC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_DMC_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_DMC_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_DMC_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_DMC_H_TAG[0];
   *pau8IORevision     = &au8LLDD_DMC_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_DMC_IO_H_TAG[0];
}


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

/****************************************************************************/

void vDMC_Init(mem_device_st *pstDeviceParams)
{
    uint32_t         u32GearRatio;

    *((volatile uint32_t *) 0xC0000000U) = 0xA5C0F17BU;      /* pds unlock */
    *((volatile uint32_t *) 0xC0000024U) = 0x001D3FC8U;      /* enable LPDDR-clock */
    
    /* set clockspeed */
    if (pstDeviceParams->eClock_rate == DMC_CLOCK_RATE_133MHz)
    {
        *((volatile uint32_t *) 0xC0000000U) = 0xA5C0F17BU;  /* pds unlock */
        *((volatile uint32_t *) 0xC0000008U) = 0x041E1E1EU;  /* enable LPDDR-clock */
     }

    /* enable mux in dmc_wrapper */
    if (pstDeviceParams->eType == DMC_TYPE_SDRAM )
    {
        *((volatile uint32_t *) 0xC0302294U) = 0x00000002U;  /* SDRAM 32 bit */
    }
    else if ( pstDeviceParams->eWidth == DMC_BUSWIDTH_32BIT )
    {
        *((volatile uint32_t *) 0xC0302294U) = 0x00000001U;  /* LPDDR 32 bit */
    }
    else
    {
        *((volatile uint32_t *) 0xC0302294U) = 0x00000003U;  /* LPDDR 16 bit */
    }

    /* DDR-pin configuration */
    *((volatile uint32_t *) 0xC0302028U) = 0x28002800U;      /* pins DDR_CAS  and DDR_CS */
    *((volatile uint32_t *) 0xC030202CU) = 0x28002800U;      /* pins DDR_CKE  and DDR_CK */
    *((volatile uint32_t *) 0xC0302030U) = 0x28002800U;      /* pins DDR_CKN  and DDR_BA0 */
    *((volatile uint32_t *) 0xC0302024U) = 0x28002800U;      /* pins DDR_WE   and DDR_RAS */

    *((volatile uint32_t *) 0xC0302000U) = 0x28002800U;      /* pins DDR_DQ0  and DDR_DQ1 */
    *((volatile uint32_t *) 0xC0302004U) = 0x28002800U;      /* pins DDR_DQ2  and DDR_DQ3 */
    *((volatile uint32_t *) 0xC0302008U) = 0x28002800U;      /* pins DDR_DQ4  and DDR_DQ5 */
    *((volatile uint32_t *) 0xC030200CU) = 0x28002800U;      /* pins DDR_DQ6  and DDR_DQ7 */
    *((volatile uint32_t *) 0xC0302010U) = 0x28002800U;      /* pins DDR_DQ8  and DDR_DQ9 */
    *((volatile uint32_t *) 0xC0302014U) = 0x28002800U;      /* pins DDR_DQ10 and DDR_DQ11 */
    *((volatile uint32_t *) 0xC0302018U) = 0x28002800U;      /* pins DDR_DQ12 and DDR_DQ13 */
    *((volatile uint32_t *) 0xC030201CU) = 0x28002800U;      /* pins DDR_DQ14 and DDR_DQ15 */
    *((volatile uint32_t *) 0xC0302020U) = 0x28002800U;      /* pins DDR_DM0  and DDR_DM1 */
    *((volatile uint32_t *) 0xC0302034U) = 0x28002800U;      /* pins DDR_BA1  and DDR_A0 */
    *((volatile uint32_t *) 0xC0302038U) = 0x28002800U;      /* pins DDR_A1   and DDR_A2 */
    *((volatile uint32_t *) 0xC030203CU) = 0x28002800U;      /* pins DDR_A3   and DDR_A4 */
    *((volatile uint32_t *) 0xC0302040U) = 0x28002800U;      /* pins DDR_A5   and DDR_A6 */
    *((volatile uint32_t *) 0xC0302044U) = 0x28002800U;      /* pins DDR_A7   and DDR_A8 */
    *((volatile uint32_t *) 0xC0302048U) = 0x28002800U;      /* pins DDR_A9   and DDR_A10 */
    *((volatile uint32_t *) 0xC030204CU) = 0x28002800U;      /* pins DDR_A11  and DDR_A12 */
    *((volatile uint32_t *) 0xC0302050U) = 0x28002800U;      /* pins DDR_A13  and DDR_DQS0 */
    *((volatile uint32_t *) 0xC0302054U) = 0x00002800U;      /* pins DDR_DQS1 */
    *((volatile uint32_t *) 0xC0302060U) = 0x28002800U;      /* pins DDR_DQS2 and DDR_DQS3 */
    *((volatile uint32_t *) 0xC0302064U) = 0x28002800U;      /* pins DDR_DM2  and DDR_DM3 */
    *((volatile uint32_t *) 0xC0302068U) = 0x28002800U;      /* pins DDR_DQ16 and DDR_DQ17 */
    *((volatile uint32_t *) 0xC030206CU) = 0x28002800U;      /* pins DDR_DQ18 and DDR_DQ19 */
    *((volatile uint32_t *) 0xC0302070U) = 0x28002800U;      /* pins DDR_DQ20 and DDR_DQ21 */
    *((volatile uint32_t *) 0xC0302074U) = 0x28002800U;      /* pins DDR_DQ22 and DDR_DQ23 */
    *((volatile uint32_t *) 0xC0302078U) = 0x28002800U;      /* pins DDR_DQ24 and DDR_DQ25 */
    *((volatile uint32_t *) 0xC030207CU) = 0x28002800U;      /* pins DDR_DQ26 and DDR_DQ27 */
    *((volatile uint32_t *) 0xC0302080U) = 0x28002800U;      /* pins DDR_DQ28 and DDR_DQ29 */
    *((volatile uint32_t *) 0xC0302084U) = 0x28002800U;      /* pins DDR_DQ30 and DDR_DQ31 */

    /* Memory Controller Initialization*/
    *((volatile uint32_t *) 0xC0D0104CU) = 0x000002D4U;      /* memory_cfg2 */

    u32GearRatio = (pstDeviceParams->u32GearRatio_1 << (uint32_t)16U) + pstDeviceParams->u32GearRatio_0;
    *((volatile uint32_t *) 0xC0D01304U) = u32GearRatio;    /* user_config */
    u32GearRatio = (pstDeviceParams->u32GearRatio_3 << (uint32_t)16U) + pstDeviceParams->u32GearRatio_2;
    if (pstDeviceParams->eType == DMC_TYPE_LPDDR )
    {
        u32GearRatio = u32GearRatio + (uint32_t)((uint32_t)0x7U << (uint32_t)12U);
    }
    *((volatile uint32_t *) 0xC0D01308U) = u32GearRatio;              /* user_config1 */
    *((volatile uint32_t *) 0xC0D01014U) = pstDeviceParams->u32T_CAS; /* t_cas */
    if (pstDeviceParams->eType == DMC_TYPE_LPDDR )
    {
        *((volatile uint32_t *) 0xC0D01018U) = 0x00000001U;  /* dqss */
    }
    else
    {
        *((volatile uint32_t *) 0xC0D01018U) = 0x00000000U;  /* dqss */
    }
    *((volatile uint32_t *) 0xC0D0101CU) = pstDeviceParams->u32T_MRD;    /* t_mrd */
    *((volatile uint32_t *) 0xC0D01020U) = pstDeviceParams->u32T_RAS;    /* t_ras */
    *((volatile uint32_t *) 0xC0D01024U) = pstDeviceParams->u32T_RC;     /* t_rc  */
    *((volatile uint32_t *) 0xC0D01028U) = pstDeviceParams->u32T_RCD;    /* t_rcd */
    *((volatile uint32_t *) 0xC0D0102CU) = pstDeviceParams->u32T_RFC;    /* t_rfc */
    *((volatile uint32_t *) 0xC0D01030U) = pstDeviceParams->u32T_RP;     /* t_rp  */
    *((volatile uint32_t *) 0xC0D01034U) = pstDeviceParams->u32T_RRD;    /* t_rrd */
    *((volatile uint32_t *) 0xC0D01038U) = pstDeviceParams->u32T_WR;     /* t_wr  */
    *((volatile uint32_t *) 0xC0D0103CU) = pstDeviceParams->u32T_WTR;    /* t_wtr */
    *((volatile uint32_t *) 0xC0D01040U) = pstDeviceParams->u32T_XP;     /* t_xp  */
    *((volatile uint32_t *) 0xC0D01044U) = pstDeviceParams->u32T_XSR;    /* t_xsr */
    *((volatile uint32_t *) 0xC0D01048U) = pstDeviceParams->u32T_ESR;    /* t_esr */
    *((volatile uint32_t *) 0xC0D01010U) = 0x000004B0U;       /* setrefresh_prd */
    *((volatile uint32_t *) 0xC0D01200U) = 0x0001003EU;       /* setchip_cfg    */
//#if (DMC_DEVICE_TYPE ==(DEV_MT46H16M32LFB5))
 //   *((volatile uint32_t *) 0xC0D0100CU) = 0x000C8011U;       /* setmemory_cfg  8012 */ 
//#else
    *((volatile uint32_t *) 0xC0D0100CU) = 0x000C8009U;       /* setmemory_cfg   */ 
//#endif
    
    /* memory device initialisation */
    *((volatile uint32_t *) 0xC0D01008U) = 0x000C0000U;      /* NOP */
    *((volatile uint32_t *) 0xC0D01008U) = 0x00000000U;      /* PRECHARGEALL */
    *((volatile uint32_t *) 0xC0D01008U) = 0x00040000U;      /* AUTOREFRESH */
    *((volatile uint32_t *) 0xC0D01008U) = 0x00040000U;      /* AUTOREFRESH */
    *((volatile uint32_t *) 0xC0D01008U) = 0x00080031U;      /* Configure Mode Registers */
    *((volatile uint32_t *) 0xC0D01008U) = 0x000A0020U;      /* Configure Extended Mode Registers */

    *((volatile uint32_t *) 0xc0d01004U) = 0x00000000U;      /* go */
}

#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section text = default
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#pragma arm section code 
#endif /* defined(__arm__) && defined(__ARMCC_VERSION) */


/****************************************************************************/
void vDMC_MemoryDeviceInit(void)
{
    vDMC_SetDirectCommand(0x000C0000U);      /* NOP */
    vDMC_SetDirectCommand(0x00000000U);      /* PRECHARGEALL */
    vDMC_SetDirectCommand(0x00040000U);      /* AUTOREFRESH */
    vDMC_SetDirectCommand(0x00040000U);      /* AUTOREFRESH */
    vDMC_SetDirectCommand(0x00080031U);      /* Configure Mode Registers */
    vDMC_SetDirectCommand(0x000A0020U);      /* Configure Extended Mode Registers */

    vDMC_SetDirectCommand(0x00000000U);      /* go */
}


/****************************************************************************/
int32_t i32DMC_EnterDeviceMode(sys_ctrl_op_mode_e eOpMode, dmc_mem_device_state_e eState,
                               mem_device_st *pstDeviceParams)
{
    int32_t i32Ret = C_SUCCESS;
    
    if (pstDeviceParams->eType == DMC_TYPE_SDRAM)
    {
        switch(eOpMode)
        {
        case SYS_STATE_STANDBY_MODE:
            /*Change to the Pause State*/
            vDMC_SetMemCntrlCommand(DMC_CMD_PAUSE);

            /*Check, that the Pause State is reached*/
            while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}

            /* Change to Low Power State */
            vDMC_SetMemCntrlCommand(DMC_CMD_SLEEP);
            /*Check, that the Low Power State is reached*/
            while(DMC_STATUS_LOW_POWER != eDMC_GetStatus()){}
            break;
        default:
            break;
        }
    }
    else if(pstDeviceParams->eType == DMC_TYPE_LPDDR)
    {
        switch(eOpMode)
        {
        case SYS_STATE_STANDBY_MODE:
            /*Change to the Pause State*/
            vDMC_SetMemCntrlCommand(DMC_CMD_PAUSE);
            /*Check, that the Pause State is reached*/
            while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}

            /* Change to Low Power State */
            vDMC_SetMemCntrlCommand(DMC_CMD_SLEEP);
            /*Check, that the Low Power State is reached*/
            while(DMC_STATUS_LOW_POWER != eDMC_GetStatus()){}
            break;

        case SYS_STATE_STOP_MODE:
            /*Change to the Pause State*/
            vDMC_SetMemCntrlCommand(DMC_CMD_PAUSE);
            /*Check, that the Pause State is reached*/
            while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}

            /*Change to the SLEEP State*/
            vDMC_SetMemCntrlCommand(DMC_CMD_SLEEP);
            /*Check, that the SLEEP State is reached*/
            while(DMC_STATUS_LOW_POWER != eDMC_GetStatus()){}

            /* Set PRECHARGEALL */
            vDMC_SetExternalMemCommand(DMC_PRECHARGEALL);
            /* Set DPD */
            vDMC_SetExternalMemCommand(DMC_DPD);
            break;
        
        case SYS_STATE_SLEEP_MODE:
            switch(eState)
            {
            case DMC_DEV_STATE_SELF_REFRESH:
                /*Change to the Pause State*/
                vDMC_SetMemCntrlCommand(DMC_CMD_PAUSE);
                /*Check, that the Pause State is reached*/
                while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}

                /* Change to Low Power State */
                vDMC_SetMemCntrlCommand(DMC_CMD_SLEEP);
                /*Check, that the Low Power State is reached*/
                while(DMC_STATUS_LOW_POWER != eDMC_GetStatus()){}
                break;
            case DMC_DEV_STATE_DEEP_POWER_DOWN:
                /*Change to the Pause State*/
                vDMC_SetMemCntrlCommand(DMC_CMD_PAUSE);
                /*Check, that the Pause State is reached*/
                while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}

                /*Change to the SLEEP State*/
                vDMC_SetMemCntrlCommand(DMC_CMD_SLEEP);
                /*Check, that the SLEEP State is reached*/
                while(DMC_STATUS_LOW_POWER != eDMC_GetStatus()){}

                /* Set PRECHARGEALL */
                vDMC_SetExternalMemCommand(DMC_PRECHARGEALL);
                /* Set DPD */
                vDMC_SetExternalMemCommand(DMC_DPD);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    else
    {
        i32Ret = C_FAILED;
    }
    return i32Ret;
}


/****************************************************************************/
int32_t i32DMC_ExitDeviceMode(sys_ctrl_op_mode_e eOpMode, dmc_mem_device_state_e eState,
                              mem_device_st *pstDeviceParams)
{
    int32_t i32Ret = C_SUCCESS;
    
    if (pstDeviceParams->eType == DMC_TYPE_SDRAM)
    {
        switch(eOpMode)
        {
        case SYS_STATE_STANDBY_MODE:
            /*Change to the Pause State*/
            vDMC_SetMemCntrlCommand(DMC_CMD_WAKEUP);
            /*Check, that the Pause State is reached*/
            while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}
            
            /* Change to Ready State */
            vDMC_SetMemCntrlCommand(DMC_CMD_GO);
            /*Check, that the Ready State is reached*/
            while(DMC_STATUS_READY != eDMC_GetStatus()){}
            break;
        default:
            break;
        }
    }
    else if(pstDeviceParams->eType == DMC_TYPE_LPDDR)
    {
        switch(eOpMode)
        {
        case SYS_STATE_STANDBY_MODE:
            /*Change to the Pause State*/
            vDMC_SetMemCntrlCommand(DMC_CMD_WAKEUP);
            /*Check, that the Pause State is reached*/
            while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}
            
            /* Change to Ready State */
            vDMC_SetMemCntrlCommand(DMC_CMD_GO);
            /*Check, that the Ready State is reached*/
            while(DMC_STATUS_READY != eDMC_GetStatus()){}
            break;

        case SYS_STATE_STOP_MODE:
            /* Set NOP */
            vDMC_SetExternalMemCommand(DMC_NOP);
            /* Initialize DMC */
            vDMC_Init(pstDeviceParams);
            break;
        
        case SYS_STATE_SLEEP_MODE:
            switch(eState)
            {
            case DMC_DEV_STATE_SELF_REFRESH:
                /* Change to the Pause State */
                vDMC_SetMemCntrlCommand(DMC_CMD_PAUSE);
                /*Check, that the Pause State is reached*/
                while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}

                /* Change to Low Power State */
                vDMC_SetMemCntrlCommand(DMC_CMD_SLEEP);
                /*Check, that the Low Power State is reached*/
                while(DMC_STATUS_LOW_POWER != eDMC_GetStatus()){}

                /* Enable the CKE Pin */
                vSetDDR_CKE_CK_DDR_CK_LATCHN(1);

                /* Change to the Pause State */
                vDMC_SetMemCntrlCommand(DMC_CMD_WAKEUP);
                /*Check, that the Pause State is reached*/
                while(DMC_STATUS_PAUSED != eDMC_GetStatus()){}

                /* Change to Ready State */
                vDMC_SetMemCntrlCommand(DMC_CMD_GO);
                /*Check, that the Ready State is reached*/
                while(DMC_STATUS_READY != eDMC_GetStatus()){}
                break;

            case DMC_DEV_STATE_DEEP_POWER_DOWN:
                /* Set NOP */
                vDMC_SetExternalMemCommand(DMC_NOP);
                /* Initialize DMC */
                vDMC_Init(pstDeviceParams);
                break;

            default:
                break;
            }
            break;
            
        default:
            break;
        }   
    }
    else
    {
        i32Ret = C_FAILED;
    }
    return i32Ret;
}


/****************************************************************************/
dmc_status_e eDMC_GetStatus(void)
{
    dmc_status_e eStatus;

    eStatus = (dmc_status_e)biGetmemc_status_memc_status();
    return eStatus;
}


/****************************************************************************/
void vDMC_GetFixedConfig(dmc_memc_status_st *pstMemcStatus)
{
    /* Temp Variables added To Avoid MISRA warning */
    uint32_t u32BanksBit0 = (uint32_t)biGetmemc_status_banks_bit0();
    uint32_t u32BanksBit1 = (uint32_t)biGetmemc_status_banks_bit1();

    pstMemcStatus->eMemcStatus  = (dmc_status_e)biGetmemc_status_memc_status(); 
    pstMemcStatus->eMemoryWidth = (dmc_width_e)biGetmemc_status_max_memory_width();
    pstMemcStatus->eMemoryType  = (dmc_type_e)biGetmemc_status_memory_support(); 
    pstMemcStatus->eMemChips    = (dmc_mem_chips_e)biGetmemc_status_memory_chips();   
    pstMemcStatus->eMemBanks    = (dmc_mem_banks_e)(u32BanksBit0 | (u32BanksBit1 << 0x1U));   
    pstMemcStatus->eMonitors    = (dmc_monitors_e)biGetmemc_status_exclusive_monitors();   
}


/****************************************************************************/
void vDMC_SetMemCntrlCommand(dmc_cmd_e eCmd)
{
    vSetmemc_cmd_memc_cmd(eCmd);
}


/****************************************************************************/
void vDMC_SetDirectCommand(uint32_t u32Value)
{
    vSetdirect_cmd(u32Value);
}

/****************************************************************************/
void vDMC_SetExternalMemCommand(dmc_direct_cmd_e eDirCmd)
{
    /* Temp Variable added To Avoid MISRA warning */
    uint8_t u8DirCommand = (uint8_t)eDirCmd;

    vSetdirect_cmd_ext_mem_cmd((u8DirCommand >> 0x02U));
    vSetdirect_cmd_memory_cmd((u8DirCommand & 0x03U));
}


/****************************************************************************/
void vDMC_SetChipNumber(uint8_t u8ChipNo)
{
    vSetdirect_cmd_chip_nmbr(u8ChipNo);
}


/****************************************************************************/
void vDMC_SetBankAddress(uint8_t u8BankAddr)
{
    vSetdirect_cmd_bank_addr(u8BankAddr);
}


/****************************************************************************/
void vDMC_SetMemoryAddress(uint16_t u16Address)
{
    vSetdirect_cmd_addr_13_to_0(u16Address);
}


/****************************************************************************/
void vDMC_SetMemConfig(uint32_t u32Config)
{
    vSetmemory_cfg(u32Config);
}


/****************************************************************************/
uint32_t u32DMC_GetMemConfig(void)
{
    return (uint32_t)u32Getmemory_cfg();
}


/****************************************************************************/
void vDMC_SetMemConfigActiveChips(dmc_mem_chips_e eActChips)
{
    vSetmemory_cfg_active_chips(eActChips);
}


/****************************************************************************/
dmc_mem_chips_e eDMC_GetMemConfigActiveChips(void)
{
    return (dmc_mem_chips_e)biGetmemory_cfg_active_chips();
}


/****************************************************************************/
void vDMC_SetMemConfigQoS(dmc_mem_config_e eQoS)
{
    vSetmemory_cfg_qos_master_bits(eQoS);
}


/****************************************************************************/
dmc_mem_config_e eDMC_GetMemConfigQoS(void)
{
    return (dmc_mem_config_e)biGetmemory_cfg_qos_master_bits();
}


/****************************************************************************/
void vDMC_SetMemConfigBurst(dmc_mem_config_e eBurst)
{
    vSetmemory_cfg_memory_burst(eBurst);
}


/****************************************************************************/
dmc_mem_config_e eDMC_GetMemConfigBurst(void)
{
    return (dmc_mem_config_e)biGetmemory_cfg_memory_burst();
}


/****************************************************************************/
void vDMC_SetMemConfigRowAddr(dmc_mem_config_e eRowAddr)
{
    vSetmemory_cfg_row_bits(eRowAddr);
}


/****************************************************************************/
dmc_mem_config_e eDMC_GetMemConfigRowAddr(void)
{
    return (dmc_mem_config_e)biGetmemory_cfg_row_bits();
}


/****************************************************************************/
void vDMC_SetMemConfigColAddr(dmc_mem_config_e eColAddr)
{
    vSetmemory_cfg_column_bits(eColAddr);
}


/****************************************************************************/
dmc_mem_config_e eDMC_GetMemConfigColAddr(void)
{
    return (dmc_mem_config_e)biGetmemory_cfg_column_bits();
}


/****************************************************************************/
void vDMC_SetMemConfigStopClk(dmc_enable_e eStopClk)
{
    vSetmemory_cfg_stop_mem_clock(eStopClk);
}


/****************************************************************************/
dmc_enable_e eDMC_GetMemConfigStopClk(void)
{
    return (dmc_enable_e)biGetmemory_cfg_stop_mem_clock();
}


/****************************************************************************/
void vDMC_SetMemConfigAutoPowerDown(dmc_enable_e ePoweDown)
{
    vSetmemory_cfg_auto_power_down(ePoweDown);
}


/****************************************************************************/
dmc_enable_e eDMC_GetMemConfigAutoPowerDown(void)
{
    return (dmc_enable_e)biGetmemory_cfg_auto_power_down();
}


/****************************************************************************/
void vDMC_SetMemConfigAutoPreCharge(dmc_auto_precharge_e ePrecharge)
{
    vSetmemory_cfg_ap_bit(ePrecharge);
}


/****************************************************************************/
dmc_auto_precharge_e eDMC_GetMemConfigAutoPreCharge(void)
{
    return (dmc_auto_precharge_e)biGetmemory_cfg_ap_bit();
}


/****************************************************************************/
void vDMC_SetMemConfigPwrDownPrd(uint8_t u8PwrDownPrd)
{
    vSetmemory_cfg_power_dwn_prd(u8PwrDownPrd);
}


/****************************************************************************/
uint8_t u8DMC_GetMemConfigPwrDownPrd(void)
{
    return (uint8_t)biGetmemory_cfg_power_dwn_prd();
}


/****************************************************************************/
void vDMC_SetRefreshPeriod(uint16_t u16RefPrd)
{
    vSetrefresh_prd_refresh_prd(u16RefPrd);
}


/****************************************************************************/
uint16_t u16DMC_GetRefreshPeriod(void)
{
    return (uint16_t)biGetrefresh_prd_refresh_prd();
}


/****************************************************************************/
void vDMC_SetCASLatency(uint8_t u8CASLatency)
{
    vSetcas_latency(u8CASLatency);
}


/****************************************************************************/
uint8_t u8DMC_GetCASLatency(void)
{
    return (uint8_t)u32Getcas_latency();
}


/****************************************************************************/
void vDMC_SetCASHalfCycle(dmc_enable_e eHalfCycle)
{
    vSetcas_latency_cas_half_cycle(eHalfCycle);
}


/****************************************************************************/
dmc_enable_e eDMC_GetCASHalfCycle(void)
{
    return (dmc_enable_e)biGetcas_latency_cas_half_cycle();
}


/****************************************************************************/
void vDMC_SetDQSTiming(uint8_t u8DQSTiming)
{
    vSett_dqss(u8DQSTiming);
}


/****************************************************************************/
uint8_t u8DMC_GetDQSTiming(void)
{
    return (uint8_t)u32Gett_dqss();
}


/****************************************************************************/
void vDMC_SetModeRegTiming(uint8_t u8Timing)
{
    vSett_mrd(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetModeRegTiming(void)
{
    return (uint8_t)u32Gett_mrd();
}


/****************************************************************************/
void vDMC_SetActiveToPrechargeTiming(uint8_t u8Timing)
{
    vSett_ras(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetActiveToPrechargeTiming(void)
{
    return (uint8_t)u32Gett_ras();
}


/****************************************************************************/
void vDMC_SetActiveToActiveTiming(uint8_t u8Timing)
{
    vSett_rc(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetActiveToActiveTiming(void)
{
    return (uint8_t)u32Gett_rc();
}


/****************************************************************************/
void vDMC_SetActiveToRWTiming(uint8_t u8Timing)
{
    vSett_rcd(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetActiveToRWTiming(void)
{
    return (uint8_t)u32Gett_rcd();
}


/****************************************************************************/
void vDMC_SetScheduleRCD(uint8_t u8Timing)
{
    vSett_rcd_schedule_rcd(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetScheduleRCD(void)
{
    return (uint8_t)biGett_rcd_schedule_rcd();
}


/****************************************************************************/
void vDMC_Set_T_RCD(uint8_t u8Timing)
{
    vSett_rcd_t_rcd(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_Get_T_RCD(void)
{
    return (uint8_t)biGett_rcd_t_rcd();
}


/****************************************************************************/
void vDMC_SetAutoRefreshTiming(uint16_t u16Timing)
{
    vSett_rfc(u16Timing);
}


/****************************************************************************/
uint16_t u16DMC_GetAutoRefreshTiming(void)
{
    return (uint16_t)u32Gett_rfc();
}


/****************************************************************************/
void vDMC_SetScheduleRFC(uint8_t u8Timing)
{
    vSett_rfc_schedule_rfc(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetScheduleRFC(void)
{
    return (uint8_t)biGett_rfc_schedule_rfc();
}


/****************************************************************************/
void vDMC_Set_T_RFC(uint8_t u8Timing)
{
    vSett_rfc_t_rfc(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_Get_T_RFC(void)
{
    return (uint8_t)biGett_rfc_t_rfc();
}


/****************************************************************************/
void vDMC_SetPrechargeTiming(uint8_t u8Timing)
{
    vSett_rp(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetPrechargeTiming(void)
{
    return (uint8_t)u32Gett_rp();
}


/****************************************************************************/
void vDMC_SetScheduleRP(uint8_t u8Timing)
{
    vSett_rp_schedule_rp(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetScheduleRP(void)
{
    return (uint8_t)biGett_rp_schedule_rp();
}


/****************************************************************************/
void vDMC_Set_T_RP(uint8_t u8Timing)
{
    vSett_rp_t_rp(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_Get_T_RP(void)
{
    return (uint8_t)biGett_rp_t_rp();
}


/****************************************************************************/
void vDMC_SetActiveDiffBankTiming(uint8_t u8Timing)
{
    vSett_rrd(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetActiveDiffBankTiming(void)
{
    return (uint8_t)u32Gett_rrd();
}


/****************************************************************************/
void vDMC_SetWriteToPrechargeTiming(uint8_t u8Timing)
{
    vSett_wr(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetWriteToPrechargeTiming(void)
{
    return (uint8_t)u32Gett_wr();
}


/****************************************************************************/
void vDMC_SetWriteToReadTiming(uint8_t u8Timing)
{
    vSett_wtr(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetWriteToReadTiming(void)
{
    return (uint8_t)u32Gett_wtr();
}


/****************************************************************************/
void vDMC_SetExitPowerDownTiming(uint8_t u8Timing)
{
    vSett_xp(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetExitPowerDownTiming(void)
{
    return (uint8_t)u32Gett_xp();
}


/****************************************************************************/
void vDMC_SetExitSelfRefreshTiming(uint8_t u8Timing)
{
    vSett_xsr(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetExitSelfRefreshTiming(void)
{
    return (uint8_t)u32Gett_xsr();
}


/****************************************************************************/
void vDMC_SetSelfRefreshTiming(uint8_t u8Timing)
{
    vSett_esr(u8Timing);
}


/****************************************************************************/
uint8_t u8DMC_GetSelfRefreshTiming(void)
{
    return (uint8_t)u32Gett_esr();
}


/****************************************************************************/
void vDMC_SetMemConfig2(uint32_t u32Config)
{
    vSetmemory_cfg2(u32Config);
}


/****************************************************************************/
uint32_t u32DMC_GetMemConfig2(void)
{
    return (uint32_t)u32Getmemory_cfg2();
}


/****************************************************************************/
void vDMC_SetMemCfg2ReadDelay(uint8_t u8Delay)
{
    vSetmemory_cfg2_read_delay(u8Delay);
}


/****************************************************************************/
uint8_t u8DMC_GetMemCfg2ReadDelay(void)
{
    return (uint8_t)biGetmemory_cfg2_read_delay();
}


/****************************************************************************/
void vDMC_SetMemCfg2MemProtocol(dmc_mem_protocol_e eProtocol)
{
    vSetmemory_cfg2_memory_protocol(eProtocol);
}


/****************************************************************************/
dmc_mem_protocol_e eDMC_GetMemCfg2MemProtocol(void)
{
    return (dmc_mem_protocol_e)biGetmemory_cfg2_memory_protocol();
}


/****************************************************************************/
void vDMC_SetMemCfg2MemWidth(dmc_width_e eMemWidth)
{
    vSetmemory_cfg2_memory_width(eMemWidth);
}


/****************************************************************************/
dmc_width_e eDMC_GetMemCfg2MemWidth(void)
{
    return (dmc_width_e)biGetmemory_cfg2_memory_width();
}


/****************************************************************************/
void vDMC_SetMemCfg2CkeInit(dmc_high_e eInit)
{
    vSetmemory_cfg2_cke_init(eInit);
}


/****************************************************************************/
dmc_high_e eDMC_GetMemCfg2CkeInit(void)
{
    return (dmc_high_e)biGetmemory_cfg2_cke_init();
}


/****************************************************************************/
void vDMC_SetMemCfg2DqmInit(dmc_high_e eInit)
{
    vSetmemory_cfg2_dqm_init(eInit);
}


/****************************************************************************/
dmc_high_e eDMC_GetMemCfg2DqmInit(void)
{
    return (dmc_high_e)biGetmemory_cfg2_dqm_init();
}


/****************************************************************************/
void vDMC_SetMemConfig3(uint32_t u32Config)
{
    vSetmemory_cfg3(u32Config);
}


/****************************************************************************/
uint32_t u32DMC_GetMemConfig3(void)
{
    return (uint32_t)u32Getmemory_cfg3();
}


/****************************************************************************/
void vDMC_SetMemCfg3PreScale(uint16_t u16Prescale)
{
    vSetmemory_cfg3_prescale(u16Prescale);
}


/****************************************************************************/
uint16_t u16DMC_GetMemCfg3PreScale(void)
{
    return (uint16_t)biGetmemory_cfg3_prescale();
}


/****************************************************************************/
void vDMC_SetMemCfg3MaxRefsCmds(uint8_t u8MaxRefsCmds)
{
    vSetmemory_cfg3_max_outs_refs(u8MaxRefsCmds);
}


/****************************************************************************/
uint8_t u8DMC_GetMemCfg3MaxRefsCmds(void)
{
    return (uint8_t)biGetmemory_cfg3_max_outs_refs();
}


/****************************************************************************/
void vDMC_SetReadTransferDelay(dmc_read_delay_e eDelay)
{
    vSetread_transfer_delay_read_transfer_delay(eDelay);
}


/****************************************************************************/
dmc_read_delay_e eDMC_GetReadTransferDelay(void)
{
    return (dmc_read_delay_e)biGetread_transfer_delay_read_transfer_delay();
}


/****************************************************************************/
void vDMC_SetIdConfig(uint8_t u8CfgID, uint8_t u8QosMax, 
                      dmc_enable_e eQosMin, dmc_enable_e eQosEnable)
{
    switch(u8CfgID)
    {
        case 0 :
                vSetid_0_cfg_qos_enable0(eQosEnable);
                vSetid_0_cfg_qos_min0(eQosMin);
                vSetid_0_cfg_qos_max0(u8QosMax);
                break;
        case 1 :
                vSetid_1_cfg_qos_enable1(eQosEnable);
                vSetid_1_cfg_qos_min1(eQosMin);
                vSetid_1_cfg_qos_max1(u8QosMax);
                break;
        case 2 :
                vSetid_2_cfg_qos_enable2(eQosEnable);
                vSetid_2_cfg_qos_min2(eQosMin);
                vSetid_2_cfg_qos_max2(u8QosMax);
                break;
        case 3 :
                vSetid_3_cfg_qos_enable3(eQosEnable);
                vSetid_3_cfg_qos_min3(eQosMin);
                vSetid_3_cfg_qos_max3(u8QosMax);
                break;
        case 4 :
                vSetid_4_cfg_qos_enable4(eQosEnable);
                vSetid_4_cfg_qos_min4(eQosMin);
                vSetid_4_cfg_qos_max4(u8QosMax);
                break;
        case 5 :
                vSetid_5_cfg_qos_enable5(eQosEnable);
                vSetid_5_cfg_qos_min5(eQosMin);
                vSetid_5_cfg_qos_max5(u8QosMax);
                break;
        case 6 :
                vSetid_6_cfg_qos_enable6(eQosEnable);
                vSetid_6_cfg_qos_min6(eQosMin);
                vSetid_6_cfg_qos_max6(u8QosMax);
                break;
        case 7 :
                vSetid_7_cfg_qos_enable7(eQosEnable);
                vSetid_7_cfg_qos_min7(eQosMin);
                vSetid_7_cfg_qos_max7(u8QosMax);
                break;
        case 8 :
                vSetid_8_cfg_qos_enable8(eQosEnable);
                vSetid_8_cfg_qos_min8(eQosMin);
                vSetid_8_cfg_qos_max8(u8QosMax);
                break;
        case 9 :
                vSetid_9_cfg_qos_enable9(eQosEnable);
                vSetid_9_cfg_qos_min9(eQosMin);
                vSetid_9_cfg_qos_max9(u8QosMax);
                break;
        case 10 :
                vSetid_10_cfg_qos_enable10(eQosEnable);
                vSetid_10_cfg_qos_min10(eQosMin);
                vSetid_10_cfg_qos_max10(u8QosMax);
                break;
        case 11 :
                vSetid_11_cfg_qos_enable11(eQosEnable);
                vSetid_11_cfg_qos_min11(eQosMin);
                vSetid_11_cfg_qos_max11(u8QosMax);
                break;
        case 12 :
                vSetid_12_cfg_qos_enable12(eQosEnable);
                vSetid_12_cfg_qos_min12(eQosMin);
                vSetid_12_cfg_qos_max12(u8QosMax);
                break;
        case 13 :
                vSetid_13_cfg_qos_enable13(eQosEnable);
                vSetid_13_cfg_qos_min13(eQosMin);
                vSetid_13_cfg_qos_max13(u8QosMax);
                break;
        case 14 :
                vSetid_14_cfg_qos_enable14(eQosEnable);
                vSetid_14_cfg_qos_min14(eQosMin);
                vSetid_14_cfg_qos_max14(u8QosMax);
                break;
        case 15 :
                vSetid_15_cfg_qos_enable15(eQosEnable);
                vSetid_15_cfg_qos_min15(eQosMin);
                vSetid_15_cfg_qos_max15(u8QosMax);
                break;                
        default :
                break;
    }
}


/****************************************************************************/
void vDMC_GetIdConfig(uint8_t u8CfgID, uint8_t *pu8QosMax, 
                        dmc_enable_e *pQosMin, dmc_enable_e *pQosEnable)
{
    switch(u8CfgID)
    {
        case 0 :
                *pQosEnable = (dmc_enable_e)biGetid_0_cfg_qos_enable0();
                *pQosMin    = (dmc_enable_e)biGetid_0_cfg_qos_min0();
                *pu8QosMax  = biGetid_0_cfg_qos_max0();
                break;
        case 1 :
                *pQosEnable = (dmc_enable_e)biGetid_1_cfg_qos_enable1();
                *pQosMin    = (dmc_enable_e)biGetid_1_cfg_qos_min1();
                *pu8QosMax  = biGetid_1_cfg_qos_max1();
                break;
        case 2 :
                *pQosEnable = (dmc_enable_e)biGetid_2_cfg_qos_enable2();
                *pQosMin    = (dmc_enable_e)biGetid_2_cfg_qos_min2();
                *pu8QosMax  = biGetid_2_cfg_qos_max2();
                break;
        case 3 :
                *pQosEnable = (dmc_enable_e)biGetid_3_cfg_qos_enable3();
                *pQosMin    = (dmc_enable_e)biGetid_3_cfg_qos_min3();
                *pu8QosMax  = biGetid_3_cfg_qos_max3();
                break;
        case 4 :
                *pQosEnable = (dmc_enable_e)biGetid_4_cfg_qos_enable4();
                *pQosMin    = (dmc_enable_e)biGetid_4_cfg_qos_min4();
                *pu8QosMax  = biGetid_4_cfg_qos_max4();
                break;
        case 5 :
                *pQosEnable = (dmc_enable_e)biGetid_5_cfg_qos_enable5();
                *pQosMin    = (dmc_enable_e)biGetid_5_cfg_qos_min5();
                *pu8QosMax  = biGetid_5_cfg_qos_max5();
                break;
        case 6 :
                *pQosEnable = (dmc_enable_e)biGetid_6_cfg_qos_enable6();
                *pQosMin    = (dmc_enable_e)biGetid_6_cfg_qos_min6();
                *pu8QosMax  = biGetid_6_cfg_qos_max6();
                break;
        case 7 :
                *pQosEnable = (dmc_enable_e)biGetid_7_cfg_qos_enable7();
                *pQosMin    = (dmc_enable_e)biGetid_7_cfg_qos_min7();
                *pu8QosMax  = biGetid_7_cfg_qos_max7();
                break;
        case 8 :
                *pQosEnable = (dmc_enable_e)biGetid_8_cfg_qos_enable8();
                *pQosMin    = (dmc_enable_e)biGetid_8_cfg_qos_min8();
                *pu8QosMax  = biGetid_8_cfg_qos_max8();
                break;
        case 9 :
                *pQosEnable = (dmc_enable_e)biGetid_9_cfg_qos_enable9();
                *pQosMin    = (dmc_enable_e)biGetid_9_cfg_qos_min9();
                *pu8QosMax  = biGetid_9_cfg_qos_max9();
                break;
        case 10 :
                *pQosEnable = (dmc_enable_e)biGetid_10_cfg_qos_enable10();
                *pQosMin    = (dmc_enable_e)biGetid_10_cfg_qos_min10();
                *pu8QosMax  = biGetid_10_cfg_qos_max10();
                break;
        case 11 :
                *pQosEnable = (dmc_enable_e)biGetid_11_cfg_qos_enable11();
                *pQosMin    = (dmc_enable_e)biGetid_11_cfg_qos_min11();
                *pu8QosMax  = biGetid_11_cfg_qos_max11();
                break;
        case 12 :
                *pQosEnable = (dmc_enable_e)biGetid_12_cfg_qos_enable12();
                *pQosMin    = (dmc_enable_e)biGetid_12_cfg_qos_min12();
                *pu8QosMax  = biGetid_12_cfg_qos_max12();
                break;
        case 13 :
                *pQosEnable = (dmc_enable_e)biGetid_13_cfg_qos_enable13();
                *pQosMin    = (dmc_enable_e)biGetid_13_cfg_qos_min13();
                *pu8QosMax  = biGetid_13_cfg_qos_max13();
                break;
        case 14 :
                *pQosEnable = (dmc_enable_e)biGetid_14_cfg_qos_enable14();
                *pQosMin    = (dmc_enable_e)biGetid_14_cfg_qos_min14();
                *pu8QosMax  = biGetid_14_cfg_qos_max14();
                break;
        case 15 :
                *pQosEnable = (dmc_enable_e)biGetid_15_cfg_qos_enable15();
                *pQosMin    = (dmc_enable_e)biGetid_15_cfg_qos_min15();
                *pu8QosMax  = biGetid_15_cfg_qos_max15();
                break;                
            
        default :
                break;
    }
}


/****************************************************************************/
void vDMC_SetChipConfig(uint32_t u32Config)
{
    vSetchip_cfg(u32Config);
}


/****************************************************************************/
uint32_t u32DMC_GetChipConfig(void)
{
    return (uint32_t)u32Getchip_cfg();
}


/****************************************************************************/
void vDMC_SetChipConfigAddrFmt(dmc_addr_format_e eAddrFmt)
{
    vSetchip_cfg_address_fmt(eAddrFmt);
}


/****************************************************************************/
dmc_addr_format_e eDMC_GetChipConfigAddrFmt(void)
{
    return (dmc_addr_format_e)biGetchip_cfg_address_fmt();
}


/****************************************************************************/
void vDMC_SetChipConfigAddrMatch(uint8_t u8AddrMatch)
{
    vSetchip_cfg_address_match(u8AddrMatch);
}


/****************************************************************************/
uint8_t u8DMC_GetChipConfigAddrMatch(void)
{
    return (uint8_t)biGetchip_cfg_address_match();
}


/****************************************************************************/
void vDMC_SetChipConfigAddrMask(uint8_t u8AddrMask)
{
    vSetchip_cfg_address_mask(u8AddrMask);
}


/****************************************************************************/
uint8_t u8DMC_GetChipConfigAddrMask(void)
{
    return (uint8_t)biGetchip_cfg_address_mask();
}


/****************************************************************************/
dmc_enable_e eDMC_GetUserStatus(void)
{
    return (dmc_enable_e)u32Getuser_status();
}


/****************************************************************************/
void vDMC_SetUserConfig(uint32_t u32Config)
{
    vSetuser_config(u32Config);
}


/****************************************************************************/
void vDMC_SetUserConfigGearRatio0(uint16_t u16GearRatio)
{
    vSetuser_config_gear_ratio0(u16GearRatio);
}


/****************************************************************************/
void vDMC_SetUserConfigGearRatio1(uint16_t u16GearRatio)
{
    vSetuser_config_gear_ratio1(u16GearRatio);
}


/****************************************************************************/
void vDMC_SetUserConfig1(uint32_t u32Config)
{
    vSetuser_config1(u32Config);
}


/****************************************************************************/
void vDMC_SetUserConfig1GearRatio3(uint16_t u16GearRatio)
{
    vSetuser_config1_gear_ratio3(u16GearRatio);
}


/****************************************************************************/
void vDMC_SetUserConfig1UseMinDelay(bool_t boDelay)
{
    vSetuser_config1_Use_Min_Delay(boDelay);
}


/****************************************************************************/
void vDMC_SetUserConfig1ClkModeChange(dmc_enable_e eModeChange)
{
    vSetuser_config1_Clock_Mode_Change(eModeChange);
}


/****************************************************************************/
void vDMC_SetUserConfig1SignalEn(dmc_enable_e eEnable)
{
    vSetuser_config1_Enable(eEnable);
}


/****************************************************************************/
void vDMC_SetUserConfig1GearRatio2(uint16_t u16GearRatio)
{
    vSetuser_config1_gear_ratio2(u16GearRatio);
}


/****************************************************************************/
void vSetEarlyWriteResponse(dmc_enable_e eEnable)
{
    if (eEnable == DMC_ENABLE)
    {
        vSetfeature_ctrl_stop_early_bresp((uint32_t)DMC_DISABLE);
    }
    else
    {
        vSetfeature_ctrl_stop_early_bresp((uint32_t)DMC_ENABLE);
    }
}


/****************************************************************************/
/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 1834 / 5.1 - casting error
** | CONS.  : allow
** | REASON : for usage of macros from io header files 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1849 / 8.1 - bitwise ~ or << expression must be immediately cast 
** |                       back to  underlying type, "unsigned char" 
** | CONS.  : allow
** | REASON : necessary for shift operations, which we know it will not over run 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1864 /10.1  - implicit conversion from underlying type, "type", 
** |                        to narrower underlying type, "type", not allowed
** | CONS.  : allow
** | REASON : to use macros from i/o header files 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1865 /10.1  -  implicit conversion from underlying type, "type", 
** |                         to same width underlying type, "type", not allowed
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1866 /10.1  -  implicit conversion from underlying type, "type",  
** |                         to underlying type, "type", changes signedness
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1867 /10.1  -  implicit conversion from underlying type, "type", 
** |                         to underlying type, "type", changes signedness
** | CONS.  : allow
** | REASON : for usage of macros from io header files or assign parameters
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1879 /10.3  - 	 cast of complex integer expression with underlying
** |                           type "type" to same width type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as macros in io header file
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1880 /10.3  -    cast of complex integer expression with underlying
** |                           type "type" to same width type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as macros in io header file
** |
**  ------------------------------------------------------------------------

*****************************************************************************/

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

