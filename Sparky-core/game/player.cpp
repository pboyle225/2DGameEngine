#include "player.h"

Player::Player(SpriteSheet * playerSprites)
{
	name = "Player";
	id = 0;

	location = math::vec3(Level::worldToScreenCoords(math::vec3(35, 20, 0)));
	
	addComponent(new Transform(location));

	health = 100; //TODO add component for health

	lastWalkingState = -1;
	
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
	addComponent(animation);
	sprite = animation->getSprite();
}

void Player::update(Layer * layer)
{
	animation->update();

	if (sprite != animation->getSprite())
	{
		layer->removeAndReplace(sprite, animation->getSprite());
		sprite = animation->getSprite();
	}

	Transform * locComp = static_cast<Transform * >(getComponent(0));
	location = locComp->location;

	//math::mat4 newLoc = math::mat4::rotation(angle, math::vec3(0, 1, 0));
	//sprite->m_Position = newLoc.

	//angle += 30;
	//sprite->m_Position= newLoc * sprite->m_Position;

	//std::cout << "Player's Coords (" << location.x << ", " << location.y << ")" << std::endl;
}

void Player::updateAnimation()
{
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
	return location;
}

void Player::setLocation(math::vec3 loc)
{
	location = loc;
}

void Player::addItemToInventory(Entity * item)
{
	inventory.push_back(item);
}

const std::vector<Entity *> & Player::getInventory() const
{
	return inventory;
}