#include "ProjectileAttack.h"

ProjectileAttack::ProjectileAttack(int damage, float speed, AttackEnum attackID, float cooldown)
	: Attack(damage, attackID, cooldown)
{
	this->speed = speed;
}