/*
 * SDLDot.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: Astrid
 */

#include "SDLDot.h"

namespace SDL
{

SDL_Dot::SDL_Dot()
:Dot()
{
}

SDL_Dot::SDL_Dot(const Util::Location& location)
:Dot(location)
{
}

SDL_Dot::SDL_Dot(const Util::Location& location, int value)
:Dot(location, value)
{
}

SDL_Dot::~SDL_Dot()
{
}

const void SDL_Dot::visualize() noexcept
{
	//TODO implement visualize()
}

} /* namespace SDL */
