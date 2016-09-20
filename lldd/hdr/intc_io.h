
/*##########################################################################
/  AUTOMATICALLY GENERATED FROM A REG_XML-FILE
/  Module                       : INTC
/  Date of creation (y-m-d:time): 2013-06-26+02:00  :  17:56:36.688+02:00
/  Excel2XML Tool ver.          : XLS2XML Converter 2.6.2
/  Stylesheet  ver              : $Revision: 1.12 $
/  Excel Sheet ver.             : vv1.1
/  Excel Sheet date             : 2013-Jun-19
/  Excel Sheet author           : ZUL
/##########################################################################*/

/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : Reference Interrupt Controller Low Level Device Driver IO
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : Interrupt Controller (INTC)
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.12 $
*   DATE        : $Date: 2015/05/04 09:07:16 $
*   TAG         : $Name: LLDD_1_6 $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/


#ifndef INTCIO_H
#define INTCIO_H

/**********************************************
*                Include files                *
**********************************************/
/* Following include file(s) needed for proper operation: */
#include "captypes.h"   /* Core specific primitive type definitions */


/*********************************************
*         Disable Misra Warnings/Rules       *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs nowarning 230  /* Rule 3.5 [R] : derived  disable warnings for nonstandard type for a bit field */
  #pragma ghs nowarning 79   /* Rule 3.5 [R] : derived  disable warnings for nonstandard type for a bit field */

  #pragma ghs nowarning 1840   /* Rule 5.7   [A] : No reuse of identifiers  */
#endif

/**********************************************
*                 Constants                   *
**********************************************/
#define LLDD_INTC_IO_H_REVISION     "$Revision: 1.12 $"
#define LLDD_INTC_IO_H_TAG          "$Name: LLDD_1_6 $"


/****************************************************************************
*
*       REGISTER: IR
*       SIZE    : 32-bits
*       ADDRESS : 0xC0108000
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IR_REG__       0xC0108000U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   EXT0	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:1; 	 /* 3..3  bit(s) R */
  uint32_t   DRS0	:1; 	 /* 4..4  bit(s) R/W */
  uint32_t   EIM0	:2; 	 /* 5..6  bit(s) R/W */
  uint32_t   ACLR0	:1; 	 /* 7..7  bit(s) R/W */
  uint32_t   EXT1	:3; 	 /* 8..10  bit(s) R/W */
  uint32_t   	:1; 	 /* 11..11  bit(s) R */
  uint32_t   DRS1	:1; 	 /* 12..12  bit(s) R/W */
  uint32_t   EIM1	:2; 	 /* 13..14  bit(s) R/W */
  uint32_t   ACLR1	:1; 	 /* 15..15  bit(s) R/W */
  uint32_t   EXT2	:3; 	 /* 16..18  bit(s) R/W */
  uint32_t   	:1; 	 /* 19..19  bit(s) R */
  uint32_t   DRS2	:1; 	 /* 20..20  bit(s) R/W */
  uint32_t   EIM2	:2; 	 /* 21..22  bit(s) R/W */
  uint32_t   ACLR2	:1; 	 /* 23..23  bit(s) R/W */
  uint32_t   EXT3	:3; 	 /* 24..26  bit(s) R/W */
  uint32_t   	:1; 	 /* 27..27  bit(s) R */
  uint32_t   DRS3	:1; 	 /* 28..28  bit(s) R/W */
  uint32_t   EIM3	:2; 	 /* 29..30  bit(s) R/W */
  uint32_t   ACLR3	:1; 	 /* 31..31  bit(s) R/W */
} IR_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} IR_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} IR_halfword_view_st;

/* WORD View */
typedef uint32_t u32IR_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIR(ch)     ((volatile IR_bit_view_st *)\
(IR_REG__  + ((uint16_t)(ch) * 0x004U)))

/* Pointer to BYTE-struct  */
#define pst_u8IR(ch)     ((volatile IR_byte_view_st *)\
(IR_REG__  + ((uint16_t)(ch) * 0x004U)))

/* Pointer to HALFWORD-struct */
#define pst_u16IR(ch)     ((volatile IR_halfword_view_st *)\
(IR_REG__  + ((uint16_t)(ch) * 0x004U)))

/* Pointer to WORD  */
#define pu32IR(ch)     ((volatile u32IR_word_view *)\
(IR_REG__  + ((uint16_t)(ch) * 0x004U)))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIR_EXT0(ch) (pst_bitIR(ch) -> EXT0)
#define vSetIR_EXT0(ch,ParValue)  (pst_bitIR(ch) -> EXT0=(ParValue))
#define biGetIR_DRS0(ch) (pst_bitIR(ch) -> DRS0)
#define vSetIR_DRS0(ch,ParValue)  (pst_bitIR(ch) -> DRS0=(ParValue))
#define biGetIR_EIM0(ch) (pst_bitIR(ch) -> EIM0)
#define vSetIR_EIM0(ch,ParValue)  (pst_bitIR(ch) -> EIM0=(ParValue))
#define biGetIR_ACLR0(ch) (pst_bitIR(ch) -> ACLR0)
#define vSetIR_ACLR0(ch,ParValue)  (pst_bitIR(ch) -> ACLR0=(ParValue))
#define biGetIR_EXT1(ch) (pst_bitIR(ch) -> EXT1)
#define vSetIR_EXT1(ch,ParValue)  (pst_bitIR(ch) -> EXT1=(ParValue))
#define biGetIR_DRS1(ch) (pst_bitIR(ch) -> DRS1)
#define vSetIR_DRS1(ch,ParValue)  (pst_bitIR(ch) -> DRS1=(ParValue))
#define biGetIR_EIM1(ch) (pst_bitIR(ch) -> EIM1)
#define vSetIR_EIM1(ch,ParValue)  (pst_bitIR(ch) -> EIM1=(ParValue))
#define biGetIR_ACLR1(ch) (pst_bitIR(ch) -> ACLR1)
#define vSetIR_ACLR1(ch,ParValue)  (pst_bitIR(ch) -> ACLR1=(ParValue))
#define biGetIR_EXT2(ch) (pst_bitIR(ch) -> EXT2)
#define vSetIR_EXT2(ch,ParValue)  (pst_bitIR(ch) -> EXT2=(ParValue))
#define biGetIR_DRS2(ch) (pst_bitIR(ch) -> DRS2)
#define vSetIR_DRS2(ch,ParValue)  (pst_bitIR(ch) -> DRS2=(ParValue))
#define biGetIR_EIM2(ch) (pst_bitIR(ch) -> EIM2)
#define vSetIR_EIM2(ch,ParValue)  (pst_bitIR(ch) -> EIM2=(ParValue))
#define biGetIR_ACLR2(ch) (pst_bitIR(ch) -> ACLR2)
#define vSetIR_ACLR2(ch,ParValue)  (pst_bitIR(ch) -> ACLR2=(ParValue))
#define biGetIR_EXT3(ch) (pst_bitIR(ch) -> EXT3)
#define vSetIR_EXT3(ch,ParValue)  (pst_bitIR(ch) -> EXT3=(ParValue))
#define biGetIR_DRS3(ch) (pst_bitIR(ch) -> DRS3)
#define vSetIR_DRS3(ch,ParValue)  (pst_bitIR(ch) -> DRS3=(ParValue))
#define biGetIR_EIM3(ch) (pst_bitIR(ch) -> EIM3)
#define vSetIR_EIM3(ch,ParValue)  (pst_bitIR(ch) -> EIM3=(ParValue))
#define biGetIR_ACLR3(ch) (pst_bitIR(ch) -> ACLR3)
#define vSetIR_ACLR3(ch,ParValue)  (pst_bitIR(ch) -> ACLR3=(ParValue))

/* LL-struct byte access */
#define vSetIRLL(ch,ParValue) (pst_u8IR(ch) -> u8LL = (ParValue))
#define u8GetIRLL(ch) (pst_u8IR(ch) -> u8LL)
/* LH-struct byte access */
#define vSetIRLH(ch,ParValue) (pst_u8IR(ch) -> u8LH = (ParValue))
#define u8GetIRLH(ch) (pst_u8IR(ch) -> u8LH)
/* HL-struct byte access */
#define vSetIRHL(ch,ParValue) (pst_u8IR(ch) -> u8HL = (ParValue))
#define u8GetIRHL(ch) (pst_u8IR(ch) -> u8HL)
/* HH-struct byte access */
#define vSetIRHH(ch,ParValue) (pst_u8IR(ch) -> u8HH = (ParValue))
#define u8GetIRHH(ch) (pst_u8IR(ch) -> u8HH)


