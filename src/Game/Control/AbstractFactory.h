/*
 * AbstractFactory.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_
#include <memory>
#include "../Entities/Ghost.h"
#include "../Entities/Pacman.h"
#include "../Entities/Wall.h"
#include "../Events/EventHandler.h"
#include "GameInfo.h"
#include "GraphicsHandler.h"

namespace Game
{
	class AbstractFactory
	{
	public:
		AbstractFactory();
		virtual ~AbstractFactory();

		AbstractFactory& operator=(const AbstractFactory& af);

		virtual shared_ptr<GameInfo> createGameInfo(int score, int lives, GameState gameState) const noexcept =0;

		virtual shared_ptr<Ghost> createGhost() const noexcept =0;
		virtual shared_ptr<Ghost> createGhost(const Util::Location& location, GhostType type) const noexcept =0;

		virtual shared_ptr<Pacman> createPacman() const noexcept =0;
		virtual shared_ptr<Pacman> createPacman(const Util::Location& location, const Util::Location& respawnPoint) const noexcept =0;

		virtual shared_ptr<Wall> createWall() const noexcept =0;
		virtual shared_ptr<Wall> createWall(const Util::Location& location) const noexcept =0;
		virtual shared_ptr<Wall> createWall(const Util::Location& location, char type) const noexcept =0;
		virtual shared_ptr<Wall> createWall(const Util::Location& location, char type, int value) const noexcept =0;

		virtual shared_ptr<EventHandler> createEventHandler() const noexcept =0;

		virtual GraphicsHandler& getGraphicsHandler()noexcept =0;

	};
}

#endif /* ABSTRACTFACTORY_H_ */
