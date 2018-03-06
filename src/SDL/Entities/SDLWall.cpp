/*
 * SDLWall.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Astrid
 */

#include "SDLWall.h"

namespace SDL
{

	SDL_Wall::SDL_Wall()
	: Game::Wall()
	{
	}

	SDL_Wall::SDL_Wall(const Location& location)
	: Game::Wall(location)
	{
	}

	SDL_Wall::SDL_Wall(char type)
	: Game::Wall(type)
	{
	}

	SDL_Wall::SDL_Wall(const Location& location, char type)
	: Game::Wall(location, type)
	{

	}

	SDL_Wall::~SDL_Wall()
	{
	}

	void SDL_Wall::visualize()
	{
		//stuff
	}

} /* namespace SDL */
