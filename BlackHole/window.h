#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdio.h>

class Window
{
public:
	Uint32 SCREEN_WIDTH = 1280;
	Uint32 SCREEN_HEIGHT = 720;
	bool quit;
	//The window we'll be rendering to
	SDL_Window* sdlWindow = NULL;
	SDL_Renderer* sdlRenderer = NULL;
	SDL_Event e;

	Window();
	~Window();
	bool Closed();
private:
};
