#ifndef DRIVER_TIMER_H__
#define DRIVER_TIMER_H__
#include "stm32f10x.h"

// Initialisation du Timer avec une valeur d'autoreload (ARR) et de prescaler (PSC)
void Timer_Base_Init (TIM_TypeDef * Timer, unsigned short ARR, unsigned short PSC);
// Lancement du Timer
void Timer_Base_Start (TIM_TypeDef * Timer);
// Arrêt du Timer
void Timer_Base_Stop (TIM_TypeDef * Timer);
// Activation de l'interruption du Timer
// Place la priorité (Prio) et défini un handler (IT_function)
void Timer_ActiveIT(TIM_TypeDef * Timer, char Prio, void(*IT_function )(void));

#endif
