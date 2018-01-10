#ifndef CONFIG_H
#define CONFIG_H

#ifdef BOARD_ARMEBS4
	#include <stdint.h>
	#include <stddef.h>
	#include "stm32f4xx_hal.h"

	#define ASSERT(expr) assert_param(expr)

#ifndef UNUSED
	#define UNUSED(x) (void)x
#endif

#endif // BOARD_ARMEBS4

#endif /* CONFIG_H_ */
