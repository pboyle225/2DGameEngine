#include "key.h"

Key::Key()
{
	id = 1;
	name = "Key";
	globalID = Entity::globalIDCounter++;
}

Key::~Key()
{

}