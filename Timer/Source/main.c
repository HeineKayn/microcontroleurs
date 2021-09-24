#include "Driver_Timer.h"
#include "Driver_GPIO.h"

// Handler d'interruption
// Inverse l'état de la LED
void callback() {
	GPIO_Toggle(GPIOA, 5);
}


int main(void){
	// Initialisation de la GPIO de la LED
	GPIO_Init(GPIOA, 5, Out_Ppull_2MHZ);
	
	// Initialisation du Timer 2 (500ms)
	Timer_Base_Init(TIM2, 44999, 799);
	// Activation de l'interruption du Timer 2 (priorité max)
	Timer_ActiveIT(TIM2, 0, callback);
	
	// Lancement du Timer 2
	Timer_Base_Start(TIM2);
	
	while(1);
}	
