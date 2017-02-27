#include "Application.hpp"

#include "SFMLEvent.hpp"

#include <iostream>

using std::cout; using std::endl;

///
///
///
/*constructor*/ Application::Application()
	: windowWidth(1280)
	, windowHeight(720)
	, windowTitle("SFML Framework")
	, targetFrameRate(60)
{
}

///
///
///
/*destructor*/ Application::~Application()
{
}

///
///
///
void Application::run()
{
	running = true;

	start();

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

		if (paused) continue;

		accumulatedTime += deltaTime.asSeconds();

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
void Application::start()
{
	window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close);
	window.setFramerateLimit(targetFrameRate);
}

///
///
///
void Application::update(sf::Time deltaTime)
{
}

///
///
///
void Application::quit()
{
	window.close();
}

///
///
///
void Application::render()
{
	window.clear();

	window.display();
}

///
///
///
void Application::processEvents(sf::Event event)
{
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