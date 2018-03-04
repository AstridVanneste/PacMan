/*
 * SDLFactory.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef SDLFACTORY_H_
#define SDLFACTORY_H_
#include "Ghost.h"
#include "AbstractFactory.h"

class SDL_Factory : public AbstractFactory
{
public:
	SDL_Factory();
	virtual ~SDL_Factory();

	Ghost* createGhost();
	Graphics_Handler* createGraphicsHandler();
};

#endif /* SDLFACTORY_H_ */
