#include <stdio.h>
#include "SDL/SDL.h"
#include "Box2d/Box2D.h"
#include "window.h"
#include "level.h"
#include "actor.h"
#include <math.h>
#include "collisionmanager.h"
#include "player.h"
#include "ball.h"
#include "platform.h"
#include <iostream>
#include <fstream>
#include "Chipmunk\chipmunk.h"


#undef main

Uint32 Tick(Uint32 interval, void* param);

bool quit = false;

SDL_Event e;

Window* gameWindow = new Window();

cpVect gravity = cpv(0.0f, -0.0f);

Level* level = new Level(gameWindow, gravity);

Ball* ball = new Ball(level, "ball");

Player* player = new Player(level, "player");

cpFloat x = 0.0f;
cpFloat y = 1.0f;

cpVect move = cpv(x, y);

Platform* platform = new Platform(level, "platform");

SDL_Event event;

//cpFloat timeStep = 1.0 / 10.0;
Uint32 time = SDL_GetTicks();

Uint32 oldTime = 0;

Uint32 interval = 5;  /* 20 ms */
SDL_TimerID timer;

int k = 0;

std::ofstream myfile;



Uint32 Tick(Uint32 interval,  void* param)
{
	
	oldTime = time;
	time = SDL_GetTicks();
	printf("ticks : %d, deltaTime: %d\n", time, time - oldTime);
	cpSpaceStep(level->space, (time - oldTime) / 1000.0f);
	player->PlayerMove();
	level->CleanUpActors();
	
	SDL_UserEvent userevent;


	/* In this example, our callback pushes an SDL_USEREVENT event
	into the queue, and causes our callback to be called again at the
	same interval: */

	userevent.type = SDL_USEREVENT;
	userevent.code = 0;
	userevent.data1 = NULL;
	userevent.data2 = NULL;

	k++;

	//printf("tick: %d\n", k);


	
	//printf("time: %d\n", deltaTime);
	
	//cpSpaceStep(level->space, 1.0f/25.0f);



	//handler->beginFunc()

	cpVect pos = cpBodyGetPosition(ball->body);
	cpVect vel = cpBodyGetVelocity(ball->body);

	//myfile << "time: " << time << ", vel: " << vel.y<< "\n";

	//printf("ballBody is at (%5.2f, %5.2f). It's velocity is (%5.2f, %5.2f)\n", pos.x, pos.y, vel.x, vel.y);
	//printf("ballBody is at (%5.2f, %5.2f). It's velocity is (%5.2f, %5.2f)\n", pos.x, pos.y, vel.x, vel.y);

	//->RenderActor("sprites/blue.png");

	//ball->RenderActor();
	//////// loads in the renderer

	level->RenderLevel();
	SDL_RenderPresent(level->window->sdlRenderer);

	SDL_RenderClear(level->window->sdlRenderer);

	
	

	////// checks if close button has been pressed and exits if so

	event.type = SDL_USEREVENT;
	event.user = userevent;
	SDL_PushEvent(&event);

	return(interval);
}



int main(){

	level->AddActor(platform);
	level->AddActor(ball);
	level->AddActor(player);


	//cpBodySetVelocity(player->body, move);

	//cpBodySetForce(player->body, move);
	//cpShapeSetSurfaceVelocity(player->shape, move);

	std::cout << ball << std::endl;
	std::cout << platform << std::endl;
	std::cout << std::endl;

	std::vector<Actor*>::const_iterator i;
	for (i = level->actorVec.begin(); i != level->actorVec.end(); ++i)
	{
		std::cout << (*i) << std::endl;

	}

	


	//std::cout << cpShapeGetUserData(ball->shape) << std::endl;
	//handler->postSolveFunc = (cpCollisionPostSolveFunc)PostStepRemove;

	myfile.open("example.txt");
	timer = SDL_AddTimer(interval, Tick, NULL);

	while (1)
	{
		SDL_PollEvent(&event);



		if (event.type == SDL_QUIT)
		{
			break;
		}

	}

	//cpShapeFree(ball->ballShape);
	//cpBodyFree(ball->ballBody);
	//cpShapeFree(ground);
	//cpSpaceFree(level->space);

	//delete(jelly);
	//delete(level);
	//delete(gameWindow);

	myfile.close();
}

