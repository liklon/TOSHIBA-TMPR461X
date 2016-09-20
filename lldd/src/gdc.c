/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference GDC Low Level Device Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphics Display Controller (GDC)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.19 $
*   DATE        : $Date: 2015/05/04 09:07:15 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "gdc_io.h"                         /* GDC registers, bits and access macros defintion */
#include "gdc.h"                            /* GDC LLDD definitions */

/*********************************************/
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1849  /* Rule 8.1  [R] : bitwise ~ or << expression must be immediately cast back to  underlying type, "unsigned char" */
  #pragma ghs nowarning 1858  /* Rule 17.4 [R] : subscript operator may only be applied to objects declared as an array type */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to narrower underlying type, "type", not allowed */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : conversion from underlying type, "int", to same width underlying type, "uint32_t", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : implicit conversion of complex expression from underlying type, "type", to underlying type, "type", not allowed */
  #pragma ghs nowarning 1878  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to wider type "type" not allowed */
  #pragma ghs nowarning 1879  /* Rule 10.3 [R] : Restrict explicit casts for integer type expressions */

  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */  
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error (used for result of i/o header amcros) */
  #pragma ghs nowarning 1835  /* Rule 11.4 [A] : allow cast from type "type" to type "type" */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1853  /* Rule 12.6 [A] : effectively boolean expression required */
  #pragma ghs nowarning 1855  /* Rule 13.2 [A] : Explicit test of a value against zero unless the expression is Boolean */

#endif  

/**********************************************
*                 Constants                   *
**********************************************/

#ifdef HW_UPDATE_BUG_FIXED
/* This macro should be moved to enum gdc_reg_update_mode_e
 * if the HW buf will be fixed: */

#define GDC_NO_UPDATE_BY_VSYNC  0

#endif

/**********************************************
*   Macros for Read/write shadow registers    *
**********************************************/

/* write a value in shadow register: */
#define UPDATE_REGISTER_LOW_WORD(chn, reg, ParValue)   (*((volatile uint32_t*) ((reg) + ((uint32_t)(chn) * GDC1_REGADR_OFFSET) )) = ((uint32_t)(ParValue)))
#define UPDATE_REGISTER_HIGH_WORD(chn, reg, ParValue)  (*((volatile uint32_t*) ((reg) + ((uint32_t)(chn) * GDC1_REGADR_OFFSET) + 4 )) = ((uint32_t)((ParValue)>>32)))
#define UPDATE_REGISTER_64BITS(chn, reg, ParValue)     (*((volatile uint64_t*) ((reg) + ((uint32_t)(chn) * GDC1_REGADR_OFFSET) )) = (ParValue))

/* Macros for 32 bit/64 bit read of shadow register: */
#define READ_REGISTER_LOW_WORD(reg, chn)  (*((volatile uint32_t*) ((reg) + ((uint8_t)(chn) * GDC1_REGADR_OFFSET) )))
#define READ_REGISTER_HIGH_WORD(reg, chn) (*((volatile uint32_t*) ((reg) + ((uint8_t)(chn) * GDC1_REGADR_OFFSET) + 4)))
#define READ_REGISTER_64BITS(reg, chn)    (*((volatile uint64_t*) ((reg) + ((uint8_t)(chn) * GDC1_REGADR_OFFSET) )))

/**********************************************
*             Constants & Macros              *
**********************************************/
/* Access masks */
#define GDC_SARXN_SAR_MASK                  0xFFFFFFF8U
#define GDC_CBARX_MASK                      0xFFFFFFF8U
#define GDC_1_BIT_MASK                      0x00000001U
#define GDC_3_BIT_MASK                      0x00000007U
#define GDC_8_BIT_MASK                      0x000000FFU
#define GDC_10_BIT_MASK                     0x000003FFU
#define GDC_11_BIT_MASK                     0x000007FFU
#define GDC_12_BIT_MASK                     0x00000FFFU
#define GDC_WARXN_WAR_MASK                  0xFFFFFFFEU
#define GDC_SCVR_LCCV_MASK                  0x0000000000FFFFFFU
#define GDC_SCVR_HACT_MASK                  0x8000000000000000U
#define GDC_DCR_ERR_GBER_MASK               0x0000000000080000U /* Mask for Clear bit GDCDCR-GBER/Bit 19)       */
#define GDC_DCR_ERR_GAPCOL_MASK             0x0200000000000000U /* Mask for Clear bit GDCDCR-GAPCOL/bit 57      */
#define GDC_DCR_ERR_GBER_AND_GAPCOL_MASK   (GDC_DCR_ERR_GBER_MASK | GDC_DCR_ERR_GAPCOL_MASK) /* Mask for Clear bit GDCDCR-GBER and GAPCOL bits */

#define MAX_WAIT_FOR_CLEAR                  1000

/* Lower range values */
#define GDC_DIMR_WIDTH_MIN_VAL              64
#define GDC_WIMR_WIDHT_MIN_VAL              8

/* range of display start position: */
#define GDC_DISP_HSTART_MIN  64U
#define GDC_DISP_HSTART_MAX  2047U
#define GDC_DISP_VSTART_MIN  64U
#define GDC_DISP_VSTART_MAX  1023U

/* range of display size: */
#define GDC_DISP_WIDTH_MIN   64U
#define GDC_DISP_WIDTH_MAX   2047U
#define GDC_DISP_HEIGHT_MIN  1U
#define GDC_DISP_HEIGHT_MAX  1023U

#define GDC_PGEN_GALVL_BITS     1
#define GDC_PGEN_GAINSEL_BITS   3
#define GDC_PGEN_GABYP_BIT      1
#define GDC_PGEN_GADEL_BIT      11
#define GDC_PGEN_GADIV_BIT      4
#define GDC_PGEN_GAINV_BIT      1
#define GDC_PGEN_GAWID_BIT      11

#define GDC_DCP1_VAL_MIN        9

/*********************************************/
 
/**********************************************
*             Constants & Macros              *
**********************************************/
#define LAYER_FMT_32bpp   0  /* 32-bit RGBA/ARGB */
#define LAYER_FMT_16bpp   1  /* 16-bit RGB       */  

#define LLDD_GDC_C_REVISION     "$Revision: 1.19 $"
#define LLDD_GDC_C_TAG          "$Name: LLDD_1_7_GFX $"

/*********************************************/
 /* Following variables will be used to keep register data before writing in shadow registers:
  * they should be defined as global, otherwise the usage of macros in gdx_io.h by another 
  * applications will not work: */
    
 volatile uint64_t u64GDCDCR_REG__Var[2]        __attribute__ ((aligned(8)));
 volatile uint64_t u64GDCCAVRA_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint64_t u64GDCSCVRA_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint64_t u64GDCSCVRB_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint64_t u64GDCSCVRC_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint64_t u64GDCSCVRD_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint64_t u64APCCR_REG__Var[2]         __attribute__ ((aligned(8)));
 volatile uint64_t u64APCCWR_REG__Var[2]        __attribute__ ((aligned(8)));
 volatile uint64_t u64APCCSR_REG__Var[2]        __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARA0_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARA1_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWARA_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCBGCR_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARB0_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARB1_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWARB_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARC0_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARC1_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARD0_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARD1_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCMWRA_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCMWRB_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCMWRC_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCMWRD_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCMWRE_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLSRA_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLSRB_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLSRC_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLSRD_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLSRE_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLDRA_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLDRB_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLDRC_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLDRD_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLDRE_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWSRA_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWSRB_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWIMRA_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWIMRB_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCCAVRB_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCHSR_REG__Var[2]        __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCVSR_REG__Var[2]        __attribute__ ((aligned(8)));
 
 volatile uint32_t u32GDCCBAR0_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCCBAR1_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCCBAR2_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCPTCR_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCGPCRA_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCGPCRB_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCGPCRC_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCPSMR_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARE0_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCLARE1_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWARC_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWARD_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWARE_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWSRC_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWSRD_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWSRE_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWIMRC_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWIMRD_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCWIMRE_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCDSR_REG__Var[2]        __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCDIMR_REG__Var[2]       __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCPROTR_REG__Var[2]      __attribute__ ((aligned(8)));
 volatile uint32_t u32APCPROTR_REG__Var[2]      __attribute__ ((aligned(8)));

 volatile uint32_t u32GDCPxGAR_REG__Var[2][12]  __attribute__ ((aligned(8)));
 volatile uint32_t u32GDCPxGBR_REG__Var[2][12]  __attribute__ ((aligned(8)));

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

/**********************************************
*             Variables                       *
**********************************************/
static uint8_t au8LLDD_GDC_C_REVISION[]    = LLDD_GDC_C_REVISION;
static uint8_t au8LLDD_GDC_C_TAG[]         = LLDD_GDC_C_TAG;
static uint8_t au8LLDD_GDC_H_REVISION[]    = LLDD_GDC_H_REVISION;
static uint8_t au8LLDD_GDC_H_TAG[]         = LLDD_GDC_H_TAG;
static uint8_t au8LLDD_GDC_IO_H_REVISION[] = LLDD_GDC_IO_H_REVISION;
static uint8_t au8LLDD_GDC_IO_H_TAG[]      = LLDD_GDC_IO_H_TAG;

/**********************************************
*             local prototypes                *
**********************************************/
static void vUpdateDCR_HighWord_Special(gdc_ch_e eGDC);
static void vUpdateDCR_Special(gdc_ch_e eGDC);

/**********************************************
*          static functions                   *
**********************************************/
static void vUpdateDCR_HighWord_Special(gdc_ch_e eGDC)
{
    /* Since UPDREG may be changed by HW (From 2 to 0) and 
     * it belongs to higher 32 bit or register, all modifications of
     * higher 32 bits (bits 32..63) from DCR register should be handled
     * special, to synchronize UPDREG in HW and local storage of register: */
    
    gdc_reg_update_mode_e  eUpdModeHW;

    /* synchronisation of update mode in HW and local storage of register: */
    /* get the update mode from HW: */
    eUpdModeHW = (gdc_reg_update_mode_e) biGetGDCDCR_UPDREG_Direct(eGDC);
    
    /* to be synchronized with HW, update local variable: */
    vSetGDCDCR_UPDREG(eGDC, eUpdModeHW);
    
    /* write now high word of DCR register in HW: */
    UPDATE_REGISTER_HIGH_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}
/****************************************************************************/
static void vUpdateDCR_Special(gdc_ch_e eGDC)
{
    /* this function will be used, where Low and high word of DCR register
     * has been changed. In this case Shadow register update should be disabled first: */
    gdc_reg_update_mode_e  eUpdModeHW;

    /* Get update mode from HW for later restore: */
    eUpdModeHW = (gdc_reg_update_mode_e) biGetGDCDCR_UPDREG_Direct(eGDC);

#ifdef HW_UPDATE_BUG_FIXED
    /* Disable Update Mode, if it was not disabled: */
    if (GDC_NO_UPDATE_BY_VSYNC != eUpdModeHW)
    {
        vGDC_SetShadowRegUpdateMode(eGDC, GDC_NO_UPDATE_BY_VSYNC);
    }
#endif
    /* Write Low Word first: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);

    /* restore update mode and write high word to HW: */
    vGDC_SetShadowRegUpdateMode(eGDC, eUpdModeHW);
}
/**********************************************
*        Exported function definition         *
**********************************************/
void vGDC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                    uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                    uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
     *pau8ModuleRevision = &au8LLDD_GDC_C_REVISION[0];
     *pau8ModuleTag      = &au8LLDD_GDC_C_TAG[0];
     *pau8HeaderRevision = &au8LLDD_GDC_H_REVISION[0];
     *pau8HeaderTag      = &au8LLDD_GDC_H_TAG[0];
     *pau8IORevision     = &au8LLDD_GDC_IO_H_REVISION[0];
     *pau8IOTag          = &au8LLDD_GDC_IO_H_TAG[0];
}


