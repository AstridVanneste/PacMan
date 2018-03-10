/*
 * SDLPacman.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Astrid
 */

#include "SDLPacman.h"
#include <memory>
#include <iostream>
#include "../Util/TextureManaging.h"
#include "../Util/TextureManager.h"
#include "../SDLGraphHandler.h"

namespace SDL
{

	SDL_Pacman::SDL_Pacman()
	:Game::Pacman()
	{
	}

	SDL_Pacman::SDL_Pacman(const SDL_Pacman& pacman)
	:Game::Pacman(pacman)
	{
	}

	SDL_Pacman::SDL_Pacman(const Location& location)
	:Game::Pacman(location)
	{
	}

	SDL_Pacman::~SDL_Pacman()
	{
	}

	const void SDL_Pacman::visualize()
	{
		//stuff

		shared_ptr<SDL_Renderer> renderer(SDL_Graph_Handler::getInstance().getRenderer());

		Location offset;
		offset.x = 0;
		offset.y = 0;
		unique_ptr<SDL_Rect> srcR = createSrcRect(offset);
		unique_ptr<SDL_Rect> destR = createDstRect(this->location);
		shared_ptr<SDL_Texture> tex = TextureManager::getInstance().getPacman();

		if(SDL_RenderCopy(renderer.get(), tex.get(), srcR.get(), destR.get())<0)
		{
			cout << "Error when drawing image on screen" << endl;
			cout << SDL_GetError() << endl;
		}
	}

} /* namespace Game */
