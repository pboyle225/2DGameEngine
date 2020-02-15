#include "KeyboardInputSystem.h"


void KeyboardInputSystem::update(std::vector<Entity*> &entities, Window* window)
{
	for (Entity* ent : entities)
	{
		Input* input = static_cast<Input*>(ent->getComponent(ComponentIDEnum::InputComp));
		if (input->type != InputType::KEYBOARD)
		{
			continue;
		}

		HandleMovement(input, window);
		HandleAttack(input, window);
	}
}

void KeyboardInputSystem::HandleMovement(Input* input, Window* window)
{
	float speed = input->speed;
	math::vec3 vel(0, 0, 0);
	input->direction = Direction::STOPPED;

	if (window->isKeyPressed(GLFW_KEY_W))
	{
		vel.y += input->speed;
	}

	if (window->isKeyPressed(GLFW_KEY_S))
	{
		vel.y -= input->speed;
	}

	if (window->isKeyPressed(GLFW_KEY_A))
	{
		vel.x -= input->speed;
	}

	if (window->isKeyPressed(GLFW_KEY_D))
	{
		vel.x += input->speed;
	}

	math::vec3 temp = vel.normalize() * math::vec3(input->speed, input->speed, input->speed);

	if (temp != math::vec3(0,0,0))
	{
		input->movementDir = temp;
	}
}

void KeyboardInputSystem::HandleAttack(Input* input, Window* window)
{
	input->isMainAttacking = window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT);
}