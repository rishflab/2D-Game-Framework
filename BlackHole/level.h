#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Box2D\Box2D.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "actor.h"


class Actor;

class Level
{
public:

	
	b2Vec2 gravity;
	b2World* b2level;
	float32 LEVEL_WIDTH = 21.33f;
	float32 LEVEL_HEIGHT = 12.0f;
	Window* window;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;

	Level(Window* window, b2Vec2 gravity);
	
	void DestroyActor(Actor* actor);
	void RenderLevel(char* filePath);
	void Step();
private:

	
};