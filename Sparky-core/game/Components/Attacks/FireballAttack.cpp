#include "FireballAttack.h"

FireballAttack::FireballAttack(int damage, float speed)
	: ProjectileAttack(damage, speed, AttackEnum::FireballID)
{

}

FireballAttack::~FireballAttack()
{

}