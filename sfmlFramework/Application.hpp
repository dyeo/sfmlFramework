#pragma once

#include "SFML.hpp"
#include "GameState.hpp"
#include "EventSystem.hpp"

#include <SFML\Graphics.hpp>
#include <string>

class Application : public sf::NonCopyable
{
public:

	Application();
	~Application();

	void run();

	void pushState(GameState *gameState);
	void popState();
	GameState* peekState(int state);

	// event system
	EventSystem eventSystem;

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

private:

	// stack of game states
	std::vector < GameState* > stateStack;


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