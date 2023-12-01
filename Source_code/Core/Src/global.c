/*
 * global.c
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */
#include "global.h"

eTrafficLightState led_status = INIT;
eTrafficLightState ped_status = BEGIN;

// First initialization for time
int redTime = 5;
int greenTime = 3;
int yellowTime = 2;

int newRed = 0;
int newGreen = 0;
int newYellow = 0;

int timerRoad1 = 0;
int timerRoad2 = 0;