/* Half-word struct access */
#define vSetIRL(ch,ParValue) (pst_u16IR(ch) -> u16L = (ParValue))
#define u16GetIRL(ch) (pst_u16IR(ch) -> u16L)
#define vSetIRH(ch,ParValue) (pst_u16IR(ch) -> u16H = (ParValue))
#define u16GetIRH(ch) (pst_u16IR(ch) -> u16H)

/* Word access */
#define vSetIR(ch,ParValue)  (*pu32IR(ch) = (ParValue))
#define u32GetIR(ch)  (*pu32IR(ch) )


/****************************************************************************
*
*       REGISTER: IVR
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080C0
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IVR_REG__       0xC01080C0U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   OVA	:10; 	 /* 0..9  bit(s) R */
  uint32_t   BVA	:22; 	 /* 10..31  bit(s) R/W */
} IVR_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} IVR_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} IVR_halfword_view_st;

/* WORD View */
typedef uint32_t u32IVR_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIVR()     ((volatile IVR_bit_view_st *)\
(IVR_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8IVR()     ((volatile IVR_byte_view_st *)\
(IVR_REG__ ))

/* Pointer to HALFWORD-struct */
#define pst_u16IVR()     ((volatile IVR_halfword_view_st *)\
(IVR_REG__ ))

/* Pointer to WORD  */
#define pu32IVR()     ((volatile u32IVR_word_view *)\
(IVR_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIVR_OVA() (pst_bitIVR() -> OVA)
#define biGetIVR_BVA() (pst_bitIVR() -> BVA)
#define vSetIVR_BVA(ParValue)  (pst_bitIVR() -> BVA=(ParValue))

/* LL-struct byte access */
#define vSetIVRLL(ParValue) (pst_u8IVR() -> u8LL = (ParValue))
#define u8GetIVRLL() (pst_u8IVR() -> u8LL)
/* LH-struct byte access */
#define vSetIVRLH(ParValue) (pst_u8IVR() -> u8LH = (ParValue))
#define u8GetIVRLH() (pst_u8IVR() -> u8LH)
/* HL-struct byte access */
#define vSetIVRHL(ParValue) (pst_u8IVR() -> u8HL = (ParValue))
#define u8GetIVRHL() (pst_u8IVR() -> u8HL)
/* HH-struct byte access */
#define vSetIVRHH(ParValue) (pst_u8IVR() -> u8HH = (ParValue))
#define u8GetIVRHH() (pst_u8IVR() -> u8HH)


/* Half-word struct access */
#define vSetIVRL(ParValue) (pst_u16IVR() -> u16L = (ParValue))
#define u16GetIVRL() (pst_u16IVR() -> u16L)
#define vSetIVRH(ParValue) (pst_u16IVR() -> u16H = (ParValue))
#define u16GetIVRH() (pst_u16IVR() -> u16H)

/* Word access */
#define vSetIVR(ParValue)  (*pu32IVR() = (ParValue))
#define u32GetIVR()  (*pu32IVR() )


/****************************************************************************
*
*       REGISTER: ICLR
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080C4
*       ACCESS  : 8, 16, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define ICLR_REG__       0xC01080C4U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   IV	:10; 	 /* 0..9  bit(s) W */
  uint32_t   	:6; 	 /* 10..31  bit(s) R */
} ICLR_bit_view_st;


/* Note: ICLR register should be written as 32 bit value! : */
/* WORD View */
typedef uint32_t u32ICLR_word_view;


/************************     ACCESS POINTERS    ****************************/
/* Pointer to WORD  */
#define pu32ICLR()     ((volatile u32ICLR_word_view *)\
(ICLR_REG__ ))

/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Note: ICLR register should be written as 32 bit value! : */


/* Word access */
#define vSetICLR(ParValue) (*pu32ICLR()  = (ParValue))
#define u32GetICLR() (*pu32ICLR() )


/****************************************************************************
*
*       REGISTER: ILEV
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080C8
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define ILEV_REG__       0xC01080C8U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   CMASK	:3; 	 /* 0..2  bit(s) R/W */
  uint32_t   	:1; 	 /* 3..3  bit(s) R */
  uint32_t   PMASK0	:3; 	 /* 4..6  bit(s) R */
  uint32_t   	:1; 	 /* 7..7  bit(s) R */
  uint32_t   PMASK1	:3; 	 /* 8..10  bit(s) R */
  uint32_t   	:1; 	 /* 11..11  bit(s) R */
  uint32_t   PMASK2	:3; 	 /* 12..14  bit(s) R */
  uint32_t   	:1; 	 /* 15..15  bit(s) R */
  uint32_t   PMASK3	:3; 	 /* 16..18  bit(s) R */
  uint32_t   	:1; 	 /* 19..19  bit(s) R */
  uint32_t   PMASK4	:3; 	 /* 20..22  bit(s) R */
  uint32_t   	:1; 	 /* 23..23  bit(s) R */
  uint32_t   PMASK5	:3; 	 /* 24..26  bit(s) R */
  uint32_t   	:4; 	 /* 27..30  bit(s) R */
  uint32_t   MLEV	:1; 	 /* 31..31  bit(s) W */
} ILEV_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} ILEV_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} ILEV_halfword_view_st;

