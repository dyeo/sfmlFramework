#pragma once

#include "IUpdatable.h"

class System : public IUpdatable
{
	CLASS_INTROSPECTION(System)

public:

	System(Application *const app) : IUpdatable(app) {}
	virtual ~System() {}

	virtual void onStart() {}
	virtual void onUpdate(sf::Time) {}
	virtual void onQuit() {}
				 
	virtual void onRender() {}
				 
	virtual void onPause() {}
	virtual void onResume() {}
				 
	virtual void onProcessEvents(sf::Event) {}

private:
};