#include "checkCollision.h"
#include <algorithm>

void CheckCollision::update(std::vector<Entity*> &entities)
{
	int size = entities.size();

	std::vector<Entity *> removeVelocEnts;

	for (int i = 0; i < size; i++)
	{
		Entity * currEnt = entities[i];
		Transform * transformComp = static_cast<Transform *>(currEnt->getComponent(0));
		Collision * collisionComp = static_cast<Collision *>(currEnt->getComponent(3));
		bool removeVeloc = false;
		Velocity * velocityComp = static_cast<Velocity *>(currEnt->getComponent(4));
		
		//Check Transform and collision component to check first if entity is on a walkable tile
		if (transformComp && collisionComp)
		{
			math::vec3 position = transformComp->location;

			//Check to see if enitity has a velocity this update
			
			if (velocityComp)
			{
				position += velocityComp->velocity;
			}

			if (!checkTile(position))
			{
				//remove any type of velocity from entity because they are about to be
				//on a non walkablea tile
				removeVelocEnts.push_back(entities[i]);
				
				if (currEnt->name == "Player" && !SoundEngine::soundEngine->isCurrentlyPlaying("sounds/bomp.wav"))
				{
					SoundEngine::soundEngine->play2D("sounds/bomp.wav", false);
				}
			}
		}

		
		//iterate through all game objects to see what is colliding with the player
		// O(n^2) right now :(
		if (currEnt->getName() == "Player")
		{
			Player * player = static_cast<Player *>(currEnt);
			math::vec3 playerScreenCoords = transformComp->location;

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
						if (entities[j]->getComponent(5)) //has collectible component
						{
							player->addItemToInventory(entities[j]);

							entities[j]->addComponent(new ToDelete());
							SoundEngine::soundEngine->play2D("sounds/pickupKey.wav", false);
							SpriteComponent * spriteComp = static_cast<SpriteComponent *>(entities[j]->getComponent(7));
							
							if (spriteComp)
							{
								SystemManager::notRenderedSprites.push_back(spriteComp->sprite);
							}

							entities[j]->removeComponent(5);
						}
						
						if (entities[j]->getComponent(10)) //has attack component
						{
							Attack * attackComp = static_cast<Attack *>(entities[j]->getComponent(10));
							attackComp->isAttacking = true;
						}
						
						if (entities[j]->getComponent(420)) //has circle radius
						{
						}
					}
				}

				CircleAppearance * aggroCircle = static_cast<CircleAppearance *>(entities[j]->getComponent(12));

				if (transformComp && aggroCircle)
				{
					float DeltaX = transformComp->location.x - std::max(playerScreenCoords.x, std::min(transformComp->location.x, playerScreenCoords.x + 0.5f));
					float DeltaY = transformComp->location.y - std::max(playerScreenCoords.y, std::min(transformComp->location.y, playerScreenCoords.y + 0.5f));
					
					AIComponent * aiComp = static_cast<AIComponent *>(entities[j]->getComponent(11));
					
					if ((DeltaX * DeltaX + DeltaY * DeltaY) < (aggroCircle->radius * aggroCircle->radius))
					{
						if (aiComp)
						{
							aiComp->isAggro = true;
						}
					}
					else if(aiComp)
					{
						aiComp->isAggro = false;
					}
				}
				
			}
		}
	}

	for (int j = 0; j < removeVelocEnts.size(); j++)
	{
		removeVelocEnts[j]->removeComponent(4);
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