/* WORD View */
typedef uint32_t u32ILEV_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitILEV()     ((volatile ILEV_bit_view_st *)\
(ILEV_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8ILEV()     ((volatile ILEV_byte_view_st *)\
(ILEV_REG__ ))

/* Pointer to HALFWORD-struct */
#define pst_u16ILEV()     ((volatile ILEV_halfword_view_st *)\
(ILEV_REG__ ))

/* Pointer to WORD  */
#define pu32ILEV()     ((volatile u32ILEV_word_view *)\
(ILEV_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetILEV_CMASK() (pst_bitILEV() -> CMASK)
#define vSetILEV_CMASK(ParValue)  (pst_bitILEV() -> CMASK=(ParValue))
#define biGetILEV_PMASK0() (pst_bitILEV() -> PMASK0)
#define biGetILEV_PMASK1() (pst_bitILEV() -> PMASK1)
#define biGetILEV_PMASK2() (pst_bitILEV() -> PMASK2)
#define biGetILEV_PMASK3() (pst_bitILEV() -> PMASK3)
#define biGetILEV_PMASK4() (pst_bitILEV() -> PMASK4)
#define biGetILEV_PMASK5() (pst_bitILEV() -> PMASK5)
#define vSetILEV_MLEV(ParValue) (pst_bitILEV() -> MLEV=(ParValue))

/* LL-struct byte access */
#define vSetILEVLL(ParValue) (pst_u8ILEV() -> u8LL = (ParValue))
#define u8GetILEVLL() (pst_u8ILEV() -> u8LL)
/* LH-struct byte access */
#define vSetILEVLH(ParValue) (pst_u8ILEV() -> u8LH = (ParValue))
#define u8GetILEVLH() (pst_u8ILEV() -> u8LH)
/* HL-struct byte access */
#define vSetILEVHL(ParValue) (pst_u8ILEV() -> u8HL = (ParValue))
#define u8GetILEVHL() (pst_u8ILEV() -> u8HL)
/* HH-struct byte access */
#define vSetILEVHH(ParValue) (pst_u8ILEV() -> u8HH = (ParValue))
#define u8GetILEVHH() (pst_u8ILEV() -> u8HH)


/* Half-word struct access */
#define vSetILEVL(ParValue) (pst_u16ILEV() -> u16L = (ParValue))
#define u16GetILEVL() (pst_u16ILEV() -> u16L)
#define vSetILEVH(ParValue) (pst_u16ILEV() -> u16H = (ParValue))
#define u16GetILEVH() (pst_u16ILEV() -> u16H)

/* Word access */
#define vSetILEV(ParValue)  (*pu32ILEV() = (ParValue))
#define u32GetILEV()  (*pu32ILEV() )


/****************************************************************************
*
*       REGISTER: IBLK
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080CC
*       ACCESS  : 8, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IBLK_REG__       0xC01080CCU

/************************       STRUCTURES        ***************************/

/* BIT View */
typedef struct{
  uint8_t   IBLK	:1; 	 /* 0..0  bit(s) W */
  uint8_t   	:7; 	 /* 1..31  bit(s) R */
} IBLK_bit_view_st;


/* BYTE View */
typedef uint8_t u8IBLK_byte_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIBLK()     ((volatile IBLK_bit_view_st *)\
(IBLK_REG__ ))

/* Pointer to BYTE  */
#define pu8IBLK()     ((volatile u8IBLK_byte_view *)\
(IBLK_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define vSetIBLK_IBLK(ParValue) (pst_bitIBLK() -> IBLK=(ParValue))

/* byte access */
#define vSetIBLK(ParValue) (*pu8IBLK() = (ParValue))
#define u8GetIBLK() (*pu8IBLK() )

/****************************************************************************
*
*       REGISTER: IRST
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080D0
*       ACCESS  : 8, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IRST_REG__       0xC01080D0U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint8_t   RDR0	:1; 	 /* 0..0  bit(s) R/W1C */
  uint8_t   RDR1	:1; 	 /* 1..1  bit(s) R/W1C */
  uint8_t   RDR2	:1; 	 /* 2..2  bit(s) R/W1C */
  uint8_t   RDR3	:1; 	 /* 3..3  bit(s) R/W1C */
  uint8_t   RDR4	:1; 	 /* 4..4  bit(s) R/W1C */
  uint8_t   RDR5	:1; 	 /* 5..5  bit(s) R/W1C */
  uint8_t   RDR6	:1; 	 /* 6..6  bit(s) R/W1C */
  uint8_t   RDR7	:1; 	 /* 7..7  bit(s) R/W1C */
} IRST_bit_view_st;


/* BYTE View */
typedef uint8_t u8IRST_byte_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIRST()     ((volatile IRST_bit_view_st *)\
(IRST_REG__ ))

/* Pointer to BYTE  */
#define pu8IRST()     ((volatile u8IRST_byte_view *)\
(IRST_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIRST_RDR0() (pst_bitIRST() -> RDR0)
#define vClrIRST_RDR0() (pst_bitIRST() -> RDR0 = (1))
#define biGetIRST_RDR1() (pst_bitIRST() -> RDR1)
#define vClrIRST_RDR1() (pst_bitIRST() -> RDR1 = (1))
#define biGetIRST_RDR2() (pst_bitIRST() -> RDR2)
#define vClrIRST_RDR2() (pst_bitIRST() -> RDR2 = (1))
#define biGetIRST_RDR3() (pst_bitIRST() -> RDR3)
#define vClrIRST_RDR3() (pst_bitIRST() -> RDR3 = (1))
#define biGetIRST_RDR4() (pst_bitIRST() -> RDR4)
#define vClrIRST_RDR4() (pst_bitIRST() -> RDR4 = (1))
#define biGetIRST_RDR5() (pst_bitIRST() -> RDR5)
#define vClrIRST_RDR5() (pst_bitIRST() -> RDR5 = (1))
#define biGetIRST_RDR6() (pst_bitIRST() -> RDR6)
#define vClrIRST_RDR6() (pst_bitIRST() -> RDR6 = (1))
#define biGetIRST_RDR7() (pst_bitIRST() -> RDR7)
#define vClrIRST_RDR7() (pst_bitIRST() -> RDR7 = (1))

/* byte access */
#define vSetIRST(ParValue) (*pu8IRST() = (ParValue))
#define u8GetIRST() (*pu8IRST() )


/****************************************************************************
*
*       REGISTER: IRREST0
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080D4
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IRREST0_REG__       0xC01080D4U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   STCH0	:1; 	 /* 0..0  bit(s) R */
  uint32_t   STCH1	:1; 	 /* 1..1  bit(s) R */
  uint32_t   STCH2	:1; 	 /* 2..2  bit(s) R */
  uint32_t   STCH3	:1; 	 /* 3..3  bit(s) R */
  uint32_t   STCH4	:1; 	 /* 4..4  bit(s) R */
  uint32_t   STCH5	:1; 	 /* 5..5  bit(s) R */
  uint32_t   STCH6	:1; 	 /* 6..6  bit(s) R */
  uint32_t   STCH7	:1; 	 /* 7..7  bit(s) R */
  uint32_t   STCH8	:1; 	 /* 8..8  bit(s) R */
  uint32_t   STCH9	:1; 	 /* 9..9  bit(s) R */
  uint32_t   STCH10	:1; 	 /* 10..10  bit(s) R */
  uint32_t   STCH11	:1; 	 /* 11..11  bit(s) R */
  uint32_t   STCH12	:1; 	 /* 12..12  bit(s) R */
  uint32_t   STCH13	:1; 	 /* 13..13  bit(s) R */
  uint32_t   STCH14	:1; 	 /* 14..14  bit(s) R */
  uint32_t   STCH15	:1; 	 /* 15..15  bit(s) R */
  uint32_t   STCH16	:1; 	 /* 16..16  bit(s) R */
  uint32_t   STCH17	:1; 	 /* 17..17  bit(s) R */
  uint32_t   STCH18	:1; 	 /* 18..18  bit(s) R */
  uint32_t   STCH19	:1; 	 /* 19..19  bit(s) R */
  uint32_t   STCH20	:1; 	 /* 20..20  bit(s) R */
  uint32_t   STCH21	:1; 	 /* 21..21  bit(s) R */
  uint32_t   STCH22	:1; 	 /* 22..22  bit(s) R */
  uint32_t   STCH23	:1; 	 /* 23..23  bit(s) R */
  uint32_t   STCH24	:1; 	 /* 24..24  bit(s) R */
  uint32_t   STCH25	:1; 	 /* 25..25  bit(s) R */
  uint32_t   STCH26	:1; 	 /* 26..26  bit(s) R */
  uint32_t   STCH27	:1; 	 /* 27..27  bit(s) R */
  uint32_t   STCH28	:1; 	 /* 28..28  bit(s) R */
  uint32_t   STCH29	:1; 	 /* 29..29  bit(s) R */
  uint32_t   STCH30	:1; 	 /* 30..30  bit(s) R */
  uint32_t   STCH31	:1; 	 /* 31..31  bit(s) R */
} IRREST0_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} IRREST0_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} IRREST0_halfword_view_st;

