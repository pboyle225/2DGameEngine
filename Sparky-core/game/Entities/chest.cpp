#include "chest.h"

Chest::Chest()
{
	id = 2;
	globalID = Entity::globalIDCounter++;
	name = "Chest";
}

Chest::~Chest()
{

}