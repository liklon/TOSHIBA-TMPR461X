/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : DMAC low level driver header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : DMAC
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.18 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef DMAC_H
#define DMAC_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_DMAC_H_REVISION     "$Revision: 1.18 $"
#define LLDD_DMAC_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/

/**
* @brief DMAC enable and disable
*/
typedef enum tag_dmac_enable_e
{
    DMAC_DISABLE = 0,                  /*!< Disable */
    DMAC_ENABLE  = 1                   /*!< Enable */
} dmac_enable_e;


/**
* @brief DMAC channels
*/
typedef enum tag_dmac_channel_e
{
    DMAC_CHANNEL_0 = 0x0,              /*!< DMA channel 0 */
    DMAC_CHANNEL_1 = 0x1,              /*!< DMA channel 1 */
    DMAC_CHANNEL_2 = 0x2,              /*!< DMA channel 2 */
    DMAC_CHANNEL_3 = 0x3,              /*!< DMA channel 3 */
    DMAC_CHANNEL_4 = 0x4,              /*!< DMA channel 4 */
    DMAC_CHANNEL_5 = 0x5,              /*!< DMA channel 5 */
    DMAC_CHANNEL_6 = 0x6,              /*!< DMA channel 6 */
    DMAC_CHANNEL_7 = 0x7               /*!< DMA channel 7 */
} dmac_channel_e;


/**
* @brief DMAC requests
*/
typedef enum tag_dmac_request_e
{
    DMAC_REQUEST_0  = 0x0001,          /*!< DMA request 0 */
    DMAC_REQUEST_1  = 0x0002,          /*!< DMA request 1 */
    DMAC_REQUEST_2  = 0x0004,          /*!< DMA request 2 */
    DMAC_REQUEST_3  = 0x0008,          /*!< DMA request 3 */
    DMAC_REQUEST_4  = 0x0010,          /*!< DMA request 4 */
    DMAC_REQUEST_5  = 0x0020,          /*!< DMA request 5 */
    DMAC_REQUEST_6  = 0x0040,          /*!< DMA request 6 */
    DMAC_REQUEST_7  = 0x0080,          /*!< DMA request 7 */
    DMAC_REQUEST_8  = 0x0100,          /*!< DMA request 8 */
    DMAC_REQUEST_9  = 0x0200,          /*!< DMA request 9 */
    DMAC_REQUEST_10 = 0x0400,          /*!< DMA request 10 */
    DMAC_REQUEST_11 = 0x0800,          /*!< DMA request 11 */
    DMAC_REQUEST_12 = 0x1000,          /*!< DMA request 12 */
    DMAC_REQUEST_13 = 0x2000,          /*!< DMA request 13 */
    DMAC_REQUEST_14 = 0x4000,          /*!< DMA request 14 */
    DMAC_REQUEST_15 = 0x8000           /*!< DMA request 15 */
} dmac_request_e;


/**
* @brief DMAC burst length
*/
typedef enum tag_dmac_burst_length_e
{
    DMAC_BURST_LENGTH_1   = 0x0,         /*!< DMA burst length 1   */
    DMAC_BURST_LENGTH_4   = 0x1,         /*!< DMA burst length 4   */
    DMAC_BURST_LENGTH_8   = 0x2,         /*!< DMA burst length 8   */
    DMAC_BURST_LENGTH_16  = 0x3,         /*!< DMA burst length 16  */
    DMAC_BURST_LENGTH_32  = 0x4,         /*!< DMA burst length 32  */
    DMAC_BURST_LENGTH_64  = 0x5,         /*!< DMA burst length 64  */
    DMAC_BURST_LENGTH_128 = 0x6,         /*!< DMA burst length 128 */
    DMAC_BURST_LENGTH_256 = 0x7          /*!< DMA burst length 256 */
} dmac_burst_length_e;


