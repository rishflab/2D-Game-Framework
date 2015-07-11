#pragma once
#include "level.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Box2D\Box2D.h"
#include <stdio.h>
#include "String.h"
#include "window.h"


class Level;

class Actor
{
public:

	Level* level;

	Actor(Level* level, char* name);
	void RenderActor(char* filePath);
	void SetTransform(float32 x, float32 y);
	void SetSize(float32 w, float32 h);
	void UpdatePosition();
	void AddHitBox(Actor* actor);
	void AddDynamicHitBox(Actor* actor);
	void DestroyBody();

	char* name;

	//actor physics variables
	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape playerBox;
	b2FixtureDef fixtureDef;
	b2Fixture* b2fixture;

	//actor transform variables
	float32 x; 
	float32 y;
	float32 w;
	float32 h;
	float32 angle;

	bool destroyable = false;


private:
	
};