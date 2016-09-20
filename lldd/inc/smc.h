/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Stepper motor controler low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : SMC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.14 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef SMC_H
#define SMC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_SMC_H_REVISION     "$Revision: 1.14 $"
#define LLDD_SMC_H_TAG          "$Name: LLDD_1_6 $"


#define SMC_SCLFAK_MIN  1
#define SMC_SCLFAK_MAX  10

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/* smc device no. */
typedef enum tag_smc_dev_e
{
   SMC0 = 0,                              /* smc device #0 */
   SMC1 = 1,                              /* smc device #1 */
   SMC2 = 2,                              /* smc device #2 */
   SMC3 = 3,                              /* smc device #3 */
   SMC4 = 4                               /* smc device #4 */
} smc_dev_e;

/* device modes */
typedef enum tag_smc_channel_mode_e
{
   SMC_ISM_MODE = 0,                      /* ISM mode */
   SMC_PWM_MODE = 1,                      /* direct PWM mode */
   SMC_ZPD_MODE = 2                       /* zero point detection */
} smc_channel_mode_e;

/* enable/disable */
typedef enum tag_smc_enable_e
{
   SMC_DISABLE = 0,                       /* disable */
   SMC_ENABLE  = 1                        /* enable  */
} smc_enable_e;

/* Interrupt types */
typedef enum tag_smc_motint_types_e
{
   SMC_INT_PPE     = 0,                   /* PPE */
   SMC_INT_MOW_END = 1,                   /* MOV_END */
   SMC_INT_ZPD     = 2                    /* ZPD */
} smc_motint_types_e;

/* ISM table mode */
typedef enum tag_smc_ism_table_mode_e
{
   SMC_ISM_TABLE_MODE_NORMAL  = 0,        /* normal table mode */
   SMC_ISM_TABLE_MODE_PRECISE = 1         /* precise table mode  */
} smc_ism_table_mode_e;

/* table index */
typedef enum tag_smc_table_index_e
{
   SMC_TABLE_INDEX_0 = 0,                 /* table index 0 */
   SMC_TABLE_INDEX_1 = 1                  /* table index 1  */
} smc_table_index_e;

/* PWM quadrant */
typedef enum tag_smc_quadrant_e
{
   SMC_PWM_QUADRANT_1 = 0,                /* quadrant 1 */
   SMC_PWM_QUADRANT_2 = 1,                /* quadrant 2 */
   SMC_PWM_QUADRANT_3 = 2,                /* quadrant 3 */
   SMC_PWM_QUADRANT_4 = 3                 /* quadrant 4 */
} smc_quadrant_e;

/* table data selection */
typedef enum tag_smc_table_data_selection_e
{
   SMC_TABLE_SLOW = 0,                    /* table data slow */
   SMC_TABLE_FAST = 1                     /* table data fast */
} smc_table_data_selection_e;

/* table data direction */
typedef enum tag_smc_table_data_direction_e
{
   SMC_TABLE_CCW = 0,                     /* table ccw */
   SMC_TABLE_CW = 1                       /* table cw */
} smc_table_data_direction_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/
typedef struct tag_smc_generalconfig_st
{
    uint8_t      u8DelayCycleCount;                      /* number of delay cycles */
    uint8_t      u8PeriodExtension;                      /* number of cycles for period extension */
    uint8_t      u8SlewRate;                             /* slew rate */
} smc_generalconfig_st;

typedef struct tag_smc_ismconfig_st
{
    float32_t                  f32IntermediateAngle;     /* (PT1) intermediate angle */
    float32_t                  f32ActualAngle;           /* (PT2) actual angle */
    uint32_t                   u32Velocity;              /* (V) velocity */
    uint32_t                   u32VelocityLimit;         /* (Vmax) velocity limit */
    uint32_t                   u32AccelerationLimit;     /* (amax) acceleration limit */
    uint32_t                   u32DecelerationLimit;     /* (dmax) deceleration limit */
    uint32_t                   u32SpeedThreshold1;       /* (V1th) speed threshold 1 */
    uint32_t                   u32SpeedThreshold2;       /* (V2th) speed threshold 2 */
    uint8_t                    u8DampingFactorK;         /* (k) damping factor K */
    uint8_t                    u8DampingFactorL;         /* (l) damping factor L */
    float32_t                  f32DegreePerFullstep;     /* rotation angle in degree per one full step */
    smc_ism_table_mode_e       eTableMode;               /* number of cycles for period extension */
    smc_table_index_e          eTableIndex;              /* starting table index */
    smc_table_data_selection_e eTableData;               /* table data */
    smc_enable_e               eUseDampingCurveHardware; /* use damping curve hardware */
} smc_ismconfig_st;

