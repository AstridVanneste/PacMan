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
#include "../Entities/SDLDot.h"
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

	const shared_ptr<Game::Ghost> SDL_Factory::createGhost() noexcept
	{
		return make_shared<SDL_Ghost>();
	}

	const shared_ptr<Game::Ghost> SDL_Factory::createGhost(const Util::Location& location, Game::GhostType type) noexcept
	{
		return make_shared<SDL_Ghost>(location, type);
	}

	const shared_ptr<Game::Pacman> SDL_Factory::createPacman() noexcept
	{
		return make_shared<SDL_Pacman>();
	}

	const shared_ptr<Game::Pacman> SDL_Factory::createPacman(const Util::Location& location) noexcept
	{
		return make_shared<SDL_Pacman>(location);
	}


	const shared_ptr<Game::Wall> SDL_Factory::createWall() noexcept
	{
		return make_shared<SDL_Wall>();
	}

	const shared_ptr<Game::Wall> SDL_Factory::createWall(const Util::Location& location) noexcept
	{
		return make_shared<SDL_Wall>(location);
	}

	const shared_ptr<Game::Wall> SDL_Factory::createWall(const Util::Location& location, char type) noexcept
	{
		return make_shared<SDL_Wall>(location, type);
	}

	const shared_ptr<Game::Dot> SDL_Factory::createDot() noexcept
	{
		return make_shared<SDL_Dot>();
	}

	const shared_ptr<Game::Dot> SDL_Factory::createDot(const Util::Location& location) noexcept
	{
		return make_shared<SDL_Dot>(location);
	}

	const shared_ptr<Game::Dot> SDL_Factory::createDot(const Util::Location& location, int value) noexcept
	{
		return make_shared<SDL_Dot>(location, value);
	}

	Game::Graphics_Handler& SDL_Factory::getGraphicsHandler() noexcept
	{
		return SDL_Graph_Handler::getInstance();
	}

	const shared_ptr<Game::Event_Handler> SDL_Factory::createEventHandler() noexcept
	{
		return make_shared<SDL_Event_Handler>();
	}
}

