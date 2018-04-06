/*
 * SDLGameInfo.cpp
 *
 *  Created on: Apr 6, 2018
 *      Author: Astrid
 */

#include "SDLGameInfo.h"

namespace SDL
{

SDL_GameInfo::SDL_GameInfo()
:GameInfo()
{
}

SDL_GameInfo::SDL_GameInfo(const SDL_GameInfo& gi)
:GameInfo(gi)
{
}

SDL_GameInfo::SDL_GameInfo(int score, int lives, Game::GameState gameState)
:GameInfo(score, lives, gameState)
{
}

SDL_GameInfo::~SDL_GameInfo()
{
}

const void SDL_GameInfo::visualize()
{
	this->visualizeScore();
	this->visualizeLives();

	if(this->gameState == Game::PAUSED)
	{
		this->visualizeStateText("PAUSED");
	}
	else if(this->gameState == Game::GAME_OVER)
	{
		this->visualizeStateText("GAME OVER!");
	}
}

const void SDL_GameInfo::visualizeScore()
{

}

const void SDL_GameInfo::visualizeLives()
{

}

const void SDL_GameInfo::visualizeStateText(const string& text)
{

}

} /* namespace Game */