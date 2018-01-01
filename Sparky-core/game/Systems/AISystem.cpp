#include "AISystem.h"

AISystem::AISystem()
{

}

void AISystem::update(std::vector<Entity*> &entities)
{
	for (int i = 0; i < entities.size(); i++)
	{
		AIComponent * aiComp = static_cast<AIComponent *>(entities[i]->getComponent(11));
		Transform * transformComp = static_cast<Transform *>(entities[i]->getComponent(0));
		Direction * directionComp = static_cast<Direction *>(entities[i]->getComponent(15));
		Projectile * projectileComp = static_cast<Projectile *>(entities[i]->getComponent(16));

		math::vec3 dir;
		
		if (projectileComp)
		{
			math::vec3 temp = projectileComp->direction * math::vec3(aiComp->speed, aiComp->speed, aiComp->speed);
			
			entities[i]->addComponent(new Velocity(temp));
		}
		else if (aiComp->isAggro)
		{
			dir = math::vec3(Level::playerLoc - transformComp->location);
			math::vec3 dir2 = dir;

			if (dir.x > 0.0f)
			{
				dir.x = aiComp->speed;
			}
			else if (dir.x < 0)
			{
				dir.x = -aiComp->speed;
			}

			if (dir.y > 0.0f)
			{
				dir.y = aiComp->speed;
			}
			else if (dir.y < 0)
			{
				dir.y = -aiComp->speed;
			}

			math::vec3 temp = dir.normalize() * math::vec3(aiComp->speed, aiComp->speed, aiComp->speed);

			if (directionComp)
			{
				directionComp->updateDirection(dir2);
			}

			entities[i]->addComponent(new Velocity(temp));
			aiComp->isAggro = false;
		}
	}
}