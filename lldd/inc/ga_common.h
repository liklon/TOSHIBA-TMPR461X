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
*   VERSION     : $Revision: 1.14 $
*   DATE        : $Date: 2015/07/21 12:30:20 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef GA_COMMON_H
#define GA_COMMON_H

/*======================================
             Include Files
=======================================*/
#include "captypes.h"

#define LLDD_GA_COMMON_H_REVISION     "$Revision: 1.14 $"
#define LLDD_GA_COMMON_H_TAG          "$Name: LLDD_1_7_GFX $"

/*==========================================================================
|                       GA Configuration Parameters                         |
 ==========================================================================*/
/*---------------------------------------
|        GA Sub-Module inclusion         |
 ---------------------------------------*/
/* Blitting Engine */
#define GA_USE_BLITTING

/* Transformation Engine */
#define GA_USE_TRANSFORM

/* Rotation Engine */
#define GA_USE_ROTATION

/* Drawing Engine */
#define GA_USE_DRAWING

/*---------------------------------------
|         GA List Configuration          |
 ---------------------------------------*/
/* Maximal Number of commands in one list */
#define GA_CMD_MAX    2048

/*---------------------------------------
|  Enable/Disable boundary check for     |
|         GA Command List                |
 ---------------------------------------*/
/* Enable/Disable boundary check in drivers for command buffer: */
/* #define GA_CMDSLIST_BOUNDARY_CHECK */


/* 1 double word more will be reserved by calculation of needed
   buffers for GA-API's. This is necesary to add later an END-Command to 
   finalize the command: 
*/   
#define RESERVED_FOR_END_CMD    1

/*======================================
                Defs
=======================================*/

/*--------------------------------------
|     GA General Purpose Registers      |
 --------------------------------------*/
#define GA_GPR0   0
#define GA_GPR1   1
#define GA_GPR2   2
#define GA_GPR3   3
#define GA_GPR4   4
#define GA_GPR5   5
#define GA_GPR6   6
#define GA_GPR7   7
#define GA_GPR8   8
#define GA_GPR9   9
#define GA_GPR10  10
#define GA_GPR11  11
#define GA_GPR12  12
#define GA_GPR13  13
#define GA_GPR14  14
#define GA_GPR15  15
#define GA_GPR16  16
#define GA_GPR17  17
#define GA_GPR18  18
#define GA_GPR19  19
#define GA_GPR20  20
#define GA_GPR21  21
#define GA_GPR22  22
#define GA_GPR23  23
#define GA_GPR24  24
#define GA_GPR25  25
#define GA_GPR26  26
#define GA_GPR27  27
#define GA_GPR28  28
#define GA_GPR29  29
#define GA_GPR30  30
#define GA_GPR31  31


/*--------------------------------------
|         GA Command Parameters         |
 --------------------------------------*/
/* Selection of module to wait on */
typedef enum tag_ga_modul_e
{
    GA_GDC0        = 0x0u,
    GA_FG0         = 0x1u,
    GA_GDC1        = 0x2u
} ga_modul_e;

/* Enables/Disables option */
typedef enum tag_ga_en_e
{
    GA_DIS         = 0x0u,     /* Disable/off */
    GA_EN          = 0x1u      /* Enable/on */
} ga_en_e;

/* Blending Order */
typedef enum tag_blendOrd_e
{
    GA_ONTO_DEST   = 0x0u,     /* Onto destination */
    GA_BEHIND_DEST = 0x1u      /* Behind destination */
} ga_blendOrd_e;

/* Color format selection */
typedef enum tag_ga_colFmt_e
{
    GA_RGB16       = 0x0u,      /* 16-bit RGB format */
    GA_RGBA32      = 0x1u       /* 32-bit RGBA format */
} ga_colFmt_e;

/*--------------------------------------
|        GA Command Construction        |
 --------------------------------------*/
/* Command Field Masks */
#define GA_MASK1           0x1u
#define GA_MASK2           0x3u
#define GA_MASK3           0x7u
#define GA_MASK4           0xfu
#define GA_MASK5           0x1fu
#define GA_MASK6           0x3fu
#define GA_MASK7           0x7fu
#define GA_MASK8           0xffu
#define GA_MASK9           0x1ffu
#define GA_MASK10          0x3ffu
#define GA_MASK12          0xfffu
#define GA_MASK14          0x3fffu
#define GA_MASK15          0x7fffu
#define GA_MASK16          0xffffu
#define GA_MASK22          0x3fffffu
#define GA_MASK24          0xffffffu
#define GA_MASK32          0xffffffffu
#define GA_MASK36          0xfffffffffull
#define GA_MASK48          0xffffffffffffull
#define GA_MASK64          0xffffffffffffffffull

