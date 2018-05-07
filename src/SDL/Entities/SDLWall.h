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
		SDL_Wall(const Util::Location& location);
		SDL_Wall(char type);
		SDL_Wall(const Util::Location& location, char type);
		SDL_Wall(const Util::Location& location, char type, int value);

		virtual ~SDL_Wall();

		SDL_Wall& operator=(const SDL_Wall& w);

		virtual void visualize() const override;
	};

} /* namespace SDL */

#endif /* SDL_ENTITIES_SDLWALL_H_ */
