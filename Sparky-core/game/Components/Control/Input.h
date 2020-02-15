#pragma once

#include "..\component.h"
#include "..\..\Enums\Direction.h"

using namespace engine;

enum InputType
{
	KEYBOARD,
	AI,
	GAMEPAD
};

class Input : public Component
{
public:
	Input(float speed, InputType type);
	~Input();

	float speed;
	bool isMainAttacking;
	math::vec3 movementDir;
	Direction direction;
	InputType type;
};