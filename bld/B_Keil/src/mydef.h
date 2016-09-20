
#ifndef __MYDEF_H__
#define __MYDEF_H__


#include "captypes.h" 
#include "gf.h"
#include "gpio.h"

#define GDCX_USE	GDC0
#define GDCX_LAYER_USE	stGDC0LayerA



/**
	??????????
*/
typedef enum model_e_index
{
	POWER_ON_LOGO_INDEX_ee = 0x01,
	MAIN_SCREEN_INDEX_ee,
	WAKE_UP_SCREEN_INDEX_ee,
	POWER_DOWN_INDEX_ee,
	BATTERY_INFO_INDEX_ee,
	MOTOR_INFO_INDEX_ee,
	SCREEN_INDEX_NUMBER_ee,

	PRNDS_INDEX_ee = 0X11,
	READY_INDEX_ee,
	SMALLLIGHT_INDEX_ee,
	LED_ON_OFF_LEFT_INDEX_ee,
	LED_ON_OFF_RIGHT_INDEX_ee,
	F_FOGLAMP_INDEX_ee,
	A_FOGLAMP_INDEX_ee,
	HIGHBEAM_INDEX_ee,
	DIPPEDHEADLIGHT_INDEX_ee,
	SAFETYBELT_INDEX_ee,
	AIRBAG_INDEX_ee,
	ASB_INDEX_ee,
	BRAKEFLUID_INDEX_ee,
	PARKING_INDEX_ee,
	MOTORERR_INDEX_ee,
	MOTOROT_INDEX_ee,     //0x20
	MOTORSPEED_INDEX_ee,
	POWERBATTERY_INDEX_ee,
	SOC_INDEX_ee,
	CHARGE_INDEX_ee,
	CHARGPLUG_INDEX_ee,
	DOOR_INDEX_ee,
	DCDC_INDEX_ee,
	POWERBATTERYCUT_INDEX_ee,
	SYSTEMERR_INDEX_ee,
	EPS_INDEX_ee,
	PARKING_ERR_INDEX_ee,
	CARLOCK_INDEX_ee,
	ERR_WORD_INDEX_ee,
	INSULATIONERR_INDEX_ee,
	BL_ADJ_LEVEL_INDEX_ee,
	CHARGE_MODE_INDEX_ee,
	ICON_TOTAL_NUMBER_ee,

    NEEDLE_SPEED_INDEX_ee = 0X41,
    ROTATE_SPEED_INDEX_ee,
    MOTOR_POWER_INDEX_ee,
    TOTAL_VOLTAGE_INDEX_ee,
	TOTAL_CURRENT_INDEX_ee,
	SOC_NUMBER_INDEX_ee,
	BATTERY_VOLTAGE_INDEX_ee,
	BATTERY_LIFE_INDEX_ee,
	TOTAL_DISTANCE_INDEX_ee,
	TRIP_DISTANCE_INDEX_ee,
	TORQUE_NUMBER_INDEX_ee,
	MOTOR_TNUMBER_INDEX_ee,
	CONTROL_TNUMBER_INDEX_ee,
	BATTERY_MAX_VOLTAGE_INDEX_ee,
	BATTERY_MIN_VOLTAGE_INDEX_ee,
	BATTERY_DROPOUT_V_INDEX_ee,   //0x50
	BATTERY_DROPOUT_T_INDEX_ee,
	CHARGE_TIME_INDEX_ee,
	BATTERY_MAX_T_INDEX_ee,
	BATTERY_MIN_T_INDEX_ee,  
	BATTERY_T_INDEX_ee, 
    POWERREUSE_INDEX_ee,
	CHARGE_CURRENT_INDEX_ee,
	CHARGE_VOLTAGE_INDEX_ee,
	NEEDLE_SOC_INDEX_ee,
	NEEDLE_AMP_INDEX_ee,
	CONTROLLER_LIFE_INDEX_ee,
	CONTROLLER_STATUS_INDEX_ee,
	OPEN_ACCELERATE_INDEX_ee,
	OPEN_DECELERATE_INDEX_ee,
	TYPE3_TOTAL_NUMBER_ee,
	
}model_index_et;

