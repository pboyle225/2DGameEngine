#include "ProjectileAttack.h"

ProjectileAttack::ProjectileAttack(int damage, float speed, AttackEnum attackID)
	: Attack(damage, attackID)
{
	this->speed = speed;
}