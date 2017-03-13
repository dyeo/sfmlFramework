#include "EventSystem.hpp"

#include "SFMLEvent.hpp"

void EventSystem::subscribe(const NameType &name, EventCallback &&callback)
{
	eventListeners[name].push_back(callback);
}

void EventSystem::notify(const Event &event) const
{
	auto type = event.name();

	if (eventListeners.find(type) == eventListeners.end())
		return;

	auto&& observers = eventListeners.at(type);

	for (auto&& observer : observers)
	{
		if(event.isValidObserver()) observer(event);
	}
}

void EventSystem::onStart() 
{
}

void EventSystem::onUpdate(sf::Time) 
{
}

void EventSystem::onQuit() 
{
}
	 
void EventSystem::onRender() 
{
}
	 
void EventSystem::onPause() 
{
}

void EventSystem::onResume() 
{
}
	 
void EventSystem::onProcessEvents(sf::Event event) 
{
	SFMLEvent sfevent(event);
	notify(sfevent);
}