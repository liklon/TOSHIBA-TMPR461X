/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : PNG-decoder low level driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : 
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
#include "png_io.h"                   /* png registers, bits and access macros defintion */
#include "png.h"                      /* Own definitions */
#include "png_memory.h"               /* buffer length definitions */

/*********************************************/
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1752  /* Rule 17.4 [R] : pointer arithmetic not allowed */  
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : cast of complex integer expression with underlying type "type" to non-integer type "type" not allowed */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to narrower underlying type, "type", not allowed */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : conversion from underlying type, "int", to same width underlying type, "uint32_t", not allowed */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : implicit conversion from underlying type, "type", to underlying type, "type", changes signedness */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : implicit conversion of complex expression from underlying type, "type", to underlying type, "type", not allowed
 */
  
  #pragma ghs nowarning 1737  /* Rule 12.1 [A] : expression may not depend on operator precedence rules */  
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error */  
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1877  /* Rule 11.3 [A] : disable casting error */
#endif

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_PNG_C_REVISION     "$Revision: 1.19 $"
#define LLDD_PNG_C_TAG          "$Name: LLDD_1_7_GFX $"

/*********************************************/
#define PNG_GLOBAL_ALLINTR_MASK  0x7FU
#define PNG_STREAM_ALLINTR_MASK  0xFFFFFFFFU
/**********************************************
*  Static variables and forward declarations  *
**********************************************/ 

static uint8_t au8LLDD_PNG_C_REVISION[]    = LLDD_PNG_C_REVISION;
static uint8_t au8LLDD_PNG_C_TAG[]         = LLDD_PNG_C_TAG;
static uint8_t au8LLDD_PNG_H_REVISION[]    = LLDD_PNG_H_REVISION;
static uint8_t au8LLDD_PNG_H_TAG[]         = LLDD_PNG_H_TAG;
static uint8_t au8LLDD_PNG_IO_H_REVISION[] = LLDD_PNG_IO_H_REVISION;
static uint8_t au8LLDD_PNG_IO_H_TAG[]      = LLDD_PNG_IO_H_TAG;

/*********************************************/

/**********************************************
*              Global variables               *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section bss = ".PNGBuffer"
#define ALIGNED
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#if defined (__KEIL__)
#pragma arm section zidata = ".PNGBuffer"
#else
#pragma arm section rwdata = ".PNGBuffer"
#endif
#define ALIGNED __align(8)
#endif /* defined(__arm__) && defined(__ARMCC_VERSION) */

/* SST buffer: 32k byte, 64-bit aligned */
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_SWB_Buffer_Stream_0[SLIDING_WINDOW_SIZE];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_SWB_Buffer_Stream_1[SLIDING_WINDOW_SIZE];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_SWB_Buffer_Stream_2[SLIDING_WINDOW_SIZE];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_SWB_Buffer_Stream_3[SLIDING_WINDOW_SIZE];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_SWB_Buffer_Stream_4[SLIDING_WINDOW_SIZE];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_SWB_Buffer_Stream_5[SLIDING_WINDOW_SIZE];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_SWB_Buffer_Stream_6[SLIDING_WINDOW_SIZE];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_SWB_Buffer_Stream_7[SLIDING_WINDOW_SIZE];

/* SST buffer: 16k byte, 64-bit aligned */
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_FSB_Buffer_Stream_0[FILTER_STREAM_BUFFER_LENGTH];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_FSB_Buffer_Stream_1[FILTER_STREAM_BUFFER_LENGTH];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_FSB_Buffer_Stream_2[FILTER_STREAM_BUFFER_LENGTH];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_FSB_Buffer_Stream_3[FILTER_STREAM_BUFFER_LENGTH];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_FSB_Buffer_Stream_4[FILTER_STREAM_BUFFER_LENGTH];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_FSB_Buffer_Stream_5[FILTER_STREAM_BUFFER_LENGTH];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_FSB_Buffer_Stream_6[FILTER_STREAM_BUFFER_LENGTH];
#if defined(__GHS__) || defined(__ghs__)
#pragma alignvar(8)
#endif /* defined(__GHS__) || defined(__ghs__) */
ALIGNED uint8_t u8PNG_FSB_Buffer_Stream_7[FILTER_STREAM_BUFFER_LENGTH];

