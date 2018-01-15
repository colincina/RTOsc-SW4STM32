#ifndef XF_C_WRAPPER_H
#define XF_C_WRAPPER_H

#include <stdint.h>

#ifdef __cplusplus
	#ifndef MUTE_XF_WRAPPER_IN_CPP_WARNING
		#warning "This header should not be included in C++ source code!"
	#endif // MUTE_XF_WRAPPER_IN_CPP_WARNING
	#undef MUTE_XF_WRAPPER_IN_CPP_WARNING
#endif

#ifdef __cplusplus
#ifdef MUTE_XF_WRAPPER_IN_CPP
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

void xfInit(int timeInterval);
void xfStart();
void xfTimeoutManagerTick();

#ifdef __cplusplus
}
#endif

#endif /* XF_C_WRAPPER_H */
