#pragma once

#include "SFML.hpp"
#include "IState.hpp"

#include "EventManager.hpp"
#include "ResourceManager.hpp"
#include "StateManager.hpp"

#include <SFML\Graphics.hpp>
#include <string>
#include <unordered_map>
#include <typeindex>

class Application : public sf::NonCopyable
{
public:

	Application();

	~Application();

	// core run function

	void run();

	// application state accessors

	bool isPaused() const { return paused; }

	bool isRunning() const { return running; }

	// application state mutators

	void pause();

	void resume();

	void close();

	// engine systems

	ISystem *const addSystem(ISystem *system);

	template <typename S>
	S *const getSystem();

protected:

	void start();

	void update(sf::Time);

	void quit();

	const sf::RenderWindow& getWindow() const { return window; }

	void render();
		 
	void processEvents(sf::Event);

private:

	// gmae systems
	std::unordered_map< std::type_index, ISystem*> systems;

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
