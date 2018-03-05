/*
 * SDLManager.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#include "SDLHandler.h"

namespace SDL
{
	SDL_Handler::SDL_Handler()
	{
		this->window = NULL;
		this->renderer = NULL;
	}

	SDL_Handler::~SDL_Handler()
	{

	}

	SDL_Handler& SDL_Handler::getInstance()
	{
		static SDL_Handler instance;
		return instance;
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
			this->window = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
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
		SDL_SetRenderDrawColor(renderer, 0, 0, 0,  255);
		SDL_RenderClear(renderer);
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
}


