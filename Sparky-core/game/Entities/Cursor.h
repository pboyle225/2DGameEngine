#pragma once

#include "Entity.h"

class Cursor : public Entity
{
public:
	Cursor()
	{
		id = 6;
		globalID = Entity::globalIDCounter++;
		name = "Cursor Entity";
		//this->sprite = sprite;

		//cursorTextures[0] = new Texture("imgs/defaultCursor.png");
		//cursorTextures[1] = new Texture("imgs/handCursor.png");

		//sprite = new Sprite(0, 0, 0, 1, 1, cursorTextures[0]);
	}

	//void update(Window * window, std::vector<Entity *> &entities, math::vec3 playerLoc)
	//{
	//	double x, y;
	//	window->getMousePosition(x, y);

	//	float newx = (float)(x * 32.0f / window->getWidth() - 16.0f);
	//	float newy = (float)(9.0f - y * 18.0f / window->getHeight());

	//	screenPosition.x = newx;
	//	screenPosition.y = newy - sprite->getSize().y;
	//	sprite->m_Position = screenPosition;

	//	//bool isTouching = false;
	//	//for (int i = 0; i < entities.size(); i++)
	//	//{
	//	//	if (entities[i]->getName() == "Player")
	//	//	{
	//	//		continue;
	//	//	}
	//	//	Transform * transformComp = static_cast<Transform *>(entities[i]->getComponent(0));
	//	//	Collectible * collectableComp = static_cast<Collectible *>(entities[i]->getComponent(5));

	//	//	if (transformComp && collectableComp)
	//	//	{
	//	//		if (((int)transformComp->location.x == (int)getWorldCoords(playerLoc).x && (int)transformComp->location.y == (int)getWorldCoords(playerLoc).y)
	//	//			|| (int)transformComp->location.x == (int)getWorldCoords(playerLoc).x && (int)transformComp->location.y - 1 == (int)getWorldCoords(playerLoc).y)
	//	//		{
	//	//			changeTexture(1);
	//	//			isTouching = true;
	//	//		}
	//	//	}
	//	//}

	//	//if (!isTouching)
	//	//{
	//	//	changeTexture(0);
	//	//}
	//}

	////calculate world coords from player position
	//math::vec3 getWorldCoords(math::vec3 playerPos)
	//{
	//	return playerPos + screenPosition;
	//}

	//void changeTexture(int key)
	//{
	//	sprite->m_Texture = cursorTextures[key];
	//}

	//Sprite * getSprite()
	//{
	//	return sprite;
	//}

private:
};