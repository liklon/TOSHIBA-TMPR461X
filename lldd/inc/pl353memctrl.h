/****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   DESCRIPTION : Memory Controller LLD for NOR and NAND Flash devices header
*                 file.
*****************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : SMC (Static Memory Controller)
*   LIBRARIES   :
*****************************************************************************
*   VERSION     : $Revision: 1.8 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary and Confidential
*****************************************************************************/
#ifndef MEMCTRL_H
#define MEMCTRL_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"                   /* Cap-Bt Data types header */

/* Function results */
typedef enum tag_MemCtrlResult_e
{
   MEMCTRL_RESULT_OK = 0
} MemCtrlResult_e;                          /* definition of enum type */

/* *** MEMCTRL BASE ADDRESS and REGISTERS ****/
#define MEMCTRL_BASE                (0xC0200000U)
#define NORFLASH_BASE_ADDRESS       (0x20000000U)
#define MEMCTRL_NAND_CHIP_ADDRESS   (0x24000000U)

/* Read-Only memc_status REGISTER */
#define MEMCTRL_MEMC_STATUS   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(0x000U))))

/* Write-Only mem_cfg_set REGISTER */
#define MEMCTRL_MEM_CFG_SET   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(0x008U))))

/* ReGISTER and "BUSY ENABLE" value for NAND Ready/!Busy line signalling */
#define MEMCTRL_BUSY_CFG_SET   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(0x204U))))
#define MEMCTRL_BUSY_ENABLE   (0x20U)

/* Write-Only mem_cfg_set REGISTER */
#define MEMCTRL_MEM_CFG_CLR   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(0x00CU))))
/* INT_CLR_1 register bit-shift */
#define MEMCTRL_INT_CLR_1_SFT   (4)         /* I/F 1 (NAND) IRQ clear */
#define MEMCTRL_INT_CLR_1_BIT    ((0x1U)<<(MEMCTRL_INT_CLR_1_SFT))

/* Write-Only direct_cmd REGISTER */
#define MEMCTRL_DIRECT_CMD   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(0x010U))))
/* Write-Only set_cycles REGISTER */
#define MEMCTRL_SET_CYCLES   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(0x014U))))

/* Write-Only set_opmode REGISTER */
#define MEMCTRL_SET_OPMODE   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(0x018U))))
/* Read-Only periph_id_x [x:= 0..3] REGISTER */
#define MEMCTRL_PERIPH_ID(x) (*(TYPES_REG8 ((MEMCTRL_BASE)+((0xFE0U)+((x)*(4U))))))

/* memc_status register bit-shifts */
#define MEMCTRL_RAW_INT_STATUS0_SFT   (5)   /* SRAM / NOR I/F status */
#define MEMCTRL_RAW_INT_STATUS1_SFT   (6)   /* NAND I/F status */
/* memc_status register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_RAW_INT_STATUS0_BIT    ((0x1U)<<(MEMCTRL_RAW_INT_STATUS0_SFT))
#define MEMCTRL_RAW_INT_STATUS1_BIT    ((0x1U)<<(MEMCTRL_RAW_INT_STATUS1_SFT))

/* direct_cmd register bit-shifts */
#define MEMCTRL_ADDR_SFT   (0)
#define MEMCTRL_SET_CRE_SFT   (20)
#define MEMCTRL_CMD_TYPE_SFT   (21)
#define MEMCTRL_CHIP_SEL_SFT   (23)
/* direct_cmd register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_ADDR_MSK   ((0xFFFFFU)<<(MEMCTRL_ADDR_SFT))
#define MEMCTRL_SET_CRE_MSK   ((0x1U)<<(MEMCTRL_SET_CRE_SFT))
/* direct_cmd chip_select values */
#define MEMCTRL_NOR_CHIP_SEL_MSK    ((0x0U)<<(MEMCTRL_CHIP_SEL_SFT))
#define MEMCTRL_NAND_CHIP_SEL_MSK   ((0x4U)<<(MEMCTRL_CHIP_SEL_SFT))
/* direct_cmd cmd_type values */
#define MEMCTRL_CMD_TYPE_UPD_REGS_AXI_MSK   ((0x0U)<<(MEMCTRL_CMD_TYPE_SFT))
#define MEMCTRL_CMD_TYPE_MODE_REGS_MSK      ((0x1U)<<(MEMCTRL_CMD_TYPE_SFT))
#define MEMCTRL_CMD_TYPE_UPD_REGS_MSK       ((0x2U)<<(MEMCTRL_CMD_TYPE_SFT))
#define MEMCTRL_CMD_TYPE_MODE_UP_REGS_MSK   ((0x3U)<<(MEMCTRL_CMD_TYPE_SFT))
/* direct_cmd set_cre values */
#define MEMCTRL_NOR_SET_CRE_LOW_MSK     ((0x0U)<<(MEMCTRL_SET_CRE_SFT))
#define MEMCTRL_NOR_SET_CRE_HIGH_MSK    ((0x1U)<<(MEMCTRL_SET_CRE_SFT))

