/*
 * StateMachine.cpp
 *
 *  Created on: 17 janv. 2018
 *      Author: Colin Cina
 */

#include <fsm/StateMachine.h>

StateMachine::StateMachine(uint16_t* pArrAdd, uint16_t pLength, uint16_t* triglvlAddr) :
currentState(ST_INIT),
points(pArrAdd),
length(pLength),
triggerLevel(triglvlAddr)
{}

StateMachine::~StateMachine()
{}

EventStatus StateMachine::process(XFEvent* pEvent)
{
	EventStatus evStat;
	SM_STATES oldstates = currentState;
	switch(currentState)
	{
		case ST_INIT:
			if(pEvent->getEventType() == XFEvent::eEventType::Initial)
			{
				currentState = ST_WAIT;
			}
			break;

		case ST_WAIT:
			if(pEvent->getEventType() == XFEvent::eEventType::Timeout)
			{
				currentState = ST_DISPLAY;
			}
			break;

		case ST_DISPLAY:
			if(pEvent->getEventType() == XFEvent::eEventType::NullTransition)
			{
				currentState = ST_WAIT;
			}
			break;

		default:
			break;
	}

	if(oldstates != currentState)
	{
		switch (currentState)
		{
			case ST_WAIT:
				scheduleTimeout(0, 1600);
				break;

			case ST_DISPLAY:
				guiDrawGraphPoints(points, length, triggerLevel);
				GEN(XFNullTransition());
				break;

			default:
				break;
		}
		evStat._status = eEventStatus::Consumed;
	}
	else
	{
		evStat._status = eEventStatus::NotConsumed;
	}
	return evStat;
}
