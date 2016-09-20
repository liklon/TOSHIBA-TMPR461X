/**
   ??????,??mydef.h????
   ???????????,???????????,???????,????????????
*/
#include "mydef.h"
#include "icons.h"
#include "images_defs.h"
#include "images_externs.h"
#include "Gfunctions.h"
#include "listmngr.h"





void vShowInit(void);


/**
	???????
	???????,?mydef.h????????????
*/
uint16_t u16Type2XYTable[TYPE2_NUMBER][2] = 
{
	{624,60},	//??
	{863,329},    //READY
	{420,15}, //??
	{443,100},	 //????
	{792,100},	 //????
	{476,15}, //???
	{458,60},	 //???
	{405,60}, //???
	{360,15}, //???
	{467,428}, //???
	{410,380},	//??  10
	{365,428},	//ASB
	{455,380},	//????
	{444,332},	//????
	{883,15}, //????
	{827,60}, //????
	{773,60}, //????
	{824,15}, //??????
	{896,371}, //SOC
	{872,428}, //????
	{819,428},  //??????  20
	{725,60},  //??
	{786,332}, //DCDC????
	{821,380}, //??????
	{762,15}, //????
	{417,428}, //EPS
	{1,1}, //????
	{762,380},	//????
	{640,170},	//	??????
	{783,428},  //???
	{1,1},   //BL_ADJ_LEVEL_INDEX_ee
	{522,120},   //CHARGE_MODE
};

/**
	???????
	???????,?mydef.h????????????
*/

uint16_t u16Type3XYTable[TYPE3_NUMBER][2] = 
{
	{151,99},   //????
	{1042,173}, //	??
	{1,1},	//	??
	{282,93}, //	???
	{1120,93}, //	???
	{282,175}, //	SOC
	{1,1},	//	????????????????
	{1030,360},	//	????
	{245,380},	//	???
	{245,350},	//	????
	{1042,256}, //	????
	{230,173}, //	????
	{230,256}, //	?????
	{282,257}, //	??????
	{282,338}, //	??????
	{1,1},	//	??????????????????????????
	{1120,338}, //	????
	{1112,72},	//	????h
	{1120,175}, //??????
	{1120,257}, //??????
	{658,286}, //battery_t   5b
	{734, 215},  //POWERREUSE_INDEX_ee
	{610, 188},  //CHARGE_CURRENT
	{610, 212},  //CHARGE_VOLTAGE
	{935,98},  //SOC??
	{1019,234},     //amp
};

int32_t u32Type3MinMaxTable[TYPE3_NUMBER][2] = 
{
	{0,260},   //????
	{0,999999}, //	??
	{1,1},	//	??
	{0,999}, //	???
	{-30,30}, //	???
	{0,100}, //	SOC
	{0,99},	//	????
	{0,999},	//	????
	{0,600000},	//	???
	{0,999},	//	????
	{0,9999}, //	????
	{0,200}, //	????
	{0,200}, //	?????
	{0,99}, //	??????
	{0,99}, //	??????
	{1,1},	//	????
	{0,200}, //	????
	{0,999},	//	????h
	{0,50}, //??????
	{0,50}, //??????
	{1,1}, //battery_t   5b
	{-100, 100},       //POWERREUSE_INDEX_ee
	{0, 100},
	{0, 1000},
	{1,1},  //SOC??
	{1,1},     //amp
};



/**
	???????
*/
vRunFun_t gRunFunTable[FUNCTION_NUMBER] =
{
	vSetIcons,  //clear all
	vShowInit,
	vSetSpeedNeedle,  //??????
	vShowSpeedNumber, //????,????
	vShowRotateSpeed,
	vShowMotorPower,
	vShowTotalVoltage,
	vShowSOCNumber,
	vShowTotalCurrent,
	vShowBatteryVoltage,
	vShowBatteryLife,
	vShowTotalDistance,
	vShowTripDistance,
	vShowTorque,
	vShowMotorT,
	vShowControlT,
	vShowBatteryMaxV,
	vShowBatteryMinV,
	vShowBatteryDropV,
	vShowBatteryDropT,
	vShowChargeTime,
	vShowBatteryMaxT,
	vShowBatteryMinT,
	vShowkpa,
	vShowkpb,
	vShowAlphaChange,
	vShowBatteryT,
	vShowDCACT,
	vShowUPST,
	vShowCurrentTime,
	vRunIconFunction,
	0,
};

uint8_t u8MenuIndex = 0;



/**
	????????,?????????????????
*/
pt_info_st stSpeedImage = {26, 23};
pt_info_st stSOCImage = {812, 23};
pt_info_st stAMPImage = {954, 205};



uint16_t SPEED_NUMBER_X = 246;
uint16_t SPEED_NUMBER_Y = 214;


void vShowInit(void)
{

	vfShowImageAt(stSpeedImage.x,stSpeedImage.y,&stImage_dial_speed);
	vfShowImageAt(stSOCImage.x,stSOCImage.y,&stImage_dial_soc);
}




