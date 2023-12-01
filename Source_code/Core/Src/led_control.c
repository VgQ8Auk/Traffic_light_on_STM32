/*
 * led_control.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#include "led_control.h"

// TURN OFF LED
void offAllLed(){
	HAL_GPIO_WritePin(TF_LED_1_GPIO_Port, TF_LED_1_Pin, RESET);
	HAL_GPIO_WritePin(TF_LED_2_GPIO_Port, TF_LED_2_Pin, RESET);

	HAL_GPIO_WritePin(TF_LED_3_GPIO_Port, TF_LED_3_Pin, RESET);
	HAL_GPIO_WritePin(TF_LED_4_GPIO_Port, TF_LED_4_Pin, RESET);

	HAL_GPIO_WritePin(PED_LED_1_GPIO_Port, PED_LED_1_Pin, RESET);
	HAL_GPIO_WritePin(PED_LED_2_GPIO_Port, PED_LED_2_Pin, RESET);
}

void offTFLed(){
	HAL_GPIO_WritePin(TF_LED_1_GPIO_Port, TF_LED_1_Pin, RESET);
	HAL_GPIO_WritePin(TF_LED_2_GPIO_Port, TF_LED_2_Pin, RESET);

	HAL_GPIO_WritePin(TF_LED_3_GPIO_Port, TF_LED_3_Pin, RESET);
	HAL_GPIO_WritePin(TF_LED_4_GPIO_Port, TF_LED_4_Pin, RESET);
}

void offPEDLed(){
	HAL_GPIO_WritePin(PED_LED_1_GPIO_Port, PED_LED_1_Pin, RESET);
	HAL_GPIO_WritePin(PED_LED_2_GPIO_Port, PED_LED_2_Pin, RESET);
}

// TURN ON TRAFFIC LIGHT 1
void onTFRed1() {
	HAL_GPIO_WritePin(TF_LED_1_GPIO_Port, TF_LED_1_Pin, SET);
	HAL_GPIO_WritePin(TF_LED_2_GPIO_Port, TF_LED_2_Pin, RESET);
}
void onTFGreen1(){
	HAL_GPIO_WritePin(TF_LED_1_GPIO_Port, TF_LED_1_Pin, RESET);
	HAL_GPIO_WritePin(TF_LED_2_GPIO_Port, TF_LED_2_Pin, SET);
}
void onTFYellow1(){
	HAL_GPIO_WritePin(TF_LED_1_GPIO_Port, TF_LED_1_Pin, SET);
	HAL_GPIO_WritePin(TF_LED_2_GPIO_Port, TF_LED_2_Pin, SET);
}

// TURN ON TRAFFIC LIGHT 2
void onTFRed2(){
	HAL_GPIO_WritePin(TF_LED_3_GPIO_Port, TF_LED_3_Pin, SET);
	HAL_GPIO_WritePin(TF_LED_4_GPIO_Port, TF_LED_4_Pin, RESET);
}
void onTFGreen2(){
	HAL_GPIO_WritePin(TF_LED_3_GPIO_Port, TF_LED_3_Pin, RESET);
	HAL_GPIO_WritePin(TF_LED_4_GPIO_Port, TF_LED_4_Pin, SET);
}
void onTFYellow2(){
	HAL_GPIO_WritePin(TF_LED_3_GPIO_Port, TF_LED_3_Pin, SET);
	HAL_GPIO_WritePin(TF_LED_4_GPIO_Port, TF_LED_4_Pin, SET);
}

// TURN ON PEDESTRIAN LIGHT
void onPEDRed(){
	HAL_GPIO_WritePin(PED_LED_1_GPIO_Port, PED_LED_1_Pin, SET);
	HAL_GPIO_WritePin(PED_LED_2_GPIO_Port, PED_LED_2_Pin, RESET);
}
void onPEDGreen(){
	HAL_GPIO_WritePin(PED_LED_1_GPIO_Port, PED_LED_1_Pin, RESET);
	HAL_GPIO_WritePin(PED_LED_2_GPIO_Port, PED_LED_2_Pin, SET);
}
