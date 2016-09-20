/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION :
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      :
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.28 $
*   DATE        : $Date: 2015/05/18 13:49:55 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "ccr_pdh_io.h"
#include "ccr_pds_io.h"
#include "ccr.h"

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_CCR_C_REVISION     "$Revision: 1.28 $"
#define LLDD_CCR_C_TAG          "$Name: LLDD_1_6 $"

#define MAX_ALARM_THRESHOLD  31 /* (5 Bits: 2^5) */
#define CCR_DEBUG_CTRL_BIT  (0x1U)

/*********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1771  /* Rule 2.4  [A] : No `commented out' sections of code */
  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */
  #pragma ghs nowarning 1834  /* Rule 5.7  [A] : No reuse of identifiers */

  #pragma ghs nowarning 667   /* Rule 1.1  [R] : ISO 9899:1990 C conformance w/o extensions */
  #pragma ghs nowarning 1800  /* Rule 8.1  [R] : Functions must always have prototype declarations */
  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : Rule 10.1 [R] : Restrict implicit conversions for integer type expressions */
 #endif
/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_CCR_C_REVISION[]        = LLDD_CCR_C_REVISION;
static uint8_t au8LLDD_CCR_C_TAG[]             = LLDD_CCR_C_TAG;
static uint8_t au8LLDD_CCR_H_REVISION[]        = LLDD_CCR_H_REVISION;
static uint8_t au8LLDD_CCR_H_TAG[]             = LLDD_CCR_H_TAG;
static uint8_t au8LLDD_CCR_PDH_IO_H_REVISION[] = LLDD_CCR_PDH_IO_H_REVISION;
static uint8_t au8LLDD_CCR_PDH_IO_H_TAG[]      = LLDD_CCR_PDH_IO_H_TAG;
static uint8_t au8LLDD_CCR_PDS_IO_H_REVISION[] = LLDD_CCR_PDS_IO_H_REVISION;
static uint8_t au8LLDD_CCR_PDS_IO_H_TAG[]      = LLDD_CCR_PDS_IO_H_TAG;

/*********************************************/

/**********************************************
*             Function definition             *
*********************************************/

/****************************************************************************/
void vCCR_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IOPDHRevision, uint8_t** pau8IOPDHTag,
                     uint8_t** pau8IOPDSRevision, uint8_t** pau8IOPDSTag)
{
   *pau8ModuleRevision = &au8LLDD_CCR_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_CCR_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_CCR_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_CCR_H_TAG[0];
   *pau8IOPDHRevision  = &au8LLDD_CCR_PDH_IO_H_REVISION[0];
   *pau8IOPDHTag       = &au8LLDD_CCR_PDH_IO_H_TAG[0];
   *pau8IOPDSRevision  = &au8LLDD_CCR_PDS_IO_H_REVISION[0];
   *pau8IOPDSTag       = &au8LLDD_CCR_PDS_IO_H_TAG[0];
}

