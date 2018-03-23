/*
 * SDLDot.h
 *
 *  Created on: Mar 19, 2018
 *      Author: Astrid
 */

#ifndef SDL_ENTITIES_SDLDOT_H_
#define SDL_ENTITIES_SDLDOT_H_

#include "../../Game/Entities/Dot.h"

namespace SDL
{

class SDL_Dot : public Game::Dot
{
const int IMAGE_OFFSET[2] = {4,1};

public:
	SDL_Dot();
	SDL_Dot(const SDL_Dot& dot);
	SDL_Dot(const Util::Location& location);
	SDL_Dot(const Util::Location& location, int value);

	//TODO = operator overloading

	const void visualize() noexcept override;

	virtual ~SDL_Dot();
};

} /* namespace SDL */

#endif /* SDL_ENTITIES_SDLDOT_H_ */
