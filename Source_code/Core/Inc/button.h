/*
 * button.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESSED_STATE 0

#define NUM_BUTTON 3

extern int button_flag[NUM_BUTTON];

void getKeyInput();
int isButtonPressed(int num);

#endif /* INC_BUTTON_H_ */
