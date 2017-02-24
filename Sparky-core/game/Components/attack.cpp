#include "attack.h"

Attack::Attack(float attackDamage, float attackSpeed, bool isMelee, bool isEnemy)
{
	id = 10;
	name = "Attack";
	bitmask = 0x1 << 10;
	this->attackSpeed = attackSpeed;
	this->attackDamage = attackDamage;
	this->isMelee = isMelee;
	isAttacking = false;
	attackID = 0; //default
	this->isEnemy = isEnemy;
	this->attackThisEntity = NULL;
	float knockbackAmount = 1.0f;

	timer.reset();
}