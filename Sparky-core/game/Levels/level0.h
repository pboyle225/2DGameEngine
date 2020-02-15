#pragma once

#include "..\scene.h"
#include "..\tilelayer.h"
#include "..\player.h"
#include "..\\Components\Control\input.h"
#include "..\\Components\Control\Transform.h"
#include "..\\Components\Action\Render.h"
#include "..\\Components\Action\Animation.h"
#include "..\\Components\Physics\RectangleCollider.h"
#include "..\\Entities\RectangleColliderEnt.h"
#include "..\\Entities\Wall.h"
#include "..\\Entities\slime.h"

class Level0
{
public:
	Level0();
	~Level0();

	std::vector<Entity*> entities;
	
	void LoadLevel();
	void RenderScene();
	void AddRenderableToCurrScene(Renderable2D* renderable);

private:
	std::vector<Scene*> scenes;
	int indexOfCurrScene;
	Player* player;
};