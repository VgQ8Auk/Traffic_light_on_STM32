/*
 * buzzer.c
 *
 *  Created on: Dec 9, 2023
 *      Author: quoca
 */
#include "buzzer.h"
extern TIM_HandleTypeDef htim3;
#define VolumeMAX 500;
#define VolumeMIN 0;
void buzzer_init()
{
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}
void buzzer_on()
{
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, VolumeMAX);
	setTimer7(500);
	if (timer7_flag == 1)
	{
		buzzer_off;
	}
}
void buzzer_off()
{
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, VolumeMIN);
}
