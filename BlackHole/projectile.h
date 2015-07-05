#pragma once
#include "Box2D\Box2D.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "level.h"
#include "actor.h"

class Projectile : public Actor
{
public:

	Projectile(Level* level, char* name);

	void AddDynamicHitBox(Projectile* player);

	void Fire(b2Vec2 velocity);
	
	
private:
};