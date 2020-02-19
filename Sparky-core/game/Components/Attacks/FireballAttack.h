#pragma once

#include "ProjectileAttack.h"

class FireballAttack : public ProjectileAttack
{
public:
	FireballAttack(int damage, float speed, float cooldown);
	~FireballAttack();
};
