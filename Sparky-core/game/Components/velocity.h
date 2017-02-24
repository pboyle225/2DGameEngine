#pragma once

#include "component.h"

class Velocity : public Component
{
public:
	Velocity(math::vec3 velocity);
	~Velocity();
	math::vec3 velocity;

	bool isBeingKnockedBack;

private:

};