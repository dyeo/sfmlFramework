#pragma once

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