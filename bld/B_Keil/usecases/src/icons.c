/*****************************************************************************
*   This software is copyright protected. All rights reserved
*   Toshiba Electronics Europe GmbH
*   European LSI Design and Engineering Center (ELDEC)
******************************************************************************
*   File Name   : $RCSfile: icons.c,v $
*   Description : Icons
******************************************************************************
*   PROJECT     : Capricorn_Bt
*   MODULE      : Application
*               : $Name:  $
*   LIBRARIES   : None
*   AUTHOR      : $Author: mto $
******************************************************************************
*   VERSION     : $Revision: 1.1 $
*   RELEASE     : Preliminary & Confidential
*   DATE        : $Date: 2014/05/09 14:05:53 $
*   SOURCE MOD. : $Source: /teenet/mpumcu/Capricorn/Capricorn_Bt/bld/Basic_Graphics_Keil/usecases/src/icons.c,v $
*   LOG:        : please have a look at the end of the file
*****************************************************************************/

/**********************************************
*                Include files                *
**********************************************/
#include "captypes.h"        /* Core specific primitive type definitions */
#include "listmngr.h"
#include "gfunctions.h"
#include "images_defs.h"
#include "images_externs.h"
#include "statevariables.h"
#include "icons.h"
#include "gpio.h"       /* GPIO LLDD definitions */
#include "adc.h"
#include "Timer_pwm.h"
#include "stdio.h"
#include "hsuart.h"
#include "string.h"
#include "intc.h"
#include "mydef.h"
/**********************************************
*             Constants & Macros              *
**********************************************/

/**********************************************
*                Variables                    *
**********************************************/
uint16_t	u16ADC1Result = 0;

void vClearScreen(void)
{
	gf_cliprect_st stPart;
	uint32_t back_color = 0x000000ff;
	
	stPart.u16SrcOffsX = 0;
	stPart.u16SrcOffsY = 0;
	stPart.u16Width    = 1280;
	stPart.u16Height   = 480;
	vGfLayerFillArea(&GDCX_LAYER_USE, &stPart,back_color );
	vGfListExecute();
}



/**********************************************
*             Function definition             *
**********************************************/
void vInitIcons(void)
{

	gf_cliprect_st stPart;
	uint32_t back_color = 0x000000ff;
	
	stPart.u16SrcOffsX = 0;
	stPart.u16SrcOffsY = 0;
	stPart.u16Width    = 1280;
	stPart.u16Height   = 480;
	

	vGfLayerFillArea(&GDCX_LAYER_USE, &stPart,back_color );
	vGfListExecute();

	vInitIconTable();
	i32GDC_SetCommonAlpha(GDCX_USE,GDC_SEG_LAYER_A,0xff);
	vGfShowLayer(GDCX_USE, &GDCX_LAYER_USE);	
	vBLControl(BL_EN_PIN, 1, BL_ON_GP_STAT);
	vBLControl(BL_ADJ_PIN, 1, BLADJ_ON_GP_STAT);

}


void vShowPowerOnLogo(void)				/**  ??LOGO?? **/
{
	
}

void vSetIcons(void)								/**  ?????????? */
{
	gf_cliprect_st stPart;
	uint32_t back_color = 0x000000ff;
	
	stPart.u16SrcOffsX = 0;
	stPart.u16SrcOffsY = 0;
	stPart.u16Width    = 1280;
	stPart.u16Height   = 480;
	

	vGfLayerFillArea(&GDCX_LAYER_USE, &stPart,back_color );
	vGfListExecute();	
}




void vCreatBatSmall(DiyBar_st* pstTmpBar)				/**  ???? **/
{

}






