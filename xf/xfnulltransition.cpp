#include "xfnulltransition.h"

XFNullTransition::XFNullTransition(IXFReactive *pBehavior) : XFEvent(XFEvent::NullTransition, 0, pBehavior){}

XFNullTransition::~XFNullTransition(){}

bool XFNullTransition::deleteAfterConsume()
{
    return true;
}
