#pragma once

#include "IUpdatable.h"

class GameState : public IUpdatable
{
	CLASS_INTROSPECTION(GameState)

public:

	GameState(Application *const app) : IUpdatable(app) {}
	virtual ~GameState() {}

	virtual void onStart() override {}
	virtual void onUpdate(sf::Time) override {}
	virtual void onQuit() override {}

	virtual void onRender() override {}

	virtual void onPause() override {}
	virtual void onResume() override {}

	virtual void onProcessEvents(sf::Event) override {}

private:
};