/* set_cycles register bit-shifts */
#define MEMCTRL_SET_T0_SFT   (0)
#define MEMCTRL_SET_T1_SFT   (4)
#define MEMCTRL_SET_T2_SFT   (8)
#define MEMCTRL_SET_T3_SFT   (11)
#define MEMCTRL_SET_T4_SFT   (14)
#define MEMCTRL_SET_T5_SFT   (17)
#define MEMCTRL_SET_T6_SFT   (20)
/* set_cycles register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_SET_T0_MSK   ((0xFU)<<(MEMCTRL_SET_T0_SFT))
#define MEMCTRL_SET_T1_MSK   ((0xFU)<<(MEMCTRL_SET_T1_SFT))
#define MEMCTRL_SET_T2_MSK   ((0x7U)<<(MEMCTRL_SET_T2_SFT))
#define MEMCTRL_SET_T3_MSK   ((0x7U)<<(MEMCTRL_SET_T3_SFT))
#define MEMCTRL_SET_T4_MSK   ((0x7U)<<(MEMCTRL_SET_T4_SFT))
#define MEMCTRL_SET_T5_MSK   ((0x7U)<<(MEMCTRL_SET_T5_SFT))
#define MEMCTRL_SET_NAND_T6_MSK   ((0xFU)<<(MEMCTRL_SET_T6_SFT)) /* NAND only */
#define MEMCTRL_SET_SRAM_T6_MSK   ((0x1U)<<(MEMCTRL_SET_T6_SFT)) /* SRAM/NOR
                                                                    only */

/* set_opmode register bit-shifts */
#define MEMCTRL_SET_MW_SFT       (0)
#define MEMCTRL_SET_RD_SYNC_SFT  (2)
#define MEMCTRL_SET_RD_BL_SFT    (3)
#define MEMCTRL_SET_WR_SYNC_SFT  (6)
#define MEMCTRL_SET_WR_BL_SFT    (7)
#define MEMCTRL_SET_BAA_SFT      (10)
#define MEMCTRL_SET_ADV_SFT      (11)
#define MEMCTRL_SET_BLS_SFT      (12)
#define MEMCTRL_SET_BURST_ALIGN_SFT (13)
/* set_opmode register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_SET_MW_MSK       ((0x3U)<<(MEMCTRL_SET_MW_SFT))
#define MEMCTRL_SET_MW_8_BITS    ((0x0U)<<(MEMCTRL_SET_MW_SFT))
#define MEMCTRL_SET_MW_16_BITS   ((0x1U)<<(MEMCTRL_SET_MW_SFT))

#define MEMCTRL_SET_RD_SYNC_MSK  ((0x1U)<<(MEMCTRL_SET_RD_SYNC_SFT))
/* ! rd_bl field must NOT be set greater than the read data FIFO depth */
#define MEMCTRL_SET_RD_BL_MSK    ((0x7U)<<(MEMCTRL_SET_RD_BL_SFT))
#define MEMCTRL_SET_RD_BL_1_BITS     ((0x0U)<<(MEMCTRL_SET_RD_BL_SFT))
#define MEMCTRL_SET_RD_BL_4_BITS     ((0x1U)<<(MEMCTRL_SET_RD_BL_SFT))
#define MEMCTRL_SET_RD_BL_8_BITS     ((0x2U)<<(MEMCTRL_SET_RD_BL_SFT))
#define MEMCTRL_SET_RD_BL_16_BITS    ((0x3U)<<(MEMCTRL_SET_RD_BL_SFT))
#define MEMCTRL_SET_RD_BL_32_BITS    ((0x4U)<<(MEMCTRL_SET_RD_BL_SFT))
#define MEMCTRL_SET_RD_BL_CNTS_BITS  ((0x5U)<<(MEMCTRL_SET_RD_BL_SFT))