/****************************************************************************/
int32_t i32CCR_EnableModuleClock(ccr_cntrl_e eCntrl, ccr_enable_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    switch (eCntrl)
    {
        case CCR_QSPI_0:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_QSPI0_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_QSPI0_GATE(1U);
                }
            }
            break;
        case CCR_QSPI_1:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_QSPI1_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_QSPI1_GATE(1U);
                }
            }
            break;
        case CCR_QSPI_INT:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_QSPI2_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_QSPI2_GATE(1U);
                }
            }
            break;
        case CCR_DMA:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_DMA_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_DMA_GATE(1U);
                }
            }
            break;
        case CCR_PARFLASH:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_PARFL_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_PARFL_GATE(1U);
                }
            }
            break;
        case CCR_DAP:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_DAP_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_DAP_GATE(1U);
                }
            }
            break;
        case CCR_GA:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_GA_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_GA_GATE(1U);
                }
            }
            break;
        case CCR_PNG:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_PNG_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_PNG_GATE(1U);
                }
            }
            break;
        case CCR_GDC_0:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_GDC0_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_GDC0_GATE(1U);
                }
            }
            break;
        case CCR_GDC_1:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_GDC1_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_GDC1_GATE(1U);
                }
            }
            break;
        case CCR_FG:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_FG_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_FG_GATE(1U);
                }
            }
            break;
        case CCR_MLB:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_MLB_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_MLB_GATE(1U);
                }
            }
            break;
        case CCR_SDRAM:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_SDRAM_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_SDRAM_GATE(1U);
                }
            }
            break;
        case CCR_SMC:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_SMC_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_SMC_GATE(1U);
                }
            }
            break;
        case CCR_I2S:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_I2S_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_I2S_GATE(1U);
                }
            }
            break;
        case CCR_HSPWM:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_HSPWM_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_HSPWM_GATE(1U);
                }
            }
            break;
        case CCR_I2SM:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_I2SM_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_I2SM_GATE(1U);
                }
            }
            break;
        case CCR_TSM:
            {
                /* Unlock CCR for writing */
                vCCR_PDS_UNLOCK();

                /* set value */
                if (eEn == CCR_ENABLE)
                {
                    vSetCCR_PERICLKGATE_CLK_TSM_GATE(0U);
                }
                else
                {
                    vSetCCR_PERICLKGATE_CLK_TSM_GATE(1U);
                }
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
int32_t i32CCR_GetEnabledModuleClock(ccr_cntrl_e eCntrl, ccr_enable_e * peEn)
{
    int32_t i32Res = C_SUCCESS;

    /* default value is disabled */
    *peEn = CCR_DISABLE;

    switch (eCntrl)
    {
        case CCR_QSPI_0:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_QSPI0_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_QSPI_1:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_QSPI1_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_QSPI_INT:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_QSPI2_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_DMA:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_DMA_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_PARFLASH:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_PARFL_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_DAP:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_DAP_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_GA:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_GA_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_PNG:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_PNG_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_GDC_0:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_GDC0_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_GDC_1:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_GDC1_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_FG:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_FG_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_MLB:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_MLB_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_SDRAM:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_SDRAM_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_SMC:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_SMC_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_I2S:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_I2S_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_HSPWM:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_HSPWM_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_I2SM:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_I2SM_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
            }
            break;
        case CCR_TSM:
            {
                if ( 0 < biGetCCR_PERICLKGATE_CLK_TSM_GATE())
                {
                    *peEn = CCR_ENABLE;
                }
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
int32_t i32CCR_SetClockFreq(ccr_cntrl_e eCntrl, ccr_clk_freq_e eFreq, ccr_modulated_clk_e eModulated)
{
    int32_t i32Res = C_SUCCESS;

    switch(eCntrl)
    {
        case CCR_QSPI_0:
            {
                if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVM2_QSPI0())
                {
                    /* Unlock CCR for writing */
                    vCCR_PDS_UNLOCK();
                    vClrCCR_CLKDIVACK_RELOADACK_MQSPI0();

                    /* Set Quad-SPI0 clock frequency */
                    vCCR_PDS_UNLOCK();
                    vSetCCR_CLKDIVM2_QSPI0(eFreq);

                    /* wait for stable clock */
                    while( 0U == biGetCCR_CLKDIVACK_RELOADACK_MQSPI0())
                    {
                        ;
                    }
                }
            }
            break;
        case CCR_QSPI_1:
            {
                if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVM2_QSPI1())
                {
                    /* Unlock CCR for writing */
                    vCCR_PDS_UNLOCK();
                    vClrCCR_CLKDIVACK_RELOADACK_MQSPI1();

                    /* Set Quad-SPI1 clock frequency */
                    vCCR_PDS_UNLOCK();
                    vSetCCR_CLKDIVM2_QSPI1(eFreq);

                    /* wait for stable clock */
                    while(0U == biGetCCR_CLKDIVACK_RELOADACK_MQSPI1())
                    {
                        ;
                    }
                }
            }
            break;
        case CCR_QSPI_INT:
            {
                if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVM2_QSPI2())
                {
                    /* Unlock CCR for writing */
                    vCCR_PDS_UNLOCK();
                    vClrCCR_CLKDIVACK_RELOADACK_MQSPI2();

                    /* Set Quad-SPI internal clock frequency */
                    vCCR_PDS_UNLOCK();
                    vSetCCR_CLKDIVM2_QSPI2(eFreq);

                    /* wait for stable clock */
                    while(0U == biGetCCR_CLKDIVACK_RELOADACK_MQSPI2())
                    {
                        ;
                    }
                }
            }
            break;
        case CCR_SDRAM:
            {
                if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVM2_SDRAMIF())
                {
                    /* Unlock CCR for writing */
                    vCCR_PDS_UNLOCK();
                    vClrCCR_CLKDIVACK_RELOADACK_MSDRAM();

                    /* Set SDRAM clock frequency */
                    vCCR_PDS_UNLOCK();
                    vSetCCR_CLKDIVM2_SDRAMIF(eFreq);

                    /* wait for stable clock */
                    while(0U == biGetCCR_CLKDIVACK_RELOADACK_MSDRAM())
                    {
                        ;
                    }
                }
            }
            break;
        case CCR_GDC_0:
            {
                if (eModulated == CCR_MODULATED)
                {
                    if (eFreq != biGetCCR_CLKDIVM1_GDC0())
                    {
                        /* Unlock CCR for writing */
                        vCCR_PDS_UNLOCK();
                        vClrCCR_CLKDIVACK_RELOADACK_MGDC0();

                        /* Set GDC0 clock frequency */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKDIVM1_GDC0(eFreq);

                        /* wait for stable clock */
                        while(0U == biGetCCR_CLKDIVACK_RELOADACK_MGDC0())
                        {
                            ;
                        }

                        /* switch to modulated clock */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKSEL_CLK_DOT0_SEL(0x01);
                    }
                }
                else
                {
                    if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVNM1_GDC0())
                    {
                        /* Unlock CCR for writing */
                        vCCR_PDS_UNLOCK();
                        vClrCCR_CLKDIVACK_RELOADACK_NMGDC0();

                        /* Set GDC0 clock frequency */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKDIVNM1_GDC0(eFreq);

                        /* wait for stable clock */
                        while(0U == biGetCCR_CLKDIVACK_RELOADACK_NMGDC0())
                        {
                            ;
                        }

                        /* switch to non modulated clock */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKSEL_CLK_DOT0_SEL(0x02);
                    }
                }
            }
            break;
        case CCR_GDC_1:
            {
                if (eModulated == CCR_MODULATED)
                {
                    if (eFreq != biGetCCR_CLKDIVM1_GDC1())
                    {
                        /* Unlock CCR for writing */
                        vCCR_PDS_UNLOCK();
                        vClrCCR_CLKDIVACK_RELOADACK_MGDC1();

                        /* Set GDC1 clock frequency */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKDIVM1_GDC1(eFreq);

                        /* wait for stable clock */
                        while(0U == biGetCCR_CLKDIVACK_RELOADACK_MGDC1())
                        {
                            ;
                        }

                        /* switch to modulated clock */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKSEL_CLK_DOT1_SEL(0x01);
                    }
                }
                else
                {
                    if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVNM1_GDC1())
                    {
                        /* Unlock CCR for writing */
                        vCCR_PDS_UNLOCK();
                        vClrCCR_CLKDIVACK_RELOADACK_NMGDC1();

                        /* Set GDC1 clock frequency */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKDIVNM1_GDC1(eFreq);

                        /* wait for stable clock */
                        while( 0U == biGetCCR_CLKDIVACK_RELOADACK_NMGDC1())
                        {
                            ;
                        }

                        /* switch to non modulated clock */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKSEL_CLK_DOT1_SEL(0x02);
                    }
                }
            }
            break;
        case CCR_I2S:
            {
                if (eModulated == CCR_MODULATED)
                {
                    if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVM3_I2S())
                    {
                        /* Unlock CCR for writing */
                        vCCR_PDS_UNLOCK();
                        vClrCCR_CLKDIVACK_RELOADACK_MI2S();

                        /* Set I2S clock frequency */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKDIVM3_I2S(eFreq);

                        /* wait for stable clock */
                        while(0U == biGetCCR_CLKDIVACK_RELOADACK_MI2S())
                        {
                            ;
                        }
                    }
                }
                else
                {
                    if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVNM3_I2S())
                    {
                        /* Unlock CCR for writing */
                        vCCR_PDS_UNLOCK();
                        vClrCCR_CLKDIVACK_RELOADACK_NMI2S();

                        /* Set I2S clock frequency */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKDIVNM3_I2S(eFreq);

                        /* wait for stable clock */
                        while(0U == biGetCCR_CLKDIVACK_RELOADACK_NMI2S())
                        {
                            ;
                        }
                    }
                }
            }
            break;
        case CCR_PARFLASH:
            {
                if (eModulated == CCR_MODULATED)
                {
                    if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVM3_PL353())
                    {
                        /* Unlock CCR for writing */
                        vCCR_PDS_UNLOCK();
                        vClrCCR_CLKDIVACK_RELOADACK_MPL353();

                        /* Set PL353 clock frequency */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKDIVM3_PL353(eFreq);

                        /* wait for stable clock */
                        while(0U == biGetCCR_CLKDIVACK_RELOADACK_MPL353())
                        {
                            ;
                        }
                    }
                }
                else
                {
                    if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVNM3_PL353())
                    {
                        /* Unlock CCR for writing */
                        vCCR_PDS_UNLOCK();
                        vClrCCR_CLKDIVACK_RELOADACK_NMPL353();

                        /* Set PL353 clock frequency */
                        vCCR_PDS_UNLOCK();
                        vSetCCR_CLKDIVNM3_PL353(eFreq);

                        /* wait for stable clock */
                        while(0U == biGetCCR_CLKDIVACK_RELOADACK_NMPL353())
                        {
                            ;
                        }

                    }
                }
            }
            break;
        case CCR_TRACE:
            {
                if (eFreq != (ccr_clk_freq_e)biGetCCR_CLKDIVNM2_TRACE())
                {
                    /* Unlock CCR for writing */
                    /* Set Quad-SPI input clock frequency */
                    vCCR_PDS_UNLOCK();
                    vSetCCR_CLKDIVNM2_TRACE((uint8_t)eFreq);

                    /* wait for stable clock */
/*                    while(0==biGetCCR_CLKDIVACK_RELOADACK_MSDRAM()){}; */
                }
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
int32_t i32CCR_SelectClockType(ccr_cntrl_e eCntrl, ccr_clock_type_e eClockType)
{
    int32_t i32Res = C_SUCCESS;

    switch(eCntrl)
    {
        case CCR_GDC_0:
            {
                switch(eClockType)
                {
                    case CCR_MODULATED_GDC0:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_DOT0_SEL(1U);
                        }
                        break;
                    case CCR_NON_MODULATED_GDC0:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_DOT0_SEL(2);
                        }
                        break;
                    case CCR_DOTCLKIN:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_DOT0_SEL(3);
                        }
                        break;
                    default:
                        {
                            i32Res = C_FAILED;
                        }
            break;
                }
            }
            break;
        case CCR_GDC_1:
            {
                switch(eClockType)
                {
                    case CCR_MODULATED_GDC0:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_DOT1_SEL(1U);
                        }
                        break;
                    case CCR_MODULATED_GDC1:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_DOT1_SEL(2);
                        }
                        break;
                    case CCR_NON_MODULATED_GDC0:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_DOT1_SEL(3);
                        }
                        break;
                    case CCR_NON_MODULATED_GDC1:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_DOT1_SEL(4);
                        }
                        break;
                    case CCR_DOTCLKIN:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_DOT1_SEL(5);
                        }
                        break;
                    default:
                        {
                            i32Res = C_FAILED;
                        }
            break;
                }
            }
            break;
        case CCR_I2S:
            {
                switch(eClockType)
                {
                    case CCR_MODULATED_I2S:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_I2S_SEL(1U);
                        }
                        break;
                    case CCR_NON_MODULATED_I2S:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_I2S_SEL(2);
                        }
                        break;
                    case CCR_I2SMCLKIN:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_I2S_SEL(3);
                        }
                        break;
                    default:
                        {
                            i32Res = C_FAILED;
                        }
            break;
                }
            }
            break;
        case CCR_320MHz:
            {
                switch(eClockType)
                {
                    case CCR_MODULATED_320MHZ:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_300_SEL(0U);
                        }
                        break;
                    case CCR_NON_MODULATED_320MHZ:
                        {
                            vCCR_PDS_UNLOCK();
                            vSetCCR_CLKSEL_CLK_300_SEL(1U);
                        }
                        break;
                    default:
                        {
                            i32Res = C_FAILED;
                        }
            break;
                }
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
void vCCR_SetPllClockStabilizationCompareValue(uint8_t u8Value)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_SBCR_PLLSTBC(u8Value);
}


