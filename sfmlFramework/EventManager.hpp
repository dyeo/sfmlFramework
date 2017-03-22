#pragma once

#include "Event.hpp"
#include "ISystem.hpp"

#include <functional>
#include <map>
#include <vector>

class Application;

class EventManager : public ISystem
{
	CLASS_INTROSPECTION(EventManager)

public:

	typedef std::function< void(const Event&) > EventCallback;

	EventManager(Application &app) : ISystem(app) {}

	~EventManager() {}

	void subscribe(const NameType &name, EventCallback &&callback);

	void notify(const Event &event) const;
	
	void onStart();

	void onUpdate(sf::Time);

	void onQuit();
		 
	void onRender();
		 
	void onPause();

	void onResume();
		 
	void onProcessEvents(sf::Event);

protected:

	std::map< NameType, std::vector<EventCallback> > eventListeners;

private:
};