#pragma once

#include "Systems/system.h"

#define NUM_SYSTEMS 6

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	static void onComponentAdded(Entity* ent);
	static void onComponentRemoved(Entity* ent);
	static void refreshSystemContainers(Entity* ent);
	static void clearEntFromSystems(Entity* ent);

	static std::unordered_map<int, Entity*> inputMap;
	static std::vector<Entity*> inputEnts;

	static std::unordered_map<int, Entity*> timerSystemMap;
	static std::vector<Entity*> timerEnts;

	static std::unordered_map<int, Entity*> renderingMap;
	static std::vector<Entity*> renderEnts;

	static std::unordered_map<int, Entity*> objectDestroyerMap;
	static std::vector<Entity*> objectDestroyEnts;

	static std::unordered_map<int, Entity*> movementMap;
	static std::vector<Entity*> movementEnts;

	static std::unordered_map<int, Entity*> physicsMap;
	static std::vector<Entity*> physicsEnts;

	static std::unordered_map<int, Entity*> attackSystemMap;
	static std::vector<Entity*> attackEnts;

	static std::unordered_map<int, Entity*> aiSystemMap;
	static std::vector<Entity*> aiEnts;

	static std::unordered_map<int, Entity*> animationSystemMap;
	static std::vector<Entity*> animationEnts;

	static std::unordered_map<int, Entity*> cursorSystemMap;
	static std::vector<Entity*> cursorEnts;

	static std::vector<Collision*> collisions;

private:
	static void clearEntFromSystem(std::unordered_map<int, Entity*>& map, std::vector<Entity*>& entBucket, Entity* ent);
	static void addEntToSystem(std::unordered_map<int, Entity*>& map, std::vector<Entity*>& entBucket, const std::bitset<MAX_COMPONENTS>& mask, Entity* ent);
};