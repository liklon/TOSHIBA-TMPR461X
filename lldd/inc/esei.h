/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : ESEI low level driver header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : ESEI
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.9 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef ESEI_H
#define ESEI_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                      /* Core specific primitive type definitions */

/*********************************************/
/* disable following Misra errors for io files */
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 1861  /* Rule 20.1 [R] : No definition, redefinition, or undefinition of reserved words and standard library names */
#endif

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_ESEI_H_REVISION     "$Revision: 1.9 $"
#define LLDD_ESEI_H_TAG          "$Name: LLDD_1_6 $"

/*********************************************/

/* Depth of the TX FIFO */
#define ESEI_TXFIFO_DEPTH                   20
                                            
/* Depth of the RX FIFO */                      
#define ESEI_RXFIFO_DEPTH                   20

/* RX Buffer ready timeout  */
#define ESEI_RX_RDY_TIMEOUT                 20000000

/* TX Buffer ready timeout  */
#define ESEI_TX_RDY_TIMEOUT                 2000000

/* Minimal bit rate */
#define ESEI_MIN_BITRATE                    (((140 * 1000000) / (2*(0xFF + 1))) / 1000)

/* Maximal bit rate */
#define ESEI_MAX_BITRATE                    (((140 * 1000000) / 2) / 1000)

/*********************************************/

/**********************************************
*               Enumerations                  *
**********************************************/
/****************************************************************************
*                          CHANNEL SELECTION MACROS
*             (Please use these macros to select module instances)
*****************************************************************************/

typedef enum tag_esei_ch_e
{
    ESEI_0 = 0x0,                       /* Channel 0 */
    ESEI_1 = 0x1000                     /* Channel 1 */
} esei_ch_e; 

/* Enable/disable channel */                        
typedef enum tag_esei_en_e                  
{                                           
    ESEI_DISABLE = 0x0,                     /* Enable */
    ESEI_ENABLE  = 0x1                      /* Disable */
} esei_en_e;                                
                                            
/* IRQ status  */                           
typedef enum tag_esei_irq_e                 
{                                           
    ESEI_IRQ_NONE   = 0x0,                  /* IRQ inactive */
    ESEI_IRQ_ACTIVE = 0x1                   /* IRQ active */
} esei_irq_e;

/* *** */

/*
 *  SEMCR parameter values
 */

/* SEMCR.OPMODE - Operational mode  */
typedef enum tag_esei_opmode_e
{
    ESEI_OPM_CFG = 0x1,                     /* Configuration mode */
    ESEI_OPM_ACT = 0x2                      /* Active mode */
} esei_opmode_e;

/* SEMCR.SESTP - SEI stop */
typedef enum tag_esei_sestp_e
{
    ESEI_START = 0x0,                       /* Normal operation */
    ESEI_STOP  = 0x1                        /* Stop after the current transfer */
} esei_sestp_e;

/* *** */

/*
 *  SECR0 parameter values
 */

/* SECR0.SSIVAL - SSI valid */
typedef enum tag_esei_ssival_e
{
    ESEI_SSI_INVALID = 0x0,                 /* SSI not valid in Master mode */
    ESEI_SSI_VALID   = 0x1                  /* SSI valid in Master mode */
} esei_ssival_e;

/* SECR0.MSTR - Master/slave mode */
typedef enum tag_esei_mstr_e
{
    ESEI_MODE_SLAVE  = 0x0,                 /* Slave mode */
    ESEI_MODE_MASTER = 0x1                  /* Master mode */
} esei_mstr_e;

/* SECR0.SBOS - Bit order */
typedef enum tag_esei_sbos_e
{
    ESEI_BIT_LSB = 0x0,                     /* LSB is shifted first */
    ESEI_BIT_MSB = 0x1                      /* MSB is shifted first */
} esei_sbos_e;

/* SECR0.SPHA - Clock phase */
typedef enum tag_esei_spha_e
{
    ESEI_ACT_HI = 0x0,                      /* Active high clock selected */
    ESEI_ACT_LO = 0x1                       /* Active low clock selected */
} esei_spha_e;

/* SECR0.SPOL - Polarity */
typedef enum tag_esei_spol_e
{
    ESEI_POL_SAMPLE = 0x0,                  /* Sample on 1-st edge, shift on 2-nd */
    ESEI_POL_SHIFT  = 0x1                   /* Shift on 1-st edge, sample on 2-nd */
} esei_spol_e;

