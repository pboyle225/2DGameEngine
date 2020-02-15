#include "attack.h"

Attack::Attack(float attackDamage, float attackSpeed, bool isMelee, bool isFriendly, int attackID, bool hurtsWhenTouched)
{
	id = 10;
	name = "Attack";
	bitmask = 0x1 << 10;
	this->attackSpeed = attackSpeed;
	this->attackDamage = attackDamage;
	this->isMelee = isMelee;
	isAttacking = false;
	this->isFriendly = isFriendly;
	this->attackThisEntity = NULL;
	this->attackID = attackID;
	this->hurtsWhentouched = hurtsWhenTouched;

	if (attackID == 0)
	{
		knockBackAmount = 3.0f;
	}
	else if (attackID == 1)
	{
		knockBackAmount = 1.0f;
	}
	else if (attackID == 2)
	{
		knockBackAmount = 2.0f;
	}

	timer.reset();
}