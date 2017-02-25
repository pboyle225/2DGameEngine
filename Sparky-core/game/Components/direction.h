#pragma once

#include "component.h"

enum DirectionLoc
{
	//0-up, 1-down, 2-left, 3-right
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Direction : public Component
{
public:
	Direction();
	DirectionLoc currDirection;
	void updateDirection(const math::vec3 & moveVector);

};
