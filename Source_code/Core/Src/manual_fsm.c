/*
 * manual_fsm.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */


#include "manual_fsm.h"

void fsm_manual(){
	switch (led_status){
	case MAN_REDGREEN:
		onTFRed1();
		onTFGreen2();

		if (isButtonPressed(1) == 1){
			led_status = INIT;
		}

		if (isButtonPressed(2) == 1){
			led_status = MAN_REDYELLOW;
		}
		if (isButtonPressed(3) == 1){
			led_status = MAN_YELLOWRED;
		}

		break;

	case MAN_REDYELLOW:
		onTFRed1();
		onTFYellow2();

		if (isButtonPressed(1) == 1){
			led_status = INIT;
		}

		if (isButtonPressed(2) == 1){
			led_status = MAN_GREENRED;
		}
		if (isButtonPressed(3) == 1){
			led_status = MAN_REDGREEN;
		}

		break;

	case MAN_GREENRED:
		onTFGreen1();
		onTFRed2();

		if (isButtonPressed(1) == 1){
			led_status = INIT;
		}

		if (isButtonPressed(2) == 1){
			led_status = MAN_YELLOWRED;
		}
		if (isButtonPressed(3) == 1){
			led_status = MAN_REDYELLOW;
		}

		break;

	case MAN_YELLOWRED:
		onTFYellow1();
		onTFRed2();

		if (isButtonPressed(1) == 1){
			led_status = INIT;
		}

		if (isButtonPressed(2) == 1){
			led_status = MAN_REDGREEN;
		}
		if (isButtonPressed(3) == 1){
			led_status = MAN_GREENRED;
		}

		break;

	default:
		break;
	}
}
