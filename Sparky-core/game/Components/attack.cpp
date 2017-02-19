#include "attack.h"

Attack::Attack(float attackDamage, float attackSpeed, bool isMelee)
{
	id = 10;
	name = "Attack";
	bitmask = 0x1 << 10;
	this->attackSpeed = attackSpeed;
	this->attackDamage = attackDamage;
	this->isMelee = isMelee;
	isAttacking = false;
	
	timer.reset();
}