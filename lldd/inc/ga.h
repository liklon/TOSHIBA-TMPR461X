/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Graphic Accelerator
*                 Reference Low-Level Driver
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Graphic Accelerator
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.19 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef GA_H
#define GA_H

/*======================================
             Include Files
=======================================*/
#include "ga_common.h"
/*======================================
                Defs
=======================================*/

#define LLDD_GA_H_REVISION     "$Revision: 1.19 $"
#define LLDD_GA_H_TAG          "$Name: LLDD_1_7_GFX $"

/* Timeout */
#define GA_TIMEOUT  10000

/* Size of Draw Engine Filter RAM (in doublewords) */
#define GA_DE_FILTER_SIZE 64

/* GA Interrupt Masks */
#define GA_IRQ_MASK_CENDIM  0x00000001U    /* GA Command End Interrupt Mask.                          */
#define GA_IRQ_MASK_CSCEIM  0x00000004U    /* Command Scheduler Command Error Interrupt Mask          */
#define GA_IRQ_MASK_CSLEIM  0x00000008U    /* Command Scheduler Command List Executed Interrupt Mask  */
#define GA_IRQ_MASK_WBWIM   0x00000010U    /* GA Write Buffer Write Bus-Error Interrupt Mask          */
#define GA_IRQ_MASK_WBRIM   0x00000020U    /* GA Write Buffer Read Bus-Error Interrupt Mask           */
#define GA_IRQ_MASK_CBIM    0x00000040U    /* GA Cache Buffer Bus-Error Interrupt Mask                */
#define GA_IRQ_MASK_RBIM    0x00000080U    /* GA Read Buffer Bus-Error Interrupt Mask                 */
#define GA_IRQ_MASK_CSLUIM  0xFFFFFF00U    /* Command List User Interrupt Mask 0 – 23                 */

/*======================================
                Enums
=======================================*/
/****************************************
*         GAIMR Param.Values
****************************************/
/* IRQ Mask */
typedef enum tag_ga_irqen_e
{
    GA_IRQ_EN  = 0x1u,     /* Enable IRQ */
    GA_IRQ_DIS = 0x0u      /* Disable IRQ */
} ga_irqen_e;

/* Bus type */
typedef enum tag_ga_bus_type_e
{
    GA_READ_BUF_BUS        = 0x00U,
    GA_CACHE_BUF_BUS       = 0x01U,
    GA_WRITE_BUF_READ_BUS  = 0x02U,
    GA_WRITE_BUF_WRITE_BUS = 0x03U,
    GA_MAX_TYPE_BUS        = 0x04U
} ga_bus_type_e;

/* Read / Write Direction */
typedef enum tag_ga_buserr_dir_e
{
    GA_BUSERR_READ_TRANSF   = 0x0U,
    GA_BUSERR_WRITE_TRANSF  = 0x1U
} ga_buserr_dir_e;

/* Burs error Type */
typedef enum tag_ga_buserr_bursttype
{
    GA_BUSERR_BURST_TYPE_FIXED   = 0x0U,
    GA_BUSERR_BURST_TYPE_INCR    = 0x1U
} ga_buserr_bursttype;

/* Burst Size */
typedef enum tag_ga_buserr_burstsize
{
    GA_BUSERR_BURST_1BYTE     = 0x0U,
    GA_BUSERR_BURST_2BYTE     = 0x1U,
    GA_BUSERR_BURST_4BYTE     = 0x2U,
    GA_BUSERR_BURST_81BYTE    = 0x3U,
    GA_BUSERR_BURST_16BYTE    = 0x4U,
    GA_BUSERR_BURST_32BYTE    = 0x5U,
    GA_BUSERR_BURST_64BYTE    = 0x6U,
    GA_BUSERR_BURST_128BYTE   = 0x7U
} ga_buserr_burstsize;


/* Response Type */
typedef enum tag_ga_buserr_resptype
{
    GA_BUSERR_RESP_OK        = 0x0U,
    GA_BUSERR_RESP_EXOKAY    = 0x1U,
    GA_BUSERR_RESP_SLVERR    = 0x2U,
    GA_BUSERR_RESP_DECERR    = 0x3U
} ga_buserr_resptype;

