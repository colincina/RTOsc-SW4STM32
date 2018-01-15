#include "xfthread.h"
#include "ixfreactive.h"
#include "xftimeoutmanager.h"

XFThread::XFThread()
#ifdef TC_QTCREATOR
    : _theMutex(QMutex::Recursive)
#endif // TC_QTCREATOR
{}

XFThread::~XFThread(){}

void XFThread::start()
{
    _bExecuting = true;
    execute();
}

void XFThread::stop()
{
    _bExecuting = false;
}

void XFThread::pushEvent(XFEvent *pEvent)
{
	#ifdef TC_QTCREATOR
		_theMutex.lock();
	#endif // TC_QTCREATOR

	#ifdef BOARD_ARMEBS4
		enterCritical();
	#endif // BOARD_ARMEBS4
    _events.push(pEvent);
	#ifdef TC_QTCREATOR
    	_theMutex.unlock();
	#endif // TC_QTCREATOR

	#ifdef BOARD_ARMEBS4
		exitCritical();
#endif // BOARD_ARMEBS4
}

void XFThread::scheduleTimeout(int timeoutId, int interval, IXFReactive *pReactive)
{
    XFTimeoutManager::getInstance()->scheduleTimeout(timeoutId, interval, pReactive);
}

void XFThread::unscheduleTimeout(int timeoutId, IXFReactive *pReactive)
{
    XFTimeoutManager::getInstance()->unscheduleTimeout(timeoutId, pReactive);
}

void XFThread::execute()
{
    while(_bExecuting)
    {
        if(!_events.empty())
        {
			#ifdef TC_QTCREATOR
                _theMutex.lock();
			#endif // TC_QTCREATOR

			#ifdef BOARD_ARMEBS4
				enterCritical();
			#endif // BOARD_ARMEBS4
        	XFEvent* temp = _events.front();
        	_events.pop();
			#ifdef TC_QTCREATOR
                _theMutex.unlock();
			#endif // TC_QTCREATOR

			#ifdef BOARD_ARMEBS4
				exitCritical();
			#endif // BOARD_ARMEBS4
            dispatchEvent(temp);
        }
    }
}

XFTimeoutManager *XFThread::getTimeoutManager() const
{
    return XFTimeoutManager::getInstance();
}

void XFThread::dispatchEvent(XFEvent *pEvent) const
{
    EventStatus tempStat = pEvent->getBehavior()->process(pEvent);
    if(tempStat ==  EventStatus::Terminate)
    {
        delete pEvent->getBehavior();
    }

    if(pEvent->deleteAfterConsume())
    {
        delete pEvent;
    }
}
