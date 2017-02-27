#pragma once

#include "SFML.hpp"

#include <SFML\Graphics.hpp>
#include <string>

class Application : public sf::NonCopyable
{
public:

	/*constructor*/				Application();
	/*destructor*/				~Application();

	void						run();
	
protected:

	void						start();
	void						update(sf::Time);
	void						quit();

	void						render();

	void						processEvents(sf::Event);

private:

	// the window to draw to
	sf::RenderWindow			window;

	// if the game is running or not
	bool						running;

	// if the game loop is paused or not
	bool						paused;
	
	// width of the window, in screen units (usually pixels)
	unsigned int				windowWidth;

	// height of the window, in screen units (usually pixels)
	unsigned int				windowHeight;

	// title of the window
	std::string					windowTitle;

	// ideal frame rate for the game to run at, in frames per second
	unsigned int				targetFrameRate;

};