/**
* @brief DMAC transfer width
*/
typedef enum tag_dmac_transfer_width_e
{
    DMAC_TRANSFER_BYTE      = 0x0,     /*!< DMA transfer bytewise */
    DMAC_TRANSFER_HALF_WORD = 0x1,     /*!< DMA transfer half word wise */
    DMAC_TRANSFER_WORD      = 0x2      /*!< DMA transfer word wise */
} dmac_transfer_width_e;


/**
* @brief DMAC AHB master select
*/
typedef enum tag_dmac_AHB_master_sel_e
{
    DMAC_SELECT_AHB_MASTER_1 = 0x0,    /*!< DMA AHB master select 1 */
    DMAC_SELECT_AHB_MASTER_2 = 0x1     /*!< DMA AHB master select 2 */
} dmac_AHB_master_sel_e;


/**
* @brief DMAC incrementation
*/
typedef enum tag_dmac_address_inc_e
{
    DMAC_NO_ADDRESS_INCREMENT = 0x0,   /*!< DMA address is not incremented */
    DMAC_ADDRESS_INCREMENT    = 0x1    /*!< DMA address is incremented */
} dmac_address_inc_e;


/**
* @brief DMAC access mode
*/
typedef enum tag_dmac_access_mode_e
{
    DMAC_USER_MODE        = 0x0,       /*!< DMA user mode */
    DMAC_PRIVILEDGED_MODE = 0x1        /*!< DMA priviledged mode */
} dmac_access_mode_e;


/**
* @brief DMAC access is bufferable or not
*/
typedef enum tag_dmac_bufferable_e
{
    DMAC_NON_BUFFERABLE = 0x0,         /*!< DMA non bufferable access */
    DMAC_BUFFERABLE     = 0x2          /*!< DMA bufferable access */
} dmac_bufferable_e;


/**
* @brief DMAC access is cacheable or not
*/
typedef enum tag_dmac_cacheable_e
{
    DMAC_NON_CACHEABLE = 0x0,          /*!< DMA non cacheable access */
    DMAC_CACHEABLE     = 0x4           /*!< DMA cacheable access */
} dmac_cacheable_e;


/**
* @brief DMAC access is bufferable or not
*/
typedef enum tag_dmac_flow_control_e
{
    DMAC_MEMORY_TO_MEMORY_BY_DMA                   = 0x0,    /*!< DMA transfer from memory to memory by DMA conroller */
    DMAC_MEMORY_TO_PERIPHERAL_BY_DMA               = 0x1,    /*!< DMA transfer from memory to peripheral by DMA conroller */
    DMAC_PERIPHERAL_TO_MEMORY_BY_DMA               = 0x2,    /*!< DMA transfer from peripheral to memory by DMA conroller */
    DMAC_SPERIPHERAL_TO_DPERIPHERAL_BY_DMA         = 0x3,    /*!< DMA transfer from source peripheral to destination peripheral by DMA conroller */
    DMAC_SPERIPHERAL_TO_DPERIPHERAL_BY_DPERIPHERAL = 0x4,    /*!< DMA transfer from source peripheral to destination peripheral by destination peripheral */
    DMAC_MEMORY_TO_PERIPHERAL_BY_PERIPHERAL        = 0x5,    /*!< DMA transfer from memory to peripheral by peripheral */
    DMAC_PERIPHERAL_TO_MEMORY_BY_PERIPHERAL        = 0x6,    /*!< DMA transfer from peripheral to memory by peripheral */
    DMAC_SPERIPHERAL_TO_DPERIPHERAL_BY_SPERIPHERAL = 0x7     /*!< DMA transfer from source peripheral to destination peripheral by source peripheral */
} dmac_flow_control_e;


/**
* @brief DMAC stop or continue transmission
*/
typedef enum tag_dmac_halt_e
{
    DMAC_CONTINUE = 0,                 /*!< continue transmission */
    DMAC_HALT     = 1                  /*!< stop transmission */
} dmac_halt_e;


