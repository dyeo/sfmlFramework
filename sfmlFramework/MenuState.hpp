#pragma once

#include "GameState.hpp"

class MenuState : public GameState
{
	CLASS_INTROSPECTION(MenuState)

public:

	MenuState(Application *const app);

	void onStart();
	void onUpdate(sf::Time);
	void onQuit();
		 
	void onRender();
		 
	void onPause();
	void onResume();
		 
	void onProcessEvents(sf::Event);

};