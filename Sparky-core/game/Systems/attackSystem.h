#pragma once
#include "system.h"

class AttackSystem : public System
{
public:
	AttackSystem();
	void update(std::vector<Entity*> &entities) override;
};
