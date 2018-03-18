/*
 * SDLEventHandler.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "SDLEventHandler.h"
#include "../Game/Events/Event.h"
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

void SDL_Event_Handler::pollEvents()
{
	SDL_Event event;
	bool end = false;
	while(SDL_PollEvent(&event))
	{
		EventType type;
		string subtype;
		switch(event.type)
		{
		case SDL_QUIT:
			type = QUIT;
			break;
		case SDL_KEYUP:
			type = KEY_UP;
			break;
		case SDL_KEYDOWN:
			type = KEY_DOWN;
			//TODO change to constants?
			switch(event.key.keysym.sym)
			{
			case SDLK_LEFT:
				subtype = "LEFT";
				break;
			case SDLK_RIGHT:
				subtype = "RIGHT";
				break;
			case SDLK_UP:
				subtype = "UP";
				break;
			case SDLK_DOWN:
				subtype = "DOWN";
				break;
			default:
				break;
			}
			break;
		default:
			//cout << "unkown event captured" << endl;
			break;
		}

		this->events.emplace_back(make_shared<Game::Event>(type, subtype));

		if(event.type == SDL_QUIT)
		{
			end = true;
		}
	}
}

} /* namespace SDL */