typedef struct tag_smc_pwmvalue_st
{
    smc_quadrant_e eQuadrant;                            /* quadrant used */
    uint16_t       u16SinDuty;                           /* PWM duty cycle for sin */
    uint16_t       u16CosDuty;                           /* PWM duty cycle for cos */
} smc_pwmvalue_st;

typedef struct tag_smc_zpdconfig_st
{
    uint8_t u8IndexIncrement;                            /* index increment */
    uint8_t u8ScanningFrequency;                         /* scanning frequency */
    uint8_t u8VoltageThreshold;                          /* voltage threshold */
} smc_zpdconfig_st;

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
 * Function:      vSMC_GetVersion
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
void vSMC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      boSMC_SetPrescaler
 *
 * Purpose:       write prescaler value to register
 *
 * Inputs:        u8Value - prescaler value
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE: OK
 *                C_FALSE: Wrong parameter
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boSMC_SetPrescaler(uint8_t u8Value);

/****************************************************************************
 *
 * Function:      u8SMC_GetPrescaler
 *
 * Purpose:       read prescaler value from register
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: prescaler value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetPrescaler(void);

/****************************************************************************
 *
 * Function:      eSMC_GetIntConfigReg
 *
 * Purpose:       reads configuration register access in user mode
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: SMC_ENABLE/SMC_DISABLE 
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_enable_e eSMC_GetIntConfigReg(void);

/****************************************************************************
 *
 * Function:      boSMC_GetIntSingle
 *
 * Purpose:       read interrupt for single motor
 *
 * Inputs:        eDevice  - SMC device
 *                eIntMask - Interrupt mask
 *
 * Outputs:       peEnable: pointer to get enabled or disabled
 *
 * Return Values: C_TRUE on success
 *                C_FALSE on invalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boSMC_GetIntSingle(smc_dev_e eDevice, smc_motint_types_e eIntMask, smc_enable_e* peEnable);

/****************************************************************************
 *
 * Function:      u32SMC_GetIntAll
 *
 * Purpose:       read all interrupts
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: interrupt vector
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetIntAll(void);

/****************************************************************************
 *
 * Function:      vSMC_ClearIntConfigReg
 *
 * Purpose:       clear configuraion register by user mode
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_ClearIntConfigReg(void);

/****************************************************************************
 *
 * Function:      boSMC_ClearIntSingle
 *
 * Purpose:       clear single interrupt
 *
 * Inputs:        eDevice  - SMC device
 *                eIntType - Interrupt mask
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE on success
 *                C_FALSE on invalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boSMC_ClearIntSingle(smc_dev_e eDevice, smc_motint_types_e eIntType);

/****************************************************************************
 *
 * Function:      vSMC_ClearIntAll
 *
 * Purpose:       clear all interrupts
 *
 * Inputs:        u32Value - clear value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_ClearIntAll(uint32_t u32Value);


/****************************************************************************
 *
 * Function:      vSetIntConfReg
 *
 * Purpose:       set interrupt mask for config register by user mode
 *
 * Inputs:        eEnable  - Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSetIntConfReg(smc_enable_e eEnable);

/****************************************************************************
 *
 * Function:      boSMC_SetIntMaskSingle
 *
 * Purpose:       set interrupt mask for single interrupt
 *
 * Inputs:        eDevice  - SMC device
 *                eIntType - Interrupt type
 *                eEnable  - Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE on success
 *                C_FALSE on invalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boSMC_SetIntMaskSingle(smc_dev_e eDevice, smc_motint_types_e eIntType, smc_enable_e eEnable);

/****************************************************************************
 *
 * Function:      vSMC_SetIntMaskAll
 *
 * Purpose:       set interrupt mask for all interrupts
 *
 * Inputs:        u32Mask - interrupt mask
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetIntMaskAll(uint32_t u32Mask);

/****************************************************************************
 *
 * Function:      u32SMC_GetIntMaskAll
 *
 * Purpose:       get interrupt mask for all interrupts
 *
 * Inputs:        void 
 *
 * Outputs:       interrupt mask
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetIntMaskAll(void);

/****************************************************************************
 *
 * Function:      eSMC_GetChannelMode
 *
 * Purpose:       read operation mode type
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: channel mode
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_channel_mode_e eSMC_GetChannelMode(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetChannelMode
 *
 * Purpose:       set operation mode type
 *
 * Inputs:        eDevice - SMC device
 *                eMode   - channel mode
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetChannelMode(smc_dev_e eDevice, smc_channel_mode_e eMode);

/****************************************************************************
 *
 * Function:      eSMC_GetPinStatus
 *
 * Purpose:       read configuration for PWM-pin behavior
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: status of pins
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_enable_e eSMC_GetPinStatus(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetPinStatus
 *
 * Purpose:       set configuration for PWM-pin behavior
 *
 * Inputs:        eDevice - SMC device
 *                eEnable - status
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetPinStatus(smc_dev_e eDevice, smc_enable_e eEnable);

/****************************************************************************
 *
 * Function:      u8SMC_GetOutputDelayCycleCount
 *
 * Purpose:       read delay cycles on PWM-lines of different stepper motors 
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: number of delay cycles
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetOutputDelayCycleCount(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetOutputDelayCycleCount
 *
 * Purpose:       set delay cycle count on PWM-lines of different stepper
 *                motors 
 *
 * Inputs:        eDevice - SMC device
 *                u8Value - number of delay cycles
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetOutputDelayCycleCount(smc_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      u8SMC_GetPeriodExtension
 *
 * Purpose:       read period extension value
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: period extension value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetPeriodExtension(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetPeriodExtension
 *
 * Purpose:       set period extension value 
 *
 * Inputs:        eDevice - SMC device
 *                u8Value - number extension cycles
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetPeriodExtension(smc_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      u8SMC_GetSlewRate
 *
 * Purpose:       read slew rate value
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: slew rate value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetSlewRate(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetSlewRate
 *
 * Purpose:       set slew rate value
 *
 * Inputs:        eDevice - SMC device
 *                u8Value - slew rate value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetSlewRate(smc_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      u8SMC_GetISMDampingFactorK
 *
 * Purpose:       read damping factor K
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: damping factor K
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetISMDampingFactorK(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetISMDampingFactorK
 *
 * Purpose:       set damping factor K
 *
 * Inputs:        eDevice - SMC device
 *                u8Value - damping factor K
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetISMDampingFactorK(smc_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      vSMC_GetISMDampingFactorL
 *
 * Purpose:       read damping factor L
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: damping factor L
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetISMDampingFactorL(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetISMDampingFactorL
 *
 * Purpose:       set damping factor L
 *
 * Inputs:        eDevice - SMC device
 *                u8Value - damping factor L
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetISMDampingFactorL(smc_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      eSMC_GetISMTableMode
 *
 * Purpose:       read table mode
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: table mode
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_ism_table_mode_e eSMC_GetISMTableMode(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetISMTableMode
 *
 * Purpose:       set table mode
 *
 * Inputs:        eDevice - SMC device
 *                eValue  - table mode
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetISMTableMode(smc_dev_e eDevice, smc_ism_table_mode_e eValue);

/****************************************************************************
 *
 * Function:      eSMC_GetISMTableIndex
 *
 * Purpose:       read table index
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: table index
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_table_index_e eSMC_GetISMTableIndex(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetISMTableIndex
 *
 * Purpose:       set table mode
 *
 * Inputs:        eDevice - SMC device
 *                eValue  - table index
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetISMTableIndex(smc_dev_e eDevice, smc_table_index_e eValue);

/****************************************************************************
 *
 * Function:      eSMC_IsISMDampingCurveHardwareEnabled
 *
 * Purpose:       read status if damping curve hardware is enabled
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: status if damping curve hardware is enabled
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_enable_e eSMC_IsISMDampingCurveHardwareEnabled(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_EnableISMDampingCurveHardware
 *
 * Purpose:       enable or disable damping curve hardware
 *
 * Inputs:        eDevice - SMC device
 *                eValue  - enable/disable damping curve hardware
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_EnableISMDampingCurveHardware(smc_dev_e eDevice, smc_enable_e eValue);

/****************************************************************************
 *
 * Function:      eSMC_GetISMReadRequestStatus
 *
 * Purpose:       read status of read request
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: read request status
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_enable_e eSMC_GetISMReadRequestStatus(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetISMReadRequest
 *
 * Purpose:       enable or disable read request
 *
 * Inputs:        eDevice - SMC device
 *                eValue  - enable/disable read request
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetISMReadRequest(smc_dev_e eDevice, smc_enable_e eValue);

/****************************************************************************
 *
 * Function:      vSMC_SetISMReadRequest
 *
 * Purpose:       read flag, if read access is performed
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: status of read access flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_enable_e eSMC_GetISMReadRequestFlagStatus(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      eSMC_GetISMFreezeRequestStatus
 *
 * Purpose:       read status of freeze request
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: freeze request status
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_enable_e eSMC_GetISMFreezeRequestStatus(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetISMFreezeRequest
 *
 * Purpose:       enable or disable freeze request
 *
 * Inputs:        eDevice - SMC device
 *                eValue  - enable/disable freeze request
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetISMFreezeRequest(smc_dev_e eDevice, smc_enable_e eValue);

/****************************************************************************
 *
 * Function:      eSMC_GetISMFreezeRequestFlagStatus
 *
 * Purpose:       read flag, if channel is frozen
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: status of freeze flag
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_enable_e eSMC_GetISMFreezeRequestFlagStatus(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      fSMC_GetISMPosition
 *
 * Purpose:       read current position value
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: position value
 *
 * Limitations:   none
 *
 ***************************************************************************/
