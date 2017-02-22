#include "circleAppearance.h"

CircleAppearance::CircleAppearance(float radius)
{
	id = 12;
	name = "Circle Appearance";
	bitmask = 0x1 << 12;

	this->radius = radius;
}