/****************************************************************************/
void vGDC_Init(gdc_ch_e eGDC)
{
    /* this function initializes local values for registers at beginning.
         * It is important, that Clear Bit will be set to "0" in local values,
         * Other wise by write back to shadow register they will be reset!
         * */
    uint32_t u32Chn;
    
    u32Chn = (GDC0 == eGDC)? 0x00U : 0x01U;
    
    u64GDCDCR_REG__Var[u32Chn]    = READ_REGISTER_64BITS(GDCDCR_REG__ , u32Chn);
    /* Important NOTE:
     * Clear Bits should not be set in local variables, other wise the clear bit will be reset by
     * next shadow register update and application will not know about it. 
     * Mask  Clr bits (GAPCOL/bit 57 and GBER/Bit 19 ) */
    u64GDCDCR_REG__Var[u32Chn]   &= (~GDC_DCR_ERR_GBER_AND_GAPCOL_MASK);
    
    u64GDCCAVRA_REG__Var[u32Chn]  = READ_REGISTER_64BITS(GDCCAVRA_REG__ , u32Chn);
    u64GDCSCVRA_REG__Var[u32Chn]  = READ_REGISTER_64BITS(GDCSCVRA_REG__ , u32Chn);
    u64GDCSCVRB_REG__Var[u32Chn]  = READ_REGISTER_64BITS(GDCSCVRB_REG__ , u32Chn);
    u64GDCSCVRC_REG__Var[u32Chn]  = READ_REGISTER_64BITS(GDCSCVRC_REG__ , u32Chn);
    u64GDCSCVRD_REG__Var[u32Chn]  = READ_REGISTER_64BITS(GDCSCVRD_REG__ , u32Chn);
    u64APCCR_REG__Var[u32Chn]     = READ_REGISTER_64BITS(APCCR_REG__ , u32Chn);
    u64APCCWR_REG__Var[u32Chn]    = READ_REGISTER_64BITS(APCCWR_REG__ , u32Chn);
    
    /* Note: CURCHKSUM is a R/C Bit, it means after read CURCHKSUM will be reset!: */
    u64APCCSR_REG__Var[u32Chn]    = READ_REGISTER_64BITS(APCCSR_REG__ , u32Chn);
    
    u32GDCLARA0_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARA0_REG__ , u32Chn);
    u32GDCLARA1_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARA1_REG__ , u32Chn);
    u32GDCWARA_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWARA_REG__ , u32Chn);
    u32GDCBGCR_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCBGCR_REG__ , u32Chn);
    u32GDCLARB0_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARB0_REG__ , u32Chn);
    u32GDCLARB1_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARB1_REG__ , u32Chn);
    u32GDCWARB_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWARB_REG__ , u32Chn);
    u32GDCLARC0_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARC0_REG__ , u32Chn);
    u32GDCLARC1_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARC1_REG__ , u32Chn);
    u32GDCLARD0_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARD0_REG__ , u32Chn);
    u32GDCLARD1_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARD1_REG__ , u32Chn);
    u32GDCMWRA_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCMWRA_REG__ , u32Chn);
    u32GDCMWRB_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCMWRB_REG__ , u32Chn);
    u32GDCMWRC_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCMWRC_REG__ , u32Chn);
    u32GDCMWRD_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCMWRD_REG__ , u32Chn);
    u32GDCMWRE_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCMWRE_REG__ , u32Chn);
    u32GDCLSRA_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLSRA_REG__ , u32Chn);
    u32GDCLSRB_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLSRB_REG__ , u32Chn);
    u32GDCLSRC_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLSRC_REG__ , u32Chn);
    u32GDCLSRD_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLSRD_REG__ , u32Chn);
    u32GDCLSRE_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLSRE_REG__ , u32Chn);
    u32GDCLDRA_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLDRA_REG__ , u32Chn);
    u32GDCLDRB_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLDRB_REG__ , u32Chn);
    u32GDCLDRC_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLDRC_REG__ , u32Chn);
    u32GDCLDRD_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLDRD_REG__ , u32Chn);
    u32GDCLDRE_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCLDRE_REG__ , u32Chn);
    u32GDCWSRA_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWSRA_REG__ , u32Chn);
    u32GDCWSRB_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWSRB_REG__ , u32Chn);
    u32GDCWIMRA_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCWIMRA_REG__ , u32Chn);
    u32GDCWIMRB_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCWIMRB_REG__ , u32Chn);
    u32GDCCAVRB_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCCAVRB_REG__ , u32Chn);
    u32GDCHSR_REG__Var[u32Chn]    = READ_REGISTER_LOW_WORD(GDCHSR_REG__ , u32Chn);
    u32GDCVSR_REG__Var[u32Chn]    = READ_REGISTER_LOW_WORD(GDCVSR_REG__ , u32Chn);
    
    u32GDCCBAR0_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCCBAR0_REG__ , u32Chn);
    u32GDCCBAR1_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCCBAR1_REG__ , u32Chn);
    u32GDCCBAR2_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCCBAR2_REG__ , u32Chn);
    u32GDCPTCR_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCPTCR_REG__ , u32Chn);
    u32GDCGPCRA_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCGPCRA_REG__ , u32Chn);
    u32GDCGPCRB_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCGPCRB_REG__ , u32Chn);
    u32GDCGPCRC_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCGPCRC_REG__ , u32Chn);
    u32GDCPSMR_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCPSMR_REG__ , u32Chn);
    u32GDCLARE0_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARE0_REG__ , u32Chn);
    u32GDCLARE1_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCLARE1_REG__ , u32Chn);
    u32GDCWARC_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWARC_REG__ , u32Chn);
    u32GDCWARD_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWARD_REG__ , u32Chn);
    u32GDCWARE_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWARE_REG__ , u32Chn);
    u32GDCWSRC_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWSRC_REG__ , u32Chn);
    u32GDCWSRD_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWSRD_REG__ , u32Chn);
    u32GDCWSRE_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCWSRE_REG__ , u32Chn);
    u32GDCWIMRC_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCWIMRC_REG__ , u32Chn);
    u32GDCWIMRD_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCWIMRD_REG__ , u32Chn);
    u32GDCWIMRE_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCWIMRE_REG__ , u32Chn);
    u32GDCDSR_REG__Var[u32Chn]    = READ_REGISTER_LOW_WORD(GDCDSR_REG__ , u32Chn);
    u32GDCDIMR_REG__Var[u32Chn]   = READ_REGISTER_LOW_WORD(GDCDIMR_REG__ , u32Chn);
    u32GDCPROTR_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(GDCPROTR_REG__ , u32Chn);
    u32APCPROTR_REG__Var[u32Chn]  = READ_REGISTER_LOW_WORD(APCPROTR_REG__ , u32Chn);

    u32GDCPxGAR_REG__Var[u32Chn][0]  = READ_REGISTER_LOW_WORD(GDCP0GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][1]  = READ_REGISTER_LOW_WORD(GDCP1GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][2]  = READ_REGISTER_LOW_WORD(GDCP2GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][3]  = READ_REGISTER_LOW_WORD(GDCP3GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][4]  = READ_REGISTER_LOW_WORD(GDCP4GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][5]  = READ_REGISTER_LOW_WORD(GDCP5GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][6]  = READ_REGISTER_LOW_WORD(GDCP6GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][7]  = READ_REGISTER_LOW_WORD(GDCP7GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][8]  = READ_REGISTER_LOW_WORD(GDCP8GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][9]  = READ_REGISTER_LOW_WORD(GDCP9GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][10] = READ_REGISTER_LOW_WORD(GDCP10GAR_REG__ , u32Chn);
    u32GDCPxGAR_REG__Var[u32Chn][11] = READ_REGISTER_LOW_WORD(GDCP11GAR_REG__ , u32Chn);
    
    u32GDCPxGBR_REG__Var[u32Chn][0]  = READ_REGISTER_LOW_WORD(GDCP0GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][1]  = READ_REGISTER_LOW_WORD(GDCP1GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][2]  = READ_REGISTER_LOW_WORD(GDCP2GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][3]  = READ_REGISTER_LOW_WORD(GDCP3GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][4]  = READ_REGISTER_LOW_WORD(GDCP4GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][5]  = READ_REGISTER_LOW_WORD(GDCP5GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][6]  = READ_REGISTER_LOW_WORD(GDCP6GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][7]  = READ_REGISTER_LOW_WORD(GDCP7GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][8]  = READ_REGISTER_LOW_WORD(GDCP8GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][9]  = READ_REGISTER_LOW_WORD(GDCP9GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][10] = READ_REGISTER_LOW_WORD(GDCP10GBR_REG__ , u32Chn);
    u32GDCPxGBR_REG__Var[u32Chn][11] = READ_REGISTER_LOW_WORD(GDCP11GBR_REG__ , u32Chn);
    
}


/****************************************************************************/
void vGDC_Switch(gdc_ch_e eGDC, gdc_on_e eSwitch)
{
    vSetGDCDCR_GDCON(eGDC, eSwitch);
    /* GDCON: belongs to high word of register: */
    /* GDCDCR register should be updated special: */  
    vUpdateDCR_HighWord_Special(eGDC);
}


/****************************************************************************/
void vGDC_SetShadowRegUpdateMode(gdc_ch_e eGDC, gdc_reg_update_mode_e eCtrl)
{
    /* Note:
     * in this fucntion UPDREG bits of DCR register should be modified.
     * These bits are in higher wordt of shadow register, so we modicy only the higher part. 
     */
    
    /* Set UPDREG bits in backup variables: */
    vSetGDCDCR_UPDREG(eGDC, eCtrl);
    /* UPDREG: belongs to high word of register: */
    UPDATE_REGISTER_HIGH_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
gdc_reg_update_status_e eGetShadowRegUpdateStatus(gdc_ch_e eGDC)
{
    gdc_reg_update_status_e eUpdMode;
    
    /* get the update mode from HW: */
    eUpdMode = (gdc_reg_update_status_e) biGetGDCDCR_UPDREG_Direct(eGDC);
    
    /* to be synchronized with HW, update local variable: */
    vSetGDCDCR_UPDREG(eGDC, eUpdMode);

    return eUpdMode;
}


/****************************************************************************/
void vGDC_SetDispConfigType(gdc_ch_e eGDC, gdc_disp_config_type_e eDispConfigType)
{
    vSetGDCDCR_LAD(eGDC, eDispConfigType);
    /* LAD: belongs to high word of register: */
    /* GDCDCR register should be updated special: */  
    vUpdateDCR_HighWord_Special(eGDC);
}


/****************************************************************************/
void vGDC_ADBSEnable(gdc_ch_e eGDC, gdc_en_e eEn)
{
    vSetGDCDCR_ADBS(eGDC, eEn);
    /* ADBS: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_ColorCorrectEnable(gdc_ch_e eGDC, gdc_en_e eEn)
{
    vSetGDCDCR_CCEN(eGDC, eEn);
    /* CCEN: belongs to high word of register: */
    /* GDCDCR register should be updated special: */  
    vUpdateDCR_HighWord_Special(eGDC);
}


/****************************************************************************/
void vGDC_SetArthMode(gdc_ch_e eGDC, gdc_arth_e eMode, gdc_arthcd_e eLoc)
{
    vSetGDCDCR_ARTHCD(eGDC, eLoc);
    vSetGDCDCR_ARTH(eGDC, eMode);
    /* ARTH & vSetGDCDCR_ARTHCD: belong to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SetDitheringMode(gdc_ch_e eGDC, gdc_dithering_e eDith)
{
    vSetGDCDCR_DITHEN(eGDC, eDith);
    /* DITHEN: belongs to high word of register: */
    /* GDCDCR register should be updated special: */  
    vUpdateDCR_HighWord_Special(eGDC);
}

/****************************************************************************/
void vGDC_SetBgrColor(gdc_ch_e eGDC, uint32_t u32Color)
{
    /* Shift to adjust the bits according to the register layout */
    vSetGDCBGCR(eGDC, (u32Color << 8) );
    
    /* Low Word of GDCBGCR register should be updated  */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCBGCR_REG__, u32GDCBGCR_REG__Var[eGDC]);
}


/****************************************************************************/
gdc_en_e eGDC_GetDispStat(gdc_ch_e eGDC)
{
    return (gdc_en_e) biGetGDCDCR_DISPIFON(eGDC);
}


/****************************************************************************/
gdc_en_e eGDC_GetPanelStat(gdc_ch_e eGDC)
{
    return (gdc_en_e) biGetGDCDCR_PNLIFON(eGDC);
}

