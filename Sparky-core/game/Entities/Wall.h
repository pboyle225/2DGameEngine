#pragma once

#include "Entity.h"

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