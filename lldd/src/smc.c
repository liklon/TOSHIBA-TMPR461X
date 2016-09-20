/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Stepper motor controler low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : 
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.13 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "smc_io.h"                   /* stepper_motor registers, bits and access macros defintion */
#include "smc.h"                      /* Own definitions */

/*********************************************/
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */  
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error (used for result of i/o header amcros) */
  #pragma ghs nowarning 1835  /* Rule 11.4 [A] : allow cast from type "type" to type "type" */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1877  /* Rule 11-3 [A] : cast of 0 from type "type" to type "type" not allowed */
  #pragma ghs nowarning 1853  /* Rule 12.6 [A] : effectively boolean expression required */
  #pragma ghs nowarning 1855  /* Rule 13.2 [A] : Explicit test of a value against zero unless the expression is Boolean */
  
  #pragma ghs nowarning 1752  /* Rule 17.4 [R] : disable "pointer arithmetic not allowed"  for usage of io header files */
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1848  /* Rule 10.4 [R] : cast of complex floating point expression from type "type" to type "type" not allowed */
  #pragma ghs nowarning 1849  /* Rule 8.1  [R] : bitwise ~ or << expression must be immediately cast back to  underlying type, "unsigned char" */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
#endif

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_SMC_C_REVISION     "$Revision: 1.13 $"
#define LLDD_SMC_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8LLDD_SMC_C_REVISION[]    = LLDD_SMC_C_REVISION;
static uint8_t au8LLDD_SMC_C_TAG[]         = LLDD_SMC_C_TAG;
static uint8_t au8LLDD_SMC_H_REVISION[]    = LLDD_SMC_H_REVISION;
static uint8_t au8LLDD_SMC_H_TAG[]         = LLDD_SMC_H_TAG;
static uint8_t au8LLDD_SMC_IO_H_REVISION[] = LLDD_SMC_IO_H_REVISION;
static uint8_t au8LLDD_SMC_IO_H_TAG[]      = LLDD_SMC_IO_H_TAG;

/*********************************************/
static float32_t f32DegreePerFullstepVal[5];
static smc_ism_table_mode_e eTableModeVal[5];

static float32_t f32ISMQuadrantOffset[5] = {(float32_t)0.0, (float32_t)0.0, (float32_t)0.0, (float32_t)0.0, (float32_t)0.0};

static float32_t f32RegToFloat(uint32_t u32Value, float32_t f32DegreePerFullstepLocal, smc_ism_table_mode_e eTableModeLocal);
static uint32_t u32SMC_FloatToReg(float32_t f32Value, float32_t f32DegreePerFullstepLocal, smc_ism_table_mode_e eTableModeLocal);

/**********************************************
*             Function definition             *
**********************************************/

void vSMC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_SMC_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_SMC_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_SMC_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_SMC_H_TAG[0];
   *pau8IORevision     = &au8LLDD_SMC_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_SMC_IO_H_TAG[0];
}

/****************************************************************************/

bool_t boSMC_SetPrescaler(uint8_t u8Value)
{
    bool_t boRes = C_TRUE;
    if ( (u8Value >= ((uint8_t)SMC_SCLFAK_MIN)) && (u8Value <= ((uint8_t)SMC_SCLFAK_MAX)) )
    {
        vSetSMCCLK_CTRL_PRE_SCALE(u8Value);
    }
    else
    {
        boRes = C_FALSE;
    }
    return boRes;
}

/****************************************************************************/

uint8_t u8SMC_GetPrescaler(void)
{
   return biGetSMCCLK_CTRL_PRE_SCALE();
}

/****************************************************************************/

smc_enable_e eSMC_GetIntConfigReg(void)
{
    smc_enable_e eResult;
    
    eResult = ( 0x01U == biGetSMCINT_CRAUM() ) ? SMC_ENABLE : SMC_DISABLE;
    
    return eResult;
}

/****************************************************************************/

bool_t boSMC_GetIntSingle(smc_dev_e eDevice, smc_motint_types_e eIntMask, smc_enable_e* peEnable)
{
    bool_t  boResult = C_TRUE;
    uint8_t u8Value;
   
    if (( C_NULL != peEnable) && (eDevice <= SMC4) )
    {
        switch(eIntMask)
        {
            case SMC_INT_PPE:
                {
                    u8Value = (uint8_t) biGetSMCINT_PPE();
                }
                break;
            case SMC_INT_MOW_END:
                {
                    u8Value = (uint8_t) biGetSMCINT_MOV_END(); 
                }
                break;
            case SMC_INT_ZPD:
                {
                    u8Value = (uint8_t) biGetSMCINT_ZPDD();
                }
                break;
            default:
                {
                    boResult = C_FALSE;
                }
		            break;
        }
   }

   if (C_TRUE == boResult)
   {
       *peEnable = ( (0x01U<<eDevice)& u8Value) ? SMC_ENABLE : SMC_DISABLE;
   }
   return boResult;
}

