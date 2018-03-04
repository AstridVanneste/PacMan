/*
 * SDLGhost.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Astrid
 */

#ifndef SDLGHOST_H_
#define SDLGHOST_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../../Game/Entities/Ghost.h"

/*
 * SDL_Factory is a subclass of AbstractFactory to abstract the game logic from the SDL layer.
 * SDL_Factory creates objects with SDL features and SDL implementations of functionalities of
 * these objects.
 */
namespace SDL
{
	class SDL_Ghost : public Game::Ghost
	{
	public:
		SDL_Ghost();
		SDL_Ghost(Game::GhostType type);
		virtual ~SDL_Ghost();

		void visualize();
	};
}

#endif /* SDLGHOST_H_ */
