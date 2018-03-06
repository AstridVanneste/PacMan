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
#include "../SDLHandler.h"

namespace SDL
{
	class SDL_Factory : public Game::AbstractFactory
	{
	public:
		SDL_Factory();
		/*virtual*/ ~SDL_Factory();

		Game::Ghost* createGhost();
		Game::Wall* createWall();
		Game::Wall* createWall(const Location& location);
		Game::Wall* createWall(char type);
		Game::Wall* createWall(const Location& location, char type);
		Game::Graphics_Handler& getGraphicsHandler();
};
}

#endif /* SDLFACTORY_H_ */
