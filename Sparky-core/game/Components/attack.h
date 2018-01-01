#pragma once

#include "component.h"
#include "../../utils/timer.h"
#include "../Systems/Attacks/CombatSkill.h"

class Attack : public Component
{
public:
	Attack(float attackDamage, float attackSpeed, bool isMelee, bool isFriendly, int attackID, bool hurtsWhenTouched);
	
	float attackDamage;
	float attackSpeed;
	bool isMelee; //delete this
	bool isAttacking;
	int attackID;
	bool isFriendly;
	float knockBackAmount;
	bool hurtsWhentouched;
	Entity * attackThisEntity;
	std::vector<Entity *> meleeRangeEnts;
	CombatSkill * combatSkill;

	Timer timer;
};
