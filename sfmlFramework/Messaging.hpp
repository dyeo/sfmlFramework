#pragma once

#include "Macro.hpp"

#include <iostream>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#define CLASS_MESSAGING(CLASS_NAME) \
	protected: \
	using __message_ptr = void(CLASS_NAME::*)(void); \
	template<typename R, typename... Args> \
	using __dynamic_message_ptr = R(CLASS_NAME::*)(Args ...); \
	std::unordered_map<::NameType, std::pair<__message_ptr, std::type_index>> __message_map; \
	template<typename F> \
	void addMessage(::NameType name, F func) \
	{ \
		auto type = std::type_index(typeid(func)); \
		__message_map.insert(std::make_pair(name, std::make_pair((__message_ptr)func, type))); \
	} \
	public: \
	template<typename R = void, typename... Args> \
	R sendMessage(::NameType name, Args... args) \
	{ \
		auto iter = __message_map.find(name); \
		if (iter == __message_map.end()) return static_cast<R>(0); \
		auto type = iter->second; \
		auto func = reinterpret_cast<__dynamic_message_ptr<R, Args...>>(type.first); \
		if (type.second != std::type_index(typeid(func))) return static_cast<R>(0); \
		return (this->*func)(std::forward<Args>(args)...); \
	} \
	private:

#define ADD_MESSAGE(CLASS_NAME, FUNCTION) addMessage(xstr(FUNCTION), &CLASS_NAME::FUNCTION);