void vGetNextAngle(needle_show_st* stneedle, int iInitAngle, int iSpeedLevel, int iMaxStep, float32_t f32param, uint8_t index, int flag)
{
    float32_t f32stepTmp = 0;
	float32_t f32speed_angle;
	if(flag == -1)
	{
	 	if(gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u8dp == 0)
			f32speed_angle = iInitAngle - (gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u32data & 0XFFFF) / f32param;
		else if(gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u8dp == 1)
			f32speed_angle = iInitAngle - (gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u32data / 10 & 0XFFFF) / f32param;
	}
	else 
	{
		if(gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u8dp == 0)
			f32speed_angle = iInitAngle + (gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u32data & 0XFFFF) / f32param;
		else if(gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u8dp == 1)
			f32speed_angle = iInitAngle + (gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u32data / 10 & 0XFFFF) / f32param;
		if(index == TOTAL_CURRENT_INDEX_ee)
		{
			if(gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u8dp == 0)
				f32speed_angle = iInitAngle + (30 - (gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u32data & 0XFFFF)) / f32param;
			else if(gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u8dp == 2)
				f32speed_angle = iInitAngle + (30 + (gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u32data & 0XFFFF)) / f32param;
			
		}
	}
	if(stneedle->f32CurrentDAngle != f32speed_angle)   
	{
		f32stepTmp = stneedle->f32StepAngle;
		if(stneedle->f32rota_angle < f32speed_angle)
		{  
			stneedle->f32StepAngle = ((uint32_t)(f32speed_angle - stneedle->f32rota_angle)) / iSpeedLevel + 1;
		}
		else if(stneedle->f32rota_angle > f32speed_angle)
		{
			stneedle->f32StepAngle = ((uint32_t)(stneedle->f32rota_angle - f32speed_angle)) / iSpeedLevel + 1;
		}

		if(stneedle->f32StepAngle > iMaxStep)  stneedle->f32StepAngle = iMaxStep;

		if(stneedle->f32CurrentDAngle > stneedle->f32rota_angle) stneedle->f32rota_angle += f32stepTmp;
		else if(stneedle->f32CurrentDAngle < stneedle->f32rota_angle) stneedle->f32rota_angle -= f32stepTmp;
		stneedle->f32CurrentDAngle = f32speed_angle;
	}
	else
	{
		if(stneedle->f32rota_angle < stneedle->f32CurrentDAngle)
		{  
			stneedle->f32rota_angle += stneedle->f32StepAngle;
		}
		else if(stneedle->f32rota_angle > stneedle->f32CurrentDAngle)
		{
			stneedle->f32rota_angle -= stneedle->f32StepAngle;
		}

		if(stneedle->f32rota_angle < stneedle->f32CurrentDAngle)
		{  
			if((stneedle->f32CurrentDAngle - stneedle->f32rota_angle) < stneedle->f32StepAngle)
			{
				stneedle->f32rota_angle = stneedle->f32CurrentDAngle;
			}
		}
		else if(stneedle->f32rota_angle > stneedle->f32CurrentDAngle)
		{
			if((stneedle->f32rota_angle - stneedle->f32CurrentDAngle) < stneedle->f32StepAngle)
			{
				stneedle->f32rota_angle = stneedle->f32CurrentDAngle;
			}
		}	
	}

}


needle_show_st stSpeedNeedle = {INIT_ANGLE, INIT_ANGLE, 0, 0, 0, 0, {0.0001, 0.0001}};
void vSetSpeedNeedle(void)								/**  ?????? */
{
#ifdef _NEEDLE_SPEED_ENABLE	
	vNGetNextAngle(&stSpeedNeedle, INIT_ANGLE, SPEED_LEVEL, MAX_STEP, SPEED_PARAM, NEEDLE_SPEED_INDEX_ee, 1);
	if(stSpeedNeedle.u8num > 0)
	{
		if(stSpeedNeedle.u8index < stSpeedNeedle.u8num)
		{
			if(stSpeedNeedle.u8dir == 0) stSpeedNeedle.f32rota_angle += stSpeedNeedle.f32table[stSpeedNeedle.u8index];
			else stSpeedNeedle.f32rota_angle -= stSpeedNeedle.f32table[stSpeedNeedle.u8index];
			stSpeedNeedle.u8index++;
		}
	}
	vGfLayerRotateBlendBitmapFull(&stImage_needle_speed,stSpeedNeedle.f32rota_angle, &GDCX_LAYER_USE,u16Type3XYTable[NEEDLE_SPEED_INDEX_ee - TYPE3_NUMBER_BASE][0], u16Type3XYTable[NEEDLE_SPEED_INDEX_ee - TYPE3_NUMBER_BASE][1]);
	vGfListExecute();
#endif	
}


void vShowSpeedNumber(void)
{
#ifdef _SPEED_NUMBER_ENABLE
	pt_info_st pt_info;
	pt_info.x = SPEED_NUMBER_X;
	pt_info.y = SPEED_NUMBER_Y;

	vShowNumberAT(1, (model_index_et)0, 0, 0, 46, 0, 0, pt_info,gModeData.sttype3DataTable[NEEDLE_SPEED_INDEX_ee - TYPE3_NUMBER_BASE]);
#endif
}



