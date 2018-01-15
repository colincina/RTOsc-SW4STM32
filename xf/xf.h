#ifndef XF_H
#define XF_H

#ifdef TC_QTCREATOR
  #include <QThread>
#endif // TC_QTCREATOR
#include "xfthread.h"

/** \mainpage PTR Execution Framework Documentation
 *
 * \section sec_xf_intro Introduction
 *
 * This library implements an e<b>X</b>ecution <b>F</b>ramework (XF) to drive finite
 * state machines. Using this framework, it is possible to drive multiple state machines
 * in a concurrent manner (pseudo-parallel) without having an operating system.
 *
 * The XF defines an interface which gives the ability to reimplement parts of the XF to
 * make changes to an other target. It is also possible to let the XF run with an RTOS.
 * This gives the possibility to run state machines in a OS like concurrent manner with
 * threads provided by the underlying RTOS.
 *
 * \section sec_xf_cmd XF Class Diagram
 *
 * Following class diagram shows the basic relations between the most important classes
 * in the PTR XF. It shall give you a basic understanding about the relations between
 * these classes:
 *
 * \image html cmd-xf.png "XF Class Diagram"
 *
 * \section sec_xf_start Starting Point
 *
 * A good point to jump into the definitions of the classes is the #XF class. Other classes
 * of interest are XFTimeoutManager, XFThread and XFReactive.
 *
 * \section sec_xf_external_links Links to related Documentation
 * \if DOC_WITH_TESTBENCH
 * - <a href="../../../../test-bench/doxygen/output/html/index.html">Test Bench Documentation</a>
 * \endif
 * - <a href="../../../../trace/doxygen/output/html/index.html">Trace Documentation</a>
 *
 * \todo Use meta programming to handle different event ids in projects.
 *
 * \if DOC_WITH_RELEASE_HISTORY
 * \section sec_xf_releases XF Releases
 * \subsection xf_v_0_7 XF Version: 2.0 (2014-04-28)
 * - sth: Changed way how XFTimeoutManager handles timeouts which timeout at the same time.
 *        Now new timeouts get behind the timeouts with the same (timeout) time.
 * \subsection xf_v_0_6 XF Version: 1.0 (2014-04-24)
 * - sth: Renamed class XFEvent to XFCustomEvent
 * - sth: Renamed IXFEvent to XFEvent (because it was never a real interface)
 * \subsection xf_v_0_5 XF Version: 0.5 (2013-12-09)
 * - sth: Now properly stopping and terminating MainThreadExec instance
 * - sth: Added new literal to EventStatus to handle composite states
 * \subsection xf_v_0_4 XF Version: 0.4 (2013-12-05)
 * - sth: Added scheduleTimeout and unscheduleTimeout to XFReactive class (helper operations)
 * \subsection xf_v_0_3 XF Version: 0.3 (2013-09-19)
 * - sth: Added handling for static events (IXFEvent::deleteAfterConsume())
 * \subsection xf_v_0_2 XF Version: 0.2 (2011-08-14)
 * - sth: Fixed bug in XFTimeoutManager::addTimeout method
 * \subsection xf_v_0_1 XF Version: 0.1 (2010-11-26)
 * - sth: First release
 * \endif
 */

#ifndef NULL
	#define NULL (0)
#endif

/**
 * Static class grouping the basic methods for the XF together.
 */
class XF
{
public:
	/**
	 * Initializes the e<b>X</b>ecution <b>F</b>ramework (XF). Call
	 * this method prior to initialize the other objects of the system.
	 */
	static void init(int timeInterval = 10);

	/**
	 * Starts the execution of the framework. This
	 * results in processing the events in the main loop.
	 */
	static void start();
	static XFThread * getMainThread();	///< Returns pointer the main thread.

protected:
    static bool _bInitialized;			///< Changes from false to true after calling method init(int). Used to handle multiple calls to init(int).
    static XFThread* _mainThread;		///< Main thread executing the main loop.
};

#ifdef TC_QTCREATOR
	class MainThreadExec : public QThread
	{
	public:
        virtual ~MainThreadExec() { XF::getMainThread()->stop(); wait(1000); }
    protected:
        virtual void run () { XF::getMainThread()->start(); }
	};
#endif // TC_QTCREATOR

#endif // XF_H
