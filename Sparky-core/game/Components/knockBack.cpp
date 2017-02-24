#include "knockBack.h"

KnockBack::KnockBack(float amount, math::vec3 direction, math::vec3 entityLoc)
{
	id = 14;
	name = "Knockback";
	bitmask = 0x1 << 14;

	this->amount = amount;
	
	if (direction.x < 0.0f)
	{
		this->direction.x = -1.0f;
	}
	else if (direction.x > 0.0f)
	{
		this->direction.x = 1.0f;
	}
	else
	{
		this->direction.x = 0.0f;
	}

	if (direction.y < 0.0f)
	{
		this->direction.y = -1.0f;
	}
	else if (direction.y > 0.0f)
	{
		this->direction.y = 1.0f;
	}
	else
	{
		this->direction.y = 0.0f;
	}
	this->direction.z = 0;


	knockBackLoc = entityLoc;
	knockBackLoc.x += amount * direction.x;
	knockBackLoc.y += amount * direction.y;

	currFrameDistance = 0.3f;
}