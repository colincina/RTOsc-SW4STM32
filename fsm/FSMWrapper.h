/*
 * FSMWrapper.h
 *
 *  Created on: 20 janv. 2018
 *      Author: Colin Cina
 */

#ifndef FSMWRAPPER_H_
#define FSMWRAPPER_H_

#include <stdint.h>

#ifdef __cplusplus
	#ifndef MUTE_FSM_WRAPPER_IN_CPP_WARNING
		#warning "This header should not be included in C++ source code!"
	#endif // MUTE_FSM_WRAPPER_IN_CPP_WARNING
	#undef MUTE_FSM_WRAPPER_IN_CPP_WARNING
#endif

#ifdef __cplusplus
#ifdef MUTE_FSM_WRAPPER_IN_CPP
#warning "This header should not be included in C++ source code!"
#endif
extern "C" {
#endif

/**
 * @brief XF to C wrapper. Allows to initialize and start XF in C.
 *
 * This XF wrapper may be useful where the main function is implemented in
 * C programming language (main.c). This allows to initialize and start
 * the XF in C.
 */

void fsmSetUp(uint16_t * pArrAdd, uint16_t pLength, uint16_t* triggerLevel);

#ifdef __cplusplus
}
#endif
#endif /* FSMWRAPPER_H_ */
