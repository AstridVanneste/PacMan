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
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			this->events.emplace_back(make_shared<Game::Event>(QUIT));
			break;
		case SDL_KEYUP:
			this->events.emplace_back(make_shared<Game::Event>(KEY_UP));
			break;
		case SDL_KEYDOWN:
			this->events.emplace_back(make_shared<Game::Event>(KEY_DOWN));
			break;
		default:
			//cout << "unkown event captured" << endl;
			break;
		}
	}
}

} /* namespace SDL */