uint32_t u32SWBBufferStartAddress[8];
uint32_t u32FSBBufferStartAddress[8];
uint32_t u32VirtualMemoryStartAddress[8];

#if defined(__GHS__) || defined(__ghs__)
#pragma ghs section bss = default
#endif /* defined(__GHS__) || defined(__ghs__) */

#if defined(__arm__) && defined(__ARMCC_VERSION)
#if defined (__KEIL__)
#pragma arm section zidata
#else
#pragma arm section rwdata
#endif
#endif /* defined(__arm__) && defined(__ARMCC_VERSION) */

/*********************************************/

/**********************************************
*             Function definition             *
**********************************************/

void vPNG_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_PNG_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_PNG_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_PNG_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_PNG_H_TAG[0];
   *pau8IORevision     = &au8LLDD_PNG_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_PNG_IO_H_TAG[0];
}

/****************************************************************************/

void vPNG_Init(void)
{
    /* SWB buffer */
    u32SWBBufferStartAddress[0] = (uint32_t)&u8PNG_SWB_Buffer_Stream_0[0];
    u32SWBBufferStartAddress[1] = (uint32_t)&u8PNG_SWB_Buffer_Stream_1[0];
    u32SWBBufferStartAddress[2] = (uint32_t)&u8PNG_SWB_Buffer_Stream_2[0];
    u32SWBBufferStartAddress[3] = (uint32_t)&u8PNG_SWB_Buffer_Stream_3[0];
    u32SWBBufferStartAddress[4] = (uint32_t)&u8PNG_SWB_Buffer_Stream_4[0];
    u32SWBBufferStartAddress[5] = (uint32_t)&u8PNG_SWB_Buffer_Stream_5[0];
    u32SWBBufferStartAddress[6] = (uint32_t)&u8PNG_SWB_Buffer_Stream_6[0];
    u32SWBBufferStartAddress[7] = (uint32_t)&u8PNG_SWB_Buffer_Stream_7[0];

    /* FSB buffer */
    u32FSBBufferStartAddress[0] = (uint32_t)&u8PNG_FSB_Buffer_Stream_0[0];
    u32FSBBufferStartAddress[1] = (uint32_t)&u8PNG_FSB_Buffer_Stream_1[0];
    u32FSBBufferStartAddress[2] = (uint32_t)&u8PNG_FSB_Buffer_Stream_2[0];
    u32FSBBufferStartAddress[3] = (uint32_t)&u8PNG_FSB_Buffer_Stream_3[0];
    u32FSBBufferStartAddress[4] = (uint32_t)&u8PNG_FSB_Buffer_Stream_4[0];
    u32FSBBufferStartAddress[5] = (uint32_t)&u8PNG_FSB_Buffer_Stream_5[0];
    u32FSBBufferStartAddress[6] = (uint32_t)&u8PNG_FSB_Buffer_Stream_6[0];
    u32FSBBufferStartAddress[7] = (uint32_t)&u8PNG_FSB_Buffer_Stream_7[0];

    /* Decoded Stream Virtual Start Address */
    u32VirtualMemoryStartAddress[0] = PNG_VIRTUAL_START_ADDRESS_STREAM_0;
    u32VirtualMemoryStartAddress[1] = PNG_VIRTUAL_START_ADDRESS_STREAM_1;
    u32VirtualMemoryStartAddress[2] = PNG_VIRTUAL_START_ADDRESS_STREAM_2;
    u32VirtualMemoryStartAddress[3] = PNG_VIRTUAL_START_ADDRESS_STREAM_3;
    u32VirtualMemoryStartAddress[4] = PNG_VIRTUAL_START_ADDRESS_STREAM_4;
    u32VirtualMemoryStartAddress[5] = PNG_VIRTUAL_START_ADDRESS_STREAM_5;
    u32VirtualMemoryStartAddress[6] = PNG_VIRTUAL_START_ADDRESS_STREAM_6;
    u32VirtualMemoryStartAddress[7] = PNG_VIRTUAL_START_ADDRESS_STREAM_7;
}   

/****************************************************************************/