#define MEMCTRL_SET_WR_SYNC_MSK  ((0x1U)<<(MEMCTRL_SET_WR_SYNC_SFT))

#define MEMCTRL_SET_WR_BL_MSK    ((0x7U)<<(MEMCTRL_SET_WR_BL_SFT))
#define MEMCTRL_SET_WR_BL_1_BITS      ((0x0U)<<(MEMCTRL_SET_WR_BL_SFT))
#define MEMCTRL_SET_WR_BL_4_BITS      ((0x1U)<<(MEMCTRL_SET_WR_BL_SFT))
#define MEMCTRL_SET_WR_BL_8_BITS      ((0x2U)<<(MEMCTRL_SET_WR_BL_SFT))
#define MEMCTRL_SET_WR_BL_16_BITS     ((0x3U)<<(MEMCTRL_SET_WR_BL_SFT))
#define MEMCTRL_SET_WR_BL_32_BITS     ((0x4U)<<(MEMCTRL_SET_WR_BL_SFT))
#define MEMCTRL_SET_WR_BL_CNTS_BITS   ((0x5U)<<(MEMCTRL_SET_WR_BL_SFT))

#define MEMCTRL_SET_BAA_MSK      ((0x1U)<<(MEMCTRL_SET_BAA_SFT))
#define MEMCTRL_SET_ADV_MSK      ((0x1U)<<(MEMCTRL_SET_ADV_SFT))
#define MEMCTRL_SET_BLS_MSK      ((0x1U)<<(MEMCTRL_SET_BLS_SFT))
#define MEMCTRL_SET_BRST_ALIGN_MSK   ((0x7U)<<(MEMCTRL_SET_BURST_ALIGN_SFT))
#define MEMCTRL_SET_BRST_CR_ANY_BITS  ((0x0U)<<(MEMCTRL_SET_BURST_ALIGN_SFT))
#define MEMCTRL_SET_BRST_CR_32_BITS   ((0x1U)<<(MEMCTRL_SET_BURST_ALIGN_SFT))
#define MEMCTRL_SET_BRST_CR_64_BITS   ((0x2U)<<(MEMCTRL_SET_BURST_ALIGN_SFT))
#define MEMCTRL_SET_BRST_CR_128_BITS  ((0x3U)<<(MEMCTRL_SET_BURST_ALIGN_SFT))
#define MEMCTRL_SET_BRST_CR_256_BITS  ((0x4U)<<(MEMCTRL_SET_BURST_ALIGN_SFT))

/* Mask used to extract NAND Base Address from a combined address information */
#define MEMCTRL_AXI_BASE_ADDR_MASK     (0xFF000000U)
/* Bit-shifts used, for the Cmd Phase sending to NAND device (AXI write) */
#define MEMCTRL_AXI_CHIP_ADDRESS_SFT     (24)
#define MEMCTRL_AXI_ADDRES_CYCLES_SFT   (21)
#define MEMCTRL_AXI_END_CMD_VALID_SFT   (20)
#define MEMCTRL_AXI_CMD_DATA_SELECT_SFT (19)
#define MEMCTRL_AXI_END_COMMAND_SFT     (11)
#define MEMCTRL_AXI_START_COMMAND_SFT   (3)

/* Bit-shifts used, for the Data Phase sending to NAND device (AXI write) */
#define MEMCTRL_AXI_CLEAR_CS_SFT     (21)

#define MEMCTRL_AXI_ECC_LAST_SFT     (10)

