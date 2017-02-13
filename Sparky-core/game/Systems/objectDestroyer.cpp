#include "objectDestroyer.h"

void ObjectDestroyer::update(std::vector<Entity *> &entities)
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getComponent(99))
		{
			Entity * toDelete = entities[i];
			entities.erase(entities.begin() + i);
			delete toDelete;

			//SystemManager::addMessage(0, "hello!");
		}
	}
}