/* *** */

/*
 *  SECR1 parameter values
 */

/* SECR1.SSZ - Transfer size */
typedef enum tag_esei_ssz_e
{
    ESEI_TXSIZE_SFL  = 0x00,                /* spec.in SEDER.SFL(Master Mode only)*/
    ESEI_TXSIZE_5    = 0x05,                /* 5 bits */
    ESEI_TXSIZE_6    = 0x06,                /* 6 bits */
    ESEI_TXSIZE_7    = 0x07,                /* 7 bits */                
    ESEI_TXSIZE_8    = 0x08,                /* 8 bits */                
    ESEI_TXSIZE_9    = 0x09,                /* 9 bits */                
    ESEI_TXSIZE_10   = 0x0a,                /* 10 bits */                
    ESEI_TXSIZE_11   = 0x0b,                /* 11 bits */                
    ESEI_TXSIZE_12   = 0x0c,                /* 12 bits */                
    ESEI_TXSIZE_13   = 0x0d,                /* 13 bits */                
    ESEI_TXSIZE_14   = 0x0e,                /* 14 bits */                
    ESEI_TXSIZE_15   = 0x0f,                /* 15 bits */                
    ESEI_TXSIZE_16   = 0x10,                /* 16 bits */
    ESEI_TXSIZE_17   = 0x11                 /* 17 bits */
} esei_ssz_e;

/* SECR1.SER - Transfer rate TODO */
typedef enum tag_esei_ser_e
{
    ESEI_BRATE_60M   = 0x01,                /* 60Mbps (full-duplex) Peak Data Rate*/
    ESEI_BRATE_40M   = 0x02,                /* 40Mbps (full-duplex) */
    ESEI_BRATE_30M   = 0x03,                /* 30Mbps (full-duplex) */
    ESEI_BRATE_24M   = 0x04,                /* 24Mbps (full-duplex) */
    ESEI_BRATE_20M   = 0x05,                /* 20Mbps (full-duplex) */
    ESEI_BRATE_17M14 = 0x06,                /* 17.14Mbps (full-duplex) */
    ESEI_BRATE_7M5   = 0x0f,                /* 7.5Mbps (full-duplex) */
    ESEI_BRATE_1M    = 0x77                 /* 1Mbps (full-duplex) */
} esei_ser_e;

/* *** */

/*
 *  SESR parameter values
 */

/* SESR.SEILC - Loop completed */
typedef enum tag_esei_seilc_e
{
    ESEI_LOOP_NOELPSD = 0x0,                /* Loop Not Elapsed*/
    ESEI_LOOP_ELPSD   = 0x1                 /* Loop Elapsed */
} esei_seilc_e;

/* SESR.SEOE/SESR.SEUE/SESR.SETF/SESR.PAR - Error status */
typedef enum tag_esei_errstat_e
{
    ESEI_NOERR = 0x0,                       /* No error */
    ESEI_ERROR = 0x1                        /* Error occured */
} esei_errstat_e;

/* SESR.SIDLE - Idle indicator */
typedef enum tag_esei_seidle_e
{
    ESEI_ACTIVE  = 0x0,                     /* SEI is active */
    ESEI_IDLE    = 0x1                      /* SEI is in idle state */
} esei_sidle_e;

/* SESR.STRDY/SRRDY - Transmit ready indicator */
typedef enum tag_esei_rdy_e
{
    ESEI_NOT_READY = 0x0,                   /* SEI Transmit/receive ready */
    ESEI_READY     = 0x1                    /* SEI Transmit/receive not ready */
} esei_rdy_e;

/* SESR.IFSD - Inter-frame space delay indicator */
typedef enum tag_esei_ifsd_e
{
    ESEI_CNT_STOPPED = 0x0,                 /* Counter stopped */
    ESEI_CNT_RUNS    = 0x1                  /* Counter running */
} esei_ifsd_e;

/* *** */

/*
 *  SEPR parameter values
 */

/* SEPR.SPP01 - Set ESEI parity */
typedef enum tag_esei_spp01_e
{
    ESEI_PARITY_BIT = 0x0,                  /* Added bit is real parity bit */
    ESEI_ALWAYS_0   = 0x2,                  /* Added parity bit is always 0 */
    ESEI_ALWAYS_1   = 0x3                   /* Added parity bit is always 1 */
} esei_spp01_e;

