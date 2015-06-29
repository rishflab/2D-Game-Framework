#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Box2D\Box2D.h"
#include <stdio.h>
#include "String.h"
#include "window.h"


class Level
{
public:

	Level(Window* window, b2Vec2 gravity);

	void RenderLevel(char* filePath);

	b2Vec2 gravity;

	b2World* b2level;
	
	float32 LEVEL_WIDTH = 40.0f;
	float32 LEVEL_HEIGHT = 12.0f;

	Window* window;
private:

	
};