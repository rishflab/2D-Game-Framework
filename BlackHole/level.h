#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "Chipmunk\chipmunk.h"
#include "actor.h"
#include <vector>

class Actor;

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

	std::vector<Actor*> actorVec;
	


	//void DestroyActor(Actor* actor);
	void RenderLevel();

	void AddActor(Actor* actor);

	void CleanUpActors();

	void DeleteActor(Actor* actor);
	
private:

	
};