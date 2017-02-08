#include "tilelayer.h"

std::vector<bool> TileLayer::isWalkable;
int TileLayer::sizeOfTile;

TileLayer::TileLayer(Shader * shader, SpriteSheet * spriteSheet, LayerData layerData, std::vector<AnimationTileData> animationsData)
	:Layer(new BatchRenderer2D(), shader, math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
{
	isCollisionLayer = false;
	int dataIterator = 0;
	int indexTemp = 0;
	sizeOfTile = 2;
	this->width =layerData.width;
	this->height = layerData.height;
	tiles = std::vector<Tile>(width * height, Tile());

	if (layerData.name == "Collision")
	{
		isCollisionLayer = true;
		isWalkable = std::vector<bool>(width * height, true);
	}
	//stack layers on top of eachother
	for (int y = (height - 1) * sizeOfTile; y >= 0; y -= sizeOfTile)
	{
		for (int x = 0; x < width * sizeOfTile; x += sizeOfTile)
		{
			std::string actualIndex;

			while (layerData.data[dataIterator] == ',' || layerData.data[dataIterator] == '\r' || layerData.data[dataIterator] == '\n')
			{
				dataIterator++;
			}

			while (layerData.data[dataIterator] != ',' && layerData.data[dataIterator] != '\r' && layerData.data[dataIterator] != '\n')
			{
				actualIndex += layerData.data[dataIterator++];
			}

			int tempIndex = (atoi(actualIndex.c_str()) - 1);

			if (tempIndex >= 0)
			{
				//Need to create Tiles
				bool isAnimated = false;
				
				for (int i = 0; i < animationsData.size(); i++)
				{
					int tileID = atoi(animationsData[i].tileID.c_str());

						if (tempIndex == tileID)
						{
							isAnimated = true;

							Sprite* initialSprite = new Sprite(x, y, sizeOfTile, sizeOfTile, spriteSheet->textures[tempIndex]);
							std::vector<Sprite *> animatedSprites;
							std::vector<int> frameDurations;

							for (int j = 0; j < animationsData[i].frameData.size(); j++)
							{
								int indexOfTexture = atoi(animationsData[i].frameData[j].tileID.c_str());
								animatedSprites.push_back(new Sprite(x, y, sizeOfTile, sizeOfTile, spriteSheet->textures[indexOfTexture]));
								frameDurations.push_back(atoi(animationsData[i].frameData[j].duration.c_str()));
							}

							Tile tileTemp(initialSprite, math::vec3(x, y, 0), new Animation(animatedSprites, frameDurations));

							tileTemp.getAnimation()->start();
							this->add(tileTemp.getSprite()); //The rendered version
							int index = (y / sizeOfTile) * height + (x/ sizeOfTile);
							
							tiles[index] = tileTemp;	  //The world version
							indexOfAnimatedTiles.push_back(index);

							break;
						}
				}

				if (!isAnimated)
				{
					if (!isCollisionLayer)
					{
						Sprite* temp = new Sprite(x, y, sizeOfTile, sizeOfTile, spriteSheet->textures[tempIndex]);
						this->add(temp);
						int index = (y / sizeOfTile) * height + (x / sizeOfTile);
						tiles[index] = Tile(temp, math::vec3(x, y, 0));
					}
					else
					{
						//Sprite* temp = new Sprite(x, y, 1, 1, NULL);
						int index = (y / sizeOfTile) * height + (x / sizeOfTile);
						tiles[index] = Tile(NULL, math::vec3(x, y, 0));
						isWalkable[index] = false;
					}
				}
			}

			indexTemp++;
		}
	}
}



TileLayer::~TileLayer()
{

}

void TileLayer::addTile(int x, int y, Sprite * tile, Animation animation)
{


}

void TileLayer::update()
{
	for (int i = 0; i < indexOfAnimatedTiles.size(); i++)
	{
		if (tiles[indexOfAnimatedTiles[i]].getAnimation() != NULL)
		{
			tiles[indexOfAnimatedTiles[i]].update(this);
		}
	}
}

SpriteSheet * TileLayer::getSpriteSheet()
{
	return spriteSheet;
}

bool TileLayer::isWalkableAtLoc(int x, int y)
{
	if ((y < height && y >= 0) && (x < width && x >= 0))
	{
		return tiles[y * height + x].isWalkable();
	}

	return false;
}

bool TileLayer::isCollision()
{
	return this->isCollisionLayer;
}
