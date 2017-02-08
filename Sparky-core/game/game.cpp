#include "../Engine.h"
#include "player.h"
#include "level.h"
#include "TmxFile.h"

using namespace engine;
using namespace graphics;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll



class Game : public Engine
{
public:
	Game()
	{

	}

	~Game()
	{
		delete playerSprites;
		delete tileSprites;
	}

	void init() override
	{
		//Create window
		window = createWindow("RPG BRO", 960, 540);


		//Load WHOLE Spritesheets into memory
		playerSprites = new SpriteSheet("imgs/playerSpritesheet.png", 4, 4, 16, 2);
		//tileSprites = new SpriteSheet("imgs/basictiles.png", 8, 15, 120, 1.5);
		tileSprites = new SpriteSheet("imgs/dungeon.png", 64, 48, 3072, 1);

		currLevel = new Level(0, tileSprites);
		player = new Player(playerSprites);
		cursor = new Sprite(0.0f, 0.0f, 1.0f, 2.0f, 2.0f, new Texture("cursor.png"));
		
		//Create background for health/mana
		Group * group = new Group(math::mat4::translation(math::vec3(-1.0f, -1.0f, 0.0f)));
		group->add(new Sprite(0, 0, 3.0f, 0.5f, math::vec4(0.95f, 0.0f, 0.0f, 0.8f)));
		group->add(new Sprite(0, -0.6f, 3.0f, 0.5f, math::vec4(0.0f, 0.0f, 0.95f, 0.8f)));
		
		//Create text for health/mana
		Label * playerHealth = new Label("Health: 100%", 0.1f, 0.1f, math::vec4(1, 1, 1, 1));
		group->add(playerHealth);
		group->add(new Label("Mana: 100%", 0.1f, -0.5f, math::vec4(1, 1, 1, 1)));

		currLevel->scenes[currLevel->indexOfCurrScene]->getPlayerLayer()->add(player->getSprite());
		currLevel->scenes[currLevel->indexOfCurrScene]->getHudLayer()->add(group);
		currLevel->scenes[currLevel->indexOfCurrScene]->getHudLayer()->add(cursor);

		SoundEngine::init();
		//SoundEngine::soundEngine->play2D("sounds/backgroundMusic1.mp3", true);
		SoundEngine::soundEngine->setSoundVolume(0.1f);
	}

	void render() override
	{
		//pass in player's location to only render sprites around them
		updateCursor();
		currLevel->scenes[currLevel->indexOfCurrScene]->renderLayers(player->getLocation());
	}

	void tick() override
	{
		printf("%d fps\n", getFPS());
		printf("%d ups\n", getUPS());
	}

	void update() override
	{
		player->update(currLevel->scenes[currLevel->indexOfCurrScene]->getPlayerLayer(), window);
		
		//TODO: make player derive from entity and throw in all entities to this funciton
		checkCollisions(player);

		//Updates view matrix based on players location so camera follows player
		currLevel->scenes[currLevel->indexOfCurrScene]->update(player->getLocation());

	}

	void updateCursor()
	{
		double x, y;
		window->getMousePosition(x, y);

		float newx = (float)(x * 32.0f / window->getWidth() - 16.0f);
		float newy = (float)(9.0f - y * 18.0f / window->getHeight());

		cursor->m_Position.x = newx - 1.05f;
		cursor->m_Position.y = newy - 1.3f;

	}

	void checkCollisions(Player * player)
	{

	}

private:
	Window* window;
	Layer* playerLayer;
	Layer* backgroundLayer;
	Sprite* playerSprite;
	Sprite* cursor;
	Shader* shader2;
	Shader* shader;
	SpriteSheet* playerSprites;
	SpriteSheet* tileSprites;
	Player * player;
	bool isRendered;
	float angle;
	Level * currLevel;
	//std::vector create a world that combines all layers to check collision with player
	//Would have to update this every update()
};

int main()
{
	Game game;
	game.start();
	return 0;
}