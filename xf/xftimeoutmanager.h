#ifndef XFTIMEOUTMANAGER_H
#define XFTIMEOUTMANAGER_H


#ifdef TC_QTCREATOR
  #include <QObject>
  #include <QMutex>
#endif // TC_QTCREATOR
#include <list>
#include "xftimeout.h"

using namespace std;

/**
 * The TimeoutManager is responsible to handle timeouts used
 * in state machines. It decrements them accordingly and inject
 * them back to the state machine when timeouted.
 *
 * <b>Requirements:</b>
 * - Implements the Singleton pattern
 * - Handle timeouts (hold, decrement, re-inject)
 */
#ifdef TC_QTCREATOR
class XFTimeoutManager : public QObject
{
    Q_OBJECT
#else
class XFTimeoutManager
{
#endif // TC_QTCREATOR

	typedef list<XFTimeout *> TimeoutList;		///< Type used for the _timeouts property.

public:
	static XFTimeoutManager * getInstance();	///< Returns a pointer to the single instance of XFTimeoutManager.
	
	/**
	 * Sets the time interval in milliseconds in which the timeout manager
	 * should handle the timeouts.
	 */
	void setTickInterval(int tickInterval);
	
	/**
	 * Starts the timeout manager.
	 */
	void start();

	/**
	 * Adds a timeout to the timeout manager.
	 *
	 * \param timeoutId The timeout id known by the reactive parameter. Is needed by the reactive part to uniquely identify the timeout.
	 * \param interval The time in milliseconds to wait until the timeout expires.
	 * \param pReactive The reactive instance where to inject the timeout when it timeouts.
	 */
	void scheduleTimeout(int timeoutId, int interval, IXFReactive * pReactive);
	
	/**
	 * Removes all timeouts corresponding the given parameters.
	 */
	void unscheduleTimeout(int timeoutId, IXFReactive * pReactive);
	
	/** \brief Called regularly in XFTimeoutManager::_tickInterval time.
	 * 
	 * On each call to this method, XFTimeoutManager::_tickInterval will be removed from the
	 * timeouts. When a timeout expires it is injected back to its reactive instance.
	 */
	void tick();

protected:
	void addTimeout(XFTimeout * pNewTimeout);	///< Adds the timeout to #_timeouts.
	
	/**
	 * Removes all timeouts corresponding the given parameters.
	 */
    void removeTimeouts(int timeoutId, IXFReactive * pReactive);

	/**
	 * Returns the timeout back to the queue of the thread executing
	 * the behavioral instance.
	 */
	void returnTimeout(XFTimeout * pTimeout);	///< Returns timeout back to behavioral class.

private:

    /**
     * @brief XFTimeoutManager constructors destructor and operator=
     * @details     The following elements are declared as private in order to forbid any uncontrolled instanciation
     *              since this class implements the singleton pattern
     */
    XFTimeoutManager();
    ~XFTimeoutManager();
    XFTimeoutManager(const XFTimeoutManager& p1);
    XFTimeoutManager& operator=(const XFTimeoutManager& p1);

#ifdef BOARD_ARMEBS4
	/**
	 * Initializes and starts a hardware timer, which will call XFTimeoutManager::tick()
	 * in a regular interval given by parameter tickTime.
	 *
	 * \param tickTime Time in milliseconds the hardware timer should call XFTimeoutManager::tick().
	 */
	void startHardwareTimer(int tickTime);		///< Starts the hardware timer on the target hardware.
#endif // BOARD_ARMEBS4

#ifdef TC_QTCREATOR
	void timerEvent(QTimerEvent * event);		///< Reimplementation from QObject class. Callback method for timers.
#endif // TC_QTCREATOR

protected:
	static XFTimeoutManager * _pInstance;		///< Pointer to single instance of XFTimeoutManager.
	int _tickInterval;							///< Interval in milliseconds the XFTimeoutManager is decrementing the timeouts.
	TimeoutList _timeouts;						///< Container holding timeouts to manage

#ifdef TC_QTCREATOR
	int _timerId;		///< Timer id received when starting timer QT timer handling (see setTickInterval(int)).
	QMutex _theMutex;
#endif // TC_QTCREATOR
};

#endif // XFTIMEOUTMANAGER_H
