#pragma once

#include "Attack.h"

class ProjectileAttack : public Attack
{
public:
	float speed;
protected:
	ProjectileAttack(int damage, float speed, AttackEnum id);
};
