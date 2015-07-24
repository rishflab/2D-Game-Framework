#include "level.h"


Level::Level(Window* window, cpVect gravity)
	:window(window)
{

	
	space = cpSpaceNew();
	cpSpaceSetGravity(space, gravity);
	cpSpaceSetIterations(space, 100);

	
	actorVec.reserve(10);
	
}

void Level::RenderLevel()
{
	std::vector<Actor*>::const_iterator i;
	for (i = actorVec.begin(); i != actorVec.end(); ++i)
	{
		if ((Actor*)(*i) != NULL)
		{
			((Actor*)(*i))->RenderActor();
		}
	}
}

void Level::AddActor(Actor* actor)
{
	//actorVec.resize(actorVec.capacity() + 1);
	actorVec.push_back(actor);	
}

void Level::CleanUpActors()
{

	std::vector<Actor*>::const_iterator i;
	//Uint32 j = 0;

	for (i = actorVec.begin(); i != actorVec.end(); ++i)
	{
		//j++;
	
			if ((*i)->destroyable == true)
			{
				actorVec.erase(i);
				break;
			}
		}

	

	//actorVec.resize(actorVec.capacity() - 1);

}

void Level::DeleteActor(Actor* actor)
{

	std::vector<Actor*>::const_iterator i;
	//Uint32 j = 0;

	for (i = actorVec.begin(); i != actorVec.end(); ++i)
	{
		//j++;

		if (actor == *i)
		{
			if (actor->destroyable == true)
			{
				actorVec.erase(i);
				break;
			}
		}
		
	}

	actorVec.resize(actorVec.capacity() - 1);
	//actorVec.erase(1);
}

//void Level::DestroyActor(Actor* actor)
//{
//	b2Body* next = NULL;
//
//	//actor->body->GetNext();
//
//	//next = actor->body->GetNext();
//
//	//commented out because fixtures are automatically destroyed when parent body is destroyed
//	//b->DestroyFixture(b->GetFixtureList());
//	DestroyBody((b2Body*)actor);
//	delete actor;
//	//Actor* actor = (Actor*)b->GetUserData();
//
//	//b->DestroyFixture(actor->b2fixture);
//	//b2level->DestroyBody(b);
//}
