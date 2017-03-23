#pragma once

#include <functional>

template <typename Ret, typename... Args>
class Gate
{
public:

	Gate<Ret, Args...>(Ret(*f)(Args...)) : func(f) {}

	inline Ret operator()(Args ...args)
	{
		if (isOpen)
		{
			return func(args...);
		}
		return static_cast<Ret>(0);
	}

	inline bool state() const { return isOpen; }

	inline void setState(bool s) { isOpen = s; }

	inline void open() { isOpen = true; }
	inline void close() { isOpen = false; }
	inline void toggle() { isOpen = !isOpen; }

private:

	bool isOpen = true;
	std::function<Ret(Args...)> func;

};