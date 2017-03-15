#pragma once

#include "Messaging.hpp"
#include <iostream>

class MessageableObject
{
	CLASS_MESSAGING(MessageableObject)

public:

	MessageableObject()
	{
		ADD_MESSAGE(MessageableObject, foo)
		ADD_MESSAGE(MessageableObject, bar)
	}

	void foo()
	{
		std::cout << __FUNCTION__ << std::endl;
	}

	int bar(int &i, int j)
	{
		std::cout << __FUNCTION__ << ' ' << i + j << std::endl;
		return i + j;
	}

};