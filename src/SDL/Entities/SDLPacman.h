/*
 * SDLPacman.h
 *
 *  Created on: 10 mrt. 2018
 *      Author: Astrid
 */

#ifndef SDL_ENTITIES_SDLPACMAN_H_
#define SDL_ENTITIES_SDLPACMAN_H_

#include "../../Game/Entities/Pacman.h"

namespace SDL
{
	const int MAX_ANIMATION = 3;

	class SDL_Pacman : public Game::Pacman
	{
	private:
		int animationOffset;
		bool animationDirection;
	public:
		SDL_Pacman();
		SDL_Pacman(const SDL_Pacman& pacman);
		SDL_Pacman(const Util::Location& location);
		virtual ~SDL_Pacman();

		SDL_Pacman& operator=(const SDL_Pacman& p) noexcept;

		const void visualize();
	};

} /* namespace Game */

#endif /* SDL_ENTITIES_SDLPACMAN_H_ */
