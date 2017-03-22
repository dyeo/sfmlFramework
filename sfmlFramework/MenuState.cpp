#pragma once

#include "MenuState.hpp"

#include "Application.hpp"
#include "SFMLEvent.hpp"

#include <iostream>

using std::cout;
using std::endl;


void MenuState_HandleSFMLEVent(const Event &e)
{
	
		
}

MenuState::MenuState(Application &const app)
	: IState(app)
{
	cout << __FUNCTION__ << endl;
}

void MenuState::onStart() 
{
	cout << __FUNCTION__ << endl;

	application.getSystem<EventManager>()->subscribe(SFMLEvent::className, [=](const Event &e)
	{
		const SFMLEvent *sfe = dynamic_cast<const SFMLEvent*>(&e);

		if (sfe->type == sfe->KeyPressed && sfe->key.code == sf::Keyboard::B)
		{
			application.getSystem<StateManager>()->pop();
		}
	});
}

void MenuState::onUpdate(sf::Time) 
{
	cout << __FUNCTION__ << endl;
}

void MenuState::onQuit() 
{
	cout << __FUNCTION__ << endl;
}

void MenuState::onRender() 
{
	cout << __FUNCTION__ << endl;
}

void MenuState::onPause() 
{
	cout << __FUNCTION__ << endl;
}

void MenuState::onResume() 
{
	cout << __FUNCTION__ << endl;
}

void MenuState::onProcessEvents(sf::Event) 
{
	cout << __FUNCTION__ << endl;
}