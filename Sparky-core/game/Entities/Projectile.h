#pragma once

#include "Entity.h"
#include "..\Enums\EntityEnum.h"

class Projectile : public Entity
{
protected:

	Projectile()
	{
		id = EntityEnum::Projectile;
		name = "Projectile";
		globalID = Entity::globalIDCounter++;
	}
};