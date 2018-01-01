#pragma once

#include "component.h"

class Collision : public Component
{
public:

	Collision();
	~Collision();

	std::vector<Entity *> entsCollidedWith;
};