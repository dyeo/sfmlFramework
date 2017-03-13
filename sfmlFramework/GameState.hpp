#pragma once

#include "Object.hpp"

#include "SFML.hpp"
#include <SFML/Window.hpp>

class Application;

class GameState
{
	CLASS_INTROSPECTION(GameState)

public:

	GameState(Application *const app) : application(app) {}
	virtual ~GameState() {}

	virtual void onStart() {}
	virtual void onUpdate(sf::Time) {}
	virtual void onQuit() {}

	virtual void onRender() {}

	virtual void onPause() {}
	virtual void onResume() {}

	virtual void onProcessEvents(sf::Event) {}

	Application *const application;

private:
};