/* WORD View */
typedef uint32_t u32IRREST0_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIRREST0()     ((volatile IRREST0_bit_view_st *)\
(IRREST0_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8IRREST0()     ((volatile IRREST0_byte_view_st *)\
(IRREST0_REG__ ))

/* Pointer to HALFWORD-struct */
#define pst_u16IRREST0()     ((volatile IRREST0_halfword_view_st *)\
(IRREST0_REG__ ))

/* Pointer to WORD  */
#define pu32IRREST0()     ((volatile u32IRREST0_word_view *)\
(IRREST0_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIRREST0_STCH0() (pst_bitIRREST0() -> STCH0)
#define biGetIRREST0_STCH1() (pst_bitIRREST0() -> STCH1)
#define biGetIRREST0_STCH2() (pst_bitIRREST0() -> STCH2)
#define biGetIRREST0_STCH3() (pst_bitIRREST0() -> STCH3)
#define biGetIRREST0_STCH4() (pst_bitIRREST0() -> STCH4)
#define biGetIRREST0_STCH5() (pst_bitIRREST0() -> STCH5)
#define biGetIRREST0_STCH6() (pst_bitIRREST0() -> STCH6)
#define biGetIRREST0_STCH7() (pst_bitIRREST0() -> STCH7)
#define biGetIRREST0_STCH8() (pst_bitIRREST0() -> STCH8)
#define biGetIRREST0_STCH9() (pst_bitIRREST0() -> STCH9)
#define biGetIRREST0_STCH10() (pst_bitIRREST0() -> STCH10)
#define biGetIRREST0_STCH11() (pst_bitIRREST0() -> STCH11)
#define biGetIRREST0_STCH12() (pst_bitIRREST0() -> STCH12)
#define biGetIRREST0_STCH13() (pst_bitIRREST0() -> STCH13)
#define biGetIRREST0_STCH14() (pst_bitIRREST0() -> STCH14)
#define biGetIRREST0_STCH15() (pst_bitIRREST0() -> STCH15)
#define biGetIRREST0_STCH16() (pst_bitIRREST0() -> STCH16)
#define biGetIRREST0_STCH17() (pst_bitIRREST0() -> STCH17)
#define biGetIRREST0_STCH18() (pst_bitIRREST0() -> STCH18)
#define biGetIRREST0_STCH19() (pst_bitIRREST0() -> STCH19)
#define biGetIRREST0_STCH20() (pst_bitIRREST0() -> STCH20)
#define biGetIRREST0_STCH21() (pst_bitIRREST0() -> STCH21)
#define biGetIRREST0_STCH22() (pst_bitIRREST0() -> STCH22)
#define biGetIRREST0_STCH23() (pst_bitIRREST0() -> STCH23)
#define biGetIRREST0_STCH24() (pst_bitIRREST0() -> STCH24)
#define biGetIRREST0_STCH25() (pst_bitIRREST0() -> STCH25)
#define biGetIRREST0_STCH26() (pst_bitIRREST0() -> STCH26)
#define biGetIRREST0_STCH27() (pst_bitIRREST0() -> STCH27)
#define biGetIRREST0_STCH28() (pst_bitIRREST0() -> STCH28)
#define biGetIRREST0_STCH29() (pst_bitIRREST0() -> STCH29)
#define biGetIRREST0_STCH30() (pst_bitIRREST0() -> STCH30)
#define biGetIRREST0_STCH31() (pst_bitIRREST0() -> STCH31)

/* LL-struct byte access */

#define u8GetIRREST0LL() (pst_u8IRREST0() -> u8LL)
/* LH-struct byte access */

#define u8GetIRREST0LH() (pst_u8IRREST0() -> u8LH)
/* HL-struct byte access */

#define u8GetIRREST0HL() (pst_u8IRREST0() -> u8HL)
/* HH-struct byte access */

#define u8GetIRREST0HH() (pst_u8IRREST0() -> u8HH)


/* Half-word struct access */

#define u16GetIRREST0L() (pst_u16IRREST0() -> u16L)

#define u16GetIRREST0H() (pst_u16IRREST0() -> u16H)

/* Word access */

#define u32GetIRREST0()  (*pu32IRREST0() )


/****************************************************************************
*
*       REGISTER: IRREST1
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080D8
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IRREST1_REG__       0xC01080D8U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   STCH32	:1; 	 /* 0..0  bit(s) R */
  uint32_t   STCH33	:1; 	 /* 1..1  bit(s) R */
  uint32_t   STCH34	:1; 	 /* 2..2  bit(s) R */
  uint32_t   STCH35	:1; 	 /* 3..3  bit(s) R */
  uint32_t   STCH36	:1; 	 /* 4..4  bit(s) R */
  uint32_t   STCH37	:1; 	 /* 5..5  bit(s) R */
  uint32_t   STCH38	:1; 	 /* 6..6  bit(s) R */
  uint32_t   STCH39	:1; 	 /* 7..7  bit(s) R */
  uint32_t   STCH40	:1; 	 /* 8..8  bit(s) R */
  uint32_t   STCH41	:1; 	 /* 9..9  bit(s) R */
  uint32_t   STCH42	:1; 	 /* 10..10  bit(s) R */
  uint32_t   STCH43	:1; 	 /* 11..11  bit(s) R */
  uint32_t   STCH44	:1; 	 /* 12..12  bit(s) R */
  uint32_t   STCH45	:1; 	 /* 13..13  bit(s) R */
  uint32_t   STCH46	:1; 	 /* 14..14  bit(s) R */
  uint32_t   STCH47	:1; 	 /* 15..15  bit(s) R */
  uint32_t   STCH48	:1; 	 /* 16..16  bit(s) R */
  uint32_t   STCH49	:1; 	 /* 17..17  bit(s) R */
  uint32_t   STCH50	:1; 	 /* 18..18  bit(s) R */
  uint32_t   STCH51	:1; 	 /* 19..19  bit(s) R */
  uint32_t   STCH52	:1; 	 /* 20..20  bit(s) R */
  uint32_t   STCH53	:1; 	 /* 21..21  bit(s) R */
  uint32_t   STCH54	:1; 	 /* 22..22  bit(s) R */
  uint32_t   STCH55	:1; 	 /* 23..23  bit(s) R */
  uint32_t   STCH56	:1; 	 /* 24..24  bit(s) R */
  uint32_t   STCH57	:1; 	 /* 25..25  bit(s) R */
  uint32_t   STCH58	:1; 	 /* 26..26  bit(s) R */
  uint32_t   STCH59	:1; 	 /* 27..27  bit(s) R */
  uint32_t   STCH60	:1; 	 /* 28..28  bit(s) R */
  uint32_t   STCH61	:1; 	 /* 29..29  bit(s) R */
  uint32_t   STCH62	:1; 	 /* 30..30  bit(s) R */
  uint32_t   STCH63	:1; 	 /* 31..31  bit(s) R */
} IRREST1_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} IRREST1_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} IRREST1_halfword_view_st;

/* WORD View */
typedef uint32_t u32IRREST1_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIRREST1()     ((volatile IRREST1_bit_view_st *)\
(IRREST1_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8IRREST1()     ((volatile IRREST1_byte_view_st *)\
(IRREST1_REG__ ))

/* Pointer to HALFWORD-struct */
#define pst_u16IRREST1()     ((volatile IRREST1_halfword_view_st *)\
(IRREST1_REG__ ))

/* Pointer to WORD  */
#define pu32IRREST1()     ((volatile u32IRREST1_word_view *)\
(IRREST1_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIRREST1_STCH32() (pst_bitIRREST1() -> STCH32)
#define biGetIRREST1_STCH33() (pst_bitIRREST1() -> STCH33)
#define biGetIRREST1_STCH34() (pst_bitIRREST1() -> STCH34)
#define biGetIRREST1_STCH35() (pst_bitIRREST1() -> STCH35)
#define biGetIRREST1_STCH36() (pst_bitIRREST1() -> STCH36)
#define biGetIRREST1_STCH37() (pst_bitIRREST1() -> STCH37)
#define biGetIRREST1_STCH38() (pst_bitIRREST1() -> STCH38)
#define biGetIRREST1_STCH39() (pst_bitIRREST1() -> STCH39)
#define biGetIRREST1_STCH40() (pst_bitIRREST1() -> STCH40)
#define biGetIRREST1_STCH41() (pst_bitIRREST1() -> STCH41)
#define biGetIRREST1_STCH42() (pst_bitIRREST1() -> STCH42)
#define biGetIRREST1_STCH43() (pst_bitIRREST1() -> STCH43)
#define biGetIRREST1_STCH44() (pst_bitIRREST1() -> STCH44)
#define biGetIRREST1_STCH45() (pst_bitIRREST1() -> STCH45)
#define biGetIRREST1_STCH46() (pst_bitIRREST1() -> STCH46)
#define biGetIRREST1_STCH47() (pst_bitIRREST1() -> STCH47)
#define biGetIRREST1_STCH48() (pst_bitIRREST1() -> STCH48)
#define biGetIRREST1_STCH49() (pst_bitIRREST1() -> STCH49)
#define biGetIRREST1_STCH50() (pst_bitIRREST1() -> STCH50)
#define biGetIRREST1_STCH51() (pst_bitIRREST1() -> STCH51)
#define biGetIRREST1_STCH52() (pst_bitIRREST1() -> STCH52)
#define biGetIRREST1_STCH53() (pst_bitIRREST1() -> STCH53)
#define biGetIRREST1_STCH54() (pst_bitIRREST1() -> STCH54)
#define biGetIRREST1_STCH55() (pst_bitIRREST1() -> STCH55)
#define biGetIRREST1_STCH56() (pst_bitIRREST1() -> STCH56)
#define biGetIRREST1_STCH57() (pst_bitIRREST1() -> STCH57)
#define biGetIRREST1_STCH58() (pst_bitIRREST1() -> STCH58)
#define biGetIRREST1_STCH59() (pst_bitIRREST1() -> STCH59)
#define biGetIRREST1_STCH60() (pst_bitIRREST1() -> STCH60)
#define biGetIRREST1_STCH61() (pst_bitIRREST1() -> STCH61)
#define biGetIRREST1_STCH62() (pst_bitIRREST1() -> STCH62)
#define biGetIRREST1_STCH63() (pst_bitIRREST1() -> STCH63)

/* LL-struct byte access */

#define u8GetIRREST1LL() (pst_u8IRREST1() -> u8LL)
/* LH-struct byte access */

#define u8GetIRREST1LH() (pst_u8IRREST1() -> u8LH)
/* HL-struct byte access */

#define u8GetIRREST1HL() (pst_u8IRREST1() -> u8HL)
/* HH-struct byte access */

#define u8GetIRREST1HH() (pst_u8IRREST1() -> u8HH)


/* Half-word struct access */

#define u16GetIRREST1L() (pst_u16IRREST1() -> u16L)

#define u16GetIRREST1H() (pst_u16IRREST1() -> u16H)

/* Word access */

#define u32GetIRREST1()  (*pu32IRREST1() )


/****************************************************************************
*
*       REGISTER: IRREST2
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080DC
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IRREST2_REG__       0xC01080DCU

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   STCH64	:1; 	 /* 0..0  bit(s) R */
  uint32_t   STCH65	:1; 	 /* 1..1  bit(s) R */
  uint32_t   STCH66	:1; 	 /* 2..2  bit(s) R */
  uint32_t   STCH67	:1; 	 /* 3..3  bit(s) R */
  uint32_t   STCH68	:1; 	 /* 4..4  bit(s) R */
  uint32_t   STCH69	:1; 	 /* 5..5  bit(s) R */
  uint32_t   STCH70	:1; 	 /* 6..6  bit(s) R */
  uint32_t   STCH71	:1; 	 /* 7..7  bit(s) R */
  uint32_t   STCH72	:1; 	 /* 8..8  bit(s) R */
  uint32_t   STCH73	:1; 	 /* 9..9  bit(s) R */
  uint32_t   STCH74	:1; 	 /* 10..10  bit(s) R */
  uint32_t   STCH75	:1; 	 /* 11..11  bit(s) R */
  uint32_t   STCH76	:1; 	 /* 12..12  bit(s) R */
  uint32_t   STCH77	:1; 	 /* 13..13  bit(s) R */
  uint32_t   STCH78	:1; 	 /* 14..14  bit(s) R */
  uint32_t   STCH79	:1; 	 /* 15..15  bit(s) R */
  uint32_t   STCH80	:1; 	 /* 16..16  bit(s) R */
  uint32_t   STCH81	:1; 	 /* 17..17  bit(s) R */
  uint32_t   STCH82	:1; 	 /* 18..18  bit(s) R */
  uint32_t   STCH83	:1; 	 /* 19..19  bit(s) R */
  uint32_t   STCH84	:1; 	 /* 20..20  bit(s) R */
  uint32_t   STCH85	:1; 	 /* 21..21  bit(s) R */
  uint32_t   STCH86	:1; 	 /* 22..22  bit(s) R */
  uint32_t   STCH87	:1; 	 /* 23..23  bit(s) R */
  uint32_t   STCH88	:1; 	 /* 24..24  bit(s) R */
  uint32_t   STCH89	:1; 	 /* 25..25  bit(s) R */
  uint32_t   STCH90	:1; 	 /* 26..26  bit(s) R */
  uint32_t   STCH91	:1; 	 /* 27..27  bit(s) R */
  uint32_t   STCH92	:1; 	 /* 28..28  bit(s) R */
  uint32_t   STCH93	:1; 	 /* 29..29  bit(s) R */
  uint32_t   STCH94	:1; 	 /* 30..30  bit(s) R */
  uint32_t   STCH95	:1; 	 /* 31..31  bit(s) R */
} IRREST2_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} IRREST2_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} IRREST2_halfword_view_st;