/****************************************************************************/
ccr_clock_stability_e eCCR_ReadClockStability(ccr_clocks_e eClk)
{
    ccr_clock_stability_e eStability;

    switch (eClk)
    {
        case CCR_OSC10M:
            {
                if (biGetCCR_SBSR_OSC10MRDY() == 0)
                {
                    eStability = CCR_CLOCK_NOT_STABLE;
                }
                else
                {
                    eStability = CCR_CLOCK_STABLE;
                }
            }
            break;
        case CCR_OSC32K:
            {
                if (biGetCCR_SBSR_OSC32KRDY() == 0)
                {
                    eStability = CCR_CLOCK_NOT_STABLE;
                }
                else
                {
                    eStability = CCR_CLOCK_STABLE;
                }
            }
            break;
        case CCR_RC100K:
            {
                if (biGetCCR_SBSR_RC100KRDY() == 0)
                {
                    eStability = CCR_CLOCK_NOT_STABLE;
                }
                else
                {
                    eStability = CCR_CLOCK_STABLE;
                }
            }
            break;
        case CCR_MODULATED_PLL:
            {
                if (biGetCCR_SBSR_MPLLRDY() == 0)
                {
                    eStability = CCR_CLOCK_NOT_STABLE;
                }
                else
                {
                    eStability = CCR_CLOCK_STABLE;
                }
            }
            break;
        case CCR_NON_MODULATED_PLL:
            {
                if (biGetCCR_SBSR_NMPLLRDY() == 0)
                {
                    eStability = CCR_CLOCK_NOT_STABLE;
                }
                else
                {
                    eStability = CCR_CLOCK_STABLE;
                }
            }
            break;
        default:
            {
                eStability = CCR_CLOCK_STABILITY_FAIL;
            }
        break;
    }

    return eStability;
}


/****************************************************************************/
int32_t i32CCR_GenerateReset(ccr_reset_type_e eResetType)
{
    int32_t i32Res = C_SUCCESS;

    switch(eResetType)
    {
        case CCR_FULL_RST:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_RSTCR_SW_FULL_RST(0x5F);
            }
            break;
        case CCR_DBG_RST:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_RSTCR_DBGRST(0xDE);
            }
            break;
        case CCR_SW_PART_RST:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_RSTCR_SW_PART_RST(0x58);
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
__asm void __wfi(void)
{
    WFI
}


/****************************************************************************/
int32_t i32CCR_SetDeviceMode(ccr_device_mode_e eMode)
{
    int32_t i32Res = C_SUCCESS;

    switch (eMode)
    {
        case CCR_DEVICE_MODE_M_PLL:      /* M_PLL */
            /* if Device is currently performing state transition, then wait: */
            while (biGetCCR_SYSDSR_MODESTAT() == 0)
            {
                ;
            }
            if (biGetCCR_SYSDSR_MODESTAT() != 1)
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_SCR(eMode);

                while (biGetCCR_SYSDSR_MODESTAT() == 0)
                {
                    ;
                }
            }
            else
            {
                i32Res = C_FAILED;
            }
            break;
        case CCR_DEVICE_MODE_M_OSC10:    /* M_OSC10 */
            /* if Device is currently performing state transition, then wait: */
            while (biGetCCR_SYSDSR_MODESTAT() == 0)
            {
                ;
            }
            if (biGetCCR_SYSDSR_MODESTAT() != 2)
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_SCR(eMode);

                while (biGetCCR_SYSDSR_MODESTAT() == 0)
                {
                    ;
                }
            }
            else
            {
                i32Res = C_FAILED;
            }
            break;
        case CCR_DEVICE_MODE_STB_OSC10:  /* STB_OSC10 */
            vCCR_PDS_UNLOCK();
            vSetCCR_SCR(eMode);
            __wfi();
            break;
        case CCR_DEVICE_MODE_SLP_OSC10:  /* SLP_OSC10 */
            vCCR_PDS_UNLOCK();
            vSetCCR_SCR(eMode);
            __wfi();
            break;
        case CCR_DEVICE_MODE_SLP_RC10:   /* SLP_RC10 */
            vCCR_PDS_UNLOCK();
            vSetCCR_SCR(eMode);
            __wfi();
            break;
        case CCR_DEVICE_MODE_STOP_R:     /* STOP_R */
            /* if Device is currently performing state transition, then wait: */
            while (biGetCCR_SYSDSR_MODESTAT() == 0)
            {
                ;
            }
            vCCR_PDS_UNLOCK();
            vSetCCR_SCR(eMode);
            __wfi();
            break;
        case CCR_DEVICE_MODE_STOP:       /* STOP */
            /* if Device is currently performing state transition, then wait: */
            while (biGetCCR_SYSDSR_MODESTAT() == 0)
            {
                ;
            }
            vCCR_PDS_UNLOCK();
            vSetCCR_SCR(eMode);
            __wfi();
            break;
        default:
            i32Res = C_FAILED;
        break;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_EnableInterrupt(ccr_interrupts_e eInterrupt, ccr_enable_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    switch(eInterrupt)
    {
        case CCR_INTERRUPTS_STATE_CHANGE:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_INTER_MODEINTEN(eEn);
            }
            break;
        case CCR_INTERRUPTS_ALARM_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_INTER_ALARMINT0EN(eEn);
            }
            break;
        case CCR_INTERRUPTS_ALARM_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_INTER_ALARMINT1EN(eEn);
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
uint32_t u32CCR_GetInterruptStatusAll(void)
{
    return u32GetCCR_INTSR();
}


