#include <stdio.h>
#include "SDL.h"
#include "window.h"


#undef main

#define SHAPE_SIZE 50

bool quit = false;

SDL_Texture* jellyfishTexture = NULL;

//
//int main()
//{
//	printf("Game Started!\n");
//
//	window* gameWindow = new window();
//
//	jellyfishTexture = gameWindow->LoadTexture("sprites/jellyfish.png");
//
//
//
//	//While application is running
//	while (!gameWindow->closed())
//	{
//		gameWindow->UpdateTextures(jellyfishTexture);
//	}
//
//
//
//	delete gameWindow;
//	
//	
//
//	return 0;
//
//
//}	



int main(){

	SDL_Window* Main_Window;
	SDL_Renderer* Main_Renderer;
	SDL_Surface* Loading_Surf;
	SDL_Texture* Background_Tx;
	SDL_Texture* BlueShapes;

	/* Rectangles for drawing which will specify source (inside the texture)
	and target (on the screen) for rendering our textures. */
	SDL_Rect SrcR;
	SDL_Rect DestR;

	SrcR.x = 0;
	SrcR.y = 0;
	SrcR.w = SHAPE_SIZE;
	SrcR.h = SHAPE_SIZE;

	DestR.x = 640 / 2 - SHAPE_SIZE / 2;
	DestR.y = 480 / 2 - SHAPE_SIZE / 2;
	DestR.w = SHAPE_SIZE;
	DestR.h = SHAPE_SIZE;


	/* Before we can render anything, we need a window and a renderer */
	Main_Window = SDL_CreateWindow("SDL_RenderCopy Example",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	Main_Renderer = SDL_CreateRenderer(Main_Window, -1, SDL_RENDERER_ACCELERATED);



	Loading_Surf = IMG_Load("sprites/jellyfish.png");
	BlueShapes = SDL_CreateTextureFromSurface(Main_Renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);


	Loading_Surf = IMG_Load("sprites/background.png");
	Background_Tx = SDL_CreateTextureFromSurface(Main_Renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);  // we got the texture now -> free surface

	/* Load an additional texture */


	for (double i = 0.0; i < 10000.0; i++){

		SDL_RenderCopyEx(Main_Renderer, Background_Tx, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

		SDL_RenderCopyEx(Main_Renderer, BlueShapes, NULL, NULL, i, NULL, SDL_FLIP_NONE);

		SDL_RenderPresent(Main_Renderer);

		SDL_RenderClear(Main_Renderer);

		SDL_Delay(33);
	}



	SDL_DestroyTexture(BlueShapes);
	SDL_DestroyTexture(Background_Tx);
	SDL_DestroyRenderer(Main_Renderer);
	SDL_DestroyWindow(Main_Window);
	SDL_Quit();


	return 0;
}