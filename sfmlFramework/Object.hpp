#pragma once

#include <unordered_map>

//

#define xstr(s) str(s)
#define str(s) #s

//

typedef const char* NameType;

//

#define CLASS_INTROSPECTION(CLASS_NAME) \
	public: \
	static constexpr ::NameType className = xstr(CLASS_NAME); \
	virtual ::NameType name() const \
	{ \
	return className; \
	} \
	bool compare(const ::NameType &rhs) const \
	{ \
	return name() == rhs; \
	} \
	bool compare(const CLASS_NAME &rhs) const \
	{ \
	return name() == rhs.name(); \
	} \
	private:

//

#define CLASS_MESSAGING(CLASS_NAME) \
	private: \
	using _CLASS_MESSAGE = void (CLASS_NAME::*)(void **, int); \
	std::unordered_map<const char *, _CLASS_MESSAGE> _MSG_MAP; \
	public: \
	void sendMessage(const char *name, void **data, int args) \
	{ \
		auto it = _MSG_MAP.find(name); \
		if (it != _MSG_MAP.end()) { (this->*(it->second))(data, args); } \
	} \
	void sendMessage(const char *name) { sendMessage(name, nullptr, 0); }

#define ADD_MESSAGE(CLASS_NAME, FUNCTION) _MSG_MAP.insert({xstr(FUNCTION), &CLASS_NAME::FUNCTION})

//