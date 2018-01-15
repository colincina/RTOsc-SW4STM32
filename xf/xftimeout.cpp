#include "xftimeout.h"

XFTimeout::XFTimeout(int id, int interval, IXFReactive *pBehavior) :
    XFEvent(XFEvent::Timeout, id, pBehavior),
    _interval(interval),
    _relTicks(interval)
{}


bool XFTimeout::operator ==(const XFTimeout &timeout) const
{
    if(this->_id == timeout._id && this->_pBehavior == timeout._pBehavior && this->_interval == timeout._interval)
    {
        return true;
    }

    return false;
}

bool XFTimeout::deleteAfterConsume()
{
    return true;
}

XFTimeout::~XFTimeout(){}

