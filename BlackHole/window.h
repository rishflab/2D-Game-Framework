#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>


class window
{
public:
	window();
	~window();

	void loadSprite();

	void updateSprites();

	bool closed();

	//Loads individual image as texture
	SDL_Texture* LoadTexture(char* path);

	void window::UpdateTextures(SDL_Texture* texture);

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	bool quit;

	//The window we'll be rendering to
	SDL_Window* sdlWindow = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* sprite = NULL;

	//The window renderer
	SDL_Renderer* sdlRenderer = NULL;

	//Current displayed texture
	SDL_Texture* texture = NULL;




	SDL_Event e;



};
