/** @file    Timer0.h
 ** @brief   Timer0 Module header file 
 ** @author  Mohamed Tarek
 ** @date    11/9/2014
 ** @version 1.0
 */  

#ifndef TIMER0_H_
#define TIMER0_H_

#include "STD_TYPE.h"
#include <avr/interrupt.h>

/* 
 * Description: this function responsible for :
 *	1. Initialize Timer0 HW Driver to run in CTC Mode 
 *	2. Set the Compare Register Value to generate interrupt every Tick_Time ms 
 */	
void Timer0_Start_CTC_Mode(uint8 Tick_Time);

/* Points to the required function in the OS upper layer Scheduler */
void Timer0_Set_CallBack(void (*Ptr2Func)(void));

#endif /* TIMER0_H_ */