#include "actor.h"

Actor::Actor(Level* level)
:level(level)
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

	SDL_RenderCopyEx(this->level->window->sdlRenderer, texture, NULL, &rect, ceil((this->angle/b2_pi)*180.0f), NULL, SDL_FLIP_NONE);



	
}

void Actor::AddHitBox()
{

	
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
	
	body = level->b2level->CreateBody(&bodyDef);
	
	playerBox.SetAsBox(w/2, h/2);
	
	fixtureDef.shape = &playerBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	
	body->CreateFixture(&fixtureDef);
	
}

void Actor::AddDynamicHitBox()
{

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
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
	b2Vec2 movement = this->body->GetPosition();
	float32 angle = this->body->GetAngle();

	this->body->SetTransform(movement, angle);
	this->SetTransform(movement.x, movement.y);
	this->angle = angle;
}