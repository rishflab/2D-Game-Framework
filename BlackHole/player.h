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

#define PLAYER_TYPE 3
#define PLAYER_FOOT_TYPE 4

class Player : public Actor
{
public:

	Player(Level* level, char* name);

	void RenderActor();

	void DestroyBody();

	void PlayerMove();

	cpCollisionHandler* handler;

	Uint32 collisionID = PLAYER_TYPE;
	cpCollisionType collisionMask = PLAYER_TYPE;

	cpShape* foot;

	//virtual void DestroyBody();

	Level* level;
	char* name;
	//bool destroyable = false;
	//void Stop();
	//private:

	//cpBool(BeginP*)(cpArbiter *arb, cpSpace *space, cpDataPointer* data);


	//static  void SPostStepRemove(cpSpace *space, cpShape *shape, void *unused);
};

static cpBool Begin(cpArbiter *arb, cpSpace *space, cpDataPointer* data);

//static cpBool SBegin(cpArbiter *arb, cpSpace *space, cpDataPointer* data);

static void PostStepRemove(cpSpace *space, cpShape *shape, void *unused);


//static void Stop(cpSpace *space, cpShape *shape, void *unused);






















//#pragma once
//#include "Box2D\Box2D.h"
//#include <stdio.h>
//#include "String.h"
//#include "window.h"
//#include "level.h"
//#include "actor.h"
//
//
//struct Hitbox
//{
//	b2Fixture* fixture;
//	char* name;
//};
//
//class Player : public Actor
//{
//public:
//
//	Player(Level* level, char* name);
//	bool onGround = false;
//
//	Hitbox hitboxes[10];
//
//	void PlayerMove();
//	void AddDynamicHitBox(Player* player);
//	void Jump();
//
//	void TakeDamage(Actor* actor);
//
//	bool IsGrounded();
//private:
//};