/*
 * button.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

#define NUM_BUTTON 4

extern int button_flag[NUM_BUTTON];

void getKeyInput();
int isButtonPressed(int num);

#endif /* INC_BUTTON_H_ */
