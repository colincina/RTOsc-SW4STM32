#ifndef IXFREACTIVE_H
#define IXFREACTIVE_H


#include <string>
#include "xfevent.h"
#include "xfeventstatus.h"


/**
 * Interface that needs to be implemented by every class having a
 * behavior. Interface methods are needed by the other parts of the XF.
 */
class IXFReactive
{

public:
	IXFReactive() {}
	virtual ~IXFReactive() {}

	virtual void startBehavior() = 0;						///< Starts the behavior.
	virtual void pushEvent(XFEvent * pEvent) = 0;			///< Injects an event into the class.
	virtual EventStatus process(XFEvent * pEvent) = 0;		///< Called by the thread to process an event.
};

#endif // IXFREACTIVE_H
