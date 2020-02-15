//#include "checkCollision.h"
//#include <algorithm>
//#include "../Components/attack.h"
//#include "../Components/Physics/RectangleCollider.h"
//#include "../Components/circleAppearance.h"
//
//void CheckCollision::update(std::vector<Entity*> &entities)
//{
//	int size = entities.size();
//
//	for (int i = 0; i < size; i++)
//	{
//		Entity * currEnt = entities[i];
//		Transform * transformCompMain = static_cast<Transform *>(currEnt->getComponent(0));
//		Attack * attackCompMain = static_cast<Attack *>(entities[i]->getComponent(10));
//		RectangleCollider * rectCompMain = static_cast<RectangleCollider*>(entities[i]->getComponent(6));
//		CircleAppearance * aggroCircleMain = static_cast<CircleAppearance *>(entities[i]->getComponent(12));
//		Collision * collisionCompMain = static_cast<Collision  *>(entities[i]->getComponent(3));
//
//		if (collisionCompMain)
//		{
//			collisionCompMain->entsCollidedWith.clear();
//
//		}
//
//
//		for (int j = 0 ; j < entities.size(); j++)
//		{
//			if (entities[i]->globalID == entities[j]->globalID)
//			{
//				continue;
//			}
//
//			RectangleCollider* rectCompSecond = static_cast<RectangleCollider*>(entities[j]->getComponent(6));
//			Transform * transformCompSecond = static_cast<Transform *>(entities[j]->getComponent(0));
//			Attack * attackCompSecondary = static_cast<Attack *>(entities[j]->getComponent(10));
//				
//			//find ents in melee range if they need it
//			if (attackCompMain)
//			{
//				if (attackCompMain->isAttacking && (attackCompMain->attackID == 0)) //attack is default melee attack
//				{
//					float meleeDistance = transformCompMain->location.distance(transformCompSecond->location);
//
//					if (meleeDistance <= 2.8f)
//					{
//						attackCompMain->meleeRangeEnts.push_back(entities[j]);
//					}
//				}
//			}
//
//			if (rectCompMain && transformCompMain && rectCompSecond && transformCompSecond && collisionCompMain)
//			{
//				//rectangle rectangle collision
//				if (transformCompMain->location.x < transformCompSecond->location.x + rectCompSecond->width &&
//					transformCompMain->location.x + rectCompMain->width > transformCompSecond->location.x &&
//					transformCompMain->location.y < transformCompSecond->location.y + rectCompSecond->height &&
//					rectCompMain->height + transformCompMain->location.y > transformCompSecond->location.y)
//				{
//					
//					if ((attackCompMain->isFriendly && !attackCompSecondary->isFriendly)
//						|| (!attackCompMain->isFriendly && attackCompSecondary->isFriendly))
//					{
//						//Entities that collided are friendly and enemy
//						if (!attackCompMain->isFriendly)
//						{
//							//Current Entity is an enemy and has hit a friendly entity
//							collisionCompMain->entsCollidedWith.push_back(entities[j]);
//						}
//						else
//						{
//							collisionCompMain->entsCollidedWith.push_back(entities[j]);
//						}
//					}
//				}
//			}
//
//			CircleAppearance * aggroCircleMain = static_cast<CircleAppearance *>(entities[i]->getComponent(12));
//
//			//Circle and rectangle collision
//			if (transformCompMain && rectCompMain && transformCompSecond && aggroCircleMain && attackCompMain && attackCompSecondary)
//			{
//				float DeltaX = transformCompSecond->location.x - std::max(transformCompMain->location.x, std::min(transformCompSecond->location.x, transformCompMain->location.x + rectCompMain->width));
//				float DeltaY = transformCompSecond->location.y - std::max(transformCompMain->location.y, std::min(transformCompSecond->location.y, transformCompMain->location.y + rectCompMain->height));
//
//				//AIComponent * aiCompMain = static_cast<AIComponent *>(entities[i]->getComponent(11));
//
//				//if ((DeltaX * DeltaX + DeltaY * DeltaY) < (aggroCircleMain->radius * aggroCircleMain->radius))
//				//{
//				//	//Rectangle circle collision occured
//
//				//	if ((attackCompMain->isFriendly && !attackCompSecondary->isFriendly)
//				//		|| (!attackCompMain->isFriendly && attackCompSecondary->isFriendly))
//				//	{
//				//		//Friendly and enemy
//				//		if (!aiCompMain->isAggro && !attackCompMain->isFriendly && entities[j]->name == "Player")
//				//		{
//				//			aiCompMain->isAggro = true;
//				//			aiCompMain->entThatAggro = entities[j];
//				//		}
//				//	}
//				//}
//				
//				//else if (aiCompMain && aiCompMain->entThatAggro == entities[j])
//				//{
//				//	aiCompMain->isAggro = false;
//				//	aiCompMain->entThatAggro = NULL;
//				//}
//				
//			}		
//		}
//	}
//}
//
//bool CheckCollision::checkTile(math::vec3 location)
//{
//	//int index = (int)(location.y / TileLayer::sizeOfTile) * Level::height + ((int)location.x / TileLayer::sizeOfTile);
//
//	//if (index < 0 || index > TileLayer::isWalkable.size() - 1)
//	//{
//	//	//Player is out of bounds somehow. Return true so game doesn't crash
//	//	return true;
//	//}
//	//else
//	//{
//	//	return TileLayer::isWalkable[index];
//	//}
//	return true;
//}