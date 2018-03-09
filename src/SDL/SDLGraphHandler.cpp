/*
 * SDLManager.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#include <vector>
#include "SDLGraphHandler.h"
#include "Util/TextureManager.h"
#include "Util/SDLDestroyShared.h"
#include "Util/SDLUtil.h"

namespace SDL
{
	SDL_Graph_Handler::SDL_Graph_Handler()
	{
		this->window = NULL;
		this->renderer = NULL;
	}

	SDL_Graph_Handler::~SDL_Graph_Handler()
	{

	}

	SDL_Graph_Handler& SDL_Graph_Handler::getInstance()
	{
		static SDL_Graph_Handler instance;
		return instance;
	}

	/*
	 * Returns a pointer to the window used by this manager.
	 */
	shared_ptr<SDL_Window> SDL_Graph_Handler::getWindow()
	{
		return this->window;
	}

	/*
	 * Returns a pointer to the renderer used by this manager.
	 */
	shared_ptr<SDL_Renderer> SDL_Graph_Handler::getRenderer()
	{
		return this->renderer;
	}


	/*
	 * Initializes everything necessary to start using SDL and the specific
	 * window and renderer of this manager.
	 */
	bool SDL_Graph_Handler::init(Location size)
	{
		if(SDL_Init(SDL_INIT_EVERYTHING)==0)
		{
			this->window = SDL_shared<SDL_Window> (SDL_CreateWindow("PacMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (size.y + 1) * ENTITY_WIDTH, (size.x* ENTITY_HEIGHT) + 10, SDL_WINDOW_SHOWN));  //TODO why the +1 for the WIDTH???
			this->renderer = SDL_shared<SDL_Renderer>(SDL_CreateRenderer(window.get(), -1, 0));

			if(this->window != NULL && this->renderer != NULL)
			{
				TextureManager::getInstance().setRenderer(this->renderer);
				return true;
			}
		}
		return false;
	}

	void SDL_Graph_Handler::delay(int time)
	{
		SDL_Delay(time);
	}

	unsigned int SDL_Graph_Handler::getTime()
	{
		return SDL_GetTicks();
	}

	bool SDL_Graph_Handler::visualizeAll(shared_ptr<Game::Map> map)
	{
		SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0,  255);
		SDL_RenderClear(renderer.get());

		Location i;
		for(i.x = 0; i.x < map->getSizeX(); i.x++)
		{
			for(i.y = 0; i.y < map->getSizeY(); i.y++)
			{
				map->getEntity(i)->visualize();
			}
		}
		SDL_RenderPresent(this->renderer.get());

		return true;
	}

	bool SDL_Graph_Handler::visualizeMap()
	{
		return true;
	}

	bool SDL_Graph_Handler::visualizeComponent()
	{
		return true;
	}
}


