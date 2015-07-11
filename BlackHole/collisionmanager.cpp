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
	//Debug_PrintActors();
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

			if (actorA->name == "redActor")
			{
				printf("%s, % s\n", ((Player*)actorA)->name, actorB->name);

				for (b2Body* body = level->b2level->GetBodyList(); body; body = body->GetNext())
				{
					Actor* actor = ((Actor*)body->GetUserData());
					if (actor == actorB)
					{
						actorA->destroyable = true;
					}
				}
			}
			else if (actorB->name == "redActor")
			{
				printf("%s, % s\n", ((Player*)actorB)->name, actorA->name);

				for (b2Body* body = level->b2level->GetBodyList(); body; body = body->GetNext())
				{
					Actor* actor = ((Actor*)body->GetUserData());
					if (actor == actorA)
					{
						actor->destroyable = true;
					}
				}
			}
			else
			{
				//non player objects collided
			}
		}
	}


	b2Body* node = level->b2level->GetBodyList();
	while (node)
	{
		b2Body* b = node;
		node = node->GetNext();

		Actor* actor = (Actor*)b->GetUserData();
		
		if (actor->destroyable)
		{
			actor->DestroyBody();
			//level->b2level->DestroyBody(b);
			delete actor;

			Debug_PrintActors();
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
