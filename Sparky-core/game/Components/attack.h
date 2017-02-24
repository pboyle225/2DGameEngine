#pragma once

#include "component.h"
#include "../../utils/timer.h"

class Attack : public Component
{
public:
	Attack(float attackDamage, float attackSpeed, bool isMelee, bool isEnemy);
	
	float attackDamage;
	float attackSpeed;
	bool isMelee; //can be melee or ranged
	bool isAttacking;
	int attackID;
	bool isEnemy;
	Entity * attackThisEntity;
	float knockbackAmount;

	Timer timer;
};
