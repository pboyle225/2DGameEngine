#pragma once

#include "../system.h"
#include "../../../graphics/window.h"

using namespace graphics;
class KeyboardInputSystem : public System
{
public:
	KeyboardInputSystem() { }
	~KeyboardInputSystem() { }
	void update(std::vector<Entity*>& entities, Window* window);
private:
	void HandleMovement(Input* input, Window* window);
	void HandleAttack(Input* input, Window* window);
};
