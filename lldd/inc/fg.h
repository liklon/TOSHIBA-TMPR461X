/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : FG Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : FG
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.11 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef FG_H
#define FG_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/


/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_FG_H_REVISION     "$Revision: 1.11 $"
#define LLDD_FG_H_TAG          "$Name: LLDD_1_7_GFX $"

/*********************************************/


/**********************************************
*               Enumerations                  *
**********************************************/

/**
* @brief Frame Grabber Colors
*/
typedef enum tag_fg_color_e
{
    FG_RED   = 0,    /*!< color red   */
    FG_GREEN = 1,    /*!< color green */    
    FG_BLUE  = 2     /*!< color blue  */    
} fg_color_e;


/**
* @brief Enable/disable Frame Grabber. Cropping, Color Correction
*/
typedef enum tag_fg_en_e
{
    FG_DISABLE = 0x0U,    /*!< disable */
    FG_ENABLE  = 0x1U     /*!< enable */
} fg_en_e;


/**
* @brief Interrupt detected
*/
typedef enum tag_fg_ir_detected_e
{
    FG_IR_NOT_DETECTED = 0x0U,    /*!< no interrupt detected */
    FG_IR_DETECTED     = 0x1U     /*!< interrupt detected    */
} fg_ir_detected_e;


/**
* @brief Interrupt clear
*/
typedef enum tag_fg_ir_clear_e
{
    FG_IR_NO_CLEAR = 0x0U,    /*!< interrupt no change */
    FG_IR_CLEAR    = 0x1U     /*!< interrupt clear     */
} fg_ir_clear_e;


/**
* @brief RGB parallel input mode
*/
typedef enum tag_fg_rgbpa_e
{
    FG_TWO8BIT_INPUT = 0x0U,    /*!< two 8-bit input channels are used (normal RGB or YCbCr mode) */
    FG_RGB_PARALLEL  = 0x1U     /*!< select RGB parallel input mode */
} fg_rgbpa_e;


/**
* @brief RGB parallel input select
*/
typedef enum tag_fg_rgb24_e
{
    FG_RGB565 = 0x0U,    /*!< 16-bit parallel input is decoded 5:6:5 */
    FG_RGB888 = 0x1U     /*!< 24-bit parallel input is decoded 8:8:8 */
} fg_rgb24_e;


/**
* @brief Non-video data input mode
*/
typedef enum tag_fg_nvmd_e
{
    FG_VIDEO_DATA     = 0x0U,    /*!< video data input */
    FG_NON_VIDEO_DATA = 0x1U     /*!< non-video data is selected as input; data is not interpreted as
                                      video data. (UDSP and USYNC need to be set to 1) */
} fg_nvmd_e;


/**
* @brief De-interlace output image: Only valid if INT = 1
*/
typedef enum tag_fg_deinterlace_e
{
    FG_DINT_NO_DEINTERLACED = 0x0U,    /*!< no de-interlacing , therefore interlaced output in each Capture Buffer */
    FG_DINT_INTERLACED      = 0x1U     /*!< output is de-interlaced (interpreted only if INT = 1)*/
} fg_deinterlace_e;


/**
* @brief Input image interlaced
*/
typedef enum tag_fg_interlace_e
{
    FG_INT_NORMAL_OPERATION = 0x0U,    /*!< normal operation */
    FG_INT_INTERLACED       = 0x1U     /*!< input data is interlaced */
} fg_interlace_e;


/**
* @brief YCbCr output selector
*/
typedef enum tag_fg_ycbro_e
{
    FG_YCBRO_RGB      = 0x0U,    /*!< RGBA or reduced RGB output */
    FG_YCBRO_YCBCR422 = 0x1U     /*!< YCbCr 4:2:2 output, Only used, if COMD = 1. */
} fg_ycbro_e;


