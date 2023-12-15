/*
 * ped_fsm.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Admin
 */

#include "ped_fsm.h"
int TIME_OUT_FOR_PEDESTRIAN = 1000;

void fsm_ped(){
	switch (ped_status){
	case INIT:
		offPEDLed();
		if (isButtonPressed(0) == 1){
			ped_flag = 1;
			ped_status = led_status;
			setTimer4(TIME_OUT_FOR_PEDESTRIAN);
		}
		break;

	case REDGREEN:
		onPEDRed();
		offbuzzer();

		if (timer4_flag == 1){
			ped_status = INIT;
			ped_flag = 0;
			setTimer4(0);
			setTimer5(0);
			setTimer3(0);
			offbuzzer();
		}

		break;

	case REDYELLOW:
		onPEDRed();
		offbuzzer();

		if (timer4_flag == 1){
			ped_status = INIT;
			ped_flag = 0;
			setTimer4(0);
			setTimer5(0);
			setTimer3(0);
			offbuzzer();
		}
		setTimer3(1);

		break;

	case GREENRED:
		onPEDGreen();
		startBuzzer();
		if (timer4_flag == 1){
			ped_status = INIT;
			ped_flag = 0;
			setTimer4(0);
			setTimer5(0);
			setTimer3(0);
			offbuzzer();
		}

		break;

	case YELLOWRED:
		if (timer5_flag == 1){
			toggleGreen();
			setTimer5(25);
		}
		startBuzzer();

		if (timer4_flag == 1){
			ped_status = INIT;
			ped_flag = 0;
			setTimer4(0);
			setTimer5(0);
			offbuzzer();
		}

		break;

	default:
		ped_status = INIT;
		break;
	}
}

