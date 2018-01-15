#ifndef INITIALEVENT_H
#define INITIALEVENT_H


#include "xfevent.h"


/**
 * Represents the first transition executed in a state machine.
 */
class InitialEvent : public XFEvent
{
public:
    InitialEvent();
	virtual ~InitialEvent();

    // XFEvent interface
public:
    virtual bool deleteAfterConsume();
};

#endif // INITIALEVENT_H
