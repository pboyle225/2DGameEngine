#pragma once

#include "..\\..\\math\_math.h"
#include "../tilelayer.h"

using namespace engine;

class LocationUtil
{
public:
	static math::vec3 worldToScreenCoords(math::vec3 loc)
	{
		return math::vec3(((int)loc.x), ((int)loc.y), loc.z);
	}

	static math::vec3 screenToWorldCoords(math::vec3 loc)
	{
		return math::vec3((loc.x / (float)TileLayer::sizeOfTile), (loc.y / (float)TileLayer::sizeOfTile), loc.z);
	}

	static math::vec3 screenToTileCoords(math::vec3 loc)
	{
		return math::vec3(((int)loc.x), ((int)loc.y), loc.z);
	}

};