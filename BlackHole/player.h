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

	Player(Level* level, char* name);

	void PlayerMove();
	void AddDynamicHitBox(Player* player);
	void Jump();

	bool IsGrounded();
private:
	
};