#include "checkCollision.h"

void CheckCollision::update(std::vector<Entity *> &entities)
{
	for (int i = 0; i < entities.size(); i++)
	{
		Transform * transformComp = static_cast<Transform *>(entities[i]->getComponent(0));
		Collision * collisionComp = static_cast<Collision *>(entities[i]->getComponent(3));
		
		//Check Transform and collision component to check first if entity is on a walkable tile
		if (transformComp && collisionComp)
		{
			Entity * currEntity = entities[i];
			math::vec3 position = transformComp->location;

			//Check to see if enitity has a velocity this update
			Velocity * velocityComp = static_cast<Velocity *>(entities[i]->getComponent(4));
			
			if (velocityComp)
			{
				position += velocityComp->velocity;
			}

			if (!checkTile(position))
			{
				//remove any type of velocity from entity because they are about to be
				//on a non walkable tile
				currEntity->removeComponent(4);
				
				if (!SoundEngine::soundEngine->isCurrentlyPlaying("sounds/bomp.wav"))
				{
					SoundEngine::soundEngine->play2D("sounds/bomp.wav", false);
				}
			}
		}

		
		//iterate through all game objects to see what is colliding with the player
		// O(n^2) right now :(
		if (entities[i]->getName() == "Player")
		{
			Player * player = static_cast<Player *>(entities[i]);
			math::vec3 playerScreenCoords = player->getLocation();

			for (int j = 0; j < entities.size(); j++)
			{
				if (entities[j]->getName() == "Player")
				{
					continue;
				}

				RectangleAppearance * rectComp = static_cast<RectangleAppearance *>(entities[j]->getComponent(6));
				Transform * transformComp = static_cast<Transform *>(entities[j]->getComponent(0));
				
				if (rectComp && transformComp)
				{
					if (playerScreenCoords.x < transformComp->location.x + rectComp->width &&
						playerScreenCoords.x + 0.5f > transformComp->location.x &&
						playerScreenCoords.y < transformComp->location.y + rectComp->height &&
						0.5f + playerScreenCoords.y > transformComp->location.y)
					{
						//Collision between player and rectangle entity
						if (entities[j]->getComponent(5))
						{
							//Collectible component add to player inventory
							player->addItemToInventory(entities[j]);

							entities[j]->addComponent(new ToDelete());
							SoundEngine::soundEngine->play2D("sounds/pickupKey.wav", false);
							SpriteComponent * spriteComp = static_cast<SpriteComponent *>(entities[j]->getComponent(7));
							
							if (spriteComp)
							{
								SystemManager::notRenderedSprites.push_back(spriteComp->sprite);
							}
						}
					}
				}
				
			}
		}


	}
}

bool CheckCollision::checkTile(math::vec3 location)
{
	int index = (int)(location.y / TileLayer::sizeOfTile) * Level::height + ((int)location.x / TileLayer::sizeOfTile);

	if (index < 0 || index > TileLayer::isWalkable.size() - 1)
	{
		//Player is out of bounds somehow. Return true so game doesn't crash
		return true;
	}
	else
	{
		return TileLayer::isWalkable[index];
	}
}