/****************************************************************************/
uint32_t u32GDC_GetStatVSync(gdc_ch_e eGDC)
{
    return (uint32_t) biGetGDCDCR_VSYNC(eGDC);
}


/****************************************************************************/
uint32_t u32GDC_GetPolVSync(gdc_ch_e eGDC)
{
    return (uint32_t) biGetGDCDCR_PVSYNC(eGDC);
}


/****************************************************************************/
uint32_t u32GDC_GetStatHSync(gdc_ch_e eGDC)
{
    return (uint32_t) biGetGDCDCR_HSYNC(eGDC);
}


/****************************************************************************/
uint32_t u32GDC_GetStatHDisp(gdc_ch_e eGDC)
{
    return (uint32_t) biGetGDCDCR_HDISP(eGDC);
}


/****************************************************************************/
void vGDC_SelDotClkSrc(gdc_ch_e eGDC, gdc_idc_e eSel)
{
    vSetGDCDCR_IDC(eGDC, eSel);
    /* IDC: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SetDotClkPol(gdc_ch_e eGDC, gdc_pol_e ePol)
{
    vSetGDCDCR_PDC(eGDC, ePol);
    /* PDC: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
int32_t i32GDC_LayerEnable(gdc_ch_e eGDC, gdc_layer_e eLayer, gdc_en_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    switch( eLayer )
    {
        case GDC_LAYER_A:
            vSetGDCDCR_AEN(eGDC, eEn);
            /* AEN: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
            break;

        case GDC_LAYER_B:
            vSetGDCDCR_BEN(eGDC, eEn);
            /* BEN: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
            break;

        case GDC_LAYER_C:
            vSetGDCDCR_CEN(eGDC, eEn);
            /* CEN: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
            break;

        case GDC_LAYER_D:
            vSetGDCDCR_DEN(eGDC, eEn);
            /* DEN: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
            break;

        case GDC_LAYER_E:
            vSetGDCDCR_EEN(eGDC, eEn);
            /* EEN: belongs to high word of register: */
            /* GDCDCR register should be updated special: */  
            vUpdateDCR_HighWord_Special(eGDC);
            break;

        default:
            /* Unsupported layer */
            i32Res = C_FAILED;
            break;
    }
    return i32Res;
}


/****************************************************************************/
int32_t i32GDC_SetDataFormat(gdc_ch_e eGDC, gdc_layer_e eLayer, gdc_dfmt_e eFmt)
{
    int32_t i32Res = C_SUCCESS;
    uint8_t u8Fmt;

    /* check pixel format for validity (clut not supported) */
    switch( eFmt )
    {
        case GDC_RGBA32:
        case GDC_ARGB32:
            u8Fmt = (uint8_t)LAYER_FMT_32bpp;
            break;

        case GDC_RGB16:
            u8Fmt = (uint8_t)LAYER_FMT_16bpp;
            break;

        default:
            i32Res = C_FAILED;
            break;
     }
   if (i32Res == C_SUCCESS)
   {
       /* 32 vs. 16-bit mode */
       switch( eLayer )
       {
           case GDC_LAYER_A:
               vSetGDCDCR_A16(eGDC, u8Fmt);
               break;

           case GDC_LAYER_B:
               vSetGDCDCR_B16(eGDC, u8Fmt);
               break;

           case GDC_LAYER_C:
               vSetGDCDCR_C16(eGDC, u8Fmt);
               break;

           case GDC_LAYER_D:
               vSetGDCDCR_D16(eGDC, u8Fmt);
               break;

           case GDC_LAYER_E:
               vSetGDCDCR_E16(eGDC, u8Fmt);
               break;

           /* Unsupported Layer */
           default:
               i32Res = C_FAILED;
               break;
       }
       if ( C_FAILED != i32Res)
       {
           /* set the flag to indicates ARGB or RGBA format*/
           if ( eFmt == GDC_ARGB32)
           {
             /* ARGB supported: This will affect all Layers!*/
             vSetGDCDCR_ARGBEN(eGDC, 1);
           }
           else
           {
               if ( eFmt == GDC_RGBA32)
               {
                 /* RGBA supported: This will effect all Layers!*/
                 vSetGDCDCR_ARGBEN(eGDC, 0);
               }
           }
           /* GDCDCR register should be updated special: */  
           vUpdateDCR_Special(eGDC);
       }
    }

    return i32Res;
}


/****************************************************************************/
void vGDC_SetLayerStart(gdc_ch_e eGDC, gdc_layer_e eLayer, uint16_t u16HStart, uint16_t u16VStart)
{
    uint32_t u32Val;

    /* Compose the entire register value */
    u32Val = (((uint32_t) (u16HStart & GDC_11_BIT_MASK)) << 16) | (u16VStart & GDC_10_BIT_MASK);

    /* Set */
    switch( eLayer )
    {
        case GDC_LAYER_A:
            vSetGDCLSRA(eGDC, u32Val);
            /* LVS & LHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCLSRA_REG__, u32GDCLSRA_REG__Var[eGDC]);
            break;

        case GDC_LAYER_B:
            vSetGDCLSRB(eGDC, u32Val);
            /* LVS & LHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCLSRB_REG__, u32GDCLSRB_REG__Var[eGDC]);
            break;

        case GDC_LAYER_C:
            vSetGDCLSRC(eGDC, u32Val);
            /* LVS & LHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCLSRC_REG__, u32GDCLSRC_REG__Var[eGDC]);
            break;

        case GDC_LAYER_D:
            vSetGDCLSRD(eGDC, u32Val);
            /* LVS & LHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCLSRD_REG__, u32GDCLSRD_REG__Var[eGDC]);
            break;

        case GDC_LAYER_E:
            vSetGDCLSRE(eGDC, u32Val);
            /* LVS & LHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCLSRE_REG__, u32GDCLSRE_REG__Var[eGDC]);
            break;

        default:
            break;
    }
}


/****************************************************************************/
int32_t i32GDC_SetLayerSize(gdc_ch_e eGDC, gdc_layer_e eLayer, uint16_t u16Width, uint16_t u16Height)
{
    int32_t i32Res = C_SUCCESS;
    uint32_t u32Val;


    if( (u16Width & GDC_12_BIT_MASK) < GDC_DIMR_WIDTH_MIN_VAL  )
    {
        i32Res = C_FAILED;
    }
    else
    {
        /* Compose the entire register value */
        u32Val = (((uint32_t) (u16Width & GDC_12_BIT_MASK)) << 16) | (u16Height & GDC_11_BIT_MASK);

        /* Set */
        switch( eLayer )
        {
            case GDC_LAYER_A:
                vSetGDCLDRA(eGDC, u32Val);
                /* LHEIGHT & LWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLDRA_REG__, u32GDCLDRA_REG__Var[eGDC]);
                break;

            case GDC_LAYER_B:
                vSetGDCLDRB(eGDC, u32Val);
                /* LHEIGHT & LWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLDRB_REG__, u32GDCLDRB_REG__Var[eGDC]);
                break;

            case GDC_LAYER_C:
                vSetGDCLDRC(eGDC, u32Val);
                /* LHEIGHT & LWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLDRC_REG__, u32GDCLDRC_REG__Var[eGDC]);
                break;

            case GDC_LAYER_D:
                vSetGDCLDRD(eGDC, u32Val);
                /* LHEIGHT & LWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLDRD_REG__, u32GDCLDRD_REG__Var[eGDC]);
                break;

            case GDC_LAYER_E:
                vSetGDCLDRE(eGDC, u32Val);
                /* LHEIGHT & LWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLDRE_REG__, u32GDCLDRE_REG__Var[eGDC]);
                break;

            default:
                i32Res = C_FAILED;
                break;
        }
    }

    return i32Res;
}


/****************************************************************************/
void vGDC_SetLayerOrder(gdc_ch_e eGDC, gdc_vord_e eOrder)
{
    vSetGDCDCR_VORD(eGDC, eOrder);
    /* VORD: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
int32_t i32GDC_SetCommonAlpha(gdc_ch_e eGDC, gdc_seg_e eEntity, uint8_t u8Alpha)
{
    int32_t i32Res = C_SUCCESS;

    switch( eEntity )
    {
        case GDC_SEG_LAYER_A:
            vSetGDCCAVRA_ALPHAA(eGDC, u8Alpha);
            /* ALPHAA: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCAVRA_REG__, u64GDCCAVRA_REG__Var[eGDC]);
            break;

        case GDC_SEG_LAYER_B:
            vSetGDCCAVRA_ALPHAB(eGDC, u8Alpha);
            /* ALPHAB: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCAVRA_REG__, u64GDCCAVRA_REG__Var[eGDC]);
            break;

        case GDC_SEG_LAYER_C:
            vSetGDCCAVRA_ALPHAC(eGDC, u8Alpha);
            /* ALPHAC: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCCAVRA_REG__, u64GDCCAVRA_REG__Var[eGDC]);
            break;

        case GDC_SEG_LAYER_D:
            vSetGDCCAVRA_ALPHAD(eGDC, u8Alpha);
            /* ALPHAD: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCCAVRA_REG__, u64GDCCAVRA_REG__Var[eGDC]);
            break;

        case GDC_SEG_LAYER_E:
            vSetGDCCAVRB_ALPHAE(eGDC, u8Alpha);
            /* ALPHAE: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCAVRB_REG__, u32GDCCAVRB_REG__Var[eGDC]);
            break;

        case GDC_SEG_WIN_A:
            vSetGDCCAVRA_WALPHAA(eGDC, u8Alpha);
            /* WALPHAA: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCAVRA_REG__, u64GDCCAVRA_REG__Var[eGDC]);
            break;

        case GDC_SEG_WIN_B:
            vSetGDCCAVRA_WALPHAB(eGDC, u8Alpha);
            /* WALPHAB: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCAVRA_REG__, u64GDCCAVRA_REG__Var[eGDC]);
            break;

        case GDC_SEG_WIN_C:
            vSetGDCCAVRA_WALPHAC(eGDC, u8Alpha);
            /* WALPHAC: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCCAVRA_REG__, u64GDCCAVRA_REG__Var[eGDC]);
            break;

        case GDC_SEG_WIN_D:
            vSetGDCCAVRA_WALPHAD(eGDC, u8Alpha);
            /* WALPHAD: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCCAVRA_REG__, u64GDCCAVRA_REG__Var[eGDC]);
            break;

        case GDC_SEG_WIN_E:
            vSetGDCCAVRB_WALPHAE(eGDC, u8Alpha);
            /* ALPHAE: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCAVRB_REG__, u32GDCCAVRB_REG__Var[eGDC]);
            break;
        default:
            i32Res = C_FAILED;
            break;
    }
    /* Report the result */
    return i32Res;
}


/****************************************************************************/
int32_t i32GDC_GetCommonAlpha(gdc_ch_e eGDC, gdc_seg_e eEntity, uint8_t* pu8Alpha)
{
    int32_t i32Res = C_SUCCESS;
    
    /* check pointer: */
    if (0x00 != pu8Alpha)
    {
        switch( eEntity )
        {
            case GDC_SEG_LAYER_A:
                *pu8Alpha= (uint8_t) biGetGDCCAVRA_ALPHAA(eGDC);
                break;

            case GDC_SEG_LAYER_B:
                *pu8Alpha= (uint8_t) biGetGDCCAVRA_ALPHAB(eGDC);
                break;

            case GDC_SEG_LAYER_C:
                *pu8Alpha= (uint8_t) biGetGDCCAVRA_ALPHAC(eGDC);
                break;

            case GDC_SEG_LAYER_D:
                *pu8Alpha= (uint8_t) biGetGDCCAVRA_ALPHAD(eGDC);
                break;

            case GDC_SEG_LAYER_E:
                *pu8Alpha= (uint8_t) biGetGDCCAVRB_ALPHAE(eGDC);
                break;

            case GDC_SEG_WIN_A:
                *pu8Alpha = (uint8_t) biGetGDCCAVRA_WALPHAA(eGDC);
                break;

            case GDC_SEG_WIN_B:
                *pu8Alpha = (uint8_t) biGetGDCCAVRA_WALPHAB(eGDC);
                break;

            case GDC_SEG_WIN_C:
                *pu8Alpha = (uint8_t) biGetGDCCAVRA_WALPHAC(eGDC);
                break;

            case GDC_SEG_WIN_D:
                *pu8Alpha = (uint8_t) biGetGDCCAVRA_WALPHAD(eGDC);
                break;

            case GDC_SEG_WIN_E:
                *pu8Alpha = (uint8_t) biGetGDCCAVRB_WALPHAE(eGDC);
                break;

            default:
                /* Unsupported entity */
                i32Res = C_FAILED;
                break;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }
    return i32Res;
}


/****************************************************************************/
int32_t i32GDC_FrameBuffConfig(gdc_ch_e eGDC, gdc_layer_e eLayer, gdc_fbcfg_st* pstBuffCfg)
{
    int32_t i32Res = C_SUCCESS;
    
    /* check pointer: */
    if (0x00 != pstBuffCfg)
    {
        switch( eLayer )
        {
            case GDC_LAYER_A:
                /*
                 *  Select default or secondary buffer, i.e. GDCLARA0 or
                 *  GDCLARA1 and write the 32 LSbits of the buffer start
                 *  address
                 */
                if( GDC_BUFF_DEFAULT == pstBuffCfg->eBuff )
                {
                    vSetGDCLARA0(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARA0_REG__, u32GDCLARA0_REG__Var[eGDC]);
                }
                else
                {
                    vSetGDCLARA1(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARA1_REG__, u32GDCLARA1_REG__Var[eGDC]);
                }
                vSetGDCMWRA_MWR(eGDC, pstBuffCfg->u16Width);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRA_REG__, u32GDCMWRA_REG__Var[eGDC]);
                break;
                
            case GDC_LAYER_B:
                /*
                 *  Select default or secondary buffer, i.e. GDCSARB0 or
                 *  GDCSARB1 and write the 32 LSbits of the buffer start
                 *  address
                 */
                if( GDC_BUFF_DEFAULT == pstBuffCfg->eBuff )
                {
                    vSetGDCLARB0(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARB0_REG__, u32GDCLARB0_REG__Var[eGDC]);
                }
                else
                {
                    vSetGDCLARB1(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARB1_REG__, u32GDCLARB1_REG__Var[eGDC]);
                }
                vSetGDCMWRB_MWR(eGDC, pstBuffCfg->u16Width);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRB_REG__, u32GDCMWRB_REG__Var[eGDC]);
                break;

            case GDC_LAYER_C:
                /*
                 *  Select default or secondary buffer, i.e. GDCSARC0 or
                 *  GDCSARC1 and write the 32 LSbits of the buffer start
                 *  address
                 */
                if( GDC_BUFF_DEFAULT == pstBuffCfg->eBuff )
                {
                    vSetGDCLARC0(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARC0_REG__, u32GDCLARC0_REG__Var[eGDC]);
                }
                else
                {
                    vSetGDCLARC1(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARC1_REG__, u32GDCLARC1_REG__Var[eGDC]);
                }
                vSetGDCMWRC_MWR(eGDC, pstBuffCfg->u16Width);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRC_REG__, u32GDCMWRC_REG__Var[eGDC]);
                break;

            case GDC_LAYER_D:
                /*
                 *  Select default or secondary buffer, i.e. GDCSARD0 or
                 *  GDCSARD1 and write the 32 LSbits of the buffer start
                 *  address
                 */
                if( GDC_BUFF_DEFAULT == pstBuffCfg->eBuff )
                {
                    vSetGDCLARD0(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARD0_REG__, u32GDCLARD0_REG__Var[eGDC]);
                }
                else
                {
                    vSetGDCLARD1(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARD1_REG__, u32GDCLARD1_REG__Var[eGDC]);
                }
                vSetGDCMWRD_MWR(eGDC, pstBuffCfg->u16Width);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRD_REG__, u32GDCMWRD_REG__Var[eGDC]);
                break;

            case GDC_LAYER_E:
                /*
                 *  Select default or secondary buffer, i.e. GDCSARE0 or
                 *  GDCSARE1 and write the 32 LSbits of the buffer start
                 *  address
                 */
                if( GDC_BUFF_DEFAULT == pstBuffCfg->eBuff )
                {
                    vSetGDCLARE0(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARE0_REG__, u32GDCLARE0_REG__Var[eGDC]);
                }
                else
                {
                    vSetGDCLARE1(eGDC, pstBuffCfg->u32Addr);
                    /* Copy register data to shadow register: */
                    UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARE1_REG__, u32GDCLARE1_REG__Var[eGDC]);
                }
                vSetGDCMWRE_MWR(eGDC, pstBuffCfg->u16Width);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRE_REG__, u32GDCMWRE_REG__Var[eGDC]);
                break;

            default:
                /* Unsupported Layer */
                i32Res = C_FAILED;
                break;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }
    return i32Res;
}


/****************************************************************************/
gdc_frmbuff_e eGDC_GetActiveFrameBuff(gdc_ch_e eGDC)
{
    return ((gdc_frmbuff_e) biGetGDCDCR_FBACT(eGDC) );
}


/****************************************************************************/
void vGDC_SetMemWidth(gdc_ch_e eGDC, gdc_layer_e eLayer, uint16_t u16Width)
{
    switch( eLayer )
    {
        case GDC_LAYER_A:
            vSetGDCMWRA_MWR(eGDC, u16Width);
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRA_REG__, u32GDCMWRA_REG__Var[eGDC]);
            break;

        case GDC_LAYER_B:
            vSetGDCMWRB_MWR(eGDC, u16Width);
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRB_REG__, u32GDCMWRB_REG__Var[eGDC]);
            break;

        case GDC_LAYER_C:
            vSetGDCMWRC_MWR(eGDC, u16Width);
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRC_REG__, u32GDCMWRC_REG__Var[eGDC]);
            break;

        case GDC_LAYER_D:
            vSetGDCMWRD_MWR(eGDC, u16Width);
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRD_REG__, u32GDCMWRD_REG__Var[eGDC]);
            break;

        case GDC_LAYER_E:
            vSetGDCMWRE_MWR(eGDC, u16Width);
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCMWRE_REG__, u32GDCMWRE_REG__Var[eGDC]);
            break;

        default:
            break;
    }
}


