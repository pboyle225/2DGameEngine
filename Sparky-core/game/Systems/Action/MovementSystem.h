#pragma once

#include "..\\system.h"

class MovementSystem : public System
{
public:
	void update(std::vector<Entity*>& entities) override;
private:
	Direction DetermineDirection(math::vec3 vec);
};