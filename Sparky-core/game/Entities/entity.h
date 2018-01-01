#pragma once
#include "../Components/component.h"

/*
	Idea for id system:
	ID 0 - Player
	ID 1 - Key
	ID 2 - Chest
	ID 3 - Disappearing Tile
	ID 4 - Slime
	ID 5 - Fireball
	ID 6 - Attack Text Entity
*/

class Entity
{
public:
	Entity();
	~Entity();

	void addComponent(Component * component);
	Component * getComponent(int id);
	void removeComponent(Component * component);
	void removeComponent(int id);

	int getID() { return id; }
	std::string getName() { return name; }
	
	int globalID;
	std::bitset<MAX_COMPONENTS> bitset;
	static int globalIDCounter;
	std::string name;
	int id;
protected:
	std::unordered_map<int, Component *> components;
};

