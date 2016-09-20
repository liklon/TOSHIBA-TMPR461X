/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : FG Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Frame Grabber (FG)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "fg.h"                            /* FG LLDD definitions */
#include "fg_io.h"                         /* FG registers, bits and access macros defintion */

/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/

#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to narrower underlying type, "type", not allowed */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : conversion from underlying type, "int", to same width underlying type, "uint32_t", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */

  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */

#endif

/*********************************************/


/**********************************************
*             Constants & Macros              *
**********************************************/

#define LLDD_FG_C_REVISION     "$Revision: 1.12 $"
#define LLDD_FG_C_TAG          "$Name: LLDD_1_7_GFX $"

/*********************************************/


/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_FG_C_REVISION[]    = LLDD_FG_C_REVISION;
static uint8_t au8LLDD_FG_C_TAG[]         = LLDD_FG_C_TAG;
static uint8_t au8LLDD_FG_H_REVISION[]    = LLDD_FG_H_REVISION;
static uint8_t au8LLDD_FG_H_TAG[]         = LLDD_FG_H_TAG;
static uint8_t au8LLDD_FG_IO_H_REVISION[] = LLDD_FG_IO_H_REVISION;
static uint8_t au8LLDD_FG_IO_H_TAG[]      = LLDD_FG_IO_H_TAG;

/*********************************************/


/**********************************************
*        Exported function definition         *
**********************************************/

/****************************************************************************
 *  read version   
 ****************************************************************************/
void vFG_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                    uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                    uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_FG_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_FG_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_FG_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_FG_H_TAG[0];
   *pau8IORevision     = &au8LLDD_FG_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_FG_IO_H_TAG[0];
}


/****************************************************************************
 *  nable/Disable Frame Grabber
 ****************************************************************************/
void vFG_FrameGrabberEnable(fg_en_e eEn)
{
    vSetFGDCR_FGACT(eEn);
}


/****************************************************************************
 *  Enable/Disable Cropping
 ****************************************************************************/
void vFG_CroppingEnable(fg_en_e eEn)
{
    vSetFGDCR_CREN(eEn);
}


/****************************************************************************
 *  Enable/Disable Color Correction
 ****************************************************************************/
void vFG_ColorCorrectEnable(fg_en_e eEn)
{
    vSetFGDCR_CCEN(eEn);
}


/****************************************************************************
 *  enable/Disable Frame Grabber
 ****************************************************************************/
void vFG_ConfigureFgSignal(fg_signals_st * pstSignal)
{
    vSetFGDCR_NFODD(pstSignal->eNfOdd);
    vSetFGDCR_NEGPC(pstSignal->eNegPc); 
    vSetFGDCR_ONEC(pstSignal->eOnec); 
    vSetFGDCR_HSACT(pstSignal->eHsact); 
    vSetFGDCR_VSACT(pstSignal->eVsact); 
    vSetFGDCR_HDACT(pstSignal->eHdact); 
    vSetFGDCR_UDSP(pstSignal->eUdsp); 
    vSetFGDCR_USYNC(pstSignal->eUsync); 
}


/****************************************************************************
 *  Configure Input Mode
 ****************************************************************************/
void vFG_SetInputMode(fg_input_format_st * pstMode)
{
    vSetFGCIR_ALPHA(pstMode->u8Alpha);              /* Set global alpha to 0xFF for RGB16->RGBA32 conversion */
    vSetFGDCR_RGBPA(pstMode->eRgbPa);               /* RGB parallel input mode */
    vSetFGDCR_RGB24(pstMode->eRgb16_24);            /* RGB parallel input mode */
    vSetFGDCR_NVMD(pstMode->eNvmd);                 /* Non-video data input mode */
    vSetFGDCR_COMD(pstMode->eComd);                 /* Colour mode */
    vSetFGDCR_INT(pstMode->eInterlMode);            /* Input image interlaced */
    vSetFGDCR_BWEX(pstMode->eBwex);                 /* Use input as alpha value */
    vSetFGDCR_SCBCR(pstMode->stSwapYcbCr.eScbCr);   /* Swap appearance of Y, Cb, Cr values  */
    vSetFGDCR_SYCBCR(pstMode->stSwapYcbCr.eSycbcr); /* Swap appearance of Y, Cb, Cr values */
}


