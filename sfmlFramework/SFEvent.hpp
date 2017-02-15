#pragma once

#include "sfml.hpp"
#include <SFML/Window.hpp>
#include "Event.hpp"

class SFEvent : public Event, public sf::Event
{
	static constexpr NameType eventType = "SFMLEvent";

public:
	
	SFEvent() {}
	~SFEvent() {}

	SFEvent(const sf::Event &eventSrc)
	{
		type = eventSrc.type;
		joystickMove = eventSrc.joystickMove;
	}

	NameType name() const
	{
		return eventType;
	}
};