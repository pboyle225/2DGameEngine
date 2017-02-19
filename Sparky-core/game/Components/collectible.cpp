#include "collectible.h"

Collectible::Collectible()
{
	id = 5;
	name = "Collectible";
	bitmask = 0x1 << 5;
}