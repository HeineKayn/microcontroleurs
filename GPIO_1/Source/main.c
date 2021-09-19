#include "Driver_GPIO.h"

int main(void){
	// Initialisation des horloges des GPIO
	Driver_Init();
	
	// Initialisation de la PA5 (LED) en Output Push/Pull
	GPIO_Init(GPIOA, 5, Out_Ppull_2MHZ);
	// Initialisation de la PC13 (Bouton) en Floating Input
	GPIO_Init(GPIOC, 13, In_Floating);

	while(1) {
		// En cas d'appuie sur le bouton (ODR == 0)
		if (GPIO_Read(GPIOC, 13) == 0) {
			// On allume la LED (ODR = 1)
			GPIO_Set(GPIOA, 5);
		} 
		else {
			// Sinon on l'éteint (ODR = 0)
			GPIO_Reset(GPIOA, 5);
		}
	}
}	
