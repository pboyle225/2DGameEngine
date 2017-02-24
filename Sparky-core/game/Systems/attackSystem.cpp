#include "attackSystem.h"

AttackSystem::AttackSystem()
{

}

void AttackSystem::update(std::vector<Entity*> &entities)
{
	for (int i = 0; i < entities.size(); i++)
	{
		Attack * attackComp = static_cast<Attack *>(entities[i]->getComponent(10));

		if (attackComp)
		{
			if (attackComp->isAttacking && attackComp->timer.elapsed() >= attackComp->attackSpeed)
			{
				//will attack this update
				
				if (attackComp->attackThisEntity)
				{
					HealthComponent * healthOfAttacking = static_cast<HealthComponent *>(attackComp->attackThisEntity->getComponent(13));

					if (healthOfAttacking)
					{
						healthOfAttacking->health -= attackComp->attackDamage;

						if (healthOfAttacking->health <= 0.0f && attackComp->attackThisEntity->getName() != "Player")
						{
							//entity ran out of health
							attackComp->attackThisEntity->addComponent(new ToDelete());
							SpriteComponent * spriteComp = static_cast<SpriteComponent *>(attackComp->attackThisEntity->getComponent(7));
							SystemManager::notRenderedSprites.push_back(spriteComp->sprite);
							GameObjectManager::clearEntFromSystems(attackComp->attackThisEntity);
						}
						else
						{
							//add a knockback to the enemy being hit
							Transform* transformComp = static_cast<Transform*>(attackComp->attackThisEntity->getComponent(0));
							attackComp->attackThisEntity->addComponent(new KnockBack(5.0f, math::vec3(1.0f, 0.0f, 0.0f), transformComp->location));

							std::cout << entities[i]->getName() << " has just attacked: " << attackComp->attackThisEntity->getName() << " for: " << attackComp->attackDamage << std::endl;
						}
					}
				}
			
				attackComp->timer.reset();
			}
			
			attackComp->attackThisEntity = NULL;
			attackComp->isAttacking = false;
		}
	}
}