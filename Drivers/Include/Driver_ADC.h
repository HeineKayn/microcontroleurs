#ifndef DRIVER_ADC_H__
#define DRIVER_ADC_H__
#include "stm32f10x.h"

// Initialisation d'un ADC
void ADC_Init (ADC_TypeDef * ADC);
//
void ADC_Channel (ADC_TypeDef * ADC, char Channel, char Group);

void ADC_Mode (ADC_TypeDef * ADC, char Mode);

void ADC_Sampling_Time (ADC_TypeDef * ADC, char Channel, char SMP);

int ADC_Result (ADC_TypeDef * ADC, char Group);

#endif