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
#include "Ghost.h"

/*
 * SDL_Factory is a subclass of AbstractFactory to abstract the game logic from the SDL layer.
 * SDL_Factory creates objects with SDL features and SDL implementations of functionalities of
 * these objects.
 */
class SDL_Ghost : public Ghost
{
public:
	SDL_Ghost();
	virtual ~SDL_Ghost();

	void visualize();
};

#endif /* SDLGHOST_H_ */