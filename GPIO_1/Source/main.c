#include "stm32f10x.h"
int main(void){
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	
	GPIOA->CRL &= ~(0xf << 5*4);
	GPIOA->CRL |= (2 << 5*4);
	
	GPIOC->CRH &= ~(0xf << 5*4);
	GPIOC->CRH |= (4 << 5*4);
	while(1) {
		if (((GPIOC->IDR >> 13) & 1) == 0) {
			GPIOA->ODR |= (1 << 5);
		} 
		else {
			GPIOA->ODR &= ~(1 << 5);
		}
	}
}	
