#include "direction.h"

Direction::Direction()
{
	id = 15;
	name = "Direction";
	bitmask = 0x1 << 15;

	this->currDirection = DOWN;
}

void Direction::updateDirection(const math::vec3 & moveVector)
{
	float absX = abs(moveVector.x);
	float absY = abs(moveVector.y);

	if (absX >= absY)
	{
		//facing right or left
		if (moveVector.x < 0)
		{
			currDirection = LEFT;
		}
		else if(moveVector.x > 0)
		{
			currDirection = RIGHT;
		}
	}
	else
	{
		//facing up or down
		if (moveVector.y < 0)
		{
			currDirection = DOWN;
		}
		else if (moveVector.y > 0)
		{
			currDirection = UP;
		}
	}
}