#include "level.h"

#include "actor.h"


Level::Level(Window* window, b2Vec2 gravity)
:window(window), gravity(gravity)
{
	b2level = new b2World(gravity);
	

}



void Level::RenderLevel(char* filePath)
{

	SDL_Surface* surface;
	SDL_Texture* texture;

	// loads image sources
	surface = IMG_Load(filePath);
	texture = SDL_CreateTextureFromSurface(window->sdlRenderer, surface);
	SDL_FreeSurface(surface);

	SDL_RenderCopyEx(window->sdlRenderer, texture, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

	// loads in the renderer
	//SDL_RenderPresent(window->sdlRenderer);

	//SDL_RenderClear(window->sdlRenderer);


}
//
//Level::~Level(){
//	delete b2level;
//}