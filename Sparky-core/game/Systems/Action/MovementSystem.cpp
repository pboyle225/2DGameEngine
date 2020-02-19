#include "MovementSystem.h"

void MovementSystem::update(std::vector<Entity*>& entities)
{
	for (Entity* ent : entities)
	{
		Input* input = static_cast<Input *>(ent->getComponent(ComponentIDEnum::InputComp));

		if (input)
		{
			if (input->movementDir != math::vec3(0, 0, 0))
			{
				ent->addComponent(new Velocity(input->movementDir));
				input->direction = DetermineDirection(input->movementDir);
				
				if (ent->id != EntityEnum::Projectile)
				{
					//reset movement
					input->movementDir = math::vec3(0,0,0);
				}
			}		
		}
	}
}

Direction MovementSystem::DetermineDirection(math::vec3 vec)
{
	if (vec.x > 0)
	{
		return Direction::RIGHT;
	}
	else if (vec.x < 0)
	{
		return Direction::LEFT;
	}
	else if (vec.y > 0)
	{
		return Direction::UP;
	}
	else if (vec.y < 0)
	{
		return Direction::DOWN;
	}

	return Direction::STOPPED;
}