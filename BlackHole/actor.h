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

	Actor(Level* level);

	void RenderActor(char* filePath);

	void SetTransform(Uint32 x, Uint32 y);
	void SetSize(Uint32 w, Uint32 h);


	Uint32 x;
	Uint32 y;
	Uint32 w;
	Uint32 h;
	float32 angle;


private:

	Level* level;
};