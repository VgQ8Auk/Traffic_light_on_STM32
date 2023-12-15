/*
 * UART.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Admin
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "global.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart2;

extern uint8_t temp;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void uart_led(int num1, int num2);
void print_string(const char *str);
void print_value(int num1, int num2);
void display();

#endif /* INC_UART_H_ */
