#pragma once

#include "Event.hpp"

class GenericEvent : public Event
{
	static constexpr NameType eventType = "GenericEvent";

public:

	GenericEvent() {}
	~GenericEvent() {}

	NameType name() const
	{
		return eventType;
	}

};