/* GA Unit selection */
#define GA_SCHED           0x0u
#define GA_BLITING         0x1u
#define GA_DRAWING         0x2u
#define GA_ROTATION        0x3u
#define GA_TRANSFORM       0x4u

/*** Command Codes ***/
#define GA_CMC_LGPR        0x1u
#define GA_CMC_CSWVSYNC    0x2u
#define GA_CMC_CSUIC	     0x3u
#define GA_CMC_CSGDC0CC	   0x4u
#define GA_CMC_CSGDC1CC	   0x5u
#define GA_CMC_END         0xffu

/* Blitting Engine Command Codes */

#define GA_CMC_BLTO16      0x02u
#define GA_CMC_BLTO32      0x04u
#define GA_CMC_BLTORLEI16  0x0au
#define GA_CMC_BLTORLEI24  0x06u
#define GA_CMC_BLTORLEI24A 0x0Eu
#define GA_CMC_BLTORLEI32  0x0cu
#define GA_CMC_BLTOP16     0x12u
#define GA_CMC_BLTOP32     0x14u
#define GA_CMC_BLTB16      0x03u
#define GA_CMC_BLTB32      0x07u
#define GA_CMC_BLTBRLEI16  0x0bu
#define GA_CMC_BLTBRLEI24  0x05u
#define GA_CMC_BLTBRLEI24A 0x0fu
#define GA_CMC_BLTBRLEI32  0x0du
#define GA_CMC_BLTBP16     0x13u
#define GA_CMC_BLTBP32     0x17u

/* Transformation Engine Command Code */
#define GA_CMC_TRANSF      0x01u
#define GA_CMC_TRANSFB     0x00u

/* Rotation Engine Command Code */
#define GA_CMC_ROT         0x01u
#define GA_CMC_ROTB        0x00u

/* Drawing Engine Command Codes */
#define GA_CMC_DE_DLRGBA32 0x03u
#define GA_CMC_DE_DLRGB16  0x04u
#define GA_CMC_DE_DTRGBA32 0x05u
#define GA_CMC_DE_DTRGB16  0x06u

/* Command Field Offsets */
#define GA_ENG_OFF         60
#define GA_LEN_OFF         56
#define GA_CMC_OFF         48
#define GA_SPC_OFF          0

/* Command Field Masks */
#define GA_ENG_MSK         (GA_MASK3)
#define GA_LEN_MSK         (GA_MASK4)
#define GA_CMC_MSK         (GA_MASK8)
#define GA_SPC_MSK         (GA_MASK48)

/* Macro for command field positioning */
#define GA_FP(val, offset, mask) (((uint64_t)(val) & (mask)) << (offset))

/* GA Command Fields (Engine, Length, Command code, Cmd Specific Params.)*/
#define GA_ENG(Engine) (GA_FP((Engine), GA_ENG_OFF, GA_ENG_MSK))
#define GA_LEN(Len)    (GA_FP((Len)   , GA_LEN_OFF, GA_LEN_MSK))
#define GA_CMC(Code)   (GA_FP((Code)  , GA_CMC_OFF, GA_CMC_MSK))
#define GA_SPC(spec)   (GA_FP((spec)  , GA_SPC_OFF, GA_SPC_MSK))

/* GA Command Construction Macro */
#define GA_CMN(Engine, Len, CmdCode, CmdSpec) ((uint64_t)0x0ull    | \
                                                GA_ENG((Engine))   | \
                                                GA_LEN((Len))      | \
                                                GA_CMC((CmdCode))  | \
                                                GA_SPC((CmdSpec)))

/*=========================================================================
|                        SCHEDULER OPERATION COMMANDS                      |
 ==========================================================================*/
/*--------------------------------------------------------------------------
|
|  Command:   Load General-Purpose Register Command (LGPR)
|
|  Descr  :   The Load General-Purpose Register command is used to configure
|             one out of the 32 General-Purpose Registers. The command
|             specific parameter for this command is the number of the
|             register that should be loaded and the value itself.
|
|  Params:    regNr   - The number of the General-Purpose Register that
|                       should be loaded
|
|             uiVal   - Value that should be stored within the selected
|                       register. If the register does not encapsulate
|                       32 bits the value within the command has to be right
|                       aligned.
|
 -------------------------------------------------------------------------*/
#define GA_LOAD(regNr, uiVal) (GA_CMN(GA_SCHED, 1, GA_CMC_LGPR,       \
                               GA_FP ((regNr), 32, GA_MASK5)      |   \
                               GA_FP ((uiVal),  0,  GA_MASK32)))

