#include "spriteComponent.h"


SpriteComponent::SpriteComponent(Sprite * sprite)
{
	id = 7;
	name = "Sprite Component";
	this->sprite = sprite;
	bitmask = 0x1 << 7;
}
