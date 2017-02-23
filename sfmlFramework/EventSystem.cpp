#include "EventSystem.hpp"

#include "GenericEvent.hpp"

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
		observer(event);
}
