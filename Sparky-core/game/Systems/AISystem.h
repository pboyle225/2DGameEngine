#pragma once

#include "system.h"

class AISystem : public System
{
public:
	AISystem();
	void update(std::vector<Entity*> &entities) override;
};
