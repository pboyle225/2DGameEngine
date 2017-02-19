#include "entity.h"
#include "../gameObjectManager.h"
int Entity::globalIDCounter = 0;


Entity::Entity() 
{

}

Entity::~Entity()
{
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}

void Entity::addComponent(Component * component)
{
	components[component->getID()] = component;

	bitset |= component->bitmask;

	GameObjectManager::onComponentAdded(this);
}

Component * Entity::getComponent(int id)
{
	auto it = components.find(id);

	if (it == components.end())
	{
		return nullptr;
	}

	return it->second;
}

void Entity::removeComponent(Component * component)
{
	std::bitset<MAX_COMPONENTS> temp = bitset & component->bitmask;
	bitset &= temp.flip(); //!= is equal to XOR
	GameObjectManager::onComponentRemoved(this);
	components.erase(component->getID());
	delete component;
}