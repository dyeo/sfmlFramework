#pragma once

#include "Event.hpp"

class GenericEvent : public Event
{
	static constexpr DescriptorType eventType = "GenericEvent";

public:

	GenericEvent() {}
	~GenericEvent() {}

	DescriptorType type() const
	{
		return eventType;
	}

};