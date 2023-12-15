/*
 * UART.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Admin
 */

#include "UART.h"

uint8_t temp = 0;
char str[40];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (huart->Instance == USART2){
		HAL_UART_Transmit(&huart2, &temp, 1, 50);
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

void uart_led(int num1, int num2){
	char str[100];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str,"!Road1=%d; Road2=%d#\r\n", num1, num2), 100);
}

void print_string(const char *str){
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 100);
}

void print_value(int num1, int num2){
	char str[100];
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str,"!Old value=%d; New value=%d#\r\n", num1, num2), 100);
}

void display(){
	if (led_status == GREENRED || led_status == YELLOWRED || led_status == REDGREEN || led_status == REDYELLOW){
		print_string("AUTOMATION MODE");
	}
}
