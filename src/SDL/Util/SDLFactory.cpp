/*
 * SDLFactory.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include "../Util/SDLFactory.h"

#include "../Entities/SDLGhost.h"
#include "../Entities/SDLWall.h"


namespace SDL
{
	SDL_Factory::SDL_Factory()
	{
	}

	SDL_Factory::~SDL_Factory()
	{
	}

	Game::Ghost* SDL_Factory::createGhost()
	{
		return new SDL_Ghost();
	}

	Game::Wall* SDL_Factory::createWall()
	{
		return new SDL_Wall();
	}

	Game::Wall* SDL_Factory::createWall(char type)
	{
		return new SDL_Wall(type);
	}

	Game::Wall* SDL_Factory::createWall(Location location)
	{
		return new SDL_Wall(location);
	}

	Game::Graphics_Handler& SDL_Factory::getGraphicsHandler()
	{
		return SDL_Handler::getInstance();
	}
}

