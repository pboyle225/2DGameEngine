#pragma once

#include "..//system.h"

class AnimationSystem : public System
{
public:
	void update(std::vector<Entity*>& entities) override;
};
