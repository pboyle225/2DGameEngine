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

		if (aiComp->isAggro)
		{
			math::vec3 dir = math::vec3(Level::playerLoc - transformComp->location);
			
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
			entities[i]->addComponent(new Velocity(temp));
		}
	}
}