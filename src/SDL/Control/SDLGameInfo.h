/*
 * SDLGameInfo.h
 *
 *  Created on: Apr 6, 2018
 *      Author: Astrid
 */

#ifndef SDL_CONTROL_SDLGAMEINFO_H_
#define SDL_CONTROL_SDLGAMEINFO_H_

#include "../../Game/Control/GameInfo.h"

#include <string>
using namespace std;

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

		const void visualizeScore();
		const void visualizeLives();
		const void visualizeStateText(const string& text);
	};

} /* namespace Game */

#endif /* SDL_CONTROL_SDLGAMEINFO_H_ */
