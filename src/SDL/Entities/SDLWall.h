/*
 * SDLWall.h
 *
 *  Created on: Mar 5, 2018
 *      Author: Astrid
 */

#ifndef SDL_ENTITIES_SDLWALL_H_
#define SDL_ENTITIES_SDLWALL_H_
#include "../../Game/Entities/Wall.h"

namespace SDL
{

	class SDL_Wall : public Game::Wall
	{
	public:
		SDL_Wall();
		SDL_Wall(Location location);
		SDL_Wall(char type);

		virtual ~SDL_Wall();

		virtual void visualize();
	};

} /* namespace SDL */

#endif /* SDL_ENTITIES_SDLWALL_H_ */