/* WORD View */
typedef uint32_t u32IRREST2_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIRREST2()     ((volatile IRREST2_bit_view_st *)\
(IRREST2_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8IRREST2()     ((volatile IRREST2_byte_view_st *)\
(IRREST2_REG__ ))

/* Pointer to HALFWORD-struct */
#define pst_u16IRREST2()     ((volatile IRREST2_halfword_view_st *)\
(IRREST2_REG__ ))

/* Pointer to WORD  */
#define pu32IRREST2()     ((volatile u32IRREST2_word_view *)\
(IRREST2_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIRREST2_STCH64() (pst_bitIRREST2() -> STCH64)
#define biGetIRREST2_STCH65() (pst_bitIRREST2() -> STCH65)
#define biGetIRREST2_STCH66() (pst_bitIRREST2() -> STCH66)
#define biGetIRREST2_STCH67() (pst_bitIRREST2() -> STCH67)
#define biGetIRREST2_STCH68() (pst_bitIRREST2() -> STCH68)
#define biGetIRREST2_STCH69() (pst_bitIRREST2() -> STCH69)
#define biGetIRREST2_STCH70() (pst_bitIRREST2() -> STCH70)
#define biGetIRREST2_STCH71() (pst_bitIRREST2() -> STCH71)
#define biGetIRREST2_STCH72() (pst_bitIRREST2() -> STCH72)
#define biGetIRREST2_STCH73() (pst_bitIRREST2() -> STCH73)
#define biGetIRREST2_STCH74() (pst_bitIRREST2() -> STCH74)
#define biGetIRREST2_STCH75() (pst_bitIRREST2() -> STCH75)
#define biGetIRREST2_STCH76() (pst_bitIRREST2() -> STCH76)
#define biGetIRREST2_STCH77() (pst_bitIRREST2() -> STCH77)
#define biGetIRREST2_STCH78() (pst_bitIRREST2() -> STCH78)
#define biGetIRREST2_STCH79() (pst_bitIRREST2() -> STCH79)
#define biGetIRREST2_STCH80() (pst_bitIRREST2() -> STCH80)
#define biGetIRREST2_STCH81() (pst_bitIRREST2() -> STCH81)
#define biGetIRREST2_STCH82() (pst_bitIRREST2() -> STCH82)
#define biGetIRREST2_STCH83() (pst_bitIRREST2() -> STCH83)
#define biGetIRREST2_STCH84() (pst_bitIRREST2() -> STCH84)
#define biGetIRREST2_STCH85() (pst_bitIRREST2() -> STCH85)
#define biGetIRREST2_STCH86() (pst_bitIRREST2() -> STCH86)
#define biGetIRREST2_STCH87() (pst_bitIRREST2() -> STCH87)
#define biGetIRREST2_STCH88() (pst_bitIRREST2() -> STCH88)
#define biGetIRREST2_STCH89() (pst_bitIRREST2() -> STCH89)
#define biGetIRREST2_STCH90() (pst_bitIRREST2() -> STCH90)
#define biGetIRREST2_STCH91() (pst_bitIRREST2() -> STCH91)
#define biGetIRREST2_STCH92() (pst_bitIRREST2() -> STCH92)
#define biGetIRREST2_STCH93() (pst_bitIRREST2() -> STCH93)
#define biGetIRREST2_STCH94() (pst_bitIRREST2() -> STCH94)
#define biGetIRREST2_STCH95() (pst_bitIRREST2() -> STCH95)

/* LL-struct byte access */

#define u8GetIRREST2LL() (pst_u8IRREST2() -> u8LL)
/* LH-struct byte access */

#define u8GetIRREST2LH() (pst_u8IRREST2() -> u8LH)
/* HL-struct byte access */

#define u8GetIRREST2HL() (pst_u8IRREST2() -> u8HL)
/* HH-struct byte access */

#define u8GetIRREST2HH() (pst_u8IRREST2() -> u8HH)


/* Half-word struct access */

#define u16GetIRREST2L() (pst_u16IRREST2() -> u16L)

#define u16GetIRREST2H() (pst_u16IRREST2() -> u16H)

/* Word access */

#define u32GetIRREST2()  (*pu32IRREST2() )


/****************************************************************************
*
*       REGISTER: IRREST3
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080E0
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IRREST3_REG__       0xC01080E0U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   STCH96	:1; 	 /* 0..0  bit(s) R */
  uint32_t   STCH97	:1; 	 /* 1..1  bit(s) R */
  uint32_t   STCH98	:1; 	 /* 2..2  bit(s) R */
  uint32_t   STCH99	:1; 	 /* 3..3  bit(s) R */
  uint32_t   STCH100	:1; 	 /* 4..4  bit(s) R */
  uint32_t   STCH101	:1; 	 /* 5..5  bit(s) R */
  uint32_t   STCH102	:1; 	 /* 6..6  bit(s) R */
  uint32_t   STCH103	:1; 	 /* 7..7  bit(s) R */
  uint32_t   STCH104	:1; 	 /* 8..8  bit(s) R */
  uint32_t   STCH105	:1; 	 /* 9..9  bit(s) R */
  uint32_t   STCH106	:1; 	 /* 10..10  bit(s) R */
  uint32_t   STCH107	:1; 	 /* 11..11  bit(s) R */
  uint32_t   STCH108	:1; 	 /* 12..12  bit(s) R */
  uint32_t   STCH109	:1; 	 /* 13..13  bit(s) R */
  uint32_t   STCH110	:1; 	 /* 14..14  bit(s) R */
  uint32_t   STCH111	:1; 	 /* 15..15  bit(s) R */
  uint32_t   STCH112	:1; 	 /* 16..16  bit(s) R */
  uint32_t   STCH113	:1; 	 /* 17..17  bit(s) R */
  uint32_t   STCH114	:1; 	 /* 18..18  bit(s) R */
  uint32_t   STCH115	:1; 	 /* 19..19  bit(s) R */
  uint32_t   STCH116	:1; 	 /* 20..20  bit(s) R */
  uint32_t   STCH117	:1; 	 /* 21..21  bit(s) R */
  uint32_t   STCH118	:1; 	 /* 22..22  bit(s) R */
  uint32_t   STCH119	:1; 	 /* 23..23  bit(s) R */
  uint32_t   STCH120	:1; 	 /* 24..24  bit(s) R */
  uint32_t   STCH121	:1; 	 /* 25..25  bit(s) R */
  uint32_t   STCH122	:1; 	 /* 26..26  bit(s) R */
  uint32_t   STCH123	:1; 	 /* 27..27  bit(s) R */
  uint32_t   STCH124	:1; 	 /* 28..28  bit(s) R */
  uint32_t   STCH125	:1; 	 /* 29..29  bit(s) R */
  uint32_t   STCH126	:1; 	 /* 30..30  bit(s) R */
  uint32_t   STCH127	:1; 	 /* 31..31  bit(s) R */
} IRREST3_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} IRREST3_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} IRREST3_halfword_view_st;

