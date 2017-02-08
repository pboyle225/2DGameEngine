#pragma once
#include <vector>
#include "frame.h"

class Animation
{
public:
	//Animation();
	Animation(std::vector<Sprite *> frames, int frameDelay);
	Animation(std::vector<Sprite *> frames, std::vector<int> frameDelay);
	void start();
	void stop();
	void restart();
	void reset();
	void addFrame(Sprite* sprite, int duration);
	Sprite* getSprite();
	void update();
private:
	int frameCount;
	int frameDelay;
	int currFrame;
	int animationDirection;
	int totalFrames;
	bool stopped;

	std::vector<Frame> frames;
};