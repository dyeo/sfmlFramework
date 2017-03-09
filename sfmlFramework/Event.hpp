#pragma once

#include "Object.hpp"

class Event
{
	CLASS_INTROSPECTION(Event)
public:

	virtual ~Event() {}

	virtual bool isValidObserver() const
	{
		return true;
	}

};