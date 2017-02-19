#include "movement.h"

void Movement::update(std::vector<Entity*> &entities)
{
	for (int i = 0; i < entities.size(); i++)
	{
		Transform * transformComp = static_cast<Transform *>(entities[i]->getComponent(0));
		Velocity * velocityComp = static_cast<Velocity *>(entities[i]->getComponent(4));

		if (transformComp && velocityComp)
		{
			transformComp->location += velocityComp->velocity;
			entities[i]->removeComponent(velocityComp);
		}
	}
}