/**
* @brief Reduced RGB mode - Not used, if COMD=1 and YCBRO=1
*/
typedef enum tag_fg_rrgb_e
{
    FG_RRGB_RGBA32 = 0x0U,    /*!< 32-bit RGBA output (data format RGBA32) */
    FG_RRGB_RGB16  = 0x1U     /*!< 16-bit reduced RGB output (data format RGB16) */
} fg_rrgb_e;


/**
* @brief Use input as alpha value - Only used in monochrome mode
*/
typedef enum tag_fg_bwex_e
{
    FG_BWEX_INTERPRET_CAMERAINPUT = 0x0U,    /*!< output is generated by normal interpretation of the camera input */
    FG_BWEX_INTERPRET_COLOR_CIR   = 0x1U     /*!< output is generated using the colour specified in the CIR register and the input signal as alpha value.*/
} fg_bwex_e;


/**
* @brief Monochrome output mode
*/
typedef enum tag_fg_mono_e
{
    FG_MONO_COLOUR     = 0x0U,     /*!< color mode */
    FG_MONO_MONOCHROME = 0x1U      /*!< monochrome mode */
} fg_mono_e;


/**
* @brief YCbCr input to RGB conversion method
*/
typedef enum tag_fg_cvmd_e
{
    FG_YCBCR2RGB_ITU601 = 0x0U,    /*!< converted using ITU R 601 */
    FG_YCBCR2RGB_ITU709 = 0x1U     /*!< converted using ITU R 709 */
} fg_cvmd_e;


/**
* @brief Color mode
*/
typedef enum tag_fg_comd_e
{
    FG_INP_COLORMODE_RGB   = 0x0U,    /*!< RGB input mode */
    FG_INP_COLORMODE_YCBCR = 0x1U     /*!< YCbCr input mode */
}   fg_comd_e;


/**
* @brief Swap appearance of chrominance (Cb/Cr) values
*/
typedef enum tag_fg_scbcr_e
{
    FG_SCBCR_CB_CR = 0x0U,    /*!< first pixel is Cb, then Cr */
    FG_SCBCR_CR_CB = 0x1U     /*!< first pixel is Cr, then Cb */
} fg_scbcr_e;


/**
* @brief Swap appearance of Y and Cb/Cr
*/
typedef enum tag_fg_sycbcr_e
{
    FG_SYCBCR_Y2Y_CBCR2CBCR_CHANNEL = 0x0U,    /*!< Y is transmitted over Y channel, Cb/Cr over CBCR channel */
    FG_SYCBCR_Y2CBCR_CBCR2Y_CHANNEL = 0x1U     /*!< Y is transmitted over CBCR channel, Cb/Cr over Y channel */
} fg_sycbcr_e;


/**
* @brief VSYNC and HSYNC signal usage
*/
typedef enum tag_fg_usync_e
{
    FG_USYNC_HVSYNC_IGNORED = 0x0U,    /*!< HSYNC and VSYNC input is ignored, the field and line
                                            blanking interval is stored in the data stream (ITU-R 656) */
    FG_USYNC_HVSYNC_USED    = 0x1U     /*!< VSYNC and HSYNC input is used to select the field and line
                                            blanking interval */
} fg_usync_e;


/**
* @brief HDISP input usage
*/
typedef enum tag_fg_udsp_e
{
    FG_UDSP_HDISP_IGNORED = 0x0U,    /*!< HDISP input signal is ignored; FGIDR and FGITR have to be set! */
    FG_UDSP_HDISP_USED    = 0x1U     /*!< HDISP input signal is used for data capturing */
} fg_udsp_e;


/**
* @brief Defines the active level of the camera�s HDISP signal
*/
typedef enum tag_fg_active_level_e
{
    FG_LOW_ACTIVE  = 0x0U,    /*!< low active */
    FG_HIGH_ACTIVE = 0x1U     /*!< high active */
} fg_active_level_e;


/**
* @brief Defines the active level of the camera�s HSYNC signal
*/
typedef enum tag_fg_hsact_e
{
    FG_HSACT_HSYNC_LOW_ACTIVE  = 0x0U,    /*!< HSYNC low active  */
    FG_HSACT_HSYNC_HIGH_ACTIVE = 0x1U     /*!< HSYNC high active */
} fg_hsact_e;


