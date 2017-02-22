#pragma once

#include "component.h"

class CircleAppearance : public Component
{
	public:
		CircleAppearance(float radius);

		float radius;
};