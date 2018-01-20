#ifndef GUI_H
#define GUI_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void guiInit();
void guiDrawGraphPoints(uint16_t * values, uint16_t count, uint16_t* triggerLevel);
void guiDrawTrigger(uint16_t level);

#ifdef __cplusplus
}
#endif
#endif /* GUI_H_ */