/* WORD View */
typedef uint32_t u32IRREST3_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIRREST3()     ((volatile IRREST3_bit_view_st *)\
(IRREST3_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8IRREST3()     ((volatile IRREST3_byte_view_st *)\
(IRREST3_REG__ ))

/* Pointer to HALFWORD-struct */
#define pst_u16IRREST3()     ((volatile IRREST3_halfword_view_st *)\
(IRREST3_REG__ ))

/* Pointer to WORD  */
#define pu32IRREST3()     ((volatile u32IRREST3_word_view *)\
(IRREST3_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIRREST3_STCH96() (pst_bitIRREST3() -> STCH96)
#define biGetIRREST3_STCH97() (pst_bitIRREST3() -> STCH97)
#define biGetIRREST3_STCH98() (pst_bitIRREST3() -> STCH98)
#define biGetIRREST3_STCH99() (pst_bitIRREST3() -> STCH99)
#define biGetIRREST3_STCH100() (pst_bitIRREST3() -> STCH100)
#define biGetIRREST3_STCH101() (pst_bitIRREST3() -> STCH101)
#define biGetIRREST3_STCH102() (pst_bitIRREST3() -> STCH102)
#define biGetIRREST3_STCH103() (pst_bitIRREST3() -> STCH103)
#define biGetIRREST3_STCH104() (pst_bitIRREST3() -> STCH104)
#define biGetIRREST3_STCH105() (pst_bitIRREST3() -> STCH105)
#define biGetIRREST3_STCH106() (pst_bitIRREST3() -> STCH106)
#define biGetIRREST3_STCH107() (pst_bitIRREST3() -> STCH107)
#define biGetIRREST3_STCH108() (pst_bitIRREST3() -> STCH108)
#define biGetIRREST3_STCH109() (pst_bitIRREST3() -> STCH109)
#define biGetIRREST3_STCH110() (pst_bitIRREST3() -> STCH110)
#define biGetIRREST3_STCH111() (pst_bitIRREST3() -> STCH111)
#define biGetIRREST3_STCH112() (pst_bitIRREST3() -> STCH112)
#define biGetIRREST3_STCH113() (pst_bitIRREST3() -> STCH113)
#define biGetIRREST3_STCH114() (pst_bitIRREST3() -> STCH114)
#define biGetIRREST3_STCH115() (pst_bitIRREST3() -> STCH115)
#define biGetIRREST3_STCH116() (pst_bitIRREST3() -> STCH116)
#define biGetIRREST3_STCH117() (pst_bitIRREST3() -> STCH117)
#define biGetIRREST3_STCH118() (pst_bitIRREST3() -> STCH118)
#define biGetIRREST3_STCH119() (pst_bitIRREST3() -> STCH119)
#define biGetIRREST3_STCH120() (pst_bitIRREST3() -> STCH120)
#define biGetIRREST3_STCH121() (pst_bitIRREST3() -> STCH121)
#define biGetIRREST3_STCH122() (pst_bitIRREST3() -> STCH122)
#define biGetIRREST3_STCH123() (pst_bitIRREST3() -> STCH123)
#define biGetIRREST3_STCH124() (pst_bitIRREST3() -> STCH124)
#define biGetIRREST3_STCH125() (pst_bitIRREST3() -> STCH125)
#define biGetIRREST3_STCH126() (pst_bitIRREST3() -> STCH126)
#define biGetIRREST3_STCH127() (pst_bitIRREST3() -> STCH127)

/* LL-struct byte access */

#define u8GetIRREST3LL() (pst_u8IRREST3() -> u8LL)
/* LH-struct byte access */

#define u8GetIRREST3LH() (pst_u8IRREST3() -> u8LH)
/* HL-struct byte access */

#define u8GetIRREST3HL() (pst_u8IRREST3() -> u8HL)
/* HH-struct byte access */

#define u8GetIRREST3HH() (pst_u8IRREST3() -> u8HH)


/* Half-word struct access */

#define u16GetIRREST3L() (pst_u16IRREST3() -> u16L)

#define u16GetIRREST3H() (pst_u16IRREST3() -> u16H)

/* Word access */

#define u32GetIRREST3()  (*pu32IRREST3() )


/****************************************************************************
*
*       REGISTER: IRREST4
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080E4
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IRREST4_REG__       0xC01080E4U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   STCH128	:1; 	 /* 0..0  bit(s) R */
  uint32_t   STCH129	:1; 	 /* 1..1  bit(s) R */
  uint32_t   STCH130	:1; 	 /* 2..2  bit(s) R */
  uint32_t   STCH131	:1; 	 /* 3..3  bit(s) R */
  uint32_t   STCH132	:1; 	 /* 4..4  bit(s) R */
  uint32_t   STCH133	:1; 	 /* 5..5  bit(s) R */
  uint32_t   STCH134	:1; 	 /* 6..6  bit(s) R */
  uint32_t   STCH135	:1; 	 /* 7..7  bit(s) R */
  uint32_t   STCH136	:1; 	 /* 8..8  bit(s) R */
  uint32_t   STCH137	:1; 	 /* 9..9  bit(s) R */
  uint32_t   STCH138	:1; 	 /* 10..10  bit(s) R */
  uint32_t   STCH139	:1; 	 /* 11..11  bit(s) R */
  uint32_t   STCH140	:1; 	 /* 12..12  bit(s) R */
  uint32_t   STCH141	:1; 	 /* 13..13  bit(s) R */
  uint32_t   STCH142	:1; 	 /* 14..14  bit(s) R */
  uint32_t   STCH143	:1; 	 /* 15..15  bit(s) R */
  uint32_t   STCH144	:1; 	 /* 16..16  bit(s) R */
  uint32_t   STCH145	:1; 	 /* 17..17  bit(s) R */
  uint32_t   STCH146	:1; 	 /* 18..18  bit(s) R */
  uint32_t   STCH147	:1; 	 /* 19..19  bit(s) R */
  uint32_t   STCH148	:1; 	 /* 20..20  bit(s) R */
  uint32_t   STCH149	:1; 	 /* 21..21  bit(s) R */
  uint32_t   STCH150	:1; 	 /* 22..22  bit(s) R */
  uint32_t   STCH151	:1; 	 /* 23..23  bit(s) R */
  uint32_t   STCH152	:1; 	 /* 24..24  bit(s) R */
  uint32_t   STCH153	:1; 	 /* 25..25  bit(s) R */
  uint32_t   STCH154	:1; 	 /* 26..26  bit(s) R */
  uint32_t   STCH155	:1; 	 /* 27..27  bit(s) R */
  uint32_t   STCH156	:1; 	 /* 28..28  bit(s) R */
  uint32_t   STCH157	:1; 	 /* 29..29  bit(s) R */
  uint32_t   STCH158	:1; 	 /* 30..30  bit(s) R */
  uint32_t   STCH159	:1; 	 /* 31..31  bit(s) R */
} IRREST4_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} IRREST4_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} IRREST4_halfword_view_st;