/* SEPR.SPEO - Parity */
typedef enum tag_esei_speo_e
{
    ESEI_PARITY_EVEN = 0x0,                 /* Even parity */
    ESEI_PARITY_ODD  = 0x1                  /* Odd parity */
} esei_speo_e;

/* *** */

/*
 *  SELCR parameter values
 */

/* SELCR.SLB - Loop blocking */
typedef enum tag_esei_slb_e
{
    ESEI_RELEASED = 0x0,                    /* Transmission released */
    ESEI_BLOCKED  = 0x1                     /* Transmission blocked */
} esei_slb_e;

/* *** */

/*
 *  SEDER parameter values
 */

/* SEDER.PR - Parity report */
typedef enum tag_esei_pr_e
{
    ESEI_PARITY_OK  = 0x0,                  /* Parity correct */
    ESEI_PARITY_ERR = 0x1                   /* Parity error in the frame */
} esei_pr_e;

/* SEDER.SCID - Chip select ID */
typedef enum tag_esei_scid_e
{
    ESEI_CS0  = 0x0,                        /* Chip select 0 */
    ESEI_CS1  = 0x1,                        /* Chip select 1 */
    ESEI_CS2  = 0x2,                        
    ESEI_CS3  = 0x3,                        
    ESEI_CS4  = 0x4,                        
    ESEI_CS5  = 0x5,                        
    ESEI_CS6  = 0x6,                        
    ESEI_CS7  = 0x7                         /* Chip select 8 */
} esei_scid_e;

/*********************************************/


/**********************************************
*                 Structures                  *
**********************************************/

/* Control configuration */
typedef struct tag_esei_ctrlcfg_st
{
    esei_mstr_e eMode;                      /* Master/Slave mode select */
    esei_sbos_e eBitOrder;                  /* Bit order (LSB/MSB) selection */
    esei_ssival_e eSsiValid;                /* SSI valid in master mode */
    esei_spha_e ePhase;                     /* SEI Phase selection */
    esei_spol_e ePolarity;                  /* SEI Polarity (TX format) */
} esei_ctrlcfg_st;

/* IRQ configuration */
typedef struct tag_esei_irqcfg_st
{
    esei_en_e eIdleIrqEn;                   /* IDLE IRQ enable */
    esei_en_e eOvflowIrqEn;                 /* Overflow IRQ enable */
    esei_en_e eUndflowIrqEn;                /* Underflow IRQ enable */
    esei_en_e eTransFmtIrqEn;               /* Transfer format error IRQ enable */
    esei_en_e eParityIrqEn;                 /* Parity IRQ enable */
} esei_irqcfg_st;

/* Sent entry data structure */
typedef struct tag_esei_dSEntry_st
{
    esei_scid_e eSlaveId;                   /* Chip Select ID of the slave */
    esei_ssz_e eFrameSize;                  /* Frame Size */
    uint16_t u16Data;                       /* Data entry */
} esei_dSEntry_st;

/* Receive entry data structure */
typedef struct tag_esei_dREntry_st
{
    esei_scid_e eSlaveId;                   /* Chip Select ID of the slave */
    esei_ssz_e eFrameSize;                  /* Frame size */
    esei_pr_e eParityErr;                   /* Parity error report (RX data only) */
    uint16_t u16Data;                       /* Data entry */
} esei_dREntry_st;

/*********************************************/


/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vESEI_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8IORevision     - pointer to IO header revision string
 *                pau8IOTag          - pointer to IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vESEI_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                      uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                      uint8_t** pau8IORevision, uint8_t** pau8IOTag);


/****************************************************************************
 *
 * Function:      vESEI_Config
 *
 * Purpose:       ESEI module configuration
 *
 * Inputs:        eCh    ESEI Channel
 *                stCfg  ESEI configuration structure
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Calling this function will switch ESEI module
 *                to configuration mode, and then back to Previous.
 *                Please note that any running transfers will be
 *                immediately stopped (even within current frame).
 *
 ***************************************************************************/
void vESEI_Config(esei_ch_e eCh, esei_ctrlcfg_st stCfg);


