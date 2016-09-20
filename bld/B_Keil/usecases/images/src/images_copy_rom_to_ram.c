/*****************************************************************************
*   This software is copyright protected. All rights reserved 
*   Toshiba Electronics Europe GmbH 
*   European LSI Design and Engineering Center (ELDEC)
****************************************************************************** 
*   File Name   : $RCSfile: $ 
*   Description : Image file
****************************************************************************** 
*   PROJECT     : Capricorn 
*   MODULE      : Graphics 
*               : $Name: $ 
*   LIBRARIES   : None 
*   AUTHOR      : $Author: $
****************************************************************************** 
*   VERSION     : $Revision: $ 
*   RELEASE     : Preliminary & Confidential 
*   DATE        : $Date: $ 
*   SOURCE MOD. : $Source: $ 
*   LOG:        : please have a look at the end of the file
*****************************************************************************/
/************************************************************************
 * Generated using TEE Capricorn: Image to C Code Generator
 * Version 2.00
 * Toshiba Electronics Europe GmbH
 * This software is copyright protected. All rights reserved
 ************************************************************************
 * Converted on: 21.01.2016 @ 10:59
 ************************************************************************/
#include "images_defs.h"
#include "images_externs.h"
#include "copy_function.h"
#include "mw_definitions.h"
#include "captypes.h"
#include "core.h"
#include "gfunctions.h"
#include "listmngr.h"

