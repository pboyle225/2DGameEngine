#pragma once
#include "Entity.h"

class AttackTextEntity : public Entity
{
public:
	AttackTextEntity()
	{
		id = 6;
		globalID = Entity::globalIDCounter++;
		name = "Attack Text Entity";
	}
};
