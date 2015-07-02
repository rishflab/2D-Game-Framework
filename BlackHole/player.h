#include "Box2D\Box2D.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "level.h"
#include "actor.h"

class Player : public Actor
{
public:
	bool onGround;

	Player(Level* level);
	void PlayerMove();
	void AddDynamicHitBox();
	void Jump();

	bool IsGrounded();
private:
	
};