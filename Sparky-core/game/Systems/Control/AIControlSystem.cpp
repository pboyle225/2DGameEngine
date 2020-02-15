#include "AIControlSystem.h"

void AIControlSystem::update(std::vector<Entity*>& entities)
{
	for (Entity* ent : entities)
	{
		Input* input = static_cast<Input*>(ent->getComponent(ComponentIDEnum::InputComp));
		if (input->type != InputType::AI)
		{
			continue;
		}

		input->movementDir += math::vec3(input->speed,0, 0);
		input->direction = Direction::DEFAULT;
		//input->isMainAttacking = true;
	}
}