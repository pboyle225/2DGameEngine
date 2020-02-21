#include "Level.h"

Level::Level()
{
	indexOfCurrScene = 0;
	LoadLevel();
}

Level::~Level()
{

}

void Level::LoadLevel()
{
	//Load level data from file
	//Load WHOLE Spritesheets into memory
	//tileSprites = new SpriteSheet("imgs/basictiles.png", 8, 15, 120, 1.5);
	//tileSprites = new SpriteSheet("imgs/dungeon.png", 64, 48, 3072, 1);
	//playerSprites = new SpriteSheet("imgs/playerSpritesheet.png", 4, 4, 16, 2);
	//sandSprites = new SpriteSheet("imgs/Flooring.png", 8, 8, 64, 1);
		
	// Load assets
	auto playerSprites = new SpriteSheet("imgs/playerSpritesheet.png", 4, 4, 16, 2);
	auto tileSprites = new SpriteSheet("imgs/Flooring.png", 8, 8, 64, 1);
		
	//TmxFile level1File("levels/levelTEST2.tmx");
	TmxFile level1File("levels/DemoLevel.tmx");
	level1File.loadTileLayersData();

	TileLayer * backgroundLayer = new TileLayer(new Shader("shaders/basic.vert", "shaders/basic.frag"), tileSprites, level1File.getLayersData()[0]);
	ObjectLayer* objectLayer = new ObjectLayer(new Shader("shaders/basic.vert", "shaders/basic.frag") , tileSprites, level1File.getLayersData()[1]);
	TileLayer * collisionLayer = new TileLayer(new Shader("shaders/basic.vert", "shaders/basic.frag"), tileSprites, level1File.getLayersData()[2]);
	Layer * hudLayer = new Layer(new BatchRenderer2D(), new Shader("shaders/basic.vert", "shaders/basic.frag"), math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
	
	
	//TODO: Don't push the layer in the list, setup a walkable tile
	//layers.push_back(collisionLayer);

	Scene* scene = new Scene();
	scene->backgroundLayers = std::vector<Layer*>(1, backgroundLayer);
	scene->objectLayer = objectLayer;
	scene->hudLayer = hudLayer;
	scenes.push_back(scene);

	//Player stuff
	std::unordered_map<AnimationStates, std::vector<Frame*>> animMap;
	std::vector<Frame*> currAnim;
	int i = 0;

	for (Texture* texture : playerSprites->textures)
	{
		if (i < 4)
		{
			Frame* frame = new Frame(texture, 7);
			currAnim.push_back(frame);
		}

		if (i == 4)
		{
			animMap[AnimationStates::MoveDown] = currAnim;
			currAnim.clear();
		}
		
		if (i >= 4 && i < 8)
		{
			Frame* frame = new Frame(texture, 7);
			currAnim.push_back(frame);
		}

		if (i == 8)
		{
			animMap[AnimationStates::MoveLeft] = currAnim;
			currAnim.clear();
		}
		
		if (i >= 8 && i < 12)
		{
			Frame* frame = new Frame(texture, 7);
			currAnim.push_back(frame);
		}
		
		if (i == 12)
		{
			animMap[AnimationStates::MoveRight] = currAnim;
			currAnim.clear();
		}

		if (i >= 12)
		{
			Frame* frame = new Frame(texture, 7);
			currAnim.push_back(frame);
		}

		if (i == 15)
		{
			animMap[AnimationStates::MoveUp] = currAnim;
			currAnim.clear();
		}

		i++;
	}

	// Set default
	Frame* frame = new Frame(animMap[AnimationStates::MoveDown][0]->getFrame(), 10);
	currAnim.push_back(frame);
	animMap[AnimationStates::Default] = currAnim;

	AnimationManager* animManager = new AnimationManager(animMap);
	math::vec3 playerLoc = math::vec3(15, 10, 0);
	Sprite* playerSprite = new Sprite(playerLoc.x, playerLoc.y, 2.2f, 2.2f, animManager->getCurrentTexture());
	playerSprite->setAnchorPoint(math::vec3(0.5f, 0.0f, 0.5f));
	Transform* playerTrans = new Transform(playerLoc);
	player = new Player();
	player->addComponent(new Input(8.0f, KEYBOARD));
	player->addComponent(playerTrans);
	player->addComponent(new Render(playerSprite));
	player->addComponent(new Animation(animManager));
	player->addComponent(new FireballAttack(5, 25.0f, 1.0f));

	const float scale = 0.5f;
	player->addComponent(new RectangleCollider(playerSprite->getSize().x * scale, playerSprite->getSize().y * scale));

	Sprite* debugRect = new Sprite(playerLoc.x, playerLoc.y, 2.2f * scale, 2.2f * scale, math::vec4(0.0f, 0.0f, 1.0f, 0.2f));
	Entity* ent = new Entity();
	ent->addComponent(playerTrans);
	ent->addComponent(new Render(debugRect));

	objectLayer->add(playerSprite);
	objectLayer->add(debugRect);

	//Sprite* cursorSprite = new Sprite(0, 0, 0, 1, 1, new Texture("imgs/defaultCursor.png"));
	//cursorSprite->setAnchorPoint(math::vec3(0, 1, 0));
	//Cursor* cursor = new Cursor();
	//cursor->addComponent(new Render(cursorSprite, false));
	//cursor->addComponent(new Transform(math::vec3(0, 0, 0)));
	//cursor->addComponent(new CursorC());
	//hudLayer->add(cursorSprite);

	//Create background for health/mana
	//Group * group = new Group(math::mat4::translation(math::vec3(-1.0f, -1.0f, 0.0f)));s
	//group->add(new Sprite(0, 0, 3.0f, 0.5f, math::vec4(0.95f, 0.0f, 0.0f, 0.8f)));
	//group->add(new Sprite(0, -0.6f, 3.0f, 0.5f, math::vec4(0.0f, 0.0f, 0.95f, 0.8f)));

	////Create text for health/mana
	//playerHealth = new Label("Health: 100", 0.1f, 0.1f, math::vec4(1, 1, 1, 1));
	//group->add(playerHealth);
	//group->add(new Label("Mana: 100", 0.1f, -0.5f, math::vec4(1, 1, 1, 1)));

	//isWalkable = TileLayer::isWalkable;
	//Level::width = backgroundLayer->getWidth();
	//Level::height = backgroundLayer->getHeight();

	for (int i = 0; i < objectLayer->getRenderables().size(); i++)
	{
		Renderable2D* renderable = objectLayer->getRenderables()[i];
		if (renderable->getTID() == 49) //Slime Enemy
		{
			Slime* slime = new Slime();
			
			animMap.clear();
			currAnim.clear();
			frame = new Frame(tileSprites->textures[25], 7);
			currAnim.push_back(frame);
			frame = new Frame(tileSprites->textures[26], 7);
			currAnim.push_back(frame);
			frame = new Frame(tileSprites->textures[27], 7);
			currAnim.push_back(frame);
			frame = new Frame(tileSprites->textures[26], 7);
			currAnim.push_back(frame);
			animMap[AnimationStates::Default] = currAnim;

			currAnim.clear();
			frame = new Frame(tileSprites->textures[24], 7);
			currAnim.push_back(frame);
			frame = new Frame(tileSprites->textures[9], 7);
			currAnim.push_back(frame);
			frame = new Frame(tileSprites->textures[16], 7);
			currAnim.push_back(frame);
			frame = new Frame(tileSprites->textures[17], 7);
			currAnim.push_back(frame);
			animMap[AnimationStates::Attacking] = currAnim;

			Transform* slimeTrans = new Transform(renderable->getPosition());
			slime->addComponent(new Animation(new AnimationManager(animMap)));
			slime->addComponent(new Input(3.0f, InputType::AI));
			slime->addComponent(slimeTrans);
			slime->addComponent(new Render(renderable));
			slime->addComponent(new Animation(new AnimationManager(animMap)));
			slime->addComponent(new RectangleCollider(renderable->getSize()));

			debugRect = new Sprite(renderable->getPosition().x, renderable->getPosition().y, renderable->getSize().x, renderable->getSize().y, math::vec4(1.0f, 0.0f, 0.0f, 0.5f));
			RectangleColliderEnt* ent2 = new RectangleColliderEnt();
			ent2->addComponent(slimeTrans);
			ent2->addComponent(new Render(debugRect));
			
			objectLayer->add(debugRect);
		}
		else if (renderable->getTID() == 75)
		{
			Wall* wall = new Wall();
			wall->addComponent(new Transform(renderable->getPosition()));
			wall->addComponent(new RectangleCollider(renderable->getSize(), true, true));
			wall->addComponent(new Render(renderable));
		}
	 }
}

void Level::RenderScene()
{
	math::vec3 currCameraLoc = GetPlayerLocation();
	//printf("Player - x: %f, y: %f\n", currCameraLoc.x, currCameraLoc.y);
	this->scenes[indexOfCurrScene]->updateCamera(currCameraLoc);
	this->scenes[indexOfCurrScene]->renderLayers(currCameraLoc);
}

Layer* Level::GetObjectLayer()
{
	return this->scenes[indexOfCurrScene]->objectLayer;
}

math::vec3 Level::GetPlayerLocation()
{
	return static_cast<Transform*>(player->getComponent(ComponentIDEnum::TransformComp))->location;
}