#pragma once

#include "entity.h"

class Wall : public Entity
{
public:
	Wall()
	{
		id = 5;
		globalID = Entity::globalIDCounter++;
		name = "Wall";
	}
};