/****************************************************************************
 *
 * Function:      vESEI_SetOpMode
 *
 * Purpose:       Set the ESEI operation mode
 *
 * Inputs:        eCh    ESEI Channel
 *                eMode  ESEI operation mode
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Please note that when switching to configuration mode
 *                any running transfers will be immediately stopped
 *                (even within current frame).
 *
 ***************************************************************************/
void vESEI_SetOpMode(esei_ch_e eCh, esei_opmode_e eMode);


/****************************************************************************
 *
 * Function:      vESEI_SetTransferSize
 *
 * Purpose:       Set the frame transfer size
 *
 * Inputs:        eCh      ESEI Channel
 *                eTxSize  Transfer frame size
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   This function switches temporary to Configuration mode.
 *                Please note that any running transfers will be immediately
 *                stopped (even within current frame).
 *
 ***************************************************************************/
void vESEI_SetTransferSize(esei_ch_e eCh, esei_ssz_e eTxSize);


/****************************************************************************
 *
 * Function:      i32ESEI_SetBitRate
 *
 * Purpose:       Set the bit rate
 *
 * Inputs:        eCh         ESEI Channel
 *                u32BitRate  Bit Rate value in [kbps]
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on bit rate out of range
 *
 * Limitations:   This function switches temporary to Configuration mode.
 *                The function will always check if the target frequency
 *                can be reached in current configuration.
 *
 ***************************************************************************/
int32_t i32ESEI_SetBitRate(esei_ch_e eCh, uint32_t u32BitRate);


/****************************************************************************
 *
 * Function:      vESEI_ParityConfig
 *
 * Purpose:       Set the parity options
 *
 * Inputs:        eCh       ESEI Channel
 *                eBitType  Type of the parity bit
 *                eMode     Parity mode (odd/even)
 *                eStopEn   ESEI stop on parity error enable
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   Calling this function will switch ESEI module
 *                to configuration mode, and then back to Previous.
 *                Please note that any running transfers will be
 *                immediately stopped (even within current frame).
 *
 ***************************************************************************/
void vESEI_ParityConfig(esei_ch_e eCh, esei_spp01_e eBitType,
                        esei_speo_e eMode, esei_en_e eStopEn);


/****************************************************************************
 *
 * Function:      vESEI_ParityEnable
 *
 * Purpose:       Enable/sisable parity
 *
 * Inputs:        eCh      ESEI Channel
 *                eEnable  Enable parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vESEI_ParityEnable(esei_ch_e eCh, esei_en_e eEnable);


/****************************************************************************
 *
 * Function:      vESEI_SetTiming
 *
 * Purpose:       Set the Inter-Frame Space and Slave Slect Space
 *
 * Inputs:        eCh         ESEI Channel
 *                ePrscal     Enables/disables IFS prescaler
 *                u16IfCount  Inter-Frame Space (10-bit counter value)
 *                u8SSCount   Slave Select Space counter value
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   When ESEI is in Slave Mode and SPHA is set to
 *                Active low clock select, the Slave Select Space
 *                counter will be forced to value 4. For more info,
 *                please see Capricorn Hardware Specification.
 *
 ***************************************************************************/
void vESEI_SetTiming(esei_ch_e eCh, esei_en_e ePrescal,
                     uint16_t u16IfCount, uint8_t u8SSCount);


/****************************************************************************
 *
 * Function:      i32ESEI_SetRunCtrl
 *
 * Purpose:       Start/stop the current transfer
 *
 * Inputs:        eCh     ESEI Channel
 *                eStart  Transfer run control
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on wrong mode
 *
 * Limitations:   This function only has effect during Master mode.
 *                The function will start the transfer only when
 *                ESEI module is in Active- and Master- mode.
 *
 ***************************************************************************/
int32_t i32ESEI_SetRunCtrl(esei_ch_e eCh, esei_sestp_e eStart);


/****************************************************************************
 *
 * Function:      eESEI_GetRunCtrl
 *
 * Purpose:       Retrieve the current transfer mode as it can be changed
 *                by the hardware
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: Current run control status
 *
 * Limitations:   none
 *
 ***************************************************************************/