/****************************************************************************/

uint32_t u32SMC_GetIntAll(void)
{
    return u32GetSMCINT();
}

/****************************************************************************/
void vSMC_ClearIntConfigReg(void)
{
    vClrSMCINT_CRAUM();
}

/****************************************************************************/
bool_t boSMC_ClearIntSingle(smc_dev_e eDevice, smc_motint_types_e eIntType)
{
    bool_t  boResult = C_TRUE;
    
    if (eDevice <= SMC4)
    {
        switch(eIntType)
        {
            case SMC_INT_PPE:
                vClrSMCINT_PPE((uint8_t)eDevice);
                break;

            case SMC_INT_MOW_END:
                vClrSMCINT_MOV_END((uint8_t)eDevice);
                break;

            case SMC_INT_ZPD:
                vClrSMCINT_ZPDD((uint8_t)eDevice);
                break;

            default:
                boResult = C_FALSE;
		            break;
        }
    }
    else
    {
        boResult = C_FALSE;
    }
     return boResult;
}
 
/****************************************************************************/
 
void vSMC_ClearIntAll(uint32_t u32Value)
{
    vSetSMCINT(u32Value);
}

/****************************************************************************/
void vSetIntConfReg(smc_enable_e eEnable)
{
    vSetSMCINT_MASK_MASK_CRAUM((uint32_t)eEnable);
}

/****************************************************************************/

bool_t boSMC_SetIntMaskSingle(smc_dev_e eDevice, smc_motint_types_e eIntType, smc_enable_e eEnable)
{
    bool_t boRes = C_TRUE;
    uint32_t u32Mask;
    if (eDevice <= SMC4 )
    {
        switch(eIntType)
        {
            case SMC_INT_PPE:
                /* read bit fields: */
                u32Mask = (uint32_t)biGetSMCINT_MASK_MASK_PPE();
                if (SMC_ENABLE == eEnable)
                {
                    /* set related bit: */
                    u32Mask |= ((uint32_t)0x01U << (uint8_t)eDevice);
                }
                else
                {
                    /* reset related bit: */
                    u32Mask &= (~((uint32_t)0x01U << (uint8_t)eDevice));
                }
                /* write back bit fields: */
                vSetSMCINT_MASK_MASK_PPE(u32Mask);
                break;
                
            case SMC_INT_MOW_END:
                u32Mask = biGetSMCINT_MASK_MASK_MOV_END();
                if (SMC_ENABLE == eEnable)
                {
                    /* set related bit: */
                    u32Mask |= ((uint32_t)0x01U << (uint8_t)eDevice);
                }
                else
                {
                    /* reset related bit: */
                    u32Mask &= (~((uint32_t)0x01U << (uint8_t)eDevice));
                }
                vSetSMCINT_MASK_MASK_MOV_END(u32Mask);
                break;
                
            case SMC_INT_ZPD:
                u32Mask = biGetSMCINT_MASK_MASK_ZPDD();
                if (SMC_ENABLE == eEnable)
                {
                    /* set related bit: */
                    u32Mask |= ((uint32_t)0x01U << (uint8_t)eDevice);
                }
                else
                {
                    /* reset related bit: */
                    u32Mask &= (~((uint32_t)0x01U << (uint8_t)eDevice));
                }
               vSetSMCINT_MASK_MASK_ZPDD(u32Mask);
                break;

            default:
                boRes = C_FALSE;
		            break;
        }
    }
    else
    {
        boRes = C_FALSE;
    }


    return boRes;
}

/****************************************************************************/

void vSMC_SetIntMaskAll(uint32_t u32Mask)
{
   vSetSMCINT_MASK(u32Mask);
}

/****************************************************************************/

uint32_t u32SMC_GetIntMaskAll(void)
{
    return u32GetSMCINT_MASK();
}

/****************************************************************************/

smc_channel_mode_e eSMC_GetChannelMode(smc_dev_e eDevice)
{
   return (smc_channel_mode_e)biGetSMCCTRL_MSEL(eDevice);
}

/****************************************************************************/

