/*
 * button.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Admin
 */

#include "button.h"


int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  200;
int button_flag[NUM_BUTTON] = {0, 0, 0};

int isButtonPressed(int num){
	if(button_flag[num] == 1){
		button_flag[num] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int num){
	//TODO
	button_flag[num]=1;
}

void getKeyInput(){
	KeyReg2 = KeyReg1;
	KeyReg1 = KeyReg0;
	//Add your button here
	KeyReg0 = HAL_GPIO_ReadPin(PED_BTN_GPIO_Port, PED_BTN_Pin);

	if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
		if (KeyReg2 != KeyReg3){
			KeyReg3 = KeyReg2;
			if (KeyReg3 == PRESSED_STATE){
				TimeOutForKeyPress = 200;
				subKeyProcess(0);
			}
		}

		else{ //press without release
			TimeOutForKeyPress--;
			if (TimeOutForKeyPress == 0){
				KeyReg3 = NORMAL_STATE;
			}

		}
	}
}

