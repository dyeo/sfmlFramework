#include "Application.hpp"
#include "SFMLEvent.hpp"
#include "MenuState.h"

#include <iostream>

using std::cout; using std::endl;

///
///
///
Application::Application()
	: windowWidth(1280)
	, windowHeight(720)
	, targetFrameRate(60)
	, windowTitle("SFML Framework")
	, eventSystem(*this)
	, stateStack(4)
{
}

///
///
///
Application::~Application()
{
}

///
///
///
void Application::run()
{
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
}

///
///
///
void Application::start()
{
	window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle, sf::Style::Close);
	window.setFramerateLimit(targetFrameRate);
	running = true;

	pushState(new MenuState(*this));
}

///
///
///
void Application::update(sf::Time deltaTime)
{
	if (!running) return;
	stateStack.back()->onUpdate(deltaTime);
}

///
///
///
void Application::quit()
{
	running = false;
	window.close();
}

///
///
///
void Application::render()
{
	if (!running) return;

	window.clear();
	
	stateStack.back()->onRender();

	window.display();
}

///
///
///
void Application::pause()
{
	paused = true;
	stateStack.back()->onPause();
}

///
///
///
void Application::resume()
{
	paused = false;
	stateStack.back()->onResume();
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
		pause();
	}
	else if (event.type == sf::Event::GainedFocus)
	{
		resume();
	}

	eventSystem.onProcessEvents(event);
	stateStack.back()->onProcessEvents(event);
}

///
///
///
void Application::pushState(GameState *gameState)
{
	stateStack.push_back(gameState);
	stateStack.back()->onStart();
}

///
///
///
void Application::popState()
{
	stateStack.back()->onQuit();
	delete stateStack.back();
	stateStack.pop_back();
	running = stateStack.empty();
}

///
///
///
GameState* Application::peekState(int state)
{
	size_t ssize = stateStack.size();
	int finalStatePos = (ssize + state) % ssize;
	if (finalStatePos >= 0 && finalStatePos < ssize)
	{
		return *(stateStack.end() - 2);
	}
	return nullptr;
}