/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   DESCRIPTION : PNG-decoder low level driver header file
******************************************************************************
*   PLATFORM    : TMPR46xXBG-300
*   PROJECT     :
*   MODULE      : PNG
*   LIBRARIES   : None
******************************************************************************
*   VERSION     : $Revision: 1.13 $
*   DATE        : $Date: 2015/05/04 09:07:14 $
*   TAG         : $Name: LLDD_1_7_GFX $
*   RELEASE     : Preliminary & Confidential
*****************************************************************************/
#ifndef PNG_H
#define PNG_H

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"

/*********************************************/
/*********************************************
*           Disable Misra Warnings/Rules     *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)

  #pragma ghs nowarning 1840  /* Rule 5.7  [A] : No reuse of identifiers */

#endif
/**********************************************
*                 Constants                   *
**********************************************/

#define LLDD_PNG_H_REVISION     "$Revision: 1.13 $"
#define LLDD_PNG_H_TAG          "$Name: LLDD_1_7_GFX $"

/*********************************************/

#define PNG_VIRTUAL_START_ADDRESS           (0x70000000)
#define PNG_VIRTUAL_STREAM_LENGTH           (0x00800000)

#define PNG_VIRTUAL_START_ADDRESS_STREAM_0  (PNG_VIRTUAL_START_ADDRESS + 0x0*PNG_VIRTUAL_STREAM_LENGTH)
#define PNG_VIRTUAL_START_ADDRESS_STREAM_1  (PNG_VIRTUAL_START_ADDRESS + 0x1*PNG_VIRTUAL_STREAM_LENGTH)
#define PNG_VIRTUAL_START_ADDRESS_STREAM_2  (PNG_VIRTUAL_START_ADDRESS + 0x2*PNG_VIRTUAL_STREAM_LENGTH)
#define PNG_VIRTUAL_START_ADDRESS_STREAM_3  (PNG_VIRTUAL_START_ADDRESS + 0x3*PNG_VIRTUAL_STREAM_LENGTH)
#define PNG_VIRTUAL_START_ADDRESS_STREAM_4  (PNG_VIRTUAL_START_ADDRESS + 0x4*PNG_VIRTUAL_STREAM_LENGTH)
#define PNG_VIRTUAL_START_ADDRESS_STREAM_5  (PNG_VIRTUAL_START_ADDRESS + 0x5*PNG_VIRTUAL_STREAM_LENGTH)
#define PNG_VIRTUAL_START_ADDRESS_STREAM_6  (PNG_VIRTUAL_START_ADDRESS + 0x6*PNG_VIRTUAL_STREAM_LENGTH)
#define PNG_VIRTUAL_START_ADDRESS_STREAM_7  (PNG_VIRTUAL_START_ADDRESS + 0x7*PNG_VIRTUAL_STREAM_LENGTH)

#define PNG_VIRTUAL_END_ADDRESS_STREAM_0    (PNG_VIRTUAL_START_ADDRESS_STREAM_0 + PNG_VIRTUAL_STREAM_LENGTH - 1)
#define PNG_VIRTUAL_END_ADDRESS_STREAM_1    (PNG_VIRTUAL_START_ADDRESS_STREAM_1 + PNG_VIRTUAL_STREAM_LENGTH - 1)
#define PNG_VIRTUAL_END_ADDRESS_STREAM_2    (PNG_VIRTUAL_START_ADDRESS_STREAM_2 + PNG_VIRTUAL_STREAM_LENGTH - 1)
#define PNG_VIRTUAL_END_ADDRESS_STREAM_3    (PNG_VIRTUAL_START_ADDRESS_STREAM_3 + PNG_VIRTUAL_STREAM_LENGTH - 1)
#define PNG_VIRTUAL_END_ADDRESS_STREAM_4    (PNG_VIRTUAL_START_ADDRESS_STREAM_4 + PNG_VIRTUAL_STREAM_LENGTH - 1)
#define PNG_VIRTUAL_END_ADDRESS_STREAM_5    (PNG_VIRTUAL_START_ADDRESS_STREAM_5 + PNG_VIRTUAL_STREAM_LENGTH - 1)
#define PNG_VIRTUAL_END_ADDRESS_STREAM_6    (PNG_VIRTUAL_START_ADDRESS_STREAM_6 + PNG_VIRTUAL_STREAM_LENGTH - 1)
#define PNG_VIRTUAL_END_ADDRESS_STREAM_7    (PNG_VIRTUAL_START_ADDRESS_STREAM_7 + PNG_VIRTUAL_STREAM_LENGTH - 1)

