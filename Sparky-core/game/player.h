#pragma once
//#include "entity.h"

#include "../Engine.h"
#include "tilelayer.h"
#include "Components/animationComponent.h"
#include "Entities/entity.h"
#include "level.h"

using namespace engine;
using namespace graphics;

class Player : public Entity
{
public:
	Player(SpriteSheet * playerSprites);
	void update(Layer * layer);
	inline Sprite * getSprite() { return sprite; }
	math::vec3 getLocation();
	void setLocation(math::vec3);
	bool walkingUp;
	bool walkingDown;
	bool walkingLeft;
	bool walkingRight;
	bool isMoving;
	void resetWalkingStates();
	int lastWalkingState; //0-up, 1-down, 2-left, 3-right
	void updateAnimation();
	void addItemToInventory(Entity * item);
	const std::vector<Entity *> & getInventory() const;

private:
	int health;
	float speed;
	Sprite* sprite;
	math::vec3 location;
	std::vector<Entity *> inventory;

	//Animation sprites
	std::vector<Sprite *> animationSprites;
	std::vector<Texture *> walkUpSprites;
	std::vector<Texture *> walkDownSprites;
	std::vector<Texture *> walkLeftSprites;
	std::vector<Texture *> walkRightSprites;
	std::vector<Texture *> idleSprites;
	Animation *walkUp;
	Animation *walkDown;
	Animation *walkLeft;
	Animation *walkRight;
	Animation *idle;
	Animation *animation;

	void move(Window * window);
	void changeAnimation(AnimationState state, AnimationComponent * animComp);
};