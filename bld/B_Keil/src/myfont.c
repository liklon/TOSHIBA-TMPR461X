#include "listmngr.h"
#include "gfunctions.h"


#include "ccr.h"
#include "intc.h"
#include "txcan.h"
#include "mydef.h"
#include "pinconfig.h"
#include "stdio.h"
#include "string.h"

rorate_param_st stRorateTable[DIVNUMBER] = 
{
		{0.7, 2, 10},
		{0.2, 4, 0},
		{0.1, 10, 0},
};

gf_image_st *stImage_14x = NULL;
gf_image_st *stImage_speed = NULL;
gf_image_st *stImage_fa = NULL;
gf_image_st *stImage_fAA = NULL;


void vSystemInitFlib(gf_image_st *pImage_14x, gf_image_st *pImage_sx, gf_image_st *pImage_a, gf_image_st *pImage_AA)
{
	if(pImage_14x != NULL && pImage_sx != NULL)
	{
		stImage_14x = pImage_14x;
		stImage_speed = pImage_sx;
		stImage_fa = pImage_a;
		stImage_fAA = pImage_AA;
	}
}



void vfShowImageAt(uint16_t x, uint16_t y, gf_image_st *stImage)
{
	u32GfLayerBlendBitmapFull(stImage, &GDCX_LAYER_USE, x, y);
	vGfListExecute();
}




void vNGetNextAngle(needle_show_st* stneedle, int iInitAngle, int iSpeedLevel, int iMaxStep, float32_t f32param, uint8_t index, int flag)
{
  float32_t f32stepTmp = 0, f32tmp;
	float32_t f32speed_angle;
	float32_t f32tmpangle[DIVNUMBER];
	uint8_t num[DIVNUMBER], numa = 0;
	uint8_t i = 0, j = 0, k = 0;
	float32_t divx = 1.0;
	float32_t tmp;
	uint8_t tmp2;
	
	tmp = (float32_t)(gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u32data);
	tmp2 = gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u8dp & 0x7f;
	for(i = 0;i < tmp2;i++)
	{
		divx *= 10;
	}
	tmp = tmp / divx;

	if((gModeData.sttype3DataTable[index - TYPE3_NUMBER_BASE].u8dp & 0x80) != 0x80)
	{
			if(flag == -1)
			{
#ifdef ANGLE2_BASE
				if(index == NEEDLE_SPEED_INDEX_ee)
				{
					if(tmp <= ANGLE_DIV)
					{
						f32speed_angle = iInitAngle - tmp * f32param;
					}
					else
					{
						f32speed_angle = iInitAngle - (tmp - ANGLE_DIV) * SPEED_PARAM2 - ANGLE2_BASE;
					}
				}
				else
				{
						f32speed_angle = iInitAngle - tmp * f32param;
				}
#else
				f32speed_angle = iInitAngle - tmp * f32param;
#endif
			}
			else 
			{
#ifdef ANGLE2_BASE
				if(index == NEEDLE_SPEED_INDEX_ee)
				{
					if(tmp <= ANGLE_DIV)
					{
						f32speed_angle = iInitAngle + tmp * f32param;
					}
					else
					{
						f32speed_angle = iInitAngle + (tmp - ANGLE_DIV) * SPEED_PARAM2 + ANGLE2_BASE;
					}
				}
				else
				{
					f32speed_angle = iInitAngle + tmp * f32param;
					
					if(index == TOTAL_CURRENT_INDEX_ee)
					{
						f32speed_angle = iInitAngle - tmp * f32param;
					}		
				}
#else

				f32speed_angle = iInitAngle + tmp * f32param;
#endif
			}
	}
    else
    {
		if(index == TOTAL_CURRENT_INDEX_ee)
		{
			f32speed_angle = iInitAngle + tmp * f32param;
		}
	}
	
/*************************************************************************************************************************/
	if(stneedle->f32CurrentDAngle != f32speed_angle)   
	{
		if(stneedle->f32rota_angle < f32speed_angle)
		{
			f32stepTmp = (f32speed_angle - stneedle->f32rota_angle);		
			stneedle->u8dir = 0;
		}	
		else if(stneedle->f32rota_angle > f32speed_angle)
		{
			f32stepTmp = (stneedle->f32rota_angle - f32speed_angle);
			stneedle->u8dir = 1;
		}	
		for(k = 0; k < DIVNUMBER;k++)
		{
			f32tmpangle[k] = f32stepTmp * stRorateTable[k].f32pre;
			if(f32tmpangle[k] > stRorateTable[k].u8minangle)
				num[k] = (uint8_t)(f32tmpangle[k] * stRorateTable[k].u8msangle / (REFRESH * 10) + 0.5) + 1;
			else num[k] = 1;

			f32tmp = f32tmpangle[k] / num[k];
			for(i = numa;i < (num[k] + numa);i++)
			{
				stneedle->f32table[i] = f32tmp;
			}

			for(i = numa;i < (numa + num[k] - 1);i++)
			{
				for(j = (numa + 1);j < (numa + num[k]);j++)
				{
					stneedle->f32table[i] += stneedle->f32table[j] / num[k];
					stneedle->f32table[j] -= stneedle->f32table[j] / num[k];
				}
			}

			numa += num[k];
			
		}

        for(i = 0;i < numa;i++)
		{
			if(stneedle->f32table[i] < 0.1)
				stneedle->f32table[i] = 0.1;
		}

		stneedle->u8num = numa;
		stneedle->u8index = 0;
		stneedle->f32CurrentDAngle = f32speed_angle;
	}
/*************************************************************************************************************************/
}