/* Memory Protection Region */
typedef enum tag_ga_memory_region_e
{
    GA_MEMORY_PROT_REGION_0   = 0x0U,
    GA_MEMORY_PROT_REGION_1   = 0x1U,
    GA_MEMORY_PROT_REGION_MAX = 0x2U
} ga_memory_region_e;

/*======================================
              Structures
=======================================*/
/* GA bus Error Control Signal-Structure */
typedef struct tag_ga_bus_err_ctrl_st
{
    ga_buserr_dir_e      eDirection;       /* Read / Write direction */
    ga_buserr_bursttype  eBurstType;       /* Burst type */
    ga_buserr_burstsize  eBurstSize;       /* Burst size */
    ga_buserr_resptype   eRespType;        /* Response Type */
    uint8_t              u8ByteEnables;    /* Byte-enables for the erroneous transfer. */
    uint8_t              u8ID;             /* ID tag of the read/write transaction that triggered an error response. */
    uint8_t              u8BurstLength;    /* Burst length of the read/write transaction that triggered an error response */
} ga_bus_err_ctrl_st;

/*======================================
      Exported Function Prototypes
=======================================*/

/****************************************************************************
 *
 * Function:      vGA_GetVersion
 *
 * Purpose:       Retrieve pointers to module and header revision and tag string
 *
 * Inputs:        none
 *
 * Outputs:       pau8ModuleRevision - pointer to module revision string
 *                pau8ModuleTag      - pointer to module tag string
 *                pau8HeaderRevision - pointer to header revision string
 *                pau8HeaderTag      - pointer to header tag string
 *                pau8CommonRevision - pointer to common header revision string
 *                pau8CommonTag      - pointer to common header tag string
 *                pau8IORevision     - pointer to IO header revision string
 *                pau8IOTag          - pointer to IO header tag string
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                    uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                    uint8_t** pau8CommonRevision, uint8_t** pau8CommonTag,
                    uint8_t** pau8IORevision, uint8_t** pau8IOTag);


/****************************************************************************
 *
 * Function:      vGA_ResetMaxUsedBuffSize
 *
 * Purpose:       Resets the counter for used buffer of command list
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: used size buffer in Double Words
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ResetMaxUsedBuffSize(void);


/****************************************************************************
 *
 * Function:      u32Ga_GetMaxUsedBuffSize
 *
 * Purpose:       To get max. used size of command buffer. This API can be
 *                used to optimize the need size of "GA_CMD_MAX" in ga_list_st
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: used size buffer in Double Words
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32GA_GetMaxUsedBuffSize(void);


/****************************************************************************
 *
 * Function:      i32GA_GetLastCmdBuffStatus
 *
 * Purpose:       returns the information if there was enough space free for
 *                command over API
 *
 * Inputs:        pstCmdList - Pointer to Command List
 *
 * Outputs:       none
 *
 * Return Values: space status for command list
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32GA_GetLastCmdBuffStatus(ga_list_st* pstCmdList);


/****************************************************************************
 *
 * Function:      u32GA_GetLastCmdSize
 *
 * Purpose:       returns the uesed buffer size for last API call (in case it
 *                was enough memory in buffer) or it returns needed size of buffer
 *                for last API call (if there was not enough memory in command buffer)
 *
 * Inputs:        pstCmdList - Pointer to Command List
 *
 * Outputs:       none
 *
 * Return Values: sized of used buffer
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32GA_GetLastCmdSize(ga_list_st* pstCmdList);


/****************************************************************************
 *
 * Function:      i32GA_CheckList
 *
 * Purpose:       To check whether there is enough space in command buffer
 *                to wrote some doble words 
 *
 * Inputs:        pstCmdList  - pointer to command list
 *                u32NeededDW - needed double words 
 *
 * Outputs:       none
 *
 * Return Values: C_FAILED  requested number of commands will not fit into list
 *                C_SUCCESS requested number of commands will fit into list   
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32GA_CheckList(ga_list_st* pstCmdList, uint32_t u32NeededDW);


/****************************************************************************
 *
 * Function:      vGA_ResetList
 *
 * Purpose:       Resets the Command List
 *
 * Inputs:        pstCmdList - Pointer to command list
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   The pointer to current list position will be reset, the
 *                content of the list will remain un-touched.
 *
 ***************************************************************************/
