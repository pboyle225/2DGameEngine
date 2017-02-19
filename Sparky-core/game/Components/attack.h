#pragma once

#include "component.h"
#include "../../utils/timer.h"

class Attack : public Component
{
public:
	Attack(float attackDamage, float attackSpeed, bool isMelee);
	
	float attackDamage;
	float attackSpeed;
	bool isMelee; //can be melee or ranged
	bool isAttacking;

	Timer timer;
};