/* *** NOR OFFSET and REGISTERS ****/

/* !!! NOR I/F Chip Select address offset !!! */
#define MEMCTRL_NOR    (0x00000100U)
/* Read-Only NOR CYCLES REGISTER */
#define MEMCTRL_SRAM_CYCLES   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_NOR)+(0x000U))))
/* Read-Only NOR OPMODE REGISTER */
#define MEMCTRL_SRAM_OPMODE   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_NOR)+(0x004U))))

/* *** NAND OFFSET and REGISTERS ****/

/* !!! NAND I/F Chip Select address offset !!! */
#define MEMCTRL_NAND   (0x00000180U)
/* Read-Only NAND CYCLES REGISTER */
#define MEMCTRL_NAND_CYCLES   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_NAND)+(0x000U))))
/* Read-Only NAND OPMODE REGISTER */
#define MEMCTRL_NAND_OPMODE   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_NAND)+(0x004U))))

/* *** ECC OFFSET and REGISTERS ****/

/* !!! ECC Chip Select address offset !!! */
#define MEMCTRL_ECC   (0x00000400U)
/* Read-Only ecc_status REGISTER */
#define MEMCTRL_ECC_STATUS   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x000U))))
/* Read-Write ecc_memcfg REGISTER */
#define MEMCTRL_ECC_MEMCFG   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x004U))))
/* Read-Write ecc_memcommand1 REGISTER */
#define MEMCTRL_ECC_MEMCMD1  (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x008U))))
/* Read-Write ecc_memcommand2 REGISTER */
#define MEMCTRL_ECC_MEMCMD2  (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x00CU))))
/* Read-Only ecc_addr0 REGISTER */
#define MEMCTRL_ECC_ADDR0    (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x010U))))
/* Read-Only ecc_addr1 REGISTER */
#define MEMCTRL_ECC_ADDR1    (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x014U))))
/* Read-Only ecc_value0 REGISTER */
#define MEMCTRL_ECC_VALUE0   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x018U))))
/* Read-Only ecc_value1 REGISTER */
#define MEMCTRL_ECC_VALUE1   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x01CU))))
/* Read-Only ecc_value2 REGISTER */
#define MEMCTRL_ECC_VALUE2   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x020U))))
/* Read-Only ecc_value3 REGISTER */
#define MEMCTRL_ECC_VALUE3   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x024U))))
/* !BUG in the spec. page 3-5 Table 3-1! Read-Only ecc_value4 REGISTER */
#define MEMCTRL_ECC_VALUE4   (*((volatile uint32_t*) ((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x028U))))
/* ECC register address calculation */
#define MEMCTRL_ECC_VALUE_ADR(X)   (((MEMCTRL_BASE)+(MEMCTRL_ECC)+(0x018U)+((4U)*((uint32_t)(X)))))

