#include "Game.hpp"

#include <iostream>

using std::cout; using std::endl;

///
///
///
/*constructor*/ Game::Game()
	: windowWidth(1280)
	, windowHeight(720)
	, windowTitle("SFML Framework")
	, targetFrameRate(60)
{
}

///
///
///
/*destructor*/ Game::~Game()
{
}

///
///
///
void Game::run()
{
	running = true;

	init();

	sf::Clock frameTimer;
	sf::Time deltaTime;
	float accumulatedTime = 0.0f;

	while (window.isOpen() && running == true)
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			processEvents(event);
		}

		deltaTime = frameTimer.restart();
		accumulatedTime += deltaTime.asSeconds();

		if (paused) continue;

		while (accumulatedTime >= deltaTime.asSeconds())
		{
			update(deltaTime);
			accumulatedTime -= deltaTime.asSeconds();
		}

		render();
	}

	quit();

	running = false;
}

///
///
///
void Game::init()
{
	cout << "init" << endl;

	window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close);
	window.setFramerateLimit(targetFrameRate);
}

///
///
///
void Game::update(sf::Time deltaTime)
{
	cout << "update " << deltaTime.asSeconds() << endl;
}

///
///
///
void Game::quit()
{
	cout << "quit" << endl;

	window.close();
}

///
///
///
void Game::render()
{
	cout << "render" << endl;

	window.clear();

	window.display();
}

///
///
///
void Game::processEvents(sf::Event event)
{
	cout << "processEvents" << endl;

	if (event.type == sf::Event::Closed)
	{
		running = false;
	}
	else if (event.type == sf::Event::LostFocus)
	{
		paused = true;
	}
	else if (event.type == sf::Event::GainedFocus)
	{
		paused = false;
	}

}