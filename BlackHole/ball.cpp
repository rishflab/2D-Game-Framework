#include "ball.h"

Ball::Ball(Level* level, char* name)
	//:Actor(level, name)
:level(level), name(name)
{
	cpFloat radius = 1.0f;
	cpFloat mass = 1.0f;

	// The moment of inertia is like mass for rotation
	// Use the cpMomentFor*() functions to help you approximate it.
	cpFloat moment = cpMomentForCircle(mass, 0, radius, cpvzero);

	// The cpSpaceAdd*() functions return the thing that you are adding.
	// It's convenient to create and add an object in one line.
	body = cpSpaceAddBody(level->space, cpBodyNew(mass, moment));
	cpBodySetPosition(body, cpv(0.0f, -4.0f));


	// Now we create the collision shape for the ball.
	// You can create multiple collision shapes that point to the same body.
	// They will all be attached to the body and move around to follow it.
	shape = cpSpaceAddShape(level->space, cpCircleShapeNew(body, radius, cpvzero));
	cpShapeSetUserData(shape, this);
	std::cout << this << std::endl;
	cpShapeSetFriction(shape, 0.7);
	cpShapeSetElasticity(shape, 0.8f);
	cpShapeSetCollisionType(shape, BALL_TYPE);
	//cpBodyApplyImpulseAtLocalPoint(body, cpv(1.0f, 0.0f), cpv(0.0f, 0.0f));

	w = radius;
	h = radius;


	//handler = cpSpaceAddCollisionHandler(level->space, 1, 2);

	//handler->beginFunc = (cpCollisionBeginFunc)Begin;
	

}



void Ball::RenderActor()
{

	SDL_Surface* surface;
	SDL_Texture* texture;


	// loads image sources
	surface = IMG_Load("sprites/ball.png");

	
	//SDL_Renderer* renderer = level->window->sdlRenderer;
	texture = SDL_CreateTextureFromSurface(level->window->sdlRenderer, surface);
	SDL_FreeSurface(surface);

	// 60 pixel in each metre

	SDL_Rect rect;

	cpFloat scale = floor(this->level->window->SCREEN_HEIGHT / this->level->LEVEL_HEIGHT);
	rect.x = floor((this->level->window->SCREEN_WIDTH / 2) - ((cpBodyGetPosition(body)).x * scale)) - (scale*this->w / 2);
	rect.y = ceil((this->level->window->SCREEN_HEIGHT / 2) - ((cpBodyGetPosition(body)).y * scale)) - (scale*this->h / 2);
	rect.w = floor(this->w * scale);
	rect.h = floor(this->h * scale);

	//printf("%f %f \n", this->w, rect.y);

	SDL_RenderCopyEx(level->window->sdlRenderer, texture, NULL, &rect, ceil((cpBodyGetAngle(body) / CP_PI)*180.0f), NULL, SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);

}


void PostStepRemove(cpSpace *space, cpShape *shape, void *unused) 
{

	((Actor*)cpShapeGetUserData(shape))->destroyable = true;

	cpSpaceRemoveShape(space, shape);
	cpSpaceRemoveBody(space, cpShapeGetBody(shape));

	cpBodyFree(cpShapeGetBody(shape));
	cpShapeFree(shape);

	//std::cout << cpShapeGetUserData(shape) << std::endl;



	
	
	
	
}


cpBool Begin(cpArbiter *arb, cpSpace *space, cpDataPointer* data) 
{
	// Get the cpShapes involved in the collision
	// The order will be the same as you defined in the handler definition
	// a->collision_type will be BULLET_TYPE and b->collision_type will be MONSTER_TYPE
	CP_ARBITER_GET_SHAPES(arb, a, b);



	std::cout << cpShapeGetCollisionType(a) << ", " << cpShapeGetCollisionType(b) << std::endl;
	// The macro expands exactly as if you had typed this:
	// cpShape *a, *b; cpArbiterGetShapes(arb, &a, &b);
	
	// Add a post step callback to safely remove the body and shape from the space.
	// Calling cpSpaceRemove*() directly from a collision handler callback can cause crashes.
	
	//
	//std::cout << data << std::endl;
	//if (*(cpCollisionType*)(cpShapeGetUserData(a)) == BALL_TYPE)
	//{
	//	cpSpaceAddPostStepCallback(space, (cpPostStepFunc)PostStepRemove, a, NULL);
	//}
	//else  if (*(cpCollisionType*)(cpShapeGetUserData(b)) == BALL_TYPE)
	//{
	//	cpSpaceAddPostStepCallback(space, (cpPostStepFunc)PostStepRemove, b, NULL);
	//}
	
	std::cout << cpShapeGetUserData(a) << std::endl;
	if (((Ball*)cpShapeGetUserData(a))->collisionID == BALL_TYPE)
	{
		cpSpaceAddPostStepCallback(space, (cpPostStepFunc)PostStepRemove, a, NULL);
	}
	else  if (((Ball*)cpShapeGetUserData(b))->collisionID == BALL_TYPE)
	{
		cpSpaceAddPostStepCallback(space, (cpPostStepFunc)PostStepRemove, b, NULL);
	}

	std::cout << "ball bounced on platform" << std::endl;

	// The object is dead, don’t process the collision further
	return 1;

	
}

void Ball::DestroyBody()
{
	cpSpaceRemoveShape(level->space, shape);
	cpSpaceRemoveBody(level->space, cpShapeGetBody(shape));

	cpBodyFree(cpShapeGetBody(shape));
	cpShapeFree(shape);
}
