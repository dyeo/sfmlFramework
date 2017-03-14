#pragma once

#include "Macro.hpp"

#include <unordered_map>

#define CLASS_MESSAGING(CLASS_NAME) \
	private: \
	using _CLASS_MESSAGE = void (CLASS_NAME::*)(void **, int); \
	std::unordered_map<::NameType *, _CLASS_MESSAGE> _MSG_MAP; \
	public: \
	void sendMessage(::NameType *name, void **data, int args) \
	{ \
		auto it = _MSG_MAP.find(name); \
		if (it != _MSG_MAP.end()) { (this->*(it->second))(data, args); } \
	} \
	void sendMessage(::NameType *name) { sendMessage(name, nullptr, 0); }

#define ADD_MESSAGE(CLASS_NAME, FUNCTION) _MSG_MAP.insert({xstr(FUNCTION), &CLASS_NAME::FUNCTION})