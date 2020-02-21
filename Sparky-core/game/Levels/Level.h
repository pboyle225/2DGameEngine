#pragma once

#include "..\Components\Attacks\FireballAttack.h"
#include "..\scene.h"
#include "../Layers/tilelayer.h"
#include "../Layers/ObjectLayer.h"
#include "..\\Entities\Player.h"
#include "..\\Components\Control\input.h"
#include "..\\Components\Control\Transform.h"
#include "..\\Components\Action\Render.h"
#include "..\\Components\Action\Animation.h"
#include "..\\Components\Physics\RectangleCollider.h"
#include "..\\Components\Control\CursorC.h"
#include "..\\Entities\RectangleColliderEnt.h"
#include "..\\Entities\Wall.h"
#include "..\\Entities\slime.h"
#include "..\\Entities\Cursor.h"

class Level
{
public:
	Level();
	~Level();

	std::vector<Entity*> entities;
	
	void LoadLevel();
	void RenderScene();
	Layer* GetObjectLayer();
	math::vec3 GetPlayerLocation();

private:
	std::vector<Scene*> scenes;
	int indexOfCurrScene;
	Player* player;
};