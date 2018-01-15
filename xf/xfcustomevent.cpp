#include "xfcustomevent.h"

XFCustomEvent::XFCustomEvent(int id, IXFReactive *pBehavior):
    XFEvent(Event, id, pBehavior)
{}

XFCustomEvent::~XFCustomEvent(){}
