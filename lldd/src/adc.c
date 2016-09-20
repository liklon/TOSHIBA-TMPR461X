/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : ADC low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : ADC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.10 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "adc_io.h"                   /* ADC registers, bits and access macros defintion */
#include "adc.h"                      /* Own definitions */

/*********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error (used for result of i/o header amcros) */
  
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : conversion from underlying type, "int", to same width underlying type, "uint32_t", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : implicit conversion of complex expression from underlying type, "type", to underlying type, "type", not allowed */
#endif /* defined(__GHS__) || defined(__ghs__) */

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_ADC_C_REVISION     "$Revision: 1.10 $"
#define LLDD_ADC_C_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8LLDD_ADC_C_REVISION[]    = LLDD_ADC_C_REVISION;
static uint8_t au8LLDD_ADC_C_TAG[]         = LLDD_ADC_C_TAG;
static uint8_t au8LLDD_ADC_H_REVISION[]    = LLDD_ADC_H_REVISION;
static uint8_t au8LLDD_ADC_H_TAG[]         = LLDD_ADC_H_TAG;
static uint8_t au8LLDD_ADC_IO_H_REVISION[] = LLDD_ADC_IO_H_REVISION;
static uint8_t au8LLDD_ADC_IO_H_TAG[]      = LLDD_ADC_IO_H_TAG;

/*********************************************/

/**********************************************
*             Function definition             *
**********************************************/

void vADC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_ADC_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_ADC_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_ADC_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_ADC_H_TAG[0];
   *pau8IORevision     = &au8LLDD_ADC_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_ADC_IO_H_TAG[0];
}


/****************************************************************************/

int32_t i32ADC_InputChannelSelection(adc_operation_mode_e eMode, adc_device_e eDevice)
{
    int32_t i32Res = C_SUCCESS;

    switch (eMode)
    {
        case ADC_CONVERSION_MODE:
            {
                vSetADCMOD_ADCH((uint32_t)eDevice);
            }
            break;
        case ADC_HP_CONVERSION_MODE:
            {
                vSetADCHP_HPCH((uint16_t)eDevice);
            }
            break;
        default:
            {
                i32Res = C_FAILED;
            }
            break;
    }

    return i32Res;
}


/****************************************************************************/

void vADC_CompareInputChannelSelection(adc_compare_channel_e eChannel, adc_device_e eDevice)
{
    vSetADCCMP_CCH(eChannel, eDevice);
}


/****************************************************************************/

void vADC_AdcConversionConfig(adc_conversion_config eConfig)
{
    vSetADCMOD_ADCH((uint32_t)eConfig.eDevice);
    vSetADCMOD_SCAN((uint32_t)eConfig.eChannelScanMode);
    vSetADCMOD_REP((uint32_t)eConfig.eRepeatMode);
    vSetADCMOD_DME((uint32_t)eConfig.eDelayedMode);
    vSetADCMOD_ITM((uint32_t)eConfig.eInterruptGenerationMode);
    vSetADCMOD_TRGE((uint32_t)eConfig.eTriggerType);
    vSetADCMOD_TSEL((uint32_t)eConfig.eTriggerSelection);
}


/****************************************************************************/

void vADC_ApplyReset(void)
{
    vSetADCMOD_ADC_RT((uint32_t)ADC_RESET);
    vSetADCMOD_ADC_RT((uint32_t)ADC_NORMAL_OPERATION);
}


/****************************************************************************/

void vADC_StartConversion(void)
{
    vSetADCSTA_ADSFT((uint8_t)1U);
}


/****************************************************************************/

void vADC_WaitForAdcCompletion(void)
{
    while(biGetADCSTA_BUSY() == 1U){}
    while (biGetADCSTA_EOS() == 0U){}
    vClrADCSTA_EOS();
}


/****************************************************************************/

void vADC_AdcHpConversionConfig(adc_hp_conversion_config eConfig)
{
    vSetADCHP_HPCH((uint8_t)eConfig.eDevice);
    vSetADCHP_HPRQ((uint8_t)eConfig.ePriorityConversionRequest);
}


/****************************************************************************/

int32_t i32ADC_CompareConfig(adc_compare_channel_e eChannel, adc_compare_config eConfig)
{
    int32_t i32Res = C_SUCCESS;

    if (eChannel <= ADC_COMPARE_CHANNEL_1)
    {
        vSetADCCMP_CVAL(eChannel, (uint32_t)eConfig.u16CompareValue);
        vSetADCCMP_CINT(eChannel, (uint32_t)eConfig.eCompareInterrupt);
        vSetADCCMP_CCON(eChannel, (uint32_t)eConfig.eCompareCondition);
        vSetADCCMP_CCH(eChannel,  (uint32_t)eConfig.eDevice);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32ADC_SetCompareValue(adc_compare_channel_e eChannel, uint16_t u16CompareValue)
{
    int32_t i32Res = C_SUCCESS;

    if (eChannel <= ADC_COMPARE_CHANNEL_1)
    {
        vSetADCCMP_CVAL(eChannel, u16CompareValue);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32ADC_WaitForCompareCompletion(adc_compare_channel_e eChannel)
{
    int32_t i32Res = C_SUCCESS;

    if (eChannel <= ADC_COMPARE_CHANNEL_1)
    {
        while(biGetADCCMP_CMON(eChannel) == 1U){}
        vClrADCCMP_CMON((uint32_t)eChannel);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int8_t i8ADC_ReadResult(adc_device_e eDevice, uint16_t * u16Result)
{
    int8_t   i8Res;
    uint16_t u16ResVal;

    u16ResVal = u16GetADCRES(eDevice);

    if ((0x4000U == (u16ResVal & 0x4000U)) || (0x0000U == (u16ResVal & 0x8000U)))
    {
        *u16Result = 0U;
        i8Res      = C_FAILED;
    }
    else
    {
        *u16Result = (uint16_t)biGetADCRES_DAT(eDevice);
        i8Res      = C_SUCCESS;
    }

    return i8Res;
}


/****************************************************************************/

int8_t i8ADC_ReadHighPriorityResult(uint16_t * u16Result)
{
    int8_t  i8Res;
    uint8_t u8Ovr, u8Val;

    u8Ovr = (uint8_t)biGetADCHPR_OVR();
    u8Val =	(uint8_t)biGetADCHPR_VAL();
    if ((1U == u8Ovr) || (0U == u8Val))
    {
        *u16Result = 0U;
        i8Res      = C_FAILED;
    }
    else
    {
        *u16Result = (uint16_t)biGetADCHPR_DAT();
        i8Res      = C_SUCCESS;
    }

    return i8Res;
}
/****************************************************************************/
adc_conversion_busy_status_e eADC_GetProcessStatus(void)
{
    adc_conversion_busy_status_e eStatus;

    eStatus = (biGetADCHP_HP() == 0x0U) ? ADC_CONVERTER_INACTIVE : ADC_CONVERTER_IN_PROGRESS;

    return eStatus;
}

/****************************************************************************/
adc_events_e eADC_GetEventsCount(void)
{
    adc_events_e eEventsNo;

    eEventsNo = (adc_events_e)biGetADCHP_HPE();

    return eEventsNo;
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
** **************************************************************************
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

