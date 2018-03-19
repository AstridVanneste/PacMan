/*
 * AbstractFactory.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_
#include <memory>
#include "Entities/Ghost.h"
#include "Entities/Pacman.h"
#include "Entities/Dot.h"
#include "GraphicsHandler.h"
#include "Entities/Wall.h"
#include "Events/EventHandler.h"

namespace Game
{
	class AbstractFactory
	{
	public:
		AbstractFactory();
		virtual ~AbstractFactory();

		AbstractFactory& operator=(const AbstractFactory& af);

		const virtual shared_ptr<Ghost> createGhost()noexcept =0;
		const virtual shared_ptr<Ghost> createGhost(const Util::Location& location, GhostType type)noexcept =0;

		const virtual shared_ptr<Pacman> createPacman()noexcept =0;
		const virtual shared_ptr<Pacman> createPacman(const Util::Location& location)noexcept =0;

		const virtual shared_ptr<Wall> createWall()noexcept =0;
		const virtual shared_ptr<Wall> createWall(const Util::Location& location)noexcept =0;
		const virtual shared_ptr<Wall> createWall(const Util::Location& location, char type)noexcept =0;

		const virtual shared_ptr<Dot> createDot()noexcept =0;
		const virtual shared_ptr<Dot> createDot(const Util::Location& location)noexcept =0;
		const virtual shared_ptr<Dot> createDot(const Util::Location& location, int value) noexcept =0;

		const virtual shared_ptr<Event_Handler> createEventHandler()noexcept =0;

		virtual Graphics_Handler& getGraphicsHandler()noexcept =0;
	};
}

#endif /* ABSTRACTFACTORY_H_ */
