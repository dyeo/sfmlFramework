#include "StateManager.hpp"

#include "Application.hpp"

StateManager::StateManager(Application & app)
	: ISystem(app)
{
}

StateManager::~StateManager()
{
}

void StateManager::onStart()
{
	if (empty()) return;
	stateStack.back()->onStart();
}


void StateManager::onUpdate(sf::Time dt)
{
	if (empty()) return;
	stateStack.back()->onUpdate(dt);
}

void StateManager::onQuit()
{
	if (empty()) return;
	stateStack.back()->onQuit();
}

void StateManager::onRender()
{
	if (empty()) return;
	stateStack.back()->onRender();
}

void StateManager::onPause()
{
	if (empty()) return;
	stateStack.back()->onPause();
}

void StateManager::onResume()
{
	if (empty()) return;
	stateStack.back()->onResume();
}

void StateManager::onProcessEvents(sf::Event e)
{
	if (empty()) return;
	stateStack.back()->onProcessEvents(e);
}

void StateManager::push(IState *gameState)
{
	stateStack.push_back(gameState);
	stateStack.back()->onStart();
}

void StateManager::pop()
{
	stateStack.back()->onQuit();
	delete stateStack.back();
	stateStack.pop_back();

	if (stateStack.empty()) application.close();
}

IState *const StateManager::peek(int state)
{
	size_t numStates = stateStack.size();
	size_t finalStatePos = (numStates + state) % numStates;
	if (finalStatePos >= 0 && finalStatePos < numStates)
	{
		return *(stateStack.begin() + finalStatePos);
	}
	return nullptr;
}

bool StateManager::empty() const
{
	return stateStack.empty();
}