void vSMC_SetChannelMode(smc_dev_e eDevice, smc_channel_mode_e eMode)
{
   vSetSMCCTRL_MSEL(eDevice, (uint32_t)eMode);
}

/****************************************************************************/

smc_enable_e eSMC_GetPinStatus(smc_dev_e eDevice)
{
   return (smc_enable_e)biGetSMCCTRL_OUTEN(eDevice);
}

/****************************************************************************/

void vSMC_SetPinStatus(smc_dev_e eDevice, smc_enable_e eEnable)
{
   vSetSMCCTRL_OUTEN(eDevice, (uint32_t)eEnable);
}

/****************************************************************************/

uint8_t u8SMC_GetOutputDelayCycleCount(smc_dev_e eDevice)
{
   return ((uint8_t)biGetSMCCTRL_DELAY_CYCLES(eDevice));
}

/****************************************************************************/

void vSMC_SetOutputDelayCycleCount(smc_dev_e eDevice, uint8_t u8Value)
{
   vSetSMCCTRL_DELAY_CYCLES(eDevice, u8Value);
}

/****************************************************************************/

uint8_t u8SMC_GetPeriodExtension(smc_dev_e eDevice)
{
   return ((uint8_t)biGetSMCCTRL_PERIOD_EXT(eDevice));
}

/****************************************************************************/

void vSMC_SetPeriodExtension(smc_dev_e eDevice, uint8_t u8Value)
{
   vSetSMCCTRL_PERIOD_EXT(eDevice, u8Value);
}

/****************************************************************************/

uint8_t u8SMC_GetSlewRate(smc_dev_e eDevice)
{
   return ((uint8_t)biGetSMCCTRL_SLEW_RATE(eDevice));
}

/****************************************************************************/

void vSMC_SetSlewRate(smc_dev_e eDevice, uint8_t u8Value)
{
   vSetSMCCTRL_SLEW_RATE(eDevice, u8Value);
}

/****************************************************************************/

uint8_t u8SMC_GetISMDampingFactorK(smc_dev_e eDevice)
{
   return ((uint8_t)biGetSMCISM_CTRL_DAMP_K(eDevice));
}

/****************************************************************************/

void vSMC_SetISMDampingFactorK(smc_dev_e eDevice, uint8_t u8Value)
{
   vSetSMCISM_CTRL_DAMP_K(eDevice, u8Value);
}

/****************************************************************************/

uint8_t u8SMC_GetISMDampingFactorL(smc_dev_e eDevice)
{
   return ((uint8_t)biGetSMCISM_CTRL_DAMP_L(eDevice));
}

/****************************************************************************/

void vSMC_SetISMDampingFactorL(smc_dev_e eDevice, uint8_t u8Value)
{
   vSetSMCISM_CTRL_DAMP_L(eDevice, u8Value);
}

/****************************************************************************/

smc_ism_table_mode_e eSMC_GetISMTableMode(smc_dev_e eDevice)
{
   return (smc_ism_table_mode_e)biGetSMCISM_CTRL_ISM_TABLE_MODE(eDevice);
}

/****************************************************************************/

void vSMC_SetISMTableMode(smc_dev_e eDevice, smc_ism_table_mode_e eValue)
{
   eTableModeVal[eDevice] = eValue;
   vSetSMCISM_CTRL_ISM_TABLE_MODE(eDevice, (uint32_t)eValue);
}

/****************************************************************************/

smc_table_index_e eSMC_GetISMTableIndex(smc_dev_e eDevice)
{
   return (smc_table_index_e)biGetSMCISM_CTRL_TABLE_IDX(eDevice);
}

/****************************************************************************/

void vSMC_SetISMTableIndex(smc_dev_e eDevice, smc_table_index_e eValue)
{
   vSetSMCISM_CTRL_TABLE_IDX(eDevice, (uint32_t)eValue);
}

/****************************************************************************/

smc_enable_e eSMC_IsISMDampingCurveHardwareEnabled(smc_dev_e eDevice)
{
   /*return (smc_enable_e)(1-biGetSMCISM_CTRL_DIS_DAMP(eDevice));*/
   return ( SMC_ENABLE==((smc_enable_e)biGetSMCISM_CTRL_DIS_DAMP(eDevice)) ) ? SMC_DISABLE : SMC_ENABLE;
}

/****************************************************************************/

void vSMC_EnableISMDampingCurveHardware(smc_dev_e eDevice, smc_enable_e eValue)
{
   vSetSMCISM_CTRL_DIS_DAMP(eDevice, ((eValue == SMC_ENABLE)? (uint32_t)SMC_DISABLE : (uint32_t)SMC_ENABLE));
}

