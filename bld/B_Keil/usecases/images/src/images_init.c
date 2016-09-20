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
#include "mw_definitions.h"
#include "captypes.h"
#include "core.h"
#include "gf.h"

void vGfInitImages(void)
{

/**
	A__Z
*/	
	stImage_AA[0].u16Width = AA0_WIDTH;
	stImage_AA[0].u16Height = AA0_HEIGHT;
	stImage_AA[0].u32Address = PHYSICAL(&u32_AA0_RLE_RAM[0]);
	stImage_AA[0].i16CenterX = AA0_XCPOS;
	stImage_AA[0].i16CenterY = AA0_YCPOS;
	stImage_AA[0].eFormat = FMT_RLERGBA24;
	stImage_AA[0].u32Paletteaddress = 0;
	        
	stImage_AA[1].u16Width = AA1_WIDTH;
	stImage_AA[1].u16Height = AA1_HEIGHT;
	stImage_AA[1].u32Address = PHYSICAL(&u32_AA1_RLE_RAM[0]);
	stImage_AA[1].i16CenterX = AA1_XCPOS;
	stImage_AA[1].i16CenterY = AA1_YCPOS;
	stImage_AA[1].eFormat = FMT_RLERGBA24;
	stImage_AA[1].u32Paletteaddress = 0;
	       
	stImage_AA[10].u16Width = AA10_WIDTH;
	stImage_AA[10].u16Height = AA10_HEIGHT;
	stImage_AA[10].u32Address = PHYSICAL(&u32_AA10_RLE_RAM[0]);
	stImage_AA[10].i16CenterX = AA10_XCPOS;
	stImage_AA[10].i16CenterY = AA10_YCPOS;
	stImage_AA[10].eFormat = FMT_RLERGBA24;
	stImage_AA[10].u32Paletteaddress = 0;
	        
	stImage_AA[11].u16Width = AA11_WIDTH;
	stImage_AA[11].u16Height = AA11_HEIGHT;
	stImage_AA[11].u32Address = PHYSICAL(&u32_AA11_RLE_RAM[0]);
	stImage_AA[11].i16CenterX = AA11_XCPOS;
	stImage_AA[11].i16CenterY = AA11_YCPOS;
	stImage_AA[11].eFormat = FMT_RLERGBA24;
	stImage_AA[11].u32Paletteaddress = 0;
	      
	stImage_AA[12].u16Width = AA12_WIDTH;
	stImage_AA[12].u16Height = AA12_HEIGHT;
	stImage_AA[12].u32Address = PHYSICAL(&u32_AA12_RLE_RAM[0]);
	stImage_AA[12].i16CenterX = AA12_XCPOS;
	stImage_AA[12].i16CenterY = AA12_YCPOS;
	stImage_AA[12].eFormat = FMT_RLERGBA24;
	stImage_AA[12].u32Paletteaddress = 0;
	      
	stImage_AA[13].u16Width = AA13_WIDTH;
	stImage_AA[13].u16Height = AA13_HEIGHT;
	stImage_AA[13].u32Address = PHYSICAL(&u32_AA13_RLE_RAM[0]);
	stImage_AA[13].i16CenterX = AA13_XCPOS;
	stImage_AA[13].i16CenterY = AA13_YCPOS;
	stImage_AA[13].eFormat = FMT_RLERGBA24;
	stImage_AA[13].u32Paletteaddress = 0;
	     
	stImage_AA[14].u16Width = AA14_WIDTH;
	stImage_AA[14].u16Height = AA14_HEIGHT;
	stImage_AA[14].u32Address = PHYSICAL(&u32_AA14_RLE_RAM[0]);
	stImage_AA[14].i16CenterX = AA14_XCPOS;
	stImage_AA[14].i16CenterY = AA14_YCPOS;
	stImage_AA[14].eFormat = FMT_RLERGBA24;
	stImage_AA[14].u32Paletteaddress = 0;
	       
	stImage_AA[15].u16Width = AA15_WIDTH;
	stImage_AA[15].u16Height = AA15_HEIGHT;
	stImage_AA[15].u32Address = PHYSICAL(&u32_AA15_RLE_RAM[0]);
	stImage_AA[15].i16CenterX = AA15_XCPOS;
	stImage_AA[15].i16CenterY = AA15_YCPOS;
	stImage_AA[15].eFormat = FMT_RLERGBA24;
	stImage_AA[15].u32Paletteaddress = 0;
	       
	stImage_AA[16].u16Width = AA16_WIDTH;
	stImage_AA[16].u16Height = AA16_HEIGHT;
	stImage_AA[16].u32Address = PHYSICAL(&u32_AA16_RLE_RAM[0]);
	stImage_AA[16].i16CenterX = AA16_XCPOS;
	stImage_AA[16].i16CenterY = AA16_YCPOS;
	stImage_AA[16].eFormat = FMT_RLERGBA24;
	stImage_AA[16].u32Paletteaddress = 0;
	    
	stImage_AA[17].u16Width = AA17_WIDTH;
	stImage_AA[17].u16Height = AA17_HEIGHT;
	stImage_AA[17].u32Address = PHYSICAL(&u32_AA17_RLE_RAM[0]);
	stImage_AA[17].i16CenterX = AA17_XCPOS;
	stImage_AA[17].i16CenterY = AA17_YCPOS;
	stImage_AA[17].eFormat = FMT_RLERGBA24;
	stImage_AA[17].u32Paletteaddress = 0;
	        
	stImage_AA[18].u16Width = AA18_WIDTH;
	stImage_AA[18].u16Height = AA18_HEIGHT;
	stImage_AA[18].u32Address = PHYSICAL(&u32_AA18_RLE_RAM[0]);
	stImage_AA[18].i16CenterX = AA18_XCPOS;
	stImage_AA[18].i16CenterY = AA18_YCPOS;
	stImage_AA[18].eFormat = FMT_RLERGBA24;
	stImage_AA[18].u32Paletteaddress = 0;
	        
	stImage_AA[19].u16Width = AA19_WIDTH;
	stImage_AA[19].u16Height = AA19_HEIGHT;
	stImage_AA[19].u32Address = PHYSICAL(&u32_AA19_RLE_RAM[0]);
	stImage_AA[19].i16CenterX = AA19_XCPOS;
	stImage_AA[19].i16CenterY = AA19_YCPOS;
	stImage_AA[19].eFormat = FMT_RLERGBA24;
	stImage_AA[19].u32Paletteaddress = 0;
	     
	stImage_AA[2].u16Width = AA2_WIDTH;
	stImage_AA[2].u16Height = AA2_HEIGHT;
	stImage_AA[2].u32Address = PHYSICAL(&u32_AA2_RLE_RAM[0]);
	stImage_AA[2].i16CenterX = AA2_XCPOS;
	stImage_AA[2].i16CenterY = AA2_YCPOS;
	stImage_AA[2].eFormat = FMT_RLERGBA24;
	stImage_AA[2].u32Paletteaddress = 0;
	     
	stImage_AA[20].u16Width = AA20_WIDTH;
	stImage_AA[20].u16Height = AA20_HEIGHT;
	stImage_AA[20].u32Address = PHYSICAL(&u32_AA20_RLE_RAM[0]);
	stImage_AA[20].i16CenterX = AA20_XCPOS;
	stImage_AA[20].i16CenterY = AA20_YCPOS;
	stImage_AA[20].eFormat = FMT_RLERGBA24;
	stImage_AA[20].u32Paletteaddress = 0;
	      
	stImage_AA[21].u16Width = AA21_WIDTH;
	stImage_AA[21].u16Height = AA21_HEIGHT;
	stImage_AA[21].u32Address = PHYSICAL(&u32_AA21_RLE_RAM[0]);
	stImage_AA[21].i16CenterX = AA21_XCPOS;
	stImage_AA[21].i16CenterY = AA21_YCPOS;
	stImage_AA[21].eFormat = FMT_RLERGBA24;
	stImage_AA[21].u32Paletteaddress = 0;
	        
	stImage_AA[22].u16Width = AA22_WIDTH;
	stImage_AA[22].u16Height = AA22_HEIGHT;
	stImage_AA[22].u32Address = PHYSICAL(&u32_AA22_RLE_RAM[0]);
	stImage_AA[22].i16CenterX = AA22_XCPOS;
	stImage_AA[22].i16CenterY = AA22_YCPOS;
	stImage_AA[22].eFormat = FMT_RLERGBA24;
	stImage_AA[22].u32Paletteaddress = 0;
	      
	stImage_AA[23].u16Width = AA23_WIDTH;
	stImage_AA[23].u16Height = AA23_HEIGHT;
	stImage_AA[23].u32Address = PHYSICAL(&u32_AA23_RLE_RAM[0]);
	stImage_AA[23].i16CenterX = AA23_XCPOS;
	stImage_AA[23].i16CenterY = AA23_YCPOS;
	stImage_AA[23].eFormat = FMT_RLERGBA24;
	stImage_AA[23].u32Paletteaddress = 0;
	       
	stImage_AA[24].u16Width = AA24_WIDTH;
	stImage_AA[24].u16Height = AA24_HEIGHT;
	stImage_AA[24].u32Address = PHYSICAL(&u32_AA24_RLE_RAM[0]);
	stImage_AA[24].i16CenterX = AA24_XCPOS;
	stImage_AA[24].i16CenterY = AA24_YCPOS;
	stImage_AA[24].eFormat = FMT_RLERGBA24;
	stImage_AA[24].u32Paletteaddress = 0;
	   
	stImage_AA[25].u16Width = AA25_WIDTH;
	stImage_AA[25].u16Height = AA25_HEIGHT;
	stImage_AA[25].u32Address = PHYSICAL(&u32_AA25_RLE_RAM[0]);
	stImage_AA[25].i16CenterX = AA25_XCPOS;
	stImage_AA[25].i16CenterY = AA25_YCPOS;
	stImage_AA[25].eFormat = FMT_RLERGBA24;
	stImage_AA[25].u32Paletteaddress = 0;
	      
	stImage_AA[3].u16Width = AA3_WIDTH;
	stImage_AA[3].u16Height = AA3_HEIGHT;
	stImage_AA[3].u32Address = PHYSICAL(&u32_AA3_RLE_RAM[0]);
	stImage_AA[3].i16CenterX = AA3_XCPOS;
	stImage_AA[3].i16CenterY = AA3_YCPOS;
	stImage_AA[3].eFormat = FMT_RLERGBA24;
	stImage_AA[3].u32Paletteaddress = 0;
	       
	stImage_AA[4].u16Width = AA4_WIDTH;
	stImage_AA[4].u16Height = AA4_HEIGHT;
	stImage_AA[4].u32Address = PHYSICAL(&u32_AA4_RLE_RAM[0]);
	stImage_AA[4].i16CenterX = AA4_XCPOS;
	stImage_AA[4].i16CenterY = AA4_YCPOS;
	stImage_AA[4].eFormat = FMT_RLERGBA24;
	stImage_AA[4].u32Paletteaddress = 0;
	         
	stImage_AA[5].u16Width = AA5_WIDTH;
	stImage_AA[5].u16Height = AA5_HEIGHT;
	stImage_AA[5].u32Address = PHYSICAL(&u32_AA5_RLE_RAM[0]);
	stImage_AA[5].i16CenterX = AA5_XCPOS;
	stImage_AA[5].i16CenterY = AA5_YCPOS;
	stImage_AA[5].eFormat = FMT_RLERGBA24;
	stImage_AA[5].u32Paletteaddress = 0;
	      
	stImage_AA[6].u16Width = AA6_WIDTH;
	stImage_AA[6].u16Height = AA6_HEIGHT;
	stImage_AA[6].u32Address = PHYSICAL(&u32_AA6_RLE_RAM[0]);
	stImage_AA[6].i16CenterX = AA6_XCPOS;
	stImage_AA[6].i16CenterY = AA6_YCPOS;
	stImage_AA[6].eFormat = FMT_RLERGBA24;
	stImage_AA[6].u32Paletteaddress = 0;
	     
	stImage_AA[7].u16Width = AA7_WIDTH;
	stImage_AA[7].u16Height = AA7_HEIGHT;
	stImage_AA[7].u32Address = PHYSICAL(&u32_AA7_RLE_RAM[0]);
	stImage_AA[7].i16CenterX = AA7_XCPOS;
	stImage_AA[7].i16CenterY = AA7_YCPOS;
	stImage_AA[7].eFormat = FMT_RLERGBA24;
	stImage_AA[7].u32Paletteaddress = 0;
	      
	stImage_AA[8].u16Width = AA8_WIDTH;
	stImage_AA[8].u16Height = AA8_HEIGHT;
	stImage_AA[8].u32Address = PHYSICAL(&u32_AA8_RLE_RAM[0]);
	stImage_AA[8].i16CenterX = AA8_XCPOS;
	stImage_AA[8].i16CenterY = AA8_YCPOS;
	stImage_AA[8].eFormat = FMT_RLERGBA24;
	stImage_AA[8].u32Paletteaddress = 0;
	  
	stImage_AA[9].u16Width = AA9_WIDTH;
	stImage_AA[9].u16Height = AA9_HEIGHT;
	stImage_AA[9].u32Address = PHYSICAL(&u32_AA9_RLE_RAM[0]);
	stImage_AA[9].i16CenterX = AA9_XCPOS;
	stImage_AA[9].i16CenterY = AA9_YCPOS;
	stImage_AA[9].eFormat = FMT_RLERGBA24;
	stImage_AA[9].u32Paletteaddress = 0;
	
/***********************************************************END A__Z*******/	

/**
	a_z
*/	
	stImage_a[0].u16Width = A0_WIDTH;
	stImage_a[0].u16Height = A0_HEIGHT;
	stImage_a[0].u32Address = PHYSICAL(&u32_a0_RLE_RAM[0]);
	stImage_a[0].i16CenterX = A0_XCPOS;
	stImage_a[0].i16CenterY = A0_YCPOS;
	stImage_a[0].eFormat = FMT_RLERGBA24;
	stImage_a[0].u32Paletteaddress = 0;
	      
	stImage_a[1].u16Width = A1_WIDTH;
	stImage_a[1].u16Height = A1_HEIGHT;
	stImage_a[1].u32Address = PHYSICAL(&u32_a1_RLE_RAM[0]);
	stImage_a[1].i16CenterX = A1_XCPOS;
	stImage_a[1].i16CenterY = A1_YCPOS;
	stImage_a[1].eFormat = FMT_RLERGBA24;
	stImage_a[1].u32Paletteaddress = 0;
	        
	stImage_a[10].u16Width = A10_WIDTH;
	stImage_a[10].u16Height = A10_HEIGHT;
	stImage_a[10].u32Address = PHYSICAL(&u32_a10_RLE_RAM[0]);
	stImage_a[10].i16CenterX = A10_XCPOS;
	stImage_a[10].i16CenterY = A10_YCPOS;
	stImage_a[10].eFormat = FMT_RLERGBA24;
	stImage_a[10].u32Paletteaddress = 0;
	    
	stImage_a[11].u16Width = A11_WIDTH;
	stImage_a[11].u16Height = A11_HEIGHT;
	stImage_a[11].u32Address = PHYSICAL(&u32_a11_RLE_RAM[0]);
	stImage_a[11].i16CenterX = A11_XCPOS;
	stImage_a[11].i16CenterY = A11_YCPOS;
	stImage_a[11].eFormat = FMT_RLERGBA24;
	stImage_a[11].u32Paletteaddress = 0;
	        
	stImage_a[12].u16Width = A12_WIDTH;
	stImage_a[12].u16Height = A12_HEIGHT;
	stImage_a[12].u32Address = PHYSICAL(&u32_a12_RLE_RAM[0]);
	stImage_a[12].i16CenterX = A12_XCPOS;
	stImage_a[12].i16CenterY = A12_YCPOS;
	stImage_a[12].eFormat = FMT_RLERGBA24;
	stImage_a[12].u32Paletteaddress = 0;
	       
	stImage_a[13].u16Width = A13_WIDTH;
	stImage_a[13].u16Height = A13_HEIGHT;
	stImage_a[13].u32Address = PHYSICAL(&u32_a13_RLE_RAM[0]);
	stImage_a[13].i16CenterX = A13_XCPOS;
	stImage_a[13].i16CenterY = A13_YCPOS;
	stImage_a[13].eFormat = FMT_RLERGBA24;
	stImage_a[13].u32Paletteaddress = 0;
	      
	stImage_a[14].u16Width = A14_WIDTH;
	stImage_a[14].u16Height = A14_HEIGHT;
	stImage_a[14].u32Address = PHYSICAL(&u32_a14_RLE_RAM[0]);
	stImage_a[14].i16CenterX = A14_XCPOS;
	stImage_a[14].i16CenterY = A14_YCPOS;
	stImage_a[14].eFormat = FMT_RLERGBA24;
	stImage_a[14].u32Paletteaddress = 0;
	      
	stImage_a[15].u16Width = A15_WIDTH;
	stImage_a[15].u16Height = A15_HEIGHT;
	stImage_a[15].u32Address = PHYSICAL(&u32_a15_RLE_RAM[0]);
	stImage_a[15].i16CenterX = A15_XCPOS;
	stImage_a[15].i16CenterY = A15_YCPOS;
	stImage_a[15].eFormat = FMT_RLERGBA24;
	stImage_a[15].u32Paletteaddress = 0;
	      
	stImage_a[16].u16Width = A16_WIDTH;
	stImage_a[16].u16Height = A16_HEIGHT;
	stImage_a[16].u32Address = PHYSICAL(&u32_a16_RLE_RAM[0]);
	stImage_a[16].i16CenterX = A16_XCPOS;
	stImage_a[16].i16CenterY = A16_YCPOS;
	stImage_a[16].eFormat = FMT_RLERGBA24;
	stImage_a[16].u32Paletteaddress = 0;
	 
	stImage_a[17].u16Width = A17_WIDTH;
	stImage_a[17].u16Height = A17_HEIGHT;
	stImage_a[17].u32Address = PHYSICAL(&u32_a17_RLE_RAM[0]);
	stImage_a[17].i16CenterX = A17_XCPOS;
	stImage_a[17].i16CenterY = A17_YCPOS;
	stImage_a[17].eFormat = FMT_RLERGBA24;
	stImage_a[17].u32Paletteaddress = 0;
	      
	stImage_a[18].u16Width = A18_WIDTH;
	stImage_a[18].u16Height = A18_HEIGHT;
	stImage_a[18].u32Address = PHYSICAL(&u32_a18_RLE_RAM[0]);
	stImage_a[18].i16CenterX = A18_XCPOS;
	stImage_a[18].i16CenterY = A18_YCPOS;
	stImage_a[18].eFormat = FMT_RLERGBA24;
	stImage_a[18].u32Paletteaddress = 0;
	     
	stImage_a[19].u16Width = A19_WIDTH;
	stImage_a[19].u16Height = A19_HEIGHT;
	stImage_a[19].u32Address = PHYSICAL(&u32_a19_RLE_RAM[0]);
	stImage_a[19].i16CenterX = A19_XCPOS;
	stImage_a[19].i16CenterY = A19_YCPOS;
	stImage_a[19].eFormat = FMT_RLERGBA24;
	stImage_a[19].u32Paletteaddress = 0;
	      
	stImage_a[2].u16Width = A2_WIDTH;
	stImage_a[2].u16Height = A2_HEIGHT;
	stImage_a[2].u32Address = PHYSICAL(&u32_a2_RLE_RAM[0]);
	stImage_a[2].i16CenterX = A2_XCPOS;
	stImage_a[2].i16CenterY = A2_YCPOS;
	stImage_a[2].eFormat = FMT_RLERGBA24;
	stImage_a[2].u32Paletteaddress = 0;
	       
	stImage_a[20].u16Width = A20_WIDTH;
	stImage_a[20].u16Height = A20_HEIGHT;
	stImage_a[20].u32Address = PHYSICAL(&u32_a20_RLE_RAM[0]);
	stImage_a[20].i16CenterX = A20_XCPOS;
	stImage_a[20].i16CenterY = A20_YCPOS;
	stImage_a[20].eFormat = FMT_RLERGBA24;
	stImage_a[20].u32Paletteaddress = 0;
	    
	stImage_a[21].u16Width = A21_WIDTH;
	stImage_a[21].u16Height = A21_HEIGHT;
	stImage_a[21].u32Address = PHYSICAL(&u32_a21_RLE_RAM[0]);
	stImage_a[21].i16CenterX = A21_XCPOS;
	stImage_a[21].i16CenterY = A21_YCPOS;
	stImage_a[21].eFormat = FMT_RLERGBA24;
	stImage_a[21].u32Paletteaddress = 0;
	     
	stImage_a[22].u16Width = A22_WIDTH;
	stImage_a[22].u16Height = A22_HEIGHT;
	stImage_a[22].u32Address = PHYSICAL(&u32_a22_RLE_RAM[0]);
	stImage_a[22].i16CenterX = A22_XCPOS;
	stImage_a[22].i16CenterY = A22_YCPOS;
	stImage_a[22].eFormat = FMT_RLERGBA24;
	stImage_a[22].u32Paletteaddress = 0;
	    
	stImage_a[23].u16Width = A23_WIDTH;
	stImage_a[23].u16Height = A23_HEIGHT;
	stImage_a[23].u32Address = PHYSICAL(&u32_a23_RLE_RAM[0]);
	stImage_a[23].i16CenterX = A23_XCPOS;
	stImage_a[23].i16CenterY = A23_YCPOS;
	stImage_a[23].eFormat = FMT_RLERGBA24;
	stImage_a[23].u32Paletteaddress = 0;
	      
	stImage_a[24].u16Width = A24_WIDTH;
	stImage_a[24].u16Height = A24_HEIGHT;
	stImage_a[24].u32Address = PHYSICAL(&u32_a24_RLE_RAM[0]);
	stImage_a[24].i16CenterX = A24_XCPOS;
	stImage_a[24].i16CenterY = A24_YCPOS;
	stImage_a[24].eFormat = FMT_RLERGBA24;
	stImage_a[24].u32Paletteaddress = 0;
	    
	stImage_a[25].u16Width = A25_WIDTH;
	stImage_a[25].u16Height = A25_HEIGHT;
	stImage_a[25].u32Address = PHYSICAL(&u32_a25_RLE_RAM[0]);
	stImage_a[25].i16CenterX = A25_XCPOS;
	stImage_a[25].i16CenterY = A25_YCPOS;
	stImage_a[25].eFormat = FMT_RLERGBA24;
	stImage_a[25].u32Paletteaddress = 0;
	     
	stImage_a[3].u16Width = A3_WIDTH;
	stImage_a[3].u16Height = A3_HEIGHT;
	stImage_a[3].u32Address = PHYSICAL(&u32_a3_RLE_RAM[0]);
	stImage_a[3].i16CenterX = A3_XCPOS;
	stImage_a[3].i16CenterY = A3_YCPOS;
	stImage_a[3].eFormat = FMT_RLERGBA24;
	stImage_a[3].u32Paletteaddress = 0;
	     
	stImage_a[4].u16Width = A4_WIDTH;
	stImage_a[4].u16Height = A4_HEIGHT;
	stImage_a[4].u32Address = PHYSICAL(&u32_a4_RLE_RAM[0]);
	stImage_a[4].i16CenterX = A4_XCPOS;
	stImage_a[4].i16CenterY = A4_YCPOS;
	stImage_a[4].eFormat = FMT_RLERGBA24;
	stImage_a[4].u32Paletteaddress = 0;
	   
	stImage_a[5].u16Width = A5_WIDTH;
	stImage_a[5].u16Height = A5_HEIGHT;
	stImage_a[5].u32Address = PHYSICAL(&u32_a5_RLE_RAM[0]);
	stImage_a[5].i16CenterX = A5_XCPOS;
	stImage_a[5].i16CenterY = A5_YCPOS;
	stImage_a[5].eFormat = FMT_RLERGBA24;
	stImage_a[5].u32Paletteaddress = 0;
	   
	stImage_a[6].u16Width = A6_WIDTH;
	stImage_a[6].u16Height = A6_HEIGHT;
	stImage_a[6].u32Address = PHYSICAL(&u32_a6_RLE_RAM[0]);
	stImage_a[6].i16CenterX = A6_XCPOS;
	stImage_a[6].i16CenterY = A6_YCPOS;
	stImage_a[6].eFormat = FMT_RLERGBA24;
	stImage_a[6].u32Paletteaddress = 0;
	    
	stImage_a[7].u16Width = A7_WIDTH;
	stImage_a[7].u16Height = A7_HEIGHT;
	stImage_a[7].u32Address = PHYSICAL(&u32_a7_RLE_RAM[0]);
	stImage_a[7].i16CenterX = A7_XCPOS;
	stImage_a[7].i16CenterY = A7_YCPOS;
	stImage_a[7].eFormat = FMT_RLERGBA24;
	stImage_a[7].u32Paletteaddress = 0;
	   
	stImage_a[8].u16Width = A8_WIDTH;
	stImage_a[8].u16Height = A8_HEIGHT;
	stImage_a[8].u32Address = PHYSICAL(&u32_a8_RLE_RAM[0]);
	stImage_a[8].i16CenterX = A8_XCPOS;
	stImage_a[8].i16CenterY = A8_YCPOS;
	stImage_a[8].eFormat = FMT_RLERGBA24;
	stImage_a[8].u32Paletteaddress = 0;
	    
	stImage_a[9].u16Width = A9_WIDTH;
	stImage_a[9].u16Height = A9_HEIGHT;
	stImage_a[9].u32Address = PHYSICAL(&u32_a9_RLE_RAM[0]);
	stImage_a[9].i16CenterX = A9_XCPOS;
	stImage_a[9].i16CenterY = A9_YCPOS;
	stImage_a[9].eFormat = FMT_RLERGBA24;
	stImage_a[9].u32Paletteaddress = 0;
	
/***********************************************************END a_z*******/

/**
	car_door
*/	

	stImage_door_d[1].u16Width = DOOR_D1_WIDTH;
	stImage_door_d[1].u16Height = DOOR_D1_HEIGHT;
	stImage_door_d[1].u32Address = PHYSICAL(&u32_door_d1_RLE_RAM[0]);
	stImage_door_d[1].i16CenterX = DOOR_D1_XCPOS;
	stImage_door_d[1].i16CenterY = DOOR_D1_YCPOS;
	stImage_door_d[1].eFormat = FMT_RLERGBA24;
	stImage_door_d[1].u32Paletteaddress = 0;
	         
	stImage_door_d[10].u16Width = DOOR_D10_WIDTH;
	stImage_door_d[10].u16Height = DOOR_D10_HEIGHT;
	stImage_door_d[10].u32Address = PHYSICAL(&u32_door_d10_RLE_RAM[0]);
	stImage_door_d[10].i16CenterX = DOOR_D10_XCPOS;
	stImage_door_d[10].i16CenterY = DOOR_D10_YCPOS;
	stImage_door_d[10].eFormat = FMT_RLERGBA24;
	stImage_door_d[10].u32Paletteaddress = 0;
	       
	stImage_door_d[11].u16Width = DOOR_D11_WIDTH;
	stImage_door_d[11].u16Height = DOOR_D11_HEIGHT;
	stImage_door_d[11].u32Address = PHYSICAL(&u32_door_d11_RLE_RAM[0]);
	stImage_door_d[11].i16CenterX = DOOR_D11_XCPOS;
	stImage_door_d[11].i16CenterY = DOOR_D11_YCPOS;
	stImage_door_d[11].eFormat = FMT_RLERGBA24;
	stImage_door_d[11].u32Paletteaddress = 0;
	           
	stImage_door_d[12].u16Width = DOOR_D12_WIDTH;
	stImage_door_d[12].u16Height = DOOR_D12_HEIGHT;
	stImage_door_d[12].u32Address = PHYSICAL(&u32_door_d12_RLE_RAM[0]);
	stImage_door_d[12].i16CenterX = DOOR_D12_XCPOS;
	stImage_door_d[12].i16CenterY = DOOR_D12_YCPOS;
	stImage_door_d[12].eFormat = FMT_RLERGBA24;
	stImage_door_d[12].u32Paletteaddress = 0;
	           
	stImage_door_d[13].u16Width = DOOR_D13_WIDTH;
	stImage_door_d[13].u16Height = DOOR_D13_HEIGHT;
	stImage_door_d[13].u32Address = PHYSICAL(&u32_door_d13_RLE_RAM[0]);
	stImage_door_d[13].i16CenterX = DOOR_D13_XCPOS;
	stImage_door_d[13].i16CenterY = DOOR_D13_YCPOS;
	stImage_door_d[13].eFormat = FMT_RLERGBA24;
	stImage_door_d[13].u32Paletteaddress = 0;
	              
	stImage_door_d[14].u16Width = DOOR_D14_WIDTH;
	stImage_door_d[14].u16Height = DOOR_D14_HEIGHT;
	stImage_door_d[14].u32Address = PHYSICAL(&u32_door_d14_RLE_RAM[0]);
	stImage_door_d[14].i16CenterX = DOOR_D14_XCPOS;
	stImage_door_d[14].i16CenterY = DOOR_D14_YCPOS;
	stImage_door_d[14].eFormat = FMT_RLERGBA24;
	stImage_door_d[14].u32Paletteaddress = 0;
	           
	stImage_door_d[15].u16Width = DOOR_D15_WIDTH;
	stImage_door_d[15].u16Height = DOOR_D15_HEIGHT;
	stImage_door_d[15].u32Address = PHYSICAL(&u32_door_d15_RLE_RAM[0]);
	stImage_door_d[15].i16CenterX = DOOR_D15_XCPOS;
	stImage_door_d[15].i16CenterY = DOOR_D15_YCPOS;
	stImage_door_d[15].eFormat = FMT_RLERGBA24;
	stImage_door_d[15].u32Paletteaddress = 0;
	             
	stImage_door_d[2].u16Width = DOOR_D2_WIDTH;
	stImage_door_d[2].u16Height = DOOR_D2_HEIGHT;
	stImage_door_d[2].u32Address = PHYSICAL(&u32_door_d2_RLE_RAM[0]);
	stImage_door_d[2].i16CenterX = DOOR_D2_XCPOS;
	stImage_door_d[2].i16CenterY = DOOR_D2_YCPOS;
	stImage_door_d[2].eFormat = FMT_RLERGBA24;
	stImage_door_d[2].u32Paletteaddress = 0;
	          
	stImage_door_d[3].u16Width = DOOR_D3_WIDTH;
	stImage_door_d[3].u16Height = DOOR_D3_HEIGHT;
	stImage_door_d[3].u32Address = PHYSICAL(&u32_door_d3_RLE_RAM[0]);
	stImage_door_d[3].i16CenterX = DOOR_D3_XCPOS;
	stImage_door_d[3].i16CenterY = DOOR_D3_YCPOS;
	stImage_door_d[3].eFormat = FMT_RLERGBA24;
	stImage_door_d[3].u32Paletteaddress = 0;
	         
	stImage_door_d[4].u16Width = DOOR_D4_WIDTH;
	stImage_door_d[4].u16Height = DOOR_D4_HEIGHT;
	stImage_door_d[4].u32Address = PHYSICAL(&u32_door_d4_RLE_RAM[0]);
	stImage_door_d[4].i16CenterX = DOOR_D4_XCPOS;
	stImage_door_d[4].i16CenterY = DOOR_D4_YCPOS;
	stImage_door_d[4].eFormat = FMT_RLERGBA24;
	stImage_door_d[4].u32Paletteaddress = 0;
	           
	stImage_door_d[5].u16Width = DOOR_D5_WIDTH;
	stImage_door_d[5].u16Height = DOOR_D5_HEIGHT;
	stImage_door_d[5].u32Address = PHYSICAL(&u32_door_d5_RLE_RAM[0]);
	stImage_door_d[5].i16CenterX = DOOR_D5_XCPOS;
	stImage_door_d[5].i16CenterY = DOOR_D5_YCPOS;
	stImage_door_d[5].eFormat = FMT_RLERGBA24;
	stImage_door_d[5].u32Paletteaddress = 0;
	       
	stImage_door_d[6].u16Width = DOOR_D6_WIDTH;
	stImage_door_d[6].u16Height = DOOR_D6_HEIGHT;
	stImage_door_d[6].u32Address = PHYSICAL(&u32_door_d6_RLE_RAM[0]);
	stImage_door_d[6].i16CenterX = DOOR_D6_XCPOS;
	stImage_door_d[6].i16CenterY = DOOR_D6_YCPOS;
	stImage_door_d[6].eFormat = FMT_RLERGBA24;
	stImage_door_d[6].u32Paletteaddress = 0;
	           
	stImage_door_d[7].u16Width = DOOR_D7_WIDTH;
	stImage_door_d[7].u16Height = DOOR_D7_HEIGHT;
	stImage_door_d[7].u32Address = PHYSICAL(&u32_door_d7_RLE_RAM[0]);
	stImage_door_d[7].i16CenterX = DOOR_D7_XCPOS;
	stImage_door_d[7].i16CenterY = DOOR_D7_YCPOS;
	stImage_door_d[7].eFormat = FMT_RLERGBA24;
	stImage_door_d[7].u32Paletteaddress = 0;
	           
	stImage_door_d[8].u16Width = DOOR_D8_WIDTH;
	stImage_door_d[8].u16Height = DOOR_D8_HEIGHT;
	stImage_door_d[8].u32Address = PHYSICAL(&u32_door_d8_RLE_RAM[0]);
	stImage_door_d[8].i16CenterX = DOOR_D8_XCPOS;
	stImage_door_d[8].i16CenterY = DOOR_D8_YCPOS;
	stImage_door_d[8].eFormat = FMT_RLERGBA24;
	stImage_door_d[8].u32Paletteaddress = 0;
	            
	stImage_door_d[9].u16Width = DOOR_D9_WIDTH;
	stImage_door_d[9].u16Height = DOOR_D9_HEIGHT;
	stImage_door_d[9].u32Address = PHYSICAL(&u32_door_d9_RLE_RAM[0]);
	stImage_door_d[9].i16CenterX = DOOR_D9_XCPOS;
	stImage_door_d[9].i16CenterY = DOOR_D9_YCPOS;
	stImage_door_d[9].eFormat = FMT_RLERGBA24;
	stImage_door_d[9].u32Paletteaddress = 0;
	
/***********************************************************END car_door*******/

/**
	disfont_14x
*/	
	stImage_disfont[0].u16Width = DISFONT0_WIDTH;
	stImage_disfont[0].u16Height = DISFONT0_HEIGHT;
	stImage_disfont[0].u32Address = PHYSICAL(&u32_disfont0_RLE_RAM[0]);
	stImage_disfont[0].i16CenterX = DISFONT0_XCPOS;
	stImage_disfont[0].i16CenterY = DISFONT0_YCPOS;
	stImage_disfont[0].eFormat = FMT_RLERGBA24;
	stImage_disfont[0].u32Paletteaddress = 0;
	          
	stImage_disfont[1].u16Width = DISFONT1_WIDTH;
	stImage_disfont[1].u16Height = DISFONT1_HEIGHT;
	stImage_disfont[1].u32Address = PHYSICAL(&u32_disfont1_RLE_RAM[0]);
	stImage_disfont[1].i16CenterX = DISFONT1_XCPOS;
	stImage_disfont[1].i16CenterY = DISFONT1_YCPOS;
	stImage_disfont[1].eFormat = FMT_RLERGBA24;
	stImage_disfont[1].u32Paletteaddress = 0;
	           
	stImage_disfont[10].u16Width = DISFONT10_WIDTH;
	stImage_disfont[10].u16Height = DISFONT10_HEIGHT;
	stImage_disfont[10].u32Address = PHYSICAL(&u32_disfont10_RLE_RAM[0]);
	stImage_disfont[10].i16CenterX = DISFONT10_XCPOS;
	stImage_disfont[10].i16CenterY = DISFONT10_YCPOS;
	stImage_disfont[10].eFormat = FMT_RLERGBA24;
	stImage_disfont[10].u32Paletteaddress = 0;
	           
	stImage_disfont[2].u16Width = DISFONT2_WIDTH;
	stImage_disfont[2].u16Height = DISFONT2_HEIGHT;
	stImage_disfont[2].u32Address = PHYSICAL(&u32_disfont2_RLE_RAM[0]);
	stImage_disfont[2].i16CenterX = DISFONT2_XCPOS;
	stImage_disfont[2].i16CenterY = DISFONT2_YCPOS;
	stImage_disfont[2].eFormat = FMT_RLERGBA24;
	stImage_disfont[2].u32Paletteaddress = 0;
	        
	stImage_disfont[3].u16Width = DISFONT3_WIDTH;
	stImage_disfont[3].u16Height = DISFONT3_HEIGHT;
	stImage_disfont[3].u32Address = PHYSICAL(&u32_disfont3_RLE_RAM[0]);
	stImage_disfont[3].i16CenterX = DISFONT3_XCPOS;
	stImage_disfont[3].i16CenterY = DISFONT3_YCPOS;
	stImage_disfont[3].eFormat = FMT_RLERGBA24;
	stImage_disfont[3].u32Paletteaddress = 0;
	            
	stImage_disfont[4].u16Width = DISFONT4_WIDTH;
	stImage_disfont[4].u16Height = DISFONT4_HEIGHT;
	stImage_disfont[4].u32Address = PHYSICAL(&u32_disfont4_RLE_RAM[0]);
	stImage_disfont[4].i16CenterX = DISFONT4_XCPOS;
	stImage_disfont[4].i16CenterY = DISFONT4_YCPOS;
	stImage_disfont[4].eFormat = FMT_RLERGBA24;
	stImage_disfont[4].u32Paletteaddress = 0;
	            
	stImage_disfont[5].u16Width = DISFONT5_WIDTH;
	stImage_disfont[5].u16Height = DISFONT5_HEIGHT;
	stImage_disfont[5].u32Address = PHYSICAL(&u32_disfont5_RLE_RAM[0]);
	stImage_disfont[5].i16CenterX = DISFONT5_XCPOS;
	stImage_disfont[5].i16CenterY = DISFONT5_YCPOS;
	stImage_disfont[5].eFormat = FMT_RLERGBA24;
	stImage_disfont[5].u32Paletteaddress = 0;
	           
	stImage_disfont[6].u16Width = DISFONT6_WIDTH;
	stImage_disfont[6].u16Height = DISFONT6_HEIGHT;
	stImage_disfont[6].u32Address = PHYSICAL(&u32_disfont6_RLE_RAM[0]);
	stImage_disfont[6].i16CenterX = DISFONT6_XCPOS;
	stImage_disfont[6].i16CenterY = DISFONT6_YCPOS;
	stImage_disfont[6].eFormat = FMT_RLERGBA24;
	stImage_disfont[6].u32Paletteaddress = 0;
	            
	stImage_disfont[7].u16Width = DISFONT7_WIDTH;
	stImage_disfont[7].u16Height = DISFONT7_HEIGHT;
	stImage_disfont[7].u32Address = PHYSICAL(&u32_disfont7_RLE_RAM[0]);
	stImage_disfont[7].i16CenterX = DISFONT7_XCPOS;
	stImage_disfont[7].i16CenterY = DISFONT7_YCPOS;
	stImage_disfont[7].eFormat = FMT_RLERGBA24;
	stImage_disfont[7].u32Paletteaddress = 0;
	             
	stImage_disfont[8].u16Width = DISFONT8_WIDTH;
	stImage_disfont[8].u16Height = DISFONT8_HEIGHT;
	stImage_disfont[8].u32Address = PHYSICAL(&u32_disfont8_RLE_RAM[0]);
	stImage_disfont[8].i16CenterX = DISFONT8_XCPOS;
	stImage_disfont[8].i16CenterY = DISFONT8_YCPOS;
	stImage_disfont[8].eFormat = FMT_RLERGBA24;
	stImage_disfont[8].u32Paletteaddress = 0;
	             
	stImage_disfont[9].u16Width = DISFONT9_WIDTH;
	stImage_disfont[9].u16Height = DISFONT9_HEIGHT;
	stImage_disfont[9].u32Address = PHYSICAL(&u32_disfont9_RLE_RAM[0]);
	stImage_disfont[9].i16CenterX = DISFONT9_XCPOS;
	stImage_disfont[9].i16CenterY = DISFONT9_YCPOS;
	stImage_disfont[9].eFormat = FMT_RLERGBA24;
	stImage_disfont[9].u32Paletteaddress = 0;
	
/***********************************************************END disfont_14x*******/


/**
	err_word
*/	
	
	stImage_ERR[1].u16Width = ERR1_WIDTH;
	stImage_ERR[1].u16Height = ERR1_HEIGHT;
	stImage_ERR[1].u32Address = PHYSICAL(&u32_ERR1_RAM[0]);
	stImage_ERR[1].i16CenterX = ERR1_XCPOS;
	stImage_ERR[1].i16CenterY = ERR1_YCPOS;
	stImage_ERR[1].eFormat = FMT_RGBA32;
	stImage_ERR[1].u32Paletteaddress = 0;
	
	stImage_ERR[10].u16Width = ERR10_WIDTH;
	stImage_ERR[10].u16Height = ERR10_HEIGHT;
	stImage_ERR[10].u32Address = PHYSICAL(&u32_ERR10_RAM[0]);
	stImage_ERR[10].i16CenterX = ERR10_XCPOS;
	stImage_ERR[10].i16CenterY = ERR10_YCPOS;
	stImage_ERR[10].eFormat = FMT_RGBA32;
	stImage_ERR[10].u32Paletteaddress = 0;
	
	stImage_ERR[11].u16Width = ERR11_WIDTH;
	stImage_ERR[11].u16Height = ERR11_HEIGHT;
	stImage_ERR[11].u32Address = PHYSICAL(&u32_ERR11_RAM[0]);
	stImage_ERR[11].i16CenterX = ERR11_XCPOS;
	stImage_ERR[11].i16CenterY = ERR11_YCPOS;
	stImage_ERR[11].eFormat = FMT_RGBA32;
	stImage_ERR[11].u32Paletteaddress = 0;
	
	stImage_ERR[12].u16Width = ERR12_WIDTH;
	stImage_ERR[12].u16Height = ERR12_HEIGHT;
	stImage_ERR[12].u32Address = PHYSICAL(&u32_ERR12_RAM[0]);
	stImage_ERR[12].i16CenterX = ERR12_XCPOS;
	stImage_ERR[12].i16CenterY = ERR12_YCPOS;
	stImage_ERR[12].eFormat = FMT_RGBA32;
	stImage_ERR[12].u32Paletteaddress = 0;
	
	stImage_ERR[13].u16Width = ERR13_WIDTH;
	stImage_ERR[13].u16Height = ERR13_HEIGHT;
	stImage_ERR[13].u32Address = PHYSICAL(&u32_ERR13_RAM[0]);
	stImage_ERR[13].i16CenterX = ERR13_XCPOS;
	stImage_ERR[13].i16CenterY = ERR13_YCPOS;
	stImage_ERR[13].eFormat = FMT_RGBA32;
	stImage_ERR[13].u32Paletteaddress = 0;
	
	stImage_ERR[14].u16Width = ERR14_WIDTH;
	stImage_ERR[14].u16Height = ERR14_HEIGHT;
	stImage_ERR[14].u32Address = PHYSICAL(&u32_ERR14_RAM[0]);
	stImage_ERR[14].i16CenterX = ERR14_XCPOS;
	stImage_ERR[14].i16CenterY = ERR14_YCPOS;
	stImage_ERR[14].eFormat = FMT_RGBA32;
	stImage_ERR[14].u32Paletteaddress = 0;
	
	stImage_ERR[15].u16Width = ERR15_WIDTH;
	stImage_ERR[15].u16Height = ERR15_HEIGHT;
	stImage_ERR[15].u32Address = PHYSICAL(&u32_ERR15_RAM[0]);
	stImage_ERR[15].i16CenterX = ERR15_XCPOS;
	stImage_ERR[15].i16CenterY = ERR15_YCPOS;
	stImage_ERR[15].eFormat = FMT_RGBA32;
	stImage_ERR[15].u32Paletteaddress = 0;
	
	stImage_ERR[16].u16Width = ERR16_WIDTH;
	stImage_ERR[16].u16Height = ERR16_HEIGHT;
	stImage_ERR[16].u32Address = PHYSICAL(&u32_ERR16_RAM[0]);
	stImage_ERR[16].i16CenterX = ERR16_XCPOS;
	stImage_ERR[16].i16CenterY = ERR16_YCPOS;
	stImage_ERR[16].eFormat = FMT_RGBA32;
	stImage_ERR[16].u32Paletteaddress = 0;
	
	stImage_ERR[17].u16Width = ERR17_WIDTH;
	stImage_ERR[17].u16Height = ERR17_HEIGHT;
	stImage_ERR[17].u32Address = PHYSICAL(&u32_ERR17_RAM[0]);
	stImage_ERR[17].i16CenterX = ERR17_XCPOS;
	stImage_ERR[17].i16CenterY = ERR17_YCPOS;
	stImage_ERR[17].eFormat = FMT_RGBA32;
	stImage_ERR[17].u32Paletteaddress = 0;
	
	stImage_ERR[18].u16Width = ERR18_WIDTH;
	stImage_ERR[18].u16Height = ERR18_HEIGHT;
	stImage_ERR[18].u32Address = PHYSICAL(&u32_ERR18_RAM[0]);
	stImage_ERR[18].i16CenterX = ERR18_XCPOS;
	stImage_ERR[18].i16CenterY = ERR18_YCPOS;
	stImage_ERR[18].eFormat = FMT_RGBA32;
	stImage_ERR[18].u32Paletteaddress = 0;
	
	stImage_ERR[19].u16Width = ERR19_WIDTH;
	stImage_ERR[19].u16Height = ERR19_HEIGHT;
	stImage_ERR[19].u32Address = PHYSICAL(&u32_ERR19_RAM[0]);
	stImage_ERR[19].i16CenterX = ERR19_XCPOS;
	stImage_ERR[19].i16CenterY = ERR19_YCPOS;
	stImage_ERR[19].eFormat = FMT_RGBA32;
	stImage_ERR[19].u32Paletteaddress = 0;
	
	stImage_ERR[2].u16Width = ERR2_WIDTH;
	stImage_ERR[2].u16Height = ERR2_HEIGHT;
	stImage_ERR[2].u32Address = PHYSICAL(&u32_ERR2_RAM[0]);
	stImage_ERR[2].i16CenterX = ERR2_XCPOS;
	stImage_ERR[2].i16CenterY = ERR2_YCPOS;
	stImage_ERR[2].eFormat = FMT_RGBA32;
	stImage_ERR[2].u32Paletteaddress = 0;
	
	stImage_ERR[3].u16Width = ERR3_WIDTH;
	stImage_ERR[3].u16Height = ERR3_HEIGHT;
	stImage_ERR[3].u32Address = PHYSICAL(&u32_ERR3_RAM[0]);
	stImage_ERR[3].i16CenterX = ERR3_XCPOS;
	stImage_ERR[3].i16CenterY = ERR3_YCPOS;
	stImage_ERR[3].eFormat = FMT_RGBA32;
	stImage_ERR[3].u32Paletteaddress = 0;
	
	stImage_ERR[4].u16Width = ERR4_WIDTH;
	stImage_ERR[4].u16Height = ERR4_HEIGHT;
	stImage_ERR[4].u32Address = PHYSICAL(&u32_ERR4_RAM[0]);
	stImage_ERR[4].i16CenterX = ERR4_XCPOS;
	stImage_ERR[4].i16CenterY = ERR4_YCPOS;
	stImage_ERR[4].eFormat = FMT_RGBA32;
	stImage_ERR[4].u32Paletteaddress = 0;
	
	stImage_ERR[5].u16Width = ERR5_WIDTH;
	stImage_ERR[5].u16Height = ERR5_HEIGHT;
	stImage_ERR[5].u32Address = PHYSICAL(&u32_ERR5_RAM[0]);
	stImage_ERR[5].i16CenterX = ERR5_XCPOS;
	stImage_ERR[5].i16CenterY = ERR5_YCPOS;
	stImage_ERR[5].eFormat = FMT_RGBA32;
	stImage_ERR[5].u32Paletteaddress = 0;
	
	stImage_ERR[6].u16Width = ERR6_WIDTH;
	stImage_ERR[6].u16Height = ERR6_HEIGHT;
	stImage_ERR[6].u32Address = PHYSICAL(&u32_ERR6_RAM[0]);
	stImage_ERR[6].i16CenterX = ERR6_XCPOS;
	stImage_ERR[6].i16CenterY = ERR6_YCPOS;
	stImage_ERR[6].eFormat = FMT_RGBA32;
	stImage_ERR[6].u32Paletteaddress = 0;
	
	stImage_ERR[7].u16Width = ERR7_WIDTH;
	stImage_ERR[7].u16Height = ERR7_HEIGHT;
	stImage_ERR[7].u32Address = PHYSICAL(&u32_ERR7_RAM[0]);
	stImage_ERR[7].i16CenterX = ERR7_XCPOS;
	stImage_ERR[7].i16CenterY = ERR7_YCPOS;
	stImage_ERR[7].eFormat = FMT_RGBA32;
	stImage_ERR[7].u32Paletteaddress = 0;
	
	stImage_ERR[8].u16Width = ERR8_WIDTH;
	stImage_ERR[8].u16Height = ERR8_HEIGHT;
	stImage_ERR[8].u32Address = PHYSICAL(&u32_ERR8_RAM[0]);
	stImage_ERR[8].i16CenterX = ERR8_XCPOS;
	stImage_ERR[8].i16CenterY = ERR8_YCPOS;
	stImage_ERR[8].eFormat = FMT_RGBA32;
	stImage_ERR[8].u32Paletteaddress = 0;
	
	stImage_ERR[9].u16Width = ERR9_WIDTH;
	stImage_ERR[9].u16Height = ERR9_HEIGHT;
	stImage_ERR[9].u32Address = PHYSICAL(&u32_ERR9_RAM[0]);
	stImage_ERR[9].i16CenterX = ERR9_XCPOS;
	stImage_ERR[9].i16CenterY = ERR9_YCPOS;
	stImage_ERR[9].eFormat = FMT_RGBA32;
	stImage_ERR[9].u32Paletteaddress = 0;
	
/***********************************************************END err_word*******/


/**
	lamp
*/	
	stImage_sspic0.u16Width = SSPIC0_WIDTH;
	stImage_sspic0.u16Height = SSPIC0_HEIGHT;
	stImage_sspic0.u32Address = PHYSICAL(&u32_sspic0_RAM[0]);
	stImage_sspic0.i16CenterX = SSPIC0_XCPOS;
	stImage_sspic0.i16CenterY = SSPIC0_YCPOS;
	stImage_sspic0.eFormat = FMT_RGBA32;
	stImage_sspic0.u32Paletteaddress = 0;
	
	stImage_sspic1.u16Width = SSPIC1_WIDTH;
	stImage_sspic1.u16Height = SSPIC1_HEIGHT;
	stImage_sspic1.u32Address = PHYSICAL(&u32_sspic1_RAM[0]);
	stImage_sspic1.i16CenterX = SSPIC1_XCPOS;
	stImage_sspic1.i16CenterY = SSPIC1_YCPOS;
	stImage_sspic1.eFormat = FMT_RGBA32;
	stImage_sspic1.u32Paletteaddress = 0;
	
	stImage_sspic10.u16Width = SSPIC10_WIDTH;
	stImage_sspic10.u16Height = SSPIC10_HEIGHT;
	stImage_sspic10.u32Address = PHYSICAL(&u32_sspic10_RAM[0]);
	stImage_sspic10.i16CenterX = SSPIC10_XCPOS;
	stImage_sspic10.i16CenterY = SSPIC10_YCPOS;
	stImage_sspic10.eFormat = FMT_RGBA32;
	stImage_sspic10.u32Paletteaddress = 0;
	
	stImage_sspic11.u16Width = SSPIC11_WIDTH;
	stImage_sspic11.u16Height = SSPIC11_HEIGHT;
	stImage_sspic11.u32Address = PHYSICAL(&u32_sspic11_RAM[0]);
	stImage_sspic11.i16CenterX = SSPIC11_XCPOS;
	stImage_sspic11.i16CenterY = SSPIC11_YCPOS;
	stImage_sspic11.eFormat = FMT_RGBA32;
	stImage_sspic11.u32Paletteaddress = 0;
	
	stImage_sspic12.u16Width = SSPIC12_WIDTH;
	stImage_sspic12.u16Height = SSPIC12_HEIGHT;
	stImage_sspic12.u32Address = PHYSICAL(&u32_sspic12_RAM[0]);
	stImage_sspic12.i16CenterX = SSPIC12_XCPOS;
	stImage_sspic12.i16CenterY = SSPIC12_YCPOS;
	stImage_sspic12.eFormat = FMT_RGBA32;
	stImage_sspic12.u32Paletteaddress = 0;
	
	stImage_sspic13.u16Width = SSPIC13_WIDTH;
	stImage_sspic13.u16Height = SSPIC13_HEIGHT;
	stImage_sspic13.u32Address = PHYSICAL(&u32_sspic13_RAM[0]);
	stImage_sspic13.i16CenterX = SSPIC13_XCPOS;
	stImage_sspic13.i16CenterY = SSPIC13_YCPOS;
	stImage_sspic13.eFormat = FMT_RGBA32;
	stImage_sspic13.u32Paletteaddress = 0;
	
	stImage_sspic14.u16Width = SSPIC14_WIDTH;
	stImage_sspic14.u16Height = SSPIC14_HEIGHT;
	stImage_sspic14.u32Address = PHYSICAL(&u32_sspic14_RAM[0]);
	stImage_sspic14.i16CenterX = SSPIC14_XCPOS;
	stImage_sspic14.i16CenterY = SSPIC14_YCPOS;
	stImage_sspic14.eFormat = FMT_RGBA32;
	stImage_sspic14.u32Paletteaddress = 0;
	
	stImage_sspic15.u16Width = SSPIC15_WIDTH;
	stImage_sspic15.u16Height = SSPIC15_HEIGHT;
	stImage_sspic15.u32Address = PHYSICAL(&u32_sspic15_RAM[0]);
	stImage_sspic15.i16CenterX = SSPIC15_XCPOS;
	stImage_sspic15.i16CenterY = SSPIC15_YCPOS;
	stImage_sspic15.eFormat = FMT_RGBA32;
	stImage_sspic15.u32Paletteaddress = 0;
	
	stImage_sspic16.u16Width = SSPIC16_WIDTH;
	stImage_sspic16.u16Height = SSPIC16_HEIGHT;
	stImage_sspic16.u32Address = PHYSICAL(&u32_sspic16_RAM[0]);
	stImage_sspic16.i16CenterX = SSPIC16_XCPOS;
	stImage_sspic16.i16CenterY = SSPIC16_YCPOS;
	stImage_sspic16.eFormat = FMT_RGBA32;
	stImage_sspic16.u32Paletteaddress = 0;
	
	stImage_sspic17.u16Width = SSPIC17_WIDTH;
	stImage_sspic17.u16Height = SSPIC17_HEIGHT;
	stImage_sspic17.u32Address = PHYSICAL(&u32_sspic17_RAM[0]);
	stImage_sspic17.i16CenterX = SSPIC17_XCPOS;
	stImage_sspic17.i16CenterY = SSPIC17_YCPOS;
	stImage_sspic17.eFormat = FMT_RGBA32;
	stImage_sspic17.u32Paletteaddress = 0;
	
	stImage_sspic18.u16Width = SSPIC18_WIDTH;
	stImage_sspic18.u16Height = SSPIC18_HEIGHT;
	stImage_sspic18.u32Address = PHYSICAL(&u32_sspic18_RAM[0]);
	stImage_sspic18.i16CenterX = SSPIC18_XCPOS;
	stImage_sspic18.i16CenterY = SSPIC18_YCPOS;
	stImage_sspic18.eFormat = FMT_RGBA32;
	stImage_sspic18.u32Paletteaddress = 0;
	
	stImage_sspic19.u16Width = SSPIC19_WIDTH;
	stImage_sspic19.u16Height = SSPIC19_HEIGHT;
	stImage_sspic19.u32Address = PHYSICAL(&u32_sspic19_RAM[0]);
	stImage_sspic19.i16CenterX = SSPIC19_XCPOS;
	stImage_sspic19.i16CenterY = SSPIC19_YCPOS;
	stImage_sspic19.eFormat = FMT_RGBA32;
	stImage_sspic19.u32Paletteaddress = 0;
	
	stImage_sspic2.u16Width = SSPIC2_WIDTH;
	stImage_sspic2.u16Height = SSPIC2_HEIGHT;
	stImage_sspic2.u32Address = PHYSICAL(&u32_sspic2_RAM[0]);
	stImage_sspic2.i16CenterX = SSPIC2_XCPOS;
	stImage_sspic2.i16CenterY = SSPIC2_YCPOS;
	stImage_sspic2.eFormat = FMT_RGBA32;
	stImage_sspic2.u32Paletteaddress = 0;
	
	stImage_sspic20.u16Width = SSPIC20_WIDTH;
	stImage_sspic20.u16Height = SSPIC20_HEIGHT;
	stImage_sspic20.u32Address = PHYSICAL(&u32_sspic20_RAM[0]);
	stImage_sspic20.i16CenterX = SSPIC20_XCPOS;
	stImage_sspic20.i16CenterY = SSPIC20_YCPOS;
	stImage_sspic20.eFormat = FMT_RGBA32;
	stImage_sspic20.u32Paletteaddress = 0;
	
	stImage_sspic21.u16Width = SSPIC21_WIDTH;
	stImage_sspic21.u16Height = SSPIC21_HEIGHT;
	stImage_sspic21.u32Address = PHYSICAL(&u32_sspic21_RAM[0]);
	stImage_sspic21.i16CenterX = SSPIC21_XCPOS;
	stImage_sspic21.i16CenterY = SSPIC21_YCPOS;
	stImage_sspic21.eFormat = FMT_RGBA32;
	stImage_sspic21.u32Paletteaddress = 0;
	
	stImage_sspic22.u16Width = SSPIC22_WIDTH;
	stImage_sspic22.u16Height = SSPIC22_HEIGHT;
	stImage_sspic22.u32Address = PHYSICAL(&u32_sspic22_RAM[0]);
	stImage_sspic22.i16CenterX = SSPIC22_XCPOS;
	stImage_sspic22.i16CenterY = SSPIC22_YCPOS;
	stImage_sspic22.eFormat = FMT_RGBA32;
	stImage_sspic22.u32Paletteaddress = 0;
	
	stImage_sspic23.u16Width = SSPIC23_WIDTH;
	stImage_sspic23.u16Height = SSPIC23_HEIGHT;
	stImage_sspic23.u32Address = PHYSICAL(&u32_sspic23_RAM[0]);
	stImage_sspic23.i16CenterX = SSPIC23_XCPOS;
	stImage_sspic23.i16CenterY = SSPIC23_YCPOS;
	stImage_sspic23.eFormat = FMT_RGBA32;
	stImage_sspic23.u32Paletteaddress = 0;
	
	stImage_sspic24.u16Width = SSPIC24_WIDTH;
	stImage_sspic24.u16Height = SSPIC24_HEIGHT;
	stImage_sspic24.u32Address = PHYSICAL(&u32_sspic24_RAM[0]);
	stImage_sspic24.i16CenterX = SSPIC24_XCPOS;
	stImage_sspic24.i16CenterY = SSPIC24_YCPOS;
	stImage_sspic24.eFormat = FMT_RGBA32;
	stImage_sspic24.u32Paletteaddress = 0;
	
	stImage_sspic25.u16Width = SSPIC25_WIDTH;
	stImage_sspic25.u16Height = SSPIC25_HEIGHT;
	stImage_sspic25.u32Address = PHYSICAL(&u32_sspic25_RAM[0]);
	stImage_sspic25.i16CenterX = SSPIC25_XCPOS;
	stImage_sspic25.i16CenterY = SSPIC25_YCPOS;
	stImage_sspic25.eFormat = FMT_RGBA32;
	stImage_sspic25.u32Paletteaddress = 0;
	
	stImage_sspic26.u16Width = SSPIC26_WIDTH;
	stImage_sspic26.u16Height = SSPIC26_HEIGHT;
	stImage_sspic26.u32Address = PHYSICAL(&u32_sspic26_RAM[0]);
	stImage_sspic26.i16CenterX = SSPIC26_XCPOS;
	stImage_sspic26.i16CenterY = SSPIC26_YCPOS;
	stImage_sspic26.eFormat = FMT_RGBA32;
	stImage_sspic26.u32Paletteaddress = 0;
	
	stImage_sspic3.u16Width = SSPIC3_WIDTH;
	stImage_sspic3.u16Height = SSPIC3_HEIGHT;
	stImage_sspic3.u32Address = PHYSICAL(&u32_sspic3_RAM[0]);
	stImage_sspic3.i16CenterX = SSPIC3_XCPOS;
	stImage_sspic3.i16CenterY = SSPIC3_YCPOS;
	stImage_sspic3.eFormat = FMT_RGBA32;
	stImage_sspic3.u32Paletteaddress = 0;
	
	stImage_sspic4.u16Width = SSPIC4_WIDTH;
	stImage_sspic4.u16Height = SSPIC4_HEIGHT;
	stImage_sspic4.u32Address = PHYSICAL(&u32_sspic4_RAM[0]);
	stImage_sspic4.i16CenterX = SSPIC4_XCPOS;
	stImage_sspic4.i16CenterY = SSPIC4_YCPOS;
	stImage_sspic4.eFormat = FMT_RGBA32;
	stImage_sspic4.u32Paletteaddress = 0;
	
	stImage_sspic5.u16Width = SSPIC5_WIDTH;
	stImage_sspic5.u16Height = SSPIC5_HEIGHT;
	stImage_sspic5.u32Address = PHYSICAL(&u32_sspic5_RAM[0]);
	stImage_sspic5.i16CenterX = SSPIC5_XCPOS;
	stImage_sspic5.i16CenterY = SSPIC5_YCPOS;
	stImage_sspic5.eFormat = FMT_RGBA32;
	stImage_sspic5.u32Paletteaddress = 0;
	
	stImage_sspic6.u16Width = SSPIC6_WIDTH;
	stImage_sspic6.u16Height = SSPIC6_HEIGHT;
	stImage_sspic6.u32Address = PHYSICAL(&u32_sspic6_RAM[0]);
	stImage_sspic6.i16CenterX = SSPIC6_XCPOS;
	stImage_sspic6.i16CenterY = SSPIC6_YCPOS;
	stImage_sspic6.eFormat = FMT_RGBA32;
	stImage_sspic6.u32Paletteaddress = 0;
	
	stImage_sspic7.u16Width = SSPIC7_WIDTH;
	stImage_sspic7.u16Height = SSPIC7_HEIGHT;
	stImage_sspic7.u32Address = PHYSICAL(&u32_sspic7_RAM[0]);
	stImage_sspic7.i16CenterX = SSPIC7_XCPOS;
	stImage_sspic7.i16CenterY = SSPIC7_YCPOS;
	stImage_sspic7.eFormat = FMT_RGBA32;
	stImage_sspic7.u32Paletteaddress = 0;
	
	stImage_sspic8.u16Width = SSPIC8_WIDTH;
	stImage_sspic8.u16Height = SSPIC8_HEIGHT;
	stImage_sspic8.u32Address = PHYSICAL(&u32_sspic8_RAM[0]);
	stImage_sspic8.i16CenterX = SSPIC8_XCPOS;
	stImage_sspic8.i16CenterY = SSPIC8_YCPOS;
	stImage_sspic8.eFormat = FMT_RGBA32;
	stImage_sspic8.u32Paletteaddress = 0;
	
	stImage_sspic9.u16Width = SSPIC9_WIDTH;
	stImage_sspic9.u16Height = SSPIC9_HEIGHT;
	stImage_sspic9.u32Address = PHYSICAL(&u32_sspic9_RAM[0]);
	stImage_sspic9.i16CenterX = SSPIC9_XCPOS;
	stImage_sspic9.i16CenterY = SSPIC9_YCPOS;
	stImage_sspic9.eFormat = FMT_RGBA32;
	stImage_sspic9.u32Paletteaddress = 0;
		
/***********************************************************END lamp*******/


/**
	prnds
*/	
		
	stImage_LEV[3].u16Width = LEV_D_WIDTH;
	stImage_LEV[3].u16Height = LEV_D_HEIGHT;
	stImage_LEV[3].u32Address = PHYSICAL(&u32_LEV_D_RAM[0]);
	stImage_LEV[3].i16CenterX = LEV_D_XCPOS;
	stImage_LEV[3].i16CenterY = LEV_D_YCPOS;
	stImage_LEV[3].eFormat = FMT_RGBA32;
	stImage_LEV[3].u32Paletteaddress = 0;
	
	stImage_LEV[2].u16Width = LEV_N_WIDTH;
	stImage_LEV[2].u16Height = LEV_N_HEIGHT;
	stImage_LEV[2].u32Address = PHYSICAL(&u32_LEV_N_RAM[0]);
	stImage_LEV[2].i16CenterX = LEV_N_XCPOS;
	stImage_LEV[2].i16CenterY = LEV_N_YCPOS;
	stImage_LEV[2].eFormat = FMT_RGBA32;
	stImage_LEV[2].u32Paletteaddress = 0;
	
	stImage_LEV[0].u16Width = LEV_P_WIDTH;
	stImage_LEV[0].u16Height = LEV_P_HEIGHT;
	stImage_LEV[0].u32Address = PHYSICAL(&u32_LEV_P_RAM[0]);
	stImage_LEV[0].i16CenterX = LEV_P_XCPOS;
	stImage_LEV[0].i16CenterY = LEV_P_YCPOS;
	stImage_LEV[0].eFormat = FMT_RGBA32;
	stImage_LEV[0].u32Paletteaddress = 0;
	
	stImage_LEV[1].u16Width = LEV_R_WIDTH;
	stImage_LEV[1].u16Height = LEV_R_HEIGHT;
	stImage_LEV[1].u32Address = PHYSICAL(&u32_LEV_R_RAM[0]);
	stImage_LEV[1].i16CenterX = LEV_R_XCPOS;
	stImage_LEV[1].i16CenterY = LEV_R_YCPOS;
	stImage_LEV[1].eFormat = FMT_RGBA32;
	stImage_LEV[1].u32Paletteaddress = 0;
	
	stImage_LEV[4].u16Width = LEV_S_WIDTH;
	stImage_LEV[4].u16Height = LEV_S_HEIGHT;
	stImage_LEV[4].u32Address = PHYSICAL(&u32_LEV_S_RAM[0]);
	stImage_LEV[4].i16CenterX = LEV_S_XCPOS;
	stImage_LEV[4].i16CenterY = LEV_S_YCPOS;
	stImage_LEV[4].eFormat = FMT_RGBA32;
	stImage_LEV[4].u32Paletteaddress = 0;

/***********************************************************END prnds*******/


/**
	speedfont
*/	
	stImage_speedfont[0].u16Width = SPEEDFONT0_WIDTH;
	stImage_speedfont[0].u16Height = SPEEDFONT0_HEIGHT;
	stImage_speedfont[0].u32Address = PHYSICAL(&u32_speedfont0_RLE_RAM[0]);
	stImage_speedfont[0].i16CenterX = SPEEDFONT0_XCPOS;
	stImage_speedfont[0].i16CenterY = SPEEDFONT0_YCPOS;
	stImage_speedfont[0].eFormat = FMT_RLERGBA24;
	stImage_speedfont[0].u32Paletteaddress = 0;
	       
	stImage_speedfont[1].u16Width = SPEEDFONT1_WIDTH;
	stImage_speedfont[1].u16Height = SPEEDFONT1_HEIGHT;
	stImage_speedfont[1].u32Address = PHYSICAL(&u32_speedfont1_RLE_RAM[0]);
	stImage_speedfont[1].i16CenterX = SPEEDFONT1_XCPOS;
	stImage_speedfont[1].i16CenterY = SPEEDFONT1_YCPOS;
	stImage_speedfont[1].eFormat = FMT_RLERGBA24;
	stImage_speedfont[1].u32Paletteaddress = 0;
	           
	stImage_speedfont[2].u16Width = SPEEDFONT2_WIDTH;
	stImage_speedfont[2].u16Height = SPEEDFONT2_HEIGHT;
	stImage_speedfont[2].u32Address = PHYSICAL(&u32_speedfont2_RLE_RAM[0]);
	stImage_speedfont[2].i16CenterX = SPEEDFONT2_XCPOS;
	stImage_speedfont[2].i16CenterY = SPEEDFONT2_YCPOS;
	stImage_speedfont[2].eFormat = FMT_RLERGBA24;
	stImage_speedfont[2].u32Paletteaddress = 0;
	           
	stImage_speedfont[3].u16Width = SPEEDFONT3_WIDTH;
	stImage_speedfont[3].u16Height = SPEEDFONT3_HEIGHT;
	stImage_speedfont[3].u32Address = PHYSICAL(&u32_speedfont3_RLE_RAM[0]);
	stImage_speedfont[3].i16CenterX = SPEEDFONT3_XCPOS;
	stImage_speedfont[3].i16CenterY = SPEEDFONT3_YCPOS;
	stImage_speedfont[3].eFormat = FMT_RLERGBA24;
	stImage_speedfont[3].u32Paletteaddress = 0;
	              
	stImage_speedfont[4].u16Width = SPEEDFONT4_WIDTH;
	stImage_speedfont[4].u16Height = SPEEDFONT4_HEIGHT;
	stImage_speedfont[4].u32Address = PHYSICAL(&u32_speedfont4_RLE_RAM[0]);
	stImage_speedfont[4].i16CenterX = SPEEDFONT4_XCPOS;
	stImage_speedfont[4].i16CenterY = SPEEDFONT4_YCPOS;
	stImage_speedfont[4].eFormat = FMT_RLERGBA24;
	stImage_speedfont[4].u32Paletteaddress = 0;
	            
	stImage_speedfont[5].u16Width = SPEEDFONT5_WIDTH;
	stImage_speedfont[5].u16Height = SPEEDFONT5_HEIGHT;
	stImage_speedfont[5].u32Address = PHYSICAL(&u32_speedfont5_RLE_RAM[0]);
	stImage_speedfont[5].i16CenterX = SPEEDFONT5_XCPOS;
	stImage_speedfont[5].i16CenterY = SPEEDFONT5_YCPOS;
	stImage_speedfont[5].eFormat = FMT_RLERGBA24;
	stImage_speedfont[5].u32Paletteaddress = 0;
	              
	stImage_speedfont[6].u16Width = SPEEDFONT6_WIDTH;
	stImage_speedfont[6].u16Height = SPEEDFONT6_HEIGHT;
	stImage_speedfont[6].u32Address = PHYSICAL(&u32_speedfont6_RLE_RAM[0]);
	stImage_speedfont[6].i16CenterX = SPEEDFONT6_XCPOS;
	stImage_speedfont[6].i16CenterY = SPEEDFONT6_YCPOS;
	stImage_speedfont[6].eFormat = FMT_RLERGBA24;
	stImage_speedfont[6].u32Paletteaddress = 0;
	               
	stImage_speedfont[7].u16Width = SPEEDFONT7_WIDTH;
	stImage_speedfont[7].u16Height = SPEEDFONT7_HEIGHT;
	stImage_speedfont[7].u32Address = PHYSICAL(&u32_speedfont7_RLE_RAM[0]);
	stImage_speedfont[7].i16CenterX = SPEEDFONT7_XCPOS;
	stImage_speedfont[7].i16CenterY = SPEEDFONT7_YCPOS;
	stImage_speedfont[7].eFormat = FMT_RLERGBA24;
	stImage_speedfont[7].u32Paletteaddress = 0;
	               
	stImage_speedfont[8].u16Width = SPEEDFONT8_WIDTH;
	stImage_speedfont[8].u16Height = SPEEDFONT8_HEIGHT;
	stImage_speedfont[8].u32Address = PHYSICAL(&u32_speedfont8_RLE_RAM[0]);
	stImage_speedfont[8].i16CenterX = SPEEDFONT8_XCPOS;
	stImage_speedfont[8].i16CenterY = SPEEDFONT8_YCPOS;
	stImage_speedfont[8].eFormat = FMT_RLERGBA24;
	stImage_speedfont[8].u32Paletteaddress = 0;
	               
	stImage_speedfont[9].u16Width = SPEEDFONT9_WIDTH;
	stImage_speedfont[9].u16Height = SPEEDFONT9_HEIGHT;
	stImage_speedfont[9].u32Address = PHYSICAL(&u32_speedfont9_RLE_RAM[0]);
	stImage_speedfont[9].i16CenterX = SPEEDFONT9_XCPOS;
	stImage_speedfont[9].i16CenterY = SPEEDFONT9_YCPOS;
	stImage_speedfont[9].eFormat = FMT_RLERGBA24;
	stImage_speedfont[9].u32Paletteaddress = 0;
	
/***********************************************************END speedfont*******/
	
/**
	instrument
*/
	stImage_dial_amp.u16Width = DIAL_AMP_WIDTH;
	stImage_dial_amp.u16Height = DIAL_AMP_HEIGHT;
	stImage_dial_amp.u32Address = PHYSICAL(&u32_dial_amp_RAM[0]);
	stImage_dial_amp.i16CenterX = DIAL_AMP_XCPOS;
	stImage_dial_amp.i16CenterY = DIAL_AMP_YCPOS;
	stImage_dial_amp.eFormat = FMT_RGBA32;
	stImage_dial_amp.u32Paletteaddress = 0;
	
	stImage_dial_soc.u16Width = DIAL_SOC_WIDTH;
	stImage_dial_soc.u16Height = DIAL_SOC_HEIGHT;
	stImage_dial_soc.u32Address = PHYSICAL(&u32_dial_soc_RAM[0]);
	stImage_dial_soc.i16CenterX = DIAL_SOC_XCPOS;
	stImage_dial_soc.i16CenterY = DIAL_SOC_YCPOS;
	stImage_dial_soc.eFormat = FMT_RGBA32;
	stImage_dial_soc.u32Paletteaddress = 0;
	
	stImage_dial_speed.u16Width = DIAL_SPEED_WIDTH;
	stImage_dial_speed.u16Height = DIAL_SPEED_HEIGHT;
	stImage_dial_speed.u32Address = PHYSICAL(&u32_dial_speed_RAM[0]);
	stImage_dial_speed.i16CenterX = DIAL_SPEED_XCPOS;
	stImage_dial_speed.i16CenterY = DIAL_SPEED_YCPOS;
	stImage_dial_speed.eFormat = FMT_RGBA32;
	stImage_dial_speed.u32Paletteaddress = 0;
/***************************************************************************************END instrument**********/

/**
	needle
*/
	stImage_needle_amp.u16Width = NEEDLE_AMP_WIDTH;
	stImage_needle_amp.u16Height = NEEDLE_AMP_HEIGHT;
	stImage_needle_amp.u32Address = PHYSICAL(&u32_needle_amp_RAM[0]);
	stImage_needle_amp.i16CenterX = NEEDLE_AMP_XCPOS;
	stImage_needle_amp.i16CenterY = NEEDLE_AMP_YCPOS;
	stImage_needle_amp.eFormat = FMT_RGBA32;
	stImage_needle_amp.u32Paletteaddress = 0;
	
	stImage_needle_speed.u16Width = NEEDLE_SPEED_WIDTH;
	stImage_needle_speed.u16Height = NEEDLE_SPEED_HEIGHT;
	stImage_needle_speed.u32Address = PHYSICAL(&u32_needle_speed_RAM[0]);
	stImage_needle_speed.i16CenterX = NEEDLE_SPEED_XCPOS;
	stImage_needle_speed.i16CenterY = NEEDLE_SPEED_YCPOS;
	stImage_needle_speed.eFormat = FMT_RGBA32;
	stImage_needle_speed.u32Paletteaddress = 0;
/***************************************************************************************END needle**************/





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
