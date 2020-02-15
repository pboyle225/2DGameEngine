#include "Collision.h"

Collision::Collision(Entity* ent1, Entity* ent2)
{
	id = ComponentIDEnum::CollisionComp;
	name = "Collision";
	this->ent1 = ent1;
	this->ent2 = ent2;

	bitmask = COLLISION_MASK;
}