/**
* @brief One input channel
*/
typedef enum tag_fg_onec_e
{
    FG_ONEC_DATA_OVER_BOTH_INPCHANNELS = 0x0U,    /*!< both input channels contain data (normal operation) */
    FG_ONEC_DATA_OVER_Y_INPCHANNEL     = 0x1U     /*!< only luminance (Y) input contains the data => 8-bit data 
                                                       (also valid for non-video data) */
} fg_onec_e;


/**
* @brief Pixel clock active edge
*/
typedef enum tag_fg_negpc_e
{
    FG_NEGPC_POS_EDGE = 0x0U,    /*!< pixel valid on positive edge of Pixel clock */
    FG_NEGPC_NEG_EDGE = 0x1U     /*!< pixel valid on negative edge of pixel clock */
} fg_negpc_e;


/**
* @brief Negate Odd field signal
*/
typedef enum tag_fg_nfodd_e
{
    FG_NFODD_LOWSIGNAL_FIRST  = 0x0U,    /*!< low level signals first line */
    FG_NFODD_HIGHSIGNAL_FIRST = 0x1U     /*!< high level signals first line */
} fg_nfodd_e;


/**
* @brief Indicates the current capture buffer
*/
typedef enum tag_fg_cbcur_e
{
    FG_CBCUR_BUFFER_1_CURR_USED = 0x1U,    /*!< buffer 1 is currently used */
    FG_CBCUR_BUFFER_2_CURR_USED = 0x2U,    /*!< buffer 2 is currently used */
    FG_CBCUR_BUFFER_3_CURR_USED = 0x3U     /*!< buffer 3 is currently used */
} fg_cbcur_e;


/**
* @brief Selects the number of active capture buffers
*/
typedef enum tag_fg_cbact_e                
{                                          
    FG_CBACT_INVALID           = 0x0U,    /*!< invalid setting   */
    FG_CBACT_USE_ONE_BUFFER    = 0x1U,    /*!< use one buffer    */
    FG_CBACT_USE_TWO_BUFFERS   = 0x2U,    /*!< use two buffers   */
    FG_CBACT_USE_THREE_BUFFERS = 0x3U     /*!< use three buffers */
} fg_cbact_e;


/**
* @brief Can be used for Non-Video mode interrupt, Measurement ready interrupt, Vertical SYNC interrupt,
         Video-Bus Timeout interrupt, Corrupted data interrupt
*/
typedef enum tag_fg_fgimr_enable_e
{
    FG_IMR_SOURCE_NONE    = 0x0U,    /*!< not source for interrupt */
    FG_IMR_SOURCE_ENABLED = 0x1U     /*!< interrupt source enabled    */
} fg_fgimr_enable_e;


/**
* @brief Can be used for Non-video mode status, Measurement ready status, Vertical SYNC status,
         Video-Bus Timeout status, Corrupted data status
*/
typedef enum tag_fg_fgisr_detection_e
{
    FG_INTR_NOT_DETECTED = 0x0U,    /*!< no interrupt detected */
    FG_INTR_DETECTED     = 0x1U     /*!< interrupt detected    */
} fg_fgisr_detection_e;


/**
* @brief No. of used buffers for frame grabber
*/
typedef enum tag_fg_used_buffer_e
{
    FG_INVALID_SETTING  = 0x0U,    /*!< one buffer used */
    FG_SINGEL_BUFFERING = 0x1U,    /*!< one buffer used */
    FG_DOUBLE_BUFFERING = 0x2U,    /*!< double buffering used */
    FG_TRIPEL_BUFFERING = 0x3U     /*!< tripple buffering used */
} fg_used_buffer_e;

/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/

