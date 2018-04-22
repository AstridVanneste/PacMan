/*
 * SDLGameInfo.cpp
 *
 *  Created on: Apr 6, 2018
 *      Author: Astrid
 */

#include "SDLGameInfo.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include "../Util/SDLUtil.h"
#include "../../Settings/Config.h"
#include "../Util/SDLDestroyShared.h"
#include "SDLGraphHandler.h"
#include "../Util/TextureManager.h"
#include "../Util/TextureManaging.h"
#include "../../Game/Control/Gamemanager.h"
using namespace std;

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

	switch(this->gameState)
	{
	case Game::PAUSED:
		this->visualizeStateText("PAUSED");
		break;
	case Game::GAME_OVER:
		this->visualizeStateText("GAME OVER!");
		break;
	case Game::NOT_STARTED:
		this->visualizeStateText("PRESS ANY KEY TO START...");
		break;
	case Game::VICTORY:
		this->visualizeStateText("VICTORY!");
		break;
	default:
		break;
	}

}

const void SDL_GameInfo::visualizeScore()
{
	shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

	string text = "SCORE: " + to_string(this->score);
	shared_ptr<SDL_Texture> tex  = TextureManager::getInstance().getText(text);

	Util::Location location = {0, 0};
	unique_ptr<SDL_Rect> dstR = createTextRect(location, text.size());

	SDL_RenderCopy(renderer.get(), tex.get(), nullptr, dstR.get());

}

const void SDL_GameInfo::visualizeLives()
{
	shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

	string text = "LIVES: " + to_string(this->lives);
	shared_ptr<SDL_Texture> tex  = TextureManager::getInstance().getText(text);

	Util::Location location = {0, 150};
	unique_ptr<SDL_Rect> dstR = createTextRect(location, text.size());

	SDL_RenderCopy(renderer.get(), tex.get(), nullptr, dstR.get());
}

const void SDL_GameInfo::visualizeStateText(const string& text)
{
	shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

	shared_ptr<SDL_Texture> tex  = TextureManager::getInstance().getText(text);

	Util::Location location = Game::Gamemanager::getInstance().getArena()->getSize();
	location.x *= ENTITY_HEIGHT;
	location.y *= ENTITY_WIDTH;
	location.y -= TEXT_WIDTH*text.size() ;
	location.x /= 2;
	location.y /= 2;

	unique_ptr<SDL_Rect> dstR = createTextRect(location, text.size());

	SDL_RenderCopy(renderer.get(), tex.get(), nullptr, dstR.get());
}

} /* namespace Game */
