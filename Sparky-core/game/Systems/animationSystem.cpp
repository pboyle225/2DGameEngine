#include "animationSystem.h"

void AnimationSystem::update(std::vector<Entity*> &entities)
{
	for (int i = 0; i < entities.size(); i++)
	{
		AnimationComponent * animComp= static_cast<AnimationComponent*>(entities[i]->getComponent(1));
		SpriteComponent * spriteComp = static_cast<SpriteComponent *>(entities[i]->getComponent(7));

		if (animComp && spriteComp)
		{
			animComp->animations[animComp->currAnimKey]->update();

			if (spriteComp->sprite->texID != animComp->animations[animComp->currAnimKey]->getSprite()->getID())
			{
				spriteComp->sprite->texID = animComp->animations[animComp->currAnimKey]->getSprite()->getID();
			}
		}
	}
}

void AnimationSystem::init(std::vector<Entity*> &entities)
{
	for (int i = 0; i < entities.size(); i++)
	{
		AnimationComponent * animComp = static_cast<AnimationComponent*>(entities[i]->getComponent(1));

		if (animComp)
		{
			animComp->animations[animComp->currAnimKey]->start();
		}
	}
}