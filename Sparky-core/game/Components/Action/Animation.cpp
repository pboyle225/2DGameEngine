#pragma once

#include "Animation.h"

Animation::Animation(AnimationManager* animManager)
{
	id = ComponentIDEnum::AnimComp;
	name = "Animation Component";
	bitmask = ANIMATION_MASK;
	this->animationManager = animManager;
}

AnimationManager* Animation::GetAnimationManager()
{
	return this->animationManager;
}