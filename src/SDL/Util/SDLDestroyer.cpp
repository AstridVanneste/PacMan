/*
 * SDLDestroyer.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: Astrid
 */

#include "SDLDestroyer.h"

namespace SDL
{

SDL_Destroyer::SDL_Destroyer()
{
}

SDL_Destroyer::~SDL_Destroyer()
{
}

void SDL_Destroyer::operator () (SDL_Window* window) const
{
	SDL_DestroyWindow(window);
}

void SDL_Destroyer:: operator () (SDL_Renderer* renderer) const
{
	SDL_DestroyRenderer(renderer);
}

void SDL_Destroyer:: operator () (SDL_Texture* texture) const
{
	SDL_DestroyTexture(texture);
}

void SDL_Destroyer:: operator () (SDL_Surface* surface) const
{
	SDL_FreeSurface(surface);
}

} /* namespace SDL */
