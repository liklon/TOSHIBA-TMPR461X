/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: main.c,v $
*   Description : System main routine
******************************************************************************
*   PROJECT     : Capricorn-Bt
*   MODULE      : System
*               : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.2 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/05/23 08:12:15 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Basic_Graphics_Keil/src/main.c,v $
*   LOG:        : please have a look at the end of the file
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#ifndef CAPBT_ROMEXEC
#include <stdio.h>
#endif /* CAPBT_ROMEXEC */

#include "captypes.h"                /* Core specific primitive type definitions */
#include "core.h"
#include "config.h"
#include "boardcfg.h"                 /* Board specific configuration interface */
#include "gfunctions.h"
#include "listmngr.h"
#include "dispparams.h"
#include "definitions.h"
#include "statevariables.h"

#include "images_defs.h"
#include "images_externs.h"
#include "gear.h"
#include "icons.h"
#include "gpio.h"
#include "pinconfig.h"
#include "buttons.h"
#include "wdt.h"
#include "wdt_io.h"
#include "string.h"
#include "rt_heap.h"
/*********************************************/
#include "gpio.h"
#include "Hsuart.h"
#include "Hsuart_io.h"
#include "mydef.h"
#include "intc.h"
#include "stdlib.h"
#include "adc.h"
#include "can.h"
#include "ccr_pdh_io.h"
model_data_st gModeData;						//??????
uint8_t u8IconConfigTable[TYPE2_NUMBER];

/**********************************************
*             Constants & Macros              *
**********************************************/
/*************************FLAG ???*******************************/
uint8_t u8SpeedChangeTimeFlag = 0;

/*********************************************/

/**********************************************
*   Local variables and forward declarations  *
**********************************************/
/*********************************************/


/**********************************************
*                  Functions                  *
**********************************************/

/****************************************************************************/
void vInitSytem(void)
{
    gf_cliprect_st stFill_GDC0 = {0, 0, GDC0_LAYERA_WIDTH, GDC0_LAYERA_HEIGHT};
	vInitCAN();
    /* Board specific, clocks and ports configuration */
    vBoardCfg();

    /* Initialize the middleware */
    vInitGraphicsSystem();
    
    /* Initialize images */
    vGfInitImages();

    /* get Images out of ROM */
    vGfCopyImagesROMtoRAM();

    /* init statevariables*/
    vInitStatevariables();

    vGfBuffFillArea(&GDCX_LAYER_USE.stDispFB, &stFill_GDC0, 0x00000000);
    vGfListExecute();
    vGfBuffFillArea(&GDCX_LAYER_USE.stWriteFB, &stFill_GDC0, 0x00000000);
    vGfListExecute();
	
		vSystemInitFlib(stImage_disfont, stImage_speedfont, stImage_a, stImage_AA);
	
	
    /* set icons */
    vInitIcons();

}


int  sendchar(int ch){
  i32UART_WriteByte(UART_CH0,ch);
  while(u32UART_IsTxFifoReady(UART_CH0) != 1);

  if( ch == '\n' )
        {
            i32UART_WriteByte(UART_CH0, '\r');
            while(u32UART_IsTxFifoReady(UART_CH0) != 1);
        }
		 return(ch);		
}
int  getkey(void)
{
	uint8_t u8Data;
	    /* read from UART */
  while (u8UART_GetRxDataCnt(UART_CH0) == 0);				
	i32UART_ReadByte(UART_CH0, &u8Data);
	
	return u8Data;	
}
				
int fputc(int ch, FILE *f) {
  return (sendchar(ch));
}

/****************************************************************************/
/*
 *  APPLICATION 
 */
void vPinconfig_UART(void)
{
    i32GPIO_EnableLatchFunction(PORT_UART0RX, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_UART0RX, PORT_UART0RX_AS_UART0RX);
    i32GPIO_EnablePullUp(PORT_UART0RX, GPIO_ENABLE);
    i32GPIO_SetOutputResistance(PORT_UART0RX, GPIO_OUTPUT_RESISTANCE_50);
    
    i32GPIO_EnableLatchFunction(PORT_UART0TX, GPIO_DISABLE);
    i32GPIO_SetPinFunction(PORT_UART0TX, PORT_UART0TX_AS_UART0TX);
    i32GPIO_EnablePullUp(PORT_UART0TX, GPIO_ENABLE);
    i32GPIO_SetOutputResistance(PORT_UART0TX, GPIO_OUTPUT_RESISTANCE_50);
}

