#include "attackSystem.h"

AttackSystem::AttackSystem()
{

}

/*
NOTES ABOUT ATTACKSYSTEM/SKILLS

ATTACK 0: traditional melee attack (Melee Attack Default)
ATTACK 1: choose a map location to charge to (Jump Attack)
ATTACK 2: Fireball (basic ranged attack)

*/

void AttackSystem::update(std::vector<Entity*> &entities)
{
	for (int i = 0; i < entities.size(); i++)
	{
		Attack * attackComp = static_cast<Attack *>(entities[i]->getComponent(10));
		Collision * collisionComp = static_cast<Collision *>(entities[i]->getComponent(3));

		if (attackComp)
		{
			//check if attack can happen
			if (attackComp->timer.elapsed() >= attackComp->attackSpeed)
			{
				if (collisionComp && attackComp->hurtsWhentouched)
				{
					if (collisionComp->entsCollidedWith.size() > 0)
					{
						for (int j = 0; j < collisionComp->entsCollidedWith.size(); j++)
						{
							if (collisionComp->entsCollidedWith[j])
							{
								attackComp->attackThisEntity = collisionComp->entsCollidedWith[j];
								deductHealth(entities[i], attackComp);
								break;
							}
						}

						if (entities[i]->getName() == "Fireball")
						{
							entities[i]->addComponent(new ToDelete());
						}

						resetAttack(attackComp);
						collisionComp->entsCollidedWith.clear();
						AnimationComponent * animComp = static_cast<AnimationComponent*>(entities[i]->getComponent(1));
						if (animComp)
						{
							animComp->setAnimation(IDLE);
						}
						continue;
					}				
				}
				
				if (attackComp->attackID == 0 && attackComp->isAttacking)
				{
					doMeleeAttack(entities[i], attackComp);
				}
				else if (attackComp->attackID == 1)
				{
					doJumpAttack(entities[i], attackComp);
				}
				else if (attackComp->attackID == 2 && attackComp->isAttacking)
				{
					doFireballAttack(entities[i], attackComp);
				}
			}
		}


		collisionComp->entsCollidedWith.clear();
	}
}

void AttackSystem::doMeleeAttack(Entity * playerEnt, Attack * attackComp)
{
	Entity * closestEnt = NULL;
	float closestDis = 100.0f;

	for (int i = 0; i < attackComp->meleeRangeEnts.size(); i++)
	{
		Transform * transformComp = static_cast<Transform *>(attackComp->meleeRangeEnts[i]->getComponent(0));
		Transform * playerTransformComp = static_cast<Transform *>(playerEnt->getComponent(0));

		float angle = atan2(transformComp->location.y - playerTransformComp->location.y, transformComp->location.x - playerTransformComp->location.x);

		Direction * playerDirection = static_cast<Direction *>(playerEnt->getComponent(15));

		if (playerDirection)
		{
			if (playerDirection->currDirection == UP)
			{
				angle -= 1.5708;
			}
			else if (playerDirection->currDirection == DOWN)
			{
				angle -= 4.71239;
			}
			else if (playerDirection->currDirection == LEFT)
			{
				angle -= 3.14159;
			}
		}

		angle = abs(angle);

		if (angle >= 3.14)
		{
			angle -= 6.28319;
			angle = abs(angle);
		}

		if (angle < 1.5f) //~90 degrees
		{
			float distance = playerTransformComp->location.distance(transformComp->location);
				
			if (distance < closestDis)
			{
				closestEnt = attackComp->meleeRangeEnts[i];
				closestDis = distance;
			}
		}
	}
	attackComp->attackThisEntity = closestEnt;

	if (attackComp->attackThisEntity)
	{
		deductHealth(playerEnt, attackComp);
	}

	attackComp->meleeRangeEnts.clear();
	attackComp->isAttacking = false;
}

/* Steps of the "Jump Attack" (ID 1)
	1. Entity must be aggro'd
	2. Entity remembers location of the entity its attacking
	3. Entity stays put for 1 second
	4. After 1 second the entity needs to jump to the location it remembered
	5. After it has reached that location the attack is done
*/
void AttackSystem::doJumpAttack(Entity * attackingEntity, Attack * attackComp)
{
	AIComponent * attackingAIComp = static_cast<AIComponent *>(attackingEntity->getComponent(11));
	AnimationComponent * animComp = static_cast<AnimationComponent*>(attackingEntity->getComponent(1));

	if (attackingAIComp->isAggro || attackComp->isAttacking)
	{
		if (animComp)
		{
			animComp->setAnimation(ATTACK_0);
		}

		//Entity is performing a jump attack
		if (!attackComp->combatSkill)
		{
			Transform * transformComp = static_cast<Transform *>(attackingAIComp->entThatAggro->getComponent(0));
			Transform * transformCompMain = static_cast<Transform *>(attackingEntity->getComponent(0));
			JumpAttack * jumpAttack = new JumpAttack(attackingEntity, transformComp->location);

			attackComp->combatSkill = jumpAttack;
			attackComp->isAttacking = true;

			//std::cout << "Entity: " << attackingEntity->getName() << transformCompMain->location << " is jumping to " << transformComp->location << std::endl;
		}

		//remove Velocity component
		attackingEntity->removeComponent(4);
		
		JumpAttack * jumpAttack = static_cast<JumpAttack *>(attackComp->combatSkill);
		
		if (jumpAttack->currFrame++ >= 80)
		{
			Transform * transformCompThis = static_cast<Transform *>(attackingEntity->getComponent(0));

			KnockBack * knockBackComp = static_cast<KnockBack *>(attackingEntity->getComponent(14));

			
			if (!knockBackComp && !jumpAttack->isJumping)
			{
				attackingEntity->addComponent(new KnockBack(0.0f, jumpAttack->jumpLoc - transformCompThis->location, jumpAttack->jumpLoc));
				jumpAttack->isJumping = true;
			}
			else if(!knockBackComp && jumpAttack->isJumping)
			{
				//attack is over
				resetAttack(attackComp);

				animComp->setAnimation(IDLE);
			}
			

		}
	}
}

