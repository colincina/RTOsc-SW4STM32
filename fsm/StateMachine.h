/*
 * StateMachine.h
 *
 *  Created on: 17 janv. 2018
 *      Author: Colin Cina
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#include "xf/xfreactive.h"
#include "xf/xf.h"
#include "xf/xfevent.h"
#include "xf/xfeventstatus.h"
#include "osc/gui.h"


class StateMachine : public XFReactive
{
public:
	enum SM_STATES { ST_INIT, ST_WAIT, ST_DISPLAY };
	StateMachine(uint16_t* pArrAdd, uint16_t pLength, uint16_t* triglvlAddr);
	virtual ~StateMachine();
	virtual EventStatus process(XFEvent * pEvent);		///< Called by the thread to process an event.

private:
	SM_STATES currentState;
	uint16_t* points;
	uint16_t length;
	uint16_t* triggerLevel;
};

#endif /* STATEMACHINE_H_ */