void vMyInitUart(uart_Ch_e eCh)
{
	uart_DataFmt_st stDataFmt;
    uart_DmaIrq_st  stDmaIrq;
    uart_Fifo_st    stFifo;
    uart_Flow_st    stFlow;

	vPinconfig_UART();
	
    /* Line/Data Format configuration */
    stDataFmt.eRwub  = UART_NOT_WAIT_WUB;  /* No wait for Wake-up bit */
    stDataFmt.eTwub  = UART_NFRAME_DATA;   /* Next Frame is Data Frame */
    stDataFmt.eLsbf  = UART_LSB;           /* LSB bit goes first */
    stDataFmt.eUeps  = UART_ODD;           /* Odd Parity*/ 
    stDataFmt.eUpen  = UART_PARITY_DIS;    /* Parity enable */
    stDataFmt.eUsbl  = UART_ONE_BIT;       /* One stop bit */
    stDataFmt.eUmode = UART_8BIT;          /* 8-bit data transmission */

    /* DMA IRQ settings */
    stDmaIrq.eTir   = UART_IRQ_EN;
    stDmaIrq.eRir   = UART_IRQ_EN;
    stDmaIrq.eSpir  = UART_IRQ_EN;
    stDmaIrq.eSioe  = UART_IRQ_EN;
    stDmaIrq.eSicts = UART_IRQ_EN;
    stDmaIrq.eSibrk = UART_IRQ_EN;
    stDmaIrq.eSitr  = UART_IRQ_EN;
    stDmaIrq.eSias  = UART_IRQ_EN;
    stDmaIrq.eSiub  = UART_BRK_DET_DIS;    /* BREAK detection disabled*/

    /* Fifo configuration */
    stFifo.u8Rdil  = 1;                    /* Receive FIFO Threshold */
    stFifo.u8Tdil  = 1;                    /* Transmit FIFO Threshold */
    stFifo.eFrStew = UART_FIFO_RST_EN;    

    /* Flow control configuration */
    stFlow.eRsdr = UART_DATA_STORE;        /* Enable data storing in Rx FIFO */
    stFlow.eTsdr = UART_TRANS_HALT;        /* Do not start transmission immediately*/
    stFlow.eTbrk = UART_TRANS_NORM;        /* Normal operation (no BREAK sent) */

    /* set baudrate accordingly */
    vUART_Init(eCh, UART_BR_115200, &stDataFmt, &stDmaIrq);

    /* Configure Tx/Rx FIFOs */
    vUART_FifoConfig(eCh, &stFifo);

    /* Configure Flow Control */
    vUART_FlowCtrlConfig(eCh, &stFlow);

    /* Enable Transmition */
    vUART_TxRunCtrl(eCh, UART_TRANS_RUN);
}



void vAppMain(void)
{
	uint8_t u8iIndex = 0;
#ifdef _AT_RUN
	uint8_t u8j = 0;
	uint8_t ff = 0;
	uint8_t bb = 0;
#endif	
	PMU_ENABLE() ;
	/* Timer Enable */
	TIMER_ENABLE() ; 
	/* Timer Reset */
	TIMER_RESET();			
	/* Initialisation of buttons */
    vInitPanelPin();
	vBLControl(PANEL_PIN, 1, PANEL_ON_GP_STAT);  
	//vInterruptEnable();
	vInitSytem();
	vMyInitUart(UART_CH0);
	//vInitPushbuttons();
    vAOBInstallEncPollTimer(10);
	//ÏÔÊ¾ºÚÆÁ
    memset(&gModeData,1,sizeof(model_data_st));
    vInitAllData();
	/* Main loop */
    u8SpeedChangeTimeFlag = 0;

#ifndef _MY_DEBUG
	while(gModeData.u8type1Data == 0 && u8CheckConnectSendData != 'o')
	{
		if(u8SpeedChangeTimeFlag > 10)
		{
			i32UART_WriteByte(UART_CH0,u8CheckConnectSendData);
			u8SpeedChangeTimeFlag = 0;
		}
	}
	
    i32UART_WriteByte(UART_CH0,0XBB);
#endif
	u8SpeedChangeTimeFlag = 0;

#ifdef _MY_DEBUG
	gModeData.u8type1Data = MAIN_SCREEN;

#endif
while( 1 )
	{
		vEvalCAN();
		
		if(u8SpeedChangeTimeFlag > (REFRESH - 1))
		{

			if(gModeData.u8type1Data == MAIN_SCREEN)
			{
				u8iIndex = 0;
				while(gRunFunTable[u8iIndex] != 0)
				{
					gRunFunTable[u8iIndex]();
					u8iIndex++;
				}				
				vGfLayerSwitchBufferSync(GDCX_USE, &GDCX_LAYER_USE);
			}
			else if(gModeData.u8type1Data == WAKE_UP_SCREEN)
			{
				vClearScreen();
				
				gModeData.u8type1Data = MOTOR_INFO_SCREEN + 1;
			}
			else if(gModeData.u8type1Data == POWER_DOWN_SCREEN)
			{
				vClearScreen();
				
				gModeData.u8type1Data = MOTOR_INFO_SCREEN + 1;

			}
			else if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
			{
				u8iIndex = 0;
	
				vGfLayerSwitchBufferSync(GDCX_USE, &GDCX_LAYER_USE);
			}
			else if(gModeData.u8type1Data == MOTOR_INFO_SCREEN)
			{
				u8iIndex = 0;
	
				vGfLayerSwitchBufferSync(GDCX_USE, &GDCX_LAYER_USE);
			}


			
			u8SpeedChangeTimeFlag = 0;
		}


#ifdef _AT_RUN
		if(u16Timer1SFlag > 10)
		{
			i32UART_WriteByte(UART_CH0 , 'r');
			for(u8j = 0;u8j < (TYPE3_TOTAL_NUMBER_ee - TYPE3_NUMBER_BASE);u8j++)
			{
				if(gModeData.sttype3DataTable[u8j].u8dp == 0)
				{
					if(gModeData.sttype3DataTable[u8j].u32data < u32Type3MinMaxTable[u8j][1])
					{
						gModeData.sttype3DataTable[u8j].u32data++;
					}
					else
					{
						gModeData.sttype3DataTable[u8j].u32data = 0;
					}
				}
				
			}
			gModeData.u8type2DataTable[bb++] = ff;
			
			if(bb >= TYPE2_NUMBER) 
			{
				if(ff == 0)  ff = 1;
				else ff = 0;
				bb = 0;
			}
	
			u16Timer1SFlag = 0;
		}	
		
#endif		
	}
}

/***************************************************************************/


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

/********************************* BEGIN OF LOG ******************************
*
* $Log: main.c,v $
* Revision 1.2  2014/05/23 08:12:15  mto
* remove printf
*
* Revision 1.1  2014/05/09 14:05:52  mto
* initial version
*
*
*********************************** END OF LOG ******************************/
