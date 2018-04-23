/*
 * SDLManager.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: Astrid
 */

#include <vector>
#include <SDL2/SDL_TTF.h>
#include "SDLGraphHandler.h"
#include "../../Game/Control/Gamemanager.h"
#include "../Util/TextureManager.h"
#include "../Util/SDLDestroyShared.h"
#include "../Util/SDLUtil.h"
#include "../../Settings/Config.h"

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
	const shared_ptr<SDL_Window> SDL_Graph_Handler::getWindow() noexcept
	{
		return this->window;
	}

	/*
	 * Returns a pointer to the renderer used by this manager.
	 */
	const shared_ptr<SDL_Renderer> SDL_Graph_Handler::getRenderer() noexcept
	{
		return this->renderer;
	}


	/*
	 * Initializes everything necessary to start using SDL and the specific
	 * window and renderer of this manager.
	 */
	bool SDL_Graph_Handler::init(Util::Location size) noexcept
	{
		if(SDL_Init(SDL_INIT_EVERYTHING)==0)
		{
			this->window = SDL_shared<SDL_Window> (SDL_CreateWindow("PacMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.y * ENTITY_WIDTH, size.x* ENTITY_HEIGHT + ARENA_OFFSET, SDL_WINDOW_SHOWN));
			this->renderer = SDL_shared<SDL_Renderer>(SDL_CreateRenderer(window.get(), -1, 0));
			if(TTF_Init()==0)
			{
				if(this->window != NULL && this->renderer != NULL)
				{
					TextureManager::getInstance().setRenderer(this->renderer);
					return true;
				}
			}
			else
			{
				cout << "TTF not properly initialized!" << endl;
			}
		}
		else
		{
			cout << "SDL not properly initialized!" << endl;
		}
		return false;
	}

	void SDL_Graph_Handler::delay(int time) noexcept
	{
		SDL_Delay(time);
	}

	unsigned int SDL_Graph_Handler::getTime() noexcept
	{
		return SDL_GetTicks();
	}

	const bool SDL_Graph_Handler::visualizeAll()
	{
		SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255,  255);
		SDL_RenderClear(renderer.get());

		Game::Gamemanager::getInstance().getArena()->visualize();
		Game::Gamemanager::getInstance().getGameInfo()->visualize();

		SDL_RenderPresent(this->renderer.get());

		return true;
	}

	void SDL_Graph_Handler::quit() noexcept
	{
		// TODO solve error with TTF_quit()
		//TTF_Quit();
		SDL_Quit();
	}
}


