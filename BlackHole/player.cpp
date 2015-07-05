#include "player.h"

Player::Player(Level* level, char* name)
: Actor(level, name)
{
	
}

void Player::AddDynamicHitBox(Player* player)
{

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);

	bodyDef.userData = player;

	bodyDef.fixedRotation = false;
	bodyDef.gravityScale = 0;
	body = level->b2level->CreateBody(&bodyDef);

	b2PolygonShape playerBox;
	b2FixtureDef fixtureDef;

	playerBox.SetAsBox(w / 2, h / 2, b2Vec2(0, 0), 0.0f);

	fixtureDef.shape = &playerBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	
	hitboxes[0].fixture = body->CreateFixture(&fixtureDef);
	hitboxes[0].name = "bodybox";

	b2PolygonShape footBox;
//2FixtureDef fixtureDef;

	playerBox.SetAsBox(w / 2, h / 2, b2Vec2(0, -1), 0.0f);

	fixtureDef.shape = &playerBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	hitboxes[1].fixture = body->CreateFixture(&fixtureDef);
	hitboxes[1].name = "footbox";




}

void Player::PlayerMove()
{

	b2Vec2 velocity(0.0f, -0.0f);
	this->body->SetLinearVelocity(velocity);
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_A])
	{
		b2Vec2 velocity(3.8f, 0.0f);
		this->body->SetLinearVelocity(velocity);
	}

	if (keyState[SDL_SCANCODE_D])
	{
		b2Vec2 velocity(-3.8f, 0.0f);
		this->body->SetLinearVelocity(velocity);
	}

	if (keyState[SDL_SCANCODE_W])
	{
		b2Vec2 velocity(0.0f, 3.8f);
		this->body->SetLinearVelocity(velocity);
	}	

	if (keyState[SDL_SCANCODE_S])
	{
		b2Vec2 velocity(0.0f, -3.8f);
		this->body->SetLinearVelocity(velocity);
	}
	/*if (keyState[SDL_SCANCODE_ESCAPE])
	{

	}*/
}

void Player::Jump()
{

}


void Player::TakeDamage(Actor* actor)
{
	printf("player took damage\n");
}
