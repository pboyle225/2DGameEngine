#include "level.h"

Level::Level(int levelNumber, SpriteSheet * tileSprites)
{
	indexOfCurrScene = 0;
	loadLevel(levelNumber, tileSprites);
}

Level::~Level()
{

}

void Level::loadLevel(int levelNumber, SpriteSheet * tileSprites)
{

	if (levelNumber == 0)
	{
		//Load level data from file
		TmxFile level1File("levels/levelTEST2.tmx");
		level1File.loadTileLayersData();

		TileLayer * backgroundLayer = new TileLayer(new Shader("shaders/basic.vert", "shaders/basic.frag"), tileSprites, level1File.getLayersData()[0], level1File.getAnimationData());
		TileLayer * objectLayer = new TileLayer(new Shader("shaders/basic.vert", "shaders/basic.frag") , tileSprites, level1File.getLayersData()[1], level1File.getAnimationData());
		TileLayer * collisionLayer = new TileLayer(new Shader("shaders/basic.vert", "shaders/basic.frag"), tileSprites, level1File.getLayersData()[2], level1File.getAnimationData());
		Layer * playerLayer = new Layer(new BatchRenderer2D(), new Shader("shaders/basic.vert", "shaders/basic.frag"), math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		Layer * hudLayer = new Layer(new BatchRenderer2D(), new Shader("shaders/basic.vert", "shaders/basic.frag"), math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

		scenes.push_back(new Scene(backgroundLayer, objectLayer, collisionLayer, playerLayer, hudLayer));
	}

}