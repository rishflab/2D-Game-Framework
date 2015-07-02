#include "player.h"

Player::Player(Level* level, char* name)
: Actor(level, name)
{
	
}

void Player::AddDynamicHitBox(Player* player)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	bodyDef.fixedRotation = true;
	bodyDef.userData = player;

	body = level->b2level->CreateBody(&bodyDef);
	body->SetGravityScale(0);
	playerBox.SetAsBox(w / 2, h / 2);

	fixtureDef.shape = &playerBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);

}

void Player::PlayerMove()
{

	b2Vec2 velocity(0.0f, -0.0f);
	this->body->SetLinearVelocity(velocity);
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	if (keyState[SDL_SCANCODE_A])
	{
		b2Vec2 velocity(0.8f, 0.0f);
		this->body->SetLinearVelocity(velocity);
	}

	if (keyState[SDL_SCANCODE_D])
	{
		b2Vec2 velocity(-0.8f, 0.0f);
		this->body->SetLinearVelocity(velocity);
	}

	if (keyState[SDL_SCANCODE_W])
	{
		b2Vec2 velocity(0.0f, 0.8f);
		this->body->SetLinearVelocity(velocity);
	}	

	if (keyState[SDL_SCANCODE_S])
	{
		b2Vec2 velocity(0.0f, -0.8f);
		this->body->SetLinearVelocity(velocity);
	}
	if (keyState[SDL_SCANCODE_ESCAPE])
	{

	}
}

void Player::Jump()
{

}
