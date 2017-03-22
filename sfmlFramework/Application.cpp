#include "Application.hpp"
#include "SFMLEvent.hpp"
#include "MenuState.hpp"

#include <typeinfo>
#include <iostream>
#include <type_traits>

using std::cout; using std::endl;

///
///
///
Application::Application()
	: windowWidth(1280)
	, windowHeight(720)
	, targetFrameRate(60)
	, windowTitle("SFML Framework")
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

	getSystem<EventManager>()->subscribe(SFMLEvent::className, [=](const Event& e)
	{
		SFMLEvent event = *dynamic_cast<const SFMLEvent *>(&e);

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
	});

	getSystem<StateManager>()->push(new MenuState(*this));
}

///
///
///
void Application::update(sf::Time deltaTime)
{
	if (!running) return;

	for (auto i = systems.begin(); i != systems.end(); ++i)
	{
		i->second->onUpdate(deltaTime);
	}
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

	for (auto i = systems.begin(); i != systems.end(); ++i)
	{
		i->second->onRender();
	}

	window.display();
}

///
///
///
void Application::pause()
{
	paused = true;

	for (auto i = systems.begin(); i != systems.end(); ++i)
	{
		i->second->onPause();
	}
}

///
///
///
void Application::resume()
{
	paused = false;

	for (auto i = systems.begin(); i != systems.end(); ++i)
	{
		i->second->onResume();
	}
}

///
///
///
void Application::close()
{
	quit();
}

///
///
///
void Application::processEvents(sf::Event event)
{
	for (auto i = systems.begin(); i != systems.end(); ++i)
	{
		i->second->onProcessEvents(event);
	}

	if (!running) return;
}

///
///
///
ISystem *const Application::addSystem(ISystem *system)
{
	auto type = std::type_index(typeid(*system));
	auto iter = systems.find(type);
	if (iter != systems.end())
	{
		return (*iter).second;
	}
	else
	{
		std::cout << "Adding system " << type.name() << '(' << type.hash_code() << ')' << std::endl;
		auto s = systems.insert(std::make_pair(type, system));
		return system;
	}
}

///
///
///
template <typename S>
S *const Application::getSystem()
{
	static_assert(std::is_base_of<ISystem, S>::value, "S does not implement ISystem");

	auto type = std::type_index(typeid(S));
	auto iter = systems.find(type);

	if (iter != systems.end())
	{
		return (S *const)(*iter).second;
	}
	else
	{
		return nullptr;
	}
}