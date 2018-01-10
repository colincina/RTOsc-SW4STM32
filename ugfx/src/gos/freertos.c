/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

/**
 * @file    src/gos/freertos.c
 * @brief   GOS FreeRTOS Operating System support.
 */
#if USE_UGFX
#include "ugfx/gfx.h"
#if GFX_USE_OS_FREERTOS
#include "mcu/delay.h"
#include "include/FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include <string.h>

#if configUSE_MUTEXES != 1
	#error "GOS: configUSE_MUTEXES must be enabled in FreeRTOSConfig.h"
#endif

#if configUSE_COUNTING_SEMAPHORES  != 1
	#error "GOS: configUSE_COUNTING_SEMAPHORES must be enabled in FreeRTOSConfig.h"
#endif

#if INCLUDE_vTaskSuspend != 1
	#error "GOS: INCLUDE_vTaskSuspend must be enabled in FreeRTOSConfig.h"
#endif

#ifndef max
	#define max(a,b) ((a) > (b) ? a : b)
#endif

/* Our module initialiser */
void _gosInit(void) {
	// the call to  vTaskStartScheduler(); has to be made before to call gfxInit() in a thread
}

void *gfxRealloc(void *ptr, size_t oldsz, size_t newsz) {
	void *np;

	if (newsz <= oldsz)
		return ptr;

	np = gfxAlloc(newsz);
	if (!np)
		return NULL;

	if (oldsz)
	{
		memcpy(np, ptr, min(newsz, oldsz));
		vPortFree(ptr);
	}
	return np;
}

void gfxSleepMilliseconds(delaytime_t ms) {

	if(ms == TIME_IMMEDIATE) {
		taskYIELD();
	}
	else {
		vTaskDelay(ms);
	}
}

void gfxSleepMicroseconds(delaytime_t us) {

	delay_wait_us(us);
}

TickType_t MS2ST(TickType_t ms) {

	uint64_t	val;

	// Fast path first
	if(configTICK_RATE_HZ == 1000) {
		return ms;
	}
	val = ms;
	val *= configTICK_RATE_HZ;
	val += 999;
	val /= 1000;

	return val;
}

void gfxSemInit(gfxSem *psem, semcount_t val, semcount_t limit)
{
	if (val > limit) {
		val = limit;
	}
	psem->counter = val;
	psem->limit = limit;
///sth	psem->sem = xSemaphoreCreateCountingNamed(limit, val, "uGFXSema");
	psem->sem = xSemaphoreCreateCounting(limit, val);
}

void gfxSemDestroy(gfxSem *psem)
{
	vSemaphoreDelete(psem->sem);
}

bool_t gfxSemWait(gfxSem *psem, delaytime_t ms)
{
	psem->counter--;

	if (ms == TIME_INFINITE) {
		if (xSemaphoreTake(psem->sem, portMAX_DELAY) == pdPASS)	{
			return TRUE;
		}
	} else {
		if(xSemaphoreTake(psem->sem, MS2ST(ms)) == pdPASS) {
			return TRUE;
		}
	}

	psem->counter++;

	return FALSE;
}

void gfxSemSignal(gfxSem *psem)
{
	taskENTER_CRITICAL();
	if (psem->counter < psem->limit) {
		psem->counter++;
		taskEXIT_CRITICAL();
		xSemaphoreGive(psem->sem);
	} else {
		taskEXIT_CRITICAL();
		taskYIELD();
	}
}

void gfxSemSignalI(gfxSem *psem) {
	signed portBASE_TYPE _unused = pdFALSE;

	if(psem->counter < psem->limit) {
		psem->counter++;
		xSemaphoreGiveFromISR(psem->sem, &_unused);
	}
}

gfxThreadHandle gfxThreadCreate(void *stackarea, size_t stacksz, threadpriority_t prio, DECLARE_THREAD_FUNCTION((*fn),p), void *param) {
	TaskHandle_t task = NULL;

	stacksz = max(configMINIMAL_STACK_SIZE, (size_t)stackarea);
	xTaskCreate(fn,"uGFX_TASK",stacksz,param ,prio, &task );

	return task;
}

#endif /* GFX_USE_OS_FREERTOS */
/** @} */
#endif /* USE_UGFX */
