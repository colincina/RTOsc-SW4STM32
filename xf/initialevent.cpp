#include "initialevent.h"

InitialEvent::InitialEvent():
    XFEvent(Initial, 0, NULL)
{}

InitialEvent::~InitialEvent(){}

bool InitialEvent::deleteAfterConsume()
{
    return true;
}
