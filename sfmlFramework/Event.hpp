#pragma once

class Event
{
public:

	virtual ~Event() {}

	typedef const char* NameType;

	virtual NameType name() const = 0;

};