void vGA_ResetList(ga_list_st* pstCmdList);


/****************************************************************************
 *
 * Function:      vGA_CloseList
 *
 * Purpose:       Closes the given list by inserting CSEND command
 *
 * Inputs:        pstCmdList - Pointer to Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_CloseList(ga_list_st* pstCmdList);


/****************************************************************************
 *
 * Function:      vGA_SyncList
 *
 * Purpose:       Inserts the VSYNC command in the command list in order to
 *                synchronize the execution of the list with vertical (VSYNC)
 *                signal from the GDC or Frame Grabber. When the command
 *                sceduler reaches this command it will stop the list
 *                execution until next VSYNC signal.
 *
 * Inputs:        eModul     - Modul selection to wait on (GDC/FG)
 *                pstCmdList - Pointer to Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_SyncList(ga_modul_e eModule, ga_list_st* pstCmdList);


/****************************************************************************
 *
 * Function:      vGA_SetUserInt
 *
 * Purpose:       defines Interrupt to CPU
 *
 * Inputs:        u8Number   - Interrupt number
 *                pstCmdList - Pointer to the Command List
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_SetUserInt(uint8_t u8Number, ga_list_st* pstCmdList);


/****************************************************************************
 *
 * Function:      vGA_Enable
 *
 * Purpose:       Enables/Disables the Graphic Accelerator
 *
 * Inputs:        eEn - Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_Enable(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_ReadAheadEnable
 *
 * Purpose:       Enables/Disables ReadBuffer Read Ahead feature
 *
 * Inputs:        eEn - Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ReadAheadEnable(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      i32GA_Reset
 *
 * Purpose:       Resets the Graphic Accelerator
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS - Reset successful
 *                C_FAILED  - Reset timeout (Reset was not completted in
 *                            predefined time interval)
 *
 * Limitations:   The function will wait the reset to complete (it can take
 *                until recent bus cycle execution is finished)
 *
 ***************************************************************************/
int32_t i32GA_Reset(void);


/****************************************************************************
 *
 * Function:      vGA_SetCmdListAddr
 *
 * Purpose:       Sets the physical address of the current command list
 *
 * Inputs:        u32Addr  - Physical address of the command list
 *                           (Must be 64-bit alligned -> uiAddr[2:0] = 0x0)
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   Make sure that when calling this function command scheduler
 *                is NOT executing a command list !!! Please note, that after
 *                the address is once written, the GA will automatically
 *                start the command list execution.
 *
 ***************************************************************************/
void vGA_SetCmdListAddr(uint32_t u32Addr);


/****************************************************************************
 *
 * Function:      u8GA_GetStatus
 *
 * Purpose:       Reads the Graphic Accelerator Status register
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: GA Status Register (GASR) value
 *
 * Limitations:   The caller must parse returned status byte. For this
 *                purpose see the description of GASR Register.
 *
 ***************************************************************************/
uint8_t u8GA_GetStatus(void);


/****************************************************************************
 *
 * Function:      boGA_CmdListFinished
 *
 * Purpose:       Indicates that the operation of a command list was finished or
 *                the GA was reset. This bit will be set to zero, when a new pointer
 *                is written.
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE:  command List Finished (ready to get new values)
 *                C_FALSE: command List is not Finished (not ready to get new values)
 *
 * Limitations: 
 *
 ***************************************************************************/
bool_t boGA_CmdListFinished(void);


/****************************************************************************
 *
 * Function:      boGA_CmdListError
 *
 * Purpose:       This function shows if the Command Scheduler detects an invalid command
 *                or not. The Graphics Accelerator halts its operation and has to be reset
 *                if error is any detected. 
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE:  any Error detected by command list
 *                C_FALSE: no error detected
 *
 * Limitations:   
 *
 ***************************************************************************/
bool_t boGA_CmdListError(void);


#ifndef _EXTENDED_GA_APIS_DISABLED_
/****************************************************************************
 *
 * Function:      boGA_CmdReg_IsBusy
 *
 * Purpose:       This function shows when any of the GA engines is currently operating.
 *                Then also the write access to many registers is prohibited.
 *                NOTE:
 *                  This function should be used from user by using direct comamnd 
 *                  registers instead of command list, before writing new commands. 
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: C_TRUE:  GA engine is busy.
 *                C_FALSE: GA engine is ready (not busy).
 *
 * Limitations:   
 *
 ***************************************************************************/
