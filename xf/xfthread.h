#ifndef XFTHREAD_H
#define XFTHREAD_H

#include <queue>
#include "xfevent.h"
#include <iterator>

#ifdef BOARD_ARMEBS4
	#include "xf/critical/critical.h"
#endif // BOARD_ARMEBS4

#ifdef TC_QTCREATOR
#include <QMutex>
#endif //TC_QTCREATOR

using namespace std;

class XFTimeoutManager;
class XFReactive;

/**
 * XFThread representing the instance executing the behavior. In a OS less XF,
 * only one instance of XFThread gets created (see XF::_mainThread). In a XF
 * interfacing an OS, multiple instances can be made, each interfacing the real
 * OS thread.
 */
class XFThread
{
public:
	XFThread();
	virtual ~XFThread();

	void start();										///< Starts the thread.
	void stop();
	void pushEvent(XFEvent * pEvent);					///< Adds event to the #_events queue. 

	/**
	 * Adds a new timeout to be handled. The XFThread will forward the timeout
	 * information to the timeout manager which is responsible to handle all timeouts.
	 */
	void scheduleTimeout(int timeoutId, int interval, IXFReactive * pReactive);

	/**
	 * Removes all timeouts corresponding the given parameters.
	 */
	void unscheduleTimeout(int timeoutId, IXFReactive * pReactive);

protected:

	/**
	 * Main loop of the thread. Implements event loop processing.
	 */
	void execute();
    XFTimeoutManager * getTimeoutManager() const;		///< Returns pointer to timeout manager. Why? XFTimeoutManager is a singleton

	/**
	 * Dispatchs the event to the corresponding behavioral part. For example
	 * the state machine which sould process the event.
	 * \param pEvent The event to dispatch
	 */
	void dispatchEvent(XFEvent * pEvent) const;

protected:
	bool _bExecuting;				///< True as long as the thread is executing the main loop.

	queue<XFEvent *> _events;		///< Queue holding events waiting to get dispatched.
	#ifdef TC_QTCREATOR
	QMutex _theMutex;
	#endif //TC_QTCREATOR

};

#endif // XFTHREAD_H
