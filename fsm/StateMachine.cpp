/*
 * StateMachine.cpp
 *
 *  Created on: 17 janv. 2018
 *      Author: Colin Cina
 */

#include <fsm/StateMachine.h>

StateMachine::StateMachine() :
currentState(ST_INIT)
{}

StateMachine::~StateMachine()
{}

void StateMachine::startBehavior()
{
	GEN(InitialEvent());
}

void StateMachine::pushEvent(XFEvent* pEvent)
{
	XF::getMainThread()->pushEvent(pEvent);
}

EventStatus StateMachine::process(XFEvent* pEvent)
{
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
				scheduleTimeout(0, 16);
				break;

			case ST_DISPLAY:
				guiDrawGraphPoints(points, POINTS_NB);
				break;

			default:
				break;
		}
	}
}
