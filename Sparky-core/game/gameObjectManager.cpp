#include "gameObjectManager.h"

std::vector<Entity*> GameObjectManager::userInputEnts;
std::unordered_map<int, Entity*>GameObjectManager::userInputMap;

std::vector<Entity*> GameObjectManager::timerSystemEnts;
std::unordered_map<int, Entity*>GameObjectManager::timerSystemMap;

std::vector<Entity*> GameObjectManager::renderingEnts;
std::unordered_map<int, Entity*>GameObjectManager::renderingMap;

std::vector<Entity*> GameObjectManager::objectDestroyerEnts;
std::unordered_map<int, Entity*>GameObjectManager::objectDestroyerMap;

std::vector<Entity*> GameObjectManager::movementEnts;
 std::unordered_map<int, Entity*>GameObjectManager::movementMap;

std::vector<Entity*> GameObjectManager::checkCollisionEnts;
std::unordered_map<int, Entity*>GameObjectManager::checkCollisionMap;

std::vector<Entity*> GameObjectManager::attackSystemEnts;
std::unordered_map<int, Entity*> GameObjectManager::attackSystemMap;

std::vector<Entity*> GameObjectManager::aiSystemEnts;
std::unordered_map<int, Entity*> GameObjectManager::aiSystemMap;

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{

}

void GameObjectManager::onComponentAdded(Entity * ent)
{
	refreshSystemContainers(ent);
}

void GameObjectManager::onComponentRemoved(Entity * ent)
{
	clearEntFromSystems(ent);
	refreshSystemContainers(ent);
}

void GameObjectManager::refreshSystemContainers(Entity * ent)
{	

	if (userInputMap[ent->globalID] == NULL && (ent->bitset & userInputMask) == userInputMask)
	{
		userInputEnts.push_back(ent);
		userInputMap[ent->globalID] = ent;
	}

	if (timerSystemMap[ent->globalID] == NULL && ((ent->bitset & timerSystemMask) == timerSystemMask))
	{
		timerSystemEnts.push_back(ent);
		timerSystemMap[ent->globalID] = ent;
	}

	if (renderingMap[ent->globalID] == NULL && ((ent->bitset & renderingMask) == renderingMask))
	{
		renderingEnts.push_back(ent);
		renderingMap[ent->globalID] = ent;
	}

	if (objectDestroyerMap[ent->globalID] == NULL && ((ent->bitset & objectDestroyerMask) == objectDestroyerMask))
	{
		objectDestroyerEnts.push_back(ent);
		objectDestroyerMap[ent->globalID] = ent;
	}

	if (movementMap[ent->globalID] == NULL && ((ent->bitset & movementMask) == movementMask))
	{
		movementEnts.push_back(ent);
		movementMap[ent->globalID] = ent;
	}

	if (checkCollisionMap[ent->globalID] == NULL && ((ent->bitset & checkCollisionMask) == checkCollisionMask))
	{
		checkCollisionEnts.push_back(ent);
		checkCollisionMap[ent->globalID] = ent;
	}

	if (attackSystemMap[ent->globalID] == NULL && ((ent->bitset & attackSystemMask) == attackSystemMask))
	{
		attackSystemEnts.push_back(ent);
		attackSystemMap[ent->globalID] = ent;
	}

	if (aiSystemMap[ent->globalID] == NULL && ((ent->bitset & aiSystemMask) == aiSystemMask))
	{
		aiSystemEnts.push_back(ent);
		aiSystemMap[ent->globalID] = ent;
	}
}

void GameObjectManager::clearEntFromSystems(Entity * ent)
{
	if (userInputMap[ent->globalID] != NULL)
	{
		for (int i = 0; i < userInputEnts.size(); i++)
		{
			if (ent == userInputEnts[i])
			{
				userInputEnts.erase(userInputEnts.begin() + i);
				userInputMap.erase(ent->globalID);
				break;
			}
		}
	}

	if (timerSystemMap[ent->globalID] != NULL)
	{
		for (int i = 0; i < timerSystemEnts.size(); i++)
		{
			if (ent == timerSystemEnts[i])
			{
				timerSystemEnts.erase(timerSystemEnts.begin() + i);
				timerSystemMap.erase(ent->globalID);
				break;
			}
		}
	}

	if (renderingMap[ent->globalID] != NULL)
	{
		for (int i = 0; i < renderingEnts.size(); i++)
		{
			if (ent == renderingEnts[i])
			{
				renderingEnts.erase(renderingEnts.begin() + i);
				renderingMap.erase(ent->globalID);
				break;
			}
		}
	}

	if (objectDestroyerMap[ent->globalID] != NULL)
	{
		for (int i = 0; i < objectDestroyerEnts.size(); i++)
		{
			if (ent == objectDestroyerEnts[i])
			{
				objectDestroyerEnts.erase(objectDestroyerEnts.begin() + i);
				objectDestroyerMap.erase(ent->globalID);
				break;
			}
		}
	}

	if (movementMap[ent->globalID] != NULL)
	{
		for (int i = 0; i < movementEnts.size(); i++)
		{
			if (ent == movementEnts[i])
			{
				movementEnts.erase(movementEnts.begin() + i);
				movementMap.erase(ent->globalID);
				break;
			}
		}
	}

	if (checkCollisionMap[ent->globalID] != NULL)
	{
		for (int i = 0; i < checkCollisionEnts.size(); i++)
		{
			if (ent == checkCollisionEnts[i])
			{
				checkCollisionEnts.erase(checkCollisionEnts.begin() + i);
				checkCollisionMap.erase(ent->globalID);
				break;
			}
		}
	}

	if (attackSystemMap[ent->globalID] != NULL)
	{
		for (int i = 0; i < attackSystemEnts.size(); i++)
		{
			if (ent == attackSystemEnts[i])
			{
				attackSystemEnts.erase(attackSystemEnts.begin() + i);
				attackSystemMap.erase(ent->globalID);
				break;
			}
		}
	}

	if (aiSystemMap[ent->globalID] != NULL)
	{
		for (int i = 0; i < aiSystemEnts.size(); i++)
		{
			if (ent == aiSystemEnts[i])
			{
				aiSystemEnts.erase(aiSystemEnts.begin() + i);
				aiSystemMap.erase(ent->globalID);
				break;
			}
		}
	}
}