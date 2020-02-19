#pragma once

#include "..//Component.h"
#include "..//..//Enums/AttackEnum.h"

using namespace engine;

class Attack : public Component
{
public:
	int damage;
	float cooldown;
	AttackEnum attackID;
	MyTimer timer;
protected:
	Attack(int damage, AttackEnum attackID, float cooldown);
	~Attack();
};