#include "collisionmanager.h"


CollisionManager::CollisionManager(Level* level)
:level(level)
{
	
}

void CollisionManager::AddActor(Actor* actor)
{
	actorList.push_front(actor);
}


void CollisionManager::Update()
{


	for (b2Contact* contact = level->b2level->GetContactList();
		contact;
		contact = contact->GetNext())
	{
		if (contact->IsTouching()){

			//printf("collision occured!\n");

			//actorA = (Actor*)contact->GetFixtureA()->GetBody()->GetUserData();
			//actorB = (Actor*)contact->GetFixtureB()->GetBody()->GetUserData();

			char* actorBName = ((Actor*)contact->GetFixtureB()->GetBody()->GetUserData())->name;
			char* actorAName = ((Actor*)contact->GetFixtureA()->GetBody()->GetUserData())->name;
	

			//printf("%p %p\n", actorA, actorB);

			//printf("%s %s\n", actorA->name, actorB->name);

			if ((actorAName == "jelly") && (actorBName == "platform"))
			{
				printf("collision between jelly and platform occured!\n");
			}

			/*if (i == 1)
			{
				i = 0;
				printf("%p %p\n", actorA, actorB);

			}*/

		}
	}


}
