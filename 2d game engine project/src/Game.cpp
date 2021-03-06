#include "Game.h"
#include <iostream>
#include "Constants.h"
#include "AssetManager.h"
#include "../Components/TransformComponent.h"
#include "../Components/SpriteComponent.h"
#include "../libs/glm/glm.hpp"




EntityManager manager;
AssetManager* Game::assetManager = new AssetManager(&manager);
SDL_Renderer* Game::renderer;

Game::Game()
{
	this->isRunning = false;
}

Game::~Game() {

}

bool Game::IsRunning() const {
	return this->isRunning;
}

glm::vec2 projectilePos = glm::vec2(0.0f, 0.0f);
glm::vec2 projectileVel = glm::vec2(20.0f, 20.0f);



void Game::Initialize(int width,int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "error initializing sdl." << std::endl;
		return;
	}
	window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_BORDERLESS
	);
	if (!window) {
		std::cerr << "error creating window." << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer) {
		std::cerr << "error with renderer." << std::endl;
		return;
	}

	LoadLevel(0);

	isRunning = true;
	return;

}

void Game::LoadLevel(int levelNumber)
{
	//entity 1
	//start including new assets to the assetmanager list
	assetManager->AddTexture("tank-image", std::string("./assets/images/tank-tiger-right.png").c_str());
	assetManager->AddTexture("chopper-image", std::string("./assets/images/chopper-spritesheet.png").c_str());
	assetManager->AddTexture("radar-image", std::string("./assets/images/radar-spritesheet.png").c_str());
	assetManager->AddTexture("saber", std::string("testlightsaber1.png").c_str());
	
	//start including entities and also components to them
	Entity& TankEntity(manager.AddEntity("tank"));
    TankEntity.AddComponent<TransformComponent>(10, 10, 0, 0, 32, 32, 1);
	TankEntity.AddComponent<SpriteComponent>("tank-image");
	
	//Entity& chopperEntity(manager.AddEntity("chopper"));
	//chopperEntity.AddComponent<TransformComponent>(240, 106, 0, 0, 32, 32, 1);
	//chopperEntity.AddComponent<SpriteComponent>("chopper-image", 2, 85, true, false);
	//
	//Entity& radarEntity(manager.AddEntity("Radar"));
	//radarEntity.AddComponent<TransformComponent>(720, 15, 0, 0, 64, 64, 1);
	//radarEntity.AddComponent<SpriteComponent>("radar-image", 8, 150, false, true);
	//
	//Entity& saberEntity(manager.AddEntity("sabers"));
	//saberEntity.AddComponent<TransformComponent>(100, 15, 0, 0, 50, 150, 1);
	//saberEntity.AddComponent<SpriteComponent>("saber", 2, 50, false, true);
	

	manager.ListAllEntities();
}

void Game::ProcessInput() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT: {
		isRunning = false;
		break;
	}
	case SDL_KEYDOWN: {
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			isRunning = false;
		}
		
		
	}
	
	
	default: {
		break;
	}
	}
}

void Game::Update() {
	//wait until 16ms has ellapsed since the last frame
	//while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME));

	int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

	if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
		SDL_Delay(timeToWait);
	}

	//delta time is the difference in ticks from last frame converted to seconds
	float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	//clamp deltatime to a max value
	deltaTime = (SDL_GetTicks() > 0.05f) ? 0.05f : deltaTime;
	//float deltaTime = 0.05f;
	//sets the new ticks for the current frame to be used in the next pass
	ticksLastFrame = SDL_GetTicks();

	manager.Update(deltaTime);
	
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
	SDL_RenderClear(renderer);

	if (manager.HasNoEntities())
	{
		return;
	}

	manager.Render();
		
	SDL_RenderPresent(renderer);

}

void Game::Destroy() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

}

void Game::testextrasprites()
{
	//entity 2
/*std::string texture2 = "./assets/images/tank-tiger-left.png";
assetManager->AddTexture("tankimage2", texture2.c_str());
Entity& entity2(manager.AddEntity("tank2"));

entity2.AddComponent<TransformComponent>(300, 0, -20, 20, 32, 32, 1);
entity2.AddComponent<SpriteComponent>("tankimage2");*/
}
