#include "platform.h"

Platform::Platform(Level* level, char* name)
	:level(level), name(name)
	//:Actor(level, name)
{
	//body = cpSpaceGetStaticBody(level->space);

	//body = cpBodyNew();
	
	body = cpSpaceAddBody(level->space, cpBodyNewStatic());
	cpBodySetPosition(body, cpv(0.0f, 0.0f));

	// Create segments around the edge of the screen.

	//cpVect platform[] = { cpv(-5.0f, 0.5f), cpv(5.0f, 0.5f), cpv(5.0f, -0.5f), cpv(5.0f, -0.5f) };

	cpVect platform[] = { cpv(-5.0f, 0.0f), cpv(5.0f, 0.0f), cpv(5.0f, -1.0f), cpv(5.0f, -1.0f) };

	//cpSegmentShape* cpSegmentShapeAlloc(void);
	//cpSegmentShape* cpSegmentShapeInit(cpSegmentShape *seg, cpBody *body, cpVect a, cpVect b, cpFloat radius);
	//cpShape* cpSegmentShapeNew(cpBody *body, cpVect a, cpVect b, cpFloat radius)

	//shape = cpSpaceAddShape(level->space, cpSegmentShapeNew(body, cpv(-5.0f, 0.0f), cpv(5.0f, 0.0f), 0.0f));
	shape = cpSpaceAddShape(level->space, cpPolyShapeNewRaw(body, 4, platform , 0.0f));

	cpShapeSetUserData(shape, this);

	cpShapeSetElasticity(shape, 1.0f);
	cpShapeSetFriction(shape, 1.0f);
	cpShapeSetCollisionType(shape, PLATFORM_TYPE);

	w = 10.0f;
	h = 1.0f;
}


void Platform::RenderActor()
{

	SDL_Surface* surface;
	SDL_Texture* texture;


	// loads image sources
	surface = IMG_Load("sprites/blue.png");
	texture = SDL_CreateTextureFromSurface(level->window->sdlRenderer, surface);
	

	SDL_FreeSurface(surface);

	// 60 pixel in each metre

	SDL_Rect rect;

	cpFloat scale = floor(this->level->window->SCREEN_HEIGHT / this->level->LEVEL_HEIGHT);
	rect.x = floor((this->level->window->SCREEN_WIDTH / 2) - ((cpBodyGetPosition(body)).x * scale)) - (scale*this->w / 2);
	rect.y = ceil((this->level->window->SCREEN_HEIGHT / 2) - ((cpBodyGetPosition(body)).y * scale)) - (scale*this->h / 2);
	//printf("y = %f \n", cpBodyGetPosition(body).y);
	rect.w = floor(this->w * scale);
	rect.h = floor(this->h * scale);

	//printf("%f %f \n", this->w, rect.y);

	SDL_RenderCopyEx(level->window->sdlRenderer, texture, NULL, &rect, ceil((cpBodyGetAngle(body) / CP_PI)*180.0f), NULL, SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);

}


