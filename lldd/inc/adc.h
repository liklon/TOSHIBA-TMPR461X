/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : ADC low level driver header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : ADC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.9 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef ADC_H
#define ADC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_ADC_H_REVISION     "$Revision: 1.9 $"
#define LLDD_ADC_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/

/*!< Operation mode */
typedef enum tag_adc_operation_mode_e
{
    ADC_CONVERSION_MODE    = 0U,    /*!< normal conversion mode */
    ADC_HP_CONVERSION_MODE = 1U,    /*!< high priority conversion mode */
    ADC_COMPARE_MODE       = 2U     /*!< compare mode */
} adc_operation_mode_e;

/*!< smc device no. */
typedef enum tag_adc_device_e
{
   ADC0  =  0U,               /*!< ADC device  0 */
   ADC1  =  1U,               /*!< ADC device  1 */
   ADC2  =  2U,               /*!< ADC device  2 */
   ADC3  =  3U,               /*!< ADC device  3 */
   ADC4  =  4U,               /*!< ADC device  4 */
   ADC5  =  5U,               /*!< ADC device  5 */
   ADC6  =  6U,               /*!< ADC device  6 */
   ADC7  =  7U,               /*!< ADC device  7 */
   ADC8  =  8U,               /*!< ADC device  8 */
   ADC9  =  9U,               /*!< ADC device  9 */
   ADC10 = 10U,               /*!< ADC device 10 */
   ADC11 = 11U,               /*!< ADC device 11 */
   ADC12 = 12U,               /*!< ADC device 12 */
   ADC13 = 13U,               /*!< ADC device 13 */
   ADC14 = 14U,               /*!< ADC device 14 */
   ADC15 = 15U                /*!< ADC device 15 */
} adc_device_e;

/*!< Scan mode */
typedef enum tag_adc_channel_scan_mode_e
{
    ADC_ONE_CHANNEL_MODE  = 0U,    /*!< One channel mode */
    ADC_CHANNEL_SCAN_MODE = 1U     /*!< Channel scan mode */
} adc_channel_scan_mode_e;

/*!< Repeat mode */
typedef enum tag_adc_repeat_mode_e
{
    ADC_SINGLE_CONVERSION   = 0U,    /*!< Single conversion */
    ADC_REPEATED_CONVERSION = 1U     /*!< Repeated conversion */
} adc_repeat_mode_e;

/*!< Delayed mode enable */
typedef enum tag_adc_delayed_mode_e
{
    ADC_START_IMMEDIATELLY = 0U,    /*!< Start next conversion immediatelly */
    ADC_START_AFTER_READ   = 1U     /*!< Start next conversion after result register read */
} adc_delayed_mode_e;

/*!< Interrupt generation */
typedef enum tag_adc_interrupt_generation_mode_e
{
    ADC_INTERRUPT_AFTER_EACH_CONVERSION   = 0U,    /*!< Interrupt is generated after each conversion */
    ADC_INTERRUPT_EVERY_FOURTH_CONVERSION = 1U     /*!< Interrupt is generated every fourth conversion */
} adc_interrupt_generation_mode_e;

/*!< Trigger */
typedef enum tag_adc_trigger_type_e
{
    ADC_SOFTWARE_TRIGGER = 0U,    /*!< Software trigger */
    ADC_HARDWARE_TRIGGER = 1U     /*!< Hardware trigger */
} adc_trigger_type_e;

/*!< trigger selection */
typedef enum tag_adc_trigger_selection_e
{
    ADC_TRIGGER_COMPLEX_TIMER_4 = 0U,    /*!< Comples timer 4 */
    ADC_TRIGGER_COMPLEX_TIMER_5 = 1U,    /*!< Comples timer 5 */
    ADC_TRIGGER_EXTERNAL        = 2U     /*!< Rising edge on external trigger */
} adc_trigger_selection_e;

/*!< Reset */
typedef enum tag_adc_reset_e
{
    ADC_NORMAL_OPERATION = 0U,    /*!< Normal operation */
    ADC_RESET            = 1U     /*!< Reset */
} adc_reset_e;

/*!< Conversion busy status */
typedef enum tag_adc_conversion_busy_status_e
{
    ADC_CONVERTER_INACTIVE    = 0U,    /*!< converter inactive */
    ADC_CONVERTER_IN_PROGRESS = 1U     /*!< conversion in progress */
} adc_conversion_busy_status_e;

