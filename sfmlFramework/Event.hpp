#pragma once

class Event
{
public:

	virtual ~Event() {}

	typedef const char* NameType;

	virtual NameType name() const = 0;

};

#define str(s) #s
#define EVENT_NAME_DECLARATION(className) private: static constexpr ::Event::NameType nameStr = str(className); \
public: NameType name() const { return nameStr; } \
private: