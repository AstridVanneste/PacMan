/*
 * SDLFactory.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef SDLFACTORY_H_
#define SDLFACTORY_H_
#include "../../Game/Util/AbstractFactory.h"
#include "../../Game/Entities/Ghost.h"

namespace SDL
{
	class SDL_Factory : public Game::AbstractFactory
	{
	public:
		SDL_Factory();
		virtual ~SDL_Factory();

		Game::Ghost* createGhost();
		Game::Graphics_Handler* createGraphicsHandler();
};
}

#endif /* SDLFACTORY_H_ */
