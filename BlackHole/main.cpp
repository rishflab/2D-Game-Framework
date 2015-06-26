#include <stdio.h>
#include "SDL.h"
#include "window.h"


#undef main



bool quit = false;

SDL_Texture* jellyfishTexture = NULL;


int main()
{
	printf("Game Started!\n");

	window* gameWindow = new window();

	jellyfishTexture = gameWindow->LoadTexture("sprites/jellyfish.png");



	//While application is running
	while (!gameWindow->closed())
	{
		gameWindow->UpdateTextures(jellyfishTexture);
	}



	delete gameWindow;
	
	

	return 0;


}	