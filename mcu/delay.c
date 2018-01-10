/************************************************************************//**
 * \file	heivs/delay.c
 * \brief	simple delays
 * \author	marc dot pignat at hevs dot ch
 ***************************************************************************/

#include "stm32f4xx_hal.h"
#include "delay.h"

void delay_wait_ms(uint32_t ms)
{
	uint32_t i;
	for (i = 0 ; i < ms ; i++)
	{
		delay_wait_us(1000);
	}
}

/**
 * \brief Delay loop
 *
 * \param n wait for 3*n CPU clocks
 */
__attribute__ ((naked))
static void _delay_loop(uint32_t n)
{
	asm volatile
	(
		"1:						\n"
		"	subs.n	%0, #1		\n" /* This is one clock */
		"	bne.n	1b			\n" /* 1+P here is 2 clocks (destination is know and a 16-bit instruction) */
		"	bx		lr			\n"
		:
		: "r" (n)
		: "cc"
	);
}

void delay_wait_us(uint32_t us)
{
	uint32_t hz;
	uint32_t mhz;
	uint32_t i;
	const uint32_t hclk = HAL_RCC_GetSysClockFreq();

	if (us > 1000)
	{
		/**
		 * What a looooong wait, call the milisecond version after rounding up
		 */
		delay_wait_ms((us+999)/1000);
		return;
	}

	/**
	 * Split clock between Hz and MHz
	 */
	mhz = hclk / (1000*1000);
	hz = hclk % (1000*1000);

	/* Multiply by us, can't overflow because us <= 1000 */
	hz *= us;
	hz /= (1000*1000);

	/* Convert to the number of iteration */
	i = mhz * us;
	i += (hz * us) / (1000 * 1000);

	/* Divide by the number of clocks in a loop, see: the _delay_loop ;) */
	i /= 3;

	/**
	 * The wait loop is in the form (--i > 0){}, so if i is zero, this loop will
	 * be far too long.
	 * There is only two way of falling here, clock or us are zero.
	 */
	if (i == 0)
	{
		return;
	}

	_delay_loop(i);
}