/****************************************************************************/
int32_t i32CCR_GetInterruptStatusSingle(ccr_interrupts_e eInterrupt, ccr_int_occurred_e * peIntOccurred)
{
    int32_t i32Res = C_SUCCESS;

    if (0x00 != peIntOccurred)
    {
        switch(eInterrupt)
        {
            case CCR_INTERRUPTS_STATE_CHANGE:
                {
                    *peIntOccurred = (ccr_int_occurred_e)biGetCCR_INTSR_MODEINT();
                }
                break;
            case CCR_INTERRUPTS_ALARM_0:
                {
                    *peIntOccurred = (ccr_int_occurred_e)biGetCCR_INTSR_ALARMINT0();
                }
                break;
            case CCR_INTERRUPTS_ALARM_1:
                {
                    *peIntOccurred = (ccr_int_occurred_e)biGetCCR_INTSR_ALARMINT1();
                }
                break;
            case CCR_INTERRUPTS_BECC:
                {
                    *peIntOccurred = (ccr_int_occurred_e)biGetCCR_INTSR_BKPRAM_ECCINT();
                }
                break;
            case CCR_INTERRUPTS_MECC:
                {
                    *peIntOccurred = (ccr_int_occurred_e)biGetCCR_INTSR_MM_ECCINT();
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
void vCCR_ClearInterruptsAll(void)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_INTCR(0x00030001);
}


/****************************************************************************/
int32_t i32CCR_ClearInterruptSingle(ccr_interrupts_e eInterrupt)
{
    int32_t i32Res = C_SUCCESS;

    switch(eInterrupt)
    {
        case CCR_INTERRUPTS_STATE_CHANGE:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_INTCR_MODEINTC(1U);
            }
            break;
        case CCR_INTERRUPTS_ALARM_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_INTCR_ALARMINT0C(1U);
            }
            break;
        case CCR_INTERRUPTS_ALARM_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_INTCR_ALARMINT1C(1U);
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
ccr_device_mode_e eCCR_GetCurrentDeviceMode(void)
{
    uint32_t u32DeviceMode;
    ccr_device_mode_e eResult;

    u32DeviceMode = biGetCCR_SYSDSR_MODESTAT();
    switch (u32DeviceMode)
    {
        case 0x00000001:
            {
                eResult = CCR_DEVICE_MODE_M_PLL;
            }
            break;
        case 0x00000010:
            {
                eResult = CCR_DEVICE_MODE_M_OSC10;
            }
            break;
        case 0x00000100:
            {
                eResult = CCR_DEVICE_MODE_STB_OSC10;
            }
            break;
        case 0x00001000:
            {
                eResult = CCR_DEVICE_MODE_SLP_OSC10;
            }
            break;
        case 0x00010000:
            {
                eResult = CCR_DEVICE_MODE_SLP_RC10;
            }
            break;
        case 0x00100000:
            {
                eResult = CCR_DEVICE_MODE_STOP_R;
            }
            break;
        case 0x01000000:
            {
                eResult = CCR_DEVICE_MODE_STOP;
            }
            break;
        default:
            {
                eResult = CCR_DEVICE_MODE_TRANSITION;
            }
            break;
    }
    return eResult;
}


/****************************************************************************/
void vCCR_ConfigureSSCG(ccr_sscg_congig_st * pstSSCGConfig)
{
    if (0x00 != pstSSCGConfig)
    {
        vCCR_PDS_UNLOCK();
         vSetCCR_SSCPLL_CTRL0_SSCPLL_MODTYPE( (uint8_t)(pstSSCGConfig->eModulationDirection) );

         vCCR_PDS_UNLOCK();
         vSetCCR_SSCPLL_CTRL2_SSCPLL_FNLEN( (uint8_t)(pstSSCGConfig->u8ModulationCycleLengthFractionalN) );

         vCCR_PDS_UNLOCK();
         vSetCCR_SSCPLL_CTRL2_SSCPLL_DSFT( (uint32_t)(pstSSCGConfig->u16ModulationDegree) );

         /* give reset to SSCG to apply new settings */
         vCCR_PDS_UNLOCK();
         vSetCCR_SSCPLL_CTRL0_SSCPLL_RESET(1U);
    }
}


/****************************************************************************/
void vCCR_SetWDTAlarmType(ccr_wdt_alarm_type_e eAlarmType)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG0_ALMWDT_RST_NMI(eAlarmType);
}


/****************************************************************************/
void vCCR_EnableBitErrorInjectionInRAM(ccr_enable_e eEn)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG0_BEINJB(eEn);
}


/****************************************************************************/
void vCCR_SetPositionOfBitErrorInjectionInRAM(uint8_t u8FirstPosition, uint8_t u8SecondPosition)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG0_BEPAB(u8FirstPosition);
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG0_BEPBB(u8SecondPosition);
}


/****************************************************************************/
void vCCR_SetCANMode(ccr_can_mode_e eCANMode)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG1_CANMODE(eCANMode);
}


/****************************************************************************/
void vCCR_SetECCMode(ccr_ecc_mode_e eECCMode)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG1_ECCM(eECCMode);
}


/****************************************************************************/
int32_t i32CCR_SetTBIODirection(ccr_tbio_channel_e eTBIOChannel, ccr_tbio_direction_e eDirection)
{
    int32_t i32Res = C_SUCCESS;

    switch(eTBIOChannel)
    {
        case CCR_TBIO_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG1_TBIO0_DIR(eDirection);
            }
            break;
        case CCR_TBIO_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG1_TBIO1_DIR(eDirection);
            }
            break;
        case CCR_TBIO_2:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG1_TBIO2_DIR(eDirection);
            }
            break;
        case CCR_TBIO_3:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG1_TBIO3_DIR(eDirection);
            }
            break;
        case CCR_TBIO_6:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG1_TBIO6_DIR(eDirection);
            }
            break;
        case CCR_TBIO_7:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG1_TBIO7_DIR(eDirection);
            }
            break;
        case CCR_TBIO_8:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG1_TBIO8_DIR(eDirection);
            }
            break;
        case CCR_TBIO_9:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG1_TBIO9_SEL(eDirection);
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
void vCCR_SetInputForComplexTimer4(ccr_tbin_source_ctimer4_e eSource)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG1_TBIN4_SEL(eSource);
}


/****************************************************************************/
void vCCR_SetInputForComplexTimer5(ccr_tbin_source_ctimer5_e eSource)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG1_TBIN5_SEL(eSource);
}


/****************************************************************************/
void vCCR_EnableGDC0Interface(ccr_enable_e eEn)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG1_DISP0ON(eEn);
}


/****************************************************************************/
void vCCR_EnableGDC1Interface(ccr_enable_e eEn)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG1_DISP1ON(eEn);
}


/****************************************************************************/
void vCCR_EnableGDCPanelInterface(ccr_enable_e eEn)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG1_PNLON(eEn);
}


/****************************************************************************/
void vCCR_SetGDCSynchronisation(ccr_gdc_sync_e eGDCSync)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERIC_REG1_S0EXTS1(eGDCSync);
}


