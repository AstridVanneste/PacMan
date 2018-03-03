/*
 * AbstractFactory.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_
#include "Ghost.h"
#include "GraphicsHandler.h"

class AbstractFactory
{
public:
	AbstractFactory();
	virtual ~AbstractFactory();

	virtual Ghost* createGhost()=0;
	virtual Graphics_Handler* createGraphicsHandler()=0;
};

#endif /* ABSTRACTFACTORY_H_ */