void vGfCopyImagesROMtoRAM(void)
{
	gf_image_st stImageLocal;

/**
	A__Z
*/	
	asm_copyfunction((uint32_t)&u32_AA0_RLE[0], (uint32_t)&u32_AA0_RLE[AA0_SIZE - 1], (uint32_t)&u32_AA0_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA1_RLE[0], (uint32_t)&u32_AA1_RLE[AA1_SIZE - 1], (uint32_t)&u32_AA1_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA10_RLE[0], (uint32_t)&u32_AA10_RLE[AA10_SIZE - 1], (uint32_t)&u32_AA10_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA11_RLE[0], (uint32_t)&u32_AA11_RLE[AA11_SIZE - 1], (uint32_t)&u32_AA11_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA12_RLE[0], (uint32_t)&u32_AA12_RLE[AA12_SIZE - 1], (uint32_t)&u32_AA12_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA13_RLE[0], (uint32_t)&u32_AA13_RLE[AA13_SIZE - 1], (uint32_t)&u32_AA13_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA14_RLE[0], (uint32_t)&u32_AA14_RLE[AA14_SIZE - 1], (uint32_t)&u32_AA14_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA15_RLE[0], (uint32_t)&u32_AA15_RLE[AA15_SIZE - 1], (uint32_t)&u32_AA15_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA16_RLE[0], (uint32_t)&u32_AA16_RLE[AA16_SIZE - 1], (uint32_t)&u32_AA16_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA17_RLE[0], (uint32_t)&u32_AA17_RLE[AA17_SIZE - 1], (uint32_t)&u32_AA17_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA18_RLE[0], (uint32_t)&u32_AA18_RLE[AA18_SIZE - 1], (uint32_t)&u32_AA18_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA19_RLE[0], (uint32_t)&u32_AA19_RLE[AA19_SIZE - 1], (uint32_t)&u32_AA19_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA2_RLE[0], (uint32_t)&u32_AA2_RLE[AA2_SIZE - 1], (uint32_t)&u32_AA2_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA20_RLE[0], (uint32_t)&u32_AA20_RLE[AA20_SIZE - 1], (uint32_t)&u32_AA20_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA21_RLE[0], (uint32_t)&u32_AA21_RLE[AA21_SIZE - 1], (uint32_t)&u32_AA21_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA22_RLE[0], (uint32_t)&u32_AA22_RLE[AA22_SIZE - 1], (uint32_t)&u32_AA22_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA23_RLE[0], (uint32_t)&u32_AA23_RLE[AA23_SIZE - 1], (uint32_t)&u32_AA23_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA24_RLE[0], (uint32_t)&u32_AA24_RLE[AA24_SIZE - 1], (uint32_t)&u32_AA24_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA25_RLE[0], (uint32_t)&u32_AA25_RLE[AA25_SIZE - 1], (uint32_t)&u32_AA25_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA3_RLE[0], (uint32_t)&u32_AA3_RLE[AA3_SIZE - 1], (uint32_t)&u32_AA3_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA4_RLE[0], (uint32_t)&u32_AA4_RLE[AA4_SIZE - 1], (uint32_t)&u32_AA4_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA5_RLE[0], (uint32_t)&u32_AA5_RLE[AA5_SIZE - 1], (uint32_t)&u32_AA5_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA6_RLE[0], (uint32_t)&u32_AA6_RLE[AA6_SIZE - 1], (uint32_t)&u32_AA6_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA7_RLE[0], (uint32_t)&u32_AA7_RLE[AA7_SIZE - 1], (uint32_t)&u32_AA7_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA8_RLE[0], (uint32_t)&u32_AA8_RLE[AA8_SIZE - 1], (uint32_t)&u32_AA8_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_AA9_RLE[0], (uint32_t)&u32_AA9_RLE[AA9_SIZE - 1], (uint32_t)&u32_AA9_RLE_RAM[0]);
		
/***********************************************************END A__Z*******/	

/**
	a_z
*/	
	asm_copyfunction((uint32_t)&u32_a0_RLE[0], (uint32_t)&u32_a0_RLE[A0_SIZE - 1], (uint32_t)&u32_a0_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a1_RLE[0], (uint32_t)&u32_a1_RLE[A1_SIZE - 1], (uint32_t)&u32_a1_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a10_RLE[0], (uint32_t)&u32_a10_RLE[A10_SIZE - 1], (uint32_t)&u32_a10_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a11_RLE[0], (uint32_t)&u32_a11_RLE[A11_SIZE - 1], (uint32_t)&u32_a11_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a12_RLE[0], (uint32_t)&u32_a12_RLE[A12_SIZE - 1], (uint32_t)&u32_a12_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a13_RLE[0], (uint32_t)&u32_a13_RLE[A13_SIZE - 1], (uint32_t)&u32_a13_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a14_RLE[0], (uint32_t)&u32_a14_RLE[A14_SIZE - 1], (uint32_t)&u32_a14_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a15_RLE[0], (uint32_t)&u32_a15_RLE[A15_SIZE - 1], (uint32_t)&u32_a15_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a16_RLE[0], (uint32_t)&u32_a16_RLE[A16_SIZE - 1], (uint32_t)&u32_a16_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a17_RLE[0], (uint32_t)&u32_a17_RLE[A17_SIZE - 1], (uint32_t)&u32_a17_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a18_RLE[0], (uint32_t)&u32_a18_RLE[A18_SIZE - 1], (uint32_t)&u32_a18_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a19_RLE[0], (uint32_t)&u32_a19_RLE[A19_SIZE - 1], (uint32_t)&u32_a19_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a2_RLE[0], (uint32_t)&u32_a2_RLE[A2_SIZE - 1], (uint32_t)&u32_a2_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a20_RLE[0], (uint32_t)&u32_a20_RLE[A20_SIZE - 1], (uint32_t)&u32_a20_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a21_RLE[0], (uint32_t)&u32_a21_RLE[A21_SIZE - 1], (uint32_t)&u32_a21_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a22_RLE[0], (uint32_t)&u32_a22_RLE[A22_SIZE - 1], (uint32_t)&u32_a22_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a23_RLE[0], (uint32_t)&u32_a23_RLE[A23_SIZE - 1], (uint32_t)&u32_a23_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a24_RLE[0], (uint32_t)&u32_a24_RLE[A24_SIZE - 1], (uint32_t)&u32_a24_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a25_RLE[0], (uint32_t)&u32_a25_RLE[A25_SIZE - 1], (uint32_t)&u32_a25_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a3_RLE[0], (uint32_t)&u32_a3_RLE[A3_SIZE - 1], (uint32_t)&u32_a3_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a4_RLE[0], (uint32_t)&u32_a4_RLE[A4_SIZE - 1], (uint32_t)&u32_a4_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a5_RLE[0], (uint32_t)&u32_a5_RLE[A5_SIZE - 1], (uint32_t)&u32_a5_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a6_RLE[0], (uint32_t)&u32_a6_RLE[A6_SIZE - 1], (uint32_t)&u32_a6_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a7_RLE[0], (uint32_t)&u32_a7_RLE[A7_SIZE - 1], (uint32_t)&u32_a7_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a8_RLE[0], (uint32_t)&u32_a8_RLE[A8_SIZE - 1], (uint32_t)&u32_a8_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_a9_RLE[0], (uint32_t)&u32_a9_RLE[A9_SIZE - 1], (uint32_t)&u32_a9_RLE_RAM[0]);
	
	
/***********************************************************END a_z*******/

/**
	car_door
*/	
	
	asm_copyfunction((uint32_t)&u32_door_d1_RLE[0], (uint32_t)&u32_door_d1_RLE[DOOR_D1_SIZE - 1], (uint32_t)&u32_door_d1_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d10_RLE[0], (uint32_t)&u32_door_d10_RLE[DOOR_D10_SIZE - 1], (uint32_t)&u32_door_d10_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d11_RLE[0], (uint32_t)&u32_door_d11_RLE[DOOR_D11_SIZE - 1], (uint32_t)&u32_door_d11_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d12_RLE[0], (uint32_t)&u32_door_d12_RLE[DOOR_D12_SIZE - 1], (uint32_t)&u32_door_d12_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d13_RLE[0], (uint32_t)&u32_door_d13_RLE[DOOR_D13_SIZE - 1], (uint32_t)&u32_door_d13_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d14_RLE[0], (uint32_t)&u32_door_d14_RLE[DOOR_D14_SIZE - 1], (uint32_t)&u32_door_d14_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d15_RLE[0], (uint32_t)&u32_door_d15_RLE[DOOR_D15_SIZE - 1], (uint32_t)&u32_door_d15_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d2_RLE[0], (uint32_t)&u32_door_d2_RLE[DOOR_D2_SIZE - 1], (uint32_t)&u32_door_d2_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d3_RLE[0], (uint32_t)&u32_door_d3_RLE[DOOR_D3_SIZE - 1], (uint32_t)&u32_door_d3_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d4_RLE[0], (uint32_t)&u32_door_d4_RLE[DOOR_D4_SIZE - 1], (uint32_t)&u32_door_d4_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d5_RLE[0], (uint32_t)&u32_door_d5_RLE[DOOR_D5_SIZE - 1], (uint32_t)&u32_door_d5_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d6_RLE[0], (uint32_t)&u32_door_d6_RLE[DOOR_D6_SIZE - 1], (uint32_t)&u32_door_d6_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d7_RLE[0], (uint32_t)&u32_door_d7_RLE[DOOR_D7_SIZE - 1], (uint32_t)&u32_door_d7_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d8_RLE[0], (uint32_t)&u32_door_d8_RLE[DOOR_D8_SIZE - 1], (uint32_t)&u32_door_d8_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_door_d9_RLE[0], (uint32_t)&u32_door_d9_RLE[DOOR_D9_SIZE - 1], (uint32_t)&u32_door_d9_RLE_RAM[0]);
		
/***********************************************************END car_door*******/

/**
	disfont_14x
*/	

	asm_copyfunction((uint32_t)&u32_disfont0_RLE[0], (uint32_t)&u32_disfont0_RLE[DISFONT0_SIZE - 1], (uint32_t)&u32_disfont0_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont1_RLE[0], (uint32_t)&u32_disfont1_RLE[DISFONT1_SIZE - 1], (uint32_t)&u32_disfont1_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont10_RLE[0], (uint32_t)&u32_disfont10_RLE[DISFONT10_SIZE - 1], (uint32_t)&u32_disfont10_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont2_RLE[0], (uint32_t)&u32_disfont2_RLE[DISFONT2_SIZE - 1], (uint32_t)&u32_disfont2_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont3_RLE[0], (uint32_t)&u32_disfont3_RLE[DISFONT3_SIZE - 1], (uint32_t)&u32_disfont3_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont4_RLE[0], (uint32_t)&u32_disfont4_RLE[DISFONT4_SIZE - 1], (uint32_t)&u32_disfont4_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont5_RLE[0], (uint32_t)&u32_disfont5_RLE[DISFONT5_SIZE - 1], (uint32_t)&u32_disfont5_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont6_RLE[0], (uint32_t)&u32_disfont6_RLE[DISFONT6_SIZE - 1], (uint32_t)&u32_disfont6_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont7_RLE[0], (uint32_t)&u32_disfont7_RLE[DISFONT7_SIZE - 1], (uint32_t)&u32_disfont7_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont8_RLE[0], (uint32_t)&u32_disfont8_RLE[DISFONT8_SIZE - 1], (uint32_t)&u32_disfont8_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_disfont9_RLE[0], (uint32_t)&u32_disfont9_RLE[DISFONT9_SIZE - 1], (uint32_t)&u32_disfont9_RLE_RAM[0]);
	
/***********************************************************END disfont_14x*******/


/**
	err_word
*/	
	
	stImageLocal = stImage_ERR[1];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR1[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[1], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[10];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR10[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[10], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[11];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR11[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[11], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[12];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR12[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[12], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[13];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR13[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[13], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[14];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR14[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[14], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[15];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR15[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[15], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[16];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR16[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[16], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[17];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR17[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[17], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[18];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR18[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[18], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[19];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR19[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[19], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[2];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR2[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[2], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[3];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR3[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[3], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[4];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR4[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[4], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[5];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR5[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[5], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[6];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR6[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[6], 0, 0);
	vGfListExecute();	
	
	stImageLocal = stImage_ERR[7];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR7[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[7], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[8];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR8[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[8], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_ERR[9];
	stImageLocal.u32Address = PHYSICAL(&u32_ERR9[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_ERR[9], 0, 0);
	vGfListExecute();
	
/***********************************************************END err_word*******/


/**
	lamp
*/	
	
	stImageLocal = stImage_sspic0;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic0[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic0, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic1;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic1[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic1, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic10;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic10[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic10, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic11;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic11[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic11, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic12;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic12[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic12, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic13;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic13[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic13, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic14;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic14[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic14, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic15;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic15[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic15, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic16;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic16[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic16, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic17;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic17[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic17, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic18;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic18[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic18, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic19;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic19[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic19, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic2;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic2[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic2, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic20;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic20[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic20, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic21;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic21[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic21, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic22;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic22[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic22, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic23;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic23[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic23, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic24;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic24[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic24, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic25;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic25[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic25, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic26;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic26[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic26, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic3;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic3[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic3, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic4;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic4[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic4, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic5;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic5[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic5, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic6;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic6[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic6, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic7;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic7[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic7, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic8;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic8[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic8, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_sspic9;
	stImageLocal.u32Address = PHYSICAL(&u32_sspic9[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_sspic9, 0, 0);
	vGfListExecute();
	
		
/***********************************************************END lamp*******/


/**
	prnds
*/	
	
	stImageLocal = stImage_LEV[3];
	stImageLocal.u32Address = PHYSICAL(&u32_LEV_D[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_LEV[3], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_LEV[2];
	stImageLocal.u32Address = PHYSICAL(&u32_LEV_N[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_LEV[2], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_LEV[0];
	stImageLocal.u32Address = PHYSICAL(&u32_LEV_P[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_LEV[0], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_LEV[1];
	stImageLocal.u32Address = PHYSICAL(&u32_LEV_R[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_LEV[1], 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_LEV[4];
	stImageLocal.u32Address = PHYSICAL(&u32_LEV_S[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_LEV[4], 0, 0);
	vGfListExecute();
		
/***********************************************************END prnds*******/


/**
	speedfont
*/	

	asm_copyfunction((uint32_t)&u32_speedfont0_RLE[0], (uint32_t)&u32_speedfont0_RLE[SPEEDFONT0_SIZE - 1], (uint32_t)&u32_speedfont0_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont1_RLE[0], (uint32_t)&u32_speedfont1_RLE[SPEEDFONT1_SIZE - 1], (uint32_t)&u32_speedfont1_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont2_RLE[0], (uint32_t)&u32_speedfont2_RLE[SPEEDFONT2_SIZE - 1], (uint32_t)&u32_speedfont2_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont3_RLE[0], (uint32_t)&u32_speedfont3_RLE[SPEEDFONT3_SIZE - 1], (uint32_t)&u32_speedfont3_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont4_RLE[0], (uint32_t)&u32_speedfont4_RLE[SPEEDFONT4_SIZE - 1], (uint32_t)&u32_speedfont4_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont5_RLE[0], (uint32_t)&u32_speedfont5_RLE[SPEEDFONT5_SIZE - 1], (uint32_t)&u32_speedfont5_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont6_RLE[0], (uint32_t)&u32_speedfont6_RLE[SPEEDFONT6_SIZE - 1], (uint32_t)&u32_speedfont6_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont7_RLE[0], (uint32_t)&u32_speedfont7_RLE[SPEEDFONT7_SIZE - 1], (uint32_t)&u32_speedfont7_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont8_RLE[0], (uint32_t)&u32_speedfont8_RLE[SPEEDFONT8_SIZE - 1], (uint32_t)&u32_speedfont8_RLE_RAM[0]);
	
	asm_copyfunction((uint32_t)&u32_speedfont9_RLE[0], (uint32_t)&u32_speedfont9_RLE[SPEEDFONT9_SIZE - 1], (uint32_t)&u32_speedfont9_RLE_RAM[0]);
		
/***********************************************************END speedfont*******/
	


/**
	instrument
*/
	stImageLocal = stImage_dial_amp;
	stImageLocal.u32Address = PHYSICAL(&u32_dial_amp[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_dial_amp, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_dial_soc;
	stImageLocal.u32Address = PHYSICAL(&u32_dial_soc[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_dial_soc, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_dial_speed;
	stImageLocal.u32Address = PHYSICAL(&u32_dial_speed[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_dial_speed, 0, 0);
	vGfListExecute();
/***************************************************************************************END instrument**********/

/**
	needle
*/
	stImageLocal = stImage_needle_amp;
	stImageLocal.u32Address = PHYSICAL(&u32_needle_amp[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_needle_amp, 0, 0);
	vGfListExecute();
	
	stImageLocal = stImage_needle_speed;
	stImageLocal.u32Address = PHYSICAL(&u32_needle_speed[0]);
	vGfBuffBlitBitmapFull(&stImageLocal, &stImage_needle_speed, 0, 0);
	vGfListExecute();
/***************************************************************************************END needle**************/


	
	vGfListWaitToComplete();
}

/****************************************************************************/

/************************** BEGIN of DISCLAIMER   **************************

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
  ï¿½Handling Guide for Semiconductor Devices,ï¿?or 
  ï¿½TOSHIBA Semiconductor Reliability Handbookï¿?etc..

- The Toshiba products listed in this document are intended for usage in 
  general electronics applications (computer, personal equipment, office 
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.). 
  These Toshiba products are neither intended nor warranted for usage in 
  equipment that requires extraordinarily high quality and/or reliability or
  a malfunction or failure of which may cause loss of human life or bodily 
  injury (ï¿½Unintended Usageï¿?. Unintended Usage include atomic energy control
  instruments, airplane or spaceship instruments, transportation instruments, 
  traffic signal instruments, combustion control instruments, medical 
  instruments, all types of safety devices, etc.. 
  Unintended Usage of Toshiba products listed in this document shall be 
  made at the customerï¿½s own risk.

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

/********************************* BEGIN OF LOG ******************************
*
* $Log: $
*
*********************************** END OF LOG ******************************/
