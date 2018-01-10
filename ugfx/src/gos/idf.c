/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

/**
 * @file    src/gos/chibios.c
 * @brief   GOS ChibiOS Operating System support.
 */
#if USE_UGFX
#include "ugfx/gfx.h"
#if GFX_USE_OS_IDF

#include "heivs/delay.h"

#include <string.h>

//SAP #if !CH_USE_MUTEXES
//SAP 	#error "GOS: CH_USE_MUTEXES must be defined in chconf.h"
//SAP #endif
//SAP #if !CH_USE_SEMAPHORES
	//SAP #error "GOS: CH_USE_SEMAPHORES must be defined in chconf.h"
//SAP #endif

/* Our module initialiser */
void _gosInit(void) {
	/* Don't initialise if the user already has */
//SAP 	if (!chThdSelf()) {
//SAP 		halInit();
//SAP 		chSysInit();
//SAP 	}
}

void * gfxRealloc(void *ptr, size_t oldsz, size_t newsz)
{
	void * np;

	if (newsz <= oldsz)
		return ptr;

	np = gfxAlloc(newsz);
	if (!np)
		return 0;

	if (oldsz)
		memcpy(np, ptr, oldsz);

	return np;
}

void gfxSleepMilliseconds(delaytime_t ms) {

	delay_wait_ms(ms);
}

void gfxSleepMicroseconds(delaytime_t us) {
	delay_wait_us(us);
}

void gfxSemInit(gfxSem * psem, semcount_t val, semcount_t limit)
{
	psem->counter = 0;
}

void gfxSemDestroy(gfxSem *psem)
{

}

bool_t gfxSemWait(gfxSem *psem, delaytime_t ms)
{
//	psem->counter--;
	return TRUE;
}

void gfxSemSignal(gfxSem *psem)
{
//	psem->counter++;
}

void gfxSemSignalI(gfxSem *psem)
{
//	psem->counter++;
}

gfxThreadHandle gfxThreadCreate(void * stackarea, size_t stacksz, threadpriority_t prio, DECLARE_THREAD_FUNCTION((*fn),p), void * param)
{
	return 0;
}

#endif /* GFX_USE_OS_IDF */
/** @} */
#endif /* USE_UGFX */
