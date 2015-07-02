#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Box2D\Box2D.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "level.h"

class Actor
{
public:
	//actor physics variables
	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape playerBox;
	b2FixtureDef fixtureDef;
	//actor transform variables
	float32 x; // x and y represent the top left of the actor object. 
	float32 y;
	float32 w;
	float32 h;
	float32 angle;

	Level* level;

	Actor(Level* level);
	void RenderActor(char* filePath);
	void SetTransform(float32 x, float32 y);
	void SetSize(float32 w, float32 h);
	void AddHitBox();
	void AddDynamicHitBox();
	void UpdatePosition();

private:
	
};