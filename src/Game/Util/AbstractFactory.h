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
#include "../GraphicsHandler.h"
#include "../Entities/Wall.h"

namespace Game
{
	class AbstractFactory
	{
	public:
		AbstractFactory();
		virtual ~AbstractFactory();

		virtual shared_ptr<Ghost> createGhost()=0;
		virtual shared_ptr<Wall> createWall()=0;
		virtual shared_ptr<Wall> createWall(const Location& location)=0;
		virtual shared_ptr<Wall> createWall(char type)=0;
		virtual shared_ptr<Wall> createWall(const Location& location, char type)=0;
		virtual Graphics_Handler& getGraphicsHandler()=0;
	};
}

#endif /* ABSTRACTFACTORY_H_ */