/**********************************************
*               Enumerations                  *
**********************************************/
/* stream */
typedef enum tag_png_stream_e
{
   PNG_STREAM_0 = 0,                      /* stream 0 */
   PNG_STREAM_1 = 1,                      /* stream 1 */
   PNG_STREAM_2 = 2,                      /* stream 2 */
   PNG_STREAM_3 = 3,                      /* stream 3 */
   PNG_STREAM_4 = 4,                      /* stream 4 */
   PNG_STREAM_5 = 5,                      /* stream 5 */
   PNG_STREAM_6 = 6,                      /* stream 6 */
   PNG_STREAM_7 = 7                       /* stream 7 */
} png_stream_e;

/* enable/disable */
typedef enum tag_png_enable_e
{
   PNG_DIS = 0,                           /* disable */
   PNG_EN  = 1                            /* enable  */
} png_enable_e;

/* interrupt type */
typedef enum tag_png_int_type_e
{
   PNG_INT_LEVEL = 0,                     /* level interrupt */
   PNG_INT_PULSE = 1                      /* pulse interrupt  */
} png_int_type_e;

/* interrupts */
typedef enum tag_png_int_e
{
   PNG_INT_VSWAEI    = 0,                 /* VSWAEI interrupt */
   PNG_INT_VSUAEI    = 1,                 /* VSUAEI interrupt  */
   PNG_INT_CW2ROEI   = 2,                 /* CW2ROEI interrupt */
   PNG_INT_CRSVAEI   = 3,                 /* CRSVAEI interrupt  */
   PNG_INT_CPEI      = 4,                 /* CPEI interrupt */
   PNG_INT_SWBEI     = 5,                 /* SWBEI interrupt  */
   PNG_INT_SSBEI     = 6,                 /* SSBEI interrupt  */
   /*********************************/
   PNG_INT_BJMPEI    = 7,                 /* BJMPEI interrupt */
   PNG_INT_UFMTEI    = 8,                 /* UFMTEI interrupt */
   PNG_INT_OOCEI     = 9,                 /* OOCEI interrupt */
   PNG_INT_CHSEI     = 10,                /* CHSEI interrupt */
   PNG_INT_EYEOSEI   = 11,                /* EYEOSEI interrupt */
   PNG_INT_NOEOSEI   = 12,                /* NOEOSEI interrupt */
   PNG_INT_CMPEI     = 13,                /* CMPEI interrupt */
   PNG_INT_BTYPEEI   = 14,                /* BTYPEEI interrupt */
   PNG_INT_DISTEI    = 15,                /* DISTEI interrupt */
   PNG_INT_NCBSEI    = 16,                /* NCBSEI interrupt */
   PNG_INT_DECEI     = 17,                /* DECEI interrupt */
   PNG_INT_FJMPWI    = 18,                /* FJMPWI interrupt */
   PNG_INT_UCHNKWI   = 19,                /* UCHNKWI interrupt */
   PNG_INT_PDICTWI   = 20,                /* PDICTWI interrupt */
   PNG_INT_ULLWI     = 21,                /* ULLWI interrupt */
   PNG_INT_UDISTWI   = 22,                /* UDISTWI interrupt */
   PNG_INT_OFCWI     = 23,                /* OFCWI interrupt */
   PNG_INT_IHDRDI    = 24,                /* IHDRDI interrupt */
   PNG_INT_PLTEDI    = 25,                /* PLTEDI interrupt */
   PNG_INT_IDATDI    = 26,                /* IDATDI interrupt */
   PNG_INT_IENDDI    = 27,                /* IENDDI interrupt */
   PNG_INT_DCDSI     = 28,                /* DCDSI interrupt */
   PNG_INT_SIDLEI    = 29,                /* SIDLEI interrupt */
   PNG_INT_DSFFULLIE = 30                 /* DSFFULLIE interrupt */
} png_int_e;