/**********************************************???????,?????????**************************************************/

#define _NEEDLE_SPEED_ENABLE      //NEEDLE_SPEED_INDEX_ee
#define _SPEED_NUMBER_ENABLE

#define _ROTATE_SPEED_ENABLE      //ROTATE_SPEED_INDEX_ee,
//#define _NEEDLE_ROTATE_ENABLE      //NEEDLE_ROTATE_INDEX_ee,


//#define _MOTOR_POWER_ENABLE       //MOTOR_POWER_INDEX_ee,
#define _TOTAL_VOLTAGE_ENABLE     //TOTAL_VOLTAGE_INDEX_ee,
#define _TOTAL_CURRENT_ENABLE       //TOTAL_CURRENT_INDEX_ee,
#define _NEEDLE_CURRENT_ENABLE	//NEEDLE_AMP_INDEX_ee
#define _SOC_NUMBER_ENABLE          //SOC_NUMBER_INDEX_ee,
#define _NEEDLE_SOC_ENABLE      //NEEDLE_SOC_INDEX_ee,

//#define _BATTERY_VOLTAGE_ENABLE       //BATTERY_VOLTAGE_INDEX_ee,
//#define _NEEDLE_VOL_ENABLE         //NEEDLE_VOL_INDEX_ee,


#define _BATTERY_LIFE_ENABLE      //BATTERY_LIFE_INDEX_ee,
#define _TOTAL_DISTANCE_ENABLE      //TOTAL_DISTANCE_INDEX_ee,
#define _TRIP_DISTANCE_ENABLE      //TRIP_DISTANCE_INDEX_ee,
#define _TORQUE_NUMBER_ENABLE      //TORQUE_NUMBER_INDEX_ee,
#define _MOTOR_TNUMBER_ENABLE      //MOTOR_TNUMBER_INDEX_ee,
#define _CONTROL_TNUMBER_ENABLE      //CONTROL_TNUMBER_INDEX_ee,
#define _BATTERY_MAX_VOLTAGE_ENABLE      //BATTERY_MAX_VOLTAGE_INDEX_ee,
#define _BATTERY_MIN_VOLTAGE_ENABLE      //BATTERY_MIN_VOLTAGE_INDEX_ee,
//#define _BATTERY_DROPOUT_V_ENABLE      //BATTERY_DROPOUT_V_INDEX_ee,
#define _BATTERY_DROPOUT_T_ENABLE      //BATTERY_DROPOUT_T_INDEX_ee,
//#define _CHARGE_TIME_ENABLE      //CHARGE_TIME_INDEX_ee,
#define _BATTERY_MAX_T_ENABLE      //BATTERY_MAX_T_INDEX_ee,
#define _BATTERY_MIN_T_ENABLE      //BATTERY_MIN_T_INDEX_ee,
//#define _CHARGE_TIME_M_ENABLE      //CHARGE_TIME_M_INDEX_ee,


//#define _NEEDLE_KPAA_ENABLE      //NEEDLE_KPAA_INDEX_ee
//#define _NEEDLE_KPAB_ENABLE      //NEEDLE_KPAB_INDEX_ee

//#define _BATTERY_T_ENABLE        //BATTERY_T_INDEX_ee, //0x5b
//#define _DCAC_T_ENABLE 			//DCAC_T_INDEX_ee,
//#define _UPS_T_ENABLE 			//UPS_T_INDEX_ee,

//#define _CURRENT_TIME_ENABLE	//CURRENT_TIME_INDEX_ee
//#define _BUF_LEN_ENABLE
//#define _RUN_LEN_ENABLE
#define _POWERREUSE_ENABLE

#define _CHARGE_CURRENT_ENABLE
#define _CHARGE_VOLTAGE_ENABLE





/**********************************************???????**************************************************/

