/*
 * SDLFactory.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef SDLFACTORY_H_
#define SDLFACTORY_H_
#include <memory>
#include "../../Game/Control/AbstractFactory.h"
#include "../../Game/Entities/Ghost.h"
#include "../../Game/Entities/Pacman.h"
#include "../Control/SDLGraphHandler.h"

namespace SDL
{
	class SDL_Factory : public Game::AbstractFactory
	{
	public:
		SDL_Factory();
		virtual ~SDL_Factory();

		SDL_Factory& operator=(const SDL_Factory& f);

		shared_ptr<Game::GameInfo> createGameInfo(int score, int lives, Game::GameState gameState) const noexcept override;

		shared_ptr<Game::Ghost> createGhost() const noexcept override;
		shared_ptr<Game::Ghost> createGhost(const Util::Location& location, Game::GhostType type) const noexcept override;

		shared_ptr<Game::Pacman> createPacman() const noexcept override;
		shared_ptr<Game::Pacman> createPacman(const Util::Location& location, const Util::Location& respawnPoint) const noexcept override;

		shared_ptr<Game::Wall> createWall() const noexcept override;
		shared_ptr<Game::Wall> createWall(const Util::Location& location) const noexcept override;
		shared_ptr<Game::Wall> createWall(const Util::Location& location, char type) const noexcept override;
		shared_ptr<Game::Wall> createWall(const Util::Location& location, char type, int value) const noexcept override;


		shared_ptr<Game::EventHandler> createEventHandler() const noexcept override;

		Game::GraphicsHandler& getGraphicsHandler() noexcept override;
};
}

#endif /* SDLFACTORY_H_ */
