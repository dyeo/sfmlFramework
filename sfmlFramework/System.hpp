#pragma once

#include "Object.hpp"

#include "SFML.hpp"
#include <SFML/Window.hpp>

class Application;

class System
{
	CLASS_INTROSPECTION(System)

public:

	System(Application &_game) : game(_game) {}
	virtual ~System() {}

	virtual void onStart() {}
	virtual void onUpdate(sf::Time) {}
	virtual void onQuit() {}
				 
	virtual void onRender() {}
				 
	virtual void onPause() {}
	virtual void onResume() {}
				 
	virtual void onProcessEvents(sf::Event) {}

	Application &game;

private:
};