/****************************************************************************/
int32_t i32CCR_SetNORAddressMask(ccr_nor_channel_e eChannel, uint16_t u16AddressMask)
{
    int32_t i32Res = C_SUCCESS;

    switch(eChannel)
    {
        case CCR_NOR_CHANNEL_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG2_ADDR_MASK0_0(u16AddressMask);
            }
            break;
        case CCR_NOR_CHANNEL_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG2_ADDR_MASK0_1(u16AddressMask);
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
int32_t i32CCR_SetNORAddressMatch(ccr_nor_channel_e eChannel, uint16_t u16AddressMatch)
{
    int32_t i32Res = C_SUCCESS;

    switch(eChannel)
    {
        case CCR_NOR_CHANNEL_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG2_ADDR_MATCH0_0(u16AddressMatch);
            }
            break;
        case CCR_NOR_CHANNEL_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG2_ADDR_MATCH0_1(u16AddressMatch);
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
int32_t i32CCR_SetNANDAddressMask(ccr_nand_channel_e eChannel, uint16_t u16AddressMask)
{
    int32_t i32Res = C_SUCCESS;

    switch(eChannel)
    {
        case CCR_NAND_CHANNEL_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG3_ADDR_MASK1_0(u16AddressMask);
            }
            break;
        case CCR_NAND_CHANNEL_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG3_ADDR_MASK1_1(u16AddressMask);
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
int32_t i32CCR_SetNANDAddressMatch(ccr_nand_channel_e eChannel, uint16_t u16AddressMatch)
{
    int32_t i32Res = C_SUCCESS;

    switch(eChannel)
    {
        case CCR_NAND_CHANNEL_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG3_ADDR_MATCH1_0(u16AddressMatch);
            }
            break;
        case CCR_NAND_CHANNEL_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG3_ADDR_MATCH1_1(u16AddressMatch);
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
void  vCCR_SetNORChipSelect(uint32_t u32Value)
{
    vCCR_PDS_UNLOCK();

    /* write complete register for NOT chip select:*/
    vSetCCR_GENERIC_REG2(u32Value);
}


/****************************************************************************/
void  vCCR_SetNANDChipSelect(uint32_t u32Value)
{
    vCCR_PDS_UNLOCK();

    /* write complete register for NOT chip select:*/
    vSetCCR_GENERIC_REG3(u32Value);
}


/****************************************************************************/
int32_t i32CCR_EnableSRAMBitErrorInspection(ccr_sram_channel_e eChannel, ccr_enable_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    switch(eChannel)
    {
        case CCR_SRAM_CHANNEL_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG4_BEINJ0(eEn);
            }
            break;
        case CCR_SRAM_CHANNEL_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG4_BEINJ1(eEn);
            }
            break;
        case CCR_SRAM_CHANNEL_2:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG5_BEINJ2(eEn);
            }
            break;
        case CCR_SRAM_CHANNEL_3:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERIC_REG5_BEINJ3(eEn);
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
int32_t i32CCR_SetSRAMBitErrorInspectionConfiguration(ccr_sram_channel_e eChannel, ccr_sram_bit_error_insp_config_st * pstConfig)
{
    int32_t i32Res = C_SUCCESS;

    if (0x00 != pstConfig)
    {
        switch(eChannel)
        {
            case CCR_SRAM_CHANNEL_0:
                {
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG4_BEPA0(pstConfig -> u8PosFirstError);
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG4_BEPB0(pstConfig -> u8PosSecondError);
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG4_BEBSEL0(pstConfig -> u8ByteSelect);
                }
                break;
            case CCR_SRAM_CHANNEL_1:
                {
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG4_BEPA1(pstConfig -> u8PosFirstError);
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG4_BEPB1(pstConfig -> u8PosSecondError);
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG4_BEBSEL1(pstConfig -> u8ByteSelect);
                }
                break;
            case CCR_SRAM_CHANNEL_2:
                {
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG5_BEPA2(pstConfig -> u8PosFirstError);
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG5_BEPB2(pstConfig -> u8PosSecondError);
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG5_BEBSEL2(pstConfig -> u8ByteSelect);
                }
                break;
            case CCR_SRAM_CHANNEL_3:
                {
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG5_BEPA3(pstConfig -> u8PosFirstError);
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG5_BEPB3(pstConfig -> u8PosSecondError);
                    vCCR_PDS_UNLOCK();
                    vSetCCR_GENERIC_REG5_BEBSEL3(pstConfig -> u8ByteSelect);
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
void vCCR_ClearWDTAlarm(void)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERICAC_REG0_WDT_ALMCLR(1U);
}


/****************************************************************************/
void vCCR_ClearErrorIrgFlagOfBackupRAM(void)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERICAC_REG0_ECCECLRB(1U);
}


/****************************************************************************/
void vCCR_ClearWarningIrgFlagOfBackupRAM(void)
{
    vCCR_PDS_UNLOCK();
    vSetCCR_GENERICAC_REG0_ECCWCLRB(1U);
}


/****************************************************************************/
int32_t i32CCR_ClearErrorIrgFlagOfSRAM(ccr_sram_channel_e eChannel)
{
    int32_t i32Res = C_SUCCESS;

    vCCR_PDS_UNLOCK();
    vSetCCR_GENERICAC_REG0_ECCECLRB(1U);

    switch(eChannel)
    {
        case CCR_SRAM_CHANNEL_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_ECCECLRS(0x1);
            }
            break;
        case CCR_SRAM_CHANNEL_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_ECCECLRS(0x2);
            }
            break;
        case CCR_SRAM_CHANNEL_2:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_ECCECLRS(0x4);
            }
            break;
        case CCR_SRAM_CHANNEL_3:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_ECCECLRS(0x8);
            }
            break;
        default:
            {
                vCCR_PDS_UNLOCK();
            }
            break;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_ClearWarningIrgFlagOfSRAM(ccr_sram_channel_e eChannel)
{
    int32_t i32Res = C_SUCCESS;

    vCCR_PDS_UNLOCK();
    vSetCCR_GENERICAC_REG0_ECCECLRB(1U);

    switch (eChannel)
    {
        case CCR_SRAM_CHANNEL_0:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_ECCWCLRS(0x1);
            }
            break;
        case CCR_SRAM_CHANNEL_1:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_ECCWCLRS(0x2);
            }
            break;
        case CCR_SRAM_CHANNEL_2:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_ECCWCLRS(0x4);
            }
            break;
        case CCR_SRAM_CHANNEL_3:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_ECCWCLRS(0x8);
            }
            break;
        default:
            {
                vCCR_PDS_UNLOCK();
            }
            break;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_IssueSynchronPulseToCTimer(ccr_complex_timer_e eComplexTimer)
{
    int32_t i32Res = C_SUCCESS;

    vCCR_PDS_UNLOCK();
    vSetCCR_GENERICAC_REG0_ECCECLRB(1U);

    switch (eComplexTimer)
    {
        case CCR_COMPLEX_TIMER_0_TO_5:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_CPXTSYN_PM(1U);
            }
            break;
        case CCR_COMPLEX_TIMER_6_TO_9:
            {
                vCCR_PDS_UNLOCK();
                vSetCCR_GENERICAC_REG0_CPXTSYN_PNM(1U);
            }
            break;
        default:
            {
                vCCR_PDS_UNLOCK();
            }
            break;
    }

    return i32Res;
}


/****************************************************************************/
ccr_enable_e eCCR_GetWDTAlarmStatusBit(void)
{
    return (ccr_enable_e)biGetCCR_GENERICSTAT_REG0_WDT_ALARM();
}


/****************************************************************************/
ccr_enable_e eCCR_GetIRQErrorFlafForBackupRAM(void)
{
    return (ccr_enable_e)biGetCCR_GENERICSTAT_REG0_ECCERRB();
}


