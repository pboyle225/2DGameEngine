#pragma once

#include "..\component.h"

class RectangleCollider : public Component
{
public:
	RectangleCollider(math::vec2 size);
	RectangleCollider(float width, float height);
	RectangleCollider(math::vec2 size, bool isEnabled, bool isSolid);
	float width;
	float height;
	bool isEnabled = true;
	bool isSolid = false;
};
