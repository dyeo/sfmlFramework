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
	if (parent == this->parent || isChild(parent) || parent == this) return;
	this->parent = parent;
}

Transform *const Transform::getParent() const
{
	return parent;
}

void Transform::addChild(Transform *const child)
{
	if (parent == child || isChild(child) || child == this) return;
	children.push_back(child);
}

void Transform::removeChild(size_t index)
{
	auto it = children.begin() + index;

	if (it < children.end())
	{
		(*it)->setParent(nullptr);
		std::swap(*it, children.back());
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
	auto it = std::find(children.begin(), children.end(), child);
	return it < children.end();
}

//

void Transform::update()
{
	for (auto ch = children.begin(); ch != children.end(); ++ch)
	{
		(*ch)->global_position = global_position + local_position;
		(*ch)->global_scale = global_scale + local_scale;
		(*ch)->global_rotation = global_rotation + local_rotation;
	}
}

//

void Transform::translate(Transform::pos_type pos)
{
	local_position += pos;
}

Transform::pos_type Transform::getPosition() const
{
	return global_position + local_position;
}

void Transform::setPosition(Transform::pos_type pos)
{
	local_position = pos - getPosition();
}

Transform::pos_type Transform::getLocalPosition() const
{
	return local_position;
}

void Transform::setLocalPosition(Transform::pos_type pos)
{
	local_position = pos;
}

//

void Transform::rotate(Transform::rot_type rot)
{
	local_rotation += rot;
}

Transform::rot_type Transform::getRotation() const
{
	return global_rotation + local_rotation;
}

void Transform::setRotation(Transform::rot_type rot)
{
	local_rotation = rot - getRotation();
}

Transform::rot_type Transform::getLocalRotation() const
{
	return local_rotation;
}

void Transform::setLocalRotation(Transform::rot_type rot)
{
	local_rotation = rot;
}

//

void Transform::scale(Transform::scl_type scl)
{
	local_scale.x *= scl.y;
	local_scale.y *= scl.y;
}

Transform::scl_type Transform::getScale() const
{
	return global_scale + local_scale;
}

void Transform::setScale(Transform::scl_type scl)
{
	local_scale = scl - getScale();
}

Transform::scl_type Transform::getLocalScale() const
{
	return local_scale;
}

void Transform::setLocalScale(Transform::scl_type scl)
{
	local_scale = scl;
}