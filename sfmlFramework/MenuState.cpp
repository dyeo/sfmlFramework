#pragma once

#include "MenuState.h"

#include <iostream>

using std::cout;
using std::endl;

MenuState::MenuState(Application &_game)
	: GameState(_game)
{
	cout << __FUNCTION__ << endl;
}

void MenuState::onStart() 
{
	cout << __FUNCTION__ << endl;
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