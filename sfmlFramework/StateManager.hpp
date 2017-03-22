#pragma once

#include "ISystem.hpp"
#include "IState.hpp"

class StateManager : public ISystem
{
public:

	StateManager(Application &app);

	~StateManager();

	virtual void onStart() override;

	virtual void onUpdate(sf::Time) override;

	virtual void onQuit() override;

	virtual void onRender() override;
	
	virtual void onPause() override;

	virtual void onResume() override;

	virtual void onProcessEvents(sf::Event) override;

	void push(IState *gameState);

	void pop();

	IState* peek(int state);

	bool empty() const;

private:

	// stack of game states
	std::vector < IState* > stateStack;

};