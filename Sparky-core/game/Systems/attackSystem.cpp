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
			if (attackComp->isAttacking)
			{
				std::cout << "Entity: " << entities[i]->getName() << " has just attacked for: " << attackComp->attackDamage << std::endl;
				attackComp->isAttacking = false;
			}
		}
	}
}