/* interrupt status */
typedef enum tag_png_int_status_e
{
   PNG_INT_NOT_PENDING = 0,               /* interrupt is not pending */
   PNG_INT_PENDING     = 1                /* interrupt is pending */
} png_int_status_e;

/* transfer type */
typedef enum tag_png_transfer_type_e
{
    PNG_READ_TRANSFER  = 0,               /* read transfer */
    PNG_WRITE_TRANSFER = 1                /* write transfer */
} png_transfer_type_e;

/* burst type */
typedef enum tag_png_burst_type_e
{
    PNG_FIXED_BURST = 0,                  /* fixed burst */
    PNG_INCR_BURST  = 1                   /* increment burst */
} png_burst_type_e;

/* response type */
typedef enum tag_png_response_type_e
{
    PNG_RESPONSE_OKAY   = 0,              /* OKAY */
    PNG_RESPONSE_EXOKAY = 1,              /* EXOKAY */
    PNG_RESPONSE_SLVERR = 2,              /* SLVERR */
    PNG_RESPONSE_DECERR = 3               /* DECERR */
} png_response_type_e;

/* decode mode */
typedef enum tag_png_decode_mode_e
{
    PNG_SINGLE_DECODE_MODE = 0,           /* single decode mode */
    PNG_LOOP_DECODE_MODE   = 1            /* loop decode mode */
} png_decode_mode_e;

/* decoded output format */
typedef enum tag_png_decoded_output_format_e
{
    PNG_OUTPUT_FORMAT_RGBA32 = 0x4,       /* RGBA32 */
    PNG_OUTPUT_FORMAT_RGB24  = 0x2,       /* RGB24 */
    PNG_OUTPUT_FORMAT_A8     = 0x1        /* A8 */
} png_decoded_output_format_e;

/* stream phase status */
typedef enum tag_png_phase_status_e
{
   PNG_IDLE_PHASE   = 0,                  /* stream in idle phase */
   PNG_DECODE_PHASE = 1                   /* stream in decode phase  */
} png_phase_status_e;

/* palette table loaded */
typedef enum tag_png_pt_loaded_e
{
   PNG_PALETTE_TABLE_NOT_LOADED = 0,      /* palette table not loaded */
   PNG_PALETTE_TABLE_LOADED     = 1       /* palette table loaded  */
} png_pt_loaded_e;

/* current chunk */
typedef enum tag_png_chunk_e
{
    PNG_CHUNK_IHDR  = 0,                  /* IHDR */
    PNG_CHUNK_IPLTE = 1,                  /* IPLTE */
    PNG_CHUNK_IDAT  = 2,                  /* IDAT */
    PNG_CHUNK_IEND  = 3                   /* IEND */
} png_chunk_e;

/* bit depth */
typedef enum tag_png_bit_depth_e
{
    PNG_BIT_DEPTH_1  = 0x1,               /* bit depth 1 */
    PNG_BIT_DEPTH_2  = 0x2,               /* bit depth 2 */
    PNG_BIT_DEPTH_4  = 0x4,               /* bit depth 4 */
    PNG_BIT_DEPTH_8  = 0x8,               /* bit depth 8 */
    PNG_BIT_DEPTH_16 = 0x10               /* bit depth 16 */
} png_bit_depth_e;

