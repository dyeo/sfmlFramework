#include "StateManager.hpp"

#include "Application.hpp"

StateManager::StateManager(Application *const app)
	: ISystem(app)
{
}

StateManager::~StateManager()
{
}

void StateManager::onUpdate(sf::Time dt)
{
	stateStack.back()->onUpdate(dt);
}

void StateManager::onQuit()
{
	stateStack.back()->onQuit();
}

void StateManager::onRender()
{
	stateStack.back()->onRender();
}

void StateManager::onPause()
{
	stateStack.back()->onPause();
}

void StateManager::onResume()
{
	stateStack.back()->onResume();
}

void StateManager::onProcessEvents(sf::Event e)
{
	stateStack.back()->onProcessEvents(e);
}

void StateManager::onStart()
{
	stateStack.back()->onStart();
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

	if (stateStack.empty()) application->close();
}

IState* StateManager::peek(int state)
{
	size_t numStates = stateStack.size();
	int finalStatePos = (numStates + state) % numStates;
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
