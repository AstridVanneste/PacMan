/*
 * SDLFactory.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include "SDLFactory.h"
#include "SDLGhost.h"
#include "SDLHandler.h"


SDL_Factory::SDL_Factory()
{
	// TODO Auto-generated constructor stub

}

SDL_Factory::~SDL_Factory()
{
	// TODO Auto-generated destructor stub
}

Ghost* SDL_Factory::createGhost()
{
	return new SDL_Ghost();
}

Graphics_Handler* SDL_Factory::createGraphicsHandler()
{
	return new SDL_Handler();
}

