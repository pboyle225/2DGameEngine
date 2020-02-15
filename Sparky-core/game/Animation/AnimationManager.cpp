#include "AnimationManager.h"

AnimationManager::AnimationManager(std::unordered_map<AnimationStates, std::vector<Frame*>> animMap)
{
	this->animMap = animMap;
	this->currAnimation = animMap[AnimationStates::Default];
	this->currState = AnimationStates::Default;
	isStopped = false;

	this->frameCount = 0;
	this->currFrame = 0;
}

void AnimationManager::start()
{
	isStopped = false;
}

void AnimationManager::pause()
{
	isStopped = true;
}

void AnimationManager::reset()
{
	this->isStopped = true;
	this->frameCount = 0;
	this->currFrame = 0;
}

void AnimationManager::changeAnimation(AnimationStates newAnim)
{
	if (this->currState == newAnim)
	{
		return;
	}

	if (this->animMap.find(newAnim) != this->animMap.end())
	{
		reset();
		this->currAnimation = this->animMap[newAnim];
		this->currState = newAnim;
		start();
	}
}

void AnimationManager::update()
{
	if (isStopped || this->currAnimation.size() <= 0)
	{
		return;
	}

	frameCount++;

	if (frameCount > this->currAnimation[currFrame]->getDuration())
	{
		frameCount = 0;
		currFrame++;

		if (currFrame > this->currAnimation.size() - 1)
		{
			currFrame = 0;
		}
	}
}

Texture* AnimationManager::getCurrentTexture()
{
	return this->currAnimation[currFrame]->getFrame();
}