#pragma once

#include "GameState.h"

class MenuState : public GameState
{
	CLASS_INTROSPECTION(MenuState)

public:

	MenuState(Application &_game);

	void onStart();
	void onUpdate(sf::Time);
	void onQuit();
		 
	void onRender();
		 
	void onPause();
	void onResume();
		 
	void onProcessEvents(sf::Event);

};