/****************************************************************************
 *  Configure Output Mode
 ****************************************************************************/
void vFG_SetOutputMode(fg_output_format_st * pstMode)
{
    vSetFGDCR_DINT(pstMode->eDeInterl);
    vSetFGDCR_YCBRO(pstMode->eOutputSelector);
    vSetFGDCR_RRGB(pstMode->eRgbFormat);
    vSetFGDCR_MONO(pstMode->eMonochrome);
    vSetFGDCR_CVMD(pstMode->eYcbcr2RgbConv);
}


/****************************************************************************
 *  Configure input image size
 ****************************************************************************/
void vFG_SetInputImageSize(uint16_t u16Width, uint16_t u16Height)
{
    vSetFGIDR_WIDTH (u16Width);
    vSetFGIDR_HEIGHT(u16Height);
}


/****************************************************************************
 *  Configure input image size
 ****************************************************************************/
void vFG_SetInputCropp(fg_input_cropp_st * pstCroppConfig)
{
    vSetFGITR_HWAIT(pstCroppConfig->u16ItrHorizWait);
    vSetFGITR_VWAIT(pstCroppConfig->u16ItrVertWait);
    
    vSetFGHCR_HCW(pstCroppConfig->u16HcrCroppWidth);
    vSetFGHCR_HCS(pstCroppConfig->u16HcrCroppLeftX);
    
    vSetFGVCR_VCH(pstCroppConfig->u16VcrCroppHeight);
    vSetFGVCR_VCS(pstCroppConfig->u16VcrCroppTopY);
}


/****************************************************************************
 *  Set properties of Capture Buffer
 ****************************************************************************/
void vFG_SetCaptureBuffers(fg_capture_buffer_st * pstCaptureBuffer)
{
    vSetFGCAR1(pstCaptureBuffer->u32CbaBufferAddr1); 
    vSetFGCAR2(pstCaptureBuffer->u32CbaBufferAddr2); 
    vSetFGCAR3(pstCaptureBuffer->u32CbaBufferAddr3);   
    vSetFGLOR (pstCaptureBuffer->u16LorLineOffset);   
    vSetFGCCR_CBACT(pstCaptureBuffer->eCbactUsedBuffer);   
}


/****************************************************************************
 *  Get current Capture Buffer
 ****************************************************************************/
fg_cbcur_e eFG_GetCurrentCaptureBuffer(void)
{
    return (fg_cbcur_e)biGetFGCCR_CBCUR();
}


/****************************************************************************
 *  Set memory write protection addresses
 ****************************************************************************/
void vFG_ConfigureMemoryWriteProtection(uint32_t u32StartAddress, uint32_t u32EndAddress)
{
    vSetFGMASR_MAS(u32StartAddress);
    vSetFGMAER_MAE(u32EndAddress);
}


/****************************************************************************
 *  Set properties of scaling
 ****************************************************************************/
void vFG_SetScalingFactors(uint16_t u16ScaleX, uint16_t u16ScaleY)
{
    vSetFGSR_XSCALE(u16ScaleX);
    vSetFGSR_YSCALE(u16ScaleY);
}


/****************************************************************************
 *  Enable several ext. sync measurement 
 ****************************************************************************/
void vFG_EnableMeasurements(fg_measure_extsync_control_st * pstMeasurement)
{
    vSetFGMCR_VCR  (pstMeasurement->eVcr);
    vSetFGMCR_HCR  (pstMeasurement->eHcr);
    vSetFGMCR_VSPWR(pstMeasurement->eVspwr);
    vSetFGMCR_HSPWR(pstMeasurement->eHspwr);
    vSetFGMCR_HDISP(pstMeasurement->eHdisp);
}


/****************************************************************************
 *  Enable ext. sync measurement VCR
 ****************************************************************************/
void vFG_EnableMeasurementVCR(fg_en_e eEn)
{
    vSetFGMCR_VCR(eEn);
}


/****************************************************************************
 *  Enable ext. sync measurement HCR
 ****************************************************************************/
void vFG_EnableMeasurementHCR(fg_en_e eEn)
{
    vSetFGMCR_HCR(eEn);
}


/****************************************************************************
 *  Enable ext. sync measurement HDISP
 ****************************************************************************/