/*!< Conversion events */
typedef enum tag_adc_events_e
{
    ADC_NO_EVENTS_OCCURED  = 0x0U,    /*!< No  hp event occured */
    ADC_ONE_EVENTS_OCCURED = 0x01U,   /*!< One hp event occured */
    ADC_TWO_EVENTS_OCCURED = 0x03U    /*!< One hp event occured */
} adc_events_e;

/*!< High priority conversion request */
typedef enum tag_adc_hp_priority_conversion_request_e
{
    ADC_NO_INTERRUPTION = 0U,    /*!< no interruption of normal operation */
    ADC_INTERRUPTION    = 1U     /*!< interruption of normal operation */
} adc_hp_priority_conversion_request_e;

/*!<  */
typedef enum tag_adc_compare_channel_e
{
    ADC_COMPARE_CHANNEL_0 = 0U,    /*!< channel 0 */
    ADC_COMPARE_CHANNEL_1 = 1U     /*!< channel 1 */
} adc_compare_channel_e;

/*!< Interrupt enable for compare interrupt */
typedef enum tag_adc_compare_interrupt_e
{
    ADC_COMPARE_INTERRUPT_DISABLED = 0U,    /*!< compare interrupt disabled */
    ADC_COMPARE_INTERRUPT_SECOND   = 1U     /*!< compare interrupt after second conversion */
} adc_compare_interrupt_e;

/*!< Compare condition */
typedef enum tag_adc_compare_condition_e
{
    ADC_INPUT_SMALLER_VALUE = 0U,    /*!< input channel value is < compare value 1 */
    ADC_INPUT_LARGER_VALUE  = 1U     /*!< input channel value is >= compare value 1 */
} adc_compare_condition_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/*!< adc conversion config */
typedef struct tag_adc_conversion_config
{
    adc_device_e                    eDevice;                  /*!< Device */
    adc_channel_scan_mode_e         eChannelScanMode;         /*!< Channel scan mode */
    adc_repeat_mode_e               eRepeatMode;              /*!< Repeat mode */
    adc_delayed_mode_e              eDelayedMode;             /*!< Delay mode */
    adc_interrupt_generation_mode_e eInterruptGenerationMode; /*!< Interrupt generation mode */
    adc_trigger_type_e              eTriggerType;             /*!< Trigger type */
    adc_trigger_selection_e         eTriggerSelection;        /*!< Trigger selection */
} adc_conversion_config;

/*!< High priority conversion configuration */
typedef struct tag_adc_hp_conversion_config
{
    adc_device_e                         eDevice;                    /*!< Device */
    adc_hp_priority_conversion_request_e ePriorityConversionRequest; /*!< Priority conversion request */
} adc_hp_conversion_config;

/*!<  */
typedef struct tag_adc_compare_config
{
    adc_device_e            eDevice;              /*!< Device */
    uint16_t                u16CompareValue;      /*!< Compare value */
    adc_compare_interrupt_e eCompareInterrupt;    /*!< Compare interrupt */
    adc_compare_condition_e eCompareCondition;    /*!< Compare condition */
} adc_compare_config;

/*********************************************/

/**********************************************
*            Forward declarations             *
**********************************************/

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/**
* @brief Implementation of function vADC_GetVersion
*
* Retrieve pointers to module and header revision and tag string
*
* @note No Limitations
*
* @param[in] None
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
void vADC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/**
* @brief Implementation of function i32ADC_InputChannelSelection
*
* Enable or disable module clock
*
* @note No Limitations
*
* @param[in] eMode     ADC mode
* @param[in] eDevice   Input device
*
* @param[in,out] None
*
* @return C_SUCCESS on success
*         C_FAILED on ivalid parameter range
*/
int32_t i32ADC_InputChannelSelection(adc_operation_mode_e eMode, adc_device_e eDevice);

/**
* @brief Implementation of function vADC_CompareInputChannelSelection
*
* Read result
*
* @note No Limitations
*
* @param[in] eChannel   Comparator channel
* @param[in] eDevice    ADC device
*
* @param[in,out] None
*
* @return void
*/
void vADC_CompareInputChannelSelection(adc_compare_channel_e eChannel, adc_device_e eDevice);

