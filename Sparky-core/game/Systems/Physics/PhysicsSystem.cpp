#include "..\Physics\PhysicsSystem.h"
#include "..\\..\\SoundEngine\soundEngine.h"

void PhysicsSystem::update(std::vector<Entity*>& entities, Timer& deltaTime)
{
	const float MAX_DT = 0.15f;
	math::vec3 dt = deltaTime.elapsed() < MAX_DT ? math::vec3(deltaTime.elapsed(), deltaTime.elapsed(), deltaTime.elapsed())
		: math::vec3(MAX_DT, MAX_DT, MAX_DT);
	HandleCollisions(entities, dt);
	
	for (int i = 0; i < entities.size(); i++)
	{
		Transform* transformComp = static_cast<Transform*>(entities[i]->getComponent(ComponentIDEnum::TransformComp));
		Velocity* velocityComp = static_cast<Velocity*>(entities[i]->getComponent(ComponentIDEnum::VelocityComp));

		if (transformComp && velocityComp)
		{
			transformComp->location += (velocityComp->velocity * dt);
			removeVel.push_back(entities[i]);
		}
	}

	for (int i = 0; i < removeVel.size(); i++)
	{
		removeVel[i]->removeComponent(ComponentIDEnum::VelocityComp);
	}
	removeVel.clear();
}

void PhysicsSystem::HandleCollisions(std::vector<Entity*>& entities, const math::vec3& dt)
{
	std::vector<std::pair<int,int>> collisions;

	for (int j = 0; j < entities.size(); j++)
	{
		RectangleCollider* rect1 = static_cast<RectangleCollider*>(entities[j]->getComponent(ComponentIDEnum::RectangleColliderComp));
		Transform* trans1 = static_cast<Transform*>(entities[j]->getComponent(ComponentIDEnum::TransformComp));
		Velocity* velocityComp1 = static_cast<Velocity*>(entities[j]->getComponent(ComponentIDEnum::VelocityComp));

		if (!rect1 || !rect1->isEnabled || !trans1)
		{
			return;
		}

		math::vec3 newPos1 = velocityComp1 ? trans1->location + (velocityComp1->velocity * dt) : trans1->location;

		for (int i = 0; i < entities.size(); i++)
		{
			if (i == j)
			{
				continue;
			}

			RectangleCollider* rect2 = static_cast<RectangleCollider*>(entities[i]->getComponent(ComponentIDEnum::RectangleColliderComp));
			Transform* trans2 = static_cast<Transform*>(entities[i]->getComponent(ComponentIDEnum::TransformComp));

			if (!rect2 || !rect2->isEnabled || !trans2)
			{
				continue;
			}

			if (AreRectanglesCollided(rect1, newPos1, rect2, trans2->location))
			{
				if (rect2->isSolid && velocityComp1)
				{
					removeVel.push_back(entities[j]);
				}
				else
				{
					bool found = false;
					for (auto const& pair : collisions)
					{
						if ((pair.first == i && pair.second == j) || (pair.first == j && pair.second == i))
						{
							found = true;
							break;
						}
					}

					if (!found)
					{
						collisions.push_back(std::pair<int, int>(i, j));
					}
				}
			}
		}
	}

	for (auto const& pair : collisions)
	{
		entities[pair.first]->addComponent(new Collision(entities[pair.first], entities[pair.second]));
	}
	collisions.clear();

	for (int i = 0; i < removeVel.size(); i++)
	{
		removeVel[i]->removeComponent(ComponentIDEnum::VelocityComp);
	}
	removeVel.clear();
}

bool PhysicsSystem::AreRectanglesCollided(RectangleCollider* rect1, math::vec3 loc1, RectangleCollider* rect2, math::vec3 loc2)
{
	return loc1.x < loc2.x + rect2->width &&
			loc1.x + rect1->width > loc2.x &&
			loc1.y < loc2.y + rect2->height &&
			rect1->height + loc1.y > loc2.y;
}

//void Movement::playBoundrySound()
//{
//	if (!SoundEngine::soundEngine->isCurrentlyPlaying("sounds/bomp.wav"))
//	{
//		SoundEngine::soundEngine->play2D("sounds/bomp.wav", false);
//	}
//}