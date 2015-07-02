#include "ball.h"

Ball::Ball(Level* level)
: Actor(level)
{

}

void Ball::AddDynamicHitBox()
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	bodyDef.fixedRotation = false;

	body = level->b2level->CreateBody(&bodyDef);
	playerBox.m_p.Set(0.0f, 0.0f);
	playerBox.m_radius = 0.5f;

	fixtureDef.shape = &playerBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);
}