/* ecc_status register bit-shifts */
#define MEMCTRL_ECC_READ_SFT           (25)
#define MEMCTRL_ECC_CAN_CORRECT_SFT    (20)
#define MEMCTRL_ECC_ECC_FAIL_SFT       (15)
#define MEMCTRL_ECC_VALUE_VALID_SFT    (10)
#define MEMCTRL_ECC_RD_NOT_WR_SFT      (9)
#define MEMCTRL_ECC_LAST_STATUS_SFT    (7)
#define MEMCTRL_ECC_STATUS_SFT         (6)
#define MEMCTRL_ECC_RAW_INT_ABORT_SFT   (5)
#define MEMCTRL_ECC_RAW_INT_EXTRA_SFT   (4)
#define MEMCTRL_ECC_RAW_INT_BLOCK3_SFT  (3)
#define MEMCTRL_ECC_RAW_INT_BLOCK2_SFT  (2)
#define MEMCTRL_ECC_RAW_INT_BLOCK1_SFT  (1)
#define MEMCTRL_ECC_RAW_INT_BLOCK0_SFT  (0)
/* ecc_status register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_ECC_READ_MSK          ((0x1FU)<<(MEMCTRL_ECC_READ_SFT))
#define MEMCTRL_ECC_CAN_CORRECT_MSK   ((0x1FU)<<(MEMCTRL_ECC_CAN_CORRECT_SFT))
#define MEMCTRL_ECC_ECC_FAIL_MSK      ((0x1FU)<<(MEMCTRL_ECC_ECC_FAIL_SFT))
#define MEMCTRL_ECC_ECC_FAIL_BLOCK0_BIT   ((0x1FU)<<(MEMCTRL_ECC_ECC_FAIL_SFT))
#define MEMCTRL_ECC_ECC_FAIL_BLOCK1_BIT   ((0x1FU)<<(MEMCTRL_ECC_ECC_FAIL_SFT+1U))
#define MEMCTRL_ECC_ECC_FAIL_BLOCK2_BIT   ((0x1FU)<<(MEMCTRL_ECC_ECC_FAIL_SFT+2U))
#define MEMCTRL_ECC_ECC_FAIL_BLOCK3_BIT   ((0x1FU)<<(MEMCTRL_ECC_ECC_FAIL_SFT+3U))
#define MEMCTRL_ECC_ECC_FAIL_BLOCK4_BIT   ((0x1FU)<<(MEMCTRL_ECC_ECC_FAIL_SFT+4U))

#define MEMCTRL_ECC_VALUE_VALID_MSK   ((0x1FU)<<(MEMCTRL_ECC_VALUE_VALID_SFT))
#define MEMCTRL_ECC_RD_NOT_WR_MSK     ((0x1U)<<(MEMCTRL_ECC_RD_NOT_WR_SFT))
#define MEMCTRL_ECC_LAST_STATUS_MSK   ((0x3U)<<(MEMCTRL_ECC_LAST_STATUS_SFT))
#define MEMCTRL_ECC_LAST_STATUS_SUCCESS_BITS   ((0x0U)<<(MEMCTRL_ECC_LAST_STATUS_SFT))
#define MEMCTRL_ECC_BUSY_MSK          ((0x1U)<<(MEMCTRL_ECC_STATUS_SFT))
#define MEMCTRL_ECC_RAW_INT_ABORT_MSK   ((0x1U)<<(MEMCTRL_ECC_RAW_INT_ABORT_SFT))
#define MEMCTRL_ECC_RAW_INT_EXTRA_MSK   ((0x1U)<<(MEMCTRL_ECC_RAW_INT_EXTRA_SFT))
#define MEMCTRL_ECC_RAW_INT_BLOCK3_MSK   ((0x1U)<<(MEMCTRL_ECC_RAW_INT_BLOCK3_SFT))
#define MEMCTRL_ECC_RAW_INT_BLOCK2_MSK   ((0x1U)<<(MEMCTRL_ECC_RAW_INT_BLOCK2_SFT))
#define MEMCTRL_ECC_RAW_INT_BLOCK1_MSK   ((0x1U)<<(MEMCTRL_ECC_RAW_INT_BLOCK1_SFT))
#define MEMCTRL_ECC_RAW_INT_BLOCK0_MSK   ((0x1U)<<(MEMCTRL_ECC_RAW_INT_BLOCK0_SFT))
/* this mask is for a convenient clearing of ALL ECC_RAW_INT_... interrupts */
#define MEMCTRL_ECC_RAW_ALL_INTS_MSK   (0x3FU)