/****************************************************************************/
ccr_enable_e eCCR_GetIRQWarningFlafForBackupRAM(void)
{
    return (ccr_enable_e)biGetCCR_GENERICSTAT_REG0_ECCWRNB();
}


/****************************************************************************/
uint8_t u8CCR_GetPosOfBitErrorInBackupRAM(void)
{
    return (uint8_t)biGetCCR_GENERICSTAT_REG0_BEPOSB();
}


/****************************************************************************/
ccr_enable_e eCCR_GetLastCheckResultForBackupRAM(void)
{
    return (ccr_enable_e)biGetCCR_GENERICSTAT_REG0_BERESB();
}


/****************************************************************************/
ccr_enable_e eCCR_GetDebuggerCR4PowerDownRequestStatus(void)
{
    return (ccr_enable_e)biGetCCR_GENERICSTAT_REG0_CR4DBGNOPWRDWN();
}


/****************************************************************************/
int32_t i32CCR_GetSRAMIrgErrorCondition(ccr_sram_channel_e eChannel, ccr_enable_e * peEn)
{
    uint32_t u32Enb = 0U;
    int32_t  i32Res = C_SUCCESS;

    if (0x00 != peEn)
    {
        switch(eChannel)
        {
            case CCR_SRAM_CHANNEL_0:
                {
                    u32Enb = 0x1U & biGetCCR_GENERICSTAT_REG1_ECCERRS();
                }
                break;
            case CCR_SRAM_CHANNEL_1:
                {
                    u32Enb = ( 0x2U & biGetCCR_GENERICSTAT_REG1_ECCERRS() ) >> 1U;
                }
                break;
            case CCR_SRAM_CHANNEL_2:
                {
                    u32Enb = ( 0x4U & biGetCCR_GENERICSTAT_REG1_ECCERRS() ) >> 2U;
                }
                break;
            case CCR_SRAM_CHANNEL_3:
                {
                    u32Enb = ( 0x8U & biGetCCR_GENERICSTAT_REG1_ECCERRS() ) >> 3U;
                }
                break;
            default:
                {
                    i32Res = C_FAILED;
                }
                break;
        }
        if (C_SUCCESS == i32Res)
        {
            *peEn = (ccr_enable_e) u32Enb;
        }
    }
    else
    {
        i32Res = C_FAILED;

    }
    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_GetSRAMIrgWarningCondition(ccr_sram_channel_e eChannel, ccr_enable_e * peEn)
{
    uint32_t u32Enb = 0U;
    int32_t  i32Res = C_SUCCESS;

    if (0x00 != peEn)
    {
        switch(eChannel)
        {
            case CCR_SRAM_CHANNEL_0:
                {
                    u32Enb = 0x1U & biGetCCR_GENERICSTAT_REG1_ECCWRNS();
                }
                break;
            case CCR_SRAM_CHANNEL_1:
                {
                    u32Enb = ( 0x2U & biGetCCR_GENERICSTAT_REG1_ECCWRNS() ) >> 1U;
                }
                break;
            case CCR_SRAM_CHANNEL_2:
                {
                    u32Enb = ( 0x4U & biGetCCR_GENERICSTAT_REG1_ECCWRNS() ) >> 2U;
                }
                break;
            case CCR_SRAM_CHANNEL_3:
                {
                    u32Enb = ( 0x8U & biGetCCR_GENERICSTAT_REG1_ECCWRNS() ) >> 3U;
                }
                break;
            default:
                {
                    i32Res = C_FAILED;
                }
                break;
        }
        if (C_SUCCESS == i32Res)
        {
            *peEn = (ccr_enable_e) u32Enb;
        }
    }
    else
    {
        i32Res = C_FAILED;

    }
    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_GetSRAMPositionOfBitError(ccr_sram_channel_e eChannel, uint8_t * pu8Position)
{
    uint32_t u32Position = 0U;
    int32_t i32Res = C_SUCCESS;

    if (0x00 != pu8Position)
    {
        switch(eChannel)
        {
            case CCR_SRAM_CHANNEL_0:
                {
                    u32Position = 0x1FU & biGetCCR_GENERICSTAT_REG1_BEPOSS();
                }
                break;
            case CCR_SRAM_CHANNEL_1:
                {
                    u32Position = 0x1FU & (biGetCCR_GENERICSTAT_REG1_BEPOSS() >> 5);
                }
                break;
            case CCR_SRAM_CHANNEL_2:
                {
                    u32Position = 0x1FU & (biGetCCR_GENERICSTAT_REG1_BEPOSS() >> 10);
                }
                break;
            case CCR_SRAM_CHANNEL_3:
                {
                    u32Position = 0x1FU & (biGetCCR_GENERICSTAT_REG1_BEPOSS() >> 15);
                }
                break;
            default:
                {
                    i32Res = C_FAILED;
                }
                break;
        }
        if (C_SUCCESS == i32Res)
        {
            *pu8Position = (uint8_t) u32Position;
        }
    }
    else
    {
        i32Res = C_FAILED;

    }
    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_GetSRAMLastCheckResult(ccr_sram_channel_e eChannel, ccr_enable_e * peEn)
{
    uint32_t u32Enb = 0U;
    int32_t  i32Res = C_SUCCESS;

    if (0x00 != peEn)
    {
        switch(eChannel)
        {
            case CCR_SRAM_CHANNEL_0:
                {
                    u32Enb = 0x1U & biGetCCR_GENERICSTAT_REG1_BERESS();
                }
                break;
            case CCR_SRAM_CHANNEL_1:
                {
                    u32Enb = ( 0x2U & biGetCCR_GENERICSTAT_REG1_BERESS() ) >> 1U;
                }
                break;
            case CCR_SRAM_CHANNEL_2:
                {
                    u32Enb = ( 0x4U & biGetCCR_GENERICSTAT_REG1_BERESS() ) >> 2U;
                }
                break;
            case CCR_SRAM_CHANNEL_3:
                {
                    u32Enb = ( 0x8U & biGetCCR_GENERICSTAT_REG1_BERESS() ) >> 3U;
                }
                break;
            default:
                {
                    i32Res = C_FAILED;
                }
                break;
        }
        if (C_SUCCESS == i32Res)
        {
            *peEn = (ccr_enable_e) u32Enb;
        }
    }
    else
    {
        i32Res = C_FAILED;

    }
    return i32Res;
}


/****************************************************************************/
ccr_device_version_e eCCR_GetDeviceVersion(void)
{
    return (ccr_device_version_e)biGetPDHR_VER_VER();
}


/****************************************************************************/
ccr_SIPflash_size_e eCCR_GetSIPFlashSize(void)
{
    return (ccr_SIPflash_size_e)biGetPDHR_VER_FLASH_SIZE();
}

/****************************************************************************/
ccr_enable_e eCCR_GeCR4DebugStatus(void)
{
    uint32_t      u32Cr4Dbg;
    ccr_enable_e  eResult;

    /* Check the JTAG port control-bit value */
    u32Cr4Dbg = biGetPDHR_DBG_CR4DEBUG();

    /* if bit value is '1' - JTAG is Disabled */
    if(CCR_DEBUG_CTRL_BIT == (u32Cr4Dbg & CCR_DEBUG_CTRL_BIT))
    {
        eResult = CCR_DISABLE;
    }
    else   /* if bit value is '0' - JTAG is Enabled */
    {
        eResult = CCR_ENABLE;
    }
    return eResult;
}

/****************************************************************************/
int32_t i32CCR_EnableR4DebugPort(ccr_processor_device_e eProcessorType, ccr_enable_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    switch(eProcessorType)
    {
        case CCR_CR4:
            {
                vCCR_PDH_UNLOCK();
                if (CCR_ENABLE == eEn)
                {
                    vSetPDHR_DBG_CR4DEBUG((uint16_t)CCR_DISABLE);
                }
                else
                {
                    vSetPDHR_DBG_CR4DEBUG((uint16_t)CCR_ENABLE);
                }
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
int32_t i32CCR_SetVRegCurrentTrim(ccr_vreg_current_trim_e eValue)
{
    int32_t i32Res = C_SUCCESS;

    if (eValue <= CCR_VREG_CURRENT_TRIM_M_10_PROZ)
    {
        vCCR_PDH_UNLOCK();
        vSetPDHR_VREGCR_VREG_IT(eValue);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_SetVRegRefVoltageTrim(ccr_vreg_ref_voltage_trim_e eValue)
{
    int32_t i32Res = C_SUCCESS;

    if (eValue <= CCR_VREG_REF_VOLTAGE_TRIM_P_0_5_PROZ)
    {
        vCCR_PDH_UNLOCK();
        vSetPDHR_VREGCR_VREG_VT(eValue);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_SetVRegTemperatureTrim(ccr_vreg_temperature_trim_e eValue)
{
    int32_t i32Res = C_SUCCESS;

    if (eValue <= CCR_VREG_TEMPERATURE_TRIM_M_25_DEGC)
    {
        vCCR_PDH_UNLOCK();
        vSetPDHR_VREGCR_VREG_TT(eValue);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_SetOscAdjustment(ccr_osc_adjustment_e eValue)
{
    int32_t i32Res = C_SUCCESS;

    if (eValue <= CCR_OSC_ADJUSTMENT_M_1)
    {
        vCCR_PDH_UNLOCK();
        vSetPDHR_ANACR_RCOSC_ADJUST(eValue);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_SetThresholdPowerGoodSensing(ccr_threshold_power_good_sensing_e eValue)
{
    int32_t i32Res = C_SUCCESS;

    if (eValue <= CCR_POWER_GOOD_SENSING_4)
    {
        vCCR_PDH_UNLOCK();
        vSetPDHR_ANACR_LVD_THRSH(eValue);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32CCR_SetAlarmComparatorThreshold(ccr_alarm_no_e eAlarmNo, uint8_t u8Value)
{
    int32_t i32Res = C_SUCCESS;

    if (u8Value <= MAX_ALARM_THRESHOLD)
    {
        vCCR_PDH_UNLOCK();
        if (CCR_ALARM_0 == eAlarmNo)
        {
            vSetPDHR_ALAMCR_ALM_THRSH0(u8Value);
        }
        else
        {
            vSetPDHR_ALAMCR_ALM_THRSH1(u8Value);
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
void vCCR_EnableAlarm(ccr_alarm_no_e eAlarmNo, ccr_enable_e eEn)
{
    vCCR_PDH_UNLOCK();

    if (CCR_ALARM_0 == eAlarmNo)
    {
        vSetPDHR_ALAMCR_ALM_EN_0(eEn);
    }
    else
    {
        vSetPDHR_ALAMCR_ALM_EN_1(eEn);
    }
}

/****************************************************************************/
int32_t i32CCR_EnableClockSupervisor(ccr_clocks_e eClocks, ccr_enable_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    if (eClocks <= CCR_OSC32K)
    {
        switch (eClocks)
        {
            case CCR_OSC10M:
                {
                    vCCR_PDH_UNLOCK();
                    vSetPDHR_CSVOSC10M_CSV_OSC10MEN((uint16_t)eEn);
                }
                break;
            case CCR_OSC32K:
                {
                    vCCR_PDH_UNLOCK();
                    vSetPDHR_CSVOSC32KEN_CSV_OSC32KEN((uint8_t)eEn);
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
void vCCR_EnableOSC10MClockSupervisorOutputResetFunction(ccr_enable_e eEn)
{
    vCCR_PDH_UNLOCK();
    vSetPDHR_CSVOSC10M_CSV_OSC10MRST(eEn);
}


/****************************************************************************/
void vCCR_EnableOSC32KHz(ccr_enable_e eEn)
{
    vCCR_PDH_UNLOCK();
    vSetPDHR_CFGR_OSC32KD(eEn);
}


/****************************************************************************/
void vCCR_ConfigureSmcIOLevel(ccr_smc_io_level_e eLevel)
{
    vCCR_PDH_UNLOCK();
    vSetPDHR_CFGR_SMC3VONLY(eLevel);
}


/****************************************************************************/
int32_t i32CCR_SetClockStabilizationCompareValue(ccr_clocks_e eClocks, uint8_t u8Value)
{
    int32_t i32Res = C_SUCCESS;

    if (eClocks <= CCR_OSC32K)
    {
        switch (eClocks)
        {
            case CCR_OSC10M:
                {
                    vCCR_PDH_UNLOCK();
                    vSetPDHR_SBCR_OSC10MSTBC(u8Value);
                }
                break;
            case CCR_OSC32K:
                {
                    vCCR_PDH_UNLOCK();
                    vSetPDHR_SBCR_OSC32KSTBC(u8Value);
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
uint16_t u16CCR_GetBootOptions(void)
{
    return u16GetPDHR_BOOTOPT();
}


/****************************************************************************/
uint32_t u32CCR_GetSystemIntStatusAll(void)
{
    return u32GetPDHR_INTSR();
}


/****************************************************************************/
ccr_enable_e eCCR_GetSystemIntStatusSingle(ccr_system_interrupt_e eInt)
{
    ccr_enable_e eEn;

    switch(eInt)
    {
        case CCR_OSC10M_CLOCK_MISSING_INT:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_CSV10MINT();
            }
            break;
        case CCR_OSC32K_CLOCK_MISSING_INT:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_CSV32KINT();
            }
            break;
        case CCR_EROR_INT_0:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_ERRINT0();
            }
            break;
        case CCR_EROR_INT_1:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_ERRINT1();
            }
            break;
        case CCR_EROR_INT_2:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_ERRINT2();
            }
            break;
        case CCR_BACKUP_ECC_RAM_INT:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_BKPRAM_ECCNMI();
            }
            break;
        case CCR_MAIN_MEMORY_ECC_RAM_INT:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_MM_ECCNMI();
            }
            break;
        case CCR_STPU_INT:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_STPU_NMI();
            }
            break;
        case CCR_WDT_INT:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_WDT_NMI();
            }
            break;
        case CCR_IO_INT:
            {
                eEn = (ccr_enable_e)biGetPDHR_INTSR_IO_NMI();
            }
            break;
        default:
            {
                eEn = CCR_DISABLE;
            }
            break;
    }

    return eEn;
}


/****************************************************************************/
int32_t i32CCR_ClearSystemIntStatusSingle(ccr_system_interrupt_e eInt)
{
    int32_t i32Res = C_SUCCESS;

    switch(eInt)
    {
        case CCR_OSC10M_CLOCK_MISSING_INT:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_INTCR_CSV10MINTC(1U);
            }
            break;
        case CCR_OSC32K_CLOCK_MISSING_INT:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_INTCR_CSV32KINTC(1U);
            }
            break;
        case CCR_EROR_INT_0:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_INTCR_ERRINT0C(1U);
            }
            break;
        case CCR_EROR_INT_1:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_INTCR_ERRINT1C(1U);
            }
            break;
        case CCR_EROR_INT_2:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_INTCR_ERRINT2C(1U);
            }
            break;
        case CCR_IO_INT:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_INTCR_IO_NMIC(1U);
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
int32_t i32CCR_EnableECCInterrupt(ccr_ecc_e eEccType, ccr_ecc_interrupt_type_e eEccIntType)
{
    int32_t i32Res = C_SUCCESS;

    switch(eEccType)
    {
        case CCR_BACKUP_RAM_ECC:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_ECCEN_BKPRAM_ECCEN(eEccIntType);
            }
            break;
        case CCR_MAIN_MEMORY_ECC:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_ECCEN_MM_ECCEN(eEccIntType);
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
uint8_t u8CCR_GetDeviceModesAll(void)
{
    return u8GetPDHR_PRVSTATE();
}


/****************************************************************************/
ccr_enable_e eCCR_GetDeviceModesSingle(ccr_modes_e eMode)
{
    ccr_enable_e eActive;

    switch(eMode)
    {
        case CCR_STB_MODE:
            {
                eActive = (ccr_enable_e)biGetPDHR_PRVSTATE_STB_MODE();
            }
            break;
        case CCR_SLPOSC10_MODE:
            {
                eActive = (ccr_enable_e)biGetPDHR_PRVSTATE_SLPOSC10_MODE();
            }
            break;
        case CCR_SLPRCOSC_MODE:
            {
                eActive = (ccr_enable_e)biGetPDHR_PRVSTATE_SLPRCOSC_MODE();
            }
            break;
        case CCR_STOPR_MODE:
            {
                eActive = (ccr_enable_e)biGetPDHR_PRVSTATE_STOPR_MODE();
            }
            break;
        case CCR_STOP_MODE:
            {
                eActive = (ccr_enable_e)biGetPDHR_PRVSTATE_STOP_MODE();
            }
            break;
        default:
            {
                eActive = CCR_DISABLE;
            }
            break;
    }

    return eActive;
}


/****************************************************************************/
int32_t i32CCR_EnableWakeupSource(ccr_wakeup_source_e eSource, ccr_enable_e eEn)
{
    int32_t i32Res = C_SUCCESS;

    switch(eSource)
    {
        case CCR_WAKEUP_SOURCE_0:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAKINTEN0(eEn);
            }
            break;
        case CCR_WAKEUP_SOURCE_1:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAKINTEN1(eEn);
            }
            break;
        case CCR_WAKEUP_SOURCE_2:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAKINTEN2(eEn);
            }
            break;
        case CCR_WAKEUP_SOURCE_3:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAKINTEN3(eEn);
            }
            break;
        case CCR_WAKEUP_SOURCE_4:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAKINTEN4(eEn);
            }
            break;
        case CCR_WAKEUP_SOURCE_5:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAKINTEN5(eEn);
            }
            break;
        case CCR_WAKEUP_SOURCE_6:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAKINTEN6(eEn);
            }
            break;
        case CCR_WAKEUP_SOURCE_7:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAKINTEN7(eEn);
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
int32_t i32CCR_SetWakeupAttribute(ccr_wakeup_source_e eSource, ccr_wakeup_attribute_e eAttribute)
{
    int32_t i32Res = C_SUCCESS;

    switch(eSource)
    {
        case CCR_WAKEUP_SOURCE_0:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAK_SEL0(eAttribute);
            }
            break;
        case CCR_WAKEUP_SOURCE_1:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAK_SEL1(eAttribute);
            }
            break;
        case CCR_WAKEUP_SOURCE_2:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAK_SEL2(eAttribute);
            }
            break;
        case CCR_WAKEUP_SOURCE_3:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAK_SEL3(eAttribute);
            }
            break;
        case CCR_WAKEUP_SOURCE_4:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAK_SEL4(eAttribute);
            }
            break;
        case CCR_WAKEUP_SOURCE_5:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAK_SEL5(eAttribute);
            }
            break;
        case CCR_WAKEUP_SOURCE_6:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAK_SEL6(eAttribute);
            }
            break;
        case CCR_WAKEUP_SOURCE_7:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_IOWKP_CFG_WAK_SEL7(eAttribute);
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
uint16_t u16CCR_GetWakeupSourceInterruptAll(ccr_wakeup_source_e eSource)
{
    return u16GetPDHR_WAKINTS();
}


/****************************************************************************/
ccr_enable_e eCCR_GetWakeupSourceInterruptSingle(ccr_wakeup_source_e eSource)
{
    ccr_enable_e eInterruptOccur;

    switch(eSource)
    {
        case CCR_WAKEUP_SOURCE_0:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_WAKINTS0();
            }
            break;
        case CCR_WAKEUP_SOURCE_1:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_WAKINTS1();
            }
            break;
        case CCR_WAKEUP_SOURCE_2:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_WAKINTS2();
            }
            break;
        case CCR_WAKEUP_SOURCE_3:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_WAKINTS3();
            }
            break;
        case CCR_WAKEUP_SOURCE_4:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_WAKINTS4();
            }
            break;
        case CCR_WAKEUP_SOURCE_5:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_WAKINTS5();
            }
            break;
        case CCR_WAKEUP_SOURCE_6:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_WAKINTS6();
            }
            break;
        case CCR_WAKEUP_SOURCE_7:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_WAKINTS7();
            }
            break;
        case CCR_WAKEUP_SOURCE_NMI:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_NMI();
            }
            break;
        case CCR_WAKEUP_SOURCE_ALARM:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_ALARM();
            }
            break;
        case CCR_WAKEUP_SOURCE_RTC:
            {
                eInterruptOccur = (ccr_enable_e)biGetPDHR_WAKINTS_RTC();
            }
            break;
        default:
            {
                eInterruptOccur = CCR_DISABLE;
            }
            break;
    }

    return eInterruptOccur;
}


