#include "disappearingTile.h"

DisapearingTile::DisapearingTile()
{
	id = 3;
	globalID = Entity::globalIDCounter++;
	name = "Disappearing Tile";
}

DisapearingTile::~DisapearingTile()
{

}