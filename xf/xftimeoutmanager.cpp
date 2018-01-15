#ifdef TC_QTCREATOR
	#include <QTimerEvent>
#endif // TC_QTCREATOR

#ifdef BOARD_ARMEBS4
#include "config/config.h"
#include "xf/critical/critical.h"
#endif // BOARD_ARMEBS4
#include "xftimeoutmanager.h"
#include "ixfreactive.h"
#include <iterator>

XFTimeoutManager * XFTimeoutManager::_pInstance = new XFTimeoutManager();

/**
 * @brief XFTimeoutManager::start
 */
void XFTimeoutManager::start()
{
#ifdef TC_QTCREATOR
    _timerId = QObject::startTimer(_tickInterval);
#endif // TC_QTCREATOR

#if defined(BOARD_ARMEBS4) and defined(EXT_TIM)
    startHardwareTimer(_tickInterval);
#endif // defined(BOARD_ARMEBS4) and defined(EXT_TIM)
}

XFTimeoutManager *XFTimeoutManager::getInstance()
{
    return _pInstance;
}

void XFTimeoutManager::setTickInterval(int tickInterval)
{
    _tickInterval = tickInterval;
}

void XFTimeoutManager::scheduleTimeout(int timeoutId, int interval, IXFReactive *pReactive)
{
    //this timeout has to be removed properly! 
    XFTimeout* temp = new XFTimeout(timeoutId, interval, pReactive);
    if(temp == NULL)
    {
        //Trace::out("allocation for timeout has failed");
    }
    else
    {
        addTimeout(temp);
    }
}

void XFTimeoutManager::unscheduleTimeout(int timeoutId, IXFReactive *pReactive)
{
    removeTimeouts(timeoutId, pReactive);
}

void XFTimeoutManager::tick()
{
    if(!_timeouts.empty())
    {
        if(_timeouts.front()->_relTicks == 0) //If there was a timeout with interval 0 scheduled, dequeue it immediately
        {
            while(_timeouts.front()->_relTicks == 0 && !_timeouts.empty())     //while there are timeouts with _interval 0 DIRECTLY after the timeout that has
            {                                                       //expired, they have to be dequeued at the same time.
                returnTimeout(_timeouts.front());
                removeTimeouts(_timeouts.front()->_id, _timeouts.front()->_pBehavior);
            }
        }

        else //Decrement and check the first timeout.
        {
            _timeouts.front()->_relTicks -= _tickInterval;                                                                // the timeout will not last that exact duration but will be extended to one more tick
            while(!_timeouts.empty())                                       //while there are timeouts with _interval 0 DIRECTLY after the timeout that has
            {                                                               //expired, they have to be dequeued at the same time.
                if(_timeouts.front()->_relTicks <= 0)
                {
                    returnTimeout(_timeouts.front());
                    _timeouts.pop_front();
                }
                else
                {
                    break;
                }
            }

         }
     }
}

