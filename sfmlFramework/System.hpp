#pragma once

#include "IUpdatable.h"

class System : public IUpdatable
{
	CLASS_INTROSPECTION(System)

public:

	System(Application *const app) : IUpdatable(app) {}
	virtual ~System() {}

	virtual void onStart() override {}
	virtual void onUpdate(sf::Time) override {}
	virtual void onQuit() override {}
				 
	virtual void onRender() override {}
				 
	virtual void onPause() override {}
	virtual void onResume() override {}
				 
	virtual void onProcessEvents(sf::Event) override {}

private:
};