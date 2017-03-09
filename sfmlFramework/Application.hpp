#pragma once

#include "SFML.hpp"
#include "GameState.h"
#include "EventSystem.hpp"

#include <SFML\Graphics.hpp>
#include <string>

class Application : public sf::NonCopyable
{
public:

	Application();
	~Application();

	void run();
	
protected:

	void start();
	void update(sf::Time);
	void quit();

	const sf::RenderWindow& getWindow() const { return window; }
	void render();
		 
	void pause();
	void resume();
	bool isPaused() const { return paused; }
		 
	bool isRunning() const { return running; }
		 
	void processEvents(sf::Event);
		 
	void pushState(GameState *gameState);
	void popState();
	GameState* peekState(int state);

private:

	// stack of game states
	std::vector < GameState* > stateStack;

	// event system
	EventSystem eventSystem;

	// the window to draw to
	sf::RenderWindow window;

	// if the game is running or not
	bool running;

	// if the game loop is paused or not
	bool paused;
	
	// width of the window, in screen units (usually pixels)
	unsigned int windowWidth;

	// height of the window, in screen units (usually pixels)
	unsigned int windowHeight;

	// title of the window
	std::string windowTitle;

	// ideal frame rate for the game to run at, in frames per second
	unsigned int targetFrameRate;

};