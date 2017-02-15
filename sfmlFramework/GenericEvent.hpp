#pragma once

#include "Event.hpp"

class GenericEvent : public Event
{
	EVENT_NAME_DECLARATION(GenericEvent)

public:

	GenericEvent() {}
	~GenericEvent() {}
};