#pragma once

#include "SFML.hpp"
#include <SFML/System/Vector2.hpp>

#include <vector>

class Transform
{
public:

	using								pos_type = sf::Vector2f;

	using								scl_type = sf::Vector2f;

	using								rot_type = float;

	//

										Transform();

	virtual								~Transform();

	//

	void								setParent(Transform *const parent);

	Transform *const					getParent() const;

	void								addChild(Transform *const child);

	void								removeChild(size_t index);

	void								removeChild(Transform *const child);

	Transform *const					getChild(size_t index) const;

	bool								isChild(Transform *const child) const;

	size_t								getChildren() const { return children.size(); }

	//

	virtual void						update();

	//

	void								translate(pos_type dsp);

	pos_type							getPosition() const;

	void								setPosition(pos_type pos);

	pos_type							getLocalPosition() const;

	void								setLocalPosition(pos_type pos);

	//

	void								rotate(rot_type rot);

	rot_type							getRotation() const;

	void								setRotation(rot_type rot);

	rot_type							getLocalRotation() const;

	void								setLocalRotation(rot_type rot);

	//

	void								scale(scl_type scl);

	scl_type							getScale() const;

	void								setScale(scl_type scl);

	scl_type							getLocalScale() const;

	void								setLocalScale(scl_type scl);

private:

	Transform							*parent;

	std::vector<Transform*>				children;

	//

	pos_type							local_position;

	rot_type							local_rotation;

	scl_type							local_scale;

	//

	pos_type							global_position;

	rot_type							global_rotation;

	scl_type							global_scale;

};