needle_show_st stRorateSpeedNeedle = {INIT_ANGLE_ROTATE, INIT_ANGLE_ROTATE, 0};
pt_info_st tmp;
void vShowRotateSpeed(void)
{
#ifdef _NEEDLE_ROTATE_ENABLE 
		vGetNextAngle(&stRorateSpeedNeedle, INIT_ANGLE_ROTATE, SPEED_LEVEL_ROTATE, MAX_STEP_ROTATE, SPEED_PARAM_ROTATE, ROTATE_SPEED_INDEX_ee, 1);
		vGfLayerRotateBlendBitmapFull(&stImage_needleA,stRorateSpeedNeedle.f32rota_angle, &GDCX_LAYER_USE,u16Type3XYTable[NEEDLE_ROTATE_INDEX_ee- TYPE3_NUMBER_BASE][0], u16Type3XYTable[NEEDLE_ROTATE_INDEX_ee - TYPE3_NUMBER_BASE][1]);
		vGfListExecute();
#endif
#ifdef _ROTATE_SPEED_ENABLE
	if(gModeData.u8type1Data == MOTOR_INFO_SCREEN)
	{
		vShowNumberAT(0, ROTATE_SPEED_INDEX_ee, "RPM", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
	}
#endif

}


needle_show_st stKPASpeedNeedle = {INIT_ANGLE_KPA, INIT_ANGLE_KPA, 0};
void vShowkpa(void)
{
#ifdef _NEEDLE_KPAA_ENABLE
		vGetNextAngle(&stKPASpeedNeedle, INIT_ANGLE_KPA, SPEED_LEVEL_KPA, MAX_STEP_KPA, SPEED_PARAM_KPA, NEEDLE_KPAA_INDEX_ee, 1);
		vGfLayerRotateBlendBitmapFull(&stImage_needleB,stKPASpeedNeedle.f32rota_angle, &GDCX_LAYER_USE,u16Type3XYTable[NEEDLE_KPAA_INDEX_ee- TYPE3_NUMBER_BASE][0], u16Type3XYTable[NEEDLE_KPAA_INDEX_ee - TYPE3_NUMBER_BASE][1]);
		vGfListExecute();	
#endif

}


needle_show_st stKPBSpeedNeedle = {INIT_ANGLE_KPB, INIT_ANGLE_KPB, 0};
void vShowkpb(void)
{
#ifdef _NEEDLE_KPAB_ENABLE
		vGetNextAngle(&stKPBSpeedNeedle, INIT_ANGLE_KPB, SPEED_LEVEL_KPB, MAX_STEP_KPB, SPEED_PARAM_KPB, NEEDLE_KPAB_INDEX_ee, -1);
		vGfLayerRotateBlendBitmapFull(&stImage_needleB,stKPBSpeedNeedle.f32rota_angle, &GDCX_LAYER_USE,u16Type3XYTable[NEEDLE_KPAB_INDEX_ee - TYPE3_NUMBER_BASE][0], u16Type3XYTable[NEEDLE_KPAB_INDEX_ee - TYPE3_NUMBER_BASE][1]);
		vGfListExecute();	
#endif

}


void vShowMotorPower(void)
{
	//vShowNumberAT(MOTOR_POWER_ee,font_et efont,uint32_t num,uint8_t u8pt)
}

void vShowTotalVoltage(void)
{
#ifdef _TOTAL_VOLTAGE_ENABLE
	if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
	{
		vShowNumberAT(0, TOTAL_VOLTAGE_INDEX_ee, "V", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
	}	
#endif
}

needle_show_st stCSpeedNeedle = {INIT_ANGLE_C, INIT_ANGLE_C, 0, 0, 0, 0, {0.0001, 0.0001}};
void vShowTotalCurrent(void)
{
#ifdef _TOTAL_CURRENT_ENABLE
	if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
	{
		vShowNumberAT(0, TOTAL_CURRENT_INDEX_ee, "A", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
	}
#endif

#ifdef _NEEDLE_CURRENT_ENABLE
	if(gModeData.u8type1Data == MAIN_SCREEN)
	{
		vNGetNextAngle(&stCSpeedNeedle, INIT_ANGLE_C, SPEED_LEVEL_C, MAX_STEP_C, SPEED_PARAM_C, TOTAL_CURRENT_INDEX_ee, 0);
		if(stCSpeedNeedle.u8num > 0)
			{
				if(stCSpeedNeedle.u8index < stCSpeedNeedle.u8num)
				{
					if(stCSpeedNeedle.u8dir == 0) stCSpeedNeedle.f32rota_angle += stCSpeedNeedle.f32table[stCSpeedNeedle.u8index];
					else stCSpeedNeedle.f32rota_angle -= stCSpeedNeedle.f32table[stCSpeedNeedle.u8index];
					stCSpeedNeedle.u8index++;
				}
			}	
		vGfLayerRotateBlendBitmapFull(&stImage_needle_amp,stCSpeedNeedle.f32rota_angle, &GDCX_LAYER_USE,u16Type3XYTable[NEEDLE_AMP_INDEX_ee- TYPE3_NUMBER_BASE][0], u16Type3XYTable[NEEDLE_AMP_INDEX_ee - TYPE3_NUMBER_BASE][1]);
		vGfListExecute();
	}
#endif

}


needle_show_st stSOCSpeedNeedle = {INIT_ANGLE_SOC, INIT_ANGLE_SOC, 0, 0, 0, 0, {0.0001, 0.0001}};
void vShowSOCNumber(void)
{
#ifdef _SOC_NUMBER_ENABLE
	if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
	{
		vShowNumberAT(0, SOC_NUMBER_INDEX_ee, "%", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
	}
#endif

#ifdef _NEEDLE_SOC_ENABLE
	if(gModeData.u8type1Data == MAIN_SCREEN)
	{
		vNGetNextAngle(&stSOCSpeedNeedle, INIT_ANGLE_SOC, SPEED_LEVEL_SOC, MAX_STEP_SOC, SPEED_PARAM_SOC, SOC_NUMBER_INDEX_ee, 1);
		if(stSOCSpeedNeedle.u8num > 0)
		{
			if(stSOCSpeedNeedle.u8index < stSOCSpeedNeedle.u8num)
			{
				if(stSOCSpeedNeedle.u8dir == 0) stSOCSpeedNeedle.f32rota_angle += stSOCSpeedNeedle.f32table[stSOCSpeedNeedle.u8index];
				else stSOCSpeedNeedle.f32rota_angle -= stSOCSpeedNeedle.f32table[stSOCSpeedNeedle.u8index];
				stSOCSpeedNeedle.u8index++;
			}
		}
		vGfLayerRotateBlendBitmapFull(&stImage_needle_speed,stSOCSpeedNeedle.f32rota_angle, &GDCX_LAYER_USE,u16Type3XYTable[NEEDLE_SOC_INDEX_ee - TYPE3_NUMBER_BASE][0], u16Type3XYTable[NEEDLE_SOC_INDEX_ee - TYPE3_NUMBER_BASE][1]);
		vGfListExecute();
		vfShowImageAt(stAMPImage.x, stAMPImage.y, &stImage_dial_amp);
	}
#endif
}

needle_show_st stVSpeedNeedle = {INIT_ANGLE_V, INIT_ANGLE_V, 0};   
void vShowBatteryVoltage(void)
{
#ifdef _NEEDLE_VOL_ENABLE
		vGetNextAngle(&stVSpeedNeedle, INIT_ANGLE_V, SPEED_LEVEL_V, MAX_STEP_V, SPEED_PARAM_V, BATTERY_VOLTAGE_INDEX_ee, -1);
		vGfLayerRotateBlendBitmapFull(&stImage_needleB,stVSpeedNeedle.f32rota_angle, &GDCX_LAYER_USE,u16Type3XYTable[NEEDLE_VOL_INDEX_ee- TYPE3_NUMBER_BASE][0], u16Type3XYTable[NEEDLE_VOL_INDEX_ee - TYPE3_NUMBER_BASE][1]);
		vGfListExecute();	
#endif

}

void vShowBatteryLife(void)
{
#ifdef _BATTERY_LIFE_ENABLE

#endif
}

void vShowTotalDistance(void)
{
#ifdef _TOTAL_DISTANCE_ENABLE
//	vShowNumberAT(1, TOTAL_DISTANCE_INDEX_ee, 0, 0, 14, 0, &stImage_KMd_RLE);
#endif
}

void vShowTripDistance(void)
{
#ifdef _TRIP_DISTANCE_ENABLE
//		vShowNumberAT(1, TRIP_DISTANCE_INDEX_ee, 0, 0, 14, 0, &stImage_KMd_RLE);
#endif
}

void vShowTorque(void)
{
#ifdef _TORQUE_NUMBER_ENABLE
	if(gModeData.u8type1Data == MOTOR_INFO_SCREEN)
	{
		vShowNumberAT(0, TORQUE_NUMBER_INDEX_ee, "N.M", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
	}
	
#endif
}

void vShowMotorT(void)
{
#ifdef _MOTOR_TNUMBER_ENABLE
	if(gModeData.u8type1Data == MOTOR_INFO_SCREEN)
	{
		vShowNumberAT(0, MOTOR_TNUMBER_INDEX_ee, "?", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
	}

#endif
}

void vShowControlT(void)
{
#ifdef _CONTROL_TNUMBER_ENABLE
	
if(gModeData.u8type1Data == MOTOR_INFO_SCREEN)
	{
		vShowNumberAT(0, CONTROL_TNUMBER_INDEX_ee, "?", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
	}
	
#endif
}


void vShowBatteryMaxV(void)
{
#ifdef _BATTERY_MAX_VOLTAGE_ENABLE
if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
{
	vShowNumberAT(0, BATTERY_MAX_VOLTAGE_INDEX_ee, "V", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
}

#endif
}

void vShowBatteryMinV(void)
{
#ifdef _BATTERY_MIN_VOLTAGE_ENABLE
if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
{
	vShowNumberAT(0, BATTERY_MIN_VOLTAGE_INDEX_ee, "V", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
}
#endif
}


void vShowBatteryDropV(void)
{
	//
}

void vShowBatteryDropT(void)
{
#ifdef _BATTERY_DROPOUT_T_ENABLE
if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
{

	vShowNumberAT(0, BATTERY_DROPOUT_T_INDEX_ee, "?", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
}
#endif
}

void vShowChargeTime(void)
{
#ifdef _CHARGE_TIME_ENABLE
	vShowNumberAT(CHARGE_TIME_INDEX_ee,FONT2418_ee,(gModeData.sttype3DataTable[CHARGE_TIME_INDEX_ee - TYPE3_NUMBER_BASE].u32data & 0xffff) / 60,0);
	vShowNumberAT(CHARGE_TIME_M_INDEX_ee,FONT2418_ee,(gModeData.sttype3DataTable[CHARGE_TIME_INDEX_ee - TYPE3_NUMBER_BASE].u32data & 0xffff) % 60,0);
#endif
}


void vShowBatteryT(void)
{
#ifdef _BATTERY_T_ENABLE
	if(u8MenuIndex == 0)
		vShowNumberAT(BATTERY_T_INDEX_ee,FONT0816_ee,gModeData.sttype3DataTable[BATTERY_T_INDEX_ee - TYPE3_NUMBER_BASE].u32data,gModeData.sttype3DataTable[BATTERY_T_INDEX_ee - TYPE3_NUMBER_BASE].u8dp);
#endif
}

void vShowDCACT(void)
{
#ifdef _DCAC_T_ENABLE
	if(u8MenuIndex == 0)
		vShowNumberAT(DCAC_T_INDEX_ee,FONT0816_ee,gModeData.sttype3DataTable[DCAC_T_INDEX_ee - TYPE3_NUMBER_BASE].u32data,gModeData.sttype3DataTable[DCAC_T_INDEX_ee - TYPE3_NUMBER_BASE].u8dp);
#endif
}


void vShowUPST(void)
{
#ifdef _UPS_T_ENABLE
	if(u8MenuIndex == 0)
		vShowNumberAT(UPS_T_INDEX_ee,FONT0816_ee,gModeData.sttype3DataTable[UPS_T_INDEX_ee - TYPE3_NUMBER_BASE].u32data,gModeData.sttype3DataTable[UPS_T_INDEX_ee - TYPE3_NUMBER_BASE].u8dp);
#endif
}



void vShowBatteryMaxT(void)
{
#ifdef _BATTERY_MAX_T_ENABLE
if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
{
	vShowNumberAT(0, BATTERY_MAX_T_INDEX_ee, "?", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
}
#endif
}
	
void vShowBatteryMinT(void)
{
#ifdef _BATTERY_MIN_T_ENABLE
if(gModeData.u8type1Data == BATTERY_INFO_SCREEN)
{
	vShowNumberAT(0, BATTERY_MIN_T_INDEX_ee, "?", 0, 14, 0, 0,tmp,gModeData.sttype3DataTable[0]);
}
#endif
}

//uint8_t u8alphaSave = 0xff;
void vShowAlphaChange(void)
{
/*
	if((gModeData.sttype3DataTable[ALPHA_DATA_INDEX_ee - TYPE3_NUMBER_BASE].u32data & 0XFF) != u8alphaSave)
	{
		i32GDC_SetCommonAlpha(GDCX_USE,GDC_SEG_LAYER_B,gModeData.sttype3DataTable[ALPHA_DATA_INDEX_ee - TYPE3_NUMBER_BASE].u32data & 0XFF);
		u8alphaSave = (gModeData.sttype3DataTable[ALPHA_DATA_INDEX_ee - TYPE3_NUMBER_BASE].u32data & 0XFF);
	}*/
}

void vShowCurrentTime(void)
{
#ifdef _CURRENT_TIME_ENABLE

	uint16_t tmpx, tmpy;
	uint8_t timetable[6] = {0,0,0,0,0,0};
	uint8_t hour, minute;
	
	tmpx = u16Type3XYTable[CURRENT_TIME_INDEX_ee - TYPE3_NUMBER_BASE][0];
	tmpy = u16Type3XYTable[CURRENT_TIME_INDEX_ee - TYPE3_NUMBER_BASE][1];

	hour = gModeData.sttype3DataTable[CURRENT_TIME_INDEX_ee - TYPE3_NUMBER_BASE].u32data / 60;
	minute = gModeData.sttype3DataTable[CURRENT_TIME_INDEX_ee - TYPE3_NUMBER_BASE].u32data - hour * 60;
	sprintf((char *)timetable, "%02d:%02d", hour, minute);

	vShowString(tmpx - 30,tmpy,timetable);

#endif

}


/*************************************************???**********************************/
DiyBar_st  DiyBarS2truct = {532, 287, 8, 0 ,1, 1};

void vChargeMode(void)
{
	uint32_t tmp = 0;
	uint32_t divx = 1;
	uint8_t i;
	uint8_t tmp2;
//	pt_info_st tmpxy;

	if(u8IconConfigTable[(CHARGE_MODE_INDEX_ee- TYPE2_NUMBER_BASE)] != 0)
	{
		if(gModeData.u8type2DataTable[ERR_WORD_INDEX_ee - TYPE2_NUMBER_BASE] != 0) return;
		if(gModeData.u8type2DataTable[CHARGE_MODE_INDEX_ee - TYPE2_NUMBER_BASE] == 0) return;
		
		if((gModeData.sttype3DataTable[SOC_NUMBER_INDEX_ee - TYPE3_NUMBER_BASE].u8dp & 0x80) != 0x80)
		{
			tmp = gModeData.sttype3DataTable[SOC_NUMBER_INDEX_ee - TYPE3_NUMBER_BASE].u32data;
			tmp2 = gModeData.sttype3DataTable[SOC_NUMBER_INDEX_ee - TYPE3_NUMBER_BASE].u8dp & 0x7f;
			for(i = 0;i < tmp2;i++)
			{
				divx *= 10;
			}
			tmp = tmp / divx;
			DiyBarS2truct.u8CurrentLevel = (uint8_t)(tmp * DiyBarS2truct.u8MaxLevel / 100.0 + 0.5);
		}
		
		vCreatBatSmall(&DiyBarS2truct);
/***************************************************************************************/

//		vShowMsgAt(502,160,&stImage_cdms_RLE);
//		switch(gModeData.u8type2DataTable[CHARGE_MODE_INDEX_ee - TYPE2_NUMBER_BASE])
//		{
//			case 1: vShowMsgAt(502,188,&stImage_mscd_RLE); break;
//			case 2: vShowMsgAt(502,188,&stImage_ptcd_RLE); break;
//			case 3: vShowMsgAt(502,188,&stImage_kscd_RLE); break;
//			default: break;
//		}
//		vShowMsgAt(614,160,&stImage_cdwcqk_RLE);

//		vShowNumberAT(0,CHARGE_CURRENT_INDEX_ee,"A",0,14,&stImage_cddl_RLE,0);
//		vShowNumberAT(0,CHARGE_VOLTAGE_INDEX_ee,"V",0,14,&stImage_cddy_RLE,0);

//		tmpxy.x = u16Type3XYTable[BATTERY_MAX_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][0];
//		tmpxy.y = u16Type3XYTable[BATTERY_MAX_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][1];
//		u16Type3XYTable[BATTERY_MAX_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][0] = 610;
//		u16Type3XYTable[BATTERY_MAX_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][1] = 236;
//		vShowNumberAT(0,BATTERY_MAX_VOLTAGE_INDEX_ee,"V",0,14,&stImage_zgdy_RLE,0);
//		u16Type3XYTable[BATTERY_MAX_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][0] = tmpxy.x;
//		u16Type3XYTable[BATTERY_MAX_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][1] = tmpxy.y;
//		

//		tmpxy.x = u16Type3XYTable[BATTERY_MIN_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][0];
//		tmpxy.y = u16Type3XYTable[BATTERY_MIN_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][1];
//		u16Type3XYTable[BATTERY_MIN_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][0] = 610;
//		u16Type3XYTable[BATTERY_MIN_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][1] = 260;
//		vShowNumberAT(0,BATTERY_MIN_VOLTAGE_INDEX_ee,"V",0,14,&stImage_zddy_RLE,0);
//		u16Type3XYTable[BATTERY_MIN_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][0] = tmpxy.x;
//		u16Type3XYTable[BATTERY_MIN_VOLTAGE_INDEX_ee - TYPE3_NUMBER_BASE][1] = tmpxy.y;

	}
}








DiyBar_st  DiyBarStruct = {634, 269, 8, 0 ,1, 1};
uint8_t u8PowerDir = 0;    //  0: 0 - 1 - 2   1: 0  -  2 - 1
void vShowPowerUse(void)
{
#ifdef _POWERREUSE_ENABLE

#endif
}




void vShowPRNDS(void)
{
	uint16_t tmpx;
	if((u8IconConfigTable[(PRNDS_INDEX_ee - TYPE2_NUMBER_BASE)]) != 0)
	{
		
		if(gModeData.u8type2DataTable[PRNDS_INDEX_ee - TYPE2_NUMBER_BASE] > 0)
		{
			tmpx = u16Type2XYTable[PRNDS_INDEX_ee - TYPE2_NUMBER_BASE][0];// + stImage_LEV[0].u16Width * (gModeData.u8type2DataTable[PRNDS_INDEX_ee - TYPE2_NUMBER_BASE] - 1);
			u32GfLayerBlendBitmapFull(&stImage_LEV[gModeData.u8type2DataTable[PRNDS_INDEX_ee - TYPE2_NUMBER_BASE] - 1], &GDCX_LAYER_USE, tmpx, u16Type2XYTable[PRNDS_INDEX_ee - TYPE2_NUMBER_BASE][1]);
			vGfListExecute();
		}
	}
}

void vShowErrWord(void)
{
	uint8_t tmp;
	if((u8IconConfigTable[(ERR_WORD_INDEX_ee - TYPE2_NUMBER_BASE)]) != 0)
	{
		if(gModeData.u8type2DataTable[ERR_WORD_INDEX_ee - TYPE2_NUMBER_BASE] != 0 && gModeData.u8type2DataTable[ERR_WORD_INDEX_ee - TYPE2_NUMBER_BASE] < 20)
		{
			tmp = gModeData.u8type2DataTable[ERR_WORD_INDEX_ee - TYPE2_NUMBER_BASE];
			vfShowImageAt(u16Type2XYTable[ERR_WORD_INDEX_ee - TYPE2_NUMBER_BASE][0] - stImage_ERR[tmp].u16Width / 2,u16Type2XYTable[ERR_WORD_INDEX_ee - TYPE2_NUMBER_BASE][1],&stImage_ERR[tmp]);	
		}
	}
}

uint16_t u16SavePwmDuty = 1;
void vSetBlPwmFunc(void)
{
	if((u8IconConfigTable[(BL_ADJ_LEVEL_INDEX_ee- TYPE2_NUMBER_BASE)]) != 0)
	{
		if(gModeData.u8type2DataTable[BL_ADJ_LEVEL_INDEX_ee - TYPE2_NUMBER_BASE] > 0 && gModeData.u8type2DataTable[BL_ADJ_LEVEL_INDEX_ee - TYPE2_NUMBER_BASE] < 10)
		{
			if(u16SavePwmDuty != gModeData.u8type2DataTable[BL_ADJ_LEVEL_INDEX_ee - TYPE2_NUMBER_BASE])
			{
				vTIMER_PWM_SetDuty(TIMER_PWM_CNTRL_19,BL_ADJ_PWM_LEVEL_PARAM * (gModeData.u8type2DataTable[BL_ADJ_LEVEL_INDEX_ee - TYPE2_NUMBER_BASE]));
				u16SavePwmDuty = gModeData.u8type2DataTable[BL_ADJ_LEVEL_INDEX_ee - TYPE2_NUMBER_BASE];
			}
		}
	}	
}

void vRunIconFunction(void)
{
	uint8_t i= 0;
	pt_info_st pt_info;
	all_data_st all_data_adc1;
	for(i = 0;i < TYPE2_NUMBER;i++)
	{
		if(u8IconConfigTable[i] != 0)
		{
			if(gModeData.u8type2DataTable[i] > 0x00)
			{
				if(stIconTable[i][1] != 0)
				{
					u32GfLayerBlendBitmapFull(stIconTable[i][1],&GDCX_LAYER_USE,u16Type2XYTable[i][0],u16Type2XYTable[i][1]);
					vGfListExecute();
				
					if(i == (DOOR_INDEX_ee - TYPE2_NUMBER_BASE))
					{
						vfShowImageAt(546,325,&stImage_door_d[gModeData.u8type2DataTable[i]]);
					}
				}
			}
			else if(gModeData.u8type2DataTable[i] == 0x00)
			{
				if((ICON_OFF_SHOW == 1) && (stIconTable[i][0] != 0))
				{
					u32GfLayerBlendBitmapFull(stIconTable[i][0],&GDCX_LAYER_USE,u16Type2XYTable[i][0],u16Type2XYTable[i][1]);
					vGfListExecute();
				}
			}
		}
		
	}
	vShowPRNDS();
	vShowErrWord();
	vSetBlPwmFunc();
	vShowPowerUse();
	vChargeMode();
	vADC_StartConversion();

	pt_info.x = 0;
	pt_info.y = 0;
	all_data_adc1.u32data = u16ADC1Result;
	all_data_adc1.u8dp = 0;
	

	vShowNumberAT(0,(model_index_et)0,0,0,14,0,0,pt_info,all_data_adc1);

	
}

/************************************IO ??*************************************/


#if defined(__GHS__) || defined(__ghs__)
__interrupt void vADCISR_Func(void)
#else
__irq void vADCISR_Func(void)
#endif /* defined(__GHS__) || defined(__ghs__) */
{
	uint16_t tmp_result;
    if(C_SUCCESS == i8ADC_ReadResult(ADC1, &tmp_result))
    {
		u16ADC1Result = tmp_result;
	}
	else
	{
		
	}
	
    vINTC_ModifyIrqLevel(INTC_RESTORE_OLD, INTC_LEVEL_7);
}






void vInitPanelPin(void)
{
#ifdef TEST_ADC_PIN
	adc_conversion_config adc_config;
#endif

#ifdef BL_ADJ_PIN
	timer_pwm_Cfg_st stpwmCfg;
#endif


#ifdef BL_EN_PIN
    i32GPIO_SetPinFunction(BL_EN_PIN, 0);
	i32GPIO_EnablePullUp(BL_EN_PIN, GPIO_DISABLE);
	i32GPIO_EnableLatchFunction(BL_EN_PIN, GPIO_DISABLE);
	i32GPIO_SetPinDirection(BL_EN_PIN, GPIO_OUTPUT);
#endif

#ifdef BL_ADJ_PIN
    i32GPIO_SetPinFunction(BL_ADJ_PIN, 5);
	i32GPIO_EnablePullUp(BL_ADJ_PIN, GPIO_DISABLE);
	i32GPIO_EnableLatchFunction(BL_ADJ_PIN, GPIO_DISABLE);
	i32GPIO_EnablePullDown(PORT_ADC_IN0,GPIO_DISABLE);

	stpwmCfg.eClkSrc = TIMER_PWM_PRESCAL;
	stpwmCfg.eDblBuffEn = TIMER_PWM_ENABLE;
	stpwmCfg.eIrqEn = TIMER_PWM_DISABLE;
	stpwmCfg.eOutLevel = TIMER_PWM_LEVEL_HI;
	stpwmCfg.ePrescalClk = TIMER_PWM_SCLK_DIV64;
	stpwmCfg.eRst = TIMER_PWM_PDR_ONLY;
	boTIMER_PWM_Config(TIMER_PWM_CNTRL_19,stpwmCfg);

	vTIMER_PWM_SetDuty(TIMER_PWM_CNTRL_19,BL_ADJ_PWM_LEVEL_PARAM * 9);
	vTIMER_PWM_SetPeriod(TIMER_PWM_CNTRL_19, 11710);
	vTIMER_PWM_Enable(TIMER_PWM_CNTRL_19, TIMER_PWM_ENABLE);	
#endif

#ifdef PANEL_PIN
	i32GPIO_SetPinFunction(PANEL_PIN, 0);
	i32GPIO_EnablePullUp(PANEL_PIN, GPIO_DISABLE);
	i32GPIO_EnableLatchFunction(PANEL_PIN, GPIO_DISABLE);
	i32GPIO_SetPinDirection(PANEL_PIN, GPIO_OUTPUT);
#endif

#ifdef TEST_ADC_PIN
	i32GPIO_SetPinFunction(TEST_ADC_PIN, PORT_ADC_IN1_AS_ADC_IN1);
	i32GPIO_EnablePullUp(TEST_ADC_PIN, GPIO_DISABLE);
	i32GPIO_EnablePullDown(TEST_ADC_PIN,GPIO_DISABLE);
	i32GPIO_EnableLatchFunction(TEST_ADC_PIN, GPIO_DISABLE);

	i32ADC_InputChannelSelection(ADC_CONVERSION_MODE, ADC1);

	adc_config.eChannelScanMode = ADC_ONE_CHANNEL_MODE;
	adc_config.eDelayedMode = ADC_START_AFTER_READ;
	adc_config.eDevice = ADC1;
	adc_config.eInterruptGenerationMode = ADC_INTERRUPT_AFTER_EACH_CONVERSION;
	adc_config.eRepeatMode = ADC_SINGLE_CONVERSION;
	adc_config.eTriggerType = ADC_SOFTWARE_TRIGGER;
	vADC_AdcConversionConfig(adc_config);

	/* configure interrupt modes */
	i32INTC_SourceConfig(INTC_ADC_CC, INTC_TO_CPU, INTC_EDGE_RISE, INTC_LEVEL_2, INTC_AUTO_CLEAR_ENABLE);

	/* set callback function for tick timer IRQ */
	vINTC_SetISRStartAddress(INTC_ADC_CC, (uint32_t)&vADCISR_Func);

	vADC_StartConversion();


	i32GPIO_SetPinFunction(PORT_HSPWM1N, PORT_HSPWM1N_AS_GPIO);
	i32GPIO_EnableLatchFunction(PORT_HSPWM1N, GPIO_DISABLE);
	i32GPIO_EnablePullUp(PORT_HSPWM1N, GPIO_DISABLE);
	i32GPIO_SetPinDirection(PORT_HSPWM1N, GPIO_OUTPUT);

	i32GPIO_SetPinFunction(PORT_SC4_C0_LEFT, PORT_SC4_C0_LEFT_AS_GPIO);
	i32GPIO_EnableLatchFunction(PORT_SC4_C0_LEFT, GPIO_DISABLE);
	i32GPIO_EnablePullUp(PORT_SC4_C0_LEFT, GPIO_DISABLE);
	i32GPIO_SetPinDirection(PORT_SC4_C0_LEFT, GPIO_OUTPUT);
	i32GPIO_SetPinState(PORT_SC4_C0_LEFT,GPIO_LOW);
	
#endif


}



/**
	BL_EN   
	??, ? or ?  1?  0?
*/
void vBLControl(gpio_portpin_e ePin, uint8_t u8stat, uint8_t u8flagon)
{
	if(ePin != (gpio_portpin_e)0)
	{
		if(u8stat == 0x1)  //?
		{
			i32GPIO_SetPinState(ePin,(gpio_state_e)u8flagon);
		}
		else if(u8stat == 0x0)
		{
			i32GPIO_SetPinState(ePin, (gpio_state_e)(GPIO_HIGH - u8flagon));
		}
	}
}


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
  conditions set forth in the ?andling Guide for Semiconductor Devices, or
  TOSHIBA Semiconductor Reliability Handbook etc..

- The Toshiba products listed in this document are intended for usage in
  general electronics applications (computer, personal equipment,
  office equipment, measuring equipment,industrial robotics, domestic
  appliances, etc.). These Toshiba products are neither intended nor
  warranted for usage in equipment that requires extraordinarily high quality
  and/or reliability or a malfunction or failure of which may cause loss
  of human life or bodily injury (?nintended Usage).
  Unintended Usage include atomic energy control instruments, airplane or
  spaceship instruments, transportation instruments, traffic signal
  instruments, combustion control instruments, medical instruments,
  all types of safety devices, etc..
  Unintended Usage of Toshiba products listed in this document shall be made
  at the customer? own risk.

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
* $Log: icons.c,v $
* Revision 1.1  2014/05/09 14:05:53  mto
* initial version
*
*
*********************************** END OF LOG ******************************/