int32_t i32PNG_SetUpStream(png_stream_e eStream, uint32_t u32StartAddress, png_decode_mode_e eDecodeMode, png_decoded_output_format_e eOutputFormat, uint32_t u32Width, uint32_t u32Height)
{
    int32_t i32Res = C_SUCCESS;

    /* check if the stream is in allowed range: */
    if (eStream > PNG_STREAM_7)
    {
        i32Res = C_FAILED;
    }
    else
    {
        /* reset png-decoder */
        vSetPNGSCTRL_SRST(eStream);

        if (biGetPNGSSTAT_PHASE(eStream) == 0)
        {
            /* SWB buffer */
            vSetPNGSWBSA_SA(eStream, u32SWBBufferStartAddress[eStream]);

            /* FSB buffer */
            vSetPNGFSBSA_SA(eStream, u32FSBBufferStartAddress[eStream]);

            /* Decoded Stream Virtual Start Address */
            vSetPNGDSVSA_SA(eStream, u32VirtualMemoryStartAddress[eStream]);

            /* set start address of input stream */
            vSetPNGSSBSA_SA(eStream, u32StartAddress);

            /* decoded output format */
            vSetPNGSOF_FSEL(eStream, eOutputFormat);

            /* set virtual memory end address */
            vSetPNGDSVEA_EA(eStream, u32VirtualMemoryStartAddress[eStream] + 4 * u32Width * u32Height);

            /* set decode mode */
            vSetPNGSCTRL_LOOP(eStream, eDecodeMode);
         
            /* start stream */
            vSetPNGSCTRL_TRIG(eStream, 0x1U);
        }
        else
        {
            i32Res = C_FAILED;
        }
    }



    return i32Res;
}

/****************************************************************************/

uint32_t u32PNG_GetModuleVersion(void)
{
   return biGetPNGVER_VERSION();
}

/****************************************************************************/

void vPNG_SetIntType(png_int_type_e eIntType)
{
    vSetPNGGCTRL_IPRE(eIntType);
}

/****************************************************************************/