/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/

/**
* @brief DMA link list description structure
*/
typedef struct tag_dmac_linklistitem_st
{
    uint32_t               u32LLIAddress;             /*!< Link list item address */
    dmac_AHB_master_sel_e  eAHBMasterSelect;          /*!< AHB selection for link list loading */
} dmac_linklistitem_st;


/**
* @brief DMA control structure
*/
typedef struct tag_dmac_control_st
{
    dmac_enable_e          eTCInterruptEnable;        /*!< Terminal count interrupt enable bit */
    uint8_t                u8Protection;              /*!< transfer protection */
    dmac_address_inc_e     eDstInc;                   /*!< Destination increment */
    dmac_address_inc_e     eSourceInc;                /*!< Source increment */
    dmac_AHB_master_sel_e  eDstAHBMasterSelect;       /*!< Destination AHB-master selection */
    dmac_AHB_master_sel_e  eSourceAHBMasterSelect;    /*!< Source AHB-master selection */
    dmac_transfer_width_e  eDstTransferWidth;         /*!< Destination transfer width */
    dmac_transfer_width_e  eSourceTransferWidth;      /*!< Source transfer width */
    dmac_burst_length_e    eDstBurstLength;           /*!< Destination burst length */
    dmac_burst_length_e    eSourceBurstLength;        /*!< Source burst length */
    uint16_t               u16TransferSize;           /*!< Size of transfers */
} dmac_control_st;


/**
* @brief DMA configuration structure
*/
typedef struct tag_dmac_config_st
{
    dmac_enable_e        eHalt;                       /*!< Halt a transfer */
    dmac_enable_e        eActive;                     /*!< Channel working or not */
    dmac_enable_e        eLockedTransfer;             /*!< Enable or disable locked transfers */
    dmac_enable_e        eMaskTCInterrupt;            /*!< Terminal count interrupt mask */
    dmac_enable_e        eMaskErrorInterrupt;         /*!< Interrupt error mask */
    dmac_flow_control_e  eFlowControl;                /*!< Flow control and transfer type */
    uint8_t              u8DstPeripheral;             /*!< Specify destination peripheral */
    uint8_t              u8SourcePeripheral;          /*!< Specify source peripheral */
} dmac_config_st;

/*********************************************/


/**********************************************
*            Forward declarations             *
**********************************************/


/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/**
* @brief Implementation of function vDMAC_GetVersion
*
* Retrieve pointers to module and header revision and tag string
*
* @note No Limitations
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
void vDMAC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag);


/**
* @brief Implementation of function u8DMAC_GetInterruptStatusAll
*
* Read status of all interrupts
*
* @note No Limitations
*
* @return Status of all interrupts
*/
uint8_t u8DMAC_GetInterruptStatusAll(void);


