/*
 * FSMWrapper.cpp
 *
 *  Created on: 20 janv. 2018
 *      Author: Colin Cina
 */

#include <fsm/FSMWrapper.h>
#include "fsm/StateMachine.h"
#define MUTE_FSM_WRAPPER_IN_CPP_WARNING

void fsmSetUp(uint16_t * pArrAdd, uint16_t pLength, uint16_t* triggerLevel)
{
	StateMachine* fsm = new StateMachine(pArrAdd, pLength, triggerLevel);
	fsm->startBehavior();
}