void vFG_EnableMeasurementHDISP(fg_en_e eEn)
{
    vSetFGMCR_HDISP(eEn);
}


/****************************************************************************
 *  Enable ext. sync measurement HSPWR
 ****************************************************************************/
void vFG_EnableMeasurementHSPWR(fg_en_e eEn)
{
    vSetFGMCR_HSPWR(eEn);
}


/****************************************************************************
 *  Enable ext. sync measurement VSPWR
 ****************************************************************************/
void vFG_EnableMeasurementVSPWR(fg_en_e eEn)
{
    vSetFGMCR_VSPWR(eEn);
}


/****************************************************************************
 *  Get results of several ext. sync measurements
 ****************************************************************************/
void vFG_GetMeasurements(fg_measurement_extsync_result_st * pstMeasurement)
{
    pstMeasurement->u16Mvcr   = biGetFGVMR_MVCR();
    pstMeasurement->u16Mhcr   = biGetFGHMR_MHCR();  
    pstMeasurement->u16Mhspwr = biGetFGHMR_MHSPWR();
    pstMeasurement->u16Mvspwr = biGetFGVMR_MVSPWR();
    pstMeasurement->u16Mhdisp = biGetFGMCR_MHDISP();
}


/****************************************************************************
 *  Get result of ext sync measurement MVCR
 ****************************************************************************/
uint16_t vFG_GetMeasurementMVCR(void)
{
    return(uint16_t) biGetFGVMR_MVCR();
}


/****************************************************************************
 *  Get result of ext sync measurement MHCR
 ****************************************************************************/
uint16_t vFG_GetMeasurementMHCR(void)
{
    return(uint16_t) biGetFGHMR_MHCR();
}


/****************************************************************************
 *  Get result of ext sync measurement MHSPWR
 ****************************************************************************/
uint16_t vFG_GetMeasurementMHSPWR(void)
{
    return(uint16_t) biGetFGHMR_MHSPWR();
}


/****************************************************************************
 *  Get result of ext sync measurement MVSPWR
 ****************************************************************************/
uint16_t vFG_GetMeasurementMVSPWR(void)
{
    return(uint16_t) biGetFGVMR_MVSPWR();
}


/****************************************************************************
 *  Get result of ext sync measurement MHDISP
 ****************************************************************************/
uint16_t vFG_GetMeasurementMHDISP(void)
{
    return(uint16_t) biGetFGMCR_MHDISP();
}


/****************************************************************************
 *  Mask generation of several Fg-interrupts
 ****************************************************************************/
void vFG_EnableIrq(fg_irqcgf_st * pstCfg)
{
    vSetFGIMR_CDI(pstCfg->eCdi);
    vSetFGIMR_VBTOI(pstCfg->eVbtoi);
    vSetFGIMR_VSI(pstCfg->eVsi);
    vSetFGIMR_MRDYI(pstCfg->eMrdyi);
    vSetFGIMR_NVI(pstCfg->eNvi);
}


/****************************************************************************
 *  Mask generation of Fg interrupt CDI
 ****************************************************************************/
void vFG_EnableIrqCDI(fg_en_e eEn)
{
    vSetFGIMR_CDI(eEn);
}


/****************************************************************************
 *  Mask generation of Fg interrupt VBTOI
 ****************************************************************************/
void vFG_EnableIrqVBTOI(fg_en_e eEn)
{
    vSetFGIMR_VBTOI(eEn);
}


/****************************************************************************
 *  Mask generation of Fg interrupt VSI
 ****************************************************************************/
void vFG_EnableIrqVSI(fg_en_e eEn)
{
    vSetFGIMR_VSI(eEn);
}


/****************************************************************************
 *  Mask generation of Fg interrupt MRDYI
 ****************************************************************************/
void vFG_EnableIrqMRDYI(fg_en_e eEn)
{
    vSetFGIMR_MRDYI(eEn);
}


/****************************************************************************
 *  Mask generation of Fg interrupt NVI
 ****************************************************************************/
void vFG_EnableIrqNVI(fg_en_e eEn)
{
    vSetFGIMR_NVI(eEn);
}


/****************************************************************************
 *  allows the MPU to check the source of interrupt CDS
 ****************************************************************************/
fg_ir_detected_e vFG_GetIrqCDS(void)
{
    return(fg_ir_detected_e) biGetFGISR_CDS();
}


