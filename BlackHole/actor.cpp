#include "actor.h"


Actor::Actor(Level* level)
:level(level)
{
	
}

void Actor::SetTransform(Uint32 x, Uint32 y)
{
	this->x = x;
	this->y = y;
}

void Actor::SetSize(Uint32 w, Uint32 h)
{
	this->w = w;
	this->h = h;
}

void Actor::RenderActor(char* filePath)
{
	
	SDL_Surface* surface;
	SDL_Texture* texture;

	// loads image sources
	surface = IMG_Load(filePath);
	texture = SDL_CreateTextureFromSurface(this->level->window->sdlRenderer, surface);
	SDL_FreeSurface(surface);

	// 60 pixel in each metre

	SDL_Rect rect;

	
	Uint32 scale = floor(this->level->window->SCREEN_HEIGHT / this->level->LEVEL_HEIGHT);
	rect.x = floor((this->level->window->SCREEN_WIDTH / 2) - (this->x * scale)) - (scale*this->w/2);
	rect.y = floor((this->level->window->SCREEN_HEIGHT / 2) - (this->y * scale)) - (scale*this->h/2);
	rect.w = this->w * scale;
	rect.h = this->h * scale;

	printf("%d %d \n", this->w, rect.y);

	SDL_RenderCopyEx(this->level->window->sdlRenderer, texture, NULL, &rect, this->angle, NULL, SDL_FLIP_NONE);

	// loads in the renderer
	SDL_RenderPresent(this->level->window->sdlRenderer);

	SDL_RenderClear(this->level->window->sdlRenderer);

	
}