pt_info_st stShowString(uint16_t x,uint16_t y,uint8_t *pstr,uint8_t xlen)
{
	uint16_t xtmp = x;
	uint16_t ytmp = y;
	uint8_t tmp;
	pt_info_st sttmp = {0,0};
	while(*pstr != '\0')
	{
		tmp = *pstr;
		if(tmp & 0x80)
		{
			pstr++;
			pstr++;
		}
		else if(tmp == '.')
		{
			u32GfLayerBlendBitmapFull((gf_image_st *)(stImage_14x + 10), &GDCX_LAYER_USE, xtmp, ytmp + (20 - ((gf_image_st *)(stImage_14x + 10))->u16Height));
			vGfListExecute();
			xtmp += 14;
			pstr++;
		}
		else if(tmp == ':')
		{
			pstr++;
		}
		else if(tmp == '(')
		{
			pstr++;
		}
		else if(tmp == ')')
		{
			pstr++;
		}
		else if('0' <= tmp && tmp <= '9')
		{
			if(xlen == 46)
			{
				u32GfLayerBlendBitmapFull((gf_image_st *)(stImage_speed + tmp - 0x30), &GDCX_LAYER_USE, xtmp, ytmp);
				vGfListExecute();
				xtmp += 46;

			}
			else
			{
				u32GfLayerBlendBitmapFull((gf_image_st *)(stImage_14x + tmp - 0x30), &GDCX_LAYER_USE, xtmp, ytmp);
				vGfListExecute();
				xtmp += 14;
			}
			pstr++;
		}
		else if(tmp <= 'z' && tmp >= 'a')
		{
			u32GfLayerBlendBitmapFull((gf_image_st *)(stImage_fa + tmp - 'a'), &GDCX_LAYER_USE, xtmp, ytmp);
			vGfListExecute();
			xtmp += 14;
			pstr++;
		}
		else if(tmp <= 'Z' && tmp >= 'A')
		{
			u32GfLayerBlendBitmapFull((gf_image_st *)(stImage_fAA + tmp - 'A'), &GDCX_LAYER_USE, xtmp, ytmp);
			vGfListExecute();
			xtmp += 14;
			pstr++;
		}
		else if(tmp == '-')
		{
		
			pstr++;
		}
		else if(tmp == '%')
		{
		
			pstr++;
		}
		else if(tmp == ' ')
		{
		    xtmp += 7;
			pstr++;
		}
		else
		{
			xtmp += 14;
			pstr++;
		}
	}

	sttmp.x = xtmp;
	sttmp.y = ytmp;
	return sttmp;
	
}