/****************************************************************************/
int32_t i32GDC_SetLayerStartAddr(gdc_ch_e eGDC,  gdc_layer_e eLayer,
                                 gdc_frmbuff_e eBuff, uint32_t u32Addr)
{
    int32_t i32Res = C_SUCCESS;

    /* modify Bits "SAR" in GDCLARxx register with masking: */
    u32Addr &= GDC_SARXN_SAR_MASK;

    switch( eLayer )
    {
        case GDC_LAYER_A:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARA0(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARA0_REG__, u32GDCLARA0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARA1(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARA1_REG__, u32GDCLARA1_REG__Var[eGDC]);
            }
            break;

        case GDC_LAYER_B:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARB0(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARB0_REG__, u32GDCLARB0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARB1(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARB1_REG__, u32GDCLARB1_REG__Var[eGDC]);
            }
            break;

        case GDC_LAYER_C:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARC0(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARC0_REG__, u32GDCLARC0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARC1(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARC1_REG__, u32GDCLARC1_REG__Var[eGDC]);
            }
            break;

        case GDC_LAYER_D:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARD0(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARD0_REG__, u32GDCLARD0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARD1(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARD1_REG__, u32GDCLARD1_REG__Var[eGDC]);
            }
            break;

        case GDC_LAYER_E:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARE0(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARE0_REG__, u32GDCLARE0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARE1(eGDC, u32Addr);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARE1_REG__, u32GDCLARE1_REG__Var[eGDC]);
            }
            break;

        default:
            /* Unsupported Layer */
            i32Res = C_FAILED;
            break;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32GDC_SetScrollVal(gdc_ch_e eGDC, gdc_layer_e eLayer,
                            gdc_frmbuff_e eBuff, uint8_t u8ScrVal)
{
    int32_t i32Res = C_SUCCESS;

    switch( eLayer )
    {
        case GDC_LAYER_A:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARA0_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARA0_REG__, u32GDCLARA0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARA1_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARA1_REG__, u32GDCLARA1_REG__Var[eGDC]);
            }
            break;

        case GDC_LAYER_B:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARB0_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARB0_REG__, u32GDCLARB0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARB1_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARB1_REG__, u32GDCLARB1_REG__Var[eGDC]);
            }
            break;

        case GDC_LAYER_C:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARC0_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARC0_REG__, u32GDCLARC0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARC1_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARC1_REG__, u32GDCLARC1_REG__Var[eGDC]);
            }
            break;

        case GDC_LAYER_D:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARD0_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARD0_REG__, u32GDCLARD0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARD1_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARD1_REG__, u32GDCLARD1_REG__Var[eGDC]);
            }
            break;

        case GDC_LAYER_E:
            if( GDC_BUFF_DEFAULT == eBuff )
            {
                vSetGDCLARE0_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARE0_REG__, u32GDCLARE0_REG__Var[eGDC]);
            }
            else
            {
                vSetGDCLARE1_SSCROLL(eGDC, u8ScrVal);
                /* Copy register data to shadow register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCLARE1_REG__, u32GDCLARE1_REG__Var[eGDC]);
            }
            break;

        default:
            /* Unsupported Layer */
            i32Res = C_FAILED;
            break;
    }

    return i32Res;
}


/****************************************************************************/
void vGDC_SetStartAddrCapture(gdc_ch_e eGDC, gdc_cbuff_e eBuff, uint32_t u32Addr)
{
    switch( eBuff )
    {
        case GDC_CBUFF1:
            vSetGDCCBAR0(eGDC, (u32Addr & GDC_CBARX_MASK));
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCBAR0_REG__, u32GDCCBAR0_REG__Var[eGDC]);
            break;

        case GDC_CBUFF2:
            vSetGDCCBAR1(eGDC, (u32Addr & GDC_CBARX_MASK));
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCBAR1_REG__, u32GDCCBAR1_REG__Var[eGDC]);
            break;

        case GDC_CBUFF3:
            vSetGDCCBAR2(eGDC, (u32Addr & GDC_CBARX_MASK));
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCCBAR2_REG__, u32GDCCBAR2_REG__Var[eGDC]);
            break;

        default:
            break;
    }
}


/****************************************************************************/
void vGDC_InitCorrClut(gdc_ch_e eGDC, gdc_clut_e eClut, const uint8_t* pu8Data)
{

    uint32_t u32Cnt;
    
    /* check pointer: */
    if (0x00 != pu8Data)
    {
        switch (eClut)
        {
            case  GDC_CLUT_RED:
                for(u32Cnt = 0; u32Cnt < GDC_CLUTSIZE_CORR; u32Cnt++)
                {
                    vSetGDCCCLUTR(eGDC, u32Cnt, pu8Data[u32Cnt]);
                }
                break;
            case  GDC_CLUT_GREEN:
                for(u32Cnt = 0; u32Cnt < GDC_CLUTSIZE_CORR; u32Cnt++)
                {
                    vSetGDCCCLUTG(eGDC, u32Cnt, pu8Data[u32Cnt]);
                }
                break;
            case  GDC_CLUT_BLUE:
                for(u32Cnt = 0; u32Cnt < GDC_CLUTSIZE_CORR; u32Cnt++)
                {
                    vSetGDCCCLUTB(eGDC, u32Cnt, pu8Data[u32Cnt]);
                }
                break;
            default:
                break;
        }
    }

}


