#include "healthComponent.h"

HealthComponent::HealthComponent(float health)
{
	id = 13;
	name = "Health Component";
	bitmask = 0x1 << 13;

	this->health = health;
	healthRegen = 0.0f;
}