/* WORD View */
typedef uint32_t u32IRREST4_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIRREST4()     ((volatile IRREST4_bit_view_st *)\
(IRREST4_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8IRREST4()     ((volatile IRREST4_byte_view_st *)\
(IRREST4_REG__ ))

/* Pointer to HALFWORD-struct */
#define pst_u16IRREST4()     ((volatile IRREST4_halfword_view_st *)\
(IRREST4_REG__ ))

/* Pointer to WORD  */
#define pu32IRREST4()     ((volatile u32IRREST4_word_view *)\
(IRREST4_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIRREST4_STCH128() (pst_bitIRREST4() -> STCH128)
#define biGetIRREST4_STCH129() (pst_bitIRREST4() -> STCH129)
#define biGetIRREST4_STCH130() (pst_bitIRREST4() -> STCH130)
#define biGetIRREST4_STCH131() (pst_bitIRREST4() -> STCH131)
#define biGetIRREST4_STCH132() (pst_bitIRREST4() -> STCH132)
#define biGetIRREST4_STCH133() (pst_bitIRREST4() -> STCH133)
#define biGetIRREST4_STCH134() (pst_bitIRREST4() -> STCH134)
#define biGetIRREST4_STCH135() (pst_bitIRREST4() -> STCH135)
#define biGetIRREST4_STCH136() (pst_bitIRREST4() -> STCH136)
#define biGetIRREST4_STCH137() (pst_bitIRREST4() -> STCH137)
#define biGetIRREST4_STCH138() (pst_bitIRREST4() -> STCH138)
#define biGetIRREST4_STCH139() (pst_bitIRREST4() -> STCH139)
#define biGetIRREST4_STCH140() (pst_bitIRREST4() -> STCH140)
#define biGetIRREST4_STCH141() (pst_bitIRREST4() -> STCH141)
#define biGetIRREST4_STCH142() (pst_bitIRREST4() -> STCH142)
#define biGetIRREST4_STCH143() (pst_bitIRREST4() -> STCH143)
#define biGetIRREST4_STCH144() (pst_bitIRREST4() -> STCH144)
#define biGetIRREST4_STCH145() (pst_bitIRREST4() -> STCH145)
#define biGetIRREST4_STCH146() (pst_bitIRREST4() -> STCH146)
#define biGetIRREST4_STCH147() (pst_bitIRREST4() -> STCH147)
#define biGetIRREST4_STCH148() (pst_bitIRREST4() -> STCH148)
#define biGetIRREST4_STCH149() (pst_bitIRREST4() -> STCH149)
#define biGetIRREST4_STCH150() (pst_bitIRREST4() -> STCH150)
#define biGetIRREST4_STCH151() (pst_bitIRREST4() -> STCH151)
#define biGetIRREST4_STCH152() (pst_bitIRREST4() -> STCH152)
#define biGetIRREST4_STCH153() (pst_bitIRREST4() -> STCH153)
#define biGetIRREST4_STCH154() (pst_bitIRREST4() -> STCH154)
#define biGetIRREST4_STCH155() (pst_bitIRREST4() -> STCH155)
#define biGetIRREST4_STCH156() (pst_bitIRREST4() -> STCH156)
#define biGetIRREST4_STCH157() (pst_bitIRREST4() -> STCH157)
#define biGetIRREST4_STCH158() (pst_bitIRREST4() -> STCH158)
#define biGetIRREST4_STCH159() (pst_bitIRREST4() -> STCH159)

/* LL-struct byte access */

#define u8GetIRREST4LL() (pst_u8IRREST4() -> u8LL)
/* LH-struct byte access */

#define u8GetIRREST4LH() (pst_u8IRREST4() -> u8LH)
/* HL-struct byte access */

#define u8GetIRREST4HL() (pst_u8IRREST4() -> u8HL)
/* HH-struct byte access */

#define u8GetIRREST4HH() (pst_u8IRREST4() -> u8HH)


/* Half-word struct access */

#define u16GetIRREST4L() (pst_u16IRREST4() -> u16L)

#define u16GetIRREST4H() (pst_u16IRREST4() -> u16H)

/* Word access */

#define u32GetIRREST4()  (*pu32IRREST4() )


/****************************************************************************
*
*       REGISTER: IRREST5
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080E8
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IRREST5_REG__       0xC01080E8U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   STCH160	:1; 	 /* 0..0  bit(s) R */
  uint32_t   STCH161	:1; 	 /* 1..1  bit(s) R */
  uint32_t   STCH162	:1; 	 /* 2..2  bit(s) R */
  uint32_t   STCH163	:1; 	 /* 3..3  bit(s) R */
  uint32_t   STCH164	:1; 	 /* 4..4  bit(s) R */
  uint32_t   STCH165	:1; 	 /* 5..5  bit(s) R */
  uint32_t   STCH166	:1; 	 /* 6..6  bit(s) R */
  uint32_t   STCH167	:1; 	 /* 7..7  bit(s) R */
  uint32_t   STCH168	:1; 	 /* 8..8  bit(s) R */
  uint32_t   STCH169	:1; 	 /* 9..9  bit(s) R */
  uint32_t   STCH170	:1; 	 /* 10..10  bit(s) R */
  uint32_t   STCH171	:1; 	 /* 11..11  bit(s) R */
  uint32_t   STCH172	:1; 	 /* 12..12  bit(s) R */
  uint32_t   STCH173	:1; 	 /* 13..13  bit(s) R */
  uint32_t   STCH174	:1; 	 /* 14..14  bit(s) R */
  uint32_t   STCH175	:1; 	 /* 15..15  bit(s) R */
  uint32_t   STCH176	:1; 	 /* 16..16  bit(s) R */
  uint32_t   STCH177	:1; 	 /* 17..17  bit(s) R */
  uint32_t   STCH178	:1; 	 /* 18..18  bit(s) R */
  uint32_t   STCH179	:1; 	 /* 19..19  bit(s) R */
  uint32_t   STCH180	:1; 	 /* 20..20  bit(s) R */
  uint32_t   STCH181	:1; 	 /* 21..21  bit(s) R */
  uint32_t   STCH182	:1; 	 /* 22..22  bit(s) R */
  uint32_t   STCH183	:1; 	 /* 23..23  bit(s) R */
  uint32_t   STCH184	:1; 	 /* 24..24  bit(s) R */
  uint32_t   STCH185	:1; 	 /* 25..25  bit(s) R */
  uint32_t   STCH186	:1; 	 /* 26..26  bit(s) R */
  uint32_t   STCH187	:1; 	 /* 27..27  bit(s) R */
  uint32_t   STCH188	:1; 	 /* 28..28  bit(s) R */
  uint32_t   STCH189	:1; 	 /* 29..29  bit(s) R */
  uint32_t   STCH190	:1; 	 /* 30..30  bit(s) R */
  uint32_t   STCH191	:1; 	 /* 31..31  bit(s) R */
} IRREST5_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} IRREST5_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} IRREST5_halfword_view_st;

/* WORD View */
typedef uint32_t u32IRREST5_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIRREST5()     ((volatile IRREST5_bit_view_st *)\
(IRREST5_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8IRREST5()     ((volatile IRREST5_byte_view_st *)\
(IRREST5_REG__ ))

/* Pointer to HALFWORD-struct */
#define pst_u16IRREST5()     ((volatile IRREST5_halfword_view_st *)\
(IRREST5_REG__ ))

/* Pointer to WORD  */
#define pu32IRREST5()     ((volatile u32IRREST5_word_view *)\
(IRREST5_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIRREST5_STCH160() (pst_bitIRREST5() -> STCH160)
#define biGetIRREST5_STCH161() (pst_bitIRREST5() -> STCH161)
#define biGetIRREST5_STCH162() (pst_bitIRREST5() -> STCH162)
#define biGetIRREST5_STCH163() (pst_bitIRREST5() -> STCH163)
#define biGetIRREST5_STCH164() (pst_bitIRREST5() -> STCH164)
#define biGetIRREST5_STCH165() (pst_bitIRREST5() -> STCH165)
#define biGetIRREST5_STCH166() (pst_bitIRREST5() -> STCH166)
#define biGetIRREST5_STCH167() (pst_bitIRREST5() -> STCH167)
#define biGetIRREST5_STCH168() (pst_bitIRREST5() -> STCH168)
#define biGetIRREST5_STCH169() (pst_bitIRREST5() -> STCH169)
#define biGetIRREST5_STCH170() (pst_bitIRREST5() -> STCH170)
#define biGetIRREST5_STCH171() (pst_bitIRREST5() -> STCH171)
#define biGetIRREST5_STCH172() (pst_bitIRREST5() -> STCH172)
#define biGetIRREST5_STCH173() (pst_bitIRREST5() -> STCH173)
#define biGetIRREST5_STCH174() (pst_bitIRREST5() -> STCH174)
#define biGetIRREST5_STCH175() (pst_bitIRREST5() -> STCH175)
#define biGetIRREST5_STCH176() (pst_bitIRREST5() -> STCH176)
#define biGetIRREST5_STCH177() (pst_bitIRREST5() -> STCH177)
#define biGetIRREST5_STCH178() (pst_bitIRREST5() -> STCH178)
#define biGetIRREST5_STCH179() (pst_bitIRREST5() -> STCH179)
#define biGetIRREST5_STCH180() (pst_bitIRREST5() -> STCH180)
#define biGetIRREST5_STCH181() (pst_bitIRREST5() -> STCH181)
#define biGetIRREST5_STCH182() (pst_bitIRREST5() -> STCH182)
#define biGetIRREST5_STCH183() (pst_bitIRREST5() -> STCH183)
#define biGetIRREST5_STCH184() (pst_bitIRREST5() -> STCH184)
#define biGetIRREST5_STCH185() (pst_bitIRREST5() -> STCH185)
#define biGetIRREST5_STCH186() (pst_bitIRREST5() -> STCH186)
#define biGetIRREST5_STCH187() (pst_bitIRREST5() -> STCH187)
#define biGetIRREST5_STCH188() (pst_bitIRREST5() -> STCH188)
#define biGetIRREST5_STCH189() (pst_bitIRREST5() -> STCH189)
#define biGetIRREST5_STCH190() (pst_bitIRREST5() -> STCH190)
#define biGetIRREST5_STCH191() (pst_bitIRREST5() -> STCH191)

/* LL-struct byte access */

#define u8GetIRREST5LL() (pst_u8IRREST5() -> u8LL)
/* LH-struct byte access */

#define u8GetIRREST5LH() (pst_u8IRREST5() -> u8LH)
/* HL-struct byte access */

#define u8GetIRREST5HL() (pst_u8IRREST5() -> u8HL)
/* HH-struct byte access */

#define u8GetIRREST5HH() (pst_u8IRREST5() -> u8HH)


/* Half-word struct access */

#define u16GetIRREST5L() (pst_u16IRREST5() -> u16L)

#define u16GetIRREST5H() (pst_u16IRREST5() -> u16H)

/* Word access */

#define u32GetIRREST5()  (*pu32IRREST5() )


/****************************************************************************
*
*       REGISTER: IWPERR
*       SIZE    : 32-bits
*       ADDRESS : 0xC01080EC
*       ACCESS  : 8, 16, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define IWPERR_REG__       0xC01080ECU

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint16_t   IWPNTEN	:1; 	 /* 0..0  bit(s) R/W */
  uint16_t   	:7; 	 /* 1..7  bit(s) R */
  uint16_t   IWPINTCLR	:1; 	 /* 8..8  bit(s) R/W */
  uint16_t   	:7; 	 /* 9..31  bit(s) R */
} IWPERR_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8L;
  uint8_t u8H;
} IWPERR_byte_view_st;

