#include "../Engine.h"
#include "Levels/level0.h"
#include "gameObjectManager.h"
#include "Systems/Physics/PhysicsSystem.h"
#include "Systems\Control\KeyboardInputSystem.h"
#include "Systems/Action/MovementSystem.h"
#include "Systems/Action/RenderSystem.h"
#include "Systems/Control/AIControlSystem.h"
#include "Systems/Action/AnimationSystem.h"

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

	}

	void init() override
	{
		//Create window
		window = createWindow("RPG BRO", 1280, 720);

		// Create sound engine
		SoundEngine::init();
		SoundEngine::soundEngine->setSoundVolume(0.1f);
		SoundEngine::soundEngine->play2D("sounds/game_intro_song_2.ogg", true);

		// Create Level
		currLevel = new Level0();

		//Load systems
		keyboardInputSystem = new KeyboardInputSystem();
		aiControlSystem = new AIControlSystem();
		movementSystem = new MovementSystem();
		physicsSystem = new PhysicsSystem();
		animationSystem = new AnimationSystem();
		renderSystem = new RenderSystem();
		//renderLayerOrder = new RenderLayerOrder();
		//objectDestroyer = new ObjectDestroyer();
		//rendering = new Rendering();
		//timerSystem = new TimerSystem();
		//attackSystem = new AttackSystem();
		//aiSystem = new AISystem();
		//animSystem = new AnimationSystem();
		
		//cursor = new Cursor();

		//animSystem->init(GameObjectManager::animationSystemEnts); //start animations
		
		//currLevel->entities.push_back(player);

		////Testing things
		//sword = new Sprite(0.1, 0.2, 0, 1.5, 1.5, tileSprites->textures[1822]);
		//sword->setAnchorPoint(math::vec3(0.0f, 0.0f, 0.0f));
		//rotation = 360.0f;
		//isPlayerAttacking = false;
		//isPlayerBehind = false;
	}

	void render() override
	{
		if (currLevel)
		{
			currLevel->RenderScene();
		}
	}

	void tick() override
	{
		printf("%d fps\n", getFPS());
		printf("%d ups\n", getUPS());
	}


	void update() override	
	{
		keyboardInputSystem->update(GameObjectManager::inputEnts, window);
		aiControlSystem->update(GameObjectManager::inputEnts);
		movementSystem->update(GameObjectManager::movementEnts);
		physicsSystem->update(GameObjectManager::physicsEnts, deltaTime);
		animationSystem->update(GameObjectManager::animationEnts);
		renderSystem->update(GameObjectManager::renderEnts);

		//Level::cursorPos = cursor->getWorldCoords(player->getLocation());
		//	
		//timerSystem->update(GameObjectManager::timerSystemEnts);
		//aiSystem->update(GameObjectManager::aiSystemEnts);
		//checkCollision->update(GameObjectManager::checkCollisionEnts);
		//attackSystem->update(GameObjectManager::attackSystemEnts);
		//objectDestroyer->update(GameObjectManager::objectDestroyerEnts);
		//rendering->update(GameObjectManager::renderingEnts, currLevel->scenes[currLevel->indexOfCurrScene]);
		//animSystem->update(GameObjectManager::animationSystemEnts);
		//
		//player->update(currLevel->scenes[currLevel->indexOfCurrScene]->getPlayerLayer());
		//isPlayerBehind =  renderLayerOrder->update(currLevel->entities, player->getLocation());

		//currLevel->scenes[currLevel->indexOfCurrScene]->update(player->getLocation());
		//Level::playerLoc = player->getLocation();


		//if (window->isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT) || isPlayerAttacking)
		//{
		//	rotation -= 8.0f;

		//	if (!isPlayerAttacking)
		//	{
		//		currLevel->scenes[0]->getPlayerLayer()->add(sword);
		//	}

		//	if (rotation <= 270.0f)
		//	{
		//		isPlayerAttacking = false;
		//		currLevel->scenes[0]->getPlayerLayer()->remove(sword);
		//		rotation = 360.0f;
		//	}
		//	else
		//	{
		//		isPlayerAttacking = true;
		//	}

		//	sword->setRotate(rotation, math::vec3(0, 0, 1));
		//}

		//HealthComponent * healthComp = static_cast<HealthComponent *>(player->getComponent(13));

		//playerHealth->text = "Health: " + std::to_string((int)healthComp->health);

		//std::cout << currLevel->scenes[0]->getObjectLayer()->getRenderables().size() << std::endl;
	}

private:
	Window* window;
	Level0 * currLevel;

	KeyboardInputSystem* keyboardInputSystem;
	MovementSystem* movementSystem;
	PhysicsSystem* physicsSystem;
	AnimationSystem* animationSystem;
	RenderSystem* renderSystem;
	AIControlSystem* aiControlSystem;

	//CheckCollision * checkCollision;
	//RenderLayerOrder * renderLayerOrder;
	//ObjectDestroyer * objectDestroyer;
	//TimerSystem * timerSystem;
	//AttackSystem * attackSystem;
	//AISystem * aiSystem;
	//AnimationSystem * animSystem;

	////Testing things
	//Sprite * sword;
	//float rotation;
	//bool isPlayerAttacking;
	//Animation * swordAnim;
	//Sprite * currSwordAnim;

};

int main()
{
	Game game;
	game.start();
	return 0;
}