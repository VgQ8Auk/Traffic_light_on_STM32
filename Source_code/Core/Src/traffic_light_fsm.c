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
		setTimer3(1);

		timerRoad1 = redTime;
		timerRoad2 = greenTime;
		print_string("AUTOMATION MODE\r\n");
		break;

	case REDGREEN:
		onTFRed1();
		onTFGreen2();

		if (timer2_flag == 1){
			setTimer2(100);
			timerRoad1--;
			timerRoad2--;
			if (timerRoad2 <= 0) timerRoad2 = yellowTime;
			uart_led(timerRoad1, timerRoad2);
		}

		if (timer1_flag == 1){
			setTimer1(yellowTime*100);
			led_status = REDYELLOW;

			if (ped_flag == 1){
				ped_status = led_status;
			}

		}

		if (isButtonPressed(1) == 1) {
			offAllLed();
			print_string("MANUAL MODE\r\n");

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
			uart_led(timerRoad1, timerRoad2);
		}

		if(timer1_flag == 1){
			setTimer1(greenTime*100);
			led_status = GREENRED;

			if (ped_flag == 1){
				ped_status = led_status;
			}
		}

		if (isButtonPressed(1) == 1) {
			offAllLed();
			print_string("MANUAL MODE\r\n");

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
			uart_led(timerRoad1, timerRoad2);
		}


		if(timer1_flag == 1){
			setTimer1(yellowTime*100);
			led_status = YELLOWRED;
			if (ped_flag == 1){
				setTimer5(25);
				ped_status = led_status;
			}
		}

		if (isButtonPressed(1) == 1) {
			offAllLed();
			print_string("MANUAL MODE\r\n");

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
			uart_led(timerRoad1, timerRoad2);
		}

		if (timer1_flag == 1){
			setTimer1(greenTime*100);
			led_status = REDGREEN;
			if (ped_flag == 1){
				ped_status = led_status;
			}
		}

		if (isButtonPressed(1) == 1) {
			offAllLed();
			print_string("MANUAL MODE\r\n");

			led_status = MAN_YELLOWRED;
			newRed = redTime;
			newGreen = greenTime;
			newYellow = yellowTime;
		}
		break;

	case MAN_REDGREEN:
		onTFRed1();
		onTFGreen2();

		if (isButtonPressed(1) == 1){
			offAllLed();
			print_string("TUNING MODE: SET RED LED\r\n");
			print_value(redTime, newRed);
			led_status = SET_RED;
			temp_status = REDGREEN;
		}

		if (isButtonPressed(2) == 1){
			led_status = MAN_REDYELLOW;
		}

		if (isButtonPressed(3) == 1){
			print_string("AUTOMATION MODE\r\n");
			led_status = REDGREEN;

			timerRoad1 = redTime;
			timerRoad2 = greenTime;

			setTimer1(greenTime*100);
			setTimer2(100);
		}

		break;

	case MAN_REDYELLOW:
		onTFRed1();
		onTFYellow2();

		if (isButtonPressed(1) == 1){
			offAllLed();
			print_string("TUNING MODE: SET RED LED\r\n");
			print_value(redTime, newRed);
			led_status = SET_RED;
			temp_status = REDYELLOW;
		}

		if (isButtonPressed(2) == 1){
			led_status = MAN_GREENRED;
		}
		if (isButtonPressed(3) == 1){
			print_string("AUTOMATION MODE\r\n");
			led_status = REDYELLOW;

			timerRoad1 = redTime;
			timerRoad2 = yellowTime;

			setTimer1(yellowTime*100);
			setTimer2(100);
		}

		break;

	case MAN_GREENRED:
		onTFGreen1();
		onTFRed2();

		if (isButtonPressed(1) == 1){
			offAllLed();
			print_string("TUNING MODE: SET RED LED\r\n");
			print_value(redTime, newRed);
			led_status = SET_RED;
			temp_status = GREENRED;
		}

		if (isButtonPressed(2) == 1){
			led_status = MAN_YELLOWRED;
		}
		if (isButtonPressed(3) == 1){
			print_string("AUTOMATION MODE\r\n");
			led_status = GREENRED;

			timerRoad1 = greenTime;
			timerRoad2 = redTime;

			setTimer1(greenTime*100);
			setTimer2(100);
		}

		break;

	case MAN_YELLOWRED:
		onTFYellow1();
		onTFRed2();

		if (isButtonPressed(1) == 1){
			offAllLed();
			print_string("TUNING MODE: SET RED LED\r\n");
			print_value(redTime, newRed);
			led_status = SET_RED;
			temp_status = YELLOWRED;
		}

		if (isButtonPressed(2) == 1){
			led_status = MAN_REDGREEN;
		}
		if (isButtonPressed(3) == 1){
			print_string("AUTOMATION MODE\n");
			led_status = YELLOWRED;

			timerRoad1 = yellowTime;
			timerRoad2 = redTime;

			setTimer1(yellowTime*100);
			setTimer2(100);
		}

		break;

	case SET_RED:
		onTFRed1();
		onTFRed2();

		if (isButtonPressed(1) == 1){
			led_status = SET_YELLOW;
			print_string("TUNING MODE: SET YELLOW LED\r\n");
			print_value(yellowTime, newYellow);
			offAllLed();
		}

		if (isButtonPressed(2) == 1){
			newRed++;
			if (newRed >= 20) newRed = 2;
			print_value(redTime, newRed);
		}

		if (isButtonPressed(3) == 1){
			redTime = newRed;
			print_string("Saved Red time: ");
			print_value(redTime, newRed);
		}
		break;

	case SET_YELLOW:
		onTFYellow1();
		onTFYellow2();

		if (isButtonPressed(1) == 1){
			led_status = SET_GREEN;
			print_string("TUNING MODE: SET GREEN LED\r\n");
			print_value(greenTime, newGreen);
			offAllLed();
		}
		if (isButtonPressed(2) == 1){
			newYellow++;
			if (newYellow >= redTime) newYellow = 1;
			print_value(yellowTime, newYellow);
		}

		if (isButtonPressed(3) == 1){
			yellowTime=newYellow;
			print_string("Saved Yellow time: ");
			print_value(yellowTime, newYellow);
		}
		break;

	case SET_GREEN:
		onTFGreen1();
		onTFGreen2();

		if (isButtonPressed(1) == 1){
			greenTime = redTime - yellowTime;
			print_string("AUTOMATION MODE\r\n");

			if (temp_status == REDGREEN){
				timerRoad1 = redTime;
				timerRoad2 = greenTime;
				print_string("First status: REDGREEN\r\n");
				led_status = REDGREEN;
			}

			else if (temp_status == REDYELLOW){
				timerRoad1 = redTime;
				timerRoad2 = yellowTime;
				print_string("First status: REDYELLOW\r\n");
				led_status = REDYELLOW;
			}

			else if (temp_status == YELLOWRED){
				timerRoad1 = yellowTime;
				timerRoad2 = redTime;
				print_string("First status: YELLOWRED\r\n");
				led_status = YELLOWRED;
			}

			else if (temp_status == GREENRED){
				timerRoad1 = greenTime;
				timerRoad2 = redTime;
				print_string("First status: GREENRED\r\n");
				led_status = GREENRED;
			}


			setTimer1(greenTime*100);
			setTimer2(100);

			offAllLed();
		}

		if (isButtonPressed(2) == 1){
			newGreen++;
			if (newGreen >= redTime) newGreen = 1;
			print_value(greenTime, newGreen);
		}

		if (isButtonPressed(3) == 1){
			greenTime = newGreen;
			yellowTime = redTime - greenTime;
			print_string("Saved Green time: ");
			print_value(greenTime, newGreen);
		}
		break;


	default:
		break;
	}


}