/* color format */
typedef enum tag_png_color_format_e
{
    PNG_COLOR_FORMAT_GRAY     = 0,        /* gray */
    PNG_COLOR_FORMAT_RGB888   = 2,        /* truecolor */
    PNG_COLOR_FORMAT_CLUT     = 3,        /* indexed */
    PNG_COLOR_FORMAT_GRAYA    = 4,        /* gray with alpha */
    PNG_COLOR_FORMAT_RGBA8888 = 6         /* truecolor with alpha */
} png_color_format_e;

/* color format */
typedef enum tag_png_burst_size_e
{
    PNG_BURST_1_BYTE     = 0,  /* 1 byte burst size   */
    PNG_BURST_2_BYTE     = 1,  /* 2 byte burst size   */
    PNG_BURST_4_BYTE     = 2,  /* 4 byte burst size   */
    PNG_BURST_8_BYTE     = 3,  /* 8 byte burst size   */
    PNG_BURST_16_BYTE    = 4,  /* 16 byte burst size  */
    PNG_BURST_32_BYTE    = 5,  /* 32 byte burst size  */
    PNG_BURST_64_BYTE    = 6,  /* 64 byte burst size  */
    PNG_BURST_128_BYTE   = 7   /* 128 byte burst size */
} png_burst_size_e;

/* color format */
typedef enum tag_png_bus_error_type_e
{
    PNG_SLIDING_WINDOW_ERR  = 0,  /* Sliding window bus error   */
    PNG_SOURCE_STREAM_ERR   = 1  /* source stream bus error    */
} png_bus_error_type_e;

/*********************************************/

/**********************************************
*                 Structures                  *
**********************************************/

/* PNG Bus error */
typedef struct tag_png_bus_error_st
{
    uint32_t             u32ErrAddress;  /* Bus error address    */
    png_transfer_type_e  eRWdir;         /* Read/Write Direction */
    png_burst_type_e     eBurstType;     /* Burst Type           */
    png_burst_size_e     eBurstSize;     /* Burst Size           */
    png_response_type_e  eRespType;      /* Response Type        */
    png_enable_e         eByteEnable;    /* Byte Enables         */
    uint8_t              u8ID;           /* ID Tag               */
    uint8_t              u8BurstLen;     /* Burst Length         */
} png_bus_error_st;

/* Stream status */
typedef struct tag_png_stream_status_st
{
    png_phase_status_e   ePhase;          /* stream phase                  */
    png_pt_loaded_e      ePalTableLoad;   /* palette table loaded          */
    png_chunk_e          eTypeOfChunk;    /* Type of chunk being processed */
    uint16_t             u16NoPalEntries; /* No. of palette entries        */
    uint8_t              u8NoIdatChunks;  /* No. of IDAT chunks            */
} png_stream_status_st;

/* Stream IHDR Information */
typedef struct tag_png_stream_ihdr_info_st
{
    png_bit_depth_e      eBitDepth;       /* number of bits per sample or number of bits per 
                                             palette index, as determined from the IHDR chunk.*/
    png_color_format_e   eColorType;      /* Color Type                     */
    uint8_t              u8ComprMethod;   /* Compression Method             */
    uint8_t              u8FilterMethod;  /* Filter Method                  */
    uint8_t              u8InterlMethod;  /* Interlace Method               */
} png_stream_ihdr_info_st;

/* Stream ZLIB Information */
typedef struct tag_png_stream_zlib_info_st
{
    uint8_t   u8ComprMethod;    /* CMF.CF (Compression Method) filed from the ZLIB stream.      */
    uint8_t   u8ComprInfo;      /* CMF.CINFO (Compression Info) field from the ZLIB stream.     */
    uint8_t   u8CheckBits;      /* Check bits for CMF and FLG, as received from the ZLIB stream */
    uint8_t   u8Fdict;          /* FLG.FDICT (i.e. Preset Dictionary) flag received in the ZLIB stream. */
    uint8_t   u8Flevel;         /* Compression Level” flags received in the ZLIB stream.         */
} png_stream_zlib_info_st;

/*********************************************/

/**********************************************
*            Forward declarations             *
**********************************************/

/*********************************************/

