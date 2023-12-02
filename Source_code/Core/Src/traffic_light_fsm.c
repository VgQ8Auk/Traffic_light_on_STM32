/*
 * traffic_light_fsm.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */


#include "traffic_light_fsm.h"

void fsm_traffic_light(){
	switch (led_status){
	case INIT:
		offAllLed();

		led_status = REDGREEN;
		setTimer1(greenTime*100);
		setTimer2(100);

		timerRoad1 = redTime;
		timerRoad2 = greenTime;
		break;

	case REDGREEN:
		onTFRed1();
		onTFGreen2();

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = yellowTime;
		}

		if (timer1_flag == 1){
			setTimer1(yellowTime*100);
			led_status = REDYELLOW;
		}

		if (isButtonPressed(1) == 1) {
			offAllLed();

			led_status = MAN_REDGREEN;
			newRed = redTime;
			newGreen = greenTime;
			newYellow = yellowTime;
		}

		break;

	case REDYELLOW:
		onTFRed1();
		onTFYellow2();

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			timerRoad2--;
			if (timerRoad1 <= 0) timerRoad1 = greenTime;
			if (timerRoad2 <= 0) timerRoad2 = redTime;
		}

		if(timer1_flag == 1){
			setTimer1(greenTime*100);
			led_status = GREENRED;
		}

		if (isButtonPressed(1) == 1) {
			offAllLed();

			led_status = MAN_REDYELLOW;
			newRed = redTime;
			newGreen = greenTime;
			newYellow = yellowTime;
		}

		break;

	case GREENRED:
		onTFGreen1();
		onTFRed2();

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			if (timerRoad1 <= 0) timerRoad1 = yellowTime;
			timerRoad2--;
		}


		if(timer1_flag == 1){
			setTimer1(yellowTime*100);
			led_status = YELLOWRED;
		}

		if (isButtonPressed(1) == 1) {
			offAllLed();

			led_status = MAN_GREENRED;
			newRed = redTime;
			newGreen = greenTime;
			newYellow = yellowTime;
		}
		break;

	case YELLOWRED:
		onTFYellow1();
		onTFRed2();

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			if (timerRoad1 <= 0) timerRoad1 = redTime;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = greenTime;
		}

		if (timer1_flag == 1){
			setTimer1(greenTime*100);
			led_status = REDGREEN;
		}

		if (isButtonPressed(1) == 1) {
			offAllLed();

			led_status = MAN_YELLOWRED;
			newRed = redTime;
			newGreen = greenTime;
			newYellow = yellowTime;
		}
		break;

	default:
		break;
	}


}
