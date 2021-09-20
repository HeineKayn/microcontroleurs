#include "Driver_Timer.h"

int main(void){
	Timer_Base_Init(TIM2, 44999, 799);
	
	Timer_Base_Start(TIM2);
	
	while(1);
}	