/*--------------------------------------------------------------------------
|
|  Command:   END Command (CSEND)
|
|  Descr  :   The CSEND command must be placed at the end of every command
|             list. It signals the Command Scheduler that all commands have
|             been executed. When the Command Scheduler is detecting this
|             mark, a flag in the status register signals that the command
|             list was executed. Optionally an interrupt is generated.
|
|  Params:    none
|
 -------------------------------------------------------------------------*/
#define GA_END() (GA_CMN(GA_SCHED, 0x1u, GA_CMC_END,0x0u))

/*--------------------------------------------------------------------------
|
|  Command:   Wait VSYNC Command (CSWVSYNC)
|
|  Descr  :   The CSWVSYNC command can be used to synchronize parts of the
|             command list with the vertical synchronization signal VSYNC
|             from the GDC or the Frame Grabber.
|
|             When the Command Scheduler is reading the CSWVSYNC command
|             it waits until the next vertical synchronization of the
|             display/camera input takes place before executing the next
|             command.
|
|  Params:    module   -  VSYNC select:
|                         Use: GA_GDC0     - Wait on GDC0
|                              GA_FG0      - Wait on FG0
|                              GA_GDC1     - Wait on GDC1
|                              GA_FG1      - Wait on FG1
|
|
 -------------------------------------------------------------------------*/
#define GA_WAIT(module) (GA_CMN(GA_SCHED, 0x1u, GA_CMC_CSWVSYNC,        \
                         GA_FP ((module), 0, GA_MASK2)))

/*--------------------------------------------------------------------------
|
|  Command:   User Interrupt Command (CSUIC)
|
|  Descr  :   The CSUIC command can be used to signal the MCU that a
|             certain part of the Command List is already executed or
|             will now start execution.
|
|  Params:    interrupt number:
|                          Use: 0 - 23
|                               values > 23 will be ignored
|
 -------------------------------------------------------------------------*/
#define GA_USERINTERRUPT(number) (GA_CMN(GA_SCHED, 0x1u, GA_CMC_CSUIC,    \
                                  GA_FP ((number), 0, GA_MASK6)))

/*--------------------------------------------------------------------------
|
|  Command:   Command Scheduler GDC0 Configuration Command (CSGDC0CC)
|
|  Descr  :   The CSGDC0CC command can be used to change the content of GDC0 registers
|
|  Params:    
|             register offset:
|                          16-bits GDC0 adress register offest
|
|             register value:
|                          32-bits
|
 -------------------------------------------------------------------------*/
#define GA_GDC0CONFIG(regOffset, value) (GA_CMN(GA_SCHED,   0x1u, GA_CMC_CSGDC0CC,  \
                                         GA_FP((regOffset), 32, GA_MASK16)      |   \
                                         GA_FP((value),      0, GA_MASK32)))

/*--------------------------------------------------------------------------
|
|  Command:   Command Scheduler GDC1 Configuration Command (CSGDC1CC)
|
|  Descr  :   The CSGDC1CC command can be used to change the content of GDC1 registers
|
|  Params:    
|             register offset:
|                          16-bits GDC1 adress register offest
|
|             register value:
|                          32-bits
|
 -------------------------------------------------------------------------*/
#define GA_GDC1CONFIG(regOffset, value) (GA_CMN(GA_SCHED,   0x1u, GA_CMC_CSGDC1CC,  \
                                         GA_FP((regOffset), 32, GA_MASK16)      |   \
                                         GA_FP((value),      0, GA_MASK32)))


/*======================================
              Structures
=======================================*/
/* Command List Structure */
typedef struct tag_ga_list_st
{
    uint64_t  ullCommands[GA_CMD_MAX] ;
    uint64_t* pu64Current;
    uint32_t  u32UsedDoubleWords; /* used or needed double words for an  GA-API */
    int32_t   i32FreeSpaceStat;   /* C_SUCCESS: OK no space free error,
                                     C_FAILED:  No free space for GA-API */
} ga_list_st ;

/****************************************************************************/


#endif /* GA_COMMON_H */

/****************************************************************************/


/****************************************************************************
*****************************************************************************
**             >>>>     MISRA-C 2004 Deviation Report     <<<<
**                          (MISRA Rule Violation)
**
**  File: ga_common.h
**  $Revision: 1.14 $
**  $Date: 2015/07/21 12:30:20 $
**
** **************************************************************************
**  ------------------------------------------------------------------------
** |
** | RULE   : 
** | CONS.  : 
** | REASON :
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

