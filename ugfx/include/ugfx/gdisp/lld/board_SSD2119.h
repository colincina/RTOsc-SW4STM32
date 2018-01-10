/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

#include "stm32f4xx_hal.h"
#include "board/lcdbacklight.h"

/* Using FSMC A19 (PE3) as DC */
#ifdef BOARD_STM32F4_DISCOVERY
#define GDISP_REG (*((volatile uint16_t *) 0x60000000)) /* DC = 0 */
#define GDISP_RAM (*((volatile uint16_t *) 0x60100000)) /* DC = 1 */
#define GDISP_DMA_STREAM STM32_DMA2_STREAM6
static const struct gpio_t reset_pin = DEF_GPIOD( 3, GPIO_OUTPUT_1 | GPIO_SPEED_100);
#endif

#ifdef BOARD_ARMEBS4
	#define GDISP_REG (*((volatile uint16_t *) 0x64000000)) /* DC = 0 */
	#define GDISP_RAM (*((volatile uint16_t *) 0x64100000)) /* DC = 1 */
	#define GDISP_DMA_STREAM STM32_DMA2_STREAM6
#else
	#warning "UGFX Display adaption: No board specified! Taking default (Armebs4) values!"
	#define GDISP_REG (*((volatile uint16_t *) 0x64000000)) /* DC = 0 */
	#define GDISP_RAM (*((volatile uint16_t *) 0x64100000)) /* DC = 1 */
	#define GDISP_DMA_STREAM STM32_DMA2_STREAM6
#endif

static inline void init_board(GDisplay *g) {

	// Only one display
	g->board = NULL;

	// Initialisation of the reset pin (DISPLAY_RESET) is done by STM32CubeMX generated code.
}

static inline void post_init_board(GDisplay *g) {
	(void) g;
}

static inline void setpin_reset(GDisplay *g, bool_t state) {
	(void) g;
	HAL_GPIO_WritePin(DISPLAY_RESET_GPIO_Port, DISPLAY_RESET_Pin, (state) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

static inline void set_backlight(GDisplay *g, uint8_t percent) {
	(void) g;

	lcdBacklightSet(percent);
}

static inline void acquire_bus(GDisplay *g) {
	(void) g;
}

static inline void release_bus(GDisplay *g) {
	(void) g;
}

static inline void write_index(GDisplay *g, uint16_t index) {
	(void) g;
	GDISP_REG = index;
}

static inline void write_data(GDisplay *g, uint16_t data) {
	(void) g;
	GDISP_RAM = data;
}

static inline void setreadmode(GDisplay *g) {
	(void) g;
}

static inline void setwritemode(GDisplay *g) {
	(void) g;
}

static inline uint16_t read_data(GDisplay *g) {
	(void) g;
	return GDISP_RAM;
}

#if defined(GDISP_USE_DMA)
	static inline void dma_with_noinc(GDisplay *g, color_t *buffer, int area) {
		(void) g;
		dmaStreamSetPeripheral(GDISP_DMA_STREAM, buffer);
		dmaStreamSetMode(GDISP_DMA_STREAM, STM32_DMA_CR_PL(0) | STM32_DMA_CR_PSIZE_HWORD | STM32_DMA_CR_MSIZE_HWORD | STM32_DMA_CR_DIR_M2M);
		for (; area > 0; area -= 65535) {
			dmaStreamSetTransactionSize(GDISP_DMA_STREAM, area > 65535 ? 65535 : area);
			dmaStreamEnable(GDISP_DMA_STREAM);
			dmaWaitCompletion(GDISP_DMA_STREAM);
		}
	}

	static inline void dma_with_inc(GDisplay *g, color_t *buffer, int area) {
		(void) g;
        dmaStreamSetPeripheral(GDISP_DMA_STREAM, buffer);
        dmaStreamSetMode(GDISP_DMA_STREAM, STM32_DMA_CR_PL(0) | STM32_DMA_CR_PINC | STM32_DMA_CR_PSIZE_HWORD | STM32_DMA_CR_MSIZE_HWORD | STM32_DMA_CR_DIR_M2M);
		for (; area > 0; area -= 65535) {
			dmaStreamSetTransactionSize(GDISP_DMA_STREAM, area > 65535 ? 65535 : area);
			dmaStreamEnable(GDISP_DMA_STREAM);
			dmaWaitCompletion(GDISP_DMA_STREAM);
		}
	}
#endif

#endif /* _GDISP_LLD_BOARD_H */

