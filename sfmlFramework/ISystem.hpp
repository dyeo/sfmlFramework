#pragma once

#include "IUpdatable.h"

class ISystem : public IUpdatable
{
	CLASS_INTROSPECTION(ISystem)

public:

	ISystem(Application *const app) : IUpdatable(app) {}
	virtual ~ISystem() {}

	virtual void onStart() = 0;
	virtual void onUpdate(sf::Time) = 0;
	virtual void onQuit() = 0;
				 
	virtual void onRender() = 0;
				 
	virtual void onPause() = 0;
	virtual void onResume() = 0;
				 
	virtual void onProcessEvents(sf::Event) = 0;

private:
};