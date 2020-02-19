#include "Slime.h"

Slime::Slime()
{
	id = 4;
	globalID = Entity::globalIDCounter++;
	name = "Slime";
}