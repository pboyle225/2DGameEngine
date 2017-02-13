#include "../Engine.h"
#include "player.h"
#include "level.h"
#include "TmxFile.h"
#include "Components\input.h"
#include "Systems\userInput.h"
#include "Systems\checkCollision.h"
#include "Systems\movement.h"
#include "Systems/renderLayerOrder.h"
#include "Systems\objectDestroyer.h"
#include "Systems\rendering.h"
#include "Systems\timerSystem.h"
#include "cursor.h"

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

		//Load systems
		userInput = new UserInput();
		checkCollision = new CheckCollision();
		movement = new Movement();
		renderLayerOrder = new RenderLayerOrder();
		objectDestroyer = new ObjectDestroyer();
		rendering = new Rendering();
		timerSystem = new TimerSystem();

		//Load WHOLE Spritesheets into memory
		playerSprites = new SpriteSheet("imgs/playerSpritesheet.png", 4, 4, 16, 2);
		//tileSprites = new SpriteSheet("imgs/basictiles.png", 8, 15, 120, 1.5);
		tileSprites = new SpriteSheet("imgs/dungeon.png", 64, 48, 3072, 1);

		currLevel = new Level(0, tileSprites);

		player = new Player(playerSprites);
		player->addComponent(new Input(window));
		player->addComponent(new Collision());
		cursor = new Cursor();
		
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
		currLevel->scenes[currLevel->indexOfCurrScene]->getHudLayer()->add(cursor->getSprite());

		SoundEngine::init();
		SoundEngine::soundEngine->play2D("sounds/backgroundMusic1.mp3", true);
		SoundEngine::soundEngine->setSoundVolume(0.1f);

		currLevel->entities.push_back(player);
		
		isPlayerBehind = false;
	}

	void render() override
	{
		//pass in player's location to only render sprites around them
		cursor->update(window);

		if (currLevel)
		{
			currLevel->scenes[currLevel->indexOfCurrScene]->renderLayers(player->getLocation(), isPlayerBehind);
		}
		else
		{
			exit(-1);
		}
	}

	void tick() override
	{
		printf("%d fps\n", getFPS());
		printf("%d ups\n", getUPS());
	}

	void update() override
	{
		userInput->update(currLevel->entities);
		timerSystem->update(currLevel->entities);
		checkCollision->update(currLevel->entities);
		movement->update(currLevel->entities);
		objectDestroyer->update(currLevel->entities);
		rendering->update(currLevel->entities, currLevel->scenes[currLevel->indexOfCurrScene]);
		
		player->update(currLevel->scenes[currLevel->indexOfCurrScene]->getPlayerLayer());
		isPlayerBehind =  renderLayerOrder->update(currLevel->entities, player->getLocation());

		currLevel->scenes[currLevel->indexOfCurrScene]->update(player->getLocation());

		bool isTouching = false;
		for (int i = 0; i < currLevel->entities.size(); i++)
		{
			if (currLevel->entities[i]->getName() == "Player")
			{
				continue;
			}
			Transform * transformComp = static_cast<Transform *>(currLevel->entities[i]->getComponent(0));

			if (transformComp)
			{
				if ((int)transformComp->location.x == (int)cursor->getWorldCoords(player->getLocation()).x && (int)transformComp->location.y == (int)cursor->getWorldCoords(player->getLocation()).y)
				{
					cursor->changeTexture(1);
					isTouching = true;
				}
			}
		}

		if (!isTouching)
		{
			cursor->changeTexture(0);
		}

		//std::cout << cursor->getWorldCoords(player->getLocation()) << std::endl;

	}

private:
	Window* window;
	SpriteSheet* playerSprites;
	SpriteSheet* tileSprites;
	Player * player;
	bool isPlayerBehind;
	Level * currLevel;
	Cursor * cursor;

	UserInput * userInput;
	CheckCollision * checkCollision;
	Movement * movement;
	RenderLayerOrder * renderLayerOrder;
	ObjectDestroyer * objectDestroyer;
	Rendering* rendering;
	TimerSystem * timerSystem;
};

int main()
{
	Game game;
	game.start();
	return 0;
}