#include "gameObjectManager.h"

std::unordered_map<int, Entity*>GameObjectManager::inputMap;
std::vector<Entity*> GameObjectManager::inputEnts;

std::unordered_map<int, Entity*> GameObjectManager::animationSystemMap;
std::vector<Entity*> GameObjectManager::animationEnts;

std::unordered_map<int, Entity*>GameObjectManager::renderingMap;
std::vector<Entity*> GameObjectManager::renderEnts;

std::unordered_map<int, Entity*> GameObjectManager::aiSystemMap;
std::vector<Entity*> GameObjectManager::aiEnts;

std::unordered_map<int, Entity*>GameObjectManager::movementMap;
std::vector<Entity*> GameObjectManager::movementEnts;

std::unordered_map<int, Entity*>GameObjectManager::physicsMap;
std::vector<Entity*> GameObjectManager::physicsEnts;

std::unordered_map<int, Entity*>GameObjectManager::timerSystemMap;
std::vector<Entity*> GameObjectManager::timerEnts;

std::unordered_map<int, Entity*>GameObjectManager::objectDestroyerMap;
std::vector<Entity*> GameObjectManager::objectDestroyEnts;


std::unordered_map<int, Entity*> GameObjectManager::attackSystemMap;
std::vector<Entity*> GameObjectManager::attackEnts;




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
	addEntToSystem(inputMap, inputEnts, INPUT_MASK, ent);
	addEntToSystem(movementMap, movementEnts, MOVEMENT_MASK, ent);
	addEntToSystem(animationSystemMap, animationEnts, ANIMATION_MASK, ent);
	addEntToSystem(renderingMap, renderEnts, RENDER_MASK, ent);
	addEntToSystem(physicsMap, physicsEnts, PHYSICS_MASK, ent);

	//if (objectDestroyerMap[ent->globalID] == NULL && ((ent->bitset & objectDestroyerMask) == objectDestroyerMask))
	//{
	//	objectDestroyerEnts.push_back(ent);
	//	objectDestroyerMap[ent->globalID] = ent;
	//}

	//if (timerSystemMap[ent->globalID] == NULL && ((ent->bitset & timerSystemMask) == timerSystemMask))
	//{
	//	timerSystemEnts.push_back(ent);
	//	timerSystemMap[ent->globalID] = ent;
	//}

	//if (checkCollisionMap[ent->globalID] == NULL && ((ent->bitset & checkCollisionMask) == checkCollisionMask))
	//{
	//	checkCollisionEnts.push_back(ent);
	//	checkCollisionMap[ent->globalID] = ent;
	//}

	//if (attackSystemMap[ent->globalID] == NULL && ((ent->bitset & attackSystemMask) == attackSystemMask))
	//{
	//	attackSystemEnts.push_back(ent);
	//	attackSystemMap[ent->globalID] = ent;
	//}

	//if (aiSystemMap[ent->globalID] == NULL && ((ent->bitset & aiSystemMask) == aiSystemMask))
	//{
	//	aiSystemEnts.push_back(ent);
	//	aiSystemMap[ent->globalID] = ent;
	//}
}

void GameObjectManager::clearEntFromSystems(Entity * ent)
{
	clearEntFromSystem(inputMap, inputEnts, ent);
	clearEntFromSystem(movementMap, movementEnts, ent);
	clearEntFromSystem(animationSystemMap, animationEnts, ent);
	clearEntFromSystem(renderingMap, renderEnts, ent);
	clearEntFromSystem(physicsMap, physicsEnts, ent);
	
	//clearEntFromSystem(timerSystemMap, ent);
	//clearEntFromSystem(objectDestroyerMap, ent);
	//clearEntFromSystem(checkCollisionMap, ent);
	//clearEntFromSystem(attackSystemMap, ent);
	//clearEntFromSystem(aiSystemMap, ent);

	//delete ent;
}

void GameObjectManager::addEntToSystem(std::unordered_map<int, Entity*>& map, std::vector<Entity*>& entBucket, const std::bitset<MAX_COMPONENTS>& mask, Entity* ent)
{
	if ((map.find(ent->globalID) == map.end()) && ((ent->bitset & mask) != 0))
	{
		map[ent->globalID] = ent;
		entBucket.push_back(ent);
	}
}

void GameObjectManager::clearEntFromSystem(std::unordered_map<int, Entity*>& map, std::vector<Entity*>& entBucket, Entity* ent)
{
	if (map.find(ent->globalID) != map.end())
	{
		map.erase(ent->globalID);
		
		for (int i = 0; i < entBucket.size(); i++)
		{
			if (entBucket[i]->globalID == ent->globalID)
			{
				entBucket.erase(entBucket.begin() + i);
				break;
			}
		}
	}
}