#include "Driver_Timer.h"

void Timer_Base_Init (TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC) {
	if (Timer == TIM1)
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	else if (Timer == TIM2)
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	else if (Timer == TIM3)
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	else
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	
	Timer->PSC = PSC;
	Timer->ARR = ARR;
}

void Timer_Base_Start (TIM_TypeDef * Timer) {
	Timer->CR1 |= 1;
}
void Timer_Base_Stop (TIM_TypeDef * Timer) {
	Timer->CR1 &= ~(1);
}
