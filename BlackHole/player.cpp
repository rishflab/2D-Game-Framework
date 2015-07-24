#include "player.h"
bool bottom = false;
Player::Player(Level* level, char* name)
:level(level), name(name)
{
	cpFloat mass = 1.0f;
	w = 1.0f;
	h = 1.0f;

	cpFloat x = 0.0f;
	cpFloat y = -1.0f;

	cpVect move = cpv(x, y);

	cpFloat moment = cpMomentForBox(mass, w, h);

	body = cpSpaceAddBody(level->space, cpBodyNew(mass, moment));
	cpBodySetPosition(body, cpv(-2.0f, 4.0f));
	//cpBodySetImpluse(body, move);
	
	cpVect verts[] = { cpv(0.5f, 0.0f), cpv(-0.5f, 0.0f), cpv(-0.5f, -1.0f), cpv(0.5f, -1.0f) };

	shape = cpSpaceAddShape(level->space, cpPolyShapeNewRaw(body, 4, verts, 0.0f));
	cpShapeSetSensor(shape, true);
	cpShapeSetUserData(shape, this);
	// to counter gravity
	//cpBodySetVelocity(body, cpv(0.0f, 10.0f));
	cpShapeSetElasticity(shape, 1.0f);
	cpShapeSetFriction(shape, 1.0f);
	cpBodySetAngle(body, 0.0f);
	cpShapeSetCollisionType(shape, PLAYER_TYPE);

	cpVect footVerts[] = { cpv(0.5f, -0.9f), cpv(-0.5f, -0.9f), cpv(-0.5f, -1.0f), cpv(0.5f, -1.0f) };
	//foot = cpSegmentShapeAlloc();
	//foot = cpSegmentShapeInit(foot, body, cpv(-0.4f, -0.9f), cpv(0.4f, -0.9f), 1.0f);
	//foot = cpSpaceAddShape(level->space, cpPolyShapeNewRaw(body, 4, footVerts, 0.0f));
	foot = cpSpaceAddShape(level->space, cpSegmentShapeNew(body, cpv(-0.4f, -1.0f), cpv(0.4f, -1.0f), 0.01f));
	//foot = cpPolyShapeNewRaw(body, 4, footVerts, 0.0f);
	//cpSegmentShapeInit
	cpShapeSetSensor(foot, true);

	cpShapeSetCollisionType(foot, PLAYER_FOOT_TYPE);

	handler = cpSpaceAddCollisionHandler(level->space, 3, 2);

	handler->beginFunc = (cpCollisionBeginFunc)Begin;
	
	//cpBodySetVelocity(body, move);
	//cpBodySetForce(body, move);
	//cpShapeSetSurfaceVelocity(shape, move);
}

void Player::RenderActor()
{
	SDL_Surface* surface;
	SDL_Texture* texture;

	// loads image sources
	surface = IMG_Load("sprites/red.png");
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

void Player::PlayerMove(){

	cpBodySetVelocity(body, cpv(0.0f, 0.0f));

	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_A]){
		cpBodySetVelocity(body, cpv(1.0f, ((cpVect)cpBodyGetVelocity(body)).y));
	}
	if (keyState[SDL_SCANCODE_D]){
		//cpBodyApplyImpulseAtLocalPoint(body, cpv(0.0f, -1.0f), cpv(0.0f, 0.0f));
		cpBodySetVelocity(body, cpv(-1.0f, ((cpVect)cpBodyGetVelocity(body)).y));
	}
	if (keyState[SDL_SCANCODE_W]){
		cpBodySetVelocity(body, cpv(((cpVect)cpBodyGetVelocity(body)).x, 1.0f));
	}
	if (keyState[SDL_SCANCODE_S] && bottom == false){
		cpBodySetVelocity(body, cpv(((cpVect)cpBodyGetVelocity(body)).x, -1.0f));
	}

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

	cpBodySetVelocity((((Player*)cpShapeGetUserData(a))->body), cpv(0.0f, 0.0f));
	cpBodySetVelocity((((Player*)cpShapeGetUserData(b))->body), cpv(0.0f, 0.0f));

	bottom = true;

	//std::cout << cpShapeGetUserData(a) << std::endl;
	//if (((Player*)cpShapeGetUserData(a))->collisionID == PLAYER_FOOT_TYPE)
	//{
	//	cpBodySetVelocity((((Player*)cpShapeGetUserData(a))->body) ,cpv(0.0f, 0.0f));
	//}
	//else  if (((Player*)cpShapeGetUserData(b))->collisionID == PLAYER_FOOT_TYPE)
	//{
	//	cpBodySetVelocity((((Player*)cpShapeGetUserData(b))->body), cpv(0.0f, 0.0f));
	//}

	//std::cout << "ball bounced on platform" << std::endl;

	//// The object is dead, don’t process the collision further
	return 1;


}
//
//void Stop(cpSpace *space, cpShape *shape, void *unused)
//{
//	
//}



//#include "player.h"
//
//Player::Player(Level* level, char* name)
//: Actor(level, name)
//{
//	
//}
//
//void Player::AddDynamicHitBox(Player* player)
//{
//
//	bodyDef.type = b2_dynamicBody;
//	bodyDef.position.Set(x, y);
//
//	bodyDef.userData = player;
//
//	bodyDef.fixedRotation = false;
//	bodyDef.gravityScale = 0;
//	body = level->b2level->CreateBody(&bodyDef);
//
//	b2PolygonShape playerBox;
//	b2FixtureDef fixtureDef;
//
//	playerBox.SetAsBox(w / 2, h / 2, b2Vec2(0, 0), 0.0f);
//
//	fixtureDef.shape = &playerBox;
//	fixtureDef.density = 1.0f;
//	fixtureDef.friction = 0.3f;
//	
//	hitboxes[0].fixture = body->CreateFixture(&fixtureDef);
//	hitboxes[0].name = "bodybox";
//
//	b2PolygonShape footBox;
////2FixtureDef fixtureDef;
//
//	playerBox.SetAsBox(w / 2, h / 2, b2Vec2(0, -1), 0.0f);
//
//	fixtureDef.shape = &playerBox;
//	fixtureDef.density = 1.0f;
//	fixtureDef.friction = 0.3f;
//
//	hitboxes[1].fixture = body->CreateFixture(&fixtureDef);
//	hitboxes[1].name = "footbox";
//
//
//
//
//}
//
//void Player::PlayerMove()
//{
//
//	b2Vec2 velocity(0.0f, -0.0f);
//	this->body->SetLinearVelocity(velocity);
//	const Uint8* keyState = SDL_GetKeyboardState(NULL);
//
//	if (keyState[SDL_SCANCODE_A])
//	{
//		b2Vec2 velocity(3.8f, 0.0f);
//		this->body->SetLinearVelocity(velocity);
//	}
//
//	if (keyState[SDL_SCANCODE_D])
//	{
//		b2Vec2 velocity(-3.8f, 0.0f);
//		this->body->SetLinearVelocity(velocity);
//	}
//
//	if (keyState[SDL_SCANCODE_W])
//	{
//		b2Vec2 velocity(0.0f, 3.8f);
//		this->body->SetLinearVelocity(velocity);
//	}	
//
//	if (keyState[SDL_SCANCODE_S])
//	{
//		b2Vec2 velocity(0.0f, -3.8f);
//		this->body->SetLinearVelocity(velocity);
//	}
//	/*if (keyState[SDL_SCANCODE_ESCAPE])
//	{
//
//	}*/
//}
//
//void Player::Jump()
//{
//
//}
//
//
//void Player::TakeDamage(Actor* actor)
//{
//	printf("player took damage\n");
//}
