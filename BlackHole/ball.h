#include "Box2D\Box2D.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "level.h"
#include "actor.h"

// class for ball which inherits from actor and is influenced by physics. In this class, unlike the actor, the x and y coordinates represent the centre
// of the Ball object.(Actors' x and y represent the top left of the Actor object.)
class Ball : public Actor
{
public:
	b2CircleShape playerBox;

	Ball::Ball(Level* level);
	void AddDynamicHitBox();
private:
};