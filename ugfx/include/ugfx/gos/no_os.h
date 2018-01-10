/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

/**
 * @file    include/gos/no_no.h
 * @brief   GOS - Operating System Support header file for system without operating system.
 */

#ifndef _GOS_NO_OS_H
#define _GOS_NO_OS_H

#if GFX_USE_OS_NONE

#include <stdlib.h>
/*===========================================================================*/
/* Type definitions                                                          */
/*===========================================================================*/

/**
 * bool_t,
 * int8_t, uint8_t,
 * int16_t, uint16_t,
 * int32_t, uint32_t,
 * size_t
 * TRUE, FALSE
 * TIME_IMMEDIATE, TIME_INFINITE
 * are already defined by ChibiOS
 */
#define TIME_IMMEDIATE				0
#define TIME_INFINITE				((delaytime_t)-1)

typedef int8_t		bool_t;

typedef uint32_t	delaytime_t;
typedef uint32_t	systemticks_t;
typedef uint16_t	semcount_t;
typedef uint32_t	threadreturn_t;
typedef uint32_t	threadpriority_t;

#define MAX_SEMAPHORE_COUNT			((semcount_t)(((unsigned long)((semcount_t)(-1))) >> 1))
#define LOW_PRIORITY				0
#define NORMAL_PRIORITY				0
#define HIGH_PRIORITY				0

#define DECLARE_THREAD_STACK(name, sz)			/* WORKING_AREA(name, sz) */ int (name) = 0
#define DECLARE_THREAD_FUNCTION(fnName, param)	threadreturn_t fnName(void *param)

typedef struct { int32_t counter; } gfxSem;
typedef struct {} gfxMutex;
typedef uint32_t gfxThreadHandle;

/*===========================================================================*/
/* Function declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

#define gfxExit()					chSysHalt()
#define gfxAlloc(sz)				malloc(sz)
#define gfxFree(ptr)				free(ptr)
#define gfxYield()					/* chThdYield() // only used in GTimer */
#define gfxSystemTicks()			/* chTimeNow() */ 0
#define gfxMillisecondsToTicks(ms)	ms	// only used in GInput & GTimer
#define gfxSystemLock()
#define gfxSystemUnlock()
#define gfxMutexInit(pmutex)		/* chMtxInit(pmutex) */
#define gfxMutexDestroy(pmutex)		/* {} */
#define gfxMutexEnter(pmutex)		/* chMtxLock(pmutex) */
#define gfxMutexExit(pmutex)		/* chMtxUnlock() */
void *gfxRealloc(void *ptr, size_t oldsz, size_t newsz);
void gfxSleepMilliseconds(delaytime_t ms);
void gfxSleepMicroseconds(delaytime_t ms);
void gfxSemInit(gfxSem *psem, semcount_t val, semcount_t limit);
void gfxSemDestroy(gfxSem *psem);
bool_t gfxSemWait(gfxSem *psem, delaytime_t ms);
void gfxSemSignal(gfxSem *psem);
void gfxSemSignalI(gfxSem *psem);
#define gfxSemCounterI(psem)		/* ((psem)->sem.s_cnt) */ 0
#define gfxSemCounter(psem)			/* ((psem)->sem.s_cnt) */ 0
gfxThreadHandle gfxThreadCreate(void *stackarea, size_t stacksz, threadpriority_t prio, DECLARE_THREAD_FUNCTION((*fn),p), void *param);
#define gfxThreadWait(thread)		/* chThdWait(thread) */
#define gfxThreadMe()				/* chThdSelf() */
#define gfxThreadClose(thread)		/* {} */




#ifdef __cplusplus
}
#endif

#endif /* GFX_USE_OS_NONE */
#endif /* _GOS_NO_OS_H */
