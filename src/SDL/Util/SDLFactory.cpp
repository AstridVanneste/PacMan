/*
 * SDLFactory.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include "../Util/SDLFactory.h"

#include "../Entities/SDLGhost.h"
#include "../Entities/SDLWall.h"
using namespace std;


namespace SDL
{
	SDL_Factory::SDL_Factory()
	{
	}

	SDL_Factory::~SDL_Factory()
	{
	}

	shared_ptr<Game::Ghost> SDL_Factory::createGhost()
	{
		return make_shared<SDL_Ghost>();
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall()
	{
		return make_shared<SDL_Wall>();
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall(char type)
	{
		return make_shared<SDL_Wall>(type);
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall(const Location& location)
	{
		return make_shared<SDL_Wall>(location);
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall(const Location& location, char type)
	{
		return make_shared<SDL_Wall>(location, type);
	}

	Game::Graphics_Handler& SDL_Factory::getGraphicsHandler()
	{
		return SDL_Handler::getInstance();
	}
}

