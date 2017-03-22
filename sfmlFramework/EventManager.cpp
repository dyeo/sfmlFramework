#include "EventManager.hpp"

#include "SFMLEvent.hpp"

void EventManager::subscribe(const NameType &name, EventCallback &&callback)
{
	eventListeners[name].push_back(callback);
}

void EventManager::notify(const Event &event) const
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

void EventManager::onStart() 
{
}

void EventManager::onUpdate(sf::Time) 
{
}

void EventManager::onQuit() 
{
}
	 
void EventManager::onRender() 
{
}
	 
void EventManager::onPause() 
{
}

void EventManager::onResume() 
{
}
	 
void EventManager::onProcessEvents(sf::Event event) 
{
	SFMLEvent sfevent(event);
	notify(sfevent);
}