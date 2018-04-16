/*
 * SDLEventHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "SDLEventHandler.h"
#include <memory>
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

namespace SDL
{

	SDL_Event_Handler::SDL_Event_Handler()
	{
	}

	SDL_Event_Handler::~SDL_Event_Handler()
	{
	}

	SDL_Event_Handler& SDL_Event_Handler::operator=(const SDL_Event_Handler& eh)
	{
		if(this != &eh)
		{
			Event_Handler::operator=(eh);
		}
		return *this;
	}

	void SDL_Event_Handler::pollEvents()
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			Game::EventType type;
			string subtype;
			switch(event.type)
			{
			case SDL_QUIT:
				type = Game::QUIT;
				break;
			case SDL_KEYUP:
				type = Game::KEY_UP;
				break;
			case SDL_KEYDOWN:
				type = Game::KEY_DOWN;
				//TODO change to constants?
				switch(event.key.keysym.sym)
				{
				case SDLK_LEFT:
					subtype = Game::LEFT_K;
					break;
				case SDLK_RIGHT:
					subtype = Game::RIGHT_K;
					break;
				case SDLK_UP:
					subtype = Game::UP_K;
					break;
				case SDLK_DOWN:
					subtype = Game::DOWN_K;
					break;
				case SDLK_ESCAPE:
					subtype = Game::ESCAPE_K;
					break;
				default:
					subtype = Game::UNKNOWN_K;
					break;
				}
				break;
			default:
				//cout << "unkown event captured" << endl;
				break;
			}
			this->events.emplace_back(make_shared<Game::Event>(type, subtype));
		}
	}
}/* namespace SDL */
