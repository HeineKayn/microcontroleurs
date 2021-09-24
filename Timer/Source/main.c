#include "Driver_Timer.h"
#include "Driver_GPIO.h"

void callback() {
	GPIO_Toggle(GPIOA, 5);
}


int main(void){
	GPIO_Init(GPIOA, 5, Out_Ppull_2MHZ);
	
	Timer_Base_Init(TIM2, 44999, 799);
	Timer_ActiveIT(TIM2, 0, callback);
	
	Timer_Base_Start(TIM2);
	
	while(1);
}	
