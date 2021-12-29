#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Entity.h"
#include "EntityManager.h"
#include "../Components/Component.h"

class AssetManager;


class Game {
public:
	Game();
	~Game();
	bool IsRunning() const;
	static SDL_Renderer* renderer;
	static AssetManager* assetManager;
	void LoadLevel(int levelNumber);
	void Initialize(int width, int height);
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();
	void testextrasprites();
	int ticksLastFrame;
	

private:
	bool isRunning;
	SDL_Window* window;
	
	
};

#endif 

