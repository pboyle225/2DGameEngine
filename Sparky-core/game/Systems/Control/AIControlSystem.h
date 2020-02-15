#pragma once

#include "../system.h"

class AIControlSystem : public System
{
public:
	void update(std::vector<Entity*>& entities);
};
