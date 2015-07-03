#include "collisionmanager.h"


CollisionManager::CollisionManager(Level* level)
:level(level)
{
	
}

void CollisionManager::AddActor(Actor* actor)
{
	
}


void CollisionManager::Update()
{
	for (b2Contact* contact = level->b2level->GetContactList();
		contact;
		contact = contact->GetNext())
	{
		if (contact->IsTouching()){


			char* actorBName = ((Actor*)contact->GetFixtureB()->GetBody()->GetUserData())->name;
			char* actorAName = ((Actor*)contact->GetFixtureA()->GetBody()->GetUserData())->name;

			//Player* playerA = (Actor*)contact->GetFixtureA()->GetBody()->GetUserData();
			//Actor* actorB = (Actor*)contact->GetFixtureB()->GetBody()->GetUserData();

			//player->TakeDamage(actorB);

			//printf("%s, % s\n", actorAName, actorBName);


			if (actorAName == "player")
			{

			}
			else if (actorBName == "player")
			{

			}
			else
			{
				//non player objects collided
			}


			for (b2Body* b = level->b2level->GetBodyList(); b; b = b->GetNext())
			{
				Actor* actorA = ((Actor*)b->GetUserData());

				//printf("%s \n", bodyName->name);
			}

	



			/*if (i == 1)
			{
				i = 0;
				printf("%p %p\n", actorA, actorB);

			}*/

		}
	}
}


void CollisionManager::Debug_PrintActors()
{

	for (b2Body* b = level->b2level->GetBodyList(); b; b = b->GetNext())
	{
		Actor* bodyName = ((Actor*)b->GetUserData());

		printf("%s \n", bodyName->name);
	}
	
}

