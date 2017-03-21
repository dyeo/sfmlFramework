#pragma once

#include "SFML.hpp"
#include "IState.hpp"
#include "EventSystem.hpp"
#include "ResourceManager.hpp"

#include <SFML\Graphics.hpp>
#include <string>

class Application : public sf::NonCopyable
{
public:

	Application();

	~Application();

	//

	void run();

	// state management

	void pushState(IState *gameState);

	void popState();

	IState* peekState(int state);

	// engine systems

	EventSystem eventSystem;

	ResourceManager resourceMananger;

protected:

	bool isPaused() const { return paused; }

	bool isRunning() const { return running; }

	//

	void start();

	void update(sf::Time);

	void quit();

	const sf::RenderWindow& getWindow() const { return window; }

	void render();
		 
	void pause();

	void resume();
		 
	void processEvents(sf::Event);

private:

	// stack of game states
	std::vector < IState* > stateStack;

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