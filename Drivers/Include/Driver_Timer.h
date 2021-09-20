#ifndef DRIVER_TIMER_H__
#define DRIVER_TIMER_H__
#include "stm32f10x.h"

void Timer_Base_Init (TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC);
void Timer_Base_Start (TIM_TypeDef * Timer);
void Timer_Base_Stop (TIM_TypeDef * Timer);

#endif
