/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH,
*   European LSI Design and Engineering Center (ELDEC)
*****************************************************************************
*   File Name   : $RCSfile: can.c,v $
*   Description : CAN-driver
*****************************************************************************
*   PROJECT     : Capricorn_Bt
*   MODULE      : CAN-driver
*   TAG         : $Name:  $
*   LIBRARIES   :
*   AUTHOR      : $Author: mto $
*****************************************************************************
*   VERSION     : $Revision: 1.4 $
*   RELEASE     : Preliminary and Confidential
*   DATE        : $Date: 2014/12/17 15:17:49 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Demo_7inch/usecases/src/can.c,v $
****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "ccr.h"
#include "intc.h"
#include "txcan.h"
#include "can.h"
#include "statevariables.h"
//#include "navigation.h"
#include "pinconfig.h"
#include "mydef.h"
/**********************************************
*             Constants & Macros              *
**********************************************/


/**********************************************
*                Variables                    *
**********************************************/
#ifdef _USE_CAN
	#define	CAN_MAX_BUFF	100
	struct recv_info
	{
		uint64_t u64CAN_Buffer[CAN_MAX_BUFF];
		uint32_t framid[CAN_MAX_BUFF];
	};

	struct recv_info stRecvInfo;
	
	uint16_t u16ReadIndex = 0;
	uint8_t u8IndexFlag = 0;
	uint16_t u16RunIndex = 0;
#endif

/**********************************************
*                functions                    *
**********************************************/
#if defined(__GHS__) || defined(__ghs__)
__interrupt void vCanRxInterrupt(void)
#else
__irq void vCanRxInterrupt(void)
#endif /* defined(__GHS__) || defined(__ghs__) */
{
#ifdef _USE_CAN
    if (1 == u8TXCAN_GetReceiveInterrupt(TXCAN_CH0, TXCAN_MB0))
    {
        vTXCAN_ClearReceiveInterrupt(TXCAN_CH0, TXCAN_MB0);
        vTXCAN_ClearPendingReceiveMessage(TXCAN_CH0, TXCAN_MB0);

        /* get values out of mailbox */
        stRecvInfo.u64CAN_Buffer[u16ReadIndex] = u64TXCAN_ReadMailbox(TXCAN_CH0, TXCAN_MB0);
		stRecvInfo.framid[u16ReadIndex] = u16TXCAN_GetStdID(TXCAN_CH0, TXCAN_MB0);
		stRecvInfo.framid[u16ReadIndex] <<= 18;
		stRecvInfo.framid[u16ReadIndex] |= u32TXCAN_GetExtID(TXCAN_CH0, TXCAN_MB0);     //读出标准ID和扩展ID

		
		
        u16ReadIndex = u16ReadIndex + 1;
        if (u16ReadIndex >= CAN_MAX_BUFF)
        {
            u16ReadIndex = 0;
			u8IndexFlag = 1;
        }
    }

    if (1 == u8TXCAN_GetReceiveInterrupt(TXCAN_CH0, TXCAN_MB2))
    {
        vTXCAN_ClearReceiveInterrupt(TXCAN_CH0, TXCAN_MB2);
        vTXCAN_ClearPendingReceiveMessage(TXCAN_CH0, TXCAN_MB2);
    }

    i32INTC_ClearIrq(u32INTC_GetVectAddr());
    vINTC_ModifyIrqLevel(INTC_RESTORE_OLD, INTC_LEVEL_7);
#endif
}


/****************************************************************************/

#if defined(__GHS__) || defined(__ghs__)
__interrupt void vCanTxInterrupt(void)
#else
__irq void vCanTxInterrupt(void)
#endif /* defined(__GHS__) || defined(__ghs__) */
{
#ifdef _USE_CAN
    if (1 == u8TXCAN_GetTransmitInterrupt(TXCAN_CH0, TXCAN_MB1))
    {
        vTXCAN_ClearTransmitInterrupt(TXCAN_CH0, TXCAN_MB1);
        vTXCAN_ClearTransmissionAcknowledge(TXCAN_CH0, TXCAN_MB1);
    }

    i32INTC_ClearIrq(u32INTC_GetVectAddr());
    vINTC_ModifyIrqLevel(INTC_RESTORE_OLD, INTC_LEVEL_7);
#endif
}


/****************************************************************************/

