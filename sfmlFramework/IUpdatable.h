#pragma once

#include "Object.hpp"

#include "SFML.hpp"
#include <SFML/Window.hpp>

class Application;

class IUpdatable
{
	CLASS_INTROSPECTION(IUpdatable)

public:

	IUpdatable(Application &app) : application(app) {}
	virtual ~IUpdatable() {}

	virtual void onStart() = 0;
	virtual void onUpdate(sf::Time) = 0;
	virtual void onQuit() = 0;

	virtual void onRender() = 0;

	virtual void onPause() = 0;
	virtual void onResume() = 0;

	virtual void onProcessEvents(sf::Event) = 0;

	Application &application;

private:
};