/****************************************************************************/

smc_enable_e eSMC_GetISMReadRequestStatus(smc_dev_e eDevice)
{
   return (smc_enable_e)biGetSMCISM_CTRL_RD_REQ(eDevice);
}

/****************************************************************************/

void vSMC_SetISMReadRequest(smc_dev_e eDevice, smc_enable_e eValue)
{
   vSetSMCISM_CTRL_RD_REQ(eDevice, (uint32_t)eValue);
}

/****************************************************************************/

smc_enable_e eSMC_GetISMReadRequestFlagStatus(smc_dev_e eDevice)
{
   return (smc_enable_e)biGetSMCISM_CTRL_RD_FLAG(eDevice);
}

/****************************************************************************/

smc_enable_e eSMC_GetISMFreezeRequestStatus(smc_dev_e eDevice)
{
   return (smc_enable_e)biGetSMCISM_CTRL_FREEZE_REQ(eDevice);
}

/****************************************************************************/

void vSMC_SetISMFreezeRequest(smc_dev_e eDevice, smc_enable_e eValue)
{
   vSetSMCISM_CTRL_FREEZE_REQ(eDevice, (uint32_t)eValue);
}

/****************************************************************************/

smc_enable_e eSMC_GetISMFreezeRequestFlagStatus(smc_dev_e eDevice)
{
   return (smc_enable_e)biGetSMCISM_CTRL_FREEZE_FLAG(eDevice);
}

/****************************************************************************/

static float32_t f32RegToFloat(uint32_t u32Value, float32_t f32DegreePerFullstepLocal, smc_ism_table_mode_e eTableModeLocal)
{
    float32_t fInteger;
    float32_t fFraction;
    float32_t fValue;
    uint32_t  u32MoveIntegerPart = 13U;
    float32_t f32ScaleFractionalPart = (float32_t)8192.0;
    uint32_t  u32IntMask = 0x3FFU;
    uint32_t  u32FracMask = 0x1FFFU;

    if (eTableModeLocal == SMC_ISM_TABLE_MODE_PRECISE)
    {
        u32MoveIntegerPart = 15U;
        f32ScaleFractionalPart = (float32_t)32768.0;
        u32IntMask = 0xFFU;
        u32FracMask = 0x7FFFU;
    }

    fInteger = (float32_t)((u32Value >> u32MoveIntegerPart) & u32IntMask);
    fFraction = (float32_t)(u32Value & u32FracMask);
    fValue = fInteger + (fFraction/f32ScaleFractionalPart);
    if ((u32Value & 0x01000000U) > 0U)
    {
        fValue = (float32_t)(-1.0) * fValue;
    }

    return (f32DegreePerFullstepLocal * fValue);
}

/****************************************************************************/

static uint32_t u32SMC_FloatToReg(float32_t f32Value, float32_t f32DegreePerFullstepLocal, smc_ism_table_mode_e eTableModeLocal)
{
    uint32_t  u32Sign = 0U;
    uint32_t  u32IntegerPart;
    uint32_t  u32FractionalPart;
    uint32_t  u32Value;
    uint32_t  u32MoveIntegerPart = 13U;
    float32_t f32ScaleFractionalPart = (float32_t)8192.0;

    if (eTableModeLocal == SMC_ISM_TABLE_MODE_PRECISE)
    {
        u32MoveIntegerPart = 15U;
        f32ScaleFractionalPart = (float32_t)32768.0;
    }
    if (f32Value < 0.0)
    {
        u32Sign  = 1U;
        f32Value = (float32_t)-1.0 * f32Value;
    }
    f32Value          = f32Value / f32DegreePerFullstepLocal;
    u32IntegerPart    = (uint32_t)f32Value;
    u32FractionalPart = (uint32_t)(f32ScaleFractionalPart * (f32Value - (float32_t)u32IntegerPart));
    u32Value          = (u32Sign << 24) + (u32IntegerPart << u32MoveIntegerPart) + u32FractionalPart;

    return u32Value;
}

/****************************************************************************/

float32_t fSMC_GetISMPosition(smc_dev_e eDevice)
{
    float32_t fValue;
    uint32_t u32Value;

    u32Value = u32GetSMCPOS_Dest(eDevice);

    fValue = f32RegToFloat((uint32_t)((float32_t)u32Value - f32ISMQuadrantOffset[eDevice]), f32DegreePerFullstepVal[eDevice], eTableModeVal[eDevice]);

    return fValue;
}

/****************************************************************************/

