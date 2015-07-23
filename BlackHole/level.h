#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "Chipmunk\chipmunk.h"
//#include "actor.h"




class Level
{
public:

	cpSpace* space;

	cpFloat LEVEL_WIDTH = 32.0f;
	cpFloat LEVEL_HEIGHT = 28.0f;
	Window* window;

	cpFloat timeStep;
	int velocityIterations;
	int positionIterations;

	Level(Window* window, cpVect gravity);
	
	//void DestroyActor(Actor* actor);
	void RenderLevel(char* filePath);
	void Step();
private:

	
};