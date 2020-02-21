#pragma once

#include "..\\..\\math\_math.h"
#include "../Layers/tilelayer.h"

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

	static math::vec2 cursorToWorldCoords(math::vec2 clickLoc, math::vec2 screenSize, math::vec3 cameraPos)
	{
		math::mat4 matProj = math::mat4(1.0f) * math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f);
		//math::mat4 matProj = math::mat4(1.0f) * math::mat4::orthographic(-100.0f, 100.0f, -100.0f, 100.0f, -1.0f, 1.0f);
		math::mat4 invMatProj = matProj.Invert();
			
		float winZ = 1.0;

		float x = (2.0f * ((float)(clickLoc.x) / (screenSize.x))) - 1.0f;
		float y = 1.0f - (2.0f * ((float)(clickLoc.y) / (screenSize.y)));
		float z = 2.0 * winZ - 1.0;
		float w = 1.0;

		math::vec4 vIn = math::vec4(x, y, z, w);
		math::vec4 pos = invMatProj * vIn;

		return math::vec2(pos.x + cameraPos.x, pos.y + cameraPos.y);

		//math::vec4 view(clickLoc.x / (screenSize.x / 2.f) - 1,
		//	1 - clickLoc.y / (screenSize.y / 2.f), 0, 1);

		//return math::vec2(view.x + cameraPos.x, view.y + cameraPos.y);
	}

};