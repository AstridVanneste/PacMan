/*
 * SDLManager.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#include "SDLHandler.h"

SDL_Handler::SDL_Handler()
{
	this->window = NULL;
	this->renderer = NULL;
}

SDL_Handler::~SDL_Handler()
{

}


/*
 * Returns a pointer to the window used by this manager.
 */
SDL_Window* SDL_Handler::getWindow()
{
	return this->window;
}

/*
 * Returns a pointer to the renderer used by this manager.
 */
SDL_Renderer* SDL_Handler::getRenderer()
{
	return this->renderer;
}


/*
 * Initializes everything necessary to start using SDL and the specific
 * window and renderer of this manager.
 */
bool SDL_Handler::init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING)==0)
	{
		this->window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
		this->renderer = SDL_CreateRenderer(window, -1, 0);

		if(this->window != NULL && this->renderer != NULL)
		{
			return true;
		}
	}
	return false;
}

bool SDL_Handler::visualizeAll()
{
	return true;
}

bool SDL_Handler::visualizeMap()
{
	return true;
}

bool SDL_Handler::visualizeComponent()
{
	return true;
}