#define	PRNDS_CF			(1) 
#define	READY_CF 			(1) 
#define	SMALLLIGHT_CF		(1) 
#define	LED_ON_OFF_LEFT_CF	(1) 
#define	LED_ON_OFF_RIGHT_CF	(1) 
#define	F_FOGLAMP_CF		(1) 
#define	A_FOGLAMP_CF		(1) 
#define	HIGHBEAM_CF			(1) 
#define	DIPPEDHEADLIGHT_CF	(1) 
#define	SAFETYBELT_CF		(1) 
#define	AIRBAG_CF			(1) 
#define	ASB_CF				(1) 
#define	BRAKEFLUID_CF		(1) 
#define	PARKING_CF			(1) 
#define	MOTORERR_CF			(1) 
#define	MOTOROT_CF			(1) 
#define	MOTORSPEED_CF		(1) 
#define	POWERBATTERY_CF		(1) 
#define	SOC_CF				(1) 
#define	CHARGE_CF			(1) 
#define	CHARGPLUG_CF		(1) 
#define	DOOR_CF				(1) 
#define	DCDC_CF				(1) 
#define	POWERBATTERYCUT_CF	(1) 
#define	SYSTEMERR_CF		(1) 
#define	EPS_CF				(1) 
#define	PARKING_ERR_CF		(1) 
#define	CARLOCK_CF			(1) 
#define	ERR_WORD_CF			(1) 
#define	INSULATIONERR_CF	(1) 
#define BL_ADJ_LEVEL_CF		(1)
#define CHARGE_MODE_CF   	(1)


#define ICON_OFF_SHOW	(0)


/************************************************??????************/
#define BL_ON_GP_STAT	(1)
#define BL_EN_PIN		PORT_PNLGPP6

#define BLADJ_ON_GP_STAT	(1)
#define BL_ADJ_PIN		PORT_PNLGPP5

#define PANEL_ON_GP_STAT	(1)
#define PANEL_PIN		PORT_PNLGPP7

//#define BL_OFF_ADC0_PIN		PORT_ADC_IN1

#define TEST_ADC_PIN	PORT_ADC_IN1
#define TEST_GPIO_PIN	PORT_ADC_IN2







#define BL_ADJ_PWM_LEVEL_PARAM	(1171)	

/***************************************** ????*****DEBUG*********************/
#define _AT_RUN
#define _MY_DEBUG
#define _USE_CAN


/******************************************??????********************************/

#define CODE_TYPE1	(0X01)
#define CODE_TYPE2	(0X02)
#define CODE_TYPE3	(0X03)

typedef struct 
{
	uint32_t u32data;
	uint8_t u8dp;
}all_data_st;

#define TYPE2_NUMBER_BASE	(0X11)
#define TYPE2_NUMBER	(ICON_TOTAL_NUMBER_ee - TYPE2_NUMBER_BASE)

#define TYPE3_NUMBER_BASE	(0X41)
#define TYPE3_NUMBER	(TYPE3_TOTAL_NUMBER_ee - TYPE3_NUMBER_BASE)

typedef struct model_data
{
	uint8_t u8type1Data;
	uint8_t u8type2DataTable[TYPE2_NUMBER];
	all_data_st sttype3DataTable[TYPE3_NUMBER];	
}model_data_st;


typedef struct
{
	uint16_t x;
	uint16_t y;
}pt_info_st;





/*******************************************************************************************/
typedef void(*vRunFun_t)(void);
#define FUNCTION_NUMBER	(32)   //???????????
#define POWER_ON_LOGO	(1)   //??????
#define MAIN_SCREEN	(2)   //?????
#define WAKE_UP_SCREEN	(3)
#define POWER_DOWN_SCREEN  (4)
#define BATTERY_INFO_SCREEN	(5)
#define MOTOR_INFO_SCREEN	(6)


/**********************?????***********************************/

#define TIMERCOMPLX_NUMBER(n)   (n * 75 * (1000 / 64))   //ms

/*******************????**********************************************/

#define REFRESH		(2)		//  ????20ms
#define MAXSTEP		(100)	// ???
#define DIVNUMBER	(3)		// ??????????

typedef struct
{
	float32_t f32pre;		//????
	uint8_t u8msangle;		// ?1???ms?
	uint8_t u8minangle;		//????
}rorate_param_st;

typedef struct
{
	float32_t f32rota_angle;       //???????
	float32_t f32CurrentDAngle;    //???????
	float32_t f32StepAngle;        //???????
	uint8_t u8num;                 //?????
	uint8_t u8index;               //???????
	uint8_t u8dir;                 //??  0???  1???
	float32_t f32table[MAXSTEP];
}needle_show_st;
	
	
/********************************************************************????**********************************/

