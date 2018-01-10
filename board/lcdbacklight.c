#include "stm32f4xx_hal.h"
#include "lcdbacklight.h"

void lcdBacklightInitialize()
{
	// Initialisation is done in CubeMX project config
}

void lcdBacklightSet(uint8_t percent)
{
	TIM5->CCR4 = percent;
}