bool_t boGA_CmdReg_IsBusy(void);
#endif


/****************************************************************************
 *
 * Function:      u32GA_GetIrqCause
 *
 * Purpose:       Reads the Graphic Accelerator Interrupt Cause
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: GA IRQ Cause value
 *
 * Limitations:   The calling function must parse returned IRQ cause byte.
 *                For this purpose see the GAICR register description.
 *                Please note that the funtion will automatically clear
 *                the interrupt source !!!
 *
 ***************************************************************************/
uint32_t u32GA_GetIrqCause(void);

/****************************************************************************
 *
 * Function:      vGA_ClearIrqCause
 *
 * Purpose:       Clears the Graphic Accelerator Interrupt Cause
 *
 * Inputs:        u32CauseMask: Mask to clear the bits ("1" in the mask means clear Bit)
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearIrqCause(uint32_t u32CauseMask);


/****************************************************************************
 *
 * Function:      vGA_SetIrqMask
 *
 * Purpose:       Sets all GA Interrupt masks in one shot
 *
 * Inputs:        u32Mask - Interrupt Mask. For this purpose you may use defines:
 *                         GA_IRQ_MASK_CENDIM, GA_IRQ_MASK_CSCEIM, GA_IRQ_MASK_CSLEIM,
 *                         GA_IRQ_MASK_WBWIM, GA_IRQ_MASK_WBRIM, GA_IRQ_MASK_CBIM,
 *                         GA_IRQ_MASK_RBIM, GA_IRQ_MASK_CSLUIM   
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_SetIrqMask(uint32_t u32Mask);


/****************************************************************************
 *
 * Function:      vGA_EnableUserIrq
 *
 * Purpose:       Enables/Disables interrupt to CPU
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *		  u8Number - interrupt line to be enabled/disabled
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableUserIrq(uint8_t u8Number, ga_en_e eEn);


#ifndef _EXTENDED_GA_APIS_DISABLED_
/****************************************************************************
 *
 * Function:      vGA_CmdReg_EnableIrqCmdEnd
 *
 * Purpose:       Enables/Disables GA Command End Interrupt
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_CmdReg_EnableIrqCmdEnd(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_CmdReg_ClearIrqCmdEnd
 *
 * Purpose:       Clears GA Command End Interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_CmdReg_ClearIrqCmdEnd(void);


#endif
/****************************************************************************
 *
 * Function:      vGA_EnableIrqCSLEI
 *
 * Purpose:       Enables/Disables Command Scheduler Command List
 *                Executed Interrupt
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableIrqCSLEI(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_ClearIrqCSLEI
 *
 * Purpose:       Clears Command Scheduler Command List Executed Interrupt. 
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearIrqCSLEI(void);


/****************************************************************************
 *
 * Function:      vGA_EnableIrqCSCEI
 *
 * Purpose:       Enables/Disables Command Scheduler Command Error IRQ
 *                Interrupt
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableIrqCSCEI(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_ClearIrqCSCEI
 *
 * Purpose:       Clears GA Command Scheduler Command Error IRQ
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearIrqCSCEI(void);


/****************************************************************************
 *
 * Function:      vGA_SetGADelay
 *
 * Purpose:       Sets the minimum delay in System Clock cycles between two
 *                consecutive memory accesses performed by any Graphics 
 *                Accelerator engine
 *
 * Inputs:        u16Delay: Delay Value (0x0000 .. 0xFFFF)
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_SetGADelay(uint16_t u16Delay);


/****************************************************************************/

