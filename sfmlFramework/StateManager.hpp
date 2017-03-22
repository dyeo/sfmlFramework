#pragma once

#include "ISystem.hpp"
#include "IState.hpp"

class StateManager : public ISystem
{
	StateManager(Application *const app);

	~StateManager();

	virtual void onUpdate(sf::Time) override;

	virtual void onQuit() override;

	virtual void onRender() override;
	
	virtual void onPause() override;

	virtual void onResume() override;

	virtual void onProcessEvents(sf::Event) override;

	virtual void onStart();

};