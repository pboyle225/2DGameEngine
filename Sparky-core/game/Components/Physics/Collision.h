#pragma once

#include "..\\component.h"

class Collision : public Component
{
public:
	Collision(Entity* ent1, Entity* ent2);

	Entity* ent1;
	Entity* ent2;
};