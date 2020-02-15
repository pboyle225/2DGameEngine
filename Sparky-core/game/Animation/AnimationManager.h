#pragma once
#include <vector>
#include "../../graphics/texture.h"
#include "Frame.h"
#include <unordered_map>

using namespace graphics;

enum AnimationStates
{
	Default,
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Idle,
	Attacking
};

class AnimationManager
{
public:
	AnimationManager(std::unordered_map<AnimationStates, std::vector<Frame*>> animMap);
	void start();
	void pause();
	void changeAnimation(AnimationStates newAnim);
	void reset();
	void update();
	Texture* getCurrentTexture();
private:
	std::unordered_map<AnimationStates, std::vector<Frame*>> animMap;
	std::vector<Frame*> currAnimation;
	AnimationStates currState;
	bool isStopped;
	int currFrame;
	int frameCount;
};