void vSMC_SetISMPosition(smc_dev_e eDevice, float32_t f32Value)
{
    uint32_t u32Value;

    u32Value = u32SMC_FloatToReg(f32Value + f32ISMQuadrantOffset[eDevice], f32DegreePerFullstepVal[eDevice], eTableModeVal[eDevice]);

    vSetSMCPOS_Dest(eDevice, u32Value);
}

/****************************************************************************/

uint16_t u16SMC_GetPWMCosDuty(smc_dev_e eDevice)
{
    return ((uint16_t)biGetSMCPWM_COSDUTY(eDevice));
}

/****************************************************************************/

void vSMC_SetPWMCosDuty(smc_dev_e eDevice, uint16_t u16Value)
{
    vSetSMCPWM_COSDUTY(eDevice, u16Value);
}

/****************************************************************************/

uint16_t u16SMC_GetPWMSinDuty(smc_dev_e eDevice)
{
    return ((uint16_t)biGetSMCPWM_SINDUTY(eDevice));
}

/****************************************************************************/

void vSMC_SetPWMSinDuty(smc_dev_e eDevice, uint16_t u16Value)
{
    vSetSMCPWM_SINDUTY(eDevice, u16Value);
}

/****************************************************************************/

smc_quadrant_e eSMC_GetPWMQuadrant(smc_dev_e eDevice)
{
    return (smc_quadrant_e)biGetSMCPWM_QUADR(eDevice);
}

/****************************************************************************/

void vSMC_SetPWM32BitData(smc_dev_e eDevice, smc_quadrant_e wQuadr, 
                          uint16_t u16Sin, uint16_t u16Cos)
{
   uint32_t u32Value;

   u32Value = ((uint32_t) wQuadr << 20) | (u16Sin<<10) | u16Cos;
   vSetSMCPWM(eDevice, u32Value);
}

/****************************************************************************/

void vSMC_SetPWMQuadrant(smc_dev_e eDevice, smc_quadrant_e eValue)
{
   vSetSMCPWM_QUADR(eDevice, (uint32_t)eValue);
}

/****************************************************************************/

uint32_t u32SMC_GetDCAIntermediateAngle(smc_dev_e eDevice)
{
    float32_t fValue;
    uint32_t u32Value;

    u32Value = biGetSMCDCA_PT1_PT1(eDevice);

    fValue = f32RegToFloat(u32Value, f32DegreePerFullstepVal[eDevice], eTableModeVal[eDevice]);

    return (uint32_t)fValue;
}

/****************************************************************************/

void vSMC_SetDCAIntermediateAngle(smc_dev_e eDevice, float32_t f32Value)
{
    uint32_t u32Value;

    u32Value = u32SMC_FloatToReg(f32Value, f32DegreePerFullstepVal[eDevice], eTableModeVal[eDevice]);

    vSetSMCDCA_PT1_PT1(eDevice, u32Value);
}

/****************************************************************************/

uint32_t u32SMC_GetDCAActualAngle(smc_dev_e eDevice)
{
    float32_t fValue;
    uint32_t u32Value;

    u32Value = biGetSMCDCA_PT2_PT2(eDevice);

    fValue = f32RegToFloat(u32Value, f32DegreePerFullstepVal[eDevice], eTableModeVal[eDevice]);

    return (uint32_t)fValue;
}

/****************************************************************************/

void vSMC_SetDCAActualAngle(smc_dev_e eDevice, float32_t f32Value)
{
    uint32_t u32Value;

    u32Value = u32SMC_FloatToReg(f32Value, f32DegreePerFullstepVal[eDevice], eTableModeVal[eDevice]);

    vSetSMCDCA_PT2_PT2(eDevice, u32Value);
}

/****************************************************************************/

uint32_t u32SMC_GetDCAVelocity(smc_dev_e eDevice)
{
    return biGetSMCDCA_V_OLD_V_OLD(eDevice);
}

/****************************************************************************/

void vSMC_SetDCAVelocity(smc_dev_e eDevice, uint32_t u32Value)
{
    vSetSMCDCA_V_OLD_V_OLD(eDevice, u32Value);
}

/****************************************************************************/

uint32_t u32SMC_GetDCAVelocityLimit(smc_dev_e eDevice)
{
    return biGetSMCDCA_V_MAX_V_MAX(eDevice);
}

/****************************************************************************/

void vSMC_SetDCAVelocityLimit(smc_dev_e eDevice, uint32_t u32Value)
{
    vSetSMCDCA_V_MAX_V_MAX(eDevice, u32Value);
}

/****************************************************************************/

