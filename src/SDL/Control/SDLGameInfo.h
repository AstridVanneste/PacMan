/*
 * SDLGameInfo.h
 *
 *  Created on: Apr 6, 2018
 *      Author: Astrid
 */

#ifndef SDL_CONTROL_SDLGAMEINFO_H_
#define SDL_CONTROL_SDLGAMEINFO_H_

#include "../../Game/Control/GameInfo.h"

namespace SDL
{

	class SDL_GameInfo: public Game::GameInfo
	{
	public:
		SDL_GameInfo();
		SDL_GameInfo(const SDL_GameInfo& gi);
		SDL_GameInfo(int score, int lives, Game::GameState gameState);

		virtual ~SDL_GameInfo();

		const void visualize() override;
	};

} /* namespace Game */

#endif /* SDL_CONTROL_SDLGAMEINFO_H_ */
