#include "scene.h"
#include "Components\circleAppearance.h"
#include "Components\rectangleAppearance.h"
#include "Components\Transform.h"
#include "Entities\entity.h"

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

void Scene::renderLayers(math::vec3 pos, bool isPlayerBehindObjects, std::vector<Entity *> & entities)
{
	if (backgroundLayer)
	{
		backgroundLayer->render(pos);
	}

	if (isPlayerBehindObjects && playerLayer && objectLayer)
	{
		playerLayer->render();
		objectLayer->render(pos);

		if (DEBUG_DRAW)
		{
			for (int j = 0; j < entities.size(); j++)
			{
				CircleAppearance * circleComp = static_cast<CircleAppearance *>(entities[j]->getComponent(12));
				RectangleAppearance * rectangleComp = static_cast<RectangleAppearance *>(entities[j]->getComponent(6));
				Transform * transComp = static_cast<Transform *>(entities[j]->getComponent(0));

				if (circleComp && transComp)
				{

					int i;
					int triangleAmount = 750;
					GLfloat twicePi = 2.0f * 3.14f;

					glBegin(GL_POINTS);
					glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
					for (i = 0; i <= triangleAmount; i++)
					{
						glVertex2f(transComp->location.x + (circleComp->radius * cos(i * twicePi / triangleAmount)), transComp->location.y + (circleComp->radius * sin(i * twicePi / triangleAmount)));
					}
					glEnd();
				}

				if (rectangleComp)
				{

				}
			}
		}

	}
	else if (playerLayer && objectLayer)
	{
		objectLayer->render(pos);
		
		if (DEBUG_DRAW)
		{
			for (int j = 0; j < entities.size(); j++)
			{
				CircleAppearance * circleComp = static_cast<CircleAppearance *>(entities[j]->getComponent(12));
				RectangleAppearance * rectangleComp = static_cast<RectangleAppearance *>(entities[j]->getComponent(6));
				Transform * transComp = static_cast<Transform *>(entities[j]->getComponent(0));

				if (circleComp && transComp)
				{

					int i;
					int triangleAmount = 750;
					GLfloat twicePi = 2.0f * 3.14f;

					glBegin(GL_POINTS);
					glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
					for (i = 0; i <= triangleAmount; i++)
					{
						glVertex2f(transComp->location.x + (circleComp->radius * cos(i * twicePi / triangleAmount)), transComp->location.y + (circleComp->radius * sin(i * twicePi / triangleAmount)));
					}
					glEnd();
				}

				if (rectangleComp)
				{

				}
			}
		}
		
		playerLayer->render();
	}

	if (collisionLayer)
	{
		//Don't render the collision layer
	}

	if (hudLayer)
	{
		hudLayer->render();
	}
}

void Scene::update(math::vec3 playerLoc)
{
	
	/*
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
	*/
	
	math::vec3 newLoc = playerLoc * math::vec3(-1, -1, -1);
	backgroundLayer->getShader()->enable();
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