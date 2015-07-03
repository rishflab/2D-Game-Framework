#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Box2D\Box2D.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "actor.h"
#include "level.h"
#include <vector>


class CollisionManager
{
public:

	CollisionManager(Level* level);

	void AddActor(Actor* actor);

	void Debug_PrintActors();

	void Update();

	Level* level;

	std::vector<Actor*> actorList;

	int i = 1;
	
private:
};