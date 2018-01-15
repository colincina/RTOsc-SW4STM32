#include "xf.h"
#include "xfreactive.h"
#include "xftimeout.h"
#include "initialevent.h"

XFReactive::XFReactive(XFThread *pThread): 
    _pThread(pThread)
{
    if(pThread == NULL)
    {
        _pThread = XF::getMainThread();
    }
    startBehavior();
}

XFReactive::~XFReactive()
{
}

void XFReactive::startBehavior()
{
    InitialEvent* ev = new InitialEvent();
    ev->setBehavior(this);
    _pCurrentEvent = ev;
    _pThread->pushEvent(ev); //this event has to be deleted upon injection in the FSM through the process event call
}

void XFReactive::pushEvent(XFEvent *pEvent)
{
    pEvent->setBehavior(this);
    _pThread->pushEvent(pEvent);
}


XFThread *XFReactive::getThread()
{
    return _pThread;
}

XFEvent *XFReactive::getCurrentEvent() const
{
    return _pCurrentEvent;
}

XFTimeout *XFReactive::getCurrentTimeout()
{
    if(_pCurrentEvent->getEventType()== XFEvent::Timeout)
    {
        return (XFTimeout*)(_pCurrentEvent);
    }
    else return NULL; /**@fixme*/
}

void XFReactive::setCurrentEvent(XFEvent *pEvent)
{
    _pCurrentEvent = pEvent;
}

EventStatus XFReactive::process(XFEvent *pEvent)
{
    setCurrentEvent(pEvent);
    EventStatus evStat = processEvent();
    return evStat; 
}

EventStatus XFReactive::processEvent(){}


