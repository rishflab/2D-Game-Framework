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

			Actor* actorA = (Actor*)contact->GetFixtureA()->GetBody()->GetUserData();
			Actor* actorB= (Actor*)contact->GetFixtureB()->GetBody()->GetUserData();
		
			//player->TakeDamage(actorB);

			//printf("%s, % s\n", actorA->name, actorB->name);
	


			if (actorA->name == "bluePlayer")
			{


				printf("%s, % s\n", ((Player*)actorA)->hitboxes[1].name  , actorB->name);

				for (b2Body* body = level->b2level->GetBodyList(); body; body = body->GetNext())
				{
					Actor* actor = ((Actor*)body->GetUserData());
					if (actor == actorB)
					{
						((Player*)actorA)->TakeDamage(actorB);
					}				
				}	
			}
			else if (actorB->name == "bluePlayer")
			{
				printf("%s, % s\n", ((Player*)actorB)->hitboxes[1].name, actorA->name);
			
				for (b2Body* body = level->b2level->GetBodyList(); body; body = body->GetNext())
				{
					Actor* actor = ((Actor*)body->GetUserData());
					if (actor == actorA)
					{
						((Player*)actorB)->TakeDamage(actorA);
					}
				}
			}
			else
			{
				//non player objects collided
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
