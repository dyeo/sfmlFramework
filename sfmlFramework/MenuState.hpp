#pragma once

#include "IState.hpp"

class MenuState : public IState
{
	CLASS_INTROSPECTION(MenuState)

public:

	MenuState(Application &app);

	virtual void onStart() override;

	virtual void onUpdate(sf::Time) override;

	virtual void onQuit() override;

	virtual void onRender() override;

	virtual void onPause() override;

	virtual void onResume() override;

	virtual void onProcessEvents(sf::Event) override;

};