#ifndef _EXTENDED_GA_APIS_DISABLED_
/****************************************************************************
 *
 * Function:      vGA_EnableIrqGAWBWI
 *
 * Purpose:       Enables/Disables GA Write Buffer Write Error Interrupt
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableIrqGAWBWI(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_ClearIrqGAWBWI
 *
 * Purpose:       Clears GA Write Buffer Write Error Interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearIrqGAWBWI(void);


/****************************************************************************
 *
 * Function:      vGA_EnableIrqGAWBRI
 *
 * Purpose:       Enables/Disables GA Write Buffer Read Error Interrupt
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableIrqGAWBRI(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_ClearIrqGAWBRI
 *
 * Purpose:       Clears GA Write Buffer Read Error Interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearIrqGAWBRI(void);


/****************************************************************************
 *
 * Function:      vGA_EnableIrqGACBIM
 *
 * Purpose:       Enables/Disables GA Cache Buffer Error Interrupt
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableIrqGACBI(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_ClearIrqGACBI
 *
 * Purpose:       Clears GA Cache Buffer Error Interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearIrqGACBI(void);


/****************************************************************************
 *
 * Function:      vGA_EnableIrqGARBI
 *
 * Purpose:       Enables/Disables GA Read Buffer Error Interrupt
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableIrqGARBI(ga_en_e eEn);



/****************************************************************************
 *
 * Function:      vGA_ClearIrqGARBI
 *
 * Purpose:       Clears GA Read Buffer Error Interrupt
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearIrqGARBI(void);


/****************************************************************************
 *
 * Function:      vGA_ClearUserIrq
 *
 * Purpose:       Clears GA Command List User Interrupt 0 - 23
 *
 * Inputs:        u8CmdListIntr: No. of Interruot (0..23) to be cleared
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearUserIrq(uint8_t u8CmdListIntr);


/****************************************************************************
 *
 * Function:      boGA_GetBusErrAddr
 *
 * Purpose:       Returns the address after bus error on GA 
 *
 * Inputs:        eBusType  Related Bus
 *
 * Outputs:       pu32BusErrAddr: Pointer to bus error address
 *
 * Return Values: No Error?
 *                C_TRUE:  No Error
 *                C_FALSE: NULL pointer
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGA_GetBusErrAddr(ga_bus_type_e eBusType, uint32_t* pu32BusErrAddr);


/****************************************************************************
 *
 * Function:      boGA_GetBusErrCtrlStatus
 *
 * Purpose:       Returns the triggering access’s control status after bus error on GA
 *
 * Inputs:        eBusType  Related Bus
 *
 * Outputs:       control status structure
 *
 * Return Values: No Error?
 *                C_TRUE:  No Error
 *                C_FALSE: Wrong parameter
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGA_GetBusErrCtrlStatus(ga_bus_type_e eBusType, ga_bus_err_ctrl_st* pstCtrlStatus);


/****************************************************************************
 *
 * Function:      boGA_SetMemoryProtRegionAddr
 *
 * Purpose:       Defines the lower and upper address of the memory region
 *                0 or 1 (primary, secondary) GA is allowed to perform write accesses.
 *                Write accesses outside the memory regions are discarded.
 *                NOTE:
 *                   The memory regions are defined with a granularity of 4Kbyte.
 *
 * Inputs:        eRegion  Related Region (0/1)
 *                u32LowAddress: Lower protected address
 *                u32HighAddress: Higher protected address
 *
 * Outputs:       none
 *
 * Return Values: No Error?
 *                C_TRUE:  No Error
 *                C_FALSE: Wrong parameter
 *
 * Limitations:   Process one controller at a time
 *
 ***************************************************************************/
bool_t boGA_SetMemoryProtRegionAddr(ga_memory_region_e eRegion, uint32_t u32LowAddress, uint32_t u32HighAddress);


