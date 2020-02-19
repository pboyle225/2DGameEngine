#pragma once

#include "..//component.h"
#include "..//..//Enums/AttackEnum.h"

class Attack : public Component
{
public:
	int damage;
	AttackEnum attackID;
protected:
	Attack(int damage, AttackEnum attackID);
	~Attack();
};