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
	Entity() { }
	~Entity()
	{
		for (int i = 0; i < components.size(); i++)
		{
			delete components[i];
		}
	}

	void addComponent(Component * component)
	{
		components[component->getID()] = component;
	}

	Component * getComponent(int id)
	{
		auto it = components.find(id);

		if (it == components.end())
		{
			return nullptr;
		}

		return it->second;
	}

	void removeComponent(int id)
	{		
		components.erase(id);
	}

	int getID() { return id; }
	std::string getName() { return name; }
	
protected:
	std::unordered_map<int, Component *> components;
	std::string name;
	int id;
};