/**
* @brief Implementation of function vADC_AdcConversionConfig
*
* Configure ADC for normal conversion
*
* @note No Limitations
*
* @param[in] eConfig   ADC conversion configuration
*
* @param[in,out] None
*
* @return void
*/
void vADC_AdcConversionConfig(adc_conversion_config eConfig);

/**
* @brief Implementation of function vADC_ApplyReset
*
* Apply reset to ADC module
*
* @note No Limitations
*
* @param[in] void
*
* @param[in,out] None
*
* @return void
*/
void vADC_ApplyReset(void);

/**
* @brief Implementation of function vADC_StartConversion
*
* Start ADC-conversion
*
* @note No Limitations
*
* @param[in] void
*
* @param[in,out] None
*
* @return void
*/
void vADC_StartConversion(void);

/**
* @brief Implementation of function vADC_WaitForAdcCompletion
*
* Busy wait for completion of ADC-conversion
*
* @note No Limitations
*
* @param[in] void
*
* @param[in,out] None
*
* @return void
*/
void vADC_WaitForAdcCompletion(void);


/**
* @brief Implementation of function vADC_WaitForCompletion
*
* Configure ADC for HP conversion
*
* @note No Limitations
*
* @param[in] eConfig   ADC HP-conversion configuration
*
* @param[in,out] None
*
* @return void
*/
void vADC_AdcHpConversionConfig(adc_hp_conversion_config eConfig);


/**
* @brief Implementation of function i32ADC_CompareConfig
*
* Configure ADC for compare operation
*
* @note No Limitations
*
* @param[in] eChannel    Compare channel
* @param[in] eConfig     Configuration of compare operation
*
* @param[in,out] None
*
* @return C_SUCCESS on success
*         C_FAILED  on ivalid parameter range
*/
int32_t i32ADC_CompareConfig(adc_compare_channel_e eChannel, adc_compare_config eConfig);


/**
* @brief Implementation of function i32ADC_SetCompareValue
*
* Set compare value
*
* @note No Limitations
*
* @param[in] eChannel           Compare channel
* @param[in] u16CompareValue    Compare value
*
* @param[in,out] None
*
* @return C_SUCCESS on success
*         C_FAILED  on ivalid parameter range
*/
int32_t i32ADC_SetCompareValue(adc_compare_channel_e eChannel, uint16_t u16CompareValue);


/**
* @brief Implementation of function i32ADC_WaitForCompareCompletion
*
* Wait for completion of compare operation
*
* @note No Limitations
*
* @param[in] eChannel    Compare channel
*
* @param[in,out] None
*
* @return C_SUCCESS on success
*         C_FAILED  on invalid parameter range
*/
int32_t i32ADC_WaitForCompareCompletion(adc_compare_channel_e eChannel);


/**
* @brief Implementation of function i8ADC_ReadResult
*
* Read result
* Only if result is valid and no result was lost a value is send back.
*
* @note No Limitations
*
* @param[in] eDevice    ADC device
*
* @param[in,out] u16Result  pointer to result value
*
* @return C_SUCCESS on success
*         C_FAILED  if result is not valid or a result was lost
*/
int8_t i8ADC_ReadResult(adc_device_e eDevice, uint16_t * u16Result);


/**
* @brief Implementation of function i8ADC_ReadHighPriorityResult
*
* Read high priority result
* Only if result is valid and no result was lost a value is send back.
*
* @note No Limitations
*
* @param[in] void
*
* @param[in,out] u16Result  pointer to result value
*
* @return C_SUCCESS on success
*         C_FAILED  if result is not valid or a result was lost
*/
int8_t i8ADC_ReadHighPriorityResult(uint16_t * u16Result);

/**
* @brief Implementation of function eADC_GetProcessStatus
*
* Read high priority status
*
* @note No Limitations
*
* @param[in] void
*
* @param[in,out] None
*
* @return ADC status
*/
adc_conversion_busy_status_e eADC_GetProcessStatus(void);

/**
* @brief Implementation of function eADC_GetEventsCount
*
* Read nomber of events for high priority, since last ADC read (bits will be cleared after read)
*
* @note No Limitations
*
* @param[in] void
*
* @param[in,out] None
*
* @return ADC events no.
*/
adc_events_e eADC_GetEventsCount(void);

/****************************************************************************/


#endif /* ADC_H */

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

