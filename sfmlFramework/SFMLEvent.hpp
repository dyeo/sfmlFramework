#pragma once


#include "sfml.hpp"
#include <SFML/Window.hpp>
#include "Event.hpp"

class SFMLEvent : public Event, public sf::Event
{
	EVENT_NAME_DECLARATION(SFMLEvent)

public:
	
	SFMLEvent() {}
	~SFMLEvent() {}

	SFMLEvent(const sf::Event &eventSrc)
	{
		type = eventSrc.type;
		joystickMove = eventSrc.joystickMove;
	}
};