#include "knockBack.h"

KnockBack::KnockBack(float amount, math::vec3 direction, math::vec3 entityLoc)
{
	id = 14;
	name = "Knockback";
	bitmask = 0x1 << 14;

	this->amount = amount;

	direction.normalize();
	this->direction = direction;

	knockBackLoc = entityLoc;
	knockBackLoc.x += amount * direction.x;
	knockBackLoc.y += amount * direction.y;

	currFrameDistance = 0.3f;
}

KnockBack::KnockBack(math::vec3 endLocation, float howFast)
{
	this->knockBackLoc = endLocation;
}