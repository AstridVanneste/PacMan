/*
 * SDLFactory.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef SDLFACTORY_H_
#define SDLFACTORY_H_
#include <memory>
#include "../../Game/Util/AbstractFactory.h"
#include "../../Game/Entities/Ghost.h"
#include "../../Game/Entities/Pacman.h"
#include "../SDLGraphHandler.h"

namespace SDL
{
	class SDL_Factory : public Game::AbstractFactory
	{
	public:
		SDL_Factory();
		virtual ~SDL_Factory();

		SDL_Factory& operator=(const SDL_Factory& f);

		shared_ptr<Game::Ghost> createGhost();
		shared_ptr<Game::Ghost> createGhost(const Location& location, Game::GhostType type);
		shared_ptr<Game::Pacman> createPacman();
		shared_ptr<Game::Pacman> createPacman(const Location& location);
		shared_ptr<Game::Wall> createWall();
		shared_ptr<Game::Wall> createWall(const Location& location);
		shared_ptr<Game::Wall> createWall(const Location& location, char type);
		shared_ptr<Game::Event_Handler> createEventHandler();
		Game::Graphics_Handler& getGraphicsHandler();
};
}

#endif /* SDLFACTORY_H_ */
