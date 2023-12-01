/*
 * led_control.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

#include "global.h"

void offAllLed();
void offTFLed();
void offPEDLed();

void onTFRed1();
void onTFGreen1();
void onTFYellow1();

void onTFRed2();
void onTFGreen2();
void onTFYellow2();

void onPEDRed();
void onPEDGreen();

#endif /* INC_LED_CONTROL_H_ */
