#pragma once

#include "Event.hpp"

class GenericEvent : public Event
{
	CLASS_INTROSPECTION(GenericEvent)

public:

	GenericEvent() {}
	~GenericEvent() {}
};