#pragma once
#include <vector>
#include <unordered_map>
#include <bitset>
//#include "../gameObjectManager.h"
#include "../../math/_math.h"

#define MAX_COMPONENTS 20

class Entity;
/*
ID List for Components:
	0 - Transform
	1 - Animation
	2 - Input
	3 - Collision
	4 - Velocity
	5 - Collectible
	6 - Rectangle Appearance
	7 - Sprite Component
	8 - Timer Component
	99 - To Delete
	10 - attack
*/

using namespace engine;

class Component
{
public:
	Component() { }

	Component(Entity * entity) 
	{ 
		this->entity = entity;
	}

	~Component() { }

	int getID()
	{
		return id;
	}

	Entity * getEntity()
	{
		return entity;
	}

	std::bitset<MAX_COMPONENTS> bitmask;
protected:
	std::string name;
	int id;
	Entity * entity;
};