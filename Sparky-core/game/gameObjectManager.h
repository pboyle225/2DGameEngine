#pragma once

#include "Systems/system.h"

#define NUM_SYSTEMS 6

const std::bitset <MAX_COMPONENTS> userInputMask = 0x5;
const std::bitset <MAX_COMPONENTS> timerSystemMask = 0x100;
const std::bitset <MAX_COMPONENTS> renderingMask = 0x1111;
const std::bitset <MAX_COMPONENTS> objectDestroyerMask = 0x200;
const std::bitset <MAX_COMPONENTS> movementMask = 0x11;
const std::bitset <MAX_COMPONENTS> checkCollisionMask = 0x0;
const std::bitset <MAX_COMPONENTS> attackSystemMask = 0x400;
const std::bitset <MAX_COMPONENTS> aiSystemMask = 0x800;

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	static void onComponentAdded(Entity * ent);

	static void onComponentRemoved(Entity * ent);

	static void refreshSystemContainers(Entity * ent);

	static void clearEntFromSystems(Entity * ent);

	static std::vector<Entity*> userInputEnts;
	static std::unordered_map<int, Entity*> userInputMap;
	
	static std::vector<Entity*> timerSystemEnts;
	static std::unordered_map<int, Entity*> timerSystemMap;
	
	static std::vector<Entity*> renderingEnts;
	static std::unordered_map<int, Entity*> renderingMap;
	
	static std::vector<Entity*> objectDestroyerEnts;
	static std::unordered_map<int, Entity*> objectDestroyerMap;
	
	static std::vector<Entity*> movementEnts;
	static std::unordered_map<int, Entity*> movementMap;
	
	static std::vector<Entity*> checkCollisionEnts;
	static std::unordered_map<int, Entity*> checkCollisionMap;
	
	static std::vector<Entity*> attackSystemEnts;
	static std::unordered_map<int, Entity*> attackSystemMap;

	static std::vector<Entity*> aiSystemEnts;
	static std::unordered_map<int, Entity*> aiSystemMap;
};