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

		virtual shared_ptr<Ghost> createGhost()=0;
		virtual shared_ptr<Ghost> createGhost(const Util::Location& location, GhostType type)=0;
		virtual shared_ptr<Pacman> createPacman()=0;
		virtual shared_ptr<Pacman> createPacman(const Util::Location& location)=0;
		virtual shared_ptr<Wall> createWall()=0;
		virtual shared_ptr<Wall> createWall(const Util::Location& location)=0;
		virtual shared_ptr<Wall> createWall(const Util::Location& location, char type)=0;
		virtual shared_ptr<Event_Handler> createEventHandler()=0;
		virtual Graphics_Handler& getGraphicsHandler()=0;
	};
}

#endif /* ABSTRACTFACTORY_H_ */
