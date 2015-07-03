#include "actor.h"

Actor::Actor(Level* level, char* name)
:level(level), name(name)
{
	
}

void Actor::SetTransform(float32 x, float32 y)
{
	this->x = x;
	this->y = y;
}

void Actor::SetSize(float32 w, float32 h)
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

	
	float32 scale = floor(this->level->window->SCREEN_HEIGHT / this->level->LEVEL_HEIGHT);
	rect.x = floor((this->level->window->SCREEN_WIDTH / 2) - (this->x * scale)) - (scale*this->w/2);
	rect.y = ceil((this->level->window->SCREEN_HEIGHT / 2) - (this->y * scale)) - (scale*this->h/2);
	rect.w = floor(this->w * scale);
	rect.h = floor(this->h * scale);

	//printf("%f %f \n", this->w, rect.y);

	SDL_RenderCopyEx(this->level->window->sdlRenderer, texture, NULL, &rect, ceil((this->angle / b2_pi)*180.0f), NULL, SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);

}

void Actor::AddHitBox(Actor* actor)
{
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.userData = actor;
	
	body = level->b2level->CreateBody(&bodyDef);
	
	playerBox.SetAsBox(w/2, h/2);
	
	fixtureDef.shape = &playerBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	
	body->CreateFixture(&fixtureDef);
}


void Actor::AddDynamicHitBox(Actor* actor)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);

	bodyDef.userData = actor;

	bodyDef.fixedRotation = false;

	body = level->b2level->CreateBody(&bodyDef);
	playerBox.SetAsBox(w/2, h/2);

	fixtureDef.shape = &playerBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);

}

void Actor::UpdatePosition()
{
	x = body->GetPosition().x;
	y = body->GetPosition().y;
	angle = body->GetAngle();
}

//void Actor::RespondToCollision(Actor* actorA, Actor* actorB)
//{
//	if (actorA->name == )
//}

