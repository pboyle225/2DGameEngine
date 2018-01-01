#include "animationComponent.h"

AnimationComponent::AnimationComponent(AnimationState startingState)
{
	id = 1;
	name = "Animation";
	bitmask = 0x1 << 1;

	this->animations = animations;
	this->currAnimKey = startingState;
}

void AnimationComponent::addAnimation(AnimationState key, std::vector<Texture *> & textures, int frameDelay)
{
	animations[key] = new Animation(textures, frameDelay);
}

void AnimationComponent::setAnimation(AnimationState animState)
{

	if (animState != currAnimKey)
	{
		if (animations[animState])
		{
			stopAnimation();
			resetAnimation();
			currAnimKey = animState;
			startAnimation();
		}
	}

}
void AnimationComponent::updateAnimation()
{
	animations[currAnimKey]->update();
}
void AnimationComponent::stopAnimation()
{
	animations[currAnimKey]->stop();
}
void AnimationComponent::resetAnimation()
{
	animations[currAnimKey]->reset();
}

void AnimationComponent::startAnimation()
{
	animations[currAnimKey]->start();
}