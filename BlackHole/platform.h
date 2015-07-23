#pragma once
#include "level.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdio.h>
#include "String.h"
#include "window.h"
#include "Chipmunk\chipmunk.h"
#include "actor.h"



#define PLATFORM_TYPE 2


class Platform : public Actor
{
public:

	Platform(Level* level, char* name);

	void RenderActor(char* filePath);
	
	void DestroyBody();

	


	/*cpBody *body ;
	cpShape *shape;

	cpFloat w;
	cpFloat h;


	Level* level;


	char* name;



	bool destroyable = false;
*/

private:

};