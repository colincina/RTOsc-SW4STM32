#include "xf/xf.h"
#include "xf/xftimeoutmanager.h"
#define MUTE_XF_WRAPPER_IN_CPP_WARNING
#include "xf.h"

void xfInit(int timeInterval)
{
	XF::init(timeInterval);
}

void xfStart()
{
	XF::start();
}

void xfTimeoutManagerTick()
{
	XFTimeoutManager::getInstance()->tick();
}
