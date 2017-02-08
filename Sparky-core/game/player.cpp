#include "player.h"

Player::Player(SpriteSheet * playerSprites)
{
	location = math::vec3(96, 117, 0);
	speed = 0.08f;
	health = 100;
	lastWalkingState = -1;
	angle = 0.0f;
	
	for (int i = 0; i < playerSprites->textures.size(); i++)
	{
		animationSprites.push_back(new Sprite(-1, -0.5, 2, 2, playerSprites->textures[i]));
	}

	//right now there is 16 animations. hard coded for now
	for (int i = 0; i < animationSprites.size(); i++)
	{
		if (i < 4)
		{
			walkDownSprites.push_back(animationSprites[i]);
		}
		else if (i >= 4 && i < 8)
		{
			walkLeftSprites.push_back(animationSprites[i]);
		}
		else if (i >= 8 && i < 12)
		{
			walkRightSprites.push_back(animationSprites[i]);
		}
		else
		{
			walkUpSprites.push_back(animationSprites[i]);
		}
	}

	walkUp = new Animation(walkUpSprites, 10);
	walkingUp = false;
	walkDown = new Animation(walkDownSprites, 10);
	walkingDown = false;
	walkLeft = new Animation(walkLeftSprites, 10);
	walkingLeft = false;
	walkRight = new Animation(walkRightSprites, 10);
	walkingRight = false;
	isMoving = false;

	animation = walkDown;
	animation->stop();
	sprite = animation->getSprite();
}

void Player::update(Layer * layer, Window * window)
{
	move(window);
	animation->update();

	if (sprite != animation->getSprite())
	{
		//animation->getSprite()->m_Position = location;
		layer->removeAndReplace(sprite, animation->getSprite());
		sprite = animation->getSprite();
	}

	//math::mat4 newLoc = math::mat4::rotation(angle, math::vec3(0, 1, 0));
	//sprite->m_Position = newLoc.

	//angle += 30;
	//sprite->m_Position= newLoc * sprite->m_Position;

	//std::cout << "Player's Coords (" << location.x << ", " << location.y << ")" << std::endl;

}

void Player::move(Window * window)
{
	//location = sprite->position;
	isMoving = false;
	math::vec3 movement(0.0f, 0.0f, 0.0f);

	if (window->isKeyPressed(GLFW_KEY_W))
	{
		movement.y += speed;
		isMoving = true;

		if (!walkingUp)
		{
			resetWalkingStates();
			walkingUp = true;
		}
	}

	if (window->isKeyPressed(GLFW_KEY_S))
	{
		movement.y -= speed;
		isMoving = true;

		if (!walkingDown)
		{
			resetWalkingStates();
			walkingDown = true;
		}
	}

	if (window->isKeyPressed(GLFW_KEY_A))
	{
		movement.x -= speed;
		isMoving = true;

		if (!walkingLeft)
		{
			resetWalkingStates();
			walkingLeft = true;
		}
	}

	if (window->isKeyPressed(GLFW_KEY_D))
	{
		movement.x += speed;
		isMoving = true;

		if (!walkingRight)
		{
			resetWalkingStates();
			walkingRight = true;
		}
	}


	if (!isMoving)
	{
		animation->stop();
		animation->reset();
		resetWalkingStates();
		lastWalkingState = -1;
	}
	else if (walkingUp && lastWalkingState != 0)
	{
		changeAnimation(walkUp);
		lastWalkingState = 0;
	}
	else if (walkingDown && lastWalkingState != 1)
	{
		changeAnimation(walkDown);
		lastWalkingState = 1;
	}
	else if (walkingLeft && lastWalkingState != 2)
	{
		changeAnimation(walkLeft);
		lastWalkingState = 2;
	}
	else if (walkingRight && lastWalkingState != 3)
	{
		changeAnimation(walkRight);
		lastWalkingState = 3;
	}


	math::vec3 temp = movement.normalize() * math::vec3(speed, speed, speed);
	
	if (checkCollision(location.x + temp.x, location.y + temp.y))
	{
		location += temp;
	}
	else
	{	
		// play some sound stream, looped
		if (!SoundEngine::soundEngine->isCurrentlyPlaying("sounds/bomp.wav"))
		{
			SoundEngine::soundEngine->play2D("sounds/bomp.wav", false);
		}
	}
}

void Player::resetWalkingStates()
{
	walkingUp = false;
	walkingDown = false;
	walkingLeft = false;
	walkingRight = false;
}

void Player::changeAnimation(Animation* anim)
{
	animation->stop();
	animation->reset();
	animation = anim;
	animation->start();
}

math::vec3 Player::getLocation()
{

	math::vec3 temp(location);
	//temp.x += sprite->getAnchorPoint().x;
	//temp.y += sprite->getAnchorPoint().y;
	return temp;
}

void Player::setLocation(math::vec3 loc)
{
	location = loc;
}

bool Player::checkCollision(float x, float y)
{
	int index = (int)(y / TileLayer::sizeOfTile) * 100 + ((int)x / TileLayer::sizeOfTile);

	//Player is out of bounds. Do some type of message?
	if (index < 0 || index > TileLayer::isWalkable.size() - 1)
	{
		return false;
	}
	else
	{
		return TileLayer::isWalkable[index];
	}
}