/****************************************************************************
 *
 * Function:      vGA_EnableMemoryProtecConfigIrq
 *
 * Purpose:       Enables/Disables interrupt, set if a non-privileged access 
 *                tries to write to GAMR0L, GAMR0H, GAMR1L, GAMR1H, GAMPICR,
 *                or GAMPIMR.
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableMemoryProtecConfigIrq(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_EnableMemoryProtecAccessIrq
 *
 * Purpose:       Enables/Disables interrupt, set if GA tries to write to 
 *                memory outside the address range defined by GAMR0L-GAMR0H 
 *                and GAMR1L-GAMR1H.
 *
 * Inputs:        eEn - Interrupt Enable/Disable parameter
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_EnableMemoryProtecAccessIrq(ga_en_e eEn);


/****************************************************************************
 *
 * Function:      vGA_ClearMemoryProtecConfigIrq
 *
 * Purpose:       Clears interrupt generated if GA tries to have a non-privileged access 
 *                tries to write to protection control registers
 *                (GAMR0L, GAMR0H, GAMR1L, GAMR1H, GAMPICR, or GAMPIMR)
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearMemoryProtecConfigIrq(void);


/****************************************************************************
 *
 * Function:      vGA_ClearMemoryProtecAccessIrq
 *
 * Purpose:       Clears interrupt generated if GA tries to write to memory 
 *                outside the address range defined by GAMR0L-GAMR0H and GAMR1L-GAMR1H
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vGA_ClearMemoryProtecAccessIrq(void);


/****************************************************************************
 *
 * Function:      u32GA_GetMemoryProtecErr_CaptAddr
 *
 * Purpose:       Get the address of the first write access performed by the 
 *                Write Buffer’s write interface that caused a memory protection
 *                violation. The register is automatically set by the Graphics 
 *                Accelerator in case of a protection violation, it is reset to
 *                zero automatically if the corresponding interrupt bit GAMPI is
 *                cleared in the Graphics Accelerator Interrupt Cause Register (GAMPICR).
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: Address caused portection error
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32GA_GetMemoryProtecErr_CaptAddr(void);


/****************************************************************************
 *
 * Function:      boGA_SetGeneralPurposeRegister
 *
 * Purpose:       Set one of 32 Purpose Registers of GA, which are used to define  
 *                the required parameters for the triggered engine.
 *                Read access is possible all the time, write access is only allowed
 *                if no engine is currently operating (GASR.BUSY=0). Nevertheless, 
 *                it is recommended to configure these registers using Command Lists.
 *
 * Inputs:        u8RegNo      No. of Register (0..31)
 *                u32RegValue: Register value to be written
 *
 * Outputs:       none
 *
 * Return Values: No Error?
 *                C_TRUE:  No Error
 *                C_FALSE: Wrong RegNo or GA was busy and cannot accept new register values.
 *
 * Limitations:   Process one controller at a time. Api cannot be executed if GA is busy.
 *
 ***************************************************************************/
bool_t boGA_SetGeneralPurposeRegister (uint8_t u8RegNo, uint32_t u32RegValue);


/****************************************************************************
 *
 * Function:      boGA_GetGeneralPurposeRegister
 *
 * Purpose:       Get content of one of 32 Purpose Registers of GA, which are used   
 *                to define the required parameters for the triggered engine.
 *
 * Inputs:        u8RegNo       No. of Register (0..31)
 *                pu32RegValue: Pointer to Register value to be read
 *
 * Outputs:       none
 *
 * Return Values: No Error?
 *                C_TRUE:  No Error
 *                C_FALSE: Wrong RegNo NULL pointer 
 *
 * Limitations:   Process one controller at a time. Api cannot be executed if GA is busy.
 *
 ***************************************************************************/
bool_t boGA_GetGeneralPurposeRegister (uint8_t u8RegNo, uint32_t* pu32RegValue);


/****************************************************************************
 *
 * Function:      boGA_SetCommandRegisterLowHigh
 *
 * Purpose:       Set command register directly (as alternative to command List).
 *                For this mode, user should take care that GA should be ready 
 *                (not busy) before writng in registers. 
 *
 * Inputs:        u32LowValue:  Lower 32 bits of 64 bits command (0..31)
 *                u32HighValue: Higher 32 bits of 64 bits command (32..63)
 *                NOTE:
 *                  1) API should write first Lowe Part and then higher Part. 
 *                    By writing of higehr word thorugh API GA will be trigegred 
 *                    to execute command if it was not busy before.
 *                  2) Related general purpose registers for command should be
 *                     written before, 
 *
 * Outputs:       none
 *
 * Return Values: No Error?
 *                C_TRUE:  No Error
 *                C_FALSE: GA was busy and cannot accept new register values.
 *
 * Limitations:   Process one controller at a time. Api cannot be executed if GA is busy.
 *
 ***************************************************************************/
bool_t boGA_SetCommandRegisterLowHigh (uint32_t u32LowValue,  uint32_t u32HighValue);


#endif /* _EXTENDED_GA_APIS_DISABLED_ */

#endif /* GA_H */

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

