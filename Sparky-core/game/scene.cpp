#include "scene.h"


Scene::Scene(Layer * backgroundLayer, Layer * objectLayer, Layer * collisionLayer, 
				Layer * playerLayer, Layer * hudLayer)
{
	this->backgroundLayer = backgroundLayer;
	this->objectLayer = objectLayer;
	this->collisionLayer = collisionLayer;
	this->playerLayer = playerLayer;
	this->hudLayer = hudLayer;
}

Scene::~Scene()
{
	delete backgroundLayer;
	delete objectLayer;
	delete collisionLayer;
	delete playerLayer;
	delete hudLayer;
}

void Scene::renderLayers(math::vec3 pos)
{
	if (backgroundLayer)
	{
		backgroundLayer->render(pos);
	}

	if (objectLayer)
	{
		objectLayer->render(pos);
	}

	if (collisionLayer)
	{
		//Don't render the collision layer
	}

	if (playerLayer)
	{
		playerLayer->render();
	}

	if (hudLayer)
	{
		hudLayer->render();
	}
}

void Scene::update(math::vec3 playerLoc)
{

	if (backgroundLayer)
	{
		backgroundLayer->update();
	}

	if (objectLayer)
	{
		objectLayer->update();
	}

	if (collisionLayer)
	{
		collisionLayer->update();
	}

	if (playerLayer)
	{
		playerLayer->update();
	}

	if (hudLayer)
	{
		hudLayer->update();
	}
	
	backgroundLayer->getShader()->enable();
	math::vec3 newLoc = playerLoc * math::vec3(-1, -1, -1);
	backgroundLayer->getShader()->setUniformMat4("vw_matrix", math::mat4::translation(newLoc));

	objectLayer->getShader()->enable();
	objectLayer->getShader()->setUniformMat4("vw_matrix", math::mat4::translation(newLoc));
	/*
	foregroundLayers[0]->getShader()->setUniformMat4("pr_matrix", math::mat4::orthographic(-zoomx, zoomx, -zoomy, zoomy, -1.0f, 1.0f));
	

	zoomx -= 0.1f;
	zoomy -= 0.05625f;

	if (zoomx <= 0)
	{
		zoomx = 16.0f;
		zoomy = 9.0f;
	}
	*/
}