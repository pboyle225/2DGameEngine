#pragma once
#include "system.h"
#include "../gameObjectManager.h"

class AttackSystem : public System
{
public:
	AttackSystem();
	void update(std::vector<Entity*> &entities) override;
};
