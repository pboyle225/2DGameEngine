//#include "timerSystem.h"
//
//void TimerSystem::update(std::vector<Entity*> &entities)
//{
//	bool happenOnce = false;
//	for (int i = 0; i < entities.size(); i++)
//	{
//		TimerComponent * timerComp = static_cast<TimerComponent *>(entities[i]->getComponent(8));
//
//		if (timerComp)
//		{	
//			//Check if entity needs to sleep
//			if (timerComp->isAlive && timerComp->timer->elapsed() >= timerComp->timeAlive)
//			{
//				timerComp->isAlive = false;
//				//SpriteComponent * spriteComp = static_cast<SpriteComponent *>(entities[i]->getComponent(7));
//				
//				/*
//				if (spriteComp)
//				{
//					SystemManager::notRenderedSprites.push_back(spriteComp->sprite);
//				}
//				*/
//
//				//Entity has no revive
//				if (!(timerComp->timeDead > 0))
//				{
//					entities[i]->addComponent(new ToDelete());
//				}
//				timerComp->timer->reset();
//			}
//			//Check if entity is asleep and needs to be woken up
//			else if (!timerComp->isAlive && timerComp->timer->elapsed() >= timerComp->timeDead)
//			{
//				timerComp->isAlive = true;
//
//				//SpriteComponent * spriteComp = static_cast<SpriteComponent *>(entities[i]->getComponent(7));
//				
//				//if (spriteComp)
//				//{
//				//	//entity has a sprite so need to add it back to the layer somehow
//				//}
//
//				timerComp->timer->reset();
//			}
//		}
//	}
//}