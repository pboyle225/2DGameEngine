#pragma once

#include "../graphics/layers/layer.h"
#include "../graphics/spritesheet.h"
#include "../graphics/batchrenderer2d.h"
#include "Tile.h"
#include "TmxFile.h"

using namespace engine;
using namespace graphics;

class TileLayer : public Layer
{
public:

	TileLayer(Shader * shader, SpriteSheet * spriteSheet, LayerData layerData, std::vector<AnimationTileData> animationsData);
	~TileLayer();

	//void addTile(int x, int y, Sprite * tile, Animation animation);
	void update();
	SpriteSheet * getSpriteSheet();
	bool isWalkableAtLoc(int x, int y);
	bool isCollision();
	int getHeight() { return height; }
	int getWidth() { return width; }
	std::vector<Tile> getTiles();

	static std::vector<bool> isWalkable;
	static int sizeOfTile;
private:
	SpriteSheet * spriteSheet;
	int width;
	int height;
	bool isCollisionLayer;

	std::vector<Tile> tiles;

	std::vector<int> indexOfAnimatedTiles;
};