/**********************************************
*        Exported function prototypes         *
**********************************************/

/****************************************************************************
 *
 * Function:      vPNG_GetVersion
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
void vPNG_GetVersion(uint8_t** pau8ModuleRevision, uint8_t** pau8ModuleTag,
                     uint8_t** pau8HeaderRevision, uint8_t** pau8HeaderTag,
                     uint8_t** pau8IORevision, uint8_t** pau8IOTag);

/****************************************************************************
 *
 * Function:      vPNG_Init
 *
 * Purpose:       Initialisation of PNG-decoder.
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: none
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vPNG_Init(void);

/****************************************************************************
 *
 * Function:      i32PNG_SetUpStream
 *
 * Purpose:       Configure png-stream and start
 *
 * Inputs:        eStream            Stream
 *                u32StartAddress    Start address of input image
 *                eDecodeMode        Loop decode mode
 *                eOutputFormat      Color output format
 *                u32Width           Image width
 *                u32Height          Image height
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on stream running
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32PNG_SetUpStream(png_stream_e eStream, uint32_t u32StartAddress, png_decode_mode_e eDecodeMode,
                           png_decoded_output_format_e eOutputFormat, uint32_t u32Width, uint32_t u32Height);

/****************************************************************************
 *
 * Function:      u32PNG_GetModuleVersion
 *
 * Purpose:       Return module version
 *
 * Inputs:        none
 *
 * Outputs:       none
 *
 * Return Values: module version
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32PNG_GetModuleVersion(void);

/****************************************************************************
 *
 * Function:      vPNG_SetIntType
 *
 * Purpose:       Set PNG-interrupt type
 *
 * Inputs:        eIntType    Interrupt type
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vPNG_SetIntType(png_int_type_e eIntType);

/****************************************************************************
 *
 * Function:      i32PNG_EnableGlobalInterruptSingle
 *
 * Purpose:       Enable or disable single interrupt
 *
 * Inputs:        eInt    Interrupt type
 *                eEn     Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32PNG_EnableGlobalInterruptSingle(png_int_e eInt, png_enable_e eEn);

/****************************************************************************
 *
 * Function:      i32PNG_EnableStreamInterruptSingle
 *
 * Purpose:       Enable or disable single interrupt
 *
 * Inputs:        eStream    Stream
 *                eInt       Interrupt type
 *                eEn        Enable or disable
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32PNG_EnableStreamInterruptSingle(png_stream_e eStream, png_int_e eInt, png_enable_e eEn);

/****************************************************************************
 *
 * Function:      vPNG_EnableGlobalInterruptAll
 *
 * Purpose:       Enable or disable all interrupt
 *
 * Inputs:        u8Value    Interrupt enable or disable value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vPNG_EnableGlobalInterruptAll(uint8_t u8Value);

/****************************************************************************
 *
 * Function:      vPNG_EnableStreamInterruptAll
 *
 * Purpose:       Enable or disable all interrupt
 *
 * Inputs:        eStream    Stream
 *                u8Value    Interrupt enable or disable value
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vPNG_EnableStreamInterruptAll(png_stream_e eStream, uint32_t u32Value);

/****************************************************************************
 *
 * Function:      i32PNG_GetGlobalInterruptStatusSingle
 *
 * Purpose:       Get single interrupt status
 *
 * Inputs:        eInt          Interrupt type
 *
 * Outputs:       peIntStatus   pointer to Interrupt status
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32PNG_GetGlobalInterruptStatusSingle(png_int_e eInt, png_int_status_e * peIntStatus);

/****************************************************************************
 *
 * Function:      i32PNG_GetStreamInterruptStatusSingle
 *
 * Purpose:       Get single interrupt status
 *
 * Inputs:        eStream       Stream
 *                eInt          Interrupt type
 *
 * Outputs:       peIntStatus   pointer to Interrupt status
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32PNG_GetStreamInterruptStatusSingle(png_stream_e eStream, png_int_e eInt, png_int_status_e * peIntStatus);

/****************************************************************************
 *
 * Function:      u8PNG_GetGlobalInterruptStatusAll
 *
 * Purpose:       Get interrupt status of all interrupt
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: Interrupt status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8PNG_GetGlobalInterruptStatusAll(void);

/****************************************************************************
 *
 * Function:      u32PNG_GetStreamInterruptStatusAll
 *
 * Purpose:       Get interrupt status of all interrupt
 *
 * Inputs:        eStream    Stream
 *
 * Outputs:       none
 *
 * Return Values: Interrupt status
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32PNG_GetStreamInterruptStatusAll(png_stream_e eStream);

/****************************************************************************
 *
 * Function:      i32PNG_ClearGlobalInterruptSingle
 *
 * Purpose:       Clear single interrupt
 *
 * Inputs:        eInt    Interrupt type
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32PNG_ClearGlobalInterruptSingle(png_int_e eInt);

/****************************************************************************
 *
 * Function:      i32PNG_ClearStreamInterruptSingle
 *
 * Purpose:       Clear single interrupt
 *
 * Inputs:        eStream    Stream
 *                eInt       Interrupt type
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32PNG_ClearStreamInterruptSingle(png_stream_e eStream, png_int_e eInt);

/****************************************************************************
 *
 * Function:      vPNG_ClearGlobalInterruptAll
 *
 * Purpose:       Clear all interrupts
 *
 * Inputs:        void
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vPNG_ClearGlobalInterruptAll(void);

/****************************************************************************
 *
 * Function:      vPNG_ClearStreamInterruptAll
 *
 * Purpose:       Clear all interrupts
 *
 * Inputs:        eStream    Stream
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vPNG_ClearStreamInterruptAll(png_stream_e eStream);

/****************************************************************************
 *
 * Function:      vPNG_ResetStream
 *
 * Purpose:       Reset png stream
 *
 * Inputs:        eStream    stream to be decoded
 *
 * Outputs:       none
 *
 * Return Values: void
 *
 * Limitations:   none
 *
 ***************************************************************************/