/**
* @brief Signal configuration
*/
typedef struct tag_fg_signals_st
{
  fg_nfodd_e        eNfOdd;    /*!< negate odd field signal */
  fg_negpc_e        eNegPc;    /*!< pixel clock active edge */
  fg_onec_e         eOnec;     /*!< one input channel */
  fg_active_level_e eHsact;    /*!< defines the active level of the camera�s HSYNC signal */
  fg_active_level_e eVsact;    /*!< defines the active level of the camera�s VSYNC signal */
  fg_active_level_e eHdact;    /*!< defines the active level of the camera�s HDISP signal */
  fg_udsp_e         eUdsp;     /*!< HDISP input usage */
  fg_usync_e        eUsync;    /*!< VSYNC and HSYNC signal usage */
} fg_signals_st;


/**
* @brief Color swap configuration
*/
typedef struct tag_fg_swap_ycbcr_st
{
  fg_scbcr_e  eScbCr;     /*!< swap appearance of chrominance (Cb/Cr) values */
  fg_sycbcr_e eSycbcr;    /*!< swap appearance of Y and Cb/Cr */
} fg_swap_ycbcr_st;


/**
* @brief Input format structure
*/
typedef struct tag_fg_input_format_st
{
  uint8_t           u8Alpha;        /*!< common alpha value used for all incoming dots */
  fg_rgbpa_e        eRgbPa;         /*!< RGB parallel input mode   */
  fg_rgb24_e        eRgb16_24;      /*!< RGB parallel input mode   */
  fg_nvmd_e         eNvmd;          /*!< non-video data input mode */
  fg_interlace_e    eInterlMode;    /*!< input image interlaced    */
  fg_bwex_e         eBwex;          /*!< use input as alpha value  */
  fg_comd_e         eComd;          /*!< color mode */
  fg_swap_ycbcr_st  stSwapYcbCr;    /*!< swap appearance of Y, Cb, Cr values */  
} fg_input_format_st;


/**
* @brief Output format structure
*/
typedef struct tag_fg_output_format_st
{
  fg_deinterlace_e  eDeInterl;          /*!< interlace type */
  fg_ycbro_e        eOutputSelector;    /*!< YCbCr output selector */
  fg_rrgb_e         eRgbFormat;         /*!< RGB color output */
  fg_mono_e         eMonochrome;        /*!< monochrome output mode */
  fg_cvmd_e         eYcbcr2RgbConv;     /*!< YCbCr input to RGB conversion method */
} fg_output_format_st;


/**
* @brief Input size structure
*/
typedef struct tag_fg_input_cropp_st
{
  uint16_t u16ItrHorizWait;      /*!< horizontal wait */
  uint16_t u16ItrVertWait;       /*!< vertical wait */
  
  uint16_t u16HcrCroppLeftX;     /*!< horizontal cropp window start position */
  uint16_t u16HcrCroppWidth;     /*!< cropp window width */

  uint16_t u16VcrCroppTopY;      /*!< vertical cropp window start position */
  uint16_t u16VcrCroppHeight;    /*!< cropp window height */
} fg_input_cropp_st;


/**
* @brief Frame buffer configuration structure
*/
typedef struct tag_fg_capture_buffer_st
{
  fg_used_buffer_e  eCbactUsedBuffer;     /*!< no. of used buffers for frame grabber */
  uint16_t          u16LorLineOffset;     /*!< LOR line offset */
  uint32_t          u32CbaBufferAddr1;    /*!< buffer address 1 */
  uint32_t          u32CbaBufferAddr2;    /*!< buffer address 2 */
  uint32_t          u32CbaBufferAddr3;    /*!< buffer address 3 */
} fg_capture_buffer_st;


/**
* @brief Color informaton
*/
typedef struct tag_fg_color_exchange_st
{
  uint8_t u8Red;      /*!< red color value */
  uint8_t u8Green;    /*!< green color value */
  uint8_t u8Blue;     /*!< blue color value */
} fg_color_exchange_st;