uint32_t u32SMC_GetDCAAcceleration(smc_dev_e eDevice)
{
    return biGetSMCDCA_ACC_ACC(eDevice);
}

/****************************************************************************/

uint32_t u32SMC_GetDCAAccelerationLimit(smc_dev_e eDevice)
{
    return biGetSMCDCA_A_MAX_A_MAX(eDevice);
}

/****************************************************************************/

void vSMC_SetDCAAccelerationLimit(smc_dev_e eDevice, uint32_t u32Value)
{
    vSetSMCDCA_A_MAX_A_MAX(eDevice, u32Value);
}

/****************************************************************************/

uint32_t u32SMC_GetDCADecelerationLimit(smc_dev_e eDevice)
{
    return biGetSMCDCA_D_MAX_D_MAX(eDevice);
}

/****************************************************************************/

void vSMC_SetDCADecelerationLimit(smc_dev_e eDevice, uint32_t u32Value)
{
    vSetSMCDCA_D_MAX_D_MAX(eDevice, u32Value);
}

/****************************************************************************/

uint32_t u32SMC_GetDCASpeedThreshold1(smc_dev_e eDevice)
{
    return biGetSMCDCA_V1_V1TH(eDevice);
}

/****************************************************************************/

void vSMC_SetDCASpeedThreshold1(smc_dev_e eDevice, uint32_t u32Value)
{
    vSetSMCDCA_V1_V1TH(eDevice, u32Value);
}

/****************************************************************************/

uint32_t u32SMC_GetDCASpeedThreshold2(smc_dev_e eDevice)
{
    return biGetSMCDCA_V2_V2TH(eDevice);
}

/****************************************************************************/

void vSMC_SetDCASpeedThreshold2(smc_dev_e eDevice, uint32_t u32Value)
{
    vSetSMCDCA_V2_V2TH(eDevice, u32Value);
}

/****************************************************************************/

smc_table_data_selection_e eSMC_GetDCATableDataSelection(smc_dev_e eDevice)
{
   return (smc_table_data_selection_e)biGetSMCDCA_TS_TS_SEL(eDevice);
}

/****************************************************************************/

void vSMC_SetDCATableDataSelection(smc_dev_e eDevice, smc_table_data_selection_e eValue)
{
   vSetSMCDCA_TS_TS_SEL(eDevice, (uint16_t)eValue);
}

/****************************************************************************/

smc_table_data_direction_e eSMC_GetDCATableDataDirection(smc_dev_e eDevice)
{
   return (smc_table_data_direction_e)biGetSMCDCA_TS_TD_SEL(eDevice);
}

/****************************************************************************/

void vSMC_SetDCATableDataDirection(smc_dev_e eDevice, smc_table_data_direction_e eValue)
{
   vSetSMCDCA_TS_TD_SEL(eDevice, (uint16_t)eValue);
}

/****************************************************************************/

uint8_t u8SMC_GetZPDIndexIncrement(smc_dev_e eDevice)
{
   return ((uint8_t)biGetSMCZPD_CTRL_IDX_INC_N(eDevice));
}

/****************************************************************************/

void vSMC_SetZPDIndexIncrement(smc_dev_e eDevice, uint8_t u8Value)
{
   vSetSMCZPD_CTRL_IDX_INC_N(eDevice, u8Value);
}

/****************************************************************************/

smc_quadrant_e eSMC_GetZPDQuadrantZPDIsIn(smc_dev_e eDevice)
{
   return (smc_quadrant_e)biGetSMCZPD_CTRL_QUAD(eDevice);
}

/****************************************************************************/

uint8_t u8SMC_GetZPDScanningFrequency(smc_dev_e eDevice)
{
   return ((uint8_t)biGetSMCZPD_CTRL_FREQ_N(eDevice));
}

/****************************************************************************/

void vSMC_SetZPDScanningFrequency(smc_dev_e eDevice, uint8_t u8Value)
{
   vSetSMCZPD_CTRL_FREQ_N(eDevice, u8Value);
}

/****************************************************************************/

uint8_t u8SMC_GetZPDVoltageThreshold(smc_dev_e eDevice)
{
   return ((uint8_t)biGetSMCZPD_CTRL_VOLT_REF(eDevice));
}

/****************************************************************************/

void vSMC_SetZPDVoltageThreshold(smc_dev_e eDevice, uint8_t u8Value)
{
   vSetSMCZPD_CTRL_VOLT_REF(eDevice, u8Value);
}

/****************************************************************************/

