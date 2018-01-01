#pragma once

#include "component.h"

class Projectile : public Component
{
public:
	Projectile(math::vec3 direction);

	math::vec3 direction;
};