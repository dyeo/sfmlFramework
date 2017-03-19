#pragma once

#include <vector>

class Transform
{
public:

	Transform();
	~Transform();

	void setParent(Transform *const parent);

	Transform *const getParent() const;

	void addChild(Transform *const child);

	void removeChild(size_t index);

	void removeChild(Transform *const child);

	Transform *const getChild(size_t index) const;

	bool isChild(Transform *const child) const;

	int getChildren() const { return children.size(); }

private:

	Transform *parent;
	std::vector<Transform*> children;

};