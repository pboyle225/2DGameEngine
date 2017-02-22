#include "userInput.h"


void UserInput::update(std::vector<Entity*> &entities)
{
	std::vector<Entity *> inputEntities;

	for (int i = 0; i < entities.size(); i++)
	{
		//Transform and input
		if (entities[i]->getComponent(0) && entities[i]->getComponent(2))
		{
			inputEntities.push_back(entities[i]);
		}
	}

	for (int i = 0; i < inputEntities.size(); i++)
	{
		//Player Entity
		if (inputEntities[i]->getID() == 0)
		{
			Player * player = static_cast<Player *>(inputEntities[i]);
			Input * inputComp = static_cast<Input *>(inputEntities[i]->getComponent(2));
			Transform * transformComp = static_cast<Transform *>(inputEntities[i]->getComponent(0));
			math::vec3 movement(0, 0, 0);
			float  speed = 0.08f;
			player->isMoving = false;

			if (inputComp->window->isKeyPressed(GLFW_KEY_W))
			{
				movement.y += speed;
				player->isMoving = true;

				if (!player->walkingUp)
				{
					player->resetWalkingStates();
					player->walkingUp = true;
				}
			}

			if (inputComp->window->isKeyPressed(GLFW_KEY_S))
			{
				movement.y -= speed;
				player->isMoving = true;

				if (!player->walkingDown)
				{
					player->resetWalkingStates();
					player->walkingDown = true;
				}
			}

			if (inputComp->window->isKeyPressed(GLFW_KEY_A))
			{
				movement.x -= speed;
				player->isMoving = true;

				if (!player->walkingLeft)
				{
					player->resetWalkingStates();
					player->walkingLeft = true;
				}
			}

			if (inputComp->window->isKeyPressed(GLFW_KEY_D))
			{
				movement.x += speed;
				player->isMoving = true;

				if (!player->walkingRight)
				{
					player->resetWalkingStates();
					player->walkingRight = true;
				}
			}

			math::vec3 temp = movement.normalize() * math::vec3(speed, speed, speed);

			if (temp.x != 0 || temp.y != 0)
			{
				player->addComponent(new Velocity(temp));
			}

			if (inputComp->window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
			{
				Attack * attackComp = static_cast<Attack *>(inputEntities[i]->getComponent(10));

				if (attackComp)
				{
					attackComp->isAttacking = true;
				}
			}

			player->updateAnimation();
		}
		//Menu widget or something
		else if (inputEntities[i]->getID() == 999)
		{

		}
		
	}
}