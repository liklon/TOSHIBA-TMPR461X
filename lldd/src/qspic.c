/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : QSPI controler low level register access
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : QSPI
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.40 $
*   DATE        : $Date: 2015/05/18 13:49:55 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "qspic_io.h"                   /* Own definitions */
#include "qspic.h"                      /* Own definitions */

/*********************************************/

/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_QSPIC_C_REVISION     "$Revision: 1.40 $"
#define LLDD_QSPIC_C_TAG          "$Name: LLDD_1_6 $"

#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1771  /* Rule 2.4  [A] : No `commented out' sections of code */
  #pragma ghs nowarning 1723  /* Rule 5.6  [A] : No identifiers with the same name in different name spaces except for struct and union members.. */
  #pragma ghs nowarning 1834  /* Rule 11.3 [A] : disable casting error */
  #pragma ghs nowarning 1835  /* Rule 11.4 [A] :  allow cast from type "type" to type "type" */
  #pragma ghs nowarning 1877  /* Rule 11.3 [A] : disable casting error */

  #pragma ghs nowarning 1864  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1865  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1866  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1867  /* Rule 10.1 [R] : disable type conversion not allowed for usage of enums for io header files */
  #pragma ghs nowarning 1847  /* Rule 10.3 [R] : disable casting error */
  #pragma ghs nowarning 1752  /* Rule 17.4 [R] : disable "pointer arithmetic not allowed"  for usage of io header files */
  #pragma ghs nowarning 1858  /* Rule 17.4 [R] : allow access to data under pointer by array (used forc copy) */
 #endif


/* definitions used for setting the Program Access Control Register 1 */
#define QSPIC_PACTRL_SEC_BUF_CNT_MASK          0xFF000000U
#define QSPIC_PACTRL_SEC_BUF_CNT_SHIFT         24U
#define QSPIC_PACTRL_PRI_BUF_CNT_MASK          0x00070000U
#define QSPIC_PACTRL_PRI_BUF_CNT_SHIFT         16U
#define QSPIC_PACTRL_SEC_BUF_EN_BIT            0x00000020U
#define QSPIC_PACTRL_PRI_EN_BIT                0x00000010U
#define QSPIC_PACTRL_SPI_CS_DEV1_BIT           0x2U
#define QSPIC_PACTRL_SPI_CYC_GO_BIT            0x00000001U

#define QSPIC_PACTRL_PRI_BUF_CNT_1             0x00010000U
#define QSPIC_PACTRL_PRI_BUF_CNT_2             0x00020000U
#define QSPIC_PACTRL_PRI_BUF_CNT_3             0x00030000U
#define QSPIC_PACTRL_PRI_BUF_CNT_4             0x00040000U
#define QSPIC_PACTRL_PRI_BUF_CNT_5             0x00050000U
#define QSPIC_PACTRL_SEC_BUF_CNT_1             0x01000000U
#define QSPIC_PACTRL_SEC_BUF_CNT_2             0x02000000U
#define QSPIC_PACTRL_SEC_BUF_CNT_3             0x03000000U

/*********************************************/

/**********************************************
*  Static variables and forward declarations  *
**********************************************/

static uint8_t au8LLDD_QSPIC_C_REVISION[]    = LLDD_QSPIC_C_REVISION;
static uint8_t au8LLDD_QSPIC_C_TAG[]         = LLDD_QSPIC_C_TAG;
static uint8_t au8LLDD_QSPIC_H_REVISION[]    = LLDD_QSPIC_H_REVISION;
static uint8_t au8LLDD_QSPIC_H_TAG[]         = LLDD_QSPIC_H_TAG;
static uint8_t au8LLDD_QSPIC_IO_H_REVISION[] = LLDD_QSPIC_IO_H_REVISION;
static uint8_t au8LLDD_QSPIC_IO_H_TAG[]      = LLDD_QSPIC_IO_H_TAG;

/*********************************************/

static qspi_AddrByte_e ePrgAddressByteCnt = QSPI_ADDR_3BYTE;

/**********************************************
*        Exported function definition         *
**********************************************/

void vQSPIC_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                       uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                       uint8_t** pau8IORevision, uint8_t** pau8IOTag)
{
   *pau8ModuleRevision = &au8LLDD_QSPIC_C_REVISION[0];
   *pau8ModuleTag      = &au8LLDD_QSPIC_C_TAG[0];
   *pau8HeaderRevision = &au8LLDD_QSPIC_H_REVISION[0];
   *pau8HeaderTag      = &au8LLDD_QSPIC_H_TAG[0];
   *pau8IORevision     = &au8LLDD_QSPIC_IO_H_REVISION[0];
   *pau8IOTag          = &au8LLDD_QSPIC_IO_H_TAG[0];
}


/****************************************************************************/

