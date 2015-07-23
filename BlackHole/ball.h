#pragma once
#include "level.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include <iostream>
#include "actor.h"
#include "Chipmunk\chipmunk.h"

#define BALL_TYPE 1

class Ball : public Actor
{
public:

	Ball(Level* level, char* name);

	void RenderActor();

	void DestroyBody();

	cpCollisionHandler* handler;

	Uint32 collisionID = BALL_TYPE;
	cpCollisionType collisionMask = BALL_TYPE;

	

	//virtual void DestroyBody();

	Level* level;
	char* name;
	//bool destroyable = false;

//private:

	//cpBool(BeginP*)(cpArbiter *arb, cpSpace *space, cpDataPointer* data);

	
	//static  void SPostStepRemove(cpSpace *space, cpShape *shape, void *unused);
};

static cpBool Begin(cpArbiter *arb, cpSpace *space, cpDataPointer* data);

//static cpBool SBegin(cpArbiter *arb, cpSpace *space, cpDataPointer* data);

static void PostStepRemove(cpSpace *space, cpShape *shape, void *unused);
