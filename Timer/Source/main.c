#include "Driver_Timer.h"
#include "Driver_GPIO.h"

// Handler d'interruption
// Inverse l'état de la LED
void callback() {
	GPIO_Toggle(GPIOA, 5);
}


int main(void){
	/*
	// Initialisation de la GPIO de la LED
	GPIO_Init(GPIOA, 5, Out_Ppull_2MHZ);
	
	// Initialisation du Timer 2 (500ms)
	Timer_Base_Init(TIM2, 44999, 799);
	// Activation de l'interruption du Timer 2 (priorité max)
	Timer_ActiveIT(TIM2, 0, callback);
	
	// Lancement du Timer 2
	Timer_Base_Start(TIM2);
	*/
	
	/* ------------------- */	

	// Initialisation du Timer 4 (100kHz)
	Timer_Base_Init(TIM4, 719, 0);
	
	// Initialisation de la pin 6 du GPIO B
	GPIO_Init(GPIOB, 6, AltOut_Ppull_2MHZ);
	
	// Initialisation de la PWM sur le channel 1 du Timer 4
	Timer_PWM(TIM4, 1);
	
	// Etablissement du rapport cyclique à 20%
	Timer_Set_Cycle_PWM(TIM4, 1, 20);
	
	// Lancement du compteur
	Timer_Base_Start(TIM4);
	while(1);
}	
