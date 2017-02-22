#include "movement.h"

void Movement::update(std::vector<Entity*> &entities)
{
	int size = entities.size();

	for (int i = 0; i < size; i++)
	{
		Transform * transformComp = static_cast<Transform *>(entities[i]->getComponent(0));
		Velocity * velocityComp = static_cast<Velocity *>(entities[i]->getComponent(4));

		if (transformComp && velocityComp)
		{
			transformComp->location += velocityComp->velocity;
		}
		
		SpriteComponent * spriteComp = static_cast<SpriteComponent *>(entities[i]->getComponent(7));

		if (spriteComp && entities[i]->name != "Player")
		{
			spriteComp->sprite->m_Position = transformComp->location;
		}

		entities[i]->removeComponent(velocityComp);
		i--;
		size = entities.size();
	}
}