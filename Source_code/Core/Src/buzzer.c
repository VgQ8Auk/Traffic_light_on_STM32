/*
 * buzzer.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Admin
 */

#include "buzzer.h"

extern TIM_HandleTypeDef htim3;

int res = 0;
void startBuzzer(){
	if(timer3_flag == 1){
		print_string("Buzzer");
//		double temp = (1-(double)timerRoad1/redTime)*100;
//
//		int res = (int)round(temp);
		if (res >= 100){
			res = 0;
		}
		else {
			res += 20;
		}

		if (ped_sig) {
			__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,res);
		}
		else {
			__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,0);
		}
		ped_sig = 1 - ped_sig;

//		double temp1 = ((double)timerRoad1/redTime)*100;
//
//		int timeBuz = (int)round(temp1);

		setTimer3(10);
	}
}

void offbuzzer(){
	__HAL_TIM_SetCompare (&htim3,TIM_CHANNEL_1,0);
}