/* ecc_memcfg register bit-shifts */
#define MEMCTRL_ECC_EXTRA_BLOCK_SIZE_SFT  (11)
#define MEMCTRL_ECC_EXTRA_BLOCK_SFT       (10)
#define MEMCTRL_ECC_INT_ABORT_SFT     (9)
#define MEMCTRL_ECC_INT_PASS_SFT      (8)
#define MEMCTRL_ECC_IGNORE_ADD_8_SFT  (7)
#define MEMCTRL_ECC_JUMP_SFT        (5)
#define MEMCTRL_ECC_READ_END_SFT    (4)
#define MEMCTRL_ECC_MODE_SFT        (2)
#define MEMCTRL_ECC_PAGE_SIZE_SFT   (0)
/* ecc_memcfg register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_ECC_EXTRA_BLOCK_SIZE_MSK   ((0x3U)<<(MEMCTRL_ECC_EXTRA_BLOCK_SIZE_SFT))
#define MEMCTRL_ECC_EXTRA_BLOCK_SIZE_4B_BITS   ((0x0U)<<(MEMCTRL_ECC_EXTRA_BLOCK_SIZE_SFT))
#define MEMCTRL_ECC_EXTRA_BLOCK_SIZE_8B_BITS   ((0x1U)<<(MEMCTRL_ECC_EXTRA_BLOCK_SIZE_SFT))
#define MEMCTRL_ECC_EXTRA_BLOCK_SIZE_16B_BITS  ((0x2U)<<(MEMCTRL_ECC_EXTRA_BLOCK_SIZE_SFT))
#define MEMCTRL_ECC_EXTRA_BLOCK_SIZE_32B_BITS  ((0x3U)<<(MEMCTRL_ECC_EXTRA_BLOCK_SIZE_SFT))

#define MEMCTRL_ECC_EXTRA_BLOCK_MSK       ((0x1U)<<(MEMCTRL_ECC_EXTRA_BLOCK_SFT))
#define MEMCTRL_ECC_INT_ABORT_MSK         ((0x1U)<<(MEMCTRL_ECC_INT_ABORT_SFT))
#define MEMCTRL_ECC_INT_PASS_MSK          ((0x1U)<<(MEMCTRL_ECC_INT_PASS_SFT))
#define MEMCTRL_ECC_A8_OUTPUT_MSK         ((0x0U)<<(MEMCTRL_ECC_IGNORE_ADD_8_SFT))
#define MEMCTRL_ECC_IGNORE_ADD_8_MSK      ((0x1U)<<(MEMCTRL_ECC_IGNORE_ADD_8_SFT))
#define MEMCTRL_ECC_JUMP_MSK              ((0x3U)<<(MEMCTRL_ECC_JUMP_SFT))
#define MEMCTRL_ECC_JUMP_NO_BITS          ((0x00U)<<(MEMCTRL_ECC_JUMP_SFT))
#define MEMCTRL_ECC_JUMP_COL_CHNG_BITS    ((0x1U)<<(MEMCTRL_ECC_JUMP_SFT))
#define MEMCTRL_ECC_JUMP_FULL_CMD_BITS    ((0x2U)<<(MEMCTRL_ECC_JUMP_SFT))
#define MEMCTRL_ECC_READ_END_MSK          ((0x1U)<<(MEMCTRL_ECC_READ_END_SFT))
#define MEMCTRL_ECC_MODE_MSK              ((0x3U)<<(MEMCTRL_ECC_MODE_SFT))
#define MEMCTRL_ECC_MODE_BYPASS_BITS      ((0x0U)<<(MEMCTRL_ECC_MODE_SFT))
#define MEMCTRL_ECC_MODE_CALC_BITS        ((0x1U)<<(MEMCTRL_ECC_MODE_SFT))
#define MEMCTRL_ECC_MODE_CALC_RD_WR_BITS  ((0x2U)<<(MEMCTRL_ECC_MODE_SFT))
#define MEMCTRL_ECC_PAGE_SIZE_MSK         ((0x3U)<<(MEMCTRL_ECC_PAGE_SIZE_SFT))
#define MEMCTRL_ECC_PAGE_SIZE_NOANY_BITS  ((0x0U)<<(MEMCTRL_ECC_PAGE_SIZE_SFT))
#define MEMCTRL_ECC_PAGE_SIZE_1X512_BITS  ((0x1U)<<(MEMCTRL_ECC_PAGE_SIZE_SFT))
#define MEMCTRL_ECC_PAGE_SIZE_2X512_BITS  ((0x2U)<<(MEMCTRL_ECC_PAGE_SIZE_SFT))
#define MEMCTRL_ECC_PAGE_SIZE_4X512_BITS  ((0x3U)<<(MEMCTRL_ECC_PAGE_SIZE_SFT))

/* ecc_memcommand1 register bit-shifts */
#define MEMCTRL_ECC_RD_CMD_END_VALID_SFT  (24)
#define MEMCTRL_ECC_RD_CMD_END_SFT        (16)
#define MEMCTRL_ECC_RD_CMD_SFT   (8)
#define MEMCTRL_ECC_WR_CMD_SFT   (0)
/* ecc_memcommand1 register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_ECC_RD_CMD_END_VALID_MSK  ((0x1U)<<(MEMCTRL_ECC_RD_CMD_END_VALID_SFT))
#define MEMCTRL_ECC_RD_CMD_END_MSK  ((0xFFU)<<(MEMCTRL_ECC_RD_CMD_END_SFT))
#define MEMCTRL_ECC_RD_CMD_MSK  ((0xFFU)<<(MEMCTRL_ECC_RD_CMD_SFT))
#define MEMCTRL_ECC_WR_CMD_MSK  ((0xFFU)<<(MEMCTRL_ECC_WR_CMD_SFT))

/* ecc_memcommand2 register bit-shifts */
/*#define MEMCTRL_ECC_RD_CL_CH_END_VALID_SFT  (24)*/
#define MEMCTRL_ECC_RD_CL_CH_END_SFT  (16)
#define MEMCTRL_ECC_RD_CL_CH_SFT  (8)
#define MEMCTRL_ECC_WR_COL_CHANGE_SFT  (0)
/* ecc_memcommand2 register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_ECC_RD_CL_CH_END_VALID_MSK  ((0x1U)<<(24))
#define MEMCTRL_ECC_RD_CL_CH_END_MSK        ((0xFFU)<<(MEMCTRL_ECC_RD_CL_CH_END_SFT))
#define MEMCTRL_ECC_RD_CL_CH_MSK    ((0xFFU)<<(MEMCTRL_ECC_RD_CL_CH_SFT))
#define MEMCTRL_ECC_WR_COL_CHANGE_MSK    ((0xFFU)<<(MEMCTRL_ECC_WR_COL_CHANGE_SFT))

/* ecc_addr0 register bit-mask for address bits [31 : 0] */
#define MEMCTRL_ECC_ADDR0_MSK  (0xFFFFFFFFU)
/* ecc_addr1 register bit-mask for address bits [55 : 32] */
#define MEMCTRL_ECC_ADDR1_MSK  (0x00FFFFFFU)