/**
* @brief Measurement properties of the external synchronization signals
*/
typedef struct tag_fg_measure_extsync_result_st
{
  uint16_t  u16Mhcr;     /*!< measured value of the HCR value of the camera input */
  uint16_t  u16Mhspwr;   /*!< measured value of the HSPWR value of the camera input */
  uint16_t  u16Mvcr;     /*!< measured value of the VCR value of the camera input */
  uint16_t  u16Mvspwr;   /*!< measured value of the VSPWR value of the camera input */
  uint16_t  u16Mhdisp;   /*!< measured value of the HDISP value of the camera input */
} fg_measurement_extsync_result_st;


/**
* @brief Measurement control of the external synchronization signals
*/
typedef struct tag_fg_measurement_extync_control_st
{
  fg_en_e  eVcr;      /*!< enable or disable VCR measurement */
  fg_en_e  eHcr;      /*!< enable or disable HSPWR measurement */
  fg_en_e  eVspwr;    /*!< enable or disable VSPWR measurement */
  fg_en_e  eHspwr;    /*!< enable or disable HSPWR measurement */
  fg_en_e  eHdisp;    /*!< enable or disable HDISP measurement */
} fg_measure_extsync_control_st;


/**
* @brief Selects the interrupt mask for the generation of the Frame Grabber interrupt
*/
typedef struct tag_fg_irqcgf_st
{
  fg_en_e  eCdi;      /*!< enable or disable CFI */
  fg_en_e  eVbtoi;    /*!< enable or disable VBTOI */
  fg_en_e  eVsi;      /*!< enable or disable VSI */
  fg_en_e  eMrdyi;    /*!< enable or disable MRDYI */
  fg_en_e  eNvi;      /*!< enable or disable NVI */
} fg_irqcgf_st;


/**
* @brief Clear interrupts
*/
typedef struct tag_fg_irqclear_st
{
  fg_ir_clear_e  eCds;      /*!< clear CDS */
  fg_ir_clear_e  eVbtos;    /*!< clear VBTOS */
  fg_ir_clear_e  eVss;      /*!< clear VSS */
  fg_ir_clear_e  eMrdys;    /*!< clear MRDYS */
  fg_ir_clear_e  eNvs;      /*!< clear NVS */
} fg_irqclear_st;

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/**
* @brief Implementation of function vFG_GetVersion
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
void vFG_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                    uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                    uint8_t** pau8IORevision, uint8_t** pau8IOTag);


/**
* @brief Implementation of function vFG_FrameGrabberEnable
*
* Enable/Disable Frame grabber
*
* @note No Limitations
*
* @param[in] eEn - enable or disable the FG
*
* @return void
*/
void vFG_FrameGrabberEnable(fg_en_e eEn);


/**
* @brief Implementation of function vFG_CroppingEnable
*
* Enable/Disable Cropping function
*
* @note No Limitations
*
* @param[in] eEn - enable or disable cropping
*
* @return void
*/
void vFG_CroppingEnable(fg_en_e eEn);


/**
* @brief Implementation of function vFG_ColorCorrectEnable
*
* Enable/Disable color correction
*
* @note No Limitations
*
* @param[in] eEn - enable or disable color correction
*
* @return void
*/
void vFG_ColorCorrectEnable(fg_en_e eEn);


/**
* @brief Implementation of function vFG_ConfigureFgSignal
*
* Configure FG-Signal properties
*
* @note No Limitations
*
* @param[in,out] pstSignal - pointer to FG-signal settings
*
* @return void
*/
void vFG_ConfigureFgSignal(fg_signals_st * pstSignal);


/**
* @brief Implementation of function vFG_SetInputMode
*
* Set properties of FG-input source
*
* @note No Limitations
*
* @param[in,out] pstMode - pointer to structure of input settings
*
* @return void
*/
void vFG_SetInputMode(fg_input_format_st * pstMode);


/**
* @brief Implementation of function vFG_SetOutputMode
*
* Set properties of FG-output
*
* @note No Limitations
*
* @param[in,out] pstMode - pointer to structure of output settings
*
* @return void
*/
void vFG_SetOutputMode(fg_output_format_st * pstMode);


