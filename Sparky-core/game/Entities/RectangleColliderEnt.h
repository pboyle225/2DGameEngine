#pragma once

#include "entity.h"

class RectangleColliderEnt : public Entity
{
public:
	RectangleColliderEnt()
	{
		id = 5;
		name = "Rectangle Collider Ent";
		globalID = Entity::globalIDCounter++;
	}
};