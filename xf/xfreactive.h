#ifndef XFREACTIVE_H
#define XFREACTIVE_H


#include "ixfreactive.h"
#include "xfeventstatus.h"
#include "xfthread.h"
#include "xftimeout.h"
#include "xfnulltransition.h"
#include "initialevent.h"

/**
 * Reactive class implementing a behavior. This class can be used to implement a
 * state machine behavior or an activity behavior.
 *
 * Override the processEvent() operation in the inherited class to implement
 * your state machine behavior.
 */
class XFReactive : public IXFReactive
{
    friend class XFThread;
public:
	#define GEN(event) pushEvent(new event);

	/**
	 * Constructor
	 *
	 * \param pThread Reference to thread who will process the behavioral part of this reactive class.
	 */
	XFReactive(XFThread * pThread = NULL);
	virtual ~XFReactive();

	virtual void startBehavior();					///< Starts the behavior, resp. the state machine.

	virtual void pushEvent(XFEvent * pEvent);

protected:
	/**
	 * Executes the current event in its implemented behavior.
	 * This method needs to be overriden to implement the
	 * behavior (i.e. state machine) needed.
	 */
	virtual EventStatus processEvent();
	virtual XFThread * getThread();					///< Returns reference to #_pThread.

	XFEvent * getCurrentEvent() const;				///< Returns the current event to be processed in processEvent().

	/** \brief Returns a refence to the actually processed timeout.
	 *
	 * Will work only if the current event is of type IXFEvent::Timeout.
	 */
	XFTimeout * getCurrentTimeout();

	inline void scheduleTimeout(int timeoutId, int interval) { getThread()->scheduleTimeout(timeoutId, interval, this); }	///< @brief Schedules a timeout for this state machine.
	inline void unscheduleTimeout(int timeoutId) { getThread()->unscheduleTimeout(timeoutId, this); }						///< @brief Unschedules a timeout for this state machine.

	void startSubStateMachine() { GEN(InitialEvent()); }	///< Starts submachine(s) in composite state.

private:
	void setCurrentEvent(XFEvent * pEvent);		///< Sets the current event to be processed in processEvent().

	/**
	 * \brief Processes the given event.
	 *
	 * This may change the state of the class
	 * according to its implemented behavior.
	 *
	 * Must only be called by the associated thread (see #_pThread).
	 *
	 * \param pEvent The event to process.
	 */
	virtual EventStatus process(XFEvent * pEvent);

protected:
	XFThread * _pThread;							///< Reference to Thread executing this behavior.
	XFEvent * _pCurrentEvent;						///< Reference to actually processed event.
};

#endif // XFREACTIVE_H