int32_t i32PNG_EnableGlobalInterruptSingle(png_int_e eInt, png_enable_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    switch (eInt)
    {
        case PNG_INT_VSWAEI:
            {
                vSetPNGGINTE_VSWAEIE(eEn);
            }
            break;
        case PNG_INT_VSUAEI:
            {
                vSetPNGGINTE_VSUAEIE(eEn);
            }
            break;
        case PNG_INT_CW2ROEI:
            {
                vSetPNGGINTE_CW2ROEIE(eEn);
            }
            break;
        case PNG_INT_CRSVAEI:
            {
                vSetPNGGINTE_CRSVAEIE(eEn);
            }
            break;
        case PNG_INT_CPEI:
            {
                vSetPNGGINTE_CPEIE(eEn);
            }
            break;
        case PNG_INT_SWBEI:
            {
                vSetPNGGINTE_SWBEIE(eEn);
            }
            break;
        case PNG_INT_SSBEI:
            {
                vSetPNGGINTE_SSBEIE(eEn);
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

int32_t i32PNG_EnableStreamInterruptSingle(png_stream_e eStream, png_int_e eInt, png_enable_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    switch (eInt)
    {
        case PNG_INT_BJMPEI:
            {
                vSetPNGSINTE_BJMPEIE(eStream, eEn);
            }
            break;
        case PNG_INT_UFMTEI:
            {
                vSetPNGSINTE_UFMTEIE(eStream, eEn);
            }
            break;
        case PNG_INT_OOCEI:
            {
                vSetPNGSINTE_OOCEIE(eStream, eEn);
            }
            break;
        case PNG_INT_CHSEI:
            {
                vSetPNGSINTE_CHSEIE(eStream, eEn);
            }
            break;
        case PNG_INT_EYEOSEI:
            {
                vSetPNGSINTE_EYEOSEIE(eStream, eEn);
            }
            break;
        case PNG_INT_NOEOSEI:
            {
                vSetPNGSINTE_NOEOSEIE(eStream, eEn);
            }
            break;
        case PNG_INT_CMPEI:
            {
                vSetPNGSINTE_CMPEIE(eStream, eEn);
            }
            break;
        case PNG_INT_BTYPEEI:
            {
                vSetPNGSINTE_BTYPEEIE(eStream, eEn);
            }
            break;
        case PNG_INT_DISTEI:
            {
                vSetPNGSINTE_DISTEIE(eStream, eEn);
            }
            break;
        case PNG_INT_NCBSEI:
            {
                vSetPNGSINTE_NCBSEIE(eStream, eEn);
            }
            break;
        case PNG_INT_DECEI:
            {
                vSetPNGSINTE_DECEIE(eStream, eEn);
            }
            break;
        case PNG_INT_FJMPWI:
            {
                vSetPNGSINTE_FJMPWIE(eStream, eEn);
            }
            break;
        case PNG_INT_UCHNKWI:
            {
                vSetPNGSINTE_UCHNKWIE(eStream, eEn);
            }
            break;
        case PNG_INT_PDICTWI:
            {
                vSetPNGSINTE_PDICTWIE(eStream, eEn);
            }
            break;
        case PNG_INT_ULLWI:
            {
                vSetPNGSINTE_ULLWIE(eStream, eEn);
            }
            break;
        case PNG_INT_UDISTWI:
            {
                vSetPNGSINTE_UDISTWIE(eStream, eEn);
            }
            break;
        case PNG_INT_OFCWI:
            {
                vSetPNGSINTE_OFCWIE(eStream, eEn);
            }
            break;
        case PNG_INT_IHDRDI:
            {
                vSetPNGSINTE_IHDRDIE(eStream, eEn);
            }
            break;
        case PNG_INT_PLTEDI:
            {
                vSetPNGSINTE_PLTEDIE(eStream, eEn);
            }
            break;
        case PNG_INT_IDATDI:
            {
                vSetPNGSINTE_IDATDIE(eStream, eEn);
            }
            break;
        case PNG_INT_IENDDI:
            {
                vSetPNGSINTE_IENDDIE(eStream, eEn);
            }
            break;
        case PNG_INT_DCDSI:
            {
                vSetPNGSINTE_DCDSIE(eStream, eEn);
            }
            break;
        case PNG_INT_SIDLEI:
            {
                vSetPNGSINTE_SIDLEIE(eStream, eEn);
            }
            break;
        case PNG_INT_DSFFULLIE:
            {
                vSetPNGSINTE_DSFFULLIE(eStream, eEn);
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

void vPNG_EnableGlobalInterruptAll(uint8_t u8Value)
{
    vSetPNGGINTELL(u8Value);
}

/****************************************************************************/

void vPNG_EnableStreamInterruptAll(png_stream_e eStream, uint32_t u32Value)
{
    vSetPNGSINTE(eStream, u32Value);
}

/****************************************************************************/

int32_t i32PNG_GetGlobalInterruptStatusSingle(png_int_e eInt, png_int_status_e * peIntStatus)
{
    int32_t i32Res = C_SUCCESS;

    if (0x00 != peIntStatus)
    {
        switch (eInt)
        {
            case PNG_INT_VSWAEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGGINTS_VSWAEIS();
                }
                break;
            case PNG_INT_VSUAEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGGINTS_VSUAEIS();
                }
                break;
            case PNG_INT_CW2ROEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGGINTS_CW2ROEIS();
                }
                break;
            case PNG_INT_CRSVAEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGGINTS_CRSVAEIS();
                }
                break;
            case PNG_INT_CPEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGGINTS_CPEIS();
                }
                break;
            case PNG_INT_SWBEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGGINTS_SWBEIS();
                }
                break;
            case PNG_INT_SSBEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGGINTS_SSBEIS();
                }
                break;
            default:
                {
                    i32Res = C_FAILED;
                }
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

int32_t i32PNG_GetStreamInterruptStatusSingle(png_stream_e eStream, png_int_e eInt, png_int_status_e * peIntStatus)
{
    int32_t i32Res = C_SUCCESS;


    if (0x00 != peIntStatus)
    {
        switch (eInt)
        {
            case PNG_INT_BJMPEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_BJMPEIS(eStream);
                }
                break;
            case PNG_INT_UFMTEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_UFMTEIS(eStream);
                }
                break;
            case PNG_INT_OOCEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_OOCEIS(eStream);
                }
                break;
            case PNG_INT_CHSEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_CHSEIS(eStream);
                }
                break;
            case PNG_INT_EYEOSEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_EYEOSEIS(eStream);
                }
                break;
            case PNG_INT_NOEOSEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_NOEOSEIS(eStream);
                }
                break;
            case PNG_INT_CMPEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_CMPEIS(eStream);
                }
                break;
            case PNG_INT_BTYPEEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_BTYPEEIS(eStream);
                }
                break;
            case PNG_INT_DISTEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_DISTEIS(eStream);
                }
                break;
            case PNG_INT_NCBSEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_NCBSEIS(eStream);
                }
                break;
            case PNG_INT_DECEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_DECEIS(eStream);
                }
                break;
            case PNG_INT_FJMPWI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_FJMPWIS(eStream);
                }
                break;
            case PNG_INT_UCHNKWI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_UCHNKWIS(eStream);
                }
                break;
            case PNG_INT_PDICTWI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_PDICTWIS(eStream);
                }
                break;
            case PNG_INT_ULLWI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_ULLWIS(eStream);
                }
                break;
            case PNG_INT_UDISTWI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_UDISTWIS(eStream);
                }
                break;
            case PNG_INT_OFCWI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_OFCWIS(eStream);
                }
                break;
            case PNG_INT_IHDRDI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_IHDRDIS(eStream);
                }
                break;
            case PNG_INT_PLTEDI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_PLTEDIS(eStream);
                }
                break;
            case PNG_INT_IDATDI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_IDATDIS(eStream);
                }
                break;
            case PNG_INT_IENDDI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_IENDDIS(eStream);
                }
                break;
            case PNG_INT_DCDSI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_DCDSIS(eStream);
                }
                break;
            case PNG_INT_SIDLEI:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_SIDLEIS(eStream);
                }
                break;
            case PNG_INT_DSFFULLIE:
                {
                    *peIntStatus = (png_int_status_e)biGetPNGSINTS_DSFFULLIS(eStream);
                }
                break;
            default:
                {
                    i32Res = C_FAILED;
                }
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

