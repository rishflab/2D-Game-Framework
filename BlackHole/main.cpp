#include <stdio.h>
#include "SDL/SDL.h"
#include "Box2d/Box2D.h"
#include "window.h"
#include <math.h>


#undef main

#define SHAPE_SIZE 50

bool quit = false;

SDL_Texture* jellyfishTexture = NULL;

//b2ContactListener
// Called when two fixtures begin to touch
void BeginContact(b2Contact* contact);

// Called when two fixtures cease to touch
void EndContact(b2Contact* contact);

//b2Contact
// Get the first fixture in this contact
b2Fixture* GetFixtureA();

// Get the second fixture in this contact
b2Fixture* GetFixtureB();

//



int main(){

	SDL_Window* Main_Window;
	SDL_Renderer* Main_Renderer;
	SDL_Surface* Loading_Surf;
	SDL_Texture* Background_Tx;
	SDL_Texture* BlueShapes;
	SDL_Texture* Platform;
	SDL_Event e;


	// DestR is the un/modified image we will display
	SDL_Rect DestR;
	SDL_Rect PlatR;
	SDL_Rect SrcR;


	// same as source but for display
	DestR.x = 320;
	DestR.y = 240;
	DestR.w = 40;
	DestR.h = 40;


	PlatR.x = 0;
	PlatR.y = 600;
	PlatR.w = 1280;
	PlatR.h = 20;

	// clipping coordinates for jellyfish

	SrcR.x = 0;
	SrcR.y = 60;
	SrcR.w = 160;
	SrcR.h = 220;


	b2Vec2 gravity(0.0f, -10.0f);
	b2World world(gravity);	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 0.0f);	b2Body* groundBody = world.CreateBody(&groundBodyDef);	b2PolygonShape groundBox;
	groundBox.SetAsBox(20.0f, 1.0f);	groundBody->CreateFixture(&groundBox, 0.0f);	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 20.0f);

	b2Body* body = world.CreateBody(&bodyDef);	b2PolygonShape playerBox;
	playerBox.SetAsBox(1.0f, 2.0f);	b2FixtureDef fixtureDef;	fixtureDef.shape = &playerBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;	body->CreateFixture(&fixtureDef);	float32 timeStep = 1.0f / 60.0f;	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	/* Before we can render anything, we need a window and a renderer */
	Main_Window = SDL_CreateWindow("SDL_RenderCopy Example",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	Main_Renderer = SDL_CreateRenderer(Main_Window, -1, SDL_RENDERER_ACCELERATED);


	// loads image sources
	Loading_Surf = IMG_Load("sprites/runningGrant.png");
	BlueShapes = SDL_CreateTextureFromSurface(Main_Renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);


	// loads image sources
	Loading_Surf = IMG_Load("sprites/platform.png");
	Platform = SDL_CreateTextureFromSurface(Main_Renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);


	Loading_Surf = IMG_Load("sprites/background.png");
	Background_Tx = SDL_CreateTextureFromSurface(Main_Renderer, Loading_Surf);
	SDL_FreeSurface(Loading_Surf);  // we got the texture now -> free surface

	/* Load an additional texture */
	int j = 0;

	//body->SetLinearVelocity(b2Vec2(0, +5));
	
	for (double i = 0.0; i < 10000.0; i++){

		world.Step(timeStep, velocityIterations, positionIterations);
		b2Vec2 position = body->GetPosition();
		float32 angle = body->GetAngle();

		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

		//printf("%d \n",floor(position.y));

		for (b2Contact* contact = world.GetContactList();
			contact;
			contact = contact->GetNext())
		{
			if (contact->IsTouching()){
				printf("collision occured!\n");
			}
		}


		// i chooses the angle the image is being displayed, BlueShapes is being rotated.
		SDL_RenderCopyEx(Main_Renderer, Background_Tx, NULL, NULL, 0, NULL, SDL_FLIP_NONE);

		SDL_RenderCopyEx(Main_Renderer, BlueShapes, &SrcR, &DestR, 0, NULL, SDL_FLIP_NONE);

		SDL_RenderCopyEx(Main_Renderer, Platform, NULL, &PlatR, 0, NULL, SDL_FLIP_NONE);
		
		// loads in the renderer
		SDL_RenderPresent(Main_Renderer);
 
		SDL_RenderClear(Main_Renderer);

		SDL_Delay(100);


		//User requests quit

		SDL_PollEvent(&e);
		if (e.type == SDL_QUIT)
			{
				break;
			}

		//Set texture based on current keystate
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	
		if (currentKeyStates[SDL_SCANCODE_LEFT])
		{
			DestR.x--;
		}
		if (currentKeyStates[SDL_SCANCODE_RIGHT])
		{
			DestR.y = DestR.y + 5;
			
			j++;
			SrcR.x = 160*j;
			if (j == 11){
				j = 0;
			}
		}
		
	}


	// free and exit
	SDL_DestroyTexture(BlueShapes);
	SDL_DestroyTexture(Background_Tx);
	SDL_DestroyRenderer(Main_Renderer);
	SDL_DestroyWindow(Main_Window);
	SDL_Quit();


	return 0;
}