/**************************************************************************************
xytype: 0?????,1???? 
etindex: ????
unit: ?????
xlen: ????????  (???????46  ????14)
**************************************************************************************/
pt_info_st vShowNumberAT(uint8_t xytype, model_index_et etindex, const char *unit, const char *headword, uint8_t xlen, gf_image_st *sthead, gf_image_st *stunit, pt_info_st pt_info, all_data_st all_dat)
{
	uint8_t tmptable[30];
	uint32_t u32data = 0;
	uint8_t u8flag = 0;
	uint8_t u8datalen = 0, u8tmplen = 0, u8ptnumber = 0;
	int8_t i,j;
	uint16_t xtmp = 0, ytmp = 0;
	pt_info_st stxy;


	for(j = 0;j < 30;j++)
	{
		tmptable[j] = '\0';
	}

	if(headword != 0)
	{
		u8tmplen = strlen(headword);
		for(i = 0;i < u8tmplen;i++)
		{
			tmptable[i] = headword[i];
		}
		u8datalen += u8tmplen;
	}
	else if(sthead != 0)
	{
		xtmp += sthead->u16Width;
	}

	if(etindex == 0)
	{
		u32data = all_dat.u32data;
		u8flag = all_dat.u8dp;
	}
	else
	{
		u32data = gModeData.sttype3DataTable[etindex - TYPE3_NUMBER_BASE].u32data;
		u8flag = gModeData.sttype3DataTable[etindex - TYPE3_NUMBER_BASE].u8dp;
	}
	if(u32data > 999999)
	{
		sprintf((char *)(&tmptable[u8datalen]), "%7d", u32data);
		u8datalen += 7;
	}
	else if(u32data > 99999)
	{
		sprintf((char *)(&tmptable[u8datalen]), "%6d", u32data);
		u8datalen += 6;
	}
	else if(u32data > 9999) 
	{
		sprintf((char *)(&tmptable[u8datalen]), "%5d", u32data);
		u8datalen += 5;
	}
	else if(u32data > 999) 
	{
		sprintf((char *)(&tmptable[u8datalen]), "%4d", u32data);
		u8datalen += 4;
	}
	else if(u32data > 99) 
	{
		sprintf((char *)(&tmptable[u8datalen]), "%3d", u32data);
		u8datalen += 3;
	}
	else if(u32data > 9) 
	{
		sprintf((char *)(&tmptable[u8datalen]), "%2d", u32data);
		u8datalen += 2;
	}
	else
	{
		sprintf((char *)(&tmptable[u8datalen]), "%d", u32data);
		u8datalen += 1;
	}

	u8ptnumber = u8flag & 0x7f;
	if(u8ptnumber != 0)
	{
		for(i = (u8datalen - 1);i >= (u8datalen - u8ptnumber);i--)
		{
			tmptable[i + 1] = tmptable[i];
		}
		tmptable[u8datalen - u8ptnumber] = '.';
		u8datalen += 1;
	}

	if((u8flag & 0x80) == 0x80)
	{
		for(i = (u8datalen - 1);i >= 0;i--)
		{
			tmptable[i + 1] = tmptable[i];
		}
		tmptable[0] = '-';
		u8datalen += 1;
	}

	
	if(unit != 0)
	{
		u8tmplen = strlen(unit);
		for(i = 0;i < u8tmplen;i++)
		{
			tmptable[u8datalen + i] = unit[i];
		}
	}
	else if(stunit != 0)
	{
		xtmp += stunit->u16Width;
	}
	
    tmptable[u8datalen + i] = '\0';
	if(xytype == 0x1)
	{
		xtmp += (u8datalen + u8tmplen) * xlen;
		if(etindex == 0)
			xtmp = pt_info.x - xtmp / 2;
		else
			xtmp = u16Type3XYTable[etindex - TYPE3_NUMBER_BASE][0] - xtmp / 2;
	}
	else
	{
		if(etindex == 0)
			xtmp = pt_info.x;
		else
			xtmp = u16Type3XYTable[etindex - TYPE3_NUMBER_BASE][0];
	}
		
	if(etindex == 0)
		ytmp = pt_info.y;
	else
		ytmp = u16Type3XYTable[etindex - TYPE3_NUMBER_BASE][1];

	if(sthead != 0)
	{
		vfShowImageAt(xtmp,ytmp,sthead);
		xtmp += sthead->u16Width;
	}
	stxy = stShowString(xtmp,ytmp,tmptable,xlen);
    if(stunit != 0)
    {
		vfShowImageAt(stxy.x + 7,stxy.y,stunit);
		stxy.x += stunit->u16Width + 7;
	}
	
	return stxy;
}