uint8_t u8PNG_GetGlobalInterruptStatusAll(void)
{
    return u8GetPNGGINTSLL();
}

/****************************************************************************/

uint32_t u32PNG_GetStreamInterruptStatusAll(png_stream_e eStream)
{
    return u32GetPNGSINTS(eStream);
}

/****************************************************************************/

int32_t i32PNG_ClearGlobalInterruptSingle(png_int_e eInt)
{
    int32_t i32Res = C_SUCCESS;

    switch (eInt)
    {
        case PNG_INT_VSWAEI:
            {
                vClrPNGGINTC_VSWAEIC();
            }
            break;
        case PNG_INT_VSUAEI:
            {
                vClrPNGGINTC_VSUAEIC();
            }
            break;
        case PNG_INT_CW2ROEI:
            {
                vClrPNGGINTC_CW2ROEIC();
            }
            break;
        case PNG_INT_CRSVAEI:
            {
                vClrPNGGINTC_CRSVAEIC();
            }
            break;
        case PNG_INT_CPEI:
            {
                vClrPNGGINTC_CPEIC();
            }
            break;
        case PNG_INT_SWBEI:
            {
                vClrPNGGINTC_SWBEIC();
            }
            break;
        case PNG_INT_SSBEI:
            {
                vClrPNGGINTC_SSBEIC();
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

int32_t i32PNG_ClearStreamInterruptSingle(png_stream_e eStream, png_int_e eInt)
{
    int32_t i32Res = C_SUCCESS;

    switch (eInt)
    {
        case PNG_INT_BJMPEI:
            {
                vClrPNGSINTC_BJMPEIC(eStream);
            }
            break;
        case PNG_INT_UFMTEI:
            {
                vClrPNGSINTC_UFMTEIC(eStream);
            }
            break;
        case PNG_INT_OOCEI:
            {
                vClrPNGSINTC_OOCEIC(eStream);
            }
            break;
        case PNG_INT_CHSEI:
            {
                vClrPNGSINTC_CHSEIC(eStream);
            }
            break;
        case PNG_INT_EYEOSEI:
            {
                vClrPNGSINTC_EYEOSEIC(eStream);
            }
            break;
        case PNG_INT_NOEOSEI:
            {
                vClrPNGSINTC_NOEOSEIC(eStream);
            }
            break;
        case PNG_INT_CMPEI:
            {
                vClrPNGSINTC_CMPEIC(eStream);
            }
            break;
        case PNG_INT_BTYPEEI:
            {
                vClrPNGSINTC_BTYPEEIC(eStream);
            }
            break;
        case PNG_INT_DISTEI:
            {
                vClrPNGSINTC_DISTEIC(eStream);
            }
            break;
        case PNG_INT_NCBSEI:
            {
                vClrPNGSINTC_NCBSEIC(eStream);
            }
            break;
        case PNG_INT_DECEI:
            {
                vClrPNGSINTC_DECEIC(eStream);
            }
            break;
        case PNG_INT_FJMPWI:
            {
                vClrPNGSINTC_FJMPWIC(eStream);
            }
            break;
        case PNG_INT_UCHNKWI:
            {
                vClrPNGSINTC_UCHNKWIC(eStream);
            }
            break;
        case PNG_INT_PDICTWI:
            {
                vClrPNGSINTC_PDICTWIC(eStream);
            }
            break;
        case PNG_INT_ULLWI:
            {
                vClrPNGSINTC_ULLWIC(eStream);
            }
            break;
        case PNG_INT_UDISTWI:
            {
                vClrPNGSINTC_UDISTWIC(eStream);
            }
            break;
        case PNG_INT_OFCWI:
            {
                vClrPNGSINTC_OFCWIC(eStream);
            }
            break;
        case PNG_INT_IHDRDI:
            {
                vClrPNGSINTC_IHDRDIC(eStream);
            }
            break;
        case PNG_INT_PLTEDI:
            {
                vClrPNGSINTC_PLTEDIC(eStream);
            }
            break;
        case PNG_INT_IDATDI:
            {
                vClrPNGSINTC_IDATDIC(eStream);
            }
            break;
        case PNG_INT_IENDDI:
            {
                vClrPNGSINTC_IENDDIC(eStream);
            }
            break;
        case PNG_INT_DCDSI:
            {
                vClrPNGSINTC_DCDSIC(eStream);
            }
            break;
        case PNG_INT_SIDLEI:
            {
                vClrPNGSINTC_SIDLEIC(eStream);
            }
            break;
        case PNG_INT_DSFFULLIE:
            {
                vClrPNGSINTC_DSFFULLIC(eStream);
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

void vPNG_ClearGlobalInterruptAll(void)
{
    vSetPNGGINTCLL(PNG_GLOBAL_ALLINTR_MASK);
}

/****************************************************************************/

void vPNG_ClearStreamInterruptAll(png_stream_e eStream)
{
    vSetPNGSINTC(eStream, PNG_STREAM_ALLINTR_MASK);
}

/****************************************************************************/
void vPNG_ResetStream(png_stream_e eStream)
{
    vSetPNGSCTRL_SRST(eStream);
}

/****************************************************************************/
bool_t boPNG_GetBusError(png_bus_error_type_e eErrType, png_bus_error_st *pstBussError)
{
    bool_t boResult = C_TRUE;

    if ((0x00 == pstBussError) || (eErrType > PNG_SOURCE_STREAM_ERR))
    {
        boResult = C_FALSE;
    }
    else
    {
        if (PNG_SLIDING_WINDOW_ERR == eErrType)
        {
            pstBussError->u32ErrAddress = (uint32_t)            biGetPNGSWBEA_ADDR();
            pstBussError->eRWdir        = (png_transfer_type_e) biGetPNGSWBEC_WR();
            pstBussError->eBurstType    = (png_burst_type_e)    biGetPNGSWBEC_BTYPE();
            pstBussError->eBurstSize    = (png_burst_size_e)    biGetPNGSWBEC_BSIZE();
            pstBussError->eRespType     = (png_response_type_e) biGetPNGSWBEC_RTYPE();
            pstBussError->eByteEnable   = (png_enable_e)        biGetPNGSWBEC_BEN();
            pstBussError->u8ID          = (uint8_t)             biGetPNGSWBEC_ID();
            pstBussError->u8BurstLen    = (uint8_t)             biGetPNGSWBEC_LEN();
        }
        else
        {
            pstBussError->u32ErrAddress = (uint32_t)            biGetPNGSSBEA_ADDR();
            pstBussError->eRWdir        = (png_transfer_type_e) biGetPNGSSBEC_WR();
            pstBussError->eBurstType    = (png_burst_type_e)    biGetPNGSSBEC_BTYPE();
            pstBussError->eBurstSize    = (png_burst_size_e)    biGetPNGSSBEC_BSIZE();
            pstBussError->eRespType     = (png_response_type_e) biGetPNGSSBEC_RTYPE();
            pstBussError->eByteEnable   = (png_enable_e)        biGetPNGSSBEC_BEN();
            pstBussError->u8ID          = (uint8_t)             biGetPNGSSBEC_ID();
            pstBussError->u8BurstLen    = (uint8_t)             biGetPNGSSBEC_LEN();
        }
    }
    return boResult;
}

/****************************************************************************/
png_phase_status_e ePNG_GetStreamPhaseStatus (png_stream_e eStream)
{
    return ((png_phase_status_e)biGetPNGSSTAT_PHASE(eStream));
}

/****************************************************************************/
bool_t boPNG_GetStreamStatus (png_stream_e eStream, png_stream_status_st *pstStreamStatus)
{
    bool_t boResult = C_TRUE;

    if ( (0x00 == pstStreamStatus) || (eStream > PNG_STREAM_7) )
    {
        boResult = C_FALSE;
    }
    else
    {
        pstStreamStatus->ePhase          = (png_phase_status_e) biGetPNGSSTAT_PHASE(eStream);
        pstStreamStatus->ePalTableLoad   = (png_pt_loaded_e) biGetPNGSSTAT_PTL(eStream);
        pstStreamStatus->eTypeOfChunk    = (png_chunk_e) biGetPNGSSTAT_CHUNK(eStream);
        pstStreamStatus->u16NoPalEntries  = (uint16_t) biGetPNGSSTAT_NPE(eStream);
        pstStreamStatus->u8NoIdatChunks  = (uint8_t) biGetPNGSSTAT_NIDAT(eStream);
    }
    return boResult;
}

/****************************************************************************/
bool_t boPNG_GetStreamIhdrInfo (png_stream_e eStream, png_stream_ihdr_info_st *pstStreamIhdrInfo)
{
    bool_t boResult = C_TRUE;

    if ( (0x00 == pstStreamIhdrInfo) || (eStream > PNG_STREAM_7) )
    {
        boResult = C_FALSE;
    }
    else
    {
        pstStreamIhdrInfo->eBitDepth       = (png_bit_depth_e) biGetPNGSIHDR_BITDEPTH(eStream);
        pstStreamIhdrInfo->eColorType      = (png_color_format_e) biGetPNGSIHDR_CLRTYP(eStream);
        pstStreamIhdrInfo->u8ComprMethod   = (uint8_t) biGetPNGSIHDR_CMPMTH(eStream);
        pstStreamIhdrInfo->u8FilterMethod  = (uint8_t) biGetPNGSIHDR_FLTMTH(eStream);
        pstStreamIhdrInfo->u8InterlMethod  = (uint8_t) biGetPNGSIHDR_INTMTH(eStream);
    }
    return boResult;
}

/****************************************************************************/

bool_t boPNG_GetStreamZlibInfo (png_stream_e eStream, png_stream_zlib_info_st *pstStreamZlibInfo)
{
    bool_t boResult = C_TRUE;

    if ( (0x00 == pstStreamZlibInfo) || (eStream > PNG_STREAM_7) )
    {
        boResult = C_FALSE;
    }
    else
    {
        pstStreamZlibInfo->u8ComprMethod = (uint8_t) biGetPNGSZHDR_CM(eStream);
        pstStreamZlibInfo->u8ComprInfo   = (uint8_t) biGetPNGSZHDR_CINFO(eStream);
        pstStreamZlibInfo->u8CheckBits   = (uint8_t) biGetPNGSZHDR_FCHECK(eStream);
        pstStreamZlibInfo->u8Fdict       = (uint8_t) biGetPNGSZHDR_FDICT(eStream);
        pstStreamZlibInfo->u8Flevel      = (uint8_t) biGetPNGSZHDR_FLEVEL(eStream);
    }
    return boResult;
}

/****************************************************************************/
bool_t boPNG_GetImageSize(png_stream_e eStream, uint32_t *pu32Width, uint32_t *pu32Height)
{
    bool_t boRes = C_TRUE;
    if ( (0x00 != pu32Width) && (0x00 != pu32Height))
    {
        *pu32Width  = biGetPNGSW_WIDTH(eStream);
        *pu32Height = biGetPNGSH_HEIGHT(eStream);
    }
    else
    {
        boRes = C_FALSE;
    }
    return boRes;
}

/****************************************************************************/
uint8_t u8PNG_GetDecodedStreamFIFOFillLevel(png_stream_e eStream)
{
    return ((uint8_t)biGetPNGDSFLVL_DSFLEVEL(eStream));
}

/****************************************************************************/

uint32_t u32PNG_GetSSBCurrentAddress(png_stream_e eStream)
{
    return ((uint32_t)biGetPNGSSBCA_CA(eStream));
}

/****************************************************************************/

uint32_t u32PNG_GetSWBCurrentAddress(png_stream_e eStream)
{
    return ((uint32_t)biGetPNGSWBCA_CA(eStream));
}

/****************************************************************************/

uint32_t u32PNG_GetFSBStartAddress(png_stream_e eStream)
{
    return ((uint32_t)biGetPNGFSBCA_CA(eStream));
}

/****************************************************************************/

uint32_t u32PNG_GetCurrentVirtualOffset(png_stream_e eStream)
{
    return ((uint32_t)biGetPNGDSCVA_CA(eStream));
}

/****************************************************************************/

int32_t i32PNG_SetPaletteTable(png_stream_e eStream, uint32_t * pu32PaletteTable)
{
    uint32_t u32Count;
    int32_t  i32Res = C_SUCCESS;

    /* check for valid data buffer pointer */
    if (C_NULL == pu32PaletteTable)
    {
        i32Res = C_FAILED;
    }
    else
    {
        /* check if stream is idle */
        if (biGetPNGSSTAT_PHASE(eStream) == 0)
        {
            switch (eStream)
            {
                case PNG_STREAM_0:
                    {
                        for (u32Count=0; u32Count<256; u32Count++)
                        {
                            vSetPNGPLT0_PLTVAL0(u32Count, *(pu32PaletteTable + 4*u32Count));
                        }
                    }
                    break;
                case PNG_STREAM_1:
                    {
                        for (u32Count=0; u32Count<256; u32Count++)
                        {
                            vSetPNGPLT1_PLTVAL1(u32Count, *(pu32PaletteTable + 4*u32Count));
                        }
                    }
                    break;
                case PNG_STREAM_2:
                    {
                        for (u32Count=0; u32Count<256; u32Count++)
                        {
                            vSetPNGPLT2_PLTVAL2(u32Count, *(pu32PaletteTable + 4*u32Count));
                        }
                    }
                    break;
                case PNG_STREAM_3:
                    {
                        for (u32Count=0; u32Count<256; u32Count++)
                        {
                            vSetPNGPLT3_PLTVAL3(u32Count, *(pu32PaletteTable + 4*u32Count));
                        }
                    }
                    break;
                case PNG_STREAM_4:
                    {
                        for (u32Count=0; u32Count<256; u32Count++)
                        {
                            vSetPNGPLT4_PLTVAL4(u32Count, *(pu32PaletteTable + 4*u32Count));
                        }
                    }
                    break;
                case PNG_STREAM_5:
                    {
                        for (u32Count=0; u32Count<256; u32Count++)
                        {
                            vSetPNGPLT5_PLTVAL5(u32Count, *(pu32PaletteTable + 4*u32Count));
                        }
                    }
                    break;
                case PNG_STREAM_6:
                    {
                        for (u32Count=0; u32Count<256; u32Count++)
                        {
                            vSetPNGPLT6_PLTVAL6(u32Count, *(pu32PaletteTable + 4*u32Count));
                        }
                    }
                    break;
                case PNG_STREAM_7:
                    {
                        for (u32Count=0; u32Count<256; u32Count++)
                        {
                            vSetPNGPLT7_PLTVAL7(u32Count, *(pu32PaletteTable + 4*u32Count));
                        }
                    }
                    break;
                default:
                    {
                        i32Res = C_FAILED;
                    }
                    break;
            }
        }
        else
        {
            i32Res = C_FAILED;
        }
    }

    return i32Res;
}

/****************************************************************************/


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: png.c
**  $Revision: 1.19 $
**  $Date: 2015/05/04 09:07:15 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 1752 / 17.4 - pointer arithmetic not allowed
** | CONS.  : allow
** | REASON : to increment command list pointer 
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

