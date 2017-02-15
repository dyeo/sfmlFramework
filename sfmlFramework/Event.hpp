#pragma once

class Event
{
public:

	virtual ~Event() {}

	typedef const char* DescriptorType;

	virtual DescriptorType type() const = 0;

};