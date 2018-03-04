/*
 * SDLFactory.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include "../Util/SDLFactory.h"

#include "../Entities/SDLGhost.h"
#include "../SDLHandler.h"

namespace SDL
{
	SDL_Factory::SDL_Factory()
	{
		// TODO Auto-generated constructor stub

	}

	SDL_Factory::~SDL_Factory()
	{
		// TODO Auto-generated destructor stub
	}

	Game::Ghost* SDL_Factory::createGhost()
	{
		return new SDL_Ghost();
	}

	Game::Graphics_Handler* SDL_Factory::createGraphicsHandler()
	{
		return new SDL_Handler();
	}
}