void vSMC_WriteZPDTable(smc_dev_e eDevice, uint8_t u8Length, const uint32_t * u32TableValues)
{
   uint32_t u32Counter;
   
   for (u32Counter=0U; u32Counter<(uint32_t)u8Length; u32Counter++)
   {
      vSetSMCZPD_TABLE( (32U*(uint32_t)eDevice) + u32Counter, *(u32TableValues+u32Counter));
   }
}

/****************************************************************************/

void vSMC_WriteISMTable(const uint32_t * u32TableValues)
{
   uint32_t u32Counter;
   
   for (u32Counter=0U; u32Counter<1024U; u32Counter++)
   {
      vSetSMCISM_TABLE(u32Counter, *(u32TableValues+u32Counter));
   }
}

/****************************************************************************/
float32_t f32SMC_GetDegreePerFullstep(smc_dev_e eDevice)
{
    return f32DegreePerFullstepVal[eDevice];
}

/****************************************************************************/
void vSMC_SetDegreePerFullstep(smc_dev_e eDevice, float32_t f32Value)
{
    f32DegreePerFullstepVal[eDevice] = f32Value;
}

/****************************************************************************/

void vSMC_GeneralConfig(smc_dev_e eDevice, const smc_generalconfig_st * pstGeneralConfig)
{
   vSetSMCCTRL_DELAY_CYCLES(eDevice, pstGeneralConfig->u8DelayCycleCount);
   vSetSMCCTRL_PERIOD_EXT(eDevice, pstGeneralConfig->u8PeriodExtension);
   vSetSMCCTRL_SLEW_RATE(eDevice, pstGeneralConfig->u8SlewRate);
}

/****************************************************************************/

void vSMC_IsmConfig(smc_dev_e eDevice, const smc_ismconfig_st * pstIsmConfig)
{
   /* internal parameter */
   f32DegreePerFullstepVal[eDevice] = pstIsmConfig->f32DegreePerFullstep;
   eTableModeVal[eDevice] = pstIsmConfig->eTableMode;

   /* DCA config */
   vSMC_SetDCAIntermediateAngle(eDevice, pstIsmConfig->f32IntermediateAngle);
   vSMC_SetDCAActualAngle(eDevice, pstIsmConfig->f32ActualAngle);
   vSetSMCDCA_V_OLD_V_OLD(eDevice, pstIsmConfig->u32Velocity);
   vSetSMCDCA_V_MAX_V_MAX(eDevice, pstIsmConfig->u32VelocityLimit);
   vSetSMCDCA_A_MAX_A_MAX(eDevice, pstIsmConfig->u32AccelerationLimit);
   vSetSMCDCA_D_MAX_D_MAX(eDevice, pstIsmConfig->u32DecelerationLimit);
   vSetSMCDCA_V1_V1TH(eDevice,     pstIsmConfig->u32SpeedThreshold1);
   vSetSMCDCA_V2_V2TH(eDevice,     pstIsmConfig->u32SpeedThreshold2);

   /* ISM config */
   vSetSMCISM_CTRL_DAMP_K(eDevice, pstIsmConfig->u8DampingFactorK);
   vSetSMCISM_CTRL_DAMP_L(eDevice, pstIsmConfig->u8DampingFactorL);
   vSetSMCISM_CTRL_ISM_TABLE_MODE(eDevice, (uint32_t) pstIsmConfig->eTableMode);
   vSetSMCISM_CTRL_TABLE_IDX     (eDevice, (uint32_t) pstIsmConfig->eTableIndex);
   vSetSMCDCA_TS_TS_SEL          (eDevice, (uint16_t) pstIsmConfig->eTableData);
   vSetSMCISM_CTRL_DIS_DAMP      (eDevice, ((SMC_ENABLE== pstIsmConfig->eUseDampingCurveHardware)? (uint32_t)SMC_DISABLE : (uint32_t)SMC_ENABLE) );
}

/****************************************************************************/

void vSMC_PwmConfig(smc_dev_e eDevice, const smc_pwmvalue_st * pstPwmConfig)
{
   vSMC_SetPWM32BitData(eDevice, pstPwmConfig->eQuadrant, pstPwmConfig->u16SinDuty, pstPwmConfig->u16CosDuty);
}

/****************************************************************************/

void vSMC_ZPDConfig(smc_dev_e eDevice, const smc_zpdconfig_st * pstZpdConfig)
{
   vSetSMCZPD_CTRL_IDX_INC_N(eDevice, pstZpdConfig->u8IndexIncrement);
   vSetSMCZPD_CTRL_FREQ_N(eDevice, pstZpdConfig->u8ScanningFrequency);
   vSetSMCZPD_CTRL_VOLT_REF(eDevice, pstZpdConfig->u8VoltageThreshold);
}