/****************************************************************************/
int32_t i32CCR_ClearWakeupInterruptSource(ccr_wakeup_source_e eSource)
{
    int32_t i32Res = C_SUCCESS;

    switch(eSource)
    {
        case CCR_WAKEUP_SOURCE_0:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_WAKINTC0(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_1:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_WAKINTC1(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_2:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_WAKINTC2(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_3:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_WAKINTC3(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_4:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_WAKINTC4(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_5:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_WAKINTC5(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_6:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_WAKINTC6(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_7:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_WAKINTC7(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_NMI:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_NMI_SC(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_ALARM:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_ALARM_SC(1U);
            }
            break;
        case CCR_WAKEUP_SOURCE_RTC:
            {
                vCCR_PDH_UNLOCK();
                vSetPDHR_WAKINTC_RTC_SC(1U);
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
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */
/****************************************************************************/

/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :   Deactivated:
** |     Not requested Rules:
** |         Rule 2.4  [A] : disable possible occurrence of 'commented out' code
** |         Rule 5.7  [A] : disable No reuse of identifiers
** |
** |     Requested Rules:
** |         Rule 1.1  [R] : ISO 9899:1990 C conformance w/o extensions
** |                         Used for asm
** |         Rule 8.1 [R] :  Restrict implicit conversions for integer type expressions:
** |                         Used for asm
** |         Rule 10.1 [R] : Restrict implicit conversions for integer type expressions:
** |                         Used to have access to register bits of I/O header files
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************/
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