/* HALFWORD View */
typedef uint16_t u16IWPERR_halfword_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitIWPERR()     ((volatile IWPERR_bit_view_st *)\
(IWPERR_REG__ ))

/* Pointer to BYTE-struct  */
#define pst_u8IWPERR()     ((volatile IWPERR_byte_view_st *)\
(IWPERR_REG__ ))

/* Pointer to HALFWORD */
#define pu16IWPERR()     ((volatile u16IWPERR_halfword_view *)\
(IWPERR_REG__ ))


/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetIWPERR_IWPNTEN() (pst_bitIWPERR() -> IWPNTEN)
#define vSetIWPERR_IWPNTEN(ParValue)  (pst_bitIWPERR() -> IWPNTEN=(ParValue))
#define biGetIWPERR_IWPINTCLR() (pst_bitIWPERR() -> IWPINTCLR)
#define vSetIWPERR_IWPINTCLR(ParValue)  (pst_bitIWPERR() -> IWPINTCLR=(ParValue))

/* L-struct byte access */
#define vSetIWPERRL(ParValue) (pst_u8IWPERR() -> u8L = (ParValue))
#define u8GetIWPERRL() (pst_u8IWPERR() -> u8L)
/* H-struct byte access */
#define vSetIWPERRH(ParValue) (pst_u8IWPERR() -> u8H = (ParValue))
#define u8GetIWPERRH() (pst_u8IWPERR() -> u8H)

/* Half-word access */
#define vSetIWPERR(ParValue) (*pu16IWPERR()  = (ParValue))
#define u16GetIWPERR() (*pu16IWPERR() )

/****************************************************************************
*
*       REGISTER: ISRADDR
*       SIZE    : 32-bits
*       ADDRESS : 0xC0108200
*       ACCESS  : 8, 16, 32, BIT-level
*
*****************************************************************************/
/* Assign Register address: */
#define ISRADDR_REG__       0xC0108200U

/************************       STRUCTURES        ***************************/


/* BIT View */
typedef struct{
  uint32_t   	:2; 	 /* 0..1  bit(s) R */
  uint32_t   ISRADDR	:30; 	 /* 2..31  bit(s) R/W */
} ISRADDR_bit_view_st;


/* BYTE View */
typedef struct{
  uint8_t u8LL;
  uint8_t u8LH;
  uint8_t u8HL;
  uint8_t u8HH;
} ISRADDR_byte_view_st;

/* HALFWORD View */
typedef struct{
  uint16_t u16L;
  uint16_t u16H;
} ISRADDR_halfword_view_st;

/* WORD View */
typedef uint32_t u32ISRADDR_word_view;



/************************     ACCESS POINTERS    ****************************/

/* Pointer to BIT-struct */
#define pst_bitISRADDR(ch)     ((volatile ISRADDR_bit_view_st *)\
(ISRADDR_REG__  + ((uint16_t)(ch) * 0x004U)))

/* Pointer to BYTE-struct  */
#define pst_u8ISRADDR(ch)     ((volatile ISRADDR_byte_view_st *)\
(ISRADDR_REG__  + ((uint16_t)(ch) * 0x004U)))

/* Pointer to HALFWORD-struct */
#define pst_u16ISRADDR(ch)     ((volatile ISRADDR_halfword_view_st *)\
(ISRADDR_REG__  + ((uint16_t)(ch) * 0x004U)))

/* Pointer to WORD  */
#define pu32ISRADDR(ch)     ((volatile u32ISRADDR_word_view *)\
(ISRADDR_REG__  + ((uint16_t)(ch) * 0x004U)))

/************************ REGISTER ACCESS MACROS ****************************/

/* ACCESS MACROS - ATTENTION: REGISTER SHADOW TECHNIQUE MIGHT BE APPLIED */
/* Bit-struct access */
#define biGetISRADDR_ISRADDR(ch) (pst_bitISRADDR(ch) -> ISRADDR)
#define vSetISRADDR_ISRADDR(ch,ParValue)  (pst_bitISRADDR(ch) -> ISRADDR=(ParValue))

/* LL-struct byte access */
#define vSetISRADDRLL(ch,ParValue) (pst_u8ISRADDR(ch) -> u8LL = (ParValue))
#define u8GetISRADDRLL(ch) (pst_u8ISRADDR(ch) -> u8LL)
/* LH-struct byte access */
#define vSetISRADDRLH(ch,ParValue) (pst_u8ISRADDR(ch) -> u8LH = (ParValue))
#define u8GetISRADDRLH(ch) (pst_u8ISRADDR(ch) -> u8LH)
/* HL-struct byte access */
#define vSetISRADDRHL(ch,ParValue) (pst_u8ISRADDR(ch) -> u8HL = (ParValue))
#define u8GetISRADDRHL(ch) (pst_u8ISRADDR(ch) -> u8HL)
/* HH-struct byte access */
#define vSetISRADDRHH(ch,ParValue) (pst_u8ISRADDR(ch) -> u8HH = (ParValue))
#define u8GetISRADDRHH(ch) (pst_u8ISRADDR(ch) -> u8HH)


/* Half-word struct access */
#define vSetISRADDRL(ch,ParValue) (pst_u16ISRADDR(ch) -> u16L = (ParValue))
#define u16GetISRADDRL(ch) (pst_u16ISRADDR(ch) -> u16L)
#define vSetISRADDRH(ch,ParValue) (pst_u16ISRADDR(ch) -> u16H = (ParValue))
#define u16GetISRADDRH(ch) (pst_u16ISRADDR(ch) -> u16H)

/* Word access */
#define vSetISRADDR(ch,ParValue)  (*pu32ISRADDR(ch) = (ParValue))
#define u32GetISRADDR(ch)  (*pu32ISRADDR(ch) )

#if defined(__GHS__) || defined(__ghs__)
#pragma ghs endnowarning /* enable Rule 3.5 [R] : derived  disable warnings for nonstandard type for a bit field */
#endif /* defined(__GHS__) || defined(__ghs__) */

#endif /* _INTCIO_H */

/************************** BEGIN of DISCLAIMER   *************************

- TOSHIBA is continually working to improve the quality and reliability of
  its products. Nevertheless, semiconductor devices in general can
  malfunction or fail due to their inherent electrical sensitivity and
  vulnerability to physical stress. It is the responsibility of the buyer,
  when utilizing TOSHIBA products, to comply with the standards of safety
  in making a safe design for the entire system, and to avoid situations in
  which a malfunction or failure of such TOSHIBA products could cause loss of
  human life, bodily injury or damage to property.

  In developing your designs, please ensure that TOSHIBA products are used
  within specified operating ranges as set forth in the most recent TOSHIBA
  products specifications.
  Also, please keep in mind the precautions and conditions set forth in the
  Handling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment, office
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.).
  These Toshiba products are neither intended nor warranted for usage in
  equipment that requires extraordinarily high quality and/or reliability or
  a malfunction or failure of which may cause loss of human life or bodily
  injury (Unintended Usage). Unintended Usage include atomic energy control
  instruments, airplane or spaceship instruments, transportation instruments,
  traffic signal instruments, combustion control instruments, medical
  instruments, all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be
  made at the customers own risk.

- Toshiba assumes no liability for any damage or losses (including but not
  limited to, loss of business profit,business interruption, loss of business
  information,and other pecuniary losses) occurring
  from the use of, or inability to use, this product.

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