#if defined(__GHS__) || defined(__ghs__)
__interrupt void vCanStatusInterrupt(void)
#else
__irq void vCanStatusInterrupt(void)
#endif /* defined(__GHS__) || defined(__ghs__) */
{
    while (1){}
}


/****************************************************************************/

void vInitCAN(void)
{
    TXCAN_timing_st stTiming;
    TXCAN_CHconfig_st stCHConfig;
    TXCAN_MBconfig_st stMBConfig;

    /* clear CAN-buffer */
    for (u16ReadIndex = 0; u16ReadIndex < CAN_MAX_BUFF; u16ReadIndex++)
    {
        stRecvInfo.u64CAN_Buffer[u16ReadIndex] = 0;
		stRecvInfo.framid[u16ReadIndex] = 0;
    }
    u16ReadIndex = 0;

    /* configure pins */
    vPinconfig_CAN();

    /* mode */
    vCCR_SetCANMode(CCR_CAN_MODE_T_1_1_1_1);

	vSetAcceptanceMaskType(TXCAN_CH0,TXCAN_MB0,TXCAN_StandardandExtendedLAM);

	vTXCAN_SetAcceptanceMask(TXCAN_CH0, TXCAN_MB0, 0x1fffffff);					//接收所有数据帧

    /* configure timing - 125K */
    stTiming.u8BaudRatePrescaler = BRP_125K;                  /* prescaler */
    stTiming.u8BitTiming1        = BT1_125K;                  /* bit timing parameter 1 */
    stTiming.u8BitTiming2        = BT2_125K;                  /* bit timing parameter 2 */
    stTiming.eSamplingType       = TXCAN_SingleSampling;      /* sampling type */
    stTiming.eBitLS              = TXCAN_BitLS2TQ;            /* lengthening and shortening of bits */
    vTXCAN_ConfigureTiming(TXCAN_CH0, &stTiming);

    /* configure channel */
    stCHConfig.eSoftwareReset     = TXCAN_SRDisable;          /* enable software reset */
    stCHConfig.eTimeStampCounter  = TXCAN_TSCDisable;         /* time stamp counter */
    stCHConfig.eTransmissionOrder = TXCAN_MailboxNumber;      /* transmission order */
    stCHConfig.eWakeUp            = TXCAN_WriteToMCR;         /* wake up on bus activity */
    stCHConfig.eSleepMode         = TXCAN_noRequest;          /* sleep mode request */
    stCHConfig.eChangeConfig      = TXCAN_CCNormalOperation;  /* change config request */
    stCHConfig.eTestError         = TXCAN_TENormalOperation;  /* test error mode */
    stCHConfig.eTestLoopback      = TXCAN_TLBNormalOperation; /* test loopback mode */
    stCHConfig.eInternalLoopback  = TXCAN_ILBNormalOperation; /* internal loopback mode */
    stCHConfig.eSuspendMode       = TXCAN_SNormalOperation;   /* suspend mode request */
    vTXCAN_ConfigureChannel(TXCAN_CH0, &stCHConfig);

    /* MCR - clear time stamp */
    vTXCAN_ClearTimeStampValue(TXCAN_CH0);

    /* disable all mailboxes */
    vTXCAN_MailboxDisableAll(TXCAN_CH0);


    /* Configure mailbox 0 of Channel 0 for id 0x334 */
    stMBConfig.eChannel = TXCAN_CH0;
    stMBConfig.eMailbox = TXCAN_MB0;
    stMBConfig.u8DataLength = 0x8;
    stMBConfig.eRemoteFrameTransmissionRequest = TXCAN_NormalFrame;
    stMBConfig.u32ExtendedIdentifier = 0x00;
    stMBConfig.u16StandardIdentifier = 0x00;
    stMBConfig.eRemoteFrameHandling  = TXCAN_SoftwareHandled;
    stMBConfig.eGlobalAcceptanceMask = TXCAN_GlobalAcceptanceMask;
    stMBConfig.eFrameType = TXCAN_Extended;
    stMBConfig.eMailboxDirection = TXCAN_Input;
    vTXCAN_ConfigureMailbox(&stMBConfig);



    /* Configure mailbox 1 of Channel 0 for id 0x333 */
    stMBConfig.eChannel = TXCAN_CH0;
    stMBConfig.eMailbox = TXCAN_MB1;
    stMBConfig.u8DataLength = 0x8;
    stMBConfig.eRemoteFrameTransmissionRequest = TXCAN_NormalFrame;
    stMBConfig.u32ExtendedIdentifier = 0x0;
    stMBConfig.u16StandardIdentifier = 0x333;
    stMBConfig.eRemoteFrameHandling  = TXCAN_SoftwareHandled;
    stMBConfig.eGlobalAcceptanceMask = TXCAN_Identifier;
    stMBConfig.eFrameType = TXCAN_Standard;
    stMBConfig.eMailboxDirection = TXCAN_Output;
    vTXCAN_ConfigureMailbox(&stMBConfig);

    /* Configure mailbox 2 of Channel 0 for id 0x331 */
    stMBConfig.eChannel = TXCAN_CH0;
    stMBConfig.eMailbox = TXCAN_MB2;
    stMBConfig.u8DataLength = 0x8;
    stMBConfig.eRemoteFrameTransmissionRequest = TXCAN_NormalFrame;
    stMBConfig.u32ExtendedIdentifier = 0x0;
    stMBConfig.u16StandardIdentifier = 0x331;
    stMBConfig.eRemoteFrameHandling  = TXCAN_SoftwareHandled;
    stMBConfig.eGlobalAcceptanceMask = TXCAN_Identifier;
    stMBConfig.eFrameType = TXCAN_Standard;
    stMBConfig.eMailboxDirection = TXCAN_Input;
    vTXCAN_ConfigureMailbox(&stMBConfig);

    /* enable interrupt */
    vTXCAN_EnableInterrupt(TXCAN_CH0, TXCAN_MB0);
    vTXCAN_EnableInterrupt(TXCAN_CH0, TXCAN_MB1);
    vTXCAN_EnableInterrupt(TXCAN_CH0, TXCAN_MB2);

    /* configure interrupts */
    i32INTC_SourceConfig(INTC_TXCAN_CH0_RX, INTC_TO_CPU, INTC_LEVEL_HI, INTC_LEVEL_3, INTC_AUTO_CLEAR_DISABLE);
    vINTC_SetISRStartAddress(INTC_TXCAN_CH0_RX, (uint32_t)&vCanRxInterrupt);

    i32INTC_SourceConfig(INTC_TXCAN_CH0_TX, INTC_TO_CPU, INTC_LEVEL_HI, INTC_LEVEL_3, INTC_AUTO_CLEAR_DISABLE);
    vINTC_SetISRStartAddress(INTC_TXCAN_CH0_TX, (uint32_t)&vCanTxInterrupt);

    i32INTC_SourceConfig(INTC_TXCAN_CH0_ST, INTC_TO_CPU, INTC_LEVEL_HI, INTC_LEVEL_3, INTC_AUTO_CLEAR_DISABLE);
    vINTC_SetISRStartAddress(INTC_TXCAN_CH0_ST, (uint32_t)&vCanStatusInterrupt);

}


