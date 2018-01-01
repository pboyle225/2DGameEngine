#include "player.h"

Player::Player(SpriteSheet * playerSprites)
{
	name = "Player";
	id = 0;
	globalID = globalIDCounter++;

	location = math::vec3(Level::worldToScreenCoords(math::vec3(14, 40, 0)));
	
	addComponent(new Transform(location));
	addComponent(new Attack(5.0f, 0.3f, true, true, 2, false));
	addComponent(new HealthComponent(100.0f));
	addComponent(new Direction());
	addComponent(new RectangleAppearance(2.0f, 2.0f));

	lastWalkingState = -1;

	AnimationComponent * animComp = new AnimationComponent(IDLE);
	
	for (int i = 0; i < playerSprites->textures.size(); i++)
	{
		if (i < 4)
		{
			walkDownSprites.push_back(playerSprites->textures[i]);
		}
		else if (i >= 4 && i < 8)
		{
			walkLeftSprites.push_back(playerSprites->textures[i]);
		}
		else if (i >= 8 && i < 12)
		{
			walkRightSprites.push_back(playerSprites->textures[i]);
		}
		else
		{
			walkUpSprites.push_back(playerSprites->textures[i]);
		}
	}

	idleSprites.push_back(walkDownSprites[0]);

	animComp->addAnimation(WALK_UP, walkUpSprites, 10);
	animComp->addAnimation(WALK_DOWN, walkDownSprites, 10);
	animComp->addAnimation(WALK_RIGHT, walkRightSprites, 10);
	animComp->addAnimation(WALK_LEFT, walkLeftSprites, 10);
	animComp->addAnimation(IDLE, idleSprites, 10);
	addComponent(animComp);

	walkingUp = false;
	walkingDown = false;
	walkingLeft = false;
	walkingRight = false;
	isMoving = false;

	sprite = new Sprite(0, 0, 0, 2, 2, idleSprites[0]);
	sprite->setAnchorPoint(math::vec3(0.5f, 0.0f, 0.0f));
	addComponent(new SpriteComponent(sprite));
}

void Player::update(Layer * layer)
{
	Transform * locComp = static_cast<Transform * >(getComponent(0));
	location = locComp->location;
}

void Player::updateAnimation()
{
	Direction * directionComp = static_cast<Direction *>(getComponent(15));
	AnimationComponent * animComp = static_cast<AnimationComponent *>(getComponent(1));

	if (!isMoving)
	{
		animComp->stopAnimation();
		animComp->resetAnimation();
		resetWalkingStates();
		lastWalkingState = -1;
	}
	else if (walkingUp && lastWalkingState != 0)
	{
		lastWalkingState = 0;
		changeAnimation(WALK_UP, animComp);
		directionComp->currDirection = UP;
	}
	else if (walkingDown && lastWalkingState != 1)
	{
		changeAnimation(WALK_DOWN, animComp);
		lastWalkingState = 1;
		directionComp->currDirection = DOWN;
	}
	else if (walkingLeft && lastWalkingState != 2)
	{
		changeAnimation(WALK_LEFT, animComp);
		lastWalkingState = 2;
		directionComp->currDirection = LEFT;
	}
	else if (walkingRight && lastWalkingState != 3)
	{
		changeAnimation(WALK_RIGHT, animComp);
		lastWalkingState = 3;
		directionComp->currDirection = RIGHT;
	}
}

void Player::resetWalkingStates()
{
	walkingUp = false;
	walkingDown = false;
	walkingLeft = false;
	walkingRight = false;
}

void Player::changeAnimation(AnimationState state, AnimationComponent * animComp)
{
	animComp->stopAnimation();
	animComp->resetAnimation();
	animComp->setAnimation(state);
	animComp->startAnimation();
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