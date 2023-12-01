/*
 * button.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#include "button.h"

uint16_t pin[4] = {PED_BTN_Pin, BTN1_Pin, BTN2_Pin, BTN3_Pin};

int KeyReg0[NUM_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeOutForKeyPress[NUM_BUTTON] =  {200, 200, 200, 200};
int button_flag[NUM_BUTTON] = {0, 0, 0, 0};

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
	for (int i=0; i < NUM_BUTTON; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		//Add your button here
		switch (i){
		case 0:
			KeyReg0[i] = HAL_GPIO_ReadPin(PED_BTN_GPIO_Port, pin[i]);
			break;
		case 1:
			KeyReg0[i] = HAL_GPIO_ReadPin(BTN1_GPIO_Port, pin[i]);
			break;
		case 2:
			KeyReg0[i] = HAL_GPIO_ReadPin(BTN2_GPIO_Port, pin[i]);
			break;
		case 3:
			KeyReg0[i] = HAL_GPIO_ReadPin(BTN3_GPIO_Port, pin[i]);
			break;
		default:
			break;
		}


		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE){
					TimeOutForKeyPress[i] = 200;
					subKeyProcess(i);
				}
			}

			else{ //press without release
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
				}

			}
		}
	}
}
