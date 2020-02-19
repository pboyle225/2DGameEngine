#include "FireballAttack.h"

FireballAttack::FireballAttack(int damage, float speed, float cooldown)
	: ProjectileAttack(damage, speed, AttackEnum::FireballID, cooldown)
{

}

FireballAttack::~FireballAttack()
{

}