void vPNG_ResetStream(png_stream_e eStream);

/****************************************************************************
 *
 * Function:      boPNG_GetBusError
 *
 * Purpose:       Get information about bus error for sliding window or
 *                source stream including bus error address.
 *
 * Inputs:        eErrType         Type of error to get its information
 *
 * Outputs:       pstBussError     Pointer to structue to get error information
 *
 * Return Values: C_TRUE/C_FALSE   OK/Error if parameteer wrong
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boPNG_GetBusError(png_bus_error_type_e eErrType, png_bus_error_st *pstBussError);

/****************************************************************************
 *
 * Function:      ePNG_GetStreamPhaseStatus
 *
 * Purpose:       Get information about stream phase status
 *
 * Inputs:        eStream       Stream to be decoded
 *
 * Outputs:       none
 *
 * Return Values: Stream phase status(IDLE/DECODE)
 *
 * Limitations:   none
 *
 ***************************************************************************/
png_phase_status_e ePNG_GetStreamPhaseStatus (png_stream_e eStream);

/****************************************************************************
 *
 * Function:      boPNG_GetStreamStatus
 *
 * Purpose:       Get information about stream status
 *
 * Inputs:        eStream       Stream to be decoded
 *
 * Outputs:       pstStreamStatus  Pointer to structue to get stream status
 *
 * Return Values: C_TRUE/C_FALSE   OK/Error if parameteer wrong
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boPNG_GetStreamStatus (png_stream_e eStream, png_stream_status_st *pstStreamStatus);

/****************************************************************************
 *
 * Function:      boPNG_GetStreamIhdrInfo
 *
 * Purpose:       Get information about stream IHDR
 *
 * Inputs:        eStream       Stream to be decoded
 *
 * Outputs:       pstStreamIhdrInfo  Pointer to structue to get stream IHDR information
 *
 * Return Values: C_TRUE/C_FALSE   OK/Error if parameteer wrong
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boPNG_GetStreamIhdrInfo (png_stream_e eStream, png_stream_ihdr_info_st *pstStreamIhdrInfo);

/****************************************************************************
 *
 * Function:      boPNG_GetStreamZlibInfo
 *
 * Purpose:       Get information about stream ZLIB information
 *
 * Inputs:        eStream       Stream to be decoded
 *
 * Outputs:       pstStreamZlibInfo  Pointer to structue to get stream ZLIB information
 *
 * Return Values: C_TRUE/C_FALSE   OK/Error if parameteer wrong
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boPNG_GetStreamZlibInfo (png_stream_e eStream, png_stream_zlib_info_st *pstStreamZlibInfo);

/****************************************************************************
 *
 * Function:      boPNG_GetImageSize
 *
 * Purpose:       Get width and height of image
 *
 * Inputs:        eStream       Stream to be decoded
 *
 * Outputs:       pu32Width   Pointer to width variable
 *                pu32Height  Pointer to height variable
 *
 * Return Values: C_TRUE/C_FALSE   OK/Error if parameteer wrong
 *
 * Limitations:   none
 *
 ***************************************************************************/