/**
* @brief Implementation of function vFG_SetInputImageSize
*
* set width and height of FG-input image
*
* @note No Limitations
*
* @param[in] u16Width  - width of input image
* @param[in] u16Height - height of input image 
*
* @return void
*/
void vFG_SetInputImageSize(uint16_t u16Width,  uint16_t u16Height);


/**
* @brief Implementation of function vFG_SetInputCropp
*
* Set properties of cropping
*
* @note No Limitations
*
* @param[in,out] pstCroppConfig - pointer to cropping properties
*
* @return void
*/
void vFG_SetInputCropp(fg_input_cropp_st * pstCroppConfig);


/**
* @brief Implementation of function vFG_SetCaptureBuffers
*
* Set no. and properties of GH-Capture buffers
*
* @note No Limitations
*
* @param[in,out] pstCaptureBuffer - pointer to capture settings
*
* @return void
*/
void vFG_SetCaptureBuffers(fg_capture_buffer_st * pstCaptureBuffer);


/**
* @brief Implementation of function eFG_GetCurrentCaptureBuffer
*
* Get number of current capture buffer
*
* @note No Limitations
*
* @return FG_CBCUR_BUFFER_1_CURR_USED - buffer 1 is currently used
* @return FG_CBCUR_BUFFER_2_CURR_USED - buffer 2 is currently used
* @return FG_CBCUR_BUFFER_3_CURR_USED - buffer 3 is currently used
*/
fg_cbcur_e eFG_GetCurrentCaptureBuffer(void);


/**
* @brief Implementation of function vFG_ConfigureMemoryWriteProtection
*
* Set lower and upper addresses for memory write protection
*
* @note No Limitations
*
* @param[in] u32StartAddress - start memory address
* @param[in] u32EndAddress   - end memory address
*
* @return void
*/
void vFG_ConfigureMemoryWriteProtection(uint32_t u32StartAddress, uint32_t u32EndAddress);


/**
* @brief Implementation of function vFG_SetScalingFactors
*
* Set properties of scaling
*
* @note No Limitations
*
* @param[in] u16ScaleX - Hoiz. scaling factor
* @param[in] u16ScaleY - Vert. scaling factor 
*
* @return void
*/
void vFG_SetScalingFactors(uint16_t u16ScaleX, uint16_t u16ScaleY);


/**
* @brief Implementation of function vFG_EnableMeasurements
*
* Enable several ext. sync measurements together
*
* @note No Limitations
*
* @param[in,out] pstMeasurement - pointer to propoerties of measurements
*
* @return void
*/
void vFG_EnableMeasurements(fg_measure_extsync_control_st * pstMeasurement);


/**
* @brief Implementation of function vFG_EnableMeasurementVCR
*
* Enable ext. sync measurement VCR
*
* @note No Limitations
*
* @param[in] eEn - enable or disable ext. sync measurement
*
* @return void
*/
void vFG_EnableMeasurementVCR(fg_en_e eEn);


/**
* @brief Implementation of function vFG_EnableMeasurementHCR
*
* Enable ext. sync measurement HCR
*
* @note No Limitations
*
* @param[in] eEn - enable or disable ext. sync measurement
*
* @return void
*/
void vFG_EnableMeasurementHCR(fg_en_e eEn);


/**
* @brief Implementation of function vFG_EnableMeasurementHDISP
*
* Enable ext. sync measurement HDISP
*
* @note No Limitations
*
* @param[in] eEn - enable or disable ext. sync measurement
*
* @return void
*/
void vFG_EnableMeasurementHDISP(fg_en_e eEn);


/**
* @brief Implementation of function vFG_EnableMeasurementHSPWR
*
* Enable ext. sync measurement HSPWR
*
* @note No Limitations
*
* @param[in] eEn - enable or disable ext. sync measurement
*
* @return void
*/
void vFG_EnableMeasurementHSPWR(fg_en_e eEn);