#define INIT_ANGLE	(-159)			//???????
#define SPEED_LEVEL	(2)				//???????????,??	vNGetNextAngle ?????			
#define MAX_STEP	(6)				//??
#define SPEED_PARAM	(1.5185)			//?????????????,????????  ?? / ??
#define SPEED_PARAM2	(0.7408)
#define ANGLE2_BASE	(91.11)
#define ANGLE_DIV	(60)				//???

#define INIT_ANGLE_ROTATE	(-115)
#define SPEED_LEVEL_ROTATE	(120)
#define MAX_STEP_ROTATE		(2)
#define SPEED_PARAM_ROTATE	(34.78)

#define INIT_ANGLE_SOC	(-129)
#define SPEED_LEVEL_SOC	(50)
#define MAX_STEP_SOC	(2)
#define SPEED_PARAM_SOC	(1.8)

#define INIT_ANGLE_KPA	(-125)
#define SPEED_LEVEL_KPA	(10)
#define MAX_STEP_KPA	(5)
#define SPEED_PARAM_KPA	(0.14)   //125  71

#define INIT_ANGLE_KPB	(124)
#define SPEED_LEVEL_KPB	(10)
#define MAX_STEP_KPB	(5)
#define SPEED_PARAM_KPB	(0.14)   //124   70

#define INIT_ANGLE_V	(129)
#define SPEED_LEVEL_V	(10)
#define MAX_STEP_V	(5)
#define SPEED_PARAM_V	(0.2)

#define INIT_ANGLE_C	(45)
#define SPEED_LEVEL_C	(10)
#define MAX_STEP_C	(5)
#define SPEED_PARAM_C	(1.47)


/******************************************************************************************************/

/***********************************??,????*********************************************************/
typedef struct
{
	uint16_t u16Startx;
	uint16_t u16Starty;
	uint8_t u8MaxLevel;
	uint8_t u8CurrentLevel;
	uint8_t u8type;      //????????
	uint8_t u8headFlag;  //????
}DiyBar_st;

/************************************************************/






/********************menu*****************************************/
typedef struct 
{
	uint8_t u8index;
	uint8_t u8enterIndex;
	uint8_t u8backIndex;
	uint8_t u8selectIndex;
	uint8_t u8lastIndex;
	void (*function)(void);
}menu_index_st;


#define KEY_ENTER	(1)
#define KEY_BACK	(2)
#define KEY_SELECT	(3)




/*****************************************************************/
extern int32_t u32Type3MinMaxTable[][2];
extern uint16_t u16TimerCount;    //?10ms??,??10000
extern model_data_st gModeData;   //??????
extern uint16_t u16Type2XYTable[][2]; 
extern uint16_t u16Type3XYTable[][2];
extern gf_image_st* stIconTable[][2];

extern DiyBar_st stBatTable[];
extern vRunFun_t gRunFunTable[];			//?????????


extern uint8_t u8IconConfigTable[];

extern uint16_t u16Timer1SFlag;

extern uint8_t u8MenuIndex;
extern uint16_t SPEED_NUMBER_X;
extern uint16_t SPEED_NUMBER_Y;

extern pt_info_st stAMPImage;


extern uint8_t u8QdIndex;




void vInitAllData(void);
void vInitIconTable(void);

void vfDelayMs(uint32_t n);
void vfShowImageAt(uint16_t x, uint16_t y, gf_image_st *stImage);
void vSystemInitFlib(gf_image_st *pImage_14x, gf_image_st *pImage_sx, gf_image_st *pImage_a, gf_image_st *pImage_AA);
void vNGetNextAngle(needle_show_st* stneedle, int iInitAngle, int iSpeedLevel, int iMaxStep, float32_t f32param, uint8_t index, int flag);
pt_info_st vShowNumberAT(uint8_t xytype, model_index_et etindex, const char *unit, const char *headword, uint8_t xlen, gf_image_st *sthead, gf_image_st *stunit, pt_info_st pt_info, all_data_st all_dat);
#endif


