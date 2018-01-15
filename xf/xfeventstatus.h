#ifndef XFEVENTSTATUS_H
#define XFEVENTSTATUS_H


/**
 * The EventStatus is used after consumption of an event. It gives an
 * information on how the event was consument and how the framework should
 * react.
 */
class EventStatus
{
public:
	/**
	 * Status values about the event processed.
	 *
	 * \see XFReactive::process
	 */
	typedef enum
	{
		Unknown			= 0,
		Consumed		= 0x0001,		///< Event consumed
		NotConsumed		= 0x0002,		///< Event not consumed
		RegionFinished  = 0x0004,		///< Composite state machine finished
		Terminate		= 0x0008		///< Terminate state machine
	} eEventStatus;

	/**
	 * Constructor
	 *
	 * \param eventStatus Initial value of the event status.
	 */
	EventStatus(eEventStatus eventStatus = Unknown) : _status(eventStatus) {}

	/**
	 * Checks if both variables contain the same event status.
	 */
	bool operator == (const EventStatus::eEventStatus & eventStatus) const
	{
		return (this->_status == eventStatus);
	}

	void operator |= (const EventStatus & eventStatus)
	{
		unsigned int s1 = _status, s2 = eventStatus._status;
		s1 |= s2;
		_status = (eEventStatus)s1;
	}

	bool is(const eEventStatus eventStatus) const
	{
		unsigned int mask = (unsigned int)eventStatus;
		return ((((unsigned int)_status) & mask) == mask);
	}

public:
	eEventStatus _status;		///< Attribute containing the status of the event.
};

typedef EventStatus::eEventStatus eEventStatus;

#endif // XFEVENTSTATUS_H
