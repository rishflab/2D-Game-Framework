#include "window.h"



window::window()
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
			//Create renderer for window
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
			if (sdlRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(sdlRenderer, 0x00, 0x00, 0x00, 0x00);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					
				}
			}

			////Get window surface
			//screenSurface = SDL_GetWindowSurface(sdlWindow);

			////Fill the surface white
			//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

			////Update the surface
			//SDL_UpdateWindowSurface(sdlWindow);

		}
	}


}

bool window::closed(){
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


}


void window::loadSprite(){


	bool success = true;

	//Load splash image

	sprite = IMG_Load("sprites/jellyfish.png");
	if (sprite == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}


}

SDL_Texture* window::LoadTexture(char* path){

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(sdlRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;

}

void window::updateSprites(){

	SDL_BlitSurface(sprite, NULL, screenSurface, NULL);

	//Update the surface
	SDL_UpdateWindowSurface(sdlWindow);


}

void window::UpdateTextures(SDL_Texture* texture){

	
	////Clear screen
	//SDL_SetRenderDrawColor(sdlRenderer, 0x00, 0x00, 0x00, 0x00);
	//SDL_RenderClear(sdlRenderer);

	////Render red filled quad
	//SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	//SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderFillRect(sdlRenderer, &fillRect);



	//Top left corner viewport
	SDL_Rect topLeftViewport;
	topLeftViewport.x = 0;
	topLeftViewport.y = 0;
	topLeftViewport.w = SCREEN_WIDTH / 2;
	topLeftViewport.h = SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport(sdlRenderer, &topLeftViewport);

	//Render texture to screen
	SDL_RenderCopy(sdlRenderer, texture, NULL, NULL);


	SDL_Rect bottomRightViewport;
	bottomRightViewport.x = SCREEN_WIDTH / 2;
	bottomRightViewport.y = SCREEN_WIDTH / 2;
	bottomRightViewport.w = SCREEN_WIDTH / 2;
	bottomRightViewport.h = SCREEN_HEIGHT / 2;
	SDL_RenderSetViewport(sdlRenderer, &bottomRightViewport);

	//Render texture to screen
	SDL_RenderCopy(sdlRenderer, texture, NULL, NULL);


	//Update screen
	SDL_RenderPresent(sdlRenderer);
	

}


window::~window()
{
	//Destroy window
	SDL_DestroyWindow(sdlWindow);
	sdlWindow = NULL;
	SDL_DestroyRenderer(sdlRenderer);
	sdlRenderer = NULL;
	SDL_DestroyTexture(texture);
	texture = NULL;

	

	//Deallocate surface
	SDL_FreeSurface(sprite);
	sprite = NULL;

	//Quit SDL subsystems
	SDL_Quit();
	IMG_Quit();


}
