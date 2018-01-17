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
#include "osc/gui.h"

#define POINTS_NB 300

class StateMachine : public XFReactive
{
public:
	enum SM_STATES { ST_INIT, ST_WAIT, ST_DISPLAY }
	StateMachine();
	virtual ~StateMachine();

	virtual void startBehavior();						///< Starts the behavior.
	virtual void pushEvent(XFEvent * pEvent);			///< Injects an event into the class.
	virtual EventStatus process(XFEvent * pEvent);		///< Called by the thread to process an event.

private:
	SM_STATES currentState;
	uint16_t points[POINTS_NB];
};

#endif /* STATEMACHINE_H_ */