/**
    ???????
*/
void vInitAllData(void)
{
	uint8_t i = 0;
	for(i = 0;i < TYPE3_NUMBER;i++)
	{
		gModeData.sttype3DataTable[i].u32data = 0;
		gModeData.sttype3DataTable[i].u8dp = 0;

	}	

	gModeData.u8type1Data = 0;

    gModeData.u8type2DataTable[ERR_WORD_INDEX_ee- TYPE2_NUMBER_BASE] = 0;
	gModeData.u8type2DataTable[CHARGE_MODE_INDEX_ee - TYPE2_NUMBER_BASE] = 0;
	
	u8IconConfigTable[0] = PRNDS_CF;
	u8IconConfigTable[1] = READY_CF;
	u8IconConfigTable[2] = SMALLLIGHT_CF;
	u8IconConfigTable[3] = LED_ON_OFF_LEFT_CF;
	u8IconConfigTable[4] = LED_ON_OFF_RIGHT_CF;
	u8IconConfigTable[5] = F_FOGLAMP_CF;
	u8IconConfigTable[6] = A_FOGLAMP_CF;
	u8IconConfigTable[7] = HIGHBEAM_CF;
	u8IconConfigTable[8] = DIPPEDHEADLIGHT_CF;
	u8IconConfigTable[9] = SAFETYBELT_CF;
	u8IconConfigTable[10] = AIRBAG_CF;
	u8IconConfigTable[11] = ASB_CF;
	u8IconConfigTable[12] = BRAKEFLUID_CF;
	u8IconConfigTable[13] = PARKING_CF;
	u8IconConfigTable[14] = MOTORERR_CF;
	u8IconConfigTable[15] = MOTOROT_CF;
	u8IconConfigTable[16] = MOTORSPEED_CF;
	u8IconConfigTable[17] = POWERBATTERY_CF;
	u8IconConfigTable[18] = SOC_CF;
	u8IconConfigTable[19] = CHARGE_CF;
	u8IconConfigTable[20] = CHARGPLUG_CF;
	u8IconConfigTable[21] = DOOR_CF;
	u8IconConfigTable[22] = DCDC_CF;
	u8IconConfigTable[23] = POWERBATTERYCUT_CF;
	u8IconConfigTable[24] = SYSTEMERR_CF;
	u8IconConfigTable[25] = EPS_CF;
	u8IconConfigTable[26] = PARKING_ERR_CF;
	u8IconConfigTable[27] = CARLOCK_CF;
	u8IconConfigTable[28] = ERR_WORD_CF;
	u8IconConfigTable[29] = INSULATIONERR_CF;
	u8IconConfigTable[30] = BL_ADJ_LEVEL_CF;
	u8IconConfigTable[31] = CHARGE_MODE_CF;
}



/**
	??????
*/
DiyBar_st stBatTable[4] = {
{56,227,8,5},   //???
{151,227,8,4},  //???
{244,227,8,3},  //SOC
{335,227,8,2}  //????
};



/**
	??????????????,??????,??????????
*/
gf_image_st* stIconTable[TYPE2_NUMBER][2];
void vInitIconTable(void)
{
		stIconTable[0][0] = 0; stIconTable[0][1] = 0;	 //??????? 
		stIconTable[1][0] = 0;	 stIconTable[1][1] = &stImage_sspic19;	   //ready
		stIconTable[2][0] = 0; stIconTable[2][1] = &stImage_sspic0;   //??
		stIconTable[3][0] = 0;	stIconTable[3][1] = &stImage_sspic3;   //????
		stIconTable[4][0] = 0; stIconTable[4][1] = &stImage_sspic6;   //????
		stIconTable[5][0] = 0; stIconTable[5][1] = &stImage_sspic2;  //???
		stIconTable[6][0] = 0; stIconTable[6][1] = &stImage_sspic5;  //???
		stIconTable[7][0] = 0; stIconTable[7][1] = &stImage_sspic4;  //???
		stIconTable[8][0] = 0; stIconTable[8][1] = &stImage_sspic0;  //???	
		stIconTable[9][0] = 0; stIconTable[9][1] = &stImage_sspic18;  //???
		stIconTable[10][0] = 0; stIconTable[10][1] = &stImage_sspic14;	//??
		stIconTable[11][0] = 0; stIconTable[11][1] = &stImage_sspic16;	//ABS
		stIconTable[12][0] = 0; stIconTable[12][1] = &stImage_sspic15;	 //???? 	
		stIconTable[13][0] = 0; stIconTable[13][1] = &stImage_sspic13;	  //????
		stIconTable[14][0] = 0; stIconTable[14][1] = &stImage_sspic9;	//????
		stIconTable[15][0] = 0; stIconTable[15][1] = &stImage_sspic11;	   //????
		stIconTable[16][0] = 0; stIconTable[16][1] = &stImage_sspic10;	  //????
		stIconTable[17][0] = 0; stIconTable[17][1] = &stImage_sspic8;	//???????
		stIconTable[18][0] = 0; stIconTable[18][1] = &stImage_sspic12;	 //SOC
		stIconTable[19][0] = 0; stIconTable[19][1] = &stImage_sspic26;	//????
		stIconTable[20][0] = 0; stIconTable[20][1] = &stImage_sspic25;	   //????
		stIconTable[21][0] = 0; stIconTable[21][1] = &stImage_sspic21;	//??
		stIconTable[22][0] = 0; stIconTable[22][1] = &stImage_sspic20;	 //DCDC????
		stIconTable[23][0] = 0; stIconTable[23][1] = &stImage_sspic23;	//??????
		stIconTable[24][0] = 0; stIconTable[24][1] = &stImage_sspic7;	 //????
		stIconTable[25][0] = 0; stIconTable[25][1] = &stImage_sspic17;	//EPS
		stIconTable[26][0] = 0; stIconTable[26][1] = 0; 	//???? 
		stIconTable[27][0] = 0; stIconTable[27][1] = &stImage_sspic22;	 //??
		stIconTable[28][0] = 0; stIconTable[28][1] = 0;    //??
		stIconTable[29][0] = 0; stIconTable[29][1] = &stImage_sspic24;	//???
		stIconTable[30][0] = 0; stIconTable[30][1] = 0;  //
		stIconTable[31][0] = 0; stIconTable[31][1] = 0;  //

}



