/**
* @brief Implementation of function vFG_EnableMeasurementVSPWR
*
* Enable ext. sync measurement VSPWR
*
* @note No Limitations
*
* @param[in] eEn - enable or disable ext. sync measurement
*
* @return void
*/
void vFG_EnableMeasurementVSPWR(fg_en_e eEn);


/**
* @brief Implementation of function vFG_GetMeasurements
*
* Get results of several ext. sync measurements
*
* @note No Limitations
*
* @param[in,out] pstMeasurement - pointer to structure for measurements
*
* @return void
*/
void vFG_GetMeasurements(fg_measurement_extsync_result_st * pstMeasurement);


/**
* @brief Implementation of function vFG_GetMeasurementMVCR
*
* Get result ext. sync measurement MVCR
*
* @note No Limitations
*
* @return Result of measurement
*/
uint16_t vFG_GetMeasurementMVCR(void);


/**
* @brief Implementation of function vFG_GetMeasurementMHCR
*
* Get result ext. sync measurement MHCR
*
* @note No Limitations
*
* @return Result of measurement
*/
uint16_t vFG_GetMeasurementMHCR(void);


/**
* @brief Implementation of function vFG_GetMeasurementMHSPWR
*
* Get result ext. sync measurement MHSPWR
*
* @note No Limitations
*
* @return Result of measurement
*/
uint16_t vFG_GetMeasurementMHSPWR(void);


/**
* @brief Implementation of function vFG_GetMeasurementMVSPWR
*
* Get result ext. sync measurement MVSPWR
*
* @note No Limitations
*
* @return Result of measurement
*/
uint16_t vFG_GetMeasurementMVSPWR(void);


/**
* @brief Implementation of function vFG_GetMeasurementMHDISP
*
* Get result ext. sync measurement MHDISP
*
* @note No Limitations
*
* @return Result of measurement
*/
uint16_t vFG_GetMeasurementMHDISP(void);


/**
* @brief Implementation of function vFG_EnableIrq
*
* Mask generation of several FG-interrupts
*
* @note No Limitations
*
* @param[in,out] pstCfg - pointer to IRQ-settings
*
* @return void
*/
void vFG_EnableIrq(fg_irqcgf_st * pstCfg);


/**
* @brief Implementation of function vFG_EnableIrqCDI
*
* Mask generation of Fg interrupt CDI
*
* @note No Limitations
*
* @param[in] eEn - enable or disableirq CDI
*
* @return void
*/
void vFG_EnableIrqCDI(fg_en_e eEn);


/**
* @brief Implementation of function vFG_EnableIrqVBTOI
*
* Mask generation of Fg interrupt VBTOI
*
* @note No Limitations
*
* @param[in] eEn - enable or disable irq VBTOI
*
* @return void
*/
void vFG_EnableIrqVBTOI(fg_en_e eEn);


/**
* @brief Implementation of function vFG_EnableIrqVSI
*
* Mask generation of Fg interrupt VSI
*
* @note No Limitations
*
* @param[in] eEn - enable or disable irq VSI
*
* @return void
*/
void vFG_EnableIrqVSI(fg_en_e eEn);


/**
* @brief Implementation of function vFG_EnableIrqMRDYI
*
* Mask generation of Fg interrupt MRDYI
*
* @note No Limitations
*
* @param[in] eEn - enable or disable irq MRDYI
*
* @return void
*/
void vFG_EnableIrqMRDYI(fg_en_e eEn);


/**
* @brief Implementation of function vFG_EnableIrqNVI
*
* Mask generation of Fg interrupt NVI
*
* @note No Limitations
*
* @param[in] eEn - enable or disable irq NVI
*
* @return void
*/
void vFG_EnableIrqNVI(fg_en_e eEn);


/**
* @brief Implementation of function vFG_GetIrqCDS
*
* Allows the MPU to check the source of  interrupt CDS
*
* @note No Limitations
*
* @return FG_IR_NOT_DETECTED if no interrupt is detected
* @return FG_IR_DETECTED if an interrupt is detected
*/
fg_ir_detected_e vFG_GetIrqCDS(void);


