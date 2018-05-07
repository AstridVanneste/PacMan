/*
 * SDLFactory.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#include <memory>
#include "SDLFactory.h"
#include "../Entities/SDLGhost.h"
#include "../Entities/SDLWall.h"
#include "../Entities/SDLPacman.h"
#include "../Util/SDLDestroyShared.h"
#include "../Events/SDLEventHandler.h"
#include "SDLGameInfo.h"
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

	shared_ptr<Game::GameInfo> SDL_Factory::createGameInfo(int score, int lives, Game::GameState gameState) const noexcept
	{
		return make_shared<SDL_GameInfo>(score, lives, gameState);
	}

	shared_ptr<Game::Ghost> SDL_Factory::createGhost() const noexcept
	{
		return make_shared<SDL_Ghost>();
	}

	shared_ptr<Game::Ghost> SDL_Factory::createGhost(const Util::Location& location, Game::GhostType type) const noexcept
	{
		return make_shared<SDL_Ghost>(location, type);
	}

	shared_ptr<Game::Pacman> SDL_Factory::createPacman() const noexcept
	{
		return make_shared<SDL_Pacman>();
	}

	shared_ptr<Game::Pacman> SDL_Factory::createPacman(const Util::Location& location, const Util::Location& respawnPoint) const noexcept
	{
		return make_shared<SDL_Pacman>(location, respawnPoint);
	}


	shared_ptr<Game::Wall> SDL_Factory::createWall() const noexcept
	{
		return make_shared<SDL_Wall>();
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall(const Util::Location& location) const noexcept
	{
		return make_shared<SDL_Wall>(location);
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall(const Util::Location& location, char type) const noexcept
	{
		return make_shared<SDL_Wall>(location, type);
	}

	shared_ptr<Game::Wall> SDL_Factory::createWall(const Util::Location& location, char type, int value) const noexcept
	{
		return make_shared<SDL_Wall>(location, type,value);
	}

	Game::GraphicsHandler& SDL_Factory::getGraphicsHandler() noexcept
	{
		return SDL_Graph_Handler::getInstance();
	}

	shared_ptr<Game::EventHandler> SDL_Factory::createEventHandler() const noexcept
	{
		return make_shared<SDL_Event_Handler>();
	}
}

