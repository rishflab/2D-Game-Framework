#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "Chipmunk\chipmunk.h"
#include "actor.h"
#include "level.h"




class Renderer
{
public:

	
	Window* window;
	Level* level;

	
	Renderer(Window* window, Level level);

	void RenderLevel(char* filePath);

private:


};