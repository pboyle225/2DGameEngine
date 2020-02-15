#include "Velocity.h"

Velocity::Velocity(math::vec3 velocity)
{
	id = 4;
	name = "Velocity";
	this->velocity = velocity;
	bitmask = 0x1 << 4;

	isBeingKnockedBack = false;
}

Velocity::~Velocity()
{

}