/****************************************************************************/

void vEvalCAN(void)
{
#if 0
	uint32_t id;
	uint64_t dat;
	if(u16RunIndex < u16ReadIndex || ((u16RunIndex > u16ReadIndex) && (u8IndexFlag == 0x1)))
	{
		id = stRecvInfo.framid[u16RunIndex];
		dat = stRecvInfo.u64CAN_Buffer[u16RunIndex];
		u16RunIndex++;
		if(u16RunIndex >= CAN_MAX_BUFF)
		{
			u16RunIndex = 0;
			u8IndexFlag = 0;
		}
		
		switch(id)
		{      
		//ֻ³µ¿ٖǆ�   
		case 0x0C0028D0:           
			system_life  =data[0];//ϵͳlife        
			controller_ST=data[1];//ֻ³µ¿ٖǆ�¬        
			speed_ST     =data[2];//¼ԋڌ¤°忪¶Ơ       
			braking_ST   =data[3];//׆¶¯̤°忪¶Ơ       
			torque=(((unsigned int)data[4])<<8)+data[5];//Ƚ¶¯µ缺ת¾֠       
			miles =(((unsigned int)data[6])<<8)+data[7];//Ѹº½o³ʠ     
			break;      
		case 0x0C0317D0:        
			CAN_MOTER_COUNT=0;        
			Mload =data[0];   //µ缺¸ººǠ       
			Mlegal=data[1];  //µ缺ת̙ºϷ¨        
			Espeed=(((unsigned int)data[2])<<8)+data[3];  //µ缺ת̙        
			Vspeed=data[4];  //³µ̙        fault_st=data[5];//¹˕З´̬ؖ        
			break;
		case 0x0c00d0ef:
			changer_st=data[0]; 
			//³丅µ脣ʽ  
			break;      
		case 0x0c01d0ef:        
			CTRL_temp=data[0]; //¿ٖǆ�Ơ       
			Etemp=data[1];     //µ缺ς¶Ơ      
			CTRL_ST=(((unsigned int)data[7])<<8)+data[6];   //µ缺¿ٖǆ�З´̬ؖ         
			break;
		case 0x0c02f3d0:
			ready_st=data[0]; //ready хºÍ
			break;    //³䶧ϵͳ      
		case 0x181A28F4:         
			BAT_num=data[2];         
			capacity=data[3];           
			Sbattery=data[4];      
			break;     
		case 0x181E28F4:        
			change_modo=data[0];        
			Cvoltage=(((unsigned int)data[2])<<8)+data[1];         
			Ccurrent=(((unsigned int)data[6])<<8)+data[5];  //³䶧µ葹 //θП؜µ葹      
			break; //BMSµ紘¹݀ͳ      
		case 0x1800D0F3: //¶¯fµ紘ة״̬        
			Amotor   =data[1]; //؜µ肷        
			Sbattery1=data[2];         
			Sbattery2=data[6];//µ紘¹˕ϵȼ¶        
			Sbattery3=data[7];      
			break;       
		case 0x181C28F4:        
			Vmax.byte[0]=data[0];      //خ´󵦌嶧ѹ        
			Vmax.byte[1]=data[1];        
			Vmin.byte[0]=data[2];     //خСµ¥ͥµ葹        
			Vmin.byte[1]=data[3];         
			Tmax        =data[4];        
			Tmin        =data[5];      
			break;      
		case  0x181D28F4:         
			Vmax_box=data[0];         
			Vmax_num=data[1]; //خ´󵦌嶧ѹةºà       
			Vmin_box=data[2]; //خСµ¥ͥµ葹Фͥºà      
			Vmin_num=data[3]; //خСµ¥ͥµ葹ФŚλ׃       
			Tmax_box=data[4];        
			Tmax_num=data[5]; //خ´󵦌嶧³َ¶ɗ黅        
			Tmin_box=data[6];        
			Tmin_num=data[7]; //خСµ¥ͥµ紘ς¶ɗ黅            
			break;      
		case  0x181B17F4:        
			Vbattery=(((unsigned int)data[1])<<8)+data[0];       
			Abattery=(((unsigned int)data[3])<<8)+data[2];            
			SOC=data[4]*0.4;      
			break;      
		default:        
			if((id&0xFF00FFFF)==0x180028F4)
			{ //µ¥ͥµ紘ς¶Ư/ς¶ȴ«¸ц�       
				CAN_BAT_COUNT=0;          
				j=(unsigned char)((id&0x00ff0000)>>16);           
				if(j<BAT_BOX_NUM)
				{ //µ紘Ф˽           
					for(i=0;i<4;i++)temp_bat[j][i]=data[i];          
				}        
			}        
			if((id&0xFF00FFFF)==0x180028F3)
			{//µ¥ͥµ紘µ葹          
				CAN_BAT_COUNT=0;          
				j=(unsigned char)((id&0x00ff0000)>>16);           
				if(j<CAN_BAT_NUM)
				{             
					for(i=0;i<4;i++)
					{              
						voltage_bat[j*4+i].byte[0]=data[i*2];               
						voltage_bat[j*4+i].byte[1]=data[i*2+1];            
					}           
				}        
			}      
			break;   
		}
	}
#endif
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
  鈥淗andling Guide for Semiconductor Devices,鈥?or 
  鈥淭OSHIBA Semiconductor Reliability Handbook鈥?etc..

- The Toshiba products listed in this document are intended for usage in 
  general electronics applications (computer, personal equipment, office 
  equipment, measuring equipment, industrial robotics, domestic appliances,
  etc.). 
  These Toshiba products are neither intended nor warranted for usage in 
  equipment that requires extraordinarily high quality and/or reliability or
  a malfunction or failure of which may cause loss of human life or bodily 
  injury (鈥淯nintended Usage鈥?. Unintended Usage include atomic energy control
  instruments, airplane or spaceship instruments, transportation instruments, 
  traffic signal instruments, combustion control instruments, medical 
  instruments, all types of safety devices, etc.. 
  Unintended Usage of Toshiba products listed in this document shall be 
  made at the customer鈥檚 own risk.

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

