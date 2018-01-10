#ifndef BOARD_LCD_BACKLIGHT_H
#define BOARD_LCD_BACKLIGHT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void lcdBacklightInitialize();
void lcdBacklightSet(uint8_t percent);

#ifdef __cplusplus
}
#endif

#endif // BOARD_LCD_BACKLIGHT_H
