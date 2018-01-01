#include "projectile.h"

Projectile::Projectile(math::vec3 direction)
{
	id = 16;
	name = "Projectile";
	bitmask = 0x1 << 16;

	this->direction = direction.normalize();
}