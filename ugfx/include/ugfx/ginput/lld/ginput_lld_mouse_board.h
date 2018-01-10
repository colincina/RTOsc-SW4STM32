/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GINPUT_LLD_MOUSE_BOARD_H
#define _GINPUT_LLD_MOUSE_BOARD_H

#include <assert.h>
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

static I2C_HandleTypeDef * bus = &hi2c1;

static void init_board(void)
{
	// Initialization of IRQ pin and I2C is done by STM32CubeMX generated code.
}

static inline bool_t getpin_irq(void)
{
//    return (HAL_GPIO_ReadPin(IRQ_TOUCH_GPIO_Port, IRQ_TOUCH_Pin) == GPIO_PIN_RESET);
	return 0;
}

static void write_reg(uint8_t reg, uint8_t n, uint16_t val)
{
	/* Buffer to store TX data (address + rw and data) */
	uint8_t tx1[] =
	{
			val
	};

	uint8_t tx2[] =
	{
			val >> 8,
			val,
	};

	if (n == 1)
	{
		HAL_I2C_Mem_Write(bus, STMPE811_ADDR << 1, reg, 1, tx1, 1, 100);
	}
	else if (n == 2)
	{
		HAL_I2C_Mem_Write(bus, STMPE811_ADDR << 1, reg, 1, tx2, 2, 100);
	}
}
 
static uint16_t read_reg(uint8_t reg, uint8_t n)
{
	HAL_StatusTypeDef status;
	uint8_t rx[2];				// Buffer to store RX data

	status = HAL_I2C_Mem_Read(bus, STMPE811_ADDR << 1, reg, 1, rx, (n < 2) ? n : 2, 200);

	if (status != HAL_OK)
	{
		assert(FALSE);
	}

	if(n == 1)
	{
		return rx[0];
	}
	uint16_t tmp;
	tmp = rx[0];
	tmp <<= 8;
	tmp |= rx[1];
	return tmp;
}

#endif /* _GINPUT_LLD_MOUSE_BOARD_H */

