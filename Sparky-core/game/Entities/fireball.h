#pragma once

#include "entity.h"

class Fireball : public Entity
{
public:
	Fireball()
	{
		id = 5;
		name = "Fireball";
		globalID = Entity::globalIDCounter++;
	}
};