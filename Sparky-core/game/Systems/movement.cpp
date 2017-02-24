#include "movement.h"

#define KNOCKBACK_FRAMES 60

void Movement::update(std::vector<Entity*> &entities)
{
	int size = entities.size();
	std::vector<Entity *> removeKnock;
	std::vector<Entity *> removeVel;

	for (int i = 0; i < size; i++)
	{
		Transform * transformComp = static_cast<Transform *>(entities[i]->getComponent(0));
		KnockBack * knockbackComp = static_cast<KnockBack *>(entities[i]->getComponent(14));
		Velocity * velocityComp = static_cast<Velocity *>(entities[i]->getComponent(4));
		Collision * collisionComp = static_cast<Collision *>(entities[i]->getComponent(3));
	
		math::vec3 newPosition = transformComp->location;
		
		if (transformComp && knockbackComp)
		{
			//entity is currently being knocked back
			newPosition.x = transformComp->location.x + (knockbackComp->direction.x * knockbackComp->currFrameDistance);
			newPosition.y = transformComp->location.y + (knockbackComp->direction.y * knockbackComp->currFrameDistance);
			bool isWalkable = checkTile(newPosition);

			if (!isWalkable
				|| (int)newPosition.x == (int)knockbackComp->knockBackLoc.x && (int)newPosition.y == (int)knockbackComp->knockBackLoc.y)
			{
				if (!isWalkable && entities[i]->getName() != "Player")
				{
					playBoundrySound();
				}
				removeKnock.push_back(entities[i]);
			}
			else
			{
				transformComp->location = newPosition;
				knockbackComp->currFrameDistance = max(0.1f, knockbackComp->currFrameDistance / 1.035f);
			}
		}
		else if (transformComp && velocityComp)
		{
			newPosition += velocityComp->velocity;

			if (checkTile(newPosition))
			{
				transformComp->location = newPosition;
			}
			else
			{
				playBoundrySound();
			}
		}
		
		SpriteComponent * spriteComp = static_cast<SpriteComponent *>(entities[i]->getComponent(7));

		if (spriteComp && entities[i]->name != "Player")
		{
			spriteComp->sprite->m_Position = transformComp->location;
		}

		entities[i]->removeComponent(velocityComp);

		if (size != entities.size())
		{
			i--;
			size = entities.size();
		}
	}

	for (int i = 0; i < removeKnock.size(); i++)
	{
		removeKnock[i]->removeComponent(14);
	}
}

bool Movement::checkTile(math::vec3 location)
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

void Movement::playBoundrySound()
{
	if (!SoundEngine::soundEngine->isCurrentlyPlaying("sounds/bomp.wav"))
	{
		SoundEngine::soundEngine->play2D("sounds/bomp.wav", false);
	}
}