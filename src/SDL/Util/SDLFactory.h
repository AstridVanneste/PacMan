/*
 * SDLFactory.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef SDLFACTORY_H_
#define SDLFACTORY_H_
#include <memory>
#include "../../Game/AbstractFactory.h"
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

		const shared_ptr<Game::Ghost> createGhost() noexcept override;
		const shared_ptr<Game::Ghost> createGhost(const Util::Location& location, Game::GhostType type) noexcept override;

		const shared_ptr<Game::Pacman> createPacman() noexcept override;
		const shared_ptr<Game::Pacman> createPacman(const Util::Location& location) noexcept override;

		const shared_ptr<Game::Wall> createWall() noexcept override;
		const shared_ptr<Game::Wall> createWall(const Util::Location& location) noexcept override;
		const shared_ptr<Game::Wall> createWall(const Util::Location& location, char type) noexcept override;

		const virtual shared_ptr<Game::Dot> createDot()noexcept override;
		const virtual shared_ptr<Game::Dot> createDot(const Util::Location& location)noexcept override;
		const virtual shared_ptr<Game::Dot> createDot(const Util::Location& location, int value) noexcept override;

		const shared_ptr<Game::Event_Handler> createEventHandler() noexcept override;

		Game::Graphics_Handler& getGraphicsHandler() noexcept override;
};
}

#endif /* SDLFACTORY_H_ */
