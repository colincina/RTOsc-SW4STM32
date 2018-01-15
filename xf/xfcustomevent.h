#ifndef XFEVENT_H
#define XFEVENT_H

#include "xf.h"
#include "xfevent.h"

/**
 * Base class for all events. When intending to signal an event, derive
 * a new class from this class.
 */
class XFCustomEvent : public XFEvent
{
public:
	/**
	 * Constructor for the class
	 *
	 * \param id Identifier uniquely identifying the event in the context of the behavior.
	 * \param pBehavior The behavior for which the event was constructed (will consume the event).
	 **/
	XFCustomEvent(int id, IXFReactive * pBehavior = NULL);
	virtual ~XFCustomEvent();

	virtual bool deleteAfterConsume() { return _bDeleteAfterConsume; }

protected:
	void setDeleteAfterConsume(bool bDeleteAfterConsume = true) { _bDeleteAfterConsume = bDeleteAfterConsume; }

protected:
	bool _bDeleteAfterConsume;
};

#endif // XFEVENT_H
