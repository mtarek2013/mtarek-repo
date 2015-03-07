/** @file    Timer0.c
 ** @brief   Timer0 Module
 ** @author  Mohamed Tarek
 ** @date    11/9/2014
 ** @version 1.0
 */ 

#include "Timer0.h"

/* Global pointer to function used to point upper layer functions
 * to be used in Call Back */
static volatile void (*g_Timer0_Call_Back_Ptr)(void);

/*********************************************************************************************/ 
void Timer0_Start_CTC_Mode(uint8 Tick_Time)
{
	TCNT0  = 0; //Timer0 initial value
	OCR0   = Tick_Time; 
	TIMSK |= (1<<OCIE0); //Enable Compare Interrupt for Timer0
	sei(); //Set the global interrupt mask bit I-bit
	/* configure the timer
	 * 1. Non PWM mode FOC0=1
	 * 2. CTC Mode WGM01=1 & WGM00=0
	 * 3. No need for OC0 so COM00=0 & COM01=0  
	 * 4. start Timer0 by initiating clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	 */
	TCCR0  = (1<<FOC0) | (1<<WGM01) | (1<<CS02) | (1<<CS00);
}
/*********************************************************************************************/
void Timer0_Set_CallBack(void(*Ptr2Func)(void))
{
	g_Timer0_Call_Back_Ptr = Ptr2Func;
}
/*********************************************************************************************/
/* Interrupt Service Routine for Timer0 compare mode */
ISR(TIMER0_COMP_vect)
{
	(*g_Timer0_Call_Back_Ptr)(); //call the function in the scheduler using call-back concept
}
/*********************************************************************************************/