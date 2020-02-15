#pragma once

#include "..\scene.h"
#include "../Layers/ObjectLayer.h"
#include "..\player.h"
#include "..\\Components\Control\input.h"
#include "..\\Components\Control\Transform.h"
#include "..\\Components\Action\Render.h"
#include "..\\Components\Action\Animation.h"
#include "..\\Components\Physics\RectangleCollider.h"
#include "..\\Entities\RectangleColliderEnt.h"
#include "..\\Entities\Wall.h"
#include "..\\Entities\slime.h"

class Level
{
public:
	Level();
	~Level();

	std::vector<Entity*> entities;
	
	void LoadLevel();
	void RenderScene();
	Layer* GetObjectLayer();

private:
	std::vector<Scene*> scenes;
	int indexOfCurrScene;
	Player* player;
};