void XFTimeoutManager::addTimeout(XFTimeout *pNewTimeout)
{
#ifdef TC_QTCREATOR
    _theMutex.lock();
#endif // TC_QTCREATOR

#ifdef BOARD_ARMEBS4
    enterCritical();
#endif // BOARD_ARMEBS4

    TimeoutList::iterator it = _timeouts.begin();

    if(_timeouts.empty() == true)
    {
        _timeouts.push_back(pNewTimeout);
    }

    else
    {
        while(it != _timeouts.end())
        {
            //if the new timeout has a bigger _interval, subtract the _interval of the currently
            //pointed timeout and move on.
            if(pNewTimeout->_relTicks > (**it)._relTicks)
            {
                pNewTimeout->_relTicks -= (**it)._relTicks;
                it++;
                //if we are at the end of the list, inert the new timeout there
                if(it == _timeouts.end())
                {
                    _timeouts.insert(_timeouts.end(), pNewTimeout);
                }
            }

            /*if the new timeout has a smaller _interval, insert it before the currently pointed
            timeout, decrement the currently pointed timeout by the _interval of the new timeout
            and move on*/
            else if(pNewTimeout->_relTicks < (**it)._relTicks)
            {
                it = _timeouts.insert(it, pNewTimeout);
                it++;
                if(it != _timeouts.end())
                {
                    (**it)._relTicks -= pNewTimeout->_relTicks;
                }
                break;
            }

            /*if the new timeout has the same value as the currently pointed timeout, they should
            end at the same time. Insert the new time out after the currently pointed timeout
            and set its interval to 0. Thereby they will be dequeued together when the tick()
            method is called. Note that this needs a special way to check for finished timeouts
            in the thick() method*/
            else if(pNewTimeout->_relTicks == (**it)._relTicks)
            {
                it++;
                pNewTimeout->_relTicks = 0;
                int refVar = 0;
                while(it != _timeouts.end() && refVar == 0)
                {
                    it++;
                    if(it != _timeouts.end())
                    {
                        refVar = (**it)._relTicks;
                    }
                }
                it = _timeouts.insert(it, pNewTimeout);
                break;
            }
        }
    }
#ifdef TC_QTCREATOR
    _theMutex.unlock();
#endif // TC_QTCREATOR

#ifdef BOARD_ARMEBS4
    exitCritical();
#endif // BOARD_ARMEBS4
}

void XFTimeoutManager::removeTimeouts(int timeoutId, IXFReactive *pReactive)
{
#ifdef TC_QTCREATOR
	_theMutex.lock();
#endif // TC_QTCREATOR

#ifdef BOARD_ARMEBS4
    enterCritical();
#endif // BOARD_ARMEBS4

    TimeoutList::iterator it = _timeouts.begin();
    int ticksToSubtract;
    while(it != _timeouts.end())
    {
        if((**it).getId() == timeoutId && (**it).getBehavior() == pReactive)
        {
            ticksToSubtract = (**it)._relTicks >= 0? (**it)._relTicks : 0;
            XFTimeout* temp = *it;      //create a pointer to the "to be deleted" element as long as we can access it
            it = _timeouts.erase(it);   //erase element from the list
            delete temp;                //free the memory
            if(it != _timeouts.end())
            {
                (**it)._relTicks -= ticksToSubtract;
            }
        }
        it++;
    }
#ifdef TC_QTCREATOR
    _theMutex.unlock();
#endif // TC_QTCREATOR

#ifdef BOARD_ARMEBS4
    exitCritical();
#endif // BOARD_ARMEBS4
}

void XFTimeoutManager::returnTimeout(XFTimeout *pTimeout)
{
    pTimeout->getBehavior()->pushEvent(pTimeout);
}

XFTimeoutManager::XFTimeoutManager()
#ifdef TC_QTCREATOR
: _theMutex(QMutex::Recursive)
#endif // TC_QTCREATOR
{}
XFTimeoutManager::~XFTimeoutManager(){}
XFTimeoutManager::XFTimeoutManager(const XFTimeoutManager &p1){}
XFTimeoutManager &XFTimeoutManager::operator=(const XFTimeoutManager &p1){}

#if defined(BOARD_ARMEBS4) and defined(EXT_TIM)
		void XFTimeoutManager::startHardwareTimer(int tickTime)
		{
					   const uint32_t tickRateInHz = 1000/tickTime;

					   bool error = SysTick_Config(SystemClock.hclk / tickRateInHz);
					   UNUSED(error);

					   ASSERT(!error);
		}

		extern "C" void SysTick_Handler()
		{
					   XFTimeoutManager::getInstance()->tick();          // Call Framework hook tick function
		}
#endif // (BOARD_ARMEBS4) and defined(EXT_TIM)


#ifdef TC_QTCREATOR
void XFTimeoutManager::timerEvent(QTimerEvent *event)
{
    tick();
}
#endif // TC_QTCREATOR