/****************************************************************************
 *  allows the MPU to check the source of interrupt VBTOS
 ****************************************************************************/
fg_ir_detected_e vFG_GetIrqVBTOS(void)
{
    return(fg_ir_detected_e) biGetFGISR_VBTOS();
}


/****************************************************************************
 *  allows the MPU to check the source of interrupt VSS 
 ****************************************************************************/
fg_ir_detected_e vFG_GetIrqVSS(void)
{
    return(fg_ir_detected_e) biGetFGISR_VSS();
}


/****************************************************************************
 *  allows the MPU to check the source of interrupt MRDYS
 ****************************************************************************/
fg_ir_detected_e vFG_GetIrqMRDYS(void)
{
    return(fg_ir_detected_e) biGetFGISR_MRDYS();
}


/****************************************************************************
 *  allows the MPU to check the source of interrupt NVS
 ****************************************************************************/
fg_ir_detected_e vFG_GetIrqNVS(void)
{
    return(fg_ir_detected_e) biGetFGISR_NVS();
}


/****************************************************************************
 *  clears several interrupts
 ****************************************************************************/
void vFG_IrqClear(fg_irqclear_st * pstIrClear)
{
    if(pstIrClear->eCds == FG_IR_CLEAR)
    {
        vClrFGISR_CDS();
    }
    if(pstIrClear->eVbtos == FG_IR_CLEAR)
    {
        vClrFGISR_VBTOS();
    }
    if(pstIrClear->eVss == FG_IR_CLEAR)
    {
        vClrFGISR_VSS();
    }
    if(pstIrClear->eMrdys == FG_IR_CLEAR)
    {
        vClrFGISR_MRDYS();
    }
    if(pstIrClear->eNvs == FG_IR_CLEAR)
    {
        vClrFGISR_NVS();
    }
}


/****************************************************************************
 *  clear interrupt CDS 
 ****************************************************************************/
void vFG_IrqClearCDS(void)
{
    vClrFGISR_CDS();
}


/****************************************************************************
  *  clear interrupt VBTOS 
 ****************************************************************************/
void vFG_IrqClearVBTOS(void)
{
    vClrFGISR_VBTOS();
}


/****************************************************************************
 *  clear interrupt VSS 
 ****************************************************************************/
void vFG_IrqClearVSS(void)
{
    vClrFGISR_VSS();
}


/****************************************************************************
 *  clear interrupt MRDYS 
 ****************************************************************************/
void vFG_IrqClearMRDYS(void)
{
    vClrFGISR_MRDYS();
}


/****************************************************************************
 *  clear interrupt NVS 
 ****************************************************************************/
void vFG_IrqClearNVS(void)
{
    vClrFGISR_NVS();
}


/****************************************************************************
 *  Definition of the exchange colour and common alpha value
 ****************************************************************************/
void vFG_SetExchColor(fg_color_exchange_st * pstColor)
{
    vSetFGCIR_RED(pstColor->u8Red);
    vSetFGCIR_GREEN(pstColor->u8Green);
    vSetFGCIR_BLUE(pstColor->u8Blue);
 
}


/****************************************************************************
 *  Definition of the exchange colour and common alpha value
 ****************************************************************************/
void vFG_SetGlobalInputAlpha(uint8_t u8Alpha)
{
    vSetFGCIR_ALPHA(u8Alpha);
}


/****************************************************************************
 *  write access to the colour correction look-up tables for each colour component.
 ****************************************************************************/
uint16_t vFG_SetClutEntry(fg_color_e eColor, uint16_t u16Entry, uint8_t u8Color)
{
    uint16_t u16Ret;

    if( u16Entry > 255 ) 
    { 
         u16Ret = 1;
    }
    else 
    {
        u16Ret = 0;
        switch( eColor ) 
        {
            case FG_RED:
                vSetFGCCLR(u16Entry, u8Color);  
                break;     

            case FG_GREEN:
                vSetFGCCLG(u16Entry, u8Color);  
                break;     

            case FG_BLUE:
                vSetFGCCLB(u16Entry, u8Color);  
                break;

            default:
                break;
        }   
    } 
    return u16Ret;  
}

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
  general electronics applications(computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury(“Unintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer’s own risk.

- Toshiba assumes no liability for any damage or losses(including but not
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
