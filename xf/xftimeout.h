#ifndef IXFTIMEOUTS_H
#define IXFTIMEOUTS_H

#include "xfevent.h"

/**
 * Interface to be implemented by timeouts. Defined methods are
 * needed by the framework classes (see also: \ref XFTimeoutManager).
 */
class XFTimeout : public XFEvent
{
	friend class XFTimeoutManager;

public:
	/**
	 * Constructor of the class.
	 * \param id The id given by the behavioral class to uniquely identifying the timeout
	 * \param interval The interval in milliseconds the timeout expires
	 * \param pBehavior Pointer to behavioral class to which the timeout belongs
	 */
	XFTimeout(int id, int interval, IXFReactive * pBehavior);
	virtual ~XFTimeout();

	/**
	 * Operator checks if #_pBehavior and #_id are equal and returns
	 * true if so. All other attributes get no attention.
	 */
	bool operator ==(const XFTimeout & timeout) const;

	virtual bool deleteAfterConsume();

protected:
	int _interval;		///< Timeout interval
	int _relTicks;		///< Used by the \ref XFTimeoutManager "TimeoutManager"  to calculate remaining time. Can get negative!
};

#endif // IXFTIMEOUTS_H