bool_t boPNG_GetImageSize(png_stream_e eStream, uint32_t *pu32Width, uint32_t *pu32Height);

/****************************************************************************
 *
 * Function:      u8PNG_GetDecodedStreamFIFOFillLevel
 *
 * Purpose:       Read current fill level of the FIFO for decoded stream
 *
 * Inputs:        eStream    stream to be decoded
 *
 * Outputs:       none
 *
 * Return Values: FIFO fill level
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint8_t u8PNG_GetDecodedStreamFIFOFillLevel(png_stream_e eStream);

/****************************************************************************
 *
 * Function:      u32PNG_GetSSBCurrentAddress
 *
 * Purpose:       Read SSB current address
 *
 * Inputs:        eStream    stream to be decoded
 *
 * Outputs:       none
 *
 * Return Values: SSB current address
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32PNG_GetSSBCurrentAddress(png_stream_e eStream);

/****************************************************************************
 *
 * Function:      u32PNG_GetSWBCurrentAddress
 *
 * Purpose:       Read SWB current address
 *
 * Inputs:        eStream    stream to be decoded
 *
 * Outputs:       none
 *
 * Return Values: SWB current address
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32PNG_GetSWBCurrentAddress(png_stream_e eStream);

/****************************************************************************
 *
 * Function:      u32PNG_GetFSBStartAddress
 *
 * Purpose:       Read FSB start address
 *
 * Inputs:        eStream    stream to be decoded
 *
 * Outputs:       none
 *
 * Return Values: FSB start address
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32PNG_GetFSBStartAddress(png_stream_e eStream);

/****************************************************************************
 *
 * Function:      u32PNG_GetCurrentVirtualOffset
 *
 * Purpose:       Read current virtual offset
 *
 * Inputs:        eStream    stream to be decoded
 *
 * Outputs:       none
 *
 * Return Values: current virtual offset
 *
 * Limitations:   none
 *
 ***************************************************************************/
uint32_t u32PNG_GetCurrentVirtualOffset(png_stream_e eStream);

/****************************************************************************
 *
 * Function:      i32PNG_SetPaletteTable
 *
 * Purpose:       Set palette table
 *
 * Inputs:        eStream             stream
 *                pu32PaletteTable    Pointer to palette table
 *
 * Outputs:       none
 *
 * Return Values: C_SUCCESS on success
 *                C_FAILED on ivalid parameter range
 *
 * Limitations:   none
 *
 ***************************************************************************/
int32_t i32PNG_SetPaletteTable(png_stream_e eStream, uint32_t * pu32PaletteTable);

/****************************************************************************/
/****************************************************************************/
#if defined(__GHS__) || defined(__ghs__)
  #pragma ghs endnowarning
#endif /* defined(__GHS__) || defined(__ghs__) */

#endif /* PNG_H */

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

