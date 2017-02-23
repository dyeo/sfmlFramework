#pragma once

#include "Event.hpp"
#include "System.hpp"

#include <functional>
#include <map>
#include <vector>

class EventSystem // : public System
{
public:

	typedef std::function< void(const Event&) > EventCallback;

	EventSystem() {}
	~EventSystem() {}

	void subscribe(const NameType &name, EventCallback &&callback);
	void notify(const Event &event) const;

protected:

	std::map< NameType, std::vector<EventCallback> > eventListeners;

private:
};