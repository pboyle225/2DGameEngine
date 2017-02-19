#include "rendering.h"


void Rendering::update(std::vector<Entity*> &entities, Scene * currScene)
{
	//Remove sprites not to be rendered
	for (int i = 0; i < SystemManager::notRenderedSprites.size(); i++)
	{
		currScene->getObjectLayer()->remove(SystemManager::notRenderedSprites[i]);
	}
}

