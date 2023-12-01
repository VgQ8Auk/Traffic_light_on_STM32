/*
 * global.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"

// FSM for traffic light
typedef enum {
	// Initial State
	INIT,

	// Traffic State
	REDGREEN,
	REDYELLOW,
	GREENRED,
	YELLOWRED,

	// Manual State
	MAN_REDGREEN,
	MAN_REDYELLOW,
	MAN_GREENRED,
	MAN_YELLOWRED,
} eTrafficLightState;

extern eTrafficLightState led_status;

extern int redTime;
extern int greenTime;
extern int yellowTime;

extern int newRed;
extern int newGreen;
extern int newYellow;

extern int timerRoad1;
extern int timerRoad2;

#endif /* INC_GLOBAL_H_ */
