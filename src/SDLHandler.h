/*
 * SDLManager.h
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#ifndef SDLHANDLER_H_
#define SDLHANDLER_H_
#include <SDL2/SDL.h>
#include <string>
#include "GraphicsHandler.h"
using namespace std;

class SDL_Handler : public Graphics_Handler
{
private:
	SDL_Renderer* renderer;
	SDL_Window* window;

public:
	SDL_Handler();
	virtual ~SDL_Handler();

	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

	bool init();
	bool visualizeAll();
	bool visualizeMap();
	bool visualizeComponent();
};

#endif /* SDLHANDLER_H_ */