int32_t i32QSPIC_ConfigureDirectControl(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_directconfig_st *pstDirConf)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_FlshMemMap0_FBA(eController,     pstDirConf->u16FlashBaseAddress);
                    vSetQSPIC_FlshMemMap0_FDEN(eController,    pstDirConf->eFlashDensity);
                    vSetQSPIC_FlshMemMap0_RE(eController,      pstDirConf->eEnableMemMapRd);
                    vSetQSPIC_DirAccCtrl0_PollWIP(eController, pstDirConf->eWIPEnable);
                    vSetQSPIC_DirAccCtrl0_SCSD(eController,    pstDirConf->u8CSTime);
                    vSetQSPIC_DirAccCtrl0_SDCE(eController,    pstDirConf->eEdge);

                    /* Direct read Control Register */
                    vSetQSPIC_DirRdCtrl0_SpiRdCmdOp    (eController, pstDirConf->stRdCtrl.eCmd);
                    vSetQSPIC_DirRdCtrl0_SpiDmyByteCnt (eController, pstDirConf->stRdCtrl.u32DummyByteCnt);
                    vSetQSPIC_DirRdCtrl0_SpiAddrByteCnt(eController, pstDirConf->stRdCtrl.eAddrByteCnt);
                    vSetQSPIC_DirRdCtrl0_SpiDatIOCtrl  (eController, pstDirConf->stRdCtrl.eSpiDatIOCtrl);
                    vSetQSPIC_DirRdCtrl0_SpiDmyIOCtrl  (eController, pstDirConf->stRdCtrl.eSpiDmyIOCtrl);
                    vSetQSPIC_DirRdCtrl0_SpiAdrIOCtrl  (eController, pstDirConf->stRdCtrl.eSpiAdrIOCtrl);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_FlshMemMap1_FBA(eController,     pstDirConf->u16FlashBaseAddress);
                    vSetQSPIC_FlshMemMap1_FDEN(eController,    pstDirConf->eFlashDensity);
                    vSetQSPIC_FlshMemMap1_RE(eController,      pstDirConf->eEnableMemMapRd);
                    vSetQSPIC_DirAccCtrl1_PollWIP(eController, pstDirConf->eWIPEnable);
                    vSetQSPIC_DirAccCtrl1_SCSD(eController,    pstDirConf->u8CSTime);
                    vSetQSPIC_DirAccCtrl1_SDCE(eController,    pstDirConf->eEdge);

                    /* Direct read Control Register */
                    vSetQSPIC_DirRdCtrl1_SpiRdCmdOp    (eController, pstDirConf->stRdCtrl.eCmd);
                    vSetQSPIC_DirRdCtrl1_SpiDmyByteCnt (eController, pstDirConf->stRdCtrl.u32DummyByteCnt);
                    vSetQSPIC_DirRdCtrl1_SpiAddrByteCnt(eController, pstDirConf->stRdCtrl.eAddrByteCnt);
                    vSetQSPIC_DirRdCtrl1_SpiDatIOCtrl  (eController, pstDirConf->stRdCtrl.eSpiDatIOCtrl);
                    vSetQSPIC_DirRdCtrl1_SpiDmyIOCtrl  (eController, pstDirConf->stRdCtrl.eSpiDmyIOCtrl);
                    vSetQSPIC_DirRdCtrl1_SpiAdrIOCtrl  (eController, pstDirConf->stRdCtrl.eSpiAdrIOCtrl);
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

int32_t i32QSPIC_ConfigurePrgControl(qspic_cntrl_e eController, qspic_prgconfig_st *pstPrgConf)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        vSetQSPIC_PrgAccCtrl0_SCSD(eController, pstPrgConf->u8CSTime);
        vSetQSPIC_PrgAccCtrl0_SDCE(eController, pstPrgConf->eEdge);

        ePrgAddressByteCnt = pstPrgConf->eAddrByteCnt;
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_SetDirectFlashBaseAddress(qspic_cntrl_e eController, qspic_dev_e eDevice, uint16_t u16FlashBaseAddress)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_FlshMemMap0_FBA(eController, u16FlashBaseAddress);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_FlshMemMap1_FBA(eController, u16FlashBaseAddress);
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