/**
* @brief Implementation of function vFG_GetIrqVBTOS
*
* Allows the MPU to check the source of  interrupt VBTOS
*
* @note No Limitations
*
* @return FG_IR_NOT_DETECTED if no interrupt is detected
* @return FG_IR_DETECTED if an interrupt is detected
*/
fg_ir_detected_e vFG_GetIrqVBTOS(void);


/**
* @brief Implementation of function vFG_GetIrqVSS
*
* Allows the MPU to check the source of  interrupt VSS
*
* @note No Limitations
* @return FG_IR_NOT_DETECTED if no interrupt is detected
* @return FG_IR_DETECTED if an interrupt is detected
*/
fg_ir_detected_e vFG_GetIrqVSS(void);


/**
* @brief Implementation of function vFG_GetIrqMRDYS
*
* Allows the MPU to check the source of  interrupt MRDYS
*
* @note No Limitations
*
* @return FG_IR_NOT_DETECTED if no interrupt is detected
* @return FG_IR_DETECTED if an interrupt is detected
*/
fg_ir_detected_e vFG_GetIrqMRDYS(void);


/**
* @brief Implementation of function vFG_GetIrqNVS
*
* Allows the MPU to check the source of  interrupt NVS
*
* @note No Limitations
*
* @return FG_IR_NOT_DETECTED if no interrupt is detected
* @return FG_IR_DETECTED if an interrupt is detected
*/
fg_ir_detected_e vFG_GetIrqNVS(void);


/**
* @brief Implementation of function vFG_IrqClear
*
* Clears several interrupts
*
* @note No Limitations
*
* @param[in,out] pstIrClear - pointer to to be cleared interrupts
*
* @return void
*/
void vFG_IrqClear(fg_irqclear_st * pstIrClear);


/**
* @brief Implementation of function vFG_IrqClearCDS
*
* Clear interrupt CDS 
*
* @note No Limitations
*
* @return void
*/
void vFG_IrqClearCDS(void);


/**
* @brief Implementation of function vFG_IrqClearVBTOS
*
* Clear interrupt VBTOS 
*
* @note No Limitations
*
* @return void
*/
void vFG_IrqClearVBTOS(void);


/**
* @brief Implementation of function vFG_IrqClearVSS
*
* Clear interrupt VSS 
*
* @note No Limitations
*
* @return void
*/
void vFG_IrqClearVSS(void);


/**
* @brief Implementation of function vFG_IrqClearMRDYS
*
* Clear interrupt MRDYS 
*
* @note No Limitations
*
* @return void
*/
void vFG_IrqClearMRDYS(void);


/**
* @brief Implementation of function vFG_IrqClearNVS
*
* Clear interrupt NVS 
*
* @note No Limitations
*
* @return void
*/
void vFG_IrqClearNVS(void);


/**
* @brief Implementation of function vFG_SetExchColor
*
* Definition of the exchange colour and common alpha value
*
* @note No Limitations
*
* @param[in,out] pstColor - pointer to colors for red, green, blue
*
* @return void
*/
void vFG_SetExchColor(fg_color_exchange_st * pstColor);


/**
* @brief Implementation of function vFG_SetGlobalInputAlpha
*
* Set global alpha value
*
* @note No Limitations
*
* @param[in] u8Alpha - alpha value
*
* @return void
*/
void vFG_SetGlobalInputAlpha(uint8_t u8Alpha);


/**
* @brief Implementation of function vFG_SetClutEntry
*
* Write access to the colour correction look-up tables for each colour component.
*
* @note No Limitations
*
* @param[in] eColor   - color-channel
* @param[in] u16Entry - clut index
* @param[in] u8Color  - color value to be set
*
* @return 0 in case of success
* @return 1 in case of error
*/
uint16_t vFG_SetClutEntry(fg_color_e eColor, uint16_t u16Entry, uint8_t u8Color);


/****************************************************************************/


#endif /* FG_H */

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
  conditions set forth in the �Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (�Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer�s own risk.

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
