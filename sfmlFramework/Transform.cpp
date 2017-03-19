#include "Transform.hpp"

Transform::Transform()
	: parent(nullptr)
{
}

Transform::~Transform()
{
	while (children.size() > 0)
	{
		delete children.back();
		children.pop_back();
	}
	children.clear();
}

void Transform::setParent(Transform *const parent)
{
	this->parent = parent;
}

Transform *const Transform::getParent() const
{
	return parent;
}

void Transform::addChild(Transform *const child)
{
	children.push_back(child);
}

void Transform::removeChild(size_t index)
{
	auto it = children.begin() + index;

	if (it < children.end())
	{
		std::swap(*it, children.back());
		delete (children.back());
		children.pop_back();
	}
}

void Transform::removeChild(Transform *const child)
{
	ptrdiff_t pos = std::find(children.begin(), children.end(), child) - children.begin();

	removeChild((size_t)pos);
}

Transform *const Transform::getChild(size_t index) const
{
	if (index < children.size())
	{
		return children[index];
	}
}

bool Transform::isChild(Transform *const child) const
{
	return std::find(children.begin(), children.end(), child) < children.end();
}
