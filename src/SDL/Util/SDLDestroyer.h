/*
 * SDLDestroyer.h
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#ifndef SDL_UTIL_SDLDESTROYER_H_
#define SDL_UTIL_SDLDESTROYER_H_
#include <SDL2/SDL.h>

namespace SDL
{

class SDL_Destroyer
{
	public:
		SDL_Destroyer();
		virtual ~SDL_Destroyer();

		void operator() (SDL_Window* window) const;
		void operator() (SDL_Renderer* renderer) const;
		void operator() (SDL_Texture* texture) const;
		void operator() (SDL_Surface* surface) const;
};

} /* namespace SDL */

#endif /* SDL_UTIL_SDLDESTROYER_H_ */