/**
* @brief Implementation of function eDMAC_GetInterruptStatus
*
* Read status of single interrupt
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return DMAC_ENABLE if interrupt of channel is set
* @return DMAC_DISABLE if interrupt of channel is not set
*/
dmac_enable_e eDMAC_GetInterruptStatus(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function u8DMAC_GetInterruptTCStatusAll
*
* Read status of all terminal count interrupts
*
* @note No Limitations
*
* @return Status of all interrupts
*/
uint8_t u8DMAC_GetInterruptTCStatusAll(void);


/**
* @brief Implementation of function eDMAC_GetInterruptTCStatus
*
* Read status of single terminal count interrupt
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return DMAC_ENABLE if interrupt of channel is set
* @return DMAC_DISABLE if interrupt of channel is not set
*/
dmac_enable_e eDMAC_GetInterruptTCStatus(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function vDMAC_ClearInterruptTCStatusAll
*
* Clear all terminal count interrupts
*
* @note No Limitations
*
* @return void
*/
void vDMAC_ClearInterruptTCStatusAll(void);


/**
* @brief Implementation of function vDMAC_ClearInterruptTCStatus
*
* Clear single terminal count interrupt
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return void
*/
void vDMAC_ClearInterruptTCStatus(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function u8DMAC_GetInterruptErrorStatusAll
*
* Read error status of all interrupts
*
* @note No Limitations
*
* @return Error status of all interrupts
*/
uint8_t u8DMAC_GetInterruptErrorStatusAll(void);


/**
* @brief Implementation of function eDMAC_GetInterruptErrorStatus
*
* Read error status of single interrupt
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return DMAC_ENABLE if interrupt error of channel is set
* @return DMAC_DISABLE if interrupt error of channel is not set
*/
dmac_enable_e eDMAC_GetInterruptErrorStatus(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function vDMAC_ClearInterruptErrorAll
*
* Clear all interrupt errors
*
* @note No Limitations
*
* @return void
*/
void vDMAC_ClearInterruptErrorAll(void);


/**
* @brief Implementation of function vDMAC_ClearInterruptError
*
* Clear single interrupt error
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return void
*/
void vDMAC_ClearInterruptError(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function u8DMAC_GetRawInterruptTCStatusAll
*
* Read status of all raw terminal count interrupts
*
* @note No Limitations
*
* @return Status of all interrupts
*/
uint8_t u8DMAC_GetRawInterruptTCStatusAll(void);


/**
* @brief Implementation of function eDMAC_GetRawInterruptTCStatus
*
* Read status of single raw terminal count interrupt
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return DMAC_ENABLE if interrupt of channel is set
* @return DMAC_DISABLE if interrupt of channel is not set
*/
dmac_enable_e eDMAC_GetRawInterruptTCStatus(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function u8DMAC_GetRawInterruptErrorStatusAll
*
* Read raw error status of all interrupts
*
* @note No Limitations
*
* @return Error status of all interrupts
*/
uint8_t u8DMAC_GetRawInterruptErrorStatusAll(void);


/**
* @brief Implementation of function eDMAC_GetRawInterruptErrorStatus
*
* Read raw error status of single interrupt
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return DMAC_ENABLE if interrupt error of channel is set
* @return DMAC_DISABLE if interrupt error of channel is not set
*/
dmac_enable_e eDMAC_GetRawInterruptErrorStatus(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function u8DMAC_GetEnabledChannelAll
*
* Read all enabled channels
*
* @note No Limitations
*
* @return Pattern of enabled/disabled channels
*/
uint8_t u8DMAC_GetEnabledChannelAll(void);


/**
* @brief Implementation of function eDMAC_GetEnabledChannel
*
* Check if single channel is enabled
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return DMAC_ENABLE if channel is enabled
* @return DMAC_DISABLE if channel is not enabled
*/
dmac_enable_e eDMAC_GetEnabledChannel(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function vDMAC_EnableSoftwareBurstRequestAll
*
* Enable all software burst requests
*
* @note No Limitations
*
* @param[in] u16Value - requests to be set
*
* @return void
*/
void vDMAC_EnableSoftwareBurstRequestAll(uint16_t u16Value);


/**
* @brief Implementation of function vDMAC_EnableSoftwareBurstRequest
*
* Enable single software burst request
*
* @note No Limitations
*
* @param[in] eDMARequest - request to be set
*
* @return void
*/
void vDMAC_EnableSoftwareBurstRequest(dmac_request_e eDMARequest);


/**
* @brief Implementation of function u16DMAC_GetEnabledSoftwareBurstRequestAll
*
* Read all enabled software burst requests
*
* @note No Limitations
*
* @return Status of all software burst requests
*/
uint16_t u16DMAC_GetEnabledSoftwareBurstRequestAll(void);


/**
* @brief Implementation of function eDMAC_GetEnabledSoftwareBurstRequest
*
* Read single enabled software burst request
*
* @note No Limitations
*
* @param[in] eDMARequest - DMA request number
*
* @return DMAC_ENABLE if software burst is enabled
* @return DMAC_DISABLE if software burst is not enabled
*/
dmac_enable_e eDMAC_GetEnabledSoftwareBurstRequest(dmac_request_e eDMARequest);


/**
* @brief Implementation of function vDMAC_EnableSoftwareSingleRequestAll
*
* Enable all software single requests
*
* @note No Limitations
*
* @param[in] u16Value - requests to be set
*
* @return void
*/
void vDMAC_EnableSoftwareSingleRequestAll(uint16_t u16Value);


/**
* @brief Implementation of function vDMAC_EnableSoftwareBurstRequest
*
* Enable single software single request
*
* @note No Limitations
*
* @param[in] eDMARequest - request to be set
*
* @return void
*/
void vDMAC_EnableSoftwareSingleRequest(dmac_request_e eDMARequest);


/**
* @brief Implementation of function u16DMAC_GetEnabledSoftwareSingleRequestAll
*
* Read single enabled software single requests
*
* @note No Limitations
*
* @return status of all software single requests
*/
uint16_t u16DMAC_GetEnabledSoftwareSingleRequestAll(void);


/**
* @brief Implementation of function eDMAC_GetEnabledSoftwareSingleRequest
*
* Read single enabled software single request
*
* @note No Limitations
*
* @param[in] eDMARequest - DMA request number
*
* @return DMAC_ENABLE if software single is enabled
* @return DMAC_DISABLE if software single is not enabled
*/
dmac_enable_e eDMAC_GetEnabledSoftwareSingleRequest(dmac_request_e eDMARequest);


/**
* @brief Implementation of function vDMAC_EnableSoftwareLastBurstRequestAll
*
* Enable all software burst requests
*
* @note No Limitations
*
* @param[in] u16Value - requests to be set
*
* @return void
*/
void vDMAC_EnableSoftwareLastBurstRequestAll(uint16_t u16Value);


/**
* @brief Implementation of function vDMAC_EnableSoftwareLastBurstRequest
*
* Enable single software burst request
*
* @note No Limitations
*
* @param[in] eDMARequest - request to be set
*
* @return void
*/
void vDMAC_EnableSoftwareLastBurstRequest(dmac_request_e eDMARequest);


/**
* @brief Implementation of function u16DMAC_GetEnabledSoftwareLastBurstRequestAll
*
* Read all enabled software burst requests
*
* @note No Limitations
*
* @return status of all software burst requests
*/
uint16_t u16DMAC_GetEnabledSoftwareLastBurstRequestAll(void);


/**
* @brief Implementation of function eDMAC_GetEnabledSoftwareLastBurstRequest
*
* Read single enabled software burst request
*
* @note No Limitations
*
* @param[in] eDMARequest - DMA request number
*
* @return DMAC_ENABLE if software last burst is enabled
* @return DMAC_DISABLE if software last burst is not enabled
*/
dmac_enable_e eDMAC_GetEnabledSoftwareLastBurstRequest(dmac_request_e eDMARequest);


/**
* @brief Implementation of function vDMAC_EnableSoftwareLastSingleRequestAll
*
* Enable all software single requests
*
* @note No Limitations
*
* @param[in] u16Value - requests to be set
*
* @return void
*/
void vDMAC_EnableSoftwareLastSingleRequestAll(uint16_t u16Value);


/**
* @brief Implementation of function vDMAC_EnableSoftwareLastSingleRequest
*
* Enable single software single request
*
* @note No Limitations
*
* @param[in] eDMARequest - request to be set
*
* @return void
*/
void vDMAC_EnableSoftwareLastSingleRequest(dmac_request_e eDMARequest);


/**
* @brief Implementation of function u16DMAC_GetEnabledSoftwareLastSingleRequestAll
*
* Read single enabled software single requests
*
* @note No Limitations
*
* @return status of all software single requests
*/
uint16_t u16DMAC_GetEnabledSoftwareLastSingleRequestAll(void);


/**
* @brief Implementation of function eDMAC_GetEnabledSoftwareLastSingleRequest
*
* Read single enabled software single request
*
* @note No Limitations
*
* @param[in] eDMARequest - DMA request number
*
* @return DMAC_ENABLE if software last single request is enabled
* @return DMAC_DISABLE if software last single request is not enabled
*/
dmac_enable_e eDMAC_GetEnabledSoftwareLastSingleRequest(dmac_request_e eDMARequest);


/**
* @brief Implementation of function vDMAC_Enable
*
* Enable or disable the DMA-controller
*
* @note No Limitations
*
* @param[in] eEnable - DMAC_ENABLE/DMAC_DISABLE
*
* @return void
*/
void vDMAC_Enable(dmac_enable_e eEnable);

/**
* @brief Implementation of function eDMAC_GetEnabled
*
* get the actual status of the DMA-controller
*
* @note No Limitations
*
* @param[in] void
*
* @return eEnable - DMAC_ENABLE/DMAC_DISABLE
*/
dmac_enable_e eDMAC_GetEnabled( void );


/**
* @brief Implementation of function vDMAC_EnableSynchronisationAll
*
* Enable synchronisation logic for all request signals
*
* @note No Limitations
*
* @param[in] u16Value - requests to be set
*
* @return void
*/
void vDMAC_EnableSynchronisationAll(uint16_t u16Value);


/**
* @brief Implementation of function vDMAC_EnableSynchronisation
*
* Enable synchronisation logic for single request signal
*
* @note No Limitations
*
* @param[in] eDMARequest - request to be set
*
* @return void
*/
void vDMAC_EnableSynchronisation(dmac_request_e eDMARequest);


/**
* @brief Implementation of function u16DMAC_GetSynchronisationAll
*
* Read synchronisation logic enable status for all request signals
*
* @note No Limitations
*
* @return status of all software single requests
*/
uint16_t u16DMAC_GetSynchronisationAll(void);


/**
* @brief Implementation of function eDMAC_GetSynchronisation
*
* Read synchronisation logic enable status for single request signals
*
* @note No Limitations
*
* @param[in] eDMARequest - DMA request number
*
* @return DMAC_ENABLE if synchronisation logic is enabled
* @return DMAC_DISABLE if synchrinisation logic is not enabled
*/
dmac_enable_e eDMAC_GetSynchronisation(dmac_request_e eDMARequest);


/**
* @brief Implementation of function vDMAC_SetSourceAddress
*
* Set source address
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
* @param[in] u32Address  - source address
*
* @return void
*/
void vDMAC_SetSourceAddress(dmac_channel_e eDMAChannel, uint32_t u32Address);


/**
* @brief Implementation of function u32DMAC_GetSourceAddress
*
* Read source address
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return source address
*/
uint32_t u32DMAC_GetSourceAddress(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function vDMAC_SetDestinationAddress
*
* Set destination address
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
* @param[in] u32Address  - destination address
*
* @return void
*/
void vDMAC_SetDestinationAddress(dmac_channel_e eDMAChannel, uint32_t u32Address);


/**
* @brief Implementation of function u32DMAC_GetDestinationAddress
*
* Read destination address
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return Destination address
*/
uint32_t u32DMAC_GetDestinationAddress(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function vDMAC_SetLinkListItem
*
* Set DMA link list configuration
*
* @note No Limitations
*
* @param[in] eDMAChannel    - DMA channel
* @param[in] stLinkListItem - Pointer to link list configuration
*
* @return void
*/
void vDMAC_SetLinkListItem(dmac_channel_e eDMAChannel, dmac_linklistitem_st * stLinkListItem);


/**
* @brief Implementation of function vDMAC_GetLinkListItem
*
* Get DMA link list configuration
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @param[in,out] stLinkListItem - Pointer to link list configuration
*
* @return void
*/
void vDMAC_GetLinkListItem(dmac_channel_e eDMAChannel, dmac_linklistitem_st * stLinkListItem);


/**
* @brief Implementation of function vDMAC_SetControl
*
* Set DMA control configuration
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
* @param[in] stControl   - Pointer to DMA channel control configuration
*
* @return void
*/
void vDMAC_SetControl(dmac_channel_e eDMAChannel, dmac_control_st * stControl);


/**
* @brief Implementation of function vDMAC_SetTransferSize
*
* Set dma transfer size for specific channel
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
* @param[in] u16TransferSize - transfer size
*
* @return void
*/
void vDMAC_SetTransferSize(dmac_channel_e eDMAChannel, uint16_t u16TransferSize);


/**
* @brief Implementation of function u32DMAC_GenerateControlValue
*
* Combine DMA control configuration to one 32-Bit value
*
* @note No Limitations
*
* @param[in] stControl - Pointer to DMA channel control configuration
*
* @return DMAC-control register value
*/
uint32_t u32DMAC_GenerateControlValue(dmac_control_st * stControl);


/**
* @brief Implementation of function vDMAC_GetControl
*
* Get DMA control configuration
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @param[in,out] stControl - Pointer to DMA channel control configuration
*
* @return C_TRUE or C_FALSE (if channel is not disbaled, information cannot be valid)
*/
bool_t boDMAC_GetControl(dmac_channel_e eDMAChannel, dmac_control_st * stControl);


/**
* @brief Implementation of function vDMAC_SetConfiguration
*
* Set DMA configuration
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
* @param[in] stConfiguration - Pointer to DMA channel configuration
*
* @return void
*/
void vDMAC_SetConfiguration(dmac_channel_e eDMAChannel, dmac_config_st * stConfiguration);


/**
* @brief Implementation of function u32DMAC_GenerateConfigurationValue
*
* Combine DMA configuration to one 32-Bit value
*
* @note No Limitations
*
* @param[in] stConfiguration - Pointer to DMA channel configuration
*
* @return DMAC-configuration register value
*/
uint32_t u32DMAC_GenerateConfigurationValue(dmac_config_st * stConfiguration);


/**
* @brief Implementation of function vDMAC_GetConfiguration
*
* Get DMA configuration
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @param[in,out] stConfiguration - Pointer to DMA channel configuration
*
* @return void
*/
void vDMAC_GetConfiguration(dmac_channel_e eDMAChannel, dmac_config_st * stConfiguration);


/**
* @brief Implementation of function vDMAC_HoldChannel
*
* Hold or continuer a DMA channel
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
* @param[in] eHalt       - Stop or continue transmission
*
* @return void
*/
void vDMAC_HoldChannel(dmac_channel_e eDMAChannel, dmac_halt_e eHalt);


/**
* @brief Implementation of function vDMAC_StartTransfer
*
* Start transfer
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return void
*/
void vDMAC_StartTransfer(dmac_channel_e eDMAChannel);


/**
* @brief Implementation of function vDMAC_StopTransfer
*
* Stop transfer, any data in the fifo is lost
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return void
*/
void vDMAC_StopTransfer(dmac_channel_e eDMAChannel);

/**
* @brief Implementation of function eDMACTransferStarted
*
* Check if DMA transfer waas started
*
* @note No Limitations
*
* @param[in] eDMAChannel - DMA channel
*
* @return DMAC_ENABLE if transfer is started
* @return DMAC_DISABLE if transfer is not satarted
*/
dmac_enable_e eDMACTransferStarted(dmac_channel_e eDMAChannel);


/****************************************************************************/


#endif /* DMAC_H*/

/****************************************************************************/


/***********************  BEGIN of DISCLAIMER  *****************************

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

****************************  END of DISCLAIMER****************************/

