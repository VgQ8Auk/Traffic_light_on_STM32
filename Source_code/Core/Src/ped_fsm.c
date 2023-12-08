/*
 * ped_fsm.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Admin
 */

#include "ped_fsm.h"

void fsm_ped(){

	switch (ped_status){
	case INIT:
		offPEDLed();
		if (isButtonPressed(0) == 1){
			ped_flag = 1;
			ped_status = led_status;
			setTimer4(500);
		}
		break;

	case REDGREEN:
		onPEDRed();

		if (timer4_flag == 1){
			ped_status = INIT;
			ped_flag = 0;
			setTimer4(0);
			setTimer5(0);
		}

		break;

	case REDYELLOW:
		onPEDRed();

		if (timer4_flag == 1){
			ped_status = INIT;
			ped_flag = 0;
			setTimer4(0);
			setTimer5(0);
		}

		break;

	case GREENRED:
		onPEDGreen();

		if (timer4_flag == 1){
			ped_status = INIT;
			ped_flag = 0;
			setTimer4(0);
			setTimer5(0);
		}

		break;

	case YELLOWRED:
		if (timer5_flag == 1){
			toggleGreen();
			setTimer5(25);
		}

		if (timer4_flag == 1){
			ped_status = INIT;
			ped_flag = 0;
			setTimer4(0);
			setTimer5(0);
		}

		break;

	default:
		ped_status = INIT;
		break;
	}
}