/****************************************************************************/

bool_t boSMC_WaitForZPDEnd(smc_dev_e eDevice)
{
    bool_t   boResult = C_TRUE;
    uint32_t u32Mask;
    
    if (eDevice <= SMC4)
    {
        u32Mask = (0x01U<<eDevice);
        while((u32Mask & biGetSMCINT_ZPDD()) == 0U)
        {
            ;
        }
    }
    else
    {
        boResult = C_FALSE;
    }
    return boResult;
}

/****************************************************************************/

bool_t boSMC_MoveToZeroPosition(smc_dev_e eDevice)
{
    bool_t   boResult = C_TRUE;
    uint32_t u32Mask;

    if (eDevice <= SMC4)
    {
        u32Mask = (0x01U<<eDevice);
        /* set mode of channel */
        vSetSMCCTRL_MSEL(eDevice, (uint32_t)SMC_ZPD_MODE);
        
        /* clear interrupt */
        vClrSMCINT_ZPDD(eDevice);
        
        /* set interrupt mask */
        vSetSMCINT_MASK_MASK_ZPDD(u32Mask & (uint32_t)SMC_ENABLE);
        
        /* enable pins */
        vSetSMCCTRL_OUTEN(eDevice, (uint32_t)SMC_ENABLE);
        
        /* wait for end of movement */
        while((u32Mask & biGetSMCINT_ZPDD()) > 0U){}
        
        /* set interrupt mask */
        vSetSMCINT_MASK_MASK_ZPDD(u32Mask & (uint32_t)SMC_DISABLE);
        
        /* clear interrupt */
        vClrSMCINT_ZPDD(eDevice);
    }
   else
   {
       boResult = C_FALSE;
   }
   return boResult;
}

/****************************************************************************/

void vSMC_ISMUpdateVariablesBeforeRead(smc_dev_e eDevice)
{
   vSetSMCISM_CTRL_RD_REQ(eDevice, (uint32_t)SMC_ENABLE);
   while(SMC_ENABLE != (smc_enable_e)biGetSMCISM_CTRL_RD_FLAG(eDevice)) {}
}

/****************************************************************************/

void vSMC_SwitchFromZPDToISM(smc_dev_e eDevice)
{
    uint32_t u32Quadrant;

    vSMC_SetISMFreezeRequest(eDevice, SMC_ENABLE);
    while (SMC_DISABLE == eSMC_GetISMFreezeRequestFlagStatus(eDevice)) {}

    u32Quadrant = biGetSMCZPD_CTRL_QUAD(eDevice);
    f32ISMQuadrantOffset[eDevice] = f32DegreePerFullstepVal[eDevice] * (float32_t)(4U - u32Quadrant);

    vSMC_SetISMPosition(eDevice, (float32_t)0.0);

    vSMC_SetChannelMode(eDevice, SMC_ISM_MODE);
    vSMC_SetISMFreezeRequest(eDevice, SMC_DISABLE);
}

/****************************************************************************/

uint32_t u32SMC_SwitchFromZPDToPWM(smc_dev_e eDevice)
{
    uint32_t u32Quadrant;

    u32Quadrant = biGetSMCZPD_CTRL_QUAD(eDevice);

    vSMC_SetChannelMode(eDevice, SMC_PWM_MODE);

    return u32Quadrant;
}

/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */
/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: smc.c
**  $Revision: 1.13 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :  5 (0286) String literal contains character which is not a
** |                    member of the basic source character set.
** |
** | REASON : This is neccessary because of driver version control.
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1752 / 17.4 - pointer arithmetic not allowed
** | CONS.  : allow
** | REASON : this is necessary to have access to the hw resources 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1847 / 10.3 - cast of complex integer expression with underlying type
** |                        "type" to non-integer type "type" not allowed 
** | CONS.  : disable
** | REASON : to use macros from i/o header files, unavoidable when addressing 
** |          memory mapped registers 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1849 / 8.1 - bitwise ~ or << expression must be immediately cast 
** |                       back to  underlying type, "unsigned char" 
** | CONS.  : allow
** | REASON : necessary for shift oeprations, which we know it will not over run 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1848 / 10.4 : cast of complex floating point expression from type 
** |                        "type" to type "type" not allowed
** | CONS.  : allow
** | REASON : necessary to allow to write integer value of a float data. 
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
**
*****************************************************************************
****************************************************************************/

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

