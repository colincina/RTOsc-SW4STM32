#include "xf.h"
#include "xftimeoutmanager.h"

//initialisation of the protected attribute so that it has a valuein
//the first check in the init() method
bool XF::_bInitialized = false;
XFThread* XF::_mainThread = NULL;

void XF::init(int timeInterval)
{
    if(_bInitialized == false)
    {
        //inhibit further calls to this method
        _bInitialized = true;

        _mainThread = new XFThread;
        if(_mainThread == NULL)
        {
            //Trace::out("Allocation for XFThread has failed");
        }

        XFTimeoutManager::getInstance()->setTickInterval(timeInterval); 
    }
}

void XF::start()
{
	XFTimeoutManager::getInstance()->start();

//Distinguish the target on which the XF will be deployed
#ifdef TC_QTCREATOR
		MainThreadExec* main = new MainThreadExec();
		main->start();
#endif // TC_QTCREATOR

#ifdef BOARD_ARMEBS4
    _mainThread->start();
#endif //BARD_ARMEBS4
}

XFThread *XF::getMainThread()
{
    return _mainThread;
}
