#include "window.h"

Window::Window()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		sdlWindow = SDL_CreateWindow("Black Hole", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (sdlWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
		}
	}


}

bool Window::Closed(){
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;

}

Window::~Window()
{
	//Destroy window
	SDL_DestroyWindow(sdlWindow);
	sdlWindow = NULL;

	SDL_DestroyRenderer(sdlRenderer);
	sdlRenderer = NULL;
	


	//Quit SDL subsystems
	SDL_Quit();
	IMG_Quit();


}
