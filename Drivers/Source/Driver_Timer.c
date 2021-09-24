#include "Driver_Timer.h"

// Pointeurs de fonctions d'interruption
void (*Timer1_Interupt)(void) = 0;
void (*Timer2_Interupt)(void) = 0;
void (*Timer3_Interupt)(void) = 0;
void (*Timer4_Interupt)(void) = 0;

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


void Timer_ActiveIT(TIM_TypeDef * Timer, char Prio, void(*IT_function )(void)) {
	// Autorisation de l'interruption et miseneplace de la priorité dans le NVIC
	// Attribution de l'adresse de l'interrupteur qau ointeur de fonction correspondant
	if (Timer == TIM1) {
		NVIC->ISER[0]|= 1 << 25;
		NVIC->IP[25] = Prio;
		Timer1_Interupt = IT_function;
	} else if (Timer == TIM2) {
		NVIC->ISER[0] = 1 << 28;
		NVIC->IP[28] = Prio;
		Timer2_Interupt = IT_function;
	} else if (Timer == TIM3) {
		NVIC->ISER[0] = 1 << 29;
		NVIC->IP[29] = Prio;
		Timer3_Interupt = IT_function;
	} else {
		NVIC->ISER[0] = 1 << 30;
		NVIC->IP[30] = Prio;
		Timer4_Interupt = IT_function;
	}
	
	// Autorisation des demandes d'interruption 
	Timer->DIER |= 0x1;
}

void TIM1_UP_IRQHandler (void) {
	TIM1->SR &= ~(0x1);
	if (Timer1_Interupt != 0)
		(*Timer1_Interupt)();
}

void TIM2_IRQHandler (void) {
	TIM2->SR &= ~(0x1);
	if (Timer2_Interupt != 0)
		(*Timer2_Interupt)();
}

void TIM3_IRQHandler (void) {
	TIM3->SR &= ~(0x1);
	if (Timer3_Interupt != 0)
		(*Timer3_Interupt)();
}

void TIM4_IRQHandler (void) {
	TIM4->SR &= ~(0x1);
	if (Timer4_Interupt != 0)
		(*Timer4_Interupt)();
}
