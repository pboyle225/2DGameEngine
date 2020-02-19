#include "Attack.h"

Attack::Attack(int damage, AttackEnum attackID)
{
	id = ComponentIDEnum::AttackComp;
	name = "Attack Component";
	bitmask = ATTACK_MASK;
	this->damage = damage;
	this->attackID = attackID;
}

Attack::~Attack()
{

}