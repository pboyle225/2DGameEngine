#include "rendering.h"


void Rendering::update(std::vector<Entity*> &entities, Scene * currScene)
{
	for (int i = 0; i < SystemManager::addRenderedSprites.size(); i++)
	{
		currScene->objectLayer->add(SystemManager::addRenderedSprites[i]);
		//std::cout << "Texture: " << SystemManager::addRenderedSprites[i]->m_Texture << std::endl;
	}
	//Remove sprites not to be rendered
	for (int i = 0; i < SystemManager::notRenderedSprites.size(); i++)
	{
		currScene->objectLayer->remove(SystemManager::notRenderedSprites[i]);
		delete SystemManager::notRenderedSprites[i];
	}

	for (int i = 0; i < SystemManager::addLabels.size(); i++)
	{
		currScene->objectLayer->add(SystemManager::addLabels[i]);
	}

	for (int i = 0; i < SystemManager::notRenderedLabels.size(); i++)
	{
		currScene->objectLayer->remove(SystemManager::notRenderedLabels[i]);
		delete SystemManager::notRenderedLabels[i];
	}

	SystemManager::notRenderedSprites.clear();
	SystemManager::addRenderedSprites.clear();
	SystemManager::addLabels.clear();
	SystemManager::notRenderedLabels.clear();
}