esei_sestp_e eESEI_GetRunCtrl(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_ClearBuffer
 *
 * Purpose:       Clear the TX/RX buffers
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on mode/state does not allow the operation 
 *
 * Limitations:   The function will check whether the ESEI is in master mode,
 *                if the current transfer is stopped and module is already
 *                in IDLE mode. If any of these conditions are not met
 *                the function will not clear buffers and will exit with
 *                C_FAILED.
 *
 *                This approach is neccessary in order to make safe and
 *                clean buffer clear, without any data being corrupted or
 *                lost.
 *
 ***************************************************************************/
int32_t i32ESEI_ClearBuffer(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_DiagLoopEnable
 *
 * Purpose:       Switch the diagnostic loop
 *
 * Inputs:        eCh      ESEI Channel
 *                eEnable  Enable/diasable request
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on wrong mode
 *
 * Limitations:   The Diagnostic-Loop can be set only when the ESEI is
 *                in active mode and configured as Master. If these
 *                conditions are not met, the function will immediatelly
 *                return with C_FAILED.
 *
 ***************************************************************************/
int32_t i32ESEI_DiagLoopEnable(esei_ch_e eCh, esei_en_e eEnable);


/****************************************************************************
 *
 * Function:      vESEI_SetMode
 *
 * Purpose:       Switch between master/slave mode
 *
 * Inputs:        eCh    ESEI Channel
 *                eMode  Master/Slave selection parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   This function switches temporary to Configuration mode.
 *                Please note that any running transfers will be immediately
 *                stopped (even within current frame).
 *
 ***************************************************************************/
void vESEI_SetMode(esei_ch_e eCh, esei_mstr_e eMode);


/****************************************************************************
 *
 * Function:      i32ESEI_IsTxBuffEmpty
 *
 * Purpose:       Check if the transmit buffer is empty
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE on empty
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsTxBuffEmpty(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsRxBuffFull
 *
 * Purpose:       Check whether the receive buffer is full
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_FALSE on empty
 *                C_TRUE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsRxBuffFull(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsLoopElapsed
 *
 * Purpose:       Check whether the loop is completed
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if elapsed
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsLoopElapsed(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsIRQActTx
 *
 * Purpose:       Check if the transmit buffer fill level interrupt is active
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if active
 *                C_FALSE otherwise
 *
 * Limitations:  none
 *
 ***************************************************************************/
int32_t i32ESEI_IsIRQActTx(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsIRQActRx
 *
 * Purpose:       Check if the receive buffer fill level interrupt is active
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if active
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsIRQActRx(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsTxFormatErr
 *
 * Purpose:       Check if a transfer format error is detected
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if detected
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsTxFormatErr(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsIdle
 *
 * Purpose:       Retrieve the current ESEI state
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if idle
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsIdle(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsUnderflowErr
 *
 * Purpose:       Check an underflow error is detected
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if detected
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsUnderflowErr(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsOverflowErr
 *
 * Purpose:       Cheks if the overflow error occured
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if detected
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsOverflowErr(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsParityErr
 *
 * Purpose:       Check if the the parity error occured in a frame
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if occured
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsParityErr(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      vESEI_ClearParityErr
 *
 * Purpose:       Clear the parity error flag
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vESEI_ClearParityErr(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      vESEI_ClearOverFlowErr
 *
 * Purpose:       Clear the overflow error flag
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vESEI_ClearOverFlowErr(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      vESEI_ClearUnderFlowErr
 *
 * Purpose:       Clear the underflow error flag
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vESEI_ClearUnderFlowErr(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      vESEI_ClearTxFormatErr
 *
 * Purpose:       Clear transmission format error flag
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vESEI_ClearTxFormatErr(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsCounterRunning
 *
 * Purpose:       Check the state of the IFS counter
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if currently running
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsIFCntrRunning(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsReadyBuffTx
 *
 * Purpose:       Check if the transmition buffer is ready to receive new
 *                data
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if ready
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsReadyBuffTx(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_IsReadyBuffRx
 *
 * Purpose:       Check if there is valid data stored in Receive buffer
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE if available
 *                C_FALSE otherwise
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_IsReadyBuffRx(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      vESEI_ClearStatusAll
 *
 * Purpose:       Clear all status bits
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vESEI_ClearStatusAll(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      vESEI_LoopEnable
 *
 * Purpose:       Enable the Loop over transmit buffer
 *
 * Inputs:        eCh      ESEI Channel
 *                eEnable  Enable Loop parameter
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vESEI_LoopEnable(esei_ch_e eCh, esei_en_e eEnable);


/****************************************************************************
 *
 * Function:      vESEI_BlockLoop
 *
 * Purpose:       Block/release the transfer loop
 *
 * Inputs:        eCh     ESEI Channel
 *                eBlock  Block/release request
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   When Loop mode is disabled, this function has no effect
 *
 ***************************************************************************/
void vESEI_BlockLoop(esei_ch_e eCh, esei_slb_e eBlock);


/****************************************************************************
 *
 * Function:      i32ESEI_SetIrqLevelTx
 *
 * Purpose:       Set the interrupt fill level of the TX buffer
 *
 * Inputs:        eCh      ESEI Channel
 *                u8Level  Fill level (0x00 - 0x13)
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid depth 
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_SetIrqLevelTx(esei_ch_e eCh, uint8_t u8Level);


/****************************************************************************
 *
 * Function:      i32ESEI_SetIrqLevelRx
 *
 * Purpose:       Set the interrupt fill level of the RX buffer
 *
 * Inputs:        eCh      ESEI Channel
 *                u8Level  Fill level (0x00 - 0x13)
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid depth
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32ESEI_SetIrqLevelRx(esei_ch_e eCh, uint8_t u8Level);


/****************************************************************************
 *
 * Function:      u8ESEI_GetLevelTx
 *
 * Purpose:       Retrieve the fill level of the TX buffer
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       the fill level
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8ESEI_GetLevelTx(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      u8ESEI_GetLevelRx
 *
 * Purpose:       Retrieve the fill level of the RX buffer
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       the fill level
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8ESEI_GetLevelRx(esei_ch_e eCh);


/****************************************************************************
 *
 * Function:      i32ESEI_WriteFrameSingle
 *
 * Purpose:       Write data to the TX FIFO, addressed by the default device
 *                SSO[0]
 *
 * Inputs:        eCh      ESEI Channel
 *                u16Data  Data to be sent
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on device busy
 *
 * Limitations:   This function can be used only in a single-slave system
 *
 ***************************************************************************/
int32_t i32ESEI_WriteFrameSingle(esei_ch_e eCh, uint16_t u16Data);


/****************************************************************************
 *
 * Function:      i32ESEI_ReadFrameSingle
 *
 * Purpose:       Read data from the default device addresed by SSO[0]
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       Data received from slave device on SSO[0]
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on device busy
 *
 * Limitations:   This function can be used only in a single-slave system
 *
 ***************************************************************************/
int32_t i32ESEI_ReadFrameSingle(esei_ch_e eCh, uint16_t* pu16Data);


/****************************************************************************
 *
 * Function:      i32ESEI_ReadFrameUni
 *
 * Purpose:       Unilateral read from default device addresed by SSO[0] and 
 *                simulatenous sending of a dummy value to the slave
 *
 * Inputs:        eCh  ESEI Channel
 *
 * Outputs:       Data received from slave device on SSO[0]
 *
 * Return Values: none
 *
 * Limitations:   This function can be used only in a Single-slave system
 *                for reading, but only on the master side
 *
 ***************************************************************************/
int32_t i32ESEI_ReadFrameUni(esei_ch_e eCh, uint16_t* pu16Data);


/****************************************************************************
 *
 * Function:       i32ESEI_WriteFrame
 *
 * Purpose:        Write one entry to the TX FIFO and specify to which
 *                 slave the entry should be sent 
 *
 * Inputs:         eCh         ESEI Channel
 *                 eCs         Selection of the slave to send the data
 *                 eToggleEn   Toggle between frames enable
 *                 eFrameSize  Frame size
 *                 u16Data     Data to be sent pointer
 *
 * Outputs:        none
 *
 * Return Values:  C_SUCCESS on success
 *                 C_FAILED on failure
 *
 * Limitations:    Multi-slave environment only
 *
 ***************************************************************************/
int32_t i32ESEI_WriteFrame(esei_ch_e eCh, esei_scid_e eCs, esei_en_e eToggleEn,
                           esei_ssz_e eFrameSize, uint16_t u16Data);


/****************************************************************************
 *
 * Function:       i32ESEI_ReadFrame
 *
 * Purpose:        Read one entry from the RX FIFO 
 *
 * Inputs:         eCh           ESEI Channel
 *                 peSlaveId     Slave ID that sent data
 *                 peParityRep   Parity report
 *                 pu8FrameSize  Frame size pointer
 *                 pu16Data      Received data
 *
 * Outputs:        none
 *
 * Return Values:  C_SUCCESS on success
 *                 C_FAILED on failure
 *
 * Limitations:    Multi-slave environment only
 *
 ***************************************************************************/
int32_t i32ESEI_ReadFrame(esei_ch_e eCh, esei_scid_e* peSlaveId,
                          esei_pr_e* peParityRep, uint8_t* pu8FrameSize,
                          uint16_t* pu16Data);


/****************************************************************************
 *
 * Function:       i32ESEI_ReadWriteFrame
 *
 * Purpose:        Write the given entry to the TX buffer and retrieve an
 *                 entry from the RX buffer
 *                 [Master mode only, full-duplex, multi-slave environment]
 *
 * Inputs:         eCh        ESEI Channel
 *                 stSend     Data frame to send with all transmission
 *                            parameters
 *                 pstRecv    Received data frame with all parameters
 *                 eToggleEn  Toggle between frames enable
 *
 * Outputs:        none
 *
 * Return Values:  C_SUCCESS on success
 *                 C_FAILED on failure
 *
 * Limitations:    Please note that this function polls with time-out for
 *                 RX buffer readiness as no IRQ mechanism is available at 
 *                 this level.
 *                 For this reason this function can be safely used only in
 *                 Master mode, because in this case the Cap-F software has
 *                 full control, and it will make sure that the transfer is
 *                 made before RX FIFO time-out is reached. However, in 
 *                 slave mode this can not be guaranteed.
 *                 When this function returns C_FAILED, the reason is either
 *                 the fact that the TX FIFO is full or the RX FIFO ready 
 *                 time-out was reached
 *
 ***************************************************************************/
int32_t i32ESEI_ReadWriteFrame(esei_ch_e eCh, esei_dSEntry_st stSend,
                               esei_dREntry_st* pstRecv, esei_en_e eToggleEn);


/****************************************************************************
 *
 * Function:       i32ESEI_ReadWriteData
 *
 * Purpose:        Write data to the TX buffer and retrieve data from the 
 *                 RX buffer
 *                 [Master mode only, full-duplex, multi-slave environment]
 *
 * Inputs:         eCh          ESEI Channel
 *                 pstSendData  Pointer to data entry array to be sent
 *                 pstRecvData  Pointer to array to store received data
 *                 u32Cnt       Number of Frames to store in TX-FIFO
 *
 * Outputs:        none
 *
 * Return Values:  The number of actualy transfered (read & write) frames
 *
 * Limitations:    Please note that this function polls with time-out for
 *                 RX buffer readiness as no IRQ mechanism is available at
 *                 this level.
 *                 For this reason this function can be safely used only in
 *                 Master mode, because in this case the Cap-F software has
 *                 full control, and it will make sure that the transfer is
 *                 made before RX FIFO time-out is reached. In slave mode
 *                 this cannot be guaranteed.
 *                 Please always check the return value in order to determine
 *                 the actual number of transferred data-frames.
 *
 ***************************************************************************/
int32_t i32ESEI_ReadWriteData(esei_ch_e eCh, const esei_dSEntry_st* pstSendData,
                              esei_dREntry_st* pstRecvData, uint32_t u32Cnt,
                              esei_en_e eToggleEn);


/****************************************************************************
 *
 * Function:       i32ESEI_IrqConfig
 *
 * Purpose:        Configures the module interrupt generation 
 *
 * Inputs:         eCh    ESEI Channel
 *                 stCfg  IRQ configuration request
 *
 * Outputs:        none
 *
 * Return Values:  none
 *
 * Limitations:    none
 *
 *
 ***************************************************************************/
void vESEI_IrqConfig(esei_ch_e eCh, esei_irqcfg_st stCfg);

/****************************************************************************/
/****************************************************************************/
/*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 1861  Rule 20.1 [R] : 
** |         No definition, redefinition, or undefinition of reserved words and
** |         standard library names performed on signed integer types  
** |       
** | CONS.  : allow
** | REASON : to use naming defined by HW registers, no conflict recognized 
** |
**  ------------------------------------------------------------------------
**
*****************************************************************************
****************************************************************************/


#endif /* ESEI_H */

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

