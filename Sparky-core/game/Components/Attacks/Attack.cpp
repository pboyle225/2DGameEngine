#include "Attack.h"

Attack::Attack(int damage, AttackEnum attackID, float cooldown)
{
	id = ComponentIDEnum::AttackComp;
	name = "Attack Component";
	bitmask = ATTACK_MASK;
	this->damage = damage;
	this->attackID = attackID;
	this->cooldown = cooldown;
}

Attack::~Attack()
{

}