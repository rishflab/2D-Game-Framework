#include "actor.h"

//Actor::Actor(Level* level, char* name)
//:level(level), name(name)
//{
//	
//
//}


Actor::Actor(Level* level, char* name)
	:level(level), name(name)
{



}

Actor::~Actor()
{
}






//
//void Actor::DestroyBody()
//
//{
//	level->b2level->DestroyBody(body);
//
//	//b2Body* node = level->b2level->GetBodyList();
//	//while (node)
//	//{
//	//	b2Body* b = node;
//	//	node = node->GetNext();
//
//	//	Actor* actor = (Actor*)b->GetUserData();
//	//	
//	//	b->DestroyFixture(b2fixture);;
//	//	level->b2level->DestroyBody(b);
//
//	//}
//}
