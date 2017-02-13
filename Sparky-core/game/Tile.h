#pragma once

#include "Components/animation.h"
#include "../graphics/renderable2d.h"

using namespace engine;
using namespace graphics;

class Tile
{
public:

	Tile()
	{
		texture = NULL;
		animation = NULL;
		position = math::vec3(0, 0, 0);
		walkable = false;
	}

	Tile(Sprite* texture, math::vec3 position)
		: texture(texture), position(position)
	{
		animation = NULL;
		walkable = false;
	}

	Tile(Sprite* texture, math::vec3 position, Animation* animation)
		: texture(texture), position(position), animation(animation)
	{
		walkable = false;
	}

	Tile(Sprite* texture, math::vec3 position, Animation* animation, bool isWalkable)
		: texture(texture), position(position), animation(animation)
	{
		this->walkable = isWalkable;
	}

	~Tile() 
	{ 
	
	}

	void update(Layer * layer)
	{
		animation->update();
		Sprite * animSprite = animation->getSprite();

		if (texture != animSprite)
		{
			//layer->removeAndReplace(texture, animation->getSprite());
			texture->m_Texture = animSprite->m_Texture;
		}
	}

	Animation * getAnimation() { return animation; }
	Renderable2D * getSprite() { return texture; }
	bool isWalkable(){ return walkable; }
private:
	Sprite * texture;
	Animation * animation;
	math::vec3 position;
	bool walkable;
};
