#pragma once

#include "Projectile.h"

class Fireball : public Projectile
{
public:
	Fireball()
		: Projectile()
	{
		name = "Fireball";
	}
};