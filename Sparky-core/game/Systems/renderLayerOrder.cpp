#include "renderLayerOrder.h"

bool RenderLayerOrder::update(std::vector<Entity*> &entities, math::vec3 playerLoc)
{
	Transform * closestTransform = findClosestEntity(entities, playerLoc);

	//math::vec3 offsetPlayerLoc(playerLoc.x )
	math::vec3 tile =  Level::screenToTileCoords(playerLoc);
	float sizeOfTile = (float)TileLayer::sizeOfTile;
	float topHalf = (closestTransform->location.y) + (sizeOfTile * 0.2);

	bool playerInTile = false;

	if(tile == closestTransform->location)
	{
		playerInTile = true;
	}
	tile.x -= 1.0f;

	if (tile == closestTransform->location)
	{
		playerInTile = true;
	}
	tile.x += 1.0f;
	tile.y -= 1.0f;
	if (tile == closestTransform->location)
	{
		playerInTile = true;
	}

	if (playerInTile && playerLoc.y > topHalf)
	{
		return true;
	}
	else
	{
		return false;
	}

}

Transform * RenderLayerOrder::findClosestEntity(std::vector<Entity *> entities, math::vec3 playerLoc)
{
	float distance = 1000000.0f; //something very large
	Entity * closestEntity = NULL;
	Transform * closestTransformComp = NULL;

	for (int i = 0; i < entities.size(); i++)
	{

		if (entities[i]->getID() == 0 || !entities[i]->getComponent(5))
		{
			//Entity is player or not collectible
			continue;
		}

		Transform * locComp = static_cast<Transform * >(entities[i]->getComponent(0));

		if (!locComp)
		{
			//Entity has no Transform
			continue;
		}

		math::vec3 objectLoc(locComp->location);
		float  totalDistance = getDistance(objectLoc, playerLoc);

		if (totalDistance < distance)
		{
			closestEntity = entities[i];
			closestTransformComp = locComp;
			distance = totalDistance;
		}
	}

	return closestTransformComp;
}

float RenderLayerOrder::getDistance(math::vec3 loc1, math::vec3 loc2)
{
	float diffx = loc1.x - loc2.x;
	float diffy = loc1.y - loc2.y;
	float diffZ = loc1.z - loc2.z;

	return sqrt((diffx * diffx) + (diffy * diffy) + (diffZ * diffZ));
}