#pragma once

#include "sfml.hpp"
#include <SFML/Window.hpp>
#include "Event.hpp"

class SFMLEvent : public Event, public sf::Event
{
	CLASS_INTROSPECTION(SFMLEvent)

public:
	
	SFMLEvent(const sf::Event &eventSrc)
		: sf::Event(eventSrc)
	{ }

	~SFMLEvent() {}
};