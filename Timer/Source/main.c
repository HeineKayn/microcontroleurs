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

	// Initialisation du Timer 2 (100kHz)
	Timer_Base_Init(TIM2, 719, 0);
	
	// Initialisation de la pin 2 du GPIO A
	GPIO_Init(GPIOA, 2, AltOut_Ppull_2MHZ);
	
	// Initialisation de la PWM sur le channel 3 du Timer 2
	Timer_PWM(TIM2, 3);
	
	// Etablissement du rapport cyclique à 20%
	Timer_Set_Cycle_PWM(TIM2, 3, 20);
	
	// Lancement du compteur
	Timer_Base_Start(TIM2);
	while(1);
}	
