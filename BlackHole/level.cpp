#include "level.h"

Level::Level(Window* window, b2Vec2 gravity)
:window(window), gravity(gravity)
{
	b2level = new b2World(gravity);

	timeStep = 1.0f / 50.0f;

	velocityIterations = 6;
	positionIterations = 2;
	
}

void Level::Step()
{
	b2level->Step(timeStep, velocityIterations, positionIterations);
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
	SDL_DestroyTexture(texture);
}
