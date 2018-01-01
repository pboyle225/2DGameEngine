#pragma once

#include "component.h"
#include "animation.h"

enum AnimationState
{
	IDLE,
	WALK_UP,
	WALK_DOWN,
	WALK_LEFT,
	WALK_RIGHT,
	ATTACK_0,
	ATTACK_1,
	ATTACK_2,
	DEATH
};

class AnimationComponent : public Component
{
public:
	AnimationComponent(AnimationState startingState);

	void addAnimation(AnimationState key, std::vector<Texture *> & textures, int frameDelay);
	void setAnimation(AnimationState animState);
	void updateAnimation();
	void stopAnimation();
	void resetAnimation();
	void startAnimation();

	std::unordered_map<AnimationState, Animation *> animations;
	AnimationState currAnimKey;
};