float32_t fSMC_GetISMPosition(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetISMPosition
 *
 * Purpose:       write position value
 *
 * Inputs:        eDevice  - SMC device
 *                f32Value - position value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetISMPosition(smc_dev_e eDevice, float32_t f32Value);

/****************************************************************************
 *
 * Function:      u16SMC_GetPWMCosDuty
 *
 * Purpose:       read PWM duty cycle for cos
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: PWM duty cycle for cos
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16SMC_GetPWMCosDuty(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetPWMCosDuty
 *
 * Purpose:       write PWM duty cycle for cos
 *
 * Inputs:        eDevice  - SMC device
 *                u16Value - PWM duty cycle for cos
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetPWMCosDuty(smc_dev_e eDevice, uint16_t u16Value);

/****************************************************************************
 *
 * Function:      u16SMC_GetPWMSinDuty
 *
 * Purpose:       read PWM duty cycle for sin
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: PWM duty cycle for sin
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint16_t u16SMC_GetPWMSinDuty(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetPWMSinDuty
 *
 * Purpose:       write PWM duty cycle for sin
 *
 * Inputs:        eDevice  - SMC device
 *                u16Value - PWM duty cycle for sin
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetPWMSinDuty(smc_dev_e eDevice, uint16_t u16Value);

/****************************************************************************
 *
 * Function:      eSMC_GetPWMQuadrant
 *
 * Purpose:       read quadrant used in PWM mode
 *
 * Inputs:        eDevice  - SMC device
 *
 * Outputs:       quadrant used in PWM mode
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_quadrant_e eSMC_GetPWMQuadrant(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetPWM32BitData
 *
 * Purpose:       sets quadrant, Sin and cos part of pwm value in one step
 *                NOTE: this API can be used to ensure all 3 parameters will
 *                       be set together, to avoid side effects by setting
 *                       separately.   
 *
 * Inputs:        eDevice  - SMC device
 *                wQuadr:  Selected Quandrant
 *                u16Sin:  Sinus part
 *                u16Cos:  Cosinus part                
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetPWM32BitData(smc_dev_e eDevice, smc_quadrant_e wQuadr, 
                          uint16_t u16Sin, uint16_t u16Cos);

/****************************************************************************
 *
 * Function:      vSMC_SetPWMQuadrant
 *
 * Purpose:       write quadrant used in PWM mode
 *
 * Inputs:        eDevice - SMC device
 *                eValue  - quadrant used in PWM mode
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetPWMQuadrant(smc_dev_e eDevice, smc_quadrant_e eValue);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCAIntermediateAngle
 *
 * Purpose:       read intermediate angle
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: intermediate angle
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCAIntermediateAngle(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCAIntermediateAngle
 *
 * Purpose:       write intermediate angle
 *
 * Inputs:        eDevice  - SMC device
 *                f32Value - intermediate angle
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCAIntermediateAngle(smc_dev_e eDevice, float32_t f32Value);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCAActualAngle
 *
 * Purpose:       write actual angle
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: actual angle
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCAActualAngle(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCAActualAngle
 *
 * Purpose:       write actual angle
 *
 * Inputs:        eDevice  - SMC device
 *                f32Value - actual angle
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCAActualAngle(smc_dev_e eDevice, float32_t f32Value);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCAVelocity
 *
 * Purpose:       read velocity
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: velocity
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCAVelocity(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCAVelocity
 *
 * Purpose:       write velocity
 *
 * Inputs:        eDevice  - SMC device
 *                u32Value - velocity
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCAVelocity(smc_dev_e eDevice, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCAVelocityLimit
 *
 * Purpose:       read velocity linit
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: velocity linit
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCAVelocityLimit(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCAVelocityLimit
 *
 * Purpose:       write velocity
 *
 * Inputs:        eDevice  - SMC device
 *                u32Value - velocity limit
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCAVelocityLimit(smc_dev_e eDevice, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      f32SMC_GetDCAAcceleration
 *
 * Purpose:       read acceleration
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       acceleration
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
float32_t f32SMC_GetDCAAcceleration(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCAAccelerationLimit
 *
 * Purpose:       read acceleration limit
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: acceleration limit value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCAAccelerationLimit(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCAAcceleration
 *
 * Purpose:       read acceleration
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: acceleration value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCAAcceleration(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCAAccelerationLimit
 *
 * Purpose:       write acceleration limit
 *
 * Inputs:        eDevice  - SMC device
 *                u32Value - scceleration limit
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCAAccelerationLimit(smc_dev_e eDevice, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCADecelerationLimit
 *
 * Purpose:       read deceleration limit
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: deceleration limit
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCADecelerationLimit(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCADecelerationLimit
 *
 * Purpose:       write deceleration limit
 *
 * Inputs:        eDevice  - SMC device
 *                u32Value - deceleration limit
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCADecelerationLimit(smc_dev_e eDevice, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCASpeedThreshold1
 *
 * Purpose:       read speed threshold 1
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: speed threshold 1
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCASpeedThreshold1(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCASpeedThreshold1
 *
 * Purpose:       write speed threshold 1
 *
 * Inputs:        eDevice  - SMC device
 *                u32Value - speed threshold 1
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCASpeedThreshold1(smc_dev_e eDevice, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      u32SMC_GetDCASpeedThreshold2
 *
 * Purpose:       read speed threshold 2
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: speed threshold 2
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_GetDCASpeedThreshold2(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCASpeedThreshold2
 *
 * Purpose:       write speed threshold 2
 *
 * Inputs:        eDevice  - SMC device
 *                u32Value - speed threshold 2
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCASpeedThreshold2(smc_dev_e eDevice, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      eSMC_GetDCATableDataSelection
 *
 * Purpose:       read table data selection value
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: table data selection value
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_table_data_selection_e eSMC_GetDCATableDataSelection(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCATableDataSelection
 *
 * Purpose:       write table data selection value
 *
 * Inputs:        eDevice  - SMC device
 *                u32Value - table data selection value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCATableDataSelection(smc_dev_e eDevice, smc_table_data_selection_e eValue);

/****************************************************************************
 *
 * Function:      eSMC_GetDCATableDataDirection
 *
 * Purpose:       read table data direction value
 *
 * Inputs:        eDevice  - SMC device
 *
 * Outputs:       none
 *
 * Return Values: table data direction value
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_table_data_direction_e eSMC_GetDCATableDataDirection(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDCATableDataDirection
 *
 * Purpose:       write table data direction value
 *
 * Inputs:        eDevice  - SMC device
 *                eValue   - Value 
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDCATableDataDirection(smc_dev_e eDevice, smc_table_data_direction_e eValue);

/****************************************************************************
 *
 * Function:      u8SMC_GetZPDIndexIncrement
 *
 * Purpose:       read index increment to subdivide measurement period
 *
 * Inputs:        eDevice  - SMC device
 *
 * Outputs:       none
 *
 * Return Values: index increment
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetZPDIndexIncrement(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetZPDIndexIncrement
 *
 * Purpose:       write index increment to subdivide measurement period
 *
 * Inputs:        eDevice - SMC device
 *                u8Value - index increment value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetZPDIndexIncrement(smc_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      eSMC_GetZPDQuadrantZPDIsIn
 *
 * Purpose:       read quadrant where the zero point is in
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: quadrant where the zero point is in
 *
 * Limitations:   none
 *
 ***************************************************************************/
smc_quadrant_e eSMC_GetZPDQuadrantZPDIsIn(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      u8SMC_GetZPDScanningFrequency
 *
 * Purpose:       read scanning frequency for scan fscan
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: scanning frequency
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetZPDScanningFrequency(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetZPDScanningFrequency
 *
 * Purpose:       write scanning frequency for scan fscan
 *
 * Inputs:        eDevice - SMC device
 *                u8Value - scanning frequency value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetZPDScanningFrequency(smc_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      u8SMC_GetZPDVoltageThreshold
 *
 * Purpose:       read voltage reference value
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: voltage reference value
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8SMC_GetZPDVoltageThreshold(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetZPDVoltageThreshold
 *
 * Purpose:       write voltage reference value
 *
 * Inputs:        eDevice - SMC device
 *                u8Value - voltage reference value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetZPDVoltageThreshold(smc_dev_e eDevice, uint8_t u8Value);

/****************************************************************************
 *
 * Function:      vSMC_WriteZPDTable
 *
 * Purpose:       write ZPD-table values
 *
 * Inputs:        eDevice        - SMC device
 *                u8Length       - length of table
 *                u32TableValues - pointer to ZPD-table values
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_WriteZPDTable(smc_dev_e eDevice, uint8_t u8Length, const uint32_t * u32TableValues);

/****************************************************************************
 *
 * Function:      vSMC_WriteISMTable
 *
 * Purpose:       write ISM-table values
 *
 * Inputs:        u32TableValues - pointer to ZPD-table values
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_WriteISMTable(const uint32_t * u32TableValues);

/****************************************************************************
 *
 * Function:      f32SMC_GetDegreePerFullstep
 *
 * Purpose:       Get internal value for rotation angle in degree for one
 *                full step
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: rotation angle in degree for one full step
 *
 * Limitations:   none
 *
 ***************************************************************************/
float32_t f32SMC_GetDegreePerFullstep(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SetDegreePerFullstep
 *
 * Purpose:       set internal value for rotation angle in degree for one
 *                full step
 *
 * Inputs:        eDevice  - SMC device
 *                f32Value - rotation angle in degree for one full step
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SetDegreePerFullstep(smc_dev_e eDevice, float32_t f32Value);

/****************************************************************************
 *
 * Function:      vSMC_GeneralConfig
 *
 * Purpose:       configure general settings of SMC IP
 *
 * Inputs:        eDevice         - SMC device
 *                pstGeneralConfig - pointer to configuration structure
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_GeneralConfig(smc_dev_e eDevice, const smc_generalconfig_st * pstGeneralConfig);

/****************************************************************************
 *
 * Function:      vSMC_IsmConfig
 *
 * Purpose:       configure ISM mode of SMC IP
 *
 * Inputs:        eDevice     - SMC device
 *                pstIsmConfig - pointer to configuration structure
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_IsmConfig(smc_dev_e eDevice, const smc_ismconfig_st * pstIsmConfig);

/****************************************************************************
 *
 * Function:      vSMC_PwmConfig
 *
 * Purpose:       configure PWM mode of SMC IP
 *
 * Inputs:        eDevice     - SMC device
 *                pstPwmConfig - pointer to configuration structure
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_PwmConfig(smc_dev_e eDevice, const smc_pwmvalue_st * pstPwmConfig);

/****************************************************************************
 *
 * Function:      vSMC_ZPDConfig
 *
 * Purpose:       configure ZPD mode of SMC IP
 *
 * Inputs:        eDevice     - SMC device
 *                pstZpdConfig - pointer to configuration structure
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_ZPDConfig(smc_dev_e eDevice, const smc_zpdconfig_st * pstZpdConfig);

/****************************************************************************
 *
 * Function:      boSMC_WaitForZPDEnd
 *
 * Purpose:       wait for ZPD interrupt
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE on success
 *                C_FALSE on invalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boSMC_WaitForZPDEnd(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      boSMC_MoveToZeroPosition
 *
 * Purpose:       rotate motor to zero position
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE on success
 *                C_FALSE on invalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boSMC_MoveToZeroPosition(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_ISMUpdateVariablesBeforeRead
 *
 * Purpose:       Update ISM-variables before read access
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_ISMUpdateVariablesBeforeRead(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      vSMC_SwitchFromZPDToISM
 *
 * Purpose:       switch from ZPD to ISM mode
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vSMC_SwitchFromZPDToISM(smc_dev_e eDevice);

/****************************************************************************
 *
 * Function:      u32SMC_SwitchFromZPDToPWM
 *
 * Purpose:       switch from ZPD to PWM mode
 *
 * Inputs:        eDevice - SMC device
 *
 * Outputs:       none
 *
 * Return Values: quadrant
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32SMC_SwitchFromZPDToPWM(smc_dev_e eDevice);

/****************************************************************************/


#endif /* SMC_H */

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