void AttackSystem::doFireballAttack(Entity * attackingEntity, Attack * attackComp)
{
	Transform* transformCompThis = static_cast<Transform*>(attackingEntity->getComponent(0));

	Fireball * fireball = new Fireball();
	fireball->addComponent(new Transform(transformCompThis->location));
	fireball->addComponent(new AIComponent(true, 0.2f));
	fireball->addComponent(new Attack(10.0f, 0.01f, true, true, 2, true));
	fireball->addComponent(new RectangleAppearance(2.0f, 2.0f));
	fireball->addComponent(new Collision());
	fireball->addComponent(new Projectile(Level::cursorPos - transformCompThis->location));
	
	Sprite * fireballSprite = new Sprite(transformCompThis->location.x, transformCompThis->location.y,
		1.0f, 1.0f, math::vec4(0.0f, 0.0f, 1.0f, 1.0f));
		
	fireball->addComponent(new SpriteComponent(fireballSprite));

	SystemManager::addRenderedSprites.push_back(fireballSprite);
	Level::entities.push_back(fireball);

	resetAttack(attackComp);
}

void AttackSystem::resetAttack(Attack * attackComp)
{
	attackComp->attackThisEntity = NULL;
	attackComp->isAttacking = false;
	attackComp->timer.reset();

	if (attackComp->combatSkill)
	{
		CombatSkill * toDelete = attackComp->combatSkill;
		attackComp->combatSkill = NULL;
		delete toDelete;
	}
}

void AttackSystem::deductHealth(Entity * attackingEntity, Attack * attackComp)
{
	HealthComponent * healthOfAttacking = static_cast<HealthComponent *>(attackComp->attackThisEntity->getComponent(13));
	
	//reset attack of entity getting hit
	Attack * attackCompToReset = static_cast<Attack*>(attackComp->attackThisEntity->getComponent(10));
	Transform * transComp = static_cast<Transform *>(attackComp->attackThisEntity->getComponent(0));
	resetAttack(attackCompToReset);

	if (healthOfAttacking)
	{
		healthOfAttacking->health -= attackComp->attackDamage;

		if (transComp)
		{
			AttackTextEntity * attackDam = new AttackTextEntity();
			attackDam->addComponent(new TimerComponent(2.0f));
			attackDam->addComponent(new Transform(transComp->location));
			Label * attackLabel = new Label(std::to_string((int)attackComp->attackDamage), transComp->location.x, transComp->location.y, math::vec4(1.0f, 0.0f, 0.0f, 1.0f));
			attackDam->addComponent(new LabelComponent(attackLabel));
			SystemManager::addLabels.push_back(attackLabel);
		}

		if (healthOfAttacking->health <= 0.0f && attackComp->attackThisEntity->getName() != "Player")
		{
			//entity is out of health
			attackComp->attackThisEntity->addComponent(new ToDelete());
			return;
		}

		//add a knockback to the enemy being hit
		Transform* transformCompAttacking = static_cast<Transform*>(attackComp->attackThisEntity->getComponent(0));
		Transform* transformCompThis = static_cast<Transform*>(attackingEntity->getComponent(0));

		if (attackComp->knockBackAmount > 0.0f)
		{
			attackComp->attackThisEntity->addComponent(new KnockBack(attackComp->knockBackAmount, transformCompAttacking->location - transformCompThis->location, transformCompAttacking->location));
		}

		if (attackComp->attackThisEntity->name == "Player")
		{
			SoundEngine::soundEngine->play2D("sounds/playerHurt1.wav");
		}
		else if (attackComp->attackThisEntity->name == "Slime")
		{
			SoundEngine::soundEngine->play2D("sounds/slimeHurt1.wav");
		}

		//std::cout << attackComp->attackThisEntity->getName() << " Health: " << healthOfAttacking->health << std::endl;
	}
}