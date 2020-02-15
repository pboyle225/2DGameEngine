#pragma once

#include "..\\system.h"
#include "../../../graphics/layers/layer.h"

class EntitySpawnerSystem : public System
{
public:
	void update(std::vector<Entity*>& entities, Layer* objectLayer);
};