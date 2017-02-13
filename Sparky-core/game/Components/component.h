#pragma once
#include <vector>
#include <unordered_map>
#include "../../math/_math.h"


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
protected:
	std::string name;
	int id;
	Entity * entity;
};