int32_t i32QSPIC_GetDirectFlashBaseAddress(qspic_cntrl_e eController, qspic_dev_e eDevice, uint16_t * u16FlashBaseAddress)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    *u16FlashBaseAddress = biGetQSPIC_FlshMemMap0_FBA(eController);
                }
                break;
            case QSPIC_DEV_1:
                {
                    *u16FlashBaseAddress = biGetQSPIC_FlshMemMap1_FBA(eController);
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

int32_t i32QSPIC_SetDirectFlashDensity(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_density_e eFlashDensity)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_FlshMemMap0_FDEN(eController, eFlashDensity);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_FlshMemMap1_FDEN(eController, eFlashDensity);
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

int32_t i32QSPIC_GetDirectFlashDensity(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_density_e * eFlashDensity)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    *eFlashDensity = (qspic_density_e) biGetQSPIC_FlshMemMap0_FDEN(eController);
                }
                break;
            case QSPIC_DEV_1:
                {
                    *eFlashDensity = (qspic_density_e) biGetQSPIC_FlshMemMap1_FDEN(eController);
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

int32_t i32QSPIC_EnableDirectMemMapRd(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_en_e eEnableMemMap)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_FlshMemMap0_RE(eController, eEnableMemMap);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_FlshMemMap1_RE(eController, eEnableMemMap);
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

int32_t i32QSPIC_GetDirectMemMapStatusRd(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_en_e * eEnableMemMap)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    *eEnableMemMap = (qspic_en_e) biGetQSPIC_FlshMemMap0_RE(eController);
                }
                break;
            case QSPIC_DEV_1:
                {
                    *eEnableMemMap = (qspic_en_e) biGetQSPIC_FlshMemMap1_RE(eController);
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

int32_t i32QSPIC_SetDirectFlashMemMap(qspic_cntrl_e eController, qspic_dev_e eDevice, uint16_t u16FlashBaseAddress,
                                      qspic_density_e eFlashDensity, qspic_en_e eEnableMemMapRd)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_FlshMemMap0_FBA(eController, u16FlashBaseAddress);
                    vSetQSPIC_FlshMemMap0_FDEN(eController, eFlashDensity);
                    vSetQSPIC_FlshMemMap0_RE(eController, eEnableMemMapRd);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_FlshMemMap1_FBA(eController, u16FlashBaseAddress);
                    vSetQSPIC_FlshMemMap1_FDEN(eController, eFlashDensity);
                    vSetQSPIC_FlshMemMap1_RE(eController, eEnableMemMapRd);
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

int32_t i32QSPIC_DirectSetReadCtrl(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32Ctrl)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_DirRdCtrl0(eController, u32Ctrl);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_DirRdCtrl1(eController, u32Ctrl);
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

int32_t i32QSPIC_DirectGetReadCtrl(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t * u32Ctrl)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    *u32Ctrl = u32GetQSPIC_DirRdCtrl0(eController);
                }
                break;
            case QSPIC_DEV_1:
                {
                    *u32Ctrl = u32GetQSPIC_DirRdCtrl1(eController);
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

int32_t i32QSPIC_DirectEnableWIPPolling(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_en_e eEnable)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_DirAccCtrl0_PollWIP(eController, eEnable);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_DirAccCtrl1_PollWIP(eController, eEnable);
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

int32_t i32QSPIC_DirectGetStatusWIPPolling(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_en_e * eEnable)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    *eEnable = (qspic_en_e) biGetQSPIC_DirAccCtrl0_PollWIP(eController);
                }
                break;
            case QSPIC_DEV_1:
                {
                    *eEnable = (qspic_en_e) biGetQSPIC_DirAccCtrl1_PollWIP(eController);
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

int32_t i32QSPIC_DirectSetCSDeassertionTime(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8CSTime)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_DirAccCtrl0_SCSD(eController, u8CSTime);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_DirAccCtrl1_SCSD(eController, u8CSTime);
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

int32_t i32QSPIC_DirectGetCSDeassertionTime(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t * u8CSTime)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    *u8CSTime = biGetQSPIC_DirAccCtrl0_SCSD(eController);
                }
                break;
            case QSPIC_DEV_1:
                {
                    *u8CSTime = biGetQSPIC_DirAccCtrl1_SCSD(eController);
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

int32_t i32QSPIC_PgrmSetCSDeassertionTime(qspic_cntrl_e eController, uint8_t u8CSTime)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        vSetQSPIC_PrgAccCtrl0_SCSD(eController, u8CSTime);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmGetCSDeassertionTime(qspic_cntrl_e eController, uint8_t * u8CSTime)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        *u8CSTime = biGetQSPIC_PrgAccCtrl0_SCSD(eController);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_DirectSetDataCaptureEdge(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_sdce_e eEdge)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    vSetQSPIC_DirAccCtrl0_SDCE(eController, eEdge);
                }
                break;
            case QSPIC_DEV_1:
                {
                    vSetQSPIC_DirAccCtrl1_SDCE(eController, eEdge);
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

int32_t i32QSPIC_DirectGetDataCaptureEdge(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_sdce_e * eEdge)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        switch (eDevice)
        {
            case QSPIC_DEV_0:
                {
                    *eEdge = (qspic_sdce_e) biGetQSPIC_DirAccCtrl0_SDCE(eController);
                }
                break;
            case QSPIC_DEV_1:
                {
                    *eEdge = (qspic_sdce_e) biGetQSPIC_DirAccCtrl1_SDCE(eController);
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

int32_t i32QSPIC_PgrmSetDataCaptureEdge(qspic_cntrl_e eController, qspic_sdce_e eEdge)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        vSetQSPIC_PrgAccCtrl0_SDCE(eController, eEdge);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmGetDataCaptureEdge(qspic_cntrl_e eController, qspic_sdce_e * eEdge)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        *eEdge = (qspic_sdce_e) biGetQSPIC_PrgAccCtrl0_SDCE(eController);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_EnableInterrupt(qspic_cntrl_e eController, qspic_en_e eEnable)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        vSetQSPIC_PrgAccIntEn_SpiIntEn(eController, eEnable);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_GetInterruptStatus(qspic_cntrl_e eController, qspic_en_e * eEnable)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        *eEnable = (qspic_en_e) biGetQSPIC_PrgAccIntEn_SpiIntEn(eController);
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}



/****************************************************************************/

int32_t i32QSPIC_IsSpiCycleDone(qspic_cntrl_e eController, bool_t * bResult)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        if ( 1==biGetQSPIC_PrgAccStat_SpiCycDone(eController) )
        {
            /* reset the cycle done flag */
            vSetQSPIC_PrgAccStat_SpiCycDone(eController, 0);
            *bResult = C_TRUE;
        }
        else
        {
            *bResult = C_FALSE;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

bool_t boQSPIC_IsSpiCycleInPgrs(qspic_cntrl_e eController)
{
    bool_t bResult = C_FALSE;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        if ( 1==biGetQSPIC_PrgAccStat_SpiCycInPrgrs(eController) )
        {
            bResult = C_TRUE;
        }
    }
    return bResult;
}


/****************************************************************************/

bool_t boQSPIC_IsSpiCycleDone(qspic_cntrl_e eController)
{
    bool_t bResult = C_FALSE;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        if ( 1==biGetQSPIC_PrgAccStat_SpiCycDone(eController) )
        {
            /* reset the cycle done flag */
            vSetQSPIC_PrgAccStat_SpiCycDone(eController, 0);
            bResult = C_TRUE;
        }
    }

    return bResult;
}


/****************************************************************************/

int32_t i32QSPIC_WaitForCompletion(qspic_cntrl_e eController)
{
    int32_t i32Res = C_SUCCESS;

    if ( (QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController) || (QSPIC_CNTRL_2 == eController) )
    {
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) )
        {
            ;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmStatusRead(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8Status)
{
    int32_t i32Res = C_SUCCESS;

    /* default values for Prg Access Ctrl value is as follows:
     * Primary and secondary buffer size = 0, both buffers are disabled
     * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
     * SpiCycGo = Program Register Access is initiated.
     */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;

    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                    (( QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1 == eDevice )))
        || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* check for valid status pointer */
        if (C_NULL == pu8Status)
        {
            i32Res = C_FAILED;
        }
        else
        {
            /* wait for cycle completion of previous program access */
            while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

            /* set up STATUS READ opcode */
            vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_STS_READ);

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }

            if ( QSPIC_CNTRL_2 == eController )
            {
                /* for QSPIC_CNTRL_2 the data is always transmitted in secondary buffer */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;
            }
            else
            {
                /* for other controllers the data is transmitted in primary buffer */
                /* set primary buffer byte counter 1 */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_1;
            }
            /* enable primary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

            /* write value to register */
            vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

            /* wait until current program access cycle is completed */
            while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

            if ( QSPIC_CNTRL_2 == eController )
            {
                /* retrieve the status */
                *pu8Status = u8GetQSPIC_SecBufDatN(eController, 0);
            }
            else
            {
                /* retrieve the status */
                *pu8Status = u8GetQSPIC_PriBufDatN(eController, 1);
            }

            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmStatusFlagRead(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8Status)
{
    int32_t i32Res = C_SUCCESS;

    /* default values for Prg Access Ctrl value is as follows:
     * Primary and secondary buffer size = 0, both buffers are disabled
     * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
     * SpiCycGo = Program Register Access is initiated.
     */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;

    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                    (( QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1 == eDevice )))
        || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* check for valid status pointer */
        if (C_NULL == pu8Status)
        {
            i32Res = C_FAILED;
        }
        else
        {
            /* wait for cycle completion of previous program access */
            while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

            /* set up STATUS READ opcode */
            vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_RFST_READ);

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }

            if ( QSPIC_CNTRL_2 == eController )
            {
                /* for QSPIC_CNTRL_2 the data is always transmitted in secondary buffer */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;
            }
            else
            {
                /* for other controllers the data is transmitted in primary buffer */
                /* set primary buffer byte counter 1 */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_1;
            }
            /* enable primary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

            /* write value to register */
            vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

            /* wait until current program access cycle is completed */
            while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

            if ( QSPIC_CNTRL_2 == eController )
            {
                /* retrieve the status */
                *pu8Status = u8GetQSPIC_SecBufDatN(eController, 0);
            }
            else
            {
                /* retrieve the status */
                *pu8Status = u8GetQSPIC_PriBufDatN(eController, 1);
            }

            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmClearStatus(qspic_cntrl_e eController, qspic_dev_e eDevice)
{
    int32_t i32Res = C_SUCCESS;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                    (( QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1 == eDevice )))
        || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* wait for cycle completion of previous program access */
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

        /* set up WRITE ENABLE opcode */
        vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_STS_CLEAR);

        if (QSPIC_DEV_1 == eDevice )
        {
            /* set SPI_CS1_N accordingly */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
        }

        /* enable primary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

        /* write value to register */
        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

        /* wait until current program access cycle is completed */
        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmReleaseDP(qspic_cntrl_e eController, qspic_dev_e eDevice)
{
    int32_t i32Res = C_SUCCESS;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                    ((eDevice==QSPIC_DEV_0) || ( eDevice==QSPIC_DEV_1)) )
        || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* wait for cycle completion of previous program access */
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

        /* set up WRITE ENABLE opcode */
        vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_RELEASE_DP);

        if (QSPIC_DEV_1 == eDevice )
        {
            /* set SPI_CS1_N accordingly */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
        }

        /* enable primary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

        /* write value to register */
        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

        /* wait until current program access cycle is completed */
        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmConfigurationRead(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8Configuration)
{
    int32_t i32Res = C_SUCCESS;
    uint8_t u8ManID = 0;
    uint8_t u8DevID = 0;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                    (( QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1 == eDevice )))
        || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* check for valid status pointer */
        if( C_NULL == pu8Configuration )
        {
            i32Res = C_FAILED;
        }
        else
        {
            i32Res = i32QSPIC_PgrmGetID(eController, eDevice, &u8ManID, &u8DevID);
            if( C_SUCCESS == i32Res )
            {
                switch( u8ManID )
                {
                    /* Macronix */
                    case 0xC2:
                        /* wait for cycle completion of previous program access */
                        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

                        /* set up STATUS READ opcode */
                        vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_CFGM_READ);

                        if (QSPIC_DEV_1 == eDevice )
                        {
                            /* set SPI_CS1_N accordingly */
                            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
                        }
                        if ( QSPIC_CNTRL_2 == eController )
                        {
                            /* for QSPIC_CNTRL_2 the data is always transmitted in secondary buffer */
                            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;
                        }
                        else
                        {
                          /* for other controllers the data is transmitted in primary buffer */
                          /* set primary buffer byte counter 1 */
                          u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_1;
                        }
                        /* enable primary buffer */
                        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

                        /* write value to register */
                        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

                        /* wait until current program access cycle is completed */
                        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

                        if ( QSPIC_CNTRL_2 == eController )
                        {
                           /* retrieve the status */
                           *pu8Configuration = u8GetQSPIC_SecBufDatN(eController, 0);
                        }
                        else
                        {
                           /* retrieve the status */
                           *pu8Configuration = u8GetQSPIC_PriBufDatN(eController, 1);
                        }
                        i32Res = C_SUCCESS;

                        break;

                    /* Spansion */
                    case 0x01:
                        /* wait for cycle completion of previous program access */
                        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

                        /* set up STATUS READ opcode */
                        vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_CFG_READ);

                        if (QSPIC_DEV_1 == eDevice )
                        {
                            /* set SPI_CS1_N accordingly */
                            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
                        }
                        /* set primary buffer byte counter 1 */
                        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_1;

                        /* enable primary buffer */
                        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

                        /* write value to register */
                        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

                        /* wait until current program access cycle is completed */
                        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

                        /* retrieve the status */
                        *pu8Configuration = u8GetQSPIC_PriBufDatN(eController, 1);

                        i32Res = C_SUCCESS;
                        break;

                    default:
                        i32Res = C_FAILED;
                        break;
                }
            }
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmConfigurationWrite(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8Status,  uint8_t u8Conf)
{
    int32_t i32Res = C_SUCCESS;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                    (( QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1 == eDevice )))
        || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {

        /* wait for cycle completion of previous program access */
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

        /* set up WRITE REGISTER (WRR) opcode */
        vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_WRITE_REG);

        if (QSPIC_DEV_1 == eDevice )
        {
            /* set SPI_CS1_N accordingly */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
        }

        /* enable primary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

        vSetQSPIC_SecBufDatN(eController, 0, u8Status);
        vSetQSPIC_SecBufDatN(eController, 1, u8Conf);

        /* set secondary buffer byte counter */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_CNT_1;

        /* enable secondary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;

        /* write value to register */
        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

        /* wait until current program access cycle is completed */
        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

        i32Res = C_SUCCESS;
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmWriteEnable(qspic_cntrl_e eController, qspic_dev_e eDevice)
{
    int32_t i32Res = C_SUCCESS;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)) )
    {
        /* wait for cycle completion of previous program access */
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

        /* set up WRITE ENABLE opcode */
        vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_WRITE_EN);

        if (QSPIC_DEV_1 == eDevice )
        {
            /* set SPI_CS1_N accordingly */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
        }

        /* enable primary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

        /* write value to register */
        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

        /* wait until current program access cycle is completed */
        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmWriteDisable(qspic_cntrl_e eController, qspic_dev_e eDevice)
{
    int32_t i32Res = C_SUCCESS;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)) )
    {
        /* wait for cycle completion of previous program access */
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

        /* set up WRITE DISABLE opcode */
        vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_WRITE_DIS);

        if (QSPIC_DEV_1 == eDevice )
        {
            /* set SPI_CS1_N accordingly */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
        }

        /* enable primary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

        /* write value to register */
        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

        /* wait until current program access cycle is completed */
        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmSectErase(qspic_cntrl_e eController, qspic_dev_e eDevice, qspic_opcode_e eOpcode, uint32_t u32SpiPhysAddr)
{
    int32_t i32Res = C_SUCCESS;
    uint32_t u32Mask;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* wait for cycle completion of previous program access */
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

        vSetQSPIC_PriBufDatN(eController, 0, eOpcode);                                      /* set up ERASE opcode */

        /* check address byte count and set address accordingly */
        if (ePrgAddressByteCnt == QSPI_ADDR_3BYTE)
        {
            vSetQSPIC_PriBufDatN(eController, 1, (uint8_t)((u32SpiPhysAddr >> 16) & 0xFFU));     /* SPI physical addr[23:16] */
            vSetQSPIC_PriBufDatN(eController, 2, (uint8_t)((u32SpiPhysAddr >>  8) & 0xFFU));     /* SPI physical addr[15:8] */
            vSetQSPIC_PriBufDatN(eController, 3, (uint8_t)((u32SpiPhysAddr >>  0) & 0xFFU));     /* SPI physical addr[7:0] */

            /* set primary buffer byte counter */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_3;
       }
        else
        {
            u32Mask = ~(biGetQSPIC_FlshMemMap0_FBA(eController) >> 8);
            vSetQSPIC_PriBufDatN(eController, 1, (uint8_t)((u32SpiPhysAddr >> 24) & u32Mask));   /* SPI physical addr[31:23] */
            vSetQSPIC_PriBufDatN(eController, 2, (uint8_t)((u32SpiPhysAddr >> 16) & 0xFFU));     /* SPI physical addr[23:16] */
            vSetQSPIC_PriBufDatN(eController, 3, (uint8_t)((u32SpiPhysAddr >>  8) & 0xFFU));     /* SPI physical addr[15:8] */
            vSetQSPIC_PriBufDatN(eController, 4, (uint8_t)((u32SpiPhysAddr >>  0) & 0xFFU));     /* SPI physical addr[7:0] */

            /* set primary buffer byte counter */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_4;
        }

        if (QSPIC_DEV_1 == eDevice )
        {
            /* set SPI_CS1_N accordingly */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
        }

        /* enable primary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

         /* write value to register */
        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

        /* wait until current program access cycle is completed */
        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmChipErase(qspic_cntrl_e eController, qspic_dev_e eDevice)
{
    int32_t i32Res = C_SUCCESS;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* wait for cycle completion of previous program access */
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

        /* set up FULL CHIP ERASE opcode */
        vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_CHIP_ERASE);

        if (QSPIC_DEV_1 == eDevice )
        {
            /* set SPI_CS1_N accordingly */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
        }

         /* enable primary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

        /* write value to register */
        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

        /* wait until current program access cycle is completed */
        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmPagePgrm(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint16_t u16DataCount, uint8_t* const pu8Data)
{
    uint16_t u16DataIndex;
    uint32_t u32Cnt;
    uint8_t  *pu8Buffer;
    int32_t  i32Res;
    uint32_t u32Mask;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* get result buffer pointer */
        pu8Buffer = pu8Data;

        /* check for valid data buffer pointer */
        if (C_NULL == pu8Buffer)
        {
            i32Res = C_FAILED;
        }
        else
        {
            /* wait for cycle completion of previous program access */
            while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

            vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_PAGE_PGRM);                       /* set up PAGE PROGRAM opcode */

            if (ePrgAddressByteCnt == QSPI_ADDR_3BYTE)
            {
                vSetQSPIC_PriBufDatN(eController, 1, (uint8_t)((u32SpiPhysAddr >> 16) & 0xFFU));     /* SPI physical addr[23:16] */
                vSetQSPIC_PriBufDatN(eController, 2, (uint8_t)((u32SpiPhysAddr >>  8) & 0xFFU));     /* SPI physical addr[15:8] */
                vSetQSPIC_PriBufDatN(eController, 3, (uint8_t)((u32SpiPhysAddr >>  0) & 0xFFU));     /* SPI physical addr[7:0] */

                /* set primary buffer byte counter */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_3;
            }
            else
            {
                u32Mask = ~(biGetQSPIC_FlshMemMap0_FBA(eController) >> 8);
                vSetQSPIC_PriBufDatN(eController, 1, (uint8_t)((u32SpiPhysAddr >> 24) & u32Mask));   /* SPI physical addr[31:23] */
                vSetQSPIC_PriBufDatN(eController, 2, (uint8_t)((u32SpiPhysAddr >> 16) & 0xFFU));     /* SPI physical addr[23:16] */
                vSetQSPIC_PriBufDatN(eController, 3, (uint8_t)((u32SpiPhysAddr >>  8) & 0xFFU));     /* SPI physical addr[15:8] */
                vSetQSPIC_PriBufDatN(eController, 4, (uint8_t)((u32SpiPhysAddr >>  0) & 0xFFU));     /* SPI physical addr[7:0] */

                /* set primary buffer byte counter */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_4;
            }

            for (u16DataIndex = 0; u16DataIndex < u16DataCount; u16DataIndex++)
            {
                vSetQSPIC_SecBufDatN(eController, u16DataIndex, pu8Buffer[u16DataIndex]);
            }

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }

            /* enable primary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

            /* set secondary buffer byte counter */
            /* follwoing code simplified:
             * u32PrgAccCtrl = u32PrgAccCtrl | ( (((uint32_t) (u16DataCount-1U) ) << QSPIC_PACTRL_SEC_BUF_CNT_SHIFT ) &  QSPIC_PACTRL_SEC_BUF_CNT_MASK );
             * */
            u32Cnt = ((uint32_t) u16DataCount) -1U;
            u32Cnt = u32Cnt << QSPIC_PACTRL_SEC_BUF_CNT_SHIFT;
            u32PrgAccCtrl |=  ( u32Cnt &  QSPIC_PACTRL_SEC_BUF_CNT_MASK );

            /* enable secondary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;

            /* write value to register */
            vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

            /* wait until current program access cycle is completed */
            while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmFastRead(qspic_cntrl_e eController, qspic_dev_e eDevice, uint32_t u32SpiPhysAddr, uint16_t u16DataCount, uint8_t* const pu8Data)
{
    uint16_t u16DataIndex;
    int32_t  i32Res;
    uint32_t u32Cnt;
    uint32_t u32Mask;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* check for valid data buffer pointer */
        if (C_NULL == pu8Data)
        {
            i32Res = C_FAILED;
        }
        else
        {
            /* wait for cycle completion of previous program access */
            while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

            vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_FAST_READ);                       /* set up FAST READ opcode */

            if (ePrgAddressByteCnt == QSPI_ADDR_3BYTE)
            {
                vSetQSPIC_PriBufDatN(eController, 1, (uint8_t)((u32SpiPhysAddr >> 16) & 0xFFU));     /* SPI physical addr[23:16] */
                vSetQSPIC_PriBufDatN(eController, 2, (uint8_t)((u32SpiPhysAddr >>  8) & 0xFFU));     /* SPI physical addr[15:8] */
                vSetQSPIC_PriBufDatN(eController, 3, (uint8_t)((u32SpiPhysAddr >>  0) & 0xFFU));     /* SPI physical addr[7:0] */

                /* set primary buffer byte counter (3 byte address plus 1 dummy byte) */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_4;
            }
            else
            {
                u32Mask = ~(biGetQSPIC_FlshMemMap0_FBA(eController) >> 8);
                vSetQSPIC_PriBufDatN(eController, 1, (uint8_t)((u32SpiPhysAddr >> 24) & u32Mask));   /* SPI physical addr[31:23] */
                vSetQSPIC_PriBufDatN(eController, 2, (uint8_t)((u32SpiPhysAddr >> 16) & 0xFFU));     /* SPI physical addr[23:16] */
                vSetQSPIC_PriBufDatN(eController, 3, (uint8_t)((u32SpiPhysAddr >>  8) & 0xFFU));     /* SPI physical addr[15:8] */
                vSetQSPIC_PriBufDatN(eController, 4, (uint8_t)((u32SpiPhysAddr >>  0) & 0xFFU));     /* SPI physical addr[7:0] */

                /* set primary buffer byte counter (4 byte address plus 1 dummy byte) */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_5;
            }

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }

            /* enable primary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

            /* set secondary buffer byte counter */
            /* follwoing code simplified:
             *   u32PrgAccCtrl = u32PrgAccCtrl | (  (((uint32_t ) (u16DataCount-1) )  << QSPIC_PACTRL_SEC_BUF_CNT_SHIFT ) &  QSPIC_PACTRL_SEC_BUF_CNT_MASK );
             */
            u32Cnt = ((uint32_t) u16DataCount) -1U;
            u32Cnt = u32Cnt << QSPIC_PACTRL_SEC_BUF_CNT_SHIFT;
            u32PrgAccCtrl |=  ( u32Cnt &  QSPIC_PACTRL_SEC_BUF_CNT_MASK );

            /* enable secondary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;

            /* write value to register */
            vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

            /* wait until current program access cycle is completed */
            while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

            /* copy reading result into result buffer array */
            for (u16DataIndex = 0; u16DataIndex < u16DataCount; u16DataIndex++)
            {
                pu8Data[u16DataIndex] = u8GetQSPIC_SecBufDatN(eController, u16DataIndex);
            }

            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/
int32_t i32QSPIC_PgrmGetID(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8ManID, uint8_t* const pu8DevID)
{
    int32_t i32Res;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;
    uint32_t u32Address1, u32Address2;

    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* check for valid data buffer pointer */
        if( (C_NULL == pu8ManID) || (C_NULL == pu8DevID) )
        {
            i32Res = C_FAILED;
        }
        else
        {
            /* wait for cycle completion of previous program access */
            while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

            vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_READ_ID);     /* set up READ ID opcode */

            if (QSPIC_CNTRL_2 == eController)
            {
                u32Address1 = 0x12;
                u32Address2 = 0x08;
            }
            else
            {
                u32Address1 = 0x0;
                u32Address2 = 0x0;
            }

            if (ePrgAddressByteCnt == QSPI_ADDR_3BYTE)
            {
                vSetQSPIC_PriBufDatN(eController, 1, u32Address1);
                vSetQSPIC_PriBufDatN(eController, 2, u32Address2);
                vSetQSPIC_PriBufDatN(eController, 3, 0x00);

                /* set primary buffer byte counter (3 byte addres plus 1 byte dummy byte) */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_3;
            }
            else
            {
                vSetQSPIC_PriBufDatN(eController, 1, u32Address1);
                vSetQSPIC_PriBufDatN(eController, 2, u32Address2);
                vSetQSPIC_PriBufDatN(eController, 3, 0x00);
                vSetQSPIC_PriBufDatN(eController, 4, 0x00);

                /* set primary buffer byte counter (4 byte address plus 1 byte dummy byte) */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_BUF_CNT_4;

            }

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }

            /* enable primary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

            /* set secondary buffer byte counter */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_CNT_1;

            /* enable secondary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;

            /* write value to register */
            vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

            /* wait until current program access cycle is completed */
            while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

            *pu8ManID = u8GetQSPIC_SecBufDatN(eController, 0);
            *pu8DevID = u8GetQSPIC_SecBufDatN(eController, 1);

            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmGetExtendedID(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t* const pu8Information)
{
    int32_t i32Res = C_SUCCESS;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* check for valid status pointer */
        if( C_NULL == pu8Information )
        {
            i32Res = C_FAILED;
        }
        else
        {
            /* wait for cycle completion of previous program access */
            while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

            /* set up STATUS READ opcode */
            vSetQSPIC_PriBufDatN(eController, 0, QSPIC_OPCODE_READ_EXTID);

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }

            /* enable primary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

            /* set secondary buffer byte counter */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_CNT_3;


            /* enable secondary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;

            /* write value to register */
            vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

            /* wait until current program access cycle is completed */
            while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

            /* Retrieve the status */
            pu8Information[0] = u8GetQSPIC_SecBufDatN(eController, 0);
            pu8Information[1] = u8GetQSPIC_SecBufDatN(eController, 1);
            pu8Information[2] = u8GetQSPIC_SecBufDatN(eController, 2);
            pu8Information[3] = u8GetQSPIC_SecBufDatN(eController, 3);

            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_WriteByte(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8Value)
{
    int32_t i32Res = C_SUCCESS;
    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* wait for cycle completion of previous program access */
        while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

        /* set up WRITE DISABLE opcode */
        vSetQSPIC_PriBufDatN(eController, 0, u8Value);

        if (QSPIC_DEV_1 == eDevice )
        {
            /* set SPI_CS1_N accordingly */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
        }

        /* enable primary buffer */
        u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

        /* write value to register */
        vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

        /* wait until current program access cycle is completed */
        while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmGetRegister(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8Command, uint16_t u16Count, uint8_t* pu8Information)
{
    int32_t  i32Res = C_SUCCESS;
    uint16_t u16Counter;
    uint32_t u32Cnt;

    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* check for valid status pointer */
        if( C_NULL == pu8Information )
        {
            i32Res = C_FAILED;
        }
        else
        {
            /* wait for cycle completion of previous program access */
            while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

            /* set up STATUS READ opcode */
            vSetQSPIC_PriBufDatN(eController, 0, u8Command);
            vSetQSPIC_PriBufDatN(eController, 1, 0x00);
            vSetQSPIC_PriBufDatN(eController, 2, 0x00);
            vSetQSPIC_PriBufDatN(eController, 3, 0x00);

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }

            /* enable primary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }
            /* set secondary buffer byte counter */
            /* follwoing code simplified:
             *   u32PrgAccCtrl = u32PrgAccCtrl | ( (((uint32_t) (u16Count-1) ) << QSPIC_PACTRL_SEC_BUF_CNT_SHIFT ) &  QSPIC_PACTRL_SEC_BUF_CNT_MASK);
             */
            u32Cnt = ((uint32_t) u16Count) -1U;
            u32Cnt = u32Cnt << QSPIC_PACTRL_SEC_BUF_CNT_SHIFT;
            u32PrgAccCtrl |=  ( u32Cnt &  QSPIC_PACTRL_SEC_BUF_CNT_MASK );

            /* enable secondary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SEC_BUF_EN_BIT;

            /* write value to register */
            vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

            /* wait until current program access cycle is completed */
            while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) ){}

            /* Retrieve the status */
            for (u16Counter=0; u16Counter<u16Count; u16Counter++)
            {
                *(pu8Information + u16Counter) = u8GetQSPIC_SecBufDatN(eController, u16Counter);
            }

            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}


/****************************************************************************/

int32_t i32QSPIC_PgrmWriteRegister(qspic_cntrl_e eController, qspic_dev_e eDevice, uint8_t u8Command, uint16_t u16Count, uint8_t* pu8Information)
{
    int32_t  i32Res = C_SUCCESS;
    uint16_t u16DataIndex;
    uint32_t u32Cnt;

    /* default values for Prg Access Ctrl value is as follows:
      * Primary and secondary buffer size = 0, both buffers are disabled
      * Chip select Number=0,SPI_CS0_N (Primary) -> QSPIC_DEV_0
      * SpiCycGo = Program Register Access is initiated.
    */
    uint32_t u32PrgAccCtrl = QSPIC_PACTRL_SPI_CYC_GO_BIT;


    if ( ( ((QSPIC_CNTRL_0 == eController) || (QSPIC_CNTRL_1 == eController ))  &&
                        ((QSPIC_DEV_0 == eDevice) || ( QSPIC_DEV_1==eDevice)))
            || (( QSPIC_CNTRL_2 == eController ) && ( QSPIC_DEV_0 == eDevice )) )
    {
        /* check for valid status pointer */
        if( C_NULL == pu8Information )
        {
            i32Res = C_FAILED;
        }
        else
        {
            /* wait for cycle completion of previous program access */
            while ( C_TRUE == boQSPIC_IsSpiCycleInPgrs(eController) ){}

            /* set up STATUS READ opcode */
            vSetQSPIC_PriBufDatN(eController, 0, u8Command);
            vSetQSPIC_PriBufDatN(eController, 1, 0x00);
            vSetQSPIC_PriBufDatN(eController, 2, 0x00);
            vSetQSPIC_PriBufDatN(eController, 3, 0x00);

            for (u16DataIndex = 0; u16DataIndex < u16Count; u16DataIndex++)
            {
                vSetQSPIC_SecBufDatN(eController, u16DataIndex, pu8Information[u16DataIndex]);
            }

            if (QSPIC_DEV_1 == eDevice )
            {
                /* set SPI_CS1_N accordingly */
                u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_SPI_CS_DEV1_BIT;
            }

            /* enable primary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | QSPIC_PACTRL_PRI_EN_BIT;

            /* set secondary buffer byte counter */
            /* follwoing code simplified:
             *   u32PrgAccCtrl = u32PrgAccCtrl | ( (((uint32_t) (u16Count-1) ) << QSPIC_PACTRL_SEC_BUF_CNT_SHIFT ) &  QSPIC_PACTRL_SEC_BUF_CNT_MASK);
             */
            u32Cnt = ((uint32_t) u16Count) -1U;
            u32Cnt = u32Cnt << QSPIC_PACTRL_SEC_BUF_CNT_SHIFT;
            u32PrgAccCtrl |=  ( u32Cnt &  QSPIC_PACTRL_SEC_BUF_CNT_MASK );

            /* enable secondary buffer */
            u32PrgAccCtrl = u32PrgAccCtrl | ( QSPIC_PACTRL_SEC_BUF_EN_BIT);

            /* write value to register */
            vSetQSPIC_PrgAccCtrl1 (eController, u32PrgAccCtrl );

            /* wait until current program access cycle is completed */
            while ( C_FALSE == boQSPIC_IsSpiCycleDone(eController) )
            {
                ;
            }

            /* Retrieve the status */
/*            for (u16DataIndex=0; u16DataIndex<=u16Count; u16DataIndex++)
            {
                *(pu8Information + u16DataIndex) = u8GetQSPIC_SecBufDatN(eController, u16DataIndex);
            }
*/

            i32Res = C_SUCCESS;
        }
    }
    else
    {
        i32Res = C_FAILED;
    }

    return i32Res;
}



/****************************************************************************/

uint32_t u32QSPIC_DirectReadWord(uint32_t u32SpiPhysAddr)
{
    return (uint32_t) word_read((int32_t)u32SpiPhysAddr);
}


/****************************************************************************/

void vQSPIC_DirectReadBurst4(uint32_t u32SpiPhysAddr, uint32_t * pu32Data)
{
    read_burst4((int32_t)u32SpiPhysAddr, pu32Data);
}


/****************************************************************************/

void vQSPIC_DirectReadBurst8(uint32_t u32SpiPhysAddr, uint32_t * pu32Data)
{
    read_burst8((int32_t)u32SpiPhysAddr, pu32Data);
}

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
**  File: qspic.c
**  $Revision: 1.40 $
**  $Date: 2015/05/18 13:49:55 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   :  5 (0286) String literal contains character which is not a
** |                    member of the basic source character set.
** |           5 (0288) Source file '<TEXT>' has comments containing characters
** |                    which are not members of the basic source character set.
** |          22 (3218) File scope static, '<TEXT>', only accessed in one
** |                    function.
** |          45 (0303) Cast between a pointer to volatile object and an
** |                    integral type.
** |          52 (1503) The function '%1s' is defined but is not used within
** |                    this project.
** |
** | REASON : This is neccessary because of driver version control.
** |
** |
** | RULE   : 52 (2018) This switch default label is unreachable.
** |
** | REASON : This is neccessary because of default statement in case.
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/


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


