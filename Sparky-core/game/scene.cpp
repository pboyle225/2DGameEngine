#include "scene.h"

//Scene::Scene(std::vector<Layer*> layers)
//{
//	this->layers = layers;
//}

Scene::Scene()
{
	this->hudLayer = NULL;
	this->objectLayer = NULL;
}

Scene::~Scene()
{
	for (auto layer : this->backgroundLayers)
	{
		delete layer;
	}

	delete this->hudLayer;
	delete this->objectLayer;
}

void Scene::renderLayers()
{
	for (Layer* layer : this->backgroundLayers)
	{
		if (layer)
		{
			layer->render();
		}
	}

	if (objectLayer)
	{
		this->objectLayer->render();
	}

	if (hudLayer)
	{
		this->hudLayer->render();
	}
}

void Scene::updateCamera(math::vec3 loc)
{
	math::vec3 newLoc = loc * math::vec3(-1, -1, -1);

	for (Layer* layer : this->backgroundLayers)
	{
		if (layer)
		{
			layer->getShader()->enable();
			layer->getShader()->setUniformMat4("vw_matrix", math::mat4::translation(newLoc));
		}
	}

	if (hudLayer)
	{
		this->hudLayer->getShader()->enable();
		this->hudLayer->getShader()->setUniformMat4("vw_matrix", math::mat4::translation(newLoc));
	}

	if (objectLayer)
	{
		this->objectLayer->getShader()->enable();
		this->objectLayer->getShader()->setUniformMat4("vw_matrix", math::mat4::translation(newLoc));
	}
}