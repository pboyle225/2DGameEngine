#pragma once

#include "component.h"

class AIComponent : public Component
{
public:
	AIComponent(bool canMove, float speed);

	bool canMove;
	bool isAggro;
	float speed;

};