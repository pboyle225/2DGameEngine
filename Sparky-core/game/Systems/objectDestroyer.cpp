#include "objectDestroyer.h"

#include "../gameObjectManager.h"

void ObjectDestroyer::update(std::vector<Entity*> &entities)
{

	std::vector<Entity *> toDeleteEnts;
	int size = entities.size();

	for (int i = 0; i < size; i++)
	{
		//if (entities[i]->getComponent(99))
		//{
		//	//SpriteComponent * spriteComp = static_cast<SpriteComponent *>(entities[i]->getComponent(7));

		//	if (spriteComp)
		//	{
		//		SystemManager::notRenderedSprites.push_back(spriteComp->sprite);
		//	}
		//	else
		//	{
		//		LabelComponent * labelComponent = static_cast<LabelComponent *>(entities[i]->getComponent(17));
		//		SystemManager::notRenderedLabels.push_back(labelComponent->label);
		//	}

		//	toDeleteEnts.push_back(entities[i]);
		//	//GameObjectManager::clearEntFromSystems(entities[i]);

		//	for (int j = 0; j < Level::entities.size(); j++)
		//	{
		//		if (entities[i]->globalID == Level::entities[j]->globalID)
		//		{
		//			Level::entities.erase(Level::entities.begin() + j);
		//			break;
		//		}
		//	}

		//}

		if (size != entities.size())
		{
			i--;
			size = entities.size();
		}
	}

	for (int i = 0; i < toDeleteEnts.size(); i++)
	{
		//std::cout << "Deleted Entity: " << toDeleteEnts[i]->name << std::endl;
		delete toDeleteEnts[i];
	}
}