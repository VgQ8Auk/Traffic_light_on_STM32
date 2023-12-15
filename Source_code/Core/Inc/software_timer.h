/*
 * software_timer.h
 *
 *  Created on: Nov 28, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

//  ==== TIMER ====
/*
 * timer1: Traffic light
 * timer2: 1s counter
 * timer3: Maybe buzzer on off (200ms)
 * timer4: Pedestrian time (10s)
 * timer5: Blinky green ped
 * timer6:
 */

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer5_flag;
extern int timer6_flag;
extern int timer7_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);
void setTimer7(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
