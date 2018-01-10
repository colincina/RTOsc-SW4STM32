#include "stm32f4xx_hal.h"
#include "lcdtouch.h"


void lcdTouchEnableIrq()
{
	// On the Armebs4 board the IRQ_TOUCH pin is on GPIO PF11
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void lcdTouchDisableIrq()
{
	HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
}
