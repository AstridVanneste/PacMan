/*
 * SDLFactory.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include <memory>
#include "../Util/SDLFactory.h"
#include "../Entities/SDLGhost.h"
#include "../Entities/SDLWall.h"
#include "../Entities/SDLPacman.h"
#include "SDLDestroyShared.h"
#include "../SDLEventHandler.h"
using namespace std;


namespace SDL
{
	SDL_Factory::SDL_Factory()
	{
	}

	SDL_Factory::~SDL_Factory()
	{
	}

	SDL_Factory& SDL_Factory::operator =(const SDL_Factory& f)
	{
		if(this != &f)
		{
			AbstractFactory::operator=(f);
		}
		return *this;
	}

	shared_ptr<Game::Ghost> SDL_Factory::createGhost()
	{
		return make_shared<SDL_Ghost>();
	}

	shared_ptr<Game::Ghost> SDL_Factory::createGhost(const Util::Location& location, Game::GhostType type)
	{
		return make_shared<SDL_Ghost>(location, type);
	}

	shared_ptr<Game::Pacman> SDL_Factory::createPacman()
	{
		return make_shared<SDL_Pacman>();
	}

	shared_ptr<Game::Pacman> SDL_Factory::createPacman(const Util::Location& location)
	{
		return make_shared<SDL_Pacman>(location);
	}


	shared_ptr<Game::Wall> SDL_Factory::createWall()
	{
		return make_shared<SDL_Wall>();
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall(const Util::Location& location)
	{
		return make_shared<SDL_Wall>(location);
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall(const Util::Location& location, char type)
	{
		return make_shared<SDL_Wall>(location, type);
	}

	Game::Graphics_Handler& SDL_Factory::getGraphicsHandler()
	{
		return SDL_Graph_Handler::getInstance();
	}

	shared_ptr<Game::Event_Handler> SDL_Factory::createEventHandler()
	{
		return make_shared<SDL_Event_Handler>();
	}
}

