#ifndef XFNULLTRANSITION_H
#define XFNULLTRANSITION_H


#include "xf.h"
#include "xfevent.h"


/**
 * Represents a transition in a state machine having no trigger.
 */
class XFNullTransition : public XFEvent
{
public:
	/**
	 * Constructor
	 *
	 * \param pBehavior Behavior in which the null transition will be executed.
	 */
	XFNullTransition(IXFReactive * pBehavior = NULL);
	virtual ~XFNullTransition();

    // XFEvent interface
public:
    virtual bool deleteAfterConsume();
};

#endif // XFNULLTRANSITION_H
