#include "player.h"

Player::Player(Level* level)
: Actor(level)
{

}

void Player::PlayerMove()
{
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
