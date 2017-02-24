#pragma once

#include "component.h"

class HealthComponent : public Component
{
public:
	HealthComponent(float health);

	float health;
	float healthRegen;

};