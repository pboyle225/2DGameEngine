#pragma once

#include "..\\system.h"
#include "../../Levels/level0.h"

class EntitySpawnerSystem : public System
{
public:
	void update(std::vector<Entity*>& entities, Level0* level);
};