#pragma once

#include "IUpdatable.h"

class GameState : public IUpdatable
{
	CLASS_INTROSPECTION(GameState)

public:

	GameState(Application *const app) : IUpdatable(app) {}
	virtual ~GameState() {}

	virtual void onStart() {}
	virtual void onUpdate(sf::Time) {}
	virtual void onQuit() {}

	virtual void onRender() {}

	virtual void onPause() {}
	virtual void onResume() {}

	virtual void onProcessEvents(sf::Event) {}

private:
};