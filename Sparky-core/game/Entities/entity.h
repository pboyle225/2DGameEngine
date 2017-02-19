#pragma once
#include "../Components/component.h"

/*
	Idea for id system:
	ID 0 - Player
	ID 1 - Key
	ID 2 - Chest
	ID 3 - Disappearing Tile
*/

class Entity
{
public:
	Entity();
	~Entity();

	void addComponent(Component * component);
	Component * getComponent(int id);
	void removeComponent(Component * component);

	int getID() { return id; }
	std::string getName() { return name; }
	
	int globalID;
	std::bitset<MAX_COMPONENTS> bitset;
	static int globalIDCounter;
protected:
	std::unordered_map<int, Component *> components;
	std::string name;
	int id;
};