/****************************************************************************/
void vGDC_SetSelectCorrCompVal(gdc_ch_e eGDC,  gdc_cmp_e eSelection, uint32_t u32CorrCompVal)
{
    switch( eSelection )
    {
        /* Data from register: GDCSCVRA_REG__: */
        case GDC_CCVAL0:  
            vSetGDCSCVRA_CCV0(eGDC, u32CorrCompVal);
            /* CCV0: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCSCVRA_REG__, u64GDCSCVRA_REG__Var[eGDC]);
            break;
            
        case GDC_CCVAL1:
            vSetGDCSCVRA_CCV1(eGDC, u32CorrCompVal);
            /* CCV1: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCSCVRA_REG__, u64GDCSCVRA_REG__Var[eGDC]);
            break;
            
        /* Data from register: GDCSCVRB_REG__*/
        case GDC_CCVAL2:
            vSetGDCSCVRB_CCV2(eGDC, u32CorrCompVal);
            /* CCV2: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCSCVRB_REG__, u64GDCSCVRB_REG__Var[eGDC]);
            break;
            
        case GDC_CCVAL3:
            vSetGDCSCVRB_CCV3(eGDC, u32CorrCompVal);
            /* CCV3: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCSCVRB_REG__, u64GDCSCVRB_REG__Var[eGDC]);
            break;
            
        /* Data from register: GDCSCVRC_REG__*/
        case GDC_CCVAL4:
            vSetGDCSCVRC_CCV4(eGDC, u32CorrCompVal);
            /* CCV4: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCSCVRC_REG__, u64GDCSCVRC_REG__Var[eGDC]);
            break;
            
        case GDC_CCVAL5:
            vSetGDCSCVRC_CCV5(eGDC, u32CorrCompVal);
            /* CCV5: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCSCVRC_REG__, u64GDCSCVRC_REG__Var[eGDC]);
            break;
            
        /* Data from register: GDCSCVRD_REG__*/            
        case GDC_CCVAL6:
            vSetGDCSCVRD_CCV6(eGDC, u32CorrCompVal);
            /* CCV6: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCSCVRD_REG__, u64GDCSCVRD_REG__Var[eGDC]);
            break;
            
        case GDC_CCVAL7:
            vSetGDCSCVRD_CCV7(eGDC, u32CorrCompVal);
            /* CCV7: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCSCVRD_REG__, u64GDCSCVRD_REG__Var[eGDC]);
            break;
            
        default:
            break;
    }
    return;
}


/****************************************************************************/
void  vGDC_ActivateCorrCompVal(gdc_ch_e eGDC, gdc_cmp_e eSelection, gdc_active_e eActive)
{
    switch( eSelection )
    {
        /* Data from register: GDCSCVRA_REG__: */
        case GDC_CCVAL0:  
            vSetGDCSCVRA_ACT0(eGDC, eActive);
            /* CCVAL0: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCSCVRA_REG__, u64GDCSCVRA_REG__Var[eGDC]);
            break;
            
        case GDC_CCVAL1:
            vSetGDCSCVRA_ACT1(eGDC, eActive);
            /* CCVAL1: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCSCVRA_REG__, u64GDCSCVRA_REG__Var[eGDC]);
            break;
            
        /* Data from register: GDCSCVRB_REG__*/
        case GDC_CCVAL2:
            vSetGDCSCVRB_ACT2(eGDC, eActive);
            /* CCVAL2: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCSCVRB_REG__, u64GDCSCVRB_REG__Var[eGDC]);
            break;
            
        case GDC_CCVAL3:
            vSetGDCSCVRB_ACT3(eGDC, eActive);
            /* CCVAL3: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCSCVRB_REG__, u64GDCSCVRB_REG__Var[eGDC]);
            break;
            
        /* Data from register: GDCSCVRC_REG__*/
        case GDC_CCVAL4:
            vSetGDCSCVRC_ACT4(eGDC, eActive);
            /* CCVAL4: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCSCVRC_REG__, u64GDCSCVRC_REG__Var[eGDC]);
            break;
            
        case GDC_CCVAL5:
            vSetGDCSCVRC_ACT5(eGDC, eActive);
            /* CCV5: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCSCVRC_REG__, u64GDCSCVRC_REG__Var[eGDC]);
            break;
            
        /* Data from register: GDCSCVRD_REG__*/
        case GDC_CCVAL6:
            vSetGDCSCVRD_ACT6(eGDC, eActive);
            /* CCVAL5: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCSCVRD_REG__, u64GDCSCVRD_REG__Var[eGDC]);
            break;
            
        case GDC_CCVAL7:
            vSetGDCSCVRD_ACT7(eGDC, eActive);
            /* CCVAL6: belongs to high word of register: */
            UPDATE_REGISTER_HIGH_WORD(eGDC, GDCSCVRD_REG__, u64GDCSCVRD_REG__Var[eGDC]);
            break;

        default:
            break;
    }
}


/****************************************************************************/
void vGDC_EnableSelectiveCorr(gdc_ch_e eGDC, gdc_en_e eEn, gdc_ccmode_e eMode)
{
    vSetGDCDCR_SCCM(eGDC, eMode);
    vSetGDCDCR_SCCEN(eGDC, eEn);
    /* SCCM and SCCEN: belong to high word of register: */
    /* GDCDCR register should be updated special: */  
    vUpdateDCR_HighWord_Special(eGDC);
}


/****************************************************************************/
int32_t i32GDC_SetDisplayStart(gdc_ch_e eGDC, uint16_t u16HStart, uint16_t u16VStart)
{
    uint32_t u32Val;
    int32_t i32Res = C_SUCCESS;
    
    if ( (u16HStart<GDC_DISP_HSTART_MIN)  || (u16HStart>GDC_DISP_HSTART_MAX) || 
          (u16VStart<GDC_DISP_VSTART_MIN) || (u16VStart>GDC_DISP_VSTART_MAX) )
    {
        i32Res = C_FAILED;
    }
    else
    {
        /* Compose the entire register value */
        u32Val = (((uint32_t) (u16HStart & GDC_11_BIT_MASK)) << 16) | (u16VStart & GDC_10_BIT_MASK);

        /* Set */
        vSetGDCDSR(eGDC, u32Val);
        /* DVS and DHS : belong to low word of register: */
        UPDATE_REGISTER_LOW_WORD(eGDC, GDCDSR_REG__, u32GDCDSR_REG__Var[eGDC]);
    }
    return i32Res;
}


/****************************************************************************/
int32_t i32GDC_SetDisplaySize(gdc_ch_e eGDC, uint16_t u16Width, uint16_t u16Height)
{
    uint32_t u32Val;
    int32_t i32Res = C_SUCCESS;
    
    if ( (u16Width<GDC_DISP_WIDTH_MIN)   || (u16Width>GDC_DISP_WIDTH_MAX) || 
          (u16Height<GDC_DISP_HEIGHT_MIN) || (u16Height>GDC_DISP_HEIGHT_MAX) )
    {
        i32Res = C_FAILED;
    }
    else
    {
        /* Compose the entire register value */
        u32Val = (((uint32_t) (u16Width & GDC_12_BIT_MASK)) << 16) | (u16Height & GDC_11_BIT_MASK);

        /* Set */
        vSetGDCDIMR(eGDC, u32Val);
        /* DHEIGHT and DWIDTH : belong to low word of register: */
        UPDATE_REGISTER_LOW_WORD(eGDC, GDCDIMR_REG__, u32GDCDIMR_REG__Var[eGDC]);
    }
    return i32Res;
}


/****************************************************************************/
void vGDC_WindowEnable(gdc_ch_e eGDC, gdc_win_e eWindow, gdc_en_e eEn)
{
    /* Single window selection */
    switch( eWindow )
    {
         case GDC_WIN_A:
             vSetGDCDCR_WAEN(eGDC, eEn);
             /* WAEN: belongs to low word of register: */
             UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
             break;

         case GDC_WIN_B:
             vSetGDCDCR_WBEN(eGDC, eEn);
             /* WBEN: belongs to low word of register: */
             UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
             break;

         case GDC_WIN_C:
             vSetGDCDCR_WCEN(eGDC, eEn);
             /* WCEN: belongs to low word of register: */
             UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
             break;

         case GDC_WIN_D:
             vSetGDCDCR_WDEN(eGDC, eEn);
             /* WDEN: belongs to low word of register: */
             UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
             break;

         case GDC_WIN_E:
             vSetGDCDCR_WEEN(eGDC, eEn);
             /* WEEN: belongs to high word of register: */
             /* GDCDCR register should be updated special: */
             vUpdateDCR_HighWord_Special(eGDC);
             break;
             
         default:
             break;
    }
}


/****************************************************************************/
int32_t i32GDC_SetWindowSize(gdc_ch_e eGDC, gdc_win_e eWindow,
                             uint16_t u16Width, uint16_t u16Height)
{
    int32_t i32Res = C_SUCCESS;
    uint32_t u32Val;

    if( (u16Width & GDC_12_BIT_MASK) < GDC_WIMR_WIDHT_MIN_VAL )
    {
        i32Res = C_FAILED;
    }
    else
    {
        /* Compose the entire register value */
        u32Val = (((uint32_t) (u16Width & GDC_12_BIT_MASK)) << 16) | (u16Height & GDC_11_BIT_MASK);

        /* Set */
        switch( eWindow )
        {
            case GDC_WIN_A:
                vSetGDCWIMRA(eGDC, u32Val);
                /* WHEIGHT & WWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCWIMRA_REG__, u32GDCWIMRA_REG__Var[eGDC]);
                break;

            case GDC_WIN_B:
                vSetGDCWIMRB(eGDC, u32Val);
                /* WHEIGHT & WWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCWIMRB_REG__, u32GDCWIMRB_REG__Var[eGDC]);
                break;

            case GDC_WIN_C:
                vSetGDCWIMRC(eGDC, u32Val);
                /* WHEIGHT & WWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCWIMRC_REG__, u32GDCWIMRC_REG__Var[eGDC]);
                break;

            case GDC_WIN_D:
                vSetGDCWIMRD(eGDC, u32Val);
                /* WHEIGHT & WWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCWIMRD_REG__, u32GDCWIMRD_REG__Var[eGDC]);
                break;

            case GDC_WIN_E:
                vSetGDCWIMRE(eGDC, u32Val);
                /* WHEIGHT & WWIDTH: belong to low word of register: */
                UPDATE_REGISTER_LOW_WORD(eGDC, GDCWIMRE_REG__, u32GDCWIMRE_REG__Var[eGDC]);
                break;
                
            default:
                i32Res = C_FAILED;
                break;
        }
    }
    return i32Res;
}


/****************************************************************************/
void vGDC_SetWindowStartPos(gdc_ch_e eGDC, gdc_win_e eWindow, uint16_t u16HStart, uint16_t u16VStart)

{
    uint32_t u32Val;

    /* Compose the entire register value */
    u32Val = (((uint32_t) (u16HStart & GDC_11_BIT_MASK)) << 16) | (u16VStart & GDC_10_BIT_MASK);
    switch( eWindow )
    {
        case GDC_WIN_A:
            vSetGDCWSRA(eGDC, u32Val);
            /* WVS & WHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWSRA_REG__, u32GDCWSRA_REG__Var[eGDC]);
            break;

        case GDC_WIN_B:
            vSetGDCWSRB(eGDC, u32Val);
            /* WVS & WHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWSRB_REG__, u32GDCWSRB_REG__Var[eGDC]);
            break;

        case GDC_WIN_C:
            vSetGDCWSRC(eGDC, u32Val);
            /* WVS & WHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWSRC_REG__, u32GDCWSRC_REG__Var[eGDC]);
            break;

        case GDC_WIN_D:
            vSetGDCWSRD(eGDC, u32Val);
            /* WVS & WHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWSRD_REG__, u32GDCWSRD_REG__Var[eGDC]);
            break;

        case GDC_WIN_E:
            vSetGDCWSRE(eGDC, u32Val);
            /* WVS & WHS: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWSRE_REG__, u32GDCWSRE_REG__Var[eGDC]);
            break;
            
        default:
            break;
    }
}


/****************************************************************************/
int32_t i32GDC_SetWindowStartAddr(gdc_ch_e eGDC, gdc_win_e eWindow, uint32_t u32Addr)
{
    int32_t i32Res = C_SUCCESS;

    /* Mask out the zero wired bits */
    u32Addr &= GDC_WARXN_WAR_MASK;

    /* Window selection */
    switch( eWindow )
    {
        case GDC_WIN_A:
            vSetGDCWARA(eGDC, u32Addr);
            /* WAR: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWARA_REG__, u32GDCWARA_REG__Var[eGDC]);
            break;

        case GDC_WIN_B:
            vSetGDCWARB(eGDC, u32Addr);
            /* WAR: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWARB_REG__, u32GDCWARB_REG__Var[eGDC]);
            break;

        case GDC_WIN_C:
            vSetGDCWARC(eGDC, u32Addr);
            /* WAR: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWARC_REG__, u32GDCWARC_REG__Var[eGDC]);
            break;

        case GDC_WIN_D:
            vSetGDCWARD(eGDC, u32Addr);
            /* WAR: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWARD_REG__, u32GDCWARD_REG__Var[eGDC]);
            break;

        case GDC_WIN_E:
            vSetGDCWARE(eGDC, u32Addr);
            /* WAR: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCWARE_REG__, u32GDCWARE_REG__Var[eGDC]);
            break;

        default:
            /* Unsupported window */
            i32Res = C_FAILED;
            break;
    }
    /* Result reporting */
    return i32Res;
}


/****************************************************************************/
void vGDC_SyncConfig(gdc_ch_e eGDC, gdc_sync_st* pstSyncCfg)
{
#ifdef HW_UPDATE_BUG_FIXED
    gdc_reg_update_mode_e eLastUpdateMode;
#endif
    if (0x00 != pstSyncCfg)
    {
        vSetGDCDCR_CSYNC(eGDC, pstSyncCfg->eSyncType);
        vSetGDCDCR_PVSYNC(eGDC, pstSyncCfg->eVSyncPol);
        vSetGDCDCR_PHSYNC(eGDC, pstSyncCfg->eHSyncPol);
        
        vSetGDCHSR_HSPWR(eGDC, pstSyncCfg->u8HsyncWdth);
        vSetGDCHSR_HCR(eGDC, pstSyncCfg->u16HLineLen);

        vSetGDCVSR_VSPWR(eGDC, pstSyncCfg->u8VsyncWdth);
        vSetGDCVSR_VCR(eGDC, pstSyncCfg->u16VFrameLen);
        
#ifdef HW_UPDATE_BUG_FIXED
        /* get last actual update mode for later restore:*/
        eLastUpdateMode = eGetShadowRegUpdateStatus(eGDC);

        /* Disable Update Mode if it was not disabled: */
        if (GDC_NO_UPDATE_BY_VSYNC != eLastUpdateMode)
        {
            vGDC_SetShadowRegUpdateMode(eGDC, GDC_NO_UPDATE_BY_VSYNC);
        }
#endif
        /* All modified bit fields belong to Low Word of registers,
         * so Copy register data to shadow register: */
        UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
        UPDATE_REGISTER_LOW_WORD(eGDC, GDCHSR_REG__, u32GDCHSR_REG__Var[eGDC]);
        UPDATE_REGISTER_LOW_WORD(eGDC, GDCVSR_REG__, u32GDCVSR_REG__Var[eGDC]);
        
#ifdef HW_UPDATE_BUG_FIXED
        /* restore Update Mode if necessary */
        if (GDC_NO_UPDATE_BY_VSYNC != eLastUpdateMode)
        {
            vGDC_SetShadowRegUpdateMode(eGDC, eLastUpdateMode);
        }
#endif
    }
}

/****************************************************************************/
void vGDC_SetSyncDir(gdc_ch_e eGDC, gdc_dir_e eDir)
{
    vSetGDCDCR_EXTSYNC(eGDC, eDir);
    /* EXTSYNC: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SelectCompSync(gdc_ch_e eGDC, gdc_csync_e eSync)
{
    vSetGDCDCR_CSYNC(eGDC, eSync);
    /* CSYNC: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SetPolVSync(gdc_ch_e eGDC, gdc_pol_e eMode)
{
    vSetGDCDCR_PVSYNC(eGDC, eMode);
    /* PVSYNC belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SetPolHSync(gdc_ch_e eGDC, gdc_pol_e eMode)
{
    vSetGDCDCR_PHSYNC(eGDC, eMode);
    /* PHSYNC belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SetPolHDisp(gdc_ch_e eGDC, gdc_pol_e eMode)
{
    vSetGDCDCR_PHDISP(eGDC, eMode);
    /* PHDISP: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SetHSync(gdc_ch_e eGDC, uint8_t u8PulseWidth, uint16_t u16LineLen)
{
    vSetGDCHSR_HSPWR(eGDC, u8PulseWidth);
    vSetGDCHSR_HCR(eGDC, u16LineLen);
    /* Copy register data to shadow register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCHSR_REG__, u32GDCHSR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SetVSync(gdc_ch_e eGDC, uint8_t u8PulseWidth, uint16_t u16VFrameLen)
{
    vSetGDCVSR_VSPWR(eGDC, u8PulseWidth);
    vSetGDCVSR_VCR(eGDC, u16VFrameLen);
    /* Copy register data to shadow register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCVSR_REG__, u32GDCVSR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_IrqConfig(gdc_ch_e eGDC, gdc_irqcgf_st* pstCfg)
{
    if (0x00 != pstCfg)
    {
        vSetGDCINTR_APCMSK(eGDC, pstCfg->eAPCIrqEn);
        vSetGDCINTR_LINE(eGDC, pstCfg->u16LineNr);
        vSetGDCINTR_HSYNCMSK(eGDC, pstCfg->eHSyncIrqEn);
        vSetGDCINTR_VSYNCMSK(eGDC, pstCfg->eVSyncIrqEn);

        vSetGDCINTR_IFURMSK(eGDC, pstCfg->eIfurIrqEn);
        vSetGDCINTR_OFURMSK(eGDC, pstCfg->eOfurIrqEn);
    }
}


/****************************************************************************/
void vGDC_SetIrqMaskAPC(gdc_ch_e eGDC, gdc_en_e eEn)
{
    vSetGDCINTR_APCMSK(eGDC, eEn);
}


/****************************************************************************/
void vGDC_SetHsyncIrqLine(gdc_ch_e eGDC, uint16_t u16LineNr)
{
    vSetGDCINTR_LINE(eGDC, u16LineNr);
}


/****************************************************************************/
void vGDC_SetIrqMaskFifoIn(gdc_ch_e eGDC, gdc_en_e eEn)
{
    vSetGDCINTR_IFURMSK(eGDC, eEn);
}


/****************************************************************************/
void vGDC_SetIrqMaskFifoOut(gdc_ch_e eGDC, gdc_en_e eEn)
{
    vSetGDCINTR_OFURMSK(eGDC, eEn);
}


/****************************************************************************/
void vGDC_SetIrqMaskVSync(gdc_ch_e eGDC, gdc_en_e eEn)
{
    vSetGDCINTR_VSYNCMSK(eGDC, eEn);
}


/****************************************************************************/
void vGDC_SetIrqMaskHSync(gdc_ch_e eGDC, gdc_en_e eEn)
{
    vSetGDCINTR_HSYNCMSK(eGDC, eEn);
}

/****************************************************************************/
gdc_irqact_e eGDC_IsIrqHSync(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = (int32_t)biGetGDCINTR_HSYNCINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_HSYNCINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}


/****************************************************************************/
gdc_irqact_e eGDC_IsIrqVSync(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = (int32_t)biGetGDCINTR_VSYNCINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_VSYNCINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}

/****************************************************************************/
gdc_irqact_e eGDC_IsIrqFifoIn(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = (int32_t)biGetGDCINTR_IFURINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_IFURINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}


/****************************************************************************/
gdc_irqact_e eGDC_IsIrqFifoOut(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = (int32_t)biGetGDCINTR_OFURINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_OFURINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}


/****************************************************************************/
gdc_irqact_e eGDC_IsIrqAPC(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = (int32_t)biGetGDCINTR_APCINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_APCINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}


/****************************************************************************/
void vGDC_PnlGppOutEnable(gdc_gpp_e ePin, gdc_en_e eEn)
{
    uint32_t u32PinStat;
    uint32_t u32Tmp;

    /* API valid only for GDC0 : */
    u32PinStat = u32GetGDCPTCR(GDC0);

    u32Tmp = 0x1;
    u32Tmp <<= (uint32_t) ePin;

    if( 1 == eEn )
    {
       u32PinStat |= u32Tmp;
    }
    else
    {
        u32PinStat &= ~u32Tmp;
    }

    vSetGDCPTCR(GDC0, u32PinStat);
    /* Copy register data to shadow register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}

/****************************************************************************/
void vGDC_SetPnlPositiveSyncSelect(gdc_ppsync_e eSync)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_PPSYNC(GDC0, eSync);
    /* PPSYNC: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}

/****************************************************************************/
bool_t boGDC_IsPnlRSPowerUpFinished(void)
{
    bool_t boRes = C_FALSE;
    
    /* API valid only for GDC0 : */
    if( biGetGDCPTCR_RSPUP(GDC0) )
    {
        boRes = C_TRUE;
    }
    return boRes;
}

/****************************************************************************/
bool_t boGDC_IsPnlRSReady(void)
{
    bool_t boRes = C_FALSE;
    
    /* API valid only for GDC0 : */
    if( biGetGDCPTCR_RSDRDY(GDC0) )
    {
        boRes = C_TRUE;
    }
    return boRes;
}

/****************************************************************************/
void vGDC_SetPnlRSDSEnable(gdc_rsdsen_e eOutput)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_RSDSEN(GDC0, eOutput);
    /* RSDSEN: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}

/****************************************************************************/
void vGDC_SetPnlSyncModeEnable(gdc_en_e eEn)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_PSMEN(GDC0, eEn);
    /* PSMEN: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}

/****************************************************************************/
void vGDC_SetPnlRSDSOutputCurrentMode(gdc_rsdsoutmode_e eOutMode)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_OCMD(GDC0, eOutMode);
    /* OCMD: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}

/****************************************************************************/
void vGDC_SetPnlRSDSPreEmphasisMode(gdc_rsdspreemp_e ePreEmp)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_PEMD(GDC0, ePreEmp);
    /* PEMD: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}

/****************************************************************************/
void vGDC_SetPnlRSDSHighImpedanceEnable(gdc_en_e eEn)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_HIZEN(GDC0, eEn);
    /* HIZEN: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}

/****************************************************************************/
bool_t boGDC_IsPnlInputSync(void)
{
    bool_t boRes = C_FALSE;

    /* API valid only for GDC0 : */
    if( biGetGDCPTCR_PSYNC(GDC0) )
    {
        boRes = C_TRUE;
    }
    return boRes;
}
/****************************************************************************/
bool_t boGDC_IsPnlTimingControlInterfaceEnabled(void)
{
    bool_t boRes = C_FALSE;

    /* API valid only for GDC0 : */
    if( biGetGDCPTCR_PTCEN(GDC0) )
    {
        boRes = C_TRUE;
    }
    return boRes;
}

/****************************************************************************/
void vGDC_SetAlignData(gdc_ddal_e eAllign)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_DDAL(GDC0, eAllign);
    /* DDAL: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}


/****************************************************************************/
void vGDC_SetPnlAlignClock(gdc_dcal_e eEdge)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_DCAL(GDC0, eEdge);
    /* DCAL: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}


/****************************************************************************/
void vGDC_PnlAlterEnable(gdc_en_e eEn)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_ALT(GDC0, eEn);
    /* ALT: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}


/****************************************************************************/
void vGDC_PnlEvenDataInvEnable(gdc_en_e eEn)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_EINVEN(GDC0, eEn);
    /* EINVEN: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}


/****************************************************************************/
void vGDC_PnlEvenRgbOutEnable(gdc_en_e eEn)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_ERGBEN(GDC0, eEn);
    /* ERGBEN: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}


/****************************************************************************/
void vGDC_PnlOddDataInvEnable(gdc_en_e eEn)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_OINVEN(GDC0, eEn);
    /* OINVEN: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}


/****************************************************************************/
void vGDC_PnlOddRgbOutEnable(gdc_en_e eEn)
{
    /* API valid only for GDC0 : */
    vSetGDCPTCR_ORGBEN(GDC0, eEn);
    /* ORGBEN: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(GDC0, GDCPTCR_REG__, u32GDCPTCR_REG__Var[GDC0]);
}

/****************************************************************************/
int32_t i32GDC_PnlSyncMode(uint16_t u16PnlSyncModeDelay, uint8_t u8PnlSyncDataDelay)
{
    int32_t iRes = C_SUCCESS;

    /* API valid only for GDC0 : */
    /* parameter range check: */
    if ( (u16PnlSyncModeDelay<7) || (u16PnlSyncModeDelay>2047) )
    {
        iRes = C_FAILED; 
    }
    else
    {
        if (u8PnlSyncDataDelay>15) 
        {
            iRes = C_FAILED; 
        }
        else
        {
            vSetGDCPSMR_PSDEL(GDC0, u16PnlSyncModeDelay);
            vSetGDCPSMR_PSDDEL(GDC0, u8PnlSyncDataDelay);
            
            /* PSDEL & PSDDEL: belong to low word of register: */
            UPDATE_REGISTER_LOW_WORD(GDC0, GDCPSMR_REG__, u32GDCPSMR_REG__Var[GDC0]);
        }
    }
    return iRes;
}


/****************************************************************************/
void vGDC_APCConfigure(gdc_ch_e eGDC, gdc_apccfg_st* pstCfg)
{
#ifdef HW_UPDATE_BUG_FIXED
    gdc_reg_update_mode_e  eLastUpdateMode;
#endif
    if (0x00 != pstCfg)
    {
        
        /* General */
        vSetAPCCR_APCAUTO(eGDC, pstCfg->eMode);
        vSetAPCCR_APCCHKFR(eGDC, pstCfg->u8Frames);

        /* Compare window definition */
        vSetAPCCWR_CWWIDTH(eGDC, pstCfg->u8WWidth);
        vSetAPCCWR_CWHEIGHT(eGDC, pstCfg->u8WHeight);
        vSetAPCCWR_HCWS(eGDC, pstCfg->u16HStart);
        vSetAPCCWR_VCWS(eGDC, pstCfg->u16VStart);

        /* Expected checksum */
        vSetAPCCSR_EXPCHKSUM(eGDC, pstCfg->u32AutoChkSum);
        
#ifdef HW_UPDATE_BUG_FIXED
        /* get last actual update mode for later restore:*/
         eLastUpdateMode = eGetShadowRegUpdateStatus(eGDC);

         /* Disable Update Mode if it was not disabled: */
         if (GDC_NO_UPDATE_BY_VSYNC != eLastUpdateMode)
         {
             vGDC_SetShadowRegUpdateMode(eGDC, GDC_NO_UPDATE_BY_VSYNC);
         }
#endif

        UPDATE_REGISTER_LOW_WORD (eGDC, APCCR_REG__,  u64APCCR_REG__Var[eGDC]);
        UPDATE_REGISTER_HIGH_WORD(eGDC, APCCSR_REG__, u64APCCSR_REG__Var[eGDC]);
        UPDATE_REGISTER_64BITS   (eGDC, APCCWR_REG__, u64APCCWR_REG__Var[eGDC]);

#ifdef HW_UPDATE_BUG_FIXED
        /* restore Update Mode if necessary */
        if (GDC_NO_UPDATE_BY_VSYNC != eLastUpdateMode)
        {
            vGDC_SetShadowRegUpdateMode(eGDC, eLastUpdateMode);
        }
#endif
    }
}


/****************************************************************************/
void vGDC_APCEnable(gdc_ch_e eGDC, gdc_en_e eEn)
{
    /* Enable/disable */
    vSetAPCCR_APCON(eGDC, eEn);
    /* APCON: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, APCCR_REG__, u64APCCR_REG__Var[eGDC]);
}


/****************************************************************************/
bool_t boGDC_IsAPCError(gdc_ch_e eGDC)
{
    bool_t boRes = C_FALSE;

    if( biGetAPCCR_APCCHKERR(eGDC) )
    {
        boRes = C_TRUE;
    }
    return boRes;
}


/****************************************************************************/
void vGDC_SetAPCCR_PolynomialGen(gdc_ch_e eGDC, uint8_t u8PgValue)
{
    /* Set PG Value for APC : */
    vSetAPCCR_APCPG(eGDC, u8PgValue);
    /* APCPG: belongs to high word of register: */
    UPDATE_REGISTER_HIGH_WORD(eGDC, APCCR_REG__, u64APCCR_REG__Var[eGDC]);
}


/****************************************************************************/
uint32_t u32GDC_GetAPCResult(gdc_ch_e eGDC)
{
    /* Note: CURCHKSUM is a R/C Bit, it means after read CURCHKSUM will be reset!: */
    return (uint32_t) biGetAPCCSR_CURCHKSUM(eGDC);
}


/****************************************************************************/
uint32_t u32GDC_GetAPCPixelVal(gdc_ch_e eGDC, gdc_apcp_e ePix)
{
    uint32_t u32Res;

    if( GDC_CURR_PIXVAL == ePix )
    {
        u32Res = (uint32_t) (u64GetAPCPVR(eGDC));
    }
    else
    {
        u32Res = (uint32_t) (u64GetAPCPVR(eGDC)>> 32);
    }
    return u32Res;
}


/****************************************************************************/
/*+-----------------------------------------------------------------------+*
 *|     START-Extended new APIs                                           |*
 *+-----------------------------------------------------------------------+*/
 
void vGDC_SetGdcWriteProtection(gdc_ch_e eGDC, gdc_write_protect_e eProtection)
{
    /* set protection level for GDC: */
    vSetGDCPROTR_GDCWPL(eGDC, eProtection);
    
    /* GDCWPL: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, GDCPROTR_REG__, u32GDCPROTR_REG__Var[eGDC]);
}


/****************************************************************************/
void vGDC_SetApcWriteProtection(gdc_ch_e eGDC, gdc_write_protect_e eProtection)
{
    /* set protection level for APC: */
    vSetAPCPROTR_APCWPL(eGDC, eProtection);
    
    /* APCWPL: belongs to low word of register: */
    UPDATE_REGISTER_LOW_WORD(eGDC, APCPROTR_REG__, u32APCPROTR_REG__Var[eGDC]);
}


/****************************************************************************/
bool_t boGDC_SetPulseGen(gdc_ch_e eGDC,
                         gdc_pg_gen_id_e   ePGenID,
                         gdc_pg_outsel_e   ePGenOut,
                         gdc_pg_cgsel_e    ePGenClk,
                         gdc_pg_trigger_e  ePGenTrig)
{
    uint8_t  u8shift;
    bool_t   boRes = C_TRUE;
    uint32_t u32NewData, u32RegData, u32RegMask;
    
    /* program
                 ePGenTrig, ePGenClk, ePGenOut
     * +--------+---------+----------+---------+
     * | 1 bit  |  3 bits |  1 bit   | 3 bits  |
     * | resv.  |  TRIGx  |  CGSELx  | OUTSELx |
     * +--------+---------+----------+---------+
     */
    u32NewData =  ((uint32_t)ePGenTrig & GDC_3_BIT_MASK) << 4;
    u32NewData += ((uint32_t)ePGenClk  & GDC_1_BIT_MASK) << 3;
    u32NewData += ((uint32_t)ePGenOut  & GDC_3_BIT_MASK);
    
    u8shift = (ePGenID%4)*8;
    
    u32NewData <<= u8shift;
    u32RegMask = GDC_8_BIT_MASK << u8shift;
    switch( ePGenID )
    {
        case GDC_PULSE_GEN_0:
        case GDC_PULSE_GEN_1:
        case GDC_PULSE_GEN_2:
        case GDC_PULSE_GEN_3:
            /* Register GDCGPCRA should be modfied, first get actual data: */
            u32RegData = u32GetGDCGPCRA(eGDC);
            /* delete related 8 bits: */
            u32RegData &= ~u32RegMask;
            
            /* insert new bits and write it back: */
            u32RegData |= u32NewData;
            vSetGDCGPCRA(eGDC, u32RegData);
            
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCGPCRA_REG__, u32GDCGPCRA_REG__Var[eGDC]);

            break;

        case GDC_PULSE_GEN_4:
        case GDC_PULSE_GEN_5:
        case GDC_PULSE_GEN_6:
        case GDC_PULSE_GEN_7:
            /* Register GDCGPCRB should be modfied, first get actual data: */
            u32RegData = u32GetGDCGPCRB(eGDC);
            /* delete related 8 bits: */
            u32RegData &= ~u32RegMask;
            
            /* insert new bits and write it back: */
            u32RegData |= u32NewData;
            vSetGDCGPCRB(eGDC, u32RegData);
            
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCGPCRB_REG__, u32GDCGPCRB_REG__Var[eGDC]);
            break;

        case GDC_PULSE_GEN_8:
        case GDC_PULSE_GEN_9:
        case GDC_PULSE_GEN_10:
        case GDC_PULSE_GEN_11:
            /* Register GDCGPCRC should be modfied, first get actual data: */
            u32RegData = u32GetGDCGPCRC(eGDC);
            /* delete related 8 bits: */
            u32RegData &= ~u32RegMask;
            
            /* insert new bits and write it back: */
            u32RegData |= u32NewData;
            vSetGDCGPCRC(eGDC, u32RegData);
            
            /* Copy register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCGPCRC_REG__, u32GDCGPCRC_REG__Var[eGDC]);
            break;

        default:
            /* Invalid Generator ID */
            boRes = C_FALSE;
            break;
    }

    return boRes;
}


/****************************************************************************/
bool_t boGDC_ConfigPulseGenA_B(gdc_ch_e eGDC,
                               gdc_pg_gen_id_e      ePGenID,
                               gdc_pg_A_B_e         eGenA_B,
                               gdc_pulse_config_st* pstConfig)

{
    uint8_t  u8Err = 0;
    bool_t   boRes = C_TRUE;
    uint32_t u32RegData;
    /* pulse generator properties: */
    gdc_pg_active_level_e  eActiveLevel_x;    /* Pulse generator active level select: */
    gdc_pg_input_e         eSelectedInput_x;  /* Pulse generator input signal select: */
    gdc_en_e               eByPassEnb_x;      /* Pulse generator bypass enable: */
    uint16_t               u16PulseDelay_x;   /* Delay of generated pulse */
    gdc_pg_divider_e       ePulseDivider_x;   /* Divider value is defined by DIV+1 */
    gdc_en_e               eInvertEnb_x;      /* Pulse generator inversion enable: */
    uint16_t               u16PulseWidth_x;   /* Width of generated pulse, measured in dot clock cycles for all input sources but VSYNC and VDISP */
    
    uint32_t u32GDCPxGAR_array[12] = {GDCP0GAR_REG__, GDCP1GAR_REG__, GDCP2GAR_REG__,  GDCP3GAR_REG__,
                                      GDCP4GAR_REG__, GDCP5GAR_REG__, GDCP6GAR_REG__,  GDCP7GAR_REG__,
                                      GDCP8GAR_REG__, GDCP9GAR_REG__, GDCP10GAR_REG__, GDCP11GAR_REG__
                                      };
    uint32_t u32GDCPxGBR_array[12] = {GDCP0GBR_REG__, GDCP1GBR_REG__, GDCP2GBR_REG__,  GDCP3GBR_REG__,
                                      GDCP4GBR_REG__, GDCP5GBR_REG__, GDCP6GBR_REG__,  GDCP7GBR_REG__,
                                      GDCP8GBR_REG__, GDCP9GBR_REG__, GDCP10GBR_REG__, GDCP11GBR_REG__
                                      };

    if ((0x00 == pstConfig) || (ePGenID > GDC_PULSE_GEN_11) )
    {
        boRes = C_FALSE;
    }
    else
    {
        eActiveLevel_x   = pstConfig->eActiveLevel;
        eSelectedInput_x = pstConfig->eSelectedInput;
        eByPassEnb_x     = pstConfig->eByPassEnb;
        u16PulseDelay_x  = pstConfig->u16PulseDelay;
        ePulseDivider_x  = pstConfig->ePulseDivider;
        eInvertEnb_x     = pstConfig->eInvertEnb;
        u16PulseWidth_x  = pstConfig->u16PulseWidth;
        
        /* check parameters: */
        if ( (GDC_ACTIVE_LVL_0 != eActiveLevel_x) && (GDC_ACTIVE_LVL_1 != eActiveLevel_x) )
        {
            u8Err++;
        }
        if ( (eSelectedInput_x < GDC_INP_DOTCLK) || (eSelectedInput_x > GDC_INP_PNL) )
        {
            u8Err++;
        }
        if ( (GDC_DISABLE != eByPassEnb_x) && (GDC_ENABLE != eByPassEnb_x) )
        {
            u8Err++;
        }
        if (u16PulseDelay_x > GDC_GADEL_MAX)
        {
            u8Err++;
        }
        if (ePulseDivider_x > GDC_DIVIDER_16)
        {
            u8Err++;
        }
        if ( (GDC_DISABLE != eInvertEnb_x) && (GDC_ENABLE != eInvertEnb_x) )
        {
            u8Err++;
        }
        if (u16PulseWidth_x > GDC_GAWID_MAX)
        {
            u8Err++;
        }
        /* if no error by parameters: */
        if (0x00 == u8Err)
        {
            /* program configuration of one shot pulse generator A or B:
             * +-------+----------+-------+-----------+----------+-------+-----------+
             * | 1 bit |  3 bits  | 1 bit |  11 bits  |  4 bits  | 1 bit |  11 bits  |
             * | GALVL |  GAINSEL | GABYP |   GADEL   |  GADIV   | GAINV |   GAWID   |
             * +-------+----------+-------+-----------+----------+-------+-----------+
             */
            u32RegData = eActiveLevel_x;
            u32RegData <<= GDC_PGEN_GAINSEL_BITS;

            u32RegData |= (uint32_t)eSelectedInput_x;
            u32RegData <<= GDC_PGEN_GABYP_BIT; 

            u32RegData |= (uint32_t)eByPassEnb_x;
            u32RegData <<= GDC_PGEN_GADEL_BIT;

            u32RegData |= u16PulseDelay_x;
            u32RegData <<= GDC_PGEN_GADIV_BIT;

            u32RegData |= (uint32_t)ePulseDivider_x;
            u32RegData <<= GDC_PGEN_GAINV_BIT;

            u32RegData |= (uint32_t)eInvertEnb_x;
            u32RegData <<= GDC_PGEN_GAWID_BIT;

            u32RegData |= u16PulseWidth_x;
        }
        if (GDC_PULSE_GEN_A == eGenA_B)
        {
            /* update back up of register in local variable: */
            u32GDCPxGAR_REG__Var[eGDC][ePGenID] = u32RegData;
            
            /* Copy GDCPxGAR (x:0..11) register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, u32GDCPxGAR_array[ePGenID], u32RegData);
        }
        else if (GDC_PULSE_GEN_B == eGenA_B)
        {
            /* update back up of register in local variable: */
            u32GDCPxGBR_REG__Var[eGDC][ePGenID] = u32RegData;
            
            /* Copy GDCPxGAR (x:0..11) register data to shadow register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, u32GDCPxGBR_array[ePGenID], u32RegData);
        }
        else
        {
            boRes = C_FALSE;
        }
    }
    return boRes;
}


/****************************************************************************/
uint16_t u16GDC_GetLastGAPIFColAddr(gdc_ch_e eGDC)
{
    uint16_t u16LastColAddr;
    /* Note: GCAR is R/C bits, so after read it will be reset to 0: */
    u16LastColAddr = u16GetGDCGCAR(eGDC);
    
    return u16LastColAddr;
}


/****************************************************************************/
bool_t boGDC_GetBusErrAddr(gdc_ch_e eGDC, uint32_t* pu32BusErrAddr)
{
    bool_t boRes = C_TRUE;
    uint32_t u32BusErrAddr;
    if (0x00 != pu32BusErrAddr)
    {
        u32BusErrAddr = (uint32_t) u32GetGDCGBEAR(eGDC);
        *pu32BusErrAddr = u32BusErrAddr;
    }
    else
    {
        boRes = C_FALSE;
    }
    return boRes;
}

/****************************************************************************/
bool_t boGDC_GetBusErrCtrlStatus(gdc_ch_e eGDC, gdc_bus_err_ctrl_st* pstCtrlStatus)
{
    bool_t boRes = C_TRUE;
    if(0x00 != pstCtrlStatus)
    {
        pstCtrlStatus->eDirection    = (gdc_buserr_dir_e) biGetGDCGBECR_WR(eGDC);
        pstCtrlStatus->eBurstType    = (gdc_buserr_bursttype_e) biGetGDCGBECR_BTYPE(eGDC);
        pstCtrlStatus->eBurstSize    = (gdc_buserr_burstsize_e) biGetGDCGBECR_BSIZE(eGDC);
        pstCtrlStatus->eRespType     = (gdc_buserr_resptype_e) biGetGDCGBECR_RTYPE(eGDC);
        pstCtrlStatus->u8ByteEnables = (uint8_t) biGetGDCGBECR_BEN(eGDC);
        pstCtrlStatus->u8ID          = (uint8_t) biGetGDCGBECR_ID(eGDC);
        pstCtrlStatus->u8BurstLength = (uint8_t) biGetGDCGBECR_LEN(eGDC);
    }
    else
    {
        boRes = C_FALSE;
    }
    return  boRes;
}


/****************************************************************************/
gdc_dcr_err_e eGDC_GetDcrBusErrors(gdc_ch_e eGDC)
{
    gdc_dcr_err_e  eRes;
    uint64_t       u64GdcDcr_HW;
    bool_t boRes_GBER   = C_FALSE;
    bool_t boRes_GAPCOL = C_FALSE;
    
    /* read HW register: */
    u64GdcDcr_HW = READ_REGISTER_64BITS(GDCDCR_REG__ , eGDC);
    
    /* check related bits: */
    if (0x00 != (u64GdcDcr_HW & GDC_DCR_ERR_GBER_MASK))
    {
        boRes_GBER = C_TRUE;
    }
    /* check related bits: */
    if (0x00 != (u64GdcDcr_HW & GDC_DCR_ERR_GAPCOL_MASK))
    {
        boRes_GAPCOL = C_TRUE;
    }
    if (C_TRUE == boRes_GBER)
    {
        eRes = (C_TRUE == boRes_GAPCOL)? GDC_DCR_ERR_GBER_AND_GAPCOL : GDC_DCR_ERR_GBER;
    }
    else if (C_TRUE == boRes_GAPCOL)
    {
        eRes = GDC_DCR_ERR_GAPCOL;
    }
    else
    {
        eRes = GDC_DCR_ERR_NONE;
    }
    return eRes;
}


/****************************************************************************/
bool_t boGDC_ClrDcrBusErrors(gdc_ch_e eGDC, gdc_dcr_err_e eClrBits)
{
    uint32_t u32Cntr;
    uint64_t u64GdcDcr_HW;
    bool_t boRes = C_TRUE;

    /* Important Not: 
     * clear bits can not be written directly to shadow register, because it can happen that
     * last modification of GDCDCR which are in shadow register but still waiting for VSYNC
     * to be copied into HW register, will be overwritten:
     *************/
    switch(eClrBits)
    {
        case GDC_DCR_ERR_GBER:
            /* set GBER bit in local variable before write to shadow register: */
            u64GDCDCR_REG__Var [eGDC] |= GDC_DCR_ERR_GBER_MASK;
            /* GBER: belongs to low word of register: */
            UPDATE_REGISTER_LOW_WORD(eGDC, GDCDCR_REG__, u64GDCDCR_REG__Var[eGDC]);
            break;
            
        case GDC_DCR_ERR_GAPCOL:
            /* set GAPCOL bit in local variable before write to shadow register: */
            u64GDCDCR_REG__Var [eGDC] |= GDC_DCR_ERR_GAPCOL_MASK;
            /* GAPCOL: belongs to high word of register: */
            vUpdateDCR_HighWord_Special(eGDC);
            break;

        case GDC_DCR_ERR_GBER_AND_GAPCOL:
            /* set GBER and GAPCOL bit in local variable before write to shadow register: */
            u64GDCDCR_REG__Var [eGDC] |= GDC_DCR_ERR_GBER_AND_GAPCOL_MASK;
            /* GBER and GAPCOL: belong to Low and high word of register: */
            vUpdateDCR_Special(eGDC);
            break;

        default:
            boRes = C_FALSE;
            break;
    }
    if (C_TRUE == boRes)
    {
        boRes = C_FALSE;
        /* set Loop Counter to 0 : */
        u32Cntr = 0;
        /* Wait until Clear bit(s) is(are) reset: */
        while ( (u32Cntr<MAX_WAIT_FOR_CLEAR) && (C_FALSE==boRes) )
        {
            u64GdcDcr_HW = READ_REGISTER_64BITS(GDCDCR_REG__ , eGDC);
            switch(eClrBits)
            {
            
                case GDC_DCR_ERR_GBER:
                    /* read clear bit from HW register, if it is 0 then clear has been done: */
                    if (0x00 == (u64GdcDcr_HW & GDC_DCR_ERR_GBER_MASK))
                    {
                        boRes = C_TRUE;
                    }
                    break;
                    
                case GDC_DCR_ERR_GAPCOL:
                    /* read clear bit from HW register, if it is 0 then clear has been done: */
                    if (0x00 == (u64GdcDcr_HW & GDC_DCR_ERR_GAPCOL_MASK))
                    {
                        boRes = C_TRUE;
                    }
                    break;
                    
                default:
                    /* read both clear bits from HW register, if both are 0 then clear has been done: */
                    if (0x00 == (u64GdcDcr_HW & GDC_DCR_ERR_GBER_AND_GAPCOL_MASK))
                    {
                        boRes = C_TRUE;
                    }
                    break;
            }
            u32Cntr++;
        } /* while .. */
    }
   /* Set clear bits in any case again to "0" in local variable: */
   u64GDCDCR_REG__Var[eGDC] &= (~GDC_DCR_ERR_GBER_AND_GAPCOL_MASK);
    
   return boRes;
}


/****************************************************************************/
void vGDC_GAPIFEnable(gdc_ch_e eGDC, gdc_en_e eEn)
{
    vSetGDCDCR_GAPEN(eGDC, eEn);
    /* GAPEN: belongs to high word of register: */
    /* GDCDCR register should be updated special: */  
    vUpdateDCR_HighWord_Special(eGDC);
}


/****************************************************************************/
bool_t boGDC_AccessToGapif(gdc_ch_e eGDC)
{
    bool_t boRes;
    boRes = ( 0x00 == biGetGDCDCR_GAPACC(eGDC))? C_FALSE : C_TRUE;
    return boRes;
}


/****************************************************************************/
gdc_irqact_e eGDC_IsIrqGap(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;
    i32IrqStat = biGetGDCINTR_GAPINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        /*
         * Note:
         *    By clearing GAPINT the error bit GAPCOL in GDCDCR register
         *    will also be cleared. */
        vClrGDCINTR_GAPINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}


/****************************************************************************/
gdc_irqact_e eGDC_IsIrqGber(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = biGetGDCINTR_GBERINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_GBERINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}


/****************************************************************************/
gdc_irqact_e eGDC_IsIrqGpe(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = biGetGDCINTR_GPEINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_GPEINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}


/****************************************************************************/
gdc_irqact_e eGDC_IsIrqDle(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = biGetGDCINTR_DLEINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_DLEINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}


/****************************************************************************/
gdc_irqact_e eGDC_IsIrqApe(gdc_ch_e eGDC)
{
    int32_t i32IrqStat;

    i32IrqStat = biGetGDCINTR_APEINT(eGDC);

    /* Clear the flag if the interrupt is active */
    if( 1 == i32IrqStat )
    {
        vClrGDCINTR_APEINT(eGDC);
    }

    return (gdc_irqact_e) i32IrqStat;
}
/*+-----------------------------------------------------------------------+*
 *|     END-Extended new APIs                                             |*
 *+-----------------------------------------------------------------------+*/

/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

/****************************************************************************/

/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: gdc.c
**  $Revision: 1.19 $
**  $Date: 2015/05/04 09:07:15 $
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
** | RULE   : 1849 / 8.1 - bitwise ~ or << expression must be immediately cast 
** |                       back to  underlying type, "unsigned char" 
** | CONS.  : allow
** | REASON : necessary for shift oeprations, which we know it will not over run 
** |
**  ------------------------------------------------------------------------
**  ------------------------------------------------------------------------
** |
** | RULE   : 1858 /17.4  - subscript operator may only be applied to objects 
** |                        declared as an array type
** | CONS.  : allow
** | REASON : to handle array of data by usage of pointer 
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
** | RULE   : 1878 /10.3  -   cast of complex integer expression with underlying 
** |                          type "type" to wider type "type" not allowed
** | CONS.  : allow
** | REASON : to assign parameters which may be defined as variables in io 
** |          header file or to allow shift operation
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

