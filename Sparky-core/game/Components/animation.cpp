#include "animation.h"

Animation::Animation(std::vector<Sprite* > frames, int frameDelay)
{
	id = 1;
	name = "Animation";

	this->stopped = true;

	for (int i = 0; i < frames.size(); i++)
	{
		addFrame(frames[i], frameDelay);
	}

	this->frameCount = 0;
	this->frameDelay = frameDelay;
	this->currFrame = 0;
	this->animationDirection = 1;
	this->totalFrames = this->frames.size();
}

Animation::Animation(std::vector<Sprite *> frames, std::vector<int> frameDelay)
{
	this->stopped = true;

	for (int i = 0; i < frames.size(); i++)
	{
		addFrame(frames[i], frameDelay[i]);
	}

	this->frameCount = 0;
	this->frameDelay = 0;
	this->currFrame = 0;
	this->animationDirection = 1;
	this->totalFrames = this->frames.size();
}
void Animation::start()
{
	if (!stopped)
	{
		return;
	}

	if (frames.size() == 0)
	{
		return;
	}

	stopped = false;
}

void Animation::stop()
{
	if (frames.size() == 0)
	{
		return;
	}

	stopped = true;
}

void Animation::restart()
{
	if (frames.size() == 0)
	{
		return;
	}

	stopped = false;
	currFrame = 0;
}

void Animation::reset()
{
	this->stopped = true;
	this->frameCount = 0;
	this->currFrame = 0;
}

void Animation::addFrame(Sprite* sprite, int duration)
{
	if (duration <= 0)
	{
		std::cout << "ERROR: FRAME DURATION LESS THAN 0" << std::endl;
		return;
	}

	frames.push_back(Frame(sprite, duration));
	currFrame = 0;
}

Sprite* Animation::getSprite()
{
	return frames[currFrame].getFrame();
}

void Animation::update()
{
	if (!stopped)
	{
		frameCount++;

		if (frameCount > frames[currFrame].getDuration())
		{
			frameCount = 0;
			currFrame += animationDirection;

			if (currFrame > totalFrames - 1)
			{
				currFrame = 0;
			}
			else if (currFrame < 0)
			{
				currFrame = totalFrames - 1;
			}
		}
	}
}