/* ecc_value x register bit-shifts */
#define MEMCTRL_ECC_VAL_INT_SFT     (31)
#define MEMCTRL_ECC_VAL_VALID_SFT   (30)
#define MEMCTRL_ECC_VAL_READ_SFT    (29)
#define MEMCTRL_ECC_VAL_FAIL_SFT    (28)
#define MEMCTRL_ECC_VAL_CORRECT_SFT (27)
#define MEMCTRL_ECC_VAL_VALUE_SFT   (0)
/* ecc_value x register bit-masks (shifted to the bits-positions) */
#define MEMCTRL_ECC_VAL_INT_MSK      ((0x1U)<<(MEMCTRL_ECC_VAL_INT_SFT))
#define MEMCTRL_ECC_VAL_VALID_MSK    ((0x1U)<<(MEMCTRL_ECC_VAL_VALID_SFT))
#define MEMCTRL_ECC_VAL_READ_MSK     ((0x1U)<<(MEMCTRL_ECC_VAL_READ_SFT))
#define MEMCTRL_ECC_VAL_FAIL_MSK     ((0x1U)<<(MEMCTRL_ECC_VAL_FAIL_SFT))
#define MEMCTRL_ECC_VAL_CORRECT_MSK  ((0x1U)<<(MEMCTRL_ECC_VAL_CORRECT_SFT))
#define MEMCTRL_ECC_VAL_VALUE_MSK    ((0x00FFFFFFU)<<(MEMCTRL_ECC_VAL_VALUE_SFT))

/* ************ SMC Memory Controller API Functions Definitions ************ */

/*****************************************************************************
* Function is empty so far.
*****************************************************************************/
MemCtrlResult_e eMemCtrl_Initialize (void);

/****************************************************************************/


#endif /* MEMCTRL_H */

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

