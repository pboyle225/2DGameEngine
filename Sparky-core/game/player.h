#pragma once
//#include "entity.h"

#include "../Engine.h"
#include "animation.h"
#include "tilelayer.h"

using namespace engine;
using namespace graphics;

class Player
{
public:
	Player(SpriteSheet * playerSprites);
	void update(Layer * layer, Window * window);
	inline Sprite * getSprite() { return sprite; }
	math::vec3 getLocation();
	void setLocation(math::vec3);
	bool checkCollision(float x, float y); //takes in world coords
private:
	math::vec3 location;
	int health;
	Sprite * sprite;
	float speed;
	float angle;

	//Animation sprites
	std::vector<Sprite *> animationSprites;
	std::vector<Sprite *> walkUpSprites;
	std::vector<Sprite *> walkDownSprites;
	std::vector<Sprite *> walkLeftSprites;
	std::vector<Sprite *> walkRightSprites;
	std::vector<Sprite *> idleSprites;
	Animation *walkUp;
	Animation *walkDown;
	Animation *walkLeft;
	Animation *walkRight;
	Animation *idle;
	Animation *animation;
	bool walkingUp;
	bool walkingDown;
	bool walkingLeft;
	bool walkingRight;
	bool isMoving;
	void resetWalkingStates();
	int lastWalkingState; //0-up, 1-down, 2-left, 3-right

	void move(Window * window);
	void changeAnimation(Animation* anim);
};