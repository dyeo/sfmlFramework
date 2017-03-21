#pragma once

#include "IUpdatable.h"

class IState : public IUpdatable
{
	CLASS_INTROSPECTION(IState)

public:

	IState(Application *const app) : IUpdatable(app) {}
	virtual ~IState() {}

	virtual void onStart() = 0;
	virtual void onUpdate(sf::Time) = 0;
	virtual void onQuit() = 0;

	virtual void onRender() = 0;

	virtual void onPause() = 0;
	virtual void onResume() = 0;

	virtual void onProcessEvents(sf::Event) = 0;

private:
};