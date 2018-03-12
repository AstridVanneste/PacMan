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

namespace SDL
{

SDL_Event_Handler::SDL_Event_Handler()
{
}

SDL_Event_Handler::~SDL_Event_Handler()
{
}

bool SDL_Event_Handler::pollEvents()
{
	SDL_Event event;
	bool end = false;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			this->events.emplace_back(make_shared<Game::Event>(QUIT));
		}
		if(event.type == SDL_QUIT)
		{
			end = true;
		}
	}

	return end;
}

} /* namespace SDL */
