#pragma once

#include "component.h"

class RectangleAppearance : public Component
{
public:
	RectangleAppearance(float width, float height);
	float width;
	float height;
};
