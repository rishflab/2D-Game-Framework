#pragma once
#include "level.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include <iostream>
#include "Chipmunk\chipmunk.h"
#include "renderer.h"



class Level;

class Actor
{
public:

	//virtual void RenderActor(char* filePath) = 0;
	//virtual void SetTransform(cpFloat x, cpFloat y) = 0;
	//virtual void SetSize(cpFloat w, cpFloat h) =  0;
	//virtual void UpdatePosition() = 0;
	//virtual void AddHitBox(Actor* actor) = 0;
	//virtual void AddDynamicHitBox(Actor* actor) = 0;
	//virtual void DestroyBody();

	//Actor(Level* level, char* name);
	virtual void RenderActor() = 0;
	void SetTransform(cpFloat x, cpFloat y);
	void SetSize(cpFloat w, cpFloat h);
	void UpdatePosition();
	void AddHitBox(Actor* actor);
	void AddDynamicHitBox(Actor* actor);
	void DestroyBody();


	cpShape* shape;

	//Level* level;
	//char* name;

	cpBody* body;
	Uint32 index;




	cpFloat w;
	cpFloat h;



	bool destroyable = false;



	//~Actor();


	//virtual cpBool Begin(cpArbiter *arb, cpSpace *space, cpDataPointer* data)= 0;
	//static int Begin(cpArbiter *arb, cpSpace *space, cpDataPointer* data);

	//static void PostStepRemove(cpSpace *space, cpShape *shape, void *unused);
	//virtual void PostStepRemove(cpSpace *space, cpShape *shape, void *unused) = 0;

};