#pragma once

#include "..\\component.h"
#include "../../Animation/AnimationManager.h"

class Animation : public Component
{
public:
	Animation(AnimationManager* animManager);
	AnimationManager* GetAnimationManager();
private:
	AnimationManager* animationManager;
};
